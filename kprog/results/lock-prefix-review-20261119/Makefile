ROOT := /workspaces/repository
BUILD := /var/tmp/kprog-tmp/perf/lock-prefix-review
.PHONY: reproduce probe-atomics shared
reproduce:
	install -d $(BUILD)
	clang-18 -c $(ROOT)/kprog/results/lock-prefix-review-20261119/fixture.S -o $(BUILD)/fixture.o
	python3 $(ROOT)/kprog/results/lock-prefix-review-20261119/reproduce.py $(BUILD)/fixture.o $(OUT)

probe-atomics:
	python3 $(ROOT)/kprog/results/lock-prefix-review-20261119/probe_atomics.py $(OUT) $(BUILD)

shared:
	python3 $(ROOT)/kprog/results/lock-prefix-review-20261119/test_shared.py $(OUT) $(BUILD)
