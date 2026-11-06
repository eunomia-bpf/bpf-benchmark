SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ACCEL ?= tcg
CPU ?= max
CPUS ?= 2
MEMORY ?= 2048

.PHONY: run
run:
	install -d results
	timeout 7200 qemu-system-aarch64 -M virt -accel $(ACCEL) -cpu $(CPU) -smp $(CPUS) -m $(MEMORY) -nographic -no-reboot \
		-kernel Image -initrd initramfs.cpio.gz \
		-fsdev local,id=results,path=$(CURDIR)/results,security_model=none \
		-device virtio-9p-device,fsdev=results,mount_tag=results \
		-append 'console=ttyAMA0 rdinit=/init loglevel=4 panic=30 oops=panic' >qemu.log 2>&1
	test "$$(cat results/guest-status)" = 0
