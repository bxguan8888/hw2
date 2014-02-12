#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>


//my define for list_for_each_entry
#define list_for_each_entry(pos, head, member)                          \
        for (pos = list_entry((head)->next, typeof(*pos), member);      \
             &pos->member != (head);    \
             pos = list_entry(pos->member.next, typeof(*pos), member))

//my define for list_each_entry_safe
#define list_for_each_entry_safe(pos, n, head, member)                  \
        for (pos = list_entry((head)->next, typeof(*pos), member),      \
                n = list_entry(pos->member.next, typeof(*pos), member); \
             &pos->member != (head);                                    \
             pos = n, n = list_entry(n->member.next, typeof(*n), member))


#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
        struct list_head name = LIST_HEAD_INIT(name)


#ifdef CONFIG_ILLEGAL_POINTER_VALUE
# define POISON_POINTER_DELTA _AC(CONFIG_ILLEGAL_POINTER_VALUE, UL)
#else
# define POISON_POINTER_DELTA 0
#endif
#define LIST_POISON1  ((void *) 0x00100100 + POISON_POINTER_DELTA)
#define LIST_POISON2  ((void *) 0x00200200 + POISON_POINTER_DELTA)



struct birthday{
  int day;
  int month;
  int year;
  struct list_head list;

};

//my version of list_add_tail_refined
void list_add_tail_refined(struct list_head*new, struct list_head *head){
  struct list_head*prev=head->prev;
  head->prev=new;
  new->next=head;
  new->prev=prev;
  prev->next=new;
}

//my version of list_del
void list_del_refined(struct list_head*entry){
  struct list_head*prev=entry->prev;
  struct list_head*next=entry->next;
  next->prev=prev;
  prev->next=next;



}

  
static LIST_HEAD(birthday_list);
/* This function is called when the module is loaded. */
int simple_init(void)
{

  struct birthday*person;
  person=kmalloc(sizeof(*person), GFP_KERNEL);
  person->day=2;
  person->month=8;
  person->year=1995;
  INIT_LIST_HEAD(&person->list);
 
  list_add_tail_refined(&person->list,&birthday_list);

      struct birthday*person2;
  person2=kmalloc(sizeof(*person2), GFP_KERNEL);
  person2->day=3;
  person2->month=9;
  person2->year=1996;
  INIT_LIST_HEAD(&person2->list); 
list_add_tail_refined(&person2->list,&birthday_list);

struct birthday*person3;
  person3=kmalloc(sizeof(*person3), GFP_KERNEL);
  person3->day=4;
  person3->month=10;
  person3->year=1997;
  INIT_LIST_HEAD(&person3->list);
 
  list_add_tail_refined(&person3->list,&birthday_list);

struct birthday*person4;
  person4=kmalloc(sizeof(*person4), GFP_KERNEL);
  person4->day=5;
  person4->month=11;
  person4->year=1998;
  INIT_LIST_HEAD(&person4->list);
 
  list_add_tail_refined(&person4->list,&birthday_list);


struct birthday*person5;
  person5=kmalloc(sizeof(*person5), GFP_KERNEL);
  person5->day=6;
  person5->month=12;
  person5->year=1999;
  INIT_LIST_HEAD(&person5->list);
 
  list_add_tail_refined(&person5->list,&birthday_list);



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
	  list_del_refined(&ptr->list);

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

