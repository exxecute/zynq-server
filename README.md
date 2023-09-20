# zynq server

## content

- [Build](#build)

    - [Compiler link](#compiler-link)

    - [Build folder](#build-folder)

    - [Test build](#test-build)

    - [Main build](#main-build)

- [SSH](#ssh)

    - [Config device command](#config-device-command)

    - [Client config](#client-config-command)

    - [Server config command](#server-config-command)

    - [Connect to zynq](#connect-to-zynq-by-ssh)

- [Serial connection](#serial-connection)

- [Tests](#tests)

    - [Hello Worlds test](#hello-world-test)

    - [Server test](#server-test)

## Build

- [Compiler link](#compiler-link)

- [Build folder](#build-folder)

- [Test build](#test-build)

- [Main build](#main-build)

### Compiler link

I used GCC for arm using cross-compiling

Link:
https://developer.arm.com/downloads/-/gnu-a

### Build folder

`mkdir build`

### Test build

**Not for arm!!!**

`cd build; gcc ../test/Hello_World/main.c -o Hello_World`

For arm:

`cd build; <GCC compiler> ../test/Hello_World/main.c -o ARM_Hello_World`

`cd build; <GCC compiler> ../test/server_test/main.c -o ARM_Server_Test`

Command how I compile (**for example**):

`cd build; '/home/execute/arm gcc/gcc-arm-10.3-2021.07-x86_64-arm-none-linux-gnueabihf/bin/arm-none-linux-gnueabihf-gcc' ../test/main.c -o ARM_Hello_World`

### Main build

`cd build; <GCC compiler> ../src/main.c -o main`

Command how I compile (**for example**):

`cd build; '/home/execute/arm gcc/gcc-arm-10.3-2021.07-x86_64-arm-none-linux-gnueabihf/bin/arm-none-linux-gnueabihf-gcc' ../src/main.c -o main`

## SSH

- [Config device command](#config-device-command)

- [Client config](#client-config-command)

- [Server config command](#server-config-command)

- [Connect to zynq](#connect-to-zynq-by-ssh)

### Config device command

`sudo mkdir -d /run/media/[you]/ROOTFS/etc/ssh; 
 sudo mkdir -d /run/media/[you]/ROOTFS/etc/ssh/ssh_config.d; 
 sudo mkdir -d /run/media/[you]/ROOTFS/etc/ssh/sshd_config.d; 
 sudo cp ./config/ssh-config/ssh_config /run/media/[you]/ROOTFS/etc/ssh; 
 sudo cp ./config/ssh-config/zynq_server.conf /run/media/[you]/ROOTFS/etc/ssh/ssh_config.d;
 sudo cp ./config/ssh-config/sshd_config /run/media/[you]/ROOTFS/etc/ssh;
 sudo cp ./config/ssh-config/sshd_config.conf /run/media/[you]/ROOTFS/etc/ssh/sshd_config.d;`

### Client config command

`sudo ./config/client-config/client_config.sh <interface>`

My interface was **eno1**

### Server config command

`./server-configurations/ip/server_config.sh`

### Connect to zynq by SSH

`ssh -Tv -oHostKeyAlgorithms=+ssh-rsa root@192.168.122.115`

password:**root**

## Serial connection

`sudo ./serial-connect.sh <dev>`

example:

`sudo ./serial-connect.sh /dev/ttyUSB0`

## Tests

- [Hello Worlds test](#hello-world-test)

- [Server test](#server-test)

### Hello World test

Prints **Hello world** in terminal.
For testing correct compiling.

### Server test

Recieves request message and sends answer message.