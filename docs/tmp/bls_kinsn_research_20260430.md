# BLSI/BLSR/BLSMSK kinsn research

Date: 2026-04-30

## Executive summary

Recommendation: **⏸ 后续 phase**. Do not put BLSI/BLSR/BLSMSK into the immediate Paper A/default kinsn implementation queue.

The exact lowest-set-bit idiom is real, but the current evidence is too narrow:

- Full `.bpf.o` census over `corpus/build`, `corpus/bcf`, and `runner/repos`: `957` object instances, `865` unique object hashes, `0` objdump errors.
- Exact matches: `BLSI = 3`, `BLSR = 3`, `BLSMSK = 0`.
- All six matches are in `corpus/build/scx/scx_lavd_main.bpf.o`.
- `scx` is a removed app in this benchmark plan because struct_ops ReJIT can crash the scheduler, so the supported 8-app corpus has `0` BLSI/BLSR/BLSMSK sites.

Per-site savings are attractive for a true bitmap traversal loop, roughly `2-3` cycles per BLS instruction on x86 BMI1 and `4-6` cycles per `BLSI+BLSR` loop iteration. The issue is not instruction quality; it is corpus coverage and benchmark relevance.

## Stage 1: existing research

`docs/tmp/20260329/bit_ops_kinsn_research_20260329.md` does **not** cover BLSI/BLSR/BLSMSK. Its scope is explicitly:

- `POPCNT/CLZ/CTZ`
- `PDEP/PEXT`
- `SHRX/SHLX`

`docs/tmp/p89_research_audit.md` correctly classifies BLS* as partial historical evidence only:

- `docs/tmp/2026-03-07/additional_jit_optimizations.md` has a narrow `x &= x - 1 -> blsr` note for the `bitcount` microbenchmark, estimating `5-15%` exec impact for that one benchmark and `40-80 LOC` complexity.
- `docs/tmp/2026-03-08/directive-discovery-analysis.md` says the same `bitcount` BLSR-style idiom is too small to drive the roadmap.
- `docs/tmp/2026-03-13/ablation-byte-recompose-callee-bmi.md` reports the BMI/BMI2-only proxy estimate as clipped to `0.0%` of current characterization surplus, with `blsr` included in that proxy family.

So P89 audit's conclusion holds: historical BLSR/micro evidence exists, but there was no current corpus census for BLSI, BLSR, and BLSMSK.

## Stage 2: corpus census

### Scope

Scanned every `.bpf.o` under:

- `corpus/build`
- `corpus/bcf`
- `runner/repos`

Totals:

| metric | count |
| --- | ---: |
| object file instances | 957 |
| unique object SHA256 hashes | 865 |
| objdump errors | 0 |

The matcher parses `llvm-objdump -d` output and tracks simple register expressions inside each disassembly symbol. It matches these exact semantic forms:

- BLSI: `x & -x`, including `tmp = x; tmp = -tmp; dst = x; dst &= tmp` and `tmp = 0; tmp -= x; dst &= tmp`.
- BLSR: `x & (x - 1)`, including `dst = x; dst += -1; dst &= x` and `dst = -1; dst += x; dst &= x`.
- BLSMSK: `x ^ (x - 1)`, including the same `x - 1` variants.

### Exact match count

| target | all object instances | unique object/symbol/pc sites | supported 8 apps |
| --- | ---: | ---: | ---: |
| BLSI | 3 | 3 | 0 |
| BLSR | 3 | 3 | 0 |
| BLSMSK | 0 | 0 | 0 |

All matches are in `scx_lavd_main.bpf.o`; no matches were found in `tracee`, `tetragon`, `bpftrace`, `bcc`, `katran`, `calico`, `cilium`, or `opentelemetry-ebpf-profiler`.

As a sanity check, the scan saw many primitive ingredients, so the zero/near-zero exact result is not caused by an empty ALU corpus:

| primitive | count |
| --- | ---: |
| `sub1` (`+= -1` / `-= 1`) | 3612 |
| register `and` | 10901 |
| register `xor` | 4063 |
| `neg` | 954 |
| backward jumps | 15345 |

### Concrete samples

`pc` below is the BPF instruction index printed by `llvm-objdump`.

| target | object | section / function | pc | sequence |
| --- | --- | --- | ---: | --- |
| BLSR | `corpus/build/scx/scx_lavd_main.bpf.o` | `.text` / `pick_most_loaded_dsq` | 498 | `r9 = r7; r9 += -0x1; r9 &= r7` |
| BLSI | `corpus/build/scx/scx_lavd_main.bpf.o` | `.text` / `pick_most_loaded_dsq` | 617 | `r2 = r7; r2 = -r2; r1 = r7; r1 &= r2` |
| BLSI | `corpus/build/scx/scx_lavd_main.bpf.o` | `.text` / `update_sys_stat` | 19629 | `r2 = r8; r2 = -r2; r1 = r8; r1 &= r2` |
| BLSR | `corpus/build/scx/scx_lavd_main.bpf.o` | `.text` / `update_sys_stat` | 19675 | `r6 = r8; r6 += -0x1; r6 &= r8` |
| BLSR | `corpus/build/scx/scx_lavd_main.bpf.o` | `struct_ops.s/lavd_init` / `lavd_init` | 461 | `r8 = r6; r8 += -0x1; r8 &= r6` |
| BLSI | `corpus/build/scx/scx_lavd_main.bpf.o` | `struct_ops.s/lavd_init` / `lavd_init` | 570 | `r2 = r6; r2 = -r2; r1 = r6; r1 &= r2` |

These are the expected bitmap traversal shape. The BLSI sites feed a de Bruijn multiply/index sequence, and the nearby BLSR sites clear the processed bit before looping. This is good qualitative evidence that BLSI/BLSR are the right ISA operations for this idiom, but it currently comes only from the removed `scx` app.

## Stage 3: ROI estimate

### x86 BMI1

Expected native lowering:

- BLSI: `blsi dst, src`
- BLSR: `blsr dst, src`
- BLSMSK: `blsmsk dst, src`

Approximate savings:

- BLSI replaces `mov + neg + and`, saving about `2-3` cycles/site on a dependent path.
- BLSR replaces `mov + sub/add -1 + and`, saving about `2-3` cycles/site.
- BLSMSK would replace `mov + sub/add -1 + xor`, also roughly `2-3` cycles/site, but there are no sites.

For a true `while (mask) { low = mask & -mask; mask &= mask - 1; ... }` loop, BLSI+BLSR can save roughly `4-6` cycles per set-bit iteration. That can matter if the bitmap is hot and has multiple set bits.

Current corpus-weighted ROI:

- Supported 8 apps: `0`, because there are no exact sites.
- Full corpus including removed apps: positive only for `scx_lavd`, which is not a valid current benchmark target.

### ARM64 fallback

ARM64 has no direct single-instruction equivalents:

- BLSI fallback: `neg tmp, src; and dst, src, tmp`
- BLSR fallback: `sub tmp, src, #1; and dst, src, tmp`
- BLSMSK fallback: `sub tmp, src, #1; eor dst, src, tmp`

These are essentially the original scalar sequences. A cross-arch kinsn pass would be x86-only useful and ARM64-neutral at best. That is acceptable for a future x86-targeted phase, but weak for the current default kinsn queue.

## Stage 4: implementation complexity

A minimal implementation would require three new kinsns:

- `bpf_blsi`
- `bpf_blsr`
- `bpf_blsmsk`

Pattern matching is simpler than extract/rotate-style passes:

- BLSI: two equivalent register values, one negated, then `and`.
- BLSR: one original register value and one `x - 1` value, then `and`.
- BLSMSK: one original register value and one `x - 1` value, then `xor`.

Fixed plumbing is still non-trivial:

- kfunc/BTF discovery and registry entries
- daemon pass integration
- x86 emitter support gated on BMI1
- ARM64 fallback emitter support
- proof-lowering tests and pass tests

BLSI and BLSR are the only pair with real qualitative evidence. BLSMSK has neither corpus sites nor historical benchmark evidence.

## Stage 5: recommendation

Overall: **⏸ 后续 phase**.

Per instruction:

| instruction | recommendation | reason |
| --- | --- | --- |
| BLSI | ⏸ 后续 phase | Good fit for bitmap traversal, but current supported corpus has `0` sites; all observed sites are in removed `scx`. |
| BLSR | ⏸ 后续 phase | Strongest of the three due historical `bitcount` micro evidence and `scx_lavd` loop sites, but still no supported-app corpus coverage. |
| BLSMSK | ❌ 不做 for now | `0` sites in the full scan and no historical evidence. Do not include just to complete the BMI1 family. |

Decision threshold for revisiting:

- A supported benchmark app starts emitting exact bitmap traversal idioms, or
- a targeted bitmap-heavy benchmark is added to Paper B / future work, with per-site profile data showing hot set-bit iteration, or
- BLSI/BLSR can be implemented opportunistically together with another BMI1 pass without adding independent benchmark or plumbing cost.

Until then, BLSI/BLSR/BLSMSK should stay out of the default Paper A pipeline.
