ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/negative/context-projection
RUN_OUT ?= $(OUT)/x86
.PHONY: build-x86 build-arm64 kvm qemu
build-x86:
	python3 $(OUT)/check.py build x86
build-arm64:
	python3 $(OUT)/check.py build arm64
kvm:
	vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'export PATH=/usr/lib/llvm-18/bin:$$PATH; mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug; insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko && python3 $(OUT)/check.py guest-x86 $(RUN_OUT)'
qemu:
	python3 $(OUT)/check.py host
