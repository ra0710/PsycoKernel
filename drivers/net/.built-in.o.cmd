cmd_drivers/net/built-in.o :=  /mnt/android/toolchains/arm-eabi-4.8/bin/arm-eabi-ld -EL    -r -o drivers/net/built-in.o drivers/net/dummy.o drivers/net/mii.o drivers/net/Space.o drivers/net/loopback.o drivers/net/tun.o drivers/net/ethernet/built-in.o drivers/net/ppp/built-in.o drivers/net/slip/built-in.o drivers/net/wireless/built-in.o drivers/net/usb/built-in.o 