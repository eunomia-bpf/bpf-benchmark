# 2026-04-22 bpftrace + BCC Threshold Refresh

## Scope and Rule

- Read:
  - `docs/kernel-jit-optimization-plan.md` (`#663`, `#664`, `#666`)
  - `docs/tmp/program-discovery-review-20260422/summary.md`
- Authoritative sources used for the refresh:
  - `e2e/results/bpftrace_authoritative_20260331.json`
  - `e2e/results/bcc_authoritative_20260403.json`
- Audit rule:
  - threshold = authoritative `requested`
  - if multiple authoritative reruns disagree, use the max
  - do not change tools/scripts without authoritative data

## Historical Rerun Audit

- `bpftrace` requested counts were consistent across the reruns that carry `program_counts.requested`: `bpftrace_authoritative_20260331.json` and `bpftrace_authoritative_20260403.json`.
- `bcc` requested counts were consistent across the reruns that carry `program_counts.requested`: `bcc_authoritative_20260331.json` and `bcc_authoritative_20260403.json`.
- Result: no family needed a max-over-inconsistent override; the latest listed authoritative files already matched the rerun maxima.

## Changed Thresholds

| Family | Tool / Script | Config path | Before | After | Authoritative requested | Active in same authoritative run | Note |
| --- | --- | --- | ---: | ---: | --- | --- | --- |
| bpftrace | `vfsstat` | `runner/libs/app_runners/bpftrace.py` | 2 | 4 | `e2e/results/bpftrace_authoritative_20260331.json:5383` | `4` at `e2e/results/bpftrace_authoritative_20260331.json:4617` | Requested and active match. |
| bcc | `biosnoop` | `e2e/cases/bcc/config.yaml` | 2 | 4 | `e2e/results/bcc_authoritative_20260403.json:3870` | `3` at `e2e/results/bcc_authoritative_20260403.json:2389` | Chose requested; active is lower in this workload. |
| bcc | `opensnoop` | `e2e/cases/bcc/config.yaml` | 2 | 6 | `e2e/results/bcc_authoritative_20260403.json:11684` | `2` at `e2e/results/bcc_authoritative_20260403.json:9359` | Large requested/active gap; chose requested per rule. |
| bcc | `capable` | `e2e/cases/bcc/config.yaml` | 1 | 2 | `e2e/results/bcc_authoritative_20260403.json:13151` | `2` at `e2e/results/bcc_authoritative_20260403.json:12323` | Requested and active match. |
| bcc | `vfsstat` | `e2e/cases/bcc/config.yaml` | 5 | 8 | `e2e/results/bcc_authoritative_20260403.json:16960` | `6` at `e2e/results/bcc_authoritative_20260403.json:14320` | Large requested/active gap; chose requested per rule. |
| bcc | `tcpconnect` | `e2e/cases/bcc/config.yaml` | 2 | 4 | `e2e/results/bcc_authoritative_20260403.json:19511` | `4` at `e2e/results/bcc_authoritative_20260403.json:17908` | Requested and active match. |
| bcc | `bindsnoop` | `e2e/cases/bcc/config.yaml` | 3 | 4 | `e2e/results/bcc_authoritative_20260403.json:21912` | `4` at `e2e/results/bcc_authoritative_20260403.json:20302` | Requested and active match. |

## Not Changed

Already aligned with authoritative requested counts:

| Family | Tool / Script | Current threshold | Authoritative requested | Active in same authoritative run | Reason |
| --- | --- | ---: | --- | --- | --- |
| bpftrace | `tcplife` | 1 | `1` at `e2e/results/bpftrace_authoritative_20260331.json:1122` | `1` at `e2e/results/bpftrace_authoritative_20260331.json:821` | Already matched. |
| bpftrace | `biosnoop` | 2 | `2` at `e2e/results/bpftrace_authoritative_20260331.json:1911` | `2` at `e2e/results/bpftrace_authoritative_20260331.json:1471` | Already matched. |
| bpftrace | `runqlat` | 3 | `3` at `e2e/results/bpftrace_authoritative_20260331.json:2996` | `3` at `e2e/results/bpftrace_authoritative_20260331.json:2396` | Already matched. |
| bpftrace | `tcpretrans` | 1 | `1` at `e2e/results/bpftrace_authoritative_20260331.json:3572` | `1` at `e2e/results/bpftrace_authoritative_20260331.json:3300` | Already matched. |
| bpftrace | `capable` | 1 | `1` at `e2e/results/bpftrace_authoritative_20260331.json:4050` | `1` at `e2e/results/bpftrace_authoritative_20260331.json:3814` | Already matched. |
| bcc | `tcplife` | 1 | `1` at `e2e/results/bcc_authoritative_20260403.json:1719` | `1` at `e2e/results/bcc_authoritative_20260403.json:1267` | Already matched. |
| bcc | `runqlat` | 3 | `3` at `e2e/results/bcc_authoritative_20260403.json:5696` | `3` at `e2e/results/bcc_authoritative_20260403.json:4547` | Already matched. |
| bcc | `syscount` | 2 | `2` at `e2e/results/bcc_authoritative_20260403.json:7046` | `2` at `e2e/results/bcc_authoritative_20260403.json:6212` | Already matched. |
| bcc | `execsnoop` | 2 | `2` at `e2e/results/bcc_authoritative_20260403.json:8410` | `2` at `e2e/results/bcc_authoritative_20260403.json:7526` | Already matched. |

No current `bpftrace` script or BCC tool in the checked-in static configs was missing authoritative data.

## Files Changed

- `runner/libs/app_runners/bpftrace.py`
- `e2e/cases/bcc/config.yaml`

## Validation

- `python3 -m py_compile runner/libs/app_runners/bpftrace.py`
  - OK
- `make check`
  - OK (exit 0)
  - Observed output included the repo `py_compile` check and the target completed successfully.
