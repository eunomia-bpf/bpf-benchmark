# Expanded Corpus Build Results

- Generated: `2026-03-24T04:47:32.697095+00:00`
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/runner/repos.yaml`
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/runner/inventory.json`
- Build root: `/home/yunwei37/workspace/bpf-benchmark/corpus/build`
- Sources considered: 0
- Compiled successfully: 0
- Compile failures: 0

## Per-Repo Summary

| Repo | ok | error | timeout |
| --- | ---: | ---: | ---: |

## Notes

- The builder keeps going across compile failures and records both `clang` and `bpftool gen object` errors.
- Output objects are written under `corpus/build/<repo>/...` and keep the source-relative path to avoid filename collisions.
- Include paths are intentionally broad; many upstream programs still fail due to repo-specific build systems, generated headers, or kernel feature assumptions.
