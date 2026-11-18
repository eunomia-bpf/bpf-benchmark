# Retained helper tail forms

Scope: audit the source helpers that take the existing tail path before the
ordinary helper lowering. The smallest source change adds rows to the current
--show stream at single-target/conditional and finite numeric-join rewrite
points. It uses their existing helper and RDI-map facts. Emitted instructions,
bindings, checks and branch cleanup retain their current behavior.

The parent lpm-body-20261118/candidate.sh rebuilds the sole Cargo unit entry
under timing SH/image SH on CPU19 and replays all295 captured requests.
inventory.py records each actual tail, available named-map operation,
original proof bytes and emitted generic/trie relocation opcodes. Original
plans retain their captured call kinds. Named trie operations identify the
map class; actual loaded key shapes determine LPM12 eligibility. Static site
counts are separate from frequency and app per-call effects.

The existing full test suite and complete blob/relocation/map/ABI comparison
cover unchanged output. The canonical CLI stays in use by checked Tracee
2754970. Source/size optimization follows the observed forms. Omp owns the
next frozen all-LTO image/check/app batch and the original-context handoff.

2026-11-18T02:32:33Z — Actual retained source has zero single-target, conditional or
finite-join helper-tail records across all295 successful requests. The same
--show streams contain 41935 ordinary helper sites and 6501 ordinary
lookup sites. OTel has52 direct trie E8 relocations and Cilium32; their
157 generic ARRAY/LPM fallback relocations are also E8. The result rules
out a tail-specific LPM opportunity for these captured programs. It covers
the retained inputs and establishes static form, separate from runtime
frequency or uncaptured programs.

| App | Captures | Ordinary helpers | Ordinary lookups | Helper tails |
| --- | ---: | ---: | ---: | ---: |
| BCC |25|140|17|0|
| Cilium |47|1567|447|0|
| Katran |1|84|66|0|
| OTel |14|1242|491|0|
| Tetragon |39|2755|926|0|
| Tracee |169|36147|4554|0|

The two native rewrite points are x86.rs:1208 and1220. The existing ordinary
record sits at1480 and is a positive control that --show is active. The
shared producer flag set at vendor/bpf/Makefile:52–56 uses O3 and permits
ordinary sibling-call optimization; the result comes from actual helper
forms, rather than an assumed disabled compiler flag. Tetragon's actual
core-compat.h:791–828 wrappers contain explicit volatile CALL instructions.
These source facts explain that region while the capture counts establish
the observed six-app result.

The14 temporary trace lines are retained as instrumentation.patch and were
removed from the production tree before publication. Current native-link
source remains at79ece52c1 plus its matrix9ebfac020. The sole Cargo unit
artifact was rebuilt after removal. Both instrumented and clean-source
full suites pass62 tests with four opt-in, and both295-request replays have
byte-identical blob/relocation/map/ABI sets to their prior source input.
The trace patch serves experiment reproduction in this same checkout;
future use first settles that open source file's ownership in COORDINATION.

Instrumented worker2871349 ended0, raw:/workspaces/kprog-raw/perf/lpm-body-20261118/candidate-20261118T021657Z-2871349.
Clean-source worker2873703 ended0 at02:25:42Z, raw:/workspaces/kprog-raw/perf/lpm-body-20261118/candidate-20261118T022438Z-2873703.
Both held timing SH/image SH, CPU19, one worker and32GiB AS. All raw trace,
initial sparse-counter report, explicit-zero report and full compatibility
JSON stay in their run directories. summary.txt uses explicit zero counters.
The canonical CLI stays2,978,744B/mtime1794948232, with peer checked Tracee
2754970 retaining the base/image lease. Own jobs and leases are terminal/free.
Omp's frozen all-LTO image/check/app batch and original-context binding stay
pending; this audit adds zero production code or app speed/size claim.

Next phase1 source review is argument evaluation in core-compat.h:492–504
and558–568. The helper selector consumes argument expressions, and the
outer helper macro applies the returned function pointer to those expressions
again. Reproduce the actual header expansion before deciding a producer
change. This is a separate potential correctness/performance class from the
now-closed tail inventory, and producer/header ownership stays with Omp.
