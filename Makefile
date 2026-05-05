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
TEST_MODE ?= test
VM_CORPUS_SAMPLES ?= 30
VM_TEST_TIMEOUT ?= 3600
VM_MICRO_TIMEOUT ?= 7200
VM_CORPUS_TIMEOUT ?= 7200
DOCKER_BUILD_CACHE_KEEP_STORAGE ?= 50GB
BENCH      ?=
FUZZ_ROUNDS ?= 1000

# Python / venv
_VENV_CANDIDATES := $(HOME)/workspace/.venv $(HOME)/.venv .venv venv
_VENV_FOUND := $(firstword $(foreach v,$(_VENV_CANDIDATES),$(if $(wildcard $(v)/bin/activate),$(v),)))
VENV ?= $(_VENV_FOUND)
PYTHON := $(if $(VENV),$(VENV)/bin/python3,python3)
export BZIMAGE PYTHON LLVM_DIR RUN_LLVM_DIR
export VM_TEST_TIMEOUT VM_MICRO_TIMEOUT VM_CORPUS_TIMEOUT
export FUZZ_ROUNDS

# Benchmark args
ROOT_VM_CORPUS_SAMPLES_IS_EXPLICIT := $(or $(findstring command line,$(origin SAMPLES)),$(findstring environment,$(origin SAMPLES)),$(findstring override,$(origin SAMPLES)))
ROOT_VM_CORPUS_SAMPLES_VALUE := $(if $(strip $(ROOT_VM_CORPUS_SAMPLES_IS_EXPLICIT)),$(SAMPLES),$(VM_CORPUS_SAMPLES))
VM_CORPUS_SUITE_ARGS = --samples "$(ROOT_VM_CORPUS_SAMPLES_VALUE)"
VM_TEST_COMMON_SUITE_ARGS = --fuzz-rounds "$(FUZZ_ROUNDS)"
VM_TEST_SUITE_ARGS = --test-mode "$(TEST_MODE)" $(VM_TEST_COMMON_SUITE_ARGS)

.PHONY: check validate daemon-tests \
	vm-selftest vm-negative-test vm-test vm-micro vm-corpus vm-all \
	aws-corpus \
	aws-arm64-test aws-arm64-benchmark aws-arm64-corpus aws-arm64-terminate \
	aws-x86-test aws-x86-benchmark aws-x86-corpus aws-x86-terminate \
	lint help clean clean-build clean-results clean-vm-tmp clean-docker-cache

help:
	@echo "Canonical run targets:"
	@echo "  VM x86:   vm-selftest vm-negative-test vm-test vm-micro vm-corpus vm-all"
	@echo "  AWS ARM:  aws-arm64-test aws-arm64-benchmark aws-arm64-corpus aws-arm64-terminate"
	@echo "  AWS x86:  aws-x86-test aws-x86-benchmark aws-x86-corpus aws-x86-terminate"
	@echo "Params: vm-micro overrides use SAMPLES/WARMUPS/INNER_REPEAT/BENCH; defaults come from runner.libs.suite_args"
	@echo "        vm-corpus SAMPLES=$(VM_CORPUS_SAMPLES)"
	@echo "        aws-arm64-test/aws-arm64-benchmark AWS_ARM64_REGION=<region> AWS_ARM64_PROFILE=<profile> AWS_ARM64_ROOT_VOLUME_GB=<override>"
	@echo "        aws-arm64-test AWS_ARM64_TEST_MODE=<selftest|negative|test>"
	@echo "        aws-arm64-benchmark AWS_ARM64_BENCH_MODE=<micro|corpus>"
	@echo "        aws-x86-test AWS_X86_REGION=<region> AWS_X86_PROFILE=<profile> AWS_X86_TEST_MODE=<selftest|negative|test>"
	@echo "        aws-x86-benchmark AWS_X86_BENCH_MODE=<micro|corpus>"
	@echo "Cleanup: clean-build clean-results clean-vm-tmp clean-docker-cache"
	@echo "Docker GC: make clean-docker-cache DOCKER_BUILD_CACHE_KEEP_STORAGE=$(DOCKER_BUILD_CACHE_KEEP_STORAGE)"

validate:
	$(MAKE) vm-test

check:
	$(MAKE) validate

lint:
	find "$(ROOT_DIR)" \
		\( -path "$(ROOT_DIR)/vendor" -o -path "$(ROOT_DIR)/docs/tmp" -o -path "$(ROOT_DIR)/runner/repos" -o -path "$(ROOT_DIR)/.cache" -o -path "$(ROOT_DIR)/tests/results" -o -path "$(ROOT_DIR)/tests/unittest/build" -o -path "$(ROOT_DIR)/tests/unittest/build-arm64" -o -path "*/__pycache__" \) -prune -o \
		-type f -name '*.py' -exec "$(PYTHON)" -m py_compile {} +

daemon-tests:
	cargo test --workspace --manifest-path "$(DAEMON_DIR)/Cargo.toml"

_VM_COMMON_DEPS = $(X86_RUNNER_RUNTIME_IMAGE_TAR) $(X86_RUNTIME_KERNEL_IMAGE) $(DAEMON_DIR)/target/release/bpfrejit-daemon

vm-selftest: $(_VM_COMMON_DEPS)
	$(RUN_TARGET_SUITE_CMD) run x86-kvm test -- --test-mode "selftest" $(VM_TEST_COMMON_SUITE_ARGS)

vm-negative-test: $(_VM_COMMON_DEPS)
	$(RUN_TARGET_SUITE_CMD) run x86-kvm test -- --test-mode "negative" $(VM_TEST_COMMON_SUITE_ARGS)

vm-test: $(_VM_COMMON_DEPS)
	$(RUN_TARGET_SUITE_CMD) run x86-kvm test -- $(VM_TEST_SUITE_ARGS)

vm-micro: $(X86_RUNNER_RUNTIME_IMAGE_TAR) $(X86_RUNTIME_KERNEL_IMAGE)
	$(RUN_TARGET_SUITE_CMD) run x86-kvm micro

vm-corpus: $(_VM_COMMON_DEPS)
	$(RUN_TARGET_SUITE_CMD) run x86-kvm corpus -- $(VM_CORPUS_SUITE_ARGS)

vm-all: vm-test vm-micro vm-corpus

_AWS_ARM64_SUITE_DEPS = $(ARM64_RUNNER_RUNTIME_IMAGE_TAR) $(DAEMON_DIR)/target/aarch64-unknown-linux-gnu/release/bpfrejit-daemon
_AWS_X86_SUITE_DEPS  = $(X86_RUNNER_RUNTIME_IMAGE_TAR) $(DAEMON_DIR)/target/release/bpfrejit-daemon

aws-arm64-test: $(_AWS_ARM64_SUITE_DEPS)
	$(RUN_TARGET_SUITE_CMD) run aws-arm64 test

aws-arm64-benchmark: $(_AWS_ARM64_SUITE_DEPS)
	$(RUN_TARGET_SUITE_CMD) benchmark aws-arm64 "$(AWS_ARM64_BENCH_MODE)"

aws-arm64-corpus: $(_AWS_ARM64_SUITE_DEPS)
	$(RUN_TARGET_SUITE_CMD) run aws-arm64 corpus

aws-arm64-terminate:
	$(RUN_TARGET_SUITE_CMD) terminate aws-arm64

aws-x86-test: $(_AWS_X86_SUITE_DEPS)
	$(RUN_TARGET_SUITE_CMD) run aws-x86 test

aws-x86-benchmark: $(_AWS_X86_SUITE_DEPS)
	$(RUN_TARGET_SUITE_CMD) benchmark aws-x86 "$(AWS_X86_BENCH_MODE)"

aws-x86-corpus: $(_AWS_X86_SUITE_DEPS)
	$(RUN_TARGET_SUITE_CMD) run aws-x86 corpus

aws-x86-terminate:
	$(RUN_TARGET_SUITE_CMD) terminate aws-x86

aws-corpus:
	case "$(RUN_TARGET_ARCH)" in \
		arm64) $(MAKE) aws-arm64-corpus ;; \
		x86_64) $(MAKE) aws-x86-corpus ;; \
		*) echo "unsupported RUN_TARGET_ARCH for aws-corpus: $(RUN_TARGET_ARCH)" >&2; exit 2 ;; \
	esac

clean: clean-build clean-vm-tmp

clean-build:
	rm -rf "$(RUNNER_BUILD_DIR)"
	rm -rf "$(RUNNER_DIR)/build-x86"
	rm -rf "$(RUNNER_DIR)/build-arm64"
	rm -rf "$(RUNNER_DIR)/build-llvmbpf"
	rm -rf "$(RUNNER_DIR)/build-arm64-llvmbpf"
	$(MAKE) -C "$(MICRO_DIR)/programs" OUTPUT_DIR="$(MICRO_DIR)/programs" clean
	rm -f "$(MICRO_DIR)"/generated-inputs/*.mem
	rm -rf "$(MICRO_DIR)/__pycache__" "$(MICRO_DIR)/build"
	cargo clean --manifest-path "$(ROOT_DIR)/bpfopt/Cargo.toml"
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
		"$(ARTIFACT_ROOT)/aws-arm64/run-state" \
		"$(ARTIFACT_ROOT)/aws-arm64/runs" \
		"$(ARTIFACT_ROOT)/aws-arm64/state" \
		"$(ARTIFACT_ROOT)/aws-x86/run-state" \
		"$(ARTIFACT_ROOT)/aws-x86/runs" \
		"$(ARTIFACT_ROOT)/aws-x86/state"

clean-results:
	@# results retention is manual; see docs/tmp/p89_disk_audit.md
	@echo "Result cleanup is manual; see docs/tmp/p89_disk_audit.md"

clean-vm-tmp:
	if [ -d "$(ROOT_DIR)/docs/tmp" ]; then find "$(ROOT_DIR)/docs/tmp" -path '*/vm-tmp/*.img' -type f -delete; fi
	if [ -d "$(ROOT_DIR)/docs/tmp/runtime-container-tmp" ]; then find "$(ROOT_DIR)/docs/tmp/runtime-container-tmp" -maxdepth 1 -mindepth 1 -type d -name 'run.*' -exec rm -rf {} +; fi

clean-docker-cache:
	@echo "Docker build cache is not pruned automatically."
	@echo "After confirming no image build is active, run:"
	@echo "  docker buildx prune --keep-storage $(DOCKER_BUILD_CACHE_KEEP_STORAGE)"
	@echo "See docs/docker-build-cache-gc.md"
