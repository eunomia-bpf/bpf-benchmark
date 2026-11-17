# Remaining zero-tail duplication

This static inventory follows `a5bb61c40`'s known-count error-zeroing.
It decodes the eight current generic scalar/string user/kernel fixtures
and inventories read-helper PLT32 relocations in the 239 retained
2026-11-16 six-app extracted entry requests. It emits no candidate code,
builds no tool and starts no guest or image.

The generic error tail restores RDI from R8 and ECX from R9D, preserves
RAX's error, zeros the full destination and returns. If an existing tail
is reused, each additional leaf needs an error jump and its own success
return. The size bound charges five bytes for that jump and one byte
for the return. Fixed counts now have smaller tails; the inventory does
not guess their count meets. This gives an upper bound rather than an
installed-size saving.

Read-helper relocations identify possible leaf combinations under the
current source selection. They do not infer numeric transfers, current
loaded-program counts or unrecorded generated Tetragon functions. The
historical payload totals belong to the retained outputs, not today's
image. Runtime/helper facts absent from a capture are not synthesized.

`run.sh` runs on CPU 19 under timing SH and retains all raw output in
`/workspaces/kprog-raw/perf/zero-tail-inventory-20261117`. It records only
actual output under the Git lock. Results and the source-change decision
are recorded below. Any future sharing must carry structural tail offsets
through branch sizing, preserve success returns and protected loads,
and avoid fake helper identities or a new public relocation format.

First run 2688184 completed the named-relocation inventory at 17:49:46Z,
then publication exited 1 because the repository ignores `output.txt`.
Its raw files remain at
`/workspaces/kprog-raw/perf/zero-tail-inventory-20261117/host-20261117T174944Z-2688184`.
The forward publication repair uses `host-output.txt` and retains the
already completed analysis without repeating it. The named-only result
does not cover numeric helper transfers: its zero OTel count does not
mean OTel has no read leaves.

`run-emitted.sh` closes that inventory gap with actual emitted ranges.
It builds the sole canonical release linker under timing SH then image
EX and replays the same 239 retained entry proofs and their recorded
plans with `--show`. This is a current-linker replay of historical
extracted input, not a current-P rebuild or installed-program census.
Exact generic tails are checked at decoded instruction boundaries.
Fixed-count tails and uncaptured generated programs remain outside this
bound. All output, including failures, is recorded; no performance
candidate or source change is applied by this replay.

The actual replay 2689690 finished at 17:54:20Z. The canonical release
linker build passed, but **0/239 plans parsed**: every retained plan
lacks the now-required `kernel_layout.probe_read.cpu_tlbstate` field.
It therefore emitted no images or ranges. The zero payload/range counts
in `emitted-summary.txt` are failure coverage, not absence of helper
work. This is an incompatibility of the historical replay inputs,
not a finding that current apps fail to load. No runtime address or
layout fact was guessed to force those plans through.

The completed named-relocation subset gives these bounds only for its
identified helper combinations:

| App | Captured requests | Requests with named reads | Multiple leaf roles | Upper bound bytes |
| --- | ---: | ---: | ---: | ---: |
| BCC | 25 | 10 | 2 | 72 |
| Tracee | 169 | 151 | 140 | 12,024 |

The other four apps have no named read relocations in those proofs and
remain uncovered for numeric helper transfers. All eight current generic
tails decode identically to 42 bytes. Reusing one existing tail with
a five-byte error jump and local success RET bounds saving at 36 bytes
per additional **generic** leaf. Smaller known-count tails, branch
widening and layout costs can reduce that figure. The Tracee bound is
small next to its retained 1,685,306-byte host payload; that comparison
is not a new installed-byte ratio or a measured candidate result.

Decision: leave tail-sharing source unchanged while complete current
load facts are unavailable, rather than add a layout abstraction on
the strength of a partial bound. The next open source item is review
finding 11, ARRAY direct returns: removing existing hot-path jumps also
shrinks the routines and needs no new sharing metadata. The independent
frozen helper-prototype wiring class still belongs to its coordinator.

Recipes are `f77ff7048` and forward repair `3c5efa762`; the failed
emission receipt is `52c5c1cfc`. [Named-only inventory](inventory.json),
[named summary](summary.txt), [emission failures](emitted-inventory.json),
[emission summary](emitted-summary.txt), [build output](build.txt) and
[raw location](emitted-host-location.txt) retain the distinctions. No
new guest, image, performance number or native optimization is claimed.
