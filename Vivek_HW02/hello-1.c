#include <linux/module.h>	
#include <linux/kernel.h>	
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vivek Senapati");

static int __init hello_1_init(void)
{
	printk(KERN_INFO "Vivek: Loading Hello1 module - Hello World 1\n");
	return 0;
}

static void __exit hello_1_exit(void)
{
	printk(KERN_INFO "Vivek: Exiting Hello1 module - Goodbye World 1\n");
}

module_init(hello_1_init);
module_exit(hello_1_exit);
