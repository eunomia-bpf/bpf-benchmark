# arm64 frozen-entry run 7 on the DGX Spark pair under KVM, 2026-11-24T03:44Z – 05:25Z

Operator 2026-11-24 03:2x UTC: "你要想办法每个程序确保用到最好的版本, 比如说这样的性能. 代码要是这样的."; 03:3x UTC:
"arm 上面也得跑". Run 6 (kprog/results/arm64-spark-run6-20261124) measured BCC, Cilium and Katran below run 5
(dcf4a1aef); this run times them again, with Tetragon, on the same root and Image (30e401e37, Image md5 4888c1c4):
`spark-9773` Cilium, BCC; `spark-d5fe` Katran, Tetragon; 3 x 180 s per arm, stats off then on. Every run rc=0 with
three samples per arm. DeepSeek paused 03:44–05:2xZ (spark-manage 00020caf, 67658198).

| App | Per call, stats on | Throughput, stats off | Throughput, stats on | Run 6 (30e401e37) | Run 5 (dcf4a1aef) |
|---|---|---|---|---|---|
| Cilium | 1.035x (eBPF 1012.3 ns, native 978.2 ns) | 1.124x (1.131, 1.142, 1.075) | 1.098x (1.093, 1.095, 1.121) | 1.017x / 1.050x / 1.091x | 1.015x / 1.084x / 1.061x |
| BCC | 0.956x (93.2 / 97.5 ns) | 1.071x (1.004, 1.074, 1.059) | 0.940x (0.940, 0.897, 0.976) | 0.938x / 0.980x / 0.988x | 0.952x / 1.011x / 0.927x |
| Katran | 0.954x (164.5 / 172.4 ns) | 1.001x (0.994, 1.011, 1.007) | 0.923x (1.182, 0.923, 0.903) | 0.932x / 0.991x / 0.823x | 0.957x / 1.008x / 0.991x |
| Tetragon | 1.400x (450.4 / 321.7 ns) | 1.245x (1.164, 1.245, 1.285) | 1.130x (1.162, 1.130, 1.137) | 1.384x / 1.222x / 1.181x | 1.384x / 1.237x / 1.171x |

On 30e401e37, Cilium and Tetragon measure above their run-5 values on per call and stats-off throughput. BCC's
native code is byte-identical in runs 5, 6 and 7; its three runs span 0.938–0.956x per call and 0.980–1.071x stats
off. Katran's three runs span 0.932–0.957x per call and 0.991–1.008x stats off; its packet generator reports
errors in both arms (7.35e9 stats off, 8.23e9 stats on in this run).

Raw results: /workspaces/kprog-raw/arm64-spark-run7/{spark-9773,spark-d5fe}/.
