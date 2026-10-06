# LICM census

Date: 2026-05-06

HEAD: `67e90225`

## Summary

Recommendation: **second wave only, stack-load-only, verifier-state-gated**.

The supported runtime corpus has `934` open-coded natural loops and `49`
`bpf_loop` helper calls. `bpf_loop` calls are excluded because the kernel has a
special inliner at `vendor/linux-framework/kernel/bpf/verifier.c:24729-24864`;
there is no general verifier LICM pass for open-coded loops.

Under the strict static gate, the supported corpus has `118` unique LICM sites,
all of them invariant stack reloads into callee-saved registers. The requested
roots scan has `0` sites. I found `0` constant-load, `0` invariant
`bpf_map_lookup_elem`, and `0` ALU LICM sites after excluding loop-carried
recurrences and caller-saved helper-call clobbers.

This is not a good Paper A first-wave pass: the only signal is spill reloads
around helper-heavy path-walk loops, and making that safe needs verifier stack
state/helper memory bounds. It is plausible as a later narrow pass if the daemon
can consume verifier facts from the preceding ReJIT log.

## Data And Tools

Inputs:

- Requested root scan: all `.bpf.o` under `runner/repos/` and `corpus/bcf/`.
- Supported runtime scan: `.bpf.o` plus Tetragon `.o` eBPF objects under
  `corpus/build/{tracee,tetragon,bpftrace,bcc,katran,cilium,opentelemetry-ebpf-profiler}`.
- The supported app list has seven apps, matching the current tree.

Tools:

- `source /home/yunwei37/workspace/.venv/bin/activate`
- Python `3.12.3` + `pyelftools 0.32`
- `llvm-objdump -d --line-numbers`: Ubuntu LLVM `18.1.3`
- `bpftool v7.7.0`, libbpf `v1.7`

Scanner:

- Decoded executable `SHT_PROGBITS | SHF_EXECINSTR` sections as 8-byte eBPF
  instructions.
- Sliced CFG analysis by non-overlapping `STT_FUNC` starts inside each section;
  sections without function symbols were treated as one function.
- Existing census docs count executable sections as "functions"; for continuity
  that count is shown below as `exec sections`, while this LICM scan uses
  `STT_FUNC functions` for subprogram coverage.
- Parse errors: `0`.

| scan set | objects | executable objects | exec sections | STT_FUNC functions | eBPF insns | open-coded loops | `bpf_loop` calls | unique LICM sites |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| requested roots | 60 | 60 | 145 | 193 | 21,142 | 86 | 1 | 0 |
| supported runtime corpus | 178 | 177 | 775 | 1,651 | 2,174,279 | 934 | 49 | 118 |

`corpus/build/tetragon/bpf_alignchecker.o` is counted as a supported object but
has no executable BPF section.

## CFG And Loop Method

CFG construction:

- Instruction PCs are section-relative eBPF slots, matching `llvm-objdump`.
- `LD_IMM64` is treated as one real instruction occupying two slots.
- Conditional jumps add target and fallthrough edges; `JA` adds only target;
  `EXIT` has no successor.
- Helper and BPF-to-BPF calls are not loop edges. BPF-to-BPF callees are scanned
  through their own `STT_FUNC` slices when symbols exist.

Loop detection:

- Built dominators with the Cooper-Harvey-Kennedy iterative idom algorithm.
- A back edge is `tail -> header` where `header` dominates `tail`.
- The natural loop body is the reverse predecessor closure from `tail` to
  `header`.
- Duplicate natural loops are keyed by `(header, body)`.
- `bpf_loop` helper id `181` is counted separately and excluded from
  open-coded-loop LICM.

Candidate gate:

- `constant`: `LD_IMM64` in the loop only if its destination register has no
  other loop write and is not caller-saved across any helper call in the loop.
- `map_lookup`: helper id `1` only if `r1` and `r2` are loop-invariant map/key
  values and a stack key has no explicit loop store in its key range.
- `stack_load`: `LDX` from `r10 + off` only if the exact stack byte range has no
  explicit loop store, the destination has no other loop write, and the register
  is not caller-saved across loop helpers.
- `ALU`: pure non-`MOV` ALU only if all operands are loop-entry invariant or
  produced by same-block invariant setup; loop-carried self-updates are rejected.
- Packet/other memory loads were audited but not counted as LICM candidates
  without verifier packet-pointer type and helper mutation state; strict static
  proof from ELF alone is `0`.

The scanner reports unique instruction sites. It observed `172` loop-level
stack-load occurrences, which collapse to `118` unique sites because some loads
are invariant in nested natural loops.

## Per-App Census

| app | objects | functions | open-coded loops | constant LICM | map_lookup LICM | stack load LICM | ALU LICM | total |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| tracee | 3 | 175 | 43 | 0 | 0 | 10 | 0 | 10 |
| tetragon | 94 | 887 | 865 | 0 | 0 | 108 | 0 | 108 |
| bpftrace | 9 | 22 | 5 | 0 | 0 | 0 | 0 | 0 |
| bcc | 57 | 397 | 17 | 0 | 0 | 0 | 0 | 0 |
| katran | 5 | 7 | 0 | 0 | 0 | 0 | 0 | 0 |
| cilium | 7 | 157 | 0 | 0 | 0 | 0 | 0 | 0 |
| otelcol-ebpf-profiler | 3 | 6 | 4 | 0 | 0 | 0 | 0 | 0 |
| **total** | **178** | **1,651** | **934** | **0** | **0** | **118** | **0** | **118** |

## Loop Body Histogram

Supported runtime corpus, natural-loop body length in eBPF instructions.

| loop body length | loops |
| --- | ---: |
| 1-8 | 3 |
| 9-16 | 187 |
| 17-32 | 101 |
| 33-64 | 372 |
| 65-128 | 114 |
| 129-256 | 69 |
| 257-512 | 4 |
| >512 | 84 |

## Top Objects

Unique LICM instruction sites.

| rank | object | app | stack load LICM | total |
| ---: | --- | --- | ---: | ---: |
| 1 | `corpus/build/tracee/tracee.bpf.o` | tracee | 10 | 10 |
| 2 | `corpus/build/tetragon/bpf_execve_event_v511.o` | tetragon | 4 | 4 |
| 3 | `corpus/build/tetragon/bpf_execve_event_v61.o` | tetragon | 4 | 4 |
| 4 | `corpus/build/tetragon/bpf_generic_fentry_v511.o` | tetragon | 4 | 4 |
| 5 | `corpus/build/tetragon/bpf_generic_fentry_v61.o` | tetragon | 4 | 4 |
| 6 | `corpus/build/tetragon/bpf_generic_kprobe_v511.o` | tetragon | 4 | 4 |
| 7 | `corpus/build/tetragon/bpf_generic_kprobe_v61.o` | tetragon | 4 | 4 |
| 8 | `corpus/build/tetragon/bpf_generic_lsm_core_v511.o` | tetragon | 4 | 4 |
| 9 | `corpus/build/tetragon/bpf_generic_lsm_core_v61.o` | tetragon | 4 | 4 |
| 10 | `corpus/build/tetragon/bpf_generic_rawtp_v511.o` | tetragon | 4 | 4 |
| 11 | `corpus/build/tetragon/bpf_generic_rawtp_v61.o` | tetragon | 4 | 4 |
| 12 | `corpus/build/tetragon/bpf_generic_tracepoint_v511.o` | tetragon | 4 | 4 |
| 13 | `corpus/build/tetragon/bpf_generic_tracepoint_v61.o` | tetragon | 4 | 4 |
| 14 | `corpus/build/tetragon/bpf_generic_uprobe_v511.o` | tetragon | 4 | 4 |
| 15 | `corpus/build/tetragon/bpf_generic_uprobe_v61.o` | tetragon | 4 | 4 |
| 16 | `corpus/build/tetragon/bpf_generic_usdt_v511.o` | tetragon | 4 | 4 |
| 17 | `corpus/build/tetragon/bpf_generic_usdt_v61.o` | tetragon | 4 | 4 |
| 18 | `corpus/build/tetragon/bpf_multi_kprobe_v511.o` | tetragon | 4 | 4 |
| 19 | `corpus/build/tetragon/bpf_multi_kprobe_v61.o` | tetragon | 4 | 4 |
| 20 | `corpus/build/tetragon/bpf_multi_uprobe_v511.o` | tetragon | 4 | 4 |

## Top Functions

All top functions are tied at two unique stack-load sites.

| rank | object:function | example PCs | total |
| ---: | --- | --- | ---: |
| 1 | `corpus/build/tetragon/bpf_execve_event_v511.o:event_execve` | `1989,1991` | 2 |
| 2 | `corpus/build/tetragon/bpf_execve_event_v511.o:execve_send` | `474,476` | 2 |
| 3 | `corpus/build/tetragon/bpf_execve_event_v61.o:event_execve` | `1274,1276` | 2 |
| 4 | `corpus/build/tetragon/bpf_execve_event_v61.o:execve_send` | `461,463` | 2 |
| 5 | `corpus/build/tetragon/bpf_generic_fentry_v511.o:generic_fentry_process_event` | `1459,1461` | 2 |
| 6 | `corpus/build/tetragon/bpf_generic_fentry_v511.o:generic_fentry_process_filter` | `18300,18302` | 2 |
| 7 | `corpus/build/tetragon/bpf_generic_fentry_v61.o:generic_fentry_process_event` | `933,935` | 2 |
| 8 | `corpus/build/tetragon/bpf_generic_fentry_v61.o:generic_fentry_process_filter` | `4210,4212` | 2 |
| 9 | `corpus/build/tetragon/bpf_generic_fexit_v511.o:generic_fexit_event` | `395,397` | 2 |
| 10 | `corpus/build/tetragon/bpf_generic_fexit_v61.o:generic_fexit_event` | `386,388` | 2 |

## Representative Sites

| app | object:function | section | PC | source | insn | loop |
| --- | --- | --- | ---: | --- | --- | --- |
| tetragon | `bpf_execve_event_v511.o:execve_send` | `tracepoint` | 474 | `runner/repos/tetragon/bpf/lib/bpf_d_path.h:163` | `r6 = *(u64 *)(r10 - 0x40)` | header `468`, len `43` |
| tetragon | `bpf_execve_event_v511.o:execve_send` | `tracepoint` | 476 | `runner/repos/tetragon/bpf/lib/bpf_d_path.h:161` | `r7 = *(u64 *)(r10 - 0x50)` | header `468`, len `43` |
| tracee | `tracee.bpf.o:tracepoint__sched__sched_process_fork` | `raw_tracepoint/sched_process_fork` | 1338 | `runner/repos/tracee/pkg/ebpf/c/common/memory.h:112` | `r7 = *(u64 *)(r10 - 0x48)` | header `1325`, len `39` |
| tracee | `tracee.bpf.o:trace_security_inode_unlink` | `kprobe/security_inode_unlink` | 1375 | `runner/repos/tracee/pkg/ebpf/c/common/filesystem.h:91` | `r9 = *(u64 *)(r10 - 0x58)` | header `1368`, len `57` |

These are bytecode-level candidates, not a final proof of verifier-safe motion.
The surrounding loops call helpers such as `bpf_probe_read_kernel`, so a real
pass needs verifier stack alias facts before moving the reload.

## Payoff Upper Bound

Recognizable constant trip counts were not reliable for the candidate loops:
the stack-load sites sit in helper-heavy path/memory walk loops whose bounds are
encoded through pointer comparisons and helper results. I therefore used the
requested conservative trip-count sweep `32 / 64 / 128`.

Existing one-second baseline run counts from
`corpus/results/x86_kvm_p89_kinsn_corpus_20260430_131403_981524/details/result.json`
are used only as an upper-bound frequency context:

| app | unique LICM sites | baseline BPF runs |
| --- | ---: | ---: |
| tracee | 10 | 11,513,652 |
| tetragon | 108 | 7,260,591 |

Gross upper-bound formula:
`sum(unique_sites_app * assumed_trip_count * app_baseline_BPF_runs)`.

This assumes every app-level BPF run reaches every candidate loop and treats one
removed BPF/JIT load as one cycle. That is intentionally much looser than a
paper metric; real loop-level frequency is unknown here.

| assumed trip count | gross upper-bound cycles/s |
| ---: | ---: |
| 32 | 28,776,971,136 |
| 64 | 57,553,942,272 |
| 128 | 115,107,884,544 |

Because the candidates are concentrated in path-walk code, the actual payoff is
likely far below this bound unless workload profiles show these loops are hot.

## Risks And LLVM Signal

Risks:

- Moving stack reloads across helper calls is only safe if the helper cannot
  write the stack range. The static scan only checks explicit `ST/STX`; the real
  pass needs verifier helper memory-argument bounds.
- Caller-saved `r0..r5` values are clobbered by helpers. The census excludes
  them; a pass must preserve that rule.
- Map lookup LICM needs map/key stability and no loop-local map update/delete
  alias. The strict scan found no such site.
- Packet-load LICM needs verifier packet-pointer type and mutation state; helpers
  such as skb-changing helpers can invalidate old packet pointers.
- Hoisting into preheaders can change code layout and verifier complexity. Every
  candidate must still go through per-pass `BPF_PROG_REJIT(log_level=2)`.

LLVM-already-done signal:

- `0` constant `LD_IMM64` sites survived the strict gate.
- `0` pure ALU sites survived after rejecting loop-carried recurrences.
- The only residual sites are stack reloads in callee-saved registers, which is
  consistent with LLVM having already hoisted ordinary scalar constants and ALU
  expressions while leaving helper/stack alias-sensitive reloads in place.

## Conclusion

Status: **second wave, not first wave**.

Do not build a broad static LICM pass for Paper A. The corpus does not support
constant, map-lookup, ALU, or packet-load LICM as first-wave work. A narrow
second-wave stack-load LICM may be worth revisiting only if it is driven by
verifier stack state and helper memory bounds from the preceding ReJIT log.
