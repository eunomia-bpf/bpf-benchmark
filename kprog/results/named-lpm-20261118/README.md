# Reuse the native trie for exact loaded LPM shapes

The smallest change adds a private lookup kind for a loaded LPM map with
a 16-byte key (four prefix bytes, twelve data bytes). The existing named
map provenance selects that exact fact. On x86 with the existing layout,
the call reaches the current shared ARRAY/LPM path. Other shapes keep their
kernel target. This reuses the existing native trie body and leaves its
runtime guards in place; direct entry can follow measured benefit.

The shape test includes the actual loader translation unit and exercises
loaded types/key sizes, the legacy site and target/name preservation. The
Rust test checks actual ELF map provenance, eligible versus ordinary kinds,
layout availability and external helper targets. Existing exhaustive trie
execution tests, the full suite and all 295 captured plans follow. Legacy
plans retain their kind, so their replay is compatibility evidence. A new
image must record actual loaded-shape selection before an app speed claim.

Host work holds timing SH/image SH, CPU19, one worker and32GiB AS. The live
checked guest's canonical CLI/base/image remain in use. Omp owns the later
frozen image/check/OTel timing batch, with all LTO on and installed size
reported alongside per-call and body/helper/map time.

2026-11-18T00:14:31Z — Named LPM shape source and full host tests completed; actual logs and source.patch committed. Raw: /workspaces/kprog-raw/perf/named-lpm-20261118/host-20261118T001244Z-2827763. Production unit-entry build and captured-request emission follow; canonical CLI stays unchanged; installed/time results remain pending.

Execution integration 2830609 ended101/SIGSEGV at00:16:37Z. The new fixture invoked an entry whose JmpEnd targets the kernel-owned epilogue after the blob; it omitted the RET that existing executable rewrite fixtures append at that boundary. A test-only forward correction appends that epilogue. The completed62-test static binding/18-shape loader/295legacy emission results remain recorded; real hit/miss execution is pending the corrected test. All failed raw output stays under integration-20261118T001550Z-2830609.
