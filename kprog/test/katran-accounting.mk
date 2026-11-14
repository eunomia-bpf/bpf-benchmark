SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
OUTPUT ?= /workspaces/kprog-raw/perf/20261114-katran-c4-accounting

.PHONY: analyze
analyze:
	taskset -c 19 prlimit --as=4294967296 -- python3 $(ROOT)/kprog/results/perf_20261113/katran_counter_accounting.py --run $(ROOT)/corpus/results/x86_kvm_corpus_20261114_012718_572545 --profile-run $(ROOT)/corpus/results/x86_kvm_corpus_20261114_183513_065331 --profile-capture /workspaces/kprog-raw/C/limits/katran --output $(OUTPUT)
