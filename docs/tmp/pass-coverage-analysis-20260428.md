# Pass Coverage Analysis - 2026-04-28

Primary source artifact:
`corpus/results/x86_kvm_corpus_20260428_070851_973550/details/result.json`

This is the artifact that matches the prompt's app counts: Tetragon 287
programs, Cilium 16, Calico 6, otelcol-ebpf-profiler 13, Katran 3, and 22
total apps.

I also checked the newer-by-mtime artifact
`corpus/results/aws_x86_corpus_20260428_184822_640612/details/result.json`.
It has the same qualitative no-final-rewrite signal, but different live app
shape for Cilium and Tetragon. Both artifacts are compacted and do not retain
successful no-op `debug_result.passes[]`.

## Bottom Line

The 17/22 low-coverage result is mostly not caused by a top-level ReJIT filter
or app/prog_type exclusion. The enabled pass set is simply narrow:

- The current passes mostly recognize small peepholes: byte-load ladders,
  adjacent shift/mask, adjacent endian load/swap, branch-over-move zero tests,
  contiguous stack/memory zeroing/copy, and a narrow map-lookup specialization.
- Packet-specific passes only cover a subset of packet idioms. In particular,
  `bounds_check_merge` advertises TC/XDP coverage but its scanner only tracks
  `ctx->data`/`ctx->data_end` at offsets `0/4`, which matches XDP-style ctx
  layout, not TC `__sk_buff` offsets `76/80`.
- Tracing/kprobe apps mostly spend bytecode on helper calls, event struct
  materialization, dynamic map keys, probe reads, perf/ringbuf output, and
  policy/filter interpreters. Those are outside the 11 enabled matchers.
- Networking apps mostly use packet cursor guards, tail calls, dynamic maps,
  packet helpers, endian parsing, and checksum/update helpers. Existing passes
  cover only narrow versions of these.

Important observability caveat: the compact artifact proves "no final bytecode
rewrite was kept" for the 17 apps. It does not prove that every raw matcher
found zero sites. Older non-compact artifacts show that Tetragon/Katran can have
raw scan sites in similar programs, but the 2026-04-28 compact artifact cannot
distinguish "zero raw sites" from "candidate site rejected/rolled back".

## Result Signal

The 5 apps with a final JIT/bytecode change in the KVM artifact are:

- `tracee/monitor`
- `bcc/capable`
- `bcc/bindsnoop`
- `bcc/biosnoop`
- `bcc/runqlat`

The 17 apps with no final rewrite are:

| app | programs requested | prog_type mix from baseline | observed signal |
|---|---:|---|---|
| `bcc/execsnoop` | 2 | `kprobe` | `changed=false`, 0 byte deltas |
| `bcc/vfsstat` | 5 | `tracing` | `changed=false`, 0 byte deltas |
| `bcc/opensnoop` | 3 | `tracing` | `changed=false`, 0 byte deltas |
| `bcc/syscount` | 2 | `tracepoint` | `changed=false`, 0 byte deltas |
| `bcc/tcpconnect` | 3 | `kprobe` | `changed=false`, 0 byte deltas |
| `bcc/tcplife` | 1 | `tracepoint` | `changed=false`, 0 byte deltas |
| `calico/felix` | 6 | `sched_cls` | `changed=false`, 0 byte deltas |
| `otelcol-ebpf-profiler/profiling` | 13 | `perf_event` 12, `tracepoint` 1 | `changed=false`, 0 byte deltas |
| `cilium/agent` | 16 | `sched_cls` 14, `tracing` 2 | `changed=false`, 0 byte deltas |
| `tetragon/observer` | 287 | `kprobe` 270, `raw_tracepoint` 7, `tracepoint` 9, `socket_filter` 1 | `changed=false`, 0 byte deltas |
| `katran` | 3 | `xdp` 2, `sched_cls` 1 | `changed=false`, 0 byte deltas |
| `bpftrace/capable` | 1 | `kprobe` | `changed=false`, 0 byte deltas |
| `bpftrace/biosnoop` | 2 | `tracepoint` | `changed=false`, 0 byte deltas |
| `bpftrace/vfsstat` | 2 | `kprobe` 1, `perf_event` 1 | `changed=false`, 0 byte deltas |
| `bpftrace/runqlat` | 3 | `tracepoint` | `changed=false`, 0 byte deltas |
| `bpftrace/tcplife` | 1 | `kprobe` | `changed=false`, 0 byte deltas |
| `bpftrace/tcpretrans` | 1 | `kprobe` | `changed=false`, 0 byte deltas |

`program_counts.applied` in the primary artifact is the old inflated value
described in `docs/tmp/low-apply-debug-20260428.md`; use app-level
`rejit_result.changed` plus byte deltas as the final-rewrite signal.

## Pass Matcher Matrix

Source files read: `daemon/src/passes/{wide_mem,rotate,cond_select,extract,endian,map_inline,const_prop,dce,bounds_check_merge,skb_load_bytes,bulk_memory}.rs`.

| pass | prog_type gate | raw matcher | main skip / no-match conditions |
|---|---|---|---|
| `wide_mem` | All prog_types, but packet-pointer sites are skipped for TC/XDP/LWT/SK_SKB | Byte loads from same base at consecutive offsets, recomposed with `LSH imm` and `OR`, width 2/4/8 | No byte ladder; width not 2/4/8; interior branch target; scratch reg live after site; likely packet pointer in packet program |
| `rotate` | All prog_types, but skips whole program if any BPF pseudo-call exists | Adjacent provenance `MOV tmp, val`; two shifts whose amounts sum to 64; `OR` combines both regs | kfunc/packed ABI unavailable; subprog pseudo-calls; missing adjacent provenance `MOV`; tmp live after site; interior branch target |
| `cond_select` | All prog_types | 4-insn diamond `Jcc +2; MOV false; JA +1; MOV true` or 3-insn `MOV true; Jcc +1; MOV false` | Platform lacks CMOV; kfunc/packed ABI unavailable; condition is not `JEQ/JNE reg, 0`; true/false operands are immediates rather than registers; interior branch target |
| `extract` | All prog_types | Adjacent `RSH64 imm; AND64 imm` on same dst, mask is low contiguous ones and `shift + len <= 64` | kfunc/packed ABI unavailable; non-adjacent pattern; non-low or non-contiguous mask; interior branch target |
| `endian_fusion` | All prog_types | `LDX_MEM` of H/W/DW immediately followed by `BPF_END TO_BE` of matching size on same dst | endian kfunc/packed ABI unavailable for that size; byte load; size mismatch; non-adjacent load/swap; interior branch target |
| `map_inline` | All prog_types | `bpf_map_lookup_elem()` with a resolved map FD, constant key, userspace-readable map value, and lookup result consumed by fixed-offset scalar loads | map type not in HASH/ARRAY/PERCPU_ARRAY/LRU_HASH; key not constant stack or frozen pseudo-map-value; verifier-guided key >8B; mutable hash lacks immediate null check; result escapes; value read fails; PERCPU_ARRAY slots differ; rewrite overlap/branch target/verifier rollback |
| `const_prop` | All prog_types | Exact scalar constants from local dataflow or verifier states; folds ALU results and constant conditional branches | No exact constants; calls clobber r0-r5; pseudo map/fd immediates are deliberately not folded; tail-call protected prefix disallows branch folding and length-changing replacements |
| `dce` | All prog_types | CFG-unreachable blocks, `ja +0` nops, dead register definitions | Needs prior simplification or dead defs; tail-call protected prefix disables unreachable/nop deletion and neutralizes dead defs instead |
| `bounds_check_merge` | Packet prog_types only: TC/XDP/SK_SKB/LWT | Packet guard ladder: `mov cursor, data; add cursor, const; compare cursor,data_end` with same root, same slow target, increasing const windows | Non-packet prog_type; TC layout mismatch (`ctx` offsets tracked as 0/4 only); variable window; different roots/targets/cmp kinds; growth >24; unsafe interleaving; branch targets; live cursor |
| `skb_load_bytes_spec` | TC only: `sched_cls` and `sched_act` | Regular helper call #26 with arg1 ctx, constant non-negative offset, fp-relative stack dest, constant len 1..8 | Non-TC prog_type; no helper #26; helper not regular call; offset/len not constant; len 0 or >8; dest not negative fp stack; call is branch target; limited arg tracking |
| `bulk_memory` | All prog_types | `memcpy`: contiguous load/store pairs, same width, >=32B. `memset`: contiguous stores of repeated zero byte, >=32B | kfunc/packed ABI unavailable; short/scattered stores; branch target inside run; live temp; overlapping same-base copy; different-base alias not proven; nonzero memset rejected by daemon matcher |

No per-app or per-prog_type pass exclusions were found in
`corpus/config/benchmark_config.yaml`; the 11 passes are enabled globally.
The KVM artifact shows all expected kinsn modules loaded.

## Per-App Diagnosis

### BCC and bpftrace tracing tools

The no-change BCC/bpftrace apps are mostly small tracing programs:

- `bcc/execsnoop`, `bcc/tcpconnect`, `bpftrace/capable`, `bpftrace/tcplife`,
  `bpftrace/tcpretrans`: `kprobe`
- `bcc/vfsstat`, `bcc/opensnoop`: `tracing`
- `bcc/syscount`, `bcc/tcplife`, `bpftrace/biosnoop`, `bpftrace/runqlat`:
  tracepoint/raw tracepoint style
- `bpftrace/vfsstat`: one kprobe plus one perf_event

Why the existing 11 passes miss:

- Packet-only passes (`bounds_check_merge`, `skb_load_bytes_spec`) are
  irrelevant for these prog_types.
- `wide_mem`, `rotate`, `extract`, and `endian_fusion` require very specific
  adjacent ALU/load idioms. These tools are dominated by helper calls, event
  construction, map updates, and field reads, not byte recomposition or
  packet-endian parsing.
- `map_inline` needs a constant-key lookup whose returned value is consumed by
  fixed-offset scalar loads. These tools more often use dynamic keys
  (`pid`, `tid`, syscall id, socket tuple) and update/output paths; map values
  are not stable scalar constants.
- `const_prop` and `dce` only help after exact constants or branch folding are
  discovered. In these programs, most values come from ctx fields, helper
  returns, and dynamic keys, so the exact-constant lattice usually does not
  produce a final bytecode change.

The BCC apps that did change (`capable`, `bindsnoop`, `biosnoop`, `runqlat`)
are the exception because they contain one of the narrow bitfield/endian/DCE
forms that the current peepholes already recognize.

### Calico

`calico/felix` loaded 6 `sched_cls` programs. Four are very small allow/deny
programs (`344` xlated bytes each), one is a tiny test program (`24` bytes),
and `conntrack_cleanup` is `1544` bytes.

Likely blockers:

- `bounds_check_merge` is nominally enabled for `sched_cls`, but the scanner
  tracks packet data/data_end as ctx offsets `0/4`. TC `__sk_buff` uses
  `76/80`, the same offsets already encoded in `skb_load_bytes_spec`. This is
  a real coverage bug for TC direct-packet guard merging.
- `skb_load_bytes_spec` only helps if the live program still calls helper #26
  with constant len <=8. These live Calico programs did not keep a final rewrite
  through that matcher.
- `map_inline` is unlikely to apply because Calico datapath maps use dynamic
  packet/endpoint keys and map types beyond the direct scalar-load subset.
- `wide_mem` avoids likely packet pointers in packet programs, so packet header
  byte ladders are intentionally skipped.

### Cilium

The KVM run has 16 Cilium programs: 14 `sched_cls` datapath programs and 2
small `tracing` dump programs. Program names include `cil_from_host`,
`cil_from_netdev`, `cil_to_host`, `tail_handle_ipv4_from_host`,
`tail_handle_ipv4_from_netdev`, and `tail_drop_notify`.

Likely blockers:

- The TC `bounds_check_merge` context-layout bug blocks the most obvious packet
  guard opportunity.
- Cilium's datapath is tail-call and map heavy. Current `map_inline` excludes
  prog arrays and does not specialize dynamic keys, and `dce/const_prop` are
  conservative around tail-call protected prefixes.
- `wide_mem` skips likely packet-pointer byte ladders in packet programs.
- `skb_load_bytes_spec` only handles a narrow TC helper pattern with len <=8.
  Prior helper census showed Cilium has many `skb_load_bytes`/`skb_store_bytes`
  opportunities in static objects, but the current live pass only covers a
  small subset and does not handle stores.

### Katran

Katran loaded `xdp_root` (`136` bytes), `balancer_ingress` (`23840` bytes,
XDP), and `healthcheck_encap` (`1000` bytes, `sched_cls`).

Likely blockers:

- `xdp_root` is intentionally tiny bootstrap code and has no meaningful local
  peephole surface.
- `balancer_ingress` is the real target, but XDP packet parsing tends to use
  packet-pointer guards, endian/header parsing, map lookups, and tail calls.
  Existing passes cover only narrow adjacent endian forms and conservative
  packet-pointer wide loads.
- Older non-compact artifacts showed raw scan sites in Katran-like programs
  (`wide_mem`, `map_inline`, `endian_fusion`), so the current compact artifact
  cannot prove true zero raw sites. It only proves no final rewrite was kept.
- The current bounds-check merge only handles constant increasing ladders with
  the same slow target and small window growth; Katran's parser paths are more
  complex.

### otelcol-ebpf-profiler

The profiler loaded 12 `perf_event` unwinder programs and one tracepoint
program. The unwinder programs are large: several are 25-37K xlated bytes.

Likely blockers:

- Packet-only passes are irrelevant.
- The code shape is stack unwinding and runtime/language-specific frame
  walking. It is heavy on pointer chasing, helper calls, bounded control flow,
  and dynamic map state, not the adjacent byte/shift/endian forms currently
  targeted.
- `map_inline` is unlikely to apply because keys and stack/frame identifiers
  are dynamic, and output maps are typically not direct scalar-load candidates.
- `bulk_memory` only sees long contiguous scalarized copies or zero fills. Large
  program size does not imply contiguous 32B copy/zero runs in BPF bytecode.

### Tetragon

Tetragon loaded 287 programs in the KVM run:

- 270 `kprobe`
- 9 `tracepoint`
- 7 `raw_tracepoint`
- 1 `socket_filter`

The dominant feature is repetition. The 287 programs include repeated generic
policy pipeline skeletons:

- `generic_kprobe_{filter_arg,process_filter,setup_event,process_event,actions,output,event}`
  repeated 33 times each
- `generic_retkprobe_{filter_arg,event,output,actions}` repeated 9 times each
- one-off execve and raw tracepoint/tracepoint variants

Why the current passes miss or fail to keep rewrites:

- Most Tetragon programs are tracing/kprobe, so packet-only passes are
  irrelevant.
- The generic pipeline is a policy interpreter: dynamic selector maps, action
  maps, event output, argument extraction, and helper calls. Current
  `map_inline` only handles constant-key scalar loads from direct-readable map
  values, not dynamic selector evaluation or perf/ring/ringbuf outputs.
- Repetition helps only if the pass targets the shared skeleton pattern. The
  current peepholes target local instruction idioms, not Tetragon's higher-level
  policy/filter structure.
- Older non-compact Tetragon artifacts did show raw `map_inline`, `wide_mem`,
  and `bulk_memory` scan sites in smaller Tetragon/default runs. Therefore the
  2026-04-28 compact artifact should not be read as proof that all 287 programs
  had zero raw sites; it only shows zero final kept rewrites.

## Restrictions Worth Relaxing

### P0: fix TC ctx layout in `bounds_check_merge`

Current state: `bounds_check_merge` is enabled for `sched_cls`/`sched_act`, but
`is_ctx_data_load()` and `is_ctx_data_end_load()` only recognize offsets `0`
and `4`. That is XDP-style layout. TC direct packet access uses
`__sk_buff->data`/`data_end` offsets `76/80`, which `skb_load_bytes_spec`
already knows.

Expected impact:

- Candidate apps: `cilium/agent` (14 TC programs), `calico/felix` (6 TC
  programs), `katran` (1 TC program), plus any future TC corpus app.
- Expected new applied programs: likely a subset, not all 21 candidates. This
  should be the first low-risk coverage fix because it removes an internal
  inconsistency in the pass.

Complexity: low to medium.

Risk: low. The existing verifier-backed per-pass check will reject unsafe
rewrites.

### P0: keep compact per-pass no-op summaries

This does not improve program count directly, but it is necessary to stop
guessing. Store, for successful no-op programs, a compact per-pass summary:
`pass_name`, raw sites seen if available, `sites_applied`,
`sites_skipped`, `skip_reasons`, `verify.status`.

Expected impact:

- New applied programs: none.
- Debug impact: high. It will distinguish true zero-match from verifier
  rollback and site-level vetoes in Tetragon/Katran/Cilium.

Complexity: low.

Risk: low if capped/aggregated rather than storing full bytecode traces.

### P0/P1: allow nonzero `bulk_memory` memset when module supports it

The daemon matcher rejects any memset fill byte other than zero. The x86 and
arm64 bulk-memory payload/module paths already carry `fill_imm8` and support
nonzero immediate fills.

Expected impact:

- Candidate apps: tracing/profiling programs that initialize event structs with
  sentinel values or repeated nonzero bytes.
- Expected new applied programs: unknown without a scan, probably modest, but
  the implementation gap is small.

Complexity: low.

Risk: low to medium. Need tests for sign/width truncation and verifier
acceptance.

### P1: site-level verifier retry for packet-pointer `wide_mem`

Current state: `wide_mem` skips likely packet pointers in packet prog_types
because wider packet loads may fail verifier alignment/range checks.

Better policy: try candidate packet sites under verifier and bisect/drop only
the rejected site(s), instead of blanket skipping all likely packet-pointer
wide loads.

Expected impact:

- Candidate apps: Cilium, Katran, Calico packet parsers.
- Expected new applied programs: small to medium; depends on how often existing
  bounds checks prove the full wide access.

Complexity: medium because current pass verification is per-pass, not per-site.

Risk: low for safety, medium for implementation complexity and compile time.

### P1: broaden `skb_load_bytes_spec`

Current state: only TC, helper #26, const offset, fp stack dest, and len <=8.

Useful extensions:

- Raise the len cap with a cost model for common lengths 14/16/20/40.
- Add `skb_store_bytes` narrow specialization for `flags=0`.
- Support additional packet prog_types where the helper contract and ctx layout
  are well understood (`socket_filter`, `cgroup_skb`, possibly flow dissector).

Expected impact:

- Prior helper census found `skb_load_bytes`/`skb_store_bytes` concentrated in
  Cilium and Calico static objects.
- Live impact depends on whether the app still loads helper-based paths in the
  benchmark workload.

Complexity: medium.

Risk: medium. Non-linear skb semantics and code-size growth need explicit
policy gates.

### P1: broaden `map_inline` map/key coverage

Current state: direct-readable map types only, constant keys, verifier-guided
keys only up to 8 bytes, mutable hash requires immediate null check, and lookup
result must feed fixed-offset scalar loads.

Useful extensions:

- Support verifier-guided keys larger than 8 bytes by reconstructing byte
  ranges, not just a `u64`.
- Add `PERCPU_HASH`/`LRU_PERCPU_HASH` support when all per-CPU slots are
  byte-identical, analogous to existing `PERCPU_ARRAY` collapse.
- Add a guarded monomorphic dynamic-key specialization for hot map lookups,
  rather than requiring static constant keys.

Expected impact:

- Candidate apps: Tetragon, Cilium, otelcol, BCC/bpftrace map-heavy tools.
- Expected new applied programs: medium to high if dynamic-key specialization
  is included; low to medium for only >8B/percpu widening.

Complexity: medium for key-size/percpu widening; high for dynamic-key PIC.

Risk: medium to high. Correct invalidation and per-CPU semantics are the hard
parts.

### P1: remove whole-program rotate subprog veto

Current state: `rotate` skips an entire program if any BPF pseudo-call exists.
The actual matcher is local, and the repo already has subprogram-boundary
helpers in `map_inline`.

Expected impact:

- Candidate apps: large tracing/profiling programs with BPF-to-BPF calls.
- Expected new applied programs: probably low unless rotate idioms are common,
  but the restriction is broader than necessary.

Complexity: medium.

Risk: medium. Liveness and branch-target analyses must be subprog-aware.

### P1: support immediate operands in `cond_select`

Current state: the matcher finds MOV immediates, but packed ABI application
requires both true/false values to be registers.

Expected impact:

- Candidate apps: tracing filters that materialize boolean flags or small enum
  values.
- Expected new applied programs: unknown but likely broader than rotate/extract
  in tracing apps.

Complexity: medium. Needs either kinsn payload ABI support for immediates or
safe materialization without introducing register pressure bugs.

Risk: low to medium.

## New Optimization Opportunities

### Tracing/kprobe apps

These apps need passes that target helper-heavy observability code rather than
packet parsers:

1. `SETcc`/`CSET` boolean materialization
   - Pattern: compare/branch producing `0/1` or small boolean flags.
   - Coverage target: BCC, bpftrace, Tetragon filters.
   - Risk: low to medium; similar to `cond_select` but specialized for boolean
     results.

2. Safe-load/probe-read specialization
   - Pattern: fixed-size `bpf_probe_read_kernel` into stack followed by scalar
     use.
   - Coverage target: Tracee, Tetragon, BCC.
   - Risk: high. General `probe_read_kernel` has nofault plus zero-on-error
     semantics and accepts opaque pointers. Only a typed, verifier-proven
     subset is safe as pure bytecode; the general form needs a safe-load kinsn
     or helper-inline contract.

3. Event struct store coalescing
   - Pattern: many scalar stack stores constructing event payloads, then perf or
     ringbuf output.
   - Coverage target: Tetragon, bpftrace, BCC, otelcol.
   - Risk: medium. This is more like stack-store DCE/coalescing than the current
     contiguous zero-fill matcher.

4. Policy-map specialization for Tetragon
   - Pattern: repeated generic policy skeletons evaluating selector/action maps.
   - Coverage target: the 33x repeated generic kprobe pipeline and 9x retkprobe
     pipeline.
   - Risk: high but high leverage. The repetition means one robust skeleton
     specialization could affect dozens or hundreds of programs.

### Tetragon-specific

The most promising Tetragon direction is not another local peephole. It is a
runtime-guided specialization of the repeated generic policy pipeline:

- specialize stable policy/action map values;
- fold selector branches when policy maps are unchanged;
- DCE unreachable action/output paths after specialization;
- invalidate and re-REJIT when policy maps change.

This is conceptually an extension of `map_inline + const_prop + dce`, but it
needs dynamic-key support and map invalidation at the policy-object level.

### Networking apps: Cilium, Calico, Katran

1. TC/XDP bounds-check normalization
   - Fix TC ctx offsets.
   - Support variable guard windows where the variable is verifier-range-bound.
   - Hoist/merge guards with different but equivalent slow exits.

2. Tail-call specialization
   - Cilium and Katran are tail-call-heavy.
   - Direct program-array PIC specialization can remove map lookup and indirect
     tail-call overhead for hot monomorphic keys.
   - Risk: high; also depends on kernel poke descriptor constraints.

3. Broader endian/header parsing
   - Current `endian_fusion` only handles adjacent `LDX + BPF_END`.
   - Packet parsers often have offset arithmetic, compare-against-network-order
     constants, byte ladders, or non-adjacent endian swaps.
   - Add matcher variants for load-after-cursor-adjust and compare-folded
     endian cases.

4. Packet helper specialization
   - Extend `skb_load_bytes_spec`; add `skb_store_bytes(flags=0)`.
   - Particularly relevant for TC datapaths, based on prior helper census.

5. Map lookup specialization beyond constant keys
   - Endpoint/policy/service maps use dynamic packet keys.
   - Constant-key map_inline will not cover the hot path; guarded dynamic-key
     specialization is needed.

## Priority Plan

| priority | proposal | expected applied-program impact | complexity | correctness/safety risk |
|---|---|---:|---|---|
| P0 | Persist compact per-pass summaries for no-op programs | 0, but removes diagnostic blind spot | low | low |
| P0 | Fix `bounds_check_merge` TC ctx offsets `76/80` | up to 21 candidate packet programs; likely subset | low-medium | low |
| P0/P1 | Enable nonzero immediate `bulk_memory` memset | unknown, likely modest | low | low-medium |
| P1 | Site-level verifier retry for packet `wide_mem` | Cilium/Katran/Calico subset | medium | low safety, medium implementation |
| P1 | Broaden `skb_load_bytes_spec` and add `skb_store_bytes(flags=0)` | networking apps if helper paths are live | medium | medium |
| P1 | `map_inline` >8B keys and uniform `PERCPU_HASH` | map-heavy tracing/networking subset | medium | medium |
| P1 | Immediate-operand `cond_select` / boolean `SETcc` | tracing filters; likely several apps | medium | low-medium |
| P1 | Subprog-aware `rotate` instead of whole-program veto | low-medium | medium | medium |
| P2 | Tetragon policy pipeline specialization | high for Tetragon if robust | high | high |
| P2 | Tail-call PIC specialization | high for Cilium/Katran | high | high |
| P2 | Safe-load kinsn for probe-read-like typed subset | high for tracing, especially Tracee/Tetragon | high | high |

## Recommended Next Measurement

Before implementing broad new passes, run one diagnostic corpus variant that
stores compact `passes[]` summaries for successful no-op programs. The exact
question to answer is:

- For each no-final-rewrite app, how many raw sites did each pass see?
- Which no-op programs were true zero-match?
- Which saw sites but lost them to site vetoes, verifier rejection, or final
  no-change cleanup?

Without that, Tetragon and Katran remain ambiguous because older non-compact
artifacts show candidate sites in similar programs while the current compact
artifact only shows no final rewrite.
