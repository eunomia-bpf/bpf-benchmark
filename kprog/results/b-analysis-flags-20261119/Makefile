ROOT := /workspaces/repository
.PHONY: metadata
metadata:
	python3 $(ROOT)/kprog/results/b-analysis-flags-20261119/metadata.py $(OUT)
.PHONY: compile
compile:
	python3 $(ROOT)/kprog/results/b-analysis-flags-20261119/compile.py $(OUT) $(CASES)
.PHONY: diagnose-stack
diagnose-stack:
	python3 $(ROOT)/kprog/results/b-analysis-flags-20261119/stack.py $(OUT)
.PHONY: post-contracts
post-contracts:
	python3 $(ROOT)/kprog/results/b-analysis-flags-20261119/post-contracts.py $(OUT)
