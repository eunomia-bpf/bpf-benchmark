# katran source-opt attempt: phase3-quic-hot-branch-layout

- Time: 2026-06-26 06:16
- App: `katran`
- Status: completed-not-stacked
- Source files: `vendor/repos/katran/katran/lib/bpf/balancer.c`, `vendor/repos/katran/katran/lib/bpf/pckt_parsing.h`
- Base: phase3 attempt 4, `phase3-vip-flag-branch-layout`
- Result path: `corpus/results/x86_kvm_corpus_20260626_132449_671728`

## Hypothesis

The Katran pktgen workload sends UDP traffic to a QUIC-enabled VIP, but pktgen does not construct a real QUIC or stable-routing payload. Marking QUIC server-id success and stable-routing header parsing as cold could make the fallback-to-CH path cheaper without changing parser semantics.

## Expected Hot Path

`process_packet()` enters the QUIC VIP branch, parses a UDP payload without a useful server id, increments `ch_routed`, skips stable-routing header handling, and later routes through LRU/global LRU/CH.

## Correctness Argument

The patch only wraps existing conditions in `__builtin_expect()`. It does not change packet parsing bounds, returned parse values, map definitions, stats keys, routing decisions, actions, or workload parameters.

## Build Command

```sh
make -C vendor katran-x86
```

## Run Command

```sh
SKIP_REJIT=all \
BPFREJIT_CORPUS_APPS='katran' \
BPFREJIT_CORPUS_BPF_STATS=0 \
SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1 \
BPFREJIT_CORPUS_APP_TIMEOUT=3600 \
BPFREJIT_CORPUS_REJIT_TIMEOUT=1200 \
TIMEOUT=7200 KEEP_WORKDIRS=1 \
make corpus
```

## Result

```text
sample=1 pktgen_total_pps=3275164 errors=230435316
sample=2 pktgen_total_pps=3299603 errors=212431597
sample=3 pktgen_total_pps=3258040 errors=227310255
mean_pktgen_total_pps=3277602
vs_clean_baseline=+7.0702%
vs_phase3_attempt4=-4.0027%
```

Follow-up: do not stack. The best katran phase3 base remains `phase3-vip-flag-branch-layout`.
