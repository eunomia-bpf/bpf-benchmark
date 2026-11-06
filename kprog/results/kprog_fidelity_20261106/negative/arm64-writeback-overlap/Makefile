ROOT := $(abspath ../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-arm64/writeback-overlap-bound
PHASE ?= before
.PHONY: build run
build:
	python3 prepare.py $(BUILD)/$(PHASE)
	python3 ../arm64-sp-alignment/prepare_full.py $(BUILD)/$(PHASE)
	python3 ../arm64-sp-alignment/package.py $(BUILD)/$(PHASE)/full-run
run:
	install -d $(PHASE)
	timeout 240 qemu-system-aarch64 -M virt -cpu cortex-a57 -smp 2 -m 2048 -nographic -no-reboot -kernel $(BUILD)/$(PHASE)/Image -initrd $(BUILD)/$(PHASE)/full-run/init.cpio -append 'console=ttyAMA0 rdinit=/init panic=-1' > $(PHASE)/guest-console.log 2>&1
	python3 collect.py $(BUILD)/$(PHASE) $(PHASE)

.PHONY: full-build full-run
full-build:
	$(MAKE) -C $(ROOT)/kprog/fidelity negative-build ARCH=arm64 NEGATIVE_BUILD=build-arm64/writeback-overlap-bound/full-current/full-suite
	cp $(BUILD)/after/bound-probe $(BUILD)/after/init $(BUILD)/after/bpf_arm64_native_lab.ko $(BUILD)/after/native-link $(BUILD)/after/companion.bpf.o $(BUILD)/after/Image $(BUILD)/full-current/
	python3 ../arm64-sp-alignment/prepare_full.py $(BUILD)/full-current
	python3 ../arm64-sp-alignment/package.py $(BUILD)/full-current/full-run
full-run:
	install -d full-after
	timeout 240 qemu-system-aarch64 -M virt -cpu cortex-a57 -smp 2 -m 2048 -nographic -no-reboot -kernel $(BUILD)/full-current/Image -initrd $(BUILD)/full-current/full-run/init.cpio -append 'console=ttyAMA0 rdinit=/init panic=-1' > full-after/guest-console.log 2>&1
	cd $(ROOT)/kprog/fidelity && python3 negative.py collect-bound --arch arm64 --build $(BUILD)/full-current/full-suite --out $(CURDIR)/full-after
