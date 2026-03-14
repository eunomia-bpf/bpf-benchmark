# Corpus v2 Policy Diagnosis

Date: 2026-03-12

## Summary

- `corpus/results/corpus_v5_v2_policy_20260312.json` underperformed both blind all-apply (`0.848x` vs `0.868x`) and v1 tuned (`0.898x`).
- The main root cause was not policy lookup. It was the policy representation:
  - v2 corpus policies were generated as an offline `(insn,family)` allowlist.
  - the files mostly used `default: skip`/`stock`, so any live-site mismatch collapsed to "apply nothing".
  - runtime filtering matched exact `(insn,family)` pairs against the live xlated program.
- A second issue remained after accounting for drift: some programs are still hurt by the coarse object-level CMOV regressor heuristic. `test_tc_tunnel:__encap_udp_eth` is the clearest example.

## Evidence

### 1. Shared-result comparison

- Compared `corpus/results/corpus_v5_vm_batch_authoritative_20260311.json` vs `corpus/results/corpus_v5_v2_policy_20260312.json`.
- On the shared measured set (`155` programs), the worst deltas vs blind included:
  - `res_spin_lock_test`: `16.743x -> 1.015x`
  - `__encap_udp_eth`: `1.250x -> 0.438x`
  - `from_nat_debug:calico_tc_skb_send_icmp_replies`: `1.203x -> 0.575x`
  - `healthcheck_encap`: `0.529x -> 0.500x`

### 2. Policy-file failures were dominated by stale sites

- `109` programs used `policy-file`.
- `70/109` emitted `policy site ... was not found in the live program; skipping`.
- `56/109` emitted `policy selected 0 of N eligible rules`.
- The warnings concentrated in `calico` (`49`) and `linux-selftests` (`13`).

Representative examples from the old v2 run:

- `katran/healthchecking:healthcheck_encap`
  - old policy: `default: skip`, only `endian insn 173 action=apply`
  - runtime: `policy site endian insn 173 ... was not found in the live program; skipping`
  - runtime: `policy selected 0 of 9 eligible rules`
- `linux-selftests/res_spin_lock:res_spin_lock_test`
  - old policy: `default: skip`, only `cmov insn 45 action=apply`
  - runtime: same stale-site pattern, then no apply

### 3. Object vs live scan confirmed coordinate drift

#### `healthcheck_encap`

- Object scan:
  - `cmov@150`
  - `endian@173`
- Live xlated scan:
  - `branch-flip@23,68,88,102,168,243,360`
  - `cmov@190`
  - `endian@213`

Conclusion:

- verifier/libbpf processing changed both offsets and the family inventory.
- the old policy could not match `endian@173`, and it also had no way to express the live-only `branch-flip` sites.

Artifacts used:

- object: `scanner scan corpus/build/katran/healthchecking.bpf.o --program-name healthcheck_encap --all --json`
- live: `scanner scan --xlated docs/tmp/healthcheck_encap.live.xlated --program-name healthcheck_encap --all --json`

#### `res_spin_lock_test`

- Object scan:
  - `cmov@45`
- Live xlated scan:
  - `branch-flip@8,24`
  - `cmov@57`

Conclusion:

- exact-site matching turned a big CMOV win into a no-op because the only explicit allowlisted site moved.

Artifacts used:

- object: `scanner scan corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o --program-name res_spin_lock_test --all --json`
- live: `scanner scan --xlated docs/tmp/res_spin_lock_test.live.xlated --program-name res_spin_lock_test --all --json`

### 4. Drift was not the only problem

`linux-selftests/test_tc_tunnel:__encap_udp_eth` was the counterexample:

- object scan and live scan both saw the same two sites: `endian@65`, `cmov@149`
- old v2 still regressed because the policy requested only `endian`
- that came from the coarse object-level CMOV regressor heuristic: the object was marked as CMOV-negative, so v2 dropped CMOV for every program in the object

This means the fix needed two parts:

1. stop using exact offline site allowlists as the primary steady-state policy
2. keep CMOV suppression as a coarse family decision, not a stale site-level omission

## Fix

### Policy semantics

Added family-level overrides to version 2 policy parsing/filtering:

- new field: `families: { family: apply|skip }`
- precedence is now:
  - explicit site override
  - family override
  - global `default`
- `sites` is now optional and may be empty

Files changed:

- `scanner/include/bpf_jit_scanner/policy_config.hpp`
- `scanner/src/policy_config.cpp`
- `scanner/tests/test_scanner.cpp`
- `corpus/policy_utils.py`

### Generator strategy

Changed `corpus/generate_default_policies.py` from:

- offline explicit `apply` site list
- `default: skip` or `default: stock`

to:

- `default: apply`
- optional `families: { cmov: skip }` on known CMOV regressor objects
- `sites: []`

This makes runtime selection depend on the live xlated scan rather than offline insn coordinates, while preserving the intended CMOV suppression.

All corpus policy artifacts were regenerated:

- `580` policy files rewritten
- new aggregate shape:
  - defaults: `{'apply': 580}`
  - files with `families`: `196`
  - files with explicit `sites`: `0`

## Smoke Validation

Smoke artifact:

- `docs/tmp/corpus-v2-policy-smoke-20260312.json`
- `docs/tmp/corpus-v2-policy-smoke-20260312.md`

Scope:

- `13` targets covering the main failure modes:
  - `healthcheck_encap`
  - `res_spin_lock*`
  - `__encap_udp_eth`
  - `calico_*send_icmp_replies`

Results:

- old v2 authoritative geomean on this subset: `0.758x`
- blind all-apply geomean on this subset: `1.170x`
- new smoke geomean on this subset: `1.055x`

Key recoveries:

- `healthcheck_encap`: `0.500x -> 0.850x`
- `res_spin_lock_test`: `1.015x -> 8.644x`
- `from_nat_debug:calico_tc_skb_send_icmp_replies`: `0.575x -> 1.019x`
- all `policy selected 0 of N` / stale-site warnings disappeared on this subset

Remaining weak spot:

- `__encap_udp_eth`: `0.438x -> 0.492x`
- it is still below blind because the object-level `cmov: skip` heuristic likely remains too coarse for `test_tc_tunnel`

## Conclusion

- The dominant regression mechanism was `site drift + default skip/stock`, not path resolution.
- The fix is to make v2 steady-state policies family-driven and live-scan-based, not offline site-allowlist-based.
- The targeted smoke strongly supports the fix direction: it removed stale-site no-op behavior and materially recovered the worst regressors.
- A full corpus rerun is still required.
- If the full rerun is still below blind, the next tuning target is the CMOV regressor heuristic, especially object-level skips such as `test_tc_tunnel`.
