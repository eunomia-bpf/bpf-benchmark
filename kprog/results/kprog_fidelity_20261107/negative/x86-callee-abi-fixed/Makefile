ROOT := $(abspath ../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-abi-fixed
OUT ?= $(CURDIR)/fresh-run
KERNEL ?= $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage
.PHONY: frozen run guest
frozen:
	install -d $(BUILD)
	tar -xzf inputs.tar.gz -C $(BUILD)
run: frozen
	taskset -c 16-19 vng --run $(KERNEL) --cwd $(ROOT) --disable-monitor --cpus 2 --mem 2G --rwdir $(ROOT) --overlay-rwdir /tmp --exec 'make -C $(CURDIR) guest OUT=$(OUT)'
guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(BUILD)/module.ko capture_checked=1
	python3 $(CURDIR)/replay.py $(BUILD) $(OUT)
