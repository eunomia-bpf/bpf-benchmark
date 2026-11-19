# Conservative stack-cache enumeration

The existing ABI analysis collects possible full-width store destinations.
The generator emits aligned arena cells at those positions. Unknown
destinations or RSP values retain the complete enumeration. All source
alias kinds remain: False is not evidence of a scalar source. Shared C
cache writers remain unchanged. Register arithmetic, pointer-index LEA,
conditional loads and zero/unknown-count shifts preserve conservative
stack aliases. An analyzed frame enables the arena even without literal
RSP/RBP memory syntax. No runtime check, flag or limit is added.

PERF 2026-11-19T18:45:59Z: Worker247988 completed0 at18:42:15Z. All18selection
cases,3normal B emissions and72shared-C cases per full/sparse layout pass.
The latter run Clang18 O3 with UBSan instrumentation and installed libubsan,
cover all9tags, direct/aliased addressing, two slots, partial writes,
release observations and replanting. Retained Tetragon6 render uses16cells
(previous53) and the same424B arena; its full B has not yet been compiled.
Actual rows/commands/logs: /workspaces/kprog-raw/perf/sparse-stack-cache-20261119/check-20261119T184205Z-247988.

Initial failures remain in the same raw parent:214752 had missing oracle
wrapper declarations;244118 caught an omitted register-only frame;244527
could not link Clang's absent sanitizer runtime;245360/246631 used wrong
oracle AUX/displacement operands. The earlier attribution of that
sanitizer report to ordinary modular pointer arithmetic was premature and
is superseded:7087690ee fixes the test operands, and the sanitizer now
passes both layouts. No production handler changed to accommodate them.

These are component preservation and compiler results. Retained Tetragon
B frame/emission, stock acceptance, current-app coverage and performance
remain open. Production diff is43additions/7deletions across the two
existing generator files; tests target alias and lifetime loss directly.

PERF 2026-11-19T18:52:30Z: Full retained-Tetragon compilation251817 is live, parent1,
CPU20/32GiBAS. Actual sourceb1e2a7cad plus peer record2c366ca95, run
/workspaces/kprog-raw/perf/sparse-stack-cache-20261119/tetragon-20261119T185126Z-251817.
The two standard preprocessing pieces pass in0.308/0.284s, producing4.7MiB
joined C; the normal O1 frontend started18:51:29Z and is pending. This is
new source with16cache cells; it repeats neither the unchanged old input
nor O3. Packet-bounds alone takes imageSH; other host stages use no timing
lock under the latest18:18 coordinator rule. No kernel/base/image changes.

First launcher250823 failed before a compiler command because the optional
external timer was absent. Its raw remains; b1e2a7cad records monotonic
walltime directly. Announced replacement251396 left no run directory or
surviving process, so it is not a started compile. Replacement251817 was
confirmed with persistent run state and parent1 before this checkpoint.
No full B emission, frame reduction or stock success is claimed yet.

PERF 2026-11-19T18:55:27Z: Job251817 normal O1 frontend passes in94.592s; bounds
passes3.521s, preserving the standard interface/limits. Actual frontend
IR16459728bytes, bounds IR11571164bytes; these are
this input's sizes, not a speedup against an unmatched old compile. The
normal pre-PEI backend started18:53:07Z and remains pending.
tetragon-partial.json records actual commands/statuses; no final B,
physical frame, stock/current-app or speed result is claimed.
