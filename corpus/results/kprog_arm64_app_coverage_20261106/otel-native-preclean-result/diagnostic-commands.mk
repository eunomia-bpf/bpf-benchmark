ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/arm64/build/a-ir-diagnostic
SRC := $(ROOT)/corpus/results/kprog_arm64_app_coverage_20261106/otel-real-v8/compile-sources/otel_perf_unwind_native.bpf.c
.PHONY: front promote
front:
	prlimit --as=17179869184 --core=0 -- clang -g -O2 -Xclang -disable-llvm-passes -mcpu=v4 -target bpf -D__TARGET_ARCH_arm64 -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src -I/usr/include/x86_64-linux-gnu -I$(ROOT)/kprog/arm64/micro-prog -emit-llvm -c $(SRC) -o $(OUT)/frontend.bc
	llvm-dis-18 $(OUT)/frontend.bc -o $(OUT)/frontend.ll
promote:
	prlimit --as=17179869184 --core=0 -- opt-18 -passes='mem2reg,instcombine,simplifycfg' $(OUT)/frontend.bc -o $(OUT)/promoted.bc
	llvm-dis-18 $(OUT)/promoted.bc -o $(OUT)/promoted.ll
.PHONY: preclean
preclean:
	prlimit --as=17179869184 --core=0 -- opt-18 -passes='instcombine,simplifycfg' $(OUT)/frontend.bc -o $(OUT)/preclean.bc
	llvm-dis-18 $(OUT)/preclean.bc -o $(OUT)/preclean.ll
.PHONY: cleanpromote
cleanpromote:
	prlimit --as=17179869184 --core=0 -- opt-18 -passes='sroa,instcombine,simplifycfg' $(OUT)/preclean.bc -o $(OUT)/cleanpromoted.bc
	llvm-dis-18 $(OUT)/cleanpromoted.bc -o $(OUT)/cleanpromoted.ll
.PHONY: optimize backend
optimize:
	prlimit --as=17179869184 --core=0 -- opt-18 -passes='default<O2>' $(OUT)/cleanpromoted.bc -o $(OUT)/optimized.bc
backend: optimize
	prlimit --as=17179869184 --core=0 -- llc-18 -mcpu=v4 -bpf-stack-size=4096 -filetype=obj $(OUT)/optimized.bc -o $(OUT)/otel_perf_unwind_native.bpf.o
.PHONY: stop-preclean
stop-preclean:
	prlimit --as=17179869184 --core=0 -- opt-18 -passes='instcombine<max-iterations=16>,simplifycfg' $(ROOT)/corpus/results/kprog_arm64_app_coverage_20261106/otel-real-v15/compiler-ir/otel_perf_unwind_stop.front.bc -o $(OUT)/stop-preclean.bc
	prlimit --as=17179869184 --core=0 -- opt-18 -passes='sroa,instcombine<max-iterations=16>,simplifycfg,default<O2>' $(OUT)/stop-preclean.bc -o $(OUT)/stop-optimized.bc
	prlimit --as=17179869184 --core=0 -- llc-18 -mcpu=v4 -bpf-stack-size=4096 -filetype=obj $(OUT)/stop-optimized.bc -o $(OUT)/otel_perf_unwind_stop.bpf.o
