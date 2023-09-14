# zynq server

## content

- [Build commands](#build-commands)

    - [Build folder](#build-folder)

    - [Test build](#test-build)

- [SSH](#ssh)

    - [Config device command](#config-device-command)

    - [Client config](#client-config-command)

    - [Server config command](#server-config-command)

    - [Connect to zynq](#connect-to-zynq-by-ssh)

## Build commands

- [Build folder](#build-folder)

- [Test build](#test-build)

### Build folder

`mkdir build`

### Test build

`cd build; gcc ../test/main.c -o test`

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