# Actual Katran on the ARM trusted service

This replay uses the unchanged corpus KatranRunner, full DSR topology, upstream Katran server, and xdp_pktgen workload. The current shim, ARM trusted loader and common service use REQUIRE_BOUND_PROOF=1; legacy REQUIRE_PREBUILT_PROOF=1 must still result in fresh kernel-owned generation. Success requires successful service receipts and an increase in bound native program execution counters during the workload. Raw program counts, packet-generator output, outcome maps and receiver counters are retained for same-work interpretation; QEMU timing is functional only.

The first two completed attempts stopped before application startup:

- The matching stock module tree had veth.ko but no modules.dep, because host-kernel-arm64 installs with DEPMOD=true. The replay now runs depmod against that exact existing tree. No kernel/module rebuild or copy was needed.
- The existing NAPI/YNL setup then required BPFREJIT_REMOTE_PYTHON_BIN. The replay now supplies python3, matching the corpus runtime contract.

Each bootstrap failure and its complete compressed guest log is retained. The retry after both fixes is tracked by summary.json when it finishes; no Katran verifier/application acceptance is claimed by these bootstrap records.

```
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-katran-arm64-build
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-katran-arm64-run
```

Builds reuse the canonical shared ARM shim/loader/native-link caches. The VM uses the retained v35 root read-only, the newly built canonical Image/module, and the matched installed stock modules. It has eight vCPUs because the unchanged corpus recipe uses guest CPUs 5 and 6; the host process is pinned to CPUs 20-23. Temporary run state is archived and deleted automatically.
