REPOS_DIR := $(ROOT_DIR)/vendor/repos
RUNNER_CONTAINER_DIR := $(RUNNER_DIR)/containers
RUN_TARGET_ARCH ?= x86_64
IMAGE_BUILD_JOBS ?= $(JOBS)
ARM64_IMAGE_BUILD_JOBS ?= 4
X86_BUILD_DISTRO_VARIANT := ubuntu24.04
BUILD_ARCH_VARIANT := $(if $(filter x86_64,$(RUN_TARGET_ARCH)),-$(X86_BUILD_DISTRO_VARIANT),)
IMAGE_ARTIFACT_ROOT ?= /artifacts/user
IMAGE_BUILD_ROOT ?= /tmp/bpf-benchmark-build/$(RUN_TARGET_ARCH)$(BUILD_ARCH_VARIANT)
ACTIVE_ARTIFACT_ROOT := $(if $(filter 1,$(BPFREJIT_IMAGE_BUILD)),$(IMAGE_ARTIFACT_ROOT),$(ARTIFACT_ROOT))
ACTIVE_BUILD_ARTIFACT_ROOT := $(if $(filter 1,$(BPFREJIT_IMAGE_BUILD)),$(IMAGE_BUILD_ROOT),$(ARTIFACT_ROOT))

MICRO_PROGRAM_DIR := $(ROOT_DIR)/micro/programs
MICRO_PROGRAM_OUTPUT_DIR := $(ACTIVE_ARTIFACT_ROOT)/micro-programs/$(RUN_TARGET_ARCH)
STAGE2_PROGRAM_DIR := $(ROOT_DIR)/native-sim/test
STAGE2_PROGRAM_OUTPUT_DIR := $(ACTIVE_ARTIFACT_ROOT)/stage2-programs/$(RUN_TARGET_ARCH)

RUNNER_BUILD_DIR_ACTIVE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(RUNNER_DIR)/build-arm64-llvmbpf,$(RUNNER_DIR)/build-llvmbpf)
RUNNER_LIBBPF_BUILD_DIR := $(RUNNER_BUILD_DIR_ACTIVE)/vendor/libbpf
RUNNER_LIBBPF_OBJDIR := $(RUNNER_LIBBPF_BUILD_DIR)/obj
RUNNER_LIBBPF_PREFIX := $(RUNNER_LIBBPF_BUILD_DIR)/prefix
RUNNER_LIBBPF_ARCHIVE := $(RUNNER_LIBBPF_OBJDIR)/libbpf.a
DEFAULT_RUNNER_LLVM_DIR := /usr/lib/llvm-18/lib/cmake/llvm
RUNNER_LLVM_DIR := $(if $(strip $(LLVM_DIR)),$(LLVM_DIR),$(if $(strip $(RUN_LLVM_DIR)),$(RUN_LLVM_DIR),$(DEFAULT_RUNNER_LLVM_DIR)))
RUNNER_CONTAINER_CC := /usr/bin/gcc
RUNNER_CONTAINER_CXX := /usr/bin/g++

CONTAINER_IMAGE_ARTIFACT_ROOT := $(ARTIFACT_ROOT)/container-images
REPO_ARTIFACT_ROOT := $(ACTIVE_ARTIFACT_ROOT)/repo-artifacts/$(RUN_TARGET_ARCH)
REPO_KATRAN_ROOT := $(REPO_ARTIFACT_ROOT)/katran
REPO_BUILD_ROOT := $(ACTIVE_BUILD_ARTIFACT_ROOT)/repo-build/$(RUN_TARGET_ARCH)$(BUILD_ARCH_VARIANT)
KATRAN_BUILD_ROOT := $(REPO_BUILD_ROOT)/katran

ARM64_RUST_TARGET := aarch64-unknown-linux-gnu
NATIVE_LINK_DIR := $(ROOT_DIR)/native-sim/x86/native_lab/native_link

RUNNER_RUNTIME_CONTAINERFILE := $(RUNNER_CONTAINER_DIR)/runner-runtime.Dockerfile
KATRAN_ARTIFACTS_CONTAINERFILE := $(RUNNER_CONTAINER_DIR)/katran-artifacts.Dockerfile
BPFREJIT_INSTALL_SCRIPT := $(RUNNER_DIR)/scripts/bpfrejit-install
BPFOPT_SHIM_DIR := $(ROOT_DIR)/bpfopt/shim

X86_RUNNER_RUNTIME_IMAGE := bpf-benchmark/runner-runtime:x86_64
ARM64_RUNNER_RUNTIME_IMAGE := bpf-benchmark/runner-runtime:arm64
X86_KATRAN_ARTIFACTS_IMAGE := bpf-benchmark/katran-artifacts:x86_64
ARM64_KATRAN_ARTIFACTS_IMAGE := bpf-benchmark/katran-artifacts:arm64
GHCR_IMAGE_PREFIX ?= ghcr.io/eunomia-bpf
GHCR_KATRAN_ARTIFACTS_IMAGE_REPOSITORY := $(GHCR_IMAGE_PREFIX)/bpf-benchmark-katran-artifacts
X86_KATRAN_ARTIFACTS_GHCR_IMAGE := $(GHCR_KATRAN_ARTIFACTS_IMAGE_REPOSITORY):x86_64
ARM64_KATRAN_ARTIFACTS_GHCR_IMAGE := $(GHCR_KATRAN_ARTIFACTS_IMAGE_REPOSITORY):arm64

X86_RUNNER_RUNTIME_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/x86_64-runner-runtime.image.tar
ARM64_RUNNER_RUNTIME_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/arm64-runner-runtime.image.tar
X86_KATRAN_ARTIFACTS_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/x86_64-katran-artifacts.image.tar
ARM64_KATRAN_ARTIFACTS_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/arm64-katran-artifacts.image.tar
ACTIVE_KATRAN_ARTIFACTS_IMAGE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_KATRAN_ARTIFACTS_IMAGE),$(X86_KATRAN_ARTIFACTS_IMAGE))
ACTIVE_KATRAN_ARTIFACTS_GHCR_IMAGE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_KATRAN_ARTIFACTS_GHCR_IMAGE),$(X86_KATRAN_ARTIFACTS_GHCR_IMAGE))

X86_RUNTIME_KERNEL_DIR := $(ARTIFACT_ROOT)/runtime-kernel/x86_64
X86_RUNTIME_KERNEL_IMAGE := $(X86_RUNTIME_KERNEL_DIR)/bzImage
HOST_BUILD_ROOT := $(ACTIVE_BUILD_ARTIFACT_ROOT)/repo-build/host
HOST_KERNEL_BUILD_DIR_X86 := $(HOST_BUILD_ROOT)/kernel/x86_64
HOST_KERNEL_BUILD_DIR_ARM64 := $(HOST_BUILD_ROOT)/kernel/arm64
HOST_KERNEL_OFFSETS_DIR_X86 := $(HOST_BUILD_ROOT)/kernel-offsets/x86_64
HOST_KERNEL_OFFSETS_DIR_ARM64 := $(HOST_BUILD_ROOT)/kernel-offsets/arm64
HOST_KINSN_DIR_X86 := $(HOST_BUILD_ROOT)/kinsn-build/x86_64
HOST_KINSN_DIR_ARM64 := $(HOST_BUILD_ROOT)/kinsn-build/arm64

.PHONY: \
	host-kernel-x86 host-kernel-arm64 host-kernel-offsets-x86 host-kernel-offsets-arm64 \
	host-kinsn-x86 host-kinsn-arm64 host-rust-x86 host-rust-arm64 host-shim-artifacts \
	aarch64-sysroot runtime-kernel-image \
	x86-katran-artifacts-image-tar arm64-katran-artifacts-image-tar image-katran-artifacts-image-tar \
	x86-runner-runtime-image-tar arm64-runner-runtime-image-tar image-runner-runtime-image-tar \
	image-push-katran-artifacts

host-kernel-x86:
	install -d "$(HOST_KERNEL_BUILD_DIR_X86)"
	cp "$(DEFCONFIG_SRC)" "$(HOST_KERNEL_BUILD_DIR_X86)/.config"
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_X86)" ARCH=x86_64 olddefconfig
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_X86)" ARCH=x86_64 bzImage modules -j"$(IMAGE_BUILD_JOBS)"
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_X86)" ARCH=x86_64 INSTALL_MOD_PATH="$(HOST_KERNEL_BUILD_DIR_X86)/modules-install" DEPMOD=true modules_install >/dev/null
	rel=$$(cat "$(HOST_KERNEL_BUILD_DIR_X86)/include/config/kernel.release"); \
		printf '{"kernel_release":"%s","target_arch":"x86_64","kernel_image":"bzImage"}\n' "$$rel" >"$(HOST_KERNEL_BUILD_DIR_X86)/manifest.json"

host-kernel-arm64:
	@command -v aarch64-linux-gnu-gcc >/dev/null
	install -d "$(HOST_KERNEL_BUILD_DIR_ARM64)"
	cp "$(ARM64_DEFCONFIG_SRC)" "$(HOST_KERNEL_BUILD_DIR_ARM64)/.config"
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_ARM64)" ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- olddefconfig
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_ARM64)" ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- Image vmlinuz.efi modules -j"$(IMAGE_BUILD_JOBS)"
	$(MAKE) -C "$(KERNEL_DIR)" O="$(HOST_KERNEL_BUILD_DIR_ARM64)" ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- INSTALL_MOD_PATH="$(HOST_KERNEL_BUILD_DIR_ARM64)/modules-install" DEPMOD=true modules_install >/dev/null
	rel=$$(cat "$(HOST_KERNEL_BUILD_DIR_ARM64)/include/config/kernel.release"); \
		printf '{"kernel_release":"%s","target_arch":"arm64","kernel_image":"vmlinuz.efi"}\n' "$$rel" >"$(HOST_KERNEL_BUILD_DIR_ARM64)/manifest.json"

host-kernel-offsets-x86: host-kernel-x86
	$(MAKE) -C "$(MICRO_PROGRAM_DIR)" OUTPUT_DIR="$(HOST_KERNEL_OFFSETS_DIR_X86)" KERNEL_VMLINUX="$(HOST_KERNEL_BUILD_DIR_X86)/vmlinux" "$(HOST_KERNEL_OFFSETS_DIR_X86)/kernel_offsets.h"

host-kernel-offsets-arm64: host-kernel-arm64
	$(MAKE) -C "$(MICRO_PROGRAM_DIR)" OUTPUT_DIR="$(HOST_KERNEL_OFFSETS_DIR_ARM64)" KERNEL_VMLINUX="$(HOST_KERNEL_BUILD_DIR_ARM64)/vmlinux" "$(HOST_KERNEL_OFFSETS_DIR_ARM64)/kernel_offsets.h"

host-kinsn-x86: host-kernel-x86
	rm -rf "$(HOST_KINSN_DIR_X86)"
	install -d "$(HOST_KINSN_DIR_X86)"
	$(MAKE) -C "$(HOST_KERNEL_BUILD_DIR_X86)" ARCH=x86_64 M="$(ROOT_DIR)/module/x86" MO="$(HOST_KINSN_DIR_X86)" modules -j"$(IMAGE_BUILD_JOBS)"
	test "$$(find "$(HOST_KINSN_DIR_X86)" -maxdepth 1 -type f -name '*.ko' | wc -l)" -gt 0

host-kinsn-arm64: host-kernel-arm64
	@command -v aarch64-linux-gnu-gcc >/dev/null
	rm -rf "$(HOST_KINSN_DIR_ARM64)"
	install -d "$(HOST_KINSN_DIR_ARM64)"
	$(MAKE) -C "$(HOST_KERNEL_BUILD_DIR_ARM64)" ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- M="$(ROOT_DIR)/module/arm64" MO="$(HOST_KINSN_DIR_ARM64)" modules -j"$(IMAGE_BUILD_JOBS)"
	test "$$(find "$(HOST_KINSN_DIR_ARM64)" -maxdepth 1 -type f -name '*.ko' | wc -l)" -gt 0

host-rust-x86:
	$(MAKE) -C "$(ROOT_DIR)/daemon" release TARGET_DIR="$(DAEMON_DIR)/target"
	cargo build --release --workspace --target-dir "$(ROOT_DIR)/bpfopt/target" --manifest-path "$(ROOT_DIR)/bpfopt/Cargo.toml" -p bpfopt -p kinsnprober
	cargo build --release --manifest-path "$(NATIVE_LINK_DIR)/Cargo.toml"

AARCH64_SYSROOT_DIR := $(ROOT_DIR)/.cache/aarch64-sysroot
AARCH64_SYSROOT_DEB_PACKAGES := libzstd1:arm64 libelf1t64:arm64 libelf-dev:arm64 zlib1g:arm64 zlib1g-dev:arm64 libzstd-dev:arm64
ARM64_CARGO_RUSTFLAGS := -C link-arg=--sysroot=$(AARCH64_SYSROOT_DIR) -C link-arg=-L$(AARCH64_SYSROOT_DIR)/usr/lib/aarch64-linux-gnu -C link-arg=-Wl,-rpath-link=$(AARCH64_SYSROOT_DIR)/usr/lib/aarch64-linux-gnu
ARM64_CARGO_ENV := \
	CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER=aarch64-linux-gnu-gcc \
	CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_RUSTFLAGS="$(ARM64_CARGO_RUSTFLAGS)"

aarch64-sysroot:
	@if [ -f "$(AARCH64_SYSROOT_DIR)/usr/include/libelf.h" ]; then exit 0; fi; \
	command -v aarch64-linux-gnu-gcc >/dev/null || { echo "aarch64-linux-gnu-gcc missing; install gcc-aarch64-linux-gnu" >&2; exit 1; }; \
	command -v dpkg-deb >/dev/null; \
	command -v apt-get >/dev/null; \
	if ! dpkg --print-foreign-architectures | grep -q arm64; then \
		echo "dpkg foreign architecture arm64 not configured; run: sudo dpkg --add-architecture arm64 && sudo apt-get update" >&2; exit 1; \
	fi; \
	install -d "$(AARCH64_SYSROOT_DIR)/.debs"; \
	cd "$(AARCH64_SYSROOT_DIR)/.debs" && apt-get download $(AARCH64_SYSROOT_DEB_PACKAGES); \
	for d in "$(AARCH64_SYSROOT_DIR)"/.debs/*.deb; do dpkg-deb -x "$$d" "$(AARCH64_SYSROOT_DIR)"; done

host-rust-arm64: aarch64-sysroot
	$(ARM64_CARGO_ENV) $(MAKE) -C "$(ROOT_DIR)/daemon" release TARGET_DIR="$(DAEMON_DIR)/target" TARGET_TRIPLE="$(ARM64_RUST_TARGET)"
	$(ARM64_CARGO_ENV) cargo build --release --workspace --target "$(ARM64_RUST_TARGET)" --target-dir "$(ROOT_DIR)/bpfopt/target" --manifest-path "$(ROOT_DIR)/bpfopt/Cargo.toml" -p bpfopt -p kinsnprober
	cargo build --release --manifest-path "$(NATIVE_LINK_DIR)/Cargo.toml"

host-shim-artifacts:
	$(MAKE) -C "$(BPFOPT_SHIM_DIR)" libbpfrejit_shim.so
	$(MAKE) -C "$(BPFOPT_SHIM_DIR)" musl

x86-katran-artifacts-image-tar:
	install -d "$(CONTAINER_IMAGE_ARTIFACT_ROOT)"
	docker build --platform linux/amd64 --target katran-artifacts \
		--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
		--build-arg IMAGE_BUILD_JOBS="$(IMAGE_BUILD_JOBS)" \
		--build-arg RUN_TARGET_ARCH=x86_64 \
		-t "$(X86_KATRAN_ARTIFACTS_IMAGE)" -f "$(KATRAN_ARTIFACTS_CONTAINERFILE)" "$(ROOT_DIR)"
	docker save -o "$(X86_KATRAN_ARTIFACTS_IMAGE_TAR).tmp" "$(X86_KATRAN_ARTIFACTS_IMAGE)"
	mv -f "$(X86_KATRAN_ARTIFACTS_IMAGE_TAR).tmp" "$(X86_KATRAN_ARTIFACTS_IMAGE_TAR)"

arm64-katran-artifacts-image-tar:
	install -d "$(CONTAINER_IMAGE_ARTIFACT_ROOT)"
	docker build --platform linux/arm64 --target katran-artifacts \
		--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
		--build-arg IMAGE_BUILD_JOBS="$(ARM64_IMAGE_BUILD_JOBS)" \
		--build-arg RUN_TARGET_ARCH=arm64 \
		-t "$(ARM64_KATRAN_ARTIFACTS_IMAGE)" -f "$(KATRAN_ARTIFACTS_CONTAINERFILE)" "$(ROOT_DIR)"
	docker save -o "$(ARM64_KATRAN_ARTIFACTS_IMAGE_TAR).tmp" "$(ARM64_KATRAN_ARTIFACTS_IMAGE)"
	mv -f "$(ARM64_KATRAN_ARTIFACTS_IMAGE_TAR).tmp" "$(ARM64_KATRAN_ARTIFACTS_IMAGE_TAR)"

image-katran-artifacts-image-tar: $(if $(filter arm64,$(RUN_TARGET_ARCH)),arm64-katran-artifacts-image-tar,x86-katran-artifacts-image-tar)

x86-runner-runtime-image-tar: x86-katran-artifacts-image-tar host-kernel-x86 host-kernel-offsets-x86 host-kinsn-x86 host-rust-x86 host-shim-artifacts
	install -d "$(CONTAINER_IMAGE_ARTIFACT_ROOT)"
	docker load -i "$(X86_KATRAN_ARTIFACTS_IMAGE_TAR)"
	docker build --platform linux/amd64 \
		--target runner-runtime \
		--build-context runner-runtime-katran-upstream=docker-image://$(X86_KATRAN_ARTIFACTS_IMAGE) \
		--build-context runner-runtime-host-kernel-image="$(HOST_KERNEL_BUILD_DIR_X86)/arch/x86/boot" \
		--build-context runner-runtime-host-kernel-offsets="$(HOST_KERNEL_OFFSETS_DIR_X86)" \
		--build-context runner-runtime-host-kernel-modules="$(HOST_KERNEL_BUILD_DIR_X86)/modules-install/lib/modules" \
		--build-context runner-runtime-host-kinsn-artifacts="$(HOST_KINSN_DIR_X86)" \
		--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
		--build-arg IMAGE_BUILD_JOBS="$(IMAGE_BUILD_JOBS)" \
		--build-arg RUN_TARGET_ARCH=x86_64 \
		--build-arg KERNEL_IMAGE_NAME=bzImage \
		--build-arg KERNEL_MANIFEST_JSON="$$(cat $(HOST_KERNEL_BUILD_DIR_X86)/manifest.json)" \
		--build-arg DAEMON_HOST_BIN_DIR="daemon/target/release" \
		--build-arg BPFOPT_HOST_BIN_DIR="bpfopt/target/release" \
		-t "$(X86_RUNNER_RUNTIME_IMAGE)" -f "$(RUNNER_RUNTIME_CONTAINERFILE)" "$(ROOT_DIR)"
	docker save -o "$(X86_RUNNER_RUNTIME_IMAGE_TAR).tmp" "$(X86_RUNNER_RUNTIME_IMAGE)"
	mv -f "$(X86_RUNNER_RUNTIME_IMAGE_TAR).tmp" "$(X86_RUNNER_RUNTIME_IMAGE_TAR)"

arm64-runner-runtime-image-tar: arm64-katran-artifacts-image-tar host-kernel-arm64 host-kernel-offsets-arm64 host-kinsn-arm64 host-rust-arm64 host-shim-artifacts
	install -d "$(CONTAINER_IMAGE_ARTIFACT_ROOT)"
	docker load -i "$(ARM64_KATRAN_ARTIFACTS_IMAGE_TAR)"
	docker build --platform linux/arm64 \
		--target runner-runtime \
		--build-context runner-runtime-katran-upstream=docker-image://$(ARM64_KATRAN_ARTIFACTS_IMAGE) \
		--build-context runner-runtime-host-kernel-image="$(HOST_KERNEL_BUILD_DIR_ARM64)/arch/arm64/boot" \
		--build-context runner-runtime-host-kernel-offsets="$(HOST_KERNEL_OFFSETS_DIR_ARM64)" \
		--build-context runner-runtime-host-kernel-modules="$(HOST_KERNEL_BUILD_DIR_ARM64)/modules-install/lib/modules" \
		--build-context runner-runtime-host-kinsn-artifacts="$(HOST_KINSN_DIR_ARM64)" \
		--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
		--build-arg IMAGE_BUILD_JOBS="$(ARM64_IMAGE_BUILD_JOBS)" \
		--build-arg RUN_TARGET_ARCH=arm64 \
		--build-arg KERNEL_IMAGE_NAME=vmlinuz.efi \
		--build-arg KERNEL_MANIFEST_JSON="$$(cat $(HOST_KERNEL_BUILD_DIR_ARM64)/manifest.json)" \
		--build-arg DAEMON_HOST_BIN_DIR="daemon/target/$(ARM64_RUST_TARGET)/release" \
		--build-arg BPFOPT_HOST_BIN_DIR="bpfopt/target/$(ARM64_RUST_TARGET)/release" \
		-t "$(ARM64_RUNNER_RUNTIME_IMAGE)" -f "$(RUNNER_RUNTIME_CONTAINERFILE)" "$(ROOT_DIR)"
	docker save -o "$(ARM64_RUNNER_RUNTIME_IMAGE_TAR).tmp" "$(ARM64_RUNNER_RUNTIME_IMAGE)"
	mv -f "$(ARM64_RUNNER_RUNTIME_IMAGE_TAR).tmp" "$(ARM64_RUNNER_RUNTIME_IMAGE_TAR)"

image-runner-runtime-image-tar: $(if $(filter arm64,$(RUN_TARGET_ARCH)),arm64-runner-runtime-image-tar,x86-runner-runtime-image-tar)

runtime-kernel-image: x86-runner-runtime-image-tar
	@install -d "$(X86_RUNTIME_KERNEL_DIR)"
	BPFREJIT_INSTALL_KERNEL_OUT_DIR="$(X86_RUNTIME_KERNEL_DIR)" "$(BPFREJIT_INSTALL_SCRIPT)" --extract-kernel-only "$(X86_RUNNER_RUNTIME_IMAGE_TAR)"
	test -s "$(X86_RUNTIME_KERNEL_IMAGE)"

image-push-katran-artifacts: image-katran-artifacts-image-tar
	docker load -i "$(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_KATRAN_ARTIFACTS_IMAGE_TAR),$(X86_KATRAN_ARTIFACTS_IMAGE_TAR))"
	docker tag "$(ACTIVE_KATRAN_ARTIFACTS_IMAGE)" "$(ACTIVE_KATRAN_ARTIFACTS_GHCR_IMAGE)"
	docker push "$(ACTIVE_KATRAN_ARTIFACTS_GHCR_IMAGE)"

.PHONY: image-katran-artifacts image-runner-artifacts \
	image-micro-program-artifacts image-stage2-program-artifacts image-test-artifacts
ifneq ($(BPFREJIT_IMAGE_BUILD),1)
image-katran-artifacts image-runner-artifacts image-micro-program-artifacts image-stage2-program-artifacts image-test-artifacts:
	@echo "$@ must be run from the runner Dockerfile with BPFREJIT_IMAGE_BUILD=1" >&2
	@exit 1
else
image-runner-artifacts:
	$(MAKE) -C "$(ROOT_DIR)/vendor/libbpf/src" -j"$(JOBS)" BUILD_STATIC_ONLY=1 \
		OBJDIR="$(RUNNER_LIBBPF_OBJDIR)" DESTDIR= PREFIX="$(RUNNER_LIBBPF_PREFIX)" \
		"$(RUNNER_LIBBPF_ARCHIVE)" install_headers
	cmake -S "$(RUNNER_DIR)" -B "$(RUNNER_BUILD_DIR_ACTIVE)" \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_C_COMPILER="$(RUNNER_CONTAINER_CC)" \
		-DCMAKE_CXX_COMPILER="$(RUNNER_CONTAINER_CXX)" \
		-DMICRO_REPO_ROOT="$(ROOT_DIR)" \
		-DMICRO_LIBBPF_PREFIX="$(RUNNER_LIBBPF_PREFIX)" \
		-DMICRO_LIBBPF_LIBRARY="$(RUNNER_LIBBPF_ARCHIVE)" \
		-DMICRO_EXEC_ENABLE_LLVMBPF="1" \
		-DLLVM_DIR="$(RUNNER_LLVM_DIR)"
	cmake --build "$(RUNNER_BUILD_DIR_ACTIVE)" --target micro_exec -j"$(JOBS)"

image-micro-program-artifacts:
	$(MAKE) -C "$(MICRO_PROGRAM_DIR)" OUTPUT_DIR="$(MICRO_PROGRAM_OUTPUT_DIR)" KERNEL_OFFSETS_INPUT="/artifacts/kernel/kernel_offsets.h" all

image-stage2-program-artifacts:
	if [ -f /artifacts/kernel/kernel_offsets.h ]; then \
		cp -f /artifacts/kernel/kernel_offsets.h "$(MICRO_PROGRAM_DIR)/kernel_offsets.h"; \
	fi
	$(MAKE) -C "$(STAGE2_PROGRAM_DIR)" OUTPUT_DIR="$(STAGE2_PROGRAM_OUTPUT_DIR)" all

image-test-artifacts:
	$(MAKE) -C "$(ROOT_DIR)/tests/unittest" BUILD_DIR="$(ROOT_DIR)/tests/unittest/$(if $(filter arm64,$(RUN_TARGET_ARCH)),build-arm64,build)" CC=gcc CLANG=clang BPF_TARGET_ARCH="$(RUN_TARGET_ARCH)"
	$(MAKE) -C "$(ROOT_DIR)/tests/negative" BUILD_DIR="$(ROOT_DIR)/tests/negative/$(if $(filter arm64,$(RUN_TARGET_ARCH)),build-arm64,build)" CC=gcc

include $(RUNNER_DIR)/mk/katran-artifacts.mk
endif
