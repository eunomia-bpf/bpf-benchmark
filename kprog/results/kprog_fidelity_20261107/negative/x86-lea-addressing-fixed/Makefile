ROOT := $(abspath ../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-lea-addressing-validation
.PHONY: build run positive-build positive-kvm positive-guest micro-build
build:
	$(MAKE) -C $(ROOT)/kprog/fidelity negative-build ARCH=x86 NEGATIVE_BUILD=$(BUILD)/negative
run:
	$(MAKE) -C $(ROOT)/kprog/fidelity negative-bound-kvm NEGATIVE_BUILD=$(BUILD)/negative NEGATIVE_BOUND_OUT=$(CURDIR)
positive-build:
	python3 positive.py build $(BUILD)/positive
positive-kvm:
	vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --disable-monitor --cpus 2 --mem 2G --rwdir $(ROOT) --overlay-rwdir /tmp --exec 'cd $(ROOT)/kprog/fidelity && make -C $(CURDIR) positive-guest'
positive-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko
	python3 positive.py check $(BUILD)/positive $(CURDIR)/positive
micro-build:
	python3 $(CURDIR)/micro.py $(BUILD)/micro $(CURDIR)
