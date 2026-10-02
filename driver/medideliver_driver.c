#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MediDeliver Project");
MODULE_DESCRIPTION("MediDeliver Linux Kernel Module");
MODULE_VERSION("1.0");

static int __init medideliver_driver_init(void)
{
    printk(KERN_INFO "MediDeliver driver loaded successfully\n");
    return 0;
}

static void __exit medideliver_driver_exit(void)
{
    printk(KERN_INFO "MediDeliver driver unloaded successfully\n");
}

module_init(medideliver_driver_init);
module_exit(medideliver_driver_exit);
