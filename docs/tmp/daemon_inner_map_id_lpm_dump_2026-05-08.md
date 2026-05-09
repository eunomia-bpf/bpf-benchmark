# daemon inner_map_id + LPM_TRIE dump note

Date: 2026-05-08

## Files and LOC

Implementation/config diff before this note:

| file | + | - | note |
| --- | ---: | ---: | --- |
| `bpfopt/crates/kernel-sys/src/lib.rs` | 19 | 0 | `BPF_MAP_LOOKUP_ELEM` wrapper |
| `daemon/src/commands.rs` | 200 | 4 | LPM dump, map-in-map supplement writer, tests, fail-fast cleanup |
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs` | 123 | 0 | supplement reader, empty LPM raw dump handling |
| `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs` | 51 | 0 | supplement + empty LPM tests |
| `runner/config/passes/map_inline/katran.yaml` | 5 | 7 | remove LPM overlay injection, restore outer-only hints |
| `runner/config/passes/map_inline/overlays/katran/lpm_src_v4.json` | 0 | 5 | remove manual workaround |
| `runner/config/passes/map_inline/overlays/katran/lpm_src_v6.json` | 0 | 5 | remove manual workaround |

Total implementation/config: +398 / -21.

## daemon behavior

`needs_bpftool_map_dump()` now includes `BPF_MAP_TYPE_LPM_TRIE`.

For `ARRAY_OF_MAPS` / `HASH_OF_MAPS`, daemon still writes the raw bpftool dump, then writes `map-<id>.inner_map_ids.json` beside it. The supplement schema is:

```json
{
  "7": {
    "00000000": "1234"
  }
}
```

NULL/missing outer entries are omitted.

Key syscall path in `daemon/src/commands.rs`:

```rust
let mut inner_fd_bytes = [0u8; std::mem::size_of::<libc::c_int>()];
if !kernel_sys::map_lookup_elem(outer_fd, key, &mut inner_fd_bytes)? {
    return Ok(None);
}
let inner_raw_fd = libc::c_int::from_ne_bytes(inner_fd_bytes);
let inner_fd = unsafe { OwnedFd::from_raw_fd(inner_raw_fd) };
let inner_info = kernel_sys::map_obj_get_info_by_fd(inner_fd.as_fd())?;
Ok(Some(inner_info.id))
```

`kernel-sys` now exposes `map_lookup_elem(fd, key, value) -> Result<bool>` through libbpf-sys. `ENOENT` returns `Ok(false)` so daemon can omit NULL entries without hiding other lookup errors.

I checked local `bpftool v7.7.0` help: `bpftool map dump MAP` has no documented flag that directly emits this table, so the daemon supplement is the stable interface. I also attempted to create a temporary empty `LPM_TRIE` for empirical `bpftool -j map dump` validation, but this host lacks the required capability:

```text
bpftool map create /tmp/bpf-lpm-dump.SA98Lj/lpm type lpm_trie key 8 value 4 entries 1 name codex_lpm flags 1
Error: map create failed: Operation not permitted
```

## bpfopt behavior

`read_map_values()` still accepts any `inner_map_id` bpftool may emit inline, then reads `map-<id>.inner_map_ids.json` and lets that supplement override/fill entries:

```rust
let supplement: HashMap<String, HashMap<String, InnerMapIdJson>> =
    serde_json::from_slice(&data)?;
let entries = supplement.get(&map_id.to_string()).ok_or_else(...)?;
for (key_hex, inner_map_id_json) in entries {
    let key = decode_inner_map_id_key_hex(map_id, key_hex, key_size)?;
    let inner_map_id = decode_inner_map_id_json(map_id, key_hex, inner_map_id_json)?;
    inner_map_ids.insert((map_id, key), inner_map_id);
}
```

Empty raw LPM dumps are treated like an enumerated-empty overlay only after explicit overlays are read, so old explicit overlays do not duplicate-fail:

```rust
if entries.is_empty() && map_metadata.map_type == kernel_sys::BPF_MAP_TYPE_LPM_TRIE {
    empty_lpm_trie_maps.insert(show.id);
}
...
synthesize_empty_lpm_trie_overlays(&empty_lpm_trie_maps, &metadata, &mut compressed_values)?;
```

## Katran config

`katran.yaml` no longer slurps `lpm_src_v4/v6` overlay files. The LPM hard hints remain and now rely on daemon bpftool dumps. The `lru_mapping` and `global_lru_maps` outer-only hard hints are restored.

## Edge Cases

- Map-in-map outer key has no live inner map: daemon omits that key from the supplement; bpfopt keeps the existing `"no live inner map"` path.
- Empty LPM_TRIE dump: bpftool `[]` becomes an enumerated-empty snapshot in bpfopt and hard NULL fold can apply.
- Non-empty LPM_TRIE dump: no synthetic enumerated overlay is created; exact/prefix semantics are not inferred.
- Supplement has `inner_map_id = 0`, wrong key width, wrong top-level map id, or invalid id string: bpfopt fails fast.
- bpftool dump size limit still applies. Oversized map dumps keep the existing skip marker behavior.

## Test Output

Targeted:

```text
cargo test --manifest-path daemon/Cargo.toml inner_map_id_supplement_schema_uses_hex_keys_under_outer_map_id
test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 27 filtered out

cargo test --manifest-path bpfopt/Cargo.toml -p bpfopt map_values_
test result: ok. 3 passed; 0 failed; 0 ignored; 0 measured; 322 filtered out
```

Workspace:

```text
cargo test --manifest-path bpfopt/Cargo.toml --workspace
test result: ok. 325 passed; 0 failed
test result: ok. 9 passed; 0 failed
test result: ok. 11 passed; 0 failed
test result: ok. 7 passed; 0 failed
test result: ok. 4 passed; 0 failed
test result: ok. 23 passed; 0 failed
test result: ok. 1 passed; 0 failed
test result: ok. 1 passed; 0 failed

cargo test --manifest-path daemon/Cargo.toml --workspace
test result: ok. 28 passed; 0 failed
```

Repository root has no `Cargo.toml`, so root-level `cargo test --workspace` is not a valid command in this checkout; the two manifest-path commands above cover the actual Rust workspaces touched here.
