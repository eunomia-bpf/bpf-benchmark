SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

.PHONY: all clean vmlinux katran bcc tetragon cilium otel tracee native-katran native-bcc native-otel native-cilium native-tracee native-tetragon native-artifacts

ROOT := $(abspath ../..)
VENDOR := $(ROOT)/vendor
BUILD := $(VENDOR)/build/native-bpf
KERNEL_RELEASE ?= $(shell uname -r)
ARCH := x86
GOARCH := amd64

CLANG ?= clang-18
LLC ?= llc-18
BPF_LINK ?= llvm-link-18
LLVM_NM ?= llvm-nm-18
LLVM_STRIP ?= llvm-strip-18
BPFTOOL ?= $(VENDOR)/build/x86/bpftool/bin/bpftool
VMLINUX_BTF ?= /sys/kernel/btf/vmlinux
NATIVE_LINK ?= $(ROOT)/native-sim/x86/native_lab/native_link/target/release/native-link

OUT := $(BUILD)/$(ARCH)/$(KERNEL_RELEASE)
VMLINUX_H := targets/$(ARCH)/$(KERNEL_RELEASE)/vmlinux.h
BPF_TARGET_ARCH := $(if $(filter arm64 aarch64,$(ARCH)),arm64,x86)
TARGET_ARCH_DEFINE := __TARGET_ARCH_$(BPF_TARGET_ARCH)
VMLINUX_GUARD_ARCH := $(shell printf '%s' '$(BPF_TARGET_ARCH)' | tr '[:lower:]' '[:upper:]')
BCC_VMLINUX_H := bcc/libbpf-tools/$(BPF_TARGET_ARCH)/vmlinux.h
TETRAGON_VMLINUX_H := tetragon/bpf/include/vmlinux_generated_$(BPF_TARGET_ARCH).h
NATIVE_SYS_INCLUDE_FLAGS ?= -I/usr/include -I/usr/include/x86_64-linux-gnu
SYS_INCLUDE_FLAGS ?= $(NATIVE_SYS_INCLUDE_FLAGS)

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
NATIVE_TARGET_FLAGS := $(if $(filter arm64 aarch64,$(ARCH)),--target=aarch64-linux-gnu)
NATIVE_ARCH_CFLAGS := $(if $(filter x86,$(ARCH)),-march=native -mno-red-zone -mgeneral-regs-only) \
	$(if $(filter arm64 aarch64,$(ARCH)),-mtune=neoverse-n1 -mgeneral-regs-only -mno-outline-atomics \
		-ffixed-x18 -ffixed-x26 -ffixed-x27 \
		-ffixed-x28)
NATIVE_CFLAGS := $(NATIVE_TARGET_FLAGS) -O3 -g -fPIC -c -DMICRO_NATIVE \
	-D$(TARGET_ARCH_DEFINE) \
	-fomit-frame-pointer $(NATIVE_ARCH_CFLAGS) -fno-stack-protector \
	-fno-asynchronous-unwind-tables -fno-unwind-tables -fno-jump-tables \
	-fno-optimize-sibling-calls \
	-Wno-unknown-attributes -mllvm -switch-to-lookup=false
KATRAN_NATIVE_CFLAGS := $(NATIVE_TARGET_FLAGS) -O3 -g -fPIC -c -DMICRO_NATIVE \
	-D$(TARGET_ARCH_DEFINE) \
	-fomit-frame-pointer $(NATIVE_ARCH_CFLAGS) -fno-stack-protector \
	-fno-asynchronous-unwind-tables -fno-unwind-tables -fno-jump-tables \
	-fno-optimize-sibling-calls \
	-Wno-unknown-attributes -Wno-compare-distinct-pointer-types \
	-mllvm -switch-to-lookup=false
KATRAN_NATIVE_OBJS := $(patsubst %,$(NATIVE_OUT)/katran/%.native.o,$(KATRAN_OBJS))
KATRAN_NATIVE_PROOF_MARKERS := $(patsubst %,$(NATIVE_OUT)/katran/%.proof.ok,$(KATRAN_OBJS))
BCC_NATIVE_OBJS := $(patsubst %,$(NATIVE_OUT)/bcc/%.native.o,$(BCC_TOOLS))
BCC_NATIVE_PROOF_MARKERS := $(patsubst %,$(NATIVE_OUT)/bcc/%.proof.ok,$(BCC_TOOLS))
CILIUM_NATIVE_PLACEHOLDER_OBJS := $(NATIVE_OUT)/cilium/cilium_placeholders.native.o
CILIUM_NATIVE_OBJS := $(patsubst %.o,$(NATIVE_OUT)/cilium/%.native.o,$(CILIUM_OBJS)) $(CILIUM_NATIVE_PLACEHOLDER_OBJS)
CILIUM_NATIVE_PROOF_MARKERS := $(patsubst %.o,$(NATIVE_OUT)/cilium/%.proof.ok,$(CILIUM_OBJS)) $(NATIVE_OUT)/cilium/cilium_placeholders.proof.ok
OTEL_EBPF_DIR := otel/support/ebpf
OTEL_NATIVE_UNIT_SRCS := $(wildcard $(OTEL_EBPF_DIR)/*.ebpf.c)
OTEL_NATIVE_UNIT_OBJS := $(patsubst $(OTEL_EBPF_DIR)/%.ebpf.c,$(NATIVE_OUT)/otel/%.native.o,$(OTEL_NATIVE_UNIT_SRCS))
OTEL_NATIVE_OBJECT := $(NATIVE_OUT)/otel/otelcol-ebpf-profiler.native.o
OTEL_NATIVE_PROOF_MARKER := $(NATIVE_OUT)/otel/otelcol-ebpf-profiler.proof.ok
TRACEE_NATIVE_OBJECT := $(NATIVE_OUT)/tracee/tracee.native.o
TRACEE_DIRECT_CORE_NATIVE_OBJECT := $(NATIVE_OUT)/tracee/tracee_direct_core.native.o
TRACEE_DIRECT_CORE_SYMBOLS := trace_sys_enter trace_sys_exit
TRACEE_LSM_SUPPORT_NATIVE_OBJS := $(patsubst %,$(NATIVE_OUT)/tracee/lsm_support/%.native.o,$(TRACEE_LSM_SUPPORT_SRCS))
TRACEE_NATIVE_OBJS := $(TRACEE_NATIVE_OBJECT) $(TRACEE_DIRECT_CORE_NATIVE_OBJECT) $(TRACEE_LSM_SUPPORT_NATIVE_OBJS)
TRACEE_NATIVE_PROOF_MARKER := $(NATIVE_OUT)/tracee/tracee.proof.ok
TRACEE_DIRECT_CORE_NATIVE_PROOF_MARKER := $(NATIVE_OUT)/tracee/tracee_direct_core.proof.ok
TRACEE_LSM_SUPPORT_NATIVE_PROOF_MARKERS := $(patsubst %,$(NATIVE_OUT)/tracee/lsm_support/%.proof.ok,$(TRACEE_LSM_SUPPORT_SRCS))
TRACEE_NATIVE_PROOF_MARKERS := $(TRACEE_NATIVE_PROOF_MARKER) $(TRACEE_DIRECT_CORE_NATIVE_PROOF_MARKER) $(TRACEE_LSM_SUPPORT_NATIVE_PROOF_MARKERS)

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

vmlinux: $(VMLINUX_H) $(BCC_VMLINUX_H) $(TETRAGON_VMLINUX_H)

$(VMLINUX_H): $(VMLINUX_BTF)
	install -d "$(dir $@)"
	if [ "$(BPF_TARGET_ARCH)" = x86 ]; then \
		test -r "$(VMLINUX_BTF)"; \
		"$(BPFTOOL)" btf dump file "$(VMLINUX_BTF)" format c > "$@"; \
	else \
		test -s "$@"; \
	fi

$(BCC_VMLINUX_H): $(VMLINUX_H)
	install -D -m 0644 "$<" "$@"

$(TETRAGON_VMLINUX_H): $(VMLINUX_H)
	install -d "$(dir $@)"
	sed 's/__VMLINUX_H__/__VMLINUX_GENERATED_$(VMLINUX_GUARD_ARCH)_H__/g' "$<" > "$@"

katran:
	install -d "$(OUT)/katran"
	for src in $(KATRAN_OBJS); do \
		"$(CLANG)" -I"$(CURDIR)/katran" -I"$(CURDIR)/katran/katran/lib/linux_includes" \
			-DDEBUG -D__KERNEL__ -Wno-unused-value -Wno-pointer-sign \
			-Wno-compare-distinct-pointer-types -O2 -emit-llvm -c -g \
			"$(CURDIR)/katran/katran/lib/bpf/$${src}.c" -o - \
		| "$(LLC)" -march=bpf -filetype=obj -o "$(OUT)/katran/$${src}.bpf.o"; \
	done

bcc: $(BCC_VMLINUX_H)
	$(MAKE) -C "$(CURDIR)/bcc/libbpf-tools" CLANG="$(CLANG)" LLVM_STRIP="$(LLVM_STRIP)" \
		OUTPUT="$(OUT)/bcc/output" APPS="$(BCC_TOOLS)" LIBBPF_OBJ= \
		INCLUDES="$(SYS_INCLUDE_FLAGS)" \
		$(BCC_OBJS)

tetragon: $(TETRAGON_VMLINUX_H)
	install -d "$(OUT)/tetragon"
	$(MAKE) -C "$(CURDIR)/tetragon/bpf" CLANG="$(CLANG)" LLC="$(LLC)" \
		BPF_TARGET_ARCH=$(BPF_TARGET_ARCH) \
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
	trace_inc="-I$(CURDIR)/tracee/pkg/ebpf/c $(SYS_INCLUDE_FLAGS)"; \
	"$(CLANG)" -D$(TARGET_ARCH_DEFINE) -D__BPF_TRACING__ -DCORE -DCOMMON_BUILD \
		$${trace_inc} -target bpf -O2 -g -mcpu=v2 \
		-c "$(CURDIR)/tracee/pkg/ebpf/c/tracee.bpf.c" \
		-o "$(OUT)/tracee/tracee.bpf.o"; \
	for src in kprobe_check lsm_check; do \
		"$(CLANG)" -D$(TARGET_ARCH_DEFINE) -D__BPF_TRACING__ \
			$${trace_inc} -target bpf -O2 -g -mcpu=v2 \
			-c "$(CURDIR)/tracee/pkg/ebpf/c/lsmsupport/$${src}.bpf.c" \
			-o "$(OUT)/tracee/lsm_support/$${src}.bpf.o"; \
	done

$(NATIVE_OUT)/katran/%.native.o: katran/katran/lib/bpf/%.c Makefile
	install -d "$(dir $@)"
	"$(CLANG)" $(KATRAN_NATIVE_CFLAGS) \
		-I"$(CURDIR)/katran" -I"$(CURDIR)/katran/katran/lib/linux_includes" \
		$(NATIVE_SYS_INCLUDE_FLAGS) \
		-o "$@" "$<"

$(NATIVE_OUT)/bcc/%.native.o: bcc/libbpf-tools/%.bpf.c $(BCC_VMLINUX_H) native_compat.h Makefile
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) -include "$(CURDIR)/native_compat.h" \
		-I"$(CURDIR)/bcc/libbpf-tools" -I"$(CURDIR)/bcc/libbpf-tools/$(BPF_TARGET_ARCH)" \
		-I"$(CURDIR)/bcc/src/cc/libbpf/include/uapi" \
		$(NATIVE_SYS_INCLUDE_FLAGS) \
		-o "$@" "$<"

$(NATIVE_OUT)/cilium/bpf_lxc.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_MAX_LXC_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_overlay.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_MAX_OVERLAY_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_sock.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_MAX_LB_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_host.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_MAX_HOST_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_wireguard.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_MAX_WIREGUARD_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_xdp.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_MAX_XDP_OPTIONS)
$(NATIVE_OUT)/cilium/bpf_alignchecker.native.o: CILIUM_NATIVE_OPTIONS := $(CILIUM_SIMPLE_OPTIONS)

$(NATIVE_OUT)/cilium/%.native.o: cilium/bpf/%.c native_compat.h Makefile
	install -d "$(dir $@)"
	"$(CLANG)" $(CILIUM_NATIVE_OPTIONS) $(NATIVE_CFLAGS) \
		-include "$(CURDIR)/native_compat.h" \
		-I"$(CURDIR)/cilium/bpf" -I"$(CURDIR)/cilium/bpf/include" \
		-I"$(CURDIR)/cilium/bpf/include/bpf" \
		-I"$(CURDIR)/cilium/bpf/include/linux" \
		-I"$(CURDIR)/cilium/bpf/lib" \
		$(NATIVE_SYS_INCLUDE_FLAGS) \
		-o "$@" "$<"

$(NATIVE_OUT)/cilium/cilium_placeholders.native.o: cilium_placeholders.c native_compat.h Makefile
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) \
		-include "$(CURDIR)/native_compat.h" \
		$(NATIVE_SYS_INCLUDE_FLAGS) \
		-o "$@" "$<"

$(OTEL_EBPF_DIR)/errors.h: otel/tools/errors-codegen/errors.json otel/tools/errors-codegen/main.go
	$(MAKE) -C "$(CURDIR)/$(OTEL_EBPF_DIR)" errors.h

$(NATIVE_OUT)/otel/%.native.o: $(OTEL_EBPF_DIR)/%.ebpf.c $(OTEL_EBPF_DIR)/errors.h Makefile
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) \
		-Wno-unused-function -Wno-unused-variable \
		-I"$(CURDIR)/$(OTEL_EBPF_DIR)" \
		-o "$@" "$<"

$(OTEL_NATIVE_OBJECT): $(OTEL_NATIVE_UNIT_OBJS)
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_TARGET_FLAGS) -r -o "$@" $(OTEL_NATIVE_UNIT_OBJS)

$(TRACEE_NATIVE_OBJECT): tracee/pkg/ebpf/c/tracee.bpf.c tracee/pkg/ebpf/c/vmlinux.h native_compat.h Makefile
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) -DMICRO_NATIVE_HELPER_MACROS \
		-include "$(CURDIR)/native_compat.h" \
		-D$(TARGET_ARCH_DEFINE) -D__BPF_TRACING__ -DCORE -DCOMMON_BUILD \
		-I"$(CURDIR)/tracee/pkg/ebpf/c" \
		$(NATIVE_SYS_INCLUDE_FLAGS) \
		-o "$@" "$<"

$(TRACEE_DIRECT_CORE_NATIVE_OBJECT): tracee/pkg/ebpf/c/tracee.bpf.c tracee/pkg/ebpf/c/vmlinux.h native_compat.h Makefile
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) -DMICRO_NATIVE_HELPER_MACROS \
		-DMICRO_NATIVE_DIRECT_CORE_READ \
		-include "$(CURDIR)/native_compat.h" \
		-D$(TARGET_ARCH_DEFINE) -D__BPF_TRACING__ -DCORE -DCOMMON_BUILD \
		-I"$(CURDIR)/tracee/pkg/ebpf/c" \
		$(NATIVE_SYS_INCLUDE_FLAGS) \
		-o "$@" "$<"

$(NATIVE_OUT)/tracee/lsm_support/%.native.o: tracee/pkg/ebpf/c/lsmsupport/%.bpf.c tracee/pkg/ebpf/c/vmlinux.h native_compat.h Makefile
	install -d "$(dir $@)"
	"$(CLANG)" $(NATIVE_CFLAGS) -DMICRO_NATIVE_HELPER_MACROS \
		-include "$(CURDIR)/native_compat.h" \
		-D$(TARGET_ARCH_DEFINE) -D__BPF_TRACING__ \
		-I"$(CURDIR)/tracee/pkg/ebpf/c/lsmsupport" \
		-I"$(CURDIR)/tracee/pkg/ebpf/c" \
		$(NATIVE_SYS_INCLUDE_FLAGS) \
		-o "$@" "$<"

$(NATIVE_LINK):
	cargo build --release --manifest-path "$(ROOT)/native-sim/x86/native_lab/native_link/Cargo.toml"

$(NATIVE_OUT)/katran/%.proof.ok: $(NATIVE_OUT)/katran/%.native.o $(NATIVE_LINK) Makefile
	install -d "$(dir $@)"
	symbols="$$("$(LLVM_NM)" --defined-only --format=posix "$<" | awk '$$2 ~ /^[Tt]$$/ {print $$1}')"; \
	if [[ -z "$${symbols}" ]]; then \
		echo "no native text symbols in $<" >&2; \
		exit 1; \
	fi; \
	for sym in $${symbols}; do \
		"$(NATIVE_LINK)" --input "$<" --symbol "$${sym}" \
			--output "$(NATIVE_OUT)/katran/$*.$${sym}.proof.o" --mode proof; \
	done; \
	printf 'ok\n' > "$@"

native-katran: $(KATRAN_NATIVE_OBJS) $(KATRAN_NATIVE_PROOF_MARKERS)
	install -d "$(NATIVE_OUT)/katran"
	install -d "$(KATRAN_NATIVE_STAGE_OUT)"
	rm -f "$(KATRAN_NATIVE_STAGE_OUT)"/*.proof.o
	install -m 0644 $(KATRAN_NATIVE_OBJS) "$(KATRAN_NATIVE_STAGE_OUT)"
	install -m 0644 "$(NATIVE_OUT)/katran"/*.proof.o "$(KATRAN_NATIVE_STAGE_OUT)"
	python3 "$(CURDIR)/write_native_manifest.py" --app katran --llvm-nm "$(LLVM_NM)" --skip-prefix jhash \
		--output "$(NATIVE_OUT)/katran/manifest.json" \
		--object "$(NATIVE_OUT)/katran/balancer.native.o" \
		--object "$(NATIVE_OUT)/katran/healthchecking_ipip.native.o" \
		--object "$(NATIVE_OUT)/katran/xdp_root.native.o"
	python3 "$(CURDIR)/write_native_manifest.py" --app katran --llvm-nm "$(LLVM_NM)" --skip-prefix jhash \
		--output "$(KATRAN_NATIVE_STAGE_OUT)/manifest.json" \
		--object "$(KATRAN_NATIVE_STAGE_OUT)/balancer.native.o" \
		--object "$(KATRAN_NATIVE_STAGE_OUT)/healthchecking_ipip.native.o" \
		--object "$(KATRAN_NATIVE_STAGE_OUT)/xdp_root.native.o"

$(NATIVE_OUT)/bcc/%.proof.ok: $(NATIVE_OUT)/bcc/%.native.o $(NATIVE_LINK) Makefile
	install -d "$(dir $@)"
	symbols="$$("$(LLVM_NM)" --defined-only --format=posix "$<" | awk '$$2 ~ /^[Tt]$$/ {print $$1}')"; \
	if [[ -z "$${symbols}" ]]; then \
		echo "no native text symbols in $<" >&2; \
		exit 1; \
	fi; \
	for sym in $${symbols}; do \
		"$(NATIVE_LINK)" --input "$<" --symbol "$${sym}" \
			--output "$(NATIVE_OUT)/bcc/$*.$${sym}.proof.o" --mode proof; \
	done; \
	printf 'ok\n' > "$@"

native-bcc: $(BCC_VMLINUX_H) $(BCC_NATIVE_OBJS) $(BCC_NATIVE_PROOF_MARKERS)
	install -d "$(NATIVE_OUT)/bcc"
	install -d "$(BCC_NATIVE_STAGE_OUT)"
	rm -f "$(BCC_NATIVE_STAGE_OUT)"/*.proof.o
	install -m 0644 $(BCC_NATIVE_OBJS) "$(BCC_NATIVE_STAGE_OUT)"
	install -m 0644 "$(NATIVE_OUT)/bcc"/*.proof.o "$(BCC_NATIVE_STAGE_OUT)"
	python3 "$(CURDIR)/write_native_manifest.py" --app bcc --llvm-nm "$(LLVM_NM)" \
		--output "$(NATIVE_OUT)/bcc/manifest.json" \
		$(foreach obj,$(BCC_NATIVE_OBJS),--object "$(obj)")
	python3 "$(CURDIR)/write_native_manifest.py" --app bcc --llvm-nm "$(LLVM_NM)" \
		--output "$(BCC_NATIVE_STAGE_OUT)/manifest.json" \
		$(foreach tool,$(BCC_TOOLS),--object "$(BCC_NATIVE_STAGE_OUT)/$(tool).native.o")

$(NATIVE_OUT)/cilium/%.proof.ok: $(NATIVE_OUT)/cilium/%.native.o $(NATIVE_LINK) Makefile
	install -d "$(dir $@)"
	symbols="$$("$(LLVM_NM)" --defined-only --format=posix "$<" | awk '$$2 ~ /^[Tt]$$/ && $$1 !~ /^__check_/ {print $$1}')"; \
	if [[ -z "$${symbols}" ]]; then \
		echo "no native text symbols in $<" >&2; \
		exit 1; \
	fi; \
	for sym in $${symbols}; do \
		"$(NATIVE_LINK)" --input "$<" --symbol "$${sym}" \
			--output "$(NATIVE_OUT)/cilium/$*.$${sym}.proof.o" --mode proof; \
	done; \
	printf 'ok\n' > "$@"

native-cilium: $(CILIUM_NATIVE_OBJS) $(CILIUM_NATIVE_PROOF_MARKERS)
	install -d "$(CILIUM_NATIVE_STAGE_OUT)"
	rm -f "$(CILIUM_NATIVE_STAGE_OUT)"/*.native.o "$(CILIUM_NATIVE_STAGE_OUT)"/*.proof.o
	install -m 0644 $(CILIUM_NATIVE_OBJS) "$(CILIUM_NATIVE_STAGE_OUT)"
	install -m 0644 "$(NATIVE_OUT)/cilium"/*.proof.o "$(CILIUM_NATIVE_STAGE_OUT)"
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

$(OTEL_NATIVE_PROOF_MARKER): $(OTEL_NATIVE_OBJECT) $(NATIVE_LINK) Makefile
	install -d "$(dir $@)"
	symbols="$$("$(LLVM_NM)" --defined-only --format=posix "$<" | awk '$$2 ~ /^[Tt]$$/ {print $$1}')"; \
	if [[ -z "$${symbols}" ]]; then \
		echo "no native text symbols in $<" >&2; \
		exit 1; \
	fi; \
	for sym in $${symbols}; do \
		"$(NATIVE_LINK)" --input "$<" --symbol "$${sym}" \
			--output "$(NATIVE_OUT)/otel/$${sym}.proof.o" --mode proof; \
	done; \
	printf 'ok\n' > "$@"

native-otel: $(OTEL_NATIVE_OBJECT) $(OTEL_NATIVE_PROOF_MARKER)
	install -d "$(OTEL_NATIVE_STAGE_OUT)"
	rm -f "$(OTEL_NATIVE_STAGE_OUT)"/*.proof.o
	install -m 0644 "$(OTEL_NATIVE_OBJECT)" "$(OTEL_NATIVE_STAGE_OUT)/otelcol-ebpf-profiler.native.o"
	for obj in $(OTEL_NATIVE_UNIT_OBJS); do \
		install -m 0644 "$${obj}" "$(OTEL_NATIVE_STAGE_OUT)/$$(basename "$${obj}")"; \
	done
	install -m 0644 "$(NATIVE_OUT)/otel"/*.proof.o "$(OTEL_NATIVE_STAGE_OUT)"
	native_data_args=(); \
	stage_data_args=(); \
	for obj in $(OTEL_NATIVE_UNIT_OBJS); do native_data_args+=(--data-object "$${obj}"); done; \
	for obj in "$(OTEL_NATIVE_STAGE_OUT)"/*.native.o; do \
		if [[ "$$(basename "$${obj}")" != "otelcol-ebpf-profiler.native.o" ]]; then \
			stage_data_args+=(--data-object "$${obj}"); \
		fi; \
	done; \
	python3 "$(CURDIR)/write_native_manifest.py" --app otelcol-ebpf-profiler --llvm-nm "$(LLVM_NM)" \
		--output "$(NATIVE_OUT)/otel/manifest.json" \
		"$${native_data_args[@]}" \
		--object "$(OTEL_NATIVE_OBJECT)"; \
	python3 "$(CURDIR)/write_native_manifest.py" --app otelcol-ebpf-profiler --llvm-nm "$(LLVM_NM)" \
		--output "$(OTEL_NATIVE_STAGE_OUT)/manifest.json" \
		"$${stage_data_args[@]}" \
		--object "$(OTEL_NATIVE_STAGE_OUT)/otelcol-ebpf-profiler.native.o"

$(TRACEE_NATIVE_PROOF_MARKER): $(TRACEE_NATIVE_OBJECT) $(NATIVE_LINK) Makefile
	install -d "$(dir $@)"
	symbols="$$("$(LLVM_NM)" --defined-only --format=posix "$<" | awk '$$2 ~ /^[Tt]$$/ {print $$1}')"; \
	if [[ -z "$${symbols}" ]]; then \
		echo "no native text symbols in $<" >&2; \
		exit 1; \
	fi; \
	for sym in $${symbols}; do \
		"$(NATIVE_LINK)" --input "$<" --symbol "$${sym}" \
			--output "$(NATIVE_OUT)/tracee/$${sym}.proof.o" --mode proof; \
	done; \
	printf 'ok\n' > "$@"

$(TRACEE_DIRECT_CORE_NATIVE_PROOF_MARKER): $(TRACEE_DIRECT_CORE_NATIVE_OBJECT) $(NATIVE_LINK) Makefile
	install -d "$(dir $@)"
	for sym in $(TRACEE_DIRECT_CORE_SYMBOLS); do \
		if ! "$(LLVM_NM)" --defined-only --format=posix "$<" | awk -v sym="$${sym}" '$$1 == sym && $$2 ~ /^[Tt]$$/ { found=1 } END { exit !found }'; then \
			echo "missing direct-core native text symbol $${sym} in $<" >&2; \
			exit 1; \
		fi; \
		"$(NATIVE_LINK)" --input "$<" --symbol "$${sym}" \
			--output "$(NATIVE_OUT)/tracee/tracee_direct_core.$${sym}.proof.o" --mode proof; \
	done; \
	printf 'ok\n' > "$@"

$(NATIVE_OUT)/tracee/lsm_support/%.proof.ok: $(NATIVE_OUT)/tracee/lsm_support/%.native.o $(NATIVE_LINK) Makefile
	install -d "$(dir $@)"
	symbols="$$("$(LLVM_NM)" --defined-only --format=posix "$<" | awk '$$2 ~ /^[Tt]$$/ {print $$1}')"; \
	if [[ -z "$${symbols}" ]]; then \
		echo "no native text symbols in $<" >&2; \
		exit 1; \
	fi; \
	for sym in $${symbols}; do \
		"$(NATIVE_LINK)" --input "$<" --symbol "$${sym}" \
			--output "$(NATIVE_OUT)/tracee/lsm_support/$*.$${sym}.proof.o" --mode proof; \
	done; \
	printf 'ok\n' > "$@"

native-tracee: $(TRACEE_NATIVE_OBJS) $(TRACEE_NATIVE_PROOF_MARKERS)
	install -d "$(TRACEE_NATIVE_STAGE_OUT)"
	rm -f "$(TRACEE_NATIVE_STAGE_OUT)"/*.native.o "$(TRACEE_NATIVE_STAGE_OUT)"/*.proof.o
	for obj in $(TRACEE_NATIVE_OBJS); do \
		install -m 0644 "$${obj}" "$(TRACEE_NATIVE_STAGE_OUT)/$$(basename "$${obj}")"; \
	done
	install -m 0644 "$(NATIVE_OUT)/tracee"/*.proof.o "$(TRACEE_NATIVE_STAGE_OUT)"
	install -m 0644 "$(NATIVE_OUT)/tracee/lsm_support"/*.proof.o "$(TRACEE_NATIVE_STAGE_OUT)"
	python3 "$(CURDIR)/write_native_manifest.py" --app tracee --llvm-nm "$(LLVM_NM)" \
		--dedupe-program last \
		--output "$(NATIVE_OUT)/tracee/manifest.json" \
		--object "$(TRACEE_NATIVE_OBJECT)" \
		--object "$(TRACEE_DIRECT_CORE_NATIVE_OBJECT),symbol=trace_sys_enter" \
		--object "$(TRACEE_DIRECT_CORE_NATIVE_OBJECT),symbol=trace_sys_exit" \
		$(foreach src,$(TRACEE_LSM_SUPPORT_SRCS),--object "$(NATIVE_OUT)/tracee/lsm_support/$(src).native.o")
	python3 "$(CURDIR)/write_native_manifest.py" --app tracee --llvm-nm "$(LLVM_NM)" \
		--dedupe-program last \
		--output "$(TRACEE_NATIVE_STAGE_OUT)/manifest.json" \
		--object "$(TRACEE_NATIVE_STAGE_OUT)/tracee.native.o" \
		--object "$(TRACEE_NATIVE_STAGE_OUT)/tracee_direct_core.native.o,symbol=trace_sys_enter" \
		--object "$(TRACEE_NATIVE_STAGE_OUT)/tracee_direct_core.native.o,symbol=trace_sys_exit" \
		$(foreach src,$(TRACEE_LSM_SUPPORT_SRCS),--object "$(TRACEE_NATIVE_STAGE_OUT)/$(src).native.o")

native-tetragon: $(TETRAGON_VMLINUX_H) native_compat.h $(NATIVE_LINK)
	install -d "$(NATIVE_OUT)/tetragon"
	install -d "$(TETRAGON_NATIVE_STAGE_OUT)"
	rm -f "$(NATIVE_OUT)/tetragon"/*.native.o "$(NATIVE_OUT)/tetragon"/*.proof.o "$(NATIVE_OUT)/tetragon"/*.proof.ok
	rm -f "$(TETRAGON_NATIVE_STAGE_OUT)"/*.native.o "$(TETRAGON_NATIVE_STAGE_OUT)"/*.proof.o
	native_out="$(NATIVE_OUT)/tetragon"; \
	stage_out="$(TETRAGON_NATIVE_STAGE_OUT)"; \
	common_flags=($(NATIVE_CFLAGS) -DMICRO_NATIVE_HELPER_MACROS -DMICRO_NATIVE_TETRAGON \
		-D$(TARGET_ARCH_DEFINE) \
		-include "$(CURDIR)/native_compat.h" \
		-I"$(CURDIR)/tetragon/bpf" \
		-I"$(CURDIR)/tetragon/bpf/include" \
		-I"$(CURDIR)/tetragon/bpf/lib" \
		-I"$(CURDIR)/tetragon/bpf/libbpf" \
		-I"$(CURDIR)/tetragon/bpf/process" \
		-I"$(CURDIR)/tetragon/bpf/errmetrics" \
		$(NATIVE_SYS_INCLUDE_FLAGS)); \
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
		for sym in $${symbols}; do \
				"$(NATIVE_LINK)" --input "$${obj}" --symbol "$${sym}" \
					--output "$${native_out}/$${base}.$${sym}.proof.o" --mode proof; \
				done; \
				printf 'ok\n' > "$${native_out}/$${base}.proof.ok"; \
				install -m 0644 "$${obj}" "$${stage_out}/$${base}.native.o"; \
				install -m 0644 "$${native_out}/$${base}."*.proof.o "$${stage_out}"; \
			done; \
		native_args=(); \
		stage_args=(); \
		for obj in "$${native_out}"/*.native.o; do native_args+=(--object "$${obj}"); done; \
		for obj in "$${stage_out}"/*.native.o; do stage_args+=(--object "$${obj}"); done; \
		python3 "$(CURDIR)/write_native_manifest.py" --app tetragon --llvm-nm "$(LLVM_NM)" --dedupe-program last \
			--source-object-root "$(VENDOR)/build/$(ARCH)/tetragon" --helper-disambiguate 174 \
			--output "$${native_out}/manifest.json" "$${native_args[@]}"; \
		python3 "$(CURDIR)/write_native_manifest.py" --app tetragon --llvm-nm "$(LLVM_NM)" --dedupe-program last \
			--source-object-root "$(VENDOR)/build/$(ARCH)/tetragon" --helper-disambiguate 174 \
			--output "$${stage_out}/manifest.json" "$${stage_args[@]}"

native-artifacts: native-katran native-bcc native-otel native-cilium native-tracee native-tetragon
