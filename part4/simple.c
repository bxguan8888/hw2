#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/sched.h>


//dfs function 
//level is the depth of the dfs tree
void dfs(struct task_struct*parent_task,int level){
  struct task_struct *task;
  struct list_head *list;
  list_for_each(list,&parent_task->children){
    task=list_entry(list,struct task_struct,sibling);
    int i=0;
    int count=4;
    char s[level*count+1];


 for(i=0;i<level*count;i++)
      {
	s[i]=' ';
      }
 s[i]='\0';

 printk(KERN_INFO"%s\\_[%d]%s",s,task->pid,task->comm);
      dfs(task,level+1);
  }


}

  
static LIST_HEAD(birthday_list);
/* This function is called when the module is loaded. */
int simple_init(void)
{
  //print the pcb of init procss
  printk(KERN_INFO"\\_[%d]%s",(&init_task)->pid,(&init_task)->comm);

  //start dfs
  dfs(&init_task,1);
  

  
       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
	

}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

