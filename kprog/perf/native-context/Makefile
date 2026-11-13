SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := $(ROOT)/kprog/perf/native-context
BUILD ?= $(HERE)/build-x86
KDIR := /workspaces/.agent-state/kprog-ck/build-x86
KRELEASE := $(shell cat $(KDIR)/include/config/kernel.release)
VMLINUX_DIR := $(ROOT)/vendor/bpf/targets/x86/$(KRELEASE)
LLVM_CONFIG := llvm-config-18
CXX := clang++-18
CC := clang-18

$(BUILD)/perf-context-lower: $(HERE)/perf-context-lower.cpp
	install -d $(BUILD)
	$(CXX) $$($(LLVM_CONFIG) --cxxflags) -std=c++17 -Wall -Wextra -Wno-unused-parameter $< -o $@ $$($(LLVM_CONFIG) --ldflags --libs core irreader bitwriter analysis support --system-libs)

$(BUILD)/layout: $(HERE)/layout.c $(VMLINUX_DIR)/vmlinux.h
	install -d $(BUILD)
	$(CC) -O2 -I$(VMLINUX_DIR) $< -o $@

$(BUILD)/layout.json: $(BUILD)/layout
	$< > $@

.PHONY: all
all: $(BUILD)/perf-context-lower $(BUILD)/layout.json
