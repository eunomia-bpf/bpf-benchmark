ROOT := /workspaces/repository
TOOL := /workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir
.PHONY: test
test:
	python3 $(ROOT)/kprog/results/checked-array-c-20261119/test.py $(OUT) $(TOOL)
.PHONY: replay
replay:
	python3 $(ROOT)/kprog/results/checked-array-c-20261119/replay.py $(OUT)/replay $(ARCHIVE) $(REQUESTS)
.PHONY: real-proof
real-proof:
	$(TOOL) $(OUT)/otel/replay/1/frontend.bc -o $(OUT)/otel/baseline.bc
	llvm-link-18 $(OUT)/otel/replay/1/native.bc $(OUT)/helpers.bc -o $(OUT)/otel/linked.bc
	clang-18 -target x86_64-linux-gnu -O3 -march=native -foptimize-sibling-calls -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables -c $(OUT)/otel/linked.bc -o $(OUT)/otel/native.o
	clang-18 -target x86_64-linux-gnu -O3 -march=native -foptimize-sibling-calls -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables -c $(OUT)/otel/baseline.bc -o $(OUT)/otel/baseline.o
	$(ROOT)/kprog/x86/native_lab/native_link/target/release/native-link --input $(OUT)/otel/native.o --symbol trusted_x86_x86_sim_xdp --mode proof --preserve-entry-abi --output $(OUT)/otel/native.proof.o
	$(ROOT)/kprog/x86/native_lab/native_link/target/release/native-link --input $(OUT)/otel/baseline.o --symbol trusted_x86_x86_sim_xdp --mode proof --preserve-entry-abi --output $(OUT)/otel/baseline.proof.o
	llvm-objdump-18 -dr $(OUT)/otel/native.proof.o > $(OUT)/otel/native.asm
	llvm-objdump-18 -dr $(OUT)/otel/baseline.proof.o > $(OUT)/otel/baseline.asm
.PHONY: pipeline
pipeline:
	python3 $(ROOT)/kprog/results/checked-array-c-20261119/pipeline.py $(OUT)/pipeline
