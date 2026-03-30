SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

$(if $(wildcard vendor/linux-framework/Makefile),,$(error vendor/linux-framework not found. Run: git submodule update --init --recursive))

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
MICRO_DIR := $(ROOT_DIR)/micro
RUNNER_DIR := $(ROOT_DIR)/runner
DAEMON_DIR := $(ROOT_DIR)/daemon
KERNEL_DIR := $(ROOT_DIR)/vendor/linux-framework
KERNEL_TEST_DIR := $(ROOT_DIR)/tests/kernel
KINSN_MODULE_DIR := $(ROOT_DIR)/module/x86
CACHE_DIR := $(ROOT_DIR)/.cache

# ARM64 / AWS (see runner/scripts/aws_arm64.sh for full docs)
ARM64_WORKTREE_DIR  ?= $(ROOT_DIR)/.worktrees/linux-framework-arm64-src
ARM64_BUILD_DIR     ?= $(KERNEL_DIR)/build-arm64
ARM64_BUILD_CONFIG  := $(ARM64_BUILD_DIR)/.config
ARM64_IMAGE         := $(ARM64_BUILD_DIR)/arch/arm64/boot/Image
ARM64_IMAGE_LINK    := $(KERNEL_DIR)/arch/arm64/boot/Image
ARM64_CONFIG_LINK   := $(KERNEL_DIR)/.config.arm64
ARM64_ROOTFS_DIR    ?= $(HOME)/.cache/bpf-benchmark/arm64-rootfs
ARM64_ROOTFS_RELEASE ?= noble
ARM64_ROOTFS_MIRROR ?= http://ports.ubuntu.com/ubuntu-ports
ARM64_QEMU          ?= qemu-system-aarch64
CROSS_COMPILE_ARM64 ?= aarch64-linux-gnu-
DOCKER              ?= docker
ARM64_CROSSBUILD_DOCKERFILE := $(ROOT_DIR)/runner/docker/arm64-crossbuild.Dockerfile
ARM64_CROSSBUILD_CONTEXT    := $(ROOT_DIR)/runner/docker
ARM64_CROSSBUILD_IMAGE      ?= bpf-benchmark-arm64-crossbuild:latest
ARM64_CROSSBUILD_STAMP      := $(ROOT_DIR)/.cache/arm64-crossbuild-image.stamp
ARM64_DOCKER_PLATFORM       ?= linux/arm64
ARM64_REPO_GUEST_MOUNT      ?= /mnt
ARM64_SELFTEST_GUEST_ROOT   ?= $(ARM64_REPO_GUEST_MOUNT)/tests/kernel
ARM64_CROSSBUILD_ENABLE_LLVMBPF ?= OFF
ARM64_CROSSBUILD_JOBS       ?= 4
ARM64_KERNEL_MAKEFLAGS      := $(filter-out B,$(MAKEFLAGS))
AWS_ARM64_SCRIPT         := $(ROOT_DIR)/runner/scripts/aws_arm64.sh
AWS_ARM64_CACHE_DIR      ?= $(ROOT_DIR)/.cache/aws-arm64
ARM64_CROSSBUILD_OUTPUT_DIR ?= $(AWS_ARM64_CACHE_DIR)/binaries
ARM64_CROSS_RUNNER_REAL  := $(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/build/micro_exec.real
ARM64_CROSS_DAEMON_REAL  := $(ARM64_CROSSBUILD_OUTPUT_DIR)/daemon/build/bpfrejit-daemon.real
AWS_ARM64_NAME_TAG       ?= bpf-benchmark-arm64
AWS_ARM64_INSTANCE_TYPE  ?= t4g.micro
AWS_ARM64_REMOTE_USER    ?= ec2-user
AWS_ARM64_REMOTE_STAGE_DIR        ?= /home/$(AWS_ARM64_REMOTE_USER)/bpf-benchmark-arm64
AWS_ARM64_REMOTE_KERNEL_STAGE_DIR ?= /home/$(AWS_ARM64_REMOTE_USER)/codex-kernel-stage
AWS_ARM64_AMI_PARAM      ?= /aws/service/ami-amazon-linux-latest/al2023-ami-kernel-default-arm64
AWS_ARM64_BENCH_ITERATIONS ?= 1
AWS_ARM64_BENCH_WARMUPS    ?= 0
AWS_ARM64_BENCH_REPEAT     ?= 10

export AWS_REGION AWS_DEFAULT_REGION AWS_PROFILE
export AWS_ARM64_CACHE_DIR AWS_ARM64_NAME_TAG AWS_ARM64_INSTANCE_TYPE
export AWS_ARM64_REMOTE_USER AWS_ARM64_REMOTE_STAGE_DIR AWS_ARM64_REMOTE_KERNEL_STAGE_DIR
export AWS_ARM64_KEY_NAME AWS_ARM64_KEY_PATH AWS_ARM64_SECURITY_GROUP_ID AWS_ARM64_SUBNET_ID
export AWS_ARM64_AMI_PARAM AWS_ARM64_AMI_ID
export AWS_ARM64_BENCH_ITERATIONS AWS_ARM64_BENCH_WARMUPS AWS_ARM64_BENCH_REPEAT
export CROSS_COMPILE_ARM64 ARM64_BUILD_DIR ARM64_WORKTREE_DIR
export ARM64_DOCKER_PLATFORM ARM64_CROSSBUILD_OUTPUT_DIR ARM64_CROSSBUILD_JOBS

AWS_X86_SCRIPT            := $(ROOT_DIR)/runner/scripts/aws_x86.sh
AWS_X86_CACHE_DIR         ?= $(ROOT_DIR)/.cache/aws-x86
AWS_X86_NAME_TAG          ?= bpf-benchmark-x86
AWS_X86_INSTANCE_TYPE     ?= t3.micro
AWS_X86_REMOTE_USER       ?= ec2-user
AWS_X86_REMOTE_STAGE_DIR  ?= /home/$(AWS_X86_REMOTE_USER)/bpf-benchmark-x86
AWS_X86_REMOTE_KERNEL_STAGE_DIR ?= /home/$(AWS_X86_REMOTE_USER)/codex-kernel-stage-x86
AWS_X86_AMI_PARAM         ?= /aws/service/ami-amazon-linux-latest/al2023-ami-kernel-default-x86_64
AWS_X86_BENCH_ITERATIONS  ?= 1
AWS_X86_BENCH_WARMUPS     ?= 0
AWS_X86_BENCH_REPEAT      ?= 10

export AWS_X86_CACHE_DIR AWS_X86_NAME_TAG AWS_X86_INSTANCE_TYPE
export AWS_X86_REMOTE_USER AWS_X86_REMOTE_STAGE_DIR AWS_X86_REMOTE_KERNEL_STAGE_DIR
export AWS_X86_KEY_NAME AWS_X86_KEY_PATH AWS_X86_SECURITY_GROUP_ID AWS_X86_SUBNET_ID
export AWS_X86_AMI_PARAM AWS_X86_AMI_ID
export AWS_X86_BENCH_ITERATIONS AWS_X86_BENCH_WARMUPS AWS_X86_BENCH_REPEAT

# Tunables
BZIMAGE ?= vendor/linux-framework/arch/x86/boot/bzImage
DAEMON  ?= daemon/target/release/bpfrejit-daemon
DAEMON_ARGS ?=
DAEMON_SOCKET ?= /tmp/bpfrejit.sock
E2E_ARGS ?=
E2E_CASE ?= all
REPOS ?=
PROFILE ?=
FILTERS ?=
ITERATIONS ?= 3
WARMUPS    ?= 1
REPEAT     ?= 100
VM_CORPUS_REPEAT ?= 200
VM_CORPUS_WORKLOAD_SECONDS ?=
BENCH      ?=
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

# Results
MICRO_RESULTS_DIR      := $(ROOT_DIR)/micro/results
SMOKE_OUTPUT           := $(MICRO_RESULTS_DIR)/smoke.json

# Python / venv
_VENV_CANDIDATES := $(HOME)/workspace/.venv $(HOME)/.venv .venv venv
_VENV_FOUND := $(firstword $(foreach v,$(_VENV_CANDIDATES),$(if $(wildcard $(v)/bin/activate),$(v),)))
VENV ?= $(_VENV_FOUND)
PYTHON := $(if $(VENV),$(VENV)/bin/python3,python3)
VENV_ACTIVATE := $(if $(VENV),source "$(VENV)/bin/activate" &&,)

# Benchmark args
LOCAL_SMOKE_ARGS := --bench simple --iterations 1 --warmups 0 --repeat 10
ROOT_VM_CORPUS_REPEAT_IS_EXPLICIT := $(or $(findstring command line,$(origin REPEAT)),$(findstring environment,$(origin REPEAT)),$(findstring override,$(origin REPEAT)))
ROOT_VM_CORPUS_REPEAT_VALUE := $(if $(strip $(ROOT_VM_CORPUS_REPEAT_IS_EXPLICIT)),$(REPEAT),$(VM_CORPUS_REPEAT))
ROOT_VM_CORPUS_REPEAT_ARG := REPEAT="$(ROOT_VM_CORPUS_REPEAT_VALUE)"
ROOT_VM_CORPUS_FILTERS_ARG := $(if $(strip $(FILTERS)),FILTERS="$(FILTERS)",)
ROOT_VM_CORPUS_WORKLOAD_SECONDS_ARG := $(if $(strip $(VM_CORPUS_WORKLOAD_SECONDS)),VM_CORPUS_WORKLOAD_SECONDS="$(VM_CORPUS_WORKLOAD_SECONDS)",)

# Incremental rebuild sources
MICRO_RUNNER_SOURCES := $(wildcard $(RUNNER_DIR)/src/*.cpp $(RUNNER_DIR)/include/*.hpp $(RUNNER_DIR)/CMakeLists.txt)
MICRO_BPF_SOURCES    := $(wildcard $(MICRO_DIR)/programs/*.bpf.c $(MICRO_DIR)/programs/common.h)
DAEMON_SOURCES       := $(wildcard $(DAEMON_DIR)/src/*.rs $(DAEMON_DIR)/Cargo.toml $(DAEMON_DIR)/Cargo.lock)
VIRTME_HOSTFS_MODULES := \
	drivers/net/veth.ko \
	net/ipv4/ip_tunnel.ko \
	net/ipv4/tunnel4.ko \
	net/ipv4/ipip.ko \
	fs/netfs/netfs.ko \
	net/9p/9pnet.ko \
	net/9p/9pnet_virtio.ko \
	fs/9p/9p.ko \
	fs/fuse/virtiofs.ko \
	fs/overlayfs/overlay.ko
VIRTME_HOSTFS_MODULE_ORDER := \
	drivers/net/veth.o \
	net/ipv4/ip_tunnel.o \
	net/ipv4/tunnel4.o \
	net/ipv4/ipip.o \
	fs/netfs/netfs.o \
	net/9p/9pnet.o \
	net/9p/9pnet_virtio.o \
	fs/9p/9p.o \
	fs/fuse/virtiofs.o \
	fs/overlayfs/overlay.o
MICRO_BPF_STAMP      := $(MICRO_DIR)/programs/.build.stamp

.PHONY: all runner micro daemon kernel kernel-build kernel-clean kernel-rebuild kernel-arm64 kernel-tests kinsn-modules virtme-hostfs-modules upstream-selftests-build \
	corpus-fetch corpus-build corpus-build-native \
	corpus-build-bcc corpus-build-libbpf-bootstrap corpus-build-xdp-tools corpus-build-xdp-tutorial corpus-build-scx \
	corpus-build-katran corpus-build-tracee corpus-build-tetragon corpus-build-cilium corpus-build-bpftrace \
	daemon-tests python-tests check smoke validate \
	vm-shell vm-test vm-selftest vm-negative-test vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all \
	arm64-worktree arm64-rootfs arm64-crossbuild-image cross-arm64 selftest-arm64 \
	vm-arm64-smoke vm-arm64-selftest \
	aws-arm64-launch aws-arm64-setup aws-arm64-benchmark aws-arm64-terminate aws-arm64 \
	aws-x86-launch aws-x86-setup aws-x86-benchmark aws-x86-terminate aws-x86-full aws-x86 \
	__kernel-config-locked __kernel-build-locked \
	help clean

# ── Help ───────────────────────────────────────────────────────────────────────
help:
	@echo "Build:  all runner micro daemon kernel kernel-clean kernel-rebuild kinsn-modules kernel-tests upstream-selftests-build kernel-arm64 cross-arm64"
	@echo "Repos:  corpus-fetch corpus-build corpus-build-native corpus-build-bcc corpus-build-libbpf-bootstrap corpus-build-xdp-tools corpus-build-xdp-tutorial corpus-build-scx corpus-build-katran corpus-build-tracee corpus-build-tetragon corpus-build-cilium corpus-build-bpftrace REPOS=\"katran tracee tetragon cilium bpftrace ...\""
	@echo "Test:   smoke daemon-tests python-tests check"
	@echo "VM x86: vm-shell vm-test vm-selftest vm-negative-test vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all validate"
	@echo "        vm-corpus (new orchestrator full corpus)"
	@echo "ARM64:  vm-arm64-smoke vm-arm64-selftest"
	@echo "AWS:    aws-arm64-launch aws-arm64-setup aws-arm64-benchmark aws-arm64-terminate aws-arm64"
	@echo "        aws-x86-launch aws-x86-setup aws-x86-benchmark aws-x86-terminate aws-x86-full aws-x86"
	@echo "Params: vm-micro ITERATIONS=$(ITERATIONS) WARMUPS=$(WARMUPS) REPEAT=$(REPEAT) BENCH=\"...\""
	@echo "        vm-corpus REPEAT=$(VM_CORPUS_REPEAT) VM_CORPUS_WORKLOAD_SECONDS=$(VM_CORPUS_WORKLOAD_SECONDS) FILTERS=\"...\" TARGET=\"x86|arm64|aws|...\""
	@echo "        vm-e2e E2E_CASE=\"all|tracee|...\" PROFILE=$(PROFILE)"

# ── Build ──────────────────────────────────────────────────────────────────────
all:
	$(MAKE) micro
	$(MAKE) daemon
	$(MAKE) kernel-tests

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
	$(MAKE) -C "$(KINSN_MODULE_DIR)" KDIR="$(KERNEL_DIR)"

virtme-hostfs-modules: kernel-build
	@:

kernel-tests:
	$(MAKE) -j"$(JOBS)" -C "$(KERNEL_TEST_DIR)" JOBS="$(JOBS)"

upstream-selftests-build: virtme-hostfs-modules
	$(MAKE) -j"$(JOBS)" -C "$(KERNEL_TEST_DIR)" JOBS="$(JOBS)" upstream-selftests

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
	rm -rf "$(KERNEL_DIR)/.virtme_mods"
	# Parallel sub-makes here occasionally race on generated kernel headers.
	$(MAKE) -j1 -C "$(KERNEL_DIR)" $(VIRTME_HOSTFS_MODULES)
	@for module in $(VIRTME_HOSTFS_MODULES); do \
		test -f "$(KERNEL_DIR)/$$module" || { \
			echo "missing built hostfs module: $(KERNEL_DIR)/$$module" >&2; \
			exit 1; \
		}; \
	done
	@printf '%s\n' $(VIRTME_HOSTFS_MODULE_ORDER) > "$(KERNEL_DIR)/modules.order"
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
	$(MAKE) vm-micro-smoke

# ── VM (x86) ──────────────────────────────────────────────────────────────────
vm-shell:
	$(MAKE) -C "$(RUNNER_DIR)" vm-shell \
		PYTHON="$(PYTHON)" VENV="$(VENV)" \
		BZIMAGE="$(BZIMAGE)" TARGET="$(TARGET)" \
		VM_COMMAND='$(VM_COMMAND)'

vm-test:
	$(MAKE) -C "$(RUNNER_DIR)" vm-test \
		PYTHON="$(PYTHON)" VENV="$(VENV)" \
		BZIMAGE="$(BZIMAGE)" TARGET="$(TARGET)"

vm-selftest:
	$(MAKE) -C "$(RUNNER_DIR)" vm-selftest \
		PYTHON="$(PYTHON)" VENV="$(VENV)" \
		BZIMAGE="$(BZIMAGE)" TARGET="$(TARGET)"

NEGATIVE_TEST_DIR := $(ROOT_DIR)/tests/negative
FUZZ_ROUNDS ?= 1000

vm-negative-test:
	$(MAKE) -C "$(RUNNER_DIR)" vm-negative-test \
		PYTHON="$(PYTHON)" VENV="$(VENV)" \
		BZIMAGE="$(BZIMAGE)" TARGET="$(TARGET)" FUZZ_ROUNDS="$(FUZZ_ROUNDS)" \
		SCX_PROG_SHOW_RACE_MODE="$(SCX_PROG_SHOW_RACE_MODE)" \
		SCX_PROG_SHOW_RACE_ITERATIONS="$(SCX_PROG_SHOW_RACE_ITERATIONS)" \
		SCX_PROG_SHOW_RACE_LOAD_TIMEOUT="$(SCX_PROG_SHOW_RACE_LOAD_TIMEOUT)" \
		SCX_PROG_SHOW_RACE_SKIP_PROBE="$(SCX_PROG_SHOW_RACE_SKIP_PROBE)"

SCX_PROG_SHOW_RACE_MODE ?= bpftool-loop
SCX_PROG_SHOW_RACE_ITERATIONS ?= 20
SCX_PROG_SHOW_RACE_LOAD_TIMEOUT ?= 20
SCX_PROG_SHOW_RACE_SKIP_PROBE ?= 0

vm-micro-smoke:
	$(MAKE) -C "$(RUNNER_DIR)" vm-micro-smoke \
		PYTHON="$(PYTHON)" VENV="$(VENV)" \
		BZIMAGE="$(BZIMAGE)" TARGET="$(TARGET)"

vm-micro:
	$(MAKE) -C "$(RUNNER_DIR)" vm-micro \
		PYTHON="$(PYTHON)" VENV="$(VENV)" \
		BZIMAGE="$(BZIMAGE)" TARGET="$(TARGET)" \
		ITERATIONS="$(ITERATIONS)" WARMUPS="$(WARMUPS)" REPEAT="$(REPEAT)" BENCH="$(BENCH)"

vm-corpus:
	$(MAKE) -C "$(RUNNER_DIR)" vm-corpus \
		PYTHON="$(PYTHON)" VENV="$(VENV)" \
		BZIMAGE="$(BZIMAGE)" DAEMON="$(DAEMON)" DAEMON_ARGS="$(DAEMON_ARGS)" TARGET="$(TARGET)" \
		$(ROOT_VM_CORPUS_REPEAT_ARG) $(ROOT_VM_CORPUS_FILTERS_ARG) $(ROOT_VM_CORPUS_WORKLOAD_SECONDS_ARG)

vm-e2e:
	$(MAKE) -C "$(RUNNER_DIR)" vm-e2e \
		PYTHON="$(PYTHON)" VENV="$(VENV)" \
		BZIMAGE="$(BZIMAGE)" DAEMON="$(DAEMON)" DAEMON_ARGS="$(DAEMON_ARGS)" TARGET="$(TARGET)" \
		E2E_CASE="$(E2E_CASE)" E2E_ARGS="$(E2E_ARGS)"

vm-all:
	$(MAKE) vm-test
	$(MAKE) vm-micro
	$(MAKE) vm-corpus
	$(MAKE) vm-e2e

# ── ARM64 kernel ───────────────────────────────────────────────────────────────
arm64-worktree:
	@mkdir -p "$(dir $(ARM64_WORKTREE_DIR))"
	@if [ ! -e "$(ARM64_WORKTREE_DIR)/.git" ]; then \
		git -C "$(KERNEL_DIR)" worktree add --detach "$(ARM64_WORKTREE_DIR)" "$$(git -C "$(KERNEL_DIR)" rev-parse HEAD)"; \
	else \
		git -C "$(ARM64_WORKTREE_DIR)" checkout --detach "$$(git -C "$(KERNEL_DIR)" rev-parse HEAD)" >/dev/null; \
	fi

$(ARM64_BUILD_CONFIG): | arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" "$(ROOT_DIR)/runner/scripts/arm64-kernel-config.sh" \
		"$(ARM64_WORKTREE_DIR)" "$(ARM64_BUILD_DIR)" "$(CROSS_COMPILE_ARM64)"
	ln -sfn build-arm64/.config "$(ARM64_CONFIG_LINK)"

$(ARM64_IMAGE): $(ARM64_BUILD_CONFIG) | arm64-worktree
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(ARM64_WORKTREE_DIR)" O="$(ARM64_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" Image -j"$(NPROC)"
	ln -sfn ../../../build-arm64/arch/arm64/boot/Image "$(ARM64_IMAGE_LINK)"

kernel-arm64: $(ARM64_IMAGE)
	ln -sfn build-arm64/.config "$(ARM64_CONFIG_LINK)"
	ln -sfn ../../../build-arm64/arch/arm64/boot/Image "$(ARM64_IMAGE_LINK)"

$(ARM64_ROOTFS_DIR)/bin/sh:
	sudo mkdir -p "$(dir $(ARM64_ROOTFS_DIR))"
	sudo rm -rf "$(ARM64_ROOTFS_DIR)"
	sudo qemu-debootstrap --arch=arm64 --variant=minbase "$(ARM64_ROOTFS_RELEASE)" \
		"$(ARM64_ROOTFS_DIR)" "$(ARM64_ROOTFS_MIRROR)"

arm64-rootfs: $(ARM64_ROOTFS_DIR)/bin/sh

# ── ARM64 cross-build & VM ────────────────────────────────────────────────────
$(ARM64_CROSSBUILD_STAMP): $(ARM64_CROSSBUILD_DOCKERFILE)
	mkdir -p "$(dir $(ARM64_CROSSBUILD_STAMP))"
	"$(DOCKER)" buildx build --load --platform "$(ARM64_DOCKER_PLATFORM)" \
		-f "$(ARM64_CROSSBUILD_DOCKERFILE)" -t "$(ARM64_CROSSBUILD_IMAGE)" "$(ARM64_CROSSBUILD_CONTEXT)"
	touch "$@"

arm64-crossbuild-image: $(ARM64_CROSSBUILD_STAMP)

cross-arm64:
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)" && mkdir -p "$(ARM64_CROSSBUILD_OUTPUT_DIR)"
	ARM64_CROSSBUILD_OUTPUT_DIR="$(ARM64_CROSSBUILD_OUTPUT_DIR)" \
	ARM64_CROSSBUILD_JOBS="$(ARM64_CROSSBUILD_JOBS)" \
	CROSS_COMPILE_ARM64="$(CROSS_COMPILE_ARM64)" \
	MICRO_EXEC_ENABLE_LLVMBPF="$(ARM64_CROSSBUILD_ENABLE_LLVMBPF)" \
	"$(ROOT_DIR)/runner/scripts/cross-arm64-build.sh"
	file "$(ARM64_CROSS_RUNNER_REAL)" | grep -F "ARM aarch64"
	file "$(ARM64_CROSS_DAEMON_REAL)" | grep -F "ARM aarch64"

selftest-arm64: arm64-crossbuild-image
	"$(DOCKER)" run --rm --platform "$(ARM64_DOCKER_PLATFORM)" --user "$$(id -u):$$(id -g)" \
		-v "$(ROOT_DIR)":/workspace -w /workspace \
		-e ARM64_CROSSBUILD_JOBS="$(ARM64_CROSSBUILD_JOBS)" \
		"$(ARM64_CROSSBUILD_IMAGE)" /workspace/runner/scripts/cross-arm64-selftest.sh
	file "$(ROOT_DIR)/tests/unittest/build-arm64/rejit_kinsn" | grep -F "ELF 64-bit LSB executable, ARM aarch64"
	file "$(ROOT_DIR)/tests/negative/build-arm64/adversarial_rejit" | grep -F "ELF 64-bit LSB executable, ARM aarch64"

vm-arm64-smoke: $(ARM64_IMAGE) $(ARM64_ROOTFS_DIR)/bin/sh
	$(VENV_ACTIVATE) python3 "$(ROOT_DIR)/runner/scripts/arm64_qemu_smoke.py" \
		--qemu "$(ARM64_QEMU)" --kernel "$(ARM64_IMAGE)" --rootfs "$(ARM64_ROOTFS_DIR)"

vm-arm64-selftest: $(ARM64_IMAGE) $(ARM64_ROOTFS_DIR)/bin/sh selftest-arm64
	$(VENV_ACTIVATE) python3 "$(ROOT_DIR)/runner/scripts/arm64_qemu_smoke.py" \
		--qemu "$(ARM64_QEMU)" --kernel "$(ARM64_IMAGE)" --rootfs "$(ARM64_ROOTFS_DIR)" \
		--host-share "$(ROOT_DIR)" --guest-mount "$(ARM64_REPO_GUEST_MOUNT)" \
		--command 'LD_LIBRARY_PATH="$(ARM64_REPO_GUEST_MOUNT)/tests/unittest/build-arm64/lib" "$(ARM64_REPO_GUEST_MOUNT)/runner/scripts/vm-selftest.sh" "$(ARM64_REPO_GUEST_MOUNT)" "$(ARM64_REPO_GUEST_MOUNT)/tests/unittest" "$(ARM64_REPO_GUEST_MOUNT)/module/arm64" "$(ARM64_REPO_GUEST_MOUNT)/tests/negative" "$(FUZZ_ROUNDS)" "$(ARM64_REPO_GUEST_MOUNT)/tests/unittest/build-arm64" "$(ARM64_REPO_GUEST_MOUNT)/tests/negative/build-arm64"'

# ── AWS ARM64 ─────────────────────────────────────────────────────────────────
aws-arm64-launch:
	"$(AWS_ARM64_SCRIPT)" launch
aws-arm64-setup:
	@test -n "$(INSTANCE_IP)" || (echo "ERROR: INSTANCE_IP= required" && exit 1)
	"$(AWS_ARM64_SCRIPT)" setup "$(INSTANCE_IP)"
aws-arm64-benchmark: cross-arm64
	@test -n "$(INSTANCE_IP)" || (echo "ERROR: INSTANCE_IP= required" && exit 1)
	"$(AWS_ARM64_SCRIPT)" benchmark "$(INSTANCE_IP)"
aws-arm64-terminate:
	@test -n "$(INSTANCE_ID)" || (echo "ERROR: INSTANCE_ID= required" && exit 1)
	"$(AWS_ARM64_SCRIPT)" terminate "$(INSTANCE_ID)"
aws-arm64: cross-arm64
	"$(AWS_ARM64_SCRIPT)" full

# ── AWS x86 ───────────────────────────────────────────────────────────────────
aws-x86-launch:
	"$(AWS_X86_SCRIPT)" launch
aws-x86-setup:
	@test -n "$(INSTANCE_IP)" || (echo "ERROR: INSTANCE_IP= required" && exit 1)
	"$(AWS_X86_SCRIPT)" setup "$(INSTANCE_IP)"
aws-x86-benchmark:
	@test -n "$(INSTANCE_IP)" || (echo "ERROR: INSTANCE_IP= required" && exit 1)
	"$(AWS_X86_SCRIPT)" benchmark "$(INSTANCE_IP)"
aws-x86-terminate:
	@test -n "$(INSTANCE_ID)" || (echo "ERROR: INSTANCE_ID= required" && exit 1)
	"$(AWS_X86_SCRIPT)" terminate "$(INSTANCE_ID)"
aws-x86-full:
	"$(AWS_X86_SCRIPT)" full
aws-x86: aws-x86-full

# ── Clean ──────────────────────────────────────────────────────────────────────
clean:
	$(MAKE) -C "$(RUNNER_DIR)" clean
	$(MAKE) -C "$(MICRO_DIR)" clean
	rm -f "$(MICRO_BPF_STAMP)"
	cargo clean --manifest-path "$(DAEMON_DIR)/Cargo.toml"
	$(MAKE) -C "$(KERNEL_TEST_DIR)" clean
	$(MAKE) -C "$(KERNEL_DIR)" clean
	rm -f "$(SMOKE_OUTPUT)" "$(ARM64_CONFIG_LINK)" "$(ARM64_IMAGE_LINK)"
	rm -rf "$(ARM64_BUILD_DIR)" "$(KERNEL_TEST_DIR)/build-arm64" "$(ARM64_CROSSBUILD_OUTPUT_DIR)"
