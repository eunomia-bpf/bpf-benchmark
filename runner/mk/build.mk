REPOS_DIR := $(RUNNER_DIR)/repos
REPO_ARTIFACT_ROOT := $(ROOT_DIR)/.cache/repo-artifacts/$(RUN_TARGET_ARCH)
REPO_SCX_ROOT := $(REPO_ARTIFACT_ROOT)/scx
REPO_BCC_ROOT := $(REPO_ARTIFACT_ROOT)/bcc/libbpf-tools/.output
REPO_TRACEE_ROOT := $(REPO_ARTIFACT_ROOT)/tracee
REPO_TETRAGON_ROOT := $(REPO_ARTIFACT_ROOT)/tetragon
REPO_KATRAN_ROOT := $(REPO_ARTIFACT_ROOT)/katran
REPO_KERNEL_MODULES_ROOT := $(REPO_ARTIFACT_ROOT)/kernel-modules
REPO_ARTIFACT_ROOT_X86 := $(ROOT_DIR)/.cache/repo-artifacts/x86_64
REPO_ARTIFACT_ROOT_ARM64 := $(ROOT_DIR)/.cache/repo-artifacts/arm64

RUNNER_BUILD_DIR_ACTIVE := $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(RUNNER_DIR)/build-arm64,$(RUNNER_DIR)/build)
RUNNER_LIBBPF_BUILD_DIR := $(RUNNER_BUILD_DIR_ACTIVE)/vendor/libbpf
RUNNER_LIBBPF_OBJDIR := $(RUNNER_LIBBPF_BUILD_DIR)/obj
RUNNER_LIBBPF_PREFIX := $(RUNNER_LIBBPF_BUILD_DIR)/prefix
RUNNER_LIBBPF_A := $(RUNNER_LIBBPF_OBJDIR)/libbpf.a
KATRAN_X86_CACHE_ROOT := $(ARTIFACT_ROOT)/x86-host/katran
KATRAN_X86_BUILD_ROOT := $(KATRAN_X86_CACHE_ROOT)/build
KATRAN_X86_INSTALL_ROOT := $(KATRAN_X86_CACHE_ROOT)/install
KATRAN_X86_CMAKE_OVERRIDE := $(KATRAN_X86_CACHE_ROOT)/cxx-override.cmake
KATRAN_ARM64_CACHE_ROOT := $(ARTIFACT_ROOT)/arm64-host/katran
KATRAN_ARM64_BUILD_ROOT := $(KATRAN_ARM64_CACHE_ROOT)/build
KATRAN_ARM64_INSTALL_ROOT := $(KATRAN_ARM64_CACHE_ROOT)/install
KATRAN_ARM64_CMAKE_OVERRIDE := $(KATRAN_ARM64_CACHE_ROOT)/cxx-override.cmake
X86_PORTABLE_LIBBPF_ROOT := $(ARTIFACT_ROOT)/libbpf-runtime/x86_64/portable
LOCK_ROOT := $(ARTIFACT_ROOT)/locks
TRACEE_X86_BUILD_ROOT := $(ARTIFACT_ROOT)/x86_64-tracee-build
TRACEE_ARM64_BUILD_ROOT := $(ARTIFACT_ROOT)/arm64-tracee-build
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
ACTIVE_BCC_PRIMARY := $(REPO_BCC_ROOT)/capable
ACTIVE_BCC_REQUIRED := $(addprefix $(REPO_BCC_ROOT)/,$(ACTIVE_BCC_TOOLS)) $(addsuffix .bpf.o,$(addprefix $(REPO_BCC_ROOT)/,$(ACTIVE_BCC_TOOLS)))
ACTIVE_TRACEE_PRIMARY := $(REPO_TRACEE_ROOT)/bin/tracee
ACTIVE_TRACEE_REQUIRED := $(ACTIVE_TRACEE_PRIMARY) $(REPO_TRACEE_ROOT)/tracee.bpf.o $(REPO_TRACEE_ROOT)/lsm_support/kprobe_check.bpf.o $(REPO_TRACEE_ROOT)/lsm_support/lsm_check.bpf.o
ACTIVE_TETRAGON_PRIMARY := $(REPO_TETRAGON_ROOT)/bin/tetragon
ACTIVE_TETRAGON_REQUIRED := $(ACTIVE_TETRAGON_PRIMARY) $(REPO_TETRAGON_ROOT)/bpf_execve_event.o $(REPO_TETRAGON_ROOT)/bpf_generic_kprobe.o
ACTIVE_KATRAN_PRIMARY := $(REPO_KATRAN_ROOT)/bin/katran_server_grpc
ACTIVE_KATRAN_REQUIRED := $(ACTIVE_KATRAN_PRIMARY) $(REPO_KATRAN_ROOT)/balancer.bpf.o $(REPO_KATRAN_ROOT)/healthchecking_ipip.bpf.o
ACTIVE_WORKLOAD_TOOLS_PRIMARY := $(ACTIVE_WORKLOAD_TOOLS_BIN_ROOT)/hackbench
ACTIVE_WORKLOAD_TOOLS_REQUIRED := $(ACTIVE_WORKLOAD_TOOLS_BIN_ROOT)/hackbench $(ACTIVE_WORKLOAD_TOOLS_BIN_ROOT)/sysbench $(ACTIVE_WORKLOAD_TOOLS_BIN_ROOT)/wrk
DAEMON_SOURCE_FILES = $(shell find "$(ROOT_DIR)/daemon/src" -type f 2>/dev/null) $(ROOT_DIR)/daemon/Cargo.toml $(ROOT_DIR)/daemon/Cargo.lock $(ROOT_DIR)/daemon/Makefile
RUNNER_SOURCE_FILES = $(shell find "$(RUNNER_DIR)/src" "$(RUNNER_DIR)/include" -type f 2>/dev/null) $(RUNNER_DIR)/CMakeLists.txt
TEST_UNITTEST_SOURCE_FILES = $(shell find "$(ROOT_DIR)/tests/unittest" \( -path '*/build' -o -path '*/build-arm64' \) -prune -o -type f -print 2>/dev/null)
TEST_NEGATIVE_SOURCE_FILES = $(shell find "$(ROOT_DIR)/tests/negative" \( -path '*/build' -o -path '*/build-arm64' \) -prune -o -type f -print 2>/dev/null)
MICRO_PROGRAM_SOURCE_FILES = $(shell find "$(ROOT_DIR)/micro/programs" -type f \( -name '*.bpf.c' -o -name '*.h' -o -name 'Makefile' \) 2>/dev/null)
KINSN_SOURCE_FILES = $(shell find "$(ACTIVE_KINSN_MODULE_DIR)" "$(ROOT_DIR)/module/include" -type f \( -name '*.c' -o -name '*.h' -o -name 'Makefile' \) -print 2>/dev/null)
SCX_SOURCE_FILES = $(shell find "$(REPOS_DIR)/scx" \( -path '*/target' -o -path '*/.git' \) -prune -o -type f \( -name '*.rs' -o -name '*.c' -o -name '*.h' -o -name 'Cargo.toml' -o -name 'Cargo.lock' -o -name 'build.rs' \) -print 2>/dev/null)
BCC_SOURCE_FILES = $(shell find "$(REPOS_DIR)/bcc/libbpf-tools" \( -path '*/.output' -o -path '*/.git' \) -prune -o -type f -print 2>/dev/null)
TRACEE_SOURCE_FILES = $(shell find "$(REPOS_DIR)/tracee" \( -path '*/dist' -o -path '*/build' -o -path '*/.git' \) -prune -o -type f \( -name '*.go' -o -name '*.c' -o -name '*.h' -o -name '*.mk' -o -name 'Makefile' -o -name 'go.mod' -o -name 'go.sum' \) -print 2>/dev/null)
TETRAGON_SOURCE_FILES = $(shell find "$(REPOS_DIR)/tetragon" \( -path '*/bpf/objs' -o -path '*/.git' \) -prune -o -type f \( -name '*.go' -o -name '*.c' -o -name '*.h' -o -name '*.yaml' -o -name '*.mk' -o -name 'Makefile' -o -name 'go.mod' -o -name 'go.sum' \) -print 2>/dev/null)
KATRAN_SOURCE_FILES = $(shell find "$(REPOS_DIR)/katran" \( -path '*/build' -o -path '*/deps' -o -path '*/.git' \) -prune -o -type f \( -name '*.cc' -o -name '*.cpp' -o -name '*.c' -o -name '*.h' -o -name '*.hpp' -o -name '*.bpf.c' -o -name '*.sh' -o -name '*.cmake' -o -name 'CMakeLists.txt' \) -print 2>/dev/null)
WORKLOAD_TOOLS_SOURCE_FILES = $(shell find "$(WORKLOAD_TOOLS_SOURCE_ROOT)" \( -path '*/.git' -o -path '*/autom4te.cache' \) -prune -o -type f \( -name '*.c' -o -name '*.cc' -o -name '*.h' -o -name '*.lua' -o -name '*.mk' -o -name '*.am' -o -name '*.ac' -o -name 'Makefile' -o -name 'configure*' \) -print 2>/dev/null)

$(RUNNER_LIBBPF_A):
	@mkdir -p "$(RUNNER_LIBBPF_OBJDIR)" "$(RUNNER_LIBBPF_PREFIX)/include"
	$(MAKE) -C "$(ROOT_DIR)/vendor/libbpf/src" -j"$(JOBS)" BUILD_STATIC_ONLY=1 OBJDIR="$(RUNNER_LIBBPF_OBJDIR)" DESTDIR= PREFIX="$(RUNNER_LIBBPF_PREFIX)" "$(RUNNER_LIBBPF_A)" install_headers

$(X86_BUILD_DIR)/arch/x86/boot/bzImage:
	@$(MAKE) -C "$(ROOT_DIR)" --no-print-directory __kernel

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

$(REPO_KERNEL_MODULES_ROOT)/lib/modules: $(X86_BUILD_DIR)/arch/x86/boot/bzImage
	@kernel_release_file="$(X86_BUILD_DIR)/include/config/kernel.release"; \
	stage_root="$(REPO_KERNEL_MODULES_ROOT)"; \
	lock_path="$(LOCK_ROOT)/x86_64-kernel-modules.lock"; \
	mkdir -p "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	test -f "$$kernel_release_file" || { echo "missing kernel release file: $$kernel_release_file" >&2; exit 1; }; \
	kernel_release="$$(tr -d '\n' < "$$kernel_release_file")"; \
	release_root="$$stage_root/lib/modules/$$kernel_release"; \
	mkdir -p "$$stage_root"; \
	$(MAKE) --no-print-directory -C "$(KERNEL_DIR)" O="$(X86_BUILD_DIR)" INSTALL_MOD_PATH="$$stage_root" DEPMOD=true CONFIG_MODULE_SIG=n modules_install >/dev/null; \
	depmod -b "$$stage_root" "$$kernel_release" >/dev/null; \
	ln -sfn "$(X86_BUILD_DIR)" "$$release_root/build"; \
	ln -sfn "$(KERNEL_DIR)" "$$release_root/source"; \
	test -f "$$release_root/kernel/drivers/block/null_blk/null_blk.ko"; \
	test -f "$$release_root/kernel/net/sched/sch_netem.ko"

$(X86_PORTABLE_LIBBPF_ROOT)/lib/libbpf.so:
	@mkdir -p "$(X86_PORTABLE_LIBBPF_ROOT)" "$(X86_LIBBPF_RUNTIME_BUILD_ROOT)"
	@docker run --rm --platform linux/amd64 \
		-v "$(ROOT_DIR):/workspace:ro" \
		-v "$(X86_LIBBPF_RUNTIME_BUILD_ROOT):/build" \
		-v "$(X86_PORTABLE_LIBBPF_ROOT):/out" \
		amazonlinux:2023 \
		bash -lc 'set -euo pipefail; \
			dnf -y install gcc make elfutils-libelf-devel binutils >/dev/null 2>&1; \
			mkdir -p /build/obj /build/stage /out; \
			make -C /workspace/vendor/libbpf/src -j"$$(nproc)" OBJDIR=/build/obj DESTDIR=/build/stage prefix= install >/dev/null; \
			lib_dir=/build/stage/usr/lib64; \
			real_so="$$(find "$$lib_dir" -maxdepth 1 -type f -name "libbpf.so.*" | sort | tail -n1)"; \
			test -n "$$real_so"; \
			rm -rf /out/lib.tmp; \
			mkdir -p /out/lib.tmp; \
			cp -L "$$real_so" /out/lib.tmp/; \
			real_name="$$(basename "$$real_so")"; \
			soname="$$(readelf -d "$$real_so" | sed -n "s/.*Library soname: \\[\\(.*\\)\\].*/\\1/p" | head -n1)"; \
			ln -sfn "$$real_name" /out/lib.tmp/libbpf.so; \
			if [[ -n "$$soname" && "$$soname" != "$$real_name" ]]; then ln -sfn "$$real_name" "/out/lib.tmp/$$soname"; fi; \
			rm -rf /out/lib; \
			mv /out/lib.tmp /out/lib; \
			chown -R $(shell id -u):$(shell id -g) /out /build'

$(ACTIVE_LIBBPF_RUNTIME_PRIMARY): $(X86_PORTABLE_LIBBPF_ROOT)/lib/libbpf.so
	@src_root="$(X86_PORTABLE_LIBBPF_ROOT)/lib"; \
	dst_root="$(REPO_ARTIFACT_ROOT)/libbpf/lib"; \
	mkdir -p "$$dst_root"; \
	find "$$src_root" -maxdepth 1 \( -type f -o -type l \) | while read -r src; do \
		[ -e "$$src" ] || continue; \
		dst="$$dst_root/$${src##*/}"; \
		rm -f "$$dst"; \
		cp -a "$$src" "$$dst"; \
	done

$(REPO_SCX_ROOT)/bin/%: $(SCX_SOURCE_FILES) $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_GCC) $(ARM64_GXX) $(ARM64_READELF))
	@package="$*"; \
	repo_root="$(REPOS_DIR)/scx"; \
	corpus_root="$(REPO_SCX_ROOT)"; \
	bin_root="$$corpus_root/bin"; \
	lock_path="$(LOCK_ROOT)/$(RUN_TARGET_ARCH)-scx.lock"; \
	mkdir -p "$$bin_root" "$$corpus_root" "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		target_release_dir="$$repo_root/target/aarch64-unknown-linux-gnu/release"; \
		PKG_CONFIG_ALLOW_CROSS=1 \
		PKG_CONFIG_SYSROOT_DIR="$(ARM64_TOOLCHAIN_ROOT)" \
		PKG_CONFIG_LIBDIR="$(ARM64_TOOLCHAIN_PKGCONFIG_DIRS)" \
		LIBRARY_PATH="$(ARM64_TOOLCHAIN_LIBRARY_DIRS)" \
		LD_LIBRARY_PATH="$(ARM64_TOOLCHAIN_LIBRARY_DIRS)" \
		BINDGEN_EXTRA_CLANG_ARGS_aarch64_unknown_linux_gnu="--sysroot=$(ARM64_TOOLCHAIN_ROOT) $(foreach dir,$(subst :, ,$(ARM64_TOOLCHAIN_INCLUDE_DIRS)),-I$(dir))" \
		CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER="$(ARM64_GCC)" \
		CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_RUSTFLAGS="-Clink-arg=--sysroot=$(ARM64_TOOLCHAIN_ROOT) $(foreach dir,$(subst :, ,$(ARM64_TOOLCHAIN_LIBRARY_DIRS)),-Clink-arg=-L$(dir))" \
		CC_aarch64_unknown_linux_gnu="$(ARM64_CC)" \
		CXX_aarch64_unknown_linux_gnu="$(ARM64_CXX)" \
		AR_aarch64_unknown_linux_gnu="$(ARM64_AR)" \
		RANLIB_aarch64_unknown_linux_gnu="$(ARM64_RANLIB)" \
		cargo build --release --target "aarch64-unknown-linux-gnu" --manifest-path "$$repo_root/Cargo.toml" --package "$$package"; \
		test -x "$$target_release_dir/$$package"; \
		cp -f "$$target_release_dir/$$package" "$@"; \
		object_path="$$(find "$$target_release_dir/build" -path "*/$$package-*/out/main.bpf.o" | sort | tail -n1)"; \
	else \
		target_release_dir="$$repo_root/target/release"; \
		cargo build --release --manifest-path "$$repo_root/Cargo.toml" --package "$$package"; \
		test -x "$$target_release_dir/$$package"; \
		cp -f "$$target_release_dir/$$package" "$@"; \
		object_path="$$(find "$$target_release_dir/build" -path "*/$$package-*/out/main.bpf.o" | sort | tail -n1)"; \
	fi; \
	test -n "$$object_path"; \
	obj_dst="$$corpus_root/$${package}_main.bpf.o"; \
	cp -f "$$object_path" "$$obj_dst"

$(REPO_SCX_ROOT)/%_main.bpf.o: $(REPO_SCX_ROOT)/bin/%
	@test -f "$@"

$(ACTIVE_BCC_PRIMARY): $(BCC_SOURCE_FILES)
	@repo_root="$(REPOS_DIR)/bcc/libbpf-tools"; \
	stage_root="$(REPO_BCC_ROOT)"; \
	lock_path="$(LOCK_ROOT)/$(RUN_TARGET_ARCH)-bcc.lock"; \
	mkdir -p "$$stage_root" "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	bpftool_cmd="$(ROOT_DIR)/vendor/linux-framework/tools/bpf/bpftool/bpftool"; \
	test -x "$$bpftool_cmd" || { echo "missing vendored bpftool build output: $$bpftool_cmd" >&2; exit 1; }; \
	make_args='LIBBPF_SRC="$(ROOT_DIR)/vendor/libbpf/src" BPFTOOL="'"$$bpftool_cmd"'" USE_BLAZESYM=0'; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		make_args="$$make_args ARCH=arm64 CROSS_COMPILE=$(CROSS_COMPILE_ARM64) CC=\"$(ARM64_CC)\" LD=\"$(ARM64_HOST_CROSS_PREFIX)ld\""; \
	fi; \
	eval $(MAKE) -C "\"$$repo_root\"" -j"$(JOBS)" $$make_args; \
	find "$$repo_root/.output" -maxdepth 1 -type f -name '*.bpf.o' | while read -r src; do \
		dst="$$stage_root/$${src##*/}"; \
		cp -f "$$src" "$$dst"; \
	done; \
	for obj in "$$repo_root"/.output/*.bpf.o; do \
		[ -f "$$obj" ] || continue; \
		tool_name="$${obj##*/}"; \
		tool_name="$${tool_name%.bpf.o}"; \
		if [ -x "$$repo_root/$$tool_name" ]; then \
			dst="$$stage_root/$$tool_name"; \
			cp -f "$$repo_root/$$tool_name" "$$dst"; \
		fi; \
	done

$(filter-out $(ACTIVE_BCC_PRIMARY),$(ACTIVE_BCC_REQUIRED)): $(ACTIVE_BCC_PRIMARY)
	@test -e "$@"

$(ACTIVE_TRACEE_PRIMARY): $(TRACEE_SOURCE_FILES)
	@repo_root="$(REPOS_DIR)/tracee"; \
	stage_root="$(REPO_TRACEE_ROOT)"; \
	lock_path="$(LOCK_ROOT)/tracee.lock"; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		build_root="$(TRACEE_ARM64_BUILD_ROOT)"; \
		output_root="$$build_root/dist"; \
		goenv_mk="$$build_root/goenv.mk"; \
		mkdir -p "$$stage_root/bin" "$$stage_root/lsm_support" "$$build_root" "$(LOCK_ROOT)"; \
		exec 9>"$$lock_path"; flock 9; \
		rm -f "$$repo_root/.build_libbpf" "$$repo_root/.build_libbpf_fix" "$$repo_root/.eval_goenv" "$$repo_root/.checklib_libbpf" "$$repo_root/goenv.mk"; \
		docker build -t "$(ARM64_CROSSBUILD_IMAGE)" -f "$(RUNNER_DIR)/docker/arm64-crossbuild.Dockerfile" "$(ROOT_DIR)"; \
		docker run --rm --platform linux/arm64 \
			-v "$(ROOT_DIR):$(ROOT_DIR)" \
			-w "$$repo_root" \
			"$(ARM64_CROSSBUILD_IMAGE)" \
			make -j"$(JOBS)" OUTPUT_DIR="$$output_root" GOENV_MK="$$goenv_mk" GOOS=linux GOARCH=arm64 GO_ARCH=arm64 bpf tracee; \
	else \
		build_root="$(TRACEE_X86_BUILD_ROOT)"; \
		output_root="$$build_root/dist"; \
		goenv_mk="$$build_root/goenv.mk"; \
		mkdir -p "$$stage_root/bin" "$$stage_root/lsm_support" "$$build_root" "$(LOCK_ROOT)"; \
		exec 9>"$$lock_path"; flock 9; \
		rm -f "$$repo_root/.build_libbpf" "$$repo_root/.build_libbpf_fix" "$$repo_root/.eval_goenv" "$$repo_root/.checklib_libbpf" "$$repo_root/goenv.mk"; \
		$(MAKE) -C "$$repo_root" -j"$(JOBS)" OUTPUT_DIR="$$output_root" GOENV_MK="$$goenv_mk" GOOS=linux GOARCH=amd64 GO_ARCH=amd64 bpf tracee; \
	fi; \
	cp -f "$$output_root/tracee.bpf.o" "$(REPO_TRACEE_ROOT)/tracee.bpf.o"; \
	find "$$output_root/lsm_support" -maxdepth 1 -type f -name '*.bpf.o' | while read -r src; do \
		dst="$(REPO_TRACEE_ROOT)/lsm_support/$${src##*/}"; \
		cp -f "$$src" "$$dst"; \
	done; \
	cp -f "$$output_root/tracee" "$@"

$(filter-out $(ACTIVE_TRACEE_PRIMARY),$(ACTIVE_TRACEE_REQUIRED)): $(ACTIVE_TRACEE_PRIMARY)
	@test -e "$@"

$(ACTIVE_TETRAGON_PRIMARY): $(TETRAGON_SOURCE_FILES)
	@repo_root="$(REPOS_DIR)/tetragon"; \
	stage_root="$(REPO_TETRAGON_ROOT)"; \
	target_arch="$$( [ "$(RUN_TARGET_ARCH)" = "arm64" ] && printf 'arm64' || printf 'amd64' )"; \
	lock_path="$(LOCK_ROOT)/$(RUN_TARGET_ARCH)-tetragon.lock"; \
	mkdir -p "$$stage_root/bin" "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	$(MAKE) -C "$$repo_root" -j"$(JOBS)" TARGET_ARCH="$$target_arch" LOCAL_CLANG=1 tetragon-bpf; \
	$(MAKE) -C "$$repo_root" -j"$(JOBS)" TARGET_ARCH="$$target_arch" tetragon EXTRA_GO_BUILD_FLAGS=-mod=mod; \
	find "$$repo_root/bpf/objs" -maxdepth 1 -type f -name '*.o' | while read -r src; do \
		dst="$$stage_root/$${src##*/}"; \
		cp -f "$$src" "$$dst"; \
	done; \
	cp -f "$$repo_root/tetragon" "$@"

$(filter-out $(ACTIVE_TETRAGON_PRIMARY),$(ACTIVE_TETRAGON_REQUIRED)): $(ACTIVE_TETRAGON_PRIMARY)
	@test -e "$@"

$(ACTIVE_KATRAN_PRIMARY): $(KATRAN_SOURCE_FILES)
	@stage_root="$(REPO_KATRAN_ROOT)"; \
	lock_path="$(LOCK_ROOT)/$(RUN_TARGET_ARCH)-katran.lock"; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		build_root="$(KATRAN_ARM64_BUILD_ROOT)"; \
		install_root="$(KATRAN_ARM64_INSTALL_ROOT)"; \
		override_file="$(KATRAN_ARM64_CMAKE_OVERRIDE)"; \
	else \
		build_root="$(KATRAN_X86_BUILD_ROOT)"; \
		install_root="$(KATRAN_X86_INSTALL_ROOT)"; \
		override_file="$(KATRAN_X86_CMAKE_OVERRIDE)"; \
	fi; \
	folly_xlog_prefixes="-DFOLLY_XLOG_STRIP_PREFIXES=\\\\\\\"$$build_root/deps/folly:$$build_root/deps/folly/build\\\\\\\""; \
	mkdir -p "$$stage_root/bin" "$$stage_root/lib" "$$build_root" "$$install_root" "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	printf '%s\n' 'set(CMAKE_CXX_COMPILE_OBJECT "<CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS> -std=gnu++20 -o <OBJECT> -c <SOURCE>")' > "$$override_file"; \
	cd "$(REPOS_DIR)/katran" && \
	env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR \
	CC=clang CXX=clang++ CXXFLAGS="$$folly_xlog_prefixes" BUILD_EXAMPLE_GRPC=1 BUILD_DIR="$$build_root" INSTALL_DIR="$$install_root" INSTALL_DEPS_ONLY=1 ./build_katran.sh; \
	mkdir -p "$$install_root/grpc/_build"; \
	ln -sfn "$$install_root/bin/grpc_cpp_plugin" "$$install_root/grpc/_build/grpc_cpp_plugin"; \
	cd "$(REPOS_DIR)/katran" && \
	env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR CMAKE_BUILD_EXAMPLE_GRPC=1 \
	CC=clang CXX=clang++ \
	cmake -S . -B "$$build_root/build" \
		-DCMAKE_PREFIX_PATH="$$install_root" \
		-DCMAKE_INSTALL_PREFIX="$$install_root" \
		-DCMAKE_BUILD_TYPE=RelWithDebInfo \
		-DPKG_CONFIG_USE_CMAKE_PREFIX_PATH=ON \
		-DLIB_BPF_PREFIX="$$install_root" \
		-DCMAKE_CXX_STANDARD=20 \
		-DCMAKE_USER_MAKE_RULES_OVERRIDE_CXX="$$override_file" \
		-DBUILD_TESTS=OFF; \
	cmake --build "$$build_root/build" --target katran_server_grpc -j"$(JOBS)"; \
	cd "$(REPOS_DIR)/katran" && ./build_bpf_modules_opensource.sh -s "$(REPOS_DIR)/katran" -b "$$build_root"; \
	cp -f "$$build_root/build/example_grpc/katran_server_grpc" "$@"; \
	for src in \
		"$$build_root/deps/bpfprog/bpf/balancer.bpf.o" \
		"$$build_root/deps/bpfprog/bpf/healthchecking_ipip.o" \
		"$$build_root/deps/bpfprog/bpf/healthchecking.bpf.o" \
		"$$build_root/deps/bpfprog/bpf/xdp_pktcntr.o" \
		"$$build_root/deps/bpfprog/bpf/xdp_root.o"; do \
		dst_name="$${src##*/}"; \
		case "$$dst_name" in \
			healthchecking_ipip.o) dst_name="healthchecking_ipip.bpf.o" ;; \
		esac; \
		dst="$$stage_root/$$dst_name"; \
		cp -f "$$src" "$$dst"; \
	done; \
	find "$$install_root/lib" -maxdepth 1 -type f | while read -r src; do \
		dst="$$stage_root/lib/$${src##*/}"; \
		cp -f "$$src" "$$dst"; \
	done

$(filter-out $(ACTIVE_KATRAN_PRIMARY),$(ACTIVE_KATRAN_REQUIRED)): $(ACTIVE_KATRAN_PRIMARY)
	@test -e "$@"

ARM64_TOOLCHAIN_ROOT := $(RUNNER_DIR)/build-arm64/toolchain
ARM64_TOOLCHAIN_BIN := $(ARM64_TOOLCHAIN_ROOT)/bin
ARM64_TOOLCHAIN_PKGCONFIG_DIRS := $(ARM64_TOOLCHAIN_ROOT)/usr/lib/aarch64-linux-gnu/pkgconfig:$(ARM64_TOOLCHAIN_ROOT)/usr/lib/pkgconfig:$(ARM64_TOOLCHAIN_ROOT)/usr/lib64/pkgconfig:$(ARM64_TOOLCHAIN_ROOT)/usr/share/pkgconfig
ARM64_TOOLCHAIN_LIBRARY_DIRS := $(ARM64_TOOLCHAIN_ROOT)/usr/lib/aarch64-linux-gnu:$(ARM64_TOOLCHAIN_ROOT)/usr/lib:$(ARM64_TOOLCHAIN_ROOT)/lib/aarch64-linux-gnu:$(ARM64_TOOLCHAIN_ROOT)/lib
ARM64_TOOLCHAIN_INCLUDE_DIRS := $(ARM64_TOOLCHAIN_ROOT)/usr/include:$(ARM64_TOOLCHAIN_ROOT)/usr/include/aarch64-linux-gnu
ARM64_HOST_CROSS_PREFIX := $(ARM64_TOOLCHAIN_BIN)/$(CROSS_COMPILE_ARM64)
ARM64_CROSS_PREFIX ?= $(CROSS_COMPILE_ARM64)
ARM64_GCC := $(ARM64_HOST_CROSS_PREFIX)gcc
ARM64_GXX := $(ARM64_HOST_CROSS_PREFIX)g++
ARM64_AR := $(ARM64_HOST_CROSS_PREFIX)ar
ARM64_RANLIB := $(ARM64_HOST_CROSS_PREFIX)ranlib
ARM64_READELF := $(ARM64_HOST_CROSS_PREFIX)readelf
ARM64_CC := $(ARM64_GCC) --sysroot=$(ARM64_TOOLCHAIN_ROOT)
ARM64_CXX := $(ARM64_GXX) --sysroot=$(ARM64_TOOLCHAIN_ROOT)
WORKLOAD_TOOLS_SOURCE_ROOT := $(REPOS_DIR)/workload-tools
WORKLOAD_TOOLS_BUILD_ROOT := $(ARTIFACT_ROOT)/workload-tools-build
WORKLOAD_TOOLS_INSTALL_ROOT := $(ARTIFACT_ROOT)/workload-tools
WORKLOAD_TOOLS_HOST_BUILD_ROOT := $(WORKLOAD_TOOLS_BUILD_ROOT)/host
WORKLOAD_TOOLS_X86_BUILD_ROOT := $(WORKLOAD_TOOLS_BUILD_ROOT)/x86_64
WORKLOAD_TOOLS_ARM64_BUILD_ROOT := $(WORKLOAD_TOOLS_BUILD_ROOT)/arm64
WORKLOAD_TOOLS_HOST_LUAJIT_ROOT := $(WORKLOAD_TOOLS_HOST_BUILD_ROOT)/luajit
WORKLOAD_TOOLS_HOST_LUAJIT_BIN := $(WORKLOAD_TOOLS_HOST_LUAJIT_ROOT)/bin/luajit
X86_LIBBPF_RUNTIME_BUILD_ROOT := $(ARTIFACT_ROOT)/libbpf-runtime/x86_64/build
WORKLOAD_TOOLS_HOST_LUAJIT_SOURCE_FILES = $(shell find "$(WORKLOAD_TOOLS_SOURCE_ROOT)/sysbench/third_party/luajit/luajit" -type f -print 2>/dev/null)

$(ARM64_GCC) $(ARM64_GXX) $(ARM64_READELF):
	@test -x "$@" || { echo "missing ARM64 toolchain executable: $@" >&2; exit 1; }

$(WORKLOAD_TOOLS_HOST_LUAJIT_BIN): $(WORKLOAD_TOOLS_HOST_LUAJIT_SOURCE_FILES)
	@source_root="$(WORKLOAD_TOOLS_SOURCE_ROOT)/sysbench/third_party/luajit"; \
	build_root="$(WORKLOAD_TOOLS_HOST_BUILD_ROOT)/luajit-src"; \
	install_root="$(WORKLOAD_TOOLS_HOST_LUAJIT_ROOT)"; \
	lock_path="$(LOCK_ROOT)/host-luajit.lock"; \
	mkdir -p "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	rm -rf "$$build_root/luajit" "$$install_root"; \
	mkdir -p "$$build_root"; \
	cp -a "$$source_root/luajit" "$$build_root/luajit"; \
	$(MAKE) -C "$$build_root/luajit" PREFIX="$$install_root" BUILDMODE=static install >/dev/null; \
	mkdir -p "$$install_root/bin"; \
	ln -sf "luajit-2.1.0-beta3" "$$install_root/bin/luajit"

$(ACTIVE_WORKLOAD_TOOLS_PRIMARY): $(WORKLOAD_TOOLS_HOST_LUAJIT_BIN) $(WORKLOAD_TOOLS_SOURCE_FILES) $(if $(filter arm64,$(RUN_TARGET_ARCH)),$(ARM64_GCC) $(ARM64_GXX) $(ARM64_READELF))
	@if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		build_root="$(WORKLOAD_TOOLS_ARM64_BUILD_ROOT)"; \
		install_root="$(ACTIVE_WORKLOAD_TOOLS_INSTALL_ROOT)"; \
		toolchain_root="$(ARM64_TOOLCHAIN_ROOT)"; \
		lock_path="$(LOCK_ROOT)/arm64-workload-tools.lock"; \
		cc_value="$(ARM64_GCC) --sysroot=$$toolchain_root"; \
	else \
		build_root="$(WORKLOAD_TOOLS_X86_BUILD_ROOT)"; \
		install_root="$(ACTIVE_WORKLOAD_TOOLS_INSTALL_ROOT)"; \
		toolchain_root=""; \
		lock_path="$(LOCK_ROOT)/x86_64-workload-tools.lock"; \
		cc_value="cc"; \
	fi; \
	source_root="$(WORKLOAD_TOOLS_SOURCE_ROOT)"; \
	work_root="$$build_root/src"; \
	rt_tests_src="$$work_root/rt-tests"; \
	sysbench_src="$$work_root/sysbench"; \
	wrk_src="$$work_root/wrk"; \
	wrk_luajit_root="$$build_root/wrk-luajit"; \
	host_luajit_root="$(WORKLOAD_TOOLS_HOST_LUAJIT_ROOT)"; \
	bin_root="$$install_root/bin"; \
	lib_root="$$install_root/lib"; \
	mkdir -p "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	test -d "$$source_root/rt-tests" || { echo "missing workload tool source root: $$source_root/rt-tests" >&2; exit 1; }; \
	test -d "$$source_root/sysbench" || { echo "missing workload tool source root: $$source_root/sysbench" >&2; exit 1; }; \
	test -d "$$source_root/wrk" || { echo "missing workload tool source root: $$source_root/wrk" >&2; exit 1; }; \
	rm -rf "$$work_root" "$$build_root/sysbench-install" "$$wrk_luajit_root" "$$install_root"; \
	mkdir -p "$$work_root" "$$build_root/sysbench-install" "$$wrk_luajit_root" "$$bin_root" "$$lib_root"; \
	cp -a "$$source_root/rt-tests" "$$rt_tests_src"; \
	cp -a "$$source_root/sysbench" "$$sysbench_src"; \
	cp -a "$$source_root/wrk" "$$wrk_src"; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		$(MAKE) -C "$$rt_tests_src" -j"$(JOBS)" CC="$(ARM64_GCC)" hackbench >/dev/null; \
		cd "$$sysbench_src"; \
		PKG_CONFIG_ALLOW_CROSS=1 \
		PKG_CONFIG_SYSROOT_DIR="$$toolchain_root" \
		PKG_CONFIG_LIBDIR="$(ARM64_TOOLCHAIN_PKGCONFIG_DIRS)" \
			CC="$(ARM64_CC)" \
			CXX="$(ARM64_CXX)" \
			AR="$(ARM64_AR)" \
			RANLIB="$(ARM64_RANLIB)" \
		CK_CONFIGURE_FLAGS="--platform=aarch64" \
		./configure --host=aarch64-linux-gnu --prefix="$$build_root/sysbench-install" --without-mysql --without-pgsql >/dev/null; \
		$(MAKE) -j"$(JOBS)" HOST_CC="cc" CROSS="aarch64-linux-gnu-" TARGET_SYS=Linux TARGET_FLAGS="--sysroot=$$toolchain_root" >/dev/null; \
		$(MAKE) install HOST_CC="cc" CROSS="aarch64-linux-gnu-" TARGET_SYS=Linux TARGET_FLAGS="--sysroot=$$toolchain_root" >/dev/null; \
	else \
		$(MAKE) -C "$$rt_tests_src" -j"$(JOBS)" CC="cc" hackbench >/dev/null; \
		cd "$$sysbench_src"; \
		./configure --prefix="$$build_root/sysbench-install" --without-mysql --without-pgsql >/dev/null; \
		$(MAKE) -j"$(JOBS)" >/dev/null; \
		$(MAKE) install >/dev/null; \
	fi; \
	ln -sfn "$$sysbench_src/third_party/luajit/inc" "$$wrk_luajit_root/include"; \
	ln -sfn "$$sysbench_src/third_party/luajit/lib" "$$wrk_luajit_root/lib"; \
	rm -f "$$wrk_src/wrk"; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		PATH="$$host_luajit_root/bin:$$PATH" $(MAKE) -C "$$wrk_src" -j"$(JOBS)" \
			CC="$$cc_value" \
			WITH_LUAJIT="$$wrk_luajit_root" \
			WITH_OPENSSL="$$toolchain_root/usr" >/dev/null; \
	else \
		PATH="$$host_luajit_root/bin:$$PATH" $(MAKE) -C "$$wrk_src" -j"$(JOBS)" \
			CC="$$cc_value" \
			WITH_LUAJIT="$$wrk_luajit_root" >/dev/null; \
	fi; \
	test -x "$$wrk_src/wrk" || { echo "missing $(RUN_TARGET_ARCH) wrk build output: $$wrk_src/wrk" >&2; exit 1; }; \
	cp -f "$$rt_tests_src/hackbench" "$$bin_root/hackbench.real"; \
	cp -f "$$build_root/sysbench-install/bin/sysbench" "$$bin_root/sysbench.real"; \
	cp -f "$$wrk_src/wrk" "$$bin_root/wrk.real"; \
	if [ "$(RUN_TARGET_ARCH)" = "arm64" ]; then \
		copy_dep() { \
			local soname="$$1"; \
			for root in "$$wrk_luajit_root/lib" "$$toolchain_root/usr/lib/aarch64-linux-gnu" "$$toolchain_root/usr/lib"; do \
				[ -f "$$root/$$soname" ] || continue; \
				cp -Lf "$$root/$$soname" "$$lib_root/$$soname"; \
				return 0; \
			done; \
			for tool in aarch64-linux-gnu-gcc aarch64-linux-gnu-g++; do \
				local resolved; \
				resolved="$$( $$tool -print-file-name="$$soname" 2>/dev/null || true )"; \
				[ -n "$$resolved" ] || continue; \
				[ "$$resolved" = "$$soname" ] && continue; \
				[ -f "$$resolved" ] || continue; \
				cp -Lf "$$resolved" "$$lib_root/$$soname"; \
				return 0; \
			done; \
			echo "missing arm64 runtime library: $$soname" >&2; \
			exit 1; \
		}; \
		for tool in hackbench sysbench wrk; do \
			$(ARM64_READELF) -d "$$bin_root/$$tool.real" | sed -n "s/.*Shared library: \\[\\(.*\\)\\]/\\1/p" | while read -r soname; do \
				[ -n "$$soname" ] || continue; \
				copy_dep "$$soname"; \
			done; \
		done; \
		copy_dep ld-linux-aarch64.so.1; \
		loader_name="ld-linux-aarch64.so.1"; \
	else \
		copy_dep() { \
			local requested="$$1"; \
			local soname="$$requested"; \
			local resolved=""; \
			if [[ "$$requested" == /* ]]; then \
				resolved="$$requested"; \
				soname="$${requested##*/}"; \
			else \
				resolved="$$(ldconfig -p 2>/dev/null | awk -v so="$$soname" '$$1==so {path=$$NF} END {if (path) print path}')"; \
			fi; \
			[ -n "$$resolved" ] || { echo "missing x86 runtime library: $$requested" >&2; exit 1; }; \
			cp -Lf "$$resolved" "$$lib_root/$$soname"; \
		}; \
		for tool in hackbench sysbench wrk; do \
			while read -r soname; do \
				[ -n "$$soname" ] || continue; \
				copy_dep "$$soname"; \
			done < <(ldd "$$bin_root/$$tool.real" | awk '/=>/ {print $$1} /ld-linux/ {print $$1}'); \
		done; \
		copy_dep ld-linux-x86-64.so.2; \
		loader_name="ld-linux-x86-64.so.2"; \
	fi; \
	for tool in hackbench sysbench wrk; do \
		printf "%s\n" \
			'#!/usr/bin/env bash' \
			'set -euo pipefail' \
			'script_path="$$(readlink -f "$$0")"' \
			'script_dir="$$(cd "$$(dirname "$$script_path")" && pwd)"' \
			'real_binary="$${script_path}.real"' \
			"loader=\"\${script_dir}/../lib/$$loader_name\"" \
			'[[ -x "$$loader" ]] || { echo "portable runtime loader not found for $$script_path" >&2; exit 1; }' \
			'[[ -f "$$real_binary" ]] || { echo "wrapped binary is missing for $$script_path: $$real_binary" >&2; exit 1; }' \
			'exec "$$loader" --library-path "$${script_dir}/../lib" "$$real_binary" "$$@"' \
			> "$$bin_root/$$tool"; \
		chmod +x "$$bin_root/$$tool"; \
	done

$(filter-out $(ACTIVE_WORKLOAD_TOOLS_PRIMARY),$(ACTIVE_WORKLOAD_TOOLS_REQUIRED)): $(ACTIVE_WORKLOAD_TOOLS_PRIMARY)
	@test -x "$@"
