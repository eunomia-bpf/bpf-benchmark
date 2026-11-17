# Probe-read remainder in 4-, 2- and 1-byte steps

Coordinator 2026-11-17 (operator: "LTO 那边反而需要更关注? 代码让 codex 去 review 一下看看有没有性能问题, 你来整改";
PERF review kprog/results/lto-review-20261117 item 1). `x86_probe_read.rs` copied the part of a read below 8 bytes one
byte at a time, each byte with its own fault-status test; the kernel's mm/maccess.c copies with 8-, 4-, 2- and 1-byte
pieces. The routine now finishes the remainder in at most one 4-, one 2- and one 1-byte load. Every source load is a
recorded load site whose EX_TYPE_BPF recovery clears R11, followed by the same status test; a fault still zeroes the whole
destination. Host execution: kernel reads 1,147 vectors and user reads 1,149 vectors, 121 exact-site faults each,
all 40 linker tests pass. `run.sh` rebuilds the image, runs the check and times five apps (stats on, 3 x 60 s) for
comparison with kprog/results/flag-tuning-20261117/1-O3.txt (same flags, previous code).

## 2026-11-17T03:29Z: rerun at -O3 (run2.sh)

run.sh's image (03:04) carried the O2 group's P objects for OTel, BCC, Cilium, Tracee and Katran: NATIVE_CFLAGS sits
outside Make's prerequisites, and the stage executable bytes equal 3-O2.txt (Tetragon, rebuilt by its recipe every time,
equals 1-O3.txt). The coordinator stopped that series during its one-image check; its raw stays in
/workspaces/kprog-raw/probe-tails-20261117. run2.sh removes the native build outputs, rebuilds at -O3 and times all six
apps; its raw goes to /workspaces/kprog-raw/probe-tails-20261117/o3 and its table to summary-o3.txt. tetragon.sh is
folded into run2.sh.

## Result at -O3 (run2, 2026-11-17 03:59–05:02 UTC, stats on, 3 x 60 s)

Image 47ba298b; stage executable bytes equal 1-O3.txt for all six apps (7 440 157). One-image check: six apps rc=0.

| App | Per call, O3 group → run2 | Throughput, O3 group → run2 | Installed native / JIT |
|---|---|---|---|
| OTel | 0.874x → **1.098x** | 1.119x → 1.077x | 0.81 |
| BCC | 0.912x → **1.013x** | 0.905x → 0.998x | 1.08 |
| Cilium | 3.243x → 2.995x (arms compile different configs; set aside) | 3.012x → 2.800x | 0.83 |
| Tetragon | first timing → **1.098x** | first timing → 1.031x | 0.75 |
| Tracee | 1.152x → 1.145x | 1.074x → 1.058x | 0.86 |
| Katran | 1.013x → 1.040x | 1.006x → 1.014x | 0.69 |

- OTel: native_tracer_entry runs 0.996 times as often natively as in eBPF (0.826 in the O3 group); native 3726 → 2926 ns per call, eBPF 3255 → 3213 ns.
- BCC block_rq_complete and Tracee trace_ret_file_* differ in count (about 1 300 against 250 calls), small against each app's totals.
- Katran's "errors" figure from may29_ratio.py sums the third sample field, which holds about 1.6e8 per sample in both arms of both runs; the run reports ok.
- Equal-work per-call geomean over OTel, BCC, Tetragon, Tracee and Katran: 1.078x.
