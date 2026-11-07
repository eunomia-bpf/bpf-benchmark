ROOT := $(abspath ../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-div-published-negative
SOURCE := $(BUILD)/source
ARCHIVE := $(CURDIR)/../../differential/x86-divide-published/producer-source.tar.gz
.PHONY: source build run positive-build positive-kvm positive-guest
source:
	install -d $(SOURCE)
	tar -xzf $(ARCHIVE) -C $(SOURCE)
	ln -sfn $(ROOT)/vendor $(SOURCE)/vendor
build: source
	python3 $(SOURCE)/kprog/fidelity/negative.py build --arch x86 --build $(BUILD)/negative
run:
	$(MAKE) -C $(ROOT)/kprog/fidelity negative-bound-kvm NEGATIVE_BUILD=$(BUILD)/negative NEGATIVE_BOUND_OUT=$(CURDIR)
positive-build: source
	python3 positive.py build $(BUILD)/positive
positive-kvm:
	vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --disable-monitor --cpus 2 --mem 2G --rwdir $(ROOT) --overlay-rwdir /tmp --exec 'cd $(ROOT)/kprog/fidelity && make -C $(CURDIR) positive-guest'
positive-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko
	python3 positive.py check $(BUILD)/positive $(CURDIR)/positive
