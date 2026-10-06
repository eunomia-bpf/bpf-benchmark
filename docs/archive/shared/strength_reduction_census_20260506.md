# Strength reduction census: `MUL`/`MOD` by power-of-two immediates

Date: 2026-05-06

HEAD: `67e90225`

## Summary

Recommendation: **do not implement as a first-wave or second-wave standalone
pass**.

The strict direct-immediate census found **0** `MUL` or `MOD` power-of-two
constant sites in both requested scan sets:

- requested roots: `runner/repos/` + `corpus/bcf/` `.bpf.o`
- supported runtime corpus:
  `corpus/build/{tracee,tetragon,bpftrace,bcc,katran,cilium,opentelemetry-ebpf-profiler}`

The supported corpus does contain direct `MUL K` and `MOD K` instructions, but
all are non-power-of-two or negative `MUL` immediates. It also contains many
already-lowered `LSH K` and `AND (2^n-1)` instructions, which is consistent with
LLVM already reducing common power-of-two multiply/modulo source patterns before
BPF bytecode is emitted.

`DIV` power-of-two is not re-scanned here. The existing division report
`docs/tmp/division_reduction_research_20260430.md` already covers it: across
that broader `957` object scan, power-of-two K divisors were only linux-selftests
`1`/`2`, and supported apps had **0** power-of-two K divisors.

## Method

Inputs:

- Requested root scan: all `.bpf.o` under `runner/repos/` and `corpus/bcf/`.
- Supported runtime scan: `.bpf.o` plus Tetragon `.o` eBPF objects under the
  seven supported app directories listed above. The prompt says "8 supported
  apps" but lists seven, matching the current supported app list in this tree.

Tools:

- Python 3.12.3 + `pyelftools 0.32`, after
  `source /home/yunwei37/workspace/.venv/bin/activate`.
- `llvm-objdump -d`: Ubuntu LLVM `18.1.3`, used for spot checks and PC
  convention.
- `bpftool`: `v7.7.0`, libbpf `v1.7`.

Scanner:

- Decoded executable `SHT_PROGBITS | SHF_EXECINSTR` sections as 8-byte eBPF
  instructions.
- Counted direct immediate forms only:
  - `BPF_ALU{,64} | BPF_MUL | BPF_K`
  - `BPF_ALU{,64} | BPF_MOD | BPF_K`
- Candidate immediate gate:
  - `imm > 1`
  - positive signed `i32`
  - power of two
- Excluded:
  - `0` / `1`
  - negative immediates
  - non-power-of-two immediates
  - register-source `X` forms, including constants materialized through a
    register; those need verifier/const-prop state and are intentionally outside
    this static direct-imm census.
- `functions` below follows the stack census convention: executable BPF
  sections. Site examples use `STT_FUNC` symbol attribution where available.

Kernel status:

- The verifier tracks scalar effects for `BPF_MUL`, `BPF_DIV`, and `BPF_MOD`
  without rewriting bytecode: `vendor/linux-framework/kernel/bpf/verifier.c:16392`,
  `:16397`, `:16414`.
- x86 JIT emits hardware `div`/`idiv` for `DIV/MOD` and `imul` for `MUL K`:
  `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1963`,
  `:2032`.
- arm64 JIT emits `MUL`, `UDIV`/`SDIV`, and `MSUB` for these classes:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1459`,
  `:1472`.

Parse errors: `0`.

## Scan Sets

| scan set | total objects | executable objects | functions | eBPF instructions | MUL pow2 imm sites | MOD pow2 imm sites |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| requested roots: `runner/repos` + `corpus/bcf` `.bpf.o` | 60 | 60 | 145 | 22,005 | 0 | 0 |
| supported runtime corpus | 178 | 177 | 775 | 2,210,713 | 0 | 0 |

`corpus/build/tetragon/bpf_alignchecker.o` is counted as a supported runtime
object but has no executable BPF section.

## Per-App Census

`DIV pow2 imm sites` is cited from
`docs/tmp/division_reduction_research_20260430.md`, not re-scanned here.

| app | total objects | functions | MUL pow2 imm sites | MOD pow2 imm sites | DIV pow2 imm sites | total |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| tracee | 3 | 159 | 0 | 0 | 0 | 0 |
| tetragon | 94 | 202 | 0 | 0 | 0 | 0 |
| bpftrace | 9 | 9 | 0 | 0 | 0 | 0 |
| bcc | 57 | 366 | 0 | 0 | 0 | 0 |
| katran | 5 | 6 | 0 | 0 | 0 | 0 |
| cilium | 7 | 27 | 0 | 0 | 0 | 0 |
| otelcol-ebpf-profiler | 3 | 6 | 0 | 0 | 0 | 0 |
| **total** | **178** | **775** | **0** | **0** | **0** | **0** |

## Candidate Histograms

No candidate immediate values were observed.

| scan set | candidate immediates |
| --- | --- |
| requested roots | none |
| supported runtime corpus | none |

Width distribution is therefore also zero:

| scan set | MUL ALU32 | MUL ALU64 | MOD ALU32 | MOD ALU64 |
| --- | ---: | ---: | ---: | ---: |
| requested roots | 0 | 0 | 0 | 0 |
| supported runtime corpus | 0 | 0 | 0 | 0 |

Direct K instructions that were scanned but excluded:

| scan set | family | direct K sites | pow2 candidates | non-pow2 | negative | `0`/`1` |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| requested roots | `MUL K` | 10 | 0 | 10 | 0 | 0 |
| requested roots | `MOD K` | 1 | 0 | 1 | 0 | 0 |
| supported runtime corpus | `MUL K` | 1,107 | 0 | 1,051 | 56 | 0 |
| supported runtime corpus | `MOD K` | 134 | 0 | 134 | 0 | 0 |

Top excluded supported immediates:

| family | imm | sites | reason |
| --- | ---: | ---: | --- |
| `MUL K` | 5 | 377 | non-power-of-two |
| `MUL K` | 60 | 263 | non-power-of-two |
| `MUL K` | 1,000,000,000 | 137 | non-power-of-two |
| `MOD K` | 24 | 123 | non-power-of-two |
| `MUL K` | 10 | 107 | non-power-of-two |
| `MUL K` | 80 | 105 | non-power-of-two |
| `MUL K` | 24 | 33 | non-power-of-two |
| `MUL K` | 30 | 10 | non-power-of-two |
| `MUL K` | 380,141,568 | 8 | non-power-of-two |
| `MUL K` | 461,845,907 | 8 | non-power-of-two |
| `MOD K` | 32,749 | 8 | non-power-of-two |
| `MOD K` | 65,537 | 2 | non-power-of-two |
| `MUL K` | 65,537 | 2 | non-power-of-two |
| `MOD K` | 10,000,000 | 1 | non-power-of-two |
| `MUL K` | 100 | 1 | non-power-of-two |

Representative excluded sites:

| object:function | section PC | insn | reason |
| --- | ---: | --- | --- |
| `corpus/build/tracee/tracee.bpf.o:murmur32` | 24 | `ALU64 MUL K -862048943` | negative immediate |
| `corpus/build/tracee/tracee.bpf.o:murmur32` | 37 | `ALU64 MUL K 5` | non-power-of-two |
| `corpus/build/cilium/bpf_host.bpf.o:snat_v6_nat` | 1543 | `ALU32 MUL K 60` | non-power-of-two |
| `corpus/build/tracee/tracee.bpf.o:tracepoint__sched__sched_process_exec` | 3943 | `ALU64 MUL K 1000000000` | non-power-of-two |
| `corpus/build/tetragon/bpf_generic_fentry.o:generic_fentry_filter_arg` | 8923 | `ALU64 MOD K 24` | non-power-of-two |
| `corpus/build/cilium/bpf_overlay.bpf.o:tail_handle_ipv6` | 20775 | `ALU32 MOD K 32749` | non-power-of-two |
| `corpus/build/katran/balancer.bpf.o:balancer_ingress` | 1282 | `ALU64 MOD K 65537` | non-power-of-two |
| `corpus/build/tracee/tracee.bpf.o:hash_task_id` | 173 | `ALU64 MOD K 10000000` | non-power-of-two |

## Top Objects

No object has candidate sites.

| rank | object | app | MUL pow2 | MOD pow2 | total |
| ---: | --- | --- | ---: | ---: | ---: |
| 1-20 | none | - | 0 | 0 | 0 |

## Top Functions

No function has candidate sites.

| rank | object:function | example PC | MUL pow2 | MOD pow2 | total |
| ---: | --- | ---: | ---: | ---: | ---: |
| 1-10 | none | - | 0 | 0 | 0 |

## LLVM-Already-Reduced Context

This is not proof that each site came from source-level multiply/modulo by a
power of two. It is a bytecode shape census showing that the corpus already has
large numbers of shifts and power-of-two masks, while direct `MUL/MOD` pow2
sites are zero.

Supported runtime corpus:

| lowered-looking shape | ALU32 sites | ALU64 sites | total |
| --- | ---: | ---: | ---: |
| `LSH K` with `0 < shift < width` | 3,843 | 55,800 | 59,643 |
| `AND K` where `K + 1` is power-of-two | 2,365 | 29,031 | 31,396 |
| **total** | **6,208** | **84,831** | **91,039** |

Per app:

| app | LSH ALU32 | LSH ALU64 | AND-mask ALU32 | AND-mask ALU64 | total |
| --- | ---: | ---: | ---: | ---: | ---: |
| tracee | 0 | 6,436 | 0 | 5,407 | 11,843 |
| tetragon | 0 | 47,011 | 0 | 23,251 | 70,262 |
| bpftrace | 0 | 22 | 0 | 0 | 22 |
| bcc | 8 | 568 | 0 | 28 | 604 |
| katran | 0 | 80 | 0 | 38 | 118 |
| cilium | 3,835 | 1,632 | 2,365 | 287 | 8,119 |
| otelcol-ebpf-profiler | 0 | 51 | 0 | 20 | 71 |
| **total** | **3,843** | **55,800** | **2,365** | **29,031** | **91,039** |

Top implied powers:

| shape | implied K | sites |
| --- | ---: | ---: |
| `LSH` | 4,294,967,296 | 25,836 |
| `AND mask` | 256 | 10,606 |
| `LSH` | 256 | 9,924 |
| `LSH` | 65,536 | 7,468 |
| `LSH` | 16,777,216 | 7,435 |
| `AND mask` | 4,096 | 5,173 |
| `AND mask` | 65,536 | 3,939 |
| `AND mask` | 16,384 | 3,715 |
| `LSH` | 4 | 3,280 |
| `AND mask` | 2 | 2,033 |

Representative already-lowered shapes:

| object:function | section PC | insn | implied source shape |
| --- | ---: | --- | --- |
| `corpus/build/tracee/tracee.bpf.o:murmur32` | 46 | `ALU64 AND K 3` | `x % 4`-compatible mask |
| `corpus/build/tracee/tracee.bpf.o:sys_enter_submit` | 1550 | `ALU64 AND K 4095` | `x % 4096`-compatible mask |
| `corpus/build/tetragon/bpf_generic_fentry.o:generic_fentry_setup_event` | 227 | `ALU64 AND K 7` | `x % 8`-compatible mask |
| `corpus/build/tracee/tracee.bpf.o:sys_exit_submit` | 1338 | `ALU64 LSH K 2` | `x * 4`-compatible shift |
| `corpus/build/tracee/tracee.bpf.o:murmur32` | 54 | `ALU64 LSH K 8` | `x * 256`-compatible shift |
| `corpus/build/tracee/tracee.bpf.o:murmur32` | 6 | `ALU64 LSH K 32` | `x * 2^32`-compatible shift |

## Payoff Upper Bound

Static candidate sites are zero, so the runtime upper bound is also zero.

Baseline run counts are from the same context file used by the stack census:

`corpus/results/x86_kvm_p89_kinsn_corpus_20260430_131403_981524/details/result.json`

The result has `workload_seconds = 1.0` and status `error`, so these counters
are only used as context. They do not affect the zero-site conclusion.

| app | baseline BPF runs | candidate sites | upper-bound site executions/s |
| --- | ---: | ---: | ---: |
| tracee | 11,513,662 | 0 | 0 |
| tetragon | 7,260,593 | 0 | 0 |
| bcc | 4,837,729 | 0 | 0 |
| bpftrace | 810,019 | 0 | 0 |
| cilium | 17,710 | 0 | 0 |
| katran | 768 | 0 | 0 |
| otelcol-ebpf-profiler | 260 | 0 | 0 |
| **total** | **24,440,741** | **0** | **0** |

Using the requested latency intuition:

- `MUL pow2 -> LSH`: approximately 2-3 cycles saved per executed site.
- `MOD pow2 -> AND`: approximately 29-99 cycles saved per executed site.

Because the supported corpus has `0` direct candidate sites, the optimistic
upper bound is `0` cycles/s and `0` ns/s on both x86 and arm64.

## Risks

- `K = 0` and `K = 1` are excluded. `log2(0)` is invalid and `1` is a trivial
  no-op case.
- Negative immediates are excluded. The supported corpus has 56 negative
  `MUL K` sites, all outside this candidate.
- `MUL` by positive power-of-two is a bit-vector identity with left shift under
  the relevant ALU width, but a pass must still preserve ALU32 zero-extension
  behavior exactly.
- `MOD pow2 -> AND` is only valid for unsigned modulo. In this kernel fork,
  signed `DIV/MOD` is visible in bytecode through `insn->off == 1`; a future
  pass must reject signed modulo. Signed remainder differs for negative inputs,
  for example `-1 % 8` is not equivalent to `-1 & 7`.
- Static direct-imm bytecode cannot see verifier-known constants in `X` source
  registers. If const-prop or verifier-state side inputs later materialize many
  `MOD X` power-of-two constants, that would be a different census.
- `DIV` magic multiply and non-power-of-two divisor work is intentionally not
  repeated here; use `docs/tmp/division_reduction_research_20260430.md`.
- The already-lowered `LSH`/`AND` counts are contextual only. Many are bit
  packing, truncation, hash, or field extraction patterns, not necessarily
  source-level strength reduction.

## Conclusion

Status: **不做 for the direct-immediate `MUL/MOD` power-of-two pass**.

The direct supported-runtime opportunity is zero: `0` candidate sites, `0`
candidate objects, `0` candidate functions, and `0` runtime upper-bound
executions. The high theoretical payoff for `MOD pow2 -> AND` does not matter
without sites in the supported corpus.

Do not schedule this in the first wave or second wave as a standalone pass.
Revisit only if a future verifier-state/const-prop census shows materialized
register-source power-of-two `MOD X` or `MUL X` sites in hot supported programs.
