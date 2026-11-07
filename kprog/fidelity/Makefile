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
ARM64_HANDOFF ?= ../results/kprog_fidelity_20261107/differential/arm64-current-logical/cpu-differential-arm64.gz
run-handoff:
	install -d build-arm64 $(OUT)
	gzip -dc $(ARM64_HANDOFF) > build-arm64/cpu-differential-handoff
	chmod +x build-arm64/cpu-differential-handoff
	./build-arm64/cpu-differential-handoff $(CASES) $(OUT)

.PHONY: negative-build negative-guest
NEGATIVE_BUILD ?= $(BUILD)/negative
NEGATIVE_OUT ?= ../results/kprog_fidelity_20261106/negative/$(ARCH)
LOADER ?= ../loader/target/debug/reversesim-loader
negative-build:
	$(PYTHON) negative.py build --arch $(ARCH) --build $(NEGATIVE_BUILD)

negative-guest:
	$(PYTHON) negative.py run --arch $(ARCH) --build $(NEGATIVE_BUILD) --out $(NEGATIVE_OUT) --loader $(LOADER)

ROOT := $(abspath ../..)
.PHONY: negative-kvm negative-qemu
negative-kvm:
	vng --run $(ROOT)/vendor/build/x86/linux/arch/x86/boot/bzImage \
		--cwd $(ROOT) --disable-monitor --cpus 8 --mem 12G \
		--rwdir $(ROOT) --overlay-rwdir /tmp \
		--exec 'make -C $(ROOT)/kprog/fidelity negative-guest NEGATIVE_OUT=$(NEGATIVE_OUT)'

build-arm64/negative-init: negative_init.c
	install -d build-arm64
	aarch64-linux-gnu-gcc -Wall -Wextra -Werror -O2 -static $< -o $@

build-arm64/negative.cpio: build-arm64/negative-init build-arm64/negative/build.json negative.py
	$(PYTHON) negative.py package --arch arm64 --build build-arm64/negative

ARM_NEGATIVE_OUT ?= ../results/kprog_fidelity_20261106/negative/arm64
negative-qemu: build-arm64/negative.cpio
	install -d $(ARM_NEGATIVE_OUT)
	timeout 240 qemu-system-aarch64 -M virt -cpu cortex-a57 -smp 2 -m 2048 \
		-nographic -no-reboot -kernel $(ROOT)/vendor/build/arm64/linux/arch/arm64/boot/Image \
		-initrd build-arm64/negative.cpio -append 'console=ttyAMA0 rdinit=/init panic=-1' \
		> $(ARM_NEGATIVE_OUT)/guest-console.log 2>&1
	$(PYTHON) negative.py collect --arch arm64 --build build-arm64/negative --out $(ARM_NEGATIVE_OUT)

.PHONY: check-loader-kallsyms
build-x86/test-kallsyms: test_kallsyms.cpp ../libnativeloader/src/native_loader.cpp
	install -d build-x86
	$(CXX) -O2 -std=c++20 -I../libnativeloader/include -I../../micro/programs/build-x86 \
		-I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/include \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		$< ../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o $@

check-loader-kallsyms: build-x86/test-kallsyms
	./build-x86/test-kallsyms ../x86/native_lab/native_link/target/release/native-link

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

.PHONY: bound-probe-build
.PHONY: check-arm64-simd
check-arm64-simd:
	install -d build-x86
	set -e; for name in fmov_route_host test_arm64_reduction_route_host test_arm64_extrev_route_host value_route_host mul_route_host test_arm64_dispatch_singleton_route_host; do \
		$(CC) -Wall -Wextra -O2 -I../formal -I../arm64 -I.. -I../../vendor/libbpf/src ../formal/oracles/$$name.c -o build-x86/$$name; \
		./build-x86/$$name; \
	done

bound-probe-build:
	$(MAKE) -C ../libnativeloader BUILD_DIR=build-fidelity
	install -d build-x86
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 -D__EXPORTED_HEADERS__ \
		-I../../vendor/linux-framework/include/uapi -I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		bound_probe.cpp ../libnativeloader/build-fidelity/libnative_loader.a \
		../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o build-x86/bound-probe
	clang -O2 -g -target bpf -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src \
		-I/usr/include/x86_64-linux-gnu -c negative_companion.bpf.c -o build-x86/negative-companion.bpf.o

.PHONY: negative-bound-kvm negative-bound-guest
NEGATIVE_BOUND_OUT ?= ../results/kprog_fidelity_20261106/negative/x86-bound
negative-bound-kvm:
	vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage \
		--cwd $(ROOT) --disable-monitor --cpus 2 --mem 2G --rwdir $(ROOT) --overlay-rwdir /tmp \
		--exec 'make -C $(ROOT)/kprog/fidelity negative-bound-guest NEGATIVE_BOUND_OUT=$(NEGATIVE_BOUND_OUT) NEGATIVE_BUILD=$(NEGATIVE_BUILD)'

negative-bound-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod ../tv/build-x86/bpf_x86_native_lab.ko
	$(PYTHON) negative.py bound --arch x86 --build $(NEGATIVE_BUILD) \
		--out $(NEGATIVE_BOUND_OUT) \
		--probe build-x86/bound-probe --companion build-x86/negative-companion.bpf.o

.PHONY: bound-probe-build-arm64 negative-bound-qemu
bound-probe-build-arm64:
	CC=aarch64-linux-gnu-gcc CXX=aarch64-linux-gnu-g++ \
		PKG_CONFIG_SYSROOT_DIR=$(ROOT)/.cache/aarch64-sysroot \
		PKG_CONFIG_LIBDIR=$(ROOT)/.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu/pkgconfig \
		$(MAKE) -C ../libnativeloader BUILD_DIR=build-fidelity-arm64 \
		LIBBPF_PREFIX=$(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/prefix \
		LIBBPF_LIBRARY=$(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/pic-obj/libbpf.a \
		KERNEL_OFFSETS_INCLUDE=$(ROOT)/micro/programs/build-arm64
	install -d build-arm64
	aarch64-linux-gnu-g++ -std=c++20 -Wall -Wextra -Werror -O2 -static \
		-D__EXPORTED_HEADERS__ -DNATIVE_LINK_PATH='"/native-link"' \
		-I../../vendor/linux-framework/include/uapi -I../../runner/build-arm64-llvmbpf/vendor/libbpf/prefix/include \
		bound_probe.cpp ../libnativeloader/build-fidelity-arm64/libnative_loader.a \
		../../runner/build-arm64-llvmbpf/vendor/libbpf/pic-obj/libbpf.a \
		-L../../.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu -lelf -lz -lzstd -ldl -pthread -o build-arm64/bound-probe
	clang -O2 -g -target bpf -I../../vendor/libbpf/include/uapi -I../../vendor/libbpf/src \
		-I/usr/include/x86_64-linux-gnu -c negative_companion.bpf.c -o build-arm64/negative-companion.bpf.o
	CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER=aarch64-linux-gnu-gcc \
		cargo build --release --target aarch64-unknown-linux-gnu --manifest-path ../x86/native_lab/native_link/Cargo.toml

ARM_NEGATIVE_BOUND_OUT ?= ../results/kprog_fidelity_20261106/negative/arm64-bound
ARM_NEGATIVE_BOUND_BUILD ?= build-arm64/negative-bound
negative-bound-qemu: bound-probe-build-arm64
	$(MAKE) negative-build ARCH=arm64 NEGATIVE_BUILD=$(ARM_NEGATIVE_BOUND_BUILD)
	aarch64-linux-gnu-gcc -Wall -Wextra -Werror -O2 -static -DBOUND_NEGATIVE negative_init.c -o build-arm64/negative-bound-init
	$(PYTHON) negative.py package-bound --arch arm64 --build $(ARM_NEGATIVE_BOUND_BUILD)
	install -d $(ARM_NEGATIVE_BOUND_OUT)
	timeout 240 qemu-system-aarch64 -M virt -cpu cortex-a57 -smp 2 -m 2048 \
		-nographic -no-reboot -kernel $(ROOT)/kprog/tv/build-kernel-arm64/arch/arm64/boot/Image \
		-initrd build-arm64/negative-bound.cpio -append 'console=ttyAMA0 rdinit=/init panic=-1' \
		> $(ARM_NEGATIVE_BOUND_OUT)/guest-console.log 2>&1
	$(PYTHON) negative.py collect-bound --arch arm64 --build $(ARM_NEGATIVE_BOUND_BUILD) --out $(ARM_NEGATIVE_BOUND_OUT)

.PHONY: stage2-build stage2-kvm stage2-guest
STAGE2_BUILD ?= build-x86/stage2
STAGE2_OUT ?= ../results/kprog_fidelity_20261106/helper-map/x86
stage2-build: bound-probe-build
	$(PYTHON) stage2.py build --build $(STAGE2_BUILD)

stage2-kvm:
	vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage \
		--cwd $(ROOT) --disable-monitor --cpus 2 --mem 2G --rwdir $(ROOT) --overlay-rwdir /tmp \
		--exec 'make -C $(ROOT)/kprog/fidelity stage2-guest STAGE2_BUILD=$(STAGE2_BUILD) STAGE2_OUT=$(STAGE2_OUT)'

stage2-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod ../tv/build-x86/bpf_x86_native_lab.ko
	$(PYTHON) stage2.py check --build $(STAGE2_BUILD) --out $(STAGE2_OUT)

.PHONY: scale-build scale-kvm scale-guest
SCALE_BUILD ?= build-x86/scale
SCALE_SIZES ?= 100 1000 10000 100000
SCALE_OUT ?= ../results/kprog_fidelity_20261106/scale/x86
scale-build:
	install -d build-x86
	$(CC) -Wall -Wextra -Werror -O2 -I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		scale_probe.c ../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o build-x86/scale-probe
	$(PYTHON) scale.py build --build $(SCALE_BUILD) --sizes $(SCALE_SIZES)

scale-kvm:
	vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage \
		--cwd $(ROOT) --disable-monitor --cpus 2 --mem 2G --rwdir $(ROOT) --overlay-rwdir /tmp \
		--exec 'make -C $(ROOT)/kprog/fidelity scale-guest SCALE_BUILD=$(SCALE_BUILD) SCALE_OUT=$(SCALE_OUT)'

scale-guest:
	@mountpoint -q /sys/kernel/tracing || mount -t tracefs tracefs /sys/kernel/tracing
	printf '%s\n' 'p:kprog_f_check bpf_check' 'r:kprog_f_check_ret bpf_check' >> /sys/kernel/tracing/kprobe_events
	$(PYTHON) scale.py check --build $(SCALE_BUILD) --out $(SCALE_OUT)

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
ARM64_CONTROL_HANDOFF ?= ../results/kprog_fidelity_20261106/differential/cpu-differential-arm64-control.gz
arm64-control-handoff:
	install -d $(ARM64_CONTROL_BUILD) $(ARM64_CONTROL_OUT)
	gzip -dc $(ARM64_CONTROL_HANDOFF) > $(ARM64_CONTROL_BUILD)/cpu-differential-handoff
	chmod +x $(ARM64_CONTROL_BUILD)/cpu-differential-handoff
	./$(ARM64_CONTROL_BUILD)/cpu-differential-handoff $(CASES) $(ARM64_CONTROL_OUT)

.PHONY: stage2-arm64-build stage2-arm64-qemu
ARM_STAGE2_BUILD ?= build-arm64/stage2-bound
ARM_STAGE2_OUT ?= ../results/kprog_fidelity_20261106/helper-map/arm64
stage2-arm64-build: bound-probe-build-arm64
	$(PYTHON) stage2.py build --arch arm64 --build $(ARM_STAGE2_BUILD)

stage2-arm64-qemu:
	aarch64-linux-gnu-gcc -Wall -Wextra -Werror -O2 -static -DBOUND_STAGE2 negative_init.c -o build-arm64/stage2-init
	$(PYTHON) stage2.py package --arch arm64 --build $(ARM_STAGE2_BUILD)
	install -d $(ARM_STAGE2_OUT)
	timeout 600 qemu-system-aarch64 -M virt -cpu cortex-a57 -smp 2 -m 2048 \
		-nographic -no-reboot -kernel $(ROOT)/kprog/tv/build-kernel-arm64/arch/arm64/boot/Image \
		-initrd $(ARM_STAGE2_BUILD)/stage2.cpio -append 'console=ttyAMA0 rdinit=/init panic=-1' \
		> $(ARM_STAGE2_OUT)/guest-console.log 2>&1
	$(PYTHON) stage2.py collect --arch arm64 --build $(ARM_STAGE2_BUILD) --out $(ARM_STAGE2_OUT)

.PHONY: check-stack-base-flags
check-stack-base-flags:
	install -d build-x86
	$(CC) -O2 -I../formal -I../../vendor/libbpf/src test_stack_base_flags.c -o build-x86/stack-base-flags
	./build-x86/stack-base-flags
