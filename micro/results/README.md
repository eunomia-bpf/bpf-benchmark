# Micro Results

Top-level `micro/results/` stores one timestamped directory per run.

- Each run lives under `micro/results/<run_type>_<timestamp>/`.
- `metadata.json` is always kept.
- Older runs of the same type keep `metadata.json` but have `details/` pruned.
- Large per-sample logs live under `details/`.

Current top-level authoritative JSON:

- `vm_micro_authoritative_20260318.json`
- `vm_micro_authoritative_20260314.json`
- `smoke_authoritative_20260313.json`
- `vm_micro_smoke_authoritative_20260313.json`
- `kernel_recompile_v2_fixed_authoritative_20260312.json`
