# SPDX-License-Identifier: MIT

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
TEST_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
BUILD_DIR ?= $(TEST_DIR)/build
RUNNER_BUILD_DIR ?= $(BUILD_DIR)
BPF_BUILD_DIR ?= $(BUILD_DIR)
PROG_BUILD_DIR := $(BPF_BUILD_DIR)/progs

LIBBPF_BUILD_DIR ?= $(RUNNER_BUILD_DIR)/vendor/libbpf
LIBBPF_OBJDIR := $(LIBBPF_BUILD_DIR)/obj
LIBBPF_PREFIX := $(LIBBPF_BUILD_DIR)/prefix
LIBBPF_A := $(LIBBPF_OBJDIR)/libbpf.a
LIBBPF_HDR := $(LIBBPF_PREFIX)/include/bpf/libbpf.h

RUNNER := $(RUNNER_BUILD_DIR)/test_recompile
BPF_SRCS := $(wildcard $(TEST_DIR)/progs/*.bpf.c)
BPF_OBJS := $(patsubst $(TEST_DIR)/progs/%.bpf.c,$(PROG_BUILD_DIR)/%.bpf.o,$(BPF_SRCS))

CC ?= cc
CLANG ?= clang
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

define get_sys_includes
$(shell $(1) -v -E - </dev/null 2>&1 \
	| sed -n '/<...> search starts here:/,/End of search list./{ s| \(/.*\)|-idirafter \1|p }')
endef

CLANG_SYS_INCLUDES := $(call get_sys_includes,$(CLANG))

.PHONY: all clean run progs runner

all: $(RUNNER) $(BPF_OBJS)

progs: $(BPF_OBJS)

runner: $(RUNNER)

run: all
	sudo $(RUNNER)

clean:
	rm -rf "$(RUNNER_BUILD_DIR)" "$(BPF_BUILD_DIR)"

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
