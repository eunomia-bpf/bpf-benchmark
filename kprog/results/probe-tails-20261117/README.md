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
