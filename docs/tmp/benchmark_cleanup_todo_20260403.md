# Benchmark Cleanup TODO (2026-04-03)

Target state agreed in review:

- Timestamped run directories are the only canonical benchmark artifacts.
- No top-level `*_authoritative_YYYYMMDD.json`.
- No `*.latest.json` or equivalent pointer files.
- No duplicate result payload copies in multiple locations.
- Result READMEs describe the timestamped artifact model only.
- Benchmark docs match the current `Makefile` and runner behavior.
- `vm-micro` remains `llvmbpf` vs `kernel`.

## TODO

- [in-progress] Remove top-level result duplication from corpus/e2e so runs only persist into timestamped artifact directories.
- [pending] Remove authoritative/latest-style helper usage from active benchmark entrypoints.
- [pending] Update `micro/results/README.md`, `corpus/results/README.md`, and `e2e/results/README.md` to document the canonical artifact layout only.
- [pending] Update benchmark docs to match current command behavior for `check`, `validate`, `vm-all`, and `vm-selftest`.
- [pending] Update benchmark docs/READMEs so `Makefile` is the canonical entrypoint and stale direct-driver examples are removed or clearly marked non-canonical.
- [pending] Verify the cleaned result flow and record any remaining follow-up separately.
