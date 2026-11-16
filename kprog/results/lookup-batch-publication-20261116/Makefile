ROOT := /workspaces/repository
RAW := /workspaces/kprog-raw/perf/20261116-lookup-batch-publication
HERE := $(ROOT)/kprog/results/lookup-batch-publication-20261116

.PHONY: dry-run publish check summarize
dry-run:
	bash -n $(HERE)/publish.sh
	python3 -c 'import ast; from pathlib import Path; ast.parse(Path("$(HERE)/summarize.py").read_text())'
	$(MAKE) -n -f $(HERE)/Makefile publish WAIT_PID=$(WAIT_PID)

publish:
	bash $(HERE)/publish.sh $(WAIT_PID)

check:
	date -u +%FT%TZ > $(RAW)/check.started
	flock -s /workspaces/.agent-state/kprog-lanes/locks/image flock -x /workspaces/.agent-state/kprog-lanes/locks/timing $(MAKE) -f $(ROOT)/kprog/perf/one-image/Makefile check LOGS=$(RAW)/check > $(RAW)/check.controller.log 2>&1
	date -u +%FT%TZ > $(RAW)/check.finished
	$(MAKE) -f $(HERE)/Makefile summarize > $(RAW)/summary.log 2>&1

summarize:
	python3 $(HERE)/summarize.py $(RAW)
