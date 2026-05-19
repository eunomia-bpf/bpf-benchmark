# vendor/Makefile — katran build entry points (no Docker, host clang
# for x86, aarch64-linux-gnu-gcc-13 for arm64 cross). See repos/README.md
# katran section for host prerequisites (apt :amd64+:arm64 -dev packages,
# multiarch version alignment, and why we drop the cross-built grpc 1.49).

.PHONY: katran-x86 katran-arm64

KATRAN  := $(CURDIR)/repos/katran
X86_OUT := $(CURDIR)/build/x86/katran
ARM_OUT := $(CURDIR)/build/arm64/katran
ARM_TC  := $(CURDIR)/../.cache/aarch64-toolchain.cmake

# folly's check_cxx_source_runs() probes need cached exit codes when
# cross-compiling (try_run can't execute the arm64 binary on x86 host).
ARM_FOLLY_EXITS := -DFOLLY_HAVE_UNALIGNED_ACCESS_EXITCODE=0 -DFOLLY_HAVE_WEAK_SYMBOLS_EXITCODE=0 -DFOLLY_HAVE_LINUX_VDSO_EXITCODE=0 -DFOLLY_HAVE_WCHAR_SUPPORT_EXITCODE=0 -DHAVE_VSNPRINTF_ERRORS_EXITCODE=0

COMMON_CMAKE := -DCMAKE_BUILD_TYPE=RelWithDebInfo -DPKG_CONFIG_USE_CMAKE_PREFIX_PATH=ON -DGFLAGS_SHARED=ON -DGFLAGS_NOTHREADS=OFF -DCMAKE_CXX_STANDARD=20 -DCMAKE_CXX_FLAGS=-fpermissive -DGLOG_INCLUDE_DIR=/usr/include -DBUILD_TESTS=OFF -DOPENSSL_NO_ASM=ON

katran-x86:
	cd $(KATRAN) && env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR \
	  CC=clang CXX=clang++ AR=ar RANLIB=ranlib NCPUS=4 \
	  KATRAN_SKIP_SYSTEM_PACKAGES=1 BUILD_EXAMPLE_GRPC=1 \
	  BUILD_DIR=$(X86_OUT)/build INSTALL_DIR=$(X86_OUT)/install \
	  INSTALL_DEPS_ONLY=1 ./build_katran.sh
	-sed -i -e 's#gflags_nothreads_static#/usr/lib/x86_64-linux-gnu/libgflags.so#g' \
	        -e 's#gflags_static#/usr/lib/x86_64-linux-gnu/libgflags.so#g' \
	        $(X86_OUT)/install/lib/cmake/folly/folly-targets*.cmake \
	        $(X86_OUT)/install/lib64/cmake/folly/folly-targets*.cmake
	rm -rf $(X86_OUT)/build/build
	env CMAKE_BUILD_EXAMPLE_GRPC=1 cmake -S $(KATRAN) -B $(X86_OUT)/build/build \
	  -DCMAKE_PREFIX_PATH=$(X86_OUT)/install -DCMAKE_INSTALL_PREFIX=$(X86_OUT)/install \
	  -DLIB_BPF_PREFIX=$(X86_OUT)/install \
	  -DLIBELF=/usr/lib/x86_64-linux-gnu/libelf.so \
	  -DGLOG_LIBRARY=/usr/lib/x86_64-linux-gnu/libglog.so \
	  -Dgflags_DIR=/usr/lib/x86_64-linux-gnu/cmake/gflags \
	  -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ \
	  $(COMMON_CMAKE)
	cmake --build $(X86_OUT)/build/build --target install -j4
	mkdir -p $(X86_OUT)/install/bpf
	cd $(KATRAN) && CLANG=clang ./build_bpf_modules_opensource.sh -s $(KATRAN) -b $(X86_OUT)/build -o $(X86_OUT)/install/bpf
	cd $(X86_OUT)/install/bpf && mv -f healthchecking_ipip.o healthchecking_ipip.bpf.o && mv -f xdp_root.o xdp_root.bpf.o

katran-arm64:
	cd $(KATRAN) && env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR \
	  CC=aarch64-linux-gnu-gcc-13 CXX=aarch64-linux-gnu-g++-13 \
	  AR=aarch64-linux-gnu-ar RANLIB=aarch64-linux-gnu-ranlib NCPUS=4 \
	  KATRAN_SKIP_SYSTEM_PACKAGES=1 BUILD_EXAMPLE_GRPC=1 \
	  KATRAN_EXTRA_CMAKE_ARGS="-DCMAKE_TOOLCHAIN_FILE=$(ARM_TC) $(ARM_FOLLY_EXITS) -D_PROTOBUF_PROTOC=/usr/bin/protoc -D_gRPC_CPP_PLUGIN=/usr/bin/grpc_cpp_plugin" \
	  BUILD_DIR=$(ARM_OUT)/build INSTALL_DIR=$(ARM_OUT)/install \
	  INSTALL_DEPS_ONLY=1 ./build_katran.sh
	rm -rf $(ARM_OUT)/install/include/grpc $(ARM_OUT)/install/include/grpcpp \
	       $(ARM_OUT)/install/lib/libgrpc* $(ARM_OUT)/install/lib/libgpr* \
	       $(ARM_OUT)/install/lib/libupb* $(ARM_OUT)/install/lib/libaddress_sorting* \
	       $(ARM_OUT)/install/lib/cmake/grpc $(ARM_OUT)/install/lib/pkgconfig/grpc*
	-sed -i -e 's#gflags_nothreads_static#/usr/lib/aarch64-linux-gnu/libgflags.so#g' \
	        -e 's#gflags_static#/usr/lib/aarch64-linux-gnu/libgflags.so#g' \
	        $(ARM_OUT)/install/lib/cmake/folly/folly-targets*.cmake \
	        $(ARM_OUT)/install/lib64/cmake/folly/folly-targets*.cmake
	rm -rf $(ARM_OUT)/build/build
	env CMAKE_BUILD_EXAMPLE_GRPC=1 cmake -S $(KATRAN) -B $(ARM_OUT)/build/build \
	  -DCMAKE_TOOLCHAIN_FILE=$(ARM_TC) \
	  -DCMAKE_PREFIX_PATH=$(ARM_OUT)/install -DCMAKE_INSTALL_PREFIX=$(ARM_OUT)/install \
	  -DLIB_BPF_PREFIX=$(ARM_OUT)/install \
	  -DLIBELF=/usr/lib/aarch64-linux-gnu/libelf.so \
	  -DGLOG_LIBRARY=/usr/lib/aarch64-linux-gnu/libglog.so \
	  -Dgflags_DIR=/usr/lib/aarch64-linux-gnu/cmake/gflags \
	  -D_PROTOBUF_PROTOC=/usr/bin/protoc -D_gRPC_CPP_PLUGIN=/usr/bin/grpc_cpp_plugin \
	  $(COMMON_CMAKE)
	cmake --build $(ARM_OUT)/build/build --target install -j4
	mkdir -p $(ARM_OUT)/install/bpf
	cd $(KATRAN) && CLANG=clang ./build_bpf_modules_opensource.sh -s $(KATRAN) -b $(ARM_OUT)/build -o $(ARM_OUT)/install/bpf
	cd $(ARM_OUT)/install/bpf && mv -f healthchecking_ipip.o healthchecking_ipip.bpf.o && mv -f xdp_root.o xdp_root.bpf.o
