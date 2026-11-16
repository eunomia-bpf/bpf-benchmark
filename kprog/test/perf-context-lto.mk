SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
KERNEL := /workspaces/.agent-state/kprog-ck/build-x86
VMLINUX := $(ROOT)/vendor/bpf/targets/x86/$(shell cat $(KERNEL)/include/config/kernel.release)
BUILD := /var/tmp/kprog-tmp/perf/perf-context-lto
OUTPUT ?= /workspaces/kprog-raw/perf/20261116-perf-context-lto
CPUS ?= 17-18
CXX := clang++-18
CC := clang-18
FLAGS := -O3 -g -fPIC -fomit-frame-pointer -march=native -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables

.PHONY: compiler check replay
IR_LINKER := $(BUILD)/link-embedded-ir
.PHONY: ir-linker
ir-linker: $(IR_LINKER)
$(IR_LINKER): $(ROOT)/kprog/x86/link_embedded_ir.cpp
	install -d $(BUILD)
	taskset -c $(CPUS) prlimit --as=8589934592 -- $(CXX) $$(llvm-config-18 --cxxflags) -std=c++17 -Wall -Wextra -Wno-unused-parameter $< -o $@ $$(llvm-config-18 --link-static --ldflags --libs core irreader linker bitwriter support --system-libs)

.PHONY: ir-link-check
ir-link-check: ir-linker
	install -d $(OUTPUT)
	$(IR_LINKER) $(ROOT)/vendor/build/native-bpf/x86/$(shell cat $(KERNEL)/include/config/kernel.release)/native/otel/ir/*.bc -o $(BUILD)/linked-entries.bc
	llvm-nm-18 --defined-only $(BUILD)/linked-entries.bc > $(OUTPUT)/linked-symbols.txt
	$(MAKE) -r -f $(ROOT)/kprog/test/perf-context-lto.mk replay CPUS=$(CPUS) REPLAY_INPUT=$(BUILD)/linked-entries.bc REPLAY_SYMBOL=perf_go_labels OUTPUT=$(OUTPUT)/static-entry

.PHONY: stage
stage:
	install -m 0755 $(BUILD)/perf-context-lto $(ROOT)/vendor/build/native-bpf/x86/stage/kprog-perf-context-lto

compiler:
	install -d $(BUILD) $(OUTPUT)
	taskset -c $(CPUS) prlimit --as=8589934592 -- $(CXX) $$(llvm-config-18 --cxxflags) -std=c++17 -fexceptions -Wall -Wextra -Wno-unused-parameter -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include $(ROOT)/kprog/x86/perf_context_lto.cpp -o $(BUILD)/perf-context-lto $$(llvm-config-18 --link-static --ldflags --libs core irreader analysis support passes native object --system-libs) $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz

check: compiler
	$(CC) $(FLAGS) -Wno-unknown-attributes -I$(VMLINUX) -Xclang -fembed-bitcode=all -c $(ROOT)/kprog/test/perf_context_lto.c -o $(BUILD)/input.o
	$(CC) $(FLAGS) -Wno-unknown-attributes -I$(VMLINUX) -DENTRY=perf_reference -c $(ROOT)/kprog/test/perf_context_lto.c -o $(BUILD)/reference.o
	$(CC) $(FLAGS) -Wno-unknown-attributes -I$(VMLINUX) -DPERF_CONTEXT_DRIVER -c $(ROOT)/kprog/test/perf_context_lto.c -o $(BUILD)/driver.o
	$(CC) $(FLAGS) $(BUILD)/input.o $(BUILD)/reference.o $(BUILD)/driver.o -o $(BUILD)/before
	$(BUILD)/before > $(OUTPUT)/before.txt && status=0 || status=$$?; test $$status = 1
	$(BUILD)/perf-context-lto $(BUILD)/input.o --symbol perf_entry --kernel-btf $(KERNEL)/vmlinux -o $(BUILD)/physical.o 2> $(OUTPUT)/compiler.txt
	$(CC) $(FLAGS) $(BUILD)/physical.o $(BUILD)/reference.o $(BUILD)/driver.o -o $(BUILD)/after
	$(BUILD)/after | tee $(OUTPUT)/after.txt
	taskset -c $(CPUS) prlimit --as=8589934592 -- $(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections -I$(ROOT)/kprog/libnativeloader/include -I$(ROOT)/micro/programs/build-x86 -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include -I$(ROOT)/vendor/libbpf/include -I$(ROOT)/vendor/libbpf/include/uapi $(ROOT)/kprog/test/native_loader_perf_context.cpp -Wl,--gc-sections $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -pthread -o $(BUILD)/loader-context
	$(BUILD)/loader-context $(BUILD)/input.o $(BUILD)/perf-context-lto $(KERNEL)/vmlinux $(BUILD)/cache > $(OUTPUT)/loader-path.txt
	read -r native < $(OUTPUT)/loader-path.txt; $(CC) $(FLAGS) "$$native" $(BUILD)/reference.o $(BUILD)/driver.o -o $(BUILD)/loader-after
	$(BUILD)/loader-after | tee $(OUTPUT)/loader-after.txt
	$(CC) $(FLAGS) -Wno-unknown-attributes -I$(VMLINUX) -DPERF_CONTEXT_STATIC -Xclang -fembed-bitcode=all -c $(ROOT)/kprog/test/perf_context_lto.c -o $(BUILD)/static-input.o
	$(BUILD)/perf-context-lto $(BUILD)/static-input.o --symbol perf_entry --kernel-btf $(KERNEL)/vmlinux -o $(BUILD)/static-physical.o 2> $(OUTPUT)/static-compiler.txt
	$(CC) $(FLAGS) $(BUILD)/static-physical.o $(BUILD)/reference.o $(BUILD)/driver.o -o $(BUILD)/static-after
	$(BUILD)/static-after | tee $(OUTPUT)/static-after.txt
	llvm-objdump-18 -dr $(BUILD)/physical.o > $(OUTPUT)/physical.dis
	tar -C $(BUILD) -czf $(OUTPUT)/build.tar.gz .
	date -u +%FT%TZ > $(OUTPUT)/finished

REPLAY_INPUT ?= /workspaces/kprog-raw/perf/20261114-otel-original-bpf/build-evidence/native_stack_trace.bc
REPLAY_SYMBOL ?= native_tracer_entry
replay:
	install -d $(OUTPUT)
	taskset -c $(CPUS) prlimit --as=8589934592 -- $(BUILD)/perf-context-lto $(REPLAY_INPUT) --symbol $(REPLAY_SYMBOL) --kernel-btf $(KERNEL)/vmlinux -o $(BUILD)/replay.o 2> $(OUTPUT)/replay-compiler.txt
	$(ROOT)/kprog/x86/native_lab/native_link/target/release/native-link --input $(BUILD)/replay.o --symbol $(REPLAY_SYMBOL) --mode proof --preserve-entry-abi --output $(BUILD)/replay.proof.o > $(OUTPUT)/proof.txt 2>&1
	llvm-objdump-18 -dr $(BUILD)/replay.o > $(OUTPUT)/replay.dis
	cp $(BUILD)/replay.o $(OUTPUT)/replay.o
	cp $(BUILD)/replay.proof.o $(OUTPUT)/replay.proof.o
	date -u +%FT%TZ > $(OUTPUT)/replay-finished

.PHONY: function-check
function-check: compiler
	taskset -c $(CPUS) prlimit --as=8589934592 -- $(MAKE) -r -f $(ROOT)/kprog/build/Makefile bpf-function-check BPF_FUNCTION_RUNTIME_ARGS='--runtime-compiler $(BUILD)/perf-context-lto --kernel-btf $(KERNEL)/vmlinux'
	cp /var/tmp/kprog-tmp/perf/bpf-functions/report.json $(OUTPUT)/function-report.json
	tar -C /var/tmp/kprog-tmp/perf/bpf-functions -czf $(OUTPUT)/function-build.tar.gz .
	date -u +%FT%TZ > $(OUTPUT)/function-finished
