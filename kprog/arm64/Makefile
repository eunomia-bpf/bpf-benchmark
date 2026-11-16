ROOT_DIR := ../..
OUTPUT_DIR ?= build
BUILD_DIR := $(OUTPUT_DIR)
MICRO_CONFIG ?= $(ROOT_DIR)/micro/config/micro_pure_jit.yaml
MICRO_PROG_DIR := micro-prog
PROOF_BUILD_DIR ?= $(MICRO_PROG_DIR)/build
NEGATIVE_PROOF_BUILD_DIR ?= $(PROOF_BUILD_DIR)/negative
NEGATIVE_NATIVE_BUILD_DIR ?= build/negative-native
NEGATIVE_CONFIG := ../test/kprog_negative_stage2.yaml
NEGATIVE_PROGRAM := unchecked_packet_read

PYTHON ?= python3
SYS_INCLUDE_FLAGS ?= -I/usr/aarch64-linux-gnu/include -I$(ROOT_DIR)/.cache/aarch64-sysroot/usr/include -I$(ROOT_DIR)/.cache/aarch64-sysroot/usr/include/aarch64-linux-gnu

.PHONY: micro-proofs-build kprog-negative-proof-build clean

arm64_sim_direct.h: arm64_sim_local_bpf.h arm64_sim.h generate_sim_dispatch.py $(wildcard ../formal/generated/*.h)
	$(PYTHON) generate_sim_dispatch.py

micro-proofs-build: arm64_sim_direct.h kprog-negative-proof-build
	$(PYTHON) ../run_micro_sim_batch.py --arch arm64 \
		--build-dir "$(PROOF_BUILD_DIR)" \
		--config "$(MICRO_CONFIG)" \
		$(MICRO_SIM_PROOF_ARGS)

kprog-negative-proof-build: arm64_sim_direct.h
	$(MAKE) -C ../test \
		OUTPUT_DIR="$(abspath $(NEGATIVE_NATIVE_BUILD_DIR))" \
		KERNEL_OFFSETS_DIR="$(abspath $(ROOT_DIR)/micro/programs/build-arm64)" \
		NATIVE_TARGET=aarch64-linux-gnu \
		NATIVE_ARCH=arm64 \
		SYS_INCLUDE_FLAGS="$(SYS_INCLUDE_FLAGS)" \
		"$(abspath $(NEGATIVE_NATIVE_BUILD_DIR))/$(NEGATIVE_PROGRAM).native.o"
	$(PYTHON) ../run_micro_sim_batch.py --arch arm64 \
		--build-dir "$(NEGATIVE_PROOF_BUILD_DIR)" \
		--native-build-dir "$(NEGATIVE_NATIVE_BUILD_DIR)" \
		--config "$(NEGATIVE_CONFIG)" \
		--jobs 1

clean:
	rm -rf $(BUILD_DIR)
