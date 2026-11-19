ROOT := /workspaces/repository
BUILD := /var/tmp/kprog-tmp/perf/lock-prefix-review
.PHONY: reproduce
reproduce:
	install -d $(BUILD)
	clang-18 -c $(ROOT)/kprog/results/lock-prefix-review-20261119/fixture.S -o $(BUILD)/fixture.o
	python3 $(ROOT)/kprog/results/lock-prefix-review-20261119/reproduce.py $(BUILD)/fixture.o $(OUT)
