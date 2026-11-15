SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
LINKER_TARGET := $(ROOT)/kprog/x86/native_lab/native_link/target
OUTPUT ?= /workspaces/kprog-raw/perf/20261115-native-relocations
BUILD := /var/tmp/kprog-tmp/perf/native-relocations

.PHONY: check build
check:
	taskset -c 8-11 prlimit --as=8589934592 -- env CARGO_BUILD_JOBS=2 CARGO_TARGET_DIR=$(LINKER_TARGET) cargo test --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml

build:
	taskset -c 8-11 prlimit --as=8589934592 -- env CARGO_BUILD_JOBS=2 CARGO_TARGET_DIR=$(LINKER_TARGET) cargo build --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml

.PHONY: evidence
evidence:
	taskset -c 8-11 prlimit --as=12884901888 -- python3 $(ROOT)/kprog/test/check_non_pic_maps.py --build $(BUILD) --output $(OUTPUT) --linker $(LINKER_TARGET)/release/native-link

.PHONY: jump-table-forms
jump-table-forms:
	install -d $(BUILD) $(OUTPUT)
	clang-18 -target x86_64-linux-gnu -O3 -march=native -foptimize-sibling-calls -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector -c $(ROOT)/kprog/test/native_jump_table.c -o $(BUILD)/jump-table.native.o
	objdump -dr -Mintel $(BUILD)/jump-table.native.o > $(OUTPUT)/jump-table.disassembly
	readelf -rW $(BUILD)/jump-table.native.o > $(OUTPUT)/jump-table.relocations

.PHONY: jump-table-check
jump-table-check: build jump-table-forms
	taskset -c 8-11 prlimit --as=12884901888 -- python3 $(ROOT)/kprog/test/check_native_jump_tables.py --build $(BUILD) --output $(OUTPUT) --linker $(LINKER_TARGET)/release/native-link
