#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>

struct birthday{
  int day;
  int month;
  int year;
  struct list_head list;

};

  
static LIST_HEAD(birthday_list);
/* This function is called when the module is loaded. */
int simple_init(void)
{

  struct birthday*person;
  person=kmalloc(sizeof(*person), GFP_KERNEL);
  person->day=2;
  person->month=8;
  person->year=1995;
  // person->list=birthday_list;
 INIT_LIST_HEAD(&person->list);
  list_add_tail(&person->list,&birthday_list);

      struct birthday*person2;
  person2=kmalloc(sizeof(*person2), GFP_KERNEL);
  person2->day=3;
  person2->month=9;
  person2->year=1996;
  INIT_LIST_HEAD(&person2->list); 
list_add_tail(&person2->list,&birthday_list);

struct birthday*person3;
  person3=kmalloc(sizeof(*person3), GFP_KERNEL);
  person3->day=4;
  person3->month=10;
  person3->year=1997;
  INIT_LIST_HEAD(&person3->list);
 
  list_add_tail(&person3->list,&birthday_list);

struct birthday*person4;
  person4=kmalloc(sizeof(*person4), GFP_KERNEL);
  person4->day=5;
  person4->month=11;
  person4->year=1998;
  INIT_LIST_HEAD(&person4->list);
 
  list_add_tail(&person4->list,&birthday_list);


struct birthday*person5;
  person5=kmalloc(sizeof(*person5), GFP_KERNEL);
  person5->day=6;
  person5->month=12;
  person5->year=1999;
  INIT_LIST_HEAD(&person5->list);
 
  list_add_tail(&person5->list,&birthday_list);


printk(KERN_INFO "Adding Module\n");
       struct birthday *ptr;
       list_for_each_entry(ptr,&birthday_list,list){
	 printk(KERN_INFO "birthday_info:1)year:%d;2)month:%d;3)day:%d",ptr->year,ptr->month,ptr->day);
       }
       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
	struct birthday *ptr, *next;
	 list_for_each_entry_safe(ptr,next,&birthday_list,list){
	  list_del(&ptr->list);
	  
	  printk(KERN_INFO "delete birthday_info:1)year:%d;2)month:%d;3)day:%d",ptr->year,ptr->month,ptr->day);
kfree(ptr);

	}

}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

