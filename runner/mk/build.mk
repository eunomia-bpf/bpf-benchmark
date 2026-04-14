REPOS_DIR := $(RUNNER_DIR)/repos
RUNNER_CONTAINER_DIR := $(RUNNER_DIR)/containers
RUN_TARGET_ARCH ?= x86_64
WORKLOAD_TOOLS_SOURCE_ROOT := $(REPOS_DIR)/workload-tools
DOCKERIGNORE_FILE := $(ROOT_DIR)/.dockerignore
X86_BUILD_DISTRO_VARIANT := ubuntu24.04
BUILD_ARCH_VARIANT := $(if $(filter x86_64,$(RUN_TARGET_ARCH)),-$(X86_BUILD_DISTRO_VARIANT),)
IMAGE_ARTIFACT_ROOT ?= /opt/bpf-benchmark
IMAGE_BUILD_ROOT ?= /tmp/bpf-benchmark-build/$(RUN_TARGET_ARCH)$(BUILD_ARCH_VARIANT)
ACTIVE_ARTIFACT_ROOT := $(if $(filter 1,$(BPFREJIT_IMAGE_BUILD)),$(IMAGE_ARTIFACT_ROOT),$(ARTIFACT_ROOT))
ACTIVE_BUILD_ARTIFACT_ROOT := $(if $(filter 1,$(BPFREJIT_IMAGE_BUILD)),$(IMAGE_BUILD_ROOT),$(ARTIFACT_ROOT))
REPO_ARTIFACT_ROOT := $(ACTIVE_ARTIFACT_ROOT)/repo-artifacts/$(RUN_TARGET_ARCH)
REPO_SCX_ROOT := $(REPO_ARTIFACT_ROOT)/scx
REPO_BCC_ROOT := $(REPO_ARTIFACT_ROOT)/bcc/libbpf-tools/.output
REPO_BPFTRACE_ROOT := $(REPO_ARTIFACT_ROOT)/bpftrace
REPO_TRACEE_ROOT := $(REPO_ARTIFACT_ROOT)/tracee
REPO_TETRAGON_ROOT := $(REPO_ARTIFACT_ROOT)/tetragon
REPO_KATRAN_ROOT := $(REPO_ARTIFACT_ROOT)/katran
REPO_KERNEL_MODULES_ROOT := $(REPO_ARTIFACT_ROOT)/kernel-modules
REPO_BUILD_ROOT := $(ACTIVE_BUILD_ARTIFACT_ROOT)/repo-build/$(RUN_TARGET_ARCH)$(BUILD_ARCH_VARIANT)
BUILD_RULE_FILES := $(ROOT_DIR)/Makefile $(RUNNER_DIR)/mk/build.mk
MICRO_PROGRAM_SOURCE_ROOT := $(ROOT_DIR)/micro/programs
MICRO_PROGRAM_OUTPUT_ROOT := $(ACTIVE_ARTIFACT_ROOT)/micro-programs/$(RUN_TARGET_ARCH)
MICRO_PROGRAM_SRCS = $(shell find "$(MICRO_PROGRAM_SOURCE_ROOT)" -maxdepth 1 -type f -name '*.bpf.c' -print 2>/dev/null)
MICRO_PROGRAM_OBJECTS = $(patsubst $(MICRO_PROGRAM_SOURCE_ROOT)/%.bpf.c,$(MICRO_PROGRAM_OUTPUT_ROOT)/%.bpf.o,$(MICRO_PROGRAM_SRCS))
SCX_BUILD_ROOT := $(REPO_BUILD_ROOT)/scx
SCX_CARGO_TARGET_DIR := $(SCX_BUILD_ROOT)/target
BPFTRACE_BUILD_ROOT := $(REPO_BUILD_ROOT)/bpftrace
TRACEE_BUILD_ROOT := $(REPO_BUILD_ROOT)/tracee
TRACEE_BUILD_DIST_ROOT := $(TRACEE_BUILD_ROOT)/dist
TETRAGON_BUILD_ROOT := $(REPO_BUILD_ROOT)/tetragon
TETRAGON_BUILD_BPF_ROOT := $(TETRAGON_BUILD_ROOT)/bpf-objs
RUNNER_BUILD_DIR_ACTIVE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(RUNNER_DIR)/build-arm64-llvmbpf,$(RUNNER_DIR)/build-llvmbpf)
RUNNER_LIBBPF_BUILD_DIR := $(RUNNER_BUILD_DIR_ACTIVE)/vendor/libbpf
RUNNER_LIBBPF_OBJDIR := $(RUNNER_LIBBPF_BUILD_DIR)/obj
RUNNER_LIBBPF_PREFIX := $(RUNNER_LIBBPF_BUILD_DIR)/prefix
RUNNER_LIBBPF_A := $(RUNNER_LIBBPF_OBJDIR)/libbpf.a
DEFAULT_RUNNER_LLVM_DIR := /usr/lib/llvm-18/lib/cmake/llvm
RUNNER_LLVM_DIR := $(if $(strip $(LLVM_DIR)),$(LLVM_DIR),$(if $(strip $(RUN_LLVM_DIR)),$(RUN_LLVM_DIR),$(DEFAULT_RUNNER_LLVM_DIR)))
RUNNER_CLANG_DIR := $(if $(strip $(CLANG_DIR)),$(CLANG_DIR),$(patsubst %/llvm,%/clang,$(RUNNER_LLVM_DIR)))
RUNNER_CONTAINER_CC := /usr/bin/gcc
RUNNER_CONTAINER_CXX := /usr/bin/g++
CONTAINER_IMAGE_ARTIFACT_ROOT := $(ARTIFACT_ROOT)/container-images
KATRAN_BUILD_ROOT := $(REPO_BUILD_ROOT)/katran
ACTIVE_WORKLOAD_TOOLS_INSTALL_ROOT := $(ACTIVE_ARTIFACT_ROOT)/workload-tools/$(RUN_TARGET_ARCH)
ACTIVE_WORKLOAD_TOOLS_BIN_ROOT := $(ACTIVE_WORKLOAD_TOOLS_INSTALL_ROOT)/bin
ACTIVE_DAEMON_BINARY := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(DAEMON_DIR)/target/aarch64-unknown-linux-gnu/release/bpfrejit-daemon,$(DAEMON_DIR)/target/release/bpfrejit-daemon)
ACTIVE_DAEMON_TARGET_TRIPLE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),aarch64-unknown-linux-gnu,)
ACTIVE_DAEMON_TARGET_ARG := $(if $(strip $(ACTIVE_DAEMON_TARGET_TRIPLE)),TARGET_TRIPLE="$(ACTIVE_DAEMON_TARGET_TRIPLE)",)
ACTIVE_RUNNER_BINARY := $(RUNNER_BUILD_DIR_ACTIVE)/micro_exec
ACTIVE_TEST_UNITTEST_BUILD_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/tests/unittest/build-arm64,$(ROOT_DIR)/tests/unittest/build)
ACTIVE_TEST_NEGATIVE_BUILD_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/tests/negative/build-arm64,$(ROOT_DIR)/tests/negative/build)
ACTIVE_TEST_UNITTEST_PRIMARY := $(ACTIVE_TEST_UNITTEST_BUILD_DIR)/rejit_regression
ACTIVE_TEST_NEGATIVE_PRIMARY := $(ACTIVE_TEST_NEGATIVE_BUILD_DIR)/scx_prog_show_race
RUNNER_RUNTIME_CONTAINERFILE := $(RUNNER_CONTAINER_DIR)/runner-runtime.Dockerfile
X86_RUNNER_RUNTIME_IMAGE := bpf-benchmark/runner-runtime:x86_64
ARM64_RUNNER_RUNTIME_IMAGE := bpf-benchmark/runner-runtime:arm64
X86_RUNNER_RUNTIME_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/x86_64-runner-runtime.image.tar
ARM64_RUNNER_RUNTIME_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/arm64-runner-runtime.image.tar
ACTIVE_CONTAINER_PLATFORM := $(if $(filter arm64,$(RUN_TARGET_ARCH)),linux/arm64,linux/amd64)
ACTIVE_RUNNER_RUNTIME_IMAGE_TAR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_RUNNER_RUNTIME_IMAGE_TAR),$(X86_RUNNER_RUNTIME_IMAGE_TAR))
HOST_ARTIFACT_OUTPUT_ROOT ?= /image-output
HOST_WORKSPACE_ROOT ?= $(ROOT_DIR)
HOST_ARTIFACT_CACHE_ROOT := $(HOST_ARTIFACT_OUTPUT_ROOT)/.cache
HOST_X86_BUILD_DIR := $(HOST_ARTIFACT_CACHE_ROOT)/x86-kernel-build
HOST_ARM64_BUILD_DIR := $(HOST_ARTIFACT_CACHE_ROOT)/arm64-kernel-build
HOST_ARM64_AWS_BUILD_DIR := $(HOST_ARTIFACT_CACHE_ROOT)/aws-arm64/kernel-build
HOST_KERNEL_ARTIFACT_TARGET := $(if $(filter arm64,$(RUN_TARGET_ARCH)),arm64-aws-kernel,x86-kernel)
ACTIVE_X86_KINSN_SOURCE_DIR := $(ROOT_DIR)/module/x86
ACTIVE_KINSN_SOURCE_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/module/arm64,$(ACTIVE_X86_KINSN_SOURCE_DIR))
ACTIVE_KINSN_MODULE_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/module/arm64,$(ACTIVE_X86_KINSN_SOURCE_DIR))
ACTIVE_X86_KERNEL_BUILD_DIR := $(X86_BUILD_DIR)
ACTIVE_X86_KERNEL_IMAGE := $(X86_BUILD_DIR)/arch/x86/boot/bzImage
ACTIVE_KERNEL_BUILD_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_AWS_BUILD_DIR),$(ACTIVE_X86_KERNEL_BUILD_DIR))
ACTIVE_KERNEL_ARCH_ARG := $(if $(filter arm64,$(RUN_TARGET_ARCH)),ARCH=arm64,)
ACTIVE_SCX_TARGET_TRIPLE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),aarch64-unknown-linux-gnu,x86_64-unknown-linux-gnu)
ACTIVE_BCC_ARCH_ARG := $(if $(filter arm64,$(RUN_TARGET_ARCH)),ARCH=arm64,)
ACTIVE_TRACEE_UNAME_M := $(if $(filter arm64,$(RUN_TARGET_ARCH)),aarch64,x86_64)
ACTIVE_TRACEE_ARCH := $(if $(filter arm64,$(RUN_TARGET_ARCH)),arm64,x86_64)
ACTIVE_TRACEE_LINUX_ARCH := $(if $(filter arm64,$(RUN_TARGET_ARCH)),arm64,x86)
ACTIVE_TRACEE_GOARCH := $(if $(filter arm64,$(RUN_TARGET_ARCH)),arm64,amd64)
ACTIVE_TETRAGON_TARGET_ARCH := $(if $(filter arm64,$(RUN_TARGET_ARCH)),arm64,amd64)
ACTIVE_BCC_TOOLS := capable execsnoop bindsnoop biosnoop vfsstat opensnoop syscount tcpconnect tcplife runqlat
ACTIVE_BCC_REQUIRED := $(addprefix $(REPO_BCC_ROOT)/,$(ACTIVE_BCC_TOOLS)) $(addsuffix .bpf.o,$(addprefix $(REPO_BCC_ROOT)/,$(ACTIVE_BCC_TOOLS)))
ACTIVE_BPFTRACE_REQUIRED := $(REPO_BPFTRACE_ROOT)/bin/bpftrace
ACTIVE_TRACEE_REQUIRED := $(REPO_TRACEE_ROOT)/bin/tracee $(REPO_TRACEE_ROOT)/tracee.bpf.o $(REPO_TRACEE_ROOT)/lsm_support/kprobe_check.bpf.o $(REPO_TRACEE_ROOT)/lsm_support/lsm_check.bpf.o
ACTIVE_TETRAGON_REQUIRED := $(REPO_TETRAGON_ROOT)/bin/tetragon $(REPO_TETRAGON_ROOT)/bpf_execve_event.o $(REPO_TETRAGON_ROOT)/bpf_generic_kprobe.o $(REPO_TETRAGON_ROOT)/bpf_alignchecker.o
ACTIVE_KATRAN_REQUIRED := $(REPO_KATRAN_ROOT)/bin/katran_server_grpc $(REPO_KATRAN_ROOT)/bpf/balancer.bpf.o $(REPO_KATRAN_ROOT)/bpf/healthchecking_ipip.bpf.o
ACTIVE_WORKLOAD_TOOLS_REQUIRED := $(ACTIVE_WORKLOAD_TOOLS_BIN_ROOT)/hackbench $(ACTIVE_WORKLOAD_TOOLS_BIN_ROOT)/sysbench $(ACTIVE_WORKLOAD_TOOLS_BIN_ROOT)/wrk
ACTIVE_SCX_REQUIRED := $(REPO_SCX_ROOT)/bin/scx_rusty $(REPO_SCX_ROOT)/scx_rusty_main.bpf.o

define RUNNER_HOST_ARTIFACT_BUILD
docker build --platform "$(1)" \
	--target runner-host-artifacts \
	--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
	--build-arg RUN_TARGET_ARCH="$(2)" \
	--build-arg RUN_HOST_ARTIFACT_TARGET="$(3)" \
	--build-arg HOST_WORKSPACE_ROOT="$(ROOT_DIR)" \
	-f "$(RUNNER_RUNTIME_CONTAINERFILE)" \
	--output type=local,dest="$(ROOT_DIR)" "$(ROOT_DIR)"
endef

REQUIRE_IMAGE_BUILD = @if [ "$(BPFREJIT_IMAGE_BUILD)" != "1" ]; then echo "$@ must be run from the runner Dockerfile with BPFREJIT_IMAGE_BUILD=1" >&2; exit 1; fi

DAEMON_SOURCE_FILES = $(shell find "$(ROOT_DIR)/daemon/src" -type f 2>/dev/null) $(ROOT_DIR)/daemon/Cargo.toml $(ROOT_DIR)/daemon/Cargo.lock $(ROOT_DIR)/daemon/Makefile
RUNNER_CORE_SOURCE_FILES = $(shell find "$(RUNNER_DIR)/src" "$(RUNNER_DIR)/include" -type f ! -name 'llvmbpf_runner.cpp' 2>/dev/null) $(RUNNER_DIR)/CMakeLists.txt
RUNNER_LLVMBPF_SOURCE_FILES = $(RUNNER_DIR)/src/llvmbpf_runner.cpp $(shell find "$(ROOT_DIR)/vendor/llvmbpf/include" "$(ROOT_DIR)/vendor/llvmbpf/src" -type f 2>/dev/null)
RUNNER_SOURCE_FILES = $(RUNNER_CORE_SOURCE_FILES) $(RUNNER_LLVMBPF_SOURCE_FILES)
TEST_UNITTEST_SOURCE_FILES = $(shell find "$(ROOT_DIR)/tests/unittest" \( -path '*/build' -o -path '*/build-arm64' \) -prune -o -type f -print 2>/dev/null)
TEST_NEGATIVE_SOURCE_FILES = $(shell find "$(ROOT_DIR)/tests/negative" \( -path '*/build' -o -path '*/build-arm64' \) -prune -o -type f -print 2>/dev/null)
MICRO_PROGRAM_SOURCE_FILES = $(MICRO_PROGRAM_SRCS) $(shell find "$(MICRO_PROGRAM_SOURCE_ROOT)" -maxdepth 1 -type f \( -name '*.h' -o -name 'Makefile' \) -print 2>/dev/null)
KINSN_SOURCE_FILES = $(shell find "$(ACTIVE_KINSN_SOURCE_DIR)" "$(ROOT_DIR)/module/include" -type f \( -name '*.c' -o -name '*.h' -o -name 'Makefile' \) -print 2>/dev/null)
SCX_SOURCE_FILES = $(shell find "$(REPOS_DIR)/scx" \( -path '*/target' -o -path '*/.git' \) -prune -o -type f \( -name '*.rs' -o -name '*.c' -o -name '*.h' -o -name 'Cargo.toml' -o -name 'Cargo.lock' -o -name 'build.rs' \) -print 2>/dev/null)
BCC_SOURCE_FILES = $(shell find "$(REPOS_DIR)/bcc/libbpf-tools" \( -path '*/.output' -o -path '*/.git' \) -prune -o -type f \( -name '*.c' -o -name '*.h' -o -name '*.sh' -o -name '*.mk' -o -name '*.yaml' -o -name '*.json' -o -name '*.txt' -o -name 'Makefile' \) -print 2>/dev/null)
BPFTRACE_SOURCE_FILES = $(shell find "$(REPOS_DIR)/bpftrace" \( -path '*/build' -o -path '*/.git' \) -prune -o -type f -print 2>/dev/null)
TRACEE_SOURCE_FILES = $(shell find "$(REPOS_DIR)/tracee" \( -path '*/dist' -o -path '*/build' -o -path '*/.git' \) -prune -o -type f \( -name '*.go' -o -name '*.c' -o -name '*.h' -o -name '*.mk' -o -name 'Makefile' -o -name 'go.mod' -o -name 'go.sum' \) -print 2>/dev/null)
TETRAGON_SOURCE_FILES = $(shell find "$(REPOS_DIR)/tetragon" \( -path '*/bpf/objs' -o -path '*/.git' \) -prune -o -type f \( -name '*.go' -o -name '*.c' -o -name '*.h' -o -name '*.yaml' -o -name '*.mk' -o -name 'Makefile' -o -name 'go.mod' -o -name 'go.sum' \) -print 2>/dev/null)
KATRAN_SOURCE_FILES = $(shell find "$(REPOS_DIR)/katran" \( -path '*/_build' -o -path '*/deps' -o -path '*/.git' \) -prune -o -type f -print 2>/dev/null)
WORKLOAD_TOOLS_SOURCE_FILES = $(shell find "$(WORKLOAD_TOOLS_SOURCE_ROOT)" \
	\( -path '*/.git' -o -path '*/autom4te.cache' -o -path '*/wrk/obj' \
		-o -path '*/sysbench/Makefile' -o -path '*/sysbench/config.status' -o -path '*/sysbench/libtool' \) -prune -o -type f \
	\( -name '*.c' -o -name '*.cc' -o -name '*.h' -o -name '*.lua' -o -name '*.mk' -o -name '*.am' -o -name '*.ac' -o -name 'Makefile' -o -name 'configure*' \) \
	! -path '*/rt-tests/hackbench' ! -path '*/sysbench/src/sysbench' ! -path '*/wrk/wrk' ! -name '*.o' -print 2>/dev/null)
LIBBPF_SOURCE_FILES = $(shell find "$(ROOT_DIR)/vendor/libbpf" \( -path '*/.git' -o -path '*/build' -o -path '*/obj' -o -path '*/prefix' \) -prune -o -type f -print 2>/dev/null)
VENDOR_LINUX_RUNTIME_SOURCE_FILES = $(ROOT_DIR)/vendor/linux-framework/Makefile $(shell find \
	"$(ROOT_DIR)/vendor/linux-framework/include" \
	"$(ROOT_DIR)/vendor/linux-framework/scripts" \
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
MICRO_RUNTIME_SOURCE_FILES = $(shell find "$(MICRO_DIR)" \( -path "$(MICRO_PROGRAM_SOURCE_ROOT)" -o -path '*/__pycache__' -o -path '*/build' -o -path '*/build-*' -o -path '*/jit-dumps' -o -path '*/results' \) -prune -o -type f -print 2>/dev/null)
CORPUS_RUNTIME_SOURCE_FILES = $(shell find "$(ROOT_DIR)/corpus" \( -path '*/__pycache__' -o -path '*/build' -o -path '*/results' \) -prune -o -type f -print 2>/dev/null)
E2E_RUNTIME_SOURCE_FILES = $(shell find "$(ROOT_DIR)/e2e" \( -path '*/__pycache__' -o -path '*/results' \) -prune -o -type f -print 2>/dev/null)
KERNEL_BUILD_META_FILES = $(shell find "$(KERNEL_DIR)" \( -path '*/.git' -o -path '*/build*' -o -path '*/.cache' \) -prune -o -type f \( -name 'Makefile' -o -name 'Kconfig*' -o -name '*.mk' -o -path '*/scripts/config' \) -print 2>/dev/null)
KERNEL_SOURCE_FILES = $(shell find "$(KERNEL_DIR)" \( -path '*/.git' -o -path '*/build*' -o -path '*/.cache' \) -prune -o -type f \( -name '*.c' -o -name '*.h' -o -name '*.S' -o -name '*.lds' -o -name '*.dts' -o -name '*.dtsi' -o -name '*.sh' \) -print 2>/dev/null)
RUNNER_RUNTIME_IMAGE_SOURCE_FILES = $(BUILD_RULE_FILES) $(RUNNER_RUNTIME_CONTAINERFILE) $(DOCKERIGNORE_FILE) \
	$(DAEMON_SOURCE_FILES) $(RUNNER_SOURCE_FILES) $(TEST_UNITTEST_SOURCE_FILES) $(TEST_NEGATIVE_SOURCE_FILES) \
	$(MICRO_PROGRAM_SOURCE_FILES) $(KINSN_SOURCE_FILES) $(SCX_SOURCE_FILES) $(BCC_SOURCE_FILES) \
	$(BPFTRACE_SOURCE_FILES) $(TRACEE_SOURCE_FILES) $(TETRAGON_SOURCE_FILES) $(KATRAN_SOURCE_FILES) \
	$(WORKLOAD_TOOLS_SOURCE_FILES) $(LIBBPF_SOURCE_FILES) $(VENDOR_LINUX_RUNTIME_SOURCE_FILES) \
	$(RUNNER_RUNTIME_SOURCE_FILES) $(MICRO_RUNTIME_SOURCE_FILES) $(CORPUS_RUNTIME_SOURCE_FILES) \
	$(E2E_RUNTIME_SOURCE_FILES) $(KERNEL_BUILD_META_FILES) $(KERNEL_SOURCE_FILES) $(DEFCONFIG_SRC) $(ARM64_DEFCONFIG_SRC)
BUILD_INPUT_SOURCE_FILES = $(sort \
	$(DAEMON_SOURCE_FILES) $(RUNNER_SOURCE_FILES) $(TEST_UNITTEST_SOURCE_FILES) $(TEST_NEGATIVE_SOURCE_FILES) \
	$(MICRO_PROGRAM_SOURCE_FILES) $(KINSN_SOURCE_FILES) $(SCX_SOURCE_FILES) $(BCC_SOURCE_FILES) \
	$(BPFTRACE_SOURCE_FILES) $(TRACEE_SOURCE_FILES) $(TETRAGON_SOURCE_FILES) $(KATRAN_SOURCE_FILES) \
	$(WORKLOAD_TOOLS_SOURCE_FILES) $(LIBBPF_SOURCE_FILES) $(VENDOR_LINUX_RUNTIME_SOURCE_FILES) \
	$(RUNNER_RUNTIME_SOURCE_FILES) $(MICRO_RUNTIME_SOURCE_FILES) $(CORPUS_RUNTIME_SOURCE_FILES) \
	$(E2E_RUNTIME_SOURCE_FILES) $(KERNEL_BUILD_META_FILES) $(KERNEL_SOURCE_FILES))

$(BUILD_INPUT_SOURCE_FILES): ;

.PHONY: FORCE
FORCE:

$(X86_RUNNER_RUNTIME_IMAGE_TAR): $(RUNNER_RUNTIME_IMAGE_SOURCE_FILES)
	@mkdir -p "$(dir $@)"
	docker build --platform linux/amd64 \
		--target runner-runtime \
		--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
		--build-arg RUN_TARGET_ARCH=x86_64 \
		-t "$(X86_RUNNER_RUNTIME_IMAGE)" -f "$(RUNNER_RUNTIME_CONTAINERFILE)" "$(ROOT_DIR)"
	docker save -o "$@" "$(X86_RUNNER_RUNTIME_IMAGE)"

$(ARM64_RUNNER_RUNTIME_IMAGE_TAR): $(RUNNER_RUNTIME_IMAGE_SOURCE_FILES)
	@mkdir -p "$(dir $@)"
	docker build --platform linux/arm64 \
		--target runner-runtime \
		--build-arg IMAGE_WORKSPACE="$(ROOT_DIR)" \
		--build-arg RUN_TARGET_ARCH=arm64 \
		-t "$(ARM64_RUNNER_RUNTIME_IMAGE)" -f "$(RUNNER_RUNTIME_CONTAINERFILE)" "$(ROOT_DIR)"
	docker save -o "$@" "$(ARM64_RUNNER_RUNTIME_IMAGE)"

$(X86_BUILD_DIR)/arch/x86/boot/bzImage $(ARTIFACT_ROOT)/repo-artifacts/x86_64/kernel-modules/lib/modules &: $(DEFCONFIG_SRC) $(KERNEL_BUILD_META_FILES) $(KERNEL_SOURCE_FILES) $(X86_RUNNER_RUNTIME_IMAGE_TAR)
	@mkdir -p "$(X86_BUILD_DIR)"
	$(call RUNNER_HOST_ARTIFACT_BUILD,linux/amd64,x86_64,x86-kernel)

ifeq ($(RUN_TARGET_ARCH),arm64)
$(ARM64_AWS_IMAGE) $(ARM64_AWS_EFI_IMAGE) $(REPO_KERNEL_MODULES_ROOT)/lib/modules &: $(ARM64_DEFCONFIG_SRC) $(KERNEL_BUILD_META_FILES) $(KERNEL_SOURCE_FILES) $(ACTIVE_RUNNER_RUNTIME_IMAGE_TAR)
	@mkdir -p "$(dir $@)"
	$(call RUNNER_HOST_ARTIFACT_BUILD,$(ACTIVE_CONTAINER_PLATFORM),$(RUN_TARGET_ARCH),$(HOST_KERNEL_ARTIFACT_TARGET))
endif

.PHONY: image-host-artifacts image-runtime-kinsn-artifacts image-x86-kernel-artifacts \
	image-arm64-kernel-artifacts image-arm64-aws-kernel-artifacts image-kernel-modules-artifacts \
	image-kinsn-artifacts image-x86-kinsn-artifacts image-arm64-kinsn-artifacts \
	image-x86-kernel-build image-arm64-kernel-build

image-host-artifacts:
	$(REQUIRE_IMAGE_BUILD)
	$(MAKE) "image-$(RUN_HOST_ARTIFACT_TARGET)-artifacts" \
		RUN_TARGET_ARCH="$(RUN_TARGET_ARCH)" \
		REPO_ARTIFACT_ROOT="$(HOST_ARTIFACT_CACHE_ROOT)/repo-artifacts/$(RUN_TARGET_ARCH)"

image-runtime-kinsn-artifacts:
	$(REQUIRE_IMAGE_BUILD)
	$(MAKE) "$(if $(filter arm64,$(RUN_TARGET_ARCH)),image-arm64-kinsn-artifacts,image-x86-kinsn-artifacts)" \
		RUN_TARGET_ARCH="$(RUN_TARGET_ARCH)" \
		HOST_ARTIFACT_OUTPUT_ROOT="$(ROOT_DIR)"

image-x86-kernel-artifacts:
	$(REQUIRE_IMAGE_BUILD)
	$(MAKE) image-x86-kernel-build ACTIVE_KERNEL_BUILD_DIR="$(HOST_X86_BUILD_DIR)" ACTIVE_KERNEL_DEFCONFIG="$(DEFCONFIG_SRC)"
	$(MAKE) image-kernel-modules-artifacts RUN_TARGET_ARCH=x86_64 ACTIVE_KERNEL_BUILD_DIR="$(HOST_X86_BUILD_DIR)" ACTIVE_KERNEL_ARCH_ARG=

image-x86-kernel-build:
	$(REQUIRE_IMAGE_BUILD)
	mkdir -p "$(ACTIVE_KERNEL_BUILD_DIR)"
	cp "$(ACTIVE_KERNEL_DEFCONFIG)" "$(ACTIVE_KERNEL_BUILD_DIR)/.config"
	make -C "$(KERNEL_DIR)" O="$(ACTIVE_KERNEL_BUILD_DIR)" olddefconfig
	make -C "$(KERNEL_DIR)" O="$(ACTIVE_KERNEL_BUILD_DIR)" -j"$(JOBS)" bzImage modules

image-arm64-kernel-artifacts:
	$(REQUIRE_IMAGE_BUILD)
	$(MAKE) image-arm64-kernel-build ACTIVE_KERNEL_BUILD_DIR="$(HOST_ARM64_BUILD_DIR)" ACTIVE_ARM64_KERNEL_TARGETS="Image vmlinuz.efi"

image-arm64-aws-kernel-artifacts:
	$(REQUIRE_IMAGE_BUILD)
	$(MAKE) image-arm64-kernel-build ACTIVE_KERNEL_BUILD_DIR="$(HOST_ARM64_AWS_BUILD_DIR)" ACTIVE_ARM64_KERNEL_TARGETS="Image vmlinuz.efi modules"
	$(MAKE) image-kernel-modules-artifacts RUN_TARGET_ARCH=arm64 ACTIVE_KERNEL_BUILD_DIR="$(HOST_ARM64_AWS_BUILD_DIR)" ACTIVE_KERNEL_ARCH_ARG=ARCH=arm64

image-arm64-kernel-build:
	$(REQUIRE_IMAGE_BUILD)
	mkdir -p "$(ACTIVE_KERNEL_BUILD_DIR)"
	cp "$(ARM64_DEFCONFIG_SRC)" "$(ACTIVE_KERNEL_BUILD_DIR)/.config"
	make -C "$(KERNEL_DIR)" O="$(ACTIVE_KERNEL_BUILD_DIR)" ARCH=arm64 CROSS_COMPILE= olddefconfig
	find "$(ACTIVE_KERNEL_BUILD_DIR)" -type f -name '*.o' -size 0 -delete
	rm -f "$(ACTIVE_KERNEL_BUILD_DIR)/vmlinux.a" "$(ACTIVE_KERNEL_BUILD_DIR)/vmlinux.o" "$(ACTIVE_KERNEL_BUILD_DIR)/drivers/of/built-in.a"
	make -C "$(KERNEL_DIR)" O="$(ACTIVE_KERNEL_BUILD_DIR)" ARCH=arm64 CROSS_COMPILE= $(ACTIVE_ARM64_KERNEL_TARGETS) -j"$(NPROC)"

image-kernel-modules-artifacts:
	$(REQUIRE_IMAGE_BUILD)
	stage_root="$(REPO_KERNEL_MODULES_ROOT)"; \
	kernel_release_file="$(ACTIVE_KERNEL_BUILD_DIR)/include/config/kernel.release"; \
	test -f "$$kernel_release_file" || { echo "missing kernel release file: $$kernel_release_file" >&2; exit 1; }; \
	kernel_release="$$(tr -d '\n' < "$$kernel_release_file")"; \
	release_root="$$stage_root/lib/modules/$$kernel_release"; \
	mkdir -p "$$stage_root"; \
	rm -rf "$$release_root"; \
	make $(ACTIVE_KERNEL_ARCH_ARG) --no-print-directory -C "$(KERNEL_DIR)" O="$(ACTIVE_KERNEL_BUILD_DIR)" INSTALL_MOD_PATH="$$stage_root" DEPMOD=true modules_install >/dev/null; \
	depmod -b "$$stage_root" "$$kernel_release" >/dev/null; \
	build_dir="$(ACTIVE_KERNEL_BUILD_DIR)"; \
	case "$$build_dir" in "$(HOST_ARTIFACT_OUTPUT_ROOT)"/*) host_build_dir="$(HOST_WORKSPACE_ROOT)$${build_dir#"$(HOST_ARTIFACT_OUTPUT_ROOT)"}" ;; *) host_build_dir="$$build_dir" ;; esac; \
	ln -sfn "$$host_build_dir" "$$release_root/build"; \
	ln -sfn "$(HOST_WORKSPACE_ROOT)/vendor/linux-framework" "$$release_root/source"; \
	test -f "$$release_root/kernel/drivers/block/null_blk/null_blk.ko"; \
	test -f "$$release_root/kernel/net/sched/sch_netem.ko"; \
	touch "$$stage_root/lib/modules"

image-kinsn-artifacts:
	$(REQUIRE_IMAGE_BUILD)
	mkdir -p "$(ACTIVE_KINSN_MODULE_DIR)"
	make $(ACTIVE_KERNEL_ARCH_ARG) -C "$(KERNEL_DIR)" O="$(ACTIVE_KERNEL_BUILD_DIR)" M="$(ACTIVE_KINSN_SOURCE_DIR)" MO="$(ACTIVE_KINSN_MODULE_DIR)" modules

image-x86-kinsn-artifacts:
	$(REQUIRE_IMAGE_BUILD)
	$(MAKE) image-x86-kernel-build ACTIVE_KERNEL_BUILD_DIR="$(HOST_X86_BUILD_DIR)" ACTIVE_KERNEL_DEFCONFIG="$(DEFCONFIG_SRC)" RUN_TARGET_ARCH=x86_64
	$(MAKE) image-kinsn-artifacts RUN_TARGET_ARCH=x86_64 ACTIVE_KERNEL_BUILD_DIR="$(HOST_X86_BUILD_DIR)" ACTIVE_KERNEL_ARCH_ARG= ACTIVE_KINSN_SOURCE_DIR="$(ROOT_DIR)/module/x86" ACTIVE_KINSN_MODULE_DIR="$(HOST_ARTIFACT_OUTPUT_ROOT)/module/x86"

image-arm64-kinsn-artifacts:
	$(REQUIRE_IMAGE_BUILD)
	$(MAKE) image-arm64-kernel-build ACTIVE_KERNEL_BUILD_DIR="$(HOST_ARM64_AWS_BUILD_DIR)" ACTIVE_ARM64_KERNEL_TARGETS="Image vmlinuz.efi modules" RUN_TARGET_ARCH=arm64
	$(MAKE) image-kinsn-artifacts RUN_TARGET_ARCH=arm64 ACTIVE_KERNEL_BUILD_DIR="$(HOST_ARM64_AWS_BUILD_DIR)" ACTIVE_KERNEL_ARCH_ARG=ARCH=arm64 ACTIVE_KINSN_SOURCE_DIR="$(ROOT_DIR)/module/arm64" ACTIVE_KINSN_MODULE_DIR="$(HOST_ARTIFACT_OUTPUT_ROOT)/module/arm64"

.PHONY: image-bcc-artifacts image-bpftrace-artifacts image-katran-artifacts image-tracee-artifacts image-tetragon-artifacts \
	image-scx-artifacts image-workload-tools-artifacts image-runner-artifacts image-daemon-artifact \
	image-micro-program-artifacts image-test-artifacts
ifneq ($(BPFREJIT_IMAGE_BUILD),1)
image-bcc-artifacts image-bpftrace-artifacts image-katran-artifacts image-tracee-artifacts image-tetragon-artifacts image-scx-artifacts \
	image-workload-tools-artifacts image-runner-artifacts image-daemon-artifact image-micro-program-artifacts \
	image-test-artifacts:
	@echo "$@ must be run from the runner Dockerfile with BPFREJIT_IMAGE_BUILD=1" >&2
	@exit 1
else
image-bcc-artifacts: $(ACTIVE_BCC_REQUIRED)
image-bpftrace-artifacts: $(ACTIVE_BPFTRACE_REQUIRED)
image-katran-artifacts: $(ACTIVE_KATRAN_REQUIRED)
image-tracee-artifacts: $(ACTIVE_TRACEE_REQUIRED)
image-tetragon-artifacts: $(ACTIVE_TETRAGON_REQUIRED)
image-scx-artifacts: $(ACTIVE_SCX_REQUIRED)
image-workload-tools-artifacts: $(ACTIVE_WORKLOAD_TOOLS_REQUIRED)
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
	make -C "$(ROOT_DIR)/tests/unittest" BUILD_DIR="$(ACTIVE_TEST_UNITTEST_BUILD_DIR)" CC=gcc CLANG=clang

$(ACTIVE_TEST_NEGATIVE_PRIMARY): $(TEST_NEGATIVE_SOURCE_FILES) $(BUILD_RULE_FILES)
	mkdir -p "$(ACTIVE_TEST_NEGATIVE_BUILD_DIR)"
	make -C "$(ROOT_DIR)/tests/negative" BUILD_DIR="$(ACTIVE_TEST_NEGATIVE_BUILD_DIR)" CC=gcc

$(MICRO_PROGRAM_OBJECTS) &: $(MICRO_PROGRAM_SOURCE_FILES) $(BUILD_RULE_FILES)
	mkdir -p "$(MICRO_PROGRAM_OUTPUT_ROOT)"
	make -C "$(MICRO_PROGRAM_SOURCE_ROOT)" OUTPUT_DIR="$(MICRO_PROGRAM_OUTPUT_ROOT)" all
	for path in $(MICRO_PROGRAM_OBJECTS); do test -f "$$path"; done

$(REPO_SCX_ROOT)/bin/%: $(SCX_SOURCE_FILES) $(BUILD_RULE_FILES)
	package="$*"; \
	repo_root="$(REPOS_DIR)/scx"; \
	corpus_root="$(REPO_SCX_ROOT)"; \
	bin_root="$$corpus_root/bin"; \
	target_dir="$(SCX_CARGO_TARGET_DIR)"; \
	target_triple="$(ACTIVE_SCX_TARGET_TRIPLE)"; \
	target_release_dir="$$target_dir/$$target_triple/release"; \
	mkdir -p "$$bin_root" "$$corpus_root" "$$corpus_root/lib" "$$target_dir"; \
	BPF_CLANG=clang CARGO_TARGET_DIR="$$target_dir" \
		cargo build --release --target "$$target_triple" --manifest-path "$$repo_root/Cargo.toml" --package "$$package"; \
	test -x "$$target_release_dir/$$package"; \
	object_path="$$(find "$$target_release_dir/build" -path "*/$$package-*/out/main.bpf.o" | sort | tail -n1)"; \
	install -m 0755 "$$target_release_dir/$$package" "$@"; \
	test -n "$$object_path"; \
	ln -f "$$object_path" "$$corpus_root/$${package}_main.bpf.o"

$(REPO_SCX_ROOT)/%_main.bpf.o: $(REPO_SCX_ROOT)/bin/%
	test -f "$@"

$(ACTIVE_BCC_REQUIRED) &: $(BCC_SOURCE_FILES) $(BUILD_RULE_FILES)
	repo_root="$(REPOS_DIR)/bcc/libbpf-tools"; \
	artifact_root="$(REPO_BCC_ROOT)"; \
	mkdir -p "$$artifact_root"; \
	make -C "$$repo_root" -j"$(JOBS)" \
		OUTPUT="$$artifact_root" \
		LIBBPF_SRC="$(ROOT_DIR)/vendor/libbpf/src" \
		BPFTOOL=bpftool \
		USE_BLAZESYM=0 \
		$(ACTIVE_BCC_ARCH_ARG) \
		$(ACTIVE_BCC_TOOLS); \
	for tool in $(ACTIVE_BCC_TOOLS); do \
		test -x "$$repo_root/$$tool" || { echo "missing bcc tool build output: $$repo_root/$$tool" >&2; exit 1; }; \
		test -f "$$artifact_root/$$tool.bpf.o" || { echo "missing bcc BPF object: $$artifact_root/$$tool.bpf.o" >&2; exit 1; }; \
		install -m 0755 "$$repo_root/$$tool" "$$artifact_root/$$tool"; \
	done; \
	for path in $(ACTIVE_BCC_REQUIRED); do test -e "$$path"; done; \
	touch $(ACTIVE_BCC_REQUIRED)

$(ACTIVE_BPFTRACE_REQUIRED): $(BPFTRACE_SOURCE_FILES) $(BUILD_RULE_FILES)
	build_root="$(BPFTRACE_BUILD_ROOT)"; \
	repo_root="$(REPOS_DIR)/bpftrace"; \
	artifact_root="$(REPO_BPFTRACE_ROOT)"; \
	mkdir -p "$$build_root" "$$artifact_root"; \
	cmake -S "$$repo_root" -B "$$build_root/build" \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_INSTALL_PREFIX="$$artifact_root" \
		-DSTATIC_LINKING=OFF \
		-DBUILD_TESTING=OFF \
		-DENABLE_MAN=OFF \
		-DENABLE_SKB_OUTPUT=OFF \
		-DUSE_SYSTEM_LIBBPF=ON \
		-DLLVM_DIR="$(RUNNER_LLVM_DIR)" \
		-DClang_DIR="$(RUNNER_CLANG_DIR)" \
		-DCMAKE_DISABLE_FIND_PACKAGE_LibBfd=TRUE \
		-DCMAKE_DISABLE_FIND_PACKAGE_LibOpcodes=TRUE; \
	cmake --build "$$build_root/build" --target install -j"$(JOBS)"; \
	test -x "$@"; \
	touch "$@"

$(ACTIVE_TRACEE_REQUIRED) &: $(TRACEE_SOURCE_FILES) $(BUILD_RULE_FILES)
	repo_root="$(REPOS_DIR)/tracee"; \
	dist_root="$(TRACEE_BUILD_DIST_ROOT)"; \
	output_root="$(REPO_TRACEE_ROOT)"; \
	mkdir -p "$$dist_root" "$$output_root/bin" "$$output_root/lsm_support"; \
	rm -rf "$$dist_root/libbpf"; \
	rm -f "$$repo_root/.build_libbpf" "$$repo_root/.build_libbpf_fix" "$$repo_root/.eval_goenv" "$$repo_root/.checklib_libbpf" "$$repo_root/goenv.mk"; \
	GOCACHE="$(TRACEE_BUILD_ROOT)/go-build" \
		make -C "$$repo_root" -j"$(JOBS)" \
			OUTPUT_DIR="$$dist_root" \
			UNAME_M="$(ACTIVE_TRACEE_UNAME_M)" \
			ARCH="$(ACTIVE_TRACEE_ARCH)" \
			LINUX_ARCH="$(ACTIVE_TRACEE_LINUX_ARCH)" \
			GO_ARCH="$(ACTIVE_TRACEE_GOARCH)" \
			CMD_GCC=gcc \
			CMD_CLANG=clang \
			CMD_GO=go \
			CMD_STRIP=llvm-strip \
			CMD_OBJCOPY=llvm-objcopy \
			tracee; \
	test -x "$$dist_root/tracee" || { echo "missing tracee build output: $$dist_root/tracee" >&2; exit 1; }; \
	install -m 0755 "$$dist_root/tracee" "$$output_root/bin/tracee"; \
	ln -f "$$dist_root/tracee.bpf.o" "$$output_root/tracee.bpf.o"; \
	ln -f "$$dist_root/lsm_support/kprobe_check.bpf.o" "$$output_root/lsm_support/kprobe_check.bpf.o"; \
	ln -f "$$dist_root/lsm_support/lsm_check.bpf.o" "$$output_root/lsm_support/lsm_check.bpf.o"; \
	for path in $(ACTIVE_TRACEE_REQUIRED); do test -e "$$path"; done; \
	touch $(ACTIVE_TRACEE_REQUIRED)

$(ACTIVE_TETRAGON_REQUIRED) &: $(TETRAGON_SOURCE_FILES) $(BUILD_RULE_FILES)
	repo_root="$(REPOS_DIR)/tetragon"; \
	build_root="$(TETRAGON_BUILD_ROOT)"; \
	bpf_output_root="$(TETRAGON_BUILD_BPF_ROOT)"; \
	artifact_root="$(REPO_TETRAGON_ROOT)"; \
	target_arch="$(ACTIVE_TETRAGON_TARGET_ARCH)"; \
	goarch="$$target_arch"; \
	version="$$(git -C "$$repo_root" describe --tags --always --exclude '*/*' 2>/dev/null || printf '%s' unknown)"; \
	mkdir -p "$$build_root" "$$artifact_root/bin" "$$bpf_output_root"; \
	if [ -L "$$repo_root/bpf/objs" ] || [ ! -e "$$repo_root/bpf/objs" ]; then \
		ln -sfn "$$bpf_output_root" "$$repo_root/bpf/objs"; \
	else \
		echo "unexpected tetragon bpf/objs directory exists: $$repo_root/bpf/objs" >&2; \
		exit 1; \
	fi; \
	GOCACHE="$$build_root/go-build" \
		make -C "$$repo_root" -j"$(JOBS)" \
			TARGET_ARCH="$$target_arch" \
			GOARCH="$$goarch" \
			VERSION="$$version" \
			LOCAL_CLANG=1 \
			tetragon-bpf tetragon; \
	test -x "$$repo_root/tetragon" || { echo "missing tetragon build output: $$repo_root/tetragon" >&2; exit 1; }; \
	ln -f "$$repo_root/tetragon" "$$artifact_root/bin/tetragon"; \
	ln -f "$$bpf_output_root/bpf_execve_event.o" "$$artifact_root/bpf_execve_event.o"; \
	ln -f "$$bpf_output_root/bpf_generic_kprobe.o" "$$artifact_root/bpf_generic_kprobe.o"; \
	ln -f "$$bpf_output_root/bpf_alignchecker.o" "$$artifact_root/bpf_alignchecker.o"; \
	for path in $(ACTIVE_TETRAGON_REQUIRED); do test -e "$$path"; done; \
	touch $(ACTIVE_TETRAGON_REQUIRED)

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
		CC=gcc CXX=g++ AR=ar RANLIB=ranlib \
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
		CC=gcc CXX=g++ AR=ar RANLIB=ranlib \
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
			-DCMAKE_C_COMPILER=gcc \
			-DCMAKE_CXX_COMPILER=g++ \
			-DCMAKE_AR=/usr/bin/ar \
			-DCMAKE_RANLIB=/usr/bin/ranlib \
			-DCMAKE_USER_MAKE_RULES_OVERRIDE_CXX="$$override_file" \
			-DBUILD_TESTS=OFF; \
	cmake --build "$$build_root/build" --target install -j"$(JOBS)"; \
	cd "$$repo_root" && ./build_bpf_modules_opensource.sh -s "$$repo_root" -b "$$build_root" -o "$$bpf_root"; \
	test -x "$$install_root/bin/katran_server_grpc" || { echo "missing Katran install output: $$install_root/bin/katran_server_grpc" >&2; exit 1; }; \
	[ -f "$$bpf_root/healthchecking_ipip.o" ] && mv -f "$$bpf_root/healthchecking_ipip.o" "$$bpf_root/healthchecking_ipip.bpf.o" || true; \
	for path in $(ACTIVE_KATRAN_REQUIRED); do test -e "$$path"; done; \
	touch $(ACTIVE_KATRAN_REQUIRED)

$(ACTIVE_WORKLOAD_TOOLS_REQUIRED) &: $(WORKLOAD_TOOLS_SOURCE_FILES) $(BUILD_RULE_FILES)
	source_root="$(WORKLOAD_TOOLS_SOURCE_ROOT)"; \
	rt_tests_src="$$source_root/rt-tests"; \
	sysbench_src="$$source_root/sysbench"; \
	wrk_src="$$source_root/wrk"; \
	wrk_luajit_root="$(ACTIVE_BUILD_ARTIFACT_ROOT)/workload-tools-build/$(RUN_TARGET_ARCH)$(BUILD_ARCH_VARIANT)/wrk-luajit"; \
	install_root="$(ACTIVE_WORKLOAD_TOOLS_INSTALL_ROOT)"; \
	bin_root="$$install_root/bin"; \
	lib_root="$$install_root/lib"; \
	test -d "$$rt_tests_src" || { echo "missing workload tool source root: $$rt_tests_src" >&2; exit 1; }; \
	test -d "$$sysbench_src" || { echo "missing workload tool source root: $$sysbench_src" >&2; exit 1; }; \
	test -d "$$wrk_src" || { echo "missing workload tool source root: $$wrk_src" >&2; exit 1; }; \
	mkdir -p "$$wrk_luajit_root" "$$bin_root" "$$lib_root"; \
	make -C "$$rt_tests_src" -j"$(JOBS)" CC=gcc hackbench; \
	cd "$$sysbench_src" && ./configure --prefix="$$install_root" --without-mysql --without-pgsql; \
	make -C "$$sysbench_src" -j"$(JOBS)"; \
	make -C "$$sysbench_src" install; \
	ln -sfn "$$sysbench_src/third_party/luajit/inc" "$$wrk_luajit_root/include"; \
	ln -sfn "$$sysbench_src/third_party/luajit/lib" "$$wrk_luajit_root/lib"; \
	ln -sfn "$$sysbench_src/third_party/luajit/lib" "$$lib_root/luajit"; \
	luajit_bin="$$(find "$$sysbench_src/third_party/luajit/bin" -maxdepth 1 -type f -perm -111 -name 'luajit-*' | sort | head -n 1)"; \
	test -n "$$luajit_bin" || { echo "missing $(RUN_TARGET_ARCH) LuaJIT build output for wrk" >&2; exit 1; }; \
	ln -sfn "$$(basename "$$luajit_bin")" "$$sysbench_src/third_party/luajit/bin/luajit"; \
	mkdir -p "$$wrk_src/obj"; \
	PATH="$$sysbench_src/third_party/luajit/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin" \
		make -C "$$wrk_src" -j"$(JOBS)" \
			CC=gcc \
			WITH_LUAJIT="$$wrk_luajit_root" \
			WITH_OPENSSL="/usr"; \
	test -x "$$wrk_src/wrk" || { echo "missing $(RUN_TARGET_ARCH) wrk build output: $$wrk_src/wrk" >&2; exit 1; }; \
	test -x "$$rt_tests_src/hackbench" || { echo "missing $(RUN_TARGET_ARCH) hackbench build output: $$rt_tests_src/hackbench" >&2; exit 1; }; \
	test -x "$$bin_root/sysbench" || { echo "missing $(RUN_TARGET_ARCH) sysbench install output: $$bin_root/sysbench" >&2; exit 1; }; \
	install -m 0755 "$$rt_tests_src/hackbench" "$$bin_root/hackbench"; \
	install -m 0755 "$$wrk_src/wrk" "$$bin_root/wrk"; \
	chmod 0755 "$$bin_root/sysbench"; \
	for path in $(ACTIVE_WORKLOAD_TOOLS_REQUIRED); do test -x "$$path"; done
endif
