# Step 0064: KVM x86 `make selftest` gate (zero knobs)

- **Command**: `PLATFORM=kvm ARCH=x86 make selftest` (zero knobs —
  `PLATFORM`/`ARCH` only). Nominal `TEST_MODE=selftest` per
  `Makefile:226` (target-specific); the KVM in-VM `TEST_MODE`
  propagation gap (recorded in 0055) means the in-VM suite runs the
  default `test`-mode full gate (superset; evidence still valid).
- **Launched**: `Wed Sep 30 14:51:47 UTC 2026`, make PID 1569206.
- **prev HEAD**: `d70317d34` (= `origin/master`, increment 23: arm64
  negative-test).
- **In-VM result window**: `2026-09-30T14:56:53.760Z →
  2026-09-30T14:56:57.940Z` (~4.2 s of in-VM work).
- **Result token**: `tests/results/fc73bdc4/`
  - `native_proof_micro_20260930_145653_760978/metadata.json`:
    `status: completed`, `progress: 29/29 completed`, `run_type:
    native_proof_micro`, `suite: micro_staged_codegen`,
    `runtime: native_proof` with `--samples 1 --warmups 0
    --inner-repeat 1` (gate defaults).
  - 32 trackable files total (token + nested run dir:
    `metadata.json`, `details/progress.json`, `details/result.json`,
    29× `details/code_compare/*.md`).
- **Benchmarks**: 29/29 `native_proof` benches ok — each
  `result`/`retval` matches `expected_result`/`expected_retval`
  (e.g. `simple`: `12345678`/`2`; `bitmap_popcount_scan`:
  `12830754992348206170`/`2`; `tc_packet_checksum_fold`: `0`/`0`).
- **Gate PASS lines** (from `make-selftest.log`, final form):
  - `PASS unchecked_packet_read rejected rc=1`
  - `PASS valid_xdp_pass`
  - `PASS invalid_opcode errno=22`
  - `PASS stack_oob_write errno=13`
  - `PASS uninitialized_register errno=13`
- **VM lifecycle**: clean `reboot: Power down` at log line 504
  (`[47.125299]`); `qemu-status=0`; make target exits 0.
- **Error markers**: 0 — no `make ***`, `FAILED`, `fatal`,
  `Aborted`, `Terminated`, `did not match`, `unexpectedly succeeded`
  anywhere in the final log.
- **Provenance**:
  - in-VM `kernel_version: 7.0.0-rc2+`, `hostname: virtme-ng`,
    `cpu_model: "Intel(R) Core(TM) Ultra 9 285K"`,
    `repo_dirty: false`, `environment: vm`.
  - in-VM sub-make (decoded from `virtme.exec=` in the metadata
    cmdline): `make -C /workspaces/repository __runtime-vm-test
    TARGET='x86-kvm' RUN_TARGET_NAME='x86-kvm' RUN_TARGET_ARCH='x86_64'
    RUN_EXECUTOR='kvm' RUNTIME_CONTAINER_IMAGE='bpf-benchmark/runner-runtime:x86_64'
    RUNTIME_IMAGE_TAR='/workspaces/repository/.cache/container-images/x86_64-runner-runtime.image.tar'
    RUN_REMOTE_PYTHON_BIN='python3' RUN_RUNTIME_PYTHON_BIN='python3'
    RUN_BPFTOOL_BIN='bpftool' RUN_NATIVE_REPOS_CSV='bcc,katran,tracee,tetragon'
    RUN_TOKEN='fc73bdc4' SAMPLES='3' FUZZ_ROUNDS='1000'
    MERLIN_COMPILETIME_MODE='none'` — note `TEST_MODE` is absent,
    confirming the propagation gap.
  - host kernel `7.3.0-070300rc3-generic` (the 09-30 host-kernel
    change; this is the first KVM x86 gate evidence since then).
- **Caveats** (raw results + PASS lines intact):
  1. The log shows a line-count oscillation across reads
     (2439 → 9949 → 504 lines, with `make: Leaving directory`
     interleaved mid-line at line 35: `[bench] (10/2make: Leaving
     directory '/workspaces/repository'`). This is log
     interleaving from a concurrent make instance writing to
     stderr simultaneously, not a defect in the result.
  2. `tests/results/aborted/d6b6575f/negative.log` (128 bytes, 14:29Z —
     before this run's 14:51 launch) holds exactly the 4
     negative-smoke PASS lines = a **parallel/supervisor instance**
     ran a KVM in-VM `TEST_MODE=negative` run during this window.
     Both `d6b6575f` and `fc73bdc4` are untracked; this step
     commits **only** `fc73bdc4` (its own token); `d6b6575f` is
     external WIP and is neither committed nor claimed here.
- **Significance**: completes the KVM x86 target-coverage matrix
  under the current host kernel. 09-30 KVM x86 log entries covered
  micro/corpus/test/negative-test; this is the first post-host-
  kernel-change KVM x86 selftest entry. The 5/5 target-parity
  matrix (0058 micro, 0059+0060 corpus, 0061 test, 0062 selftest,
  0063 negative-test) is now complete on arm64; KVM x86 evidence
  continues under the user's 2026-09-30 authorization.
- **AWS arm64**: re-checked read-only 2026-09-30 — no `~/.aws`, no
  aws-cli profiles, no matching `.pem`; resume when credentials
  land.
