ROOT := $(abspath ../../../../..)
SOURCE := $(ROOT)/kprog/fidelity/build-lea-final-published/source
BUILD := $(ROOT)/kprog/fidelity/build-lea-published-validation
OUT := $(CURDIR)/published
.PHONY: build run negative-guest positive-build positive-kvm positive-guest micro-build probe-build
build:
	install -d $(OUT)
	python3 $(SOURCE)/kprog/fidelity/negative.py build --arch x86 --build $(BUILD)/negative
run:
	vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --disable-monitor --cpus 2 --mem 2G --rwdir $(ROOT) --overlay-rwdir /tmp --exec 'cd $(ROOT)/kprog/fidelity && make -C $(CURDIR) -f published.mk negative-guest'
negative-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko
	python3 $(SOURCE)/kprog/fidelity/negative.py bound --arch x86 --build $(BUILD)/negative --out $(OUT) --probe $(ROOT)/kprog/fidelity/build-lea-private-probe/bound-probe --companion $(ROOT)/kprog/fidelity/build-x86/negative-companion.bpf.o
positive-build:
	python3 positive.py build $(BUILD)/positive
positive-kvm:
	vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --disable-monitor --cpus 2 --mem 2G --rwdir $(ROOT) --overlay-rwdir /tmp --exec 'cd $(ROOT)/kprog/fidelity && make -C $(CURDIR) -f published.mk positive-guest'
positive-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko
	python3 positive.py check $(BUILD)/positive $(OUT)/positive
micro-build:
	python3 $(CURDIR)/micro.py $(BUILD)/micro $(OUT)

probe-build:
	install -d $(ROOT)/kprog/fidelity/build-lea-private-probe
	g++ -std=c++20 -Wall -Wextra -Werror -O2 -D__EXPORTED_HEADERS__ -DNATIVE_LINK_PATH='"$(ROOT)/kprog/fidelity/build-lea-private-link-target/release/native-link"' -I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include $(ROOT)/kprog/fidelity/bound_probe.cpp $(ROOT)/kprog/libnativeloader/build-fidelity/libnative_loader.a $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o $(ROOT)/kprog/fidelity/build-lea-private-probe/bound-probe

.PHONY: link-build link-test
LINK_SOURCE := $(ROOT)/kprog/fidelity/build-lea-native-link/source
LINK_TARGET := $(ROOT)/kprog/fidelity/build-lea-private-link-target
link-build:
	install -d $(LINK_SOURCE)
	tar -xzf $(CURDIR)/../../differential/x86-lea-addressing-fixed/native-link-source.tar.gz -C $(LINK_SOURCE)
	CARGO_TARGET_DIR=$(LINK_TARGET) cargo build --locked --release --manifest-path $(LINK_SOURCE)/kprog/x86/native_lab/native_link/Cargo.toml
link-test:
	CARGO_TARGET_DIR=$(LINK_TARGET) cargo test --locked --release --manifest-path $(LINK_SOURCE)/kprog/x86/native_lab/native_link/Cargo.toml

.PHONY: abi-build abi-kvm abi-guest
abi-build:
	python3 -c 'import sys;sys.path.insert(0,"$(SOURCE)/kprog/fidelity");import negative;from pathlib import Path;negative.FIXTURES["x86"]={"callee_saved_clobber":"mov rbx,0x123456789abcdef0; mov eax,2; ret"};negative.build("x86",Path("$(BUILD)/abi-observation"))'
	$(LINK_TARGET)/release/native-link --input $(BUILD)/abi-observation/callee_saved_clobber.native.o --symbol entry --mode proof --preserve-entry-abi --output $(BUILD)/abi-observation/callee_saved_clobber.proof.o
	$(LINK_TARGET)/release/native-link --input $(BUILD)/abi-observation/callee_saved_clobber.proof.o --symbol entry --mode kernel --output $(BUILD)/abi-observation/linked.bin --output-abi $(BUILD)/abi-observation/linked.abi
abi-kvm:
	vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --disable-monitor --cpus 2 --mem 2G --rwdir $(ROOT) --overlay-rwdir /tmp --exec 'cd $(ROOT)/kprog/fidelity && make -C $(CURDIR) -f published.mk abi-guest'
abi-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko
	python3 $(SOURCE)/kprog/fidelity/negative.py bound --arch x86 --build $(BUILD)/abi-observation --out $(OUT)/abi-observation --probe $(ROOT)/kprog/fidelity/build-lea-private-probe/bound-probe --companion $(ROOT)/kprog/fidelity/build-x86/negative-companion.bpf.o
