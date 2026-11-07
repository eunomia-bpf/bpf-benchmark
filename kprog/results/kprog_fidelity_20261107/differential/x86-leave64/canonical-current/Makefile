ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/differential/x86-leave64/canonical-current
REF := $(ROOT)/kprog/fidelity/build-x86-leave64/reference
.PHONY: reference-build reference
reference-build:
	cd $(REF) && lake build reference
reference:
	python3 $(ROOT)/kprog/fidelity/leave64_reference.py --cases $(OUT)/../cases.jsonl.gz --binary $(ROOT)/kprog/fidelity/build-x86-leave64/leave64 --reference $(REF)/.lake/build/bin/reference --out $(OUT)
