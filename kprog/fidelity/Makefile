PYTHON ?= python3
ARCH ?= x86
CC_x86 ?= cc
CC_arm64 ?= aarch64-linux-gnu-gcc
BUILD := build-$(ARCH)
CASES ?= 1024
OUT ?= ../results/kprog_fidelity_20261106/differential
HEADERS := $(wildcard ../$(ARCH)/*.h ../formal/generated/*.h)

.PHONY: build run run-built run-emulated
build: $(BUILD)/cpu-differential

$(BUILD)/generated.c: generate.py
	install -d $(BUILD)
	$(PYTHON) generate.py --arch $(ARCH) --out $(BUILD)

$(BUILD)/cpu-differential: $(BUILD)/generated.c driver.c driver.h $(HEADERS)
	$(CC_$(ARCH)) -O1 -g -std=gnu11 -Werror=implicit-function-declaration -static \
		-I../../vendor/libbpf/src -I../../vendor/libbpf/include/uapi \
		driver.c $(BUILD)/generated.c $(BUILD)/native.S -o $@

run: build

run run-built:
	test -x ./$(BUILD)/cpu-differential
	install -d $(OUT)
	./$(BUILD)/cpu-differential $(CASES) $(OUT)

run-emulated: build
	install -d $(OUT)
	qemu-aarch64-static ./$(BUILD)/cpu-differential $(CASES) $(OUT)

.PHONY: run-handoff
run-handoff:
	install -d build-arm64 $(OUT)
	gzip -dc ../results/kprog_fidelity_20261106/differential/cpu-differential-arm64.gz > build-arm64/cpu-differential-handoff
	chmod +x build-arm64/cpu-differential-handoff
	./build-arm64/cpu-differential-handoff $(CASES) $(OUT)

.PHONY: negative-build negative-guest
NEGATIVE_BUILD ?= $(BUILD)/negative
NEGATIVE_OUT ?= ../results/kprog_fidelity_20261106/negative/$(ARCH)
LOADER ?= ../loader/target/debug/reversesim-loader
negative-build:
	$(PYTHON) negative.py build --arch $(ARCH) --build $(NEGATIVE_BUILD)

negative-guest:
	$(PYTHON) negative.py run --arch $(ARCH) --build $(NEGATIVE_BUILD) --out $(NEGATIVE_OUT) --loader $(LOADER)

ROOT := $(abspath ../..)
.PHONY: negative-kvm negative-qemu
negative-kvm:
	vng --run $(ROOT)/vendor/build/x86/linux/arch/x86/boot/bzImage \
		--cwd $(ROOT) --disable-monitor --cpus 8 --mem 12G \
		--rwdir $(ROOT) --overlay-rwdir /tmp \
		--exec 'make -C $(ROOT)/kprog/fidelity negative-guest'

build-arm64/negative-init: negative_init.c
	install -d build-arm64
	aarch64-linux-gnu-gcc -Wall -Wextra -Werror -O2 -static $< -o $@

build-arm64/negative.cpio: build-arm64/negative-init build-arm64/negative/build.json negative.py
	$(PYTHON) negative.py package --arch arm64 --build build-arm64/negative

negative-qemu: build-arm64/negative.cpio
	install -d ../results/kprog_fidelity_20261106/negative/arm64
	timeout 240 qemu-system-aarch64 -M virt -cpu cortex-a57 -smp 2 -m 2048 \
		-nographic -no-reboot -kernel $(ROOT)/vendor/build/arm64/linux/arch/arm64/boot/Image \
		-initrd build-arm64/negative.cpio -append 'console=ttyAMA0 rdinit=/init panic=-1' \
		> ../results/kprog_fidelity_20261106/negative/arm64/guest-console.log 2>&1
	$(PYTHON) negative.py collect --arch arm64 --build build-arm64/negative --out ../results/kprog_fidelity_20261106/negative/arm64
