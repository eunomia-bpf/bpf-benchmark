# Helper/map correctness after map-alias linker integration

Replay the same13 micro_stage2 native/source objects and same bound producer
through the current native-only trusted service/linker. All26 object hashes
and producer SHA match the preceding post-context run. Fresh RUN_OUT keeps
all historical requests unchanged. No kernel/module/image/source rebuild,
no workload change and no timing claim. The completed results are recorded below.

```sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/helper-map/x86-trusted-service/Makefile kvm RUN_OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/helper-map/x86-trusted-service/post-map-alias
```

## Completed result

All13 cases passed on the kernel JIT and fresh bound native path. Every
64-bit result exactly matched its unchanged expected value; every retval
was2 and all cases had nonzero generations. `results.csv` records each
result/count. The guest Make exited0. All original26 fixture objects and
producer SHA, kernel-owned/generated native objects, request source pins
and host input hashes were checked. The current linker SHA and all exact
source identities are in the summary. Historical requests remain separate.

`outcomes.json.gz` contains full raw per-case outputs and request records.
`run-post-map-alias.tar.gz` retains all13 trusted request archives, raw
service/guest logs and inputs. This is functional correctness evidence,
with no throughput or speedup claim. No kernel/module/image/workload was
rebuilt or changed for this replay.
