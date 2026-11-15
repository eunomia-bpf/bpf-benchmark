# CFG-resolved helper identities

2026-11-15; source `399a6bab0`. The linker now computes register-call helper
identities over actual control flow. A call binds only when all reachable
predecessors agree. The analysis models register copies, partial writes,
caller-saved clobbers, backedges and the real relative-code-table destinations.
Unrecognized indirect branches conservatively reach every instruction.
Tail-frame setup uses the same helper facts. Numeric helper loads and observed
named-helper addresses retain their values; the old lexical tracker and
adjacency lookahead were removed.

The final subset passes **38 Rust tests**, with one existing ignored test.
New cases distinguish unreachable lexical assignments from reachable joins,
invalidate partial writes and caller-clobbered values, and revisit loop
backedges. A full linker/host counterexample checks that the selected helper
relocation targets helper 4 rather than an unreachable helper 1, and that a
later scalar observation still reads the numeric helper value 4.

C's rebuilt Tetragon `event_execve` object has SHA256
`d307c102c4a14cfe44995e9d697a2192d05a39ea53a8edf10ae439381305df35`.
This retained product predates `a01ef4879`, which removes the vendor-source
splits used by that build. Its machine-code shape is a linker regression
input; it does not certify the subsequently required untouched-source/header
producer route. Fresh products still need their application checks.
The analysis resolves **252 helper sites**, including **39 R13 calls**.
R13 at 0x1629 is compatibility read (ID 4); at 0x1f57 it is kernel read
(ID 113). The initial test incorrectly expected all R13 sites to be helper 4;
that failure is retained. The next full proof attempt reached a separate
shared-`.rodata` table-range failure. The final helper regression isolates
identity analysis and does not relabel that full-proof failure as success.
An initial host-regression compile error omitted a pointer-to-integer cast;
its failure and corrected result are also retained.

The actual-object test requires C's rebuilt product and reads it in place;
its SHA is computed from the bytes analyzed. No source/object copy or app
rebuild is made by the test. Raw logs:
`/workspaces/kprog-raw/perf/20261115-helper-cfg`.

The 38-test logs capture the helper step before the separate rodata-span fix.
`tetragon.json` was copied after the follow-up rodata-span test had completed:
its helper facts are unchanged, while its proof size/relocation fields belong
to that later fix, documented in `../rodata-spans/report.md`. Those proof
fields are not a result of `399a6bab0` alone.
No normal CLI/base publication, kernel installation, application execution,
throughput, per-call speed or code-size gain is claimed.

2026-11-15T17:22Z: the old in-place application assertion is retired as a
unit test: C's new header-route object has no R13 calls, so expecting39 at
fixed offsets tests a removed product's register allocation. Its historical
receipt above remains. The deterministic replacement retains the actual
failure class (R13=4 over an unreachable1, then rebind113) and checks distinct
compat/kernel-read identities and relocation targets. Current application
objects are inventories through --show helper-site JSON, without assuming
the old object's offsets/counts. Clock suite first compiled with a test-only
lifetime error, then passed its new seven shapes but hit this stale artifact
assertion; both failures remain raw. Full corrected-suite result pending.
