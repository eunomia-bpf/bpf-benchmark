REPOS_DIR := $(RUNNER_DIR)/repos
RUNNER_CONTAINER_DIR := $(RUNNER_DIR)/containers
CONTAINER_RUNTIME ?= docker
RUN_TARGET_ARCH ?= x86_64
HOST_UID := $(shell id -u)
HOST_GID := $(shell id -g)
DOCKERIGNORE_FILE := $(ROOT_DIR)/.dockerignore
REPO_ARTIFACT_ROOT := $(ROOT_DIR)/.cache/repo-artifacts/$(RUN_TARGET_ARCH)
REPO_SCX_ROOT := $(REPO_ARTIFACT_ROOT)/scx
REPO_BCC_ROOT := $(REPO_ARTIFACT_ROOT)/bcc/libbpf-tools/.output
REPO_BPFTRACE_ROOT := $(REPO_ARTIFACT_ROOT)/bpftrace
REPO_TRACEE_ROOT := $(REPO_ARTIFACT_ROOT)/tracee
REPO_TETRAGON_ROOT := $(REPO_ARTIFACT_ROOT)/tetragon
REPO_KATRAN_ROOT := $(REPO_ARTIFACT_ROOT)/katran
REPO_KERNEL_MODULES_ROOT := $(REPO_ARTIFACT_ROOT)/kernel-modules
X86_BUILD_DISTRO_VARIANT := rocky9
BUILD_ARCH_VARIANT := $(if $(filter x86_64,$(RUN_TARGET_ARCH)),-$(X86_BUILD_DISTRO_VARIANT),)
REPO_BUILD_ROOT := $(ARTIFACT_ROOT)/repo-build/$(RUN_TARGET_ARCH)$(BUILD_ARCH_VARIANT)
BUILD_RULE_FILES := $(ROOT_DIR)/Makefile $(RUNNER_DIR)/mk/build.mk $(RUNNER_DIR)/libs/workspace_layout.py
MICRO_PROGRAM_SOURCE_ROOT := $(ROOT_DIR)/micro/programs
MICRO_PROGRAM_OUTPUT_ROOT := $(ARTIFACT_ROOT)/micro-programs/$(RUN_TARGET_ARCH)
MICRO_PROGRAM_SRCS = $(shell find "$(MICRO_PROGRAM_SOURCE_ROOT)" -maxdepth 1 -type f -name '*.bpf.c' -print 2>/dev/null)
MICRO_PROGRAM_OBJECTS = $(patsubst $(MICRO_PROGRAM_SOURCE_ROOT)/%.bpf.c,$(MICRO_PROGRAM_OUTPUT_ROOT)/%.bpf.o,$(MICRO_PROGRAM_SRCS))
SCX_BUILD_ROOT := $(REPO_BUILD_ROOT)/scx
SCX_CARGO_TARGET_DIR := $(SCX_BUILD_ROOT)/target
BCC_BUILD_ROOT := $(REPO_BUILD_ROOT)/bcc
BCC_BUILD_REPO := $(BCC_BUILD_ROOT)/src
BCC_BUILD_OUTPUT_ROOT := $(BCC_BUILD_REPO)/libbpf-tools/.output
BPFTRACE_BUILD_ROOT := $(REPO_BUILD_ROOT)/bpftrace-static
TRACEE_BUILD_ROOT := $(REPO_BUILD_ROOT)/tracee
TRACEE_BUILD_REPO := $(TRACEE_BUILD_ROOT)/src
TRACEE_BUILD_GOENV_MK := $(TRACEE_BUILD_ROOT)/goenv.mk
TRACEE_BUILD_DIST_ROOT := $(TRACEE_BUILD_REPO)/dist
TRACEE_LIBBPF_ROOT := $(TRACEE_BUILD_DIST_ROOT)/libbpf
TRACEE_LIBBPF_OBJDIR := $(TRACEE_LIBBPF_ROOT)/obj-pic
TRACEE_LIBBPF_A := $(TRACEE_LIBBPF_OBJDIR)/libbpf.a
TETRAGON_BUILD_ROOT := $(REPO_BUILD_ROOT)/tetragon
TETRAGON_BUILD_REPO := $(TETRAGON_BUILD_ROOT)/src
TETRAGON_BUILD_BPF_ROOT := $(TETRAGON_BUILD_ROOT)/bpf-objs
RUNNER_BASE_BUILD_DIR_ACTIVE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(RUNNER_DIR)/build-arm64,$(RUNNER_DIR)/build)
RUNNER_BUILD_FEATURE_SUFFIX := $(if $(filter 1,$(RUN_SUITE_NEEDS_LLVMBPF)),-llvmbpf,)
RUNNER_BUILD_DIR_ACTIVE := $(RUNNER_BASE_BUILD_DIR_ACTIVE)$(RUNNER_BUILD_FEATURE_SUFFIX)
RUNNER_LIBBPF_BUILD_DIR := $(RUNNER_BASE_BUILD_DIR_ACTIVE)/vendor/libbpf
RUNNER_LIBBPF_OBJDIR := $(RUNNER_LIBBPF_BUILD_DIR)/obj
RUNNER_LIBBPF_PREFIX := $(RUNNER_LIBBPF_BUILD_DIR)/prefix
RUNNER_LIBBPF_A := $(RUNNER_LIBBPF_OBJDIR)/libbpf.a
DEFAULT_RUNNER_LLVM_DIR := /usr/lib64/llvm20/lib64/cmake/llvm
RUNNER_LLVM_DIR := $(if $(strip $(LLVM_DIR)),$(LLVM_DIR),$(if $(strip $(RUN_LLVM_DIR)),$(RUN_LLVM_DIR),$(DEFAULT_RUNNER_LLVM_DIR)))
RUNNER_CONTAINER_CC := /opt/rh/gcc-toolset-14/root/usr/bin/gcc
RUNNER_CONTAINER_CXX := /opt/rh/gcc-toolset-14/root/usr/bin/g++
CONTAINER_IMAGE_ARTIFACT_ROOT := $(ARTIFACT_ROOT)/container-images
KATRAN_BUILD_ROOT := $(REPO_BUILD_ROOT)/katran
KATRAN_BUILD_REPO := $(KATRAN_BUILD_ROOT)/src
KATRAN_INSTALL_ROOT := $(REPO_KATRAN_ROOT)
KATRAN_CMAKE_OVERRIDE := $(KATRAN_BUILD_ROOT)/cxx-override.cmake
ACTIVE_WORKLOAD_TOOLS_INSTALL_ROOT := $(ARTIFACT_ROOT)/workload-tools/$(RUN_TARGET_ARCH)
ACTIVE_WORKLOAD_TOOLS_BIN_ROOT := $(ACTIVE_WORKLOAD_TOOLS_INSTALL_ROOT)/bin
ACTIVE_DAEMON_BINARY := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(DAEMON_DIR)/target/aarch64-unknown-linux-gnu/release/bpfrejit-daemon,$(DAEMON_DIR)/target/release/bpfrejit-daemon)
ACTIVE_DAEMON_TARGET_TRIPLE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),aarch64-unknown-linux-gnu,)
ACTIVE_DAEMON_TARGET_ARG := $(if $(strip $(ACTIVE_DAEMON_TARGET_TRIPLE)),TARGET_TRIPLE="$(ACTIVE_DAEMON_TARGET_TRIPLE)",)
ACTIVE_CARGO_TARGET_LINKER_ENV := $(if $(filter arm64,$(RUN_TARGET_ARCH)),-e CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER=gcc,)
ACTIVE_RUNNER_BINARY := $(RUNNER_BUILD_DIR_ACTIVE)/micro_exec
ACTIVE_TEST_UNITTEST_BUILD_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/tests/unittest/build-arm64,$(ROOT_DIR)/tests/unittest/build)
ACTIVE_TEST_NEGATIVE_BUILD_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/tests/negative/build-arm64,$(ROOT_DIR)/tests/negative/build)
ACTIVE_TEST_UNITTEST_PRIMARY := $(ACTIVE_TEST_UNITTEST_BUILD_DIR)/rejit_regression
ACTIVE_TEST_NEGATIVE_PRIMARY := $(ACTIVE_TEST_NEGATIVE_BUILD_DIR)/scx_prog_show_race
ACTIVE_MICRO_PROGRAM_PRIMARY := $(MICRO_PROGRAM_OUTPUT_ROOT)/simple.bpf.o
RUNNER_BUILD_CONTAINERFILE := $(RUNNER_CONTAINER_DIR)/runner-build.Dockerfile
RUNNER_RUNTIME_CONTAINERFILE := $(RUNNER_CONTAINER_DIR)/runner-runtime.Dockerfile
BPFTRACE_STATIC_CONTAINERFILE := $(REPOS_DIR)/bpftrace/docker/Dockerfile.static
X86_RUNNER_BUILD_CONTAINERFILE := $(RUNNER_BUILD_CONTAINERFILE)
ARM64_RUNNER_BUILD_CONTAINERFILE := $(RUNNER_BUILD_CONTAINERFILE)
X86_RUNNER_RUNTIME_CONTAINERFILE := $(RUNNER_RUNTIME_CONTAINERFILE)
ARM64_RUNNER_RUNTIME_CONTAINERFILE := $(RUNNER_RUNTIME_CONTAINERFILE)
X86_RUNNER_BUILD_IMAGE := bpf-benchmark/runner-build:x86_64
ARM64_RUNNER_BUILD_IMAGE := bpf-benchmark/runner-build:arm64
X86_RUNNER_RUNTIME_IMAGE := bpf-benchmark/runner-runtime:x86_64
ARM64_RUNNER_RUNTIME_IMAGE := bpf-benchmark/runner-runtime:arm64
X86_BPFTRACE_STATIC_BUILD_IMAGE := bpf-benchmark/bpftrace-static-build:x86_64
ARM64_BPFTRACE_STATIC_BUILD_IMAGE := bpf-benchmark/bpftrace-static-build:arm64
X86_RUNNER_BUILD_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/x86_64-runner-build.image.tar
ARM64_RUNNER_BUILD_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/arm64-runner-build.image.tar
X86_RUNNER_RUNTIME_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/x86_64-runner-runtime.image.tar
ARM64_RUNNER_RUNTIME_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/arm64-runner-runtime.image.tar
X86_BPFTRACE_STATIC_BUILD_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/x86_64-bpftrace-static-build.image.tar
ARM64_BPFTRACE_STATIC_BUILD_IMAGE_TAR := $(CONTAINER_IMAGE_ARTIFACT_ROOT)/arm64-bpftrace-static-build.image.tar
ACTIVE_CONTAINER_PLATFORM := $(if $(filter arm64,$(RUN_TARGET_ARCH)),linux/arm64,linux/amd64)
ACTIVE_RUNNER_BUILD_IMAGE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_RUNNER_BUILD_IMAGE),$(X86_RUNNER_BUILD_IMAGE))
ACTIVE_RUNNER_BUILD_IMAGE_TAR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_RUNNER_BUILD_IMAGE_TAR),$(X86_RUNNER_BUILD_IMAGE_TAR))
ACTIVE_BPFTRACE_STATIC_BUILD_IMAGE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_BPFTRACE_STATIC_BUILD_IMAGE),$(X86_BPFTRACE_STATIC_BUILD_IMAGE))
ACTIVE_BPFTRACE_STATIC_BUILD_IMAGE_TAR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_BPFTRACE_STATIC_BUILD_IMAGE_TAR),$(X86_BPFTRACE_STATIC_BUILD_IMAGE_TAR))
ENSURE_X86_RUNNER_BUILD_IMAGE = $(CONTAINER_RUNTIME) image inspect "$(X86_RUNNER_BUILD_IMAGE)" >/dev/null 2>&1 || $(CONTAINER_RUNTIME) load -i "$(X86_RUNNER_BUILD_IMAGE_TAR)"
ENSURE_ARM64_RUNNER_BUILD_IMAGE = $(CONTAINER_RUNTIME) image inspect "$(ARM64_RUNNER_BUILD_IMAGE)" >/dev/null 2>&1 || $(CONTAINER_RUNTIME) load -i "$(ARM64_RUNNER_BUILD_IMAGE_TAR)"
ENSURE_ACTIVE_RUNNER_BUILD_IMAGE = $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ENSURE_ARM64_RUNNER_BUILD_IMAGE),$(ENSURE_X86_RUNNER_BUILD_IMAGE))
ENSURE_X86_BPFTRACE_STATIC_BUILD_IMAGE = $(CONTAINER_RUNTIME) image inspect "$(X86_BPFTRACE_STATIC_BUILD_IMAGE)" >/dev/null 2>&1 || $(CONTAINER_RUNTIME) load -i "$(X86_BPFTRACE_STATIC_BUILD_IMAGE_TAR)"
ENSURE_ARM64_BPFTRACE_STATIC_BUILD_IMAGE = $(CONTAINER_RUNTIME) image inspect "$(ARM64_BPFTRACE_STATIC_BUILD_IMAGE)" >/dev/null 2>&1 || $(CONTAINER_RUNTIME) load -i "$(ARM64_BPFTRACE_STATIC_BUILD_IMAGE_TAR)"
ENSURE_ACTIVE_BPFTRACE_STATIC_BUILD_IMAGE = $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ENSURE_ARM64_BPFTRACE_STATIC_BUILD_IMAGE),$(ENSURE_X86_BPFTRACE_STATIC_BUILD_IMAGE))
ACTIVE_X86_KINSN_SOURCE_DIR := $(ROOT_DIR)/module/x86
ACTIVE_X86_KINSN_OUTPUT_DIR := $(if $(filter 1,$(RUN_AWS_KERNEL)),$(X86_AWS_KINSN_MODULE_DIR),$(ACTIVE_X86_KINSN_SOURCE_DIR))
ACTIVE_KINSN_SOURCE_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/module/arm64,$(ACTIVE_X86_KINSN_SOURCE_DIR))
ACTIVE_KINSN_MODULE_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/module/arm64,$(ACTIVE_X86_KINSN_OUTPUT_DIR))
ACTIVE_X86_KERNEL_BUILD_DIR := $(if $(filter 1,$(RUN_AWS_KERNEL)),$(X86_AWS_BUILD_DIR),$(X86_BUILD_DIR))
ACTIVE_X86_KERNEL_IMAGE := $(if $(filter 1,$(RUN_AWS_KERNEL)),$(X86_AWS_IMAGE),$(X86_BUILD_DIR)/arch/x86/boot/bzImage)
ACTIVE_X86_KERNEL_CONFIG_DEP := $(if $(filter 1,$(RUN_AWS_KERNEL)),$(X86_AWS_BUILD_CONFIG),$(X86_BUILD_DIR)/include/linux/kconfig.h)
ACTIVE_KERNEL_BUILD_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_AWS_BUILD_DIR),$(ACTIVE_X86_KERNEL_BUILD_DIR))
ACTIVE_KERNEL_ARCH_ARG := $(if $(filter arm64,$(RUN_TARGET_ARCH)),ARCH=arm64,)
ACTIVE_SCX_TARGET_TRIPLE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),aarch64-unknown-linux-gnu,x86_64-unknown-linux-gnu)
ACTIVE_BCC_ARCH_ARG := $(if $(filter arm64,$(RUN_TARGET_ARCH)),ARCH=arm64,)
ACTIVE_TRACEE_UNAME_M := $(if $(filter arm64,$(RUN_TARGET_ARCH)),aarch64,x86_64)
ACTIVE_TRACEE_ARCH := $(if $(filter arm64,$(RUN_TARGET_ARCH)),arm64,x86_64)
ACTIVE_TRACEE_LINUX_ARCH := $(if $(filter arm64,$(RUN_TARGET_ARCH)),arm64,x86)
ACTIVE_TRACEE_GOARCH := $(if $(filter arm64,$(RUN_TARGET_ARCH)),arm64,amd64)
ACTIVE_TETRAGON_TARGET_ARCH := $(if $(filter arm64,$(RUN_TARGET_ARCH)),arm64,amd64)
ACTIVE_KINSN_PRIMARY := $(ACTIVE_KINSN_MODULE_DIR)/bpf_rotate.ko
ACTIVE_KINSN_SECONDARIES := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ACTIVE_KINSN_MODULE_DIR)/bpf_select.ko $(ACTIVE_KINSN_MODULE_DIR)/bpf_extract.ko $(ACTIVE_KINSN_MODULE_DIR)/bpf_endian.ko $(ACTIVE_KINSN_MODULE_DIR)/bpf_ldp.ko $(ACTIVE_KINSN_MODULE_DIR)/bpf_bulk_memory.ko,$(ACTIVE_KINSN_MODULE_DIR)/bpf_select.ko $(ACTIVE_KINSN_MODULE_DIR)/bpf_extract.ko $(ACTIVE_KINSN_MODULE_DIR)/bpf_endian.ko $(ACTIVE_KINSN_MODULE_DIR)/bpf_bulk_memory.ko)
ACTIVE_BCC_TOOLS := capable execsnoop bindsnoop biosnoop vfsstat opensnoop syscount tcpconnect tcplife runqlat
ACTIVE_BCC_REQUIRED := $(addprefix $(REPO_BCC_ROOT)/,$(ACTIVE_BCC_TOOLS)) $(addsuffix .bpf.o,$(addprefix $(REPO_BCC_ROOT)/,$(ACTIVE_BCC_TOOLS)))
ACTIVE_BPFTRACE_REQUIRED := $(REPO_BPFTRACE_ROOT)/bin/bpftrace
ACTIVE_TRACEE_REQUIRED := $(REPO_TRACEE_ROOT)/bin/tracee $(REPO_TRACEE_ROOT)/tracee.bpf.o $(REPO_TRACEE_ROOT)/lsm_support/kprobe_check.bpf.o $(REPO_TRACEE_ROOT)/lsm_support/lsm_check.bpf.o
ACTIVE_TETRAGON_REQUIRED := $(REPO_TETRAGON_ROOT)/bin/tetragon $(REPO_TETRAGON_ROOT)/bpf_execve_event.o $(REPO_TETRAGON_ROOT)/bpf_generic_kprobe.o $(REPO_TETRAGON_ROOT)/bpf_alignchecker.o
ACTIVE_KATRAN_REQUIRED := $(REPO_KATRAN_ROOT)/bin/katran_server_grpc $(REPO_KATRAN_ROOT)/bpf/balancer.bpf.o $(REPO_KATRAN_ROOT)/bpf/healthchecking_ipip.bpf.o
ACTIVE_WORKLOAD_TOOLS_REQUIRED := $(ACTIVE_WORKLOAD_TOOLS_BIN_ROOT)/hackbench $(ACTIVE_WORKLOAD_TOOLS_BIN_ROOT)/sysbench $(ACTIVE_WORKLOAD_TOOLS_BIN_ROOT)/wrk
ACTIVE_SCX_REQUIRED := $(REPO_SCX_ROOT)/bin/scx_rusty $(REPO_SCX_ROOT)/scx_rusty_main.bpf.o
ACTIVE_NATIVE_REPO_REQUIRED := $(ACTIVE_BCC_REQUIRED) $(ACTIVE_BPFTRACE_REQUIRED) $(ACTIVE_KATRAN_REQUIRED) $(ACTIVE_TRACEE_REQUIRED) $(ACTIVE_TETRAGON_REQUIRED)
ACTIVE_RUNTIME_USERSPACE_REQUIRED := $(ACTIVE_DAEMON_BINARY) $(ACTIVE_RUNNER_BINARY) $(MICRO_PROGRAM_OBJECTS) $(ACTIVE_WORKLOAD_TOOLS_REQUIRED) $(ACTIVE_NATIVE_REPO_REQUIRED) $(ACTIVE_SCX_REQUIRED)
DAEMON_SOURCE_FILES = $(shell find "$(ROOT_DIR)/daemon/src" -type f 2>/dev/null) $(ROOT_DIR)/daemon/Cargo.toml $(ROOT_DIR)/daemon/Cargo.lock $(ROOT_DIR)/daemon/Makefile
RUNNER_CORE_SOURCE_FILES = $(shell find "$(RUNNER_DIR)/src" "$(RUNNER_DIR)/include" -type f ! -name 'llvmbpf_runner.cpp' 2>/dev/null) $(RUNNER_DIR)/CMakeLists.txt
RUNNER_LLVMBPF_SOURCE_FILES = $(RUNNER_DIR)/src/llvmbpf_runner.cpp $(shell find "$(ROOT_DIR)/vendor/llvmbpf/include" "$(ROOT_DIR)/vendor/llvmbpf/src" -type f 2>/dev/null)
RUNNER_SOURCE_FILES = $(RUNNER_CORE_SOURCE_FILES) $(if $(filter 1,$(RUN_SUITE_NEEDS_LLVMBPF)),$(RUNNER_LLVMBPF_SOURCE_FILES),)
TEST_UNITTEST_SOURCE_FILES = $(shell find "$(ROOT_DIR)/tests/unittest" \( -path '*/build' -o -path '*/build-arm64' \) -prune -o -type f -print 2>/dev/null)
TEST_NEGATIVE_SOURCE_FILES = $(shell find "$(ROOT_DIR)/tests/negative" \( -path '*/build' -o -path '*/build-arm64' \) -prune -o -type f -print 2>/dev/null)
MICRO_PROGRAM_SOURCE_FILES = $(MICRO_PROGRAM_SRCS) $(shell find "$(MICRO_PROGRAM_SOURCE_ROOT)" -maxdepth 1 -type f \( -name '*.h' -o -name 'Makefile' \) -print 2>/dev/null)
KINSN_SOURCE_FILES = $(shell find "$(ACTIVE_KINSN_SOURCE_DIR)" "$(ROOT_DIR)/module/include" -type f \( -name '*.c' -o -name '*.h' -o -name 'Makefile' \) -print 2>/dev/null)
SCX_SOURCE_FILES = $(shell find "$(REPOS_DIR)/scx" \( -path '*/target' -o -path '*/.git' \) -prune -o -type f \( -name '*.rs' -o -name '*.c' -o -name '*.h' -o -name 'Cargo.toml' -o -name 'Cargo.lock' -o -name 'build.rs' \) -print 2>/dev/null)
BCC_SOURCE_FILES = $(shell find "$(REPOS_DIR)/bcc/libbpf-tools" \( -path '*/.output' -o -path '*/.git' \) -prune -o -type f \( -name '*.c' -o -name '*.h' -o -name '*.sh' -o -name '*.mk' -o -name '*.yaml' -o -name '*.json' -o -name '*.txt' -o -name 'Makefile' \) -print 2>/dev/null)
BPFTRACE_SOURCE_FILES = $(shell find "$(REPOS_DIR)/bpftrace" \( -path '*/build' -o -path '*/.git' \) -prune -o -type f -print 2>/dev/null)
TRACEE_SOURCE_FILES = $(shell find "$(REPOS_DIR)/tracee" \( -path '*/dist' -o -path '*/build' -o -path '*/.git' \) -prune -o -type f \( -name '*.go' -o -name '*.c' -o -name '*.h' -o -name '*.mk' -o -name 'Makefile' -o -name 'go.mod' -o -name 'go.sum' \) -print 2>/dev/null)
TETRAGON_SOURCE_FILES = $(shell find "$(REPOS_DIR)/tetragon" \( -path '*/bpf/objs' -o -path '*/.git' \) -prune -o -type f \( -name '*.go' -o -name '*.c' -o -name '*.h' -o -name '*.yaml' -o -name '*.mk' -o -name 'Makefile' -o -name 'go.mod' -o -name 'go.sum' \) -print 2>/dev/null)
KATRAN_SOURCE_FILES = $(shell find "$(REPOS_DIR)/katran" \( -path '*/build' -o -path '*/_build' -o -path '*/deps' -o -path '*/.git' \) -prune -o -type f \( -name '*.cc' -o -name '*.cpp' -o -name '*.c' -o -name '*.h' -o -name '*.hpp' -o -name '*.bpf.c' -o -name '*.sh' -o -name '*.cmake' -o -name 'CMakeLists.txt' \) -print 2>/dev/null)
WORKLOAD_TOOLS_SOURCE_FILES = $(shell find "$(WORKLOAD_TOOLS_SOURCE_ROOT)" \( -path '*/.git' -o -path '*/autom4te.cache' \) -prune -o -type f \( -name '*.c' -o -name '*.cc' -o -name '*.h' -o -name '*.lua' -o -name '*.mk' -o -name '*.am' -o -name '*.ac' -o -name 'Makefile' -o -name 'configure*' \) -print 2>/dev/null)
LIBBPF_SOURCE_FILES = $(shell find "$(ROOT_DIR)/vendor/libbpf" \( -path '*/.git' -o -path '*/build' -o -path '*/obj' -o -path '*/prefix' \) -prune -o -type f -print 2>/dev/null)
KERNEL_BUILD_META_FILES = $(shell find "$(KERNEL_DIR)" \( -path '*/.git' -o -path '*/build*' -o -path '*/.cache' \) -prune -o -type f \( -name 'Makefile' -o -name 'Kconfig*' -o -name '*.mk' -o -path '*/scripts/config' \) -print 2>/dev/null)
KERNEL_SOURCE_FILES = $(shell find "$(KERNEL_DIR)" \( -path '*/.git' -o -path '*/build*' -o -path '*/.cache' \) -prune -o -type f \( -name '*.c' -o -name '*.h' -o -name '*.S' -o -name '*.lds' -o -name '*.dts' -o -name '*.dtsi' -o -name '*.sh' \) -print 2>/dev/null)

$(DAEMON_SOURCE_FILES) \
$(RUNNER_SOURCE_FILES) \
$(TEST_UNITTEST_SOURCE_FILES) \
$(TEST_NEGATIVE_SOURCE_FILES) \
$(MICRO_PROGRAM_SOURCE_FILES) \
$(KINSN_SOURCE_FILES) \
$(SCX_SOURCE_FILES) \
$(BCC_SOURCE_FILES) \
$(BPFTRACE_SOURCE_FILES) \
$(TRACEE_SOURCE_FILES) \
$(TETRAGON_SOURCE_FILES) \
$(KATRAN_SOURCE_FILES) \
$(WORKLOAD_TOOLS_SOURCE_FILES) \
$(LIBBPF_SOURCE_FILES) \
$(KERNEL_BUILD_META_FILES) \
$(KERNEL_SOURCE_FILES): ;

.PHONY: FORCE
FORCE:

$(RUNNER_LIBBPF_A): $(LIBBPF_SOURCE_FILES) $(BUILD_RULE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_TAR)
	@$(ENSURE_ACTIVE_RUNNER_BUILD_IMAGE)
	@$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		rm -rf "$(RUNNER_LIBBPF_OBJDIR)" "$(RUNNER_LIBBPF_PREFIX)"
	@mkdir -p "$(RUNNER_LIBBPF_OBJDIR)" "$(RUNNER_LIBBPF_PREFIX)/include"
	$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		make -C "$(ROOT_DIR)/vendor/libbpf/src" -j"$(JOBS)" BUILD_STATIC_ONLY=1 \
			OBJDIR="$(RUNNER_LIBBPF_OBJDIR)" DESTDIR= PREFIX="$(RUNNER_LIBBPF_PREFIX)" \
			"$(RUNNER_LIBBPF_A)" install_headers

$(X86_RUNNER_BUILD_IMAGE_TAR): $(X86_RUNNER_BUILD_CONTAINERFILE) $(DOCKERIGNORE_FILE)
	@mkdir -p "$(dir $@)"
	$(CONTAINER_RUNTIME) build --platform linux/amd64 -t "$(X86_RUNNER_BUILD_IMAGE)" -f "$(X86_RUNNER_BUILD_CONTAINERFILE)" "$(ROOT_DIR)"
	$(CONTAINER_RUNTIME) save -o "$@" "$(X86_RUNNER_BUILD_IMAGE)"

$(ARM64_RUNNER_BUILD_IMAGE_TAR): $(ARM64_RUNNER_BUILD_CONTAINERFILE) $(DOCKERIGNORE_FILE)
	@mkdir -p "$(dir $@)"
	$(CONTAINER_RUNTIME) build --platform linux/arm64 -t "$(ARM64_RUNNER_BUILD_IMAGE)" -f "$(ARM64_RUNNER_BUILD_CONTAINERFILE)" "$(ROOT_DIR)"
	$(CONTAINER_RUNTIME) save -o "$@" "$(ARM64_RUNNER_BUILD_IMAGE)"

$(X86_BPFTRACE_STATIC_BUILD_IMAGE_TAR): $(BPFTRACE_STATIC_CONTAINERFILE)
	@mkdir -p "$(dir $@)"
	$(CONTAINER_RUNTIME) build --platform linux/amd64 -t "$(X86_BPFTRACE_STATIC_BUILD_IMAGE)" -f "$(BPFTRACE_STATIC_CONTAINERFILE)" "$(REPOS_DIR)/bpftrace"
	$(CONTAINER_RUNTIME) save -o "$@" "$(X86_BPFTRACE_STATIC_BUILD_IMAGE)"

$(ARM64_BPFTRACE_STATIC_BUILD_IMAGE_TAR): $(BPFTRACE_STATIC_CONTAINERFILE)
	@mkdir -p "$(dir $@)"
	$(CONTAINER_RUNTIME) build --platform linux/arm64 -t "$(ARM64_BPFTRACE_STATIC_BUILD_IMAGE)" -f "$(BPFTRACE_STATIC_CONTAINERFILE)" "$(REPOS_DIR)/bpftrace"
	$(CONTAINER_RUNTIME) save -o "$@" "$(ARM64_BPFTRACE_STATIC_BUILD_IMAGE)"

ifeq ($(RUN_TARGET_ARCH),x86_64)
$(X86_RUNNER_RUNTIME_IMAGE_TAR): $(X86_RUNNER_RUNTIME_CONTAINERFILE) $(ACTIVE_RUNTIME_USERSPACE_REQUIRED)
	@mkdir -p "$(dir $@)"
	$(CONTAINER_RUNTIME) build --platform linux/amd64 \
		--build-context repo-artifacts="$(REPO_ARTIFACT_ROOT)" \
		--build-context workload-tools="$(ACTIVE_WORKLOAD_TOOLS_INSTALL_ROOT)" \
		--build-context daemon-bin="$(dir $(ACTIVE_DAEMON_BINARY))" \
		--build-context runner-bin="$(RUNNER_BUILD_DIR_ACTIVE)" \
		--build-context micro-programs="$(MICRO_PROGRAM_OUTPUT_ROOT)" \
		-t "$(X86_RUNNER_RUNTIME_IMAGE)" -f "$(X86_RUNNER_RUNTIME_CONTAINERFILE)" "$(RUNNER_CONTAINER_DIR)"
	$(CONTAINER_RUNTIME) save -o "$@" "$(X86_RUNNER_RUNTIME_IMAGE)"
else
$(X86_RUNNER_RUNTIME_IMAGE_TAR): FORCE
	@echo "RUN_TARGET_ARCH=$(RUN_TARGET_ARCH) does not match $@" >&2
	@exit 1
endif

ifeq ($(RUN_TARGET_ARCH),arm64)
$(ARM64_RUNNER_RUNTIME_IMAGE_TAR): $(ARM64_RUNNER_RUNTIME_CONTAINERFILE) $(ACTIVE_RUNTIME_USERSPACE_REQUIRED)
	@mkdir -p "$(dir $@)"
	$(CONTAINER_RUNTIME) build --platform linux/arm64 \
		--build-context repo-artifacts="$(REPO_ARTIFACT_ROOT)" \
		--build-context workload-tools="$(ACTIVE_WORKLOAD_TOOLS_INSTALL_ROOT)" \
		--build-context daemon-bin="$(dir $(ACTIVE_DAEMON_BINARY))" \
		--build-context runner-bin="$(RUNNER_BUILD_DIR_ACTIVE)" \
		--build-context micro-programs="$(MICRO_PROGRAM_OUTPUT_ROOT)" \
		-t "$(ARM64_RUNNER_RUNTIME_IMAGE)" -f "$(ARM64_RUNNER_RUNTIME_CONTAINERFILE)" "$(RUNNER_CONTAINER_DIR)"
	$(CONTAINER_RUNTIME) save -o "$@" "$(ARM64_RUNNER_RUNTIME_IMAGE)"
else
$(ARM64_RUNNER_RUNTIME_IMAGE_TAR): FORCE
	@echo "RUN_TARGET_ARCH=$(RUN_TARGET_ARCH) does not match $@" >&2
	@exit 1
endif

$(X86_BUILD_DIR)/arch/x86/boot/bzImage: $(KERNEL_CONFIG_PATH) $(KERNEL_BUILD_META_FILES) $(KERNEL_SOURCE_FILES) $(X86_RUNNER_BUILD_IMAGE_TAR)
	@mkdir -p "$(X86_BUILD_DIR)"
	@$(ENSURE_X86_RUNNER_BUILD_IMAGE)
	@$(CONTAINER_RUNTIME) run --rm --platform linux/amd64 \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(X86_RUNNER_BUILD_IMAGE)" \
		make -C "$(KERNEL_DIR)" O="$(X86_BUILD_DIR)" olddefconfig
	@$(CONTAINER_RUNTIME) run --rm --platform linux/amd64 \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(X86_RUNNER_BUILD_IMAGE)" \
		make -C "$(KERNEL_DIR)" O="$(X86_BUILD_DIR)" -j"$(JOBS)" bzImage modules

$(X86_BUILD_DIR)/include/linux/kconfig.h:
	@mkdir -p "$(X86_BUILD_DIR)/include"
	@ln -sfn "$(KERNEL_DIR)/include/linux" "$(X86_BUILD_DIR)/include/linux"
	@test -f "$@"

$(ACTIVE_DAEMON_BINARY): $(DAEMON_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_TAR)
	@mkdir -p "$(dir $@)"
	@$(ENSURE_ACTIVE_RUNNER_BUILD_IMAGE)
	$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		$(ACTIVE_CARGO_TARGET_LINKER_ENV) -e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		make -C "$(ROOT_DIR)/daemon" release TARGET_DIR="$(DAEMON_DIR)/target" $(ACTIVE_DAEMON_TARGET_ARG)

$(ACTIVE_RUNNER_BINARY): $(RUNNER_LIBBPF_A) $(RUNNER_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_TAR)
	@mkdir -p "$(dir $@)"
	@$(ENSURE_ACTIVE_RUNNER_BUILD_IMAGE)
	@$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		rm -rf "$(RUNNER_BUILD_DIR_ACTIVE)/CMakeCache.txt" "$(RUNNER_BUILD_DIR_ACTIVE)/CMakeFiles"
	@$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		cmake -S "$(RUNNER_DIR)" -B "$(RUNNER_BUILD_DIR_ACTIVE)" \
			-DCMAKE_BUILD_TYPE=Release \
			-DCMAKE_C_COMPILER="$(RUNNER_CONTAINER_CC)" \
			-DCMAKE_CXX_COMPILER="$(RUNNER_CONTAINER_CXX)" \
			-DMICRO_REPO_ROOT="$(ROOT_DIR)" \
			-DMICRO_LIBBPF_PREFIX="$(RUNNER_LIBBPF_PREFIX)" \
			-DMICRO_LIBBPF_LIBRARY="$(RUNNER_LIBBPF_A)" \
			-DMICRO_EXEC_ENABLE_LLVMBPF="$(RUN_SUITE_NEEDS_LLVMBPF)" \
			-DLLVM_DIR="$(RUNNER_LLVM_DIR)"
	@$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		cmake --build "$(RUNNER_BUILD_DIR_ACTIVE)" --target micro_exec -j"$(JOBS)"

$(ACTIVE_TEST_UNITTEST_PRIMARY): $(TEST_UNITTEST_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_TAR)
	@mkdir -p "$(ACTIVE_TEST_UNITTEST_BUILD_DIR)" "$(ACTIVE_TEST_UNITTEST_BUILD_DIR)/vendor/bpftool"
	@$(ENSURE_ACTIVE_RUNNER_BUILD_IMAGE)
	@$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		make -C "$(ROOT_DIR)/tests/unittest" BUILD_DIR="$(ACTIVE_TEST_UNITTEST_BUILD_DIR)" CC=gcc CLANG=clang

$(ACTIVE_TEST_NEGATIVE_PRIMARY): $(TEST_NEGATIVE_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_TAR)
	@mkdir -p "$(ACTIVE_TEST_NEGATIVE_BUILD_DIR)"
	@$(ENSURE_ACTIVE_RUNNER_BUILD_IMAGE)
	@$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		make -C "$(ROOT_DIR)/tests/negative" BUILD_DIR="$(ACTIVE_TEST_NEGATIVE_BUILD_DIR)" CC=gcc

$(MICRO_PROGRAM_OBJECTS) &: $(MICRO_PROGRAM_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_TAR)
	@mkdir -p "$(MICRO_PROGRAM_OUTPUT_ROOT)"
	@$(ENSURE_ACTIVE_RUNNER_BUILD_IMAGE)
	@$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		make -C "$(MICRO_PROGRAM_SOURCE_ROOT)" OUTPUT_DIR="$(MICRO_PROGRAM_OUTPUT_ROOT)" all; \
	for path in $(MICRO_PROGRAM_OBJECTS); do \
		test -f "$$path"; \
	done

$(ACTIVE_KINSN_PRIMARY): $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_AWS_BUILD_DIR)/arch/arm64/boot/Image,$(ACTIVE_X86_KERNEL_IMAGE)) $(KINSN_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_TAR)
	@mkdir -p "$(ACTIVE_KINSN_MODULE_DIR)"
	@if [ "$(filter 1,$(RUN_AWS_KERNEL))" = "1" ]; then \
		mkdir -p "$(X86_AWS_KINSN_MODULE_ROOT)/include"; \
		rsync -a --delete --delete-excluded --include='*/' --include='*.c' --include='*.h' --include='Makefile' --exclude='*' "$(ACTIVE_KINSN_SOURCE_DIR)/" "$(ACTIVE_KINSN_MODULE_DIR)/"; \
		rsync -a --delete --delete-excluded --include='*/' --include='*.h' --exclude='*' "$(ROOT_DIR)/module/include/" "$(X86_AWS_KINSN_MODULE_ROOT)/include/"; \
	fi
	@$(ENSURE_ACTIVE_RUNNER_BUILD_IMAGE)
	$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		make $(ACTIVE_KERNEL_ARCH_ARG) -C "$(KERNEL_DIR)" O="$(ACTIVE_KERNEL_BUILD_DIR)" M="$(ACTIVE_KINSN_MODULE_DIR)" modules

$(ACTIVE_KINSN_SECONDARIES): $(ACTIVE_KINSN_PRIMARY)
	@test -f "$@"

$(REPO_KERNEL_MODULES_ROOT)/lib/modules: $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_AWS_IMAGE) $(ARM64_AWS_BUILD_CONFIG),$(ACTIVE_X86_KERNEL_IMAGE) $(ACTIVE_X86_KERNEL_CONFIG_DEP)) $(ACTIVE_RUNNER_BUILD_IMAGE_TAR)
	@stage_root="$(REPO_KERNEL_MODULES_ROOT)"; \
	$(ENSURE_ACTIVE_RUNNER_BUILD_IMAGE); \
	kernel_release_file="$(ACTIVE_KERNEL_BUILD_DIR)/include/config/kernel.release"; \
	test -f "$$kernel_release_file" || { echo "missing kernel release file: $$kernel_release_file" >&2; exit 1; }; \
		kernel_release="$$(tr -d '\n' < "$$kernel_release_file")"; \
		release_root="$$stage_root/lib/modules/$$kernel_release"; \
		mkdir -p "$$stage_root"; \
		rm -rf "$$release_root"; \
		if [ "$(filter arm64,$(RUN_TARGET_ARCH))" = "arm64" ]; then \
			$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
				--user "$(HOST_UID):$(HOST_GID)" \
				-e HOME=/tmp/bpf-benchmark-container \
				-v "$(ROOT_DIR):$(ROOT_DIR)" \
				-w "$(ROOT_DIR)" \
				"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
				make $(ACTIVE_KERNEL_ARCH_ARG) --no-print-directory -C "$(KERNEL_DIR)" O="$(ACTIVE_KERNEL_BUILD_DIR)" -j"$(JOBS)" modules; \
		fi; \
		$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
			--user "$(HOST_UID):$(HOST_GID)" \
			-e HOME=/tmp/bpf-benchmark-container \
			-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		make $(ACTIVE_KERNEL_ARCH_ARG) --no-print-directory -C "$(KERNEL_DIR)" O="$(ACTIVE_KERNEL_BUILD_DIR)" INSTALL_MOD_PATH="$$stage_root" DEPMOD=true modules_install >/dev/null; \
	$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		depmod -b "$$stage_root" "$$kernel_release" >/dev/null; \
	ln -sfn "$(ACTIVE_KERNEL_BUILD_DIR)" "$$release_root/build"; \
		ln -sfn "$(KERNEL_DIR)" "$$release_root/source"; \
		test -f "$$release_root/kernel/drivers/block/null_blk/null_blk.ko"; \
		test -f "$$release_root/kernel/net/sched/sch_netem.ko"; \
		touch "$@"

$(REPO_SCX_ROOT)/bin/%: $(SCX_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_TAR)
	@package="$*"; \
	$(ENSURE_ACTIVE_RUNNER_BUILD_IMAGE); \
	repo_root="$(REPOS_DIR)/scx"; \
	corpus_root="$(REPO_SCX_ROOT)"; \
	bin_root="$$corpus_root/bin"; \
	target_dir="$(SCX_CARGO_TARGET_DIR)"; \
	mkdir -p "$$bin_root" "$$corpus_root" "$$corpus_root/lib" "$$target_dir"; \
	container_platform="$(ACTIVE_CONTAINER_PLATFORM)"; \
	container_image="$(ACTIVE_RUNNER_BUILD_IMAGE)"; \
	target_triple="$(ACTIVE_SCX_TARGET_TRIPLE)"; \
	target_release_dir="$$target_dir/$$target_triple/release"; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		$(ACTIVE_CARGO_TARGET_LINKER_ENV) -e HOME=/tmp/bpf-benchmark-container \
		-e BPF_CLANG=clang \
		-e CARGO_TARGET_DIR="$$target_dir" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
		cargo build --release --target "$$target_triple" --manifest-path "$$repo_root/Cargo.toml" --package "$$package"; \
	test -x "$$target_release_dir/$$package"; \
	object_path="$$(find "$$target_release_dir/build" -path "*/$$package-*/out/main.bpf.o" | sort | tail -n1)"; \
	install -m 0755 "$$target_release_dir/$$package" "$@"; \
	test -n "$$object_path"; \
	obj_dst="$$corpus_root/$${package}_main.bpf.o"; \
	ln -f "$$object_path" "$$obj_dst"

$(REPO_SCX_ROOT)/%_main.bpf.o: $(REPO_SCX_ROOT)/bin/%
	@test -f "$@"

$(ACTIVE_BCC_REQUIRED) &: $(BCC_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_TAR)
	@repo_src="$(REPOS_DIR)/bcc"; \
	$(ENSURE_ACTIVE_RUNNER_BUILD_IMAGE); \
	build_root="$(BCC_BUILD_ROOT)"; \
	build_repo="$(BCC_BUILD_REPO)"; \
	repo_root="$$build_repo/libbpf-tools"; \
	artifact_root="$(REPO_BCC_ROOT)"; \
	build_output_root="$(BCC_BUILD_OUTPUT_ROOT)"; \
	mkdir -p "$$build_root" "$$artifact_root" "$$build_output_root"; \
	rsync -a --delete --delete-excluded \
		--filter='P libbpf-tools/.output/' \
		--exclude '.git' \
		--exclude 'libbpf-tools/.output/' \
		$(foreach tool,$(ACTIVE_BCC_TOOLS),--exclude 'libbpf-tools/$(tool)') \
		"$$repo_src/" "$$build_repo/"; \
	container_platform="$(ACTIVE_CONTAINER_PLATFORM)"; \
	container_image="$(ACTIVE_RUNNER_BUILD_IMAGE)"; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
		make -C "$$repo_root" -j"$(JOBS)" \
			OUTPUT="$$build_output_root" \
			LIBBPF_SRC="$(ROOT_DIR)/vendor/libbpf/src" \
			BPFTOOL=bpftool \
			USE_BLAZESYM=0 \
			$(ACTIVE_BCC_ARCH_ARG) \
			$(ACTIVE_BCC_TOOLS); \
	for tool in $(ACTIVE_BCC_TOOLS); do \
		test -x "$$repo_root/$$tool" || { echo "missing bcc tool build output: $$repo_root/$$tool" >&2; exit 1; }; \
		test -f "$$build_output_root/$$tool.bpf.o" || { echo "missing bcc BPF object: $$build_output_root/$$tool.bpf.o" >&2; exit 1; }; \
		install -m 0755 "$$repo_root/$$tool" "$$artifact_root/$$tool"; \
		ln -f "$$build_output_root/$$tool.bpf.o" "$$artifact_root/$$tool.bpf.o"; \
	done; \
	for path in $(ACTIVE_BCC_REQUIRED); do \
		test -e "$$path"; \
	done; \
	touch $(ACTIVE_BCC_REQUIRED)

$(ACTIVE_BPFTRACE_REQUIRED): $(BPFTRACE_SOURCE_FILES) $(ACTIVE_BPFTRACE_STATIC_BUILD_IMAGE_TAR)
	@$(ENSURE_ACTIVE_BPFTRACE_STATIC_BUILD_IMAGE); \
	build_root="$(BPFTRACE_BUILD_ROOT)"; \
	repo_root="$(REPOS_DIR)/bpftrace"; \
	artifact_root="$(REPO_BPFTRACE_ROOT)"; \
	mkdir -p "$$build_root" "$$artifact_root"; \
	container_platform="$(ACTIVE_CONTAINER_PLATFORM)"; \
	container_image="$(ACTIVE_BPFTRACE_STATIC_BUILD_IMAGE)"; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
		cmake -S "$$repo_root" -B "$$build_root/build" \
			-DCMAKE_BUILD_TYPE=Release \
			-DCMAKE_INSTALL_PREFIX="$$artifact_root" \
			-DSTATIC_LINKING=ON \
			-DBUILD_TESTING=OFF \
			-DENABLE_MAN=OFF \
			-DENABLE_SKB_OUTPUT=OFF \
			-DUSE_SYSTEM_LIBBPF=ON \
			-DLLVM_DIR=/usr/lib/cmake/llvm18 \
			-DClang_DIR=/usr/lib/cmake/clang18 \
			-DCMAKE_EXE_LINKER_FLAGS=-static \
			-DCMAKE_DISABLE_FIND_PACKAGE_LibBfd=TRUE \
			-DCMAKE_DISABLE_FIND_PACKAGE_LibOpcodes=TRUE; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
		cmake --build "$$build_root/build" --target install -j"$(JOBS)"; \
	test -x "$@"; \
	touch "$@"

$(ACTIVE_TRACEE_REQUIRED) &: $(TRACEE_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_TAR)
	@repo_src="$(REPOS_DIR)/tracee"; \
	$(ENSURE_ACTIVE_RUNNER_BUILD_IMAGE); \
	build_root="$(TRACEE_BUILD_ROOT)"; \
	repo_root="$(TRACEE_BUILD_REPO)"; \
	dist_root="$(TRACEE_BUILD_DIST_ROOT)"; \
	output_root="$(REPO_TRACEE_ROOT)"; \
	mkdir -p "$$build_root" "$$output_root/bin" "$$output_root/lsm_support"; \
		rsync -a --delete --delete-excluded \
			--filter='P dist/' \
			--filter='P build/' \
			--exclude '.git' \
			--exclude 'dist/' \
			--exclude 'build/' \
			"$$repo_src/" "$$repo_root/"; \
		rm -rf "$$dist_root/libbpf"; \
		rm -f "$$repo_root/.build_libbpf" "$$repo_root/.build_libbpf_fix" "$$repo_root/.eval_goenv" "$$repo_root/.checklib_libbpf" "$$repo_root/goenv.mk"; \
		container_platform="$(ACTIVE_CONTAINER_PLATFORM)"; \
		container_image="$(ACTIVE_RUNNER_BUILD_IMAGE)"; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e GOCACHE="$$build_root/go-build" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
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
	for path in $(ACTIVE_TRACEE_REQUIRED); do \
		test -e "$$path"; \
	done; \
	touch $(ACTIVE_TRACEE_REQUIRED)

$(ACTIVE_TETRAGON_REQUIRED) &: $(TETRAGON_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_TAR)
	@repo_src="$(REPOS_DIR)/tetragon"; \
	$(ENSURE_ACTIVE_RUNNER_BUILD_IMAGE); \
	build_root="$(TETRAGON_BUILD_ROOT)"; \
	repo_root="$(TETRAGON_BUILD_REPO)"; \
	bpf_output_root="$(TETRAGON_BUILD_BPF_ROOT)"; \
	artifact_root="$(REPO_TETRAGON_ROOT)"; \
	target_arch="$(ACTIVE_TETRAGON_TARGET_ARCH)"; \
	goarch="$$target_arch"; \
	version="$$(git -C "$$repo_src" describe --tags --always --exclude '*/*' 2>/dev/null || printf '%s' unknown)"; \
	mkdir -p "$$build_root" "$$artifact_root/bin" "$$bpf_output_root"; \
	rsync -a --delete --exclude '.git' --exclude 'build' --exclude 'bpf/objs' "$$repo_src/" "$$repo_root/"; \
	container_platform="$(ACTIVE_CONTAINER_PLATFORM)"; \
	container_image="$(ACTIVE_RUNNER_BUILD_IMAGE)"; \
	if [ -L "$$repo_root/bpf/objs" ] || [ ! -e "$$repo_root/bpf/objs" ]; then \
		ln -sfn "$$bpf_output_root" "$$repo_root/bpf/objs"; \
	else \
		echo "unexpected tetragon bpf/objs directory exists: $$repo_root/bpf/objs" >&2; \
		exit 1; \
	fi; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e GOCACHE="$$build_root/go-build" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
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
	for path in $(ACTIVE_TETRAGON_REQUIRED); do \
		test -e "$$path"; \
	done; \
	touch $(ACTIVE_TETRAGON_REQUIRED)

$(ACTIVE_KATRAN_REQUIRED) &: $(KATRAN_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_TAR)
	@repo_src="$(REPOS_DIR)/katran"; \
	$(ENSURE_ACTIVE_RUNNER_BUILD_IMAGE); \
	build_root="$(KATRAN_BUILD_ROOT)"; \
	repo_root="$(KATRAN_BUILD_REPO)"; \
	install_root="$(KATRAN_INSTALL_ROOT)"; \
	artifact_root="$(REPO_KATRAN_ROOT)"; \
	override_file="$(KATRAN_CMAKE_OVERRIDE)"; \
	bpf_root="$$artifact_root/bpf"; \
	container_platform="$(ACTIVE_CONTAINER_PLATFORM)"; \
	container_image="$(ACTIVE_RUNNER_BUILD_IMAGE)"; \
	mkdir -p "$$repo_root" "$$install_root/bin" "$$install_root/lib" "$$install_root/lib64" "$$bpf_root" "$$build_root"; \
	rsync -a --delete --delete-excluded \
		--exclude '.git' \
		--exclude '_build' \
		--exclude 'deps' \
		"$$repo_src/" "$$repo_root/"; \
	printf '%s\n' 'set(CMAKE_CXX_COMPILE_OBJECT "<CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -std=gnu++20 -o <OBJECT> -c <SOURCE>")' > "$$override_file"; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$$repo_root" \
		"$$container_image" \
		env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR \
			CC=gcc CXX=g++ AR=ar RANLIB=ranlib \
			KATRAN_SKIP_SYSTEM_PACKAGES=1 BUILD_EXAMPLE_GRPC=1 BUILD_DIR="$$build_root" INSTALL_DIR="$$install_root" INSTALL_DEPS_ONLY=1 ./build_katran.sh; \
	for cmake_file in "$$install_root"/lib/cmake/folly/folly-targets*.cmake "$$install_root"/lib64/cmake/folly/folly-targets*.cmake; do \
		[ -f "$$cmake_file" ] || continue; \
		sed -i \
			-e 's#gflags_nothreads_static#/usr/lib64/libgflags.so#g' \
			-e 's#gflags_static#/usr/lib64/libgflags.so#g' \
			"$$cmake_file"; \
	done; \
	mkdir -p "$$install_root/grpc/_build"; \
	ln -sfn "$$install_root/bin/grpc_cpp_plugin" "$$install_root/grpc/_build/grpc_cpp_plugin"; \
	rm -rf "$$build_root/build"; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
		env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR CMAKE_BUILD_EXAMPLE_GRPC=1 \
			CC=gcc CXX=g++ AR=ar RANLIB=ranlib \
			cmake -S "$$repo_root" -B "$$build_root/build" \
				-DCMAKE_PREFIX_PATH="$$install_root" \
				-DCMAKE_INSTALL_PREFIX="$$install_root" \
				-DCMAKE_BUILD_TYPE=RelWithDebInfo \
				-DPKG_CONFIG_USE_CMAKE_PREFIX_PATH=ON \
				-DLIB_BPF_PREFIX="$$install_root" \
				-DLIBELF=/usr/lib64/libelf.so \
				-DGLOG_LIBRARY=/usr/lib64/libglog.so \
				-DGLOG_INCLUDE_DIR=/usr/include \
				-Dgflags_DIR=/usr/lib64/cmake/gflags \
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
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
		cmake --build "$$build_root/build" --target install -j"$(JOBS)"; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$$repo_root" \
		"$$container_image" \
		./build_bpf_modules_opensource.sh -s "$$repo_root" -b "$$build_root" -o "$$bpf_root"; \
	test -x "$$install_root/bin/katran_server_grpc" || { echo "missing Katran install output: $$install_root/bin/katran_server_grpc" >&2; exit 1; }; \
	[ -f "$$bpf_root/healthchecking_ipip.o" ] && mv -f "$$bpf_root/healthchecking_ipip.o" "$$bpf_root/healthchecking_ipip.bpf.o" || true; \
	for path in $(ACTIVE_KATRAN_REQUIRED); do \
		test -e "$$path"; \
	done; \
	touch $(ACTIVE_KATRAN_REQUIRED)

WORKLOAD_TOOLS_SOURCE_ROOT := $(REPOS_DIR)/workload-tools
WORKLOAD_TOOLS_BUILD_ROOT := $(ARTIFACT_ROOT)/workload-tools-build/$(RUN_TARGET_ARCH)$(BUILD_ARCH_VARIANT)

$(ACTIVE_WORKLOAD_TOOLS_REQUIRED) &: $(WORKLOAD_TOOLS_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_TAR)
	@container_platform="$(ACTIVE_CONTAINER_PLATFORM)"; \
	$(ENSURE_ACTIVE_RUNNER_BUILD_IMAGE); \
	container_image="$(ACTIVE_RUNNER_BUILD_IMAGE)"; \
	build_root="$(WORKLOAD_TOOLS_BUILD_ROOT)"; \
	install_root="$(ACTIVE_WORKLOAD_TOOLS_INSTALL_ROOT)"; \
	source_root="$(WORKLOAD_TOOLS_SOURCE_ROOT)"; \
	work_root="$$build_root/src"; \
	rt_tests_src="$$work_root/rt-tests"; \
	sysbench_src="$$work_root/sysbench"; \
	wrk_src="$$work_root/wrk"; \
	wrk_luajit_root="$$build_root/wrk-luajit"; \
	bin_root="$$install_root/bin"; \
	lib_root="$$install_root/lib"; \
	test -d "$$source_root/rt-tests" || { echo "missing workload tool source root: $$source_root/rt-tests" >&2; exit 1; }; \
	test -d "$$source_root/sysbench" || { echo "missing workload tool source root: $$source_root/sysbench" >&2; exit 1; }; \
	test -d "$$source_root/wrk" || { echo "missing workload tool source root: $$source_root/wrk" >&2; exit 1; }; \
	mkdir -p "$$work_root" "$$wrk_luajit_root" "$$bin_root" "$$lib_root"; \
	rsync -a --delete \
		--exclude '.git' \
		--exclude 'autom4te.cache' \
		--exclude 'sysbench/third_party/luajit/bin' \
		--exclude 'sysbench/third_party/luajit/inc' \
		--exclude 'sysbench/third_party/luajit/lib' \
		--exclude 'sysbench/third_party/luajit/share' \
		--exclude 'sysbench/third_party/luajit/tmp' \
		"$$source_root/" "$$work_root/"; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
		make -C "$$rt_tests_src" -j"$(JOBS)" CC=gcc hackbench; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$$sysbench_src" \
		"$$container_image" \
		./configure --prefix="$$install_root" --without-mysql --without-pgsql; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$$sysbench_src" \
		"$$container_image" \
		make -j"$(JOBS)"; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$$sysbench_src" \
		"$$container_image" \
		make install; \
	ln -sfn "$$sysbench_src/third_party/luajit/inc" "$$wrk_luajit_root/include"; \
	ln -sfn "$$sysbench_src/third_party/luajit/lib" "$$wrk_luajit_root/lib"; \
	ln -sfn "$$sysbench_src/third_party/luajit/lib" "$$lib_root/luajit"; \
	luajit_bin="$$(find "$$sysbench_src/third_party/luajit/bin" -maxdepth 1 -type f -perm -111 -name 'luajit-*' | sort | head -n 1)"; \
	test -n "$$luajit_bin" || { echo "missing $(RUN_TARGET_ARCH) LuaJIT build output for wrk" >&2; exit 1; }; \
	ln -sfn "$$(basename "$$luajit_bin")" "$$sysbench_src/third_party/luajit/bin/luajit"; \
	mkdir -p "$$wrk_src/obj"; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e PATH="$$sysbench_src/third_party/luajit/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
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
	for path in $(ACTIVE_WORKLOAD_TOOLS_REQUIRED); do \
		test -x "$$path"; \
	done
