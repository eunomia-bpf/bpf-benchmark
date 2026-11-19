.PHONY: prepare check replay stock-probe stock stock-guest coverage
INPUTS ?= /workspaces/kprog-raw/perf/cilium-headlen-20261119/inputs-41/inputs.json
coverage:
	python3 kprog/results/cilium-headlen-20261119/coverage.py $(ARCHIVE) $(OUT)
prepare:
	python3 kprog/results/cilium-headlen-20261119/prepare.py $(OUT) $(PREVIOUS)
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
