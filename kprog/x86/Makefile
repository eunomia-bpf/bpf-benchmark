ROOT_DIR := ../..
BUILD_DIR := build
MICRO_CONFIG ?= $(ROOT_DIR)/micro/config/micro_pure_jit.yaml
PROOF_BUILD_DIR ?= micro-prog/build
NEGATIVE_PROOF_BUILD_DIR ?= $(PROOF_BUILD_DIR)/negative
NEGATIVE_NATIVE_BUILD_DIR ?= build/negative-native
NEGATIVE_CONFIG := ../test/kprog_negative_stage2.yaml
NEGATIVE_PROGRAM := unchecked_packet_read

PYTHON ?= python3

.PHONY: micro-proofs-build kprog-negative-proof-build clean

micro-proofs-build: kprog-negative-proof-build
	$(PYTHON) ../run_micro_sim_batch.py --arch x86 \
		--build-dir "$(PROOF_BUILD_DIR)" \
		--config "$(MICRO_CONFIG)" \
		$(MICRO_SIM_PROOF_ARGS)

kprog-negative-proof-build:
	$(MAKE) -C ../test \
		OUTPUT_DIR="$(abspath $(NEGATIVE_NATIVE_BUILD_DIR))" \
		KERNEL_OFFSETS="$(abspath $(ROOT_DIR)/micro/programs/build-x86/kernel_offsets.h)" \
		"$(abspath $(NEGATIVE_NATIVE_BUILD_DIR))/$(NEGATIVE_PROGRAM).native.o"
	$(PYTHON) ../run_micro_sim_batch.py --arch x86 \
		--build-dir "$(NEGATIVE_PROOF_BUILD_DIR)" \
		--native-build-dir "$(NEGATIVE_NATIVE_BUILD_DIR)" \
		--config "$(NEGATIVE_CONFIG)" \
		--jobs 1

clean:
	rm -rf $(BUILD_DIR)
