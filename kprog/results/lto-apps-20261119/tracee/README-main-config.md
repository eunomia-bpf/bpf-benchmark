# Tracee main configuration on image 3b5fa4b40, with the fp-arithmetic pass and the nofault bindings

Run `corpus/results/x86_kvm_corpus_20261121_022836_577758`, `APP=tracee/monitor`, frozen entry defaults
(3 samples x 180 s per arm, stats on, CPUs 0-7, 8 vCPUs, 64 GiB), on image 3b5fa4b40 with the base loader
rebuilt from HEAD and the base `packet-bounds` carrying the fp-arithmetic pass (2141a0e00) plus the two
`*_nofault` kernel-symbol bindings (8e0d92c7f). Started 02:28:36Z, finished 11:18:44Z.

## Coverage

| Arm | Replaced native | Failed | Kept on eBPF | Records / executed |
|---|---|---|---|---|
| baseline | 0 | 0 | 0 | 167 / 64 |
| post_rejit | **169** | **0** | **0** | 167 / 64 |

Every program the loader reached was replaced by its native image; the `current_task`/`cpu_number` GOT
failures of `a941b3539` are gone, as is the guest crash of `0c4e…`'s gs-load variant. Both arms recorded
the same 167 program records and the same 64 programs executed, so the program sets are identical.

## Numbers, with both arms' counts beside them

| Metric | Baseline arm | Native arm | Ratio |
|---|---|---|---|
| Per invocation (evaluation §5, 41 retained pairs) | — | — | **0.609 geomean** (median 0.659, 32/41 faster) = 1.64x |
| Pooled ns/inv (41/167 retained programs each) | 364.6 | 188.2 | 1.937x |
| Workload throughput (3 samples) | 342815 / 347113 / 346722 | 576681 / 580718 / 589599 | **1.675x** (per sample 1.682 / 1.673 / 1.700) |
| Calls in the stats window | 6,976,141,063 | 11,358,600,433 | 1.63x more calls in the native arm |

The two arms were run as the frozen entry runs them (one guest per arm, `skip_rejit` on the baseline), so
they are not the same guest process; the call totals differ by 1.63x because the native arm does more
workload per unit time at a fixed 180 s window. That is reported, and no figure here is withheld for it
(coordinator 2026-11-20T16:47:59Z: report the counts beside the number).

Reading: per call the native image is 1.64x faster over the programs the workload actually exercises, well
past the operator's 20% target for this app, and the app's own workload rate rises 1.675x. Against the
05-29 floor for Tracee (0.948x) this is far above it.

## Provenance

- Base: one base, `/workspaces/.agent-state/kprog-ck`; loader and compiler replaced in place, no second base.
- Image: `bpf-benchmark/kprog:current`, manifest `3b5fa4b40`.
- Entry: `kprog/results/lto-apps-20261119/Makefile` -> `kprog/results/lto-config-20261119/run_lto.sh`,
  3 samples x 180 s, stats on.
- Frozen benchmark framework and settings untouched; no command-line override of SAMPLES/STATS/DURATION.