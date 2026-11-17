PYTHON ?= python3
ARCH ?= x86
CC_x86 ?= cc
CC_arm64 ?= aarch64-linux-gnu-gcc
BUILD := build-$(ARCH)
CASES ?= 1024
OUT ?= ../results/kprog_fidelity_20261106/differential
HEADERS := $(wildcard ../$(ARCH)/*.h ../formal/generated/*.h)
ENCODER_SOURCES := $(wildcard ../$(ARCH)/micro-prog/*.py)

.PHONY: build run run-built run-emulated
build: $(BUILD)/cpu-differential

$(BUILD)/generated.c $(BUILD)/native.S &: generate.py $(ENCODER_SOURCES) $(HEADERS) ../helper_abi.py
	install -d $(BUILD)
	$(PYTHON) generate.py --arch $(ARCH) --out $(BUILD)

$(BUILD)/generated.o: $(BUILD)/generated.c driver.h $(HEADERS)
	$(CC_$(ARCH)) -O1 -g -std=gnu11 -Werror=implicit-function-declaration \
		-I../../vendor/libbpf/src -I../../vendor/libbpf/include/uapi -c $< -o $@

$(BUILD)/cpu-differential: $(BUILD)/generated.o $(BUILD)/native.S driver.c driver.h
	$(CC_$(ARCH)) -O1 -g -std=gnu11 -static driver.c $(BUILD)/generated.o $(BUILD)/native.S -o $@

run: build

run run-built:
	test -x ./$(BUILD)/cpu-differential
	install -d $(OUT)
	./$(BUILD)/cpu-differential $(CASES) $(OUT)

run-emulated: build
	install -d $(OUT)
	qemu-aarch64-static ./$(BUILD)/cpu-differential $(CASES) $(OUT)

.PHONY: run-handoff
ARM64_HANDOFF ?= ../results/kprog_fidelity_20261107/differential/arm64-current-core/cpu-differential-arm64.gz
run-handoff:
	install -d build-arm64 $(OUT)
	gzip -dc $(ARM64_HANDOFF) > build-arm64/cpu-differential-handoff
	chmod +x build-arm64/cpu-differential-handoff
	./build-arm64/cpu-differential-handoff $(CASES) $(OUT)

.PHONY: check-loader-kallsyms
LOADER_HEADERS := $(wildcard ../libnativeloader/src/*.hpp)
build-x86/test-kallsyms: test_kallsyms.cpp ../libnativeloader/src/native_loader.cpp $(LOADER_HEADERS)
	install -d build-x86
	$(CXX) -O2 -std=c++20 -I../libnativeloader/include -I../../micro/programs/build-x86 \
		-I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/include \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		$< ../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o $@

check-loader-kallsyms: build-x86/test-kallsyms
	./build-x86/test-kallsyms ../x86/native_lab/native_link/target/release/native-link

.PHONY: check-loader-data-symbols
build-x86/test_data_symbol_bounds: test_data_symbol_bounds.cpp test_data_symbol_bounds.S ../libnativeloader/src/native_loader.cpp $(LOADER_HEADERS)
	install -d build-x86
	$(CC_x86) -c test_data_symbol_bounds.S -o build-x86/data-symbols.o
	$(CXX) -O2 -std=c++20 -I../libnativeloader/include -I../../micro/programs/build-x86 \
		-I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/include \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		$< ../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o $@

check-loader-data-symbols: build-x86/test_data_symbol_bounds
	./build-x86/test_data_symbol_bounds build-x86/data-symbols.o

.PHONY: check-loader-verifier-log
build-x86/test_verifier_log: test_verifier_log.cpp ../libnativeloader/src/native_loader.cpp $(LOADER_HEADERS)
	install -d build-x86
	$(CXX) -O2 -std=c++20 -I../libnativeloader/include -I../../micro/programs/build-x86 \
		-I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/include \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		$< ../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o $@

check-loader-verifier-log: build-x86/test_verifier_log
	./build-x86/test_verifier_log

.PHONY: check-loader-data-layout
build-x86/test_data_symbol_layout: test_data_symbol_layout.cpp ../libnativeloader/src/native_loader.cpp $(LOADER_HEADERS)
	install -d build-x86
	$(CXX) -O2 -std=c++20 -I../libnativeloader/include -I../../micro/programs/build-x86 \
		-I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/include \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		$< ../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o $@

check-loader-data-layout: build-x86/test_data_symbol_layout
	./build-x86/test_data_symbol_layout build-x86/data-symbols.o

.PHONY: tcb
TCB_OUT ?= ../results/kprog_fidelity_20261106/tcb
tcb:
	$(PYTHON) tcb.py --out $(TCB_OUT)

.PHONY: reference-build reference-check
reference-build:
	cd ../formal && lake build reference

reference-check: build reference-build
	$(PYTHON) reference_check.py --binary ./$(BUILD)/cpu-differential --arch $(ARCH) --cases $(CASES) --out $(OUT) --control-paths

.PHONY: check-stack-memory
check-stack-memory:
	install -d build-x86
	set -e; for name in stack_arm stack_arena stack_write_lanes stack_write_tag_action stack_read_tag_source helper_arg_ptr; do \
		$(CC) -Wall -Wextra -O2 -I../formal -I../arm64 -I.. -I../../vendor/libbpf/src ../formal/oracles/test_arm64_$${name}_route_host.c -o build-x86/$${name}-check; \
		./build-x86/$${name}-check; \
	done

.PHONY: check-memory-operands
check-memory-operands:
	install -d build-x86
	$(CC) -Wall -Wextra -O2 -I../formal -I../x86 -I.. -I../../vendor/libbpf/src ../formal/oracles/test_x86_imul_route_host.c -o build-x86/imul-memory-check
	./build-x86/imul-memory-check
	$(CC) -Wall -Wextra -O2 -I../formal -I../x86 -I.. -I../../vendor/libbpf/src ../formal/oracles/test_x86_bt_route_host.c -o build-x86/bt-memory-check
	./build-x86/bt-memory-check
	$(CC) -Wall -Wextra -O2 -I../formal -I../x86 -I.. -I../../vendor/libbpf/src ../formal/oracles/btmem_index_route_host.c -o build-x86/btmem-index-check
	./build-x86/btmem-index-check

.PHONY: check-arm64-simd
check-arm64-simd:
	install -d build-x86
	set -e; for name in fmov_route_host test_arm64_reduction_route_host test_arm64_extrev_route_host value_route_host mul_route_host test_arm64_dispatch_singleton_route_host; do \
		$(CC) -Wall -Wextra -O2 -I../formal -I../arm64 -I.. -I../../vendor/libbpf/src ../formal/oracles/$$name.c -o build-x86/$$name; \
		./build-x86/$$name; \
	done

.PHONY: scale-build scale-kvm scale-guest
SCALE_BUILD ?= build-x86/scale
SCALE_SIZES ?= 100 1000 10000 100000
SCALE_OUT ?= ../results/kprog_fidelity_20261106/scale/x86
SCALE_RECORDS ?= $(SCALE_BUILD)
SCALE_ARGS ?=
SCALE_WAIT_PID ?= 0
SCALE_BATCH_ARGS ?=
.PHONY: scale-stock-batch
scale-stock-batch:
	$(PYTHON) scale_batch.py --build $(abspath $(SCALE_BUILD)) --records $(abspath $(SCALE_RECORDS)) --out $(abspath $(SCALE_OUT)) --wait-pid $(SCALE_WAIT_PID) $(SCALE_BATCH_ARGS)

.PHONY: scale-records-test
scale-records-test:
	$(PYTHON) -m unittest test_scale_records

scale-build:
	install -d build-x86
	$(CC) -Wall -Wextra -Werror -O2 -I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		scale_probe.c ../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o build-x86/scale-probe
	$(PYTHON) scale.py build --build $(SCALE_BUILD) --records $(SCALE_RECORDS) --sizes $(SCALE_SIZES) $(SCALE_ARGS)

scale-kvm:
	install -d $(SCALE_OUT)
	date -u +%FT%TZ > $(SCALE_OUT)/started
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	status=0; taskset -c 18-19 prlimit --as=17179869184 -- vng \
		--run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd $(ROOT) --disable-monitor --cpus 2 --memory 8G --rwdir $(ROOT) \
		--rwdir /var/tmp=$(abspath $(SCALE_BUILD)) --rwdir $(abspath $(SCALE_OUT)) --overlay-rwdir /tmp \
		--append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C $(ROOT)/kprog/fidelity scale-guest SCALE_BUILD=/var/tmp SCALE_OUT=$(abspath $(SCALE_OUT)) SCALE_RECORDS=$(abspath $(SCALE_RECORDS))' || status=$$?; \
	printf '%s\n' "$$status" > $(SCALE_OUT)/exit-code; date -u +%FT%TZ > $(SCALE_OUT)/finished; exit $$status

scale-guest:
	@mountpoint -q /sys/kernel/tracing || mount -t tracefs tracefs /sys/kernel/tracing
	printf '%s\n' 'p:kprog_f_check bpf_check' 'r:kprog_f_check_ret bpf_check' >> /sys/kernel/tracing/kprobe_events
	$(PYTHON) scale.py check --build $(SCALE_BUILD) --records $(SCALE_RECORDS) --out $(SCALE_OUT)

.PHONY: arm64-control-build arm64-control-qemu
ARM64_CONTROL_BUILD ?= build-arm64-control
ARM64_CONTROL_OUT ?= ../results/kprog_fidelity_20261106/differential/arm64-control-qemu
arm64-control-build:
	$(PYTHON) arm64_control.py $(ARM64_CONTROL_BUILD)
	aarch64-linux-gnu-gcc -O1 -g -std=gnu11 -static -I../../vendor/libbpf/src \
		driver.c $(ARM64_CONTROL_BUILD)/generated.c $(ARM64_CONTROL_BUILD)/native.o \
		-Wl,--section-start=.kprog_native=0x1000000 -o $(ARM64_CONTROL_BUILD)/cpu-differential

arm64-control-qemu:
	install -d $(ARM64_CONTROL_OUT)
	qemu-aarch64-static $(ARM64_CONTROL_BUILD)/cpu-differential $(CASES) $(ARM64_CONTROL_OUT)

.PHONY: reference-replay
reference-replay: reference-build
	$(PYTHON) reference_check.py --reuse-trace --binary ./$(BUILD)/cpu-differential --arch $(ARCH) --cases $(CASES) --out $(OUT) --control-paths

.PHONY: arm64-control-handoff
ARM64_CONTROL_HANDOFF ?= ../results/kprog_fidelity_20261107/differential/arm64-control-branches/cpu-differential-arm64.gz
arm64-control-handoff:
	install -d $(ARM64_CONTROL_BUILD) $(ARM64_CONTROL_OUT)
	gzip -dc $(ARM64_CONTROL_HANDOFF) > $(ARM64_CONTROL_BUILD)/cpu-differential-handoff
	chmod +x $(ARM64_CONTROL_BUILD)/cpu-differential-handoff
	./$(ARM64_CONTROL_BUILD)/cpu-differential-handoff $(CASES) $(ARM64_CONTROL_OUT)

.PHONY: check-stack-base-flags
check-stack-base-flags:
	install -d build-x86
	$(CC) -O2 -I../formal -I../../vendor/libbpf/src test_stack_base_flags.c -o build-x86/stack-base-flags
	./build-x86/stack-base-flags

.PHONY: x86-control-build x86-control-run
X86_CONTROL_BUILD ?= build-x86-control
X86_CONTROL_OUT ?= ../results/kprog_fidelity_20261107/differential/x86-control
$(X86_CONTROL_BUILD)/generated.c $(X86_CONTROL_BUILD)/native.o &: x86_control.py generate.py tcb.py driver.c driver.h control_inputs.c control_inputs.h control_trace.cpp Makefile ../helper_abi.py ../trusted_generation.py ../../kinsn/module/include/native_lab_input.h $(wildcard ../x86/micro-prog/*.py ../x86/*.h ../formal/generated/*.h)
	$(PYTHON) x86_control.py $(X86_CONTROL_BUILD)

$(X86_CONTROL_BUILD)/cpu-differential: $(X86_CONTROL_BUILD)/generated.c $(X86_CONTROL_BUILD)/native.o driver.c driver.h control_inputs.c control_inputs.h
	$(CC_x86) -O1 -g -std=gnu11 -static -I../../vendor/libbpf/src \
		driver.c control_inputs.c $(X86_CONTROL_BUILD)/generated.c $(X86_CONTROL_BUILD)/native.o \
		-Wl,--section-start=.kprog_native=0x1000000 -o $@

$(X86_CONTROL_BUILD)/control-trace: control_trace.cpp
	install -d $(X86_CONTROL_BUILD)
	$(CXX) -O2 -std=c++20 -Wall -Wextra -Werror $< -lelf -o $@

x86-control-build: $(X86_CONTROL_BUILD)/cpu-differential $(X86_CONTROL_BUILD)/control-trace

x86-control-run: x86-control-build
	install -d $(X86_CONTROL_OUT)
	./$(X86_CONTROL_BUILD)/control-trace ./$(X86_CONTROL_BUILD)/cpu-differential $(CASES) $(X86_CONTROL_OUT) $(X86_CONTROL_OUT)/cpu-states.bin

PREPROCESS_SIZES ?= 100 1000
PREPROCESS_ARGS ?=
PREPROCESS_AS ?= 8589934592
PREPROCESS_CPUS ?= 8-11
.PHONY: preprocess-profile
preprocess-profile:
	taskset -c $(PREPROCESS_CPUS) prlimit --as=$(PREPROCESS_AS) -- python3 /workspaces/repository/kprog/test/profile_b_preprocess.py --sizes $(PREPROCESS_SIZES) $(PREPROCESS_ARGS) --build $(SCALE_BUILD) --output $(SCALE_OUT)
