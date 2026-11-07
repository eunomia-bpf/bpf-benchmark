ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/negative/arm64-trusted-sp
RUN_OUT ?= $(OUT)
.PHONY: build qemu
build:
	python3 $(OUT)/replay.py build
qemu:
	python3 $(OUT)/replay.py host --out $(RUN_OUT)

.PHONY: linker-build
linker-build:
	CARGO_TARGET_DIR=$(ROOT)/kprog/fidelity/build-return-linker cargo test --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml arm64_
	CARGO_TARGET_DIR=$(ROOT)/kprog/fidelity/build-return-linker CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER=aarch64-linux-gnu-gcc cargo build --release --target aarch64-unknown-linux-gnu --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml
