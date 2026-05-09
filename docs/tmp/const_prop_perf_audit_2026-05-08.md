# const_prop perf audit for katran balancer_ingress

Date: 2026-05-08 local / 2026-05-09 UTC.

## Scope

Primary inputs:

- `corpus/results/x86_kvm_corpus_20260509_022133_477580/details/apps/katran.json`
- `corpus/results/x86_kvm_corpus_20260509_033417_280052/details/apps/katran.json`
- Additional matching ratio source found in this workspace: `corpus/results/x86_kvm_corpus_20260509_031932_134386/details/apps/katran.json`
- Map-inline-only comparison: `corpus/results/x86_kvm_corpus_20260509_031956_984494/details/apps/katran.json`
- New allowed run: `corpus/results/x86_kvm_corpus_20260509_035218_490293/details/apps/katran.json`

The requested `0.7458` const_prop ratio is present in
`x86_kvm_corpus_20260509_031932_134386`, not in the two explicitly named
source directories. The explicitly named `022133` directory has ratio
`0.9454`; `033417` has ratio `0.9768`.

## Data retention limitation

The current `bpfopt_summary` schema does not retain per-applied-site PC, dst
register, original ALU opcode, replacement instruction, or hot/cold path
classification. It stores only aggregate pass counters, skip reason counts,
diagnostics strings, and before/after instruction counts. See
`bpfopt/crates/bpfopt/src/main.rs` `PassReport`: `sites_applied`,
`sites_matched`, `sites_skipped`, `skip_reasons`, `diagnostics`,
`insn_count_before`, `insn_count_after`, `insn_delta`.

Consequences:

- Exact PC list for the 70 applied sites: not recoverable from retained JSON.
- Exact dst register distribution: not recoverable.
- Exact original fold kind distribution, such as MOV-X versus ADD/AND/LSH
  result: not recoverable.
- Hot path percentage using PC < 200: not recoverable.

`KEEP_WORKDIRS=1` did not produce success workdir artifacts. The daemon only
tars workdirs when result status is non-ok or a pass fails; successful workdirs
are removed by `WorkDir::drop`.

## 70 applied sites: aggregate classification

Strictly recoverable from retained summaries:

| Run | Passes | map_inline applied | const_prop matched | const_prop applied | const_prop skipped | const_prop insns | const_prop diagnostic |
|---|---:|---:|---:|---:|---:|---:|---|
| `022133` | noop,map_inline,const_prop | 11 | 129 | 70 | 59 | 2542 -> 2599 (+57) | `const_prop_alu_materialized=70` |
| `031932` | noop,map_inline,const_prop | 11 | 129 | 70 | 59 | 2542 -> 2599 (+57) | `const_prop_alu_materialized=70` |
| `033417` | noop,map_inline,const_prop | 11 | 129 | 70 | 59 | 2542 -> 2599 (+57) | `const_prop_alu_materialized=70` |
| `035218` | noop,map_inline,const_prop,dce | 13 | 127 | 70 | 57 | 2542 -> 2599 (+57) | `const_prop_alu_materialized=70` |

Inferred replacement width:

| Replacement class | Count | Basis |
|---|---:|---|
| Single-instruction immediate materialization (`MOV32 K` or `MOV64 K`) | 13 | 70 replacements with total `insn_delta=+57`; these did not grow |
| Double-instruction `LD_IMM64` materialization | 57 | Each grew original one-instruction ALU/MOV into two BPF insns |
| Total ALU materializations | 70 | `const_prop_alu_materialized=70` |

This means const_prop alone is not BPF bytecode slimming here. It expands the
pass input from 2542 to 2599 instructions. Its direct value must come either
from x86 JIT immediate encoding, from enabling later passes such as dce, or from
noise.

## Verifier-state source

Applied replacements are gated by `InsnDeltaState`, not by EdgeFullState alone.
The code populates `insn_delta_scalar_post_states` only for
`VerifierInsnKind::InsnDeltaState`, and `fold_alu_instruction` accepts a
replacement only if `instruction_post_state_proves_scalar_exact_in_context`
matches the destination post-state. Therefore the 70 applied replacements had
matching InsnDelta post-state evidence. Edge/full states may still contribute
pre-instruction facts, but an EdgeFullState-only candidate cannot pass the final
post-state guard.

## Bytecode and JIT size

| Case | Run | Pass summary | Kernel `bytes_xlated` | Kernel `bytes_jited` |
|---|---|---:|---:|---:|
| baseline | `031956`/`022133`/`033417` | original | 23840 | 13629 |
| map_inline only | `031956` | map_inline `2542 -> 2542` | 22008 | 12614 |
| map_inline+const_prop | `022133`/`031932`/`033417` | const_prop `2542 -> 2599` | 22464 | 12993 |
| map_inline+const_prop+dce | `035218` | const_prop `2542 -> 2599`, dce `2599 -> 2375` | 18960 | 11025 |

Relative to map_inline only, const_prop alone increased the final kernel sizes
in the comparable 11-applied map_inline runs:

- `bytes_xlated`: 22008 -> 22464 (+456)
- `bytes_jited`: 12614 -> 12993 (+379)

With dce enabled after const_prop, the pass-level net effect was:

- const_prop: +57 BPF insns
- dce: -224 BPF insns
- net from const_prop input: 2542 -> 2375 (-167 BPF insns)

The dce run was not perfectly apples-to-apples with the 11-applied isolated
runs: the current worktree/config inlined 13 map sites in `035218`, including
two additional `server_id_map` sites. I did not revert or edit those existing
workspace changes.

## Raw counter ratios

Ratio is `(post run_time_ns_delta / post run_cnt_delta) /
(baseline run_time_ns_delta / baseline run_cnt_delta)`.

| Run | Passes | baseline ns/run | post ns/run | ratio | Size note |
|---|---|---:|---:|---:|---|
| `031956` | noop,map_inline | 307.212 | 327.807 | 1.0670 | 13629 -> 12614 JIT bytes |
| `031932` | noop,map_inline,const_prop | 250.112 | 186.534 | 0.7458 | 13629 -> 12993 JIT bytes |
| `022133` | noop,map_inline,const_prop | 156.794 | 148.239 | 0.9454 | 13629 -> 12993 JIT bytes |
| `033417` | noop,map_inline,const_prop | 151.253 | 147.741 | 0.9768 | 13629 -> 12993 JIT bytes |
| `035218` | noop,map_inline,const_prop,dce | 146.962 | 145.172 | 0.9878 | 13629 -> 11025 JIT bytes |

The VM timing spread is large. The dce run shows a large deterministic code-size
drop but not a clear single-run perf win; its SAMPLES=1 ratio is close to 1.0.

## Conclusion

const_prop alone is not demonstrably useful as a standalone performance pass in
this katran slice. It applies 70 ALU materializations, but 57 of them expand to
`LD_IMM64`, and the final JIT image is larger than map_inline-only in the
11-applied comparison. The observed const_prop-only ratios range from a large
win to near-neutral, which is consistent with VM noise rather than a stable
direct JIT benefit.

const_prop is clearly useful as a dce enabler: dce removes 224 dead-def
instructions after const_prop and produces the smallest final BPF/JIT image in
this audit. The performance effect of that shrink was not proven by the single
new SAMPLES=1 run, but the bytecode mechanism is clear.

## Recommendations

1. Treat const_prop and dce as a coupled optimization for paper claims that rely
   on dead-code exposure. Reporting const_prop alone overstates what the pass
   can do without its consumer.
2. Do not add a stricter high-value filter based only on the retained
   `bpfopt_summary`; the data needed to tell hot/high-value sites from cold
   sites is not present.
3. For a future audit, preserve a success workdir or emit an external analysis
   sidecar outside `result.json` with per-site PC, dst reg, original opcode,
   replacement opcode, replacement width, and whether a later dce removed the
   producer chain. That is the minimum data needed to decide whether the 57
   `LD_IMM64` expansions should be filtered.
4. Re-run the dce comparison from a clean, fixed map_inline configuration before
   using the `035218` perf ratio as evidence; this run has 13 map_inline sites,
   while the isolated const_prop runs have 11.
