# Paper Review R1: "Userspace-Guided Backend Optimization for eBPF JIT Compilers"

**Date:** 2026-03-10
**Reviewer:** Claude Sonnet 4.6 (automated review agent)
**Sources:** `docs/paper/paper.tex` + `docs/kernel-jit-optimization-plan.md`

---

## Overall Score: 5.5 / 10

The paper has a compelling, well-structured story and a real implementation. The mechanism/policy separation thesis is genuinely novel and the fixed-baselines falsification section is intellectually honest. However, it has several serious problems that would likely lead to a conditional reject at OSDI: (1) key numbers are internally inconsistent, (2) the v5 evaluation section claims validation of a feature that has known critical bugs per the plan, (3) the 40-real-program "attach+trigger" result from the expanded corpus study is completely absent, (4) the fixed-baselines table contains unexplained anomalies that reviewers will attack, and (5) the cmov_select evaluation numbers conflict with the characterization section. The writing quality is high throughout; the problems are empirical and structural, not stylistic.

---

## Strengths

1. **Clear story arc.** Characterization → root-cause → policy-sensitivity thesis → mechanism design → evaluation → falsification is tight and well-motivated.

2. **Intellectual honesty.** The falsification condition (Section 7.1) and the limitations subsection are unusually candid for a systems paper. The "What would further strengthen the argument" paragraph is good.

3. **Mechanism/policy separation is genuinely novel.** The five "why userspace" reasons are distinct and not reducible to "microarchitecture diversity." The TOCTOU protection via sealed memfd is a nice detail.

4. **v5 declarative extensibility section.** The Table 9 (v4 vs v5 extensibility comparison) is a strong contribution if the implementation is solid. The 80-LOC vs 0-LOC framing is compelling.

5. **Fixed-heuristic baselines.** Implementing and evaluating CONFIG_BPF_JIT_FIXED_{...} as explicit falsification baselines is exactly right. Reviewers would demand it; the paper provides it.

6. **Statistical methodology.** Paired Wilcoxon + BH correction + bootstrap CIs is appropriate and described clearly.

---

## Weaknesses (ranked by severity)

### W1 [CRITICAL] — cmov_select numbers conflict between abstract, characterization, and evaluation

The abstract states: "llvmbpf achieves 0.181x (147.5 ns vs 815 ns kernel)".
Table 2 (per-benchmark) lists: cmov_select exec ratio NOT present — the table ends at code_clone_8.
Table 6 (policy-sensitivity): "cmov_select: stock 815ns, with CMOV 648ns, -20.5%".

But MEMORY.md records: "cmov_select: L/K = 0.181x (llvmbpf 147.5ns vs kernel 815ns, 5.53x faster)". The characterization section (pure-JIT suite) says the geomean is over 31 benchmarks. Does cmov_select count as one of the 31, or is it the 50-benchmark set? This is unclear.

More critically: Table 6 says stock kernel on cmov_select is 815 ns, and applying COND_SELECT recompile gives 648 ns (-20.5%). But this means the recompile result (648 ns) is still 4.4x slower than llvmbpf (147.5 ns). The paper never explains this gap — if the recompile applies cmov, why is the result so much worse than LLVM which also uses cmov? This will be the first question from any reviewer.

**Fix needed:** Add an explicit sentence explaining that cmov_select has a subprogram call structure (per the Limitations section) that prevents full coverage: only some sites are recompiled, not all. Cross-reference the Limitations subsection. Also, verify that "with CMOV 648 ns" comes from the same VM run as "stock 815 ns" — the per-family table (Table 7) shows cmov_select/log2_fold but does NOT show cmov_select performance improvement; Table 6 does. These need consistent provenance.

### W2 [CRITICAL] — v5 section overclaims given known implementation bugs

Section 4.6 (Extensibility: v4 to v5) is presented as a working system. Section 5.5 (v5 Declarative Pattern Validation) claims "v5 matches v4 on both site count and native code size." However, `docs/kernel-jit-optimization-plan.md` (TODO section, tasks 58-62) lists five v5 "blocker" issues:

- Task 58: "Canonical binding table + parameterized emitter — CRITICAL — x86 emitter should extract operands from binding table, not re-parse BPF insn position. This is the core missing piece of v5 extensibility."
- Task 59: "COND_SELECT on v5 path — CRITICAL — the paper's most important policy-sensitive case must walk v5 declarative framework."
- Task 62: "Kernel-owned CPU legality — HIGH — must verify from (canonical_form, native_choice), not trust blob's cpu_features_required."

The v5 review score is 4.5/10 (task 55). The paper's v5 section implies a fully-working declarative system. A reviewer who asks "show me that a new pattern variant requires zero kernel code" will find the COND_SELECT family still hardcoded.

**Fix needed:** Either (a) fix tasks 58-62 before submission, or (b) honestly scope-down the v5 section to "design + partial implementation" and list which canonical forms are on the declarative path and which are still hardcoded. The current text is misleading.

### W3 [CRITICAL] — Fixed-baselines table (Table 10) has unexplained anomalies that will sink the paper

Table 10 shows:
- `stride_load_16`: ROT-only +131%, LEA-only +141%, ALL +111% exec regression
- `rotate64_hash`: FIXED-ALL -53% exec, yet per-family table (Table 7) shows ROTATE-only +20%^* for the same benchmark

The paper briefly addresses the rotate64_hash discrepancy in the footnote (^*) and in the WIDE+ROTATE combined row. But `stride_load_16` regressing by 131% under ROTATE-only is never explained. The plan (MEMORY.md section "Kernel-Fixed Baselines Results") notes "LEA: fixed-all regression on stride_load_16 (+14.2%) — combination interference" but Table 10 shows +141% for LEA-only, not +14.2%. These numbers do not match.

Concretely: MEMORY.md says `stride_load_16` fixed-all exec_ns goes from 437 to 499 (+14.2%). But Table 10 shows +131% for ROTATE-only on stride_load_16. These require reconciliation and explanation. Is +131% from a single noisy run? The paper notes "Median of 3 same-day VM runs" — 3 runs is not enough for a 131% claim.

**Fix needed:** (a) Increase repetitions for fixed-baseline evaluation (at least 10 runs), (b) provide a hypothesis for why ROTATE-only regresses stride_load_16 by 131% (is it a measurement artifact? is it a real microarchitectural effect?), (c) reconcile with MEMORY.md numbers which show +14.2% not +131%.

### W4 [MAJOR] — Missing: 40 real programs with both directive sites AND performance data

`docs/kernel-jit-optimization-plan.md` Task 54 records: "468 .bpf.o (including selftests+bcc+xdp-tools repos), 429 census, 40 real programs simultaneously with sites+performance data (29 test_run + 11 tracing). `run_corpus_tracing.py` implements attach+trigger measurement."

This result — 40 real programs where the scanner finds sites AND performance was measured — is a strong empirical claim that is completely absent from the paper. Section 5.4 (Directive Site Census) presents the 491-object census but never connects it to performance data. The distinction between "programs with sites" and "programs where we measured performance impact" is conflated.

The 11 "tracing attach+trigger" results are particularly noteworthy: they show the framework works on programs that cannot use bpf_prog_test_run (the normal test path). This is a significant evaluation contribution that reviewers will specifically ask about ("did you test on real tracing programs?").

**Fix needed:** Add a subsection or table combining site census + performance measurement for the 40 real programs. Specifically call out the attach+trigger methodology for tracing programs.

### W5 [MAJOR] — log2_fold fixed-CMOV numbers inconsistent with plan data

The paper (Table 6 and Section 5.3) states: fixed-CMOV on log2_fold degrades by "+19.7%" (948 ns → 1135 ns).
MEMORY.md "Kernel-Fixed Baselines Results" states: `log2_fold` stock 258 ns, fixed-all 331 ns, +28.3%.
Task 47 ("Per-directive isolation test") records: "CMOV-only: only log2_fold changed, +19.7%".

So there are TWO different log2_fold stock exec times: 258 ns (from the kernel-fixed-baselines experiment) and 948 ns (from Table 6 in the paper). These differ by 3.7x. The plan notes the fixed-baselines were run in VM (7.0-rc2), while Table 6 appears to use host or a different VM run. If these are from different environments (host vs VM, different isolation conditions), they need to be clearly labeled. If they are from the same environment, one is wrong.

Additionally: Table 7 (per-family results) shows `log2_fold` COND_SELECT: stock 648 B / re-JIT 682 B, exec +19.7%. But the stock time listed in Table 6 is 948 ns while Table 7's note implies stock is the 648-byte program. Is 948 ns the exec time of the 648-byte stock JIT? This needs one unified table with consistent provenance.

**Fix needed:** Standardize all log2_fold measurements to the same environment (VM 7.0-rc2) and clearly state timing source. Reconcile the 258 ns vs 948 ns discrepancy.

### W6 [MAJOR] — COND_SELECT (cmov_select) performance delta questionable

Table 7 shows COND_SELECT on cmov_select: stock 3537 B native, Re-JIT B column is missing (the row only shows code delta implicitly as "changed"). But the paper says cmov_select achieves +20.5% improvement under COND_SELECT (Table 6). Meanwhile the abstract claims llvmbpf achieves 5.53x speedup on cmov_select. If COND_SELECT recompile only achieves -20.5% on a benchmark where the gap is 5.53x, the paper needs to explain why recompile closes so little of the gap.

The Limitations section (subprogram boundary) provides the answer but the connection is not made explicit in the evaluation. A reviewer reading Table 6 will ask "you got -20.5% but llvmbpf is 5.53x faster — why is your recompile so far from the upper bound?"

**Fix needed:** Add a sentence in Section 5.3 explicitly saying: "The gap between re-JIT (-20.5%) and the llvmbpf upper bound (5.53x) is primarily explained by [N] sites not being recognized due to the subprogram boundary limitation (Section 5.7); full coverage would require addressing task #46."

### W7 [MODERATE] — Abstract claims "3,007 directive sites across 491 programs" but 40 programs have no performance

The abstract's "3,007 directive sites across 491 real and micro programs, including 114 programs (23.2%) with at least one applicable site" implies these are all meaningful. But per Task 52 (corpus-perf-results): "0 runnable programs with directive sites" in the initial corpus — all programs with sites were tracing type, not test_run-able. This was later fixed (Task 54), but the census count and the performance-validated count are two very different claims and should not be merged in the abstract.

**Fix needed:** Distinguish "programs scanned for sites" from "programs where performance was measured." The abstract currently conflates them.

### W8 [MODERATE] — v5 CMOV issue not in paper

Per Task 55 (v5-iteration-results): "CMOV on v5: 6 sites, +76% policy-sensitive." The plan MEMORY.md says "(+76% from v5 iteration)". But the paper's policy-sensitivity validation (Section 5.3) uses +19.7% (from fixed-CMOV kernel baseline) and mentions v4 numbers throughout. The v5-specific +76% cmov slowdown is not in the paper. If this is a v5 measurement (as MEMORY.md implies), it needs to appear in the v5 validation section.

### W9 [MODERATE] — Benchmark suite description is incomplete for 50-benchmark set

Table 1 (suite-level summary) mentions "Pure-JIT (50 full rerun)" but the paper only describes the 31-benchmark authoritative set in detail. The 19 additional benchmarks (added to probe specific mechanisms) are never listed or described. Appendix A only covers "31 authoritative." Reviewers will ask what the additional 19 are and why they improve the geomean from 0.849x to 0.797x (is it because they are easier for LLVM, or harder for kernel?).

**Fix needed:** Either add the additional 19 to Appendix A, or add a paragraph explaining their composition and why the geomean shifts.

### W10 [MINOR] — rotate64_hash ROTATE exec-time anomaly poorly explained

Table 7 footnote says: "rotate64_hash exec time increases with ror (3-op) vs. decreasing with rorx (BMI2, 1-op)." But the eval setup (Section 5.1) is QEMU/KVM VM with an Arrow Lake-S host. Arrow Lake-S supports BMI2. Why is the paper showing ROR (non-BMI2) results for rotate64_hash? If the CPU has BMI2, shouldn't the policy choose rorx by default?

The plan notes this issue: the scanner was generating BPF_JIT_ROT_ROR (not RORX) as a bug (Task R3), later fixed. But Table 7 still shows a +20% regression for ROTATE on rotate64_hash, suggesting the data may be from before the R3 fix or from a non-BMI2 run.

**Fix needed:** Clarify whether the ROTATE results in Table 7 use rorx or ror, and add a note explaining why ror was tested (e.g., to demonstrate the CPU-feature-gating mechanism).

---

## Section-by-Section Suggestions

### Abstract
- Add "v5 declarative pattern extension" to contributions (currently only in Section 4.6)
- Clarify that "3,007 sites" is scanner coverage, not necessarily performance-validated
- The "+19.7% fixed-CMOV slowdown" number in line 3 of the abstract should match Table 6 (currently consistent, good)

### Section 1 (Introduction)
- The "policy-sensitivity evidence" contribution item says "10--26%"; Table 3 shows 18.1%--26.3% benefit and 23.9%--18.1% harm. The range "10--26%" is technically accurate but understates the cmov_select result (0.181x). Consider: "up to 26% benefit or 24% harm for cmov; 5.53x benefit for unpredictable branch isolation"
- Missing contribution: "expanded corpus evaluation (40 real programs with performance data)"

### Section 2 (Background)
- The JIT pipeline description is excellent; no changes needed
- K2 citation: the paper says "The work closest to ours is the llvmbpf userspace runtime itself~\cite{k2}" — this is wrong, K2 is a BPF superoptimizer, not the llvmbpf runtime. The llvmbpf citation should point to the eunomia-bpf project or the LLVM BPF backend literature.

### Section 3 (Characterization)
- Section 3.5 (Real-Program Validation): "162 paired instances of 36 unique real-world BPF programs" — how are 36 unique programs producing 162 instances? The paper never explains. MEMORY.md says "162 paired instances (36 unique)" but doesn't clarify. Reviewers will ask if this is 162 = 36 programs × ~4-5 different functions per program, and whether the 14 "runnable" programs are a subset of the 36 or different programs.
- The code-size/exec-time disconnect paragraph (r=0.131, p=0.48) is a good finding but the correlation is across only 31 points — a reviewer may note this is underpowered for a correlation claim.

### Section 4 (Design)
- Section 4.3 (BPF_PROG_JIT_RECOMPILE interface): The `log_level` field in the UAPI is listed but the paper acknowledges it's not implemented (Limitations: "A production-grade implementation requires transactional re-JIT"). The field appears in code listing but Table 4 (impl components) says "no logging implemented except pr_debug." Make this consistent: either say the UAPI reserves it for future use or note that log_buf support (Task R4) is unimplemented.
- Section 4.6 (v5 Extensibility): This section needs a clear caveat that COND_SELECT is NOT yet on the v5 path (Task 59 is unresolved). The current text says "the key invariants from v4 are preserved" which implies v5 works for all four rule families.

### Section 5 (Evaluation)
- Table 7 (per-family results): The `cmov_select` row is missing — there is no row for COND_SELECT on cmov_select (unpredictable branch). The only COND_SELECT row is log2_fold (predictable branch, showing regression). This creates an asymmetry: you need a COND_SELECT + unpredictable branch row to complete the story. The cmov_select result (-20.5%) from Table 6 should also appear in Table 7 with consistent columns.
- Section 5.4 (Directive Site Census): The note that COND_SELECT appears in "BCC libbpf-tools profiling programs (biostacks: 15 sites, cpudist: 14 sites)" is excellent. But: these are tracing programs. Were they tested via the attach+trigger method? If yes, say so. If no, this is potentially misleading (sites exist but were never actually recompiled).
- Section 5.5 (v5 Validation): Change "v5 matches v4" to "v5 matches v4 for ROTATE and WIDE_MEM canonical forms; COND_SELECT remains on the v4 path." Add a note about known gaps (Tasks 58, 59).

### Section 6 (Discussion)
- Section 6.1 (Falsification): Excellent. The "What would further strengthen the argument" paragraph is good. Consider adding: "A second important open question is whether the ROTATE regression on stride_load_16 (+131%) is microarchitectural noise or a real interaction; this requires more repetitions."
- Section 6.3 (Deployment Model): Good, but lacks any timing data. What is "typical re-JIT latency is sub-millisecond"? The claim appears in Section 4.5 but is never measured. Add a footnote or measurement for representative programs (or remove the claim).

### Section 7 (Related Work)
- K2 citation issue: "The work closest to ours is the llvmbpf userspace runtime itself~\cite{k2}" — fix to correct citation for llvmbpf.
- The Halide analogy (Section 7.5) is apt but brief. Consider expanding: the key difference from Halide is that the "schedule" in BpfReJIT is constrained to a pre-approved set of equivalence-preserving lowerings, making it safe for a multi-tenant kernel.
- Missing related work: **BOLT** (Meta's binary optimizer), **Propeller** (LLVM's profile-guided optimization at linking time), **AutoFDO**. These are the systems closest in spirit to profile-guided post-compilation optimization. A reviewer will ask why you don't compare to these.

### Section 8 (Conclusion)
- Solid, but overstates v5: "The framework is ... extensible: adding a new rule family costs approximately 100--200 kernel LOC." This is v4 extensibility. v5 extensibility (new pattern for existing canonical form = 0 kernel LOC) should be the headline claim since the paper has a dedicated section on it.

---

## Missing Experiments/Data That Reviewers Will Ask For

1. **Rigorous re-JIT benchmarking** (Task 57): Current evaluation uses powersave governor, no CPU pinning, inside QEMU. OSDI reviewers will reject data from such a setup for an OSDI paper. At minimum: performance governor, CPU pinning, 30×1000 repeats for all v4 results (currently the re-JIT data is "median of 3 same-day VM runs").

2. **Cross-microarchitecture validation** (mentioned as future work in Section 6.1 but presented as "most important remaining"): The paper's entire falsification argument rests on one CPU (Arrow Lake-S). Even a second data point — e.g., an older Broadwell or Skylake — would substantially strengthen the claim. The plan mentions ARM64 CI exists (Task 26a).

3. **Per-directive isolation baseline (not just fixed-all)**: Table 10 shows individual directive columns, which is good. But the data source is stated as "3 same-day VM runs" which is insufficient. Also: the ADDR_CALC column shows no code-size change for most programs (0), meaning the ADDR_CALC fixed baseline is not actually exercised on these programs. This should be stated.

4. **End-to-end deployment evaluation**: The plan repeatedly states "one real deployment eval" as an OSDI go condition. The current evaluation is entirely on microbenchmarks and the census. No Cilium/Katran evaluation exists.

5. **cmov_select full coverage (Task 46)**: The benchmark designed to show cmov policy sensitivity has limited scanner coverage due to subprogram boundary. The paper presents -20.5% improvement, but the potential is 5.53x (llvmbpf upper bound). This gap is explained in Limitations but never quantified as "if we fixed subprog coverage, we would see approximately X%."

6. **Policy iteration demo**: The paper describes a PGO loop in Section 4.5 (load → profile → apply → measure → iterate) but there is no experimental evidence that this loop actually works end-to-end. At minimum, a 2-step iteration (apply CMOV → measure regression → revert → confirm recovery) would be compelling.

7. **ARM64 characterization** (Task 26a): The plan records ARM64 pure-JIT L/K = 0.656x (vs x86 0.797x). This is a major finding — LLVM's advantage is larger on ARM64 — but it does not appear in the paper at all.

---

## Data Accuracy Checks

| Claim in paper | Plan/MEMORY data | Status |
|---|---|---|
| Abstract: geomean 0.849x [0.834, 0.865], 25/31 sig | MEMORY: "Pure-JIT (31): geomean 0.849x [0.834, 0.865], 25/31 significant" | ✅ Match |
| Abstract: code-size geomean 0.496x | MEMORY: "Code-size geomean: 0.496x (31/31)" | ✅ Match |
| Abstract: 3,007 sites across 491 programs, 114 (23.2%) with ≥1 site | Table 8: 491, 114, 23.2%, 3,007 | ✅ Match |
| Section 3 intro: "50 pure-JIT + 11 runtime = 61" | MEMORY: "Suite: 50 pure-jit + 11 runtime = 61 total" | ✅ Match |
| Section 3.3: "31 vs 0 cmov instructions" | plan §2: "31 vs 0 cmov" | ✅ Match |
| log2_fold stock exec: 948 ns (Table 6) vs 258 ns (plan MEMORY) | INCONSISTENT | ❌ Needs reconciliation |
| fixed-CMOV regression: +19.7% (Table 6, 10) | plan Task 47: "+19.7%" | ✅ Match on percentage |
| fixed-CMOV regression: 948 → 1135 ns (Table 6) | plan MEMORY "log2_fold 258→331 ns" | ❌ Inconsistent absolute values |
| rotate64_hash: ROTATE 0→126 sites | plan §8.2c: "0→126 sites" | ✅ Match |
| rotate64_hash: ROTATE -32.3% code | plan §8.2c: "-32.3% code" | ✅ Match |
| rotate64_hash: ROTATE exec +20%* | plan §8.2c: "-28.4% exec" (for rorx?) | ⚠️ Ambiguous — paper shows +20% for ror, plan shows -28.4%; likely different variants |
| VM vs host geomean: 1.003x (combined 61) | MEMORY: "VM 7.0-rc2 vs Host 6.15.11 kernel: geomean 1.003x" | ✅ Match |
| cmov_select: llvmbpf 147.5 ns, kernel 815 ns, 0.181x | MEMORY: "cmov_select: L/K = 0.181x (llvmbpf 147.5ns vs kernel 815ns)" | ✅ Match |
| WIDE_MEM: load_byte_recompose -14.2% exec | plan §8.2b: "-13%/-14%"; plan §8.2d: "-13.0%" for fixed baseline | ⚠️ Paper uses -14.2% (v4 recompile), plan §8.2d uses -13.0% (fixed baseline) — check provenance |
| Surplus: byte-load 50.7%, branch 19.9%, prologue 18.5% | plan §2 table: same values | ✅ Match |
| 1,800 kernel LOC | MEMORY: "approximately 1,800 kernel LOC" | ✅ Match |

---

## Concrete Text Edits Needed

**1. Fix K2 citation for llvmbpf (Section 7)**

Current:
```
The work closest to ours is the llvmbpf userspace runtime itself~\cite{k2}
```
Fix:
```
The work closest to ours is the llvmbpf userspace runtime~\cite{llvmbpf}
```
(Add correct citation for llvmbpf/eunomia-bpf.)

**2. Fix v5 scope in Section 4.6**

After "We validate that v5 matches v4's site coverage..." add:
```
\emph{Note:} The v5 declarative path is currently implemented for ROTATE and WIDE\_MEM canonical forms. COND\_SELECT remains on the v4 hardcoded validator path; extending it to v5 is future work (requiring a parameterized binding table to avoid re-parsing BPF instruction operands).
```

**3. Fix cmov_select gap in Section 5.3**

After "The cmov\_select result confirms cmovcc is highly beneficial for unpredictable branches":
```
The remaining gap between the re-JIT result ($-20.5\%$, 648~ns) and the llvmbpf upper bound (147.5~ns, 5.53x faster than stock) reflects limited scanner coverage: the cmov\_select benchmark uses BPF-to-BPF subprogram calls, and the scanner does not currently traverse subprogram boundaries (Section~\ref{sec:limitations}). Full coverage would require the subprogram inlining or cross-boundary scanning described in future work.
```

**4. Add sentence explaining 162 instance origin (Section 3.5)**

```
The 36 unique programs consist of individual BPF programs within multi-program ELF objects; a single .bpf.o can contain 3--8 individual programs, yielding 162 paired instances from 36 unique source files.
```

**5. Clarify fixed-baselines evaluation confidence (Section 5.6)**

Change "Median of 3 same-day VM runs" to:
```
Median of 3 same-day VM runs (powersave governor, no CPU pinning; see Section~\ref{sec:limitations} for caveats on measurement confidence).
```

**6. Add ARM64 characterization finding (Section 3 or Discussion)**

```
Cross-architecture note: on our ARM64 CI runner, llvmbpf achieves a geomean of 0.656x vs.\ kernel (compared to 0.797x on x86-64), suggesting the backend gap is larger on ARM64---consistent with the kernel's ARM64 JIT having fewer peephole optimizations than x86. A full ARM64 analysis is deferred to future work.
```

**7. Reconcile log2_fold stock exec time**

Table 6 shows stock = 948 ns. Table 7 shows stock jited_prog_len = 648 B. The plan MEMORY says stock = 258 ns. This inconsistency must be resolved before submission. If 948 ns is correct (VM, 7.0-rc2), add a footnote explaining why it differs from the characterization measurement (258 ns may be from the host kernel, not the VM).

---

## LaTeX Issues

1. **Line 24**: `\acmBooktitle` has the conference name in both `\acmConference` and `\acmBooktitle` — this is correct for USENIX but the class is `sigconf` (ACM). If targeting OSDI (USENIX), use the `\documentclass[...]{acmart}` USENIX template variant. Currently the class and the conference affiliation are inconsistent.

2. **Table 10 (fixed_baselines)**: Uses `\scriptsize` — on a two-column ACM layout this will be very small. Consider splitting into two rows or using a landscape table.

3. **Figure 1 (byte_recompose)**: Contains a TODO placeholder (`% TODO: replace with actual figure`). This placeholder must be replaced before any review.

4. **Listings**: The `bpf_attr` union listing (line 600) uses `language=C` but `__aligned_u64` is not standard C; consider adding a note that this is Linux kernel UAPI style.

5. **Missing bibliography**: The paper references `\cite{cmov_branch}`, `\cite{credal}`, `\cite{feedback_directed}`, `\cite{jit_survey}`, `\cite{superoptimizer}`, `\cite{stoke}`, `\cite{peephole}` — none of these have corresponding entries provided. The bibliography file `references.bib` is referenced but not shown. Verify all citations compile.

6. **Section numbering**: The paper uses `\section` but the conf template typically uses numbered sections. At OSDI page limits (~14 pages), this paper is likely long — estimate current length and check against OSDI page limit.

---

## Summary of Priority Actions Before Submission

| Priority | Action |
|----------|--------|
| P0 | Fix log2_fold exec time inconsistency (948 ns vs 258 ns) across all tables |
| P0 | Replace Figure 1 TODO placeholder with actual native code comparison figure |
| P0 | Fix K2 citation for llvmbpf |
| P0 | Fix v5 scope: caveat that COND_SELECT is NOT on v5 path yet |
| P1 | Add cmov_select gap explanation (subprog coverage) in Section 5.3 |
| P1 | Reconcile rotate64_hash ROTATE exec: +20% (paper) vs -28.4% (plan) — clarify ror vs rorx |
| P1 | Add 40-real-program + tracing attach+trigger results |
| P1 | Increase fixed-baseline repetitions from 3 to ≥10 |
| P2 | Add cmov_select COND_SELECT row to Table 7 |
| P2 | Add ARM64 characterization finding |
| P2 | Add BOLT/Propeller/AutoFDO to related work |
| P2 | Explain stride_load_16 +131% ROTATE regression |
| P3 | Policy iteration demo (2-step: apply → measure regression → revert) |
| P3 | Re-JIT latency measurement to support "sub-millisecond" claim |
