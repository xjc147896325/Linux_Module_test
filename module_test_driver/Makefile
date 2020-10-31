#!/bin/bash

obj-m += module_test_driver.o

KDIR := /home/topeet/zImage/iTop4412_Kernel_3.0

PWD ?= $(shell pwd)

all:	
	make -C $(KDIR) M=$(PWD) modules
		
		
clean:
	rm -rf *.o *.mod.o *.order *.symvers *.mod.c