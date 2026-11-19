ROOT := /workspaces/repository
TOOL := /workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir
.PHONY: test
test:
	python3 $(ROOT)/kprog/results/checked-array-c-20261119/test.py $(OUT) $(TOOL)
.PHONY: replay
replay:
	python3 $(ROOT)/kprog/results/checked-array-c-20261119/replay.py $(OUT)/replay $(ARCHIVE)
