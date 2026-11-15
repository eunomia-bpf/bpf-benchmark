# Clock-helper linkage and Katran call-site audit

2026-11-15; sources 51fcc939f, 013fe50d4, 97ae73a66, fbee52b39.

Normal x86 runtime calls and sibling transfers to `bpf_ktime_get_ns` now bind
directly to the sole boot kernel's `ktime_get_mono_fast_ns`. The original helper
must still be available for the program type. Materialized helper addresses,
numeric IDs and proof semantics retain their original identities. The normal
plan records the boot symbol and the loader cache advances to v41; all other
LTO remains enabled together.

This is the exact function called by kernel/bpf/helpers.c:178. The actual
vmlinux wrapper has a five-byte fentry call and a five-byte tail jump to it.
The optimization removes wrapper instructions; it does not remove the clock
read or justify a predicted gain from the helper's profile share.

The final suite passed **44 tests**, with one pre-existing ignored host timing
microbenchmark. Seven real ELF/host-execution forms cover PLT, GOT, hoisted
pointers, numeric IDs, observed identities and sibling transfers; missing/zero
original and fast-helper facts fail explicitly. Loader C++ syntax also passes.
The actual sole-kernel helper fixture passed all ten program-type queries;
XDP's original wrapper and fast symbol match independent full kallsyms and are
distinct. `clock.link-plan.json` is the actual normal serialized plan from that
fixture. This is component validation, not a Katran native execution result.

The paired base publisher completed at **17:42:02Z**, status 0. Exact linker,
loader, static/shared library and compiler hashes are in `base-tool-sha256.txt`.
Image replacement is a separate in-flight step under image EX; the previously
installed image is af3f9d4e. No new timing result is claimed here.

The current staged Katran ELF (c0dc65fc...) has 84 actual proof-CFG helper sites:
66 map lookups, eight clock calls, two CPU-number calls, four XDP head changes
and four map updates. The inventory records input offsets and exact source/tool
hashes. The proof object was measured in a memfd and closed, without retaining
a second compiled product. Its linker was 4af1f805, immediately before the
availability-negative refinement, rather than the published 64eb98aa linker.
These static sites are not frequencies, and proof-mode map=null does not
certify runtime lookup inlining. C's 15:55 timed run did not preserve actual
link plans; its staged object was replaced at 16:44. The next timed native arm
will retain live plans and blob/relocation hashes and lengths for the actual
map/helper binding audit. That audit remains open.

The initial test-only temporary-borrow compile failure and then the stale
moving-Tetragon fixed-39-R13 assertion are preserved in the raw checks. The
latter is now a deterministic two-helper R13 regression; no runtime capability
was disabled. `checks.json` records all statuses, commands and times.

Raw logs, diagnostics and commands remain at
`/workspaces/kprog-raw/perf/20261115-clock-lto/` (check, check-v2, check-v3,
kernel-facts, publish, image). No paper, workload or benchmark setting changed.
