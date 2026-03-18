# Corpus Rerun 2026-03-18

## 1. How `vm-corpus` runs

- Makefile target: `make vm-corpus REPEAT=200`
- Actual entrypoint: `micro/driver.py corpus v5-vm-batch --use-policy`
- This path uses per-program `version: 3` policy files under `corpus/policies/`
- It does **not** use the old `--blind-apply --recompile-all` debug lane
- Target selection comes from `docs/tmp/corpus-runnability-results.json` via `load_packet_test_run_targets()`
- In this checkout that inventory file had been deleted during cleanup, so I restored it at the default path from `corpus/results/corpus_recompile_authoritative_20260313.json`
- Restored inventory semantics match the old authoritative run's measured set: `152` baseline-ok packet-test-run targets

## 2. Round 1: refreshed policy as-is

Command:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
make vm-corpus REPEAT=200
```

Output:

- JSON: `corpus/results/dev/vm_corpus_round1_20260318.json`
- Markdown: `corpus/results/dev/vm_corpus_round1_20260318.md`

Topline:

- Overall exec geomean: `0.8995x`
- Applied programs: `27`
- Applied-only exec geomean: `1.0472x`
- Non-applied exec geomean: `0.8705x`

By source:

- `calico`: `1.0376x`
- `katran`: `1.0050x`
- `tracee`: `1.0000x`
- `xdp-tutorial`: `1.0425x`
- `linux-selftests`: `0.7351x`
- `xdp-tools`: `0.7641x`

Main findings:

- `40` stale policy misses remained
- Breakdown: `calico=35`, `katran=2`, `linux-selftests=2`, `xdp-tutorial=1`
- `katran/balancer_ingress` confirmed the object-vs-live mismatch:
  - policy file had only `wide=4 + endian=4`
  - live xlated scan still had `94` sites (`branch-flip=56 rotate=20 cmov=8 endian=4 wide=4 extract=2`)
- Two `linux-selftests/.../balancer_ingress` rotate policies failed recompile with `EINVAL`
- Persistent actual-apply regressors:
  - `calico/to_nat_debug/calico_tc_skb_icmp_inner_nat` (`0.656x`)
  - `calico/to_wep_debug/calico_tc_skb_icmp_inner_nat` (`0.888x`)
  - `linux-selftests/test_tc_tunnel/__encap_sit_none` (`0.800x`)
  - `xdp-tools/xdp_fwd_fib_full` (`0.979x`, also historically negative)

## 3. Policy adjustment

I made two classes of changes.

1. Live-xlated remap for stale policies

- Refreshed `38` stale policy files by:
  - dumping guest xlated for the exact program with `vng --rwdir <repo>`
  - scanning the dumped xlated with `scanner scan --xlated --all --json`
  - remapping the existing policy onto the live manifest with `remap_policy_v3_to_live()`
- Important detail: I preserved the current family selection already present in each policy; this was a stale-site refresh, not a blind family expansion

2. Clear known-bad policies

- Cleared the two rotate policies that reproducibly hit `BPF_PROG_JIT_RECOMPILE ... errno=22`
- Cleared four persistent actual regressors:
  - `corpus/policies/calico/to_nat_debug/calico_tc_skb_icmp_inner_nat.policy.yaml`
  - `corpus/policies/calico/to_wep_debug/calico_tc_skb_icmp_inner_nat.policy.yaml`
  - `corpus/policies/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel/__encap_sit_none.policy.yaml`
  - `corpus/policies/xdp-tools/xdp_forward/xdp_fwd_fib_full.policy.yaml`

## 4. Round 2: after live refresh + clears

Command:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
make vm-corpus REPEAT=200
```

Output:

- JSON: `corpus/results/dev/vm_corpus_round2_20260318.json`
- Markdown: `corpus/results/dev/vm_corpus_round2_20260318.md`

Topline:

- Overall exec geomean: `0.8810x`
- Applied programs: `61`
- Applied-only exec geomean: `1.0767x`
- Non-applied exec geomean: `0.7701x`
- Stale misses: `0`
- Recompile failures: `0`

By source:

- `calico`: `1.0656x`
- `katran`: `1.0488x`
- `tracee`: `1.0198x`
- `xdp-tutorial`: `1.2283x`
- `linux-selftests`: `0.6292x`
- `xdp-tools`: `0.7748x`

What improved:

- `applied` count jumped `27 -> 61`
- `applied-only` improved `1.0472x -> 1.0767x`
- `calico` improved `1.0376x -> 1.0656x`
- `katran` improved `1.0050x -> 1.0488x`
- `balancer_ingress` in Katran now actually applied (`wide+endian`) and improved from `0.5667x` in old authority to `0.9138x` in round 2
- `_fix_port_egress` improved from stale-miss `0.3333x` to applied `1.2500x`
- `recompile_failure_reasons` became empty

What still blocks overall:

- The remaining `91` non-applied rows are extremely noisy: geomean `0.7701x`
- The worst regressors in round 2 are almost all stock/no-op rows with no applied families:
  - `tc_count_pkts 0.125x`
  - `tcx6 0.238x`
  - `main_does_not_change 0.267x`
  - `prepare/program 0.286x`
  - `main_changes 0.333x`
- `linux-selftests` is dominated by these non-applied rows and collapsed to `0.6292x`

## 5. Why I stopped iterating

After round 2, stale policy misses were already eliminated. The remaining deficit is not primarily a policy-hit problem.

Counterfactuals from the round 2 JSON:

- If every remaining **eligible but non-applied** row were magically neutral (`1.0x`), overall would still only be `0.9378x`
- If **all non-applied** rows were magically neutral (`1.0x`), overall would be only `1.0301x`
- A very optimistic upper bound, where every remaining eligible non-applied row somehow achieved the current applied-only geomean (`1.0767x`) and every other non-applied row became neutral, is only `1.0554x`

Interpretation:

- Policy tuning fixed what it could fix:
  - stale miss count `40 -> 0`
  - applied geomean `1.047x -> 1.077x`
- The remaining overall loss is dominated by stock/no-op rows, especially `linux-selftests`, whose paired measurements moved sharply negative relative to the 2026-03-13 authoritative run even without recompile apply
- That behavior is outside the reach of policy cleanup alone

## 6. Final status

- Goal `> 1.05x` overall: **not achieved**
- Old authority `1.0463x`: **not beaten**
- Best result today:
  - full corpus overall: `0.8995x` in round 1, `0.8810x` in round 2
  - best policy-sensitive metrics: round 2 `applied-only 1.0767x`, `calico 1.0656x`, `katran 1.0488x`, `xdp-tutorial 1.2283x`

Best-supported conclusion:

- The refreshed policy family is directionally better once it actually applies
- The current blocker is corpus-wide non-applied measurement instability, not stale policy hits anymore
- Further meaningful improvement now requires benchmark-side work on the non-applied/no-op population, not another small policy sweep
