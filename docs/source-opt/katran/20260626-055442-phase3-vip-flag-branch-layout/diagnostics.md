# Diagnostics

## Base

Base patch was phase3 attempt 3, `phase3-unlikely-hot-map-misses`.

```text
xdp size: 0x4858
.relxdp size: 0x450
```

## Candidate

The candidate keeps the phase3 attempt 3 source changes and adds branch layout hints for the benchmark's hot Katran VIP shape:

- `F_HASH_NO_SRC_PORT` expected cold.
- `F_QUIC_VIP` expected hot.
- UDP stable routing expected hot.
- local delivery and IPv6 real expected cold.

The formal run used the full stacked `source.diff`, not a delta-only patch.

```text
xdp size: 0x4890
.relxdp size: 0x450
sha256: e9cdc005a6dbb0d33fbe708a2aa936000e757ce2e5fcd3d67bed2cf7c17ca2e8
```

The candidate grew the `xdp` section by `0x38` bytes relative to phase3 attempt 3. Despite the size increase, branch layout improved the pktgen workload.

## Formal Result

Result path: `corpus/results/x86_kvm_corpus_20260626_130130_983141`

```text
sample=1 pktgen_total_pps=3406881 errors=265158411
sample=2 pktgen_total_pps=3418862 errors=264374245
sample=3 pktgen_total_pps=3417054 errors=264773447
mean_pktgen_total_pps=3414266
errors_total=794306103
vs_clean_baseline=+11.5346%
vs_phase3_attempt3=+1.9222%
```

Decision: `accepted-for-analysis`. This is the current katran source-opt best and should be used as the next katran phase3 base.
