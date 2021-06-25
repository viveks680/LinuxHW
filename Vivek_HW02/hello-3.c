#include <linux/module.h>
#include <linux/moduleparam.h>	
#include <linux/kernel.h>	
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vivek Senapati");		


static char *name = "blank";
static char *street = "blank";
static char *city = "blank";
static int zip = 999;

module_param(name, charp , 0000);
module_param(street, charp , 0000);
module_param(city, charp , 0000);
module_param(zip, int, 0000);

static int __init hello_3_init(void)
{
	printk(KERN_INFO "Vivek: Loading Hello3 module - Hello World 3\n");
	printk(KERN_INFO "Vivek: =====================================\n");
	printk(KERN_INFO "Vivek: Name : %s\n", name);
	printk(KERN_INFO "Vivek: Street : %s\n", street);
	printk(KERN_INFO "Vivek: City : %s\n", city);
	printk(KERN_INFO "Vivek: ZIP code : %d\n", zip);
	return 0;
}

static void __exit hello_3_exit(void)
{
	printk(KERN_INFO "Vivek: Exiting Hello3 module - Goodbye World 3\n");
}

module_init(hello_3_init);
module_exit(hello_3_exit);
