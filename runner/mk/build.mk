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
KATRAN_ARTIFACTS_BUILD_RULE_FILE := $(RUNNER_DIR)/mk/katran-artifacts.mk
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
ACTIVE_BPFOPT_BINARIES := $(addprefix $(ACTIVE_BPFOPT_BINARY_DIR)/,bpfopt bpfprof)
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
ACTIVE_X86_KINSN_SOURCE_DIR := $(ROOT_DIR)/module/x86
ACTIVE_KINSN_SOURCE_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/module/arm64,$(ACTIVE_X86_KINSN_SOURCE_DIR))
ACTIVE_KATRAN_REQUIRED := $(REPO_KATRAN_ROOT)/bin/katran_server_grpc $(REPO_KATRAN_ROOT)/bpf/balancer.bpf.o $(REPO_KATRAN_ROOT)/bpf/healthchecking_ipip.bpf.o $(REPO_KATRAN_ROOT)/bpf/xdp_root.bpf.o

REQUIRE_IMAGE_BUILD = @if [ "$(BPFREJIT_IMAGE_BUILD)" != "1" ]; then echo "$@ must be run from the runner Dockerfile with BPFREJIT_IMAGE_BUILD=1" >&2; exit 1; fi

KERNEL_SYS_SOURCE_FILES = $(shell find "$(ROOT_DIR)/bpfopt/crates/kernel-sys" -type f \( -name '*.rs' -o -name 'Cargo.toml' \) -print 2>/dev/null) $(ROOT_DIR)/bpfopt/Cargo.toml
BPFOPT_SOURCE_FILES = $(shell find "$(ROOT_DIR)/bpfopt/crates" -type f \( -name '*.rs' -o -name 'Cargo.toml' \) -print 2>/dev/null) $(ROOT_DIR)/bpfopt/Cargo.toml $(ROOT_DIR)/bpfopt/Cargo.lock
DAEMON_SOURCE_FILES = $(shell find "$(ROOT_DIR)/daemon/src" "$(ROOT_DIR)/daemon/crates" -type f 2>/dev/null) $(ROOT_DIR)/daemon/Cargo.toml $(ROOT_DIR)/daemon/Cargo.lock $(ROOT_DIR)/daemon/Makefile $(KERNEL_SYS_SOURCE_FILES)
RUNNER_CORE_SOURCE_FILES = $(shell find "$(RUNNER_DIR)/src" "$(RUNNER_DIR)/include" -type f ! -name 'llvmbpf_runner.cpp' 2>/dev/null) $(RUNNER_DIR)/CMakeLists.txt
RUNNER_LLVMBPF_SOURCE_FILES = $(RUNNER_DIR)/src/llvmbpf_runner.cpp $(shell find "$(ROOT_DIR)/vendor/llvmbpf/include" "$(ROOT_DIR)/vendor/llvmbpf/src" -type f 2>/dev/null)
RUNNER_SOURCE_FILES = $(RUNNER_CORE_SOURCE_FILES) $(RUNNER_LLVMBPF_SOURCE_FILES)
TEST_UNITTEST_SOURCE_FILES = $(shell find "$(ROOT_DIR)/tests/unittest" \( -path '*/build' -o -path '*/build-arm64' \) -prune -o -type f -print 2>/dev/null)
TEST_NEGATIVE_SOURCE_FILES = $(shell find "$(ROOT_DIR)/tests/negative" \( -path '*/build' -o -path '*/build-arm64' \) -prune -o -type f -print 2>/dev/null)
MICRO_PROGRAM_SOURCE_FILES = $(MICRO_PROGRAM_SRCS) $(shell find "$(MICRO_PROGRAM_SOURCE_ROOT)" -maxdepth 1 -type f \( -name '*.h' -o -name 'Makefile' \) -print 2>/dev/null)
KINSN_SOURCE_FILES = $(shell find "$(ACTIVE_KINSN_SOURCE_DIR)" "$(ROOT_DIR)/module/include" -type f \( -name '*.c' -o -name '*.h' -o -name 'Makefile' \) -print 2>/dev/null)
# Keep Katran artifact invalidation tied to the sparse checkout paths used by
# katran-artifacts.Dockerfile; docs and unrelated repos must not rebuild folly.
KATRAN_SOURCE_FILES = $(shell if [ -d "$(REPOS_DIR)/katran" ]; then \
	for rel in CMakeLists.txt build build_bpf_modules_opensource.sh build_katran.sh cmake example_grpc katran/decap katran/lib; do \
		path="$(REPOS_DIR)/katran/$$rel"; \
		if [ -f "$$path" ]; then \
			printf '%s\n' "$$path"; \
		elif [ -d "$$path" ]; then \
			find "$$path" \( -path '*/_build' -o -path '*/deps' -o -path '*/.git' \) -prune -o -type f -print; \
		fi; \
	done; \
fi 2>/dev/null)
LIBBPF_SOURCE_FILES = $(shell find "$(ROOT_DIR)/vendor/libbpf" \( -path '*/.git' -o -path '*/build' -o -path '*/obj' -o -path '*/prefix' \) -prune -o -type f \
	\( -name '*.[ch]' -o -name '*.S' -o -name '*.lds' -o -name '*.map' -o -name '*.mk' -o -name '*.sh' \
		-o -name '*.template' -o -name 'Build' -o -name 'Makefile' \) -print 2>/dev/null)
# Katran's image builds bpftool before compiling Katran BPF objects.  Track the
# bpftool/libbpf inputs directly instead of every kernel/bpf source file.
BPFTOOL_SOURCE_FILES = $(ROOT_DIR)/vendor/linux-framework/Makefile \
	$(ROOT_DIR)/vendor/linux-framework/kernel/bpf/disasm.c \
	$(ROOT_DIR)/vendor/linux-framework/kernel/bpf/disasm.h \
	$(shell find \
	"$(ROOT_DIR)/vendor/linux-framework/arch/arm64/include/uapi/asm" \
	"$(ROOT_DIR)/vendor/linux-framework/include" \
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
KATRAN_ARTIFACTS_IMAGE_SOURCE_FILES = $(ROOT_DIR)/Makefile $(KATRAN_ARTIFACTS_BUILD_RULE_FILE) \
	$(KATRAN_ARTIFACTS_CONTAINERFILE) $(DOCKERIGNORE_FILE) $(KATRAN_SOURCE_FILES) $(BPFTOOL_SOURCE_FILES)
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
		-p bpfopt -p bpfprof

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

include $(KATRAN_ARTIFACTS_BUILD_RULE_FILE)

endif
