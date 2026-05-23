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
VENDOR_BUILD_DIR := $(ROOT_DIR)/vendor/build

DEFAULT_RUNNER_LLVM_DIR := $(ROOT_DIR)/llvm-backend/build-bpf-kinsn/lib/cmake/llvm
RUNNER_LLVM_DIR := $(if $(strip $(LLVM_DIR)),$(LLVM_DIR),$(if $(strip $(RUN_LLVM_DIR)),$(RUN_LLVM_DIR),$(DEFAULT_RUNNER_LLVM_DIR)))
RUNNER_LIBBPF_CFLAGS := -O2 -Werror -Wall -std=gnu89
ARM64_RUNNER_LLVM_SYSROOT := $(ROOT_DIR)/.cache/sysroots/arm64-llvm15
# arm64 uses the in-repo kinsn LLVM (cross-built for aarch64), matching x86
# (build.mk:14) so both arches link the same modified LLVM-23. The legacy
# arm64-llvm15 sysroot is retained only for its -L/rpath link dirs below.
ARM64_RUNNER_LLVM_DIR := $(ROOT_DIR)/llvm-backend/build-bpf-kinsn-arm64/lib/cmake/llvm
ARM64_PKG_CONFIG_LIBDIR = $(AARCH64_SYSROOT_DIR)/usr/lib/aarch64-linux-gnu/pkgconfig
ARM64_SYS_INCLUDE_FLAGS = -I/usr/aarch64-linux-gnu/include -I$(AARCH64_SYSROOT_DIR)/usr/include -I$(AARCH64_SYSROOT_DIR)/usr/include/aarch64-linux-gnu

CONTAINER_IMAGE_ARTIFACT_ROOT := $(ARTIFACT_ROOT)/container-images

ARM64_RUST_TARGET := aarch64-unknown-linux-gnu
NATIVE_LINK_DIR := $(ROOT_DIR)/native-sim/x86/native_lab/native_link
ARM64_NATIVE_KERNEL_SMOKE_DIR := $(ROOT_DIR)/native-sim/arm64/native_lab_smoke
ARM64_SIM_PROOF_DIR := $(ROOT_DIR)/native-sim/arm64
MICRO_PROOF_CONFIG := $(if $(strip $(SUITE)),$(if $(filter /%,$(SUITE)),$(SUITE),$(ROOT_DIR)/$(SUITE)),$(ROOT_DIR)/micro/config/micro_pure_jit.yaml)
BPFOPT_LLVM_BUILD_X86 := $(ROOT_DIR)/bpfopt/llvm/build-kinsn
BPFOPT_LLVM_BUILD_ARM64 := $(ROOT_DIR)/bpfopt/llvm/build-kinsn-arm64
X86_BPFOPT_HOST_BIN ?= bpfopt/llvm/build-kinsn/bpfopt
ARM64_BPFOPT_HOST_BIN ?= bpfopt/llvm/build-kinsn-arm64/bpfopt
X86_KINSNPROBER_HOST_BIN := bpfopt/target/release/kinsnprober
ARM64_KINSNPROBER_HOST_BIN := bpfopt/target/$(ARM64_RUST_TARGET)/release/kinsnprober

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
HOST_KERNEL_IMAGE_X86 := $(X86_RUNTIME_KERNEL_IMAGE)
HOST_KERNEL_VMLINUX_X86 := $(HOST_KERNEL_BUILD_DIR_X86)/vmlinux
HOST_KERNEL_MODULES_ORDER_X86 := $(HOST_KERNEL_BUILD_DIR_X86)/modules.order
HOST_KERNEL_IMAGE_ARM64 := $(HOST_KERNEL_BUILD_DIR_ARM64)/arch/arm64/boot/Image
HOST_KERNEL_EFI_ARM64 := $(HOST_KERNEL_BUILD_DIR_ARM64)/arch/arm64/boot/vmlinuz.efi
HOST_KERNEL_VMLINUX_ARM64 := $(HOST_KERNEL_BUILD_DIR_ARM64)/vmlinux
HOST_KERNEL_MODULES_ORDER_ARM64 := $(HOST_KERNEL_BUILD_DIR_ARM64)/modules.order

.PHONY: \
	host-kernel-x86 host-kernel-arm64 \
	host-kinsn-x86 host-kinsn-arm64 host-rust-x86 host-rust-arm64 host-bpfopt-llvm-x86 host-bpfopt-llvm-arm64 \
	host-shim-x86 host-shim-arm64 host-shim-artifacts \
	host-runner-x86 host-runner-arm64 host-micro-programs-x86 host-micro-programs-arm64 \
	host-stage2-programs-x86 host-stage2-programs-arm64 host-x86-sim-proofs host-arm64-native-kernel-smoke host-arm64-sim-proofs \
	apps host-source-apps host-source-apps-x86 host-source-apps-arm64 \
	aarch64-sysroot runtime-kernel-image \
	x86-runner-runtime-image-tar arm64-runner-runtime-image-tar image-runner-runtime-image-tar

apps: host-source-apps
host-source-apps: host-source-apps-x86 host-source-apps-arm64
host-source-apps-x86:
	$(MAKE) -C "$(ROOT_DIR)/vendor" apps-x86 GO="$(HOST_GO)" JOBS="$(JOBS)"
host-source-apps-arm64:
	$(MAKE) -C "$(ROOT_DIR)/vendor" apps-arm64 GO="$(HOST_GO)" JOBS="$(JOBS)"

$(HOST_KERNEL_BUILD_DIR_X86)/.config: $(DEFCONFIG_SRC)
	install -d "$(HOST_KERNEL_BUILD_DIR_X86)"
	cp "$(DEFCONFIG_SRC)" "$(HOST_KERNEL_BUILD_DIR_X86)/.config"

$(HOST_KERNEL_BUILD_DIR_X86)/include/config/auto.conf: $(HOST_KERNEL_BUILD_DIR_X86)/.config
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_X86)" ARCH=x86_64 olddefconfig

host-kernel-x86: $(HOST_KERNEL_BUILD_DIR_X86)/include/config/auto.conf
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_X86)" ARCH=x86_64 bzImage modules -j"$(IMAGE_BUILD_JOBS)"
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_X86)" ARCH=x86_64 INSTALL_MOD_PATH="$(HOST_KERNEL_BUILD_DIR_X86)/modules-install" INSTALL_MOD_STRIP=1 DEPMOD=true modules_install >/dev/null

$(HOST_KERNEL_IMAGE_X86) $(HOST_KERNEL_VMLINUX_X86) $(HOST_KERNEL_MODULES_ORDER_X86) &: $(HOST_KERNEL_BUILD_DIR_X86)/include/config/auto.conf
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_X86)" ARCH=x86_64 bzImage modules -j"$(IMAGE_BUILD_JOBS)"
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_X86)" ARCH=x86_64 INSTALL_MOD_PATH="$(HOST_KERNEL_BUILD_DIR_X86)/modules-install" INSTALL_MOD_STRIP=1 DEPMOD=true modules_install >/dev/null

$(HOST_KERNEL_BUILD_DIR_ARM64)/.config: $(ARM64_DEFCONFIG_SRC)
	install -d "$(HOST_KERNEL_BUILD_DIR_ARM64)"
	cp "$(ARM64_DEFCONFIG_SRC)" "$(HOST_KERNEL_BUILD_DIR_ARM64)/.config"

$(HOST_KERNEL_BUILD_DIR_ARM64)/include/config/auto.conf: $(HOST_KERNEL_BUILD_DIR_ARM64)/.config
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_ARM64)" ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- olddefconfig

host-kernel-arm64: $(HOST_KERNEL_BUILD_DIR_ARM64)/include/config/auto.conf
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_ARM64)" ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- Image vmlinuz.efi modules -j"$(IMAGE_BUILD_JOBS)"
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_ARM64)" ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- INSTALL_MOD_PATH="$(HOST_KERNEL_BUILD_DIR_ARM64)/modules-install" INSTALL_MOD_STRIP=1 DEPMOD=true modules_install >/dev/null

$(HOST_KERNEL_IMAGE_ARM64) $(HOST_KERNEL_EFI_ARM64) $(HOST_KERNEL_VMLINUX_ARM64) $(HOST_KERNEL_MODULES_ORDER_ARM64) &: $(HOST_KERNEL_BUILD_DIR_ARM64)/include/config/auto.conf
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_ARM64)" ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- Image vmlinuz.efi modules -j"$(IMAGE_BUILD_JOBS)"
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_ARM64)" ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- INSTALL_MOD_PATH="$(HOST_KERNEL_BUILD_DIR_ARM64)/modules-install" INSTALL_MOD_STRIP=1 DEPMOD=true modules_install >/dev/null

host-kinsn-x86: host-kernel-x86
	install -d "$(HOST_KINSN_DIR_X86)"
	$(MAKE) -C "$(HOST_KERNEL_BUILD_DIR_X86)" ARCH=x86_64 M="$(ROOT_DIR)/module/x86" MO="$(HOST_KINSN_DIR_X86)" modules -j"$(IMAGE_BUILD_JOBS)"

host-kinsn-arm64: host-kernel-arm64
	install -d "$(HOST_KINSN_DIR_ARM64)"
	$(MAKE) -C "$(HOST_KERNEL_BUILD_DIR_ARM64)" ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- M="$(ROOT_DIR)/module/arm64" MO="$(HOST_KINSN_DIR_ARM64)" modules -j"$(IMAGE_BUILD_JOBS)"

host-rust-x86:
	cargo build --release --workspace --target-dir "$(ROOT_DIR)/bpfopt/target" --manifest-path "$(ROOT_DIR)/bpfopt/Cargo.toml" -p kinsnprober
	cargo build --release --manifest-path "$(NATIVE_LINK_DIR)/Cargo.toml"

AARCH64_SYSROOT_DIR := $(ROOT_DIR)/.cache/aarch64-sysroot
AARCH64_SYSROOT_DEB_PACKAGES := libzstd1:arm64 libelf1t64:arm64 libelf-dev:arm64 zlib1g:arm64 zlib1g-dev:arm64 libzstd-dev:arm64 \
	libyaml-cpp0.8:arm64 libyaml-cpp-dev:arm64 libspdlog1.12:arm64 libspdlog-dev:arm64 libfmt9:arm64 libfmt-dev:arm64
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
	$(ARM64_CARGO_ENV) cargo build --release --workspace --target "$(ARM64_RUST_TARGET)" --target-dir "$(ROOT_DIR)/bpfopt/target" --manifest-path "$(ROOT_DIR)/bpfopt/Cargo.toml" -p kinsnprober
	$(ARM64_CARGO_ENV) cargo build --release --target "$(ARM64_RUST_TARGET)" --manifest-path "$(NATIVE_LINK_DIR)/Cargo.toml"

host-bpfopt-llvm-x86: $(ROOT_DIR)/$(X86_BPFOPT_HOST_BIN)

$(ROOT_DIR)/bpfopt/llvm/build-kinsn/bpfopt: $(ROOT_DIR)/bpfopt/llvm/CMakeLists.txt $(ROOT_DIR)/bpfopt/llvm/src/main.cpp $(ROOT_DIR)/bpfopt/llvm/src/bpf_bytecode.hpp $(ROOT_DIR)/bpfopt/llvm/src/llvm_mapinline.hpp
	cmake -S "$(ROOT_DIR)/bpfopt/llvm" -B "$(BPFOPT_LLVM_BUILD_X86)" -DCMAKE_BUILD_TYPE=Release -DLLVM_DIR="$(RUNNER_LLVM_DIR)"
	cmake --build "$(BPFOPT_LLVM_BUILD_X86)" -j"$(JOBS)"

host-bpfopt-llvm-arm64: $(ROOT_DIR)/$(ARM64_BPFOPT_HOST_BIN)

$(ROOT_DIR)/bpfopt/llvm/build-kinsn-arm64/bpfopt: aarch64-sysroot $(ROOT_DIR)/bpfopt/llvm/CMakeLists.txt $(ROOT_DIR)/bpfopt/llvm/src/main.cpp $(ROOT_DIR)/bpfopt/llvm/src/bpf_bytecode.hpp $(ROOT_DIR)/bpfopt/llvm/src/llvm_mapinline.hpp
	$(ARM64_PKG_CONFIG) cmake -S "$(ROOT_DIR)/bpfopt/llvm" -B "$(BPFOPT_LLVM_BUILD_ARM64)" -DCMAKE_BUILD_TYPE=Release -DLLVM_DIR="$(ARM64_RUNNER_LLVM_DIR)" -DCMAKE_SYSTEM_NAME=Linux -DCMAKE_SYSTEM_PROCESSOR=aarch64 -DCMAKE_C_COMPILER=aarch64-linux-gnu-gcc -DCMAKE_CXX_COMPILER=aarch64-linux-gnu-g++ -DCMAKE_FIND_ROOT_PATH="$(AARCH64_SYSROOT_DIR);$(ARM64_RUNNER_LLVM_SYSROOT);/usr/aarch64-linux-gnu" -DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER -DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=BOTH -DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=BOTH -DCMAKE_FIND_ROOT_PATH_MODE_PACKAGE=BOTH -DCMAKE_EXE_LINKER_FLAGS="-L$(AARCH64_SYSROOT_DIR)/usr/lib/aarch64-linux-gnu -L$(ARM64_RUNNER_LLVM_SYSROOT)/usr/lib/aarch64-linux-gnu -Wl,-rpath-link,$(AARCH64_SYSROOT_DIR)/usr/lib/aarch64-linux-gnu -Wl,-rpath-link,$(ARM64_RUNNER_LLVM_SYSROOT)/usr/lib/aarch64-linux-gnu -Wl,-rpath-link,$(ARM64_RUNNER_LLVM_SYSROOT)/usr/lib/llvm-15/lib"
	cmake --build "$(BPFOPT_LLVM_BUILD_ARM64)" -j"$(JOBS)"

host-shim-x86:
	install -d "$(BPFOPT_SHIM_BUILD_X86)"
	$(MAKE) -C "$(BPFOPT_SHIM_DIR)" CC=gcc SHIM_SO="$(BPFOPT_SHIM_BUILD_X86)/libbpfrejit_shim.so" "$(BPFOPT_SHIM_BUILD_X86)/libbpfrejit_shim.so"

host-shim-arm64:
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
host-runner-arm64: RUNNER_CMAKE_CROSS := -DCMAKE_SYSTEM_NAME=Linux -DCMAKE_SYSTEM_PROCESSOR=aarch64 -DCMAKE_FIND_ROOT_PATH="$(AARCH64_SYSROOT_DIR);$(ARM64_RUNNER_LLVM_SYSROOT);/usr/aarch64-linux-gnu" -DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER -DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=BOTH -DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=BOTH -DCMAKE_FIND_ROOT_PATH_MODE_PACKAGE=BOTH -DCMAKE_EXE_LINKER_FLAGS="-L$(AARCH64_SYSROOT_DIR)/usr/lib/aarch64-linux-gnu -L$(ARM64_RUNNER_LLVM_SYSROOT)/usr/lib/aarch64-linux-gnu -Wl,-rpath-link,$(AARCH64_SYSROOT_DIR)/usr/lib/aarch64-linux-gnu -Wl,-rpath-link,$(ARM64_RUNNER_LLVM_SYSROOT)/usr/lib/aarch64-linux-gnu -Wl,-rpath-link,$(ARM64_RUNNER_LLVM_SYSROOT)/usr/lib/llvm-15/lib"
host-runner-arm64: RUNNER_PKG_CONFIG := PKG_CONFIG_LIBDIR="$(ARM64_PKG_CONFIG_LIBDIR)" PKG_CONFIG_SYSROOT_DIR="$(AARCH64_SYSROOT_DIR)"
host-runner-x86: host-micro-programs-x86
host-runner-arm64: aarch64-sysroot host-source-apps-arm64 host-micro-programs-arm64
host-runner-x86 host-runner-arm64:
	$(MAKE) -C "$(ROOT_DIR)/vendor/libbpf/src" -j"$(JOBS)" BUILD_STATIC_ONLY=1 $(RUNNER_LIBBPF_ENV) CFLAGS="$(RUNNER_LIBBPF_CFLAGS)" OBJDIR="$(RUNNER_BUILD_DIR_ARCH)/vendor/libbpf/obj" DESTDIR= PREFIX="$(RUNNER_BUILD_DIR_ARCH)/vendor/libbpf/prefix" "$(RUNNER_BUILD_DIR_ARCH)/vendor/libbpf/obj/libbpf.a" install_headers
	$(RUNNER_PKG_CONFIG) cmake -S "$(RUNNER_DIR)" -B "$(RUNNER_BUILD_DIR_ARCH)" -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER="$(RUNNER_CC)" -DCMAKE_CXX_COMPILER="$(RUNNER_CXX)" -DMICRO_REPO_ROOT="$(ROOT_DIR)" -DMICRO_LIBBPF_PREFIX="$(RUNNER_BUILD_DIR_ARCH)/vendor/libbpf/prefix" -DMICRO_LIBBPF_LIBRARY="$(RUNNER_BUILD_DIR_ARCH)/vendor/libbpf/obj/libbpf.a" -DMICRO_KERNEL_OFFSETS_INCLUDE="$(RUNNER_KERNEL_OFFSETS_INCLUDE)" -DMICRO_EXEC_ENABLE_LLVMBPF=1 -DLLVM_DIR="$(RUNNER_LLVM_DIR_ARCH)" $(RUNNER_CMAKE_CROSS)
	cmake --build "$(RUNNER_BUILD_DIR_ARCH)" --target micro_exec -j"$(JOBS)"
	$(RUNNER_STRIP) --strip-unneeded "$(RUNNER_BUILD_DIR_ARCH)/micro_exec"

host-micro-programs-x86: host-kernel-x86 $(HOST_KERNEL_VMLINUX_X86)
	$(MAKE) -C "$(MICRO_PROGRAM_DIR)" OUTPUT_DIR="$(MICRO_PROGRAM_BUILD_X86)" KERNEL_VMLINUX="$(HOST_KERNEL_BUILD_DIR_X86)/vmlinux" all

host-micro-programs-arm64: host-kernel-arm64 $(HOST_KERNEL_VMLINUX_ARM64)
	$(MAKE) -C "$(MICRO_PROGRAM_DIR)" OUTPUT_DIR="$(MICRO_PROGRAM_BUILD_ARM64)" KERNEL_VMLINUX="$(HOST_KERNEL_BUILD_DIR_ARM64)/vmlinux" NATIVE_TARGET=aarch64-linux-gnu NATIVE_ARCH=arm64 SYS_INCLUDE_FLAGS="$(ARM64_SYS_INCLUDE_FLAGS)" all

host-stage2-programs-x86: host-micro-programs-x86
	$(MAKE) -C "$(STAGE2_PROGRAM_DIR)" OUTPUT_DIR="$(STAGE2_PROGRAM_BUILD_X86)" KERNEL_OFFSETS="$(MICRO_PROGRAM_BUILD_X86)/kernel_offsets.h" all

host-stage2-programs-arm64: host-micro-programs-arm64
	$(MAKE) -C "$(STAGE2_PROGRAM_DIR)" OUTPUT_DIR="$(STAGE2_PROGRAM_BUILD_ARM64)" KERNEL_OFFSETS="$(MICRO_PROGRAM_BUILD_ARM64)/kernel_offsets.h" NATIVE_TARGET=aarch64-linux-gnu NATIVE_ARCH=arm64 SYS_INCLUDE_FLAGS="$(ARM64_SYS_INCLUDE_FLAGS)" all

host-arm64-native-kernel-smoke:
	$(MAKE) -C "$(ARM64_NATIVE_KERNEL_SMOKE_DIR)" OUTPUT_DIR="$(STAGE2_PROGRAM_BUILD_ARM64)/native_kernel_smoke" all

host-x86-sim-proofs: host-micro-programs-x86
	$(MAKE) -C "$(ROOT_DIR)/native-sim/x86" PROOF_BUILD_DIR="$(STAGE2_PROGRAM_BUILD_X86)/x86_sim_proofs" MICRO_CONFIG="$(MICRO_PROOF_CONFIG)" micro-proofs-build

host-arm64-sim-proofs: host-micro-programs-arm64
	$(MAKE) -C "$(ARM64_SIM_PROOF_DIR)" PROOF_BUILD_DIR="$(STAGE2_PROGRAM_BUILD_ARM64)/arm64_sim_proofs" MICRO_CONFIG="$(MICRO_PROOF_CONFIG)" micro-proofs-build

x86-runner-runtime-image-tar: $(HOST_KERNEL_IMAGE_X86) host-kinsn-x86 host-rust-x86 host-shim-x86 host-source-apps-x86 host-runner-x86 host-micro-programs-x86 host-stage2-programs-x86 host-x86-sim-proofs $(X86_BPFOPT_HOST_BIN)
	install -d "$(CONTAINER_IMAGE_ARTIFACT_ROOT)"
	docker build --platform linux/amd64 \
		--target runner-runtime \
		--build-context runner-runtime-host-runner-build="$(RUNNER_DIR)/build-llvmbpf" \
		--build-context runner-runtime-host-micro-programs="$(MICRO_PROGRAM_BUILD_X86)" \
		--build-context runner-runtime-host-stage2-programs="$(STAGE2_PROGRAM_BUILD_X86)" \
		--build-context runner-runtime-host-negative="$(ROOT_DIR)/tests/negative/build" \
		--build-context runner-runtime-host-kernel-image="$(HOST_KERNEL_BUILD_DIR_X86)/arch/x86/boot" \
		--build-context runner-runtime-host-kernel-offsets="$(MICRO_PROGRAM_BUILD_X86)" \
		--build-context runner-runtime-host-kernel-modules="$(HOST_KERNEL_BUILD_DIR_X86)/modules-install/lib/modules" \
		--build-context runner-runtime-host-kinsn-artifacts="$(HOST_KINSN_DIR_X86)" \
		--build-context runner-runtime-host-shim="$(BPFOPT_SHIM_BUILD_X86)" \
		--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
		--build-arg RUN_TARGET_ARCH=x86_64 \
		--build-arg VENDOR_BUILD_ARCH=x86 \
		--build-arg RUNNER_BUILD_DIR_NAME=build-llvmbpf \
		--build-arg TEST_BUILD_DIR=build \
		--build-arg KERNEL_IMAGE_NAME=bzImage \
		--build-arg KERNEL_MANIFEST_JSON="$$(printf '{"kernel_release":"%s","target_arch":"x86_64","kernel_image":"bzImage"}' "$$(cat "$(HOST_KERNEL_BUILD_DIR_X86)/include/config/kernel.release")")" \
		--build-arg BPFOPT_HOST_BIN="$(X86_BPFOPT_HOST_BIN)" \
		--build-arg KINSNPROBER_HOST_BIN="$(X86_KINSNPROBER_HOST_BIN)" \
		-t "$(X86_RUNNER_RUNTIME_IMAGE)" -f "$(RUNNER_RUNTIME_CONTAINERFILE)" "$(ROOT_DIR)"
	docker save -o "$(X86_RUNNER_RUNTIME_IMAGE_TAR).tmp" "$(X86_RUNNER_RUNTIME_IMAGE)"
	mv -f "$(X86_RUNNER_RUNTIME_IMAGE_TAR).tmp" "$(X86_RUNNER_RUNTIME_IMAGE_TAR)"

arm64-runner-runtime-image-tar: $(HOST_KERNEL_IMAGE_ARM64) $(HOST_KERNEL_EFI_ARM64) host-kinsn-arm64 host-rust-arm64 host-shim-arm64 host-source-apps-arm64 host-runner-arm64 host-micro-programs-arm64 host-stage2-programs-arm64 host-arm64-native-kernel-smoke host-arm64-sim-proofs $(ARM64_BPFOPT_HOST_BIN)
	install -d "$(CONTAINER_IMAGE_ARTIFACT_ROOT)"
	docker build --platform linux/arm64 \
		--target runner-runtime \
		--build-context runner-runtime-host-runner-build="$(RUNNER_DIR)/build-arm64-llvmbpf" \
		--build-context runner-runtime-host-micro-programs="$(MICRO_PROGRAM_BUILD_ARM64)" \
		--build-context runner-runtime-host-stage2-programs="$(STAGE2_PROGRAM_BUILD_ARM64)" \
		--build-context runner-runtime-host-negative="$(ROOT_DIR)/tests/negative/build-arm64" \
		--build-context runner-runtime-host-kernel-image="$(HOST_KERNEL_BUILD_DIR_ARM64)/arch/arm64/boot" \
		--build-context runner-runtime-host-kernel-offsets="$(MICRO_PROGRAM_BUILD_ARM64)" \
		--build-context runner-runtime-host-kernel-modules="$(HOST_KERNEL_BUILD_DIR_ARM64)/modules-install/lib/modules" \
		--build-context runner-runtime-host-kinsn-artifacts="$(HOST_KINSN_DIR_ARM64)" \
		--build-context runner-runtime-host-shim="$(BPFOPT_SHIM_BUILD_ARM64)" \
		--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
		--build-arg RUN_TARGET_ARCH=arm64 \
		--build-arg VENDOR_BUILD_ARCH=arm64 \
		--build-arg RUNNER_BUILD_DIR_NAME=build-arm64-llvmbpf \
		--build-arg TEST_BUILD_DIR=build-arm64 \
		--build-arg KERNEL_IMAGE_NAME=vmlinuz.efi \
		--build-arg KERNEL_MANIFEST_JSON="$$(printf '{"kernel_release":"%s","target_arch":"arm64","kernel_image":"vmlinuz.efi"}' "$$(cat "$(HOST_KERNEL_BUILD_DIR_ARM64)/include/config/kernel.release")")" \
		--build-arg BPFOPT_HOST_BIN="$(ARM64_BPFOPT_HOST_BIN)" \
		--build-arg KINSNPROBER_HOST_BIN="$(ARM64_KINSNPROBER_HOST_BIN)" \
		--build-arg NATIVE_LINK_HOST_BIN="native-sim/x86/native_lab/native_link/target/$(ARM64_RUST_TARGET)/release/native-link" \
		-t "$(ARM64_RUNNER_RUNTIME_IMAGE)" -f "$(RUNNER_RUNTIME_CONTAINERFILE)" "$(ROOT_DIR)"
	docker save -o "$(ARM64_RUNNER_RUNTIME_IMAGE_TAR).tmp" "$(ARM64_RUNNER_RUNTIME_IMAGE)"
	mv -f "$(ARM64_RUNNER_RUNTIME_IMAGE_TAR).tmp" "$(ARM64_RUNNER_RUNTIME_IMAGE_TAR)"

image-runner-runtime-image-tar: $(if $(filter arm64,$(RUN_TARGET_ARCH)),arm64-runner-runtime-image-tar,x86-runner-runtime-image-tar)

runtime-kernel-image: x86-runner-runtime-image-tar
