SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

.PHONY: all clean vmlinux katran bcc tetragon cilium otel tracee native-katran native-bcc native-otel native-cilium native-tracee native-tetragon native-artifacts

ROOT := $(abspath ../..)
VENDOR := $(ROOT)/vendor
BUILD := $(VENDOR)/build/native-bpf
KERNEL_RELEASE ?= $(shell uname -r)
ARCH := x86
GOARCH := $(if $(filter arm64 aarch64,$(ARCH)),arm64,amd64)
# The kernel architecture name the apps and their headers use, and the system headers: the host
# multiarch directory on x86, the cross sysroot clang finds for --target=aarch64-linux-gnu on arm64.
BPF_ARCH := $(if $(filter arm64 aarch64,$(ARCH)),arm64,x86)
BPF_ARCH_UC := $(if $(filter arm64 aarch64,$(ARCH)),ARM64,X86)
SYS_INC := $(if $(filter arm64 aarch64,$(ARCH)),-idirafter /usr/include,-I/usr/include -I/usr/include/x86_64-linux-gnu)

CLANG ?= clang-18
LLC ?= llc-18
BPF_LINK ?= llvm-link-18
LLVM_NM ?= llvm-nm-18
LLVM_STRIP ?= llvm-strip-18
LLVM_OBJCOPY ?= llvm-objcopy-18
BPFTOOL ?= $(VENDOR)/build/x86/bpftool/bin/bpftool
VMLINUX_BTF ?= /sys/kernel/btf/vmlinux
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
# arm64: each staged object gets a single executable section (merge-text.ld), so native-link
# resolves a program's calls into the object's other functions by address; x86 keeps its sections.
native_merge_text = $(if $(filter arm64 aarch64,$(ARCH)),for o in "$(1)"/*.native.o; do aarch64-linux-gnu-ld -r -T "$(CURDIR)/merge-text.ld" "$$o" -o "$$o.merged" && mv "$$o.merged" "$$o"; done,true)
KATRAN_NATIVE_STAGE_OUT := $(NATIVE_STAGE_ROOT)/katran
BCC_NATIVE_STAGE_OUT := $(NATIVE_STAGE_ROOT)/bcc
OTEL_NATIVE_STAGE_OUT := $(NATIVE_STAGE_ROOT)/otelcol-ebpf-profiler
CILIUM_NATIVE_STAGE_OUT := $(NATIVE_STAGE_ROOT)/cilium
TRACEE_NATIVE_STAGE_OUT := $(NATIVE_STAGE_ROOT)/tracee
OTEL_NATIVE_IR_DIR := $(NATIVE_OUT)/otel/ir
OTEL_NATIVE_IR := $(OTEL_NATIVE_IR_DIR)/otelcol-ebpf-profiler.llvmbc
TETRAGON_NATIVE_STAGE_OUT := $(NATIVE_STAGE_ROOT)/tetragon
TRACEE_LSM_SUPPORT_SRCS := kprobe_check lsm_check
NATIVE_TARGET_FLAGS := $(if $(filter arm64 aarch64,$(ARCH)),--target=aarch64-linux-gnu)
# Use branches for selects after source loops have been unrolled, too.
NATIVE_ARCH_CFLAGS := $(if $(filter x86,$(ARCH)),-march=native -mno-red-zone -mgeneral-regs-only -mllvm -x86-cmov-converter-force-all) \
	$(if $(filter arm64 aarch64,$(ARCH)),-mtune=neoverse-n1 -mgeneral-regs-only -mno-outline-atomics -ffixed-x26)
NATIVE_CFLAGS := $(NATIVE_TARGET_FLAGS) -O3 -g -fPIC -c -DMICRO_NATIVE \
	-fomit-frame-pointer $(NATIVE_ARCH_CFLAGS) -fno-stack-protector \
	-fno-asynchronous-unwind-tables -fno-unwind-tables -fno-jump-tables \
	-fno-optimize-sibling-calls \
	-Xclang -fembed-bitcode=all \
	-Wno-unknown-attributes -mllvm -switch-to-lookup=false
KATRAN_NATIVE_CFLAGS := $(NATIVE_TARGET_FLAGS) -O3 -g -fPIC -c -DMICRO_NATIVE \
	-fomit-frame-pointer $(NATIVE_ARCH_CFLAGS) -fno-stack-protector \
	-fno-asynchronous-unwind-tables -fno-unwind-tables -fno-jump-tables \
	-fno-optimize-sibling-calls \
	-Xclang -fembed-bitcode=all \
	-Wno-unknown-attributes -Wno-compare-distinct-pointer-types \
	-mllvm -switch-to-lookup=false
KATRAN_NATIVE_OBJS := $(patsubst %,$(NATIVE_OUT)/katran/%.native.o,$(KATRAN_OBJS))
BCC_NATIVE_OBJS := $(patsubst %,$(NATIVE_OUT)/bcc/%.native.o,$(BCC_TOOLS))
CILIUM_NATIVE_PLACEHOLDER_OBJS := $(NATIVE_OUT)/cilium/cilium_placeholders.native.o
CILIUM_NATIVE_OBJS := $(patsubst %.o,$(NATIVE_OUT)/cilium/%.native.o,$(CILIUM_OBJS)) $(CILIUM_NATIVE_PLACEHOLDER_OBJS)
OTEL_EBPF_DIR := otel/support/ebpf
OTEL_NATIVE_UNIT_SRCS := $(wildcard $(OTEL_EBPF_DIR)/*.ebpf.c)
OTEL_NATIVE_UNIT_OBJS := $(patsubst $(OTEL_EBPF_DIR)/%.ebpf.c,$(NATIVE_OUT)/otel/%.native.o,$(OTEL_NATIVE_UNIT_SRCS))
OTEL_NATIVE_OBJECT := $(NATIVE_OUT)/otel/otelcol-ebpf-profiler.native.o
TRACEE_NATIVE_OBJECT := $(NATIVE_OUT)/tracee/tracee.native.o
TRACEE_LSM_SUPPORT_NATIVE_OBJS := $(patsubst %,$(NATIVE_OUT)/tracee/lsm_support/%.native.o,$(TRACEE_LSM_SUPPORT_SRCS))
TRACEE_NATIVE_OBJS := $(TRACEE_NATIVE_OBJECT) $(TRACEE_LSM_SUPPORT_NATIVE_OBJS)

# The switches cilium-agent itself turns on for the frozen workload, read from the node_config.h, ep_config.h,
# netdev_config.h and filter_config.h it generates (/workspaces/kprog-raw/perf/20261113-cilium-context-runtime-retry2/
# baseline-state/state; again /workspaces/kprog-raw/perf/20261113-cilium-live-config/baseline-state/state): IPv4 with
# masquerade and nodeport, every packet traced (ep_config.h #undef MONITOR_AGGREGATION, so lib/trace.h takes
# TRACE_AGGREGATE_NONE = 0), policy audit and verdict notifications. The agent runs with --policy-audit-mode=true,
# --enable-monitor=false, --enable-hubble=false (runner/libs/app_runners/cilium.py). Both arms then do the same
# per-packet work. First added in 3ff2ac946 (11-17); the 5/29 restore 3aa496416 (11-21) dropped it.
CILIUM_AGENT_NODE_OPTIONS := -DSKIP_DEBUG=1 -DENABLE_IPV4=1 -DENABLE_MASQUERADE_IPV4=1 -DENABLE_NODEPORT=1 \
	-DSERVICE_NO_BACKEND_RESPONSE=1 -DCT_REPORT_FLAGS=0x0007 -DMONITOR_AGGREGATION=0 \
	-DPOLICY_AUDIT_MODE=1 -DPOLICY_VERDICT_NOTIFY=1
CILIUM_AGENT_LXC_OPTIONS := $(CILIUM_AGENT_NODE_OPTIONS) -DENABLE_ROUTING=1
CILIUM_AGENT_HOST_OPTIONS := $(CILIUM_AGENT_LXC_OPTIONS) -DHOST_ENDPOINT=1
CILIUM_AGENT_XDP_OPTIONS := $(CILIUM_AGENT_NODE_OPTIONS) -DCIDR4_HMAP_ELEMS=20971520 -DCIDR4_LMAP_ELEMS=65536 \
	-DCIDR4_FILTER -DCIDR4_LPM_PREFILTER -DCIDR6_FILTER -DCIDR6_LPM_PREFILTER
# Objects the frozen workload leaves unloaded (overlay, sock, wireguard) keep these broader options.
CILIUM_MAX_BASE_OPTIONS := -DSKIP_DEBUG=1 -DENABLE_IPV4=1 \
	-DPOLICY_AUDIT_MODE=1 \
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
CILIUM_MAX_HOST_OPTIONS := $(filter-out -DENABLE_HOST_FIREWALL=1,$(CILIUM_MAX_BASE_OPTIONS)) -DENCAP_IFINDEX=1
CILIUM_MAX_WIREGUARD_OPTIONS := $(CILIUM_MAX_BASE_OPTIONS) \
	-DENCAP_IFINDEX=1 -DTUNNEL_MODE=1 -DENABLE_WIREGUARD=1
CILIUM_XDP_BASE_OPTIONS := $(filter-out -DENABLE_NODEPORT_ACCELERATION=1,$(CILIUM_MAX_BASE_OPTIONS))
CILIUM_MAX_XDP_OPTIONS := $(CILIUM_XDP_BASE_OPTIONS) \
	-DLB_SELECTION_PER_SERVICE=1 -DLB_SELECTION_MAGLEV=2 \
	-DLB_SELECTION_RANDOM=1
CILIUM_MAX_LXC_OPTIONS := $(CILIUM_MAX_BASE_OPTIONS) -DENCAP_IFINDEX=1
CILIUM_SIMPLE_OPTIONS := -DENABLE_IPV4=1

all: vmlinux katran bcc tetragon cilium otel tracee

clean:
	rm -rf "$(OUT)"
	rm -rf "$(CURDIR)/tetragon/bpf/objs" "$(CURDIR)/tetragon/bpf/deps"
	$(MAKE) -C "$(CURDIR)/cilium/bpf" clean >/dev/null
	$(MAKE) -C "$(CURDIR)/otel/support/ebpf" clean >/dev/null

vmlinux: $(VMLINUX_H) bcc/libbpf-tools/$(BPF_ARCH)/vmlinux.h tetragon/bpf/include/vmlinux_generated_$(BPF_ARCH).h

$(VMLINUX_H): $(VMLINUX_BTF)
	install -d "$(dir $@)"
	"$(BPFTOOL)" btf dump file "$(VMLINUX_BTF)" format c > "$@"

bcc/libbpf-tools/$(BPF_ARCH)/vmlinux.h: $(VMLINUX_H)
	install -D -m 0644 "$<" "$@"

tetragon/bpf/include/vmlinux_generated_$(BPF_ARCH).h: $(VMLINUX_H)
	install -d "$(dir $@)"
	sed 's/__VMLINUX_H__/__VMLINUX_GENERATED_$(BPF_ARCH_UC)_H__/g' "$<" > "$@"

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

$(NATIVE_OUT)/katran/%.native.o: katran/katran/lib/bpf/%.c katran-helpers.h native-helpers.h
	install -d "$(dir $@)"
	"$(CLANG)" $(KATRAN_NATIVE_CFLAGS) -include "$(CURDIR)/katran-helpers.h" \
		-I"$(CURDIR)/katran" -I"$(CURDIR)/katran/katran/lib/linux_includes" \
		$(SYS_INC) \
		-o "$@" "$<"

$(NATIVE_OUT)/bcc/%.native.o: bcc/libbpf-tools/%.bpf.c bcc/libbpf-tools/$(BPF_ARCH)/vmlinux.h native_compat.h native-helpers.h
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) -include "$(CURDIR)/native_compat.h" \
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

$(NATIVE_OUT)/cilium/%.native.o: cilium/bpf/%.c native_compat.h native-helpers.h
	install -d "$(dir $@)"
	"$(CLANG)" $(CILIUM_NATIVE_OPTIONS) $(NATIVE_CFLAGS) \
		-include "$(CURDIR)/native_compat.h" \
		-I"$(CURDIR)/cilium/bpf" -I"$(CURDIR)/cilium/bpf/include" \
		-I"$(CURDIR)/cilium/bpf/include/bpf" \
		-I"$(CURDIR)/cilium/bpf/include/linux" \
		-I"$(CURDIR)/cilium/bpf/lib" \
		$(SYS_INC) \
		-o "$@" "$<"

$(NATIVE_OUT)/cilium/cilium_placeholders.native.o: cilium_placeholders.c native_compat.h native-helpers.h
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) \
		-include "$(CURDIR)/native_compat.h" \
		$(SYS_INC) \
		-o "$@" "$<"

$(OTEL_EBPF_DIR)/errors.h: otel/tools/errors-codegen/errors.json otel/tools/errors-codegen/main.go
	$(MAKE) -C "$(CURDIR)/$(OTEL_EBPF_DIR)" errors.h

$(NATIVE_OUT)/otel/%.native.o: $(OTEL_EBPF_DIR)/%.ebpf.c $(OTEL_EBPF_DIR)/errors.h $(OTEL_EBPF_DIR)/bpfdefs.h native-helpers.h
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) \
		-Wno-unused-function -Wno-unused-variable \
		-I"$(CURDIR)/$(OTEL_EBPF_DIR)" \
		-o "$@" "$<"

# clang -r concatenates each unit's .llvmbc into one section, which is two
# modules in a row, not one module: llvm-link can read the section but not the
# program. The runtime context compiler needs a single module, so extract the
# unit bitcode, retain its section entry roots, and embed the linked module.
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

$(TRACEE_NATIVE_OBJECT): tracee/pkg/ebpf/c/tracee.bpf.c tracee/pkg/ebpf/c/vmlinux.h native_compat.h native-helpers.h
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) \
		-include "$(CURDIR)/native_compat.h" \
		-D__TARGET_ARCH_$(BPF_ARCH) -D__BPF_TRACING__ -DCORE -DCOMMON_BUILD \
		-I"$(CURDIR)/tracee/pkg/ebpf/c" \
		$(SYS_INC) \
		-o "$@" "$<"

$(NATIVE_OUT)/tracee/lsm_support/%.native.o: tracee/pkg/ebpf/c/lsmsupport/%.bpf.c tracee/pkg/ebpf/c/vmlinux.h native_compat.h native-helpers.h
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) \
		-include "$(CURDIR)/native_compat.h" \
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
	python3 "$(CURDIR)/write_native_manifest.py" --app katran --llvm-nm "$(LLVM_NM)" --skip-prefix jhash \
		--output "$(NATIVE_OUT)/katran/manifest.json" \
		--object "$(NATIVE_OUT)/katran/balancer.native.o" \
		--object "$(NATIVE_OUT)/katran/healthchecking_ipip.native.o" \
		--object "$(NATIVE_OUT)/katran/xdp_root.native.o"
	$(call native_merge_text,$(KATRAN_NATIVE_STAGE_OUT))
	python3 "$(CURDIR)/write_native_manifest.py" --app katran --llvm-nm "$(LLVM_NM)" --skip-prefix jhash \
		--output "$(KATRAN_NATIVE_STAGE_OUT)/manifest.json" \
		--object "$(KATRAN_NATIVE_STAGE_OUT)/balancer.native.o" \
		--object "$(KATRAN_NATIVE_STAGE_OUT)/healthchecking_ipip.native.o" \
		--object "$(KATRAN_NATIVE_STAGE_OUT)/xdp_root.native.o"

native-bcc: bcc/libbpf-tools/$(BPF_ARCH)/vmlinux.h $(BCC_NATIVE_OBJS)
	install -d "$(NATIVE_OUT)/bcc"
	install -d "$(BCC_NATIVE_STAGE_OUT)"
	install -m 0644 $(BCC_NATIVE_OBJS) "$(BCC_NATIVE_STAGE_OUT)"
	python3 "$(CURDIR)/write_native_manifest.py" --app bcc --llvm-nm "$(LLVM_NM)" \
		--output "$(NATIVE_OUT)/bcc/manifest.json" \
		$(foreach obj,$(BCC_NATIVE_OBJS),--object "$(obj)")
	$(call native_merge_text,$(BCC_NATIVE_STAGE_OUT))
	python3 "$(CURDIR)/write_native_manifest.py" --app bcc --llvm-nm "$(LLVM_NM)" \
		--output "$(BCC_NATIVE_STAGE_OUT)/manifest.json" \
		$(foreach tool,$(BCC_TOOLS),--object "$(BCC_NATIVE_STAGE_OUT)/$(tool).native.o")

native-cilium: $(CILIUM_NATIVE_OBJS)
	install -d "$(CILIUM_NATIVE_STAGE_OUT)"
	rm -f "$(CILIUM_NATIVE_STAGE_OUT)"/*.native.o
	install -m 0644 $(CILIUM_NATIVE_OBJS) "$(CILIUM_NATIVE_STAGE_OUT)"
	python3 "$(CURDIR)/write_native_manifest.py" --app cilium --llvm-nm "$(LLVM_NM)" \
		--output "$(NATIVE_OUT)/cilium/manifest.json" \
		--object "$(NATIVE_OUT)/cilium/bpf_lxc.native.o,source_map_prefix=cilium_calls_0" \
		--object "$(NATIVE_OUT)/cilium/bpf_overlay.native.o,source_map_prefix=cilium_calls_ov" \
		--object "$(NATIVE_OUT)/cilium/bpf_sock.native.o" \
		--object "$(NATIVE_OUT)/cilium/bpf_host.native.o,source_map_prefix=cilium_calls_ho,source_map_prefix=cilium_calls_ne" \
		--object "$(NATIVE_OUT)/cilium/bpf_host.native.o,symbol=tail_drop_notify,source_xlated_len=752" \
		--object "$(NATIVE_OUT)/cilium/bpf_lxc.native.o,symbol=tail_drop_notify,source_xlated_len=696" \
		--object "$(NATIVE_OUT)/cilium/bpf_wireguard.native.o,source_map_prefix=cilium_calls_wi" \
		--object "$(NATIVE_OUT)/cilium/bpf_xdp.native.o,prog_type=6" \
		--object "$(NATIVE_OUT)/cilium/cilium_placeholders.native.o"
	$(call native_merge_text,$(CILIUM_NATIVE_STAGE_OUT))
	python3 "$(CURDIR)/write_native_manifest.py" --app cilium --llvm-nm "$(LLVM_NM)" \
		--output "$(CILIUM_NATIVE_STAGE_OUT)/manifest.json" \
		--object "$(CILIUM_NATIVE_STAGE_OUT)/bpf_lxc.native.o,source_map_prefix=cilium_calls_0" \
		--object "$(CILIUM_NATIVE_STAGE_OUT)/bpf_overlay.native.o,source_map_prefix=cilium_calls_ov" \
		--object "$(CILIUM_NATIVE_STAGE_OUT)/bpf_sock.native.o" \
		--object "$(CILIUM_NATIVE_STAGE_OUT)/bpf_host.native.o,source_map_prefix=cilium_calls_ho,source_map_prefix=cilium_calls_ne" \
		--object "$(CILIUM_NATIVE_STAGE_OUT)/bpf_host.native.o,symbol=tail_drop_notify,source_xlated_len=752" \
		--object "$(CILIUM_NATIVE_STAGE_OUT)/bpf_lxc.native.o,symbol=tail_drop_notify,source_xlated_len=696" \
		--object "$(CILIUM_NATIVE_STAGE_OUT)/bpf_wireguard.native.o,source_map_prefix=cilium_calls_wi" \
		--object "$(CILIUM_NATIVE_STAGE_OUT)/bpf_xdp.native.o,prog_type=6" \
		--object "$(CILIUM_NATIVE_STAGE_OUT)/cilium_placeholders.native.o"

native-otel: $(OTEL_NATIVE_OBJECT)
	install -d "$(OTEL_NATIVE_STAGE_OUT)"
	install -m 0644 "$(OTEL_NATIVE_OBJECT)" "$(OTEL_NATIVE_STAGE_OUT)/otelcol-ebpf-profiler.native.o"
	python3 "$(CURDIR)/write_native_manifest.py" --app otelcol-ebpf-profiler --llvm-nm "$(LLVM_NM)" \
		--output "$(NATIVE_OUT)/otel/manifest.json" \
		--object "$(OTEL_NATIVE_OBJECT)"
	$(call native_merge_text,$(OTEL_NATIVE_STAGE_OUT))
	python3 "$(CURDIR)/write_native_manifest.py" --app otelcol-ebpf-profiler --llvm-nm "$(LLVM_NM)" \
		--output "$(OTEL_NATIVE_STAGE_OUT)/manifest.json" \
		--object "$(OTEL_NATIVE_STAGE_OUT)/otelcol-ebpf-profiler.native.o"

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
	$(call native_merge_text,$(TRACEE_NATIVE_STAGE_OUT))
	python3 "$(CURDIR)/write_native_manifest.py" --app tracee --llvm-nm "$(LLVM_NM)" \
		--output "$(TRACEE_NATIVE_STAGE_OUT)/manifest.json" \
		--object "$(TRACEE_NATIVE_STAGE_OUT)/tracee.native.o" \
		$(foreach src,$(TRACEE_LSM_SUPPORT_SRCS),--object "$(TRACEE_NATIVE_STAGE_OUT)/$(src).native.o")

native-tetragon: tetragon/bpf/include/vmlinux_generated_$(BPF_ARCH).h native_compat.h $(NATIVE_LINK)
	install -d "$(NATIVE_OUT)/tetragon"
	install -d "$(TETRAGON_NATIVE_STAGE_OUT)"
	rm -f "$(NATIVE_OUT)/tetragon"/*.native.o
	rm -f "$(TETRAGON_NATIVE_STAGE_OUT)"/*.native.o
	native_out="$(NATIVE_OUT)/tetragon"; \
	stage_out="$(TETRAGON_NATIVE_STAGE_OUT)"; \
	common_flags=($(NATIVE_CFLAGS) -fms-extensions -DMICRO_NATIVE_TETRAGON \
		-D__TARGET_ARCH_$(BPF_ARCH) \
		-include "$(CURDIR)/native_compat.h" \
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
			symbols="$$("$(LLVM_NM)" --defined-only --format=posix "$${obj}" | awk '$$2 ~ /^[Tt]$$/ && $$1 !~ /^LBB/ && $$1 !~ /^__check_/ {print $$1}')"; \
			if [[ -z "$${symbols}" ]]; then \
			echo "no native text symbols in $${obj}" >&2; \
			exit 1; \
		fi; \
			install -m 0644 "$${obj}" "$${stage_out}/$${base}.native.o"; \
		done; \
		native_args=(); \
		stage_args=(); \
		for obj in "$${native_out}"/*.native.o; do native_args+=(--object "$${obj}"); done; \
		for obj in "$${stage_out}"/*.native.o; do stage_args+=(--object "$${obj}"); done; \
		python3 "$(CURDIR)/write_native_manifest.py" --app tetragon --llvm-nm "$(LLVM_NM)" --dedupe-program last \
			--source-object-root "$(VENDOR)/build/$(BPF_ARCH)/tetragon" --helper-disambiguate 174 \
			--output "$${native_out}/manifest.json" "$${native_args[@]}"; \
		$(call native_merge_text,$${stage_out}); \
		python3 "$(CURDIR)/write_native_manifest.py" --app tetragon --llvm-nm "$(LLVM_NM)" --dedupe-program last \
			--source-object-root "$(VENDOR)/build/$(BPF_ARCH)/tetragon" --helper-disambiguate 174 \
			--output "$${stage_out}/manifest.json" "$${stage_args[@]}"

# The loader runs this compiler at load time; it ships in the stage. It optimizes at -O3, as P does.
PERF_CONTEXT_LTO ?= $(NATIVE_STAGE_ROOT)/kprog-perf-context-lto
# The tool executes in the destination runtime; use that same base's LLVM18 on arm64.
PERF_CONTEXT_CXX := clang++-18
PERF_CONTEXT_LIBS = $$(llvm-config-18 --link-static --ldflags --libs core irreader analysis support passes native aarch64 object linker --system-libs) \
	$(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz
ifeq ($(BPF_ARCH),arm64)
PERF_CONTEXT_CXX := aarch64-linux-gnu-g++
PERF_CONTEXT_LIBS := $(ROOT)/.cache/qemu-arm64-root/usr/lib/llvm-18/lib/libLLVM.so.1 \
	$(ROOT)/.cache/qemu-arm64-root/usr/lib/aarch64-linux-gnu/libbpf.so.1 \
	-Wl,-rpath-link,$(ROOT)/.cache/qemu-arm64-root/usr/lib/aarch64-linux-gnu \
	-Wl,-rpath-link,$(ROOT)/.cache/qemu-arm64-root/lib/aarch64-linux-gnu -lpthread -ldl -lz
endif
$(PERF_CONTEXT_LTO): $(ROOT)/kprog/x86/perf_context_lto.cpp $(ROOT)/kprog/libnativeloader/src/native_loader_lto.hpp \
		$(ROOT)/kprog/x86/bpf_function_bodies.hpp $(ROOT)/kprog/x86/runtime_bpf_callee.hpp $(ROOT)/vendor/bpf/native-lpm.h Makefile
	install -d "$(dir $@)"
	$(PERF_CONTEXT_CXX) $$(llvm-config-18 --cxxflags) -std=c++17 -fexceptions -Wall -Wextra -Wno-unused-parameter \
		-I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include "$<" -o "$@" \
		$(PERF_CONTEXT_LIBS)


# All P objects use the common flags above, including after a flag-only change.
$(KATRAN_NATIVE_OBJS) $(BCC_NATIVE_OBJS) $(CILIUM_NATIVE_OBJS) $(OTEL_NATIVE_UNIT_OBJS) $(TRACEE_NATIVE_OBJS): Makefile

native-artifacts: native-katran native-bcc native-otel native-cilium native-tracee native-tetragon $(PERF_CONTEXT_LTO)
