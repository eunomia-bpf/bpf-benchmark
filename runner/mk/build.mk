REPOS_DIR := $(RUNNER_DIR)/repos
RUNNER_CONTAINER_DIR := $(RUNNER_DIR)/containers
CONTAINER_RUNTIME ?= docker
HOST_UID := $(shell id -u)
HOST_GID := $(shell id -g)
DOCKERIGNORE_FILE := $(ROOT_DIR)/.dockerignore
REPO_ARTIFACT_ROOT := $(ROOT_DIR)/.cache/repo-artifacts/$(RUN_TARGET_ARCH)
REPO_SCX_ROOT := $(REPO_ARTIFACT_ROOT)/scx
REPO_BCC_ROOT := $(REPO_ARTIFACT_ROOT)/bcc/libbpf-tools/.output
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
BCC_RUNTIME_LIB_ROOT := $(REPO_ARTIFACT_ROOT)/bcc/libbpf-tools/lib
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
RUNNER_BUILD_DIR_ACTIVE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(RUNNER_DIR)/build-arm64,$(RUNNER_DIR)/build)
RUNNER_LIBBPF_BUILD_DIR := $(RUNNER_BUILD_DIR_ACTIVE)/vendor/libbpf
RUNNER_LIBBPF_OBJDIR := $(RUNNER_LIBBPF_BUILD_DIR)/obj
RUNNER_LIBBPF_PREFIX := $(RUNNER_LIBBPF_BUILD_DIR)/prefix
RUNNER_LIBBPF_A := $(RUNNER_LIBBPF_OBJDIR)/libbpf.a
CONTAINER_IMAGE_STATE_ROOT := $(ARTIFACT_ROOT)/container-images
KATRAN_BUILD_ROOT := $(REPO_BUILD_ROOT)/katran
KATRAN_BUILD_REPO := $(KATRAN_BUILD_ROOT)/src
KATRAN_INSTALL_ROOT := $(KATRAN_BUILD_ROOT)/install
KATRAN_CMAKE_OVERRIDE := $(KATRAN_BUILD_ROOT)/cxx-override.cmake
ACTIVE_WORKLOAD_TOOLS_INSTALL_ROOT := $(ARTIFACT_ROOT)/workload-tools/$(RUN_TARGET_ARCH)
ACTIVE_WORKLOAD_TOOLS_BIN_ROOT := $(ACTIVE_WORKLOAD_TOOLS_INSTALL_ROOT)/bin
ACTIVE_DAEMON_BINARY := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(DAEMON_DIR)/target/aarch64-unknown-linux-gnu/release/bpfrejit-daemon,$(DAEMON_DIR)/target/release/bpfrejit-daemon)
ACTIVE_RUNNER_BINARY := $(RUNNER_BUILD_DIR_ACTIVE)/micro_exec
ACTIVE_TEST_UNITTEST_BUILD_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/tests/unittest/build-arm64,$(ROOT_DIR)/tests/unittest/build)
ACTIVE_TEST_NEGATIVE_BUILD_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/tests/negative/build-arm64,$(ROOT_DIR)/tests/negative/build)
ACTIVE_TEST_UNITTEST_PRIMARY := $(ACTIVE_TEST_UNITTEST_BUILD_DIR)/rejit_regression
ACTIVE_TEST_NEGATIVE_PRIMARY := $(ACTIVE_TEST_NEGATIVE_BUILD_DIR)/scx_prog_show_race
ACTIVE_MICRO_PROGRAM_PRIMARY := $(MICRO_PROGRAM_OUTPUT_ROOT)/simple.bpf.o
RUNNER_BUILD_CONTAINERFILE := $(RUNNER_CONTAINER_DIR)/runner-build.Dockerfile
X86_RUNNER_BUILD_CONTAINERFILE := $(RUNNER_BUILD_CONTAINERFILE)
ARM64_RUNNER_BUILD_CONTAINERFILE := $(RUNNER_BUILD_CONTAINERFILE)
X86_RUNNER_BUILD_IMAGE := bpf-benchmark/runner-build:x86_64
ARM64_RUNNER_BUILD_IMAGE := bpf-benchmark/runner-build:arm64
X86_RUNNER_BUILD_IMAGE_STATE := $(CONTAINER_IMAGE_STATE_ROOT)/x86_64-runner-build.image-id
ARM64_RUNNER_BUILD_IMAGE_STATE := $(CONTAINER_IMAGE_STATE_ROOT)/arm64-runner-build.image-id
ACTIVE_CONTAINER_PLATFORM := $(if $(filter arm64,$(RUN_TARGET_ARCH)),linux/arm64,linux/amd64)
ACTIVE_RUNNER_BUILD_IMAGE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_RUNNER_BUILD_IMAGE),$(X86_RUNNER_BUILD_IMAGE))
ACTIVE_RUNNER_BUILD_IMAGE_STATE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_RUNNER_BUILD_IMAGE_STATE),$(X86_RUNNER_BUILD_IMAGE_STATE))
ACTIVE_KINSN_MODULE_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/module/arm64,$(ROOT_DIR)/module/x86)
ACTIVE_KINSN_PRIMARY := $(ACTIVE_KINSN_MODULE_DIR)/bpf_rotate.ko
ACTIVE_KINSN_SECONDARIES := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ACTIVE_KINSN_MODULE_DIR)/bpf_select.ko $(ACTIVE_KINSN_MODULE_DIR)/bpf_extract.ko $(ACTIVE_KINSN_MODULE_DIR)/bpf_endian.ko $(ACTIVE_KINSN_MODULE_DIR)/bpf_ldp.ko $(ACTIVE_KINSN_MODULE_DIR)/bpf_bulk_memory.ko,$(ACTIVE_KINSN_MODULE_DIR)/bpf_select.ko $(ACTIVE_KINSN_MODULE_DIR)/bpf_extract.ko $(ACTIVE_KINSN_MODULE_DIR)/bpf_endian.ko $(ACTIVE_KINSN_MODULE_DIR)/bpf_bulk_memory.ko)
ACTIVE_LIBBPF_RUNTIME_PRIMARY := $(REPO_ARTIFACT_ROOT)/libbpf/lib/libbpf.so
ACTIVE_BCC_TOOLS := capable execsnoop bindsnoop biosnoop vfsstat opensnoop syscount tcpconnect tcplife runqlat
ACTIVE_BCC_REQUIRED := $(addprefix $(REPO_BCC_ROOT)/,$(ACTIVE_BCC_TOOLS)) $(addsuffix .bpf.o,$(addprefix $(REPO_BCC_ROOT)/,$(ACTIVE_BCC_TOOLS)))
ACTIVE_TRACEE_REQUIRED := $(REPO_TRACEE_ROOT)/bin/tracee $(REPO_TRACEE_ROOT)/tracee.bpf.o $(REPO_TRACEE_ROOT)/lsm_support/kprobe_check.bpf.o $(REPO_TRACEE_ROOT)/lsm_support/lsm_check.bpf.o
ACTIVE_TETRAGON_REQUIRED := $(REPO_TETRAGON_ROOT)/bin/tetragon $(REPO_TETRAGON_ROOT)/bpf_execve_event.o $(REPO_TETRAGON_ROOT)/bpf_generic_kprobe.o
ACTIVE_KATRAN_REQUIRED := $(REPO_KATRAN_ROOT)/bin/katran_server_grpc $(REPO_KATRAN_ROOT)/bpf/balancer.bpf.o $(REPO_KATRAN_ROOT)/bpf/healthchecking_ipip.bpf.o
ACTIVE_WORKLOAD_TOOLS_REQUIRED := $(ACTIVE_WORKLOAD_TOOLS_BIN_ROOT)/hackbench $(ACTIVE_WORKLOAD_TOOLS_BIN_ROOT)/sysbench $(ACTIVE_WORKLOAD_TOOLS_BIN_ROOT)/wrk
DAEMON_SOURCE_FILES = $(shell find "$(ROOT_DIR)/daemon/src" -type f 2>/dev/null) $(ROOT_DIR)/daemon/Cargo.toml $(ROOT_DIR)/daemon/Cargo.lock $(ROOT_DIR)/daemon/Makefile
RUNNER_SOURCE_FILES = $(shell find "$(RUNNER_DIR)/src" "$(RUNNER_DIR)/include" -type f 2>/dev/null) $(RUNNER_DIR)/CMakeLists.txt
TEST_UNITTEST_SOURCE_FILES = $(shell find "$(ROOT_DIR)/tests/unittest" \( -path '*/build' -o -path '*/build-arm64' \) -prune -o -type f -print 2>/dev/null)
TEST_NEGATIVE_SOURCE_FILES = $(shell find "$(ROOT_DIR)/tests/negative" \( -path '*/build' -o -path '*/build-arm64' \) -prune -o -type f -print 2>/dev/null)
MICRO_PROGRAM_SOURCE_FILES = $(MICRO_PROGRAM_SRCS) $(shell find "$(MICRO_PROGRAM_SOURCE_ROOT)" -maxdepth 1 -type f \( -name '*.h' -o -name 'Makefile' \) -print 2>/dev/null)
KINSN_SOURCE_FILES = $(shell find "$(ACTIVE_KINSN_MODULE_DIR)" "$(ROOT_DIR)/module/include" -type f \( -name '*.c' -o -name '*.h' -o -name 'Makefile' \) -print 2>/dev/null)
SCX_SOURCE_FILES = $(shell find "$(REPOS_DIR)/scx" \( -path '*/target' -o -path '*/.git' \) -prune -o -type f \( -name '*.rs' -o -name '*.c' -o -name '*.h' -o -name 'Cargo.toml' -o -name 'Cargo.lock' -o -name 'build.rs' \) -print 2>/dev/null)
BCC_SOURCE_FILES = $(shell find "$(REPOS_DIR)/bcc/libbpf-tools" \( -path '*/.output' -o -path '*/.git' \) -prune -o -type f \( -name '*.c' -o -name '*.h' -o -name '*.sh' -o -name '*.mk' -o -name '*.yaml' -o -name '*.json' -o -name '*.txt' -o -name 'Makefile' \) -print 2>/dev/null)
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
$(TRACEE_SOURCE_FILES) \
$(TETRAGON_SOURCE_FILES) \
$(KATRAN_SOURCE_FILES) \
$(WORKLOAD_TOOLS_SOURCE_FILES) \
$(LIBBPF_SOURCE_FILES) \
$(KERNEL_BUILD_META_FILES) \
$(KERNEL_SOURCE_FILES): ;

$(RUNNER_LIBBPF_A): $(LIBBPF_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_STATE)
	@mkdir -p "$(RUNNER_LIBBPF_OBJDIR)" "$(RUNNER_LIBBPF_PREFIX)/include"
	$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		bash -eu -o pipefail -c ' \
			make -C "$(ROOT_DIR)/vendor/libbpf/src" -j"$(JOBS)" BUILD_STATIC_ONLY=1 \
				OBJDIR="$(RUNNER_LIBBPF_OBJDIR)" DESTDIR= PREFIX="$(RUNNER_LIBBPF_PREFIX)" \
				"$(RUNNER_LIBBPF_A)" install_headers; \
		'

$(X86_RUNNER_BUILD_IMAGE_STATE): $(X86_RUNNER_BUILD_CONTAINERFILE) $(DOCKERIGNORE_FILE)
	@mkdir -p "$(dir $@)"
	$(CONTAINER_RUNTIME) build --platform linux/amd64 -t "$(X86_RUNNER_BUILD_IMAGE)" -f "$(X86_RUNNER_BUILD_CONTAINERFILE)" "$(ROOT_DIR)"
	@$(CONTAINER_RUNTIME) image inspect --format '{{.Id}}' "$(X86_RUNNER_BUILD_IMAGE)" > "$@"

$(ARM64_RUNNER_BUILD_IMAGE_STATE): $(ARM64_RUNNER_BUILD_CONTAINERFILE) $(DOCKERIGNORE_FILE)
	@mkdir -p "$(dir $@)"
	$(CONTAINER_RUNTIME) build --platform linux/arm64 -t "$(ARM64_RUNNER_BUILD_IMAGE)" -f "$(ARM64_RUNNER_BUILD_CONTAINERFILE)" "$(ROOT_DIR)"
	@$(CONTAINER_RUNTIME) image inspect --format '{{.Id}}' "$(ARM64_RUNNER_BUILD_IMAGE)" > "$@"

$(X86_BUILD_DIR)/arch/x86/boot/bzImage: $(KERNEL_CONFIG_PATH) $(KERNEL_BUILD_META_FILES) $(KERNEL_SOURCE_FILES) $(X86_RUNNER_BUILD_IMAGE_STATE)
	@mkdir -p "$(X86_BUILD_DIR)"
	@$(CONTAINER_RUNTIME) run --rm --platform linux/amd64 \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e KERNEL_WORKTREE="$(KERNEL_DIR)" \
		-e KERNEL_BUILD_DIR="$(X86_BUILD_DIR)" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(X86_RUNNER_BUILD_IMAGE)" \
		bash -eu -o pipefail -c ' \
			make -C "$$KERNEL_WORKTREE" O="$$KERNEL_BUILD_DIR" olddefconfig; \
			make -C "$$KERNEL_WORKTREE" O="$$KERNEL_BUILD_DIR" -j"$(JOBS)" bzImage modules; \
		'

$(X86_BUILD_DIR)/include/linux/kconfig.h: $(X86_BUILD_DIR)/arch/x86/boot/bzImage $(KERNEL_DIR)/include/linux/kconfig.h
	@mkdir -p "$(X86_BUILD_DIR)/include"
	@ln -sfn "$(KERNEL_DIR)/include/linux" "$(X86_BUILD_DIR)/include/linux"
	@test -f "$@"

$(ACTIVE_DAEMON_BINARY): $(DAEMON_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_STATE)
	@mkdir -p "$(dir $@)"
	@target_triple=""; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		target_triple="aarch64-unknown-linux-gnu"; \
	fi; \
	$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e DAEMON_TARGET_DIR="$(DAEMON_DIR)/target" \
		-e DAEMON_TARGET_TRIPLE="$$target_triple" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		bash -eu -o pipefail -c ' \
			if [ -n "$$DAEMON_TARGET_TRIPLE" ]; then \
				make -C "$(ROOT_DIR)/daemon" release TARGET_DIR="$$DAEMON_TARGET_DIR" TARGET_TRIPLE="$$DAEMON_TARGET_TRIPLE"; \
			else \
				make -C "$(ROOT_DIR)/daemon" release TARGET_DIR="$$DAEMON_TARGET_DIR"; \
			fi; \
		'

$(ACTIVE_RUNNER_BINARY): $(RUNNER_LIBBPF_A) $(RUNNER_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_STATE)
	@mkdir -p "$(dir $@)"
	@if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		$(CONTAINER_RUNTIME) run --rm --platform linux/arm64 \
			--user "$(HOST_UID):$(HOST_GID)" \
			-e HOME=/tmp/bpf-benchmark-container \
			-v "$(ROOT_DIR):$(ROOT_DIR)" \
			-w "$(ROOT_DIR)" \
			"$(ARM64_RUNNER_BUILD_IMAGE)" \
			bash -eu -o pipefail -c ' \
				cmake_args='\''-S "$(RUNNER_DIR)" -B "$(RUNNER_BUILD_DIR_ACTIVE)" -DCMAKE_BUILD_TYPE=Release -DMICRO_REPO_ROOT="$(ROOT_DIR)" -DMICRO_LIBBPF_PREFIX="$(RUNNER_LIBBPF_PREFIX)" -DMICRO_LIBBPF_LIBRARY="$(RUNNER_LIBBPF_A)" -DMICRO_EXEC_ENABLE_LLVMBPF="$(RUN_SUITE_NEEDS_LLVMBPF)"'\''; \
				if [ -n "$(LLVM_DIR)" ]; then cmake_args="$$cmake_args -DLLVM_DIR=$(LLVM_DIR)"; fi; \
				eval cmake $$cmake_args; \
				cmake --build "$(RUNNER_BUILD_DIR_ACTIVE)" --target micro_exec -j"$(JOBS)"'; \
	else \
		$(CONTAINER_RUNTIME) run --rm --platform linux/amd64 \
			--user "$(HOST_UID):$(HOST_GID)" \
			-e HOME=/tmp/bpf-benchmark-container \
			-v "$(ROOT_DIR):$(ROOT_DIR)" \
			-w "$(ROOT_DIR)" \
			"$(X86_RUNNER_BUILD_IMAGE)" \
			bash -eu -o pipefail -c ' \
				cmake_args='\''-S "$(RUNNER_DIR)" -B "$(RUNNER_BUILD_DIR_ACTIVE)" -DCMAKE_BUILD_TYPE=Release -DMICRO_REPO_ROOT="$(ROOT_DIR)" -DMICRO_LIBBPF_PREFIX="$(RUNNER_LIBBPF_PREFIX)" -DMICRO_LIBBPF_LIBRARY="$(RUNNER_LIBBPF_A)" -DMICRO_EXEC_ENABLE_LLVMBPF="$(RUN_SUITE_NEEDS_LLVMBPF)"'\''; \
				if [ -n "$(LLVM_DIR)" ]; then cmake_args="$$cmake_args -DLLVM_DIR=$(LLVM_DIR)"; fi; \
				eval cmake $$cmake_args; \
				cmake --build "$(RUNNER_BUILD_DIR_ACTIVE)" --target micro_exec -j"$(JOBS)"'; \
	fi

$(ACTIVE_TEST_UNITTEST_PRIMARY): $(TEST_UNITTEST_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_STATE)
	@mkdir -p "$(ACTIVE_TEST_UNITTEST_BUILD_DIR)" "$(ACTIVE_TEST_UNITTEST_BUILD_DIR)/vendor/bpftool"
	@$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e TEST_BUILD_DIR="$(ACTIVE_TEST_UNITTEST_BUILD_DIR)" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		bash -eu -o pipefail -c ' \
			make -C "$(ROOT_DIR)/tests/unittest" BUILD_DIR="$$TEST_BUILD_DIR" CC=gcc CLANG=clang; \
		'

$(ACTIVE_TEST_NEGATIVE_PRIMARY): $(TEST_NEGATIVE_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_STATE)
	@mkdir -p "$(ACTIVE_TEST_NEGATIVE_BUILD_DIR)"
	@$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e TEST_BUILD_DIR="$(ACTIVE_TEST_NEGATIVE_BUILD_DIR)" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		bash -eu -o pipefail -c ' \
			make -C "$(ROOT_DIR)/tests/negative" BUILD_DIR="$$TEST_BUILD_DIR" CC=gcc; \
		'

$(MICRO_PROGRAM_OBJECTS) &: $(MICRO_PROGRAM_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_STATE)
	@mkdir -p "$(MICRO_PROGRAM_OUTPUT_ROOT)"
	@$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e MICRO_PROGRAM_OUTPUT_ROOT="$(MICRO_PROGRAM_OUTPUT_ROOT)" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		bash -eu -o pipefail -c ' \
			make -C "$(MICRO_PROGRAM_SOURCE_ROOT)" OUTPUT_DIR="$$MICRO_PROGRAM_OUTPUT_ROOT" all; \
		'; \
	for path in $(MICRO_PROGRAM_OBJECTS); do \
		test -f "$$path"; \
	done

$(ACTIVE_KINSN_PRIMARY): $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_AWS_BUILD_DIR)/arch/arm64/boot/Image,$(X86_BUILD_DIR)/arch/x86/boot/bzImage) $(KINSN_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_STATE)
	@module_dir="$(ACTIVE_KINSN_MODULE_DIR)"; \
	kernel_build_dir="$(X86_BUILD_DIR)"; \
	kernel_arch=""; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		kernel_build_dir="$(ARM64_AWS_BUILD_DIR)"; \
		kernel_arch="arm64"; \
	fi; \
	$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e KINSN_MODULE_DIR="$$module_dir" \
		-e KERNEL_BUILD_DIR="$$kernel_build_dir" \
		-e KERNEL_ARCH="$$kernel_arch" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		bash -eu -o pipefail -c ' \
			make_args=(-C "$(KERNEL_DIR)" O="$$KERNEL_BUILD_DIR" M="$$KINSN_MODULE_DIR" modules); \
			if [ -n "$$KERNEL_ARCH" ]; then make_args=(ARCH="$$KERNEL_ARCH" "$${make_args[@]}"); fi; \
			make "$${make_args[@]}"; \
		'

$(ACTIVE_KINSN_SECONDARIES): $(ACTIVE_KINSN_PRIMARY)
	@test -f "$@"

$(REPO_KERNEL_MODULES_ROOT)/lib/modules: $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_AWS_IMAGE) $(ARM64_AWS_BUILD_CONFIG),$(X86_BUILD_DIR)/arch/x86/boot/bzImage $(X86_BUILD_DIR)/include/linux/kconfig.h) $(ACTIVE_RUNNER_BUILD_IMAGE_STATE)
	@stage_root="$(REPO_KERNEL_MODULES_ROOT)"; \
	kernel_arch=""; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		build_dir="$(ARM64_AWS_BUILD_DIR)"; \
	else \
		build_dir="$(X86_BUILD_DIR)"; \
	fi; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		kernel_arch="arm64"; \
	fi; \
	kernel_release_file="$$build_dir/include/config/kernel.release"; \
	test -f "$$kernel_release_file" || { echo "missing kernel release file: $$kernel_release_file" >&2; exit 1; }; \
	kernel_release="$$(tr -d '\n' < "$$kernel_release_file")"; \
	release_root="$$stage_root/lib/modules/$$kernel_release"; \
	mkdir -p "$$stage_root"; \
	$(CONTAINER_RUNTIME) run --rm --platform "$(ACTIVE_CONTAINER_PLATFORM)" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e KERNEL_BUILD_DIR="$$build_dir" \
		-e KERNEL_STAGE_ROOT="$$stage_root" \
		-e KERNEL_RELEASE="$$kernel_release" \
		-e KERNEL_ARCH="$$kernel_arch" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ACTIVE_RUNNER_BUILD_IMAGE)" \
		bash -eu -o pipefail -c ' \
			make_args=(--no-print-directory -C "$(KERNEL_DIR)" O="$$KERNEL_BUILD_DIR" INSTALL_MOD_PATH="$$KERNEL_STAGE_ROOT" DEPMOD=true CONFIG_MODULE_SIG=n modules_install); \
			if [ -n "$$KERNEL_ARCH" ]; then make_args=(ARCH="$$KERNEL_ARCH" "$${make_args[@]}"); fi; \
			make "$${make_args[@]}" >/dev/null; \
			depmod -b "$$KERNEL_STAGE_ROOT" "$$KERNEL_RELEASE" >/dev/null; \
		'; \
	ln -sfn "$$build_dir" "$$release_root/build"; \
	ln -sfn "$(KERNEL_DIR)" "$$release_root/source"; \
	test -f "$$release_root/kernel/drivers/block/null_blk/null_blk.ko"; \
	test -f "$$release_root/kernel/net/sched/sch_netem.ko"

$(ACTIVE_LIBBPF_RUNTIME_PRIMARY): $(LIBBPF_SOURCE_FILES) $(BUILD_RULE_FILES) $(X86_RUNNER_BUILD_IMAGE_STATE)
	@runtime_root="$(REPO_ARTIFACT_ROOT)/libbpf"; \
	mkdir -p "$$runtime_root" "$(X86_LIBBPF_BUILD_ROOT)"; \
	$(CONTAINER_RUNTIME) run --rm --platform linux/amd64 \
		--user "$(HOST_UID):$(HOST_GID)" \
		-v "$(ROOT_DIR):/workspace:ro" \
		-v "$(X86_LIBBPF_BUILD_ROOT):/build" \
		-v "$$runtime_root:/out" \
		"$(X86_RUNNER_BUILD_IMAGE)" \
		bash -lc 'set -euo pipefail; \
			mkdir -p /build/obj /build/stage /out; \
			make -C /workspace/vendor/libbpf/src -j"$$(nproc)" OBJDIR=/build/obj DESTDIR=/build/stage prefix= install >/dev/null; \
			lib_dir=/build/stage/usr/lib64; \
			real_so="$$(find "$$lib_dir" -maxdepth 1 -type f -name "libbpf.so.*" | sort | tail -n1)"; \
			test -n "$$real_so"; \
			real_name="$$(basename "$$real_so")"; \
			mkdir -p /out/lib; \
			cp -L "$$real_so" "/out/lib/$$real_name"; \
			soname="$$(readelf -d "$$real_so" | sed -n "s/.*Library soname: \\[\\(.*\\)\\].*/\\1/p" | head -n1)"; \
			ln -sfn "$$real_name" /out/lib/libbpf.so; \
			if [[ -n "$$soname" && "$$soname" != "$$real_name" ]]; then ln -sfn "$$real_name" "/out/lib/$$soname"; fi'

$(REPO_SCX_ROOT)/bin/%: $(SCX_SOURCE_FILES) $(BUILD_RULE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_STATE)
	@package="$*"; \
	repo_root="$(REPOS_DIR)/scx"; \
	corpus_root="$(REPO_SCX_ROOT)"; \
	bin_root="$$corpus_root/bin"; \
	target_dir="$(SCX_CARGO_TARGET_DIR)"; \
	mkdir -p "$$bin_root" "$$corpus_root" "$$corpus_root/lib" "$$target_dir"; \
		container_platform="$(ACTIVE_CONTAINER_PLATFORM)"; \
		container_image="$(ACTIVE_RUNNER_BUILD_IMAGE)"; \
		if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
			target_triple="aarch64-unknown-linux-gnu"; \
		else \
			target_triple="x86_64-unknown-linux-gnu"; \
		fi; \
	target_release_dir="$$target_dir/$$target_triple/release"; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e SCX_PACKAGE="$$package" \
		-e SCX_MANIFEST_PATH="$$repo_root/Cargo.toml" \
		-e SCX_TARGET_DIR="$$target_dir" \
		-e SCX_TARGET_TRIPLE="$$target_triple" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
		bash -eu -o pipefail -c ' \
			export BPF_CLANG=clang; \
			export CARGO_TARGET_DIR="$$SCX_TARGET_DIR"; \
			cargo build --release --target "$$SCX_TARGET_TRIPLE" --manifest-path "$$SCX_MANIFEST_PATH" --package "$$SCX_PACKAGE"; \
		'; \
	test -x "$$target_release_dir/$$package"; \
	object_path="$$(find "$$target_release_dir/build" -path "*/$$package-*/out/main.bpf.o" | sort | tail -n1)"; \
	PORTABLE_WRAP_CONTAINER_PLATFORM="$$container_platform" PORTABLE_WRAP_CONTAINER_IMAGE="$$container_image" \
		$(call PORTABLE_WRAP_BINARY,$$target_release_dir/$$package,$@,$$corpus_root/lib); \
		test -n "$$object_path"; \
		obj_dst="$$corpus_root/$${package}_main.bpf.o"; \
		ln -f "$$object_path" "$$obj_dst"

$(REPO_SCX_ROOT)/%_main.bpf.o: $(REPO_SCX_ROOT)/bin/%
	@test -f "$@"

$(ACTIVE_BCC_REQUIRED) &: $(BCC_SOURCE_FILES) $(BUILD_RULE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_STATE)
	@repo_src="$(REPOS_DIR)/bcc"; \
	build_root="$(BCC_BUILD_ROOT)"; \
	build_repo="$(BCC_BUILD_REPO)"; \
	repo_root="$$build_repo/libbpf-tools"; \
	artifact_root="$(REPO_BCC_ROOT)"; \
	build_output_root="$(BCC_BUILD_OUTPUT_ROOT)"; \
	runtime_lib_root="$(BCC_RUNTIME_LIB_ROOT)"; \
	mkdir -p "$$build_root" "$$artifact_root" "$$runtime_lib_root" "$$build_output_root"; \
	rsync -a --delete --delete-excluded \
		--filter='P libbpf-tools/.output/' \
		--exclude '.git' \
		--exclude 'libbpf-tools/.output/' \
		$(foreach tool,$(ACTIVE_BCC_TOOLS),--exclude 'libbpf-tools/$(tool)') \
		"$$repo_src/" "$$build_repo/"; \
	container_platform="$(ACTIVE_CONTAINER_PLATFORM)"; \
	container_image="$(ACTIVE_RUNNER_BUILD_IMAGE)"; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		bcc_arch="arm64"; \
	else \
		bcc_arch="x86_64"; \
	fi; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e BCC_REPO_ROOT="$$repo_root" \
		-e BCC_BUILD_OUTPUT_ROOT="$$build_output_root" \
		-e BCC_LIBBPF_SRC="$(ROOT_DIR)/vendor/libbpf/src" \
		-e BCC_ARCH="$$bcc_arch" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
		bash -eu -o pipefail -c ' \
			make_args=(OUTPUT="$$BCC_BUILD_OUTPUT_ROOT" LIBBPF_SRC="$$BCC_LIBBPF_SRC" BPFTOOL=bpftool USE_BLAZESYM=0); \
			if [ "$$BCC_ARCH" = "arm64" ]; then make_args+=(ARCH=arm64); fi; \
			make -C "$$BCC_REPO_ROOT" -j"$(JOBS)" "$${make_args[@]}" $(ACTIVE_BCC_TOOLS); \
		'; \
	for tool in $(ACTIVE_BCC_TOOLS); do \
		test -x "$$repo_root/$$tool" || { echo "missing bcc tool build output: $$repo_root/$$tool" >&2; exit 1; }; \
		test -f "$$build_output_root/$$tool.bpf.o" || { echo "missing bcc BPF object: $$build_output_root/$$tool.bpf.o" >&2; exit 1; }; \
		PORTABLE_WRAP_CONTAINER_PLATFORM="$$container_platform" PORTABLE_WRAP_CONTAINER_IMAGE="$$container_image" \
			$(call PORTABLE_WRAP_BINARY,$$repo_root/$$tool,$$artifact_root/$$tool,$$runtime_lib_root); \
		ln -f "$$build_output_root/$$tool.bpf.o" "$$artifact_root/$$tool.bpf.o"; \
	done; \
	for path in $(ACTIVE_BCC_REQUIRED); do \
		test -e "$$path"; \
	done

$(ACTIVE_TRACEE_REQUIRED) &: $(TRACEE_SOURCE_FILES) $(BUILD_RULE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_STATE)
	@repo_src="$(REPOS_DIR)/tracee"; \
	build_root="$(TRACEE_BUILD_ROOT)"; \
	repo_root="$(TRACEE_BUILD_REPO)"; \
	dist_root="$(TRACEE_BUILD_DIST_ROOT)"; \
	output_root="$(REPO_TRACEE_ROOT)"; \
	mkdir -p "$$build_root" "$$output_root/bin" "$$output_root/lsm_support" "$$output_root/lib"; \
	rsync -a --delete --delete-excluded \
		--filter='P dist/' \
		--filter='P build/' \
		--exclude '.git' \
		--exclude 'dist/' \
		--exclude 'build/' \
		"$$repo_src/" "$$repo_root/"; \
	container_platform="$(ACTIVE_CONTAINER_PLATFORM)"; \
	container_image="$(ACTIVE_RUNNER_BUILD_IMAGE)"; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		tracee_uname_m="aarch64"; \
		tracee_arch="arm64"; \
		tracee_linux_arch="arm64"; \
		tracee_goarch="arm64"; \
	else \
		tracee_uname_m="x86_64"; \
		tracee_arch="x86_64"; \
		tracee_linux_arch="x86"; \
		tracee_goarch="amd64"; \
	fi; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e GOCACHE="$$build_root/go-build" \
		-e TRACEE_REPO_ROOT="$$repo_root" \
		-e TRACEE_OUTPUT_DIR="$$dist_root" \
		-e TRACEE_UNAME_M="$$tracee_uname_m" \
		-e TRACEE_ARCH="$$tracee_arch" \
		-e TRACEE_LINUX_ARCH="$$tracee_linux_arch" \
		-e TRACEE_GOARCH="$$tracee_goarch" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
		bash -eu -o pipefail -c ' \
			make -C "$$TRACEE_REPO_ROOT" -j"$(JOBS)" \
				OUTPUT_DIR="$$TRACEE_OUTPUT_DIR" \
				UNAME_M="$$TRACEE_UNAME_M" \
				ARCH="$$TRACEE_ARCH" \
				LINUX_ARCH="$$TRACEE_LINUX_ARCH" \
				GO_ARCH="$$TRACEE_GOARCH" \
				CMD_GCC=gcc \
				CMD_CLANG=clang \
				CMD_GO=go \
				CMD_STRIP=llvm-strip \
				CMD_OBJCOPY=llvm-objcopy \
				tracee; \
		'; \
	test -x "$$dist_root/tracee" || { echo "missing tracee build output: $$dist_root/tracee" >&2; exit 1; }; \
	PORTABLE_WRAP_CONTAINER_PLATFORM="$$container_platform" PORTABLE_WRAP_CONTAINER_IMAGE="$$container_image" \
		$(call PORTABLE_WRAP_BINARY,$$dist_root/tracee,$$output_root/bin/tracee,$$output_root/lib); \
	ln -f "$$dist_root/tracee.bpf.o" "$$output_root/tracee.bpf.o"; \
	ln -f "$$dist_root/lsm_support/kprobe_check.bpf.o" "$$output_root/lsm_support/kprobe_check.bpf.o"; \
	ln -f "$$dist_root/lsm_support/lsm_check.bpf.o" "$$output_root/lsm_support/lsm_check.bpf.o"; \
	for path in $(ACTIVE_TRACEE_REQUIRED); do \
		test -e "$$path"; \
	done

$(ACTIVE_TETRAGON_REQUIRED) &: $(TETRAGON_SOURCE_FILES) $(BUILD_RULE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_STATE)
	@repo_src="$(REPOS_DIR)/tetragon"; \
	build_root="$(TETRAGON_BUILD_ROOT)"; \
	repo_root="$(TETRAGON_BUILD_REPO)"; \
	bpf_output_root="$(TETRAGON_BUILD_BPF_ROOT)"; \
	artifact_root="$(REPO_TETRAGON_ROOT)"; \
	target_arch="$$( [ "$(RUN_TARGET_ARCH)" = "arm64" ] && printf 'arm64' || printf 'amd64' )"; \
	goarch="$$target_arch"; \
	version="$$(git -C "$$repo_src" describe --tags --always --exclude '*/*' 2>/dev/null || printf '%s' unknown)"; \
	mkdir -p "$$build_root" "$$artifact_root/bin" "$$bpf_output_root"; \
	rsync -a --delete --exclude '.git' --exclude 'build' --exclude 'bpf/objs' "$$repo_src/" "$$repo_root/"; \
	if [ -L "$$repo_root/bpf/objs" ] || [ ! -e "$$repo_root/bpf/objs" ]; then \
		ln -sfn "$$bpf_output_root" "$$repo_root/bpf/objs"; \
	else \
		echo "legacy tetragon bpf/objs directory exists: $$repo_root/bpf/objs; clean it explicitly once" >&2; \
		exit 1; \
	fi; \
	container_platform="$(ACTIVE_CONTAINER_PLATFORM)"; \
	container_image="$(ACTIVE_RUNNER_BUILD_IMAGE)"; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e GOCACHE="$$build_root/go-build" \
		-e TETRAGON_REPO_ROOT="$$repo_root" \
		-e TETRAGON_TARGET_ARCH="$$target_arch" \
		-e TETRAGON_GOARCH="$$goarch" \
		-e TETRAGON_VERSION="$$version" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
		bash -eu -o pipefail -c ' \
			make -C "$$TETRAGON_REPO_ROOT" -j"$(JOBS)" \
				TARGET_ARCH="$$TETRAGON_TARGET_ARCH" \
				GOARCH="$$TETRAGON_GOARCH" \
				VERSION="$$TETRAGON_VERSION" \
				LOCAL_CLANG=1 \
				tetragon-bpf tetragon; \
		'; \
	test -x "$$repo_root/tetragon" || { echo "missing tetragon build output: $$repo_root/tetragon" >&2; exit 1; }; \
	ln -f "$$repo_root/tetragon" "$$artifact_root/bin/tetragon"; \
	ln -f "$$bpf_output_root/bpf_execve_event.o" "$$artifact_root/bpf_execve_event.o"; \
	ln -f "$$bpf_output_root/bpf_generic_kprobe.o" "$$artifact_root/bpf_generic_kprobe.o"; \
	for path in $(ACTIVE_TETRAGON_REQUIRED); do \
		test -e "$$path"; \
	done

$(ACTIVE_KATRAN_REQUIRED) &: $(KATRAN_SOURCE_FILES) $(BUILD_RULE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_STATE)
	@repo_src="$(REPOS_DIR)/katran"; \
	build_root="$(KATRAN_BUILD_ROOT)"; \
	repo_root="$(KATRAN_BUILD_REPO)"; \
	install_root="$(KATRAN_INSTALL_ROOT)"; \
	artifact_root="$(REPO_KATRAN_ROOT)"; \
	artifact_bin_root="$$artifact_root/bin"; \
	artifact_lib_root="$$artifact_root/lib"; \
	override_file="$(KATRAN_CMAKE_OVERRIDE)"; \
	bpf_root="$$artifact_root/bpf"; \
	folly_xlog_prefixes="-DFOLLY_XLOG_STRIP_PREFIXES=\\\\\\\"$$build_root/deps/folly:$$build_root/deps/folly/build\\\\\\\""; \
	container_platform="$(ACTIVE_CONTAINER_PLATFORM)"; \
	container_image="$(ACTIVE_RUNNER_BUILD_IMAGE)"; \
	mkdir -p "$$repo_root" "$$install_root/bin" "$$install_root/lib" "$$install_root/lib64" "$$artifact_bin_root" "$$artifact_lib_root" "$$bpf_root" "$$build_root"; \
	rsync -a --delete --delete-excluded \
		--exclude '.git' \
		--exclude 'build' \
		--exclude '_build' \
		--exclude 'deps' \
		"$$repo_src/" "$$repo_root/"; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e HOME=/tmp/bpf-benchmark-container \
		-e KATRAN_REPO_ROOT="$$repo_root" \
		-e KATRAN_BUILD_ROOT="$$build_root" \
		-e KATRAN_INSTALL_ROOT="$$install_root" \
		-e KATRAN_OVERRIDE_FILE="$$override_file" \
		-e KATRAN_BPF_ROOT="$$bpf_root" \
		-e KATRAN_ARTIFACT_ROOT="$$artifact_root" \
		-e FOLLY_XLOG_PREFIXES="$$folly_xlog_prefixes" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
		bash -eu -o pipefail -c ' \
			mkdir -p "$$KATRAN_INSTALL_ROOT/bin" "$$KATRAN_INSTALL_ROOT/lib" "$$KATRAN_INSTALL_ROOT/lib64" "$$KATRAN_BPF_ROOT" "$$KATRAN_BUILD_ROOT"; \
			printf "%s\n" '\''set(CMAKE_CXX_COMPILE_OBJECT "<CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -std=gnu++20 -o <OBJECT> -c <SOURCE>")'\'' > "$$KATRAN_OVERRIDE_FILE"; \
			cd "$$KATRAN_REPO_ROOT"; \
				env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR \
					CC=gcc CXX=g++ AR=ar RANLIB=ranlib \
					CXXFLAGS="$$FOLLY_XLOG_PREFIXES" \
					KATRAN_SKIP_SYSTEM_PACKAGES=1 BUILD_EXAMPLE_GRPC=1 BUILD_DIR="$$KATRAN_BUILD_ROOT" INSTALL_DIR="$$KATRAN_INSTALL_ROOT" INSTALL_DEPS_ONLY=1 ./build_katran.sh; \
			mkdir -p "$$KATRAN_INSTALL_ROOT/grpc/_build"; \
			ln -sfn "$$KATRAN_INSTALL_ROOT/bin/grpc_cpp_plugin" "$$KATRAN_INSTALL_ROOT/grpc/_build/grpc_cpp_plugin"; \
			env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR CMAKE_BUILD_EXAMPLE_GRPC=1 \
				CC=gcc CXX=g++ AR=ar RANLIB=ranlib \
				cmake -S "$$KATRAN_REPO_ROOT" -B "$$KATRAN_BUILD_ROOT/build" \
					-DCMAKE_PREFIX_PATH="$$KATRAN_INSTALL_ROOT" \
					-DCMAKE_INSTALL_PREFIX="$$KATRAN_INSTALL_ROOT" \
					-DCMAKE_BUILD_TYPE=RelWithDebInfo \
					-DPKG_CONFIG_USE_CMAKE_PREFIX_PATH=ON \
					-DLIB_BPF_PREFIX="$$KATRAN_INSTALL_ROOT" \
					-DCMAKE_CXX_STANDARD=20 \
					-DCMAKE_C_COMPILER=gcc \
					-DCMAKE_CXX_COMPILER=g++ \
					-DCMAKE_AR=ar \
					-DCMAKE_RANLIB=ranlib \
					-DCMAKE_USER_MAKE_RULES_OVERRIDE_CXX="$$KATRAN_OVERRIDE_FILE" \
					-DBUILD_TESTS=OFF; \
			cmake --build "$$KATRAN_BUILD_ROOT/build" --target install -j"$(JOBS)"; \
			cd "$$KATRAN_REPO_ROOT" && ./build_bpf_modules_opensource.sh -s "$$KATRAN_REPO_ROOT" -b "$$KATRAN_BUILD_ROOT" -o "$$KATRAN_BPF_ROOT"; \
		'; \
	PORTABLE_WRAP_CONTAINER_PLATFORM="$$container_platform" PORTABLE_WRAP_CONTAINER_IMAGE="$$container_image" PORTABLE_WRAP_SEARCH_DIRS="$$install_root/lib64:$$install_root/lib:/usr/lib64:/lib64:/usr/lib:/lib" \
		$(call PORTABLE_WRAP_BINARY,$$install_root/bin/katran_server_grpc,$$artifact_bin_root/katran_server_grpc,$$artifact_lib_root); \
	[ -f "$$bpf_root/healthchecking_ipip.o" ] && mv -f "$$bpf_root/healthchecking_ipip.o" "$$bpf_root/healthchecking_ipip.bpf.o" || true; \
	for path in $(ACTIVE_KATRAN_REQUIRED); do \
		test -e "$$path"; \
	done

define PORTABLE_WRAP_BINARY
	runtime_input="$(1)"; \
	runtime_wrapper="$(2)"; \
	runtime_lib_dir="$(3)"; \
	mkdir -p "$$(dirname "$$runtime_wrapper")" "$$runtime_lib_dir"; \
	container_platform="$${PORTABLE_WRAP_CONTAINER_PLATFORM:-}"; \
	container_image="$${PORTABLE_WRAP_CONTAINER_IMAGE:-}"; \
	[ -n "$$container_platform" ] || { echo "PORTABLE_WRAP_CONTAINER_PLATFORM is required" >&2; exit 1; }; \
	[ -n "$$container_image" ] || { echo "PORTABLE_WRAP_CONTAINER_IMAGE is required" >&2; exit 1; }; \
	$(CONTAINER_RUNTIME) run --rm --platform "$$container_platform" \
		--user "$(HOST_UID):$(HOST_GID)" \
		-e PORTABLE_INPUT="$$runtime_input" \
		-e PORTABLE_WRAPPER="$$runtime_wrapper" \
		-e PORTABLE_LIB_DIR="$$runtime_lib_dir" \
		-e PORTABLE_SEARCH_DIRS="$${PORTABLE_WRAP_SEARCH_DIRS:-}" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
		bash -eu -o pipefail -c ' \
			runtime_input="$$PORTABLE_INPUT"; \
			runtime_wrapper="$$PORTABLE_WRAPPER"; \
			runtime_lib_dir="$$PORTABLE_LIB_DIR"; \
			cp -Lf "$$runtime_input" "$$runtime_wrapper.real"; \
			chmod +x "$$runtime_wrapper.real"; \
			loader_name=""; \
			seen_paths=""; \
			resolve_lib() { \
				name="$$1"; \
				for root in $$(printf "%s" "$${PORTABLE_SEARCH_DIRS:-}" | tr ":" " "); do \
					[ -n "$$root" ] || continue; \
					[ -e "$$root/$$name" ] || continue; \
					printf "%s\n" "$$root/$$name"; \
					return 0; \
				done; \
				if [ "$${name#/}" != "$$name" ] && [ -e "$$name" ]; then \
					printf "%s\n" "$$name"; \
					return 0; \
				fi; \
				resolved="$$(ldconfig -p 2>/dev/null | awk -v so="$$name" '\''$$1==so {print $$NF; exit}'\'')"; \
				[ -n "$$resolved" ] || return 1; \
				printf "%s\n" "$$resolved"; \
			}; \
			copy_binary_deps() { \
				current="$$(readlink -f "$$1")"; \
				[ -n "$$current" ] || return 0; \
				case " $$seen_paths " in \
					*" $$current "*) return 0 ;; \
				esac; \
				seen_paths="$$seen_paths $$current"; \
				interpreter="$$(readelf -l "$$current" | sed -n "s/.*Requesting program interpreter: \\(.*\\)]/\\1/p" | tr -d "[]" | head -n1)"; \
				if [ -n "$$interpreter" ] && [ -z "$$loader_name" ]; then \
					loader_path="$$(resolve_lib "$$interpreter")" || { echo "missing runtime loader: $$interpreter" >&2; exit 1; }; \
					loader_real="$$(readlink -f "$$loader_path")"; \
					loader_name="$$(basename "$$loader_real")"; \
					loader_dest="$$(readlink -f "$$runtime_lib_dir/$$loader_name" 2>/dev/null || true)"; \
					if [ "$$loader_real" != "$$loader_dest" ]; then \
						cp -Lf "$$loader_real" "$$runtime_lib_dir/$$loader_name"; \
					fi; \
				fi; \
				deps_file="$$(mktemp)"; \
				readelf -d "$$current" | sed -n "s/.*Shared library: \\[\\(.*\\)\\].*/\\1/p" > "$$deps_file"; \
				while IFS= read -r soname; do \
					[ -n "$$soname" ] || continue; \
					resolved="$$(resolve_lib "$$soname")" || { echo "missing runtime dependency: $$soname" >&2; exit 1; }; \
					resolved_real="$$(readlink -f "$$resolved")"; \
					resolved_name="$$(basename "$$resolved_real")"; \
					resolved_dest="$$(readlink -f "$$runtime_lib_dir/$$resolved_name" 2>/dev/null || true)"; \
					if [ "$$resolved_real" != "$$resolved_dest" ]; then \
						cp -Lf "$$resolved_real" "$$runtime_lib_dir/$$resolved_name"; \
					fi; \
					if [ "$$soname" != "$$resolved_name" ]; then \
						ln -sfn "$$resolved_name" "$$runtime_lib_dir/$$soname"; \
					fi; \
					soname_value="$$(readelf -d "$$resolved_real" | sed -n "s/.*Library soname: \\[\\(.*\\)\\].*/\\1/p" | head -n1)"; \
					if [ -n "$$soname_value" ] && [ "$$soname_value" != "$$resolved_name" ]; then \
						ln -sfn "$$resolved_name" "$$runtime_lib_dir/$$soname_value"; \
					fi; \
					copy_binary_deps "$$resolved_real"; \
				done < "$$deps_file"; \
				rm -f "$$deps_file"; \
			}; \
			copy_binary_deps "$$runtime_wrapper.real"; \
			[ -n "$$loader_name" ] || { echo "missing bundled loader for $$runtime_wrapper.real" >&2; exit 1; }; \
			printf "%s\n" \
				"#!/usr/bin/env bash" \
				"set -euo pipefail" \
				"script_path=\"\$$(readlink -f \"\$$0\")\"" \
				"script_dir=\"\$$(cd \"\$$(dirname \"\$$script_path\")\" && pwd)\"" \
				"real_binary=\"\$$script_path.real\"" \
				"lib_dir=\"\$$script_dir/../lib\"" \
				"loader=\"\$$lib_dir/$$loader_name\"" \
				"[[ -x \"\$$loader\" ]] || { echo \"portable runtime loader not found: \$$loader\" >&2; exit 1; }" \
				"[[ -f \"\$$real_binary\" ]] || { echo \"wrapped binary is missing: \$$real_binary\" >&2; exit 1; }" \
				"exec \"\$$loader\" --library-path \"\$$lib_dir\" \"\$$real_binary\" \"\$$@\"" \
				> "$$runtime_wrapper"; \
			chmod +x "$$runtime_wrapper"; \
		'
endef

WORKLOAD_TOOLS_SOURCE_ROOT := $(REPOS_DIR)/workload-tools
WORKLOAD_TOOLS_BUILD_ROOT := $(ARTIFACT_ROOT)/workload-tools-build/$(RUN_TARGET_ARCH)$(BUILD_ARCH_VARIANT)
X86_LIBBPF_BUILD_ROOT := $(ARTIFACT_ROOT)/libbpf-build/x86_64/runtime

$(ACTIVE_WORKLOAD_TOOLS_REQUIRED) &: $(WORKLOAD_TOOLS_SOURCE_FILES) $(ACTIVE_RUNNER_BUILD_IMAGE_STATE)
	@container_platform="$(ACTIVE_CONTAINER_PLATFORM)"; \
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
		-e WORKLOAD_RT_TESTS_SRC="$$rt_tests_src" \
		-e WORKLOAD_SYSBENCH_SRC="$$sysbench_src" \
		-e WORKLOAD_WRK_SRC="$$wrk_src" \
		-e WORKLOAD_INSTALL_ROOT="$$install_root" \
		-e WORKLOAD_WRK_LUAJIT_ROOT="$$wrk_luajit_root" \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$$container_image" \
		bash -eu -o pipefail -c ' \
			make -C "$$WORKLOAD_RT_TESTS_SRC" -j"$(JOBS)" CC=gcc hackbench >/dev/null; \
			cd "$$WORKLOAD_SYSBENCH_SRC"; \
			test -x ./configure || ./autogen.sh >/dev/null; \
			./configure --prefix="$$WORKLOAD_INSTALL_ROOT" --without-mysql --without-pgsql >/dev/null; \
			make -j"$(JOBS)" >/dev/null; \
			make install >/dev/null; \
			ln -sfn "$$WORKLOAD_SYSBENCH_SRC/third_party/luajit/inc" "$$WORKLOAD_WRK_LUAJIT_ROOT/include"; \
			ln -sfn "$$WORKLOAD_SYSBENCH_SRC/third_party/luajit/lib" "$$WORKLOAD_WRK_LUAJIT_ROOT/lib"; \
			mkdir -p "$$WORKLOAD_WRK_SRC/obj"; \
			PATH="$$WORKLOAD_SYSBENCH_SRC/third_party/luajit/bin:$$PATH" make -C "$$WORKLOAD_WRK_SRC" -j"$(JOBS)" \
				CC=gcc \
				WITH_LUAJIT="$$WORKLOAD_WRK_LUAJIT_ROOT" \
				WITH_OPENSSL="/usr" >/dev/null; \
		'; \
	ln -sfn "$$sysbench_src/third_party/luajit/inc" "$$wrk_luajit_root/include"; \
	ln -sfn "$$sysbench_src/third_party/luajit/lib" "$$wrk_luajit_root/lib"; \
	test -x "$$wrk_src/wrk" || { echo "missing $(RUN_TARGET_ARCH) wrk build output: $$wrk_src/wrk" >&2; exit 1; }; \
	test -x "$$rt_tests_src/hackbench" || { echo "missing $(RUN_TARGET_ARCH) hackbench build output: $$rt_tests_src/hackbench" >&2; exit 1; }; \
	test -x "$$bin_root/sysbench" || { echo "missing $(RUN_TARGET_ARCH) sysbench install output: $$bin_root/sysbench" >&2; exit 1; }; \
	PORTABLE_WRAP_CONTAINER_PLATFORM="$$container_platform" PORTABLE_WRAP_CONTAINER_IMAGE="$$container_image" PORTABLE_WRAP_SEARCH_DIRS="$$wrk_luajit_root/lib:/usr/lib64:/lib64:/usr/lib:/lib" \
		$(call PORTABLE_WRAP_BINARY,$$rt_tests_src/hackbench,$$bin_root/hackbench,$$lib_root); \
	PORTABLE_WRAP_CONTAINER_PLATFORM="$$container_platform" PORTABLE_WRAP_CONTAINER_IMAGE="$$container_image" PORTABLE_WRAP_SEARCH_DIRS="$$wrk_luajit_root/lib:/usr/lib64:/lib64:/usr/lib:/lib" \
		$(call PORTABLE_WRAP_BINARY,$$bin_root/sysbench,$$bin_root/sysbench,$$lib_root); \
	PORTABLE_WRAP_CONTAINER_PLATFORM="$$container_platform" PORTABLE_WRAP_CONTAINER_IMAGE="$$container_image" PORTABLE_WRAP_SEARCH_DIRS="$$wrk_luajit_root/lib:/usr/lib64:/lib64:/usr/lib:/lib" \
		$(call PORTABLE_WRAP_BINARY,$$wrk_src/wrk,$$bin_root/wrk,$$lib_root); \
	for path in $(ACTIVE_WORKLOAD_TOOLS_REQUIRED); do \
		test -x "$$path"; \
	done
