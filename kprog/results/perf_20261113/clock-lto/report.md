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

The image publisher completed at **17:47:36Z**, status 0, under image EX with
no live QEMU observed before launch. Current image is **d4b19c9fab0b**;
config is **3404250f5e68**. The superseded af3 image was already absent at
final cleanup. Boot 8cafa600, configuration and both external modules match
before/after. The existing publisher restores vmlinux from that unchanged
boot; its ELF-container hash is now 30f48c23 (the boot is authoritative).

`image-tools.json` streams the sole saved tar without extracting a filesystem:
shipped linker64eb98aa, stripped runtime loader928a1558 and shim19f2f67a all
match the exact canonical packaging inputs. The unstripped base loadera92b
has a different expected hash. The checked/B compilers remain in the sole
base; the frozen Dockerfile does not package those service tools.

All **1193** staged native files match the new image. The old image had1174;
34 paths differ from current stage (Katran/Tetragon/Tracee), recorded in
`image-publication.json`. These are C's existing staged outputs, not a producer
rebuild in this step. The shipped Katran balancer is c0dc65fc, matching the
84-site inventory above. This establishes which artifacts the next run uses,
not their whole-app output equivalence. C was notified to run one fixed-
frequency A/A and one A/B and retain the actual native plans/blob metadata.

2026-11-15 runtime-plan replay support (86a95222e): the helper audit can now
consume the saved runtime plan. It runs the same native -> proof -> kernel
sequence as the loader, retaining only hashes, lengths, helper sites,
relocation targets, ABI and map-patch observations. All compiled outputs live
in memfds and close at completion. The native input, plan and linker hashes
are checked for changes during analysis; this adds no application load gate.
The Katran audit uses the already-published canonical linker and accepts
`KATRAN_LINK_PLAN=/actual/saved.link-plan.json`, without an implicit rebuild.

The clock-only fixture compiled with the unified x86 flags and replayed using
the actual boot plan: proof1704B, runtime blob10B, one16B relocation whose
kind1 target is18446744072220283792, the actual fast-clock symbol. Both linker
invocations returned0. This validates the replay tool and normal call binding,
not a timed Katran arm. See runtime-audit.json/runtime-audit-commands.json;
full logs remain in the raw runtime-audit directory. No image/CLI rebuild was
needed for this analysis-only tooling.

The revised proof-only audit was also rerun on the shipped Katran c0dc65fc
object with published linker64eb98aa. Full proof bytes/hash and all84 helper
sites match the earlier4af1f805 audit exactly (audit-regression.json).

Source optimization lead: x86_known_maps currently clears map facts at every
basic-block entry. A dominating map pointer hoisted into a callee-saved register
therefore loses named lookup specialization across a branch even when all
reachable paths retain it. Existing tests explicitly enforce that conservative
behavior. Determine its actual Katran frequency from the saved runtime plan
before attributing the1.060x result to it. A CFG meet over identical map names
could preserve these facts; mixed identities, unknown inner maps, partial
writes and call clobbers must remain unknown. This is a candidate, not a landed
optimization or a measured explanation.
