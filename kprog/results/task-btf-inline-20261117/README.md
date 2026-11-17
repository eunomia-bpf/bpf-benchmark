# Current-task BTF helper inlining

The multi-day helper item 1a extends the existing current-task GS load to
`bpf_get_current_task_btf`. Both kernel helper bodies return `current`
(`kernel/trace/bpf_trace.c:755–768`), and the verifier lowers both names
identically (`kernel/bpf/verifier.c:24026–24041`). The runtime pointer is
unchanged; the verifier's distinct trusted-pointer type is not rewritten.

The existing executable probe-read fixture now exercises the BTF spelling
with its full-width `0x123456789abcdef0` GS pointer. Before the change,
selection returns `None` and the new fixture case cannot obtain the inline
body. Other helper cases and fault-recovery vectors remain in that same
focused test. `run-host.sh` uses the canonical linker target directory on
CPU 19 under timing SH; raw logs and emitted fixture bytes remain in
`/workspaces/kprog-raw/perf/task-btf-inline-20261117`.

Validation and app timing are pending. The coordinator owns the clock and
leaf-batch2 publications; no image or guest is started by this step. Those
recipes build the working tree, so their recorded source revision must
include any joined source changes when attributing results. A separate
incremental BTF-helper speedup has not been measured.

Per executed eligible site this substitutes one 9-byte GS load for an
external call, removing call/return overhead while retaining any compiler
caller spills. The original 5-byte call becomes 4 local bytes larger before
branch layout. The historical inventory has 121 static sites over 109
distinct Tracee entry names, not a current installed-copy or dynamic count.
Current installed bytes, per-call time and its body/helper/map split await
the targeted stats-on run after the reserved publications. Jiffies is the
remaining part of item 1a.
