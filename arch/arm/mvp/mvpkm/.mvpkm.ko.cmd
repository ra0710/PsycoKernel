cmd_arch/arm/mvp/mvpkm/mvpkm.ko := /mnt/android/toolchains/arm-eabi-4.8/bin/arm-eabi-ld -EL -r  -T /mnt/android/M8Kernel/M8_ATT/scripts/module-common.lds --build-id  -o arch/arm/mvp/mvpkm/mvpkm.ko arch/arm/mvp/mvpkm/mvpkm.o arch/arm/mvp/mvpkm/mvpkm.mod.o