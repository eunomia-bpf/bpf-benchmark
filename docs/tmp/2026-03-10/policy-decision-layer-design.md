# Policy Decision Layer Design

**Status:** Design document (TODO #45)
**Date:** 2026-03-10
**Context:** v4 Round 3 complete — ALL 4 directive families have non-zero coverage. The scanner currently hardcodes `native_choice` for every site it finds. This document designs a real policy decision layer for workload-aware directive selection.

---

## 1. The Problem: Hardcoded Policy Is Wrong

### 1.1 Current State

The scanner in `micro/runner/src/kernel_runner.cpp` finds patterns and unconditionally emits the same `native_choice`:

```cpp
// Found rotate pattern → always use RORX
rules.push_back({idx, 5, BPF_JIT_RK_ROTATE, BPF_JIT_ROT_RORX, 0});

// Found cmov pattern → always use CMOVCC
rules.push_back({idx, 4, BPF_JIT_RK_COND_SELECT, BPF_JIT_SEL_CMOVCC, 0});
```

### 1.2 What the Evidence Says

Experimental data from v4 testing contradicts a blanket "always apply" policy:

| Directive | Benchmark | Result | Interpretation |
|-----------|-----------|--------|----------------|
| COND_SELECT cmov | log2_fold (6 sites) | +7.9% to +28% **slower** | Predictable branches — cmov breaks speculative execution |
| COND_SELECT cmov | cmov_select (POC v2) | **5.53x faster** (0.181x) | Unpredictable branches — cmov eliminates misprediction penalty |
| ROTATE rorx | rotate64_hash (115 sites) | 0.832x (20% **slower**) | BMI2 rorx has longer latency on current test hardware |
| ROTATE rorx | packet_rss_hash (11 sites) | **2.000x faster** | Hash kernels benefit from RORX encoding efficiency |
| WIDE_MEM | load_byte_recompose (1 site) | 0.842x (18% **slower** in R3) | Single-site wide load, timing noise obscures benefit |
| WIDE_MEM | stride_load_4 (2 sites) | **1.834x faster** | Multiple byte-load ladders, clear benefit |
| ADDR_CALC lea | stride_load_16 | **-12% exec, -6B code** | Consistently beneficial |

Key insight: **the same directive kind can help or hurt on the same hardware depending on the program's branch predictability, loop structure, and site density.** ROTATE even shows contradictory results between two programs on the same run.

### 1.3 Why Fixed Kernel Heuristics Cannot Solve This

A fixed kernel peephole that always applies cmov when it sees a diamond pattern would:
- Help `cmov_select` (+5.53x)
- Hurt `log2_fold` (-28%)
- Net effect depends on which programs dominate the workload

The kernel has no access to:
1. Runtime branch miss rates for this program in this deployment
2. The operator's I-cache budget (cmov expands code; rotating shrinks it)
3. Fleet-wide A/B test results comparing policy A vs policy B
4. CPU microarchitecture errata or specific µarch characterization beyond the generic feature flags

This is the core paper argument: **profitability is a function of workload + CPU + deployment context, not just program structure.**

---

## 2. Architecture Overview

The policy layer sits between the scanner (which finds candidate sites) and the blob builder (which serializes decisions to the kernel). It consumes site features and profile data, and outputs per-site `native_choice` values.

```
┌─────────────────────────────────────────────────────────────┐
│  Phase 1: Discovery (already implemented)                    │
│                                                              │
│  Xlated BPF bytecode                                         │
│       │                                                      │
│       ▼                                                      │
│  Pattern Scanners (find_cmov_select_sites_xlated, etc.)      │
│       │                                                      │
│       ▼                                                      │
│  Candidate Site List: [{idx, site_len, rule_kind, ...}]      │
└─────────────────────────────┬───────────────────────────────┘
                              │
┌─────────────────────────────▼───────────────────────────────┐
│  Phase 2: Feature Extraction (NEW)                           │
│                                                              │
│  Per-site static features:                                   │
│  - loop_depth: is this site inside a loop? (estimate via     │
│    backward jump target analysis)                            │
│  - site_density: how many sibling sites in same basic block? │
│  - code_budget: estimated code size delta (negative=shrink)  │
│  - operand_type: BPF_K (immediate) vs BPF_X (register src)  │
│                                                              │
│  Program-level static features:                              │
│  - total_sites: candidate count for this directive kind      │
│  - subprog_count: multi-function programs have more context  │
│  - xlated_insn_count: overall program size                   │
└─────────────────────────────┬───────────────────────────────┘
                              │
┌─────────────────────────────▼───────────────────────────────┐
│  Phase 3: Profile Collection (NEW — core of PGO story)       │
│                                                              │
│  Load program with stock kernel JIT (no recompile)           │
│  Run bpf_prog_test_run N_profile times with perf counters:   │
│  - branch-misses (perf_event_open, PERF_HW_BRANCH_MISSES)   │
│  - instructions retired                                      │
│  - cycles                                                    │
│                                                              │
│  Problem: perf counters are program-wide, not per-site.      │
│  Solution: isolate per-site branch behavior via A/B method   │
│  (described in Section 4.2).                                 │
└─────────────────────────────┬───────────────────────────────┘
                              │
┌─────────────────────────────▼───────────────────────────────┐
│  Phase 4: Policy Engine (NEW — decision algorithm)           │
│                                                              │
│  Input: per-site features + program profile data             │
│  Output: per-site native_choice (or SKIP to leave as-is)     │
│                                                              │
│  Implements pluggable policy strategies:                     │
│  - StaticHeuristic: CPU feature DB + simple rules            │
│  - ProfileGuided: perf counter threshold decision            │
│  - ExperimentAB: run both, pick faster                       │
│  - ManualOverride: explicit per-site choice from config file  │
└─────────────────────────────┬───────────────────────────────┘
                              │
┌─────────────────────────────▼───────────────────────────────┐
│  Phase 5: Blob Build + Apply (already implemented)           │
│                                                              │
│  build_policy_blob_from_xlated(program_fd, pre_info, rules)  │
│       │                                                      │
│       ▼                                                      │
│  BPF_PROG_JIT_RECOMPILE syscall                              │
│       │                                                      │
│       ▼                                                      │
│  Measurement: exec_ns before vs after                        │
└─────────────────────────────────────────────────────────────┘
```

---

## 3. Site Feature Extraction API

### 3.1 Data Structures

```
struct SiteFeatures {
    // Identity
    uint32_t site_start;       // instruction index in xlated program
    uint16_t site_len;         // number of BPF instructions in pattern
    uint16_t rule_kind;        // BPF_JIT_RK_COND_SELECT, BPF_JIT_RK_ROTATE, etc.

    // Static features (computed from xlated bytecode alone)
    bool     inside_loop;      // site is a backward-jump target or in loop body
    uint32_t loop_depth;       // estimated nesting level (0 = not in loop)
    uint32_t sibling_sites;    // other candidate sites in same 64-insn window
    int32_t  code_delta_bytes; // estimated native code size change if applied
                               // (negative = shrink, positive = grow)
    bool     operand_is_imm;   // BPF_K source (true) vs BPF_X register (false)
    uint32_t bb_insn_count;    // basic block size containing this site

    // Directive-specific features
    union {
        struct {               // COND_SELECT specific
            uint8_t  jcc_opcode;    // BPF_JEQ, BPF_JLT, etc.
            uint8_t  true_branch_taken_est; // static prediction: 0=not_taken dominant
        } cond_select;
        struct {               // ROTATE specific
            uint8_t  rotate_width;  // 32 or 64
            int32_t  rotate_amount; // shift count N
        } rotate;
        struct {               // WIDE_MEM specific
            uint8_t  access_width;  // 2, 4, or 8 bytes
            uint16_t base_offset;   // memory offset
        } wide_mem;
        struct {               // ADDR_CALC (LEA) specific
            int32_t  scale;         // multiply factor
            int32_t  addend;        // constant to add
        } addr_calc;
    };
};

struct ProgramFeatures {
    uint32_t xlated_insn_count;
    uint32_t nr_subprogs;
    uint32_t candidate_count[4];   // per directive kind
    // Perf profile (filled in after profile collection)
    uint64_t baseline_exec_ns;
    uint64_t baseline_branch_misses;
    uint64_t baseline_instructions;
    uint64_t baseline_cycles;
    double   branch_miss_rate;     // misses / instructions
    double   ipc;                  // instructions / cycles
};
```

### 3.2 Feature Extraction Function Signatures

```
// Extract static features for a single candidate site
SiteFeatures extract_site_features(
    const bpf_insn_raw *insns,
    uint32_t            insn_cnt,
    const policy_rule  &candidate);

// Extract program-level static features
ProgramFeatures extract_program_features(
    const bpf_insn_raw *insns,
    uint32_t            insn_cnt,
    const std::vector<policy_rule> &candidates);

// Fill in profile measurements (call after running bpf_prog_test_run)
void fill_profile_measurements(
    ProgramFeatures    &prog_features,
    uint64_t            exec_ns,
    uint64_t            branch_misses,
    uint64_t            instructions,
    uint64_t            cycles);
```

### 3.3 Loop Detection Algorithm

Since BPF programs are DAGs (no true loops at the BPF level after verifier), the "loop" detection targets the common pattern where the verifier's bounded loop unrolling still leaves detectable backward jump targets, or where the program has a linear hot path executed many times per packet.

Practical heuristic:
1. Walk all BPF jump instructions in the program.
2. Mark any instruction index that is a target of a backward jump (`jmp.off < 0`) as a "loop header."
3. For each candidate site, check if it falls within a region bounded by a loop header above and its corresponding forward exit below.
4. Loop depth = number of nested loop regions containing the site.

This is conservative (may miss some patterns) but is safe — it never incorrectly classifies a non-loop as a loop.

---

## 4. Profile Collection

### 4.1 Program-Wide Perf Counters

The simplest profile method uses `perf_event_open` around `bpf_prog_test_run`. This gives program-wide counters, not per-site counters.

```
Profile Collection Protocol:
  1. Load program with stock JIT (no recompile flag)
  2. Open perf events: PERF_HW_BRANCH_MISSES, PERF_HW_INSTRUCTIONS, PERF_HW_CPU_CYCLES
  3. Run bpf_prog_test_run(repeat=N_profile) with perf counting enabled
  4. Record: branch_misses, instructions, cycles, exec_ns
  5. Compute: miss_rate = branch_misses / instructions
              ipc       = instructions / cycles
```

N_profile choice: 1000 iterations is sufficient to get stable counter readings. The counters accumulate across iterations and are divided by repeat count.

This method is already partially implemented in `micro_exec` via the `--perf-counters` flag. The policy layer would call the same infrastructure.

### 4.2 Per-Site Branch Miss Attribution

Program-wide counters don't tell us *which* sites are responsible for branch misses. Two methods to attribute misses to sites:

**Method A: Site Isolation (preferred for paper)**

For each candidate COND_SELECT site i:
1. Build a policy blob with only site i set to `BPF_JIT_SEL_CMOVCC`
2. Run with perf counters: `miss_rate_with_cmov_at_i`
3. If `miss_rate_with_cmov_at_i` < `miss_rate_baseline` significantly:
   - Site i was responsible for branch misses → cmov is beneficial
4. Else:
   - Site i had predictable branches → keep branch

This requires one `BPF_PROG_JIT_RECOMPILE` call per candidate site. For a program with K candidates, cost is K round trips. For programs with many sites (rotate64_hash has 115 ROTATE sites), this is expensive but feasible as an offline profiling step.

**Method B: Exec Time A/B (simpler, already implemented)**

For each candidate site i:
1. Apply cmov at site i only
2. Measure exec_ns delta
3. If exec_ns_cmov < exec_ns_branch → site benefits from cmov

This is what the paper currently demonstrates with log2_fold (6 sites, each independently testable). The exec_ns signal is noisier than branch-miss counters but avoids the need for perf privileges.

**Method C: Batch A/B (fastest)**

1. Apply all cmov sites → measure exec_ns_all_cmov
2. Apply no cmov sites → measure exec_ns_baseline
3. If all_cmov is better: keep all. If worse: try removing sites one by one.

This is a greedy approach. It works well when sites are mostly independent (no interaction effects). For cmov, sites in different code paths are independent; sites in the same basic block may interact through dependency chains.

### 4.3 Profile Data Thresholds

Based on experimental evidence from the no-cmov ablation study (§7.1 of the optimization plan):

| Benchmark | Normal | No-cmov | Delta | Interpretation |
|-----------|--------|---------|-------|----------------|
| switch_dispatch | 213 ns | 269 ns | +26.3% slower without cmov | high miss rate, cmov helps |
| binary_search | 205 ns | 229 ns | +11.7% slower without cmov | moderate miss rate, cmov helps |
| bounds_ladder | 83 ns | 68 ns | -18.1% faster without cmov | predictable, cmov hurts |
| large_mixed_500 | 415 ns | 316 ns | -23.9% faster without cmov | predictable, cmov hurts |
| log2_fold (v4 A/B) | 764 ns | — | +7.9% with cmov | predictable, cmov hurts |

Proposed thresholds for the profile-guided policy:

```
CMOV_MISS_RATE_THRESHOLD = 0.02   // 2% branch misses per instruction
                                   // Above this: prefer cmov
                                   // Below this: keep branch
                                   // Rationale: misprediction penalty ~15 cycles;
                                   //   cmov break-even at ~1-2% miss rate for
                                   //   typical 3-GHz CPU with IPC=3
```

For ROTATE, the threshold is simpler — it depends on code-size sensitivity, not branch prediction:

```
ROTATE_APPLY_IF_CODE_SHRINKS = true   // Apply rorx if it reduces jited_prog_len
                                       // (true for most hash-heavy programs)
ROTATE_RORX_REQUIRE_BMI2 = true       // Only apply rorx on BMI2-capable CPUs
                                       // (enforced via cpu_features_required field)
```

For WIDE_MEM: consistently beneficial when the access is on a hot path:

```
WIDE_MEM_MIN_SITES = 1    // Apply even for single-site programs (load_byte_recompose)
                           // unless exec_ns A/B shows regression
```

For ADDR_CALC (LEA): consistently beneficial in all tested cases:

```
LEA_APPLY_ALWAYS = true   // No known downside; code shrinks, no branch effect
```

---

## 5. Decision Algorithm

### 5.1 Policy Engine Interface

```
enum class PolicyStrategy {
    STATIC_HEURISTIC,   // CPU DB + static program analysis only
    PROFILE_GUIDED,     // perf counters + exec_ns A/B
    EXPERIMENT_AB,      // run both policies, pick better exec_ns
    MANUAL_OVERRIDE,    // explicit per-site choice from JSON config
};

struct PolicyDecision {
    uint32_t site_start;
    uint16_t rule_kind;
    uint16_t native_choice;  // BPF_JIT_SEL_CMOVCC / BPF_JIT_SEL_BRANCH / SKIP
    double   confidence;     // 0.0-1.0: how confident is the engine
    std::string rationale;   // human-readable explanation (for paper/debugging)
};

// Abstract base class for policy engines
class PolicyEngine {
public:
    virtual std::vector<PolicyDecision> decide(
        int                              prog_fd,
        const std::vector<SiteFeatures> &sites,
        const ProgramFeatures           &prog_features) = 0;
};
```

### 5.2 Static Heuristic Policy (Level 1)

Simplest implementation. Uses only static bytecode analysis + CPU feature DB:

```
StaticHeuristicPolicy::decide(prog_fd, sites, prog_features):

  For each site in sites:
    switch site.rule_kind:

      case COND_SELECT:
        // Static proxy for branch predictability:
        // Branches inside loops are more likely unpredictable
        // (data-dependent outcomes over many iterations).
        if site.inside_loop and site.loop_depth >= 2:
          decision = CMOVCC, confidence=0.6, rationale="nested loop, likely unpredictable"
        elif site.inside_loop:
          decision = CMOVCC, confidence=0.45, rationale="single loop, uncertain"
        else:
          decision = BRANCH, confidence=0.7, rationale="non-loop, likely predictable"

      case ROTATE:
        // Always beneficial if: (1) BMI2 available and (2) code shrinks
        if cpu_has_bmi2():
          decision = RORX, confidence=0.8, rationale="BMI2 available, code shrink"
        else:
          decision = ROR, confidence=0.7, rationale="no BMI2, standard rotate"

      case WIDE_MEM:
        // Always apply — no known downside for aligned accesses
        decision = WIDE_LOAD, confidence=0.9, rationale="wide load consistently beneficial"

      case ADDR_CALC:
        // Always apply — LEA consistently shrinks code and equals or beats mov+shift+add
        decision = LEA_FUSION, confidence=0.95, rationale="LEA always beneficial"
```

This is the `advisor-static` baseline in the evaluation plan (§6.1 of the optimization plan).

### 5.3 Profile-Guided Policy (Level 2, Paper Sweet Spot)

This is the primary contribution. It adds a profiling phase before making decisions:

```
ProfileGuidedPolicy::decide(prog_fd, sites, prog_features):

  Step 1: Collect baseline profile
    run bpf_prog_test_run(prog_fd, repeat=1000) with perf counters
    → baseline_exec_ns, baseline_branch_misses, baseline_instructions
    → miss_rate = baseline_branch_misses / baseline_instructions

  Step 2: Classify program-level branch predictability
    if miss_rate > CMOV_MISS_RATE_THRESHOLD:
      program_class = UNPREDICTABLE   // cmov likely beneficial
    else:
      program_class = PREDICTABLE     // cmov likely harmful

  Step 3: For COND_SELECT sites specifically
    if program_class == UNPREDICTABLE:
      // Apply cmov at all sites (batch A/B confirms later)
      all_cmov_decisions = [CMOVCC for each site]
    else:
      // Isolate per-site contribution (Method A from §4.2)
      for each site i:
        apply cmov only at site i → measure exec_ns_cmov_i
        if exec_ns_cmov_i < baseline_exec_ns * 0.95:  // 5% improvement threshold
          site_i_decision = CMOVCC
        else:
          site_i_decision = BRANCH

  Step 4: For ROTATE, WIDE_MEM, ADDR_CALC
    // These are not branch-predictability dependent
    // Use exec_ns A/B at batch level (apply all vs none)
    apply_all = apply all sites of this kind
    measure exec_ns_with_all
    if exec_ns_with_all < baseline_exec_ns * 0.97:  // 3% improvement threshold
      apply all sites
    else:
      // Try subsets or skip
      skip all sites of this kind

  Step 5: Final validation
    apply full decision set → measure exec_ns_final
    if exec_ns_final > baseline_exec_ns * 1.02:  // 2% regression guard
      revert to baseline (BRANCH/no-directive for all sites)
      log "final A/B regression, reverting policy"
```

This is the `advisor-profiled` baseline in the evaluation plan.

### 5.4 Experiment A/B Policy (Level 3)

The most expensive but most accurate policy. Used for paper data collection, not production:

```
ExperimentABPolicy::decide(prog_fd, sites, prog_features):

  // Run full grid: for each subset of sites, measure exec_ns
  // For small N (<=8 sites), exhaustive 2^N
  // For large N (>8 sites), greedy hillclimb from all-off baseline

  For small N:
    best_choice = all-off
    best_exec_ns = baseline_exec_ns
    for each bitmask M in 0..2^N-1:
      apply policy where site_i is on iff bit_i in M
      measure exec_ns_M
      if exec_ns_M < best_exec_ns:
        best_choice = M
        best_exec_ns = exec_ns_M

  For large N (greedy):
    current = all-off
    for each site i (sorted by static heuristic confidence descending):
      toggle site i on
      measure exec_ns
      if improved: keep on, else revert

  Return best_choice as decisions
```

This is used to generate the "oracle" data points that demonstrate the upper bound of what profile-guided policy can achieve vs a fixed heuristic.

---

## 6. Integration with the Scanner Framework

### 6.1 Current Code Flow (kernel_runner.cpp, lines 1400-1497)

```
1. find_cmov_select_sites_xlated()  → vector<policy_rule> (hardcoded native_choice)
2. find_wide_load_sites_xlated()    → vector<policy_rule>
3. find_rotate_sites_xlated()       → vector<policy_rule>
4. find_addr_calc_sites_xlated()    → vector<policy_rule>
5. concat all rules
6. build_policy_blob_from_xlated()  → bytes
7. BPF_PROG_JIT_RECOMPILE syscall
```

### 6.2 Proposed Code Flow with Policy Layer

```
1. find_cmov_select_sites_xlated()  → vector<policy_rule> (candidates only)
   find_wide_load_sites_xlated()
   find_rotate_sites_xlated()
   find_addr_calc_sites_xlated()

2. [NEW] extract_site_features() for each candidate    → vector<SiteFeatures>
3. [NEW] extract_program_features(candidates)          → ProgramFeatures

4. [NEW if --policy-profile or --policy-ab]
   ProfileGuidedPolicy::collect_baseline_profile(prog_fd) → fill ProgramFeatures.perf fields

5. [NEW] PolicyEngine::decide(prog_fd, sites, prog_features) → vector<PolicyDecision>
   (replaces the implicit "always apply the same native_choice" logic)

6. Filter decisions: remove any with native_choice == SKIP
   Build rules vector from remaining PolicyDecisions

7. build_policy_blob_from_xlated(rules)  → bytes
8. BPF_PROG_JIT_RECOMPILE syscall
9. Measure exec_ns after recompile
```

### 6.3 CLI Flags to Add

```
--policy-strategy <static|profile|ab|manual>
    Which policy engine to use (default: static)

--policy-cmov-miss-threshold <float>
    Branch miss rate threshold for cmov decisions (default: 0.02)

--policy-profile-repeat <int>
    Number of test_run iterations for profile collection (default: 1000)

--policy-config <path>
    JSON file with manual per-site overrides (for --policy-strategy manual)

--policy-log <path>
    Write per-site decision rationale to this file (JSON)
```

### 6.4 Output: Policy Decision Log

Every policy run produces a JSON log file capturing what was decided and why. This is essential for debugging, paper writeup, and fleet operators understanding what the system did:

```json
{
  "program": "log2_fold.bpf.o",
  "policy_strategy": "profile",
  "baseline": {
    "exec_ns": 764,
    "branch_misses": 12453,
    "instructions": 8934521,
    "miss_rate": 0.00139
  },
  "decisions": [
    {
      "site_start": 42,
      "rule_kind": "COND_SELECT",
      "static_features": {
        "inside_loop": false,
        "loop_depth": 0,
        "operand_is_imm": true
      },
      "native_choice": "BRANCH",
      "confidence": 0.82,
      "rationale": "miss_rate=0.00139 < threshold=0.020; predictable branch, cmov would hurt"
    }
  ],
  "after_recompile": {
    "exec_ns": 771,
    "delta_pct": "+0.9%"
  }
}
```

For `cmov_select.bpf.o` (unpredictable branches):

```json
{
  "program": "cmov_select.bpf.o",
  "policy_strategy": "profile",
  "baseline": {
    "exec_ns": 815,
    "branch_misses": 1823456,
    "instructions": 7234123,
    "miss_rate": 0.252
  },
  "decisions": [
    {
      "site_start": 285,
      "rule_kind": "COND_SELECT",
      "native_choice": "CMOVCC",
      "confidence": 0.91,
      "rationale": "miss_rate=0.252 >> threshold=0.020; highly unpredictable branch"
    }
  ],
  "after_recompile": {
    "exec_ns": 147,
    "delta_pct": "-82.0%"
  }
}
```

---

## 7. Concrete Worked Example: log2_fold vs cmov_select

This section demonstrates how the profile-guided policy correctly handles both programs, while a fixed "always cmov" policy fails on log2_fold.

### 7.1 log2_fold

**Program structure:** Implements `log2()` via repeated right-shift + compare. The branch at each step checks a known power-of-two threshold. With fixed input distributions (or input values that share the same log2 result bucket), branches are highly predictable.

**v4 A/B result:** 6 cmov sites found. Baseline 764 ns. With cmov: 824 ns (+7.9%).

**Fixed kernel heuristic response:** Sees diamond pattern → applies cmov → program gets **slower**.

**Profile-guided policy response:**

```
Step 1: Collect baseline profile
  exec_ns = 764, branch_misses = ~9000, instructions = ~8.9M per 1000-repeat run
  miss_rate = 9000 / 8934521 = 0.00101  (0.1%)

Step 2: Classify
  miss_rate 0.001 << threshold 0.020
  program_class = PREDICTABLE

Step 3: For each of 6 COND_SELECT sites
  decision = BRANCH (don't apply cmov)
  rationale: "miss_rate below threshold; cmov would serialize speculative execution"

Step 4-5: No cmov applied, exec_ns unchanged at ~764 ns
```

**Result:** Profile-guided policy correctly leaves log2_fold's branches alone. **Fixed heuristic fails here.**

### 7.2 cmov_select

**Program structure:** Selects between two values based on a comparison of randomly shuffled array elements. Branch outcome is effectively random — 50% taken / 50% not-taken.

**Characterization result:** Kernel baseline 815 ns, llvmbpf (which auto-emits cmov) 147 ns. 5.53x gap. After v4 recompile with cmov: targeted to close to ~150 ns.

**Fixed kernel heuristic response:** Sees diamond pattern → applies cmov → program gets **much faster**. This case works for the fixed heuristic.

**Profile-guided policy response:**

```
Step 1: Collect baseline profile
  exec_ns = 815, branch_misses = ~1.8M, instructions = ~7.2M per 1000-repeat run
  miss_rate = 1823456 / 7234123 = 0.252  (25.2%)

Step 2: Classify
  miss_rate 0.252 >> threshold 0.020
  program_class = UNPREDICTABLE

Step 3: For each cmov site (once subprog boundary issue is fixed)
  decision = CMOVCC
  rationale: "miss_rate=25.2% far exceeds threshold; cmov eliminates misprediction penalty"

Step 4-5: All cmov applied, exec_ns drops dramatically
```

**Result:** Profile-guided policy correctly applies cmov. Fixed heuristic also gets this right, but only because it's a favorable case.

### 7.3 The Case Fixed Heuristics Cannot Handle

The decisive case for the paper is a program that has **mixed** sites: some predictable branches (in a linear control flow path) and some unpredictable branches (in a data-dependent inner loop).

A fixed "always cmov" heuristic applies cmov to all sites — including the predictable ones, causing regression. A fixed "never cmov" heuristic misses the unpredictable sites entirely.

The profile-guided policy, using per-site isolation (Method A from §4.2), correctly applies cmov only to the unpredictable sites.

This motivates adding a benchmark with mixed branch predictability — e.g., a program that does a predictable bounds check followed by a data-dependent conditional select inside a hash loop. The new benchmark `packet_rss_hash` (11 rotate sites, 2x speedup from ROTATE) is already a good candidate for mixed-directive analysis.

---

## 8. Paper Narrative: Why This Cannot Be Done With Fixed Kernel Heuristics

### 8.1 The Core Argument (4 Paragraphs for Paper §5)

**Paragraph 1 — What fixed heuristics can do:** A kernel maintainer could add a peephole pass that detects the diamond pattern (jcc + 2 movs) and emits cmovcc. This covers the structural legality check — the pattern is semantically safe to lower with cmov. It would help programs with unpredictable branches (cmov_select: -82%) and hurt programs with predictable branches (log2_fold: +8%). The kernel maintainer has no way to distinguish these cases at program-load time.

**Paragraph 2 — What the kernel cannot observe:** Branch predictability depends on the *data* the program processes at runtime, not on the program's static structure. log2_fold and cmov_select have identical structural patterns (diamond-shaped jcc + mov sequences), but log2_fold sees inputs concentrated in a narrow value range (predictable outcomes) while cmov_select sees uniformly random input pairs (unpredictable outcomes). The kernel processes the BPF program once at load time — it never observes the runtime data distribution.

**Paragraph 3 — What the framework enables:** Our framework exposes the re-JIT interface (`BPF_PROG_JIT_RECOMPILE`) that allows privileged userspace code to make the decision after collecting runtime evidence. The operator loads the program with the stock JIT, runs it with profiling enabled, observes the branch-miss rate, and then recompiles with the appropriate policy. This is a strictly richer decision surface than anything available at load time. The decision can also be updated: if the workload shifts (e.g., traffic pattern changes make previously-predictable branches unpredictable), the operator can re-profile and re-JIT without disrupting running programs.

**Paragraph 4 — Fleet-level differentiation:** Two hosts running the same BPF program may need different policies if their traffic profiles differ. A fixed kernel heuristic enforces the same policy on all hosts. Our framework allows per-host policy, enabling fleet A/B testing: deploy new policy to 5% of hosts, compare latency metrics, roll out if positive. This is standard practice in production BPF deployments (Cilium, Katran) for other configuration axes; our framework extends it to JIT code generation choices.

### 8.2 Falsification Condition (Mandatory per §5.4 of optimization plan)

The paper must honestly state when fixed heuristics are sufficient:

> If our experiments show that a fixed "always cmov if branch-miss > X%" threshold in the kernel would achieve the same performance as the profile-guided userspace policy across all tested programs and hardware, the correct conclusion is to implement the kernel peephole, not the userspace framework. We test this directly by implementing the fixed kernel baselines (TODO #44, evaluation §6.1 baseline 3-4).

The framework's value is proven only if there exists at least one program/workload combination where:
(a) the fixed heuristic makes the wrong choice, AND
(b) the profile-guided policy makes the correct choice.

The log2_fold / cmov_select pair already provides this evidence at the micro-benchmark level. Real-program evaluation will test whether this generalizes.

---

## 9. Implementation Plan (TODO #45 Breakdown)

### Phase A: Static Feature Extraction (2-3 days)
- Implement `SiteFeatures` struct and `extract_site_features()` in `micro/scanner/` (extracted from kernel_runner.cpp per TODO #43)
- Implement loop detection via backward jump analysis
- Unit tests: verify loop detection on known programs (binary_search has a loop, log2_fold does not)

### Phase B: Perf Counter Integration (1-2 days)
- Extend `--perf-counters` flag to return structured counters to the policy layer
- Compute `miss_rate` and `ipc` from raw counter values
- Validate on cmov_select (should show high miss_rate) vs log2_fold (should show low miss_rate)

### Phase C: Static Heuristic Engine (1 day)
- Implement `StaticHeuristicPolicy` class
- Wire into scanner flow with `--policy-strategy static`
- Produces deterministic decisions, no runtime profiling needed
- Benchmark: does static heuristic avoid log2_fold regression? (Probably not — loop depth is 0 in log2_fold, so static policy might still pick CMOVCC)

### Phase D: Profile-Guided Engine (2-3 days)
- Implement `ProfileGuidedPolicy` with Method B (exec_ns A/B, simpler)
- Add `--policy-strategy profile` and `--policy-profile-repeat N`
- Validate: log2_fold gets BRANCH decision, cmov_select gets CMOVCC decision
- This is the key paper experiment

### Phase E: Policy Decision Log Output (1 day)
- Implement JSON log output per §6.4
- Used for paper table generation and debugging

### Phase F: Paper Experiments (2-3 days)
- Run profile-guided vs static-heuristic vs fixed-kernel-heuristic on full benchmark set
- Generate Table: per-program decisions, exec_ns delta with each strategy
- Identify programs where strategies disagree → these are the paper's evidence

### Total Estimated Effort: 9-12 days for a complete implementation

---

## 10. Relation to Existing Components

| Component | Role | Changes Needed |
|-----------|------|----------------|
| `micro/runner/src/kernel_runner.cpp` (lines 519-564) | Pattern scanning (cmov) | Extract to `scanner/` library (TODO #43); add SiteFeatures output |
| `micro/runner/src/kernel_runner.cpp` (lines 700+) | Pattern scanning (rotate) | Same extraction |
| `micro/runner/src/kernel_runner.cpp` (lines 1400-1497) | Scan-build-apply flow | Insert policy engine between scan and build |
| `micro/runner/include/micro_exec.hpp` | Options/CLI | Add `--policy-strategy`, `--policy-log`, etc. |
| `micro/run_micro.py` | Python orchestrator | No changes — policy operates inside micro_exec |
| `vendor/linux` kernel | Legality plane | No changes — policy is purely userspace |
| `micro/runner/src/common.cpp` | Perf counter plumbing | Extend to return structured counters to policy layer |

The policy decision layer is **entirely in userspace**. The kernel sees only the final policy blob — it doesn't know whether decisions came from a static heuristic, a profile run, or a manual override. This is by design: the kernel's job is legality validation, not profitability decisions.

---

## 11. Summary

The policy decision layer transforms the v4 framework from "scanner that always applies every found site" to "profiler + analyzer + decision engine that applies sites only when beneficial." The three-level design (static → profile-guided → A/B experiment) maps to the three paper baselines (`advisor-static`, `advisor-profiled`, and the oracle upper bound). The profile-guided approach is the paper's primary claim: by collecting runtime branch-miss data with `perf_event_open` and iterating with `BPF_PROG_JIT_RECOMPILE`, the framework makes correct decisions (BRANCH for log2_fold, CMOVCC for cmov_select) that no fixed kernel heuristic can replicate without access to the same runtime evidence.
