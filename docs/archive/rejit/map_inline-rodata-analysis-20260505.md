# map_inline .rodata/.data analysis - 2026-05-05

## Executive summary

- Current `map_inline` is not helper-only. It has one path for `bpf_map_lookup_elem()` result loads and a separate path for direct `BPF_LD_IMM64 | BPF_PSEUDO_MAP_VALUE` / `BPF_PSEUDO_MAP_IDX_VALUE` loads from global-data maps (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:117-137`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1243-1339`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1833-1942`).
- Current `map_inline` accepts `BPF_MAP_TYPE_ARRAY`, so `.rodata`'s `ARRAY + BPF_F_RDONLY_PROG` map type is in scope by type. It does not check `BPF_F_RDONLY_PROG`, `map->frozen`, or a userspace freeze bit because the bpfopt `MapInfo` omits flags/frozen state (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:20-33`, `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:47-60`).
- The kernel verifier does know frozen read-only map values. For direct `PTR_TO_MAP_VALUE` reads, it calls `bpf_map_direct_read()` and marks the destination register known when the map has `BPF_F_RDONLY_PROG`, is frozen, has no active writers, and supports `map_direct_value_addr` (`vendor/linux-framework/kernel/bpf/verifier.c:7503-7521`, `vendor/linux-framework/kernel/bpf/verifier.c:8060-8078`). It can then take only the live branch and later hard-wire/remove dead code for privileged programs (`vendor/linux-framework/kernel/bpf/verifier.c:17868-17910`, `vendor/linux-framework/kernel/bpf/verifier.c:22647-22670`, `vendor/linux-framework/kernel/bpf/verifier.c:26501-26507`).
- The saved `bcc/syscount` result shows the daemon optimized already-folded 14/44-instruction programs, while the object file has 31/120 instructions in `sys_enter`/`sys_exit` with direct `.rodata` loads. That strongly supports interpretation (a): in that artifact, `map_inline` did not see the `.rodata` filter loads as candidate sites; they were already gone from the code it optimized (`corpus/results/x86_kvm_corpus_20260505_072912_434124/details/apps/bcc__syscount.json:75`, disassembly below).
- `.data` / `.bss` direct global inlining is not safely complete. The current direct pseudo-map-value path would constantize any snapshot-backed direct load, but it does not emit `MapInlineRecord`s, so the daemon invalidation tracker has no dependency to watch for direct global-data inlines (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1243-1339`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:953-956`, `daemon/src/invalidation.rs:86-107`).

## Current map_inline scope

Map types: the pass's metadata layer treats `HASH`, `ARRAY`, `PERCPU_ARRAY`, and `LRU_HASH` as supporting direct value access (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:47-55`). Lookup/null-check removal is narrower: only `ARRAY` and `PERCPU_ARRAY` are unconditionally removable (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:62-68`), while `HASH` and `LRU_HASH` are speculative and need an immediate null check (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:70-73`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:814-817`). `PERCPU_HASH` and `LRU_PERCPU_HASH` are excluded; the test asserts they skip as "not inlineable" (`bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1754-1790`). Because `.rodata` is an `ARRAY` map with `BPF_F_RDONLY_PROG`, it is accepted by type, but the flag is not part of `MapInfo` (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:20-33`).

Patterns: helper lookup matching starts at `find_map_lookup_sites()`, which looks for helper call `imm == 1` (`bpf_map_lookup_elem`) and a preceding pseudo-map FD/IDX load into `r1` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:117-137`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1488-1502`). Separately, `build_direct_map_value_load_rewrites()` scans all `LDX` memory instructions, resolves the source register back to a pseudo-map-value pointer, reads key `0`, and replaces the load with a constant (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1243-1339`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1833-1942`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2408-2410`). The direct path is covered by tests for both FD-value and IDX-value pseudo forms (`bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:352-394`).

The "mutated by kernel-side BPF program" skip is not a map type or freeze check. It is a daemon-side filter before bpfopt sees map values: `write_live_map_values()` skips a map if `bpf_mutated` contains its map id (`daemon/src/commands.rs:1115-1141`). `bpf_mutated` is computed by enumerating loaded BPF programs, detecting helper calls to map update/delete/push/pop, and then adding every map used by any such program (`daemon/src/commands.rs:1234-1258`, `daemon/src/commands.rs:1261-1295`). I found no unit test for the exact "mutated by kernel-side BPF program" string; the existing skipped-map tests cover scan overflow (`daemon/src/commands.rs:2056-2125`).

`map_inline` does not require `map_freeze`. The daemon snapshot carries `map_flags` from `bpf_map_info` (`daemon/crates/bpfget/src/lib.rs:36-60`, `daemon/crates/bpfget/src/lib.rs:226-248`), but `write_live_map_values()` filters only by map type and kernel-side mutation (`daemon/src/commands.rs:1131-1141`, `daemon/src/commands.rs:1298-1306`). Therefore un-frozen but currently stable `.data` / `.bss` `ARRAY` maps can be fed to bpfopt. Helper-lookup inlines produce `MapInlineRecord`s for invalidation tracking (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1213-1225`, `daemon/src/commands.rs:943-952`); direct pseudo-map-value inlines currently do not.

## BPF compilation of .rodata access

The source file referenced by DWARF debug info is not present at `runner/repos/bcc/libbpf-tools/syscount.bpf.c` in this checkout, but the object has line records for it. The object has `.rodata` and `.maps` sections; `.rodata` is alloc-only, `.maps` is writable/alloc (`llvm-readelf -S corpus/build/x86_64/bcc/libbpf-tools/.output/syscount.bpf.o`):

```text
[ 7] .rodata           PROGBITS        0000000000000000 0004f8 000030 00   A  0   0  8
[ 8] .maps             PROGBITS        0000000000000000 000528 000060 00  WA  0   0  8
```

The symbol table places the filters in `.rodata`: `filter_cg` at offset 0, `filter_pid` at 8, and the other booleans/integers nearby. It places `cgroup_map`, `start`, and `data` in `.maps` (`llvm-readelf -s corpus/build/x86_64/bcc/libbpf-tools/.output/syscount.bpf.o`):

```text
20: 0000000000000000     1 OBJECT  GLOBAL DEFAULT     7 filter_cg
22: 0000000000000008     4 OBJECT  GLOBAL DEFAULT     7 filter_pid
25: 0000000000000003     1 OBJECT  GLOBAL DEFAULT     7 filter_failed
26: 0000000000000004     4 OBJECT  GLOBAL DEFAULT     7 filter_errno
27: 0000000000000002     1 OBJECT  GLOBAL DEFAULT     7 measure_latency
28: 0000000000000001     1 OBJECT  GLOBAL DEFAULT     7 count_by_process
21: 0000000000000000    32 OBJECT  GLOBAL DEFAULT     8 cgroup_map
23: 0000000000000020    32 OBJECT  GLOBAL DEFAULT     8 start
29: 0000000000000040    32 OBJECT  GLOBAL DEFAULT     8 data
```

`filter_pid` is not compiled as `bpf_map_lookup_elem(&rodata, key)`. It is compiled as a direct pseudo-map-value relocation: `LD_IMM64` to a map-value pointer, followed by scalar `LDX` from that pointer. In `sys_enter`, line 63 emits two loads from the same rodata pointer:

```text
; .../syscount.bpf.c:63
      12: 18 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 r1 = 0x0 ll
      14: 61 12 00 00 00 00 00 00                         r2 = *(u32 *)(r1 + 0x0)
; .../syscount.bpf.c:63
      15: 15 02 03 00 00 00 00 00                         if r2 == 0x0 goto +0x3 <LBB0_4>
      16: 77 06 00 00 20 00 00 00                         r6 >>= 0x20
; .../syscount.bpf.c:63
      17: 61 11 00 00 00 00 00 00                         r1 = *(u32 *)(r1 + 0x0)
      18: 5d 61 0a 00 00 00 00 00                         if r1 != r6 goto +0xa <LBB0_5>
```

The relocation table identifies instruction offset `0x60` (PC 12) as `filter_pid`, whose symbol value is `.rodata+0x8`:

```text
Relocation section '.reltracepoint/raw_syscalls/sys_enter'
0000000000000060  ... R_BPF_64_64  0000000000000008 filter_pid
```

`sys_exit` has the same direct form for `filter_pid`, `filter_failed`, `filter_errno`, `measure_latency`, and `count_by_process`; helper lookups are only for real maps such as `start` and `data`:

```text
; .../syscount.bpf.c:89
      14: 18 01 ... 00 00 00 00                           r1 = 0x0 ll
      16: 61 12 00 00 00 00 00 00                         r2 = *(u32 *)(r1 + 0x0)
...
; .../maps.bpf.h:31
      66: 18 01 ... 00 00 00 00                           r1 = 0x0 ll
      68: 85 00 00 00 01 00 00 00                         call 0x1
```

For a `.bss` example, `tcpconnect.bpf.o` has `.bss` as a separate writable/alloc NOBITS section and `.rodata` filters in section 11 (`llvm-readelf -S corpus/build/x86_64/bcc/libbpf-tools/.output/tcpconnect.bpf.o`). Its direct global reads use the same `LD_IMM64 + LDX` form; e.g. `filter_pid` at `tcpconnect.bpf.c:74`:

```text
; .../tcpconnect.bpf.c:74
       4: 18 01 ... 00 00 00 00                           r1 = 0x0 ll
       6: 61 12 00 00 00 00 00 00                         r2 = *(u32 *)(r1 + 0x0)
       7: 15 02 03 00 00 00 00 00                         if r2 == 0x0 goto +0x3 <LBB0_2>
```

I found no `.data` section in the supported x86 corpus objects during this scan; the only local `.data` section found was under removed `scx` (`corpus/build/x86_64/scx/scx_rusty_main.bpf.o`), so I did not use it as a supported-app example.

## Kernel verifier const-fold behavior

The verifier has explicit readonly-map detection:

```c
/* vendor/linux-framework/kernel/bpf/verifier.c:7503-7521 */
static bool bpf_map_is_rdonly(const struct bpf_map *map)
{
	return (map->map_flags & BPF_F_RDONLY_PROG) &&
	       READ_ONCE(map->frozen) &&
	       !bpf_map_write_active(map);
}
```

For `PTR_TO_MAP_VALUE` direct reads, the verifier reads the backing map value and marks the destination scalar known:

```c
/* vendor/linux-framework/kernel/bpf/verifier.c:8060-8078 */
if (tnum_is_const(reg->var_off) &&
    bpf_map_is_rdonly(map) &&
    map->ops->map_direct_value_addr &&
    map->map_type != BPF_MAP_TYPE_INSN_ARRAY) {
	int map_off = off + reg->var_off.value;
	u64 val = 0;

	err = bpf_map_direct_read(map, map_off, size, &val, is_ldsx);
	if (err)
		return err;

	regs[value_regno].type = SCALAR_VALUE;
	__mark_reg_known(&regs[value_regno], val);
}
```

`bpf_map_direct_read()` uses `map_direct_value_addr` and copies 1/2/4/8 byte values out of the map (`vendor/linux-framework/kernel/bpf/verifier.c:7523-7551`). `BPF_PSEUDO_MAP_VALUE` itself is recognized as `PTR_TO_MAP_VALUE`, with the map offset stored from the second half of `LD_IMM64` (`vendor/linux-framework/kernel/bpf/verifier.c:18107-18117`). Earlier verifier validation also requires direct value support for pseudo-map-value loads (`vendor/linux-framework/kernel/bpf/verifier.c:22159-22221`).

So the user's suspicion "kernel verifier probably does not fold `.rodata`" is wrong for this kernel: it does track frozen `.rodata` map contents as known scalar values. It also uses known scalar values to decide conditional branch direction (`vendor/linux-framework/kernel/bpf/verifier.c:16982-17028`, `vendor/linux-framework/kernel/bpf/verifier.c:17206-17245`, `vendor/linux-framework/kernel/bpf/verifier.c:17868-17910`). For privileged verification, it then hard-wires and removes dead code (`vendor/linux-framework/kernel/bpf/verifier.c:22647-22695`, `vendor/linux-framework/kernel/bpf/verifier.c:26501-26507`). This is verifier/JIT-time folding, not a bpfopt `map_inline` report event.

## Why bcc corpus shows 0 applies

For `bcc/syscount`, the saved result has two programs. Program 6 reports `insns_before: 14`, `insns_after: 14`, `map_inline sites_applied: 0`, and `skipped_maps: [{map_id:3, reason:"mutated by kernel-side BPF program"}]` inside the daemon output (`corpus/results/x86_kvm_corpus_20260505_072912_434124/details/apps/bcc__syscount.json:75`, `corpus/results/x86_kvm_corpus_20260505_072912_434124/details/apps/bcc__syscount.json:87-103`). Program 7 similarly reports `insns_before: 44`, `sites_applied: 0`, and skipped maps 3 and 2 (`corpus/results/x86_kvm_corpus_20260505_072912_434124/details/apps/bcc__syscount.json:124-140`).

Those instruction counts are already the folded sizes. The object's `sys_enter` section has 31 instructions, and the `.rodata` filter blocks account for the difference; after `filter_cg == 0` and `filter_pid == 0` are folded away, the remaining `sys_enter` code is exactly the 14-instruction path that updates `start`. The object's `sys_exit` section has 120 instructions, while the result says 44; that is likewise consistent with readonly filter folding and dead-code removal.

The `.rodata` map is not in `skipped_maps` because `skipped_maps` is not a list of all maps considered. It is only populated for daemon-side exclusion cases: kernel-side BPF mutation and scan overflow (`daemon/src/commands.rs:1115-1190`). A normal `.rodata` scan would not appear there. The skipped map ids in this artifact are more consistent with the writable maps used by helper updates (`start` in program 6; `start` and `data` in program 7), because the daemon marks maps used by programs containing map-update helpers as unsafe (`daemon/src/commands.rs:1234-1295`).

Verdict on the two interpretations: for this artifact, it is (a) in practice: `map_inline` did not see inlinable `.rodata` load sites in its effective input. The concrete evidence is the daemon's 14/44 instruction input counts versus the object's 31/120 direct-rodata-load instruction streams. The exact temporary bpfopt report and `map-values.json` are not retained in `corpus/results/x86_kvm_corpus_20260505_072912_434124/`, so I cannot cite a saved per-pass diagnostic proving the absence of each PC. But if current `map_inline` had seen the direct pseudo-map-value loads with snapshot values, it would increment `sites_applied`; if it had seen them without snapshot values, the direct path would error on a missing `map_values` key rather than return `status:"ok"` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1294-1339`, `bpfopt/crates/bpfopt/src/pass.rs:205-234`).

## Gap analysis: what classes of inline we're missing

- `.rodata`: semantically safe after freeze and already folded by the kernel verifier for this syscount case. Current bpfopt can constantize direct pseudo-map-value loads, but corpus artifacts may show zero applies because those loads are already gone before bpfopt sees the code. `map_inline` reports do not distinguish "already folded by verifier" from "no site existed" (`corpus/results/x86_kvm_corpus_20260505_072912_434124/details/apps/bcc__syscount.json:97-103`).
- `.bss`: writable global data is an `ARRAY`-style direct map-value access. Current direct path can rewrite it if a snapshot entry exists, but this is unsafe unless invalidation is recorded, because userspace and BPF may write `.bss` after load.
- `.data`: same as `.bss`, except initialized nonzero. Current daemon-side invalidation can track helper-lookup inlines via `MapInlineRecord` (`daemon/src/invalidation.rs:86-107`), but direct pseudo-map-value inlines emit no record and therefore are not covered.
- Helper lookups into mutable hash/array maps: already supported for selected map types with snapshot values. Hash-like maps are marked speculative and tracked; arrays are treated as removable and also recorded for tracking (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:62-73`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1213-1225`).

## Recommended extensions

1. Add explicit direct-global policy. Treat `.rodata` direct pseudo-map-value loads separately from `.data`/`.bss`: require `BPF_F_RDONLY_PROG + frozen` metadata for untracked direct constantization, or otherwise require invalidation tracking. Today bpfopt cannot make that distinction because `MapInfo` lacks flags/frozen (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:20-33`, `daemon/crates/bpfget/src/lib.rs:36-60`).
2. Emit `MapInlineRecord` for direct pseudo-map-value inlines. The record should use key `0` and the full expected global-data map value, so `MapInvalidationTracker` can re-read the map and trigger re-ReJIT if userspace changes `.data` or `.bss` (`daemon/src/invalidation.rs:117-157`).
3. Surface "already verifier-folded" separately in analysis tooling, not framework metrics. Since framework result payloads must remain raw and avoid rollups, this should be a post-hoc diagnostic script that compares object disassembly to daemon `orig_insn_count` / xlated count. Do not add a summary field to `result.json`.
4. Preserve daemon temporary bpfopt reports for failure/smoke forensics only if it fits existing artifact policy. The current syscount result lost the per-pass direct-map diagnostics, making the final step inferential rather than fully observable from saved files.
5. Keep `.data` dynamic inlining under the plan's JVM deopt model: map stable -> inline -> daemon-owned invalidation -> re-ReJIT. The plan already describes this as the intended dynamic map inlining model (`docs/kernel-jit-optimization-plan.md:209-210`), and the v3 design requires daemon-prepared `--map-values` and real verifier-state side inputs (`docs/tmp/bpfopt_design_v3.md:92-102`, `docs/tmp/bpfopt_design_v3.md:124-132`).
