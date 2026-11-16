
## Checked against the rebuilt linker

PERF's numeric-helper-tail fix `152ca8054` is in this tree, but the release
binary predated it (03:12), so the run above used a stale linker. Both were
retested with a binary built at 08:39 from that source:

- `generic_kprobe_filter_arg` proof mode: passes, 4607-byte proof, 61 relocs.
- kernel mode with a real plan: **same failure**,
  `Error: x86 helper tail branch cel_expr_0 has no helper address`.

So the numeric-helper-tail fix does not cover this case, and the diagnosis
stands on the rebuilt linker too. The instruction shape confirms why: the
`cel_expr` switch emits `jmp 0x712 <cel_expr+0x22>` and siblings — a tail jump,
not a call — with `R_X86_64_PLT32` relocations against `cel_expr_0`, an
undefined symbol. A tail jump to a defined symbol becomes a direct branch; to an
undefined one the linker assumes a helper and demands an address from the plan.
For a symbol Tetragon links in at policy load, there is none.
