ROOT := /workspaces/repository
TOOL := /var/tmp/kprog-tmp/perf/native-base-roots
.PHONY: inspect
inspect:
	install -d /var/tmp/kprog-tmp/perf
	clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 $(ROOT)/kprog/results/native-base-roots-20261119/roots.cpp -o $(TOOL) $$(llvm-config-18 --ldflags --libs core irreader analysis support --system-libs)
	$(TOOL) $(INPUT) > $(OUT)
