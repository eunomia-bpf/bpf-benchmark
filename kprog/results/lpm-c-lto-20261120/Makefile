ROOT := /workspaces/repository
RAW ?= /workspaces/kprog-raw/perf/lpm-c-lto-20261120
TMP := /var/tmp/kprog-tmp/perf/lpm-c-lto
TOOL := $(ROOT)/vendor/build/native-bpf/x86/stage/kprog-perf-context-lto

.PHONY: compiler check
compiler:
	$(MAKE) -C $(ROOT)/vendor/bpf $(TOOL)

check:
	install -d $(RAW) $(TMP)
	clang-18 -O3 -march=native -Xclang -fembed-bitcode=all -fPIC -mno-red-zone -mgeneral-regs-only \
		-fno-stack-protector -fomit-frame-pointer -c $(ROOT)/kprog/results/lpm-c-lto-20261120/fixture.c -o $(TMP)/fixture.o
	python3 $(ROOT)/kprog/results/lpm-c-lto-20261120/check.py $(RAW) $(TMP)
