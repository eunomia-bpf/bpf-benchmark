ROOT := $(abspath ../../..)
BASE := /workspaces/.agent-state/kprog-ck/verified-compiler
LLVM_CXXFLAGS := $(shell llvm-config-18 --cxxflags)
LLVM_LDFLAGS := $(shell llvm-config-18 --ldflags --system-libs --libs core irreader bitwriter analysis scalaropts transformutils)
.PHONY: baseline build-sim compare
baseline:
	python3 capture.py
	python3 default_ir.py before
build-sim:
	flock /workspaces/.agent-state/kprog-lanes/locks/image clang++-18 $(LLVM_CXXFLAGS) -O2 $(ROOT)/kprog/x86/compile_sim_ir.cpp $(LLVM_LDFLAGS) -o $(BASE)/compile-sim-ir
compare:
	python3 default_ir.py after
