ROOT := /workspaces/repository
RAW := /workspaces/kprog-raw/perf/20261116-known-lookup-targets

.PHONY: host
host:
	install -d $(RAW)
	cd $(ROOT)/kprog/x86/native_lab/native_link && cargo test --release -- --test-threads=1 > $(RAW)/linker-tests.log 2>&1
	cd $(ROOT)/kprog/x86/native_lab/native_link && cargo build --release > $(RAW)/linker-build.log 2>&1
	$(MAKE) -C $(ROOT)/kprog/libnativeloader > $(RAW)/loader-build.log 2>&1
	python3 $(ROOT)/kprog/results/known-lookup-targets-20261116/replay.py $(RAW) > $(RAW)/replay.log 2>&1
	python3 $(ROOT)/kprog/results/known-lookup-targets-20261116/unwinder.py $(RAW) > $(RAW)/unwinder.log 2>&1

.PHONY: unwinder
unwinder:
	install -d $(RAW)
	python3 $(ROOT)/kprog/results/known-lookup-targets-20261116/unwinder.py $(RAW) > $(RAW)/unwinder.log 2>&1
