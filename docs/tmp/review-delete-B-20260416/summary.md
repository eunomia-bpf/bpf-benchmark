# Review Delete B - 2026-04-16

## Scope

- Read `docs/kernel-jit-optimization-plan.md` before editing.
- Initial working tree was clean for `e2e/cases/tetragon/case.py` and `e2e/cases/tracee/case.py`; no read-only fallback was needed there.
- Did not touch `runner/`, `vendor/linux-framework/`, `vendor/llvmbpf/`, `module/`, or `docs/kernel-jit-optimization-plan.md`.

## Deleted

- Removed 235 timestamped `e2e/results/*_2026*_*` session directories.
- Removed 70 timestamped `micro/results/<run_type>_<timestamp>` session directories.
- Removed local ignored micro intermediates: `micro/generated-inputs/`, `micro/jit-dumps/`, `micro/build-arm64/`, `micro/tools/`, and generated `micro/programs/` build products.
- Removed unused vendor gitlinks and `.gitmodules` entries for `vendor/bpftool`, `vendor/linux`, and `vendor/linux-baseline`.

## Kept

- Kept flat authoritative e2e and micro result artifacts, including the documented `*_authoritative_*.json` files.
- Kept `vendor/linux-framework`, `vendor/llvmbpf`, `vendor/libbpf`, and the two `vendor/bpfrejit_*_defconfig` files.
- Kept e2e and micro source cases, drivers, and catalog behavior intact.

## Small Cleanup

- `micro/compare_results.py` now reuses the existing `runner.libs.statistics.geometric_mean` helper instead of carrying a local duplicate.
- `micro/driver.py` and affected e2e cases now import existing helper functions from their current owner modules.
- `micro/config/micro_pure_jit.yaml` no longer records the removed `vendor/bpftool` metadata entry.
- `micro/results/README.md` now documents that timestamped session directories are transient and that retained top-level JSON files are the durable artifacts.

## Notes

- Concurrent staged `corpus/results` deletions and `runner/...` modifications were left out of this review-B commit.
- Concurrent untracked result `.gitignore` files were observed and left unstaged.
