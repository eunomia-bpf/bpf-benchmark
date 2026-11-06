ROOT := $(abspath ../../../../..)
FROZEN := $(ROOT)/kprog/fidelity/build-x86-after-lea-complete
.PHONY: check
check:
	$(CC) -O1 -g -std=gnu11 -static $(ROOT)/kprog/fidelity/driver.c $(FROZEN)/generated.o $(FROZEN)/native.S -o $(FROZEN)/cpu-differential-driver-layout
	python3 check.py $(FROZEN)/cpu-differential-driver-layout
