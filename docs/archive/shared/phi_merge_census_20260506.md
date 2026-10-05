# PHI-style merge simplification census

Date: 2026-05-06

HEAD: `67e90225`

## Summary

Recommendation: **second wave, imm-only first**.

The supported runtime corpus has nonzero PHI-style merge opportunities under a
conservative static gate:

- `1,462` unique scalar/liveness-qualified sites across `121,556` CFG merge
  points.
- `1,316` sites are `all-assign-same-imm`; this is the only clearly attractive
  first implementation shape.
- `61` are `all-copy-same-reg` and `85` are `same-alu-op`; these need stronger
  liveness/source-interference and verifier-state checks before implementation.
- `46` merge points are strict one-insn-body diamonds, counted as a structural
  subset, not added to the unique total. Most classic diamonds appear already
  simplified by LLVM or covered by existing `cond_select`/SETcc-style work.

This is not a first-wave pass because the payoff estimate is very loose and the
safe transform is code sinking at CFG joins, not a simple local peephole. It is
worth a second-wave prototype limited to scalar immediate assignments:

```text
pred1: rN = K; goto M
pred2: rN = K; goto M
M:     use rN
```

For helper calls, `use rN` often cannot become an immediate operand. The viable
rewrite is usually sinking one `rN = K` into the merge block and deleting the
per-edge copies.

## Inputs And Tools

Inputs:

- Requested root scan: all `.bpf.o` under `runner/repos/` and `corpus/bcf/`.
- Supported runtime scan:
  `corpus/build/{tracee,tetragon,bpftrace,bcc,katran,cilium,opentelemetry-ebpf-profiler}`.

The prompt says "8 supported apps" but lists seven directories. This matches the
current supported-app rule in this tree; Calico is not scanned as supported.

Tools:

- Python 3.12.3 + `pyelftools 0.32`, after
  `source /home/yunwei37/workspace/.venv/bin/activate`.
- `llvm-objdump -d`: Ubuntu LLVM `18.1.3`, used for PC spot checks.
- `bpftool`: `v7.7.0`, libbpf `v1.7`.

Parse errors: `0`.

`functions` below are ELF `STT_FUNC` slices, falling back to an executable
section when function symbols are absent. This is stricter than the older
section-count convention because this census needs per-function CFGs.

## CFG Method

Scanner:

- Decode executable `EM_BPF` sections as 8-byte eBPF instructions.
- Treat `LDDW` as one logical instruction plus one pseudo slot, so CFG
  fallthrough skips the second slot.
- Build basic-block leaders from function entry, jump targets, conditional
  fallthroughs, and post-terminator code.
- Edges:
  - `JA`: target only.
  - conditional `JMP`/`JMP32`: target and fallthrough.
  - `EXIT`: no successor.
  - calls and ordinary instructions: fallthrough.

Candidate gate:

- A merge block must have at least two predecessor blocks.
- For each incoming predecessor, inspect the last five non-control tail
  instructions and keep the last register write per destination.
- A candidate exists when every predecessor has the same destination register
  and the same tail signature:
  - `all-assign-same-imm`: `MOV K` or `LDDW K`;
  - `all-copy-same-reg`: `MOV X` from the same source register;
  - `same-alu-op`: same ALU width, op, source mode, and operand.
- Exclude if the first merge instruction redefines the destination.
- Exclude if the destination is not live-in to the merge block.
- Exclude `same-alu-op` at cyclic merge blocks to avoid induction-variable
  false positives.
- Scalar gate:
  - immediates are scalar;
  - copies require the copied source to be conservatively scalar at each tail;
  - ALU sites require the result destination to be conservatively scalar after
    each tail instruction;
  - pointer/unknown values are rejected.
- `diamond-collapsible` is counted when a strict two-predecessor merge has a
  conditional header whose two successors are one-insn bodies that both enter
  the merge. It is a subset marker, not an extra unique site.

## Scan Sets

| scan set | objects | exec objects | functions | eBPF insns | merge points | raw tail matches | strict unique sites | diamond subset |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| requested roots: `runner/repos` + `corpus/bcf` | 60 | 60 | 193 | 22,005 | 1,185 | 87 | 13 | 0 |
| supported runtime corpus | 178 | 177 | 1,651 | 2,210,713 | 121,556 | 14,847 | 1,462 | 46 |

`corpus/build/tetragon/bpf_alignchecker.o` has no executable BPF section, so it
is counted as an object but not as an executable object.

## Requested Roots

| root | objects | functions | merge points | all-assign-same-imm | all-copy-same-reg | same-alu-op | diamond-collapsible | total unique |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `runner/repos` | 43 | 155 | 711 | 0 | 0 | 1 | 0 | 1 |
| `corpus/bcf` | 17 | 38 | 474 | 12 | 0 | 0 | 0 | 12 |
| **total** | **60** | **193** | **1,185** | **12** | **0** | **1** | **0** | **13** |

Representative requested-root sites:

| object:function | section | pred PCs | merge PC | kind |
| --- | --- | --- | ---: | --- |
| `runner/repos/katran/_build/deps/bpfprog/bpf/balancer.bpf.o:balancer_ingress` | `xdp` | `155, 308` | 311 | `same-alu-op`, `r1 RSH= 8` |
| `corpus/bcf/bcc/clang-20_-O1_ksnoop.bpf.o:ksnoop` | `.text` | `275, 284, 289, 294, 299, 304` | 306 | `all-assign-same-imm`, `r2 = 8` |
| `corpus/bcf/bcc/clang-21_-O1_ksnoop.bpf.o:ksnoop` | `.text` | `661, 696` | 698 | `all-assign-same-imm`, `r1 = 0` |

## Per-App Census

`diamond-collapsible` is a subset count. `total unique` is
`imm + copy + alu`, without adding the diamond subset again.

| app | objects | functions | merge points | all-assign-same-imm | all-copy-same-reg | same-alu-op | diamond-collapsible | total unique |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| tracee | 3 | 175 | 15,820 | 292 | 0 | 18 | 44 | 310 |
| tetragon | 94 | 887 | 92,639 | 433 | 20 | 37 | 0 | 490 |
| bpftrace | 9 | 22 | 27 | 0 | 0 | 0 | 0 | 0 |
| bcc | 57 | 397 | 1,261 | 31 | 0 | 0 | 2 | 31 |
| katran | 5 | 7 | 128 | 0 | 0 | 1 | 0 | 1 |
| cilium | 7 | 157 | 11,473 | 556 | 41 | 29 | 0 | 626 |
| otelcol-ebpf-profiler | 3 | 6 | 208 | 4 | 0 | 0 | 0 | 4 |
| **total** | **178** | **1,651** | **121,556** | **1,316** | **61** | **85** | **46** | **1,462** |

## Predecessor Histogram

Per merge basic block.

| predecessor count | requested roots | supported runtime |
| --- | ---: | ---: |
| 2 | 743 | 100,398 |
| 3 | 191 | 10,470 |
| 4 | 93 | 3,747 |
| 5 | 37 | 1,949 |
| 6 | 32 | 829 |
| 7 | 13 | 554 |
| 8 | 29 | 975 |
| 9 | 26 | 388 |
| 10-16 | 10 | 1,190 |
| 17-32 | 9 | 648 |
| 33-64 | 2 | 131 |
| 65-128 | 0 | 130 |
| 129-256 | 0 | 81 |
| >256 | 0 | 66 |
| **total** | **1,185** | **121,556** |

Largest supported merge fan-in observed: `642` predecessor blocks.

## Top Objects

Supported runtime corpus, ranked by strict unique candidate count.

| rank | object | app | imm | copy | alu | diamond subset | total |
| ---: | --- | --- | ---: | ---: | ---: | ---: | ---: |
| 1 | `corpus/build/tracee/tracee.bpf.o` | tracee | 292 | 0 | 18 | 44 | 310 |
| 2 | `corpus/build/cilium/bpf_host.bpf.o` | cilium | 202 | 13 | 6 | 0 | 221 |
| 3 | `corpus/build/cilium/bpf_lxc.bpf.o` | cilium | 119 | 15 | 5 | 0 | 139 |
| 4 | `corpus/build/cilium/bpf_overlay.bpf.o` | cilium | 85 | 7 | 0 | 0 | 92 |
| 5 | `corpus/build/cilium/bpf_wireguard.bpf.o` | cilium | 82 | 6 | 0 | 0 | 88 |
| 6 | `corpus/build/cilium/bpf_xdp.bpf.o` | cilium | 68 | 0 | 18 | 0 | 86 |
| 7 | `corpus/build/tetragon/bpf_generic_fentry_v511.o` | tetragon | 12 | 1 | 0 | 0 | 13 |
| 8 | `corpus/build/tetragon/bpf_generic_fentry_v53.o` | tetragon | 12 | 0 | 0 | 0 | 12 |
| 9 | `corpus/build/tetragon/bpf_generic_kprobe_v511.o` | tetragon | 12 | 0 | 0 | 0 | 12 |
| 10 | `corpus/build/tetragon/bpf_generic_kprobe_v53.o` | tetragon | 12 | 0 | 0 | 0 | 12 |
| 11 | `corpus/build/tetragon/bpf_generic_kprobe_v61.o` | tetragon | 8 | 1 | 3 | 0 | 12 |
| 12 | `corpus/build/tetragon/bpf_generic_lsm_core_v511.o` | tetragon | 11 | 1 | 0 | 0 | 12 |
| 13 | `corpus/build/tetragon/bpf_generic_rawtp_v511.o` | tetragon | 11 | 1 | 0 | 0 | 12 |
| 14 | `corpus/build/tetragon/bpf_generic_uprobe_v511.o` | tetragon | 12 | 0 | 0 | 0 | 12 |
| 15 | `corpus/build/tetragon/bpf_generic_uprobe_v53.o` | tetragon | 12 | 0 | 0 | 0 | 12 |
| 16 | `corpus/build/tetragon/bpf_multi_kprobe_v511.o` | tetragon | 12 | 0 | 0 | 0 | 12 |
| 17 | `corpus/build/tetragon/bpf_multi_kprobe_v53.o` | tetragon | 12 | 0 | 0 | 0 | 12 |
| 18 | `corpus/build/tetragon/bpf_multi_kprobe_v61.o` | tetragon | 8 | 1 | 3 | 0 | 12 |
| 19 | `corpus/build/tetragon/bpf_multi_uprobe_v511.o` | tetragon | 12 | 0 | 0 | 0 | 12 |
| 20 | `corpus/build/tetragon/bpf_generic_fentry_v61.o` | tetragon | 8 | 1 | 2 | 0 | 11 |

## Top Functions

Supported runtime corpus, ranked by strict unique candidate count.

| rank | object:function | example merge PC | imm | copy | alu | total |
| ---: | --- | ---: | ---: | ---: | ---: | ---: |
| 1 | `corpus/build/cilium/bpf_host.bpf.o:cil_to_netdev` | 4445 | 23 | 2 | 1 | 26 |
| 2 | `corpus/build/cilium/bpf_host.bpf.o:tail_handle_ipv4_from_netdev` | 40629 | 24 | 0 | 0 | 24 |
| 3 | `corpus/build/cilium/bpf_host.bpf.o:cil_host_policy` | 13456 | 20 | 2 | 1 | 23 |
| 4 | `corpus/build/cilium/bpf_host.bpf.o:tail_handle_ipv6_from_netdev` | 32366 | 23 | 0 | 0 | 23 |
| 5 | `corpus/build/cilium/bpf_xdp.bpf.o:tail_lb_ipv6` | 21872 | 16 | 0 | 3 | 19 |
| 6 | `corpus/build/cilium/bpf_wireguard.bpf.o:tail_handle_ipv6` | 17507 | 18 | 0 | 0 | 18 |
| 7 | `corpus/build/cilium/bpf_wireguard.bpf.o:tail_handle_ipv4` | 20786 | 16 | 0 | 0 | 16 |
| 8 | `corpus/build/cilium/bpf_xdp.bpf.o:tail_lb_ipv4` | 19088 | 16 | 0 | 0 | 16 |
| 9 | `corpus/build/cilium/bpf_host.bpf.o:tail_nodeport_nat_ingress_ipv4` | 15093 | 14 | 0 | 1 | 15 |
| 10 | `corpus/build/cilium/bpf_lxc.bpf.o:tail_nodeport_nat_ingress_ipv6` | 6789 | 11 | 2 | 0 | 13 |

## Representative Sites

| object:function | section | pred PCs | merge PC | kind |
| --- | --- | --- | ---: | --- |
| `corpus/build/tracee/tracee.bpf.o:sys_enter_submit` | `raw_tracepoint/sys_enter_submit` | `83, 86` | 94 | `all-assign-same-imm`, `r1 = 1` |
| `corpus/build/tracee/tracee.bpf.o:trace_sys_enter` | `raw_tracepoint/trace_sys_enter` | `682, 686, 688` | 689 | `all-assign-same-imm`, `r1 = 8` |
| `corpus/build/cilium/bpf_host.bpf.o:cil_to_netdev` | `tc/entry` | `4361, 4403, 4442` | 4445 | `same-alu-op`, `w1 &= w2` |
| `corpus/build/cilium/bpf_host.bpf.o:cil_to_netdev` | `tc/entry` | `4774, 4777` | 4779 | `all-assign-same-imm`, `r2 = 0` |
| `corpus/build/tetragon/bpf_execve_event.o:event_execve` | `tracepoint/sys_execve` | `948, 977, 1219` | 1220 | `all-copy-same-reg`, `r1 = r6` |
| `corpus/build/bcc/libbpf-tools/.output/bindsnoop.bpf.o:ipv4_bind_entry` | `kprobe/inet_bind` | `1, 5` | 10 | `all-assign-same-imm`, `r1 = 0` |
| `corpus/build/katran/balancer.bpf.o:balancer_ingress` | `xdp` | `148, 298` | 301 | `same-alu-op`, `r1 >>= 8` |
| `corpus/build/opentelemetry-ebpf-profiler/native_stack_trace.bpf.o:perf_unwind_native` | `perf_event/unwind_native` | `220, 225, 233, 240, 247, 253, 259, 265, 271, 274, 277, 280, 283, 286, 289, 292` | 294 | `all-assign-same-imm`, `r1 = 0` |

## Payoff Upper Bound

Baseline counter source:

`corpus/results/x86_kvm_p89_kop_corpus_20260430_131403_981524/details/result.json`

The result status is `error`, so these counters are context only. Counts are
baseline `run_cnt_delta` summed by runner.

| app | strict unique sites | baseline BPF runs | all-sites-execute upper bound | 1-2 cycle upper bound |
| --- | ---: | ---: | ---: | ---: |
| tracee | 310 | 11,513,652 | 3,569,232,120 | 3.6B-7.1B cycles |
| tetragon | 490 | 7,260,591 | 3,557,689,590 | 3.6B-7.1B cycles |
| bcc | 31 | 4,837,729 | 149,969,599 | 150.0M-299.9M cycles |
| bpftrace | 0 | 810,019 | 0 | 0 |
| cilium | 626 | 17,710 | 11,086,460 | 11.1M-22.2M cycles |
| katran | 1 | 768 | 768 | 768-1,536 cycles |
| otelcol-ebpf-profiler | 4 | 260 | 1,040 | 1,040-2,080 cycles |
| **total** | **1,462** | - | **7,287,979,577** | **7.3B-14.6B cycles** |

This is an intentionally loose ceiling: it assumes every static candidate in an
app executes on every BPF program run for that app. It should not be quoted as
expected speedup. The useful signal is ranking: Tracee, Tetragon, and Cilium
hold nearly all static sites; BPFTrace and Katran have effectively none.

Diamond collapse is not added to payoff. It can remove a conditional branch in
some shapes, but that overlaps with `cond_select` and SETcc/CSET-style work.

## Risks And LLVM Signal

Risks:

- Pointer values must stay out. The static scanner rejects unknown/pointer-like
  copy and ALU sites, but a real pass should still consume verifier states.
- `all-copy-same-reg` is not just value equality. The source register must stay
  available until every replaced use, and source/destination liveness must not
  conflict.
- `same-alu-op` on `ADD`/`SUB` can be pointer arithmetic. The prototype should
  avoid it unless verifier state proves scalar-only.
- Helper calls cannot consume immediates directly. Common immediate sites need
  code sinking before the call, with branch fixups, not just operand rewrite.
- Multi-predecessor and loop-header merges are common. Moving code into a loop
  header or switch join must preserve per-iteration semantics and verifier
  initialization on every path.
- Missing initialization must fail closed. A CFG bug that sinks a write past a
  path where the register is not initialized would surface as verifier
  `!read_ok`/type errors.

LLVM signal:

- The strict supported count is `1,462 / 121,556` merge points, about `1.2%`.
- `46` strict diamonds remain, only about `0.04%` of merge points. True
  if/else/end same-body diamonds are mostly gone by LLVM SimplifyCFG/SSA PHI
  lowering before BPF bytecode emission.
- The surviving sites are mostly generated-code helper argument setup, switch
  joins, or large tail-merged error paths. `all-assign-same-imm` dominates
  (`1,316 / 1,462`, about `90%`).
- Raw syntactic tail matches were much higher (`14,847`), but liveness/scalar
  gates removed about `90%`. This is a warning against a simple textual CFG
  peephole.

## Conclusion

Status: **second wave**.

Do not implement a broad PHI merge pass in the first wave. The clean subset is
real but narrower than the raw CFG count suggests. A second-wave prototype
should start with `all-assign-same-imm` only, require destination live-in at the
merge, sink one scalar immediate assignment into the merge block, and delete the
per-edge duplicates after ReJIT verification. Leave `all-copy-same-reg`,
`same-alu-op`, and diamond branch deletion for a later verifier-state-driven
version.
