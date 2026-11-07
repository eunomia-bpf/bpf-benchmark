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

source-frame-proof:
	python3 $(HERE)/lift_startup_proofs.py bcc_trace_frame512 $(HERE)/bcc-capture-12/bpfrejit_1716_7e4864ff1af3e9d4.bpf tracepoint/native/startup
	objdump -dr -Mintel $(HERE)/startup-lift/bcc_trace_frame512/entry.native.o

source-frame-minimized-proof:
	python3 $(HERE)/lift_startup_proofs.py bcc_trace_frame8 $(HERE)/bcc-capture-12/bpfrejit_1716_7e4864ff1af3e9d4.bpf tracepoint/native/startup
	objdump -dr -Mintel $(HERE)/startup-lift/bcc_trace_frame8/entry.native.o

source-frame-cfg-proof:
	python3 $(HERE)/lift_startup_proofs.py bcc_trace_frame_cfg $(HERE)/bcc-capture-12/bpfrejit_1716_7e4864ff1af3e9d4.bpf tracepoint/native/startup
	objdump -dr -Mintel $(HERE)/startup-lift/bcc_trace_frame_cfg/entry.native.o

source-frame-cpu:
	python3 $(HERE)/check_source_frames.py

source-frame-bound-build:
	install -d $(HERE)/source-frame-bound
	clang -g -O2 -target bpf -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -c $(HERE)/source_frame_source.bpf.c -o $(HERE)/source-frame-bound/source.bpf.o
	python3 -c 'import json; from pathlib import Path; p=Path("$(HERE)/startup-lift/bcc_trace_frame_cfg/manifest-entry.json"); e=json.loads(p.read_text()); e["program"]="frame_source"; e["prog_type"]=5; Path("$(HERE)/source-frame-bound/manifest.json").write_text(json.dumps({"objects":[e]},indent=2)+"\n")'
	c++ -std=c++20 -Wall -Wextra -Werror -O2 -D__EXPORTED_HEADERS__ -DNATIVE_LINK_PATH='"$(LINK_TARGET)/release/native-link"' -I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include $(ROOT)/kprog/fidelity/bound_probe.cpp $(LOADER)/libnative_loader.a $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -o $(HERE)/source-frame-bound/bound-probe

source-frame-kvm:
	taskset -c 12-15 vng --run $(INPUT)/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /workspaces/.agent-state/kprog-lanes/C --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/strict-runtime.mk source-frame-guest'

source-frame-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(INPUT)/bpf_x86_native_lab.ko
	BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1 $(HERE)/source-frame-bound/bound-probe $(HERE)/source-frame-bound/source.bpf.o $(HERE)/source-frame-bound/manifest.json

fixed-load-prepare:
	python3 $(HERE)/fixed_load_consumer.py prepare

fixed-load-bcc-compile:
	KPROG_COMPILE_WORKERS=1 taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -f $(HERE)/Makefile compile PHASE=bcc-real-14

source-frame-call-proofs:
	for name in five_args saved_r6 backwards; do python3 $(HERE)/lift_startup_proofs.py frame_$$name $(HERE)/source-call-inputs/$$name.bpf.bin socket; done
	python3 $(HERE)/check_source_calls.py cpu frame_

fixed-load-integrate:
	python3 $(HERE)/fixed_load_consumer.py integrate

katran-real:
	python3 $(HERE)/katran_real.py
	KPROG_COMPILE_WORKERS=1 taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -f $(HERE)/Makefile compile PHASE=katran-real-1

MODULE_DIAGNOSTIC := /workspaces/.agent-state/kprog-lanes/C/module-diagnostic
module-diagnostic:
	taskset -c 12-15 prlimit --as=12884901888 --core=0 -- $(MAKE) -C $(ROOT)/kprog/tv/build-kernel-x86 M=$(MODULE_DIAGNOSTIC)/x86 ARCH=x86 bpf_x86_native_lab.ko

katran-real-2:
	python3 $(HERE)/katran_real.py katran-real-2
	KPROG_COMPILE_WORKERS=1 taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -f $(HERE)/Makefile compile PHASE=katran-real-2

katran-real-3:
	python3 $(HERE)/katran_real.py katran-real-3
	KPROG_COMPILE_WORKERS=1 taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -f $(HERE)/Makefile compile PHASE=katran-real-3

KATRAN_PHASE ?= katran-real-4
katran-verify:
	taskset -c 12-15 vng --run $(PAIRED)/bzImage --cwd $(ROOT) --rwdir $(ROOT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/Makefile guest-verify PHASE=$(KATRAN_PHASE)'

katran-real-4:
	python3 $(HERE)/katran_real.py katran-real-4
	KPROG_COMPILE_WORKERS=1 taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -f $(HERE)/Makefile compile PHASE=katran-real-4

BOUND_HELPER_SOURCE := /workspaces/.agent-state/kprog-lanes/C/bound-helper-source
bound-helper-build:
	cmake -S $(BOUND_HELPER_SOURCE)/kprog/libnativeloader -B $(BOUND_HELPER_SOURCE)/build -DNATIVE_LOADER_REPO_ROOT=$(ROOT) -DNATIVE_LOADER_LIBBPF_PREFIX=$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix -DNATIVE_LOADER_LIBBPF_LIBRARY=$(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -DNATIVE_LOADER_KERNEL_OFFSETS_INCLUDE=$(ROOT)/micro/programs/build-x86
	taskset -c 12-15 cmake --build $(BOUND_HELPER_SOURCE)/build -j2 --target native_loader_shared

katran-real-5:
	python3 $(HERE)/katran_real.py katran-real-5
	KPROG_COMPILE_WORKERS=1 taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -f $(HERE)/Makefile compile PHASE=katran-real-5

packet-helper-contract:
	python3 $(ROOT)/kprog/formal/tools/generate_abi_load_spec.py
	cd $(ROOT)/kprog/formal && lake build KProgFormal.Generated.GeneratedAbiLoad KProgFormal.X86MovLoadHandler

bcc-memory-proofs:
	python3 $(HERE)/embed_memory_runtime.py
	python3 $(HERE)/bcc_real.py $(HERE)/bcc-real-15 $(HERE)/bcc-memory-input
	KPROG_COMPILE_WORKERS=1 taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -f $(HERE)/Makefile compile PHASE=bcc-real-15

bcc-memory-retry:
	python3 $(HERE)/bcc_real.py $(HERE)/bcc-real-16 $(HERE)/bcc-memory-input
	KPROG_COMPILE_WORKERS=1 taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -f $(HERE)/Makefile compile PHASE=bcc-real-16

packet-helper-host:
	cc -O2 -Wall -Wextra -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -I$(ROOT)/vendor/libbpf/src $(HERE)/packet_helper_host.c -o $(HERE)/packet-helper-host
	$(HERE)/packet-helper-host
	$(MAKE) -f $(HERE)/anonymous.mk helper-host

katran-real-6:
	python3 $(HERE)/katran_real.py katran-real-6
	python3 -c 'from pathlib import Path; p=Path("$(HERE)/katran-real-6/simulator/kprog/formal/generated/x86_reg_write.h");s=p.read_text().replace("(STORAGE).b[1] =", "*(volatile __u8 *)&(STORAGE).b[1] =").replace("(STORAGE).b[0] =", "*(volatile __u8 *)&(STORAGE).b[0] =").replace("(STORAGE).w =", "*(volatile __u16 *)&(STORAGE).w =");p.write_text(s)'
	KPROG_COMPILE_WORKERS=1 taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -f $(HERE)/Makefile compile PHASE=katran-real-6

packet-helper-bound-build:
	python3 $(HERE)/packet_helper_bound.py

packet-helper-kvm:
	taskset -c 12-15 vng --run $(PAIRED)/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /workspaces/.agent-state/kprog-lanes/C --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(HERE)/strict-runtime.mk packet-helper-guest'

packet-helper-guest:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(INPUT)/bpf_x86_native_lab.ko
	BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1 $(HERE)/source-frame-bound/bound-probe $(HERE)/packet-helper-bound/source.bpf.o $(HERE)/packet-helper-bound/manifest.json 42 2

packet-stack-host:
	for name in stack_arm stack_write_lanes; do cc -Wall -Wextra -O2 -I$(ROOT)/kprog/formal -I$(ROOT)/kprog/x86 -I$(ROOT)/kprog -I$(ROOT)/vendor/libbpf/src $(ROOT)/kprog/formal/oracles/test_x86_$${name}_route_host.c -o $(HERE)/packet-$${name}-host; $(HERE)/packet-$${name}-host; done

katran-real-7:
	python3 $(HERE)/katran_real.py katran-real-7
	python3 -c 'from pathlib import Path; p=Path("$(HERE)/katran-real-7/simulator/kprog/formal/generated/x86_reg_write.h");s=p.read_text().replace("(STORAGE).b[1] = (__u8)(VALUE);", "do { if ((TAG) != (SCALAR_TAG)) *(volatile __u8 *)\u0026(STORAGE).b[1] = (__u8)(VALUE); else (STORAGE).b[1] = (__u8)(VALUE); } while (0);").replace("(STORAGE).b[0] = (__u8)(VALUE);", "do { if ((TAG) != (SCALAR_TAG)) *(volatile __u8 *)\u0026(STORAGE).b[0] = (__u8)(VALUE); else (STORAGE).b[0] = (__u8)(VALUE); } while (0);").replace("(STORAGE).w = (__u16)(VALUE);", "do { if ((TAG) != (SCALAR_TAG)) *(volatile __u16 *)\u0026(STORAGE).w = (__u16)(VALUE); else (STORAGE).w = (__u16)(VALUE); } while (0);");p.write_text(s)'
	KPROG_COMPILE_WORKERS=1 taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -f $(HERE)/Makefile compile PHASE=katran-real-7

bcc-byte-stack-compile:
	KPROG_COMPILE_WORKERS=1 taskset -c 12-15 prlimit --as=8589934592 --core=0 -- $(MAKE) -f $(HERE)/Makefile compile PHASE=bcc-real-17
