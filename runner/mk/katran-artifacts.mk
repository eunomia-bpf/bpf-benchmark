# GCC 13 can ICE while compiling grpc's tcp_client_posix.cc on Ubuntu 24.04.
# Build Katran's C/C++ userspace stack with clang instead.
$(ACTIVE_KATRAN_REQUIRED) &: $(KATRAN_SOURCE_FILES) $(KATRAN_ARTIFACTS_BUILD_RULE_FILE)
	repo_root="$(REPOS_DIR)/katran"; \
	build_root="$(KATRAN_BUILD_ROOT)"; \
	install_root="$(REPO_KATRAN_ROOT)"; \
	artifact_root="$(REPO_KATRAN_ROOT)"; \
	override_file="$(KATRAN_BUILD_ROOT)/cxx-override.cmake"; \
	bpf_root="$$artifact_root/bpf"; \
	system_libdir="$$(pkg-config --variable=libdir libelf)"; \
	mkdir -p "$$install_root/bin" "$$install_root/lib" "$$install_root/lib64" "$$bpf_root" "$$build_root/deps"; \
	command -v grpc_cpp_plugin >/dev/null; \
	touch "$$build_root/deps/grpc_installed"; \
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
	cd "$$repo_root" && ./build_bpf_modules_opensource.sh -s "$$repo_root" -b "$$build_root" -o "$$bpf_root"; \
	test -x "$$install_root/bin/katran_server_grpc" || { echo "missing Katran install output: $$install_root/bin/katran_server_grpc" >&2; exit 1; }; \
	[ -f "$$bpf_root/healthchecking_ipip.o" ] && mv -f "$$bpf_root/healthchecking_ipip.o" "$$bpf_root/healthchecking_ipip.bpf.o" || true; \
	[ -f "$$bpf_root/xdp_root.o" ] && mv -f "$$bpf_root/xdp_root.o" "$$bpf_root/xdp_root.bpf.o" || true; \
	for path in $(ACTIVE_KATRAN_REQUIRED); do test -e "$$path"; done; \
	touch $(ACTIVE_KATRAN_REQUIRED)
