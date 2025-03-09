#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/jiffies.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("egan_wu");
MODULE_DESCRIPTION("A simple Hello Kernel Module");
MODULE_VERSION("1.2");

// default values
static char *user = "Default";
module_param(user, charp, 0644); // (param, dtype, permission)
MODULE_PARM_DESC(user, "The name of user");

static int __init hello_init(void) {
    printk(KERN_INFO "[%lu] Hello, Kernel!\n", jiffies);
    printk(KERN_INFO "[%lu] Hello, %s!\n", jiffies, user);
    return 0;
}

static void __exit hello_exit(void) {
    printk(KERN_INFO "[%lu] Goodbye, Kernel!\n", jiffies);
    printk(KERN_INFO "[%lu] Goodbye, %s!\n", jiffies, user);
}

module_init(hello_init);
module_exit(hello_exit);

