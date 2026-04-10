REPOS_DIR := $(RUNNER_DIR)/repos
REPO_ARTIFACT_ROOT := $(ROOT_DIR)/.cache/repo-artifacts/$(RUN_TARGET_ARCH)
REPO_SCX_ROOT := $(REPO_ARTIFACT_ROOT)/scx
REPO_BCC_ROOT := $(REPO_ARTIFACT_ROOT)/bcc/libbpf-tools/.output
REPO_TRACEE_ROOT := $(REPO_ARTIFACT_ROOT)/tracee
REPO_TETRAGON_ROOT := $(REPO_ARTIFACT_ROOT)/tetragon
REPO_KATRAN_ROOT := $(REPO_ARTIFACT_ROOT)/katran
REPO_KERNEL_MODULES_ROOT := $(REPO_ARTIFACT_ROOT)/kernel-modules
X86_SYSROOT_VARIANT := rocky9
BUILD_ARCH_VARIANT := $(if $(filter x86_64,$(RUN_TARGET_ARCH)),-$(X86_SYSROOT_VARIANT),)
REPO_BUILD_ROOT := $(ARTIFACT_ROOT)/repo-build/$(RUN_TARGET_ARCH)$(BUILD_ARCH_VARIANT)
BUILD_RULE_FILES := $(ROOT_DIR)/Makefile $(RUNNER_DIR)/mk/build.mk $(RUNNER_DIR)/libs/workspace_layout.py
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
X86_TOOLCHAIN_ROOT := $(RUNNER_DIR)/build-x86/toolchain
X86_TOOLCHAIN_BIN := $(X86_TOOLCHAIN_ROOT)/usr/bin
X86_TOOLCHAIN_WRAPPER_ROOT := $(RUNNER_DIR)/build-x86/wrappers
X86_TOOLCHAIN_SUPPORT_LIB_ROOT := $(RUNNER_DIR)/build-x86/tool-libs
X86_GCC_BIN := $(X86_TOOLCHAIN_BIN)/gcc
X86_GXX_BIN := $(X86_TOOLCHAIN_BIN)/g++
X86_LD_BIN := $(X86_TOOLCHAIN_BIN)/ld
X86_AR_BIN := $(X86_TOOLCHAIN_BIN)/ar
X86_RANLIB_BIN := $(X86_TOOLCHAIN_BIN)/ranlib
X86_NM_BIN := $(X86_TOOLCHAIN_BIN)/nm
X86_OBJCOPY_BIN := $(X86_TOOLCHAIN_BIN)/objcopy
X86_OBJDUMP_BIN := $(X86_TOOLCHAIN_BIN)/objdump
X86_READELF_BIN := $(X86_TOOLCHAIN_BIN)/readelf
X86_STRIP_BIN := $(X86_TOOLCHAIN_BIN)/strip
X86_CC_WRAPPER := $(X86_TOOLCHAIN_WRAPPER_ROOT)/gcc
X86_CXX_WRAPPER := $(X86_TOOLCHAIN_WRAPPER_ROOT)/g++
X86_LD_WRAPPER := $(X86_TOOLCHAIN_WRAPPER_ROOT)/ld
X86_AR_WRAPPER := $(X86_TOOLCHAIN_WRAPPER_ROOT)/ar
X86_RANLIB_WRAPPER := $(X86_TOOLCHAIN_WRAPPER_ROOT)/ranlib
X86_NM_WRAPPER := $(X86_TOOLCHAIN_WRAPPER_ROOT)/nm
X86_OBJCOPY_WRAPPER := $(X86_TOOLCHAIN_WRAPPER_ROOT)/objcopy
X86_OBJDUMP_WRAPPER := $(X86_TOOLCHAIN_WRAPPER_ROOT)/objdump
X86_READELF_WRAPPER := $(X86_TOOLCHAIN_WRAPPER_ROOT)/readelf
X86_STRIP_WRAPPER := $(X86_TOOLCHAIN_WRAPPER_ROOT)/strip
X86_TOOLCHAIN_PKGCONFIG_DIRS := $(X86_TOOLCHAIN_ROOT)/usr/lib64/pkgconfig:$(X86_TOOLCHAIN_ROOT)/usr/share/pkgconfig
X86_TOOLCHAIN_LIBRARY_DIRS := $(X86_TOOLCHAIN_ROOT)/usr/lib64:$(X86_TOOLCHAIN_ROOT)/lib64
X86_TOOLCHAIN_INCLUDE_DIRS := $(X86_TOOLCHAIN_ROOT)/usr/include
X86_GCC := $(X86_CC_WRAPPER)
X86_GXX := $(X86_CXX_WRAPPER)
X86_CC := $(X86_CC_WRAPPER)
X86_CXX := $(X86_CXX_WRAPPER)
X86_TOOLCHAIN_FILE_DEPS := $(X86_GCC_BIN) $(X86_GXX_BIN) $(X86_LD_BIN) $(X86_AR_BIN) $(X86_RANLIB_BIN) $(X86_NM_BIN) $(X86_OBJCOPY_BIN) $(X86_OBJDUMP_BIN) $(X86_READELF_BIN) $(X86_STRIP_BIN)
X86_LD := $(X86_LD_WRAPPER)
X86_AR := $(X86_AR_WRAPPER)
X86_RANLIB := $(X86_RANLIB_WRAPPER)
X86_NM := $(X86_NM_WRAPPER)
X86_OBJCOPY := $(X86_OBJCOPY_WRAPPER)
X86_OBJDUMP := $(X86_OBJDUMP_WRAPPER)
X86_READELF := $(X86_READELF_WRAPPER)
X86_STRIP := $(X86_STRIP_WRAPPER)
X86_BUILD_TOOL_DEPS := $(X86_TOOLCHAIN_FILE_DEPS) $(X86_CC_WRAPPER) $(X86_CXX_WRAPPER) $(X86_LD_WRAPPER) $(X86_AR_WRAPPER) $(X86_RANLIB_WRAPPER) $(X86_NM_WRAPPER) $(X86_OBJCOPY_WRAPPER) $(X86_OBJDUMP_WRAPPER) $(X86_READELF_WRAPPER) $(X86_STRIP_WRAPPER)

RUNNER_BUILD_DIR_ACTIVE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(RUNNER_DIR)/build-arm64,$(RUNNER_DIR)/build)
RUNNER_LIBBPF_BUILD_DIR := $(RUNNER_BUILD_DIR_ACTIVE)/vendor/libbpf
RUNNER_LIBBPF_OBJDIR := $(RUNNER_LIBBPF_BUILD_DIR)/obj
RUNNER_LIBBPF_PREFIX := $(RUNNER_LIBBPF_BUILD_DIR)/prefix
RUNNER_LIBBPF_A := $(RUNNER_LIBBPF_OBJDIR)/libbpf.a
KATRAN_BUILD_ROOT := $(REPO_BUILD_ROOT)/katran
KATRAN_INSTALL_ROOT := $(REPO_KATRAN_ROOT)
KATRAN_CMAKE_OVERRIDE := $(KATRAN_BUILD_ROOT)/cxx-override.cmake
ACTIVE_WORKLOAD_TOOLS_INSTALL_ROOT := $(ARTIFACT_ROOT)/workload-tools/$(RUN_TARGET_ARCH)
ACTIVE_WORKLOAD_TOOLS_BIN_ROOT := $(ACTIVE_WORKLOAD_TOOLS_INSTALL_ROOT)/bin
ACTIVE_DAEMON_BINARY := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(DAEMON_DIR)/target/aarch64-unknown-linux-gnu/release/bpfrejit-daemon,$(DAEMON_DIR)/target/release/bpfrejit-daemon)
ACTIVE_RUNNER_BINARY := $(RUNNER_BUILD_DIR_ACTIVE)/micro_exec
ACTIVE_TEST_UNITTEST_BUILD_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/tests/unittest/build-arm64,$(ROOT_DIR)/tests/unittest/build)
ACTIVE_TEST_NEGATIVE_BUILD_DIR := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ROOT_DIR)/tests/negative/build-arm64,$(ROOT_DIR)/tests/negative/build)
ACTIVE_TEST_UNITTEST_PRIMARY := $(ACTIVE_TEST_UNITTEST_BUILD_DIR)/rejit_regression
ACTIVE_TEST_NEGATIVE_PRIMARY := $(ACTIVE_TEST_NEGATIVE_BUILD_DIR)/scx_prog_show_race
ACTIVE_MICRO_PROGRAM_PRIMARY := $(ROOT_DIR)/micro/programs/simple.bpf.o
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
MICRO_PROGRAM_SOURCE_FILES = $(shell find "$(ROOT_DIR)/micro/programs" -type f \( -name '*.bpf.c' -o -name '*.h' -o -name 'Makefile' \) 2>/dev/null)
KINSN_SOURCE_FILES = $(shell find "$(ACTIVE_KINSN_MODULE_DIR)" "$(ROOT_DIR)/module/include" -type f \( -name '*.c' -o -name '*.h' -o -name 'Makefile' \) -print 2>/dev/null)
SCX_SOURCE_FILES = $(shell find "$(REPOS_DIR)/scx" \( -path '*/target' -o -path '*/.git' \) -prune -o -type f \( -name '*.rs' -o -name '*.c' -o -name '*.h' -o -name 'Cargo.toml' -o -name 'Cargo.lock' -o -name 'build.rs' \) -print 2>/dev/null)
BCC_SOURCE_FILES = $(shell find "$(REPOS_DIR)/bcc/libbpf-tools" \( -path '*/.output' -o -path '*/.git' \) -prune -o -type f \( -name '*.c' -o -name '*.h' -o -name '*.sh' -o -name '*.mk' -o -name '*.yaml' -o -name '*.json' -o -name '*.txt' -o -name 'Makefile' \) -print 2>/dev/null)
TRACEE_SOURCE_FILES = $(shell find "$(REPOS_DIR)/tracee" \( -path '*/dist' -o -path '*/build' -o -path '*/.git' \) -prune -o -type f \( -name '*.go' -o -name '*.c' -o -name '*.h' -o -name '*.mk' -o -name 'Makefile' -o -name 'go.mod' -o -name 'go.sum' \) -print 2>/dev/null)
TETRAGON_SOURCE_FILES = $(shell find "$(REPOS_DIR)/tetragon" \( -path '*/bpf/objs' -o -path '*/.git' \) -prune -o -type f \( -name '*.go' -o -name '*.c' -o -name '*.h' -o -name '*.yaml' -o -name '*.mk' -o -name 'Makefile' -o -name 'go.mod' -o -name 'go.sum' \) -print 2>/dev/null)
KATRAN_SOURCE_FILES = $(shell find "$(REPOS_DIR)/katran" \( -path '*/build' -o -path '*/deps' -o -path '*/.git' \) -prune -o -type f \( -name '*.cc' -o -name '*.cpp' -o -name '*.c' -o -name '*.h' -o -name '*.hpp' -o -name '*.bpf.c' -o -name '*.sh' -o -name '*.cmake' -o -name 'CMakeLists.txt' \) -print 2>/dev/null)
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
$(KERNEL_SOURCE_FILES):

$(RUNNER_LIBBPF_A): $(LIBBPF_SOURCE_FILES)
	@mkdir -p "$(RUNNER_LIBBPF_OBJDIR)" "$(RUNNER_LIBBPF_PREFIX)/include"
	$(MAKE) -C "$(ROOT_DIR)/vendor/libbpf/src" -j"$(JOBS)" BUILD_STATIC_ONLY=1 OBJDIR="$(RUNNER_LIBBPF_OBJDIR)" DESTDIR= PREFIX="$(RUNNER_LIBBPF_PREFIX)" "$(RUNNER_LIBBPF_A)" install_headers

$(X86_BUILD_DIR)/arch/x86/boot/bzImage: $(KERNEL_CONFIG_PATH) $(KERNEL_BUILD_META_FILES) $(KERNEL_SOURCE_FILES)
	@mkdir -p "$(X86_BUILD_DIR)"
	@$(MAKE) -C "$(KERNEL_DIR)" O="$(X86_BUILD_DIR)" olddefconfig
	@set -e; \
	if [ -f "$@" ]; then \
		if $(MAKE) -C "$(KERNEL_DIR)" O="$(X86_BUILD_DIR)" -q bzImage modules; then \
			echo "[kernel] reuse existing x86 bzImage/modules"; \
		else \
			status="$$?"; \
			if [ "$$status" -eq 1 ]; then \
				$(MAKE) -C "$(KERNEL_DIR)" O="$(X86_BUILD_DIR)" -j"$(JOBS)" bzImage modules; \
			else \
				exit "$$status"; \
			fi; \
		fi; \
	else \
		$(MAKE) -C "$(KERNEL_DIR)" O="$(X86_BUILD_DIR)" -j"$(JOBS)" bzImage modules; \
	fi

$(X86_BUILD_DIR)/include/linux/kconfig.h: $(X86_BUILD_DIR)/arch/x86/boot/bzImage $(KERNEL_DIR)/include/linux/kconfig.h
	@mkdir -p "$(X86_BUILD_DIR)/include"
	@ln -sfn "$(KERNEL_DIR)/include/linux" "$(X86_BUILD_DIR)/include/linux"
	@test -f "$@"

$(ACTIVE_DAEMON_BINARY): $(DAEMON_SOURCE_FILES)
	@mkdir -p "$(dir $@)"
	@if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		$(MAKE) -C "$(ROOT_DIR)/daemon" release TARGET_DIR="$(DAEMON_DIR)/target" TARGET_TRIPLE="aarch64-unknown-linux-gnu"; \
	else \
		$(MAKE) -C "$(ROOT_DIR)/daemon" release TARGET_DIR="$(DAEMON_DIR)/target"; \
	fi

$(ACTIVE_RUNNER_BINARY): $(RUNNER_LIBBPF_A) $(RUNNER_SOURCE_FILES)
	@mkdir -p "$(dir $@)"
	@if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		docker build -t "$(ARM64_CROSSBUILD_IMAGE)" -f "$(RUNNER_DIR)/docker/arm64-crossbuild.Dockerfile" "$(ROOT_DIR)"; \
		docker run --rm --platform linux/arm64 \
			-v "$(ROOT_DIR):$(ROOT_DIR)" \
			-w "$(ROOT_DIR)" \
			"$(ARM64_CROSSBUILD_IMAGE)" \
			bash -eu -o pipefail -c ' \
				cmake_args='\''-S "$(RUNNER_DIR)" -B "$(RUNNER_BUILD_DIR_ACTIVE)" -DCMAKE_BUILD_TYPE=Release -DMICRO_REPO_ROOT="$(ROOT_DIR)" -DMICRO_LIBBPF_PREFIX="$(RUNNER_LIBBPF_PREFIX)" -DMICRO_LIBBPF_LIBRARY="$(RUNNER_LIBBPF_A)" -DMICRO_EXEC_ENABLE_LLVMBPF="$(RUN_SUITE_NEEDS_LLVMBPF)"'\''; \
				if [ -n "$(LLVM_DIR)" ]; then cmake_args="$$cmake_args -DLLVM_DIR=$(LLVM_DIR)"; fi; \
				eval cmake $$cmake_args; \
				cmake --build "$(RUNNER_BUILD_DIR_ACTIVE)" --target micro_exec -j"$(JOBS)"'; \
	else \
		cmake_args='-S "$(RUNNER_DIR)" -B "$(RUNNER_BUILD_DIR_ACTIVE)" -DCMAKE_BUILD_TYPE=Release -DMICRO_REPO_ROOT="$(ROOT_DIR)" -DMICRO_LIBBPF_PREFIX="$(RUNNER_LIBBPF_PREFIX)" -DMICRO_LIBBPF_LIBRARY="$(RUNNER_LIBBPF_A)" -DMICRO_EXEC_ENABLE_LLVMBPF="$(RUN_SUITE_NEEDS_LLVMBPF)"'; \
		if [ -n "$(LLVM_DIR)" ]; then cmake_args="$$cmake_args -DLLVM_DIR=$(LLVM_DIR)"; fi; \
		eval cmake $$cmake_args; \
		cmake --build "$(RUNNER_BUILD_DIR_ACTIVE)" --target micro_exec -j"$(JOBS)"; \
	fi

$(ACTIVE_TEST_UNITTEST_PRIMARY): $(TEST_UNITTEST_SOURCE_FILES) $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_GCC))
	@mkdir -p "$(ACTIVE_TEST_UNITTEST_BUILD_DIR)" "$(ACTIVE_TEST_UNITTEST_BUILD_DIR)/vendor/bpftool"
	@if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		$(MAKE) -C "$(ROOT_DIR)/tests/unittest" BUILD_DIR="$(ACTIVE_TEST_UNITTEST_BUILD_DIR)" CC="aarch64-linux-gnu-gcc" CLANG="clang"; \
	else \
		$(MAKE) -C "$(ROOT_DIR)/tests/unittest" BUILD_DIR="$(ACTIVE_TEST_UNITTEST_BUILD_DIR)"; \
	fi

$(ACTIVE_TEST_NEGATIVE_PRIMARY): $(TEST_NEGATIVE_SOURCE_FILES) $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_GCC))
	@mkdir -p "$(ACTIVE_TEST_NEGATIVE_BUILD_DIR)"
	@if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		$(MAKE) -C "$(ROOT_DIR)/tests/negative" BUILD_DIR="$(ACTIVE_TEST_NEGATIVE_BUILD_DIR)" CC="aarch64-linux-gnu-gcc"; \
	else \
		$(MAKE) -C "$(ROOT_DIR)/tests/negative" BUILD_DIR="$(ACTIVE_TEST_NEGATIVE_BUILD_DIR)"; \
	fi

$(ACTIVE_MICRO_PROGRAM_PRIMARY): $(MICRO_PROGRAM_SOURCE_FILES)
	@$(MAKE) -C "$(ROOT_DIR)/micro/programs" OUTPUT_DIR="$(ROOT_DIR)/micro/programs" "$@"

$(ACTIVE_KINSN_PRIMARY): $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_GCC) $(ARM64_GXX) $(ARM64_READELF) $(ARM64_AWS_BUILD_DIR)/arch/arm64/boot/Image,$(X86_BUILD_DIR)/arch/x86/boot/bzImage) $(KINSN_SOURCE_FILES)
	@module_dir="$(ACTIVE_KINSN_MODULE_DIR)"; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		$(MAKE) -C "$(KERNEL_DIR)" O="$(ARM64_AWS_BUILD_DIR)" ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" M="$$module_dir" modules; \
	else \
		$(MAKE) -C "$(KERNEL_DIR)" O="$(X86_BUILD_DIR)" M="$$module_dir" modules; \
	fi

$(ACTIVE_KINSN_SECONDARIES): $(ACTIVE_KINSN_PRIMARY)
	@test -f "$@"

$(REPO_KERNEL_MODULES_ROOT)/lib/modules: $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_AWS_IMAGE) $(ARM64_AWS_BUILD_CONFIG),$(X86_BUILD_DIR)/arch/x86/boot/bzImage $(X86_BUILD_DIR)/include/linux/kconfig.h)
	@stage_root="$(REPO_KERNEL_MODULES_ROOT)"; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		build_dir="$(ARM64_AWS_BUILD_DIR)"; \
	else \
		build_dir="$(X86_BUILD_DIR)"; \
	fi; \
	kernel_release_file="$$build_dir/include/config/kernel.release"; \
	test -f "$$kernel_release_file" || { echo "missing kernel release file: $$kernel_release_file" >&2; exit 1; }; \
	kernel_release="$$(tr -d '\n' < "$$kernel_release_file")"; \
	release_root="$$stage_root/lib/modules/$$kernel_release"; \
	mkdir -p "$$stage_root"; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		$(MAKE) --no-print-directory -C "$(KERNEL_DIR)" O="$$build_dir" ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" INSTALL_MOD_PATH="$$stage_root" DEPMOD=true CONFIG_MODULE_SIG=n modules_install >/dev/null; \
	else \
		$(MAKE) --no-print-directory -C "$(KERNEL_DIR)" O="$$build_dir" INSTALL_MOD_PATH="$$stage_root" DEPMOD=true CONFIG_MODULE_SIG=n modules_install >/dev/null; \
	fi; \
	depmod -b "$$stage_root" "$$kernel_release" >/dev/null; \
	ln -sfn "$$build_dir" "$$release_root/build"; \
	ln -sfn "$(KERNEL_DIR)" "$$release_root/source"; \
	test -f "$$release_root/kernel/drivers/block/null_blk/null_blk.ko"; \
	test -f "$$release_root/kernel/net/sched/sch_netem.ko"

$(ACTIVE_LIBBPF_RUNTIME_PRIMARY): $(LIBBPF_SOURCE_FILES) $(BUILD_RULE_FILES)
	@runtime_root="$(REPO_ARTIFACT_ROOT)/libbpf"; \
	mkdir -p "$$runtime_root" "$(X86_LIBBPF_RUNTIME_BUILD_ROOT)"; \
	docker run --rm --platform linux/amd64 \
		-v "$(ROOT_DIR):/workspace:ro" \
		-v "$(X86_LIBBPF_RUNTIME_BUILD_ROOT):/build" \
		-v "$$runtime_root:/out" \
		amazonlinux:2023 \
		bash -lc 'set -euo pipefail; \
			dnf -y install gcc make elfutils-libelf-devel binutils >/dev/null 2>&1; \
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
			if [[ -n "$$soname" && "$$soname" != "$$real_name" ]]; then ln -sfn "$$real_name" "/out/lib/$$soname"; fi; \
			chown -R $(shell id -u):$(shell id -g) /out /build'

$(REPO_SCX_ROOT)/bin/%: $(SCX_SOURCE_FILES) $(BUILD_RULE_FILES) $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_GCC) $(ARM64_GXX) $(ARM64_READELF),$(X86_BUILD_TOOL_DEPS))
	@package="$*"; \
	repo_root="$(REPOS_DIR)/scx"; \
	corpus_root="$(REPO_SCX_ROOT)"; \
	bin_root="$$corpus_root/bin"; \
	target_dir="$(SCX_CARGO_TARGET_DIR)"; \
	mkdir -p "$$bin_root" "$$corpus_root" "$$corpus_root/lib" "$$target_dir"; \
		if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
			target_release_dir="$$target_dir/aarch64-unknown-linux-gnu/release"; \
		PKG_CONFIG_ALLOW_CROSS=1 \
		PKG_CONFIG_SYSROOT_DIR="$(ARM64_TOOLCHAIN_ROOT)" \
		PKG_CONFIG_LIBDIR="$(ARM64_TOOLCHAIN_PKGCONFIG_DIRS)" \
		BINDGEN_EXTRA_CLANG_ARGS_aarch64_unknown_linux_gnu="--sysroot=$(ARM64_TOOLCHAIN_ROOT) $(foreach dir,$(subst :, ,$(ARM64_TOOLCHAIN_INCLUDE_DIRS)),-I$(dir))" \
		CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER="$(ARM64_GCC)" \
			CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_RUSTFLAGS="-Clink-arg=--sysroot=$(ARM64_TOOLCHAIN_ROOT) $(foreach dir,$(subst :, ,$(ARM64_TOOLCHAIN_LIBRARY_DIRS)),-Clink-arg=-L$(dir))" \
			CC_aarch64_unknown_linux_gnu="$(ARM64_CC)" \
			CXX_aarch64_unknown_linux_gnu="$(ARM64_CXX)" \
			AR_aarch64_unknown_linux_gnu="$(ARM64_AR)" \
			RANLIB_aarch64_unknown_linux_gnu="$(ARM64_RANLIB)" \
			CARGO_TARGET_DIR="$$target_dir" \
			cargo build --release --target "aarch64-unknown-linux-gnu" --manifest-path "$$repo_root/Cargo.toml" --package "$$package"; \
			test -x "$$target_release_dir/$$package"; \
			object_path="$$(find "$$target_release_dir/build" -path "*/$$package-*/out/main.bpf.o" | sort | tail -n1)"; \
		else \
			target_release_dir="$$target_dir/x86_64-unknown-linux-gnu/release"; \
			PKG_CONFIG_ALLOW_CROSS=1 \
			PKG_CONFIG_SYSROOT_DIR="$(X86_TOOLCHAIN_ROOT)" \
			PKG_CONFIG_LIBDIR="$(X86_TOOLCHAIN_PKGCONFIG_DIRS)" \
			BINDGEN_EXTRA_CLANG_ARGS_x86_64_unknown_linux_gnu="--sysroot=$(X86_TOOLCHAIN_ROOT) $(foreach dir,$(subst :, ,$(X86_TOOLCHAIN_INCLUDE_DIRS)),-I$(dir))" \
				CARGO_TARGET_X86_64_UNKNOWN_LINUX_GNU_LINKER="$(X86_CC)" \
			CARGO_TARGET_X86_64_UNKNOWN_LINUX_GNU_RUSTFLAGS="-Clink-arg=--sysroot=$(X86_TOOLCHAIN_ROOT) $(foreach dir,$(subst :, ,$(X86_TOOLCHAIN_LIBRARY_DIRS)),-Clink-arg=-L$(dir))" \
			CC_x86_64_unknown_linux_gnu="$(X86_CC)" \
			CXX_x86_64_unknown_linux_gnu="$(X86_CXX)" \
				AR_x86_64_unknown_linux_gnu="$(X86_AR)" \
				RANLIB_x86_64_unknown_linux_gnu="$(X86_RANLIB)" \
			CARGO_TARGET_DIR="$$target_dir" \
			cargo build --release --target "x86_64-unknown-linux-gnu" --manifest-path "$$repo_root/Cargo.toml" --package "$$package"; \
			test -x "$$target_release_dir/$$package"; \
			object_path="$$(find "$$target_release_dir/build" -path "*/$$package-*/out/main.bpf.o" | sort | tail -n1)"; \
		fi; \
		$(call PORTABLE_WRAP_BINARY,$$target_release_dir/$$package,$@,$$corpus_root/lib); \
		test -n "$$object_path"; \
		obj_dst="$$corpus_root/$${package}_main.bpf.o"; \
		ln -f "$$object_path" "$$obj_dst"

$(REPO_SCX_ROOT)/%_main.bpf.o: $(REPO_SCX_ROOT)/bin/%
	@test -f "$@"

$(ACTIVE_BCC_REQUIRED) &: $(BCC_SOURCE_FILES) $(BUILD_RULE_FILES) $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_GCC) $(ARM64_GXX) $(ARM64_READELF),$(X86_BUILD_TOOL_DEPS))
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
	bpftool_cmd="$(ROOT_DIR)/vendor/linux-framework/tools/bpf/bpftool/bpftool"; \
	test -x "$$bpftool_cmd" || { echo "missing vendored bpftool build output: $$bpftool_cmd" >&2; exit 1; }; \
	make_args='OUTPUT="'"$$build_output_root"'" LIBBPF_SRC="$(ROOT_DIR)/vendor/libbpf/src" BPFTOOL="'"$$bpftool_cmd"'" USE_BLAZESYM=0'; \
	make_env=""; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		make_args="$$make_args ARCH=arm64 CROSS_COMPILE=$(CROSS_COMPILE_ARM64) CC=\"$(ARM64_CC)\" LD=\"$(ARM64_HOST_CROSS_PREFIX)ld\""; \
		make_env='PKG_CONFIG_ALLOW_CROSS=1 PKG_CONFIG_SYSROOT_DIR="$(ARM64_TOOLCHAIN_ROOT)" PKG_CONFIG_LIBDIR="$(ARM64_TOOLCHAIN_PKGCONFIG_DIRS)"'; \
	else \
			make_args="$$make_args CC=\"$(X86_CC)\" LD=\"$(X86_LD)\" AR=\"$(X86_AR)\" RANLIB=\"$(X86_RANLIB)\""; \
		make_env='PKG_CONFIG_ALLOW_CROSS=1 PKG_CONFIG_SYSROOT_DIR="$(X86_TOOLCHAIN_ROOT)" PKG_CONFIG_LIBDIR="$(X86_TOOLCHAIN_PKGCONFIG_DIRS)"'; \
	fi; \
	eval $$make_env $(MAKE) -C "\"$$repo_root\"" -j"$(JOBS)" $$make_args $(ACTIVE_BCC_TOOLS); \
	for tool in $(ACTIVE_BCC_TOOLS); do \
		test -x "$$repo_root/$$tool" || { echo "missing bcc tool build output: $$repo_root/$$tool" >&2; exit 1; }; \
		test -f "$$build_output_root/$$tool.bpf.o" || { echo "missing bcc BPF object: $$build_output_root/$$tool.bpf.o" >&2; exit 1; }; \
		$(call PORTABLE_WRAP_BINARY,$$repo_root/$$tool,$$artifact_root/$$tool,$$runtime_lib_root); \
		ln -f "$$build_output_root/$$tool.bpf.o" "$$artifact_root/$$tool.bpf.o"; \
	done; \
	for path in $(ACTIVE_BCC_REQUIRED); do \
		test -e "$$path"; \
	done

$(ACTIVE_TRACEE_REQUIRED) &: $(TRACEE_SOURCE_FILES) $(BUILD_RULE_FILES) $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_GCC) $(ARM64_GXX) $(ARM64_READELF),$(X86_BUILD_TOOL_DEPS))
	@repo_src="$(REPOS_DIR)/tracee"; \
	build_root="$(TRACEE_BUILD_ROOT)"; \
	repo_root="$(TRACEE_BUILD_REPO)"; \
	dist_root="$(TRACEE_BUILD_DIST_ROOT)"; \
	libbpf_root="$(TRACEE_LIBBPF_ROOT)"; \
	libbpf_obj_root="$(TRACEE_LIBBPF_OBJDIR)"; \
	libbpf_archive="$(TRACEE_LIBBPF_A)"; \
	output_root="$(REPO_TRACEE_ROOT)"; \
	mkdir -p "$$build_root" "$$output_root/bin" "$$output_root/lsm_support" "$$output_root/lib" "$$dist_root" "$$dist_root/signatures" "$$dist_root/btfhub"; \
	rsync -a --delete --delete-excluded \
		--filter='P dist/' \
		--filter='P build/' \
		--exclude '.git' \
		--exclude 'dist/' \
		--exclude 'build/' \
		"$$repo_src/" "$$repo_root/"; \
		mkdir -p "$$dist_root" "$$output_root/bin" "$$output_root/lsm_support" "$$output_root/lib" "$$libbpf_obj_root" "$$libbpf_root/include/linux"; \
		tracee_pkgconfig_env=""; \
		if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
			libbpf_cc="$(ARM64_CC)"; \
			libbpf_ar="$(ARM64_AR)"; \
			libbpf_ranlib="$(ARM64_RANLIB)"; \
			tracee_cc="$(ARM64_CC)"; \
			tracee_goarch="arm64"; \
			tracee_make_arch_env='UNAME_M=aarch64 ARCH=arm64 LINUX_ARCH=arm64 GO_ARCH=arm64 CMD_GCC="$(ARM64_CC)"'; \
			tracee_cgo_cflags="-I$$libbpf_root/include $(foreach dir,$(subst :, ,$(ARM64_TOOLCHAIN_INCLUDE_DIRS)),-I$(dir))"; \
			tracee_cgo_ldflags="$$libbpf_archive $(foreach dir,$(subst :, ,$(ARM64_TOOLCHAIN_LIBRARY_DIRS)),-L$(dir)) -lelf -lz"; \
				tracee_pkgconfig_env='PKG_CONFIG_ALLOW_CROSS=1'; \
			else \
				libbpf_cc="$(X86_CC)"; \
				libbpf_ar="$(X86_AR)"; \
				libbpf_ranlib="$(X86_RANLIB)"; \
				tracee_cc="$(X86_CC)"; \
				tracee_goarch="amd64"; \
				tracee_make_arch_env='UNAME_M=x86_64 ARCH=x86_64 LINUX_ARCH=x86 GO_ARCH=amd64 CMD_GCC="$(X86_CC)"'; \
				tracee_cgo_cflags="-I$$libbpf_root/include $(foreach dir,$(subst :, ,$(X86_TOOLCHAIN_INCLUDE_DIRS)),-I$(dir))"; \
				tracee_cgo_ldflags="$$libbpf_archive $(foreach dir,$(subst :, ,$(X86_TOOLCHAIN_LIBRARY_DIRS)),-L$(dir)) -lelf -lz"; \
				tracee_pkgconfig_env='PKG_CONFIG_ALLOW_CROSS=1'; \
			fi; \
				CC="$$libbpf_cc" AR="$$libbpf_ar" RANLIB="$$libbpf_ranlib" EXTRA_CFLAGS="-fPIC" \
				$(MAKE) -C "$$repo_root/3rdparty/libbpf/src" --no-print-directory BUILD_STATIC_ONLY=1 \
					OBJDIR="$$libbpf_obj_root" DESTDIR="$$libbpf_root" PREFIX="$$dist_root" \
					LIBDIR=/to-be-removed INCLUDEDIR=/include UAPIDIR=/include install install_uapi_headers; \
			cp "$$repo_root/3rdparty/libbpf/include/uapi/linux/"*.h "$$libbpf_root/include/linux/"; \
			sed -i 's|^libdir=/to-be-removed$$|libdir=$${prefix}/libbpf/obj|' "$$libbpf_obj_root/libbpf.pc"; \
			sed -i 's|^includedir=$${prefix}/include$$|includedir=$${prefix}/libbpf/include|' "$$libbpf_obj_root/libbpf.pc"; \
			eval GOCACHE="\"$$build_root/go-build\"" PKG_CONFIG_PATH="\"$$libbpf_obj_root\"" $$tracee_pkgconfig_env $(MAKE) -C "\"$$repo_root\"" -j"$(JOBS)" OUTPUT_DIR="\"$$dist_root\"" $$tracee_make_arch_env bpf; \
			eval GOCACHE="\"$$build_root/go-build\"" PKG_CONFIG_PATH="\"$$libbpf_obj_root\"" $$tracee_pkgconfig_env $(MAKE) -C "\"$$repo_root\"" --no-print-directory OUTPUT_DIR="\"$$dist_root\"" btfhub; \
			touch "$$dist_root/btfhub/.place-holder"; \
			cd "$$repo_root" && \
				GOEXPERIMENT=norandomizedheapbase64 \
				GOOS=linux GOARCH="$$tracee_goarch" CGO_ENABLED=1 \
				CC="$$tracee_cc" \
				CGO_CFLAGS="$$tracee_cgo_cflags" \
				CGO_LDFLAGS="$$tracee_cgo_ldflags" \
					GOCACHE="$$build_root/go-build" \
					go build -tags core,ebpf,lsmsupport --buildmode=plugin \
						-o "$$dist_root/signatures/builtin.so" \
				signatures/golang/test_helpers.go signatures/golang/export.go; \
		cd "$$repo_root" && \
			GOEXPERIMENT=norandomizedheapbase64 \
				GOOS=linux GOARCH="$$tracee_goarch" CGO_ENABLED=1 \
				CC="$$tracee_cc" \
				CGO_CFLAGS="$$tracee_cgo_cflags" \
				CGO_LDFLAGS="$$tracee_cgo_ldflags" \
					GOCACHE="$$build_root/go-build" \
					go build -tags core,ebpf,lsmsupport -ldflags="-w" -o "$$dist_root/tracee" ./cmd/tracee; \
	test -x "$$dist_root/tracee" || { echo "missing tracee build output: $$dist_root/tracee" >&2; exit 1; }; \
	$(call PORTABLE_WRAP_BINARY,$$dist_root/tracee,$$output_root/bin/tracee,$$output_root/lib); \
	ln -f "$$dist_root/tracee.bpf.o" "$$output_root/tracee.bpf.o"; \
	ln -f "$$dist_root/lsm_support/kprobe_check.bpf.o" "$$output_root/lsm_support/kprobe_check.bpf.o"; \
	ln -f "$$dist_root/lsm_support/lsm_check.bpf.o" "$$output_root/lsm_support/lsm_check.bpf.o"; \
	for path in $(ACTIVE_TRACEE_REQUIRED); do \
		test -e "$$path"; \
	done

$(ACTIVE_TETRAGON_REQUIRED) &: $(TETRAGON_SOURCE_FILES) $(BUILD_RULE_FILES)
	@repo_src="$(REPOS_DIR)/tetragon"; \
	build_root="$(TETRAGON_BUILD_ROOT)"; \
	repo_root="$(TETRAGON_BUILD_REPO)"; \
	bpf_output_root="$(TETRAGON_BUILD_BPF_ROOT)"; \
	artifact_root="$(REPO_TETRAGON_ROOT)"; \
	target_arch="$$( [ "$(RUN_TARGET_ARCH)" = "arm64" ] && printf 'arm64' || printf 'amd64' )"; \
	goarch="$$target_arch"; \
	mkdir -p "$$build_root" "$$artifact_root/bin" "$$bpf_output_root"; \
	rsync -a --delete --exclude '.git' --exclude 'build' --exclude 'bpf/objs' "$$repo_src/" "$$repo_root/"; \
	version="$$(git -C "$$repo_root" describe --tags --always --exclude '*/*' 2>/dev/null || printf '%s' unknown)"; \
	if [ -L "$$repo_root/bpf/objs" ] || [ ! -e "$$repo_root/bpf/objs" ]; then \
		ln -sfn "$$bpf_output_root" "$$repo_root/bpf/objs"; \
	else \
		echo "legacy tetragon bpf/objs directory exists: $$repo_root/bpf/objs; clean it explicitly once" >&2; \
		exit 1; \
	fi; \
	$(MAKE) -C "$$repo_root" -j"$(JOBS)" TARGET_ARCH="$$target_arch" LOCAL_CLANG=1 tetragon-bpf; \
	cd "$$repo_root" && CGO_ENABLED=0 GOARCH="$$goarch" GOCACHE="$$build_root/go-build" go build -mod=mod \
		-ldflags "-X github.com/cilium/tetragon/pkg/version.Version=$$version -X github.com/cilium/tetragon/pkg/version.Name=tetragon -s -w" \
		-o "$$artifact_root/bin/tetragon" ./cmd/tetragon/; \
	ln -f "$$bpf_output_root/bpf_execve_event.o" "$$artifact_root/bpf_execve_event.o"; \
	ln -f "$$bpf_output_root/bpf_generic_kprobe.o" "$$artifact_root/bpf_generic_kprobe.o"; \
	for path in $(ACTIVE_TETRAGON_REQUIRED); do \
		test -e "$$path"; \
	done

$(ACTIVE_KATRAN_REQUIRED) &: $(KATRAN_SOURCE_FILES) $(BUILD_RULE_FILES) $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_GCC) $(ARM64_GXX) $(ARM64_READELF),$(X86_BUILD_TOOL_DEPS))
	@build_root="$(KATRAN_BUILD_ROOT)"; \
	install_root="$(KATRAN_INSTALL_ROOT)"; \
	override_file="$(KATRAN_CMAKE_OVERRIDE)"; \
	bpf_root="$(REPO_KATRAN_ROOT)/bpf"; \
	folly_xlog_prefixes="-DFOLLY_XLOG_STRIP_PREFIXES=\\\\\\\"$$build_root/deps/folly:$$build_root/deps/folly/build\\\\\\\""; \
	katran_pkgconfig_env=""; \
	katran_cc="clang"; \
	katran_cxx="clang++"; \
	katran_ar="ar"; \
	katran_ranlib="ranlib"; \
	cmake_arch_args=""; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		katran_cc="$(ARM64_CC)"; \
		katran_cxx="$(ARM64_CXX)"; \
		katran_ar="$(ARM64_AR)"; \
		katran_ranlib="$(ARM64_RANLIB)"; \
		cmake_arch_args="-DCMAKE_SYSTEM_NAME=Linux -DCMAKE_SYSTEM_PROCESSOR=aarch64"; \
		katran_pkgconfig_env='PKG_CONFIG_ALLOW_CROSS=1 PKG_CONFIG_SYSROOT_DIR="$(ARM64_TOOLCHAIN_ROOT)" PKG_CONFIG_LIBDIR="$(ARM64_TOOLCHAIN_PKGCONFIG_DIRS)"'; \
	else \
		katran_cc="gcc"; \
		katran_cxx="g++"; \
		katran_ar="ar"; \
		katran_ranlib="ranlib"; \
		cmake_arch_args=""; \
		katran_pkgconfig_env=""; \
	fi; \
	mkdir -p "$$install_root/bin" "$$install_root/lib" "$$install_root/lib64" "$$bpf_root" "$$build_root"; \
	printf '%s\n' 'set(CMAKE_CXX_COMPILE_OBJECT "<CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -std=gnu++20 -o <OBJECT> -c <SOURCE>")' > "$$override_file"; \
	cd "$(REPOS_DIR)/katran" && \
	eval $$katran_pkgconfig_env env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR \
	CC="$$katran_cc" CXX="$$katran_cxx" AR="$$katran_ar" RANLIB="$$katran_ranlib" \
	CXXFLAGS="$$folly_xlog_prefixes" BUILD_EXAMPLE_GRPC=1 BUILD_DIR="$$build_root" INSTALL_DIR="$$install_root" INSTALL_DEPS_ONLY=1 ./build_katran.sh; \
	mkdir -p "$$install_root/grpc/_build"; \
	ln -sfn "$$install_root/bin/grpc_cpp_plugin" "$$install_root/grpc/_build/grpc_cpp_plugin"; \
	cd "$(REPOS_DIR)/katran" && \
	eval $$katran_pkgconfig_env env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR CMAKE_BUILD_EXAMPLE_GRPC=1 \
	CC="$$katran_cc" CXX="$$katran_cxx" AR="$$katran_ar" RANLIB="$$katran_ranlib" \
	cmake -S . -B "$$build_root/build" \
		-DCMAKE_PREFIX_PATH="$$install_root" \
		-DCMAKE_INSTALL_PREFIX="$$install_root" \
		-DCMAKE_BUILD_TYPE=RelWithDebInfo \
		-DPKG_CONFIG_USE_CMAKE_PREFIX_PATH=ON \
		-DLIB_BPF_PREFIX="$$install_root" \
		-DCMAKE_CXX_STANDARD=20 \
		-DCMAKE_C_COMPILER="$$katran_cc" \
		-DCMAKE_CXX_COMPILER="$$katran_cxx" \
		-DCMAKE_AR="$$katran_ar" \
		-DCMAKE_RANLIB="$$katran_ranlib" \
		-DCMAKE_USER_MAKE_RULES_OVERRIDE_CXX="$$override_file" \
		-DBUILD_TESTS=OFF $$cmake_arch_args; \
	cmake --build "$$build_root/build" --target install -j"$(JOBS)"; \
		PORTABLE_WRAP_SEARCH_DIRS="/lib/x86_64-linux-gnu:/usr/lib/x86_64-linux-gnu:$$install_root/lib64:$$install_root/lib" $(call PORTABLE_WRAP_BINARY,$$install_root/bin/katran_server_grpc,$$install_root/bin/katran_server_grpc,$$install_root/lib); \
	cd "$(REPOS_DIR)/katran" && ./build_bpf_modules_opensource.sh -s "$(REPOS_DIR)/katran" -b "$$build_root" -o "$$bpf_root"; \
	[ -f "$$bpf_root/healthchecking_ipip.o" ] && mv -f "$$bpf_root/healthchecking_ipip.o" "$$bpf_root/healthchecking_ipip.bpf.o" || true; \
	for path in $(ACTIVE_KATRAN_REQUIRED); do \
		test -e "$$path"; \
	done

ARM64_TOOLCHAIN_ROOT := $(RUNNER_DIR)/build-arm64/toolchain
ARM64_TOOLCHAIN_BIN := $(ARM64_TOOLCHAIN_ROOT)/bin
ARM64_TOOLCHAIN_PKGCONFIG_DIRS := $(ARM64_TOOLCHAIN_ROOT)/usr/lib/aarch64-linux-gnu/pkgconfig:$(ARM64_TOOLCHAIN_ROOT)/usr/lib/pkgconfig:$(ARM64_TOOLCHAIN_ROOT)/usr/lib64/pkgconfig:$(ARM64_TOOLCHAIN_ROOT)/usr/share/pkgconfig
ARM64_TOOLCHAIN_LIBRARY_DIRS := $(ARM64_TOOLCHAIN_ROOT)/usr/lib/aarch64-linux-gnu:$(ARM64_TOOLCHAIN_ROOT)/usr/lib:$(ARM64_TOOLCHAIN_ROOT)/lib/aarch64-linux-gnu:$(ARM64_TOOLCHAIN_ROOT)/lib
ARM64_TOOLCHAIN_INCLUDE_DIRS := $(ARM64_TOOLCHAIN_ROOT)/usr/include:$(ARM64_TOOLCHAIN_ROOT)/usr/include/aarch64-linux-gnu
ARM64_HOST_CROSS_PREFIX := $(ARM64_TOOLCHAIN_BIN)/$(CROSS_COMPILE_ARM64)
ARM64_CROSS_PREFIX ?= $(CROSS_COMPILE_ARM64)
ARM64_GCC := $(ARM64_HOST_CROSS_PREFIX)gcc
ARM64_GXX := $(ARM64_HOST_CROSS_PREFIX)g++
ARM64_LD := $(ARM64_HOST_CROSS_PREFIX)ld
ARM64_AR := $(ARM64_HOST_CROSS_PREFIX)ar
ARM64_RANLIB := $(ARM64_HOST_CROSS_PREFIX)ranlib
ARM64_NM := $(ARM64_HOST_CROSS_PREFIX)nm
ARM64_OBJCOPY := $(ARM64_HOST_CROSS_PREFIX)objcopy
ARM64_OBJDUMP := $(ARM64_HOST_CROSS_PREFIX)objdump
ARM64_READELF := $(ARM64_HOST_CROSS_PREFIX)readelf
ARM64_STRIP := $(ARM64_HOST_CROSS_PREFIX)strip
ARM64_CC := $(ARM64_GCC) --sysroot=$(ARM64_TOOLCHAIN_ROOT)
ARM64_CXX := $(ARM64_GXX) --sysroot=$(ARM64_TOOLCHAIN_ROOT)

$(X86_TOOLCHAIN_FILE_DEPS) $(X86_TOOLCHAIN_ROOT)/usr/include/features.h &:
	@mkdir -p "$(X86_TOOLCHAIN_ROOT)"
	docker run --rm --platform linux/amd64 \
		-v "$(X86_TOOLCHAIN_ROOT):/out" \
		rockylinux:9 \
		bash -lc 'set -euo pipefail; \
			dnf -y install --installroot=/out --releasever=9 --setopt=install_weak_deps=False --nodocs \
				binutils gcc gcc-c++ glibc-devel libstdc++-devel elfutils-libelf-devel zlib-devel openssl-devel pkgconf-pkg-config >/dev/null 2>&1; \
			test -x /out/usr/bin/gcc; \
			test -x /out/usr/bin/g++; \
				test -x /out/usr/bin/readelf; \
				chown -R $(shell id -u):$(shell id -g) /out'

$(X86_TOOLCHAIN_WRAPPER_ROOT)/%: $(X86_TOOLCHAIN_FILE_DEPS) $(BUILD_RULE_FILES)
	@mkdir -p "$(X86_TOOLCHAIN_WRAPPER_ROOT)"
	@target="$@"; \
	tool_name="$$(basename "$$target")"; \
	tool_bin="$(X86_TOOLCHAIN_BIN)/$$tool_name"; \
	case "$$tool_name" in \
		gcc|g++|ld|ar|ranlib|nm|objcopy|objdump|readelf|strip) ;; \
		*) echo "unsupported x86 wrapper target: $$tool_name" >&2; exit 1 ;; \
	esac; \
	case "$$tool_name" in \
		ld) tool_bin="$(X86_TOOLCHAIN_BIN)/ld.bfd" ;; \
	esac; \
	test -x "$$tool_bin"; \
	support_root="$(X86_TOOLCHAIN_SUPPORT_LIB_ROOT)"; \
	mkdir -p "$$support_root"; \
	for pattern in libbfd*.so* libopcodes*.so* libctf*.so* libzstd*.so*; do \
		for src in $(X86_TOOLCHAIN_ROOT)/usr/lib64/$$pattern; do \
			[ -e "$$src" ] || continue; \
			ln -sfn "$$src" "$$support_root/$$(basename "$$src")"; \
		done; \
	done; \
	case "$$tool_name" in \
		gcc|g++) env_prefix='' ; sysroot_args='--sysroot=$(X86_TOOLCHAIN_ROOT)' ;; \
		*) env_prefix='LD_LIBRARY_PATH="'"$$support_root"'$${LD_LIBRARY_PATH:+:$${LD_LIBRARY_PATH}}"' ; sysroot_args='' ;; \
	esac; \
	printf '%s\n' \
		'#!/usr/bin/env bash' \
		'set -euo pipefail' \
		'exec env '"$$env_prefix"' "'"$$tool_bin"'" '"$$sysroot_args"' "$$@"' \
		> "$$target"; \
	chmod +x "$$target"

define PORTABLE_WRAP_BINARY
	runtime_input="$(1)"; \
	runtime_wrapper="$(2)"; \
	runtime_lib_dir="$(3)"; \
	mkdir -p "$$(dirname "$$runtime_wrapper")" "$$runtime_lib_dir"; \
	cp -Lf "$$runtime_input" "$$runtime_wrapper.real"; \
	chmod +x "$$runtime_wrapper.real"; \
	readelf_bin="readelf"; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		readelf_bin="$(ARM64_READELF)"; \
	elif [ "$(RUN_TARGET_ARCH)" = "x86_64" ] && [ -x "$(X86_READELF)" ]; then \
		readelf_bin="$(X86_READELF)"; \
	fi; \
	loader_name=""; \
	seen_paths=""; \
	candidate_matches_arch() { \
		candidate="$$(readlink -f "$$1" 2>/dev/null || true)"; \
		[ -n "$$candidate" ] || return 1; \
		[ -e "$$candidate" ] || return 1; \
		if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
			"$$readelf_bin" -h "$$candidate" 2>/dev/null | grep -q 'Class:[[:space:]]*ELF64' || return 1; \
			"$$readelf_bin" -h "$$candidate" 2>/dev/null | grep -q 'Machine:[[:space:]]*AArch64' || return 1; \
			return 0; \
		fi; \
		if [ "$(RUN_TARGET_ARCH)" = "x86_64" ]; then \
			"$$readelf_bin" -h "$$candidate" 2>/dev/null | grep -q 'Class:[[:space:]]*ELF64' || return 1; \
			"$$readelf_bin" -h "$$candidate" 2>/dev/null | grep -Eq 'Machine:[[:space:]]*(Advanced Micro Devices X86-64|X86-64)' || return 1; \
			return 0; \
		fi; \
		return 0; \
	}; \
		resolve_lib() { \
			name="$$1"; \
			runtime_search_dirs="$${PORTABLE_WRAP_SEARCH_DIRS:-}"; \
		for root in $$(printf '%s' "$$runtime_search_dirs" | tr ':' ' '); do \
			[ -n "$$root" ] || continue; \
			[ -e "$$root/$$name" ] || continue; \
			candidate_matches_arch "$$root/$$name" || continue; \
			printf '%s\n' "$$root/$$name"; \
			return 0; \
		done; \
			if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
				if [ "$${name#/}" != "$$name" ] && [ -e "$(ARM64_TOOLCHAIN_ROOT)/$${name#/}" ] && candidate_matches_arch "$(ARM64_TOOLCHAIN_ROOT)/$${name#/}"; then \
					printf '%s\n' "$(ARM64_TOOLCHAIN_ROOT)/$${name#/}"; \
					return 0; \
				fi; \
				for root in "$(ARM64_TOOLCHAIN_ROOT)/usr/lib/aarch64-linux-gnu" "$(ARM64_TOOLCHAIN_ROOT)/usr/lib64" "$(ARM64_TOOLCHAIN_ROOT)/usr/lib" "$(ARM64_TOOLCHAIN_ROOT)/lib/aarch64-linux-gnu" "$(ARM64_TOOLCHAIN_ROOT)/lib64" "$(ARM64_TOOLCHAIN_ROOT)/lib"; do \
					[ -e "$$root/$$name" ] || continue; \
					candidate_matches_arch "$$root/$$name" || continue; \
					printf '%s\n' "$$root/$$name"; \
					return 0; \
				done; \
				gcc_resolved="$$( $(ARM64_GCC) -print-file-name="$$name" 2>/dev/null )"; \
				if [ -n "$$gcc_resolved" ] && [ "$$gcc_resolved" != "$$name" ] && [ -e "$$gcc_resolved" ] && candidate_matches_arch "$$gcc_resolved"; then \
					printf '%s\n' "$$gcc_resolved"; \
					return 0; \
				fi; \
				for root in "/usr/aarch64-linux-gnu/lib" "/usr/lib/aarch64-linux-gnu"; do \
					[ -e "$$root/$$name" ] || continue; \
					candidate_matches_arch "$$root/$$name" || continue; \
					printf '%s\n' "$$root/$$name"; \
					return 0; \
					done; \
					return 1; \
				fi; \
				if [ "$(RUN_TARGET_ARCH)" = "x86_64" ] && [ -d "$(X86_TOOLCHAIN_ROOT)" ]; then \
					if [ "$${name#/}" != "$$name" ] && [ -e "$(X86_TOOLCHAIN_ROOT)/$${name#/}" ] && candidate_matches_arch "$(X86_TOOLCHAIN_ROOT)/$${name#/}"; then \
						printf '%s\n' "$(X86_TOOLCHAIN_ROOT)/$${name#/}"; \
						return 0; \
					fi; \
					for root in "$(X86_TOOLCHAIN_ROOT)/usr/lib64" "$(X86_TOOLCHAIN_ROOT)/lib64" "/lib/x86_64-linux-gnu" "/usr/lib/x86_64-linux-gnu" "/lib64" "/usr/lib64"; do \
						[ -e "$$root/$$name" ] || continue; \
						candidate_matches_arch "$$root/$$name" || continue; \
						printf '%s\n' "$$root/$$name"; \
						return 0; \
					done; \
					gcc_resolved="$$( $(X86_GCC) -print-file-name="$$name" 2>/dev/null )"; \
				if [ -n "$$gcc_resolved" ] && [ "$$gcc_resolved" != "$$name" ] && [ -e "$$gcc_resolved" ] && candidate_matches_arch "$$gcc_resolved"; then \
					printf '%s\n' "$$gcc_resolved"; \
					return 0; \
				fi; \
				return 1; \
			fi; \
			if [ "$${name#/}" != "$$name" ] && [ -e "$$name" ] && candidate_matches_arch "$$name"; then \
				printf '%s\n' "$$name"; \
				return 0; \
		fi; \
		resolved="$$(ldconfig -p 2>/dev/null | awk -v so="$$name" '$$1==so {print $$NF; exit}')"; \
		candidate_matches_arch "$$resolved" || return 1; \
		[ -n "$$resolved" ] || return 1; \
		printf '%s\n' "$$resolved"; \
	}; \
	copy_binary_deps() { \
		current="$$(readlink -f "$$1")"; \
		[ -n "$$current" ] || return 0; \
		case " $$seen_paths " in \
			*" $$current "*) return 0 ;; \
		esac; \
		seen_paths="$$seen_paths $$current"; \
		interpreter="$$( "$$readelf_bin" -l "$$current" | sed -n 's/.*Requesting program interpreter: \(.*\)]/\1/p' | tr -d '[]' | head -n1 )"; \
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
		"$$readelf_bin" -d "$$current" | sed -n 's/.*Shared library: \[\(.*\)\].*/\1/p' > "$$deps_file"; \
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
			soname_value="$$( "$$readelf_bin" -d "$$resolved_real" | sed -n 's/.*Library soname: \[\(.*\)\].*/\1/p' | head -n1 )"; \
			if [ -n "$$soname_value" ] && [ "$$soname_value" != "$$resolved_name" ]; then \
				ln -sfn "$$resolved_name" "$$runtime_lib_dir/$$soname_value"; \
			fi; \
			copy_binary_deps "$$resolved_real"; \
		done < "$$deps_file"; \
		rm -f "$$deps_file"; \
	}; \
	copy_binary_deps "$$runtime_wrapper.real"; \
	[ -n "$$loader_name" ] || { echo "missing bundled loader for $$runtime_wrapper.real" >&2; exit 1; }; \
	printf '%s\n' \
		'#!/usr/bin/env bash' \
		'set -euo pipefail' \
		'script_path="$$(readlink -f "$$0")"' \
		'script_dir="$$(cd "$$(dirname "$$script_path")" && pwd)"' \
		'real_binary="$${script_path}.real"' \
		'lib_dir="$${script_dir}/../lib"' \
		'loader="$${lib_dir}/'"$$loader_name"'"' \
		'[[ -x "$$loader" ]] || { echo "portable runtime loader not found: $$loader" >&2; exit 1; }' \
		'[[ -f "$$real_binary" ]] || { echo "wrapped binary is missing: $$real_binary" >&2; exit 1; }' \
		'exec "$$loader" --library-path "$$lib_dir" "$$real_binary" "$$@"' \
		> "$$runtime_wrapper"; \
	chmod +x "$$runtime_wrapper"
endef

WORKLOAD_TOOLS_SOURCE_ROOT := $(REPOS_DIR)/workload-tools
WORKLOAD_TOOLS_BUILD_ROOT := $(ARTIFACT_ROOT)/workload-tools-build/$(RUN_TARGET_ARCH)$(BUILD_ARCH_VARIANT)
WORKLOAD_TOOLS_HOST_LUAJIT_SOURCE_ROOT := $(WORKLOAD_TOOLS_BUILD_ROOT)/host-luajit-src
WORKLOAD_TOOLS_HOST_LUAJIT_ROOT := $(WORKLOAD_TOOLS_BUILD_ROOT)/host-luajit
WORKLOAD_TOOLS_HOST_LUAJIT_BIN := $(WORKLOAD_TOOLS_HOST_LUAJIT_ROOT)/bin/luajit
X86_LIBBPF_RUNTIME_BUILD_ROOT := $(ARTIFACT_ROOT)/libbpf-runtime/x86_64/build
WORKLOAD_TOOLS_HOST_LUAJIT_SOURCE_FILES = $(shell find "$(WORKLOAD_TOOLS_SOURCE_ROOT)/sysbench/third_party/luajit/luajit" -type f -print 2>/dev/null)

$(ARM64_GCC) $(ARM64_GXX) $(ARM64_READELF):
	@test -x "$@" || { echo "missing ARM64 toolchain executable: $@" >&2; exit 1; }

$(WORKLOAD_TOOLS_HOST_LUAJIT_BIN): $(WORKLOAD_TOOLS_HOST_LUAJIT_SOURCE_FILES)
	@source_root="$(WORKLOAD_TOOLS_SOURCE_ROOT)/sysbench/third_party/luajit"; \
	build_root="$(WORKLOAD_TOOLS_HOST_LUAJIT_SOURCE_ROOT)"; \
	install_root="$(WORKLOAD_TOOLS_HOST_LUAJIT_ROOT)"; \
	mkdir -p "$$build_root" "$$install_root/bin"; \
	rsync -a --delete "$$source_root/luajit/" "$$build_root/luajit/"; \
	$(MAKE) -C "$$build_root/luajit" PREFIX="$$install_root" BUILDMODE=static install >/dev/null; \
	ln -sf "luajit-2.1.0-beta3" "$$install_root/bin/luajit"

$(ACTIVE_WORKLOAD_TOOLS_REQUIRED) &: $(WORKLOAD_TOOLS_HOST_LUAJIT_BIN) $(WORKLOAD_TOOLS_SOURCE_FILES) $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_GCC) $(ARM64_GXX) $(ARM64_READELF),$(X86_BUILD_TOOL_DEPS))
	@if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		toolchain_root="$(ARM64_TOOLCHAIN_ROOT)"; \
		cc_value="$(ARM64_GCC) --sysroot=$$toolchain_root"; \
		cxx_value="$(ARM64_GXX) --sysroot=$$toolchain_root"; \
		pkgconfig_dirs="$(ARM64_TOOLCHAIN_PKGCONFIG_DIRS)"; \
	else \
		toolchain_root="$(X86_TOOLCHAIN_ROOT)"; \
		cc_value="$(X86_GCC)"; \
		cxx_value="$(X86_GXX)"; \
		pkgconfig_dirs="$(X86_TOOLCHAIN_PKGCONFIG_DIRS)"; \
	fi; \
	build_root="$(WORKLOAD_TOOLS_BUILD_ROOT)"; \
	install_root="$(ACTIVE_WORKLOAD_TOOLS_INSTALL_ROOT)"; \
	source_root="$(WORKLOAD_TOOLS_SOURCE_ROOT)"; \
	work_root="$$build_root/src"; \
	rt_tests_src="$$work_root/rt-tests"; \
	sysbench_src="$$work_root/sysbench"; \
	wrk_src="$$work_root/wrk"; \
	wrk_luajit_root="$$build_root/wrk-luajit"; \
	host_luajit_root="$(WORKLOAD_TOOLS_HOST_LUAJIT_ROOT)"; \
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
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		$(MAKE) -C "$$rt_tests_src" -j"$(JOBS)" CC="$(ARM64_GCC)" hackbench >/dev/null; \
		cd "$$sysbench_src"; \
		PKG_CONFIG_ALLOW_CROSS=1 \
		PKG_CONFIG_SYSROOT_DIR="$$toolchain_root" \
			PKG_CONFIG_LIBDIR="$$pkgconfig_dirs" \
				CC="$(ARM64_CC)" \
				CXX="$(ARM64_CXX)" \
				AR="$(ARM64_AR)" \
				RANLIB="$(ARM64_RANLIB)" \
			CK_CONFIGURE_FLAGS="--platform=aarch64" \
			./configure --host=aarch64-linux-gnu --prefix="$$install_root" --without-mysql --without-pgsql >/dev/null; \
			$(MAKE) -j"$(JOBS)" HOST_CC="cc" CROSS="aarch64-linux-gnu-" TARGET_SYS=Linux TARGET_FLAGS="--sysroot=$$toolchain_root" >/dev/null; \
			$(MAKE) install HOST_CC="cc" CROSS="aarch64-linux-gnu-" TARGET_SYS=Linux TARGET_FLAGS="--sysroot=$$toolchain_root" >/dev/null; \
	else \
		$(MAKE) -C "$$rt_tests_src" -j"$(JOBS)" CC="$$cc_value" hackbench >/dev/null; \
		cd "$$sysbench_src"; \
		PKG_CONFIG_ALLOW_CROSS=1 \
		PKG_CONFIG_SYSROOT_DIR="$$toolchain_root" \
			PKG_CONFIG_LIBDIR="$$pkgconfig_dirs" \
			CC="$$cc_value" \
			CXX="$$cxx_value" \
			./configure --prefix="$$install_root" --without-mysql --without-pgsql >/dev/null; \
		PKG_CONFIG_ALLOW_CROSS=1 \
		PKG_CONFIG_SYSROOT_DIR="$$toolchain_root" \
			PKG_CONFIG_LIBDIR="$$pkgconfig_dirs" \
			$(MAKE) -j"$(JOBS)" CC="$$cc_value" CXX="$$cxx_value" >/dev/null; \
		PKG_CONFIG_ALLOW_CROSS=1 \
		PKG_CONFIG_SYSROOT_DIR="$$toolchain_root" \
			PKG_CONFIG_LIBDIR="$$pkgconfig_dirs" \
			$(MAKE) install CC="$$cc_value" CXX="$$cxx_value" >/dev/null; \
	fi; \
	ln -sfn "$$sysbench_src/third_party/luajit/inc" "$$wrk_luajit_root/include"; \
	ln -sfn "$$sysbench_src/third_party/luajit/lib" "$$wrk_luajit_root/lib"; \
	mkdir -p "$$wrk_src/obj"; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		PATH="$$host_luajit_root/bin:$$PATH" $(MAKE) -C "$$wrk_src" -j"$(JOBS)" \
			CC="$$cc_value" \
			WITH_LUAJIT="$$wrk_luajit_root" \
			WITH_OPENSSL="$$toolchain_root/usr" >/dev/null; \
	else \
		PATH="$$host_luajit_root/bin:$$PATH" $(MAKE) -C "$$wrk_src" -j"$(JOBS)" \
			CC="$$cc_value" \
			WITH_LUAJIT="$$wrk_luajit_root" \
			WITH_OPENSSL="$$toolchain_root/usr" >/dev/null; \
	fi; \
	test -x "$$wrk_src/wrk" || { echo "missing $(RUN_TARGET_ARCH) wrk build output: $$wrk_src/wrk" >&2; exit 1; }; \
	test -x "$$rt_tests_src/hackbench" || { echo "missing $(RUN_TARGET_ARCH) hackbench build output: $$rt_tests_src/hackbench" >&2; exit 1; }; \
	test -x "$$bin_root/sysbench" || { echo "missing $(RUN_TARGET_ARCH) sysbench install output: $$bin_root/sysbench" >&2; exit 1; }; \
		PORTABLE_WRAP_SEARCH_DIRS="$$wrk_luajit_root/lib:$$toolchain_root/usr/lib64:$$toolchain_root/lib64"; \
	$(call PORTABLE_WRAP_BINARY,$$rt_tests_src/hackbench,$$bin_root/hackbench,$$lib_root); \
	$(call PORTABLE_WRAP_BINARY,$$bin_root/sysbench,$$bin_root/sysbench,$$lib_root); \
	$(call PORTABLE_WRAP_BINARY,$$wrk_src/wrk,$$bin_root/wrk,$$lib_root); \
	for path in $(ACTIVE_WORKLOAD_TOOLS_REQUIRED); do \
		test -x "$$path"; \
	done
