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
