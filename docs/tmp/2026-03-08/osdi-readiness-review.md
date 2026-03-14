# OSDI/SOSP Readiness Review

This is the review I would write if this project landed in an OSDI/SOSP PC discussion today. It is intentionally blunt.

## 1. Novelty Assessment

### Is "userspace-guided backend optimization for kernel JIT" genuinely novel?

Partially. The genuinely novel part is not "backend optimization" by itself. That space is old. The novel part is the specific split:

- kernel owns legality and fail-closed adoption;
- privileged userspace owns profitability, rollout, and policy evolution;
- the interface is bounded, digest-bound to one finalized BPF image, and designed for real BPF deployment ownership.

That is a plausible systems contribution, especially in eBPF where deployment ownership really does live in userspace agents such as Cilium/Katran-style loaders.

But the novelty is only moderate unless you prove two things:

1. some profitable backend decisions really do vary across CPU/workload/program in ways fixed kernel policy does not capture; and
2. the mechanism supports more than one narrow "interesting case" plus one obvious kernel peephole.

Right now the idea is more novel than the prototype.

### What is the closest related work?

The closest reviewer mental models are:

- BOLT / post-link layout optimization: profitability driven by profile and code layout, not by source semantics.
- PGO / AutoFDO: deployment-informed compiler policy rather than fixed heuristics.
- JVM tiering / GraalVM: runtime or near-runtime policy chooses among multiple legal lowerings/tiers.
- llvmbpf / LLVM-based JIT: the direct "why not just use a better compiler backend?" competitor.

The paper is not "more novel than these systems" in a broad compiler sense. The claim has to be narrower:

- not a new optimizer architecture;
- not a new JIT theory;
- a new kernel/userspace ownership split for bounded backend decisions in eBPF.

### How is this different from profile-guided JIT optimization in other systems?

The main differences are:

- userspace does not emit arbitrary native code;
- the kernel still owns verification, legality, and final code emission;
- the interface is bound to one exact finalized pre-verifier BPF image;
- the system is designed to fail closed back to the stock JIT;
- the intended policy owner is the deployment operator, not the upstream kernel and not an in-process runtime.

That is real differentiation. It is also a double-edged sword. It makes the safety story stronger, but it also makes the mechanism look narrower and less transformative than JVM/JIT work.

### Would a reviewer say "just add these peepholes to the kernel"?

Yes. They would be right for a large fraction of the current directive set.

Today:

- `wide_load` looks exactly like a kernel peephole that should probably just exist.
- `rotate_fusion`, `lea_fusion`, `bitfield_extract`, and maybe `wide_store` also read like kernel backend cleanups.
- `bounds_window` may or may not belong in userspace, but the current story does not prove it.

The only strong counterexample on paper today is `cmov_select`, and even that is still under-specified and only weakly validated.

If the best implemented directives are mostly local peepholes, reviewers will conclude the interface is elaborate machinery around optimizations the kernel should own directly.

### Would a reviewer say "just use LLVM's JIT"?

Also yes. This is the other obvious attack.

The honest answer is:

- if a deployment can simply replace the kernel JIT with llvmbpf/LLVM and gets most of the gains, that is a much simpler engineering answer;
- your paper only survives if the contribution is not "better optimization than LLVM," but "how to keep the kernel JIT model while externalizing profitability policy under kernel safety constraints."

That is a defensible distinction, but it is not yet a winning one. You still need to explain why the deployment must retain the kernel JIT path instead of using llvmbpf as the real backend.

### Bottom line on novelty

As an OSDI/SOSP claim:

- the idea is novel enough if framed as legality/profitability separation for eBPF JIT deployment;
- it is not novel enough if framed as "we added a few backend directives";
- it is not novel enough if fixed kernel heuristics or llvmbpf already capture the same wins.

## 2. The Mechanism/Policy Story

### Is the legality/profitability split convincing?

Conceptually, yes. It is the best part of the design.

It is clean and reviewer-friendly:

- legality is stable, kernel-local, and safety-critical;
- profitability is unstable, deployment-specific, and operationally owned by userspace.

The problem is not the abstraction. The problem is that the current evidence only strongly supports a narrow subset of that claim.

Today the docs convincingly support:

- `wide_load` as a legality-heavy local rewrite;
- narrow `cmov_select` as a maybe-policy-sensitive rewrite.

They do not yet convincingly support:

- non-local layout policy;
- inlining policy;
- a broader family of policy-sensitive backend decisions.

So the split is convincing as a thesis, but not yet as a demonstrated system.

### The "5 why-userspace reasons" — are they each independently strong?

Not equally.

Strong:

- updateability;
- fleet A/B testing and rollback;
- ownership by the service/operator rather than kernel maintainers.

Potentially strong, but needs evidence:

- workload adaptation;
- program-level composition/code-size-budget management.

The weakest of the five is program-level composition. It is plausible, but in the current docs it still reads partly like padding unless you show concrete cases where a locally profitable transform becomes globally harmful because of code-size or I-cache effects.

The workload-adaptation argument is also not fully earned yet. Right now it is supported mostly by suggestive microbenchmark sensitivity, not a real deployment result.

### Is there evidence that fixed kernel policies actually fail to capture the profitability?

Not yet. There is suggestive evidence, not decisive evidence.

What exists:

- `no-cmov` ablation shows mixed outcomes;
- branch-layout sensitivity changes with input distribution;
- frequency sensitivity exists;
- the docs explicitly recognize the need for kernel-fixed baselines.

What is missing:

- `kernel-fixed-cmov` across multiple CPUs and workload classes;
- `kernel-fixed-layout` against userspace-guided layout;
- evidence that a sensible kernel heuristic cannot recover the same gains;
- multi-program evidence that the best decision changes across programs, not just across synthetic branches.

Until those baselines exist, the main reviewer reaction will be: "Interesting, but you have not actually shown that userspace policy beats a decent in-kernel heuristic."

### The mandatory falsification condition is good — but has it been tested?

No. It has been declared, not exercised.

That condition is excellent and intellectually honest:

> if fixed kernel policies recover the same gains, the answer is kernel peepholes / kernel-only policy, not a new interface.

But a falsification condition only helps if you actually run the falsification experiment. Right now the project has not done that. So the strongest sentence in the design is still hypothetical.

## 3. System Design Quality

### Is the architecture over-engineered for what it does?

Yes, somewhat.

The core interface is disciplined and appropriately narrow:

- one `BPF_PROG_LOAD` extension;
- one sealed `memfd`;
- one load-time blob;
- fail-closed fallback;
- no post-load mutation.

That part is good.

The over-engineering starts when the design grows a lot of permanent kernel-visible structure around a feature that still only has two v1 directives:

- rich CPU contract fields;
- per-record feature bitmaps;
- `policy_id`, `policy_version`, `workload_class` in the ABI;
- structured per-site result arrays in `bpf_prog_info`;
- fairly elaborate rollout and telemetry design.

That makes the system look more mature than it is. Reviewers will notice the imbalance.

### The blob format is very detailed — but v1 only has 2 directive kinds. Is this premature?

Partly yes.

The strictness is good:

- bounded size;
- strict parsing;
- reserved-zero rules;
- versioning discipline;
- digest binding.

The premature part is turning operational metadata and observability into a kernel ABI before the core mechanism has proven value. For v1, a smaller ABI would be easier to defend.

### The security analysis is thorough — but does the threat model match reality?

Only partially.

The security writeup is solid on parser safety, fail-closed behavior, TOCTOU, and privilege boundaries.

But the threat model that matters for paper acceptance is broader than "can an attacker exploit the blob parser?":

- how much new TCB is being added to verifier/JIT critical paths?
- how realistic is the constant-blinding exclusion?
- what happens in mixed-loader environments?
- how do pinned programs, shared maps, and link replacement affect rollout?
- how much operational rigidity is introduced by exact digest binding?

Those are the real "systems reality" questions. The docs acknowledge some of them, but the design is still stronger on security posture than on deployment realism.

### How does this compare to other kernel extension mechanisms?

It is much narrower than `io_uring`, `nftables`, or `netfilter`.

Those interfaces expose broad, durable abstractions with obvious multi-workload utility.

This proposal is a specialized backend-policy interface for one subsystem. That is not bad, but it raises the bar:

- the mechanism must be obviously necessary;
- the gains must be clearly unattainable with simpler kernel-only approaches;
- the ABI must feel minimal and stable.

Right now it still feels closer to a specialized hint ABI than to a broadly inevitable kernel extension mechanism.

## 4. Evaluation Gaps

### What experiments are missing?

The missing experiments are exactly the ones reviewers will ask for first:

- `kernel-wide-load`, `kernel-fixed-cmov`, and `kernel-fixed-layout` baselines;
- same-program, different-CPU, different-workload policy divergence;
- real-program directive acceptance census by kind;
- multi-function program evaluation, not just mostly straight-line microbenchmarks;
- end-to-end Cilium/Katran-style deployment with real traffic;
- compile/load overhead: blob parse, digest, remap, validation, logging;
- constant-blinding availability impact;
- rollout experiment with pinned programs, shared maps, and rollback;
- hardware diversity beyond one host plus frequency sweeps;
- either arm64 data or a very explicit x86-only claim.

### Is micro-benchmark evidence sufficient for a systems paper?

No.

Microbenchmarks are necessary here because they isolate mechanism and causality. They are not sufficient because the external-validity problem is severe:

- the project itself notes the micro suite covers only a tiny fraction of the real corpus feature space;
- the intended novelty is operational policy ownership, not merely instruction-level speedups;
- the strongest "why userspace" arguments are about deployment, workload, and fleet behavior, none of which microbenchmarks capture.

Without real workloads, the paper reads like a compiler microbenchmark paper with kernel plumbing.

### What end-to-end evaluation is needed?

At minimum:

- one real datapath workload such as Cilium or Katran;
- real traffic or replayed trace traffic;
- versioned program replacement rather than just `BPF_PROG_TEST_RUN`;
- shared pinned maps across old/new versions;
- actual measurement of throughput/latency plus rollout/rollback behavior.

If the paper claims fleet policy, the evaluation has to leave the toy-loader world.

### How would you demonstrate the "fleet A/B testing" story?

Do not hand-wave it. Run it.

Concrete demonstration:

1. choose one real deployment-like program;
2. define two policy versions, for example fixed-kernel-like vs userspace-guided;
3. canary the new version on a subset of nodes or processes;
4. collect acceptance/rejection telemetry and performance counters;
5. show rollback is just program/link replacement, not service disruption;
6. show the policy update happened without kernel changes.

Without this, "fleet A/B testing" is just a slogan.

### What about overhead measurement?

This is currently under-specified and mandatory.

You need:

- blob size distribution;
- parse time;
- digest time;
- remap time;
- validator time per directive kind;
- logging overhead when enabled;
- extra memory retained per program;
- load-time slowdown relative to stock `BPF_PROG_LOAD`;
- rejection/drop rates in real workloads.

If the interface adds noticeable load-time complexity, reviewers will ask whether the operational cost is worth the marginal gain over kernel peepholes.

## 5. The "Why Not Just..." Questions

### Why not just submit kernel patches for `wide_load` and `cmov`?

For `wide_load`, that is the default reviewer conclusion today. It looks like a kernel patch.

For `cmov`, the answer could be better:

- if profitability really varies by CPU/workload/program, userspace policy is defensible;
- but you have not shown that fixed kernel heuristics fail badly enough.

So the honest answer is:

- `wide_load` should probably be a kernel patch regardless;
- `cmov_select` may justify a policy split, but only if evaluation proves kernel-fixed policy is materially worse.

### Why not just use llvmbpf/LLVM JIT instead of kernel JIT?

This is the strongest alternative.

Honest answer:

- if your environment can use llvmbpf as the execution backend, that is simpler and already recovers many backend gaps;
- your system only matters if the deployment must keep the kernel JIT path for correctness, integration, or operational reasons;
- the paper therefore has to argue for preserving the kernel JIT model while importing deployment-specific profitability policy.

If that argument stays weak, reviewers will prefer llvmbpf.

### Why not extend BPF bytecode with `BPF_SELECT` or `BPF_WIDE_LOAD`?

This is a serious competitor, especially if the set of useful transforms stays small.

The best answer is:

- new bytecodes permanently change the ISA, compiler pipeline, verifier semantics, and portability story;
- directives are less invasive because they encode optional backend choices over already-legal semantics;
- directives also allow deployment-specific selection without forcing every compiler and every kernel to understand new semantic ops.

That said, if the paper only ends up needing two or three recurring idioms, reviewers may still prefer a bytecode extension or plain kernel peepholes over a new side-channel ABI.

### Why not use compiler hints or BTF annotations?

Compiler hints are weaker because they live too early:

- they do not see the exact finalized post-CO-RE image;
- they do not know the eventual workload class;
- they do not help with fleet rollout or post-deployment policy changes.

That is the right answer.

But again, for simple cases like `wide_load`, early hints may be enough. The paper survives only if the important cases really need deployment-time policy.

### Why not use PGO feedback via perf/AutoFDO?

This is the right conceptual competitor for layout and branch profitability.

The honest answer is:

- PGO/AutoFDO already solve a similar policy problem in ordinary compiler pipelines;
- your contribution is not "PGO is impossible," but "the kernel JIT lacks a safe, bounded mechanism to consume deployment-specific backend policy";
- if fixed kernel heuristics plus profile feedback are enough, your interface loses.

So this question is not a dismissal. It is a real bar you have to clear.

## 6. Paper Structure Suggestion

### What goes in the abstract?

The abstract should say exactly four things:

1. kernel eBPF JITs leave significant backend performance on the table relative to better backends;
2. some missed backend decisions have stable legality but deployment-specific profitability;
3. you introduce a fail-closed kernel/userspace split where the kernel validates bounded directives and userspace owns policy;
4. userspace-guided policy beats fixed kernel baselines on real workloads while preserving safety and manageable load-time overhead.

If sentence 4 cannot be supported, do not submit.

### What are the key figures/tables?

You need these figures:

1. one motivating figure showing kernel JIT vs llvmbpf gap and where it comes from;
2. one architecture figure showing legality plane vs policy plane;
3. one directive lifecycle figure: finalized image -> blob -> verifier remap -> adopt/reject;
4. one table separating policy-sensitive directives from substrate/kernel-like directives;
5. one result figure showing userspace-guided vs fixed-kernel baselines across CPU/workload/program combinations;
6. one end-to-end deployment figure or table showing canary rollout, acceptance, performance, and rollback.

### What is the evaluation methodology?

Use three layers:

1. mechanism isolation
   - microbenchmarks for `wide_load`, `cmov_select`, and the third family.
2. external validity
   - real-program corpus acceptance census, code-size effects, multi-function programs.
3. systems validation
   - one real deployment with rollout and telemetry.

Measure:

- runtime/throughput;
- code size;
- acceptance/rejection/drop rates;
- load-time overhead;
- PMU counters where relevant;
- operational rollout behavior.

## 7. Overall Verdict

### Current readiness: 4/10 for OSDI/SOSP

Why so low:

- the framing is smarter than the actual demonstrated mechanism;
- the current x86 JIT structure only clearly supports local peephole-like rewrites;
- the strongest alternative explanations are still alive: kernel peepholes, llvmbpf, bytecode extensions, PGO-style heuristics;
- the decisive experiments do not exist yet;
- Path A vs Path B is unresolved, which means the paper does not yet know what system it is actually building.

This is a strong research direction. It is not close to an OSDI/SOSP submission today.

### What would get it to 8/10?

You need all of the following:

- settle Path A vs Path B;
- implement the mechanism you actually plan to defend;
- add one third directive family that is truly policy-sensitive, not just another kernel peephole;
- run fixed-kernel baselines and show they lose in meaningful cases;
- run one real end-to-end deployment evaluation;
- quantify load-time overhead and rejection/drop behavior;
- either merge with the characterization story or deeply inline that evidence into the paper.

### What would get it to 10/10?

To be a real OSDI/SOSP contender, the paper would need:

- a tight, minimal mechanism whose scope matches its claim;
- decisive evidence that userspace policy beats kernel-fixed policy on real workloads;
- a deployment story that works with pinned programs, shared maps, and rollback;
- strong real-program coverage;
- either a second architecture or a very compelling reason why x86-only is enough;
- a clear answer to "why not llvmbpf?" that reviewers accept.

That is a high bar. Right now the project is below it.

### Is the two-paper strategy correct, or should it be one paper?

As a work plan, two papers is correct.

As a top-tier submission strategy, one paper is probably correct unless the optimization paper becomes much stronger than it is now.

The characterization already does most of the motivational heavy lifting. Without that evidence, the interface paper looks too narrow. With it, the story becomes coherent:

- characterize the gap;
- identify which parts are policy-sensitive;
- build the legality/profitability split;
- validate it in deployment.

That is the OSDI/SOSP arc.

### Is the Path A vs Path B decision critical for submission?

Absolutely. It is probably the most critical design decision in the project.

If Path A wins:

- the mechanism is implementable sooner;
- but the paper is likely narrower and much more vulnerable to the "just add peepholes to the kernel" critique.

If Path B wins:

- the paper can support non-local transforms and a stronger novelty story;
- but the implementation risk and security/TCB burden go up sharply.

If this decision is unresolved, the paper is not submission-ready. You cannot submit a systems paper while still undecided about which system actually exists.

## Final Assessment

This is not a mediocre paper. It is currently a potentially good paper trapped in an unresolved contribution boundary.

The design docs are smart enough to know the danger:

- they already admit `wide_load` alone does not justify the interface;
- they already admit fixed kernel policies are the mandatory falsifier;
- they already admit the x86 JIT structure may only support local rewrites.

That honesty is a strength. But it also means the current verdict is straightforward:

If you submit now, reviewers will say the framing is stronger than the evidence, the mechanism is narrower than the claim, and the simpler alternatives have not been ruled out.

That is a reject.
