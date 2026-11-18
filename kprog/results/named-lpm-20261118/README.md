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

2026-11-18T00:20:01Z — Source `f98d0c87c` and execution regression `5da837c51` are pushed. The full Rust suite passes **62 tests**, with four existing opt-in tests. The pre-change focused regression compiled and failed on unknown private kind lpm12, as recorded in before.txt. The actual loader translation-unit fixture passes18 loaded type/key combinations plus the legacy site, preserving the kernel target and map name. All841 preceding standalone fixture/metadata files remain identical.

The ELF fixture covers all eight combinations of exact map identity, ordinary versus eligible LPM kind and layout availability. Its four executed candidate cases return the expected value pointer or NULL for full-depth hit, shorter-prefix miss, empty root and over-max prefix. This exercises the new binding and existing native routine together. Existing65590 trie/guard/ABI and34920 bit/prefix/flag cases also remain in the full suite.

Every one of the295 original captured requests emits, and the complete blob/relocation/map-patch/ABI artifact sets are byte-identical to the shared-zero source baseline. See compatibility.json. Those plans retain their original call kind; this establishes compatibility and preserves the recorded legacy programs. New-image captures must show actual lpm12 selection before claiming app activation or an app-size/time change.

| App | Legacy requests emitted | Identical artifact sets |
| --- | ---: | ---: |
| BCC |25/25|25|
| Cilium |47/47|47|
| Katran |1/1|1|
| OTel |14/14|14|
| Tetragon |39/39|39|
| Tracee |169/169|169|

Production growth is small: one lookup kind, loaded-shape selection in the existing schema function, existing call/identity behavior for other shapes, and one x86 target choice. The new routine copies zero trie implementations. It reuses current shared ARRAY/LPM code, retaining its type/data-size guards. An eligible program previously containing only raw trie calls may gain one native routine; installed growth and per-call benefit must be reported together. A direct worker entry and further code sharing can follow the measured result.

Execution integration2830609 ended101/SIGSEGV because its host fixture omitted the kernel-owned epilogue; the fixture now appends the same RET used by existing executable rewrite tests. Retry2831372 passes the complete62-test suite and ends0 at00:18:23Z. Functional production source stayed atf98d0c87c;5da837c51 adds the corrected execution regression. Both raw runs remain. The first source/test/replay worker2827763 ended0 at00:14:46Z.

Canonical CLI metadata remains2978744 bytes /1794948232 mtime. Current base/image and checked Tracee guest remain in use. Omp's next frozen image/check/OTel stats-on default batch measures actual selected paths, native installs/failures, installed native/JIT bytes, per-call, throughput and body/helpers/maps with all LTO on. Results from an image carrying the pending cohort describe that cohort; individual timing attribution requires a measured comparison. The helper-context query remains frozen-core owner work and a separate phase1 correctness issue. All hard app targets remain open.

Raw: /workspaces/kprog-raw/perf/named-lpm-20261118/host-20261118T001244Z-2827763; failed execution /workspaces/kprog-raw/perf/named-lpm-20261118/integration-20261118T001550Z-2830609; successful execution /workspaces/kprog-raw/perf/named-lpm-20261118/integration-20261118T001729Z-2831372.
