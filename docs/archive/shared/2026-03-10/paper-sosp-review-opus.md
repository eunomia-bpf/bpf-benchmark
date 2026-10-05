# SOSP/OSDI PC Review: BpfReJIT

**Reviewer**: Senior PC Member (simulated)
**Paper**: "BpfReJIT: Separating Mechanism and Policy in Kernel eBPF JIT Optimization"
**Venue target**: OSDI '26

---

## 1. Overall Score: 4/10 (Weak Reject)

The paper is between "weak reject" and "borderline." There is a real observation here (policy-sensitivity of JIT lowering), and the engineering is substantial. But the gap between the claim ("mechanism/policy separation for kernel JIT, analogous to Halide") and the evidence (4 peephole rules, 1 benchmark demonstrating policy-sensitivity, no deployment) is too wide for a top systems venue. The novelty quantum feels closer to an EuroSys or USENIX ATC paper than OSDI/SOSP, and several critical evaluation pieces are missing.

---

## 2. Summary

The paper observes that the Linux kernel eBPF JIT produces native code 15% slower and 2x larger than LLVM -O3 on the same BPF bytecode, attributable to three backend deficiencies. It argues that fixing these via kernel heuristics fails because some optimizations (notably cmov) are policy-sensitive: they help some workloads and hurt others. It proposes BpfReJIT, a framework that separates JIT optimization mechanism (kernel safety enforcement) from policy (userspace profitability decisions) via a new BPF_PROG_JIT_RECOMPILE syscall. Four rule families are implemented, and a declarative pattern extension reduces the cost of adding new variants. Evaluation shows ROTATE achieves 1.24x speedup, 60/60 production programs recompile successfully, and extension cost drops 31.8x.

---

## 3. Strengths

**S1. Real and well-measured gap.** The characterization of kernel JIT vs LLVM -O3 is methodologically sound (Wilcoxon signed-rank, BH correction, bootstrap CIs, CPU-pinned, turbo-disabled). The 89% root-cause decomposition via JIT-dump analysis is convincing and useful to the community regardless of the system contribution.

**S2. Policy-sensitivity is a genuine insight.** The observation that cmov helps unpredictable branches (+26% when removed) but hurts predictable branches (+34.5% when forced) is well-demonstrated and non-obvious. This is the paper's strongest conceptual contribution.

**S3. Clean mechanism/policy separation in the interface.** The BPF_PROG_JIT_RECOMPILE design -- digest-bound, sealed memfd, fail-closed, no native code upload -- is well thought out from a security standpoint. The "userspace specifies named variants, kernel emits" model is elegant.

**S4. Honest reporting.** The paper does not hide negative results: WIDE_MEM's p=0.164, COND_SELECT's regression, and the Cilium loading failure are all reported. This builds credibility.

**S5. Declarative extension mechanism.** The v5 pattern descriptor approach (32 LOC vs 1018 LOC for same-form variants) is a useful engineering contribution, though its significance depends on how many canonical forms are ultimately needed.

**S6. End-to-end prototype.** A working kernel prototype with 1800 LOC across 7 files, tested on real production programs, is substantial engineering.

---

## 4. Weaknesses (by severity)

### W1. The policy-sensitivity thesis rests on a single benchmark (Critical)

The entire "why not just fix the kernel" argument depends on cmov being policy-sensitive. The paper demonstrates this on exactly one benchmark (log2_fold) with one optimization (cmov). This is the paper's central claim, and one data point is not enough.

**What a skeptical reviewer would say:** "Branch predictability is easily inferrable from program structure. A kernel heuristic that checks for select-diamonds with data-dependent conditions vs. monotone comparisons would get cmov right for both log2_fold and switch_dispatch. The authors haven't shown that the decision is fundamentally uncomputable from static analysis -- they've shown that a trivial heuristic fails, which is a straw man."

The paper needs either: (a) multiple optimization families that are policy-sensitive (not just cmov), or (b) evidence that static analysis of BPF bytecode cannot determine profitability (e.g., because it depends on runtime input distributions, not program structure).

### W2. No end-to-end deployment or throughput evaluation (Critical)

The paper has zero deployment results. No Cilium datapath running with BpfReJIT policies. No Katran load balancer showing improved packets-per-second. No latency improvement on any real network function. The "60/60 production recompiles succeed" result shows the framework doesn't crash, not that it helps.

For OSDI/SOSP, the standard is at least one real-world deployment showing end-to-end impact. The fact that Cilium programs fail to load (acknowledged in limitations) makes this gap even more concerning -- the most important production BPF system cannot even be tested.

### W3. Four rule families is not "generality" (Major)

The paper claims mechanism/policy separation as a general design principle, analogous to Halide's algorithm/schedule separation. But Halide's schedule space has hundreds of transformations (tiling, vectorization, parallelization, fusion, etc.) and is demonstrably necessary because the space is too large for fixed heuristics. BpfReJIT has 4 rule families, of which:
- ROTATE: works, substrate optimization (not policy-sensitive)
- WIDE_MEM: works for code size, not statistically significant for exec time
- ADDR_CALC: modest 5.2% gain
- COND_SELECT: demonstrates a regression, not a gain

The "generality" claim would require either many more families or evidence that the space grows significantly with new architectures/workloads.

### W4. The Halide analogy is misleading (Major)

Halide separates algorithm from schedule because the schedule space is combinatorially large and workload-dependent. The schedule includes tiling dimensions, vectorization widths, parallelization strategies, fusion decisions, and storage layouts -- dozens of independent dimensions each with many choices.

BpfReJIT's "policy space" is: for each site, choose variant A or variant B (at most). This is not a combinatorial optimization problem -- it's a binary decision at each site, and there are at most a few hundred sites in a program. The analogy overstates the contribution. A more honest analogy might be "compiler flag tuning" (e.g., -ffast-math, -march=native), which is useful but not OSDI-level.

### W5. Table 4 (cmov ablation) is measured in the wrong system (Major)

Table 4 measures the effect of disabling cmov in llvmbpf (userspace LLVM JIT), not in the kernel JIT. The paper's system modifies the kernel JIT. The implicit assumption is that cmov profitability transfers from llvmbpf to kernel JIT, but this is never validated. The kernel JIT has different register allocation, code layout, and prologue/epilogue code, all of which could affect branch prediction and thus cmov profitability.

Table 7 (per-family re-JIT results) does show the kernel re-JIT regression for log2_fold, which partially addresses this. But Table 4 appears before the system is introduced and could mislead readers into thinking the ablation was done on the proposed system.

### W6. RQ1 belongs in Motivation, not Evaluation (Minor)

RQ1 ("How large is the code quality gap?") repeats the characterization from Section 2.3, adding only a single sentence about real-world programs. This inflates the evaluation section without adding new experimental evidence. The 5 RQs would be cleaner as 4 (RQ2-RQ5).

### W7. Safety argument is incomplete (Minor)

"xlated_prog_len unchanged" is necessary but not sufficient for safety. It shows that BPF bytecode is unmodified, but does not prove that the new native code correctly implements the BPF semantics. A re-JIT could emit cmov with the wrong condition code, producing silently wrong results. The paper mentions no differential testing, no formal verification of emitters, and no test suite beyond "the benchmark returns the same value." For a security-sensitive kernel component, this is a gap.

### W8. Missing cross-architecture validation (Minor)

The paper claims the design is architecture-neutral (Section 5.2 shows x86 and arm64 emitters), but all evaluation is x86-only. ARM64 is where cmov (csel) has very different performance characteristics. A single ARM64 data point would significantly strengthen the policy-sensitivity argument.

---

## 5. Per-Section Specific Suggestions

### Introduction
1. The "five properties" list (updateability, composition, workload adaptation, fleet A/B, ownership) reads like a sales pitch. At least 2-3 of these need concrete evidence in the evaluation. Currently none are evaluated.
2. The contribution list mixes characterization and system contributions. Consider leading with the system contribution and making characterization secondary.
3. "The first systematic native-code-level comparison" -- verify this claim. There may be prior work comparing kernel JIT output quality (e.g., in BPF mailing list discussions or K2/Merlin papers).

### Background and Motivation
1. The "Existing BPF Optimizers Cannot Close This Gap" subsection is too brief. A reviewer familiar with Merlin will say: "Merlin lifts BPF to LLVM IR. LLVM IR has select instructions. LLVM's backend can emit cmov. So Merlin could theoretically emit BPF bytecode that, when JIT-compiled, uses cmov." The paper needs to explain why this doesn't work (BPF ISA has no select opcode; Merlin lowers back to BPF before JIT).
2. Table 3 (instruction surplus sources) lacks methodology detail. "JIT-dump analysis of 22 benchmarks" -- how exactly? Manual inspection? Automated classification? What are the 22 benchmarks?
3. The policy-sensitivity argument (Section 2.4) should explicitly discuss whether branch predictability can be determined statically from BPF bytecode. If it can (e.g., comparison against constants in monotone order), the kernel could use a static heuristic. The paper must argue that static analysis is insufficient in general.

### Design
1. Section 3.5 (Declarative Pattern Extension) is too brief for such an important contribution. Expand with a concrete example: show a v5 pattern descriptor for ROTATE, walk through the binding table, and show how the kernel's canonical form emitter uses the bindings.
2. The security model section should discuss what happens if the policy blob requests CMOV at a site where the BPF pattern doesn't match a diamond. The "fail-closed" answer is good but should be stated explicitly with an example.
3. Missing: how does the framework handle concurrent access? If a BPF program is being executed on one CPU while re-JIT happens on another, what ensures consistency? The limitation about "not yet fully RCU-protected" should be more prominent -- this is a correctness issue, not just a limitation.

### Implementation
1. The O(1) rule lookup claim ("sorted array indexing") should be justified. If rules are sparse (e.g., 10 rules across 500 BPF instructions), is a sorted array the right data structure?
2. Missing: how large is the re-JIT latency? If a policy blob triggers re-compilation, how long does it take? Is the program unavailable during this window?

### Evaluation
1. RQ3 (safety) needs more evidence. Add differential testing: run the program with and without re-JIT on diverse inputs, compare outputs. "60/60 succeed" means "no crashes," not "correct behavior."
2. RQ4: WIDE_MEM's non-significant result (p=0.164) should be discussed more seriously. Is the sample size sufficient? Would more iterations change the result? Or is WIDE_MEM genuinely a code-size-only optimization?
3. Missing RQ: overhead on unoptimized programs. The paper claims "zero overhead" but doesn't measure it. Add a benchmark showing that programs without policies have identical performance to stock JIT (within noise).

### Related Work
1. Missing comparison with profile-guided optimization in other JIT compilers (HotSpot, V8, Graal). These systems have solved the "static heuristic vs. runtime feedback" problem in a different way. Why is BpfReJIT's approach better for BPF?
2. Missing discussion of Linux kernel live patching (kpatch, livepatch). These systems also modify running kernel code. How does BpfReJIT's re-JIT compare in terms of safety guarantees?

---

## 6. "If I Were the Authors" -- Actionable Improvement List

**Priority 1 (Must-do for resubmission):**

1. **Find 2+ more policy-sensitive rule families.** ROTATE profitability likely varies with hash table size (small tables fit in L1, large don't). WIDE_MEM profitability may depend on cache line alignment. Test these hypotheses. If only cmov is policy-sensitive, the paper reduces to "we added cmov to the kernel JIT and made it optional."

2. **One real deployment.** Pick the simplest production BPF program that has directive sites and can be loaded (e.g., a Katran XDP program). Show end-to-end throughput improvement with BpfReJIT vs. stock JIT vs. fixed-kernel-peephole baseline. Even 2-3% PPS improvement on a real load balancer is worth more than any number of microbenchmarks.

3. **Strengthen the "static analysis can't do it" argument.** Show a program where cmov profitability depends on runtime input distribution, not program structure. For example, a BPF program that processes network packets where the branch direction depends on packet content distribution, which varies between deployments.

4. **Address the Merlin/K2 rebuttal.** Add a concrete example or experiment showing that Merlin, even after lifting to LLVM IR, cannot produce BPF bytecode that causes the kernel JIT to emit cmov. This is because the BPF ISA lacks a select instruction and the kernel JIT is a 1:1 opcode translator.

**Priority 2 (Strong improvement):**

5. **Expand the declarative pattern section.** This is your strongest engineering contribution. Give it a full page with a worked example, code snippets of a v5 descriptor, and a comparison table showing v4 vs. v5 for each of the 4 families.

6. **Add ARM64 evaluation.** Even a single data point showing that cmov (csel on ARM64) has different profitability characteristics on ARM64 than x86 would validate the cross-architecture story.

7. **Add differential testing for safety.** Run each re-JIT'd program on 1000 random inputs and compare outputs to stock JIT. Report match rate.

8. **Move RQ1 to Motivation.** Restructure evaluation as RQ1=policy-sensitivity, RQ2=effectiveness, RQ3=safety, RQ4=extensibility.

**Priority 3 (Nice to have):**

9. **Drop or weaken the Halide analogy.** Use it as a sentence-level comparison, not a structural framing device. The analogy sets expectations the paper cannot meet.

10. **Add re-JIT latency measurement.** How long does BPF_PROG_JIT_RECOMPILE take? Is it fast enough for iterative optimization?

11. **Report the "five properties" evaluation gap.** Either add experiments for updateability/composition/A-B-testing/etc., or remove these from the Introduction.

---

## 7. Top 3 Reject Reasons

**R1. Insufficient evidence for the core thesis.** The mechanism/policy separation is justified by exactly one policy-sensitive optimization (cmov) on one benchmark (log2_fold). A senior reviewer will say: "This is not mechanism/policy separation -- this is an optional compiler flag. We've had -fno-if-conversion for decades."

**R2. No deployment evaluation.** OSDI/SOSP systems papers require demonstrated impact on real workloads. "60/60 production programs recompile without crashing" is not impact. The paper cannot show that any real-world program actually benefits from BpfReJIT in a deployment scenario.

**R3. Novelty quantum is below the OSDI/SOSP bar.** The core contribution is: (a) adding 4 peephole optimizations to the kernel JIT (engineering, not research), and (b) making them optional via a syscall (systems plumbing). The mechanism/policy separation principle is the novelty, but with only 4 rules and 1 policy-sensitive case, it's not convincingly demonstrated as a general principle. This feels like a solid EuroSys/ATC paper, not an OSDI/SOSP paper.

---

## 8. "If I Were to Champion This Paper"

If I wanted to argue for acceptance at the PC meeting, I would say:

"This paper identifies a genuine and previously unexplored design dimension in kernel eBPF: the JIT backend's native instruction selection is currently a fixed, non-configurable compiler pass, and the paper shows that this fixedness is wrong -- the same legal optimization helps some programs and hurts others by comparable magnitudes. The mechanism/policy separation principle is clean, the security model is well-designed (no native code upload, digest binding, fail-closed), and the prototype is real kernel code, not simulation.

The characterization alone would be a contribution: nobody has previously done a systematic native-code-level comparison of the kernel JIT against a strong baseline. The 89% root cause decomposition gives the kernel BPF community actionable information.

Yes, the evaluation is currently weak on deployment, and yes, only one optimization is policy-sensitive. But the framework is there, it works, and the policy-sensitivity finding for cmov is real and non-trivial. This is early-stage but important systems work that opens a new interface boundary in the kernel. With a revision cycle adding deployment results and more policy-sensitive families, this could be a strong paper.

I would champion it for a shepherd, with the conditions: (1) one real deployment evaluation, (2) at least one more policy-sensitive optimization family, (3) ARM64 data point."

However, I must be honest: without those additions, I cannot vote accept. The current delta between claim and evidence is too large.

---

## 9. Next Steps: What Experiments/Features/Data Would Move This from Borderline to Accept

### Experiments

1. **Policy-sensitivity matrix.** For each of the 4 rule families, test profitability on at least 5 diverse benchmarks. Show that ROTATE profitability varies with hash table size or input entropy. Show that WIDE_MEM profitability varies with access alignment or cache line crossing. If only CMOV is policy-sensitive, pivot the paper to "BPF JIT peephole optimization with optional cmov" (which is a less exciting but more honest story).

2. **Static analysis upper bound experiment.** Implement a simple static heuristic in the kernel for cmov (e.g., "use cmov if the diamond has data-dependent condition, use branch if it has comparison against constants"). Measure its accuracy. If the heuristic is 95%+ accurate, the framework is not needed. If it's <80% accurate, the framework is justified. This experiment is essential.

3. **End-to-end throughput.** Pick Katran XDP (it has 10 directive sites per your census). Run a packet generator against stock kernel JIT vs. BpfReJIT-with-policy. Report PPS, p99 latency, and CPU utilization. Even on a small testbed, this is infinitely more convincing than microbenchmarks.

4. **Cross-architecture.** Run the 5 key benchmarks (log2_fold, rotate64_hash, load_byte_recompose, stride_load_16, cmov_select) on ARM64 with both stock JIT and BpfReJIT. Show that CMOV (csel) profitability differs between x86 and ARM64. This validates the "policy depends on microarchitecture" claim.

5. **Iterative policy loop.** Demonstrate the load -> profile -> apply -> measure -> refine loop on one real program. Show that the second policy iteration improves over the first. This validates the "workload adaptation" claim.

### Features

6. **RCU-protected re-JIT.** The current prototype has a correctness hole (non-atomic re-JIT). Even if not production-ready, implementing basic RCU protection shows the design is viable for production use.

7. **Logging interface.** Add log_level/log_buf/log_size to the syscall attrs. Without feedback on which rules were accepted/rejected, the "iterative policy" story is incomplete.

8. **A simple static policy heuristic in userspace.** Implement "use cmov if the diamond's condition register is loaded from a hash/map lookup" as a default policy. Show it beats both always-cmov and never-cmov. This makes the system practically useful, not just a research prototype.

### Data

9. **Cilium loading fix.** Cilium is the highest-profile BPF deployment. Not being able to load Cilium programs is a serious credibility issue. Invest the engineering effort to make it work, even if it requires BTF/section compatibility workarounds.

10. **Larger production corpus with runtime data.** The current 60/60 result shows "no crashes." Get at least 10 programs where you can measure actual performance impact of re-JIT. Even if most show no change (because they have few sites), a few showing improvement would be valuable.

11. **Comparison with kernel-fixed baselines in the paper.** The kernel-fixed-baselines experiment (from the design hub) is exactly the right comparison. Include it prominently: "fixed kernel heuristic gets ROTATE right but gets CMOV wrong, demonstrating the need for selective policy."

---

## Appendix: Detailed Section-by-Section Notes

### Abstract
- "15% execution-time gap and 2x code-size gap" -- these are strong motivating numbers, good.
- "forcing cmov on predictable branches degrades performance by 34.5% (p=0.002)" -- this is the paper's key finding, well-placed.
- "Four rule families cover the identified gaps" -- this undersells the system. Emphasize mechanism/policy separation as the contribution, not the specific rules.
- "On 60 production BPF programs from Calico, Katran, and Suricata, all recompilations succeed" -- this should say what the recompilations achieve, not just that they succeed. "succeed with zero syscall failures" sounds like the bar is "doesn't crash."

### Section 1 (Introduction)
- Para 1: Good setup of BPF's importance and JIT's simplicity.
- Para 2 ("How large is the gap?"): Strong. Concrete numbers with CIs.
- Para 3 ("Why not just fix the kernel?"): This is where the paper is most vulnerable. The argument is: "cmov is policy-sensitive, therefore we need a framework." But (a) only cmov is shown to be policy-sensitive, and (b) a smart kernel heuristic might handle cmov correctly. The paper needs a stronger impossibility argument.
- Para 4 ("Key insight"): The Halide analogy appears here. As discussed in W4, this sets expectations too high.
- Para 5 ("Our system"): Clear and well-written.
- "Five properties" list: These are all claimed, none are evaluated. This is a red flag for reviewers.

### Section 2 (Background and Motivation)
- Section 2.1: Good, concise.
- Section 2.2: Too brief. The K2/Merlin rebuttal needs more depth (see W1 notes above).
- Section 2.3: The characterization is the paper's strongest empirical contribution. Consider giving it more space.
- Section 2.4: The single-benchmark policy-sensitivity evidence is the paper's weakest link.
- Table 4: Measured in llvmbpf, not in the proposed system. This disconnect should be explicitly acknowledged.

### Section 3 (Design)
- The text-based "architecture figure" (Figure 1) looks amateurish. Create a proper diagram.
- Section 3.4 (Security Model): Well-designed but missing the concurrent execution scenario.
- Section 3.5 (v5 Declarative Extension): Too short for such an important contribution.

### Section 4 (Implementation)
- 1800 LOC across 7 files is modest but appropriate for a kernel modification.
- The rule dispatch code listing is helpful.
- Missing: re-JIT latency, memory overhead of policy storage.

### Section 5 (Evaluation)
- The 5-RQ structure is reasonable but RQ1 should be in motivation.
- Table 7 is the most important table in the paper. It clearly shows the distribution of results across families.
- The production corpus section (RQ3) needs to show performance impact, not just success/failure.
- Missing: comparison with kernel-fixed baselines (which exists in the design hub but is not in the paper).

### Section 6 (Discussion)
- The "Falsification condition" paragraph is excellent. More papers should include this.
- "LLVM as upper bound" is a good framing.
- Limitations are honestly stated.

### Section 7 (Related Work)
- Missing: JIT compilers with PGO (HotSpot, V8, Graal).
- Missing: Linux live patching comparison.
- The K2/Merlin/EPSO comparison table (Table 1) is clear but could add a "Policy-sensitive?" column.

### Writing Quality
- Generally well-written, concise, and clear.
- The weakest paragraphs are in Section 2.4 (policy-sensitivity) and Section 3.5 (declarative extension), where the most important claims have the least supporting evidence.
- The "so what" moment is the log2_fold regression: "the same legal optimization degrades performance by 34.5%." This is memorable. Build the paper around it more explicitly.
- After reading the paper, the one sentence a reviewer remembers is: "cmov helps some programs and hurts others, so the kernel JIT should let userspace choose." The question is whether this observation alone justifies a framework, or whether it could be addressed by a 50-line kernel heuristic.
