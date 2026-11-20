ROOT := /workspaces/repository
OUT ?= /workspaces/kprog-raw/perf/dynamic-array-c-20261120/before
MODE ?= before
.PHONY: check replay receipt
check:
	taskset -c 16-19 nice -n 19 prlimit --as=8589934592 -- python3 $(ROOT)/kprog/results/dynamic-array-c-20261120/check.py $(OUT) $(MODE)
replay:
	$(MAKE) -f $(ROOT)/kprog/results/helper-sharing-20261120/Makefile replay OUT=$(OUT) REPLAY_ARGS='--capture /workspaces/kprog-raw/perf/percpu-array-c-20261120/otel-20261120T062059Z/service.tar.gz --requests 3 4'
receipt:
	cp $(OUT)/report.json $(ROOT)/kprog/results/dynamic-array-c-20261120/$(MODE)-result.json
	tar -czf $(ROOT)/kprog/results/dynamic-array-c-20261120/$(MODE)-evidence.tar.gz -C $(dir $(OUT)) $(notdir $(OUT))

.PHONY: compatibility run-replay
compatibility:
	install -d $(OUT)/array $(OUT)/percpu
	$(MAKE) -f $(ROOT)/kprog/results/checked-array-c-20261119/Makefile test OUT=$(OUT)/array
	$(MAKE) -f $(ROOT)/kprog/results/percpu-array-c-20261120/Makefile check OUT=$(OUT)/percpu
run-replay:
	install -d $(OUT)
	date -u +%FT%TZ > $(OUT)/started
	status=0; flock -s /workspaces/.agent-state/kprog-lanes/locks/image taskset -c 16-19 \
		nice -n 19 prlimit --as=17179869184 -- $(MAKE) -f $(ROOT)/kprog/results/dynamic-array-c-20261120/Makefile replay OUT=$(OUT) || status=$$?; \
		tar -czf $(OUT)/native-products.tar.gz -C /var/tmp/kprog-tmp/perf/helper-sharing 3 4 || exit $$?; \
		printf '%s\n' "$$status" > $(OUT)/exit-code; date -u +%FT%TZ > $(OUT)/finished; exit $$status
