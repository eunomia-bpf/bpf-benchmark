REPOS_DIR := $(RUNNER_DIR)/repos
RUNNER_CONTAINER_DIR := $(RUNNER_DIR)/containers
RUN_TARGET_ARCH ?= x86_64
IMAGE_BUILD_JOBS ?= $(JOBS)
ARM64_IMAGE_BUILD_JOBS ?= 4
DOCKERIGNORE_FILE := $(ROOT_DIR)/.dockerignore
X86_BUILD_DISTRO_VARIANT := ubuntu24.04
BUILD_ARCH_VARIANT := $(if $(filter x86_64,$(RUN_TARGET_ARCH)),-$(X86_BUILD_DISTRO_VARIANT),)
IMAGE_ARTIFACT_ROOT ?= /artifacts/user
KERNEL_ARTIFACT_ROOT ?= /artifacts
KERNEL_MODULES_ARTIFACT_ROOT ?= $(KERNEL_ARTIFACT_ROOT)/modules
IMAGE_BUILD_ROOT ?= /tmp/bpf-benchmark-build/$(RUN_TARGET_ARCH)$(BUILD_ARCH_VARIANT)
ACTIVE_ARTIFACT_ROOT := $(if $(filter 1,$(BPFREJIT_IMAGE_BUILD)),$(IMAGE_ARTIFACT_ROOT),$(ARTIFACT_ROOT))
ACTIVE_BUILD_ARTIFACT_ROOT := $(if $(filter 1,$(BPFREJIT_IMAGE_BUILD)),$(IMAGE_BUILD_ROOT),$(ARTIFACT_ROOT))
REPO_ARTIFACT_ROOT := $(ACTIVE_ARTIFACT_ROOT)/repo-artifacts/$(RUN_TARGET_ARCH)
REPO_KATRAN_ROOT := $(REPO_ARTIFACT_ROOT)/katran
REPO_BUILD_ROOT := $(ACTIVE_BUILD_ARTIFACT_ROOT)/repo-build/$(RUN_TARGET_ARCH)$(BUILD_ARCH_VARIANT)
BUILD_RULE_FILES := $(ROOT_DIR)/Makefile $(RUNNER_DIR)/mk/build.mk
MICRO_PROGRAM_SOURCE_ROOT := $(ROOT_DIR)/micro/programs
MICRO_PROGRAM_OUTPUT_ROOT := $(ACTIVE_ARTIFACT_ROOT)/micro-programs/$(RUN_TARGET_ARCH)
MICRO_PROGRAM_SRCS = $(shell find "$(MICRO_PROGRAM_SOURCE_ROOT)" -maxdepth 1 -type f -name '*.bpf.c' -print 2>/dev/null)
MICRO_PROGRAM_OBJECTS = $(patsubst $(MICRO_PROGRAM_SOURCE_ROOT)/%.bpf.c,$(MICRO_PROGRAM_OUTPUT_ROOT)/%.bpf.o,$(MICRO_PROGRAM_SRCS))
RUNNER_BUILD_DIR_ACTIVE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(RUNNER_DIR)/build-arm64-llvmbpf,$(RUNNER_DIR)/build-llvmbpf)
RUNNER_LIBBPF_BUILD_DIR := $(RUNNER_BUILD_DIR_ACTIVE)/vendor/libbpf
RUNNER_LIBBPF_OBJDIR := $(RUNNER_LIBBPF_BUILD_DIR)/obj
RUNNER_LIBBPF_PREFIX := $(RUNNER_LIBBPF_BUILD_DIR)/prefix
RUNNER_LIBBPF_A := $(RUNNER_LIBBPF_OBJDIR)/libbpf.a
DEFAULT_RUNNER_LLVM_DIR := /usr/lib/llvm-18/lib/cmake/llvm
RUNNER_LLVM_DIR := $(if $(strip $(LLVM_DIR)),$(LLVM_DIR),$(if $(strip $(RUN_LLVM_DIR)),$(RUN_LLVM_DIR),$(DEFAULT_RUNNER_LLVM_DIR)))
RUNNER_CONTAINER_CC := /usr/bin/gcc
RUNNER_CONTAINER_CXX := /usr/bin/g++
CONTAINER_IMAGE_ARTIFACT_ROOT := $(ARTIFACT_ROOT)/container-images
KATRAN_BUILD_ROOT := $(REPO_BUILD_ROOT)/katran
ACTIVE_DAEMON_BINARY := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(DAEMON_DIR)/target/aarch64-unknown-linux-gnu/release/bpfrejit-daemon,$(DAEMON_DIR)/target/release/bpfrejit-daemon)
ACTIVE_DAEMON_TARGET_TRIPLE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),aarch64-unknown-linux-gnu,)
ACTIVE_DAEMON_TARGET_ARG := $(if $(strip $(ACTIVE_DAEMON_TARGET_TRIPLE)),TARGET_TRIPLE="$(ACTIVE_DAEMON_TARGET_TRIPLE)",)
ACTIVE_RUNNER_BINARY := $(RUNNER_BUILD_DIR_ACTIVE)/micro_exec
ACTIVE_TEST_UNITTEST_BUILD_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/tests/unittest/build-arm64,$(ROOT_DIR)/tests/unittest/build)
ACTIVE_TEST_NEGATIVE_BUILD_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/tests/negative/build-arm64,$(ROOT_DIR)/tests/negative/build)
ACTIVE_TEST_UNITTEST_PRIMARY := $(ACTIVE_TEST_UNITTEST_BUILD_DIR)/rejit_regression
ACTIVE_TEST_NEGATIVE_PRIMARY := $(ACTIVE_TEST_NEGATIVE_BUILD_DIR)/scx_prog_show_race
RUNNER_RUNTIME_CONTAINERFILE := $(RUNNER_CONTAINER_DIR)/runner-runtime.Dockerfile
BPFREJIT_INSTALL_SCRIPT := $(RUNNER_DIR)/scripts/bpfrejit-install
X86_RUNNER_RUNTIME_IMAGE := bpf-benchmark/runner-runtime:x86_64
ARM64_RUNNER_RUNTIME_IMAGE := bpf-benchmark/runner-runtime:arm64
X86_RUNNER_RUNTIME_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/x86_64-runner-runtime.image.tar
ARM64_RUNNER_RUNTIME_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/arm64-runner-runtime.image.tar
ACTIVE_RUNNER_RUNTIME_IMAGE_TAR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_RUNNER_RUNTIME_IMAGE_TAR),$(X86_RUNNER_RUNTIME_IMAGE_TAR))
X86_RUNTIME_KERNEL_DIR := $(ARTIFACT_ROOT)/runtime-kernel/x86_64
X86_RUNTIME_KERNEL_IMAGE := $(X86_RUNTIME_KERNEL_DIR)/bzImage
ACTIVE_X86_KINSN_SOURCE_DIR := $(ROOT_DIR)/module/x86
ACTIVE_KINSN_SOURCE_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/module/arm64,$(ACTIVE_X86_KINSN_SOURCE_DIR))
ACTIVE_KINSN_MODULE_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/module/arm64,$(ACTIVE_X86_KINSN_SOURCE_DIR))
ACTIVE_KERNEL_BUILD_DIR := $(IMAGE_BUILD_ROOT)/kernel-build
ACTIVE_KERNEL_ARCH_ARG := $(if $(filter arm64,$(RUN_TARGET_ARCH)),ARCH=arm64,)
ACTIVE_KERNEL_DEFCONFIG := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_DEFCONFIG_SRC),$(DEFCONFIG_SRC))
ACTIVE_KERNEL_IMAGE_PATH := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ACTIVE_KERNEL_BUILD_DIR)/arch/arm64/boot/vmlinuz.efi,$(ACTIVE_KERNEL_BUILD_DIR)/arch/x86/boot/bzImage)
ACTIVE_KERNEL_IMAGE_NAME := $(if $(filter arm64,$(RUN_TARGET_ARCH)),vmlinuz.efi,bzImage)
ACTIVE_KERNEL_BUILD_TARGETS := $(if $(filter arm64,$(RUN_TARGET_ARCH)),Image vmlinuz.efi modules,bzImage modules)
ACTIVE_KATRAN_REQUIRED := $(REPO_KATRAN_ROOT)/bin/katran_server_grpc $(REPO_KATRAN_ROOT)/bpf/balancer.bpf.o $(REPO_KATRAN_ROOT)/bpf/healthchecking_ipip.bpf.o $(REPO_KATRAN_ROOT)/bpf/xdp_root.bpf.o

REQUIRE_IMAGE_BUILD = @if [ "$(BPFREJIT_IMAGE_BUILD)" != "1" ]; then echo "$@ must be run from the runner Dockerfile with BPFREJIT_IMAGE_BUILD=1" >&2; exit 1; fi

DAEMON_SOURCE_FILES = $(shell find "$(ROOT_DIR)/daemon/src" -type f 2>/dev/null) $(ROOT_DIR)/daemon/Cargo.toml $(ROOT_DIR)/daemon/Cargo.lock $(ROOT_DIR)/daemon/Makefile
RUNNER_CORE_SOURCE_FILES = $(shell find "$(RUNNER_DIR)/src" "$(RUNNER_DIR)/include" -type f ! -name 'llvmbpf_runner.cpp' 2>/dev/null) $(RUNNER_DIR)/CMakeLists.txt
RUNNER_LLVMBPF_SOURCE_FILES = $(RUNNER_DIR)/src/llvmbpf_runner.cpp $(shell find "$(ROOT_DIR)/vendor/llvmbpf/include" "$(ROOT_DIR)/vendor/llvmbpf/src" -type f 2>/dev/null)
RUNNER_SOURCE_FILES = $(RUNNER_CORE_SOURCE_FILES) $(RUNNER_LLVMBPF_SOURCE_FILES)
TEST_UNITTEST_SOURCE_FILES = $(shell find "$(ROOT_DIR)/tests/unittest" \( -path '*/build' -o -path '*/build-arm64' \) -prune -o -type f -print 2>/dev/null)
TEST_NEGATIVE_SOURCE_FILES = $(shell find "$(ROOT_DIR)/tests/negative" \( -path '*/build' -o -path '*/build-arm64' \) -prune -o -type f -print 2>/dev/null)
MICRO_PROGRAM_SOURCE_FILES = $(MICRO_PROGRAM_SRCS) $(shell find "$(MICRO_PROGRAM_SOURCE_ROOT)" -maxdepth 1 -type f \( -name '*.h' -o -name 'Makefile' \) -print 2>/dev/null)
KINSN_SOURCE_FILES = $(shell find "$(ACTIVE_KINSN_SOURCE_DIR)" "$(ROOT_DIR)/module/include" -type f \( -name '*.c' -o -name '*.h' -o -name 'Makefile' \) -print 2>/dev/null)
KATRAN_SOURCE_FILES = $(shell find "$(REPOS_DIR)/katran" \( -path '*/_build' -o -path '*/deps' -o -path '*/.git' \) -prune -o -type f -print 2>/dev/null)
LIBBPF_SOURCE_FILES = $(shell find "$(ROOT_DIR)/vendor/libbpf" \( -path '*/.git' -o -path '*/build' -o -path '*/obj' -o -path '*/prefix' \) -prune -o -type f -print 2>/dev/null)
VENDOR_LINUX_RUNTIME_SOURCE_FILES = $(ROOT_DIR)/vendor/linux-framework/Makefile $(shell find \
	"$(ROOT_DIR)/vendor/linux-framework/arch/arm64/include/uapi/asm" \
	"$(ROOT_DIR)/vendor/linux-framework/include" \
	"$(ROOT_DIR)/vendor/linux-framework/kernel/bpf" \
	"$(ROOT_DIR)/vendor/linux-framework/scripts" \
	"$(ROOT_DIR)/vendor/linux-framework/tools/arch" \
	"$(ROOT_DIR)/vendor/linux-framework/tools/bpf/bpftool" \
	"$(ROOT_DIR)/vendor/linux-framework/tools/build" \
	"$(ROOT_DIR)/vendor/linux-framework/tools/include" \
	"$(ROOT_DIR)/vendor/linux-framework/tools/lib" \
	"$(ROOT_DIR)/vendor/linux-framework/tools/sched_ext/include" \
	"$(ROOT_DIR)/vendor/linux-framework/tools/scripts" \
	\( -path '*/.git' -o -path '*/build-*' -o -path '*/.cache' \
		-o -path '*/tools/bpf/bpftool/bootstrap' \
		-o -path '*/tools/bpf/bpftool/libbpf' \) -prune -o -type f \
	! -path '*/tools/bpf/bpftool/bpftool' \
	! -path '*/tools/bpf/bpftool/FEATURE-DUMP.bpftool' \
	! -path '*/tools/bpf/bpftool/vmlinux.h' \
	! -name '*.d' ! -name '*.o' ! -name '*.cmd' ! -name '*.skel.h' -print 2>/dev/null)
RUNNER_RUNTIME_SOURCE_FILES = $(shell find "$(RUNNER_DIR)" \( -path "$(RUNNER_DIR)/repos" -o -path '*/__pycache__' -o -path '*/build' -o -path '*/build-*' \) -prune -o -type f \( -name '*.py' -o -name '*.yaml' -o -name '*.env' \) -print 2>/dev/null)
RUNNER_SCRIPT_SOURCE_FILES = $(shell find "$(RUNNER_DIR)/scripts" -type f -print 2>/dev/null)
MICRO_RUNTIME_SOURCE_FILES = $(shell find "$(MICRO_DIR)" \( -path "$(MICRO_PROGRAM_SOURCE_ROOT)" -o -path '*/__pycache__' -o -path '*/build' -o -path '*/build-*' -o -path '*/jit-dumps' -o -path '*/results' \) -prune -o -type f -print 2>/dev/null)
CORPUS_RUNTIME_SOURCE_FILES = $(shell find "$(ROOT_DIR)/corpus" \( -path '*/__pycache__' -o -path '*/build' -o -path '*/results' \) -prune -o -type f -print 2>/dev/null)
E2E_RUNTIME_SOURCE_FILES = $(shell find "$(ROOT_DIR)/e2e" \( -path '*/__pycache__' -o -path '*/results' \) -prune -o -type f -print 2>/dev/null)
KERNEL_BUILD_META_FILES = $(shell find "$(KERNEL_DIR)" \( -path '*/.git' -o -path '*/build*' -o -path '*/.cache' \) -prune -o -type f \( -name 'Makefile' -o -name 'Kconfig*' -o -name '*.mk' -o -path '*/scripts/config' \) -print 2>/dev/null)
KERNEL_SOURCE_FILES = $(shell find "$(KERNEL_DIR)" \( -path '*/.git' -o -path '*/build*' -o -path '*/.cache' \) -prune -o -type f \( -name '*.c' -o -name '*.h' -o -name '*.S' -o -name '*.lds' -o -name '*.dts' -o -name '*.dtsi' -o -name '*.sh' \) -print 2>/dev/null)
RUNNER_RUNTIME_IMAGE_SOURCE_FILES = $(BUILD_RULE_FILES) $(RUNNER_RUNTIME_CONTAINERFILE) $(DOCKERIGNORE_FILE) \
	$(DAEMON_SOURCE_FILES) $(RUNNER_SOURCE_FILES) $(TEST_UNITTEST_SOURCE_FILES) $(TEST_NEGATIVE_SOURCE_FILES) \
	$(MICRO_PROGRAM_SOURCE_FILES) $(KINSN_SOURCE_FILES) $(KATRAN_SOURCE_FILES) \
	$(LIBBPF_SOURCE_FILES) $(VENDOR_LINUX_RUNTIME_SOURCE_FILES) \
	$(RUNNER_RUNTIME_SOURCE_FILES) $(RUNNER_SCRIPT_SOURCE_FILES) $(MICRO_RUNTIME_SOURCE_FILES) $(CORPUS_RUNTIME_SOURCE_FILES) \
	$(E2E_RUNTIME_SOURCE_FILES) $(KERNEL_BUILD_META_FILES) $(KERNEL_SOURCE_FILES) $(DEFCONFIG_SRC) $(ARM64_DEFCONFIG_SRC)
BUILD_INPUT_SOURCE_FILES = $(sort \
	$(DAEMON_SOURCE_FILES) $(RUNNER_SOURCE_FILES) $(TEST_UNITTEST_SOURCE_FILES) $(TEST_NEGATIVE_SOURCE_FILES) \
	$(MICRO_PROGRAM_SOURCE_FILES) $(KINSN_SOURCE_FILES) $(KATRAN_SOURCE_FILES) \
	$(LIBBPF_SOURCE_FILES) $(VENDOR_LINUX_RUNTIME_SOURCE_FILES) \
	$(RUNNER_RUNTIME_SOURCE_FILES) $(RUNNER_SCRIPT_SOURCE_FILES) $(MICRO_RUNTIME_SOURCE_FILES) $(CORPUS_RUNTIME_SOURCE_FILES) \
	$(E2E_RUNTIME_SOURCE_FILES) $(KERNEL_BUILD_META_FILES) $(KERNEL_SOURCE_FILES))

$(BUILD_INPUT_SOURCE_FILES): ;

.PHONY: FORCE
FORCE:

$(X86_RUNNER_RUNTIME_IMAGE_TAR): $(RUNNER_RUNTIME_IMAGE_SOURCE_FILES)
	@mkdir -p "$(dir $@)"
	docker build --platform linux/amd64 \
		--target runner-runtime \
		--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
		--build-arg IMAGE_BUILD_JOBS="$(IMAGE_BUILD_JOBS)" \
		--build-arg RUN_TARGET_ARCH=x86_64 \
		-t "$(X86_RUNNER_RUNTIME_IMAGE)" -f "$(RUNNER_RUNTIME_CONTAINERFILE)" "$(ROOT_DIR)"
	docker save -o "$@" "$(X86_RUNNER_RUNTIME_IMAGE)"

$(ARM64_RUNNER_RUNTIME_IMAGE_TAR): $(RUNNER_RUNTIME_IMAGE_SOURCE_FILES)
	@mkdir -p "$(dir $@)"
	docker build --platform linux/arm64 \
		--target runner-runtime \
		--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
		--build-arg IMAGE_BUILD_JOBS="$(ARM64_IMAGE_BUILD_JOBS)" \
		--build-arg RUN_TARGET_ARCH=arm64 \
		-t "$(ARM64_RUNNER_RUNTIME_IMAGE)" -f "$(RUNNER_RUNTIME_CONTAINERFILE)" "$(ROOT_DIR)"
	docker save -o "$@" "$(ARM64_RUNNER_RUNTIME_IMAGE)"

.PHONY: image-runner-runtime-image-tar
image-runner-runtime-image-tar: $(ACTIVE_RUNNER_RUNTIME_IMAGE_TAR)

$(X86_RUNTIME_KERNEL_IMAGE): $(X86_RUNNER_RUNTIME_IMAGE_TAR) $(BPFREJIT_INSTALL_SCRIPT)
	@mkdir -p "$(X86_RUNTIME_KERNEL_DIR)"
	BPFREJIT_INSTALL_KERNEL_OUT_DIR="$(X86_RUNTIME_KERNEL_DIR)" \
		"$(BPFREJIT_INSTALL_SCRIPT)" --extract-kernel-only "$<"
	test -s "$@"

.PHONY: image-kernel-artifacts image-kernel-build image-kernel-modules-artifacts image-kinsn-artifacts

image-kernel-artifacts:
	$(REQUIRE_IMAGE_BUILD)
	rm -rf "$(KERNEL_ARTIFACT_ROOT)/kernel" "$(KERNEL_ARTIFACT_ROOT)/modules" "$(KERNEL_ARTIFACT_ROOT)/kinsn" "$(KERNEL_ARTIFACT_ROOT)/manifest.json"
	mkdir -p "$(KERNEL_ARTIFACT_ROOT)/kernel" "$(KERNEL_ARTIFACT_ROOT)/modules" "$(KERNEL_ARTIFACT_ROOT)/kinsn"
	$(MAKE) image-kernel-build RUN_TARGET_ARCH="$(RUN_TARGET_ARCH)" ACTIVE_KERNEL_BUILD_DIR="$(ACTIVE_KERNEL_BUILD_DIR)"
	$(MAKE) image-kernel-modules-artifacts RUN_TARGET_ARCH="$(RUN_TARGET_ARCH)" ACTIVE_KERNEL_BUILD_DIR="$(ACTIVE_KERNEL_BUILD_DIR)" KERNEL_MODULES_ARTIFACT_ROOT="$(KERNEL_ARTIFACT_ROOT)/modules"
	$(MAKE) image-kinsn-artifacts RUN_TARGET_ARCH="$(RUN_TARGET_ARCH)" ACTIVE_KERNEL_BUILD_DIR="$(ACTIVE_KERNEL_BUILD_DIR)" ACTIVE_KINSN_MODULE_DIR="$(KERNEL_ARTIFACT_ROOT)/kinsn"
	cp -a "$(ACTIVE_KERNEL_IMAGE_PATH)" "$(KERNEL_ARTIFACT_ROOT)/kernel/$(ACTIVE_KERNEL_IMAGE_NAME)"
	kernel_release="$$(tr -d '\n' < "$(ACTIVE_KERNEL_BUILD_DIR)/include/config/kernel.release")"; \
	printf '{\n  "kernel_release": "%s",\n  "target_arch": "%s",\n  "kernel_image": "%s"\n}\n' \
		"$$kernel_release" "$(RUN_TARGET_ARCH)" "$(ACTIVE_KERNEL_IMAGE_NAME)" >"$(KERNEL_ARTIFACT_ROOT)/manifest.json"; \
	test -s "$(KERNEL_ARTIFACT_ROOT)/kernel/$(ACTIVE_KERNEL_IMAGE_NAME)"; \
	test -d "$(KERNEL_ARTIFACT_ROOT)/modules/$$kernel_release"; \
	find "$(KERNEL_ARTIFACT_ROOT)/kinsn" -type f -name '*.ko' | grep -q .

image-kernel-build:
	$(REQUIRE_IMAGE_BUILD)
	mkdir -p "$(ACTIVE_KERNEL_BUILD_DIR)"
	cp "$(ACTIVE_KERNEL_DEFCONFIG)" "$(ACTIVE_KERNEL_BUILD_DIR)/.config"
	"$(KERNEL_DIR)/scripts/config" --file "$(ACTIVE_KERNEL_BUILD_DIR)/.config" --enable BLK_DEV_LOOP
	"$(KERNEL_DIR)/scripts/config" --file "$(ACTIVE_KERNEL_BUILD_DIR)/.config" --enable VIRTIO_CONSOLE
	"$(KERNEL_DIR)/scripts/config" --file "$(ACTIVE_KERNEL_BUILD_DIR)/.config" --enable EXT4_FS
	"$(KERNEL_DIR)/scripts/config" --file "$(ACTIVE_KERNEL_BUILD_DIR)/.config" --enable JBD2
	"$(KERNEL_DIR)/scripts/config" --file "$(ACTIVE_KERNEL_BUILD_DIR)/.config" --enable FS_MBCACHE
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		make -C "$(KERNEL_DIR)" O="$(ACTIVE_KERNEL_BUILD_DIR)" ARCH=arm64 CROSS_COMPILE= olddefconfig; \
		find "$(ACTIVE_KERNEL_BUILD_DIR)" -type f -name '*.o' -size 0 -delete; \
		rm -f "$(ACTIVE_KERNEL_BUILD_DIR)/vmlinux.a" "$(ACTIVE_KERNEL_BUILD_DIR)/vmlinux.o" "$(ACTIVE_KERNEL_BUILD_DIR)/drivers/of/built-in.a"; \
		make -C "$(KERNEL_DIR)" O="$(ACTIVE_KERNEL_BUILD_DIR)" ARCH=arm64 CROSS_COMPILE= $(ACTIVE_KERNEL_BUILD_TARGETS) -j"$(JOBS)"; \
	else \
		make -C "$(KERNEL_DIR)" O="$(ACTIVE_KERNEL_BUILD_DIR)" olddefconfig; \
		make -C "$(KERNEL_DIR)" O="$(ACTIVE_KERNEL_BUILD_DIR)" $(ACTIVE_KERNEL_BUILD_TARGETS) -j"$(JOBS)"; \
	fi
	test -f "$(ACTIVE_KERNEL_BUILD_DIR)/include/config/kernel.release"
	test -s "$(ACTIVE_KERNEL_IMAGE_PATH)"

image-kernel-modules-artifacts:
	$(REQUIRE_IMAGE_BUILD)
	stage_root="$(KERNEL_MODULES_ARTIFACT_ROOT)"; \
	kernel_release_file="$(ACTIVE_KERNEL_BUILD_DIR)/include/config/kernel.release"; \
	test -f "$$kernel_release_file" || { echo "missing kernel release file: $$kernel_release_file" >&2; exit 1; }; \
	kernel_release="$$(tr -d '\n' < "$$kernel_release_file")"; \
	install_root="$(IMAGE_BUILD_ROOT)/modules-install"; \
	release_root="$$stage_root/$$kernel_release"; \
	mkdir -p "$$stage_root"; \
	rm -rf "$$install_root" "$$release_root"; \
	make $(ACTIVE_KERNEL_ARCH_ARG) --no-print-directory -C "$(KERNEL_DIR)" O="$(ACTIVE_KERNEL_BUILD_DIR)" INSTALL_MOD_PATH="$$install_root" DEPMOD=true modules_install >/dev/null; \
	depmod -b "$$install_root" "$$kernel_release" >/dev/null; \
	cp -a "$$install_root/lib/modules/$$kernel_release" "$$release_root"; \
	rm -f "$$release_root/build" "$$release_root/source"; \
	test -f "$$release_root/kernel/drivers/block/null_blk/null_blk.ko"; \
	test -f "$$release_root/kernel/net/sched/sch_netem.ko"; \
	touch "$$stage_root"

image-kinsn-artifacts:
	$(REQUIRE_IMAGE_BUILD)
	mkdir -p "$(ACTIVE_KINSN_MODULE_DIR)"
	make $(ACTIVE_KERNEL_ARCH_ARG) -C "$(KERNEL_DIR)" O="$(ACTIVE_KERNEL_BUILD_DIR)" M="$(ACTIVE_KINSN_SOURCE_DIR)" MO="$(ACTIVE_KINSN_MODULE_DIR)" modules

.PHONY: image-katran-artifacts image-runner-artifacts image-daemon-artifact \
	image-micro-program-artifacts image-test-artifacts
ifneq ($(BPFREJIT_IMAGE_BUILD),1)
image-katran-artifacts image-runner-artifacts image-daemon-artifact image-micro-program-artifacts image-test-artifacts:
	@echo "$@ must be run from the runner Dockerfile with BPFREJIT_IMAGE_BUILD=1" >&2
	@exit 1
else
image-katran-artifacts: $(ACTIVE_KATRAN_REQUIRED)
image-runner-artifacts: $(ACTIVE_RUNNER_BINARY)
image-daemon-artifact: $(ACTIVE_DAEMON_BINARY)
image-micro-program-artifacts: $(MICRO_PROGRAM_OBJECTS)
image-test-artifacts: $(ACTIVE_TEST_UNITTEST_PRIMARY) $(ACTIVE_TEST_NEGATIVE_PRIMARY)

$(RUNNER_LIBBPF_A): $(LIBBPF_SOURCE_FILES) $(BUILD_RULE_FILES)
	rm -rf "$(RUNNER_LIBBPF_OBJDIR)" "$(RUNNER_LIBBPF_PREFIX)"
	mkdir -p "$(RUNNER_LIBBPF_OBJDIR)" "$(RUNNER_LIBBPF_PREFIX)/include"
	make -C "$(ROOT_DIR)/vendor/libbpf/src" -j"$(JOBS)" BUILD_STATIC_ONLY=1 \
		OBJDIR="$(RUNNER_LIBBPF_OBJDIR)" DESTDIR= PREFIX="$(RUNNER_LIBBPF_PREFIX)" \
		"$(RUNNER_LIBBPF_A)" install_headers

$(ACTIVE_DAEMON_BINARY): $(DAEMON_SOURCE_FILES) $(BUILD_RULE_FILES)
	mkdir -p "$(dir $@)"
	make -C "$(ROOT_DIR)/daemon" release TARGET_DIR="$(DAEMON_DIR)/target" $(ACTIVE_DAEMON_TARGET_ARG)

$(ACTIVE_RUNNER_BINARY): $(RUNNER_LIBBPF_A) $(RUNNER_SOURCE_FILES) $(BUILD_RULE_FILES)
	mkdir -p "$(dir $@)"
	rm -rf "$(RUNNER_BUILD_DIR_ACTIVE)/CMakeCache.txt" "$(RUNNER_BUILD_DIR_ACTIVE)/CMakeFiles"
	cmake -S "$(RUNNER_DIR)" -B "$(RUNNER_BUILD_DIR_ACTIVE)" \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_C_COMPILER="$(RUNNER_CONTAINER_CC)" \
		-DCMAKE_CXX_COMPILER="$(RUNNER_CONTAINER_CXX)" \
		-DMICRO_REPO_ROOT="$(ROOT_DIR)" \
		-DMICRO_LIBBPF_PREFIX="$(RUNNER_LIBBPF_PREFIX)" \
		-DMICRO_LIBBPF_LIBRARY="$(RUNNER_LIBBPF_A)" \
		-DMICRO_EXEC_ENABLE_LLVMBPF="1" \
		-DLLVM_DIR="$(RUNNER_LLVM_DIR)"
	cmake --build "$(RUNNER_BUILD_DIR_ACTIVE)" --target micro_exec -j"$(JOBS)"

$(ACTIVE_TEST_UNITTEST_PRIMARY): $(TEST_UNITTEST_SOURCE_FILES) $(BUILD_RULE_FILES)
	mkdir -p "$(ACTIVE_TEST_UNITTEST_BUILD_DIR)" "$(ACTIVE_TEST_UNITTEST_BUILD_DIR)/vendor/bpftool"
	make -C "$(ROOT_DIR)/tests/unittest" BUILD_DIR="$(ACTIVE_TEST_UNITTEST_BUILD_DIR)" CC=gcc CLANG=clang BPF_TARGET_ARCH="$(RUN_TARGET_ARCH)"

$(ACTIVE_TEST_NEGATIVE_PRIMARY): $(TEST_NEGATIVE_SOURCE_FILES) $(BUILD_RULE_FILES)
	mkdir -p "$(ACTIVE_TEST_NEGATIVE_BUILD_DIR)"
	make -C "$(ROOT_DIR)/tests/negative" BUILD_DIR="$(ACTIVE_TEST_NEGATIVE_BUILD_DIR)" CC=gcc

$(MICRO_PROGRAM_OBJECTS) &: $(MICRO_PROGRAM_SOURCE_FILES) $(BUILD_RULE_FILES)
	mkdir -p "$(MICRO_PROGRAM_OUTPUT_ROOT)"
	make -C "$(MICRO_PROGRAM_SOURCE_ROOT)" OUTPUT_DIR="$(MICRO_PROGRAM_OUTPUT_ROOT)" all
	for path in $(MICRO_PROGRAM_OBJECTS); do test -f "$$path"; done

# GCC 13 can ICE while compiling grpc's tcp_client_posix.cc on Ubuntu 24.04.
# Build Katran's C/C++ userspace stack with clang instead.
$(ACTIVE_KATRAN_REQUIRED) &: $(KATRAN_SOURCE_FILES) $(BUILD_RULE_FILES)
	repo_root="$(REPOS_DIR)/katran"; \
	build_root="$(KATRAN_BUILD_ROOT)"; \
	install_root="$(REPO_KATRAN_ROOT)"; \
	artifact_root="$(REPO_KATRAN_ROOT)"; \
	override_file="$(KATRAN_BUILD_ROOT)/cxx-override.cmake"; \
	bpf_root="$$artifact_root/bpf"; \
	system_libdir="$$(pkg-config --variable=libdir libelf)"; \
	mkdir -p "$$install_root/bin" "$$install_root/lib" "$$install_root/lib64" "$$bpf_root" "$$build_root"; \
	printf '%s\n' 'set(CMAKE_CXX_COMPILE_OBJECT "<CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -std=gnu++20 -o <OBJECT> -c <SOURCE>")' > "$$override_file"; \
	cd "$$repo_root" && env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR \
		CC=clang CXX=clang++ AR=ar RANLIB=ranlib \
		NCPUS="$(JOBS)" \
		KATRAN_SKIP_SYSTEM_PACKAGES=1 BUILD_EXAMPLE_GRPC=1 BUILD_DIR="$$build_root" INSTALL_DIR="$$install_root" INSTALL_DEPS_ONLY=1 ./build_katran.sh; \
	for cmake_file in "$$install_root"/lib/cmake/folly/folly-targets*.cmake "$$install_root"/lib64/cmake/folly/folly-targets*.cmake; do \
		[ -f "$$cmake_file" ] || continue; \
		sed -i \
			-e "s#gflags_nothreads_static#$$system_libdir/libgflags.so#g" \
			-e "s#gflags_static#$$system_libdir/libgflags.so#g" \
			"$$cmake_file"; \
	done; \
	mkdir -p "$$install_root/grpc/_build"; \
	ln -sfn "$$install_root/bin/grpc_cpp_plugin" "$$install_root/grpc/_build/grpc_cpp_plugin"; \
	rm -rf "$$build_root/build"; \
	env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR CMAKE_BUILD_EXAMPLE_GRPC=1 \
		CC=clang CXX=clang++ AR=ar RANLIB=ranlib \
		cmake -S "$$repo_root" -B "$$build_root/build" \
			-DCMAKE_PREFIX_PATH="$$install_root" \
			-DCMAKE_INSTALL_PREFIX="$$install_root" \
			-DCMAKE_BUILD_TYPE=RelWithDebInfo \
			-DPKG_CONFIG_USE_CMAKE_PREFIX_PATH=ON \
			-DLIB_BPF_PREFIX="$$install_root" \
			-DLIBELF="$$system_libdir/libelf.so" \
			-DGLOG_LIBRARY="$$system_libdir/libglog.so" \
			-DGLOG_INCLUDE_DIR=/usr/include \
			-Dgflags_DIR="$$system_libdir/cmake/gflags" \
			-DGFLAGS_SHARED=ON \
			-DGFLAGS_NOTHREADS=OFF \
			-DCMAKE_CXX_STANDARD=20 \
			-DCMAKE_CXX_FLAGS="-fpermissive" \
			-DCMAKE_C_COMPILER=clang \
			-DCMAKE_CXX_COMPILER=clang++ \
			-DCMAKE_AR=/usr/bin/ar \
			-DCMAKE_RANLIB=/usr/bin/ranlib \
			-DCMAKE_USER_MAKE_RULES_OVERRIDE_CXX="$$override_file" \
			-DBUILD_TESTS=OFF; \
	cmake --build "$$build_root/build" --target install -j"$(JOBS)"; \
	if [ -x "$$install_root/example/katran_server_grpc" ]; then \
		mkdir -p "$$install_root/bin"; \
		cp -f "$$install_root/example/katran_server_grpc" "$$install_root/bin/katran_server_grpc"; \
		chmod 0755 "$$install_root/bin/katran_server_grpc"; \
	fi; \
	cd "$$repo_root" && ./build_bpf_modules_opensource.sh -s "$$repo_root" -b "$$build_root" -o "$$bpf_root"; \
	bpfprog_bpf="$$build_root/deps/bpfprog/bpf"; \
	if [ -d "$$bpfprog_bpf" ]; then \
		mkdir -p "$$bpf_root"; \
		cp -f "$$bpfprog_bpf"/*.o "$$bpf_root"/; \
	fi; \
	test -x "$$install_root/bin/katran_server_grpc" || { echo "missing Katran install output: $$install_root/bin/katran_server_grpc" >&2; exit 1; }; \
	[ -f "$$bpf_root/healthchecking_ipip.o" ] && mv -f "$$bpf_root/healthchecking_ipip.o" "$$bpf_root/healthchecking_ipip.bpf.o" || true; \
	[ -f "$$bpf_root/xdp_root.o" ] && mv -f "$$bpf_root/xdp_root.o" "$$bpf_root/xdp_root.bpf.o" || true; \
	for path in $(ACTIVE_KATRAN_REQUIRED); do test -e "$$path"; done; \
	touch $(ACTIVE_KATRAN_REQUIRED)

endif
