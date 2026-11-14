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
