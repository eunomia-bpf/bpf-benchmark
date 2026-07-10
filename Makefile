SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
MICRO_DIR := $(ROOT_DIR)/micro
RUNNER_DIR := $(ROOT_DIR)/runner
KERNEL_DIR := $(ROOT_DIR)/vendor/linux-framework
ARTIFACT_ROOT := $(ROOT_DIR)/.cache
RUNNER_BUILD_DIR ?= $(RUNNER_DIR)/build


NPROC        ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
JOBS         ?= $(NPROC)
DEFCONFIG_SRC := $(ROOT_DIR)/vendor/bpfrejit_x86_defconfig
ARM64_DEFCONFIG_SRC := $(ROOT_DIR)/vendor/bpfrejit_arm64_defconfig

include $(RUNNER_DIR)/mk/build.mk

# Tunables
PLATFORM ?= kvm
ARCH     ?= x86
BZIMAGE  ?= $(X86_RUNTIME_KERNEL_IMAGE)
SAMPLES  ?= 3
WORKLOAD_DURATION ?=
TIMEOUT  ?= 7200
BENCH    ?=
FUZZ_ROUNDS ?= 1000
MERLIN_COMPILETIME_MODE ?= none
MERLIN_BUILD_DIR ?= $(ROOT_DIR)/.cache/third-party-smoke/build/merlin-v0.01-llvm18
DOCKER_BUILD_CACHE_KEEP_STORAGE ?= 50GB
CPU_GOVERNOR_FILES := $(wildcard /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor)
CPU_POLICY_MAX_FREQ_FILES := $(wildcard /sys/devices/system/cpu/cpufreq/policy[0-7]/scaling_max_freq)

# PLATFORM × ARCH → runner target name + suite command tables.
RUN_KEY := $(PLATFORM)-$(ARCH)
ARM64_RUNTIME_KERNEL_IMAGE := $(VENDOR_BUILD_DIR)/arm64/linux/arch/arm64/boot/vmlinuz.efi
ARM64_QEMU_KERNEL_IMAGE := $(VENDOR_BUILD_DIR)/arm64/linux/arch/arm64/boot/Image
ARM64_QEMU_BIN ?= $(shell command -v qemu-system-aarch64 2>/dev/null || true)
ARM64_QEMU_ROOT ?= $(ARTIFACT_ROOT)/qemu-arm64-root
ARM64_QEMU_ROOT_TMP := $(ARM64_QEMU_ROOT).tmp
ARM64_QEMU_WORKSPACE := $(ARM64_QEMU_ROOT)$(ROOT_DIR)
ARM64_QEMU_RUN_SCRIPT := $(ARM64_QEMU_ROOT)/qemu-run.sh
ARM64_QEMU_STATUS := $(ARM64_QEMU_ROOT)/qemu-status
ARM64_QEMU_ROOT_READY := $(ARM64_QEMU_ROOT)/qemu-init

RUN_TARGET.kvm-x86 := x86-kvm
RUN_TARGET.aws-x86 := aws-x86
RUN_TARGET.aws-arm64 := aws-arm64
RUN_TARGET.docker-x86 := x86-docker
RUN_TARGET.qemu-arm64 := arm64-qemu
TARGET := $(RUN_TARGET.$(RUN_KEY))
RUN_TARGET_NAME := $(TARGET)

RUN_TARGET_ARCH.kvm-x86 := x86_64
RUN_TARGET_ARCH.aws-x86 := x86_64
RUN_TARGET_ARCH.aws-arm64 := arm64
RUN_TARGET_ARCH.docker-x86 := x86_64
RUN_TARGET_ARCH.qemu-arm64 := arm64
RUN_TARGET_ARCH := $(RUN_TARGET_ARCH.$(RUN_KEY))

RUN_EXECUTOR.kvm-x86 := kvm
RUN_EXECUTOR.aws-x86 := aws-ssh
RUN_EXECUTOR.aws-arm64 := aws-ssh
RUN_EXECUTOR.docker-x86 := local-docker
RUN_EXECUTOR.qemu-arm64 := kvm
RUN_EXECUTOR := $(RUN_EXECUTOR.$(RUN_KEY))

RUNTIME_CONTAINER_IMAGE.kvm-x86 := $(X86_RUNNER_RUNTIME_IMAGE)
RUNTIME_CONTAINER_IMAGE.aws-x86 := $(X86_RUNNER_RUNTIME_IMAGE)
RUNTIME_CONTAINER_IMAGE.aws-arm64 := $(ARM64_RUNNER_RUNTIME_IMAGE)
RUNTIME_CONTAINER_IMAGE.docker-x86 := $(X86_RUNNER_RUNTIME_IMAGE)
RUNTIME_CONTAINER_IMAGE.qemu-arm64 := $(ARM64_RUNNER_RUNTIME_IMAGE)
RUNTIME_CONTAINER_IMAGE := $(RUNTIME_CONTAINER_IMAGE.$(RUN_KEY))

RUNTIME_IMAGE_TAR.kvm-x86 := $(X86_RUNNER_RUNTIME_IMAGE_TAR)
RUNTIME_IMAGE_TAR.docker-x86 := $(X86_RUNNER_RUNTIME_IMAGE_TAR)
RUNTIME_IMAGE_TAR.qemu-arm64 := $(ARM64_RUNNER_RUNTIME_IMAGE_TAR)
RUNTIME_IMAGE_TAR := $(RUNTIME_IMAGE_TAR.$(RUN_KEY))

VM_KERNEL_IMAGE.kvm-x86 := $(BZIMAGE)
VM_KERNEL_IMAGE.qemu-arm64 := $(ARM64_RUNTIME_KERNEL_IMAGE)
VM_KERNEL_IMAGE := $(VM_KERNEL_IMAGE.$(RUN_KEY))
VM_EXECUTABLE.kvm-x86 := vng
VM_EXECUTABLE.qemu-arm64 := vng
VM_EXECUTABLE := $(VM_EXECUTABLE.$(RUN_KEY))
VM_CPUS.kvm-x86 := 8
VM_CPUS.qemu-arm64 := 2
VM_CPUS := $(or $(VM_CPUS),$(VM_CPUS.$(RUN_KEY)))
VM_MEM.kvm-x86 := 64G
VM_MEM.qemu-arm64 := 2G
VM_MEM := $(or $(VM_MEM),$(VM_MEM.$(RUN_KEY)))
VNG = $(VM_EXECUTABLE) --run "$(VM_KERNEL_IMAGE)" --cwd "$(ROOT_DIR)" --disable-monitor --verbose \
	--cpus "$(VM_CPUS)" --mem "$(VM_MEM)" --rwdir "$(ROOT_DIR)" --overlay-rwdir /tmp \
	--append "loglevel=7 panic=30 oops=panic"

RUN_REMOTE_PYTHON_BIN ?= python3
RUN_RUNTIME_PYTHON_BIN ?= python3
RUN_BPFTOOL_BIN ?= bpftool
RUN_NATIVE_REPOS_CSV ?= bcc,katran,tracee,tetragon

AWS_X86_NAME_TAG ?= bpf-benchmark-x86
AWS_X86_TEST_INSTANCE_TYPE ?= t3.micro
AWS_X86_BENCH_INSTANCE_TYPE ?= t3.small
AWS_X86_REMOTE_USER ?= ec2-user
AWS_X86_REMOTE_STAGE_DIR ?= /var/tmp/bpf-benchmark-aws-x86
AWS_X86_AMI_PARAM ?= /aws/service/ami-amazon-linux-latest/al2023-ami-kernel-default-x86_64
AWS_X86_REGION ?= us-east-1
AWS_X86_PROFILE ?= codex-ec2
AWS_X86_ROOT_VOLUME_GB ?= 32
AWS_X86_KEY_PATH ?= /home/yunwei37/.ssh/codex-arm64-test-20260319121631.pem
AWS_X86_KEY_NAME ?= $(basename $(notdir $(AWS_X86_KEY_PATH)))
AWS_X86_SECURITY_GROUP_ID ?= sg-02dc8d8b61d78608c
AWS_X86_SUBNET_ID ?= subnet-009460065a1cd946c

AWS_ARM64_NAME_TAG ?= bpf-benchmark-arm64
AWS_ARM64_TEST_INSTANCE_TYPE ?= t4g.micro
AWS_ARM64_BENCH_INSTANCE_TYPE ?= t4g.small
AWS_ARM64_REMOTE_USER ?= ec2-user
AWS_ARM64_REMOTE_STAGE_DIR ?= /var/tmp/bpf-benchmark-aws-arm64
AWS_ARM64_AMI_PARAM ?= /aws/service/ami-amazon-linux-latest/al2023-ami-kernel-default-arm64
AWS_ARM64_REGION ?= us-east-1
AWS_ARM64_PROFILE ?= codex-ec2
AWS_ARM64_ROOT_VOLUME_GB ?= 32
AWS_ARM64_KEY_PATH ?= /home/yunwei37/.ssh/codex-arm64-test-20260319121631.pem
AWS_ARM64_KEY_NAME ?= $(basename $(notdir $(AWS_ARM64_KEY_PATH)))
AWS_ARM64_SECURITY_GROUP_ID ?= sg-0ebe13c1e4c0defc9
AWS_ARM64_SUBNET_ID ?= subnet-009460065a1cd946c

AWS_PREFIX.x86 := AWS_X86
AWS_PREFIX.arm64 := AWS_ARM64
AWS_TARGET_NAME.x86 := aws-x86
AWS_TARGET_NAME.arm64 := aws-arm64
AWS_BASE_ENV = TARGET=$(AWS_TARGET_NAME.$(AWS_ARCH_KEY)) RUN_TARGET_NAME=$(AWS_TARGET_NAME.$(AWS_ARCH_KEY)) \
	RUN_TARGET_ARCH=$(RUN_TARGET_ARCH.aws-$(AWS_ARCH_KEY)) \
	RUN_EXECUTOR=aws-ssh RUN_NAME_TAG="$($(AWS_PREFIX.$(AWS_ARCH_KEY))_NAME_TAG)" \
	RUN_REMOTE_USER="$($(AWS_PREFIX.$(AWS_ARCH_KEY))_REMOTE_USER)" \
	RUN_AMI_PARAM="$($(AWS_PREFIX.$(AWS_ARCH_KEY))_AMI_PARAM)" \
	RUN_ROOT_VOLUME_GB="$($(AWS_PREFIX.$(AWS_ARCH_KEY))_ROOT_VOLUME_GB)" \
	RUN_AWS_KEY_NAME="$($(AWS_PREFIX.$(AWS_ARCH_KEY))_KEY_NAME)" \
	RUN_AWS_KEY_PATH="$($(AWS_PREFIX.$(AWS_ARCH_KEY))_KEY_PATH)" \
	RUN_AWS_SECURITY_GROUP_ID="$($(AWS_PREFIX.$(AWS_ARCH_KEY))_SECURITY_GROUP_ID)" \
	RUN_AWS_SUBNET_ID="$($(AWS_PREFIX.$(AWS_ARCH_KEY))_SUBNET_ID)" \
	RUN_AWS_REGION="$($(AWS_PREFIX.$(AWS_ARCH_KEY))_REGION)" RUN_AWS_PROFILE="$($(AWS_PREFIX.$(AWS_ARCH_KEY))_PROFILE)" \
	RUN_REMOTE_PYTHON_BIN="$(RUN_REMOTE_PYTHON_BIN)" RUN_RUNTIME_PYTHON_BIN="$(RUN_RUNTIME_PYTHON_BIN)" \
	RUN_RUNTIME_CONTAINER_IMAGE="$(RUNTIME_CONTAINER_IMAGE.aws-$(AWS_ARCH_KEY))" RUN_BPFTOOL_BIN="$(RUN_BPFTOOL_BIN)" \
	RUN_NATIVE_REPOS_CSV="$(RUN_NATIVE_REPOS_CSV)" RUN_TOKEN="$(RUN_TOKEN)"
AWS_RUN_ENV = $(AWS_BASE_ENV) RUN_INSTANCE_TYPE="$(AWS_INSTANCE_TYPE)" RUN_SUITE_NEEDS_RUNTIME_BTF=$(AWS_BTF) \
	RUN_REMOTE_STAGE_DIR="$($(AWS_PREFIX.$(AWS_ARCH_KEY))_REMOTE_STAGE_DIR)/$(AWS_SUITE)/$(RUN_TOKEN)" \
	$(foreach v,$(SUITE_ENV_NAMES),$(v)="$($(v))")

# Python / venv
_VENV_CANDIDATES := $(HOME)/workspace/.venv $(HOME)/.venv .venv venv
_VENV_ACTIVATE := $(firstword $(wildcard $(addsuffix /bin/activate,$(_VENV_CANDIDATES))))
_VENV_FOUND := $(patsubst %/bin/activate,%,$(_VENV_ACTIVATE))
VENV ?= $(_VENV_FOUND)
PYTHON := $(or $(VENV:%=%/bin/python3),python3)
export BZIMAGE PYTHON LLVM_DIR RUN_LLVM_DIR TIMEOUT FUZZ_ROUNDS WORKLOAD_DURATION

# KEEP_WORKDIRS: empty/0 = no tars (default), 1 = tar on real failures only.
# To capture an artifact from a successful pass, edit the relevant
# runner/config/passes/<pass>/<app>.yaml `command:` to append `&& false` —
# that turns the step into a controlled failure and the existing
# failure-tar pipeline writes the workdir to details/failure-artifacts/.
KEEP_WORKDIRS ?=

# Suite knobs are env-only for local, VM, Docker, and AWS runs.
SUITE_ENV_NAMES = SAMPLES WARMUPS INNER_REPEAT BENCH SUITE RUNTIMES FUZZ_ROUNDS TEST_MODE WORKLOAD_DURATION \
	KEEP_WORKDIRS BPFREJIT_BENCH_PASSES BPFREJIT_CORPUS_APPS SKIP_REJIT CPU STRICT_ENV SHUFFLE_SEED \
	REGENERATE_INPUTS LIST MICRO_RUNNER_BINARY PERF_COUNTERS \
	BPFREJIT_BRANCH_PROFILE_ROOT \
	MERLIN_ARTIFACT_MODE MERLIN_COMPILETIME_MODE \
	BPFREJIT_CORPUS_APP_TIMEOUT BPFREJIT_CORPUS_REJIT_TIMEOUT \
	BPFREJIT_CORPUS_WORKLOAD_ONLY BPFREJIT_CORPUS_BPF_STATS \
	BPFREJIT_CORPUS_NATIVE_LOADER_POST_ONLY \
	BPFREJIT_SHIM_NATIVE_LOADER BPFREJIT_SHIM_NATIVE_MANIFEST \
	BPFREJIT_SHIM_NATIVE_JIT_DUMP_LIMIT BPFREJIT_SHIM_NATIVE_KMSG_PROGRESS \
	BPFREJIT_NATIVE_LOADER_SO \
	BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF \
	BPFREJIT_NATIVE_LINK_BINARY BPFREJIT_NATIVE_DISABLE_MAP_LOWERING \
	BPFREJIT_FTRACE_FUNCTION_PROFILE BPFREJIT_FTRACE_FUNCTIONS \
	BPFREJIT_KPROBE_FUNCTION_COUNTS BPFREJIT_KPROBE_FUNCTIONS \
	BPFREJIT_TRACEE_STOP_MODE BPFREJIT_TRACEE_EVENTS
export $(SUITE_ENV_NAMES)

# Per-run identity. RUN_TOKEN must be unique per invocation so AWS remote stage
# dirs and local run-state directories don't collide across concurrent or
# sequential failed runs. Random hex when not user-supplied.
RUN_TOKEN ?= $(shell od -An -N4 -tx4 /dev/urandom 2>/dev/null | tr -d ' \n')
export RUN_TOKEN TARGET

RUN_MAKE_BASE_VAR_NAMES = TARGET RUN_TARGET_NAME RUN_TARGET_ARCH RUN_EXECUTOR RUNTIME_CONTAINER_IMAGE RUNTIME_IMAGE_TAR \
	RUN_REMOTE_PYTHON_BIN RUN_RUNTIME_PYTHON_BIN RUN_BPFTOOL_BIN RUN_NATIVE_REPOS_CSV RUN_TOKEN
RUN_MAKE_VARS = $(foreach v,$(RUN_MAKE_BASE_VAR_NAMES),$(v)='$($(v))') \
	$(foreach v,$(SUITE_ENV_NAMES),$(if $($(v)),$(v)='$($(v))'))

RUNTIME_ENV_BASE_NAMES = TARGET RUN_TARGET_NAME RUN_TOKEN RUN_TARGET_ARCH RUN_EXECUTOR RUN_REMOTE_PYTHON_BIN \
	RUN_RUNTIME_PYTHON_BIN RUN_BPFTOOL_BIN RUN_NATIVE_REPOS_CSV
RUNTIME_ENV = $(foreach v,$(RUNTIME_ENV_BASE_NAMES),-e $(v)="$($(v))") \
	$(foreach v,$(SUITE_ENV_NAMES),$(if $($(v)),-e $(v)="$($(v))"))
RUNTIME_MOUNTS = -v /sys:/sys -v /sys/fs/bpf:/sys/fs/bpf -v /sys/kernel/debug:/sys/kernel/debug \
	-v /lib/modules:/lib/modules:ro -v /boot:/boot:ro
RUNTIME_DOCKER = docker run --rm --privileged --pid=host --network=host --ipc=host --cgroupns=host \
	-e BPFREJIT_INSIDE_RUNTIME_CONTAINER=1 -e HOME=/root $(RUNTIME_ENV) \
	-w "$(ROOT_DIR)" $(RUNTIME_MOUNTS)
RUNTIME_DOCKER_RUN = $(RUNTIME_DOCKER) -v "$(ROOT_DIR)/$(RUNTIME_RESULT_DIR):$(ROOT_DIR)/$(RUNTIME_RESULT_DIR)" "$(RUNTIME_CONTAINER_IMAGE)" python3 -m $(RUNTIME_SUITE_MODULE)

.PHONY: check validate lint clean \
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

selftest: selftest-$(RUN_KEY)
negative-test: negative-test-$(RUN_KEY)
test: test-$(RUN_KEY)

selftest-kvm-x86 selftest-qemu-arm64 selftest-aws-x86 selftest-aws-arm64: TEST_MODE ?= selftest
negative-test-kvm-x86 negative-test-qemu-arm64 negative-test-aws-x86 negative-test-aws-arm64: TEST_MODE ?= negative
test-kvm-x86 test-qemu-arm64 test-aws-x86 test-aws-arm64: TEST_MODE ?= test
selftest-kvm-x86 negative-test-kvm-x86 test-kvm-x86: runtime-kernel-image kvm-host-cpu
	$(VNG) --exec "$(MAKE) -C $(ROOT_DIR) __runtime-vm-test $(RUN_MAKE_VARS)"

selftest-qemu-arm64 negative-test-qemu-arm64 test-qemu-arm64: RUNTIME_RESULT_DIR := tests/results
selftest-qemu-arm64 negative-test-qemu-arm64 test-qemu-arm64: RUNTIME_SUITE_MODULE := runner.suites.test
selftest-qemu-arm64 negative-test-qemu-arm64 test-qemu-arm64: $(ARM64_QEMU_ROOT_READY)
	printf '%s\n' "#!/bin/sh" "set -eu" "export BPFREJIT_INSIDE_RUNTIME_CONTAINER=1 HOME=/root $(RUN_MAKE_VARS)" "exec python3 -m $(RUNTIME_SUITE_MODULE)" >"$(ARM64_QEMU_RUN_SCRIPT)"
	chmod +x "$(ARM64_QEMU_RUN_SCRIPT)"
	rm -f "$(ARM64_QEMU_STATUS)"
	"$(ARM64_QEMU_BIN)" -M virt -cpu cortex-a57 -smp "$(VM_CPUS)" -m "$(VM_MEM)" -nographic -no-reboot \
		-kernel "$(ARM64_QEMU_KERNEL_IMAGE)" \
		-fsdev local,id=rootfs,path="$(ARM64_QEMU_ROOT)",security_model=none,multidevs=remap \
		-device virtio-9p-device,fsdev=rootfs,mount_tag=/dev/root \
		-append "console=ttyAMA0 root=/dev/root rootfstype=9p rootflags=trans=virtio,version=9p2000.L,access=any rw init=/qemu-init loglevel=7 panic=30 oops=panic raid=noautodetect"
	test "$$(cat "$(ARM64_QEMU_STATUS)")" = "0"
	install -d "$(ROOT_DIR)/$(RUNTIME_RESULT_DIR)"
	cp -a "$(ARM64_QEMU_WORKSPACE)/$(RUNTIME_RESULT_DIR)/." "$(ROOT_DIR)/$(RUNTIME_RESULT_DIR)/"

AWS_TEST_TARGETS = selftest-aws-x86 negative-test-aws-x86 test-aws-x86 selftest-aws-arm64 negative-test-aws-arm64 test-aws-arm64
AWS_BENCH_TARGETS = micro-aws-x86 corpus-aws-x86 micro-aws-arm64 corpus-aws-arm64
$(AWS_TEST_TARGETS) $(AWS_BENCH_TARGETS):
	$(AWS_RUN_ENV) "$(PYTHON)" -m runner.libs.aws_executor run $(AWS_TARGET_NAME.$(AWS_ARCH_KEY)) $(AWS_SUITE)

selftest-aws-x86 negative-test-aws-x86 test-aws-x86 micro-aws-x86 corpus-aws-x86: AWS_ARCH_KEY := x86
selftest-aws-arm64 negative-test-aws-arm64 test-aws-arm64 micro-aws-arm64 corpus-aws-arm64: AWS_ARCH_KEY := arm64
$(AWS_TEST_TARGETS): AWS_INSTANCE_TYPE = $($(AWS_PREFIX.$(AWS_ARCH_KEY))_TEST_INSTANCE_TYPE)
$(AWS_TEST_TARGETS): AWS_BTF := 1
$(AWS_BENCH_TARGETS): AWS_INSTANCE_TYPE = $($(AWS_PREFIX.$(AWS_ARCH_KEY))_BENCH_INSTANCE_TYPE)
$(AWS_BENCH_TARGETS): AWS_BTF := 0
$(AWS_TEST_TARGETS): AWS_SUITE := test
selftest-aws-x86 negative-test-aws-x86 test-aws-x86: x86-runner-runtime-image-tar
selftest-aws-arm64 negative-test-aws-arm64 test-aws-arm64: arm64-runner-runtime-image-tar

selftest-docker-x86 negative-test-docker-x86 test-docker-x86:
	$(error PLATFORM=docker supports micro/corpus only)

kvm-host-cpu:
	printf 'performance\n' | sudo tee $(CPU_GOVERNOR_FILES) >/dev/null
	printf '1\n' | sudo tee /sys/devices/system/cpu/intel_pstate/no_turbo >/dev/null
	$(foreach f,$(CPU_POLICY_MAX_FREQ_FILES),sudo cp "$(f)" "$(dir $(f))scaling_min_freq";)

micro: micro-$(RUN_KEY)
corpus: corpus-$(RUN_KEY)

micro-kvm-x86 micro-qemu-arm64 micro-docker-x86: RUNTIME_SUITE := micro
corpus-kvm-x86 corpus-qemu-arm64 corpus-docker-x86: RUNTIME_SUITE := corpus
micro-kvm-x86 corpus-kvm-x86: runtime-kernel-image kvm-host-cpu
	$(VNG) --exec "$(MAKE) -C $(ROOT_DIR) __runtime-vm-$(RUNTIME_SUITE) $(RUN_MAKE_VARS)"

micro-qemu-arm64: RUNTIME_RESULT_DIR := micro/results
corpus-qemu-arm64: RUNTIME_RESULT_DIR := corpus/results
micro-qemu-arm64: RUNTIME_SUITE_MODULE := runner.suites.micro
corpus-qemu-arm64: RUNTIME_SUITE_MODULE := corpus.driver
micro-qemu-arm64 corpus-qemu-arm64: $(ARM64_QEMU_ROOT_READY)
	printf '%s\n' "#!/bin/sh" "set -eu" "export BPFREJIT_INSIDE_RUNTIME_CONTAINER=1 HOME=/root $(RUN_MAKE_VARS)" "exec python3 -m $(RUNTIME_SUITE_MODULE)" >"$(ARM64_QEMU_RUN_SCRIPT)"
	chmod +x "$(ARM64_QEMU_RUN_SCRIPT)"
	rm -f "$(ARM64_QEMU_STATUS)"
	"$(ARM64_QEMU_BIN)" -M virt -cpu cortex-a57 -smp "$(VM_CPUS)" -m "$(VM_MEM)" -nographic -no-reboot \
		-kernel "$(ARM64_QEMU_KERNEL_IMAGE)" \
		-fsdev local,id=rootfs,path="$(ARM64_QEMU_ROOT)",security_model=none,multidevs=remap \
		-device virtio-9p-device,fsdev=rootfs,mount_tag=/dev/root \
		-append "console=ttyAMA0 root=/dev/root rootfstype=9p rootflags=trans=virtio,version=9p2000.L,access=any rw init=/qemu-init loglevel=7 panic=30 oops=panic raid=noautodetect"
	test "$$(cat "$(ARM64_QEMU_STATUS)")" = "0"
	install -d "$(ROOT_DIR)/$(RUNTIME_RESULT_DIR)"
	cp -a "$(ARM64_QEMU_WORKSPACE)/$(RUNTIME_RESULT_DIR)/." "$(ROOT_DIR)/$(RUNTIME_RESULT_DIR)/"

micro-docker-x86: x86-runner-runtime-image-tar
corpus-docker-x86: x86-runner-runtime-host-docker-image-tar
micro-docker-x86 corpus-docker-x86:
	$(MAKE) __runtime-host-$(RUNTIME_SUITE) $(RUN_MAKE_VARS)

micro-aws-x86 micro-aws-arm64: AWS_SUITE := micro
corpus-aws-x86 corpus-aws-arm64: AWS_SUITE := corpus
micro-aws-x86 corpus-aws-x86: x86-runner-runtime-image-tar
micro-aws-arm64 corpus-aws-arm64: arm64-runner-runtime-image-tar

micro-% corpus-% selftest-% negative-test-% test-%:
	$(error unsupported PLATFORM/ARCH: PLATFORM=$(PLATFORM) ARCH=$(ARCH))

__runtime-host-micro __runtime-vm-micro: RUNTIME_RESULT_DIR := micro/results
__runtime-host-corpus __runtime-vm-corpus: RUNTIME_RESULT_DIR := corpus/results
__runtime-vm-test: RUNTIME_RESULT_DIR := tests/results
__runtime-host-micro __runtime-vm-micro: RUNTIME_SUITE_MODULE := runner.suites.micro
__runtime-host-corpus __runtime-vm-corpus: RUNTIME_SUITE_MODULE := corpus.driver
__runtime-vm-test: RUNTIME_SUITE_MODULE := runner.suites.test

__runtime-host-micro:
	install -d "$(ROOT_DIR)/$(RUNTIME_RESULT_DIR)"
	docker load -i "$(RUNTIME_IMAGE_TAR)" >/dev/null
	$(RUNTIME_DOCKER_RUN)

__runtime-host-corpus:
	install -d "$(ROOT_DIR)/$(RUNTIME_RESULT_DIR)"
	docker load -i "$(RUNTIME_IMAGE_TAR)" >/dev/null
	$(RUNTIME_DOCKER_RUN)

__runtime-vm-docker:
	install -d /run/bpf-benchmark-docker /run/bpf-benchmark-docker/data /run/bpf-benchmark-docker/exec
	truncate -s "$${BPFREJIT_VM_DOCKER_DISK_SIZE:-64G}" /var/tmp/bpf-benchmark-docker.img
	mkfs.ext4 -F -q /var/tmp/bpf-benchmark-docker.img
	mount -o loop,discard /var/tmp/bpf-benchmark-docker.img /run/bpf-benchmark-docker
	dockerd --data-root /run/bpf-benchmark-docker/data --exec-root /run/bpf-benchmark-docker/exec --pidfile /run/bpf-benchmark-docker/docker.pid --host unix:///run/docker.sock --bridge=none --iptables=false --ip-masq=false --ip-forward=false >/run/bpf-benchmark-docker/dockerd.log 2>&1 &
	for _ in 1 2 3 4 5 6 7 8 9 10; do docker info >/dev/null 2>&1 && break; sleep 1; done
	docker info >/dev/null

__runtime-vm-micro __runtime-vm-corpus __runtime-vm-test: __runtime-vm-docker
	install -d "$(ROOT_DIR)/$(RUNTIME_RESULT_DIR)"
	"$(RUNNER_DIR)/scripts/bpfrejit-install" --image "$(RUNTIME_CONTAINER_IMAGE)" "$(RUNTIME_IMAGE_TAR)"
	$(RUNTIME_DOCKER_RUN)

arm64-qemu-root: $(ARM64_QEMU_ROOT)

$(ARM64_QEMU_ROOT): $(ARM64_QEMU_ROOT_READY)

$(ARM64_QEMU_ROOT_READY): $(ARM64_RUNNER_RUNTIME_IMAGE_TAR) $(RUNNER_DIR)/scripts/qemu-arm64-init
	test -n "$(ARM64_QEMU_BIN)"
	install -d "$(ARTIFACT_ROOT)"
	rm -rf "$(ARM64_QEMU_ROOT_TMP)"
	install -d "$(ARM64_QEMU_ROOT_TMP)"
	docker load -i "$(ARM64_RUNNER_RUNTIME_IMAGE_TAR)" >/dev/null
	cid=$$(docker create --platform linux/arm64 "$(ARM64_RUNNER_RUNTIME_IMAGE)" /bin/true); \
		trap 'docker rm -f '"$$cid"' >/dev/null 2>&1 || true; rm -rf "$(ARM64_QEMU_ROOT_TMP)"' EXIT; \
		docker export "$$cid" | tar -C "$(ARM64_QEMU_ROOT_TMP)" -xf -; \
		docker rm "$$cid" >/dev/null; \
		trap - EXIT; \
			rm -rf "$(ARM64_QEMU_ROOT)"; \
			mv "$(ARM64_QEMU_ROOT_TMP)" "$(ARM64_QEMU_ROOT)"
	install -m 0755 "$(RUNNER_DIR)/scripts/qemu-arm64-init" "$(ARM64_QEMU_ROOT)/qemu-init"

all: test micro corpus

terminate: terminate-$(PLATFORM)

terminate-aws: AWS_ARCH_KEY := $(ARCH)
terminate-aws:
	$(AWS_BASE_ENV) "$(PYTHON)" -m runner.libs.aws_executor terminate $(TARGET)

terminate-%:
	$(error terminate requires PLATFORM=aws)

clean: clean-build clean-vm-tmp

clean-build:
	rm -rf "$(RUNNER_BUILD_DIR)"
	rm -rf "$(RUNNER_DIR)/build-x86"
	rm -rf "$(RUNNER_DIR)/build-arm64"
	rm -rf "$(RUNNER_DIR)/build-llvmbpf"
	rm -rf "$(RUNNER_DIR)/build-arm64-llvmbpf"
	$(MAKE) -C "$(MICRO_DIR)/programs" OUTPUT_DIR="$(MICRO_DIR)/programs" clean
	rm -f "$(MICRO_DIR)"/generated-inputs/*.mem
	rm -rf "$(MICRO_DIR)/__pycache__" "$(MICRO_DIR)/build" "$(MICRO_DIR)"/programs/build-x86 "$(MICRO_DIR)"/programs/build-arm64
	cargo clean --manifest-path "$(ROOT_DIR)/bpfopt/Cargo.toml"
	rm -rf \
		"$(ARTIFACT_ROOT)/container-images" \
		"$(ARTIFACT_ROOT)/aws-arm64/run-state" \
		"$(ARTIFACT_ROOT)/aws-arm64/runs" \
		"$(ARTIFACT_ROOT)/aws-arm64/state" \
		"$(ARTIFACT_ROOT)/aws-x86/run-state" \
		"$(ARTIFACT_ROOT)/aws-x86/runs" \
		"$(ARTIFACT_ROOT)/aws-x86/state"
	rm -rf "$(ROOT_DIR)"/vendor/build
	rm -rf "$(ROOT_DIR)"/module/x86/build "$(ROOT_DIR)"/module/arm64/build
	rm -rf "$(ROOT_DIR)"/native-sim/test/build-x86 "$(ROOT_DIR)"/native-sim/test/build-arm64

clean-results:
	@# results retention is manual; see docs/tmp/p89_disk_audit.md
	@echo "Result cleanup is manual; see docs/tmp/p89_disk_audit.md"

clean-vm-tmp:
	-find "$(ROOT_DIR)/docs/tmp" -path '*/vm-tmp/*.img' -type f -delete
	-find "$(ROOT_DIR)/docs/tmp/runtime-container-tmp" -maxdepth 1 -mindepth 1 -type d -name 'run.*' -exec rm -rf {} +

clean-docker-cache:
	@echo "Docker build cache is not pruned automatically."
	@echo "After confirming no image build is active, run:"
	@echo "  docker buildx prune --keep-storage $(DOCKER_BUILD_CACHE_KEEP_STORAGE)"
	@echo "See docs/tmp/docker-build-cache-gc.md"
