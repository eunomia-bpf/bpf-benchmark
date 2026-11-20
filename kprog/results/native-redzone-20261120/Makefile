ROOT := /workspaces/repository
.PHONY: before after
before:
	python3 $(ROOT)/kprog/results/native-redzone-20261120/check.py $(OUT) before
after:
	python3 $(ROOT)/kprog/results/native-redzone-20261120/check.py $(OUT) after

.PHONY: receipt
receipt:
	python3 $(ROOT)/kprog/results/native-redzone-20261120/receipt.py
