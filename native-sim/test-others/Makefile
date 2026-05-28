# Standalone build + run for native-sim/test-others/. No dependency on the
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
# flags as native-sim/test/Makefile, so the resulting objects are produced
# by an identical toolchain — the only difference is the runner.

DEB_HOST_MULTIARCH := $(shell gcc -print-multiarch 2>/dev/null || dpkg-architecture -qDEB_HOST_MULTIARCH 2>/dev/null)
SYS_INCLUDE_FLAGS := $(if $(DEB_HOST_MULTIARCH),-I/usr/include/$(DEB_HOST_MULTIARCH))
REPO_ROOT := $(abspath $(CURDIR)/../..)
OUTPUT_DIR ?= $(CURDIR)/build
CLANG ?= clang
NATIVE_ARCH ?= $(shell uname -m)

# Locate vendored libbpf static lib + headers. Mirrors what runner/
# uses; the runner build links against build-llvmbpf/vendor/libbpf,
# which is shipped pre-built in the runtime container. For host
# debugging we fall back to system libbpf (`-lbpf`).
RUNNER_LIBBPF_DIR := $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/obj
RUNNER_LIBBPF_HDR := $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include
ifeq ($(wildcard $(RUNNER_LIBBPF_DIR)/libbpf.a),)
LIBBPF_CFLAGS :=
LIBBPF_LDFLAGS := -lbpf -lelf -lz
else
LIBBPF_CFLAGS := -I$(RUNNER_LIBBPF_HDR)
LIBBPF_LDFLAGS := $(RUNNER_LIBBPF_DIR)/libbpf.a -lelf -lz
endif

BPF_CFLAGS := -Wall -Wextra -O2 -g -target bpf $(SYS_INCLUDE_FLAGS) -MMD -MP

# Same flags as native-sim/test/Makefile so .native.o has identical
# constraints (no PLT, no jump tables, no red zone, no unwind tables).
NATIVE_ARCH_CFLAGS := $(if $(filter x86_64 amd64,$(NATIVE_ARCH)),-march=native -mno-red-zone -mgeneral-regs-only) \
    $(if $(filter arm64 aarch64,$(NATIVE_ARCH)),-mtune=neoverse-n1 -mgeneral-regs-only)
NATIVE_CFLAGS := -Wall -Wextra -O2 -g -fPIC -c -fno-plt -DMICRO_NATIVE \
    -fomit-frame-pointer $(NATIVE_ARCH_CFLAGS) -fno-stack-protector \
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

# C++ runner that exercises BOTH the kernel-JIT path (libbpf) and the
# native_lab kinsn path (via native_lab_attach.cpp), then reports
# per-call handler overhead for each. -fno-omit-frame-pointer keeps the
# uprobe target visible in symbols even at -O2.
$(RUNNER): runner.cpp native_lab_attach.cpp native_lab_attach.hpp | $(OUTPUT_DIR)
	c++ -O2 -g -Wall -Wextra -std=c++17 -fno-omit-frame-pointer \
	    $(LIBBPF_CFLAGS) -o "$@" runner.cpp native_lab_attach.cpp \
	    $(LIBBPF_LDFLAGS)

test: all
	sudo "$(RUNNER)"

# Boot virtme-ng with the bench framework's kinsn-aware kernel + insmod
# the bpf_x86_native_lab .ko, then run the perf-compare runner.
# Requires the regular bench build to have produced the kernel under vendor/build
# and the kinsn modules under module/x86/build. Host's Ubuntu
# kernel doesn't ship the kinsn / BPF_PROG_REJIT framework, so the
# native_lab leg fails outside the framework VM -- this is the canonical
# way to exercise it standalone.
KIMG := $(REPO_ROOT)/vendor/build/x86/linux/arch/x86/boot/bzImage
KINSN_KO_DIR := $(REPO_ROOT)/module/x86/build
NATIVE_LINK_HOST := $(REPO_ROOT)/native-sim/x86/native_lab/native_link/target/release/native-link

VM_SCRIPT := $(OUTPUT_DIR)/run-in-vm.sh
test-vm: all $(VM_SCRIPT)
	@if [ ! -f "$(KIMG)" ]; then \
	    echo "framework kernel missing: $(KIMG)"; \
	    echo "run \`make corpus\` (or any bench target) once to populate the cache."; \
	    exit 1; \
	fi
	@if [ ! -f "$(NATIVE_LINK_HOST)" ]; then \
	    echo "native-link binary missing: $(NATIVE_LINK_HOST)"; \
	    echo "run \`(cd native-sim/x86/native_lab/native_link && cargo build --release)\`."; \
	    exit 1; \
	fi
	vng --run "$(KIMG)" --cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" \
	    --overlay-rwdir /tmp --disable-monitor \
	    --append "loglevel=7 panic=30 oops=panic" \
	    --exec "$(VM_SCRIPT)"

# Script the VM runs at boot. Loads kinsn modules, then invokes the
# perf-compare runner with the host-built native-link binary path
# threaded through via an env var.
$(VM_SCRIPT): | $(OUTPUT_DIR)
	@printf '%s\n' \
	    '#!/bin/bash' \
	    'set -eu' \
	    'cd "$(CURDIR)"' \
	    'for ko in $(KINSN_KO_DIR)/bpf_*.ko; do' \
	    '    insmod "$$ko" 2>/dev/null || true' \
	    'done' \
	    'export BPFREJIT_NATIVE_LINK_BINARY="$(NATIVE_LINK_HOST)"' \
	    '"$(RUNNER)"' \
	    > "$@"
	@chmod +x "$@"

clean:
	rm -rf $(OUTPUT_DIR)

-include $(DEPS)
