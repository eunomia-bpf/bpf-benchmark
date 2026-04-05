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
BPFTOOL_RUNTIME ?= /usr/local/sbin/bpftool
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
DAEMON ?= daemon/target/release/bpfrejit-daemon
DAEMON_ARGS ?=
DAEMON_SOCKET ?= /tmp/bpfrejit.sock
VM_BACKEND ?= vng
VM_EXECUTABLE ?= $(ROOT_DIR)/scripts/vng-wrapper.sh
VM_LOCK_SCOPE ?= vm_global
VM_MACHINE_NAME ?= x86-kvm
VM_MACHINE_ARCH ?= x86_64
PROFILE ?=
FILTERS ?=
SAMPLES ?= 3
WARMUPS ?= 1
INNER_REPEAT ?= 100
VM_CORPUS_SAMPLES ?= 30
VM_CORPUS_WORKLOAD_SECONDS ?=
VM_CORPUS_ARGS ?=
BENCH ?=
FUZZ_ROUNDS ?= 1000
VM_COMMAND ?= /bin/bash
E2E_CASE ?= all
E2E_ARGS ?=

BZIMAGE_PATH := $(if $(filter /%,$(BZIMAGE)),$(BZIMAGE),$(REPO_ROOT)/$(BZIMAGE))
DAEMON_PATH := $(if $(filter /%,$(DAEMON)),$(DAEMON),$(REPO_ROOT)/$(DAEMON))
KATRAN_SERVER_BINARY ?= $(REPO_ROOT)/e2e/cases/katran/bin/katran_server_grpc
KATRAN_SERVER_LIB_DIR ?= $(REPO_ROOT)/e2e/cases/katran/lib
VMLINUX_PATH := $(REPO_ROOT)/vendor/linux-framework/vmlinux
MICRO_RUNNER := $(ROOT_DIR)/build/micro_exec
KERNEL_TEST_DIR := $(REPO_ROOT)/tests/kernel
UNITTEST_DIR := $(REPO_ROOT)/tests/unittest
KINSN_MODULE_DIR := $(REPO_ROOT)/module/x86
NEGATIVE_TEST_DIR := $(REPO_ROOT)/tests/negative

MICRO_RESULTS_DIR := $(REPO_ROOT)/micro/results
CORPUS_RESULTS_DIR := $(REPO_ROOT)/corpus/results
E2E_RESULTS_DIR := $(REPO_ROOT)/e2e/results
VM_MICRO_SMOKE_OUTPUT ?= $(MICRO_RESULTS_DIR)/vm_micro_smoke.json
VM_MICRO_OUTPUT ?= $(MICRO_RESULTS_DIR)/vm_micro.json
VM_CORPUS_OUTPUT_JSON ?= $(CORPUS_RESULTS_DIR)/vm_corpus.json
VM_CORPUS_OUTPUT_MD ?= $(CORPUS_RESULTS_DIR)/vm_corpus.md
VM_CPUS ?=
VM_MEM ?=
VM_TEST_TIMEOUT ?= 3600
VM_SELFTEST_TIMEOUT ?= 3600
VM_NEGATIVE_TIMEOUT ?= 3600
VM_MICRO_TIMEOUT ?= 7200
VM_CORPUS_TIMEOUT ?= 7200
VM_E2E_TIMEOUT ?= 7200
SCX_PROG_SHOW_RACE_MODE ?= bpftool-loop
SCX_PROG_SHOW_RACE_ITERATIONS ?= 20
SCX_PROG_SHOW_RACE_LOAD_TIMEOUT ?= 20
SCX_PROG_SHOW_RACE_SKIP_PROBE ?= 0

_VENV_CANDIDATES := $(HOME)/workspace/.venv $(HOME)/.venv $(REPO_ROOT)/.venv $(REPO_ROOT)/venv
_VENV_FOUND := $(firstword $(foreach v,$(_VENV_CANDIDATES),$(if $(wildcard $(v)/bin/activate),$(v),)))
VENV ?= $(_VENV_FOUND)
VENV_ACTIVATE := $(if $(VENV),source "$(VENV)/bin/activate" &&,)
VM_INIT := $(VENV_ACTIVATE)
VM_BACKEND_FLAG := $(if $(strip $(VM_BACKEND)),--vm-backend "$(VM_BACKEND)",)
VM_EXECUTABLE_FLAG := $(if $(strip $(VM_EXECUTABLE)),--vm-executable "$(VM_EXECUTABLE)",)
VM_LOCK_SCOPE_FLAG := $(if $(strip $(VM_LOCK_SCOPE)),--vm-lock-scope "$(VM_LOCK_SCOPE)",)
VM_MACHINE_NAME_FLAG := $(if $(strip $(VM_MACHINE_NAME)),--vm-machine-name "$(VM_MACHINE_NAME)",)
VM_MACHINE_ARCH_FLAG := $(if $(strip $(VM_MACHINE_ARCH)),--vm-machine-arch "$(VM_MACHINE_ARCH)",)
VM_CPU_FLAG := $(if $(strip $(VM_CPUS)),--cpus "$(VM_CPUS)",)
VM_MEM_FLAG := $(if $(strip $(VM_MEM)),--mem "$(VM_MEM)",)
JOBS ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
BPFTOOL_JOBS ?= 1

BENCH_FLAGS := $(foreach b,$(BENCH),--bench $(b))
MICRO_ARGS := --samples $(SAMPLES) --warmups $(WARMUPS) --inner-repeat $(INNER_REPEAT) $(BENCH_FLAGS)
VM_SMOKE_ARGS := --samples 1 --warmups 0 --inner-repeat 50
FILTER_FLAGS := $(foreach filter,$(FILTERS),--filter "$(filter)")
SAMPLES_IS_EXPLICIT := $(or $(findstring command line,$(origin SAMPLES)),$(findstring environment,$(origin SAMPLES)),$(findstring override,$(origin SAMPLES)))
VM_CORPUS_SAMPLES_VALUE := $(if $(strip $(SAMPLES_IS_EXPLICIT)),$(SAMPLES),$(VM_CORPUS_SAMPLES))
VM_CORPUS_SAMPLES_FLAG := --samples "$(VM_CORPUS_SAMPLES_VALUE)"
VM_CORPUS_WORKLOAD_SECONDS_FLAG := $(if $(strip $(VM_CORPUS_WORKLOAD_SECONDS)),--workload-seconds "$(VM_CORPUS_WORKLOAD_SECONDS)",)

.PHONY: all micro_exec vendor_libbpf vendor_bpftool \
	corpus-fetch corpus-build corpus-build-native \
	corpus-build-bcc corpus-build-libbpf-bootstrap corpus-build-xdp-tools corpus-build-xdp-tutorial corpus-build-scx \
	corpus-build-katran corpus-build-tracee corpus-build-tetragon corpus-build-cilium corpus-build-bpftrace \
	scx-artifacts e2e-prep \
	kernel-image unittest-build negative-build upstream-selftests-build kinsn-modules-build micro-programs daemon-binary \
	vm-shell vm-selftest vm-negative-test vm-micro-smoke \
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
	$(PYTHON) "$(ROOT_DIR)/scripts/build_scx_artifacts.py"

e2e-prep:
	@repos="$(strip $(REPOS))"; \
	if [ -z "$$repos" ]; then \
		case "$(strip $(E2E_CASE))" in \
			""|all) repos="tracee tetragon bpftrace scx bcc katran" ;; \
			*) repos="$$(printf '%s\n' "$(strip $(E2E_CASE))" | tr ',' ' ')" ;; \
		esac; \
	fi; \
	native_repos="$$(printf '%s\n' "$$repos" | tr ' ' '\n' | awk '/^(bcc|katran|tracee|tetragon)$$/ { print }' | paste -sd' ' -)"; \
	if [ -n "$$repos" ]; then \
		$(MAKE) corpus-fetch REPOS="$$repos"; \
	fi; \
	if [ -n "$$native_repos" ]; then \
		$(MAKE) corpus-build-native REPOS="$$native_repos"; \
	fi; \
	if printf '%s\n' "$$repos" | tr ' ' '\n' | grep -Fx scx >/dev/null; then \
		$(MAKE) scx-artifacts; \
	fi

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
	$(MAKE) -C "$(NEGATIVE_TEST_DIR)" all

upstream-selftests-build:
	$(MAKE) -C "$(REPO_ROOT)" upstream-selftests-build BZIMAGE="$(BZIMAGE)"

kinsn-modules-build:
	$(MAKE) -C "$(REPO_ROOT)" kinsn-modules BZIMAGE="$(BZIMAGE)"

unittest-build:
	$(MAKE) -C "$(UNITTEST_DIR)" all

micro-programs:
	$(MAKE) -C "$(REPO_ROOT)/micro" programs

daemon-binary:
	cargo build --release --manifest-path "$(REPO_ROOT)/daemon/Cargo.toml"

vm-shell: kernel-image kinsn-modules-build
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" \
		$(VM_BACKEND_FLAG) \
		$(VM_EXECUTABLE_FLAG) \
		$(VM_LOCK_SCOPE_FLAG) \
		$(VM_MACHINE_NAME_FLAG) \
		$(VM_MACHINE_ARCH_FLAG) \
		--action vm-test \
		--kernel-image "$(BZIMAGE_PATH)" \
		$(VM_CPU_FLAG) \
		$(VM_MEM_FLAG) \
		--timeout "$(VM_TEST_TIMEOUT)" \
		--command 'cd "$(REPO_ROOT)" && $(VM_INIT) $(VM_COMMAND)'

vm-selftest: unittest-build negative-build daemon-binary kernel-image kinsn-modules-build
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" \
		$(VM_BACKEND_FLAG) \
		$(VM_EXECUTABLE_FLAG) \
		$(VM_LOCK_SCOPE_FLAG) \
		$(VM_MACHINE_NAME_FLAG) \
		$(VM_MACHINE_ARCH_FLAG) \
		--action vm-selftest \
		--kernel-image "$(BZIMAGE_PATH)" \
		$(VM_CPU_FLAG) \
		$(VM_MEM_FLAG) \
		--timeout "$(VM_SELFTEST_TIMEOUT)" \
		--command '$(VM_INIT) "$(ROOT_DIR)/scripts/vm-selftest.sh" "$(REPO_ROOT)" "$(REPO_ROOT)/tests/unittest" "$(KINSN_MODULE_DIR)" "$(NEGATIVE_TEST_DIR)" "$(FUZZ_ROUNDS)"'

vm-negative-test: scx-artifacts kernel-image kinsn-modules-build
	$(MAKE) -C "$(NEGATIVE_TEST_DIR)"
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" \
		$(VM_BACKEND_FLAG) \
		$(VM_EXECUTABLE_FLAG) \
		$(VM_LOCK_SCOPE_FLAG) \
		$(VM_MACHINE_NAME_FLAG) \
		$(VM_MACHINE_ARCH_FLAG) \
		--action vm-negative-test \
		--kernel-image "$(BZIMAGE_PATH)" \
		$(VM_CPU_FLAG) \
		$(VM_MEM_FLAG) \
		--timeout "$(VM_NEGATIVE_TIMEOUT)" \
		--command '$(VM_INIT) echo "=== adversarial_rejit ===" && "$(NEGATIVE_TEST_DIR)/build/adversarial_rejit" && echo "=== fuzz_rejit ($(FUZZ_ROUNDS) rounds) ===" && "$(NEGATIVE_TEST_DIR)/build/fuzz_rejit" $(FUZZ_ROUNDS) && echo "=== scx_prog_show_race ($(SCX_PROG_SHOW_RACE_MODE)) ===" && "$(NEGATIVE_TEST_DIR)/build/scx_prog_show_race" "$(REPO_ROOT)" --mode "$(SCX_PROG_SHOW_RACE_MODE)" --iterations "$(SCX_PROG_SHOW_RACE_ITERATIONS)" --load-timeout "$(SCX_PROG_SHOW_RACE_LOAD_TIMEOUT)" $(if $(filter 1,$(SCX_PROG_SHOW_RACE_SKIP_PROBE)),--skip-probe,)'

vm-micro-smoke: micro_exec micro-programs kernel-image
	mkdir -p "$(MICRO_RESULTS_DIR)"
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" \
		$(VM_BACKEND_FLAG) \
		$(VM_EXECUTABLE_FLAG) \
		$(VM_LOCK_SCOPE_FLAG) \
		$(VM_MACHINE_NAME_FLAG) \
		$(VM_MACHINE_ARCH_FLAG) \
		--action vm-micro-smoke \
		--kernel-image "$(BZIMAGE_PATH)" \
		$(VM_CPU_FLAG) \
		$(VM_MEM_FLAG) \
		--timeout "$(VM_MICRO_TIMEOUT)" \
		--command 'cd "$(REPO_ROOT)" && $(VENV_ACTIVATE) python3 "$(REPO_ROOT)/micro/driver.py" --runtime llvmbpf --runtime kernel $(VM_SMOKE_ARGS) --output "$(VM_MICRO_SMOKE_OUTPUT)"'

clean:
	rm -rf $(BUILD_DIR)
	rm -f "$(VM_MICRO_SMOKE_OUTPUT)" "$(VM_MICRO_OUTPUT)" \
		"$(VM_CORPUS_OUTPUT_JSON)" "$(VM_CORPUS_OUTPUT_MD)"
