# Diagnostics

## Base

Base patch was phase3 attempt 4, `phase3-vip-flag-branch-layout`.

```text
xdp size: 0x4890
.relxdp size: 0x450
```

## Candidate

The candidate keeps phase3 attempt 4 and adds parser fallback branch hints:

- `qpr.server_id > 0` expected cold for the pktgen UDP payload.
- `!qpr.is_initial` expected hot after no server id.
- QUIC long-header parsing expected cold for pktgen payload.
- stable-routing header parsing expected cold for pktgen payload.

The formal run used the full stacked `source.diff`, not a delta-only patch.

```text
xdp size: 0x4890
.relxdp size: 0x450
sha256: 29d8e8fd847b0edaff8f15aed0de0f0731cc4667f7c42aca6cd00406cdc26b97
```

The candidate kept the same `xdp` section size as phase3 attempt 4 and reduced objdump line count from 2856 to 2852, but performance regressed.

## Formal Result

Result path: `corpus/results/x86_kvm_corpus_20260626_132449_671728`

```text
sample=1 pktgen_total_pps=3275164 errors=230435316
sample=2 pktgen_total_pps=3299603 errors=212431597
sample=3 pktgen_total_pps=3258040 errors=227310255
mean_pktgen_total_pps=3277602
errors_total=670177168
vs_clean_baseline=+7.0702%
vs_phase3_attempt4=-4.0027%
```

Decision: `completed-not-stacked`. Parser fallback hints are not a good continuation direction for katran under this workload; keep phase3 attempt 4 as the current katran best.
