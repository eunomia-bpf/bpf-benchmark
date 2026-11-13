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

# Tool build only, from the sole kernel source; no kernel/base/image rebuild.
loader-perf-build:
	install -d $(LOADER_PERF_BUILD)
	$(MAKE) -C $(ROOT)/vendor/linux-framework/tools/perf O=$(LOADER_PERF_BUILD)/ -j4 NO_LIBBPF=1 NO_LIBPYTHON=1 NO_LIBPERL=1 NO_LIBTRACEEVENT=1 NO_SLANG=1 NO_LIBUNWIND=1 NO_LIBNUMA=1 NO_AUXTRACE=1 NO_LIBCAP=1 NO_LIBLLVM=1
	$(LOADER_PERF_SOURCE) version --build-options

loader-perf-tool:
	install -D -m 755 $(LOADER_PERF_SOURCE) $(LOADER_PERF_OUTPUT)
	$(LOADER_PERF_OUTPUT) version --build-options
