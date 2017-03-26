obj-m += ls_module.o
KERNELDIR = /usr/src/linux-headers-4.4.0-66-generic

all:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	sudo insmod ls_module.ko
	sudo dmesg -c >> DFS_output.txt
	ps -eLf >> ps_eLf_output.txt
clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	sudo rmmod ls_module.ko
	sudo dmesg -c
	sudo rm	-r ps_eLf_output.txt DFS_output.txt
