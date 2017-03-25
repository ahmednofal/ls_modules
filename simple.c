// Including the linux kernel module libraries
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>


int module_start(void)
{
    printk(KERN_INFO"\nhello world from the new module\n");
    return 0;
}
void module_end(void)
{
    printk(KERN_INFO"\nBye, World from the new module\n");
}


module_init(module_start);
module_exit(module_end);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ahmed Nofal");
MODULE_DESCRIPTION("This is just a module to try loading and removing kernel modules");


