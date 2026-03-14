# Microarchitectural Benchmark Analysis Beyond Instruction-Level Effects

## Scope and Repo-State Notes

Read for this analysis:

- `docs/tmp/benchmark_coverage_analysis.md`
- `docs/paper.md` sections 5 and 9
- `config/micro_pure_jit.yaml`
- representative programs under `micro/programs/*.bpf.c`

Important current-tree distinction:

- `config/micro_pure_jit.yaml` now contains **45** benchmarks, not the older 31-case inventory used by the paper's authoritative pure-JIT analysis.
- Several microarchitecture-oriented additions now exist in the tree or in fixed-validation artifacts: `memcmp_prefix_64`, `packet_parse_vlans_tcpopts`, `local_call_fanout`, `packet_rss_hash`, `imm64_storm`, `alu32_64_pingpong`, `branch_fanout_32`, `deep_guard_tree_8`, `mega_basic_block_2048`.
- That means some gaps identified in the older coverage note are no longer "missing in source"; the remaining question is whether they are already sufficient, isolated, and authoritatively measured.

Two current-suite facts matter a lot for the analysis below:

- The pure-JIT manifest's largest staged/packet input is only **4104 B**. Most inputs are far smaller. So the current suite is still overwhelmingly **L1D-resident** and does not meaningfully probe L2/L3 or memory-latency regimes.
- The in-tree PMU support from `micro/runner/src/perf_counters.cpp` is limited to `cycles`, `instructions`, `branches`, `branch_misses`, `cache_references`, `cache_misses`, `task_clock_ns`, `context_switches`, `cpu_migrations`, and `page_faults`. That is enough for basic branch studies and coarse cache transitions, but not enough for frontend, iTLB, port-pressure, ROB, store-forwarding, or SMT resource attribution.

The paper's PMU caveat also still applies: kernel-side PMU collection includes kernel-mode activity around `BPF_PROG_TEST_RUN`, while llvmbpf PMU collection is user-only. For the dimensions below, PMU is therefore best treated as:

- strong for within-runtime sweeps,
- decent for coarse paired trends,
- weak for fine-grained kernel-vs-llvmbpf causal attribution unless the runner is extended.

## High-Level Conclusion

The biggest microarchitectural gaps are no longer "we need another ALU microkernel." The bigger missing space is:

- **data-side working-set scaling** beyond L1,
- **frontend thresholds**: L1I, DSB/uop cache, alignment cliffs, and iTLB/page working set,
- **SMT interference** and shared-core contention,
- **store-side backend behavior**: store buffer, store-to-load forwarding, event-struct construction,
- **predictor-capacity effects** beyond simple branch density: BTB, indirect branches, and return behavior.

The current suite already does a solid job on:

- scalar dependency depth,
- ILP vs pressure tradeoffs,
- branch density and some branch layout,
- byte-recompose vs direct wide-load lowering,
- fixed local-call overhead at a small scale.

It does **not** yet do a solid job on:

- when code-size savings actually become **frontend wins**,
- when data layout/alignment amplifies or suppresses the wide-load advantage,
- how codegen behaves under **shared-core** pressure,
- how write-heavy BPF motifs behave,
- when JIT differences wash out because the benchmark becomes truly memory-bound.

## Current Tree Signals Worth Noting

Even before adding new benchmarks, the newer provisional cases already hint at the right directions:

- `packet_rss_hash` appears to be a strong differentiator in fixed validation: llvmbpf was roughly **0.47x** kernel execution time with smaller code. Packet arithmetic plus field extraction looks more revealing than `checksum`.
- `local_call_fanout` appears meaningful: llvmbpf was roughly **0.72x** with a much smaller multi-function layout. That suggests multi-function frontend/prologue effects are real.
- `mega_basic_block_2048` is the first benchmark that plausibly creates a real L1I cliff: provisional native size was about **30.7 KB** for llvmbpf vs **49.5 KB** for kernel.
- `memcmp_prefix_64` and `packet_parse_vlans_tcpopts` both showed mild **smaller-but-slower** behavior in fixed validation, despite smaller llvmbpf code. That is exactly the kind of frontend/branch microarchitecture paradox the current authoritative suite only partially explains.
- `branch_fanout_32` was faster on llvmbpf even though its provisional native code was larger than kernel's. That is a useful warning: once control-flow shape changes, static code size alone stops being a reliable predictor.

## 1. Data Structure Layout and Memory Access Patterns

### Relevance

- Relevant for real BPF programs that read map values, packet headers, CO-RE structs, ringbuf records, and event payloads.
- However, not every subtopic here is equally JIT-sensitive. Field ordering and false sharing mostly change the **workload's memory behavior**, not the JIT's semantics. They matter because they modulate whether the JIT's load/store strategy gets amplified or masked.
- Alignment and line-splitting are much more directly JIT-relevant, because llvmbpf often tries to capitalize on direct wide loads while the kernel JIT frequently falls back to byte-oriented reconstruction.

### Current Coverage

- Partially covered:
- `memory_pair_sum`, `load_native_u64`, `load_byte_recompose`, `load_word32`, `checksum`, `packet_parse`, `packet_parse_vlans_tcpopts`, and `packet_rss_hash` all exercise read-side layout sensitivity.
- `stride_load_4` and `stride_load_16` cover sequential vs wider-stride access, but only over a tiny ring.
- `memcmp_prefix_64` adds early-exit byte comparison over structured byte arrays.

- Still missing:
- typed hot/cold struct layout experiments,
- deliberate cache-line split loads/stores,
- true random gather or pointer-chasing,
- array-of-structs versus struct-of-arrays,
- write-heavy field packing,
- false sharing or coherence traffic.

- Most current programs use `unsigned char data[...]` plus helper-style byte assembly. That is excellent for isolating byte-recompose, but weak for studying realistic typed struct layout.

### New Benchmarks

- `struct_hotcold_layout`: same semantic fields, but hot fields are either packed into one 64 B line or split across two lines.
- `cacheline_split_load`: place a hot 8-byte field at offsets like 56, 60, and 63 to compare aligned, line-split, and worst-case unaligned access.
- `aos_vs_soa_classifier`: same logical record set, one as array-of-structs and one as struct-of-arrays.
- `random_gather_mapvalue`: fixed-count indirect gather through a permutation table or pointer-like offset table.
- `event_struct_pack`: build a small output struct with different field orderings, then read back selected fields before returning.

### Likely Kernel vs llvmbpf Magnitude

- Field ordering alone: usually **low to medium** as a JIT differentiator, often under 10-15%.
- Alignment and cache-line splitting: **medium**, and sometimes higher, because direct wide loads can either shine or hit split-load penalties.
- Random gather / pointer-chase: usually **low** as a JIT differentiator once memory latency dominates. Good for realism, less good for separating JITs.
- False sharing: potentially huge absolute slowdown, but probably **low priority** for kernel-vs-llvmbpf because both runtimes will touch the same coherence domain.

### PMU Measurability

- Current runner counters: only **partial**. `cache_references` and `cache_misses` can show gross transitions but not line-split behavior or hierarchy level.
- Better events needed: L1/L2/L3 breakdown, load-blocking, aliasing, and coherence events.
- False sharing especially needs events outside the current 10-counter set.

## 2. Cache Hierarchy Effects

### Relevance

- Very relevant for real 1k-10k-insn BPF programs, especially once packet parsers, policy trees, or multi-function programs stop fitting entirely in the smallest frontend structures.
- On the data side, relevance depends on working-set size. Many tracing programs only touch a few fields, but many map-heavy or batch-like programs do not.

### Current Coverage

- I-side partial coverage:
- `large_mixed_500` and `large_mixed_1000` begin to stress larger code footprints.
- `imm64_storm` and `mega_basic_block_2048` push farther in the current manifest.

- D-side partial coverage:
- `stride_load_4`, `stride_load_16`, `checksum`, and `mixed_alu_mem` exercise access patterns.

- But the current pure-JIT suite is still overwhelmingly **below true cache-capacity stress**:
- maximum input size is only 4104 B,
- most inputs fit comfortably in L1D,
- no benchmark intentionally grows data working set through L1, L2, LLC, and memory,
- no benchmark explicitly separates data-cache effects from code-cache effects.

### New Benchmarks

- `working_set_seq_sweep`: same sequential reduction kernel at 1 KB, 8 KB, 32 KB, 256 KB, and 1 MB.
- `working_set_stride_sweep`: same working-set ladder, with stride values chosen to cooperate with or defeat prefetchers.
- `prefetch_breaker_random`: same arithmetic as the sequential sweep, but with randomized access order.
- `hot_loop_cold_blob`: identical hot loop, but increasing amounts of cold inline code to isolate L1I pressure from dynamic work.
- `function_footprint_sweep`: same logical work spread across 1, 4, 8, and 16 local functions to test instruction working set rather than data working set.

### Likely Kernel vs llvmbpf Magnitude

- Data working-set sweep: the JIT gap should usually **shrink** as the benchmark becomes truly memory-bound.
- Instruction working-set sweep: likely **medium to high**, especially when the kernel version spills past a frontend threshold before the llvmbpf version does.
- Prefetch-sensitive stride/random sweeps: often **medium** at most as a paired JIT effect, but still important for understanding when codegen differences wash out.

### PMU Measurability

- Current runner counters: **coarse only**. Good enough to detect broad cache-miss phase changes, not enough to identify L1 vs L2 vs LLC or I-side vs D-side misses.
- Better with external perf or runner extension: cache hierarchy and iTLB/icache events.

## 3. SMT / Hyper-Threading

### Relevance

- Highly relevant in practice. BPF frequently runs on cores that are not dedicated, and a single-threaded benchmark on an idle sibling can materially overestimate wins that disappear under contention.
- The two JITs emit different mixes of loads, shifts, branches, `cmov`, and BMI instructions, so they are unlikely to degrade identically under shared-core pressure.

### Current Coverage

- Not covered by the current suite at all.
- The harness can pin to a CPU, but it does not currently orchestrate sibling-thread interference or compare SMT-on versus SMT-off runs.

### New Benchmarks or Configurations

- First do this as a **configuration matrix**, not a new BPF program:
- run existing `load_byte_recompose`, `bitcount`, `switch_dispatch`, `local_call_fanout`, `packet_rss_hash`, and `mega_basic_block_2048` with the sibling thread idle,
- then with a frontend-heavy sibling burner,
- then with an ALU/port-heavy sibling burner,
- then with a load/store-heavy sibling burner.

- If a dedicated benchmark is desired:
- `paired_bpf_same_core`: two copies of the same BPF benchmark launched simultaneously on sibling threads.

### Likely Kernel vs llvmbpf Magnitude

- Usually **medium**, often 5-25% extra differential.
- Largest candidates are port-limited or frontend-limited kernels such as `load_byte_recompose`, `imm64_storm`, and `mega_basic_block_2048`.
- SMT is also a plausible way to manufacture new smaller-but-slower paradoxes.

### PMU Measurability

- Current runner counters: enough to observe overall slowdown and maybe coarse branch/cache changes.
- Not enough to explain shared ROB, scheduler, RS, or port contention.
- Proper attribution needs topdown or port/uop events.

## 4. Bank Conflicts, Port Pressure, AGUs, and Buffers

### Relevance

- Relevant, but this is where microarchitecture specificity starts to matter.
- Kernel byte-recompose emits many loads, shifts, and ORs; llvmbpf sometimes trades those for wider loads, `lea`, `cmov`, and BMI2. That is a real port-mix difference.
- Register-file bank conflicts are probably too vendor-specific and too hard to generalize to be a first-wave benchmark target.

### Current Coverage

- Partial incidental coverage:
- `load_byte_recompose`,
- `mixed_alu_mem`,
- `bitcount`,
- `alu32_64_pingpong`,
- `packet_rss_hash`,
- `local_call_fanout`.

- Missing:
- explicit AGU saturation,
- load/store queue pressure,
- store buffer saturation,
- store-heavy address-generation kernels.

### New Benchmarks

- `agu_triple_gather`: three indexed loads and one indexed store per iteration with dense address arithmetic.
- `store_buffer_ring`: many independent stores before a final reduction.
- `aliasing_load_store`: alternating loads and stores to near addresses with aliasing and non-aliasing variants.
- `stack_record_fill`: build and update a stack or map-value record repeatedly before consuming it.

### Likely Kernel vs llvmbpf Magnitude

- Usually **medium** when the benchmark is tuned to be address-generation or buffer limited.
- Lower on simple scalar kernels.
- Potentially quite relevant for event-output or write-heavy workloads, which the current pure-JIT suite barely touches.

### PMU Measurability

- Current runner counters: effectively **no direct attribution**.
- Needs model-specific port-dispatch and resource-stall events.
- Without those, only the end-result slowdown can be observed.

## 5. Branch Prediction Microarchitecture

### Relevance

- Very relevant. This is one of the most obviously BPF-relevant microarchitectural dimensions.
- Real parsers, classifiers, policy trees, and security filters all create branch-rich hot paths.
- Tail calls and local calls introduce indirect-target and return behavior that simple branch-density tests do not capture.

### Current Coverage

- Better covered than most other dimensions:
- `branch_layout`,
- `branch_dense`,
- `switch_dispatch`,
- `binary_search`,
- `memcmp_prefix_64`,
- `deep_guard_tree_8`,
- `packet_parse`,
- `packet_parse_vlans_tcpopts`,
- `local_call_fanout`,
- `bpf_call_chain`.

- Remaining holes:
- BTB capacity effects,
- predictor history pollution,
- indirect branch prediction for tail calls,
- deeper return-stack effects,
- distribution sensitivity beyond one fixed synthetic input mix.

### New Benchmarks

- `btb_capacity_sweep`: many distinct branch sites executed in round-robin to exceed target-buffer capacity gradually.
- `predictor_alias_pair`: two branches with adversarially correlated patterns to stress shared history structures.
- `tail_call_pipeline`: 4-, 8-, and 16-stage prog-array pipelines.
- `rsb_depth_sweep`: nested local-call trees with call depths beyond typical shallow cases.
- Input-only variants for current programs:
- `branch_layout` with 99/1, 90/10, 50/50, alternating, and randomized distributions,
- `memcmp_prefix_64` with different early/late mismatch mixes,
- `deep_guard_tree_8` with biased versus uniform leaf probabilities.

### Likely Kernel vs llvmbpf Magnitude

- Basic branch-layout effects: already **medium**.
- `cmov`-friendly select workloads can be **high**.
- BTB and indirect-target effects could also be **medium to high** in multi-stage or tail-call-heavy designs.
- Deep RSB effects are probably **low relevance** for typical shallow BPF local-call depth, but still worth a synthetic stressor.

### PMU Measurability

- This is one of the few dimensions that the current runner can already measure reasonably well.
- `branches` and `branch_misses` are available now.
- What remains missing is only the finer breakdown: BTB vs PHT vs indirect predictor vs RSB.

## 6. Frontend Effects: Fetch, Decode, DSB/uop Cache, LSD

### Relevance

- Highly relevant on Intel-class x86, especially because the paper's strongest structural result is that llvmbpf usually emits much less code.
- Once programs get large enough, the main question stops being "how many instructions?" and becomes "which frontend thresholds did each runtime cross?"

### Current Coverage

- Partial, but not isolated.
- `large_mixed_500`, `large_mixed_1000`, `imm64_storm`, `branch_fanout_32`, and `mega_basic_block_2048` all move toward frontend stress.
- None of them isolate:
- fetch alignment,
- DSB residency,
- decode bandwidth,
- LSD eligibility,
- or the exact threshold at which smaller code becomes a true frontend win.

### New Benchmarks

- `loop_body_size_sweep`: same recurrence with hot loop bodies engineered to land around important frontend size thresholds.
- `alignment_pad_sweep`: hot loop alignment shifted without changing semantics.
- `lsd_candidate` and `lsd_breaker`: two nearly identical tight loops where one stays in the loop-stream-friendly regime and one barely exits it.
- `cmov_predictable_branch`: highly predictable branches where branchless lowering could reduce code size while worsening dependency structure.

### Likely Kernel vs llvmbpf Magnitude

- Usually **medium**, but can become **high** once one runtime crosses an L1I/DSB/LSD threshold and the other does not.
- Alignment-only effects are often smaller, but they are exactly the sort of mechanism that can create a credible smaller-but-slower paradox.

### PMU Measurability

- Current runner counters: **not enough**.
- Stronger attribution needs frontend-specific events or topdown metrics.
- Cycles plus code-size sweeps can still reveal the existence of the effect even if they cannot prove the exact frontend sub-mechanism.

## 7. Backend Effects: ILP, Rename Pressure, ROB, STLF, Disambiguation

### Relevance

- Very relevant, and this is the area the current suite already covers best.
- But the current suite covers mostly **read-heavy scalar backend behavior**, not write-heavy backend behavior.

### Current Coverage

- Strong existing coverage:
- `dep_chain_short`,
- `dep_chain_long`,
- `multi_acc_4`,
- `multi_acc_8`,
- `spill_pressure`,
- `fixed_loop_small`,
- `fixed_loop_large`,
- `nested_loop_2`,
- `nested_loop_3`,
- `code_clone_2`,
- `code_clone_8`,
- `mixed_alu_mem`,
- `alu32_64_pingpong`,
- `mega_basic_block_2048`.

- Missing:
- store-to-load forwarding success/failure,
- partial-width forwarding hazards,
- store buffer occupancy,
- stack/event-struct readback,
- memory disambiguation cases where address relations are hard to prove dynamically.

### New Benchmarks

- `stlf_hit_miss`: exact store-forwarding hit vs partial-overlap miss variants.
- `event_struct_fill_readback`: construct a record on stack or in map value, then immediately consume selected fields.
- `aliasing_store_load`: same-address, nearby-address, and non-aliasing variants.
- `rename_pressure_wide`: a wide temporary-heavy kernel with minimal memory traffic.
- `atomic_plus_readback`: runtime-backed atomic updates followed by dependent reads to expose ordering and forwarding costs.

### Likely Kernel vs llvmbpf Magnitude

- Existing ILP/dependency coverage already shows **medium to high** effects.
- The missing store-side cases are likely **medium**, but they matter a lot for real tracing and event-output programs.
- Memory-disambiguation-specific gaps will probably be smaller and noisier unless designed very carefully.

### PMU Measurability

- Current runner counters: only coarse end-result observation.
- Proper attribution needs store-forwarding, resource-stall, or topdown-style backend events.

## 8. Code Size, iTLB, and Page-Boundary Effects

### Relevance

- Highly relevant for real 1k-10k-insn BPF programs.
- This is probably the single most important "go beyond instruction count" dimension that is still underdeveloped.
- If llvmbpf is often 1.5-2x smaller in native bytes, page count and instruction working-set structure will diverge materially long before total instruction count reaches pathological extremes.

### Current Coverage

- Partially covered:
- `large_mixed_500`,
- `large_mixed_1000`,
- `imm64_storm`,
- `mega_basic_block_2048`.

- But still not isolated:
- no explicit text-page sweep,
- no page-boundary crossing control,
- no multi-function code-placement sweep,
- no deliberate iTLB study.

- `mega_basic_block_2048` is especially promising here because the provisional native size difference is already large enough to plausibly separate "fits in roughly 32 KB L1I-sized regime" from "does not."

### New Benchmarks

- `text_page_sweep`: same hot semantics, but progressively larger cold code to create 4 KB, 8 KB, 16 KB, 32 KB, and 64 KB text footprints.
- `page_boundary_loop`: hot loop aligned fully inside a page versus straddling a 4 KB boundary.
- `multi_function_scatter`: same total work split across 1, 4, 8, and 16 local functions.
- `hot_cold_section_split`: inline cold miss path versus out-of-line cold path.

### Likely Kernel vs llvmbpf Magnitude

- Often **medium to high** once code footprint crosses L1I, DSB, or iTLB thresholds.
- This is likely where code-size savings will finally translate into a microarchitectural win that looks larger than what instruction-count ratios alone would predict.

### PMU Measurability

- Current runner counters: **no direct iTLB or I-cache visibility**.
- Needs `itlb` and icache-related events from extended perf collection.
- Even without those events, careful footprint sweeps should still show interpretable cycle cliffs.

## Configuration-Only Experiments That Should Be Run

These do not require new BPF programs, only runner, input, or machine-configuration changes.

### 1. SMT Matrix on Existing Benchmarks

- Run on an isolated logical CPU with sibling idle.
- Run again with the sibling running:
- a frontend burner,
- an ALU/port burner,
- a load/store burner,
- a branchy burner.

Best existing candidates:

- `load_byte_recompose`
- `switch_dispatch`
- `packet_rss_hash`
- `local_call_fanout`
- `mega_basic_block_2048`

### 2. Fixed-Frequency Sweeps

- Run at two or three fixed frequencies with turbo off.
- Interpretation:
- if the ratio stays similar, the benchmark is likely still core-bound,
- if the ratio compresses at lower frequency, memory/cache effects are taking over,
- if the ratio widens at higher frequency, frontend/backend core resources are probably the real bottleneck.

### 3. Input-Distribution Sweeps for Existing Branch Benchmarks

- `branch_layout`: 99/1, 90/10, 50/50, alternating, randomized.
- `memcmp_prefix_64`: early mismatch dominated, late mismatch dominated, full-match dominated, uniform mix.
- `deep_guard_tree_8`: hot-leaf skew versus uniform leaf use.
- `packet_parse_vlans_tcpopts`: 0/1/2 VLAN tags, short vs long TCP options, valid-only vs mixed-valid-invalid packets.

These should reveal microarchitectural effects without changing the BPF bytecode.

### 4. Larger Repeat Counts for PMU Visibility

- Many microbenchmarks are too short for stable PMU counts.
- Run `--perf-counters --perf-scope full_repeat_avg` with substantially larger `repeat` values on selected branch- and cache-oriented cases.
- This will not fix the PMU asymmetry, but it will make counters non-zero often enough to be useful.

### 5. Authoritative Promotion of the Newer Provisional Cases

- Several already-implemented benchmarks are probably more useful than adding brand-new ones immediately.
- The first action should be to bring these into the same stable, publication-quality paired run flow:
- `packet_rss_hash`
- `local_call_fanout`
- `memcmp_prefix_64`
- `packet_parse_vlans_tcpopts`
- `mega_basic_block_2048`

## Benchmarks Specifically Designed to Trigger "Smaller but Slower"

Yes, this is possible, and the best candidates are not random. They share one pattern: the code-size reduction does **not** shorten the real dynamic bottleneck.

### 1. `cmov_predictable_branch`

- Same semantics expressed as a highly predictable branch tree.
- If llvmbpf turns it into `cmov`-heavy code, static size may shrink but the critical dataflow chain may lengthen.
- This is a very plausible smaller-but-slower candidate.

### 2. `alignment_cliff_loop`

- Two semantically identical versions whose only difference is padding/alignment around the hot loop.
- The smaller version can still be slower if it lands on worse fetch or DSB boundaries.
- This is the cleanest way to test a frontend paradox directly.

### 3. `hot_loop_cold_blob`

- Inflate or shrink only cold out-of-line work while keeping the hot recurrence unchanged.
- This creates a benchmark where code size changes substantially but the throughput-limiting recurrence does not.
- Good for showing that smaller code does not necessarily mean faster code.

### 4. `btb_alias_compaction`

- Compact code so that more hot branches execute in a denser spatial pattern with worse BTB aliasing.
- The llvmbpf version could be smaller yet suffer more mispredictions.
- Harder to make portable, but very interesting on x86.

### 5. SMT-Only Paradox on Existing Benchmarks

- A benchmark may be smaller and faster in isolation, but smaller and slower under sibling interference.
- `switch_dispatch`, `load_byte_recompose`, and `packet_rss_hash` are strong candidates for this kind of inversion.

Current provisional evidence already suggests this direction is real:

- `memcmp_prefix_64` and `packet_parse_vlans_tcpopts` both showed mildly smaller-but-slower behavior in fixed validation.

## Prioritized First Wave

If the goal is to maximize new microarchitectural insight rather than simply add more benchmarks, the best first wave is:

1. `working_set_seq_sweep` plus `working_set_stride_sweep`
2. `text_page_sweep` plus `page_boundary_loop`
3. SMT configuration matrix on existing `load_byte_recompose`, `switch_dispatch`, `packet_rss_hash`, `local_call_fanout`, and `mega_basic_block_2048`
4. `stlf_hit_miss` plus `event_struct_fill_readback`
5. `btb_capacity_sweep` or `tail_call_pipeline`

Reason:

- Together they hit the biggest remaining blind spots: true cache hierarchy behavior, frontend thresholds, shared-core resource contention, store-side backend effects, and predictor-capacity effects.
- They also move the suite away from its current bias toward single-threaded, read-heavy, L1-resident kernels.

## Bottom Line

The current suite is already strong on instruction-selection-visible backend effects, especially dependency depth, byte-recompose, and simple branch structure. The missing frontier is no longer "more small compute kernels." It is the set of effects that only appear when:

- data no longer lives entirely in L1,
- code footprint starts to matter to L1I/DSB/iTLB,
- the core is shared with a sibling thread,
- stores and read-after-write behavior become first-class,
- or branch prediction is stressed through capacity and indirection rather than just density.

Those are also exactly the effects most likely to matter once you leave 100-500-insn synthetic kernels and move toward realistic 1k-10k-insn BPF programs.
