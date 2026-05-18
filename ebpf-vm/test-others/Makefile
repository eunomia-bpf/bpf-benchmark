# Standalone build + run for ebpf-vm/test-others/. No dependency on the
# bench micro framework — just clang, libbpf, and a hosted libc.
#
# `make` produces:
#   build/runner                  — standalone harness binary
#   build/<name>.bpf.o            — kernel-side libbpf-loadable object
#   build/<name>.native.o         — clang -target x86_64 object for the
#                                   native_lab kinsn path (built but not
#                                   exercised by the kernel-side test;
#                                   see README for native_lab status).
#
# `make test` runs each program with the standalone harness and checks
# the per-program map count matches the expected trigger count.
#
# Reuses the same kernel BPF flags and the same -target x86_64 native
# flags as ebpf-vm/test/Makefile, so the resulting objects are produced
# by an identical toolchain — the only difference is the runner.

DEB_HOST_MULTIARCH := $(shell gcc -print-multiarch 2>/dev/null || dpkg-architecture -qDEB_HOST_MULTIARCH 2>/dev/null)
SYS_INCLUDE_FLAGS := $(if $(DEB_HOST_MULTIARCH),-I/usr/include/$(DEB_HOST_MULTIARCH))
REPO_ROOT := $(abspath $(CURDIR)/../..)
OUTPUT_DIR ?= $(CURDIR)/build
CLANG ?= clang

# Locate vendored libbpf static lib + headers. Mirrors what runner/
# uses; the runner build links against build-llvmbpf/vendor/libbpf,
# which is shipped pre-built in the runtime container. For host
# debugging we fall back to system libbpf (`-lbpf`).
RUNNER_LIBBPF_DIR := $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/obj
RUNNER_LIBBPF_HDR := $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/usr/include
ifeq ($(wildcard $(RUNNER_LIBBPF_DIR)/libbpf.a),)
LIBBPF_CFLAGS :=
LIBBPF_LDFLAGS := -lbpf -lelf -lz
else
LIBBPF_CFLAGS := -I$(RUNNER_LIBBPF_HDR)
LIBBPF_LDFLAGS := $(RUNNER_LIBBPF_DIR)/libbpf.a -lelf -lz
endif

BPF_CFLAGS := -Wall -Wextra -O2 -g -target bpf $(SYS_INCLUDE_FLAGS) -MMD -MP

# Same flags as ebpf-vm/test/Makefile so .native.o has identical
# constraints (no PLT, no jump tables, no red zone, no unwind tables).
NATIVE_CFLAGS := -Wall -Wextra -O2 -g -fPIC -c -fno-plt -DMICRO_NATIVE \
    -fomit-frame-pointer -mno-red-zone -fno-stack-protector \
    -fno-asynchronous-unwind-tables -fno-unwind-tables -fno-jump-tables \
    -mllvm -switch-to-lookup=false \
    $(SYS_INCLUDE_FLAGS) -MMD -MP

BPF_SRCS := $(wildcard *.bpf.c)
BPF_OBJS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.bpf.o,$(BPF_SRCS))
NATIVE_OBJS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.native.o,$(BPF_SRCS))
RUNNER := $(OUTPUT_DIR)/runner
DEPS := $(BPF_OBJS:.o=.d) $(NATIVE_OBJS:.o=.d)

.PHONY: all clean test
all: $(BPF_OBJS) $(NATIVE_OBJS) $(RUNNER)

$(OUTPUT_DIR):
	mkdir -p "$@"

$(OUTPUT_DIR)/%.bpf.o: %.bpf.c | $(OUTPUT_DIR)
	$(CLANG) $(BPF_CFLAGS) -MF "$(OUTPUT_DIR)/$*.bpf.d" -MT "$@" -c -o "$@" "$<"

$(OUTPUT_DIR)/%.native.o: %.bpf.c | $(OUTPUT_DIR)
	$(CLANG) $(NATIVE_CFLAGS) -MF "$(OUTPUT_DIR)/$*.native.d" -MT "$@" -o "$@" "$<"

# Disable frame-pointer omission for the runner so the uprobe target is
# easy to spot in objdump; otherwise -O2 may inline it even with
# __attribute__((noinline)) on older clang. Build with `cc` (host) for
# the runner binary.
$(RUNNER): runner.c | $(OUTPUT_DIR)
	cc -O2 -g -Wall -Wextra -fno-omit-frame-pointer \
	    $(LIBBPF_CFLAGS) -o "$@" runner.c $(LIBBPF_LDFLAGS)

test: all
	@echo "=== kprobe ==="
	sudo "$(RUNNER)" "$(OUTPUT_DIR)/kprobe_getpid.bpf.o" kprobe
	@echo "=== uprobe ==="
	sudo "$(RUNNER)" "$(OUTPUT_DIR)/uprobe_self.bpf.o" uprobe
	@echo "=== raw_tracepoint ==="
	sudo "$(RUNNER)" "$(OUTPUT_DIR)/tracepoint_sched_switch.bpf.o" raw_tp

clean:
	rm -rf $(OUTPUT_DIR)

-include $(DEPS)
