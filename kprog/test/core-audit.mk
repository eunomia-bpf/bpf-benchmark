SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
BUILD := /var/tmp/kprog-tmp/perf/core-audit
OUTPUT ?= /workspaces/kprog-raw/perf/20261114-core-audit
KDIR := /workspaces/.agent-state/kprog-ck/build-x86
LIBBPF := $(ROOT)/runner/build-llvmbpf/vendor/libbpf
REFERENCE_ARGS ?=
TARGET ?= $(KDIR)/vmlinux
AUDIT_ARGS ?=
CORE_COMPILER := /var/tmp/kprog-tmp/perf/core-ir/core-ir-lower

$(BUILD)/core-reference: $(ROOT)/kprog/test/core_relocation_reference.c
	install -d $(BUILD)
	$(CC) -O2 -g -Wall -Wextra -Werror -I$(LIBBPF)/prefix/include -I$(ROOT)/vendor/libbpf/src -I$(ROOT)/vendor/libbpf/include -I$(ROOT)/vendor/libbpf/include/uapi $< $(LIBBPF)/pic-obj/libbpf.a -lelf -lz -o $@

.PHONY: reference
reference: $(BUILD)/core-reference
	install -d $(OUTPUT)
	taskset -c 19 prlimit --as=4294967296 -- $(BUILD)/core-reference $(SOURCE) $(TARGET) $(REFERENCE_ARGS) > $(OUTPUT)/reference.tsv

.PHONY: native-layout
native-layout:
	install -d $(BUILD) $(OUTPUT)
	taskset -c 19 prlimit --as=4294967296 -- pahole --btf_encode_detached=$(BUILD)/native.btf $(NATIVE) > $(OUTPUT)/pahole.log 2>&1

.PHONY: audit
audit: $(BUILD)/core-reference
	taskset -c 19 prlimit --as=4294967296 -- python3 $(ROOT)/kprog/test/audit_core_objects.py --build $(BUILD) --output $(OUTPUT) $(AUDIT_ARGS)

.PHONY: macro-policy
macro-policy:
	install -d $(BUILD) $(OUTPUT)
	$(CC) -O2 -Wall -Wextra -Werror $(ROOT)/kprog/test/core_macro_policy.c -o $(BUILD)/macro-policy
	$(BUILD)/macro-policy > $(OUTPUT)/macro-policy.json

$(CORE_COMPILER): $(ROOT)/kprog/build/core-ir-lower.cpp $(ROOT)/kprog/x86/core_zero_compare.h
	install -d $(dir $@)
	taskset -c 19 prlimit --as=8589934592 -- $(CXX) $$(llvm-config-18 --cxxflags) -std=c++17 -Wall -Wextra -Wno-unused-parameter -I$(ROOT)/vendor/libbpf/src -I$(ROOT)/vendor/libbpf/include/uapi $< -o $@ $(LIBBPF)/pic-obj/libbpf.a -lelf -lz $$(llvm-config-18 --ldflags --libs core irreader bitwriter passes --system-libs)

.PHONY: core-compiler
core-compiler: $(CORE_COMPILER)

.PHONY: mechanism-check
mechanism-check: $(CORE_COMPILER) $(BUILD)/core-reference
	taskset -c 19 prlimit --as=4294967296 -- python3 $(ROOT)/kprog/test/check_core_mechanism.py --build $(BUILD) --output $(OUTPUT) --compiler $(CORE_COMPILER) --target $(KDIR)/vmlinux

.PHONY: zero-compare-build zero-compare-run zero-compare-guest
zero-compare-build: $(BUILD)/core-reference
	taskset -c 19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_core_zero_compare.py --build $(BUILD) --output $(OUTPUT) --target $(KDIR)/vmlinux
	$(CC) -O2 -g -Wall -Wextra -Werror -I$(LIBBPF)/prefix/include $(ROOT)/kprog/test/core_zero_compare_client.c $(LIBBPF)/pic-obj/libbpf.a -lelf -lz -ldl -o $(BUILD)/zero-client

zero-compare-run:
	install -d $(OUTPUT)
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	taskset -c 22-23 prlimit --as=8589934592 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir /var/tmp=$(BUILD) --rodir /kprog-core-compiler=$(dir $(CORE_COMPILER)) --rwdir $(OUTPUT) --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(ROOT)/kprog/test/core-audit.mk zero-compare-guest BUILD=/var/tmp OUTPUT=$(OUTPUT)'

zero-compare-guest:
	python3 $(ROOT)/kprog/test/check_core_zero_compare.py --kernel --client $(BUILD)/zero-client --compiler /kprog-core-compiler/core-ir-lower --build $(BUILD) --output $(OUTPUT) --target $(KDIR)/vmlinux
