# Post-Build Fix Static Verify Report (2026-03-28)

## Commands

```bash
python3 runner/scripts/build_corpus_objects.py --max-sources 0
make daemon && make runner
make vm-static-test TARGET=x86
```

## Corpus Rebuild

- Generated at: `2026-03-28T18:46:23.879380+00:00`
- Source summary from `corpus/results/expanded_corpus_build_smoke_20260328.json`
- Built: `0`
- Failed: `8`
- Available: `469`

Notes:
- `built=0` means the rebuild staged existing objects only.
- The builder reported `sources_total=477` and `staged_existing=469`.

## Daemon And Runner Build

- `make daemon && make runner` completed successfully.

## Static Verify

- Generated at: `2026-03-28T19:15:16.569968+00:00`
- Summary from `daemon/tests/results/static_verify.json`
- Objects: `531`
- Programs: `1241`
- Applied: `345`
- Verifier accepted: `345`

Notes:
- `vm-static-test` completed successfully with exit code `0`.
- The `531` objects are `469` macro objects plus `62` micro objects (`manifest_counts` in the result JSON).
