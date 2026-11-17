# Current-task BTF and jiffies helper inlining

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

`bpf_jiffies64` now selects a live 64-bit global read from the same-boot
`jiffies` address in the existing LTO layout. This matches the x86-64
helper (`kernel/bpf/helpers.c:394–397`, `include/linux/jiffies.h:86–102`)
and verifier lowering (`kernel/bpf/verifier.c:23973–23995`). The address
uses the existing helper-anchor adjustment, while its value is loaded
on each execution. Missing optional facts keep the original kernel call.
The GS prefix remains exclusive to per-CPU loads. A signed disp32 global
uses an 8-byte absolute SIB load without an address-size override; another
address uses a 10-byte moffs64 load. The executable fixture checks fresh
values 0, `0x123456789abcdef0` and `UINTPTR_MAX`; a byte-level regression
checks the sign-extended kernel address encoding and the old-plan case.

Host validation passes at 2026-11-17T11:00:08Z: the focused Rust test has
one pass and no failures (44 other tests filtered). Its executable
current-task BTF fixture returns the full-width GS pointer, and jiffies
returns each changed 64-bit value. Existing scalar/kernel-string/compat
fault, zeroing, policy and nesting cases also pass. The loader layout
writer instantiation compiles with C++20, `-Wall -Wextra -Werror`, exit 0
at 10:59:47Z. `run-header.sh` checks that template without creating a
second loader build. Small receipts are in `host-summary.json` and
`host.log`; all emitted bytes and raw logs stay under the raw directory.

App timing is pending. The coordinator owns the clock and
leaf-batch2 publications; no image or guest is started by this step. Those
recipes build the working tree, so their recorded source revision must
include any joined source changes when attributing results. A separate
incremental BTF-helper speedup has not been measured.

Per executed eligible site this substitutes one 9-byte GS load for an
external call, removing call/return overhead while retaining any compiler
caller spills. The original 5-byte call becomes 4 local bytes larger before
branch layout. The historical inventory has 121 static sites over 109
distinct Tracee entry names, not a current installed-copy or dynamic count.
Jiffies replaces a 5-byte external call with an 8-byte load on the sole
kernel's usual address class, a 3-byte local increase. The retained cohort
has 91 static calls over 13 Cilium entry names. These local byte deltas
are not installed app totals. Current installed bytes, per-call time and
its body/helper/map split await the targeted stats-on runs after the
reserved publications. Item 1a remains open until those results land.
