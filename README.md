# Linux-Kernel-Module
## Running PROC
1- Compile files using **make** command
```
make
```
2- Insert module, there is two ways 
the first one just type **make ins**
```
make ins
```
the second one type each file using **insmod kernel_object_name**
```
sudo insmod jiffies.ko
sudo insmod seconds.ko
```
**ps they are the same way but I have previously modified the **make** file to shorten the required steps to insert modules**

3- Read proc file using **cat /proc/proc_name**
```
cat /proc/jiffies
cat /proc/seconds
```
4- Removing modules using 
either **make rm**
```
make rm
```
or removing them one by one using **rmmod kernel_object_name**
```
sudo rmmod jiffies.ko
sudo rmmod seconds.ko
```
