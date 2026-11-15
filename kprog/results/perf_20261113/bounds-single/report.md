# Sole packet-bounds route

2026-11-15T14:22:20Z: 1c5f8b7d7 removes both opt-in flags and the
unsafe untied-asm alternative. The trusted caller now supplies only input/output;
canonical constant context loads and tied identities are always active.
The base packet-bounds is now SHA4827e435, identical to its canonical build.
Image af3 remains unchanged; its compiler copy is older until C's next image
packaging. C Katran ordinary-native timing does not need this B compiler.

New tests fail on the old base tool's default untied-identity behavior, then
pass on the new binary: 60 before/after native cases, BPF untied output
preservation, the real normal service pipeline, four canonical tracing load
widths with exact R1/+80 encoding, and dynamic/other-section/untied negatives.
The sole all-pairs backend still matches direct allocated code on its existing
independent-register fixture. The ALL environment/CLI selector was already
removed by8f48bf443; no second automatic route remains.

Raw /workspaces/kprog-raw/perf/20261115-bounds-single, controlMake2 expected,
check/publish1034124 terminal0 (actual launcher.pid in raw is authoritative).
CPU16–19 caller/8GiBAS/imageEX; no VM or concurrent timing owner observed.
Check source build rule used CPUs8–11 as recorded in make.log. Published after
all three scoped checks. Existing Clang911032 remains SIGSTOP for C's timing.
No image/kernel/helper/LTO/workload change or performance result. Handler
conversion P-SPECIALIZE now leads per14:20 steering; FORMAL owns M4–M6.
