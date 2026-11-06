ROOT := $(abspath ../../../../..)
PRIVATE := /workspaces/.agent-state/kprog-lanes/F/exclusive-export/kprog/formal
.PHONY: snapshot reference
snapshot:
	python3 ../x86-control-reference/snapshot.py $(PRIVATE)
	cp ../arm64-sp-reference/forms.tsv ../arm64-sp-reference/native-code.json ../arm64-sp-reference/host.txt .
reference:
	python3 $(ROOT)/kprog/fidelity/reference_check.py --binary $(ROOT)/kprog/fidelity/build-arm64-sp-observer/cpu-differential --arch arm64 --cases 1024 --out . --reuse-trace --trace ../arm64-sp-reference/cpu-states.bin --reference $(CURDIR)/reference
