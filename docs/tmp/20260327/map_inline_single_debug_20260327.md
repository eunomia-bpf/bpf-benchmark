# map_inline single-file debug

Date: 2026-03-26

## Commands run

1. `source /home/yunwei37/workspace/.venv/bin/activate && make daemon`
2. `cargo run --manifest-path daemon/Cargo.toml --release -- rewrite --btf-custom-path vendor/linux-framework/vmlinux --passes map_inline,const_prop,dce --debug corpus/build/katran/xdp_pktcntr.bpf.o 2>&1`
3. `cargo run --manifest-path daemon/Cargo.toml --release -- rewrite --btf-custom-path vendor/linux-framework/vmlinux --passes map_inline,const_prop,dce --debug corpus/build/bcc/libbpf-tools/tcplife.bpf.o 2>&1 | head -100`
4. `cargo test --manifest-path daemon/Cargo.toml test_map_inline_real_katran_xdp -- --nocapture`
5. `llvm-objdump -dr corpus/build/katran/xdp_pktcntr.bpf.o`
6. `llvm-objdump -dr corpus/build/bcc/libbpf-tools/tcplife.bpf.o`

Artifacts saved under `docs/tmp/20260327/`:

- `xdp_pktcntr_map_inline_debug.log`
- `tcplife_map_inline_debug_head100.log`
- `tcplife_direct_rewrite_error.log`
- `rewrite_passes_after_subcommand_error.log`
- `debug_flag_error.log`
- `daemon_help.txt`
- `daemon_rewrite_help.txt`
- `xdp_pktcntr.objdump.txt`
- `tcplife.objdump.txt`
- `test_map_inline_real_katran_xdp.log`

## Findings

### 1. The exact CLI in the prompt never reaches `map_inline`

The Katran run fails in argument parsing before the pass pipeline starts:

- `docs/tmp/20260327/xdp_pktcntr_map_inline_debug.log:487-494` shows:
  - the exact `cargo run ... rewrite ... xdp_pktcntr.bpf.o` command
  - `error: unexpected argument '--btf-custom-path' found`
  - `Usage: bpfrejit-daemon rewrite <PROG_ID>`

The current CLI shape confirms why:

- `daemon/src/main.rs:29-79` defines only top-level options plus `Rewrite { prog_id: u32 }`
- `docs/tmp/20260327/daemon_help.txt:15-40` shows top-level options are `--passes`, `--list-passes`, `--no-rollback`, `--pgo`, `--pgo-interval-ms`
- `docs/tmp/20260327/daemon_rewrite_help.txt:1-9` shows `rewrite` accepts only `<PROG_ID>`

Additional parser checks:

- `docs/tmp/20260327/rewrite_passes_after_subcommand_error.log:1-7` shows `rewrite --passes map_inline 0` is also rejected
- `docs/tmp/20260327/debug_flag_error.log:1-5` shows `--debug` is not a valid current CLI flag
- `rg -n "btf-custom-path|--debug" daemon/src` returned no matches

Conclusion: the current daemon has no object-path rewrite mode, no `--btf-custom-path` flag, and no `--debug` flag. The prompt command is incompatible with the current binary.

### 2. `cmd_rewrite()` is live-program-only and does not print pass diagnostics

`cmd_rewrite()` does not load a `.bpf.o`. It fetches a live kernel program by numeric ID:

- `daemon/src/commands.rs:555-580`
  - `bpf::get_orig_insns_by_id(prog_id)?`
  - `bpf::bpf_prog_get_fd_by_id(prog_id)?`
  - `program.set_map_ids(bpf::bpf_prog_get_map_ids(fd.as_raw_fd()).unwrap_or_default())`

It also does not print `PassResult.diagnostics`:

- `daemon/src/commands.rs:586-592` prints only `sites_applied` and `sites_skipped`
- `daemon/src/commands.rs:595-610` prints `nothing to rewrite` or the rewritten instructions

The structured debug JSON path exists only in `apply`, not in `rewrite`:

- `daemon/src/commands.rs:620-623` calls `emit_debug_result(&result)` from `cmd_apply()`

Conclusion: even for a valid live `rewrite <PROG_ID>` invocation, current `rewrite` would not print the per-site `map_inline` diagnostics the prompt expected.

### 3. `map_inline` requires live map metadata and live map value reads

`map_inline` depends on `branch_targets` and `map_info`:

- `daemon/src/passes/map_inline.rs:158-165`

Its `run()` method requires resolved map metadata at each pseudo-map load site:

- `daemon/src/passes/map_inline.rs:179-197`
  - if no reference exists: skip reason `map reference metadata unavailable`
  - if the reference exists but `info` is missing: skip reason `map info unavailable`

Map metadata comes from `program.map_ids` and live map lookups:

- `daemon/src/analysis/map_info.rs:104-116`
  - `MapInfoAnalysis.run()` calls `collect_map_references(&program.insns, &program.map_ids, resolve_live_map_info)`
- `daemon/src/analysis/map_info.rs:183-192`
  - `resolve_live_map_info()` calls `bpf::bpf_map_get_info_by_id(map_id)`

Map values are read through kernel map syscalls:

- `daemon/src/passes/map_inline.rs:473-485`
  - `build_site_rewrite()` calls `bpf::bpf_map_lookup_elem_by_id(info.map_id, ...)`
- `daemon/src/bpf.rs:506-516`
  - `bpf_map_get_info_by_id()` opens a live map by ID
- `daemon/src/bpf.rs:575-596`
  - `bpf_map_lookup_elem_by_id()` opens the live map and calls `BPF_MAP_LOOKUP_ELEM`

Conclusion: current `map_inline` is not object-only. It needs `program.map_ids`, then live kernel map info, then live kernel map value bytes.

### 4. Offline `.bpf.o` support exists today only in tests

The repo does have an offline fixture path, but only under `#[cfg(test)]`:

- `daemon/src/test_utils.rs:32-57`
  - `into_program_with_synthetic_maps()` installs synthetic maps and calls `program.set_map_ids(map_ids)`
- `daemon/src/bpf.rs:507-510` and `daemon/src/bpf.rs:577-593`
  - test-only mock-map fast paths exist inside `bpf_map_get_info_by_id()` and `bpf_map_lookup_elem_by_id()`
- `daemon/src/passes/mod.rs:991-1013`
  - `run_real_case(..., with_maps = true, ...)` feeds real `.bpf.o` fixtures into the pipeline with synthetic maps
- `daemon/src/passes/mod.rs:1074-1082`
  - `test_map_inline_real_katran_xdp` explicitly expects `map_inline` to change `katran/xdp_pktcntr.bpf.o`

Verification:

- `docs/tmp/20260327/test_map_inline_real_katran_xdp.log:100-103` shows `test_map_inline_real_katran_xdp ... ok`

Conclusion: offline fixture rewriting is currently test-only. The CLI does not expose this path.

### 5. Katran `xdp_pktcntr.bpf.o` definitely contains map lookup sites

`llvm-objdump` on the object shows two `bpf_map_lookup_elem` helper calls:

- `docs/tmp/20260327/xdp_pktcntr.objdump.txt:12-17`
  - `r1 = ... ctl_array`
  - `call 0x1`
  - immediate null check
  - fixed load `r1 = *(u32 *)(r0 + 0x0)`
- `docs/tmp/20260327/xdp_pktcntr.objdump.txt:20-26`
  - `r1 = ... cntrs_array`
  - `call 0x1`
  - load/add/store through the returned pointer

The ELF parser test also identifies the map types:

- `daemon/src/elf_parser.rs:1039-1046`
  - `ctl_array` is map type `2` with value size `4`
  - `cntrs_array` is map type `6` with value size `8`
- `daemon/src/analysis/map_info.rs:13-17`
  - type `2` is `ARRAY`
  - type `6` is `PERCPU_ARRAY`

Implications for `map_inline`:

- `ctl_array` is an `ARRAY`, which is inlineable (`supports_direct_value_access()` / `is_inlineable_v1()`)
- `cntrs_array` is a `PERCPU_ARRAY`, which is deliberately not inlineable

So for Katran, the likely per-site behavior is:

- site at call PC 7 (`ctl_array`): inlineable candidate
- site at call PC 15 (`cntrs_array`): skip because map type 6 is not inlineable in v1

### 6. Katran's first site matches the pass pattern; the second does not

From the object code:

- first lookup:
  - constant key `0` stored on stack
  - immediate null check
  - one fixed load from `r0 + 0`
- second lookup:
  - constant key `0` stored on stack
  - returned pointer is used for load, arithmetic, and store

This matches the pass rules:

- `daemon/src/passes/map_inline.rs:211-223`
  - constant-key extraction is required
- `daemon/src/passes/map_inline.rs:260-277`
  - only fixed-offset scalar loads from `r0` are eligible
- `daemon/src/passes/map_inline.rs:1083-1128`
  - any non-load use of `r0` is tracked as `other_uses`

Therefore:

- the first `ctl_array` lookup should inline when map metadata/value bytes are available
- the second `cntrs_array` lookup would not inline even if it were not `PERCPU_ARRAY`, because the returned pointer is used beyond fixed loads

### 7. BCC `tcplife.bpf.o` also contains map lookup sites, but the CLI still fails before execution

The prompt's `cargo run ... | head -100` case mostly captured Rust warnings, not the parser error:

- `docs/tmp/20260327/tcplife_map_inline_debug_head100.log` contains 100 lines of warnings

Running the already-built binary directly shows the same parser failure as Katran:

- `docs/tmp/20260327/tcplife_direct_rewrite_error.log:1-7`

The object itself does have helper-1 map lookup sites:

- `docs/tmp/20260327/tcplife.objdump.txt:199-215`
  - lookup of `birth`
  - lookup of `idents`

Conclusion: `tcplife` is not failing because it lacks map lookups. It is failing because the current CLI never accepts the `.bpf.o` rewrite invocation.

## Direct answers to the prompt's questions

### Does `map_inline` find `map_lookup_elem` call sites here?

For `xdp_pktcntr.bpf.o`, yes at the object level:

- call PC 7 for `ctl_array`
- call PC 15 for `cntrs_array`

For `tcplife.bpf.o`, yes at the object level:

- call PCs 166 and 177 in the shown slice

For the exact CLI commands in the prompt, no runtime answer is available because the daemon never enters the pass pipeline.

### Does it try to read map values?

Yes, when it reaches `build_site_rewrite()`, it calls `bpf_map_lookup_elem_by_id()`:

- `daemon/src/passes/map_inline.rs:481-485`
- `daemon/src/bpf.rs:575-596`

### What error/skip reason does it give?

For the exact commands run here, the error is not a `map_inline` skip. It is a CLI parse failure:

- unexpected `--btf-custom-path`
- unexpected `--passes` after subcommand
- unexpected `--debug`

If an offline object path were wired up without supplying map IDs/info/values, the likely `map_inline` skips would be:

- `map reference metadata unavailable` or
- `map info unavailable`

If map IDs existed but values were unreadable, the likely skip would be:

- `map lookup failed: ...`

### Is it because in rewrite mode (offline, no kernel), the daemon cannot read live map values?

For the current CLI, the failure happens even earlier: the daemon does not support offline object-file rewrite mode at all.

At a deeper design level, yes: current `map_inline` is built around live map IDs and live `BPF_MAP_LOOKUP_ELEM` reads. The only existing offline path is the unit-test harness, which injects synthetic map IDs and synthetic values under `#[cfg(test)]`.

## Bottom line

The focused debug failure is not "Katran map_inline applied 0." The current daemon never runs `map_inline` on `xdp_pktcntr.bpf.o` because the CLI only supports `rewrite <PROG_ID>` for live kernel programs.

The pass logic itself is not the primary problem:

- the Katran fixture is known-good for `map_inline` in tests
- the first Katran lookup site is a real inlineable array lookup
- the second Katran lookup site is a `PERCPU_ARRAY` and should be skipped

The actual missing piece is runtime plumbing for offline `.bpf.o` execution:

- parse the object
- populate per-program map IDs/info from ELF metadata
- provide value bytes without live kernel maps, or define an explicit synthetic/mock source
- expose an object-path rewrite command that can print `PassResult.diagnostics`
