ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../../..)
HERE := $(ROOT)/corpus/results/kprog_arm64_app_coverage_20261106
PHASE ?= exact
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
