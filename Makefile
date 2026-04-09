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
ARTIFACT_ROOT := $(ROOT_DIR)/.cache
X86_BUILD_DIR ?= $(ARTIFACT_ROOT)/x86-kernel-build
X86_KERNEL_LOCK := $(ARTIFACT_ROOT)/x86-kernel.lock
ARM64_AWS_KERNEL_LOCK := $(ARTIFACT_ROOT)/arm64-aws-kernel.lock
RUNNER_BUILD_DIR ?= $(RUNNER_DIR)/build

include $(RUNNER_DIR)/mk/arm64_defaults.mk
include $(RUNNER_DIR)/mk/build.mk
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
BZIMAGE ?= $(X86_BUILD_DIR)/arch/x86/boot/bzImage
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
KERNEL_CONFIG_PATH := $(X86_BUILD_DIR)/.config
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

.PHONY: check validate \
		vm-selftest vm-negative-test vm-test vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all \
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
	@mkdir -p "$(ARTIFACT_ROOT)"; \
	flock "$(X86_KERNEL_LOCK)" "$(MAKE)" --no-print-directory __kernel-inner BZIMAGE="$(BZIMAGE)"

__kernel-inner:
	@test -n "$(BZIMAGE_PATH)" || { echo "BZIMAGE_PATH is required" >&2; exit 1; }
	@mkdir -p "$(X86_BUILD_DIR)"
	@if [ ! -f "$(KERNEL_CONFIG_PATH)" ]; then cp "$(DEFCONFIG_SRC)" "$(KERNEL_CONFIG_PATH)"; fi
	@$(MAKE) -C "$(KERNEL_DIR)" O="$(X86_BUILD_DIR)" olddefconfig
	@set -e; \
	if [ -f "$(X86_BUILD_DIR)/arch/x86/boot/bzImage" ]; then \
		if $(MAKE) -C "$(KERNEL_DIR)" O="$(X86_BUILD_DIR)" -q bzImage modules; then \
			echo "[kernel] reuse existing x86 bzImage/modules"; \
		else \
			status="$$?"; \
			if [ "$$status" -eq 1 ]; then \
				$(MAKE) -C "$(KERNEL_DIR)" O="$(X86_BUILD_DIR)" -j"$(JOBS)" bzImage modules; \
			else \
				exit "$$status"; \
			fi; \
		fi; \
	else \
		$(MAKE) -C "$(KERNEL_DIR)" O="$(X86_BUILD_DIR)" -j"$(JOBS)" bzImage modules; \
	fi
	@if [ "$(BZIMAGE_PATH)" != "$(X86_BUILD_DIR)/arch/x86/boot/bzImage" ]; then \
		mkdir -p "$$(dirname "$(BZIMAGE_PATH)")"; \
		cp "$(X86_BUILD_DIR)/arch/x86/boot/bzImage" "$(BZIMAGE_PATH)"; \
	fi

__kernel-clean:
	rm -rf "$(X86_BUILD_DIR)"

__kernel-rebuild: __kernel-clean
	$(MAKE) __kernel BZIMAGE="$(BZIMAGE)"

__kernel-x86-artifacts:
	@test -n "$(OUTPUT_ROOT)" || { echo "OUTPUT_ROOT is required" >&2; exit 1; }
	@mkdir -p "$(ARTIFACT_ROOT)"; \
	flock "$(X86_KERNEL_LOCK)" bash -eu -o pipefail -c '\
		artifact_root="$(OUTPUT_ROOT)"; \
		$(MAKE) --no-print-directory __kernel-inner BZIMAGE="$(BZIMAGE)"; \
		kernel_release_file="$(X86_BUILD_DIR)/include/config/kernel.release"; \
		[[ -f "$$kernel_release_file" ]] || { echo "missing kernel release file: $$kernel_release_file" >&2; exit 1; }; \
		kernel_release="$$(tr -d '\''\n'\'' < "$$kernel_release_file")"; \
		install_root="$$artifact_root/modules-$$kernel_release.root"; \
		boot_artifact="$$artifact_root/boot/bzImage-$$kernel_release"; \
		modules_artifact="$$artifact_root/modules-$$kernel_release.tar.gz"; \
		if [[ -f "$$artifact_root/kernel-release.txt" ]] && [[ "$$(tr -d '\''\n'\'' < "$$artifact_root/kernel-release.txt")" = "$$kernel_release" ]] && [[ -f "$$boot_artifact" ]] && [[ -f "$$modules_artifact" ]] && [[ "$$boot_artifact" -nt "$(X86_BUILD_DIR)/arch/x86/boot/bzImage" ]] && [[ "$$modules_artifact" -nt "$(X86_BUILD_DIR)/modules.order" ]]; then \
			echo "[kernel-artifacts] reuse x86 $$kernel_release"; \
			exit 0; \
		fi; \
		rm -rf "$$artifact_root"; \
		mkdir -p "$$artifact_root/boot"; \
		mkdir -p "$$install_root"; \
		cp "$(X86_BUILD_DIR)/arch/x86/boot/bzImage" "$$boot_artifact"; \
		printf "%s\n" "$$kernel_release" > "$$artifact_root/kernel-release.txt"; \
		$(MAKE) --no-print-directory -C "$(KERNEL_DIR)" O="$(X86_BUILD_DIR)" INSTALL_MOD_PATH="$$install_root" DEPMOD=true CONFIG_MODULE_SIG=n modules_install; \
		rm -f "$$install_root/lib/modules/$$kernel_release/build" "$$install_root/lib/modules/$$kernel_release/source"; \
		tar -C "$$install_root" -czf "$$modules_artifact" lib'

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
$(ARM64_BUILD_CONFIG): $(ARM64_GCC) $(ARM64_GXX) $(ARM64_READELF)
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" "$(PYTHON)" -m runner.libs.arm64_kernel_config local \
		"$(KERNEL_DIR)" "$(ARM64_BUILD_DIR)" "$(ARM64_CROSS_PREFIX)"
	ln -sfn build-arm64/.config "$(ARM64_CONFIG_LINK)"

$(ARM64_IMAGE): $(ARM64_BUILD_CONFIG)
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(KERNEL_DIR)" O="$(ARM64_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(ARM64_CROSS_PREFIX)" Image -j"$(NPROC)"
	ln -sfn ../../../build-arm64/arch/arm64/boot/Image "$(ARM64_IMAGE_LINK)"

$(ARM64_EFI_IMAGE): $(ARM64_BUILD_CONFIG)
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(KERNEL_DIR)" O="$(ARM64_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(ARM64_CROSS_PREFIX)" vmlinuz.efi -j"$(NPROC)"

__kernel-arm64: $(ARM64_IMAGE) $(ARM64_EFI_IMAGE)
	ln -sfn build-arm64/.config "$(ARM64_CONFIG_LINK)"
	ln -sfn ../../../build-arm64/arch/arm64/boot/Image "$(ARM64_IMAGE_LINK)"

$(ARM64_AWS_BUILD_CONFIG): $(ARM64_GCC) $(ARM64_GXX) $(ARM64_READELF)
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" ARM64_BASE_CONFIG="$(ARM64_AWS_BASE_CONFIG)" "$(PYTHON)" -m runner.libs.arm64_kernel_config aws \
		"$(KERNEL_DIR)" "$(ARM64_AWS_BUILD_DIR)" "$(ARM64_CROSS_PREFIX)"

$(ARM64_AWS_IMAGE): $(ARM64_AWS_BUILD_CONFIG)
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(KERNEL_DIR)" O="$(ARM64_AWS_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(ARM64_CROSS_PREFIX)" Image -j"$(NPROC)"

$(ARM64_AWS_EFI_IMAGE): $(ARM64_AWS_BUILD_CONFIG)
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(KERNEL_DIR)" O="$(ARM64_AWS_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(ARM64_CROSS_PREFIX)" vmlinuz.efi -j"$(NPROC)"

__kernel-arm64-aws: $(ARM64_AWS_IMAGE) $(ARM64_AWS_EFI_IMAGE)

__kernel-arm64-aws-artifacts:
	@test -n "$(OUTPUT_ROOT)" || { echo "OUTPUT_ROOT is required" >&2; exit 1; }
	@mkdir -p "$(ARTIFACT_ROOT)"; \
	flock "$(ARM64_AWS_KERNEL_LOCK)" bash -eu -o pipefail -c '\
		artifact_root="$(OUTPUT_ROOT)"; \
		$(MAKE) --no-print-directory __kernel-arm64-aws ARM64_AWS_BUILD_DIR="$(ARM64_AWS_BUILD_DIR)" ARM64_AWS_BASE_CONFIG="$(ARM64_AWS_BASE_CONFIG)"; \
		kernel_release_file="$(ARM64_AWS_BUILD_DIR)/include/config/kernel.release"; \
		[[ -f "$$kernel_release_file" ]] || { echo "missing kernel release file: $$kernel_release_file" >&2; exit 1; }; \
		kernel_release="$$(tr -d '\''\n'\'' < "$$kernel_release_file")"; \
		install_root="$$artifact_root/modules-$$kernel_release.root"; \
		boot_artifact="$$artifact_root/boot/vmlinuz-$$kernel_release.efi"; \
		modules_artifact="$$artifact_root/modules-$$kernel_release.tar.gz"; \
		if [[ -f "$$artifact_root/kernel-release.txt" ]] && [[ "$$(tr -d '\''\n'\'' < "$$artifact_root/kernel-release.txt")" = "$$kernel_release" ]] && [[ -f "$$boot_artifact" ]] && [[ -f "$$modules_artifact" ]] && [[ "$$boot_artifact" -nt "$(ARM64_AWS_BUILD_DIR)/arch/arm64/boot/vmlinuz.efi" ]] && [[ "$$modules_artifact" -nt "$(ARM64_AWS_BUILD_DIR)/modules.order" ]]; then \
			echo "[kernel-artifacts] reuse arm64 $$kernel_release"; \
			exit 0; \
		fi; \
		rm -rf "$$artifact_root"; \
		mkdir -p "$$artifact_root/boot"; \
		mkdir -p "$$install_root"; \
		cp "$(ARM64_AWS_BUILD_DIR)/arch/arm64/boot/vmlinuz.efi" "$$boot_artifact"; \
		printf "%s\n" "$$kernel_release" > "$$artifact_root/kernel-release.txt"; \
		$(MAKE) --no-print-directory -C "$(KERNEL_DIR)" O="$(ARM64_AWS_BUILD_DIR)" ARCH=arm64 CROSS_COMPILE="$(ARM64_CROSS_PREFIX)" INSTALL_MOD_PATH="$$install_root" DEPMOD=true CONFIG_MODULE_SIG=n modules_install; \
		rm -f "$$install_root/lib/modules/$$kernel_release/build" "$$install_root/lib/modules/$$kernel_release/source"; \
		tar -C "$$install_root" -czf "$$modules_artifact" lib'

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

# ── Clean ──────────────────────────────────────────────────────────────────────
clean:
	rm -rf "$(RUNNER_BUILD_DIR)"
	rm -rf "$(RUNNER_DIR)/build-arm64"
	$(MAKE) -C "$(MICRO_DIR)" clean
	cargo clean --manifest-path "$(DAEMON_DIR)/Cargo.toml"
	$(MAKE) -C "$(KERNEL_DIR)" clean
	rm -f "$(ARM64_CONFIG_LINK)" "$(ARM64_IMAGE_LINK)"
	rm -rf "$(ARM64_BUILD_DIR)" "$(ROOT_DIR)/.state/runner-contracts"
	rm -rf \
		"$(ARTIFACT_ROOT)/aws-arm64/kernel-build" \
		"$(ARTIFACT_ROOT)/aws-arm64/setup-artifacts" \
		"$(ARTIFACT_ROOT)/aws-arm64/run-state" \
		"$(ARTIFACT_ROOT)/aws-arm64/runs" \
		"$(ARTIFACT_ROOT)/aws-arm64/state" \
		"$(ARTIFACT_ROOT)/aws-x86/kernel-build" \
		"$(ARTIFACT_ROOT)/aws-x86/setup-artifacts" \
		"$(ARTIFACT_ROOT)/aws-x86/run-state" \
		"$(ARTIFACT_ROOT)/aws-x86/runs" \
		"$(ARTIFACT_ROOT)/aws-x86/state"
