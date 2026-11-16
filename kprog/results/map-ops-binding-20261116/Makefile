ROOT := /workspaces/repository
RAW := /workspaces/kprog-raw/perf/20261116-map-ops-binding

.PHONY: host
host:
	install -d $(RAW)
	cd $(ROOT)/kprog/x86/native_lab/native_link && cargo test --release -- --test-threads=1 > $(RAW)/linker-tests.log 2>&1
	cd $(ROOT)/kprog/x86/native_lab/native_link && cargo build --release > $(RAW)/linker-build.log 2>&1
	$(MAKE) -C $(ROOT)/kprog/libnativeloader > $(RAW)/loader-build.log 2>&1
	$(MAKE) -f $(ROOT)/kprog/results/map-ops-binding-20261116/Makefile syntax RAW=$(RAW)

.PHONY: syntax
syntax:
	python3 $(ROOT)/kprog/results/map-ops-binding-20261116/module-syntax.py > $(RAW)/module-syntax.log 2>&1
