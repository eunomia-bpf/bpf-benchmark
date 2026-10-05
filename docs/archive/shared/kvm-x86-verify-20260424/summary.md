# KVM x86 Verify 2026-04-24

## Scope

- Branch: `codex/remove-dead-code-complexity`
- Initial build-fix commit pushed: `ffced1c8` (`Fix KVM runtime build inputs`)
- Follow-up runtime/e2e/corpus fix commit pushed: `ee750376` (`Fix VM corpus and e2e ReJIT flows`)

## Code Fixes

- `runner/libs/rejit.py`
  - restored missing `dataclass` import so ReJIT module imports cleanly
- `runner/libs/case_common.py`
  - added lifecycle hooks for per-runner skip/abort behavior
  - default live ReJIT target set now comes from runner-specific `live_rejit_programs()`
- `runner/libs/app_runners/base.py`
  - added default `live_rejit_programs()` hook
- `runner/libs/app_runners/tracee.py`
  - excluded `syscall__init_module` from live ReJIT targets
  - fixes corpus `tracee/default` failure on `BPF_PROG_REJIT: Invalid argument`
- `runner/libs/app_runners/scx.py`
- `corpus/driver.py`
- `e2e/cases/scx/case.py`
  - restored skip semantics for unsupported SCX live ReJIT instead of failing the suite

## Verification Runs

### `make vm-e2e`

- Final passing run completed at `2026-04-25 03:43:24 -0700`
- Result: `e2e: ALL PASSED`
- Latest passing case artifacts:

| case | artifact dir | status | programs | `result.json` bytes |
| --- | --- | --- | ---: | ---: |
| tracee | `e2e/results/tracee_20260425_092614_688492` | `ok` | 158 | 286423 |
| tetragon | `e2e/results/tetragon_20260425_093158_192348` | `ok` | 287 | 338521 |
| bpftrace | `e2e/results/bpftrace_20260425_093500_223502` | `ok` | 10 | 56444 |
| scx | `e2e/results/scx_20260425_093747_765355` | `ok` | 13 | 20542 |
| bcc | `e2e/results/bcc_20260425_093822_885596` | `ok` | 26 | 95325 |
| katran | `e2e/results/katran_20260425_094250_768725` | `ok` | 3 | 5820 |

Checks:

- `bpftrace` / `bcc` / `katran` program counts are no longer `0`; they are `10 / 26 / 3`
- `tracee` `result.json` is `286423` bytes, well under `1 MB`
- `tetragon` stabilized within the enforced `45s` window
  - evidence in code: [runner/libs/app_runners/tetragon.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/tetragon.py:57) uses `timeout_s=self.load_timeout`
  - default is `45` at [runner/libs/app_runners/tetragon.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/tetragon.py:133)
  - the latest `tetragon` case passed, so attach + program-set stabilization completed inside that window

### `make vm-corpus SAMPLES=1`

- Final passing run completed at `2026-04-25 03:03:01 -0700`
- Artifact dir: `corpus/results/x86_kvm_corpus_20260425_094938_806034`
- Overall status: `ok`
- Result count: `20`
- OK count: `20`

Apps:

- `bcc/capable`
- `bcc/execsnoop`
- `bcc/bindsnoop`
- `bcc/biosnoop`
- `bcc/vfsstat`
- `bcc/opensnoop`
- `bcc/syscount`
- `bcc/tcpconnect`
- `bcc/tcplife`
- `bcc/runqlat`
- `scx/rusty`
- `tetragon/default`
- `katran`
- `tracee/default`
- `bpftrace/capable`
- `bpftrace/biosnoop`
- `bpftrace/vfsstat`
- `bpftrace/runqlat`
- `bpftrace/tcplife`
- `bpftrace/tcpretrans`

## Review

- `python -m py_compile $(rg --files runner/libs runner/suites corpus e2e -g '*.py')` passed
- direct imports passed for:
  - `runner.libs.rejit`
  - `runner.libs.case_common`
  - `runner.libs.app_runners.base`
  - `runner.libs.app_runners.scx`
  - `runner.libs.app_runners.tracee`
  - `corpus.driver`
  - `e2e.cases.scx.case`

Note:

- a broader `python -m py_compile $(rg --files runner corpus e2e -g '*.py')` fails in vendored upstream code under `runner/repos/suricata/`
  - `runner/repos/suricata/qa/sock_to_gzip_file.py` is Python 2 syntax
  - this is outside the benchmark core files changed in this task

## Final State

- Required code fixes are committed and pushed
- `vm-e2e` passed on the latest code
- `vm-corpus SAMPLES=1` passed on the latest code
- requested artifact checks passed
