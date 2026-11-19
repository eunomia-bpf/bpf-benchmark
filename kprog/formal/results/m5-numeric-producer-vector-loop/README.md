# M5: actual Numeric live vector-pointer loop

The existing loop target/value/test/increment/store/iteration/setup/exit and
full traversal proofs now accept their execution world and matching Cenv
where needed. The combined header laws also take the actual callback-symbol
facts used by the preceding tail. All 11 original public execution contracts
remain projections. Actual source, offsets, counter arithmetic, store rights,
loop induction and memory/temporary framing are reused.

`initialized_vectors` appends only 362 silent transitions to the actual
Numeric initialized tail: four setup, 32 iterations of 11 and six exit.
The two header pointer arrays now point to the real prior VectorLocal block
at source offsets `16*i + (high ? 8 : 0)`. The existing borrowed vector reader
follows these pointers to all 32 low/high pairs of actual input words. The
small index map connects them to flattened input words `2*i + high`.
No separate ISA/C body or decoder is introduced.

All 12 scalar pointer fields and 16 typed tail fields survive. The earlier
table/LR/SP/stack/context identities, GPRs/x0 context-tag1/x30 zero-tag10,
flags, LR/SP zero, 64 input vector words, 24 stack tags, context cells and
initial204 global frame/permissions/allocation frontier remain. The same
98 ordered provider traces remain. Counter `_i` reaches 32; other temporaries
are unchanged, preserving the earlier `_ctx` readback.

The loop's exact write footprint is header offsets96..607. Actual local
binding distinctness frames the vector words and other locals. Both borrowed
cache-storage resources derive at the new reached memory from preserved
scalar pointers and actual rights; their cold values survive by local framing.
Earlier header construction and input visits execute once.

The current Numeric interface still needs a source proof that the consumer's
`_continuation` temporary retains its original parameter. It is not inferred
from having that parameter in the theorem. Complete register Storage/view,
caller/native/original-context/provider admission, relative caches, physical
memory/alias/origin/control and all-family O1/O2/O4 recount remain M5.
Complete ISA-handler/family count remains 0; M6 follows M5. The separate x86
atomic/released-alias formal bindings remain open.
No C/runtime, benchmark, paper/design, kernel, base or image change is made.

Raw attempts: /workspaces/kprog-raw/formal/m5-numeric-producer-vector-loop.
Every host command holds timing SH. One-worker builds CPU17/32GiB;
reads/queries/Git CPU16. Default200000 heartbeats/512 recursion/asyncfalse.
Validation outcomes and public axiom sets are recorded in validation.json.

Final validation: full Lake passes 333 jobs; all 15 public type/axiom
queries pass. Focused attempts are retained in validation.json. All ten Arm64
exports retain the byte baseline. The historical 23-file comparison records
12 changed x86 exports and exit 1; it remains an explicit
report, with no x86 atomic/alias proof claim. Current export bytes are
248620630; historical baseline bytes are 243488732. Native make check
remains due at final goal confirmation.
