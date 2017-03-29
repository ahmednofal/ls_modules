obj-m += normal_traversal.o

all:
	@$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	@sudo insmod normal_traversal.ko
	@sudo dmesg -c >> ../normal_traversal_output.txt
	@ps -el >> ../ps_el_output.txt
	
clean:
	@$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	@sudo rmmod normal_traversal.ko
	@sudo dmesg -c
