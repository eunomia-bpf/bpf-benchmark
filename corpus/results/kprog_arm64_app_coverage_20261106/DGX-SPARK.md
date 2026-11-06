# DGX Spark replay preparation

The portable verifier-load replay is built and has passed locally under
full-system QEMU TCG. It currently contains the first BCC label-proof artifact;
it does not run an application workload or establish generation-bound native
execution. Its kernel and guest userspace are packaged, so Spark does not need
the local supervisor's base initramfs or a repository workspace mount.

On this build host, from the repository root:

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile bundle PHASE=label-pilot
# Already exercised locally, with exit 0:
taskset -c 16-19 make -C kprog/arm64/build/app-coverage/label-pilot/replay run
```

Output: `kprog/arm64/build/app-coverage/label-pilot/replay.tar.gz`. This archive
contains the framework AArch64 kernel `Image`, a guest initramfs containing the
AArch64 loader, libraries and compiled BPF artifact, and a standalone Makefile.
The raw local replay logs are retained in `portable-replay/` next to this file.

Transfer the archive to a DGX Spark with `qemu-system-aarch64`, GNU make,
coreutils and writable `/dev/kvm` available. Set `SPARK` to its SSH host:

```sh
scp kprog/arm64/build/app-coverage/label-pilot/replay.tar.gz "$SPARK:replay.tar.gz"
```

Then, in a shell on Spark:

```sh
uname -m                  # must report aarch64
install -d kprog-arm64-replay
tar -xzf replay.tar.gz -C kprog-arm64-replay
cd kprog-arm64-replay
make run ACCEL=kvm CPU=host
```

Every loader outcome and verifier log is written under `results/`; the serial
console is `qemu.log`. The Makefile returns failure if any load fails, after
retaining every per-artifact outcome. Keep those files even for a failed run.
This is functional hardware replay; lane R owns performance measurement.

For a larger completed diagnostic batch, build the identical archive with
`PHASE=label-all` (or `PHASE=helper-ids`) and repeat the same transfer/run
sequence. The packaging command includes all successfully compiled artifacts
present at packaging time; pending or failed artifacts remain in the host
coverage table and are not counted as passed by the archive.

The requested six-app workload replay is not ready yet. T's new manifest
entrypoint accepts `simulator_object` and `simulator_program` and has passed
a helper-proof fixture. Its original-map fixture still returns `0xCCCCCCCC`
instead of the initialized value `2` at the 07:52 UTC checkpoint. A's app
artifacts still use the diagnostic XDP ABI and synthetic map declarations;
real app context/map generation and complete verifier coverage remain open.
A `.proof.o` native-link input is insufficient to enable verified execution.
No existing six-app manifest selects validated simulator artifacts with the
correct original maps and ABI, so no `make corpus` command can honestly be
presented as the requested verified six-app run yet. The real app runtime
image and matching proof manifests must be built before this diagnostic
replay can be replaced with application workload runs.

## Built application image replay, 2026-11-06

The preceding pilot description records the earlier checkpoint. The current
runtimev9 image contains all six upstream applications, their existing Python
runners and workloads, the kernel modules, loader/linker and current manifests.
Katran's root triple passes bound QEMU execution; the actual balancer proof
has compiled and is running through application startup. The previousv8
Katran/OTel runs retained one/twelve baseline counter rows and missing-proof
failures, now recorded in runtime-context-v8/. BCC's v7 retry reached63 bound replacements, then four native-load
errors and a measurement socket failure. These commands run and retain those
actual application outcomes while the remaining defects are repaired.

On the build host, prepare the portable launcher from the current built image:

```sh
BASE="$PWD/kprog/arm64/build/app-runtime-v9"
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile app-replay-build \
  RUNTIME_BASE="$BASE" RUNTIME_IMAGE=bpf-benchmark/runner-runtime:arm64-a-context-v9
scp -r "$BASE/spark" "$SPARK:kprog-arm64-app"
scp "$BASE/image.tar" "$SPARK:kprog-arm64-app/image.tar"
```

The transferred directory contains the built matching kernel, unchanged guest
init, exact existing launch environment and standalone Makefile. Docker loads
and exports the image layers on Spark; no host workspace is mounted. Spark
needs Docker, Python3, GNU make, QEMU AArch64 and access to KVM. In its shell:

```sh
cd kprog-arm64-app
sudo make run ACCEL=kvm CPU=host APP=katran SAMPLES=1 WORKLOAD_DURATION=2
```

Run every application through the same two-start workload. Preserve the make
status and serial log for each attempt, including failures:

```sh
install -d runs
for stats in 0 1; do
  for app in bcc/set otelcol-ebpf-profiler/profiling cilium/agent tetragon/observer katran tracee/monitor; do
    label=$(printf '%s' "$app" | tr / _)-stats$stats
    if sudo make run ACCEL=kvm CPU=host APP="$app" BPF_STATS="$stats" \
      SAMPLES=3 WORKLOAD_DURATION=30 >"runs/$label.make.log" 2>&1; then
      rc=0
    else
      rc=$?
    fi
    printf '%s\n' "$rc" >"runs/$label.rc"
    if test -f qemu.log; then cp qemu.log "runs/$label.qemu.log"; fi
  done
done
```

Raw driver results, lifecycle logs and per-phase program/work counters stay in
`root/workspaces/repository/corpus/results/`; host identity is `host.txt`.
Feature probes use the operator-requested unchanged load path. Every resident
native replacement still requires a generation-bound proof, and a failed
verified replacement remains an error. The portable image export/prepare was
exercised on this build host; actual Spark hardware execution has not occurred.
The four component replay archives for entry ABI, source maps, code dispatch
and exclusive outcomes also contain their built matching kernel/initrd and
accept `make -C runtime run ACCEL=kvm CPU=host` after extraction.
