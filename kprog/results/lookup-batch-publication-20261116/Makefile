ROOT := /workspaces/repository
RAW := /workspaces/kprog-raw/perf/20261116-lookup-batch-publication
HERE := $(ROOT)/kprog/results/lookup-batch-publication-20261116

.PHONY: dry-run publish check summarize
dry-run:
	bash -n $(HERE)/publish.sh
	python3 -c 'import ast; from pathlib import Path; ast.parse(Path("$(HERE)/summarize.py").read_text())'
	$(MAKE) -n -f $(HERE)/Makefile publish WAIT_PID=$(WAIT_PID)

publish:
	install -d $(RAW)
	bash $(HERE)/publish.sh $(WAIT_PID) $(RAW)

check:
	date -u +%FT%TZ > $(RAW)/check.started
	flock -x /workspaces/.agent-state/kprog-lanes/locks/timing flock -s /workspaces/.agent-state/kprog-lanes/locks/image $(MAKE) -f $(ROOT)/kprog/perf/one-image/Makefile check LOGS=$(RAW)/check > $(RAW)/check.controller.log 2>&1
	date -u +%FT%TZ > $(RAW)/check.finished
	$(MAKE) -f $(HERE)/Makefile summarize > $(RAW)/summary.log 2>&1

summarize:
	python3 $(HERE)/summarize.py $(RAW)

.PHONY: loader
loader:
	flock -s /workspaces/.agent-state/kprog-lanes/locks/timing $(MAKE) -C $(ROOT)/kprog/libnativeloader > $(RAW)/lpm-loader-build.log 2>&1
