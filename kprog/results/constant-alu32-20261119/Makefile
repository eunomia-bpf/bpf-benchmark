BOUNDS := /workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds
.PHONY: test replay
test:
	python3 kprog/results/constant-alu32-20261119/test.py $(BOUNDS) $(OUT) $(MODE)
replay:
	python3 kprog/results/constant-alu32-20261119/replay.py $(OUT)
