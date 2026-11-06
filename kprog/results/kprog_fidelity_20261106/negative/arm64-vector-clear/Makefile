ROOT := $(abspath ../../../../..)
BUILD ?= $(ROOT)/kprog/fidelity/build-arm64/vector-clear/before
OUT ?= $(CURDIR)/before
.PHONY: build package run
build:
	python3 build.py $(BUILD)
package:
	$(MAKE) -C $(ROOT)/kprog/fidelity bound-probe-build-arm64
	install -d $(dir $(BUILD))
	cp $(ROOT)/kprog/fidelity/build-arm64/bound-probe $(ROOT)/kprog/fidelity/build-arm64/negative-companion.bpf.o $(dir $(BUILD))
	aarch64-linux-gnu-gcc -Wall -Wextra -Werror -O2 -static -DBOUND_NEGATIVE $(ROOT)/kprog/fidelity/negative_init.c -o $(dir $(BUILD))/negative-bound-init
	python3 $(ROOT)/kprog/fidelity/negative.py package-bound --arch arm64 --build $(BUILD)
run:
	install -d $(OUT)
	timeout 240 qemu-system-aarch64 -M virt -cpu cortex-a57 -smp 2 -m 2048 -nographic -no-reboot -kernel $(ROOT)/kprog/tv/build-kernel-arm64/arch/arm64/boot/Image -initrd $(dir $(BUILD))/negative-bound.cpio -append 'console=ttyAMA0 rdinit=/init panic=-1' > $(OUT)/guest-console.log 2>&1
	python3 $(ROOT)/kprog/fidelity/negative.py collect-bound --arch arm64 --build $(BUILD) --out $(OUT)

.PHONY: contract
contract:
	python3 $(ROOT)/kprog/formal/tools/generate_arm64_dq_mem_spec.py
