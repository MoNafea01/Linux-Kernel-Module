obj-m += jiffies.o
obj-m += seconds.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
ins:
	sudo insmod jiffies.ko 
	sudo insmod seconds.ko
rm:
	sudo rmmod jiffies.ko 
	sudo rmmod seconds.ko
