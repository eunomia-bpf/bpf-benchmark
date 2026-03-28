# Expanded Corpus Build Results

- Generated: `2026-03-28T18:40:56.745655+00:00`
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/runner/repos.yaml`
- Repo root: `/home/yunwei37/workspace/bpf-benchmark/runner/repos`
- Macro corpus: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_corpus.yaml`
- Build root: `/home/yunwei37/workspace/bpf-benchmark/corpus/build`
- Sources considered: 282
- Built from source: 2
- Staged existing objects: 279
- Available objects: 281
- Failures: 1

## Per-Repo Summary

| Repo | ok | existing | error | timeout |
| --- | ---: | ---: | ---: | ---: |
| linux-selftests | 2 | 279 | 1 | 0 |

## Failure Stages

| Stage | Count |
| --- | ---: |
| clang | 1 |

## Top Errors

| Error | Count |
| --- | ---: |
| In file included from /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/tools/i... | 1 |

## Sample Failures

| Repo | Path | Stage | Error |
| --- | --- | --- | --- |
| linux-selftests | tools/testing/selftests/bpf/progs/arena_atomics.c | clang | In file included from /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/tools/i... |

## Notes

- The builder scans repo sources directly from `runner/repos.yaml`.
- Global include paths are pinned to repo-managed libbpf and `vendor/linux-framework` headers; host `/usr/include` is not injected.
- Macro-corpus objects that are already present under `corpus/build/` are recorded as `existing` so `vm-corpus` can validate one strict availability report.
