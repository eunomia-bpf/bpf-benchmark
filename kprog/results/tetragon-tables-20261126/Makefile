.PHONY: reproduce check-calls
reproduce:
	python3 reproduce.py $(REQUESTS)
check-calls:
	$(CC) -c calls.S -o calls.o
	python3 check_calls.py $(REVISION)

.PHONY: compile
compile:
	python3 compile.py
