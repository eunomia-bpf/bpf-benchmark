# map_inline C5 evidence audit (2026-05-13)

## Verdict

C5 is exploitable in real corpus: 5 writer-helper call sites make `find_direct_map_load_for_reg_before_site(..., r1)` return `None`, and at least one same-program dynamic-map case (`katran/530_balancer_ingress`) uses the same logical map for `bpf_map_lookup_elem` plus value loads and for the untracked writer.

## Methodology

Context read once:

```sh
sed -n '1,220p' docs/kernel-jit-optimization-plan.md
sed -n '560,640p' bpfopt/crates/bpfopt/src/passes/map_inline.rs
sed -n '2150,2255p' bpfopt/crates/bpfopt/src/passes/map_inline.rs
```

Corpus size check:

```sh
find bpfopt/testbin -path '*/canonicalize_output.bin' | wc -l
```

Scanner:

```sh
python3 - <<'PY'
# inline scanner, not saved in the repo
# - read each canonicalize_output.bin as raw struct bpf_insn[] using struct.unpack_from('<BBhi')
# - treated LD_IMM64 as a 2-slot instruction and skipped the second slot
# - matched helper calls with code 0x85, src_reg == 0, imm in {1,2,3,73,74}
# - collected subprogram frame starts from BPF_PSEUDO_CALL and BPF_PSEUDO_FUNC pc-relative targets
# - implemented the map_inline resolver shape:
#   direct LD_IMM64 map fd/idx, recursive MOV64_REG, recursive fp-relative STX_DW/LDX_DW stack slots,
#   REG_RESOLUTION_LIMIT = 64
# - approximated lookup value-load targets by following r0 aliases after lookup_elem and recording LDX_MEM loads
PY
```

Source/object cross-checks used for the concrete resolver-None cases:

```sh
rg -n "sched_process_free|sched_process_fork|tail_handle_ipv4|balancer_ingress" bpfopt/testccode -S
rg -n "map_update_elem|map_delete_elem|bpf_map_update_elem|bpf_map_delete_elem|lookup_elem" bpfopt/testccode/katran_balancer.bpf.c bpfopt/testccode/tracee_tracee.bpf.c bpfopt/testccode/cilium_bpf_lxc.bpf.c bpfopt/testccode/cilium_bpf_host.bpf.c bpfopt/testccode/cilium_bpf_xdp.bpf.c
llvm-objdump -dr --section=raw_tracepoint/sched_process_free bpfopt/testobject/tracee_tracee.bpf.o
llvm-objdump -dr --section=xdp --start-address=0x46f0 --stop-address=0x47b8 bpfopt/testobject/katran_balancer.bpf.o
```

Important interpretation detail: `canonicalize_output.bin` contains canonical per-program map indexes (`MapPseudo::Idx`) rather than live map IDs. For writer calls where the resolver returns `None`, there is no raw `map_idx` to report by definition. Same-map conclusions below therefore distinguish raw static `map_idx` proof from source/alias proof.

## Statistics

### Writer-helper calls

Scanned 542 programs under `bpfopt/testbin/*/*/canonicalize_output.bin`.

| app | programs | programs w/writer | writer calls | update | delete | push | pop |
|---|---:|---:|---:|---:|---:|---:|---:|
| bcc_set | 21 | 12 | 17 | 10 | 7 | 0 | 0 |
| bpftrace_set | 9 | 7 | 18 | 11 | 7 | 0 | 0 |
| cilium_agent | 53 | 42 | 475 | 452 | 23 | 0 | 0 |
| katran | 1 | 1 | 4 | 4 | 0 | 0 | 0 |
| otelcol-ebpf-profiler_profiling | 13 | 3 | 11 | 9 | 2 | 0 | 0 |
| tetragon_observer | 287 | 207 | 982 | 751 | 231 | 0 | 0 |
| tracee_monitor | 158 | 145 | 371 | 326 | 45 | 0 | 0 |
| **total** | **542** | **417** | **1878** | **1559** | **319** | **0** | **0** |

### r1 resolution shape

`prev insn not map r1` is the intentionally strict approximation requested in the prompt. It overcounts heavily because normal helper setup usually inserts key/value/flag instructions after the map load. `resolver None` is the C5 trigger count matching the current recursive implementation.

| app | writer calls | prev insn not map r1 | prev def not direct map | resolved via mov/stack | resolver None |
|---|---:|---:|---:|---:|---:|
| bcc_set | 17 | 17 | 0 | 0 | 0 |
| bpftrace_set | 18 | 18 | 0 | 0 | 0 |
| cilium_agent | 475 | 455 | 17 | 15 | 2 |
| katran | 4 | 4 | 4 | 3 | 1 |
| otelcol-ebpf-profiler_profiling | 11 | 9 | 0 | 0 | 0 |
| tetragon_observer | 982 | 751 | 0 | 0 | 0 |
| tracee_monitor | 371 | 334 | 3 | 1 | 2 |
| **total** | **1878** | **1588** | **24** | **19** | **5** |

What the implementation can trace:

- Direct `LD_IMM64` map fd/idx into the target register.
- Recursive `MOV64_REG` chains.
- Recursive `LDX_DW [r10 + off]` stack reloads when the matching previous store is `STX_DW [r10 + off] = src`.
- The recursion limit is 64; no budget-exhaustion case appeared in the scan.

Observed `resolver None` causes:

- Helper-return map pointers from map-in-map lookup results.
- Branch/layout sensitivity in `prev_def_in_frame`: the nearest earlier linear definition can be a scalar from another branch, even when the executing path has a map pointer.
- No cross-subprogram parameter case was needed to explain the 5 observed failures.

### Non-direct writer plus same-map inline target

| app | resolver-None writer calls | raw same static `map_idx` proof | same logical map lookup/value target | notes |
|---|---:|---:|---:|---|
| cilium_agent | 2 | 0 | 0 counted | Same stack map pointer is used by a lookup in the same bytecode region, but that lookup is itself not a direct `find_map_lookup_sites` target. Same map is also read in continuation programs, which is cross-program, not the same-program C5 condition. |
| katran | 1 | 0 | 1 source-level | Dynamic `lru_map` is looked up, value fields are read, and the same `lru_map` is updated in `check_and_update_real_index_in_lru`; raw bytecode has no direct static map index for the writer. |
| tracee_monitor | 2 | 0 | 0 counted | `sched_process_fork` has outer map lookup, inner map lookup using the returned map pointer, then update on that same returned map pointer, but the inner lookup result is passed to the update helper rather than loaded with `LDX_MEM`, so it is not counted as a value-load inline target. `sched_process_free` deletes an inner map but has no same-program inner lookup/value-load target. |
| all other apps | 0 | 0 | 0 | No resolver-None writer calls. |

The raw static `map_idx` proof column is zero because every C5-trigger writer has an unresolved map argument. The concrete exploit evidence is therefore the same logical map pointer, not a resolved canonical index.

## Concrete examples

### 1. tracee_monitor/570_tracepoint__sched__sched_process_fork - unresolved map-in-map update, no value-load target

Writer:

```text
1926: r1 = map_idx[18]
1928: call BPF_FUNC_map_lookup_elem       ; outer process_tree_map_version lookup
1929: r6 = r0                             ; r6 is inner_proc_tree_map
1930: if r6 == 0 goto ...
1931: r2 = r10
1932: r2 += -84
1933: r1 = r6
1934: call BPF_FUNC_map_lookup_elem       ; lookup inner_proc_tree_map[parent_pid]
1935: if r0 == 0 goto ...
1936: r2 = r10
1937: r2 += -88
1938: r1 = r6
1939: r3 = r0
1940: r4 = 0
1941: call BPF_FUNC_map_update_elem       ; update same inner_proc_tree_map
```

Why r1 is non-direct: the writer map argument is an alias of a previous helper return (`r0` from `map_lookup_elem`, copied through `r6`). `find_direct_map_load_for_reg_before_site` stops at the helper-call definition of `r0` and returns `None`.

Same-map inline target: not counted. The same `r6` map pointer is used for `bpf_map_lookup_elem` at PC 1934, but the returned pointer is passed to `bpf_map_update_elem` as the value argument rather than loaded with `LDX_MEM`. Source confirms the same-map lookup/update pattern in `bpfopt/testccode/tracee_tracee.bpf.c`: `process_tree_map_version` lookup around line 696, inner lookup around line 698, and `bpf_map_update_elem(inner_proc_tree_map, ...)` around line 700.

### 2. tracee_monitor/581_tracepoint__sched__sched_process_free - unresolved map-in-map delete, no same-program target

Writer:

```text
36: r1 = map_idx[2]
38: call BPF_FUNC_map_lookup_elem       ; outer process_tree_map_version lookup
39: if r0 == 0 goto ...
40: r2 = r10
41: r2 += -8
42: r1 = r0                             ; inner_proc_tree_map
43: call BPF_FUNC_map_delete_elem
```

Why r1 is non-direct: the delete target is the map pointer returned by an outer map-in-map lookup. The resolver follows `r1 = r0`, then reaches the helper-call definition of `r0` and returns `None`.

Same-map inline target: no same-program inner-map lookup/value-load target found. The source at `bpfopt/testccode/tracee_tracee.bpf.c` around lines 1628-1630 deletes from `inner_proc_tree_map` after looking it up from `process_tree_map_version`, but this program does not also lookup values from that same inner map.

### 3. katran/530_balancer_ingress - unresolved dynamic LRU map writer

Writer:

```text
2116: r4 = *(u8 *)(r3 + 1)
2117: *(u64 *)(r10 - 168) = r4
...
2284: r1 = *(u64 *)(r10 - 168)
2285: r4 = 0
2286: call BPF_FUNC_map_update_elem
```

Why r1 is non-direct: the nearest linear stack-slot store does not lead to a map load; it leads to an `LDX` byte load. This is a branch/layout-sensitive failure of the linear `prev_def_in_frame` walk. The current resolver returns `None`.

Same-map inline target: source-level yes for the dynamic `lru_map` pattern. `bpfopt/testccode/katran_balancer.bpf.c` has `dst_lru = bpf_map_lookup_elem(lru_map, &pckt->flow)` around line 619 and `bpf_map_update_elem(lru_map, &pckt->flow, &new_dst_lru, BPF_ANY)` around line 634. Raw canonical bytecode cannot attach a static `map_idx` to this writer because the map pointer is dynamic.

### 4. cilium_agent/213_tail_handle_ipv4 - unresolved stack-carried map pointer

Writer:

```text
243: r1 = r9
254: *(u64 *)(r10 - 192) = r1
255: call BPF_FUNC_map_lookup_elem
...
546: r1 = *(u64 *)(r10 - 192)
547: w4 = 0
548: call BPF_FUNC_map_update_elem
```

Why r1 is non-direct: the stack slot does have a previous `STX_DW`, but tracing that store reaches `r1 = r9`, and the nearest earlier linear definition of `r9` is a scalar error code (`w9 = -135`) from another branch. The current branch-insensitive resolver returns `None`.

Same-map inline target: not counted. The same stack-carried map pointer is used by a lookup in this bytecode, but that lookup is also not a direct `find_map_lookup_sites` target. The same source map family has lookup/value-load readers in continuation programs, but that is cross-program evidence, not the same-program C5 condition requested here.

### 5. cilium_agent/195_tail_handle_ipv4 - duplicate unresolved stack-carried map pointer

This is byte-for-byte the same resolver shape as `213_tail_handle_ipv4` at the writer site:

```text
243: r1 = r9
254: *(u64 *)(r10 - 192) = r1
255: call BPF_FUNC_map_lookup_elem
...
546: r1 = *(u64 *)(r10 - 192)
547: w4 = 0
548: call BPF_FUNC_map_update_elem
```

Why r1 is non-direct: same branch/layout-sensitive stack trace as example 4.

Same-map inline target: not counted for the same reason as example 4.

### 6. katran/530_balancer_ingress - stack-slot indirection that is already handled

Non-C5 example:

```text
828:  r1 = map_idx[3]
830:  *(u64 *)(r10 - 168) = r1
...
1342: r1 = *(u64 *)(r10 - 168)
1344: call BPF_FUNC_map_update_elem
```

Why r1 is non-direct: the writer map argument is reloaded from a stack slot.

Resolver result: handled. `find_direct_map_load_for_stack_slot_before_site` recursively finds the `STX_DW` at PC 830 and then the direct map load at PC 828. This is one of 19 writer calls where the previous definition is not direct but the current recursion succeeds.

### 7. cilium_agent/175_tail_handle_snat_fwd_ipv4 - mov-chain indirection that is already handled

Non-C5 example:

```text
1125: r7 = map_idx[6]
...
1207: r1 = r7
1209: call BPF_FUNC_map_update_elem
```

Why r1 is non-direct: the writer map argument is copied through a callee-saved register.

Resolver result: handled. The recursive `MOV64_REG` path finds the direct map load at PC 1125.

## Recommendation

Fix C5 fail-fast or conservatively. The corpus has real resolver-None writer helpers, including a same-program dynamic-map lookup/value-load/update sequence in Katran where a stale inline snapshot is plausible. Keeping the silent `continue` is not supported by the evidence.

The minimal evidence-backed fix is: when a writer helper is found and `find_direct_map_load_for_reg_before_site(..., r1)` returns `None`, fail `map_inline` with a diagnostic or conservatively mark all snapshot candidate maps mutable for that program. Strengthening the resolver for branch-sensitive stack cases would reduce false positives for the Cilium examples, but it would not cover helper-return map pointers from map-in-map patterns, so it is not sufficient by itself.
