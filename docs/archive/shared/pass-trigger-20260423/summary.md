# Pass Trigger Analysis — `x86_kvm_corpus_20260423_064352_754994`

Artifact: `corpus/results/x86_kvm_corpus_20260423_064352_754994/result.json`

Scope:
- Total discovered programs: `122`
- `comparison_exclusion_reason=no_programs_changed_in_loader`: `38`

Method:
- `no_programs_changed_in_loader` is an observability bucket, not a byte-size equality check; the plan doc already notes it mixes `0-site`, `all rollback`, and `apply success but final unchanged` cases (`docs/kernel-jit-optimization-plan.md:25`, `docs/kernel-jit-optimization-plan.md:1041`).
- The daemon serializes per-pass `sites_applied`, `sites_skipped`, `verify_result`, and optional `rollback` in `PassDetail` (`daemon/src/commands.rs:117-166`), sourced from `PassResult` (`daemon/src/pass.rs:274-361`).
- The artifact does **not** serialize `sites_found`. In this note I only treat `sites_applied`, `sites_skipped`, and `verify_result` as ground truth. When I mention a `found_proxy`, it means `sites_applied + sites_skipped`, and it can over-count whole-pass gates like `rotate: subprog pseudo-calls not yet supported`.
- `sites_rolled_back` is also not serialized directly. I attribute rollback count as `sites_applied` on pass records with `verify_result=rejected`, because `PassManager` restores the pre-pass snapshot on rejection (`daemon/src/pass.rs:925-973`).
- `const_prop` and `dce` can appear multiple times because the pipeline runs them to a fixed point (`daemon/src/pass.rs:744`, `daemon/src/pass.rs:829-869`). Per-program summaries below aggregate by pass name across all rounds.
- Current benchmark default does not include `branch_flip` (`docs/kernel-jit-optimization-plan.md:1021`), and this artifact contains zero `branch_flip` records.

## Part 1. Per-pass Static Trigger Conditions

### `map_inline`

Matcher:
- `bpf_map_lookup_elem()` helper call with a recoverable pseudo-map load (`daemon/src/passes/map_inline.rs:109-129`, `daemon/src/passes/map_inline.rs:783-919`).
- Also rewrites direct `PSEUDO_MAP_VALUE` scalar loads into constant loads when the source map is frozen (`daemon/src/passes/map_inline.rs:1381-1472`).

Needs:
- Map type must support direct value access: `HASH`, `ARRAY`, `PERCPU_ARRAY`, `LRU_HASH` (`daemon/src/analysis/map_info.rs:35-80`).
- Key must be recoverable from stack materialization, verifier-guided stack state, or pseudo-map-value materialization (`daemon/src/passes/map_inline.rs:1122-1249`).
- Lookup result use must be fixed-offset scalar loads; mutable maps additionally forbid escaping non-load uses (`daemon/src/passes/map_inline.rs:881-919`, `daemon/src/passes/map_inline.rs:2279-2469`).
- Speculative mutable-map inline requires an immediate null check (`daemon/src/passes/map_inline.rs:888-891`, `daemon/src/passes/map_inline.rs:1366-1379`).

Skips / properties:
- Unsupported map types, non-constant keys, non-fixed-load consumers, mutable value escape, non-uniform `PERCPU_ARRAY`, failed live-map reads (`daemon/src/passes/map_inline.rs:824-945`, `daemon/src/passes/map_inline.rs:1521-1562`).
- No explicit program-type gate; this is the only default pass that meaningfully touches tracing/raw-tracepoint/perf-event unchanged programs.

### `const_prop`

Matcher:
- No peephole site matcher. It is a verifier-assisted dataflow pass that folds exact constants into `MOV32`/`MOV64`/`LD_IMM64`, and folds provably constant conditional branches into `JA` or `NOP` (`daemon/src/passes/const_prop.rs:175-291`, `daemon/src/passes/const_prop.rs:417-449`).

Needs:
- Exact scalar constants either from local evaluation or from parsed verifier state snapshots (`daemon/src/passes/const_prop.rs:39-173`, `daemon/src/passes/const_prop.rs:452-745`).

Skips / properties:
- Pseudo-immediates such as `MAP_FD` / `MAP_VALUE` are treated as non-foldable (`daemon/src/passes/const_prop.rs:369-379`).
- Tail-call protected prefixes are filtered to avoid changing poke-sensitive control flow (`daemon/src/passes/const_prop.rs:201-219`, `daemon/src/passes/const_prop.rs:729-745`).
- No program-type gate in the pass itself; many failures are deferred to per-pass re-verify.

### `dce`

Matcher:
- No structural matcher. Removes unreachable basic blocks, dead register defs, and fixed-point `NOP` chains after earlier simplifications (`daemon/src/passes/dce.rs:12-123`).

Needs:
- Prior simplification from `const_prop` / `map_inline` / other rewrites; otherwise it often has nothing to remove.

Skips / properties:
- Tail-call protected prefixes are handled in a tail-safe mode that neutralizes rather than deletes when needed (`daemon/src/passes/dce.rs:38-86`, `daemon/src/passes/utils.rs:84-120`, `daemon/src/passes/utils.rs:239-290`).
- No program-type gate; verifier rejection happens after rewrite.

### `skb_load_bytes_spec`

Matcher:
- Direct helper call `bpf_skb_load_bytes` (`helper #26`) with `arg1=ctx`, constant `arg2=offset`, fp-relative stack destination in `arg3`, and constant `arg4=len` where `1 <= len <= 8` (`daemon/src/passes/skb_load_bytes.rs:116-189`).

Needs:
- Program type must be `SCHED_CLS` or `SCHED_ACT` because the pass hardcodes `skb->data` and `skb->data_end` layout (`daemon/src/passes/skb_load_bytes.rs:72-77`, `daemon/src/passes/skb_load_bytes.rs:106-113`).

Skips / properties:
- Rejects branch-target helper PCs, non-regular helper calls, non-constant offset/len, non-stack destination, and `len > 8` (`daemon/src/passes/skb_load_bytes.rs:127-189`).
- Fast path intentionally remains bytewise to avoid creating verifier-illegal unaligned packet loads (`daemon/src/passes/skb_load_bytes.rs:257-267`).

### `bounds_check_merge`

Matcher:
- Packet-guard ladder of the form `MOV cursor, root; ADD cursor, const_window; J{GT/LT/GE/LE} cursor, data_end, slow` (`daemon/src/passes/bounds_check_merge.rs:250-409`).
- Merges consecutive guards only when they share the same packet root, same compare kind, same slow target, increasing window end, and the next window grows by at most `24` bytes (`daemon/src/passes/bounds_check_merge.rs:31-32`, `daemon/src/passes/bounds_check_merge.rs:412-430`).

Needs:
- Program type must be packet-carrying: `SCHED_CLS`, `SCHED_ACT`, `XDP`, `SK_SKB`, `LWT_IN`, `LWT_OUT`, `LWT_XMIT` (`daemon/src/passes/bounds_check_merge.rs:94-106`, `daemon/src/passes/bounds_check_merge.rs:237-247`).

Skips / properties:
- Variable-window guards are explicitly recognized and rejected in v1 (`daemon/src/passes/bounds_check_merge.rs:267-268`, `daemon/src/passes/bounds_check_merge.rs:362-396`).
- Non-ladder guards are reported as `guard not part of a mergeable ladder` (`daemon/src/passes/bounds_check_merge.rs:144-151`).

### `wide_mem`

Matcher:
- Byte-recompose ladders `LDX(B)` + `LSH` + `OR`, in either low-byte-first or high-byte-first form, for widths `2..=8` bytes (`daemon/src/passes/wide_mem.rs:48-150`).

Needs:
- Safe emit only exists for widths `2`, `4`, and `8` (`daemon/src/passes/wide_mem.rs:460-468`).

Skips / properties:
- Rejects interior branch targets and live scratch regs (`daemon/src/passes/wide_mem.rs:411-458`).
- On packet-sensitive program types (`TC`, `XDP`, `LWT_*`, `SK_SKB`), heuristically rejects bases likely derived from `ctx->data` / `ctx->data_end` (`daemon/src/passes/wide_mem.rs:323-378`, `daemon/src/passes/wide_mem.rs:470-501`).
- No kinsn dependency; pure BPF rewrite.

### `bulk_memory`

Matcher:
- Scalarized contiguous `memcpy` runs: repeated `LDX_MEM width tmp, [src+off]` followed by `STX_MEM width [dst+off], tmp` with monotonic offsets (`daemon/src/passes/bulk_memory.rs:253-383`, `daemon/src/passes/bulk_memory.rs:446-473`).
- Scalarized zero `memset` runs: repeated zero stores with monotonic offsets (`daemon/src/passes/bulk_memory.rs:385-443`, `daemon/src/passes/bulk_memory.rs:475-499`).

Needs:
- Chunk size must be at least `32` bytes; runs are chunked up to `128` bytes (`daemon/src/passes/bulk_memory.rs:14-15`, `daemon/src/passes/bulk_memory.rs:603-647`).
- Requires `bpf_memcpy_bulk` / `bpf_memset_bulk` kfunc and packed ABI (`daemon/src/passes/bulk_memory.rs:120-167`).

Skips / properties:
- Rejects overlapping same-base memcpy, tmp regs live after the run, alias-unsafe different-base memcpy, and unsupported widths (`daemon/src/passes/bulk_memory.rs:129-141`, `daemon/src/passes/bulk_memory.rs:348-369`, `daemon/src/passes/bulk_memory.rs:679-690`).

### `rotate`

Matcher:
- Rotate idiom `MOV tmp, val; RSH64 tmp, a; LSH64 val, b; OR64 tmp,val` or the inverse shift ordering, with `a + b == 64` (`daemon/src/passes/rotate.rs:223-350`).

Needs:
- `bpf_rotate64` kfunc and packed ABI (`daemon/src/passes/rotate.rs:29-48`).

Skips / properties:
- Whole-program veto if any `BPF_PSEUDO_CALL` exists, because safety is currently intraprocedural only (`daemon/src/passes/rotate.rs:50-65`).
- Rejects interior branch targets and live `tmp_reg` across the site (`daemon/src/passes/rotate.rs:77-109`).

### `cond_select` (`cmov` / `csel` lowering)

Matcher:
- Four-insn diamond `Jcc +2; MOV false; JA +1; MOV true`, or three-insn short form `MOV true; Jcc +1; MOV false` (`daemon/src/passes/cond_select.rs:330-413`).

Needs:
- Platform must advertise `has_cmov` (`daemon/src/passes/cond_select.rs:128-136`).
- `bpf_select64` kfunc and packed ABI (`daemon/src/passes/cond_select.rs:139-176`).
- Current lowering only accepts `JEQ reg, 0` or `JNE reg, 0` (`daemon/src/passes/cond_select.rs:71-80`, `daemon/src/passes/cond_select.rs:186-197`).
- Packed path currently requires both true/false arms to already be in registers (`daemon/src/passes/cond_select.rs:104-110`, `daemon/src/passes/cond_select.rs:218-223`).

Skips / properties:
- Rejects interior branch targets outside the site’s own JCC target (`daemon/src/passes/cond_select.rs:199-216`).

### `extract` (`bextr` lowering)

Matcher:
- Two-insn bitfield idiom `RSH64_IMM dst, shift; AND64_IMM dst, mask`, where `mask` is contiguous from bit 0 and `shift + popcount(mask) <= 64` (`daemon/src/passes/extract.rs:10-24`, `daemon/src/passes/extract.rs:40-94`).

Needs:
- `bpf_extract64` kfunc and packed ABI (`daemon/src/passes/extract.rs:111-130`).

Skips / properties:
- Only interior-branch-target filtering after match; no explicit program-type gate (`daemon/src/passes/extract.rs:140-153`).

### `endian_fusion`

Matcher:
- `LDX_MEM(H/W/DW)` immediately followed by `END_TO_BE` of matching size on the same destination register (`daemon/src/passes/endian.rs:17-33`, `daemon/src/passes/endian.rs:53-107`).

Needs:
- Size-specific endian-load kfunc for `16/32/64` and packed ABI (`daemon/src/passes/endian.rs:109-133`, `daemon/src/passes/endian.rs:222-315`).

Skips / properties:
- Rejects missing size-specific target and interior branch targets (`daemon/src/passes/endian.rs:265-315`).
- On arm64, large/non-encodable offsets are rewritten by address materialization around a zero-offset packed call (`daemon/src/passes/endian.rs:139-210`).

### `branch_flip`

Matcher:
- True if/else diamonds `Jcc +N; then...; JA +M; else...` (`daemon/src/passes/branch_flip.rs:10-37`, `daemon/src/passes/branch_flip.rs:309-349`).

Needs:
- Program-level PMU branch miss rate must be present and below threshold (`daemon/src/passes/branch_flip.rs:85-112`).
- Per-site branch profile is preferred; otherwise it falls back to a size-asymmetry heuristic (`daemon/src/passes/branch_flip.rs:153-181`).

Skips / properties:
- Rejects interior branch targets and non-invertible conditions such as `JSET` (`daemon/src/passes/branch_flip.rs:132-151`, `daemon/src/passes/branch_flip.rs:363-377`).
- Static only in this note: benchmark default excludes it (`docs/kernel-jit-optimization-plan.md:1021`), and this artifact has zero serialized `branch_flip` pass records.

## Part 2. `38` Unchanged Programs

### Type-level summary

| prog type | unchanged progs | median insns | A | B | C | D |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `kprobe` | 10 | 86 | 4 | 1 | 0 | 5 |
| `perf_event` | 1 | 67 | 0 | 0 | 0 | 1 |
| `raw_tracepoint` | 4 | 31 | 2 | 0 | 0 | 2 |
| `struct_ops` | 10 | 607 | 0 | 9 | 0 | 1 |
| `tracepoint` | 8 | 47 | 5 | 1 | 0 | 2 |
| `tracing` | 4 | 12 | 1 | 0 | 0 | 3 |
| `xdp` | 1 | 2542 | 0 | 1 | 0 | 0 |

### Pass-level surface inside the unchanged bucket

`F_proxy` below means `sites_applied + sites_skipped`, and is only a lower-fidelity proxy for passes that whole-pass skip before scanning.

| pass | unique unchanged progs with non-zero surface | `F_proxy` / rolled-back sites |
| --- | ---: | ---: |
| `map_inline` | 15 | `150 / 13` |
| `const_prop` | 11 | `156 / 156` |
| `dce` | 2 | `9 / 9` |
| `skb_load_bytes_spec` | 0 | `0 / 0` |
| `bounds_check_merge` | 0 | `0 / 0` |
| `wide_mem` | 2 | `7 / 7` |
| `bulk_memory` | 2 | `3 / 2` |
| `rotate` | 11 | `11 / 0` |
| `cond_select` | 9 | `123 / 0` |
| `extract` | 1 | `2 / 2` |
| `endian_fusion` | 1 | `2 / 2` |

Pass-surface legend for the per-program table:
- `aN`: `sites_applied=N`
- `sN`: `sites_skipped=N`
- `rbN`: `sites_applied=N` then verifier-rejected and rolled back
- `gate`: whole-pass gate; the serialized skip record is not a real site count
- `skb_load_bytes_spec` and `bounds_check_merge` are omitted from the table because they are `0` for all `38` unchanged programs

| cat | app | prog id | program name | type | bytes_xlated | insns | non-zero pass surface |
| --- | --- | ---: | --- | --- | ---: | ---: | --- |
| A | `bcc/bindsnoop` | 13 | `bindsnoop_entry` | `kprobe` | 120 | 15 | `-` |
| A | `bcc/biosnoop` | 18 | `trace_pid_start_tp` | `tracepoint` | 448 | 56 | `-` |
| A | `bcc/execsnoop` | 9 | `syscall__execve` | `kprobe` | 4144 | 516 | `-` |
| A | `bcc/execsnoop` | 10 | `do_ret_sys_execve` | `kprobe` | 704 | 86 | `-` |
| A | `bcc/opensnoop` | 31 | `kretfunc__vmlinux____x64_sys_openat` | `tracing` | 600 | 75 | `-` |
| A | `bcc/runqlat` | 48 | `sched_wakeup` | `raw_tracepoint` | 248 | 31 | `-` |
| A | `bcc/runqlat` | 49 | `raw_tracepoint__sched_wakeup_new` | `raw_tracepoint` | 248 | 31 | `-` |
| A | `bcc/syscount` | 35 | `tracepoint__raw_syscalls__sys_enter` | `tracepoint` | 112 | 14 | `-` |
| A | `bcc/tcpconnect` | 39 | `trace_connect_entry` | `kprobe` | 120 | 15 | `-` |
| A | `bpftrace/biosnoop` | 185 | `block_io_start` | `tracepoint` | 408 | 51 | `-` |
| A | `bpftrace/runqlat` | 199 | `sched_wakeup` | `tracepoint` | 136 | 17 | `-` |
| A | `bpftrace/runqlat` | 200 | `tracepoint_sched_sched_wakeup_new` | `tracepoint` | 136 | 17 | `-` |
| B | `katran` | 127 | `balancer_ingress` | `xdp` | 23840 | 2542 | `map_inline rb6; dce rb5; wide_mem rb4; rotate gate; cond_select s7; endian_fusion rb2` |
| B | `scx/rusty` | 56 | `rusty_select_cpu` | `struct_ops` | 6624 | 733 | `const_prop rb14; rotate gate` |
| B | `scx/rusty` | 59 | `rusty_dispatch` | `struct_ops` | 1304 | 246 | `const_prop rb11` |
| B | `scx/rusty` | 60 | `rusty_runnable` | `struct_ops` | 3656 | 611 | `const_prop rb15; rotate gate; cond_select s9` |
| B | `scx/rusty` | 61 | `rusty_running` | `struct_ops` | 952 | 115 | `const_prop rb6; rotate gate` |
| B | `scx/rusty` | 62 | `rusty_stopping` | `struct_ops` | 1840 | 223 | `const_prop rb3; rotate gate` |
| B | `scx/rusty` | 63 | `rusty_quiescent` | `struct_ops` | 3808 | 603 | `const_prop rb15; rotate gate; cond_select s9` |
| B | `scx/rusty` | 64 | `rusty_set_weight` | `struct_ops` | 392 | 68 | `const_prop rb1; rotate gate` |
| B | `scx/rusty` | 65 | `rusty_set_cpumask` | `struct_ops` | 10360 | 2093 | `const_prop rb47; rotate gate; cond_select s28` |
| B | `scx/rusty` | 66 | `rusty_init_task` | `struct_ops` | 8848 | 2847 | `const_prop rb3; bulk_memory rb1; rotate gate; cond_select s28; extract rb2` |
| B | `tetragon/default` | 89 | `event_execve` | `tracepoint` | 20272 | 2468 | `map_inline rb7; const_prop rb1; rotate gate; cond_select s9` |
| B | `tracee/default` | 158 | `trace_security_file_open` | `kprobe` | 37160 | 4628 | `map_inline s27; const_prop rb40; dce rb4; wide_mem rb3; bulk_memory rb1; cond_select s4` |
| D | `bcc/biosnoop` | 19 | `trace_req_start` | `kprobe` | 616 | 77 | `cond_select s1` |
| D | `bcc/syscount` | 36 | `tracepoint__raw_syscalls__sys_exit` | `tracepoint` | 400 | 44 | `map_inline s3` |
| D | `bcc/tcpconnect` | 40 | `trace_connect_v4_return` | `kprobe` | 720 | 88 | `map_inline s1` |
| D | `bcc/tcpconnect` | 41 | `trace_connect_v6_return` | `kprobe` | 712 | 87 | `map_inline s1` |
| D | `bcc/tcplife` | 44 | `tracepoint__sock__inet_sock_set_state` | `tracepoint` | 1672 | 205 | `map_inline s2` |
| D | `bcc/vfsstat` | 25 | `vfs_open` | `tracing` | 144 | 12 | `map_inline s1` |
| D | `bcc/vfsstat` | 26 | `vfs_read` | `tracing` | 136 | 11 | `map_inline s1` |
| D | `bcc/vfsstat` | 27 | `vfs_write` | `tracing` | 144 | 12 | `map_inline s1` |
| D | `bpftrace/vfsstat` | 192 | `1` | `perf_event` | 680 | 67 | `map_inline s3` |
| D | `bpftrace/vfsstat` | 193 | `vfs_create` | `kprobe` | 224 | 24 | `map_inline s1` |
| D | `scx/rusty` | 58 | `rusty_enqueue` | `struct_ops` | 13024 | 2168 | `rotate gate; cond_select s28` |
| D | `tetragon/default` | 90 | `tg_kp_bprm_committing_creds` | `kprobe` | 2560 | 292 | `map_inline s4` |
| D | `tracee/default` | 135 | `tracepoint__raw_syscalls__sys_enter` | `raw_tracepoint` | 264 | 29 | `map_inline s1` |
| D | `tracee/default` | 139 | `tracepoint__raw_syscalls__sys_exit` | `raw_tracepoint` | 320 | 36 | `map_inline s1` |

## Part 3. A / B / C / D Classification

### A. All passes `total_sites=0`

Count: `12`

Findings:
- `11/12` are smaller than `100` insns; median is `31` insns. This bucket is dominated by tiny `tracepoint` / `raw_tracepoint` / `tracing` programs and a few tiny kprobes.
- The typical shape is “single helper or context-field plumbing with no arithmetic/data-recompose idiom”, so no default matcher fires at all.
- Representative examples:
  - `bcc/syscount:tracepoint__raw_syscalls__sys_enter#35` (`14` insns, `tracepoint`)
  - `bcc/runqlat:sched_wakeup#48` (`31` insns, `raw_tracepoint`)
  - `bpftrace/runqlat:sched_wakeup#199` (`17` insns, `tracepoint`)
- The one large outlier is `bcc/execsnoop:syscall__execve#9` (`516` insns), which still has zero surface; this is evidence that “large program” does not imply “current pass family sees useful idioms”.

### B. Pass matched or rewrote, but verifier rolled the pass back

Count: `12`

Findings:
- Dominant type is `struct_ops`: `9/12` B-programs.
- `const_prop` dominates this class: it appears in `11/12` B-programs and accounts for `156` rolled-back sites inside the unchanged bucket.
- Representative examples:
  - `scx/rusty:rusty_set_cpumask#65`: `const_prop rb47`, plus `rotate gate`, `cond_select s28`
  - `katran:balancer_ingress#127`: `map_inline rb6`, `dce rb5`, `wide_mem rb4`, `endian_fusion rb2`
  - `tracee/default:trace_security_file_open#158`: `const_prop rb40`, `dce rb4`, `wide_mem rb3`, `bulk_memory rb1`
- Most common verifier error in unchanged B-programs:
  - `const_prop`: `EPERM` on eight SCX `struct_ops` programs, `EINVAL` on `rusty_init_task#66`, `event_execve#89`, `trace_security_file_open#158`
  - All other rollbacking passes in this bucket are `EINVAL`

### C. `sites_applied > 0` but final program remained byte-identical

Count: `0` observed in this artifact

Notes:
- I did not find any unchanged program where a pass had `sites_applied > 0`, `verify_result != rejected`, and the final optimize result still reported `changed=false`.
- Because the artifact does not serialize bytecode hashes, this is “0 observed cases under current daemon telemetry”, not a stronger proof that such cases cannot happen.

### D. Skip-only / gated, no verifier rollback

Count: `14`

Findings:
- `12/14` are `map_inline`-only skip programs.
- The remaining two are:
  - `bcc/biosnoop:trace_req_start#19` with only `cond_select s1`
  - `scx/rusty:rusty_enqueue#58` with `rotate gate` and `cond_select s28`
- This class is the cleanest “matcher coverage” signal: the daemon sees a surface, but current matcher limits or site-policy limits stop before re-verify.

## Part 4. Coverage Holes

1. Observability-heavy program types are mostly invisible to the current pass family.
Evidence:
- `17/38` unchanged programs are `tracepoint` / `raw_tracepoint` / `tracing` / `perf_event`.
- Within those `17`, `8` are strict zero-surface `A`, `8` are `map_inline`-only `D`, and only `event_execve#89` reaches broader pass surface before rollback.
- Concrete IDs: `trace_pid_start_tp#18`, `tracepoint__raw_syscalls__sys_enter#35`, `sched_wakeup#48`, `vfs_open#25`, `perf_event "1"#192`.

2. `map_inline` is the only default pass reaching many tracing/raw-tracing programs, but its current matcher is too narrow for their key/use patterns.
Evidence:
- `12` unchanged programs are `map_inline`-only.
- Dominant skip reasons in the unchanged bucket:
  - constant-key recovery failure: `10` programs / `47` skipped sites
  - non-fixed-load consumers: `8` programs / `38` skipped sites
- Concrete IDs: `vfs_open#25`, `trace_connect_v4_return#40`, `tracepoint__raw_syscalls__sys_enter#135`, `tg_kp_bprm_committing_creds#90`.

3. `cond_select` has broad surface but zero realized coverage.
Evidence:
- Whole corpus: `48` unique programs, `363` skipped-site proxy, `0` applied.
- Unchanged bucket: `9` programs, `123` skipped-site proxy, `0` applied.
- Aggregated skip reasons corpus-wide:
  - unsupported compare form: `206` skipped sites / `46` programs
  - packed ABI requires both arms in registers: `145` skipped sites / `37` programs
- Concrete IDs: `trace_req_start#19`, `rusty_enqueue#58`, `rusty_set_cpumask#65`, `event_execve#89`.

4. `rotate` is blocked by a whole-program pseudo-call veto, not by absence of candidate programs.
Evidence:
- Whole corpus: `26` unique programs hit the global `subprog pseudo-calls not yet supported` gate and `0` apply.
- Unchanged bucket: `11` programs hit the same gate.
- Concrete IDs: `rusty_select_cpu#56`, `rusty_enqueue#58`, `event_execve#89`, `balancer_ingress#127`.
- Important caveat: because the pass exits before scanning, the artifact cannot tell how many actual rotate sites were inside those programs.

5. `struct_ops` is a verifier/safety-model hole, not a matcher hole.
Evidence:
- `10/10` unchanged `struct_ops` programs have some pass surface.
- But `9/10` fall into `B` rollback and the remaining `1/10` is `rotate gate + cond_select skip`.
- Concrete IDs: `rusty_select_cpu#56`, `rusty_set_cpumask#65`, `rusty_init_task#66`, `rusty_enqueue#58`.

6. Two packet-oriented passes are completely absent from this corpus.
Evidence:
- `skb_load_bytes_spec`: `0/122` programs, `0` sites
- `bounds_check_merge`: `0/122` programs, `0` sites
- This is consistent with their narrow static domain: `skb_load_bytes_spec` is TC-only helper-26 specialization (`daemon/src/passes/skb_load_bytes.rs:106-113`), and `bounds_check_merge` is packet-guard-ladder only (`daemon/src/passes/bounds_check_merge.rs:237-247`, `daemon/src/passes/bounds_check_merge.rs:285-430`).

7. `branch_flip` currently has no runtime coverage data in this artifact.
Evidence:
- Static pass exists (`daemon/src/passes/branch_flip.rs:79-181`, `daemon/src/passes/branch_flip.rs:309-377`).
- Benchmark default excludes it (`docs/kernel-jit-optimization-plan.md:1021`).
- Offline census still says branch-flip family has `2264` candidate sites corpus-wide (`docs/kernel-jit-optimization-plan.md:190`).

## Part 5. Recommended Improvement Directions

| direction | why this is the right target | direct unchanged unlock | broader corpus surface | risk / note |
| --- | --- | ---: | ---: | --- |
| Relax `cond_select` packed ABI to accept immediate true/false arms by materializing small immediates or extending payload | Current packed path hard-requires both arms in registers (`daemon/src/passes/cond_select.rs:104-110`, `daemon/src/passes/cond_select.rs:218-223`). This blocks `145` skipped sites across `37` programs, including `106` skipped sites across `8` unchanged programs. | `2` direct (`trace_req_start#19`, `rusty_enqueue#58`); `8` upper-bound in unchanged bucket | `37` programs / `145` sites | Low to medium. Mostly emission/register-pressure work. |
| Extend `cond_select` compare lowering beyond `JEQ/JNE reg,0` | Current matcher only accepts simple zero-tests (`daemon/src/passes/cond_select.rs:71-80`, `daemon/src/passes/cond_select.rs:186-197`). Corpus-wide this leaves `206` skipped sites on `46` programs. | `2` direct; `8` upper-bound in unchanged bucket | `46` programs / `206` sites | Medium. Needs compare-result materialization or a richer select ABI. |
| Make `rotate` subprog-aware instead of whole-program pseudo-call veto | The pass exits before scanning if any pseudo-call exists (`daemon/src/passes/rotate.rs:50-65`). This blocks `26` programs corpus-wide, `11` inside the unchanged bucket. | `1` direct (`rusty_enqueue#58`); `11` upper-bound in unchanged bucket | `26` gated programs | Medium to high. Needs interprocedural safety and pseudo-call remap discipline. |
| Improve `map_inline` constant-key recovery | The main unchanged skip reason is non-recoverable constant key (`daemon/src/passes/map_inline.rs:843-859`, `daemon/src/passes/map_inline.rs:1122-1249`). | `7` direct; `10` upper-bound in unchanged bucket | `77` programs / `519` skipped sites | Medium. Best ROI inside the unchanged bucket. |
| Expand `map_inline` consumer model beyond fixed-offset scalar loads | Current use classification rejects many tracing-style consumers (`daemon/src/passes/map_inline.rs:881-919`, `daemon/src/passes/map_inline.rs:2279-2469`). | `5` direct; `8` upper-bound in unchanged bucket | `81` programs / `361` skipped sites | High. Pointer-escape and alias safety get harder quickly. |
| Add daemon-side verifier pre-check for known-`EPERM` `const_prop` cases before rewrite | `const_prop` is the biggest rollback source. In the unchanged bucket alone, eight SCX `struct_ops` programs contribute `112` rolled-back sites with deterministic `EPERM`. The pass framework already verifies after each change (`daemon/src/pass.rs:950-973`); a cheap early reject would stop noisy rollback churn. | `0` unlock; avoids `8` unchanged false-rollback cases | `27` unique programs show `EPERM` on `const_prop` somewhere in corpus | Low. This is rollback avoidance, not coverage expansion. |
| Introduce a tracing-oriented helper/context specialization pass | `17` unchanged observability programs (`tracepoint`/`raw_tracepoint`/`tracing`/`perf_event`) currently show either zero surface or map-inline-only surface. Existing plan work already points to helper specialization as the next tracing-family direction (`docs/kernel-jit-optimization-plan.md:215`). | upper-bound `17` | upper-bound is the observability-heavy slice now missed by all arithmetic/copy passes | High. This is a new pass family, not a matcher tweak. |
| Do **not** spend near-term effort broadening `skb_load_bytes_spec` or `bounds_check_merge` for this x86 corpus | They hit `0/122` programs here. This run gives no empirical evidence that widening them will move the unchanged bucket. | `0` | `0` in this artifact | Low ROI for the current corpus. Revisit only with a packet-heavy suite. |

Highest-ROI order for reducing the current `38` unchanged bucket:
1. `map_inline` key recovery
2. `map_inline` consumer expansion
3. `cond_select` operand/compare widening
4. `rotate` pseudo-call support
5. `const_prop` verifier pre-check for noise reduction

Net interpretation:
- The unchanged bucket is **not** primarily “program too small” or “no optimization exists”.
- It splits into three concrete engineering problems:
  - small observability programs that no current pass family understands (`A`)
  - verifier/safety-model failures, dominated by `const_prop` and `struct_ops` (`B`)
  - matcher-policy gaps, dominated by `map_inline`, `cond_select`, and `rotate` (`D`)
