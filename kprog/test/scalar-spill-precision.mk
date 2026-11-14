SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
OUTPUT ?= /workspaces/kprog-raw/perf/20261114-scalar-spill-precision
KDIR := /workspaces/.agent-state/kprog-ck/build-x86
LIBBPF := $(ROOT)/runner/build-llvmbpf/vendor/libbpf
OPTIMIZATION ?= O3
CODEGEN_ARGS ?=
REPLAY_ARGS ?=
REPLAY_BUILD ?= /var/tmp/kprog-tmp/perf/retained-proof-replay
BACKEND_ARGS ?=
CONTEXT_BUILD ?= /var/tmp/kprog-tmp/perf/context-loads
IDENTITY_ARGS ?=
HELPER_SHAPE_BUILD ?= /var/tmp/kprog-tmp/perf/helper-shapes
SPILL_GROUP_BUILD ?= /var/tmp/kprog-tmp/perf/spill-groups

.PHONY: spill-groups-build spill-groups-run spill-groups-guest
spill-groups-build:
	install -d $(SPILL_GROUP_BUILD)
	$(CC) -O2 -g -Wall -Wextra -Werror -I$(LIBBPF)/prefix/include $(ROOT)/kprog/test/scalar_spill_values.c $(LIBBPF)/pic-obj/libbpf.a -lelf -lz -o $(SPILL_GROUP_BUILD)/values-client
	taskset -c 19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_spill_groups.py --build $(SPILL_GROUP_BUILD) --output $(OUTPUT) --compile-only

spill-groups-run:
	install -d $(OUTPUT)
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	taskset -c 22-23 prlimit --as=8589934592 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir /var/tmp=$(SPILL_GROUP_BUILD) --rwdir $(OUTPUT) --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(ROOT)/kprog/test/scalar-spill-precision.mk spill-groups-guest SPILL_GROUP_BUILD=/var/tmp OUTPUT=$(OUTPUT)'

spill-groups-guest:
	python3 $(ROOT)/kprog/test/check_spill_groups.py --build $(SPILL_GROUP_BUILD) --output $(OUTPUT)

.PHONY: tracee-probe-sites
tracee-probe-sites:
	taskset -c 19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/results/perf_20261113/tracee_probe_sites.py --capture /workspaces/kprog-raw/C/limits/tracee --output $(OUTPUT) --perf /var/tmp/kprog-tmp/C/perf-build/perf --baseline-id 25 --native-id 217

.PHONY: helper-shapes
helper-shapes:
	taskset -c 19 python3 $(ROOT)/kprog/test/check_helper_call_shapes.py --linker $(ROOT)/corpus/results/perf-corrected-all-lto-linker-20261114/native-link.real --layouts $(ROOT)/corpus/results/perf-corrected-all-lto-linker-20261114 --build $(HELPER_SHAPE_BUILD) --output $(OUTPUT)

.PHONY: build run analyze codegen whole-word replay values-build values-run backend-check checked-corpus context-build context-run context-replay identity-check
identity-check:
	install -d $(OUTPUT) $(CONTEXT_BUILD)
	taskset -c 18-19 clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -I$(ROOT)/vendor/libbpf/include/uapi $(ROOT)/kprog/x86/packet_bounds_ir.cpp -o $(CONTEXT_BUILD)/packet-bounds $$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)
	taskset -c 18-19 python3 $(ROOT)/kprog/test/check_packet_identities.py --tool $(CONTEXT_BUILD)/packet-bounds --legacy /workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds --output $(OUTPUT) $(IDENTITY_ARGS)

context-replay:
	install -d $(OUTPUT) $(CONTEXT_BUILD)
	taskset -c 19 prlimit --as=25769803776 -- python3 $(ROOT)/kprog/test/replay_context_compiler.py --archive $(CONTEXT_ARCHIVE) --build $(CONTEXT_BUILD) --output $(OUTPUT) --tool $(CONTEXT_TOOL)

context-build:
	install -d $(OUTPUT) $(CONTEXT_BUILD)
	taskset -c 18-19 clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -I$(ROOT)/vendor/libbpf/include/uapi $(ROOT)/kprog/x86/packet_bounds_ir.cpp -o $(CONTEXT_BUILD)/packet-bounds $$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)
	taskset -c 18-19 python3 $(ROOT)/kprog/test/check_context_loads.py --tool $(CONTEXT_BUILD)/packet-bounds --legacy /workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds --output $(OUTPUT)
	$(CC) -O2 -g -Wall -Wextra -Werror -I$(LIBBPF)/prefix/include $(ROOT)/kprog/test/context_load_client.c $(LIBBPF)/pic-obj/libbpf.a -lelf -lz -o $(OUTPUT)/context-client

context-run:
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	taskset -c 22-23 vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(OUTPUT) --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec '$(OUTPUT)/context-client $(OUTPUT)/off.o $(OUTPUT)/on.o'

checked-corpus:
	install -d $(OUTPUT) $(REPLAY_BUILD)
	date -u +%FT%TZ > $(OUTPUT)/started
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	status=0; taskset -c 16-17 prlimit --as=85899345920 -- vng --run $(KDIR)/arch/x86/boot/bzImage \
		--cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rwdir /var/tmp=$(REPLAY_BUILD) \
		--overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local \
		--disable-monitor --verbose --cpus 2 --memory 48G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'bash $(ROOT)/kprog/test/run_checked_otel.sh $(OUTPUT)' || status=$$?; \
	printf '%s\n' "$$status" > $(OUTPUT)/exit-code; date -u +%FT%TZ > $(OUTPUT)/finished; exit $$status

backend-check:
	taskset -c 18-19 python3 $(ROOT)/kprog/test/check_whole_word_backend.py --output $(OUTPUT) --clang $(ROOT)/kprog/stock-path/bin/clang $(BACKEND_ARGS)

values-build:
	install -d $(OUTPUT)
	$(CC) -O2 -g -Wall -Wextra -Werror -I$(LIBBPF)/prefix/include $(ROOT)/kprog/test/scalar_spill_values.c $(LIBBPF)/pic-obj/libbpf.a -lelf -lz -o $(OUTPUT)/values-client
	llc-18 -O3 -march=bpf -mcpu=v4 -verify-machineinstrs -start-before=prologepilog -filetype=obj $(ROOT)/kprog/test/scalar_spill_values.mir -o $(OUTPUT)/original.o
	python3 $(ROOT)/kprog/x86/whole_word_spills.py $(ROOT)/kprog/test/scalar_spill_values.mir $(OUTPUT)/lowered.mir
	llc-18 -O3 -march=bpf -mcpu=v4 -verify-machineinstrs -start-before=prologepilog -filetype=obj $(OUTPUT)/lowered.mir -o $(OUTPUT)/lowered.o

values-run: values-build
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	taskset -c 22-23 vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(OUTPUT) --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec '$(OUTPUT)/values-client $(OUTPUT)/original.o $(OUTPUT)/lowered.o'

replay:
	install -d $(OUTPUT) $(REPLAY_BUILD)
	printf '%s\n' --native '$(NATIVE)' --metadata '$(METADATA)' --context '$(CONTEXT)' --source '$(SOURCE)' --proof '$(PROOF)' --symbol '$(SYMBOL)' --linker '$(LINKER)' --output '$(OUTPUT)' $(REPLAY_ARGS) > $(OUTPUT)/arguments
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	taskset -c 22-23 vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rwdir /var/tmp=$(REPLAY_BUILD) --overlay-rwdir /tmp --disable-monitor --verbose --cpus 1 --memory 8G --append 'loglevel=4 panic=30 oops=panic' --exec 'mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug; mount -t bpf bpffs /sys/fs/bpf; insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko; CLANG=$(ROOT)/kprog/stock-path/bin/clang python3 $(ROOT)/kprog/test/verify_retained_proof.py @$(OUTPUT)/arguments'

whole-word:
	install -d $(OUTPUT)
	taskset -c 18-19 python3 $(ROOT)/kprog/x86/whole_word_spills.py $(MIR) $(OUTPUT)/whole.mir --low $(LOW) --high $(HIGH)
	taskset -c 18-19 llc-18 -O3 -march=bpf -mcpu=v4 -bpf-stack-size=4096 -verify-machineinstrs -start-before=prologepilog -stop-after=prologepilog $(OUTPUT)/whole.mir -o $(OUTPUT)/after.mir
	taskset -c 18-19 llc-18 -O3 -march=bpf -mcpu=v4 -bpf-stack-size=4096 -verify-machineinstrs -start-before=prologepilog -filetype=obj $(OUTPUT)/whole.mir -o $(OUTPUT)/whole.o

codegen:
	taskset -c 18-19 python3 $(ROOT)/kprog/test/spill_codegen_probe.py $(BITCODE) $(OUTPUT) --optimization $(OPTIMIZATION) $(CODEGEN_ARGS)

analyze:
	taskset -c 18-19 python3 $(ROOT)/kprog/test/analyze_spill_lifetimes.py $(MIR) $(REPORT)

build:
	install -d $(OUTPUT)
	$(CC) -O2 -g -Wall -Wextra -Werror -I$(LIBBPF)/prefix/include $(ROOT)/kprog/test/scalar_spill_precision.c $(LIBBPF)/pic-obj/libbpf.a -lelf -lz -o $(OUTPUT)/client

run: build
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	taskset -c 22-23 vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(OUTPUT) --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec '$(OUTPUT)/client $(OUTPUT)'
