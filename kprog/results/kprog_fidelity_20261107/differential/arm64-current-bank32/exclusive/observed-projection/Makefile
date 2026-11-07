ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/differential/arm64-current-bank32/exclusive/observed-projection
.PHONY: proof reference
proof:
	cd $(ROOT)/kprog/fidelity/build-x86-control/reference && lake env lean $(OUT)/Observation.lean
reference:
	python3 $(ROOT)/kprog/fidelity/reference_check.py --arch arm64 --binary $(ROOT)/kprog/fidelity/build-arm64-exclusive-choice/cpu-differential --cases 1024 --out $(OUT) --reuse-trace --trace $(OUT)/../cpu-states.bin --reference $(ROOT)/kprog/fidelity/build-x86-control/reference/.lake/build/bin/reference --exclusive-observation-witness $(OUT)/witness.json
