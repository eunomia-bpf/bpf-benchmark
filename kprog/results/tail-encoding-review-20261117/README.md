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
