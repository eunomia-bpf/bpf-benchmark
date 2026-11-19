.PHONY: prepare check replay stock-probe stock stock-guest coverage
INPUTS ?= /workspaces/kprog-raw/perf/cilium-headlen-20261119/inputs-41/inputs.json
SOURCE_ARCHIVE ?= /workspaces/kprog-raw/verified/20261119-checked-cilium/service.tar.gz
coverage:
	python3 kprog/results/cilium-headlen-20261119/coverage.py $(ARCHIVE) $(OUT)
prepare:
	python3 kprog/results/cilium-headlen-20261119/prepare.py $(OUT) "$(PREVIOUS)" "$(SOURCE_ARCHIVE)"
check:
	python3 kprog/results/cilium-headlen-20261119/check.py $(OUT) $(MODE)
replay:
	python3 kprog/results/cilium-headlen-20261119/replay.py $(OUT) $(INPUTS)
PROBE := /var/tmp/kprog-tmp/perf/cilium-headlen/stock-probe
stock-probe:
	install -d $(dir $(PROBE))
	$(CC) -O2 -Wall -Wextra -Werror -Irunner/build-llvmbpf/vendor/libbpf/prefix/include \
		kprog/results/cilium-headlen-20261119/stock.c \
		runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o $(PROBE)
stock:
	install -d $(OUT) $(OUT)/probe-inputs
	taskset -c 18-19 prlimit --as=8589934592 -- vng \
		--run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd /workspaces/repository --rwdir /workspaces/repository --rwdir $(OUT) \
		--rodir $(OUT)/probe-inputs=$(dir $(PROBE)) \
		--disable-monitor --cpus 2 --memory 2G --overlay-rwdir /tmp \
		--append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -f kprog/results/cilium-headlen-20261119/Makefile stock-guest OUT=$(OUT) FIXTURE=$(FIXTURE)'
stock-guest:
	$(OUT)/probe-inputs/stock-probe $(FIXTURE) $(OUT)/verifier.log > $(OUT)/stock-result.jsonl

ARCHIVE_PROBE := /var/tmp/kprog-tmp/perf/cilium-headlen/archive-stock
REPLAY ?= /workspaces/kprog-raw/perf/cilium-headlen-20261119/edge-candidate-20261119T225223Z-487083/replay
.PHONY: archive-probe archive-prepare archive-stock archive-guest
archive-probe:
	install -d $(dir $(ARCHIVE_PROBE))
	$(CXX) -std=gnu++20 -O1 -g -ffunction-sections -fdata-sections \
		-Ikprog/libnativeloader/include -Imicro/programs/build-x86 \
		-Irunner/build-llvmbpf/vendor/libbpf/prefix/include -Ivendor/libbpf/include -Ivendor/libbpf/include/uapi \
		kprog/results/cilium-headlen-20261119/archive_stock.cpp -Wl,--gc-sections \
		runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -pthread -o $(ARCHIVE_PROBE)
archive-prepare:
	python3 kprog/results/cilium-headlen-20261119/archive_stock.py prepare $(INPUTS) $(REPLAY) $(OUT)
archive-stock:
	install -d $(OUT)/probe-inputs
	taskset -c 18-19 prlimit --as=8589934592 -- vng \
		--run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd /workspaces/repository --rwdir /workspaces/repository --rwdir $(OUT) \
		--rodir $(OUT)/probe-inputs=$(dir $(ARCHIVE_PROBE)) \
		--disable-monitor --cpus 2 --memory 2G --overlay-rwdir /tmp \
		--append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -f kprog/results/cilium-headlen-20261119/Makefile archive-guest OUT=$(OUT) INPUTS=$(INPUTS) REPLAY=$(REPLAY)'
archive-guest:
	python3 kprog/results/cilium-headlen-20261119/archive_stock.py load $(INPUTS) $(REPLAY) $(OUT)
.PHONY: archive-ir
archive-ir:
	llvm-dis-18 $(REPLAY)/$(REQUEST)/bounds.bc -o $(OUT)/$(REQUEST)/bounds.ll
	llvm-objdump-18 -dr $(REPLAY)/$(REQUEST)/replay.bpf.o > $(OUT)/$(REQUEST)/b-disassembly.txt

FRESHNESS_PROBE := /var/tmp/kprog-tmp/perf/cilium-headlen/inspect-freshness
.PHONY: freshness-probe freshness-inspect
freshness-probe:
	clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -Ivendor/libbpf/include/uapi \
		kprog/results/cilium-headlen-20261119/inspect_freshness.cpp -o $(FRESHNESS_PROBE) \
		$$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)
freshness-inspect:
	$(FRESHNESS_PROBE) $(REPLAY)/$(REQUEST)/bounds.bc > $(OUT)/$(REQUEST)/freshness.stdout 2> $(OUT)/$(REQUEST)/freshness.log
