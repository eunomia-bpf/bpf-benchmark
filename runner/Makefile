SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c

ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/..)
RUNNER_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
REPOS_DIR := $(RUNNER_DIR)/repos
KATRAN_HELPER_ROOT := $(ROOT_DIR)/e2e/cases/katran

BUILD_DIR ?= $(RUNNER_DIR)/build
JOBS ?= $(shell nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
MICRO_EXEC_ENABLE_LLVMBPF ?= OFF
MICRO_REPO_ROOT ?= $(ROOT_DIR)
LLVM_DIR ?=
CORPUS_BUILD_DIR ?= $(ROOT_DIR)/corpus/build
SCX_PACKAGES_CSV ?=
SCX_TARGET_TRIPLE ?=
NATIVE_REPOS_CSV ?=
NATIVE_TARGET_ARCH ?= x86_64
ARM64_CROSSBUILD_IMAGE ?= bpf-benchmark-arm64-crossbuild:latest

LIBBPF_BUILD_DIR := $(BUILD_DIR)/vendor/libbpf
LIBBPF_OBJDIR := $(LIBBPF_BUILD_DIR)/obj
LIBBPF_PREFIX := $(LIBBPF_BUILD_DIR)/prefix
LIBBPF_A := $(LIBBPF_OBJDIR)/libbpf.a
KATRAN_HELPER_BIN := $(KATRAN_HELPER_ROOT)/bin/katran_server_grpc
KATRAN_HELPER_BPF := $(KATRAN_HELPER_ROOT)/bin/balancer.bpf.o

.PHONY: micro_exec portable-libbpf scx-binaries native-repos native-repos-inner \
	native-repo-bcc native-repo-tracee native-repo-tetragon native-repo-katran clean

micro_exec: $(LIBBPF_A)
	@cmake_args='-S "$(RUNNER_DIR)" -B "$(BUILD_DIR)" -DCMAKE_BUILD_TYPE=Release -DMICRO_REPO_ROOT="$(MICRO_REPO_ROOT)" -DMICRO_LIBBPF_PREFIX="$(LIBBPF_PREFIX)" -DMICRO_LIBBPF_LIBRARY="$(LIBBPF_A)" -DMICRO_EXEC_ENABLE_LLVMBPF="$(MICRO_EXEC_ENABLE_LLVMBPF)"'; \
	if [ -n "$(LLVM_DIR)" ]; then cmake_args="$$cmake_args -DLLVM_DIR=$(LLVM_DIR)"; fi; \
	if [ -n "$${MICRO_LLVMBPF_LIBRARY:-}" ]; then cmake_args="$$cmake_args -DMICRO_LLVMBPF_LIBRARY=$${MICRO_LLVMBPF_LIBRARY}"; fi; \
	if [ -n "$${MICRO_LLVMBPF_BUILD_CACHE:-}" ]; then cmake_args="$$cmake_args -DMICRO_LLVMBPF_BUILD_CACHE=$${MICRO_LLVMBPF_BUILD_CACHE}"; fi; \
	if [ -n "$${MICRO_LLVMBPF_SPDLOG_LIBRARY:-}" ]; then cmake_args="$$cmake_args -DMICRO_LLVMBPF_SPDLOG_LIBRARY=$${MICRO_LLVMBPF_SPDLOG_LIBRARY}"; fi; \
	eval cmake $$cmake_args; \
	cmake --build "$(BUILD_DIR)" --target micro_exec -j"$(JOBS)"

$(LIBBPF_A):
	@mkdir -p "$(LIBBPF_OBJDIR)" "$(LIBBPF_PREFIX)/include"
	$(MAKE) -C "$(ROOT_DIR)/vendor/libbpf/src" -j"$(JOBS)" BUILD_STATIC_ONLY=1 OBJDIR="$(LIBBPF_OBJDIR)" DESTDIR= PREFIX="$(LIBBPF_PREFIX)" "$(LIBBPF_A)" install_headers

portable-libbpf:
	@test -n "$(OUTPUT_ROOT)" || { echo "OUTPUT_ROOT is required" >&2; exit 1; }
	@docker run --rm \
		-v "$(ROOT_DIR):/workspace:ro" \
		-v "$(OUTPUT_ROOT):/out" \
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

scx-binaries:
	@test -n "$(SCX_PACKAGES_CSV)" || { echo "SCX_PACKAGES_CSV is required" >&2; exit 1; }
	@repo_root="$(REPOS_DIR)/scx"; \
	corpus_root="$(CORPUS_BUILD_DIR)/scx"; \
	bin_root="$$corpus_root/bin"; \
	target_args=""; \
	target_release_dir="$$repo_root/target/release"; \
	if [ -n "$(SCX_TARGET_TRIPLE)" ]; then \
		target_args='--target "$(SCX_TARGET_TRIPLE)"'; \
		target_release_dir="$$repo_root/target/$(SCX_TARGET_TRIPLE)/release"; \
	fi; \
	mkdir -p "$$bin_root" "$$corpus_root"; \
	for package in $$(printf '%s' "$(SCX_PACKAGES_CSV)" | tr ',' ' '); do \
		[ -n "$$package" ] || continue; \
		cargo build --release $$target_args --manifest-path "$$repo_root/Cargo.toml" --package "$$package"; \
		test -x "$$target_release_dir/$$package"; \
		cp -f "$$target_release_dir/$$package" "$$bin_root/$$package"; \
		object_path="$$(find "$$target_release_dir/build" -path "*/$$package-*/out/main.bpf.o" | sort | tail -n1)"; \
		test -n "$$object_path"; \
		cp -f "$$object_path" "$$corpus_root/$${package}_main.bpf.o"; \
	done

native-repos:
	@test -n "$(NATIVE_REPOS_CSV)" || { echo "NATIVE_REPOS_CSV is required" >&2; exit 1; }
	@if [ "$(NATIVE_TARGET_ARCH)" = "arm64" ] && [ "$$(uname -m)" != "aarch64" ] && [ "$$(uname -m)" != "arm64" ]; then \
		docker image inspect "$(ARM64_CROSSBUILD_IMAGE)" >/dev/null 2>&1 || \
			docker build -t "$(ARM64_CROSSBUILD_IMAGE)" -f "$(RUNNER_DIR)/docker/arm64-crossbuild.Dockerfile" "$(ROOT_DIR)"; \
		docker run --rm --platform linux/arm64 \
			-v "$(ROOT_DIR):/workspace" \
			-w /workspace/runner \
			"$(ARM64_CROSSBUILD_IMAGE)" \
			make --no-print-directory native-repos-inner \
				ROOT_DIR=/workspace \
				RUNNER_DIR=/workspace/runner \
				CORPUS_BUILD_DIR=/workspace/corpus/build \
				NATIVE_REPOS_CSV="$(NATIVE_REPOS_CSV)" \
				NATIVE_TARGET_ARCH=arm64 \
				JOBS="$(JOBS)"; \
	else \
		$(MAKE) --no-print-directory native-repos-inner \
			NATIVE_REPOS_CSV="$(NATIVE_REPOS_CSV)" \
			NATIVE_TARGET_ARCH="$(NATIVE_TARGET_ARCH)" \
			CORPUS_BUILD_DIR="$(CORPUS_BUILD_DIR)" \
			JOBS="$(JOBS)"; \
	fi

native-repos-inner:
	@test -n "$(NATIVE_REPOS_CSV)" || { echo "NATIVE_REPOS_CSV is required" >&2; exit 1; }
	@for repo in $$(printf '%s' "$(NATIVE_REPOS_CSV)" | tr ',' ' '); do \
		[ -n "$$repo" ] || continue; \
		$(MAKE) --no-print-directory "native-repo-$$repo" \
			NATIVE_TARGET_ARCH="$(NATIVE_TARGET_ARCH)" \
			CORPUS_BUILD_DIR="$(CORPUS_BUILD_DIR)" \
			JOBS="$(JOBS)"; \
	done

native-repo-bcc:
	@repo_root="$(REPOS_DIR)/bcc/libbpf-tools"; \
	stage_root="$(CORPUS_BUILD_DIR)/bcc/libbpf-tools/.output"; \
	rm -rf "$(CORPUS_BUILD_DIR)/bcc"; \
	mkdir -p "$$stage_root"; \
	bpftool_cmd="$(ROOT_DIR)/vendor/linux-framework/tools/bpf/bpftool/bpftool"; \
	if [ ! -x "$$bpftool_cmd" ]; then \
		bpftool_cmd="$$(command -v bpftool || true)"; \
	fi; \
	test -n "$$bpftool_cmd" || { echo "bpftool is required for bcc native repo build" >&2; exit 1; }; \
	$(MAKE) -C "$$repo_root" -j"$(JOBS)" \
		LIBBPF_SRC="$(ROOT_DIR)/vendor/libbpf/src" \
		BPFTOOL="$$bpftool_cmd" \
		USE_BLAZESYM=0; \
	find "$$repo_root/.output" -maxdepth 1 -type f -name '*.bpf.o' -exec cp -f {} "$$stage_root"/ \; ; \
	for obj in "$$repo_root"/.output/*.bpf.o; do \
		[ -f "$$obj" ] || continue; \
		tool_name="$${obj##*/}"; \
		tool_name="$${tool_name%.bpf.o}"; \
		if [ -x "$$repo_root/$$tool_name" ]; then \
			cp -f "$$repo_root/$$tool_name" "$$stage_root/$$tool_name"; \
		fi; \
	done

native-repo-tracee:
	@repo_root="$(REPOS_DIR)/tracee"; \
	stage_root="$(CORPUS_BUILD_DIR)/tracee"; \
	go_arch="$$( [ "$(NATIVE_TARGET_ARCH)" = "arm64" ] && printf 'arm64' || printf 'amd64' )"; \
	rm -rf "$$stage_root"; \
	mkdir -p "$$stage_root/bin" "$$stage_root/lsm_support"; \
	rm -f "$$repo_root/goenv.mk"; \
	$(MAKE) -C "$$repo_root" -j"$(JOBS)" GO_ARCH="$$go_arch" bpf tracee evt traceectl lsm-check; \
	cp -f "$$repo_root/dist/tracee.bpf.o" "$$stage_root/tracee.bpf.o"; \
	find "$$repo_root/dist/lsm_support" -maxdepth 1 -type f -name '*.bpf.o' -exec cp -f {} "$$stage_root/lsm_support"/ \; ; \
	for bin in tracee evt traceectl lsm-check; do \
		test -x "$$repo_root/dist/$$bin"; \
		cp -f "$$repo_root/dist/$$bin" "$$stage_root/bin/$$bin"; \
	done

native-repo-tetragon:
	@repo_root="$(REPOS_DIR)/tetragon"; \
	stage_root="$(CORPUS_BUILD_DIR)/tetragon"; \
	target_arch="$$( [ "$(NATIVE_TARGET_ARCH)" = "arm64" ] && printf 'arm64' || printf 'amd64' )"; \
	rm -rf "$$stage_root"; \
	mkdir -p "$$stage_root/bin"; \
	$(MAKE) -C "$$repo_root" -j"$(JOBS)" TARGET_ARCH="$$target_arch" LOCAL_CLANG=1 tetragon-bpf; \
	$(MAKE) -C "$$repo_root" -j"$(JOBS)" TARGET_ARCH="$$target_arch" tetragon EXTRA_GO_BUILD_FLAGS=-mod=mod; \
	find "$$repo_root/bpf/objs" -maxdepth 1 -type f -name '*.o' -exec cp -f {} "$$stage_root"/ \; ; \
	test -x "$$repo_root/tetragon"; \
	cp -f "$$repo_root/tetragon" "$$stage_root/bin/tetragon"

native-repo-katran:
	@if [ "$(NATIVE_TARGET_ARCH)" = "arm64" ]; then \
		echo "arm64 katran native repo build is not yet Make-backed without repo getdeps" >&2; \
		exit 1; \
	fi
	@stage_root="$(CORPUS_BUILD_DIR)/katran"; \
	rm -rf "$$stage_root"; \
	mkdir -p "$$stage_root/bin" "$$stage_root/lib"; \
	test -f "$(KATRAN_HELPER_BPF)"; \
	test -x "$(KATRAN_HELPER_BIN)"; \
	cp -f "$(KATRAN_HELPER_BPF)" "$$stage_root/balancer.bpf.o"; \
	cp -f "$(KATRAN_HELPER_BIN)" "$$stage_root/bin/katran_server_grpc"; \
	find "$(KATRAN_HELPER_ROOT)/lib" -maxdepth 1 -type f -exec cp -f {} "$$stage_root/lib"/ \;

clean:
	rm -rf "$(BUILD_DIR)"
