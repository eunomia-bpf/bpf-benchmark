# Actual Katran on the ARM trusted service

This replay uses the unchanged corpus KatranRunner, full DSR topology, upstream Katran server, and xdp_pktgen workload. The current shim, ARM trusted loader and common service use REQUIRE_BOUND_PROOF=1; legacy REQUIRE_PREBUILT_PROOF=1 must still result in fresh kernel-owned generation. Success requires successful service receipts and an increase in bound native program execution counters during the workload. Raw program counts, packet-generator output, outcome maps and receiver counters are retained for same-work interpretation; QEMU timing is functional only.

The first two completed attempts stopped before application startup:

- The matching stock module tree had veth.ko but no modules.dep, because host-kernel-arm64 installs with DEPMOD=true. The replay now runs depmod against that exact existing tree. No kernel/module rebuild or copy was needed.
- The existing NAPI/YNL setup then required BPFREJIT_REMOTE_PYTHON_BIN. The replay now supplies python3, matching the corpus runtime contract.

Each bootstrap failure and its complete compressed guest log is retained. The retry after both fixes reached the actual balancer_ingress load (source program 14, XDP expected_attach_type 37), then the common service rejected GET_MAP with ENOENT before generation. No proof was compiled, no native application was attached, and no workload ran. This is a submitted map-membership failure, not a verifier rejection.

The capsule contains 17 map aliases. Fresh native-link relocation inspection references only 14: decap_vip_stats (map 16), stable_rt_stats (15) and tpr_stats_map (18) are absent from the reachable native proof. They are also absent from the source entry's ELF relocation list (the latter is an entry-only inspection, not a full source subprogram closure). The raw kernel request/error and exact alias list are retained in map-query-failure.json and the compressed run archive. The exact failing GET_MAP identity was not logged, so the three extras are a static diagnosis, not a runtime identity observation. T/C own the capsule/map-membership correction; no source-membership bypass or retry with unchanged inputs was introduced.

```
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-katran-arm64-build
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-katran-arm64-run
```

Builds reuse the canonical shared ARM shim/loader/native-link caches. The VM uses the retained v35 root read-only, the newly built canonical Image/module, and the matched installed stock modules. It has eight vCPUs because the unchanged corpus recipe uses guest CPUs 5 and 6; the host process is pinned to CPUs 20-23. Temporary run state is archived and deleted automatically.
