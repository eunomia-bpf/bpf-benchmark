SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
REPO_ROOT := $(abspath $(ROOT_DIR)/..)

include $(ROOT_DIR)/mk/arm64_defaults.mk

ARM64_CROSSBUILD_OUTPUT_DIR ?= $(ARM64_HOST_CACHE_ROOT)/binaries
ARM64_CROSSBUILD_BUILD_ROOT ?= $(ARM64_HOST_CACHE_ROOT)/arm64-cross/build
ARM64_CROSSBUILD_CARGO_HOME ?= $(ARM64_HOST_CACHE_ROOT)/cargo-home
ARM64_HOST_DAEMON_TARGET_DIR ?= $(ARM64_HOST_CACHE_ROOT)/daemon-host-cross/target
ARM64_HOST_DAEMON_OUTPUT_DIR ?= $(ARM64_HOST_CACHE_ROOT)/daemon-host-cross/output
ARM64_HOST_DAEMON_BINARY ?= $(ARM64_HOST_DAEMON_OUTPUT_DIR)/bpfrejit-daemon
ARM64_HOST_DAEMON_CARGO_HOME ?= $(ARM64_HOST_CACHE_ROOT)/cargo-home-host-daemon
ARM64_HOST_SCX_BUILD_ROOT ?= $(ARM64_HOST_CACHE_ROOT)/scx-host-cross/build
ARM64_HOST_SCX_CARGO_HOME ?= $(ARM64_HOST_CACHE_ROOT)/scx-host-cross/cargo-home
ARM64_SOURCE_REPO_ROOT ?= $(REPO_ROOT)/runner/repos
ARM64_SYSROOT_ROOT ?= $(ARM64_HOST_CACHE_ROOT)/sysroot
ARM64_SYSROOT_LOCK_FILE ?= $(ARM64_HOST_CACHE_ROOT)/sysroot.lock
ARM64_SYSROOT_REMOTE_HOST ?=
ARM64_SYSROOT_REMOTE_USER ?=
ARM64_SYSROOT_SSH_KEY_PATH ?=
ARM64_CROSS_RUNNER_REAL ?= $(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/build/micro_exec.real
ARM64_CROSS_DAEMON_REAL ?= $(ARM64_CROSSBUILD_OUTPUT_DIR)/daemon/build/bpfrejit-daemon.real
ARM64_TEST_MODE ?= test
ARM64_TEST_ARTIFACTS_ROOT ?= $(ARM64_HOST_CACHE_ROOT)/test-artifacts
ARM64_TEST_UNITTEST_BUILD_DIR ?= $(ARM64_TEST_ARTIFACTS_ROOT)/unittest/build-arm64
ARM64_TEST_NEGATIVE_BUILD_DIR ?= $(ARM64_TEST_ARTIFACTS_ROOT)/negative/build-arm64
ARM64_TEST_DAEMON_OUTPUT_DIR ?= $(ARM64_TEST_ARTIFACTS_ROOT)/daemon
ARM64_UPSTREAM_SELFTEST_OUTPUT_DIR ?= $(ARM64_TEST_ARTIFACTS_ROOT)/upstream-bpf-selftests
VMLINUX_BTF ?=
arm64_container_path = $(patsubst $(REPO_ROOT)%,/workspace%,$(1))

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
VM_CORPUS_SAMPLES ?= 30
VM_CORPUS_TIMEOUT ?= 7200
UNITTEST_DIR := $(REPO_ROOT)/tests/unittest
NEGATIVE_TEST_DIR := $(REPO_ROOT)/tests/negative
UNITTEST_BUILD_DIR ?= $(UNITTEST_DIR)/build
NEGATIVE_BUILD_DIR ?= $(NEGATIVE_TEST_DIR)/build
MICRO_PROGRAM_OUTPUT_DIR ?= $(REPO_ROOT)/micro/programs
DAEMON_TARGET_DIR ?= $(REPO_ROOT)/daemon/target
KINSN_MODULE_OUTPUT_DIR ?=
JOBS ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
BPFTOOL_JOBS ?= 1
UPSTREAM_SELFTEST_SOURCE_DIR ?= $(REPO_ROOT)/vendor/linux-framework/tools/testing/selftests/bpf
UPSTREAM_SELFTEST_HOST_PYTHON_BIN ?= $(PYTHON)
UPSTREAM_SELFTEST_ARCH ?=
UPSTREAM_SELFTEST_CROSS_COMPILE ?=
UPSTREAM_SELFTEST_SYSROOT_ROOT ?=
UPSTREAM_SELFTEST_PKGCONFIG_LIBDIR ?=

.PHONY: all micro_exec vendor_libbpf vendor_bpftool \
	corpus-fetch corpus-build corpus-build-native \
	corpus-build-bcc corpus-build-libbpf-bootstrap corpus-build-xdp-tools corpus-build-xdp-tutorial corpus-build-scx \
	corpus-build-katran corpus-build-tracee corpus-build-tetragon corpus-build-cilium corpus-build-bpftrace \
	scx-artifacts \
	kernel-image unittest-build negative-build upstream-selftests-build kinsn-modules-build micro-programs daemon-binary daemon-tests \
	__arm64-crossbuild-image __arm64-daemon-host-cross __arm64-workload-tools-host-cross __cross-arm64 __cross-arm64-scx __cross-arm64-bench __arm64-test-artifacts \
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
	UPSTREAM_SELFTEST_SOURCE_DIR="$(UPSTREAM_SELFTEST_SOURCE_DIR)" \
	UPSTREAM_SELFTEST_OUTPUT_DIR="$(UPSTREAM_SELFTEST_OUTPUT_DIR)" \
	UPSTREAM_SELFTEST_HOST_PYTHON_BIN="$(UPSTREAM_SELFTEST_HOST_PYTHON_BIN)" \
	UPSTREAM_SELFTEST_ARCH="$(UPSTREAM_SELFTEST_ARCH)" \
	UPSTREAM_SELFTEST_CROSS_COMPILE="$(UPSTREAM_SELFTEST_CROSS_COMPILE)" \
	UPSTREAM_SELFTEST_SYSROOT_ROOT="$(UPSTREAM_SELFTEST_SYSROOT_ROOT)" \
	UPSTREAM_SELFTEST_PKGCONFIG_LIBDIR="$(UPSTREAM_SELFTEST_PKGCONFIG_LIBDIR)" \
	UPSTREAM_SELFTEST_LLVM_SUFFIX="$(UPSTREAM_SELFTEST_LLVM_SUFFIX)" \
	VMLINUX_BTF="$(VMLINUX_BTF)" \
		bash "$(ROOT_DIR)/scripts/build_upstream_selftests.sh"

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

daemon-tests:
	cargo test --manifest-path "$(REPO_ROOT)/daemon/Cargo.toml"

$(ARM64_CROSSBUILD_STAMP): $(ARM64_CROSSBUILD_DOCKERFILE)
	mkdir -p "$(dir $(ARM64_CROSSBUILD_STAMP))"
	flock "$(ARM64_CROSSBUILD_LOCK)" "$(DOCKER)" buildx build --load --platform "$(ARM64_DOCKER_PLATFORM)" \
		-f "$(ARM64_CROSSBUILD_DOCKERFILE)" -t "$(ARM64_CROSSBUILD_IMAGE)" "$(ARM64_CROSSBUILD_CONTEXT)"
	touch "$@"

__arm64-crossbuild-image: $(ARM64_CROSSBUILD_STAMP)

__arm64-daemon-host-cross:
	ARM64_HOST_DAEMON_TARGET_DIR="$(ARM64_HOST_DAEMON_TARGET_DIR)" \
	ARM64_HOST_DAEMON_OUTPUT_DIR="$(ARM64_HOST_DAEMON_OUTPUT_DIR)" \
	ARM64_HOST_DAEMON_BINARY="$(ARM64_HOST_DAEMON_BINARY)" \
	ARM64_HOST_DAEMON_CARGO_HOME="$(ARM64_HOST_DAEMON_CARGO_HOME)" \
	ARM64_SYSROOT_ROOT="$(ARM64_SYSROOT_ROOT)" \
	ARM64_SYSROOT_LOCK_FILE="$(ARM64_SYSROOT_LOCK_FILE)" \
	ARM64_SYSROOT_REMOTE_HOST="$(ARM64_SYSROOT_REMOTE_HOST)" \
	ARM64_SYSROOT_REMOTE_USER="$(ARM64_SYSROOT_REMOTE_USER)" \
	ARM64_SYSROOT_SSH_KEY_PATH="$(ARM64_SYSROOT_SSH_KEY_PATH)" \
	CROSS_COMPILE_ARM64="$(CROSS_COMPILE_ARM64)" \
	bash "$(REPO_ROOT)/runner/scripts/build-arm64-daemon-host.sh"
	file "$(ARM64_HOST_DAEMON_BINARY)" | grep -F "ELF 64-bit LSB pie executable, ARM aarch64"

__arm64-workload-tools-host-cross:
	ARM64_WORKLOAD_TOOLS_SOURCE_ROOT="$(ARM64_WORKLOAD_TOOLS_SOURCE_ROOT)" \
	ARM64_WORKLOAD_TOOLS_BUILD_ROOT="$(ARM64_WORKLOAD_TOOLS_BUILD_ROOT)" \
	ARM64_WORKLOAD_TOOLS_OUTPUT_ROOT="$(ARM64_WORKLOAD_TOOLS_OUTPUT_ROOT)" \
	ARM64_WORKLOAD_TOOLS_LIST="$(ARM64_WORKLOAD_TOOLS_LIST)" \
	ARM64_SYSROOT_ROOT="$(ARM64_SYSROOT_ROOT)" \
	ARM64_SYSROOT_LOCK_FILE="$(ARM64_SYSROOT_LOCK_FILE)" \
	ARM64_SYSROOT_REMOTE_HOST="$(ARM64_SYSROOT_REMOTE_HOST)" \
	ARM64_SYSROOT_REMOTE_USER="$(ARM64_SYSROOT_REMOTE_USER)" \
	ARM64_SYSROOT_SSH_KEY_PATH="$(ARM64_SYSROOT_SSH_KEY_PATH)" \
	CROSS_COMPILE_ARM64="$(CROSS_COMPILE_ARM64)" \
		bash "$(REPO_ROOT)/runner/scripts/build-arm64-workload-tools-host.sh"
	@if [ -n "$(ARM64_WORKLOAD_TOOLS_LIST)" ]; then \
		tool_root="$(ARM64_WORKLOAD_TOOLS_OUTPUT_ROOT)/workload-tools"; \
		test -d "$$tool_root/bin"; \
		for tool in $$(printf '%s' "$(ARM64_WORKLOAD_TOOLS_LIST)" | tr ',' ' '); do \
			test -x "$$tool_root/bin/$$tool"; \
			test -f "$$tool_root/bin/$$tool.real"; \
			file "$$tool_root/bin/$$tool.real" | grep -F "ARM aarch64" >/dev/null; \
		done; \
	fi

__cross-arm64: __arm64-crossbuild-image
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR).tmp" && mkdir -p "$(ARM64_CROSSBUILD_OUTPUT_DIR).tmp"
	@if [ -z "$(ARM64_CROSSBUILD_RUNTIME_TARGETS)" ] || printf ',%s,' "$(ARM64_CROSSBUILD_RUNTIME_TARGETS)" | grep -q ',daemon,'; then \
		$(MAKE) __arm64-daemon-host-cross \
			ARM64_HOST_DAEMON_TARGET_DIR="$(ARM64_HOST_DAEMON_TARGET_DIR)" \
			ARM64_HOST_DAEMON_OUTPUT_DIR="$(ARM64_HOST_DAEMON_OUTPUT_DIR)" \
			ARM64_HOST_DAEMON_BINARY="$(ARM64_HOST_DAEMON_BINARY)" \
			ARM64_HOST_DAEMON_CARGO_HOME="$(ARM64_HOST_DAEMON_CARGO_HOME)" \
			ARM64_SYSROOT_ROOT="$(ARM64_SYSROOT_ROOT)" \
			ARM64_SYSROOT_LOCK_FILE="$(ARM64_SYSROOT_LOCK_FILE)" \
			ARM64_SYSROOT_REMOTE_HOST="$(ARM64_SYSROOT_REMOTE_HOST)" \
			ARM64_SYSROOT_REMOTE_USER="$(ARM64_SYSROOT_REMOTE_USER)" \
			ARM64_SYSROOT_SSH_KEY_PATH="$(ARM64_SYSROOT_SSH_KEY_PATH)"; \
	fi
	"$(DOCKER)" run --rm --platform "$(ARM64_DOCKER_PLATFORM)" \
		-v "$(REPO_ROOT)":/workspace -w /workspace \
		-e HOME=/tmp/codex \
		-e CARGO_HOME="$(call arm64_container_path,$(ARM64_CROSSBUILD_CARGO_HOME))" \
		-e HOST_UID="$$(id -u)" \
		-e HOST_GID="$$(id -g)" \
		-e ARM64_SOURCE_REPO_ROOT="$(call arm64_container_path,$(ARM64_SOURCE_REPO_ROOT))" \
		-e ARM64_CROSSBUILD_OUTPUT_DIR="$(call arm64_container_path,$(ARM64_CROSSBUILD_OUTPUT_DIR)).tmp" \
		-e ARM64_CROSSBUILD_BUILD_ROOT="$(call arm64_container_path,$(ARM64_CROSSBUILD_BUILD_ROOT))" \
		-e ARM64_CROSSBUILD_JOBS="$(ARM64_CROSSBUILD_JOBS)" \
			-e ARM64_CROSSBUILD_SCX_PACKAGES="$(ARM64_CROSSBUILD_SCX_PACKAGES)" \
			-e ARM64_CROSSBUILD_RUNTIME_TARGETS="$(ARM64_CROSSBUILD_RUNTIME_TARGETS)" \
			-e ARM64_HOST_PYTHON_BIN="$(PYTHON)" \
			-e ARM64_PREBUILT_DAEMON_BINARY="$(call arm64_container_path,$(ARM64_HOST_DAEMON_BINARY))" \
			-e MICRO_EXEC_ENABLE_LLVMBPF="$(ARM64_CROSSBUILD_ENABLE_LLVMBPF)" \
	"$(ARM64_CROSSBUILD_IMAGE)" bash /workspace/runner/scripts/cross-arm64-build.sh
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)" && mv "$(ARM64_CROSSBUILD_OUTPUT_DIR).tmp" "$(ARM64_CROSSBUILD_OUTPUT_DIR)"
	@if [ -z "$(ARM64_CROSSBUILD_RUNTIME_TARGETS)" ] || printf ',%s,' "$(ARM64_CROSSBUILD_RUNTIME_TARGETS)" | grep -q ',runner,'; then \
		file "$(ARM64_CROSS_RUNNER_REAL)" | grep -F "ARM aarch64"; \
	fi
	@if [ -z "$(ARM64_CROSSBUILD_RUNTIME_TARGETS)" ] || printf ',%s,' "$(ARM64_CROSSBUILD_RUNTIME_TARGETS)" | grep -q ',daemon,'; then \
		file "$(ARM64_CROSS_DAEMON_REAL)" | grep -F "ARM aarch64"; \
	fi

__cross-arm64-scx:
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp" && mkdir -p "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp"
	ARM64_SCX_SOURCE_REPO_ROOT="$(ARM64_SOURCE_REPO_ROOT)" \
	ARM64_SCX_BUILD_ROOT="$(ARM64_HOST_SCX_BUILD_ROOT)" \
	ARM64_SCX_PROMOTE_ROOT="$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp" \
	ARM64_SCX_CARGO_HOME="$(ARM64_HOST_SCX_CARGO_HOME)" \
	ARM64_SCX_PACKAGES="$(ARM64_CROSSBUILD_SCX_PACKAGES)" \
	ARM64_SYSROOT_ROOT="$(ARM64_SYSROOT_ROOT)" \
	ARM64_SYSROOT_LOCK_FILE="$(ARM64_SYSROOT_LOCK_FILE)" \
		ARM64_SYSROOT_REMOTE_HOST="$(ARM64_SYSROOT_REMOTE_HOST)" \
		ARM64_SYSROOT_REMOTE_USER="$(ARM64_SYSROOT_REMOTE_USER)" \
		ARM64_SYSROOT_SSH_KEY_PATH="$(ARM64_SYSROOT_SSH_KEY_PATH)" \
		ARM64_HOST_PYTHON_BIN="$(PYTHON)" \
		CROSS_COMPILE_ARM64="$(CROSS_COMPILE_ARM64)" \
		ARM64_CROSSBUILD_JOBS="$(ARM64_CROSSBUILD_JOBS)" \
			bash "$(REPO_ROOT)/runner/scripts/build-arm64-scx-host.sh"
	test -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp/runner/repos/scx/target/release"
	test -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp/corpus/build/scx"
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/repos/scx" "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/scx"
	mkdir -p "$(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/repos/scx/target/release" "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/scx" "$(ARM64_CROSSBUILD_OUTPUT_DIR)/lib"
	cp -a "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp/runner/repos/scx/target/release/." "$(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/repos/scx/target/release/"
	cp -a "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp/corpus/build/scx/." "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/scx/"
	if [ -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp/lib" ]; then cp -a "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp/lib/." "$(ARM64_CROSSBUILD_OUTPUT_DIR)/lib/"; fi
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp"

__cross-arm64-bench: __arm64-crossbuild-image
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp" && mkdir -p "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp"
	"$(DOCKER)" run --rm --platform "$(ARM64_DOCKER_PLATFORM)" \
		-v "$(REPO_ROOT)":/workspace -w /workspace \
		-e HOME=/tmp/codex \
		-e CARGO_HOME="$(call arm64_container_path,$(ARM64_CROSSBUILD_CARGO_HOME))" \
		-e HOST_UID="$$(id -u)" \
		-e HOST_GID="$$(id -g)" \
		-e ARM64_SOURCE_REPO_ROOT="$(call arm64_container_path,$(ARM64_SOURCE_REPO_ROOT))" \
		-e ARM64_CROSSBUILD_OUTPUT_DIR="$(call arm64_container_path,$(ARM64_CROSSBUILD_OUTPUT_DIR)).bench.tmp" \
			-e ARM64_CROSSBUILD_BUILD_ROOT="$(call arm64_container_path,$(ARM64_CROSSBUILD_BUILD_ROOT))" \
			-e ARM64_CROSSBUILD_JOBS="$(ARM64_CROSSBUILD_JOBS)" \
			-e ARM64_CROSSBUILD_BENCH_REPOS="$(ARM64_CROSSBUILD_BENCH_REPOS)" \
			-e ARM64_HOST_PYTHON_BIN="$(PYTHON)" \
			-e ARM64_CROSSBUILD_ONLY_BENCH=1 \
			"$(ARM64_CROSSBUILD_IMAGE)" bash /workspace/runner/scripts/cross-arm64-build.sh
	@set -e; repo_csv="$(ARM64_CROSSBUILD_BENCH_REPOS)"; \
	case ",$$repo_csv," in \
		*,bcc,*) test -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/runner/repos/bcc/libbpf-tools/.output" && test -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/corpus/build/bcc/libbpf-tools" ;; \
	esac; \
	case ",$$repo_csv," in \
		*,katran,*) test -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/corpus/build/katran" && test -x "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/katran/bin/katran_server_grpc" && test -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/katran/lib" ;; \
	esac; \
	case ",$$repo_csv," in \
		*,tracee,*) test -x "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/corpus/build/tracee/bin/tracee" && test -f "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/corpus/build/tracee/tracee.bpf.o" ;; \
	esac; \
	case ",$$repo_csv," in \
		*,tetragon,*) test -x "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/corpus/build/tetragon/bin/tetragon" ;; \
	esac
	@if printf ',%s,' "$(ARM64_CROSSBUILD_BENCH_REPOS)" | grep -q ',bcc,'; then \
		rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/repos/bcc" "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/bcc"; \
	fi
	@if printf ',%s,' "$(ARM64_CROSSBUILD_BENCH_REPOS)" | grep -q ',katran,'; then \
		rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/katran" "$(ARM64_CROSSBUILD_OUTPUT_DIR)/katran"; \
	fi
	@if printf ',%s,' "$(ARM64_CROSSBUILD_BENCH_REPOS)" | grep -q ',tracee,'; then \
		rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/tracee"; \
	fi
	@if printf ',%s,' "$(ARM64_CROSSBUILD_BENCH_REPOS)" | grep -q ',tetragon,'; then \
		rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/tetragon"; \
	fi
	mkdir -p "$(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/repos" "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build" "$(ARM64_CROSSBUILD_OUTPUT_DIR)/lib"
	if [ -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/runner/repos" ]; then cp -a "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/runner/repos/." "$(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/repos/"; fi
	if [ -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/corpus/build" ]; then cp -a "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/corpus/build/." "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/"; fi
	if [ -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/katran" ]; then mkdir -p "$(ARM64_CROSSBUILD_OUTPUT_DIR)/katran" && cp -a "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/katran/." "$(ARM64_CROSSBUILD_OUTPUT_DIR)/katran/"; fi
	if [ -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/lib" ]; then cp -a "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/lib/." "$(ARM64_CROSSBUILD_OUTPUT_DIR)/lib/"; fi
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp"

__arm64-test-artifacts:
	@if [ "$(ARM64_TEST_MODE)" = "selftest" ] || [ "$(ARM64_TEST_MODE)" = "test" ]; then \
		$(MAKE) __arm64-daemon-host-cross \
			ARM64_HOST_DAEMON_TARGET_DIR="$(ARM64_HOST_DAEMON_TARGET_DIR)" \
			ARM64_HOST_DAEMON_OUTPUT_DIR="$(ARM64_HOST_DAEMON_OUTPUT_DIR)" \
			ARM64_HOST_DAEMON_BINARY="$(ARM64_HOST_DAEMON_BINARY)" \
			ARM64_HOST_DAEMON_CARGO_HOME="$(ARM64_HOST_DAEMON_CARGO_HOME)" \
			ARM64_SYSROOT_ROOT="$(ARM64_SYSROOT_ROOT)" \
			ARM64_SYSROOT_LOCK_FILE="$(ARM64_SYSROOT_LOCK_FILE)" \
			ARM64_SYSROOT_REMOTE_HOST="$(ARM64_SYSROOT_REMOTE_HOST)" \
			ARM64_SYSROOT_REMOTE_USER="$(ARM64_SYSROOT_REMOTE_USER)" \
			ARM64_SYSROOT_SSH_KEY_PATH="$(ARM64_SYSROOT_SSH_KEY_PATH)"; \
	fi
	VMLINUX_BTF="$(VMLINUX_BTF)" \
	ARM64_TEST_MODE="$(ARM64_TEST_MODE)" \
	ARM64_TEST_ARTIFACTS_ROOT="$(ARM64_TEST_ARTIFACTS_ROOT)" \
	ARM64_TEST_UNITTEST_BUILD_DIR="$(ARM64_TEST_UNITTEST_BUILD_DIR)" \
	ARM64_TEST_NEGATIVE_BUILD_DIR="$(ARM64_TEST_NEGATIVE_BUILD_DIR)" \
		ARM64_TEST_DAEMON_OUTPUT_DIR="$(ARM64_TEST_DAEMON_OUTPUT_DIR)" \
		ARM64_UPSTREAM_SELFTEST_OUTPUT_DIR="$(ARM64_UPSTREAM_SELFTEST_OUTPUT_DIR)" \
	ARM64_TEST_PREBUILT_DAEMON_BINARY="$(ARM64_HOST_DAEMON_BINARY)" \
	ARM64_HOST_PYTHON_BIN="$(PYTHON)" \
	ARM64_UPSTREAM_SELFTEST_LLVM_SUFFIX="$(UPSTREAM_SELFTEST_LLVM_SUFFIX)" \
	ARM64_SYSROOT_ROOT="$(ARM64_SYSROOT_ROOT)" \
	ARM64_SYSROOT_LOCK_FILE="$(ARM64_SYSROOT_LOCK_FILE)" \
	ARM64_SYSROOT_REMOTE_HOST="$(ARM64_SYSROOT_REMOTE_HOST)" \
	ARM64_SYSROOT_REMOTE_USER="$(ARM64_SYSROOT_REMOTE_USER)" \
	ARM64_SYSROOT_SSH_KEY_PATH="$(ARM64_SYSROOT_SSH_KEY_PATH)" \
		ARM64_CROSSBUILD_JOBS="$(ARM64_CROSSBUILD_JOBS)" \
		CROSS_COMPILE_ARM64="$(CROSS_COMPILE_ARM64)" \
			bash "$(REPO_ROOT)/runner/scripts/build-arm64-repo-tests-host.sh"
	@if [ "$(ARM64_TEST_MODE)" != "negative" ]; then \
		file "$(ARM64_TEST_UNITTEST_BUILD_DIR)/rejit_kinsn" | grep -F "ARM aarch64"; \
	fi
	@if [ "$(ARM64_TEST_MODE)" = "selftest" ] || [ "$(ARM64_TEST_MODE)" = "negative" ] || [ "$(ARM64_TEST_MODE)" = "test" ]; then \
		file "$(ARM64_TEST_NEGATIVE_BUILD_DIR)/adversarial_rejit" | grep -F "ARM aarch64"; \
	fi

clean:
	rm -rf $(BUILD_DIR)
