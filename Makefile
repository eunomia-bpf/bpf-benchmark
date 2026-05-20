SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

$(if $(wildcard vendor/linux-framework/Makefile),,$(error vendor/linux-framework not found. Run: git submodule update --init --recursive))

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
MICRO_DIR := $(ROOT_DIR)/micro
RUNNER_DIR := $(ROOT_DIR)/runner
DAEMON_DIR := $(ROOT_DIR)/daemon
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
DOCKER_BUILD_CACHE_KEEP_STORAGE ?= 50GB
CPU_GOVERNOR_FILES := $(wildcard /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor)
CPU_POLICY_MAX_FREQ_FILES := $(wildcard /sys/devices/system/cpu/cpufreq/policy[0-7]/scaling_max_freq)

# PLATFORM × ARCH → runner target name + suite command tables.
RUN_KEY := $(PLATFORM)-$(ARCH)
ARM64_RUNTIME_KERNEL_IMAGE := $(VENDOR_BUILD_DIR)/arm64/linux/arch/arm64/boot/vmlinuz.efi

RUN_TARGET.kvm-x86 := x86-kvm
RUN_TARGET.aws-x86 := aws-x86
RUN_TARGET.aws-arm64 := aws-arm64
RUN_TARGET.docker-x86 := x86-docker
RUN_TARGET.qemu-arm64 := arm64-qemu
TARGET := $(RUN_TARGET.$(RUN_KEY))

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
VM_CPUS.qemu-arm64 := 8
VM_CPUS := $(or $(VM_CPUS),$(VM_CPUS.$(RUN_KEY)))
VM_MEM.kvm-x86 := 64G
VM_MEM.qemu-arm64 := 64G
VM_MEM := $(or $(VM_MEM),$(VM_MEM.$(RUN_KEY)))

# Python / venv
_VENV_CANDIDATES := $(HOME)/workspace/.venv $(HOME)/.venv .venv venv
_VENV_FOUND := $(firstword $(foreach v,$(_VENV_CANDIDATES),$(if $(wildcard $(v)/bin/activate),$(v),)))
VENV ?= $(_VENV_FOUND)
PYTHON := $(if $(VENV),$(VENV)/bin/python3,python3)
export BZIMAGE PYTHON LLVM_DIR RUN_LLVM_DIR TIMEOUT FUZZ_ROUNDS WORKLOAD_DURATION

# KEEP_WORKDIRS: empty/0 = no tars (default), 1 = tar on real failures only.
# To capture an artifact from a successful pass, edit the relevant
# runner/config/passes/<pass>/<app>.yaml `command:` to append `&& false` —
# that turns the step into a controlled failure and the existing
# failure-tar pipeline writes the workdir to details/failure-artifacts/.
KEEP_WORKDIRS ?=

# All user knobs flow through to the in-container driver via the all-env
# passthrough in suite_commands.build_runtime_container_command — no enumeration here.
export SAMPLES WARMUPS SKIP_REJIT INNER_REPEAT KEEP_WORKDIRS

# Per-run identity. RUN_TOKEN must be unique per invocation so AWS remote stage
# dirs and local run-state directories don't collide across concurrent or
# sequential failed runs. Random hex when not user-supplied.
RUN_TOKEN ?= $(shell head -c 32 /dev/urandom 2>/dev/null | tr -dc 'a-z0-9' | head -c 8)
export RUN_TOKEN TARGET

# micro and test suites still consume legacy CLI args until their drivers migrate.
MICRO_ARGS = --samples "$(SAMPLES)" --warmups "$(or $(WARMUPS),0)" --inner-repeat "$(or $(INNER_REPEAT),100000)" $(foreach b,$(BENCH),--bench "$(b)") $(if $(SUITE),--suite "$(SUITE)") $(foreach r,$(RUNTIMES),--runtime "$(r)")
TEST_ARGS_COMMON = --fuzz-rounds "$(FUZZ_ROUNDS)"

RUN_MAKE_VARS = TARGET='$(TARGET)' RUN_TARGET_ARCH='$(RUN_TARGET_ARCH)' RUN_EXECUTOR='$(RUN_EXECUTOR)' \
	RUNTIME_CONTAINER_IMAGE='$(RUNTIME_CONTAINER_IMAGE)' RUNTIME_IMAGE_TAR='$(RUNTIME_IMAGE_TAR)' \
	RUN_TOKEN='$(RUN_TOKEN)' SAMPLES='$(SAMPLES)' WARMUPS='$(WARMUPS)' INNER_REPEAT='$(INNER_REPEAT)' \
	BENCH='$(BENCH)' SUITE='$(SUITE)' RUNTIMES='$(RUNTIMES)' FUZZ_ROUNDS='$(FUZZ_ROUNDS)' \
	WORKLOAD_DURATION='$(WORKLOAD_DURATION)' KEEP_WORKDIRS='$(KEEP_WORKDIRS)' \
	BPFREJIT_BENCH_PASSES='$(BPFREJIT_BENCH_PASSES)' BPFREJIT_CORPUS_APPS='$(BPFREJIT_CORPUS_APPS)' \
	SKIP_REJIT='$(SKIP_REJIT)'

RUNTIME_ENV = -e TARGET="$(TARGET)" -e RUN_TOKEN="$(RUN_TOKEN)" -e SAMPLES="$(SAMPLES)" \
	-e RUN_TARGET_ARCH="$(RUN_TARGET_ARCH)" -e RUN_EXECUTOR="$(RUN_EXECUTOR)" \
	-e WARMUPS="$(WARMUPS)" -e INNER_REPEAT="$(INNER_REPEAT)" -e KEEP_WORKDIRS="$(KEEP_WORKDIRS)" \
	-e BPFREJIT_BENCH_PASSES="$(BPFREJIT_BENCH_PASSES)" -e BPFREJIT_CORPUS_APPS="$(BPFREJIT_CORPUS_APPS)" \
	-e WORKLOAD_DURATION="$(WORKLOAD_DURATION)" -e SKIP_REJIT="$(SKIP_REJIT)"
RUNTIME_MOUNTS = -v /sys:/sys -v /sys/fs/bpf:/sys/fs/bpf -v /sys/kernel/debug:/sys/kernel/debug \
	-v /lib/modules:/lib/modules:ro -v /boot:/boot:ro
RUNTIME_DOCKER = docker run --rm --privileged --pid=host --network=host --ipc=host --cgroupns=host \
	-e BPFREJIT_INSIDE_RUNTIME_CONTAINER=1 -e HOME=/root $(RUNTIME_ENV) \
	-w "$(ROOT_DIR)" $(RUNTIME_MOUNTS)
MICRO_CONTAINER_ARGS = --workspace "$(ROOT_DIR)" --target-arch "$(RUN_TARGET_ARCH)" --target-name "$(TARGET)" \
	--executor "$(RUN_EXECUTOR)" --run-token "$(RUN_TOKEN)" --python-bin python3 --bpftool-bin bpftool \
	--output "$(ROOT_DIR)/micro/results/$(TARGET)_micro.json" $(MICRO_ARGS)
TEST_CONTAINER_ARGS = --workspace "$(ROOT_DIR)" --target-arch "$(RUN_TARGET_ARCH)" --target-name "$(TARGET)" \
	--executor "$(RUN_EXECUTOR)" --run-token "$(RUN_TOKEN)" --python-bin python3 --bpftool-bin bpftool \
	--artifact-dir "$(ROOT_DIR)/tests/results/$(RUN_TOKEN)" $(TEST_MODE_ARGS)

.PHONY: check validate daemon-tests lint clean \
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

daemon-tests:
	cargo test --workspace --manifest-path "$(DAEMON_DIR)/Cargo.toml"

selftest: selftest-$(RUN_KEY)
negative-test: negative-test-$(RUN_KEY)
test: test-$(RUN_KEY)

selftest-kvm-x86: TEST_MODE_ARGS := --test-mode selftest $(TEST_ARGS_COMMON)
negative-test-kvm-x86: TEST_MODE_ARGS := --test-mode negative $(TEST_ARGS_COMMON)
test-kvm-x86: TEST_MODE_ARGS := --test-mode test $(TEST_ARGS_COMMON)
selftest-kvm-x86 negative-test-kvm-x86 test-kvm-x86: runtime-kernel-image kvm-host-cpu
	$(VM_EXECUTABLE) --run "$(VM_KERNEL_IMAGE)" --cwd "$(ROOT_DIR)" --disable-monitor --verbose --cpus "$(VM_CPUS)" --mem "$(VM_MEM)" --rwdir "$(ROOT_DIR)" --overlay-rwdir /tmp --append "loglevel=7 panic=30 oops=panic" --exec "$(MAKE) -C $(ROOT_DIR) __runtime-vm-test $(RUN_MAKE_VARS)"

selftest-qemu-arm64: TEST_MODE_ARGS := --test-mode selftest $(TEST_ARGS_COMMON)
negative-test-qemu-arm64: TEST_MODE_ARGS := --test-mode negative $(TEST_ARGS_COMMON)
test-qemu-arm64: TEST_MODE_ARGS := --test-mode test $(TEST_ARGS_COMMON)
selftest-qemu-arm64 negative-test-qemu-arm64 test-qemu-arm64: arm64-runner-runtime-image-tar
	$(VM_EXECUTABLE) --run "$(VM_KERNEL_IMAGE)" --cwd "$(ROOT_DIR)" --disable-monitor --verbose --cpus "$(VM_CPUS)" --mem "$(VM_MEM)" --rwdir "$(ROOT_DIR)" --overlay-rwdir /tmp --append "loglevel=7 panic=30 oops=panic" --exec "$(MAKE) -C $(ROOT_DIR) __runtime-vm-test $(RUN_MAKE_VARS)"

selftest-aws-x86:
	"$(PYTHON)" -m runner.libs.aws_executor run aws-x86 test --test-mode selftest $(TEST_ARGS_COMMON)

negative-test-aws-x86:
	"$(PYTHON)" -m runner.libs.aws_executor run aws-x86 test --test-mode negative $(TEST_ARGS_COMMON)

test-aws-x86:
	"$(PYTHON)" -m runner.libs.aws_executor run aws-x86 test --test-mode test $(TEST_ARGS_COMMON)

selftest-aws-arm64:
	"$(PYTHON)" -m runner.libs.aws_executor run aws-arm64 test --test-mode selftest $(TEST_ARGS_COMMON)

negative-test-aws-arm64:
	"$(PYTHON)" -m runner.libs.aws_executor run aws-arm64 test --test-mode negative $(TEST_ARGS_COMMON)

test-aws-arm64:
	"$(PYTHON)" -m runner.libs.aws_executor run aws-arm64 test --test-mode test $(TEST_ARGS_COMMON)

selftest-docker-x86 negative-test-docker-x86 test-docker-x86:
	$(error PLATFORM=docker supports micro/corpus only)

kvm-host-cpu:
	printf 'performance\n' | sudo tee $(CPU_GOVERNOR_FILES) >/dev/null
	printf '1\n' | sudo tee /sys/devices/system/cpu/intel_pstate/no_turbo >/dev/null
	$(foreach f,$(CPU_POLICY_MAX_FREQ_FILES),sudo cp "$(f)" "$(dir $(f))scaling_min_freq";)

micro: micro-$(RUN_KEY)
corpus: corpus-$(RUN_KEY)

micro-kvm-x86: runtime-kernel-image kvm-host-cpu
	$(VM_EXECUTABLE) --run "$(VM_KERNEL_IMAGE)" --cwd "$(ROOT_DIR)" --disable-monitor --verbose --cpus "$(VM_CPUS)" --mem "$(VM_MEM)" --rwdir "$(ROOT_DIR)" --overlay-rwdir /tmp --append "loglevel=7 panic=30 oops=panic" --exec "$(MAKE) -C $(ROOT_DIR) __runtime-vm-micro $(RUN_MAKE_VARS)"

corpus-kvm-x86: runtime-kernel-image kvm-host-cpu
	$(VM_EXECUTABLE) --run "$(VM_KERNEL_IMAGE)" --cwd "$(ROOT_DIR)" --disable-monitor --verbose --cpus "$(VM_CPUS)" --mem "$(VM_MEM)" --rwdir "$(ROOT_DIR)" --overlay-rwdir /tmp --append "loglevel=7 panic=30 oops=panic" --exec "$(MAKE) -C $(ROOT_DIR) __runtime-vm-corpus $(RUN_MAKE_VARS)"

micro-qemu-arm64: arm64-runner-runtime-image-tar
	$(VM_EXECUTABLE) --run "$(VM_KERNEL_IMAGE)" --cwd "$(ROOT_DIR)" --disable-monitor --verbose --cpus "$(VM_CPUS)" --mem "$(VM_MEM)" --rwdir "$(ROOT_DIR)" --overlay-rwdir /tmp --append "loglevel=7 panic=30 oops=panic" --exec "$(MAKE) -C $(ROOT_DIR) __runtime-vm-micro $(RUN_MAKE_VARS)"

corpus-qemu-arm64: arm64-runner-runtime-image-tar
	$(VM_EXECUTABLE) --run "$(VM_KERNEL_IMAGE)" --cwd "$(ROOT_DIR)" --disable-monitor --verbose --cpus "$(VM_CPUS)" --mem "$(VM_MEM)" --rwdir "$(ROOT_DIR)" --overlay-rwdir /tmp --append "loglevel=7 panic=30 oops=panic" --exec "$(MAKE) -C $(ROOT_DIR) __runtime-vm-corpus $(RUN_MAKE_VARS)"

micro-docker-x86: x86-runner-runtime-image-tar
	$(MAKE) __runtime-host-micro $(RUN_MAKE_VARS)

corpus-docker-x86: x86-runner-runtime-image-tar
	$(MAKE) __runtime-host-corpus $(RUN_MAKE_VARS)

micro-aws-x86:
	"$(PYTHON)" -m runner.libs.aws_executor run aws-x86 micro $(MICRO_ARGS)

corpus-aws-x86:
	"$(PYTHON)" -m runner.libs.aws_executor run aws-x86 corpus

micro-aws-arm64:
	"$(PYTHON)" -m runner.libs.aws_executor run aws-arm64 micro $(MICRO_ARGS)

corpus-aws-arm64:
	"$(PYTHON)" -m runner.libs.aws_executor run aws-arm64 corpus

micro-% corpus-% selftest-% negative-test-% test-%:
	$(error unsupported PLATFORM/ARCH: PLATFORM=$(PLATFORM) ARCH=$(ARCH))

__runtime-host-micro:
	install -d "$(ROOT_DIR)/micro/results"
	sudo "$(RUNNER_DIR)/scripts/bpfrejit-install" --image "$(RUNTIME_CONTAINER_IMAGE)" "$(RUNTIME_IMAGE_TAR)"
	$(RUNTIME_DOCKER) -v "$(ROOT_DIR)/micro/results:$(ROOT_DIR)/micro/results" "$(RUNTIME_CONTAINER_IMAGE)" python3 -m runner.suites.micro $(MICRO_CONTAINER_ARGS)

__runtime-host-corpus:
	install -d "$(ROOT_DIR)/corpus/results"
	sudo "$(RUNNER_DIR)/scripts/bpfrejit-install" --image "$(RUNTIME_CONTAINER_IMAGE)" "$(RUNTIME_IMAGE_TAR)"
	$(RUNTIME_DOCKER) -v "$(ROOT_DIR)/corpus/results:$(ROOT_DIR)/corpus/results" "$(RUNTIME_CONTAINER_IMAGE)" python3 -m corpus.driver

__runtime-vm-docker:
	rm -rf /run/bpf-benchmark-docker /tmp/bpf-benchmark-docker.img
	install -d /run/bpf-benchmark-docker /run/bpf-benchmark-docker/data /run/bpf-benchmark-docker/exec
	truncate -s "$${BPFREJIT_VM_DOCKER_DISK_SIZE:-64G}" /tmp/bpf-benchmark-docker.img
	mkfs.ext4 -F -q /tmp/bpf-benchmark-docker.img
	mount -o loop,discard /tmp/bpf-benchmark-docker.img /run/bpf-benchmark-docker
	dockerd --data-root /run/bpf-benchmark-docker/data --exec-root /run/bpf-benchmark-docker/exec --pidfile /run/bpf-benchmark-docker/docker.pid --host unix:///run/docker.sock --bridge=none --iptables=false --ip-masq=false --ip-forward=false >/run/bpf-benchmark-docker/dockerd.log 2>&1 &
	sleep 10
	docker info >/dev/null

__runtime-vm-micro: __runtime-vm-docker
	install -d "$(ROOT_DIR)/micro/results"
	"$(RUNNER_DIR)/scripts/bpfrejit-install" --image "$(RUNTIME_CONTAINER_IMAGE)" "$(RUNTIME_IMAGE_TAR)"
	$(RUNTIME_DOCKER) -v "$(ROOT_DIR)/micro/results:$(ROOT_DIR)/micro/results" "$(RUNTIME_CONTAINER_IMAGE)" python3 -m runner.suites.micro $(MICRO_CONTAINER_ARGS)

__runtime-vm-corpus: __runtime-vm-docker
	install -d "$(ROOT_DIR)/corpus/results"
	"$(RUNNER_DIR)/scripts/bpfrejit-install" --image "$(RUNTIME_CONTAINER_IMAGE)" "$(RUNTIME_IMAGE_TAR)"
	$(RUNTIME_DOCKER) -v "$(ROOT_DIR)/corpus/results:$(ROOT_DIR)/corpus/results" "$(RUNTIME_CONTAINER_IMAGE)" python3 -m corpus.driver

__runtime-vm-test: __runtime-vm-docker
	install -d "$(ROOT_DIR)/tests/results"
	"$(RUNNER_DIR)/scripts/bpfrejit-install" --image "$(RUNTIME_CONTAINER_IMAGE)" "$(RUNTIME_IMAGE_TAR)"
	$(RUNTIME_DOCKER) -v "$(ROOT_DIR)/tests/results:$(ROOT_DIR)/tests/results" "$(RUNTIME_CONTAINER_IMAGE)" python3 -m runner.suites.test $(TEST_CONTAINER_ARGS)

all: test micro corpus

terminate: terminate-$(PLATFORM)

terminate-aws:
	"$(PYTHON)" -m runner.libs.aws_executor terminate $(TARGET)

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
	cargo clean --manifest-path "$(DAEMON_DIR)/Cargo.toml"
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
	@echo "See docs/docker-build-cache-gc.md"
