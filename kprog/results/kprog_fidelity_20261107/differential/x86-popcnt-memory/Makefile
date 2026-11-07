ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/differential/x86-popcnt-memory
.PHONY: reference
reference:
	python3 $(ROOT)/kprog/fidelity/reference_check.py --binary $(ROOT)/kprog/fidelity/build-x86/cpu-differential --arch x86 --cases 1024 --out $(OUT) --reference /workspaces/.agent-state/kprog-lanes/F/reference-control-frozen --control-paths
