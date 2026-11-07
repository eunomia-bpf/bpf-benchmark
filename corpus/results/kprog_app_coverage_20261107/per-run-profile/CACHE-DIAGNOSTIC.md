# Same-input functional cache diagnostic

The unchanged upstream Katran server loads all its programs with the existing frozen image and matching kernel. Each fresh instance starts with an empty fallback LRU and receives100 identical TCP ACK/VIP inputs with flags0. CPU12-15 was used only for functional diagnosis; recorded durations are not comparative timing.

| Arm | Lowering disabled | Inputs | Non-SYN misses | Cache entries observed |
|---|---:|---:|---:|---:|
| JIT |0|100|1|1|
| native |0|100|100|1|
| native |1|100|1|1|

Both native arms record1 replacement and0 loader failures. Every explicit input returns XDP_TX3,84B, FNV647f2ff540c87b52ba. In all three caches the exact40B key is `0a0000020000000000000000000000000a6401010000000000000000000000007a691f9006000000` and16B value is `01000000000000000000000000000000`. Native insertion and retained keys therefore work, while lowering changes lookup behavior. This isolates a correctness defect in the lowering path; it is not evidence of cache-hit performance overhead. Connection-rate counters are1/100/1, consistent with the miss counts. All app-owned maps/programs remain loaded; there is no program exclusion.

`cache-functional-raw.tar.gz` retains before/after map dumps, sampled raw cache bytes, actual work results, upstream setup, shim logs and cached link plans for both native settings. Lowered fallback sites20/41/47 are `lru_hash` with key/value adjustment88 and ref-byte offset35, targeting the actual `__htab_map_lookup_elem`; disabled sites call the generic map helper. The runtime VIP hash JIT adjustment72 agrees with the loader, so an offset mismatch has not been established. A follow-up diagnostic records guest-local tracefs raw lookup args/returns and loaded JIT bytes to distinguish key/address failure from postprocessing. No upstream source/workload or common app runner is changed.
