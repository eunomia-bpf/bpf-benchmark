Actual entry to the architectural register relation
==================================================

`Arm64ProgramEntryRegisterView.entry_represents` strengthens the actual
initialized-body execution with `Arm64Registers.Represents`. The relation
holds in the same reached memory, at its allocation frontier, alongside the
original 98 provider traces, 92 typed header readbacks, initialized values,
register storage, Freeable ranges, context temporary and caller frame.
The actual function, environment and continuation are retained.

The proof derives SP zero through its header pointer, NZCV bytes by typed local
identity, and all 32 vector pairs through the initialized pointer/data arrays.
The 64-word vector ABI index `2*i + high` is proved to address the same data as
`16*i + 8*high`. The existing GPR reader supplies all 31 raw value/tag pairs;
the actual stored 32-bit tags are proved equal to the existing byte-tag view.

`raw_values_represent` and `raw_native_registers` were lifted from the existing
source proof in `Arm64EntryAdmissibility`. Both routes now reuse these same
proofs. The original source theorem signatures are unchanged. Context ValueRep
supplies x0's numeric binding; scalar values represent themselves; x30's zero
payload is materialized with its RETURN origin. No new ISA model or initializer
execution is introduced.

`NativeBindings` records the remaining same-invocation assumptions explicitly:
native x0/context, x30/return origin, other GPR values, SP origin, the actual
masked flag bytes, and both vector halves. It does not assume a completed
register relation or successful borrowed reads. ProviderAt contracts remain
explicit too. Deriving these contracts from the native input ABI and original
context, physical memory/ranges/aliasing, relative caches, all-outcome admission,
the actual return bridge and complete ordinary MOVK refinement remains M5 work.
This register predicate does not claim PC or full native-memory refinement.
O1/O2/O4 have not been recounted; completed ISA-family count remains 0.
M6 follows M5.

From `kprog/formal`, with the original proof limits:

```
ulimit -v 33554432
export LEAN_NUM_THREADS=1
taskset -c 17 nice -n 19 lake build KProgFormal.ClightRefinement.Arm64ProgramEntryRegisterView
taskset -c 17 nice -n 19 lake env lean -j1 results/m5-program-entry-register-view/Query.lean
taskset -c 17 nice -n 19 lake build
```

Raw logs and resource/check receipts remain under
`/workspaces/kprog-raw/formal/m5-program-entry-register-view`.
No C/runtime/compiler/kernel/base/image/benchmark/paper/design source changed
in this step. Fresh final Lake/make check and frozen-byte confirmation remain
due after M5/M6.

Focused compilation passed 195 jobs on the first attempt and all nine public
type/axiom queries passed. The full Lake confirmation is running; the receipt
records that pending status explicitly.
