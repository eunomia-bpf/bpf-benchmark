# BUILD_AND_EVALUATE Step 0011 Report

Date: 2026-09-25
Experiment: extend retained-bytecode rewrite evidence to Tetragon's default hint-free `map_inline` policy path (largest retained set, six maps, multi-site programs)
Result: supported; the same rewrite reconciliation now holds for a fourth application and a materially larger, structurally more varied rewrite population

## Source ownership and experiment selection

Steps 0008-0010 retired three `map_inline` policy shapes: Cilium's
`.rodata.config` path, Katran's overlay/hint path, and Tracee's hint-free path
on a stress-ng workload.  All three are *thin* or single-site-per-program: the
largest is Cilium at 122 changed load instances (large only because Cilium
folds many BPF objects into one aggregate `.rodata.config` inline), while
Katran is 1 instance / 16 sites and Tracee is 12 instances / 12 sites — exactly
one site per program.  The retained population therefore had no case with
**multiple applied sites in a single program** and no case with **several
distinct maps inlined across one application**.

Tetragon fills both gaps in one run.  Its
`corpus/config/benchmark_config.yaml` entry uses the default policy
(`--map-values`, `--map-ids`, no `--inline-hint` anchors; there is no
`overlays/tetragon/` hint file), it inlines six distinct array maps at once,
and its per-workdir site histogram is `{1: 106, 2: 2, 3: 10}` — ten programs
carry two or three applied sites.  Its program-type mix (kprobe-heavy plus
`tracepoint`, `raw_tracepoint`, `socket_filter`, `tracing`, `lsm`) and its
stress-ng workload also differ from the packet-generator applications.

The run was executed this step:

```
env PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=tetragon/observer \
    BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1 WORKLOAD_DURATION=30 \
    KEEP_WORKDIRS=1 make corpus -o runtime-kernel-image
```

with the standard `RUSTUP_HOME`/`CARGO_HOME`/`PATH`/`CLANG` and `VMLINUX_BTF`
exports, at source commit `ac3432e60`.  It exited 0 after ~400 s inside the
guest (`make exit=0`, `end 2026-09-25T13:38:53`).  Only
`runner/config/passes/**` policy was exercised; no frozen workload, app runner,
`corpus/driver.py`, benchmark Makefile, or launch wiring changed.

Making Tetragon auditable required extending both independent analyzers along
the seams steps 0009/0010 opened, not special-casing it:

- `analysis/audit_loadtime_evidence.py` gained a
  `WORKLOAD_CONTRACTS["tetragon/observer"]` entry of `kind: stress_ng` with the
  six-stressor set (`eventfd, mmap, udp, sock, sockfd, sockpair`), leaf count 1,
  and workload `stress_ng_tetragon_policy_hot`; the existing
  `_parse_stress_ng_phase` branch parses it unmodified.
- `analysis/audit_map_inline_snapshots.py` gained an
  `APP_CONTRACTS["tetragon/observer"]` entry naming its six declared entry maps
  (`tg_conf_map`, `policy_conf`, `policy_stats`, `cgroup_rate_opt`, `.rodata`,
  `config_map`); it falls into the existing `declared_entry_maps` branch, so no
  new code path was added.

## Valid result

The retained report stream
(`details/loadtime-reports/tetragon__observer.jsonl`) holds 215 rows: 118
changed load instances and 97 unchanged, 140 applied sites, instruction counts
234,754 → 220,562 (−14,192).  The run's `metadata.status` is `completed`; the
Tetragon app record is `status: ok` with an empty `error`.

This is the largest retained changed-instance set in the package (118 vs
Cilium's 122 — it is the first *kprobe-dominant* large set, and unlike Cilium's
it is spread over 118 independent BPF objects rather than folded into one
aggregate).  The changed set spans `kprobe` (110 instances), `tracepoint` (4),
`raw_tracepoint` (3) and `socket_filter` (1); the site-per-workdir histogram is
`{1: 106, 2: 2, 3: 10}`, so the reconciliation covers multi-site programs, not
only one site each.

Six distinct array maps are inlined, verified against each workdir's
`map-values/map-<id>.show.json`: `tg_conf_map` (77 sites), `policy_conf` (41),
`policy_stats` (18), `cgroup_rate_opt` (2), `.rodata` (1, `frozen=1`,
`flags=1152`, on the `execve_map_upda` socket_filter) and `config_map` (1,
`array`, 736-byte value, on the `generic_tracepo` tracepoint).

For all 118 changed workdirs the retained per-step `input.step.0.bin` /
`output.next.0.bin` are raw `struct bpf_insn[]` arrays whose lengths equal
`8 * insn_count_before` and `8 * insn_count_after`, and the two images differ
byte-for-byte.

Both independent auditors were run against the source run and agree.  The
load-time auditor (`--app tetragon/observer --expected-pass map_inline
--expected-samples 1 --expected-workload-seconds 30`) reports
`outcome: supported`, `integrity_errors.total = 0`,
`changed_load_instances = 118`, `sites_applied = sites_matched = 140`,
`changed_insns 76619 -> 62427` (changed instances only),
`loads {optimized_events: 118, successful_changed_loads: 118,
failed_changed_loads: 0, unpaired_optimized_events: 0,
original_preflight_pass_throughs: 2}`, and a raw
`workloads.policy_to_baseline_ratio = 2.4667` (bogo-ops/s sum 328,719.88 →
810,844.13).  The snapshot auditor (`--app tetragon/observer`) reports
`outcome: supported` with the same 215/118/140 report counts, exactly the six
declared `map_classes` (all `array`), and
`weak_value_diagnostic {matches: 140, misses: 0, skipped_dump_unavailable: 0}`.
The auditor's non-blocking `other_candidate_errors` list (2 `bpfopt step
map_inline failed` and 61 `verifier probe rejected candidate ... errno=22 ...
passing original BPF_PROG_LOAD through`) is reported raw; per the project's
fail-visible policy it surfaces as a record, not as a hidden gate.

Re-running each tool on the step-0008 Cilium, step-0009 Katran and step-0010
Tracee runs reproduces their prior numbers byte-for-byte (169/122/3787/0
integrity errors/3787 matches; 6/1/16/0/2 matches + 14 skipped;
162/12/12/0/12 matches), so the extension regressed nothing.

The evidence is shipped hash-bound at
`docs/artifacts/evidence/rq2-tetragon-map-inline-retained-bytecode/`:
`receipt.json` binds the command, source commit, normalized `make-corpus.log`,
the report stream, and the per-step bytecode for all 118 changed workdirs by
SHA256 (364 hashed files plus `receipt.json` = 365 staged, all verified; the raw
`output.next.0.bin` images are staged with `git add -f` because the repository's
bare `output*` gitignore rule would otherwise drop them).
`docs/artifacts/render_claim_table.py` gained a derived row (`RQ2 Tetragon
retained map_inline bytecode (140 sites)`) that recomputes the counts and both
reconciliations at render time; it reads `PASS`, and a mutation test on the
shared reconciliation predicate (`len_mismatches == 0` → `>= 0`) made the
renderer's `--self-test` fail for all four applications at once, proving the
derivation is load-bearing.  The self-test gained a three-instance Tetragon
fixture (including a 3-site program) that asserts aggregation
(`insn 700->510`) as well as the `identical` and `short` degradations.  The row
set is now 54 rows (49 `PASS`, 5 `PARTIAL`); the five `PARTIAL` rows are
unchanged.

## Scientific boundary and next action

Latitude, stated plainly: this is a rewrite-reconciliation result on a single
startup, not per-pass throughput causality.  The workload counters retained in
`apps/tetragon__observer.json` (policy-to-baseline bogo-ops/s ratio 2.4667)
come from one start pair and are recorded as raw values only; the ratio is a
raw workload field the auditor prints, not a framework-side metric, and with
`SAMPLES=1` it is not a stability claim.

What Tetragon adds is breadth of the *rewrite*, not of the *measurement*: the
retained set now covers multi-site programs and six simultaneously-inlined
maps, so the reconciliation predicate is exercised over programs whose before/
after deltas are not single-site lookups.  It does not establish a
population-scale effect, and the fresh 140-site figure is reported beside,
never merged with, the paper's declared Tetragon site figures.

Four `map_inline` policy shapes and four applications are now covered, but all
remain single-startup rewrite reconciliations.  The remaining runnable
questions — the proof line's AArch64 items, and per-pass throughput causality —
stay outside this step's scope.

## Delivery

One commit shipped this step and was pushed to `origin/master`: `d667370cc`
(the Tetragon evidence dir, both analyzer extensions, the renderer row plus its
self-test fixture, the `package-atc26.sh` manifest/required additions, and the
two additive guide edits).

The archival ZIP `docs/artifacts/dist/atc26-ae-2.zip` was then rebuilt so it
names the new commit and the new evidence paths: 917,166,159 bytes, sha256
`b57e3cc441851df101489a3b75e0630b447556dfba36fa91c6560151b65e035c`,
`ARTIFACT_MANIFEST.json.superprojectCommit =
d667370ccdb661aae9230d698ed4c201af6aaa56`, and `validationEvidence` lists the
three new `rq2-tetragon-*` paths beside the three `rq2-tracee-*` paths.  The
packager's own `self-test: OK (10 evidence classes)` and clean-extraction
verification both passed.
