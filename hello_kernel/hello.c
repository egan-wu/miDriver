#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/jiffies.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("egan_wu");
MODULE_DESCRIPTION("A simple Hello Kernel Module");
MODULE_VERSION("1.2.1");

// default values
static char *user = "Default";
module_param(user, charp, 0644); // (param, dtype, permission)
MODULE_PARM_DESC(user, "The name of user");

// allocate buffer
static char *buffer;
static int buf_size;
MODULE_PARM_DESC(buffer, "The buffer allocated during initial");
MODULE_PARM_DESC(buf_size, "Total buffer size in dword");
module_param(buf_size, int, 0644); // (param, dtype, permission)

static int __init hello_init(void) {
    buffer = kmalloc(buf_size, GFP_KERNEL); // allocate 128-DW
    if (!buffer) {
        pr_err("[%lu] Error, Failed to allocate memory(%d)!\n", jiffies, buf_size);
        return -ENOMEM;
    }

    printk(KERN_INFO "[%lu] Hello, Kernel!\n", jiffies);
    printk(KERN_INFO "[%lu] Hello, %s!\n", jiffies, user);
    printk(KERN_INFO "[%lu] allocated buffer size: %d\n", jiffies, buf_size);
    return 0;
}

static void __exit hello_exit(void) {
    printk(KERN_INFO "[%lu] Goodbye, Kernel!\n", jiffies);
    printk(KERN_INFO "[%lu] Goodbye, %s!\n", jiffies, user);
}

module_init(hello_init);
module_exit(hello_exit);

