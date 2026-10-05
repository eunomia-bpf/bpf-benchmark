# BCC kheaders cache fix summary - 2026-04-18

Commit: `94da788053ef4085aaa7829ccbaee0420f76c85d`

## Disk usage

- Before cleanup: `262M docs/tmp/runtime-container-tmp`
- After one-shot cleanup of old `run.x86-kvm.e2e.*` / `run.x86-kvm.micro.*`: `4.0K docs/tmp/runtime-container-tmp`
- After cache creation and verification runs: `51M docs/tmp/runtime-container-tmp`

The final directory contains the shared cache at `docs/tmp/runtime-container-tmp/bcc-kheaders/7.0.0-rc2/`. The failed full KVM suite attempts also left small debug scratch dirs:

- `docs/tmp/runtime-container-tmp/run.x86-kvm.e2e.13eebd67/`
- `docs/tmp/runtime-container-tmp/run.x86-kvm.corpus.1bb566b1/`

Those were retained because the new cleanup hook only removes per-run scratch after successful top-level runs.

## Verification

- `python3 -m py_compile runner/libs/app_runners/bcc.py runner/libs/kvm_executor.py runner/libs/aws_executor.py runner/libs/suite_commands.py`: PASS
- `git diff --check`: PASS before commit
- `make vm-e2e E2E_CASE=bcc E2E_SMOKE=1`: PASS
- Repeated `make vm-e2e E2E_CASE=bcc E2E_SMOKE=1`: PASS

Cache checks:

- Shared cache path exists: `docs/tmp/runtime-container-tmp/bcc-kheaders/7.0.0-rc2/`
- Representative header exists: `docs/tmp/runtime-container-tmp/bcc-kheaders/7.0.0-rc2/include/uapi/linux/pps_gen.h`
- Ready marker timestamp before and after the second smoke run stayed `1776501819`, confirming reuse.
- No `run.*` scratch directory remained after either successful BCC smoke run.

## Re-dispatched suites

- `make vm-e2e`: FAIL, Tracee case failed before suite success.
  - Failure: `/artifacts/tracee/bin/tracee` could not load `libelf.so.1` and `libz.so.1`.
  - BPFTrace, SCX, BCC, Katran, and Tetragon completed OK in this run.
- `make vm-corpus`: FAIL.
  - BCC corpus apps completed OK.
  - Tracee failed with the same missing `libelf.so.1` / `libz.so.1` runtime image issue.
  - BPFTrace `vfsstat`, `runqlat`, and `tcpretrans` failed while extracting kheaders because `tar` attempted ownership changes on the mounted runtime tmpdir.
  - SCX, Tetragon, Katran, and the other observed BPFTrace apps completed OK.

AWS x86 and AWS arm64 suites were not attempted after the KVM verification failures.
