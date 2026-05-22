ROOT_DIR := ../..
BUILD_DIR := build
BPF_OBJ := $(BUILD_DIR)/x86_sim_hardcoded.bpf.o
MICRO_CONFIG ?= $(ROOT_DIR)/micro/config/micro_pure_jit.yaml
PROOF_BUILD_DIR ?= micro-prog/build
LOADER_MANIFEST := ../loader/Cargo.toml
LOADER_BIN := ../loader/target/debug/reversesim-loader

CLANG ?= clang
CARGO ?= cargo
PYTHON ?= python3
BPF_STACK_SIZE ?= 4096

.PHONY: build run micro-proofs-build micro-proofs-run clean

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

micro-proofs-build:
	$(PYTHON) ../run_micro_sim_batch.py --arch x86 --build-only \
		--build-dir "$(PROOF_BUILD_DIR)" \
		--config "$(MICRO_CONFIG)" \
		$(MICRO_SIM_PROOF_ARGS)

micro-proofs-run:
	$(PYTHON) ../run_micro_sim_batch.py --arch x86 \
		--build-dir "$(PROOF_BUILD_DIR)" \
		--config "$(MICRO_CONFIG)" \
		$(MICRO_SIM_PROOF_ARGS)

clean:
	rm -rf $(BUILD_DIR) ../loader/target
