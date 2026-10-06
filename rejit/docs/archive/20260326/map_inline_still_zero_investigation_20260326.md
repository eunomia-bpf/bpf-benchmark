# map_inline still 0 hits investigation (2026-03-26)

## Short answer

`static_verify` does allow live map metadata lookup and, in principle, live map value reads.

The zero-hit result is not because `static_verify` only opens objects without loading them, and not because `MapInfoAnalysis` is unable to reach kernel maps. The actual path is:

1. `static_verify.py` dispatches `static_verify_object` jobs to the C++ batch runner.
2. `runner/src/batch_runner.cpp` does a real `bpf_object__load()` on each object.
3. The daemon fetches live `map_ids` from the loaded program and attaches them to `BpfProgram`.
4. `MapInfoAnalysis` resolves only map metadata.
5. `map_inline` itself performs the live `BPF_MAP_LOOKUP_ELEM` by map ID, but only after the candidate site passes the earlier pattern/type/use checks.

So the answer to the key question is: yes, static verify mode can read map values, but most real programs never reach that read.

## Findings

### 1. `static_verify` uses real kernel loads, not open-only verification

`daemon/tests/static_verify.py` builds `static_verify_object` jobs and sends them to the batch runner (`daemon/tests/static_verify.py:234-252`, `daemon/tests/static_verify.py:495-520`).

`runner/src/batch_runner.cpp` owns that path, not `runner/src/kernel_runner.cpp`:

- `runner/src/kernel_runner.cpp` contains no `static_verify` path at all.
- `runner/src/batch_runner.cpp:1231-1254` opens the ELF and calls `bpf_object__load(object.get())`.
- `runner/src/batch_runner.cpp:1317-1362` then gets a real program FD and sends the loaded program ID to the daemon.

Conclusion: in static verify mode, programs and maps are really created in the kernel.

### 2. `static_verify` does not populate maps before optimization

I found no map initialization in the static verify path:

- No `bpf_map_update_elem()` in `daemon/tests/static_verify.py`
- No `bpf_map_update_elem()` in `runner/src/batch_runner.cpp`

By contrast, the normal kernel execution path does explicit map setup and some special fixtures:

- `runner/src/kernel_runner.cpp:2258-2274` loads the object and only initializes Katran fixtures for the regular runtime path.
- `runner/src/kernel_runner.cpp:2570-2611` writes `input_map` / `result_map` during actual execution.

So static verify gives the daemon live maps, but usually empty/default ones.

### 3. `MapInfoAnalysis` reads metadata only

`MapInfoAnalysis` does not read map values:

- `daemon/src/analysis/map_info.rs:114-116` runs `collect_map_references(..., resolve_live_map_info)`.
- `daemon/src/analysis/map_info.rs:183-192` resolves only `map_type`, `key_size`, `value_size`, `max_entries`, `frozen`, and `map_id`.

It also only marks a subset of map types as inlineable:

- `daemon/src/analysis/map_info.rs:48-52` allows `HASH`, `ARRAY`, and `LRU_HASH`.
- It deliberately excludes per-CPU maps.

Conclusion: `MapInfoAnalysis` is not the blocker for value visibility; it is just metadata plumbing.

### 4. Live value reads happen inside `map_inline`, after earlier gates

The actual value read happens in `map_inline`:

- `daemon/src/passes/map_inline.rs:160-250` first checks:
  - map metadata exists
  - map type is inlineable
  - key extraction succeeds
  - key width matches
  - speculative cases have an immediate null check
  - the lookup result is only used by fixed-offset scalar loads
- Only then does `daemon/src/passes/map_inline.rs:420-422` call `bpf_map_lookup_elem_by_id(...)`.
- That syscall wrapper is `daemon/src/bpf.rs:575-596`.

The daemon side also wires real map IDs into the program before the pipeline:

- `daemon/src/commands.rs:767-785` fetches `bpf_prog_get_map_ids()` and calls `program.set_map_ids(...)`.
- `daemon/src/bpf.rs:727-775` fetches the live map IDs from the loaded program FD.

Conclusion: static verify absolutely can perform a live map value read. It just usually fails earlier.

## Static verify evidence

Using the current checked-in static verify artifacts:

- Artifact: `daemon/tests/results/static_verify.json`
- Daemon log: `daemon/tests/results/static_verify.daemon.log`

Summary from `static_verify.json`:

- `objects_total=477`
- `programs_total=1178`
- `programs_ok=215`
- `programs_applied=104`
- applied passes include `live_patch`, `const_prop`, `dangerous_helper_firewall`, `endian_fusion`, `wide_mem`, `dce`, `cond_select`, `extract`
- applied `map_inline` count: `0`

Aggregated `map_inline` skip reasons from `static_verify.daemon.log`:

- `lookup key is not a constant stack materialization`: `230`
- `map type 6 not inlineable in v1`: `115`
- `map type 8 not inlineable in v1`: `13`
- `map type 5 not inlineable in v1`: `9`
- `map type 7 not inlineable in v1`: `6`
- `lookup result has non-load uses`: `4`
- `lookup result is not consumed by fixed-offset scalar loads`: `3`

Important negative evidence:

- `map lookup failed: ...`: `0`
- `map info unavailable`: `0`
- `map reference metadata unavailable`: `0`

That means the pass is usually not failing at the actual value-read syscall. It is being rejected earlier on site structure or map-type eligibility.

## Concrete program examples

### Katran `balancer_ingres`

From `daemon/tests/results/static_verify.daemon.log`, `balancer_ingres` has:

- `sites_applied=0`
- `sites_skipped=64`
- skip reasons:
  - `lookup key is not a constant stack materialization`: `14`
  - `map type 6 not inlineable in v1`: `42`
  - `map type 12 not inlineable in v1`: `2`
  - `map type 13 not inlineable in v1`: `2`
  - `lookup result is not consumed by fixed-offset scalar loads`: `2`
  - `lookup result has non-load uses`: `2`

This is consistent with Katran source shape: many lookups target per-CPU or otherwise unsupported maps, and many surviving array/hash lookups still miss the exact constant-key pattern that `map_inline` expects.

### Tetragon `event_execve`

From the same daemon log, `event_execve` has:

- `sites_applied=0`
- `sites_skipped=21`
- skip reasons:
  - `lookup key is not a constant stack materialization`: `6`
  - `map type 6 not inlineable in v1`: `10`
  - `map type 10 not inlineable in v1`: `4`
  - `lookup result has non-load uses`: `1`

Again, this is not a value-read failure. The pass is filtered out before lookup time.

## VM corpus check

I started the requested run:

```bash
make vm-corpus TARGET=x86 REPEAT=10
```

The run was much slower than expected for a "quick" probe, so I interrupted it after live-checking partial progress. Before interruption, the guest-side partial result had reached:

- completed records: `72 / 764`
- applied pass counts so far:
  - `live_patch`: `15`
  - `const_prop`: `6`
  - `dce`: `6`
  - `cond_select`: `1`
  - `endian_fusion`: `1`
- `map_inline`: `0`

Because the run was interrupted, its temporary guest result file was cleaned up by the driver, so there is no durable repo artifact for that exact partial sample. I am recording the observed count here explicitly.

For additional context, the latest completed corpus artifact in the repo was:

- `corpus/results/vm_corpus_20260326_201508/metadata.json`
- that run used `repeat=50`
- it also had no `map_inline` in the applied pass counts

There is also an older preserved guest-batch partial under:

- `docs/tmp/20260326/corpus-rejit-batch/corpus-rejit-vm-batch-result-h3s2y1cf.json`
- it contains `543` completed records and also has `map_inline=0` in applied pass counts

## Bottom line

The current evidence points to this:

1. `static_verify` does create real kernel maps.
2. `map_inline` is capable of reading live map values there.
3. But static verify does not populate maps before optimization.
4. More importantly, zero-hit is usually caused before value-read time by:
   - unsupported map types, especially per-CPU maps
   - failure to recover the constant stack key pattern
   - lookup result uses that are not the narrow fixed-load pattern

So the deeper problem is not "static_verify forbids map value reading." The deeper problem is "real corpus programs rarely satisfy the current `map_inline` matcher and inlineability constraints, so the pass almost never reaches the value read at all."
