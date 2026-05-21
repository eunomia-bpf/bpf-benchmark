SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

.PHONY: all clean vmlinux katran bcc tetragon cilium otel tracee

ROOT := $(abspath ../..)
VENDOR := $(ROOT)/vendor
BUILD := $(VENDOR)/build/native-bpf
KERNEL_RELEASE ?= $(shell uname -r)
ARCH := x86
GOARCH := amd64

CLANG ?= clang-18
LLC ?= llc-18
BPF_LINK ?= llvm-link-18
LLVM_STRIP ?= llvm-strip-18
BPFTOOL ?= $(VENDOR)/build/x86/bpftool/bin/bpftool
VMLINUX_BTF ?= /sys/kernel/btf/vmlinux

OUT := $(BUILD)/$(ARCH)/$(KERNEL_RELEASE)
VMLINUX_H := targets/$(ARCH)/$(KERNEL_RELEASE)/vmlinux.h

KATRAN_OBJS := balancer healthchecking_ipip healthchecking xdp_root
BCC_TOOLS := capable biosnoop vfsstat opensnoop syscount tcpconnect tcplife runqlat
BCC_OBJS := $(patsubst %,$(OUT)/bcc/output/%.bpf.o,$(BCC_TOOLS))
CILIUM_OBJS := bpf_lxc.o bpf_overlay.o bpf_sock.o bpf_host.o bpf_wireguard.o bpf_xdp.o bpf_alignchecker.o

all: vmlinux katran bcc tetragon cilium otel tracee

clean:
	rm -rf "$(OUT)"
	rm -rf "$(CURDIR)/tetragon/bpf/objs" "$(CURDIR)/tetragon/bpf/deps"
	$(MAKE) -C "$(CURDIR)/cilium/bpf" clean >/dev/null
	$(MAKE) -C "$(CURDIR)/otel/support/ebpf" clean >/dev/null

vmlinux: $(VMLINUX_H) bcc/libbpf-tools/x86/vmlinux.h tetragon/bpf/include/vmlinux_generated_x86.h

$(VMLINUX_H): $(VMLINUX_BTF)
	install -d "$(dir $@)"
	"$(BPFTOOL)" btf dump file "$(VMLINUX_BTF)" format c > "$@"

bcc/libbpf-tools/x86/vmlinux.h: $(VMLINUX_H)
	install -D -m 0644 "$<" "$@"

tetragon/bpf/include/vmlinux_generated_x86.h: $(VMLINUX_H)
	install -d "$(dir $@)"
	sed 's/__VMLINUX_H__/__VMLINUX_GENERATED_X86_H__/g' "$<" > "$@"

katran:
	install -d "$(OUT)/katran"
	for src in $(KATRAN_OBJS); do \
		"$(CLANG)" -I"$(CURDIR)/katran" -I"$(CURDIR)/katran/katran/lib/linux_includes" \
			-DDEBUG -D__KERNEL__ -Wno-unused-value -Wno-pointer-sign \
			-Wno-compare-distinct-pointer-types -O2 -emit-llvm -c -g \
			"$(CURDIR)/katran/katran/lib/bpf/$${src}.c" -o - \
		| "$(LLC)" -march=bpf -filetype=obj -o "$(OUT)/katran/$${src}.bpf.o"; \
	done

bcc: bcc/libbpf-tools/x86/vmlinux.h
	$(MAKE) -C "$(CURDIR)/bcc/libbpf-tools" CLANG="$(CLANG)" LLVM_STRIP="$(LLVM_STRIP)" \
		OUTPUT="$(OUT)/bcc/output" APPS="$(BCC_TOOLS)" LIBBPF_OBJ= \
		INCLUDES="-I/usr/include -I/usr/include/x86_64-linux-gnu" \
		$(BCC_OBJS)

tetragon: tetragon/bpf/include/vmlinux_generated_x86.h
	install -d "$(OUT)/tetragon"
	$(MAKE) -C "$(CURDIR)/tetragon/bpf" CLANG="$(CLANG)" LLC="$(LLC)" \
		BPF_TARGET_ARCH=x86 \
		OBJS='$$(filter-out $$(OBJSDIR)bpf_map_test_p1.o $$(OBJSDIR)bpf_map_test_p2.o $$(OBJSDIR)bpf_map_test_p3.o,$$(PROCESSOBJ) $$(CGROUPOBJ) $$(ALIGNCHECKEROBJ))' \
		DEPS='$$(patsubst $$(OBJSDIR)%.o,$$(DEPSDIR)%.d,$$(OBJS))' -j"$$(nproc)"
	for obj in "$(CURDIR)/tetragon/bpf/objs/"*.o; do \
		case "$$(basename "$${obj}")" in bpf_map_test_p*.o|bpf_lseek*.o) continue;; esac; \
		install -D -m 0644 "$${obj}" "$(OUT)/tetragon/$$(basename "$${obj}")"; \
	done

cilium:
	install -d "$(OUT)/cilium"
	$(MAKE) -C "$(CURDIR)/cilium/bpf" CLANG="$(CLANG)" $(CILIUM_OBJS) -j"$$(nproc)"
	for obj in $(CILIUM_OBJS); do \
		install -D -m 0644 "$(CURDIR)/cilium/bpf/$${obj}" "$(OUT)/cilium/$${obj}"; \
	done

otel:
	install -d "$(OUT)/otel"
	$(MAKE) -C "$(CURDIR)/otel/support/ebpf" BPF_CLANG="$(CLANG)" \
		BPF_LINK="$(BPF_LINK)" LLC="$(LLC)" STRIP="$(LLVM_STRIP)" \
		TARGET_ARCH="$(GOARCH)" TRACER_NAME="tracer.ebpf.$(GOARCH)" -j"$$(nproc)"
	install -D -m 0644 "$(CURDIR)/otel/support/ebpf/tracer.ebpf.$(GOARCH)" \
		"$(OUT)/otel/tracer.ebpf.$(GOARCH)"

tracee:
	install -d "$(OUT)/tracee/lsm_support"
	install -D -m 0644 "$(VENDOR)/repos/tracee/pkg/ebpf/c/vmlinux.h" \
		"$(CURDIR)/tracee/pkg/ebpf/c/vmlinux.h"
	trace_inc="-I$(CURDIR)/tracee/pkg/ebpf/c -I/usr/include -I/usr/include/x86_64-linux-gnu"; \
	"$(CLANG)" -D__TARGET_ARCH_x86 -D__BPF_TRACING__ -DCORE -DCOMMON_BUILD \
		$${trace_inc} -target bpf -O2 -g -mcpu=v2 \
		-c "$(CURDIR)/tracee/pkg/ebpf/c/tracee.bpf.c" \
		-o "$(OUT)/tracee/tracee.bpf.o"; \
	for src in kprobe_check lsm_check; do \
		"$(CLANG)" -D__TARGET_ARCH_x86 -D__BPF_TRACING__ \
			$${trace_inc} -target bpf -O2 -g -mcpu=v2 \
			-c "$(CURDIR)/tracee/pkg/ebpf/c/lsmsupport/$${src}.bpf.c" \
			-o "$(OUT)/tracee/lsm_support/$${src}.bpf.o"; \
	done
