# SPDX-License-Identifier: MIT

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
TEST_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
BUILD_DIR ?= $(TEST_DIR)/build
RUNNER_BUILD_DIR ?= $(BUILD_DIR)
BPF_BUILD_DIR ?= $(BUILD_DIR)
PROG_BUILD_DIR := $(BPF_BUILD_DIR)/progs
UPSTREAM_KERNEL_TREE ?= $(ROOT_DIR)/vendor/linux-framework
UPSTREAM_SELFTESTS_DIR := $(UPSTREAM_KERNEL_TREE)/tools/testing/selftests/bpf
UPSTREAM_SELFTESTS_OUT := $(BUILD_DIR)/upstream-bpf-selftests
VMLINUX_BTF ?= $(UPSTREAM_KERNEL_TREE)/vmlinux
KERNEL_SYMVERS ?= $(UPSTREAM_KERNEL_TREE)/Module.symvers
UPSTREAM_TEST_KMODS ?= bpf_testmod.ko bpf_test_no_cfi.ko bpf_test_modorder_x.ko \
	bpf_test_modorder_y.ko bpf_test_rqspinlock.ko
UPSTREAM_TEST_KMOD_OUTPUTS := $(addprefix $(UPSTREAM_SELFTESTS_OUT)/,$(UPSTREAM_TEST_KMODS))
LIBBPF_BUILD_DIR ?= $(RUNNER_BUILD_DIR)/vendor/libbpf
LIBBPF_OBJDIR := $(LIBBPF_BUILD_DIR)/obj
LIBBPF_PREFIX := $(LIBBPF_BUILD_DIR)/prefix
LIBBPF_A := $(LIBBPF_OBJDIR)/libbpf.a
LIBBPF_HDR := $(LIBBPF_PREFIX)/include/bpf/libbpf.h

RUNNER := $(RUNNER_BUILD_DIR)/test_recompile
BPF_SRCS := $(wildcard $(TEST_DIR)/progs/*.bpf.c)
BPF_OBJS := $(patsubst $(TEST_DIR)/progs/%.bpf.c,$(PROG_BUILD_DIR)/%.bpf.o,$(BPF_SRCS))

CC ?= cc
CLANG ?= $(shell command -v clang-20 2>/dev/null || command -v clang 2>/dev/null || echo clang)
SELFTESTS_CLANG ?= $(CLANG)
SELFTESTS_LLVM_CONFIG ?= $(shell command -v llvm-config-20 2>/dev/null || command -v llvm-config 2>/dev/null || echo llvm-config)
SELFTESTS_LLVM_STRIP ?= $(shell command -v llvm-strip-20 2>/dev/null || command -v llvm-strip 2>/dev/null || echo llvm-strip)
SELFTESTS_LLVM_OBJCOPY ?= $(shell command -v llvm-objcopy-20 2>/dev/null || command -v llvm-objcopy 2>/dev/null || echo llvm-objcopy)
SELFTESTS_LLVM_READELF ?= $(shell command -v llvm-readelf-20 2>/dev/null || command -v llvm-readelf 2>/dev/null || echo llvm-readelf)
PKG_CONFIG ?= pkg-config
CFLAGS ?= -O2 -g -Wall -Wextra
HOST_PKG_CONFIG_DEPS ?= libelf zlib libzstd
TEST_KERNEL_ROOT ?= $(TEST_DIR)

BPF_CFLAGS := -O2 -g --target=bpf
BPF_INCLUDES := \
	-I$(ROOT_DIR)/vendor/libbpf/src \
	-I$(ROOT_DIR)/vendor/libbpf/include/uapi \
	-I$(ROOT_DIR)/vendor/libbpf/include
ifeq ($(shell command -v $(PKG_CONFIG) 2>/dev/null),)
NO_PKG_CONFIG := 1
endif
ifdef NO_PKG_CONFIG
HOST_EXT_CFLAGS :=
HOST_EXT_LIBS := -lelf -lz -lzstd
else
HOST_EXT_CFLAGS := $(shell $(PKG_CONFIG) --cflags $(HOST_PKG_CONFIG_DEPS))
HOST_EXT_LIBS := $(shell $(PKG_CONFIG) --libs $(HOST_PKG_CONFIG_DEPS))
endif
HOST_INCLUDES := \
	-I$(ROOT_DIR)/vendor/linux-framework/include/uapi \
	-I$(LIBBPF_PREFIX)/include \
	-I$(ROOT_DIR)/vendor/libbpf/include \
	-I$(ROOT_DIR)/vendor/libbpf/include/uapi \
	-I$(ROOT_DIR)/vendor/libbpf/src \
	$(HOST_EXT_CFLAGS)
HOST_LDLIBS ?= $(LIBBPF_A) $(HOST_EXT_LIBS) -lpthread
JOBS ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)

define get_sys_includes
$(shell $(1) -v -E - </dev/null 2>&1 \
	| sed -n '/<...> search starts here:/,/End of search list./{ s| \(/.*\)|-idirafter \1|p }')
endef

CLANG_SYS_INCLUDES := $(call get_sys_includes,$(CLANG))

.PHONY: all clean run progs runner upstream-selftests

all: $(RUNNER) $(BPF_OBJS)

progs: $(BPF_OBJS)

runner: $(RUNNER)

upstream-selftests:
	rm -rf "$(UPSTREAM_SELFTESTS_OUT)"
	mkdir -p "$(UPSTREAM_SELFTESTS_OUT)"
	$(MAKE) -C "$(UPSTREAM_SELFTESTS_DIR)" clean OUTPUT="$(UPSTREAM_SELFTESTS_OUT)"
	@if [ -f "$(KERNEL_SYMVERS)" ]; then \
		rebuild_kmods=0; \
		for ko in $(UPSTREAM_TEST_KMOD_OUTPUTS); do \
			if [ ! -e "$$ko" ] || [ "$(KERNEL_SYMVERS)" -nt "$$ko" ]; then \
				rebuild_kmods=1; \
				break; \
			fi; \
		done; \
		if [ "$$rebuild_kmods" -eq 1 ]; then \
			$(MAKE) -C "$(UPSTREAM_SELFTESTS_DIR)/test_kmods" clean; \
			rm -f $(UPSTREAM_TEST_KMOD_OUTPUTS); \
		fi; \
	fi
	$(MAKE) -j"$(JOBS)" -C "$(UPSTREAM_SELFTESTS_DIR)" \
		OUTPUT="$(UPSTREAM_SELFTESTS_OUT)" \
		VMLINUX_BTF="$(VMLINUX_BTF)" \
		TEST_KMODS="$(UPSTREAM_TEST_KMODS)" \
		MODULES="$(UPSTREAM_TEST_KMODS)" \
		SKIP_DOCS=1 \
		CLANG="$(SELFTESTS_CLANG)" \
		LLVM_CONFIG="$(SELFTESTS_LLVM_CONFIG)" \
		LLVM_STRIP="$(SELFTESTS_LLVM_STRIP)" \
		LLVM_OBJCOPY="$(SELFTESTS_LLVM_OBJCOPY)" \
		LLVM_READELF="$(SELFTESTS_LLVM_READELF)" \
		"$(UPSTREAM_SELFTESTS_OUT)/test_verifier" \
		"$(UPSTREAM_SELFTESTS_OUT)/test_progs" \
		"$(UPSTREAM_SELFTESTS_OUT)/bpf_testmod.ko" \
		"$(UPSTREAM_SELFTESTS_OUT)/bpf_test_no_cfi.ko"

run: all
	$(RUNNER)

clean:
	rm -rf "$(RUNNER_BUILD_DIR)" "$(BPF_BUILD_DIR)" "$(UPSTREAM_SELFTESTS_OUT)"

$(sort $(RUNNER_BUILD_DIR) $(BPF_BUILD_DIR) $(PROG_BUILD_DIR)):
	mkdir -p $@

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

$(PROG_BUILD_DIR)/%.bpf.o: $(TEST_DIR)/progs/%.bpf.c | $(PROG_BUILD_DIR)
	$(CLANG) $(BPF_CFLAGS) $(BPF_INCLUDES) $(CLANG_SYS_INCLUDES) -c $< -o $@

$(RUNNER): $(TEST_DIR)/test_recompile.c $(LIBBPF_A) $(LIBBPF_HDR) | $(RUNNER_BUILD_DIR)
	$(CC) $(CFLAGS) $(HOST_INCLUDES) -DTEST_KERNEL_ROOT=\"$(TEST_KERNEL_ROOT)\" \
		-o $@ $< $(HOST_LDLIBS)
