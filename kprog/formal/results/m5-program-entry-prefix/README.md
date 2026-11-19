# Actual production ABI and cache prefix

M5 now composes the actual generated one-context call entry with the initial
189 ABI/local assignments and four cache initializers. The first segment uses
567 Clight transitions; entry adds one, and the cache stores add twelve, for
580 transitions to the actual post-cache successor. All production temporary
bindings are unchanged, including the original context temporary.

`prefix_source` checks the first segment against the emitted
`f_arm64_execute_compile.fn_body`. `cacheStage` and `afterCacheStage` are
extracted from that same production body; `cache_source` checks all four cache
assignments and their real successor. Neither successor is a mapped source tail.

The source prefix proof is shared rather than replayed in a second proof body.
`Arm64Producer.prefix_body_bound` takes the executing function, local environment
and ABI layout separately. Its only composite requirement is the actual ABI
record (216 bytes, fields at 0/48/68/80/88/208). The three local cells carry their
binding, fresh block and complete allocated Freeable range. The production
instantiation derives them from allocation correspondence. Full composite
environment equality is not required. Existing source entry APIs retain their
signatures and specialize this shared proof.

`Arm64Producer.initialize_caches_body` shares the original four-store memory
construction, readbacks, separation and framing with the production execution.
The production theorem derives its actual cache bindings, both zero base words
and both zero validity bytes. Permissions and the exact allocation frontier are
preserved; all caller observations are framed from the real call entry.

This is the actual pre-header prefix, not the later GPR pointer-table setup.
The three following helper-context setup assignments and kind-6 input calls
still need actual execution and provider composition. The separately proved
638-transition header/vector-loop suffix starts much later at `beforeHeader`;
entry and that suffix are not yet composed. Native-provider/original-context
semantics, table/SP contents, the actual signed32 return bridge and complete
handler/native refinements remain M5 obligations. Completed ISA families remain
zero. M6 follows M5.

Validation receipts are in `validation.json`; public type/axiom queries are in
`Query.lean`. Raw commands, all attempted logs and exits stay under
`/workspaces/kprog-raw/formal/m5-program-entry-prefix`. Checks run on CPU17,
one worker, 32 GiB address space and unchanged proof caps, with control work on
CPU16. The 2026-11-19 18:18:59 coordination rule allows host checks without the
timing lock. No simulator C, compiler, runtime, kernel, image, base, benchmark,
paper or design source is changed by this step.

Focused build: 173 jobs passed (880.256 s, including the 433 s shared-prefix
rebuild and dependent proofs). Eleven public type checks and ten axiom reports
passed (1.559 s). One full `lake build` passed 348 jobs (552.049 s), including existing
MOVK call/native/context and provider/register-storage consumers. The closed
syntax/layout facts use standard logical axioms; execution facts also inherit
`CC.externalFunctionsSem` and `CC.inlineAssemblySem` through imported `Step2`.
No new axiom, `sorry`, external transition or proof-limit increase is introduced.
The two failed elaboration attempts are retained in the validation receipt and
raw logs. The last whole `make check` pass is commit
`5236c0e9677f635526fdd515cde5195b2ba0810c`; it is not a fresh check of this step.
Fresh full Lake and `make check` remain due at final M1–M6 closure.
