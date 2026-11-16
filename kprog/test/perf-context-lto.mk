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
stage: $(BUILD)/kprog-bpf-callee-ir
	install -m 0755 $(BUILD)/perf-context-lto $(ROOT)/vendor/build/native-bpf/x86/stage/kprog-perf-context-lto
	install -m 0755 $(BUILD)/kprog-bpf-callee-ir $(ROOT)/vendor/build/native-bpf/x86/stage/kprog-bpf-callee-ir

compiler: $(BUILD)/kprog-bpf-callee-ir
	install -d $(BUILD) $(OUTPUT)
	taskset -c $(CPUS) prlimit --as=8589934592 -- $(CXX) $$(llvm-config-18 --cxxflags) -std=c++17 -fexceptions -Wall -Wextra -Wno-unused-parameter -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include $(ROOT)/kprog/x86/perf_context_lto.cpp -o $(BUILD)/perf-context-lto $$(llvm-config-18 --link-static --ldflags --libs core irreader analysis support passes native object linker --system-libs) $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz

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

.PHONY: function-loader-check
function-loader-check: compiler
	$(CC) $(FLAGS) -Xclang -fembed-bitcode=all -c $(ROOT)/kprog/build/test-bpf-function.c -o $(BUILD)/functions-input.o
	taskset -c $(CPUS) prlimit --as=8589934592 -- $(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections -I$(ROOT)/kprog/libnativeloader/include -I$(ROOT)/micro/programs/build-x86 -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include -I$(ROOT)/vendor/libbpf/include -I$(ROOT)/vendor/libbpf/include/uapi $(ROOT)/kprog/test/native_loader_function_bodies.cpp -Wl,--gc-sections $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -pthread -o $(BUILD)/loader-functions
	$(BUILD)/loader-functions $(BUILD)/functions-input.o $(BUILD)/perf-context-lto $(KERNEL)/vmlinux $(BUILD)/function-cache > $(OUTPUT)/loader-functions.txt
	while read -r value object; do \
	  $(CC) "$$object" -o $(BUILD)/loader-function-result; \
	  if [ "$$value" = -1 ]; then $(BUILD)/loader-function-result 0xffffffffffffffff 0xffffffff; else $(BUILD)/loader-function-result 0 0; fi; \
	done < $(OUTPUT)/loader-functions.txt
	tar -C $(BUILD) -czf $(OUTPUT)/loader-function-build.tar.gz .
	date -u +%FT%TZ > $(OUTPUT)/loader-function-finished

.PHONY: function-live-inputs function-live-kvm guest-function-live
function-live-inputs: compiler
	$(CC) $(FLAGS) -Xclang -fembed-bitcode=all -c $(ROOT)/kprog/test/native_function_live.c -o $(BUILD)/live-input.o
	$(CC) $(FLAGS) -DFUNCTION_DRIVER -c $(ROOT)/kprog/test/native_function_live.c -o $(BUILD)/live-driver.o
	taskset -c $(CPUS) prlimit --as=8589934592 -- $(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections -I$(ROOT)/kprog/libnativeloader/include -I$(ROOT)/micro/programs/build-x86 -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include -I$(ROOT)/vendor/libbpf/include -I$(ROOT)/vendor/libbpf/include/uapi $(ROOT)/kprog/test/native_function_live.cpp -Wl,--gc-sections $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -pthread -o $(BUILD)/function-live

function-live-kvm: function-live-inputs
	install -d $(OUTPUT)/live $(OUTPUT)/inputs
	flock -s /workspaces/.agent-state/kprog-lanes/locks/image taskset -c $(CPUS) prlimit --as=8589934592 -- vng --run $(KERNEL)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rodir $(OUTPUT)/inputs=$(BUILD) --rwdir $(OUTPUT) --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/perf-context-lto.mk guest-function-live OUTPUT=$(OUTPUT) BUILD=$(OUTPUT)/inputs'
	tar -C $(BUILD) -czf $(OUTPUT)/live-build.tar.gz .
	date -u +%FT%TZ > $(OUTPUT)/live-finished

guest-function-live:
	$(FUNCTION_LIVE_ENV) $(BUILD)/function-live $(BUILD)/live-input.o $(BUILD)/perf-context-lto $(OUTPUT)/live $(OUTPUT)/live/native-path.txt > $(OUTPUT)/live/kernel.json
	read -r object < $(OUTPUT)/live/native-path.txt; $(CC) "$$object" $(BUILD)/live-driver.o -o $(OUTPUT)/live/native-result
	$(OUTPUT)/live/native-result
	printf 'BPF and native result both 13\n' > $(OUTPUT)/live/execution.txt

.PHONY: function-shim-live-kvm guest-function-shim-live
function-shim-live-kvm: function-live-inputs
	$(MAKE) -C $(ROOT)/bpfopt/shim libbpfrejit_shim.so
	install -d $(OUTPUT)/live $(OUTPUT)/inputs
	flock -s /workspaces/.agent-state/kprog-lanes/locks/image taskset -c $(CPUS) prlimit --as=8589934592 -- vng --run $(KERNEL)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rodir $(OUTPUT)/inputs=$(BUILD) --rwdir $(OUTPUT) --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/perf-context-lto.mk guest-function-shim-live OUTPUT=$(OUTPUT) BUILD=$(OUTPUT)/inputs'
	tar -C $(BUILD) -czf $(OUTPUT)/shim-live-build.tar.gz .
	date -u +%FT%TZ > $(OUTPUT)/shim-live-finished

guest-function-shim-live: FUNCTION_LIVE_ENV = env FUNCTION_CAPTURE_SHIM=1 BPFREJIT_SHIM_DIR=$(OUTPUT)/live BPFREJIT_SHIM_LOG=$(OUTPUT)/live/shim.log LD_PRELOAD=$(ROOT)/bpfopt/shim/libbpfrejit_shim.so
guest-function-shim-live: guest-function-live

.PHONY: callee-ir
callee-ir: $(BUILD)/kprog-bpf-callee-ir
$(BUILD)/kprog-bpf-callee-ir: $(ROOT)/kprog/x86/bpf_callee_ir.cpp $(ROOT)/kprog/test/build_callee_ir.py $(ROOT)/runner/build-llvmbpf/CMakeFiles/micro_exec.dir/link.txt
	install -d $(BUILD)
	taskset -c $(CPUS) prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/build_callee_ir.py --root $(ROOT) --build $(BUILD)

.PHONY: callee-check
callee-check: compiler
	$(CC) $(FLAGS) -Xclang -fembed-bitcode=all -c $(ROOT)/kprog/test/bpf_callee_abi.c -o $(BUILD)/callee-abi-input.o
	python3 $(ROOT)/kprog/test/check_bpf_callee_abi.py --build $(BUILD) --compiler $(BUILD)/perf-context-lto --kernel $(KERNEL)/vmlinux --linker $(ROOT)/kprog/x86/native_lab/native_link/target/release/native-link --output $(OUTPUT)
	tar -C $(BUILD) -czf $(OUTPUT)/callee-abi-build.tar.gz .
	date -u +%FT%TZ > $(OUTPUT)/callee-abi-finished

-include $(BUILD)/bpf-callee-ir.compile.d $(BUILD)/bpf-callee-ir.link.d

.PHONY: upstream-cel-check
upstream-cel-check: compiler
	cd $(ROOT)/vendor/repos/tetragon && GOMAXPROCS=1 GOFLAGS=-p=1 go build -mod=vendor -o $(BUILD)/upstream-cel-export $(ROOT)/kprog/test/export_tetragon_cel.go
	$(BUILD)/upstream-cel-export > $(OUTPUT)/upstream-cel.json
	$(CC) $(FLAGS) -Xclang -fembed-bitcode=all -c $(ROOT)/kprog/test/tetragon_cel_native.c -o $(BUILD)/tetragon-cel-input.o
	python3 $(ROOT)/kprog/test/check_tetragon_cel.py --build $(BUILD) --output $(OUTPUT) --compiler $(BUILD)/perf-context-lto --kernel $(KERNEL)/vmlinux --linker $(ROOT)/kprog/x86/native_lab/native_link/target/release/native-link
	tar -C $(BUILD) -czf $(OUTPUT)/upstream-cel-build.tar.gz .
	date -u +%FT%TZ > $(OUTPUT)/upstream-cel-finished

CEL_CASES ?= /workspaces/kprog-raw/perf/20261116-upstream-cel/upstream-cel.json
.PHONY: upstream-cel-b upstream-cel-stock guest-upstream-cel-stock
upstream-cel-b: compiler
	$(CC) $(FLAGS) -DCEL_STOCK_ENTRY -Xclang -fembed-bitcode=all -c $(ROOT)/kprog/test/tetragon_cel_native.c -o $(BUILD)/cel-stock-input.o
	python3 $(ROOT)/kprog/test/build_tetragon_cel_b.py --build $(BUILD) --output $(OUTPUT) --cases $(CEL_CASES) --compiler $(BUILD)/perf-context-lto --kernel $(KERNEL)/vmlinux --linker $(ROOT)/kprog/x86/native_lab/native_link/target/release/native-link --bounds /var/tmp/kprog-tmp/perf/context-loads-v2/packet-bounds
	tar -C $(BUILD) -czf $(OUTPUT)/cel-b-build.tar.gz .
	date -u +%FT%TZ > $(OUTPUT)/cel-b-finished

upstream-cel-stock:
	$(CC) -O2 -Wall -Wextra -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include $(ROOT)/kprog/test/context_table_stock.c $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o $(BUILD)/cel-stock-loader
	install -d $(OUTPUT)/inputs $(OUTPUT)/stock
	flock -s /workspaces/.agent-state/kprog-lanes/locks/image taskset -c $(CPUS) prlimit --as=8589934592 -- vng --run $(KERNEL)/arch/x86/boot/bzImage --cwd $(ROOT) --rodir $(OUTPUT)/inputs=$(BUILD) --rwdir $(OUTPUT) --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/perf-context-lto.mk guest-upstream-cel-stock OUTPUT=$(OUTPUT)'
	date -u +%FT%TZ > $(OUTPUT)/cel-stock-finished

guest-upstream-cel-stock:
	for object in $(OUTPUT)/inputs/cel-*.bpf.o; do name=$$(basename "$$object" .bpf.o); $(OUTPUT)/inputs/cel-stock-loader "$$object" trusted_x86_x86_sim_xdp $(OUTPUT)/stock/$$name.verifier.log > $(OUTPUT)/stock/$$name.json; done
