obj-m += ls_module.o
KERNELDIR = /usr/src/linux-headers-4.4.0-66-generic

all:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
