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
