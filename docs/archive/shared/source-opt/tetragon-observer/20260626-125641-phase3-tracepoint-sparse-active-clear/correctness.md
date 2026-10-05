# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor tetragon-x86` completed successfully before the formal run. | pass |
| Formal entrypoint | Ran the public `make corpus` target with `BPFREJIT_CORPUS_APPS='tetragon/observer'`; no direct runner invocation. | pass |
| Load | App result status is `ok`; app `error` is empty. | pass |
| Workload | Three baseline workload samples returned `returncode=0`; stress-ng reported `passed: 6`, `failed: 0`, and `metrics untrustworthy: 0` for each sample. | pass |
| ReJIT skip semantics | Suite result has `skip_rejit=true`; app `post_rejit` is `null`, so no post phase ran under `SKIP_REJIT=all`. | pass |
| ABI | No map layout, event payload, tail-call index, attach point, or userspace loader interface changed. | pass |
| Fallback safety | Selector-enabled or missed no-selector fast-path events still clear the full `sel.active[]` array before the original filter tail-call path. | pass |
| Restore | `source.diff` matched the live Tetragon diff, was reverse-applied with `patch -R`, and `git -C vendor/repos/tetragon status --short` printed no local changes. | pass |
