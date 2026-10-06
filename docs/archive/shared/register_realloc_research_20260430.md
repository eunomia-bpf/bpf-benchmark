# BPF register reallocation research

Date: 2026-04-30
HEAD: `e2bb1a9295a654dc083cf28e65e4e0dac58a0bc0`

## Summary

Recommendation: **`📝 调研完成（待实现）`**.

This is worth implementing as a pure bytecode pass, separate from REJIT native spill-to-register. The corpus signal is strong: in the supported runtime corpus, a static scan found **62,406** caller-saved stack spill/fill pairs involving `r1..r5`; **59,297** pairs cross at least one helper/kfunc call, i.e. **95.0%** of matched pairs are the exact class that callee-saved `r6..r9` can avoid.

The caveat is implementation complexity. Existing `bpfopt` has CFG and per-instruction liveness, but no live intervals, interference graph, reaching-def analysis, or generic register rename framework. A first implementation should be conservative: handle one-slot/one-live-range candidates where a target `r6..r9` is provably dead for the whole interval, then let `bpfverify` re-run verifier proof on the rewritten bytecode.

## Stage 1: Existing analysis

Existing infrastructure:

- `bpfopt/crates/bpfopt/src/analysis/liveness.rs` implements a fixed-point backward `LivenessAnalysis` and exposes `LivenessResult { live_out }`.
- `insn_use_def()` treats calls as using `r1..r5` and defining/clobbering `r0..r5`, while preserving `r6..r9`.
- `bpfopt/crates/bpfopt/src/analysis/cfg.rs` builds basic blocks and discovers BPF-to-BPF subprogram entries, including pseudo calls.
- `bpfopt/crates/bpfopt/src/analysis/branch_target.rs` marks branch and pseudo-call targets.
- Several passes already consume liveness for local safety checks: `wide_mem`, `bulk_memory`, `rotate`, `ccmp`, `bounds_check_merge`, and dead-definition cleanup in `passes/utils.rs`.

Missing infrastructure for this pass:

- No generic `RegisterAlias`, `DefUse`, reaching-def, live interval, interference graph, or graph-coloring allocator exists.
- `LivenessResult` only exposes `live_out`; a register reallocator will also want `live_in`, per-subprogram boundaries, and lifetime intervals.
- Existing alias tracking in `map_inline` and `prefetch` is pass-local and value-specific, not reusable as a general register allocator.

Adjacent research:

- `docs/tmp/20260329/rejit_register_mapping_research_20260329.md` is about native REJIT `reg_map` / spill-to-register. It does not provide corpus liveness data for BPF bytecode register reallocation.
- `docs/tmp/p89_research_audit.md` correctly marked this row as missing dedicated research before this document.

## Stage 2: Corpus census

Method:

- Disassembled objects with `llvm-objdump -d`.
- Matched 64-bit caller-saved spills and fills:

```text
*(u64 *)(r10 - N) = r1..r5
r1..r5 = *(u64 *)(r10 - N)
```

- Paired a fill with the latest still-valid caller-saved spill to the same stack slot, invalidating on overlapping stack stores.
- Counted a pair as `cross_helper` when at least one non-pseudo `call` appeared between the spill and fill.
- Counted BPF-to-BPF pseudo calls separately. They also follow the caller-saved convention, but they need subprogram-aware validation.
- This is a static, path-insensitive census. It is good for ROI and shape discovery; implementation must use CFG/reaching-def/liveness, not this linear matcher.

### Scan sets

| scan set | objects | spill stores | fill loads | matched pairs | cross helper pairs | cross helper share |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| strict `.bpf.o`, `corpus/build` + `corpus/bcf` + `runner/repos` | 957 | 62,065 | 127,275 | 55,224 | 51,780 | 93.8% |
| requested roots, `.bpf.o` only: `corpus/bcf` + `runner/repos` | 60 | 669 | 639 | 482 | 423 | 87.8% |
| supported runtime corpus, eBPF `.o`/`.bpf.o` under the 8 supported apps | 186 | 56,062 | 154,020 | 62,406 | 59,297 | 95.0% |

The supported runtime scan includes Tetragon `.o` BPF objects, so it is the best signal for current app ROI. The strict `.bpf.o` scan is useful for consistency with earlier P89 object-level censuses.

### Supported app distribution

| app | objects | matched pairs | cross helper pairs | same-reg pairs |
| --- | ---: | ---: | ---: | ---: |
| `tetragon` | 94 | 41,992 | 40,065 | 29,742 |
| `tracee` | 3 | 15,231 | 14,303 | 9,587 |
| `cilium` | 7 | 3,164 | 2,976 | 1,788 |
| `calico` | 8 | 1,711 | 1,662 | 673 |
| `bcc` | 57 | 199 | 198 | 65 |
| `katran` | 5 | 60 | 45 | 27 |
| `otelcol-ebpf-profiler` | 3 | 47 | 46 | 25 |
| `bpftrace` | 9 | 2 | 2 | 0 |

Tetragon and Tracee dominate the static opportunity: together they account for **54,368** supported-app cross-helper pairs, or **91.7%** of the supported-app total.

### Requested roots distribution

| app/repo | matched pairs | cross helper pairs |
| --- | ---: | ---: |
| `xdp-tools` | 166 | 162 |
| `bcc` | 168 | 134 |
| `collected` | 76 | 65 |
| `katran` | 56 | 46 |
| `libbpf-bootstrap` | 16 | 16 |

Top requested-root programs:

| program | pairs | cross helper |
| --- | ---: | ---: |
| `runner/repos/xdp-tools/xdp-forward/xdp_flowtable.bpf.o:xdp:xdp_fwd_flow_full` | 82 | 80 |
| `runner/repos/xdp-tools/xdp-forward/xdp_flowtable.bpf.o:xdp:xdp_fwd_flow_direct` | 82 | 80 |
| `corpus/bcf/collected/xdp_synproxy_kern.bpf.o:xdp:syncookie_xdp` | 56 | 46 |
| `runner/repos/katran/_build/deps/bpfprog/bpf/balancer.bpf.o:xdp:balancer_ingress` | 51 | 43 |
| `corpus/bcf/bcc/clang-20_-O1_ksnoop.bpf.o:.text:ksnoop` | 38 | 29 |

### Callee-saved pressure

For each supported-runtime cross-helper pair, the scanner counted how many of `r6..r9` were never mentioned in the linear spill-to-fill window. This is not a substitute for liveness, but it estimates how often a simple target choice could work without renaming existing callee-saved ranges.

| apparently free `r6..r9` regs | cross helper pairs |
| ---: | ---: |
| 0 | 38,432 |
| 1 | 15,203 |
| 2 | 2,675 |
| 3 | 1,606 |
| 4 | 1,381 |

So a conservative first pass that requires at least one unused callee-saved register in the whole window still has up to **20,865** supported-runtime cross-helper candidates. The remaining **38,432** candidates need a real interference graph or interval splitting if we want to cover them safely.

## Stage 3: Feasibility and risks

The semantic argument is clean when the proof obligations are met:

1. Identify a single value live range currently materialized as caller-saved register -> stack slot -> caller-saved register.
2. Prove one `r6..r9` target is not live anywhere in that interval and is not used as an ABI register at the relevant calls.
3. Rename all uses/defs in that live range to the target callee-saved register.
4. Delete the now-dead spill/fill, or replace a fill with a register move if the value must be placed back into `r1..r5` for a helper argument.
5. Re-run verifier proof through `bpfverify`.

Key risks:

- **Existing `r6..r9` use**: most hot candidates mention at least one callee-saved register in the window, and 64.8% of supported cross-helper pairs mention all four. A naive "pick an unused R6-R9" pass will leave much of the opportunity untouched.
- **Reaching definitions**: liveness alone does not prove that a fill is reading exactly one spill. Stack slots can be reused, merged across branches, or partially overwritten. The pass needs reaching-def/stack-slot value analysis.
- **Subprograms**: BPF-to-BPF pseudo calls and subprogram entries require per-subprogram allocation boundaries. The convention still preserves `r6..r9`, but call arguments and return values in `r0..r5` cannot be freely renamed across call boundaries.
- **ABI-sensitive uses**: helper/kfunc calls consume arguments in `r1..r5`. If the renamed value becomes a call argument, the pass may need to insert `rN = r6..r9` before the call, which still saves stack traffic but may not reduce instruction count.
- **Verifier state**: changing register numbers changes verifier register state traces. The transform is still pure bytecode, but verifier replay is mandatory; no unchecked proof shortcut should be added.
- **Metadata**: if the pass deletes instructions rather than NOPing them, BTF func_info/line_info and address maps must stay consistent with existing bpfverify replay behavior.

Relative complexity: this is materially harder than const-prop or a local kinsn peephole. It is closer to a small register allocator plus stack-slot reaching-def analysis.

## Stage 4: ROI estimate

Per pair saving:

- Removing a stack spill and fill saves roughly **2 cycles** in the best steady-state case, plus stack-memory pressure and load/store queue pressure.
- If a fill must become `r1..r5 = r6..r9` for a helper argument, instruction count may stay flat, but memory traffic still becomes a register move.

Break-even at 3 GHz:

| one-time pass/ReJIT overhead | pair executions needed at 2 cycles/pair |
| --- | ---: |
| 100 us | 150,000 |
| 1 ms | 1,500,000 |
| 10 ms | 15,000,000 |

Using `corpus/results/x86_kvm_p89_kinsn_corpus_20260430_131403_981524/details/result.json` (`workload_seconds = 1.0`), measured baseline BPF run counts by runner were:

| runner | baseline runs |
| --- | ---: |
| `tracee` | 11,513,652 |
| `tetragon` | 7,260,591 |
| `bcc` | 4,837,729 |
| `bpftrace` | 810,019 |
| `cilium` | 17,710 |
| `katran` | 768 |
| `otelcol-ebpf-profiler` | 260 |

The measured apps with static candidates account for **24.44M** BPF program runs in this one-second result. If only one candidate pair executes per run, the theoretical saving is about **48.9M cycles/s**, or **1.6% of one 3 GHz core**. Tracee plus Tetragon alone would be **37.5M cycles/s** under the same one-pair-per-run assumption.

That is enough to clear the break-even bar for long-running workloads. The missing piece is per-site dynamic frequency: static pair count must not be multiplied by app run count blindly because many candidates are in mutually exclusive blocks. A first implementation can still be justified because the break-even threshold is low and the static signal is concentrated in hot, helper-heavy apps.

## Stage 5: Recommendation

Status: **`📝 调研完成（待实现）`**.

Suggested implementation path:

1. Add a stack-slot reaching-def analysis for `r10 - N` slots and expose `live_in` alongside `live_out`.
2. Build per-subprogram live intervals for BPF registers and a small interference check for target `r6..r9`.
3. Implement a conservative first pass for one-spill/one-or-more-fill intervals crossing helper calls, requiring one provably non-conflicting callee-saved target.
4. Delete spill/fill only when all uses are renamed; otherwise replace stack fill with a register move only when that is still profitable and verifier-safe.
5. Keep it separate from REJIT spill-to-register. This pass rewrites BPF bytecode; REJIT spill-to-register maps stack slots to native registers and has different architecture constraints.

Do not put this directly into the default pipeline until it passes supported-app corpus verification and produces per-program performance data. The research result supports implementation, not an unconditional default-policy decision.
