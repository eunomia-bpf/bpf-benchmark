# BUILD_AND_EVALUATE Step 0010 Report

Date: 2026-09-25
Experiment: extend retained-bytecode rewrite evidence to Tracee's hint-free `map_inline` policy path and stress-ng workload
Result: supported; the same rewrite reconciliation now holds for a third application, a third policy shape, and a non-packet workload parser

## Source ownership and experiment selection

Step 0008 retired the Cilium `.rodata.config` path and step 0009 the Katran
overlay/hint path.  Both are packet-generator applications whose `map_inline`
policy names its targets explicitly.  Tracee differs on both axes: its
`corpus/config/benchmark_config.yaml` entry uses the default policy
(`--map-values`, `--map-ids`, no `--inline-hint` anchors), it inlines its two
global config arrays (`config_map`, `netconfig_map`), and its workload is
stress-ng rather than kernel pktgen.  A Cilium-plus-Katran result therefore
leaves both the hint-free policy shape and the non-packet workload shape
unaudited.

The run was executed this step:

```
env PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=tracee/monitor \
    BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1 WORKLOAD_DURATION=30 \
    KEEP_WORKDIRS=1 make corpus -o runtime-kernel-image
```

with the standard `RUSTUP_HOME`/`CARGO_HOME`/`PATH`/`CLANG` and `VMLINUX_BTF`
exports, at source commit `14ab524f32`.  It exited 0 after ~362 s inside the
guest.  Only `runner/config/passes/**` policy was exercised; no frozen workload,
app runner, `corpus/driver.py`, benchmark Makefile, or launch wiring changed.

Making Tracee auditable required extending both independent analyzers along the
seams step 0009 opened rather than special-casing it:

- `analysis/audit_loadtime_evidence.py` gained a `STRESS_NG_RE` metrics-row
  parser and a `WORKLOAD_CONTRACTS["tracee/monitor"]` entry of `kind:
  stress_ng`; `parse_workloads` now dispatches to `_parse_pktgen_phase` or
  `_parse_stress_ng_phase` and selects `packets_per_second_sum` or
  `bogo_ops_per_second_sum` as the ratio metric from `contract["kind"]`.
- `analysis/audit_map_inline_snapshots.py` gained an `APP_CONTRACTS
  ["tracee/monitor"]` entry naming its two declared entry maps.

## Valid result

The retained report stream (`details/loadtime-reports/tracee__monitor.jsonl`)
holds 162 rows: 12 changed load instances and 150 unchanged, 12 applied sites,
instruction counts 400,640 → 398,817 (−1,823).  The run's `metadata.status` is
`completed`; the Tracee app record is `status: ok` with an empty `error`.

The changed set spans three program types — `kprobe` (`trace_dup`, `trace_dup2`,
`trace_dup3`, `trace_ptrace`, `trace_process_v`, `trace_arch_prct`,
`lkm_seeker_mod_`), `raw_tracepoint` (`sys_enter_init`, `sys_exit_init`,
`tracepoint__sch`) and `cgroup_skb` (`cgroup_skb_ingr`, `cgroup_skb_egre`) —
and the per-program deltas are large for single sites (`sys_enter_init` 579 →
416, `lkm_seeker_mod_` 218 → 90, `cgroup_skb_ingr` 3,602 → 3,420) because each
inlined array load replaces a whole map-value lookup sequence.

For all 12 changed workdirs the retained per-step `input.step.0.bin` /
`output.next.0.bin` are raw `struct bpf_insn[]` arrays whose lengths equal
`8 * insn_count_before` and `8 * insn_count_after`, and the two images differ
byte-for-byte.

Both independent auditors were run against the source run and agree.  The
load-time auditor (`--app tracee/monitor --expected-pass map_inline
--expected-samples 1 --expected-workload-seconds 30`) reports
`outcome: supported`, `integrity_errors.total = 0`,
`changed_load_instances = 12`, `sites_applied = sites_matched = 12`,
`changed_insns 11907 -> 10084`, every bytecode reconciliation at 12/12
(`input_matches_reported_before`, `mutable_input_matches_reported_after`,
`output_matches_reported_after`, `retained_output_next_0`),
`loads {optimized_events: 12, successful_changed_loads: 12,
failed_changed_loads: 0, unpaired_optimized_events: 0,
original_preflight_pass_throughs: 0}`, and
`workloads.policy_to_baseline_ratio = 1.0035`.  The snapshot auditor
(`--app tracee/monitor`) reports `outcome: supported` with the same 162/12/12
report counts, map classes exactly `config_map` and `netconfig_map` (both
`array`), and `weak_value_diagnostic {matches: 12, misses: 0,
skipped_dump_unavailable: 0}`.

Re-running each tool on the step-0008 Cilium and step-0009 Katran runs
reproduces their prior numbers byte-for-byte (169 rows / 122 changed / 3,787
sites / 0 integrity errors / 3,787 matches; 6 rows / 1 changed / 16 sites / 0
integrity errors / 2 matches + 14 skipped), so the extension regressed nothing.

The evidence is shipped hash-bound at
`docs/artifacts/evidence/rq2-tracee-map-inline-retained-bytecode/`:
`receipt.json` binds the command, source commit, normalized `make-corpus.log`,
the report stream, and the per-step bytecode for all 12 changed workdirs by
SHA256 (46 hashed files plus `receipt.json`, all verified; the raw
`output.next.0.bin` images are staged with `git add -f` because the repository's
bare `output*` gitignore rule would otherwise drop them).
`docs/artifacts/render_claim_table.py` gained a derived row (`RQ2 Tracee
retained map_inline bytecode (12 sites)`) that recomputes the counts and both
reconciliations at render time; it reads `PASS`, and a mutation test on the
shared reconciliation predicate (`len_mismatches == 0` → `>= 0`) made the
renderer's `--self-test` fail for all three applications at once, proving the
derivation is load-bearing.  The three near-duplicate Cilium/Katran/Tracee row
builders were consolidated into one `_retained_bytecode_app_row` helper plus
three thin wrappers, and the self-test gained a two-instance Tracee fixture that
asserts aggregation (`insn 1061->769`) as well as the `identical` and `short`
degradations.  The row set is now 53 rows (48 `PASS`, 5 `PARTIAL`); the five
`PARTIAL` rows are unchanged.

## Scientific boundary and next action

Latitude, stated plainly: the Tracee set is **small** — 12 changed load
instances and 12 applied sites, with exactly one site per program.  It
establishes that the hint-free policy path produces a retained, verifiable
rewrite across three program types and that the stress-ng workload parses
deterministically; it does not establish a population-scale effect.  The fresh
12-site figure is reported beside, never merged with, the paper's declared RQ2
4086 figure or any declared Tracee site count.

As in steps 0008 and 0009 this is a rewrite-reconciliation result on a single
startup, not per-pass throughput causality: the workload counters retained in
`apps/tracee__monitor.json` (policy-to-baseline bogo-ops/s ratio 1.0035,
356,542.34 → 357,790.41 summed across the seven stress-ng stressors) come from
one start pair and are recorded as raw values only.  The reported ratio is a
raw workload field the auditor prints, not a framework-side metric.

Three apps now cover three distinct `map_inline` policy shapes, but all three
remain single-startup rewrite reconciliations.  The remaining runnable
questions — a second application pushed past the single-site-per-program regime,
the proof line's next AArch64 items, and per-pass throughput causality — stay
outside this step's scope.

## Delivery

Two commits shipped this step and were pushed to `origin/master`:
`b917cb294` (the Tracee evidence dir, both analyzer extensions, the renderer
row, and the guide edits) and `b09aeea11` (this report).

The archival ZIP `docs/artifacts/dist/atc26-ae-2.zip` was then rebuilt so it no
longer predates them.  Rebuilding surfaced a real defect in
`docs/artifacts/package-atc26.sh` that predates this step: the unquoted
`README-ARTIFACT.md` heredoc interpreted the backticks around `map_inline`,
printing `bash: line 228: map_inline: command not found` and writing
`single-pass  run` into the archive README.  Commit `578762b98` escapes the
backticks, adds the Tracee run to the README's retained-evidence sentence, and
bumps the Tracee evidence paths into `ARTIFACT_MANIFEST.json`'s
`validationEvidence`.  A region-verbatim reproduction confirmed the escaped
heredoc emits literal backticks.

The rebuilt archive (916,380,580 bytes) reports
`superprojectCommit = 578762b985ac6d5e2aed4ec8115cd2bebddb5d5e`, contains a
correct README, and lists the three new `rq2-tracee-*` validation paths; its
`sha256` is `aa3317db6b7f731893b5d417088938dc7dd83f2ffb4f47fb6bc0199589f1797a`.
The packager's own `self-test: OK (10 evidence classes)` and clean-extraction
verification both passed on the rebuilt ZIP.
