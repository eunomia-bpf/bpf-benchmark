# enumerate --json Per-Site Manifest Fix

## Problem

`e2e/common/recompile.py`'s `_apply_one_enumerate()` needed per-site manifest data
(insn offset, family, pattern_kind) to remap static policies to live program site
addresses via `remap_policy_v3_to_live`.  However, `scanner enumerate --json` only
emitted aggregate counts (`total_sites`, `applied_sites`) without per-site detail,
so the code fell back to calling the legacy `scan --prog-fd` path to get the full
manifest — requiring a caller-held file descriptor.

## Fix

### 1. `scanner/src/cli.cpp` — add `sites` array to enumerate JSON output

Added a new `EnumerateSiteInfo` struct:
```cpp
struct EnumerateSiteInfo {
    uint32_t insn = 0;
    std::string family;
    std::string pattern_kind;
};
```

Added `std::vector<EnumerateSiteInfo> sites` to `EnumerateResult`.

After pattern matching in `run_enumerate`, the code now calls
`bpf_jit_scanner::build_scan_manifest()` to extract per-site data and
populates `res.sites` from `manifest.sites`.

In the JSON output block, a `"sites":[...]` array is emitted for each program:
```json
{
  "prog_id": 84092,
  "name": "syncookie_xdp",
  "total_sites": 36,
  "applied_sites": 36,
  "recompile_ok": false,
  "sites": [
    {"insn": 6,  "family": "endian",  "pattern_kind": "endian-load-swap-16"},
    {"insn": 47, "family": "extract", "pattern_kind": "bitfield-extract-64-shift-mask"},
    ...
  ]
}
```

### 2. `e2e/common/recompile.py` — use enumerate sites directly

`_apply_one_enumerate()` now extracts the `sites` list from the enumerate scan
record and builds `live_manifest = {"sites": enum_sites}` directly, compatible
with `remap_policy_v3_to_live`.  The legacy `_scan_live_manifest` fallback is
retained only when the enumerate record has no `sites` key (old scanner binary).

`_scan_counts_from_enumerate()` is updated to derive per-family counts from
the `sites` array when present, instead of returning all zeros.

## Validation

Build:
```
cmake --build scanner/build --target bpf-jit-scanner -j  → [100%] OK
```

Tests:
```
cd scanner/build && ctest  → 1/1 Passed
```

Python syntax:
```
python3 -m py_compile e2e/common/recompile.py  → OK
```

Live test (enumerate --prog-id 84092 --json):
```
prog_id=84092 name=syncookie_xdp total_sites=36 sites_len=36
first site: {'insn': 6, 'family': 'endian', 'pattern_kind': 'endian-load-swap-16'}
```

Remap pipeline test: 2 sites explicit → 2 remapped, 0 dropped — works correctly
with enumerate-format `sites` list passed directly to `remap_policy_v3_to_live`.

## Files Changed

- `scanner/src/cli.cpp`: `EnumerateSiteInfo` struct, `sites` vector in
  `EnumerateResult`, site population after pattern match, JSON output extended
- `e2e/common/recompile.py`: `_apply_one_enumerate` uses enumerate sites
  directly; `_scan_counts_from_enumerate` derives per-family counts from sites
