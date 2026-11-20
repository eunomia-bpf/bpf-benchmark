ROOT := /workspaces/repository
OUT ?= /workspaces/kprog-raw/perf/pid-c-lto-20261120/before
MODE ?= before
.PHONY: check receipt
check:
	taskset -c 16-19 nice -n 19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/results/pid-c-lto-20261120/check.py $(OUT) $(MODE)
receipt:
	cp $(OUT)/report.json $(ROOT)/kprog/results/pid-c-lto-20261120/$(MODE)-result.json
	tar -czf $(ROOT)/kprog/results/pid-c-lto-20261120/$(MODE)-evidence.tar.gz -C $(dir $(OUT)) $(notdir $(OUT))
