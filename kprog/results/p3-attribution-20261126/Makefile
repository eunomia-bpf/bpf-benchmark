ROOT := /workspaces/repository
HERE := $(ROOT)/kprog/results/p3-attribution-20261126
APP ?= tetragon/observer
OUT ?= $(HERE)

.PHONY: diagnostic profile batch checks analyze pmu-check
diagnostic:
	python3 $(HERE)/diagnostic.py $(APP) $(OUT)
profile:
	EVENT=cpu_core/cycles/ PERIOD=1000000 bash $(ROOT)/kprog/results/profile-20261123/profile-host.sh $(APP) $(OUT)
batch:
	python3 $(HERE)/batch.py $(OUT)
checks:
	python3 $(HERE)/batch.py $(OUT) diagnostic
analyze:
	bash $(HERE)/analyze.sh $(OUT)
pmu-check:
	/workspaces/.agent-state/kprog-ck/perf-tool/perf stat -a -C 0-7 -e cpu_core/cycles/ -- sleep 1

.PHONY: module-control module-normal generic-control control-dry-run
KEY_SIZES := 2 4 8 12 14 16 20 24 32 36 38 40 41 48 64 88 224 256 260
module-control:
	$(MAKE) -C $(ROOT)/kprog/perf/direct-native module KCFLAGS='$(foreach N,$(KEY_SIZES),-Dkprog_htab_elem_k$(N)=kprog_htab_control_k$(N))'
module-normal:
	$(MAKE) -C $(ROOT)/kprog/perf/direct-native module
generic-control:
	python3 $(HERE)/generic_control.py $(OUT)
control-dry-run:
	python3 $(HERE)/generic_control.py $(OUT) --dry-run
