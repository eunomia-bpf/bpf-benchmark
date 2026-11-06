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

.PHONY: bounded-check
bounded-check:
	taskset -c 16-23 python3 $(HERE)/bounded_check.py $(HERE)/$(PHASE)

.PHONY: control-host-check
control-host-check:
	taskset -c 16-23 python3 $(HERE)/register_cells_check.py $(HERE)/$(PHASE) a64_route_host test_arm64_call_ret_route_host


.PHONY: bounded-negative-check
bounded-negative-check:
	python3 $(HERE)/bounded_negative.py $(HERE)/$(PHASE) generate
	$(MAKE) -f $(HERE)/Makefile compile PHASE=$(PHASE) COMPILE_ARGS='0 1 900'
	! $(MAKE) -f $(HERE)/Makefile verify PHASE=$(PHASE)
	python3 $(HERE)/bounded_negative.py $(HERE)/$(PHASE) check
	$(MAKE) -f $(HERE)/Makefile summarize PHASE=$(PHASE)


.PHONY: return-negative-check
return-negative-check:
	python3 $(HERE)/return_negative.py $(HERE)/$(PHASE) generate
	$(MAKE) -f $(HERE)/Makefile compile PHASE=$(PHASE) COMPILE_ARGS='0 6 900 1 2048'
	! $(MAKE) -f $(HERE)/Makefile verify PHASE=$(PHASE)
	python3 $(HERE)/return_negative.py $(HERE)/$(PHASE) check
	$(MAKE) -f $(HERE)/Makefile summarize PHASE=$(PHASE)

.PHONY: control-artifacts
control-artifacts:
	tar -C $(ROOT)/kprog/arm64/build/bounded-dispatch -czf $(HERE)/bounded-return-v2/native-fixtures.tar.gz native bounded_branch.proof.o bounded_dispatch.proof.o
	tar -C $(HERE)/return-forgery -czf $(HERE)/return-forgery/native-fixtures.tar.gz outer_scalar_zero.S outer_scalar_zero.asm outer_scalar_zero.proof.o local_scalar_pc.S local_scalar_pc.asm local_scalar_pc.proof.o

.PHONY: abi-stage2-build abi-negative-build
abi-stage2-build:
	taskset -c 16-23 python3 $(ROOT)/kprog/fidelity/stage2.py build --arch arm64 --build $(HERE)/$(PHASE)

abi-negative-build:
	taskset -c 16-23 $(MAKE) -C $(ROOT)/kprog/fidelity negative-build ARCH=arm64 NEGATIVE_BUILD=$(HERE)/$(PHASE)


.PHONY: abi-effect-check
abi-effect-check:
	taskset -c 16-23 python3 $(HERE)/abi_check.py $(HERE)/$(PHASE)


.PHONY: generate-frozen
generate-frozen:
	python3 $(HERE)/freeze_constructor.py $(HERE)/$(PHASE)
	taskset -c 16-19 $(MAKE) -C $(ROOT)/kprog/arm64 app-proofs-build \
		APP_SIM_PROOF_ARGS='--generate-only --proof-root $(HERE)/$(PHASE)/input --generator $(HERE)/$(PHASE)/constructor/kprog/arm64/micro-prog/generate_micro_sim_proofs.py --report-dir $(HERE)/$(PHASE) --output-dir $(ROOT)/kprog/arm64/app-coverage-$(PHASE)'


.PHONY: abi-negative-bound
abi-negative-bound: abi-negative-build
	cp $(ROOT)/kprog/fidelity/build-arm64/bound-probe $(HERE)/bound-probe
	cp $(ROOT)/kprog/fidelity/build-arm64/negative-companion.bpf.o $(HERE)/negative-companion.bpf.o
	aarch64-linux-gnu-gcc -Wall -Wextra -Werror -O2 -static -DBOUND_NEGATIVE $(ROOT)/kprog/fidelity/negative_init.c -o $(HERE)/negative-bound-init
	python3 $(ROOT)/kprog/fidelity/negative.py package-bound --arch arm64 --build $(HERE)/$(PHASE)
	taskset -c 12-15 timeout 300 qemu-system-aarch64 -M virt -cpu cortex-a57 -smp 2 -m 2048 \
		-nographic -no-reboot -kernel $(ROOT)/kprog/tv/build-kernel-arm64/arch/arm64/boot/Image \
		-initrd $(HERE)/negative-bound.cpio -append 'console=ttyAMA0 rdinit=/init panic=-1' \
		>$(HERE)/$(PHASE)/guest-console.log 2>&1
	python3 $(ROOT)/kprog/fidelity/negative.py collect-bound --arch arm64 --build $(HERE)/$(PHASE) --out $(HERE)/$(PHASE)

.PHONY: abi-artifacts
abi-artifacts:
	tar -C $(HERE) -czf $(HERE)/abi-constructor-artifacts.tar.gz abi-effects-before abi-effects-fixed abi-effects-tail abi-negative-final abi-stage2-final abi-positives-fixed abi_check.py

.PHONY: abi-positive-identity
abi-positive-identity:
	python3 -c 'from pathlib import Path; base=Path("$(HERE)"); new=list((base/"abi-positives-fixed/sources").glob("*.bpf.c")); assert len(new)==29; assert all(p.read_bytes()==(base/"control-return-micro/sources"/p.name).read_bytes() for p in new); print("29 current ABI-checked C sources exactly match the 29 full-system QEMU passes")'

.PHONY: abi-census-artifacts
abi-census-artifacts:
	tar -C $(HERE)/defined-frozen -czf $(HERE)/defined-frozen/constructor-inputs.tar.gz constructor input commands.jsonl
	tar -C $(ROOT) -czf $(HERE)/abi-bound-runtime.tar.gz kprog/tv/build-kernel-arm64/arch/arm64/boot/Image corpus/results/kprog_arm64_app_coverage_20261106/negative-bound.cpio kprog/fidelity/negative.py kprog/fidelity/negative_init.c kprog/fidelity/bound_probe.cpp kprog/fidelity/negative_companion.bpf.c

.PHONY: runtime-preflight-capture
runtime-preflight-capture:
	python3 $(HERE)/runtime_preflight.py $(HERE)/$(PHASE)

.PHONY: sp-write-check
sp-write-check:
	python3 $(HERE)/sp_write_check.py $(HERE)/$(PHASE)

.PHONY: sp-write-artifacts
sp-write-artifacts:
	tar -C $(HERE)/$(PHASE) -czf $(HERE)/$(PHASE)/native-fixtures.tar.gz main.c sp_restore.S sp_restore.asm sp_restore.proof.o native native.json

.PHONY: runtime-complete-capture
runtime-complete-capture:
	python3 $(HERE)/runtime_complete.py $(HERE)/$(PHASE)

.PHONY: native-link-check native-link-build native-link-ro-artifacts
native-link-check:
	taskset -c 16-23 cargo test --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml --target-dir $(ROOT)/kprog/arm64/build/app-native-link

native-link-build:
	taskset -c 16-23 cargo build --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml --target-dir $(ROOT)/kprog/arm64/build/app-native-link

native-link-ro-artifacts:
	tar -C $(ROOT) -czf $(HERE)/readonly-link/replay.tar.gz -T $(HERE)/readonly-link/replay-files.txt

.PHONY: bcc-real-generate
bcc-real-generate: native-link-build
	python3 $(HERE)/bcc_real.py $(HERE)/$(PHASE) $(ROOT)/kprog/arm64/build/app-native-link/release/native-link

.PHONY: bcc-real-manifest
bcc-real-manifest:
	python3 $(HERE)/bcc_manifest.py $(HERE)/$(PHASE)

.PHONY: stack-store-check
stack-store-check:
	python3 $(HERE)/stack_store_check.py $(HERE)/$(PHASE)

.PHONY: memory-tags-check
memory-tags-check:
	python3 $(HERE)/memory_tags_check.py $(HERE)/$(PHASE)

.PHONY: return-byte-before
return-byte-before:
	python3 $(HERE)/return_byte_before.py $(HERE)/$(PHASE)
	$(MAKE) -f $(HERE)/Makefile compile PHASE=$(PHASE) COMPILE_ARGS='0 2 900 1 2048'
	! $(MAKE) -f $(HERE)/Makefile verify PHASE=$(PHASE)

.PHONY: bcc-real-verify-build
bcc-real-verify-build:
	aarch64-linux-gnu-g++ -std=c++20 -Wall -Wextra -Werror -O2 -static \
		-I$(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/prefix/include \
		$(ROOT)/corpus/results/kprog_app_coverage_20261106/verify_proof.cpp \
		$(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/pic-obj/libbpf.a \
		-L$(ROOT)/.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu -lelf -lz -lzstd \
		-o $(HERE)/verify-proof

.PHONY: bcc-real-verify-package
bcc-real-verify-package:
	python3 $(HERE)/bcc_verify_package.py $(HERE)/$(PHASE) $(BASE_INITRAMFS)

.PHONY: bcc-real-verify
bcc-real-verify: bcc-real-verify-package
	install -d $(HERE)/$(PHASE)/verify
	taskset -c 12-15 timeout 7200 qemu-system-aarch64 -M virt -cpu max -smp 2 -m 2048 -nographic -no-reboot \
		-kernel /workspaces/.agent-state/kprog-lanes/T/paired-input-abi2/arm64/Image -initrd $(BUILD)/initramfs.cpio.gz \
		-fsdev local,id=results,path=$(HERE)/$(PHASE)/verify,security_model=none \
		-device virtio-9p-device,fsdev=results,mount_tag=results \
		-append 'console=ttyAMA0 rdinit=/init loglevel=4 panic=30 oops=panic' >$(HERE)/$(PHASE)/qemu.log 2>&1
	test "$$(cat $(HERE)/$(PHASE)/verify/guest-status)" = 0

.PHONY: bcc-tag-words
bcc-tag-words:
	python3 $(HERE)/bcc_tag_words.py $(HERE)/$(PHASE)
	$(MAKE) -f $(HERE)/Makefile compile PHASE=$(PHASE) COMPILE_ARGS='0 23 900 1 2048'
	$(MAKE) -f $(HERE)/Makefile bcc-real-verify PHASE=$(PHASE)

.PHONY: bcc-packed-tags
bcc-packed-tags:
	python3 $(HERE)/bcc_tag_words.py $(HERE)/$(PHASE) packed
	$(MAKE) -f $(HERE)/Makefile compile PHASE=$(PHASE) COMPILE_ARGS='0 23 900 1 2048'
	$(MAKE) -f $(HERE)/Makefile bcc-real-verify PHASE=$(PHASE)

.PHONY: memory-results
memory-results:
	python3 $(HERE)/memory_results.py

.PHONY: memory-artifacts
memory-artifacts:
	tar -C $(HERE) -czf $(HERE)/memory-extension/replay.tar.gz \
		abi-memory-final-v2 memory-tags-packed stack-store-packed memory-final-micro memory-final-stage2 \
		bcc-real-entries-v8 bcc-real-entries-v9 bcc-tag-word bcc-packed-tags bcc-packed-tags-v2 \
		memory-return-final return-byte-before
