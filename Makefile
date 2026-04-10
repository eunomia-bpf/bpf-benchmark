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
RUNNER_BUILD_DIR ?= $(RUNNER_DIR)/build
AWS_X86_SETUP_ROOT := $(ARTIFACT_ROOT)/aws-x86/setup-artifacts/x86
AWS_X86_SETUP_KERNEL_RELEASE_FILE := $(AWS_X86_SETUP_ROOT)/kernel-release.txt
AWS_X86_SETUP_KERNEL_IMAGE := $(AWS_X86_SETUP_ROOT)/boot/bzImage
AWS_X86_SETUP_MODULES_ARCHIVE := $(AWS_X86_SETUP_ROOT)/modules.tar.gz
AWS_X86_CANONICAL_MODULES_ROOT := $(ARTIFACT_ROOT)/repo-artifacts/x86_64/kernel-modules/lib/modules
AWS_ARM64_SETUP_ROOT := $(ARTIFACT_ROOT)/aws-arm64/setup-artifacts/arm64
AWS_ARM64_SETUP_KERNEL_RELEASE_FILE := $(AWS_ARM64_SETUP_ROOT)/kernel-release.txt
AWS_ARM64_SETUP_KERNEL_IMAGE := $(AWS_ARM64_SETUP_ROOT)/boot/vmlinuz.efi
AWS_ARM64_SETUP_MODULES_ARCHIVE := $(AWS_ARM64_SETUP_ROOT)/modules.tar.gz

include $(RUNNER_DIR)/mk/arm64_defaults.mk
include $(RUNNER_DIR)/mk/build.mk

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
KERNEL_CONFIG_PATH := $(X86_BUILD_DIR)/.config
NPROC        ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
JOBS         ?= $(NPROC)
DEFCONFIG_SRC := $(ROOT_DIR)/vendor/bpfrejit_defconfig
ARM64_KERNEL_CONFIG_SCRIPT := $(RUNNER_DIR)/libs/arm64_kernel_config.py
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

$(AWS_X86_SETUP_KERNEL_RELEASE_FILE) $(AWS_X86_SETUP_KERNEL_IMAGE) $(AWS_X86_SETUP_MODULES_ARCHIVE) &: $(ROOT_DIR)/Makefile $(RUNNER_DIR)/mk/build.mk $(X86_BUILD_DIR)/arch/x86/boot/bzImage $(AWS_X86_CANONICAL_MODULES_ROOT)
	@bash -eu -o pipefail -c '\
		artifact_root="$(AWS_X86_SETUP_ROOT)"; \
		release_file="$(AWS_X86_SETUP_KERNEL_RELEASE_FILE)"; \
		kernel_image="$(AWS_X86_SETUP_KERNEL_IMAGE)"; \
		modules_archive="$(AWS_X86_SETUP_MODULES_ARCHIVE)"; \
		kernel_release_file="$(X86_BUILD_DIR)/include/config/kernel.release"; \
		[[ -f "$$kernel_release_file" ]] || { echo "missing kernel release file: $$kernel_release_file" >&2; exit 1; }; \
		kernel_release="$$(tr -d '\''\n'\'' < "$$kernel_release_file")"; \
		source_modules_root="$(AWS_X86_CANONICAL_MODULES_ROOT)/$$kernel_release"; \
		[[ -d "$$source_modules_root" ]] || { echo "missing canonical x86 modules root: $$source_modules_root" >&2; exit 1; }; \
		install_root="$$(mktemp -d "$$artifact_root/modules.root.XXXXXX")"; \
		trap '\''rm -rf "$$install_root"'\'' EXIT; \
		mkdir -p "$$artifact_root/boot"; \
		ln -f "$(X86_BUILD_DIR)/arch/x86/boot/bzImage" "$$kernel_image"; \
		printf "%s\n" "$$kernel_release" > "$$release_file"; \
		mkdir -p "$$install_root/lib/modules"; \
		cp -a "$$source_modules_root" "$$install_root/lib/modules/"; \
		rm -f "$$install_root/lib/modules/$$kernel_release/build" "$$install_root/lib/modules/$$kernel_release/source"; \
		tar -C "$$install_root" -czf "$$modules_archive" lib; \
		test -f "$$release_file"; \
		test -f "$$kernel_image"; \
		test -f "$$modules_archive"'

$(KERNEL_CONFIG_PATH): $(DEFCONFIG_SRC)
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
$(ARM64_BUILD_CONFIG): $(ARM64_GCC) $(ARM64_GXX) $(ARM64_READELF) $(ARM64_KERNEL_CONFIG_SCRIPT) $(KERNEL_BUILD_META_FILES)
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" "$(PYTHON)" -m runner.libs.arm64_kernel_config local \
		"$(KERNEL_DIR)" "$(ARM64_BUILD_DIR)" "$(ARM64_CROSS_PREFIX)"
	ln -sfn build-arm64/.config "$(ARM64_CONFIG_LINK)"

$(ARM64_IMAGE) $(ARM64_EFI_IMAGE) &: $(ROOT_DIR)/Makefile $(RUNNER_DIR)/mk/build.mk $(ARM64_BUILD_CONFIG) $(KERNEL_BUILD_META_FILES) $(KERNEL_SOURCE_FILES)
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(KERNEL_DIR)" O="$(ARM64_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(ARM64_CROSS_PREFIX)" Image vmlinuz.efi -j"$(NPROC)"
	ln -sfn ../../../build-arm64/arch/arm64/boot/Image "$(ARM64_IMAGE_LINK)"

$(ARM64_AWS_BUILD_CONFIG): $(ROOT_DIR)/Makefile $(RUNNER_DIR)/mk/build.mk $(ARM64_GCC) $(ARM64_GXX) $(ARM64_READELF) $(ARM64_KERNEL_CONFIG_SCRIPT) $(ARM64_AWS_BASE_CONFIG) $(KERNEL_BUILD_META_FILES)
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" ARM64_BASE_CONFIG="$(ARM64_AWS_BASE_CONFIG)" "$(PYTHON)" -m runner.libs.arm64_kernel_config aws \
		"$(KERNEL_DIR)" "$(ARM64_AWS_BUILD_DIR)" "$(ARM64_CROSS_PREFIX)"

$(ARM64_AWS_IMAGE) $(ARM64_AWS_EFI_IMAGE) &: $(ROOT_DIR)/Makefile $(RUNNER_DIR)/mk/build.mk $(ARM64_AWS_BUILD_CONFIG) $(KERNEL_BUILD_META_FILES) $(KERNEL_SOURCE_FILES)
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(KERNEL_DIR)" O="$(ARM64_AWS_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(ARM64_CROSS_PREFIX)" Image vmlinuz.efi -j"$(NPROC)"

$(AWS_ARM64_SETUP_KERNEL_RELEASE_FILE) $(AWS_ARM64_SETUP_KERNEL_IMAGE) $(AWS_ARM64_SETUP_MODULES_ARCHIVE) &: $(ROOT_DIR)/Makefile $(RUNNER_DIR)/mk/build.mk $(ARM64_AWS_IMAGE) $(ARM64_AWS_EFI_IMAGE)
	@bash -eu -o pipefail -c '\
		artifact_root="$(AWS_ARM64_SETUP_ROOT)"; \
		release_file="$(AWS_ARM64_SETUP_KERNEL_RELEASE_FILE)"; \
		kernel_image="$(AWS_ARM64_SETUP_KERNEL_IMAGE)"; \
		modules_archive="$(AWS_ARM64_SETUP_MODULES_ARCHIVE)"; \
		kernel_release_file="$(ARM64_AWS_BUILD_DIR)/include/config/kernel.release"; \
		[[ -f "$$kernel_release_file" ]] || { echo "missing kernel release file: $$kernel_release_file" >&2; exit 1; }; \
		kernel_release="$$(tr -d '\''\n'\'' < "$$kernel_release_file")"; \
		install_root="$$(mktemp -d "$$artifact_root/modules.root.XXXXXX")"; \
		trap '\''rm -rf "$$install_root"'\'' EXIT; \
		mkdir -p "$$artifact_root/boot"; \
		ln -f "$(ARM64_AWS_BUILD_DIR)/arch/arm64/boot/vmlinuz.efi" "$$kernel_image"; \
		printf "%s\n" "$$kernel_release" > "$$release_file"; \
		$(MAKE) --no-print-directory -C "$(KERNEL_DIR)" O="$(ARM64_AWS_BUILD_DIR)" ARCH=arm64 CROSS_COMPILE="$(ARM64_CROSS_PREFIX)" INSTALL_MOD_PATH="$$install_root" DEPMOD=true CONFIG_MODULE_SIG=n modules_install; \
		depmod -b "$$install_root" "$$kernel_release"; \
		rm -f "$$install_root/lib/modules/$$kernel_release/build" "$$install_root/lib/modules/$$kernel_release/source"; \
		tar -C "$$install_root" -czf "$$modules_archive" lib; \
		test -f "$$release_file"; \
		test -f "$$kernel_image"; \
		test -f "$$modules_archive"'

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
