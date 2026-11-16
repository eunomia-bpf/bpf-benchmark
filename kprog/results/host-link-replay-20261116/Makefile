ROOT := /workspaces/repository
RAW := /workspaces/kprog-raw/perf/20261116-host-link-replay
HERE := $(ROOT)/kprog/results/host-link-replay-20261116

.PHONY: capture-tracee
capture-tracee:
	$(MAKE) -f $(ROOT)/kprog/results/shared-hash-regression-20261116/Makefile profile \
		RAW=$(RAW) CASE=tracee-capture APP=tracee/monitor MODE=shared

.PHONY: dry-run proofs
dry-run:
	python3 $(HERE)/proofs.py --dry-run

proofs:
	python3 $(HERE)/proofs.py $(RAW)/proofs-initial
