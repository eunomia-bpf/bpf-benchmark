ROOT := /workspaces/repository
RAW := /workspaces/kprog-raw/perf/20261116-katran-decay
RUN ?= $(ROOT)/corpus/results/x86_kvm_corpus_20261116_192946_405839
CASE ?= stats-off

.PHONY: analyze
analyze:
	install -d $(RAW)
	python3 $(ROOT)/kprog/results/katran-decay-20261116/analyze.py $(RUN) $(RAW)/$(CASE).json > $(RAW)/$(CASE).log
