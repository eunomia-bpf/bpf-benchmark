BOUNDS := /workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds
.PHONY: test rebuild replay syntax
syntax:
	clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -Ivendor/libbpf/include/uapi \
		-fsyntax-only kprog/x86/packet_bounds_ir.cpp
test:
	python3 kprog/results/b-pointer-difference-20261119/test.py $(OUT) $(MODE)
rebuild:
	clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -Ivendor/libbpf/include/uapi \
		kprog/x86/packet_bounds_ir.cpp -o $(BOUNDS) \
		$$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)
replay:
	python3 kprog/results/b-pointer-difference-20261119/replay.py $(OUT) $(REQUEST)

PROBE := /var/tmp/kprog-tmp/perf/b-pointer-difference/stock-probe
FIXTURE := $(OUT)/../fixture/fixture.bpf.o
.PHONY: stock-probe stock stock-guest
stock-probe:
	install -d $(dir $(PROBE))
	$(CC) -O2 -Wall -Wextra -Werror -Irunner/build-llvmbpf/vendor/libbpf/prefix/include \
		kprog/results/b-pointer-difference-20261119/stock.c \
		runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o $(PROBE)
stock:
	install -d $(OUT) $(OUT)/probe-inputs
	taskset -c 18-19 prlimit --as=8589934592 -- vng \
		--run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd /workspaces/repository --rwdir /workspaces/repository --rwdir $(OUT) \
		--rodir $(OUT)/probe-inputs=$(dir $(PROBE)) \
		--disable-monitor --cpus 2 --memory 2G --overlay-rwdir /tmp \
		--append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -f kprog/results/b-pointer-difference-20261119/Makefile stock-guest OUT=$(OUT) FIXTURE=$(FIXTURE)'
stock-guest:
	$(OUT)/probe-inputs/stock-probe $(FIXTURE) $(OUT)/verifier.log > $(OUT)/stock-result.json
.PHONY: katran-inspect
katran-inspect:
	python3 kprog/results/b-pointer-difference-20261119/inspect_katran.py $(OUT)
