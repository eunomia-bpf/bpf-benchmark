ROOT := /workspaces/repository
HERE := $(ROOT)/kprog/results/p3-attribution-20261126
APP ?= tetragon/observer
OUT ?= $(HERE)

.PHONY: diagnostic profile batch checks pmu-check
diagnostic:
	python3 $(HERE)/diagnostic.py $(APP) $(OUT)
profile:
	EVENT=cpu_core/cycles/ PERIOD=1000000 bash $(ROOT)/kprog/results/profile-20261123/profile-host.sh $(APP) $(OUT)
batch:
	python3 $(HERE)/batch.py $(OUT)
checks:
	python3 $(HERE)/batch.py $(OUT) diagnostic
pmu-check:
	/workspaces/.agent-state/kprog-ck/perf-tool/perf stat -a -C 0-7 -e cpu_core/cycles/ -- sleep 1
