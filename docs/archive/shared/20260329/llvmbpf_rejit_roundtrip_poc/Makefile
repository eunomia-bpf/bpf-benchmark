ROOT_DIR := $(abspath $(CURDIR)/../../../..)
BUILD_DIR := $(CURDIR)/build
LLVM_CONFIG ?= llvm-config
CMAKE ?= cmake

.PHONY: all host-lifter guest-helper clean

all: host-lifter guest-helper

host-lifter:
	$(CMAKE) -S "$(CURDIR)" -B "$(BUILD_DIR)" -DCMAKE_BUILD_TYPE=Release -DLLVM_DIR="$$( $(LLVM_CONFIG) --cmakedir )"
	$(CMAKE) --build "$(BUILD_DIR)" --target llvmbpf-raw-lift -j4

guest-helper:
	cargo build --release --manifest-path "$(CURDIR)/guest_helper/Cargo.toml"

clean:
	rm -rf "$(BUILD_DIR)" "$(CURDIR)/guest_helper/target"
