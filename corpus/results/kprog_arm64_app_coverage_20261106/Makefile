ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../../..)
HERE := $(ROOT)/corpus/results/kprog_arm64_app_coverage_20261106
PHASE ?= exact
SOURCE_PHASE ?= compare-gt
BUILD := $(ROOT)/kprog/arm64/build/app-coverage/$(PHASE)
BASE_INITRAMFS ?= /workspaces/.agent-state/bpf-benchmark-supervisor/kfunc-inline-claude-20261004/round5-arm64.cpio.gz
KERNEL ?= $(ROOT)/vendor/build/arm64/linux/arch/arm64/boot/Image

.PHONY: generate compile summarize package verify

generate:
	taskset -c 16-19 $(MAKE) -C $(ROOT)/kprog/arm64 app-proofs-build APP_SIM_PROOF_ARGS='--generate-only --report-dir $(HERE)/$(PHASE) --output-dir $(ROOT)/kprog/arm64/app-coverage-$(PHASE)'

compile:
	taskset -c 16-23 python3 $(HERE)/coverage.py compile $(HERE)/$(PHASE) $(COMPILE_ARGS)

summarize:
	python3 $(HERE)/coverage.py summarize $(HERE)/$(PHASE)

package:
	python3 $(HERE)/coverage.py package $(HERE)/$(PHASE) $(BUILD) $(BASE_INITRAMFS)

verify: package
	install -d $(HERE)/$(PHASE)/verify
	taskset -c 16-19 timeout 7200 qemu-system-aarch64 -M virt -cpu max -smp 2 -m 2048 -nographic -no-reboot \
		-kernel $(KERNEL) -initrd $(BUILD)/initramfs.cpio.gz \
		-fsdev local,id=results,path=$(HERE)/$(PHASE)/verify,security_model=none \
		-device virtio-9p-device,fsdev=results,mount_tag=results \
		-append 'console=ttyAMA0 rdinit=/init loglevel=4 panic=30 oops=panic' >$(HERE)/$(PHASE)/qemu.log 2>&1
	test "$$(cat $(HERE)/$(PHASE)/verify/guest-status)" = 0

.PHONY: bundle
bundle: package
	install -d $(BUILD)/replay
	cp $(KERNEL) $(BUILD)/replay/Image
	cp $(BUILD)/initramfs.cpio.gz $(BUILD)/replay/initramfs.cpio.gz
	cp $(HERE)/Replay.mk $(BUILD)/replay/Makefile
	tar -C $(BUILD)/replay -czf $(BUILD)/replay.tar.gz Image initramfs.cpio.gz Makefile

.PHONY: helper-contract-generate
helper-contract-generate:
	cd $(ROOT)/kprog/formal && python3 tools/generate_arm64_helper_idents_spec.py

.PHONY: inventory
inventory:
	python3 $(HERE)/coverage.py inventory $(HERE)/inventory

.PHONY: helper-contract-check
helper-contract-check:
	cd $(ROOT)/kprog/formal && lake build KProgFormal.Arm64HelperIdents
	cd $(ROOT)/kprog/formal && python3 tools/generate_arm64_helper_idents_spec.py --check
	cd $(ROOT)/kprog/formal && python3 tools/check_helper_idents.py
	cd $(ROOT)/kprog/formal && cc -Wall -Wextra -O2 -I. oracles/test_arm64_helper_idents_host.c -o build/test_arm64_helper_idents_host
	$(ROOT)/kprog/formal/build/test_arm64_helper_idents_host
	cd $(ROOT)/kprog/formal && cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_helper_call_host.c -o build/test_arm64_helper_call_host
	$(ROOT)/kprog/formal/build/test_arm64_helper_call_host

.PHONY: register-cell-host-check write-arm-generate
register-cell-host-check:
	taskset -c 16-23 python3 $(HERE)/register_cells_check.py $(HERE)/$(PHASE)

write-arm-generate:
	cd $(ROOT)/kprog/formal && python3 tools/generate_arm64_write_arm_spec.py

.PHONY: helper-abi-update
helper-abi-update:
	python3 $(HERE)/generate_helpers.py
	$(MAKE) -f $(HERE)/Makefile helper-contract-generate

.PHONY: census
census:
	python3 $(HERE)/coverage.py census $(HERE)/complete $(HERE)/real-helpers $(HERE)/helper-complete-75

.PHONY: compare-cond-proof compare-cond-generate compare-cond-host
compare-cond-proof:
	cd $(ROOT)/kprog/formal && taskset -c 16-23 lake build KProgFormal.Arm64CompareCond

compare-cond-generate:
	python3 $(HERE)/compare_check.py $(HERE)/$(PHASE)

compare-cond-host:
	taskset -c 16-23 python3 $(HERE)/register_cells_check.py $(HERE)/$(PHASE) test_arm64_compare_cond_host

.PHONY: specialize-constant-dispatch
specialize-constant-dispatch:
	python3 $(HERE)/specialize.py $(HERE)/$(PHASE) $(HERE)/$(SOURCE_PHASE)

.PHONY: direct-differential
direct-differential:
	$(MAKE) -C $(ROOT)/kprog/fidelity ARCH=arm64 BUILD=build-arm64-a-direct build-arm64-a-direct/generated.c
	python3 $(HERE)/direct_differential.py $(HERE)/$(PHASE)
	taskset -c 16-23 $(MAKE) -C $(ROOT)/kprog/fidelity ARCH=arm64 BUILD=build-arm64-a-direct OUT=$(HERE)/$(PHASE)/differential CASES=1024 run-emulated

.PHONY: generate-micro-cases
generate-micro-cases:
	python3 $(HERE)/generate_micro_cases.py $(HERE)/$(PHASE)

.PHONY: direct-header-generate direct-header-check
direct-header-generate:
	python3 $(ROOT)/kprog/arm64/generate_sim_dispatch.py

direct-header-check:
	python3 $(ROOT)/kprog/arm64/generate_sim_dispatch.py --check

.PHONY: unary-check
unary-check:
	python3 $(HERE)/unary_check.py --arch arm64 --out $(ROOT)/kprog/fidelity/build-arm64-a-unary
	taskset -c 16-23 $(MAKE) -C $(ROOT)/kprog/fidelity ARCH=arm64 BUILD=build-arm64-a-unary OUT=$(HERE)/$(PHASE)/differential CASES=1024 run-emulated


.PHONY: unary-artifacts
unary-artifacts:
	tar -C $(ROOT)/kprog/fidelity -czf $(HERE)/$(PHASE)/replay.tar.gz driver.c driver.h generate.py tcb.py build-arm64-a-unary/generated.c build-arm64-a-unary/native.S build-arm64-a-unary/native.o build-arm64-a-unary/instructions.S build-arm64-a-unary/instructions.asm build-arm64-a-unary/coverage.json build-arm64-a-unary/cpu-differential build-arm64-a-unary/snapshot
