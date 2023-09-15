# zynq server

## content

- [Build](#build)

    - [Compiler link](#compiler-link)

    - [Build folder](#build-folder)

    - [Test build](#test-build)

- [SSH](#ssh)

    - [Config device command](#config-device-command)

    - [Client config](#client-config-command)

    - [Server config command](#server-config-command)

    - [Connect to zynq](#connect-to-zynq-by-ssh)

## Build

- [Compiler link](#compiler-link)

- [Build folder](#build-folder)

- [Test build](#test-build)

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

`<GCC compiler> ../test/Hello_World/main.c -o ARM_Hello_World`

Command how I compile (**for example**):

`'/home/execute/arm gcc/gcc-arm-10.3-2021.07-x86_64-arm-none-linux-gnueabihf/bin/arm-none-linux-gnueabihf-gcc' ../test/main.c -o ARM_Hello_World`

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