ROOT_DIR := ../..
BUILD_DIR := build
BPF_OBJ := $(BUILD_DIR)/x86_sim_hardcoded.bpf.o
MICRO_CONFIG ?= $(ROOT_DIR)/micro/config/micro_pure_jit.yaml
PROOF_BUILD_DIR ?= micro-prog/build
NEGATIVE_PROOF_BUILD_DIR ?= $(PROOF_BUILD_DIR)/negative
NEGATIVE_NATIVE_BUILD_DIR ?= build/negative-native
NEGATIVE_CONFIG := ../test/kprog_negative_stage2.yaml
NEGATIVE_PROGRAM := unchecked_packet_read
LOADER_MANIFEST := ../loader/Cargo.toml
LOADER_BIN := ../loader/target/debug/reversesim-loader

CLANG ?= clang
CARGO ?= cargo
PYTHON ?= python3
BPF_STACK_SIZE ?= 4096

.PHONY: build run micro-proofs-build micro-proofs-run kprog-negative-proof-build app-proofs-build clean

build: $(BPF_OBJ)
	$(CARGO) build --manifest-path $(LOADER_MANIFEST)

$(BPF_OBJ): x86_sim_hardcoded.bpf.c x86_sim_local_bpf.h
	install -d $(BUILD_DIR)
	$(CLANG) -g -O2 -target bpf -mllvm -bpf-stack-size=$(BPF_STACK_SIZE) \
		-D__TARGET_ARCH_x86 \
		-I$(ROOT_DIR)/vendor/libbpf/include/uapi \
		-I$(ROOT_DIR)/vendor/libbpf/src \
		-I/usr/include/x86_64-linux-gnu \
		-c x86_sim_hardcoded.bpf.c -o $(BPF_OBJ)

run: build
	$(LOADER_BIN) --object $(BPF_OBJ) --program x86_sim_hardcoded_xdp --case simple --load-only

micro-proofs-build: kprog-negative-proof-build
	$(PYTHON) ../run_micro_sim_batch.py --arch x86 --build-only \
		--build-dir "$(PROOF_BUILD_DIR)" \
		--config "$(MICRO_CONFIG)" \
		$(MICRO_SIM_PROOF_ARGS)

kprog-negative-proof-build:
	$(MAKE) -C ../test \
		OUTPUT_DIR="$(abspath $(NEGATIVE_NATIVE_BUILD_DIR))" \
		KERNEL_OFFSETS="$(abspath $(ROOT_DIR)/micro/programs/build-x86/kernel_offsets.h)" \
		"$(abspath $(NEGATIVE_NATIVE_BUILD_DIR))/$(NEGATIVE_PROGRAM).native.o"
	$(PYTHON) ../run_micro_sim_batch.py --arch x86 --build-only \
		--build-dir "$(NEGATIVE_PROOF_BUILD_DIR)" \
		--native-build-dir "$(NEGATIVE_NATIVE_BUILD_DIR)" \
		--config "$(NEGATIVE_CONFIG)" \
		--jobs 1

micro-proofs-run:
	$(PYTHON) ../run_micro_sim_batch.py --arch x86 \
		--build-dir "$(PROOF_BUILD_DIR)" \
		--config "$(MICRO_CONFIG)" \
		$(MICRO_SIM_PROOF_ARGS)

app-proofs-build:
	$(PYTHON) run_app_sim_smoke.py --keep-going $(APP_SIM_PROOF_ARGS)

clean:
	rm -rf $(BUILD_DIR) ../loader/target
