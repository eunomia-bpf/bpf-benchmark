# Pass Split Analysis

Date: `2026-03-31`

This report compares three benchmark configurations:

1. `A_full_kop`: full legacy pass set with kop enabled
2. `B_trio_kop`: `map_inline,const_prop,dce` with kop enabled
3. `C_trio_no_kop`: `map_inline,const_prop,dce` with kop disabled

The `--no-kop` path was fixed before running `C`, and the run metadata confirms `kop_enabled=false` with no attached kop metadata.

## Artifact Directories

- `A_full_kop`
  - `corpus/results/vm_corpus_20260331_142235`
  - `e2e/results/tracee_20260331_142809`
  - `e2e/results/tetragon_20260331_143749`
  - `e2e/results/bpftrace_20260331_143903`
  - `e2e/results/scx_20260331_144536`
  - `e2e/results/bcc_20260331_144654`
  - `e2e/results/katran_20260331_145740`
- `B_trio_kop`
  - `corpus/results/vm_corpus_20260331_165110`
  - `e2e/results/tracee_20260331_165528`
  - `e2e/results/tetragon_20260331_170510`
  - `e2e/results/bpftrace_20260331_170625`
  - `e2e/results/scx_20260331_171259`
  - `e2e/results/bcc_20260331_171418`
  - `e2e/results/katran_20260331_172503`
- `C_trio_no_kop`
  - `corpus/results/vm_corpus_20260331_172734`
  - `e2e/results/tracee_20260331_173203`
  - `e2e/results/tetragon_20260331_174143`
  - `e2e/results/bpftrace_20260331_174258`
  - `e2e/results/scx_20260331_174932`
  - `e2e/results/bcc_20260331_175051`
  - `e2e/results/katran_20260331_180136`

Top-level `vm_corpus.json` and `*_authoritative_20260331.json` files were restored to the default `B_trio_kop` artifacts after the experimental runs.

## Summary Matrix

| Metric | A_full_kop | B_trio_kop | C_trio_no_kop |
| --- | ---: | ---: | ---: |
| corpus geomean | 1.0051 | 0.9844 | 0.9489 |
| tracee app throughput ratio | 0.9415 | 0.9552 | 0.9678 |
| tracee BPF speedup | 0.9548 | 0.9763 | 0.9786 |
| tetragon app throughput ratio | 0.6200 | 0.6324 | 0.7165 |
| tetragon BPF speedup | 1.0157 | 0.9387 | 1.1141 |
| bpftrace geomean | 1.0444 | 1.0871 | 1.1292 |
| scx throughput ratio | 0.9951 | 0.9951 | 1.0075 |
| bcc geomean | 0.9984 | 0.9881 | 1.0121 |
| katran workload ratio | 1.0039 | 1.0015 | 0.9951 |
| katran BPF speedup | 1.0077 | 0.9981 | 0.9831 |

Interpretation:

- The corpus suite does not like `no-kop`; `C` is the worst overall corpus result.
- Live E2E workloads mostly improve when kop is removed from the daemon session.
- Katran is the main E2E holdout for `no-kop`.
- The old full pass set is not clearly dominant anywhere and remains particularly bad for tracee/tetragon app throughput.

## Corpus B vs C

Largest regressions from `B_trio_kop -> C_trio_no_kop`:

- `bpftrace/tcpretrans`: `1.4340 -> 0.7822`
- `bcc/tcpconnect`: `0.9036 -> 0.7311`
- `tetragon/default`: `1.1288 -> 0.9777`
- `bpftrace/vfsstat`: `1.0867 -> 0.9576`
- `bcc/capable`: `1.1007 -> 0.9848`

Largest improvements from `B_trio_kop -> C_trio_no_kop`:

- `bcc/biosnoop`: `0.8229 -> 1.0351`
- `bcc/bindsnoop`: `0.8805 -> 1.0549`
- `bpftrace/tcplife`: `0.8001 -> 0.8562`
- `bcc/tcplife`: `0.9297 -> 0.9773`
- `scx/rusty`: `0.9992 -> 1.0400`

## Current Recommendation

- Keep the default benchmark profile at `map_inline,const_prop,dce`.
- Keep kop enabled for the default corpus and authoritative result publication.
- Treat `no-kop` as an experimental axis, not the default, until the corpus regressions are understood.
- The next performance investigation should focus on:
  - `bpftrace/tcpretrans`
  - `bcc/tcpconnect`
  - `tetragon/default`
  - why live E2E improves under `no-kop` while corpus worsens

## Direct Answer: kop vs map_inline

Current data does not support either of these claims:

- "`kop` is simply bad"
- "`map_inline` has no value"

The stronger conclusions are:

- `kop` is not a safe universal default today.
  - Disabling it improves most live E2E app-level results.
  - Disabling it hurts corpus program-level results.
  - That means `kop` has a real effect, but the effect is directionally inconsistent across measurement modes.

- `map_inline` is clearly doing real work.
  - BCC and corpus runs still report substantial `map_inline/const_prop/dce` site counts.
  - Several workloads improve materially under the trio pipeline, so the pipeline is not a no-op.
  - The current issue is not "map_inline does nothing"; it is that the net effect of `map_inline -> const_prop -> dce` is workload-dependent and can regress specific programs.

- The current matrix does not isolate `map_inline` cleanly enough to blame it by itself.
  - We changed both pass selection and kop state.
  - To isolate root cause, we still need fixed-kop ablations:
    - `map_inline only`
    - `const_prop only`
    - `dce only`
    - `map_inline + const_prop`
    - `map_inline + const_prop + dce`
  - And fixed-pass `kop on/off` comparisons for the same exact workload set.
