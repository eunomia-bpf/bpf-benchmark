SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
# External kernel artifacts are inputs; never apply Make's implicit link rules.
MAKEFLAGS += --no-builtin-rules
ROOT := /workspaces/repository
LINKER_TARGET := $(ROOT)/kprog/x86/native_lab/native_link/target
LINKER_BINARY ?= $(LINKER_TARGET)/release/native-link
OUTPUT ?= /workspaces/kprog-raw/perf/20261115-native-relocations
BUILD := /var/tmp/kprog-tmp/perf/native-relocations
TABLE_CONTEXT_BUILD := /var/tmp/kprog-tmp/perf/table-context
MAP_LOOKUP_BUILD := /var/tmp/kprog-tmp/perf/map-table-lookup
CONTEXT_TOOL := /var/tmp/kprog-tmp/perf/context-loads-v2/packet-bounds
CHECKED_TOOL := /var/tmp/kprog-tmp/perf/checked-compiler/compile-sim-ir
CHECKED_PACKET_BUILD := /var/tmp/kprog-tmp/perf/checked-packet
KERNEL_LAYOUT_BUILD := /var/tmp/kprog-tmp/perf/kernel-layout
KERNEL_LAYOUT := $(KERNEL_LAYOUT_BUILD)/kernel-layout.json
KDIR := /workspaces/.agent-state/kprog-ck/build-x86
BOOT_CAPTURE ?= /workspaces/kprog-raw/perf/20261115-normal-layout-plan/boot-ready
LIBBPF_PREFIX := $(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix
LIBBPF_LIBRARY := $(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a

$(KERNEL_LAYOUT_BUILD)/facts: $(ROOT)/kprog/test/kernel_lto_layout.cpp $(ROOT)/kprog/libnativeloader/src/native_loader_lto.hpp
	install -d $(KERNEL_LAYOUT_BUILD)
	taskset -c 8-11 prlimit --as=8589934592 -- clang++-18 -std=c++20 -O2 -Wall -Wextra -Werror -I$(LIBBPF_PREFIX)/include $< $(LIBBPF_LIBRARY) -lelf -lz -o $@

$(KERNEL_LAYOUT): $(KERNEL_LAYOUT_BUILD)/facts $(KDIR)/vmlinux $(BOOT_CAPTURE)/kernel.kallsyms
	taskset -c 8-11 prlimit --as=8589934592 -- $(KERNEL_LAYOUT_BUILD)/facts $(KDIR)/vmlinux $(BOOT_CAPTURE)/kernel.kallsyms > $@

$(KERNEL_LAYOUT_BUILD)/runtime-array-layout: $(ROOT)/kprog/build/runtime-array-layout.c
	$(MAKE) -r -f $(ROOT)/kprog/build/Makefile $@ BUILD=$(KERNEL_LAYOUT_BUILD)

.PHONY: kernel-layout kernel-layout-check loader-syntax
kernel-layout: $(KERNEL_LAYOUT)

kernel-layout-check: $(KERNEL_LAYOUT) $(KERNEL_LAYOUT_BUILD)/runtime-array-layout
	taskset -c 8-11 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_kernel_lto_layout.py --layout $(KERNEL_LAYOUT) --kernel $(KDIR) --boot-capture $(BOOT_CAPTURE) --reference-compiler $(KERNEL_LAYOUT_BUILD)/runtime-array-layout --historical-reference $(ROOT)/corpus/results/perf-corrected-all-lto-linker-20261114 --output $(OUTPUT)/kernel-layout

loader-syntax:
	taskset -c 8-11 prlimit --as=12884901888 -- clang++-18 -std=gnu++20 -fsyntax-only -I$(ROOT)/kprog/libnativeloader/include -I$(ROOT)/micro/programs/build-x86 -I$(LIBBPF_PREFIX)/include -I$(ROOT)/vendor/libbpf/include -I$(ROOT)/vendor/libbpf/include/uapi $(ROOT)/kprog/libnativeloader/src/native_loader.cpp

.PHONY: restore-boot-metadata kernel-layout-boot guest-kernel-layout
restore-boot-metadata:
	flock -s /workspaces/.agent-state/kprog-lanes/locks/image python3 $(ROOT)/kprog/test/restore_boot_elf.py --kernel $(KDIR) --extractor $(ROOT)/vendor/linux-framework/scripts/extract-vmlinux --output $(OUTPUT)/boot-recovery

kernel-layout-boot: $(KERNEL_LAYOUT_BUILD)/facts
	install -d $(OUTPUT) $(OUTPUT)/inputs
	taskset -c 16-17 prlimit --as=17179869184 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rodir $(OUTPUT)/inputs=$(KERNEL_LAYOUT_BUILD) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 4G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/native-relocations.mk guest-kernel-layout OUTPUT=$(OUTPUT) KERNEL_LAYOUT_BUILD=$(OUTPUT)/inputs'

guest-kernel-layout:
	uname -r > $(OUTPUT)/kernel.release
	cat /proc/kallsyms > $(OUTPUT)/kernel.kallsyms
	cat /sys/kernel/btf/vmlinux > $(OUTPUT)/kernel.btf
	$(KERNEL_LAYOUT_BUILD)/facts /sys/kernel/btf/vmlinux /proc/kallsyms > $(OUTPUT)/kernel-layout.json

.PHONY: check build
check: $(KERNEL_LAYOUT)
	taskset -c 8-11 prlimit --as=8589934592 -- env CARGO_BUILD_JOBS=2 CARGO_TARGET_DIR=$(LINKER_TARGET) cargo test --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml

.PHONY: map-table-b
map-table-b: check
	taskset -c 19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_map_table_b.py --build /var/tmp/kprog-tmp/perf/map-pointer-tables --output $(OUTPUT)/map-table-b

.PHONY: map-table-lookup
map-table-lookup: check $(CONTEXT_TOOL)
	taskset -c 19 prlimit --as=17179869184 -- python3 $(ROOT)/kprog/test/build_map_table_lookup.py --build $(MAP_LOOKUP_BUILD) --output $(OUTPUT) --kernel-layout $(KERNEL_LAYOUT) --bounds $(CONTEXT_TOOL)

.PHONY: shared-table-b
shared-table-b: $(CONTEXT_TOOL)
	taskset -c 19 prlimit --as=17179869184 -- python3 $(ROOT)/kprog/test/check_shared_table_b.py --build /var/tmp/kprog-tmp/perf/helper-cfg --output $(OUTPUT) --bounds $(CONTEXT_TOOL)

.PHONY: shared-table-stock guest-shared-table-stock
shared-table-stock: $(TABLE_CONTEXT_BUILD)/stock-client
	install -d $(OUTPUT) $(OUTPUT)/inputs $(OUTPUT)/client
	taskset -c 16-17 prlimit --as=8589934592 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rodir $(OUTPUT)/inputs=/var/tmp/kprog-tmp/perf/helper-cfg --rodir $(OUTPUT)/client=$(TABLE_CONTEXT_BUILD) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/native-relocations.mk guest-shared-table-stock OUTPUT=$(OUTPUT)'

guest-shared-table-stock:
	uname -r > $(OUTPUT)/kernel.release
	$(OUTPUT)/client/stock-client $(OUTPUT)/inputs/shared.original.bpf.o $(OUTPUT)/inputs/shared.bpf.o $(OUTPUT)/original.verifier.log $(OUTPUT)/generated.verifier.log second_table shared_model_x86_sim_xdp > $(OUTPUT)/stock.jsonl

build:
	flock -x /workspaces/.agent-state/kprog-lanes/locks/image taskset -c 8-11 prlimit --as=8589934592 -- env CARGO_BUILD_JOBS=2 CARGO_TARGET_DIR=$(LINKER_TARGET) bash -eu -c 'if test -L "$(LINKER_TARGET)/release/native-link"; then unlink "$(LINKER_TARGET)/release/native-link"; fi; exec cargo build --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml'

.PHONY: preserve-running-linker
preserve-running-linker:
	flock -s /workspaces/.agent-state/kprog-lanes/locks/image python3 $(ROOT)/kprog/test/preserve_running_linker.py --canonical $(LINKER_TARGET)/release/native-link --retained $(ROOT)/corpus/results/perf-corrected-all-lto-linker-20261114/native-link-on --loader /workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader --output $(OUTPUT)/pairing

# The queued run_verified_make caller holds image EX before Make starts.
.PHONY: publish-normal-pair
publish-normal-pair: $(CONTEXT_TOOL) $(CHECKED_TOOL)
	install -d $(OUTPUT)
	git -C $(ROOT) rev-parse HEAD > $(OUTPUT)/source-head.txt
	CMAKE_BUILD_PARALLEL_LEVEL=2 $(MAKE) -r -C $(ROOT)/kprog/libnativeloader trusted-service BUILD_DIR=/workspaces/.agent-state/kprog-ck/verified-loader
	if test -L $(LINKER_TARGET)/release/native-link; then unlink $(LINKER_TARGET)/release/native-link; fi
	taskset -c 8-11 prlimit --as=8589934592 -- env CARGO_BUILD_JOBS=2 CARGO_TARGET_DIR=$(LINKER_TARGET) cargo build --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml
	install -m755 $(CONTEXT_TOOL) /workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds
	install -m755 $(CHECKED_TOOL) /workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir
	sha256sum $(LINKER_TARGET)/release/native-link /workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader /workspaces/.agent-state/kprog-ck/verified-loader/libnative_loader.a /workspaces/.agent-state/kprog-ck/verified-loader/libnative_loader.so /workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds /workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir > $(OUTPUT)/tool-sha256.txt
	date -u +%FT%TZ > $(OUTPUT)/published

.PHONY: evidence
evidence: $(KERNEL_LAYOUT)
	taskset -c 8-11 prlimit --as=12884901888 -- python3 $(ROOT)/kprog/test/check_non_pic_maps.py --build $(BUILD) --output $(OUTPUT)/maps --linker $(LINKER_BINARY) --kernel-layout $(KERNEL_LAYOUT)

.PHONY: jump-table-forms
jump-table-forms:
	install -d $(BUILD) $(OUTPUT)
	clang-18 -target x86_64-linux-gnu -O3 -march=native -foptimize-sibling-calls -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector -c $(ROOT)/kprog/test/native_jump_table.c -o $(BUILD)/jump-table.native.o
	objdump -dr -Mintel $(BUILD)/jump-table.native.o > $(OUTPUT)/jump-table.disassembly
	readelf -rW $(BUILD)/jump-table.native.o > $(OUTPUT)/jump-table.relocations

.PHONY: jump-table-check
jump-table-check: $(LINKER_BINARY) jump-table-forms $(KERNEL_LAYOUT)
	taskset -c 8-11 prlimit --as=12884901888 -- python3 $(ROOT)/kprog/test/check_native_jump_tables.py --build $(BUILD) --output $(OUTPUT)/jump-tables --linker $(LINKER_BINARY) --kernel-layout $(KERNEL_LAYOUT)

.PHONY: compiler-cleanup-check
compiler-cleanup-check:
	taskset -c 8-11 prlimit --as=12884901888 -- python3 $(ROOT)/kprog/test/check_whole_word_backend.py --output $(OUTPUT)/backend --clang $(ROOT)/kprog/stock-path/bin/clang
	$(MAKE) -f $(ROOT)/kprog/test/native-relocations.mk identity-normal-check OUTPUT=$(OUTPUT)

$(CONTEXT_TOOL): $(ROOT)/kprog/x86/packet_bounds_ir.cpp
	taskset -c 8-11 prlimit --as=8589934592 -- clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -I$(ROOT)/vendor/libbpf/include/uapi $< -o $@ $$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)

$(CHECKED_TOOL): $(ROOT)/kprog/x86/compile_sim_ir.cpp
	install -d $(dir $@)
	taskset -c 8-11 prlimit --as=8589934592 -- clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -I$(ROOT)/vendor/libbpf/include/uapi $< -o $@ $$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)

.PHONY: checked-compiler-build
checked-compiler-build: $(CHECKED_TOOL)

.PHONY: checked-table-host checked-fault-host
checked-table-host: $(CHECKED_TOOL)
	CLANG=$(ROOT)/kprog/stock-path/bin/clang taskset -c 19 prlimit --as=17179869184 -- python3 $(ROOT)/kprog/test/check_checked_codegen.py --build $(TABLE_CONTEXT_BUILD) --output $(OUTPUT)/table --linker $(LINKER_BINARY) --compiler $(CHECKED_TOOL) --accepted /workspaces/kprog-raw/perf/20261115-table-context/final/result.json

checked-fault-host: $(CHECKED_TOOL)
	install -d $(OUTPUT)/fault
	status=0; taskset -c 8-11 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_lto_fault.py $(CHECKED_TOOL) $(dir $(CHECKED_TOOL))/fault || status=$$?; cp $(dir $(CHECKED_TOOL))/fault/*.json $(OUTPUT)/fault/; exit $$status

$(CHECKED_PACKET_BUILD)/packet.native.o: $(ROOT)/kprog/test/checked_packet_native.c
	install -d $(CHECKED_PACKET_BUILD)
	clang-18 -O3 -march=native -foptimize-sibling-calls -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-asynchronous-unwind-tables -I$(ROOT)/vendor/bpf/targets/x86/$$(cat $(KDIR)/include/config/kernel.release) -c $< -o $@

.PHONY: checked-packet-host
checked-packet-host: $(CHECKED_TOOL) $(CHECKED_PACKET_BUILD)/packet.native.o
	install -d $(OUTPUT)/packet
	status=0; CLANG=$(ROOT)/kprog/stock-path/bin/clang taskset -c 16-17 prlimit --as=17179869184 -- python3 $(ROOT)/kprog/test/check_checked_packet.py $(CHECKED_TOOL) $(LINKER_BINARY) /workspaces/.agent-state/kprog-ck/verified-compiler/context-lower /workspaces/.agent-state/kprog-ck/verified-compiler/public-layout.json /workspaces/.agent-state/kprog-ck/verified-compiler/physical-layout.json $(CHECKED_PACKET_BUILD)/packet.native.o $(CHECKED_PACKET_BUILD)/host $(CONTEXT_TOOL) || status=$$?; if test -d $(CHECKED_PACKET_BUILD)/host; then cd $(CHECKED_PACKET_BUILD)/host; find . -type f -name '*.json' -exec cp --parents '{}' $(OUTPUT)/packet/ \;; fi; exit $$status

.PHONY: identity-normal-check
identity-normal-check: $(CONTEXT_TOOL)
	taskset -c 8-11 prlimit --as=12884901888 -- python3 $(ROOT)/kprog/test/check_packet_identities.py --tool $(CONTEXT_TOOL) --output $(OUTPUT)/identities

.PHONY: table-context-build
table-context-build: $(KERNEL_LAYOUT) $(CONTEXT_TOOL)
	taskset -c 19 prlimit --as=17179869184 -- python3 $(ROOT)/kprog/test/build_context_table.py --build $(TABLE_CONTEXT_BUILD) --output $(OUTPUT) --linker $(LINKER_BINARY) --kernel-layout $(KERNEL_LAYOUT) --bounds $(CONTEXT_TOOL)

$(TABLE_CONTEXT_BUILD)/stock-client: $(ROOT)/kprog/test/context_table_stock.c
	install -d $(TABLE_CONTEXT_BUILD)
	$(CC) -O2 -g -Wall -Wextra -Werror -I$(LIBBPF_PREFIX)/include $< $(LIBBPF_LIBRARY) -lelf -lz -o $@

.PHONY: table-context-stock guest-table-context-stock
table-context-stock: $(TABLE_CONTEXT_BUILD)/stock-client
	install -d $(OUTPUT) $(OUTPUT)/inputs
	taskset -c 16-17 prlimit --as=8589934592 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rodir $(OUTPUT)/inputs=$(TABLE_CONTEXT_BUILD) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/native-relocations.mk guest-table-context-stock OUTPUT=$(OUTPUT) TABLE_CONTEXT_BUILD=$(OUTPUT)/inputs'

guest-table-context-stock:
	uname -r > $(OUTPUT)/kernel.release
	$(TABLE_CONTEXT_BUILD)/stock-client $(TABLE_CONTEXT_BUILD)/original.bpf.o $(TABLE_CONTEXT_BUILD)/trusted_x86.bpf.o $(OUTPUT)/original.verifier.log $(OUTPUT)/generated.verifier.log > $(OUTPUT)/stock.jsonl

.PHONY: table-context-checked guest-table-context-checked
table-context-checked:
	install -d $(OUTPUT) $(OUTPUT)/inputs
	git -C $(ROOT) rev-parse HEAD > $(OUTPUT)/source-head.txt
	sha256sum $(KDIR)/arch/x86/boot/bzImage $(LINKER_BINARY) /workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader /workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir $(TABLE_CONTEXT_BUILD)/table.native.o $(TABLE_CONTEXT_BUILD)/trusted_x86.bpf.o > $(OUTPUT)/inputs.sha256
	taskset -c 16-17 prlimit --as=17179869184 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rwdir $(OUTPUT)/inputs=$(TABLE_CONTEXT_BUILD) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 4G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/native-relocations.mk guest-table-context-checked OUTPUT=$(OUTPUT) TABLE_CONTEXT_BUILD=$(OUTPUT)/inputs'

guest-table-context-checked:
	uname -r > $(OUTPUT)/kernel.release
	mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	mountpoint -q /sys/fs/bpf || mount -t bpf bpffs /sys/fs/bpf
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	CLANG=$(ROOT)/kprog/stock-path/bin/clang python3 $(ROOT)/kprog/test/verify_retained_proof.py --native $(TABLE_CONTEXT_BUILD)/table.native.o --metadata $(ROOT)/kprog/test/table_context_metadata.json --context $(ROOT)/kprog/test/table_context_load_context.json --source $(TABLE_CONTEXT_BUILD)/original.bpf.o --proof $(TABLE_CONTEXT_BUILD)/trusted_x86.bpf.o --symbol jump_table --linker $(LINKER_BINARY) --checked-source $(TABLE_CONTEXT_BUILD)/trusted_x86.bpf.i --checked-frontend $(TABLE_CONTEXT_BUILD)/trusted_x86.bpf.bounds-input.bc --checked-compiler /workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir --output $(OUTPUT)/replay

.PHONY: map-table-lookup-checked guest-map-table-lookup-checked
map-table-lookup-checked:
	install -d $(OUTPUT) $(OUTPUT)/inputs
	git -C $(ROOT) rev-parse HEAD > $(OUTPUT)/source-head.txt
	sha256sum $(KDIR)/arch/x86/boot/bzImage $(LINKER_BINARY) /workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader /workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir $(MAP_LOOKUP_BUILD)/lookup.native.o $(MAP_LOOKUP_BUILD)/trusted_x86.bpf.o > $(OUTPUT)/inputs.sha256
	taskset -c 16-17 prlimit --as=17179869184 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rwdir $(OUTPUT)/inputs=$(MAP_LOOKUP_BUILD) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 4G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/native-relocations.mk guest-map-table-lookup-checked OUTPUT=$(OUTPUT) MAP_LOOKUP_BUILD=$(OUTPUT)/inputs'

guest-map-table-lookup-checked:
	uname -r > $(OUTPUT)/kernel.release
	mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	mountpoint -q /sys/fs/bpf || mount -t bpf bpffs /sys/fs/bpf
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	CLANG=$(ROOT)/kprog/stock-path/bin/clang python3 $(ROOT)/kprog/test/verify_retained_proof.py --native $(MAP_LOOKUP_BUILD)/lookup.native.o --metadata $(ROOT)/kprog/test/map_table_lookup_metadata.json --context $(ROOT)/kprog/test/table_context_load_context.json --source $(MAP_LOOKUP_BUILD)/original.bpf.o --proof $(MAP_LOOKUP_BUILD)/trusted_x86.bpf.o --symbol map_lookup_table --linker $(LINKER_BINARY) --checked-source $(MAP_LOOKUP_BUILD)/trusted_x86.bpf.i --checked-frontend $(MAP_LOOKUP_BUILD)/trusted_x86.bpf.bounds-input.bc --checked-compiler /workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir --output $(OUTPUT)/replay
