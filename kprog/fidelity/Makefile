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
