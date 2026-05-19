# vendor/Makefile — source-built app artifacts and katran BPF entry points.
#
# katran_server_grpc itself is committed prebuilt under
# vendor/binary/katran/{x86_64,arm64}/bin/, extracted from the
# bpf-benchmark/katran-artifacts:{x86_64,arm64} docker images and
# stripped. To rebuild it from source see repos/README.md katran
# section + the commented cmake recipe at the bottom of this file.
#
# `make katran-x86` / `make katran-arm64` only (re)builds the BPF
# bytecode (.bpf.o), which is fast and architecture-neutral.

SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

.PHONY: apps apps-x86 apps-arm64 cilium-x86 cilium-arm64 tetragon-x86 tetragon-arm64 otel-x86 otel-arm64 tracee-x86 tracee-arm64 bcc-x86 bcc-arm64 bpftrace-x86 bpftrace-arm64 katran-x86 katran-arm64 katran-bpf

ROOT       := $(abspath $(CURDIR)/..)
BUILD      := $(CURDIR)/build
CACHE      := $(ROOT)/.cache
GO         ?= go
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

ARM64_SYSROOT := $(BUILD)/sysroots/arm64-llvm15
ARM64_DEBS    := $(BUILD)/.apt-arm64-debs
ARM64_PKGS    := llvm-15-dev:arm64 llvm-15:arm64 llvm-15-runtime:arm64 llvm-15-tools:arm64 llvm-15-linker-tools:arm64 \
	libllvm15t64:arm64 libclang-15-dev:arm64 libclang-common-15-dev:arm64 libclang-cpp15t64:arm64 libclang1-15t64:arm64 libclang-rt-15-dev:arm64 \
	libobjc-13-dev:arm64 libobjc4:arm64 libgc1:arm64 libffi8:arm64 libffi-dev:arm64 libxml2:arm64 libxml2-dev:arm64 \
	libedit2:arm64 libtinfo6:arm64 libncurses-dev:arm64 libbsd0:arm64 libmd0:arm64 libzstd-dev:arm64 zlib1g:arm64 zlib1g-dev:arm64 \
	libbpf-dev:arm64 libbpf1:arm64 libelf-dev:arm64 libelf1t64:arm64 libdw-dev:arm64 libdw1t64:arm64 liblzma-dev:arm64 liblzma5:arm64 \
	libbz2-dev:arm64 libbz2-1.0:arm64 libpcap-dev:arm64 libpcap0.8-dev:arm64 libpcap0.8t64:arm64 \
	binutils-dev:arm64 libbinutils:arm64 libctf-nobfd0:arm64 libctf0:arm64 libsframe1:arm64 libcereal-dev

apps: apps-x86 apps-arm64
apps-x86: cilium-x86 tetragon-x86 otel-x86 tracee-x86 bcc-x86 bpftrace-x86
apps-arm64: cilium-arm64 tetragon-arm64 otel-arm64 tracee-arm64 bcc-arm64 bpftrace-arm64

cilium-x86 cilium-arm64:
	arch="$(patsubst cilium-%,%,$@)"; goarch=$$(test "$$arch" = x86 && echo amd64 || echo arm64); \
	$(GO_ENV) $(MAKE) -C "$(CILIUM)/daemon" GO="$(GO)" GOARCH="$$goarch" CGO_ENABLED=0 cilium-agent; \
	install -D -m 0755 "$(CILIUM)/daemon/cilium-agent" "$(BUILD)/$$arch/cilium/bin/cilium-agent"

tetragon-x86 tetragon-arm64:
	arch="$(patsubst tetragon-%,%,$@)"; goarch=$$(test "$$arch" = x86 && echo amd64 || echo arm64); bpfarch=$$(test "$$arch" = x86 && echo x86 || echo arm64); \
	bpfroot="$(BUILD)/.tetragon-bpf/$$arch"; objdir="$$bpfroot/objs/"; depsdir="$$bpfroot/deps/"; install -d "$$bpfroot"; \
	$(GO_ENV) $(MAKE) -C "$(TETRAGON)" GO="$(GO)" TARGET_ARCH="$$goarch" GOARCH="$$goarch" tetragon; \
	install -D -m 0755 "$(TETRAGON)/tetragon" "$(BUILD)/$$arch/tetragon/bin/tetragon"; \
	$(MAKE) -C "$(TETRAGON)/bpf" CLANG="$(CLANG)" LLC="$(LLC)" BPF_TARGET_ARCH="$$bpfarch" OBJSDIR="$$objdir" DEPSDIR="$$depsdir" -j"$(JOBS)"; \
	install -d "$(BUILD)/$$arch/tetragon"; \
	cp -a "$$objdir/." "$(BUILD)/$$arch/tetragon/"

$(CACHE)/otelcol-ebpf-profiler-%.yaml:
	install -d "$(dir $@)"
	printf '%s\n' \
	  'dist:' '  name: otelcol-ebpf-profiler' '  output_path: $(CACHE)/otelcol-ebpf-profiler-build-$*' '  version: $(OTEL_VER)' '  otelcol_version: $(OTELCOL_VER)' \
	  'receivers:' '  - gomod: go.opentelemetry.io/ebpf-profiler v0.0.0' '    import: go.opentelemetry.io/ebpf-profiler/collector' '    path: $(OTEL)' \
	  'exporters:' '  - gomod: go.opentelemetry.io/collector/exporter/debugexporter v$(OTELCOL_VER)' \
	  'replaces:' '  - go.opentelemetry.io/ebpf-profiler => $(OTEL)' >"$@"

otel-x86 otel-arm64: otel-%: $(CACHE)/otelcol-ebpf-profiler-%.yaml
	goarch=$$(test "$*" = x86 && echo amd64 || echo arm64); cc=$$(test "$*" = arm64 && echo aarch64-linux-gnu-gcc || true); \
	$(GO_ENV) GOOS=linux GOARCH="$$goarch" CGO_ENABLED=0 CC="$$cc" "$(GO)" run "$(OCB)" --config "$<"; \
	install -D -m 0755 "$(CACHE)/otelcol-ebpf-profiler-build-$*/otelcol-ebpf-profiler" "$(BUILD)/$*/otelcol-ebpf-profiler/bin/otelcol-ebpf-profiler"

$(ARM64_SYSROOT)/.stamp:
	install -d "$(ARM64_DEBS)" "$(ARM64_SYSROOT)"
	if ! dpkg --print-foreign-architectures | grep -qx arm64; then sudo dpkg --add-architecture arm64; sudo apt-get update; fi
	cd "$(ARM64_DEBS)" && apt-get download $(ARM64_PKGS)
	for deb in "$(ARM64_DEBS)"/*.deb; do dpkg-deb -x "$$deb" "$(ARM64_SYSROOT)"; done
	install -d "$(ARM64_SYSROOT)/usr/lib/llvm-15/lib/cmake/clang"
	printf '%s\n' \
	  'get_filename_component(CLANG_INSTALL_PREFIX "$${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)' \
	  'set(CLANG_CMAKE_DIR "$${CMAKE_CURRENT_LIST_DIR}")' \
	  'set(CLANG_INCLUDE_DIRS "$${CLANG_INSTALL_PREFIX}/include")' \
	  'set(CLANG_EXPORTED_TARGETS libclang)' \
	  'if(NOT TARGET libclang)' \
	  '  add_library(libclang SHARED IMPORTED)' \
	  '  set_target_properties(libclang PROPERTIES IMPORTED_LOCATION "$${CLANG_INSTALL_PREFIX}/lib/libclang-15.so.1" IMPORTED_SONAME "libclang-15.so.1")' \
	  'endif()' >"$(ARM64_SYSROOT)/usr/lib/llvm-15/lib/cmake/clang/ClangConfig.cmake"
	touch "$@"

tracee-x86:
	@if file "$(BUILD)/x86/tracee/bin/tracee" 2>/dev/null | grep -q 'x86-64'; then exit 0; fi
	rm -f "$(TRACEE)/goenv.mk" "$(TRACEE)/.eval_goenv"
	$(MAKE) -C "$(TRACEE)" GO_ARCH=amd64 LINUX_ARCH=x86 ARCH=x86_64 CMD_GO="$(GO)" CMD_CLANG="$(CLANG)" CMD_GCC=gcc clean-tracee clean-bpf
	$(GO_ENV) $(MAKE) -C "$(TRACEE)" GO_ARCH=amd64 LINUX_ARCH=x86 ARCH=x86_64 CMD_GO="$(GO)" CMD_CLANG="$(CLANG)" CMD_GCC=gcc tracee
	file "$(TRACEE)/dist/tracee" | grep -q 'x86-64'
	install -D -m 0755 "$(TRACEE)/dist/tracee" "$(BUILD)/x86/tracee/bin/tracee"

$(BUILD)/.tracee-build/arm64/bin/tracee-arm64-cc:
	install -d "$(dir $@)"
	printf '%s\n' '#!/usr/bin/env bash' 'prev=' 'for arg in "$$@"; do' '  if [[ "$$prev" == "-target" && "$$arg" == "bpf" ]]; then exec clang-18 "$$@"; fi' '  prev="$$arg"' 'done' 'exec clang-18 --target=aarch64-linux-gnu "$$@"' >"$@"
	chmod +x "$@"

tracee-arm64: $(BUILD)/.tracee-build/arm64/bin/tracee-arm64-cc
	@if file "$(BUILD)/arm64/tracee/bin/tracee" 2>/dev/null | grep -q 'ARM aarch64'; then exit 0; fi
	rm -f "$(TRACEE)/goenv.mk" "$(TRACEE)/.eval_goenv"
	PATH="$(dir $<):$$PATH" $(MAKE) -C "$(TRACEE)" GO_ARCH=arm64 LINUX_ARCH=arm64 ARCH=arm64 CMD_GO="$(GO)" CMD_CLANG=tracee-arm64-cc CMD_GCC=aarch64-linux-gnu-gcc clean-tracee clean-bpf
	PATH="$(dir $<):$$PATH" $(GO_ENV) $(MAKE) -C "$(TRACEE)" GO_ARCH=arm64 LINUX_ARCH=arm64 ARCH=arm64 CMD_GO="$(GO)" CMD_CLANG=tracee-arm64-cc CMD_GCC=aarch64-linux-gnu-gcc tracee
	file "$(TRACEE)/dist/tracee" | grep -q 'ARM aarch64'
	install -D -m 0755 "$(TRACEE)/dist/tracee" "$(BUILD)/arm64/tracee/bin/tracee"

bcc-x86:
	install -d "$(BUILD)/.bcc-build/x86-llvm15"
	GIT_CONFIG_GLOBAL="$(BUILD)/.bcc-build/x86-llvm15/gitconfig" cmake -S "$(BCC)" -B "$(BUILD)/.bcc-build/x86-llvm15" -GNinja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="$(BUILD)/x86/bcc" -DNO_BLAZESYM=ON -DENABLE_EXAMPLES=OFF -DENABLE_MAN=OFF -DENABLE_TESTS=OFF -DENABLE_LLVM_SHARED=ON -DENABLE_LLVM_NATIVECODEGEN=OFF -DLLVM_DIR=/usr/lib/llvm-15/lib/cmake/llvm -DCLANG_DIR=/usr/lib/llvm-15 -DREVISION=0.29.1 -DREVISION_LAST=0.29.1 -DCMAKE_CXX_FLAGS= -DCMAKE_CXX_FLAGS_RELEASE='-O3 -DNDEBUG'
	GIT_CONFIG_GLOBAL="$(BUILD)/.bcc-build/x86-llvm15/gitconfig" cmake --build "$(BUILD)/.bcc-build/x86-llvm15" -j"$(JOBS)"
	GIT_CONFIG_GLOBAL="$(BUILD)/.bcc-build/x86-llvm15/gitconfig" cmake --install "$(BUILD)/.bcc-build/x86-llvm15"

bcc-arm64: $(ARM64_SYSROOT)/.stamp
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

KATRAN  := $(CURDIR)/repos/katran
BPF_OUT := $(CURDIR)/build/katran/bpf

katran-x86 katran-arm64 katran-bpf:
	cd $(KATRAN) && CLANG=clang ./build_bpf_modules_opensource.sh \
	  -s $(KATRAN) -b $(CURDIR)/build/katran -o $(BPF_OUT)

# ============================================================
# Disabled: full host C++ build of katran_server_grpc.
#
# katran_server_grpc is now committed prebuilt at
#   vendor/binary/katran/{x86_64,arm64}/bin/katran_server_grpc
# (extracted from docker images, stripped, 4.3M each, matches the
# runner-runtime ubuntu:24.04 base .so set).
#
# To rebuild from source, restore the recipes below + see
# vendor/repos/README.md katran section for host -dev prerequisites.
# Arm64 cross-build still needs aarch64-linux-gnu-gcc-13 +
# .cache/aarch64-toolchain.cmake.
# ============================================================
#
# ARM_TC  := $(CURDIR)/../.cache/aarch64-toolchain.cmake
# ARM_FOLLY_EXITS := -DFOLLY_HAVE_UNALIGNED_ACCESS_EXITCODE=0 -DFOLLY_HAVE_WEAK_SYMBOLS_EXITCODE=0 -DFOLLY_HAVE_LINUX_VDSO_EXITCODE=0 -DFOLLY_HAVE_WCHAR_SUPPORT_EXITCODE=0 -DHAVE_VSNPRINTF_ERRORS_EXITCODE=0
# COMMON_CMAKE := -DCMAKE_BUILD_TYPE=RelWithDebInfo -DPKG_CONFIG_USE_CMAKE_PREFIX_PATH=ON -DGFLAGS_SHARED=ON -DGFLAGS_NOTHREADS=OFF -DCMAKE_CXX_STANDARD=20 -DCMAKE_CXX_FLAGS=-fpermissive -DGLOG_INCLUDE_DIR=/usr/include -DBUILD_TESTS=OFF -DOPENSSL_NO_ASM=ON
#
# katran-x86-server:
# 	cd $(KATRAN) && env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR \
# 	  CC=clang CXX=clang++ AR=ar RANLIB=ranlib NCPUS=4 \
# 	  KATRAN_SKIP_SYSTEM_PACKAGES=1 BUILD_EXAMPLE_GRPC=0 \
# 	  BUILD_DIR=$(CURDIR)/build/x86/katran/build INSTALL_DIR=$(CURDIR)/build/x86/katran/install \
# 	  INSTALL_DEPS_ONLY=1 ./build_katran.sh
# 	-sed -i -e 's#gflags_nothreads_static#/usr/lib/x86_64-linux-gnu/libgflags.so#g' \
# 	        -e 's#gflags_static#/usr/lib/x86_64-linux-gnu/libgflags.so#g' \
# 	        $(CURDIR)/build/x86/katran/install/lib/cmake/folly/folly-targets*.cmake \
# 	        $(CURDIR)/build/x86/katran/install/lib64/cmake/folly/folly-targets*.cmake
# 	env CMAKE_BUILD_EXAMPLE_GRPC=1 cmake -S $(KATRAN) -B $(CURDIR)/build/x86/katran/build/build \
# 	  -DCMAKE_PREFIX_PATH=$(CURDIR)/build/x86/katran/install -DCMAKE_INSTALL_PREFIX=$(CURDIR)/build/x86/katran/install \
# 	  -DLIB_BPF_PREFIX=$(CURDIR)/build/x86/katran/install \
# 	  -DLIBELF=/usr/lib/x86_64-linux-gnu/libelf.so \
# 	  -DGLOG_LIBRARY=/usr/lib/x86_64-linux-gnu/libglog.so \
# 	  -Dgflags_DIR=/usr/lib/x86_64-linux-gnu/cmake/gflags \
# 	  -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ \
# 	  $(COMMON_CMAKE)
# 	cmake --build $(CURDIR)/build/x86/katran/build/build --target install -j4
#
# katran-arm64-server:
# 	cd $(KATRAN) && env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR \
# 	  CC=aarch64-linux-gnu-gcc-13 CXX=aarch64-linux-gnu-g++-13 \
# 	  AR=aarch64-linux-gnu-ar RANLIB=aarch64-linux-gnu-ranlib NCPUS=4 \
# 	  KATRAN_SKIP_SYSTEM_PACKAGES=1 BUILD_EXAMPLE_GRPC=0 \
# 	  KATRAN_EXTRA_CMAKE_ARGS="-DCMAKE_TOOLCHAIN_FILE=$(ARM_TC) $(ARM_FOLLY_EXITS)" \
# 	  BUILD_DIR=$(CURDIR)/build/arm64/katran/build INSTALL_DIR=$(CURDIR)/build/arm64/katran/install \
# 	  INSTALL_DEPS_ONLY=1 ./build_katran.sh
# 	-sed -i -e 's#gflags_nothreads_static#/usr/lib/aarch64-linux-gnu/libgflags.so#g' \
# 	        -e 's#gflags_static#/usr/lib/aarch64-linux-gnu/libgflags.so#g' \
# 	        $(CURDIR)/build/arm64/katran/install/lib/cmake/folly/folly-targets*.cmake \
# 	        $(CURDIR)/build/arm64/katran/install/lib64/cmake/folly/folly-targets*.cmake
# 	env CMAKE_BUILD_EXAMPLE_GRPC=1 cmake -S $(KATRAN) -B $(CURDIR)/build/arm64/katran/build/build \
# 	  -DCMAKE_TOOLCHAIN_FILE=$(ARM_TC) \
# 	  -DCMAKE_PREFIX_PATH=$(CURDIR)/build/arm64/katran/install -DCMAKE_INSTALL_PREFIX=$(CURDIR)/build/arm64/katran/install \
# 	  -DLIB_BPF_PREFIX=$(CURDIR)/build/arm64/katran/install \
# 	  -DLIBELF=/usr/lib/aarch64-linux-gnu/libelf.so \
# 	  -DGLOG_LIBRARY=/usr/lib/aarch64-linux-gnu/libglog.so \
# 	  -Dgflags_DIR=/usr/lib/aarch64-linux-gnu/cmake/gflags \
# 	  -D_PROTOBUF_PROTOC=/usr/bin/protoc -D_gRPC_CPP_PLUGIN=/usr/bin/grpc_cpp_plugin \
# 	  $(COMMON_CMAKE)
# 	cmake --build $(CURDIR)/build/arm64/katran/build/build --target install -j4
