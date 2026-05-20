ROOT_DIR := ../..
OUTPUT_DIR ?= build
BUILD_DIR := $(OUTPUT_DIR)
BPF_OBJ := $(BUILD_DIR)/arm64_sim_hardcoded.bpf.o
GEN_DIR := $(BUILD_DIR)/micro-prog
MICRO_BUILD_DIR ?= $(ROOT_DIR)/micro/programs/build-arm64
SIMPLE_GEN_C := $(GEN_DIR)/simple_arm64_sim.bpf.c
SIMPLE_INPUT := $(GEN_DIR)/simple.mem
SIMPLE_OBJ := $(BUILD_DIR)/simple_arm64_sim.bpf.o
LOADER_MANIFEST := ../loader/Cargo.toml
LOADER_BIN := ../loader/target/debug/reversesim-loader

CLANG ?= clang
CARGO ?= cargo
PYTHON ?= python3
BPF_STACK_SIZE ?= 4096

.PHONY: build run simple-proof-build simple-proof clean

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

$(GEN_DIR):
	install -d "$@"

$(SIMPLE_GEN_C): micro-prog/generate_micro_sim_proofs.py $(MICRO_BUILD_DIR)/simple.native.so | $(GEN_DIR)
	$(PYTHON) micro-prog/generate_micro_sim_proofs.py \
		--bench simple \
		--native-so "$(MICRO_BUILD_DIR)/simple.native.so" \
		--output "$(SIMPLE_GEN_C)" \
		--input-output "$(SIMPLE_INPUT)"

$(SIMPLE_INPUT): $(SIMPLE_GEN_C)
	@test -f "$@"

$(SIMPLE_OBJ): $(SIMPLE_GEN_C) arm64_sim_local_bpf.h arm64_sim.h
	install -d $(BUILD_DIR)
	$(CLANG) -g -O2 -target bpf -mllvm -bpf-stack-size=$(BPF_STACK_SIZE) \
		-D__TARGET_ARCH_arm64 \
		-I. \
		-I$(ROOT_DIR)/vendor/libbpf/include/uapi \
		-I$(ROOT_DIR)/vendor/libbpf/src \
		-I/usr/include/x86_64-linux-gnu \
		-c "$(SIMPLE_GEN_C)" -o "$(SIMPLE_OBJ)"

simple-proof-build: $(SIMPLE_OBJ) $(SIMPLE_INPUT)

simple-proof: build simple-proof-build
	$(LOADER_BIN) --object $(SIMPLE_OBJ) --program simple_arm64_sim_xdp \
		--input "$(SIMPLE_INPUT)" --expected-result 12345678 --case simple

clean:
	rm -rf $(BUILD_DIR)
