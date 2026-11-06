SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := $(ROOT)/corpus/results/kprog_app_coverage_20261106
PHASE ?= baseline
DISPATCH := $(HERE)/dispatch-build
HOST_FLAGS := -O2 -Wno-c23-extensions -I$(ROOT)/vendor/libbpf/src -I$(ROOT)/vendor/libbpf/include/uapi

.PHONY: compile verify guest-verify summarize dispatch-regression zero-address-call zero-address-sources
zero-address-call:
	taskset -c 8-23 cargo test --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml
	$(MAKE) -C $(ROOT) host-native-link
	install -d $(HERE)/zero-address-call
	$(ROOT)/kprog/x86/native_lab/native_link/target/release/native-link --input $(ROOT)/vendor/build/native-bpf/x86/stage/tetragon/bpf_generic_uprobe_v61.native.o --symbol try_preload_arg --mode proof --preserve-entry-abi --output $(HERE)/zero-address-call/uprobe.proof.o
	$(ROOT)/kprog/x86/native_lab/native_link/target/release/native-link --input $(ROOT)/vendor/build/native-bpf/x86/stage/tetragon/bpf_multi_uprobe_v61.native.o --symbol try_preload_arg --mode proof --preserve-entry-abi --output $(HERE)/zero-address-call/multi-uprobe.proof.o
zero-address-sources:
	install -d $(HERE)/zero-address-call/input/tetragon
	install -m 0644 $(HERE)/zero-address-call/uprobe.proof.o $(HERE)/zero-address-call/input/tetragon/bpf_generic_uprobe_v61.try_preload_arg.proof.o
	install -m 0644 $(HERE)/zero-address-call/multi-uprobe.proof.o $(HERE)/zero-address-call/input/tetragon/bpf_multi_uprobe_v61.try_preload_arg.proof.o
	$(MAKE) -C $(ROOT)/kprog/x86 app-proofs-build APP_SIM_PROOF_ARGS='--generate-only --proof-root $(HERE)/zero-address-call/input --report-dir $(HERE)/zero-address-call/generation --output-dir $(ROOT)/kprog/x86/app-coverage-zero-address'
dispatch-regression:
	python3 $(HERE)/check_dispatch.py $(GENERATOR)
	cc $(HOST_FLAGS) -DLICENSE=old_license -c $(DISPATCH)/old.c -o $(DISPATCH)/old.o
	cc $(HOST_FLAGS) -DLICENSE=current_license -c $(DISPATCH)/current.c -o $(DISPATCH)/current.o
	cc $(HOST_FLAGS) $(DISPATCH)/main.c $(DISPATCH)/native.S $(DISPATCH)/old.o $(DISPATCH)/current.o -o $(DISPATCH)/check
	taskset -c 8-15 $(DISPATCH)/check
summarize:
	python3 $(HERE)/summarize.py

compile:
	taskset -c 8-15 python3 $(HERE)/coverage.py compile $(HERE)/$(PHASE)

verify:
	taskset -c 8-15 vng --run $(ROOT)/vendor/build/x86/linux/arch/x86/boot/bzImage \
		--cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor \
		--cpus 4 --memory 8G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -f $(HERE)/Makefile guest-verify PHASE=$(PHASE)'

guest-verify:
	python3 $(HERE)/coverage.py verify $(HERE)/$(PHASE)

indirect-inventory:
	taskset -c 8-23 python3 $(HERE)/scan_indirect.py

indirect-regression:
	python3 $(HERE)/check_indirect.py prepare
	cc -c $(HERE)/indirect-build/join.S -o $(HERE)/indirect-build/join.proof.o
	cc -c $(HERE)/indirect-build/cmov.S -o $(HERE)/indirect-build/cmov.proof.o
	cc -c $(HERE)/indirect-build/call.S -o $(HERE)/indirect-build/call.proof.o
	python3 $(HERE)/check_indirect.py generate
	cc $(HOST_FLAGS) -DLICENSE=join_license -c $(HERE)/indirect-build/join.bpf.c -o $(HERE)/indirect-build/join.sim.o
	cc $(HOST_FLAGS) -DLICENSE=cmov_license -c $(HERE)/indirect-build/cmov.bpf.c -o $(HERE)/indirect-build/cmov.sim.o
	cc $(HOST_FLAGS) -DLICENSE=call_license -c $(HERE)/indirect-build/call.bpf.c -o $(HERE)/indirect-build/call.sim.o
	cc -no-pie -O2 $(HERE)/indirect-build/main.c $(HERE)/indirect-build/join.proof.o $(HERE)/indirect-build/cmov.proof.o $(HERE)/indirect-build/call.proof.o $(HERE)/indirect-build/join.sim.o $(HERE)/indirect-build/cmov.sim.o $(HERE)/indirect-build/call.sim.o -o $(HERE)/indirect-build/check
	taskset -c 8-23 $(HERE)/indirect-build/check

indirect-bpf: indirect-regression
	clang -g -O2 -Wno-c23-extensions -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_x86 -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/indirect-build/join.bpf.c -o $(HERE)/indirect-build/join.bpf.o
	clang -g -O2 -Wno-c23-extensions -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_x86 -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/indirect-build/cmov.bpf.c -o $(HERE)/indirect-build/cmov.bpf.o
	clang -g -O2 -Wno-c23-extensions -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_x86 -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/indirect-build/call.bpf.c -o $(HERE)/indirect-build/call.bpf.o

cmov-regression:
	cc -Wall -Wextra -O2 -I$(ROOT)/kprog/formal $(ROOT)/kprog/formal/oracles/test_x86_cmov_host.c -o $(HERE)/indirect-build/test_x86_cmov_host
	$(HERE)/indirect-build/test_x86_cmov_host
	cc -Wall -Wextra -O2 -I$(ROOT)/kprog/formal -I$(ROOT)/kprog/x86 -I$(ROOT)/kprog -I$(ROOT)/vendor/libbpf/src $(ROOT)/kprog/formal/oracles/cmov_step_route_host.c -o $(HERE)/indirect-build/cmov_step_route_host
	$(HERE)/indirect-build/cmov_step_route_host
	cc -Wall -Wextra -O2 -I$(ROOT)/kprog/formal -I$(ROOT)/kprog/x86 -I$(ROOT)/kprog -I$(ROOT)/vendor/libbpf/src $(ROOT)/kprog/formal/oracles/test_x86_cmov_route_host.c -o $(HERE)/indirect-build/test_x86_cmov_route_host
	$(HERE)/indirect-build/test_x86_cmov_route_host

finite-target-census:
	taskset -c 8-23 python3 $(HERE)/scan_targets.py

indirect-kvm: indirect-bpf
	taskset -c 8-23 vng --run $(ROOT)/vendor/build/x86/linux/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile indirect-guest'

indirect-guest:
	python3 $(HERE)/check_indirect.py verify

indirect-bound-build:
	$(MAKE) -C $(ROOT)/kprog/libnativeloader BUILD_DIR=build-capplication
	c++ -std=c++20 -Wall -Wextra -Werror -O2 -D__EXPORTED_HEADERS__ -DNATIVE_LINK_PATH='"$(ROOT)/kprog/x86/native_lab/native_link/target/release/native-link"' -I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include $(ROOT)/kprog/fidelity/bound_probe.cpp $(ROOT)/kprog/libnativeloader/build-capplication/libnative_loader.a $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o $(HERE)/indirect-build/bound-probe
	clang -O2 -g -target bpf -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/indirect-build/original.bpf.c -o $(HERE)/indirect-build/original.bpf.o
	clang -O2 -g -target bpf -DCALL_FIXTURE -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/indirect-build/original.bpf.c -o $(HERE)/indirect-build/original-call.bpf.o

indirect-bound-kvm: indirect-bound-build
	taskset -c 8-23 vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile indirect-bound-guest'

indirect-bound-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko
	python3 $(HERE)/check_indirect.py bound

helper-abi-update:
	python3 $(HERE)/generate_helpers.py

helper-abi-regression:
	python3 $(HERE)/check_helper_abi.py
	cc $(HOST_FLAGS) $(HERE)/indirect-build/helper-abi.c -o $(HERE)/indirect-build/helper-abi
	$(HERE)/indirect-build/helper-abi

finite-prepare:
	python3 $(HERE)/prepare_finite.py prepare

finite-generate:
	$(MAKE) -C $(ROOT)/kprog/x86 app-proofs-build APP_SIM_PROOF_ARGS='--generate-only --proof-root $(HERE)/finite/input --report-dir $(HERE)/finite --output-dir $(ROOT)/kprog/x86/app-coverage-finite'

finite-freeze:
	python3 $(HERE)/prepare_finite.py freeze

abi-negative-build:
	python3 $(ROOT)/kprog/fidelity/negative.py build --arch x86 --build $(HERE)/abi-definedness

abi-regression: abi-negative-build
	python3 $(HERE)/check_abi.py

abi-bound-build: indirect-bound-build
	clang -O2 -g -target bpf -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(ROOT)/kprog/fidelity/negative_companion.bpf.c -o $(HERE)/abi-definedness/companion.bpf.o

abi-bound-kvm: abi-negative-build abi-bound-build
	taskset -c 8-23 vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile abi-bound-guest'

abi-bound-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko
	python3 $(ROOT)/kprog/fidelity/negative.py bound --arch x86 --build $(HERE)/abi-definedness --out $(HERE)/abi-bound --probe $(HERE)/indirect-build/bound-probe --companion $(HERE)/abi-definedness/companion.bpf.o

abi-corpus-generate:
	python3 $(HERE)/prepare_finite.py prepare defined-final
	$(MAKE) -C $(ROOT)/kprog/x86 app-proofs-build APP_SIM_PROOF_ARGS='--generate-only --proof-root $(HERE)/defined-final/input --report-dir $(HERE)/defined-final --output-dir $(ROOT)/kprog/x86/app-coverage-defined-final --generator $(HERE)/defined-final/simulator/kprog/x86/micro-prog/generate_micro_sim_proofs.py'

abi-corpus-freeze:
	python3 $(HERE)/prepare_finite.py freeze defined-final

abi-positive-compile: abi-regression
	$(MAKE) -f $(HERE)/Makefile compile PHASE=abi-positive

pushpop-before-build:
	python3 $(HERE)/check_pushpop.py before-build

pushpop-before-kvm: pushpop-before-build
	taskset -c 8-23 vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile pushpop-before-guest'

pushpop-before-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko
	python3 $(HERE)/check_pushpop.py before-bound

pushpop-contract:
	python3 $(ROOT)/kprog/formal/tools/generate_x86_specialization_spec.py

pushpop-prepare:
	python3 $(HERE)/check_pushpop.py prepare
	for name in imm8_negative imm8_positive imm32_negative imm32_positive imm16 push_mem_old_sp pop_mem_new_sp pop_mem16 pop_mem_index; do cc -c $(HERE)/pushpop-build/$$name.S -o $(HERE)/pushpop-build/$$name.proof.o || exit 1; done
	python3 $(HERE)/check_pushpop.py generate

pushpop-host: pushpop-prepare
	for name in imm8_negative imm8_positive imm32_negative imm32_positive imm16 push_mem_old_sp pop_mem_new_sp pop_mem16 pop_mem_index; do cc $(HOST_FLAGS) -DLICENSE=$${name}_license -c $(HERE)/pushpop-build/$$name.bpf.c -o $(HERE)/pushpop-build/$$name.sim.o || exit 1; done
	cc -no-pie -O2 $(HERE)/pushpop-build/main.c $(HERE)/pushpop-build/*.proof.o $(HERE)/pushpop-build/*.sim.o -o $(HERE)/pushpop-build/check
	taskset -c 8-23 $(HERE)/pushpop-build/check

pushpop-after-build:
	python3 $(HERE)/check_pushpop.py after-build

pushpop-after-kvm: pushpop-after-build
	taskset -c 8-23 vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile pushpop-after-guest'

pushpop-after-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko
	python3 $(HERE)/check_pushpop.py after-bound

pushpop-bpf: pushpop-prepare
	for name in imm8_negative imm8_positive imm32_negative imm32_positive imm16 push_mem_old_sp pop_mem_new_sp pop_mem16 pop_mem_index; do clang -g -O2 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_x86 -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/pushpop-build/$$name.bpf.c -o $(HERE)/pushpop-build/$$name.bpf.o || exit 1; done

pushpop-kvm: pushpop-bpf
	taskset -c 8-23 vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile pushpop-guest'

pushpop-guest:
	python3 $(HERE)/check_pushpop.py verify

pushpop-formal:
	python3 $(ROOT)/kprog/formal/tools/generate_x86_specialization_spec.py --check
	cd $(ROOT)/kprog/formal && taskset -c 8-23 lake build KProgFormal.X86Specialization
	cc -Wall -Wextra -O2 -I$(ROOT)/kprog/formal -I$(ROOT)/kprog/x86 -I$(ROOT)/kprog -I$(ROOT)/vendor/libbpf/src $(ROOT)/kprog/formal/oracles/test_x86_specialization_host.c -o $(HERE)/pushpop-build/specialization-host
	$(HERE)/pushpop-build/specialization-host
	cc -Wall -Wextra -O2 -I$(ROOT)/kprog/formal -I$(ROOT)/kprog/x86 -I$(ROOT)/kprog -I$(ROOT)/vendor/libbpf/src $(ROOT)/kprog/formal/oracles/test_x86_pushpop_route_host.c -o $(HERE)/pushpop-build/register-route-host
	$(HERE)/pushpop-build/register-route-host

helper-effects-regression:
	python3 $(HERE)/check_helper_effects.py

arithmetic-regression:
	python3 $(HERE)/check_abi_arithmetic.py

arithmetic-census:
	python3 $(HERE)/prepare_finite.py prepare arithmetic
	$(MAKE) -C $(ROOT)/kprog/x86 app-proofs-build APP_SIM_PROOF_ARGS='--generate-only --proof-root $(HERE)/arithmetic/input --report-dir $(HERE)/arithmetic --output-dir $(ROOT)/kprog/x86/app-coverage-arithmetic --generator $(HERE)/arithmetic/simulator/kprog/x86/micro-prog/generate_micro_sim_proofs.py'

helper-effects-census:
	python3 $(HERE)/prepare_finite.py prepare helper-effects
	$(MAKE) -C $(ROOT)/kprog/x86 app-proofs-build APP_SIM_PROOF_ARGS='--generate-only --proof-root $(HERE)/helper-effects/input --report-dir $(HERE)/helper-effects --output-dir $(ROOT)/kprog/x86/app-coverage-helper-effects --generator $(HERE)/helper-effects/simulator/kprog/x86/micro-prog/generate_micro_sim_proofs.py'

runtime-build: pushpop-bpf
	$(MAKE) -C $(ROOT)/kprog/libnativeloader BUILD_DIR=build-capplication
	$(MAKE) -C $(ROOT)/bpfopt/shim SHIM_SO=$(HERE)/verified-runtime-shim.so $(HERE)/verified-runtime-shim.so
	install -d $(HERE)/verified-runtime
	clang -g -O2 -target bpf -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/runtime_source.bpf.c -o $(HERE)/verified-runtime/source.bpf.o
	c++ -O2 -I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include $(HERE)/runtime_startup.cpp $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o $(HERE)/verified-runtime/startup

runtime-kvm: runtime-build
	taskset -c 8-23 vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile runtime-guest'

runtime-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko
	python3 $(HERE)/check_runtime.py

runtime-python:
	python3 -m unittest discover -s $(ROOT)/tests/python -p test_corpus_incremental.py

ret-before-build:
	python3 $(HERE)/check_return.py before build

ret-before-kvm: ret-before-build
	taskset -c 8-23 vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile ret-before-guest'

ret-before-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko
	python3 $(HERE)/check_return.py before bound

ret-after-build:
	python3 $(HERE)/check_return.py after build

ret-regression:
	python3 $(HERE)/check_return.py after regression

ret-after-kvm: ret-after-build
	taskset -c 8-23 vng --run $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile ret-after-guest'

ret-after-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko
	python3 $(HERE)/check_return.py after bound

native-dispatch-test:
	taskset -c 8-15 cargo test --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml

native-dispatch-build:
	taskset -c 8-15 cargo build --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml --target-dir $(HERE)/native-dispatch-link
	python3 $(HERE)/check_native_dispatch.py prepare
	cc -c $(HERE)/native-dispatch/join_dispatch.S -o $(HERE)/native-dispatch/join_dispatch.o
	cc -c $(HERE)/native-dispatch/cmov_dispatch.S -o $(HERE)/native-dispatch/cmov_dispatch.o
	cc -c $(HERE)/native-dispatch/got_dispatch.S -o $(HERE)/native-dispatch/got_dispatch.o
	python3 $(HERE)/check_native_dispatch.py link
	cc -no-pie -O2 $(HERE)/native-dispatch/host.c $(HERE)/native-dispatch/*.host.S -o $(HERE)/native-dispatch/host-check
	$(HERE)/native-dispatch/host-check
	clang -g -O2 -target bpf -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/native-dispatch/join_dispatch.bpf.c -o $(HERE)/native-dispatch/join_dispatch.bpf.o
	clang -g -O2 -target bpf -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/native-dispatch/cmov_dispatch.bpf.c -o $(HERE)/native-dispatch/cmov_dispatch.bpf.o
	clang -g -O2 -target bpf -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/native-dispatch/got_dispatch.bpf.c -o $(HERE)/native-dispatch/got_dispatch.bpf.o
	clang -g -O2 -target bpf -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/native-dispatch/source.bpf.c -o $(HERE)/native-dispatch/join_dispatch.source.bpf.o
	clang -g -O2 -target bpf -DINVERT -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/native-dispatch/source.bpf.c -o $(HERE)/native-dispatch/cmov_dispatch.source.bpf.o
	clang -g -O2 -target bpf -DGOT_RESULT -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/native-dispatch/source.bpf.c -o $(HERE)/native-dispatch/got_dispatch.source.bpf.o

native-dispatch-bound-build: native-dispatch-build
	$(MAKE) -C $(ROOT)/kprog/libnativeloader BUILD_DIR=build-cdispatch
	c++ -std=c++20 -Wall -Wextra -Werror -O2 -D__EXPORTED_HEADERS__ -DNATIVE_LINK_PATH='"$(HERE)/native-dispatch-link/release/native-link"' -I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include $(ROOT)/kprog/fidelity/bound_probe.cpp $(ROOT)/kprog/libnativeloader/build-cdispatch/libnative_loader.a $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o $(HERE)/native-dispatch/bound-probe
	install -m 0644 $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage $(HERE)/native-dispatch/bzImage
	install -m 0644 $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko $(HERE)/native-dispatch/bpf_x86_native_lab.ko

native-dispatch-kvm: native-dispatch-bound-build
	taskset -c 8-15 vng --run $(HERE)/native-dispatch/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile native-dispatch-guest'

native-dispatch-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(HERE)/native-dispatch/bpf_x86_native_lab.ko
	python3 $(HERE)/check_native_dispatch.py bound

code-dispatch-build:
	taskset -c 8-15 cargo build --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml --target-dir $(HERE)/native-dispatch-link
	python3 $(HERE)/check_code_dispatch.py prepare
	for name in join cmov call pc32; do cc -c $(HERE)/code-dispatch/$$name.S -o $(HERE)/code-dispatch/$$name.native.o || exit 1; done
	python3 $(HERE)/check_code_dispatch.py link
	cc -O2 -no-pie $(HERE)/code-dispatch/host.c $(HERE)/code-dispatch/*.host.S -o $(HERE)/code-dispatch/host-check
	$(HERE)/code-dispatch/host-check
	for name in join cmov call pc32; do clang -g -O2 -Wno-c23-extensions -target bpf -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/code-dispatch/$$name.bpf.c -o $(HERE)/code-dispatch/$$name.bpf.o || exit 1; done
	clang -g -O2 -target bpf -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/code-dispatch/original.bpf.c -o $(HERE)/code-dispatch/original.bpf.o
	clang -g -O2 -target bpf -DCALL_FIXTURE -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/code-dispatch/original.bpf.c -o $(HERE)/code-dispatch/original-call.bpf.o

	clang -g -O2 -target bpf -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/code-dispatch/pc32-original.bpf.c -o $(HERE)/code-dispatch/pc32-original.bpf.o

code-dispatch-kvm: code-dispatch-build
	c++ -std=c++20 -Wall -Wextra -Werror -O2 -D__EXPORTED_HEADERS__ -DNATIVE_LINK_PATH='"$(HERE)/native-dispatch-link/release/native-link"' -I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include $(ROOT)/kprog/fidelity/bound_probe.cpp $(ROOT)/kprog/libnativeloader/build-cdispatch/libnative_loader.a $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o $(HERE)/code-dispatch/bound-probe
	taskset -c 8-15 vng --run $(HERE)/native-dispatch/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile code-dispatch-guest'

code-dispatch-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(HERE)/native-dispatch/bpf_x86_native_lab.ko
	python3 $(HERE)/check_code_dispatch.py bound

startup-inventory:
	python3 $(HERE)/capture_startup.py $(HERE)/startup-x86

bcc-real-generate:
	python3 $(HERE)/bcc_real.py $(HERE)/$(PHASE)

bcc-real-compile:
	KPROG_COMPILE_WORKERS=1 prlimit --as=8589934592 --core=0 -- $(MAKE) -f $(HERE)/Makefile compile PHASE=$(PHASE)

raw-context-build:
	python3 $(HERE)/check_raw_context.py prepare
	for name in tail_word tail_signed frame_slot outside_frame; do cc -c $(HERE)/raw-context/$$name.S -o $(HERE)/raw-context/$$name.native.o || exit 1; done
	python3 $(HERE)/check_raw_context.py generate
	cc -no-pie -O2 $(HERE)/raw-context/host.c $(HERE)/raw-context/*.native.o -o $(HERE)/raw-context/host-check
	$(HERE)/raw-context/host-check
	for name in tail_word tail_signed frame_slot outside_frame; do clang -g -O2 -Wno-c23-extensions -target bpf -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/raw-context/$$name.bpf.c -o $(HERE)/raw-context/$$name.bpf.o || exit 1; done
	clang -g -O2 -target bpf -DEXPECTED=0x84332211u -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/raw-context/source.bpf.c -o $(HERE)/raw-context/tail_word.source.bpf.o
	clang -g -O2 -target bpf -DEXPECTED=0xffffff84u -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/raw-context/source.bpf.c -o $(HERE)/raw-context/tail_signed.source.bpf.o

	for name in frame_slot outside_frame; do clang -g -O2 -target bpf -DEXPECTED=1 -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/raw-context/source.bpf.c -o $(HERE)/raw-context/$$name.source.bpf.o || exit 1; done

raw-context-kvm: raw-context-build bcc-real-verify-build
	$(MAKE) -C $(ROOT)/kprog/libnativeloader BUILD_DIR=build-ccontext
	c++ -std=c++20 -Wall -Wextra -Werror -O2 -D__EXPORTED_HEADERS__ -DNATIVE_LINK_PATH='"$(HERE)/native-dispatch-link/release/native-link"' -I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include $(ROOT)/kprog/fidelity/bound_probe.cpp $(ROOT)/kprog/libnativeloader/build-ccontext/libnative_loader.a $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o $(HERE)/raw-context/bound-probe
	taskset -c 8-15 vng --run $(HERE)/entry-input/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile raw-context-guest'

raw-context-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(HERE)/entry-input/bpf_x86_native_lab.ko
	python3 $(HERE)/check_raw_context.py bound

bcc-real-verify-build:
	c++ -std=c++20 -Wall -Wextra -Werror -O2 -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include $(HERE)/verify_proof.cpp $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o $(HERE)/verify-proof
	install -d $(HERE)/entry-input
	install -m 0644 $(ROOT)/kprog/tv/build-kernel-x86/arch/x86/boot/bzImage $(HERE)/entry-input/bzImage
	install -m 0644 $(ROOT)/kprog/tv/build-kernel-x86/.config $(HERE)/entry-input/kernel.config
	install -m 0644 $(ROOT)/kprog/tv/build-kernel-x86/Module.symvers $(HERE)/entry-input/Module.symvers
	install -m 0644 $(ROOT)/kprog/tv/build-x86/bpf_x86_native_lab.ko $(HERE)/entry-input/bpf_x86_native_lab.ko

bcc-real-verify: bcc-real-verify-build
	taskset -c 8-15 vng --run $(HERE)/entry-input/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile guest-verify PHASE=$(PHASE)'

context-runtime-build: pushpop-bpf bcc-real-verify-build
	$(MAKE) -C $(ROOT)/kprog/libnativeloader BUILD_DIR=build-ccontext
	$(MAKE) -C $(ROOT)/bpfopt/shim SHIM_SO=$(HERE)/context-runtime-shim.so $(HERE)/context-runtime-shim.so
	install -d $(HERE)/context-runtime
	clang -g -O2 -target bpf -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/runtime_source.bpf.c -o $(HERE)/context-runtime/source.bpf.o
	c++ -O2 -I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include $(HERE)/runtime_startup.cpp $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o $(HERE)/context-runtime/startup

context-runtime-kvm: context-runtime-build
	taskset -c 8-15 vng --run $(HERE)/entry-input/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile context-runtime-guest'

context-runtime-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(HERE)/entry-input/bpf_x86_native_lab.ko
	python3 $(HERE)/check_context_runtime.py

raw-entry-census:
	python3 $(HERE)/prepare_finite.py prepare raw-entry-census
	$(MAKE) -C $(ROOT)/kprog/x86 app-proofs-build APP_SIM_PROOF_ARGS='--generate-only --proof-root $(HERE)/raw-entry-census/input --report-dir $(HERE)/raw-entry-census --output-dir $(ROOT)/kprog/x86/app-coverage-raw-entry --generator $(HERE)/raw-entry-census/simulator/kprog/x86/micro-prog/generate_micro_sim_proofs.py'

raw-entry-host:
	cc -O2 -I$(ROOT)/vendor/libbpf/src $(HERE)/raw_entry_host.c -o $(HERE)/raw-entry-host
	$(HERE)/raw-entry-host

BCC_RUNTIME_PACKAGE ?= bcc-runtime-7
BCC_RUNTIME_IMAGE ?= bpf-benchmark/kprog-bcc:c-20261106-7
BCC_RUNTIME_BASE ?= bpf-benchmark/kprog-bcc-base:c-20261106-7
PAIRED_CONTEXT ?= /workspaces/.agent-state/kprog-lanes/T/paired-context-v2/x86

bcc-runtime-package:
	python3 $(HERE)/package_bcc.py $(PHASE) $(BCC_RUNTIME_PACKAGE)

bcc-runtime-image:
	docker tag 4e0cc5f9ddf0 $(BCC_RUNTIME_BASE)
	docker build --build-context paired-context=$(PAIRED_CONTEXT) --build-context bcc-verified=$(HERE)/$(BCC_RUNTIME_PACKAGE) --build-arg BASE_IMAGE=$(BCC_RUNTIME_BASE) -f $(HERE)/bcc-runtime.Dockerfile -t $(BCC_RUNTIME_IMAGE) $(HERE)/$(BCC_RUNTIME_PACKAGE)
	docker save -o $(HERE)/$(BCC_RUNTIME_PACKAGE).image.tar $(BCC_RUNTIME_IMAGE)

bcc-runtime-corpus:
	install -d /workspaces/.agent-state/kprog-lanes/C/var-tmp-bcc-7
	BPFREJIT_CORPUS_APPS=bcc BPFREJIT_BENCH_PASSES=noop BPFREJIT_SHIM_NATIVE_LOADER=post BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1 $(MAKE) -C $(ROOT) -o runtime-kernel-image corpus RUNTIME_CONTAINER_IMAGE=$(BCC_RUNTIME_IMAGE) RUNTIME_IMAGE_TAR=$(HERE)/$(BCC_RUNTIME_PACKAGE).image.tar BZIMAGE=$(PAIRED_CONTEXT)/bzImage VNG='vng --run $(PAIRED_CONTEXT)/bzImage --cwd $(ROOT) --disable-monitor --verbose --cpus 2 --pin 12-15 --memory 2G --rwdir $(ROOT) --rwdir /var/tmp=/workspaces/.agent-state/kprog-lanes/C/var-tmp-bcc-7 --overlay-rwdir /tmp --append "loglevel=4 panic=30 oops=panic"' VM_CPU_PIN=12-15 VM_CPUS=2 VM_MEM=2G SAMPLES=1 WORKLOAD_DURATION=5 TIMEOUT=900

siphash-compile:
	install -d $(HERE)/siphash-compile
	taskset -c 12-15 clang -g -O3 -target bpf -mllvm -bpf-stack-size=4096 -D__TARGET_ARCH_x86 -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(ROOT)/kprog/x86/micro-prog/siphash_rotate64_mixer.bpf.c -o $(HERE)/siphash-compile/siphash.bpf.o

raw-entry-artifacts:
	python3 $(HERE)/archive_raw_entry.py
	tar -czf $(HERE)/raw-formal-artifacts.tar.gz --exclude=.lake --exclude=target --exclude=build -C /workspaces/.agent-state/kprog-lanes/C raw-check-source -C $(HERE) raw-formal-export.log raw-formal-first-failure.log raw-source-revision.txt
