REPOS_DIR := $(RUNNER_DIR)/repos
RUNNER_CONTAINER_DIR := $(RUNNER_DIR)/containers
RUN_TARGET_ARCH ?= x86_64
IMAGE_BUILD_JOBS ?= $(JOBS)
ARM64_IMAGE_BUILD_JOBS ?= 4
DOCKERIGNORE_FILE := $(ROOT_DIR)/.dockerignore
X86_BUILD_DISTRO_VARIANT := ubuntu24.04
BUILD_ARCH_VARIANT := $(if $(filter x86_64,$(RUN_TARGET_ARCH)),-$(X86_BUILD_DISTRO_VARIANT),)
IMAGE_ARTIFACT_ROOT ?= /artifacts/user
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
ACTIVE_BPFOPT_TARGET_ARG := $(if $(strip $(ACTIVE_DAEMON_TARGET_TRIPLE)),--target "$(ACTIVE_DAEMON_TARGET_TRIPLE)",)
ACTIVE_BPFOPT_BINARY_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/bpfopt/target/aarch64-unknown-linux-gnu/release,$(ROOT_DIR)/bpfopt/target/release)
ACTIVE_BPFOPT_BINARIES := $(addprefix $(ACTIVE_BPFOPT_BINARY_DIR)/,bpfopt bpfget bpfrejit bpfverify bpfprof)
ACTIVE_RUNNER_BINARY := $(RUNNER_BUILD_DIR_ACTIVE)/micro_exec
ACTIVE_TEST_UNITTEST_BUILD_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/tests/unittest/build-arm64,$(ROOT_DIR)/tests/unittest/build)
ACTIVE_TEST_NEGATIVE_BUILD_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/tests/negative/build-arm64,$(ROOT_DIR)/tests/negative/build)
ACTIVE_TEST_UNITTEST_PRIMARY := $(ACTIVE_TEST_UNITTEST_BUILD_DIR)/rejit_regression
ACTIVE_TEST_NEGATIVE_PRIMARY := $(ACTIVE_TEST_NEGATIVE_BUILD_DIR)/adversarial_rejit
RUNNER_RUNTIME_CONTAINERFILE := $(RUNNER_CONTAINER_DIR)/runner-runtime.Dockerfile
KERNEL_FORK_CONTAINERFILE := $(RUNNER_CONTAINER_DIR)/kernel-fork.Dockerfile
KATRAN_ARTIFACTS_CONTAINERFILE := $(RUNNER_CONTAINER_DIR)/katran-artifacts.Dockerfile
BPFREJIT_INSTALL_SCRIPT := $(RUNNER_DIR)/scripts/bpfrejit-install
KERNEL_FORK_COMMIT_SHORT_LEN := 7
KERNEL_FORK_COMMIT := $(shell cd "$(KERNEL_DIR)" && hash=$$(git rev-parse HEAD) && printf '%.$(KERNEL_FORK_COMMIT_SHORT_LEN)s\n' "$$hash")
KERNEL_FORK_COMMIT_X86 := $(KERNEL_FORK_COMMIT)
KERNEL_FORK_COMMIT_ARM64 := $(KERNEL_FORK_COMMIT)
X86_RUNNER_RUNTIME_IMAGE := bpf-benchmark/runner-runtime:x86_64
ARM64_RUNNER_RUNTIME_IMAGE := bpf-benchmark/runner-runtime:arm64
X86_KERNEL_FORK_IMAGE := bpf-benchmark/kernel-fork:x86_64-$(KERNEL_FORK_COMMIT_X86)
ARM64_KERNEL_FORK_IMAGE := bpf-benchmark/kernel-fork:arm64-$(KERNEL_FORK_COMMIT_ARM64)
X86_KATRAN_ARTIFACTS_IMAGE := bpf-benchmark/katran-artifacts:x86_64
ARM64_KATRAN_ARTIFACTS_IMAGE := bpf-benchmark/katran-artifacts:arm64
GHCR_IMAGE_PREFIX ?= ghcr.io/eunomia-bpf
GHCR_KERNEL_FORK_IMAGE_REPOSITORY := $(GHCR_IMAGE_PREFIX)/bpf-benchmark-kernel-fork
GHCR_KATRAN_ARTIFACTS_IMAGE_REPOSITORY := $(GHCR_IMAGE_PREFIX)/bpf-benchmark-katran-artifacts
X86_KERNEL_FORK_GHCR_IMAGE := $(GHCR_KERNEL_FORK_IMAGE_REPOSITORY):x86_64-$(KERNEL_FORK_COMMIT_X86)
ARM64_KERNEL_FORK_GHCR_IMAGE := $(GHCR_KERNEL_FORK_IMAGE_REPOSITORY):arm64-$(KERNEL_FORK_COMMIT_ARM64)
X86_KATRAN_ARTIFACTS_GHCR_IMAGE := $(GHCR_KATRAN_ARTIFACTS_IMAGE_REPOSITORY):x86_64
ARM64_KATRAN_ARTIFACTS_GHCR_IMAGE := $(GHCR_KATRAN_ARTIFACTS_IMAGE_REPOSITORY):arm64
X86_RUNNER_RUNTIME_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/x86_64-runner-runtime.image.tar
ARM64_RUNNER_RUNTIME_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/arm64-runner-runtime.image.tar
X86_KERNEL_FORK_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/x86_64-kernel-fork-$(KERNEL_FORK_COMMIT_X86).image.tar
ARM64_KERNEL_FORK_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/arm64-kernel-fork-$(KERNEL_FORK_COMMIT_ARM64).image.tar
X86_KATRAN_ARTIFACTS_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/x86_64-katran-artifacts.image.tar
ARM64_KATRAN_ARTIFACTS_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/arm64-katran-artifacts.image.tar
ACTIVE_KERNEL_FORK_IMAGE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_KERNEL_FORK_IMAGE),$(X86_KERNEL_FORK_IMAGE))
ACTIVE_KATRAN_ARTIFACTS_IMAGE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_KATRAN_ARTIFACTS_IMAGE),$(X86_KATRAN_ARTIFACTS_IMAGE))
ACTIVE_KERNEL_FORK_GHCR_IMAGE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_KERNEL_FORK_GHCR_IMAGE),$(X86_KERNEL_FORK_GHCR_IMAGE))
ACTIVE_KATRAN_ARTIFACTS_GHCR_IMAGE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_KATRAN_ARTIFACTS_GHCR_IMAGE),$(X86_KATRAN_ARTIFACTS_GHCR_IMAGE))
ACTIVE_RUNNER_RUNTIME_IMAGE_TAR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_RUNNER_RUNTIME_IMAGE_TAR),$(X86_RUNNER_RUNTIME_IMAGE_TAR))
ACTIVE_KERNEL_FORK_IMAGE_TAR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_KERNEL_FORK_IMAGE_TAR),$(X86_KERNEL_FORK_IMAGE_TAR))
ACTIVE_KATRAN_ARTIFACTS_IMAGE_TAR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_KATRAN_ARTIFACTS_IMAGE_TAR),$(X86_KATRAN_ARTIFACTS_IMAGE_TAR))
KERNEL_FORK_BUILD_PLATFORM ?= linux/amd64
X86_KERNEL_FORK_PULL_PLATFORM := $(KERNEL_FORK_BUILD_PLATFORM)
ARM64_KERNEL_FORK_PULL_PLATFORM := $(KERNEL_FORK_BUILD_PLATFORM)
X86_KATRAN_ARTIFACTS_PULL_PLATFORM := linux/amd64
ARM64_KATRAN_ARTIFACTS_PULL_PLATFORM := linux/arm64
X86_RUNTIME_KERNEL_DIR := $(ARTIFACT_ROOT)/runtime-kernel/x86_64
X86_RUNTIME_KERNEL_IMAGE := $(X86_RUNTIME_KERNEL_DIR)/bzImage
X86_AWS_KERNEL_IMAGE := $(X86_BUILD_DIR)/arch/x86/boot/bzImage
X86_AWS_KERNEL_RELEASE_FILE := $(X86_BUILD_DIR)/include/config/kernel.release
X86_AWS_KERNEL_MODULES_ROOT := $(ARTIFACT_ROOT)/repo-artifacts/x86_64/kernel-modules/lib/modules
X86_AWS_KERNEL_ARTIFACT_STAMP := $(X86_BUILD_DIR)/.aws-kernel-artifacts.stamp
ACTIVE_X86_KINSN_SOURCE_DIR := $(ROOT_DIR)/module/x86
ACTIVE_KINSN_SOURCE_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/module/arm64,$(ACTIVE_X86_KINSN_SOURCE_DIR))
ACTIVE_KATRAN_REQUIRED := $(REPO_KATRAN_ROOT)/bin/katran_server_grpc $(REPO_KATRAN_ROOT)/bpf/balancer.bpf.o $(REPO_KATRAN_ROOT)/bpf/healthchecking_ipip.bpf.o $(REPO_KATRAN_ROOT)/bpf/xdp_root.bpf.o

REQUIRE_IMAGE_BUILD = @if [ "$(BPFREJIT_IMAGE_BUILD)" != "1" ]; then echo "$@ must be run from the runner Dockerfile with BPFREJIT_IMAGE_BUILD=1" >&2; exit 1; fi

KERNEL_SYS_SOURCE_FILES = $(shell find "$(ROOT_DIR)/bpfopt/crates/kernel-sys" -type f \( -name '*.rs' -o -name 'Cargo.toml' \) -print 2>/dev/null) $(ROOT_DIR)/bpfopt/Cargo.toml
BPFOPT_SOURCE_FILES = $(shell find "$(ROOT_DIR)/bpfopt/crates" -type f \( -name '*.rs' -o -name 'Cargo.toml' \) -print 2>/dev/null) $(ROOT_DIR)/bpfopt/Cargo.toml $(ROOT_DIR)/bpfopt/Cargo.lock
DAEMON_SOURCE_FILES = $(shell find "$(ROOT_DIR)/daemon/src" -type f 2>/dev/null) $(ROOT_DIR)/daemon/Cargo.toml $(ROOT_DIR)/daemon/Cargo.lock $(ROOT_DIR)/daemon/Makefile $(KERNEL_SYS_SOURCE_FILES)
RUNNER_CORE_SOURCE_FILES = $(shell find "$(RUNNER_DIR)/src" "$(RUNNER_DIR)/include" -type f ! -name 'llvmbpf_runner.cpp' 2>/dev/null) $(RUNNER_DIR)/CMakeLists.txt
RUNNER_LLVMBPF_SOURCE_FILES = $(RUNNER_DIR)/src/llvmbpf_runner.cpp $(shell find "$(ROOT_DIR)/vendor/llvmbpf/include" "$(ROOT_DIR)/vendor/llvmbpf/src" -type f 2>/dev/null)
RUNNER_SOURCE_FILES = $(RUNNER_CORE_SOURCE_FILES) $(RUNNER_LLVMBPF_SOURCE_FILES)
TEST_UNITTEST_SOURCE_FILES = $(shell find "$(ROOT_DIR)/tests/unittest" \( -path '*/build' -o -path '*/build-arm64' \) -prune -o -type f -print 2>/dev/null)
TEST_NEGATIVE_SOURCE_FILES = $(shell find "$(ROOT_DIR)/tests/negative" \( -path '*/build' -o -path '*/build-arm64' \) -prune -o -type f -print 2>/dev/null)
MICRO_PROGRAM_SOURCE_FILES = $(MICRO_PROGRAM_SRCS) $(shell find "$(MICRO_PROGRAM_SOURCE_ROOT)" -maxdepth 1 -type f \( -name '*.h' -o -name 'Makefile' \) -print 2>/dev/null)
KINSN_SOURCE_FILES = $(shell find "$(ACTIVE_KINSN_SOURCE_DIR)" "$(ROOT_DIR)/module/include" -type f \( -name '*.c' -o -name '*.h' -o -name 'Makefile' \) -print 2>/dev/null)
KATRAN_SOURCE_FILES = $(shell find "$(REPOS_DIR)/katran" \( -path '*/_build' -o -path '*/deps' -o -path '*/.git' \) -prune -o -type f -print 2>/dev/null)
LIBBPF_SOURCE_FILES = $(shell find "$(ROOT_DIR)/vendor/libbpf" \( -path '*/.git' -o -path '*/build' -o -path '*/obj' -o -path '*/prefix' \) -prune -o -type f \
	\( -name '*.[ch]' -o -name '*.S' -o -name '*.lds' -o -name '*.map' -o -name '*.mk' -o -name '*.sh' \
		-o -name '*.template' -o -name 'Build' -o -name 'Makefile' \) -print 2>/dev/null)
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
	"$(ROOT_DIR)/vendor/linux-framework/tools/scripts" \
		\( -path '*/.git' -o -path '*/build-*' -o -path '*/.cache' \
			-o -path '*/tools/bpf/bpftool/bootstrap' \
			-o -path '*/tools/bpf/bpftool/libbpf' \) -prune -o -type f \
		\( -name '*.[ch]' -o -name '*.S' -o -name '*.lds' -o -name '*.mk' -o -name '*.sh' \
			-o -name '*.y' -o -name '*.l' -o -name '*.pl' -o -name '*.awk' \
			-o -name 'Build' -o -name 'Kbuild' -o -name 'Makefile' \) \
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
KERNEL_FORK_IMAGE_SOURCE_FILES = $(KERNEL_FORK_CONTAINERFILE) $(DOCKERIGNORE_FILE) \
	$(KERNEL_BUILD_META_FILES) $(KERNEL_SOURCE_FILES) $(DEFCONFIG_SRC) $(ARM64_DEFCONFIG_SRC)
KATRAN_ARTIFACTS_IMAGE_SOURCE_FILES = $(BUILD_RULE_FILES) $(KATRAN_ARTIFACTS_CONTAINERFILE) $(DOCKERIGNORE_FILE) \
	$(KATRAN_SOURCE_FILES) $(VENDOR_LINUX_RUNTIME_SOURCE_FILES)
RUNNER_RUNTIME_IMAGE_SOURCE_FILES = $(BUILD_RULE_FILES) $(RUNNER_RUNTIME_CONTAINERFILE) $(DOCKERIGNORE_FILE) \
	$(DAEMON_SOURCE_FILES) $(BPFOPT_SOURCE_FILES) $(RUNNER_SOURCE_FILES) $(TEST_UNITTEST_SOURCE_FILES) $(TEST_NEGATIVE_SOURCE_FILES) \
	$(MICRO_PROGRAM_SOURCE_FILES) $(KINSN_SOURCE_FILES) \
	$(LIBBPF_SOURCE_FILES) $(VENDOR_LINUX_RUNTIME_SOURCE_FILES) $(RUNNER_SCRIPT_SOURCE_FILES)
RUNNER_RUNTIME_IMAGE_LAYER_FILES = $(RUNNER_RUNTIME_SOURCE_FILES) $(MICRO_RUNTIME_SOURCE_FILES) \
	$(CORPUS_RUNTIME_SOURCE_FILES) $(E2E_RUNTIME_SOURCE_FILES)
RUNNER_RUNTIME_IMAGE_INPUT_FILES = $(RUNNER_RUNTIME_IMAGE_SOURCE_FILES) $(RUNNER_RUNTIME_IMAGE_LAYER_FILES)
BUILD_INPUT_SOURCE_FILES = $(sort \
	$(DAEMON_SOURCE_FILES) $(BPFOPT_SOURCE_FILES) $(RUNNER_SOURCE_FILES) $(TEST_UNITTEST_SOURCE_FILES) $(TEST_NEGATIVE_SOURCE_FILES) \
	$(MICRO_PROGRAM_SOURCE_FILES) $(KINSN_SOURCE_FILES) $(KATRAN_SOURCE_FILES) \
	$(LIBBPF_SOURCE_FILES) $(VENDOR_LINUX_RUNTIME_SOURCE_FILES) \
	$(RUNNER_RUNTIME_SOURCE_FILES) $(RUNNER_SCRIPT_SOURCE_FILES) $(MICRO_RUNTIME_SOURCE_FILES) $(CORPUS_RUNTIME_SOURCE_FILES) \
	$(E2E_RUNTIME_SOURCE_FILES) $(KERNEL_BUILD_META_FILES) $(KERNEL_SOURCE_FILES) \
	$(KERNEL_FORK_CONTAINERFILE) $(RUNNER_RUNTIME_CONTAINERFILE) $(KATRAN_ARTIFACTS_CONTAINERFILE) $(DOCKERIGNORE_FILE))

$(BUILD_INPUT_SOURCE_FILES): ;

.PHONY: FORCE
FORCE:

$(X86_KERNEL_FORK_IMAGE_TAR): $(KERNEL_FORK_IMAGE_SOURCE_FILES)
	@mkdir -p "$(dir $@)"
	@if docker pull --platform "$(X86_KERNEL_FORK_PULL_PLATFORM)" "$(X86_KERNEL_FORK_GHCR_IMAGE)"; then \
		docker tag "$(X86_KERNEL_FORK_GHCR_IMAGE)" "$(X86_KERNEL_FORK_IMAGE)"; \
		echo "using GHCR kernel-fork image: $(X86_KERNEL_FORK_GHCR_IMAGE)"; \
	else \
		echo "GHCR kernel-fork image unavailable, building locally: $(X86_KERNEL_FORK_IMAGE)"; \
		docker build --platform "$(KERNEL_FORK_BUILD_PLATFORM)" \
			--target kernel-fork \
			--build-arg IMAGE_BUILD_JOBS="$(IMAGE_BUILD_JOBS)" \
			--build-arg RUN_TARGET_ARCH=x86_64 \
			-t "$(X86_KERNEL_FORK_IMAGE)" -f "$(KERNEL_FORK_CONTAINERFILE)" "$(ROOT_DIR)"; \
		docker tag "$(X86_KERNEL_FORK_IMAGE)" "$(X86_KERNEL_FORK_GHCR_IMAGE)"; \
	fi
	tmp="$@.$$$$.tmp"; rm -f "$$tmp"; docker save -o "$$tmp" "$(X86_KERNEL_FORK_IMAGE)"; mv -f "$$tmp" "$@"

$(ARM64_KERNEL_FORK_IMAGE_TAR): $(KERNEL_FORK_IMAGE_SOURCE_FILES)
	@mkdir -p "$(dir $@)"
	@if docker pull --platform "$(ARM64_KERNEL_FORK_PULL_PLATFORM)" "$(ARM64_KERNEL_FORK_GHCR_IMAGE)"; then \
		docker tag "$(ARM64_KERNEL_FORK_GHCR_IMAGE)" "$(ARM64_KERNEL_FORK_IMAGE)"; \
		echo "using GHCR kernel-fork image: $(ARM64_KERNEL_FORK_GHCR_IMAGE)"; \
	else \
		echo "GHCR kernel-fork image unavailable, building locally: $(ARM64_KERNEL_FORK_IMAGE)"; \
		docker build --platform "$(KERNEL_FORK_BUILD_PLATFORM)" \
			--target kernel-fork \
			--build-arg IMAGE_BUILD_JOBS="$(ARM64_IMAGE_BUILD_JOBS)" \
			--build-arg RUN_TARGET_ARCH=arm64 \
			-t "$(ARM64_KERNEL_FORK_IMAGE)" -f "$(KERNEL_FORK_CONTAINERFILE)" "$(ROOT_DIR)"; \
		docker tag "$(ARM64_KERNEL_FORK_IMAGE)" "$(ARM64_KERNEL_FORK_GHCR_IMAGE)"; \
	fi
	tmp="$@.$$$$.tmp"; rm -f "$$tmp"; docker save -o "$$tmp" "$(ARM64_KERNEL_FORK_IMAGE)"; mv -f "$$tmp" "$@"

$(X86_KATRAN_ARTIFACTS_IMAGE_TAR): $(KATRAN_ARTIFACTS_IMAGE_SOURCE_FILES)
	@mkdir -p "$(dir $@)"
	@if docker pull --platform "$(X86_KATRAN_ARTIFACTS_PULL_PLATFORM)" "$(X86_KATRAN_ARTIFACTS_GHCR_IMAGE)"; then \
		docker tag "$(X86_KATRAN_ARTIFACTS_GHCR_IMAGE)" "$(X86_KATRAN_ARTIFACTS_IMAGE)"; \
		echo "using GHCR katran-artifacts image: $(X86_KATRAN_ARTIFACTS_GHCR_IMAGE)"; \
	else \
		echo "GHCR katran-artifacts image unavailable, building locally: $(X86_KATRAN_ARTIFACTS_IMAGE)"; \
		docker build --platform linux/amd64 \
			--target katran-artifacts \
			--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
			--build-arg IMAGE_BUILD_JOBS="$(IMAGE_BUILD_JOBS)" \
			--build-arg RUN_TARGET_ARCH=x86_64 \
			-t "$(X86_KATRAN_ARTIFACTS_IMAGE)" -f "$(KATRAN_ARTIFACTS_CONTAINERFILE)" "$(ROOT_DIR)"; \
		docker tag "$(X86_KATRAN_ARTIFACTS_IMAGE)" "$(X86_KATRAN_ARTIFACTS_GHCR_IMAGE)"; \
	fi
	tmp="$@.$$$$.tmp"; rm -f "$$tmp"; docker save -o "$$tmp" "$(X86_KATRAN_ARTIFACTS_IMAGE)"; mv -f "$$tmp" "$@"

$(ARM64_KATRAN_ARTIFACTS_IMAGE_TAR): $(KATRAN_ARTIFACTS_IMAGE_SOURCE_FILES)
	@mkdir -p "$(dir $@)"
	@if docker pull --platform "$(ARM64_KATRAN_ARTIFACTS_PULL_PLATFORM)" "$(ARM64_KATRAN_ARTIFACTS_GHCR_IMAGE)"; then \
		docker tag "$(ARM64_KATRAN_ARTIFACTS_GHCR_IMAGE)" "$(ARM64_KATRAN_ARTIFACTS_IMAGE)"; \
		echo "using GHCR katran-artifacts image: $(ARM64_KATRAN_ARTIFACTS_GHCR_IMAGE)"; \
	else \
		echo "GHCR katran-artifacts image unavailable, building locally: $(ARM64_KATRAN_ARTIFACTS_IMAGE)"; \
		docker build --platform linux/arm64 \
			--target katran-artifacts \
			--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
			--build-arg IMAGE_BUILD_JOBS="$(ARM64_IMAGE_BUILD_JOBS)" \
			--build-arg RUN_TARGET_ARCH=arm64 \
			-t "$(ARM64_KATRAN_ARTIFACTS_IMAGE)" -f "$(KATRAN_ARTIFACTS_CONTAINERFILE)" "$(ROOT_DIR)"; \
		docker tag "$(ARM64_KATRAN_ARTIFACTS_IMAGE)" "$(ARM64_KATRAN_ARTIFACTS_GHCR_IMAGE)"; \
	fi
	tmp="$@.$$$$.tmp"; rm -f "$$tmp"; docker save -o "$$tmp" "$(ARM64_KATRAN_ARTIFACTS_IMAGE)"; mv -f "$$tmp" "$@"

$(X86_RUNNER_RUNTIME_IMAGE_TAR): $(RUNNER_RUNTIME_IMAGE_INPUT_FILES) $(X86_KATRAN_ARTIFACTS_IMAGE_TAR) $(X86_KERNEL_FORK_IMAGE_TAR)
	@mkdir -p "$(dir $@)"
	docker load -i "$(X86_KATRAN_ARTIFACTS_IMAGE_TAR)"
	docker load -i "$(X86_KERNEL_FORK_IMAGE_TAR)"
	docker build --platform linux/amd64 \
		--target runner-runtime \
		--build-context runner-runtime-katran-upstream=docker-image://$(X86_KATRAN_ARTIFACTS_IMAGE) \
		--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
		--build-arg IMAGE_BUILD_JOBS="$(IMAGE_BUILD_JOBS)" \
		--build-arg RUN_TARGET_ARCH=x86_64 \
		--build-arg VENDOR_LINUX_FRAMEWORK_COMMIT="$(KERNEL_FORK_COMMIT_X86)" \
		--build-arg KERNEL_FORK_IMAGE_PLATFORM="$(KERNEL_FORK_BUILD_PLATFORM)" \
		-t "$(X86_RUNNER_RUNTIME_IMAGE)" -f "$(RUNNER_RUNTIME_CONTAINERFILE)" "$(ROOT_DIR)"
	tmp="$@.$$$$.tmp"; rm -f "$$tmp"; docker save -o "$$tmp" "$(X86_RUNNER_RUNTIME_IMAGE)"; mv -f "$$tmp" "$@"

$(ARM64_RUNNER_RUNTIME_IMAGE_TAR): $(RUNNER_RUNTIME_IMAGE_INPUT_FILES) $(ARM64_KATRAN_ARTIFACTS_IMAGE_TAR) $(ARM64_KERNEL_FORK_IMAGE_TAR)
	@mkdir -p "$(dir $@)"
	docker load -i "$(ARM64_KATRAN_ARTIFACTS_IMAGE_TAR)"
	docker load -i "$(ARM64_KERNEL_FORK_IMAGE_TAR)"
	docker build --platform linux/arm64 \
		--target runner-runtime \
		--build-context runner-runtime-katran-upstream=docker-image://$(ARM64_KATRAN_ARTIFACTS_IMAGE) \
		--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
		--build-arg IMAGE_BUILD_JOBS="$(ARM64_IMAGE_BUILD_JOBS)" \
		--build-arg RUN_TARGET_ARCH=arm64 \
		--build-arg VENDOR_LINUX_FRAMEWORK_COMMIT="$(KERNEL_FORK_COMMIT_ARM64)" \
		--build-arg KERNEL_FORK_IMAGE_PLATFORM="$(KERNEL_FORK_BUILD_PLATFORM)" \
		-t "$(ARM64_RUNNER_RUNTIME_IMAGE)" -f "$(RUNNER_RUNTIME_CONTAINERFILE)" "$(ROOT_DIR)"
	tmp="$@.$$$$.tmp"; rm -f "$$tmp"; docker save -o "$$tmp" "$(ARM64_RUNNER_RUNTIME_IMAGE)"; mv -f "$$tmp" "$@"

.PHONY: image-kernel-fork-image-tar image-katran-artifacts-image-tar image-runner-runtime-image-tar \
	image-push-kernel-fork image-push-katran-artifacts
image-kernel-fork-image-tar: $(ACTIVE_KERNEL_FORK_IMAGE_TAR)
image-katran-artifacts-image-tar: $(ACTIVE_KATRAN_ARTIFACTS_IMAGE_TAR)
image-runner-runtime-image-tar: $(ACTIVE_RUNNER_RUNTIME_IMAGE_TAR)

image-push-kernel-fork:
	@if docker image inspect "$(ACTIVE_KERNEL_FORK_IMAGE)" >/dev/null 2>&1; then \
		echo "using local kernel-fork image: $(ACTIVE_KERNEL_FORK_IMAGE)"; \
	elif [ -f "$(ACTIVE_KERNEL_FORK_IMAGE_TAR)" ]; then \
		docker load -i "$(ACTIVE_KERNEL_FORK_IMAGE_TAR)"; \
	else \
		$(MAKE) image-kernel-fork-image-tar RUN_TARGET_ARCH="$(RUN_TARGET_ARCH)"; \
	fi
	docker tag "$(ACTIVE_KERNEL_FORK_IMAGE)" "$(ACTIVE_KERNEL_FORK_GHCR_IMAGE)"
	docker push "$(ACTIVE_KERNEL_FORK_GHCR_IMAGE)"

image-push-katran-artifacts:
	@if docker image inspect "$(ACTIVE_KATRAN_ARTIFACTS_IMAGE)" >/dev/null 2>&1; then \
		echo "using local katran-artifacts image: $(ACTIVE_KATRAN_ARTIFACTS_IMAGE)"; \
	elif [ -f "$(ACTIVE_KATRAN_ARTIFACTS_IMAGE_TAR)" ]; then \
		docker load -i "$(ACTIVE_KATRAN_ARTIFACTS_IMAGE_TAR)"; \
	else \
		$(MAKE) image-katran-artifacts-image-tar RUN_TARGET_ARCH="$(RUN_TARGET_ARCH)"; \
	fi
	docker tag "$(ACTIVE_KATRAN_ARTIFACTS_IMAGE)" "$(ACTIVE_KATRAN_ARTIFACTS_GHCR_IMAGE)"
	docker push "$(ACTIVE_KATRAN_ARTIFACTS_GHCR_IMAGE)"

$(X86_RUNTIME_KERNEL_IMAGE): $(X86_RUNNER_RUNTIME_IMAGE_TAR) $(BPFREJIT_INSTALL_SCRIPT)
	@mkdir -p "$(X86_RUNTIME_KERNEL_DIR)"
	BPFREJIT_INSTALL_KERNEL_OUT_DIR="$(X86_RUNTIME_KERNEL_DIR)" \
		"$(BPFREJIT_INSTALL_SCRIPT)" --extract-kernel-only "$<"
	test -s "$@"
	touch "$@"

$(X86_AWS_KERNEL_ARTIFACT_STAMP): $(X86_RUNNER_RUNTIME_IMAGE_TAR)
	@mkdir -p "$(dir $(X86_AWS_KERNEL_IMAGE))" "$(dir $(X86_AWS_KERNEL_RELEASE_FILE))" "$(X86_AWS_KERNEL_MODULES_ROOT)"
	tmpdir="$$(mktemp -d /tmp/bpfrejit-aws-x86-kernel.XXXXXX)"; \
	cid=""; \
	cleanup() { \
		if [ -n "$$cid" ]; then docker rm -f "$$cid" >/dev/null 2>&1 || true; fi; \
		rm -rf "$$tmpdir"; \
	}; \
	trap cleanup EXIT; \
	docker load -i "$<"; \
	cid="$$(docker create "$(X86_RUNNER_RUNTIME_IMAGE)" /bin/true)"; \
	docker cp "$$cid:/artifacts/manifest.json" "$$tmpdir/manifest.json"; \
	read -r kernel_release target_arch kernel_image < <(python3 -c 'import json, sys; manifest = json.load(open(sys.argv[1], encoding="utf-8")); keys = ("kernel_release", "target_arch", "kernel_image"); values = [str(manifest.get(key) or "").strip() for key in keys]; all(values) or sys.exit("manifest is missing kernel fields"); print(*values)' "$$tmpdir/manifest.json"); \
	test "$$target_arch" = "x86_64"; \
	test "$$kernel_image" = "bzImage"; \
	docker cp "$$cid:/artifacts/kernel/$$kernel_image" "$(X86_AWS_KERNEL_IMAGE)"; \
	docker cp "$$cid:/artifacts/kernel/System.map" "$(X86_BUILD_DIR)/System.map"; \
	docker cp "$$cid:/artifacts/kernel/Module.symvers" "$(X86_BUILD_DIR)/Module.symvers"; \
	docker cp "$$cid:/artifacts/kernel/.config" "$(X86_BUILD_DIR)/.config"; \
	printf '%s\n' "$$kernel_release" >"$(X86_AWS_KERNEL_RELEASE_FILE)"; \
	rm -rf "$(X86_AWS_KERNEL_MODULES_ROOT)/$$kernel_release"; \
	docker cp "$$cid:/artifacts/modules/$$kernel_release" "$(X86_AWS_KERNEL_MODULES_ROOT)/$$kernel_release"; \
	rm -f "$(X86_AWS_KERNEL_MODULES_ROOT)/$$kernel_release/build" "$(X86_AWS_KERNEL_MODULES_ROOT)/$$kernel_release/source"; \
	test -s "$(X86_AWS_KERNEL_IMAGE)"; \
	test -s "$(X86_AWS_KERNEL_RELEASE_FILE)"; \
	test -d "$(X86_AWS_KERNEL_MODULES_ROOT)/$$kernel_release"; \
	test -f "$(X86_AWS_KERNEL_MODULES_ROOT)/$$kernel_release/kernel/drivers/block/null_blk/null_blk.ko"; \
	test -f "$(X86_AWS_KERNEL_MODULES_ROOT)/$$kernel_release/kernel/net/sched/sch_netem.ko"; \
	touch "$@"

$(X86_AWS_KERNEL_IMAGE) $(X86_AWS_KERNEL_RELEASE_FILE): $(X86_AWS_KERNEL_ARTIFACT_STAMP)
	@test -s "$@"

$(X86_AWS_KERNEL_MODULES_ROOT): $(X86_AWS_KERNEL_ARTIFACT_STAMP)
	@test -d "$@"

.PHONY: image-katran-artifacts image-runner-artifacts image-daemon-artifact image-bpfopt-artifacts \
	image-micro-program-artifacts image-test-artifacts
ifneq ($(BPFREJIT_IMAGE_BUILD),1)
image-katran-artifacts image-runner-artifacts image-daemon-artifact image-bpfopt-artifacts image-micro-program-artifacts image-test-artifacts:
	@echo "$@ must be run from the runner Dockerfile with BPFREJIT_IMAGE_BUILD=1" >&2
	@exit 1
else
image-katran-artifacts: $(ACTIVE_KATRAN_REQUIRED)
image-runner-artifacts: $(ACTIVE_RUNNER_BINARY)
image-daemon-artifact: $(ACTIVE_DAEMON_BINARY)
image-bpfopt-artifacts: $(ACTIVE_BPFOPT_BINARIES)
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

$(ACTIVE_BPFOPT_BINARIES) &: $(BPFOPT_SOURCE_FILES) $(BUILD_RULE_FILES)
	cargo build --release --workspace $(ACTIVE_BPFOPT_TARGET_ARG) --target-dir "$(ROOT_DIR)/bpfopt/target" --manifest-path "$(ROOT_DIR)/bpfopt/Cargo.toml" \
		-p bpfopt -p bpfget -p bpfrejit -p bpfverify -p bpfprof

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
	mkdir -p "$$install_root/bin" "$$install_root/lib" "$$install_root/lib64" "$$bpf_root" "$$build_root/deps"; \
	grpc_plugin="$$(command -v grpc_cpp_plugin)"; \
	clang_bin="$$(command -v clang)"; \
	llc_bin="$$(command -v llc)"; \
	clang_root="$$build_root/deps/clang/clang+llvm-12.0.0-x86_64-linux-gnu-ubuntu-20.04"; \
	mkdir -p "$$install_root/grpc/_build"; \
	ln -sf "$$grpc_plugin" "$$install_root/grpc/_build/grpc_cpp_plugin"; \
	mkdir -p "$$clang_root/bin" "$$clang_root/lib"; \
	ln -sf "$$clang_bin" "$$clang_root/bin/clang"; \
	ln -sf "$$llc_bin" "$$clang_root/bin/llc"; \
	touch "$$build_root/deps/grpc_installed" "$$build_root/deps/clang_installed"; \
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
	install -m 0755 "$$install_root/example/katran_server_grpc" "$$install_root/bin/katran_server_grpc"; \
	cd "$$repo_root" && ./build_bpf_modules_opensource.sh -s "$$repo_root" -b "$$build_root"; \
	install -m 0644 "$$build_root/deps/bpfprog/bpf/balancer.bpf.o" "$$bpf_root/balancer.bpf.o"; \
	install -m 0644 "$$build_root/deps/bpfprog/bpf/healthchecking_ipip.o" "$$bpf_root/healthchecking_ipip.bpf.o"; \
	install -m 0644 "$$build_root/deps/bpfprog/bpf/xdp_root.o" "$$bpf_root/xdp_root.bpf.o"; \
	test -x "$$install_root/bin/katran_server_grpc" || { echo "missing Katran install output: $$install_root/bin/katran_server_grpc" >&2; exit 1; }; \
	for path in $(ACTIVE_KATRAN_REQUIRED); do test -e "$$path"; done; \
	touch $(ACTIVE_KATRAN_REQUIRED)

endif
