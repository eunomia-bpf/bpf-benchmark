# Fresh checked OTel main installed

The active same-source/all-LTO whole-application diagnostic verified B for
`perf_unwind_native` and installed its checked-native program41 at
2026-11-14T21:12:37Z. This is request3, original source program35; the prior
two actual requests installed programs27/34. The main started20:09:02 and
completed after approximately63.6 minutes on the shared two-vCPU guest.
That wall interval includes generation, verification and checked-native
compilation; it is not an isolated compiler-cost measurement.

`checked-simulator-verification.json`, the actual compiler commands,
frontend-IR reuse record, spill-lowering record and source metadata retain
its evidence. The complete126883360-byte successful request archive remains
at the persistent path recorded in `receipt.json`. Only small records are
published here; no compiled product is copied into this result directory.

The run uses the same ef449 source producer, corrected combined all-LTO
linker and `KPROG_BPF_WHOLE_WORD_SPILLS=1`; context/strict-identity options
remain off. This fresh success connects the optional automatic backend to
real whole-app startup after earlier load-only replay. The remaining actual
programs and the one10s workload are still running. Full application status,
execution counters, own-counter windows and equal-work remain open. This is
not a new performance number or full application acceptance claim.

The guest remains16–17/2vCPU48GiB, shared image lock, sole kernel/base/image.
Raw directory: `/workspaces/kprog-raw/perf/20261114-otel-whole-word-checked`.
After make605029 exits, the existing context-body compiler queue617107
continues; no duplicate large frontend was started.
