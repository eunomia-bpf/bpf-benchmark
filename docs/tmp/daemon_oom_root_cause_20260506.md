# Daemon OOM Root Cause - 2026-05-06

## 1. Quantitative estimate

Observed failure:

- App: `tetragon/observer`
- Program count: 287 programs in `corpus/results/x86_kvm_corpus_20260506_181633_977145/details/apps/tetragon__observer.json`
- Pass list: `noop,map_inline`
- Kernel OOM kill: `anon-rss:53325152kB`, which is 50.85 GiB RSS
- Per-program equivalent if all 287 snapshots were retained concurrently: 50.85 GiB / 287 = 181.5 MiB per program

The surviving tetragon artifact does not contain the requested exact `used_maps` evidence. Its `rejit_result` is `{}` because the daemon was killed before it returned a response, and the results directory does not contain a tetragon `fdinfo` dump. Therefore this estimate uses the surviving program count, HEAD code, static Tetragon BTF map definitions from the checked-out object files, and one older preserved `map-values.json` only as a format sanity check.

The daemon's raw map snapshot cost for one active program is:

```text
sum(snapshot maps) entries_scanned * (key_size + lookup_value_size)
```

where `lookup_value_size` is `value_size` for ordinary maps and `round_up_8(value_size) * possible_cpu_count` for percpu maps. In this environment `/sys/devices/system/cpu/possible` is `0-23`, so the static estimate below uses 24 possible CPUs.

Largest direct Tetragon maps visible from BTF, using full-map upper bounds:

| map | type | max_entries | key_size | value_size | lookup value size | raw full snapshot |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| `tg_cgrps_tracking_map` | hash | 32768 | 8 | 144 | 144 | 4.75 MiB |
| `data_heap` | percpu_array | 1 | 4 | 32768 | 786432 | 0.75 MiB |
| `process_call_heap` | percpu_array | 1 | 4 | 25712 | 617088 | 0.59 MiB |
| `string_maps_heap` | percpu_array | 1 | 4 | 16384 | 393216 | 0.38 MiB |
| `tg_stats_map` | percpu_array | 1 | 4 | 14336 | 344064 | 0.33 MiB |
| `tg_mbset_map` | hash | 1024 | 256 | 8 | 8 | 0.26 MiB |
| `tg_execve_joined_info_map` | lru_hash | 8192 | 8 | 16 | 16 | 0.19 MiB |
| `execve_msg_heap_map` | percpu_array | 1 | 4 | 6224 | 149376 | 0.14 MiB |
| `execve_map_update_data` | array | 1 | 4 | 131080 | 131080 | 0.13 MiB |
| `buffer_heap_map` | percpu_array | 1 | 4 | 4352 | 104448 | 0.10 MiB |

Those direct static maps alone do not explain 53 GiB as pure payload. Even a large direct-map working set of about 8 MiB raw per program would be about 2.2 GiB raw for 287 programs, or about 35-40 GiB only after assuming all programs are retained and applying a very high 16-18x representation/allocator factor. HEAD code disproves the "all 287 retained" part.

The actual daemon memory multiplier is nevertheless large:

- Raw snapshot bytes are stored in `Vec<u8>` keys and `Vec<u8>` values inside per-map `BTreeMap`s.
- The daemon then constructs `MapValuesJson`, hex-encoding every key and value into `String`s while the raw `Vec<u8>` data is still live.
- `serde_json` streams that structure to disk, but the fully materialized hex payload already exists in daemon memory before serialization starts.
- `rayon` runs several program optimizations concurrently, so this peak is multiplied by active workers, not by 287.
- Map-in-map recursion can expand one program's snapshot beyond the direct maps listed above because inner maps are discovered from live outer-map values and are snapshotted too. There is no cross-program or cross-worker sharing by map ID.

With the observed RSS, the required per-active-worker footprint is:

| active workers | RSS per active program needed to reach 50.85 GiB |
| ---: | ---: |
| 16 | 3.18 GiB |
| 8 | 6.36 GiB |
| 4 | 12.71 GiB |
| 2 | 25.43 GiB |
| 1 | 50.85 GiB |

This rules out "small maps plus ordinary Rust overhead" as the whole story. Tens of MiB of real map data inflated 10-20x cannot reach 53 GiB unless many active workers, repeated map-in-map expansion, and allocator RSS high-water retention are also present.

Hypothesis estimates:

- Hypothesis 1, linear per-prog map snapshot duplication: true as per-active-program duplication, false as "all 287 snapshots are held concurrently." HEAD uses per-program deep copies with no sharing, but concurrency is bounded by the Rayon worker pool.
- Hypothesis 2, Rust data-structure overhead: contributing factor, not sufficient alone. The overhead comes from `Vec<u8>` allocation per key/value, tree nodes, cloned hex `String`s, and JSON serialization. It plausibly turns hundreds of MiB of active raw snapshot bytes into multiple GiB, but it does not turn tens of MiB total into 53 GiB by itself.
- Hypothesis 3, leak/not-released snapshots: no logical leak is visible in HEAD. Snapshot containers are local to one program's `write_live_map_values` call and are not stored in daemon results. However, allocator high-water behavior can leave the daemon RSS high after large transient allocations, making the process look leak-like under a long parallel run.
- Hypothesis 4, other: the best fit is per-active-program snapshot duplication plus transient raw/hex double representation, map-in-map recursive expansion, Rayon fanout, and allocator RSS retention. `bpfopt` also deserializes and clones the full JSON in its child process, but the OOM victim RSS was the daemon, so child memory is secondary system pressure rather than the daemon's 53 GiB RSS.

## 2. Code citations

All source references are from `HEAD` (`e3c3388b`), not the dirty working tree.

- `daemon/src/main.rs:21-24`: daemon entrypoint only calls `server::cmd_serve(SOCKET_PATH)`.
- `daemon/src/server.rs:33-64`: the socket server accepts and handles one client inline. There is no request-level thread fanout.
- `daemon/src/server.rs:66-94`: `handle_client` processes request lines serially.
- `daemon/src/server.rs:271-286`: `execute_plan` dispatches to `commands::try_execute_plan`.
- `daemon/src/server.rs:292-314`: the server stores `OptimizeOneResult` values until JSON response serialization, but those results do not contain map snapshots.
- `daemon/src/commands.rs:276-286`: default worker count is CPU-derived and capped at 16.
- `daemon/src/commands.rs:399-424`: `try_apply_programs_with` builds a Rayon pool and executes `prog_ids.par_iter()`. This proves program optimization is parallelized, but bounded by the worker pool rather than all 287 programs at once.
- `daemon/src/commands.rs:450-468`: `try_execute_plan` clones only plan steps by program ID before invoking the per-program Rayon loop.
- `daemon/src/commands.rs:470-508`: `execute_one` creates a per-program `WorkDir`. On success it returns without archiving the workdir; on error it tars the workdir.
- `daemon/src/commands.rs:321-335`: `tar_workdir` captures `tar` stdout into memory and base64-encodes it. This can be expensive on errors, but it is not the dominant tetragon OOM path because the daemon died before returning tetragon results.
- `daemon/src/commands.rs:527-587`: `run_program_steps` invokes `write_live_map_values` only when a pass references `${MAP_VALUES}`. The map snapshot is constructed inside one program's optimization path.
- `daemon/src/commands.rs:568-586`: the live map-value snapshot is written before pass execution. The snapshot variables do not escape through `OptimizeOneResult`.
- `daemon/src/commands.rs:948-1048`: `write_live_map_values` owns local `map_metadata`, `entries_by_map`, `entries_partial_by_map`, `queue`, and `scanned` containers. It opens each used map, scans keys, looks up values, queues inner maps, and inserts deep-copied keys and values into `BTreeMap`s. There is no `Arc`, `Rc`, process-wide cache, or sharing by map ID.
- `daemon/src/commands.rs:963-972`: the per-call map snapshot containers are created as local variables.
- `daemon/src/commands.rs:974-1030`: every scanned key is copied into `MapKeySnapshot`, and every non-null value is copied into `MapValueSnapshotEntry { value: Some(Vec<u8>), ... }`.
- `daemon/src/commands.rs:1051-1092`: `write_map_values_snapshot` constructs `MapValuesJson` in memory, including hex `String`s for keys and values, before writing JSON to disk. Raw snapshot bytes and hex JSON fields coexist transiently.
- `daemon/src/commands.rs:1377-1382`: `write_json_file` uses `serde_json::to_writer_pretty`, so the daemon is not intentionally buffering a second complete JSON file; the important in-memory copy is the already-built `MapValuesJson` payload.
- `daemon/src/commands.rs:255-264`: map entries are represented as `Vec<Vec<u8>>` keys and `Option<Vec<u8>>` values, which means per-entry heap allocations.
- `daemon/src/commands.rs:338-342`: map lookup uses `bpf_map_lookup_value_size`, so percpu map values are expanded before allocation.
- `daemon/src/bpf.rs:930-956`: `bpf_map_lookup_elem_optional` allocates `vec![0u8; value_size]` for every looked-up value and returns that `Vec<u8>`.
- `daemon/src/bpf.rs:958-970`: `bpf_map_get_next_key` allocates a fresh `Vec<u8>` for every key.
- `daemon/src/bpf.rs:973-979`: `bpf_map_lookup_value_size` multiplies percpu map value size by possible CPU count after 8-byte rounding.
- `daemon/src/bpf.rs:1004-1019`: possible CPU count comes from `/sys/devices/system/cpu/possible`.
- `daemon/src/commands.rs:344-385`: map key scans keep a `Vec<Vec<u8>>` of all scanned keys up to `max_entries`, so array-like maps and full hash maps can materialize all entries.
- `daemon/src/commands.rs:1155-1174`: only hash, array, percpu array, lru hash, array-of-maps, and hash-of-maps are snapshotted. Map-in-map outer maps are included.
- `daemon/src/bpf.rs:92-123`: `live_program_bytecode_snapshots` snapshots all live program bytecode for writable-map detection per target program. This is another per-program no-sharing input, but it is likely smaller than map values.
- `daemon/Cargo.toml:16-18` and `daemon/Cargo.toml:24-31`: daemon dependencies include `rayon`, `serde_json`, and ordinary collection/serialization crates. There is no mmap-backed or shared map-snapshot storage crate.
- `bpfopt/crates/bpfopt/src/main.rs:235-263`: `bpfopt` receives map snapshots as JSON structs with `entries: Vec<MapEntryJson>`.
- `bpfopt/crates/bpfopt/src/main.rs:572-587`: `attach_program_inputs` attaches decoded map metadata and map values to the `BpfProgram`.
- `bpfopt/crates/bpfopt/src/main.rs:1062-1123`: `read_map_values` deserializes the full JSON and decodes each hex key/value into `HashMap<(u32, Vec<u8>), Vec<u8>>` and related collections.
- `bpfopt/crates/bpfopt/src/pass.rs:86-132`: `BpfProgram` stores decoded map values as owned hash maps and sets.
- `bpfopt/crates/bpfopt/src/pass.rs:211-243`: snapshot lookups clone keys for lookup and clone values on return.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1511-1536`: map-inline runtime-key analysis clones matching map entries into `RuntimeMapEntry` values.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1934-2085`: the direct pseudo-map-value path keeps a pass-local cache of cloned snapshot values.

## 3. Verdict

Dominant cause: hypothesis 1, but in the corrected form "linear per-active-program map snapshot duplication with no inter-program sharing," amplified by raw/hex double representation, map-in-map expansion, and allocator RSS high-water behavior.

Confidence: medium-high for the code-level cause, medium for the numeric size attribution.

The code proves there is no daemon result vector holding 287 completed map snapshots, and it does not show a logical lifetime leak where snapshots survive past a program's optimization result. It also proves that every active Rayon worker can independently deep-copy the same live maps, recursively include inner maps, and then duplicate the raw bytes into hex JSON while the raw containers remain live. That is the only HEAD path that matches a 53 GiB daemon RSS during `map_inline`.

The missing tetragon `used_maps` data prevents a precise map-by-map reconstruction for the failed run. Static direct-map sizes alone are too small to explain 53 GiB, which points to the combination of concurrent per-program duplication, inner-map recursion, representation inflation, and allocator retention rather than a single enormous ordinary map.

## 4. Fix dimensions, not solutions

The fix should attack these dimensions, without excluding programs from ReJIT and without choosing a concrete threshold here:

- Per-program scope: reduce how long raw snapshot containers and derived serialization buffers coexist in one program's optimization path.
- Sharing: avoid repeatedly materializing identical map snapshots for different programs that reference the same live map IDs or inner map IDs.
- Data representation: reduce owned `Vec<u8>`/`String` duplication, especially raw bytes plus hex JSON at the same time.
- Map-in-map accounting: make recursive inner-map snapshot cost explicit and bounded by policy rather than invisible inside each program worker.
- Concurrency: backpressure snapshot-heavy work so memory peak is controlled by bytes in flight, not only by Rayon worker count.
- Snapshot admission policy: define a fail-fast, visible behavior for map snapshots that exceed resource policy; do not silently skip ReJIT or hide the failure.
- Allocator/RSS behavior: ensure large transient allocations are released at useful boundaries or isolated so daemon RSS does not retain the peak across the corpus.
- Child process pressure: account for `bpfopt`'s full JSON deserialize/decode and map-inline cloning as system memory pressure even though the killed RSS belonged to the daemon.
