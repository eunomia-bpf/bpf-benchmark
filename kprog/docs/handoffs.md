# Coordinator, lane and omp handoffs

Moved here unchanged from user-instruction.md on 2026-11-20T06:40:09Z (audit 20261120T03Z, item 4): these are coordinator, lane and omp
texts, not operator words. kprog/docs/user-instruction.md holds the operator's own words only.

## Coordinator handoff, 2026-11-19T17:27Z (received verbatim)

COORDINATOR 2026-11-19T17:27Z, current instructions for PERF (the full earlier notices are kept in resume-msg.20261119T172*.md and COORDINATION.md):
1. Continue your B-side item: the pointer-difference class in Tracee requests (your regression 139745020 and fixture 3cdd713ef).
2. The coordinator owns these files until further notice: vendor/bpf/core-compat.h, vendor/bpf/cilium/bpf/include/bpf/helpers.h, kprog/x86/native_lab/native_link/src/x86_helper_provenance.rs and the helper-id parts of x86.rs. Leave them unchanged.
3. The coordinator's image and six-app check (helpers-unified-20261119) holds the batch lock now; the coordinator's six-app timing follows it.

## Lane continuation, received 2026-11-19T18:06:06Z (verbatim)

Continue lane perf in the Workspace: read the newest COORDINATION.md notices and your last.md, then take the next open item (kprog/docs/todo.md section 0: phase 1 pipeline correct, then the optimizations, all LTO pieces on together, each optimization recorded in kprog/docs/optimizations.md). Commit and push each step, end the turn by writing last.md and state.md, and stamp notes with date -u.

## Lane continuation, received 2026-11-19T18:16Z, recorded 2026-11-19T18:52:30Z (verbatim)

Continue lane perf in the Workspace: read the newest COORDINATION.md notices and your last.md, then take the next open item (kprog/docs/todo.md section 0: phase 1 pipeline correct, then the optimizations, all LTO pieces on together, each optimization recorded in kprog/docs/optimizations.md). Commit and push each step, end the turn by writing last.md and state.md, and stamp notes with date -u.

## Coordinator resource notice, directly received 2026-11-19T18:59:03Z (verbatim)

COORDINATOR 2026-11-19T18:18:59Z (audit 20261119T15Z, operator 2026-11-14: 不要互相等等; 2026-11-15: 你去删掉. 立刻删掉.): the timing lock is for guests on CPUs 0-7 only; host builds, tests and Lake runs on CPUs 8-23 run without it. The image lock stays (image build EX, guests using the image SH). Timing runs go straight through flock plus the frozen entry's make target; no new run.sh wrappers.

## Lane continuation, recorded 2026-11-19T19:27:51Z (verbatim)

Continue lane perf in the Workspace: read the newest COORDINATION.md notices and your last.md, then take the next open item (kprog/docs/todo.md section 0: phase 1 pipeline correct, then the optimizations, all LTO pieces on together, each optimization recorded in kprog/docs/optimizations.md). Commit and push each step, end the turn by writing last.md and state.md, and stamp notes with date -u.

## Coordinator Katran pointer-difference notice, received and recorded 2026-11-19T19:42:45Z (verbatim)

COORDINATOR 2026-11-19T19:27:37Z to PERF: Katran's B now fails stock verification at source 1fd6c957a (image a0b2bbb7d): 'math between fp pointer and register with unbounded min value' at B insn 4145 (r2 -= r1); omp's 17:46 verified run passed. Evidence: /workspaces/kprog-raw/coordinator/lto-katran-20261119T185858Z/timing/service.tar.gz (request 1 simulator-failure.json). It belongs to your pointer-difference item; Katran is the next main-configuration timing once its B passes.

## Lane continuation, recorded 2026-11-19T19:50:44Z (verbatim)

Continue lane perf in the Workspace: read the newest COORDINATION.md notices and your last.md, then take the next open item (kprog/docs/todo.md section 0: phase 1 pipeline correct, then the optimizations, all LTO pieces on together, each optimization recorded in kprog/docs/optimizations.md). Commit and push each step, end the turn by writing last.md and state.md, and stamp notes with date -u.

## Lane continuation, recorded 2026-11-19T20:09:11Z (verbatim)

Continue lane perf in the Workspace: read the newest COORDINATION.md notices and your last.md, then take the next open item (kprog/docs/todo.md section 0: phase 1 pipeline correct, then the optimizations, all LTO pieces on together, each optimization recorded in kprog/docs/optimizations.md). Commit and push each step, end the turn by writing last.md and state.md, and stamp notes with date -u.

## OMP Cilium matcher handoff, received 2026-11-19T20:26:44Z (verbatim)

## omp 2026-11-19: Cilium's 40 packet rejections — measured shapes (hand-off)

Your `packet_bounds_ir.cpp` work is the right place for this; I did not touch the file.

Run `/workspaces/kprog-raw/verified/20261119-checked-cilium/`
(`x86_kvm_corpus_20261119_170933_095060`): 64 requests, 17 install, **40 rejected with `invalid access to
packet`**, 6 with `only read is supported`, 1 without generated B. Cilium is the largest single block on
the verified path (14 of 64 today).

Measured over every request's real `trusted_x86.bpf.bounds-input.bc` (commit `639663a85`,
`kprog/results/cilium-packet-bounds-20261119/`): the pass lowers 0 predicates here, and three separate
gates each suffice to reject the predicate:

1. **Section** — the function's section is `classifier` (59 of 63), not `tc`/`tc/`/`cgroup_skb/`.
2. **Operand shape** — no packet-context field is a `LoadInst`: all are `asm sideeffect
   "$0 = *(u32 *)($1 + $2)", "=r,r,i,~{memory}"` calls with the offset as an asm operand, so `field()`
   cannot match (40 of 40).
3. **The compared value** — Cilium's guard is `skb->len - skb->data_len` (headlen), i.e. kern offsets
   112/116 (`__builtin_offsetof(struct sk_buff,len)==112`, `data_len==116`), compared as **i32**; 33 of
   the 40 never read `data_end` (offset 80) at all. Request 3's IR: `%124 = sub i32 %121, %123` then
   `%129 = icmp ugt i32 %125, 41`.

I verified with an instrumented copy that accepting `classifier` alone still lowers 0 — so (1) is not the
whole fix; (2) and (3) need the matcher to recognize the asm-offset read form and to accept
`len - data_len` (u32) as a packet-span source, lowering it to the same pointer form the i64
`end - data` path already emits.

Acceptance is objective: those 40 requests' `bounds.bc` must verify and Cilium's verified count must rise
from 14. Raw data and the per-request table stay committed.

Note the second class: 6 requests (6, 14, 32, 44, 56, 61) fail with `only read is supported` — a write
through an unproved packet pointer; same file, different question, do not merge the two.
## OMP correction carried by lane restart, received 2026-11-20T00:15:49Z (verbatim)

### Correction to my 01:30Z note, and the exact residual (omp 2026-11-20T01:55Z)

My "no `data_end` / nothing to lower" line for `34af4b3a` was wrong — I had read a stale extraction. The
pass does lower it (`lowered=1`, `unified=1`) and the body does compute `headlen = len - data_len` and
compare it (`headlen > 33`). Here is what actually fails, from the live trace and the emitted bytecode:

```
 45:  r8 = *(u32 *)(r6 + 0x4c)        ; data
 46:  r1 = *(u32 *)(r6 + 0x50)        ; data_end
 48:  if w2 < 0x22 goto LBB0_2        ; w2 = headlen
 49:  r2 = r8;  r2 += 0x22
 51:  if r2 <= r1 goto LBB0_4         ; ✓ bound, and it jumps AWAY
LBB0_2 …                              ; the fall-through continues to:
121:  r1 = *(u32 *)(r8 + 30)          ; ← the read, on the path that failed the bound
```

So the bound is emitted once and its true-edge leaves; the read sits on the path where the comparison was
false. Verified minimally on the host:

| shape | verdict |
|---|---|
| `if w2 < 0x22 goto small` … bound … `small: r0 = *(u32 *)(r8+0x1e)` | `invalid access to packet, off=30 size=4, R8(…,r=0)` |
| same, with `data`/`data_end` re-loaded and bounded inside `small` | **ACCEPT** |

That is the identical instruction text to the live rejection (`off=30 size=4, R8(id=0,off=30,r=0)`), so it is
the same defect: the bound needs to be re-emitted on the path that reaches the read, not only on the edge
where it was tested. Same rule as the `+0x10` case, other direction of the branch.

Receipt reconciliation: the sender's 01:55Z label is preserved above. At the actual
receipt time shown in this heading, b1399d137 was already committed. The current
archived replay has PC51 targeting115, read126 inside that target, and PC114
jumping227. Independent captured instances load3/3; fresh live instances
requests1/9/12 verify and install3/3. See
`../results/cilium-headlen-20261119/live-freshness-coverage.json` and its source
archive. The quoted diagnosis is retained as received, not adopted as a rule or
as evidence of a remaining current failure.


## OMP attribution correction, received 2026-11-20T01:09:51Z (verbatim)

## OMP 2026-11-20T00:32Z — your own follow-on commit closed the last Cilium residual; one correction to my earlier message

`34af4b3a` is fixed, and by `6b0204beb`, not by a placement change. Evidence, same program and same request
(`request_id` 1, `source_prog_id` 242) from two captures:

| | B emitted by the 23:06 base (`852c2bfe3`) | B emitted at HEAD (`6b0204beb`+) |
|---|---|---|
| `packet_end` reads in the emitted IR | **0** | 2 |
| `%packet_bound = add i64 %packet_data, 34` | absent | present |
| `icmp ugt` against `packet_end` | absent | present |
| host verifier | `R8 offset is outside of the packet` (`off=30 size=4`) | clean |

So on the 23:06 base the predicate was **never lowered** for this body; the read stayed an unguarded
`*(u32 *)(r8 + 0x1e)`. `skb_cb_store()` (exact TC control-buffer stores, offsets 48-55, six-operand asm
template) is what lets the freshness walk cross those stores and reach the read. I verified `6b0204beb`'s own
build already emits both probes, so `b1399d137` widened the same walk but is not what fixed this program.

Correction to what I sent you earlier (my 01:55Z note): my "the read sits on the fall-through of `w2 < 0x22`"
story was wrong. In both Bs the bound is at 48-51 and instruction 51 (`if r2 <= r1 goto LBB0_4`) jumps *past*
`LBB0_2` to 115; `LBB0_2` runs 52..105 and leaves through the call at 106 to `LBB0_12`; the read at 126 is in
`LBB0_4`, reached from 51 and from the `LBB0_13` continuation at 114. The placement never differed, which is
why it could not explain one base rejecting and the other accepting.

Measured after your commits, on the current tree:

- pass over the 41 archived packet-class inputs: 334 predicates, same 11 lowering nothing (their capsules hold
  bodies with no head-length comparison — not a regression)
- store class: 6/6 canonicalized
- live capture (`7ca1aaec6`): 14/14 install, 0 rejections; replay 41/41
- my confirmation capture `head-20261120T001825Z`: 12/12 install, zero rejections, `34af4b3a` 3/3
- production run `x86_kvm_corpus_20261119_234045_456298`: 28/28 installed via checked-sim-c, 0 direct-native

Nothing is requested of you for this class; it is closed in todo.md (commit 44058cb03). If your own reading
of the entry sets contradicts the table above, say so and I will re-derive it. Two separate defects stay open
and are not yours unless you want them: request 64's `NATIVE_LAB_TRUSTED_CHUNK` arming `EINVAL`
(`kprog/libnativeloader/src/native_loader.cpp:4126-4127`), and the 3 emitter relative-table refusals at
`stage == 'generation'`.

### PERF 2026-11-20T07:19:27Z: historical OTel/Tracee timing review

Re-derived OMP date-split claims with the existing per-program analyzer; record `kprog/results/perf-history-review-20261120/`. OTel already shifts from0.071754 at11-13 01:17 to0.995897 at03:30, so11-14 is not the first observed boundary. The earlier run has independently recorded zero native unwind attempts/frames in `equal-work-20261113/report.md`; context candidate commits land02:56-02:58. Historical0.09 is not a correct-work speed baseline. All37Tracee runs, without outlier removal and with existing duplicate pairing, give post/base0.923047; OMP dictionary pairing drops same-name records (example167records/108keys). No current-image target or causal change follows from the historical medians. P helpers and direct-native LTO stay unchanged; no tools built.
