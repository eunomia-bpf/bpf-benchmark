# map_inline zero hits in corpus: debug notes

Date: 2026-03-27

## Bottom line

I did **not** find a code path that would make `map_inline` skip just because a map value is all zeros.

I also did **not** find a serve-protocol limitation that would prevent the daemon from reading live map values in corpus mode. In serve mode, the daemon has enough information to do:

1. `prog_id -> prog_fd`
2. `prog_fd -> map_ids`
3. `map_id -> map_fd`
4. `map_fd -> BPF_MAP_LOOKUP_ELEM`

So the observed `0` `map_inline` hits in corpus are **not explained by**:

- zero-valued maps
- missing map FDs in serve mode
- lack of access to original bytecode

The remaining likely explanation is a **live-program-specific skip or rollback** that cannot be proven from host-side code inspection alone because the current corpus artifacts do not retain the per-program `map_inline` skip diagnostics needed to explain the zero count.

## What `map_inline` requires

`MapInlinePass` requires all of the following in [daemon/src/passes/map_inline.rs](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs):

- it must find a `bpf_map_lookup_elem()` helper call and its `LD_IMM64 BPF_PSEUDO_MAP_FD` map load ([map_inline.rs:167-205](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs:167))
- the map type must be inlineable (`ARRAY`, `HASH`, `LRU_HASH` in v1) ([map_inline.rs:205-214](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs:205), [analysis/map_info.rs](/home/yunwei37/workspace/bpf-benchmark/daemon/src/analysis/map_info.rs))
- the lookup key must be a constant stack materialization ([map_inline.rs:240-266](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs:240))
- for speculative maps, it wants an immediate null-check after the helper ([map_inline.rs:284-289](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs:284))
- the helper result must only feed fixed-offset scalar loads ([map_inline.rs:290-307](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs:290))

When all of that matches, it reads the live map value with `bpf_map_lookup_elem_by_id()` and replaces the scalar load users with constants ([map_inline.rs:512-602](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs:512)).

Important: there is **no check for “value is zero, skip”**. The pass simply emits a constant load via `emit_constant_load()`. A zero scalar still becomes a valid `MOV r, 0` style rewrite ([map_inline.rs:573-584](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs:573)).

## What the daemon needs, and whether corpus serve mode has it

Corpus starts a long-lived `daemon serve` socket ([corpus/modes.py:577-579](/home/yunwei37/workspace/bpf-benchmark/corpus/modes.py:577), [corpus/modes.py:1806-1810](/home/yunwei37/workspace/bpf-benchmark/corpus/modes.py:1806)).

The runner sends an `optimize` request with:

- `prog_id`
- optional `passes`

in [runner/src/kernel_runner.cpp:1230-1260](/home/yunwei37/workspace/bpf-benchmark/runner/src/kernel_runner.cpp:1230).

The daemon’s serve handler only needs that `prog_id`; it calls `try_apply_one(prog_id, ...)` ([daemon/src/server.rs:149-175](/home/yunwei37/workspace/bpf-benchmark/daemon/src/server.rs:149)).

Inside `try_apply_one()` the daemon does:

- `bpf_prog_get_fd_by_id(prog_id)` ([commands.rs:730-732](/home/yunwei37/workspace/bpf-benchmark/daemon/src/commands.rs:730))
- `bpf_prog_get_info(..., true)` to fetch original instructions ([commands.rs:731-732](/home/yunwei37/workspace/bpf-benchmark/daemon/src/commands.rs:731))
- `bpf_prog_get_map_ids(fd)` ([commands.rs:810-811](/home/yunwei37/workspace/bpf-benchmark/daemon/src/commands.rs:810))
- `program.set_map_ids(...)` before running passes ([commands.rs:826-828](/home/yunwei37/workspace/bpf-benchmark/daemon/src/commands.rs:826))

The map-value read path is:

- `bpf_map_get_fd_by_id(map_id)` ([daemon/src/bpf.rs:483-496](/home/yunwei37/workspace/bpf-benchmark/daemon/src/bpf.rs:483))
- `bpf_map_lookup_elem_by_id(map_id, key, value_size)` ([daemon/src/bpf.rs:576-596](/home/yunwei37/workspace/bpf-benchmark/daemon/src/bpf.rs:576))

So corpus serve mode **does** have the three required capabilities:

- program map IDs
- map FDs
- live element lookup

## Zero-valued maps are not filtered out

This was the main hypothesis to test. The code does not support it.

`build_site_rewrite()` reads the value bytes and immediately turns the consuming loads into constants ([map_inline.rs:526-583](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/map_inline.rs:526)).

There is no branch equivalent to:

- `if value == 0 { skip }`
- `if all_zero(value) { skip }`

So for an array map whose element exists and is zero-initialized, `map_inline` should still produce a valid constant rewrite.

## Offline rewrite mode: current CLI does not support the requested test

The exact command requested in the task is **not supported by the current daemon CLI**.

`bpfrejit-daemon rewrite` only accepts a live `PROG_ID` ([daemon/src/main.rs:74-79](/home/yunwei37/workspace/bpf-benchmark/daemon/src/main.rs:74), [daemon/src/main.rs:181-183](/home/yunwei37/workspace/bpf-benchmark/daemon/src/main.rs:181)).

I built the daemon with:

```bash
source /home/yunwei37/workspace/.venv/bin/activate && make daemon
```

Then I ran the exact requested command:

```bash
cargo run --manifest-path daemon/Cargo.toml --release -- rewrite --btf-custom-path vendor/linux-framework/vmlinux --passes map_inline,const_prop,dce --debug corpus/build/katran/xdp_pktcntr.bpf.o
```

It failed with:

```text
error: unexpected argument '--btf-custom-path' found
Usage: bpfrejit-daemon rewrite <PROG_ID>
```

So there is currently **no standalone offline `.bpf.o` rewrite CLI** in this tree. The existing offline/object-based path only exists in the daemon’s unit-test harness with synthetic mock maps, not as a user-facing command.

## Katran `xdp_pktcntr` is a real candidate

The test fixture object and the corpus-built object are byte-for-byte identical.

I compared:

- `daemon/tests/fixtures/katran/xdp_pktcntr.bpf.o`
- `corpus/build/katran/xdp_pktcntr.bpf.o`

and their SHA-256 hashes match.

The object contains:

- a `ctl_array` lookup with constant key `0`
- an immediate null check
- a fixed-offset scalar load from `r0`

and then a second lookup into `cntrs_array` (a percpu array, which is not inlineable).

That means the first site is exactly the kind of site `map_inline` is intended to rewrite. So the lack of corpus hits is **not** because the corpus object is missing an obvious candidate.

## One concrete harness issue I found

In the prepared compile path used by object-batch execution, `build_prepared_program_compile_sample()` applies daemon REJIT but does **not** load fixtures first ([runner/src/kernel_runner.cpp:2313-2345](/home/yunwei37/workspace/bpf-benchmark/runner/src/kernel_runner.cpp:2313)).

By contrast, the non-prepared single-run path loads fixtures before daemon optimize ([runner/src/kernel_runner.cpp:3016-3019](/home/yunwei37/workspace/bpf-benchmark/runner/src/kernel_runner.cpp:3016)).

Implication:

- fixture-dependent compile-time map inlining can be missed in prepared/object-batch corpus mode

This does **not** explain `xdp_pktcntr` specifically, because that case should still inline from a zero-initialized array map, but it is a real corpus-path discrepancy.

## Proposed fix

1. Add a real offline object rewrite command to the daemon.
   It should accept `.bpf.o`, program name, optional synthetic map seed data, and `--debug`.

2. Preserve per-program `map_inline` evidence in corpus artifacts.
   At minimum:
   - `inlined_map_entries`
   - per-pass diagnostics / skip reasons
   - final disabled passes after rollback

3. Load fixtures before daemon optimize in the prepared compile path.
   That closes a real discrepancy between single-run and corpus object-batch execution.

4. Add a regression test for zero-valued array maps.
   The expected result should be that `map_inline` still fires and emits zero constants.

## Root-cause statement

Based on code inspection, the root cause of `0` `map_inline` hits in corpus is **not**:

- a zero-value special-case skip
- lack of map FDs / map values in serve mode
- missing original bytecode in serve mode

What remains unresolved without a VM run is **which live-program-specific skip/rollback path is actually happening in corpus**, including the expected `xdp_pktcntr` case. The current corpus outputs do not preserve enough `map_inline` diagnostics to answer that last part from artifacts alone.
