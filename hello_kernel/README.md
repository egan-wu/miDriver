# Hello Kernel

## Main Target
* Implement a **hello.ko** kernel
    * print "hello" when being loaded into OS.
    * print "goodbye" when being removed from OS.

### build hello kernel
Use the following command to build kernel objects
```
   cd ./hello_kernel
   make 
```
> You should see hello_kernel.ko in your repository

### insert module
Use the following command to insert kernel
```
    sudo insmod hello.ko
```

> After inserting module, you can check kernel message by following command.
```
    sudo dmesg | tail -5 -n
```
> You should see something similar as the follow message.
```
    ...
    [ 2746.745650] Hello, Kernel!
```

### check module list
Use the following command to check whether hello.ko is actually inserted 
```
    lsmod
```
> You should find **hello** in the list similar like the following
```
    Module                  Size  Used by
    ...
    hello                  12288  0
    tls                   155648  0
    8021q                  45056  0
    ...
```

### remove module
```
    sudo rmmod hello
```

> After removing module, you can check kernel message again by following command.
```
    sudo dmesg | tail -5 -n
```
> You should see something similar as the follow message.
```
    ...
    [10518.070881] Goodbye, Kernel!
```