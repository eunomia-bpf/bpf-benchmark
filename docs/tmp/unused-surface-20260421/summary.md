# Unused contract surface verification (2026-04-21)

## Per-item results

| Item | Verify result | Action taken | Notes |
| --- | --- | --- | --- |
| `runner/suites/corpus.py:43` / `runner/libs/suite_args.py:112` / `Makefile:88` corpus `--warmups` | `UNUSED` | deleted | `runner.suites.corpus` accepted `--warmups`, `suite_args_from_env()` emitted it for corpus, and `VM_CORPUS_SUITE_ARGS` also emitted it. `corpus/driver.py` does not parse or read `--warmups`, so the flag was forwarded into a dead end. |
| root `Makefile:46` `PROFILE` | `UNUSED` | deleted | Active code only used prefixed AWS profile inputs (`AWS_ARM64_PROFILE` / `AWS_X86_PROFILE`) through `runner/libs/run_contract.py`. The unprefixed root `PROFILE` variable was only declared in `Makefile` and printed in the `vm-e2e` help text. |
| `Makefile:64` `KALLSYMS_EXTRA_PASS` | `UNUSED` | deleted | `git grep -n 'KALLSYMS_EXTRA_PASS' -- Makefile runner .github scripts` only found the declaration. |
| `Makefile:202` `aws-e2e` / `aws-corpus` | `USED` | kept | These are live user-facing single-suite AWS wrappers. Recent plan/report docs record real runs via `make aws-e2e RUN_TARGET_ARCH=...` and `make aws-corpus RUN_TARGET_ARCH=...`. They dispatch to `run aws-<arch> <suite>`; canonical `aws-*-benchmark` with a single mode ultimately calls the same `_run_action()` path, but the wrappers remain current entry points and `aws-e2e` also preserves `SUITES` -> `AWS_*_E2E_CASES` compatibility. |

## Dry-run validation

`make -n vm-e2e 2>&1 | head`

```text
"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run x86-kvm e2e -- --e2e-cases "all"
```

`make -n aws-e2e RUN_TARGET_ARCH=x86_64 2>&1 | head`

```text
case "x86_64" in \
	arm64) AWS_ARM64_E2E_CASES="" "/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run aws-arm64 e2e ;; \
	x86_64) AWS_X86_E2E_CASES="" "/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run aws-x86 e2e ;; \
	*) echo "unsupported RUN_TARGET_ARCH for aws-e2e: x86_64" >&2; exit 2 ;; \
esac
```

`python3 -m py_compile runner/suites/corpus.py runner/suites/e2e.py runner/libs/suite_args.py`

```text
exit 0 (no output)
```

## Alias verification notes

Additional dry-runs used to confirm the AWS wrapper/canonical relationship without launching AWS:

- `make -n aws-e2e RUN_TARGET_ARCH=arm64`
- `make -n aws-corpus RUN_TARGET_ARCH=x86_64`
- `make -n aws-arm64-benchmark AWS_ARM64_BENCH_MODE=e2e`
- `make -n aws-x86-benchmark AWS_X86_BENCH_MODE=corpus`

Code inspection of `runner/libs/run_target_suite.py:209-211` confirmed that `benchmark aws-<arch> "<single-suite>"` iterates into the same `_run_action()` used by the wrappers for single-suite modes.

## Commits

- `af50b6d115d1c948a5a7a96f6bc277c605bb18fa` `[corpus] remove ignored --warmups flag`
- `3c6ab8fb5ae0a0258412ffa5de67216ec02809fa` `[make] remove unused PROFILE / KALLSYMS_EXTRA_PASS variables`

## Not deleted

- `aws-e2e` and `aws-corpus` were intentionally kept because they are still documented and used as the current single-suite AWS entry points.
