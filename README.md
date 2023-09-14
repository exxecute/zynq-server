# zynq server

## content

- [Build commands](#build-commands)

    - [Build folder](#build-folder)

    - [Test build](#test-build)

- [SSH](#ssh)

    - [Config device command](#config-device-command)

    - [Client config](#client-config-command)

    - [Server config command](#server-config-command)

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

### Config device command

`sudo mkdir -d /run/media/[you]/ROOTFS/etc/ssh; sudo cp ./config/ssh-config/ssh_config /run/media/[you]/ROOTFS/etc/ssh`

### Client config command

`sudo ./config/client-config/client_config.sh <interface>`

My interface was **eno1**

### Server config command

``