ROOT := $(abspath ../../../../..)
OBJECT := $(ROOT)/kprog/fidelity/build-arm64/wsp-return-negative.o
.PHONY: check
check:
	install -d $(dir $(OBJECT))
	aarch64-linux-gnu-gcc -c case.S -o $(OBJECT)
	python3 check.py $(OBJECT)
