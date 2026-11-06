SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ACCEL ?= tcg
CPU ?= cortex-a57
CPUS ?= 8
MEMORY ?= 4096
APP ?= bcc/set
SAMPLES ?= 1
WORKLOAD_DURATION ?= 2
BPF_STATS ?= 1
IMAGE_TAR ?= image.tar
ROOTFS ?= $(CURDIR)/root
IMAGE := $(shell cat runtime-image.txt)

.PHONY: prepare configure run
prepare: $(ROOTFS)/qemu-init

$(ROOTFS)/qemu-init: $(IMAGE_TAR) qemu-init
	docker load -i $(IMAGE_TAR)
	install -d $(ROOTFS)
	container=$$(docker create $(IMAGE)); \
	trap 'docker rm "$$container" >/dev/null' EXIT; \
	docker export "$$container" | tar -xpf - -C $(ROOTFS)
	install -m 0755 qemu-init $(ROOTFS)/qemu-init

configure: prepare
	python3 configure.py $(ROOTFS) '$(APP)' $(SAMPLES) $(WORKLOAD_DURATION) $(BPF_STATS)

run: configure
	if test -f qemu.log; then \
		install -d logs; previous=logs/$$(date -u +%Y%m%dT%H%M%S%N); \
		mv qemu.log "$$previous.qemu.log"; \
		if test -f host.txt; then mv host.txt "$$previous.host.txt"; fi; \
	fi
	uname -a >host.txt
	timeout 7200 qemu-system-aarch64 -M virt -accel $(ACCEL) -cpu $(CPU) -smp $(CPUS) -m $(MEMORY) -nographic -no-reboot \
		-kernel Image \
		-fsdev local,id=rootfs,path=$(ROOTFS),security_model=none,multidevs=remap \
		-device virtio-9p-device,fsdev=rootfs,mount_tag=/dev/root \
		-append 'console=ttyAMA0 root=/dev/root rootfstype=9p rootflags=trans=virtio,version=9p2000.L,access=any rw init=/qemu-init loglevel=7 panic=30 oops=panic raid=noautodetect' >qemu.log 2>&1
	test "$$(cat $(ROOTFS)/qemu-status)" = 0
