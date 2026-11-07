ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/differential/arm64-current-logical
REFERENCE := /workspaces/.agent-state/kprog-lanes/F/reference-control-frozen
.PHONY: reference
reference:
	python3 $(ROOT)/kprog/fidelity/reference_check.py --binary $(ROOT)/kprog/fidelity/build-arm64/cpu-differential --arch arm64 --cases 1024 --out $(OUT) --reference $(REFERENCE)
