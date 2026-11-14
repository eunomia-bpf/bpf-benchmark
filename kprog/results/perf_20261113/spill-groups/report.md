# Multiple independent whole-word spill groups

`KPROG_BPF_WHOLE_WORD_SPILLS_ALL=1` with whole-word spills enabled forwards
`--all-scalar-pairs` to the B-only MIR pass. Four pairs of scalar4/aligned8
spills can be packed before a later non-scalar spill, with no selected slot
address escaping. Its default is zero; the existing single-pair selection
used by the current OTel application stays unchanged.

The focused test includes eight scalar slots, a live register crossing a
block, a later untouched64-bit spill, overflow and a separate padding object.
It exercises sparse frame IDs after removing interior slots. Actual stack
access depth falls80->48 for the small fixture and544->512 for its padded
form. The same output object is replaced between phases, so no per-mode
compiled copies are kept.

On the sole stock kernel, the small original and both packed forms each
execute1060 cases (36 boundary pairs plus1024 seeded cases), matching the
independent C arithmetic reference:3180 successful executions. The padded
original is rejected for its fp-544 stack write; the512-byte packed form
loads and executes. The LLVM compiler uses the existing production4096-byte
emission setting so the negative fixture reaches the unchanged kernel512
limit. The initial host attempt that hit LLVM's default512 limit remains raw.

Both the existing single-pair fixture and the new eight-slot fixture produce
exactly the prior single-pair MIR/selection with the new mode off, compared
against b9dc82ceb loaded from git into memory. The active OTel service invokes
the default CLI and retains that selection. No simulator header, native P,
pre-bounds IR, kernel, base or image changed.

Source4c2c594c0/4afdb8824/c162875d4/2662ac31e. Make spill-groups-build/run in
scalar-spill-precision.mk; guest22–23/onevCPU2GiB/imageSH/8GiB hostAS. Small
records and exact commands are retained here; full raw logs at
`/workspaces/kprog-raw/perf/20261114-spill-groups`. Service flag wiring and
actual retained-body replay remain next. This proves the focused semantic
and stack-boundary subset, not a census-body or full-app acceptance gain.
