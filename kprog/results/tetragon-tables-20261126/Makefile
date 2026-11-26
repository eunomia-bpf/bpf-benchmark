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
