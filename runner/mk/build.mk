REPOS_DIR := $(ROOT_DIR)/vendor/repos
RUNNER_CONTAINER_DIR := $(RUNNER_DIR)/containers
RUN_TARGET_ARCH ?= x86_64
IMAGE_BUILD_JOBS ?= $(JOBS)

MICRO_PROGRAM_DIR := $(ROOT_DIR)/micro/programs
STAGE2_PROGRAM_DIR := $(ROOT_DIR)/native-sim/test
MICRO_PROGRAM_BUILD_X86 := $(MICRO_PROGRAM_DIR)/build-x86
MICRO_PROGRAM_BUILD_ARM64 := $(MICRO_PROGRAM_DIR)/build-arm64
STAGE2_PROGRAM_BUILD_X86 := $(STAGE2_PROGRAM_DIR)/build-x86
STAGE2_PROGRAM_BUILD_ARM64 := $(STAGE2_PROGRAM_DIR)/build-arm64
UNITTEST_BUILD_X86 := $(ROOT_DIR)/tests/unittest/build
UNITTEST_BUILD_ARM64 := $(ROOT_DIR)/tests/unittest/build-arm64
NEGATIVE_BUILD_X86 := $(ROOT_DIR)/tests/negative/build
NEGATIVE_BUILD_ARM64 := $(ROOT_DIR)/tests/negative/build-arm64
VENDOR_BUILD_DIR := $(ROOT_DIR)/vendor/build
RUNTIME_LIBS_X86 := $(VENDOR_BUILD_DIR)/x86/runtime-libs
RUNTIME_LIBS_ARM64 := $(VENDOR_BUILD_DIR)/arm64/runtime-libs

DEFAULT_RUNNER_LLVM_DIR := /usr/lib/llvm-18/lib/cmake/llvm
RUNNER_LLVM_DIR := $(if $(strip $(LLVM_DIR)),$(LLVM_DIR),$(if $(strip $(RUN_LLVM_DIR)),$(RUN_LLVM_DIR),$(DEFAULT_RUNNER_LLVM_DIR)))
RUNNER_LIBBPF_CFLAGS := -O2 -Werror -Wall -std=gnu89
ARM64_RUNNER_LLVM_SYSROOT := $(ROOT_DIR)/.cache/sysroots/arm64-llvm17
ARM64_RUNNER_LLVM_DIR := $(ARM64_RUNNER_LLVM_SYSROOT)/usr/lib/llvm-17/lib/cmake/llvm
ARM64_PKG_CONFIG_LIBDIR = $(AARCH64_SYSROOT_DIR)/usr/lib/aarch64-linux-gnu/pkgconfig
ARM64_SYS_INCLUDE_FLAGS = -I/usr/aarch64-linux-gnu/include -I$(AARCH64_SYSROOT_DIR)/usr/include -I$(AARCH64_SYSROOT_DIR)/usr/include/aarch64-linux-gnu

CONTAINER_IMAGE_ARTIFACT_ROOT := $(ARTIFACT_ROOT)/container-images

ARM64_RUST_TARGET := aarch64-unknown-linux-gnu
NATIVE_LINK_DIR := $(ROOT_DIR)/native-sim/x86/native_lab/native_link

RUNNER_RUNTIME_CONTAINERFILE := $(RUNNER_CONTAINER_DIR)/runner-runtime.Dockerfile
BPFOPT_SHIM_DIR := $(ROOT_DIR)/bpfopt/shim
BPFOPT_SHIM_BUILD_X86 := $(BPFOPT_SHIM_DIR)/build-x86
BPFOPT_SHIM_BUILD_ARM64 := $(BPFOPT_SHIM_DIR)/build-arm64

X86_RUNNER_RUNTIME_IMAGE := bpf-benchmark/runner-runtime:x86_64
ARM64_RUNNER_RUNTIME_IMAGE := bpf-benchmark/runner-runtime:arm64

X86_RUNNER_RUNTIME_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/x86_64-runner-runtime.image.tar
ARM64_RUNNER_RUNTIME_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/arm64-runner-runtime.image.tar

X86_RUNTIME_KERNEL_IMAGE := $(VENDOR_BUILD_DIR)/x86/linux/arch/x86/boot/bzImage
HOST_GO ?= $(or $(GO),go)
HOST_KERNEL_BUILD_DIR_X86 := $(VENDOR_BUILD_DIR)/x86/linux
HOST_KERNEL_BUILD_DIR_ARM64 := $(VENDOR_BUILD_DIR)/arm64/linux
HOST_KINSN_DIR_X86 := $(ROOT_DIR)/module/x86/build
HOST_KINSN_DIR_ARM64 := $(ROOT_DIR)/module/arm64/build
MICRO_PROGRAM_KINSN_ARGS := \
	$(if $(strip $(BPFREJIT_MICRO_BPF_COMPILER)),BPFREJIT_MICRO_BPF_COMPILER="$(BPFREJIT_MICRO_BPF_COMPILER)") \
	$(if $(strip $(BPF_KINSN_LLC)),BPF_KINSN_LLC="$(BPF_KINSN_LLC)") \
	$(if $(strip $(BPF_KINSN_LLC_FLAGS)),BPF_KINSN_LLC_FLAGS="$(BPF_KINSN_LLC_FLAGS)") \
	$(if $(strip $(BPF_KINSN_TRIPLE)),BPF_KINSN_TRIPLE="$(BPF_KINSN_TRIPLE)") \
	$(if $(strip $(BPF_KINSN_CPU)),BPF_KINSN_CPU="$(BPF_KINSN_CPU)")

.PHONY: \
	host-kernel-x86 host-kernel-arm64 \
	host-kinsn-x86 host-kinsn-arm64 host-rust-x86 host-rust-arm64 \
	host-shim-x86 host-shim-arm64 host-shim-artifacts \
	host-runner-x86 host-runner-arm64 host-micro-programs-x86 host-micro-programs-arm64 \
	host-stage2-programs-x86 host-stage2-programs-arm64 \
	host-unittest-x86 host-unittest-arm64 host-negative-x86 host-negative-arm64 \
	host-runtime-libs-x86 host-runtime-libs-arm64 \
	apps host-source-apps host-source-apps-x86 host-source-apps-arm64 \
	aarch64-sysroot runtime-kernel-image \
	x86-runner-runtime-image-tar arm64-runner-runtime-image-tar image-runner-runtime-image-tar

apps: host-source-apps
host-source-apps: host-source-apps-x86 host-source-apps-arm64
host-source-apps-x86:
	$(MAKE) -C "$(ROOT_DIR)/vendor" apps-x86 GO="$(HOST_GO)" JOBS="$(JOBS)"
host-source-apps-arm64:
	$(MAKE) -C "$(ROOT_DIR)/vendor" apps-arm64 GO="$(HOST_GO)" JOBS="$(JOBS)"

host-kernel-x86:
	install -d "$(HOST_KERNEL_BUILD_DIR_X86)"
	cp "$(DEFCONFIG_SRC)" "$(HOST_KERNEL_BUILD_DIR_X86)/.config"
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_X86)" ARCH=x86_64 olddefconfig
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_X86)" ARCH=x86_64 bzImage modules -j"$(IMAGE_BUILD_JOBS)"
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_X86)" ARCH=x86_64 INSTALL_MOD_PATH="$(HOST_KERNEL_BUILD_DIR_X86)/modules-install" INSTALL_MOD_STRIP=1 DEPMOD=true modules_install >/dev/null
	rel=$$(cat "$(HOST_KERNEL_BUILD_DIR_X86)/include/config/kernel.release"); \
		printf '{"kernel_release":"%s","target_arch":"x86_64","kernel_image":"bzImage"}\n' "$$rel" >"$(HOST_KERNEL_BUILD_DIR_X86)/manifest.json"

host-kernel-arm64:
	@command -v aarch64-linux-gnu-gcc >/dev/null
	install -d "$(HOST_KERNEL_BUILD_DIR_ARM64)"
	cp "$(ARM64_DEFCONFIG_SRC)" "$(HOST_KERNEL_BUILD_DIR_ARM64)/.config"
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_ARM64)" ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- olddefconfig
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_ARM64)" ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- Image vmlinuz.efi modules -j"$(IMAGE_BUILD_JOBS)"
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_ARM64)" ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- INSTALL_MOD_PATH="$(HOST_KERNEL_BUILD_DIR_ARM64)/modules-install" INSTALL_MOD_STRIP=1 DEPMOD=true modules_install >/dev/null
	rel=$$(cat "$(HOST_KERNEL_BUILD_DIR_ARM64)/include/config/kernel.release"); \
		printf '{"kernel_release":"%s","target_arch":"arm64","kernel_image":"vmlinuz.efi"}\n' "$$rel" >"$(HOST_KERNEL_BUILD_DIR_ARM64)/manifest.json"

host-kinsn-x86: host-kernel-x86
	install -d "$(HOST_KINSN_DIR_X86)"
	$(MAKE) -C "$(HOST_KERNEL_BUILD_DIR_X86)" ARCH=x86_64 M="$(ROOT_DIR)/module/x86" MO="$(HOST_KINSN_DIR_X86)" modules -j"$(IMAGE_BUILD_JOBS)"

host-kinsn-arm64: host-kernel-arm64
	@command -v aarch64-linux-gnu-gcc >/dev/null
	install -d "$(HOST_KINSN_DIR_ARM64)"
	$(MAKE) -C "$(HOST_KERNEL_BUILD_DIR_ARM64)" ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- M="$(ROOT_DIR)/module/arm64" MO="$(HOST_KINSN_DIR_ARM64)" modules -j"$(IMAGE_BUILD_JOBS)"

host-rust-x86:
	cargo build --release --workspace --target-dir "$(ROOT_DIR)/bpfopt/target" --manifest-path "$(ROOT_DIR)/bpfopt/Cargo.toml" -p bpfopt -p kinsnprober
	cargo build --release --manifest-path "$(NATIVE_LINK_DIR)/Cargo.toml"

AARCH64_SYSROOT_DIR := $(ROOT_DIR)/.cache/aarch64-sysroot
AARCH64_SYSROOT_DEB_PACKAGES := libzstd1:arm64 libelf1t64:arm64 libelf-dev:arm64 zlib1g:arm64 zlib1g-dev:arm64 libzstd-dev:arm64 \
	libyaml-cpp0.8:arm64 libyaml-cpp-dev:arm64 libspdlog1.15:arm64 libspdlog-dev:arm64 libfmt10:arm64 libfmt-dev:arm64
ARM64_CARGO_RUSTFLAGS := -C link-arg=--sysroot=$(AARCH64_SYSROOT_DIR) -C link-arg=-L$(AARCH64_SYSROOT_DIR)/usr/lib/aarch64-linux-gnu -C link-arg=-Wl,-rpath-link=$(AARCH64_SYSROOT_DIR)/usr/lib/aarch64-linux-gnu
ARM64_CARGO_ENV := \
	CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER=aarch64-linux-gnu-gcc \
	CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_RUSTFLAGS="$(ARM64_CARGO_RUSTFLAGS)"

aarch64-sysroot: $(AARCH64_SYSROOT_DIR)/usr/include/libelf.h $(AARCH64_SYSROOT_DIR)/usr/include/yaml-cpp/yaml.h $(AARCH64_SYSROOT_DIR)/usr/include/spdlog/spdlog.h

$(AARCH64_SYSROOT_DIR)/usr/include/libelf.h $(AARCH64_SYSROOT_DIR)/usr/include/yaml-cpp/yaml.h $(AARCH64_SYSROOT_DIR)/usr/include/spdlog/spdlog.h &:
	command -v aarch64-linux-gnu-gcc >/dev/null || { echo "aarch64-linux-gnu-gcc missing; install gcc-aarch64-linux-gnu" >&2; exit 1; }; \
	command -v dpkg-deb >/dev/null; \
	command -v apt-get >/dev/null; \
	install -d "$(AARCH64_SYSROOT_DIR)/.debs"; \
	cd "$(AARCH64_SYSROOT_DIR)/.debs" && apt-get download $(AARCH64_SYSROOT_DEB_PACKAGES); \
	for d in "$(AARCH64_SYSROOT_DIR)"/.debs/*.deb; do dpkg-deb -x "$$d" "$(AARCH64_SYSROOT_DIR)"; done

host-rust-arm64: aarch64-sysroot
	$(ARM64_CARGO_ENV) cargo build --release --workspace --target "$(ARM64_RUST_TARGET)" --target-dir "$(ROOT_DIR)/bpfopt/target" --manifest-path "$(ROOT_DIR)/bpfopt/Cargo.toml" -p bpfopt -p kinsnprober
	cargo build --release --manifest-path "$(NATIVE_LINK_DIR)/Cargo.toml"

host-shim-x86:
	install -d "$(BPFOPT_SHIM_BUILD_X86)"
	$(MAKE) -C "$(BPFOPT_SHIM_DIR)" CC=gcc SHIM_SO="$(BPFOPT_SHIM_BUILD_X86)/libbpfrejit_shim.so" "$(BPFOPT_SHIM_BUILD_X86)/libbpfrejit_shim.so"

host-shim-arm64:
	command -v aarch64-linux-gnu-gcc >/dev/null
	install -d "$(BPFOPT_SHIM_BUILD_ARM64)"
	$(MAKE) -C "$(BPFOPT_SHIM_DIR)" CC=aarch64-linux-gnu-gcc SHIM_SO="$(BPFOPT_SHIM_BUILD_ARM64)/libbpfrejit_shim.so" "$(BPFOPT_SHIM_BUILD_ARM64)/libbpfrejit_shim.so"

host-shim-artifacts: host-shim-x86 host-shim-arm64

host-runner-x86: RUNNER_BUILD_DIR_ARCH := $(RUNNER_DIR)/build-llvmbpf
host-runner-x86: RUNNER_CC := gcc
host-runner-x86: RUNNER_CXX := g++
host-runner-x86: RUNNER_LIBBPF_ENV := CC=gcc
host-runner-x86: RUNNER_STRIP := strip
host-runner-x86: RUNNER_LLVM_DIR_ARCH := $(RUNNER_LLVM_DIR)
host-runner-x86: RUNNER_KERNEL_OFFSETS_INCLUDE := $(MICRO_PROGRAM_BUILD_X86)
host-runner-arm64: RUNNER_BUILD_DIR_ARCH := $(RUNNER_DIR)/build-arm64-llvmbpf
host-runner-arm64: RUNNER_CC := aarch64-linux-gnu-gcc
host-runner-arm64: RUNNER_CXX := aarch64-linux-gnu-g++
host-runner-arm64: RUNNER_LIBBPF_ENV := CC=aarch64-linux-gnu-gcc LD=aarch64-linux-gnu-ld AR=aarch64-linux-gnu-ar
host-runner-arm64: RUNNER_STRIP := aarch64-linux-gnu-strip
host-runner-arm64: RUNNER_LLVM_DIR_ARCH := $(ARM64_RUNNER_LLVM_DIR)
host-runner-arm64: RUNNER_KERNEL_OFFSETS_INCLUDE := $(MICRO_PROGRAM_BUILD_ARM64)
host-runner-arm64: RUNNER_CMAKE_CROSS := -DCMAKE_SYSTEM_NAME=Linux -DCMAKE_SYSTEM_PROCESSOR=aarch64 -DCMAKE_FIND_ROOT_PATH="$(AARCH64_SYSROOT_DIR);$(ARM64_RUNNER_LLVM_SYSROOT);/usr/aarch64-linux-gnu" -DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER -DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=BOTH -DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=BOTH -DCMAKE_FIND_ROOT_PATH_MODE_PACKAGE=BOTH -DCMAKE_EXE_LINKER_FLAGS="-L$(AARCH64_SYSROOT_DIR)/usr/lib/aarch64-linux-gnu -L$(ARM64_RUNNER_LLVM_SYSROOT)/usr/lib/aarch64-linux-gnu -Wl,-rpath-link,$(AARCH64_SYSROOT_DIR)/usr/lib/aarch64-linux-gnu -Wl,-rpath-link,$(ARM64_RUNNER_LLVM_SYSROOT)/usr/lib/aarch64-linux-gnu -Wl,-rpath-link,$(ARM64_RUNNER_LLVM_SYSROOT)/usr/lib/llvm-17/lib"
host-runner-arm64: RUNNER_PKG_CONFIG := PKG_CONFIG_LIBDIR="$(ARM64_PKG_CONFIG_LIBDIR)" PKG_CONFIG_SYSROOT_DIR="$(AARCH64_SYSROOT_DIR)"
host-runner-x86: host-micro-programs-x86
host-runner-arm64: aarch64-sysroot host-source-apps-arm64 host-micro-programs-arm64
host-runner-x86 host-runner-arm64:
	$(MAKE) -C "$(ROOT_DIR)/vendor/libbpf/src" -j"$(JOBS)" BUILD_STATIC_ONLY=1 $(RUNNER_LIBBPF_ENV) CFLAGS="$(RUNNER_LIBBPF_CFLAGS)" OBJDIR="$(RUNNER_BUILD_DIR_ARCH)/vendor/libbpf/obj" DESTDIR= PREFIX="$(RUNNER_BUILD_DIR_ARCH)/vendor/libbpf/prefix" "$(RUNNER_BUILD_DIR_ARCH)/vendor/libbpf/obj/libbpf.a" install_headers
	$(RUNNER_PKG_CONFIG) cmake -S "$(RUNNER_DIR)" -B "$(RUNNER_BUILD_DIR_ARCH)" -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER="$(RUNNER_CC)" -DCMAKE_CXX_COMPILER="$(RUNNER_CXX)" -DMICRO_REPO_ROOT="$(ROOT_DIR)" -DMICRO_LIBBPF_PREFIX="$(RUNNER_BUILD_DIR_ARCH)/vendor/libbpf/prefix" -DMICRO_LIBBPF_LIBRARY="$(RUNNER_BUILD_DIR_ARCH)/vendor/libbpf/obj/libbpf.a" -DMICRO_KERNEL_OFFSETS_INCLUDE="$(RUNNER_KERNEL_OFFSETS_INCLUDE)" -DMICRO_EXEC_ENABLE_LLVMBPF=1 -DLLVM_DIR="$(RUNNER_LLVM_DIR_ARCH)" $(RUNNER_CMAKE_CROSS)
	cmake --build "$(RUNNER_BUILD_DIR_ARCH)" --target micro_exec -j"$(JOBS)"
	$(RUNNER_STRIP) --strip-unneeded "$(RUNNER_BUILD_DIR_ARCH)/micro_exec"

host-micro-programs-x86: host-kernel-x86
	$(MAKE) -C "$(MICRO_PROGRAM_DIR)" OUTPUT_DIR="$(MICRO_PROGRAM_BUILD_X86)" KERNEL_VMLINUX="$(HOST_KERNEL_BUILD_DIR_X86)/vmlinux" $(MICRO_PROGRAM_KINSN_ARGS) all

host-micro-programs-arm64: host-kernel-arm64
	$(MAKE) -C "$(MICRO_PROGRAM_DIR)" OUTPUT_DIR="$(MICRO_PROGRAM_BUILD_ARM64)" KERNEL_VMLINUX="$(HOST_KERNEL_BUILD_DIR_ARM64)/vmlinux" NATIVE_TARGET=aarch64-linux-gnu NATIVE_ARCH=arm64 SYS_INCLUDE_FLAGS="$(ARM64_SYS_INCLUDE_FLAGS)" $(MICRO_PROGRAM_KINSN_ARGS) all

host-stage2-programs-x86: host-micro-programs-x86
	$(MAKE) -C "$(STAGE2_PROGRAM_DIR)" OUTPUT_DIR="$(STAGE2_PROGRAM_BUILD_X86)" KERNEL_OFFSETS="$(MICRO_PROGRAM_BUILD_X86)/kernel_offsets.h" all

host-stage2-programs-arm64: host-micro-programs-arm64
	$(MAKE) -C "$(STAGE2_PROGRAM_DIR)" OUTPUT_DIR="$(STAGE2_PROGRAM_BUILD_ARM64)" KERNEL_OFFSETS="$(MICRO_PROGRAM_BUILD_ARM64)/kernel_offsets.h" NATIVE_TARGET=aarch64-linux-gnu NATIVE_ARCH=arm64 SYS_INCLUDE_FLAGS="$(ARM64_SYS_INCLUDE_FLAGS)" all

host-unittest-x86: host-kernel-x86
	$(MAKE) -C "$(ROOT_DIR)/tests/unittest" BUILD_DIR="$(UNITTEST_BUILD_X86)" CC=gcc CLANG=clang BPF_TARGET_ARCH=x86_64 VMLINUX_BTF="$(HOST_KERNEL_BUILD_DIR_X86)/vmlinux" all

host-unittest-arm64: host-kernel-arm64
	$(MAKE) -C "$(ROOT_DIR)/tests/unittest" BUILD_DIR="$(UNITTEST_BUILD_ARM64)" CC=aarch64-linux-gnu-gcc CLANG=clang BPF_TARGET_ARCH=arm64 VMLINUX_BTF="$(HOST_KERNEL_BUILD_DIR_ARM64)/vmlinux" SYS_INCLUDE_FLAGS="$(ARM64_SYS_INCLUDE_FLAGS)" all

host-negative-x86:
	install -d "$(NEGATIVE_BUILD_X86)"
	$(MAKE) -C "$(ROOT_DIR)/tests/negative" BUILD_DIR="$(NEGATIVE_BUILD_X86)" CC=gcc all

host-negative-arm64:
	install -d "$(NEGATIVE_BUILD_ARM64)"
	$(MAKE) -C "$(ROOT_DIR)/tests/negative" BUILD_DIR="$(NEGATIVE_BUILD_ARM64)" CC=aarch64-linux-gnu-gcc all

host-runtime-libs-x86:
	install -d "$(RUNTIME_LIBS_X86)"
	touch "$(RUNTIME_LIBS_X86)/.keep"

host-runtime-libs-arm64: aarch64-sysroot
	install -d "$(RUNTIME_LIBS_ARM64)"
	touch "$(RUNTIME_LIBS_ARM64)/.keep"
	cp -a "$(AARCH64_SYSROOT_DIR)/usr/lib/aarch64-linux-gnu"/libspdlog.so* "$(RUNTIME_LIBS_ARM64)/"
	cp -a "$(AARCH64_SYSROOT_DIR)/usr/lib/aarch64-linux-gnu"/libfmt.so* "$(RUNTIME_LIBS_ARM64)/"
	cp -a "$(ARM64_RUNNER_LLVM_SYSROOT)/usr/lib/aarch64-linux-gnu"/libbfd*.so* "$(RUNTIME_LIBS_ARM64)/"
	cp -a "$(ARM64_RUNNER_LLVM_SYSROOT)/usr/lib/aarch64-linux-gnu"/libopcodes*.so* "$(RUNTIME_LIBS_ARM64)/"
	cp -a "$(ARM64_RUNNER_LLVM_SYSROOT)/usr/lib/aarch64-linux-gnu"/libsframe.so* "$(RUNTIME_LIBS_ARM64)/"

x86-runner-runtime-image-tar: host-kernel-x86 host-kinsn-x86 host-rust-x86 host-shim-x86 host-source-apps-x86 host-runner-x86 host-micro-programs-x86 host-stage2-programs-x86 host-unittest-x86 host-negative-x86 host-runtime-libs-x86
	install -d "$(CONTAINER_IMAGE_ARTIFACT_ROOT)"
	docker build --platform linux/amd64 \
		--target runner-runtime \
		--build-context runner-runtime-host-runner-build="$(RUNNER_DIR)/build-llvmbpf" \
		--build-context runner-runtime-host-micro-programs="$(MICRO_PROGRAM_BUILD_X86)" \
		--build-context runner-runtime-host-stage2-programs="$(STAGE2_PROGRAM_BUILD_X86)" \
		--build-context runner-runtime-host-unittest="$(ROOT_DIR)/tests/unittest/build" \
		--build-context runner-runtime-host-negative="$(ROOT_DIR)/tests/negative/build" \
		--build-context runner-runtime-host-kernel-image="$(HOST_KERNEL_BUILD_DIR_X86)/arch/x86/boot" \
		--build-context runner-runtime-host-kernel-offsets="$(MICRO_PROGRAM_BUILD_X86)" \
		--build-context runner-runtime-host-kernel-modules="$(HOST_KERNEL_BUILD_DIR_X86)/modules-install/lib/modules" \
		--build-context runner-runtime-host-kinsn-artifacts="$(HOST_KINSN_DIR_X86)" \
		--build-context runner-runtime-host-shim="$(BPFOPT_SHIM_BUILD_X86)" \
		--build-context runner-runtime-host-extra-libs="$(RUNTIME_LIBS_X86)" \
		--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
		--build-arg RUN_TARGET_ARCH=x86_64 \
		--build-arg VENDOR_BUILD_ARCH=x86 \
		--build-arg RUNNER_BUILD_DIR_NAME=build-llvmbpf \
		--build-arg TEST_BUILD_DIR=build \
		--build-arg KERNEL_IMAGE_NAME=bzImage \
		--build-arg KERNEL_MANIFEST_JSON="$$(cat $(HOST_KERNEL_BUILD_DIR_X86)/manifest.json)" \
		--build-arg BPFOPT_HOST_BIN_DIR="bpfopt/target/release" \
		-t "$(X86_RUNNER_RUNTIME_IMAGE)" -f "$(RUNNER_RUNTIME_CONTAINERFILE)" "$(ROOT_DIR)"
	docker save -o "$(X86_RUNNER_RUNTIME_IMAGE_TAR).tmp" "$(X86_RUNNER_RUNTIME_IMAGE)"
	mv -f "$(X86_RUNNER_RUNTIME_IMAGE_TAR).tmp" "$(X86_RUNNER_RUNTIME_IMAGE_TAR)"

arm64-runner-runtime-image-tar: host-kernel-arm64 host-kinsn-arm64 host-rust-arm64 host-shim-arm64 host-source-apps-arm64 host-runner-arm64 host-micro-programs-arm64 host-stage2-programs-arm64 host-unittest-arm64 host-negative-arm64 host-runtime-libs-arm64
	install -d "$(CONTAINER_IMAGE_ARTIFACT_ROOT)"
	docker build --platform linux/arm64 \
		--target runner-runtime \
		--build-context runner-runtime-host-runner-build="$(RUNNER_DIR)/build-arm64-llvmbpf" \
		--build-context runner-runtime-host-micro-programs="$(MICRO_PROGRAM_BUILD_ARM64)" \
		--build-context runner-runtime-host-stage2-programs="$(STAGE2_PROGRAM_BUILD_ARM64)" \
		--build-context runner-runtime-host-unittest="$(ROOT_DIR)/tests/unittest/build-arm64" \
		--build-context runner-runtime-host-negative="$(ROOT_DIR)/tests/negative/build-arm64" \
		--build-context runner-runtime-host-kernel-image="$(HOST_KERNEL_BUILD_DIR_ARM64)/arch/arm64/boot" \
		--build-context runner-runtime-host-kernel-offsets="$(MICRO_PROGRAM_BUILD_ARM64)" \
		--build-context runner-runtime-host-kernel-modules="$(HOST_KERNEL_BUILD_DIR_ARM64)/modules-install/lib/modules" \
		--build-context runner-runtime-host-kinsn-artifacts="$(HOST_KINSN_DIR_ARM64)" \
		--build-context runner-runtime-host-shim="$(BPFOPT_SHIM_BUILD_ARM64)" \
		--build-context runner-runtime-host-extra-libs="$(RUNTIME_LIBS_ARM64)" \
		--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
		--build-arg RUN_TARGET_ARCH=arm64 \
		--build-arg VENDOR_BUILD_ARCH=arm64 \
		--build-arg RUNNER_BUILD_DIR_NAME=build-arm64-llvmbpf \
		--build-arg TEST_BUILD_DIR=build-arm64 \
		--build-arg KERNEL_IMAGE_NAME=vmlinuz.efi \
		--build-arg KERNEL_MANIFEST_JSON="$$(cat $(HOST_KERNEL_BUILD_DIR_ARM64)/manifest.json)" \
		--build-arg BPFOPT_HOST_BIN_DIR="bpfopt/target/$(ARM64_RUST_TARGET)/release" \
		-t "$(ARM64_RUNNER_RUNTIME_IMAGE)" -f "$(RUNNER_RUNTIME_CONTAINERFILE)" "$(ROOT_DIR)"
	docker save -o "$(ARM64_RUNNER_RUNTIME_IMAGE_TAR).tmp" "$(ARM64_RUNNER_RUNTIME_IMAGE)"
	mv -f "$(ARM64_RUNNER_RUNTIME_IMAGE_TAR).tmp" "$(ARM64_RUNNER_RUNTIME_IMAGE_TAR)"

image-runner-runtime-image-tar: $(if $(filter arm64,$(RUN_TARGET_ARCH)),arm64-runner-runtime-image-tar,x86-runner-runtime-image-tar)

runtime-kernel-image: x86-runner-runtime-image-tar
