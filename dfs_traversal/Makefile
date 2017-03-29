obj-m += dfs_traversal_tasks.o

all:
	@$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	@sudo insmod dfs_traversal_tasks.ko
	@sudo dmesg -c >> ../DFS_output.txt
	@ps -eLf >> ../ps_eLf_output.txt
clean:
	@$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	@sudo rmmod dfs_traversal_tasks.ko
	@sudo dmesg -c
	@sudo rm -r *.txt
