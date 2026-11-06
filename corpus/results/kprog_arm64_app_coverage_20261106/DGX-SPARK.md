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

The requested six-app workload replay is not ready yet. The app shim's C
entrypoint does not provide `FdLoadOptions.proof_insns`, and the artifact scan
still uses XDP ABI and synthetic map declarations rather than the application
program's context and live maps. T owns the proof/binding API; A owns the
AArch64 app proof generation/integration and remaining compile failures. A
`.proof.o` native-link input is insufficient to enable that path. No existing
`make corpus` command can honestly be presented as six-app verified execution
at this checkpoint. The app runtime image and bound app proof lookup must be
built before that command sequence can replace this diagnostic replay.
