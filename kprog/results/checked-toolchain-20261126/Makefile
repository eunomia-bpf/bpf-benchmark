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

.PHONY: regressions
regressions:
	python3 regressions.py

.PHONY: consolidate arm-regressions
consolidate:
	flock /workspaces/.agent-state/kprog-lanes/locks/image python3 consolidate.py
arm-regressions:
	$(MAKE) -C ../arm64-common-flags-20261126 abi-checked-after helpers-mixed

.PHONY: frontend-before frontend-after
frontend-before:
	python3 frontend_check.py before
frontend-after:
	python3 frontend_check.py after

.PHONY: flags-after
flags-after:
	python3 flags_check.py after

.PHONY: frontend-broker
frontend-broker:
	python3 frontend_check.py broker

.PHONY: frontend-stock
frontend-stock:
	python3 frontend_stock.py
