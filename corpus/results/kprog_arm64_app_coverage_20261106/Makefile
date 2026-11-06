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
	taskset -c 16-19 python3 $(HERE)/coverage.py compile $(HERE)/$(PHASE)

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
