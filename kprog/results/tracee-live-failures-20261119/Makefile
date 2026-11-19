.PHONY: inspect recover
inspect:
	python3 kprog/results/tracee-live-failures-20261119/inspect.py $(SERVICE) $(OUT)

recover:
	install -d $(OUT)
	tar -czf $(OUT)/completed-capsules.tar.gz --transform='s,^,service/requests/,' -C $(REQUESTS) 27.success.tar.gz 28.success.tar.gz 30.success.tar.gz
	$(MAKE) -f kprog/results/tracee-live-failures-20261119/Makefile inspect SERVICE=$(OUT)/completed-capsules.tar.gz OUT=$(OUT)
