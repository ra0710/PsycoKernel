cmd_crypto/ansi_cprng.ko := /mnt/android/toolchains/arm-eabi-4.8/bin/arm-eabi-ld -EL -r  -T /mnt/android/M8Kernel/M8_ATT/scripts/module-common.lds --build-id  -o crypto/ansi_cprng.ko crypto/ansi_cprng.o crypto/ansi_cprng.mod.o