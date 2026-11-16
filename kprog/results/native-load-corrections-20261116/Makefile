ROOT := /workspaces/repository
HERE := $(ROOT)/kprog/results/native-load-corrections-20261116
RAW := /workspaces/kprog-raw/perf/20261116-native-load-corrections

.PHONY: inventory
inventory:
	python3 $(HERE)/inventory.py $(ROOT)/corpus/results/x86_kvm_corpus_20261116_232540_669421 $(RAW)/tetragon-inventory.json > $(RAW)/tetragon-inventory.log
