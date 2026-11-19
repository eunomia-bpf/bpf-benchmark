# Hand-written helper routines off: Workspace bpf-benchmark-lean (2026-11-18/19)

Operator 2026-11-18: "一边分析, 一边去一个新的 workspace 去把这些擦掉测试一下." Workspace yunwei356/bpf-benchmark-lean
(systems-dev, large-benchmark, node lab) was built from scratch at master 2bdb09335 with one local change (9e5d20b1d):
the linker receives no array, probe_read or LPM layout, so no hand-written helper routine is emitted and every
helper call in native code calls the kernel helper function, as the JIT does. Image 69e2e166, frozen entry
kprog/perf/one-image/Makefile corpus. Raw in that Workspace: /workspaces/kprog-raw/lean.

The comparison image is 3246e818 in bpf-benchmark-dev (all LTO, routines on; kprog/results/lto-all-20261118).
The lab node restarted at about 17:34 UTC on 11-18; the stats-on round ran after that, on a quiet node.
No reruns (operator 2026-11-19: "不要随便重跑").

Function: one-image check six apps rc=0; native replacements OTel 14, BCC 25, Cilium 113, Tetragon 288,
Tracee 169, Katran 1; native-loader failures 0.

| App | Per call (stats on), routines on -> off | Throughput (stats on) | Stats off, routines on -> off | Installed native/JIT |
|---|---|---|---|---|
| OTel | 0.986x -> 0.952x | 1.001x -> 1.062x | 0.950x -> 0.990x | 0.74 -> 0.70 |
| BCC | 1.019x -> 1.011x | 1.013x -> 0.997x | 0.954x -> 1.142x (samples 1.080 / 1.258 / 0.978) | 1.46 -> 0.77 |
| Cilium | 1.118x -> 1.278x | 1.049x -> 1.160x | 1.051x -> 0.945x (node load 15-17) | 0.78 -> 0.76 |
| Tetragon | 1.110x -> 1.027x | 1.062x -> 0.968x | 1.013x -> 1.010x | 0.79 -> 0.71 |
| Tracee | 1.369x -> 1.046x | 1.194x -> 1.035x | 1.332x -> 1.214x (node load 22) | 0.84 -> 0.76 |
| Katran | 1.049x -> 1.030x | 1.023x -> 1.024x | 1.065x -> run cut by the node restart | 0.68 -> 0.64 |

Reading: Cilium is faster without the hand-written map routines and fusion; Tracee and Tetragon lose the gain
that came from inlined probe reads; OTel, BCC and Katran are about the same. Code shrinks on every app.
Decision (coordinator): the routines stay deleted from master (07d9c4c96); probe reads and the other hot helpers
come back the way the design puts them, as C compiled with the specialized sim C in the LTO configuration.
