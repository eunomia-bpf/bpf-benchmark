# Kernel probe reads as leaves (2026-11-17)

run.sh waits for the user-leaf batch, rebuilds the one image with ac7116e0d, runs the one-image check and times BCC, Tetragon and Tracee; summary.txt holds the table and hostload.log in raw records host load around each run. Host tests: 40 linker tests pass; kernel reads pass 1152 host vectors (122 exact-site faults: both sides of USER_PTR_MAX + PAGE_SIZE, the vsyscall page and the page below it, a non-canonical address, width zero), kernel strings 193; the user routine stays byte-identical; the kernel routine grows 317 -> 374 bytes with the policy inline and the call and ten push/pop gone. Raw: /workspaces/kprog-raw/kernel-leaf-20261117.

## Result (image c0ff0b4c, stats on, 3 x 60 s)

One-image check: six apps rc=0, native replacements unchanged per app, zero native-loader failures.

| App | Per call, user leaf → kernel leaf | Native ns/call | eBPF ns/call | Throughput |
|---|---|---|---|---|
| Tracee | 1.118x → **1.378x** | 328.8 → **266.5** | 367.5 → 367.2 | 1.068x → **1.221x** |
| Tracee, second run | **1.401x** | 307.7 | 431.0 | **1.255x** |
| Tetragon | 1.098x (run2) → 1.061x | 698.1 → 704.1 | 766.5 → 747.0 | 1.031x → 1.011x |
| BCC | 1.001x → 1.022x | 102.6 → 105.1 | 102.7 → 107.4 | 1.005x → 1.017x |

- Tracee calls bpf_probe_read_kernel directly; its native time falls 19 % once the reads stop calling the kernel's
  policy function and drop their frame. The repeat ran on a busier host (both arms 15–17 % slower) and keeps the ratio.
- Tetragon's native reads go through bpf_probe_read (compat, helper 4), which still called the kernel; the compat
  dispatcher (compat-read-20261117) routes them to the same leaves.
- BCC's per-call time is mostly ktime, perf_event_output and map updates; its reads are few.
- Installed native bytes: Tracee 1 700 692 → 1 716 880 (the leaves carry their policy inline), BCC 8 334 → 8 733,
  Tetragon 1 924 132.
- hostload.log in raw records load averages 6–14 around the runs.
