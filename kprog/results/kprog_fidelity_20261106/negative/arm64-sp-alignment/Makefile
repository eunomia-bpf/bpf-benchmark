ROOT := $(abspath ../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-arm64/sp-alignment-bound
.PHONY: build run
build:
	aarch64-linux-gnu-g++ -std=c++20 -Wall -Wextra -Werror -O2 -static -D__EXPORTED_HEADERS__ -DNATIVE_LINK_PATH='"/native-link"' -I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/prefix/include $(ROOT)/kprog/fidelity/bound_probe.cpp $(BUILD)/libnative_loader.a $(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -L$(ROOT)/.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu -lelf -lz -lzstd -ldl -pthread -o $(BUILD)/bound-probe
	aarch64-linux-gnu-gcc -Wall -Wextra -Werror -O2 -static -DBOUND_NEGATIVE $(ROOT)/kprog/fidelity/negative_init.c -o $(BUILD)/init
	python3 package.py $(BUILD)
run:
	timeout 240 qemu-system-aarch64 -M virt -cpu cortex-a57 -smp 2 -m 2048 -nographic -no-reboot -kernel $(BUILD)/Image -initrd $(BUILD)/init.cpio -append 'console=ttyAMA0 rdinit=/init panic=-1' > guest-console.log 2>&1
	python3 collect.py

check:
	python3 check_alignment.py $(BUILD)/regressions

full-build:
	$(MAKE) -C $(ROOT)/kprog/fidelity negative-build ARCH=arm64 NEGATIVE_BUILD=build-arm64/sp-alignment-bound/full-suite

full-package:
	python3 prepare_full.py $(BUILD)
	python3 package.py $(BUILD)/full-run
full-run:
	install -d full-after
	timeout 240 qemu-system-aarch64 -M virt -cpu cortex-a57 -smp 2 -m 2048 -nographic -no-reboot -kernel $(BUILD)/Image -initrd $(BUILD)/full-run/init.cpio -append 'console=ttyAMA0 rdinit=/init panic=-1' > full-after/guest-console.log 2>&1
	cd $(ROOT)/kprog/fidelity && python3 negative.py collect-bound --arch arm64 --build $(BUILD)/full-suite --out $(CURDIR)/full-after

positive-build:
	python3 prepare_positive.py $(BUILD)
	python3 package.py $(BUILD)/positive-run
positive-run:
	install -d positive-after
	timeout 240 qemu-system-aarch64 -M virt -cpu cortex-a57 -smp 2 -m 2048 -nographic -no-reboot -kernel $(BUILD)/Image -initrd $(BUILD)/positive-run/init.cpio -append 'console=ttyAMA0 rdinit=/init panic=-1' > positive-after/guest-console.log 2>&1
	python3 collect_positive.py
