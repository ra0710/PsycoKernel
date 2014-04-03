#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x6c1934ef, "module_layout" },
	{ 0x19394941, "kmalloc_caches" },
	{ 0x15692c87, "param_ops_int" },
	{ 0x6d4f69dd, "i2c_transfer" },
	{ 0xf34378af, "mutex_unlock" },
	{ 0x7d11c268, "jiffies" },
	{ 0x472d15ff, "i2c_clients_command" },
	{ 0xc2821775, "tuner_count" },
	{ 0x27e1a049, "printk" },
	{ 0x73e20c1c, "strlcpy" },
	{ 0xc93968d1, "mutex_lock" },
	{ 0xe6b3b90a, "arm_delay_ops" },
	{ 0x3bd1b1f6, "msecs_to_jiffies" },
	{ 0x1af6413e, "kmem_cache_alloc_trace" },
	{ 0x37a0cba, "kfree" },
	{ 0x9d669763, "memcpy" },
	{ 0x4845c423, "param_array_ops" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0xcb4b189, "tuners" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=tuner-types";
