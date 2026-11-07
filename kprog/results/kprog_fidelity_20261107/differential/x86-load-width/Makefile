HERE := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
ROOT := $(abspath $(HERE)/../../../../..)
BUILD := $(ROOT)/kprog/fidelity/build-x86-loadwidth
CXX ?= g++
CC ?= cc
CLANG ?= /usr/lib/llvm-18/bin/clang
OBJECTS := $(wildcard $(ROOT)/runner/build-llvmbpf/CMakeFiles/micro_exec.dir/workspaces/repository/vendor/llvmbpf/src/*.o)
.PHONY: check
check:
	install -d $(BUILD)
	$(CLANG) -O2 -target bpf -I$(HERE)/before -c $(HERE)/loads.c -o $(HERE)/before/loads.o
	$(CLANG) -O2 -target bpf -I$(HERE)/current -c $(HERE)/loads.c -o $(HERE)/current/loads.o
	$(CC) -O2 -I$(HERE)/current -c $(HERE)/loads.c -o $(BUILD)/host.o
	$(CXX) -O2 -std=c++20 -I$(ROOT)/vendor/llvmbpf/include -I$(ROOT)/vendor/llvmbpf/src -I$(HERE) $(HERE)/run.cpp $(BUILD)/host.o $(OBJECTS) -L/usr/lib/llvm-18/lib -lLLVM-18 -lspdlog -lfmt -ldl -pthread -o $(BUILD)/check
	python3 $(HERE)/extract.py $(HERE)
	$(BUILD)/check $(HERE)
