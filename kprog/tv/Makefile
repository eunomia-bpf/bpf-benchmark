ARCH ?= x86
KDIR ?= $(abspath ../../vendor/build/$(ARCH)/linux)
CROSS_arm64 := aarch64-linux-gnu-

.PHONY: check module-check inventory

check: data-layout-check manifest-check
	python3 test_kernel_patch.py
	cd ../formal && lake build KProgFormal.Reference.Memory
	cd ../formal && lake env lean ../tv/Composition.lean
	$(MAKE) bpf-check

.PHONY: environment-check
environment-check: build/exclusive-input.bpf.o build/test-exclusive-host
	python3 test_exclusive_wire.py
	python3 test_kernel_patch.py

build/exclusive-input.bpf.o: exclusive_input.bpf.c ../../kinsn/module/include/native_lab_input.h
	install -d build
	clang -O2 -target bpf -c $< -o $@

build/test-exclusive-host: test_exclusive_host.c ../../kinsn/module/include/native_lab_input.h
	install -d build
	$(CC) -std=gnu11 -Wall -Wextra -Werror -O2 -fsanitize=address,undefined $< -o $@


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

.PHONY: data-layout-check
data-layout-check: build/test-data-layout
	./build/test-data-layout

build/test-data-layout: test_data_layout.cpp ../libnativeloader/src/native_data_layout.hpp
	install -d build
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 -fsanitize=address,undefined \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include $< \
		../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o $@

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

# Diagnose the shared build's stale-header BTF failure without replacing the
# immutable per-lane runtime pairs or adding a benchmark admission gate.
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

build/test-loader: test_loader.cpp build/context-helper-25.bpf.o build/context-helper-27.bpf.o build/context-helper-67.bpf.o build/bcc-map-probe/manifest.json build/source-value.bpf.o build/source-value-wrong-site.bpf.o build/native-entry.o build/simulator.bpf.o build/runtime-config/simulator.bpf.o build/wrong-capacity/simulator.bpf.o build/wrong-value-size/simulator.bpf.o build/wrong-layout/simulator.bpf.o build/wrong-readonly/simulator.bpf.o build/wrong-data-layout/simulator.bpf.o ../libnativeloader/src/native_loader.cpp \
		$(wildcard ../libnativeloader/src/*.hpp ../libnativeloader/include/*.hpp)
	$(MAKE) -C ../libnativeloader BUILD_DIR=build
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 \
		-DTV_NATIVE_LINK_PATH='"$(TV_NATIVE_LINK)"' \
		-I../../vendor/libbpf/include/uapi \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		$< ../libnativeloader/build/libnative_loader.a \
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

TV_ARM64_KERNEL_PREREQUISITE ?= kernel-build-arm64
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

build/test-manifest: test_manifest.cpp ../libnativeloader/src/native_loader_manifest.hpp
	install -d build
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 -fsanitize=address,undefined $< -o $@

build-arm64/bound-probe: ../fidelity/bound_probe.cpp ../libnativeloader/include/native_loader.hpp ../libnativeloader/build-arm64/libnative_loader.a
	install -d build-arm64
	aarch64-linux-gnu-g++ -std=c++20 -Wall -Wextra -Werror -O2 -static \
		-D__EXPORTED_HEADERS__ -DNATIVE_LINK_PATH='"/native-link"' \
		-I../../vendor/linux-framework/include/uapi -I../../runner/build-arm64-llvmbpf/vendor/libbpf/prefix/include \
		$< ../libnativeloader/build-arm64/libnative_loader.a \
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


build/context-helper-%.bpf.o: test_contextual_helpers.bpf.c
	install -d build
	clang -O2 -g -target bpf -DTV_CONTEXT_HELPER=$* -I../../vendor/libbpf/include/uapi \
		-I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		-I/usr/include/x86_64-linux-gnu -c $< -o $@

build-arm64/capture-context: capture_context_init.cpp capture_context.cpp
	install -d build-arm64
	aarch64-linux-gnu-g++ -std=c++20 -Wall -Wextra -Werror -O2 -static -D__EXPORTED_HEADERS__ \
		-I../../vendor/linux-framework/include/uapi -I../../runner/build-arm64-llvmbpf/vendor/libbpf/prefix/include \
		$< ../../runner/build-arm64-llvmbpf/vendor/libbpf/pic-obj/libbpf.a \
		-L../../.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu -lelf -lz -lzstd -o $@

.PHONY: simple-context-kernel-check-arm64
simple-context-kernel-check-arm64: build-arm64/capture-context
	test -s build/simple-arm64/simple.bpf.o
	install -d build-arm64/context-initramfs/capture
	cp build-arm64/capture-context build-arm64/context-initramfs/init
	cp build/simple-arm64/simple.bpf.o build-arm64/context-initramfs/simple.bpf.o
	cd build-arm64/context-initramfs && find . -print0 | cpio --null -o --format=newc > ../context-initramfs.cpio
	timeout 180 taskset -c 8-11 qemu-system-aarch64 -M virt -cpu cortex-a72 \
		-accel tcg,thread=multi -smp 2 -m 2048 -nographic -no-reboot \
		-kernel build-kernel-arm64/arch/arm64/boot/Image \
		-initrd build-arm64/context-initramfs.cpio -append 'console=ttyAMA0 rdinit=/init panic=1' \
		> build-arm64/context-kernel.log 2>&1
	cat build-arm64/context-kernel.log
	rg -q '^actual ARM kernel context capture: PASS' build-arm64/context-kernel.log
	python3 extract_arm64_context.py

.PHONY: exclusive-runtime-arm64
exclusive-runtime-arm64:
	$(MAKE) -C ../../vendor/linux-framework O=$(CURDIR)/build-kernel-arm64 \
		ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- -j8 vmlinuz.efi modules
	cp build-kernel-arm64/vmlinux.symvers build-kernel-arm64/Module.symvers
	$(MAKE) -C build-kernel-arm64 ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- \
		M=$(abspath ../../kinsn/module/arm64) MO=$(CURDIR)/build-arm64/all-exclusive modules
	$(MAKE) -C build-kernel-arm64 ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- \
		INSTALL_MOD_PATH=$(CURDIR)/build-arm64/exclusive-stock modules_install

build-arm64/all-modules-init: arm64_all_modules_init.c
	install -d build-arm64
	aarch64-linux-gnu-gcc -Wall -Wextra -Werror -O2 -static $< -o $@

.PHONY: simple-entry-check simple-entry-certificate
simple-entry-check: simple-platform-check simple-kernel-artifact-check
	$(MAKE) simple-entry-certificate

SIMPLE_ENTRY_DIR ?= build/simple-arm64
simple-entry-certificate: private-spills-check
	cd ../formal && LEAN_PATH=../tv/build:../tv/$(SIMPLE_ENTRY_DIR) lake env lean -R ../tv/$(SIMPLE_ENTRY_DIR) \
		-o ../tv/$(SIMPLE_ENTRY_DIR)/SimpleCompiled.olean ../tv/$(SIMPLE_ENTRY_DIR)/SimpleCompiled.lean
	cd ../formal && LEAN_PATH=../tv/build:../tv/$(SIMPLE_ENTRY_DIR) lake env lean -R ../tv/$(SIMPLE_ENTRY_DIR) \
		-o ../tv/$(SIMPLE_ENTRY_DIR)/SimplePlatform.olean ../tv/$(SIMPLE_ENTRY_DIR)/SimplePlatform.lean
	cd ../formal && LEAN_PATH=../tv/build:../tv/$(SIMPLE_ENTRY_DIR) lake env lean -R ../tv ../tv/SimpleEntryCertificate.lean

.PHONY: simple-entry-negative-check
simple-entry-negative-check: simple-entry-check
	python3 test_entry_artifacts.py

.PHONY: private-spills-check
private-spills-check:
	cd ../formal && lake env lean -R ../tv -o ../tv/build/PrivateSpills.olean ../tv/PrivateSpills.lean


.PHONY: simple-kernel-artifact-check
simple-kernel-artifact-check:
	../arm64/build/app-native-link/release/native-link --input build/simple-arm64/native-link/simple.proof.o \
		--symbol simple_xdp --mode kernel --output build/simple-arm64/simple.kernel.bin \
		--output-relocs build/simple-arm64/simple.kernel.relocs \
		--output-abi build/simple-arm64/simple.kernel.abi \
		--output-environment-layout build/simple-arm64/simple.kernel.environment.json
	test ! -s build/simple-arm64/simple.kernel.relocs
	python3 extract_simple_arm64.py --native-blob build/simple-arm64/simple.kernel.bin

.PHONY: simple-blocks-check
simple-blocks-check: simple-entry-check
	$(MAKE) simple-blocks-certificate

.PHONY: simple-blocks-certificate
simple-blocks-certificate:
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64 lake env lean -R ../tv \
		-o ../tv/build/SimpleEntryCertificate.olean ../tv/SimpleEntryCertificate.lean
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64 lake env lean -R ../tv \
		-o ../tv/build/SimpleGuardCertificate.olean ../tv/SimpleGuardCertificate.lean
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64 lake env lean -R ../tv -o ../tv/build/SimpleBlocks.olean ../tv/SimpleBlocks.lean

CAPTURE_ARM64_PROGRAM ?= simple
CAPTURE_ARM64_ARTIFACTS ?= build/simple-arm64
CAPTURE_ARM64_OUTPUT ?= build-arm64
.PHONY: simple-checked-artifact-check
simple-checked-artifact-check:
	python3 extract_checked.py build-arm64/checked-kernel.log build/simple-checked
	$(MAKE) checked-certificate

SIMPLE_CHECKED_DIR ?= build/simple-checked
.PHONY: checked-certificate
checked-certificate:
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64 lake env lean -R ../tv/$(SIMPLE_CHECKED_DIR) \
		-o ../tv/$(SIMPLE_CHECKED_DIR)/SimpleChecked.olean ../tv/$(SIMPLE_CHECKED_DIR)/SimpleChecked.lean

.PHONY: checked-platform-check
checked-platform-check: bpf-check simple-checked-artifact-check
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64:../tv/build/simple-checked lake env lean -R ../tv -o ../tv/build/SimpleCheckedPlatform.olean ../tv/SimpleCheckedPlatform.lean

.PHONY: capture-loader-build
capture-loader-build:
	$(MAKE) -C ../libnativeloader BUILD_DIR=build
	$(MAKE) -C ../libnativeloader BUILD_DIR=build-arm64 \
		LIBBPF_PREFIX=$(abspath ../../runner/build-arm64-llvmbpf/vendor/libbpf/prefix) \
		LIBBPF_LIBRARY=$(abspath ../../runner/build-arm64-llvmbpf/vendor/libbpf/pic-obj/libbpf.a) \
		KERNEL_OFFSETS_INCLUDE=$(abspath ../../micro/programs/build-arm64)

.PHONY: checked-first-block-check
checked-first-block-check: checked-platform-check simple-blocks-check
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64 lake env lean -R ../tv -o ../tv/build/SimpleStoreCertificate.olean ../tv/SimpleStoreCertificate.lean
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64:../tv/build/simple-checked lake env lean -R ../tv -o ../tv/build/SimpleCheckedBlocks.olean ../tv/SimpleCheckedBlocks.lean

.PHONY: simple-emitted-check simple-emitted-certificate
simple-emitted-check: simple-invocation-abi-check
	python3 extract_checked.py build-arm64/checked-kernel.log build/simple-checked --exports build/capture-loader-arm64-emitted
	python3 test_emitted_sites.py build/capture-loader-arm64-emitted
	python3 extract_simple_emitted.py build/capture-loader-arm64-emitted build/simple-emitted
	$(MAKE) simple-emitted-certificate

SIMPLE_EMITTED_DIR ?= build/simple-emitted
simple-emitted-certificate:
	@set -e; for source in $(SIMPLE_EMITTED_DIR)/SimpleEmitted_*.lean; do \
		cd $(CURDIR)/../formal; \
		LEAN_PATH=../tv/build:../tv/build/simple-arm64:../tv/build/simple-checked \
		lake env lean -R ../tv/$(SIMPLE_EMITTED_DIR) ../tv/$$source; done

.PHONY: simple-emitted-negative-check
simple-emitted-negative-check:
	python3 test_simple_emitted.py build/capture-loader-arm64-emitted

.PHONY: simple-pc-relocation-check
simple-pc-relocation-check: checked-first-block-check
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64:../tv/build/simple-checked lake env lean -R ../tv -o ../tv/build/SimplePCRelocation.olean ../tv/SimplePCRelocation.lean

X86_ABI_NATIVE_LINK ?= ../x86/native_lab/native_link/target/release/native-link
.PHONY: x86-native-abi-check
x86-native-abi-check:
	python3 test_x86_native_abi.py $(X86_ABI_NATIVE_LINK) build/x86-native-abi

.PHONY: x86-native-abi-kernel-check
build/x86-abi-bound-probe: ../fidelity/bound_probe.cpp ../libnativeloader/build/libnative_loader.a
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 -D__EXPORTED_HEADERS__ \
		-DNATIVE_LINK_PATH='"$(abspath build/native-link-abi)"' \
		-I../../vendor/linux-framework/include/uapi -I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		$< ../libnativeloader/build/libnative_loader.a \
		../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o $@

x86-native-abi-kernel-check: build/x86-abi-bound-probe
	$(MAKE) module-check ARCH=x86 KDIR=$(CURDIR)/build-kernel-x86
	taskset -c 16-19 vng --run $(CURDIR)/build-kernel-x86/arch/x86/boot/bzImage \
		--cwd $(abspath ../..) --rwdir $(abspath ../..) --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/tv guest-x86-native-abi-check'

.PHONY: simple-execution-relocation-check
simple-execution-relocation-check: simple-pc-relocation-check
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64:../tv/build/simple-checked lake env lean -R ../tv -o ../tv/build/SimpleExecutionRelocation.olean ../tv/SimpleExecutionRelocation.lean

.PHONY: simple-invocation-abi-check
simple-invocation-abi-check: simple-execution-relocation-check
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64:../tv/build/simple-checked lake env lean -R ../tv -o ../tv/build/SimpleInvocationABI.olean ../tv/SimpleInvocationABI.lean

.PHONY: simple-packet-guard-check
simple-packet-guard-check: simple-blocks-check
	python3 extract_simple_packet.py build-arm64/simple-packet/checked-kernel.log build/simple-packet-arm64 build/capture-loader-arm64-simple-packet
	python3 test_emitted_sites.py build/capture-loader-arm64-simple-packet --native-bytes 68 --store-offset 40
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64 lake env lean -R ../tv/build/simple-packet-arm64 -o ../tv/build/simple-packet-arm64/PacketCompiled.olean ../tv/build/simple-packet-arm64/PacketCompiled.lean
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64:../tv/build/simple-packet-arm64 lake env lean -R ../tv -o ../tv/build/PacketGuardCertificate.olean ../tv/PacketGuardCertificate.lean

.PHONY: simple-packet-entry-check simple-packet-entry-negative-check
simple-packet-entry-check: checked-platform-check simple-packet-guard-check
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-arm64:../tv/build/simple-packet-arm64 lake env lean -R ../tv -o ../tv/build/PacketEntryCertificate.olean ../tv/PacketEntryCertificate.lean
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-checked:../tv/build/simple-arm64:../tv/build/simple-packet-arm64 lake env lean -R ../tv -o ../tv/build/PacketCheckedPlatform.olean ../tv/PacketCheckedPlatform.lean
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-checked:../tv/build/simple-arm64:../tv/build/simple-packet-arm64 lake env lean -R ../tv -o ../tv/build/PacketCheckedBlocks.olean ../tv/PacketCheckedBlocks.lean

simple-packet-entry-negative-check:
	python3 test_packet_entry.py

.PHONY: simple-packet-store-check
simple-packet-store-check: checked-first-block-check simple-packet-entry-check
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-checked:../tv/build/simple-arm64:../tv/build/simple-packet-arm64 lake env lean -R ../tv -o ../tv/build/PacketStoreTransport.olean ../tv/PacketStoreTransport.lean

.PHONY: simple-packet-invocation-check
simple-packet-invocation-check: simple-packet-store-check
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-checked:../tv/build/simple-arm64:../tv/build/simple-packet-arm64 lake env lean -R ../tv -o ../tv/build/PacketInvocation.olean ../tv/PacketInvocation.lean

.PHONY: simple-packet-pc-relocation-check simple-packet-execution-relocation-check simple-packet-invocation-abi-check
simple-packet-pc-relocation-check: simple-packet-invocation-check
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-checked:../tv/build/simple-arm64:../tv/build/simple-packet-arm64 lake env lean -R ../tv -o ../tv/build/PacketPCRelocation.olean ../tv/PacketPCRelocation.lean

simple-packet-execution-relocation-check: simple-packet-pc-relocation-check
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-checked:../tv/build/simple-arm64:../tv/build/simple-packet-arm64 lake env lean -R ../tv -o ../tv/build/PacketExecutionRelocation.olean ../tv/PacketExecutionRelocation.lean

simple-packet-invocation-abi-check: simple-packet-execution-relocation-check simple-invocation-abi-check
	cd ../formal && LEAN_PATH=../tv/build:../tv/build/simple-checked:../tv/build/simple-arm64:../tv/build/simple-packet-arm64 lake env lean -R ../tv -o ../tv/build/PacketInvocationABI.olean ../tv/PacketInvocationABI.lean

.PHONY: simple-packet-emitted-check simple-packet-emitted-certificate simple-packet-emitted-negative-check
simple-packet-emitted-check: simple-packet-invocation-abi-check
	python3 extract_simple_emitted.py build/capture-loader-arm64-simple-packet build/simple-packet-emitted --program simple_packet
	$(MAKE) simple-packet-emitted-certificate

PACKET_EMITTED_DIR ?= build/simple-packet-emitted
simple-packet-emitted-certificate:
	@set -e; for source in $(PACKET_EMITTED_DIR)/PacketEmitted_*.lean; do \
		cd $(CURDIR)/../formal; \
		LEAN_PATH=../tv/build:../tv/build/simple-arm64:../tv/build/simple-checked:../tv/build/simple-packet-arm64 \
		lake env lean -R ../tv/$(PACKET_EMITTED_DIR) ../tv/$$source; done

simple-packet-emitted-negative-check:
	python3 test_simple_emitted.py build/capture-loader-arm64-simple-packet --program simple_packet

.PHONY: trusted-kernel-check guest-trusted-kernel-check
build/test-trusted-transport: test_trusted_transport.c ../../kinsn/module/include/native_lab_trusted_wire.h
	install -d build
	$(CC) -Wall -Wextra -Werror -O2 -g -D__EXPORTED_HEADERS__ \
		-I../../vendor/linux-framework/include/uapi -I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		$< ../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o $@

trusted-kernel-check: kernel-build-x86 build/test-trusted-transport
	$(MAKE) module-check ARCH=x86 KDIR=$(CURDIR)/build-kernel-x86
	taskset -c 8-11 vng --run $(CURDIR)/build-kernel-x86/arch/x86/boot/bzImage \
		--cwd $(abspath ../..) --rwdir $(abspath ../..) --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/tv guest-trusted-kernel-check'

guest-trusted-kernel-check:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod build-x86/bpf_x86_native_lab.ko
	./build/test-trusted-transport /sys/kernel/debug/bpf_x86_native_lab

.PHONY: trusted-client-check guest-trusted-client-check
build/test-trusted-client: test_trusted_client.cpp ../libnativeloader/build/libnative_loader.a
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 -D__EXPORTED_HEADERS__ \
		-I../../vendor/linux-framework/include/uapi -I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		$< ../libnativeloader/build/libnative_loader.a \
		../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o $@

trusted-client-check:
	$(MAKE) -C ../libnativeloader BUILD_DIR=build
	$(MAKE) build/test-trusted-client
	$(MAKE) module-check ARCH=x86 KDIR=$(CURDIR)/build-kernel-x86
	taskset -c 8-11 vng --run $(CURDIR)/build-kernel-x86/arch/x86/boot/bzImage \
		--cwd $(abspath ../..) --rwdir $(abspath ../..) --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/tv guest-trusted-client-check'

guest-trusted-client-check:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod build-x86/bpf_x86_native_lab.ko
	./build/test-trusted-client ../../vendor/build/native-bpf/x86/stage/bcc/vfsstat.native.o kprobe_vfs_read

.PHONY: trusted-capture-check guest-trusted-capture-check
trusted-capture-check:
	$(MAKE) -C ../libnativeloader trusted-service-check
	cmake --build ../libnativeloader/build --target trusted-service-client
	clang -O2 -fno-asynchronous-unwind-tables -c ../test/trusted_native.c -o ../libnativeloader/build/trusted-native.o
	$(MAKE) module-check ARCH=x86 KDIR=$(CURDIR)/build-kernel-x86
	taskset -c 8-11 vng --run $(CURDIR)/build-kernel-x86/arch/x86/boot/bzImage \
		--cwd $(abspath ../..) --rwdir $(abspath ../..) --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/tv guest-trusted-capture-check'

guest-trusted-capture-check:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod build-x86/bpf_x86_native_lab.ko capture_checked=1
	PATH="/usr/lib/llvm-18/bin:$$PATH" PYTHONDONTWRITEBYTECODE=1 python3 capture_trusted_service.py

build/trusted-simple-client: trusted_simple_client.cpp ../libnativeloader/build/libnative_loader.a
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 -D__EXPORTED_HEADERS__ \
		-I../../vendor/linux-framework/include/uapi -I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		$< ../libnativeloader/build/libnative_loader.a \
		../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o $@

TRUSTED_SIMPLE_OUTPUT ?= $(abspath ../results/kprog_tv_20261107/trusted-simple)

.PHONY: trusted-simple-check guest-trusted-simple-check
trusted-simple-check: build/simple.native.o
	$(MAKE) -C ../libnativeloader trusted-service
	$(MAKE) build/trusted-simple-client
	taskset -c 8-11 vng --run $(CURDIR)/build-kernel-x86/arch/x86/boot/bzImage \
		--cwd $(abspath ../..) --rwdir $(abspath ../..) --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/tv guest-trusted-simple-check TRUSTED_SIMPLE_OUTPUT="$(TRUSTED_SIMPLE_OUTPUT)"'

guest-trusted-simple-check:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod build-x86/bpf_x86_native_lab.ko capture_checked=1
	PATH="/usr/lib/llvm-18/bin:$$PATH" PYTHONDONTWRITEBYTECODE=1 python3 capture_trusted_service.py simple --output-dir "$(TRUSTED_SIMPLE_OUTPUT)"


build/simple.native.o: ../../micro/programs/simple.bpf.c ../../micro/programs/common.h ../../micro/programs/build-host-docker-x86/kernel_offsets.h
	install -d build
	clang -O3 -g -fPIC -fno-plt -DMICRO_NATIVE -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only \
		-fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables -fno-jump-tables \
		-mllvm -switch-to-lookup=false -I../../micro/programs/build-host-docker-x86 -c $< -o $@

.PHONY: trusted-binding-check
trusted-binding-check:
	PYTHONDONTWRITEBYTECODE=1 python3 check_trusted_capture.py

.PHONY: trusted-simple-entry-certificate
trusted-simple-entry-certificate: trusted-binding-check bpf-check
	cd ../formal && lake build KProgFormal.Reference.X86Path
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/PrivateSpills.olean ../tv/PrivateSpills.lean
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/TrustedSimpleX86.olean ../tv/TrustedSimpleX86.lean

.PHONY: trusted-simple-safety-certificate
trusted-simple-safety-certificate: trusted-simple-cfg-certificate
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/TrustedSimpleSafety.olean ../tv/TrustedSimpleSafety.lean

.PHONY: trusted-simple-cfg-certificate
trusted-simple-cfg-certificate: trusted-simple-entry-certificate
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/TrustedSimpleCFG.olean ../tv/TrustedSimpleCFG.lean

# Regression for unbound ABI output markers reading an undefined entry r0.
# Actual Katran loads its own programs through the unchanged upstream server.
UNBOUND_KATRAN_INPUTS ?= $(CURDIR)/build/unbound-katran
.PHONY: unbound-katran-inputs unbound-katran-check guest-unbound-katran-check unbound-loader-regression
unbound-katran-inputs:
	python3 test_unbound_katran.py --prepare $(UNBOUND_KATRAN_INPUTS)

unbound-katran-check:
	$(MAKE) module-check KDIR=$(CURDIR)/build-kernel-x86
	taskset -c 8-11 vng --run $(CURDIR)/build-kernel-x86/arch/x86/boot/bzImage \
		--cwd $(abspath ../..) --rwdir $(abspath ../..) --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 4G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/tv guest-unbound-katran-check UNBOUND_KATRAN_INPUTS=$(UNBOUND_KATRAN_INPUTS)'

guest-unbound-katran-check:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod build-x86/bpf_x86_native_lab.ko
	python3 test_unbound_katran.py $(UNBOUND_KATRAN_INPUTS)

unbound-loader-regression: unbound-kernel-check unbound-katran-check

.PHONY: trusted-simple-platform-certificate
trusted-simple-platform-certificate: trusted-simple-safety-certificate
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/TrustedSimplePlatform.olean ../tv/TrustedSimplePlatform.lean

.PHONY: trusted-simple-current-audit
trusted-simple-current-audit: trusted-simple-entry-certificate
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/TrustedSimpleCurrent.olean ../tv/TrustedSimpleCurrent.lean

.PHONY: trusted-simple-jit-certificate
trusted-simple-jit-certificate: trusted-simple-safety-certificate
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/TrustedSimpleJIT.olean ../tv/TrustedSimpleJIT.lean

.PHONY: trusted-simple-b29-certificate
trusted-simple-b29-certificate: trusted-simple-safety-certificate
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/TrustedSimpleB29.olean ../tv/TrustedSimpleB29.lean

.PHONY: trusted-simple-b29-state-certificate
trusted-simple-b29-state-certificate: trusted-simple-b29-certificate
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/TrustedSimpleB29State.olean ../tv/TrustedSimpleB29State.lean

.PHONY: trusted-simple-b29-observer-certificate
trusted-simple-b29-observer-certificate: trusted-simple-b29-state-certificate
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/TrustedSimpleB29Observer.olean ../tv/TrustedSimpleB29Observer.lean

.PHONY: trusted-simple-b29-blocks-certificate
trusted-simple-b29-blocks-certificate: trusted-simple-b29-observer-certificate
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/TrustedSimpleB29Blocks.olean ../tv/TrustedSimpleB29Blocks.lean

.PHONY: trusted-simple-b29-embedding-certificate
trusted-simple-b29-embedding-certificate: trusted-simple-b29-blocks-certificate
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/TrustedSimpleB29Embedding.olean ../tv/TrustedSimpleB29Embedding.lean

.PHONY: trusted-simple-b29-wrapper-certificate
trusted-simple-b29-wrapper-certificate: trusted-simple-b29-embedding-certificate trusted-simple-jit-certificate
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/TrustedSimpleB29Wrapper.olean ../tv/TrustedSimpleB29Wrapper.lean

.PHONY: native-link-relocation-check
native-link-relocation-check: bpf-check
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkRelocation.olean ../tv/NativeLinkRelocation.lean

.PHONY: native-link-relocation-table-check
native-link-relocation-table-check: native-link-relocation-check
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkRelocationTable.olean ../tv/NativeLinkRelocationTable.lean

.PHONY: private-spill-projection-check
private-spill-projection-check: bpf-check
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/PrivateSpillProjection.olean ../tv/PrivateSpillProjection.lean

.PHONY: native-link-literal-check
native-link-literal-check: native-link-relocation-table-check
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkLiteral.olean ../tv/NativeLinkLiteral.lean

.PHONY: native-link-patch-table-check
native-link-patch-table-check: native-link-literal-check
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkPatchTable.olean ../tv/NativeLinkPatchTable.lean

.PHONY: native-link-movabs-check
native-link-movabs-check: native-link-patch-table-check
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkMovabs.olean ../tv/NativeLinkMovabs.lean

.PHONY: native-link-guarded-emission-check
native-link-guarded-emission-check: native-link-movabs-check
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkGuardedEmission.olean ../tv/NativeLinkGuardedEmission.lean

.PHONY: native-link-chunk-layout-check
native-link-chunk-layout-check: native-link-guarded-emission-check
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkChunkLayout.olean ../tv/NativeLinkChunkLayout.lean

.PHONY: native-link-byte-layout-check
native-link-byte-layout-check: native-link-chunk-layout-check
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkByteLayout.olean ../tv/NativeLinkByteLayout.lean

.PHONY: native-link-chunk-planner-check
native-link-chunk-planner-check: native-link-byte-layout-check
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkChunkPlanner.olean ../tv/NativeLinkChunkPlanner.lean

.PHONY: trusted-memory-check guest-trusted-memory-check
build/trusted-memory-%.o: trusted_memory.c
	install -d build
	clang -O2 -fno-builtin -fno-vectorize -fno-slp-vectorize -fno-asynchronous-unwind-tables -DCOPY_BYTES=$* -c $< -o $@

build/trusted-memory-unsafe.o: trusted_memory.c
	install -d build
	clang -O2 -fno-builtin -fno-vectorize -fno-slp-vectorize -fno-asynchronous-unwind-tables -DCOPY_BYTES=8 -DUNSAFE_DESTINATION -c $< -o $@

trusted-memory-check: build/trusted-memory-8.o build/trusted-memory-32.o build/trusted-memory-96.o build/trusted-memory-unsafe.o build/test-trusted-transport
	$(MAKE) -C ../libnativeloader trusted-service
	cmake --build ../libnativeloader/build --target trusted-service-client
	$(MAKE) module-check ARCH=x86 KDIR=$(CURDIR)/build-kernel-x86
	taskset -c 8-11 vng --run $(CURDIR)/build-kernel-x86/arch/x86/boot/bzImage \
		--cwd $(abspath ../..) --rwdir $(abspath ../..) --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/tv guest-trusted-memory-check'

guest-trusted-memory-check:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod build-x86/bpf_x86_native_lab.ko
	./build/test-trusted-transport /sys/kernel/debug/bpf_x86_native_lab
	rmmod bpf_x86_native_lab
	insmod build-x86/bpf_x86_native_lab.ko
	PATH="/usr/lib/llvm-18/bin:$$PATH" PYTHONDONTWRITEBYTECODE=1 python3 test_trusted_memory.py

.PHONY: simulator-composition-check
simulator-composition-check: bpf-check
	cd ../formal && lake build KProgFormal.Refinement.X86Dispatcher
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/SimulatorComposition.olean ../tv/SimulatorComposition.lean

.PHONY: native-link-final-image-check
native-link-final-image-check: native-link-byte-layout-check
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkFinalImage.olean ../tv/NativeLinkFinalImage.lean

.PHONY: native-link-arm-bl26-check
native-link-arm-bl26-check: native-link-relocation-table-check
	cd ../formal && lake build KProgFormal.Reference.AArch64
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkArmBL26.olean ../tv/NativeLinkArmBL26.lean

.PHONY: native-link-arm-helper-check
native-link-arm-helper-check: native-link-arm-bl26-check
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkArmHelper.olean ../tv/NativeLinkArmHelper.lean

.PHONY: native-link-arm-helper-guard-check arm-helper-emitter-check
arm-helper-emitter-check:
	python3 test_arm_helper_emitter.py

native-link-arm-helper-guard-check: native-link-arm-helper-check arm-helper-emitter-check
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkArmHelperGuard.olean ../tv/NativeLinkArmHelperGuard.lean

.PHONY: native-link-arm-placement-check
native-link-arm-placement-check: native-link-arm-helper-guard-check native-link-final-image-check
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkArmPlacement.olean ../tv/NativeLinkArmPlacement.lean

.PHONY: native-link-arm-exclusive-check
native-link-arm-exclusive-check: native-link-arm-helper-check bpf-check build/test-environment-binding
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkArmExclusive.olean ../tv/NativeLinkArmExclusive.lean

.PHONY: native-link-arm-percpu-check
native-link-arm-percpu-check: native-link-arm-helper-check native-link-final-image-check
	python3 test_arm_percpu_emitter.py
	cd ../formal && lake build KProgFormal.Refinement.Arm64Register
	cd ../formal && LEAN_PATH=../tv/build lake env lean -R ../tv \
		-o ../tv/build/NativeLinkArmPerCpu.olean ../tv/NativeLinkArmPerCpu.lean
