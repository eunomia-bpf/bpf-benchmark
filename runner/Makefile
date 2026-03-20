ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
REPO_ROOT := $(abspath $(ROOT_DIR)/..)

BUILD_DIR ?= $(ROOT_DIR)/build
LIBBPF_BUILD_DIR := $(BUILD_DIR)/vendor/libbpf
LIBBPF_OBJDIR := $(LIBBPF_BUILD_DIR)/obj
LIBBPF_PREFIX := $(LIBBPF_BUILD_DIR)/prefix
LIBBPF_A := $(LIBBPF_OBJDIR)/libbpf.a
LIBBPF_HEADER := $(LIBBPF_PREFIX)/include/bpf/bpf.h
BPFTOOL_BUILD_DIR := $(BUILD_DIR)/vendor/bpftool
TOOLS_BUILD_DIR := $(BUILD_DIR)/tools
DIRECTIVE_HINT_BIN := $(TOOLS_BUILD_DIR)/directive_hint
MICRO_EXEC_ENABLE_LLVMBPF ?= ON

.PHONY: all micro_exec directive_hint vendor_libbpf vendor_bpftool clean

all: micro_exec directive_hint

vendor_libbpf: $(LIBBPF_A) $(LIBBPF_HEADER)

$(LIBBPF_A) $(LIBBPF_HEADER) &:
	mkdir -p $(LIBBPF_OBJDIR)
	mkdir -p $(LIBBPF_PREFIX)
	mkdir -p $(LIBBPF_PREFIX)/include
	$(MAKE) -C $(REPO_ROOT)/vendor/libbpf/src \
		BUILD_STATIC_ONLY=1 \
		OBJDIR=$(LIBBPF_OBJDIR) \
		DESTDIR= \
		PREFIX=$(LIBBPF_PREFIX) \
		$(LIBBPF_A) install_headers

$(BUILD_DIR):
	mkdir -p $@

$(TOOLS_BUILD_DIR):
	mkdir -p $@

$(BPFTOOL_BUILD_DIR):
	mkdir -p $@

micro_exec: $(LIBBPF_A) $(LIBBPF_HEADER) | $(BUILD_DIR)
	cmake -S $(ROOT_DIR) -B $(BUILD_DIR) \
		-DCMAKE_BUILD_TYPE=Release \
		-DMICRO_REPO_ROOT=$(REPO_ROOT) \
		-DMICRO_LIBBPF_PREFIX=$(LIBBPF_PREFIX) \
		-DMICRO_LIBBPF_LIBRARY=$(LIBBPF_A) \
		-DMICRO_EXEC_ENABLE_LLVMBPF=$(MICRO_EXEC_ENABLE_LLVMBPF)
	cmake --build $(BUILD_DIR) --target micro_exec -j

directive_hint: $(LIBBPF_A) $(LIBBPF_HEADER) | $(TOOLS_BUILD_DIR)
	$(CXX) -O2 -g -Wall -Wextra -std=c++20 \
		-I$(LIBBPF_PREFIX)/include \
		-I$(ROOT_DIR)/include \
		-o $(DIRECTIVE_HINT_BIN) \
		$(REPO_ROOT)/micro/tools/directive_hint.c \
		$(ROOT_DIR)/src/common.cpp \
		$(ROOT_DIR)/src/elf_program_loader.cpp \
		$(LIBBPF_A) -lelf -lz

vendor_bpftool: | $(BPFTOOL_BUILD_DIR)
	$(MAKE) -C $(REPO_ROOT)/vendor/bpftool/src \
		OUTPUT=$(BPFTOOL_BUILD_DIR) \
		BPF_DIR=$(REPO_ROOT)/vendor/libbpf/src

clean:
	rm -rf $(BUILD_DIR)
