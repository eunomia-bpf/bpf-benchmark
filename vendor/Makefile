# vendor/Makefile — source-built app artifacts.

SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

.PHONY: apps apps-x86 apps-arm64 cilium-x86 cilium-arm64 tetragon-x86 tetragon-arm64 otel-x86 otel-arm64 tracee-x86 tracee-arm64 bcc-x86 bcc-arm64 katran-x86 katran-arm64 bpftool-x86 bpftool-arm64

ROOT       := $(abspath $(CURDIR)/..)
BUILD      := $(CURDIR)/build
CACHE      := $(ROOT)/.cache
GO         ?= go
TRACEE_GO  := $(notdir $(GO))
GO_ENV     := GOTOOLCHAIN=auto GOCACHE=$(CACHE)/go-build GOMODCACHE=$(CACHE)/go-mod
JOBS       ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
CLANG      ?= clang-18
LLC        ?= llc-18
OPT        ?= opt-18
OCB        := go.opentelemetry.io/collector/cmd/builder@v0.139.0
OTEL_VER   := 0.140.0
OTELCOL_VER:= 0.139.0

CILIUM     := $(CURDIR)/repos/cilium
CILIUM_EBPF:= $(CURDIR)/repos/cilium-ebpf
TETRAGON   := $(CURDIR)/repos/tetragon
OTEL       := $(CURDIR)/repos/opentelemetry-ebpf-profiler
TRACEE     := $(CURDIR)/repos/tracee
BCC        := $(CURDIR)/repos/bcc
KATRAN     := $(CURDIR)/repos/katran
BPFTOOL    := $(CURDIR)/linux-framework/tools/bpf/bpftool
GO_DYNAMIC_LDFLAGS := -linkmode external
KATRAN_BPF_OBJS := balancer.bpf.o healthchecking_ipip.bpf.o healthchecking.bpf.o xdp_root.bpf.o
KATRAN_BPF_DEPS := $(wildcard $(KATRAN)/katran/lib/bpf/*.h $(KATRAN)/katran/lib/linux_includes/*.h)
MERLIN_COMPILETIME_MODE ?= none
MERLIN_BUILD_DIR ?= $(ROOT)/.cache/third-party-smoke/build/merlin-v0.01-llvm18
MERLIN_ATOMIC_PLUGIN ?= $(MERLIN_BUILD_DIR)/lib/libAtomicBPF.so
MERLIN_ALIGN_PLUGIN ?= $(MERLIN_BUILD_DIR)/lib/libAlignBPF.so
MERLIN_BPF_CLANG = python3 $(CURDIR)/merlin_bpf_clang.py --clang $(CLANG) --llc $(LLC) --opt $(OPT) --mode $(MERLIN_COMPILETIME_MODE) --atomic-plugin $(MERLIN_ATOMIC_PLUGIN) --align-plugin $(MERLIN_ALIGN_PLUGIN)
KATRAN_BPF_CC = python3 "$(CURDIR)/build_katran_bpf.py" --input "$<" --output "$@" --katran-root "$(KATRAN)" --clang "$(CLANG)" --llc "$(LLC)" --opt "$(OPT)" --mode "$(MERLIN_COMPILETIME_MODE)" --atomic-plugin "$(MERLIN_ATOMIC_PLUGIN)" --align-plugin "$(MERLIN_ALIGN_PLUGIN)"
BPFTOOL_FLAGS := VMLINUX_BTF= feature-libbfd=0 feature-libbfd-liberty=0 feature-libbfd-liberty-z=0
BCC_LIBBPF_TOOLS := capable biosnoop vfsstat opensnoop syscount tcpconnect tcplife runqlat
BCC_LIBBPF_FLAGS = -f "$(BCC)/libbpf-tools/Makefile" -C "$(BUILD)/.bcc-libbpf/$(MERLIN_COMPILETIME_MODE)/$*" VPATH="$(BCC)/libbpf-tools:$(BCC)/libbpf-tools/$(BCC_ARCH)" APPS="$(BCC_LIBBPF_TOOLS)" APP_ALIASES= BZ_APPS= OUTPUT="$(BUILD)/.bcc-libbpf/$(MERLIN_COMPILETIME_MODE)/$*/output" BPFTOOL_SRC="$(BCC)/libbpf-tools/bpftool/src" LIBBPF_SRC="$(BCC)/src/cc/libbpf/src" EXTRA_CFLAGS="-I$(BCC)/src/cc/libbpf/include/uapi" ARCH="$(BCC_ARCH)" USE_BLAZESYM=0 CLANG='$(MERLIN_BPF_CLANG)' LLVM_STRIP=llvm-strip-18

apps: apps-x86 apps-arm64
apps-x86: cilium-x86 tetragon-x86 otel-x86 tracee-x86 bcc-x86 katran-x86 bpftool-x86
apps-arm64: cilium-arm64 tetragon-arm64 otel-arm64 tracee-arm64 bcc-arm64 katran-arm64 bpftool-arm64

cilium-x86: GOARCH := amd64
cilium-x86: GOCC := gcc
cilium-arm64: GOARCH := arm64
cilium-arm64: GOCC := aarch64-linux-gnu-gcc
cilium-x86 cilium-arm64: cilium-%:
	install -d "$(BUILD)/$*/cilium/bin"
	CC="$(GOCC)" $(GO_ENV) $(MAKE) -C "$(CILIUM)/daemon" GO="$(GO)" GOARCH="$(GOARCH)" CGO_ENABLED=1 NOSTRIP=1 EXTRA_GO_BUILD_LDFLAGS="$(GO_DYNAMIC_LDFLAGS)" TARGET="$(BUILD)/$*/cilium/bin/cilium-agent" "$(BUILD)/$*/cilium/bin/cilium-agent"

tetragon-x86: GOARCH := amd64
tetragon-x86: BPFARCH := x86
tetragon-x86: GOCC := gcc
tetragon-arm64: GOARCH := arm64
tetragon-arm64: BPFARCH := arm64
tetragon-arm64: GOCC := aarch64-linux-gnu-gcc
tetragon-x86 tetragon-arm64: tetragon-%:
		install -d "$(BUILD)/$*/tetragon/bin" "$(BUILD)/.tetragon-bpf/$(MERLIN_COMPILETIME_MODE)/$*/objs" "$(BUILD)/.tetragon-bpf/$(MERLIN_COMPILETIME_MODE)/$*/deps"
	CC="$(GOCC)" $(GO_ENV) $(MAKE) -C "$(TETRAGON)" GO="$(GO)" TARGET_ARCH="$(GOARCH)" GOARCH="$(GOARCH)" CGO_ENABLED=1 NOSTRIP=1 EXTRA_GO_BUILD_LDFLAGS="$(GO_DYNAMIC_LDFLAGS)" EXTRA_GO_BUILD_FLAGS="-o $(BUILD)/$*/tetragon/bin/tetragon" tetragon
	find "$(BUILD)/.tetragon-bpf/$(MERLIN_COMPILETIME_MODE)/$*/objs" "$(BUILD)/.tetragon-bpf/$(MERLIN_COMPILETIME_MODE)/$*/deps" -type f -delete
	$(MAKE) -C "$(TETRAGON)/bpf" CLANG='$(MERLIN_BPF_CLANG)' LLC="$(LLC)" BPF_TARGET_ARCH="$(BPFARCH)" OBJSDIR="$(BUILD)/.tetragon-bpf/$(MERLIN_COMPILETIME_MODE)/$*/objs/" DEPSDIR="$(BUILD)/.tetragon-bpf/$(MERLIN_COMPILETIME_MODE)/$*/deps/" -j"$(JOBS)"
	install -d "$(BUILD)/$*/tetragon"
	cp -a "$(BUILD)/.tetragon-bpf/$(MERLIN_COMPILETIME_MODE)/$*/objs/." "$(BUILD)/$*/tetragon/"

$(BUILD)/otelcol-ebpf-profiler-%.yaml: Makefile
	install -d "$(dir $@)"
	printf '%s\n' \
	  'dist:' '  name: otelcol-ebpf-profiler' '  output_path: $(BUILD)/otelcol-ebpf-profiler-build-$*' '  version: $(OTEL_VER)' '  otelcol_version: $(OTELCOL_VER)' '  cgo_enabled: true' \
	  'receivers:' '  - gomod: go.opentelemetry.io/ebpf-profiler v0.0.0' '    import: go.opentelemetry.io/ebpf-profiler/collector' '    path: $(OTEL)' \
	  'exporters:' '  - gomod: go.opentelemetry.io/collector/exporter/debugexporter v$(OTELCOL_VER)' \
	  'replaces:' '  - go.opentelemetry.io/ebpf-profiler => $(OTEL)' '  - github.com/cilium/ebpf => $(CILIUM_EBPF)' >"$@"

otel-x86: GOARCH := amd64
otel-x86: GOCC := gcc
otel-arm64: GOARCH := arm64
otel-arm64: GOCC := aarch64-linux-gnu-gcc
otel-x86 otel-arm64: otel-%: $(BUILD)/otelcol-ebpf-profiler-%.yaml
	$(MAKE) -B -C "$(OTEL)/support/ebpf" BPF_CLANG='$(MERLIN_BPF_CLANG)' LLC="$(LLC)" TARGET_ARCH="$(GOARCH)"
	$(GO_ENV) GOOS=linux GOARCH="$(GOARCH)" CGO_ENABLED=1 CC="$(GOCC)" "$(GO)" run "$(OCB)" --config "$<" --ldflags="$(GO_DYNAMIC_LDFLAGS)"
	install -D -m 0755 "$(BUILD)/otelcol-ebpf-profiler-build-$*/otelcol-ebpf-profiler" "$(BUILD)/$*/otelcol-ebpf-profiler/bin/otelcol-ebpf-profiler"

tracee-x86:
	CGO_ENABLED=1 $(GO_ENV) $(MAKE) -B -C "$(TRACEE)" OUTPUT_DIR="$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/x86/dist" GOENV_MK="$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/x86/dist/goenv.mk" GO_ARCH=amd64 LINUX_ARCH=x86 ARCH=x86_64 CMD_GO="$(TRACEE_GO)" CMD_CLANG="$(CLANG)" CMD_BPF_CLANG='$(MERLIN_BPF_CLANG)' CMD_LIBBPF_CC="$(CLANG)" CMD_CGO_CC="$(CLANG)" CMD_GCC=gcc bpf embedded-dirs btfhub signatures
	rm -rf "$(TRACEE)/dist/lsm_support" "$(TRACEE)/dist/btfhub"
	install -d "$(TRACEE)/dist/lsm_support" "$(TRACEE)/dist/btfhub"
	cp "$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/x86/dist/tracee.bpf.o" "$(TRACEE)/dist/tracee.bpf.o"
	cp -a "$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/x86/dist/lsm_support/." "$(TRACEE)/dist/lsm_support/"
	cp -a "$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/x86/dist/btfhub/." "$(TRACEE)/dist/btfhub/"
	rm -f "$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/x86/dist/tracee"
	CGO_ENABLED=1 $(GO_ENV) $(MAKE) -C "$(TRACEE)" OUTPUT_DIR="$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/x86/dist" GOENV_MK="$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/x86/dist/goenv.mk" GO_ARCH=amd64 LINUX_ARCH=x86 ARCH=x86_64 CMD_GO="$(TRACEE_GO)" CMD_CLANG="$(CLANG)" CMD_BPF_CLANG="$(CLANG)" CMD_LIBBPF_CC="$(CLANG)" CMD_CGO_CC="$(CLANG)" CMD_GCC=gcc tracee
	file "$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/x86/dist/tracee" | grep -q 'x86-64'
	install -D -m 0755 "$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/x86/dist/tracee" "$(BUILD)/x86/tracee/bin/tracee"

tracee-arm64:
	CGO_ENABLED=1 $(GO_ENV) $(MAKE) -B -C "$(TRACEE)" OUTPUT_DIR="$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/arm64/dist" GOENV_MK="$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/arm64/dist/goenv.mk" GO_ARCH=arm64 LINUX_ARCH=arm64 ARCH=arm64 CMD_GO="$(TRACEE_GO)" CMD_CLANG="$(CLANG)" CMD_BPF_CLANG='$(MERLIN_BPF_CLANG)' CMD_LIBBPF_CC=aarch64-linux-gnu-gcc CMD_CGO_CC=aarch64-linux-gnu-gcc CMD_GCC=aarch64-linux-gnu-gcc bpf embedded-dirs btfhub signatures
	rm -rf "$(TRACEE)/dist/lsm_support" "$(TRACEE)/dist/btfhub"
	install -d "$(TRACEE)/dist/lsm_support" "$(TRACEE)/dist/btfhub"
	cp "$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/arm64/dist/tracee.bpf.o" "$(TRACEE)/dist/tracee.bpf.o"
	cp -a "$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/arm64/dist/lsm_support/." "$(TRACEE)/dist/lsm_support/"
	cp -a "$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/arm64/dist/btfhub/." "$(TRACEE)/dist/btfhub/"
	rm -f "$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/arm64/dist/tracee"
	CGO_ENABLED=1 $(GO_ENV) $(MAKE) -C "$(TRACEE)" OUTPUT_DIR="$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/arm64/dist" GOENV_MK="$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/arm64/dist/goenv.mk" GO_ARCH=arm64 LINUX_ARCH=arm64 ARCH=arm64 CMD_GO="$(TRACEE_GO)" CMD_CLANG="$(CLANG)" CMD_BPF_CLANG="$(CLANG)" CMD_LIBBPF_CC=aarch64-linux-gnu-gcc CMD_CGO_CC=aarch64-linux-gnu-gcc CMD_GCC=aarch64-linux-gnu-gcc tracee
	file "$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/arm64/dist/tracee" | grep -q 'ARM aarch64'
	install -D -m 0755 "$(BUILD)/.tracee-build/$(MERLIN_COMPILETIME_MODE)/arm64/dist/tracee" "$(BUILD)/arm64/tracee/bin/tracee"

bcc-x86: BCC_ARCH := x86
bcc-arm64: BCC_ARCH := arm64
bcc-arm64: BCC_CROSS := CC=aarch64-linux-gnu-gcc LD=aarch64-linux-gnu-ld BPFTOOL="$(BUILD)/x86/bpftool/bin/bpftool"
bcc-arm64: bpftool-x86
bcc-x86 bcc-arm64: bcc-%:
	install -d "$(BUILD)/.bcc-libbpf/$(MERLIN_COMPILETIME_MODE)/$*" "$(BUILD)/$*/bcc/bin"
	ln -sfn "$(BCC)/libbpf-tools/$(BCC_ARCH)" "$(BUILD)/.bcc-libbpf/$(MERLIN_COMPILETIME_MODE)/$*/$(BCC_ARCH)"
	$(MAKE) -B $(BCC_LIBBPF_FLAGS) $(BCC_CROSS) $(BCC_LIBBPF_TOOLS) -j"$(JOBS)"
	install -m 0755 $(addprefix $(BUILD)/.bcc-libbpf/$(MERLIN_COMPILETIME_MODE)/$*/,$(BCC_LIBBPF_TOOLS)) "$(BUILD)/$*/bcc/bin"

katran-x86: $(addprefix $(BUILD)/x86/katran/bpf/,$(KATRAN_BPF_OBJS))
katran-arm64: $(addprefix $(BUILD)/arm64/katran/bpf/,$(KATRAN_BPF_OBJS))

.PHONY: force-katran-bpf-mode
force-katran-bpf-mode:

.SECONDARY: $(BUILD)/x86/katran/bpf/.merlin-compile-mode $(BUILD)/arm64/katran/bpf/.merlin-compile-mode

$(BUILD)/%/katran/bpf/.merlin-compile-mode: force-katran-bpf-mode
	install -d "$(dir $@)"
	printf '%s\n' "$(MERLIN_COMPILETIME_MODE)" > "$@.tmp"
	mv "$@.tmp" "$@"
	rm -f "$@.tmp"

$(BUILD)/x86/katran/bpf/%.bpf.o: $(KATRAN)/katran/lib/bpf/%.c $(KATRAN_BPF_DEPS) $(BUILD)/x86/katran/bpf/.merlin-compile-mode
	install -d "$(dir $@)"
	$(KATRAN_BPF_CC)

$(BUILD)/arm64/katran/bpf/%.bpf.o: $(KATRAN)/katran/lib/bpf/%.c $(KATRAN_BPF_DEPS) $(BUILD)/arm64/katran/bpf/.merlin-compile-mode
	install -d "$(dir $@)"
	$(KATRAN_BPF_CC)

bpftool-x86: BPFTOOL_LLVM := 0
bpftool-arm64: BPFTOOL_LLVM := 0
bpftool-arm64: BPFTOOL_CROSS := ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- EXTRA_LDFLAGS="-L/usr/lib/aarch64-linux-gnu -Wl,-rpath-link,/usr/lib/aarch64-linux-gnu"
bpftool-x86 bpftool-arm64: bpftool-%:
	install -d "$(BUILD)/.bpftool/$*" "$(BUILD)/$*/bpftool/bin"
	$(MAKE) -C "$(BPFTOOL)" OUTPUT="$(BUILD)/.bpftool/$*/" $(BPFTOOL_FLAGS) feature-llvm="$(BPFTOOL_LLVM)" $(BPFTOOL_CROSS) -j"$(JOBS)"
	install -m 0755 "$(BUILD)/.bpftool/$*/bpftool" "$(BUILD)/$*/bpftool/bin/bpftool"
