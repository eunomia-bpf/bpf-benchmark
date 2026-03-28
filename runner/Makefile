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
MICRO_EXEC_ENABLE_LLVMBPF ?= ON
PYTHON ?= python3
REPOS ?=
SKIP_CORPUS_FETCH ?= 0
REPO_FLAGS := $(foreach repo,$(REPOS),--repo $(repo))

BZIMAGE ?= vendor/linux-framework/arch/x86/boot/bzImage
DAEMON ?= daemon/target/release/bpfrejit-daemon
DAEMON_ARGS ?=
DAEMON_SOCKET ?= /tmp/bpfrejit.sock
TARGET ?=
PROFILE ?=
FILTERS ?=
ITERATIONS ?= 3
WARMUPS ?= 1
REPEAT ?= 100
BENCH ?=
STATIC_VERIFY_ARGS ?=
FUZZ_ROUNDS ?= 1000
VM_COMMAND ?= /bin/bash
E2E_CASE ?= all
E2E_ARGS ?=

BZIMAGE_PATH := $(if $(filter /%,$(BZIMAGE)),$(BZIMAGE),$(REPO_ROOT)/$(BZIMAGE))
DAEMON_PATH := $(if $(filter /%,$(DAEMON)),$(DAEMON),$(REPO_ROOT)/$(DAEMON))
VMLINUX_PATH := $(REPO_ROOT)/vendor/linux-framework/vmlinux
MICRO_RUNNER := $(ROOT_DIR)/build/micro_exec
KERNEL_TEST_DIR := $(REPO_ROOT)/tests/kernel
UNITTEST_DIR := $(REPO_ROOT)/tests/unittest
KINSN_MODULE_DIR := $(REPO_ROOT)/module/x86
NEGATIVE_TEST_DIR := $(REPO_ROOT)/tests/negative

MICRO_RESULTS_DIR := $(REPO_ROOT)/micro/results
CORPUS_RESULTS_DIR := $(REPO_ROOT)/corpus/results
E2E_RESULTS_DIR := $(REPO_ROOT)/e2e/results
TRACEE_CACHED_BINARY := $(REPO_ROOT)/e2e/cases/tracee/bin/tracee
TRACEE_SETUP_SCRIPT := $(REPO_ROOT)/e2e/cases/tracee/setup.sh
TETRAGON_SETUP_SCRIPT := $(REPO_ROOT)/e2e/cases/tetragon/setup.sh
VM_MICRO_SMOKE_OUTPUT ?= $(MICRO_RESULTS_DIR)/vm_micro_smoke.json
VM_MICRO_OUTPUT ?= $(MICRO_RESULTS_DIR)/vm_micro.json
VM_CORPUS_OUTPUT_JSON ?= $(CORPUS_RESULTS_DIR)/vm_corpus.json
VM_CORPUS_OUTPUT_MD ?= $(CORPUS_RESULTS_DIR)/vm_corpus.md
CORPUS_BUILD_REPORT ?= $(CORPUS_RESULTS_DIR)/expanded_corpus_build.latest.json
VM_STATIC_OUTPUT ?= $(REPO_ROOT)/daemon/tests/results/static_verify.json

VM_CPUS ?=
VM_MEM ?=
VM_TEST_TIMEOUT ?= 3600
VM_SELFTEST_TIMEOUT ?= 3600
VM_STATIC_TIMEOUT ?= 7200
VM_NEGATIVE_TIMEOUT ?= 3600
VM_MICRO_TIMEOUT ?= 7200
VM_E2E_TIMEOUT ?= 7200
SCX_PROG_SHOW_RACE_MODE ?= bpftool-loop
SCX_PROG_SHOW_RACE_ITERATIONS ?= 20
SCX_PROG_SHOW_RACE_LOAD_TIMEOUT ?= 20
SCX_PROG_SHOW_RACE_SKIP_PROBE ?= 0

_VENV_CANDIDATES := $(HOME)/workspace/.venv $(HOME)/.venv $(REPO_ROOT)/.venv $(REPO_ROOT)/venv
_VENV_FOUND := $(firstword $(foreach v,$(_VENV_CANDIDATES),$(if $(wildcard $(v)/bin/activate),$(v),)))
VENV ?= $(_VENV_FOUND)
VENV_ACTIVATE := $(if $(VENV),source "$(VENV)/bin/activate" &&,)
VM_INIT := $(VENV_ACTIVATE) "$(REPO_ROOT)/module/load_all.sh" &&
TARGET_FLAG := $(if $(strip $(TARGET)),--target "$(TARGET)",)
VM_CPU_FLAG := $(if $(strip $(VM_CPUS)),--cpus "$(VM_CPUS)",)
VM_MEM_FLAG := $(if $(strip $(VM_MEM)),--mem "$(VM_MEM)",)
JOBS ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)

BENCH_FLAGS := $(foreach b,$(BENCH),--bench $(b))
MICRO_ARGS := --iterations $(ITERATIONS) --warmups $(WARMUPS) --repeat $(REPEAT) $(BENCH_FLAGS)
VM_SMOKE_ARGS := --iterations 1 --warmups 0 --repeat 50
PROFILE_FLAG := $(if $(strip $(PROFILE)),--profile "$(PROFILE)",)
FILTER_FLAGS := $(foreach filter,$(FILTERS),--filter "$(filter)")
REPEAT_IS_EXPLICIT := $(or $(findstring command line,$(origin REPEAT)),$(findstring environment,$(origin REPEAT)),$(findstring override,$(origin REPEAT)))
VM_CORPUS_OUTPUT_JSON_IS_EXPLICIT := $(or $(findstring command line,$(origin VM_CORPUS_OUTPUT_JSON)),$(findstring environment,$(origin VM_CORPUS_OUTPUT_JSON)),$(findstring override,$(origin VM_CORPUS_OUTPUT_JSON)))
VM_CORPUS_OUTPUT_MD_IS_EXPLICIT := $(or $(findstring command line,$(origin VM_CORPUS_OUTPUT_MD)),$(findstring environment,$(origin VM_CORPUS_OUTPUT_MD)),$(findstring override,$(origin VM_CORPUS_OUTPUT_MD)))
VM_CORPUS_REPEAT_FLAG := $(if $(strip $(REPEAT_IS_EXPLICIT)),--repeat "$(REPEAT)",)
VM_CORPUS_OUTPUT_JSON_FLAG := $(if $(strip $(VM_CORPUS_OUTPUT_JSON_IS_EXPLICIT)),--output-json "$(VM_CORPUS_OUTPUT_JSON)",)
VM_CORPUS_OUTPUT_MD_FLAG := $(if $(strip $(VM_CORPUS_OUTPUT_MD_IS_EXPLICIT)),--output-md "$(VM_CORPUS_OUTPUT_MD)",)

.PHONY: all micro_exec vendor_libbpf vendor_bpftool \
	corpus-fetch corpus-build-objects corpus-build corpus-build-native \
	corpus-build-bcc corpus-build-libbpf-bootstrap corpus-build-xdp-tools corpus-build-xdp-tutorial corpus-build-scx \
	corpus-build-katran corpus-build-tracee corpus-build-tetragon corpus-build-cilium corpus-build-bpftrace \
	scx-artifacts e2e-prep e2e-tracee-setup e2e-tetragon-setup \
	kernel-image unittest-build negative-build upstream-selftests-build kinsn-modules-build micro-programs daemon-binary \
	vm-shell vm-test vm-selftest vm-static-test vm-negative-test vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all \
	clean

all: micro_exec

corpus-fetch:
ifeq ($(SKIP_CORPUS_FETCH),1)
	@echo "corpus-fetch: skipped (SKIP_CORPUS_FETCH=1)"
else
	$(PYTHON) $(ROOT_DIR)/scripts/fetch_corpus_repos.py $(REPO_FLAGS)
endif

corpus-build-objects:
	$(PYTHON) $(ROOT_DIR)/scripts/build_corpus_objects.py $(REPO_FLAGS)

corpus-build: corpus-fetch corpus-build-objects

corpus-build-native: corpus-fetch vendor_bpftool
	$(PYTHON) "$(ROOT_DIR)/scripts/build_corpus_native.py" --jobs "$(JOBS)" $(REPO_FLAGS)

corpus-build-bcc: vendor_bpftool
	$(PYTHON) "$(ROOT_DIR)/scripts/fetch_corpus_repos.py" --repo bcc
	$(PYTHON) "$(ROOT_DIR)/scripts/build_corpus_native.py" --jobs "$(JOBS)" --repo bcc

corpus-build-libbpf-bootstrap: vendor_bpftool
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
	@if [ ! -d "$(REPO_ROOT)/runner/repos/bcc" ] || [ ! -d "$(REPO_ROOT)/runner/repos/scx" ]; then \
		$(PYTHON) "$(ROOT_DIR)/scripts/fetch_corpus_repos.py" --repo bcc --repo scx; \
	fi
	$(PYTHON) "$(ROOT_DIR)/scripts/build_scx_artifacts.py"

e2e-tracee-setup:
	@if [ -x "$(TRACEE_CACHED_BINARY)" ]; then \
		echo "tracee setup: using cached $(TRACEE_CACHED_BINARY)"; \
	else \
		bash "$(TRACEE_SETUP_SCRIPT)" || true; \
	fi

e2e-tetragon-setup:
	@if command -v tetragon >/dev/null 2>&1 && command -v tetra >/dev/null 2>&1 && command -v stress-ng >/dev/null 2>&1; then \
		echo "tetragon setup: using cached system binaries"; \
	else \
		bash "$(TETRAGON_SETUP_SCRIPT)" || true; \
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
	cmake -S $(ROOT_DIR) -B $(BUILD_DIR) \
		-DCMAKE_BUILD_TYPE=Release \
		-DMICRO_REPO_ROOT=$(REPO_ROOT) \
		-DMICRO_LIBBPF_PREFIX=$(LIBBPF_PREFIX) \
		-DMICRO_LIBBPF_LIBRARY=$(LIBBPF_A) \
		-DMICRO_EXEC_ENABLE_LLVMBPF=$(MICRO_EXEC_ENABLE_LLVMBPF)
	cmake --build $(BUILD_DIR) --target micro_exec -j "$(JOBS)"

vendor_bpftool: | $(BPFTOOL_BUILD_DIR)
	$(MAKE) -C $(REPO_ROOT)/vendor/bpftool/src \
		-j"$(JOBS)" \
		OUTPUT=$(BPFTOOL_BUILD_DIR) \
		BPF_DIR=$(REPO_ROOT)/vendor/libbpf/src

kernel-image:
	$(MAKE) -C "$(REPO_ROOT)" kernel BZIMAGE="$(BZIMAGE)"
	$(MAKE) -C "$(REPO_ROOT)" virtme-hostfs-modules BZIMAGE="$(BZIMAGE)"

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
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" $(TARGET_FLAG) \
		--action vm-test \
		--kernel-image "$(BZIMAGE_PATH)" \
		$(VM_CPU_FLAG) \
		$(VM_MEM_FLAG) \
		--timeout "$(VM_TEST_TIMEOUT)" \
		--command 'cd "$(REPO_ROOT)" && $(VM_INIT) $(VM_COMMAND)'

vm-test: scx-artifacts
	$(MAKE) kernel-image BZIMAGE="$(BZIMAGE)"
	$(MAKE) upstream-selftests-build BZIMAGE="$(BZIMAGE)"
	$(MAKE) unittest-build
	$(MAKE) negative-build
	$(MAKE) kinsn-modules-build BZIMAGE="$(BZIMAGE)"
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" $(TARGET_FLAG) \
		--action vm-test \
		--kernel-image "$(BZIMAGE_PATH)" \
		$(VM_CPU_FLAG) \
		$(VM_MEM_FLAG) \
		--timeout "$(VM_TEST_TIMEOUT)" \
		--command 'SCX_PROG_SHOW_RACE_MODE="$(SCX_PROG_SHOW_RACE_MODE)" SCX_PROG_SHOW_RACE_ITERATIONS="$(SCX_PROG_SHOW_RACE_ITERATIONS)" SCX_PROG_SHOW_RACE_LOAD_TIMEOUT="$(SCX_PROG_SHOW_RACE_LOAD_TIMEOUT)" SCX_PROG_SHOW_RACE_SKIP_PROBE="$(SCX_PROG_SHOW_RACE_SKIP_PROBE)" $(VM_INIT) "$(ROOT_DIR)/scripts/run_all_tests.sh" "$(REPO_ROOT)"'

vm-selftest: unittest-build negative-build kernel-image kinsn-modules-build
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" $(TARGET_FLAG) \
		--action vm-selftest \
		--kernel-image "$(BZIMAGE_PATH)" \
		$(VM_CPU_FLAG) \
		$(VM_MEM_FLAG) \
		--timeout "$(VM_SELFTEST_TIMEOUT)" \
		--command '$(VM_INIT) "$(ROOT_DIR)/scripts/vm-selftest.sh" "$(REPO_ROOT)" "$(REPO_ROOT)/tests/unittest" "$(KINSN_MODULE_DIR)" "$(NEGATIVE_TEST_DIR)" "$(FUZZ_ROUNDS)"'

vm-static-test: micro-programs daemon-binary kernel-image kinsn-modules-build
	mkdir -p "$(REPO_ROOT)/daemon/tests/results"
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" $(TARGET_FLAG) \
		--action vm-static-test \
		--kernel-image "$(BZIMAGE_PATH)" \
		$(VM_CPU_FLAG) \
		$(VM_MEM_FLAG) \
		--timeout "$(VM_STATIC_TIMEOUT)" \
		--command 'cd "$(REPO_ROOT)" && $(VM_INIT) python3 "$(REPO_ROOT)/daemon/tests/static_verify.py" --daemon-binary "$(DAEMON_PATH)" --daemon-args="$(DAEMON_ARGS)" --output "$(VM_STATIC_OUTPUT)" $(STATIC_VERIFY_ARGS)'

vm-negative-test: scx-artifacts kernel-image kinsn-modules-build
	$(MAKE) -C "$(NEGATIVE_TEST_DIR)"
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" $(TARGET_FLAG) \
		--action vm-negative-test \
		--kernel-image "$(BZIMAGE_PATH)" \
		$(VM_CPU_FLAG) \
		$(VM_MEM_FLAG) \
		--timeout "$(VM_NEGATIVE_TIMEOUT)" \
		--command '$(VM_INIT) echo "=== adversarial_rejit ===" && "$(NEGATIVE_TEST_DIR)/build/adversarial_rejit" && echo "=== fuzz_rejit ($(FUZZ_ROUNDS) rounds) ===" && "$(NEGATIVE_TEST_DIR)/build/fuzz_rejit" $(FUZZ_ROUNDS) && echo "=== scx_prog_show_race ($(SCX_PROG_SHOW_RACE_MODE)) ===" && "$(NEGATIVE_TEST_DIR)/build/scx_prog_show_race" "$(REPO_ROOT)" --mode "$(SCX_PROG_SHOW_RACE_MODE)" --iterations "$(SCX_PROG_SHOW_RACE_ITERATIONS)" --load-timeout "$(SCX_PROG_SHOW_RACE_LOAD_TIMEOUT)" $(if $(filter 1,$(SCX_PROG_SHOW_RACE_SKIP_PROBE)),--skip-probe,)'

vm-micro-smoke: micro_exec micro-programs daemon-binary kernel-image kinsn-modules-build
	mkdir -p "$(MICRO_RESULTS_DIR)"
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" $(TARGET_FLAG) \
		--action vm-micro-smoke \
		--kernel-image "$(BZIMAGE_PATH)" \
		$(VM_CPU_FLAG) \
		$(VM_MEM_FLAG) \
		--timeout "$(VM_MICRO_TIMEOUT)" \
		--command 'cd "$(REPO_ROOT)" && $(VM_INIT) "$(DAEMON_PATH)" $(DAEMON_ARGS) serve --socket "$(DAEMON_SOCKET)" & DAEMON_PID=$$!; sleep 0.5; trap "kill $$DAEMON_PID 2>/dev/null; rm -f $(DAEMON_SOCKET)" EXIT; python3 "$(REPO_ROOT)/micro/driver.py" --runtime kernel --runtime kernel-rejit --daemon-socket "$(DAEMON_SOCKET)" $(VM_SMOKE_ARGS) --output "$(VM_MICRO_SMOKE_OUTPUT)"'

vm-micro: micro_exec micro-programs daemon-binary kernel-image kinsn-modules-build
	mkdir -p "$(MICRO_RESULTS_DIR)"
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" $(TARGET_FLAG) \
		--action vm-micro \
		--kernel-image "$(BZIMAGE_PATH)" \
		$(VM_CPU_FLAG) \
		$(VM_MEM_FLAG) \
		--timeout "$(VM_MICRO_TIMEOUT)" \
		--command 'cd "$(REPO_ROOT)" && $(VM_INIT) "$(DAEMON_PATH)" $(DAEMON_ARGS) serve --socket "$(DAEMON_SOCKET)" & DAEMON_PID=$$!; sleep 0.5; trap "kill $$DAEMON_PID 2>/dev/null; rm -f $(DAEMON_SOCKET)" EXIT; python3 "$(REPO_ROOT)/micro/driver.py" --runtime llvmbpf --runtime kernel --runtime kernel-rejit --daemon-socket "$(DAEMON_SOCKET)" $(MICRO_ARGS) --output "$(VM_MICRO_OUTPUT)"'

vm-corpus: corpus-build micro_exec daemon-binary kernel-image kinsn-modules-build
	mkdir -p "$(CORPUS_RESULTS_DIR)"
	TARGET="$(TARGET)" $(VENV_ACTIVATE) $(PYTHON) "$(REPO_ROOT)/corpus/driver.py" \
		$(PROFILE_FLAG) \
		$(FILTER_FLAGS) \
		--kernel-image "$(BZIMAGE_PATH)" \
		--runner "$(MICRO_RUNNER)" \
		--daemon "$(DAEMON_PATH)" \
		--btf-custom-path "$(VMLINUX_PATH)" \
		--corpus-build-report "$(CORPUS_BUILD_REPORT)" \
		$(VM_CORPUS_REPEAT_FLAG) \
		$(VM_CORPUS_OUTPUT_JSON_FLAG) \
		$(VM_CORPUS_OUTPUT_MD_FLAG)

vm-e2e: e2e-prep e2e-tracee-setup e2e-tetragon-setup micro_exec daemon-binary kernel-image kinsn-modules-build
	mkdir -p "$(E2E_RESULTS_DIR)"
	$(PYTHON) "$(ROOT_DIR)/scripts/run_vm_shell.py" $(TARGET_FLAG) \
		--action vm-e2e \
		--kernel-image "$(BZIMAGE_PATH)" \
		$(VM_CPU_FLAG) \
		$(VM_MEM_FLAG) \
		--timeout "$(VM_E2E_TIMEOUT)" \
		--command 'cd "$(REPO_ROOT)" && $(VM_INIT) python3 "$(REPO_ROOT)/e2e/run.py" $(E2E_CASE) $(E2E_ARGS)'

vm-all:
	$(MAKE) vm-test TARGET="$(TARGET)"
	$(MAKE) vm-static-test TARGET="$(TARGET)"
	$(MAKE) vm-micro TARGET="$(TARGET)"
	$(MAKE) vm-corpus TARGET="$(TARGET)"
	$(MAKE) vm-e2e TARGET="$(TARGET)"

clean:
	rm -rf $(BUILD_DIR)
	rm -f "$(VM_MICRO_SMOKE_OUTPUT)" "$(VM_MICRO_OUTPUT)" \
		"$(VM_CORPUS_OUTPUT_JSON)" "$(VM_CORPUS_OUTPUT_MD)" "$(VM_STATIC_OUTPUT)"
