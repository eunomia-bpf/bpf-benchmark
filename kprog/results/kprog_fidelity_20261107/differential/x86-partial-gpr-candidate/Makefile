ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/differential/x86-partial-gpr-candidate
BUILD := build-x86-partial-gpr-candidate
REFERENCE := /workspaces/.agent-state/kprog-lanes/F/reference-control-frozen
.PHONY: build reference
build:
	python3 $(OUT)/select.py
	$(MAKE) -C $(ROOT)/kprog/fidelity ARCH=x86 BUILD=$(BUILD) build
reference: build
	python3 $(ROOT)/kprog/fidelity/reference_check.py --binary $(ROOT)/kprog/fidelity/$(BUILD)/cpu-differential --arch x86 --cases 1024 --out $(OUT) --reference $(REFERENCE)
