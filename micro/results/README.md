# Micro Results

Canonical micro result payloads use these JSON names:

- `micro_<N>bench_authoritative_YYYYMMDD.json`: full-suite authoritative run (N = benchmark count).
- `micro_<N>bench_smoke_YYYYMMDD.json`: subset or spotcheck run.
- `vm_micro_smoke_authoritative_YYYYMMDD.json`: VM smoke run.
- `smoke_authoritative_YYYYMMDD.json`: minimal smoke (llvmbpf-only, no VM).
- `smoke.latest.json` / `vm_micro_smoke.latest.json`: symlinks to newest authoritative smoke JSON.

Conventions:

- `YYYYMMDD` is the UTC calendar date from the payload's `generated_at` timestamp.
- `*.latest.json` is only for authoritative results.
- Markdown reports, figures, and the `rigorous/` spotcheck archive are supporting artifacts and keep descriptive names.
- Per-benchmark ablation results live under `per_form_ablation_YYYYMMDD/`.
- Archived intermediate files live under `archive/`.

Current authoritative results:

- Full 62-bench suite: `micro_62bench_authoritative_20260313.json`
- Policy-optimized build (build #40): `micro_62bench_build40_policy_optimized_20260313.json`
- Kernel recompile paired run: `kernel_recompile_v2_fixed_authoritative_20260312.json`
