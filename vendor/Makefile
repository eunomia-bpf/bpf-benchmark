# vendor/Makefile — source-built app artifacts.

SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

.PHONY: apps apps-x86 apps-arm64 cilium-x86 cilium-arm64 tetragon-x86 tetragon-arm64 otel-x86 otel-arm64 tracee-x86 tracee-arm64 bcc-x86 bcc-arm64 bpftrace-x86 bpftrace-arm64 katran-x86 katran-arm64 bpftool-x86 bpftool-arm64

ROOT       := $(abspath $(CURDIR)/..)
BUILD      := $(CURDIR)/build
CACHE      := $(ROOT)/.cache
GO         ?= go
TRACEE_GO  := $(notdir $(GO))
GO_ENV     := GOTOOLCHAIN=auto GOCACHE=$(CACHE)/go-build GOMODCACHE=$(CACHE)/go-mod
JOBS       ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
CLANG      ?= clang-18
LLC        ?= llc-18
OCB        := go.opentelemetry.io/collector/cmd/builder@v0.139.0
OTEL_VER   := 0.140.0
OTELCOL_VER:= 0.139.0

CILIUM     := $(CURDIR)/repos/cilium
TETRAGON   := $(CURDIR)/repos/tetragon
OTEL       := $(CURDIR)/repos/opentelemetry-ebpf-profiler
TRACEE     := $(CURDIR)/repos/tracee
BCC        := $(CURDIR)/repos/bcc
BPFTRACE   := $(CURDIR)/repos/bpftrace
KATRAN     := $(CURDIR)/repos/katran
BPFTOOL    := $(CURDIR)/linux-framework/tools/bpf/bpftool
GO_DYNAMIC_LDFLAGS := -linkmode external
KATRAN_BPF_OBJS := balancer.bpf.o healthchecking_ipip.bpf.o healthchecking.bpf.o xdp_root.bpf.o
KATRAN_BPF_DEPS := $(wildcard $(KATRAN)/katran/lib/bpf/*.h $(KATRAN)/katran/lib/linux_includes/*.h)
KATRAN_BPF_CC = "$(CLANG)" -I"$(KATRAN)" -I"$(KATRAN)/katran/lib/linux_includes" -DDEBUG -D__KERNEL__ -Wno-unused-value -Wno-pointer-sign -Wno-compare-distinct-pointer-types -O2 -emit-llvm -c -g "$<" -o - | "$(LLC)" -march=bpf -filetype=obj -o "$@"
BPFTOOL_FLAGS := VMLINUX_BTF= feature-libbfd=0 feature-libbfd-liberty=0 feature-libbfd-liberty-z=0

ARM64_SYSROOT := $(BUILD)/sysroots/arm64-llvm15
ARM64_DEBS    := $(BUILD)/.apt-arm64-debs
ARM64_CLANG_CONFIG := $(ARM64_SYSROOT)/usr/lib/llvm-15/lib/cmake/clang/ClangConfig.cmake
ARM64_PKGS    := llvm-15-dev:arm64 llvm-15:arm64 llvm-15-runtime:arm64 llvm-15-tools:arm64 llvm-15-linker-tools:arm64 \
	libllvm15t64:arm64 libclang-15-dev:arm64 libclang-common-15-dev:arm64 libclang-cpp15t64:arm64 libclang1-15t64:arm64 libclang-rt-15-dev:arm64 \
	libobjc-13-dev:arm64 libobjc4:arm64 libgc1:arm64 libffi8:arm64 libffi-dev:arm64 libxml2:arm64 libxml2-dev:arm64 \
	libedit2:arm64 libtinfo6:arm64 libncurses-dev:arm64 libbsd0:arm64 libmd0:arm64 libzstd-dev:arm64 zlib1g:arm64 zlib1g-dev:arm64 \
	libbpf-dev:arm64 libbpf1:arm64 libelf-dev:arm64 libelf1t64:arm64 libdw-dev:arm64 libdw1t64:arm64 liblzma-dev:arm64 liblzma5:arm64 \
	libbz2-dev:arm64 libbz2-1.0:arm64 libpcap-dev:arm64 libpcap0.8-dev:arm64 libpcap0.8t64:arm64 \
	binutils-dev:arm64 libbinutils:arm64 libctf-nobfd0:arm64 libctf0:arm64 libsframe1:arm64 libcereal-dev

apps: apps-x86 apps-arm64
apps-x86: cilium-x86 tetragon-x86 otel-x86 tracee-x86 bcc-x86 bpftrace-x86 katran-x86 bpftool-x86
apps-arm64: cilium-arm64 tetragon-arm64 otel-arm64 tracee-arm64 bcc-arm64 bpftrace-arm64 katran-arm64 bpftool-arm64

cilium-x86: GOARCH := amd64
cilium-x86: GOCC := gcc
cilium-arm64: GOARCH := arm64
cilium-arm64: GOCC := aarch64-linux-gnu-gcc
cilium-x86 cilium-arm64: cilium-%:
	install -d "$(BUILD)/$*/cilium/bin"
	CC="$(GOCC)" $(GO_ENV) $(MAKE) -C "$(CILIUM)/daemon" GO="$(GO)" GOARCH="$(GOARCH)" CGO_ENABLED=1 EXTRA_GO_BUILD_LDFLAGS="$(GO_DYNAMIC_LDFLAGS)" TARGET="$(BUILD)/$*/cilium/bin/cilium-agent" "$(BUILD)/$*/cilium/bin/cilium-agent"

tetragon-x86: GOARCH := amd64
tetragon-x86: BPFARCH := x86
tetragon-x86: GOCC := gcc
tetragon-arm64: GOARCH := arm64
tetragon-arm64: BPFARCH := arm64
tetragon-arm64: GOCC := aarch64-linux-gnu-gcc
tetragon-x86 tetragon-arm64: tetragon-%:
	install -d "$(BUILD)/$*/tetragon/bin" "$(BUILD)/.tetragon-bpf/$*"
	CC="$(GOCC)" $(GO_ENV) $(MAKE) -C "$(TETRAGON)" GO="$(GO)" TARGET_ARCH="$(GOARCH)" GOARCH="$(GOARCH)" CGO_ENABLED=1 EXTRA_GO_BUILD_LDFLAGS="$(GO_DYNAMIC_LDFLAGS)" EXTRA_GO_BUILD_FLAGS="-o $(BUILD)/$*/tetragon/bin/tetragon" tetragon
	$(MAKE) -C "$(TETRAGON)/bpf" CLANG="$(CLANG)" LLC="$(LLC)" BPF_TARGET_ARCH="$(BPFARCH)" OBJSDIR="$(BUILD)/.tetragon-bpf/$*/objs/" DEPSDIR="$(BUILD)/.tetragon-bpf/$*/deps/" -j"$(JOBS)"
	install -d "$(BUILD)/$*/tetragon"
	cp -a "$(BUILD)/.tetragon-bpf/$*/objs/." "$(BUILD)/$*/tetragon/"

$(CACHE)/otelcol-ebpf-profiler-%.yaml: Makefile
	install -d "$(dir $@)"
	printf '%s\n' \
	  'dist:' '  name: otelcol-ebpf-profiler' '  output_path: $(CACHE)/otelcol-ebpf-profiler-build-$*' '  version: $(OTEL_VER)' '  otelcol_version: $(OTELCOL_VER)' '  cgo_enabled: true' \
	  'receivers:' '  - gomod: go.opentelemetry.io/ebpf-profiler v0.0.0' '    import: go.opentelemetry.io/ebpf-profiler/collector' '    path: $(OTEL)' \
	  'exporters:' '  - gomod: go.opentelemetry.io/collector/exporter/debugexporter v$(OTELCOL_VER)' \
	  'replaces:' '  - go.opentelemetry.io/ebpf-profiler => $(OTEL)' >"$@"

otel-x86: GOARCH := amd64
otel-x86: GOCC := gcc
otel-arm64: GOARCH := arm64
otel-arm64: GOCC := aarch64-linux-gnu-gcc
otel-x86 otel-arm64: otel-%: $(CACHE)/otelcol-ebpf-profiler-%.yaml
	$(GO_ENV) GOOS=linux GOARCH="$(GOARCH)" CGO_ENABLED=1 CC="$(GOCC)" "$(GO)" run "$(OCB)" --config "$<" --ldflags="-s -w $(GO_DYNAMIC_LDFLAGS)"
	install -D -m 0755 "$(CACHE)/otelcol-ebpf-profiler-build-$*/otelcol-ebpf-profiler" "$(BUILD)/$*/otelcol-ebpf-profiler/bin/otelcol-ebpf-profiler"

$(ARM64_CLANG_CONFIG):
	install -d "$(ARM64_DEBS)" "$(ARM64_SYSROOT)"
	sudo dpkg --add-architecture arm64
	sudo apt-get update
	cd "$(ARM64_DEBS)" && apt-get download $(ARM64_PKGS)
	for deb in "$(ARM64_DEBS)"/*.deb; do dpkg-deb -x "$$deb" "$(ARM64_SYSROOT)"; done
	install -d "$(ARM64_SYSROOT)/usr/lib/llvm-15/lib/cmake/clang"
	printf '%s\n' \
	  'include_guard(GLOBAL)' \
	  'get_filename_component(CLANG_INSTALL_PREFIX "$${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)' \
	  'set(CLANG_CMAKE_DIR "$${CMAKE_CURRENT_LIST_DIR}")' \
	  'set(CLANG_INCLUDE_DIRS "$${CLANG_INSTALL_PREFIX}/include")' \
	  'set(CLANG_EXPORTED_TARGETS libclang)' \
	  'add_library(libclang SHARED IMPORTED GLOBAL)' \
	  'set_target_properties(libclang PROPERTIES IMPORTED_LOCATION "$${CLANG_INSTALL_PREFIX}/lib/libclang-15.so.1" IMPORTED_SONAME "libclang-15.so.1")' >"$@"

tracee-x86:
	CGO_ENABLED=1 $(GO_ENV) $(MAKE) -C "$(TRACEE)" OUTPUT_DIR="$(BUILD)/.tracee-build/x86/dist" GOENV_MK="$(BUILD)/.tracee-build/x86/dist/goenv.mk" GO_ARCH=amd64 LINUX_ARCH=x86 ARCH=x86_64 CMD_GO="$(TRACEE_GO)" CMD_CLANG="$(CLANG)" CMD_BPF_CLANG="$(CLANG)" CMD_LIBBPF_CC="$(CLANG)" CMD_CGO_CC="$(CLANG)" CMD_GCC=gcc tracee
	file "$(BUILD)/.tracee-build/x86/dist/tracee" | grep -q 'x86-64'
	install -D -m 0755 "$(BUILD)/.tracee-build/x86/dist/tracee" "$(BUILD)/x86/tracee/bin/tracee"

tracee-arm64:
	CGO_ENABLED=1 $(GO_ENV) $(MAKE) -C "$(TRACEE)" OUTPUT_DIR="$(BUILD)/.tracee-build/arm64/dist" GOENV_MK="$(BUILD)/.tracee-build/arm64/dist/goenv.mk" GO_ARCH=arm64 LINUX_ARCH=arm64 ARCH=arm64 CMD_GO="$(TRACEE_GO)" CMD_CLANG="$(CLANG)" CMD_BPF_CLANG="$(CLANG)" CMD_LIBBPF_CC=aarch64-linux-gnu-gcc CMD_CGO_CC=aarch64-linux-gnu-gcc CMD_GCC=aarch64-linux-gnu-gcc tracee
	file "$(BUILD)/.tracee-build/arm64/dist/tracee" | grep -q 'ARM aarch64'
	install -D -m 0755 "$(BUILD)/.tracee-build/arm64/dist/tracee" "$(BUILD)/arm64/tracee/bin/tracee"

bcc-x86:
	install -d "$(BUILD)/.bcc-build/x86-llvm15"
	GIT_CONFIG_GLOBAL="$(BUILD)/.bcc-build/x86-llvm15/gitconfig" cmake -S "$(BCC)" -B "$(BUILD)/.bcc-build/x86-llvm15" -GNinja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="$(BUILD)/x86/bcc" -DNO_BLAZESYM=ON -DENABLE_EXAMPLES=OFF -DENABLE_MAN=OFF -DENABLE_TESTS=OFF -DENABLE_LLVM_SHARED=ON -DENABLE_LLVM_NATIVECODEGEN=OFF -DLLVM_DIR=/usr/lib/llvm-15/lib/cmake/llvm -DCLANG_DIR=/usr/lib/llvm-15 -DREVISION=0.29.1 -DREVISION_LAST=0.29.1 -DCMAKE_CXX_FLAGS= -DCMAKE_CXX_FLAGS_RELEASE='-O3 -DNDEBUG'
	GIT_CONFIG_GLOBAL="$(BUILD)/.bcc-build/x86-llvm15/gitconfig" cmake --build "$(BUILD)/.bcc-build/x86-llvm15" -j"$(JOBS)"
	GIT_CONFIG_GLOBAL="$(BUILD)/.bcc-build/x86-llvm15/gitconfig" cmake --install "$(BUILD)/.bcc-build/x86-llvm15"

bcc-arm64: $(ARM64_CLANG_CONFIG)
	install -d "$(BUILD)/.bcc-build/arm64"
	GIT_CONFIG_GLOBAL="$(BUILD)/.bcc-build/arm64/gitconfig" cmake -S "$(BCC)" -B "$(BUILD)/.bcc-build/arm64" -GNinja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="$(BUILD)/arm64/bcc" -DCMAKE_SYSTEM_NAME=Linux -DCMAKE_SYSTEM_PROCESSOR=aarch64 -DCMAKE_C_COMPILER=aarch64-linux-gnu-gcc -DCMAKE_CXX_COMPILER=aarch64-linux-gnu-g++ -DCMAKE_FIND_ROOT_PATH="$(ARM64_SYSROOT)" -DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER -DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=BOTH -DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=BOTH -DCMAKE_FIND_ROOT_PATH_MODE_PACKAGE=BOTH -DNO_BLAZESYM=ON -DENABLE_EXAMPLES=OFF -DENABLE_MAN=OFF -DENABLE_TESTS=OFF -DENABLE_LLVM_SHARED=ON -DENABLE_LLVM_NATIVECODEGEN=OFF -DLLVM_DIR="$(ARM64_SYSROOT)/usr/lib/llvm-15/lib/cmake/llvm" -DCLANG_DIR="$(ARM64_SYSROOT)/usr/lib/llvm-15" -Dlibclang-shared="$(ARM64_SYSROOT)/usr/lib/llvm-15/lib/libclang-cpp.so.15" -DREVISION=0.29.1 -DREVISION_LAST=0.29.1 -DZLIB_LIBRARY="$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu/libz.so" -DZLIB_INCLUDE_DIR="$(ARM64_SYSROOT)/usr/include" -DLIBELF_LIBRARIES=/usr/lib/aarch64-linux-gnu/libelf.so -DLIBELF_INCLUDE_DIRS=/usr/include -DLIBLZMA_LIBRARIES=/usr/lib/aarch64-linux-gnu/liblzma.so -DLIBLZMA_INCLUDE_DIRS=/usr/include -DFFI_INCLUDE_DIR="$(ARM64_SYSROOT)/usr/include/aarch64-linux-gnu" -DFFI_LIBRARY_DIR="$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu" -DFFI_LIBRARIES="$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu/libffi.so" -DTerminfo_LIBRARIES="$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu/libtinfo.so" -DLIBXML2_LIBRARY="$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu/libxml2.so" -DLIBXML2_INCLUDE_DIR="$(ARM64_SYSROOT)/usr/include/libxml2" -DCMAKE_CXX_FLAGS= -DCMAKE_CXX_FLAGS_RELEASE='-O3 -DNDEBUG'
	GIT_CONFIG_GLOBAL="$(BUILD)/.bcc-build/arm64/gitconfig" cmake --build "$(BUILD)/.bcc-build/arm64" -j"$(JOBS)"
	GIT_CONFIG_GLOBAL="$(BUILD)/.bcc-build/arm64/gitconfig" cmake --install "$(BUILD)/.bcc-build/arm64"

bpftrace-x86:
	cmake -S "$(BPFTRACE)" -B "$(BUILD)/.bpftrace-build/x86" -GNinja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="$(BUILD)/x86/bpftrace" -DUSE_SYSTEM_BPF_BCC=ON -DBUILD_TESTING=OFF -DENABLE_MAN=OFF -DENABLE_TEST_VALIDATE_CODEGEN=OFF -DLLVM_REQUESTED_VERSION=17 -DCMAKE_CXX_FLAGS='-DBPFTRACE_VERSION=\\\"v0.19.0\\\"'
	cmake --build "$(BUILD)/.bpftrace-build/x86" -j"$(JOBS)"
	cmake --install "$(BUILD)/.bpftrace-build/x86"

bpftrace-arm64: bcc-arm64
	CPATH="$(BUILD)/arm64/bcc/include:$(ARM64_SYSROOT)/usr/include:$(ARM64_SYSROOT)/usr/include/aarch64-linux-gnu:$(ARM64_SYSROOT)/usr/include/elfutils" LIBRARY_PATH="$(BUILD)/arm64/bcc/lib:$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu:$(ARM64_SYSROOT)/usr/lib/llvm-15/lib" LD_LIBRARY_PATH="$(BUILD)/arm64/bcc/lib:$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu:$(ARM64_SYSROOT)/usr/lib/llvm-15/lib" cmake -S "$(BPFTRACE)" -B "$(BUILD)/.bpftrace-build/arm64" -GNinja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="$(BUILD)/arm64/bpftrace" -DCMAKE_SYSTEM_NAME=Linux -DCMAKE_SYSTEM_PROCESSOR=aarch64 -DCMAKE_C_COMPILER=aarch64-linux-gnu-gcc -DCMAKE_CXX_COMPILER=aarch64-linux-gnu-g++ -DCMAKE_FIND_ROOT_PATH="$(ARM64_SYSROOT);$(BUILD)/arm64/bcc" -DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER -DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=ONLY -DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=ONLY -DCMAKE_FIND_ROOT_PATH_MODE_PACKAGE=ONLY -DCMAKE_PREFIX_PATH="$(ARM64_SYSROOT)/usr/lib/llvm-15;$(BUILD)/arm64/bcc" -DUSE_SYSTEM_BPF_BCC=ON -DBUILD_TESTING=OFF -DENABLE_MAN=OFF -DENABLE_TEST_VALIDATE_CODEGEN=OFF -DENABLE_SKB_OUTPUT=OFF -DLLVM_REQUESTED_VERSION=15 -DLLVM_DIR="$(ARM64_SYSROOT)/usr/lib/llvm-15/lib/cmake/llvm" -DClang_DIR="$(ARM64_SYSROOT)/usr/lib/llvm-15/lib/cmake/clang" -DLIBBCC_INCLUDE_DIRS="$(BUILD)/arm64/bcc/include" -DLIBBCC_LIBRARIES="$(BUILD)/arm64/bcc/lib/libbcc.so" -DLIBBCC_BPF_LIBRARIES="$(BUILD)/arm64/bcc/lib/libbcc_bpf.so" -DLIBBCC_LOADER_LIBRARY_STATIC="$(BUILD)/arm64/bcc/lib/libbcc-loader-static.a" -DLIBBPF_INCLUDE_DIRS="$(ARM64_SYSROOT)/usr/include" -DLIBBPF_LIBRARIES="$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu/libbpf.so" -DLIBCEREAL_INCLUDE_DIRS="$(ARM64_SYSROOT)/usr/include" -DLIBELF_INCLUDE_DIRS="$(ARM64_SYSROOT)/usr/include" -DLIBELF_LIBRARIES="$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu/libelf.so" -DLIBDW_INCLUDE_DIRS="$(ARM64_SYSROOT)/usr/include/elfutils" -DLIBDW_LIBRARIES="$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu/libdw.so" -DLIBBFD_INCLUDE_DIRS="$(ARM64_SYSROOT)/usr/include" -DLIBBFD_LIBRARIES="$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu/libbfd.so" -DLIBOPCODES_INCLUDE_DIRS="$(ARM64_SYSROOT)/usr/include" -DLIBOPCODES_LIBRARIES="$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu/libopcodes.so" -DZLIB_LIBRARY="$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu/libz.so" -DZLIB_INCLUDE_DIR="$(ARM64_SYSROOT)/usr/include" -DFFI_INCLUDE_DIR="$(ARM64_SYSROOT)/usr/include/aarch64-linux-gnu" -DFFI_LIBRARY_DIR="$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu" -DFFI_LIBRARIES="$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu/libffi.so" -DTerminfo_LIBRARIES="$(ARM64_SYSROOT)/usr/lib/aarch64-linux-gnu/libtinfo.so" -DCMAKE_CXX_FLAGS='-I$(ARM64_SYSROOT)/usr/lib/llvm-15/include'
	cmake --build "$(BUILD)/.bpftrace-build/arm64" -j"$(JOBS)"
	cmake --install "$(BUILD)/.bpftrace-build/arm64"

katran-x86: $(addprefix $(BUILD)/x86/katran/bpf/,$(KATRAN_BPF_OBJS))
katran-arm64: $(addprefix $(BUILD)/arm64/katran/bpf/,$(KATRAN_BPF_OBJS))
$(BUILD)/x86/katran/bpf/%.bpf.o: $(KATRAN)/katran/lib/bpf/%.c $(KATRAN_BPF_DEPS)
	install -d "$(dir $@)"
	$(KATRAN_BPF_CC)

$(BUILD)/arm64/katran/bpf/%.bpf.o: $(KATRAN)/katran/lib/bpf/%.c $(KATRAN_BPF_DEPS)
	install -d "$(dir $@)"
	$(KATRAN_BPF_CC)

bpftool-x86: BPFTOOL_LLVM := 1
bpftool-arm64: BPFTOOL_LLVM := 0
bpftool-arm64: BPFTOOL_CROSS := ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- EXTRA_LDFLAGS="-L/usr/lib/aarch64-linux-gnu -Wl,-rpath-link,/usr/lib/aarch64-linux-gnu"
bpftool-x86 bpftool-arm64: bpftool-%:
	install -d "$(BUILD)/.bpftool/$*" "$(BUILD)/$*/bpftool/bin"
	$(MAKE) -C "$(BPFTOOL)" OUTPUT="$(BUILD)/.bpftool/$*/" $(BPFTOOL_FLAGS) feature-llvm="$(BPFTOOL_LLVM)" $(BPFTOOL_CROSS) -j"$(JOBS)"
	install -m 0755 "$(BUILD)/.bpftool/$*/bpftool" "$(BUILD)/$*/bpftool/bin/bpftool"
