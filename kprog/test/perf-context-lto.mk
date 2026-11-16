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
