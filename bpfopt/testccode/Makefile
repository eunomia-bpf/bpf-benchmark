CLANG ?= clang

ROOT := ../..
BCC_ROOT := /tmp/bpfopt-upstream-src/bcc/libbpf-tools
BPFTRACE_ROOT := /tmp/bpfopt-upstream-src/bpftrace/src/stdlib
TETRAGON_ROOT := /tmp/bpfopt-upstream-src/tetragon/bpf
TRACEE_ROOT := /tmp/bpfopt-upstream-src/tracee/pkg/ebpf/c

COMMON_CFLAGS ?= \
	-O3 -S -ffreestanding -fno-stack-protector -fno-asynchronous-unwind-tables \
	-Wno-address-of-packed-member -Wno-compare-distinct-pointer-types \
	-Wno-gnu-variable-sized-type-not-at-end -Wno-incompatible-library-redeclaration \
	-Wno-int-conversion -Wno-macro-redefined -Wno-pointer-sign \
	-Wno-tautological-compare -Wno-unknown-attributes \
	-include native_shims/core_builtins.h

X86_CFLAGS ?= --target=x86_64-linux-gnu -march=x86-64-v3 -masm=intel -D__TARGET_ARCH_x86
ARM64_CFLAGS ?= --target=aarch64-linux-gnu -march=armv8.2-a -D__TARGET_ARCH_arm64

BCC_X86_CFLAGS := -I$(BCC_ROOT) -I$(BCC_ROOT)/x86
BCC_ARM64_CFLAGS := -I$(BCC_ROOT) -I$(BCC_ROOT)/arm64
BPFTRACE_CFLAGS := -Inative_shims/bpftrace -I$(BPFTRACE_ROOT) -I$(BPFTRACE_ROOT)/include -I$(BPFTRACE_ROOT)/strings
CILIUM_CFLAGS := -Inative_shims/cilium -I$(ROOT)/runner/repos/cilium/bpf -I$(ROOT)/runner/repos/cilium/bpf/include -I$(ROOT)/runner/repos/cilium/bpf/include/bpf/ctx
KATRAN_CFLAGS := -I$(ROOT)/runner/repos/katran -I$(ROOT)/runner/repos/katran/katran/lib/linux_includes
OTEL_CFLAGS := -I$(ROOT)/runner/repos/opentelemetry-ebpf-profiler/support/ebpf
TETRAGON_CFLAGS := -fno-integrated-as -Inative_shims/tetragon -Inative_shims/tetragon/lib -Inative_shims/tetragon/process -I$(TETRAGON_ROOT)/include -I$(TETRAGON_ROOT)/lib -I$(TETRAGON_ROOT)/libbpf -I$(TETRAGON_ROOT)/process -I$(TETRAGON_ROOT)/process/types -I$(TETRAGON_ROOT)/errmetrics -I$(TETRAGON_ROOT)
TRACEE_CFLAGS := -Inative_shims/tracee -I$(TRACEE_ROOT) -I$(TRACEE_ROOT)/common -I$(TRACEE_ROOT)/lsmsupport

C_SRCS := $(sort $(wildcard *.c))
X86_ASM := $(C_SRCS:.c=.x86.s)
ARM64_ASM := $(C_SRCS:.c=.arm64.s)

app_cflags_x86 = \
	$(if $(filter bcc_%,$(notdir $(1))),$(BCC_X86_CFLAGS),) \
	$(if $(filter bpftrace_%,$(notdir $(1))),$(BPFTRACE_CFLAGS),) \
	$(if $(filter cilium_%,$(notdir $(1))),$(CILIUM_CFLAGS),) \
	$(if $(filter katran_%,$(notdir $(1))),$(KATRAN_CFLAGS),) \
	$(if $(filter otel_%,$(notdir $(1))),$(OTEL_CFLAGS),) \
	$(if $(filter tetragon_%,$(notdir $(1))),$(TETRAGON_CFLAGS),) \
	$(if $(filter tracee_%,$(notdir $(1))),$(TRACEE_CFLAGS),)

app_cflags_arm64 = \
	$(if $(filter bcc_%,$(notdir $(1))),$(BCC_ARM64_CFLAGS),) \
	$(if $(filter bpftrace_%,$(notdir $(1))),$(BPFTRACE_CFLAGS),) \
	$(if $(filter cilium_%,$(notdir $(1))),$(CILIUM_CFLAGS),) \
	$(if $(filter katran_%,$(notdir $(1))),$(KATRAN_CFLAGS),) \
	$(if $(filter otel_%,$(notdir $(1))),$(OTEL_CFLAGS),) \
	$(if $(filter tetragon_%,$(notdir $(1))),$(TETRAGON_CFLAGS),) \
	$(if $(filter tracee_%,$(notdir $(1))),$(TRACEE_CFLAGS),)

.PHONY: all x86 arm64 clean list

all: x86 arm64

x86: $(X86_ASM)

arm64: $(ARM64_ASM)

list:
	@printf '%s\n' $(C_SRCS)

%.x86.s: %.c Makefile
	$(CLANG) $(COMMON_CFLAGS) $(X86_CFLAGS) $(call app_cflags_x86,$<) $< -o $@

%.arm64.s: %.c Makefile
	$(CLANG) $(COMMON_CFLAGS) $(ARM64_CFLAGS) $(call app_cflags_arm64,$<) $< -o $@

clean:
	rm -f $(X86_ASM) $(ARM64_ASM)
