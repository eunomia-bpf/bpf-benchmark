REPOS_DIR := $(RUNNER_DIR)/repos
REPO_ARTIFACT_ROOT := $(ROOT_DIR)/$(RUN_REPO_ARTIFACT_ROOT)
REPO_SCX_ROOT := $(REPO_ARTIFACT_ROOT)/scx
REPO_BCC_ROOT := $(REPO_ARTIFACT_ROOT)/bcc/libbpf-tools/.output
REPO_TRACEE_ROOT := $(REPO_ARTIFACT_ROOT)/tracee
REPO_TETRAGON_ROOT := $(REPO_ARTIFACT_ROOT)/tetragon
REPO_KATRAN_ROOT := $(REPO_ARTIFACT_ROOT)/katran
REPO_KERNEL_MODULES_ROOT := $(REPO_ARTIFACT_ROOT)/kernel-modules

RUNNER_LIBBPF_BUILD_DIR := $(RUNNER_BUILD_DIR)/vendor/libbpf
RUNNER_LIBBPF_OBJDIR := $(RUNNER_LIBBPF_BUILD_DIR)/obj
RUNNER_LIBBPF_PREFIX := $(RUNNER_LIBBPF_BUILD_DIR)/prefix
RUNNER_LIBBPF_A := $(RUNNER_LIBBPF_OBJDIR)/libbpf.a
KATRAN_X86_CACHE_ROOT := $(ARTIFACT_ROOT)/x86-host/katran
KATRAN_X86_BUILD_ROOT := $(KATRAN_X86_CACHE_ROOT)/build
KATRAN_X86_INSTALL_ROOT := $(KATRAN_X86_CACHE_ROOT)/install
KATRAN_ARM64_CACHE_ROOT := $(ARTIFACT_ROOT)/arm64-host/katran
KATRAN_ARM64_BUILD_ROOT := $(KATRAN_ARM64_CACHE_ROOT)/build
KATRAN_ARM64_INSTALL_ROOT := $(KATRAN_ARM64_CACHE_ROOT)/install
X86_PORTABLE_LIBBPF_ROOT := $(ARTIFACT_ROOT)/libbpf-runtime/x86_64/portable
X86_PORTABLE_LIBBPF_STAMP := $(X86_PORTABLE_LIBBPF_ROOT)/.ready
X86_PORTABLE_LIBBPF_SOURCE_INPUTS := $(shell find "$(ROOT_DIR)/vendor/libbpf/src" "$(ROOT_DIR)/vendor/libbpf/include" -type f ! -path '*/.git/*' 2>/dev/null | sort)
ARM64_CROSSBUILD_STAMP := $(ARTIFACT_ROOT)/arm64-host/crossbuild-image.stamp
LOCK_ROOT := $(ARTIFACT_ROOT)/locks

.PHONY: __arm64-crossbuild-image \
	__daemon-binary-x86_64 __daemon-binary-arm64 \
	__runner-binary-x86_64 __runner-binary-arm64 __runner-binary-arm64-inner \
	__kernel-modules-x86_64 \
	__kinsn-modules-x86_64 __kinsn-modules-arm64 \
	__repo-test-binaries-x86_64 __repo-test-binaries-arm64 \
	__micro-programs \
	__x86-portable-libbpf \
	__scx-binaries-x86_64 __scx-binaries-arm64 __scx-binaries-arm64-inner \
	__native-repos-x86_64 __native-repos-arm64 __native-repos-arm64-inner \
	__native-repo-bcc __native-repo-tracee __native-repo-tetragon \
	__native-repo-katran-x86_64 __native-repo-katran-arm64

__arm64-crossbuild-image:
	@mkdir -p "$(dir $(ARM64_CROSSBUILD_STAMP))"
	@if [ ! -f "$(ARM64_CROSSBUILD_STAMP)" ] || [ "$(RUNNER_DIR)/docker/arm64-crossbuild.Dockerfile" -nt "$(ARM64_CROSSBUILD_STAMP)" ]; then \
		docker build -t "$(ARM64_CROSSBUILD_IMAGE)" -f "$(RUNNER_DIR)/docker/arm64-crossbuild.Dockerfile" "$(ROOT_DIR)" && \
		touch "$(ARM64_CROSSBUILD_STAMP)"; \
	else \
		docker image inspect "$(ARM64_CROSSBUILD_IMAGE)" >/dev/null 2>&1 || \
			( docker build -t "$(ARM64_CROSSBUILD_IMAGE)" -f "$(RUNNER_DIR)/docker/arm64-crossbuild.Dockerfile" "$(ROOT_DIR)" && touch "$(ARM64_CROSSBUILD_STAMP)" ); \
	fi

__daemon-binary-x86_64:
	@$(MAKE) -C "$(ROOT_DIR)/daemon" release TARGET_DIR="$(DAEMON_DIR)/target"

__daemon-binary-arm64:
	@$(MAKE) -C "$(ROOT_DIR)/daemon" release TARGET_DIR="$(DAEMON_DIR)/target" TARGET_TRIPLE="aarch64-unknown-linux-gnu"

__runner-binary-x86_64: $(RUNNER_LIBBPF_A)
	@cmake_args='-S "$(RUNNER_DIR)" -B "$(RUNNER_BUILD_DIR)" -DCMAKE_BUILD_TYPE=Release -DMICRO_REPO_ROOT="$(ROOT_DIR)" -DMICRO_LIBBPF_PREFIX="$(RUNNER_LIBBPF_PREFIX)" -DMICRO_LIBBPF_LIBRARY="$(RUNNER_LIBBPF_A)" -DMICRO_EXEC_ENABLE_LLVMBPF="$(RUN_SUITE_NEEDS_LLVMBPF)"'; \
	if [ -n "$(LLVM_DIR)" ]; then cmake_args="$$cmake_args -DLLVM_DIR=$(LLVM_DIR)"; fi; \
	eval cmake $$cmake_args; \
	cmake --build "$(RUNNER_BUILD_DIR)" --target micro_exec -j"$(JOBS)"

__runner-binary-arm64: __arm64-crossbuild-image
	@docker run --rm --platform linux/arm64 \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ARM64_CROSSBUILD_IMAGE)" \
		make --no-print-directory __runner-binary-arm64-inner \
			ROOT_DIR="$(ROOT_DIR)" \
			RUNNER_DIR="$(RUNNER_DIR)" \
			RUNNER_BUILD_DIR="$(RUNNER_BUILD_DIR)" \
			JOBS="$(JOBS)" \
			RUN_SUITE_NEEDS_LLVMBPF="$(RUN_SUITE_NEEDS_LLVMBPF)" \
			LLVM_DIR="$(LLVM_DIR)"

__runner-binary-arm64-inner: $(RUNNER_LIBBPF_A)
	@cmake_args='-S "$(RUNNER_DIR)" -B "$(RUNNER_BUILD_DIR)" -DCMAKE_BUILD_TYPE=Release -DMICRO_REPO_ROOT="$(ROOT_DIR)" -DMICRO_LIBBPF_PREFIX="$(RUNNER_LIBBPF_PREFIX)" -DMICRO_LIBBPF_LIBRARY="$(RUNNER_LIBBPF_A)" -DMICRO_EXEC_ENABLE_LLVMBPF="$(RUN_SUITE_NEEDS_LLVMBPF)"'; \
	if [ -n "$(LLVM_DIR)" ]; then cmake_args="$$cmake_args -DLLVM_DIR=$(LLVM_DIR)"; fi; \
	eval cmake $$cmake_args; \
	cmake --build "$(RUNNER_BUILD_DIR)" --target micro_exec -j"$(JOBS)"

$(RUNNER_LIBBPF_A):
	@mkdir -p "$(RUNNER_LIBBPF_OBJDIR)" "$(RUNNER_LIBBPF_PREFIX)/include"
	$(MAKE) -C "$(ROOT_DIR)/vendor/libbpf/src" -j"$(JOBS)" BUILD_STATIC_ONLY=1 OBJDIR="$(RUNNER_LIBBPF_OBJDIR)" DESTDIR= PREFIX="$(RUNNER_LIBBPF_PREFIX)" "$(RUNNER_LIBBPF_A)" install_headers

__kinsn-modules-x86_64:
	@module_dir="$(ROOT_DIR)/module/x86"; \
		$(MAKE) -C "$(ROOT_DIR)" --no-print-directory __kernel; \
		$(MAKE) -C "$(KERNEL_DIR)" O="$(X86_BUILD_DIR)" M="$$module_dir" modules

__kinsn-modules-arm64:
	@module_dir="$(ROOT_DIR)/module/arm64"; \
		$(MAKE) -C "$(ROOT_DIR)" --no-print-directory __kernel-arm64-aws ARM64_AWS_BASE_CONFIG="$(ARM64_AWS_BASE_CONFIG)"; \
		$(MAKE) -C "$(KERNEL_DIR)" O="$(ARM64_AWS_BUILD_DIR)" ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)" M="$$module_dir" modules

__kernel-modules-x86_64:
	@kernel_release_file="$(X86_BUILD_DIR)/include/config/kernel.release"; \
	stage_root="$(REPO_KERNEL_MODULES_ROOT)"; \
	lock_path="$(LOCK_ROOT)/x86_64-kernel-modules.lock"; \
	mkdir -p "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	$(MAKE) -C "$(ROOT_DIR)" --no-print-directory __kernel; \
	test -f "$$kernel_release_file" || { echo "missing kernel release file: $$kernel_release_file" >&2; exit 1; }; \
	kernel_release="$$(tr -d '\n' < "$$kernel_release_file")"; \
	release_root="$$stage_root/lib/modules/$$kernel_release"; \
	ready_stamp="$$stage_root/.ready"; \
	if [ -f "$$ready_stamp" ] && \
		[ "$$ready_stamp" -nt "$(X86_BUILD_DIR)/modules.order" ] && \
		[ -f "$$release_root/kernel/drivers/block/null_blk/null_blk.ko" ] && \
		[ -f "$$release_root/kernel/net/sched/sch_netem.ko" ]; then \
		exit 0; \
	fi; \
	rm -rf "$$stage_root"; \
	mkdir -p "$$stage_root"; \
	$(MAKE) --no-print-directory -C "$(KERNEL_DIR)" O="$(X86_BUILD_DIR)" INSTALL_MOD_PATH="$$stage_root" DEPMOD=true CONFIG_MODULE_SIG=n modules_install >/dev/null; \
	rm -f "$$release_root/build" "$$release_root/source"; \
	test -f "$$release_root/kernel/drivers/block/null_blk/null_blk.ko"; \
	test -f "$$release_root/kernel/net/sched/sch_netem.ko"; \
	touch "$$ready_stamp"

__repo-test-binaries-x86_64:
	@mkdir -p "$(ROOT_DIR)/tests/unittest/build" "$(ROOT_DIR)/tests/unittest/build/vendor/bpftool" "$(ROOT_DIR)/tests/negative/build"
	@$(MAKE) -C "$(ROOT_DIR)/tests/unittest" BUILD_DIR="$(ROOT_DIR)/tests/unittest/build"
	@$(MAKE) -C "$(ROOT_DIR)/tests/negative" BUILD_DIR="$(ROOT_DIR)/tests/negative/build"

__repo-test-binaries-arm64:
	@mkdir -p "$(ROOT_DIR)/tests/unittest/build-arm64" "$(ROOT_DIR)/tests/unittest/build-arm64/vendor/bpftool" "$(ROOT_DIR)/tests/negative/build-arm64"
	@$(MAKE) -C "$(ROOT_DIR)/tests/unittest" BUILD_DIR="$(ROOT_DIR)/tests/unittest/build-arm64" CC="aarch64-linux-gnu-gcc" CLANG="clang"
	@$(MAKE) -C "$(ROOT_DIR)/tests/negative" BUILD_DIR="$(ROOT_DIR)/tests/negative/build-arm64" CC="aarch64-linux-gnu-gcc"

__micro-programs:
	@$(MAKE) -C "$(ROOT_DIR)/micro/programs" OUTPUT_DIR="$(ROOT_DIR)/micro/programs"

__x86-portable-libbpf: $(X86_PORTABLE_LIBBPF_STAMP)

$(X86_PORTABLE_LIBBPF_STAMP): $(X86_PORTABLE_LIBBPF_SOURCE_INPUTS)
	@mkdir -p "$(X86_PORTABLE_LIBBPF_ROOT)"
	@docker run --rm --platform linux/amd64 \
		-v "$(ROOT_DIR):/workspace:ro" \
		-v "$(X86_PORTABLE_LIBBPF_ROOT):/out" \
		amazonlinux:2023 \
		bash -lc 'set -euo pipefail; \
			dnf -y install gcc make elfutils-libelf-devel binutils >/dev/null 2>&1; \
			rm -rf /tmp/libbpf-obj /tmp/libbpf-stage /out/lib; \
			mkdir -p /out/lib; \
			make -C /workspace/vendor/libbpf/src -j"$$(nproc)" OBJDIR=/tmp/libbpf-obj DESTDIR=/tmp/libbpf-stage prefix= install >/dev/null; \
			lib_dir=/tmp/libbpf-stage/usr/lib64; \
			real_so="$$(find "$$lib_dir" -maxdepth 1 -type f -name "libbpf.so.*" | sort | tail -n1)"; \
			test -n "$$real_so"; \
			cp -L "$$real_so" /out/lib/; \
			real_name="$$(basename "$$real_so")"; \
			soname="$$(readelf -d "$$real_so" | sed -n "s/.*Library soname: \\[\\(.*\\)\\].*/\\1/p" | head -n1)"; \
			if [[ -n "$$soname" && "$$soname" != "$$real_name" ]]; then ln -sfn "$$real_name" "/out/lib/$$soname"; fi; \
			chown -R $(shell id -u):$(shell id -g) /out'
	@touch "$@"

__scx-binaries-x86_64:
	@test -n "$(RUN_SCX_PACKAGES_CSV)" || { echo "RUN_SCX_PACKAGES_CSV is required" >&2; exit 1; }
	@repo_root="$(REPOS_DIR)/scx"; \
	corpus_root="$(REPO_SCX_ROOT)"; \
	bin_root="$$corpus_root/bin"; \
	lock_path="$(LOCK_ROOT)/x86_64-scx.lock"; \
	mkdir -p "$$bin_root" "$$corpus_root" "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	for package in $$(printf '%s' "$(RUN_SCX_PACKAGES_CSV)" | tr ',' ' '); do \
		[ -n "$$package" ] || continue; \
		cargo build --release --manifest-path "$$repo_root/Cargo.toml" --package "$$package"; \
		test -x "$$repo_root/target/release/$$package"; \
		dst="$$bin_root/$$package"; \
		if ! cmp -s "$$repo_root/target/release/$$package" "$$dst" 2>/dev/null; then cp -f "$$repo_root/target/release/$$package" "$$dst"; fi; \
		object_path="$$(find "$$repo_root/target/release/build" -path "*/$$package-*/out/main.bpf.o" | sort | tail -n1)"; \
		test -n "$$object_path"; \
		obj_dst="$$corpus_root/$${package}_main.bpf.o"; \
		if ! cmp -s "$$object_path" "$$obj_dst" 2>/dev/null; then cp -f "$$object_path" "$$obj_dst"; fi; \
	done

__scx-binaries-arm64: __require-arm64-toolchain __scx-binaries-arm64-inner

__scx-binaries-arm64-inner:
	@test -n "$(RUN_SCX_PACKAGES_CSV)" || { echo "RUN_SCX_PACKAGES_CSV is required" >&2; exit 1; }
	@repo_root="$(REPOS_DIR)/scx"; \
	corpus_root="$(REPO_SCX_ROOT)"; \
	bin_root="$$corpus_root/bin"; \
	target_release_dir="$$repo_root/target/aarch64-unknown-linux-gnu/release"; \
	lock_path="$(LOCK_ROOT)/arm64-scx.lock"; \
	mkdir -p "$$bin_root" "$$corpus_root" "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	for package in $$(printf '%s' "$(RUN_SCX_PACKAGES_CSV)" | tr ',' ' '); do \
		[ -n "$$package" ] || continue; \
		CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER="$(ARM64_GCC)" \
		CC_aarch64_unknown_linux_gnu="$(ARM64_GCC)" \
		CXX_aarch64_unknown_linux_gnu="$(ARM64_GXX)" \
		AR_aarch64_unknown_linux_gnu="$(ARM64_AR)" \
		RANLIB_aarch64_unknown_linux_gnu="$(ARM64_RANLIB)" \
		cargo build --release --target "aarch64-unknown-linux-gnu" --manifest-path "$$repo_root/Cargo.toml" --package "$$package"; \
		test -x "$$target_release_dir/$$package"; \
		dst="$$bin_root/$$package"; \
		if ! cmp -s "$$target_release_dir/$$package" "$$dst" 2>/dev/null; then cp -f "$$target_release_dir/$$package" "$$dst"; fi; \
		object_path="$$(find "$$target_release_dir/build" -path "*/$$package-*/out/main.bpf.o" | sort | tail -n1)"; \
		test -n "$$object_path"; \
		obj_dst="$$corpus_root/$${package}_main.bpf.o"; \
		if ! cmp -s "$$object_path" "$$obj_dst" 2>/dev/null; then cp -f "$$object_path" "$$obj_dst"; fi; \
	done

__native-repos-x86_64:
	@test -n "$(RUN_NATIVE_REPOS_CSV)" || { echo "RUN_NATIVE_REPOS_CSV is required" >&2; exit 1; }
	@for repo in $$(printf '%s' "$(RUN_NATIVE_REPOS_CSV)" | tr ',' ' '); do \
		[ -n "$$repo" ] || continue; \
		repo_target="__native-repo-$$repo"; \
		if [ "$$repo" = "katran" ]; then repo_target="__native-repo-katran-x86_64"; fi; \
		$(MAKE) --no-print-directory "$$repo_target"; \
	done

__native-repos-arm64: __require-arm64-toolchain __native-repos-arm64-inner

__native-repos-arm64-inner:
	@test -n "$(RUN_NATIVE_REPOS_CSV)" || { echo "RUN_NATIVE_REPOS_CSV is required" >&2; exit 1; }
	@for repo in $$(printf '%s' "$(RUN_NATIVE_REPOS_CSV)" | tr ',' ' '); do \
		[ -n "$$repo" ] || continue; \
		repo_target="__native-repo-$$repo"; \
		if [ "$$repo" = "katran" ]; then repo_target="__native-repo-katran-arm64"; fi; \
		$(MAKE) --no-print-directory "$$repo_target"; \
	done

__native-repo-bcc:
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
		if ! cmp -s "$$src" "$$dst" 2>/dev/null; then cp -f "$$src" "$$dst"; fi; \
	done; \
	for obj in "$$repo_root"/.output/*.bpf.o; do \
		[ -f "$$obj" ] || continue; \
		tool_name="$${obj##*/}"; \
		tool_name="$${tool_name%.bpf.o}"; \
		if [ -x "$$repo_root/$$tool_name" ]; then \
			dst="$$stage_root/$$tool_name"; \
			if ! cmp -s "$$repo_root/$$tool_name" "$$dst" 2>/dev/null; then cp -f "$$repo_root/$$tool_name" "$$dst"; fi; \
		fi; \
	done

__native-repo-tracee:
	@repo_root="$(REPOS_DIR)/tracee"; \
	stage_root="$(REPO_TRACEE_ROOT)"; \
	go_arch="$$( [ "$(RUN_TARGET_ARCH)" = "arm64" ] && printf 'arm64' || printf 'amd64' )"; \
	lock_path="$(LOCK_ROOT)/$(RUN_TARGET_ARCH)-tracee.lock"; \
	mkdir -p "$$stage_root/bin" "$$stage_root/lsm_support" "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	rm -f "$$repo_root/goenv.mk"; \
	$(MAKE) -C "$$repo_root" -j"$(JOBS)" GO_ARCH="$$go_arch" bpf tracee evt traceectl lsm-check; \
	if ! cmp -s "$$repo_root/dist/tracee.bpf.o" "$$stage_root/tracee.bpf.o" 2>/dev/null; then cp -f "$$repo_root/dist/tracee.bpf.o" "$$stage_root/tracee.bpf.o"; fi; \
	find "$$repo_root/dist/lsm_support" -maxdepth 1 -type f -name '*.bpf.o' | while read -r src; do \
		dst="$$stage_root/lsm_support/$${src##*/}"; \
		if ! cmp -s "$$src" "$$dst" 2>/dev/null; then cp -f "$$src" "$$dst"; fi; \
	done; \
	for bin in tracee evt traceectl lsm-check; do \
		test -x "$$repo_root/dist/$$bin"; \
		dst="$$stage_root/bin/$$bin"; \
		if ! cmp -s "$$repo_root/dist/$$bin" "$$dst" 2>/dev/null; then cp -f "$$repo_root/dist/$$bin" "$$dst"; fi; \
	done

__native-repo-tetragon:
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
		if ! cmp -s "$$src" "$$dst" 2>/dev/null; then cp -f "$$src" "$$dst"; fi; \
	done; \
	test -x "$$repo_root/tetragon"; \
	if ! cmp -s "$$repo_root/tetragon" "$$stage_root/bin/tetragon" 2>/dev/null; then cp -f "$$repo_root/tetragon" "$$stage_root/bin/tetragon"; fi

__native-repo-katran-x86_64:
	@stage_root="$(REPO_KATRAN_ROOT)"; \
		build_root="$(KATRAN_X86_BUILD_ROOT)"; \
		install_root="$(KATRAN_X86_INSTALL_ROOT)"; \
		folly_xlog_prefixes="-DFOLLY_XLOG_STRIP_PREFIXES=\\\\\\\"$$build_root/deps/folly:$$build_root/deps/folly/build\\\\\\\""; \
		lock_path="$(LOCK_ROOT)/x86_64-katran.lock"; \
		mkdir -p "$$stage_root/bin" "$$stage_root/lib" "$$build_root" "$$install_root" "$(LOCK_ROOT)"; \
		exec 9>"$$lock_path"; flock 9; \
		cd "$(REPOS_DIR)/katran" && \
		env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR \
		CC=clang CXX=clang++ CXXFLAGS="$$folly_xlog_prefixes" BUILD_EXAMPLE_GRPC=1 BUILD_DIR="$$build_root" INSTALL_DIR="$$install_root" ./build_katran.sh; \
		if ! cmp -s "$$build_root/build/example_grpc/katran_server_grpc" "$$stage_root/bin/katran_server_grpc" 2>/dev/null; then cp -f "$$build_root/build/example_grpc/katran_server_grpc" "$$stage_root/bin/katran_server_grpc"; fi; \
	for src in \
		"$$install_root/bpfprog/bpf/balancer.bpf.o" \
		"$$install_root/bpfprog/bpf/healthchecking_ipip.o" \
		"$$install_root/bpfprog/bpf/healthchecking.bpf.o" \
		"$$install_root/bpfprog/bpf/xdp_pktcntr.o" \
		"$$install_root/bpfprog/bpf/xdp_root.o"; do \
		dst_name="$${src##*/}"; \
		case "$$dst_name" in \
			healthchecking_ipip.o) dst_name="healthchecking_ipip.bpf.o" ;; \
		esac; \
		dst="$$stage_root/$$dst_name"; \
		if ! cmp -s "$$src" "$$dst" 2>/dev/null; then cp -f "$$src" "$$dst"; fi; \
	done; \
	find "$$install_root/lib" -maxdepth 1 -type f | while read -r src; do \
		dst="$$stage_root/lib/$${src##*/}"; \
		if ! cmp -s "$$src" "$$dst" 2>/dev/null; then cp -f "$$src" "$$dst"; fi; \
	done

__native-repo-katran-arm64:
	@stage_root="$(REPO_KATRAN_ROOT)"; \
		build_root="$(KATRAN_ARM64_BUILD_ROOT)"; \
		install_root="$(KATRAN_ARM64_INSTALL_ROOT)"; \
		folly_xlog_prefixes="-DFOLLY_XLOG_STRIP_PREFIXES=\\\\\\\"$$build_root/deps/folly:$$build_root/deps/folly/build\\\\\\\""; \
		lock_path="$(LOCK_ROOT)/arm64-katran.lock"; \
		mkdir -p "$$stage_root/bin" "$$stage_root/lib" "$$build_root" "$$install_root" "$(LOCK_ROOT)"; \
		exec 9>"$$lock_path"; flock 9; \
		cd "$(REPOS_DIR)/katran" && \
		env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR \
		CC=clang CXX=clang++ CXXFLAGS="$$folly_xlog_prefixes" BUILD_EXAMPLE_GRPC=1 BUILD_DIR="$$build_root" INSTALL_DIR="$$install_root" ./build_katran.sh; \
		if ! cmp -s "$$build_root/build/example_grpc/katran_server_grpc" "$$stage_root/bin/katran_server_grpc" 2>/dev/null; then cp -f "$$build_root/build/example_grpc/katran_server_grpc" "$$stage_root/bin/katran_server_grpc"; fi; \
	for src in \
		"$$install_root/bpfprog/bpf/balancer.bpf.o" \
		"$$install_root/bpfprog/bpf/healthchecking_ipip.o" \
		"$$install_root/bpfprog/bpf/healthchecking.bpf.o" \
		"$$install_root/bpfprog/bpf/xdp_pktcntr.o" \
		"$$install_root/bpfprog/bpf/xdp_root.o"; do \
		dst_name="$${src##*/}"; \
		case "$$dst_name" in \
			healthchecking_ipip.o) dst_name="healthchecking_ipip.bpf.o" ;; \
		esac; \
		dst="$$stage_root/$$dst_name"; \
		if ! cmp -s "$$src" "$$dst" 2>/dev/null; then cp -f "$$src" "$$dst"; fi; \
	done; \
	find "$$install_root/lib" -maxdepth 1 -type f | while read -r src; do \
		dst="$$stage_root/lib/$${src##*/}"; \
		if ! cmp -s "$$src" "$$dst" 2>/dev/null; then cp -f "$$src" "$$dst"; fi; \
	done

ARM64_TOOLCHAIN_ROOT := $(RUNNER_DIR)/build-arm64/toolchain
ARM64_TOOLCHAIN_BIN := $(ARM64_TOOLCHAIN_ROOT)/bin
ARM64_TOOLCHAIN_PKGCONFIG_DIRS := $(ARM64_TOOLCHAIN_ROOT)/usr/lib64/pkgconfig:$(ARM64_TOOLCHAIN_ROOT)/usr/share/pkgconfig
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
WORKLOAD_TOOLS_BUILD_RULES := $(RUNNER_DIR)/mk/build.mk
WORKLOAD_TOOLS_HOST_BUILD_ROOT := $(WORKLOAD_TOOLS_BUILD_ROOT)/host
WORKLOAD_TOOLS_X86_BUILD_ROOT := $(WORKLOAD_TOOLS_BUILD_ROOT)/x86_64
WORKLOAD_TOOLS_ARM64_BUILD_ROOT := $(WORKLOAD_TOOLS_BUILD_ROOT)/arm64
WORKLOAD_TOOLS_HOST_LUAJIT_ROOT := $(WORKLOAD_TOOLS_HOST_BUILD_ROOT)/luajit
WORKLOAD_TOOLS_HOST_LUAJIT_BIN := $(WORKLOAD_TOOLS_HOST_LUAJIT_ROOT)/bin/luajit
WORKLOAD_TOOLS_X86_INSTALL_STAMP := $(WORKLOAD_TOOLS_INSTALL_ROOT)/x86_64/.ready
WORKLOAD_TOOLS_ARM64_INSTALL_STAMP := $(WORKLOAD_TOOLS_INSTALL_ROOT)/arm64/.ready
WORKLOAD_TOOLS_SOURCE_INPUTS := $(shell find "$(WORKLOAD_TOOLS_SOURCE_ROOT)/rt-tests" "$(WORKLOAD_TOOLS_SOURCE_ROOT)/sysbench" "$(WORKLOAD_TOOLS_SOURCE_ROOT)/wrk" -type f ! -path '*/.git/*' 2>/dev/null | sort)
X86_LIBBPF_RUNTIME_BUILD_ROOT := $(ARTIFACT_ROOT)/libbpf-runtime/x86_64/build
ARM64_LIBBPF_RUNTIME_BUILD_ROOT := $(ARTIFACT_ROOT)/libbpf-runtime/arm64/build

.PHONY: __workload-tools-x86_64 __workload-tools-arm64 __libbpf-runtime-x86_64 __libbpf-runtime-arm64 __require-arm64-toolchain

__require-arm64-toolchain:
	@test -x "$(ARM64_GCC)" || { echo "missing ARM64 cross gcc: $(ARM64_GCC)" >&2; exit 1; }
	@test -x "$(ARM64_GXX)" || { echo "missing ARM64 cross g++: $(ARM64_GXX)" >&2; exit 1; }
	@test -x "$(ARM64_READELF)" || { echo "missing ARM64 readelf: $(ARM64_READELF)" >&2; exit 1; }

__libbpf-runtime-x86_64: __x86-portable-libbpf
	@src_root="$(X86_PORTABLE_LIBBPF_ROOT)/lib"; \
	dst_root="$(REPO_ARTIFACT_ROOT)/libbpf/lib"; \
	mkdir -p "$$dst_root"; \
	find "$$src_root" -maxdepth 1 -type f -o -type l | while read -r src; do \
		[ -e "$$src" ] || continue; \
		dst="$$dst_root/$${src##*/}"; \
		if ! cmp -s "$$src" "$$dst" 2>/dev/null; then cp -a "$$src" "$$dst"; fi; \
	done

__libbpf-runtime-arm64: __require-arm64-toolchain
	@build_root="$(ARM64_LIBBPF_RUNTIME_BUILD_ROOT)"; \
		dst_root="$(REPO_ARTIFACT_ROOT)/libbpf"; \
		obj_root="$$build_root/obj"; \
		mkdir -p "$$obj_root" "$$dst_root"; \
		$(MAKE) -C "$(ROOT_DIR)/vendor/libbpf/src" -j"$(JOBS)" \
			OBJDIR="$$obj_root" \
			DESTDIR= \
			PREFIX="$$dst_root" \
			LIBDIR="$$dst_root/lib" \
			INCLUDEDIR="$$dst_root/include" \
			CC="$(ARM64_CC)" \
			AR="$(ARM64_AR)" \
			RANLIB="$(ARM64_RANLIB)" \
			BUILD_STATIC_ONLY=0 install >/dev/null; \
		test -f "$$dst_root/lib/libbpf.so" -o -f "$$dst_root/lib/libbpf.so."* -o -f "$$dst_root/lib64/libbpf.so" -o -f "$$dst_root/lib64/libbpf.so."*

__workload-tools-x86_64: $(WORKLOAD_TOOLS_X86_INSTALL_STAMP)

$(WORKLOAD_TOOLS_X86_INSTALL_STAMP): $(WORKLOAD_TOOLS_SOURCE_INPUTS) $(WORKLOAD_TOOLS_BUILD_RULES)
	@source_root="$(WORKLOAD_TOOLS_SOURCE_ROOT)"; \
	build_root="$(WORKLOAD_TOOLS_X86_BUILD_ROOT)"; \
	work_root="$$build_root/src"; \
	rt_tests_src="$$work_root/rt-tests"; \
	sysbench_src="$$work_root/sysbench"; \
	wrk_src="$$work_root/wrk"; \
	wrk_luajit_root="$$build_root/wrk-luajit"; \
	host_luajit_root="$(WORKLOAD_TOOLS_HOST_LUAJIT_ROOT)"; \
	install_root="$(WORKLOAD_TOOLS_INSTALL_ROOT)/x86_64"; \
	bin_root="$$install_root/bin"; \
	lib_root="$$install_root/lib"; \
	lock_path="$(LOCK_ROOT)/x86_64-workload-tools.lock"; \
	mkdir -p "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	test -d "$$source_root/rt-tests" || { echo "missing workload tool source root: $$source_root/rt-tests" >&2; exit 1; }; \
	test -d "$$source_root/sysbench" || { echo "missing workload tool source root: $$source_root/sysbench" >&2; exit 1; }; \
	test -d "$$source_root/wrk" || { echo "missing workload tool source root: $$source_root/wrk" >&2; exit 1; }; \
	rm -rf "$$work_root"; \
	mkdir -p "$$work_root"; \
	cp -a "$$source_root/rt-tests" "$$rt_tests_src"; \
	cp -a "$$source_root/sysbench" "$$sysbench_src"; \
	cp -a "$$source_root/wrk" "$$wrk_src"; \
	rm -rf "$$rt_tests_src/bld"; \
	$(MAKE) -C "$$sysbench_src" distclean >/dev/null 2>&1 || true; \
	rm -rf "$$build_root/sysbench-install" "$$wrk_luajit_root"; \
	$(MAKE) -C "$$rt_tests_src" -j"$(JOBS)" CC="cc" hackbench >/dev/null; \
	cd "$$sysbench_src"; \
	./configure --prefix="$$build_root/sysbench-install" --without-mysql --without-pgsql >/dev/null; \
	$(MAKE) -j"$(JOBS)" >/dev/null; \
	$(MAKE) install >/dev/null; \
	mkdir -p "$$wrk_luajit_root"; \
	ln -sfn "$$sysbench_src/third_party/luajit/inc" "$$wrk_luajit_root/include"; \
	ln -sfn "$$sysbench_src/third_party/luajit/lib" "$$wrk_luajit_root/lib"; \
	rm -f "$$wrk_src/wrk"; \
	PATH="$$host_luajit_root/bin:$$PATH" $(MAKE) -C "$$wrk_src" -j"$(JOBS)" \
		CC="cc" \
		WITH_LUAJIT="$$wrk_luajit_root" >/dev/null; \
	test -x "$$wrk_src/wrk" || { echo "missing x86 wrk build output: $$wrk_src/wrk" >&2; exit 1; }; \
	rm -rf "$$install_root"; \
	mkdir -p "$$bin_root" "$$lib_root"; \
	cp -f "$$rt_tests_src/hackbench" "$$bin_root/hackbench.real"; \
	cp -f "$$build_root/sysbench-install/bin/sysbench" "$$bin_root/sysbench.real"; \
	cp -f "$$wrk_src/wrk" "$$bin_root/wrk.real"; \
		copy_x86_dep() { \
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
			copy_x86_dep "$$soname"; \
		done < <(ldd "$$bin_root/$$tool.real" | awk '/=>/ {print $$1} /ld-linux/ {print $$1}'); \
	done; \
	copy_x86_dep ld-linux-x86-64.so.2; \
	for tool in hackbench sysbench wrk; do \
		printf "%s\n" \
			'#!/usr/bin/env bash' \
			'set -euo pipefail' \
			'script_path="$$(readlink -f "$$0")"' \
			'script_dir="$$(cd "$$(dirname "$$script_path")" && pwd)"' \
			'real_binary="${script_path}.real"' \
			'loader="${script_dir}/../lib/ld-linux-x86-64.so.2"' \
			'[[ -x "$$loader" ]] || { echo "portable runtime loader not found for $$script_path" >&2; exit 1; }' \
			'[[ -f "$$real_binary" ]] || { echo "wrapped binary is missing for $$script_path: $$real_binary" >&2; exit 1; }' \
			'exec "$$loader" --library-path "${script_dir}/../lib" "$$real_binary" "$$@"' \
			> "$$bin_root/$$tool"; \
		chmod +x "$$bin_root/$$tool"; \
	done; \
	touch "$@"

$(WORKLOAD_TOOLS_HOST_LUAJIT_BIN): $(WORKLOAD_TOOLS_SOURCE_ROOT)/sysbench/third_party/luajit/luajit/src/Makefile $(WORKLOAD_TOOLS_BUILD_RULES)
	@source_root="$(WORKLOAD_TOOLS_SOURCE_ROOT)/sysbench/third_party/luajit"; \
	build_root="$(WORKLOAD_TOOLS_HOST_BUILD_ROOT)/luajit-src"; \
	install_root="$(WORKLOAD_TOOLS_HOST_LUAJIT_ROOT)"; \
	lock_path="$(LOCK_ROOT)/host-luajit.lock"; \
	mkdir -p "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	rm -rf "$$build_root" "$$install_root"; \
	mkdir -p "$$build_root"; \
	tar -C "$$source_root" -cf - luajit | tar -xf - -C "$$build_root"; \
	$(MAKE) -C "$$build_root/luajit" PREFIX="$$install_root" BUILDMODE=static install >/dev/null; \
	ln -sf "luajit-2.1.0-beta3" "$$install_root/bin/luajit"

__workload-tools-arm64: $(WORKLOAD_TOOLS_ARM64_INSTALL_STAMP)

$(WORKLOAD_TOOLS_ARM64_INSTALL_STAMP): __require-arm64-toolchain $(WORKLOAD_TOOLS_HOST_LUAJIT_BIN) $(WORKLOAD_TOOLS_SOURCE_INPUTS) $(WORKLOAD_TOOLS_BUILD_RULES)
	@source_root="$(WORKLOAD_TOOLS_SOURCE_ROOT)"; \
	build_root="$(WORKLOAD_TOOLS_ARM64_BUILD_ROOT)"; \
	work_root="$$build_root/src"; \
	rt_tests_src="$$work_root/rt-tests"; \
	sysbench_src="$$work_root/sysbench"; \
	wrk_src="$$work_root/wrk"; \
	wrk_luajit_root="$$build_root/wrk-luajit"; \
	host_luajit_root="$(WORKLOAD_TOOLS_HOST_LUAJIT_ROOT)"; \
	install_root="$(WORKLOAD_TOOLS_INSTALL_ROOT)/arm64"; \
	bin_root="$$install_root/bin"; \
	lib_root="$$install_root/lib"; \
	toolchain_root="$(ARM64_TOOLCHAIN_ROOT)"; \
	lock_path="$(LOCK_ROOT)/arm64-workload-tools.lock"; \
	mkdir -p "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	test -d "$$source_root/rt-tests" || { echo "missing workload tool source root: $$source_root/rt-tests" >&2; exit 1; }; \
	test -d "$$source_root/sysbench" || { echo "missing workload tool source root: $$source_root/sysbench" >&2; exit 1; }; \
	test -d "$$source_root/wrk" || { echo "missing workload tool source root: $$source_root/wrk" >&2; exit 1; }; \
	rm -rf "$$work_root"; \
	mkdir -p "$$work_root"; \
	cp -a "$$source_root/rt-tests" "$$rt_tests_src"; \
	cp -a "$$source_root/sysbench" "$$sysbench_src"; \
	cp -a "$$source_root/wrk" "$$wrk_src"; \
	rm -rf "$$rt_tests_src/bld"; \
	$(MAKE) -C "$$sysbench_src" distclean >/dev/null 2>&1 || true; \
	rm -rf "$$build_root/sysbench-install" "$$wrk_luajit_root"; \
	$(MAKE) -C "$$rt_tests_src" -j"$(JOBS)" CC="$(ARM64_GCC)" hackbench; \
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
	mkdir -p "$$wrk_luajit_root"; \
	ln -sfn "$$sysbench_src/third_party/luajit/inc" "$$wrk_luajit_root/include"; \
	ln -sfn "$$sysbench_src/third_party/luajit/lib" "$$wrk_luajit_root/lib"; \
	rm -f "$$wrk_src/wrk"; \
	PATH="$$host_luajit_root/bin:$$PATH" $(MAKE) -C "$$wrk_src" -j"$(JOBS)" \
		CC="$(ARM64_GCC) --sysroot=$$toolchain_root" \
		WITH_LUAJIT="$$wrk_luajit_root" \
		WITH_OPENSSL="$$toolchain_root/usr"; \
	test -x "$$wrk_src/wrk" || { echo "missing arm64 wrk build output: $$wrk_src/wrk" >&2; exit 1; }; \
	rm -rf "$$install_root"; \
	mkdir -p "$$bin_root" "$$lib_root"; \
	cp -f "$$rt_tests_src/hackbench" "$$bin_root/hackbench.real"; \
	cp -f "$$build_root/sysbench-install/bin/sysbench" "$$bin_root/sysbench.real"; \
	cp -f "$$wrk_src/wrk" "$$bin_root/wrk.real"; \
	copy_arm_dep() { \
		local soname="$$1"; \
		shift; \
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
			copy_arm_dep "$$soname"; \
		done; \
	done; \
	copy_arm_dep ld-linux-aarch64.so.1; \
	for tool in hackbench sysbench wrk; do \
		printf "%s\n" \
			'#!/usr/bin/env bash' \
			'set -euo pipefail' \
			'script_path="$$(readlink -f "$$0")"' \
			'script_dir="$$(cd "$$(dirname "$$script_path")" && pwd)"' \
			'real_binary="${script_path}.real"' \
			'loader="${script_dir}/../lib/ld-linux-aarch64.so.1"' \
			'[[ -x "$$loader" ]] || { echo "portable runtime loader not found for $$script_path" >&2; exit 1; }' \
			'[[ -f "$$real_binary" ]] || { echo "wrapped binary is missing for $$script_path: $$real_binary" >&2; exit 1; }' \
			'exec "$$loader" --library-path "${script_dir}/../lib" "$$real_binary" "$$@"' \
			> "$$bin_root/$$tool"; \
		chmod +x "$$bin_root/$$tool"; \
	done; \
	touch "$@"
