ROOT := /workspaces/repository
OUT := $(ROOT)/corpus/results/kprog_app_coverage_20261107/xdp-context-identity
.PHONY: kvm guest
kvm:
	taskset -c 16-19 vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(OUT)/Makefile guest'
guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko
	PATH=/usr/lib/llvm-18/bin:$$PATH PYTHONDONTWRITEBYTECODE=1 python3 $(OUT)/check.py
