# Micro Results

Top-level `micro/results/` keeps only checked-in authoritative JSON plus this README.

- `archive/` stores historical, intermediate, analysis, and auxiliary artifacts.
- `dev/` is the default output location for `make smoke`, `make vm-micro-smoke`, and `make vm-micro`.
- `YYYYMMDD` in authoritative filenames comes from the payload `generated_at` date in UTC.

Current top-level authoritative JSON:

- `vm_micro_authoritative_20260318.json`
- `vm_micro_authoritative_20260314.json`
- `smoke_authoritative_20260313.json`
- `vm_micro_smoke_authoritative_20260313.json`
- `kernel_recompile_v2_fixed_authoritative_20260312.json`
