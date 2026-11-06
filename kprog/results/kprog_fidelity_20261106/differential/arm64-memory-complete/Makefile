ROOT := $(abspath ../../../../..)
PRIVATE := /workspaces/.agent-state/kprog-lanes/F/exclusive-export/kprog/formal
.PHONY: snapshot reference before-reference
snapshot:
	python3 snapshot.py $(PRIVATE)
reference:
	python3 $(ROOT)/kprog/fidelity/reference_check.py --binary $(ROOT)/kprog/fidelity/build-arm64-memory-complete/cpu-differential --arch arm64 --cases 256 --out . --reuse-trace --reference $(CURDIR)/reference
before-reference:
	python3 $(ROOT)/kprog/fidelity/reference_check.py --binary $(ROOT)/kprog/fidelity/build-arm64-addressed-memory/cpu-differential --arch arm64 --cases 256 --out ../arm64-memory-matrix --reuse-trace --reference $(CURDIR)/reference

.PHONY: axioms
axioms:
	cd $(ROOT)/kprog/formal && lake env lean $(CURDIR)/PrintMemory.lean
