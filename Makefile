SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
MICRO_DIR := $(ROOT_DIR)/micro
RUNNER_DIR := $(ROOT_DIR)/runner
DAEMON_DIR := $(ROOT_DIR)/daemon
KERNEL_DIR := $(ROOT_DIR)/vendor/linux-framework
KERNEL_TEST_DIR := $(ROOT_DIR)/tests/kernel
ARM64_WORKTREE_DIR ?= $(ROOT_DIR)/.worktrees/linux-framework-arm64-src
ARM64_BUILD_DIR ?= $(KERNEL_DIR)/build-arm64
ARM64_BUILD_CONFIG := $(ARM64_BUILD_DIR)/.config
ARM64_IMAGE := $(ARM64_BUILD_DIR)/arch/arm64/boot/Image
ARM64_IMAGE_LINK := $(KERNEL_DIR)/arch/arm64/boot/Image
ARM64_CONFIG_LINK := $(KERNEL_DIR)/.config.arm64
ARM64_ROOTFS_DIR ?= $(HOME)/.cache/bpf-benchmark/arm64-rootfs
ARM64_ROOTFS_RELEASE ?= noble
ARM64_ROOTFS_MIRROR ?= http://ports.ubuntu.com/ubuntu-ports
ARM64_QEMU ?= qemu-system-aarch64
ARM64_SMOKE_SCRIPT := $(ROOT_DIR)/runner/scripts/arm64_qemu_smoke.py
CROSS_COMPILE_ARM64 ?= aarch64-linux-gnu-
DOCKER ?= docker
ARM64_CROSSBUILD_DOCKERFILE := $(ROOT_DIR)/runner/docker/arm64-crossbuild.Dockerfile
ARM64_CROSSBUILD_CONTEXT := $(ROOT_DIR)/runner/docker
ARM64_CROSSBUILD_IMAGE ?= bpf-benchmark-arm64-crossbuild:latest
ARM64_CROSSBUILD_STAMP := $(ROOT_DIR)/.cache/arm64-crossbuild-image.stamp
ARM64_DOCKER_PLATFORM ?= linux/arm64
ARM64_REPO_GUEST_MOUNT ?= /mnt
ARM64_SELFTEST_GUEST_ROOT ?= $(ARM64_REPO_GUEST_MOUNT)/tests/kernel
AWS_ARM64_SCRIPT := $(ROOT_DIR)/runner/scripts/aws_arm64.sh
AWS_ARM64_CACHE_DIR ?= $(ROOT_DIR)/.cache/aws-arm64
ARM64_CROSSBUILD_OUTPUT_DIR ?= $(AWS_ARM64_CACHE_DIR)/binaries
ARM64_CROSSBUILD_LIB_DIR := $(ARM64_CROSSBUILD_OUTPUT_DIR)/lib
ARM64_CROSS_RUNNER_DIR := $(ARM64_CROSSBUILD_OUTPUT_DIR)/runner/build
ARM64_CROSS_RUNNER := $(ARM64_CROSS_RUNNER_DIR)/micro_exec
ARM64_CROSS_RUNNER_REAL := $(ARM64_CROSS_RUNNER_DIR)/micro_exec.real
ARM64_CROSS_DAEMON_DIR := $(ARM64_CROSSBUILD_OUTPUT_DIR)/daemon/build
ARM64_CROSS_DAEMON := $(ARM64_CROSS_DAEMON_DIR)/bpfrejit-daemon
ARM64_CROSS_DAEMON_REAL := $(ARM64_CROSS_DAEMON_DIR)/bpfrejit-daemon.real
AWS_ARM64_NAME_TAG ?= bpf-benchmark-arm64
AWS_ARM64_INSTANCE_TYPE ?= t4g.micro
ARM64_CROSSBUILD_ENABLE_LLVMBPF ?= ON
AWS_ARM64_REMOTE_USER ?= ec2-user
AWS_ARM64_REMOTE_STAGE_DIR ?= /home/$(AWS_ARM64_REMOTE_USER)/bpf-benchmark-arm64
AWS_ARM64_REMOTE_KERNEL_STAGE_DIR ?= /home/$(AWS_ARM64_REMOTE_USER)/codex-kernel-stage
AWS_ARM64_AMI_PARAM ?= /aws/service/ami-amazon-linux-latest/al2023-ami-kernel-default-arm64
AWS_ARM64_BENCH_ITERATIONS ?= 1
AWS_ARM64_BENCH_WARMUPS ?= 0
AWS_ARM64_BENCH_REPEAT ?= 10
ARM64_CROSSBUILD_JOBS ?= 4

export AWS_REGION AWS_DEFAULT_REGION AWS_PROFILE
export AWS_ARM64_CACHE_DIR AWS_ARM64_NAME_TAG AWS_ARM64_INSTANCE_TYPE
export AWS_ARM64_REMOTE_USER AWS_ARM64_REMOTE_STAGE_DIR AWS_ARM64_REMOTE_KERNEL_STAGE_DIR
export AWS_ARM64_KEY_NAME AWS_ARM64_KEY_PATH AWS_ARM64_SECURITY_GROUP_ID AWS_ARM64_SUBNET_ID
export AWS_ARM64_AMI_PARAM AWS_ARM64_AMI_ID
export AWS_ARM64_BENCH_ITERATIONS AWS_ARM64_BENCH_WARMUPS AWS_ARM64_BENCH_REPEAT
export CROSS_COMPILE_ARM64 ARM64_BUILD_DIR ARM64_WORKTREE_DIR
export ARM64_DOCKER_PLATFORM ARM64_CROSSBUILD_OUTPUT_DIR ARM64_CROSSBUILD_JOBS

# Result directories
MICRO_RESULTS_DIR := $(ROOT_DIR)/micro/results
MICRO_RESULTS_DEV_DIR := $(MICRO_RESULTS_DIR)/dev
CORPUS_RESULTS_DIR := $(ROOT_DIR)/corpus/results
CORPUS_RESULTS_DEV_DIR := $(CORPUS_RESULTS_DIR)/dev
E2E_RESULTS_DIR := $(ROOT_DIR)/e2e/results
E2E_RESULTS_DEV_DIR := $(E2E_RESULTS_DIR)/dev
# docs/tmp is for analysis reports (.md) only, NOT for JSON results
TMP_DIR := $(ROOT_DIR)/docs/tmp

BZIMAGE ?= vendor/linux-framework/arch/x86/boot/bzImage
DAEMON ?= daemon/target/release/bpfrejit-daemon
KINSN_MODULE_DIR := $(ROOT_DIR)/module/x86
KINSN_MODULES := $(KINSN_MODULE_DIR)/bpf_rotate.ko $(KINSN_MODULE_DIR)/bpf_select.ko $(KINSN_MODULE_DIR)/bpf_extract.ko
ITERATIONS ?= 3
WARMUPS ?= 1
REPEAT ?= 100
# Auto-detect virtualenv: check common locations before falling back to system Python.
# Override with: make VENV=/path/to/venv ...
_VENV_CANDIDATES := $(HOME)/workspace/.venv $(HOME)/.venv .venv venv
_VENV_FOUND := $(firstword $(foreach v,$(_VENV_CANDIDATES),$(if $(wildcard $(v)/bin/activate),$(v),)))
VENV ?= $(_VENV_FOUND)
# Optional: pass BENCH=name1 BENCH2=name2 ... via BENCH_FILTER env var, e.g.:
#   make vm-micro BENCH=simple
#   make vm-micro BENCH="simple bitcount"
BENCH ?=

VNG ?= vng
NPROC ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
# Prevent top-level `make -B` from leaking into recursive kernel submakes.
ARM64_KERNEL_MAKEFLAGS := $(filter-out B,$(MAKEFLAGS))

BZIMAGE_PATH := $(if $(filter /%,$(BZIMAGE)),$(BZIMAGE),$(ROOT_DIR)/$(BZIMAGE))
DAEMON_PATH := $(if $(filter /%,$(DAEMON)),$(DAEMON),$(ROOT_DIR)/$(DAEMON))
MICRO_RUNNER := $(RUNNER_DIR)/build/micro_exec
KERNEL_SELFTEST := $(KERNEL_TEST_DIR)/build/test_recompile
KERNEL_SELFTEST_ARM64 := $(KERNEL_TEST_DIR)/build-arm64/test_recompile
KERNEL_SELFTEST_ARM64_LIB_DIR := $(KERNEL_TEST_DIR)/build-arm64/lib
KERNEL_TEST_BPF_BUILD_DIR := $(KERNEL_TEST_DIR)/build
KERNEL_TEST_BPF_SRCS := $(wildcard $(KERNEL_TEST_DIR)/progs/*.bpf.c)
KERNEL_TEST_BPF_OBJS := $(patsubst $(KERNEL_TEST_DIR)/progs/%.bpf.c,$(KERNEL_TEST_BPF_BUILD_DIR)/progs/%.bpf.o,$(KERNEL_TEST_BPF_SRCS))
VMLINUX_PATH := $(KERNEL_DIR)/vmlinux
KERNEL_PERF_PATH := $(KERNEL_DIR)/tools/perf/perf
UPSTREAM_SELFTESTS_BIN_DIR ?= $(ROOT_DIR)/docs/tmp/bpf_selftests_bin

# Default Makefile outputs go to results/dev/. Promote manually to the top-level
# results/ directory when a run becomes authoritative.
SMOKE_OUTPUT := $(MICRO_RESULTS_DEV_DIR)/smoke.json
VM_MICRO_SMOKE_OUTPUT := $(MICRO_RESULTS_DEV_DIR)/vm_micro_smoke.json
VM_MICRO_OUTPUT := $(MICRO_RESULTS_DEV_DIR)/vm_micro.json
VM_CORPUS_OUTPUT_JSON := $(CORPUS_RESULTS_DEV_DIR)/vm_corpus.json
VM_CORPUS_OUTPUT_MD := $(CORPUS_RESULTS_DEV_DIR)/vm_corpus.md
VM_TRACEE_OUTPUT_JSON := $(E2E_RESULTS_DEV_DIR)/tracee.json
VM_TRACEE_OUTPUT_MD := $(E2E_RESULTS_DEV_DIR)/tracee.md
VM_TETRAGON_OUTPUT_JSON := $(E2E_RESULTS_DEV_DIR)/tetragon.json
VM_TETRAGON_OUTPUT_MD := $(E2E_RESULTS_DEV_DIR)/tetragon.md
VM_BPFTRACE_OUTPUT_JSON := $(E2E_RESULTS_DEV_DIR)/bpftrace.json
VM_BPFTRACE_OUTPUT_MD := $(E2E_RESULTS_DEV_DIR)/bpftrace.md
VM_BPFTRACE_REPORT_MD := $(E2E_RESULTS_DEV_DIR)/bpftrace_report.md
VM_SCX_OUTPUT_JSON := $(E2E_RESULTS_DEV_DIR)/scx.json
VM_SCX_OUTPUT_MD := $(E2E_RESULTS_DEV_DIR)/scx.md
VM_KATRAN_OUTPUT_JSON := $(E2E_RESULTS_DEV_DIR)/katran.json
VM_KATRAN_OUTPUT_MD := $(E2E_RESULTS_DEV_DIR)/katran.md

# Build --bench flags from BENCH variable (space-separated list of benchmark names)
# e.g. make vm-micro BENCH="simple bitcount" → --bench simple --bench bitcount
BENCH_FLAGS := $(foreach b,$(BENCH),--bench $(b))

# Named policy set support: POLICY=default|all-apply|baseline
# default → micro/policies/ (canonical per-benchmark policies)
# all-apply → micro/policies/variants/all-apply/ (all sites applied, for ablation)
# baseline → micro/policies/variants/baseline/ (no sites, stock kernel)
POLICY ?= default
ifeq ($(POLICY),default)
  POLICY_DIR := $(ROOT_DIR)/micro/policies
else
  POLICY_DIR := $(ROOT_DIR)/micro/policies/variants/$(POLICY)
endif
# Pass --policy-dir only when a non-default policy is requested
POLICY_DIR_FLAG := $(if $(filter-out default,$(POLICY)),--policy-dir "$(POLICY_DIR)",)

# Shell snippet to load kinsn kernel modules inside VM (best-effort, ignores errors if already loaded or missing).
LOAD_KINSN_MODULES := for ko in "$(KINSN_MODULE_DIR)/bpf_rotate.ko" "$(KINSN_MODULE_DIR)/bpf_select.ko" "$(KINSN_MODULE_DIR)/bpf_extract.ko"; do \
		if [ -f "$$ko" ]; then sudo -n insmod "$$ko" 2>/dev/null || true; fi; \
	done; \
	echo "kinsn modules: $$(ls /sys/kernel/btf/bpf_rotate /sys/kernel/btf/bpf_select /sys/kernel/btf/bpf_extract 2>/dev/null | wc -l)/3 loaded";

MICRO_ARGS := --iterations $(ITERATIONS) --warmups $(WARMUPS) --repeat $(REPEAT) $(BENCH_FLAGS)
LOCAL_SMOKE_ARGS := --bench simple --iterations 1 --warmups 0 --repeat 10
VM_SMOKE_ARGS := --bench simple --bench load_byte_recompose --bench cmov_dense --iterations 1 --warmups 0 --repeat 10
VENV_ACTIVATE := $(if $(VENV),source "$(VENV)/bin/activate" &&,)

# File-based dependency sources (for proper incremental rebuilds)
MICRO_RUNNER_SOURCES := $(wildcard \
	$(RUNNER_DIR)/src/*.cpp \
	$(RUNNER_DIR)/include/*.hpp \
	$(RUNNER_DIR)/CMakeLists.txt)
MICRO_BPF_SOURCES := $(wildcard \
	$(MICRO_DIR)/programs/*.bpf.c \
	$(MICRO_DIR)/programs/common.h)
DAEMON_SOURCES := $(wildcard \
	$(DAEMON_DIR)/src/*.rs \
	$(DAEMON_DIR)/Cargo.toml \
	$(DAEMON_DIR)/Cargo.lock)
KERNEL_JIT_SOURCES := \
	$(KERNEL_DIR)/arch/x86/net/bpf_jit_comp.c \
	$(KERNEL_DIR)/kernel/bpf/syscall.c \
	$(KERNEL_DIR)/kernel/bpf/verifier.c \
	$(KERNEL_DIR)/kernel/bpf/trampoline.c \
	$(KERNEL_DIR)/kernel/bpf/dispatcher.c
# Stamp file for BPF program objects (programs/ has no separate build dir)
MICRO_BPF_STAMP := $(MICRO_DIR)/programs/.build.stamp

.PHONY: all runner micro daemon kernel kernel-perf kernel-arm64 kernel-tests kernel-test-progs \
	arm64-crossbuild-image selftest-arm64 daemon-tests unittest-tests python-tests clean kinsn-modules \
	smoke check validate verify-build compare \
	vm-selftest vm-upstream-test-verifier vm-upstream-test-progs \
	vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all \
	vm-arm64-smoke vm-arm64-selftest arm64-worktree arm64-rootfs \
	cross-arm64 \
	aws-arm64-launch aws-arm64-setup aws-arm64-benchmark aws-arm64-terminate aws-arm64 \
	help

help:
	@echo "=== BPF Benchmark Suite ==="
	@echo ""
	@echo "Build targets:"
	@echo "  make all              - Build micro runner, daemon, and kernel tests"
	@echo "  make runner           - Build micro_exec runner"
	@echo "  make micro            - Build micro_exec runner and BPF programs"
	@echo "  make daemon           - Build bpfrejit-daemon"
	@echo "  make kernel           - Build kernel bzImage"
	@echo "  make kernel-perf      - Build kernel-matched perf from vendor/linux-framework/tools/perf"
	@echo "  make kernel-arm64     - Cross-build ARM64 Image under vendor/linux-framework/build-arm64"
	@echo "  make kernel-tests     - Build kernel recompile test binary"
	@echo "  make arm64-crossbuild-image - Build the Docker image for ARM64 userspace cross-builds"
	@echo "  make cross-arm64      - Build AL2023-compatible ARM64 micro_exec + daemon via Docker"
	@echo "  make selftest-arm64   - Cross-build the ARM64 kernel selftest binary via Docker"
	@echo ""
	@echo "Test/smoke targets:"
	@echo "  make smoke            - Quick llvmbpf smoke test (no VM)"
	@echo "  make check            - Build + daemon tests + smoke"
	@echo "  make validate         - check + vm-selftest + vm-micro-smoke"
	@echo "  make unittest-tests   - Build+run tests/unittest/ (requires VM + REJIT kernel)"
	@echo "  make python-tests     - Run Python unit tests (no VM needed)"
	@echo "  make vm-arm64-smoke   - Boot ARM64 kernel in qemu-system-aarch64 and run uname/bpf_jit smoke"
	@echo "  make vm-arm64-selftest - Boot ARM64 QEMU and run the ARM64 test_recompile selftest"
	@echo ""
	@echo "AWS ARM64 targets (require configured AWS CLI + EC2 networking/key vars):"
	@echo "  make aws-arm64-launch - Launch or reuse tagged $(AWS_ARM64_INSTANCE_TYPE) instance and record state"
	@echo "  make aws-arm64-setup INSTANCE_IP=x - Upload/install ARM64 kernel + modules, reboot, verify"
	@echo "  make aws-arm64-benchmark INSTANCE_IP=x - Build/upload ARM64 binaries and run bare-metal smoke"
	@echo "  make aws-arm64-terminate INSTANCE_ID=i-xxx - Terminate instance and clear cached state"
	@echo "  make aws-arm64       - Full lifecycle: local cross-build -> launch -> setup -> benchmark -> terminate"
	@echo ""
	@echo "Benchmark targets (require VM):"
	@echo "  make vm-selftest      - Run kernel recompile selftests in VM"
	@echo "  make vm-upstream-test-verifier  - Run upstream BPF test_verifier in VM (526 tests, JIT/verifier)"
	@echo "  make vm-upstream-test-progs [BPF_SELFTEST_FILTER=\"verifier jit xdp\"]"
	@echo "                        - Run upstream test_progs in VM (filter: BPF_SELFTEST_FILTER)"
	@echo "  make vm-micro-smoke   - Quick kernel+recompile smoke in VM"
	@echo "  make vm-micro         - Full micro benchmark suite in VM"
	@echo "  make vm-corpus        - Corpus benchmark in VM"
	@echo "  make vm-e2e           - E2E benchmarks (tracee/tetragon/bpftrace/scx/katran) in VM"
	@echo "  make vm-all           - All VM benchmarks"
	@echo ""
	@echo "Utility targets:"
	@echo "  make verify-build     - Verify bzImage, daemon, micro_exec artifacts exist"
	@echo "  make compare OLD=a.json NEW=b.json  - Compare two result JSON files"
	@echo ""
	@echo "Tunable parameters:"
	@echo "  ITERATIONS=N          - JIT iterations (default: 3)"
	@echo "  WARMUPS=N             - Warmup iterations (default: 1)"
	@echo "  REPEAT=N              - Repeat count (default: 100)"
	@echo "  BENCH=\"name1 name2\"   - Run only specific benchmarks (vm-micro)"
	@echo "  BZIMAGE=path          - Custom kernel image path"
	@echo "  CROSS_COMPILE_ARM64=  - ARM64 cross-compiler prefix (default: aarch64-linux-gnu-)"
	@echo "  ARM64_ROOTFS_DIR=     - ARM64 guest rootfs path (default: $$HOME/.cache/bpf-benchmark/arm64-rootfs)"
	@echo "  DOCKER=cmd            - Container engine command (default: docker)"
	@echo "  ARM64_CROSSBUILD_OUTPUT_DIR= - Local ARM64 userspace artifact dir (default: $(ARM64_CROSSBUILD_OUTPUT_DIR))"
	@echo "  POLICY=name           - Named policy set (default: default)"
	@echo "                          default  → micro/policies/"
	@echo "                          all-apply → micro/policies/variants/all-apply/"
	@echo "                          baseline → micro/policies/variants/baseline/"
	@echo "  AWS_ARM64_KEY_NAME=   - EC2 key pair name for launch"
	@echo "  AWS_ARM64_KEY_PATH=   - Local SSH private key for setup/benchmark"
	@echo "  AWS_ARM64_SECURITY_GROUP_ID= / AWS_ARM64_SUBNET_ID= - Required for launch"
	@echo "  AWS_REGION=           - AWS region for EC2/SSM/STS"
	@echo "  AWS_ARM64_INSTANCE_TYPE= - EC2 instance type (default: $(AWS_ARM64_INSTANCE_TYPE))"
	@echo "  AWS_ARM64_BENCH_ITERATIONS/WARMUPS/REPEAT - Remote smoke params (default: 1/0/10)"
	@echo ""
	@echo "Results are written to:"
	@echo "  micro/results/dev/    - Default Makefile micro outputs"
	@echo "  corpus/results/dev/   - Default Makefile corpus outputs"
	@echo "  e2e/results/dev/      - Default Makefile E2E outputs"
	@echo "  */results/            - Authoritative JSON promoted manually"
	@echo "  docs/tmp/             - Analysis reports (.md only)"
	@echo "  $(AWS_ARM64_CACHE_DIR)/results/ - AWS ARM64 smoke JSON/log bundles"
	@echo ""
	@echo "See docs/tmp/aws_arm64_benchmark_20260319.md for the current AWS ARM64 workflow/state."

verify-build:
	@test -f "$(BZIMAGE_PATH)" || (echo "ERROR: bzImage not found at $(BZIMAGE_PATH). Run: make kernel" && exit 1)
	@test -f "$(MICRO_RUNNER)" || (echo "ERROR: micro_exec not found. Run: make micro" && exit 1)
	@test -f "$(DAEMON_PATH)" || (echo "ERROR: daemon not found. Run: make daemon" && exit 1)
	@# Check if kernel source is newer than bzImage (stale build detection)
	@if [ "$$(find "$(KERNEL_DIR)/arch/x86/net/bpf_jit_comp.c" "$(KERNEL_DIR)/kernel/bpf/syscall.c" "$(KERNEL_DIR)/kernel/bpf/verifier.c" "$(KERNEL_DIR)/kernel/bpf/trampoline.c" "$(KERNEL_DIR)/kernel/bpf/dispatcher.c" -newer "$(BZIMAGE_PATH)" 2>/dev/null | head -1)" ]; then \
		echo "WARNING: kernel source is newer than bzImage — consider: make kernel"; \
	fi
	@# Check if daemon source is newer than binary
	@if [ "$$(find "$(DAEMON_DIR)/src/" -name '*.rs' -newer "$(DAEMON_PATH)" 2>/dev/null | head -1)" ]; then \
		echo "WARNING: daemon source is newer than binary — consider: make daemon"; \
	fi
	@echo "Kernel:     $$(cd "$(KERNEL_DIR)" && git rev-parse --short HEAD 2>/dev/null || echo 'n/a')"
	@echo "Daemon:     $$(ls -la "$(DAEMON_PATH)" 2>/dev/null | awk '{print $$6,$$7,$$8}' || echo 'not built')"
	@echo "micro_exec: $$(ls -la "$(MICRO_RUNNER)" 2>/dev/null | awk '{print $$6,$$7,$$8}' || echo 'not built')"
	@echo "bzImage:    $$(ls -lh "$(BZIMAGE_PATH)" | awk '{print $$5, $$6, $$7, $$8}')"
	@echo "POLICY:     $(POLICY) (dir: $(POLICY_DIR))"
	@echo "[verify-build] OK"

# Compare two result JSON files: make compare OLD=path/to/old.json NEW=path/to/new.json
compare:
	@test -n "$(OLD)" || (echo "ERROR: OLD= required. Usage: make compare OLD=a.json NEW=b.json" && exit 1)
	@test -n "$(NEW)" || (echo "ERROR: NEW= required. Usage: make compare OLD=a.json NEW=b.json" && exit 1)
	$(VENV_ACTIVATE) python3 "$(MICRO_DIR)/compare_results.py" "$(OLD)" "$(NEW)"

all:
	@echo "=== Running make all ==="
	$(MAKE) micro
	$(MAKE) daemon
	$(MAKE) kernel-tests

# PHONY build targets (for manual invocation / forced rebuild)
micro:
	@echo "=== Running make micro ==="
	$(MAKE) runner
	$(MAKE) -C "$(MICRO_DIR)" programs

runner:
	@echo "=== Running make runner ==="
	$(MAKE) -C "$(RUNNER_DIR)" micro_exec

daemon:
	@echo "=== Running make daemon ==="
	cargo build --release --manifest-path "$(DAEMON_DIR)/Cargo.toml"

kinsn-modules:
	@echo "=== Running make kinsn-modules ==="
	$(MAKE) -C "$(KINSN_MODULE_DIR)" KDIR="$(KERNEL_DIR)"

kernel:
	@echo "=== Running make kernel ==="
	$(MAKE) -C "$(KERNEL_DIR)" -j"$(NPROC)" bzImage

kernel-perf:
	@echo "=== Running make kernel-perf ==="
	$(MAKE) -C "$(KERNEL_DIR)/tools/perf" \
		ARCH=x86 \
		NO_LIBPYTHON=1 \
		NO_LIBPERF_TEST=1 \
		perf -j"$(NPROC)"
	@test -x "$(KERNEL_PERF_PATH)" || (echo "ERROR: perf not found at $(KERNEL_PERF_PATH)" && exit 1)

arm64-worktree:
	@mkdir -p "$(dir $(ARM64_WORKTREE_DIR))"
	@if [ ! -e "$(ARM64_WORKTREE_DIR)/.git" ]; then \
		git -C "$(KERNEL_DIR)" worktree add --detach "$(ARM64_WORKTREE_DIR)" "$$(git -C "$(KERNEL_DIR)" rev-parse HEAD)"; \
	else \
		git -C "$(ARM64_WORKTREE_DIR)" checkout --detach "$$(git -C "$(KERNEL_DIR)" rev-parse HEAD)" >/dev/null; \
	fi

$(ARM64_BUILD_CONFIG): | arm64-worktree
	@echo "=== Generating ARM64 kernel config ==="
	mkdir -p "$(ARM64_BUILD_DIR)"
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(ARM64_WORKTREE_DIR)" O="$(ARM64_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" defconfig
	"$(ARM64_WORKTREE_DIR)/scripts/config" --file "$(ARM64_BUILD_CONFIG)" \
		-e BPF -e BPF_SYSCALL -e BPF_JIT \
		-e VIRTIO -e VIRTIO_BLK -e VIRTIO_NET \
		-e NET_9P -e 9P_FS -e NET_9P_VIRTIO \
		-e PCI -e VIRTIO_PCI -e VIRTIO_MMIO \
		-e BLK_DEV_INITRD -e DEVTMPFS -e DEVTMPFS_MOUNT \
		-e TMPFS -e TMPFS_POSIX_ACL \
		-e SERIAL_AMBA_PL011 -e SERIAL_AMBA_PL011_CONSOLE
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(ARM64_WORKTREE_DIR)" O="$(ARM64_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" olddefconfig
	ln -sfn build-arm64/.config "$(ARM64_CONFIG_LINK)"

$(ARM64_IMAGE): $(ARM64_BUILD_CONFIG) | arm64-worktree
	@echo "=== Building ARM64 Image ==="
	MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" $(MAKE) -C "$(ARM64_WORKTREE_DIR)" O="$(ARM64_BUILD_DIR)" \
		ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" Image -j"$(NPROC)"
	ln -sfn ../../../build-arm64/arch/arm64/boot/Image "$(ARM64_IMAGE_LINK)"

kernel-arm64: $(ARM64_IMAGE)
	ln -sfn build-arm64/.config "$(ARM64_CONFIG_LINK)"
	ln -sfn ../../../build-arm64/arch/arm64/boot/Image "$(ARM64_IMAGE_LINK)"
	@echo "ARM64 config: $(ARM64_CONFIG_LINK)"
	@echo "ARM64 Image:  $(ARM64_IMAGE_LINK)"

kernel-tests:
	@echo "=== Running make kernel-tests ==="
	$(MAKE) -C "$(KERNEL_TEST_DIR)"

kernel-test-progs:
	@echo "=== Building kernel test BPF objects ==="
	$(MAKE) -C "$(KERNEL_TEST_DIR)" BPF_BUILD_DIR="$(KERNEL_TEST_BPF_BUILD_DIR)" $(KERNEL_TEST_BPF_OBJS)

daemon-tests:
	@echo "=== Running daemon tests ==="
	cargo test --manifest-path "$(DAEMON_DIR)/Cargo.toml"

# File-based targets for incremental rebuilds (used by vm-* targets)
$(MICRO_RUNNER): $(MICRO_RUNNER_SOURCES)
	@echo "=== Building micro_exec (sources changed) ==="
	$(MAKE) -C "$(RUNNER_DIR)" micro_exec

$(MICRO_BPF_STAMP): $(MICRO_BPF_SOURCES)
	@echo "=== Building BPF programs (sources changed) ==="
	$(MAKE) -C "$(MICRO_DIR)" programs
	touch "$@"

$(DAEMON_PATH): $(DAEMON_SOURCES)
	@echo "=== Building bpfrejit-daemon (sources changed) ==="
	cargo build --release --manifest-path "$(DAEMON_DIR)/Cargo.toml"

$(BZIMAGE_PATH): $(KERNEL_JIT_SOURCES)
	@echo "=== Building bzImage (kernel sources changed) ==="
	$(MAKE) -C "$(KERNEL_DIR)" -j"$(NPROC)" bzImage

$(ARM64_ROOTFS_DIR)/bin/sh:
	@echo "=== Preparing ARM64 rootfs ($(ARM64_ROOTFS_RELEASE)) ==="
	sudo mkdir -p "$(dir $(ARM64_ROOTFS_DIR))"
	sudo rm -rf "$(ARM64_ROOTFS_DIR)"
	sudo qemu-debootstrap --arch=arm64 --variant=minbase "$(ARM64_ROOTFS_RELEASE)" \
		"$(ARM64_ROOTFS_DIR)" "$(ARM64_ROOTFS_MIRROR)"

arm64-rootfs: $(ARM64_ROOTFS_DIR)/bin/sh
	@echo "ARM64 rootfs: $(ARM64_ROOTFS_DIR)"

$(ARM64_CROSSBUILD_STAMP): $(ARM64_CROSSBUILD_DOCKERFILE)
	@echo "=== Building ARM64 crossbuild image ($(ARM64_CROSSBUILD_IMAGE)) ==="
	mkdir -p "$(dir $(ARM64_CROSSBUILD_STAMP))"
	"$(DOCKER)" buildx build --load --platform "$(ARM64_DOCKER_PLATFORM)" \
		-f "$(ARM64_CROSSBUILD_DOCKERFILE)" -t "$(ARM64_CROSSBUILD_IMAGE)" "$(ARM64_CROSSBUILD_CONTEXT)"
	touch "$@"

arm64-crossbuild-image: $(ARM64_CROSSBUILD_STAMP)
	@echo "ARM64 crossbuild image: $(ARM64_CROSSBUILD_IMAGE)"

cross-arm64: arm64-crossbuild-image
	@echo "=== Running make cross-arm64 ==="
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)"
	mkdir -p "$(ARM64_CROSSBUILD_OUTPUT_DIR)"
	"$(DOCKER)" run --rm \
		--platform "$(ARM64_DOCKER_PLATFORM)" \
		--user "$$(id -u):$$(id -g)" \
		-v "$(ROOT_DIR)":/workspace \
		-v "$(ARM64_CROSSBUILD_OUTPUT_DIR)":/out \
		-w /workspace \
		"$(ARM64_CROSSBUILD_IMAGE)" \
		bash -lc 'set -euo pipefail; \
			build_root=/tmp/bpf-benchmark-arm64; \
			runner_build="$$build_root/runner"; \
			daemon_build="$$build_root/daemon"; \
			rm -rf "$$build_root"; \
			mkdir -p /out/runner/build /out/daemon/build /out/lib; \
				export CMAKE_BUILD_PARALLEL_LEVEL="$(ARM64_CROSSBUILD_JOBS)"; \
				make -C /workspace/runner \
					BUILD_DIR="$$runner_build" \
					MICRO_EXEC_ENABLE_LLVMBPF=$(ARM64_CROSSBUILD_ENABLE_LLVMBPF) \
					micro_exec >/dev/null; \
			cmake -S /workspace/daemon -B "$$daemon_build" \
				-DCMAKE_BUILD_TYPE=Release \
				-DBPF_REJIT_DAEMON_BUILD_CLI=ON \
				-DBPF_REJIT_DAEMON_BUILD_TESTS=OFF >/dev/null; \
			cmake --build "$$daemon_build" --target bpfrejit-daemon -j"$(ARM64_CROSSBUILD_JOBS)" >/dev/null; \
			cp "$$runner_build/micro_exec" /out/runner/build/micro_exec.real; \
			cp "$$daemon_build/bpfrejit-daemon" /out/daemon/build/bpfrejit-daemon.real; \
			copy_runtime_libs() { \
				local binary="$$1"; \
				local lib; \
				while read -r lib; do \
					case "$$(basename "$$lib")" in \
						libyaml-cpp.so*|libelf.so*|libz.so*|libzstd.so*|libstdc++.so*|libgcc_s.so*|libbpf.so*) \
							cp -L "$$lib" /out/lib/ ;; \
					esac; \
				done < <(ldd "$$binary" | awk '\''/=> \// {print $$3} /^\// {print $$1}'\'' | sort -u); \
			}; \
			copy_runtime_libs /out/runner/build/micro_exec.real; \
			copy_runtime_libs /out/daemon/build/bpfrejit-daemon.real; \
			printf '\''%s\n'\'' \
				'\''#!/usr/bin/env bash'\'' \
				'\''set -euo pipefail'\'' \
				'\''SCRIPT_DIR="$$(cd "$$(dirname "$${BASH_SOURCE[0]}")" && pwd)"'\'' \
				'\''BUNDLE_ROOT="$$(cd "$$SCRIPT_DIR/../.." && pwd)"'\'' \
				'\''LIB_DIR="$$BUNDLE_ROOT/lib"'\'' \
				'\''export LD_LIBRARY_PATH="$$LIB_DIR$${LD_LIBRARY_PATH:+:$$LD_LIBRARY_PATH}"'\'' \
				'\''exec "$$SCRIPT_DIR/micro_exec.real" "$$@"'\'' \
				> /out/runner/build/micro_exec; \
			printf '\''%s\n'\'' \
				'\''#!/usr/bin/env bash'\'' \
				'\''set -euo pipefail'\'' \
				'\''SCRIPT_DIR="$$(cd "$$(dirname "$${BASH_SOURCE[0]}")" && pwd)"'\'' \
				'\''BUNDLE_ROOT="$$(cd "$$SCRIPT_DIR/../.." && pwd)"'\'' \
				'\''LIB_DIR="$$BUNDLE_ROOT/lib"'\'' \
				'\''export LD_LIBRARY_PATH="$$LIB_DIR$${LD_LIBRARY_PATH:+:$$LD_LIBRARY_PATH}"'\'' \
				'\''exec "$$SCRIPT_DIR/bpfrejit-daemon.real" "$$@"'\'' \
				> /out/daemon/build/bpfrejit-daemon; \
			chmod +x /out/runner/build/micro_exec /out/daemon/build/bpfrejit-daemon; \
			file /out/runner/build/micro_exec.real; \
			file /out/daemon/build/bpfrejit-daemon.real'
	file "$(ARM64_CROSS_RUNNER_REAL)" | grep -F "ARM aarch64"
	file "$(ARM64_CROSS_DAEMON_REAL)" | grep -F "ARM aarch64"
	@echo "ARM64 runner: $(ARM64_CROSS_RUNNER)"
	@echo "ARM64 daemon: $(ARM64_CROSS_DAEMON)"

smoke: $(MICRO_RUNNER) $(MICRO_BPF_STAMP)
	@echo "=== Running make smoke ==="
	mkdir -p "$(MICRO_RESULTS_DEV_DIR)"
	$(VENV_ACTIVATE) python3 "$(MICRO_DIR)/driver.py" suite \
		--runtime llvmbpf \
		$(LOCAL_SMOKE_ARGS) \
		--output "$(SMOKE_OUTPUT)"
	@python3 -c 'import json, pathlib; payload = json.loads(pathlib.Path("$(SMOKE_OUTPUT)").read_text()); bench = payload["benchmarks"][0]; run = bench["runs"][0]; result = next(iter(run["result_distribution"]), "?"); print("SMOKE OK: {} {} exec {:.0f} ns, compile {:.3f} ms, result {}".format(bench["name"], run["runtime"], float(run["exec_ns"]["median"]), float(run["compile_ns"]["median"]) / 1e6, result))'

unittest-tests:
	@echo "=== Running make unittest-tests ==="
	$(MAKE) -C tests/unittest run

python-tests:
	@echo "=== Running Python unit tests ==="
	$(VENV_ACTIVATE) python3 -m pytest tests/python/ -v

check:
	@echo "=== Running make check ==="
	$(MAKE) all
	$(MAKE) daemon-tests
	$(MAKE) python-tests
	$(MAKE) smoke

validate:
	@echo "=== Running make validate ==="
	$(MAKE) check
	$(MAKE) vm-selftest
	$(MAKE) vm-micro-smoke

vm-selftest: kernel-tests $(BZIMAGE_PATH)
	@echo "=== Running make vm-selftest ==="
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(LOAD_KINSN_MODULES) sudo -n "$(KERNEL_SELFTEST)"'

# Upstream BPF selftests (test_verifier and test_progs) for REJIT regression testing.
# test_verifier: 526 tests, covers JIT, verifier, atomic ops.
# test_progs: full upstream suite (422 test groups), run with -t filter for JIT/verifier subset.
# Binaries must be pre-built; see docs/tmp/kernel_selftest_setup_20260322.md for build instructions.
UPSTREAM_TEST_VERIFIER_BIN := $(UPSTREAM_SELFTESTS_BIN_DIR)/test_verifier
UPSTREAM_TEST_PROGS_BIN    := $(UPSTREAM_SELFTESTS_BIN_DIR)/test_progs
BPF_SELFTEST_FILTER ?= verifier jit

vm-upstream-test-verifier: $(BZIMAGE_PATH)
	@echo "=== Running upstream test_verifier in VM ==="
	@test -f "$(UPSTREAM_TEST_VERIFIER_BIN)" || (echo "ERROR: test_verifier not found at $(UPSTREAM_TEST_VERIFIER_BIN). See docs/tmp/kernel_selftest_setup_20260322.md" && exit 1)
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -m 2G -- \
		bash -c 'cd "$(UPSTREAM_SELFTESTS_BIN_DIR)" && sudo ./test_verifier 2>&1'

vm-upstream-test-progs: $(BZIMAGE_PATH)
	@echo "=== Running upstream test_progs (filter: $(BPF_SELFTEST_FILTER)) in VM ==="
	@test -f "$(UPSTREAM_TEST_PROGS_BIN)" || (echo "ERROR: test_progs not found at $(UPSTREAM_TEST_PROGS_BIN). See docs/tmp/kernel_selftest_setup_20260322.md" && exit 1)
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -m 4G -- \
		bash -c 'cd "$(UPSTREAM_SELFTESTS_BIN_DIR)" && sudo ./test_progs $(foreach t,$(BPF_SELFTEST_FILTER),-t $(t)) 2>&1'

vm-micro-smoke: $(MICRO_RUNNER) $(MICRO_BPF_STAMP) $(BZIMAGE_PATH)
	@echo "=== Running make vm-micro-smoke (POLICY=$(POLICY)) ==="
	mkdir -p "$(MICRO_RESULTS_DEV_DIR)"
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(LOAD_KINSN_MODULES) \
			$(VENV_ACTIVATE) python3 "$(MICRO_DIR)/driver.py" suite \
			--runtime kernel \
			--runtime kernel-rejit \
			$(VM_SMOKE_ARGS) \
			$(POLICY_DIR_FLAG) \
			--output "$(VM_MICRO_SMOKE_OUTPUT)"'

# Run the full micro benchmark suite in a VM.
# To run only specific benchmarks: make vm-micro BENCH="simple bitcount"
# To use a named policy set: make vm-micro POLICY=all-apply
vm-micro: $(MICRO_RUNNER) $(MICRO_BPF_STAMP) $(DAEMON_PATH) verify-build $(BZIMAGE_PATH)
	@echo "=== Running make vm-micro (POLICY=$(POLICY)) ==="
	mkdir -p "$(MICRO_RESULTS_DEV_DIR)"
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(LOAD_KINSN_MODULES) \
			$(VENV_ACTIVATE) python3 "$(MICRO_DIR)/driver.py" suite \
			--runtime llvmbpf \
			--runtime kernel \
			--runtime kernel-rejit \
			--daemon-path "$(DAEMON_PATH)" \
			$(MICRO_ARGS) \
			$(POLICY_DIR_FLAG) \
			--output "$(VM_MICRO_OUTPUT)"'

# The corpus batch harness already manages one vng boot per target internally.
vm-corpus: $(MICRO_RUNNER) $(DAEMON_PATH) verify-build $(BZIMAGE_PATH)
	@echo "=== Running make vm-corpus ==="
	mkdir -p "$(CORPUS_RESULTS_DEV_DIR)"
	$(VENV_ACTIVATE) python3 "$(ROOT_DIR)/corpus/driver.py" packet \
		--skip-build \
		--kernel-image "$(BZIMAGE_PATH)" \
		--runner "$(MICRO_RUNNER)" \
		--scanner "$(DAEMON_PATH)" \
		--btf-custom-path "$(VMLINUX_PATH)" \
		--repeat "$(REPEAT)" \
		--use-policy \
		--output-json "$(VM_CORPUS_OUTPUT_JSON)" \
		--output-md "$(VM_CORPUS_OUTPUT_MD)"

vm-e2e: $(MICRO_RUNNER) $(DAEMON_PATH) verify-build $(BZIMAGE_PATH)
	@echo "=== Running make vm-e2e ==="
	mkdir -p "$(E2E_RESULTS_DEV_DIR)"
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(VENV_ACTIVATE) python3 "$(ROOT_DIR)/e2e/run.py" tracee \
			--output-json "$(VM_TRACEE_OUTPUT_JSON)" \
			--output-md "$(VM_TRACEE_OUTPUT_MD)"'
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(VENV_ACTIVATE) python3 "$(ROOT_DIR)/e2e/run.py" tetragon \
			--output-json "$(VM_TETRAGON_OUTPUT_JSON)" \
			--output-md "$(VM_TETRAGON_OUTPUT_MD)"'
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(VENV_ACTIVATE) python3 "$(ROOT_DIR)/e2e/run.py" bpftrace \
			--skip-build \
			--output-json "$(VM_BPFTRACE_OUTPUT_JSON)" \
			--output-md "$(VM_BPFTRACE_OUTPUT_MD)" \
			--report-md "$(VM_BPFTRACE_REPORT_MD)"'
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(VENV_ACTIVATE) python3 "$(ROOT_DIR)/e2e/run.py" scx \
			--output-json "$(VM_SCX_OUTPUT_JSON)" \
			--output-md "$(VM_SCX_OUTPUT_MD)"'
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(VENV_ACTIVATE) python3 "$(ROOT_DIR)/e2e/run.py" katran \
			--output-json "$(VM_KATRAN_OUTPUT_JSON)" \
			--output-md "$(VM_KATRAN_OUTPUT_MD)"'

vm-all:
	@echo "=== Running make vm-all ==="
	$(MAKE) vm-selftest
	$(MAKE) vm-micro
	$(MAKE) vm-corpus
	$(MAKE) vm-e2e

selftest-arm64: arm64-crossbuild-image kernel-test-progs
	@echo "=== Running make selftest-arm64 ==="
	mkdir -p "$(dir $(KERNEL_SELFTEST_ARM64))" "$(KERNEL_SELFTEST_ARM64_LIB_DIR)"
	"$(DOCKER)" run --rm \
		--platform "$(ARM64_DOCKER_PLATFORM)" \
		--user "$$(id -u):$$(id -g)" \
		-v "$(ROOT_DIR)":/workspace \
		-w /workspace \
		"$(ARM64_CROSSBUILD_IMAGE)" \
		bash -lc 'set -eu -o pipefail; \
			make -C "/workspace/tests/kernel" \
				RUNNER_BUILD_DIR="/workspace/tests/kernel/build-arm64" \
				BPF_BUILD_DIR="/workspace/tests/kernel/build" \
				LIBBPF_BUILD_DIR="/workspace/tests/kernel/build-arm64/vendor/libbpf" \
				TEST_KERNEL_ROOT="$(ARM64_SELFTEST_GUEST_ROOT)" \
				CC=gcc \
				AR=ar \
				CFLAGS="-O2 -g -Wall -Wextra -no-pie" \
				PKG_CONFIG=pkg-config \
				"/workspace/tests/kernel/build-arm64/test_recompile"; \
			cp -L /usr/lib64/libelf.so.1 "/workspace/tests/kernel/build-arm64/lib/libelf.so.1"; \
			cp -L /usr/lib64/libz.so.1 "/workspace/tests/kernel/build-arm64/lib/libz.so.1"; \
			cp -L /usr/lib64/libzstd.so.1 "/workspace/tests/kernel/build-arm64/lib/libzstd.so.1";'
	file "$(KERNEL_SELFTEST_ARM64)"
	file "$(KERNEL_SELFTEST_ARM64)" | grep -F "ELF 64-bit LSB executable, ARM aarch64"

vm-arm64-smoke: $(ARM64_IMAGE) $(ARM64_ROOTFS_DIR)/bin/sh $(ARM64_SMOKE_SCRIPT)
	@echo "=== Running make vm-arm64-smoke ==="
	$(VENV_ACTIVATE) python3 "$(ARM64_SMOKE_SCRIPT)" \
		--qemu "$(ARM64_QEMU)" \
		--kernel "$(ARM64_IMAGE)" \
		--rootfs "$(ARM64_ROOTFS_DIR)"

vm-arm64-selftest: $(ARM64_IMAGE) $(ARM64_ROOTFS_DIR)/bin/sh $(ARM64_SMOKE_SCRIPT) selftest-arm64
	@echo "=== Running make vm-arm64-selftest ==="
	$(VENV_ACTIVATE) python3 "$(ARM64_SMOKE_SCRIPT)" \
		--qemu "$(ARM64_QEMU)" \
		--kernel "$(ARM64_IMAGE)" \
		--rootfs "$(ARM64_ROOTFS_DIR)" \
		--host-share "$(ROOT_DIR)" \
		--guest-mount "$(ARM64_REPO_GUEST_MOUNT)" \
		--command 'mount -t tmpfs tmpfs /tmp' \
		--command 'mkdir -p /tmp/selftest /tmp/selftest/lib' \
		--command 'cp "$(ARM64_REPO_GUEST_MOUNT)/tests/kernel/build-arm64/test_recompile" /tmp/selftest/test_recompile' \
		--command 'cp -a "$(ARM64_REPO_GUEST_MOUNT)/tests/kernel/build-arm64/lib/." /tmp/selftest/lib/' \
		--command 'chmod +x /tmp/selftest/test_recompile' \
		--command 'LD_LIBRARY_PATH=/tmp/selftest/lib /tmp/selftest/test_recompile'

aws-arm64-launch:
	@echo "=== Running make aws-arm64-launch ==="
	@test -x "$(AWS_ARM64_SCRIPT)" || (echo "ERROR: missing executable $(AWS_ARM64_SCRIPT)" && exit 1)
	"$(AWS_ARM64_SCRIPT)" launch

aws-arm64-setup:
	@echo "=== Running make aws-arm64-setup ==="
	@test -n "$(INSTANCE_IP)" || (echo "ERROR: INSTANCE_IP= required. Usage: make aws-arm64-setup INSTANCE_IP=1.2.3.4" && exit 1)
	@test -x "$(AWS_ARM64_SCRIPT)" || (echo "ERROR: missing executable $(AWS_ARM64_SCRIPT)" && exit 1)
	"$(AWS_ARM64_SCRIPT)" setup "$(INSTANCE_IP)"

aws-arm64-benchmark: cross-arm64
	@echo "=== Running make aws-arm64-benchmark ==="
	@test -n "$(INSTANCE_IP)" || (echo "ERROR: INSTANCE_IP= required. Usage: make aws-arm64-benchmark INSTANCE_IP=1.2.3.4" && exit 1)
	@test -x "$(AWS_ARM64_SCRIPT)" || (echo "ERROR: missing executable $(AWS_ARM64_SCRIPT)" && exit 1)
	"$(AWS_ARM64_SCRIPT)" benchmark "$(INSTANCE_IP)"

aws-arm64-terminate:
	@echo "=== Running make aws-arm64-terminate ==="
	@test -n "$(INSTANCE_ID)" || (echo "ERROR: INSTANCE_ID= required. Usage: make aws-arm64-terminate INSTANCE_ID=i-0123456789abcdef0" && exit 1)
	@test -x "$(AWS_ARM64_SCRIPT)" || (echo "ERROR: missing executable $(AWS_ARM64_SCRIPT)" && exit 1)
	"$(AWS_ARM64_SCRIPT)" terminate "$(INSTANCE_ID)"

aws-arm64: cross-arm64
	@echo "=== Running make aws-arm64 ==="
	@test -x "$(AWS_ARM64_SCRIPT)" || (echo "ERROR: missing executable $(AWS_ARM64_SCRIPT)" && exit 1)
	"$(AWS_ARM64_SCRIPT)" full

clean:
	@echo "=== Running make clean ==="
	$(MAKE) -C "$(MICRO_DIR)" clean
	rm -f "$(MICRO_BPF_STAMP)"
	cargo clean --manifest-path "$(DAEMON_DIR)/Cargo.toml"
	$(MAKE) -C "$(KERNEL_TEST_DIR)" clean
	$(MAKE) -C "$(KERNEL_DIR)" clean
	rm -f \
		"$(SMOKE_OUTPUT)" \
		"$(VM_MICRO_SMOKE_OUTPUT)" \
		"$(VM_MICRO_OUTPUT)" \
		"$(VM_CORPUS_OUTPUT_JSON)" \
		"$(VM_CORPUS_OUTPUT_MD)" \
		"$(VM_TRACEE_OUTPUT_JSON)" \
		"$(VM_TRACEE_OUTPUT_MD)" \
		"$(VM_TETRAGON_OUTPUT_JSON)" \
		"$(VM_TETRAGON_OUTPUT_MD)" \
		"$(VM_BPFTRACE_OUTPUT_JSON)" \
		"$(VM_BPFTRACE_OUTPUT_MD)" \
		"$(VM_BPFTRACE_REPORT_MD)" \
		"$(VM_SCX_OUTPUT_JSON)" \
		"$(VM_SCX_OUTPUT_MD)" \
		"$(VM_KATRAN_OUTPUT_JSON)" \
		"$(VM_KATRAN_OUTPUT_MD)" \
		"$(ARM64_CONFIG_LINK)" \
		"$(ARM64_IMAGE_LINK)"
	rm -rf "$(ARM64_BUILD_DIR)"
	rm -rf "$(dir $(KERNEL_SELFTEST_ARM64))"
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)"
