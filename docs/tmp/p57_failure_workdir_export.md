# P57 Failure Workdir Export

## Context Audit

- KVM execution goes through `runner/libs/kvm_executor.py`. The guest script creates the suite result directory on the host-visible workspace path before starting Docker inside the VM.
- Runtime Docker command construction is in `runner/libs/suite_commands.py`. It bind-mounts only the active suite result root into the image workspace, for example `e2e/results` to `/home/yunwei37/workspace/bpf-benchmark/e2e/results`, plus system mounts such as `/sys`, `/sys/fs/bpf`, `/lib/modules`, and `/boot`.
- The e2e artifact run directory is created by `e2e/driver.py` after the runtime container starts. While a case is running, `metadata.json` contains `status: "running"` and process identity fields including `launcher_pid`; `details/` is the intended per-run detail directory.
- The daemon starts before the final per-run artifact directory is known, so a fixed daemon startup path cannot point directly at `e2e/results/<app_timestamp>/details/failures`.

## Chosen Design

Option A was implemented: the daemon writes failure workdirs directly into a host-visible mounted result directory. No cleanup-time `scp` or `docker cp` path is needed.

The daemon accepts:

- `BPFREJIT_DAEMON_FAILURE_ROOT`
- `BPFREJIT_DAEMON_FAILURE_LAYOUT`

Supported layouts:

- `direct`: write `<failure_root>/<prog_id>/...`. This is the default local mode and keeps `/var/lib/bpfrejit-daemon/failures` working when no runtime result mount is configured.
- `active-run-details`: treat the root as a suite result root or workspace root, find exactly one active `metadata.json` with `status: "running"` matching the daemon parent process when `launcher_pid` is available, and write `<run_dir>/details/failures/<prog_id>/...`.

Inside the runtime container, the Docker image entrypoint sets `BPFREJIT_DAEMON_FAILURE_ROOT` to the active suite result root when it can infer the suite from `python -m runner.suites.<suite>`. The daemon also has a runtime-container default: if `BPFREJIT_INSIDE_RUNTIME_CONTAINER=1` and no explicit failure root is present, it uses `BPFREJIT_IMAGE_WORKSPACE` with `active-run-details`, scanning the mounted `micro/results`, `corpus/results`, `e2e/results`, and `tests/results` roots.

## Fail-Fast Behavior

- Daemon startup validates the configured export root with a real create/write/remove probe before binding the socket.
- Each failure export validates the resolved `details/failures` directory with another write probe.
- `active-run-details` requires exactly one active run; zero or multiple active runs are errors.
- A duplicate `<prog_id>` failure directory in the same run is an error.
- Copy, stat, JSON parse, chmod, and write errors propagate into the daemon error message. There is no warning-and-continue path for export failures.

## Exported Files

The daemon preserves the raw failure workdir and normalizes the triage names required by the host result contract:

- `prog.bpf` from `prog.bin`
- `info.json` from `prog_info.json`
- `verifier.log`, preferring the nonempty final ReJIT verifier log when present
- `replay.sh` with bpfverify and bpfrejit replay commands

The intended host path is:

`e2e/results/<app_timestamp>/details/failures/<prog_id>/{prog.bpf,verifier.log,replay.sh,info.json}`

## Verification

- `cargo build --manifest-path daemon/Cargo.toml`
- `cargo clippy --manifest-path daemon/Cargo.toml -- -D warnings`
- `cargo test --manifest-path daemon/Cargo.toml`

KVM verification command:

`make vm-e2e SAMPLES=1 VM_E2E_SUITE_ARGS="--case tracee" PYTHON=/home/yunwei37/workspace/.venv/bin/python`

Host artifact proof from the tracee KVM run:

- Run directory: `e2e/results/tracee_20260429_200339_517479`
- Failure directory: `e2e/results/tracee_20260429_200339_517479/details/failures/20`
- Required files were present: `prog.bpf`, `info.json`, `replay.sh`, and `verifier.log`
- `verifier.log` size: `248868` bytes
- `verifier.log` begins with real verifier output:

```text
func#0 @0
Live regs before insn:
      0: .1........ (bf) r8 = r1
      1: ........8. (b7) r1 = 0
```

The file was readable directly on the host after the KVM/QEMU process that created the artifact exited:

`sed -n '1,60p' e2e/results/tracee_20260429_200339_517479/details/failures/20/verifier.log`
