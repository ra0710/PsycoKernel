cmd_arch/arm/boot/msm8974pro-ab-pm8941-m8-xf.dtb := /mnt/android/M8Kernel/M8_ATT/scripts/dtc/dtc -O dtb -o arch/arm/boot/msm8974pro-ab-pm8941-m8-xf.dtb -b 0  -d arch/arm/boot/.msm8974pro-ab-pm8941-m8-xf.dtb.d arch/arm/boot/dts/msm8974pro-ab-pm8941-m8-xf.dts

source_arch/arm/boot/msm8974pro-ab-pm8941-m8-xf.dtb := arch/arm/boot/dts/msm8974pro-ab-pm8941-m8-xf.dts

deps_arch/arm/boot/msm8974pro-ab-pm8941-m8-xf.dtb := \
  arch/arm/boot/dts/msm8974pro-ab-pm8941.dtsi \
  arch/arm/boot/dts/msm8974pro-pm8941.dtsi \
  arch/arm/boot/dts/msm8974pro.dtsi \
  arch/arm/boot/dts/msm8974.dtsi \
  arch/arm/boot/dts/skeleton.dtsi \
  arch/arm/boot/dts/msm8974-camera.dtsi \
  arch/arm/boot/dts/msm8974-coresight.dtsi \
  arch/arm/boot/dts/msm-gdsc.dtsi \
  arch/arm/boot/dts/msm8974-ion.dtsi \
  arch/arm/boot/dts/msm8974-gpu.dtsi \
  arch/arm/boot/dts/msm8974-mdss.dtsi \
  arch/arm/boot/dts/msm8974-smp2p.dtsi \
  arch/arm/boot/dts/msm8974-bus.dtsi \
  arch/arm/boot/dts/msm8974-htc.dtsi \
  arch/arm/boot/dts/msm-rdbg.dtsi \
  arch/arm/boot/dts/msm8974-v2-iommu.dtsi \
  arch/arm/boot/dts/msm-iommu-v1.dtsi \
  arch/arm/boot/dts/msm8974-v2-iommu-domains.dtsi \
  arch/arm/boot/dts/msm8974pro-pm.dtsi \
  arch/arm/boot/dts/msm8974pro-ion.dtsi \
  arch/arm/boot/dts/msm-pm8x41-rpm-regulator.dtsi \
  arch/arm/boot/dts/msm-pm8841.dtsi \
  arch/arm/boot/dts/msm-pm8941.dtsi \
  arch/arm/boot/dts/msm8974-regulator.dtsi \
  arch/arm/boot/dts/msm-pm8x41-vreg-dump.dtsi \
  arch/arm/boot/dts/msm8974-clock.dtsi \
  arch/arm/boot/dts/msm8974-m8-common.dtsi \
  arch/arm/boot/dts/dsi-panel-m8.dtsi \
  arch/arm/boot/dts/msm8974-leds.dtsi \
  arch/arm/boot/dts/batterydata-m8-id1.dtsi \
  arch/arm/boot/dts/batterydata-m8-id2.dtsi \
  arch/arm/boot/dts/batterydata-m8-id3.dtsi \
  arch/arm/boot/dts/batterydata-m8-unknown-id.dtsi \
  arch/arm/boot/dts/msm8974-camera-sensor-m8-ver-b.dtsi \
  arch/arm/boot/dts/msm8974-m8-xb-pmicgpio.dtsi \
  arch/arm/boot/dts/msm8974-touch-fw-0key-config.dtsi \
  arch/arm/boot/dts/msm8974-m8-storage.dtsi \

arch/arm/boot/msm8974pro-ab-pm8941-m8-xf.dtb: $(deps_arch/arm/boot/msm8974pro-ab-pm8941-m8-xf.dtb)

$(deps_arch/arm/boot/msm8974pro-ab-pm8941-m8-xf.dtb):