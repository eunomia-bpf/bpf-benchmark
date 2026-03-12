ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
REPO_ROOT := $(abspath $(ROOT_DIR)/..)

BUILD_DIR := $(ROOT_DIR)/build
LIBBPF_BUILD_DIR := $(BUILD_DIR)/vendor/libbpf
LIBBPF_OBJDIR := $(LIBBPF_BUILD_DIR)/obj
LIBBPF_PREFIX := $(LIBBPF_BUILD_DIR)/prefix
LIBBPF_A := $(LIBBPF_OBJDIR)/libbpf.a
LIBBPF_HEADER := $(LIBBPF_PREFIX)/include/bpf/bpf.h

BPFTOOL_BUILD_DIR := $(BUILD_DIR)/vendor/bpftool/
BPFTOOL_BIN := $(BPFTOOL_BUILD_DIR)bpftool

RUNNER_BUILD_DIR := $(BUILD_DIR)/runner
RUNNER_BIN := $(RUNNER_BUILD_DIR)/micro_exec
TOOLS_BUILD_DIR := $(BUILD_DIR)/tools
DIRECTIVE_HINT_BIN := $(TOOLS_BUILD_DIR)/directive_hint

.PHONY: all deps programs micro_exec directive_hint vendor_libbpf vendor_bpftool clean

all: programs micro_exec directive_hint

deps: vendor_libbpf micro_exec directive_hint vendor_bpftool

programs:
	$(MAKE) -C $(ROOT_DIR)/programs

vendor_libbpf: $(LIBBPF_A) $(LIBBPF_HEADER)

$(LIBBPF_A) $(LIBBPF_HEADER):
	mkdir -p $(LIBBPF_OBJDIR)
	mkdir -p $(LIBBPF_PREFIX)
	$(MAKE) -C $(REPO_ROOT)/vendor/libbpf/src \
		BUILD_STATIC_ONLY=1 \
		OBJDIR=$(LIBBPF_OBJDIR) \
		DESTDIR= \
		PREFIX=$(LIBBPF_PREFIX) \
		$(LIBBPF_A) install_headers

$(RUNNER_BUILD_DIR) $(TOOLS_BUILD_DIR) $(BPFTOOL_BUILD_DIR):
	mkdir -p $@

micro_exec: $(LIBBPF_A) $(LIBBPF_HEADER) | $(RUNNER_BUILD_DIR)
	cmake -S $(ROOT_DIR)/runner -B $(RUNNER_BUILD_DIR) \
		-DCMAKE_BUILD_TYPE=Release \
		-DMICRO_REPO_ROOT=$(REPO_ROOT) \
		-DMICRO_LIBBPF_PREFIX=$(LIBBPF_PREFIX) \
		-DMICRO_LIBBPF_LIBRARY=$(LIBBPF_A)
	cmake --build $(RUNNER_BUILD_DIR) --target micro_exec -j

directive_hint: $(LIBBPF_A) $(LIBBPF_HEADER) | $(TOOLS_BUILD_DIR)
	$(CXX) -O2 -g -Wall -Wextra -std=c++20 \
		-I$(LIBBPF_PREFIX)/include \
		-I$(ROOT_DIR)/runner/include \
		-o $(DIRECTIVE_HINT_BIN) \
		$(ROOT_DIR)/tools/directive_hint.c \
		$(ROOT_DIR)/runner/src/common.cpp \
		$(ROOT_DIR)/runner/src/elf_program_loader.cpp \
		$(LIBBPF_A) -lelf -lz

vendor_bpftool: | $(BPFTOOL_BUILD_DIR)
	$(MAKE) -C $(REPO_ROOT)/vendor/bpftool/src \
		OUTPUT=$(BPFTOOL_BUILD_DIR) \
		BPF_DIR=$(REPO_ROOT)/vendor/libbpf/src

clean:
	$(MAKE) -C $(ROOT_DIR)/programs clean
	rm -f $(ROOT_DIR)/generated-inputs/*.mem
	rm -f $(ROOT_DIR)/results/*.json
	rm -rf $(ROOT_DIR)/__pycache__
	@if [ -d "$(BUILD_DIR)" ]; then \
		rm -rf "$(LIBBPF_BUILD_DIR)" "$(BPFTOOL_BUILD_DIR)" "$(RUNNER_BUILD_DIR)"; \
		for entry in "$(BUILD_DIR)"/*; do \
			[ -e "$$entry" ] || continue; \
			rm -rf "$$entry" 2>/dev/null || \
				printf 'Skipping undeletable build artifact: %s\n' "$$entry"; \
		done; \
		rmdir "$(BUILD_DIR)" 2>/dev/null || true; \
	fi
