The actual Arm64 entry reaches its initialized body
==================================================

`Arm64ProgramEntryInitialized.entry_initialized` joins the actual RAW prefix to
the existing 638-step header/loop suffix. The actual function, environment,
continuation and memory are shared throughout. Its trace is the flattening of
the same 98 ordered provider traces; the suffix has no external calls.

The result carries all 12 scalar/header pointers, 64 vector pointers and 16
typed tail fields (including scalar constants and callback/data pointers). `Values` retains actual and canonical allocation
bindings, 31 word/tag readbacks, 62 table targets, flags and LR, 64 vector words,
24 stack-tag clears, signed SP zero, context/tag stores and both zero cache
words/validity bytes. The actual context temporary remains `ctx` and the loop
index is 32. Caller blocks, permissions and the actual allocation frontier are
preserved.

`Values.transport` uses the suffix's typed local-load frame, with checked
identifier separation. `Values.storage` derives the existing borrowed register
storage and write permissions in the same reached memory. `Values.gpr_reads`
follows both real pointer tables through the borrowed reader, preserving x0's
context pointer and x30's RETURN tag. `Values.cold_cache_reads` follows the real
header pointers to both zero validity bytes and base words. It supplies actual
cold-read facts rather than assuming a cache-state relation. No initializer is
replayed, no memory equality is assumed, and no alternate ISA model is added.

ProviderAt and context ValueRep contracts remain explicit. Relating these
inputs and the cell map to the native invocation, all-outcome admission, the
actual signed32 wrapper/borrowed uint32 return bridge and ordinary MOVK's
complete native refinement remain M5 work. O1/O2/O4 have not been recounted;
completed ISA-family count is 0. M6 follows M5.

Reproduce from `kprog/formal` using CPU17, nice19, one worker and 32 GiB address
space with the original proof limits:

```
ulimit -v 33554432
export LEAN_NUM_THREADS=1
taskset -c 17 nice -n 19 lake build KProgFormal.ClightRefinement.Arm64ProgramEntryInitialized
taskset -c 17 nice -n 19 lake env lean -j1 results/m5-program-entry-initialized/Query.lean
taskset -c 17 nice -n 19 lake build
```

The persistent raw directory is
`/workspaces/kprog-raw/formal/m5-program-entry-initialized`.
The receipt records resource settings, all attempted checks, queried axioms and
source hashes. This step changes only formal proofs, receipts and its todo line.
Fresh final Lake/make check and frozen-byte confirmation remain due after M5/M6.

Focused compilation passed 194 jobs and all five public type/axiom queries
passed. The initial proof commit recorded the full Lake confirmation as running.
The terminal result is recorded below and in validation.json. A comment was
clarified to distinguish the 92 typed header readbacks from pointers: three
tail fields hold scalar constants. This wording correction changes no proof
statement or term. The final focused and public-query reruns confirm the edit.

The final focused build passed 194 jobs, all five public type/axiom queries
passed, and one full Lake build passed 357 jobs. Earlier syntax, dependent-table
selection and definitional-conversion failures remain in the persistent logs.
All checks start at nice 19 on CPU17 with one worker and 32 GiB address space;
sampled Lake/Lean threads confirm that priority. Proof caps are unchanged.
The four data/storage/reader proofs use standard Lean logic; actual execution
also retains imported Clean external-function and assembly semantics. No new
axiom was added.
