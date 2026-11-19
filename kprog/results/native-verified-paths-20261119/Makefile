ROOT := /workspaces/repository
MODE ?= verified
.PHONY: prepare test
prepare:
	python3 $(ROOT)/kprog/results/native-verified-paths-20261119/prepare.py
test:
	python3 $(ROOT)/kprog/results/native-verified-paths-20261119/test.py $(OUT) $(MODE)
