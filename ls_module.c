// Including the linux kernel module libraries
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/list.h>

//#include <bits/sched.h>

struct task_struct *task;
#define WIDTHOFWHITESPACES -20
/*
    *priniting_mesg prints out the headlines of each of the three columns
    *printing_tasks_info prints out the name, state and pid of each task
    *   task_comm is the name of the task
    *   task_state is the state of the task
    *   task_pid is the process id of the task
*/
#define printing_mesg printk("%-20s%-20s%s", "TASKNAME", "STATE", "PID");
#define printing_tasks_info(task_comm, task_state, task_pid) \
    printk("\n%-20s%-20ld%-20d\n", task_comm, task_state, task_pid);

/*
    *tasks_traversak_as_DFS uses the macros list_for_each, list_entry to output the name, state and pid of each task
    *in a Depth First Search manner utilizing the tree nature of the processes struct in linux
    *   list_for_each is from the list.h file, description can be found there
    *   list_entry is in the list.h description can be found there
*/
//printk("%-20%-20%s", "TASKNAME", "STATE", "PID");

void tasks_traversal_as_DFS(struct task_struct *head_task)
{

    struct list_head *list;
    struct list_head *head_task_children_list = &(head_task->children);
    //struct list_head *current_task_children_list;

    // Children, Sibling, list_for_each, struct list head, init_task, list_entry
    if (head_task!= NULL)
    {
        printing_tasks_info(head_task->comm, head_task->state, head_task->pid);
        list_for_each(list, head_task_children_list)
        {
            task = list_entry(list, struct task_struct, sibling);
            /* task points to the next child in the list */
            tasks_traversal_as_DFS(task);
        }
    }
}

void tasks_traversal(void)
{
    printing_mesg;
    for_each_process(task)
    {
        printing_tasks_info(task->comm, task->state, task->pid);
    }
}
int module_start(void)
{
    //tasks_traversal();
    printk("\nPrinting tasks DFS Mode \n\n");
    printing_mesg;
    tasks_traversal_as_DFS(&init_task);

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
