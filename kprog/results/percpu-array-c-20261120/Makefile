ROOT := /workspaces/repository
.PHONY: check replay receipt method
check:
	python3 $(ROOT)/kprog/results/percpu-array-c-20261120/check.py $(OUT)
replay:
	$(MAKE) -f $(ROOT)/kprog/results/helper-sharing-20261120/Makefile replay OUT=$(OUT) REPLAY_ARGS='--capture /workspaces/kprog-raw/perf/lookup-grouping-20261120/otel-20261120T053716Z/service.tar.gz --requests 3 4'
receipt:
	python3 $(ROOT)/kprog/results/percpu-array-c-20261120/receipt.py $(OUT)
method:
	python3 $(ROOT)/kprog/results/percpu-array-c-20261120/method.py
