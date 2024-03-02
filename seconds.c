#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <asm/param.h>

#define BUFFER_SIZE 128
#define PROC_NAME "seconds"

unsigned long jiffies_start, jiffies_end, elapsed_time;

ssize_t proc_read(struct file *file, char __user *usr_buf,size_t count, loff_t *pos);

static const struct file_operations proc_ops ={
  .owner = THIS_MODULE,
  .read = proc_read,
};

int proc_init(void){
  jiffies_start = jiffies;
  proc_create(PROC_NAME, 0666, NULL, (const struct proc_ops*)&proc_ops);
  return 0;
}

void proc_exit(void){
  remove_proc_entry(PROC_NAME, NULL);
}

ssize_t proc_read(struct file *file, char  __user *usr_buf,size_t count, loff_t *pos)
{
  int rv = 0;
  char buffer[BUFFER_SIZE];
  static int completed = 0;
  
  if (completed)
  {
  completed = 0;
  return 0;
  }
  completed = 1;
  jiffies_end = jiffies;
  elapsed_time = jiffies_end - jiffies_start;
  rv = sprintf(buffer, "ELAPSED TIME : %lu \n",elapsed_time/HZ);
  copy_to_user(usr_buf, buffer, rv);
  return rv;
}

module_init(proc_init);
module_exit(proc_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("JIFFIES MODULE");
MODULE_AUTHOR("NAFEA");
