# arm64 frozen-entry run 6 on the DGX Spark pair under KVM, 2026-11-23T19:43Z – 22:15Z

Code: bpf-benchmark 30e401e37 (LPM tries call `trie_lookup_elem`, 77908203a; a lookup on an inner map takes the
outer map's inner-template form). Guest image checked in the Workspace 2026-11-23 18:35–19:36Z: six applications
rc=0, every running program native (OTel 13, BCC 23, Cilium 105, Tetragon 93, Tracee 82, Katran 1). Same harness
as run 5 (kprog/results/arm64-spark-run5-20261123): `spark-rotate.sh` in `kprog-qemu-arm64:24.04`,
`--cpuset-cpus 15-19` (Cortex-X925), 4 vCPU / 8 GiB, Image md5 4888c1c4; `spark-9773` OTel, BCC, Cilium;
`spark-d5fe` Tetragon, Tracee, Katran; 3 x 180 s per arm, stats off then on. Every run rc=0 with three samples per
arm. DeepSeek paused 11-23 19:40Z – 11-24 03:3xZ (spark-manage a09665b2, f4f26bc7).

| App | Per call, stats on | Throughput, stats off | Throughput, stats on | Run 5, dcf4a1aef (per call / off / on) |
|---|---|---|---|---|
| OTel | 1.017x (eBPF 261.8 ns, native 257.5 ns) | 1.016x (1.014, 1.027, 0.992) | 0.990x (0.987, 0.989, 1.001) | 1.004x / 1.013x / 0.988x |
| BCC | 0.938x (93.0 / 99.2 ns) | 0.980x (0.979, 1.008, 0.980) | 0.988x (0.988, 0.912, 1.034) | 0.952x / 1.011x / 0.927x |
| Cilium | 1.017x (995.3 / 978.7 ns) | 1.050x (1.056, 1.046, 1.053) | 1.091x (1.078, 1.100, 1.095) | 1.015x / 1.084x / 1.061x |
| Tetragon | 1.384x (446.8 / 322.7 ns) | 1.222x (1.324, 1.200, 1.210) | 1.181x (1.081, 1.203, 1.106) | 1.384x / 1.237x / 1.171x |
| Tracee | 1.534x (332.9 / 217.0 ns) | 1.404x (1.409, 1.370, 1.397) | 1.233x (1.250, 1.209, 1.226) | 1.585x / 1.398x / 1.283x |
| Katran | 0.932x (162.8 / 174.6 ns) | 0.991x (0.989, 0.991, 0.993) | 0.823x (0.823, 0.914, 0.810) | 0.957x / 1.008x / 0.991x |

Geomean over six: per call 1.115x (run 5 1.126x), throughput stats off 1.101x (run 5 1.116x).

Native code loaded into the kernel, run 6 against run 5 (post-rejit bytes_jited, stats-off runs): OTel and BCC are
byte-identical, so their differences are run-to-run spread. Tetragon: 35 programs each 8 bytes longer (an inner-map
lookup in its direct form). Tracee: 12 programs 88–200 bytes longer. Katran: 9848 -> 9864 bytes (two inner-map
lookups in their direct form). Cilium: the stats-off capture loads 71 native programs (run 5: 64).

Katran's packet generator reports errors in both arms (69 in the stats-off run, 7.86e9 in the stats-on run).

Raw results: /workspaces/kprog-raw/arm64-spark-run6/{spark-9773,spark-d5fe}/ (run directories as the guest wrote
them under workspaces/repository/corpus/results/, and each Spark's progress.log). Run 7 (same root and Image)
times Cilium, BCC, Katran and Tetragon again from 2026-11-24T03:44Z.
