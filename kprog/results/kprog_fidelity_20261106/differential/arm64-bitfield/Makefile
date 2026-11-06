ROOT := $(abspath ../../../../..)
REFERENCE := $(ROOT)/kprog/fidelity/build-arm64-bitfield/reference
.PHONY: original-replay
original-replay:
	install -d original-matrix
	cp ../arm64-sp-reference/forms.tsv ../arm64-sp-reference/native-code.json ../arm64-sp-reference/host.txt original-matrix/
	python3 $(ROOT)/kprog/fidelity/reference_check.py --binary $(ROOT)/kprog/fidelity/build-arm64-sp-observer/cpu-differential --arch arm64 --cases 1024 --out original-matrix --reuse-trace --trace ../arm64-sp-reference/cpu-states.bin --reference $(REFERENCE)
