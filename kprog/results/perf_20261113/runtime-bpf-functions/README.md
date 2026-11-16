2026-11-16T10:43:11Z

Source 0f5c55894 shares the existing exact BPF constant-leaf materializer
between producer lowering and trusted runtime LTO. Runtime LTO now accepts
explicit function bodies from a facts file and a program type; PERF_EVENT
context conversion remains selected for PERF_EVENT, with its previous default.
The runtime compiler reads embedded LLVM IR from P, materializes the supplied
MOV64/MOV32 immediate plus EXIT bodies before O3, then emits native code.
No app name, missing body or absent metadata supplies an implementation.

Validation through the committed Make entry on CPU 16 with an 8 GiB address-space
bound finished at 10:42:25 UTC: six values times 48 real indirect ABI vectors
through both compilers, five producer and four runtime malformed/unsupported
cases, and both absent-facts producer paths byte-identical to the retained
reference tool. Six signatures cover scalar widths, pointers and void returns;
MOV64 sign extension and MOV32 zero extension are checked. Existing public,
loader/cache and static-entry PERF_EVENT tests each pass 256 contexts with
zero mismatches. All fixture facts are constructed test inputs, never app facts.

```sh
make -r -f kprog/test/perf-context-lto.mk function-check check CPUS=16 \
  OUTPUT=/workspaces/kprog-raw/perf/20261116-runtime-bpf-functions
```

Raw compiler logs, exact inputs, binaries and output are retained in that raw
directory, including function-build.tar.gz and build.tar.gz. No image/base was
replaced during the active round. The live metadata consumer, shared P/B facts,
and compilation of nonconstant generated bodies remain open under P1j-d19.
This component does not establish native installation or performance.
