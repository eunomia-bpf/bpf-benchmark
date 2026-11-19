BOUNDS := /workspaces/.agent-state/kprog-ck/verified-compiler/packet-bounds
.PHONY: test rebuild
test:
	python3 kprog/results/b-pointer-difference-20261119/test.py $(OUT) $(MODE)
rebuild:
	clang++-18 $$(llvm-config-18 --cxxflags) -std=c++17 -Ivendor/libbpf/include/uapi \
		kprog/x86/packet_bounds_ir.cpp -o $(BOUNDS) \
		$$(llvm-config-18 --ldflags --libs core irreader bitwriter analysis support --system-libs)
