# Current trusted loader tail-map registration regression

Replay 13 unchanged stage2 helper/map fixtures after common loader commit3d0e584b5.
Same native/source objects, producer, simulator, generator, native-link,
kernel and module as the preceding x86 run. Only the trusted loader binary
and common C++ source changed. Fresh output keeps old requests intact.
No build, workload change, timing or speedup claim. The completed results are recorded below.

## Completed result

All13 cases passed on the kernel JIT and fresh bound native path after
the common C++ loader tail-call-map registration integration. Every
64-bit result exactly matched its unchanged expected value; every retval
was2 and all cases had nonzero generations. `results.csv` records each
result/count. The guest Make exited0. All original26 fixture objects and
producer SHA, kernel-owned/generated native objects, request source pins
and host input hashes were checked. The current linker and trusted loader SHAs and all exact
source identities are in the summary. Historical requests remain separate.

`outcomes.json.gz` contains full raw per-case outputs and request records.
`run-post-tail-map.tar.gz` retains all13 trusted request archives, raw
service/guest logs and inputs. This is functional correctness evidence,
with no throughput or speedup claim. No kernel/module/image/workload was
rebuilt or changed for this replay.
