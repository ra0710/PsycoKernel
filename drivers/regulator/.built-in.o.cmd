cmd_drivers/regulator/built-in.o :=  /mnt/android/toolchains/arm-eabi-4.8/bin/arm-eabi-ld -EL    -r -o drivers/regulator/built-in.o drivers/regulator/core.o drivers/regulator/dummy.o drivers/regulator/fixed-helper.o drivers/regulator/of_regulator.o drivers/regulator/fixed.o drivers/regulator/stub-regulator.o drivers/regulator/qpnp-regulator.o 