// Including the linux kernel module libraries
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
//#include <bits/sched.h>

struct task_struct *task;
// Traverse tasks as a dfs
void tasks_traversal_as_DFS()
{
    printk("\nPrinting tasks normally \n\n");
    printk("%-20s%-20s%s", "TASKNAME", "STATE", "PID");
    for_each_process(task)
    {
        printk("\n%-20s%-20ld%-20d\n", task->comm, task->state, task->pid);
    }
}
void tasks_traversal()
{
    printk("%-20s%-20s%s", "TASKNAME", "STATE", "PID");
    for_each_process(task)
    {
        printk("\n%-20s%-20ld%-20d\n", task->comm, task->state, task->pid);
    }
}
int module_start(void)
{
    tasks_traversal();
    tasks_traversal_as_DFS();

    return 0;
}
void module_end(void)
{
    printk(KERN_INFO "\nBye, World from the ls_module file\n");
}

module_init(module_start);
module_exit(module_end);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ahmed Nofal");
MODULE_DESCRIPTION("This is just a module to try loading and removing the tasks lister module");
