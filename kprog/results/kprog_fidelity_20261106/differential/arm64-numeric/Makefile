ROOT := $(abspath ../../../../..)
BUILD := build-arm64-numeric
.PHONY: build run
build:
	$(MAKE) -C $(ROOT)/kprog/fidelity build ARCH=arm64 BUILD=$(BUILD)
run:
	$(MAKE) -C $(ROOT)/kprog/fidelity run-emulated ARCH=arm64 BUILD=$(BUILD) OUT=$(CURDIR) CASES=1024
.PHONY: control
control:
	$(MAKE) -C $(ROOT)/kprog/fidelity arm64-control-build arm64-control-qemu ARM64_CONTROL_BUILD=build-arm64-control-numeric ARM64_CONTROL_OUT=$(CURDIR)/control CASES=1024
POS := $(ROOT)/kprog/fidelity/build-arm64/numeric-positive
.PHONY: positive-build positive-run
positive-build:
	python3 positive.py $(POS)
	python3 $(ROOT)/kprog/fidelity/negative.py package-bound --arch arm64 --build $(POS)
	cp $(dir $(POS))negative-bound.cpio $(POS)/init.cpio
positive-run:
	install -d positive
	timeout 240 qemu-system-aarch64 -M virt -cpu cortex-a57 -smp 2 -m 2048 -nographic -no-reboot -kernel $(ROOT)/kprog/tv/build-kernel-arm64/arch/arm64/boot/Image -initrd $(POS)/init.cpio -append 'console=ttyAMA0 rdinit=/init panic=-1' > positive/guest-console.log 2>&1
	python3 $(ROOT)/kprog/fidelity/negative.py collect-bound --arch arm64 --build $(POS) --out positive
.PHONY: host
host:
	cd $(ROOT)/kprog/formal && set -e; for name in test_arm64_dispatch_singleton_route_host test_arm64_dispatch_family_route_host test_arm64_alu_operand_select_route_host test_arm64_pair_mem_route_host test_arm64_stack_arm_route_host test_arm64_stack_arena_route_host test_arm64_stack_write_lanes_route_host test_arm64_stack_write_tag_action_route_host test_arm64_stack_read_tag_source_route_host; do \
		cc -O2 -Wall -Wextra -I. -I../arm64 -I.. -I../../vendor/libbpf/src -include oracles/arm64_entry_environment_host.h -DKPROG_TEST_EXCLUSIVE_FAILURE=0 -include oracles/arm64_exclusive_choice_host.h oracles/$$name.c -o build/$$name-f-numeric; \
		./build/$$name-f-numeric; \
	done
.PHONY: reference
reference:
	python3 $(ROOT)/kprog/fidelity/reference_check.py --binary $(ROOT)/kprog/fidelity/$(BUILD)/cpu-differential --arch arm64 --cases 1024 --out . --reference $(ROOT)/kprog/formal/.lake/build/bin/reference
.PHONY: lean
lean:
	cd $(ROOT)/kprog/formal && lake build KProgFormal.Refinement.Arm64NumericAddress
