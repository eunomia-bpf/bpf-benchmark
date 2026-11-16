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
	$(MAKE) -f $(ROOT)/kprog/results/inner-array-lto-20261116/Makefile definitions RAW=$(RAW)

.PHONY: definitions
definitions:
	install -d $(RAW) $(TMP)
	clang-18 -O2 -g -target bpf -I/usr/include/x86_64-linux-gnu \
		-I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include \
		-c $(ROOT)/kprog/results/inner-array-lto-20261116/nested.bpf.c -o $(TMP)/nested.bpf.o
	$(CXX) -std=gnu++20 -O1 -ffunction-sections -fdata-sections \
		-I$(ROOT)/kprog/libnativeloader/include -I$(ROOT)/micro/programs/build-x86 \
		-I$(ROOT)/runner/build-llvmbpf/vendor/libbpf/prefix/include \
		-I$(ROOT)/vendor/libbpf/include -I$(ROOT)/vendor/libbpf/include/uapi \
		$(ROOT)/kprog/results/inner-array-lto-20261116/definitions.cpp -Wl,--gc-sections \
		$(ROOT)/runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a -lelf -lz -ldl -pthread -o $(TMP)/definitions
	$(TMP)/definitions $(TMP)/nested.bpf.o $(ROOT)/vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64 \
		> $(RAW)/definitions.log 2>&1
	$(MAKE) -C $(ROOT)/kprog/libnativeloader > $(RAW)/loader-build.log 2>&1
	$(MAKE) -f $(ROOT)/kprog/results/map-ops-binding-20261116/Makefile syntax RAW=$(RAW)

.PHONY: inspect
inspect:
	python3 $(ROOT)/kprog/results/inner-array-lto-20261116/ir_form.py $(RAW)
