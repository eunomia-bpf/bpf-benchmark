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
CONTEXT_BUILD ?= /var/tmp/kprog-tmp/perf/context-loads-v2
IDENTITY_ARGS ?=
HELPER_SHAPE_BUILD ?= /var/tmp/kprog-tmp/perf/helper-shapes
SPILL_GROUP_BUILD ?= /var/tmp/kprog-tmp/perf/spill-groups
HELPER_MEMORY_BUILD ?= /var/tmp/kprog-tmp/perf/helper-memory

.PHONY: spill-liveness-check
spill-liveness-check:
	taskset -c 18-19 python3 $(ROOT)/kprog/test/check_spill_lifetimes.py

.PHONY: helper-memory-build helper-memory-run helper-memory-guest
helper-memory-build:
	install -d $(HELPER_MEMORY_BUILD) $(OUTPUT)
	$(CC) -O2 -g -Wall -Wextra -Werror -I$(LIBBPF)/prefix/include $(ROOT)/kprog/test/scalar_spill_values.c $(LIBBPF)/pic-obj/libbpf.a -lelf -lz -o $(HELPER_MEMORY_BUILD)/values-client
	taskset -c 18-19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_b_helper_memory.py --tool $(CONTEXT_BUILD)/packet-bounds --build $(HELPER_MEMORY_BUILD) --output $(OUTPUT)

helper-memory-run:
	install -d $(OUTPUT)
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	taskset -c 16-17 prlimit --as=8589934592 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir /var/tmp=$(HELPER_MEMORY_BUILD) --rwdir $(OUTPUT) --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(ROOT)/kprog/test/scalar-spill-precision.mk helper-memory-guest HELPER_MEMORY_BUILD=/var/tmp OUTPUT=$(OUTPUT)'

helper-memory-guest:
	$(HELPER_MEMORY_BUILD)/values-client $(HELPER_MEMORY_BUILD)/original.o $(HELPER_MEMORY_BUILD)/normalized.o > $(OUTPUT)/kernel.jsonl 2> $(OUTPUT)/verifier.log

.PHONY: hotspot-spill-replay
hotspot-spill-replay:
	taskset -c 19 prlimit --as=25769803776 -- python3 $(ROOT)/kprog/test/replay_hotspot_spills.py --archive /workspaces/kprog-raw/perf/20261114-otel-whole-word-checked/service.tar.gz --member service/requests/5.failure.tar.gz --build /var/tmp/kprog-tmp/perf/otel-whole-word-checked --output $(OUTPUT)

.PHONY: otel-main-spill-replay
otel-main-spill-replay:
	taskset -c 8-11 prlimit --as=17179869184 -- python3 $(ROOT)/kprog/test/replay_hotspot_spills.py --archive /workspaces/kprog-raw/perf/20261115-otel-current-app-retry2/service.tar.gz --member service/requests/3.failure.tar.gz --build /var/tmp/kprog-tmp/perf/otel-main-spill-replay --output $(OUTPUT)

.PHONY: otel-main-backend-choices
otel-main-backend-choices:
	taskset -c 8-11 prlimit --as=17179869184 -- python3 $(ROOT)/kprog/test/measure_b_backend_choices.py --archive /workspaces/kprog-raw/perf/20261115-otel-current-app-retry2/service.tar.gz --member service/requests/3.failure.tar.gz --output $(OUTPUT) $(BACKEND_CHOICE_ARGS)

.PHONY: hotspot-spill-lifetimes
hotspot-spill-lifetimes:
	install -d $(OUTPUT)
	taskset -c 8 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/analyze_spill_lifetimes.py /var/tmp/kprog-tmp/perf/otel-whole-word-checked/trusted_x86.bpf.before.mir $(OUTPUT)/lifetimes.json

.PHONY: spill-groups-main
spill-groups-main:
	taskset -c 19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/replay_spill_groups_mir.py --archive /workspaces/kprog-raw/perf/20261114-otel-whole-word-checked/state/session-d1wppo7h/requests/3.success.tar.gz --build $(SPILL_GROUP_BUILD) --output $(OUTPUT)

.PHONY: spill-groups-build spill-groups-run spill-groups-guest
spill-groups-build:
	install -d $(SPILL_GROUP_BUILD)
	$(CC) -O2 -g -Wall -Wextra -Werror -I$(LIBBPF)/prefix/include $(ROOT)/kprog/test/scalar_spill_values.c $(LIBBPF)/pic-obj/libbpf.a -lelf -lz -o $(SPILL_GROUP_BUILD)/values-client
	taskset -c 19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_spill_groups.py --build $(SPILL_GROUP_BUILD) --output $(OUTPUT) --compile-only

spill-groups-run:
	install -d $(OUTPUT)
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	taskset -c 16-17 prlimit --as=8589934592 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir /var/tmp=$(SPILL_GROUP_BUILD) --rwdir $(OUTPUT) --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -f $(ROOT)/kprog/test/scalar-spill-precision.mk spill-groups-guest SPILL_GROUP_BUILD=/var/tmp OUTPUT=$(OUTPUT)'

spill-groups-guest:
	python3 $(ROOT)/kprog/test/check_spill_groups.py --build $(SPILL_GROUP_BUILD) --output $(OUTPUT)

.PHONY: tracee-probe-sites
tracee-probe-sites:
	taskset -c 19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/results/perf_20261113/tracee_probe_sites.py --capture /workspaces/kprog-raw/C/limits/tracee --output $(OUTPUT) --perf /var/tmp/kprog-tmp/C/perf-build/perf --baseline-id 25 --native-id 217

HELPER_SHAPE_LINKER ?= $(ROOT)/kprog/x86/native_lab/native_link/target/release/native-link
.PHONY: helper-shapes
helper-shapes:
	$(MAKE) -f $(ROOT)/kprog/test/native-relocations.mk kernel-layout
	taskset -c 19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_helper_call_shapes.py --linker $(HELPER_SHAPE_LINKER) --kernel-layout /var/tmp/kprog-tmp/perf/kernel-layout/kernel-layout.json --build $(HELPER_SHAPE_BUILD) --output $(OUTPUT)

.PHONY: build run analyze codegen whole-word replay values-build values-run backend-check checked-corpus context-build context-run context-replay identity-check
identity-check:
	install -d $(OUTPUT) $(CONTEXT_BUILD)
	taskset -c 18-19 clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -I$(ROOT)/vendor/libbpf/include/uapi $(ROOT)/kprog/x86/packet_bounds_ir.cpp -o $(CONTEXT_BUILD)/packet-bounds $$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)
	taskset -c 18-19 python3 $(ROOT)/kprog/test/check_packet_identities.py --tool $(CONTEXT_BUILD)/packet-bounds --output $(OUTPUT) $(IDENTITY_ARGS)
	taskset -c 18-19 python3 $(ROOT)/kprog/test/check_private_stack_ir.py --tool $(CONTEXT_BUILD)/packet-bounds --build $(CONTEXT_BUILD)/private-stack --output $(OUTPUT)/private-stack

context-replay:
	install -d $(OUTPUT) $(CONTEXT_BUILD)
	taskset -c 19 prlimit --as=25769803776 -- python3 $(ROOT)/kprog/test/replay_context_compiler.py --archive $(CONTEXT_ARCHIVE) --build $(CONTEXT_BUILD) --output $(OUTPUT) --tool $(CONTEXT_TOOL)

context-build:
	install -d $(OUTPUT) $(CONTEXT_BUILD)
	taskset -c 18-19 clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -I$(ROOT)/vendor/libbpf/include/uapi $(ROOT)/kprog/x86/packet_bounds_ir.cpp -o $(CONTEXT_BUILD)/packet-bounds $$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)
	taskset -c 18-19 python3 $(ROOT)/kprog/test/check_context_loads.py --tool $(CONTEXT_BUILD)/packet-bounds --build $(CONTEXT_BUILD)/cases --output $(OUTPUT)
	$(CC) -O2 -g -Wall -Wextra -Werror -I$(LIBBPF)/prefix/include $(ROOT)/kprog/test/context_load_client.c $(LIBBPF)/pic-obj/libbpf.a -lelf -lz -o $(CONTEXT_BUILD)/context-client

context-run:
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	taskset -c 22-23 vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(CONTEXT_BUILD) --rwdir $(OUTPUT) --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec '$(CONTEXT_BUILD)/context-client $(CONTEXT_BUILD)/cases/reference.o $(CONTEXT_BUILD)/cases/canonical.o'

CHECKED_APP ?= otelcol-ebpf-profiler/profiling
CHECKED_LOADER ?= /workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader
CHECKED_APPS ?= otelcol-ebpf-profiler/profiling bcc/set cilium/agent tetragon/observer tracee/monitor katran
CHECKED_HOST_CPUS ?= 16-17
CHECKED_VM_MEMORY ?= 48G
CHECKED_VM_ADDRESS_SPACE ?= 85899345920
checked-corpus:
	install -d $(OUTPUT) $(OUTPUT)/loader-inputs $(REPLAY_BUILD)
	date -u +%FT%TZ > $(OUTPUT)/started
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	status=0; taskset -c $(CHECKED_HOST_CPUS) prlimit --as=$(CHECKED_VM_ADDRESS_SPACE) -- vng --run $(KDIR)/arch/x86/boot/bzImage \
		--cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rwdir /var/tmp=$(REPLAY_BUILD) --rodir $(OUTPUT)/loader-inputs=$(dir $(CHECKED_LOADER)) \
		--overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local \
		--disable-monitor --verbose --cpus 2 --memory $(CHECKED_VM_MEMORY) --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'bash $(ROOT)/kprog/test/run_checked_otel.sh $(OUTPUT) $(CHECKED_APP) $(OUTPUT)/loader-inputs/$(notdir $(CHECKED_LOADER))' || status=$$?; \
	printf '%s\n' "$$status" > $(OUTPUT)/exit-code; date -u +%FT%TZ > $(OUTPUT)/finished; \
	if test -f $(REPLAY_BUILD)/bpf-benchmark-docker.img; then stat --printf='%s bytes %n\n' $(REPLAY_BUILD)/bpf-benchmark-docker.img >> $(OUTPUT)/removed-build-copies.txt; rm -f $(REPLAY_BUILD)/bpf-benchmark-docker.img; printf -- '- %s PERF checked-corpus: removed completed guest Docker disk build in %s; raw service/run evidence kept at %s.\n' "$$(date -u +%FT%TZ)" '$(REPLAY_BUILD)' '$(OUTPUT)' >> $(ROOT)/kprog/docs/cleanup-log.md; fi; exit $$status

.PHONY: checked-corpus-all
checked-corpus-all: CHECKED_HOST_CPUS = 8-15
checked-corpus-all:
	install -d $(OUTPUT)
	failed=0; for app in $(CHECKED_APPS); do \
		date -u +%FT%TZ >> $(OUTPUT)/progress.log; \
		$(MAKE) -r -f $(ROOT)/kprog/test/scalar-spill-precision.mk checked-corpus \
			OUTPUT=$(OUTPUT)/$${app%%/*} CHECKED_APP=$$app \
			CHECKED_HOST_CPUS=$(CHECKED_HOST_CPUS) CHECKED_LOADER=$(CHECKED_LOADER) \
			> $(OUTPUT)/$${app%%/*}.log 2>&1 && rc=0 || rc=$$?; \
		printf '%s\t%s\n' "$$app" "$$rc" >> $(OUTPUT)/run-codes.tsv; \
		if test $$rc -ne 0; then failed=1; fi; \
	done; exit $$failed

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
