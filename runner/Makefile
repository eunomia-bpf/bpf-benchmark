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
BPFTOOL_BUILD_DIR := $(BUILD_DIR)/vendor/bpftool
TOOLS_BUILD_DIR := $(BUILD_DIR)/tools
DIRECTIVE_HINT_BIN := $(TOOLS_BUILD_DIR)/directive_hint
MICRO_EXEC_ENABLE_LLVMBPF ?= ON
PYTHON ?= python3
REPOS ?=
REPO_FLAGS := $(foreach repo,$(REPOS),--repo $(repo))

BZIMAGE ?= vendor/linux-framework/arch/x86/boot/bzImage
DAEMON ?= daemon/target/release/bpfrejit-daemon
DAEMON_SOCKET ?= /tmp/bpfrejit.sock
TARGET ?=
ITERATIONS ?= 3
WARMUPS ?= 1
REPEAT ?= 100
BENCH ?=
STATIC_VERIFY_ARGS ?=
FUZZ_ROUNDS ?= 1000

BZIMAGE_PATH := $(if $(filter /%,$(BZIMAGE)),$(BZIMAGE),$(REPO_ROOT)/$(BZIMAGE))
DAEMON_PATH := $(if $(filter /%,$(DAEMON)),$(DAEMON),$(REPO_ROOT)/$(DAEMON))
VMLINUX_PATH := $(REPO_ROOT)/vendor/linux-framework/vmlinux
MICRO_RUNNER := $(ROOT_DIR)/build/micro_exec
KERNEL_TEST_DIR := $(REPO_ROOT)/tests/kernel
KINSN_MODULE_DIR := $(REPO_ROOT)/module/x86
NEGATIVE_TEST_DIR := $(REPO_ROOT)/tests/negative

MICRO_RESULTS_DIR := $(REPO_ROOT)/micro/results
CORPUS_RESULTS_DIR := $(REPO_ROOT)/corpus/results
E2E_RESULTS_DIR := $(REPO_ROOT)/e2e/results
VM_MICRO_SMOKE_OUTPUT ?= $(MICRO_RESULTS_DIR)/vm_micro_smoke.json
VM_MICRO_OUTPUT ?= $(MICRO_RESULTS_DIR)/vm_micro.json
VM_CORPUS_OUTPUT_JSON ?= $(CORPUS_RESULTS_DIR)/vm_corpus.json
VM_CORPUS_OUTPUT_MD ?= $(CORPUS_RESULTS_DIR)/vm_corpus.md
VM_STATIC_OUTPUT ?= $(REPO_ROOT)/daemon/tests/results/static_verify.json

VM_CPUS ?= 2
VM_MEM ?= 4G
VM_TEST_TIMEOUT ?= 3600
VM_SELFTEST_TIMEOUT ?= 3600
VM_STATIC_TIMEOUT ?= 7200
VM_NEGATIVE_TIMEOUT ?= 3600
VM_MICRO_TIMEOUT ?= 7200
VM_E2E_TIMEOUT ?= 7200

_VENV_CANDIDATES := $(HOME)/workspace/.venv $(HOME)/.venv $(REPO_ROOT)/.venv $(REPO_ROOT)/venv
_VENV_FOUND := $(firstword $(foreach v,$(_VENV_CANDIDATES),$(if $(wildcard $(v)/bin/activate),$(v),)))
VENV ?= $(_VENV_FOUND)
VENV_ACTIVATE := $(if $(VENV),source "$(VENV)/bin/activate" &&,)
VM_INIT := $(VENV_ACTIVATE) "$(REPO_ROOT)/module/load_all.sh" 2>/dev/null || true;
TARGET_FLAG := $(if $(strip $(TARGET)),--target "$(TARGET)",)

BENCH_FLAGS := $(foreach b,$(BENCH),--bench $(b))
MICRO_ARGS := --iterations $(ITERATIONS) --warmups $(WARMUPS) --repeat $(REPEAT) $(BENCH_FLAGS)
VM_SMOKE_ARGS := --iterations 1 --warmups 0 --repeat 50

.PHONY: all micro_exec directive_hint vendor_libbpf vendor_bpftool \
	corpus-fetch corpus-build-objects corpus-build \
	scx-artifacts e2e-prep \
	kernel-image kernel-tests-build kinsn-modules-build micro-programs daemon-binary \
	vm-test vm-selftest vm-static-test vm-negative-test vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all \
	clean

all: micro_exec directive_hint

corpus-fetch:
	$(PYTHON) $(ROOT_DIR)/scripts/fetch_corpus_repos.py $(REPO_FLAGS)

corpus-build-objects:
	$(PYTHON) $(ROOT_DIR)/scripts/build_corpus_objects.py $(REPO_FLAGS)

corpus-build: corpus-fetch corpus-build-objects

scx-artifacts:
	@if [ ! -d "$(REPO_ROOT)/runner/repos/scx" ]; then \
		$(PYTHON) "$(ROOT_DIR)/scripts/fetch_corpus_repos.py" --repo scx; \
	fi
	$(PYTHON) "$(ROOT_DIR)/scripts/build_scx_artifacts.py"

e2e-prep:
	@if [ ! -d "$(REPO_ROOT)/runner/repos/bcc" ] || [ ! -d "$(REPO_ROOT)/runner/repos/scx" ]; then \
		$(PYTHON) "$(ROOT_DIR)/scripts/fetch_corpus_repos.py" --repo bcc --repo scx; \
	fi
	$(PYTHON) "$(ROOT_DIR)/scripts/build_scx_artifacts.py"

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

kernel-image:
	$(MAKE) -C "$(REPO_ROOT)" kernel BZIMAGE="$(BZIMAGE)"

kernel-tests-build:
	$(MAKE) -C "$(REPO_ROOT)" kernel-tests

kinsn-modules-build:
	$(MAKE) -C "$(REPO_ROOT)" kinsn-modules BZIMAGE="$(BZIMAGE)"

micro-programs:
	$(MAKE) -C "$(REPO_ROOT)/micro" programs

daemon-binary:
	cargo build --release --manifest-path "$(REPO_ROOT)/daemon/Cargo.toml"

vm-test: kernel-tests-build kernel-image kinsn-modules-build
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" $(TARGET_FLAG) \
		--action vm-test \
		--kernel-image "$(BZIMAGE_PATH)" \
		--cpus "$(VM_CPUS)" \
		--mem "$(VM_MEM)" \
		--timeout "$(VM_TEST_TIMEOUT)" \
		--command '$(VM_INIT) "$(ROOT_DIR)/scripts/run_all_tests.sh" "$(REPO_ROOT)"'

vm-selftest: kernel-tests-build kernel-image kinsn-modules-build
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" $(TARGET_FLAG) \
		--action vm-selftest \
		--kernel-image "$(BZIMAGE_PATH)" \
		--cpus "$(VM_CPUS)" \
		--mem "$(VM_MEM)" \
		--timeout "$(VM_SELFTEST_TIMEOUT)" \
		--command '$(VM_INIT) "$(ROOT_DIR)/scripts/vm-selftest.sh" "$(REPO_ROOT)" "$(KERNEL_TEST_DIR)/build/test_recompile" "$(REPO_ROOT)/tests/unittest" "$(KINSN_MODULE_DIR)"'

vm-static-test: micro-programs daemon-binary kernel-image kinsn-modules-build
	mkdir -p "$(REPO_ROOT)/daemon/tests/results"
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" $(TARGET_FLAG) \
		--action vm-static-test \
		--kernel-image "$(BZIMAGE_PATH)" \
		--cpus "$(VM_CPUS)" \
		--mem "$(VM_MEM)" \
		--timeout "$(VM_STATIC_TIMEOUT)" \
		--command 'cd "$(REPO_ROOT)" && $(VM_INIT) python3 "$(REPO_ROOT)/daemon/tests/static_verify.py" --daemon-binary "$(DAEMON_PATH)" --output "$(VM_STATIC_OUTPUT)" $(STATIC_VERIFY_ARGS)'

vm-negative-test: kernel-image kinsn-modules-build
	$(MAKE) -C "$(NEGATIVE_TEST_DIR)"
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" $(TARGET_FLAG) \
		--action vm-negative-test \
		--kernel-image "$(BZIMAGE_PATH)" \
		--cpus "$(VM_CPUS)" \
		--mem "$(VM_MEM)" \
		--timeout "$(VM_NEGATIVE_TIMEOUT)" \
		--command '$(VM_INIT) echo "=== adversarial_rejit ===" && "$(NEGATIVE_TEST_DIR)/build/adversarial_rejit" && echo "=== fuzz_rejit ($(FUZZ_ROUNDS) rounds) ===" && "$(NEGATIVE_TEST_DIR)/build/fuzz_rejit" $(FUZZ_ROUNDS)'

vm-micro-smoke: micro_exec micro-programs daemon-binary kernel-image kinsn-modules-build
	mkdir -p "$(MICRO_RESULTS_DIR)"
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" $(TARGET_FLAG) \
		--action vm-micro-smoke \
		--kernel-image "$(BZIMAGE_PATH)" \
		--cpus "$(VM_CPUS)" \
		--mem "$(VM_MEM)" \
		--timeout "$(VM_MICRO_TIMEOUT)" \
		--command 'cd "$(REPO_ROOT)" && $(VM_INIT) "$(DAEMON_PATH)" --pgo serve --socket "$(DAEMON_SOCKET)" & DAEMON_PID=$$!; sleep 0.5; trap "kill $$DAEMON_PID 2>/dev/null; rm -f $(DAEMON_SOCKET)" EXIT; python3 "$(REPO_ROOT)/micro/driver.py" --runtime kernel --runtime kernel-rejit --daemon-socket "$(DAEMON_SOCKET)" $(VM_SMOKE_ARGS) --output "$(VM_MICRO_SMOKE_OUTPUT)"'

vm-micro: micro_exec micro-programs daemon-binary kernel-image kinsn-modules-build
	mkdir -p "$(MICRO_RESULTS_DIR)"
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" $(TARGET_FLAG) \
		--action vm-micro \
		--kernel-image "$(BZIMAGE_PATH)" \
		--cpus "$(VM_CPUS)" \
		--mem "$(VM_MEM)" \
		--timeout "$(VM_MICRO_TIMEOUT)" \
		--command 'cd "$(REPO_ROOT)" && $(VM_INIT) "$(DAEMON_PATH)" --pgo serve --socket "$(DAEMON_SOCKET)" & DAEMON_PID=$$!; sleep 0.5; trap "kill $$DAEMON_PID 2>/dev/null; rm -f $(DAEMON_SOCKET)" EXIT; python3 "$(REPO_ROOT)/micro/driver.py" --runtime llvmbpf --runtime kernel --runtime kernel-rejit --daemon-socket "$(DAEMON_SOCKET)" $(MICRO_ARGS) --output "$(VM_MICRO_OUTPUT)"'

vm-corpus: micro_exec daemon-binary kernel-image kinsn-modules-build
	mkdir -p "$(CORPUS_RESULTS_DIR)"
	TARGET="$(TARGET)" $(VENV_ACTIVATE) $(PYTHON) "$(REPO_ROOT)/corpus/driver.py" packet \
		--kernel-image "$(BZIMAGE_PATH)" \
		--runner "$(MICRO_RUNNER)" \
		--daemon "$(DAEMON_PATH)" \
		--btf-custom-path "$(VMLINUX_PATH)" \
		--repeat "$(REPEAT)" \
		--output-json "$(VM_CORPUS_OUTPUT_JSON)" \
		--output-md "$(VM_CORPUS_OUTPUT_MD)"

vm-e2e: e2e-prep micro_exec daemon-binary kernel-image kinsn-modules-build
	mkdir -p "$(E2E_RESULTS_DIR)"
	bash "$(REPO_ROOT)/e2e/cases/tracee/setup.sh" || true
	bash "$(REPO_ROOT)/e2e/cases/tetragon/setup.sh" || true
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" $(TARGET_FLAG) \
		--action vm-e2e \
		--kernel-image "$(BZIMAGE_PATH)" \
		--cpus "$(VM_CPUS)" \
		--mem "$(VM_MEM)" \
		--timeout "$(VM_E2E_TIMEOUT)" \
		--command 'cd "$(REPO_ROOT)" && $(VM_INIT) python3 "$(REPO_ROOT)/e2e/run.py" all'

vm-all:
	$(MAKE) vm-test TARGET="$(TARGET)"
	$(MAKE) vm-micro TARGET="$(TARGET)"
	$(MAKE) vm-corpus TARGET="$(TARGET)"
	$(MAKE) vm-e2e TARGET="$(TARGET)"

clean:
	rm -rf $(BUILD_DIR)
	rm -f "$(VM_MICRO_SMOKE_OUTPUT)" "$(VM_MICRO_OUTPUT)" \
		"$(VM_CORPUS_OUTPUT_JSON)" "$(VM_CORPUS_OUTPUT_MD)" "$(VM_STATIC_OUTPUT)"
