# define the object file to be build
obj-m += hello.o

# define kernel source directory
KERNEL_DIR := /lib/modules/$(shell uname -r)/build

# define currect working directory
PWD := $(shell pwd)

# specified GCC compiler version
CC := x86_64-linux-gnu-gcc-13

all:
	make -C $(KERNEL_DIR) M=$(PWD) CC=$(CC) modules

clean:
	make -C $(KERNEL_DIR) M=$(PWD) CC=$(CC) clean
	