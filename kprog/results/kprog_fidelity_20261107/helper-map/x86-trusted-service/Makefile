ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/helper-map/x86-trusted-service
.PHONY: build guest kvm
build:
	python3 $(OUT)/check.py build
guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko
	PATH=/usr/lib/llvm-18/bin:$$PATH PYTHONDONTWRITEBYTECODE=1 python3 $(OUT)/check.py check
kvm:
	taskset -c 16-19 vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(OUT)/Makefile guest'
