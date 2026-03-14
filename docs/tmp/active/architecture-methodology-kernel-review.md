# BpfReJIT Architecture, Methodology, and Kernel Code Review

**Date**: 2026-03-13
**Reviewer**: Claude (deep review)
**Scope**: (1) engineering decoupling, (2) benchmark methodology, (3) kernel code quality

---

## Part 1: Architecture Decoupling Review

### 1.1 Scanner Enumerate -- Verified Working

Ran `sudo scanner/build/bpf-jit-scanner enumerate` on the live host. It correctly:
- Iterates all BPF programs via `BPF_PROG_GET_NEXT_ID`
- Opens fd via `bpf_prog_get_fd_by_id()` internally (no caller-held fd needed)
- Reports per-program site breakdown with family/pattern_kind detail
- Outputs both human-readable and `--json` formats

197 live programs were scanned on the host, including Tracee kprobes/tracepoints
and XDP syncookie programs. The scanner correctly identified cmov, extract,
endian, branch-flip, wide, and rotate sites across all program types.

**Verdict: Enumerate path is fully functional and decoupled from application loading.**

### 1.2 E2E Pipeline: .bpf.o Dependencies

The E2E pipeline has TWO modes:

**Mode A -- Enumerate path (primary, `_USE_ENUMERATE_PATH = True`)**:
- `scan_programs()` calls `_enumerate_scan_one()` which invokes
  `scanner enumerate --prog-id <id> --json`
- `apply_recompile()` calls `_apply_one_enumerate()` which invokes
  `scanner enumerate --prog-id <id> --recompile --json`
- Neither path requires a `.bpf.o` file
- The fd is opened internally by the scanner via `bpf_prog_get_fd_by_id()`

**Mode B -- Legacy fallback (when enumerate fails)**:
- Falls back to `scan --prog-fd` / `apply --prog-fd`
- Requires caller to open a prog fd via `_prog_fd_by_id()` or `/proc` scanning
- Still does NOT require a `.bpf.o` file for scanning/recompiling

**Where .bpf.o IS still used**:
1. **Policy resolution** (`resolve_policy_files()`): Uses `object_path` to locate
   `.policy.yaml` files via naming convention (`tracee.bpf.o` -> `tracee.bpf.o.policy.yaml`).
   This is a policy file lookup, not a BPF program loading dependency.
2. **Manual fallback** in Tracee E2E (`run_manual_fallback()`): When the Tracee daemon
   is unavailable, the harness manually loads programs from `tracee.bpf.o` via libbpf.
   This is a test infrastructure fallback, not an architectural coupling.
3. **Corpus compile-and-load**: The macro corpus pipeline compiles `.bpf.c` -> `.bpf.o`
   then loads via `micro_exec run-kernel`. This is the corpus benchmark path, which
   necessarily needs object files.

### 1.3 Assessment: Decoupling Grade

| Component | Decoupled? | Notes |
|-----------|-----------|-------|
| Scanner enumerate (scan) | YES | No .bpf.o, no app modification needed |
| Scanner enumerate (recompile) | YES | Direct kernel syscall via prog_id |
| E2E Tracee (with daemon) | YES | Scanner uses prog_ids from live progs |
| E2E Tracee (manual fallback) | PARTIAL | Needs .bpf.o for manual load |
| Policy resolution | SOFT COUPLING | Uses .bpf.o path for naming convention |
| Corpus pipeline | BY DESIGN | Needs .bpf.o (it IS the test artifact) |

**Finding 1.3a (Minor)**: The `PolicyTarget` dataclass still has `object_path` as an
optional field, and `resolve_policy_files()` uses it for policy file lookup. This is
acceptable since it is the *policy naming convention*, not a functional dependency.
The enumerate recompile path works with `--policy-dir` which is independent of object
paths.

**Finding 1.3b (Good)**: The `_USE_ENUMERATE_PATH = True` flag in `recompile.py` is
well-designed. All fallbacks to legacy scan/apply paths are graceful degradation, not
silent behavioral changes.

**Overall Decoupling Verdict: GOOD.** The three-component model (A: unmodified app,
B: independent scanner/CLI, C: kernel recompile) is correctly implemented. The scanner
enumerate path fully operates on live programs without any application modification
or object file dependency.

---

## Part 2: Benchmark Methodology Review

### 2.1 Micro Benchmark Measurement

**Warmup**: Configurable via `--warmups` (default from suite YAML). Warmup samples are
run but discarded. This is correct.

**Iterations**: Each iteration produces one sample per runtime. The number of iterations
controls the number of data points for statistics.

**Repeat**: The `--repeat` parameter controls the inner loop count inside `micro_exec`.
Each sample measures `repeat` executions and reports the total time. This amortizes
per-invocation overhead.

**Counterbalanced Design**: For 2 runtimes, the order alternates per iteration
(A,B on even iterations; B,A on odd). For >2 runtimes, seeded shuffle is used.
This is a standard counterbalancing technique that controls for order effects
(cache warming, thermal throttling).

**Statistics**: `ns_summary()` computes count, mean, median, min, max, p95, stdev.
Uses Python `statistics.median` and `statistics.stdev`. This is adequate for
descriptive statistics.

**Finding 2.1a (Missing): No confidence intervals or statistical tests.**
The benchmark reports descriptive statistics (median, stdev) but does not compute:
- Confidence intervals (e.g., 95% CI via bootstrap)
- Statistical significance tests (e.g., Wilcoxon signed-rank for paired comparisons)
- Effect size estimates

The `generate_figures.py` file does import `scipy.stats.wilcoxon` and has
`BOOTSTRAP_ITERATIONS = 10_000`, so this analysis exists in the figure generation
pipeline, not in the core measurement. This is acceptable -- statistical tests
belong in post-processing, not in the runner.

**Finding 2.1b (Good): CPU pinning and environment recording.**
- `--cpu` flag pins child processes via `taskset -c`
- CPU governor and turbo state are recorded in output JSON
- `validate_publication_environment()` exists for strict mode
- VM detection is performed (bare-metal vs VM)

**Finding 2.1c (Missing): No automated governor/turbo control.**
The micro runner records governor/turbo state but does not set them. The rigorous
framework VM runner (`_driver_impl_run_rigorous_framework_vm.py`) does have
`disable_turbo` and `turbo_snapshot` support. This is the correct division:
the rigorous path controls the environment, while the basic runner just records it.

### 2.2 Corpus Measurement Methodology

The macro corpus uses `micro_exec run-kernel` with `bpf_prog_test_run_opts`.
This measures **exec_ns** (kernel-reported BPF execution time), which is the
correct metric for JIT quality evaluation since it excludes syscall/context-switch
overhead.

**Finding 2.2a (Known Issue): Dummy packet / early exit.**
The memory notes state "corpus exec geomean 0.875x was confirmed invalid due to
dummy packet causing early-exit." The corpus pipeline uses
`materialize_dummy_packet()` which generates a fixed binary packet. If BPF programs
bail out early because the packet does not match expected protocol headers, the
measured execution time reflects only the guard check, not the optimized hot path.
This is a known issue with a fix pending.

### 2.3 E2E Methodology

**Architecture**: The E2E tracee case is a genuine end-to-end measurement:
1. Start Tracee daemon (or manually load BPF programs)
2. Run baseline workload (exec_storm, file_io, network, scheduler)
3. Measure app throughput (ops/s), BPF run_time_ns, agent CPU, system CPU
4. Apply recompile via scanner enumerate
5. Re-run same workloads with identical parameters
6. Compare before/after

**Finding 2.3a (Good): True app-level metric.**
The E2E pipeline measures `ops_per_sec` from `stress-ng`, `fio`, or `wrk` --
these are genuine application-level throughput metrics, not just BPF ns. The
`sample_bpf_stats()` function uses `bpf_prog_get_info_by_fd()` to read kernel
`run_time_ns` and `run_cnt`, providing both application-level and BPF-level metrics.

**Finding 2.3b (Concern): No repeated trials in E2E.**
The E2E pipeline runs each workload once per phase (baseline and post-recompile).
There is no repeated measurement or confidence interval. For a paper result, this
needs at minimum 3-5 repeated trials with variance reporting.

**Finding 2.3c (Good): Same-boot comparison.**
Baseline and post-recompile measurements happen within the same VM boot / process
lifetime, which controls for boot-to-boot variance. The `enable_bpf_stats()` context
manager correctly enables kernel BPF stats accounting for the measurement window.

**Finding 2.3d (Good): BPF stats delta computation.**
`compute_delta()` correctly computes per-program run_cnt and run_time_ns deltas,
deriving avg_ns_per_run. This is the right approach for isolating BPF overhead.

### 2.4 Methodology Summary

| Aspect | Micro | Corpus | E2E |
|--------|-------|--------|-----|
| Warmup | YES | YES (via iterations) | NO (should add) |
| Repeat/inner loop | YES | YES | N/A (wall clock) |
| Counterbalanced order | YES | YES | N/A (sequential) |
| CPU pinning | YES (optional) | YES (in VM) | NO |
| Paired comparison | YES (same boot) | YES (same boot) | YES (same boot) |
| Repeated trials | YES (N iterations) | YES (N iterations) | NO (single) |
| Statistical tests | In post-processing | In post-processing | NONE |
| App-level metric | N/A (BPF ns) | N/A (BPF ns) | YES (ops/s) |

---

## Part 3: Kernel Code Quality Review

### 3.1 emit_canonical_select (CMOV)

**Code path**: `bpf_jit_comp.c:1544`

Handles three site shapes:
- `site_len=2`: guarded update (jcc +1, mov) -> `emit_bpf_cmov_guarded_update()`
- `site_len=4`: diamond (jcc+2, mov, ja+1, mov) -> `emit_bpf_cmov_select()`
- `site_len=3`: compact (mov, jcc+1, mov) -> `emit_bpf_cmov_select_compact()`
- Larger: returns `-EOPNOTSUPP` (fall through to stock emission)

**Quality**: Good. The guarded update path (`emit_bpf_cmov_guarded_update()`) has
careful validation:
- Verifies jump width matches update width (JMP vs JMP32)
- Handles self-assign noop (bpf_mov_is_noop)
- Handles src==dst noop (cmov_src_reg == dst_reg)
- For BPF_K source, uses AUX_REG to materialize the immediate without clobbering flags

**Finding 3.1a (Correctness): Width mismatch guard is correct.**
Lines 1505-1508 ensure that 64-bit jumps only pair with 64-bit moves and
32-bit jumps with 32-bit moves. This prevents silent data corruption.

### 3.2 emit_canonical_rotate (RORX)

**Code path**: `bpf_jit_comp.c:2408`

Two native choices:
- `BPF_JIT_ROT_RORX`: VEX-encoded RORX (requires BMI2)
- `BPF_JIT_ROT_ROR`: Standard ROR with optional MOV prefix

**Quality**: Good. The RORX encoding manually constructs the VEX prefix:
- byte2 handles R/X/B bits correctly with is_ereg() checks
- byte3 handles W bit (64-bit) correctly
- The `ror_imm` computation `width - rot_amount` is correct for converting
  left-rotate-amount to right-rotate-amount

**Finding 3.2a (Good): CPU feature guard.**
`boot_cpu_has(X86_FEATURE_BMI2)` is checked before emitting RORX. Falls back
to ROR if BMI2 is unavailable.

### 3.3 emit_canonical_endian_fusion (MOVBE)

**Code path**: `bpf_jit_comp.c:2760`

Emits MOVBE for byte-swapping load/store operations.

**Quality**: Good. Parameter validation is thorough:
- Checks all 5 parameters are correct types
- Validates width is 16/32/64
- Validates direction is LOAD_SWAP or SWAP_STORE
- CPU feature check: `boot_cpu_has(X86_FEATURE_MOVBE)`

The `emit_movbe_load()` and `emit_movbe_store()` emit correct `0F 38 F0`/`F1`
opcodes with proper 66h prefix for 16-bit and REX.W for 64-bit.

### 3.4 emit_bitfield_extract_core (BEXTR)

**Code path**: `bpf_jit_comp.c:3354`

**Finding 3.4a (FIXED): BEXTR without-copy guard is present.**
Lines 3388-3389 check `src_reg != dst_reg` before using BEXTR. The comment at
lines 3384-3386 explains the rationale: for without-copy sites (src==dst), BEXTR
would expand 2 instructions (SHR+AND, 6B) to 2 instructions (MOV_imm32+BEXTR, 9B),
wasting 3B per site. This guard was the subject of a recent fix (commit daca445b1).

**Quality**: Good. The function handles multiple cases correctly:
- Trivial case: no shift and full mask -> just MOV (or nothing if src==dst)
- Zero mask -> emit immediate 0
- BEXTR path: with BMI1, contiguous low-bit field, src!=dst
- Fallback: SHR+AND (shift-first or mask-first based on `mask_first` parameter)

### 3.5 Recompile Flow (jit_directives.c)

**Syscall handler**: `bpf_prog_jit_recompile()` at line 3514.

**Security checks**:
- `CAP_BPF || CAP_SYS_ADMIN` required (line 3539)
- Policy blob delivered via sealed memfd (write/grow/shrink sealed, line 476)
- Blinded programs rejected (line 3600) -- POC limitation, correctly documented

**Concurrency**:
- `mutex_trylock(&main_aux->jit_recompile_mutex)` prevents concurrent recompile
  on the same program (line 3547)
- Returns `-EBUSY` on contention rather than blocking (fail-fast)

**RCU Safety**:
- `smp_store_release(&prog->bpf_func, ...)` at line 3454 ensures the new function
  pointer is visible to all CPUs before the old image is freed
- `synchronize_rcu()` at line 3459 waits for all in-flight BPF program executions
  to complete before freeing old images
- Old binary headers freed AFTER `synchronize_rcu()` (lines 3474-3476)
- Old priv stacks freed AFTER `synchronize_rcu()` (lines 3477-3478)

**Finding 3.5a (Good): Fail-closed design.**
On any error during re-JIT:
1. All image programs are aborted (`bpf_jit_recompile_abort()`)
2. Shadow ksyms are deleted
3. Rollback state is restored if `BPF_F_RECOMPILE_ROLLBACK` was set
4. If not rollback, the pre-recompile image is still restored
5. Failed policy is freed; old policy may be restored

The `out_abort` path (line 3499) correctly cleans up shadow ksyms and
aborts all staged images.

**Finding 3.5b (Good): No-op detection.**
Lines 3400-3401: If a policy is present but no rules were actually applied
(`jit_recompile_num_applied == 0`), the existing live image is kept. This
avoids unnecessary RCU grace periods and image allocation.

Lines 3678-3684: When no rules applied, rollback restores the pre-recompile
state and logs "no rules applied; kept the pre-recompile image."

**Finding 3.5c (Good): Snapshot/rollback architecture.**
The `bpf_jit_recompile_snapshot()` function saves complete state:
- bpf_func pointer
- priv_stack_ptr
- extable
- jit_data
- jited_len, num_exentries
- Full insn copy (for programs with subprogram calls)

The restore path (`bpf_jit_recompile_restore_prog_state()`) correctly
restores all fields and resets the recompile aux state.

**Finding 3.5d (Potential concern): struct_ops guard.**
Line 3575: Attached struct_ops programs are rejected with -EOPNOTSUPP.
The comment correctly explains that struct_ops trampolines hardcode
`prog->bpf_func`, so recompiling would leave stale trampoline references.
This is a correct safety guard.

### 3.6 Validation Framework

**Every canonical form has a dedicated validator**:
- `bpf_jit_validate_cond_select_rule()` -- checks diamond/compact shape
- `bpf_jit_validate_wide_mem_rule()` -- parses byte-recompose shape
- `bpf_jit_validate_rotate_rule()` -- supports 4/5/6-insn rotate idioms
- `bpf_jit_validate_addr_calc_rule()` -- validates LEA fusion shape
- `bpf_jit_validate_bitfield_extract_rule()` -- validates shift+mask pattern
- `bpf_jit_validate_endian_fusion_rule()` -- validates endian swap pattern
- `bpf_jit_validate_branch_flip_rule()` -- validates branch inversion

**Interior edge check** (`bpf_jit_has_interior_edge()`):
Applied to ALL pattern rules (line 2738), not just cond_select. This is a
critical safety property: if any jump from outside a pattern site targets an
interior instruction, the transformation would corrupt jump targets. The check
scans all instructions in the program, not just nearby ones.

**CPU feature gating** (`bpf_jit_cpu_features_for_native_choice()`):
- CMOV: requires X86_FEATURE_CMOV (universal on x86_64)
- RORX: requires X86_FEATURE_BMI2
- MOVBE: requires X86_FEATURE_MOVBE
- BEXTR: requires X86_FEATURE_BMI1

### 3.7 Code Quality Issues

**Finding 3.7a (Minor): Duplicate `bpf_jit_rule_form()` definition.**
The function `bpf_jit_rule_form()` is defined twice:
- Once in `jit_directives.c` at line 628
- Once in `bpf_jit_comp.c` at line 3468

Both are static functions with identical implementations. This is not a bug
(static linkage means they are separate symbols), but it is code duplication.
The one in `bpf_jit_comp.c` could be replaced by a shared declaration in the
header. However, since both files are in the same compilation unit effectively
(via the JIT compile path), this is a minor style issue.

**Finding 3.7b (Good): Overflow protection.**
`check_add_overflow()` is used consistently for site range calculations
(lines 127, 687-689, 3503), preventing integer overflow in site_start + site_len
computations.

**Finding 3.7c (Good): Logging architecture.**
The recompile log system allocates a kernel buffer, formats messages during
recompile, then copies to user via `copy_to_user()` at the end. This avoids
holding locks during user-space writes and provides useful diagnostics.

---

## Summary of Findings

### Critical Issues: NONE

### Important Findings (should address for paper):

1. **E2E needs repeated trials** (Finding 2.3b): Single-run workload measurements
   have high variance. Need at minimum 3-5 runs per workload for paper-grade results.

2. **Corpus dummy packet issue** (Finding 2.2a): Known and tracked, fix pending.

### Minor/Informational Findings:

3. **No CI in core runner** (Finding 2.1a): Acceptable -- bootstrap/Wilcoxon exists
   in `generate_figures.py` post-processing.

4. **Policy path soft coupling** (Finding 1.3a): Uses .bpf.o path for policy naming
   convention. Not a functional dependency.

5. **Duplicate static function** (Finding 3.7a): `bpf_jit_rule_form()` defined in
   two files. Cosmetic issue.

### Positive Findings:

- Scanner enumerate fully decoupled from application loading
- Counterbalanced runtime ordering in micro benchmarks
- RCU-safe image replacement with synchronize_rcu() + smp_store_release()
- Fail-closed recompile with complete snapshot/rollback
- Interior edge safety check on ALL pattern rules
- CPU feature gating for all ISA extensions
- BEXTR without-copy guard correctly implemented
- Thorough parameter validation in all emitters
