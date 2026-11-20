# Actual production vector-input traversal

All 64 production vector initializers now have checked complete body equations,
mapped input temporaries, indices and actual successors. The certificate starts
at the actual post-flag vector-input stage and extracts the real successor after
all 64 visits. Each initializer agrees with the existing layout-parameterized
call/store schema.

The production vector array uses anonymous tag `__5183`; the source unit uses
`__2854`. `VectorLayout` carries only the selected composite record, its 16-byte
size and low/high field offsets 0 and 8. Both worlds instantiate those facts.
Actual local binding follows from the imported allocator and checked type/name
correspondence. The proof does not assume equality of the complete composite
environments.

The original vector call, return, store and readback/frame construction now
takes the function, environment, anonymous tag, input temporary and successor.
Each visit executes three internal call transitions, the explicit provider
outcome, and four internal return/store transitions. The original 512-byte
allocation/range/alignment witness constructs the store once; the actual and
source instances use that same proof. The original source type definitions and
public APIs are retained.

`Arm64ProducerVectorInputs.run_suffix_body` is the existing 64-visit induction
parameterized by function/environment, stages, input temporaries and per-input
execution. It retains ordered traces, earlier vector words, other-local loads,
unselected temporaries and caller/access/frontier frames. `initialized` derives
all 64 words and the actual array binding at the actual post-vector successor.

`entry_initialized` places these 64 traces after the preceding 34 GPR/flag
traces. All 31 register words/tags, 62 table pointers to those same cells,
masked flags/LR zero, caches, original context and caller resources survive
in the same reached memory. Provider availability, post-memory preservation
and native/original-context correspondence remain explicit invocation
obligations. This step does not establish native or all-outcome admission.

The remaining RAW/tag/SP/stack/context setup precedes the separately proved
header/body suffix. The return-type bridge, ISA refinement and O1/O2/O4 recount
remain M5 work. Completed ISA-family count is zero; M6 follows M5.

Public queries are in `Query.lean`; commands, exits, repaired attempts and final
source hashes are in `validation.json`. Raw data remains under
`/workspaces/kprog-raw/formal/m5-program-entry-vector-inputs`. Checks use CPU17,
one worker, 32 GiB address space and unchanged 200000-heartbeat/512-recursion
caps with `Elab.async false`; controls run on CPU16. Host checks follow the
2026-11-19 18:18:59 coordination rule without the guest timing lock. This step
changes formal proofs, receipts and its todo line. Fresh final Lake and
`make check` remain required when M1–M6 close.

Shared vector helpers passed 153 jobs. The final focused build passed 192 jobs,
all 18 public type/axiom queries passed, and one full Lake build passed 355 jobs.
The source-alias recursion and deferred-index-proof attempts remain in the raw
logs and receipt. Neither repair increased proof limits. Pure source/layout/
binding facts use standard logic; execution retains the imported Step2 external
and assembly semantic models. No new axiom was added.
