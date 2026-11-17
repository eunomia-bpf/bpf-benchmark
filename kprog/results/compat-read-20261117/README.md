# Compat probe reads through the leaves (2026-11-17)

run.sh waits for the kernel-leaf Tracee repeat, rebuilds the one image with d6b4d335e, runs the one-image check and times Tetragon and Tracee; summary.txt holds the table, raw hostload.log records host load. Host tests: 40 linker tests pass; the compat dispatcher passes 9 host vectors (64-bit task above and below TASK_SIZE_MAX, TIF_ADDR32 below and above 0xffffe000, ADDR_LIMIT_3GB at 0xd0000000, kernel-leaf fault recovery); kernel and kernel-string leaves pass 1152 and 193 vectors and shrink by 8 bytes each without the width-zero branch; the user leaf stays byte-identical. Raw: /workspaces/kprog-raw/compat-read-20261117.

## Result (image fc7c4707, stats on, 3 x 60 s)

One-image check: six apps rc=0; native replacements per app unchanged (OTel 14, BCC 25, Cilium 113, Tetragon 288,
Tracee 169, Katran 1), zero native-loader failures, so the new task_flags and task_personality layout facts resolve in
the guest.

| App | Per call, kernel leaf → compat | Native ns/call | eBPF ns/call | Throughput |
|---|---|---|---|---|
| Tetragon | 1.061x → **1.113x** | 704.1 → 660.9 | 747.0 → 735.4 | 1.011x → 1.035x |
| Tracee | 1.378x / 1.401x → 1.373x | 266.5 / 307.7 → 267.7 | 367.2 / 431.0 → 367.4 | 1.221x / 1.255x → **1.281x** |

- Tetragon's native time falls 6.1 % once its bpf_probe_read calls reach the leaves.
- Installed native bytes: Tetragon 1 924 132 → 2 078 688 (each program now carries the dispatcher and both leaves),
  native / JIT 0.84; Tracee 1 716 880 → 1 761 243, 0.85.
- hostload.log in raw: load averages 5–12 around the runs (the guest holds eight CPUs).
