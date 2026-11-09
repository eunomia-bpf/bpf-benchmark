# SPDX-License-Identifier: GPL-2.0
# Measurement-only direct-native recipe, see README.md. Timing only: the
# native code runs without verification.
SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := $(ROOT)/kprog/perf/direct-native
KDIR ?= $(ROOT)/kprog/tv/build-kernel-x86
OUT ?= /var/tmp/kprog-tmp/direct-native/build
STATE ?= /var/tmp/kprog-tmp/direct-native/state
BASE_IMAGE ?= bpf-benchmark/kprog-five-step-tracee:r-restored
IMAGE ?= bpf-benchmark/kprog-direct-native:r-restored
APP ?= katran
PAYLOAD ?= $(ROOT)/corpus/results/kprog_app_coverage_20261109/katran-regression-current/inline-producer/payload.tar.gz
APPS ?= $(APP)
CPUS ?= 8-15
VM_CPUS ?= 8
VM_MEM ?= 12G
BPFREJIT_CORPUS_BPF_STATS ?= 1
SAMPLES ?= 1
WORKLOAD_DURATION ?= 2
JIT_DUMP_LIMIT ?=
IMAGE_TAR := $(STATE)/var-tmp/runtime.image.tar
GUEST_IMAGE_TAR := /var/tmp/runtime.image.tar

.PHONY: module image corpus guest

module:
	install -d $(OUT)/module
	$(MAKE) -C $(KDIR) M=$(HERE) MO=$(OUT)/module ARCH=x86 modules

# Overlay the module and one app's payload (native/<app>/ in PAYLOAD) on BASE_IMAGE.
image: module
	rm -rf $(OUT)/image
	install -d $(OUT)/image/payload $(STATE)/var-tmp
	tar -xzf $(PAYLOAD) -C $(OUT)/image/payload
	cp $(OUT)/module/bpf_x86_native_lab.ko $(OUT)/image/
	cp -r $(OUT)/image/payload/native/$(APP) $(OUT)/image/native-app
	cp $(HERE)/Dockerfile $(OUT)/image/Dockerfile
	docker build --build-arg BASE_IMAGE=$(BASE_IMAGE) --build-arg APP=$(APP) -t $(IMAGE) $(OUT)/image
	rm -f $(IMAGE_TAR)
	docker save -o $(IMAGE_TAR) $(IMAGE)

corpus:
	install -d $(STATE)/var-tmp
	taskset -c $(CPUS) vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /var/tmp=$(STATE)/var-tmp --overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local --disable-monitor --cpus $(VM_CPUS) --memory $(VM_MEM) --append 'loglevel=4 panic=30 oops=panic' --exec 'BPFREJIT_CORPUS_BPF_STATS=$(BPFREJIT_CORPUS_BPF_STATS) make -f $(HERE)/Makefile guest IMAGE=$(IMAGE) APPS=$(APPS) SAMPLES=$(SAMPLES) WORKLOAD_DURATION=$(WORKLOAD_DURATION) JIT_DUMP_LIMIT=$(JIT_DUMP_LIMIT)'
	rm -f $(STATE)/var-tmp/bpf-benchmark-docker.img

guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	PATH=/usr/lib/llvm-18/bin:$$PATH BPFREJIT_CORPUS_APPS=$(APPS) BPFREJIT_CORPUS_APP_TIMEOUT=0 BPFREJIT_CORPUS_REJIT_TIMEOUT=0 BPFREJIT_SHIM_NATIVE_LOADER=post BPFREJIT_SHIM_NATIVE_JIT_DUMP_LIMIT=$(JIT_DUMP_LIMIT) $(MAKE) -C $(ROOT) __runtime-vm-corpus PLATFORM=kvm ARCH=x86 RUNTIME_CONTAINER_IMAGE=$(IMAGE) RUNTIME_IMAGE_TAR=$(GUEST_IMAGE_TAR) SAMPLES=$(SAMPLES) WORKLOAD_DURATION=$(WORKLOAD_DURATION)
