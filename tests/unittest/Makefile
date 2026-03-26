ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
UNITTEST_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
BUILD_DIR ?= $(UNITTEST_DIR)/build

CC ?= cc
CLANG ?= clang
CFLAGS ?= -O2 -g -Wall -Wno-cpp
# Use -I (not -isystem) so vendor REJIT headers override system linux/bpf.h
INCLUDES := -I$(ROOT_DIR)/vendor/linux-framework/include/uapi

# libbpf (static) — used by rejit_prog_types, rejit_audit_tests, rejit_swap_tests,
# rejit_struct_ops_* tests
LIBBPF_BUILD_DIR ?= $(BUILD_DIR)/vendor/libbpf
LIBBPF_OBJDIR := $(LIBBPF_BUILD_DIR)/obj
LIBBPF_PREFIX := $(LIBBPF_BUILD_DIR)/prefix
LIBBPF_A := $(LIBBPF_OBJDIR)/libbpf.a
LIBBPF_HDR := $(LIBBPF_PREFIX)/include/bpf/libbpf.h

BPFTOOL_BUILD_DIR ?= $(BUILD_DIR)/vendor/bpftool
BPFTOOL_BOOTSTRAP := $(BPFTOOL_BUILD_DIR)/bootstrap/bpftool
VMLINUX_INCLUDE_DIR := $(BUILD_DIR)/include
VMLINUX_HDR := $(VMLINUX_INCLUDE_DIR)/vmlinux.h
VMLINUX_BTF_PATHS ?= \
	$(ROOT_DIR)/vendor/linux-framework/vmlinux \
	$(ROOT_DIR)/vendor/linux-framework/build/vmlinux \
	/sys/kernel/btf/vmlinux \
	/boot/vmlinux-$(shell uname -r)
VMLINUX_BTF ?= $(abspath $(firstword $(wildcard $(VMLINUX_BTF_PATHS))))

ifeq ($(VMLINUX_BTF)$(VMLINUX_H),)
$(error Cannot find a vmlinux for VMLINUX_BTF at any of "$(VMLINUX_BTF_PATHS)")
endif

PKG_CONFIG ?= pkg-config
ifeq ($(shell command -v $(PKG_CONFIG) 2>/dev/null),)
NO_PKG_CONFIG := 1
endif
ifdef NO_PKG_CONFIG
HOST_EXT_LIBS := -lelf -lz -lzstd
else
HOST_EXT_LIBS := $(shell $(PKG_CONFIG) --libs libelf zlib libzstd 2>/dev/null || echo "-lelf -lz -lzstd")
endif

LIBBPF_INCLUDES := \
	-I$(LIBBPF_PREFIX)/include \
	-I$(ROOT_DIR)/vendor/libbpf/include \
	-I$(ROOT_DIR)/vendor/libbpf/include/uapi \
	-I$(ROOT_DIR)/vendor/libbpf/src

BPF_CFLAGS := -O2 -g --target=bpf -D__wsum=__u32
# LIBBPF_PREFIX first so <bpf/bpf_helpers.h> resolves to vendor libbpf, not system /usr/include/bpf
BPF_INCLUDES := \
	-I$(VMLINUX_INCLUDE_DIR) \
	-I$(LIBBPF_PREFIX)/include \
	-I$(ROOT_DIR)/vendor/libbpf/src \
	-I$(ROOT_DIR)/vendor/libbpf/include/uapi \
	-I$(ROOT_DIR)/vendor/libbpf/include \
	-I$(ROOT_DIR)/vendor/linux-framework/tools/sched_ext/include

define get_sys_includes
$(shell $(1) -v -E - </dev/null 2>&1 \
	| sed -n '/<...> search starts here:/,/End of search list./{ s| \(/.*\)|-idirafter \1|p }')
endef
CLANG_SYS_INCLUDES := $(call get_sys_includes,$(CLANG))

# Tests that only need kernel UAPI headers
SIMPLE_TESTS := rejit_poc rejit_safety_tests rejit_regression rejit_tail_call \
                rejit_spectre rejit_kinsn \
                rejit_verifier_negative_tests

# Tests that also need libbpf
LIBBPF_TESTS := rejit_prog_types rejit_audit_tests rejit_swap_tests \
                rejit_struct_ops_rollback_tests \
                rejit_struct_ops_multi_callsite_tests

TESTS := $(SIMPLE_TESTS) $(LIBBPF_TESTS)

BPF_PROGS_DIR := $(UNITTEST_DIR)/progs
BPF_SRCS := $(wildcard $(BPF_PROGS_DIR)/*.bpf.c)
BPF_OBJS := $(patsubst $(BPF_PROGS_DIR)/%.bpf.c,$(BUILD_DIR)/progs/%.bpf.o,$(BPF_SRCS))

.PHONY: all clean run tests

all: $(addprefix $(BUILD_DIR)/,$(TESTS)) $(BPF_OBJS)

# Simple tests: only kernel UAPI headers, no libbpf
$(addprefix $(BUILD_DIR)/,$(SIMPLE_TESTS)): $(BUILD_DIR)/%: $(UNITTEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< -lpthread

# libbpf-dependent tests
$(addprefix $(BUILD_DIR)/,$(LIBBPF_TESTS)): $(BUILD_DIR)/%: $(UNITTEST_DIR)/%.c $(LIBBPF_A) $(LIBBPF_HDR) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBBPF_INCLUDES) -o $@ $< $(LIBBPF_A) $(HOST_EXT_LIBS) -lpthread

$(LIBBPF_A) $(LIBBPF_HDR) &:
	mkdir -p $(LIBBPF_OBJDIR)
	mkdir -p $(LIBBPF_PREFIX)
	mkdir -p $(LIBBPF_PREFIX)/include
	$(MAKE) -C $(ROOT_DIR)/vendor/libbpf/src \
		BUILD_STATIC_ONLY=1 \
		OBJDIR=$(LIBBPF_OBJDIR) \
		DESTDIR= \
		PREFIX=$(LIBBPF_PREFIX) \
		$(LIBBPF_A) install_headers

$(BPFTOOL_BOOTSTRAP):
	mkdir -p $(BPFTOOL_BUILD_DIR)
	$(MAKE) -C $(ROOT_DIR)/vendor/linux-framework/tools/bpf/bpftool OUTPUT=$(BPFTOOL_BUILD_DIR)/ bootstrap

ifeq ($(VMLINUX_H),)
$(VMLINUX_HDR): $(VMLINUX_BTF) $(BPFTOOL_BOOTSTRAP) | $(VMLINUX_INCLUDE_DIR)
	$(BPFTOOL_BOOTSTRAP) btf dump file $(VMLINUX_BTF) format c > $@
else
$(VMLINUX_HDR): $(VMLINUX_H) | $(VMLINUX_INCLUDE_DIR)
	cp "$(VMLINUX_H)" $@
endif

$(BUILD_DIR)/progs/%.bpf.o: $(BPF_PROGS_DIR)/%.bpf.c $(LIBBPF_HDR) $(VMLINUX_HDR) | $(BUILD_DIR)/progs
	$(CLANG) $(BPF_CFLAGS) $(BPF_INCLUDES) $(CLANG_SYS_INCLUDES) -c $< -o $@

$(BUILD_DIR) $(BUILD_DIR)/progs $(VMLINUX_INCLUDE_DIR):
	mkdir -p $@

run: all
	@for t in $(TESTS); do \
	    echo "=== $$t ==="; \
	    $(BUILD_DIR)/$$t $(BUILD_DIR)/progs || exit 1; \
	done

clean:
	rm -rf $(BUILD_DIR)
