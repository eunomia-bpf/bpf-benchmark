# Actual production flag inputs and LR initialization

The production post-table spine now carries kernel-checked equations for all
four actual flag declarations, their mapped input temporaries and real
successor chain. The following LR-zero assignment and its actual vector-start
successor are checked separately. Actual local bindings are derived from the
imported allocator and the existing name/type correspondence.

The existing flag call, return and scalar-store proofs now take the function,
local environment and input symbol explicitly. The source APIs instantiate
the same proof. The production instance resolves input block 59 and uses its
real continuation. Each visit has three internal call transitions, the stated
external outcome, and four internal return/store transitions. The stored byte
is the low bit of the supplied 64-bit word, using the original `flagWord` proof.
No provider purity, availability or full-word result is invented.

`Arm64ProducerFlagInputs.run_suffix_body` is the existing induction generalized
over function, environment, declaration/stage families, name correspondence,
successor links and per-input execution. Both source and production instances
retain all four traces, prior flag readbacks, other-local loads, unselected
temporaries and caller resources. The existing LR store construction likewise
now takes the function, environment, real successor and binding; its actual
instance executes three internal transitions and writes zero.

`initialized` reaches the actual `vectorStart` with all four masked flag bytes,
LR zero, actual/source local bindings and memory/temporary frames. Its provider
availability and post-memory preservation remain the explicit `ProviderAt`
contract. `entry_initialized` composes the preceding actual register/table
prefix with these visits, keeping the 30 GPR traces before the four flag traces.
All 31 register word/tag readbacks, 62 table pointers to those same cells, cache
base/validity readbacks and the original context temporary survive in one reached
memory, with caller frame, permissions and allocation frontier retained.

The 64 vector inputs and remaining RAW/tag/stack/context setup precede the
separately proved header/body suffix. Full native/provider/original-context and
all-outcome admission, the signed32/borrowed uint32 return bridge, ISA refinement
and O1/O2/O4 recount remain M5 work. Completed ISA-family count is zero; M6 follows
M5.

Public type/axiom queries are in `Query.lean`; commands, exits, source hashes and
all attempted checks are in `validation.json`. Raw data remains under
`/workspaces/kprog-raw/formal/m5-program-entry-flags`. Checks use CPU17, one worker,
32 GiB address space and unchanged 200000-heartbeat/512-recursion caps with
`Elab.async false`; controls run on CPU16. Host checks follow the 2026-11-19
18:18:59 coordination rule without the guest timing lock. This step changes
formal proofs, receipts and its todo line. Fresh final Lake and `make check`
remain required when M1–M6 close.

Shared flag helpers passed 152 jobs; shared traversal/LR helpers passed 170 jobs.
The final focused build passed 191 jobs, all 18 public type/axiom queries passed,
and one full Lake build passed 354 jobs. The repaired final-theorem name-resolution
attempt remains in the raw logs and receipt. Pure source/binding facts use standard
logic; execution retains the imported Step2 external and assembly semantic models.
No new axiom or proof-limit change was added.
