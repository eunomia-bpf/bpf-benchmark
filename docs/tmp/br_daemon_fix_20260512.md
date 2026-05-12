# BR daemon target.json fix (2026-05-12)

## Scope

Fixed the BR pass-set pre-pass failure:

```text
probe target kinsns for prog X: target probing requested with no kinsn targets
```

The direct config trigger was DCE requesting `${TARGET}` even though `dce` is a pure bytecode pass. The daemon-side issue was that target JSON preparation treated an empty kinsn probe list as an error instead of producing a platform-only target.

## Changed files

- `runner/config/passes/dce/default.yaml:6`
  - Removed `--target ${TARGET}` from the DCE command.
  - DCE now runs as a pure bytecode pass with `--input`, `--output`, `--report`, and `--prog-type` only.

- `daemon/src/bpf.rs:87`
  - Added `target_json_for_probes()`.
  - Empty probe lists now return:

```json
{
  "arch": "<detected arch>",
  "features": ["<detected features>"],
  "kinsns": {}
}
```

- `daemon/src/bpf.rs:98`
  - Kept `probe_target_json()` fail-fast for callers that explicitly request kinsn probing with an empty target list.

- `daemon/src/commands.rs:522`
  - Changed target file preparation from `probe_target_json(kinsn_probes)` to `target_json_for_probes(kinsn_probes)`.
  - Updated error context to `prepare target.json for prog {prog_id}`.

## Validation

- `cargo build -p bpfrejit-daemon`
  - Status: passed.
  - Run from `/home/yunwei37/workspace/bpf-benchmark/daemon` because the repository root has no `Cargo.toml`.

- `cargo test -p bpfopt --lib`
  - Status: passed.
  - Run from `/home/yunwei37/workspace/bpf-benchmark/bpfopt`.
  - Result: 165 passed, 0 failed.

## Notes

- No kernel files under `vendor/linux-framework` were touched.
- No `bpfopt` code logic was changed.
- No commit was created.
