![Screenshot from 2022-06-14 11-02-17](https://user-images.githubusercontent.com/105910992/173501192-11411236-b73a-4a09-84ef-c5f048ca00f4.png)
U-Boot

  - git clone <https://source.denx.de/u-boot/u-boot.git>
  - ls configs
  - make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-
  - make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- qemu_arm_defconfig
  - make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-
  - qemu-system-arm -machine ?
  - qemu-system-arm -machine virt -serial stdio -display none -bios u-boot.bin
  - U-Boot shell
    - bdinfo
    - setenv
    - printenv
    - saveenv
  - make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- menuconfig
  - make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- clean
  - make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- mrproper


- Kernel

  - make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- bcm2835_defconfig
  - make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-
  - qemu-system-arm -M raspi2 -m 512M -kernel arch/arm/boot/zImage -nographic -append "console=ttyAMA0,115200 root=/dev/mmcblk0p2 rootwait rw" -cpu cortex-a15 -dtb ./arch/arm/boot/dts/bcm2836-rpi-2-b.dtb

- Root FS

  - wget <https://busybox.net/downloads/busybox-1.32.1.tar.bz2>
  - bunzip2 < busybox-1.32.1.tar.bz2 | tar xvf -
  - cd busybox-1.32.1
  - make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- defconfig
  - make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- menuconfig
    - Enable static linking
  - make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- install
    - Create root fs in \_install directory locally
  - cd \_install
  - find . | cpio -o --format=newc > ../rootfs.img
  - cd ..
  - gzip -c rootfs.img > rootfs.img.gz
  - qemu-system-arm -M raspi2 -m 512M -kernel zImage -nographic -append "console=ttyAMA0,115200" -cpu cortex-a15 -dtb bcm2836-rpi-2-b.dtb -initrd rootfs.img.gz -append "root=/dev/ram rdinit=/bin/sh"
