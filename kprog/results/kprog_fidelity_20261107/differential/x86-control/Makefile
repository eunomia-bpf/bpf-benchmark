ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/differential/x86-control
.PHONY: reference
reference:
	python3 $(ROOT)/kprog/fidelity/x86_reference_path.py --binary $(ROOT)/kprog/fidelity/build-x86-control/cpu-differential --reference $(ROOT)/kprog/fidelity/build-x86-control/reference/.lake/build/bin/reference --out $(OUT) --cases 1024

.PHONY: reference-build
reference-build:
	cd $(ROOT)/kprog/fidelity/build-x86-control/reference && lake build reference
