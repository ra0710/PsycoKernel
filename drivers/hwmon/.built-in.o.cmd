cmd_drivers/hwmon/built-in.o :=  /mnt/android/toolchains/arm-eabi-4.8/bin/arm-eabi-ld -EL    -r -o drivers/hwmon/built-in.o drivers/hwmon/hwmon.o drivers/hwmon/epm_adc.o drivers/hwmon/qpnp-adc-voltage.o drivers/hwmon/qpnp-adc-common.o drivers/hwmon/qpnp-adc-current.o 