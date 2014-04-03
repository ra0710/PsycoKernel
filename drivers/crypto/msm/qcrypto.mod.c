#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x6c1934ef, "module_layout" },
	{ 0x19394941, "kmalloc_caches" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0x1424f59, "sg_copy_to_buffer" },
	{ 0x528c709d, "simple_read_from_buffer" },
	{ 0xd1b98981, "debugfs_create_dir" },
	{ 0x363c7ca4, "mem_map" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0xc45c55cd, "dev_set_drvdata" },
	{ 0xcf8cc5ee, "msm_bus_scale_unregister_client" },
	{ 0x2a4312d3, "crypto_ablkcipher_type" },
	{ 0xc6b9506c, "crypto_dequeue_request" },
	{ 0x79aa04a2, "get_random_bytes" },
	{ 0x8371daff, "sg_copy_from_buffer" },
	{ 0x8949858b, "schedule_work" },
	{ 0xdfabe0ff, "scm_call" },
	{ 0xf087137d, "__dynamic_pr_debug" },
	{ 0x78f062cb, "msm_bus_scale_client_update_request" },
	{ 0xf34378af, "mutex_unlock" },
	{ 0x62c933b3, "debugfs_create_file" },
	{ 0x103c9c3e, "qce_ablk_cipher_req" },
	{ 0x68d86d1a, "crypto_aead_type" },
	{ 0x9515c2c7, "debugfs_remove_recursive" },
	{ 0x91dda801, "scatterwalk_map_and_copy" },
	{ 0xa7ecf324, "__init_waitqueue_head" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x5f754e5a, "memset" },
	{ 0x776462ba, "msm_bus_cl_get_pdata" },
	{ 0x588e8ef4, "dev_err" },
	{ 0x8ddab831, "_raw_spin_unlock_irqrestore" },
	{ 0x27e1a049, "printk" },
	{ 0x71c90087, "memcmp" },
	{ 0xe3f0223, "wait_for_completion_interruptible" },
	{ 0xfaef0ed, "__tasklet_schedule" },
	{ 0x7d8541ba, "crypto_register_ahash" },
	{ 0xc93968d1, "mutex_lock" },
	{ 0xd26f8cb, "qce_enable_clk" },
	{ 0x9545af6d, "tasklet_init" },
	{ 0x40dac250, "platform_driver_register" },
	{ 0x499043d3, "crypto_init_queue" },
	{ 0x82072614, "tasklet_kill" },
	{ 0xbbfbb9c, "qce_hw_support" },
	{ 0xf061042e, "crypto_enqueue_request" },
	{ 0x352a292e, "_dev_info" },
	{ 0x1437bc5e, "qce_aead_req" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x827cca97, "qce_open" },
	{ 0x81a61e31, "qce_disable_clk" },
	{ 0x2f100fce, "crypto_unregister_ahash" },
	{ 0xc6715e4f, "crypto_register_alg" },
	{ 0x1af6413e, "kmem_cache_alloc_trace" },
	{ 0x1a9b678e, "_raw_spin_lock_irqsave" },
	{ 0x575c81e1, "qce_close" },
	{ 0x37a0cba, "kfree" },
	{ 0x9d669763, "memcpy" },
	{ 0x7ded90b3, "msm_bus_scale_register_client" },
	{ 0xcfd9a2c0, "des_ekey" },
	{ 0xf9e73082, "scnprintf" },
	{ 0x7a4497db, "kzfree" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0xad998077, "complete" },
	{ 0xb81960ca, "snprintf" },
	{ 0xca54fee, "_test_and_set_bit" },
	{ 0x13bd67bf, "platform_driver_unregister" },
	{ 0xfe2bdee5, "crypto_unregister_alg" },
	{ 0x4a1f9926, "dev_get_drvdata" },
	{ 0x75b45b18, "qce_process_sha_req" },
	{ 0x5795c61d, "crypto_ahash_type" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";
