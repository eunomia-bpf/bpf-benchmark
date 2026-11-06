ROOT := $(abspath ../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-x86/negative-matched-current
BUNDLE := /workspaces/.agent-state/kprog-lanes/T/shared-btf-fixed/x86
LINKER := $(BUILD)/native-link
.PHONY: build run guest
build:
	install -d $(BUILD)
	cp $(BUNDLE)/bzImage $(BUILD)/bzImage
	cp $(BUNDLE)/bpf_x86_native_lab.ko $(BUILD)/bpf_x86_native_lab.ko
	cp /workspaces/.agent-state/kprog-lanes/T/context-v2-map-value/x86/libnative_loader.a $(BUILD)/libnative_loader.a
	cp $(ROOT)/kprog/x86/native_lab/native_link/target-c-readonly/release/native-link $(LINKER)
	cp $(ROOT)/kprog/fidelity/build-x86/negative-companion.bpf.o $(BUILD)/companion.bpf.o
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 -D__EXPORTED_HEADERS__ -DNATIVE_LINK_PATH='"$(LINKER)"' -I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include $(ROOT)/kprog/fidelity/bound_probe.cpp $(BUILD)/libnative_loader.a $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o $(BUILD)/bound-probe
run:
	vng --run $(BUILD)/bzImage --cwd $(ROOT) --disable-monitor --cpus 2 --mem 2G --rwdir $(ROOT) --overlay-rwdir /tmp --exec 'make -C $(CURDIR) guest'
guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(BUILD)/bpf_x86_native_lab.ko
	cd $(ROOT)/kprog/fidelity && python3 negative.py bound --arch x86 --build build-x86/negative-post-ldp --out $(CURDIR) --probe $(BUILD)/bound-probe --companion $(BUILD)/companion.bpf.o
