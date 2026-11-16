ROOT := /workspaces/repository
RAW := /workspaces/kprog-raw/perf/20261116-host-link-replay
HERE := $(ROOT)/kprog/results/host-link-replay-20261116
EMISSION_OUTPUT ?= $(RAW)/emission-initial

.PHONY: capture-tracee
capture-tracee:
	$(MAKE) -f $(ROOT)/kprog/results/shared-hash-regression-20261116/Makefile profile \
		RAW=$(RAW) CASE=tracee-capture APP=tracee/monitor MODE=shared

.PHONY: dry-run proofs
dry-run:
	python3 $(HERE)/proofs.py --dry-run

proofs:
	python3 $(HERE)/proofs.py $(RAW)/proofs-initial

.PHONY: emission-dry-run emission
emission-dry-run:
	python3 $(HERE)/emission.py $(RAW) --dry-run

emission:
	python3 $(HERE)/emission.py $(RAW) $(EMISSION_OUTPUT)

.PHONY: capture-tetragon
capture-tetragon:
	DEBUGINFOD_URLS= flock -s /workspaces/.agent-state/kprog-lanes/locks/image \
		python3 $(HERE)/tetragon.py run --app tetragon/observer \
		--cpus 20-23 --vcpus 4 --memory 32G --seconds 60 --freq 199 --host-event cycles:G \
		--state-root /var/tmp/kprog-tmp/perf/tetragon-load-diagnostic --persist-output --out $(RAW)/tetragon-capture
