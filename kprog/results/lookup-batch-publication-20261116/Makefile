ROOT := /workspaces/repository
RAW := /workspaces/kprog-raw/perf/20261116-lookup-batch-publication
HERE := $(ROOT)/kprog/results/lookup-batch-publication-20261116

.PHONY: dry-run publish summarize
dry-run:
	bash -n $(HERE)/publish.sh
	python3 -c 'import ast; from pathlib import Path; ast.parse(Path("$(HERE)/summarize.py").read_text())'
	$(MAKE) -n -f $(HERE)/Makefile publish WAIT_PID=$(WAIT_PID)

publish:
	bash $(HERE)/publish.sh $(WAIT_PID)

summarize:
	python3 $(HERE)/summarize.py $(RAW)
