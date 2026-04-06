SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
REPO_ROOT := $(abspath $(ROOT_DIR)/..)

BUILD_DIR ?= $(ROOT_DIR)/build
LIBBPF_BUILD_DIR := $(BUILD_DIR)/vendor/libbpf
LIBBPF_OBJDIR := $(LIBBPF_BUILD_DIR)/obj
LIBBPF_PREFIX := $(LIBBPF_BUILD_DIR)/prefix
LIBBPF_A := $(LIBBPF_OBJDIR)/libbpf.a
LIBBPF_HEADER := $(LIBBPF_PREFIX)/include/bpf/bpf.h
BPFTOOL_BUILD_DIR := $(BUILD_DIR)/vendor/bpftool/
BPFTOOL_BOOTSTRAP := $(BPFTOOL_BUILD_DIR)/bootstrap/bpftool
TOOLS_BUILD_DIR := $(BUILD_DIR)/tools
MICRO_EXEC_ENABLE_LLVMBPF ?= ON
LLVM_CONFIG ?= $(shell command -v llvm-config 2>/dev/null)
LLVMBPF_CMAKE_CACHE := $(REPO_ROOT)/vendor/llvmbpf/build/CMakeCache.txt
LLVMBPF_LLVM_DIR ?= $(shell sed -n 's/^LLVM_DIR:PATH=//p' "$(LLVMBPF_CMAKE_CACHE)" 2>/dev/null | head -n 1)
LLVM_DIR_FLAG := $(if $(filter ON,$(MICRO_EXEC_ENABLE_LLVMBPF)),$(if $(strip $(LLVMBPF_LLVM_DIR)),-DLLVM_DIR=$(LLVMBPF_LLVM_DIR),$(if $(LLVM_CONFIG),-DLLVM_DIR=$$($(LLVM_CONFIG) --cmakedir),)),)
MICRO_LLVMBPF_LIBRARY ?=
MICRO_LLVMBPF_BUILD_CACHE ?=
PYTHON ?= python3
REPOS ?=
SKIP_CORPUS_FETCH ?= 0
REPO_FLAGS := $(foreach repo,$(REPOS),--repo $(repo))

BZIMAGE ?= vendor/linux-framework/arch/x86/boot/bzImage
E2E_CASE ?= all
KATRAN_SERVER_BINARY ?= $(REPO_ROOT)/e2e/cases/katran/bin/katran_server_grpc
KATRAN_SERVER_LIB_DIR ?= $(REPO_ROOT)/e2e/cases/katran/lib
UNITTEST_DIR := $(REPO_ROOT)/tests/unittest
NEGATIVE_TEST_DIR := $(REPO_ROOT)/tests/negative
UNITTEST_BUILD_DIR ?= $(UNITTEST_DIR)/build
NEGATIVE_BUILD_DIR ?= $(NEGATIVE_TEST_DIR)/build
MICRO_PROGRAM_OUTPUT_DIR ?= $(REPO_ROOT)/micro/programs
DAEMON_TARGET_DIR ?= $(REPO_ROOT)/daemon/target
KINSN_MODULE_OUTPUT_DIR ?=
JOBS ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
BPFTOOL_JOBS ?= 1

.PHONY: all micro_exec vendor_libbpf vendor_bpftool \
	corpus-fetch corpus-build corpus-build-native \
	corpus-build-bcc corpus-build-libbpf-bootstrap corpus-build-xdp-tools corpus-build-xdp-tutorial corpus-build-scx \
	corpus-build-katran corpus-build-tracee corpus-build-tetragon corpus-build-cilium corpus-build-bpftrace \
	scx-artifacts \
	kernel-image unittest-build negative-build upstream-selftests-build kinsn-modules-build micro-programs daemon-binary \
	clean

all: micro_exec

corpus-fetch:
ifeq ($(SKIP_CORPUS_FETCH),1)
	@echo "corpus-fetch: skipped (SKIP_CORPUS_FETCH=1)"
else
	$(PYTHON) $(ROOT_DIR)/scripts/fetch_corpus_repos.py $(REPO_FLAGS)
endif

corpus-build: corpus-fetch corpus-build-native

corpus-build-native: corpus-fetch
	KATRAN_SERVER_BINARY="$(KATRAN_SERVER_BINARY)" \
	KATRAN_SERVER_LIB_DIR="$(KATRAN_SERVER_LIB_DIR)" \
	$(PYTHON) "$(ROOT_DIR)/scripts/build_corpus_native.py" --jobs "$(JOBS)" $(REPO_FLAGS)

corpus-build-bcc:
	$(PYTHON) "$(ROOT_DIR)/scripts/fetch_corpus_repos.py" --repo bcc
	$(PYTHON) "$(ROOT_DIR)/scripts/build_corpus_native.py" --jobs "$(JOBS)" --repo bcc

corpus-build-libbpf-bootstrap:
	$(PYTHON) "$(ROOT_DIR)/scripts/fetch_corpus_repos.py" --repo libbpf-bootstrap
	$(PYTHON) "$(ROOT_DIR)/scripts/build_corpus_native.py" --jobs "$(JOBS)" --repo libbpf-bootstrap

corpus-build-xdp-tools:
	$(PYTHON) "$(ROOT_DIR)/scripts/fetch_corpus_repos.py" --repo xdp-tools
	$(PYTHON) "$(ROOT_DIR)/scripts/build_corpus_native.py" --jobs "$(JOBS)" --repo xdp-tools

corpus-build-xdp-tutorial:
	$(PYTHON) "$(ROOT_DIR)/scripts/fetch_corpus_repos.py" --repo xdp-tutorial --repo xdp-tools
	$(PYTHON) "$(ROOT_DIR)/scripts/build_corpus_native.py" --jobs "$(JOBS)" --repo xdp-tutorial

corpus-build-scx:
	$(PYTHON) "$(ROOT_DIR)/scripts/fetch_corpus_repos.py" --repo scx
	$(PYTHON) "$(ROOT_DIR)/scripts/build_corpus_native.py" --jobs "$(JOBS)" --repo scx

corpus-build-katran:
	$(PYTHON) "$(ROOT_DIR)/scripts/fetch_corpus_repos.py" --repo katran
	KATRAN_SERVER_BINARY="$(KATRAN_SERVER_BINARY)" \
	KATRAN_SERVER_LIB_DIR="$(KATRAN_SERVER_LIB_DIR)" \
	$(PYTHON) "$(ROOT_DIR)/scripts/build_corpus_native.py" --jobs "$(JOBS)" --repo katran

corpus-build-tracee:
	$(PYTHON) "$(ROOT_DIR)/scripts/fetch_corpus_repos.py" --repo tracee
	$(PYTHON) "$(ROOT_DIR)/scripts/build_corpus_native.py" --jobs "$(JOBS)" --repo tracee

corpus-build-tetragon:
	$(PYTHON) "$(ROOT_DIR)/scripts/fetch_corpus_repos.py" --repo tetragon
	$(PYTHON) "$(ROOT_DIR)/scripts/build_corpus_native.py" --jobs "$(JOBS)" --repo tetragon

corpus-build-cilium:
	$(PYTHON) "$(ROOT_DIR)/scripts/fetch_corpus_repos.py" --repo cilium
	$(PYTHON) "$(ROOT_DIR)/scripts/build_corpus_native.py" --jobs "$(JOBS)" --repo cilium

corpus-build-bpftrace:
	$(PYTHON) "$(ROOT_DIR)/scripts/fetch_corpus_repos.py" --repo bpftrace
	$(PYTHON) "$(ROOT_DIR)/scripts/build_corpus_native.py" --jobs "$(JOBS)" --repo bpftrace

scx-artifacts:
	@if [ ! -d "$(REPO_ROOT)/runner/repos/scx" ]; then \
		$(PYTHON) "$(ROOT_DIR)/scripts/fetch_corpus_repos.py" --repo scx; \
	fi
	$(PYTHON) "$(ROOT_DIR)/scripts/build_scx_artifacts.py" \
		--repo-root "$(REPO_ROOT)/runner/repos" \
		--promote-root "$(REPO_ROOT)"

vendor_libbpf: $(LIBBPF_A) $(LIBBPF_HEADER)

$(LIBBPF_A) $(LIBBPF_HEADER) &:
	mkdir -p $(LIBBPF_OBJDIR)
	mkdir -p $(LIBBPF_PREFIX)
	mkdir -p $(LIBBPF_PREFIX)/include
	$(MAKE) -C $(REPO_ROOT)/vendor/libbpf/src \
		-j"$(JOBS)" \
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
	@if [ "$(MICRO_EXEC_ENABLE_LLVMBPF)" = "ON" ] && [ -z "$(LLVMBPF_LLVM_DIR)" ] && [ -z "$(LLVM_CONFIG)" ]; then \
		echo "MICRO_EXEC_ENABLE_LLVMBPF=ON requires vendor/llvmbpf LLVM_DIR metadata or llvm-config on PATH" >&2; \
		exit 1; \
	fi
	cmake -S $(ROOT_DIR) -B $(BUILD_DIR) \
		-DCMAKE_BUILD_TYPE=Release \
		-DMICRO_REPO_ROOT=$(REPO_ROOT) \
		-DMICRO_LIBBPF_PREFIX=$(LIBBPF_PREFIX) \
		-DMICRO_LIBBPF_LIBRARY=$(LIBBPF_A) \
		$(LLVM_DIR_FLAG) \
		$(if $(strip $(MICRO_LLVMBPF_LIBRARY)),-DMICRO_LLVMBPF_LIBRARY=$(MICRO_LLVMBPF_LIBRARY),) \
		$(if $(strip $(MICRO_LLVMBPF_BUILD_CACHE)),-DMICRO_LLVMBPF_BUILD_CACHE=$(MICRO_LLVMBPF_BUILD_CACHE),) \
		-DMICRO_EXEC_ENABLE_LLVMBPF=$(MICRO_EXEC_ENABLE_LLVMBPF)
	cmake --build $(BUILD_DIR) --target micro_exec -j "$(JOBS)"

vendor_bpftool: | $(BPFTOOL_BUILD_DIR)
	$(MAKE) -C $(REPO_ROOT)/vendor/bpftool/src \
		-j"$(BPFTOOL_JOBS)" \
		OUTPUT=$(BPFTOOL_BUILD_DIR) \
		BPF_DIR=$(REPO_ROOT)/vendor/libbpf/src \
		bootstrap

kernel-image:
	$(MAKE) -C "$(REPO_ROOT)" kernel BZIMAGE="$(BZIMAGE)"

negative-build:
	$(MAKE) -C "$(NEGATIVE_TEST_DIR)" BUILD_DIR="$(NEGATIVE_BUILD_DIR)" all

upstream-selftests-build:
	$(MAKE) -C "$(REPO_ROOT)" upstream-selftests-build \
		BZIMAGE="$(BZIMAGE)" \
		UPSTREAM_SELFTEST_OUTPUT_DIR="$(UPSTREAM_SELFTEST_OUTPUT_DIR)"

kinsn-modules-build:
	$(MAKE) -C "$(REPO_ROOT)" kinsn-modules \
		BZIMAGE="$(BZIMAGE)" \
		KINSN_MODULE_OUTPUT_DIR="$(KINSN_MODULE_OUTPUT_DIR)"

unittest-build:
	$(MAKE) -C "$(UNITTEST_DIR)" BUILD_DIR="$(UNITTEST_BUILD_DIR)" all

micro-programs:
	$(MAKE) -C "$(REPO_ROOT)/micro" programs PROGRAM_OUTPUT_DIR="$(MICRO_PROGRAM_OUTPUT_DIR)"

daemon-binary:
	cargo build --release --target-dir "$(DAEMON_TARGET_DIR)" --manifest-path "$(REPO_ROOT)/daemon/Cargo.toml"

clean:
	rm -rf $(BUILD_DIR)
