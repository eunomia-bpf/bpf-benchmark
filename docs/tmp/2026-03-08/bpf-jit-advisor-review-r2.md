# Review of Revised BPF-JIT Advisor Design (Round 2)

## Overall Verdict

This revision is materially better than the first-round draft. It fixed several of the most damaging problems from round 1:

- the scope is now paper-sized rather than "everything at once";
- `Mode 2` is correctly the main contribution;
- post-relocation extraction fixes the most obvious CO-RE/libbpf staleness issue;
- the safety section no longer hides behind "advisory only";
- the design now admits that direct peepholes are the more upstreamable end state for individual mature patterns;
- the evaluation plan now includes the right baselines, especially direct kernel peepholes and fail-closed robustness tests.

So the revision did respond to the first review in a serious way. I would no longer call the design "conceptually promising but structurally unfocused." It is now focused.

However, the central feasibility risk is still kernel-side, and it remains significant. The revised document moved toward the right answer by introducing verifier-retained facts, but it still understates how much of the problem has become **verifier-assisted JIT**, not merely "userspace hints plus local checks." That is not fatal for a paper, but it does mean the current design is still not fully credible as written.

My updated verdict is:

- **substantially improved;**
- **closer to publishable;**
- **still not yet strong enough on kernel feasibility and LLVM round-trip realism to be OSDI/SOSP-ready without further narrowing or a prototype result.**

## What Improved Relative to Round 1

The following revisions directly address first-round criticism and, in my view, are real improvements rather than cosmetic edits:

### 1. Scope control is much better

Demoting `Mode 1`, cutting `block-order`, `rotate-ok`, and riscv from v1, and focusing on `wide-load-ok` plus `select-region` was the right move. This makes the system reviewable.

### 2. The post-relocation extraction fix is correct

Moving extraction after CO-RE, call relocation, and subprogram finalization is a real fix to an actual loader-integrity problem. This was one of the most important first-round objections, and the revision addresses it cleanly.

### 3. The safety model is stated much more honestly

The revision now correctly says "fail-closed against malformed/stale/unprovable hints" instead of implying that "advisory" alone is enough. That is a major improvement.

### 4. The design now concedes the right upstreaming comparison

The revised "why hints instead of peepholes" section is much stronger than round 1 because it no longer pretends the hint path is cheaper or obviously more upstreamable. The factorization argument is the right one to make for a research artifact.

### 5. The evaluation plan is now much more reviewer-aware

Adding:

- direct local peephole baselines,
- malformed/stale hint testing,
- acceptance-rate and overhead breakdowns,
- multi-function and CO-RE-heavy coverage,
- arm64 requirements for cross-arch claims,

was necessary. The revision now asks the right experimental questions.

These changes are enough that I would score the revision clearly above the first-round 5/10 overall. But the design still has unresolved issues that matter exactly in the areas you asked me to focus on.

## 1. Kernel-Side Feasibility

## 1.1 Would BPF maintainers accept a hint UAPI?

The revision improved this substantially by **stopping the claim that the UAPI is obviously upstream-ready**. That was the right correction.

My answer is still: **probably not as a permanent Linux UAPI in the current form**.

Why:

- Existing `BPF_PROG_LOAD` metadata channels are all tied to verifier semantics, attach semantics, or observability/debug (`prog_btf_fd`, `func_info`, `line_info`, `attach_btf_*`, `fd_array`), not to user-provided backend optimization advice.
- A per-program `hint_fd` would create a new user-controlled optimization surface that maintainers would immediately compare against:
  - direct x86/arm64 JIT peepholes;
  - verifier-produced summaries consumed by the JIT;
  - or simply extending existing in-kernel analysis.
- For the two v1 patterns, neither hint kind is so global or so opaque that maintainers would obviously prefer a new UAPI over direct kernel work.

So the revision fixed the **overclaim**, but not the underlying acceptability problem.

My more precise judgment is:

- **research prototype**: credible;
- **out-of-tree artifact**: credible;
- **upstream Linux UAPI**: still doubtful.

If this paper is framed as "this exact UAPI will be accepted by Alexei/Daniel," I would reject that claim. If it is framed as "this is a research vehicle to test whether userspace-discovered backend opportunities matter," I can accept it.

## 1.2 Is the verifier-retained-facts mechanism realistic?

This is the most important remaining issue.

The revision is directionally correct: `wide-load-ok` cannot be justified by structural matching alone. You do need verifier help.

But the document still makes the retained-facts mechanism sound more straightforward than it is.

### What the verifier actually has

During verification, the kernel does track rich facts:

- register type/class,
- fixed offset and variable offset,
- `id`,
- range information,
- nullability/reference state,
- stack-slot state,
- alignment-related facts,
- some per-insn aux information.

This is visible in current verifier state (`struct bpf_reg_state`) and per-insn aux data (`struct bpf_insn_aux_data`) in [`vendor/linux/include/linux/bpf_verifier.h`](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/include/linux/bpf_verifier.h).

### What survives after verification

Very little of the full path-sensitive state survives into the eventual JIT-visible program object today. The verifier explicitly frees its explored states and clears/frees `insn_aux_data` at the end of `bpf_check()` in [`vendor/linux/kernel/bpf/verifier.c`](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c).

This means the revision is right that **new retention plumbing is required**.

### Why the proposed facts are still under-specified

The design proposes per-load facts such as:

- `region_id`,
- `ptr_class`,
- `base_reg`,
- `fixed_off`,
- `readable_bytes`,
- `align_log2`,
- `NONNULL`,
- `STACK_INIT`,
- `UNALIGNED_OK`.

That is the right *shape* of data, but several of these are not existing verifier outputs with stable semantics:

- `readable_bytes` is a summarized proof object, not a current verifier field;
- `region_id` sounds simple, but the verifier's notion of pointer identity is subtler than a stable "object id" across packet/map/ctx/stack cases;
- packet safety is often path-sensitive and offset-sensitive in a way that is not obviously compressible to a single per-load `readable_bytes`;
- `UNALIGNED_OK` is architecture- and memory-class-sensitive, so defining it once in a generic retained-fact layer is nontrivial.

The revision therefore improves the argument from "local checks are enough" to "we need verifier-retained summaries," which is good. But it does **not yet show that these summaries are easy to compute, stable, or minimal**.

### The biggest missing kernel detail: verifier rewrites

This is, in my view, the strongest remaining kernel-side objection.

The revision correctly fixes **post-libbpf** drift, but it still keys hints to the pre-verifier finalized instruction image. The kernel verifier can and does rewrite programs before JIT:

- inserted `BPF_ST_NOSPEC`,
- context-access conversions,
- helper/kfunc/call fixups,
- local-call patching,
- dead-code sanitization and related adjustments,
- metadata/index adjustments.

Current verifier code explicitly tracks original instruction indices via `orig_idx` in `struct bpf_insn_aux_data`, and then clears that data later. The revised design does not explain how a `hint_fd` keyed to pre-verifier indices remains stable by the time `do_jit()` or `build_insn()` consumes the rewritten program.

This is not a minor omission. It is the exact same class of staleness bug as the first-round pre-relocation problem, just one stage later.

The design needs one of:

1. hints keyed to original instruction ids, with kernel-side remapping through verifier rewrite history;
2. hints reattached after verifier rewriting using retained `orig_idx` maps;
3. or a narrower claim that v1 only supports program classes with no relevant verifier rewrites.

Until this is specified, I do **not** consider the retained-facts story fully realistic.

## 1.3 Is hint consumption in `do_jit()` implementable without major refactoring?

**Implementable: yes.**

**As lightweight as the document suggests: no.**

The x86 JIT in [`vendor/linux/arch/x86/net/bpf_jit_comp.c`](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c) is a multi-pass per-insn loop over `prog->insnsi` with `addrs[]` convergence and per-insn address assumptions. arm64 in [`vendor/linux/arch/arm64/net/bpf_jit_comp.c`](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/arm64/net/bpf_jit_comp.c) is similar in spirit.

That means:

- a region-consuming hint is not impossible;
- but it is not just "if hint at anchor, emit replacement and skip N insns."

You also need to preserve:

- `addrs[]` consistency across skipped instructions,
- branch-target correctness,
- `jited_linfo` / address mapping expectations,
- exception-table interactions where relevant,
- multi-pass size convergence.

For `select-region`, this is still realistic because the transformed region is small and purely control/data flow.

For `wide-load-ok`, it is realistic only if the supported region shape is extremely narrow.

So my judgment is:

- `select-region`: clearly implementable;
- `wide-load-ok`: implementable, but only with stricter v1 restrictions than the document currently states;
- "no major refactoring": too optimistic.

## 1.4 Are there existing kernel mechanisms that could serve the same purpose?

Yes, but not all of the alternatives are equally good.

### `BPF_PROG_TYPE` / attach annotations

No. These are far too coarse. They constrain verifier behavior and context semantics, not per-region JIT lowering opportunities.

### BTF metadata

Partially, but only as a transport hack, not as the real mechanism.

Current kernel BTF already supports:

- `func_info`,
- `line_info`,
- declaration tags (`DECL_TAG`),

and the verifier already uses decl tags for function-level semantics such as `exception_callback:` in [`vendor/linux/kernel/bpf/btf.c`](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/btf.c) and [`vendor/linux/kernel/bpf/verifier.c`](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c).

However:

- `func_info`/`line_info` are fixed-layout and not a real hint channel;
- decl tags are function/type/argument-level, not instruction-region-level.

So BTF is not a clean substitute for per-region hints.

### Verifier-assisted JIT

This is the strongest alternative, and the revision unintentionally strengthens it.

Once you admit that `wide-load-ok` needs verifier-retained facts, the cleanest kernel story becomes:

- verifier computes/retains the necessary proof summary;
- JIT uses it directly;
- userspace may optionally help with candidate discovery, but the kernel owns the legality basis.

That is simpler, more upstreamable, and avoids a new UAPI for the hardest legality question.

In other words, the revised design is now much closer to **verifier-assisted JIT plus optional userspace pattern discovery** than to a pure userspace-oracle system. That is progress, but the document should say this more explicitly.

## 2. LLVM-Side Feasibility

## 2.1 Is the BPF -> LLVM IR lifting in `llvmbpf` suitable for reliable hint extraction?

For `Mode 2` hint extraction on a **restricted subset**, maybe yes.

For `Mode 1` round-trip, no.

Current `llvmbpf` in [`vendor/llvmbpf/src/compiler.cpp`](/home/yunwei37/workspace/bpf-benchmark/vendor/llvmbpf/src/compiler.cpp) lifts BPF into IR that is designed for **native execution of an emulated BPF machine state**:

- registers are materialized as allocas;
- the stack is synthetic;
- helpers become external calls;
- local BPF calls use manual call-stack machinery and `indirectbr`.

That is acceptable for recognizing some local optimized shapes like:

- a byte-load/shift/or tree that became one wide load;
- a local branch diamond that became an LLVM `select`.

So for the narrow `Mode 2` extractor, I think the revision is now plausible if it stays very local.

But "reliable hint extraction" still depends on a problem the document continues to underplay: **projection back to original BPF indices after optimization**.

With `InstCombine + SimplifyCFG`, even these local patterns can lose an obvious one-to-one mapping. The revision improved by restricting hint scope, but it still needs a much more explicit origin discipline:

- when origin metadata is attached;
- which transforms are allowed to merge/discard it;
- how projections fail closed.

I would accept this as a research prototype risk for `Mode 2`.
I would **not** accept it as already solved.

## 2.2 Can LLVM's BPF backend faithfully round-trip bytecode for `Mode 1`?

Still no, not in the strong sense implied by the design.

The revision was smart to demote `Mode 1`, because the underlying technical situation is still difficult:

- current `llvmbpf` has no `LLVM IR -> optimized BPF bytecode/.bpf.o` path;
- the lifted IR is not canonical verifier-friendly BPF IR;
- helpers, maps, local calls, and `LDDW` forms are already transformed in ways that are good for host-native execution, not for verifier-faithful re-emission.

More importantly, upstream LLVM's BPF backend itself contains BPF-specific verifier-preservation machinery:

- `BPFPreserveStaticOffset`,
- `BPFCheckAndAdjustIR`,
- `BPFAdjustOpt`,

in [`tmp/llvm20-bpf-src/BPFPreserveStaticOffset.cpp`](/home/yunwei37/workspace/bpf-benchmark/tmp/llvm20-bpf-src/BPFPreserveStaticOffset.cpp), [`tmp/llvm20-bpf-src/BPFCheckAndAdjustIR.cpp`](/home/yunwei37/workspace/bpf-benchmark/tmp/llvm20-bpf-src/BPFCheckAndAdjustIR.cpp), and [`tmp/llvm20-bpf-src/BPFAdjustOpt.cpp`](/home/yunwei37/workspace/bpf-benchmark/tmp/llvm20-bpf-src/BPFAdjustOpt.cpp).

That is evidence in both directions:

- positive: upstream LLVM does contain real BPF/verifier-aware infrastructure;
- negative: this infrastructure exists because generic LLVM optimization is dangerous for verifier-visible semantics.

So the revision was right to demote `Mode 1`, but it still understates how far `Mode 1` is from "restricted but straightforward."

My recommendation remains:

- keep `Mode 1` only as fallback/tooling/comparison;
- do not let the paper depend on faithful arbitrary-ELF round-trip.

## 2.3 What LLVM version dependencies are there?

The design is still too vague here.

Current `llvmbpf` builds with LLVM `>= 15` according to [`vendor/llvmbpf/CMakeLists.txt`](/home/yunwei37/workspace/bpf-benchmark/vendor/llvmbpf/CMakeLists.txt), but the repo also carries LLVM 20 BPF backend sources under `tmp/llvm20-bpf-src/`, and the BPF backend's verifier-facing behavior has evolved over time.

So I would separate the answer:

- **Mode 2 extraction only**: probably workable on the current llvmbpf baseline (`LLVM >= 15`) if the extractor uses only local IR patterning.
- **Mode 1 re-emission**: should pin to a recent LLVM series and state that explicitly, because verifier-preserving BPF backend behavior is version-sensitive.

Right now the document does not pin a version, which means it is hand-waving a very practical source of engineering failure.

## 2.4 Are there LLVM upstream efforts that overlap or conflict?

No direct upstream LLVM effort obviously conflicts with `Mode 2` hint extraction.

The overlap is with `Mode 1`:

- LLVM upstream BPF work is already about constraining optimization to remain verifier-friendly.
- That means a custom lifted pipeline that depends on arbitrary IR reshaping is pushing against the same constraints upstream BPF backend developers are already managing.

So the revised design is fine as long as it treats LLVM as:

- a userspace analysis oracle for `Mode 2`,
- not proof that `Mode 1` round-trip is near-trivial.

## 3. Remaining Gaps

## 3.1 Did the revision fix the safety model adequately?

**Partially yes, but not fully.**

Fixed well:

- fail-closed framing;
- malformed blob hardening;
- stale-hint handling for the loader/relocation stage;
- explicit requirement for verifier-retained facts.

Still not fixed:

- verifier-rewrite-induced staleness between load-time indices and JIT-time program image;
- exact semantics and construction cost of the retained facts;
- a crisp v1 exclusion list for pointer classes/memory classes that are too subtle.

My recommendation is to tighten v1 further:

- support only stack, map-value, and perhaps ctx accesses first;
- exclude packet and more exotic pointer classes unless a prototype demonstrates the retained-facts summary is actually implementable.

## 3.2 Is the "why hints not peepholes" argument now convincing?

More convincing than round 1, but not fully.

What works now:

- the document finally uses the right argument: shared userspace discovery and cross-arch factorization.

What still does not fully work:

- for exactly two local patterns, direct kernel peepholes still look extremely competitive;
- `wide-load-ok` in particular risks reading as "a userspace-discovered peephole with a UAPI attached."

So the revised argument is **good enough for a research artifact**, but still weak as a permanent design argument.

The evaluation must win this point empirically. Without that experiment, reviewers will still prefer direct peepholes.

## 3.3 Is the evaluation plan sufficient?

It is much better, but I still would not call it sufficient yet.

What improved:

- direct peephole baseline;
- fail-closed testing;
- overhead measurement;
- harder program classes.

What is still missing or still too implicit:

- a concrete plan for verifier-rewrite stability or original-index remapping;
- more realistic real-program coverage for attach-context-sensitive program types;
- arm64 characterization evidence before claiming the same backend gap exists there;
- a plan to report **which memory classes actually accept `wide-load-ok`**.

This matters because `docs/paper.md` still shows that the benchmark suite covers a very narrow corner of the corpus:

- only `0.8%` of the 5D feature box;
- `97.2%` of corpus programs are multi-function;
- the current suite has `0%` multi-function coverage.

The revision now acknowledges this better, but the evaluation is still only persuasive if the prototype can survive harder real-program loadability and hint-acceptance tests.

## 3.4 What is still missing?

The two biggest missing design details are:

1. **How hints survive verifier rewriting.**
2. **What exact verifier summary is realistic to retain, and for which pointer classes.**

Until those are specified, the kernel-side feasibility story is still incomplete.

## 4. Comparison with Alternative Approaches

## 4.1 Direct kernel peepholes

For the v1 patterns, direct peepholes remain:

- simpler,
- more upstreamable,
- easier to reason about from a trust/UAPI standpoint.

The hint design beats them only on:

- cross-arch factorization,
- userspace iteration speed,
- and research leverage.

So for an OSDI/SOSP artifact, the hint design is still defendable.
For upstream Linux, direct peepholes remain the default favorite.

## 4.2 Verifier-assisted JIT

This is now the strongest competitor and, in some sense, the revised design has moved toward it.

For `wide-load-ok`, verifier-retained legality summaries are the hard part. Once you accept that, the cleanest design is:

- verifier computes proof summary,
- JIT consumes proof summary,
- userspace is optional for candidate discovery.

That removes the main trust objection without giving up the kernel-side legality basis.

I would rate this alternative as **more realistic for kernel acceptance** than a permanent hint UAPI.

## 4.3 Modified BPF ISA

Cleaner long-term, much harder to upstream.

Adding explicit select or wider load forms would be architecturally cleaner, but it would require:

- ISA changes,
- verifier changes,
- interpreter updates,
- all JITs/toolchain updates,
- and a much longer upstream path.

So compared with ISA modification:

- the revised hint design is more practical as a short-term research prototype;
- the ISA path is cleaner only as a distant end state.

## 5. Updated Scores

| Dimension | Round 1 | Round 2 | Rationale |
| --- | ---: | ---: | --- |
| Technical quality | 6/10 | **7/10** | Narrower scope, better safety framing, and the right post-relocation fix materially improve the design. The remaining technical weakness is the still-underspecified verifier-retained-facts and verifier-rewrite story. |
| Novelty | 6/10 | **7/10** | Centering `Mode 2` sharpens the paper's real novelty. The contribution now reads less like "another BPF optimizer" and more like "userspace-guided backend-lowering recovery." |
| Presentation clarity | 8/10 | **9/10** | This version is much clearer, more disciplined, and more honest about non-claims. |
| Feasibility | 4/10 | **5/10** | Better than round 1, but still held back by kernel acceptance risk and the lack of a convincing verifier-retained-facts plus verifier-rewrite integration story. |
| Overall publishability at OSDI/SOSP | 5/10 | **6/10** | This is now plausibly paper-shaped, but it still needs either a narrower prototype result or a more concrete kernel feasibility story before I would call it ready. |

## Bottom Line

The revision **did** address a large fraction of the first-round critique, and it deserves credit for that. In particular, the design is now focused on the right problem, asks the right experimental questions, and avoids several earlier overclaims.

But the kernel-side hardest part is still not fully solved:

- post-libbpf drift is fixed, but post-verifier drift is not;
- "retained verifier facts" is the right answer, but still not a realistic enough design as written;
- and once you accept verifier-retained facts, the cleanest long-term comparison point becomes verifier-assisted JIT, not a permanent hint UAPI.

If I were advising the authors, I would say:

1. keep `Mode 2` as the paper center;
2. further narrow `wide-load-ok` to memory classes with a demonstrably realistic verifier summary;
3. explicitly solve original-index versus verifier-rewritten-index mapping;
4. treat permanent upstream UAPI acceptance as a non-goal;
5. make verifier-assisted JIT the main alternative you have to beat, not just direct peepholes.

That version would be substantially stronger.
