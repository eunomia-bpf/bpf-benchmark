ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/differential/arm64-control-branches
BINARY := $(ROOT)/kprog/fidelity/build-arm64-control/cpu-differential
.PHONY: cpu reference
cpu:
	qemu-aarch64-static $(BINARY) 1024 $(OUT) $(OUT)/cpu-states.bin
reference:
	python3 $(ROOT)/kprog/fidelity/arm64_reference_path.py --binary $(BINARY) --reference /workspaces/.agent-state/kprog-lanes/F/reference-control-frozen --out $(OUT) --cases 1024
