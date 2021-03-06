#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/types.h>
#include<linux/kdev_t.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#include<linux/device.h>
#include<linux/time.h>
#include<linux/random.h>
#include "chardev.h"
#define DEVICE_NAME "/dev/imu_char"



static dev_t first;
static struct cdev c_dev;
static struct class *cls;

static int device_open(struct inode *inode, struct file *file)
{
printk (KERN_INFO "%s opened\n",DEVICE_NAME);
return 0;

}

static int device_release(struct inode *inode, struct file *file)
{
printk(KERN_INFO "%s close\n",DEVICE_NAME);
return 0;

}



void  my_read(struct file *f,char __user *buffer, size_t length, loff_t *off)
{

       printk(KERN_INFO "Subi's char reading...\n");
}

void  my_write(struct file *f,char __user *buffer, size_t length, loff_t *off)
{

       printk(KERN_INFO "Subi's char writing...\n");
}


/*declaring ioctl*/
static long device_ioctl(struct file *file,unsigned int ioctl_num,unsigned long ioctl_param)
{
 int value;
//char *temp;
//char ch;

switch (ioctl_num)
{
case IOCTL_GYRO_READ_XAXIS:
value=((ioctl_num<<2)+(ioctl_num>>2))+(ioctl_num%2)+33;
break;

case IOCTL_GYRO_READ_YAXIS:
value=((ioctl_num<<2)+(ioctl_num>>2))+(ioctl_num%2)+33;
break;

case IOCTL_GYRO_READ_ZAXIS:
value=((ioctl_num<<2)+(ioctl_num>>2))+(ioctl_num%2)+33;
break;

case IOCTL_ACCELERO_READ_XAXIS:
value=((ioctl_num<<2)+(ioctl_num>>2))+(ioctl_num%2)+33;
break;

case IOCTL_ACCELERO_READ_YAXIS:
value=((ioctl_num<<2)+(ioctl_num>>2))+(ioctl_num%2)+33;
break;

case IOCTL_ACCELERO_READ_ZAXIS:
value=((ioctl_num<<2)+(ioctl_num>>2))+(ioctl_num%2)+33;
break;

case IOCTL_MAGNETO_READ_XAXIS:
value=((ioctl_num<<2)+(ioctl_num>>2))+(ioctl_num%2)+33;
break;

case IOCTL_MAGNETO_READ_YAXIS:
value=((ioctl_num<<2)+(ioctl_num>>2))+(ioctl_num%2)+33;
break;

case IOCTL_MAGNETO_READ_ZAXIS:
value=((ioctl_num<<2)+(ioctl_num>>2))+(ioctl_num%2)+33;
break;

case IOCTL_barometer_readPressure:
value=((ioctl_num<<2)+(ioctl_num>>2))+(ioctl_num%2)+33;
break;

default:
return -1;
}
printk(KERN_INFO "%s has param=%d value=%d\n",DEVICE_NAME, ioctl_num, value);
return value;


}

static struct file_operations fops=
{
	.owner= THIS_MODULE,
	.open= device_open,
	.release= device_release,
	.read= my_read,
	.write= my_write,
        .unlocked_ioctl=device_ioctl


};

static int __init mychar_init(void)
{
	printk(KERN_INFO "Subi's char registered\n");
        
	if(alloc_chrdev_region(&first,0,10,"Subi's assignment1")<0)
	{
		return -1;
	}
         printk(KERN_INFO "Major=%d\n",MAJOR(first));
	if ((cls=class_create(THIS_MODULE,"Subi's chardrv"))==NULL)
	{
		unregister_chrdev_region(first,10);
		return -1;
	}
	if (device_create(cls,NULL,first,NULL,"imu_char")==NULL)
	{
		class_destroy(cls);
		unregister_chrdev_region(first,10);
		return -1;
	}

	cdev_init(&c_dev,&fops);
	if(cdev_add(&c_dev,first,10)==-1)
	{
		device_destroy(cls,first);
		class_destroy(cls);
		unregister_chrdev_region(first,10);
	}
	return 0;
}

static void __exit mychar_exit(void)
{
	cdev_del(&c_dev);
	device_destroy(cls,first);
	class_destroy(cls);
	unregister_chrdev_region(first,10);
	printk(KERN_INFO "Subi's char unregistered\n");
}

module_init(mychar_init);
module_exit(mychar_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SURABHI";)



