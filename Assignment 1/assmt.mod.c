#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x8bc1d4a6, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x378f389b, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0xd22e6e52, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x1e4887eb, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0xdbd8d99d, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xca66795d, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0xc2e36dcc, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x1b4996ba, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "1AE6C495936528A1B350722");
