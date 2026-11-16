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
BOOT_CAPTURE ?= /workspaces/kprog-raw/perf/20261115-base-consistency/boot
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

CHECK_CPUS ?= 8-11
.PHONY: lto-ranges-audit
lto-ranges-audit:
	taskset -c $(CHECK_CPUS) prlimit --as=8589934592 -- env CARGO_BUILD_JOBS=1 CARGO_TARGET_DIR=$(LINKER_TARGET) NATIVE_LINK_LTO_AUDIT_REPORT=/workspaces/kprog-raw/perf/20261116-native-corpus-before-publication/report.json cargo test --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml retained_lto_diagnostics_preserve_payload_bytes -- --ignored --nocapture

.PHONY: helper-register-abi
helper-register-abi:
	taskset -c 16-17 prlimit --as=2147483648 -- python3 $(ROOT)/kprog/test/check_tetragon_helper_registers.py --build /var/tmp/kprog-tmp/perf/helper-register-abi --output $(OUTPUT)

.PHONY: helper-join-proof
helper-join-proof:
	install -d $(OUTPUT) $(BUILD)
	clang-18 -O3 -g -fPIC -fomit-frame-pointer -march=native -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables -I$(ROOT)/vendor/libbpf/include/uapi -D__KPROG_CORE_ANSWERS='"$(ROOT)/vendor/build/native-bpf/x86/$(shell cat $(KDIR)/include/config/kernel.release)/answers/tetragon.h"' -c $(ROOT)/kprog/test/tetragon_helper_join.c -o $(BUILD)/helper-join.o
	llvm-objdump-18 -dr $(BUILD)/helper-join.o > $(OUTPUT)/helper-join.dis
	$(LINKER_BINARY) --input $(BUILD)/helper-join.o --symbol helper_join --mode proof --preserve-entry-abi --output $(OUTPUT)/helper-join.proof.o
	python3 -c 'import pathlib,tarfile; archive=tarfile.open("/workspaces/kprog-raw/perf/20261116-checked-six-apps/tetragon/state/session-sxeysh3e/requests/1.success.tar.gz"); name=next(n for n in archive.getnames() if n.endswith(".link-plan.json")); pathlib.Path("$(OUTPUT)/link-plan.json").write_bytes(archive.extractfile(name).read())'
	$(LINKER_BINARY) --input $(OUTPUT)/helper-join.proof.o --symbol helper_join --mode kernel --link-plan $(OUTPUT)/link-plan.json --output $(OUTPUT)/blob.bin --output-relocs $(OUTPUT)/relocs.bin --output-map-patches $(OUTPUT)/maps.tsv --output-abi $(OUTPUT)/abi.tsv

.PHONY: numeric-tail-b numeric-tail-stock guest-numeric-tail-stock
NUMERIC_TAIL_BUILD := /var/tmp/kprog-tmp/perf/helper-cfg
numeric-tail-b:
	clang-18 -target bpf -O2 -g -c $(ROOT)/kprog/test/native_numeric_helper_tail.c -o $(NUMERIC_TAIL_BUILD)/numeric-tail.source.bpf.o
	taskset -c 16 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/build_numeric_helper_tail_b.py --build $(NUMERIC_TAIL_BUILD) --output $(OUTPUT)
	tar -C $(NUMERIC_TAIL_BUILD) -czf $(OUTPUT)/build.tar.gz .

numeric-tail-stock:
	install -d $(OUTPUT) $(OUTPUT)/inputs
	flock -s /workspaces/.agent-state/kprog-lanes/locks/image taskset -c 16 prlimit --as=8589934592 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(OUTPUT) --rodir $(OUTPUT)/inputs=$(NUMERIC_TAIL_BUILD) --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/native-relocations.mk guest-numeric-tail-stock OUTPUT=$(OUTPUT)'

guest-numeric-tail-stock:
	mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	mountpoint -q /sys/fs/bpf || mount -t bpf bpffs /sys/fs/bpf
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	python3 $(ROOT)/kprog/test/verify_retained_proof.py --native $(OUTPUT)/inputs/numeric-tail.native.o --metadata $(OUTPUT)/inputs/metadata.json --context $(OUTPUT)/inputs/context.json --source $(OUTPUT)/inputs/numeric-tail.source.bpf.o --proof $(OUTPUT)/inputs/trusted_x86.bpf.o --symbol numeric_tail --linker $(LINKER_BINARY) --output $(OUTPUT)/replay

.PHONY: check build
check: $(KERNEL_LAYOUT)
	taskset -c $(CHECK_CPUS) prlimit --as=8589934592 -- env CARGO_BUILD_JOBS=2 CARGO_TARGET_DIR=$(LINKER_TARGET) NATIVE_LINK_HASH_TEST_OUTPUT=$(OUTPUT)/hash-execution cargo test --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml

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
	flock -x /workspaces/.agent-state/kprog-lanes/locks/image taskset -c $(CHECK_CPUS) prlimit --as=8589934592 -- env CARGO_BUILD_JOBS=2 CARGO_TARGET_DIR=$(LINKER_TARGET) bash -eu -c 'if test -L "$(LINKER_TARGET)/release/native-link"; then unlink "$(LINKER_TARGET)/release/native-link"; fi; exec cargo build --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml'

.PHONY: preserve-running-linker
preserve-running-linker:
	flock -s /workspaces/.agent-state/kprog-lanes/locks/image python3 $(ROOT)/kprog/test/preserve_running_linker.py --canonical $(LINKER_TARGET)/release/native-link --retained $(ROOT)/corpus/results/perf-corrected-all-lto-linker-20261114/native-link-on --loader /workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader --output $(OUTPUT)/pairing

# Caller holds image SH on behalf of this already-running guest batch. It
# releases naturally when that exact owner exits; it never signals the owner.
.PHONY: hold-existing-guest-image
hold-existing-guest-image:
	tail --pid=$(PERF_GUEST_OWNER_PID) -f /dev/null

.PHONY: base-consistency-smoke
base-consistency-smoke:
	bash $(ROOT)/kprog/test/run_base_consistency_smoke.sh $(OUTPUT)

.PHONY: base-consistency-inventory
base-consistency-inventory:
	python3 $(ROOT)/kprog/test/image_module_inventory.py --image $(ROOT)/.cache/container-images/x86_64-runner-runtime.image.tar --kernel $(KDIR) --output $(OUTPUT)

.PHONY: base-stock-module-smoke
base-stock-module-smoke:
	install -d $(OUTPUT)
	sha256sum $(KDIR)/arch/x86/boot/bzImage /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko > $(OUTPUT)/input-sha256.txt
	taskset -c 16-17 vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'bash kprog/test/guest_base_stock_module.sh $(OUTPUT)'

.PHONY: image-pc32 guest-image-pc32
image-pc32:
	install -d $(BUILD) $(OUTPUT)
	clang-18 -target x86_64-linux-gnu -O3 -march=native -foptimize-sibling-calls -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector -c $(ROOT)/kprog/test/non_pic_map.c -o $(BUILD)/non-pic.native.o
	readelf -rW $(BUILD)/non-pic.native.o > $(OUTPUT)/native-relocations.txt
	bash $(ROOT)/kprog/test/run_image_pc32.sh $(OUTPUT)

guest-image-pc32:
	$(MAKE) -r -C $(ROOT) __runtime-vm-docker
	$(ROOT)/runner/scripts/bpfrejit-install --image bpf-benchmark/kprog:current /var/tmp/runtime.image.tar
	python3 $(ROOT)/kprog/test/check_image_pc32.py --image bpf-benchmark/kprog:current --build $(OUTPUT)/inputs --kernel-layout $(OUTPUT)/layout/kernel-layout.json --repo-linker $(LINKER_BINARY) --output $(OUTPUT)

# The queued run_verified_make caller holds image EX before Make starts.
.PHONY: publish-normal-pair
publish-normal-pair: $(CONTEXT_TOOL) $(CHECKED_TOOL)
	install -d $(OUTPUT)
	git -C $(ROOT) rev-parse HEAD > $(OUTPUT)/source-head.txt
	CMAKE_BUILD_PARALLEL_LEVEL=2 $(MAKE) -r -C $(ROOT)/kprog/libnativeloader trusted-service BUILD_DIR=/workspaces/.agent-state/kprog-ck/verified-loader
	if test -L $(LINKER_TARGET)/release/native-link; then unlink $(LINKER_TARGET)/release/native-link; fi
	taskset -c $(CHECK_CPUS) prlimit --as=8589934592 -- env CARGO_BUILD_JOBS=2 CARGO_TARGET_DIR=$(LINKER_TARGET) cargo build --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml
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

ABSOLUTE_TABLE_BUILD := /var/tmp/kprog-tmp/perf/absolute-code-tables
.PHONY: absolute-table-forms
absolute-table-forms:
	install -d $(ABSOLUTE_TABLE_BUILD) $(OUTPUT)
	clang-18 -target x86_64-linux-gnu -O3 -march=native -foptimize-sibling-calls -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector -c $(ROOT)/kprog/test/native_absolute_code_table.c -o $(ABSOLUTE_TABLE_BUILD)/absolute.native.o
	objdump -dr -Mintel $(ABSOLUTE_TABLE_BUILD)/absolute.native.o > $(OUTPUT)/native.disassembly
	readelf -rW $(ABSOLUTE_TABLE_BUILD)/absolute.native.o > $(OUTPUT)/native.relocations
	$(LINKER_BINARY) --input $(ABSOLUTE_TABLE_BUILD)/absolute.native.o --symbol absolute_table --mode proof --output $(ABSOLUTE_TABLE_BUILD)/absolute.proof.o > $(OUTPUT)/proof.stdout 2> $(OUTPUT)/proof.stderr

.PHONY: absolute-table-source
absolute-table-source: $(KERNEL_LAYOUT)
	taskset -c 16-19 prlimit --as=8589934592 -- env CARGO_BUILD_JOBS=2 CARGO_TARGET_DIR=$(LINKER_TARGET) cargo test --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml

.PHONY: absolute-table-b
absolute-table-b: $(CONTEXT_TOOL)
	taskset -c 16-19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_absolute_code_table.py --build $(ABSOLUTE_TABLE_BUILD) --output $(OUTPUT) --bounds $(CONTEXT_TOOL) --linker $(LINKER_BINARY) --kernel-layout $(KERNEL_LAYOUT)

.PHONY: absolute-table-stock guest-absolute-table-stock
absolute-table-stock: /var/tmp/kprog-tmp/perf/scheduled-table/stock-client
	install -d $(OUTPUT)
	sha256sum $(KDIR)/arch/x86/boot/bzImage $(ABSOLUTE_TABLE_BUILD)/absolute.bpf.o $(ABSOLUTE_TABLE_BUILD)/absolute.proof.o > $(OUTPUT)/input-sha256.txt
	taskset -c 16-17 prlimit --as=8589934592 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rodir $(OUTPUT)/inputs=$(ABSOLUTE_TABLE_BUILD) --rodir $(OUTPUT)/client=/var/tmp/kprog-tmp/perf/scheduled-table --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/native-relocations.mk guest-absolute-table-stock OUTPUT=$(OUTPUT)'

guest-absolute-table-stock:
	$(OUTPUT)/client/stock-client $(OUTPUT)/inputs/absolute.bpf.o absolute_model_x86_sim_xdp $(OUTPUT)/verifier.log > $(OUTPUT)/result.json

# Caller holds image EX across the in-place rebuild and its short boot check.
ABSOLUTE_KERNEL_OUTPUT ?= /workspaces/kprog-raw/perf/20261115-absolute-code-tables/kernel
.PHONY: absolute-image-kernel
absolute-image-kernel:
	install -d $(ABSOLUTE_KERNEL_OUTPUT)
	git -C $(ROOT)/vendor/linux-framework rev-parse HEAD > $(ABSOLUTE_KERNEL_OUTPUT)/kernel-source.txt
	sha256sum $(KDIR)/.config $(KDIR)/arch/x86/boot/bzImage $(KDIR)/vmlinux > $(ABSOLUTE_KERNEL_OUTPUT)/before-sha256.txt
	$(MAKE) -r -C $(ROOT)/kprog/libnativeloader shared-base-modules-repair REFRESH_OUTPUT=$(ABSOLUTE_KERNEL_OUTPUT)/packaging
	sha256sum $(KDIR)/.config $(KDIR)/arch/x86/boot/bzImage $(KDIR)/vmlinux /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko > $(ABSOLUTE_KERNEL_OUTPUT)/after-sha256.txt
	$(MAKE) -r -f $(ROOT)/kprog/test/native-relocations.mk kernel-layout-boot OUTPUT=$(ABSOLUTE_KERNEL_OUTPUT)/boot
	$(MAKE) -r -f $(ROOT)/kprog/test/native-relocations.mk kernel-layout BOOT_CAPTURE=$(ABSOLUTE_KERNEL_OUTPUT)/boot
	date -u +%FT%TZ > $(ABSOLUTE_KERNEL_OUTPUT)/published

.PHONY: jump-table-check
jump-table-check: $(LINKER_BINARY) jump-table-forms $(KERNEL_LAYOUT)
	taskset -c 8-11 prlimit --as=12884901888 -- python3 $(ROOT)/kprog/test/check_native_jump_tables.py --build $(BUILD) --output $(OUTPUT)/jump-tables --linker $(LINKER_BINARY) --kernel-layout $(KERNEL_LAYOUT)

.PHONY: compiler-cleanup-check
compiler-cleanup-check:
	taskset -c 8-11 prlimit --as=12884901888 -- python3 $(ROOT)/kprog/test/check_whole_word_backend.py --output $(OUTPUT)/backend --clang $(ROOT)/kprog/stock-path/bin/clang
	$(MAKE) -f $(ROOT)/kprog/test/native-relocations.mk identity-normal-check OUTPUT=$(OUTPUT)

$(CONTEXT_TOOL): $(ROOT)/kprog/x86/packet_bounds_ir.cpp
	install -d $(dir $@)
	taskset -c 8-11 prlimit --as=8589934592 -- clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -I$(ROOT)/vendor/libbpf/include/uapi $< -o $@ $$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)

.PHONY: bounds-single-control bounds-single-check bounds-single-publish
bounds-single-control:
	taskset -c 16-19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_packet_identities.py --tool /workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds --output $(OUTPUT)/identities

bounds-single-check: $(CONTEXT_TOOL)
	taskset -c 16-19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_packet_identities.py --tool $(CONTEXT_TOOL) --output $(OUTPUT)/identities
	taskset -c 16-19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_context_loads.py --tool $(CONTEXT_TOOL) --build /var/tmp/kprog-tmp/perf/context-loads-v2/cases --output $(OUTPUT)/context
	taskset -c 16-19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_whole_word_backend.py --output $(OUTPUT)/backend --clang $(ROOT)/kprog/stock-path/bin/clang

bounds-single-publish: $(CONTEXT_TOOL)
	install -d $(OUTPUT)
	sha256sum /workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds > $(OUTPUT)/previous-tool.sha256
	install -m755 $(CONTEXT_TOOL) /workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds
	sha256sum $(CONTEXT_TOOL) /workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds $(ROOT)/kprog/x86/packet_bounds_ir.cpp $(ROOT)/kprog/x86/trusted_specializer.py $(ROOT)/kprog/x86/whole_word_spills.py > $(OUTPUT)/published-tool.sha256

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

.PHONY: scheduled-table-b
scheduled-table-b: $(CONTEXT_TOOL)
	taskset -c $(CHECK_CPUS) prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_scheduled_table.py --build /var/tmp/kprog-tmp/perf/scheduled-table --output $(OUTPUT)/simulator --bounds $(CONTEXT_TOOL)

.PHONY: scheduled-otel-source
scheduled-otel-source:
	taskset -c 8-11 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/render_scheduled_otel.py --build /var/tmp/kprog-tmp/perf/scheduled-table --output $(OUTPUT)/otel-source

.PHONY: scheduled-table-reference scheduled-table-stock guest-scheduled-table-stock
scheduled-table-reference:
	taskset -c 8-11 prlimit --as=8589934592 -- clang-18 -target bpf -O2 -g -I/usr/include/x86_64-linux-gnu -I$(ROOT)/vendor/libbpf/src -c $(ROOT)/kprog/test/scheduled_table_reference.bpf.c -o /var/tmp/kprog-tmp/perf/scheduled-table/scheduled.original.bpf.o

scheduled-table-stock: /var/tmp/kprog-tmp/perf/scheduled-table/stock-client
	install -d $(OUTPUT) $(OUTPUT)/inputs $(OUTPUT)/client
	flock -s /workspaces/.agent-state/kprog-lanes/locks/image taskset -c 16-17 prlimit --as=8589934592 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rodir $(OUTPUT)/inputs=/var/tmp/kprog-tmp/perf/scheduled-table --rodir $(OUTPUT)/client=/var/tmp/kprog-tmp/perf/scheduled-table --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/native-relocations.mk guest-scheduled-table-stock OUTPUT=$(OUTPUT)'

guest-scheduled-table-stock:
	uname -r > $(OUTPUT)/kernel.release
	$(OUTPUT)/client/stock-client $(OUTPUT)/inputs/scheduled.original.bpf.o $(OUTPUT)/inputs/scheduled.bpf.o $(OUTPUT)/original.verifier.log $(OUTPUT)/generated.verifier.log > $(OUTPUT)/stock.jsonl
	$(OUTPUT)/client/stock-client $(OUTPUT)/inputs/base.bpf.o trusted_x86_x86_sim_xdp $(OUTPUT)/base.verifier.log >> $(OUTPUT)/stock.jsonl

/var/tmp/kprog-tmp/perf/scheduled-table/stock-client: $(ROOT)/kprog/test/scheduled_table_stock.cpp $(ROOT)/kprog/libnativeloader/src/native_loader.cpp
	taskset -c 8-11 prlimit --as=8589934592 -- $(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections -I$(ROOT)/kprog/libnativeloader/include -I$(ROOT)/micro/programs/build-x86 -I$(LIBBPF_PREFIX)/include -I$(ROOT)/vendor/libbpf/include -I$(ROOT)/vendor/libbpf/include/uapi $< -Wl,--gc-sections $(LIBBPF_LIBRARY) -lelf -lz -ldl -pthread -o $@

.PHONY: scheduled-table-checked guest-scheduled-table-checked
scheduled-table-checked:
	install -d $(OUTPUT) $(OUTPUT)/inputs
	taskset -c 16-17 prlimit --as=17179869184 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rwdir $(OUTPUT)/inputs=/var/tmp/kprog-tmp/perf/scheduled-table --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 4G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/native-relocations.mk guest-scheduled-table-checked OUTPUT=$(OUTPUT)'

guest-scheduled-table-checked:
	uname -r > $(OUTPUT)/kernel.release
	mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	mountpoint -q /sys/fs/bpf || mount -t bpf bpffs /sys/fs/bpf
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	CLANG=$(ROOT)/kprog/stock-path/bin/clang python3 $(ROOT)/kprog/test/verify_retained_proof.py --native $(OUTPUT)/inputs/scheduled.native.o --metadata $(ROOT)/kprog/test/table_context_metadata.json --context $(ROOT)/kprog/test/table_context_load_context.json --source $(OUTPUT)/inputs/scheduled.original.bpf.o --proof $(OUTPUT)/inputs/scheduled.bpf.o --symbol scheduled_table --linker $(LINKER_BINARY) --checked-source $(OUTPUT)/inputs/scheduled.bpf.i --checked-frontend $(OUTPUT)/inputs/scheduled.bpf.bounds-input.bc --checked-compiler /workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir --output $(OUTPUT)/replay

.PHONY: current-otel-preprocess
current-otel-preprocess:
	taskset -c 8-11 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/profile_current_otel.py --build /var/tmp/kprog-tmp/perf/otel-whole-word-checked --output $(OUTPUT) --metadata /workspaces/kprog-raw/perf/20261115-otel-hotspot-spills/replay/request__generation.metadata.json --entry /workspaces/kprog-raw/perf/20261115-otel-hotspot-spills/replay/request__kernel.entry

.PHONY: bmi2-specialization bmi2-contract
bmi2-specialization: $(CONTEXT_TOOL)
	taskset -c 8-11 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_bmi2_specialization.py --build /var/tmp/kprog-tmp/perf/bmi2-specialization --output $(OUTPUT) --bounds $(CONTEXT_TOOL) --linker $(LINKER_BINARY)

bmi2-contract:
	python3 $(ROOT)/kprog/formal/tools/generate_x86_specialization_spec.py --check
	install -d /var/tmp/kprog-tmp/perf/bmi2-specialization
	taskset -c 8-11 prlimit --as=8589934592 -- $(MAKE) -C $(ROOT)/kprog/formal -f $(ROOT)/kprog/test/native-relocations.mk bmi2-contract-host ROOT=$(ROOT)
	$(MAKE) -r -f $(ROOT)/kprog/test/native-relocations.mk bmi2-contract-lean

.PHONY: bmi2-contract-host
bmi2-contract-host:
	clang-18 -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_specialization_chain_host.c -o /var/tmp/kprog-tmp/perf/bmi2-specialization/chain
	/var/tmp/kprog-tmp/perf/bmi2-specialization/chain
	clang-18 -Wall -Wextra -O2 -I. -I../x86 -I../../kprog -I../../vendor/libbpf/src oracles/test_x86_specialization_host.c -o /var/tmp/kprog-tmp/perf/bmi2-specialization/specialization
	/var/tmp/kprog-tmp/perf/bmi2-specialization/specialization

.PHONY: bmi2-contract-lean
bmi2-contract-lean:
	cd $(ROOT)/kprog/formal && taskset -c 8-11 prlimit --as=17179869184 -- env LEAN_NUM_THREADS=2 lake build KProgFormal.X86Specialization

.PHONY: load-oracles
load-oracles:
	taskset -c 8-11 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_load_oracles.py --build /var/tmp/kprog-tmp/perf/load-writeback --output $(OUTPUT)

.PHONY: host-input-x86-profiles host-input-arm64-profiles
host-input-x86-profiles:
	taskset -c 16-19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_host_input_profiles.py --arch x86 --output $(OUTPUT)

host-input-arm64-profiles:
	taskset -c 16-19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_host_input_profiles.py --arch arm64 --output $(OUTPUT)

.PHONY: control-input-comparison
control-input-comparison:
	taskset -c 16-19 prlimit --as=2147483648 -- python3 $(ROOT)/kprog/test/compare_control_inputs.py --before /workspaces/kprog-raw/perf/20261115-preprocess-growth/cells-control/mismatches.jsonl --after /workspaces/kprog-raw/perf/20261115-host-input-route/control-after/mismatches.jsonl --output $(OUTPUT)

.PHONY: control-hardware-witness
CONTROL_WITNESS_RUN ?= /workspaces/kprog-raw/perf/20261115-control-witness/full
control-hardware-witness:
	taskset -c 16-19 prlimit --as=2147483648 -- python3 $(ROOT)/kprog/test/analyze_control_witness.py --run $(CONTROL_WITNESS_RUN) --before /workspaces/kprog-raw/perf/20261115-host-input-route/control-after --output $(OUTPUT)

.PHONY: native-stores
native-stores: $(CONTEXT_TOOL)
	python3 $(ROOT)/kprog/formal/tools/generate_x86_store_spec.py --check
	taskset -c 8-11 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_native_stores.py --build /var/tmp/kprog-tmp/perf/store-writeback --output $(OUTPUT) --bounds $(CONTEXT_TOOL) --linker $(LINKER_BINARY)

.PHONY: current-otel-frontend
current-otel-frontend:
	taskset -c 8-11 prlimit --as=17179869184 -- python3 $(ROOT)/kprog/test/profile_current_otel.py --frontend --build /var/tmp/kprog-tmp/perf/otel-whole-word-checked --output $(OUTPUT) --metadata /workspaces/kprog-raw/perf/20261115-otel-hotspot-spills/replay/request__generation.metadata.json --entry /workspaces/kprog-raw/perf/20261115-otel-hotspot-spills/replay/request__kernel.entry

FRONTEND_PROFILE ?= /workspaces/kprog-raw/perf/20261115-store-constants/otel-frontend/result.json
.PHONY: current-otel-backend
current-otel-backend: $(CONTEXT_TOOL)
	taskset -c 8-11 prlimit --as=17179869184 -- python3 $(ROOT)/kprog/test/resume_simulator_frontend.py --profile $(FRONTEND_PROFILE) --source /var/tmp/kprog-tmp/perf/otel-whole-word-checked/trusted_x86.bpf.c --object /var/tmp/kprog-tmp/perf/otel-whole-word-checked/trusted_x86.bpf.o --bounds $(CONTEXT_TOOL) --output $(OUTPUT)

.PHONY: frontend-resume-host
frontend-resume-host: $(CONTEXT_TOOL)
	taskset -c 8-11 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_frontend_resume.py --build /var/tmp/kprog-tmp/perf/store-writeback --bounds $(CONTEXT_TOOL) --output $(OUTPUT)/resume

.PHONY: tracee-proof-survey
tracee-proof-survey:
	taskset -c 16-19 prlimit --as=4294967296 -- python3 $(ROOT)/kprog/test/survey_native_proofs.py --native $(ROOT)/vendor/build/native-bpf/x86/$$(cat $(KDIR)/include/config/kernel.release)/native/tracee/tracee.native.o --linker $(LINKER_BINARY) --build /var/tmp/kprog-tmp/perf/native-proof-survey --output $(OUTPUT)

.PHONY: scalar-rodata-check
scalar-rodata-check: $(KERNEL_LAYOUT)
	taskset -c 16-19 prlimit --as=8589934592 -- env CARGO_BUILD_JOBS=2 CARGO_TARGET_DIR=$(LINKER_TARGET) cargo test --release --manifest-path $(ROOT)/kprog/x86/native_lab/native_link/Cargo.toml anonymous_section_data_reference_excludes_unrelated_code_tables -- --nocapture

.PHONY: scalar-rodata-b scalar-rodata-reference scalar-rodata-stock guest-scalar-rodata-stock
scalar-rodata-b: $(CONTEXT_TOOL)
	taskset -c 16-19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_scalar_rodata_b.py --build /var/tmp/kprog-tmp/perf/scalar-rodata --output $(OUTPUT) --bounds $(CONTEXT_TOOL)

scalar-rodata-reference:
	taskset -c 16-19 prlimit --as=8589934592 -- clang-18 -target bpf -O2 -g -I/usr/include/x86_64-linux-gnu -I$(ROOT)/vendor/libbpf/src -c $(ROOT)/kprog/test/scalar_rodata_reference.bpf.c -o /var/tmp/kprog-tmp/perf/scalar-rodata/scalar.original.bpf.o

scalar-rodata-stock: /var/tmp/kprog-tmp/perf/scheduled-table/stock-client
	install -d $(OUTPUT) $(OUTPUT)/inputs
	taskset -c 16-17 prlimit --as=8589934592 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rodir $(OUTPUT)/inputs=/var/tmp/kprog-tmp/perf/scalar-rodata --rodir $(OUTPUT)/client=/var/tmp/kprog-tmp/perf/scheduled-table --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/native-relocations.mk guest-scalar-rodata-stock OUTPUT=$(OUTPUT)'

guest-scalar-rodata-stock:
	uname -r > $(OUTPUT)/kernel.release
	$(OUTPUT)/client/stock-client $(OUTPUT)/inputs/scalar.original.bpf.o $(OUTPUT)/inputs/scalar.bpf.o $(OUTPUT)/original.verifier.log $(OUTPUT)/generated.verifier.log scalar_reference scalar_model_x86_sim_xdp > $(OUTPUT)/stock.jsonl

.PHONY: frontend-debugger frontend-stacks
frontend-debugger:
	install -d $(OUTPUT)
	apt-get --simulate --no-install-recommends install gdb > $(OUTPUT)/package-plan.log 2>&1
	taskset -c 8-11 prlimit --as=2147483648 -- env DEBIAN_FRONTEND=noninteractive apt-get -y --no-install-recommends install gdb > $(OUTPUT)/package-install.log 2>&1

frontend-stacks:
	taskset -c 8-11 prlimit --as=2147483648 -- python3 $(ROOT)/kprog/test/sample_compiler_stack.py --pid $(COMPILER_PID) --output $(OUTPUT)

.PHONY: frontend-release-image
COMPILER_LOCK_FD ?= 9
COMPILER_LOCK ?= /workspaces/.agent-state/kprog-lanes/locks/image
frontend-release-image:
	taskset -c 8-11 prlimit --as=536870912 -- python3 $(ROOT)/kprog/test/release_compiler_image_lock.py --pid $(COMPILER_LAUNCHER) --fd $(COMPILER_LOCK_FD) --lock $(COMPILER_LOCK) --output $(OUTPUT)

.PHONY: frontend-constants
frontend-constants:
	taskset -c 8-11 prlimit --as=2147483648 -- python3 $(ROOT)/kprog/test/probe_frontend_constants.py --build /var/tmp/kprog-tmp/perf/frontend-constants --output $(OUTPUT)

.PHONY: inline-otel-measure
inline-otel-measure:
	taskset -c 8-11 prlimit --as=17179869184 -- python3 $(ROOT)/kprog/test/measure_inline_otel.py --build /var/tmp/kprog-tmp/perf/otel-whole-word-checked --metadata /workspaces/kprog-raw/perf/20261115-otel-hotspot-spills/replay/request__generation.metadata.json --previous /workspaces/kprog-raw/perf/20261115-width-constants/otel-frontend/result.json --output $(OUTPUT) $(INLINE_MEASURE_ARGS)

.PHONY: inline-table-debug
inline-table-debug:
	taskset -c 16-19 prlimit --as=2147483648 -- python3 $(ROOT)/kprog/test/observe_inline_debug.py --bitcode $(ABSOLUTE_TABLE_BUILD)/absolute.bpf.bounds-input.bc --object $(ABSOLUTE_TABLE_BUILD)/absolute.bpf.o --output $(OUTPUT)/debug.json

.PHONY: inline-helper-host
inline-helper-host:
	install -d /var/tmp/kprog-tmp/perf/inline-helper-host $(OUTPUT)
	taskset -c 16-19 prlimit --as=8589934592 -- clang-18 -O2 -g -w -I$(ROOT)/vendor/libbpf/src $(ROOT)/kprog/test/inline_helper_host.c -o /var/tmp/kprog-tmp/perf/inline-helper-host/check
	taskset -c 16-19 /var/tmp/kprog-tmp/perf/inline-helper-host/check > $(OUTPUT)/helper.json

.PHONY: memory-b-pipeline-check
memory-b-pipeline-check:
	taskset -c 16-19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_memory_b_pipeline.py --frontend $(ABSOLUTE_TABLE_BUILD)/absolute.bpf.bounds-input.bc --object $(ABSOLUTE_TABLE_BUILD)/absolute.bpf.o --bounds $(CONTEXT_TOOL) --output $(OUTPUT)

.PHONY: resume-owned-compiler
resume-owned-compiler:
	taskset -c 16 prlimit --as=536870912 -- python3 $(ROOT)/kprog/test/resume_owned_compiler.py --compiler $(RESUME_COMPILER) --launcher $(RESUME_LAUNCHER) --timing /workspaces/.agent-state/kprog-lanes/locks/timing --image /workspaces/.agent-state/kprog-lanes/locks/image --output $(OUTPUT)

.PHONY: inline-scale-stock
inline-scale-stock:
	taskset -c 16-19 prlimit --as=2147483648 -- python3 $(ROOT)/kprog/test/prepare_inline_scale_checks.py --profiles $(SCALE_PROFILES) --build /var/tmp/kprog-tmp/perf/scale --output $(OUTPUT)/records
	$(MAKE) -r -C $(ROOT)/kprog/fidelity scale-kvm SCALE_BUILD=/var/tmp/kprog-tmp/perf/scale SCALE_RECORDS=$(OUTPUT)/records SCALE_OUT=$(OUTPUT)/guest

.PHONY: ir-debug-census
ir-debug-census:
	taskset -c 16-19 prlimit --as=4294967296 -- python3 $(ROOT)/kprog/test/observe_inline_debug.py --bitcode $(BITCODE) --output $(OUTPUT)/result.json

.PHONY: b-debug-variables-check
b-debug-variables-check: $(CONTEXT_TOOL)
	taskset -c 16-19 prlimit --as=4294967296 -- python3 $(ROOT)/kprog/test/check_b_debug_variables.py --tool $(CONTEXT_TOOL) --previous /workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds --build /var/tmp/kprog-tmp/perf/b-debug-variables --output $(OUTPUT)

.PHONY: memory-b-continuation-check
memory-b-continuation-check: $(CONTEXT_TOOL)
	taskset -c 16-19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_memory_b_pipeline.py --frontend $(FRONTEND) --object $(REFERENCE_OBJECT) --bounds $(CONTEXT_TOOL) --output $(OUTPUT)

# Audit the published canonical linker; do not rebuild it during artifact analysis.
KATRAN_LINK_PLAN ?=
KATRAN_AUDIT_JIT ?=
.PHONY: katran-helper-audit
katran-helper-audit:
	taskset -c 16-19 prlimit --as=2147483648 -- python3 $(ROOT)/kprog/test/audit_native_helper_sites.py --native $(ROOT)/corpus/results/katran-c-hdr-20261115/objects/balancer.native.o --symbol balancer_ingress --linker $(LINKER_BINARY) $(if $(KATRAN_LINK_PLAN),--link-plan $(KATRAN_LINK_PLAN),) $(if $(KATRAN_AUDIT_JIT),--jit-capture $(KATRAN_AUDIT_JIT) --jit-program 16,) --output $(OUTPUT)

.PHONY: reference-helper-intervals
reference-helper-intervals:
	python3 $(ROOT)/kprog/test/compare_helper_intervals.py $(HELPER_INTERVAL_ARGS) --output $(OUTPUT)

.PHONY: clock-kernel-facts
clock-kernel-facts:
	$(MAKE) -r -C $(ROOT)/kprog/libnativeloader helper-context-kernel-input HELPER_BUILD=/var/tmp/kprog-tmp/perf/helper-context
	$(MAKE) -r -C $(ROOT)/kprog/libnativeloader helper-context-kernel-kvm HELPER_BUILD=/var/tmp/kprog-tmp/perf/helper-context HELPER_KERNEL_OUTPUT=$(OUTPUT)

.PHONY: image-tool-inventory
image-tool-inventory:
	python3 $(ROOT)/kprog/test/image_tool_inventory.py --image $(ROOT)/.cache/container-images/x86_64-runner-runtime.image.tar --output $(OUTPUT)/tool-inventory.json

HELPER_AUDIT_BUILD := /var/tmp/kprog-tmp/perf/helper-audit
HELPER_AUDIT_PLAN ?= /workspaces/kprog-raw/perf/20261115-clock-lto/kernel-facts/clock.link-plan.json
.PHONY: clock-plan-audit
clock-plan-audit:
	install -d $(HELPER_AUDIT_BUILD) $(OUTPUT)
	clang-18 -target x86_64-linux-gnu -O3 -march=native -fPIC -foptimize-sibling-calls -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector -c $(ROOT)/kprog/test/native_clock_audit.c -o $(HELPER_AUDIT_BUILD)/clock.native.o
	taskset -c 16-19 prlimit --as=2147483648 -- python3 $(ROOT)/kprog/test/audit_native_helper_sites.py --native $(HELPER_AUDIT_BUILD)/clock.native.o --symbol clock_audit --linker $(LINKER_BINARY) --link-plan $(HELPER_AUDIT_PLAN) --output $(OUTPUT)

$(BUILD)/native-map-relocs: $(ROOT)/kprog/test/native_image_map_reloc.c
	install -d $(BUILD)
	$(CC) -O2 -Wall -Wextra -Werror -D__EXPORTED_HEADERS__ -I$(ROOT)/vendor/linux-framework/include/uapi -I$(LIBBPF_PREFIX)/include $< $(LIBBPF_LIBRARY) -lelf -lz -o $@

.PHONY: native-map-relocs guest-native-map-relocs
native-map-relocs: $(BUILD)/native-map-relocs
	install -d $(OUTPUT)
	sha256sum $(KDIR)/arch/x86/boot/bzImage $(ROOT)/kinsn/module/x86/build/bpf_x86_native_lab.ko $(BUILD)/native-map-relocs $(KERNEL_LAYOUT) > $(OUTPUT)/input-sha256.txt
	taskset -c 16-17 prlimit --as=8589934592 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rodir $(OUTPUT)/inputs=$(BUILD) --rodir $(OUTPUT)/layout=$(KERNEL_LAYOUT_BUILD) --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/native-relocations.mk guest-native-map-relocs OUTPUT=$(OUTPUT)'

guest-native-map-relocs:
	mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod $(ROOT)/kinsn/module/x86/build/bpf_x86_native_lab.ko
	$(OUTPUT)/inputs/native-map-relocs $$(python3 -c 'import json; print(json.load(open("$(OUTPUT)/layout/kernel-layout.json"))["array"]["value"])') > $(OUTPUT)/result.jsonl 2> $(OUTPUT)/verifier.log

.PHONY: katran-body-profile
katran-body-profile:
	install -d $(OUTPUT)
	$(MAKE) -C $(ROOT) kvm-host-cpu
	flock -x /workspaces/.agent-state/kprog-lanes/locks/timing flock -s /workspaces/.agent-state/kprog-lanes/locks/image prlimit --as=103079215104 -- python3 $(ROOT)/kprog/perf/profile/phase-profile.py run --app katran --seconds 60 --cpus 0-7 --vcpus 8 --memory 64G --freq 999 --out $(OUTPUT)/profile --annotate 0 --state-root /var/tmp/kprog-tmp/perf/katran-body-profile --perf /var/tmp/kprog-tmp/C/perf-build/perf --persist-output

.PHONY: profile-input-smoke
profile-input-smoke:
	install -d /var/tmp/kprog-tmp/perf/profile-input-smoke $(OUTPUT)
	ln -sfn /var/tmp/perf-input/perf /var/tmp/kprog-tmp/perf/profile-input-smoke/perf
	ln -sfn $(ROOT)/kinsn/module/x86/build/bpf_x86_native_lab.ko /var/tmp/kprog-tmp/perf/profile-input-smoke/bpf_x86_native_lab.ko
	ln -sfn $(ROOT)/.cache/container-images/x86_64-runner-runtime.image.tar /var/tmp/kprog-tmp/perf/profile-input-smoke/runtime.image.tar
	flock -s /workspaces/.agent-state/kprog-lanes/locks/image taskset -c 16-17 prlimit --as=8589934592 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /var/tmp=/var/tmp/kprog-tmp/perf/profile-input-smoke --rodir /var/tmp/perf-input=/var/tmp/kprog-tmp/C/perf-build --rwdir $(OUTPUT) --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'set -eu; test -x /var/tmp/perf; test -r /var/tmp/runtime.image.tar; test -r /var/tmp/bpf_x86_native_lab.ko; /var/tmp/perf --version > $(OUTPUT)/perf-version.txt; stat -Lc "%F %s %n" /var/tmp/perf /var/tmp/runtime.image.tar /var/tmp/bpf_x86_native_lab.ko > $(OUTPUT)/guest-inputs.txt'

.PHONY: katran-profile-analysis
katran-profile-analysis:
	taskset -c 8-11 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/perf/profile/jit-window-costs.py --directory /workspaces/kprog-raw/perf/20261115-katran-body-profile-retry2/profile --run $(ROOT)/corpus/results/x86_kvm_corpus_20261115_201355_537645 --perf /var/tmp/kprog-tmp/C/perf-build/perf --app katran --output $(OUTPUT)

.PHONY: katran-source-costs
katran-source-costs:
	python3 $(ROOT)/kprog/perf/profile/source-costs.py --analysis /workspaces/kprog-raw/perf/20261115-katran-body-profile-retry2/analysis-callers/result.json --source-map /workspaces/kprog-raw/perf/20261115-katran-body-profile-retry2/source-audit-profile-facts/jit-source-map.json --baseline-capture /workspaces/kprog-raw/perf/20261115-katran-body-profile-retry2/profile/baseline.jit-lines.json --output $(OUTPUT)

.PHONY: katran-hot-instructions
katran-hot-instructions:
	taskset -c 8-11 prlimit --as=2147483648 -- python3 $(ROOT)/kprog/perf/profile/hot-jit-instructions.py --capture /workspaces/kprog-raw/perf/20261115-katran-body-profile-retry2/profile --analysis /workspaces/kprog-raw/perf/20261115-katran-body-profile-retry2/analysis-callers/result.json --source-map /workspaces/kprog-raw/perf/20261115-katran-body-profile-retry2/source-audit-profile-facts/jit-source-map.json --output $(OUTPUT)

.PHONY: relative-schedule-replay
relative-schedule-replay:
	taskset -c 16-18 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/replay_relative_schedule.py --archive $(SCHEDULE_ARCHIVE) --build /var/tmp/kprog-tmp/perf/relative-schedule --output $(OUTPUT)

.PHONY: generator-profile
generator-profile:
	taskset -c 16-18 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/profile_sim_generation.py --archive $(SCHEDULE_ARCHIVE) --build /var/tmp/kprog-tmp/perf/relative-schedule --output $(OUTPUT)

.PHONY: loop-pointer-analysis
loop-pointer-analysis:
	taskset -c $(CHECK_CPUS) prlimit --as=8589934592 -- python3 $(ROOT)/kprog/test/check_loop_pointer_analysis.py --build /var/tmp/kprog-tmp/perf/loop-pointer-analysis --output $(OUTPUT) --linker $(LINKER_BINARY) $(LOOP_POINTER_ARGS)

.PHONY: loop-pointer-debug
loop-pointer-debug:
	taskset -c 16-18 prlimit --as=8589934592 -- gdb --batch -ex run -ex 'thread apply all bt' --args python3 $(ROOT)/kprog/test/check_loop_pointer_analysis.py --build /var/tmp/kprog-tmp/perf/loop-pointer-analysis --output $(OUTPUT) --linker $(LINKER_BINARY) $(LOOP_POINTER_ARGS)

.PHONY: relative-schedule-b
relative-schedule-b: $(CONTEXT_TOOL)
	taskset -c 16-18 prlimit --as=17179869184 -- python3 $(ROOT)/kprog/test/replay_relative_schedule.py --archive $(SCHEDULE_ARCHIVE) --build /var/tmp/kprog-tmp/perf/relative-schedule --output $(OUTPUT) --compile --bounds $(CONTEXT_TOOL)

.PHONY: relative-schedule-stock guest-relative-schedule-stock
SCHEDULE_SOURCE ?= $(ROOT)/vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64
SCHEDULE_SYMBOL ?= perf_unwind_native
relative-schedule-stock:
	install -d $(OUTPUT) $(OUTPUT)/inputs
	python3 -c 'import pathlib,tarfile; build=pathlib.Path("/var/tmp/kprog-tmp/perf/relative-schedule"); archive=tarfile.open("$(SCHEDULE_ARCHIVE)"); fields={"kernel.native.o":"replay.native.o","generation.metadata.json":"replay.metadata.json","kernel.facts.json":"replay.context.json"}; [(build/name).write_bytes(archive.extractfile("request/"+source).read()) for source,name in fields.items()]'
	flock -s /workspaces/.agent-state/kprog-lanes/locks/image taskset -c 16-18 prlimit --as=17179869184 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUTPUT) --rodir $(OUTPUT)/inputs=/var/tmp/kprog-tmp/perf/relative-schedule --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 8G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/native-relocations.mk guest-relative-schedule-stock OUTPUT=$(OUTPUT) SCHEDULE_SOURCE=$(SCHEDULE_SOURCE) SCHEDULE_SYMBOL=$(SCHEDULE_SYMBOL)'

guest-relative-schedule-stock:
	mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	mountpoint -q /sys/fs/bpf || mount -t bpf bpffs /sys/fs/bpf
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	python3 $(ROOT)/kprog/test/verify_retained_proof.py --native $(OUTPUT)/inputs/replay.native.o --metadata $(OUTPUT)/inputs/replay.metadata.json --context $(OUTPUT)/inputs/replay.context.json --source $(SCHEDULE_SOURCE) --proof $(OUTPUT)/inputs/replay.bpf.o --symbol $(SCHEDULE_SYMBOL) --linker $(LINKER_BINARY) --output $(OUTPUT)/replay

.PHONY: string-pool-check string-pool-kernel guest-string-pool
string-pool-check:
	taskset -c 16-18 prlimit --as=8589934592 -- $(MAKE) -C $(ROOT)/kprog/libnativeloader entry-data-check CXX=clang++-18 ENTRY_DATA_OUTPUT=$(OUTPUT)/host ENTRY_DATA_REAL_PROOF=$(ROOT)/vendor/build/native-bpf/x86/7.0.0-rc2+/native/tracee/tracee.native.o

string-pool-kernel: string-pool-check
	install -d $(OUTPUT)/kernel $(OUTPUT)/test-inputs
	flock -s /workspaces/.agent-state/kprog-lanes/locks/image taskset -c 16-18 prlimit --as=8589934592 -- vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(OUTPUT) --rodir $(OUTPUT)/test-inputs=/var/tmp/kprog-tmp/verified/entry-data --overlay-rwdir /tmp --disable-monitor --cpus 1 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -r -f kprog/test/native-relocations.mk guest-string-pool OUTPUT=$(OUTPUT)'

guest-string-pool:
	mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	$(OUTPUT)/test-inputs/entry-data kernel $(OUTPUT)/test-inputs/fixture.o $(LINKER_BINARY) $(OUTPUT)/kernel $(OUTPUT)/host/existing.proof.o
