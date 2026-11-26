.PHONY: reproduce check-calls
reproduce:
	python3 reproduce.py $(REQUESTS)
check-calls:
	$(CC) -c calls.S -o calls.o
	python3 check_calls.py $(REVISION)

.PHONY: compile
compile:
	python3 compile.py

.PHONY: return-paths
return-paths:
	python3 return_paths.py $(REQUESTS)

.PHONY: compile-group return-pipeline
compile-group:
	python3 compile.py $(REQUEST) $(RECORDS)
return-pipeline:
	python3 return_pipeline.py

.PHONY: probe-hoisted
probe-hoisted:
	python3 hoisted_probe.py

.PHONY: check-hoisted
check-hoisted:
	$(CC) -c hoisted.S -o hoisted.o
	python3 check_hoisted.py $(REVISION)

.PHONY: hoisted-pipeline
hoisted-pipeline:
	python3 return_pipeline.py $(CURDIR)/hoisted-pipeline 9

.PHONY: backend-o2-group backend-o2-control
BACKEND_OUT ?= $(CURDIR)/backend-o2-control
backend-o2-group:
	python3 backend_control.py $(REQUEST) $(RECORDS)
backend-o2-control:
	python3 return_pipeline.py --backend-o2 $(BACKEND_OUT) 39

.PHONY: spill-liveness
spill-liveness:
	python3 spill_liveness.py

.PHONY: check-return-lea
check-return-lea:
	$(CC) -c calls.S -o calls.o
	python3 check_return_lea.py $(REVISION)

.PHONY: unsplit-group unsplit-control
UNSPLIT_OUT ?= $(CURDIR)/unsplit-control
unsplit-group:
	python3 unsplit_control.py $(REQUEST) $(RECORDS)
unsplit-control:
	python3 return_pipeline.py --unsplit $(UNSPLIT_OUT) 39
