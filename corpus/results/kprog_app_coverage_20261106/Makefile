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
