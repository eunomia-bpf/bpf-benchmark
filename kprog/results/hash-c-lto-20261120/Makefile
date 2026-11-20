ROOT := /workspaces/repository
.PHONY: check
check:
	python3 $(ROOT)/kprog/results/hash-c-lto-20261120/check.py $(OUT)

BUILD := /var/tmp/kprog-tmp/perf/hash-c-lto
PROBE := /var/tmp/kprog-tmp/perf/cilium-headlen/archive-stock
.PHONY: generation stock stock-guest native
generation:
	python3 $(ROOT)/kprog/results/hash-c-lto-20261120/production.py $(OUT) generation
stock:
	install -d $(OUT)/probe-inputs $(OUT)/generation-inputs
	flock -s /workspaces/.agent-state/kprog-lanes/locks/image \
		taskset -c 20-21 nice -n 19 prlimit --as=8589934592 -- vng \
		--run /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage \
		--cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUT) \
		--rodir $(OUT)/probe-inputs=$(dir $(PROBE)) --rodir $(OUT)/generation-inputs=$(BUILD)/generation \
		--disable-monitor --cpus 2 --memory 2G --overlay-rwdir /tmp \
		--append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -f kprog/results/hash-c-lto-20261120/Makefile stock-guest OUT=$(OUT)'
stock-guest:
	python3 $(ROOT)/kprog/results/hash-c-lto-20261120/stock.py $(OUT)
native:
	python3 $(ROOT)/kprog/results/hash-c-lto-20261120/production.py $(OUT) native

.PHONY: receipt
receipt:
	python3 $(ROOT)/kprog/results/hash-c-lto-20261120/receipt.py
