# Actual producer register storage for writing

`Arm64ProducerRegisterStorage.Storage` retains allocation-bound word/tag tables,
their real header roots and all 31 slots each, current write permissions for
every cell, and the actual signed-long SP pointer and word readback. Word cells
support Mint64 stores and tag cells Mint8unsigned stores at offset 0. Permission
facts derive from imported local allocation and the reached access map, rather
than from successful reads.

The storage laws prove that differently selected word/tag cells are distinct,
that a cell is separate from any differently named actual producer local, and
that every cell is fresh relative to the producer's caller frontier. The
separation law covers header/tables/SP/flags/vectors when their actual allocation
bindings and distinct names are supplied. These are Clight block facts; native
physical-address range aliasing remains a separate obligation.

The joint header proof now returns this storage resource together with the
existing concrete register relation from ONE actual 638-transition execution.
Stronger source witnesses retain it through RAW setup, 64 vector inputs, four
flag inputs, x30-zero/table initialization, 30 GPR inputs, and the actual
producer call. `producer_registers_initialized_with_storage` therefore constructs
both the register relation and writable storage through all 98 input visits.
No independent reached memories are identified and no storage contents are
assumed at the full producer boundary.

Existing observer APIs are projections of these same stronger witnesses.
Their signatures and callers remain valid, including the source-initialized
linked NOP contract. No additional runtime path or alternate evaluator is
introduced. Provider outcomes/post-memory/frame obligations and native input,
origin, physical memory/alias ABI and program-control bindings remain explicit.
The scalar writer's actual C procedure still needs execution/refinement proof.
M5/M6 and O1/O2/O4 recount remain open; complete ISA-handler refinement count
is 0.

Focused builds pass the storage/header subset (167 jobs) and affected full
producer/NOP subset (173 jobs). Full Lake passes 300 jobs. Four public type/axiom
queries pass: resource-carrying producer construction, local separation,
62-cell separation, and caller freshness. Three allocation laws use only
propext/Classical.choice/Quot.sound; source execution also mentions the already
imported external/assembly semantics. No new semantic axiom or C body is added.
All 23 exports (243488732 bytes) remain byte-identical to 9c617740f.

The first threading build exposed a one-space tactic indentation error in the
factored proof text. Correcting it preserved all proof limits. Initial storage
and header proofs passed directly; final affected and full builds pass, with
full Lake run once on final proof source. All attempts remain in raw.

From kprog/formal, under timing SH, CPU17 or18, `ulimit -v 33554432`,
LEAN_NUM_THREADS=1 and default 200000 heartbeats/512 recursion depth:

```
lake build KProgFormal.ClightRefinement.Arm64ProducerGprInputs KProgFormal.ClightRefinement.Arm64InitializedNop
lake env lean -j1 results/m5-register-storage/Query.lean
lake build
python3 results/clight-build/compare.py 9c617740f
```

Raw: /workspaces/kprog-raw/formal/m5-register-storage. C, exports and frozen
benchmark paths are unchanged. Last complete native make check passed at
5236c0e9677f635526fdd515cde5195b2ba0810c; it was not repeated for this Lean-only
step. Actual M5/M6 completion still requires fresh full Lake and make check.
