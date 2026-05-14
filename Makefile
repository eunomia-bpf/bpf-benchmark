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

ARM64_BUILD_DIR     ?= $(ARTIFACT_ROOT)/arm64-kernel-build


NPROC        ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
JOBS         ?= $(NPROC)
DEFCONFIG_SRC := $(ROOT_DIR)/vendor/bpfrejit_x86_defconfig
ARM64_DEFCONFIG_SRC := $(ROOT_DIR)/vendor/bpfrejit_arm64_defconfig

include $(RUNNER_DIR)/mk/build.mk

export ARM64_BUILD_DIR

# Tunables
PLATFORM ?= kvm
ARCH     ?= x86
BZIMAGE  ?= $(X86_RUNTIME_KERNEL_IMAGE)
SAMPLES  ?= 3
WORKLOAD_DURATION ?=
TIMEOUT  ?= 7200
BENCH    ?=
MICRO_BENCHMARK_SET ?=
MICRO_SUITE ?=
FUZZ_ROUNDS ?= 1000
DOCKER_BUILD_CACHE_KEEP_STORAGE ?= 50GB

# PLATFORM × ARCH → runner target name + suite executor.
ifeq ($(PLATFORM),kvm)
  ifneq ($(ARCH),x86)
    $(error PLATFORM=kvm only supports ARCH=x86)
  endif
  TARGET := x86-kvm
  KVM_HOST_SETUP := kvm-host-cpu
  COMMON_DEPS := $(X86_RUNNER_RUNTIME_IMAGE_TAR) $(X86_RUNTIME_KERNEL_IMAGE) $(DAEMON_DIR)/target/release/bpfrejit-daemon
  EXECUTOR_INVOKE = taskset -c 0-7 "$(PYTHON)" -m runner.libs.kvm_executor
else ifeq ($(PLATFORM),aws)
  EXECUTOR_INVOKE = "$(PYTHON)" -m runner.libs.aws_executor run
  ifeq ($(ARCH),arm64)
    TARGET := aws-arm64
    COMMON_DEPS := $(ARM64_RUNNER_RUNTIME_IMAGE_TAR)
  else ifeq ($(ARCH),x86)
    TARGET := aws-x86
    COMMON_DEPS := $(X86_RUNNER_RUNTIME_IMAGE_TAR) $(DAEMON_DIR)/target/release/bpfrejit-daemon
  else
    $(error PLATFORM=aws supports ARCH={x86,arm64})
  endif
else
  $(error PLATFORM must be kvm or aws)
endif

# Python / venv
_VENV_CANDIDATES := $(HOME)/workspace/.venv $(HOME)/.venv .venv venv
_VENV_FOUND := $(firstword $(foreach v,$(_VENV_CANDIDATES),$(if $(wildcard $(v)/bin/activate),$(v),)))
VENV ?= $(_VENV_FOUND)
PYTHON := $(if $(VENV),$(VENV)/bin/python3,python3)
export BZIMAGE PYTHON LLVM_DIR RUN_LLVM_DIR TIMEOUT FUZZ_ROUNDS WORKLOAD_DURATION

# KEEP_WORKDIRS: empty/0 = no tars (default), 1 = tar on real failures only.
# To capture an artifact from a successful pass, edit the relevant
# runner/config/passes/<pass>/<app>.yaml `command:` to append `&& false` —
# that turns the step into a controlled failure and the existing
# failure-tar pipeline writes the workdir to details/failure-artifacts/.
KEEP_WORKDIRS ?=

# All user knobs flow through to the in-container driver via the all-env
# passthrough in suite_commands.build_runtime_container_command — no enumeration here.
export SAMPLES WARMUPS SKIP_REJIT INNER_REPEAT KEEP_WORKDIRS

# Per-run identity. RUN_TOKEN must be unique per invocation so AWS remote stage
# dirs and local run-state directories don't collide across concurrent or
# sequential failed runs. Random hex when not user-supplied.
RUN_TOKEN ?= $(shell head -c 32 /dev/urandom 2>/dev/null | tr -dc 'a-z0-9' | head -c 8)
export RUN_TOKEN TARGET

# micro and test suites still consume legacy CLI args until their drivers migrate.
MICRO_ARGS = --samples "$(SAMPLES)" --warmups "$(or $(WARMUPS),0)" --inner-repeat "$(or $(INNER_REPEAT),10)" $(if $(MICRO_SUITE),--suite "$(MICRO_SUITE)") $(if $(MICRO_BENCHMARK_SET),--benchmark-set "$(MICRO_BENCHMARK_SET)") $(foreach b,$(BENCH),--bench "$(b)")
TEST_ARGS_COMMON = --fuzz-rounds "$(FUZZ_ROUNDS)"

.PHONY: check validate daemon-tests lint clean \
	selftest negative-test test micro corpus all terminate kvm-host-cpu \
	clean-build clean-results clean-vm-tmp clean-docker-cache

validate:
	$(MAKE) test

check:
	$(MAKE) validate

lint:
	find "$(ROOT_DIR)" \
		\( -path "$(ROOT_DIR)/vendor" -o -path "$(ROOT_DIR)/docs/tmp" -o -path "$(ROOT_DIR)/runner/repos" -o -path "$(ROOT_DIR)/.cache" -o -path "$(ROOT_DIR)/tests/results" -o -path "$(ROOT_DIR)/tests/unittest/build" -o -path "$(ROOT_DIR)/tests/unittest/build-arm64" -o -path "*/__pycache__" \) -prune -o \
		-type f -name '*.py' -exec "$(PYTHON)" -m py_compile {} +

daemon-tests:
	cargo test --workspace --manifest-path "$(DAEMON_DIR)/Cargo.toml"

selftest: $(COMMON_DEPS)
	$(EXECUTOR_INVOKE) $(TARGET) test --test-mode selftest $(TEST_ARGS_COMMON)

negative-test: $(COMMON_DEPS)
	$(EXECUTOR_INVOKE) $(TARGET) test --test-mode negative $(TEST_ARGS_COMMON)

test: $(COMMON_DEPS)
	$(EXECUTOR_INVOKE) $(TARGET) test --test-mode test $(TEST_ARGS_COMMON)

kvm-host-cpu:
	sudo sh -c 'for f in /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor; do echo performance > "$$f"; done'
	sudo sh -c 'echo 1 > /sys/devices/system/cpu/intel_pstate/no_turbo'
	sudo sh -c 'for p in /sys/devices/system/cpu/cpufreq/policy[0-7]; do cat "$$p/scaling_max_freq" > "$$p/scaling_min_freq"; done'

micro: $(KVM_HOST_SETUP) $(COMMON_DEPS)
	$(EXECUTOR_INVOKE) $(TARGET) micro $(MICRO_ARGS)

corpus: $(KVM_HOST_SETUP) $(COMMON_DEPS)
	$(EXECUTOR_INVOKE) $(TARGET) corpus

all: test micro corpus

terminate:
	@if [ "$(PLATFORM)" != aws ]; then echo "terminate requires PLATFORM=aws" >&2; exit 2; fi
	"$(PYTHON)" -m runner.libs.aws_executor terminate $(TARGET)

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
	rm -rf "$(X86_BUILD_DIR)" "$(ARM64_BUILD_DIR)" "$(ARTIFACT_ROOT)/runtime-kernel"
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
