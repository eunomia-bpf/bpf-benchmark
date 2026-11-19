BUILD_DIR ?= build
REPO_ROOT := $(abspath ../..)
LIBBPF_PREFIX ?= $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix
LIBBPF_LIBRARY ?= $(REPO_ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a
KERNEL_OFFSETS_INCLUDE ?= $(REPO_ROOT)/micro/programs/build-x86
KDIR ?= /workspaces/.agent-state/kprog-ck/build-x86
VMLINUX_DIR ?= $(REPO_ROOT)/vendor/bpf/targets/x86/$(shell cat $(KDIR)/include/config/kernel.release)

# The registered service reads the checked-sim-c tools from this one base.
CHECKED_COMPILER_BASE ?= /workspaces/.agent-state/kprog-ck/verified-compiler
CHECKED_LOADER ?= /workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader
TOOL_BUILD ?= /var/tmp/kprog-tmp/verified/checked-tools

SOURCE_MAP_BUILD ?= /var/tmp/kprog-tmp/verified/source-maps
SOURCE_MAP_OUTPUT ?= /workspaces/kprog-raw/verified/20261114-source-maps/host

.PHONY: all clean trusted-service checked-sim-stage checked-corpus checked-corpus-all source-maps-check

all:
	cmake -S . -B "$(BUILD_DIR)" \
		-DNATIVE_LOADER_REPO_ROOT="$(REPO_ROOT)" \
		-DNATIVE_LOADER_LIBBPF_PREFIX="$(LIBBPF_PREFIX)" \
		-DNATIVE_LOADER_LIBBPF_LIBRARY="$(LIBBPF_LIBRARY)" \
		-DNATIVE_LOADER_KERNEL_OFFSETS_INCLUDE="$(KERNEL_OFFSETS_INCLUDE)"
	cmake --build "$(BUILD_DIR)" --target native_loader native_loader_shared

clean:
	rm -rf "$(BUILD_DIR)"

trusted-service: all
	cmake --build "$(BUILD_DIR)" --target trusted-native-loader trusted-service-client
	$(CC) -O2 -fPIC -mno-red-zone -mgeneral-regs-only -fno-stack-protector \
		-fno-asynchronous-unwind-tables -c ../test/trusted_native.c -o "$(BUILD_DIR)/trusted-native.o"

# Build the checked-sim-c tools from source and install them into the one base.
checked-sim-stage:
	install -d "$(TOOL_BUILD)" "$(CHECKED_COMPILER_BASE)"
	clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../x86/compile_sim_ir.cpp -o "$(TOOL_BUILD)/compile-sim-ir" \
		$$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)
	clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../build/socket-context-lower.cpp -o "$(TOOL_BUILD)/context-lower" \
		$$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis transformutils support --system-libs)
	clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" \
		../x86/packet_bounds_ir.cpp -o "$(TOOL_BUILD)/packet-bounds" \
		$$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)
	clang-18 -I"$(REPO_ROOT)/vendor/libbpf/include/uapi" ../build/packet-public-layout.c -o "$(TOOL_BUILD)/public-layout"
	clang-18 -I"$(VMLINUX_DIR)" ../build/packet-physical-layout.c -o "$(TOOL_BUILD)/physical-layout"
	install -m 0755 "$(TOOL_BUILD)/compile-sim-ir" "$(TOOL_BUILD)/context-lower" "$(TOOL_BUILD)/packet-bounds" \
		"$(TOOL_BUILD)/public-layout" "$(TOOL_BUILD)/physical-layout" "$(CHECKED_COMPILER_BASE)/"
	"$(CHECKED_COMPILER_BASE)/public-layout" > "$(CHECKED_COMPILER_BASE)/public-layout.json"
	"$(CHECKED_COMPILER_BASE)/physical-layout" > "$(CHECKED_COMPILER_BASE)/physical-layout.json"

# Whole-app checked-sim-c: the registered service builds B, the stock verifier checks it,
# and the frozen corpus runs the app in a guest (kprog/test/run_checked_otel.sh).
CHECKED_APP ?= otelcol-ebpf-profiler/profiling
CHECKED_APPS ?= otelcol-ebpf-profiler/profiling bcc/set cilium/agent tetragon/observer tracee/monitor katran
CHECKED_OUTPUT ?= /workspaces/kprog-raw/verified/checked-corpus
CHECKED_GUEST_BUILD ?= /var/tmp/kprog-tmp/verified/checked-corpus
CHECKED_HOST_CPUS ?= 16-17
CHECKED_VM_CPUS ?= 2
CHECKED_VM_MEMORY ?= 48G
CHECKED_VM_ADDRESS_SPACE ?= 85899345920
checked-corpus:
	install -d "$(CHECKED_OUTPUT)" "$(CHECKED_OUTPUT)/loader-inputs" "$(CHECKED_OUTPUT)/bounds-inputs" "$(CHECKED_GUEST_BUILD)"
	date -u +%FT%TZ > "$(CHECKED_OUTPUT)/started"
	exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9; \
	status=0; taskset -c $(CHECKED_HOST_CPUS) prlimit --as=$(CHECKED_VM_ADDRESS_SPACE) -- vng --run $(KDIR)/arch/x86/boot/bzImage \
		--cwd $(REPO_ROOT) --rwdir $(REPO_ROOT) --rwdir $(CHECKED_OUTPUT) --rwdir /var/tmp=$(CHECKED_GUEST_BUILD) \
		--rodir $(CHECKED_OUTPUT)/loader-inputs=$(dir $(CHECKED_LOADER)) --rodir $(CHECKED_OUTPUT)/bounds-inputs=$(CHECKED_COMPILER_BASE) \
		--overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local \
		--disable-monitor --verbose --cpus $(CHECKED_VM_CPUS) --memory $(CHECKED_VM_MEMORY) --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'bash $(REPO_ROOT)/kprog/test/run_checked_otel.sh $(CHECKED_OUTPUT) $(CHECKED_APP) $(CHECKED_OUTPUT)/loader-inputs/$(notdir $(CHECKED_LOADER)) $(CHECKED_OUTPUT)/bounds-inputs/packet-bounds' || status=$$?; \
	printf '%s\n' "$$status" > "$(CHECKED_OUTPUT)/exit-code"; date -u +%FT%TZ > "$(CHECKED_OUTPUT)/finished"; \
	rm -f "$(CHECKED_GUEST_BUILD)/bpf-benchmark-docker.img"; exit $$status

checked-corpus-all: CHECKED_HOST_CPUS = 8-15
checked-corpus-all:
	install -d "$(CHECKED_OUTPUT)"
	failed=0; for app in $(CHECKED_APPS); do \
		$(MAKE) checked-corpus CHECKED_OUTPUT=$(CHECKED_OUTPUT)/$${app%%/*} CHECKED_APP=$$app \
			CHECKED_HOST_CPUS=$(CHECKED_HOST_CPUS) CHECKED_VM_CPUS=$(CHECKED_VM_CPUS) CHECKED_LOADER=$(CHECKED_LOADER) \
			> $(CHECKED_OUTPUT)/$${app%%/*}.log 2>&1 && rc=0 || rc=$$?; \
		printf '%s\t%s\n' "$$app" "$$rc" >> $(CHECKED_OUTPUT)/run-codes.tsv; \
		if test $$rc -ne 0; then failed=1; fi; \
	done; exit $$failed

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
