ROOT := /workspaces/repository
HERE := $(ROOT)/kprog/results/conditional-tail-20261116
RAW := /workspaces/kprog-raw/perf/20261116-conditional-tail
STATE := /var/tmp/kprog-tmp/perf/conditional-tail
CASE ?= before

.PHONY: replay host dry-run
dry-run:
	python3 -c 'import ast; from pathlib import Path; ast.parse(Path("$(HERE)/replay.py").read_text())'

replay:
	install -d $(STATE) $(RAW)/$(CASE)
	cc -c $(HERE)/fixture.S -o $(STATE)/fixture.o
	python3 $(HERE)/replay.py $(STATE)/fixture.o $(RAW)/$(CASE)

host:
	cd $(ROOT)/kprog/x86/native_lab/native_link && cargo test --release -- --test-threads=1 > $(RAW)/linker-tests.log 2>&1
	cd $(ROOT)/kprog/x86/native_lab/native_link && cargo build --release > $(RAW)/linker-build.log 2>&1
