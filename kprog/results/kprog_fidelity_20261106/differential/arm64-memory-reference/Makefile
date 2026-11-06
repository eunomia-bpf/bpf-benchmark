ROOT := $(abspath ../../../../..)
SNAPSHOT := $(ROOT)/kprog/fidelity/build-arm64-memory-reference
.PHONY: freeze replay
freeze:
	python3 freeze.py $(SNAPSHOT)
replay:
	python3 $(SNAPSHOT)/reference_check.py --reuse-trace --trace ../arm64-sp-reference/cpu-states.bin --reference $(SNAPSHOT)/reference --binary $(SNAPSHOT)/cpu-differential --arch arm64 --cases 1024 --out .
