HERE := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
ROOT := $(abspath $(HERE)/../../../../..)
BUILD := build-x86-production-current
REFERENCE := /workspaces/.agent-state/kprog-lanes/F/reference-control-frozen
.PHONY: build reference
build:
	$(MAKE) -C $(ROOT)/kprog/fidelity ARCH=x86 BUILD=$(BUILD) build
reference: build
	python3 $(ROOT)/kprog/fidelity/reference_check.py --binary $(ROOT)/kprog/fidelity/$(BUILD)/cpu-differential --arch x86 --cases 256 --out $(HERE) --reference $(REFERENCE) --control-paths
