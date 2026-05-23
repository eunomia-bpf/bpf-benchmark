# Stage 2 build: maps + helpers test programs. Each .bpf.c is compiled twice:
#   - .bpf.o : -target bpf, what kernel JIT consumes via libbpf
#   - .native.o : userspace x86-64 .o with `.rela.text` against extern
#                 helper / map symbols, what native-link consumes
#
# Driven by runner/mk/build.mk's host-stage2-programs-* targets. Docker copies
# the resulting component-local build directory directly into the runtime image.
DEB_HOST_MULTIARCH := $(shell gcc -print-multiarch 2>/dev/null || dpkg-architecture -qDEB_HOST_MULTIARCH 2>/dev/null)
SYS_INCLUDE_FLAGS ?= $(if $(DEB_HOST_MULTIARCH),-I/usr/include/$(DEB_HOST_MULTIARCH))
REPO_ROOT := $(abspath $(CURDIR)/../..)
OUTPUT_DIR ?= $(CURDIR)/build
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
NATIVE_ARCH_CFLAGS := $(if $(filter x86_64 amd64,$(NATIVE_ARCH)),-mno-red-zone -mgeneral-regs-only) \
    $(if $(filter arm64 aarch64,$(NATIVE_ARCH)),-mgeneral-regs-only)
NATIVE_CFLAGS := $(NATIVE_TARGET_FLAGS) -Wall -Wextra -O3 -g -fPIC -c -fno-plt -DMICRO_NATIVE \
    -fomit-frame-pointer $(NATIVE_ARCH_CFLAGS) -fno-stack-protector \
    -fno-asynchronous-unwind-tables -fno-unwind-tables -fno-jump-tables \
    -mllvm -switch-to-lookup=false \
    $(SYS_INCLUDE_FLAGS) -MMD -MP

# Reuse the kernel_offsets.h that micro/programs generates from BTF, so the
# context-struct offsets in common.h's MICRO_NATIVE branch match the host
# kernel layout. Not all Stage 2 programs reference SKB/XDP context offsets
# directly, but common.h includes the header unconditionally.
KERNEL_OFFSETS_DIR ?= $(REPO_ROOT)/micro/programs/build-x86
KERNEL_OFFSETS := $(KERNEL_OFFSETS_DIR)/kernel_offsets.h
KERNEL_OFFSETS_INCLUDE := $(dir $(abspath $(KERNEL_OFFSETS)))
MICRO_PROGRAMS_DIR := $(REPO_ROOT)/micro/programs

BPF_SRCS := $(wildcard *.bpf.c)
BPF_OBJS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.bpf.o,$(BPF_SRCS))
NATIVE_OBJS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.native.o,$(BPF_SRCS))
DEPS := $(BPF_OBJS:.o=.d) $(NATIVE_OBJS:.o=.d)

.PHONY: all clean
all: $(BPF_OBJS) $(NATIVE_OBJS)

$(OUTPUT_DIR):
	mkdir -p "$@"

$(KERNEL_OFFSETS):
	$(MAKE) -C $(MICRO_PROGRAMS_DIR) OUTPUT_DIR="$(KERNEL_OFFSETS_DIR)" "$@"

$(OUTPUT_DIR)/%.bpf.o: %.bpf.c | $(OUTPUT_DIR)
	$(CLANG) $(BPF_CFLAGS) -MF "$(OUTPUT_DIR)/$*.bpf.d" -MT "$@" -c -o "$@" "$<"

$(OUTPUT_DIR)/%.native.o: %.bpf.c $(KERNEL_OFFSETS) Makefile | $(OUTPUT_DIR)
	$(CLANG) $(NATIVE_CFLAGS) -I"$(MICRO_PROGRAMS_DIR)" -I"$(KERNEL_OFFSETS_INCLUDE)" \
	    -MF "$(OUTPUT_DIR)/$*.native.d" -MT "$@" -o "$@" "$<"

clean:
	rm -rf $(OUTPUT_DIR)

-include $(DEPS)
