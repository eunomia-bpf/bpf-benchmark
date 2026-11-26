ROOT := /workspaces/repository
HERE := $(ROOT)/kprog/results/hash-family-c-20261126
LOCKS := /workspaces/.agent-state/kprog-lanes/locks

.PHONY: check offline module-x86 module-arm64 loaders key-sizes
key-sizes:
	cd $(ROOT) && python3 $(HERE)/key_sizes.py > $(HERE)/key-sizes.json
.PHONY: key-sizes-arm64
key-sizes-arm64:
	cd $(ROOT) && python3 $(HERE)/key_sizes.py arm64 > $(HERE)/key-sizes-arm64.json
check:
	$(MAKE) -C $(ROOT)/kprog/results/hash-c-lto-20261120 check OUT=$(OUT)/host
offline:
	python3 $(ROOT)/kprog/results/restore-529-20261121/offline_link.py $(ROOT)/vendor/build/native-bpf/x86/stage x86 > $(HERE)/offline-x86.log
	python3 $(ROOT)/kprog/results/restore-529-20261121/offline_link.py $(ROOT)/vendor/build/native-bpf/arm64/stage arm64 > $(HERE)/offline-arm64.log
module-x86:
	$(MAKE) -C $(ROOT)/kprog/perf/direct-native module OUT=$(ROOT)/kinsn/module/x86/build
module-arm64:
	$(MAKE) -C /workspaces/.agent-state/kprog-ck/build-arm64 M=$(ROOT)/kprog/perf/direct-native MO=$(ROOT)/kinsn/module/arm64/build ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- modules
loaders:
	$(MAKE) -C $(ROOT)/runner/build-llvmbpf native_loader_shared -j2
	$(MAKE) -C $(ROOT)/runner/build-arm64-llvmbpf native_loader_shared -j2

TEST_BUILD := /var/tmp/kprog-tmp/perf/hash-family
TEST_FLAGS := -std=c++20 -O1 -ffunction-sections -fdata-sections \
	-I$(ROOT)/kprog/libnativeloader/include -I$(ROOT)/micro/programs/build-x86 \
	-I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include \
	-I$(ROOT)/vendor/libbpf/include -I$(ROOT)/vendor/libbpf/include/uapi
TEST_LIBS := -Wl,--gc-sections -L$(ROOT)/runner/build-llvmbpf/native_loader \
	-Wl,-rpath,$(ROOT)/runner/build-llvmbpf/native_loader -lnative_loader -lbpf -lelf -lz
.PHONY: loader-selection
loader-selection:
	install -d $(TEST_BUILD)
	$(CXX) $(TEST_FLAGS) $(HERE)/loader_selection.cpp $(TEST_LIBS) -o $(TEST_BUILD)/direct
	$(TEST_BUILD)/direct
	$(CXX) $(TEST_FLAGS) -DTRUSTED $(HERE)/loader_selection.cpp $(TEST_LIBS) -o $(TEST_BUILD)/trusted
	$(TEST_BUILD)/trusted
.PHONY: collect
OUT ?= $(HERE)
collect:
	python3 $(HERE)/collect.py $(OUT)
