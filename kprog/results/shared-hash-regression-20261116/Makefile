ROOT := /workspaces/repository
RAW := /workspaces/kprog-raw/perf/20261116-shared-hash-regression
HERE := $(ROOT)/kprog/results/shared-hash-regression-20261116
INPUT := $(ROOT)/corpus/results/shared-hash-regression-20261116
CASE ?= katran-shared
APP ?= katran
MODE ?= shared

.PHONY: audit
audit:
	install -d $(RAW)
	python3 $(ROOT)/kprog/results/shared-hash-regression-20261116/audit.py $(RAW) > $(RAW)/audit.log 2>&1

.PHONY: preflight stage profile
preflight:
	python3 $(HERE)/preflight.py $(RAW) > $(RAW)/preflight.json
	python3 -c "import ast,pathlib; [ast.parse(p.read_text()) for p in pathlib.Path('$(HERE)').glob('*.py')]"

stage:
	install -d $(INPUT)/captures
	chmod +x $(HERE)/link.py
	ln $(HERE)/link.py $(INPUT)/copy-link
	ln $(HERE)/link.py $(INPUT)/shared-link
	cp $(RAW)/katran.copied-hash.bin $(INPUT)/copied-hash.bin
	cp $(RAW)/katran.copied-hash-sites.json $(INPUT)/copied-hash-sites.json

profile:
	DEBUGINFOD_URLS= flock -s /workspaces/.agent-state/kprog-lanes/locks/image \
		python3 $(HERE)/profile.py $(MODE) run --app $(APP) \
		--cpus 20-23 --vcpus 4 --memory 32G --seconds 60 --freq 199 --host-event cycles:G \
		--state-root /var/tmp/kprog-tmp/perf/shared-hash-regression --persist-output --out $(RAW)/$(CASE)

.PHONY: costs
costs:
	DEBUGINFOD_URLS= python3 $(HERE)/costs.py $(RAW) $(CASE) > $(RAW)/$(CASE).costs.log 2>&1

.PHONY: compare
compare:
	python3 $(HERE)/compare.py $(RAW) > $(RAW)/comparison.log
