ROOT := /workspaces/repository
RAW := /workspaces/kprog-raw/perf/20261116-inner-array-lto
TMP := /var/tmp/kprog-tmp/perf/inner-array-lto
TOOL := $(ROOT)/vendor/build/native-bpf/x86/stage/kprog-perf-context-lto

.PHONY: host
host:
	install -d $(RAW) $(TMP)
	$(MAKE) -C $(ROOT)/vendor/bpf $(TOOL) > $(RAW)/compiler-build.log 2>&1
	clang-18 -O3 -Xclang -fembed-bitcode=all -fPIC -mno-red-zone -mgeneral-regs-only \
		-c $(ROOT)/kprog/results/inner-array-lto-20261116/fixture.c -o $(TMP)/fixture.native.o
	python3 $(ROOT)/kprog/results/inner-array-lto-20261116/check.py $(RAW) $(TMP) > $(RAW)/check.log 2>&1
	$(MAKE) -C $(ROOT)/kprog/libnativeloader > $(RAW)/loader-build.log 2>&1
	$(MAKE) -f $(ROOT)/kprog/results/map-ops-binding-20261116/Makefile syntax RAW=$(RAW)

.PHONY: inspect
inspect:
	python3 $(ROOT)/kprog/results/inner-array-lto-20261116/inspect.py $(RAW)
