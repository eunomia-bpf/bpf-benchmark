# Stage 2 POC: build each .bpf.c twice -- once as BPF (.bpf.o) so the
# kernel verifier + JIT can resolve helpers/maps for us, once as native
# x86 (.native.so) so we have userspace-compiled bytes to splat via the
# bpf_x86_native_lab kinsn after native-link patches in the resolved
# addresses.
DEB_HOST_MULTIARCH := $(shell gcc -print-multiarch 2>/dev/null || dpkg-architecture -qDEB_HOST_MULTIARCH 2>/dev/null)
SYS_INCLUDE_FLAGS := $(if $(DEB_HOST_MULTIARCH),-I/usr/include/$(DEB_HOST_MULTIARCH))
REPO_ROOT := $(abspath $(CURDIR)/../..)
OUTPUT_DIR ?= $(CURDIR)/build
CLANG ?= clang

BPF_CFLAGS := -Wall -Wextra -O2 -g -target bpf $(SYS_INCLUDE_FLAGS) -MMD -MP

# Native-lab build: clang -target x86_64 from the SAME source. We stop
# at the .o stage on purpose: a fully-linked .so already resolves every
# external symbol (helpers, maps) through the userspace PLT/GOT, baking
# in addresses that have no meaning inside the kernel. An object file's
# `.rela.text` section still carries unresolved relocations referencing
# the original symbol names (R_X86_64_PLT32 against `bpf_ktime_get_ns`,
# R_X86_64_PC32 against `&test_array`, etc.) -- exactly what native-link
# needs to patch with kernel addresses.
#
# Flags:
#   -c                  emit .o, skip .so linking.
#   -fPIC               PC-relative code; assembler emits R_X86_64_PLT32 /
#                       R_X86_64_PC32 / R_X86_64_REX_GOTPCRELX style relocs.
#   -DMICRO_NATIVE      pick the userspace branch of native_helpers.h /
#                       common.h.
#   -fomit-frame-pointer / -mno-red-zone / -fno-stack-protector /
#   -fno-jump-tables / -mllvm -switch-to-lookup=false:
#                       inherited from the Stage 1 micro/programs native
#                       build flags.
NATIVE_CFLAGS := -Wall -Wextra -O2 -g -fPIC -c -DMICRO_NATIVE \
    -fomit-frame-pointer -mno-red-zone -fno-stack-protector \
    -fno-asynchronous-unwind-tables -fno-unwind-tables -fno-jump-tables \
    -mllvm -switch-to-lookup=false \
    $(SYS_INCLUDE_FLAGS) -MMD -MP

# Reuse the kernel_offsets.h that micro/programs generates from BTF, so
# the SKB context offset helpers from common.h work in this tree too.
# We don't need them for the current Stage 2 test programs (all XDP) but
# common.h includes the header unconditionally in MICRO_NATIVE mode.
KERNEL_OFFSETS := $(REPO_ROOT)/micro/programs/kernel_offsets.h
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
	$(MAKE) -C $(MICRO_PROGRAMS_DIR) $@

$(OUTPUT_DIR)/%.bpf.o: %.bpf.c | $(OUTPUT_DIR)
	$(CLANG) $(BPF_CFLAGS) -MF "$(OUTPUT_DIR)/$*.bpf.d" -MT "$@" -c -o "$@" "$<"

$(OUTPUT_DIR)/%.native.o: %.bpf.c $(KERNEL_OFFSETS) | $(OUTPUT_DIR)
	$(CLANG) $(NATIVE_CFLAGS) -I"$(MICRO_PROGRAMS_DIR)" \
	    -MF "$(OUTPUT_DIR)/$*.native.d" -MT "$@" -o "$@" "$<"

clean:
	rm -rf $(OUTPUT_DIR)

-include $(DEPS)
