/*
 * Copyright (C) 2000 - 2007 Jeff Dike (jdike@{addtoit,linux.intel}.com)
 * Licensed under the GPL
 */

#include "linux/mm.h"
#include "linux/sched.h"
#include "asm/uaccess.h"
#include "skas.h"

extern int arch_switch_tls(struct task_struct *to);

void arch_switch_to(struct task_struct *to)
{
	int err = arch_switch_tls(to);
	if (!err)
		return;

	if (err != -EINVAL)
		printk(KERN_WARNING "arch_switch_tls failed, errno %d, "
		       "not EINVAL\n", -err);
	else
		printk(KERN_WARNING "arch_switch_tls failed, errno = EINVAL\n");
}

int is_syscall(unsigned long addr)
{
	unsigned short instr;
	int n;

	n = copy_from_user(&instr, (void __user *) addr, sizeof(instr));
	if (n) {
		n = access_process_vm(current, addr, &instr, sizeof(instr), 0);
		if (n != sizeof(instr)) {
			printk(KERN_ERR "is_syscall : failed to read "
			       "instruction from 0x%lx\n", addr);
			return 1;
		}
	}
	
	return (instr == 0x80cd) || (instr == 0x340f);
}

#define FLAG_MASK 0x00044dd5

static const int reg_offsets[] = {
	[EBX] = HOST_BX,
	[ECX] = HOST_CX,
	[EDX] = HOST_DX,
	[ESI] = HOST_SI,
	[EDI] = HOST_DI,
	[EBP] = HOST_BP,
	[EAX] = HOST_AX,
	[DS] = HOST_DS,
	[ES] = HOST_ES,
	[FS] = HOST_FS,
	[GS] = HOST_GS,
	[EIP] = HOST_IP,
	[CS] = HOST_CS,
	[EFL] = HOST_EFLAGS,
	[UESP] = HOST_SP,
	[SS] = HOST_SS,
};

int putreg(struct task_struct *child, int regno, unsigned long value)
{
	regno >>= 2;
	switch (regno) {
	case EBX:
	case ECX:
	case EDX:
	case ESI:
	case EDI:
	case EBP:
	case EAX:
	case EIP:
	case UESP:
		break;
	case FS:
		if (value && (value & 3) != 3)
			return -EIO;
		break;
	case GS:
		if (value && (value & 3) != 3)
			return -EIO;
		break;
	case DS:
	case ES:
		if (value && (value & 3) != 3)
			return -EIO;
		value &= 0xffff;
		break;
	case SS:
	case CS:
		if ((value & 3) != 3)
			return -EIO;
		value &= 0xffff;
		break;
	case EFL:
		value &= FLAG_MASK;
		child->thread.regs.regs.gp[HOST_EFLAGS] |= value;
		return 0;
	case ORIG_EAX:
		child->thread.regs.regs.syscall = value;
		return 0;
	default :
		panic("Bad register in putreg() : %d\n", regno);
	}
	child->thread.regs.regs.gp[reg_offsets[regno]] = value;
	return 0;
}

int poke_user(struct task_struct *child, long addr, long data)
{
	if ((addr & 3) || addr < 0)
		return -EIO;

	if (addr < MAX_REG_OFFSET)
		return putreg(child, addr, data);
	else if ((addr >= offsetof(struct user, u_debugreg[0])) &&
		 (addr <= offsetof(struct user, u_debugreg[7]))) {
		addr -= offsetof(struct user, u_debugreg[0]);
		addr = addr >> 2;
		if ((addr == 4) || (addr == 5))
			return -EIO;
		child->thread.arch.debugregs[addr] = data;
		return 0;
	}
	return -EIO;
}

unsigned long getreg(struct task_struct *child, int regno)
{
	unsigned long mask = ~0UL;

	regno >>= 2;
	switch (regno) {
	case ORIG_EAX:
		return child->thread.regs.regs.syscall;
	case FS:
	case GS:
	case DS:
	case ES:
	case SS:
	case CS:
		mask = 0xffff;
		break;
	case EIP:
	case UESP:
	case EAX:
	case EBX:
	case ECX:
	case EDX:
	case ESI:
	case EDI:
	case EBP:
	case EFL:
		break;
	default:
		panic("Bad register in getreg() : %d\n", regno);
	}
	return mask & child->thread.regs.regs.gp[reg_offsets[regno]];
}

int peek_user(struct task_struct *child, long addr, long data)
{
	unsigned long tmp;

	if ((addr & 3) || addr < 0)
		return -EIO;

	tmp = 0;  
	if (addr < MAX_REG_OFFSET) {
		tmp = getreg(child, addr);
	}
	else if ((addr >= offsetof(struct user, u_debugreg[0])) &&
		 (addr <= offsetof(struct user, u_debugreg[7]))) {
		addr -= offsetof(struct user, u_debugreg[0]);
		addr = addr >> 2;
		tmp = child->thread.arch.debugregs[addr];
	}
	return put_user(tmp, (unsigned long __user *) data);
}

static int get_fpregs(struct user_i387_struct __user *buf, struct task_struct *child)
{
	int err, n, cpu = ((struct thread_info *) child->stack)->cpu;
	struct user_i387_struct fpregs;

	err = save_fp_registers(userspace_pid[cpu], (unsigned long *) &fpregs);
	if (err)
		return err;

	n = copy_to_user(buf, &fpregs, sizeof(fpregs));
	if(n > 0)
		return -EFAULT;

	return n;
}

static int set_fpregs(struct user_i387_struct __user *buf, struct task_struct *child)
{
	int n, cpu = ((struct thread_info *) child->stack)->cpu;
	struct user_i387_struct fpregs;

	n = copy_from_user(&fpregs, buf, sizeof(fpregs));
	if (n > 0)
		return -EFAULT;

	return restore_fp_registers(userspace_pid[cpu],
				    (unsigned long *) &fpregs);
}

static int get_fpxregs(struct user_fxsr_struct __user *buf, struct task_struct *child)
{
	int err, n, cpu = ((struct thread_info *) child->stack)->cpu;
	struct user_fxsr_struct fpregs;

	err = save_fpx_registers(userspace_pid[cpu], (unsigned long *) &fpregs);
	if (err)
		return err;

	n = copy_to_user(buf, &fpregs, sizeof(fpregs));
	if(n > 0)
		return -EFAULT;

	return n;
}

static int set_fpxregs(struct user_fxsr_struct __user *buf, struct task_struct *child)
{
	int n, cpu = ((struct thread_info *) child->stack)->cpu;
	struct user_fxsr_struct fpregs;

	n = copy_from_user(&fpregs, buf, sizeof(fpregs));
	if (n > 0)
		return -EFAULT;

	return restore_fpx_registers(userspace_pid[cpu],
				     (unsigned long *) &fpregs);
}

long subarch_ptrace(struct task_struct *child, long request,
		    unsigned long addr, unsigned long data)
{
	int ret = -EIO;
	void __user *datap = (void __user *) data;
	switch (request) {
	case PTRACE_GETFPREGS: 
		ret = get_fpregs(datap, child);
		break;
	case PTRACE_SETFPREGS: 
		ret = set_fpregs(datap, child);
		break;
	case PTRACE_GETFPXREGS: 
		ret = get_fpxregs(datap, child);
		break;
	case PTRACE_SETFPXREGS: 
		ret = set_fpxregs(datap, child);
		break;
	default:
		ret = -EIO;
	}
	return ret;
}