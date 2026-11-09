ifneq ($(KERNELRELEASE),)
obj-m += native_load_fault_module.o
else
ROOT := $(abspath ../../..)
OUT ?= $(ROOT)/kprog/test/native_load_fault/build
KDIR ?= $(ROOT)/kprog/tv/build-kernel-x86
.PHONY: all
all:
	install -d $(OUT)
	$(MAKE) -C $(KDIR) M=$(ROOT)/kprog/test/native_load_fault MO=$(OUT)/module ARCH=x86 modules
	$(ROOT)/vendor/build/x86/bpftool/bin/bpftool btf dump file $(KDIR)/vmlinux format c > $(OUT)/vmlinux.h
	clang-18 -O3 -g -fPIC -c -march=native -mgeneral-regs-only -mno-red-zone -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables -fno-jump-tables -fno-optimize-sibling-calls -I$(OUT) native.c -o $(OUT)/native.o
	$(CXX) -std=c++20 -O2 -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include probe.cpp $(ROOT)/kprog/libnativeloader/build/libnative_loader.a $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -pthread -o $(OUT)/probe
endif
