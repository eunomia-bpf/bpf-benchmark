ROOT := $(abspath ../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-arm64/ldp-overlap-bound
PHASE ?= before
.PHONY: build run
build:
	python3 prepare.py $(BUILD)/$(PHASE)
	python3 ../arm64-sp-alignment/package.py $(BUILD)/$(PHASE)
run:
	install -d $(PHASE)
	timeout 240 qemu-system-aarch64 -M virt -cpu cortex-a57 -smp 2 -m 2048 -nographic -no-reboot -kernel $(BUILD)/$(PHASE)/Image -initrd $(BUILD)/$(PHASE)/init.cpio -append 'console=ttyAMA0 rdinit=/init panic=-1' > $(PHASE)/guest-console.log 2>&1
	python3 collect.py $(BUILD)/$(PHASE) $(PHASE)

.PHONY: full-build full-run
full-build:
	$(MAKE) -C $(ROOT)/kprog/fidelity negative-build ARCH=arm64 NEGATIVE_BUILD=build-arm64/ldp-overlap-bound/after/full-suite
full-run:
	python3 ../arm64-sp-alignment/prepare_full.py $(BUILD)/after
	python3 ../arm64-sp-alignment/package.py $(BUILD)/after/full-run
	install -d full-after
	timeout 240 qemu-system-aarch64 -M virt -cpu cortex-a57 -smp 2 -m 2048 -nographic -no-reboot -kernel $(BUILD)/after/Image -initrd $(BUILD)/after/full-run/init.cpio -append 'console=ttyAMA0 rdinit=/init panic=-1' > full-after/guest-console.log 2>&1
	cd $(ROOT)/kprog/fidelity && python3 negative.py collect-bound --arch arm64 --build $(BUILD)/after/full-suite --out $(CURDIR)/full-after
