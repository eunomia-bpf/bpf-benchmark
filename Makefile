SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

$(if $(wildcard vendor/linux-framework/Makefile),,$(error vendor/linux-framework not found. Run: git submodule update --init --recursive))

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
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

# ARM64 / AWS
ARM64_WORKTREE_DIR  ?= $(ROOT_DIR)/.worktrees/linux-framework-arm64-src
ARM64_BUILD_DIR     ?= $(KERNEL_DIR)/build-arm64
ARM64_BUILD_CONFIG  := $(ARM64_BUILD_DIR)/.config
ARM64_IMAGE         := $(ARM64_BUILD_DIR)/arch/arm64/boot/Image
ARM64_EFI_IMAGE     := $(ARM64_BUILD_DIR)/arch/arm64/boot/vmlinuz.efi
ARM64_IMAGE_LINK    := $(KERNEL_DIR)/arch/arm64/boot/Image
ARM64_CONFIG_LINK   := $(KERNEL_DIR)/.config.arm64
ARM64_AWS_BUILD_DIR ?= $(CACHE_DIR)/aws-arm64/kernel-build
ARM64_AWS_BUILD_CONFIG := $(ARM64_AWS_BUILD_DIR)/.config
ARM64_AWS_IMAGE     := $(ARM64_AWS_BUILD_DIR)/arch/arm64/boot/Image
ARM64_AWS_EFI_IMAGE := $(ARM64_AWS_BUILD_DIR)/arch/arm64/boot/vmlinuz.efi
ARM64_AWS_BASE_CONFIG ?=
CROSS_COMPILE_ARM64 ?= aarch64-linux-gnu-
DOCKER              ?= docker
ARM64_CROSSBUILD_DOCKERFILE := $(ROOT_DIR)/runner/docker/arm64-crossbuild.Dockerfile
ARM64_CROSSBUILD_CONTEXT    := $(ROOT_DIR)/runner/docker
ARM64_CROSSBUILD_IMAGE      ?= bpf-benchmark-arm64-crossbuild:latest
ARM64_CROSSBUILD_STAMP      := $(ROOT_DIR)/.cache/arm64-crossbuild-image.stamp
ARM64_CROSSBUILD_LOCK       := $(ROOT_DIR)/.cache/arm64-crossbuild-image.lock
ARM64_DOCKER_PLATFORM       ?= linux/arm64
ARM64_CROSSBUILD_ENABLE_LLVMBPF ?= OFF
ARM64_CROSSBUILD_JOBS       ?= 4
ARM64_KERNEL_MAKEFLAGS      := $(filter-out B,$(MAKEFLAGS))
RUN_TARGET_SUITE_SCRIPT  := $(ROOT_DIR)/runner/scripts/run_target_suite.sh
AWS_ARM64_CACHE_DIR      ?= $(ROOT_DIR)/.cache/aws-arm64
ARM64_TEST_ARTIFACTS_ROOT ?= $(AWS_ARM64_CACHE_DIR)/test-artifacts
ARM64_TEST_UNITTEST_BUILD_DIR ?= $(ARM64_TEST_ARTIFACTS_ROOT)/unittest/build-arm64
ARM64_TEST_NEGATIVE_BUILD_DIR ?= $(ARM64_TEST_ARTIFACTS_ROOT)/negative/build-arm64
ARM64_TEST_DAEMON_OUTPUT_DIR ?= $(ARM64_TEST_ARTIFACTS_ROOT)/daemon
ARM64_CROSSBUILD_OUTPUT_DIR ?= $(AWS_ARM64_CACHE_DIR)/binaries
ARM64_CROSSBUILD_CARGO_HOME ?= $(CACHE_DIR)/aws-arm64/cargo-home
ARM64_HOST_DAEMON_ROOT ?= $(AWS_ARM64_CACHE_DIR)/daemon-host-cross
ARM64_HOST_DAEMON_TARGET_DIR ?= $(ARM64_HOST_DAEMON_ROOT)/target
ARM64_HOST_DAEMON_OUTPUT_DIR ?= $(ARM64_HOST_DAEMON_ROOT)/output
ARM64_HOST_DAEMON_BINARY ?= $(ARM64_HOST_DAEMON_OUTPUT_DIR)/bpfrejit-daemon
ARM64_HOST_DAEMON_CARGO_HOME ?= $(CACHE_DIR)/aws-arm64/cargo-home-host-daemon
ARM64_HOST_SCX_ROOT ?= $(AWS_ARM64_CACHE_DIR)/scx-host-cross
ARM64_HOST_SCX_BUILD_ROOT ?= $(ARM64_HOST_SCX_ROOT)/build
ARM64_HOST_SCX_CARGO_HOME ?= $(ARM64_HOST_SCX_ROOT)/cargo-home
ARM64_CROSS_RUNNER_REAL  := $(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/build/micro_exec.real
ARM64_CROSS_DAEMON_REAL  := $(ARM64_CROSSBUILD_OUTPUT_DIR)/daemon/build/bpfrejit-daemon.real
AWS_ARM64_BENCH_MODE ?= all

export CROSS_COMPILE_ARM64 ARM64_BUILD_DIR ARM64_WORKTREE_DIR
export ARM64_DOCKER_PLATFORM ARM64_CROSSBUILD_JOBS
AWS_X86_CACHE_DIR         ?= $(ROOT_DIR)/.cache/aws-x86
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

# Derived
BZIMAGE_PATH := $(if $(filter /%,$(BZIMAGE)),$(BZIMAGE),$(ROOT_DIR)/$(BZIMAGE))
DAEMON_PATH  := $(if $(filter /%,$(DAEMON)),$(DAEMON),$(ROOT_DIR)/$(DAEMON))
MICRO_RUNNER := $(RUNNER_DIR)/build/micro_exec
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

# Incremental rebuild sources
MICRO_RUNNER_SOURCES := $(wildcard $(RUNNER_DIR)/src/*.cpp $(RUNNER_DIR)/include/*.hpp $(RUNNER_DIR)/CMakeLists.txt)
MICRO_BPF_SOURCES    := $(wildcard $(MICRO_DIR)/programs/*.bpf.c $(MICRO_DIR)/programs/common.h)
DAEMON_SOURCES       := $(wildcard $(DAEMON_DIR)/src/*.rs $(DAEMON_DIR)/Cargo.toml $(DAEMON_DIR)/Cargo.lock)
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
MICRO_BPF_STAMP      := $(MICRO_DIR)/programs/.build.stamp

.PHONY: all runner micro daemon kernel kernel-build kernel-clean kernel-rebuild kernel-arm64 kinsn-modules virtme-hostfs-modules upstream-selftests-build \
	corpus-fetch corpus-build corpus-build-native \
	corpus-build-bcc corpus-build-libbpf-bootstrap corpus-build-xdp-tools corpus-build-xdp-tutorial corpus-build-scx \
	corpus-build-katran corpus-build-tracee corpus-build-tetragon corpus-build-cilium corpus-build-bpftrace \
	daemon-tests python-tests check smoke validate \
	vm-test vm-micro vm-corpus vm-e2e vm-all \
	arm64-worktree __arm64-crossbuild-image __arm64-daemon-host-cross __cross-arm64 __cross-arm64-scx __cross-arm64-bench __arm64-test-artifacts \
	kernel-arm64-aws \
	aws-arm64-test aws-arm64-benchmark aws-arm64-terminate aws-arm64 \
	aws-x86-test aws-x86-benchmark aws-x86-terminate aws-x86 \
	__aws-arm64-benchmark-micro __aws-arm64-benchmark-corpus __aws-arm64-benchmark-e2e \
	__aws-x86-benchmark-micro __aws-x86-benchmark-corpus __aws-x86-benchmark-e2e \
	__kernel-config-locked __kernel-build-locked \
	help clean

# ── Help ───────────────────────────────────────────────────────────────────────
help:
	@echo "Build:  all runner micro daemon kernel kernel-clean kernel-rebuild kinsn-modules upstream-selftests-build kernel-arm64"
	@echo "Repos:  corpus-fetch corpus-build corpus-build-native corpus-build-bcc corpus-build-libbpf-bootstrap corpus-build-xdp-tools corpus-build-xdp-tutorial corpus-build-scx corpus-build-katran corpus-build-tracee corpus-build-tetragon corpus-build-cilium corpus-build-bpftrace REPOS=\"katran tracee tetragon cilium bpftrace ...\""
	@echo "Test:   smoke daemon-tests python-tests check"
	@echo "VM x86 canonical: vm-test vm-micro vm-corpus vm-e2e vm-all validate"
	@echo "        vm-corpus (full corpus suite driver)"
	@echo "AWS:    aws-arm64-test aws-arm64-benchmark aws-arm64-terminate aws-arm64"
	@echo "        aws-x86-test aws-x86-benchmark aws-x86-terminate aws-x86"
	@echo "Params: vm-micro SAMPLES=$(SAMPLES) WARMUPS=$(WARMUPS) INNER_REPEAT=$(INNER_REPEAT) BENCH=\"...\""
	@echo "        vm-corpus SAMPLES=$(VM_CORPUS_SAMPLES) VM_CORPUS_WORKLOAD_SECONDS=$(VM_CORPUS_WORKLOAD_SECONDS) FILTERS=\"...\" VM_CORPUS_ARGS=\"--rejit-passes map_inline,const_prop,dce --no-kinsn\""
	@echo "        vm-e2e E2E_CASE=\"all|tracee|...\" E2E_ARGS=\"--rejit-passes map_inline,const_prop,dce --no-kinsn\" PROFILE=$(PROFILE)"
	@echo "        aws-arm64-test/aws-arm64-benchmark AWS_ARM64_REGION=<region> AWS_ARM64_PROFILE=<profile> AWS_ARM64_ROOT_VOLUME_GB=<override>"
	@echo "        aws-arm64-test AWS_ARM64_TEST_MODE=<selftest|negative|test>"
	@echo "        aws-arm64-benchmark AWS_ARM64_BENCH_MODE=$(AWS_ARM64_BENCH_MODE) AWS_ARM64_E2E_CASES=<all|tracee,tetragon,...>"
	@echo "        aws-x86-test AWS_X86_REGION=<region> AWS_X86_PROFILE=<profile> AWS_X86_TEST_MODE=<selftest|negative|test>"
	@echo "        aws-x86-benchmark AWS_X86_BENCH_MODE=$(AWS_X86_BENCH_MODE) AWS_X86_E2E_CASES=<all|tracee,tetragon,...>"
	@echo "        AWS benchmark mode 'all' fans out micro/corpus/e2e in parallel on dedicated remote instances"

# ── Build ──────────────────────────────────────────────────────────────────────
all:
	$(MAKE) micro
	$(MAKE) daemon

runner:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" micro_exec

corpus-fetch:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" PYTHON="$(PYTHON)" REPOS="$(REPOS)" corpus-fetch

corpus-build:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" PYTHON="$(PYTHON)" REPOS="$(REPOS)" corpus-build

corpus-build-native:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" PYTHON="$(PYTHON)" REPOS="$(REPOS)" corpus-build-native

corpus-build-bcc:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" PYTHON="$(PYTHON)" corpus-build-bcc

corpus-build-libbpf-bootstrap:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" PYTHON="$(PYTHON)" corpus-build-libbpf-bootstrap

corpus-build-xdp-tools:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" PYTHON="$(PYTHON)" corpus-build-xdp-tools

corpus-build-xdp-tutorial:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" PYTHON="$(PYTHON)" corpus-build-xdp-tutorial

corpus-build-scx:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" PYTHON="$(PYTHON)" corpus-build-scx

corpus-build-katran:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" PYTHON="$(PYTHON)" corpus-build-katran

corpus-build-tracee:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" PYTHON="$(PYTHON)" corpus-build-tracee

corpus-build-tetragon:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" PYTHON="$(PYTHON)" corpus-build-tetragon

corpus-build-cilium:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" PYTHON="$(PYTHON)" corpus-build-cilium

corpus-build-bpftrace:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" PYTHON="$(PYTHON)" corpus-build-bpftrace

micro:
	$(MAKE) -j"$(JOBS)" runner
	$(MAKE) -j"$(JOBS)" -C "$(MICRO_DIR)" JOBS="$(JOBS)" programs

daemon:
	cargo build --release --manifest-path "$(DAEMON_DIR)/Cargo.toml"

kernel: kernel-build
	@test -f "$(BZIMAGE_PATH)"

kernel-clean:
	$(MAKE) -C "$(KERNEL_DIR)" clean
	rm -f "$(KERNEL_CONFIG_STAMP)"
	rm -f "$(KERNEL_BUILD_STAMP)"

kernel-rebuild: kernel-clean
	$(MAKE) kernel BZIMAGE="$(BZIMAGE)"

kinsn-modules: kernel-build
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

virtme-hostfs-modules: kernel-build
	@:

upstream-selftests-build: virtme-hostfs-modules
	@if [ ! -f "$(UPSTREAM_SELFTEST_DIR)/Makefile" ]; then \
		echo "upstream-selftests-build is unavailable in this checkout: missing $(UPSTREAM_SELFTEST_DIR)/Makefile" >&2; \
		exit 2; \
	fi
	rm -rf "$(UPSTREAM_SELFTEST_OUTPUT_DIR)"
	mkdir -p "$(UPSTREAM_SELFTEST_OUTPUT_DIR)"
	$(MAKE) -j"$(JOBS)" -C "$(UPSTREAM_SELFTEST_DIR)" \
		CLANG="$(UPSTREAM_SELFTEST_CLANG)" \
		LLC="$(UPSTREAM_SELFTEST_LLC)" \
		LLVM_CONFIG="$(UPSTREAM_SELFTEST_LLVM_CONFIG)" \
		LLVM_OBJCOPY="$(UPSTREAM_SELFTEST_LLVM_OBJCOPY)" \
		LLVM_STRIP="$(UPSTREAM_SELFTEST_LLVM_STRIP)" \
		OUTPUT="$(UPSTREAM_SELFTEST_OUTPUT_DIR)" \
		test_verifier test_progs

# Incremental rebuild rules
$(MICRO_RUNNER): $(MICRO_RUNNER_SOURCES)
	$(MAKE) -C "$(RUNNER_DIR)" micro_exec

$(MICRO_BPF_STAMP): $(MICRO_BPF_SOURCES)
	$(MAKE) -C "$(MICRO_DIR)" programs && touch "$@"

$(DAEMON_PATH): $(DAEMON_SOURCES)
	cargo build --release --manifest-path "$(DAEMON_DIR)/Cargo.toml"

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

kernel-build:
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

# ── Local tests ────────────────────────────────────────────────────────────────
smoke: $(MICRO_RUNNER) $(MICRO_BPF_STAMP)
	mkdir -p "$(MICRO_RESULTS_DIR)"
	$(VENV_ACTIVATE) python3 "$(MICRO_DIR)/driver.py" --runtime llvmbpf $(LOCAL_SMOKE_ARGS) --output "$(SMOKE_OUTPUT)"

daemon-tests:
	cargo test --manifest-path "$(DAEMON_DIR)/Cargo.toml"

python-tests:
	$(PYTHON) -m pytest tests/python/ -v

check:
	$(MAKE) all
	$(MAKE) daemon-tests
	$(MAKE) python-tests
	$(MAKE) smoke

validate:
	$(MAKE) check
	$(MAKE) vm-test
	SAMPLES=1 WARMUPS=0 INNER_REPEAT=50 "$(RUN_TARGET_SUITE_SCRIPT)" run x86-kvm micro

# ── VM (x86) ──────────────────────────────────────────────────────────────────
vm-test:
	"$(RUN_TARGET_SUITE_SCRIPT)" run x86-kvm test

vm-micro:
	"$(RUN_TARGET_SUITE_SCRIPT)" run x86-kvm micro

vm-corpus:
	"$(RUN_TARGET_SUITE_SCRIPT)" run x86-kvm corpus

vm-e2e:
	"$(RUN_TARGET_SUITE_SCRIPT)" run x86-kvm e2e

vm-all:
	$(MAKE) vm-test
	$(MAKE) vm-micro
	$(MAKE) vm-corpus
	$(MAKE) vm-e2e

# ── ARM64 kernel ───────────────────────────────────────────────────────────────
arm64-worktree:
	@mkdir -p "$(dir $(ARM64_WORKTREE_DIR))"
	@git -C "$(KERNEL_DIR)" worktree prune
	@if [ ! -e "$(ARM64_WORKTREE_DIR)/.git" ]; then \
		git -C "$(KERNEL_DIR)" worktree add --detach "$(ARM64_WORKTREE_DIR)" "$$(git -C "$(KERNEL_DIR)" rev-parse HEAD)"; \
	else \
		git -C "$(ARM64_WORKTREE_DIR)" checkout --detach "$$(git -C "$(KERNEL_DIR)" rev-parse HEAD)" >/dev/null; \
	fi

$(ARM64_BUILD_CONFIG): $(ROOT_DIR)/runner/scripts/arm64-kernel-config.sh | arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" "$(ROOT_DIR)/runner/scripts/arm64-kernel-config.sh" \
		"$(ARM64_WORKTREE_DIR)" "$(ARM64_BUILD_DIR)" "$(CROSS_COMPILE_ARM64)"
	ln -sfn build-arm64/.config "$(ARM64_CONFIG_LINK)"

$(ARM64_IMAGE): $(ARM64_BUILD_CONFIG) | arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(ARM64_WORKTREE_DIR)" O="$(ARM64_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" Image -j"$(NPROC)"
	ln -sfn ../../../build-arm64/arch/arm64/boot/Image "$(ARM64_IMAGE_LINK)"

$(ARM64_EFI_IMAGE): $(ARM64_BUILD_CONFIG) | arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(ARM64_WORKTREE_DIR)" O="$(ARM64_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" vmlinuz.efi -j"$(NPROC)"

kernel-arm64: $(ARM64_IMAGE) $(ARM64_EFI_IMAGE)
	ln -sfn build-arm64/.config "$(ARM64_CONFIG_LINK)"
	ln -sfn ../../../build-arm64/arch/arm64/boot/Image "$(ARM64_IMAGE_LINK)"

$(ARM64_AWS_BUILD_CONFIG): $(ROOT_DIR)/runner/scripts/aws_arm64_kernel_config.sh | arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" ARM64_BASE_CONFIG="$(ARM64_AWS_BASE_CONFIG)" "$(ROOT_DIR)/runner/scripts/aws_arm64_kernel_config.sh" \
		"$(ARM64_WORKTREE_DIR)" "$(ARM64_AWS_BUILD_DIR)" "$(CROSS_COMPILE_ARM64)"

$(ARM64_AWS_IMAGE): $(ARM64_AWS_BUILD_CONFIG) | arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(ARM64_WORKTREE_DIR)" O="$(ARM64_AWS_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" Image -j"$(NPROC)"

$(ARM64_AWS_EFI_IMAGE): $(ARM64_AWS_BUILD_CONFIG) | arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(ARM64_WORKTREE_DIR)" O="$(ARM64_AWS_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" vmlinuz.efi -j"$(NPROC)"

kernel-arm64-aws: $(ARM64_AWS_IMAGE) $(ARM64_AWS_EFI_IMAGE)

# ── ARM64 cross-build & VM ────────────────────────────────────────────────────
$(ARM64_CROSSBUILD_STAMP): $(ARM64_CROSSBUILD_DOCKERFILE)
	mkdir -p "$(dir $(ARM64_CROSSBUILD_STAMP))"
	flock "$(ARM64_CROSSBUILD_LOCK)" "$(DOCKER)" buildx build --load --platform "$(ARM64_DOCKER_PLATFORM)" \
		-f "$(ARM64_CROSSBUILD_DOCKERFILE)" -t "$(ARM64_CROSSBUILD_IMAGE)" "$(ARM64_CROSSBUILD_CONTEXT)"
	touch "$@"

__arm64-crossbuild-image: $(ARM64_CROSSBUILD_STAMP)

__arm64-daemon-host-cross:
	ARM64_HOST_DAEMON_TARGET_DIR="$(ARM64_HOST_DAEMON_TARGET_DIR)" \
	ARM64_HOST_DAEMON_OUTPUT_DIR="$(ARM64_HOST_DAEMON_OUTPUT_DIR)" \
	ARM64_HOST_DAEMON_BINARY="$(ARM64_HOST_DAEMON_BINARY)" \
	ARM64_HOST_DAEMON_CARGO_HOME="$(ARM64_HOST_DAEMON_CARGO_HOME)" \
	ARM64_SYSROOT_ROOT="$(ARM64_SYSROOT_ROOT)" \
	ARM64_SYSROOT_LOCK_FILE="$(ARM64_SYSROOT_LOCK_FILE)" \
	ARM64_SYSROOT_REMOTE_HOST="$(ARM64_SYSROOT_REMOTE_HOST)" \
	ARM64_SYSROOT_REMOTE_USER="$(ARM64_SYSROOT_REMOTE_USER)" \
	ARM64_SYSROOT_SSH_KEY_PATH="$(ARM64_SYSROOT_SSH_KEY_PATH)" \
	CROSS_COMPILE_ARM64="$(CROSS_COMPILE_ARM64)" \
		bash "$(ROOT_DIR)/runner/scripts/build-arm64-daemon-host.sh"
	file "$(ARM64_HOST_DAEMON_BINARY)" | grep -F "ELF 64-bit LSB pie executable, ARM aarch64"

__cross-arm64: __arm64-crossbuild-image
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR).tmp" && mkdir -p "$(ARM64_CROSSBUILD_OUTPUT_DIR).tmp"
	@if [ -z "$(ARM64_CROSSBUILD_RUNTIME_TARGETS)" ] || printf ',%s,' "$(ARM64_CROSSBUILD_RUNTIME_TARGETS)" | grep -q ',daemon,'; then \
		$(MAKE) __arm64-daemon-host-cross \
			ARM64_HOST_DAEMON_TARGET_DIR="$(ARM64_HOST_DAEMON_TARGET_DIR)" \
			ARM64_HOST_DAEMON_OUTPUT_DIR="$(ARM64_HOST_DAEMON_OUTPUT_DIR)" \
			ARM64_HOST_DAEMON_BINARY="$(ARM64_HOST_DAEMON_BINARY)" \
			ARM64_HOST_DAEMON_CARGO_HOME="$(ARM64_HOST_DAEMON_CARGO_HOME)"; \
	fi
	"$(DOCKER)" run --rm --platform "$(ARM64_DOCKER_PLATFORM)" \
		-v "$(ROOT_DIR)":/workspace -w /workspace \
		-e HOME=/tmp/codex \
		-e CARGO_HOME="$(call arm64_container_path,$(ARM64_CROSSBUILD_CARGO_HOME))" \
		-e HOST_UID="$$(id -u)" \
		-e HOST_GID="$$(id -g)" \
		-e ARM64_SOURCE_REPO_ROOT="$(call arm64_container_path,$(ARM64_SOURCE_REPO_ROOT))" \
		-e ARM64_CROSSBUILD_OUTPUT_DIR="$(call arm64_container_path,$(ARM64_CROSSBUILD_OUTPUT_DIR)).tmp" \
		-e ARM64_CROSSBUILD_BUILD_ROOT="$(call arm64_container_path,$(ARM64_CROSSBUILD_BUILD_ROOT))" \
		-e ARM64_CROSSBUILD_JOBS="$(ARM64_CROSSBUILD_JOBS)" \
		-e ARM64_CROSSBUILD_SCX_PACKAGES="$(ARM64_CROSSBUILD_SCX_PACKAGES)" \
		-e ARM64_CROSSBUILD_RUNTIME_TARGETS="$(ARM64_CROSSBUILD_RUNTIME_TARGETS)" \
		-e ARM64_PREBUILT_DAEMON_BINARY="$(call arm64_container_path,$(ARM64_HOST_DAEMON_BINARY))" \
		-e MICRO_EXEC_ENABLE_LLVMBPF="$(ARM64_CROSSBUILD_ENABLE_LLVMBPF)" \
	"$(ARM64_CROSSBUILD_IMAGE)" bash /workspace/runner/scripts/cross-arm64-build.sh
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)" && mv "$(ARM64_CROSSBUILD_OUTPUT_DIR).tmp" "$(ARM64_CROSSBUILD_OUTPUT_DIR)"
	@if [ -z "$(ARM64_CROSSBUILD_RUNTIME_TARGETS)" ] || printf ',%s,' "$(ARM64_CROSSBUILD_RUNTIME_TARGETS)" | grep -q ',runner,'; then \
		file "$(ARM64_CROSS_RUNNER_REAL)" | grep -F "ARM aarch64"; \
	fi
	@if [ -z "$(ARM64_CROSSBUILD_RUNTIME_TARGETS)" ] || printf ',%s,' "$(ARM64_CROSSBUILD_RUNTIME_TARGETS)" | grep -q ',daemon,'; then \
		file "$(ARM64_CROSS_DAEMON_REAL)" | grep -F "ARM aarch64"; \
	fi

__cross-arm64-scx:
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp" && mkdir -p "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp"
	ARM64_SCX_SOURCE_REPO_ROOT="$(ARM64_SOURCE_REPO_ROOT)" \
	ARM64_SCX_BUILD_ROOT="$(ARM64_HOST_SCX_BUILD_ROOT)" \
	ARM64_SCX_PROMOTE_ROOT="$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp" \
	ARM64_SCX_CARGO_HOME="$(ARM64_HOST_SCX_CARGO_HOME)" \
	ARM64_SCX_PACKAGES="$(ARM64_CROSSBUILD_SCX_PACKAGES)" \
	ARM64_SYSROOT_ROOT="$(ARM64_SYSROOT_ROOT)" \
	ARM64_SYSROOT_LOCK_FILE="$(ARM64_SYSROOT_LOCK_FILE)" \
	ARM64_SYSROOT_REMOTE_HOST="$(ARM64_SYSROOT_REMOTE_HOST)" \
	ARM64_SYSROOT_REMOTE_USER="$(ARM64_SYSROOT_REMOTE_USER)" \
	ARM64_SYSROOT_SSH_KEY_PATH="$(ARM64_SYSROOT_SSH_KEY_PATH)" \
	CROSS_COMPILE_ARM64="$(CROSS_COMPILE_ARM64)" \
	ARM64_CROSSBUILD_JOBS="$(ARM64_CROSSBUILD_JOBS)" \
		bash "$(ROOT_DIR)/runner/scripts/build-arm64-scx-host.sh"
	test -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp/runner/repos/scx/target/release"
	test -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp/corpus/build/scx"
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/repos/scx" "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/scx"
	mkdir -p "$(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/repos/scx/target/release" "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/scx" "$(ARM64_CROSSBUILD_OUTPUT_DIR)/lib"
	cp -a "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp/runner/repos/scx/target/release/." "$(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/repos/scx/target/release/"
	cp -a "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp/corpus/build/scx/." "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/scx/"
	if [ -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp/lib" ]; then cp -a "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp/lib/." "$(ARM64_CROSSBUILD_OUTPUT_DIR)/lib/"; fi
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR).scx.tmp"

__cross-arm64-bench: __arm64-crossbuild-image
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp" && mkdir -p "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp"
	"$(DOCKER)" run --rm --platform "$(ARM64_DOCKER_PLATFORM)" \
		-v "$(ROOT_DIR)":/workspace -w /workspace \
		-e HOME=/tmp/codex \
		-e CARGO_HOME="$(call arm64_container_path,$(ARM64_CROSSBUILD_CARGO_HOME))" \
		-e HOST_UID="$$(id -u)" \
		-e HOST_GID="$$(id -g)" \
		-e ARM64_SOURCE_REPO_ROOT="$(call arm64_container_path,$(ARM64_SOURCE_REPO_ROOT))" \
		-e ARM64_CROSSBUILD_OUTPUT_DIR="$(call arm64_container_path,$(ARM64_CROSSBUILD_OUTPUT_DIR)).bench.tmp" \
		-e ARM64_CROSSBUILD_BUILD_ROOT="$(call arm64_container_path,$(ARM64_CROSSBUILD_BUILD_ROOT))" \
		-e ARM64_CROSSBUILD_JOBS="$(ARM64_CROSSBUILD_JOBS)" \
		-e ARM64_CROSSBUILD_BENCH_REPOS="$(ARM64_CROSSBUILD_BENCH_REPOS)" \
		-e ARM64_CROSSBUILD_ONLY_BENCH=1 \
		"$(ARM64_CROSSBUILD_IMAGE)" bash /workspace/runner/scripts/cross-arm64-build.sh
	@set -e; repo_csv="$(ARM64_CROSSBUILD_BENCH_REPOS)"; \
	case ",$$repo_csv," in \
		*,bcc,*) test -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/runner/repos/bcc/libbpf-tools/.output" && test -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/corpus/build/bcc/libbpf-tools" ;; \
	esac; \
	case ",$$repo_csv," in \
		*,katran,*) test -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/corpus/build/katran" && test -x "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/katran/bin/katran_server_grpc" && test -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/katran/lib" ;; \
	esac; \
	case ",$$repo_csv," in \
		*,tracee,*) test -x "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/corpus/build/tracee/bin/tracee" && test -f "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/corpus/build/tracee/tracee.bpf.o" ;; \
	esac; \
	case ",$$repo_csv," in \
		*,tetragon,*) test -x "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/corpus/build/tetragon/bin/tetragon" ;; \
	esac
	@if printf ',%s,' "$(ARM64_CROSSBUILD_BENCH_REPOS)" | grep -q ',bcc,'; then \
		rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/repos/bcc" "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/bcc"; \
	fi
	@if printf ',%s,' "$(ARM64_CROSSBUILD_BENCH_REPOS)" | grep -q ',katran,'; then \
		rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/katran" "$(ARM64_CROSSBUILD_OUTPUT_DIR)/katran"; \
	fi
	@if printf ',%s,' "$(ARM64_CROSSBUILD_BENCH_REPOS)" | grep -q ',tracee,'; then \
		rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/tracee"; \
	fi
	@if printf ',%s,' "$(ARM64_CROSSBUILD_BENCH_REPOS)" | grep -q ',tetragon,'; then \
		rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/tetragon"; \
	fi
	mkdir -p "$(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/repos" "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build" "$(ARM64_CROSSBUILD_OUTPUT_DIR)/lib"
	if [ -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/runner/repos" ]; then cp -a "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/runner/repos/." "$(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/repos/"; fi
	if [ -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/corpus/build" ]; then cp -a "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/corpus/build/." "$(ARM64_CROSSBUILD_OUTPUT_DIR)/corpus/build/"; fi
	if [ -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/katran" ]; then mkdir -p "$(ARM64_CROSSBUILD_OUTPUT_DIR)/katran" && cp -a "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/katran/." "$(ARM64_CROSSBUILD_OUTPUT_DIR)/katran/"; fi
	if [ -d "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/lib" ]; then cp -a "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp/lib/." "$(ARM64_CROSSBUILD_OUTPUT_DIR)/lib/"; fi
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR).bench.tmp"

__arm64-test-artifacts:
	@if [ "$(ARM64_TEST_MODE)" = "selftest" ] || [ "$(ARM64_TEST_MODE)" = "test" ]; then \
		$(MAKE) __arm64-daemon-host-cross \
			ARM64_HOST_DAEMON_TARGET_DIR="$(ARM64_HOST_DAEMON_TARGET_DIR)" \
			ARM64_HOST_DAEMON_OUTPUT_DIR="$(ARM64_HOST_DAEMON_OUTPUT_DIR)" \
			ARM64_HOST_DAEMON_BINARY="$(ARM64_HOST_DAEMON_BINARY)" \
			ARM64_HOST_DAEMON_CARGO_HOME="$(ARM64_HOST_DAEMON_CARGO_HOME)"; \
	fi
	VMLINUX_BTF="$(VMLINUX_BTF)" \
	ARM64_TEST_MODE="$(ARM64_TEST_MODE)" \
	ARM64_TEST_ARTIFACTS_ROOT="$(ARM64_TEST_ARTIFACTS_ROOT)" \
	ARM64_TEST_UNITTEST_BUILD_DIR="$(ARM64_TEST_UNITTEST_BUILD_DIR)" \
	ARM64_TEST_NEGATIVE_BUILD_DIR="$(ARM64_TEST_NEGATIVE_BUILD_DIR)" \
	ARM64_TEST_DAEMON_OUTPUT_DIR="$(ARM64_TEST_DAEMON_OUTPUT_DIR)" \
	ARM64_TEST_PREBUILT_DAEMON_BINARY="$(ARM64_HOST_DAEMON_BINARY)" \
	ARM64_SYSROOT_ROOT="$(ARM64_SYSROOT_ROOT)" \
	ARM64_SYSROOT_LOCK_FILE="$(ARM64_SYSROOT_LOCK_FILE)" \
	ARM64_SYSROOT_REMOTE_HOST="$(ARM64_SYSROOT_REMOTE_HOST)" \
	ARM64_SYSROOT_REMOTE_USER="$(ARM64_SYSROOT_REMOTE_USER)" \
	ARM64_SYSROOT_SSH_KEY_PATH="$(ARM64_SYSROOT_SSH_KEY_PATH)" \
		ARM64_CROSSBUILD_JOBS="$(ARM64_CROSSBUILD_JOBS)" \
		CROSS_COMPILE_ARM64="$(CROSS_COMPILE_ARM64)" \
			bash "$(ROOT_DIR)/runner/scripts/build-arm64-repo-tests-host.sh"
	@if [ "$(ARM64_TEST_MODE)" != "negative" ]; then \
		file "$(ARM64_TEST_UNITTEST_BUILD_DIR)/rejit_kinsn" | grep -F "ARM aarch64"; \
	fi
	@if [ "$(ARM64_TEST_MODE)" = "selftest" ] || [ "$(ARM64_TEST_MODE)" = "negative" ] || [ "$(ARM64_TEST_MODE)" = "test" ]; then \
		file "$(ARM64_TEST_NEGATIVE_BUILD_DIR)/adversarial_rejit" | grep -F "ARM aarch64"; \
	fi

# ── AWS ARM64 ─────────────────────────────────────────────────────────────────
aws-arm64-test:
	"$(RUN_TARGET_SUITE_SCRIPT)" run aws-arm64 test
__aws-arm64-benchmark-micro:
	"$(RUN_TARGET_SUITE_SCRIPT)" run aws-arm64 micro
__aws-arm64-benchmark-corpus:
	"$(RUN_TARGET_SUITE_SCRIPT)" run aws-arm64 corpus
__aws-arm64-benchmark-e2e:
	"$(RUN_TARGET_SUITE_SCRIPT)" run aws-arm64 e2e
aws-arm64-benchmark:
	+@case "$(AWS_ARM64_BENCH_MODE)" in \
		micro) "$(MAKE)" --no-print-directory __aws-arm64-benchmark-micro ;; \
		corpus) "$(MAKE)" --no-print-directory __aws-arm64-benchmark-corpus ;; \
		e2e) "$(MAKE)" --no-print-directory __aws-arm64-benchmark-e2e ;; \
		all) "$(MAKE)" --no-print-directory -j3 \
			__aws-arm64-benchmark-micro \
			__aws-arm64-benchmark-corpus \
			__aws-arm64-benchmark-e2e ;; \
		*) echo "ERROR: AWS_ARM64_BENCH_MODE must be one of micro, corpus, e2e, all" >&2; exit 1 ;; \
	esac
aws-arm64-terminate:
	"$(RUN_TARGET_SUITE_SCRIPT)" terminate aws-arm64
aws-arm64: aws-arm64-test aws-arm64-benchmark

# ── AWS x86 ───────────────────────────────────────────────────────────────────
aws-x86-test:
	"$(RUN_TARGET_SUITE_SCRIPT)" run aws-x86 test
__aws-x86-benchmark-micro:
	"$(RUN_TARGET_SUITE_SCRIPT)" run aws-x86 micro
__aws-x86-benchmark-corpus:
	"$(RUN_TARGET_SUITE_SCRIPT)" run aws-x86 corpus
__aws-x86-benchmark-e2e:
	"$(RUN_TARGET_SUITE_SCRIPT)" run aws-x86 e2e
aws-x86-benchmark:
	+@case "$(AWS_X86_BENCH_MODE)" in \
		micro) "$(MAKE)" --no-print-directory __aws-x86-benchmark-micro ;; \
		corpus) "$(MAKE)" --no-print-directory __aws-x86-benchmark-corpus ;; \
		e2e) "$(MAKE)" --no-print-directory __aws-x86-benchmark-e2e ;; \
		all) "$(MAKE)" --no-print-directory -j3 \
			__aws-x86-benchmark-micro \
			__aws-x86-benchmark-corpus \
			__aws-x86-benchmark-e2e ;; \
		*) echo "ERROR: AWS_X86_BENCH_MODE must be one of micro, corpus, e2e, all" >&2; exit 1 ;; \
	esac
aws-x86-terminate:
	"$(RUN_TARGET_SUITE_SCRIPT)" terminate aws-x86
aws-x86: aws-x86-test aws-x86-benchmark

# ── Clean ──────────────────────────────────────────────────────────────────────
clean:
	$(MAKE) -C "$(RUNNER_DIR)" clean
	$(MAKE) -C "$(MICRO_DIR)" clean
	rm -f "$(MICRO_BPF_STAMP)"
	cargo clean --manifest-path "$(DAEMON_DIR)/Cargo.toml"
	$(MAKE) -C "$(KERNEL_DIR)" clean
	rm -f "$(SMOKE_OUTPUT)" "$(ARM64_CONFIG_LINK)" "$(ARM64_IMAGE_LINK)"
	rm -rf "$(ARM64_BUILD_DIR)" "$(ARM64_CROSSBUILD_OUTPUT_DIR)" "$(ARM64_TEST_ARTIFACTS_ROOT)" "$(UPSTREAM_SELFTEST_OUTPUT_DIR)"
