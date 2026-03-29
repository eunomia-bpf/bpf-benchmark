# llvmbpf Map Relocation Fix Report (2026-03-29)

## Summary

This round did not finish a fresh VM-side verifier sweep because the shared environment was already running other VM benchmark jobs (`vm-corpus` and a tracee e2e guest), and repo policy forbids running verifier/benchmark VMs in parallel with them.

The main implementation result is a new guest-side map relocation reconstruction path for the llvmbpf round-trip verifier helper:

- It rebuilds missing pseudo-map `LD_IMM64` instructions from the original loaded program's `orig_insns`.
- It preserves explicit `old_fd -> map_id` bindings instead of relying on subset-sensitive first-seen order.
- It inserts the rebuilt pseudo-map loads before matched helper calls in the round-trip program and rewrites jump / pseudo-call PCs after insertion.

This is effectively a hybrid Scheme C:

- use the original loaded bytecode as the authoritative map-reference table
- repair the lowered round-trip bytecode just before VM-side `BPF_PROG_LOAD`

I chose this instead of a pure host-side ELF relocation pass because internal global-data maps (`.rodata/.data/.bss`) alias multiple symbols onto the same kernel map, which makes host-only symbol-name reconstruction ambiguous.

## Failure Analysis

I compared several original vs round-trip programs:

- `corpus/build/libbpf-bootstrap/examples/c/bootstrap.bpf.o` / `handle_exec`
- `corpus/build/bcc/libbpf-tools/filelife.bpf.o` / `vfs_unlink_ret`
- `corpus/build/bcc/libbpf-tools/syscount.bpf.o` / `sys_exit`

Representative findings:

1. Original programs still encode map semantics in the loaded bytecode.

   Example from `bootstrap.bpf.o` `handle_exec`:

   - original insn 10: `LD_IMM64 r1, exec_start`
   - original insn 13: `call bpf_map_update_elem#2`

2. The round-trip bytecode loses the map operand and emits scalar zero.

   Same program after round-trip:

   - round-trip insn 15: `r1 = 0`
   - round-trip insn 17: `call 0x2`

3. The same loss appears in real map-heavy programs.

   `filelife` `vfs_unlink_ret`:

   - original: `LD_IMM64 r1, currevent` before `call 0x1` / `call 0x3`
   - round-trip: `r1 = 0` before the same helper calls

   `syscount` `sys_exit`:

   - original: `LD_IMM64 r1, start` / `LD_IMM64 r1, data`
   - round-trip: `r1 = 0` before `call 0x1` / `call 0x2`

4. A pure host-side relocation table extracted from `.bpf.o` is not enough for internal maps.

   In `syscount.bpf.o`, relocations mention symbols like:

   - `filter_cg`
   - `filter_pid`
   - `measure_latency`
   - `count_by_process`
   - `data`
   - `.rodata`

   but the loaded program reports only `map_id_count = 4`, so multiple relocation symbols collapse onto fewer actual kernel maps. That makes a host-only symbol-to-map reconstruction fragile.

## Implementation

Updated:

- `docs/tmp/20260329/llvmbpf_bulk_roundtrip/guest_verify_helper/src/main.rs`

### 1. Explicit map-fd bindings from original loaded bytecode

The helper now scans `orig_insns` for pseudo-map `LD_IMM64` instructions and builds stable:

- `old_fd -> map_id`

bindings from the original program's real map order.

This fixes a subtle issue in the old helper path: if the repaired round-trip bytecode only references a subset of the original maps, first-seen-order relocation can bind the wrong map IDs.

### 2. Helper-map site extraction from original program

The helper now extracts a site list from `orig_insns`:

- pseudo-map `LD_IMM64`
- followed in the same straight-line region by a helper call

For each such site it records:

- helper id
- exact two-insn pseudo-map `LD_IMM64` pair

This keeps the original pseudo source tag intact:

- `BPF_PSEUDO_MAP_FD`
- `BPF_PSEUDO_MAP_VALUE`

### 3. Round-trip repair by insertion

The helper scans the round-trip bytecode for helper calls and greedily matches them against the original helper-map site sequence by helper id.

For each match it inserts the original pseudo-map `LD_IMM64` pair immediately before the matched round-trip helper call.

### 4. Jump / pseudo-call PC rewrite

Because insertion changes instruction indices, the helper rewrites:

- conditional jumps
- `JA`
- `BPF_PSEUDO_CALL`

Targets are remapped to the start of the inserted repair region, so control flow that used to jump directly to a helper call now reaches the inserted pseudo-map load first.

### 5. Repair stats in helper JSON output

The helper now emits a `map_repair` section in its JSON output:

- `explicit_fd_bindings`
- `original_helper_map_sites`
- `matched_helper_map_sites`
- `inserted_ldimm64_pairs`

This is intended to make future bulk reports show whether a verifier improvement actually came from the new repair path.

## Build Validation

Built successfully:

```bash
cargo build --release --manifest-path docs/tmp/20260329/llvmbpf_bulk_roundtrip/guest_verify_helper/Cargo.toml
```

`cargo test` for this standalone helper crate is currently not a useful signal because importing `daemon/src/insn.rs` also imports its test-only `crate::elf_parser` dependency, which is not wired into the helper crate.

## VM Validation Status

I prepared a small manifest subset containing:

- `filelife.bpf.o`
- `syscount.bpf.o`
- `bootstrap.bpf.o`

but did not run it to completion because the environment already had active VM jobs:

- `vm-corpus`
- a tracee e2e guest

Running another verifier VM in parallel would violate repo policy and risk invalid results.

## Expected Impact

The repair path is designed to address the dominant current verifier blocker:

- helper map argument downgraded from `map_ptr` to scalar zero

It should improve verifier acceptance for programs where:

- control flow lowered correctly
- helper IDs survived post-processing
- the remaining verifier rejection is specifically missing pseudo-map load state

It does not yet repair every non-helper map-value use. If helper-site repair alone is not enough to exceed `>20%`, the next extension should target:

- pseudo-map-value loads used for direct memory access, not helper calls

## Next Steps

1. Re-run `run-vm-verify` once the current VM benchmark jobs finish.
2. Check `map_repair` counters on the subset first.
3. If subset results look good, run the full 170-object sweep.
4. Bucket the remaining verifier failures after helper-map repair.
5. If needed, extend the same original-bytecode reconstruction approach to direct map-value loads.
