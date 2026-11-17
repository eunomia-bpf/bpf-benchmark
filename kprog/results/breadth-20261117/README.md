# Breadth round on the current image (2026-11-17)

run.sh times all six apps one after another through the frozen corpus entry with its defaults (3 samples x 180 s, stats off) on image fc7c4707, to set each app beside its 2026-05-29 floor. summary.txt holds the throughput ratios and installed sizes; raw and hostload.log are in /workspaces/kprog-raw/breadth-20261117.

## Result (image fc7c4707, stats off, 3 x 180 s)

| App | Throughput native/eBPF | Per-sample | 05-29 floor |
|---|---|---|---|
| OTel | 1.053x | 1.053 / 1.084 / 1.044 | 1.849x (05-29 native read the wrong context and skipped unwinding) |
| BCC | 0.998x | 0.998 / 0.996 / 1.004 | 0.985x |
| Cilium | 2.819x | 3.277 / 2.622 / 2.797 | 1.319x; the arms compile different switches (native MONITOR_AGGREGATION, extra features), so set aside |
| Tetragon | 1.042x | 1.049 / 1.036 / 1.042 | 1.009x |
| Tracee | 0.886x | 0.719 / 0.880 / 0.945 | 0.948x |
| Katran | 1.086x | 0.754 / 1.101 / 1.237 | 1.113x |

Tracee and Katran each have one native sample far below the others while unlocked host work ran (omp's cargo test around
11:10-11:15 overlaps Tracee's first native sample); their spread exceeds 5 %, so rerun.sh times both again after the
ktime batch on its image, and every lane now runs CPU work under flock -s locks/timing.
