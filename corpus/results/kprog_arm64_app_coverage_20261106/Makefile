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

.PHONY: native-link-arm64
native-link-arm64:
	CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER=aarch64-linux-gnu-gcc \
		taskset -c 16-23 cargo build --release --target aarch64-unknown-linux-gnu \
		--manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml --target-dir $(ROOT)/kprog/arm64/build/app-native-link
	install -m 0755 $(ROOT)/kprog/arm64/build/app-native-link/aarch64-unknown-linux-gnu/release/native-link \
		$(ROOT)/kprog/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link

.PHONY: readonly-bound-build
readonly-bound-build:
	python3 $(HERE)/readonly_bound.py $(HERE)/$(PHASE) prepare
	for name in readonly_7 readonly_64 readonly_119; do \
		clang -g -O2 -target bpf -D__TARGET_ARCH_arm64 \
		-I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu \
		-c $(HERE)/$(PHASE)/$$name.bpf.c -o $(HERE)/$(PHASE)/$$name.bpf.o || exit 1; \
		clang -g -O2 -target bpf -D__TARGET_ARCH_arm64 -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu \
		-c $(HERE)/$(PHASE)/$$name.no-addend.bpf.c -o $(HERE)/$(PHASE)/$$name.no-addend.bpf.o || exit 1; \
		clang -g -O2 -target bpf -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src \
		-I/usr/include/x86_64-linux-gnu -c $(HERE)/$(PHASE)/$$name.source.bpf.c -o $(HERE)/$(PHASE)/$$name.source.bpf.o || exit 1; \
	done
	aarch64-linux-gnu-g++ -std=c++20 -Wall -Wextra -Werror -O2 -static -D__EXPORTED_HEADERS__ -DNATIVE_LINK_PATH='"/native-link"' \
		-I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/prefix/include \
		$(ROOT)/kprog/fidelity/bound_probe.cpp /workspaces/.agent-state/kprog-lanes/T/paired-context-v2/arm64/libnative_loader.a \
		$(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/pic-obj/libbpf.a \
		-L$(ROOT)/.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu -lelf -lz -lzstd -ldl -o $(HERE)/$(PHASE)/bound-probe

.PHONY: readonly-bound-package
readonly-bound-package:
	python3 $(HERE)/readonly_bound.py $(HERE)/$(PHASE) package $(BASE_INITRAMFS)

.PHONY: readonly-bound-check
readonly-bound-check: readonly-bound-package
	install -d $(HERE)/$(PHASE)/verify
	taskset -c 12-15 timeout 600 qemu-system-aarch64 -M virt -cpu max -smp 2 -m 2048 -nographic -no-reboot \
		-kernel /workspaces/.agent-state/kprog-lanes/T/paired-context-v2/arm64/Image -initrd $(BUILD)/initramfs.cpio.gz \
		-fsdev local,id=results,path=$(HERE)/$(PHASE)/verify,security_model=none \
		-device virtio-9p-device,fsdev=results,mount_tag=results \
		-append 'console=ttyAMA0 rdinit=/init loglevel=4 panic=30 oops=panic' >$(HERE)/$(PHASE)/qemu.log 2>&1
	test "$$(cat $(HERE)/$(PHASE)/verify/guest-status)" = 0
	python3 $(HERE)/readonly_bound.py $(HERE)/$(PHASE) collect

.PHONY: readonly-bound-artifacts
readonly-bound-artifacts:
	install -d $(HERE)/$(PHASE)/runtime
	cp $(BOUND_KERNEL) $(HERE)/$(PHASE)/runtime/Image
	cp $(BUILD)/initramfs.cpio.gz $(HERE)/$(PHASE)/runtime/initramfs.cpio.gz
	cp $(HERE)/Replay.mk $(HERE)/$(PHASE)/runtime/Makefile
	tar --exclude=replay.tar.gz -C $(HERE)/$(PHASE) -czf $(BUILD)/replay.tar.gz .
	mv $(BUILD)/replay.tar.gz $(HERE)/$(PHASE)/replay.tar.gz

APP ?= bcc/set
VM_CPUS ?= 8
RUNTIME_BASE ?= $(ROOT)/kprog/arm64/build/app-runtime-v2
RUNTIME_IMAGE ?= bpf-benchmark/runner-runtime:arm64-a-context-v2
RUNTIME_SHIM_BUILD ?= $(ROOT)/bpfopt/shim/build-arm64-a-context-v2
TETRAGON_ALIGN_BUILD := $(ROOT)/kprog/arm64/build/tetragon-alignchecker

.PHONY: tetragon-alignchecker
tetragon-alignchecker:
	install -d $(TETRAGON_ALIGN_BUILD)/objs $(TETRAGON_ALIGN_BUILD)/deps
	taskset -c 16-23 $(MAKE) -C $(ROOT)/vendor/repos/tetragon/bpf -f Makefile -f $(HERE)/TetragonObjects.mk CLANG=clang \
		BPF_TARGET_ARCH=arm64 OBJSDIR=$(TETRAGON_ALIGN_BUILD)/objs/ DEPSDIR=$(TETRAGON_ALIGN_BUILD)/deps/ \
		$(TETRAGON_ALIGN_BUILD)/objs/bpf_alignchecker.o
	install -m 0644 $(TETRAGON_ALIGN_BUILD)/objs/bpf_alignchecker.o $(ROOT)/vendor/build/arm64/tetragon/bpf_alignchecker.o

.PHONY: readonly-metadata-check
readonly-metadata-check:
	python3 $(HERE)/readonly_metadata.py $(HERE)/$(PHASE)

.PHONY: pin-runtime-v2
pin-runtime-v2:
	python3 $(HERE)/pin_runtime.py $(RUNTIME_BASE)

.PHONY: runtime-shim-v2
runtime-shim-v2:
	python3 $(HERE)/pin_shim.py
	taskset -c 16-23 $(MAKE) -C $(ROOT) host-shim-arm64 \
		BPFOPT_SHIM_DIR=$(ROOT)/kprog/arm64/build/published-shim-v8/bpfopt/shim \
		BPFOPT_SHIM_BUILD_ARM64=$(RUNTIME_SHIM_BUILD)

.PHONY: qemu-context-v2-root
qemu-context-v2-root:
	taskset -c 16-23 $(MAKE) -C $(ROOT) PLATFORM=qemu ARCH=arm64 arm64-qemu-root \
		-o host-kernel-arm64 -o host-kinsn-arm64 -o host-rust-arm64 -o host-shim-arm64 \
		-o host-source-apps-arm64 -o host-runner-arm64 -o host-micro-programs-arm64 \
		-o host-stage2-programs-arm64 -o host-arm64-sim-proofs -o host-bpfopt-llvm-arm64 \
		-o host-native-bpf-arm64 -o host-merlin-runtime-context \
		RUNNER_DIR=$(RUNTIME_BASE)/runner \
		HOST_KERNEL_BUILD_DIR_ARM64=$(RUNTIME_BASE)/kernel \
		HOST_KINSN_DIR_ARM64=$(RUNTIME_BASE)/kinsn \
		BPFOPT_SHIM_BUILD_ARM64=$(RUNTIME_SHIM_BUILD) \
		NATIVE_BPF_ARTIFACTS_ARM64=$(ROOT)/kprog/arm64/build/app-verified-stage \
		ARM64_RUNNER_RUNTIME_IMAGE=$(RUNTIME_IMAGE) \
		ARM64_RUNNER_RUNTIME_IMAGE_TAR=$(RUNTIME_BASE)/image.tar \
		ARM64_QEMU_ROOT=$(RUNTIME_BASE)/root

.PHONY: qemu-context-v2-app
qemu-context-v2-app:
	taskset -c 8-11 timeout 7200 $(MAKE) -C $(ROOT) PLATFORM=qemu ARCH=arm64 corpus \
		-o $(RUNTIME_BASE)/root/qemu-init \
		ARM64_QEMU_ROOT=$(RUNTIME_BASE)/root \
		ARM64_QEMU_KERNEL_IMAGE=$(RUNTIME_BASE)/kernel/arch/arm64/boot/Image \
		ARM64_RUNNER_RUNTIME_IMAGE=$(RUNTIME_IMAGE) \
		ARM64_RUNNER_RUNTIME_IMAGE_TAR=$(RUNTIME_BASE)/image.tar \
		VM_CPUS=$(VM_CPUS) VM_MEM=4096 SAMPLES=1 WORKLOAD_DURATION=2 KEEP_WORKDIRS=1 \
		BPFREJIT_CORPUS_APP_TIMEOUT=7200 \
		BPFREJIT_KEEP_ALL_WORKDIRS=1 BPFREJIT_CORPUS_BPF_STATS=1 \
		BPFREJIT_CORPUS_APPS=$(APP) BPFREJIT_SHIM_NATIVE_LOADER=post \
		BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1

.PHONY: runtime-results
runtime-results:
	python3 $(HERE)/runtime_results.py $(RUNTIME_RESULTS_ARGS)

.PHONY: katran-root-build
katran-root-build: direct-header-generate
	python3 $(HERE)/katran_root.py $(HERE)/$(PHASE)
	clang -g -O2 -target bpf -D__TARGET_ARCH_arm64 \
		-I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu \
		-c $(HERE)/$(PHASE)/katran_xdp_root.bpf.c -o $(HERE)/$(PHASE)/katran_xdp_root.bpf.o
	clang -g -O2 -target bpf -D__TARGET_ARCH_arm64 \
		-I$(ROOT)/vendor/bpf/katran/katran/lib/linux_includes -I/usr/include/x86_64-linux-gnu \
		-c $(HERE)/$(PHASE)/original-source.c -o $(HERE)/$(PHASE)/katran_xdp_root.source.bpf.o

.PHONY: katran-root-install
katran-root-install:
	python3 $(HERE)/katran_root.py $(HERE)/$(PHASE) install

.PHONY: tetragon-objects
tetragon-objects:
	install -d $(TETRAGON_ALIGN_BUILD)/objs $(TETRAGON_ALIGN_BUILD)/deps
	taskset -c 12-15 $(MAKE) -j2 -C $(ROOT)/vendor/repos/tetragon/bpf -f Makefile -f $(HERE)/TetragonObjects.mk CLANG=clang \
		BPF_TARGET_ARCH=arm64 OBJSDIR=$(TETRAGON_ALIGN_BUILD)/objs/ DEPSDIR=$(TETRAGON_ALIGN_BUILD)/deps/ all
	install -m 0644 $(TETRAGON_ALIGN_BUILD)/objs/*.o $(ROOT)/vendor/build/arm64/tetragon/

.PHONY: fmov-bank-build
fmov-bank-build: direct-header-generate
	python3 $(HERE)/fmov_bank.py $(HERE)/$(PHASE) prepare
	for source in $(HERE)/$(PHASE)/*.bpf.c; do \
		clang -g -O2 -target bpf -D__TARGET_ARCH_arm64 \
		-I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu \
		-c $$source -o $${source%.c}.o || exit 1; \
	done
	aarch64-linux-gnu-g++ -std=c++20 -Wall -Wextra -Werror -O2 -static -D__EXPORTED_HEADERS__ -DNATIVE_LINK_PATH='"/native-link"' \
		-I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/prefix/include \
		$(ROOT)/kprog/fidelity/bound_probe.cpp /workspaces/.agent-state/kprog-lanes/T/context-v2-datasec/arm64/libnative_loader.a \
		$(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/pic-obj/libbpf.a \
		-L$(ROOT)/.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu -lelf -lz -lzstd -ldl -o $(HERE)/$(PHASE)/bound-probe

.PHONY: fmov-bank-package
BOUND_KERNEL ?= /workspaces/.agent-state/kprog-lanes/T/paired-context-v2/arm64/Image
BOUND_MODULE ?= /workspaces/.agent-state/kprog-lanes/T/paired-context-v2/arm64/bpf_arm64_native_lab.ko
fmov-bank-package:
	python3 $(HERE)/fmov_bank.py $(HERE)/$(PHASE) package $(BASE_INITRAMFS) $(BOUND_MODULE)

.PHONY: fmov-bank-check
fmov-bank-check: fmov-bank-package
	install -d $(HERE)/$(PHASE)/verify
	taskset -c 12-15 timeout 600 qemu-system-aarch64 -M virt -cpu max -smp 2 -m 2048 -nographic -no-reboot \
		-kernel $(BOUND_KERNEL) -initrd $(BUILD)/initramfs.cpio.gz \
		-fsdev local,id=results,path=$(HERE)/$(PHASE)/verify,security_model=none \
		-device virtio-9p-device,fsdev=results,mount_tag=results \
		-append 'console=ttyAMA0 rdinit=/init loglevel=4 panic=30 oops=panic' >$(HERE)/$(PHASE)/qemu.log 2>&1
	test "$$(cat $(HERE)/$(PHASE)/verify/guest-status)" = 0

.PHONY: cilium-native-arch-check
CILIUM_TEST_PYTHON := $(ROOT)/kprog/arm64/build/python-tests/bin/python
$(CILIUM_TEST_PYTHON):
	python3 -m venv --system-site-packages $(ROOT)/kprog/arm64/build/python-tests
	$(CILIUM_TEST_PYTHON) -m pip install 'pytest>=8,<9'

cilium-native-arch-check: $(CILIUM_TEST_PYTHON)
	cd $(ROOT) && $(CILIUM_TEST_PYTHON) -m pytest -q tests/python/test_cilium_native_build.py

.PHONY: cilium-native-arch-replay
cilium-native-arch-replay:
	python3 $(HERE)/cilium_arch_replay.py $(HERE)/$(PHASE)

.PHONY: helper-dispatch-build
helper-dispatch-build: direct-header-generate
	python3 $(HERE)/helper_dispatch.py $(HERE)/$(PHASE)
	for source in $(HERE)/$(PHASE)/*.bpf.c; do \
		clang -g -O2 -target bpf -D__TARGET_ARCH_arm64 \
		-I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu \
		-c $$source -o $${source%.c}.o || exit 1; \
	done

.PHONY: memory-width-generate
memory-width-generate:
	cd $(ROOT)/kprog/formal && python3 tools/generate_arm64_load_bytes_spec.py
	cd $(ROOT)/kprog/formal && python3 tools/generate_arm64_store_bytes_spec.py

.PHONY: memory-width-check
memory-width-check: memory-width-generate
	install -d $(HERE)/$(PHASE)
	cc -Wall -Wextra -Werror -O2 -g -fsanitize=address,undefined -fno-omit-frame-pointer \
		$(HERE)/memory_width.c -o $(HERE)/$(PHASE)/host
	$(HERE)/$(PHASE)/host
	clang -g -O2 -target bpf -c $(HERE)/memory_width.c -o $(HERE)/$(PHASE)/width.bpf.o
	python3 $(HERE)/memory_width.py $(HERE)/$(PHASE)
	cd $(ROOT)/kprog/formal && cc -Wall -Wextra -Werror -O2 -I. oracles/test_arm64_load_bytes_host.c -o $(HERE)/$(PHASE)/load-oracle
	$(HERE)/$(PHASE)/load-oracle
	cd $(ROOT)/kprog/formal && cc -Wall -Wextra -Werror -O2 -I. oracles/test_arm64_store_bytes_host.c -o $(HERE)/$(PHASE)/store-oracle
	$(HERE)/$(PHASE)/store-oracle

.PHONY: startup-arm64-build
startup-arm64-build: direct-header-generate
	python3 $(HERE)/startup_arm64.py $(HERE)/$(PHASE) prepare
	clang -g -O2 -target bpf -D__TARGET_ARCH_arm64 \
		-I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu \
		-c $(HERE)/$(PHASE)/source.bpf.c -o $(HERE)/$(PHASE)/source.bpf.o
	python3 $(HERE)/startup_arm64.py $(HERE)/$(PHASE) generate
	for source in $(HERE)/$(PHASE)/startup_*.bpf.c; do \
		clang -g -O2 -target bpf -D__TARGET_ARCH_arm64 \
		-I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu \
		-c $$source -o $${source%.c}.o || exit 1; \
	done
	$(MAKE) -f $(HERE)/Makefile startup-arm64-driver PHASE=$(PHASE)

.PHONY: startup-arm64-driver
startup-arm64-driver:
	aarch64-linux-gnu-g++ -std=c++20 -Wall -Wextra -Werror -O2 $(HERE)/startup_inspect.cpp -ldl -o $(HERE)/$(PHASE)/inspect
	aarch64-linux-gnu-g++ -std=c++20 -Wall -Wextra -Werror -O2 -D__EXPORTED_HEADERS__ \
		-I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/prefix/include \
		$(ROOT)/corpus/results/kprog_app_coverage_20261106/runtime_startup.cpp \
		$(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/pic-obj/libbpf.a \
		-L$(ROOT)/.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu -lelf -lz -lzstd -o $(HERE)/$(PHASE)/startup

.PHONY: startup-arm64-check
STARTUP_LOADER ?= /workspaces/.agent-state/kprog-lanes/T/context-v2-func-ip/arm64/libnative_loader.so
startup-arm64-check:
	python3 $(HERE)/startup_arm64.py $(HERE)/$(PHASE) package $(BASE_INITRAMFS) $(STARTUP_LOADER)
	install -d $(HERE)/$(PHASE)/verify
	taskset -c 12-15 timeout 600 qemu-system-aarch64 -M virt -cpu max -smp 2 -m 2048 -nographic -no-reboot \
		-kernel /workspaces/.agent-state/kprog-lanes/T/paired-context-v2/arm64/Image -initrd $(BUILD)/initramfs.cpio.gz \
		-fsdev local,id=results,path=$(HERE)/$(PHASE)/verify,security_model=none \
		-device virtio-9p-device,fsdev=results,mount_tag=results \
		-append 'console=ttyAMA0 rdinit=/init loglevel=4 panic=30 oops=panic' >$(HERE)/$(PHASE)/qemu.log 2>&1
	python3 $(HERE)/startup_arm64.py $(HERE)/$(PHASE) collect

.PHONY: startup-arm64-install
startup-arm64-install:
	python3 $(HERE)/startup_arm64.py $(HERE)/$(PHASE) install

.PHONY: startup-arm64-collect
startup-arm64-collect:
	python3 $(HERE)/startup_arm64.py $(HERE)/$(PHASE) collect

.PHONY: source-map-arm64-build
source-map-arm64-build:
	python3 $(HERE)/source_map_arm64.py $(HERE)/$(PHASE) $(SOURCE_MAP_ARGS)

.PHONY: source-map-arm64-check
source-map-arm64-check:
	aarch64-linux-gnu-g++ -std=c++20 -Wall -Wextra -Werror -O2 -static -D__EXPORTED_HEADERS__ \
		-I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/prefix/include \
		$(HERE)/source_map_probe.cpp $(ROOT)/kprog/libnativeloader/build-arm64-a-map-order-v3/libnative_loader.a \
		$(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/pic-obj/libbpf.a \
		-L$(ROOT)/.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu -lelf -lz -lzstd -ldl -o $(HERE)/$(PHASE)/source-map-probe
	python3 $(HERE)/source_map_arm64.py $(HERE)/$(PHASE) package $(BASE_INITRAMFS)
	install -d $(HERE)/$(PHASE)/verify
	taskset -c 12-15 timeout 600 qemu-system-aarch64 -M virt -cpu max -smp 2 -m 2048 -nographic -no-reboot \
		-kernel /workspaces/.agent-state/kprog-lanes/T/paired-context-v2/arm64/Image -initrd $(BUILD)/initramfs.cpio.gz \
		-fsdev local,id=results,path=$(HERE)/$(PHASE)/verify,security_model=none \
		-device virtio-9p-device,fsdev=results,mount_tag=results \
		-append 'console=ttyAMA0 rdinit=/init loglevel=4 panic=30 oops=panic' >$(HERE)/$(PHASE)/qemu.log 2>&1
	test "$$(cat $(HERE)/$(PHASE)/verify/guest-status)" = 0

.PHONY: source-map-arm64-install
source-map-arm64-install:
	python3 $(HERE)/source_map_arm64.py $(HERE)/$(PHASE) install

.PHONY: exclusive-layout-check stack-sub-check
exclusive-layout-check:
	python3 $(HERE)/exclusive_layout.py $(HERE)/$(PHASE)

stack-sub-check:
	cd $(ROOT)/kprog/formal && python3 tools/generate_arm64_alu_handler_spec.py
	cd $(ROOT)/kprog/formal && taskset -c 16-19 lake build KProgFormal.Arm64AluHandler KProgFormal.Arm64AluOperandHandler KProgFormal.Arm64AluOperandSelect
	cd $(ROOT)/kprog/formal && cc -Wall -Wextra -Werror -O2 -I. oracles/test_arm64_alu_handler_host.c -o build/test_arm64_alu_handler_host
	$(ROOT)/kprog/formal/build/test_arm64_alu_handler_host
	cd $(ROOT)/kprog/formal && cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_alu_operand_select_route_host.c -o build/test_arm64_alu_operand_select_route_host
	$(ROOT)/kprog/formal/build/test_arm64_alu_operand_select_route_host
	$(MAKE) -f $(HERE)/Makefile direct-header-generate

.PHONY: code-dispatch-build exclusive-choice-check exclusive-choice-build
exclusive-choice-build: direct-header-generate
	python3 $(HERE)/exclusive_choice.py $(HERE)/$(PHASE)
	for source in $(HERE)/$(PHASE)/*.bpf.c; do \
		clang -g -O2 -target bpf -D__TARGET_ARCH_arm64 \
		-I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu \
		-c $$source -o $${source%.c}.o || exit 1; \
	done

exclusive-choice-check: direct-header-generate
	cd $(ROOT)/kprog/formal && python3 tools/generate_arm64_stlxr_spec.py
	cd $(ROOT)/kprog/formal && taskset -c 16-19 lake build KProgFormal.Arm64Stlxr
	cd $(ROOT)/kprog/formal && cc -Wall -Wextra -Werror -O2 -I. oracles/test_arm64_stlxr_host.c -o build/test_arm64_stlxr_host
	$(ROOT)/kprog/formal/build/test_arm64_stlxr_host
	cd $(ROOT)/kprog/formal && cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_stlxr_route_host.c -o build/test_arm64_stlxr_route_host
	$(ROOT)/kprog/formal/build/test_arm64_stlxr_route_host
	cd $(ROOT)/kprog/formal && cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/stlxr_route_host.c -o build/stlxr_route_host
	$(ROOT)/kprog/formal/build/stlxr_route_host
	$(MAKE) -f $(HERE)/Makefile direct-header-generate

.PHONY: exclusive-legacy-host-check
exclusive-legacy-host-check:
	cd $(ROOT)/kprog/formal && cc -DKPROG_TEST_EXCLUSIVE_FAILURE=0 -include oracles/arm64_exclusive_choice_host.h -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/value_route_host.c -o build/value_route_host
	$(ROOT)/kprog/formal/build/value_route_host

code-dispatch-build: direct-header-generate
	python3 $(HERE)/code_dispatch.py $(HERE)/$(PHASE)
	for source in $(HERE)/$(PHASE)/*.bpf.c; do \
		clang -g -O2 -target bpf -D__TARGET_ARCH_arm64 \
		-I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu \
		-c $$source -o $${source%.c}.o || exit 1; \
	done

.PHONY: entry-abi-build context-helper-host-check
context-helper-host-check:
	cd $(ROOT)/kprog/formal && taskset -c 16-19 lake build KProgFormal.Arm64HelperArgPtrShape
	install -d $(ROOT)/kprog/arm64/build
	cc -Wall -Wextra -Werror -O2 -I$(ROOT) -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu $(HERE)/context_helper_host.c -o $(ROOT)/kprog/arm64/build/context-helper-host
	$(ROOT)/kprog/arm64/build/context-helper-host
	cd $(ROOT)/kprog/formal && cc -DKPROG_TEST_EXCLUSIVE_FAILURE=0 -include oracles/arm64_exclusive_choice_host.h -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog -I../../vendor/libbpf/src oracles/test_arm64_helper_call_host.c -o build/test_arm64_helper_call_host
	$(ROOT)/kprog/formal/build/test_arm64_helper_call_host

entry-abi-build: direct-header-generate
	python3 $(HERE)/entry_abi.py $(HERE)/$(PHASE) $(ENTRY_ABI_ARGS)
	for source in $(HERE)/$(PHASE)/*.bpf.c; do \
		clang -g -O2 -target bpf -D__TARGET_ARCH_arm64 \
		-I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu \
		-c $$source -o $${source%.c}.o || exit 1; \
	done

.PHONY: runtime-loader-build
runtime-loader-build:
	PKG_CONFIG_LIBDIR=$(ROOT)/.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu/pkgconfig \
		PKG_CONFIG_SYSROOT_DIR=$(ROOT)/.cache/aarch64-sysroot \
		CXX=aarch64-linux-gnu-g++ CC=aarch64-linux-gnu-gcc taskset -c 16-19 $(MAKE) -C $(ROOT)/kprog/libnativeloader \
		BUILD_DIR=build-arm64-a-map-order-v3 \
		LIBBPF_PREFIX=$(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/prefix \
		LIBBPF_LIBRARY=$(ROOT)/runner/build-arm64-llvmbpf/vendor/libbpf/pic-obj/libbpf.a \
		KERNEL_OFFSETS_INCLUDE=$(ROOT)/micro/programs/build-arm64

.PHONY: original-btf-declarations otel-real-generate otel-real-link otel-real-install
original-btf-declarations:
	install -d $(ROOT)/kprog/arm64/build
	cc -O2 -Wall -Wextra -Werror -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include \
		$(ROOT)/corpus/results/kprog_app_coverage_20261106/original_btf_declarations.c \
		$(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz \
		-o $(ROOT)/kprog/arm64/build/original-btf-declarations

otel-real-generate: direct-header-generate original-btf-declarations
	python3 $(HERE)/otel_real.py $(HERE)/$(PHASE)

otel-real-link:
	python3 $(HERE)/otel_real.py $(HERE)/$(PHASE) link

otel-real-install:
	python3 $(HERE)/otel_real.py $(HERE)/$(PHASE) install

.PHONY: load-offset-check
load-offset-check:
	python3 $(ROOT)/kprog/formal/tools/generate_arm64_load_bytes_spec.py --check
	python3 $(HERE)/load_offset_check.py $(HERE)/$(PHASE)
	cc -Wall -Wextra -O2 -I$(ROOT)/kprog/formal $(ROOT)/kprog/formal/oracles/test_arm64_load_bytes_host.c -o $(ROOT)/kprog/arm64/build/load-bytes-host
	$(ROOT)/kprog/arm64/build/load-bytes-host
