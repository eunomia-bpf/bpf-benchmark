ROOT_DIR := ../..
BUILD_DIR := build
BPF_OBJ := $(BUILD_DIR)/x86_vm.bpf.o
LOADER_MANIFEST := loader/Cargo.toml
LOADER_BIN := loader/target/debug/x86-ebpf-vm-loader

CLANG ?= clang
CARGO ?= cargo

.PHONY: build run clean

build: $(BPF_OBJ)
	$(CARGO) build --manifest-path $(LOADER_MANIFEST)

$(BPF_OBJ): x86_vm.bpf.c xvm_abi.h
	mkdir -p $(BUILD_DIR)
	$(CLANG) -g -O2 -target bpf -D__TARGET_ARCH_x86 \
		-I$(ROOT_DIR)/vendor/libbpf/include/uapi \
		-I$(ROOT_DIR)/vendor/libbpf/src \
		-I/usr/include/x86_64-linux-gnu \
		-c x86_vm.bpf.c -o $(BPF_OBJ)

run: build
	$(LOADER_BIN) --object $(BPF_OBJ) --case simple

clean:
	rm -rf $(BUILD_DIR) loader/target
