REPOS_DIR := $(RUNNER_DIR)/repos
KATRAN_HELPER_ROOT := $(ROOT_DIR)/e2e/cases/katran

RUNNER_LIBBPF_BUILD_DIR := $(RUNNER_BUILD_DIR)/vendor/libbpf
RUNNER_LIBBPF_OBJDIR := $(RUNNER_LIBBPF_BUILD_DIR)/obj
RUNNER_LIBBPF_PREFIX := $(RUNNER_LIBBPF_BUILD_DIR)/prefix
RUNNER_LIBBPF_A := $(RUNNER_LIBBPF_OBJDIR)/libbpf.a
KATRAN_HELPER_BIN := $(KATRAN_HELPER_ROOT)/bin/katran_server_grpc
KATRAN_HELPER_BPF := $(KATRAN_HELPER_ROOT)/bin/balancer.bpf.o
KATRAN_ARM64_CACHE_ROOT := $(ARTIFACT_ROOT)/arm64-host/katran
KATRAN_ARM64_BUILD_ROOT := $(KATRAN_ARM64_CACHE_ROOT)/build
KATRAN_ARM64_INSTALL_ROOT := $(KATRAN_ARM64_CACHE_ROOT)/install
ARM64_CROSSBUILD_STAMP := $(ARTIFACT_ROOT)/arm64-host/crossbuild-image.stamp
LOCK_ROOT := $(ARTIFACT_ROOT)/locks

.PHONY: __arm64-crossbuild-image \
	__daemon-binary-x86_64 __daemon-binary-arm64 \
	__runner-binary-x86_64 __runner-binary-arm64 __runner-binary-arm64-inner \
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
	$(MAKE) -C "$$module_dir" KDIR="$(ROOT_DIR)/vendor/linux-framework"

__kinsn-modules-arm64:
	@module_dir="$(ROOT_DIR)/module/arm64"; \
	$(MAKE) -C "$(ROOT_DIR)" --no-print-directory __kernel-arm64-aws; \
	$(MAKE) -C "$$module_dir" KDIR="$(ARM64_AWS_BUILD_DIR)" ARCH=arm64 CROSS_COMPILE="$(CROSS_COMPILE_ARM64)"

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

__x86-portable-libbpf:
	@docker run --rm \
		-v "$(ROOT_DIR):/workspace:ro" \
		-v "$(RUNNER_DIR)/build/x86-portable-libbpf:/out" \
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
			if [[ -n "$$soname" && "$$soname" != "$$real_name" ]]; then ln -sfn "$$real_name" "/out/lib/$$soname"; fi'

__scx-binaries-x86_64:
	@test -n "$(RUN_SCX_PACKAGES_CSV)" || { echo "RUN_SCX_PACKAGES_CSV is required" >&2; exit 1; }
	@repo_root="$(REPOS_DIR)/scx"; \
	corpus_root="$(ROOT_DIR)/corpus/build/x86_64/scx"; \
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

__scx-binaries-arm64: __arm64-crossbuild-image
	@test -n "$(RUN_SCX_PACKAGES_CSV)" || { echo "RUN_SCX_PACKAGES_CSV is required" >&2; exit 1; }
	@docker run --rm --platform linux/arm64 \
		-v "$(ROOT_DIR):$(ROOT_DIR)" \
		-w "$(ROOT_DIR)" \
		"$(ARM64_CROSSBUILD_IMAGE)" \
		make --no-print-directory __scx-binaries-arm64-inner \
			ROOT_DIR="$(ROOT_DIR)" \
			RUNNER_DIR="$(RUNNER_DIR)" \
			JOBS="$(JOBS)" \
			RUN_SCX_PACKAGES_CSV="$(RUN_SCX_PACKAGES_CSV)"

__scx-binaries-arm64-inner:
	@test -n "$(RUN_SCX_PACKAGES_CSV)" || { echo "RUN_SCX_PACKAGES_CSV is required" >&2; exit 1; }
	@repo_root="$(REPOS_DIR)/scx"; \
	corpus_root="$(ROOT_DIR)/corpus/build/arm64/scx"; \
	bin_root="$$corpus_root/bin"; \
	target_release_dir="$$repo_root/target/aarch64-unknown-linux-gnu/release"; \
	lock_path="$(LOCK_ROOT)/arm64-scx.lock"; \
	mkdir -p "$$bin_root" "$$corpus_root" "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	for package in $$(printf '%s' "$(RUN_SCX_PACKAGES_CSV)" | tr ',' ' '); do \
		[ -n "$$package" ] || continue; \
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

__native-repos-arm64: __arm64-crossbuild-image
	@test -n "$(RUN_NATIVE_REPOS_CSV)" || { echo "RUN_NATIVE_REPOS_CSV is required" >&2; exit 1; }
	@docker run --rm --platform linux/arm64 \
		-v "$(ROOT_DIR):/workspace" \
		-w /workspace \
		"$(ARM64_CROSSBUILD_IMAGE)" \
		make --no-print-directory __native-repos-arm64-inner ROOT_DIR=/workspace RUNNER_DIR=/workspace/runner JOBS="$(JOBS)" RUN_NATIVE_REPOS_CSV="$(RUN_NATIVE_REPOS_CSV)"

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
	stage_root="$(ROOT_DIR)/corpus/build/$(RUN_TARGET_ARCH)/bcc/libbpf-tools/.output"; \
	lock_path="$(LOCK_ROOT)/$(RUN_TARGET_ARCH)-bcc.lock"; \
	mkdir -p "$$stage_root" "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	bpftool_cmd="$(ROOT_DIR)/vendor/linux-framework/tools/bpf/bpftool/bpftool"; \
	if [ ! -x "$$bpftool_cmd" ]; then bpftool_cmd="$$(command -v bpftool || true)"; fi; \
	test -n "$$bpftool_cmd" || { echo "bpftool is required for bcc native repo build" >&2; exit 1; }; \
	$(MAKE) -C "$$repo_root" -j"$(JOBS)" LIBBPF_SRC="$(ROOT_DIR)/vendor/libbpf/src" BPFTOOL="$$bpftool_cmd" USE_BLAZESYM=0; \
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
	stage_root="$(ROOT_DIR)/corpus/build/$(RUN_TARGET_ARCH)/tracee"; \
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
	stage_root="$(ROOT_DIR)/corpus/build/$(RUN_TARGET_ARCH)/tetragon"; \
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
	@stage_root="$(ROOT_DIR)/corpus/build/x86_64/katran"; \
	lock_path="$(LOCK_ROOT)/x86_64-katran.lock"; \
	mkdir -p "$$stage_root/bin" "$$stage_root/lib" "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	test -f "$(KATRAN_HELPER_BPF)"; \
	test -x "$(KATRAN_HELPER_BIN)"; \
	if ! cmp -s "$(KATRAN_HELPER_BPF)" "$$stage_root/balancer.bpf.o" 2>/dev/null; then cp -f "$(KATRAN_HELPER_BPF)" "$$stage_root/balancer.bpf.o"; fi; \
	if ! cmp -s "$(KATRAN_HELPER_BIN)" "$$stage_root/bin/katran_server_grpc" 2>/dev/null; then cp -f "$(KATRAN_HELPER_BIN)" "$$stage_root/bin/katran_server_grpc"; fi; \
	find "$(KATRAN_HELPER_ROOT)/lib" -maxdepth 1 -type f | while read -r src; do \
		dst="$$stage_root/lib/$${src##*/}"; \
		if ! cmp -s "$$src" "$$dst" 2>/dev/null; then cp -f "$$src" "$$dst"; fi; \
	done

__native-repo-katran-arm64:
	@stage_root="$(ROOT_DIR)/corpus/build/arm64/katran"; \
	build_root="$(KATRAN_ARM64_BUILD_ROOT)"; \
	install_root="$(KATRAN_ARM64_INSTALL_ROOT)"; \
	lock_path="$(LOCK_ROOT)/arm64-katran.lock"; \
	mkdir -p "$$stage_root/bin" "$$stage_root/lib" "$$build_root" "$$install_root" "$(LOCK_ROOT)"; \
	exec 9>"$$lock_path"; flock 9; \
	BUILD_EXAMPLE_GRPC=1 BUILD_DIR="$$build_root" INSTALL_DIR="$$install_root" "$(REPOS_DIR)/katran/build_katran.sh"; \
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
