# const_prop Cilium datapath fix round 1

## Code changes

- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:31`: verifier oracle keys are now `(pc, frame, reg)`, with `frames_by_pc` tracked for context-insensitive simulation.
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:121`: `from_states` now counts visits per `(pc, frame)` and observations per `(pc, frame, reg)`. A fact is accepted only when every visit observed that register and the observed exact value has no conflict.
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:166`: when simulation has no concrete verifier frame, lookup is fail-closed across all frames at that PC; every frame must have an agreeing exact fact.
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:433`: call post-state oracle replay is blocked so R0-R5 are not repopulated after helper-call clobbering.
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:439`: `MOV X` is treated as provenance-sensitive. It does not receive verifier-oracle post-state replay and is not materialized from oracle facts; local scalar-only evaluation can still fold it.

## Tests added

- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:865`  
  `const_prop_does_not_seed_caller_saved_regs_from_call_post_state`
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:880`  
  `const_prop_does_not_use_oracle_for_register_mov_provenance`
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:898`  
  `const_prop_rejects_replacement_when_observation_missing_at_some_visit`
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:920`  
  `const_prop_rejects_replacement_when_full_state_visit_omits_reg`
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:936`  
  `const_prop_rejects_replacement_across_disagreeing_frames`
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:952`  
  `const_prop_accepts_when_every_visit_agrees`

Each test has a `Bug caught:` comment describing the specific regression it detects.

## Validation

Unit test:

```bash
cargo test -p bpfopt -- const_prop
```

Result: passed. `15` `const_prop`-matching lib tests, `1` main test, and doc tests passed.

Cilium reproducer:

```bash
PLATFORM=kvm ARCH=x86 SAMPLES=1 WORKLOAD_DURATION=10 BPFREJIT_BENCH_PASSES="noop,const_prop" BPFREJIT_CORPUS_APPS="cilium/agent" KEEP_WORKDIRS=1 TIMEOUT=3600 make corpus
```

Result dir: `corpus/results/x86_kvm_corpus_20260508_201303_179175`

Observed app payload:

- `status`: `ok`
- `error`: empty string
- `baseline.workloads[]`: `1`
- `post_rejit.workloads[]`: `1`
- `baseline.bpf[]`: `53`
- `post_rejit.bpf[]`: `53`
- `rejit_result.status`: `ok`
- `const_prop` pass statuses: `46` ok, `3` failed_rejit recorded

Katran regression check:

```bash
PLATFORM=kvm ARCH=x86 SAMPLES=1 WORKLOAD_DURATION=10 BPFREJIT_BENCH_PASSES="noop,const_prop" BPFREJIT_CORPUS_APPS="katran" KEEP_WORKDIRS=1 TIMEOUT=3600 make corpus
```

Result dir: `corpus/results/x86_kvm_corpus_20260508_201652_917373`

Observed app payload:

- `status`: `ok`
- `error`: empty string
- `baseline.workloads[]`: `1`
- `post_rejit.workloads[]`: `1`
- `baseline.bpf[]`: `1`
- `post_rejit.bpf[]`: `1`
- `rejit_result.status`: `ok`
- `const_prop sites_applied`: `122`

## Cilium sites_applied comparison

Computed from `details/apps/cilium__agent.json`:

```bash
jq '[.rejit_result.per_program[]?.passes[]? | select(.step.name=="const_prop") | (.bpfopt_summary.sites_applied // 0)] | add // 0' <app-json>
```

- Before fix, provided failing run `corpus/results/x86_kvm_corpus_20260508_191351_975279`: `1229`
- After fix, passing run `corpus/results/x86_kvm_corpus_20260508_201303_179175`: `964`

