HERE := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
ROOT := $(abspath $(HERE)/../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-x86-register-read-bpf
CXX ?= g++
CC ?= cc
CLANG ?= /usr/lib/llvm-18/bin/clang
OBJECTS := $(wildcard $(ROOT)/runner/build-llvmbpf/CMakeFiles/micro_exec.dir/workspaces/repository/vendor/llvmbpf/src/*.o)
.PHONY: check
check:
	install -d $(BUILD)
	$(CLANG) -O2 -target bpf -mcpu=v4 -I$(HERE)/before -c $(HERE)/reads.c -o $(HERE)/before/reads.o
	$(CLANG) -O2 -target bpf -mcpu=v4 -I$(HERE)/candidate -c $(HERE)/reads.c -o $(HERE)/candidate/reads.o
	$(CC) -O2 -I$(HERE)/candidate -c $(HERE)/reads.c -o $(BUILD)/host.o
	$(CXX) -O2 -std=c++20 -I$(ROOT)/vendor/llvmbpf/include -I$(ROOT)/vendor/llvmbpf/src -I$(HERE) $(HERE)/run.cpp $(BUILD)/host.o $(OBJECTS) -L/usr/lib/llvm-18/lib -lLLVM-18 -lspdlog -lfmt -ldl -pthread -o $(BUILD)/check
	python3 $(HERE)/extract.py $(HERE)
	$(BUILD)/check $(HERE)
