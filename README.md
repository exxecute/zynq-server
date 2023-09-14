# zynq server

## content

- [Build commands](#build-commands)

    - [Build folder](#build-folder)

    - [Test build](#test-build)

- [SSH](#ssh)

    - [Config device command](#config-device-command)

## Build commands

- [Build folder](#build-folder)

- [Test build](#test-build)

### Build folder

`mkdir build`

### Test build

`cd build; gcc ../test/main.c -o test`

## SSH

- [Config device command](#config-device-command)

### Config device command

`sudo mkdir -d /run/media/[you]/ROOTFS/etc/ssh; sudo cp ./config/ssh-config/ssh_config /run/media/[you]/ROOTFS/etc/ssh`