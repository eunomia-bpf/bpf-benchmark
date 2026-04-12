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

include $(RUNNER_DIR)/mk/arm64_defaults.mk

# ARM64 / AWS
ARM64_BUILD_DIR     ?= $(ARTIFACT_ROOT)/arm64-kernel-build
ARM64_BUILD_CONFIG  := $(ARM64_BUILD_DIR)/.config
ARM64_IMAGE         := $(ARM64_BUILD_DIR)/arch/arm64/boot/Image
ARM64_EFI_IMAGE     := $(ARM64_BUILD_DIR)/arch/arm64/boot/vmlinuz.efi
ARM64_AWS_BUILD_CONFIG := $(ARM64_AWS_BUILD_DIR)/.config
ARM64_AWS_IMAGE     := $(ARM64_AWS_BUILD_DIR)/arch/arm64/boot/Image
ARM64_AWS_EFI_IMAGE := $(ARM64_AWS_BUILD_DIR)/arch/arm64/boot/vmlinuz.efi
ARM64_KERNEL_MAKEFLAGS      := $(filter-out B,$(MAKEFLAGS))
RUN_TARGET_SUITE_CMD  = "$(PYTHON)" -m runner.libs.run_target_suite
AWS_ARM64_BENCH_MODE ?= all

include $(RUNNER_DIR)/mk/build.mk

export ARM64_BUILD_DIR
AWS_X86_BENCH_MODE        ?= all

# Tunables
BZIMAGE ?= $(X86_BUILD_DIR)/arch/x86/boot/bzImage
E2E_ARGS ?=
E2E_CASE ?= all
E2E_SMOKE ?= 0
VM_CORPUS_ARGS ?=
REPOS ?=
PROFILE ?=
FILTERS ?=
TEST_MODE ?= test
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
ARM64_KERNEL_CONFIG_FRAGMENT := $(ROOT_DIR)/vendor/bpfrejit_arm64.config
# Results
MICRO_RESULTS_DIR      := $(ROOT_DIR)/micro/results

# Python / venv
_VENV_CANDIDATES := $(HOME)/workspace/.venv $(HOME)/.venv .venv venv
_VENV_FOUND := $(firstword $(foreach v,$(_VENV_CANDIDATES),$(if $(wildcard $(v)/bin/activate),$(v),)))
VENV ?= $(_VENV_FOUND)
PYTHON := $(if $(VENV),$(VENV)/bin/python3,python3)
export BZIMAGE PYTHON LLVM_CONFIG LLVM_DIR RUN_LLVM_DIR
export VM_TEST_TIMEOUT VM_MICRO_TIMEOUT VM_CORPUS_TIMEOUT VM_E2E_TIMEOUT
export FUZZ_ROUNDS SCX_PROG_SHOW_RACE_MODE SCX_PROG_SHOW_RACE_ITERATIONS SCX_PROG_SHOW_RACE_LOAD_TIMEOUT SCX_PROG_SHOW_RACE_SKIP_PROBE
VENV_ACTIVATE := $(if $(VENV),source "$(VENV)/bin/activate" &&,)

# Benchmark args
ROOT_VM_CORPUS_SAMPLES_IS_EXPLICIT := $(or $(findstring command line,$(origin SAMPLES)),$(findstring environment,$(origin SAMPLES)),$(findstring override,$(origin SAMPLES)))
ROOT_VM_CORPUS_SAMPLES_VALUE := $(if $(strip $(ROOT_VM_CORPUS_SAMPLES_IS_EXPLICIT)),$(SAMPLES),$(VM_CORPUS_SAMPLES))
VM_MICRO_SUITE_ARGS = --samples "$(SAMPLES)" --warmups "$(WARMUPS)" --inner-repeat "$(INNER_REPEAT)" $(if $(strip $(BENCH)),--bench "$(BENCH)",)
VM_MICRO_SMOKE_SUITE_ARGS = --samples "1" --warmups "0" --inner-repeat "50"
VM_CORPUS_SUITE_ARGS = --samples "$(ROOT_VM_CORPUS_SAMPLES_VALUE)" --warmups "0" $(if $(strip $(FILTERS)),--corpus-filters "$(FILTERS)",) $(if $(strip $(VM_CORPUS_WORKLOAD_SECONDS)),--corpus-workload-seconds "$(VM_CORPUS_WORKLOAD_SECONDS)",) $(if $(strip $(VM_CORPUS_ARGS)),-- $(VM_CORPUS_ARGS),)
VM_E2E_SUITE_ARGS = --e2e-cases "$(E2E_CASE)" $(if $(filter 1,$(E2E_SMOKE)),--e2e-smoke,) $(if $(strip $(E2E_ARGS)),-- $(E2E_ARGS),)
VM_TEST_COMMON_SUITE_ARGS = --fuzz-rounds "$(FUZZ_ROUNDS)" --scx-prog-show-race-mode "$(SCX_PROG_SHOW_RACE_MODE)" --scx-prog-show-race-iterations "$(SCX_PROG_SHOW_RACE_ITERATIONS)" --scx-prog-show-race-load-timeout "$(SCX_PROG_SHOW_RACE_LOAD_TIMEOUT)" $(if $(filter 1,$(SCX_PROG_SHOW_RACE_SKIP_PROBE)),--scx-prog-show-race-skip-probe,)
VM_TEST_SUITE_ARGS = --test-mode "$(TEST_MODE)" $(VM_TEST_COMMON_SUITE_ARGS)

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
	@echo "        containerized local builds: CONTAINER_RUNTIME=<docker|podman>"
	@echo "        AWS benchmark mode 'all' runs micro/corpus/e2e through the target runner"

$(KERNEL_CONFIG_PATH): $(DEFCONFIG_SRC)
	mkdir -p "$(dir $@)"
	cp "$(DEFCONFIG_SRC)" "$@"

check:
	$(PYTHON) -m py_compile \
		micro/catalog.py \
		runner/libs/aws_executor.py \
		runner/libs/aws_remote_host.py \
		runner/libs/kvm_executor.py \
		runner/libs/run_contract.py \
		runner/libs/run_target_suite.py \
		runner/libs/suite_args.py \
		runner/suites/corpus.py \
		runner/suites/e2e.py \
		runner/suites/micro.py \
		runner/suites/test.py \
		runner/libs/vm.py

validate:
	$(MAKE) check
	$(MAKE) vm-test

# ── VM (x86) ──────────────────────────────────────────────────────────────────
vm-selftest:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm test -- --test-mode "selftest" $(VM_TEST_COMMON_SUITE_ARGS)

vm-negative-test:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm test -- --test-mode "negative" $(VM_TEST_COMMON_SUITE_ARGS)

vm-test:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm test -- $(VM_TEST_SUITE_ARGS)

vm-micro-smoke:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm micro -- $(VM_MICRO_SMOKE_SUITE_ARGS)

vm-micro:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm micro -- $(VM_MICRO_SUITE_ARGS)

vm-corpus:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm corpus -- $(VM_CORPUS_SUITE_ARGS)

vm-e2e:
	$(RUN_TARGET_SUITE_CMD) run x86-kvm e2e -- $(VM_E2E_SUITE_ARGS)

vm-all:
	$(MAKE) vm-test
	$(MAKE) vm-micro
	$(MAKE) vm-corpus
	$(MAKE) vm-e2e

# ── ARM64 kernel ───────────────────────────────────────────────────────────────
$(ARM64_BUILD_CONFIG): $(ARM64_RUNNER_BUILD_IMAGE_TAR) $(ARM64_KERNEL_CONFIG_FRAGMENT) $(KERNEL_BUILD_META_FILES)
	@$(ENSURE_ARM64_RUNNER_BUILD_IMAGE)
	$(CONTAINER_RUNTIME) run --rm --platform linux/arm64 \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ARM64_RUNNER_BUILD_IMAGE)" \
		bash -c "mkdir -p '$(ARM64_BUILD_DIR)' && \
		  rm -rf '$(ARM64_BUILD_DIR)/scripts' '$(ARM64_BUILD_DIR)/tools' '$(ARM64_BUILD_DIR)/arch/arm64/kernel/pi' '$(ARM64_BUILD_DIR)/arch/arm64/kvm/hyp/nvhe' && \
		  make -C '$(KERNEL_DIR)' O='$(ARM64_BUILD_DIR)' ARCH=arm64 CROSS_COMPILE= defconfig && \
		  '$(KERNEL_DIR)/scripts/kconfig/merge_config.sh' -m -O '$(ARM64_BUILD_DIR)' '$(ARM64_BUILD_DIR)/.config' '$(ARM64_KERNEL_CONFIG_FRAGMENT)' && \
		  make -C '$(KERNEL_DIR)' O='$(ARM64_BUILD_DIR)' ARCH=arm64 CROSS_COMPILE= olddefconfig"

$(ARM64_IMAGE) $(ARM64_EFI_IMAGE) &: $(ROOT_DIR)/Makefile $(RUNNER_DIR)/mk/build.mk $(ARM64_RUNNER_BUILD_IMAGE_TAR) $(ARM64_BUILD_CONFIG) $(KERNEL_BUILD_META_FILES) $(KERNEL_SOURCE_FILES)
	@$(ENSURE_ARM64_RUNNER_BUILD_IMAGE)
	$(CONTAINER_RUNTIME) run --rm --platform linux/arm64 \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ARM64_RUNNER_BUILD_IMAGE)" \
		make -C "$(KERNEL_DIR)" O="$(ARM64_BUILD_DIR)" ARCH=arm64 CROSS_COMPILE= Image vmlinuz.efi -j"$(NPROC)"

$(ARM64_AWS_BUILD_CONFIG): $(ROOT_DIR)/Makefile $(RUNNER_DIR)/mk/build.mk $(ARM64_RUNNER_BUILD_IMAGE_TAR) $(ARM64_KERNEL_CONFIG_FRAGMENT) $(ARM64_AWS_BASE_CONFIG) $(KERNEL_BUILD_META_FILES)
	@$(ENSURE_ARM64_RUNNER_BUILD_IMAGE)
	$(CONTAINER_RUNTIME) run --rm --platform linux/arm64 \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ARM64_RUNNER_BUILD_IMAGE)" \
		bash -c "mkdir -p '$(ARM64_AWS_BUILD_DIR)' && \
		  rm -rf '$(ARM64_AWS_BUILD_DIR)/scripts' '$(ARM64_AWS_BUILD_DIR)/tools' '$(ARM64_AWS_BUILD_DIR)/arch/arm64/kernel/pi' '$(ARM64_AWS_BUILD_DIR)/arch/arm64/kvm/hyp/nvhe' && \
		  cp '$(ARM64_AWS_BASE_CONFIG)' '$(ARM64_AWS_BUILD_DIR)/.config' && \
		  ena_mode=\$$(grep -o 'CONFIG_ENA_ETHERNET=[ym]' '$(ARM64_AWS_BASE_CONFIG)' | cut -d= -f2 || true) && \
		  '$(KERNEL_DIR)/scripts/kconfig/merge_config.sh' -m -O '$(ARM64_AWS_BUILD_DIR)' '$(ARM64_AWS_BUILD_DIR)/.config' '$(ARM64_KERNEL_CONFIG_FRAGMENT)' && \
		  '$(KERNEL_DIR)/scripts/config' --file '$(ARM64_AWS_BUILD_DIR)/.config' -d LOCALVERSION_AUTO -e NET_VENDOR_AMAZON && \
		  if [ \"\$$ena_mode\" = y ]; then '$(KERNEL_DIR)/scripts/config' --file '$(ARM64_AWS_BUILD_DIR)/.config' -e ENA_ETHERNET; \
		  elif [ \"\$$ena_mode\" = m ]; then '$(KERNEL_DIR)/scripts/config' --file '$(ARM64_AWS_BUILD_DIR)/.config' -m ENA_ETHERNET; \
		  else '$(KERNEL_DIR)/scripts/config' --file '$(ARM64_AWS_BUILD_DIR)/.config' -m ENA_ETHERNET; fi && \
		  make -C '$(KERNEL_DIR)' O='$(ARM64_AWS_BUILD_DIR)' ARCH=arm64 CROSS_COMPILE= olddefconfig"

$(ARM64_AWS_IMAGE) $(ARM64_AWS_EFI_IMAGE) &: $(ROOT_DIR)/Makefile $(RUNNER_DIR)/mk/build.mk $(ARM64_RUNNER_BUILD_IMAGE_TAR) $(ARM64_AWS_BUILD_CONFIG) $(KERNEL_BUILD_META_FILES) $(KERNEL_SOURCE_FILES)
	@$(ENSURE_ARM64_RUNNER_BUILD_IMAGE)
	$(CONTAINER_RUNTIME) run --rm --platform linux/arm64 \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e MAKEFLAGS="$(ARM64_KERNEL_MAKEFLAGS)" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ARM64_RUNNER_BUILD_IMAGE)" \
		make -C "$(KERNEL_DIR)" O="$(ARM64_AWS_BUILD_DIR)" ARCH=arm64 CROSS_COMPILE= Image vmlinuz.efi -j"$(NPROC)"

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

clean:
	rm -rf "$(RUNNER_BUILD_DIR)"
	rm -rf "$(RUNNER_DIR)/build-arm64"
	$(MAKE) -C "$(MICRO_DIR)" clean
	cargo clean --manifest-path "$(DAEMON_DIR)/Cargo.toml"
	rm -rf "$(X86_BUILD_DIR)" "$(ARM64_BUILD_DIR)" "$(ROOT_DIR)/.state/runner-contracts"
	rm -rf \
		"$(ARTIFACT_ROOT)/container-images" \
		"$(ARTIFACT_ROOT)/libbpf-build" \
		"$(ARTIFACT_ROOT)/micro-programs" \
		"$(ARTIFACT_ROOT)/repo-artifacts" \
		"$(ARTIFACT_ROOT)/repo-build" \
		"$(ARTIFACT_ROOT)/workload-tools" \
		"$(ARTIFACT_ROOT)/workload-tools-build" \
		"$(ARTIFACT_ROOT)/aws-arm64/kernel-build" \
		"$(ARTIFACT_ROOT)/aws-arm64/run-state" \
		"$(ARTIFACT_ROOT)/aws-arm64/runs" \
		"$(ARTIFACT_ROOT)/aws-arm64/state" \
		"$(ARTIFACT_ROOT)/aws-x86/kernel-build" \
		"$(ARTIFACT_ROOT)/aws-x86/run-state" \
		"$(ARTIFACT_ROOT)/aws-x86/runs" \
		"$(ARTIFACT_ROOT)/aws-x86/state"
