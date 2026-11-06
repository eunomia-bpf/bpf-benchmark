ROOT := $(abspath ../../../../..)
PRIVATE := /workspaces/.agent-state/kprog-lanes/F/exclusive-export/kprog/formal
.PHONY: snapshot reference
snapshot:
	python3 snapshot.py $(PRIVATE)
reference:
	python3 $(ROOT)/kprog/fidelity/reference_check.py --reuse-trace --control-paths --trace ../x86-full-conditions/cpu-states.bin --binary $(ROOT)/kprog/fidelity/build-x86-full-conditions/cpu-differential --arch x86 --cases 1024 --out . --reference $(CURDIR)/reference

.PHONY: wire
wire:
	cd $(ROOT)/kprog/formal && lake build reference
	python3 $(ROOT)/kprog/formal/tools/check_reference_x86_path.py
