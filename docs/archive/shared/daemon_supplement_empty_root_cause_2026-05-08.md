# daemon map-in-map supplement empty root cause

Date: 2026-05-08 local / 2026-05-09 UTC

## Result

Root cause is the live Katran `lru_mapping` outer map is empty when the daemon snapshots it. The daemon supplement writer is faithfully recording that empty live state.

This validates the observable part of candidate (a): every `BPF_MAP_LOOKUP_ELEM` on map 7 returned `ENOENT`. The narrower "daemon snapshots before Katran later populates it" explanation is not supported by this run. ReJIT happened after a successful baseline workload, and map 7 was still empty.

The more specific cause is Katran runner configuration:

- `runner/libs/app_runners/katran.py` starts `katran_server_grpc` without `-forwarding_cores`, so the upstream flag default is an empty string.
- `runner/repos/katran/example_grpc/katran_server.cpp` parses that to an empty `forwardingCores` vector.
- `runner/repos/katran/katran/lib/KatranLb.cpp::initLrus()` creates only the prototype map when `forwardingCores_` is empty.
- `runner/repos/katran/katran/lib/KatranLb.cpp::attachLrus()` iterates `forwardingCores_`, so it performs zero `BPF_MAP_UPDATE_ELEM` calls into `lru_mapping`.
- The corpus VIP is configured with `F_LRU_BYPASS`, so the workload still runs while `lru_mapping` remains empty.

Therefore the failing `map_inline` hint is invalid for the current corpus setup:

```text
--inline-hint=lru_mapping:!00000000
```

It asks `bpfopt` to hard-fold a map-in-map outer lookup for key `0`, but there is no live inner map at that key.

## Runtime Evidence

Command run:

```bash
KEEP_WORKDIRS=1 BPFREJIT_BENCH_PASSES="noop,map_inline" BPFREJIT_CORPUS_APPS="katran" SAMPLES=1 make corpus
```

Result directory:

```text
corpus/results/x86_kvm_corpus_20260509_055221_709064
```

Temporary daemon dump lines in `details/daemon.stderr.log`:

```text
inner_map_id_supplement_lookup outer_map_id=7 key=00000000 result=Ok(false) errno=ENOENT
inner_map_id_supplement_lookup outer_map_id=7 key=01000000 result=Ok(false) errno=ENOENT
...
inner_map_id_supplement_lookup outer_map_id=7 key=7e000000 result=Ok(false) errno=ENOENT
inner_map_id_supplement_lookup outer_map_id=7 key=7f000000 result=Ok(false) errno=ENOENT
daemon: map_snapshot prog_id=9 map_id=7 map_type=12 size_bytes=3 action=dumped
```

Counts:

```text
outer_map_id=7 lookup lines: 128
result=Ok(false) errno=ENOENT lines: 128
result=Ok(true) lines: 0
result=Err lines: 0
```

Failure artifact confirms the supplement is empty:

```text
details/failure-artifacts/9.tar.gz: ./map-values/map-7.inner_map_ids.json
{
  "7": {}
}
```

`map-7.show.json` confirms this is the expected map and metadata:

```json
{
  "id": 7,
  "type": "array_of_maps",
  "name": "lru_mapping",
  "bytes_key": 4,
  "bytes_value": 4,
  "max_entries": 128
}
```

`map-7.dump.json` is also empty:

```json
[]
```

The ReJIT failure is then expected:

```text
error: inline hint anchor lru_mapping key 0x00000000 for map-in-map outer map_id=7: map-in-map outer map 7 has no live inner map for key 0x00000000
```

## Candidate Checks

### (a) lookup returns ENOENT for all slots

Confirmed. All 128 ARRAY_OF_MAPS slots returned `Ok(false)` / `ENOENT`.

Refined root cause: the map is not merely observed during a short loader race. In this corpus run it remains empty after the baseline workload because no forwarding cores are configured, so `attachLrus()` has no keys to populate.

### (b) `kernel_sys::map_lookup_elem` API misuse

Rejected.

`bpfopt/crates/kernel-sys/src/lib.rs::map_lookup_elem` maps `ret == 0` to `Ok(true)`, `ENOENT` to `Ok(false)`, and other errors to `Err`. The temporary daemon dump observed 128 `Ok(false)` results and zero `Ok(true)` results, so successful lookups were not being swallowed.

### (c) value buffer length wrong

Rejected.

The outer map reports `bytes_value: 4`, and daemon passes `[u8; 4]`. `bpf_map_lookup_elem(fd, key, value)` does not receive a user-provided length argument; the kernel copies according to the map value size. There were no `EFAULT` or other errors in the dump.

### (d) outer map type filter wrong

Rejected.

The daemon did enter the supplement path for map type 12 (`array_of_maps`), emitted lookup lines, and wrote `map-7.inner_map_ids.json`. `needs_inner_map_id_supplement()` is matching this map.

## Proposed Fix Path

Pick one policy and make it explicit:

1. If Paper A wants to measure `lru_mapping` map-in-map folding for Katran, start Katran with a populated forwarding core set, for example adding a runner-side `-forwarding_cores=0` or the actual traffic CPU list, then only hint keys that are guaranteed populated.
2. If the current corpus intentionally runs with `F_LRU_BYPASS` and no forwarding cores, remove or gate `--inline-hint=lru_mapping:!00000000` from `runner/config/passes/map_inline/katran.yaml`. A hard map-in-map hint must require a live inner map.
3. Optionally add a fail-fast Katran runner readiness check for map-in-map entries if the optimization policy depends on them. That should fail before ReJIT rather than letting `bpfopt` discover an invalid hard hint later.

Do not change daemon supplement semantics: empty live map-in-map outers should continue to produce an empty supplement.

## Debug Change Status

Temporary debug added during investigation:

- File: `daemon/src/commands.rs`
- Location: `lookup_inner_map_id_for_outer_key`
- Added behavior: one `eprintln!` match around each lookup result, reporting `outer_map_id`, key, wrapper result, errno classification, and value on success.
- Added LOC: 16

The temporary debug block was removed after the run. There is no remaining `inner_map_id_supplement_lookup` marker in `daemon/src`.
