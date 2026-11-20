ROOT := /workspaces/repository
HASH_CAPTURE_ARGS ?= --capture /workspaces/kprog-raw/perf/helper-sharing-20261120/bcc-20261120T051434Z/service.tar.gz --requests 15 20
.PHONY: replay
replay:
	python3 $(ROOT)/kprog/results/helper-sharing-20261120/replay.py $(OUT) $(REPLAY_ARGS)

.PHONY: receipt
receipt:
	python3 $(ROOT)/kprog/results/helper-sharing-20261120/receipt.py

.PHONY: hash-tail
hash-tail:
	install -d $(OUT)/host $(OUT)/production $(OUT)/bcc
	date -u +%FT%TZ > $(OUT)/started
	$(MAKE) -f $(ROOT)/kprog/results/hash-c-lto-20261120/Makefile check OUT=$(OUT)/host
	cp /workspaces/kprog-raw/perf/hash-c-lto-20261120/production-20261120T041613Z/stock-result.json $(OUT)/production/stock-result.json
	$(MAKE) -f $(ROOT)/kprog/results/hash-c-lto-20261120/Makefile native OUT=$(OUT)/production
	$(MAKE) replay OUT=$(OUT)/bcc REPLAY_ARGS='$(HASH_CAPTURE_ARGS)' -f $(ROOT)/kprog/results/helper-sharing-20261120/Makefile
	date -u +%FT%TZ > $(OUT)/finished

.PHONY: hash-tail-receipt
hash-tail-receipt:
	python3 $(ROOT)/kprog/results/helper-sharing-20261120/hash_tail_receipt.py $(OUT)

.PHONY: grouping grouping-receipt
grouping:
	$(MAKE) -f $(ROOT)/kprog/results/helper-sharing-20261120/Makefile hash-tail OUT=$(OUT) HASH_CAPTURE_ARGS='--capture /workspaces/kprog-raw/perf/hash-tail-20261120/bcc-20261120T052633Z/service.tar.gz --requests 14 20'
	$(MAKE) -f $(ROOT)/kprog/results/lpm-c-lto-20261120/Makefile post-b RAW=$(OUT)/lpm STOCK=/workspaces/kprog-raw/perf/lpm-c-lto-20261120/stock-20261120T022137Z
	$(MAKE) -f $(ROOT)/kprog/results/helper-sharing-20261120/Makefile replay OUT=$(OUT)/otel REPLAY_ARGS='--capture /workspaces/kprog-raw/perf/helper-sharing-20261120/otel-20261120T045640Z/service.tar.gz --requests 3 4'
	date -u +%FT%TZ > $(OUT)/grouping-finished

grouping-receipt:
	python3 $(ROOT)/kprog/results/helper-sharing-20261120/grouping_receipt.py $(OUT)
