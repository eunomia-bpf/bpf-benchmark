ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/differential/arm64-numeric-tokens
BUILD := build-arm64-numeric-tokens
REFERENCE := /workspaces/.agent-state/kprog-lanes/F/reference-control-frozen
.PHONY: build reference
build:
	python3 $(OUT)/select.py
	$(MAKE) -C $(ROOT)/kprog/fidelity ARCH=arm64 BUILD=$(BUILD) build
reference: build
	python3 $(ROOT)/kprog/fidelity/reference_check.py --binary $(ROOT)/kprog/fidelity/$(BUILD)/cpu-differential --arch arm64 --cases 1024 --out $(OUT) --reference $(REFERENCE)
