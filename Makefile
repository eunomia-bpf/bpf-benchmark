SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
MICRO_DIR := $(ROOT_DIR)/micro
SCANNER_DIR := $(ROOT_DIR)/scanner
KERNEL_DIR := $(ROOT_DIR)/vendor/linux-framework
KERNEL_TEST_DIR := $(ROOT_DIR)/tests/kernel

# Result output directories (canonical locations)
MICRO_RESULTS_DIR := $(ROOT_DIR)/micro/results
CORPUS_RESULTS_DIR := $(ROOT_DIR)/corpus/results
E2E_RESULTS_DIR := $(ROOT_DIR)/e2e/results
# docs/tmp is for analysis reports (.md) only, NOT for JSON results
TMP_DIR := $(ROOT_DIR)/docs/tmp

BZIMAGE ?= vendor/linux-framework/arch/x86/boot/bzImage
SCANNER ?= scanner/build/bpf-jit-scanner
ITERATIONS ?= 10
WARMUPS ?= 2
REPEAT ?= 200
VENV ?= /home/yunwei37/workspace/.venv
# Optional: pass BENCH=name1 BENCH2=name2 ... via BENCH_FILTER env var, e.g.:
#   make vm-micro BENCH=simple
#   make vm-micro BENCH="simple bitcount"
BENCH ?=

VNG ?= vng
NPROC ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)

BZIMAGE_PATH := $(if $(filter /%,$(BZIMAGE)),$(BZIMAGE),$(ROOT_DIR)/$(BZIMAGE))
SCANNER_PATH := $(if $(filter /%,$(SCANNER)),$(SCANNER),$(ROOT_DIR)/$(SCANNER))
SCANNER_BUILD_DIR := $(abspath $(dir $(SCANNER_PATH)))
SCANNER_TEST_PATH := $(SCANNER_BUILD_DIR)/test_scanner
MICRO_RUNNER := $(MICRO_DIR)/build/runner/micro_exec
KERNEL_SELFTEST := $(KERNEL_TEST_DIR)/build/test_recompile
VMLINUX_PATH := $(KERNEL_DIR)/vmlinux

# Canonical output file paths
SMOKE_OUTPUT := $(MICRO_RESULTS_DIR)/smoke.latest.json
VM_MICRO_SMOKE_OUTPUT := $(MICRO_RESULTS_DIR)/vm_micro_smoke.latest.json
VM_MICRO_OUTPUT := $(MICRO_RESULTS_DIR)/vm_micro.latest.json
VM_CORPUS_OUTPUT_JSON := $(CORPUS_RESULTS_DIR)/vm_corpus.latest.json
VM_CORPUS_OUTPUT_MD := $(CORPUS_RESULTS_DIR)/vm_corpus.latest.md
VM_TRACEE_OUTPUT_JSON := $(E2E_RESULTS_DIR)/tracee.latest.json
VM_TRACEE_OUTPUT_MD := $(E2E_RESULTS_DIR)/tracee.latest.md
VM_TETRAGON_OUTPUT_JSON := $(E2E_RESULTS_DIR)/tetragon.latest.json
VM_TETRAGON_OUTPUT_MD := $(E2E_RESULTS_DIR)/tetragon.latest.md
VM_BPFTRACE_OUTPUT_JSON := $(E2E_RESULTS_DIR)/bpftrace.latest.json
VM_BPFTRACE_OUTPUT_MD := $(E2E_RESULTS_DIR)/bpftrace.latest.md
VM_BPFTRACE_REPORT_MD := $(E2E_RESULTS_DIR)/bpftrace_report.latest.md
VM_XDP_OUTPUT_JSON := $(E2E_RESULTS_DIR)/xdp_forwarding.latest.json
VM_XDP_OUTPUT_MD := $(E2E_RESULTS_DIR)/xdp_forwarding.latest.md

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

MICRO_ARGS := --iterations $(ITERATIONS) --warmups $(WARMUPS) --repeat $(REPEAT) $(BENCH_FLAGS)
LOCAL_SMOKE_ARGS := --bench simple --iterations 1 --warmups 0 --repeat 10
VM_SMOKE_ARGS := --bench simple --bench load_byte_recompose --iterations 1 --warmups 0 --repeat 10
VENV_ACTIVATE := source "$(VENV)/bin/activate" &&

# File-based dependency sources (for proper incremental rebuilds)
MICRO_RUNNER_SOURCES := $(wildcard \
	$(MICRO_DIR)/runner/src/*.cpp \
	$(MICRO_DIR)/runner/src/*.h \
	$(MICRO_DIR)/runner/CMakeLists.txt)
MICRO_BPF_SOURCES := $(wildcard \
	$(MICRO_DIR)/programs/*.bpf.c \
	$(MICRO_DIR)/programs/common.h)
SCANNER_SOURCES := $(wildcard \
	$(SCANNER_DIR)/src/*.cpp \
	$(SCANNER_DIR)/include/bpf_jit_scanner/*.hpp \
	$(SCANNER_DIR)/CMakeLists.txt)
KERNEL_JIT_SOURCES := \
	$(KERNEL_DIR)/arch/x86/net/bpf_jit_comp.c \
	$(KERNEL_DIR)/kernel/bpf/jit_directives.c
# Stamp file for BPF program objects (programs/ has no separate build dir)
MICRO_BPF_STAMP := $(MICRO_DIR)/programs/.build.stamp

.PHONY: all micro scanner kernel kernel-tests scanner-tests clean \
	smoke check validate verify-build compare \
	vm-selftest vm-micro-smoke vm-micro vm-corpus vm-e2e vm-all \
	help

help:
	@echo "=== BPF Benchmark Suite ==="
	@echo ""
	@echo "Build targets:"
	@echo "  make all              - Build micro runner, scanner, and kernel tests"
	@echo "  make micro            - Build micro_exec runner and BPF programs"
	@echo "  make scanner          - Build bpf-jit-scanner"
	@echo "  make kernel           - Build kernel bzImage"
	@echo "  make kernel-tests     - Build kernel recompile test binary"
	@echo ""
	@echo "Test/smoke targets:"
	@echo "  make smoke            - Quick llvmbpf smoke test (no VM)"
	@echo "  make check            - Build + scanner tests + smoke"
	@echo "  make validate         - check + vm-selftest + vm-micro-smoke"
	@echo ""
	@echo "Benchmark targets (require VM):"
	@echo "  make vm-selftest      - Run kernel recompile selftests in VM"
	@echo "  make vm-micro-smoke   - Quick kernel+recompile smoke in VM"
	@echo "  make vm-micro         - Full micro benchmark suite in VM"
	@echo "  make vm-corpus        - Corpus benchmark in VM"
	@echo "  make vm-e2e           - E2E benchmarks (tracee/tetragon/bpftrace/xdp) in VM"
	@echo "  make vm-all           - All VM benchmarks"
	@echo ""
	@echo "Utility targets:"
	@echo "  make verify-build     - Verify bzImage, scanner, micro_exec artifacts exist"
	@echo "  make compare OLD=a.json NEW=b.json  - Compare two result JSON files"
	@echo ""
	@echo "Tunable parameters:"
	@echo "  ITERATIONS=N          - JIT iterations (default: 10)"
	@echo "  WARMUPS=N             - Warmup iterations (default: 2)"
	@echo "  REPEAT=N              - Repeat count (default: 200)"
	@echo "  BENCH=\"name1 name2\"   - Run only specific benchmarks (vm-micro)"
	@echo "  BZIMAGE=path          - Custom kernel image path"
	@echo "  POLICY=name           - Named policy set (default: default)"
	@echo "                          default  → micro/policies/"
	@echo "                          all-apply → micro/policies/variants/all-apply/"
	@echo "                          baseline → micro/policies/variants/baseline/"
	@echo ""
	@echo "Results are written to:"
	@echo "  micro/results/        - Micro benchmark results"
	@echo "  corpus/results/       - Corpus benchmark results"
	@echo "  e2e/results/          - E2E benchmark results"
	@echo "  docs/tmp/             - Analysis reports (.md only)"

verify-build:
	@test -f "$(BZIMAGE_PATH)" || (echo "ERROR: bzImage not found at $(BZIMAGE_PATH). Run: make kernel" && exit 1)
	@test -f "$(MICRO_RUNNER)" || (echo "ERROR: micro_exec not found. Run: make micro" && exit 1)
	@test -f "$(SCANNER_PATH)" || (echo "ERROR: scanner not found. Run: make scanner" && exit 1)
	@# Check if kernel source is newer than bzImage (stale build detection)
	@if [ "$$(find "$(KERNEL_DIR)/arch/x86/net/bpf_jit_comp.c" "$(KERNEL_DIR)/kernel/bpf/jit_directives.c" -newer "$(BZIMAGE_PATH)" 2>/dev/null | head -1)" ]; then \
		echo "WARNING: kernel source is newer than bzImage — consider: make kernel"; \
	fi
	@# Check if scanner source is newer than binary
	@if [ "$$(find "$(SCANNER_DIR)/src/" -name '*.cpp' -newer "$(SCANNER_PATH)" 2>/dev/null | head -1)" ]; then \
		echo "WARNING: scanner source is newer than binary — consider: make scanner"; \
	fi
	@echo "Kernel:     $$(cd "$(KERNEL_DIR)" && git rev-parse --short HEAD 2>/dev/null || echo 'n/a')"
	@echo "Scanner:    $$(cd "$(SCANNER_DIR)" && git rev-parse --short HEAD 2>/dev/null || echo 'n/a')"
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
	$(MAKE) scanner
	$(MAKE) kernel-tests

# PHONY build targets (for manual invocation / forced rebuild)
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

# File-based targets for incremental rebuilds (used by vm-* targets)
$(MICRO_RUNNER): $(MICRO_RUNNER_SOURCES)
	@echo "=== Building micro_exec (sources changed) ==="
	$(MAKE) -C "$(MICRO_DIR)" micro_exec

$(MICRO_BPF_STAMP): $(MICRO_BPF_SOURCES)
	@echo "=== Building BPF programs (sources changed) ==="
	$(MAKE) -C "$(MICRO_DIR)" programs
	touch "$@"

$(SCANNER_PATH): $(SCANNER_SOURCES)
	@echo "=== Building bpf-jit-scanner (sources changed) ==="
	cmake -S "$(SCANNER_DIR)" -B "$(SCANNER_BUILD_DIR)" \
		-DCMAKE_BUILD_TYPE=Release \
		-DBPF_JIT_SCANNER_BUILD_TESTS=ON
	cmake --build "$(SCANNER_BUILD_DIR)" --target bpf-jit-scanner -j"$(NPROC)"

$(BZIMAGE_PATH): $(KERNEL_JIT_SOURCES)
	@echo "=== Building bzImage (kernel sources changed) ==="
	$(MAKE) -C "$(KERNEL_DIR)" -j"$(NPROC)" bzImage

smoke: $(MICRO_RUNNER) $(MICRO_BPF_STAMP)
	@echo "=== Running make smoke ==="
	mkdir -p "$(MICRO_RESULTS_DIR)"
	$(VENV_ACTIVATE) python3 "$(MICRO_DIR)/driver.py" suite \
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

vm-selftest: kernel-tests $(BZIMAGE_PATH)
	@echo "=== Running make vm-selftest ==="
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && sudo -n "$(KERNEL_SELFTEST)"'

vm-micro-smoke: $(MICRO_RUNNER) $(MICRO_BPF_STAMP) $(BZIMAGE_PATH)
	@echo "=== Running make vm-micro-smoke (POLICY=$(POLICY)) ==="
	mkdir -p "$(MICRO_RESULTS_DIR)"
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(VENV_ACTIVATE) python3 "$(MICRO_DIR)/driver.py" suite \
			--runtime kernel \
			--runtime kernel-recompile \
			$(VM_SMOKE_ARGS) \
			$(POLICY_DIR_FLAG) \
			--output "$(VM_MICRO_SMOKE_OUTPUT)"'

# Run the full micro benchmark suite in a VM.
# To run only specific benchmarks: make vm-micro BENCH="simple bitcount"
# To use a named policy set: make vm-micro POLICY=all-apply
vm-micro: $(MICRO_RUNNER) $(MICRO_BPF_STAMP) $(SCANNER_PATH) verify-build $(BZIMAGE_PATH)
	@echo "=== Running make vm-micro (POLICY=$(POLICY)) ==="
	mkdir -p "$(MICRO_RESULTS_DIR)"
	$(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
		bash -lc 'cd "$(ROOT_DIR)" && $(VENV_ACTIVATE) python3 "$(MICRO_DIR)/driver.py" suite \
			--runtime llvmbpf \
			--runtime kernel \
			--runtime kernel-recompile \
			$(MICRO_ARGS) \
			$(POLICY_DIR_FLAG) \
			--output "$(VM_MICRO_OUTPUT)"'

# The corpus batch harness already manages one vng boot per target internally.
vm-corpus: $(MICRO_RUNNER) $(MICRO_BPF_STAMP) $(SCANNER_PATH) verify-build $(BZIMAGE_PATH)
	@echo "=== Running make vm-corpus ==="
	mkdir -p "$(CORPUS_RESULTS_DIR)"
	$(VENV_ACTIVATE) python3 "$(MICRO_DIR)/driver.py" corpus v5-vm-batch \
		--skip-build \
		--kernel-image "$(BZIMAGE_PATH)" \
		--runner "$(MICRO_RUNNER)" \
		--scanner "$(SCANNER_PATH)" \
		--btf-custom-path "$(VMLINUX_PATH)" \
		--repeat "$(REPEAT)" \
		--use-policy \
		--output-json "$(VM_CORPUS_OUTPUT_JSON)" \
		--output-md "$(VM_CORPUS_OUTPUT_MD)"

vm-e2e: $(MICRO_RUNNER) $(MICRO_BPF_STAMP) $(SCANNER_PATH) verify-build $(BZIMAGE_PATH)
	@echo "=== Running make vm-e2e ==="
	mkdir -p "$(E2E_RESULTS_DIR)"
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
	rm -f "$(MICRO_BPF_STAMP)"
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
