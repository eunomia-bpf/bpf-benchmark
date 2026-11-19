ROOT := /workspaces/repository
MODE ?= normalized
.PHONY: prepare test
prepare:
	python3 $(ROOT)/kprog/results/native-private-stack-20261119/prepare.py
test:
	python3 $(ROOT)/kprog/results/native-private-stack-20261119/test.py $(OUT) $(MODE)
