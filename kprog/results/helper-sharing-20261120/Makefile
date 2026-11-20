ROOT := /workspaces/repository
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
	$(MAKE) replay OUT=$(OUT)/bcc REPLAY_ARGS='--capture /workspaces/kprog-raw/perf/helper-sharing-20261120/bcc-20261120T051434Z/service.tar.gz --requests 15 20' -f $(ROOT)/kprog/results/helper-sharing-20261120/Makefile
	date -u +%FT%TZ > $(OUT)/finished
