# Cilium head-length bounds

PERF 2026-11-19T21:07:34Z. This is the phase-1 compiler repair for the 40 archived
Cilium `invalid access to packet` requests identified in
[the measured handoff](../cilium-packet-bounds-20261119/README.md).
The six trusted-sk_buff store failures and three live-table generation failures
remain separate. The established previous stock-verified count is 14.

Candidate `cdd26e9cd`, refined through `650994842` and `80dbcfc51`, recognizes
classifier sections, the simulator's exact asm u32 field reads and ALU32
identities, and the frozen kernel's i32 `len - data_len` head length.
It retains the scalar predicate and expresses its implied packet bound using
the public context data/data_end fields. Native P and its frontend IR stay
unchanged. Kernel `include/linux/filter.h`'s `bpf_compute_data_pointers` and
`include/linux/skbuff.h`'s `skb_headlen` establish the identity; `layout.c`
checks len112/data_len116 and their u32 widths against the actual target header.

The fresh public span must still describe the captured head length.
`80dbcfc51` walks predecessor paths back to each field read, including loops,
and leaves the original predicate unchanged across possible skb mutation.
Proven reads, register identities, kernel casts and private alloca stores
preserve this fact. This adds no runtime test or limit.

Current controls contain 12 positive forms and eight exclusions. They include
explicit LLVM predicates to avoid duplicate comparisons produced by Clang,
strict/inclusive 42/43-byte bounds, readonly loops, mutating loop backedges,
and intervening helper/asm writes. Against the installed old compiler,
only the two original spans match, the ten new forms miss, and all eight
exclusions remain unchanged. `freshness-before-result.json` records this
expected baseline. Final candidate syntax and target layout checks pass;
these are not candidate B or stock-verifier results.

The committed `validate.sh` runs under image EX only for the one canonical
compiler replacement, then image SH for controls, captured Katran replay,
five stock fixture loads/four TEST_RUN cases, all 40 captured frontend-to-B
replays, and the existing fresh Cilium checked-corpus entry. Functional guests
use CPUs18-19, without the timing lock. Host replays use CPUs8-11 with four
workers, each inheriting an 8GiB address-space limit. All LTO pieces and the
uniform app flags remain on. No archived frontend is recompiled from C.

Final worker303179 is parented to PID1 and queued at2026-11-19T21:06:31Z.
Raw: `/workspaces/kprog-raw/perf/cilium-headlen-20261119/check-20261119T210631Z-303179`.
Launch log: `/workspaces/kprog-raw/perf/cilium-headlen-final-launch-20261119.log`.
The active coordinator image reader is preserved. Earlier unstarted waiters
269752,296915,298900 ended143 and all their raw directories remain.

OMP independently reports 40/40 B emissions and235 pointer bounds from the
earlier candidate. That is useful compiler evidence, but it predates the
freshness correction and establishes neither stock acceptance nor bytewise
parity on other apps. PERF uses the canonical compiler, not the peer's
`/tmp/pbt/pb-new` diagnostic build. The fresh guest's per-request journals
will decide coverage; a successful fixture or B emission alone does not
close the 40-request acceptance objective. No runtime gain is claimed here.
