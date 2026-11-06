ROOT := $(abspath ../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-arm64/exclusive-bound
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
	$(MAKE) -C $(ROOT)/kprog/fidelity negative-build ARCH=arm64 NEGATIVE_BUILD=build-arm64/exclusive-bound/full-current/full-suite
	cp $(BUILD)/before/bound-probe $(BUILD)/before/init $(BUILD)/before/bpf_arm64_native_lab.ko $(BUILD)/before/native-link $(BUILD)/before/companion.bpf.o $(BUILD)/before/Image $(BUILD)/full-current/
	python3 ../arm64-sp-alignment/prepare_full.py $(BUILD)/full-current
	python3 ../arm64-sp-alignment/package.py $(BUILD)/full-current/full-run
full-run:
	install -d full-before
	timeout 240 qemu-system-aarch64 -M virt -cpu cortex-a57 -smp 2 -m 2048 -nographic -no-reboot -kernel $(BUILD)/full-current/Image -initrd $(BUILD)/full-current/full-run/init.cpio -append 'console=ttyAMA0 rdinit=/init panic=-1' > full-before/guest-console.log 2>&1
	cd $(ROOT)/kprog/fidelity && python3 negative.py collect-bound --arch arm64 --build $(BUILD)/full-current/full-suite --out $(CURDIR)/full-before
