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
UPSTREAM_SELFTEST_DIR := $(KERNEL_DIR)/tools/testing/selftests/bpf
KINSN_MODULE_DIR := $(ROOT_DIR)/module/x86
CACHE_DIR := $(ROOT_DIR)/.cache
UPSTREAM_SELFTEST_OUTPUT_DIR := $(CACHE_DIR)/upstream-bpf-selftests
KINSN_MODULE_OUTPUT_DIR ?=
UPSTREAM_SELFTEST_LLVM_SUFFIX ?= -20
UPSTREAM_SELFTEST_CLANG ?= clang$(UPSTREAM_SELFTEST_LLVM_SUFFIX)
UPSTREAM_SELFTEST_LLC ?= llc$(UPSTREAM_SELFTEST_LLVM_SUFFIX)
UPSTREAM_SELFTEST_LLVM_CONFIG ?= llvm-config$(UPSTREAM_SELFTEST_LLVM_SUFFIX)
UPSTREAM_SELFTEST_LLVM_OBJCOPY ?= llvm-objcopy$(UPSTREAM_SELFTEST_LLVM_SUFFIX)
UPSTREAM_SELFTEST_LLVM_STRIP ?= llvm-strip$(UPSTREAM_SELFTEST_LLVM_SUFFIX)
LLVM_CONFIG ?= $(UPSTREAM_SELFTEST_LLVM_CONFIG)

include $(RUNNER_DIR)/mk/arm64_defaults.mk

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

export CROSS_COMPILE_ARM64 ARM64_BUILD_DIR ARM64_WORKTREE_DIR
export ARM64_DOCKER_PLATFORM ARM64_CROSSBUILD_JOBS
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

.PHONY: __kernel __kernel-clean __kernel-rebuild __kernel-arm64 __kinsn-modules \
		check validate \
		vm-selftest vm-negative-test vm-test vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all \
		__arm64-worktree \
		__kernel-arm64-aws \
	__native-repo-build \
		__scx-build \
		__bundle-cache \
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
	"$(PYTHON)" -m runner.libs.x86_kernel_artifacts ensure-kvm-kernel \
		--kernel-dir "$(KERNEL_DIR)" \
		--defconfig "$(DEFCONFIG_SRC)" \
		--bzimage "$(BZIMAGE_PATH)" \
		--jobs "$(JOBS)"

__kernel-clean:
	$(MAKE) -C "$(KERNEL_DIR)" clean

__kernel-rebuild: __kernel-clean
	$(MAKE) __kernel BZIMAGE="$(BZIMAGE)"

__kinsn-modules: __kernel
	@if [ -z "$(KINSN_MODULE_OUTPUT_DIR)" ]; then \
		echo "KINSN_MODULE_OUTPUT_DIR is required" >&2; \
		exit 1; \
	fi
	"$(PYTHON)" -m runner.libs.x86_kernel_artifacts stage-kinsn \
		--kernel-dir "$(KERNEL_DIR)" \
		--module-dir "$(KINSN_MODULE_DIR)" \
		--output-dir "$(KINSN_MODULE_OUTPUT_DIR)"

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
__arm64-worktree:
	@mkdir -p "$(dir $(ARM64_WORKTREE_DIR))"
	@git -C "$(KERNEL_DIR)" worktree prune
	@if [ ! -e "$(ARM64_WORKTREE_DIR)/.git" ]; then \
		git -C "$(KERNEL_DIR)" worktree add --detach "$(ARM64_WORKTREE_DIR)" "$$(git -C "$(KERNEL_DIR)" rev-parse HEAD)"; \
	else \
		git -C "$(ARM64_WORKTREE_DIR)" checkout --detach "$$(git -C "$(KERNEL_DIR)" rev-parse HEAD)" >/dev/null; \
	fi

$(ARM64_BUILD_CONFIG): | __arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" "$(PYTHON)" -m runner.libs.arm64_kernel_config local \
		"$(ARM64_WORKTREE_DIR)" "$(ARM64_BUILD_DIR)" "$(CROSS_COMPILE_ARM64)"
	ln -sfn build-arm64/.config "$(ARM64_CONFIG_LINK)"

$(ARM64_IMAGE): $(ARM64_BUILD_CONFIG) | __arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(ARM64_WORKTREE_DIR)" O="$(ARM64_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" Image -j"$(NPROC)"
	ln -sfn ../../../build-arm64/arch/arm64/boot/Image "$(ARM64_IMAGE_LINK)"

$(ARM64_EFI_IMAGE): $(ARM64_BUILD_CONFIG) | __arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(ARM64_WORKTREE_DIR)" O="$(ARM64_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" vmlinuz.efi -j"$(NPROC)"

__kernel-arm64: $(ARM64_IMAGE) $(ARM64_EFI_IMAGE)
	ln -sfn build-arm64/.config "$(ARM64_CONFIG_LINK)"
	ln -sfn ../../../build-arm64/arch/arm64/boot/Image "$(ARM64_IMAGE_LINK)"

$(ARM64_AWS_BUILD_CONFIG): | __arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" ARM64_BASE_CONFIG="$(ARM64_AWS_BASE_CONFIG)" "$(PYTHON)" -m runner.libs.arm64_kernel_config aws \
		"$(ARM64_WORKTREE_DIR)" "$(ARM64_AWS_BUILD_DIR)" "$(CROSS_COMPILE_ARM64)"

$(ARM64_AWS_IMAGE): $(ARM64_AWS_BUILD_CONFIG) | __arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(ARM64_WORKTREE_DIR)" O="$(ARM64_AWS_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" Image -j"$(NPROC)"

$(ARM64_AWS_EFI_IMAGE): $(ARM64_AWS_BUILD_CONFIG) | __arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(ARM64_WORKTREE_DIR)" O="$(ARM64_AWS_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" vmlinuz.efi -j"$(NPROC)"

__kernel-arm64-aws: $(ARM64_AWS_IMAGE) $(ARM64_AWS_EFI_IMAGE)

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

# ── Native Repo Build ──────────────────────────────────────────────────────────
__native-repo-build:
	@test -n "$(NATIVE_REPO_ROOT)" || { echo "NATIVE_REPO_ROOT is required" >&2; exit 1; }
	@test -n "$(NATIVE_BUILD_ROOT)" || { echo "NATIVE_BUILD_ROOT is required" >&2; exit 1; }
	@test -n "$(NATIVE_STAGE_ROOT)" || { echo "NATIVE_STAGE_ROOT is required" >&2; exit 1; }
	@repo_args=(); \
	if [ -n "$(NATIVE_REPOS_CSV)" ]; then \
		IFS=, read -r -a repos <<< "$(NATIVE_REPOS_CSV)"; \
		for repo in "$${repos[@]}"; do \
			[ -n "$$repo" ] || continue; \
			repo_args+=(--repo "$$repo"); \
		done; \
	fi; \
	vmlinux_args=(); \
	if [ -n "$(NATIVE_VMLINUX_BTF)" ]; then \
		vmlinux_args+=(--vmlinux-btf "$(NATIVE_VMLINUX_BTF)"); \
	fi; \
	"$(PYTHON)" "$(ROOT_DIR)/runner/scripts/build_corpus_native.py" \
		--jobs "$(JOBS)" \
		--repo-root "$(NATIVE_REPO_ROOT)" \
		--build-root "$(NATIVE_BUILD_ROOT)" \
		--stage-root "$(NATIVE_STAGE_ROOT)" \
		"$${vmlinux_args[@]}" \
		"$${repo_args[@]}"

# ── SCX Build ──────────────────────────────────────────────────────────────────
__scx-build:
	@test -n "$(SCX_REPO_ROOT)" || { echo "SCX_REPO_ROOT is required" >&2; exit 1; }
	@test -n "$(SCX_PROMOTE_ROOT)" || { echo "SCX_PROMOTE_ROOT is required" >&2; exit 1; }
	@package_args=(); \
	if [ -n "$(SCX_PACKAGES_CSV)" ]; then \
		IFS=, read -r -a packages <<< "$(SCX_PACKAGES_CSV)"; \
		for package in "$${packages[@]}"; do \
			[ -n "$$package" ] || continue; \
			package_args+=(--package "$$package"); \
		done; \
	fi; \
	target_args=(); \
	if [ -n "$(SCX_TARGET_TRIPLE)" ]; then \
		target_args+=(--target-triple "$(SCX_TARGET_TRIPLE)"); \
	fi; \
	"$(PYTHON)" "$(ROOT_DIR)/runner/scripts/build_scx_artifacts.py" \
		--force \
		--jobs "$(JOBS)" \
		--repo-root "$(SCX_REPO_ROOT)" \
		--promote-root "$(SCX_PROMOTE_ROOT)" \
		"$${target_args[@]}" \
		"$${package_args[@]}"

# ── Upstream Selftests Build ───────────────────────────────────────────────────
__upstream-selftests:
	@test -n "$(UPSTREAM_SELFTEST_SOURCE_DIR)" || { echo "UPSTREAM_SELFTEST_SOURCE_DIR is required" >&2; exit 1; }
	@test -n "$(UPSTREAM_SELFTEST_OUTPUT_DIR)" || { echo "UPSTREAM_SELFTEST_OUTPUT_DIR is required" >&2; exit 1; }
	@test -n "$(UPSTREAM_SELFTEST_HOST_PYTHON_BIN)" || { echo "UPSTREAM_SELFTEST_HOST_PYTHON_BIN is required" >&2; exit 1; }
	@test -n "$(VMLINUX_BTF)" || { echo "VMLINUX_BTF is required" >&2; exit 1; }
	@"$(PYTHON)" -m runner.libs.build_upstream_selftests

# ── ARM64 Container Build ──────────────────────────────────────────────────────
__arm64-container-build:
	@test -n "$(ARM64_DOCKER_PLATFORM)" || { echo "ARM64_DOCKER_PLATFORM is required" >&2; exit 1; }
	@test -n "$(ARM64_CROSSBUILD_DOCKERFILE)" || { echo "ARM64_CROSSBUILD_DOCKERFILE is required" >&2; exit 1; }
	@test -n "$(ARM64_CROSSBUILD_CONTEXT)" || { echo "ARM64_CROSSBUILD_CONTEXT is required" >&2; exit 1; }
	@test -n "$(ARM64_CROSSBUILD_IMAGE)" || { echo "ARM64_CROSSBUILD_IMAGE is required" >&2; exit 1; }
	@test -n "$(ARM64_CROSSBUILD_STAMP)" || { echo "ARM64_CROSSBUILD_STAMP is required" >&2; exit 1; }
	@test -n "$(ARM64_CROSSBUILD_LOCK)" || { echo "ARM64_CROSSBUILD_LOCK is required" >&2; exit 1; }
	@test -n "$(ARM64_CROSSBUILD_OUTPUT_DIR)" || { echo "ARM64_CROSSBUILD_OUTPUT_DIR is required" >&2; exit 1; }
	@test -n "$(ARM64_CROSSBUILD_BUILD_ROOT)" || { echo "ARM64_CROSSBUILD_BUILD_ROOT is required" >&2; exit 1; }
	@test -n "$(ARM64_SOURCE_REPO_ROOT)" || { echo "ARM64_SOURCE_REPO_ROOT is required" >&2; exit 1; }
	@test -n "$(ARM64_HOST_PYTHON_BIN)" || { echo "ARM64_HOST_PYTHON_BIN is required" >&2; exit 1; }
	@stamp_path="$(ARM64_CROSSBUILD_STAMP)"; \
	lock_path="$(ARM64_CROSSBUILD_LOCK)"; \
	dockerfile_path="$(ARM64_CROSSBUILD_DOCKERFILE)"; \
	mkdir -p "$$(dirname "$$stamp_path")" "$$(dirname "$$lock_path")"; \
	flock "$$lock_path" bash -eu -o pipefail -c '\
		stamp_path="$$1"; \
		dockerfile_path="$$2"; \
		image="$$3"; \
		platform="$$4"; \
		context_dir="$$5"; \
		if [ -f "$$stamp_path" ] && [ "$$stamp_path" -nt "$$dockerfile_path" ]; then \
			exit 0; \
		fi; \
		docker buildx build --load --platform "$$platform" -f "$$dockerfile_path" -t "$$image" "$$context_dir"; \
		touch "$$stamp_path"; \
	' _ "$$stamp_path" "$$dockerfile_path" "$(ARM64_CROSSBUILD_IMAGE)" "$(ARM64_DOCKER_PLATFORM)" "$(ARM64_CROSSBUILD_CONTEXT)"; \
	docker run --rm --platform "$(ARM64_DOCKER_PLATFORM)" \
		-v "$(ROOT_DIR):/workspace" \
		-w /workspace \
		-e HOME=/tmp/codex \
		-e CARGO_HOME="$(ARM64_CROSSBUILD_CARGO_HOME)" \
		-e HOST_UID="$(HOST_UID)" \
		-e HOST_GID="$(HOST_GID)" \
		-e ARM64_SOURCE_REPO_ROOT="$(ARM64_SOURCE_REPO_ROOT)" \
		-e ARM64_CROSSBUILD_OUTPUT_DIR="$(ARM64_CROSSBUILD_OUTPUT_DIR)" \
		-e ARM64_CROSSBUILD_BUILD_ROOT="$(ARM64_CROSSBUILD_BUILD_ROOT)" \
		-e ARM64_BENCH_REPO_ROOT="$(ARM64_BENCH_REPO_ROOT)" \
		-e ARM64_NATIVE_REPO_BUILD_ROOT="$(ARM64_NATIVE_REPO_BUILD_ROOT)" \
		-e ARM64_KATRAN_GETDEPS_ROOT="$(ARM64_KATRAN_GETDEPS_ROOT)" \
		-e ARM64_KATRAN_GETDEPS_LOCK="$(ARM64_KATRAN_GETDEPS_LOCK)" \
		-e ARM64_VENDOR_BPFTOOL_ROOT="$(ARM64_VENDOR_BPFTOOL_ROOT)" \
		-e ARM64_VENDOR_BPFTOOL_LOCK="$(ARM64_VENDOR_BPFTOOL_LOCK)" \
		-e ARM64_CROSSBUILD_JOBS="$(ARM64_CROSSBUILD_JOBS)" \
		-e ARM64_CROSSBUILD_RUNTIME_TARGETS="$(ARM64_CROSSBUILD_RUNTIME_TARGETS)" \
		-e MICRO_EXEC_ENABLE_LLVMBPF="$(MICRO_EXEC_ENABLE_LLVMBPF)" \
		-e ARM64_PREBUILT_DAEMON_BINARY="$(ARM64_PREBUILT_DAEMON_BINARY)" \
		-e ARM64_HOST_PYTHON_BIN=python3 \
		-e ARM64_CROSSBUILD_BENCH_REPOS="$(ARM64_CROSSBUILD_BENCH_REPOS)" \
		-e ARM64_CROSSBUILD_ONLY_BENCH="$(ARM64_CROSSBUILD_ONLY_BENCH)" \
		"$(ARM64_CROSSBUILD_IMAGE)" \
		python3 -m runner.libs.arm64_container_build

# ── ARM64 Host Build ───────────────────────────────────────────────────────────
__arm64-host-build:
	@test -n "$(ARM64_HOST_BUILD_MODE)" || { echo "ARM64_HOST_BUILD_MODE is required" >&2; exit 1; }
	@"$(PYTHON)" -m runner.libs.arm64_host_build "$(ARM64_HOST_BUILD_MODE)"

# ── Bundle Cache ───────────────────────────────────────────────────────────────
__bundle-cache:
	@test -n "$(BUNDLE_MANIFEST_PATH)" || { echo "BUNDLE_MANIFEST_PATH is required" >&2; exit 1; }
	@test -n "$(BUNDLE_INPUTS_PATH)" || { echo "BUNDLE_INPUTS_PATH is required" >&2; exit 1; }
	@test -n "$(BUNDLE_CACHE_DIR)" || { echo "BUNDLE_CACHE_DIR is required" >&2; exit 1; }
	@cache_dir="$(BUNDLE_CACHE_DIR)"; \
	cache_root="$$(dirname "$$cache_dir")"; \
	lock_dir="$$cache_root/.locks"; \
	cache_key="$$(basename "$$cache_dir")"; \
	lock_file="$$lock_dir/$$cache_key.lock"; \
	mkdir -p "$$lock_dir" "$$cache_root"; \
	flock "$$lock_file" bash -eu -o pipefail -c '\
		cache_dir="$$1"; \
		manifest_path="$$2"; \
		bundle_inputs_path="$$3"; \
		python_bin="$$4"; \
		if [ -f "$$cache_dir/bundle.tar.gz" ] && tar -tzf "$$cache_dir/bundle.tar.gz" >/dev/null 2>&1; then \
			exit 0; \
		fi; \
		rm -rf "$$cache_dir"; \
		tmp_dir="$${cache_dir}.tmp.$$PPID"; \
		rm -rf "$$tmp_dir"; \
		mkdir -p "$$tmp_dir"; \
		"$$python_bin" -m runner.libs.build_remote_bundle "$$manifest_path" "$$bundle_inputs_path" "$$tmp_dir/workspace" "$$tmp_dir/bundle.tar.gz"; \
		rm -rf "$$tmp_dir/workspace"; \
		mv "$$tmp_dir" "$$cache_dir"; \
	' _ "$$cache_dir" "$(BUNDLE_MANIFEST_PATH)" "$(BUNDLE_INPUTS_PATH)" "$(PYTHON)"

# ── Clean ──────────────────────────────────────────────────────────────────────
clean:
	rm -rf "$(RUNNER_DIR)/build"
	$(MAKE) -C "$(MICRO_DIR)" clean
	cargo clean --manifest-path "$(DAEMON_DIR)/Cargo.toml"
	$(MAKE) -C "$(KERNEL_DIR)" clean
	rm -f "$(ARM64_CONFIG_LINK)" "$(ARM64_IMAGE_LINK)"
	rm -rf "$(ARM64_BUILD_DIR)" "$(UPSTREAM_SELFTEST_OUTPUT_DIR)" "$(CACHE_DIR)/arm64-host"
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
