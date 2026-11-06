# Startup helper and anonymous-load increment

The x86 simulator dispatch now forwards public Linux helpers160 (coarse clock)
and173 (function IP) through their typed helper calls. The67-row generated
contract retains all65 earlier helpers. The anonymous manifest selector compares
complete original bytecode, so equal-length anonymous programs cannot select
each other by name, length or manifest ordering. Missing/invalid selectors fail.

Validation:

- Full immutable formal check passes;4,100 selector and18,690 typed-call/full-register host cases pass. Negative proofs and all29 positive micro proofs compile.
- Eleven anonymous-selector host checks pass, including same-length values0/1, malformed hex, missing selectors, type mismatch and ambiguity.
- In a private strict shim, four actual loads (anonymous0,1,clock and a program named `native_lab_stub`) execute expected returns with generation1. Two previous bypass controls retain generation0; bad selectors exit97.
- An actual libbpf object startup replaces all six successful programs, including its transient probes, with bound native programs. Fresh runs with actual load flags0 and8 both return127/generation1. The private loader uses the kernel’s ordinary KPROBE helper173 body for the captured attach type0; lane T owns the general type/attach-aware resolver. The shared shim has not yet adopted this private change.
- The source-bytecode compiler uses existing llvmbpf instruction lowering and LLVM function composition. Five-argument calls, saved caller R6 and backward subprogram calls return165/177/165 on both the CPU and bound KVM. No vendor app, workload or launcher changed.

An external native helper tail-jump exposed a linker problem: its unresolved
PLT32 jump shrinks during proof linking and loses the helper operation. The
coarse-clock first failure is retained. The new source compiler emits ordinary
calls with LLVM’s `-disable-tail-calls`; repair of existing native tail-jumps
remains active work. Dynamic-map probes and further application programs also
remain active work. No complete corpus app or matching-work timing is claimed.

The completed readonly census rerun has the following **artifact** outcomes;
internal functions and alternate builds are included, so these are not actual
application-program denominators. Every failed artifact retains its raw error.

| Application | Artifacts | Generated | Specialization failed |
| --- | ---: | ---: | ---: |
| bcc | 34 | 33 | 1 |
| cilium | 82 | 58 | 24 |
| katran | 6 | 5 | 1 |
| otelcol-ebpf-profiler | 30 | 28 | 2 |
| tetragon | 809 | 193 | 616 |
| tracee | 175 | 112 | 63 |

Failure causes in these707 artifact records:

- 401: undefined entry/input register.
- 155: undefined architectural flags/carry.
- 129: unresolved helper copy-source stack relation.
- 13: undefined saved bytes escape private stack.
- 2: undefined native ABI stack value at 0x2ba: inc    QWORD PTR [r14].
- 1: undefined native ABI stack value at 0x3b2: inc    QWORD PTR [r14].
- 1: undefined native ABI stack value at 0x1223: inc    QWORD PTR [r14].
- 1: undefined native ABI stack value at 0x2d5b: inc    QWORD PTR [r14].
- 1: undefined native ABI stack value at 0x384: inc    QWORD PTR [r14].
- 1: undefined native ABI stack value at 0x37e: inc    QWORD PTR [r14].
- 1: undefined native ABI stack value at 0x1561: or     QWORD PTR [rsp+rax*8+0x10],rcx.
- 1: undefined native ABI stack value at 0x1554: or     QWORD PTR [rsp+rax*8+0x10],rcx.

Actual successful-load/resident denominators and BCC25-entry verifier outcomes
are retained in [readonly-layout.md](readonly-layout.md). The completed helper census independently repeats429/1,136 generated and707
recorded failures against the full-formal-checked immutable source export.
Neither census is combined with earlier verifier results.

Commands:

```sh
make -f corpus/results/kprog_app_coverage_20261106/anonymous.mk host helper-host helper-micro
make -f corpus/results/kprog_app_coverage_20261106/anonymous.mk build kvm
make -f corpus/results/kprog_app_coverage_20261106/anonymous.mk object-startup-proofs object-kvm
make -f corpus/results/kprog_app_coverage_20261106/anonymous.mk source-call-proofs source-call-cpu source-call-kvm
make -f corpus/results/kprog_app_coverage_20261106/anonymous.mk helper-census
```

`startup-helper-artifacts.tar.gz` preserves the private shim/loader sources,
exact bytecode/native/proof inputs, raw guest logs, previous failures, generated
readonly census sources and native proof inputs, and the immutable formal source.
Top-level invocation logs are retained alongside it.
