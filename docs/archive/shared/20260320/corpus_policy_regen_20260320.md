# Corpus Policy Regeneration Report (2026-03-20)

- Goal: regenerate `corpus/policies/` after the scanner ROTATE tightening from task `#268`, while continuing to skip `cmov` and `extract` per `#193`.
- Note on CLI: the current generator expects `--skip-families` as a single comma-separated value. The literal command
  `python3 corpus/generate_default_policies.py --skip-families cmov extract`
  fails with `unrecognized arguments: extract`. I ran the equivalent intended command:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
python3 corpus/generate_default_policies.py --skip-families cmov,extract
```

## Generation Summary

- Generator summary:
  `scanned_objects=565`
  `site_positive_objects=150`
  `site_positive_programs=580`
  `policies_written=580`
  `skip_families=cmov,extract`
  `skip_objects=cmov:124,extract:37`
  `skip_programs=cmov:494,extract:97`
  `stale_removed=2`
  `warnings=111`

## Diff Summary

- `46` policy files changed relative to `HEAD`.
- Status breakdown: `44` modified, `2` deleted.
- `git diff --stat -- corpus/policies` reports `1059` insertions and `756` deletions.
- Removed stale policy files:
  `corpus/policies/linux-selftests/tools/testing/selftests/bpf/progs/core_kern/balancer_ingress.policy.yaml`
  `corpus/policies/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2/balancer_ingress.policy.yaml`

## ROTATE Impact

- `10` explicit `rotate` policy sites were removed by the regeneration.
- All `10` removed rotate sites came from:
  `corpus/policies/calico/from_hep_debug/calico_tc_maglev.policy.yaml`
- In the changed set, explicit rotate allowlist entries went from `10` to `0`.
- After regeneration, the entire current `corpus/policies/` tree contains `0` explicit `rotate` allowlist sites.

## Validation

- Parsed every generated policy successfully with:

```bash
python3 -c 'from corpus.policy_utils import parse_policy_v3; import glob; [parse_policy_v3(open(f).read()) for f in glob.glob("corpus/policies/**/*.yaml", recursive=True)]'
```

- Result: success (`PARSE_OK`).
