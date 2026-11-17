# One compile-flag set for every app

Coordinator 2026-11-17. Operator: "也得通过调优编译参数做到native 快 50%、代码量少一半. 必须要确保这样, 硬性要求",
"编译参数所有 app 统一.", and "接下来你来做, 不要叫其他人, 你来负责清理好并且自己去调性能参数".

`tune.sh` rebuilds the one image with the frozen recipe for each candidate NATIVE_CFLAGS (set on the make command line,
the source tree unchanged), records executable bytes per app (`textsize.py`), then times OTel, BCC, Cilium, Tracee and
Katran through the frozen corpus entry with stats on (SAMPLES=3, WORKLOAD_DURATION=60: a tuning measurement; official
numbers stay 3 x 180 s). Ratios come from `may29_ratio.py` (the 05-29 parser) and installed bytes from `inst.py`.
Order: O3 (current), Os, O2. The CMOV-to-branch and no-unrolling candidates were dropped on the operator's word (2026-11-17 ~23:58 UTC: "没必要吧").
Lanes are stopped, so the host is quiet. Each candidate's summary is committed as `<n>-<name>.txt` when it lands.

## Result (2026-11-17T02:59:47Z, coordinator)

| App | per call O3 / Os / O2 | throughput O3 / Os / O2 | staged exec bytes O3 / Os |
|---|---|---|---|
| OTel | 0.874 / 1.068 / 11.565 | 1.119 / 1.027 / 1.849 | 547,799 / 413,855 |
| BCC | 0.912 / load failed / 1.007 | 0.905 / - / 1.007 | 8,015 / 7,170 |
| Cilium | 3.243 / 3.361 / 2.864 | 3.012 / 3.036 / 2.785 | 275,918 / 260,932 |
| Tracee | 1.152 / load failed / 1.109 | 1.074 / - / 1.084 | 1,457,903 / 1,431,924 |
| Katran | 1.013 / 1.015 / 1.039 | 1.006 / 1.008 / 1.034 | 9,830 / 9,376 |

- BCC, Tracee and Katran move by at most about 4% per call across the three levels: within run-to-run spread.
- Os: Tracee's native load fails with "native data symbol .L.str.6 exceeds BPF data map value_size for .rodata.str1.1"
  (clang merges string constants differently, the native string pool outgrows the BPF .rodata map), the shim then
  returns EINVAL and the app exits; BCC's guest exits 255 after the baseline.
- O2: OTel per call 11.6x with the same invocation counts and installed size: the load-time PERF_EVENT context
  conversion most likely misses loads at O2 and the program exits early, the same class as the 05-29 1.849x. Unequal work.
- Cilium: the native objects are built with the sample config headers and CILIUM_MAX_* while the eBPF arm uses the
  agent's runtime config; its ratios are left out until the configs match.

Decision (coordinator): the one flag set stays -O3 for every app. Compile flags move per call by a few percent at most;
the operator's targets need the LTO work (operator 2026-11-17: "LTO 那边反而需要更关注?"). Os comes back as the
code-size candidate after the string-pool binding and the shim's link-failure path are fixed.

## Installed bytes, corrected 2026-11-17

inst.py now pairs each replacement's original and native jit-info lines by thread and keys the pair by native program
ID (perf review b6d0e9647: the name-keyed sums let later loads overwrite programs with the same truncated name).
O3 group, recomputed: OTel 0.80, BCC 1.00 (25 programs, 7 965 → 7 962 B), Cilium 0.83 (113), Tracee 0.82
(169 programs, 2 068 918 → 1 690 978 B), Katran 0.69. Per-call and throughput figures are unchanged.
