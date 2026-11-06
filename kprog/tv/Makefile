ARCH ?= x86
KDIR ?= $(abspath ../../vendor/build/$(ARCH)/linux)
CROSS_arm64 := aarch64-linux-gnu-

.PHONY: check binding-check module-check kernel-check guest-kernel-check kernel-check-arm64

check: binding-check
	cd ../formal && lake env lean ../tv/Composition.lean

binding-check: build/test-binding
	./build/test-binding

build/test-binding: test_binding.c ../../kinsn/module/include/native_lab_binding.h
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

build/test-binding-kernel: test_binding_kernel.c ../../kinsn/module/include/native_lab_binding.h
	install -d build
	$(CC) -Wall -Wextra -Werror -O2 -g -D__EXPORTED_HEADERS__ \
		-I../../vendor/linux-framework/include/uapi -I../../runner/build-llvmbpf/vendor/libbpf/prefix/include \
		$< ../../runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o $@

kernel-check: module-check build/test-binding-kernel
	test "$(ARCH)" = x86
	taskset -c 8-23 vng --run ../../vendor/build/x86/linux/arch/x86/boot/bzImage \
		--cwd $(abspath ../..) --rwdir $(abspath ../..) --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/tv guest-kernel-check'

guest-kernel-check:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod build-x86/bpf_x86_native_lab.ko
	./build/test-binding-kernel

build-arm64/test-binding-kernel: test_binding_kernel.c ../../kinsn/module/include/native_lab_binding.h
	install -d build-arm64
	aarch64-linux-gnu-gcc -Wall -Wextra -Werror -O2 -g -static -D__EXPORTED_HEADERS__ \
		-I../../vendor/linux-framework/include/uapi -I../../runner/build-arm64-llvmbpf/vendor/libbpf/prefix/include \
		$< ../../runner/build-arm64-llvmbpf/vendor/libbpf/pic-obj/libbpf.a \
		-lelf -lz -lzstd -o $@

kernel-check-arm64: build-arm64/test-binding-kernel
	$(MAKE) module-check ARCH=arm64
	install -d build-arm64/initramfs/sys build-arm64/initramfs/proc build-arm64/initramfs/dev
	cp build-arm64/test-binding-kernel build-arm64/initramfs/init
	cp build-arm64/bpf_arm64_native_lab.ko build-arm64/initramfs/module.ko
	cd build-arm64/initramfs && find . -print0 | cpio --null -o --format=newc > ../initramfs.cpio
	timeout 180 taskset -c 8-23 qemu-system-aarch64 -M virt -cpu cortex-a72 \
		-accel tcg,thread=multi -smp 2 -m 2048 -nographic -no-reboot \
		-kernel ../../vendor/build/arm64/linux/arch/arm64/boot/Image \
		-initrd build-arm64/initramfs.cpio -append 'console=ttyAMA0 rdinit=/init panic=1' \
		> build-arm64/kernel.log 2>&1
	cat build-arm64/kernel.log
	rg -q '^kernel binding regression: PASS' build-arm64/kernel.log
