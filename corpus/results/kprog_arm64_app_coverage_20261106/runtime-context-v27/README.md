# Actual BCC generation-bound startup, runtime v27

The unchanged BCC workload was attempted under full-system AArch64 QEMU with
REQUIRE_BOUND_PROOF=1. All 23 current proof candidates compile. The runtime
manifest retains 32 selectors, including nine previously captured startup
selectors. No application program is filtered.

The baseline has 23 resident program counter rows. Native startup logs 14 bound
replacements and five native-load failures; the application exits with tcplife
rc 97 and records no native workload counter rows. This is an unsuccessful
application run. The driver exit 0 does not change its recorded app status.

| Failure | Observed cause |
| --- | --- |
| vfsstat fentry_vfs_read | Exclusive retry loop rejected as infinite |
| tcplife inet_sock_set_state | Stack write at -520 rejected; compiled maximum offset 584 |
| opensnoop sys_exit_openat | EINVAL; retained verifier tail ends in exit without a precise cause |
| syscount sys_exit | Exclusive retry loop rejected as infinite |
| runqlat sched_switch | Exclusive retry loop rejected as infinite |

Opensnoop's compiled maximum stack offset is 472, down from 880, but its actual
load still fails. Its cause is being investigated rather than called accepted.
The two native arms did not complete the same work because native measurement
was not reached. QEMU timings are functional only.

Raw startup requests, native replacements, per-program resident counters,
application stdout/stderr/errors, and the complete runner directory are
retained. exact-bcc-runtime-payload.tar.gz preserves all 32 manifest entries and
their native/proof payloads; runtime-identity.json pins the built image/kernel.
The frozen compiler sources/checks are in ../stack-layout-result/.

Run the same existing target sequence with the built lane runtime:

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile qemu-context-v2-app RUNTIME_BASE=/workspaces/repository/kprog/arm64/build/app-runtime-v27 RUNTIME_IMAGE=bpf-benchmark/runner-runtime:arm64-a-context-v27 APP=bcc/set
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile app-replay-build RUNTIME_BASE=/workspaces/repository/kprog/arm64/build/app-runtime-v27 RUNTIME_IMAGE=bpf-benchmark/runner-runtime:arm64-a-context-v27
```

Spark preparation completed; the app errors above remain open on QEMU and are
not claimed fixed on hardware. General hardware instructions remain in
../DGX-SPARK.md.
