SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

$(if $(wildcard vendor/linux-framework/Makefile),,$(error vendor/linux-framework not found. Run: git submodule update --init --recursive))

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
REPO_ROOT := $(ROOT_DIR)
MICRO_DIR := $(ROOT_DIR)/micro
RUNNER_DIR := $(ROOT_DIR)/runner
DAEMON_DIR := $(ROOT_DIR)/daemon
KERNEL_DIR := $(ROOT_DIR)/vendor/linux-framework
KERNEL_TEST_DIR := $(ROOT_DIR)/tests/kernel
KINSN_MODULE_DIR := $(ROOT_DIR)/module/x86
CACHE_DIR := $(ROOT_DIR)/.cache
KINSN_MODULE_OUTPUT_DIR ?=
RUNNER_BUILD_DIR ?= $(RUNNER_DIR)/build

include $(RUNNER_DIR)/mk/arm64_defaults.mk
include $(RUNNER_DIR)/mk/local_prep.mk

# ARM64 / AWS
ARM64_BUILD_DIR     ?= $(KERNEL_DIR)/build-arm64
ARM64_BUILD_CONFIG  := $(ARM64_BUILD_DIR)/.config
ARM64_IMAGE         := $(ARM64_BUILD_DIR)/arch/arm64/boot/Image
ARM64_EFI_IMAGE     := $(ARM64_BUILD_DIR)/arch/arm64/boot/vmlinuz.efi
ARM64_IMAGE_LINK    := $(KERNEL_DIR)/arch/arm64/boot/Image
ARM64_CONFIG_LINK   := $(KERNEL_DIR)/.config.arm64
ARM64_AWS_BUILD_CONFIG := $(ARM64_AWS_BUILD_DIR)/.config
ARM64_AWS_IMAGE     := $(ARM64_AWS_BUILD_DIR)/arch/arm64/boot/Image
ARM64_AWS_EFI_IMAGE := $(ARM64_AWS_BUILD_DIR)/arch/arm64/boot/vmlinuz.efi
ARM64_KERNEL_MAKEFLAGS      := $(filter-out B,$(MAKEFLAGS))
RUN_TARGET_SUITE_CMD  = "$(PYTHON)" -m runner.libs.run_target_suite
AWS_ARM64_BENCH_MODE ?= all

export CROSS_COMPILE_ARM64 ARM64_BUILD_DIR
AWS_X86_BENCH_MODE        ?= all

# Tunables
BZIMAGE ?= vendor/linux-framework/arch/x86/boot/bzImage
E2E_ARGS ?=
E2E_CASE ?= all
VM_CORPUS_ARGS ?=
REPOS ?=
PROFILE ?=
FILTERS ?=
SAMPLES    ?= 3
WARMUPS    ?= 1
INNER_REPEAT ?= 100
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
KALLSYMS_EXTRA_PASS ?= 1

# Derived
BZIMAGE_PATH := $(if $(filter /%,$(BZIMAGE)),$(BZIMAGE),$(ROOT_DIR)/$(BZIMAGE))
KERNEL_CONFIG_PATH := $(KERNEL_DIR)/.config
NPROC        ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
JOBS         ?= $(NPROC)
DEFCONFIG_SRC := $(ROOT_DIR)/vendor/bpfrejit_defconfig
# Results
MICRO_RESULTS_DIR      := $(ROOT_DIR)/micro/results

# Python / venv
_VENV_CANDIDATES := $(HOME)/workspace/.venv $(HOME)/.venv .venv venv
_VENV_FOUND := $(firstword $(foreach v,$(_VENV_CANDIDATES),$(if $(wildcard $(v)/bin/activate),$(v),)))
VENV ?= $(_VENV_FOUND)
PYTHON := $(if $(VENV),$(VENV)/bin/python3,python3)
export BZIMAGE PYTHON LLVM_CONFIG
export VM_TEST_TIMEOUT VM_MICRO_TIMEOUT VM_CORPUS_TIMEOUT VM_E2E_TIMEOUT
export FUZZ_ROUNDS SCX_PROG_SHOW_RACE_MODE SCX_PROG_SHOW_RACE_ITERATIONS SCX_PROG_SHOW_RACE_LOAD_TIMEOUT SCX_PROG_SHOW_RACE_SKIP_PROBE
VENV_ACTIVATE := $(if $(VENV),source "$(VENV)/bin/activate" &&,)

# Benchmark args
ROOT_VM_CORPUS_SAMPLES_IS_EXPLICIT := $(or $(findstring command line,$(origin SAMPLES)),$(findstring environment,$(origin SAMPLES)),$(findstring override,$(origin SAMPLES)))
ROOT_VM_CORPUS_SAMPLES_VALUE := $(if $(strip $(ROOT_VM_CORPUS_SAMPLES_IS_EXPLICIT)),$(SAMPLES),$(VM_CORPUS_SAMPLES))
ROOT_VM_CORPUS_SAMPLES_ARG := SAMPLES="$(ROOT_VM_CORPUS_SAMPLES_VALUE)"
ROOT_VM_CORPUS_FILTERS_ARG := $(if $(strip $(FILTERS)),FILTERS="$(FILTERS)",)
ROOT_VM_CORPUS_WORKLOAD_SECONDS_ARG := $(if $(strip $(VM_CORPUS_WORKLOAD_SECONDS)),VM_CORPUS_WORKLOAD_SECONDS="$(VM_CORPUS_WORKLOAD_SECONDS)",)
ROOT_VM_CORPUS_EXTRA_ARGS := $(if $(strip $(VM_CORPUS_ARGS)),VM_CORPUS_ARGS='$(VM_CORPUS_ARGS)',)

.PHONY: __kernel __kernel-clean __kernel-rebuild __kernel-arm64 __kernel-x86-artifacts __kernel-arm64-aws-artifacts __kinsn-modules \
		__runner-binary __daemon-binary __x86-portable-libbpf __native-repos __prepare-local \
		__repo-test-binaries __micro-programs __scx-binaries \
		check validate \
		vm-selftest vm-negative-test vm-test vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all \
		__kernel-arm64-aws \
		aws-arm64-test aws-arm64-benchmark aws-arm64-terminate aws-arm64 \
		aws-x86-test aws-x86-benchmark aws-x86-terminate aws-x86 \
	help clean

# ── Help ───────────────────────────────────────────────────────────────────────
help:
	@echo "Canonical run targets:"
	@echo "  VM x86:   vm-selftest vm-negative-test vm-test vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all validate"
	@echo "  AWS ARM:  aws-arm64-test aws-arm64-benchmark aws-arm64-terminate aws-arm64"
	@echo "  AWS x86:  aws-x86-test aws-x86-benchmark aws-x86-terminate aws-x86"
	@echo "Params: vm-micro SAMPLES=$(SAMPLES) WARMUPS=$(WARMUPS) INNER_REPEAT=$(INNER_REPEAT) BENCH=\"...\""
	@echo "        vm-corpus SAMPLES=$(VM_CORPUS_SAMPLES) VM_CORPUS_WORKLOAD_SECONDS=$(VM_CORPUS_WORKLOAD_SECONDS) FILTERS=\"...\" VM_CORPUS_ARGS=\"--rejit-passes map_inline,const_prop,dce --no-kinsn\""
	@echo "        vm-e2e E2E_CASE=\"all|tracee|...\" E2E_ARGS=\"--rejit-passes map_inline,const_prop,dce --no-kinsn\" PROFILE=$(PROFILE)"
	@echo "        aws-arm64-test/aws-arm64-benchmark AWS_ARM64_REGION=<region> AWS_ARM64_PROFILE=<profile> AWS_ARM64_ROOT_VOLUME_GB=<override>"
	@echo "        aws-arm64-test AWS_ARM64_TEST_MODE=<selftest|negative|test>"
	@echo "        aws-arm64-benchmark AWS_ARM64_BENCH_MODE=$(AWS_ARM64_BENCH_MODE) AWS_ARM64_E2E_CASES=<all|tracee,tetragon,...>"
	@echo "        aws-x86-test AWS_X86_REGION=<region> AWS_X86_PROFILE=<profile> AWS_X86_TEST_MODE=<selftest|negative|test>"
	@echo "        aws-x86-benchmark AWS_X86_BENCH_MODE=$(AWS_X86_BENCH_MODE) AWS_X86_E2E_CASES=<all|tracee,tetragon,...>"
	@echo "        AWS benchmark mode 'all' fans out micro/corpus/e2e in parallel on dedicated remote instances"
	@echo "Developer-only raw build helpers still exist internally but are intentionally omitted here."

__kernel:
	@test -n "$(BZIMAGE_PATH)" || { echo "BZIMAGE_PATH is required" >&2; exit 1; }
	@if [ ! -f "$(KERNEL_CONFIG_PATH)" ]; then cp "$(DEFCONFIG_SRC)" "$(KERNEL_CONFIG_PATH)"; fi
	$(MAKE) -C "$(KERNEL_DIR)" olddefconfig
	$(MAKE) -C "$(KERNEL_DIR)" -j"$(JOBS)" bzImage modules
	@if [ "$(BZIMAGE_PATH)" != "$(KERNEL_DIR)/arch/x86/boot/bzImage" ]; then \
		mkdir -p "$$(dirname "$(BZIMAGE_PATH)")"; \
		cp "$(KERNEL_DIR)/arch/x86/boot/bzImage" "$(BZIMAGE_PATH)"; \
	fi

__kernel-clean:
	$(MAKE) -C "$(KERNEL_DIR)" clean

__kernel-rebuild: __kernel-clean
	$(MAKE) __kernel BZIMAGE="$(BZIMAGE)"

__kernel-x86-artifacts: __kernel
	@test -n "$(OUTPUT_ROOT)" || { echo "OUTPUT_ROOT is required" >&2; exit 1; }
	@artifact_root="$(OUTPUT_ROOT)"; \
	rm -rf "$$artifact_root"; \
	mkdir -p "$$artifact_root/boot"; \
	kernel_release="$$( $(MAKE) -s -C "$(KERNEL_DIR)" kernelrelease )"; \
	install_root="$$artifact_root/modules-$$kernel_release.root"; \
	mkdir -p "$$install_root"; \
	cp "$(KERNEL_DIR)/arch/x86/boot/bzImage" "$$artifact_root/boot/bzImage-$$kernel_release"; \
	printf '%s\n' "$$kernel_release" > "$$artifact_root/kernel-release.txt"; \
	$(MAKE) -C "$(KERNEL_DIR)" INSTALL_MOD_PATH="$$install_root" DEPMOD=true modules_install; \
	tar -C "$$install_root" -czf "$$artifact_root/modules-$$kernel_release.tar.gz" lib

__kinsn-modules: __kernel
	@module_output_dir="$(if $(strip $(KINSN_MODULE_OUTPUT_DIR)),$(KINSN_MODULE_OUTPUT_DIR),$(KINSN_MODULE_DIR))"; \
	$(MAKE) -C "$(KINSN_MODULE_DIR)" KDIR="$(KERNEL_DIR)"; \
	mkdir -p "$$module_output_dir"; \
	find "$(KINSN_MODULE_DIR)" -maxdepth 1 -type f \( -name '*.ko' -o -name 'modules.order' -o -name 'Module.symvers' \) -exec cp {} "$$module_output_dir"/ \;

$(KERNEL_CONFIG_PATH):
	cp "$(DEFCONFIG_SRC)" "$@"

check:
	@true

validate:
	$(MAKE) check
	$(MAKE) vm-test

# ── VM (x86) ──────────────────────────────────────────────────────────────────
vm-selftest:
	TEST_MODE=selftest $(RUN_TARGET_SUITE_CMD) run x86-kvm test

vm-negative-test:
	TEST_MODE=negative $(RUN_TARGET_SUITE_CMD) run x86-kvm test

vm-test:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm test

vm-micro-smoke:
	SAMPLES=1 WARMUPS=0 INNER_REPEAT=50 $(RUN_TARGET_SUITE_CMD) run x86-kvm micro

vm-micro:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm micro

vm-corpus:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm corpus

vm-e2e:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm e2e

vm-all:
	$(MAKE) vm-test
	$(MAKE) vm-micro
	$(MAKE) vm-corpus
	$(MAKE) vm-e2e

# ── ARM64 kernel ───────────────────────────────────────────────────────────────
$(ARM64_BUILD_CONFIG):
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" "$(PYTHON)" -m runner.libs.arm64_kernel_config local \
		"$(KERNEL_DIR)" "$(ARM64_BUILD_DIR)" "$(CROSS_COMPILE_ARM64)"
	ln -sfn build-arm64/.config "$(ARM64_CONFIG_LINK)"

$(ARM64_IMAGE): $(ARM64_BUILD_CONFIG)
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(KERNEL_DIR)" O="$(ARM64_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" Image -j"$(NPROC)"
	ln -sfn ../../../build-arm64/arch/arm64/boot/Image "$(ARM64_IMAGE_LINK)"

$(ARM64_EFI_IMAGE): $(ARM64_BUILD_CONFIG)
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(KERNEL_DIR)" O="$(ARM64_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" vmlinuz.efi -j"$(NPROC)"

__kernel-arm64: $(ARM64_IMAGE) $(ARM64_EFI_IMAGE)
	ln -sfn build-arm64/.config "$(ARM64_CONFIG_LINK)"
	ln -sfn ../../../build-arm64/arch/arm64/boot/Image "$(ARM64_IMAGE_LINK)"

$(ARM64_AWS_BUILD_CONFIG):
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" ARM64_BASE_CONFIG="$(ARM64_AWS_BASE_CONFIG)" "$(PYTHON)" -m runner.libs.arm64_kernel_config aws \
		"$(KERNEL_DIR)" "$(ARM64_AWS_BUILD_DIR)" "$(CROSS_COMPILE_ARM64)"

$(ARM64_AWS_IMAGE): $(ARM64_AWS_BUILD_CONFIG)
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(KERNEL_DIR)" O="$(ARM64_AWS_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" Image -j"$(NPROC)"

$(ARM64_AWS_EFI_IMAGE): $(ARM64_AWS_BUILD_CONFIG)
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(KERNEL_DIR)" O="$(ARM64_AWS_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" vmlinuz.efi -j"$(NPROC)"

__kernel-arm64-aws: $(ARM64_AWS_IMAGE) $(ARM64_AWS_EFI_IMAGE)

__kernel-arm64-aws-artifacts: __kernel-arm64-aws
	@test -n "$(OUTPUT_ROOT)" || { echo "OUTPUT_ROOT is required" >&2; exit 1; }
	@artifact_root="$(OUTPUT_ROOT)"; \
	rm -rf "$$artifact_root"; \
	mkdir -p "$$artifact_root/boot"; \
	kernel_release="$$( $(MAKE) -s -C "$(KERNEL_DIR)" O="$(ARM64_AWS_BUILD_DIR)" ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" kernelrelease )"; \
	install_root="$$artifact_root/modules-$$kernel_release.root"; \
	mkdir -p "$$install_root"; \
	cp "$(ARM64_AWS_BUILD_DIR)/arch/arm64/boot/vmlinuz.efi" "$$artifact_root/boot/vmlinuz-$$kernel_release.efi"; \
	printf '%s\n' "$$kernel_release" > "$$artifact_root/kernel-release.txt"; \
	$(MAKE) -C "$(KERNEL_DIR)" O="$(ARM64_AWS_BUILD_DIR)" ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" INSTALL_MOD_PATH="$$install_root" DEPMOD=true modules_install; \
	tar -C "$$install_root" -czf "$$artifact_root/modules-$$kernel_release.tar.gz" lib

# ── AWS aliases ───────────────────────────────────────────────────────────────
aws-arm64-test:
	$(RUN_TARGET_SUITE_CMD) run aws-arm64 test

aws-arm64-benchmark:
	$(RUN_TARGET_SUITE_CMD) benchmark aws-arm64 "$(AWS_ARM64_BENCH_MODE)"

aws-arm64-terminate:
	$(RUN_TARGET_SUITE_CMD) terminate aws-arm64

aws-arm64: aws-arm64-test aws-arm64-benchmark

aws-x86-test:
	$(RUN_TARGET_SUITE_CMD) run aws-x86 test

aws-x86-benchmark:
	$(RUN_TARGET_SUITE_CMD) benchmark aws-x86 "$(AWS_X86_BENCH_MODE)"

aws-x86-terminate:
	$(RUN_TARGET_SUITE_CMD) terminate aws-x86

aws-x86: aws-x86-test aws-x86-benchmark

# ── Runner / Daemon ────────────────────────────────────────────────────────────
__daemon-binary:
	@test -n "$(DAEMON_TARGET_DIR)" || { echo "DAEMON_TARGET_DIR is required" >&2; exit 1; }
	@$(MAKE) -C "$(DAEMON_DIR)" release TARGET_DIR="$(DAEMON_TARGET_DIR)" TARGET_TRIPLE="$${DAEMON_TARGET_TRIPLE:-}"

__runner-binary:
	@test -n "$(RUNNER_BUILD_DIR)" || { echo "RUNNER_BUILD_DIR is required" >&2; exit 1; }
	@$(MAKE) -C "$(RUNNER_DIR)" --no-print-directory micro_exec \
		BUILD_DIR="$(RUNNER_BUILD_DIR)" \
		JOBS="$(or $(JOBS),$(NPROC))" \
		MICRO_REPO_ROOT="$(ROOT_DIR)" \
		MICRO_EXEC_ENABLE_LLVMBPF="$${MICRO_EXEC_ENABLE_LLVMBPF:-OFF}" \
		LLVM_DIR="$${RUN_LLVM_DIR:-$${LLVM_DIR:-}}"

__x86-portable-libbpf:
	@test -n "$(X86_PORTABLE_LIBBPF_ROOT)" || { echo "X86_PORTABLE_LIBBPF_ROOT is required" >&2; exit 1; }
	@$(MAKE) -C "$(RUNNER_DIR)" --no-print-directory portable-libbpf \
		OUTPUT_ROOT="$(X86_PORTABLE_LIBBPF_ROOT)"

__native-repos:
	@test -n "$(NATIVE_REPOS_CSV)" || { echo "NATIVE_REPOS_CSV is required" >&2; exit 1; }
	@test -n "$(NATIVE_TARGET_ARCH)" || { echo "NATIVE_TARGET_ARCH is required" >&2; exit 1; }
	@$(MAKE) -C "$(RUNNER_DIR)" native-repos \
		CORPUS_BUILD_DIR="$(ROOT_DIR)/corpus/build" \
		NATIVE_REPOS_CSV="$(NATIVE_REPOS_CSV)" \
		NATIVE_TARGET_ARCH="$(NATIVE_TARGET_ARCH)" \
		JOBS="$(or $(JOBS),$(NPROC))"

__repo-test-binaries:
	@test -n "$(UNITTEST_BUILD_DIR)" || { echo "UNITTEST_BUILD_DIR is required" >&2; exit 1; }
	@test -n "$(NEGATIVE_BUILD_DIR)" || { echo "NEGATIVE_BUILD_DIR is required" >&2; exit 1; }
	@$(MAKE) -C "$(ROOT_DIR)/tests/unittest" BUILD_DIR="$(UNITTEST_BUILD_DIR)"
	@$(MAKE) -C "$(ROOT_DIR)/tests/negative" BUILD_DIR="$(NEGATIVE_BUILD_DIR)"

__micro-programs:
	@test -n "$(MICRO_PROGRAMS_OUTPUT_DIR)" || { echo "MICRO_PROGRAMS_OUTPUT_DIR is required" >&2; exit 1; }
	@$(MAKE) -C "$(ROOT_DIR)/micro/programs" OUTPUT_DIR="$(MICRO_PROGRAMS_OUTPUT_DIR)"

__scx-binaries:
	@test -n "$(SCX_PACKAGES_CSV)" || { echo "SCX_PACKAGES_CSV is required" >&2; exit 1; }
	@$(MAKE) -C "$(RUNNER_DIR)" --no-print-directory scx-binaries \
		SCX_PACKAGES_CSV="$(SCX_PACKAGES_CSV)" \
		SCX_TARGET_TRIPLE="$${SCX_TARGET_TRIPLE:-}" \
		CORPUS_BUILD_DIR="$(ROOT_DIR)/corpus/build"

# ── Clean ──────────────────────────────────────────────────────────────────────
clean:
	rm -rf "$(RUNNER_BUILD_DIR)"
	$(MAKE) -C "$(MICRO_DIR)" clean
	cargo clean --manifest-path "$(DAEMON_DIR)/Cargo.toml"
	$(MAKE) -C "$(KERNEL_DIR)" clean
	rm -f "$(ARM64_CONFIG_LINK)" "$(ARM64_IMAGE_LINK)"
	rm -rf "$(ARM64_BUILD_DIR)" "$(CACHE_DIR)/arm64-host"
	rm -rf \
		"$(CACHE_DIR)/aws-arm64/kernel-build" \
		"$(CACHE_DIR)/aws-arm64/setup-artifacts" \
		"$(CACHE_DIR)/aws-arm64/run-state" \
		"$(CACHE_DIR)/aws-arm64/runs" \
		"$(CACHE_DIR)/aws-arm64/state" \
		"$(CACHE_DIR)/aws-x86/kernel-build" \
		"$(CACHE_DIR)/aws-x86/setup-artifacts" \
		"$(CACHE_DIR)/aws-x86/run-state" \
		"$(CACHE_DIR)/aws-x86/runs" \
		"$(CACHE_DIR)/aws-x86/state"
