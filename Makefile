SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
MICRO_DIR := $(ROOT_DIR)/micro
SCANNER_DIR := $(ROOT_DIR)/scanner
KERNEL_DIR := $(ROOT_DIR)/vendor/linux-framework
KERNEL_TEST_DIR := $(ROOT_DIR)/tests/kernel
TMP_DIR := $(ROOT_DIR)/docs/tmp

BZIMAGE ?= vendor/linux-framework/arch/x86/boot/bzImage
SCANNER ?= scanner/build/bpf-jit-scanner
ITERATIONS ?= 10
WARMUPS ?= 2
REPEAT ?= 200
VENV ?= /home/yunwei37/workspace/.venv

VNG ?= vng
NPROC ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)

BZIMAGE_PATH := $(if $(filter /%,$(BZIMAGE)),$(BZIMAGE),$(ROOT_DIR)/$(BZIMAGE))
SCANNER_PATH := $(if $(filter /%,$(SCANNER)),$(SCANNER),$(ROOT_DIR)/$(SCANNER))
SCANNER_BUILD_DIR := $(abspath $(dir $(SCANNER_PATH)))
SCANNER_TEST_PATH := $(SCANNER_BUILD_DIR)/test_scanner
MICRO_RUNNER := $(MICRO_DIR)/build/runner/micro_exec
KERNEL_SELFTEST := $(KERNEL_TEST_DIR)/build/test_recompile
VMLINUX_PATH := $(KERNEL_DIR)/vmlinux

SMOKE_OUTPUT := $(TMP_DIR)/root-makefile-smoke.json
VM_MICRO_SMOKE_OUTPUT := $(TMP_DIR)/root-makefile-vm-micro-smoke.json
VM_MICRO_OUTPUT := $(TMP_DIR)/root-makefile-vm-micro.json
VM_CORPUS_OUTPUT_JSON := $(TMP_DIR)/root-makefile-vm-corpus.json
VM_CORPUS_OUTPUT_MD := $(TMP_DIR)/root-makefile-vm-corpus.md
VM_TRACEE_OUTPUT_JSON := $(TMP_DIR)/root-makefile-vm-tracee.json
VM_TRACEE_OUTPUT_MD := $(TMP_DIR)/root-makefile-vm-tracee.md
VM_TETRAGON_OUTPUT_JSON := $(TMP_DIR)/root-makefile-vm-tetragon.json
VM_TETRAGON_OUTPUT_MD := $(TMP_DIR)/root-makefile-vm-tetragon.md
VM_BPFTRACE_OUTPUT_JSON := $(TMP_DIR)/root-makefile-vm-bpftrace.json
VM_BPFTRACE_OUTPUT_MD := $(TMP_DIR)/root-makefile-vm-bpftrace.md
VM_BPFTRACE_REPORT_MD := $(TMP_DIR)/root-makefile-vm-bpftrace-report.md
VM_XDP_OUTPUT_JSON := $(TMP_DIR)/root-makefile-vm-xdp-forwarding.json
VM_XDP_OUTPUT_MD := $(TMP_DIR)/root-makefile-vm-xdp-forwarding.md

MICRO_ARGS := --iterations $(ITERATIONS) --warmups $(WARMUPS) --repeat $(REPEAT)
LOCAL_SMOKE_ARGS := --bench simple --iterations 1 --warmups 0 --repeat 10
VM_SMOKE_ARGS := --bench simple --bench load_byte_recompose --iterations 1 --warmups 0 --repeat 10
VENV_ACTIVATE := source "$(VENV)/bin/activate" &&

.PHONY: all micro scanner kernel kernel-tests scanner-tests clean \
	smoke check validate \
	vm-selftest vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all

all:
	@echo "=== Running make all ==="
	$(MAKE) micro
	$(MAKE) scanner
	$(MAKE) kernel-tests

micro:
	@echo "=== Running make micro ==="
	$(MAKE) -C "$(MICRO_DIR)" micro_exec programs

scanner:
	@echo "=== Running make scanner ==="
	cmake -S "$(SCANNER_DIR)" -B "$(SCANNER_BUILD_DIR)" \
		-DCMAKE_BUILD_TYPE=Release \
		-DBPF_JIT_SCANNER_BUILD_TESTS=ON
	cmake --build "$(SCANNER_BUILD_DIR)" --target bpf-jit-scanner -j"$(NPROC)"

kernel:
	@echo "=== Running make kernel ==="
	$(MAKE) -C "$(KERNEL_DIR)" -j"$(NPROC)" bzImage

kernel-tests:
	@echo "=== Running make kernel-tests ==="
	$(MAKE) -C "$(KERNEL_TEST_DIR)"

scanner-tests: scanner
	@echo "=== Running scanner tests ==="
	cmake --build "$(SCANNER_BUILD_DIR)" --target test_scanner -j"$(NPROC)"
	ctest --test-dir "$(SCANNER_BUILD_DIR)" --output-on-failure

$(BZIMAGE_PATH):
	@echo "=== Running make kernel (missing bzImage) ==="
	$(MAKE) -C "$(KERNEL_DIR)" -j"$(NPROC)" bzImage

smoke: micro
	@echo "=== Running make smoke ==="
	mkdir -p "$(TMP_DIR)"
	$(VENV_ACTIVATE) python3 "$(MICRO_DIR)/run_micro.py" \
		--runtime llvmbpf \
		$(LOCAL_SMOKE_ARGS) \
		--output "$(SMOKE_OUTPUT)"

check:
	@echo "=== Running make check ==="
	$(MAKE) all
	$(MAKE) scanner-tests
	$(MAKE) smoke

validate:
	@echo "=== Running make validate ==="
	$(MAKE) check
	$(MAKE) vm-selftest
	$(MAKE) vm-micro-smoke

vm-selftest: kernel-tests | $(BZIMAGE_PATH)
	@echo "=== Running make vm-selftest ==="
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && sudo -n "$(KERNEL_SELFTEST)"'

vm-micro-smoke: micro | $(BZIMAGE_PATH)
	@echo "=== Running make vm-micro-smoke ==="
	mkdir -p "$(TMP_DIR)"
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(VENV_ACTIVATE) python3 "$(MICRO_DIR)/run_micro.py" \
			--runtime kernel \
			--runtime kernel-recompile \
			$(VM_SMOKE_ARGS) \
			--output "$(VM_MICRO_SMOKE_OUTPUT)"'

vm-micro: micro | $(BZIMAGE_PATH)
	@echo "=== Running make vm-micro ==="
	mkdir -p "$(TMP_DIR)"
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(VENV_ACTIVATE) python3 "$(MICRO_DIR)/run_micro.py" \
			--runtime llvmbpf \
			--runtime kernel \
			--runtime kernel-recompile \
			$(MICRO_ARGS) \
			--output "$(VM_MICRO_OUTPUT)"'

# The corpus batch harness already manages one vng boot per target internally.
vm-corpus: micro scanner | $(BZIMAGE_PATH)
	@echo "=== Running make vm-corpus ==="
	mkdir -p "$(TMP_DIR)"
	$(VENV_ACTIVATE) python3 "$(ROOT_DIR)/corpus/run_corpus_v5_vm_batch.py" \
		--skip-build \
		--kernel-image "$(BZIMAGE_PATH)" \
		--runner "$(MICRO_RUNNER)" \
		--scanner "$(SCANNER_PATH)" \
		--btf-custom-path "$(VMLINUX_PATH)" \
		--repeat "$(REPEAT)" \
		--use-policy \
		--output-json "$(VM_CORPUS_OUTPUT_JSON)" \
		--output-md "$(VM_CORPUS_OUTPUT_MD)"

vm-e2e: micro scanner | $(BZIMAGE_PATH)
	@echo "=== Running make vm-e2e ==="
	mkdir -p "$(TMP_DIR)"
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
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" --network loop --network loop -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(VENV_ACTIVATE) python3 "$(ROOT_DIR)/e2e/run.py" xdp_forwarding \
			--output-json "$(VM_XDP_OUTPUT_JSON)" \
			--output-md "$(VM_XDP_OUTPUT_MD)" \
			--topology-mode preexisting \
			--router-left-if eth0 \
			--source-if eth1 \
			--router-right-if eth2 \
			--sink-if eth3'

vm-all:
	@echo "=== Running make vm-all ==="
	$(MAKE) vm-selftest
	$(MAKE) vm-micro
	$(MAKE) vm-corpus
	$(MAKE) vm-e2e

clean:
	@echo "=== Running make clean ==="
	$(MAKE) -C "$(MICRO_DIR)" clean
	rm -rf "$(SCANNER_BUILD_DIR)"
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
		"$(VM_XDP_OUTPUT_JSON)" \
		"$(VM_XDP_OUTPUT_MD)"
