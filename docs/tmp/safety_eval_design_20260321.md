# BpfReJIT Safety Evaluation Design

OSDI/SOSP-grade security testing suite for proving BpfReJIT does not violate the kernel safety model.

---

## Part I: Related Work Survey -- How Top-Tier Papers Test BPF Safety

### 1.1 Jitterbug (OSDI'20) -- Formal Verification of BPF JIT

**Method**: Bounded symbolic verification via SMT solvers (Boolector, Z3) through the Serval framework. Each BPF instruction's JIT compilation is verified individually: for all possible initial register values, all jump offsets, and all immediate values, the native code must produce the same observable state as the BPF semantics specification.

**Key techniques**:
- Per-instruction bisimulation proof: BPF state machine step == native state machine step
- SMT-based exhaustive search within bounded instruction windows
- Automated counterexample generation when a JIT emitter is buggy

**Results**: Found and fixed 16 previously unknown bugs in 5 deployed Linux JIT backends. Designed and verified a new RISC-V 32-bit JIT from scratch.

**Relevance to BpfReJIT**: Jitterbug verifies the JIT *compiler* itself. BpfReJIT does not modify the JIT compiler -- it modifies the *input bytecode* and then feeds it through the stock verifier+JIT pipeline. Therefore, Jitterbug-style formal verification of the JIT is orthogonal. What we need instead is evidence that (a) the REJIT syscall correctly invokes the existing verifier, and (b) the bytecode transformations preserve program semantics.

### 1.2 Jitk (OSDI'14) -- Verified JIT via CompCert

**Method**: End-to-end formal verification using Coq proofs on top of the CompCert verified compiler. The entire pipeline from high-level policy language to native x86 code is proven correct.

**Key techniques**:
- Coq proof of functional correctness for the BPF-to-native translation
- Integration into Linux kernel as a drop-in replacement for the existing BPF JIT
- Machine-checked proofs covering all code paths

**Relevance to BpfReJIT**: Demonstrates the gold standard (full formal verification). BpfReJIT intentionally sidesteps this by relying on the *existing* verified pipeline (verifier + JIT). Our safety claim is: "We add no new trusted code to the safety-critical path." Testing must demonstrate this claim empirically.

### 1.3 K2 (SIGCOMM'21) -- Synthesis-Based BPF Optimization

**Method**: Three-stage correctness assurance:
1. **Random testing**: Auto-generated test cases with concrete inputs; quick pruning of obviously wrong candidates
2. **Formal equivalence checking**: SMT-based proof that optimized program == original program for all inputs
3. **Formal safety checking**: SMT-based proof that optimized program passes verifier constraints

**Key techniques**:
- Domain-specific SMT encoding of BPF semantics (6 orders of magnitude acceleration)
- Test-then-verify pipeline: cheap tests first, expensive SMT proofs only for candidates that pass testing
- Explicit separation of equivalence (correctness) from safety

**Relevance to BpfReJIT**: K2's three-stage approach is the closest model. BpfReJIT's safety story differs because we delegate safety checking to the kernel verifier (not our own SMT checker). But we should adopt K2's differential testing approach: run original vs. transformed programs on the same inputs and compare results.

### 1.4 Merlin (ASPLOS'24) -- Multi-Tier BPF Optimization

**Method**: Compiler correctness argument -- each optimization pass is semantics-preserving by construction. Evaluation validates through:
- Verifier acceptance: all optimized programs pass the BPF verifier
- Functional testing: test_run on representative inputs, comparing original vs. optimized return values
- Size and performance measurement

**Relevance to BpfReJIT**: Merlin claims correctness from the compiler's design. BpfReJIT can make a similar claim for daemon correctness, but the critical difference is that BpfReJIT has an additional safety guarantee from the kernel verifier. We should test both: daemon correctness (differential testing) and kernel safety (negative testing + fuzzing).

### 1.5 EPSO (ASE'25) -- Superoptimization for BPF

**Method**: Offline discovery of rewrite rules via exhaustive enumeration of small instruction sequences, then online application. Correctness ensured by:
- SMT-based equivalence checking of each rewrite rule
- Verifier acceptance of all rewritten programs

**Relevance**: Similar to K2. Confirms that the combination of SMT equivalence + verifier acceptance is the standard approach for BPF bytecode transformation correctness.

### 1.6 BCF (SOSP'25) -- Certificate-Based BPF Verification

**Method**: Offloads complex verification reasoning to userspace, but requires formal proofs that are validated by a minimal in-kernel proof checker. Evaluation includes:
- Verification pass rate on 512 real eBPF programs (78.7%)
- Average proof size (541 bytes) and checking time (48.5 us)
- No false positives (soundness): rejected programs are truly unsafe

**Relevance to BpfReJIT**: BCF and BpfReJIT share the theme of "offload intelligence to userspace, keep kernel minimal." BCF's soundness guarantee (no false positives from the proof checker) parallels our claim that the verifier rejects all unsafe REJIT submissions.

### 1.7 BpfChecker (CCS'24) -- Differential Fuzzing of eBPF Runtimes

**Method**: Differential fuzzing across multiple eBPF runtimes (Linux kernel, uBPF, rbpf, bpftime):
- Lightweight eBPF IR for constrained mutation
- Semantic Correctness Rate (SCR) metric: % of generated programs that pass the verifier
- Comparison of execution results across runtimes to detect divergence
- ASan + UBSan enabled on userspace runtimes

**Results**: 28 implementation flaws, including 7 crashes and 2 CVEs.

**Relevance to BpfReJIT**: Directly applicable. We can use differential fuzzing between stock execution and post-REJIT execution on the same kernel. Our "two runtimes" are the same kernel, just pre-REJIT vs. post-REJIT.

### 1.8 BRF (FSE'24) -- eBPF Runtime Fuzzer

**Method**: Coverage-guided fuzzing of the eBPF runtime, built on Syzkaller:
- Semantic-aware program generation (satisfies verifier constraints)
- Syscall sequence generation (map creation, prog load, test_run)
- Coverage feedback via extended kcov
- 48-hour fuzzing sessions, 8 parallel fuzzer processes per VM

**Results**: 8x more programs executed vs. Syzkaller, 101% higher code coverage, 6 vulnerabilities (2 CVEs).

**Relevance to BpfReJIT**: BRF's approach of generating verifier-passable programs + syscall sequences is directly applicable to REJIT fuzzing. We need a variant that generates: LOAD -> test_run -> REJIT(mutated) -> test_run sequences.

### 1.9 Linux selftests/bpf -- Community Practice

**Structure**:
- `verifier/` directory: ~35 files with hundreds of individual test cases, each specifying BPF instruction sequences with expected `ACCEPT` or `REJECT` outcomes and specific error strings
- `prog_tests/` directory: 200+ functional tests exercising program load, attach, execution, and cleanup
- `test_verifier.c`: Main test harness that exercises the verifier with both positive (should accept) and negative (should reject) test cases

**Testing patterns**:
- **Negative testing**: Each `REJECT` test case specifies an expected `.errstr` that the verifier must produce. Examples: "unknown opcode", "R0 !read_ok", "BPF_LDX uses reserved fields", "unreachable insn"
- **Boundary testing**: Tests for off-by-one in stack access, register ranges, loop detection
- **Regression testing**: Each CVE fix adds a corresponding test case
- **CI integration**: BPF CI runs all selftests for every kernel patch submission

**Relevance to BpfReJIT**: The selftest pattern (instruction array + expected result + expected error string) is the model for our negative test suite. We must adapt it to the REJIT path: load a valid program, then attempt REJIT with malicious bytecode, and verify rejection.

### 1.10 syzkaller + BPF

**Coverage**: syzkaller has BPF syscall descriptions but is poor at generating verifier-passable programs. BRF (above) extends syzkaller specifically for BPF. The key insight: naive fuzzing hits the verifier wall; semantic-aware generation is needed.

**Relevance**: For REJIT fuzzing, we need semantic awareness too -- but at a different level. The fuzzer should generate programs that *almost* pass the verifier (to stress boundary conditions), not just random bytes.

---

## Part II: BpfReJIT Safety Claims and Test Requirements

### 2.1 Safety Claims We Must Demonstrate

Based on the security model in the plan doc (section 4.3), BpfReJIT makes these safety claims:

| # | Claim | What must be tested |
|---|-------|---------------------|
| S1 | Verifier validates all REJIT submissions identically to PROG_LOAD | Negative tests: malicious bytecode rejected via REJIT path |
| S2 | Failed REJIT does not affect the running program | Negative tests: verify original program still works after rejected REJIT |
| S3 | REJIT requires CAP_BPF + CAP_SYS_ADMIN | Privilege tests: unprivileged REJIT returns EPERM |
| S4 | Concurrent REJIT + execution is safe (no crash/UAF) | Stress tests: concurrent test_run + REJIT |
| S5 | kinsn modules have safe lifecycle (load/unload during program execution) | Module lifecycle tests |
| S6 | Daemon correctness: transformed program produces same results | Differential tests: stock vs. REJIT output comparison |
| S7 | Fail-safe: daemon bug cannot crash kernel | Fuzz tests: random bytecode mutations via REJIT |

### 2.2 Known Issues from Kernel Review (docs/tmp/kernel_v2_review_20260321.md)

The kernel review identified critical issues that our tests must also cover:

| Issue | Severity | Test coverage needed |
|-------|----------|---------------------|
| Stale XDP dispatcher after REJIT (UAF) | Critical | Stress test: REJIT on attached XDP program |
| RCU lifecycle: old image freed while executing | Critical | Concurrent execution + REJIT stress test |
| `fd_array` kernel/user pointer confusion | Critical | Negative test: REJIT with crafted fd_array |
| Missing `prog->len`/`insnsi` update after swap | Major | Info API test: GET_INFO_BY_FD after different-length REJIT |
| Incomplete `prog_flags` replay | Major | Negative test: REJIT with flag-dependent behavior |
| Torn reader state during concurrent REJIT | Major | Concurrent GET_INFO_BY_FD + REJIT |
| `load_time` semantic change | Minor | Info API consistency test |
| kinsn registry global string collision | Major | Module test: same-name kfuncs in different BTFs |

---

## Part III: Test Suite Design

### A. Negative Test Suite (Malicious Bytecode Rejection via REJIT)

**Goal**: Demonstrate claim S1 (verifier catches all unsafe REJIT submissions) and S2 (original program unharmed after rejection).

**Design**: Each test case follows this pattern:
1. Load a known-good BPF program via BPF_PROG_LOAD
2. Verify it executes correctly (test_run, check return value)
3. Attempt BPF_PROG_REJIT with malicious bytecode
4. Assert REJIT returns error (EINVAL, EACCES, or specific errno)
5. Assert original program still executes correctly (unchanged return value)
6. Assert no kernel WARNING/BUG/Oops in dmesg

**Test cases (20 cases)**:

| # | Category | Description | Expected error | Reference |
|---|----------|-------------|----------------|-----------|
| N01 | Empty program | REJIT with zero instructions | EINVAL ("no bpf_exit") | verifier/basic.c |
| N02 | Unknown opcode | REJIT with `BPF_RAW_INSN(0,0,0,0,0)` | EINVAL ("unknown opcode") | verifier/junk_insn.c |
| N03 | No exit | REJIT with instructions but no BPF_EXIT | EINVAL ("not an exit") | verifier/basic.c |
| N04 | Uninitialized R0 | REJIT with only `BPF_EXIT` (R0 not set) | EINVAL ("R0 !read_ok") | verifier/basic.c |
| N05 | Out-of-bounds stack | REJIT with stack access at offset -520 (beyond 512 limit) | EINVAL ("invalid stack off") | CVE-2017-16995 pattern |
| N06 | Backward jump (loop) | REJIT with `BPF_JMP_IMM(BPF_JA, 0, 0, -1)` (infinite loop) | EINVAL ("unreachable insn" / "back-edge") | verifier/jump.c |
| N07 | Illegal helper call | REJIT calling helper ID 0xFFFF (nonexistent) | EINVAL ("invalid func unknown#65535") | Standard verifier check |
| N08 | Null pointer deref | REJIT with map_lookup_elem result used without NULL check | EINVAL ("R0 invalid mem access") | Common verifier catch |
| N09 | Type confusion | REJIT treating scalar as pointer (BPF_LDX from scalar register) | EINVAL ("R* invalid mem access") | CVE-2021-3490 pattern |
| N10 | ALU overflow exploit | REJIT with 32-bit ALU operation followed by 64-bit pointer arithmetic exploiting truncation | EINVAL (bounds check failure) | CVE-2021-3490 pattern |
| N11 | Out-of-bounds packet | REJIT with packet access beyond data_end without bounds check | EINVAL ("invalid access to packet") | verifier/ctx_skb.c |
| N12 | Wrong prog type | REJIT XDP program with TC-only helper (e.g., `bpf_skb_change_head`) | EINVAL ("unknown func") | Program type mismatch |
| N13 | Oversized program | REJIT with >1M instructions (verifier limit) | E2BIG / EINVAL | verifier/scale.c |
| N14 | Invalid register | REJIT using register R11+ (only R0-R10 valid) | EINVAL ("reserved fields") | verifier/basic_instr.c |
| N15 | Double-free map ref | REJIT where map fd_array references a closed/invalid fd | EBADF / EINVAL | fd_array handling |
| N16 | Mismatched prog type | Load as XDP, REJIT bytecode that assumes TC context | EINVAL (context access violation) | prog_type enforcement |
| N17 | Privileged helper without cap | REJIT calling bpf_probe_read_kernel (requires CAP_PERFMON in some configs) | EACCES / EINVAL | Capability check |
| N18 | Stack overflow via calls | REJIT with deeply nested BPF-to-BPF function calls exceeding stack depth | EINVAL ("combined stack size") | verifier/calls.c |
| N19 | LD_IMM64 truncated | REJIT with odd instruction count leaving LD_IMM64 split across boundary | EINVAL ("invalid BPF_LD_IMM64") | verifier/ld_imm64.c |
| N20 | Speculative type confusion | REJIT with speculative out-of-bounds access (Spectre v1 pattern) | EINVAL (bounds/speculation check) | CVE-2019-7308 pattern |

**Implementation file**: `tests/safety/negative/test_rejit_negative.c`

**Framework**: Single C file, modeled after the selftest `verifier/*.c` pattern. Each test is a function returning 0 (pass) or 1 (fail). A `main()` runs all tests and reports.

### B. Fuzz Testing (REJIT Fuzzer)

**Goal**: Demonstrate claim S7 (daemon bug cannot crash kernel) -- even if the daemon submits garbage, the kernel stays safe.

**Design**: Coverage-guided fuzzer that mutates BPF bytecode and submits via REJIT.

**Architecture**:
```
                   +-----------+
                   | Seed Pool |  (valid BPF programs from micro/)
                   +-----+-----+
                         |
                   +-----v-----+
                   |  Mutator   |  (random mutation strategies)
                   +-----+-----+
                         |
              +----------v----------+
              | BPF_PROG_LOAD (seed)|
              +----------+----------+
                         |
              +----------v----------+
              | BPF_PROG_REJIT      |
              | (mutated bytecode)  |
              +----------+----------+
                         |
                   +-----v-----+
                   |  Oracle    |
                   +-----+-----+
                   |            |
            +------v---+  +----v------+
            | REJECT   |  |  ACCEPT   |
            | (ok)     |  | test_run  |
            +----------+  | check ret |
                          +-----------+
```

**Mutation strategies** (following BpfChecker's approach):
1. **Bit flip**: Flip 1-8 random bits in the instruction stream
2. **Instruction replacement**: Replace a random instruction with a random valid/invalid opcode
3. **Register randomization**: Randomize src_reg/dst_reg fields in random instructions
4. **Immediate randomization**: Replace imm32 with random values (0, -1, INT_MAX, INT_MIN, random)
5. **Instruction insertion**: Insert a random instruction at a random position
6. **Instruction deletion**: Remove a random instruction
7. **Instruction swap**: Swap two random instructions
8. **Opcode substitution**: Change opcode class (ALU->JMP, LD->ST, etc.)

**Oracle rules**:
- REJIT returns error --> OK (verifier correctly rejected)
- REJIT succeeds AND test_run produces same result as original --> OK (valid transformation)
- REJIT succeeds AND test_run produces different result --> LOG as potential daemon correctness issue (NOT a safety bug, but worth investigating)
- Kernel crash / WARNING / Oops --> FAIL (safety violation)

**Parameters**:
- Iterations: 100,000 (minimum for paper; 1,000,000 for thorough testing)
- Seed programs: All .bpf.o from micro/programs/ (62 programs)
- Mutations per seed: 1-5 random mutations composed
- Timeout per iteration: 1 second

**Metrics to report in paper**:
- Total iterations
- Rejection rate (expected: >99%)
- Acceptance rate of mutated programs
- Kernel crash count (must be 0)
- Kernel WARNING count (must be 0)
- Unique verifier error messages encountered
- Time per iteration (expected: <1ms for rejection)

**Implementation file**: `tests/safety/fuzz/rejit_fuzzer.c`

### C. Concurrent Stress Test

**Goal**: Demonstrate claims S4 (concurrent REJIT + execution is safe) and address critical kernel review findings (RCU lifecycle, stale dispatcher).

**Design**: Multi-threaded stress test with configurable thread counts and duration.

**Thread layout**:
```
Thread 1 (executor):
  loop:
    bpf_prog_test_run(prog_fd, data, &retval)
    assert retval in {EXPECTED_OLD, EXPECTED_NEW}

Thread 2 (rejitter):
  loop:
    bpf_prog_rejit(prog_fd, new_bytecode_A)
    sleep(random 0-1ms)
    bpf_prog_rejit(prog_fd, new_bytecode_B)  // toggle back

Thread 3 (info_reader):
  loop:
    bpf_prog_get_info_by_fd(prog_fd, &info)
    // just exercise the path, check for crashes

Thread 4 (dmesg_monitor):
  monitor /dev/kmsg for WARNING/BUG/Oops
  flag on first occurrence
```

**Test scenarios**:

| # | Scenario | Threads | Duration | Key assertion |
|---|----------|---------|----------|---------------|
| C01 | Basic concurrent exec+rejit | 2 (exec+rejit) | 10s | No crash, retval in expected set |
| C02 | High contention | 4 exec + 2 rejit | 30s | No crash, no WARNING |
| C03 | Rapid rejit toggle | 1 exec + 1 rejit (no sleep) | 10s | No crash |
| C04 | Concurrent info read | 1 exec + 1 rejit + 1 info | 10s | No torn state crash |
| C05 | REJIT during attached XDP | exec via XDP + rejit | 10s | No UAF (addresses kernel review finding) |
| C06 | Module unload during REJIT | rejit + module rmmod | 10s | No crash (kinsn lifecycle) |

**Invariants checked**:
1. `retval` is always in the set `{result_of_old_program, result_of_new_program}`
2. No kernel WARNING/BUG/Oops throughout the test
3. Program is still functional after stress test ends
4. `bpf_prog_get_info_by_fd()` never returns garbage or triggers crash
5. dmesg has no RCU stall warnings
6. No memory leaks (check `/proc/meminfo` before/after, or use kmemleak if available)

**Implementation file**: `tests/safety/concurrent/test_rejit_stress.c`

### D. Privilege Model Test

**Goal**: Demonstrate claim S3 (REJIT requires proper capabilities).

**Design**: Test the capability checks on the REJIT syscall path.

**Test cases**:

| # | Scenario | Setup | Expected |
|---|----------|-------|----------|
| P01 | Root can REJIT | CAP_BPF + CAP_SYS_ADMIN | Success (REJIT works) |
| P02 | No caps | Drop all capabilities | EPERM |
| P03 | CAP_BPF only | Drop CAP_SYS_ADMIN | EPERM |
| P04 | CAP_SYS_ADMIN only | Drop CAP_BPF | EPERM |
| P05 | Unprivileged user | Fork + setuid to nobody | EPERM |
| P06 | Namespace isolation | Unshare user namespace, then REJIT | EPERM (unless ns has token) |
| P07 | Invalid prog_fd | Valid caps, but fd=-1 | EBADF |
| P08 | Non-BPF fd | Valid caps, but fd=socket/file | EINVAL/ENOTSUPP |
| P09 | Closed fd race | Close fd then REJIT | EBADF |

**Implementation approach**: Use `prctl(PR_SET_KEEPCAPS)` + `setresuid()` + `cap_set_proc()` to precisely control capabilities. Alternatively, fork a child process and drop caps there.

**Implementation file**: `tests/safety/privilege/test_rejit_privilege.c`

### E. Differential Testing (Daemon Correctness)

**Goal**: Demonstrate claim S6 (transformed program produces same results as original).

**Design**: For every benchmark program in the suite, compare stock execution vs. post-REJIT execution with identical inputs.

**Architecture**:
```
For each benchmark in micro/config/micro_pure_jit.yaml:
  1. Load program via BPF_PROG_LOAD
  2. Generate input via input_generators.py
  3. Run N times via bpf_prog_test_run -> collect retvals_stock[]
  4. Apply daemon rewrite (BPF_PROG_REJIT)
  5. Run N times via bpf_prog_test_run -> collect retvals_rejit[]
  6. Assert retvals_stock == retvals_rejit (element-wise)
  7. Also compare:
     - xlated_prog_len (may differ, that's OK)
     - jited_prog_len (may differ, that's OK)
     - Return value (MUST be identical)
```

**Coverage**:
- All 62 micro benchmarks (micro_pure_jit.yaml)
- All corpus programs with optimization sites (91+ programs)
- E2E programs (Tracee, Katran sections with REJIT applied)

**Edge cases to test**:
- Programs where daemon finds no optimization sites (REJIT should be no-op or identity)
- Programs with every supported transformation family (wide, rotate, cmov, bextr, branch_flip, endian)
- Programs with kinsn calls (test with and without module loaded)

**Input diversity**: For each program, test with:
1. The standard generated input (from input_generators.py)
2. All-zero input
3. All-ones input (0xFF bytes)
4. Maximum-size input
5. Minimum-size input (1 byte where applicable)

**Implementation file**: `tests/safety/differential/test_rejit_differential.py`

**Why Python**: Reuses the existing micro benchmark infrastructure (input_generators.py, benchmark_catalog.py, runner/libs/). The heavy lifting (BPF execution) is done by micro_exec; Python only orchestrates and compares.

### F. Info API Consistency Test

**Goal**: Address the kernel review finding that `prog->len`/`insnsi` are not updated after REJIT, causing metadata inconsistency.

**Test cases**:

| # | Scenario | Check |
|---|----------|-------|
| I01 | Same-length REJIT | `xlated_prog_len` unchanged, `orig_prog_len` unchanged |
| I02 | Different-length REJIT (longer) | `xlated_prog_len` reflects new program |
| I03 | Different-length REJIT (shorter) | `xlated_prog_len` reflects new program |
| I04 | `jited_prog_len` consistency | JIT image length matches new bytecode complexity |
| I05 | `orig_prog_insns` after REJIT | Should reflect which version? (document semantics) |
| I06 | Multiple REJITs | Info consistent after 2nd, 3rd REJIT |

**Implementation file**: `tests/safety/negative/test_rejit_info_consistency.c` (can be merged into negative suite)

### G. Module Lifecycle Test (kinsn)

**Goal**: Demonstrate claim S5 (kinsn modules have safe lifecycle).

**Test cases**:

| # | Scenario | Expected |
|---|----------|----------|
| M01 | Load module -> load program with kinsn -> execute | Inline emission, correct result |
| M02 | Load program with kinsn -> unload module -> execute | Fallback to normal CALL, correct result |
| M03 | Load module -> REJIT to add kinsn call -> execute | Inline emission after REJIT |
| M04 | REJIT to add kinsn call -> unload module -> execute | Graceful fallback |
| M05 | Rapid module load/unload during REJIT | No crash |
| M06 | Two modules with same-name kfunc (collision test) | Deterministic resolution or error |

**Implementation file**: `tests/safety/module/test_kinsn_lifecycle.c`

---

## Part IV: Directory Structure

```
tests/
  safety/
    negative/
      test_rejit_negative.c          # 20 malicious bytecode cases (Part III.A)
      test_rejit_info_consistency.c   # Info API after REJIT (Part III.F)
    fuzz/
      rejit_fuzzer.c                  # Coverage-guided REJIT fuzzer (Part III.B)
    concurrent/
      test_rejit_stress.c             # Multi-threaded stress test (Part III.C)
    privilege/
      test_rejit_privilege.c          # Capability/permission tests (Part III.D)
    differential/
      test_rejit_differential.py      # Stock vs REJIT result comparison (Part III.E)
    module/
      test_kinsn_lifecycle.c          # kinsn module load/unload lifecycle (Part III.G)
    Makefile                          # Build all C test programs
    run_all.sh                        # Run full safety suite in VM
    README.md                         # Test descriptions and usage
  vm_test_comprehensive.sh            # Existing integration test
  vm_test_daemon_live.sh              # Existing daemon live test
  hold_bpf_prog.c                     # Existing helper
  hold_bpf_prog                       # Existing binary
  test_live_policy_discovery.py        # Existing unit test
  test_profile_guided_policy.py        # Existing unit test
  Makefile                             # Top-level: build all test programs
```

### Build dependencies

All C test programs link against:
- `libbpf` (from vendor/libbpf or system)
- `libcap` (for privilege tests)
- `libpthread` (for concurrent tests)
- Standard Linux headers with BPF_PROG_REJIT support

The `tests/safety/Makefile` should:
1. Detect whether the running kernel supports BPF_PROG_REJIT (compile-time check via UAPI header)
2. Build all C programs with `-O2 -Wall -Werror`
3. Support `make -C tests/safety` standalone build

### VM execution

`tests/safety/run_all.sh` should:
1. Boot VM with BpfReJIT kernel (`vng --run vendor/linux-framework/arch/x86/boot/bzImage`)
2. Load kinsn modules if available
3. Run each test category in order: privilege -> negative -> info -> differential -> fuzz -> concurrent -> module
4. Collect dmesg before and after each category
5. Report summary: PASS/FAIL per category, total kernel warnings, any crashes
6. Exit with non-zero if any safety test fails

---

## Part V: Paper Presentation Strategy

### What to claim in the OSDI paper

**Section: Security Evaluation** (expected ~1 page)

> BpfReJIT's safety model (Section 4.3) claims that the kernel verifier provides identical safety guarantees for REJIT submissions as for initial program loads. We validate this claim with a comprehensive security test suite comprising five categories of tests.

**Table format for the paper**:

| Test category | # Cases | Method | Key result |
|---------------|---------|--------|------------|
| Negative (malicious bytecode) | 20 | Submit known-unsafe bytecode via REJIT; verify rejection and original program survival | 20/20 rejected; 0 kernel warnings |
| Privilege model | 9 | Attempt REJIT with varying capability sets | All unprivileged attempts blocked (EPERM) |
| Fuzzing | 100K+ | Random bytecode mutation + REJIT submission | 0 kernel crashes; >99% rejection rate |
| Concurrent stress | 6 scenarios | Parallel execution + REJIT + info reads | 0 crashes; 0 torn states; retvals always in expected set |
| Differential | 62 micro + 91 corpus | Compare stock vs. REJIT-optimized execution results | 100% result equivalence across all inputs |
| kinsn lifecycle | 6 scenarios | Module load/unload during program execution | 0 crashes; correct fallback behavior |

**Key sentences for the paper**:

1. "We submitted 20 classes of known-unsafe BPF bytecode through BPF_PROG_REJIT, covering all major verifier rejection categories (Section X). In every case, the verifier correctly rejected the submission and the original program continued executing without interruption."

2. "We fuzzed the REJIT path with N iterations of randomly mutated bytecode. The verifier rejected M% of submissions; the remaining N2 programs that passed verification produced results identical to their pre-mutation originals. Zero kernel crashes or warnings occurred throughout."

3. "Under concurrent stress testing (K executor threads + L rejitter threads for T seconds), the return value was always in the expected set {old_result, new_result}, with zero torn states, zero crashes, and zero dmesg warnings."

4. "Differential testing across all N benchmark programs confirmed 100% result equivalence between stock and REJIT-optimized execution across M distinct input patterns per program."

### Comparison with related work testing methodology

| System | Formal verification | Negative testing | Fuzzing | Differential testing | Concurrent stress |
|--------|:---:|:---:|:---:|:---:|:---:|
| Jitterbug (OSDI'20) | SMT per-insn | -- | -- | -- | -- |
| Jitk (OSDI'14) | Coq proof | -- | -- | -- | -- |
| K2 (SIGCOMM'21) | SMT equiv+safety | -- | Random test cases | Input comparison | -- |
| Merlin (ASPLOS'24) | By construction | -- | -- | test_run comparison | -- |
| EPSO (ASE'25) | SMT equiv | -- | -- | -- | -- |
| BCF (SOSP'25) | Proof checker | -- | -- | -- | -- |
| **BpfReJIT** | **Verifier delegation** | **20 cases** | **100K+ iters** | **153+ programs** | **6 scenarios, 30s+** |

**Key differentiator**: BpfReJIT is the only system that (a) delegates safety to the existing verified pipeline rather than adding new verified components, and (b) validates this delegation empirically with negative + fuzz + concurrent testing. This is a weaker but more practical guarantee than formal verification, justified by the insight that BpfReJIT adds zero new code to the safety-critical verifier/JIT path.

---

## Part VI: Implementation Priority

| Priority | Component | Effort | Blocks paper? |
|----------|-----------|--------|:---:|
| P0 | Negative test suite (A) | 2-3 days | Yes |
| P0 | Differential test (E) | 1-2 days | Yes |
| P1 | Concurrent stress test (C) | 2-3 days | Yes |
| P1 | Privilege model test (D) | 1 day | Yes |
| P2 | Fuzz testing (B) | 3-5 days | Nice-to-have |
| P2 | Module lifecycle test (G) | 1-2 days | Only if kinsn in paper |
| P3 | Info API consistency (F) | 1 day | After kernel fixes |

**Total estimated effort**: 10-16 days for P0+P1+P2.

**Prerequisite**: Several kernel bugs identified in the review (Part II, Section 2.2) must be fixed before concurrent stress tests can pass. Specifically:
- The RCU lifecycle issue (stale image freed while executing)
- The XDP dispatcher stale pointer issue
- The `prog->len`/`insnsi` update omission

These fixes are tracked separately in the kernel development plan.

---

## References

- [Jitterbug: Specification and verification in the field (OSDI'20)](https://www.usenix.org/conference/osdi20/presentation/nelson)
- [Jitk: A Trustworthy In-Kernel Interpreter Infrastructure (OSDI'14)](https://www.usenix.org/conference/osdi14/technical-sessions/presentation/wang_xi)
- [K2: Synthesizing Safe and Efficient Kernel Extensions (SIGCOMM'21)](https://conferences.sigcomm.org/sigcomm/2021/files/papers/3452296.3472929.pdf)
- [Merlin: Multi-tier Optimization of eBPF Code (ASPLOS'24)](https://dl.acm.org/doi/10.1145/3620666.3651387)
- [EPSO: A Caching-Based Efficient Superoptimizer for BPF Bytecode (ASE'25)](https://arxiv.org/abs/2511.15589)
- [BCF: Prove It to the Kernel (SOSP'25)](https://github.com/SunHao-0/BCF)
- [BpfChecker: Differential Fuzzing of eBPF Runtimes (CCS'24)](https://dl.acm.org/doi/10.1145/3658644.3690237)
- [BRF: Fuzzing the eBPF Runtime (FSE'24)](https://dl.acm.org/doi/10.1145/3643778)
- [SafeBPF: Hardware-assisted Defense-in-depth (CCSW'24)](https://tfjmp.org/publications/2024-ccsw.pdf)
- [Linux BPF selftests](https://github.com/torvalds/linux/tree/master/tools/testing/selftests/bpf)
- [syzkaller kernel fuzzer](https://github.com/google/syzkaller)
- [Moat: Towards Safe BPF Kernel Extension (USENIX Security'24)](https://www.usenix.org/system/files/usenixsecurity24-lu-hongyi.pdf)
