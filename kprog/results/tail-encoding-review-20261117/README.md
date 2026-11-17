# Tail-transition encoding inventory

This read-only follow-on measures linker-owned tail stubs from the actual
post-label-fix replay. It does not modify the queued dead-ID/fusion source
cohort, live main CLI, image, base, kernel or benchmark.

`x86.rs:3905–3944` emits three near Jcc instructions and wide map/target
operands into declared byte chunks. Because these chunks are opaque to the
outer block encoder, its normal short-branch optimization cannot shorten them.
The sole kernel's indirect tail emitter uses short JBE/JAE/JE, a disp8 map-bound
comparison/function load and imm8 target-entry ADD (bpf_jit_comp.c:746–807).
The same native operations can use those encodings when their actual offsets fit.
Instruction count and live map/count/null/frame work remain unchanged.

The reader locates real kind-10 relocations and validates the surrounding
three branches have one common miss target and the success ends in JMP RCX.
It computes all three shortened displacements together. The counter-pointer
load's four-byte relocation remains unchanged: the frozen direct module patches
exactly four bytes (direct-native/bpf_x86_native_lab.c:235–247). It is not a
normal dispensable disp32. Do not shorten it or reuse the target-entry immediate
as the counter field. Counter offset/chunk mapping must follow any earlier
byte removal; current `tail_count_patch_preserves_target_entry` and
`kernel_tail_calls_always_relocate_the_counter_frame` exercise that contract.

Run the committed reader with `bash kprog/results/tail-encoding-review-20261117/run.sh`.
Raw is persistent at `/workspaces/kprog-raw/perf/tail-encoding-review-20261117`.
All counts are static retained request-set opportunities, with unknown hot
frequency. No transformed fragment, installed saving, per-call gain or new
runtime check is claimed. Actual findings follow after execution.

## Actual retained findings, 2026-11-17T22:08:35Z

Reader38cc97063 completed under timing SH on CPU19. All206 kind-10 stubs
are recognized: Cilium87, OTel13, Tetragon59, Tracee47; BCC/Katran0.
Every common miss target fits rel8 after shortening all three branches.
All206 map-bound displacements, program-function displacements and tail-entry
immediates also fit their short forms. Original stub bytes total18,956.

| App | Requests | Tail sites | Three Jcc bytes | Three operand bytes | Static opportunity |
| --- | ---: | ---: | ---: | ---: | ---: |
| bcc/set | 25 | 0 | 0 | 0 | 0 |
| cilium/agent | 47 | 87 | 1044 | 783 | 1827 |
| katran | 1 | 0 | 0 | 0 | 0 |
| otelcol-ebpf-profiler/profiling | 14 | 13 | 156 | 117 | 273 |
| tetragon/observer | 39 | 59 | 708 | 531 | 1239 |
| tracee/monitor | 169 | 47 | 564 | 423 | 987 |

Total static opportunity4,326B:2,472B from three Jcc encodings and1,854B
from three operands. This is21B per observed stub, keeping every instruction
and every bounds/count/null/live-slot/frame operation. Static sites are not
hot frequencies or installed savings. Counter fields and complete stub bytes
are retained in inventory.json. No code was patched or executed.

A future minimal change belongs in build_x86_tail_call_inline: choose existing
short memory/ADD forms from the provided layout facts, map the three local
branches, and map the counter displacement before chunk emission. Keep that
field four bytes even though its signed value fits disp8. Existing first-chunk
source-label handling must remain. Do not add constant-slot caching, alter
program-array updates/lifetime handling, or replace the three live tests.
Existing tail_count_patch_preserves_target_entry and
kernel_tail_calls_always_relocate_the_counter_frame plus full focused suite
and captured-request replay are the required regression subset. This is a
follow-on after the already queued dead-ID and ARRAY/LPM work, not a source
change mixed into those cohorts. Omp owns later image/check/target timing.

The earlier dynamic probe zero-tail population is already in
results/current-link-capture-20261117/replay-summary.txt; it was not rerun or
counted as another new result here. All raw stays at
/workspaces/kprog-raw/perf/tail-encoding-review-20261117.
