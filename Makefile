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
DAEMON  ?= daemon/target/release/bpfrejit-daemon
DAEMON_ARGS ?=
DAEMON_SOCKET ?= /tmp/bpfrejit.sock
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
PYTHON_STATIC_TESTS := \
	tests/python/test_run_contract.py \
	tests/python/test_prepare_local_inputs.py \
	tests/python/test_run_target_suite.py \
	tests/python/test_build_remote_bundle.py \
	tests/python/test_build_upstream_selftests.py \
	tests/python/test_execute_workspace.py \
	tests/python/test_state_file.py

# Derived
BZIMAGE_PATH := $(if $(filter /%,$(BZIMAGE)),$(BZIMAGE),$(ROOT_DIR)/$(BZIMAGE))
KERNEL_SYMVERS_PATH := $(KERNEL_DIR)/Module.symvers
KERNEL_CONFIG_PATH := $(KERNEL_DIR)/.config
KERNEL_CONFIG_STAMP := $(KERNEL_DIR)/.bpfrejit_config.stamp
KERNEL_BUILD_STAMP := $(KERNEL_DIR)/.bpfrejit_kernel_build.stamp
KERNEL_BUILD_LOCK := $(CACHE_DIR)/kernel-build.lock
NPROC        ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
JOBS         ?= $(NPROC)
DEFCONFIG_SRC := $(ROOT_DIR)/vendor/bpfrejit_defconfig
arm64_container_path = $(patsubst $(ROOT_DIR)%,/workspace%,$(1))

# Results
MICRO_RESULTS_DIR      := $(ROOT_DIR)/micro/results
SMOKE_OUTPUT           := $(MICRO_RESULTS_DIR)/smoke.json

# Python / venv
_VENV_CANDIDATES := $(HOME)/workspace/.venv $(HOME)/.venv .venv venv
_VENV_FOUND := $(firstword $(foreach v,$(_VENV_CANDIDATES),$(if $(wildcard $(v)/bin/activate),$(v),)))
VENV ?= $(_VENV_FOUND)
PYTHON := $(if $(VENV),$(VENV)/bin/python3,python3)
export BZIMAGE PYTHON
export VM_TEST_TIMEOUT VM_MICRO_TIMEOUT VM_CORPUS_TIMEOUT VM_E2E_TIMEOUT
export FUZZ_ROUNDS SCX_PROG_SHOW_RACE_MODE SCX_PROG_SHOW_RACE_ITERATIONS SCX_PROG_SHOW_RACE_LOAD_TIMEOUT SCX_PROG_SHOW_RACE_SKIP_PROBE
VENV_ACTIVATE := $(if $(VENV),source "$(VENV)/bin/activate" &&,)

# Benchmark args
LOCAL_SMOKE_ARGS := --bench simple --samples 1 --warmups 0 --inner-repeat 10
ROOT_VM_CORPUS_SAMPLES_IS_EXPLICIT := $(or $(findstring command line,$(origin SAMPLES)),$(findstring environment,$(origin SAMPLES)),$(findstring override,$(origin SAMPLES)))
ROOT_VM_CORPUS_SAMPLES_VALUE := $(if $(strip $(ROOT_VM_CORPUS_SAMPLES_IS_EXPLICIT)),$(SAMPLES),$(VM_CORPUS_SAMPLES))
ROOT_VM_CORPUS_SAMPLES_ARG := SAMPLES="$(ROOT_VM_CORPUS_SAMPLES_VALUE)"
ROOT_VM_CORPUS_FILTERS_ARG := $(if $(strip $(FILTERS)),FILTERS="$(FILTERS)",)
ROOT_VM_CORPUS_WORKLOAD_SECONDS_ARG := $(if $(strip $(VM_CORPUS_WORKLOAD_SECONDS)),VM_CORPUS_WORKLOAD_SECONDS="$(VM_CORPUS_WORKLOAD_SECONDS)",)
ROOT_VM_CORPUS_EXTRA_ARGS := $(if $(strip $(VM_CORPUS_ARGS)),VM_CORPUS_ARGS='$(VM_CORPUS_ARGS)',)

VIRTME_HOSTFS_MODULES := \
	drivers/block/null_blk/null_blk.ko \
	drivers/net/veth.ko \
	net/ipv4/ip_tunnel.ko \
	net/ipv4/tunnel4.ko \
	net/ipv4/ipip.ko \
	net/sched/sch_netem.ko \
	fs/netfs/netfs.ko \
	net/9p/9pnet.ko \
	net/9p/9pnet_virtio.ko \
	fs/9p/9p.ko \
	fs/fuse/virtiofs.ko \
	fs/overlayfs/overlay.ko
VIRTME_HOSTFS_MODULE_ORDER := \
	drivers/block/null_blk/null_blk.o \
	drivers/net/veth.o \
	net/ipv4/ip_tunnel.o \
	net/ipv4/tunnel4.o \
	net/ipv4/ipip.o \
	net/sched/sch_netem.o \
	fs/netfs/netfs.o \
	net/9p/9pnet.o \
	net/9p/9pnet_virtio.o \
	fs/9p/9p.o \
	fs/fuse/virtiofs.o \
	fs/overlayfs/overlay.o
.PHONY: __kernel __kernel-build __kernel-clean __kernel-rebuild __kernel-arm64 __kinsn-modules __virtme-hostfs-modules \
		check validate \
		vm-selftest vm-negative-test vm-test vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all \
		__arm64-worktree \
		__kernel-arm64-aws \
		aws-arm64-test aws-arm64-benchmark aws-arm64-terminate aws-arm64 \
		aws-x86-test aws-x86-benchmark aws-x86-terminate aws-x86 \
		__kernel-config-locked __kernel-build-locked \
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

__kernel: __kernel-build
	@test -f "$(BZIMAGE_PATH)"

__kernel-clean:
	$(MAKE) -C "$(KERNEL_DIR)" clean
	rm -f "$(KERNEL_CONFIG_STAMP)"
	rm -f "$(KERNEL_BUILD_STAMP)"

__kernel-rebuild: __kernel-clean
	$(MAKE) __kernel BZIMAGE="$(BZIMAGE)"

__kinsn-modules: __kernel-build
	$(MAKE) -C "$(KINSN_MODULE_DIR)" KDIR="$(KERNEL_DIR)" clean
	$(MAKE) -C "$(KINSN_MODULE_DIR)" KDIR="$(KERNEL_DIR)"
	@if [ -n "$(KINSN_MODULE_OUTPUT_DIR)" ]; then \
		rm -rf "$(KINSN_MODULE_OUTPUT_DIR)"; \
		mkdir -p "$(KINSN_MODULE_OUTPUT_DIR)"; \
		find "$(KINSN_MODULE_DIR)" -maxdepth 1 -type f -name '*.ko' -exec cp '{}' "$(KINSN_MODULE_OUTPUT_DIR)/" \;; \
		count="$$(find "$(KINSN_MODULE_OUTPUT_DIR)" -maxdepth 1 -type f -name '*.ko' | wc -l | tr -d ' ')"; \
		test "$$count" -gt 0 || { \
			echo "no kinsn modules staged under $(KINSN_MODULE_OUTPUT_DIR)" >&2; \
			exit 1; \
		}; \
	fi

__virtme-hostfs-modules: __kernel-build
	@:

$(KERNEL_CONFIG_PATH):
	cp "$(DEFCONFIG_SRC)" "$@"

__kernel-config-locked:
	@if ! diff -q "$(DEFCONFIG_SRC)" "$(KERNEL_CONFIG_PATH)" >/dev/null 2>&1; then \
		cp "$(DEFCONFIG_SRC)" "$(KERNEL_CONFIG_PATH)"; \
	fi
	"$(KERNEL_DIR)/scripts/config" --file "$(KERNEL_CONFIG_PATH)" \
		--enable UNWINDER_ORC \
		--disable UNWINDER_FRAME_POINTER \
		--set-str SYSTEM_TRUSTED_KEYS "" \
		--set-str SYSTEM_REVOCATION_KEYS ""
	$(MAKE) -C "$(KERNEL_DIR)" olddefconfig
	touch "$(KERNEL_CONFIG_STAMP)"

__kernel-build:
	@mkdir -p "$(dir $(KERNEL_BUILD_LOCK))"
	flock "$(KERNEL_BUILD_LOCK)" $(MAKE) __kernel-build-locked

__kernel-build-locked:
	$(MAKE) __kernel-config-locked
	# Let kbuild decide what is stale. Skipping here can leave the guest
	# booting an older bzImage while hostfs modules are rebuilt for the
	# current tree, which breaks Katran's veth/ipip module loading path.
	$(MAKE) -C "$(KERNEL_DIR)" -j"$(JOBS)" bzImage modules_prepare
	@if [ -f "$(KERNEL_DIR)/vmlinux.symvers" ]; then \
		cp "$(KERNEL_DIR)/vmlinux.symvers" "$(KERNEL_SYMVERS_PATH)"; \
		fi
	@test -f "$(KERNEL_SYMVERS_PATH)"
	@touch "$(KERNEL_SYMVERS_PATH)"
	# Parallel sub-makes here occasionally race on generated kernel headers.
	$(MAKE) -j1 -C "$(KERNEL_DIR)" $(VIRTME_HOSTFS_MODULES)
	@for module in $(VIRTME_HOSTFS_MODULES); do \
		test -f "$(KERNEL_DIR)/$$module" || { \
			echo "missing built hostfs module: $(KERNEL_DIR)/$$module" >&2; \
			exit 1; \
		}; \
	done
	@printf '%s\n' $(VIRTME_HOSTFS_MODULE_ORDER) > "$(KERNEL_DIR)/modules.order"
	@kernel_release="$$(cat "$(KERNEL_DIR)/include/config/kernel.release")"; \
		test -n "$$kernel_release" || { \
			echo "kernel release file is empty: $(KERNEL_DIR)/include/config/kernel.release" >&2; \
			exit 1; \
		}; \
		stage_dir="$(KERNEL_DIR)/.virtme_mods"; \
		modules_root="$$stage_dir/lib/modules/$$kernel_release"; \
		fresh=1; \
		test -f "$$modules_root/modules.dep" || fresh=0; \
		if [ "$$fresh" -eq 1 ]; then \
			for module in $(VIRTME_HOSTFS_MODULES); do \
				installed_path="$$modules_root/kernel/$$module"; \
				source_path="$(KERNEL_DIR)/$$module"; \
				if [ ! -f "$$installed_path" ] || [ "$$installed_path" -ot "$$source_path" ]; then \
					fresh=0; \
					break; \
				fi; \
			done; \
		fi; \
		if [ "$$fresh" -eq 0 ]; then \
			tmp_stage="$(KERNEL_DIR)/.virtme_mods.tmp"; \
			prev_stage="$(KERNEL_DIR)/.virtme_mods.prev"; \
			rm -rf "$$tmp_stage" "$$prev_stage"; \
			mkdir -p "$$tmp_stage"; \
			$(MAKE) -C "$(KERNEL_DIR)" INSTALL_MOD_PATH="$$tmp_stage" modules_install >/dev/null; \
			rm -f "$$tmp_stage/lib/modules/$$kernel_release/build" \
			      "$$tmp_stage/lib/modules/$$kernel_release/source"; \
			for module in $(VIRTME_HOSTFS_MODULES); do \
				installed_path="$$tmp_stage/lib/modules/$$kernel_release/kernel/$$module"; \
				test -f "$$installed_path" || { \
					echo "missing installed hostfs module: $$installed_path" >&2; \
					exit 1; \
				}; \
			done; \
			if [ -e "$$stage_dir" ]; then \
				mv "$$stage_dir" "$$prev_stage"; \
			fi; \
			mv "$$tmp_stage" "$$stage_dir"; \
			rm -rf "$$prev_stage"; \
		fi
	@touch "$(KERNEL_BUILD_STAMP)"

check:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" \
		MICRO_PROGRAM_OUTPUT_DIR="$(MICRO_DIR)/programs" \
		micro_exec micro-programs
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" DAEMON_TARGET_DIR="$(DAEMON_DIR)/target" daemon-binary
	$(MAKE) -C "$(RUNNER_DIR)" daemon-tests
	$(PYTHON) -m pytest $(PYTHON_STATIC_TESTS) -v
	mkdir -p "$(MICRO_RESULTS_DIR)"
	$(VENV_ACTIVATE) "$(PYTHON)" "$(MICRO_DIR)/driver.py" --runtime llvmbpf $(LOCAL_SMOKE_ARGS) --output "$(SMOKE_OUTPUT)"

validate:
	$(MAKE) check
	$(MAKE) vm-test
	$(MAKE) vm-micro-smoke

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

$(ARM64_BUILD_CONFIG): $(ROOT_DIR)/runner/scripts/arm64-kernel-config.sh | __arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" "$(ROOT_DIR)/runner/scripts/arm64-kernel-config.sh" \
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

$(ARM64_AWS_BUILD_CONFIG): $(ROOT_DIR)/runner/scripts/aws_arm64_kernel_config.sh | __arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" ARM64_BASE_CONFIG="$(ARM64_AWS_BASE_CONFIG)" "$(ROOT_DIR)/runner/scripts/aws_arm64_kernel_config.sh" \
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

# ── Clean ──────────────────────────────────────────────────────────────────────
clean:
	$(MAKE) -C "$(RUNNER_DIR)" clean
	$(MAKE) -C "$(MICRO_DIR)" clean
	cargo clean --manifest-path "$(DAEMON_DIR)/Cargo.toml"
	$(MAKE) -C "$(KERNEL_DIR)" clean
	rm -f "$(SMOKE_OUTPUT)" "$(ARM64_CONFIG_LINK)" "$(ARM64_IMAGE_LINK)"
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
