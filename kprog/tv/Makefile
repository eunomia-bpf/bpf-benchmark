ARCH ?= x86
KDIR ?= $(abspath ../../vendor/build/$(ARCH)/linux)
CROSS_arm64 := aarch64-linux-gnu-

.PHONY: check binding-check module-check kernel-check guest-kernel-check kernel-check-arm64 inventory

check: binding-check data-layout-check manifest-check
	python3 test_kernel_patch.py
	cd ../formal && lake build KProgFormal.Reference.Memory
	cd ../formal && lake env lean ../tv/Composition.lean
	$(MAKE) bpf-check

.PHONY: environment-check
environment-check: build/test-environment-binding build/exclusive-input.bpf.o build/test-exclusive-host
	./build/test-environment-binding
	python3 test_exclusive_wire.py
	python3 test_kernel_patch.py

build/exclusive-input.bpf.o: exclusive_input.bpf.c ../../kinsn/module/include/native_lab_input.h
	install -d build
	clang -O2 -target bpf -c $< -o $@

build/test-exclusive-host: test_exclusive_host.c ../../kinsn/module/include/native_lab_input.h
	install -d build
	$(CC) -std=gnu11 -Wall -Wextra -Werror -O2 -fsanitize=address,undefined $< -o $@

build/test-environment-binding: test_environment_binding.cpp ../libnativeloader/src/native_environment_binding.hpp ../libnativeloader/src/native_loader_manifest.hpp ../../kinsn/module/include/native_lab_exclusive.h ../../kinsn/module/include/native_lab_input.h
	install -d build
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 -fsanitize=address,undefined $< -o $@

.PHONY: bpf-check cmov-check cmov-certificate cmov-negative-check
bpf-check:
	install -d build
	cd ../formal && lake env lean -R ../tv -o ../tv/build/Composition.olean ../tv/Composition.lean
	cd ../formal && lake env lean -R ../tv -o ../tv/build/BPF.olean ../tv/BPF.lean
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv -o ../tv/build/BPFPath.olean ../tv/BPFPath.lean
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv ../tv/BPFChecks.lean
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv -o ../tv/build/BPFPlatform.olean ../tv/BPFPlatform.lean

build/CompiledBlocks.lean: build/cmov-block.bpf.o extract_blocks.py
	python3 extract_blocks.py $< $@

CMOV_BLOCK_DIR ?= build
cmov-check: bpf-check build/CompiledBlocks.lean
	$(MAKE) cmov-certificate

cmov-certificate:
	cd ../formal && LEAN_PATH=../tv/$(CMOV_BLOCK_DIR):../tv/build lake env lean -R ../tv/$(CMOV_BLOCK_DIR) \
		-o ../tv/$(CMOV_BLOCK_DIR)/CompiledBlocks.olean ../tv/$(CMOV_BLOCK_DIR)/CompiledBlocks.lean
	cd ../formal && LEAN_PATH=../tv/$(CMOV_BLOCK_DIR):../tv/build lake env lean -R ../tv ../tv/CmovCertificate.lean

cmov-negative-check: cmov-check
	python3 test_compiled_blocks.py

binding-check: build/test-binding
	./build/test-binding

.PHONY: data-layout-check
data-layout-check: build/test-data-layout
	./build/test-data-layout

build/test-data-layout: test_data_layout.cpp ../libnativeloader/src/native_data_layout.hpp
	install -d build
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 -fsanitize=address,undefined \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include $< \
		../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o $@

build/test-binding: test_binding.c ../../kinsn/module/include/native_lab_binding.h ../../kinsn/module/include/native_lab_map_offset.h
	install -d build
	$(CC) -std=c11 -Wall -Wextra -Werror -O2 -fsanitize=address,undefined $< -o $@

# Build only this module in a lane-owned directory, without replacing the
# shared image or the other lanes' module artifacts.
module-check: build-$(ARCH)/Makefile build-$(ARCH)/bpf_$(ARCH)_native_lab.c
	$(MAKE) -C $(KDIR) M=$(CURDIR)/build-$(ARCH) ARCH=$(ARCH) \
		TV_ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_$(ARCH)) modules

build-$(ARCH)/Makefile: module.mk
	install -d build-$(ARCH)
	cp $< $@

build-$(ARCH)/bpf_$(ARCH)_native_lab.c: ../../kinsn/module/$(ARCH)/bpf_$(ARCH)_native_lab.c
	install -d build-$(ARCH)
	cp $< $@

build/test-binding-kernel: test_binding_kernel.c test_native_inputs.h test_context.h ../../kinsn/module/include/native_lab_input.h ../../kinsn/module/include/native_lab_binding.h
	install -d build
	$(CC) -Wall -Wextra -Werror -O2 -g -D__EXPORTED_HEADERS__ \
		-I../../vendor/linux-framework/include/uapi -I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		$< ../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o $@

kernel-check: kernel-build-x86 build/test-binding-kernel build/test-loader
	test "$(ARCH)" = x86
	$(MAKE) module-check KDIR=$(CURDIR)/build-kernel-x86
	taskset -c 8-23 vng --run $(CURDIR)/build-kernel-x86/arch/x86/boot/bzImage \
		--cwd $(abspath ../..) --rwdir $(abspath ../..) --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/tv guest-kernel-check'

guest-kernel-check:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod build-x86/bpf_x86_native_lab.ko || { dmesg; exit 1; }
	./build/test-binding-kernel
	./build/test-loader

# Diagnose the shared build's stale-header BTF failure without replacing the
# immutable per-lane runtime pairs or adding a benchmark admission gate.
.PHONY: shared-kernel-check guest-shared-kernel-check
shared-kernel-check: build/test-binding-kernel build/test-loader
	$(MAKE) -C ../../vendor/build/x86/linux ARCH=x86 \
		M=$(abspath ../../kinsn/module/x86) MO=$(CURDIR)/build-x86/all-shared-btf modules
	taskset -c 8-23 vng --run $(abspath ../../vendor/build/x86/linux/arch/x86/boot/bzImage) \
		--cwd $(abspath ../..) --rwdir $(abspath ../..) --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/tv guest-shared-kernel-check'

guest-shared-kernel-check:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	for module in build-x86/all-shared-btf/*.ko; do insmod "$$module" || { dmesg; exit 1; }; done
	cat /proc/modules
	./build/test-binding-kernel
	./build/test-loader

build/native-entry.o: test_native_entry.c
	install -d build
	$(CC) -O2 -c -fno-stack-protector -fno-asynchronous-unwind-tables \
		-fno-unwind-tables -fomit-frame-pointer -mno-red-zone -fno-plt $< -o $@

build/simulator.bpf.o: test_simulator.bpf.c
	install -d build
	clang -O2 -g -target bpf -I../../vendor/libbpf/include/uapi \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		-I/usr/include/x86_64-linux-gnu -c $< -o $@

build/cmov-block.bpf.o: cmov_block.bpf.c $(wildcard ../x86/*.h ../formal/generated/*.h)
	install -d build
	clang -O3 -target bpf -I../../vendor/libbpf/include/uapi \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include/bpf \
		-I/usr/include/x86_64-linux-gnu -c $< -o $@

.PHONY: linker-build
linker-build:
	cargo build --release --manifest-path ../x86/native_lab/native_link/Cargo.toml

kernel-check: linker-build

build/test-loader: test_loader.cpp build/bcc-map-probe/manifest.json build/source-value.bpf.o build/source-value-wrong-site.bpf.o build/native-entry.o build/simulator.bpf.o build/runtime-config/simulator.bpf.o build/wrong-capacity/simulator.bpf.o build/wrong-value-size/simulator.bpf.o build/wrong-layout/simulator.bpf.o build/wrong-readonly/simulator.bpf.o build/wrong-data-layout/simulator.bpf.o ../libnativeloader/src/native_loader.cpp \
		$(wildcard ../libnativeloader/src/*.hpp ../libnativeloader/include/*.hpp)
	$(MAKE) -C ../libnativeloader BUILD_DIR=build-tv-binding
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 \
		-DTV_NATIVE_LINK_PATH='"$(TV_NATIVE_LINK)"' \
		-I../../vendor/libbpf/include/uapi \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		$< ../libnativeloader/build-tv-binding/libnative_loader.a \
		../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o $@

TV_NATIVE_LINK ?= ../x86/native_lab/native_link/target/release/native-link

build/wrong-layout/simulator.bpf.o: test_simulator.bpf.c
	install -d build/wrong-layout
	clang -O2 -g -target bpf -Dprivate_zero=unrelated_zero -I../../vendor/libbpf/include/uapi \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		-I/usr/include/x86_64-linux-gnu -c $< -o $@

build/wrong-readonly/simulator.bpf.o: test_simulator.bpf.c
	install -d build/wrong-readonly
	clang -O2 -g -target bpf -DTV_READONLY_WORD=0x1122334400000003ULL -I../../vendor/libbpf/include/uapi \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		-I/usr/include/x86_64-linux-gnu -c $< -o $@

build/wrong-data-layout/simulator.bpf.o: test_simulator.bpf.c
	install -d build/wrong-data-layout
	clang -O2 -g -target bpf -Dtv_readonly_data=unrelated_readonly_data -I../../vendor/libbpf/include/uapi \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		-I/usr/include/x86_64-linux-gnu -c $< -o $@

build-arm64/test-binding-kernel: test_binding_kernel.c test_native_inputs.h test_context.h ../../kinsn/module/include/native_lab_input.h ../../kinsn/module/include/native_lab_binding.h
	install -d build-arm64
	aarch64-linux-gnu-gcc -Wall -Wextra -Werror -O2 -g -static -D__EXPORTED_HEADERS__ \
		-I../../vendor/linux-framework/include/uapi -I../../runner/build-arm64-llvmbpf/vendor/libbpf/prefix/include \
		$< ../../runner/build-arm64-llvmbpf/vendor/libbpf/pic-obj/libbpf.a \
		-L../../.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu -lelf -lz -lzstd -o $@

TV_ARM64_KERNEL_PREREQUISITE ?= kernel-build-arm64
kernel-check-arm64: build-arm64/test-binding-kernel
	$(MAKE) $(TV_ARM64_KERNEL_PREREQUISITE)
	$(MAKE) module-check ARCH=arm64 KDIR=$(CURDIR)/build-kernel-arm64
	install -d build-arm64/initramfs/sys build-arm64/initramfs/proc build-arm64/initramfs/dev
	cp build-arm64/test-binding-kernel build-arm64/initramfs/init
	cp build-arm64/bpf_arm64_native_lab.ko build-arm64/initramfs/module.ko
	cd build-arm64/initramfs && find . -print0 | cpio --null -o --format=newc > ../initramfs.cpio
	timeout 180 taskset -c 8-23 qemu-system-aarch64 -M virt -cpu cortex-a72 \
		-accel tcg,thread=multi -smp 2 -m 2048 -nographic -no-reboot \
		-kernel build-kernel-arm64/arch/arm64/boot/Image \
		-initrd build-arm64/initramfs.cpio -append 'console=ttyAMA0 rdinit=/init panic=1' \
		> build-arm64/kernel.log 2>&1
	cat build-arm64/kernel.log
	rg -q '^kernel binding regression: PASS' build-arm64/kernel.log

inventory:
	python3 inventory.py --out ../results/kprog_tv_20261106/programs.jsonl

.PHONY: kernel-build-x86 kernel-build-arm64
kernel-build-x86: build-kernel-x86/.copied
	python3 apply_kernel_patch.py
	$(MAKE) -C ../../vendor/linux-framework O=$(CURDIR)/build-kernel-x86 \
		ARCH=x86 -j8 bzImage
	cp build-kernel-x86/vmlinux.symvers build-kernel-x86/Module.symvers

build-kernel-x86/.copied:
	install -d build-kernel-x86
	cp -a --reflink=auto ../../vendor/build/x86/linux/. build-kernel-x86/
	touch $@

kernel-build-arm64: build-kernel-arm64/.copied
	python3 apply_kernel_patch.py
	$(MAKE) -C ../../vendor/linux-framework O=$(CURDIR)/build-kernel-arm64 \
		ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- -j8 Image
	cp build-kernel-arm64/vmlinux.symvers build-kernel-arm64/Module.symvers

build-kernel-arm64/.copied:
	install -d build-kernel-arm64
	cp -a --reflink=auto ../../vendor/build/arm64/linux/. build-kernel-arm64/
	touch $@

.PHONY: input-check
build/input-block.bpf.o: input_block.bpf.c ../../kinsn/module/include/native_lab_input.h
	install -d build
	clang -O2 -target bpf -c $< -o $@

build/inputs/CompiledBlocks.lean: build/input-block.bpf.o extract_blocks.py
	install -d build/inputs
	python3 extract_blocks.py $< $@

INPUT_BLOCK_DIR ?= build/inputs
input-check: bpf-check build/inputs/CompiledBlocks.lean
	$(MAKE) input-certificate

.PHONY: input-certificate input-negative-check
input-certificate:
	cd ../formal && LEAN_PATH=../tv/$(INPUT_BLOCK_DIR):../tv/build lake env lean -R ../tv/$(INPUT_BLOCK_DIR) \
		-o ../tv/$(INPUT_BLOCK_DIR)/CompiledBlocks.olean ../tv/$(INPUT_BLOCK_DIR)/CompiledBlocks.lean
	cd ../formal && LEAN_PATH=../tv/$(INPUT_BLOCK_DIR):../tv/build lake env lean -R ../tv ../tv/InputCertificate.lean

input-negative-check: input-check
	python3 test_compiled_blocks.py input

.PHONY: manifest-check
manifest-check: build/test-manifest
	./build/test-manifest

.PHONY: rodata-metadata-check
rodata-metadata-check: build/test-rodata-metadata
	./build/test-rodata-metadata

build/test-rodata-metadata: test_rodata_metadata.cpp ../libnativeloader/src/native_rodata_binding.hpp ../libnativeloader/src/native_loader_manifest.hpp
	install -d build
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 -fsanitize=address,undefined $< -o $@

build/test-manifest: test_manifest.cpp ../libnativeloader/src/native_loader_manifest.hpp
	install -d build
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 -fsanitize=address,undefined $< -o $@

build-arm64/bound-probe: ../fidelity/bound_probe.cpp ../libnativeloader/include/native_loader.hpp ../libnativeloader/build-tv-context-v2-arm64/libnative_loader.a
	install -d build-arm64
	aarch64-linux-gnu-g++ -std=c++20 -Wall -Wextra -Werror -O2 -static \
		-D__EXPORTED_HEADERS__ -DNATIVE_LINK_PATH='"/native-link"' \
		-I../../vendor/linux-framework/include/uapi -I../../runner/build-arm64-llvmbpf/vendor/libbpf/prefix/include \
		$< ../libnativeloader/build-tv-context-v2-arm64/libnative_loader.a \
		../../runner/build-arm64-llvmbpf/vendor/libbpf/pic-obj/libbpf.a \
		-L../../.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu -lelf -lz -lzstd -ldl -pthread -o $@

build-arm64/stage2-init: ../fidelity/negative_init.c
	install -d build-arm64
	aarch64-linux-gnu-gcc -Wall -Wextra -Werror -O2 -static -DBOUND_STAGE2 $< -o $@

build/runtime-config/simulator.bpf.o: test_simulator.bpf.c
	install -d build/runtime-config
	clang -O2 -g -target bpf -DTV_MAP_MAX_ENTRIES=0 -DTV_MAP_VALUE_SIZE=0 -I../../vendor/libbpf/include/uapi \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		-I/usr/include/x86_64-linux-gnu -c $< -o $@

build/wrong-capacity/simulator.bpf.o: test_simulator.bpf.c
	install -d build/wrong-capacity
	clang -O2 -g -target bpf -DTV_MAP_MAX_ENTRIES=2 -I../../vendor/libbpf/include/uapi \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		-I/usr/include/x86_64-linux-gnu -c $< -o $@

build/wrong-value-size/simulator.bpf.o: test_simulator.bpf.c
	install -d build/wrong-value-size
	clang -O2 -g -target bpf -DTV_MAP_VALUE_SIZE=8 -I../../vendor/libbpf/include/uapi \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		-I/usr/include/x86_64-linux-gnu -c $< -o $@

.PHONY: context-kernel-check guest-context-kernel-check
context-kernel-check: build/capture-context build/context-fields.bpf.o
	taskset -c 8-23 vng --run $(CURDIR)/build-kernel-x86/arch/x86/boot/bzImage \
		--cwd $(abspath ../..) --rwdir $(abspath ../..) --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/tv guest-context-kernel-check'

guest-context-kernel-check:
	install -d build/context-access
	./build/capture-context

.PHONY: context-check
context-check: bpf-check
	python3 extract_context.py
	$(MAKE) context-certificate

CONTEXT_BLOCK_DIR ?= build
.PHONY: context-certificate context-negative-check
context-certificate:
	cd ../formal && LEAN_PATH=../tv/$(CONTEXT_BLOCK_DIR):../tv/build lake env lean -R ../tv/$(CONTEXT_BLOCK_DIR) \
		-o ../tv/$(CONTEXT_BLOCK_DIR)/KernelContexts.olean ../tv/$(CONTEXT_BLOCK_DIR)/KernelContexts.lean
	cd ../formal && LEAN_PATH=../tv/$(CONTEXT_BLOCK_DIR):../tv/build lake env lean -R ../tv ../tv/ContextChecks.lean

context-negative-check: context-check
	python3 test_context_artifacts.py

build/context-fields.bpf.o: context_fields.bpf.c
	install -d build
	clang -O2 -g -target bpf -I../../vendor/libbpf/include/uapi \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		-I/usr/include/x86_64-linux-gnu -c $< -o $@

build/capture-context: capture_context.cpp
	install -d build
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include $< \
		../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o $@

.PHONY: simple-arm64-artifacts
simple-arm64-artifacts:
	python3 prepare_simple_arm64.py
	clang -O2 -g -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_arm64 \
		-I../../vendor/libbpf/include/uapi -I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include/bpf \
		-I/usr/include/x86_64-linux-gnu -c build/simple-arm64/simple.bpf.c -o build/simple-arm64/simple.bpf.o
	aarch64-linux-gnu-objdump -dr build/simple-arm64/native-link/simple.proof.o > build/simple-arm64/native.asm
	llvm-objdump-18 -d build/simple-arm64/simple.bpf.o > build/simple-arm64/proof.asm

.PHONY: native-path-check
native-path-check: bpf-check
	cd ../formal && lake build KProgFormal.Reference.AArch64
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv -o ../tv/build/ARM64Path.olean ../tv/ARM64Path.lean

.PHONY: simple-arm64-counterexample
simple-arm64-counterexample: native-path-check
	python3 extract_simple_arm64.py
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64 lake env lean -R ../tv/build/simple-arm64 \
		-o ../tv/build/simple-arm64/SimpleCompiled.olean ../tv/build/simple-arm64/SimpleCompiled.lean
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64 lake env lean -R ../tv ../tv/SimpleStoreCounterexample.lean

SIMPLE_BLOCK_DIR ?= build/simple-arm64
.PHONY: simple-arm64-certificate simple-arm64-negative-check
simple-arm64-certificate: native-path-check
	python3 extract_simple_arm64.py --directory $(SIMPLE_BLOCK_DIR)
	cd ../formal && LEAN_PATH=../tv/build:../tv/$(SIMPLE_BLOCK_DIR) lake env lean -R ../tv/$(SIMPLE_BLOCK_DIR) \
		-o ../tv/$(SIMPLE_BLOCK_DIR)/SimpleCompiled.olean ../tv/$(SIMPLE_BLOCK_DIR)/SimpleCompiled.lean
	cd ../formal && LEAN_PATH=../tv/build:../tv/$(SIMPLE_BLOCK_DIR) lake env lean -R ../tv ../tv/SimpleStoreCertificate.lean
	cd ../formal && LEAN_PATH=../tv/build:../tv/$(SIMPLE_BLOCK_DIR) lake env lean -R ../tv ../tv/SimpleGuardCertificate.lean

simple-arm64-negative-check: simple-arm64-certificate
	python3 test_simple_artifacts.py

.PHONY: source-map-check
source-map-check: build/test-source-maps
	./build/test-source-maps

build/test-source-maps: test_source_maps.cpp ../libnativeloader/src/native_source_map_binding.hpp ../libnativeloader/src/native_loader_manifest.hpp
	install -d build
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 -fsanitize=address,undefined $< -o $@

build/source-value.bpf.o: test_source_value.bpf.c
	install -d build
	clang -O2 -g -target bpf -I../../vendor/libbpf/include/uapi \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		-I/usr/include/x86_64-linux-gnu -c $< -o $@

build/source-value-wrong-site.bpf.o: test_source_value.bpf.c
	install -d build
	clang -O2 -g -target bpf -DTV_SOURCE_SITE='"1"' -I../../vendor/libbpf/include/uapi \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		-I/usr/include/x86_64-linux-gnu -c $< -o $@

build/bcc-map-probe/manifest.json: ../results/kprog_tv_20261106/source-map-bcc-probe-inputs.tar.gz
	install -d build/bcc-map-probe
	tar -xzf $< -C build/bcc-map-probe
	touch $@

.PHONY: simple-arm64-guard-check
simple-arm64-guard-check: native-path-check
	python3 extract_simple_arm64.py
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64 lake env lean -R ../tv/build/simple-arm64 \
		-o ../tv/build/simple-arm64/SimpleCompiled.olean ../tv/build/simple-arm64/SimpleCompiled.lean
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64 lake env lean -R ../tv ../tv/SimpleGuardCertificate.lean

.PHONY: simple-context-kernel-check guest-simple-context-kernel-check
simple-context-kernel-check: build/capture-context
	test -s build/simple-arm64/simple.bpf.o
	taskset -c 8-23 vng --run $(CURDIR)/build-kernel-x86/arch/x86/boot/bzImage \
		--cwd $(abspath ../..) --rwdir $(abspath ../..) --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/tv guest-simple-context-kernel-check'

guest-simple-context-kernel-check:
	install -d build/simple-context
	./build/capture-context build/simple-arm64/simple.bpf.o build/simple-context

.PHONY: simple-platform-check
simple-platform-check: native-path-check
	python3 extract_simple_arm64.py
	python3 extract_simple_context.py
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64 lake env lean -R ../tv/build/simple-arm64 \
		-o ../tv/build/simple-arm64/SimpleCompiled.olean ../tv/build/simple-arm64/SimpleCompiled.lean
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64 lake env lean -R ../tv/build/simple-arm64 \
		-o ../tv/build/simple-arm64/SimplePlatform.olean ../tv/build/simple-arm64/SimplePlatform.lean
