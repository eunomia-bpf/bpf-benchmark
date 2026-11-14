BUILD_DIR ?= build
SUBPROCESS_BUILD ?= /var/tmp/kprog-tmp/verified/loader-subprocess
SUBPROCESS_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-loader-spawn/functional
TIMING_BUILD ?= /var/tmp/kprog-tmp/verified/loader-timings
TIMING_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-loader-timings/functional
REPO_ROOT := $(abspath ../..)
LIBBPF_PREFIX ?= $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix
LIBBPF_LIBRARY ?= $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a
KERNEL_OFFSETS_INCLUDE ?= $(REPO_ROOT)/micro/programs/build-x86
SERVICE_RUN ?= $(abspath $(BUILD_DIR))/trusted-service-client $(abspath $(BUILD_DIR))/trusted-native.o
HELPER_BUILD ?= /var/tmp/kprog-tmp/verified/helper-context
HELPER_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-helper-context/functional
HELPER_KERNEL_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-helper-context/kernel
HELPER_KERNEL_MODULE ?= /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
REFRESH_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-shared-refresh
REFRESH_OPERATION ?= full
IMAGE_INVENTORY_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-kfunc-refresh/native-inputs.json

DATA_LAYOUT_BUILD ?= /var/tmp/kprog-tmp/verified/data-layout
DATA_LAYOUT_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-data-layout/host
DATA_LAYOUT_KERNEL_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-data-layout/kernel
ENTRY_DATA_BUILD ?= /var/tmp/kprog-tmp/verified/entry-data
ENTRY_DATA_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-entry-data/host
ENTRY_DATA_KERNEL_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-entry-data/kernel
ENTRY_DATA_REAL_PROOF ?= /var/tmp/kprog-tmp/perf/cilium-config-symbols/bpf_lxc-roundtrip/tail_no_service_ipv4.proof.o
ENTRY_DATA_LINKER ?= $(REPO_ROOT)/kprog/x86/native_lab/native_link/target/release/native-link
DIRECT_TAIL_BUILD ?= /var/tmp/kprog-tmp/verified/direct-tail
DIRECT_TAIL_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-direct-tail/host
FRAME_BUILD ?= /var/tmp/kprog-tmp/verified/frame-pointer
FRAME_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-frame-pointer/kernel
FRAME_LINKER ?= $(DIRECT_TAIL_BUILD)/cargo/debug/native-link
SOURCE_MAP_BUILD ?= /var/tmp/kprog-tmp/verified/source-maps
SOURCE_MAP_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-source-maps/host
SOURCE_MAP_KERNEL_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-source-maps/kernel
SOURCE_MAP_LOADER ?= /workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader
SOURCE_MAP_VM_MEMORY ?= 2G
SERVICE_EXECUTION_ARGS ?=
CHECKED_COMPILER_BASE ?= /workspaces/.agent-state/kprog-ck/verified-compiler
CHECKED_COMPILER_STAGE_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-checked-compiler-stage/stage
CHECKED_COMPILER_SERVICE_ARGS = --execution-mode checked-sim-c --sim-native-compiler $(CHECKED_COMPILER_BASE)/compile-sim-ir --sim-context-compiler $(CHECKED_COMPILER_BASE)/context-lower --sim-public-layout $(CHECKED_COMPILER_BASE)/public-layout.json --sim-physical-layout $(CHECKED_COMPILER_BASE)/physical-layout.json --sim-bounds-compiler $(CHECKED_COMPILER_BASE)/packet-bounds
CHECKED_SIM_BUILD ?= /var/tmp/kprog-tmp/verified/checked-sim
CHECKED_SIM_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-checked-sim/host
CHECKED_SIM_KERNEL_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-checked-sim/kernel
LTO_FAULT_BUILD ?= /var/tmp/kprog-tmp/verified/lto-fault
LTO_FAULT_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-lto-fault/host
CHECKED_PACKET_BUILD ?= /var/tmp/kprog-tmp/verified/checked-packet
CHECKED_PACKET_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-checked-packet/host
CHECKED_PACKET_KERNEL_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-checked-packet/kernel
CHECKED_PACKET_VMLINUX ?= $(REPO_ROOT)/vendor/bpf/targets/x86/$(shell cat /workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release)/vmlinux.h
PACKET_LAYOUT_REFRESH_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-boot-packet-layout/refresh
PACKET_LAYOUT_BPFTOOL ?= $(REPO_ROOT)/vendor/build/x86/bpftool/bin/bpftool
CENSUS_CHECKPOINT_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-integration-checkpoint/snapshot
CENSUS_CHECKPOINT_QUEUES ?= /workspaces/kprog-raw/verified/20261114-kfunc-refresh/queue-0 /workspaces/kprog-raw/verified/20261114-kfunc-refresh/queue-1 /workspaces/kprog-raw/verified/20261114-kfunc-refresh/queue-2
CENSUS_PUBLISH_BASE ?= /workspaces/kprog-raw/verified/20261114-kfunc-refresh/cumulative-outcomes.jsonl
CENSUS_PUBLISH_QUEUES ?= $(CENSUS_CHECKPOINT_OUTPUT)/queue-0/outcomes.jsonl $(CENSUS_CHECKPOINT_OUTPUT)/queue-1/outcomes.jsonl $(CENSUS_CHECKPOINT_OUTPUT)/queue-2/outcomes.jsonl
CENSUS_PUBLISH_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-integration-checkpoint/publication
CENSUS_PUBLISH_DESTINATION ?= $(REPO_ROOT)/kprog/results/verified_20261114/census-checkpoint-complete
VERIFIED_APP_RAW ?= /workspaces/kprog-raw/verified/20261114-integrated-bcc
VERIFIED_APP ?= bcc/set
VERIFIED_APP_CORPUS ?= $(REPO_ROOT)/corpus/results/x86_kvm_corpus_20261114_043432_568815
VERIFIED_APP_CAPTURES ?= $(REPO_ROOT)/corpus/results/verified-captures-07xostih
VERIFIED_APP_PREFIX ?= $(REPO_ROOT)/kprog/results/verified_20261114/integrated-bcc
VERIFIED_APP_EXIT_FILE ?= exit-code
MAP_BOUNDS_CLASS_WORKLIST ?= $(REPO_ROOT)/kprog/results/verified_20261114/map-bounds-class-triage.json
MAP_BOUNDS_CLASS_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-map-bounds-class/native-evidence
CLASS_INSPECT_ARGS ?=
SELF_COMPARE_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-self-compare/before
SELF_COMPARE_BUILD ?= /var/tmp/kprog-tmp/verified/self-compare
SELF_COMPARE_KERNEL_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-self-compare/kernel
SELF_COMPARE_BEFORE ?= /workspaces/kprog-raw/verified/20261114-self-compare/before/fixture.bpf.o
SELF_COMPARE_AFTER ?= /workspaces/kprog-raw/verified/20261114-self-compare/after-initialized/fixture.bpf.o
KFUNC_BUILD ?= /var/tmp/kprog-tmp/verified/kfunc
KFUNC_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-kfunc/host
KFUNC_KERNEL_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-kfunc/kernel
KFUNC_BPF ?= /workspaces/kprog-raw/perf/20261113-tetragon-same-source/build-evidence/bpf_generic_kprobe_v61.direct.bpf.o
KFUNC_NATIVE ?= /var/tmp/kprog-tmp/perf/tetragon-same-source/bpf_generic_kprobe_v61.native.o
KERNEL_ELF_RESTORE_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-kernel-elf-restore
KFUNC_MODEL_OUTPUT ?= /workspaces/kprog-raw/verified/20261113-kfunc/model

.PHONY: kfunc-model-check
kfunc-model-check:
	install -d "$(KFUNC_MODEL_OUTPUT)"
	clang-18 -O2 -fPIC -c ../test/kfunc_model_fixture.c -o "$(KFUNC_MODEL_OUTPUT)/fixture.native.o"
	CLANG="$(REPO_ROOT)/kprog/stock-path/bin/clang" python3 ../test/check_kfunc_model.py "$(KFUNC_MODEL_OUTPUT)/fixture.native.o" \
		/workspaces/.agent-state/kprog-ck/build-x86/vmlinux "$(KFUNC_MODEL_OUTPUT)"

# Invoke under the exclusive image/base lock; the unchanged boot is authoritative.
.PHONY: kernel-elf-from-boot
kernel-elf-from-boot:
	install -d "$(KERNEL_ELF_RESTORE_OUTPUT)"
	sha256sum /workspaces/.agent-state/kprog-ck/build-x86/vmlinux \
		/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage > "$(KERNEL_ELF_RESTORE_OUTPUT)/before.sha256"
	"$(REPO_ROOT)/vendor/linux-framework/scripts/extract-vmlinux" \
		/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage > /workspaces/.agent-state/kprog-ck/build-x86/vmlinux
	sha256sum /workspaces/.agent-state/kprog-ck/build-x86/vmlinux \
		/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage > "$(KERNEL_ELF_RESTORE_OUTPUT)/after.sha256"

.PHONY: kfunc-inputs kfunc-check kfunc-kernel-kvm guest-kfunc kfunc-model-kernel-kvm
kfunc-model-kernel-kvm:
	install -d "$(KFUNC_KERNEL_OUTPUT)"
	install -m 0644 "$(KFUNC_MODEL_OUTPUT)/generated/trusted_x86.bpf.o" "$(KFUNC_KERNEL_OUTPUT)/model.bpf.o"
	install -m 0644 "$(KFUNC_MODEL_OUTPUT)/iterator/trusted_x86.bpf.o" "$(KFUNC_KERNEL_OUTPUT)/iterator.bpf.o"
	$(MAKE) kfunc-kernel-kvm KFUNC_MODEL_PROOF="$(KFUNC_KERNEL_OUTPUT)/model.bpf.o $(KFUNC_KERNEL_OUTPUT)/iterator.bpf.o"

kfunc-inputs:
	install -d "$(KFUNC_BUILD)"
	clang-18 -O2 -fPIC -c ../test/native_kfunc_fixture.c -o "$(KFUNC_BUILD)/weak.o"
	clang-18 -O2 -fPIC -DKFUNC_PRESENT_STRONG -c ../test/native_kfunc_fixture.c -o "$(KFUNC_BUILD)/strong.o"
	clang-18 -target bpf -O2 -g -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		-I"$(REPO_ROOT)/vendor/libbpf/src" -I/usr/include/x86_64-linux-gnu \
		-c ../test/kfunc_proof_fixture.bpf.c -o "$(KFUNC_BUILD)/proof.bpf.o"
	$(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections \
		-Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" \
		-I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../test/native_loader_kfunc.cpp -Wl,--gc-sections "$(LIBBPF_LIBRARY)" -lelf -lz -ldl -pthread \
		-o "$(KFUNC_BUILD)/kfunc"

kfunc-check: kfunc-inputs
	install -d "$(KFUNC_OUTPUT)"
	"$(KFUNC_BUILD)/kfunc" host "$(KFUNC_BUILD)/weak.o" "$(KFUNC_BUILD)/strong.o" \
		"$(KFUNC_BPF)" "$(KFUNC_NATIVE)" /workspaces/.agent-state/kprog-ck/build-x86/vmlinux "$(KFUNC_OUTPUT)" "$(KFUNC_BUILD)/proof.bpf.o"

kfunc-kernel-kvm:
	install -d "$(KFUNC_KERNEL_OUTPUT)"
	install -m 0755 "$(KFUNC_BUILD)/kfunc" "$(KFUNC_KERNEL_OUTPUT)/kfunc"
	install -m 0644 "$(KFUNC_BUILD)/weak.o" "$(KFUNC_BUILD)/strong.o" "$(KFUNC_KERNEL_OUTPUT)/"
	install -m 0644 "$(KFUNC_BUILD)/proof.bpf.o" "$(KFUNC_KERNEL_OUTPUT)/proof.bpf.o"
	install -m 0644 "$(KFUNC_BPF)" "$(KFUNC_KERNEL_OUTPUT)/source.bpf.o"
	install -m 0644 "$(KFUNC_NATIVE)" "$(KFUNC_KERNEL_OUTPUT)/source.native.o"
	taskset -c 13 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(KFUNC_KERNEL_OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-kfunc KFUNC_KERNEL_OUTPUT=$(KFUNC_KERNEL_OUTPUT) KFUNC_MODEL_PROOF="$(KFUNC_MODEL_PROOF)"'

guest-kfunc:
	"$(KFUNC_KERNEL_OUTPUT)/kfunc" kernel "$(KFUNC_KERNEL_OUTPUT)/weak.o" "$(KFUNC_KERNEL_OUTPUT)/strong.o" \
		"$(KFUNC_KERNEL_OUTPUT)/source.bpf.o" "$(KFUNC_KERNEL_OUTPUT)/source.native.o" \
		/sys/kernel/btf/vmlinux "$(KFUNC_KERNEL_OUTPUT)" "$(KFUNC_KERNEL_OUTPUT)/proof.bpf.o" $(KFUNC_MODEL_PROOF)

.PHONY: source-maps-check
source-maps-check:
	install -d "$(SOURCE_MAP_BUILD)" "$(SOURCE_MAP_OUTPUT)"
	clang-18 -O2 -g -target bpf -I/usr/include/x86_64-linux-gnu -I"$(LIBBPF_PREFIX)/include/bpf" \
		-c ../test/source_maps_fixture.c -o "$(SOURCE_MAP_BUILD)/fixture.bpf.o"
	clang-18 -O2 -fPIC -mno-red-zone -mgeneral-regs-only -fomit-frame-pointer -I"$(LIBBPF_PREFIX)/include/bpf" \
		-c ../test/source_maps_fixture.c -o "$(SOURCE_MAP_BUILD)/fixture.native.o"
	$(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections \
		-Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" \
		-I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../test/native_loader_source_maps.cpp -Wl,--gc-sections "$(LIBBPF_LIBRARY)" -lelf -lz -ldl -pthread \
		-o "$(SOURCE_MAP_BUILD)/source-maps"
	install -m 0644 "$(SOURCE_MAP_BUILD)/fixture.bpf.o" "$(SOURCE_MAP_BUILD)/fixture.native.o" "$(SOURCE_MAP_OUTPUT)/"
	"$(SOURCE_MAP_BUILD)/source-maps" "$(SOURCE_MAP_OUTPUT)/fixture.bpf.o" \
		"$(SOURCE_MAP_OUTPUT)/fixture.native.o" "$(SOURCE_MAP_OUTPUT)"

.PHONY: source-maps-kvm guest-source-maps
source-maps-kvm:
	install -d "$(SOURCE_MAP_KERNEL_OUTPUT)"
	install -m 0755 "$(SOURCE_MAP_BUILD)/source-maps" "$(SOURCE_MAP_KERNEL_OUTPUT)/source-maps"
	install -m 0644 "$(SOURCE_MAP_BUILD)/fixture.bpf.o" "$(SOURCE_MAP_BUILD)/fixture.native.o" "$(SOURCE_MAP_KERNEL_OUTPUT)/"
	install -m 0755 "$(FRAME_LINKER)" "$(SOURCE_MAP_KERNEL_OUTPUT)/native-link.real"
	taskset -c 14 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(SOURCE_MAP_KERNEL_OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory $(SOURCE_MAP_VM_MEMORY) --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-source-maps SOURCE_MAP_KERNEL_OUTPUT=$(SOURCE_MAP_KERNEL_OUTPUT) SOURCE_MAP_LOADER=$(SOURCE_MAP_LOADER) SERVICE_EXECUTION_ARGS="$(SERVICE_EXECUTION_ARGS)"'

guest-source-maps:
	CLANG="$(REPO_ROOT)/kprog/stock-path/bin/clang" KPROG_FRAME_LINKER="$(SOURCE_MAP_KERNEL_OUTPUT)/native-link.real" \
		python3 ../trusted_service.py --arch 1 \
		--endpoint /sys/kernel/debug/bpf_x86_native_lab/specializer \
		--module /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko \
		--state "$(SOURCE_MAP_KERNEL_OUTPUT)/state" --results "$(SOURCE_MAP_KERNEL_OUTPUT)/service.tar.gz" \
		--native-link "$(REPO_ROOT)/kprog/test/tail_call_frame/native-link.sh" \
		--loader "$(SOURCE_MAP_LOADER)" $(SERVICE_EXECUTION_ARGS) \
		--run "$(SOURCE_MAP_KERNEL_OUTPUT)/source-maps" kernel "$(SOURCE_MAP_KERNEL_OUTPUT)/fixture.bpf.o" \
		"$(SOURCE_MAP_KERNEL_OUTPUT)/fixture.native.o" "$(REPO_ROOT)/kprog/test/tail_call_frame/native-link.sh" "$(SOURCE_MAP_KERNEL_OUTPUT)"

.PHONY: checked-sim-inputs checked-sim-check checked-sim-kvm checked-sim-stage
.PHONY: lto-fault-check
lto-fault-check:
	install -d "$(LTO_FAULT_BUILD)"
	clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../x86/compile_sim_ir.cpp -o "$(LTO_FAULT_BUILD)/compile-sim-ir" \
		$$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)
	python3 ../test/check_lto_fault.py "$(LTO_FAULT_BUILD)/compile-sim-ir" "$(LTO_FAULT_OUTPUT)"

# Stage the tools already exercised by checked-packet-check/kvm. The caller
# holds the image writer lock after existing service guests have exited.
# The registered service runs outside the app image and reads this sole base.
checked-sim-stage:
	install -d "$(CHECKED_COMPILER_BASE)" "$(CHECKED_COMPILER_STAGE_OUTPUT)"
	sha256sum "$(CHECKED_SIM_BUILD)/compile-sim-ir" "$(CHECKED_PACKET_BUILD)/context-lower" \
		"$(CHECKED_PACKET_BUILD)/packet-bounds" "$(CHECKED_PACKET_BUILD)/public-layout" \
		"$(CHECKED_PACKET_BUILD)/physical-layout" > "$(CHECKED_COMPILER_STAGE_OUTPUT)/input-tool-sha256"
	install -m 0755 "$(CHECKED_SIM_BUILD)/compile-sim-ir" "$(CHECKED_PACKET_BUILD)/context-lower" \
		"$(CHECKED_PACKET_BUILD)/packet-bounds" "$(CHECKED_PACKET_BUILD)/public-layout" \
		"$(CHECKED_PACKET_BUILD)/physical-layout" "$(CHECKED_COMPILER_BASE)/"
	"$(CHECKED_COMPILER_BASE)/public-layout" > "$(CHECKED_COMPILER_BASE)/public-layout.json"
	"$(CHECKED_COMPILER_BASE)/physical-layout" > "$(CHECKED_COMPILER_BASE)/physical-layout.json"
	sha256sum "$(CHECKED_COMPILER_BASE)"/* > "$(CHECKED_COMPILER_STAGE_OUTPUT)/tool-sha256"
	sha256sum ../x86/compile_sim_ir.cpp ../x86/packet_bounds_ir.cpp \
		../perf/native-context/socket-context-lower.cpp ../perf/native-context/packet-public-layout.c \
		../perf/native-context/packet-physical-layout.c "$(CHECKED_PACKET_VMLINUX)" \
		> "$(CHECKED_COMPILER_STAGE_OUTPUT)/source-at-stage-sha256"
	install -m 0644 "$(CHECKED_COMPILER_BASE)/public-layout.json" "$(CHECKED_COMPILER_BASE)/physical-layout.json" \
		"$(CHECKED_COMPILER_STAGE_OUTPUT)/"
	printf '%s\n' '$(CHECKED_COMPILER_SERVICE_ARGS)' > "$(CHECKED_COMPILER_STAGE_OUTPUT)/service-args.txt"
	date -u +%FT%TZ > "$(CHECKED_COMPILER_STAGE_OUTPUT)/finished"
	printf -- '- LANE VERIFIED %s: BASE STAGED checked simulator compiler/context/bounds tools in %s; hashes/layouts/args %s. Sole image/kernel unchanged; actual app execution with this opt-in mode remains separate.\n' \
		"$$(date -u +%FT%TZ)" "$(CHECKED_COMPILER_BASE)" "$(CHECKED_COMPILER_STAGE_OUTPUT)" \
		>> /workspaces/.agent-state/kprog-lanes/COORDINATION.md

checked-sim-inputs:
	install -d "$(CHECKED_SIM_BUILD)"
	clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../x86/compile_sim_ir.cpp -o "$(CHECKED_SIM_BUILD)/compile-sim-ir" \
		$$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)
	$(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections \
		-Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" \
		-I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		src/native_loader.cpp ../trusted_loader.cpp -Wl,--gc-sections \
		"$(LIBBPF_LIBRARY)" -lelf -lz -ldl -pthread -o "$(CHECKED_SIM_BUILD)/trusted-native-loader"

checked-sim-check: checked-sim-inputs
	CLANG="$(REPO_ROOT)/kprog/stock-path/bin/clang" python3 ../test/check_checked_simulator.py \
		"$(CHECKED_SIM_BUILD)/compile-sim-ir" "$(FRAME_LINKER)" "$(SOURCE_MAP_BUILD)/fixture.native.o" "$(CHECKED_SIM_OUTPUT)"
	python3 ../test/check_trusted_service.py TrustedApplicationBootstrap

checked-sim-kvm:
	install -d "$(CHECKED_SIM_KERNEL_OUTPUT)"
	install -m 0755 "$(CHECKED_SIM_BUILD)/compile-sim-ir" "$(CHECKED_SIM_BUILD)/trusted-native-loader" "$(CHECKED_SIM_KERNEL_OUTPUT)/"
	$(MAKE) source-maps-kvm SOURCE_MAP_KERNEL_OUTPUT="$(CHECKED_SIM_KERNEL_OUTPUT)" \
		SOURCE_MAP_LOADER="$(CHECKED_SIM_KERNEL_OUTPUT)/trusted-native-loader" \
		SERVICE_EXECUTION_ARGS="--execution-mode checked-sim-c --sim-native-compiler $(CHECKED_SIM_KERNEL_OUTPUT)/compile-sim-ir"

.PHONY: checked-packet-inputs checked-packet-check checked-packet-layout-refresh
# Rebuild only the generated target header and its packet-layout emitter. The
# caller holds imageEX after service guests exit; kernel/app/image builds stay
# untouched. No VMLINUX_BTF Make override can trigger an implicit ELF rebuild.
checked-packet-layout-refresh:
	install -d "$(PACKET_LAYOUT_REFRESH_OUTPUT)" "$(CHECKED_PACKET_BUILD)"
	sha256sum /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		/workspaces/.agent-state/kprog-ck/build-x86/vmlinux "$(CHECKED_PACKET_VMLINUX)" \
		> "$(PACKET_LAYOUT_REFRESH_OUTPUT)/before-core-header-sha256"
	install -m 0644 "$(CHECKED_COMPILER_BASE)/physical-layout.json" "$(PACKET_LAYOUT_REFRESH_OUTPUT)/before-layout.json"
	"$(PACKET_LAYOUT_BPFTOOL)" btf dump file /workspaces/.agent-state/kprog-ck/build-x86/vmlinux format c \
		> "$(CHECKED_PACKET_VMLINUX).tmp"
	mv -f "$(CHECKED_PACKET_VMLINUX).tmp" "$(CHECKED_PACKET_VMLINUX)"
	clang-18 -I"$(dir $(CHECKED_PACKET_VMLINUX))" ../perf/native-context/packet-physical-layout.c -o "$(CHECKED_PACKET_BUILD)/physical-layout"
	"$(CHECKED_PACKET_BUILD)/physical-layout" > "$(PACKET_LAYOUT_REFRESH_OUTPUT)/after-layout.json"
	$(MAKE) checked-sim-stage CHECKED_COMPILER_STAGE_OUTPUT="$(PACKET_LAYOUT_REFRESH_OUTPUT)/stage"
	sha256sum /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		/workspaces/.agent-state/kprog-ck/build-x86/vmlinux "$(CHECKED_PACKET_VMLINUX)" \
		> "$(PACKET_LAYOUT_REFRESH_OUTPUT)/after-core-header-sha256"
	printf -- '- %s VERIFIED: replaced sole generated target vmlinux.h from unchanged boot-matched ELF BTF, rebuilt packet physical-layout in place and restaged same-base compiler tools; raw before/after hashes/layouts %s. No kernel/app/image rebuild or raw deletion.\n' \
		"$$(date -u +%FT%TZ)" "$(PACKET_LAYOUT_REFRESH_OUTPUT)" >> "$(REPO_ROOT)/kprog/docs/cleanup-log.md"
	printf -- '- LANE VERIFIED %s: BASE packet-layout refreshed from boot-matched ELF BTF via the sole target header; before/after hashes/layouts %s. Kernel/native app objects/image unchanged; field deltas and affected subset execution to be collected separately.\n' \
		"$$(date -u +%FT%TZ)" "$(PACKET_LAYOUT_REFRESH_OUTPUT)" >> /workspaces/.agent-state/kprog-lanes/COORDINATION.md
	date -u +%FT%TZ > "$(PACKET_LAYOUT_REFRESH_OUTPUT)/finished"

checked-packet-inputs: checked-sim-inputs
	install -d "$(CHECKED_PACKET_BUILD)"
	clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../perf/native-context/socket-context-lower.cpp -o "$(CHECKED_PACKET_BUILD)/context-lower" \
		$$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis transformutils support --system-libs)
	clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../x86/packet_bounds_ir.cpp -o "$(CHECKED_PACKET_BUILD)/packet-bounds" \
		$$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)
	clang-18 -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" ../perf/native-context/packet-public-layout.c -o "$(CHECKED_PACKET_BUILD)/public-layout"
	clang-18 -I"$(dir $(CHECKED_PACKET_VMLINUX))" ../perf/native-context/packet-physical-layout.c -o "$(CHECKED_PACKET_BUILD)/physical-layout"
	clang-18 -O2 -fPIC -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-asynchronous-unwind-tables \
		-I"$(dir $(CHECKED_PACKET_VMLINUX))" -c ../test/checked_packet_native.c -o "$(CHECKED_PACKET_BUILD)/packet.native.o"
	clang-18 -target bpf -mcpu=v4 -O2 -g -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" -I"$(LIBBPF_PREFIX)/include/bpf" \
		-I/usr/include/x86_64-linux-gnu -c ../test/checked_packet.bpf.c -o "$(CHECKED_PACKET_BUILD)/source.bpf.o"
	clang-18 -c ../test/checked_packet_bad.S -o "$(CHECKED_PACKET_BUILD)/bad.native.o"
	$(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections \
		-Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" \
		-I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		src/native_loader.cpp ../test/checked_packet_client.cpp -Wl,--gc-sections \
		"$(LIBBPF_LIBRARY)" -lelf -lz -ldl -pthread -o "$(CHECKED_PACKET_BUILD)/client"

checked-packet-check: checked-packet-inputs
	install -d "$(CHECKED_PACKET_OUTPUT)"
	"$(CHECKED_PACKET_BUILD)/public-layout" > "$(CHECKED_PACKET_OUTPUT)/public-layout.json"
	"$(CHECKED_PACKET_BUILD)/physical-layout" > "$(CHECKED_PACKET_OUTPUT)/physical-layout.json"
	CLANG="$(REPO_ROOT)/kprog/stock-path/bin/clang" python3 ../test/check_checked_packet.py \
		"$(CHECKED_SIM_BUILD)/compile-sim-ir" "$(FRAME_LINKER)" "$(CHECKED_PACKET_BUILD)/context-lower" \
		"$(CHECKED_PACKET_OUTPUT)/public-layout.json" "$(CHECKED_PACKET_OUTPUT)/physical-layout.json" \
		"$(CHECKED_PACKET_BUILD)/packet.native.o" "$(CHECKED_PACKET_OUTPUT)/tests" "$(CHECKED_PACKET_BUILD)/packet-bounds"
	python3 ../test/check_packet_bounds.py "$(CHECKED_PACKET_BUILD)/packet-bounds" "$(CHECKED_SIM_BUILD)/compile-sim-ir" "$(CHECKED_PACKET_OUTPUT)/bounds-tests"
	python3 ../test/check_preprocess_stream.py "$(REPO_ROOT)/kprog/stock-path/bin/clang" "$(CHECKED_PACKET_OUTPUT)/preprocess-control"

.PHONY: checked-packet-kvm guest-checked-packet guest-checked-packet-case
checked-packet-kvm:
	install -d "$(CHECKED_PACKET_KERNEL_OUTPUT)"
	install -m 0755 "$(CHECKED_SIM_BUILD)/compile-sim-ir" "$(CHECKED_SIM_BUILD)/trusted-native-loader" \
		"$(CHECKED_PACKET_BUILD)/context-lower" "$(CHECKED_PACKET_BUILD)/packet-bounds" "$(CHECKED_PACKET_BUILD)/client" "$(CHECKED_PACKET_KERNEL_OUTPUT)/"
	install -m 0644 "$(CHECKED_PACKET_BUILD)/source.bpf.o" "$(CHECKED_PACKET_BUILD)/packet.native.o" \
		"$(CHECKED_PACKET_BUILD)/bad.native.o" "$(CHECKED_PACKET_KERNEL_OUTPUT)/"
	install -m 0755 "$(FRAME_LINKER)" "$(CHECKED_PACKET_KERNEL_OUTPUT)/native-link.real"
	"$(CHECKED_PACKET_BUILD)/public-layout" > "$(CHECKED_PACKET_KERNEL_OUTPUT)/public-layout.json"
	"$(CHECKED_PACKET_BUILD)/physical-layout" > "$(CHECKED_PACKET_KERNEL_OUTPUT)/physical-layout.json"
	taskset -c 14 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(CHECKED_PACKET_KERNEL_OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory $(SOURCE_MAP_VM_MEMORY) --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-checked-packet CHECKED_PACKET_KERNEL_OUTPUT=$(CHECKED_PACKET_KERNEL_OUTPUT)'

guest-checked-packet:
	python3 ../test/check_checked_packet_guest.py "$(CHECKED_PACKET_KERNEL_OUTPUT)"

guest-checked-packet-case:
	CLANG="$(REPO_ROOT)/kprog/stock-path/bin/clang" KPROG_FRAME_LINKER="$(CHECKED_PACKET_KERNEL_OUTPUT)/native-link.real" \
		python3 ../trusted_service.py --arch 1 --endpoint /sys/kernel/debug/bpf_x86_native_lab/specializer \
		--module /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko \
		--state "$(CHECKED_PACKET_KERNEL_OUTPUT)/$(CHECKED_PACKET_CASE)/state" \
		--results "$(CHECKED_PACKET_KERNEL_OUTPUT)/$(CHECKED_PACKET_CASE)/service.tar.gz" \
		--native-link "$(REPO_ROOT)/kprog/test/tail_call_frame/native-link.sh" \
		--loader "$(CHECKED_PACKET_KERNEL_OUTPUT)/trusted-native-loader" --execution-mode checked-sim-c \
		--sim-native-compiler "$(CHECKED_PACKET_KERNEL_OUTPUT)/compile-sim-ir" \
		--sim-context-compiler "$(CHECKED_PACKET_KERNEL_OUTPUT)/context-lower" \
		--sim-public-layout "$(CHECKED_PACKET_KERNEL_OUTPUT)/public-layout.json" \
		--sim-physical-layout "$(CHECKED_PACKET_KERNEL_OUTPUT)/physical-layout.json" \
		--sim-bounds-compiler "$(CHECKED_PACKET_KERNEL_OUTPUT)/packet-bounds" \
		--run "$(CHECKED_PACKET_KERNEL_OUTPUT)/client" "$(CHECKED_PACKET_KERNEL_OUTPUT)/source.bpf.o" \
		"$(CHECKED_PACKET_KERNEL_OUTPUT)/$(if $(filter reject,$(CHECKED_PACKET_CASE)),bad,packet).native.o" \
		"$(REPO_ROOT)/kprog/test/tail_call_frame/native-link.sh" "$(CHECKED_PACKET_CASE)" \
		"$(CHECKED_PACKET_KERNEL_OUTPUT)/$(CHECKED_PACKET_CASE)/execution.jsonl"

.PHONY: tail-frame-inputs tail-frame-kvm guest-tail-frame
tail-frame-inputs:
	install -d "$(FRAME_BUILD)"
	clang-18 -O2 -g -target bpf -I/usr/include/x86_64-linux-gnu -I"$(LIBBPF_PREFIX)/include/bpf" \
		-c ../test/tail_call_frame/program.c -o "$(FRAME_BUILD)/source.bpf.o"
	clang-18 -fPIC -c ../test/tail_call_frame/frame-pointer.S -o "$(FRAME_BUILD)/frame.native.o"
	$(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections \
		-Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" \
		-I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		src/native_loader.cpp ../test/tail_call_frame/client.cpp -Wl,--gc-sections \
		"$(LIBBPF_LIBRARY)" -lelf -lz -ldl -pthread -o "$(FRAME_BUILD)/client"

tail-frame-kvm:
	install -d "$(FRAME_OUTPUT)"
	install -m 0755 "$(FRAME_BUILD)/client" "$(FRAME_OUTPUT)/client"
	install -m 0644 "$(FRAME_BUILD)/source.bpf.o" "$(FRAME_BUILD)/frame.native.o" "$(FRAME_OUTPUT)/"
	install -m 0755 "$(FRAME_LINKER)" "$(FRAME_OUTPUT)/native-link.real"
	taskset -c 13 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(FRAME_OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-tail-frame FRAME_OUTPUT=$(FRAME_OUTPUT) FRAME_LINKER=$(FRAME_OUTPUT)/native-link.real'

guest-tail-frame:
	CLANG="$(REPO_ROOT)/kprog/stock-path/bin/clang" KPROG_FRAME_LINKER="$(FRAME_LINKER)" \
		python3 ../trusted_service.py --arch 1 \
		--endpoint /sys/kernel/debug/bpf_x86_native_lab/specializer \
		--module /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko \
		--state "$(FRAME_OUTPUT)/state" --results "$(FRAME_OUTPUT)/service.tar.gz" \
		--native-link "$(REPO_ROOT)/kprog/test/tail_call_frame/native-link.sh" \
		--loader /workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader \
		--run "$(FRAME_OUTPUT)/client" "$(FRAME_OUTPUT)/source.bpf.o" "$(FRAME_OUTPUT)/frame.native.o" \
		"$(REPO_ROOT)/kprog/test/tail_call_frame/native-link.sh" "$(FRAME_OUTPUT)/native-image.bin"

.PHONY: direct-tail-check
direct-tail-check:
	install -d "$(DIRECT_TAIL_BUILD)" "$(DIRECT_TAIL_OUTPUT)"
	CARGO_TARGET_DIR="$(DIRECT_TAIL_BUILD)/cargo" CARGO_BUILD_JOBS=1 CARGO_PROFILE_DEV_OPT_LEVEL=3 CARGO_PROFILE_DEV_DEBUG=0 \
		cargo test --manifest-path "$(REPO_ROOT)/kprog/x86/native_lab/native_link/Cargo.toml"
	CARGO_TARGET_DIR="$(DIRECT_TAIL_BUILD)/cargo" CARGO_BUILD_JOBS=1 CARGO_PROFILE_DEV_OPT_LEVEL=3 CARGO_PROFILE_DEV_DEBUG=0 \
		cargo build --manifest-path "$(REPO_ROOT)/kprog/x86/native_lab/native_link/Cargo.toml"
	clang-18 -fPIC -c ../test/native_direct_tail_fixture.S -o "$(DIRECT_TAIL_OUTPUT)/fixture.o"
	clang-18 -shared "$(DIRECT_TAIL_OUTPUT)/fixture.o" -o "$(DIRECT_TAIL_OUTPUT)/control.so"
	python3 ../test/check_native_direct_tail.py "$(DIRECT_TAIL_BUILD)/cargo/debug/native-link" \
		"$(DIRECT_TAIL_OUTPUT)/fixture.o" "$(DIRECT_TAIL_OUTPUT)/control.so" "$(ENTRY_DATA_LINKER)" "$(DIRECT_TAIL_OUTPUT)"

.PHONY: entry-data-inputs entry-data-check entry-data-kernel-kvm guest-entry-data
entry-data-inputs:
	install -d "$(ENTRY_DATA_BUILD)"
	clang-18 -O2 -fPIC -c ../test/native_entry_data_fixture.c -o "$(ENTRY_DATA_BUILD)/fixture.o"
	$(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections \
		-Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" \
		-I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../test/native_loader_entry_data.cpp -Wl,--gc-sections "$(LIBBPF_LIBRARY)" -lelf -lz -ldl -pthread \
		-o "$(ENTRY_DATA_BUILD)/entry-data"

entry-data-check: entry-data-inputs
	install -d "$(ENTRY_DATA_OUTPUT)"
	install -m 0644 "$(ENTRY_DATA_REAL_PROOF)" "$(ENTRY_DATA_OUTPUT)/existing.proof.o"
	"$(ENTRY_DATA_BUILD)/entry-data" host "$(ENTRY_DATA_BUILD)/fixture.o" "$(ENTRY_DATA_LINKER)" \
		"$(ENTRY_DATA_OUTPUT)" "$(ENTRY_DATA_OUTPUT)/existing.proof.o"

entry-data-kernel-kvm:
	install -d "$(ENTRY_DATA_KERNEL_OUTPUT)"
	install -m 0755 "$(ENTRY_DATA_BUILD)/entry-data" "$(ENTRY_DATA_KERNEL_OUTPUT)/entry-data"
	install -m 0644 "$(ENTRY_DATA_BUILD)/fixture.o" "$(ENTRY_DATA_KERNEL_OUTPUT)/fixture.o"
	install -m 0644 "$(ENTRY_DATA_REAL_PROOF)" "$(ENTRY_DATA_KERNEL_OUTPUT)/existing.proof.o"
	taskset -c 13 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(ENTRY_DATA_KERNEL_OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-entry-data ENTRY_DATA_KERNEL_OUTPUT=$(ENTRY_DATA_KERNEL_OUTPUT) ENTRY_DATA_LINKER=$(ENTRY_DATA_LINKER)'

guest-entry-data:
	mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	"$(ENTRY_DATA_KERNEL_OUTPUT)/entry-data" kernel "$(ENTRY_DATA_KERNEL_OUTPUT)/fixture.o" "$(ENTRY_DATA_LINKER)" \
		"$(ENTRY_DATA_KERNEL_OUTPUT)" "$(ENTRY_DATA_KERNEL_OUTPUT)/existing.proof.o"

.PHONY: data-layout-inputs data-layout-check data-layout-kernel-kvm guest-data-layout
data-layout-inputs:
	install -d "$(DATA_LAYOUT_BUILD)"
	clang-18 -O2 -fPIC -c ../test/native_data_layout_fixture.c -o "$(DATA_LAYOUT_BUILD)/fixture.o"
	$(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections \
		-Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" \
		-I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../test/native_loader_data_layout.cpp -Wl,--gc-sections "$(LIBBPF_LIBRARY)" -lelf -lz -ldl -pthread \
		-o "$(DATA_LAYOUT_BUILD)/data-layout"

data-layout-check: data-layout-inputs
	install -d "$(DATA_LAYOUT_OUTPUT)"
	"$(DATA_LAYOUT_BUILD)/data-layout" host "$(DATA_LAYOUT_BUILD)/fixture.o" "$(DATA_LAYOUT_OUTPUT)"

data-layout-kernel-kvm:
	install -d "$(DATA_LAYOUT_KERNEL_OUTPUT)"
	install -m 0755 "$(DATA_LAYOUT_BUILD)/data-layout" "$(DATA_LAYOUT_KERNEL_OUTPUT)/data-layout"
	install -m 0644 "$(DATA_LAYOUT_BUILD)/fixture.o" "$(DATA_LAYOUT_KERNEL_OUTPUT)/fixture.o"
	taskset -c 13 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(DATA_LAYOUT_KERNEL_OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-data-layout DATA_LAYOUT_KERNEL_OUTPUT=$(DATA_LAYOUT_KERNEL_OUTPUT)'

guest-data-layout:
	mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	"$(DATA_LAYOUT_KERNEL_OUTPUT)/data-layout" kernel "$(DATA_LAYOUT_KERNEL_OUTPUT)/fixture.o" "$(DATA_LAYOUT_KERNEL_OUTPUT)"

.PHONY: shared-image-artifact-inventory shared-image-restore
shared-image-artifact-inventory:
	python3 ../test/image_native_inventory.py --image "$(REPO_ROOT)/.cache/container-images/x86_64-runner-runtime.image.tar" \
		--stage "$(REPO_ROOT)/vendor/build/native-bpf/x86/stage" --output "$(IMAGE_INVENTORY_OUTPUT)"

# Restore the same saved image after a daemon restart, under the image writer lock.
shared-image-restore:
	docker image load -i "$(REPO_ROOT)/.cache/container-images/x86_64-runner-runtime.image.tar"

.PHONY: shared-base-refresh shared-base-finalize shared-base-modules-repair shared-module-syntax
.PHONY: resident-census-checkpoint resident-census-publish resident-census-publish-test verified-app-collect verified-app-collect-test
.PHONY: map-bounds-class-inspect
.PHONY: self-compare-inputs
.PHONY: self-compare-proof
self-compare-proof:
	cd ../formal && lake env lean KProgFormal/X86CmpOpHandler.lean

.PHONY: self-compare-kernel-inputs self-compare-kvm guest-self-compare
self-compare-kernel-inputs:
	install -d "$(SELF_COMPARE_BUILD)" "$(SELF_COMPARE_KERNEL_OUTPUT)"
	$(CXX) -std=gnu++20 -O1 -I"$(LIBBPF_PREFIX)/include" ../test/self_compare_kernel.cpp \
		"$(LIBBPF_LIBRARY)" -lelf -lz -o "$(SELF_COMPARE_BUILD)/self-compare"
	install -m 0755 "$(SELF_COMPARE_BUILD)/self-compare" "$(SELF_COMPARE_KERNEL_OUTPUT)/"
	install -m 0644 "$(SELF_COMPARE_BEFORE)" "$(SELF_COMPARE_KERNEL_OUTPUT)/before.bpf.o"
	install -m 0644 "$(SELF_COMPARE_AFTER)" "$(SELF_COMPARE_KERNEL_OUTPUT)/after.bpf.o"

self-compare-kvm:
	taskset -c 14 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(SELF_COMPARE_KERNEL_OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 1G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-self-compare SELF_COMPARE_KERNEL_OUTPUT=$(SELF_COMPARE_KERNEL_OUTPUT)'

guest-self-compare:
	"$(SELF_COMPARE_KERNEL_OUTPUT)/self-compare" "$(SELF_COMPARE_KERNEL_OUTPUT)/before.bpf.o" \
		"$(SELF_COMPARE_KERNEL_OUTPUT)/after.bpf.o" "$(SELF_COMPARE_KERNEL_OUTPUT)"

self-compare-inputs:
	install -d "$(SELF_COMPARE_OUTPUT)"
	clang-18 -O2 -I"$(REPO_ROOT)" -I"$(LIBBPF_PREFIX)/include/bpf" \
		../test/self_compare.c -o "$(SELF_COMPARE_OUTPUT)/host"
	"$(SELF_COMPARE_OUTPUT)/host" > "$(SELF_COMPARE_OUTPUT)/host.log"
	clang-18 -target bpf -mcpu=v4 -O2 -g -I"$(REPO_ROOT)" -I"$(LIBBPF_PREFIX)/include/bpf" \
		-I/usr/include/x86_64-linux-gnu -c ../test/self_compare.c -o "$(SELF_COMPARE_OUTPUT)/fixture.bpf.o"
	llvm-objdump-18 -d -l --no-show-raw-insn "$(SELF_COMPARE_OUTPUT)/fixture.bpf.o" > "$(SELF_COMPARE_OUTPUT)/bpf.disassembly"
	sha256sum ../x86/x86_sim_local_bpf.h ../test/self_compare.c "$(SELF_COMPARE_OUTPUT)/fixture.bpf.o" \
		> "$(SELF_COMPARE_OUTPUT)/sha256"

map-bounds-class-inspect:
	python3 ../test/inspect_map_bounds_class.py --worklist "$(MAP_BOUNDS_CLASS_WORKLIST)" --output "$(MAP_BOUNDS_CLASS_OUTPUT)" $(CLASS_INSPECT_ARGS)

verified-app-collect:
	python3 ../test/collect_verified_app.py --raw "$(VERIFIED_APP_RAW)" --corpus "$(VERIFIED_APP_CORPUS)" \
		--captures "$(VERIFIED_APP_CAPTURES)" --prefix "$(VERIFIED_APP_PREFIX)" --exit-file "$(VERIFIED_APP_EXIT_FILE)" --app "$(VERIFIED_APP)"

verified-app-collect-test:
	python3 ../test/test_collect_verified_app.py

resident-census-publish:
	python3 ../test/publish_checkpoint_census.py --base "$(CENSUS_PUBLISH_BASE)" \
		$(foreach journal,$(CENSUS_PUBLISH_QUEUES),--queue "$(journal)") \
		--output "$(CENSUS_PUBLISH_OUTPUT)" --published "$(CENSUS_PUBLISH_DESTINATION)"

resident-census-publish-test:
	python3 ../test/test_publish_checkpoint_census.py

resident-census-checkpoint:
	python3 ../test/resident_verified_census.py checkpoint --output "$(CENSUS_CHECKPOINT_OUTPUT)" \
		$(foreach queue,$(CENSUS_CHECKPOINT_QUEUES),--queue "$(queue)")

shared-base-refresh:
	bash ../test/refresh_verified_base.sh "$(REFRESH_OUTPUT)" "$(REFRESH_OPERATION)"

shared-base-finalize:
	bash ../test/refresh_verified_base.sh "$(REFRESH_OUTPUT)" --finalize

shared-base-modules-repair:
	bash ../test/refresh_verified_base.sh "$(REFRESH_OUTPUT)" --modules-only

shared-module-syntax:
	$(MAKE) -C ../stock-path/module syntax-check
	python3 ../test/module_syntax_check.py "$(REPO_ROOT)/kinsn/module/x86/build" .bpf_x86_native_lab.o.cmd

.PHONY: helper-context-kernel-input helper-context-kernel-kvm guest-helper-context-kernel
helper-context-kernel-input:
	install -d "$(HELPER_BUILD)"
	$(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections \
		-Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" \
		-I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../test/native_loader_helper_kernel.cpp -Wl,--gc-sections "$(LIBBPF_LIBRARY)" -lelf -lz -ldl -pthread \
		-o "$(HELPER_BUILD)/helper-kernel"

# Consume the prepared shared module; never rebuild it on a reader's startup.
helper-context-kernel-kvm:
	install -d "$(HELPER_KERNEL_OUTPUT)"
	install -m 0755 "$(HELPER_BUILD)/helper-kernel" "$(HELPER_KERNEL_OUTPUT)/helper-kernel"
	taskset -c 13 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(HELPER_KERNEL_OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-helper-context-kernel HELPER_KERNEL_OUTPUT=$(HELPER_KERNEL_OUTPUT) HELPER_KERNEL_MODULE=$(HELPER_KERNEL_MODULE)'

guest-helper-context-kernel:
	mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod "$(HELPER_KERNEL_MODULE)"
	"$(HELPER_KERNEL_OUTPUT)/helper-kernel" "$(HELPER_KERNEL_OUTPUT)"

.PHONY: helper-context-check
helper-context-check:
	install -d "$(HELPER_BUILD)" "$(HELPER_OUTPUT)"
	$(CXX) -std=c++20 -O2 -Wall -Wextra -Werror -fsanitize=address,undefined ../test/native_loader_helper_query.cpp -o "$(HELPER_BUILD)/helper-query"
	"$(HELPER_BUILD)/helper-query" "$(HELPER_OUTPUT)"
	$(CXX) -std=gnu++20 -fsyntax-only -Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" -I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" src/native_loader.cpp
	$(MAKE) -C ../stock-path/module syntax-check

.PHONY: subprocess-check
subprocess-check:
	install -d "$(SUBPROCESS_BUILD)" "$(SUBPROCESS_OUTPUT)"
	$(CXX) -std=c++20 -O2 -pthread -Wall -Wextra -Werror ../test/native_loader_subprocess.cpp -o "$(SUBPROCESS_BUILD)/child-boundary"
	"$(SUBPROCESS_BUILD)/child-boundary" "$(SUBPROCESS_OUTPUT)"

.PHONY: lifetime-probe
lifetime-probe:
	python3 ../test/native_loader_lifetime.py "$(abspath $(BUILD_DIR))/libnative_loader.so"

.PHONY: timings-check
timings-check:
	install -d "$(TIMING_BUILD)" "$(TIMING_OUTPUT)"
	$(CXX) -std=c++20 -O2 -pthread -Wall -Wextra -Werror ../test/native_loader_timings.cpp -o "$(TIMING_BUILD)/phase-log"
	python3 ../test/check_native_loader_timings.py "$(TIMING_BUILD)/phase-log" "$(TIMING_OUTPUT)"
	$(CXX) -std=gnu++20 -fsyntax-only -Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" -I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" src/native_loader.cpp
VM_MEM ?= 2G
VM_CPUS ?= 2
SERVICE_HOST_CPUS ?= 8-15
VNG_FLAGS ?=

.PHONY: all clean

.PHONY: native-image-handoff native-image-handoff-kvm guest-native-image-handoff
native-image-handoff:
	install -d "$(BUILD_DIR)"
	$(CC) -O2 -Wall -Wextra -Werror -D__EXPORTED_HEADERS__ \
		-I"$(REPO_ROOT)/vendor/linux-framework/include/uapi" \
		-I"$(LIBBPF_PREFIX)/include" \
		../test/native_image_handoff.c "$(LIBBPF_LIBRARY)" -lelf -lz -pthread \
		-o "$(BUILD_DIR)/native-image-handoff"

# NATIVE_MODULE selects the coordinator-built direct-native module.
native-image-handoff-kvm: native-image-handoff
	taskset -c $(SERVICE_HOST_CPUS) vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(abspath $(BUILD_DIR))" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-native-image-handoff BUILD_DIR=$(abspath $(BUILD_DIR)) NATIVE_MODULE=$(NATIVE_MODULE)'

guest-native-image-handoff:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod "$(NATIVE_MODULE)"
	"$(BUILD_DIR)/native-image-handoff"

all:
	cmake -S . -B "$(BUILD_DIR)" \
		-DNATIVE_LOADER_REPO_ROOT="$(REPO_ROOT)" \
		-DNATIVE_LOADER_LIBBPF_PREFIX="$(LIBBPF_PREFIX)" \
		-DNATIVE_LOADER_LIBBPF_LIBRARY="$(LIBBPF_LIBRARY)" \
		-DNATIVE_LOADER_KERNEL_OFFSETS_INCLUDE="$(KERNEL_OFFSETS_INCLUDE)"
	cmake --build "$(BUILD_DIR)" --target native_loader native_loader_shared

clean:
	rm -rf "$(BUILD_DIR)"

# Existing service wire, on the sole kernel/base; does not execute native code.
.PHONY: trusted-submission-check guest-trusted-submission-check
trusted-submission-check: all
	$(CXX) -std=c++20 -Wall -Wextra -Werror -O2 \
		-I"$(LIBBPF_PREFIX)/include" ../test/trusted_submission.cpp \
		"$(BUILD_DIR)/libnative_loader.a" "$(LIBBPF_LIBRARY)" -lelf -lz -ldl \
		-o "$(BUILD_DIR)/trusted-submission"
	$(MAKE) -C ../stock-path/module
	taskset -c 8-19 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-trusted-submission-check BUILD_DIR=$(abspath $(BUILD_DIR))'

guest-trusted-submission-check:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	"$(BUILD_DIR)/trusted-submission" "$(REPO_ROOT)/vendor/build/native-bpf/x86/stage/bcc/vfsstat.native.o"

.PHONY: trusted-service trusted-service-kvm guest-trusted-service
trusted-service: all
	cmake --build "$(BUILD_DIR)" --target trusted-native-loader trusted-service-client
	$(CC) -O2 -fPIC -mno-red-zone -mgeneral-regs-only -fno-stack-protector \
		-fno-asynchronous-unwind-tables -c ../test/trusted_native.c -o "$(BUILD_DIR)/trusted-native.o"

SAFETY_INPUTS ?= /workspaces/.agent-state/kprog-ck/verified-safety
.PHONY: trusted-safety-inputs
trusted-safety-inputs: all
	KPROG_STOCK_LOADER="$(abspath $(BUILD_DIR))" python3 ../stock-path/run_safety.py build \
		--out "$(SAFETY_INPUTS)" --inputs "$(SAFETY_INPUTS)"

.PHONY: trusted-safety-kvm guest-trusted-safety
trusted-safety-kvm: trusted-service trusted-safety-inputs
	$(MAKE) -C ../stock-path/module
	install -d "$(OUTPUT)"
	taskset -c 8-19 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory $(VM_MEM) --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-trusted-safety BUILD_DIR=$(abspath $(BUILD_DIR)) OUTPUT=$(OUTPUT) SAFETY_INPUTS=$(SAFETY_INPUTS)'

guest-trusted-safety:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	CLANG="$(REPO_ROOT)/kprog/stock-path/bin/clang" KPROG_STOCK_LOADER="$(abspath $(BUILD_DIR))" \
		python3 ../stock-path/run_safety.py check --out "$(OUTPUT)" --inputs "$(SAFETY_INPUTS)"

# The shared module is built explicitly under the image writer lock. Starting
# a service guest must not replace it while another guest uses the sole base.
trusted-service-kvm: trusted-service
	install -d "$(OUTPUT)"
	taskset -c $(SERVICE_HOST_CPUS) vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor $(VNG_FLAGS) --cpus $(VM_CPUS) --memory $(VM_MEM) --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-trusted-service BUILD_DIR=$(abspath $(BUILD_DIR)) OUTPUT=$(OUTPUT) SERVICE_RUN="$(SERVICE_RUN)" SERVICE_EXECUTION_ARGS="$(SERVICE_EXECUTION_ARGS)"'

guest-trusted-service:
	CLANG="$(REPO_ROOT)/kprog/stock-path/bin/clang" python3 ../trusted_service.py --arch 1 \
		--endpoint /sys/kernel/debug/bpf_x86_native_lab/specializer \
		--module /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko \
		--state "$(OUTPUT)/state" --results "$(OUTPUT)/service.tar.gz" \
		--native-link "$(REPO_ROOT)/kprog/x86/native_lab/native_link/target/release/native-link" \
		--loader "$(BUILD_DIR)/trusted-native-loader" $(SERVICE_EXECUTION_ARGS) \
		--run $(SERVICE_RUN)

.PHONY: trusted-lifecycle-check guest-trusted-lifecycle
trusted-lifecycle-check: all
	$(MAKE) -C ../stock-path/module
	install -d "$(OUTPUT)"
	taskset -c 8-19 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(OUTPUT)" --overlay-rwdir /tmp \
		--disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -C kprog/libnativeloader guest-trusted-lifecycle BUILD_DIR=$(abspath $(BUILD_DIR)) OUTPUT=$(OUTPUT)'

guest-trusted-lifecycle:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod /workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko
	python3 ../test/pending_native_snapshot.py "$(OUTPUT)" \
		"$(REPO_ROOT)/bpfopt/shim/build-x86/libbpfrejit_shim.so" "$(BUILD_DIR)/libnative_loader.so"

STACK_RELEASE_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-stack-release/host
.PHONY: stack-release-check
stack-release-check:
	install -d "$(STACK_RELEASE_OUTPUT)"
	$(CC) -O2 -g -fsanitize=undefined -fno-sanitize-recover=undefined -I"$(REPO_ROOT)" \
		-I"$(LIBBPF_PREFIX)/include/bpf" ../formal/oracles/test_invocation_stack_host.c \
		-o "$(STACK_RELEASE_OUTPUT)/host"
	"$(STACK_RELEASE_OUTPUT)/host" > "$(STACK_RELEASE_OUTPUT)/host.log"
	sha256sum ../x86/x86_sim_local_bpf.h ../formal/oracles/test_invocation_stack_host.c \
		"$(STACK_RELEASE_OUTPUT)/host" > "$(STACK_RELEASE_OUTPUT)/sha256"

DIRECT_RECOVERY_BUILD ?= /var/tmp/kprog-tmp/verified/direct-recovery
DIRECT_RECOVERY_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-direct-recovery/host
DIRECT_RECOVERY_KERNEL_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-direct-recovery/kernel
.PHONY: direct-recovery-check direct-recovery-kvm guest-direct-recovery
direct-recovery-check:
	install -d "$(DIRECT_RECOVERY_BUILD)" "$(DIRECT_RECOVERY_OUTPUT)"
	$(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections -Iinclude -I"$(KERNEL_OFFSETS_INCLUDE)" -I"$(LIBBPF_PREFIX)/include" -I"$(REPO_ROOT)/vendor/libbpf/include" -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" ../test/native_loader_recovery.cpp -Wl,--gc-sections "$(LIBBPF_LIBRARY)" -lelf -lz -ldl -pthread -o "$(DIRECT_RECOVERY_BUILD)/recovery"
	"$(DIRECT_RECOVERY_BUILD)/recovery" host "$(DIRECT_RECOVERY_OUTPUT)" > "$(DIRECT_RECOVERY_OUTPUT)/host.log"
	$(MAKE) -C ../perf/direct-native module KDIR=/workspaces/.agent-state/kprog-ck/build-x86 OUT="$(DIRECT_RECOVERY_BUILD)"
	sha256sum src/native_loader.cpp ../perf/direct-native/bpf_x86_native_lab.c ../test/native_loader_recovery.cpp "$(DIRECT_RECOVERY_BUILD)/recovery" "$(DIRECT_RECOVERY_BUILD)/module/bpf_x86_native_lab.ko" > "$(DIRECT_RECOVERY_OUTPUT)/sha256"

direct-recovery-kvm:
	install -d "$(DIRECT_RECOVERY_KERNEL_OUTPUT)"
	install -m 0755 "$(DIRECT_RECOVERY_BUILD)/recovery" "$(DIRECT_RECOVERY_KERNEL_OUTPUT)/recovery"
	install -m 0644 "$(DIRECT_RECOVERY_BUILD)/module/bpf_x86_native_lab.ko" "$(DIRECT_RECOVERY_KERNEL_OUTPUT)/bpf_x86_native_lab.ko"
	taskset -c 14-15 vng --run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage --cwd "$(REPO_ROOT)" --rwdir "$(REPO_ROOT)" --rwdir "$(DIRECT_RECOVERY_KERNEL_OUTPUT)" --overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 2G --append 'loglevel=4 panic=30 oops=panic' --exec 'make -C kprog/libnativeloader guest-direct-recovery DIRECT_RECOVERY_KERNEL_OUTPUT=$(DIRECT_RECOVERY_KERNEL_OUTPUT)'

guest-direct-recovery:
	@mountpoint -q /sys/kernel/debug || mount -t debugfs debugfs /sys/kernel/debug
	insmod "$(DIRECT_RECOVERY_KERNEL_OUTPUT)/bpf_x86_native_lab.ko"
	"$(DIRECT_RECOVERY_KERNEL_OUTPUT)/recovery" kernel "$(DIRECT_RECOVERY_KERNEL_OUTPUT)"

PRIVATE_INPUT_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-private-input/host
.PHONY: private-input-check
private-input-check:
	install -d "$(CHECKED_PACKET_BUILD)" "$(PRIVATE_INPUT_OUTPUT)"
	clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" ../x86/packet_bounds_ir.cpp -o "$(CHECKED_PACKET_BUILD)/packet-bounds" $$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)
	python3 ../test/check_packet_bounds.py "$(CHECKED_PACKET_BUILD)/packet-bounds" "$(CHECKED_COMPILER_BASE)/compile-sim-ir" "$(PRIVATE_INPUT_OUTPUT)/tests"
	sha256sum ../x86/packet_bounds_ir.cpp ../test/check_packet_bounds.py "$(CHECKED_PACKET_BUILD)/packet-bounds" > "$(PRIVATE_INPUT_OUTPUT)/sha256"
