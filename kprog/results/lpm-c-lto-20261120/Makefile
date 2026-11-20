ROOT := /workspaces/repository
RAW ?= /workspaces/kprog-raw/perf/lpm-c-lto-20261120
TMP := /var/tmp/kprog-tmp/perf/lpm-c-lto
TOOL := $(ROOT)/vendor/build/native-bpf/x86/stage/kprog-perf-context-lto

.PHONY: compiler check
compiler:
	$(MAKE) -C $(ROOT)/vendor/bpf $(TOOL)

check:
	install -d $(RAW) $(TMP)
	$(CXX) -std=c++20 -O1 -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include \
		$(ROOT)/kprog/results/lpm-c-lto-20261120/layout.cpp \
		$(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -o $(TMP)/layout
	$(TMP)/layout /workspaces/.agent-state/kprog-ck/build-x86/vmlinux > $(RAW)/layout.json
	clang-18 -O3 -march=native -Xclang -fembed-bitcode=all -fPIC -mno-red-zone -mgeneral-regs-only \
		-fno-stack-protector -fomit-frame-pointer -c $(ROOT)/kprog/results/lpm-c-lto-20261120/fixture.c -o $(TMP)/fixture.o
	python3 $(ROOT)/kprog/results/lpm-c-lto-20261120/check.py $(RAW) $(TMP)

.PHONY: compatibility syntax
compatibility:
	install -d $(RAW)/array /var/tmp/kprog-tmp/perf/inner-array-lto
	clang-18 -O3 -Xclang -fembed-bitcode=all -fPIC -mno-red-zone -mgeneral-regs-only \
		-c $(ROOT)/kprog/results/inner-array-lto-20261116/fixture.c -o /var/tmp/kprog-tmp/perf/inner-array-lto/fixture.native.o
	python3 $(ROOT)/kprog/results/inner-array-lto-20261116/check.py $(RAW)/array /var/tmp/kprog-tmp/perf/inner-array-lto \
		> $(RAW)/array-check.log 2>&1

syntax:
	$(CXX) -std=gnu++20 -fsyntax-only -I$(ROOT)/kprog/libnativeloader/include \
		-I$(ROOT)/micro/programs/build-x86 -I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include \
		-I$(ROOT)/vendor/libbpf/include -I$(ROOT)/vendor/libbpf/include/uapi \
		$(ROOT)/kprog/libnativeloader/src/native_loader.cpp

.PHONY: archive
archive:
	python3 $(ROOT)/kprog/results/lpm-c-lto-20261120/archive.py $(RAW)

.PHONY: generation
generation:
	install -d $(RAW)
	python3 $(ROOT)/kprog/results/lpm-c-lto-20261120/generation.py $(RAW)

STOCK_PROBE := /var/tmp/kprog-tmp/perf/cilium-headlen/archive-stock
.PHONY: stock-probe stock stock-guest
stock-probe:
	$(MAKE) -f $(ROOT)/kprog/results/cilium-headlen-20261119/Makefile archive-probe

stock:
	install -d $(RAW)/probe-inputs
	date -u +%FT%TZ > $(RAW)/started
	status=0; flock -s /workspaces/.agent-state/kprog-lanes/locks/image \
		taskset -c 20-21 nice -n 19 prlimit --as=8589934592 -- vng \
		--run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd $(ROOT) --rwdir $(ROOT) --rwdir $(RAW) \
		--rodir $(RAW)/probe-inputs=$(dir $(STOCK_PROBE)) \
		--disable-monitor --cpus 2 --memory 2G --overlay-rwdir /tmp \
		--append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -f kprog/results/lpm-c-lto-20261120/Makefile stock-guest RAW=$(RAW)' || status=$$?; \
		printf '%s\n' "$$status" > $(RAW)/exit-code; date -u +%FT%TZ > $(RAW)/finished; exit $$status

stock-guest:
	python3 $(ROOT)/kprog/results/lpm-c-lto-20261120/stock.py $(RAW)
