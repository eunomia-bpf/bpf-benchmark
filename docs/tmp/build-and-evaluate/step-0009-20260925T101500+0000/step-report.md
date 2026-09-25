# BUILD_AND_EVALUATE Step 0009 Report

Date: 2026-09-25
Experiment: extend retained-bytecode rewrite evidence to Katran's overlay/hint `map_inline` policy path
Result: supported; the same rewrite reconciliation now holds for a second application and policy path

## Source ownership and experiment selection

Step 0008 retained per-step before/after bytecode for Cilium, whose
`map_inline` policy reads `.rodata.config` directly.  Katran reaches the same
pass through a materially different policy: its
`runner/config/passes/map_inline/katran.yaml` resolves map ids from
`map-*.show.json`, builds an overlay file from
`overlays/katran/*.json`, and drives the pass with explicit
`--inline-hint=ctl_array/vip_map/ch_rings/reals/server_id_map` anchors.  A
Cilium-only result therefore leaves that whole path unaudited.

The run was executed this step:

```
env PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=katran \
    BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1 WORKLOAD_DURATION=30 \
    KEEP_WORKDIRS=1 make corpus -o runtime-kernel-image
```

with the standard `RUSTUP_HOME`/`CARGO_HOME`/`PATH`/`CLANG` and `VMLINUX_BTF`
exports, at source commit `b04df85dc1`.  It exited 0 after 3m29s.  Only
`runner/config/passes/**` policy was exercised; no frozen workload, app runner,
`corpus/driver.py`, benchmark Makefile, or launch wiring changed.

Making Katran auditable required generalizing the two independent analyzers,
which were Cilium-hardcoded.  Both now take per-application contracts
(`WORKLOAD_CONTRACTS` in `analysis/audit_loadtime_evidence.py`, `APP_CONTRACTS`
in `analysis/audit_map_inline_snapshots.py`, plus a required `--app` flag) so an
unknown application fails fast instead of silently reusing Cilium's shape.

## Valid result

The retained report stream (`details/loadtime-reports/katran.jsonl`) holds 6
rows: 1 changed load instance (`balancer_ingres`, xdp) and 5 unchanged, 16
applied sites, instruction counts 2,554 → 2,284 (−270).  The run's
`metadata.status` is `completed`; the Katran app record is `status: ok` with an
empty `error`; all four pktgen leaves report returncode 0.

The changed workdir's retained per-step `input.step.0.bin` /
`output.next.0.bin` are raw `struct bpf_insn[]` arrays whose lengths equal
`8 * 2542` and `8 * 2272`, and the two images differ byte-for-byte.  The
post-phase shim log supplies a third independent stream: exactly one
`loadtime optimized prog=balancer_ingres insns=2542->2272 maps=14` line and
zero failure lines.  The inlined map classes are exactly the hinted set
(`ch_rings` 2, `ctl_array` 2, `reals` 6, `server_id_map` 2, `vip_map` 4).

Both independent auditors were run against the source run and agree.  The
load-time auditor (`--app katran --expected-pass map_inline --expected-samples 1
--expected-workload-seconds 30`) reports `outcome: supported`,
`integrity_errors.total = 0`, `sites_applied = sites_matched = 16`,
`changed_insns 2542 -> 2272`, and every bytecode reconciliation at 1/1.  The
snapshot auditor (`--app katran`) reports `outcome: supported` with the same
map-class set and the same 6/1/16 report counts.  Re-running each tool on the
step-0008 Cilium run reproduces its prior numbers byte-for-byte (169 rows /
3,787 sites / 0 integrity errors; 0 skipped, 3,787 matches, 0 misses), so the
generalization regressed nothing.

The evidence is shipped hash-bound at
`docs/artifacts/evidence/rq2-katran-map-inline-retained-bytecode/`:
`receipt.json` binds the command, source commit, normalized `make-corpus.log`,
the report stream, and the per-step bytecode for the changed workdir by SHA256
(14 files, all verified).  `docs/artifacts/render_claim_table.py` gained a
derived row (`RQ2 Katran retained map_inline bytecode (16 sites)`) that
recomputes the counts and both reconciliations at render time; it reads `PASS`,
and a mutation test on its reconciliation predicate made the renderer's
`--self-test` fail, proving the derivation is load-bearing.  The row set is now
52 rows (47 `PASS`, 5 `PARTIAL`); the five `PARTIAL` rows are unchanged.

## Scientific boundary and next action

Latitude, stated plainly: the Katran set is **thin**.  One changed load
instance and 16 applied sites is two orders of magnitude below Cilium's 122 and
3,787, so this result establishes that the overlay/hint policy path produces a
retained, verifiable rewrite — not any population-scale effect.  The fresh
16-site figure is reported beside, never merged with, the paper's declared
Katran site figures or with Cilium's fresh 3,787.  As in step 0008 this is a
rewrite-reconciliation result on a single startup, not per-pass throughput
causality; the workload counters retained in `apps/katran.json` (policy-to-
baseline pps ratio 1.0666, `run_time_ns_delta/run_cnt_delta` 177.00 → 153.75
ns/run) come from one start pair and are recorded as raw values only.

Two Katran-specific divergences from Cilium are handled explicitly rather than
papered over: one workload name repeats across N pktgen threads (so the workload
contract asserts equal baseline/post leaf counts and ≥1, not a fixed count), and
the hinted maps are size-skipped or key-absent because their values come from
static overlays (so the snapshot auditor's value check is `optional` for Katran
and unavailable checks are counted as `skipped_dump_unavailable` = 14, excluded
from the diagnostic denominator, rather than as misses).

The remaining runnable question is whether a second application can be pushed
past the single-changed-instance regime, and the proof line's next AArch64
items; both stay outside this step's scope.
