# Directive Gap Analysis

Date: 2026-03-11

Reviewed inputs:

- `docs/kernel-jit-optimization-plan.md`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `scanner/src/`
- `docs/tmp/corpus-runnability-report.md`
- `docs/tmp/corpus-batch-recompile-results.md`
- `docs/tmp/corpus-recompile-regression-analysis.md`
- `docs/tmp/selective-policy-results.md`
- `docs/tmp/cmov-kernel-benefit-experiment.md`
- `docs/tmp/kernel-fixed-baselines-per-directive.md`
- `docs/tmp/kernel-fixed-baselines-test-results.md`
- `docs/tmp/rigorous-benchmark-results.md`
- `micro/results/performance_deep_analysis.md`
- `docs/paper-comparison.md`
- `docs/tmp/k2-merlin-epso-comparison.md`
- `docs/tmp/directive-discovery-analysis.md`
- `docs/tmp/bpf-jit-advisor-v7.md`

## Executive Summary

1. We are over-focused on CMOV if the claim is "CMOV is the biggest practical recovery path." Corpus site counts do not support that, and current measured CMOV impact is mostly negative. We are not over-focused on CMOV if the claim is "CMOV is the cleanest current policy-sensitivity example." That part is still true.
2. The current four directives are enough for a v1 substrate paper claim, but not yet enough for a strong OSDI claim by themselves. Three of the four look like kernel-owned peepholes, and one of them (`lea_fusion`) has zero runnable corpus sites in the current data.
3. The current x86 JIT still has several obvious local inefficiencies that do not need new directives at all: fixed NOP waste in the prologue, zero-displacement encoding waste, conservative register save/restore around `div/mod` and variable shifts, and over-verbose endian/load sequences.
4. The repo does not currently contain a defensible whole-suite "stock kernel vs BpfReJIT kernel" recovery number on the 31 pure-JIT benchmarks. What we have today is strong local wins (`rotate`), a strong local opportunity (`wide_load`), a weak local signal (`lea`), and a strong policy falsification (`cmov` can hurt badly).
5. Theoretical backend-only headroom is still large. The characterization attributes about 89.1% of measured native-code surplus to backend-side effects (`50.7%` byte-recompose + `19.9%` branch/control-flow + `18.5%` prologue/epilogue). But the current implemented directives have not yet converted that headroom into aggregate runtime recovery.
6. The next sprint should split into two tracks:
   - paper-worthy directives: `bitfield_extract`, `packet_ctx_wide_load`, and one broader policy-sensitive control-flow directive (`branch_reorder`, or at minimum broader hybrid `cmov_select` recognition);
   - kernel-local cleanup patches: prologue NOP waste, zero-displacement memory encodings, endian-load fusion, and liveness-aware save/restore cleanup.

## 1. Are We Over-Focused On CMOV?

### 1.1 What the corpus actually contains

The current implementation surface is only four families. The scanner and v5 pattern library expose:

- `cmov`
- `wide_load`
- `rotate`
- `addr_calc` / `lea`

That is visible in `scanner/src/scanner.cpp:614-647` and `scanner/src/pattern_v5.cpp:407-417, 775-801`.

However, "4 directives" is already more than "4 hardcoded shapes." The v5 built-in library expands to:

- `320` concrete `cmov` descriptors
- `4` `wide_load` descriptors
- `11` `rotate` descriptors
- `1` `lea` descriptor

That comes from `scanner/src/pattern_v5.cpp:423-548`, `551-734`, and `737-773`.

The site census is the important part:

| Slice | CMOV | WIDE | ROTATE | LEA | Reading |
| --- | ---: | ---: | ---: | ---: | --- |
| Raw candidate scan across 514 objects | 1237 | 1870 | 1840 | 0 | CMOV is not dominant even before runnability filtering. |
| Runnable/loadable corpus (`docs/tmp/corpus-runnability-report.md`) | 840 | 389 | 1840 | 0 | By site count, ROTATE dominates; CMOV is second. |
| Measured paired packet subset (`docs/tmp/corpus-batch-recompile-results.md`) | 242 | 342 | 1840 | 0 | By site count, CMOV is the smallest of the three nonzero families. |

Source lines:

- `docs/tmp/cross-domain-directive-census.md:8-16`
- `docs/tmp/corpus-runnability-report.md:40-47`
- `docs/tmp/corpus-batch-recompile-results.md:17-21`

The right nuance is "site count" versus "program breadth."

- In the runnable corpus, CMOV is `27.4%` of detected sites, WIDE is `12.7%`, and ROTATE is `60.0%`.
- In the measured subset, CMOV is only `10.0%` of sites, WIDE is `14.1%`, and ROTATE is `75.9%`.
- But in the measured subset, CMOV appears in `73` programs, WIDE in `39`, and ROTATE in only `4` (`docs/tmp/corpus-batch-recompile-results.md:37-44`).

So CMOV is broad but sparse. ROTATE is dense but concentrated. LEA is currently absent in real runnable programs.

There is one more important distortion: real-program ROTATE counts are dominated by two very large selftest objects. The broader real-program census reports `1810` rotate sites but only `2` corpus programs with any rotate at all, versus `183` CMOV sites spread across `55` programs (`docs/tmp/real-program-directive-census.md:42-56`). That makes CMOV more representative across programs, but not more important by raw site volume.

### 1.2 What CMOV currently does to performance

The characterization and recompile results are consistent on one point: CMOV is the family with the clearest policy sensitivity, but not the family with the clearest positive aggregate payoff.

#### Micro and characterization evidence

- The plan document explicitly records mixed CMOV behavior: `switch_dispatch +26%`, `binary_search +12%`, `bounds_ladder -18%`, `large_mixed -24%` (`docs/kernel-jit-optimization-plan.md:120-129`).
- The current kernel recompile path does not actually hit the headline unpredictable-branch cases. `switch_dispatch`, `binary_search`, and `bounds_ladder` all still have `cmov_sites = 0` under the current v5 path (`docs/tmp/cmov-kernel-benefit-experiment.md:52-65, 114-139`).
- The one rigorous isolated kernel CMOV benchmark we do have, `log2_fold`, is a clean loss: `stock / recompile-v5-cmov = 0.655x`, code size `648 -> 682`, `q = 0.0033` (`docs/tmp/rigorous-benchmark-results.md:28-42`).
- The fixed-kernel baseline agrees. `CMOV-only` changes only `log2_fold`, and hurts it by `+19.7%`; `fixed-all` also regresses `log2_fold` (`docs/tmp/kernel-fixed-baselines-per-directive.md:25-33, 81-87`; `docs/tmp/kernel-fixed-baselines-test-results.md:40-45`).

#### Corpus evidence

- The family-level batch result for CMOV is negative: `Exec Ratio = 0.821x`, `54` regressions out of `72` measured pairs with CMOV applied (`docs/tmp/corpus-batch-recompile-results.md:37-44`).
- After removing only sub-resolution noise, CMOV-applied rows are still `8` wins / `34` losses with geomean `0.845x`; CMOV-only rows are `2` wins / `14` losses with geomean `0.797x` (`docs/tmp/corpus-recompile-regression-analysis.md:98-109`).
- The selective skip experiment shows why CMOV still matters to the paper story. Skipping CMOV globally does not help the raw full corpus, but it does help the signal-bearing shared non-sub subset: `0.828x -> 0.870x`, and especially Calico CMOV-only rows: `0.811x -> 0.886x` (`docs/tmp/selective-policy-results.md:13-29, 65-72`).

### 1.3 CMOV versus the other three families

| Family | Current corpus prevalence | Strongest current runtime evidence | Current role |
| --- | --- | --- | --- |
| `cmov_select` | Broad across programs, not dominant by sites | Mostly negative today; strong evidence that fixed heuristics fail | Best current policy-sensitivity example |
| `wide_load` | Moderate site count; clearly real | Largest characterized backend bucket (`50.7%` surplus, `2.24x` isolated penalty), but rigorous kernel recovery is not yet stable | Best quantitative coverage story |
| `rotate_fusion` | Huge site count but concentrated in a few programs | Strongest clean positive kernel wins: `rotate64_hash 1.193x`, `packet_rss_hash 1.235x` | Best "we can actually win" story |
| `lea_fusion` | No runnable corpus sites today | Small positive isolated result, but unstable and weak | Useful substrate demo, weak paper pillar |

Sources:

- `docs/kernel-jit-optimization-plan.md:120-129`
- `docs/tmp/rigorous-benchmark-results.md:44-106`
- `docs/tmp/kernel-fixed-baselines-per-directive.md:27-33, 69-87`
- `docs/tmp/corpus-batch-recompile-results.md:37-44`

### 1.4 Verdict

CMOV should not be the poster child for "this is where most of the performance gap is." That claim is wrong. `wide_load` owns the biggest characterized bucket, and `rotate` has the cleanest positive runtime wins.

CMOV should remain the poster child for "why backend policy cannot be hardcoded in the kernel." That claim is right. The repo already has the decisive falsification result: unconditional CMOV hurts a predictable branch workload, and skipping CMOV helps the cleaner Calico subset.

So the right paper framing is:

- lead the quantitative recovery story with `wide_load` and `rotate_fusion`;
- use `cmov_select` to demonstrate policy sensitivity and the failure of fixed heuristics;
- move the long-term novelty flagship from narrow CMOV to `branch_reorder`, because that is the broader policy-sensitive control-flow story.

## 2. Are 4 Directives Enough For A Systems Paper?

### 2.1 Raw count comparison with K2, Merlin, and EPSO

The apples-to-apples comparison is not "4 versus 795." The units are different.

| System | What it exposes | Count that matters | Interpretation |
| --- | --- | --- | --- |
| BpfReJIT today | canonical backend directive families | `4` families, `336` built-in pattern descriptors | Small canonical surface, larger userspace pattern vocabulary |
| K2 | synthesis-based bytecode optimizer | `6` proposal-generation rewrite rules in the synthesis engine | Not a small fixed directive set; it is a search-based compiler |
| Merlin | named optimizers in a multi-layer optimizer | `6` optimizers | Whole-program optimizer stack, not backend directives |
| EPSO | rewrite-rule database | `795` rules | Large learned bytecode rewrite corpus |

Evidence in-tree:

- BpfReJIT family surface: `scanner/src/scanner.cpp:614-647`, `scanner/src/pattern_v5.cpp:423-801`
- K2 / Merlin / EPSO positioning and results: `docs/paper-comparison.md:566-580`
- EPSO rule count: `docs/paper-comparison.md:570`

Primary-source counts checked outside the repo:

- Merlin names six optimizer components.
- K2 is best described as a synthesis compiler seeded by a small rewrite-rule proposal set, not as "a six-pass backend."

So "4 directives" is not embarrassingly small if the unit is canonical backend mechanisms. The real question is whether those four families span enough of the backend gap and enough novelty classes.

It is also important that the kernel interface itself is already generic. `vendor/linux-framework/include/linux/bpf_jit_directives.h:71-125` defines a general `bpf_jit_rule`, `bpf_jit_policy`, and canonical-parameter payload; it does not hard-code "only four optimizations forever." The current four-family limit comes from the implemented pattern library and emitters, not from the transport format. The plan document makes the same scalability claim explicitly: each added directive should be on the order of `~50-100` LOC validator plus `~50-100` LOC emitter per architecture (`docs/kernel-jit-optimization-plan.md:211-212`).

### 2.2 Coverage of the identified backend gap

The characterization gives three big native-code buckets:

- byte-recompose: `50.7%`
- branch/control-flow: `19.9%`
- prologue/epilogue: `18.5%`

Together: about `89.1%` of measured native-code surplus (`docs/tmp/k2-merlin-epso-comparison.md:111-127`).

Against that decomposition, the current four directives look like this:

| Current family | Which gap bucket it attacks | How much of that bucket it really reaches today |
| --- | --- | --- |
| `wide_load` | byte-recompose (`50.7%`) | Real and important, but still limited in shape coverage and memory-class reach |
| `cmov_select` | part of branch/control-flow (`19.9%`) | Narrow local select subset only; misses `switch_dispatch`, `binary_search`, `bounds_ladder` entirely |
| `rotate_fusion` | small residual bucket | Useful, but not one of the top three measured macro-buckets |
| `lea_fusion` | small residual bucket | Very small and currently unsupported by runnable corpus evidence |

Two immediate consequences follow.

1. The current four directives do not touch the entire `18.5%` prologue/epilogue bucket at all.
2. The current CMOV implementation only touches a narrow slice of the branch bucket, and currently misses the best microbenchmarks for making the policy-sensitive case.

That means the current four families cover:

- one major bucket well in principle (`wide_load`);
- one major bucket only partially (`cmov_select`);
- two smaller x86 combines (`rotate`, `lea`);
- none of the large prologue bucket.

This is enough for a defensible v1 mechanism story. It is not enough for "we already cover most of the backend gap in practice."

### 2.3 What fraction of the gap do the four directives close today?

The honest answer is: we do not yet have a good whole-suite runtime number.

What the repo does have:

- pure-JIT LLVM vs kernel characterization: `L/K = 0.849x` (`docs/kernel-jit-optimization-plan.md:120`; `micro/results/performance_deep_analysis.md:11-16`)
- strong local kernel recompile wins for rotate (`docs/tmp/rigorous-benchmark-results.md:44-58, 92-106`)
- one modest isolated LEA win (`docs/tmp/rigorous-benchmark-results.md:76-90`)
- a non-significant isolated WIDE recovery on the current rigorous kernel run (`docs/tmp/rigorous-benchmark-results.md:60-74`)
- a strongly negative isolated CMOV result (`docs/tmp/rigorous-benchmark-results.md:28-42`)
- negative current real-program aggregate recompile results: `0.826x` raw, `0.847x` after removing only sub-resolution noise (`docs/tmp/corpus-batch-recompile-results.md:15-16`; `docs/tmp/corpus-recompile-regression-analysis.md:23-35`)

So today we can say:

- the directives close large local gaps on some benchmarks;
- the current implementation does not yet demonstrate positive aggregate runtime recovery on a representative corpus slice;
- therefore there is no defensible "% of the 0.849x gap closed" headline yet.

If a reviewer forces a structural answer anyway, the best one is:

- current families directly target at least the `50.7%` byte-recompose bucket and part of the `19.9%` branch bucket;
- in practice, current realized recovery is much smaller because the branch coverage is too narrow, LEA has no corpus traction, and prologue remains untouched.

### 2.4 Are four enough in principle?

Yes, if "four" means four canonical mechanism classes and they include:

- at least one large substrate win;
- at least one clearly policy-sensitive family;
- and enough pattern diversity on the userspace side to show why the split matters.

No, if "four" means the exact current set as the final paper payload.

The current set is borderline because:

- `wide_load`, `rotate_fusion`, and `lea_fusion` all read like kernel-owned peepholes;
- `cmov_select` is the only live policy-sensitive family, and its present matcher is too narrow;
- `lea_fusion` has zero runnable corpus sites;
- prologue/epilogue is still a large uncovered bucket.

My read is:

- `4` canonical families is enough as a mechanism count;
- the current *composition* of those four is not yet enough for OSDI without either one more strong straight-line family (`bitfield_extract`) or one more structural family (`branch_reorder` / hybridized select normalization).

## 3. Kernel Patch Review: What Are The Next Optimization Opportunities In `bpf_jit_comp.c`?

### 3.1 The important distinction

Some of the best next steps are new directives. Some are not. Several obvious x86 inefficiencies should simply be fixed in the kernel JIT, not elevated into userspace policy.

### 3.2 Kernel-local cleanup opportunities

| Opportunity | Code reference | Current behavior | Why it is suboptimal | Directive-worthy? |
| --- | --- | --- | --- | --- |
| Prologue patch-window waste | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:519-522`, `529-531` | Always emits `X86_PATCH_SIZE` NOPs and sometimes an extra `nop3` to preserve layout | Pure code-size tax; comment literally says "waste 5 bytes for now and optimize later" | No |
| Direct tail-call patch-window waste | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:841-865` | Emits a direct jump, then burns another `X86_PATCH_SIZE` NOP window | Same issue in another hot structural path | No |
| Zero-displacement memory encoding waste | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1584-1591` | Always emits a disp8 even for `off == 0` to avoid special-casing R13 | One wasted byte on many loads/stores | No |
| 64-bit stack immediate stores | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1849-1856` | Always materializes imm64 in a register and then stores | Misses zero/small-immediate special cases | No |
| `div/mod` save-restore overhead | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3220-3288` | Pushes/pops `rax` and `rdx`, routes through `r11` conservatively | Correct but liveness-blind; expensive in tight integer code | No |
| Variable shift fallback overhead | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3332-3389` | Uses BMI2 when possible, otherwise saves/restores `rcx` or bounces through `r11` | Correct but still conservative when liveness would allow less motion | No |
| Over-verbose endian handling | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3391-3446` | Uses register-side `ror`/`bswap`/`movzwl` sequences only | No `movbe`; no fused load+extract path | Usually no; partly a precondition for new directives |

These are straightforward patch-review items. They improve the backend whether or not userspace policy exists.

### 3.3 Directive-worthy gaps or at least directive-adjacent gaps

| Opportunity | Code reference | What is missing today | Why it matters |
| --- | --- | --- | --- |
| Partial wide loads beyond `2/4/8` | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2220-2290`, `2543-2577` | The code explicitly says `3/5/6/7` are not supported | This leaves byte-recompose coverage incomplete |
| Richer LEA patterns | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2451-2540`, `2658-2720` | Only `mov + shl(1..3) + add`; no displacement, no subtract/add-imm forms | Current LEA family is too narrow to appear in corpus |
| Bitfield/extract lowering | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3332-3446` | No `bextr`-style or equivalent extract family | Packet/socket parsing still pays extra shifts and masks |
| Branch-layout control | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3823-4043` | Linear compare/test + `jcc` lowering only; no block placement | This is the real general control-flow gap behind `branch_layout` |
| Broader select recognition | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3039-3076`, `3886-3919`; `scanner/src/scanner.cpp:114-146` | Only two local select layouts are recognized | Current CMOV story misses the benchmarks that make it compelling |
| Bounds-window reasoning | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3589-3637` and packet parser paths generally | No way to delete redundant later guards after one dominating readable-window check | Packet parsing still pays repeated compare/add/branch overhead |

### 3.4 Per focus area requested by this review

#### Prologue / epilogue generation

What the kernel already does well:

- It has already adopted a first adaptive callee-saved optimization: `detect_reg_usage()` only tracks BPF regs `6-9` and only saves corresponding callee-saved registers (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2059-2073`, `2918-2943`, `4060-4066`).

What remains conservative:

- fixed prologue NOP windows (`519-531`);
- always materialized frame-pointer setup for normal programs (`546-555`);
- unconditional `r12` save/load when arena VM is present (`2937-2943`, `4064-4066`);
- duplicated tail-call teardown sequences in both direct and indirect tail-call paths (`728-870`).

Bottom line: this bucket is still real, and it is currently completely outside the four-family directive set.

#### ALU operation emission

The simple "does it always use 64-bit ops?" question is mostly answered in the kernel's favor. The main ALU paths already distinguish `BPF_ALU` from `BPF_ALU64` correctly (`3081-3205`). So the generic width discipline is not the biggest obvious remaining flaw.

The remaining ALU-side gaps are more specific:

- `div/mod` around `rax/rdx` are conservative and heavy (`3220-3288`);
- variable shifts still require `rcx` juggling on the non-BMI2 path (`3332-3389`);
- endian and cast sequences are verbose and not load-aware (`3097-3139`, `3391-3446`).

#### Memory access patterns

The kernel emits standard x86 base/index/disp addressing competently, but still leaves efficiency on the table:

- it wastes a byte on `off == 0` loads/stores (`1584-1591`);
- current wide-load lowering stops at `2/4/8` widths (`2220-2290`, `2543-2577`);
- there is no packet/ctx-specific wide-load or load+extract family;
- there is no `movbe` path for endian-sensitive memory loads.

#### Branch emission

This is still the biggest structural weakness after byte-recompose.

- Stock lowering remains `cmp/test + jcc` in a linear emitter (`3823-4043`).
- Current CMOV support only fires on exact matched select idioms (`3039-3076`, `3886-3919`).
- The jump-padding and `addrs[]` convergence machinery make true block reordering awkward inside the current backend (`3925-4043`).

This is exactly why the repo's later design docs move `branch_reorder` to verifier level.

#### Constant materialization

The current JIT already contains several good local peepholes:

- `0` goes to `xor reg, reg`;
- 32-bit fitting immediates are used when possible;
- imm64 materialization is narrowed when it fits (`emit_mov_imm32`, `emit_mov_imm64` around `911-998`).

What it does not do:

- narrow the stack-store path for common imm64 stores (`1849-1856`);
- reuse or CSE repeated constants across nearby emission sequences;
- exploit memory forms for some endian/extract patterns.

#### Bounds check emission

The `BPF_PROBE_MEM` path is correct but conservative. The check sequence at `3589-3637` is long enough to matter:

- load `VSYSCALL_ADDR`;
- copy address to `r11`;
- add offset;
- subtract;
- load `limit`;
- compare;
- branch;
- synthesize zero result on failure.

This path is semantics-heavy and not the first place I would try to paper-sell a directive. But it is concrete evidence that bounds reasoning remains expensive in the kernel JIT.

#### Extension / truncation handling

Again, the kernel is correct but verbose:

- BE16 uses `ror ax, 8` plus `movzwl`;
- BE32/64 use `bswap`;
- LE16/32 use explicit zero-extension idioms (`3391-3446`).

There is no extract-aware lowering here, which is one reason `bitfield_extract` is attractive.

#### Stack frame setup

The biggest remaining issues are not semantic bugs; they are conservative layout choices:

- fixed patch windows;
- fixed frame pointer;
- arena-base materialization via `r12`;
- tail-call bookkeeping pushing/popping extra slots.

This matches the characterization's `18.5%` prologue/epilogue bucket: it is still very much alive.

### 3.5 What LLVM does better that the kernel JIT still does not do at all

The most important "LLVM does this, kernel does not" items are:

1. Native select lowering in real control-flow cases. The characterization still says `31` LLVM `cmov` versus kernel `0` (`docs/kernel-jit-optimization-plan.md:122-123`).
2. Hot/cold branch layout. The `branch_layout` characterization shows `0.225x` versus `0.326x`, a `44.6%` input-sensitivity gap, and the kernel has no block scheduler (`docs/kernel-jit-optimization-plan.md:124-125`).
3. Native packet/header extraction patterns. The current kernel JIT has no bitfield/extract family at all, and current wide-load support is still partial.
4. More aggressive backend cleanup around fixed prologue cost. The kernel has improved here, but the remaining fixed-NOP and frame-layout conservatism show that it is not finished.

## 4. Performance Gap Analysis

### 4.1 Baseline numbers

The characterization anchor is:

- pure-JIT exec geomean `L/K = 0.849x` on `31` benchmarks (`docs/kernel-jit-optimization-plan.md:120`; `micro/results/performance_deep_analysis.md:11-16`)

Equivalent ways to read that:

- parity gap in ratio space: `1 - 0.849 = 0.151`
- kernel slowdown versus LLVM: about `17.8%`

The native-code-surplus decomposition says:

- byte-recompose: `50.7%`
- branch/control-flow: `19.9%`
- prologue/epilogue: `18.5%`
- combined backend-heavy surplus: about `89.1%`

Source: `docs/tmp/k2-merlin-epso-comparison.md:111-127`.

### 4.2 What fraction of this gap do the current directives recover?

The repo does not yet have a whole-suite measured recovery number for "stock kernel JIT" versus "BpfReJIT kernel" on the 31 pure-JIT benchmarks. So there is no honest suite-level percentage to quote.

What we can say:

- `rotate` clearly recovers meaningful local gaps and produces the strongest isolated wins.
- `wide_load` attacks the biggest characterized bucket, but the current rigorous isolated kernel result is still statistically weak.
- `lea` recovers a small local gap on one benchmark and has no corpus presence.
- `cmov` currently recovers negative gap on the one isolated benchmark where it really applies, and aggregate corpus CMOV is mostly negative.

So the currently demonstrated aggregate recovery is:

- positive on selected micro cases;
- not yet demonstrated as positive at suite level;
- negative on the current measured packet corpus aggregate.

### 4.3 Theoretical maximum with backend-only changes

There are two sensible upper bounds.

#### Native-code-surplus upper bound

If the decomposition is taken literally, about `89.1%` of measured native-code surplus is backend-side. That is the cleanest statement to make in the paper.

#### Naive runtime-ratio upper bound

If you naively map that `89.1%` recovery onto the `0.849x` execution ratio, the implied best-case backend-only runtime would be roughly:

- `L/K ~= 0.98x`

depending on whether you do the mapping in ratio space or slowdown space.

This is an inference, not a measurement. I would not write it as a headline result. But it is a useful planning bound: backend-only changes plausibly move the kernel very close to parity, not all the way to perfect equality.

### 4.4 Biggest remaining contributors we have not addressed

Ordered by likely remaining importance:

1. The rest of byte-recompose and field extraction:
   - unsupported `3/5/6/7` wide loads;
   - packet/ctx-specific wide loads;
   - bitfield/extract idioms;
   - endian-aware load fusion.
2. Control-flow beyond narrow selects:
   - broader select normalization;
   - branch layout / hot fallthrough;
   - redundant bounds-window checks in packet parsers.
3. Prologue / epilogue:
   - still a measured `18.5%` bucket;
   - untouched by current directives.
4. Small but real x86 backend cleanup:
   - zero-displacement encodings;
   - stack imm64 stores;
   - liveness-aware save/restore cleanup around `div/mod` and shifts.

## 5. Concrete Next Directive Proposals

Two notes before the table:

1. The expected site counts below are estimates, because the current scanner does not yet detect these families directly.
2. Some of the highest-value next tasks are not new families at all. In particular, broader CMOV/select recognition is an enabling task for the existing `cmov_select` family, not obviously a separate directive family.

| Proposal | Description | Current code it would affect | Expected corpus site count | Expected perf impact | Complexity | Type | Priority |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `bitfield_extract` | Recognize `(src >> c) & mask` and packed-field extraction; lower to `bextr` when available or compact `shr+and` sequence otherwise | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3332-3446`, plus new canonical emitter near `2579-2721`; userspace patterns in `scanner/src/pattern_v5.cpp` | `~100-300` runnable-corpus sites | Medium-high on packet/socket parsing, checksum, RSS-style code; also helps code size | About `100-200` LOC kernel plus patterns; `docs/tmp/jit-pass-framework-v5-design.md:1633-1641` explicitly proposes it as a low-cost next canonical form | Mostly straight-line peephole / substrate | P0 |
| `packet_ctx_wide_load` | Extend wide-load fusion from current local ladders to packet and ctx field extraction with fixed offsets | Existing wide-load paths at `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2220-2290, 2543-2577`, generic load emission at `1639-1748`; likely needs verifier retained-fact path too | `~300-800` sites | High on packet-heavy XDP/TC/socket code; likely the biggest next practical recovery family | `150-250` LOC for the verifier-side pass according to `docs/tmp/bpf-jit-advisor-v7.md:2218-2222`, plus emitter/pattern work | Mostly substrate, likely verifier-assisted | P0 |
| `bounds_window` | Remove later redundant guards once an earlier dominating readable-window check proves them unnecessary | Current evidence lives in packet-load and guard-heavy paths; today the relevant backend symptoms show up around `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3589-3637` and repeated branch lowering at `3823-4043` | `~50-200` sites, but high leverage per site | High on parser fast paths and bounds-heavy ladders | `150-250` LOC verifier pass per `docs/tmp/bpf-jit-advisor-v7.md:2218-2222` | Policy-sensitive / structural verifier transform | P1 |
| `branch_reorder` | Closed-diamond hot/cold fallthrough reordering driven by workload and branch predictability | The missing functionality corresponds to current linear branch emission at `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3823-4043`; design docs already argue it does not fit local `do_jit()` patching | `~50-150` closed diamonds in realistic workloads; site count is secondary to importance | Potentially high where branch bias is stable; strongest structural novelty candidate | `250-400` LOC per `docs/tmp/bpf-jit-advisor-v7.md:2218-2222` | Strongly policy-sensitive | P1 for paper value, P2 for engineering difficulty |
| `wide_store` | Fuse adjacent narrow stores or zero-init runs into wider native stores | Would extend store emission near `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1750-1847` and stack-init paths | `~50-150` sites, mostly tracing / stack-init heavy code | Low-medium for runtime, medium for code size | `100-160` LOC according to `docs/tmp/bpf-jit-advisor-v7.md:2306-2308` and `docs/tmp/jit-pass-framework-v5-design.md:1633-1641` | Straight-line substrate | P2 |
| `subprog_inline` | Inline hot BPF-to-BPF call chains to remove call/return overhead and expose more local combines | Would interact with call/tail-call lowering at `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3783-3821`, but the repo's later design docs correctly place it before JIT at verifier level | Many candidate programs exist (`97.2%` multi-function prevalence), but profitable hot sites are probably only tens to low hundreds | Medium-high on hot call chains; potentially important long-term | High; not a narrow patch; requires re-verification and subprog pipeline changes | Strongly policy-sensitive, but heavy | P3 / future |

### 5.1 Why these and not "more CMOV" as a new family?

Because the immediate CMOV problem is recognition coverage, not lack of a family slot.

The current scanner only recognizes two local layouts:

- diamond: `jcc +2; mov; ja +1; mov`
- compact: `mov; jcc +1; mov`

That is `scanner/src/scanner.cpp:114-146`. It also omits `JSET/JSET32` from its accepted conditional-jump set (`scanner/src/scanner.cpp:40-53`).

So the immediate CMOV to-do list is:

1. broaden select recognition for the existing `cmov_select` family;
2. ideally move recognition to a verifier-normalized internal select abstraction;
3. only then decide whether a separate structural branch policy family is needed in the next increment.

I would not sell "cmov_v2" as a new family until the current family has proper recognition coverage.

## 6. Is The Current Improvement Sufficient For OSDI?

### 6.1 Short answer

Not yet.

### 6.2 Why not yet

OSDI does not require a giant average speedup if the mechanism is novel, deployable, and rigorously evaluated. But the current snapshot still has three evaluation weaknesses:

1. No positive whole-suite recovery number for the stock-kernel-to-BpfReJIT path.
2. Real-program execution evidence is still narrow and noisy; the measured paired corpus is almost entirely packet replay and many rows are tens of ns (`docs/tmp/corpus-recompile-regression-analysis.md:9-35`).
3. The implemented directive mix is still too peephole-heavy. The repo's own readiness review says a stronger OSDI version needs "one third directive family that is truly policy-sensitive, not just another kernel peephole" (`docs/tmp/osdi-readiness-review.md:425-445`).

### 6.3 Comparison with similar systems-paper bars

The local comparison document gives rough external bars:

- K2: `1.36-55.03%` latency reduction
- EPSO: `6.60%` average runtime improvement
- KFuse: up to `2.3x` on real applications

Source: `docs/paper-comparison.md:566-580`.

The lesson is not "we must beat X% average speedup." The lesson is:

- modest averages can still publish if the mechanism is new and the evaluation is convincing;
- but "a few positive micro cases plus a negative current corpus geomean" is not convincing enough.

### 6.4 What would make the performance story sufficient

At minimum, I would want all of the following:

1. One positive aggregate stock-kernel-versus-BpfReJIT number on a non-noisy benchmark slice.
2. One stronger real-program end-to-end evaluation where selective policy beats both:
   - stock kernel JIT
   - and a fixed kernel heuristic baseline
3. One more high-prevalence family beyond the current four, ideally `bitfield_extract` or `packet_ctx_wide_load`.
4. One broader policy-sensitive control-flow result beyond the current narrow CMOV matcher.

### 6.5 What is the weakest current evaluation point?

The weakest point is not raw mechanism correctness. The weakest point is aggregate runtime recovery on real programs.

Concretely:

- the framework shows that fixed kernel heuristics can lose;
- the framework shows that some local backend wins are real;
- but it does not yet show that userspace-controlled backend policy wins often enough, on realistic enough workloads, to carry an OSDI evaluation section.

The second-weakest point is LEA. `lea_fusion` is a fine substrate demo, but with zero runnable corpus sites it should not be counted as major evaluation weight.

## Recommended Next Sprint

If the goal is "best paper value per unit kernel work," I would do this order:

1. Add `bitfield_extract`.
2. Extend `wide_load` toward `packet_ctx_wide_load`.
3. Broaden recognition for the existing `cmov_select` family so the current system can actually hit `switch_dispatch`-style control-flow cases.
4. Land the obvious kernel-local x86 cleanup patches:
   - prologue NOP waste
   - zero-displacement memory encoding
   - imm64 stack-store narrowing
   - better endian/load fusion
5. Decide whether the next structural headline is `bounds_window` or `branch_reorder`.

If the goal is "best OSDI novelty per unit work," I would instead do:

1. `bitfield_extract`
2. broader hybrid `cmov_select` recognition
3. `branch_reorder`
4. one real end-to-end deployment evaluation on a packet policy workload

That ordering is less incremental, but much better aligned with the paper argument.
