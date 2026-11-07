ROOT := $(abspath ../../../../..)
BUILD := build-x86/divide-fault-fixed
OUT := ../results/kprog_fidelity_20261106/negative/x86-divide-fault-fixed
.PHONY: build run
build:
	$(MAKE) -C $(ROOT)/kprog/fidelity negative-build ARCH=x86 NEGATIVE_BUILD=$(BUILD)
run:
	$(MAKE) -C $(ROOT)/kprog/fidelity negative-bound-kvm NEGATIVE_BUILD=$(BUILD) NEGATIVE_BOUND_OUT=$(OUT)
POSITIVE := $(ROOT)/kprog/fidelity/build-x86/divide-positive
.PHONY: positive-build positive-kvm positive-guest
positive-build:
	python3 positive.py build $(POSITIVE)
positive-kvm:
	vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --disable-monitor --cpus 2 --mem 2G --rwdir $(ROOT) --overlay-rwdir /tmp --exec 'cd $(ROOT)/kprog/fidelity && make -C $(ROOT)/kprog/results/kprog_fidelity_20261106/negative/x86-divide-fault-fixed positive-guest'
positive-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko
	python3 positive.py check $(POSITIVE) $(CURDIR)/positive
