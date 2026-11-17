# Probe-read empty remainder (2026-11-17)

run.sh rebuilds the one image with the linker change in 0dcf97880 and times OTel, BCC and Tracee; summary.txt holds the table, compared with run2 in ../probe-tails-20261117/summary-o3.txt. Raw: /workspaces/kprog-raw/zero-remainder-20261117.

## Result (image eb4d9a3e, stats on, 3 x 60 s)

| App | Per call, run2 → empty remainder | Throughput, run2 → empty remainder |
|---|---|---|
| OTel | 1.098x → **1.174x** | 1.077x → 1.202x |
| BCC | 1.013x → 1.016x | 0.998x → 1.025x |
| Tracee | 1.145x → **1.154x** (second run) | 1.058x → 1.098x (second run) |

- OTel native per call 2926 → 2874 ns; its eBPF arm measured 3375 ns against 3213 ns in run2, so part of the ratio
  change comes from the eBPF arm.
- Tracee's first run (053609_920585) has one native sample at 204 491 (per-sample 1.122 / 0.600 / 0.933, per call
  0.977x); tracee2.sh repeated it on the same image: per-sample 1.095 / 1.079 / 1.101, 24 of 24 active programs track.
- Equal-work per-call geomean with Tetragon and Katran from run2: 1.095x.
