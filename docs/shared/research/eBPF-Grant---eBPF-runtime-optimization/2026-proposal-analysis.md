# 2026 eBPF Foundation Research Fund Proposal — Analysis and Writing Notes

Date: 2026-07-13
Scope: how to organize the 2026 proposal (eBPF runtime optimization) from the group's existing paper lines, what the fund actually requires, and what the winning-proposal format looks like.

## 1. The eBPF Foundation Research Fund — verified facts

- **2026 cycle: applications opened June 15, close July 15, 2026; recipients announced September 1, 2026.** Progress updates due December 1, 2026 and May 1, 2027; two blog posts are a reporting requirement.
- Materials: **Project Summary (max 2 pages)** covering area of focus, techniques, relevant prior work, and a timeline with milestones and expected outcomes; **Budget description (max 1 page)**; CVs for all participants; organization/tax details. Submission via Google Form. Up to **$50,000** per award, paid to the university as an unrestricted gift; funds may cover a researcher's salary.
- Topics of interest that directly match this proposal: *program optimization techniques*, *in-kernel JIT compiler improvements*, *formal verification of the verifier and JITs*, *limitations of the eBPF verifier*, *application efficiency improvements*, *network performance analysis and optimization*.
- Reviewers: the **eBPF Steering Committee** (lead maintainers of the ecosystem). 2024: 25 proposals from 20 universities, 5 funded. 2025: 27 proposals from 23 universities, 2 funded (EPASS, Univ. of Michigan; eBPF Governors, UC Riverside).
- The fund page links the **two 2025 winning proposals verbatim** (copies in `sample/sample1.pdf` = eBPF Governors, `sample/sample2.pdf` = EPASS). Their shared shape: numbered sections, a motivating-data figure plus a system-overview figure, a proof-of-concept paragraph with concrete numbers and a GitHub link, an explicit **Tasks 1..N** list, **milestones dated to the fund's own reporting dates** (Dec 1 / May 1, blog posts), and references — all packed into 2 pages at roughly 10–11pt.
- **EPASS (2025 winner) overlaps with BpfReJIT's space**: it also transforms programs at load time, re-verifies them, and argues no TCB growth — but for *programmability and safety within the ISA*. Our proposal must explicitly position itself as complementary: we target the *performance* gap **below the ISA** (native emits) and **after deployment** (workload-guided facts). Both current drafts do this.

## 2. Assets: the four paper lines in the benchmark repo

### 2.1 Kops (`docs/paper/`, arXiv:2606.24213) — most mature, full paper
- "Kops: Safely Extending the eBPF Compilation Pipeline with Native Operations." Complete: characterization → mechanism → seven hardware-idiom operations → Lean 4 proofs → implementation → four-RQ evaluation with real numbers on both architectures.
- Key numbers: eBPF-vs-native gap 1.57× geomean (up to 2×) over the pure-bytecode microbenchmarks; Kops micro geomean **1.242× (x86-64) / 1.222× (ARM64)**, recovering **42% of the gap**; native code size −22.8%/−12.1%; **Cilium 1.074× and Katran 1.073×** end-to-end (1.114× for Cilium under a tuned policy); no measurable kernel-side load-time overhead (0.99×).
- RQ3 is a policy-sensitivity counterexample: coverage maximization hurts (Katran 21→62 applied sites drops throughput to 0.995×) → "profitability, not coverage" is the open problem.
- RQ4 is a design-space upper bound: whole-program native replacement reaches **2.358× on Cilium** at the cost of a larger TCB; hardware idioms alone recover only **5.4%** of that ceiling on the real datapath (vs 42% on microbenchmarks) because real datapaths live in helpers, maps, and tail calls. **The 5.4%-vs-42% contrast is the strongest motivation sentence available for the grant.**

### 2.2 BpfReJIT (`docs/speculative-optimization/`) — architecture complete, claims honestly limited
- "Transparent Speculative Optimization for Deployed eBPF Programs." Runner/shim/pass-engine separation on stock kernels; two paths (load-time evaluated; running-process replacement implemented but not yet evaluated at paper grade).
- Claim ledger: C1 (transparent load-time application on six real apps) supported; C2 (live replacement coverage) no paper-grade result; C3 (runtime side inputs beat static policy) unproven; C4 (conservative policy avoids regressions) **currently unsupported** — the July 1 branch-layout run improved geomean (0.949 ratio) but a rerun regressed (stitched 1.113, 44 wins / 60 losses).
- Its "Result Gates" and four RQs are, verbatim, the open questions a grant can promise to resolve: profitability gating on held-out runs, live-replacement coverage across attachment types, phase-change recovery.

### 2.3 NativeBPF (`docs/kprog-simulator-in-ebpf/`) — design/position paper
- "Verifying Native Kernel Extensions with an eBPF Simulator": verify a specialized simulator artifact ("simulator I executing native program P") with the stock verifier, then execute P natively; explicitly not PCC, not SFI, not native-to-eBPF lowering; safety is a conditional transfer (simulator fidelity + hash binding join the TCB).
- Evaluation is still a plan, but its "native-execution preview" is exactly Kops RQ4's 2.358× path. **NativeBPF is the missing verification story for that upper bound** — the three papers meet end to end in one design space (stock eBPF → BpfReJIT, zero kernel change → Kops, small proven TCB → native + verification transfer).
- Recommendation for the grant: keep NativeBPF out of the funded scope (it has no numbers yet); at most one clause next to the 2.358× ceiling as the long-term direction.

### 2.4 bpf-bench (`docs/ebpf27-bpfoptbench/`) — workshop-sized, compiled
- Agentic auto-research framework + benchmark: 6 production apps / 146 programs / 42 microbenchmarks, hidden correctness checks against unsound transformations, agent-discovered speedups up to 34%, crash isolation. Open source: https://github.com/eunomia-bpf/bpf-bench.
- Dual role in the grant: the community-facing benchmark deliverable, and a one-sentence 2026-flavored methodology hook (agent-assisted search of the optimization space). Do not make it the main line — the proposal must stay an eBPF-ecosystem proposal, not an ML proposal.

## 3. Recommended story

One claim carries the whole proposal (bold it, like both winners do):

> *eBPF users pay for verified safety with up to 2× performance — we close that gap while the stock kernel verifier remains the sole safety authority.*

Structure the argument on two axes that the papers already establish:

```
TCB/mechanism axis:  stock eBPF → BpfReJIT (pure bytecode, zero kernel change) → Kops (module + Lean 4 proof) → native + verification transfer
performance:              1×            increasing                      micro +24%, apps +7–12%        2.358× ceiling
lifecycle axis:      before load (LLVM) → at load (Kops / BpfReJIT load-time) → after deployment (BpfReJIT live, open)
```

For a maintainer committee, the three highest-value points are:
1. **The TCB argument, stated explicitly**: the verifier is never modified; every candidate re-passes stock verification; Kops' only per-operation TCB addition is the native emit, discharged by Lean 4 proofs.
2. **The work is de-risked**: EPASS won in 2025 with "prototype + one strong number + GitHub link + fund the hardening." We are in an even stronger position: an arXiv paper with dual-architecture numbers, plus a public benchmark. **The ask funds the exposed open problem (profitability policy), not building from scratch.** Including the negative results (Katran 0.995× under coverage-max; the branch-layout rerun regression) signals maturity and leads directly into the Tasks.
3. **Ecosystem give-back**: benchmark suite release, kernel RFC for the Kops interface, and the two required blog posts written into the milestones.

## 4. Recommended format (and the current state of both drafts)

**Recommendation: follow the winning-sample format, not the 2025 paragraph format.** Reasons: the fund page links the two winners as implicit templates; the reviewers skim like maintainers (figures, numbers, artifact links); the 2-page limit including references is physically infeasible at 12pt paragraph style (the current paragraph draft runs ~3 pages of body text); and the 2025 paragraph-style submission was not among the winners.

Two-page budget for the sample-style version:
- **Introduction (~0.5 pg)**: adoption in one sentence → gap figure (per-category 2× chart) → why the JIT cannot be fixed in place (TCB / upstream cycle / per-arch code) → bold thesis. Fold Related Work into a closing paragraph and **explicitly differentiate EPASS**.
- **Approach (~0.5 pg)**: two bolded mechanism paragraphs (Kops + pipeline figure; BpfReJIT) and a short benchmark-substrate paragraph. Not three co-equal thrusts — two mechanisms and one substrate, to avoid reading as a three-paper bundle.
- **Preliminary Results (~0.3 pg)**: dense numbers + arXiv + GitHub links, including the negative results.
- **Tasks 1–5 (~0.3 pg)**: (1) cost-model-guided per-site profitability policy for Kops; (2) extend operations to map/helper-adjacent patterns (motivated by 5.4% vs 42%); (3) stability-aware gating for profile-guided passes, validated held-out; (4) live-replacement coverage + phase-change recovery; (5) benchmark release + upstream RFC.
- **Milestones (~0.2 pg)**: Sept 1, 2026 start; **Dec 1, 2026** M1 + first blog post; **May 1, 2027** M2 + progress update; Aug 1, 2027 M3 + RFC + second blog post; expected outcomes name OSDI/SOSP-level submissions.

Current files in this repo:
- `main.tex / overview.tex / budget.tex / biblio.bib` — the live 2026 draft in the **2025 paragraph format** (main.tex is byte-identical to the 2025 version except the title). Title: "eBPF Runtime Optimization: Safely Closing the Performance Gap to Native Code". 25 real bib entries including Kops (arXiv:2606.24213) and EPASS.
- `2025/` — the four 2025 LLM-serving-observability files, untouched.
- `old/2026-draft-winning-sample-style-overview.tex` — the sample-style alternative (numbered sections, two figures in `figs/`, Tasks 1–5, dated milestones). Enabling it requires in main.tex: 10pt, `\geometry{margin=0.8in}`, and the two-column `\scriptsize` bibliography block.
- `sample/` — the two 2025 winning proposals (PDF).

## 5. Writing cautions

1. **Do not import the papers' hedging.** The BpfReJIT paper's "results are mixed / open empirical gates" wording is a paper virtue; in the proposal the same facts become "open research questions this funding will resolve."
2. **One number, one appearance, one scope.** 0.609×, 2×, 1.57×, 24%, 22%, 12%, 34%, 42%, 5.4%, 2.358× measure different things (pure-JIT vs characterization vs micro vs production vs ceiling). State each once with its scope; reviewers cross-check.
3. Known limitations that do not belong in the proposal: the ARM64 tail-call poke gap, the OTEL post-optimization panic.
4. **Emphasize "works on stock kernels / no verifier changes"** at every opportunity — it is the single strongest adoption argument for this committee.
5. Remaining to-dos outside LaTeX: budget-year figures need updating by the PI (currently quotes AY 2025–26 costs); CVs and university tax/administrative details are separate form uploads.

## 6. Title

**Decided (2026-07-13): "eBPF Runtime Optimization: Safely Closing the Performance Gap to Native Code"** — used in `main.tex` and `budget.tex`. If the sample-style overview is enabled, keep this title there as well.

Rejected alternatives, for the record:
- Closing the eBPF Native-Performance Gap: Verified Native Operations and Workload-Guided Re-Optimization
- Making Verified Kernel Extensions as Fast as Native Code
