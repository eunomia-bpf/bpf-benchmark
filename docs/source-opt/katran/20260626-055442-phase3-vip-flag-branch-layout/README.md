# katran source-opt attempt: phase3-vip-flag-branch-layout

- Time: 2026-06-26 05:54
- App: `katran`
- Status: accepted-for-analysis
- Source files: `vendor/repos/katran/katran/lib/bpf/balancer.c`
- Base: phase3 attempt 3, `phase3-unlikely-hot-map-misses`
- Result path: `corpus/results/x86_kvm_corpus_20260626_130130_983141`

## Hypothesis

The benchmark Katran VIP uses a stable hot path: QUIC VIP, UDP stable routing, IPv4 real, and no local delivery. Keeping phase3 attempt 3's metadata reuse and adding branch prediction hints around those existing feature checks can make the JIT layout favor the hot path without changing semantics.

## Expected Hot Path

`process_packet()` looks up the VIP, updates stats, handles QUIC CID routing, applies UDP stable routing, checks LRU/global LRU/CH, then encapsulates to an IPv4 real. The candidate marks expected-cold feature branches and map-miss paths as unlikely, and marks QUIC plus UDP stable routing as likely.

## Correctness Argument

The patch only wraps existing boolean conditions in `__builtin_expect()` and preserves phase3 attempt 3's local metadata reuse. It does not change map definitions, packet parsing bounds, packet actions, stats keys, tail-call routing, loaded program set, or workload parameters.

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
sample=1 pktgen_total_pps=3406881 errors=265158411
sample=2 pktgen_total_pps=3418862 errors=264374245
sample=3 pktgen_total_pps=3417054 errors=264773447
mean_pktgen_total_pps=3414266
vs_clean_baseline=+11.5346%
vs_phase3_attempt3=+1.9222%
```

Follow-up: stack this attempt as the current katran best base. The next attempt should look for a semantic-preserving reduction in repeated hot-path stats or map work, because this branch-layout-only patch already clears the 10% target.
