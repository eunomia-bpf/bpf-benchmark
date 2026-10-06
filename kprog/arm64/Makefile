ROOT_DIR := ../..
OUTPUT_DIR ?= build
BUILD_DIR := $(OUTPUT_DIR)
BPF_OBJ := $(BUILD_DIR)/arm64_sim_hardcoded.bpf.o
MICRO_CONFIG ?= $(ROOT_DIR)/micro/config/micro_pure_jit.yaml
MICRO_PROG_DIR := micro-prog
PROOF_BUILD_DIR ?= $(MICRO_PROG_DIR)/build
NEGATIVE_PROOF_BUILD_DIR ?= $(PROOF_BUILD_DIR)/negative
NEGATIVE_NATIVE_BUILD_DIR ?= build/negative-native
NEGATIVE_CONFIG := ../test/kprog_negative_stage2.yaml
NEGATIVE_PROGRAM := unchecked_packet_read
SIMPLE_INPUT := $(PROOF_BUILD_DIR)/simple.mem
SIMPLE_OBJ := $(PROOF_BUILD_DIR)/simple.bpf.o
LOADER_MANIFEST := ../loader/Cargo.toml
LOADER_BIN := ../loader/target/debug/reversesim-loader

CLANG ?= clang
CARGO ?= cargo
PYTHON ?= python3
BPF_STACK_SIZE ?= 4096
SYS_INCLUDE_FLAGS ?= -I/usr/aarch64-linux-gnu/include -I$(ROOT_DIR)/.cache/aarch64-sysroot/usr/include -I$(ROOT_DIR)/.cache/aarch64-sysroot/usr/include/aarch64-linux-gnu

.PHONY: build run micro-proofs-generate micro-proofs-build micro-proofs-run kprog-negative-proof-build app-proofs-build simple-proof-build simple-proof clean

build: $(BPF_OBJ)
	$(CARGO) build --manifest-path $(LOADER_MANIFEST)

$(BPF_OBJ): arm64_sim_hardcoded.bpf.c arm64_sim_local_bpf.h arm64_sim.h
	install -d $(BUILD_DIR)
	$(CLANG) -g -O2 -target bpf -mllvm -bpf-stack-size=$(BPF_STACK_SIZE) \
		-D__TARGET_ARCH_arm64 \
		-I$(ROOT_DIR)/vendor/libbpf/include/uapi \
		-I$(ROOT_DIR)/vendor/libbpf/src \
		-I/usr/include/x86_64-linux-gnu \
		-c arm64_sim_hardcoded.bpf.c -o $(BPF_OBJ)

run: build
	$(LOADER_BIN) --object $(BPF_OBJ) --program arm64_sim_hardcoded_xdp --case simple --load-only

micro-proofs-generate:
	$(PYTHON) ../run_micro_sim_batch.py --arch arm64 --generate-only \
		--build-dir "$(PROOF_BUILD_DIR)" \
		--config "$(MICRO_CONFIG)" \
		$(MICRO_SIM_PROOF_ARGS)

$(PROOF_BUILD_DIR):
	install -d "$@"

$(PROOF_BUILD_DIR)/%.bpf.o: $(MICRO_PROG_DIR)/%.bpf.c arm64_sim_local_bpf.h arm64_sim.h | $(PROOF_BUILD_DIR)
	$(CLANG) -g -O2 -target bpf -mllvm -bpf-stack-size=$(BPF_STACK_SIZE) \
		-D__TARGET_ARCH_arm64 \
		-I. \
		-I$(ROOT_DIR)/vendor/libbpf/include/uapi \
		-I$(ROOT_DIR)/vendor/libbpf/src \
		-I/usr/include/x86_64-linux-gnu \
		-c "$<" -o "$@"

$(SIMPLE_INPUT): | $(PROOF_BUILD_DIR)
	dd if=/dev/zero of="$@" bs=64 count=1 status=none

micro-proofs-build: kprog-negative-proof-build
	$(PYTHON) ../run_micro_sim_batch.py --arch arm64 --build-only \
		--build-dir "$(PROOF_BUILD_DIR)" \
		--config "$(MICRO_CONFIG)" \
		$(MICRO_SIM_PROOF_ARGS)

kprog-negative-proof-build:
	$(MAKE) -C ../test \
		OUTPUT_DIR="$(abspath $(NEGATIVE_NATIVE_BUILD_DIR))" \
		KERNEL_OFFSETS_DIR="$(abspath $(ROOT_DIR)/micro/programs/build-arm64)" \
		NATIVE_TARGET=aarch64-linux-gnu \
		NATIVE_ARCH=arm64 \
		SYS_INCLUDE_FLAGS="$(SYS_INCLUDE_FLAGS)" \
		"$(abspath $(NEGATIVE_NATIVE_BUILD_DIR))/$(NEGATIVE_PROGRAM).native.o"
	$(PYTHON) ../run_micro_sim_batch.py --arch arm64 --build-only \
		--build-dir "$(NEGATIVE_PROOF_BUILD_DIR)" \
		--native-build-dir "$(NEGATIVE_NATIVE_BUILD_DIR)" \
		--config "$(NEGATIVE_CONFIG)" \
		--jobs 1

micro-proofs-run:
	$(PYTHON) ../run_micro_sim_batch.py --arch arm64 \
		--build-dir "$(PROOF_BUILD_DIR)" \
		--config "$(MICRO_CONFIG)" \
		$(MICRO_SIM_PROOF_ARGS)

app-proofs-build:
	$(PYTHON) run_app_sim_smoke.py --keep-going $(APP_SIM_PROOF_ARGS)

simple-proof-build: $(SIMPLE_OBJ) $(SIMPLE_INPUT)

simple-proof: build simple-proof-build
	$(LOADER_BIN) --object $(SIMPLE_OBJ) --program simple_arm64_sim_xdp \
		--input "$(SIMPLE_INPUT)" --expected-result 12345678 --case simple

clean:
	rm -rf $(BUILD_DIR)
