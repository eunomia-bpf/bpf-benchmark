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

After the shared source-used-map projection and ARM extern correction, the next real run successfully queried all 14 pinned map facts and generated the native-link proof. Its guest clang was killed by the kernel OOM killer at 3,437,480 KiB anonymous RSS in the 4 GiB guest. The native request failed with service status -5; compilation returned -9, and the verifier was never invoked. The application reported no attached XDP program and no workload ran. `compiler-oom.json` and `run-20261107T095459034219Z.tar.gz` preserve the actual receipt, kernel OOM line and full request inputs/logs. All recorded input hashes stayed unchanged.

The next Katran replay uses 8 GiB guest RAM, within the lane limit, with the same eight guest vCPUs and CPUs 20-23 on the host. This is a response to the observed compiler OOM; no compiler flag, native input, kernel policy or workload change was made. Updated ARM shim/loader binaries must be built incrementally before that replay.


## Completed 8 GiB replay

The 8 GiB replay completed compilation and reached the real generation-bound verifier. It rejected instruction 2, `*(u64 *)(r10 - 568) = r1`, with `invalid write to stack R10 off=-568 size=8`. All 14 kernel-pinned map facts and native linking succeeded. The service returned status -5, the Katran process exited before shim program readiness, and no application workload ran. This is a verifier stack-size rejection, not the earlier compiler OOM and not application coverage.

`summary.json` and `run-20261107T111747460800Z.tar.gz` retain the complete closed run: exact kernel/native inputs, generated C and BPF, compiler commands, verifier diagnostics, service/shim logs and the 14 map identities. The archive SHA256 is `804dcbd346c9468bd158e725eedf61ea6997dd8c0e864d5dff0bcc12f82b682e`. The kernel-owned native ELF matches the original and specializer input SHA256 `8e9d78758740ab2c38e085dcaac933d740d5a387b41f4df55813cba6c097a01c`. All monitored input hashes stayed unchanged; guest exit was 1 and QEMU exit was 0.

The initial command records host CPUs 20-23. Near the end, all live QEMU threads moved to the available lane CPUs 8-11; `run/host-affinity-migration.json` records the exact before/after affinities. This was a functional replay and supplies no performance result. The already queued compact-payload Katran replay started after this driver exited, using separate output state; its outcome remains pending here.
