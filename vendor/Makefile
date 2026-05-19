# vendor/Makefile — katran BPF bytecode build entry points.
#
# katran_server_grpc itself is committed prebuilt under
# vendor/binary/katran/{x86_64,arm64}/bin/, extracted from the
# bpf-benchmark/katran-artifacts:{x86_64,arm64} docker images and
# stripped. To rebuild it from source see repos/README.md katran
# section + the commented cmake recipe at the bottom of this file.
#
# `make katran-x86` / `make katran-arm64` only (re)builds the BPF
# bytecode (.bpf.o), which is fast and architecture-neutral.

.PHONY: katran-x86 katran-arm64 katran-bpf

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
