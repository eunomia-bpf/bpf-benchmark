SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

.PHONY: all clean vmlinux katran bcc tetragon cilium otel tracee native-katran native-bcc native-otel native-cilium native-tracee native-tetragon native-artifacts

ROOT := $(abspath ../..)
VENDOR := $(ROOT)/vendor
BUILD := $(VENDOR)/build/native-bpf
# The one kernel (AGENTS.md first section), never the host uname.
KERNEL_RELEASE ?= $(shell cat /workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release)
ARCH := x86
GOARCH := amd64

CLANG ?= clang-18
LLC ?= llc-18
LLVM_NM ?= llvm-nm-18
LLVM_STRIP ?= llvm-strip-18
LLVM_OBJCOPY ?= llvm-objcopy-18
LLVM_DIS ?= llvm-dis-18
BPFTOOL ?= $(VENDOR)/build/x86/bpftool/bin/bpftool
# The one kernel the guests boot, not the host's running kernel: the two BTFs differ, and a
# header generated from the host silently compiles BCC against a different kernel.
VMLINUX_BTF ?= /workspaces/.agent-state/kprog-ck/build-x86/vmlinux
NATIVE_LINK ?= $(ROOT)/kprog/x86/native_lab/native_link/target/release/native-link
NATIVE_IR_LINK ?= /workspaces/.agent-state/kprog-ck/verified-compiler/link-embedded-ir

OUT := $(BUILD)/$(ARCH)/$(KERNEL_RELEASE)
VMLINUX_H := targets/$(ARCH)/$(KERNEL_RELEASE)/vmlinux.h

KATRAN_OBJS := balancer healthchecking_ipip healthchecking xdp_root
BCC_TOOLS_WITH_COMMA := capable biosnoop vfsstat opensnoop syscount tcpconnect tcplife
BCC_LAST_TOOL := runqlat
BCC_TOOLS := $(BCC_TOOLS_WITH_COMMA) $(BCC_LAST_TOOL)
BCC_OBJS := $(patsubst %,$(OUT)/bcc/output/%.bpf.o,$(BCC_TOOLS))
CILIUM_OBJS := bpf_lxc.o bpf_overlay.o bpf_sock.o bpf_host.o bpf_wireguard.o bpf_xdp.o bpf_alignchecker.o
NATIVE_OUT := $(OUT)/native
NATIVE_STAGE_ROOT := $(BUILD)/$(ARCH)/stage
KATRAN_NATIVE_STAGE_OUT := $(NATIVE_STAGE_ROOT)/katran
BCC_NATIVE_STAGE_OUT := $(NATIVE_STAGE_ROOT)/bcc
OTEL_NATIVE_STAGE_OUT := $(NATIVE_STAGE_ROOT)/otelcol-ebpf-profiler
CILIUM_NATIVE_STAGE_OUT := $(NATIVE_STAGE_ROOT)/cilium
TRACEE_NATIVE_STAGE_OUT := $(NATIVE_STAGE_ROOT)/tracee
TETRAGON_NATIVE_STAGE_OUT := $(NATIVE_STAGE_ROOT)/tetragon
TRACEE_LSM_SUPPORT_SRCS := kprobe_check lsm_check
# The kernel architecture name the apps and their headers use (x86, arm64).
BPF_ARCH := $(if $(filter arm64 aarch64,$(ARCH)),arm64,x86)
NATIVE_TARGET_FLAGS := $(if $(filter arm64 aarch64,$(ARCH)),--target=aarch64-linux-gnu)
# System headers: the host multiarch directory on x86; on arm64 the cross sysroot clang finds for
# --target=aarch64-linux-gnu, with /usr/include after it for generic headers.
SYS_INC := $(if $(filter arm64 aarch64,$(ARCH)),-idirafter /usr/include,-I/usr/include -I/usr/include/x86_64-linux-gnu)
NATIVE_ARCH_CFLAGS := $(if $(filter x86,$(ARCH)),-march=native -mno-red-zone -mgeneral-regs-only) \
	$(if $(filter arm64 aarch64,$(ARCH)),-mtune=neoverse-n1 -mgeneral-regs-only -mno-outline-atomics)
# One compile-flag set for every app (operator 2026-11-15: "编译参数所有 app 统一.", "所有优化参数必须打开").
# -fPIC makes map references R_X86_64_REX_GOTPCRELX, the form native-link patches; without it
# clang emits R_X86_64_PC32 and the map address reaches the kernel unpatched. It costs no
# codegen: every app's xdp/.text section is byte-identical with and without it.
NATIVE_CFLAGS := $(NATIVE_TARGET_FLAGS) -O3 -g -fPIC -c \
	-fomit-frame-pointer $(NATIVE_ARCH_CFLAGS) -fno-stack-protector \
	-fno-asynchronous-unwind-tables -fno-unwind-tables \
	-Xclang -fembed-bitcode=all \
	-Wno-unknown-attributes -Wno-compare-distinct-pointer-types
KATRAN_NATIVE_OBJS := $(patsubst %,$(NATIVE_OUT)/katran/%.native.o,$(KATRAN_OBJS))
BCC_NATIVE_OBJS := $(patsubst %,$(NATIVE_OUT)/bcc/%.native.o,$(BCC_TOOLS))
CILIUM_NATIVE_OBJS := $(patsubst %.o,$(NATIVE_OUT)/cilium/%.native.o,$(CILIUM_OBJS))
OTEL_EBPF_DIR := otel/support/ebpf
# The ELF the application embeds in itself and loads (go:embed in support_$(GOARCH).go). The
# original-ELF binder needs its symbol/slot layout, so the canonical payload ships this exact
# tracked file, nothing rebuilt or relinked.
OTEL_SOURCE_BPF_OBJECT := $(VENDOR)/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.$(GOARCH)
OTEL_NATIVE_UNIT_SRCS := $(wildcard $(OTEL_EBPF_DIR)/*.ebpf.c)
OTEL_NATIVE_UNIT_OBJS := $(patsubst $(OTEL_EBPF_DIR)/%.ebpf.c,$(NATIVE_OUT)/otel/%.native.o,$(OTEL_NATIVE_UNIT_SRCS))
OTEL_NATIVE_OBJECT := $(NATIVE_OUT)/otel/otelcol-ebpf-profiler.native.o
OTEL_NATIVE_IR_DIR := $(NATIVE_OUT)/otel/ir
OTEL_NATIVE_IR := $(OTEL_NATIVE_IR_DIR)/otelcol-ebpf-profiler.llvmbc
TRACEE_NATIVE_OBJECT := $(NATIVE_OUT)/tracee/tracee.native.o
TRACEE_LSM_SUPPORT_NATIVE_OBJS := $(patsubst %,$(NATIVE_OUT)/tracee/lsm_support/%.native.o,$(TRACEE_LSM_SUPPORT_SRCS))
TRACEE_NATIVE_OBJS := $(TRACEE_NATIVE_OBJECT) $(TRACEE_LSM_SUPPORT_NATIVE_OBJS)

# The switches cilium-agent itself turns on for the frozen workload, read from the node_config.h, ep_config.h,
# netdev_config.h and filter_config.h it generates (/workspaces/kprog-raw/perf/20261113-cilium-context-runtime-retry2/
# baseline-state/state): IPv4 with masquerade and nodeport, every packet traced (ep_config.h #undef
# MONITOR_AGGREGATION, so lib/trace.h takes TRACE_AGGREGATE_NONE = 0), policy audit and verdict notifications.
# Node addresses vary per run and stay runtime values; only these compile-time switches are taken.
CILIUM_AGENT_NODE_OPTIONS := -DSKIP_DEBUG=1 -DENABLE_IPV4=1 -DENABLE_MASQUERADE_IPV4=1 -DENABLE_NODEPORT=1 \
	-DSERVICE_NO_BACKEND_RESPONSE=1 -DCT_REPORT_FLAGS=0x0007 -DMONITOR_AGGREGATION=0 \
	-DPOLICY_AUDIT_MODE=1 -DPOLICY_VERDICT_NOTIFY=1
CILIUM_AGENT_LXC_OPTIONS := $(CILIUM_AGENT_NODE_OPTIONS) -DENABLE_ROUTING=1
CILIUM_AGENT_HOST_OPTIONS := $(CILIUM_AGENT_LXC_OPTIONS) -DHOST_ENDPOINT=1
CILIUM_AGENT_XDP_OPTIONS := $(CILIUM_AGENT_NODE_OPTIONS) -DCIDR4_HMAP_ELEMS=20971520 -DCIDR4_LMAP_ELEMS=65536 \
	-DCIDR4_FILTER -DCIDR4_LPM_PREFILTER -DCIDR6_FILTER -DCIDR6_LPM_PREFILTER
# Objects the frozen workload leaves unloaded (overlay, sock, wireguard) keep these broader options.
CILIUM_MAX_BASE_OPTIONS := -DSKIP_DEBUG=1 -DENABLE_IPV4=1 \
	-DENABLE_ROUTING=1 -DPOLICY_VERDICT_NOTIFY=1 \
	-DMONITOR_AGGREGATION=3 -DCT_REPORT_FLAGS=0x0002 \
	-DENABLE_HOST_FIREWALL=1 \
	-DENABLE_MASQUERADE_IPV4=1 \
	-DENABLE_NODEPORT=1 -DENABLE_NODEPORT_ACCELERATION=1 \
	-DENABLE_DSR_ICMP_ERRORS=1 -DENABLE_DSR=1 -DENABLE_DSR_BYUSER=1 \
	-DENABLE_HOST_ROUTING=1 -DSERVICE_NO_BACKEND_RESPONSE=1
CILIUM_MAX_LB_OPTIONS := $(CILIUM_MAX_BASE_OPTIONS) \
	-DENCAP_IFINDEX=1 -DTUNNEL_MODE=1 \
	-DLB_SELECTION_PER_SERVICE=1 -DLB_SELECTION_MAGLEV=2 \
	-DLB_SELECTION_RANDOM=1
CILIUM_MAX_OVERLAY_OPTIONS := $(CILIUM_MAX_BASE_OPTIONS) -DENCAP_IFINDEX=1 \
	-DTUNNEL_MODE=1 \
	-DLB_SELECTION_PER_SERVICE=1 -DLB_SELECTION_MAGLEV=2 \
	-DLB_SELECTION_RANDOM=1
CILIUM_MAX_WIREGUARD_OPTIONS := $(CILIUM_MAX_BASE_OPTIONS) \
	-DENCAP_IFINDEX=1 -DTUNNEL_MODE=1 -DENABLE_WIREGUARD=1
CILIUM_SIMPLE_OPTIONS := -DENABLE_IPV4=1

all: vmlinux katran bcc tetragon cilium otel tracee

clean:
	rm -rf "$(OUT)"
	rm -rf "$(CURDIR)/tetragon/bpf/objs" "$(CURDIR)/tetragon/bpf/deps"
	$(MAKE) -C "$(CURDIR)/cilium/bpf" clean >/dev/null
	$(MAKE) -C "$(CURDIR)/otel/support/ebpf" clean >/dev/null

# CO-RE answers, from the sole kernel's BTF, before the compile that uses them.
# A flavor type's members have the target's offsets only in the target's BTF,
# so the C type system alone cannot answer; core-compat.h looks each query up
# in this table and fails the compile on a query it does not hold.
CORE_ANSWERS := $(OUT)/answers
CORE_ANSWERS_PY := $(CURDIR)/core-answers.py
BCC_CORE_CFLAGS := -Ibcc/libbpf-tools -Ibcc/libbpf-tools/$(BPF_ARCH) \
	-Ibcc/src/cc/libbpf/include/uapi -I. $(SYS_INC)
TRACEE_CORE_CFLAGS := -D__TARGET_ARCH_$(BPF_ARCH) -D__BPF_TRACING__ -DCORE -DCOMMON_BUILD -I. \
	-Itracee/pkg/ebpf/c $(SYS_INC)
# Tetragon compiles each object under several variant defines; a query can exist
# in one variant only, so the scan carries every variant the compile uses.
TETRAGON_CORE_CFLAGS := -D__TARGET_ARCH_$(BPF_ARCH) -fms-extensions \
	-DMICRO_NATIVE_TETRAGON \
	-D__LARGE_BPF_PROG -D__V511_BPF_PROG -D__V61_BPF_PROG \
	-D__MULTI_KPROBE -D__RHEL7_BPF_PROG -D__BPF_OVERRIDE_RETURN -I. \
	-Itetragon/bpf -Itetragon/bpf/include -Itetragon/bpf/lib -Itetragon/bpf/libbpf \
	-Itetragon/bpf/process -Itetragon/bpf/errmetrics \
	$(SYS_INC)

$(CORE_ANSWERS)/bcc.h: $(CORE_ANSWERS_PY) $(wildcard bcc/libbpf-tools/*.h) bcc/libbpf-tools/$(BPF_ARCH)/vmlinux.h
	install -d "$(CORE_ANSWERS)"
	python3 "$(CORE_ANSWERS_PY)" --btf "$(VMLINUX_BTF)" --bpftool "$(BPFTOOL)" --clang "$(CLANG)" \
		--cflags "$(BCC_CORE_CFLAGS)" --out "$@" --report "$(CORE_ANSWERS)/bcc.json" bcc/libbpf-tools

$(CORE_ANSWERS)/tracee.h: $(CORE_ANSWERS_PY) $(wildcard tracee/pkg/ebpf/c/*.h) tracee/pkg/ebpf/c/vmlinux.h
	install -d "$(CORE_ANSWERS)"
	python3 "$(CORE_ANSWERS_PY)" --btf "$(VMLINUX_BTF)" --bpftool "$(BPFTOOL)" --clang "$(CLANG)" \
		--cflags "$(TRACEE_CORE_CFLAGS)" --out "$@" --report "$(CORE_ANSWERS)/tracee.json" tracee

$(CORE_ANSWERS)/tetragon.h: $(CORE_ANSWERS_PY) $(wildcard tetragon/bpf/lib/*.h) tetragon/bpf/include/vmlinux_generated_$(BPF_ARCH).h
	install -d "$(CORE_ANSWERS)"
	python3 "$(CORE_ANSWERS_PY)" --btf "$(VMLINUX_BTF)" --bpftool "$(BPFTOOL)" --clang "$(CLANG)" \
		--cflags "$(TETRAGON_CORE_CFLAGS)" --out "$@" --report "$(CORE_ANSWERS)/tetragon.json" \
		tetragon/bpf/process tetragon/bpf/lib tetragon/bpf/errmetrics tetragon/bpf/cgroup

# OTel makes no CO-RE query; an empty table still gates a query it starts to make.
$(CORE_ANSWERS)/otel.h: $(CORE_ANSWERS_PY) $(wildcard otel/support/ebpf/*.h)
	install -d "$(CORE_ANSWERS)"
	python3 "$(CORE_ANSWERS_PY)" --btf "$(VMLINUX_BTF)" --bpftool "$(BPFTOOL)" --clang "$(CLANG)" \
		--cflags "-Iotel/support/ebpf -I. $(SYS_INC)" \
		--out "$@" --report "$(CORE_ANSWERS)/otel.json" otel/support/ebpf

$(CORE_ANSWERS)/cilium.h: $(CORE_ANSWERS_PY) $(wildcard cilium/bpf/lib/*.h)
	install -d "$(CORE_ANSWERS)"
	python3 "$(CORE_ANSWERS_PY)" --btf "$(VMLINUX_BTF)" --bpftool "$(BPFTOOL)" --clang "$(CLANG)" \
		--cflags "-Icilium/bpf -Icilium/bpf/include -Icilium/bpf/include/bpf -Icilium/bpf/include/linux -Icilium/bpf/lib $(SYS_INC)" \
		--out "$@" --report "$(CORE_ANSWERS)/cilium.json" cilium/bpf

CORE_ANSWER_TABLES := $(CORE_ANSWERS)/bcc.h $(CORE_ANSWERS)/tracee.h $(CORE_ANSWERS)/tetragon.h $(CORE_ANSWERS)/otel.h $(CORE_ANSWERS)/cilium.h
# Everything a CO-RE app's native objects need: the compat scaffolding and the
# app's own answer table.
core_flags = -include "$(CURDIR)/core-compat.h" -D__KPROG_CORE_ANSWERS='"$(1)"'

core-answers: $(CORE_ANSWER_TABLES)

vmlinux: $(VMLINUX_H) bcc/libbpf-tools/$(BPF_ARCH)/vmlinux.h tetragon/bpf/include/vmlinux_generated_$(BPF_ARCH).h

$(VMLINUX_H): $(VMLINUX_BTF)
	install -d "$(dir $@)"
	"$(BPFTOOL)" btf dump file "$(VMLINUX_BTF)" format c > "$@"

bcc/libbpf-tools/$(BPF_ARCH)/vmlinux.h: $(VMLINUX_H)
	install -D -m 0644 "$<" "$@"

tetragon/bpf/include/vmlinux_generated_$(BPF_ARCH).h: $(VMLINUX_H)
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

bcc: bcc/libbpf-tools/$(BPF_ARCH)/vmlinux.h
	$(MAKE) -C "$(CURDIR)/bcc/libbpf-tools" CLANG="$(CLANG)" LLVM_STRIP="$(LLVM_STRIP)" \
		OUTPUT="$(OUT)/bcc/output" APPS="$(BCC_TOOLS)" LIBBPF_OBJ= \
		INCLUDES="$(SYS_INC)" \
		$(BCC_OBJS)

tetragon: tetragon/bpf/include/vmlinux_generated_$(BPF_ARCH).h
	install -d "$(OUT)/tetragon"
	$(MAKE) -C "$(CURDIR)/tetragon/bpf" CLANG="$(CLANG)" LLC="$(LLC)" \
		BPF_TARGET_ARCH=$(BPF_ARCH) \
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
	trace_inc="-I$(CURDIR)/tracee/pkg/ebpf/c $(SYS_INC)"; \
	"$(CLANG)" -D__TARGET_ARCH_$(BPF_ARCH) -D__BPF_TRACING__ -DCORE -DCOMMON_BUILD \
		$${trace_inc} -target bpf -O2 -g -mcpu=v2 \
		-c "$(CURDIR)/tracee/pkg/ebpf/c/tracee.bpf.c" \
		-o "$(OUT)/tracee/tracee.bpf.o"; \
	for src in kprobe_check lsm_check; do \
		"$(CLANG)" -D__TARGET_ARCH_$(BPF_ARCH) -D__BPF_TRACING__ \
			$${trace_inc} -target bpf -O2 -g -mcpu=v2 \
			-c "$(CURDIR)/tracee/pkg/ebpf/c/lsmsupport/$${src}.bpf.c" \
			-o "$(OUT)/tracee/lsm_support/$${src}.bpf.o"; \
	done

$(NATIVE_OUT)/katran/%.native.o: katran/katran/lib/bpf/%.c katran-compat.h native-helpers.h Makefile
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) -include "$(CURDIR)/katran-compat.h" -DDEBUG -D__KERNEL__ \
		-I"$(CURDIR)/katran" -I"$(CURDIR)/katran/katran/lib/linux_includes" \
		$(SYS_INC) \
		-o "$@" "$<"

$(NATIVE_OUT)/bcc/%.native.o: bcc/libbpf-tools/%.bpf.c bcc/libbpf-tools/$(BPF_ARCH)/vmlinux.h \
		core-compat.h native-helpers.h $(CORE_ANSWERS)/bcc.h Makefile
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) $(call core_flags,$(CORE_ANSWERS)/bcc.h) \
		-I"$(CURDIR)/bcc/libbpf-tools" -I"$(CURDIR)/bcc/libbpf-tools/$(BPF_ARCH)" \
		-I"$(CURDIR)/bcc/src/cc/libbpf/include/uapi" \
		$(SYS_INC) \
		-o "$@" "$<"

$(NATIVE_OUT)/cilium/bpf_lxc.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_AGENT_LXC_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_overlay.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_MAX_OVERLAY_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_sock.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_MAX_LB_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_host.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_AGENT_HOST_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_wireguard.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_MAX_WIREGUARD_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_xdp.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_AGENT_XDP_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_alignchecker.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_SIMPLE_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_lxc.bpf.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_AGENT_LXC_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_overlay.bpf.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_MAX_OVERLAY_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_sock.bpf.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_MAX_LB_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_host.bpf.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_AGENT_HOST_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_wireguard.bpf.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_MAX_WIREGUARD_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_xdp.bpf.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_AGENT_XDP_OPTIONS)

# The BPF object each Cilium native object is paired with in the manifest (the agent compiles the loaded one
# at run time; this one has the same source and switches).
$(NATIVE_OUT)/cilium/%.bpf.o: cilium/bpf/%.c Makefile
	install -d "$(dir $@)"
	"$(CLANG)" $(CILIUM_NATIVE_OPTIONS) -O2 --target=bpf -mcpu=v3 -g -std=gnu99 -nostdinc -D__NR_CPUS__=128 \
		-Wno-address-of-packed-member -Wno-unknown-warning-option \
		-I"$(CURDIR)/cilium/bpf" -I"$(CURDIR)/cilium/bpf/include" -c -o "$@" "$<"

$(NATIVE_OUT)/cilium/%.native.o: cilium/bpf/%.c core-compat.h native-helpers.h $(CORE_ANSWERS)/cilium.h Makefile
	install -d "$(dir $@)"
	"$(CLANG)" $(CILIUM_NATIVE_OPTIONS) $(NATIVE_CFLAGS) \
		$(call core_flags,$(CORE_ANSWERS)/cilium.h) -DMICRO_NATIVE_CILIUM \
		-I"$(CURDIR)/cilium/bpf" -I"$(CURDIR)/cilium/bpf/include" \
		-I"$(CURDIR)/cilium/bpf/include/bpf" \
		-I"$(CURDIR)/cilium/bpf/include/linux" \
		-I"$(CURDIR)/cilium/bpf/lib" \
		$(SYS_INC) \
		-o "$@" "$<"

$(OTEL_EBPF_DIR)/errors.h: otel/tools/errors-codegen/errors.json otel/tools/errors-codegen/main.go
	$(MAKE) -C "$(CURDIR)/$(OTEL_EBPF_DIR)" errors.h

$(NATIVE_OUT)/otel/%.native.o: $(OTEL_EBPF_DIR)/%.ebpf.c $(OTEL_EBPF_DIR)/errors.h core-compat.h native-helpers.h $(CORE_ANSWERS)/otel.h Makefile
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) $(call core_flags,$(CORE_ANSWERS)/otel.h) \
		-Wno-unused-function -Wno-unused-variable \
		-I"$(CURDIR)/$(OTEL_EBPF_DIR)" \
		-o "$@" "$<"

# clang -r concatenates each unit's .llvmbc into one section, which is two
# modules in a row, not one module: llvm-link can read the section but not the
# program. The runtime context compiler needs a single module, so extract the
# unit bitcode, retain its section entry roots, and embed the linked module.
$(NATIVE_IR_LINK): $(ROOT)/kprog/x86/link_embedded_ir.cpp
	install -d "$(dir $@)"
	clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -Wall -Wextra -Wno-unused-parameter "$<" -o "$@" \
		$$(llvm-config-18 --link-static --ldflags --libs core irreader linker bitwriter support --system-libs)

# The loader runs this compiler at load time; it ships in the stage. It optimizes at -O3, as P does.
PERF_CONTEXT_LTO ?= $(NATIVE_STAGE_ROOT)/kprog-perf-context-lto
$(PERF_CONTEXT_LTO): $(ROOT)/kprog/x86/perf_context_lto.cpp $(ROOT)/kprog/libnativeloader/src/native_loader_lto.hpp \
		$(ROOT)/kprog/x86/bpf_function_bodies.hpp $(ROOT)/kprog/x86/runtime_bpf_callee.hpp $(ROOT)/vendor/bpf/native-lpm.h
	install -d "$(dir $@)"
	clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -fexceptions -Wall -Wextra -Wno-unused-parameter \
		-I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include "$<" -o "$@" \
		$$(llvm-config-18 --link-static --ldflags --libs core irreader analysis support passes native object linker --system-libs) \
		$(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz

$(OTEL_NATIVE_OBJECT): $(OTEL_NATIVE_UNIT_OBJS) $(NATIVE_IR_LINK)
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_TARGET_FLAGS) -r -o "$@" $(OTEL_NATIVE_UNIT_OBJS)
	install -d "$(OTEL_NATIVE_IR_DIR)"
	rm -f "$(OTEL_NATIVE_IR_DIR)"/*.bc
	for o in $(OTEL_NATIVE_UNIT_OBJS); do \
		"$(LLVM_OBJCOPY)" --dump-section .llvmbc="$(OTEL_NATIVE_IR_DIR)/$$(basename $$o .native.o).bc" "$$o"; \
	done
	"$(NATIVE_IR_LINK)" $(OTEL_NATIVE_IR_DIR)/*.bc -o "$(OTEL_NATIVE_IR)"
	"$(LLVM_OBJCOPY)" --remove-section .llvmbc --remove-section .llvmcmd "$@"
	"$(LLVM_OBJCOPY)" --add-section .llvmbc="$(OTEL_NATIVE_IR)" "$@"

$(TRACEE_NATIVE_OBJECT): tracee/pkg/ebpf/c/tracee.bpf.c tracee/pkg/ebpf/c/vmlinux.h \
		core-compat.h native-helpers.h $(CORE_ANSWERS)/tracee.h Makefile
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) $(call core_flags,$(CORE_ANSWERS)/tracee.h) \
		-D__TARGET_ARCH_$(BPF_ARCH) -D__BPF_TRACING__ -DCORE -DCOMMON_BUILD \
		-I"$(CURDIR)/tracee/pkg/ebpf/c" \
		$(SYS_INC) \
		-o "$@" "$<"

$(NATIVE_OUT)/tracee/lsm_support/%.native.o: tracee/pkg/ebpf/c/lsmsupport/%.bpf.c tracee/pkg/ebpf/c/vmlinux.h \
		core-compat.h native-helpers.h $(CORE_ANSWERS)/tracee.h Makefile
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) $(call core_flags,$(CORE_ANSWERS)/tracee.h) \
		-D__TARGET_ARCH_$(BPF_ARCH) -D__BPF_TRACING__ \
		-I"$(CURDIR)/tracee/pkg/ebpf/c/lsmsupport" \
		-I"$(CURDIR)/tracee/pkg/ebpf/c" \
		$(SYS_INC) \
		-o "$@" "$<"

$(NATIVE_LINK):
	cargo build --release --manifest-path "$(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml"

native-katran: $(KATRAN_NATIVE_OBJS)
	install -d "$(NATIVE_OUT)/katran"
	install -d "$(KATRAN_NATIVE_STAGE_OUT)"
	install -m 0644 $(KATRAN_NATIVE_OBJS) "$(KATRAN_NATIVE_STAGE_OUT)"
	install -m 0644 $(foreach obj,balancer healthchecking_ipip xdp_root,$(VENDOR)/build/$(BPF_ARCH)/katran/bpf/$(obj).bpf.o) "$(KATRAN_NATIVE_STAGE_OUT)"
	python3 "$(CURDIR)/write_native_manifest.py" --app katran --llvm-nm "$(LLVM_NM)" --skip-prefix jhash \
		--output "$(NATIVE_OUT)/katran/manifest.json" \
		--object "$(NATIVE_OUT)/katran/balancer.native.o" \
		--object "$(NATIVE_OUT)/katran/healthchecking_ipip.native.o" \
		--object "$(NATIVE_OUT)/katran/xdp_root.native.o"
	python3 "$(CURDIR)/write_native_manifest.py" --app katran --llvm-nm "$(LLVM_NM)" --skip-prefix jhash \
		--output "$(KATRAN_NATIVE_STAGE_OUT)/manifest.json" \
		--object "$(KATRAN_NATIVE_STAGE_OUT)/balancer.native.o,source=$(KATRAN_NATIVE_STAGE_OUT)/balancer.bpf.o" \
		--object "$(KATRAN_NATIVE_STAGE_OUT)/healthchecking_ipip.native.o,source=$(KATRAN_NATIVE_STAGE_OUT)/healthchecking_ipip.bpf.o" \
		--object "$(KATRAN_NATIVE_STAGE_OUT)/xdp_root.native.o,source=$(KATRAN_NATIVE_STAGE_OUT)/xdp_root.bpf.o"

native-bcc: bcc/libbpf-tools/$(BPF_ARCH)/vmlinux.h $(BCC_NATIVE_OBJS)
	install -d "$(NATIVE_OUT)/bcc"
	install -d "$(BCC_NATIVE_STAGE_OUT)"
	install -m 0644 $(BCC_NATIVE_OBJS) "$(BCC_NATIVE_STAGE_OUT)"
	install -m 0644 $(foreach tool,$(BCC_TOOLS),$(VENDOR)/build/.bcc-libbpf/$(BPF_ARCH)/output/$(tool).bpf.o) "$(BCC_NATIVE_STAGE_OUT)"
	python3 "$(CURDIR)/write_native_manifest.py" --app bcc --llvm-nm "$(LLVM_NM)" \
		--output "$(NATIVE_OUT)/bcc/manifest.json" \
		$(foreach obj,$(BCC_NATIVE_OBJS),--object "$(obj)")
	python3 "$(CURDIR)/write_native_manifest.py" --app bcc --llvm-nm "$(LLVM_NM)" \
		--output "$(BCC_NATIVE_STAGE_OUT)/manifest.json" \
		$(foreach tool,$(BCC_TOOLS),--object "$(BCC_NATIVE_STAGE_OUT)/$(tool).native.o,source=$(BCC_NATIVE_STAGE_OUT)/$(tool).bpf.o")

CILIUM_SOURCE_OBJS := $(foreach obj,bpf_lxc bpf_overlay bpf_sock bpf_host bpf_wireguard bpf_xdp,$(NATIVE_OUT)/cilium/$(obj).bpf.o)
native-cilium: $(CILIUM_NATIVE_OBJS) $(CILIUM_SOURCE_OBJS)
	install -d "$(CILIUM_NATIVE_STAGE_OUT)"
	rm -f "$(CILIUM_NATIVE_STAGE_OUT)"/*.native.o
	install -m 0644 $(CILIUM_NATIVE_OBJS) "$(CILIUM_NATIVE_STAGE_OUT)"
	install -m 0644 $(CILIUM_SOURCE_OBJS) "$(CILIUM_NATIVE_STAGE_OUT)"
	python3 "$(CURDIR)/write_native_manifest.py" --app cilium --llvm-nm "$(LLVM_NM)" \
		--output "$(NATIVE_OUT)/cilium/manifest.json" \
		--object "$(NATIVE_OUT)/cilium/bpf_lxc.native.o" \
		--object "$(NATIVE_OUT)/cilium/bpf_overlay.native.o" \
		--object "$(NATIVE_OUT)/cilium/bpf_sock.native.o" \
		--object "$(NATIVE_OUT)/cilium/bpf_host.native.o" \
		--object "$(NATIVE_OUT)/cilium/bpf_wireguard.native.o" \
		--object "$(NATIVE_OUT)/cilium/bpf_xdp.native.o"
	python3 "$(CURDIR)/write_native_manifest.py" --app cilium --llvm-nm "$(LLVM_NM)" \
		--output "$(CILIUM_NATIVE_STAGE_OUT)/manifest.json" \
		--object "$(CILIUM_NATIVE_STAGE_OUT)/bpf_lxc.native.o,source=$(CILIUM_NATIVE_STAGE_OUT)/bpf_lxc.bpf.o" \
		--object "$(CILIUM_NATIVE_STAGE_OUT)/bpf_overlay.native.o,source=$(CILIUM_NATIVE_STAGE_OUT)/bpf_overlay.bpf.o" \
		--object "$(CILIUM_NATIVE_STAGE_OUT)/bpf_sock.native.o,source=$(CILIUM_NATIVE_STAGE_OUT)/bpf_sock.bpf.o" \
		--object "$(CILIUM_NATIVE_STAGE_OUT)/bpf_host.native.o,source=$(CILIUM_NATIVE_STAGE_OUT)/bpf_host.bpf.o" \
		--object "$(CILIUM_NATIVE_STAGE_OUT)/bpf_wireguard.native.o,source=$(CILIUM_NATIVE_STAGE_OUT)/bpf_wireguard.bpf.o" \
		--object "$(CILIUM_NATIVE_STAGE_OUT)/bpf_xdp.native.o,source=$(CILIUM_NATIVE_STAGE_OUT)/bpf_xdp.bpf.o"

native-otel: $(OTEL_NATIVE_OBJECT) $(OTEL_SOURCE_BPF_OBJECT)
	install -d "$(OTEL_NATIVE_STAGE_OUT)"
	install -m 0644 "$(OTEL_NATIVE_OBJECT)" "$(OTEL_NATIVE_STAGE_OUT)/otelcol-ebpf-profiler.native.o"
	install -m 0644 "$(OTEL_SOURCE_BPF_OBJECT)" "$(OTEL_NATIVE_STAGE_OUT)/$(notdir $(OTEL_SOURCE_BPF_OBJECT))"
	python3 "$(CURDIR)/write_native_manifest.py" --app otelcol-ebpf-profiler --llvm-nm "$(LLVM_NM)" \
		--output "$(NATIVE_OUT)/otel/manifest.json" \
		--object "$(OTEL_NATIVE_OBJECT)"
	python3 "$(CURDIR)/write_native_manifest.py" --app otelcol-ebpf-profiler --llvm-nm "$(LLVM_NM)" \
		--output "$(OTEL_NATIVE_STAGE_OUT)/manifest.json" \
		--object "$(OTEL_NATIVE_STAGE_OUT)/otelcol-ebpf-profiler.native.o,source=$(OTEL_NATIVE_STAGE_OUT)/$(notdir $(OTEL_SOURCE_BPF_OBJECT))"

native-tracee: $(TRACEE_NATIVE_OBJS)
	install -d "$(TRACEE_NATIVE_STAGE_OUT)"
	rm -f "$(TRACEE_NATIVE_STAGE_OUT)"/*.native.o
	for obj in $(TRACEE_NATIVE_OBJS); do \
		install -m 0644 "$${obj}" "$(TRACEE_NATIVE_STAGE_OUT)/$$(basename "$${obj}")"; \
	done
	python3 "$(CURDIR)/write_native_manifest.py" --app tracee --llvm-nm "$(LLVM_NM)" \
		--output "$(NATIVE_OUT)/tracee/manifest.json" \
		--object "$(TRACEE_NATIVE_OBJECT)" \
		$(foreach src,$(TRACEE_LSM_SUPPORT_SRCS),--object "$(NATIVE_OUT)/tracee/lsm_support/$(src).native.o")
	install -m 0644 "$(VENDOR)/build/.tracee-build/$(BPF_ARCH)/dist/tracee.bpf.o" "$(TRACEE_NATIVE_STAGE_OUT)/tracee.bpf.o"
	for src in $(TRACEE_LSM_SUPPORT_SRCS); do install -m 0644 "$(VENDOR)/build/.tracee-build/$(BPF_ARCH)/dist/lsm_support/$${src}.bpf.o" "$(TRACEE_NATIVE_STAGE_OUT)/$${src}.bpf.o"; done
	python3 "$(CURDIR)/write_native_manifest.py" --app tracee --llvm-nm "$(LLVM_NM)" \
		--output "$(TRACEE_NATIVE_STAGE_OUT)/manifest.json" \
		--object "$(TRACEE_NATIVE_STAGE_OUT)/tracee.native.o,source=$(TRACEE_NATIVE_STAGE_OUT)/tracee.bpf.o" \
		$(foreach src,$(TRACEE_LSM_SUPPORT_SRCS),--object "$(TRACEE_NATIVE_STAGE_OUT)/$(src).native.o,source=$(TRACEE_NATIVE_STAGE_OUT)/$(src).bpf.o")

native-tetragon: tetragon/bpf/include/vmlinux_generated_$(BPF_ARCH).h core-compat.h native-helpers.h $(CORE_ANSWERS)/tetragon.h $(NATIVE_LINK)
	install -d "$(NATIVE_OUT)/tetragon"
	install -d "$(TETRAGON_NATIVE_STAGE_OUT)"
	rm -f "$(NATIVE_OUT)/tetragon"/*.native.o "$(NATIVE_OUT)/tetragon"/*.proof.o "$(NATIVE_OUT)/tetragon"/*.proof.ok
	rm -f "$(TETRAGON_NATIVE_STAGE_OUT)"/*.native.o
	native_out="$(NATIVE_OUT)/tetragon"; \
	stage_out="$(TETRAGON_NATIVE_STAGE_OUT)"; \
	common_flags=($(NATIVE_CFLAGS) -fms-extensions -DMICRO_NATIVE_TETRAGON \
		$(call core_flags,$(CORE_ANSWERS)/tetragon.h) \
		-D__TARGET_ARCH_$(BPF_ARCH) \
		-I"$(CURDIR)/tetragon/bpf" \
		-I"$(CURDIR)/tetragon/bpf/include" \
		-I"$(CURDIR)/tetragon/bpf/lib" \
		-I"$(CURDIR)/tetragon/bpf/libbpf" \
		-I"$(CURDIR)/tetragon/bpf/process" \
		-I"$(CURDIR)/tetragon/bpf/errmetrics" \
		$(SYS_INC)); \
	compile_native() { \
		local name="$$1"; \
		local src="$$2"; \
		local extra="$${3:-}"; \
		"$(CLANG)" "$${common_flags[@]}" $${extra} -o "$${native_out}/$${name}.native.o" "$${src}"; \
	}; \
	for name in bpf_loader bpf_cgroup bpf_prog_iter \
		bpf_execve_event bpf_fork bpf_exit bpf_execve_bprm_commit_creds \
		bpf_generic_kprobe bpf_generic_retkprobe bpf_generic_tracepoint \
		bpf_generic_uprobe bpf_generic_retuprobe bpf_generic_rawtp \
		bpf_generic_usdt bpf_generic_fentry bpf_generic_fexit \
		bpf_execve_map_update; do \
		compile_native "$${name}" "$(CURDIR)/tetragon/bpf/process/$${name}.c" ""; \
	done; \
	compile_native bpf_generic_lsm_core "$(CURDIR)/tetragon/bpf/process/bpf_generic_lsm_core.c" "-D__LARGE_BPF_PROG"; \
	compile_native bpf_generic_lsm_output "$(CURDIR)/tetragon/bpf/process/bpf_generic_lsm_output.c" "-D__LARGE_BPF_PROG"; \
	compile_native bpf_enforcer "$(CURDIR)/tetragon/bpf/process/bpf_enforcer.c" "-D__BPF_OVERRIDE_RETURN"; \
	compile_native bpf_multi_enforcer "$(CURDIR)/tetragon/bpf/process/bpf_enforcer.c" "-D__BPF_OVERRIDE_RETURN -D__MULTI_KPROBE"; \
	compile_native bpf_fmodret_enforcer "$(CURDIR)/tetragon/bpf/process/bpf_enforcer.c" ""; \
	for name in bpf_execve_event bpf_exit bpf_fork; do \
		compile_native "$${name}_v310" "$(CURDIR)/tetragon/bpf/process/$${name}.c" "-D__RHEL7_BPF_PROG"; \
	done; \
	for name in bpf_execve_event; do \
		compile_native "$${name}_v53" "$(CURDIR)/tetragon/bpf/process/$${name}.c" "-D__LARGE_BPF_PROG"; \
	done; \
	for name in bpf_generic_kprobe bpf_generic_retkprobe bpf_generic_tracepoint \
		bpf_generic_uprobe bpf_generic_retuprobe bpf_generic_rawtp \
		bpf_generic_usdt bpf_generic_fentry bpf_generic_fexit \
		bpf_execve_map_update; do \
		compile_native "$${name}_v53" "$(CURDIR)/tetragon/bpf/process/$${name}.c" "-D__LARGE_BPF_PROG"; \
	done; \
	for pair in \
		"bpf_multi_kprobe_v53 bpf_generic_kprobe.c" \
		"bpf_multi_retkprobe_v53 bpf_generic_retkprobe.c"; do \
		set -- $${pair}; \
		compile_native "$$1" "$(CURDIR)/tetragon/bpf/process/$$2" "-D__LARGE_BPF_PROG -D__MULTI_KPROBE"; \
	done; \
	for name in bpf_execve_event bpf_exit bpf_fork bpf_loader \
		bpf_execve_map_update; do \
		compile_native "$${name}_v511" "$(CURDIR)/tetragon/bpf/process/$${name}.c" "-D__LARGE_BPF_PROG -D__V511_BPF_PROG"; \
	done; \
	for name in bpf_generic_kprobe bpf_generic_retkprobe bpf_generic_tracepoint \
		bpf_generic_uprobe bpf_generic_retuprobe bpf_generic_rawtp \
		bpf_generic_usdt bpf_generic_fentry bpf_generic_fexit \
		bpf_generic_lsm_core bpf_generic_lsm_output \
		bpf_generic_lsm_ima_file bpf_generic_lsm_ima_bprm; do \
		compile_native "$${name}_v511" "$(CURDIR)/tetragon/bpf/process/$${name}.c" "-D__LARGE_BPF_PROG -D__V511_BPF_PROG"; \
	done; \
	for pair in \
		"bpf_multi_kprobe_v511 bpf_generic_kprobe.c" \
		"bpf_multi_retkprobe_v511 bpf_generic_retkprobe.c" \
		"bpf_multi_uprobe_v511 bpf_generic_uprobe.c" \
		"bpf_multi_retuprobe_v511 bpf_generic_retuprobe.c" \
		"bpf_multi_usdt_v511 bpf_generic_usdt.c"; do \
		set -- $${pair}; \
		compile_native "$$1" "$(CURDIR)/tetragon/bpf/process/$$2" "-D__LARGE_BPF_PROG -D__V511_BPF_PROG -D__MULTI_KPROBE"; \
	done; \
	for name in bpf_execve_event bpf_execve_map_update \
		bpf_generic_kprobe bpf_generic_retkprobe bpf_generic_tracepoint \
		bpf_generic_uprobe bpf_generic_retuprobe bpf_generic_rawtp \
		bpf_generic_usdt bpf_generic_fentry bpf_generic_fexit \
		bpf_generic_lsm_core bpf_generic_lsm_output \
		bpf_generic_lsm_ima_file bpf_generic_lsm_ima_bprm; do \
		compile_native "$${name}_v61" "$(CURDIR)/tetragon/bpf/process/$${name}.c" "-D__LARGE_BPF_PROG -D__V511_BPF_PROG -D__V61_BPF_PROG"; \
	done; \
	for pair in \
		"bpf_multi_kprobe_v61 bpf_generic_kprobe.c" \
		"bpf_multi_retkprobe_v61 bpf_generic_retkprobe.c" \
		"bpf_multi_uprobe_v61 bpf_generic_uprobe.c" \
		"bpf_multi_retuprobe_v61 bpf_generic_retuprobe.c" \
		"bpf_multi_usdt_v61 bpf_generic_usdt.c"; do \
		set -- $${pair}; \
		compile_native "$$1" "$(CURDIR)/tetragon/bpf/process/$$2" "-D__LARGE_BPF_PROG -D__V511_BPF_PROG -D__V61_BPF_PROG -D__MULTI_KPROBE"; \
	done; \
	for name in bpf_cgroup_mkdir bpf_cgroup_rmdir bpf_cgroup_release bpf_cgtracker; do \
		compile_native "$${name}" "$(CURDIR)/tetragon/bpf/cgroup/$${name}.c" ""; \
	done; \
	for name in bpf_cgroup_mkdir bpf_cgroup_rmdir bpf_cgroup_release; do \
		compile_native "$${name}_v511" "$(CURDIR)/tetragon/bpf/cgroup/$${name}.c" "-D__LARGE_BPF_PROG -D__V511_BPF_PROG"; \
	done; \
		for obj in "$${native_out}"/*.native.o; do \
			base="$$(basename "$${obj}" .native.o)"; \
			install -m 0644 "$${obj}" "$${stage_out}/$${base}.native.o"; \
		done; \
		native_args=(); \
		stage_args=(); \
		for obj in "$${native_out}"/*.native.o; do native_args+=(--object "$${obj}"); done; \
		for obj in "$${stage_out}"/*.native.o; do b="$$(basename "$${obj}" .native.o)"; src="$(VENDOR)/build/$(BPF_ARCH)/tetragon/$${b}.o"; if [ -f "$${src}" ]; then install -m 0644 "$${src}" "$${stage_out}/$${b}.o"; stage_args+=(--object "$${obj},source=$${stage_out}/$${b}.o"); fi; done; \
		python3 "$(CURDIR)/write_native_manifest.py" --app tetragon --llvm-nm "$(LLVM_NM)" \
			--output "$${native_out}/manifest.json" "$${native_args[@]}"; \
		python3 "$(CURDIR)/write_native_manifest.py" --app tetragon --llvm-nm "$(LLVM_NM)" \
			--output "$${stage_out}/manifest.json" "$${stage_args[@]}"

native-artifacts: native-katran native-bcc native-otel native-cilium native-tracee native-tetragon $(PERF_CONTEXT_LTO)
