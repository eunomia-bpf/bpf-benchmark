# P1-B kinsn TargetSpec consolidation

Date: 2026-05-09

## Summary

`bpfopt/crates/bpfopt/src/kinsn.rs` now owns the single kinsn target table:

```rust
pub struct TargetSpec {
    pub canonical_name: &'static str,
    pub registry_slot: KinsnSlot,
    pub probe_aliases: &'static [&'static str],
    pub required_by_pass: &'static str,
    pub proof_layout: ProofLayout,
}
```

Field rationale:

- `canonical_name`: public target JSON / CLI name used by bpfopt after alias canonicalization.
- `registry_slot`: fixed-array index for runtime BTF IDs and module call offsets.
- `probe_aliases`: kernel BTF function names emitted through `list-passes --json`.
- `required_by_pass`: canonical pass name that requires the target.
- `proof_layout`: packed sidecar payload schema used by BTF metadata proof remapping.

CLI aliases are derived from the table by accepting each canonical name, each probe alias, and their `bpf_`-stripped forms. This preserves `rotate64`, `bulk_memcpy`, and legacy `memcpy_bulk` spellings without a separate alias table.

## Target Entries

| canonical_name | aliases / probe names | pass | slot | proof layout |
|---|---|---|---|---|
| `bpf_rotate64` | `bpf_rotate64`, `rotate64` | `rotate` | `Rotate64` | rotate payload, shift mask 63 |
| `bpf_rotate32` | `bpf_rotate32`, `rotate32` | `rotate` | `Rotate32` | rotate payload, shift mask 31 |
| `bpf_select64` | `bpf_select64`, `select64` | `cond_select` | `Select64` | select payload |
| `bpf_ccmp64` | `bpf_ccmp64`, `ccmp64` | `ccmp` | `Ccmp64` | ccmp payload |
| `bpf_extract64` | `bpf_extract64`, `extract64` | `extract` | `Extract64` | extract payload |
| `bpf_endian_load16` | `bpf_endian_load16`, `endian_load16` | `endian_fusion` | `EndianLoad16` | endian payload |
| `bpf_endian_load32` | `bpf_endian_load32`, `endian_load32` | `endian_fusion` | `EndianLoad32` | endian payload |
| `bpf_endian_load64` | `bpf_endian_load64`, `endian_load64` | `endian_fusion` | `EndianLoad64` | endian payload |
| `bpf_bulk_memcpy` | `bpf_bulk_memcpy`, `bulk_memcpy`, `bpf_memcpy_bulk`, `memcpy_bulk` | `bulk_memory` | `BulkMemcpy` | bulk memcpy payload |
| `bpf_bulk_memset` | `bpf_bulk_memset`, `bulk_memset`, `bpf_memset_bulk`, `memset_bulk` | `bulk_memory` | `BulkMemset` | bulk memset payload |
| `bpf_prefetch` | `bpf_prefetch`, `prefetch` | `prefetch` | `Prefetch` | prefetch payload |

## Derived Relations

- `KinsnRegistry`: stores `btf_ids: [i32; KinsnSlot::COUNT]` and `call_offsets: [i16; KinsnSlot::COUNT]`; all name lookups go through `TargetSpec.registry_slot`.
- `main.rs`: target JSON and `--kinsns` parsing use `target_spec_by_name()` for canonicalization; required kinsns are read from pass metadata instead of a second pass-name match.
- `PASS_REGISTRY`: `KinsnRef` stores only the canonical target name and resolves `json_name` / `probe_aliases` through `TargetSpec` serialization.
- `utils.rs`: proof-region dispatch iterates `KINSN_TARGETS`, matches by slot BTF ID and slot call offset, then calls the proof decoder selected by `TargetSpec.proof_layout`.

## Daemon Decision

No daemon mirror table was added.

Reason: `daemon/src/server.rs` parses runner-provided `kinsn_probes[]`, and `daemon/src/bpf.rs` probes only that request list. There is no daemon-side hardcoded target metadata to consolidate. This keeps the daemon independent from `bpfopt` and avoids a path dependency.

## LOC Delta

P1-B core-file line counts measured before edits and after final formatting:

| file | before | after | delta |
|---|---:|---:|---:|
| `bpfopt/crates/bpfopt/src/main.rs` | 1534 | 1455 | -79 |
| `bpfopt/crates/bpfopt/src/pass.rs` | 1012 | 1009 | -3 |
| `bpfopt/crates/bpfopt/src/passes/mod.rs` | 238 | 249 | +11 |
| `bpfopt/crates/bpfopt/src/passes/utils.rs` | 1531 | 1448 | -83 |
| `bpfopt/crates/bpfopt/src/passes/rotate.rs` | 468 | 470 | +2 |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs` | 800 | 800 | 0 |
| `bpfopt/crates/bpfopt/src/passes/cond_select.rs` | 574 | 574 | 0 |
| `bpfopt/crates/bpfopt/src/passes/ccmp.rs` | 345 | 345 | 0 |
| `bpfopt/crates/bpfopt/src/passes/extract.rs` | 190 | 190 | 0 |
| `bpfopt/crates/bpfopt/src/passes/endian.rs` | 512 | 517 | +5 |
| `bpfopt/crates/bpfopt/src/passes/prefetch.rs` | 797 | 797 | 0 |
| `bpfopt/crates/bpfopt/src/lib.rs` | 20 | 21 | +1 |
| `bpfopt/crates/bpfopt/src/kinsn.rs` | 0 | 46 | +46 |
| `daemon/src/bpf.rs` | 395 | 395 | 0 |
| total | 8416 | 8316 | -100 |

Requested HEAD-scoped check:

```text
git diff --shortstat HEAD -- bpfopt/crates/bpfopt/src daemon/src
38 files changed, 878 insertions(+), 1314 deletions(-)
```

That command reports net `-436` over tracked files. The table above includes the new untracked `kinsn.rs` file, giving the P1-B core-file total `-100`.

## Compliance Self-Check

- No ReJIT filtering, runner, corpus, vendor, e2e, micro, benchmark logic, or `map_inline.rs` body changes.
- No daemon path dependency on `bpfopt`.
- No hardcoded BTF IDs; IDs still come from target JSON or `--kinsns`.
- No helper-number aliases, `#[allow(dead_code)]`, `.ok()`, `let _ =`, or `unwrap_or_default` introduced in the touched core files.
- No tests, benchmarks, `make`, `cargo run`, or component binaries were run.
- Verification run only:
  - `cd bpfopt && cargo build --workspace --locked`
  - `cd daemon && cargo build --workspace --locked`

## Follow-Up Simplification

`PASS_REGISTRY` still carries one small canonical-name slice per kinsn pass. A later cleanup could derive all kinsn pass metadata directly from `KINSN_TARGETS.required_by_pass`, while preserving explicit pass ordering and non-kinsn metadata in `PASS_REGISTRY`.
