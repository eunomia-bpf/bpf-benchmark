# BUILD_AND_EVALUATE Step 0012 Report

Date: 2026-09-25
Experiment: extend retained-bytecode rewrite evidence to **AArch64** — the same Katran overlay/hint `map_inline` policy path, executed by the local arm64 QEMU corpus executor
Result: supported; the rewrite reconciliation is architecture-symmetric (arm64 Katran reproduces the x86 set's 1 changed instance / 16 applied sites / 2554→2284 insns exactly)

## Source ownership and experiment selection

Steps 0008-0011 retired four `map_inline` policy shapes across four
applications — Cilium's `.rodata.config` path, Katran's overlay/hint path,
Tracee's hint-free path, and Tetragon's hint-free multi-map path.  **Every one
of the four sets was x86 only.**  AArch64 had been explored for `kop`-class
passes and for RQ3 Katran site arms, but no *retained-bytecode* set existed on
the arm64 axis, so the reconciliation claim ("the retained before/after
bytecode lengths match the reported instruction counts and the images differ")
had never been demonstrated on the second architecture the paper measures.

Katran is the cheapest arm64 counterpart: its x86 set is a single changed
instance / 16 applied sites, its arm64 `map_inline` policy path was already
known to complete under local QEMU, and the local arm64 prerequisites
(`.cache/container-images/arm64-runner-runtime.image.tar`,
`.cache/qemu-arm64-root/qemu-init`, `vendor/build/arm64/linux/arch/arm64/boot/Image`,
`qemu-system-aarch64`) were current — no AWS instance was needed.

The run was executed this step:

```
env PLATFORM=qemu ARCH=arm64 BPFREJIT_CORPUS_APPS=katran \
    BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1 WORKLOAD_DURATION=30 \
    KEEP_WORKDIRS=1 make corpus
```

with the standard `RUSTUP_HOME`/`CARGO_HOME`/`PATH`/`CLANG` exports, at source
commit `8f90c5a12`.  It exited 0; the guest-reported window was
`1970-01-01T00:00:12.467359` → `1970-01-01T00:05:38.512353`, i.e. 326 s (the
arm64 guest clock is unset, so arm64 `metadata.json` timestamps are epoch-based
and its `source_revision`/`command` are `None` — the run's own
`provenance/start.json` carries the host HEAD and the exact command).  Only
`runner/config/passes/**` policy was exercised; no frozen workload, app runner,
`corpus/driver.py`, benchmark Makefile, or launch wiring changed.

Making the arm64 run auditable required extending **both** independent
analyzers plus the renderer along the seam, not special-casing QEMU.  Each file
already gated on the literal `"x86_kvm_corpus"`; each now has one shared
`CORPUS_RUN_TYPES = {"x86_kvm_corpus", "arm64_qemu_corpus"}` set and a
membership test, so a single code path serves both architectures:

- `analysis/audit_loadtime_evidence.py`: run-type gate is now
  `require(metadata.get("run_type") in CORPUS_RUN_TYPES, ...)`.
- `analysis/audit_map_inline_snapshots.py`: same membership gate; its
  `samples == 1` / `workload_seconds == 30.0` gates already matched the run's
  contract and were untouched.
- `docs/artifacts/render_claim_table.py`: `_retained_bytecode_app_row`'s
  `run_ok` predicate now tests membership.  The file already knew the
  `arm64_qemu_corpus` run type elsewhere (the RQ3 Katran site arms pass
  `run_type="arm64_qemu_corpus"`), so this is the same vocabulary, not a new
  one.

## Valid result

The retained report stream (`details/loadtime-reports/katran.jsonl`) holds 6
rows: 1 changed load instance and 5 unchanged, 16 applied sites, instruction
counts 2,554 → 2,284 (−270).  The run's `metadata.status` is `completed`
(`run_type: arm64_qemu_corpus`, `samples: 1`, `workload_seconds: 30.0`); the
Katran app record is `status: ok` with an empty `error`.

The single changed instance is `balancer_ingres` (`xdp`) at 2,542 → 2,272
insns; the five unchanged rows are the two `socket_filter` bootstrap probes
(`1017_0`, `1017_2`), the `libbpf_nametest` `socket_filter`, the `det_arg_ctx`
`kprobe`, and the `cgroup_sock` program — each at 2 or 4 insns with 0 applied
sites.

This is byte-for-byte symmetric with the x86 Katran set (also 1 changed
instance, 16 applied sites, 2,554 → 2,284), which is the expected result: the
policy is the same overlay/hint `map_inline` path with identical
`overlays/katran/*.json` inputs, so the rewrite itself should not depend on the
target ISA.  The retained evidence is what demonstrates that, rather than
asserting it.

For the changed workdir the retained per-step `input.step.0.bin` /
`output.next.0.bin` are raw `struct bpf_insn[]` arrays (8 bytes per insn on both
architectures) whose lengths equal `8 * 2542 = 20336` and `8 * 2272 = 18176`,
and the two images differ byte-for-byte.

Both independent auditors were run against the source run and agree.  The
load-time auditor (`--app katran --expected-pass map_inline --expected-samples 1
--expected-workload-seconds 30`) reports `outcome: supported`,
`integrity_errors.total = 0`, `changed_load_instances = 1`,
`sites_applied = sites_matched = 16`, `changed_insns 2542 -> 2272`,
`loads {optimized_events: 1, successful_changed_loads: 1, failed_changed_loads:
0, unpaired_optimized_events: 0}`, and 6 referenced workdirs.  The snapshot
auditor (`--app katran`) reports `outcome: supported` with the same 6/1/16
counts and exactly the five hinted map classes — `reals` (6),
`vip_map` (4), `ch_rings` (2), `ctl_array` (2), `server_id_map` (2), all
`array` except `vip_map` (`hash`) — and
`weak_value_diagnostic {matches: 2, misses: 0, skipped_dump_unavailable: 14}`.

Re-running each tool on the step-0008 Cilium, step-0009 Katran, step-0010
Tracee and step-0011 Tetragon x86 runs reproduces their prior numbers
byte-for-byte (169/122/3787/0/3787; 6/1/16/0/2 + 14 skipped; 162/12/12/0/12;
215/118/140), so widening the gate regressed nothing.

The evidence is shipped hash-bound at
`docs/artifacts/evidence/rq2-katran-arm64-map-inline-retained-bytecode/`:
`receipt.json` binds the command, source commit, normalized `make-corpus.log`,
the report stream, and the per-step bytecode for the changed workdir by SHA256
(13 hashed files plus `receipt.json` = 14 staged, all verified; the raw
`output.next.0.bin` image is staged with `git add -f` because the repository's
bare `output*` gitignore rule would otherwise drop it).
`docs/artifacts/render_claim_table.py` gained a derived row (`RQ2 Katran arm64
retained map_inline bytecode (16 sites)`) that recomputes the counts and both
reconciliations at render time; it reads `PASS`.  Its self-test fixture proves
the widened gate is load-bearing: the fixture's valid arm64 run passes, an
`x86_kvm_corpus` run also passes (one code path), and a deliberately unknown
run type flips the row to `PARTIAL` with `run status valid=False`.  Removing
`"arm64_qemu_corpus"` from the shared set makes the fixture fail, which is the
mutation test for this step.  The row set is now 55 rows (50 `PASS`, 5
`PARTIAL`); the five `PARTIAL` rows are unchanged, and the 54 pre-existing row
labels are byte-identical to the pre-edit dump.

## Scientific boundary and next action

Latitude, stated plainly: this is a rewrite-reconciliation result on a single
startup, not per-pass throughput causality, and it is a *breadth-of-architecture*
result rather than a new magnitude.  The arm64 Katran set is the smallest in the
package (1 changed instance), so it establishes that the same overlay/hint
rewrite and the same reconciliation hold under the arm64 executor — not a
population-scale effect.  The fresh 16-site figure is reported beside, never
merged with, the paper's declared Katran site figures or with the x86 set.  The
raw workload counters retained in `apps/katran.json` (two
`katran_kernel_pktgen_l2_udp_thread` components, 95,312 / 92,829 packets per
second in the baseline phase vs 92,449 / 87,578 in the post-ReJIT phase, a raw
`policy_to_baseline_ratio = 0.9569`) come from one start pair and are recorded
as raw values only; with `SAMPLES=1` they are not a stability claim.

Five `map_inline` retained-bytecode sets now span five applications and two
architectures, but all remain single-startup rewrite reconciliations.  The
remaining runnable question — **per-pass throughput causality** — stays outside
this step's scope.

## Delivery

One commit shipped this step and was pushed to `origin/master`: `66261fe12`
(the arm64 evidence dir, the three widened run-type gates, the renderer row plus
its self-test fixture, the `package-atc26.sh` manifest/required additions and
its `README-ARTIFACT.md` enumeration, and the two additive guide edits).
