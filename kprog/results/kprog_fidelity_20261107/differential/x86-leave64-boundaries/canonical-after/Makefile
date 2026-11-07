ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/kprog_fidelity_20261107/differential/x86-leave64-boundaries/canonical-after
REF := $(ROOT)/kprog/fidelity/build-x86-leave64/reference
.PHONY: reference
reference:
	python3 $(ROOT)/kprog/fidelity/leave64_reference.py --cases $(OUT)/../kvm-clearcpuid-lass/cases.jsonl.gz --binary $(ROOT)/kprog/fidelity/build-x86-leave64-boundaries/leave64 --reference $(REF)/.lake/build/bin/reference --input-classes 33 --out $(OUT)
