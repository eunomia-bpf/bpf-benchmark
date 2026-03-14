# Pure-JIT Benchmark Coverage Analysis

## Scope and Snapshot

Reviewed inputs:

- `micro/programs/*.bpf.c`
- `config/micro_pure_jit.yaml`
- `micro/benchmark_catalog.py`
- `docs/paper.md` sections 8 and 9

Current-state observations from the checked-in tree:

- `config/micro_pure_jit.yaml` currently defines **36** pure-JIT benchmarks across **9** categories: `baseline`, `alu-mix`, `dependency-ilp`, `control-flow`, `memory-local`, `loop-shape`, `call-size`, `program-scale`, and `call-overhead`.
- Of those 36 pure-JIT benchmarks, **34** use staged map-backed input and only **2** are packet-backed (`simple_packet`, `fibonacci_iter_packet`).
- `micro/benchmark_catalog.py` is not a second independent catalog. It is only a manifest loader; the taxonomy itself lives in `config/micro_pure_jit.yaml`.
- The paper and the representativeness report still describe an older inventory (`35` pure-JIT benchmarks, no `call-overhead` category). The current critique therefore uses the source tree and manifest as ground truth, not the stale inventory counts.

External-validity frame from `docs/paper.md`:

- The combined suite occupies only **0.8%** of the corpus 5D feature box.
- The suite maximum is **6.9x below** the corpus median on total instructions and **20.6x below** the corpus median on memory ops.
- **97.2%** of corpus programs are multi-function, while the paper explicitly calls out a multi-function gap.
- `BPF_PROG_TEST_RUN` structurally limits execution-time validation to packet-oriented program types, leaving tracepoint/kprobe/perf_event/cgroup scenarios largely out of reach.

Bottom line: the suite is good at isolating a small set of backend mechanisms, but it is still narrow relative to contemporary BPF usage and especially narrow relative to tracing/security programs that rely on BTF, kfuncs, event output, and richer call graphs.

## A. Coverage Gaps

### A1. Variable-length packet parsing is effectively absent

Current coverage:

- `packet_parse` is the only pure-JIT parser-shaped benchmark.
- It parses a fixed 64-byte synthetic Ethernet+IPv4 record with:
  - EtherType always IPv4
  - IPv4 IHL fixed at 5
  - no VLAN tags
  - no IPv6 extension headers
  - no TCP options walk
  - no fragments
  - no malformed or truncated packet cases

Gap:

- There is no benchmark that advances a packet cursor based on header-derived lengths.
- There is no parser loop that mixes bounds checks, variable offsets, and protocol-dependent branch targets.
- There is no realistic XDP/TC-style “one packet per invocation” parser hot path.

Why it matters:

- Real networking BPF code spends a lot of effort on cursor advancement and variable-length validation.
- This is exactly where JIT differences in byte loads, zero-extension, branch threading, and live-range growth become visible.
- The current `packet_parse` instead amortizes one map lookup across **64 synthetic packets inside one invocation**, which is not how production XDP/TC programs execute.

### A2. Map-access motifs are missing from the pure-JIT suite

Current coverage:

- Pure-JIT benchmarks do exactly one staging lookup into `input_map`, then run on a stable map-value pointer.
- The runtime suite has `hash_map_lookup`, `percpu_map_update`, `map_lookup_churn`, and `map_roundtrip`.

Gap:

- Pure-JIT has no dedicated benchmark for hot map lookup call sites.
- There is no LRU map benchmark anywhere.
- There is no clean separation between:
  - lookup helper ABI cost
  - map implementation cost
  - code quality of the surrounding hot loop

Why it matters:

- The current pure-JIT conclusions say little about programs where each event performs one or a few map lookups and then only modest computation.
- The runtime suite proves these motifs exist in the repo, but it does not isolate them as “pure-JIT-ish” call-site patterns because the runtime data-structure behavior dominates.

### A3. String and byte-comparison workloads are untested

Current coverage:

- None of the current benchmarks perform `memcmp`/`strncmp`-style logic, prefix tests, exact-match byte scans, or filename/path matching.

Gap:

- No benchmark exercises early-exit byte comparison.
- No benchmark models common security/tracing patterns such as:
  - license or magic-value checks
  - path prefix matching
  - command name / filename filtering
  - exact header signature comparison

Why it matters:

- These patterns are common in LSM, tracing, and security filters.
- They stress short byte loads, branch diamonds, early exits, and sometimes 32/64-bit mixed compares.

### A4. Call-graph coverage is still too thin

Current coverage:

- `bpf_call_chain` is the only explicit BPF-to-BPF benchmark.
- It is a fixed chain of three local subprogram calls repeated in a loop.

Gap:

- No tail calls.
- No prog-array dispatch.
- No fan-out call graph where the caller chooses among several subprograms.
- No mixed hot/cold subprogram layout.
- No benchmark with several functions that each have different register pressure and prologue needs.

Why it matters:

- The paper already identifies prologue/epilogue quality and callee-saved handling as important.
- A single linear local-call chain is too narrow to represent the multi-function reality the paper itself flags.

### A5. Packet-data arithmetic is only weakly represented

Current coverage:

- `checksum` performs repeated 16-bit reduction, but on staged map memory.
- `packet_parse` only extracts fields; it does not hash or transform them.

Gap:

- No realistic flow-hash benchmark.
- No 5-tuple hash / RSS-style mixing.
- No incremental checksum adjustment after a header rewrite.
- No packet-derived arithmetic that combines endian conversion, field extraction, and scalar mixing.

Why it matters:

- Networking BPF commonly does more than parse; it hashes, classifies, and rewrites.
- Those kernels stress constant materialization, mixed-width arithmetic, rotates/shifts, and data-dependent control.

### A6. Event-output paths are missing

Current coverage:

- No ring-buffer output.
- No `bpf_perf_event_output`.
- No event-struct construction followed by emission.

Gap:

- The suite does not cover one of the most common tracing/control-plane patterns: gather fields, format a small record, emit it.

Why it matters:

- This pattern combines stack or map-value stores, helper ABI setup, and often BTF/CO-RE field extraction.
- It is common enough that its absence leaves tracing-oriented external validity weak.

### A7. BTF-based struct access is missing

Current coverage:

- The pure-JIT suite only touches packet bytes and map values.
- No benchmark uses `BPF_CORE_READ`, `__builtin_preserve_access_index`, or BTF-described kernel struct walks.

Gap:

- No CO-RE style field access.
- No pointer chasing through nested kernel structs.
- No benchmark where field offsets are not “just packet offsets”.

Why it matters:

- BTF-based access is a defining pattern in modern tracing, observability, and security BPF.
- The current suite therefore underrepresents whole classes of production programs even before helper calls are considered.

### A8. kfunc calls are absent

Current coverage:

- No benchmark exercises kfunc call sites.

Gap:

- No kfunc ABI setup.
- No benchmark mixes kfuncs with BTF-based object access.

Why it matters:

- kfunc-heavy code is increasingly common in newer kernels.
- It is a distinct code-generation surface from classic helper calls and should not be treated as equivalent.

### A9. Atomic operations are absent

Current coverage:

- No `lock_xadd`, `xchg`, `cmpxchg`, or explicit atomic counter patterns.

Gap:

- No shared-counter or contention-avoidance motifs.
- No benchmark covers JIT lowering for atomic memory ops.

Why it matters:

- Stateful packet/accounting programs frequently use atomic increments or compare-and-swap style updates.
- This is a backend-visible instruction class, not just a runtime issue.

### A10. Attach-context diversity is still too narrow

Current coverage:

- Pure-JIT is effectively XDP-shaped.
- Packet-backed benchmarks are only `simple_packet` and `fibonacci_iter_packet`, and neither is parser-heavy.

Gap:

- No tracing, security, cgroup, LSM, or perf-event shaped pure-JIT workload.
- No context structs other than packet/map style memory.

Why it matters:

- Sections 8 and 9 of the paper already warn that current execution-time validation is confined largely to TC/classifier and socket-filter scenarios.
- The missing motifs in A6-A9 are not accidental; they are downstream of the harness bias toward packet-test-run-compatible programs.

## B. Unrealistic Patterns

The suite is intentionally synthetic, so “unrealistic” is not automatically a flaw. The issue is whether a benchmark is being used as a mechanism probe or as a proxy for production behavior. Several current kernels are useful mechanism probes but poor workload proxies.

### B1. Bulk staged input creates a batch-processing bias

Most pure-JIT benchmarks:

- perform one staging lookup,
- then iterate over **32/64/128/256** items from a stable map value,
- and return a single scalar.

This differs from many real BPF programs, which usually process:

- one packet,
- one event,
- one map lookup result,
- or a very small number of fields per invocation.

Bias introduced:

- Prologue and helper setup are amortized over many logical work items.
- The suite overemphasizes steady-state loop codegen.
- It underemphasizes entry overhead, cursor setup, context reads, and short hot paths.

The paper acknowledges this partially by calling the design “staged I/O” rather than helper-free isolation, but the resulting workload model is still more batch-like than real XDP/TC or tracing code.

### B2. `packet_parse` is not representative packet parsing

Why it is artificial:

- It loops over **64 synthetic packets inside one invocation**.
- Every record is exactly 64 bytes.
- Every record is parseable as IPv4 with fixed IHL.
- There are no VLAN tags, TCP options, or malformed/truncated records.

What that means:

- It tests fixed-offset field extraction more than real parser behavior.
- It avoids the control-flow irregularity that makes packet parsing hard.

### B3. `binary_search` is not actually binary search

The benchmark named `binary_search` performs:

- a linear scan over 32 elements,
- no early exit once found,
- and a `found` flag update.

That makes it useful as a branch-heavy search kernel, but misleading as a workload label. Real production code would not call this binary search, and the benchmark does not exercise the branch structure or index arithmetic of an actual binary-search tree.

### B4. `code_clone_*` and `large_mixed_*` are explicit stress kernels, not real workloads

`code_clone_2`, `code_clone_8`, `large_mixed_500`, and `large_mixed_1000` are dominated by macro-cloned scalar blocks with repeated synthetic salts.

These are useful for:

- code-size stress,
- scheduler pressure,
- allocator scaling,
- “smaller but slower” paradox analysis.

They are not realistic stand-ins for why real BPF programs become large. Real BPF programs usually grow due to:

- multiple subprograms,
- attach-point boilerplate,
- helper-heavy control flow,
- parser branches,
- policy logic,
- and event-output machinery,

not because the same arithmetic block is cloned many times inside one loop.

### B5. `branch_dense` is a synthetic branch mesh

`branch_dense` applies many unrelated predicates to the same integer:

- threshold compare,
- parity,
- modulo-7 bucket,
- bit tests,
- value range,
- mixed `value`/`i` predicates.

This is good for stressing branch lowering, but it is much denser and less semantically structured than real packet or event classifiers, which usually branch on named fields and often exit early.

### B6. Long scalar recurrences are overrepresented relative to production

`fibonacci_iter`, `fixed_loop_small`, `fixed_loop_large`, `nested_loop_2`, and `nested_loop_3` are all dominated by bounded synthetic recurrences and deep loop nests.

These are valid JIT stressors, but as top-level workload proxies they are weak because:

- BPF latency budgets discourage long synthetic loops,
- real programs more often mix short control flow with field extraction and helper calls,
- and `fibonacci_iter_packet` is especially artificial because it is packet-backed without using packet structure at all.

### B7. Causal-isolation load benchmarks are intentionally non-workload-like

`load_word32`, `load_byte`, `load_byte_recompose`, and `load_native_u64` are clean mechanism probes for width handling and byte recomposition.

But they are not realistic workloads because they:

- isolate one lowering pattern,
- operate on idealized aligned or byte-addressed arrays,
- and avoid the richer control/data structure around those loads that exists in production code.

They should stay in the suite, but they should be treated explicitly as causal-isolation microkernels, not as representative applications.

### B8. Input distributions are deterministic and unusually “clean”

Examples:

- `branch_layout` uses a fixed 90/10 hot/cold split.
- `switch_dispatch` operates on synthetic 6-bit values.
- `packet_parse` uses only valid, fixed-layout packets.
- `hash_map_lookup` uses a deterministic no-miss key set.

Bias introduced:

- predictor behavior may be overfit to one static distribution,
- miss paths and malformed-data paths are underexplored,
- and dynamic-control irregularity is weaker than in production traffic/event streams.

### B9. Repo-hygiene issue: the inventory itself is drifting

This is not a benchmark-pattern issue, but it affects interpretation:

- current `micro_pure_jit.yaml` has **36** benchmarks,
- the paper still describes **35**,
- `micro/results/representativeness_report.md` still reports **35** and omits the new `call-overhead` category,
- `micro/README.md` is also stale.

That drift makes it harder to tell which benchmarks are authoritative, post-hoc causal-isolation cases, or newer additions such as `bpf_call_chain`.

## C. Missing JIT Stress Tests

### C1. Very large basic blocks are only partially covered

Current partial coverage:

- `code_clone_*`
- `large_mixed_*`

What is still missing:

- a truly large **single straight-line block** with many live temporaries and no loop-carried structure,
- or a large join-heavy acyclic region.

Why it matters:

- Current large kernels still rely on repeated loop bodies.
- That stresses steady-state throughput, but not the same scheduling/register-allocation problems as a mega-block emitted from flattened policy code.

### C2. Dense immediate-operand stress is missing

Current state:

- The suite uses some large constants, but usually a small set of repeated salts.

Missing:

- a benchmark with dozens or hundreds of **distinct** 64-bit immediates,
- especially many `BPF_MOV64_IMM` style literals that cannot be trivially reused.

Why it matters:

- This would stress literal materialization, register pressure, and instruction selection.

### C3. Mixed 32-bit and 64-bit arithmetic is under-tested

Current partial coverage:

- many benchmarks use `u32` loop counters and `u64` accumulators,
- `load_word32` uses 32-bit loads.

Missing:

- deliberate `ALU32`/`ALU64` ping-pong,
- chains where a 32-bit op feeds a 64-bit op and vice versa,
- zero-extension-sensitive compare/store patterns.

Why it matters:

- Zero-extension handling is a common JIT sharp edge.
- The current suite is overwhelmingly `u64`-centric.

### C4. Many distinct branch targets are only weakly covered

Current partial coverage:

- `switch_dispatch` has many cases,
- `branch_dense` has many predicates.

Missing:

- wide dispatch with **distinct nontrivial case bodies**,
- sparse decision trees,
- and multiple merge points carrying different live values.

Why it matters:

- `switch_dispatch` mostly returns constants, which favors `cmov` lowering analysis but not broad branch-target layout analysis.

### C5. Large-constant materialization stress is missing

This overlaps with C2 but deserves separate emphasis:

- No benchmark deliberately floods the program with unique large constants.
- Existing constants are mostly reused or embedded in repeated templates.

Why it matters:

- Some backends are better at hoisting/reusing constant materialization than others.
- A dedicated stress case would reveal that directly.

### C6. Deeply nested conditionals are missing

Current state:

- `branch_dense` is flat.
- `bounds_*` benchmarks have repeated guards, but not a realistic nested decision tree.

Missing:

- 6-10 level nested conditionals,
- especially on packet or struct fields,
- with both hot and cold exits.

Why it matters:

- Deep nesting stresses code layout, branch inversion choices, spill behavior at joins, and path-length asymmetry.

### C7. Multi-function prologue/epilogue diversity is still under-tested

Current state:

- only `bpf_call_chain` touches local calls.

Missing:

- several subprograms with different live-register needs,
- fan-out call graphs,
- cold helper-like leaf functions versus hot arithmetic leaf functions.

Why it matters:

- The paper already identifies callee-saved register policy as a meaningful differentiator.
- One uniform 3-call chain is too weak to map that design space.

## D. Proposed New Benchmarks

### D1. Recommended benchmark set

| Name | Gap covered | Description and JIT pattern | Expected impact | Mode | Complexity |
| --- | --- | --- | --- | --- | --- |
| `packet_parse_vlans_tcpopts` | Variable-length parsing | Packet-backed parser for Ethernet + optional 0/1/2 VLAN tags + IPv4 + TCP data-offset walk. Exercises variable cursor advancement, repeated bounds checks, mixed 8/16/32-bit loads, and nested protocol branches. | Code size: medium-high. Exec time: medium-high. Likely larger divergence than current `packet_parse` because it adds variable offsets and more branch structure. | Pure-JIT, packet-backed | Medium |
| `packet_parse_ipv6_ext` | Variable-length parsing | IPv6 parser with extension-header loop (hop-by-hop, routing, fragment, dst options). Tests loop-carried packet cursor updates and many distinct protocol exits. | Code size: high. Exec time: medium-high. Good stress for branch layout and zero-extension around byte fields. | Pure-JIT, packet-backed | Medium-high |
| `map_lookup_hot_hash` | Map lookups | One hot hash-map lookup per iteration against a pre-populated map, followed by a small fixed compute block. Separates “lookup site + small follow-on work” from the current heavier runtime cases. | Code size: low-medium. Exec time: high relative to size because helper/runtime dominates. Valuable for modeling common per-event lookups. | Runtime-backed | Medium |
| `map_lookup_hot_lru` | Map lookups | Same structure as above, but with `BPF_MAP_TYPE_LRU_HASH` and configurable hit/miss mix. Useful because LRU behavior is common in flow caches and absent from the current suite. | Code size: low-medium. Exec time: high. More realistic than array/hash-only coverage. | Runtime-backed | Medium-high |
| `map_lookup_hot_percpu` | Map lookups | Per-CPU array/hash lookup followed by short arithmetic. Targets current-CPU slot selection and per-CPU pointer use without update traffic. | Code size: low-medium. Exec time: medium-high. Complements `percpu_map_update` by isolating read-side behavior. | Runtime-backed | Medium |
| `memcmp_prefix_64` | String/byte comparisons | Compare a 64-byte candidate against a constant pattern with three controlled scenarios: early mismatch, late mismatch, full match. Models filename/license/header signature tests. | Code size: low-medium. Exec time: highly data-dependent. Good for early-exit branching and byte-load lowering. | Pure-JIT, staged or packet-backed | Low |
| `local_call_fanout` | Richer BPF-to-BPF calls | Caller chooses among 4-8 `__noinline` subprograms based on parsed fields. Each callee has a different register-pressure profile. Tests call-site layout, prologue diversity, and join-point register allocation. | Code size: medium-high. Exec time: medium. Better representation of multi-function programs than a fixed chain. | Pure-JIT | Medium |
| `tail_call_pipeline_4` | Tail calls | A 4-stage prog-array pipeline (`parse -> classify -> account -> action`) with a controlled fall-through rate. Directly measures tail-call dispatch and stage-local codegen. | Code size: high across program set. Exec time: high. Strong real-world relevance for decomposed datapaths. | Runtime-backed, prog-array support | High |
| `packet_rss_hash` | Packet-data arithmetic | Parse a packet 5-tuple and compute a Toeplitz-like or Jenkins-style flow hash. Mixes endian conversion, rotates, shifts, and field extraction from packet memory. | Code size: medium. Exec time: medium. Likely more workload-realistic than standalone `checksum`. | Pure-JIT, packet-backed | Medium |
| `incremental_csum_diff` | Packet-data arithmetic | Read IPv4/TCP fields, mutate one field, and compute an incremental checksum update instead of full recomputation. Tests mixed 16/32-bit arithmetic, carry folding, and packet-field dependency chains. | Code size: medium. Exec time: medium. More representative of packet rewrite programs. | Pure-JIT, packet-backed | Medium |
| `ringbuf_event_submit` | Ring buffer / perf output | Read a handful of fields, fill a compact event struct, and emit it via `bpf_ringbuf_reserve/submit` or `bpf_ringbuf_output`. Tests helper ABI setup, stack writes, and event formatting. | Code size: medium. Exec time: high because helper cost dominates. Important tracing/control-plane motif. | Runtime-backed, ringbuf support | Medium-high |
| `perf_event_output_record` | Perf event output | Same idea as above but via `bpf_perf_event_output`, which remains common in older tracing code. Useful if ringbuf and perf-event paths diverge between runtimes. | Code size: medium. Exec time: high. | Runtime-backed, perf-event map support | Medium-high |
| `core_struct_walk_task_file` | BTF-based struct access | CO-RE/BTF benchmark that walks a small kernel object graph such as task -> mm/file/path-like fields and folds selected fields. Tests preserve-access-index lowering and pointer chasing. | Code size: medium-high. Exec time: medium-high. Large external-validity gain because current suite has zero CO-RE coverage. | Harness extension required | High |
| `kfunc_sock_ops_mix` | kfunc calls | Parse or obtain a BTF-backed object and make 1-3 kfunc calls around a small arithmetic block. Tests kfunc call lowering, BTF IDs, and mixed call-site pressure. | Code size: medium. Exec time: medium-high. Important for newer kernels. | Harness extension required | High |
| `atomic_counter_xadd` | Atomic ops | Atomically increment one or more counters in a map value using `lock_xadd`/`fetch_add`, then fold the observed values. Tests atomic lowering and memory-ordering visible instruction sequences. | Code size: low-medium. Exec time: medium-high. Fills a completely empty instruction-class gap. | Runtime-backed | Medium |
| `imm64_storm` | Dense immediates / large constants | Straight-line kernel with 64-128 distinct 64-bit immediates mixed into a reduction. Purpose-built for constant materialization stress. | Code size: high. Exec time: medium. Useful as a pure backend stressor, not a workload proxy. | Pure-JIT | Low |
| `alu32_64_pingpong` | Mixed 32/64 ops | Alternates `u32` and `u64` arithmetic, shifts, compares, and stores on the same live values. Explicitly targets zero-extension correctness and code quality. | Code size: medium. Exec time: medium. Good chance of revealing differences hidden by current `u64`-heavy suite. | Pure-JIT | Low-medium |
| `branch_fanout_32` | Many branch targets | 32-way sparse decision DAG where each arm performs nontrivial work and merges into a shared reduction. Stronger branch-layout stress than constant-return `switch_dispatch`. | Code size: high. Exec time: medium-high. | Pure-JIT | Medium |
| `deep_guard_tree_8` | Deep nesting | 8-level nested conditional parser/policy tree on packet or synthetic-record fields. Targets branch inversion, spill behavior, and hot/cold asymmetry. | Code size: high. Exec time: medium-high. | Pure-JIT, preferably packet-backed | Medium |
| `mega_basic_block_2048` | Very large basic blocks | A single acyclic straight-line block with many live temporaries and minimal control flow. Pure stress test for scheduling and register allocation. | Code size: very high. Exec time: medium. Best classified as a JIT stressor, not a realism benchmark. | Pure-JIT | Low-medium |

### D2. Best additions if only 5 can be built first

If the goal is to improve external validity fastest rather than to maximize synthetic stress coverage, the highest-value first wave is:

1. `packet_parse_vlans_tcpopts`
2. `memcmp_prefix_64`
3. `local_call_fanout`
4. `packet_rss_hash`
5. `atomic_counter_xadd`

Reason:

- Together they cover the most obvious missing real-world motifs while staying closer to the current harness than CO-RE, kfunc, or tail-call pipelines.
- They also reduce the current overconcentration in long scalar loops and cloned arithmetic blocks.

### D3. Best additions if the goal is backend-differentiating stress

If the goal is specifically to expose optimization differences between JITs, the first wave should instead be:

1. `imm64_storm`
2. `alu32_64_pingpong`
3. `branch_fanout_32`
4. `deep_guard_tree_8`
5. `mega_basic_block_2048`

Reason:

- These do not maximize realism, but they directly target backend decision points that the current suite only partially probes.

## Overall Assessment

The current pure-JIT suite is strong at three things:

- isolating scalar ALU and loop/codegen mechanisms,
- isolating the kernel’s byte-recompose weakness,
- and giving clear small-to-medium synthetic kernels for code-size and exec-time comparison.

Its main limitations are structural:

- too much staged batch-style input,
- too little true packet-context diversity,
- almost no coverage of tracing/security-era BPF features,
- and very limited call-graph realism relative to a corpus that is overwhelmingly multi-function.

The most important practical correction is not to delete the synthetic kernels. It is to relabel them honestly as mechanism probes, then add a second layer of realistic parser/string/call/output/atomic/BTF benchmarks so the suite stops over-extrapolating from one narrow corner of the BPF design space.
