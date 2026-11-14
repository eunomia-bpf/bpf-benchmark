SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
HERE := $(ROOT)/kprog/perf/native-context
BUILD ?= $(HERE)/build-x86
KDIR := /workspaces/.agent-state/kprog-ck/build-x86
KRELEASE := $(shell cat $(KDIR)/include/config/kernel.release)
VMLINUX_DIR := $(ROOT)/vendor/bpf/targets/x86/$(KRELEASE)
LLVM_CONFIG := llvm-config-18
CXX := clang++-18
CC := clang-18

$(BUILD)/perf-context-lower: $(HERE)/perf-context-lower.cpp
	install -d $(BUILD)
	$(CXX) $$($(LLVM_CONFIG) --cxxflags) -std=c++17 -Wall -Wextra -Wno-unused-parameter $< -o $@ $$($(LLVM_CONFIG) --ldflags --libs core irreader bitwriter analysis support --system-libs)

$(BUILD)/layout: $(HERE)/layout.c $(VMLINUX_DIR)/vmlinux.h
	install -d $(BUILD)
	$(CC) -O2 -I$(VMLINUX_DIR) $< -o $@

$(BUILD)/layout.json: $(BUILD)/layout
	$< > $@

.PHONY: all
all: $(BUILD)/perf-context-lower $(BUILD)/layout.json

$(BUILD)/test-driver.o: $(HERE)/test-perf-context.c
	install -d $(BUILD)
	$(CC) -O3 -DTEST_DRIVER -c $< -o $@

$(BUILD)/test.plain: $(HERE)/test-perf-context.c $(BUILD)/test-driver.o
	$(CC) -O3 $< $(BUILD)/test-driver.o -o $@

$(BUILD)/test.lowered: $(HERE)/test-perf-context.c $(BUILD)/test-driver.o $(BUILD)/perf-context-lower $(BUILD)/layout.json
	$(CC) -O3 -emit-llvm -c $< -o $(BUILD)/test.bc
	$(BUILD)/perf-context-lower $(BUILD)/test.bc --layout=$(BUILD)/layout.json -o $(BUILD)/test.lowered.bc
	$(CC) -O3 $(BUILD)/test.lowered.bc $(BUILD)/test-driver.o -o $@

.PHONY: check
check: $(BUILD)/test.plain $(BUILD)/test.lowered
	$(BUILD)/test.plain && result=0 || result=$$?; test $$result = 1
	$(BUILD)/test.lowered

OUTPUT ?= $(ROOT)/corpus/results/perf-context-20261113
.PHONY: otel
otel: all
	python3 $(HERE)/build-otel.py --build $(BUILD) --output $(OUTPUT)

$(BUILD)/core-flavor-lower: $(HERE)/core-flavor-lower.cpp
	install -d $(BUILD)
	$(CXX) $$($(LLVM_CONFIG) --cxxflags) -std=c++17 -Wall -Wextra -Wno-unused-parameter $< -o $@ -l:libclang-cpp.so.18.1 $$($(LLVM_CONFIG) --ldflags --libs --system-libs) -lbpf

$(BUILD)/core.fixture.plain: $(HERE)/test-core-flavor.c
	install -d $(BUILD)
	$(CC) -O2 -DMICRO_NATIVE -include $(ROOT)/vendor/bpf/native_compat.h -I$(VMLINUX_DIR) $< -o $@

$(BUILD)/core.fixture.i: $(HERE)/test-core-flavor.c $(HERE)/core-queries.h
	install -d $(BUILD)
	$(CC) -DMICRO_NATIVE -DCORE_LOWER -include $(ROOT)/vendor/bpf/native_compat.h -I$(HERE) -I$(VMLINUX_DIR) -E -P $< -o $@

$(BUILD)/core.fixture.lowered.i: $(BUILD)/core.fixture.i $(BUILD)/core-flavor-lower
	$(BUILD)/core-flavor-lower $< $@ $(KDIR)/vmlinux

$(BUILD)/core.fixture.fixed: $(BUILD)/core.fixture.lowered.i
	$(CC) -O2 -fms-extensions -Wno-deprecated-non-prototype $< -o $@

.PHONY: core-check
core-check: $(BUILD)/core.fixture.plain $(BUILD)/core.fixture.fixed
	$(BUILD)/core.fixture.plain && result=0 || result=$$?; test $$result = 1
	$(BUILD)/core.fixture.fixed

CORE_OUTPUT ?= $(ROOT)/corpus/results/perf-core-20261113
CORE_SELECTION ?= --only bpf_fork bpf_generic_kprobe_v61
.PHONY: tetragon-core
tetragon-core: $(BUILD)/core-flavor-lower
	python3 $(HERE)/build-tetragon.py --build $(BUILD) --kernel $(KDIR)/vmlinux --output $(CORE_OUTPUT) $(CORE_SELECTION)

OBSERVER_OUTPUT ?= $(ROOT)/corpus/results/perf-observers-20261113
.PHONY: tetra-observer
tetra-observer:
	install -d $(BUILD) $(OBSERVER_OUTPUT)
	cd $(ROOT)/vendor/repos/tetragon && CGO_ENABLED=0 go build -mod=vendor -p=4 -ldflags '-s -w' -o $(BUILD)/tetra ./cmd/tetra/
	install -m 755 $(BUILD)/tetra $(OBSERVER_OUTPUT)/tetra
	$(OBSERVER_OUTPUT)/tetra getevents --help > $(OBSERVER_OUTPUT)/getevents-help.txt

LINK_PROFILE_OUTPUT ?= $(ROOT)/corpus/results/perf-link-load-profile-20261113
LINK_PROFILE_PAYLOAD ?= $(ROOT)/corpus/results/verified-linker-runtime-maps-20261113/native-link
.PHONY: linker-profile
linker-profile:
	install -d $(LINK_PROFILE_OUTPUT)
	install -m 755 $(HERE)/link-cost.py $(LINK_PROFILE_OUTPUT)/native-link
	python3 -c 'import json, pathlib, sys; (pathlib.Path(sys.argv[1]) / "config.json").write_text(json.dumps({"linker": sys.argv[2]}, indent=2) + "\n")' '$(LINK_PROFILE_OUTPUT)' '$(LINK_PROFILE_PAYLOAD)'

LOADER_PERF_BUILD ?= /var/tmp/kprog-tmp/perf/perf-build
LOADER_PERF_SOURCE ?= $(LOADER_PERF_BUILD)/perf
LOADER_PERF_OUTPUT ?= /var/tmp/kprog-tmp/perf/var-tmp/perf
.PHONY: loader-perf-deps loader-perf-build loader-perf-tool
loader-perf-deps:
	apt-get install -y --no-install-recommends libdw-dev

# Software cpu-clock sampler only: PMU event tables and Python bindings unused.
# Tool build from the sole kernel source; no kernel/base/image rebuild.
loader-perf-build:
	install -d $(LOADER_PERF_BUILD)
	$(MAKE) -C $(ROOT)/vendor/linux-framework/tools/perf O=$(LOADER_PERF_BUILD)/ -j4 NO_JEVENTS=1 NO_LIBBPF=1 NO_LIBPYTHON=1 NO_LIBPERL=1 NO_LIBTRACEEVENT=1 NO_SLANG=1 NO_LIBUNWIND=1 NO_LIBNUMA=1 NO_AUXTRACE=1 NO_LIBCAP=1 NO_LIBLLVM=1
	$(LOADER_PERF_SOURCE) version --build-options

loader-perf-tool:
	install -D -m 755 $(LOADER_PERF_SOURCE) $(LOADER_PERF_OUTPUT)
	$(LOADER_PERF_OUTPUT) version --build-options

MEMORY_FLAGS_OUTPUT ?= /var/tmp/kprog-tmp/perf/memory-flags
MEMORY_FLAGS_LOGS ?= /workspaces/kprog-raw/perf/20261113-memory-flags
.PHONY: memory-flags
memory-flags:
	python3 $(HERE)/memory-flags.py --app tracee --only tracee --output $(MEMORY_FLAGS_OUTPUT) --logs $(MEMORY_FLAGS_LOGS)

LINK_MEMORY_TARGET ?= /var/tmp/kprog-tmp/perf/native-link-memory
.PHONY: memory-link-check memory-link-build
memory-link-check:
	CARGO_TARGET_DIR=$(LINK_MEMORY_TARGET) CARGO_PROFILE_DEV_OPT_LEVEL=3 CARGO_PROFILE_DEV_DEBUG=0 cargo test --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml

memory-link-build:
	CARGO_TARGET_DIR=$(LINK_MEMORY_TARGET) CARGO_PROFILE_DEV_OPT_LEVEL=3 CARGO_PROFILE_DEV_DEBUG=0 cargo build --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml

LINK_MEMORY_EVIDENCE ?= /workspaces/kprog-raw/perf/20261113-local-memory/objects
.PHONY: memory-link-evidence
memory-link-evidence:
	python3 $(HERE)/memory-link-evidence.py --candidate $(LINK_MEMORY_TARGET)/debug/native-link --reference $(ROOT)/corpus/results/verified-linker-runtime-maps-20261113/native-link.real --output $(LINK_MEMORY_EVIDENCE)

LINK_MEMORY_PAYLOAD ?= $(ROOT)/corpus/results/perf-local-memory-20261113
LINK_MEMORY_PROFILE ?= /workspaces/kprog-raw/perf/20261113-local-memory/profile-on
LINK_MEMORY_CAPTURE ?= $(ROOT)/corpus/results/perf-memory-profile-on-20261113
.PHONY: memory-link-payload memory-profile
memory-link-payload:
	install -d $(LINK_MEMORY_PAYLOAD)
	install -m 755 $(LINK_MEMORY_TARGET)/debug/native-link $(LINK_MEMORY_PAYLOAD)/native-link.real
	strip --strip-debug $(LINK_MEMORY_PAYLOAD)/native-link.real
	install -m 755 $(HERE)/native-link-memory.sh $(LINK_MEMORY_PAYLOAD)/native-link-on
	install -m 755 $(HERE)/native-link-memory.sh $(LINK_MEMORY_PAYLOAD)/native-link-off
	$(LINK_MEMORY_PAYLOAD)/native-link-on --help > $(LINK_MEMORY_PAYLOAD)/help.txt

memory-profile:
	env PATH=$(ROOT)/kprog/perf/may29-image/eqcodex-bin:$$PATH EQCODEX_OUT=$(LINK_MEMORY_CAPTURE) EQCODEX_NATIVE_LINK_BINARY=$(LINK_MEMORY_PAYLOAD)/native-link-on \
		python3 $(ROOT)/kprog/perf/profile/phase-profile.py run --app tracee/monitor --seconds 45 --cpus 16-19 --vcpus 4 --memory 8G --freq 999 --out $(LINK_MEMORY_PROFILE) --annotate 0

OTEL_PROFILE_RAW ?= /workspaces/kprog-raw/perf/20261114-otel-profile/run
OTEL_PROFILE_CAPTURE ?= $(ROOT)/corpus/results/perf-otel-profile-20261114
OTEL_PROFILE_MANIFEST ?= $(ROOT)/corpus/results/perf-otel-upstream-20261114/manifest-context.json
PROFILE_TOOL_BUILD ?= /var/tmp/kprog-tmp/perf/profile-tool
PROFILE_PERF_SOURCE ?= /workspaces/kprog-raw/perf/20261113-loader-cpu-profile/tool/perf
.PHONY: profile-tool otel-profile
profile-tool:
	install -d $(PROFILE_TOOL_BUILD)
	install -m755 $(PROFILE_PERF_SOURCE) $(PROFILE_TOOL_BUILD)/perf
	$(PROFILE_TOOL_BUILD)/perf version --build-options

otel-profile: profile-tool
	env PATH=$(ROOT)/kprog/perf/may29-image/eqcodex-bin:$$PATH EQCODEX_OUT=$(OTEL_PROFILE_CAPTURE) EQCODEX_PROGRESS_LOG=/var/tmp/out/guest.log EQCODEX_NATIVE_LINK_BINARY=$(LINK_MEMORY_PAYLOAD)/native-link-on \
		python3 $(ROOT)/kprog/perf/profile/phase-profile.py run --app otelcol-ebpf-profiler/profiling --seconds 45 --cpus 16-19 --vcpus 4 --memory 32G --freq 199 --out $(OTEL_PROFILE_RAW) --annotate 0 --manifest $(OTEL_PROFILE_MANIFEST) --state-root /var/tmp/kprog-tmp/perf/phase-profile --perf $(PROFILE_TOOL_BUILD)/perf

.PHONY: memory-host-bench
memory-host-bench:
	NATIVE_LINK_MEMORY_BENCH_OUTPUT=/workspaces/kprog-raw/perf/20261113-local-memory/host-microbench.json CARGO_TARGET_DIR=$(LINK_MEMORY_TARGET) CARGO_PROFILE_DEV_OPT_LEVEL=3 CARGO_PROFILE_DEV_DEBUG=0 \
		cargo test --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml memory_host_microbenchmark -- --ignored

SOCKET_BUILD ?= /var/tmp/kprog-tmp/perf/socket-context
CILIUM_UPSTREAM := $(ROOT)/vendor/repos/cilium/bpf
UPSTREAM_SOCKET_FEATURES ?= -DENABLE_IPV4=1
.PHONY: upstream-socket-ir
upstream-socket-ir:
	install -d $(SOCKET_BUILD)
	prlimit --as=8589934592 -- $(CC) -target bpf -O2 -g -emit-llvm -c -D__TARGET_ARCH_x86 $(UPSTREAM_SOCKET_FEATURES) -DSKIP_DEBUG=1 \
		-I$(CILIUM_UPSTREAM) -I$(CILIUM_UPSTREAM)/include -I/usr/include/x86_64-linux-gnu \
		$(CILIUM_UPSTREAM)/bpf_sock.c -o $(SOCKET_BUILD)/upstream-sock.bc
	llvm-dis-18 $(SOCKET_BUILD)/upstream-sock.bc -o $(SOCKET_BUILD)/upstream-sock.ll
	$(CC) -target bpf -O2 -c $(SOCKET_BUILD)/upstream-sock.bc -o $(SOCKET_BUILD)/upstream-sock.bpf.o

$(SOCKET_BUILD)/public-layout: $(HERE)/socket-public-layout.c $(CILIUM_UPSTREAM)/include/linux/bpf.h
	install -d $(SOCKET_BUILD)
	$(CC) -O2 -I$(CILIUM_UPSTREAM)/include -I/usr/include/x86_64-linux-gnu $< -o $@

$(SOCKET_BUILD)/physical-layout: $(HERE)/socket-physical-layout.c $(VMLINUX_DIR)/vmlinux.h
	install -d $(SOCKET_BUILD)
	$(CC) -O2 -Wno-unknown-attributes -I$(VMLINUX_DIR) $< -o $@

$(SOCKET_BUILD)/public-layout.json: $(SOCKET_BUILD)/public-layout
	$< > $@
$(SOCKET_BUILD)/physical-layout.json: $(SOCKET_BUILD)/physical-layout
	$< > $@

$(SOCKET_BUILD)/socket-context-lower: $(HERE)/socket-context-lower.cpp
	install -d $(SOCKET_BUILD)
	$(CXX) $$($(LLVM_CONFIG) --cxxflags) -std=c++17 -Wall -Wextra -Wno-unused-parameter $< -o $@ $$($(LLVM_CONFIG) --ldflags --libs core irreader bitwriter analysis support --system-libs)

$(SOCKET_BUILD)/driver.o: $(HERE)/test-socket-driver.c $(VMLINUX_DIR)/vmlinux.h
	install -d $(SOCKET_BUILD)
	$(CC) -O2 -Wno-unknown-attributes -I$(VMLINUX_DIR) -c $< -o $@

.PHONY: socket-context-check
socket-context-check: $(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/public-layout.json $(SOCKET_BUILD)/physical-layout.json $(SOCKET_BUILD)/driver.o
	$(CC) -O2 -I$(CILIUM_UPSTREAM)/include -emit-llvm -c $(HERE)/test-socket-context.c -o $(SOCKET_BUILD)/fixture.bc
	$(CC) -O2 $(SOCKET_BUILD)/fixture.bc $(SOCKET_BUILD)/driver.o -o $(SOCKET_BUILD)/plain
	$(SOCKET_BUILD)/plain && result=0 || result=$$?; test $$result = 1
	$(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/fixture.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json -o $(SOCKET_BUILD)/fixture.physical.bc
	$(CC) -O2 $(SOCKET_BUILD)/fixture.physical.bc $(SOCKET_BUILD)/driver.o -o $(SOCKET_BUILD)/fixed
	$(SOCKET_BUILD)/fixed

.PHONY: upstream-socket-native
upstream-socket-native: upstream-socket-ir $(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/public-layout.json $(SOCKET_BUILD)/physical-layout.json
	python3 $(HERE)/socket-helper-names.py > $(SOCKET_BUILD)/helper-names.json
	$(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/upstream-sock.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json --native-codegen --helper-names $(SOCKET_BUILD)/helper-names.json -o $(SOCKET_BUILD)/upstream-sock.physical.bc
	$(CC) -target x86_64-linux-gnu -O3 -g -fPIC -fno-optimize-sibling-calls -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-jump-tables -c $(SOCKET_BUILD)/upstream-sock.physical.bc -o $(SOCKET_BUILD)/upstream-sock.native.o
	llvm-objdump-18 -dr $(SOCKET_BUILD)/upstream-sock.native.o > $(SOCKET_BUILD)/upstream-sock.native.dis

.PHONY: socket-context-errors
socket-context-errors: $(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/public-layout.json $(SOCKET_BUILD)/physical-layout.json
	for kind in DYNAMIC OUTSIDE ESCAPE; do \
		$(CC) -O2 -D$$kind -I$(CILIUM_UPSTREAM)/include -emit-llvm -c $(HERE)/test-socket-errors.c -o $(SOCKET_BUILD)/$$kind.bc; \
		$(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/$$kind.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json -o $(SOCKET_BUILD)/$$kind.output.bc && result=0 || result=$$?; \
		test $$result = 1; \
	done

.PHONY: upstream-socket-proof
upstream-socket-proof: upstream-socket-native
	python3 $(HERE)/socket-proof.py --input $(SOCKET_BUILD)/upstream-sock.native.o --linker $(LINK_MEMORY_PAYLOAD)/native-link.real --output $(SOCKET_BUILD)/proofs

SOCKET_RAW ?= /workspaces/kprog-raw/perf/20261113-socket-context
SOCKET_RECEIPT ?= $(ROOT)/kprog/results/perf_20261113/socket-context-host.json
.PHONY: socket-retain
socket-retain:
	python3 $(HERE)/socket-retain.py --build $(SOCKET_BUILD) --raw $(SOCKET_RAW) --output $(SOCKET_RECEIPT) --features='$(UPSTREAM_SOCKET_FEATURES)' --log $(SOCKET_RAW)/complete.log

CILIUM_CAPTURE ?=
CILIUM_IR_BUILD ?= /var/tmp/kprog-tmp/perf/cilium-context
CILIUM_UNIT ?= bpf_lxc
CILIUM_INPUT_ARGS ?=
.PHONY: upstream-cilium-ir
upstream-cilium-ir:
	prlimit --as=8589934592 -- python3 $(HERE)/cilium-upstream.py --capture $(CILIUM_CAPTURE) --output $(CILIUM_IR_BUILD)/$(CILIUM_UNIT) $(CILIUM_INPUT_ARGS)
	llvm-dis-18 $(CILIUM_IR_BUILD)/$(CILIUM_UNIT).bc -o $(CILIUM_IR_BUILD)/$(CILIUM_UNIT).ll
	prlimit --as=8589934592 -- $(CC) -target bpf -mcpu=v3 -O2 -c $(CILIUM_IR_BUILD)/$(CILIUM_UNIT).bc -o $(CILIUM_IR_BUILD)/$(CILIUM_UNIT).bpf.o

PACKET_BUILD ?= /var/tmp/kprog-tmp/perf/packet-context
$(PACKET_BUILD)/public-layout: $(HERE)/packet-public-layout.c $(CILIUM_UPSTREAM)/include/linux/bpf.h
	install -d $(PACKET_BUILD)
	$(CC) -O2 -I$(CILIUM_UPSTREAM)/include -I/usr/include/x86_64-linux-gnu $< -o $@
$(PACKET_BUILD)/physical-layout: $(HERE)/packet-physical-layout.c $(VMLINUX_DIR)/vmlinux.h
	install -d $(PACKET_BUILD)
	$(CC) -O2 -Wno-unknown-attributes -I$(VMLINUX_DIR) $< -o $@
$(PACKET_BUILD)/driver.o: $(HERE)/test-packet-driver.c $(VMLINUX_DIR)/vmlinux.h
	install -d $(PACKET_BUILD)
	$(CC) -O2 -Wno-unknown-attributes -I$(VMLINUX_DIR) -c $< -o $@
$(PACKET_BUILD)/driver.asm.o: $(HERE)/test-packet-driver.c $(VMLINUX_DIR)/vmlinux.h
	install -d $(PACKET_BUILD)
	$(CC) -O2 -DBPF_POINTER_ASM -Wno-unknown-attributes -I$(VMLINUX_DIR) -c $< -o $@
.PHONY: packet-context-check
packet-context-check: $(SOCKET_BUILD)/socket-context-lower $(PACKET_BUILD)/public-layout $(PACKET_BUILD)/physical-layout $(PACKET_BUILD)/driver.o $(PACKET_BUILD)/driver.asm.o
	$(PACKET_BUILD)/public-layout > $(PACKET_BUILD)/public-layout.json
	$(PACKET_BUILD)/physical-layout > $(PACKET_BUILD)/physical-layout.json
	$(CC) -O2 -I$(CILIUM_UPSTREAM)/include -emit-llvm -c $(HERE)/test-packet-context.c -o $(PACKET_BUILD)/fixture.bc
	$(CC) -O2 $(PACKET_BUILD)/fixture.bc $(PACKET_BUILD)/driver.o -o $(PACKET_BUILD)/plain
	$(PACKET_BUILD)/plain && result=0 || result=$$?; test $$result = 1
	$(SOCKET_BUILD)/socket-context-lower $(PACKET_BUILD)/fixture.bc --public-layout $(PACKET_BUILD)/public-layout.json --physical-layout $(PACKET_BUILD)/physical-layout.json -o $(PACKET_BUILD)/fixture.physical.bc
	$(CC) -O2 $(PACKET_BUILD)/fixture.physical.bc $(PACKET_BUILD)/driver.o -o $(PACKET_BUILD)/fixed
	$(PACKET_BUILD)/fixed
	$(CC) -target bpf -O2 -DBPF_POINTER_ASM -I$(CILIUM_UPSTREAM)/include -emit-llvm -c $(HERE)/test-packet-context.c -o $(PACKET_BUILD)/fixture.asm.bc
	python3 $(HERE)/socket-helper-names.py > $(PACKET_BUILD)/helper-names.json
	$(SOCKET_BUILD)/socket-context-lower $(PACKET_BUILD)/fixture.asm.bc --public-layout $(PACKET_BUILD)/public-layout.json --physical-layout $(PACKET_BUILD)/physical-layout.json --native-codegen --helper-names $(PACKET_BUILD)/helper-names.json -o $(PACKET_BUILD)/fixture.asm.physical.bc
	$(CC) -O2 $(PACKET_BUILD)/fixture.asm.physical.bc $(PACKET_BUILD)/driver.asm.o -o $(PACKET_BUILD)/fixed.asm
	$(PACKET_BUILD)/fixed.asm

.PHONY: upstream-cilium-native
upstream-cilium-native: upstream-cilium-ir $(SOCKET_BUILD)/socket-context-lower $(PACKET_BUILD)/public-layout $(PACKET_BUILD)/physical-layout
	$(PACKET_BUILD)/public-layout > $(PACKET_BUILD)/public-layout.json
	$(PACKET_BUILD)/physical-layout > $(PACKET_BUILD)/physical-layout.json
	python3 $(HERE)/socket-helper-names.py > $(PACKET_BUILD)/helper-names.json
	$(SOCKET_BUILD)/socket-context-lower $(CILIUM_IR_BUILD)/$(CILIUM_UNIT).bc --public-layout $(PACKET_BUILD)/public-layout.json --physical-layout $(PACKET_BUILD)/physical-layout.json --native-codegen --helper-names $(PACKET_BUILD)/helper-names.json -o $(CILIUM_IR_BUILD)/$(CILIUM_UNIT).physical.bc
	prlimit --as=8589934592 -- $(CC) -target x86_64-linux-gnu -O3 -g -fPIC -fno-optimize-sibling-calls -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-jump-tables -c $(CILIUM_IR_BUILD)/$(CILIUM_UNIT).physical.bc -o $(CILIUM_IR_BUILD)/$(CILIUM_UNIT).native.o

.PHONY: upstream-cilium-link
upstream-cilium-link: upstream-cilium-native
	python3 $(HERE)/socket-proof.py --input $(CILIUM_IR_BUILD)/$(CILIUM_UNIT).native.o --linker $(LINK_MEMORY_PAYLOAD)/native-link.real --output $(CILIUM_IR_BUILD)/$(CILIUM_UNIT)-links --section-prefix tc/ --section-prefix xdp

.PHONY: cilium-kernel-roundtrip
cilium-kernel-roundtrip:
	python3 $(HERE)/socket-proof.py --input $(CILIUM_IR_BUILD)/$(CILIUM_UNIT).native.o --linker $(LINK_MEMORY_PAYLOAD)/native-link-off --output $(CILIUM_IR_BUILD)/$(CILIUM_UNIT)-roundtrip --section-prefix tc/ --section-prefix xdp --kernel-roundtrip

.PHONY: cilium-object-compare
cilium-object-compare:
	python3 $(HERE)/cilium-object-compare.py --record $(CILIUM_IR_BUILD)/$(CILIUM_UNIT).json --output $(CILIUM_IR_BUILD)/$(CILIUM_UNIT)-comparison.json

.PHONY: cilium-llc-reference
cilium-llc-reference:
	prlimit --as=8589934592 -- llc-18 -march=bpf -mcpu=v3 -filetype=obj $(CILIUM_IR_BUILD)/$(CILIUM_UNIT).bc -o $(CILIUM_IR_BUILD)/$(CILIUM_UNIT).llc.bpf.o
	python3 $(HERE)/cilium-object-compare.py --record $(CILIUM_IR_BUILD)/$(CILIUM_UNIT).json --extra-bpf $(CILIUM_IR_BUILD)/$(CILIUM_UNIT).llc.bpf.o --output $(CILIUM_IR_BUILD)/$(CILIUM_UNIT)-llc-comparison.json

.PHONY: cilium-retain
cilium-retain:
	python3 $(HERE)/cilium-retain.py --raw /workspaces/kprog-raw/perf/20261113-packet-context --upstream-build $(CILIUM_IR_BUILD) --packet-build $(PACKET_BUILD) --compiler $(SOCKET_BUILD)/socket-context-lower --output $(ROOT)/kprog/results/perf_20261113/packet-context-host.json

.PHONY: cilium-live-prepare
CILIUM_LIVE_RAW ?= /workspaces/kprog-raw/perf/20261113-cilium-live-config
CILIUM_LIVE_CAPTURE ?= $(ROOT)/corpus/results/perf-cilium-live-config-20261113
CILIUM_LIVE_RUN ?= $(ROOT)/corpus/results/x86_kvm_corpus_20261113_075230_200030
CILIUM_LIVE_RECEIPT ?= $(ROOT)/kprog/results/perf_20261113/cilium-live-config-runtime.json
CILIUM_BASELINE_SNAPSHOT ?= baseline-0001
cilium-live-prepare:
	python3 $(HERE)/cilium-live-prepare.py --raw $(CILIUM_LIVE_RAW) --capture $(CILIUM_LIVE_CAPTURE) --run $(CILIUM_LIVE_RUN) --output $(CILIUM_LIVE_RECEIPT) --baseline-snapshot $(CILIUM_BASELINE_SNAPSHOT)

.PHONY: cilium-replay-retain
CILIUM_REPLAY_BUILD ?= /var/tmp/kprog-tmp/perf/cilium-live-replay
CILIUM_REPLAY_RAW ?= /workspaces/kprog-raw/perf/20261113-cilium-live-replay
CILIUM_REPLAY_RECEIPT ?= $(ROOT)/kprog/results/perf_20261113/cilium-live-source-replay.json
CILIUM_REPLAY_PROTOCOL ?= c4135e82c
CILIUM_REPLAY_ARGS ?=
cilium-replay-retain:
	python3 $(HERE)/cilium-replay-retain.py --build $(CILIUM_REPLAY_BUILD) --raw $(CILIUM_REPLAY_RAW) --output $(CILIUM_REPLAY_RECEIPT) --protocol-commit $(CILIUM_REPLAY_PROTOCOL) $(CILIUM_REPLAY_ARGS)

CILIUM_PAYLOAD ?= $(ROOT)/corpus/results/perf-cilium-same-source-20261113
.PHONY: cilium-candidate
cilium-candidate:
	install -d $(CILIUM_PAYLOAD)
	install -m644 $(CILIUM_IR_BUILD)/bpf_lxc.native.o $(CILIUM_IR_BUILD)/bpf_host.native.o $(CILIUM_IR_BUILD)/bpf_xdp.native.o $(CILIUM_PAYLOAD)
	python3 $(ROOT)/vendor/bpf/write_native_manifest.py --app cilium --llvm-nm llvm-nm-18 --output $(CILIUM_PAYLOAD)/manifest.json \
		--object $(CILIUM_PAYLOAD)/bpf_lxc.native.o,source_map_prefix=cilium_calls_0 \
		--object $(CILIUM_PAYLOAD)/bpf_host.native.o,source_map_prefix=cilium_calls_ho,source_map_prefix=cilium_calls_ne \
		--object $(CILIUM_PAYLOAD)/bpf_xdp.native.o,prog_type=6

.PHONY: cilium-candidate-witness
cilium-candidate-witness: cilium-candidate
	for unit in bpf_lxc bpf_host bpf_xdp; do install -m644 $(CILIUM_IR_BUILD)/$$unit.direct.bpf.o $(CILIUM_PAYLOAD)/$$unit.original.bpf.o; done
	python3 $(HERE)/original-bpf-index.py --output $(CILIUM_PAYLOAD)/original-bpf-index.json \
		--pair $(CILIUM_PAYLOAD)/bpf_lxc.native.o $(CILIUM_PAYLOAD)/bpf_lxc.original.bpf.o \
		--pair $(CILIUM_PAYLOAD)/bpf_host.native.o $(CILIUM_PAYLOAD)/bpf_host.original.bpf.o \
		--pair $(CILIUM_PAYLOAD)/bpf_xdp.native.o $(CILIUM_PAYLOAD)/bpf_xdp.original.bpf.o

BPF_INDEX_BUILD ?= /var/tmp/kprog-tmp/perf/original-bpf-index
.PHONY: original-bpf-index
original-bpf-index:
	python3 $(HERE)/original-bpf-index.py --output $(BPF_INDEX_OUTPUT) $(BPF_INDEX_PAIRS)

.PHONY: original-bpf-index-check
original-bpf-index-check:
	install -d $(BPF_INDEX_BUILD)
	$(CC) -target bpf -O2 -g -c $(HERE)/test-native-frame.c -o $(BPF_INDEX_BUILD)/fixture.bpf.o
	$(CC) -O2 -g -c $(HERE)/test-native-frame.c -o $(BPF_INDEX_BUILD)/fixture.native.o
	python3 $(HERE)/check-original-bpf-index.py $(BPF_INDEX_BUILD)/fixture.native.o $(BPF_INDEX_BUILD)/fixture.bpf.o

.PHONY: cilium-context-manifest
MANIFEST_CONTEXT_ARGS ?=
cilium-context-manifest:
	python3 $(HERE)/manifest-context.py --input $(CILIUM_PAYLOAD)/manifest.json --output $(CILIUM_PAYLOAD)/manifest-context.json $(MANIFEST_CONTEXT_ARGS)

.PHONY: cilium-config-check
cilium-config-check:
	python3 -m unittest discover -s $(ROOT)/kprog/perf/may29-image -p test_cilium_config.py
	python3 -m unittest discover -s $(HERE) -p test_cilium_live_prepare.py

.PHONY: observer-check
observer-check:
	python3 -m unittest discover -s $(ROOT)/kprog/perf/may29-image -p test_eqcodex_capture.py

SWITCH_BUILD ?= /var/tmp/kprog-tmp/perf/native-switch
.PHONY: native-switch-check
native-switch-check: $(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/public-layout.json $(SOCKET_BUILD)/physical-layout.json
	install -d $(SWITCH_BUILD)
	$(CC) -target bpf -O2 -emit-llvm -c $(HERE)/test-native-switch.c -o $(SWITCH_BUILD)/input.bc
	python3 $(HERE)/socket-helper-names.py > $(SWITCH_BUILD)/helper-names.json
	$(SOCKET_BUILD)/socket-context-lower $(SWITCH_BUILD)/input.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json --native-codegen --helper-names $(SWITCH_BUILD)/helper-names.json -o $(SWITCH_BUILD)/native.bc
	$(CC) -target x86_64-linux-gnu -O3 -fPIC -fno-optimize-sibling-calls -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-jump-tables -c $(SWITCH_BUILD)/native.bc -o $(SWITCH_BUILD)/native.o
	$(LINK_MEMORY_PAYLOAD)/native-link.real --mode proof --input $(SWITCH_BUILD)/native.o --symbol native_switch --output $(SWITCH_BUILD)/proof.o
	$(LINK_MEMORY_PAYLOAD)/native-link.real --mode kernel --input $(SWITCH_BUILD)/proof.o --symbol native_switch --output $(SWITCH_BUILD)/blob.bin

.PHONY: native-switch-evidence
native-switch-evidence:
	tar -czf $(ROOT)/kprog/results/perf_20261113/native-switch-regression.tar.gz -C /workspaces/kprog-raw/perf 20261113-native-switch

CORE_IR_BUILD ?= /var/tmp/kprog-tmp/perf/core-ir
$(CORE_IR_BUILD)/libbpf/libbpf.a:
	$(MAKE) -C $(ROOT)/vendor/libbpf/src BUILD_STATIC_ONLY=1 OBJDIR=$(CORE_IR_BUILD)/libbpf

$(CORE_IR_BUILD)/core-ir-lower: $(HERE)/core-ir-lower.cpp $(CORE_IR_BUILD)/libbpf/libbpf.a
	$(CXX) $$($(LLVM_CONFIG) --cxxflags) -std=c++17 -Wall -Wextra -Wno-unused-parameter -I$(ROOT)/vendor/libbpf/src -I$(ROOT)/vendor/libbpf/include/uapi $< -o $@ $(CORE_IR_BUILD)/libbpf/libbpf.a -lelf -lz $$($(LLVM_CONFIG) --ldflags --libs core irreader bitwriter passes --system-libs)

.PHONY: core-ir-tool
core-ir-tool: $(CORE_IR_BUILD)/core-ir-lower

CORE_IR_INPUT ?= $(CORE_IR_BUILD)/input.bc
CORE_IR_LOCAL_BPF ?= $(CORE_IR_BUILD)/input.bpf.o
CORE_IR_OUTPUT ?= $(CORE_IR_BUILD)/resolved.bc
CORE_IR_REPORT ?= $(CORE_IR_BUILD)/resolved.json
.PHONY: core-ir-resolve
core-ir-resolve: core-ir-tool
	prlimit --as=17179869184 -- $(CORE_IR_BUILD)/core-ir-lower $(CORE_IR_INPUT) --local-bpf $(CORE_IR_LOCAL_BPF) --target-btf $(KDIR)/vmlinux --report $(CORE_IR_REPORT) -o $(CORE_IR_OUTPUT)

.PHONY: core-ir-check
core-ir-check: core-ir-tool $(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/public-layout.json $(SOCKET_BUILD)/physical-layout.json
	$(CC) -target bpf -O2 -g -I/usr/include/x86_64-linux-gnu -emit-llvm -c $(HERE)/test-core-ir.c -o $(CORE_IR_BUILD)/fixture.bc
	$(CC) -target bpf -O2 -g -c $(CORE_IR_BUILD)/fixture.bc -o $(CORE_IR_BUILD)/fixture.bpf.o
	$(CORE_IR_BUILD)/core-ir-lower $(CORE_IR_BUILD)/fixture.bc --local-bpf $(CORE_IR_BUILD)/fixture.bpf.o --target-btf $(KDIR)/vmlinux --report $(CORE_IR_BUILD)/fixture.json -o $(CORE_IR_BUILD)/fixture.fixed.bc
	python3 $(HERE)/socket-helper-names.py > $(CORE_IR_BUILD)/helper-names.json
	$(SOCKET_BUILD)/socket-context-lower $(CORE_IR_BUILD)/fixture.fixed.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json --native-codegen --helper-names $(CORE_IR_BUILD)/helper-names.json -o $(CORE_IR_BUILD)/fixture.native.bc
	$(CC) -O2 -DTEST_DRIVER -I$(VMLINUX_DIR) -c $(HERE)/test-core-ir.c -o $(CORE_IR_BUILD)/driver.o
	$(CC) -target x86_64-linux-gnu -O2 $(CORE_IR_BUILD)/fixture.native.bc $(CORE_IR_BUILD)/driver.o -o $(CORE_IR_BUILD)/fixture.fixed
	$(CORE_IR_BUILD)/fixture.fixed
	$(CC) -target bpf -O2 -g -emit-llvm -c $(HERE)/test-core-ir-ids.c -o $(CORE_IR_BUILD)/ids.bc
	$(CC) -target bpf -O2 -g -c $(CORE_IR_BUILD)/ids.bc -o $(CORE_IR_BUILD)/ids.bpf.o
	$(CORE_IR_BUILD)/core-ir-lower $(CORE_IR_BUILD)/ids.bc --local-bpf $(CORE_IR_BUILD)/ids.bpf.o --target-btf $(KDIR)/vmlinux --report $(CORE_IR_BUILD)/ids.json -o $(CORE_IR_BUILD)/ids.fixed.bc
	$(SOCKET_BUILD)/socket-context-lower $(CORE_IR_BUILD)/ids.fixed.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json --native-codegen --helper-names $(CORE_IR_BUILD)/helper-names.json -o $(CORE_IR_BUILD)/ids.native.bc
	$(CC) -target x86_64-linux-gnu -O2 -DTEST_DRIVER $(HERE)/test-core-ir-ids.c $(CORE_IR_BUILD)/ids.native.bc -lbpf -o $(CORE_IR_BUILD)/ids.fixed
	$(CORE_IR_BUILD)/ids.fixed $(CORE_IR_BUILD)/ids.bpf.o $(KDIR)/vmlinux
	$(CC) -target bpf -O2 -g -I/usr/include/x86_64-linux-gnu -DUNGUARDED_MISSING -emit-llvm -c $(HERE)/test-core-ir.c -o $(CORE_IR_BUILD)/unguarded.bc
	$(CC) -target bpf -O2 -g -c $(CORE_IR_BUILD)/unguarded.bc -o $(CORE_IR_BUILD)/unguarded.bpf.o
	$(CORE_IR_BUILD)/core-ir-lower $(CORE_IR_BUILD)/unguarded.bc --local-bpf $(CORE_IR_BUILD)/unguarded.bpf.o --target-btf $(KDIR)/vmlinux --report $(CORE_IR_BUILD)/unguarded.json -o $(CORE_IR_BUILD)/unguarded.fixed.bc > $(CORE_IR_BUILD)/unguarded.log 2>&1 && status=0 || status=$$?; test $$status = 1
	$(CC) -target bpf -O2 -g -I/usr/include/x86_64-linux-gnu -DLOCAL_LAYOUT_SHIFT -c $(HERE)/test-core-ir.c -o $(CORE_IR_BUILD)/shifted.bpf.o
	$(CORE_IR_BUILD)/core-ir-lower $(CORE_IR_BUILD)/fixture.bc --local-bpf $(CORE_IR_BUILD)/shifted.bpf.o --target-btf $(KDIR)/vmlinux --report $(CORE_IR_BUILD)/shifted.json -o $(CORE_IR_BUILD)/shifted.fixed.bc > $(CORE_IR_BUILD)/shifted.log 2>&1 && status=0 || status=$$?; test $$status = 1
	$(CC) -target bpf -O2 -g -I/usr/include/x86_64-linux-gnu -DRESIZED_SCALAR -emit-llvm -c $(HERE)/test-core-ir.c -o $(CORE_IR_BUILD)/resized.bc
	$(CC) -target bpf -O2 -g -c $(CORE_IR_BUILD)/resized.bc -o $(CORE_IR_BUILD)/resized.bpf.o
	$(CORE_IR_BUILD)/core-ir-lower $(CORE_IR_BUILD)/resized.bc --local-bpf $(CORE_IR_BUILD)/resized.bpf.o --target-btf $(KDIR)/vmlinux --report $(CORE_IR_BUILD)/resized.json -o $(CORE_IR_BUILD)/resized.fixed.bc > $(CORE_IR_BUILD)/resized.log 2>&1 && status=0 || status=$$?; test $$status = 1

.PHONY: core-ir-retain
CORE_IR_RETAIN_ARGS ?=
core-ir-retain:
	python3 $(HERE)/core-ir-retain.py --build $(CORE_IR_BUILD) --raw $(CORE_IR_RAW) --tracee-ir $(CORE_IR_INPUT) --tracee-bpf $(CORE_IR_LOCAL_BPF) --target $(KDIR)/vmlinux --output $(CORE_IR_RECEIPT) $(CORE_IR_RETAIN_ARGS)

.PHONY: core-ir-width-check
core-ir-width-check: core-ir-tool $(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/public-layout.json $(SOCKET_BUILD)/physical-layout.json
	$(CC) -target bpf -O2 -g -emit-llvm -c $(HERE)/test-core-ir-width.c -o $(CORE_IR_BUILD)/width.bc
	$(CC) -target bpf -O2 -g -c $(CORE_IR_BUILD)/width.bc -o $(CORE_IR_BUILD)/width.bpf.o
	$(CORE_IR_BUILD)/core-ir-lower $(CORE_IR_BUILD)/width.bc --local-bpf $(CORE_IR_BUILD)/width.bpf.o --target-btf $(KDIR)/vmlinux --report $(CORE_IR_BUILD)/width.json -o $(CORE_IR_BUILD)/width.fixed.bc
	python3 $(HERE)/socket-helper-names.py > $(CORE_IR_BUILD)/helper-names.json
	$(SOCKET_BUILD)/socket-context-lower $(CORE_IR_BUILD)/width.fixed.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json --native-codegen --helper-names $(CORE_IR_BUILD)/helper-names.json -o $(CORE_IR_BUILD)/width.native.bc
	$(CC) -O2 -DTEST_DRIVER -I$(VMLINUX_DIR) -c $(HERE)/test-core-ir-width.c -o $(CORE_IR_BUILD)/width.driver.o
	$(CC) -target x86_64-linux-gnu -O2 $(CORE_IR_BUILD)/width.native.bc $(CORE_IR_BUILD)/width.driver.o -o $(CORE_IR_BUILD)/width.fixed
	$(CORE_IR_BUILD)/width.fixed
	$(CC) -target bpf -O2 -g -DWIDE_COMPARE -emit-llvm -c $(HERE)/test-core-ir-width.c -o $(CORE_IR_BUILD)/width-compare.bc
	$(CC) -target bpf -O2 -g -c $(CORE_IR_BUILD)/width-compare.bc -o $(CORE_IR_BUILD)/width-compare.bpf.o
	$(CORE_IR_BUILD)/core-ir-lower $(CORE_IR_BUILD)/width-compare.bc --local-bpf $(CORE_IR_BUILD)/width-compare.bpf.o --target-btf $(KDIR)/vmlinux --report $(CORE_IR_BUILD)/width-compare.json -o $(CORE_IR_BUILD)/width-compare.fixed.bc > $(CORE_IR_BUILD)/width-compare.log 2>&1 && status=0 || status=$$?; test $$status = 1

$(CORE_IR_BUILD)/width-bpf-reference: $(HERE)/test-core-width-bpf.c $(CORE_IR_BUILD)/libbpf/libbpf.a
	$(CC) -O2 -g -I$(ROOT)/vendor/libbpf/src -I$(ROOT)/vendor/libbpf/include -I$(ROOT)/vendor/libbpf/include/uapi $< $(CORE_IR_BUILD)/libbpf/libbpf.a -lelf -lz -o $@

.PHONY: core-ir-width-bpf-check
core-ir-width-bpf-check: $(CORE_IR_BUILD)/width-bpf-reference
	$(CORE_IR_BUILD)/width-bpf-reference $(CORE_IR_BUILD)/width.bpf.o $(KDIR)/vmlinux $(CORE_IR_BUILD)/width.patched.bpf.bin 0 > $(CORE_IR_BUILD)/width-bpf-reference.log 2>&1
	$(CORE_IR_BUILD)/width-bpf-reference $(CORE_IR_BUILD)/resized.bpf.o $(KDIR)/vmlinux $(CORE_IR_BUILD)/signed.patched.bpf.bin 1 > $(CORE_IR_BUILD)/signed-bpf-reference.log 2>&1

TETRAGON_SAME_BUILD ?= /var/tmp/kprog-tmp/perf/tetragon-same-source
TETRAGON_UNIT ?= bpf_generic_kprobe_v61
TETRAGON_SOURCE ?= $(ROOT)/vendor/repos/tetragon/bpf/process/bpf_generic_kprobe.c
.PHONY: upstream-tetragon-ir upstream-tetragon-native
upstream-tetragon-ir:
	prlimit --as=17179869184 -- python3 $(HERE)/tetragon-upstream.py --unit $(TETRAGON_UNIT) --source $(TETRAGON_SOURCE) --output $(TETRAGON_SAME_BUILD) --reference $(ROOT)/vendor/build/x86/tetragon/$(TETRAGON_UNIT).o

upstream-tetragon-native: upstream-tetragon-ir core-ir-tool $(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/public-layout.json $(SOCKET_BUILD)/physical-layout.json
	prlimit --as=17179869184 -- $(CORE_IR_BUILD)/core-ir-lower $(TETRAGON_SAME_BUILD)/$(TETRAGON_UNIT).bc --local-bpf $(TETRAGON_SAME_BUILD)/$(TETRAGON_UNIT).direct.bpf.o --target-btf $(KDIR)/vmlinux --report $(TETRAGON_SAME_BUILD)/$(TETRAGON_UNIT).core.json -o $(TETRAGON_SAME_BUILD)/$(TETRAGON_UNIT).core.bc
	$(ASM_BUILD)/bpf-asm-lower $(TETRAGON_SAME_BUILD)/$(TETRAGON_UNIT).core.bc -o $(TETRAGON_SAME_BUILD)/$(TETRAGON_UNIT).asm.bc
	python3 $(HERE)/socket-helper-names.py > $(TETRAGON_SAME_BUILD)/$(TETRAGON_UNIT).helper-names.json
	$(SOCKET_BUILD)/socket-context-lower $(TETRAGON_SAME_BUILD)/$(TETRAGON_UNIT).asm.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json --native-codegen --helper-names $(TETRAGON_SAME_BUILD)/$(TETRAGON_UNIT).helper-names.json -o $(TETRAGON_SAME_BUILD)/$(TETRAGON_UNIT).native.bc
	prlimit --as=17179869184 -- $(CC) -target x86_64-linux-gnu -O3 -g -fPIC -fno-optimize-sibling-calls -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-jump-tables -c $(TETRAGON_SAME_BUILD)/$(TETRAGON_UNIT).native.bc -o $(TETRAGON_SAME_BUILD)/$(TETRAGON_UNIT).native.o

.PHONY: cilium-helper-replay
cilium-helper-replay:
	python3 $(HERE)/socket-helper-names.py > $(CILIUM_HELPER_RAW)/helper-names.json
	python3 $(HERE)/cilium-helper-replay.py --capture $(CILIUM_HELPER_CAPTURE) --linker $(LINK_MEMORY_PAYLOAD)/native-link-off --helper-names $(CILIUM_HELPER_RAW)/helper-names.json --output $(CILIUM_HELPER_RAW)/replay

.PHONY: retain-host-artifacts
retain-host-artifacts:
	python3 $(HERE)/retain-host-artifacts.py --raw $(HOST_ARTIFACT_RAW) --output $(HOST_ARTIFACT_RECEIPT) --protocol $(HOST_ARTIFACT_PROTOCOL) $(HOST_ARTIFACT_ARGS)

.PHONY: split-host-artifacts
split-host-artifacts:
	python3 $(HERE)/split-retained-archive.py --receipt $(HOST_ARTIFACT_RECEIPT) --raw-archive $(HOST_ARTIFACT_RAW_ARCHIVE)

ASM_BUILD ?= /var/tmp/kprog-tmp/perf/bpf-asm
$(ASM_BUILD)/bpf-asm-lower: $(HERE)/bpf-asm-lower.cpp
	install -d $(ASM_BUILD)
	$(CXX) $$($(LLVM_CONFIG) --cxxflags) -std=c++17 -Wall -Wextra -Wno-unused-parameter $< -o $@ $$($(LLVM_CONFIG) --ldflags --libs core irreader bitwriter --system-libs)

upstream-tetragon-native: $(ASM_BUILD)/bpf-asm-lower

.PHONY: bpf-asm-check upstream-tetragon-link
bpf-asm-check: $(ASM_BUILD)/bpf-asm-lower $(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/public-layout.json $(SOCKET_BUILD)/physical-layout.json
	$(CC) -target bpf -O2 -g -emit-llvm -c $(HERE)/test-bpf-asm.c -o $(ASM_BUILD)/fixture.bc
	$(CC) -target bpf -O2 -g -c $(ASM_BUILD)/fixture.bc -o $(ASM_BUILD)/fixture.bpf.o
	llvm-objdump-18 -d $(ASM_BUILD)/fixture.bpf.o > $(ASM_BUILD)/fixture.bpf.dis
	$(ASM_BUILD)/bpf-asm-lower $(ASM_BUILD)/fixture.bc -o $(ASM_BUILD)/fixture.lowered.bc
	python3 $(HERE)/socket-helper-names.py > $(ASM_BUILD)/helper-names.json
	$(SOCKET_BUILD)/socket-context-lower $(ASM_BUILD)/fixture.lowered.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json --native-codegen --helper-names $(ASM_BUILD)/helper-names.json -o $(ASM_BUILD)/fixture.native.bc
	$(CC) -O2 -DTEST_DRIVER -c $(HERE)/test-bpf-asm.c -o $(ASM_BUILD)/driver.o
	$(CC) -target x86_64-linux-gnu -O2 $(ASM_BUILD)/fixture.native.bc $(ASM_BUILD)/driver.o -o $(ASM_BUILD)/fixture
	$(ASM_BUILD)/fixture
	$(CC) -target bpf -O2 -g -emit-llvm -c $(HERE)/test-bpf-compare.c -o $(ASM_BUILD)/compare.bc
	$(ASM_BUILD)/bpf-asm-lower $(ASM_BUILD)/compare.bc -o $(ASM_BUILD)/compare.lowered.bc
	$(SOCKET_BUILD)/socket-context-lower $(ASM_BUILD)/compare.lowered.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json --native-codegen --helper-names $(ASM_BUILD)/helper-names.json -o $(ASM_BUILD)/compare.native.bc
	$(CC) -O2 -DTEST_DRIVER -c $(HERE)/test-bpf-compare.c -o $(ASM_BUILD)/compare.driver.o
	$(CC) -target x86_64-linux-gnu -O2 $(ASM_BUILD)/compare.native.bc $(ASM_BUILD)/compare.driver.o -o $(ASM_BUILD)/compare
	$(ASM_BUILD)/compare
	$(CC) -target bpf -O2 -g -emit-llvm -c $(HERE)/test-bpf-errno-store.c -o $(ASM_BUILD)/errno-store.bc
	$(CC) -target bpf -O2 -g -c $(HERE)/test-bpf-errno-store.c -o $(ASM_BUILD)/errno-store.bpf.o
	llvm-objdump-18 -d $(ASM_BUILD)/errno-store.bpf.o > $(ASM_BUILD)/errno-store.bpf.dis
	$(ASM_BUILD)/bpf-asm-lower $(ASM_BUILD)/errno-store.bc -o $(ASM_BUILD)/errno-store.lowered.bc
	$(SOCKET_BUILD)/socket-context-lower $(ASM_BUILD)/errno-store.lowered.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json --native-codegen --helper-names $(ASM_BUILD)/helper-names.json -o $(ASM_BUILD)/errno-store.native.bc
	$(CC) -O2 -DTEST_DRIVER -c $(HERE)/test-bpf-errno-store.c -o $(ASM_BUILD)/errno-store.driver.o
	$(CC) -target x86_64-linux-gnu -O2 $(ASM_BUILD)/errno-store.native.bc $(ASM_BUILD)/errno-store.driver.o -o $(ASM_BUILD)/errno-store
	$(ASM_BUILD)/errno-store

TETRAGON_SECTION_ARGS ?= --section-prefix kprobe --section-prefix tracepoint --section-prefix raw_tracepoint --section-prefix uprobe --section-prefix fmod_ret/
TETRAGON_LINKER ?= $(LINK_MEMORY_PAYLOAD)/native-link-off
upstream-tetragon-link: upstream-tetragon-native
	python3 $(HERE)/socket-proof.py --input $(TETRAGON_SAME_BUILD)/$(TETRAGON_UNIT).native.o --linker $(TETRAGON_LINKER) --output $(TETRAGON_SAME_BUILD)/$(TETRAGON_UNIT)-links $(TETRAGON_SECTION_ARGS)

.PHONY: upstream-tetragon-batch
upstream-tetragon-batch: core-ir-tool $(ASM_BUILD)/bpf-asm-lower $(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/public-layout.json $(SOCKET_BUILD)/physical-layout.json
	prlimit --as=17179869184 -- python3 $(HERE)/tetragon-batch.py --manifest $(TETRAGON_BATCH_MANIFEST) --raw $(TETRAGON_BATCH_RAW) --build $(TETRAGON_BATCH_BUILD) --socket-build $(SOCKET_BUILD) $(TETRAGON_BATCH_ARGS)

.PHONY: upstream-tetragon-manifest
upstream-tetragon-manifest:
	python3 $(HERE)/tetragon-manifest.py --template $(TETRAGON_MANIFEST_TEMPLATE) --output $(TETRAGON_MANIFEST_OUTPUT) --receipt $(TETRAGON_MANIFEST_RECEIPT) $(TETRAGON_MANIFEST_BATCHES)

WEAK_BUILD ?= /var/tmp/kprog-tmp/perf/weak-ksym
.PHONY: weak-ksym-check
weak-ksym-check: $(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/public-layout.json $(SOCKET_BUILD)/physical-layout.json
	install -d $(WEAK_BUILD)
	$(CC) -target bpf -O2 -g -emit-llvm -c $(HERE)/test-weak-ksym.c -o $(WEAK_BUILD)/input.bc
	python3 $(HERE)/socket-helper-names.py > $(WEAK_BUILD)/helper-names.json
	$(SOCKET_BUILD)/socket-context-lower $(WEAK_BUILD)/input.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json --native-codegen --helper-names $(WEAK_BUILD)/helper-names.json -o $(WEAK_BUILD)/native.bc
	$(CC) -target x86_64-linux-gnu -O2 -fPIC -c $(WEAK_BUILD)/native.bc -o $(WEAK_BUILD)/native.o
	llvm-readelf-18 -r $(WEAK_BUILD)/native.o > $(WEAK_BUILD)/relocations.txt
	llvm-objdump-18 -d $(WEAK_BUILD)/native.o > $(WEAK_BUILD)/disassembly.txt
	$(CC) -O2 -fPIE -pie -DTEST_DRIVER $(HERE)/test-weak-ksym.c $(WEAK_BUILD)/native.o -o $(WEAK_BUILD)/absent
	$(WEAK_BUILD)/absent
	$(CC) -O2 -fPIE -pie -DTEST_DRIVER -DSYMBOL_PRESENT $(HERE)/test-weak-ksym.c $(WEAK_BUILD)/native.o -o $(WEAK_BUILD)/present
	$(WEAK_BUILD)/present

CONFIG_GLOBALS_BUILD ?= /var/tmp/kprog-tmp/perf/config-globals
.PHONY: config-globals-check
config-globals-check: $(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/public-layout.json $(SOCKET_BUILD)/physical-layout.json
	install -d $(CONFIG_GLOBALS_BUILD)
	$(CC) -target bpf -O2 -g -emit-llvm -c $(HERE)/test-config-globals.c -o $(CONFIG_GLOBALS_BUILD)/input.bc
	python3 $(HERE)/socket-helper-names.py > $(CONFIG_GLOBALS_BUILD)/helper-names.json
	$(SOCKET_BUILD)/socket-context-lower $(CONFIG_GLOBALS_BUILD)/input.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json --native-codegen --helper-names $(CONFIG_GLOBALS_BUILD)/helper-names.json -o $(CONFIG_GLOBALS_BUILD)/native.bc
	$(CC) -target x86_64-linux-gnu -O2 -fPIC -c $(CONFIG_GLOBALS_BUILD)/native.bc -o $(CONFIG_GLOBALS_BUILD)/native.o
	llvm-readelf-18 -r $(CONFIG_GLOBALS_BUILD)/native.o > $(CONFIG_GLOBALS_BUILD)/relocations.txt
	$(CC) -shared $(CONFIG_GLOBALS_BUILD)/native.o -o $(CONFIG_GLOBALS_BUILD)/libconfig-fixture.so
	$(CC) -O2 -DTEST_DRIVER $(HERE)/test-config-globals.c -L$(CONFIG_GLOBALS_BUILD) -lconfig-fixture -Wl,--export-dynamic -Wl,-rpath,$(CONFIG_GLOBALS_BUILD) -o $(CONFIG_GLOBALS_BUILD)/check
	$(CONFIG_GLOBALS_BUILD)/check

.PHONY: config-globals-roundtrip config-globals-default-check
config-globals-roundtrip:
	python3 $(HERE)/socket-proof.py --input $(CONFIG_GLOBALS_BUILD)/native.o --linker $(LINK_MEMORY_PAYLOAD)/native-link-off --output $(CONFIG_GLOBALS_BUILD)/links --section-prefix test/ --kernel-roundtrip

config-globals-default-check:
	install -m755 $(CONFIG_GLOBALS_REFERENCE_TOOL) $(CONFIG_GLOBALS_BUILD)/reference-socket-context-lower
	$(CONFIG_GLOBALS_BUILD)/reference-socket-context-lower $(CONFIG_GLOBALS_BUILD)/input.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json -o $(CONFIG_GLOBALS_BUILD)/default-before.bc
	$(SOCKET_BUILD)/socket-context-lower $(CONFIG_GLOBALS_BUILD)/input.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json -o $(CONFIG_GLOBALS_BUILD)/default-after.bc
	cmp $(CONFIG_GLOBALS_BUILD)/default-before.bc $(CONFIG_GLOBALS_BUILD)/default-after.bc

FROZEN_BUILD ?= /var/tmp/kprog-tmp/perf/frozen-data
$(FROZEN_BUILD)/frozen-data-lower: $(HERE)/frozen-data-lower.cpp
	install -d $(FROZEN_BUILD)
	$(CXX) $$($(LLVM_CONFIG) --cxxflags) -std=c++17 -Wall -Wextra -Wno-unused-parameter $< -o $@ $$($(LLVM_CONFIG) --ldflags --libs core irreader bitwriter analysis --system-libs)

.PHONY: frozen-data-ir frozen-data-check
frozen-data-ir: $(FROZEN_BUILD)/frozen-data-lower
	$(FROZEN_BUILD)/frozen-data-lower $(FROZEN_INPUT) --constants $(FROZEN_CONSTANTS) --report $(FROZEN_REPORT) -o $(FROZEN_OUTPUT)

frozen-data-check: $(FROZEN_BUILD)/frozen-data-lower $(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/public-layout.json $(SOCKET_BUILD)/physical-layout.json
	$(CC) -target bpf -O2 -g -emit-llvm -c $(HERE)/test-config-globals.c -o $(FROZEN_BUILD)/fixture.bc
	$(FROZEN_BUILD)/frozen-data-lower $(FROZEN_BUILD)/fixture.bc --constants $(HERE)/test-frozen-data.json --report $(FROZEN_BUILD)/fixture.json -o $(FROZEN_BUILD)/fixture.frozen.bc
	python3 $(HERE)/socket-helper-names.py > $(FROZEN_BUILD)/helper-names.json
	$(SOCKET_BUILD)/socket-context-lower $(FROZEN_BUILD)/fixture.frozen.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json --native-codegen --helper-names $(FROZEN_BUILD)/helper-names.json -o $(FROZEN_BUILD)/fixture.native.bc
	$(CC) -target x86_64-linux-gnu -O3 -fPIC -c $(FROZEN_BUILD)/fixture.native.bc -o $(FROZEN_BUILD)/fixture.native.o
	$(CC) -shared $(FROZEN_BUILD)/fixture.native.o -o $(FROZEN_BUILD)/libfrozen-fixture.so
	$(CC) -O2 $(HERE)/test-frozen-data-driver.c -L$(FROZEN_BUILD) -lfrozen-fixture -Wl,--export-dynamic -Wl,-rpath,$(FROZEN_BUILD) -o $(FROZEN_BUILD)/check
	$(FROZEN_BUILD)/check
	$(FROZEN_BUILD)/frozen-data-lower $(FROZEN_BUILD)/fixture.bc --constants $(HERE)/test-frozen-data-mutable.json --report $(FROZEN_BUILD)/mutable.json -o $(FROZEN_BUILD)/mutable.bc > $(FROZEN_BUILD)/mutable.log 2>&1 && result=0 || result=$$?; test $$result = 1
	$(FROZEN_BUILD)/frozen-data-lower $(FROZEN_BUILD)/fixture.bc --constants $(HERE)/test-frozen-data-short.json --report $(FROZEN_BUILD)/short.json -o $(FROZEN_BUILD)/short.bc > $(FROZEN_BUILD)/short.log 2>&1 && result=0 || result=$$?; test $$result = 1

.PHONY: frozen-cilium-native
frozen-cilium-native: frozen-data-ir $(SOCKET_BUILD)/socket-context-lower $(PACKET_BUILD)/public-layout $(PACKET_BUILD)/physical-layout
	$(PACKET_BUILD)/public-layout > $(PACKET_BUILD)/public-layout.json
	$(PACKET_BUILD)/physical-layout > $(PACKET_BUILD)/physical-layout.json
	python3 $(HERE)/socket-helper-names.py > $(PACKET_BUILD)/helper-names.json
	$(SOCKET_BUILD)/socket-context-lower $(FROZEN_OUTPUT) --public-layout $(PACKET_BUILD)/public-layout.json --physical-layout $(PACKET_BUILD)/physical-layout.json --native-codegen --helper-names $(PACKET_BUILD)/helper-names.json -o $(FROZEN_BUILD)/$(CILIUM_UNIT).native.bc
	prlimit --as=8589934592 -- $(CC) -target x86_64-linux-gnu -O3 -g -fPIC -fno-optimize-sibling-calls -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-jump-tables -c $(FROZEN_BUILD)/$(CILIUM_UNIT).native.bc -o $(FROZEN_BUILD)/$(CILIUM_UNIT).native.o

OTEL_UPSTREAM_BUILD ?= /var/tmp/kprog-tmp/perf/otel-upstream
OTEL_UNIT ?= native_stack_trace
.PHONY: upstream-otel-ir
upstream-otel-ir:
	prlimit --as=17179869184 -- python3 $(HERE)/otel-upstream.py --unit $(OTEL_UNIT) --output $(OTEL_UPSTREAM_BUILD)

.PHONY: upstream-otel-bpf
upstream-otel-bpf:
	prlimit --as=17179869184 -- python3 $(HERE)/otel-upstream.py --all --output $(OTEL_UPSTREAM_BUILD) --bpf-reference $(ROOT)/vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64

OTEL_NATIVE_BUILD ?= /var/tmp/kprog-tmp/perf/otel-original-native
.PHONY: upstream-otel-native
upstream-otel-native: all $(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/public-layout.json $(SOCKET_BUILD)/physical-layout.json
	install -d $(OTEL_NATIVE_BUILD)
	python3 $(HERE)/socket-helper-names.py > $(OTEL_NATIVE_BUILD)/helper-names.json
	prlimit --as=17179869184 -- python3 $(HERE)/otel-native.py --original $(OTEL_UPSTREAM_BUILD)/tracer.linked.bc --output $(OTEL_NATIVE_BUILD) --retarget $(SOCKET_BUILD)/socket-context-lower --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json --perf-context $(BUILD)/perf-context-lower --perf-layout $(BUILD)/layout.json

.PHONY: upstream-otel-link
upstream-otel-link: upstream-otel-native
	prlimit --as=17179869184 -- python3 $(HERE)/socket-proof.py --input $(OTEL_NATIVE_BUILD)/tracer.native.o --linker $(LINK_MEMORY_PAYLOAD)/native-link-off --output $(OTEL_NATIVE_BUILD)/links --section-prefix perf_event/ --section-prefix kprobe/ --section-prefix uprobe/ --section-prefix tracepoint/ --section-prefix raw_tracepoint/ --kernel-roundtrip

OTEL_UPSTREAM_PAYLOAD ?= $(ROOT)/corpus/results/perf-otel-upstream-20261114
.PHONY: upstream-otel-candidate
upstream-otel-candidate:
	install -d $(OTEL_UPSTREAM_PAYLOAD)
	install -m644 $(OTEL_NATIVE_BUILD)/tracer.native.o $(OTEL_UPSTREAM_PAYLOAD)/otelcol-ebpf-profiler.native.o
	install -m644 $(OTEL_UPSTREAM_BUILD)/tracer.bpf.o $(OTEL_UPSTREAM_PAYLOAD)/tracer.original.bpf.o
	python3 $(ROOT)/vendor/bpf/write_native_manifest.py --app otelcol-ebpf-profiler --llvm-nm llvm-nm-18 --output $(OTEL_UPSTREAM_PAYLOAD)/manifest.json --object $(OTEL_UPSTREAM_PAYLOAD)/otelcol-ebpf-profiler.native.o
	python3 $(HERE)/manifest-context.py --input $(OTEL_UPSTREAM_PAYLOAD)/manifest.json --output $(OTEL_UPSTREAM_PAYLOAD)/manifest-context.json --kernel-data-layout

NATIVE_FRAME_BUILD ?= /var/tmp/kprog-tmp/perf/native-frame
NATIVE_FRAME_REFERENCE_TOOL ?= /workspaces/kprog-raw/perf/20261114-otel-original-native/input-evidence/socket-context-lower
.PHONY: native-frame-check
native-frame-check: $(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/public-layout.json $(SOCKET_BUILD)/physical-layout.json
	install -d $(NATIVE_FRAME_BUILD)
	install -m755 $(NATIVE_FRAME_REFERENCE_TOOL) $(NATIVE_FRAME_BUILD)/reference-lower
	$(CC) -target bpf -O2 -g -fno-omit-frame-pointer -emit-llvm -c $(HERE)/test-native-frame.c -o $(NATIVE_FRAME_BUILD)/input.bc
	python3 $(HERE)/socket-helper-names.py > $(NATIVE_FRAME_BUILD)/helper-names.json
	$(CC) -O2 -DTEST_DRIVER -c $(HERE)/test-native-frame.c -o $(NATIVE_FRAME_BUILD)/driver.o
	for variant in before after; do \
		tool=$(NATIVE_FRAME_BUILD)/reference-lower; if [[ $$variant = after ]]; then tool=$(SOCKET_BUILD)/socket-context-lower; fi; \
		$$tool $(NATIVE_FRAME_BUILD)/input.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json -o $(NATIVE_FRAME_BUILD)/default-$$variant.bc; \
		$$tool $(NATIVE_FRAME_BUILD)/input.bc --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json --native-codegen --helper-names $(NATIVE_FRAME_BUILD)/helper-names.json -o $(NATIVE_FRAME_BUILD)/$$variant.bc; \
		$(CC) -target x86_64-linux-gnu -O3 -fPIC -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-jump-tables -c $(NATIVE_FRAME_BUILD)/$$variant.bc -o $(NATIVE_FRAME_BUILD)/$$variant.o; \
		$(CC) $(NATIVE_FRAME_BUILD)/$$variant.o $(NATIVE_FRAME_BUILD)/driver.o -o $(NATIVE_FRAME_BUILD)/$$variant; \
		$(NATIVE_FRAME_BUILD)/$$variant; \
		python3 $(HERE)/socket-proof.py --input $(NATIVE_FRAME_BUILD)/$$variant.o --linker $(LINK_MEMORY_PAYLOAD)/native-link-off --output $(NATIVE_FRAME_BUILD)/$$variant-links --section-prefix frame-test --kernel-roundtrip; \
	done
	python3 $(HERE)/check-native-frame.py --build $(NATIVE_FRAME_BUILD)

BPF_FUNCTION_BUILD ?= /var/tmp/kprog-tmp/perf/bpf-functions
BPF_FUNCTION_REFERENCE ?= /workspaces/kprog-raw/perf/20261114-native-frame/input-evidence/socket-context-lower
.PHONY: bpf-function-check
bpf-function-check: $(SOCKET_BUILD)/socket-context-lower $(SOCKET_BUILD)/public-layout.json $(SOCKET_BUILD)/physical-layout.json
	install -d $(BPF_FUNCTION_BUILD)
	install -m755 $(BPF_FUNCTION_REFERENCE) $(BPF_FUNCTION_BUILD)/reference-lower
	$(CC) -O2 -g -emit-llvm -c $(HERE)/test-bpf-function.c -o $(BPF_FUNCTION_BUILD)/input.bc
	python3 $(HERE)/socket-helper-names.py > $(BPF_FUNCTION_BUILD)/helpers.json
	python3 $(HERE)/test-bpf-functions.py --build $(BPF_FUNCTION_BUILD) --compiler $(SOCKET_BUILD)/socket-context-lower --reference $(BPF_FUNCTION_BUILD)/reference-lower --public-layout $(SOCKET_BUILD)/public-layout.json --physical-layout $(SOCKET_BUILD)/physical-layout.json
