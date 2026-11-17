# User probe read as a leaf (2026-11-17)

run.sh rebuilds the one image with 6beae45cc, runs the one-image check and times OTel, BCC and Tracee; summary.txt holds the table, compared with ../zero-remainder-20261117. Host tests: 40 linker tests pass; the user routine passes 1149 host vectors and shrinks from 388 to 370 bytes; the kernel and kernel-string routines stay byte-identical. Raw: /workspaces/kprog-raw/leaf-read-20261117.

## Result (image f64641e3, stats on, 3 x 60 s)

One-image check: six apps rc=0; native replacements per app equal the previous image (OTel 14, BCC 25, Cilium 113,
Tetragon 288, Tracee 169, Katran 1) and the shim logs hold zero native-loader failures.

| App | Per call, empty remainder → user leaf | Native ns/call | eBPF ns/call | Throughput |
|---|---|---|---|---|
| OTel | 1.174x → 1.105x | 2873.8 → 2899.2 | 3375.0 → 3203.1 | 1.076x |
| BCC | 1.016x → 1.001x | 106.0 → 102.6 | 107.7 → 102.7 | 1.005x |
| Tracee | 1.154x → 1.118x | 317.0 → 328.8 | 365.7 → 367.5 | 1.068x |

- The eBPF arms moved back to their usual values (OTel 3203 ns, as in run2's 3213); native moved by +0.9 %, −3.2 % and
  +3.7 %, inside the run-to-run band, so the user leaf shows no separable per-call effect on these three apps.
- Installed native bytes: OTel 135 604 → 135 424, BCC 8 334 → 8 334, Tracee 1 700 836 → 1 700 692.
- Tracee's per-sample ratios span 1.032–1.096 (6.4 %). The image moved on to the kernel leaf at 07:02 ahead of a
  same-image repeat; the kernel-leaf image keeps the user routine byte-identical, so its Tracee run carries both steps.
