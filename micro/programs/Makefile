DEB_HOST_MULTIARCH := $(shell gcc -print-multiarch 2>/dev/null || dpkg-architecture -qDEB_HOST_MULTIARCH 2>/dev/null)
SYS_INCLUDE_FLAGS ?= $(if $(DEB_HOST_MULTIARCH),-I/usr/include/$(DEB_HOST_MULTIARCH))
OUTPUT_DIR ?= $(CURDIR)
CLANG ?= clang
BPFREJIT_MICRO_BPF_COMPILER ?= clang
BPF_KINSN_LLC ?=
BPF_KINSN_LLC_FLAGS ?=
BPF_KINSN_TRIPLE ?= bpfel
BPF_KINSN_CPU ?= v3
NATIVE_TARGET ?=
NATIVE_ARCH ?= $(shell uname -m)
REPO_ROOT := $(abspath $(CURDIR)/../..)

CFLAGS := -Wall -Wextra -O2 -g -target bpf $(SYS_INCLUDE_FLAGS) -MMD -MP
NATIVE_TARGET_FLAGS := $(if $(NATIVE_TARGET),--target=$(NATIVE_TARGET))
NATIVE_ARCH_CFLAGS := $(if $(filter x86_64 amd64,$(NATIVE_ARCH)),-mno-red-zone)
NATIVE_CFLAGS := $(NATIVE_TARGET_FLAGS) -Wall -Wextra -O2 -g -fPIC -shared -fno-plt -DMICRO_NATIVE \
	-fomit-frame-pointer $(NATIVE_ARCH_CFLAGS) -fno-stack-protector \
	-fno-asynchronous-unwind-tables -fno-unwind-tables -fno-jump-tables \
	-mllvm -switch-to-lookup=false \
	$(SYS_INCLUDE_FLAGS) -MMD -MP
BPF_SRCS := $(wildcard *.bpf.c)
BPF_OBJS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.bpf.o,$(BPF_SRCS))

# Native_lab support: the userspace .native.so reads kernel ctx structs
# directly via hard-coded offsets. Offsets are extracted from the running
# kernel's BTF at build time so the native code lines up with whatever
# `struct xdp_buff` / `struct sk_buff` the fork kernel is built with.
KERNEL_VMLINUX ?= $(REPO_ROOT)/vendor/build/x86/linux/vmlinux
KERNEL_OFFSETS_INPUT ?=
KERNEL_OFFSETS := $(OUTPUT_DIR)/kernel_offsets.h
BPF_DEPS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.bpf.d,$(BPF_SRCS))
NATIVE_SOS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.native.so,$(BPF_SRCS))
NATIVE_DEPS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.native.d,$(BPF_SRCS))

.PHONY: all clean

all: $(BPF_OBJS) $(NATIVE_SOS)

$(OUTPUT_DIR)/%.bpf.o: %.bpf.c | $(OUTPUT_DIR)
ifeq ($(BPFREJIT_MICRO_BPF_COMPILER),kinsn-llvm)
	@test -x "$(BPF_KINSN_LLC)" || { echo "BPF_KINSN_LLC must point to the kinsn-enabled llc" >&2; exit 1; }
	$(CLANG) $(CFLAGS) -MF "$(OUTPUT_DIR)/$*.bpf.d" -MT "$@" -S -emit-llvm -c -o "$(OUTPUT_DIR)/$*.bpf.ll" "$<"
	"$(BPF_KINSN_LLC)" -mtriple="$(BPF_KINSN_TRIPLE)" -mcpu="$(BPF_KINSN_CPU)" -filetype=obj -bpf-enable-kinsn-select $(BPF_KINSN_LLC_FLAGS) -o "$@" "$(OUTPUT_DIR)/$*.bpf.ll"
else
	$(CLANG) $(CFLAGS) -MF "$(OUTPUT_DIR)/$*.bpf.d" -MT "$@" -c -o "$@" "$<"
endif

ifeq ($(KERNEL_OFFSETS_INPUT),)
$(KERNEL_OFFSETS): $(KERNEL_VMLINUX) Makefile | $(OUTPUT_DIR)
	@if [ ! -x "$$(command -v pahole)" ]; then \
	    echo "pahole not found; install dwarves to extract kernel field offsets" >&2; \
	    exit 1; \
	fi
	@{ \
	    echo '/* Auto-generated from $(KERNEL_VMLINUX). DO NOT EDIT. */'; \
	    echo '#pragma once'; \
	    pahole -C sk_buff '$(KERNEL_VMLINUX)' 2>/dev/null | \
	        awk '/unsigned char \*\s*data;/ { match($$0, /\/\*[ \t]+([0-9]+)[ \t]+[0-9]+ \*\//, a); printf "#define K_SK_BUFF_DATA_OFFSET %du\n", a[1] } \
	             /unsigned int\s*len;/      { match($$0, /\/\*[ \t]+([0-9]+)[ \t]+[0-9]+ \*\//, a); printf "#define K_SK_BUFF_LEN_OFFSET %du\n", a[1] } \
	             /char\s+cb\[/              { match($$0, /\/\*[ \t]+([0-9]+)[ \t]+[0-9]+ \*\//, a); printf "#define K_SK_BUFF_CB_OFFSET %du\n", a[1] }'; \
	    pahole -C bpf_skb_data_end '$(KERNEL_VMLINUX)' 2>/dev/null | \
	        awk '/void \*\s*data_end;/ { match($$0, /\/\*[ \t]+([0-9]+)[ \t]+[0-9]+ \*\//, a); printf "#define K_BPF_SKB_DATA_END_FIELD_OFFSET %du\n", a[1] }'; \
	    pahole -C qdisc_skb_cb '$(KERNEL_VMLINUX)' 2>/dev/null | \
	        awk '/unsigned char\s+data\[/ { match($$0, /\/\*[ \t]+([0-9]+)[ \t]+[0-9]+ \*\//, a); printf "#define K_QDISC_SKB_CB_DATA_OFFSET %du\n", a[1] }'; \
	    echo '#define K_SK_BUFF_BPF_DATA_END_OFFSET (K_SK_BUFF_CB_OFFSET + K_BPF_SKB_DATA_END_FIELD_OFFSET)'; \
	    echo '#define K_SK_BUFF_BPF_CB_OFFSET (K_SK_BUFF_CB_OFFSET + K_QDISC_SKB_CB_DATA_OFFSET)'; \
	    pahole -C xdp_buff '$(KERNEL_VMLINUX)' 2>/dev/null | \
	        awk '/void \*\s*data;/     { match($$0, /\/\*[ \t]+([0-9]+)[ \t]+[0-9]+ \*\//, a); printf "#define K_XDP_BUFF_DATA_OFFSET %du\n", a[1] } \
	             /void \*\s*data_end;/ { match($$0, /\/\*[ \t]+([0-9]+)[ \t]+[0-9]+ \*\//, a); printf "#define K_XDP_BUFF_DATA_END_OFFSET %du\n", a[1] }'; \
	} > "$@"
else
$(KERNEL_OFFSETS): $(KERNEL_OFFSETS_INPUT) | $(OUTPUT_DIR)
	cp "$<" "$@"
endif

$(NATIVE_SOS): $(KERNEL_OFFSETS)

$(OUTPUT_DIR)/%.native.so: %.bpf.c $(KERNEL_OFFSETS) | $(OUTPUT_DIR)
	$(CLANG) $(NATIVE_CFLAGS) -I"$(OUTPUT_DIR)" -MF "$(OUTPUT_DIR)/$*.native.d" -MT "$@" -o "$@" "$<"

$(OUTPUT_DIR):
	mkdir -p "$@"

clean:
	rm -f \
		"$(OUTPUT_DIR)"/*.bpf.o \
			"$(OUTPUT_DIR)"/*.bpf.d \
			"$(OUTPUT_DIR)"/*.bpf.ll \
			"$(OUTPUT_DIR)"/*.native.so \
			"$(OUTPUT_DIR)"/*.native.d \
			"$(OUTPUT_DIR)"/*.bpf.bin \
			"$(OUTPUT_DIR)"/*.directive.bin \
			"$(OUTPUT_DIR)"/*.policy.bin \
			"$(OUTPUT_DIR)"/kernel_offsets.h

-include $(BPF_DEPS) $(NATIVE_DEPS)
