# Probe-read remainder in 4-, 2- and 1-byte steps

Coordinator 2026-11-17 (operator: "LTO 那边反而需要更关注? 代码让 codex 去 review 一下看看有没有性能问题, 你来整改";
PERF review kprog/results/lto-review-20261117 item 1). `x86_probe_read.rs` copied the part of a read below 8 bytes one
byte at a time, each byte with its own fault-status test; the kernel's mm/maccess.c copies with 8-, 4-, 2- and 1-byte
pieces. The routine now finishes the remainder in at most one 4-, one 2- and one 1-byte load. Every source load is a
recorded load site whose EX_TYPE_BPF recovery clears R11, followed by the same status test; a fault still zeroes the whole
destination. Host execution: kernel reads 1,147 vectors and user reads 1,149 vectors, 121 exact-site faults each,
all 40 linker tests pass. `run.sh` rebuilds the image, runs the check and times five apps (stats on, 3 x 60 s) for
comparison with kprog/results/flag-tuning-20261117/1-O3.txt (same flags, previous code).
