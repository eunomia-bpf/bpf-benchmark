ROOT := /workspaces/repository
RAW := /workspaces/kprog-raw/perf/20261116-host-link-replay

.PHONY: capture-tracee
capture-tracee:
	$(MAKE) -f $(ROOT)/kprog/results/shared-hash-regression-20261116/Makefile profile \
		RAW=$(RAW) CASE=tracee-capture APP=tracee/monitor MODE=shared
