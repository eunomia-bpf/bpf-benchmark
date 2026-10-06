# Rotate Capture Fix - 2026-05-06

## Diagnosis

The completed Cilium capture run did not execute the previous wrapper. Every
recorded rotate command was the plain `timeout 600 bpfopt --pass rotate ...`
form, so `BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS` was either absent when runner
Python built the plan or the runtime image did not contain the wrapper patch.
That run also had no `details/failure-artifacts/` directory, which means even a
daemon failure would not have been persisted to the host.

Source tracing showed the old env path was fragile for this job:

- `BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS` was an unrecorded env side channel.
- `runner/libs/rejit_plan.py` used it to mutate every pass command.
- Host export still separately required `--keep-failure-artifacts`.
- The daemon only returns `workdir_tar_b64` when a program or pass fails; the
  success path does not preserve workdirs.

Because success workdir export is not available without daemon changes, runner
Python still has to use the existing failure-artifact tar path for this
diagnostic capture.

## Fix

Replaced the env hook with an explicit corpus runner flag:

```text
--capture-pass-input PASS
```

When set, the corpus driver selects the smallest live program by positive
`bytes_xlated`, asks `runner.libs.rejit_plan` to wrap only that program's
matching pass, and automatically enables the existing failure-artifact output
directory. The wrapped command copies the daemon-fed `${INPUT}` to:

```text
${WORKDIR}/captured-input-<pass>.bin
```

It then runs the real `bpfopt` command and finally checks for a deliberately
absent marker file under the same fresh daemon workdir. That check makes only
the selected step fail, so the daemon returns the existing workdir tar without
changing daemon or kernel code. The old `&& false` path and the stale
`BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS` passthrough were deleted.

For the Cilium rotate capture run, use the existing app/pass filters plus the
new flag, for example:

```text
BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_BENCH_PASSES=rotate \
  make vm-corpus VM_CORPUS_SUITE_ARGS='--capture-pass-input rotate'
```

Expected host artifact:

```text
corpus/results/<run>/details/failure-artifacts/<prog_id>.tar.gz
```

Extract that tar and use `captured-input-rotate.bin` for offline `bpfopt
--pass rotate` analysis.

## Validation

- Default plan generation has no capture wrapper.
- Capture plan generation wraps only the requested program and pass.
- The wrapper uses `test -e ${WORKDIR}/bpfrejit-capture-export-trigger-<pass>`
  and does not contain `&& false`.
- The suite entrypoint forwards `--capture-pass-input` to `corpus/driver.py`.
- Capture selection fails fast if program metadata lacks positive
  `bytes_xlated`.
