# P1-B redo: pass-owned kinsn descriptors

Date: 2026-05-09

## Design

P1-B was redone from a centralized `kinsn.rs` target table to pass-owned kinsn metadata. Each kinsn pass now owns its own `KINSN_TARGETS` slice containing `KinsnDescriptor` entries:

```rust
pub struct KinsnDescriptor {
    pub canonical_name: &'static str,
    pub aliases: &'static [&'static str],
    pub decode_proof: fn(&[u8]) -> ProofRegion,
}
```

`PASS_REGISTRY` is the only aggregation point. `PassMetadata` now stores `kinsn_targets: &'static [KinsnDescriptor]`, and `KinsnRegistry::new()` walks `PASS_REGISTRY` to populate:

- `by_name: HashMap<&'static str, RegistryEntry>`
- `by_btf_id: HashMap<i32, &'static KinsnDescriptor>`

`RegistryEntry` stores the runtime `btf_id`, `call_off`, and descriptor pointer. CLI alias canonicalization goes through `KinsnRegistry`'s `by_name` map, so canonical names and all descriptor aliases are accepted from `target.json` and `--kinsns`.

Proof remapping no longer matches a centralized `ProofLayout` enum. `passes/utils.rs` now does:

```rust
let desc = registry.lookup_by_btf_id(btf_id)?;
let proof = (desc.decode_proof)(payload);
let proof_len = proof.proof_len()?;
```

The individual proof decoder functions moved into their owning pass modules.

## Deleted And Added

Deleted from the source tree:

- `bpfopt/crates/bpfopt/src/kinsn.rs`
- `KinsnSlot`
- `ProofLayout`
- `TargetSpec`
- `KinsnRef`

New/changed fields:

- `pass.rs::KinsnDescriptor`: `canonical_name`, `aliases`, `decode_proof`
- `pass.rs::KinsnRegistry`: `by_name`, `by_btf_id`
- `pass.rs::RegistryEntry`: `btf_id`, `call_off`, `descriptor`
- `passes/mod.rs::PassMetadata`: `kinsn_targets`
- `main.rs::ListPassEntry`: internal `kinsn_targets`, serialized as the existing `kinsns_used` JSON field for compatibility

## Kinsn Targets

| pass | canonical targets | aliases |
|---|---|---|
| `rotate` | `bpf_rotate64`, `bpf_rotate32` | `rotate64`, `rotate32` |
| `cond_select` | `bpf_select64` | `select64` |
| `ccmp` | `bpf_ccmp64` | `ccmp64` |
| `extract` | `bpf_extract64` | `extract64` |
| `endian_fusion` | `bpf_endian_load16`, `bpf_endian_load32`, `bpf_endian_load64` | `endian_load16`, `endian_load32`, `endian_load64` |
| `bulk_memory` | `bpf_bulk_memcpy`, `bpf_bulk_memset` | `bulk_memcpy`, `bpf_memcpy_bulk`, `memcpy_bulk`; `bulk_memset`, `bpf_memset_bulk`, `memset_bulk` |
| `prefetch` | `bpf_prefetch` | `prefetch` |

## Bytecode Identity Argument

The emit path was not changed:

- `emit_packed_kinsn_call_with_off()` is unchanged.
- Per-pass payload packing is unchanged.
- Per-pass BTF ID and call offset reads now use canonical target names instead of `KinsnSlot`, but feed the same values into the same emit helper.
- Decoder functions only compute proof-region lengths for BTF metadata remapping after kinsn replacement; they do not participate in instruction emission.

Therefore the emitted bytecode for a given registry state is byte-identical to the previous implementation. The change is metadata ownership and proof-dispatch structure, not lowering.

## LOC Delta

Requested HEAD-scoped command:

```text
git diff --shortstat HEAD -- bpfopt/crates/bpfopt/src daemon/src
26 files changed, 973 insertions(+), 1193 deletions(-)
```

Per-file `git diff --numstat HEAD -- bpfopt/crates/bpfopt/src daemon/src`:

| file | + | - |
|---|---:|---:|
| `bpfopt/crates/bpfopt/src/insn.rs` | 21 | 12 |
| `bpfopt/crates/bpfopt/src/main.rs` | 61 | 140 |
| `bpfopt/crates/bpfopt/src/pass.rs` | 262 | 57 |
| `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs` | 2 | 2 |
| `bpfopt/crates/bpfopt/src/passes/bounds_check_merge_tests.rs` | 1 | 10 |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs` | 102 | 54 |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs` | 6 | 2 |
| `bpfopt/crates/bpfopt/src/passes/ccmp.rs` | 74 | 102 |
| `bpfopt/crates/bpfopt/src/passes/ccmp_tests.rs` | 4 | 3 |
| `bpfopt/crates/bpfopt/src/passes/cond_select.rs` | 44 | 56 |
| `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs` | 8 | 15 |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs` | 1 | 1 |
| `bpfopt/crates/bpfopt/src/passes/endian.rs` | 56 | 90 |
| `bpfopt/crates/bpfopt/src/passes/endian_tests.rs` | 56 | 58 |
| `bpfopt/crates/bpfopt/src/passes/extract.rs` | 42 | 55 |
| `bpfopt/crates/bpfopt/src/passes/extract_tests.rs` | 6 | 4 |
| `bpfopt/crates/bpfopt/src/passes/mod.rs` | 10 | 16 |
| `bpfopt/crates/bpfopt/src/passes/mod_tests.rs` | 1 | 1 |
| `bpfopt/crates/bpfopt/src/passes/prefetch.rs` | 44 | 58 |
| `bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs` | 8 | 16 |
| `bpfopt/crates/bpfopt/src/passes/rewrite.rs` | 32 | 20 |
| `bpfopt/crates/bpfopt/src/passes/rotate.rs` | 77 | 59 |
| `bpfopt/crates/bpfopt/src/passes/rotate_tests.rs` | 21 | 25 |
| `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs` | 1 | 1 |
| `bpfopt/crates/bpfopt/src/passes/utils.rs` | 32 | 335 |
| `bpfopt/crates/bpfopt/src/passes/wide_mem.rs` | 1 | 1 |

Note: this HEAD-scoped table includes pre-existing dirty bpfopt changes in the workspace. No `daemon/src` file changed in this redo.

## Adding A New Kinsn

Adding a new target to an existing kinsn pass now changes one pass file:

1. Add a `KinsnDescriptor` to that pass's `KINSN_TARGETS`.
2. Add the pass-local `decode_*_proof` function.
3. Use the canonical target name in that pass's existing availability/emit path.

No edits are needed in `pass.rs`, `main.rs`, or `passes/utils.rs`; the registry and CLI alias map are derived from `PASS_REGISTRY`.

Adding an entirely new pass still needs the normal pass-module registration in `passes/mod.rs`, because `PASS_REGISTRY` remains the explicit pass ordering and construction list.

## Compliance Self-Check

- Did not touch `vendor/linux-framework`.
- Did not touch daemon, runner, corpus, e2e, micro, or vendor code.
- Did not change `emit_packed_kinsn_call_with_off()` or kinsn payload emit paths.
- Removed the centralized kinsn table and enum dispatch.
- Did not add hardcoded BTF IDs or helper-number aliases.
- Did not add `#[allow(dead_code)]`, `.ok()`, `let _ =`, or `unwrap_or_default()`.
- Did not run `cargo test` or `make`.
- Did not commit.

## Verification

- `cargo build --workspace --locked` from repo root failed immediately because `/home/yunwei37/workspace/bpf-benchmark` has no `Cargo.toml`.
- `cd /home/yunwei37/workspace/bpf-benchmark/bpfopt && cargo build --workspace --locked`: passed.
- `cd /home/yunwei37/workspace/bpf-benchmark/daemon && cargo build --workspace --locked`: passed.
