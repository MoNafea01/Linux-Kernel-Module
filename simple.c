#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <asm/param.h>
#include <linux/jiffies.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mohamed Nafea");
MODULE_DESCRIPTION("simple module example");
MODULE_VERSION("0.01");

int simple_init(void){
	printk(KERN_INFO "%lu \t %d\n", jiffies, HZ);
	return 0;
}

void simple_exit(void){
	printk(KERN_INFO "%lu\n", jiffies);
}

module_init(simple_init);
module_exit(simple_exit);
