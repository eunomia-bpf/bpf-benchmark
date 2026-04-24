SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

$(if $(wildcard vendor/linux-framework/Makefile),,$(error vendor/linux-framework not found. Run: git submodule update --init --recursive))

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
MICRO_DIR := $(ROOT_DIR)/micro
RUNNER_DIR := $(ROOT_DIR)/runner
DAEMON_DIR := $(ROOT_DIR)/daemon
KERNEL_DIR := $(ROOT_DIR)/vendor/linux-framework
ARTIFACT_ROOT := $(ROOT_DIR)/.cache
X86_BUILD_DIR ?= $(ARTIFACT_ROOT)/x86-kernel-build
RUNNER_BUILD_DIR ?= $(RUNNER_DIR)/build

# ARM64 / AWS
ARM64_BUILD_DIR     ?= $(ARTIFACT_ROOT)/arm64-kernel-build
RUN_TARGET_SUITE_CMD  = "$(PYTHON)" -m runner.libs.run_target_suite
AWS_ARM64_BENCH_MODE ?=

# Build inputs consumed by included runner make rules.
NPROC        ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
JOBS         ?= $(NPROC)
DEFCONFIG_SRC := $(ROOT_DIR)/vendor/bpfrejit_x86_defconfig
ARM64_DEFCONFIG_SRC := $(ROOT_DIR)/vendor/bpfrejit_arm64_defconfig

include $(RUNNER_DIR)/mk/build.mk

export ARM64_BUILD_DIR
AWS_X86_BENCH_MODE        ?=

# Tunables
BZIMAGE ?= $(X86_RUNTIME_KERNEL_IMAGE)
E2E_ARGS ?=
E2E_SMOKE ?= 0
VM_CORPUS_ARGS ?=
TEST_MODE ?= test
VM_CORPUS_SAMPLES ?= 30
VM_CORPUS_WORKLOAD_SECONDS ?=
VM_TEST_TIMEOUT ?= 3600
VM_MICRO_TIMEOUT ?= 7200
VM_CORPUS_TIMEOUT ?= 7200
VM_E2E_TIMEOUT ?= 7200
BENCH      ?=
FUZZ_ROUNDS ?= 1000
SCX_PROG_SHOW_RACE_MODE ?= bpftool-loop
SCX_PROG_SHOW_RACE_ITERATIONS ?= 20
SCX_PROG_SHOW_RACE_LOAD_TIMEOUT ?= 20
SCX_PROG_SHOW_RACE_SKIP_PROBE ?= 0

# Results
MICRO_RESULTS_DIR      := $(ROOT_DIR)/micro/results

# Python / venv
_VENV_CANDIDATES := $(HOME)/workspace/.venv $(HOME)/.venv .venv venv
_VENV_FOUND := $(firstword $(foreach v,$(_VENV_CANDIDATES),$(if $(wildcard $(v)/bin/activate),$(v),)))
VENV ?= $(_VENV_FOUND)
PYTHON := $(if $(VENV),$(VENV)/bin/python3,python3)
export BZIMAGE PYTHON LLVM_DIR RUN_LLVM_DIR
export VM_TEST_TIMEOUT VM_MICRO_TIMEOUT VM_CORPUS_TIMEOUT VM_E2E_TIMEOUT
export FUZZ_ROUNDS SCX_PROG_SHOW_RACE_MODE SCX_PROG_SHOW_RACE_ITERATIONS SCX_PROG_SHOW_RACE_LOAD_TIMEOUT SCX_PROG_SHOW_RACE_SKIP_PROBE

# Benchmark args
empty :=
space := $(empty) $(empty)
comma := ,
ROOT_VM_CORPUS_SAMPLES_IS_EXPLICIT := $(or $(findstring command line,$(origin SAMPLES)),$(findstring environment,$(origin SAMPLES)),$(findstring override,$(origin SAMPLES)))
ROOT_VM_CORPUS_SAMPLES_VALUE := $(if $(strip $(ROOT_VM_CORPUS_SAMPLES_IS_EXPLICIT)),$(SAMPLES),$(VM_CORPUS_SAMPLES))
VM_MICRO_SMOKE_SUITE_ARGS = --samples "1" --warmups "0" --inner-repeat "50"
VM_CORPUS_SUITE_ARGS = --samples "$(ROOT_VM_CORPUS_SAMPLES_VALUE)" $(if $(strip $(VM_CORPUS_WORKLOAD_SECONDS)),--corpus-workload-seconds "$(VM_CORPUS_WORKLOAD_SECONDS)",) $(if $(strip $(VM_CORPUS_ARGS)),-- $(VM_CORPUS_ARGS),)
VM_E2E_SUITE_ARGS = $(if $(filter 1,$(E2E_SMOKE)),--e2e-smoke,) $(if $(strip $(E2E_ARGS)),-- $(E2E_ARGS),)
VM_TEST_COMMON_SUITE_ARGS = --fuzz-rounds "$(FUZZ_ROUNDS)" --scx-prog-show-race-mode "$(SCX_PROG_SHOW_RACE_MODE)" --scx-prog-show-race-iterations "$(SCX_PROG_SHOW_RACE_ITERATIONS)" --scx-prog-show-race-load-timeout "$(SCX_PROG_SHOW_RACE_LOAD_TIMEOUT)" $(if $(filter 1,$(SCX_PROG_SHOW_RACE_SKIP_PROBE)),--scx-prog-show-race-skip-probe,)
VM_TEST_SUITE_ARGS = --test-mode "$(TEST_MODE)" $(VM_TEST_COMMON_SUITE_ARGS)

.PHONY: check validate \
	vm-selftest vm-negative-test vm-test vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all \
	aws-e2e aws-corpus \
	aws-arm64-test aws-arm64-benchmark aws-arm64-terminate \
	aws-x86-test aws-x86-benchmark aws-x86-terminate \
	help clean

help:
	@echo "Canonical run targets:"
	@echo "  VM x86:   vm-selftest vm-negative-test vm-test vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all validate"
	@echo "  AWS ARM:  aws-arm64-test aws-arm64-benchmark aws-arm64-terminate"
	@echo "  AWS x86:  aws-x86-test aws-x86-benchmark aws-x86-terminate"
	@echo "Params: vm-micro overrides use SAMPLES/WARMUPS/INNER_REPEAT/BENCH; defaults come from runner.libs.suite_args"
	@echo "        vm-corpus SAMPLES=$(VM_CORPUS_SAMPLES) VM_CORPUS_WORKLOAD_SECONDS=$(VM_CORPUS_WORKLOAD_SECONDS) VM_CORPUS_ARGS=\"--no-kinsn\""
	@echo "        vm-e2e E2E_ARGS=\"--no-kinsn\""
	@echo "        aws-arm64-test/aws-arm64-benchmark AWS_ARM64_REGION=<region> AWS_ARM64_PROFILE=<profile> AWS_ARM64_ROOT_VOLUME_GB=<override>"
	@echo "        aws-arm64-test AWS_ARM64_TEST_MODE=<selftest|negative|test>"
	@echo "        aws-arm64-benchmark AWS_ARM64_BENCH_MODE=<micro|corpus|e2e>"
	@echo "        aws-x86-test AWS_X86_REGION=<region> AWS_X86_PROFILE=<profile> AWS_X86_TEST_MODE=<selftest|negative|test>"
	@echo "        aws-x86-benchmark AWS_X86_BENCH_MODE=<micro|corpus|e2e>"

check:
	find corpus runner e2e -type f -name '*.py' \
		-not -path 'runner/repos/*' \
		-not -path 'runner/build-*/*' \
		-not -path 'corpus/results/*' \
		-not -path 'e2e/results/*' \
		-not -path '*/__pycache__/*' \
		-exec $(PYTHON) -m py_compile {} +

validate:
	$(MAKE) check
	$(MAKE) vm-test

vm-selftest:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm test -- --test-mode "selftest" $(VM_TEST_COMMON_SUITE_ARGS)

vm-negative-test:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm test -- --test-mode "negative" $(VM_TEST_COMMON_SUITE_ARGS)

vm-test:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm test -- $(VM_TEST_SUITE_ARGS)

vm-micro-smoke:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm micro -- $(VM_MICRO_SMOKE_SUITE_ARGS)

vm-micro:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm micro

vm-corpus:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm corpus -- $(VM_CORPUS_SUITE_ARGS)

vm-e2e:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm e2e -- $(VM_E2E_SUITE_ARGS)

vm-all:
	$(MAKE) vm-test
	$(MAKE) vm-micro
	$(MAKE) vm-corpus
	$(MAKE) vm-e2e

aws-arm64-test:
	$(RUN_TARGET_SUITE_CMD) run aws-arm64 test

aws-arm64-benchmark:
	$(RUN_TARGET_SUITE_CMD) benchmark aws-arm64 "$(AWS_ARM64_BENCH_MODE)"

aws-arm64-terminate:
	$(RUN_TARGET_SUITE_CMD) terminate aws-arm64

aws-x86-test:
	$(RUN_TARGET_SUITE_CMD) run aws-x86 test

aws-x86-benchmark:
	$(RUN_TARGET_SUITE_CMD) benchmark aws-x86 "$(AWS_X86_BENCH_MODE)"

aws-x86-terminate:
	$(RUN_TARGET_SUITE_CMD) terminate aws-x86

aws-e2e:
	case "$(RUN_TARGET_ARCH)" in \
		arm64) $(RUN_TARGET_SUITE_CMD) run aws-arm64 e2e ;; \
		x86_64) $(RUN_TARGET_SUITE_CMD) run aws-x86 e2e ;; \
		*) echo "unsupported RUN_TARGET_ARCH for aws-e2e: $(RUN_TARGET_ARCH)" >&2; exit 2 ;; \
	esac

aws-corpus:
	case "$(RUN_TARGET_ARCH)" in \
		arm64) $(RUN_TARGET_SUITE_CMD) run aws-arm64 corpus ;; \
		x86_64) $(RUN_TARGET_SUITE_CMD) run aws-x86 corpus ;; \
		*) echo "unsupported RUN_TARGET_ARCH for aws-corpus: $(RUN_TARGET_ARCH)" >&2; exit 2 ;; \
	esac

clean:
	rm -rf "$(RUNNER_BUILD_DIR)"
	rm -rf "$(RUNNER_DIR)/build-x86"
	rm -rf "$(RUNNER_DIR)/build-arm64"
	rm -rf "$(RUNNER_DIR)/build-llvmbpf"
	rm -rf "$(RUNNER_DIR)/build-arm64-llvmbpf"
	$(MAKE) -C "$(MICRO_DIR)" clean
	cargo clean --manifest-path "$(DAEMON_DIR)/Cargo.toml"
	rm -rf "$(X86_BUILD_DIR)" "$(ARM64_BUILD_DIR)" "$(ARTIFACT_ROOT)/runtime-kernel" "$(ROOT_DIR)/.state/runner-contracts"
	rm -rf \
		"$(ARTIFACT_ROOT)/container-images" \
		"$(ARTIFACT_ROOT)/libbpf-build" \
		"$(ARTIFACT_ROOT)/micro-programs" \
		"$(ARTIFACT_ROOT)/repo-artifacts" \
		"$(ARTIFACT_ROOT)/repo-build" \
		"$(ARTIFACT_ROOT)/workload-tools" \
		"$(ARTIFACT_ROOT)/workload-tools-build" \
		"$(ARTIFACT_ROOT)/aws-arm64/kernel-build" \
		"$(ARTIFACT_ROOT)/aws-arm64/results" \
		"$(ARTIFACT_ROOT)/aws-arm64/run-state" \
		"$(ARTIFACT_ROOT)/aws-arm64/runs" \
		"$(ARTIFACT_ROOT)/aws-arm64/state" \
		"$(ARTIFACT_ROOT)/aws-x86/results" \
		"$(ARTIFACT_ROOT)/aws-x86/run-state" \
		"$(ARTIFACT_ROOT)/aws-x86/runs" \
		"$(ARTIFACT_ROOT)/aws-x86/state"
