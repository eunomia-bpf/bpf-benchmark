# Wave 2 fallback cleanup summary

## Field removal

Before (active writer/reader sites):
- `runner/libs/case_common.py` synthesized `effective_enabled_passes_by_program` into merged REJIT results.
- `corpus/driver.py` copied `effective_enabled_passes_by_program` back into sliced per-app corpus payloads.
- `runner/libs/rejit.py` exposed `collect_effective_enabled_passes()` to reconstruct selected passes from that field.
- `corpus/driver.py` run metadata wrote `selected_rejit_passes`, `selected_rejit_passes_provenance`, optional `selected_rejit_passes_warning`, and `requested_rejit_passes`.
- `e2e/driver.py` run metadata wrote the same selected/requested pass fields, including the `requested_fallback` branch.
- `e2e/cases/bcc/case.py` wrote BCC-level `selected_rejit_passes`, `selected_rejit_passes_provenance`, optional warning text, and `requested_rejit_passes`.

After:
- `effective_enabled_passes_by_program` is no longer written anywhere in the active corpus/e2e writer path.
- `collect_effective_enabled_passes()` is deleted.
- corpus/e2e `metadata.json` now records suite-level provenance once via:
  - `config.enabled_passes`
  - `policy.exclusions`
- BCC payloads no longer write selected/effective per-program pass metadata.
- The active Rust daemon had no live `effective_enabled_passes_by_program` response field to remove; the field only existed in Python-side synthesis.

Files changed for the removal:
- `runner/libs/rejit.py`
- `runner/libs/case_common.py`
- `corpus/driver.py`
- `e2e/driver.py`
- `e2e/cases/bcc/case.py`

## Metadata schema diff

Removed from run metadata:
- `selected_rejit_passes`
- `selected_rejit_passes_provenance`
- `selected_rejit_passes_warning`
- `requested_rejit_passes`

Added to run metadata:
- `config.enabled_passes`
- `policy.exclusions`

Removed from result payloads:
- `effective_enabled_passes_by_program`

Retained intentionally:
- `scan_enabled_passes`
  This is the actual scan request input sent to the daemon, not a redundant per-program reconstruction.

## Other fallbacks swept

- `e2e/driver.py`:
  deleted the `requested_fallback` branch that replaced missing provenance with requested passes.
- `corpus/driver.py`:
  deleted the run-metadata path that treated requested passes as truth when selected/effective provenance was missing.
- `e2e/cases/bcc/case.py`:
  deleted the missing-provenance fallback branch and all BCC-selected-pass metadata writes.
- `runner/libs/app_runners/katran.py`:
  removed silent temp-file cleanup `except FileNotFoundError: pass` branches and stopped rewriting a missing `bpftool prog run` output file into empty bytes.

## Anything not removed

- Historical artifacts under `corpus/results/` and `e2e/results/` still contain the deleted field and were intentionally left untouched.
- `runner/libs/case_common.py::_resolve_apply_passes_by_program()` still computes per-program pass lists for the live apply request path.
  That derivation is still required to send concrete daemon apply requests; only serialization of the derived data was removed.
- No daemon Rust response field was removed because the active daemon did not emit this field.

## Validation results

- `python3 -c "import corpus.driver, e2e.driver, runner.libs.rejit, runner.libs.case_common"`:
  pass
- `python3 -m compileall corpus/ e2e/ runner/ daemon/`:
  fails due pre-existing vendored Python 2 scripts under `runner/repos/`, not this change:
  - `runner/repos/calico/cni-plugin/contrib/test_scripts/benchmark.py`
  - `runner/repos/calico/cni-plugin/contrib/test_scripts/simple_test.py`
  - `runner/repos/calico/cni-plugin/contrib/test_scripts/util.py`
  - `runner/repos/suricata/qa/sock_to_gzip_file.py`
- Supplemental active-code compileall:
  `python3 -m compileall -q corpus/driver.py e2e/driver.py e2e/cases/ runner/libs/ daemon/`
  pass
- `cargo check --manifest-path daemon/Cargo.toml`:
  pass
- `make vm-e2e E2E_CASE=bcc SAMPLES=1`:
  skipped
  Reason: `pgrep -af "docker build"` showed an active arm64 runtime-image rebuild at validation time:
  `3438524 docker build --platform linux/arm64 --target runner-runtime --build-arg IMAGE_WORKSPACE=/home/yunwei37/workspace/bpf-benchmark --build-arg IMAGE_BUILD_JOBS=4 --build-arg RUN_TARGET_ARCH=arm64 -t bpf-benchmark/runner-runtime:arm64 -f /home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile /home/yunwei37/workspace/bpf-benchmark`
