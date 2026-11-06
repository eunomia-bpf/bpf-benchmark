# Captured source-map proof producer

The captured BCC global-data probe now generates a native object and its
canonical simulator proof with an explicit original-map binding. Its five
source instructions load MAP_VALUE at offset16, store42 through one eight-byte
write, and return0. No application map is allocated or initialized by the proof.

The frontend gives each source map identity one incomplete external native
object. References at different offsets share that object and retain their
relative offsets, so LLVM cannot invent disjoint storage for one source map.
The proof declares a strong external incomplete byte array and records the
native symbol, source LDDW index and proof symbol in `.native_lab.source_maps`.
The loader patches that external proof relocation to the original map base;
the compiled pointer addition supplies the source offset exactly once.

A new AUX bit on the existing pointer-load opcode selects MAP_VALUE provenance
(tag6). Object addresses retain tag5. The JSON contract generates the C/Lean
selector, and the handler theorem composes its result with the existing whole
64-bit pointer write. Old two-selector APIs and their theorems remain intact.
Native-link also preserves undefined PC32 zero-offset64-bit LEA relocations in
proof mode and resolves their native pointer literals before requiring an ELF
data section. Missing identities fail explicitly.

Completed checks:

- All74 linker regressions pass, including preserved external identity,
  resolved native literal and missing-identity rejection.
- The focused Lean selector/writeback proof and1,342 UBSan host cases pass.
  An isolated full formal check passes with349 builds and the complete C,
  Rust, wire and primitive-memory-width recipe. The first export omitted an
  internal kernel header, and the next run hit the existing EntryEnvironment
  SAT timeout; both logs are retained. The unchanged retry passes.
- The negative proof and all29 workload-derived micro proofs compile from
  copied inputs. The first compile exposed stale tracked generated C using
  the old one-argument PUSH API. Regenerating only the private source copy
  from the actual saved native proof ELFs repairs those inputs; no handler or
  proof condition was relaxed.
- The original BCC map probe, incomplete-extent variant and alias-aware variant
  have identical native and simulator instruction bytes. Lane T's actual KVM
  test of that pair passes generation-bound execution: store42 at16, all
  neighboring bytes preserved, and no map reset during binding. Its consumer,
  module and raw kernel evidence are published in `d25b4d7f4`.
- A two-offset source-map regression executes the generated native code on the
  real CPU, returns42 and preserves every neighboring byte. Multi-site source
  selectors retain exact FD bytes, so normalization cannot silently change a
  required alias relationship. Reusable multi-map alias-class metadata remains
  active integration work with the consumer.
- Fresh BCC phase13 generates/compiles all25 resident entries from the saved
  phase11 native/original objects. Additional tracepoint helper113, tracepoint
  zero and fentry zero probes generate/compile. This is preparation for the
  strict whole-application retry, not an application success or timing result.

Commands from the repository root:

```sh
make -f corpus/results/kprog_app_coverage_20261106/strict-runtime.mk test-link link-build
make -f corpus/results/kprog_app_coverage_20261106/strict-runtime.mk source-map-contract source-map-host source-map-lean
make -f corpus/results/kprog_app_coverage_20261106/strict-runtime.mk source-map-prepare source-map-formal
make -f corpus/results/kprog_app_coverage_20261106/strict-runtime.mk source-map-micro-prepare source-map-micro-refresh source-map-micro
make -f corpus/results/kprog_app_coverage_20261106/strict-runtime.mk source-map-proof-v3 source-map-alias bcc-transient-proofs bcc-refresh
make -f corpus/results/kprog_app_coverage_20261106/strict-runtime.mk build
make -f corpus/results/kprog_app_coverage_20261106/bcc-strict.mk package image corpus
```

Result directories are immutable attempts; use a fresh name when rerunning
an already completed generation. [Raw evidence](source-map-artifacts.tar.gz)
contains source/native/proof objects, compiler and formal logs, the two-offset
CPU result, the25-entry BCC snapshot and the tested formal sources. The other
five applications and the remaining BCC startup/runtime failures are still
being completed; none is excluded from the six-application goal.


The strict phase13 retry has now finished. It records37 required-bound native
replacements, including all eight global-data probes and four resident fentry
programs. Seven replacement loads are verifier rejections: six helper113
tracepoint probes report stack-pointer arithmetic with4294967289, and the
capable entry reports a forbidden modified-context-pointer dereference at88.
The helper probe also exposes an independent frontend bug: llvmbpf allocated
one stack byte although the helper writes eight through an R10-derived pointer.
These two implementation paths are being repaired; the old helper proof is a
retained failing input, not a native-execution positive.

The full raw run is `x86_kvm_corpus_20261106_175435_598627` in the evidence
archive. There is no completed native workload or matching-work comparison.
The source baseline has25 resident programs and77 successful startup loads;
37 replacements in a stopped restart do not replace that denominator.
