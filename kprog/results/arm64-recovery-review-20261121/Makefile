ROOT := /workspaces/repository
OUT ?= /var/tmp/kprog-tmp/S2/review-20261121
.PHONY: host sites
host:
	install -d $(OUT)
	$(CC) -O2 -g -fsanitize=undefined -fno-sanitize-recover=undefined -I$(ROOT)/vendor/libbpf/src -I$(ROOT)/kprog/formal $(ROOT)/kprog/formal/oracles/test_arm64_read_followup_host.c -o $(OUT)/read-followup
	$(OUT)/read-followup
sites:
	python3 $(ROOT)/kprog/formal/oracles/test_arm64_load_sites.py $(OUT)/sites

.PHONY: link
link:
	CARGO_TARGET_DIR=$(OUT)/cargo cargo test --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml -j4
	CARGO_TARGET_DIR=$(OUT)/cargo cargo build --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml -j4

KDIR := /workspaces/.agent-state/kprog-ck/build-arm64
ARM_LIBBPF := $(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf
ARM_SYSROOT := $(ROOT)/.cache/aarch64-sysroot
.PHONY: guest-build
guest-build:
	CARGO_TARGET_DIR=$(OUT)/cargo CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER=aarch64-linux-gnu-gcc cargo build --release --target aarch64-unknown-linux-gnu --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml -j4
	$(MAKE) -C $(KDIR) M=$(ROOT)/kprog/stock-path/module MO=$(OUT)/module ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- modules
	$(MAKE) -C $(KDIR) M=$(ROOT)/kprog/test/native_load_fault MO=$(OUT)/fixture-module ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- modules
	$(ROOT)/vendor/build/x86/bpftool/bin/bpftool btf dump file $(KDIR)/vmlinux format c > $(OUT)/vmlinux.h
	clang-18 --target=aarch64-linux-gnu -O3 -g -fPIC -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables -fno-jump-tables -fno-optimize-sibling-calls -I$(OUT) -c $(ROOT)/kprog/test/native_load_fault/arm64.c -o $(OUT)/arm64.o
	clang-18 --target=aarch64-linux-gnu -O3 -g -fPIC -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables -fno-jump-tables -fno-optimize-sibling-calls -I$(OUT) -c $(ROOT)/kprog/test/native_load_fault/native.c -o $(OUT)/native.o
	PKG_CONFIG_LIBDIR=$(ARM_SYSROOT)/usr/lib/aarch64-linux-gnu/pkgconfig PKG_CONFIG_SYSROOT_DIR=$(ARM_SYSROOT) cmake -S $(ROOT)/kprog/libnativeloader -B $(OUT)/loader -DCMAKE_SYSTEM_NAME=Linux -DCMAKE_SYSTEM_PROCESSOR=aarch64 -DCMAKE_CXX_COMPILER=aarch64-linux-gnu-g++ -DCMAKE_BUILD_TYPE=Release -DNATIVE_LOADER_REPO_ROOT=$(ROOT) -DNATIVE_LOADER_LIBBPF_PREFIX=$(ARM_LIBBPF)/prefix -DNATIVE_LOADER_LIBBPF_LIBRARY=$(ARM_LIBBPF)/pic-obj/libbpf.a -DNATIVE_LOADER_KERNEL_OFFSETS_INCLUDE=$(ROOT)/micro/programs/build-arm64
	cmake --build $(OUT)/loader --target trusted-native-loader -j4
	aarch64-linux-gnu-g++ -std=c++20 -O2 -I$(ARM_LIBBPF)/prefix/include $(ROOT)/kprog/test/native_load_fault/probe.cpp $(OUT)/loader/libnative_loader.a $(ARM_LIBBPF)/pic-obj/libbpf.a -L$(ARM_SYSROOT)/usr/lib/aarch64-linux-gnu -lelf -lz -lzstd -ldl -pthread -o $(OUT)/probe

.PHONY: guest
guest:
	python3 $(ROOT)/kprog/results/arm64-recovery-review-20261121/guest.py host $(OUT)

.PHONY: micro
micro:
	python3 $(ROOT)/kprog/arm64/micro-prog/generate_micro_sim_proofs.py --config $(ROOT)/micro/config/micro_pure_jit.yaml --proof-object-dir $(ROOT)/kprog/arm64/micro-prog/build/native-link --output-dir $(OUT)/micro-src
	python3 $(ROOT)/kprog/arm64/micro-prog/generate_micro_sim_proofs.py --config $(ROOT)/kprog/test/kprog_negative_stage2.yaml --proof-object-dir $(ROOT)/kprog/arm64/micro-prog/build/native-link --output-dir $(OUT)/negative-src
	python3 $(ROOT)/kprog/results/arm64-recovery-review-20261121/compile_micro.py $(OUT)
