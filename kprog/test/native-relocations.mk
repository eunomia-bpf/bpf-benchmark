SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
LINKER_TARGET := $(ROOT)/kprog/x86/native_lab/native_link/target
OUTPUT ?= /workspaces/kprog-raw/perf/20261115-native-relocations

.PHONY: check build
check:
	taskset -c 8-11 prlimit --as=8589934592 -- env CARGO_BUILD_JOBS=2 CARGO_TARGET_DIR=$(LINKER_TARGET) cargo test --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml

build:
	taskset -c 8-11 prlimit --as=8589934592 -- env CARGO_BUILD_JOBS=2 CARGO_TARGET_DIR=$(LINKER_TARGET) cargo build --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml
