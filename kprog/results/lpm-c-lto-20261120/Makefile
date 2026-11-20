ROOT := /workspaces/repository
RAW ?= /workspaces/kprog-raw/perf/lpm-c-lto-20261120
TMP := /var/tmp/kprog-tmp/perf/lpm-c-lto
TOOL := $(ROOT)/vendor/build/native-bpf/x86/stage/kprog-perf-context-lto

.PHONY: compatibility syntax
compatibility:
	install -d $(RAW) $(TMP)/array $(TMP)/probe
	$(MAKE) -f $(ROOT)/kprog/results/checked-array-c-20261119/Makefile test OUT=$(TMP)/array \
		> $(RAW)/array.log 2>&1
	$(MAKE) -f $(ROOT)/kprog/results/checked-probe-c-20261119/Makefile test OUT=$(TMP)/probe \
		> $(RAW)/probe.log 2>&1

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
	clang-18 -O3 -march=native -Xclang -fembed-bitcode=all -fPIC -mno-red-zone -mgeneral-regs-only \
		-fno-stack-protector -fomit-frame-pointer -c $(ROOT)/kprog/results/lpm-c-lto-20261120/stock_entry.c -o $(TMP)/stock-entry.input.o
	python3 $(ROOT)/kprog/results/lpm-c-lto-20261120/generation.py $(RAW)

STOCK_PROBE := /var/tmp/kprog-tmp/perf/cilium-headlen/archive-stock
.PHONY: stock stock-guest
stock:
	install -d $(RAW)/probe-inputs $(RAW)/generation-inputs
	date -u +%FT%TZ > $(RAW)/started
	status=0; flock -s /workspaces/.agent-state/kprog-lanes/locks/image \
		taskset -c 20-21 nice -n 19 prlimit --as=8589934592 -- vng \
		--run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd $(ROOT) --rwdir $(ROOT) --rwdir $(RAW) \
		--rodir $(RAW)/probe-inputs=$(dir $(STOCK_PROBE)) \
		--rodir $(RAW)/generation-inputs=$(TMP)/generation \
		--disable-monitor --cpus 2 --memory 2G --overlay-rwdir /tmp \
		--append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -f kprog/results/lpm-c-lto-20261120/Makefile stock-guest RAW=$(RAW)' || status=$$?; \
		printf '%s\n' "$$status" > $(RAW)/exit-code; date -u +%FT%TZ > $(RAW)/finished; exit $$status

stock-guest:
	python3 $(ROOT)/kprog/results/lpm-c-lto-20261120/stock.py $(RAW)

.PHONY: post-b
post-b:
	install -d $(RAW)
	python3 $(ROOT)/kprog/results/lpm-c-lto-20261120/post_b.py $(RAW) $(STOCK)

.PHONY: native-receipt
native-receipt:
	python3 $(ROOT)/kprog/results/lpm-c-lto-20261120/native_receipt.py

.PHONY: app-receipt
app-receipt:
	python3 $(ROOT)/kprog/results/lpm-c-lto-20261120/app_receipt.py $(APP_RECEIPT_ARGS)

.PHONY: prefix-receipt
prefix-receipt:
	python3 $(ROOT)/kprog/results/lpm-c-lto-20261120/prefix_receipt.py
