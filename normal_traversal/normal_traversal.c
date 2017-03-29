// Including the linux kernel module libraries
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/list.h>

/*
    *priniting_mesg prints out the headlines of each of the three columns
    *printing_tasks_info prints out the name, state and pid of each task
    *   task_comm is the name of the task
    *   task_state is the state of the task
    *   task_pid is the process id of the task
*/
#define printing_mesg printk("%-20s%-20s%s\n", "TASKNAME", "STATE", "PID");
#define printing_tasks_info(task_comm, task_state, task_pid) \
    printk("%-20s%-20ld%-20d\n", task_comm, task_state, task_pid);


void tasks_traversal(void)
{
    struct task_struct *task;
    for_each_process(task)
    {
        printing_tasks_info(task->comm, task->state, task->pid);
    }
}
int module_start(void)
{
    printk("\tPrinting tasks in normal order \n\n");
    printing_mesg;
    tasks_traversal();
    return 0;
}
void module_end(void)
{
    printk(KERN_INFO "\tRemoved ls_modules\n");
}

module_init(module_start);
module_exit(module_end);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ahmed Nofal");
MODULE_DESCRIPTION("This is just a module to try loading and removing the tasks lister module");
