# Current emitted zero-tail duplication

The smallest useful next step is to count structurally identical zero-fill
suffixes in the 295 successful current-source emissions before choosing a
sharing implementation. The earlier 239-plan inventory had missing runtime
fields and covered named PLT32 calls only. The current production emissions
include numeric calls, fixed scalar counts and generated entry functions.

This reader decodes each actual probe region, confirms the destination-restore
instruction and final RET, and groups exact suffix bytes within each program.
It records protected loads and relocations in those suffixes. Each duplicated
suffix is charged a six-byte success-return/error-jump replacement. Prefix
branch sizing and retargeting remain implementation costs; this local bound
has yet to become an installed-code saving or a timing result.

The committed run uses CPU 19, timing SH and a 4 GiB address-space limit.
All inputs stay read-only. Source, canonical linker, base, image and guests
retain their current state; Omp owns the next image batch with all LTO on.

2026-11-17T23:38:57Z — Reader 6d9973af3 and RET classification 505d62384 completed on all 295 successful map-CFG emissions (source 9cf2726e0). Host 2813341 ended 0 at 23:34:48Z; follow-up 2814493 ended 0 at 23:35:50Z. The initial reader counted RET's implicit stack-read metadata as a protected load; the final reader lists those return sites separately. Both raw runs remain.

| App | Captured requests | Probe regions | Zero tails | Duplicate copies | Local saving bound |
| --- | ---: | ---: | ---: | ---: | ---: |
| BCC | 25 | 9 | 9 | 0 | 0 B |
| Cilium | 47 | 0 | 0 | 0 | 0 B |
| Katran | 1 | 0 | 0 | 0 | 0 B |
| OTel | 14 | 17 | 17 | 0 | 0 B |
| Tetragon | 39 | 119 | 80 | 45 | 1552 B |
| Tracee | 169 | 683 | 485 | 313 | 11268 B |

The groups cover 33 Tetragon requests and 140 Tracee requests. There are 356 duplicate dynamic 42-byte tails, each charged six bytes for a local success RET and an error JMP, plus two duplicate fixed 8-byte tails. All 591 identified suffixes have their final RET recovery entry and zero protected source-load entries or relocations. Scalar/string and user/kernel variants share the dynamic byte sequence only after their own domain policy, copy and cleanup work. The exact code, decoded instructions, metadata and input/status paths stay in inventory.json.

These bounds are 0.546% of Tetragon and 0.646% of Tracee's captured neutral payload totals; they leave the installed-half target and per-call targets open. A source implementation must preserve the local success/zero-length RET, error RAX, original R8/R9D, policy denial and post-fault cleanup, and map the zero label through branch compaction. Matching suffix bytes establishes duplication; changing the production emitter requires explicit structural offsets from zero_fill/user_leaf/kernel_routine through compact into append/share, followed by the existing fault/SMAP/string/fixed matrix and all captured emissions. A raw byte-search rewrite would broaden the transformation beyond its structural facts. Keep production changes within that small scope and use Omp's next all-LTO batch for installed-size and per-call effects.

Raw: /workspaces/kprog-raw/perf/current-zero-tails-20261117/host-20261117T233549Z-2814493; initial classification raw: /workspaces/kprog-raw/perf/current-zero-tails-20261117/host-20261117T233447Z-2813341. All own workers are terminal; canonical CLI, base and image remain in use by peer checked Tracee 2754970.
