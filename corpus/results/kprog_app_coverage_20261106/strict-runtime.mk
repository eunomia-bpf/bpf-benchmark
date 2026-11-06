SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := $(ROOT)/corpus/results/kprog_app_coverage_20261106
INPUT := $(HERE)/strict-runtime-input
PAIRED := /workspaces/.agent-state/kprog-lanes/T/paired-context-v2/x86
LOADER := /workspaces/.agent-state/kprog-lanes/T/context-v2-source-map/x86

build:
	install -d $(INPUT)
	cc -O2 -g -Wall -Wextra -fPIC -D_GNU_SOURCE -I$(ROOT)/vendor/libbpf/include/uapi -shared $(ROOT)/bpfopt/shim/libbpfrejit_shim.c -o $(INPUT)/libbpfrejit_shim.so -ldl -lpthread
	install -m0644 $(LOADER)/libnative_loader.so $(INPUT)/libnative_loader.so
	install -m0644 $(LOADER)/bpf_x86_native_lab.ko $(INPUT)/bpf_x86_native_lab.ko
	install -m0644 $(PAIRED)/bzImage $(INPUT)/bzImage

kvm:
	taskset -c 12-15 vng --run $(INPUT)/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /workspaces/.agent-state/kprog-lanes/C --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/strict-runtime.mk guest'

guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(INPUT)/bpf_x86_native_lab.ko
	KPROG_TEST_SHIM=$(INPUT)/libbpfrejit_shim.so KPROG_TEST_LOADER=$(INPUT)/libnative_loader.so python3 $(HERE)/check_object_startup.py object-startup-published

artifacts:
	tar -czf $(HERE)/strict-runtime-artifacts.tar.gz --exclude='sockets' -C $(HERE) strict-runtime-input object-startup-published

LINK_TARGET := $(ROOT)/kprog/x86/native_lab/native_link/target-c-tail
link-build:
	taskset -c 12-15 cargo build -j2 --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml --target-dir $(LINK_TARGET)

test-link:
	taskset -c 12-15 cargo test -j2 --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml --target-dir $(LINK_TARGET)

tail-build:
	python3 $(HERE)/check_tail_helpers.py build

tail-kvm:
	taskset -c 12-15 vng --run $(INPUT)/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /workspaces/.agent-state/kprog-lanes/C --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/strict-runtime.mk tail-guest'

tail-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(INPUT)/bpf_x86_native_lab.ko
	python3 $(HERE)/check_tail_helpers.py bound

tail-negative:
	python3 $(HERE)/check_tail_helpers.py negative

tail-artifacts:
	tar -czf $(HERE)/tail-helper-artifacts.tar.gz --exclude='sockets' --exclude='target' -C $(HERE) tail-helper tail-object-direct tail-object-got tail-object-numeric tail-object-subprogram -C /workspaces/.agent-state/kprog-lanes/C/tail-check-source kprog/x86/native_lab/native_link

source-map-elf:
	install -d $(HERE)/source-map-elf
	clang -O2 -g -target bpf -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/source_map_elf_probe.bpf.c -o $(HERE)/source-map-elf/probe.bpf.o
	llvm-objdump-18 -dr $(HERE)/source-map-elf/probe.bpf.o

source-map-contract:
	python3 $(ROOT)/kprog/formal/tools/generate_x86_ptr_write_spec.py

source-map-ir:
	install -d $(HERE)/source-map-lift
	$(HERE)/lift-bpf-ir $(HERE)/bcc-capture-12/bpfrejit_1931_918b4f57cc8f3b1e.bpf $(HERE)/source-map-lift/native.ll

source-map-proof:
	python3 $(HERE)/lift_startup_proofs.py bcc_map_value $(HERE)/bcc-capture-12/bpfrejit_1931_918b4f57cc8f3b1e.bpf socket

source-map-host:
	cc -Wall -Wextra -Werror -O2 -fsanitize=undefined -I$(ROOT)/kprog/formal $(ROOT)/kprog/formal/oracles/test_x86_mov_load_map_ptr_host.c -o $(HERE)/source-map-ptr-host
	$(HERE)/source-map-ptr-host

source-map-lean:
	cd $(ROOT)/kprog/formal && taskset -c 20-23 lake build KProgFormal.X86PtrWriteHandler

SOURCE_MAP_CHECK := /workspaces/.agent-state/kprog-lanes/C/source-map-check-source
source-map-prepare:
	python3 $(HERE)/prepare_source_map_check.py

source-map-formal:
	taskset -c 20-23 prlimit --as=12884901888 --core=0 -- $(MAKE) -C $(SOURCE_MAP_CHECK)/kprog/formal check

source-map-repair-export:
	cp -a $(ROOT)/vendor/linux-framework/include/. $(SOURCE_MAP_CHECK)/vendor/linux-framework/include/

bcc-transient-proofs:
	python3 $(HERE)/lift_startup_proofs.py bcc_trace_read $(HERE)/bcc-capture-12/bpfrejit_1716_7e4864ff1af3e9d4.bpf tracepoint/native/startup
	python3 $(HERE)/lift_startup_proofs.py bcc_trace_zero $(HERE)/bpf-lift/zero.bpf.bin tracepoint/native/startup
	python3 $(HERE)/lift_startup_proofs.py bcc_fentry_zero $(HERE)/bpf-lift/zero.bpf.bin fentry/native_startup_probe

bcc-refresh:
	python3 $(HERE)/bcc_real.py $(HERE)/bcc-real-13 $(HERE)/bcc-real-11
	KPROG_COMPILE_WORKERS=1 taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -f $(HERE)/Makefile compile PHASE=bcc-real-13

source-map-micro-prepare:
	install -d $(SOURCE_MAP_CHECK)/runner $(SOURCE_MAP_CHECK)/kprog
	cp -a $(ROOT)/runner/libs $(SOURCE_MAP_CHECK)/runner/
	cp $(ROOT)/kprog/run_micro_sim_batch.py $(SOURCE_MAP_CHECK)/kprog/

source-map-micro:
	taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -C $(SOURCE_MAP_CHECK)/kprog/x86 -o kprog-negative-proof-build micro-proofs-build MICRO_CONFIG=../test/kprog_negative_stage2.yaml PROOF_BUILD_DIR=$(HERE)/source-map-micro-negative MICRO_SIM_PROOF_ARGS='--no-generate --jobs 1'
	taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -C $(SOURCE_MAP_CHECK)/kprog/x86 -o kprog-negative-proof-build micro-proofs-build PROOF_BUILD_DIR=$(HERE)/source-map-micro MICRO_SIM_PROOF_ARGS='--no-generate --jobs 1'

source-map-proof-v2:
	python3 $(HERE)/lift_startup_proofs.py bcc_map_value_v2 $(HERE)/bcc-capture-12/bpfrejit_1931_918b4f57cc8f3b1e.bpf socket

source-map-micro-refresh:
	install -d $(SOURCE_MAP_CHECK)/kprog/x86/micro-prog/build/native-link
	cp $(ROOT)/kprog/x86/micro-prog/build/native-link/*.proof.o $(SOURCE_MAP_CHECK)/kprog/x86/micro-prog/build/native-link/
	python3 $(SOURCE_MAP_CHECK)/kprog/x86/micro-prog/generate_micro_sim_proofs.py --proof-object-dir $(SOURCE_MAP_CHECK)/kprog/x86/micro-prog/build/native-link

source-map-alias:
	python3 $(HERE)/check_source_map_alias.py

source-map-proof-v3:
	python3 $(HERE)/lift_startup_proofs.py bcc_map_value_v3 $(HERE)/bcc-capture-12/bpfrejit_1931_918b4f57cc8f3b1e.bpf socket

source-map-alias-recheck:
	python3 -c 'from pathlib import Path; import shutil; shutil.move("$(HERE)/source-map-alias", "$(HERE)/source-map-alias-first"); shutil.move("$(HERE)/startup-lift/bcc_map_alias", "$(HERE)/startup-lift/bcc_map_alias-first")'
	python3 $(HERE)/check_source_map_alias.py

source-map-artifacts:
	python3 $(HERE)/archive_source_maps.py

guard-kvm:
	taskset -c 12-15 vng --run $(INPUT)/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /workspaces/.agent-state/kprog-lanes/C --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/strict-runtime.mk guard-guest'

guard-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(INPUT)/bpf_x86_native_lab.ko
	KPROG_TEST_SHIM=$(INPUT)/libbpfrejit_shim.so KPROG_TEST_LOADER=$(INPUT)/libnative_loader.so python3 $(HERE)/check_object_startup.py strict-guard-return
