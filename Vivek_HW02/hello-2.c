#include <linux/module.h>	
#include <linux/kernel.h>	
#include <linux/init.h>		

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vivek Senapati");

static int hello2_data __initdata = 2;

static int __init hello_2_init(void)
{
	printk(KERN_INFO "Vivek: Loading Hello 2 module - Hello World 2\n");
	printk(KERN_INFO "Vivek: Number %d is printed using __initdata\n", hello2_data);
	return 0;
}

static void __exit hello_2_exit(void)
{
	printk(KERN_INFO "Vivek: Exiting Hello 2 module - Goodbye World 2\n");
}

module_init(hello_2_init);
module_exit(hello_2_exit);
