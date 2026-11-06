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
