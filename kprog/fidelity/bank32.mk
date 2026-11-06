BUILD := build-arm64-bank32
OUT ?= ../results/kprog_fidelity_20261106/differential/arm64-bank32
CASES ?= 1024
HEADERS := $(wildcard ../arm64/*.h ../formal/generated/*.h)
SOURCES := $(wildcard ../arm64/micro-prog/*.py)
.PHONY: build run-qemu reference
build: $(BUILD)/cpu-differential
$(BUILD)/generated.c $(BUILD)/native.S &: arm64_bank.py $(SOURCES) $(HEADERS)
	install -d $(BUILD)
	python3 arm64_bank.py --out $(BUILD)
$(BUILD)/cpu-differential: $(BUILD)/generated.c $(BUILD)/native.S driver.c driver.h
	aarch64-linux-gnu-gcc -O1 -g -std=gnu11 -static -Wall -Wextra -Werror=implicit-function-declaration -DKPROG_FIDELITY_VECTOR_BANK=32 -I../../vendor/libbpf/src -I../../vendor/libbpf/include/uapi driver.c $(BUILD)/generated.c $(BUILD)/native.S -o $@
run-qemu: build
	install -d $(OUT)
	qemu-aarch64-static $(BUILD)/cpu-differential $(CASES) $(OUT) $(OUT)/cpu-states.bin
reference:
	python3 reference_check.py --binary $(BUILD)/cpu-differential --arch arm64 --cases $(CASES) --out $(OUT) --reuse-trace
