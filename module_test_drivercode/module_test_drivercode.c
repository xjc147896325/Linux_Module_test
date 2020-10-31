#include <linux/init.h>
#include <linux/module.h>

/* 驱动注册头文件 包含驱动的结构体和注册卸载的函数*/
#include <linux/platform_device.h>
/*注册杂项设备的头文件*/
#include <linux/miscdevice.h>
/*注册设备节点的文件的结构体*/
#include <linux/fs.h>

#define  DRIVER_NAME "hello_ctl"
#define  DEVICE_NAME "hello_ctl"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("jOKERII");

static long hello_ioctl(struct file *files, unsigned int cmd, unsigned long arg)
{
	printk("cmd is %d, arg is %d\n",cmd,arg);
	return 0;
}

static int hello_release(struct inode *inode, struct file *file)
{
	printk(KERN_EMERG "hello_release\n");
	return 0;
}

static int hello_open(struct inode *inode, struct file *file)
{
	printk(KERN_EMERG "hello_open\n");
	return 0;
}

static struct file_operations hello_ops = 
{
	.owmer = THIS_MODULE,
	.open = hello_open,
	.release = hello_release,
	.unlocked_ioctl = hello_ioctl,
};

static struct miscdevice hello_dev = 
{
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEVICE_NAME,
	.fops  = &hello_ops,
}
	
	
static int hello_probe(struct platform_device *pdv)
{
	printk(KERN_EMERG "\tinitialized\n");
	misc_register(&hello_dev);
	
	return 0;
}

static int hello_remove(struct platform_device *pdv)
{
	printk(KERN_EMERG "\tremove\n");
	misc_deregister(&hello_dev);
	
	return 0;
}

static void hello_shutdown(struct platform_device *pdv)
{
	;
}

static int hello_suspend(struct platform_device *pdv)
{
	
	return 0;
}

static int hello_resume(struct platform_device *pdv)
{
	
	return 0;
}


struct platform_driver hello_driver = 
{
	.probe     = hello_probe,
	.remove    = hello_remove,
	.shutdown  = hello_shutdown,
	.suspend   = hello_suspend,
	.resume    = hello_resume,
	.driver    = {
		.name  = DRIVER_NAME,
		.owner = THIS_MODULE,
	}
};


static int hello_init(void)
{
	int DriverState;
	
	printk(KERN_EMERG "HELLO WORLD, now the module is enterd\n");
	
	DriverState = platform_driver_register(&hello_driver);
	
	printk(KERN_EMERG "\tDriverState is %d\n", DriverState);
	
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_EMERG "HELLO WORLD, now the module has exited\n");
	
	platform_driver_unregister(&hello_driver);
}

module_init(hello_init);
module_exit(hello_exit);

