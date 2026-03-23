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
ARM64_CROSSBUILD_ENABLE_LLVMBPF ?= ON
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

# Tunables
BZIMAGE ?= vendor/linux-framework/arch/x86/boot/bzImage
DAEMON  ?= daemon/target/release/bpfrejit-daemon
DAEMON_SOCKET ?= /tmp/bpfrejit.sock
ITERATIONS ?= 3
WARMUPS    ?= 1
REPEAT     ?= 100
BENCH      ?=

# Derived
BZIMAGE_PATH := $(if $(filter /%,$(BZIMAGE)),$(BZIMAGE),$(ROOT_DIR)/$(BZIMAGE))
DAEMON_PATH  := $(if $(filter /%,$(DAEMON)),$(DAEMON),$(ROOT_DIR)/$(DAEMON))
MICRO_RUNNER := $(RUNNER_DIR)/build/micro_exec
VMLINUX_PATH := $(KERNEL_DIR)/vmlinux
KERNEL_SYMVERS_PATH := $(KERNEL_DIR)/Module.symvers
NPROC        ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
DEFCONFIG_SRC := $(ROOT_DIR)/vendor/bpfrejit_defconfig

# Results
MICRO_RESULTS_DIR      := $(ROOT_DIR)/micro/results
CORPUS_RESULTS_DIR     := $(ROOT_DIR)/corpus/results
E2E_RESULTS_DIR        := $(ROOT_DIR)/e2e/results
SMOKE_OUTPUT           := $(MICRO_RESULTS_DIR)/smoke.json
VM_MICRO_SMOKE_OUTPUT  := $(MICRO_RESULTS_DIR)/vm_micro_smoke.json
VM_MICRO_OUTPUT        := $(MICRO_RESULTS_DIR)/vm_micro.json
VM_CORPUS_OUTPUT_JSON  := $(CORPUS_RESULTS_DIR)/vm_corpus.json
VM_CORPUS_OUTPUT_MD    := $(CORPUS_RESULTS_DIR)/vm_corpus.md

# Python / venv
_VENV_CANDIDATES := $(HOME)/workspace/.venv $(HOME)/.venv .venv venv
_VENV_FOUND := $(firstword $(foreach v,$(_VENV_CANDIDATES),$(if $(wildcard $(v)/bin/activate),$(v),)))
VENV ?= $(_VENV_FOUND)
PYTHON := $(if $(VENV),$(VENV)/bin/python3,python3)
VENV_ACTIVATE := $(if $(VENV),source "$(VENV)/bin/activate" &&,)

# VNG / VM
VNG ?= $(ROOT_DIR)/runner/scripts/vng-wrapper.sh
VM_INIT := $(VENV_ACTIVATE) "$(ROOT_DIR)/module/load_all.sh" 2>/dev/null || true;

# Benchmark args
BENCH_FLAGS      := $(foreach b,$(BENCH),--bench $(b))
MICRO_ARGS       := --iterations $(ITERATIONS) --warmups $(WARMUPS) --repeat $(REPEAT) $(BENCH_FLAGS)
LOCAL_SMOKE_ARGS := --bench simple --iterations 1 --warmups 0 --repeat 10
VM_SMOKE_ARGS    := --iterations 1 --warmups 0 --repeat 50

# Incremental rebuild sources
MICRO_RUNNER_SOURCES := $(wildcard $(RUNNER_DIR)/src/*.cpp $(RUNNER_DIR)/include/*.hpp $(RUNNER_DIR)/CMakeLists.txt)
MICRO_BPF_SOURCES    := $(wildcard $(MICRO_DIR)/programs/*.bpf.c $(MICRO_DIR)/programs/common.h)
DAEMON_SOURCES       := $(wildcard $(DAEMON_DIR)/src/*.rs $(DAEMON_DIR)/Cargo.toml $(DAEMON_DIR)/Cargo.lock)
KERNEL_JIT_SOURCES   := $(addprefix $(KERNEL_DIR)/,arch/x86/net/bpf_jit_comp.c kernel/bpf/syscall.c kernel/bpf/verifier.c kernel/bpf/trampoline.c kernel/bpf/dispatcher.c)
MICRO_BPF_STAMP      := $(MICRO_DIR)/programs/.build.stamp

.PHONY: all runner micro daemon kernel kernel-arm64 kernel-tests kinsn-modules \
	daemon-tests python-tests check smoke validate \
	vm-test vm-selftest vm-negative-test vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all \
	arm64-worktree arm64-rootfs arm64-crossbuild-image cross-arm64 selftest-arm64 \
	vm-arm64-smoke vm-arm64-selftest \
	aws-arm64-launch aws-arm64-setup aws-arm64-benchmark aws-arm64-terminate aws-arm64 \
	help clean

# ── Help ───────────────────────────────────────────────────────────────────────
help:
	@echo "Build:  all runner micro daemon kernel kinsn-modules kernel-tests kernel-arm64 cross-arm64"
	@echo "Test:   smoke daemon-tests python-tests check"
	@echo "VM x86: vm-test vm-selftest vm-negative-test vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all validate"
	@echo "ARM64:  vm-arm64-smoke vm-arm64-selftest"
	@echo "AWS:    aws-arm64-launch aws-arm64-setup aws-arm64-benchmark aws-arm64-terminate aws-arm64"
	@echo "Params: ITERATIONS=$(ITERATIONS) WARMUPS=$(WARMUPS) REPEAT=$(REPEAT) BENCH=\"...\""

# ── Build ──────────────────────────────────────────────────────────────────────
all:
	$(MAKE) micro
	$(MAKE) daemon
	$(MAKE) kernel-tests

runner:
	$(MAKE) -C "$(RUNNER_DIR)" micro_exec

micro:
	$(MAKE) runner
	$(MAKE) -C "$(MICRO_DIR)" programs

daemon:
	cargo build --release --manifest-path "$(DAEMON_DIR)/Cargo.toml"

kernel: $(BZIMAGE_PATH)

kinsn-modules: $(BZIMAGE_PATH)
kinsn-modules: $(KERNEL_SYMVERS_PATH)
	$(MAKE) -C "$(KINSN_MODULE_DIR)" KDIR="$(KERNEL_DIR)"

kernel-tests:
	$(MAKE) -C "$(KERNEL_TEST_DIR)"

# Incremental rebuild rules
$(MICRO_RUNNER): $(MICRO_RUNNER_SOURCES)
	$(MAKE) -C "$(RUNNER_DIR)" micro_exec

$(MICRO_BPF_STAMP): $(MICRO_BPF_SOURCES)
	$(MAKE) -C "$(MICRO_DIR)" programs && touch "$@"

$(DAEMON_PATH): $(DAEMON_SOURCES)
	cargo build --release --manifest-path "$(DAEMON_DIR)/Cargo.toml"

$(BZIMAGE_PATH): $(KERNEL_JIT_SOURCES)
	@if [ -f "$(DEFCONFIG_SRC)" ] && ! diff -q "$(DEFCONFIG_SRC)" "$(KERNEL_DIR)/.config" >/dev/null 2>&1; then \
		cp "$(DEFCONFIG_SRC)" "$(KERNEL_DIR)/.config"; $(MAKE) -C "$(KERNEL_DIR)" olddefconfig; fi
	$(MAKE) -C "$(KERNEL_DIR)" -j"$(NPROC)" bzImage modules_prepare

$(KERNEL_SYMVERS_PATH): $(KERNEL_JIT_SOURCES)
	@if [ -f "$(DEFCONFIG_SRC)" ] && ! diff -q "$(DEFCONFIG_SRC)" "$(KERNEL_DIR)/.config" >/dev/null 2>&1; then \
		cp "$(DEFCONFIG_SRC)" "$(KERNEL_DIR)/.config"; $(MAKE) -C "$(KERNEL_DIR)" olddefconfig; fi
	$(MAKE) -C "$(KERNEL_DIR)" -j"$(NPROC)" modules

# ── Local tests ────────────────────────────────────────────────────────────────
smoke: $(MICRO_RUNNER) $(MICRO_BPF_STAMP)
	mkdir -p "$(MICRO_RESULTS_DIR)"
	$(VENV_ACTIVATE) python3 "$(MICRO_DIR)/driver.py" suite --runtime llvmbpf $(LOCAL_SMOKE_ARGS) --output "$(SMOKE_OUTPUT)"

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
vm-test: kernel-tests $(BZIMAGE_PATH) kinsn-modules
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc '$(VM_INIT) "$(ROOT_DIR)/runner/scripts/run_all_tests.sh" "$(ROOT_DIR)"'

vm-selftest: kernel-tests $(BZIMAGE_PATH) kinsn-modules
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc '$(VM_INIT) "$(ROOT_DIR)/runner/scripts/vm-selftest.sh" \
			"$(ROOT_DIR)" \
			"$(KERNEL_TEST_DIR)/build/test_recompile" \
			"$(ROOT_DIR)/tests/unittest" \
			"$(KINSN_MODULE_DIR)"'

NEGATIVE_TEST_DIR := $(ROOT_DIR)/tests/negative
FUZZ_ROUNDS ?= 1000

vm-negative-test: $(BZIMAGE_PATH)
	$(MAKE) -C "$(NEGATIVE_TEST_DIR)"
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc '$(VM_INIT) \
			echo "=== adversarial_rejit ===" && \
			"$(NEGATIVE_TEST_DIR)/build/adversarial_rejit" && \
			echo "=== fuzz_rejit ($(FUZZ_ROUNDS) rounds) ===" && \
			"$(NEGATIVE_TEST_DIR)/build/fuzz_rejit" $(FUZZ_ROUNDS)'

vm-micro-smoke: $(MICRO_RUNNER) $(MICRO_BPF_STAMP) $(DAEMON_PATH) $(BZIMAGE_PATH) kinsn-modules
	mkdir -p "$(MICRO_RESULTS_DIR)"
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(VM_INIT) \
			"$(DAEMON_PATH)" --pgo serve --socket "$(DAEMON_SOCKET)" & DAEMON_PID=$$!; sleep 0.5; \
			trap "kill $$DAEMON_PID 2>/dev/null; rm -f $(DAEMON_SOCKET)" EXIT; \
			python3 "$(MICRO_DIR)/driver.py" suite --runtime kernel --runtime kernel-rejit \
			--daemon-socket "$(DAEMON_SOCKET)" $(VM_SMOKE_ARGS) --output "$(VM_MICRO_SMOKE_OUTPUT)"'

vm-micro: $(MICRO_RUNNER) $(MICRO_BPF_STAMP) $(DAEMON_PATH) $(BZIMAGE_PATH) kinsn-modules
	mkdir -p "$(MICRO_RESULTS_DIR)"
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(VM_INIT) \
			"$(DAEMON_PATH)" --pgo serve --socket "$(DAEMON_SOCKET)" & DAEMON_PID=$$!; sleep 0.5; \
			trap "kill $$DAEMON_PID 2>/dev/null; rm -f $(DAEMON_SOCKET)" EXIT; \
			python3 "$(MICRO_DIR)/driver.py" suite --runtime llvmbpf --runtime kernel --runtime kernel-rejit \
			--daemon-socket "$(DAEMON_SOCKET)" $(MICRO_ARGS) --output "$(VM_MICRO_OUTPUT)"'

vm-corpus: $(MICRO_RUNNER) $(DAEMON_PATH) $(BZIMAGE_PATH) kinsn-modules
	mkdir -p "$(CORPUS_RESULTS_DIR)"
	$(VENV_ACTIVATE) python3 "$(ROOT_DIR)/corpus/driver.py" packet --skip-build \
		--kernel-image "$(BZIMAGE_PATH)" --runner "$(MICRO_RUNNER)" --daemon "$(DAEMON_PATH)" \
		--vng "$(VNG)" --btf-custom-path "$(VMLINUX_PATH)" --repeat "$(REPEAT)" \
		--output-json "$(VM_CORPUS_OUTPUT_JSON)" --output-md "$(VM_CORPUS_OUTPUT_MD)"

vm-e2e: $(MICRO_RUNNER) $(DAEMON_PATH) $(BZIMAGE_PATH) kinsn-modules
	mkdir -p "$(E2E_RESULTS_DIR)"
	@# Pre-download E2E tool binaries on the host so the VM guest can access them
	bash "$(ROOT_DIR)/e2e/cases/tracee/setup.sh" || true
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(VM_INIT) python3 "$(ROOT_DIR)/e2e/run.py" all'

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

cross-arm64: arm64-crossbuild-image
	rm -rf "$(ARM64_CROSSBUILD_OUTPUT_DIR)" && mkdir -p "$(ARM64_CROSSBUILD_OUTPUT_DIR)"
	"$(DOCKER)" run --rm --platform "$(ARM64_DOCKER_PLATFORM)" --user "$$(id -u):$$(id -g)" \
		-v "$(ROOT_DIR)":/workspace -v "$(ARM64_CROSSBUILD_OUTPUT_DIR)":/out -w /workspace \
		-e ARM64_CROSSBUILD_JOBS="$(ARM64_CROSSBUILD_JOBS)" \
		-e MICRO_EXEC_ENABLE_LLVMBPF="$(ARM64_CROSSBUILD_ENABLE_LLVMBPF)" \
		"$(ARM64_CROSSBUILD_IMAGE)" /workspace/runner/scripts/cross-arm64-build.sh
	file "$(ARM64_CROSS_RUNNER_REAL)" | grep -F "ARM aarch64"
	file "$(ARM64_CROSS_DAEMON_REAL)" | grep -F "ARM aarch64"

selftest-arm64: arm64-crossbuild-image
	mkdir -p "$(KERNEL_TEST_DIR)/build-arm64/lib"
	"$(DOCKER)" run --rm --platform "$(ARM64_DOCKER_PLATFORM)" --user "$$(id -u):$$(id -g)" \
		-v "$(ROOT_DIR)":/workspace -w /workspace \
		-e ARM64_SELFTEST_GUEST_ROOT="$(ARM64_SELFTEST_GUEST_ROOT)" \
		"$(ARM64_CROSSBUILD_IMAGE)" /workspace/runner/scripts/cross-arm64-selftest.sh
	file "$(KERNEL_TEST_DIR)/build-arm64/test_recompile" | grep -F "ELF 64-bit LSB executable, ARM aarch64"

vm-arm64-smoke: $(ARM64_IMAGE) $(ARM64_ROOTFS_DIR)/bin/sh
	$(VENV_ACTIVATE) python3 "$(ROOT_DIR)/runner/scripts/arm64_qemu_smoke.py" \
		--qemu "$(ARM64_QEMU)" --kernel "$(ARM64_IMAGE)" --rootfs "$(ARM64_ROOTFS_DIR)"

vm-arm64-selftest: $(ARM64_IMAGE) $(ARM64_ROOTFS_DIR)/bin/sh selftest-arm64
	$(VENV_ACTIVATE) python3 "$(ROOT_DIR)/runner/scripts/arm64_qemu_smoke.py" \
		--qemu "$(ARM64_QEMU)" --kernel "$(ARM64_IMAGE)" --rootfs "$(ARM64_ROOTFS_DIR)" \
		--host-share "$(ROOT_DIR)" --guest-mount "$(ARM64_REPO_GUEST_MOUNT)" \
		--command 'mount -t tmpfs tmpfs /tmp' \
		--command 'mkdir -p /tmp/selftest /tmp/selftest/lib' \
		--command 'cp "$(ARM64_REPO_GUEST_MOUNT)/tests/kernel/build-arm64/test_recompile" /tmp/selftest/' \
		--command 'cp -a "$(ARM64_REPO_GUEST_MOUNT)/tests/kernel/build-arm64/lib/." /tmp/selftest/lib/' \
		--command 'chmod +x /tmp/selftest/test_recompile' \
		--command 'LD_LIBRARY_PATH=/tmp/selftest/lib /tmp/selftest/test_recompile'

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

# ── Clean ──────────────────────────────────────────────────────────────────────
clean:
	$(MAKE) -C "$(MICRO_DIR)" clean
	rm -f "$(MICRO_BPF_STAMP)"
	cargo clean --manifest-path "$(DAEMON_DIR)/Cargo.toml"
	$(MAKE) -C "$(KERNEL_TEST_DIR)" clean
	$(MAKE) -C "$(KERNEL_DIR)" clean
	rm -f "$(SMOKE_OUTPUT)" "$(VM_MICRO_SMOKE_OUTPUT)" "$(VM_MICRO_OUTPUT)" \
		"$(VM_CORPUS_OUTPUT_JSON)" "$(VM_CORPUS_OUTPUT_MD)" "$(ARM64_CONFIG_LINK)" "$(ARM64_IMAGE_LINK)"
	rm -rf "$(ARM64_BUILD_DIR)" "$(KERNEL_TEST_DIR)/build-arm64" "$(ARM64_CROSSBUILD_OUTPUT_DIR)"
