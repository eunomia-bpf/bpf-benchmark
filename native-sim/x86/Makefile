ROOT_DIR := ../..
BUILD_DIR := build
BPF_OBJ := $(BUILD_DIR)/x86_sim_hardcoded.bpf.o
TEMPLATE_OBJ := $(BUILD_DIR)/x86_sim_template_helpers.bpf.o
LOADER_MANIFEST := ../loader/Cargo.toml
LOADER_BIN := ../loader/target/debug/reversesim-loader

CLANG ?= clang
CARGO ?= cargo

.PHONY: build build-templates run clean

build: $(BPF_OBJ) $(TEMPLATE_OBJ)
	$(CARGO) build --manifest-path $(LOADER_MANIFEST)

build-templates: $(TEMPLATE_OBJ)

$(BPF_OBJ): x86_sim_hardcoded.bpf.c x86_sim_bpf.h x86_sim.h
	mkdir -p $(BUILD_DIR)
	$(CLANG) -g -O2 -target bpf -D__TARGET_ARCH_x86 \
		-I$(ROOT_DIR)/vendor/libbpf/include/uapi \
		-I$(ROOT_DIR)/vendor/libbpf/src \
		-I/usr/include/x86_64-linux-gnu \
		-c x86_sim_hardcoded.bpf.c -o $(BPF_OBJ)

$(TEMPLATE_OBJ): x86_sim_template_helpers.bpf.c x86_sim_bpf.h x86_sim.h
	mkdir -p $(BUILD_DIR)
	$(CLANG) -g -O2 -target bpf -D__TARGET_ARCH_x86 \
		-I$(ROOT_DIR)/vendor/libbpf/include/uapi \
		-I$(ROOT_DIR)/vendor/libbpf/src \
		-I/usr/include/x86_64-linux-gnu \
		-c x86_sim_template_helpers.bpf.c -o $(TEMPLATE_OBJ)

run: build
	$(LOADER_BIN) --object $(BPF_OBJ) --program x86_sim_hardcoded_xdp --case simple

clean:
	rm -rf $(BUILD_DIR) ../loader/target
