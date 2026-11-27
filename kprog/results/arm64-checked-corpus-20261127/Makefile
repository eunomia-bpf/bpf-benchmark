.PHONY: guest
guest:
	python3 guest_controller.py $(CHECK_APP)
.PHONY: report
report:
	python3 report.py
.PHONY: ctx-compile
ctx-compile:
	prlimit --as=17179869184 taskset -c 16 python3 ctx_compile.py
.PHONY: ctx-operand
ctx-operand:
	install -d /workspaces/kprog-raw/perf/arm64-checked-corpus-20261127/operand-probe
	clang-18 -O2 -target bpf -c ctx_operand.c -o /workspaces/kprog-raw/perf/arm64-checked-corpus-20261127/operand-probe/probe.o
	llvm-objdump-18 -d /workspaces/kprog-raw/perf/arm64-checked-corpus-20261127/operand-probe/probe.o

.PHONY: callback-audit
callback-audit:
	python3 callback_audit.py
