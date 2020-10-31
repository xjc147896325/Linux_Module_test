#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("jOKERII");

static int hello_init(void)
{
	printk(KERN_EMERG "HELLO WORLD, now the module is enterd");
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_EMERG "HELLO WORLD, now the module has exited");
}

module_init(hello_init);
module_exit(hello_exit);

