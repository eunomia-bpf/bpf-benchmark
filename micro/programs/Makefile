DEB_HOST_MULTIARCH := $(shell gcc -print-multiarch 2>/dev/null || dpkg-architecture -qDEB_HOST_MULTIARCH 2>/dev/null)
SYS_INCLUDE_FLAGS := $(if $(DEB_HOST_MULTIARCH),-I/usr/include/$(DEB_HOST_MULTIARCH))
OUTPUT_DIR ?= $(CURDIR)
CLANG ?= clang
REPO_ROOT := $(abspath $(CURDIR)/../..)

CFLAGS := -Wall -Wextra -O2 -g -target bpf $(SYS_INCLUDE_FLAGS) -MMD -MP
NATIVE_CFLAGS := -Wall -Wextra -O2 -g -fPIC -shared -fno-plt -DMICRO_NATIVE \
	-fomit-frame-pointer -mno-red-zone -fno-stack-protector \
	-fno-asynchronous-unwind-tables -fno-unwind-tables -fno-jump-tables \
	-mllvm -switch-to-lookup=false \
	$(SYS_INCLUDE_FLAGS) -MMD -MP
BPF_SRCS := $(wildcard *.bpf.c)
BPF_OBJS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.bpf.o,$(BPF_SRCS))

# Native_lab support: the userspace .native.so reads kernel ctx structs
# directly via hard-coded offsets. Offsets are extracted from the running
# kernel's BTF at build time so the native code lines up with whatever
# `struct xdp_buff` / `struct sk_buff` the fork kernel is built with.
KERNEL_VMLINUX ?= $(REPO_ROOT)/.cache/repo-build/host/kernel/x86_64/vmlinux
KERNEL_OFFSETS_INPUT ?=
KERNEL_OFFSETS := $(OUTPUT_DIR)/kernel_offsets.h
BPF_DEPS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.bpf.d,$(BPF_SRCS))
NATIVE_SOS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.native.so,$(BPF_SRCS))
NATIVE_DEPS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.native.d,$(BPF_SRCS))

.PHONY: all clean

all: $(BPF_OBJS) $(NATIVE_SOS)

$(OUTPUT_DIR)/%.bpf.o: %.bpf.c | $(OUTPUT_DIR)
	$(CLANG) $(CFLAGS) -MF "$(OUTPUT_DIR)/$*.bpf.d" -MT "$@" -c -o "$@" "$<"

ifeq ($(KERNEL_OFFSETS_INPUT),)
$(KERNEL_OFFSETS): $(KERNEL_VMLINUX) | $(OUTPUT_DIR)
	@if [ ! -x "$$(command -v pahole)" ]; then \
	    echo "pahole not found; install dwarves to extract kernel field offsets" >&2; \
	    exit 1; \
	fi
	@{ \
	    echo '/* Auto-generated from $(KERNEL_VMLINUX). DO NOT EDIT. */'; \
	    echo '#pragma once'; \
	    pahole -C sk_buff '$(KERNEL_VMLINUX)' 2>/dev/null | \
	        awk '/unsigned char \*\s*data;/ { match($$0, /\/\*[ \t]+([0-9]+)[ \t]+[0-9]+ \*\//, a); printf "#define K_SK_BUFF_DATA_OFFSET %du\n", a[1] } \
	             /unsigned int\s*len;/      { match($$0, /\/\*[ \t]+([0-9]+)[ \t]+[0-9]+ \*\//, a); printf "#define K_SK_BUFF_LEN_OFFSET %du\n", a[1] }'; \
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
			"$(OUTPUT_DIR)"/*.native.so \
			"$(OUTPUT_DIR)"/*.native.d \
			"$(OUTPUT_DIR)"/*.bpf.bin \
			"$(OUTPUT_DIR)"/*.directive.bin \
			"$(OUTPUT_DIR)"/*.policy.bin \
			"$(OUTPUT_DIR)"/kernel_offsets.h

-include $(BPF_DEPS) $(NATIVE_DEPS)
