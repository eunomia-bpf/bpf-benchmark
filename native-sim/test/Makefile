# Stage 2 build: maps + helpers test programs. Each .bpf.c is compiled twice:
#   - .bpf.o : -target bpf, what kernel JIT consumes via libbpf
#   - .native.o : userspace x86-64 .o with `.rela.text` against extern
#                 helper / map symbols, what native-link consumes
#   - .native.so: userspace-native runner artifact. Helper calls remain
#                 undefined and bind to micro_exec's exported shim symbols.
#
# Driven by runner/mk/build.mk's host-stage2-programs-* targets. Docker copies
# the resulting component-local build directory directly into the runtime image.
DEB_HOST_MULTIARCH := $(shell gcc -print-multiarch 2>/dev/null || dpkg-architecture -qDEB_HOST_MULTIARCH 2>/dev/null)
SYS_INCLUDE_FLAGS ?= $(if $(DEB_HOST_MULTIARCH),-I/usr/include/$(DEB_HOST_MULTIARCH))
REPO_ROOT := $(abspath $(CURDIR)/../..)
OUTPUT_DIR ?= $(CURDIR)/build
CC ?= cc
CLANG ?= clang
NATIVE_TARGET ?=
NATIVE_ARCH ?= $(shell uname -m)

BPF_CFLAGS := -Wall -Wextra -O2 -g -target bpf $(SYS_INCLUDE_FLAGS) -MMD -MP

# Native-lab build: clang -target x86_64 (host arch) from the SAME source.
# We stop at .o (`-c`) on purpose: a fully linked .so would resolve every
# external symbol through the userspace dynamic linker, baking in PLT
# addresses that have no meaning in the kernel. An object file's
# .rela.text keeps the unresolved relocations referencing the original
# helper / map symbol names; native-link rewrites them to kernel addresses.
#
# -fno-plt makes clang emit `call *[rip+disp32]` (6 bytes, GOTPCREL) for
# external function calls instead of `call rel32` (5 bytes, PLT32).
# native-link patches the disp32 to point at a literal-pool entry holding
# the helper's kernel address; no trampoline needed.
NATIVE_TARGET_FLAGS := $(if $(NATIVE_TARGET),--target=$(NATIVE_TARGET))
NATIVE_ARCH_CFLAGS := $(if $(filter x86_64 amd64,$(NATIVE_ARCH)),-march=native -mno-red-zone -mgeneral-regs-only) \
    $(if $(filter arm64 aarch64,$(NATIVE_ARCH)),-mtune=neoverse-n1 -mgeneral-regs-only)
NATIVE_COMMON_CFLAGS := $(NATIVE_TARGET_FLAGS) -Wall -Wextra -O3 -g -fPIC -fno-plt -DMICRO_NATIVE \
    -fomit-frame-pointer $(NATIVE_ARCH_CFLAGS) -fno-stack-protector \
    -fno-asynchronous-unwind-tables -fno-unwind-tables -fno-jump-tables \
    -mllvm -switch-to-lookup=false \
    $(SYS_INCLUDE_FLAGS)
NATIVE_CFLAGS := $(NATIVE_COMMON_CFLAGS) -c -MMD -MP
NATIVE_SO_CFLAGS := $(NATIVE_COMMON_CFLAGS) -DMICRO_NATIVE_USERSPACE -shared -MMD -MP

# Reuse the kernel_offsets.h that micro/programs generates from BTF, so the
# context-struct offsets in common.h's MICRO_NATIVE branch match the host
# kernel layout. Not all Stage 2 programs reference SKB/XDP context offsets
# directly, but common.h includes the header unconditionally.
KERNEL_OFFSETS_DIR ?= $(REPO_ROOT)/micro/programs/build-x86
KERNEL_OFFSETS := $(KERNEL_OFFSETS_DIR)/kernel_offsets.h
KERNEL_OFFSETS_INCLUDE := $(dir $(abspath $(KERNEL_OFFSETS)))
MICRO_PROGRAMS_DIR := $(REPO_ROOT)/micro/programs
RUNNER_LIBBPF_DIR := $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj
RUNNER_LIBBPF_HDR := $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include
ifeq ($(wildcard $(RUNNER_LIBBPF_DIR)/libbpf.a),)
LIBBPF_CFLAGS :=
LIBBPF_LDFLAGS := -lbpf -lelf -lz
else
LIBBPF_CFLAGS := -I$(RUNNER_LIBBPF_HDR)
LIBBPF_LDFLAGS := $(RUNNER_LIBBPF_DIR)/libbpf.a -lelf -lz
endif
SHIM_SO ?= $(REPO_ROOT)/bpfopt/shim/libbpfrejit_shim.so

BPF_SRCS := $(wildcard *.bpf.c)
BPF_OBJS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.bpf.o,$(BPF_SRCS))
NATIVE_OBJS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.native.o,$(BPF_SRCS))
NATIVE_SOS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.native.so,$(BPF_SRCS))
NATIVE_SO_DEPS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.native-so.d,$(BPF_SRCS))
DEPS := $(BPF_OBJS:.o=.d) $(NATIVE_OBJS:.o=.d) $(NATIVE_SO_DEPS)
MULTI_PROG_TOOL := $(OUTPUT_DIR)/multi_prog_tool

.PHONY: all clean multi-prog-tool shim-multi-prog-smoke
all: $(BPF_OBJS) $(NATIVE_OBJS) $(NATIVE_SOS)

$(OUTPUT_DIR):
	install -d "$@"

$(KERNEL_OFFSETS):
	$(MAKE) -C $(MICRO_PROGRAMS_DIR) OUTPUT_DIR="$(KERNEL_OFFSETS_DIR)" "$@"

$(OUTPUT_DIR)/%.bpf.o: %.bpf.c | $(OUTPUT_DIR)
	$(CLANG) $(BPF_CFLAGS) -MF "$(OUTPUT_DIR)/$*.bpf.d" -MT "$@" -c -o "$@" "$<"

$(OUTPUT_DIR)/%.native.o: %.bpf.c $(KERNEL_OFFSETS) Makefile | $(OUTPUT_DIR)
	$(CLANG) $(NATIVE_CFLAGS) -I"$(MICRO_PROGRAMS_DIR)" -I"$(KERNEL_OFFSETS_INCLUDE)" \
	    -MF "$(OUTPUT_DIR)/$*.native.d" -MT "$@" -o "$@" "$<"

$(OUTPUT_DIR)/%.native.so: %.bpf.c $(KERNEL_OFFSETS) Makefile | $(OUTPUT_DIR)
	$(CLANG) $(NATIVE_SO_CFLAGS) -I"$(MICRO_PROGRAMS_DIR)" -I"$(KERNEL_OFFSETS_INCLUDE)" \
	    -MF "$(OUTPUT_DIR)/$*.native-so.d" -MT "$@" -o "$@" "$<"

$(MULTI_PROG_TOOL): multi_prog_tool.c | $(OUTPUT_DIR)
	$(CC) -O2 -g -Wall -Wextra $(LIBBPF_CFLAGS) -o "$@" "$<" $(LIBBPF_LDFLAGS)

multi-prog-tool: $(OUTPUT_DIR)/multi_prog_smoke.bpf.o $(OUTPUT_DIR)/multi_prog_smoke.native.o $(MULTI_PROG_TOOL)

shim-multi-prog-smoke: multi-prog-tool
	$(MAKE) -C "$(REPO_ROOT)/bpfopt/shim" SHIM_SO="$(SHIM_SO)" "$(SHIM_SO)"
	rm -rf /tmp/native_loader_multi_prog_shim
	install -d /tmp/native_loader_multi_prog_shim
	sudo -n env \
		BPFREJIT_SHIM_DIR=/tmp/native_loader_multi_prog_shim \
		BPFREJIT_SHIM_LOG=/tmp/native_loader_multi_prog_shim/shim.log \
		LD_PRELOAD="$(SHIM_SO)" \
		"$(MULTI_PROG_TOOL)" "$(OUTPUT_DIR)/multi_prog_smoke.bpf.o"
	grep -q "BPF_PROG_LOAD" /tmp/native_loader_multi_prog_shim/shim.log

clean:
	rm -rf $(OUTPUT_DIR)

-include $(DEPS)
