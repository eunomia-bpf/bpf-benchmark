ROOT := /workspaces/repository
RAW := /workspaces/kprog-raw/perf/20261116-shared-hash-regression

.PHONY: audit
audit:
	install -d $(RAW)
	python3 $(ROOT)/kprog/results/shared-hash-regression-20261116/audit.py $(RAW) > $(RAW)/audit.log 2>&1
