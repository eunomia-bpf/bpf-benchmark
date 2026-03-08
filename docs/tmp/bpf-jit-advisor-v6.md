# Userspace-Guided Backend Optimization for eBPF JITs (BPF JIT Advisor v6)

## 1. Executive Thesis

The v5r2 design is **implementation-ready**, but it is still **paper-thin** for OSDI/SOSP if the story remains "two directives (`wide_load` and `cmov_select`) plus some transport and validation machinery."

That is not the right contribution boundary.

The stronger thesis is:

> eBPF JIT optimization should be split into a stable **kernel legality plane** and an updateable **userspace backend policy plane**. The kernel validates and safely adopts bounded backend directives tied to one finalized BPF image; privileged userspace decides which directives to request based on CPU profile, workload profile, program shape, code-size budget, and fleet policy. The contribution is not any one peephole. The contribution is the mechanism/policy split, the fail-closed legality substrate, and the evidence that profitable backend decisions vary across programs, workloads, and hardware.

Under this thesis:

- `wide_load` is a **substrate exercise** and a strong baseline-recovery case, but not the paper's novelty anchor;
- `cmov_select` is a **real userspace-policy case**, but by itself it is too narrow to carry an OSDI/SOSP story;
- the paper becomes strong only when it combines:
  1. backend characterization evidence,
  2. a fail-closed kernel/userspace split,
  3. multiple directive families with different policy reasons,
  4. real deployment and evaluation evidence.

## 2. Honest Assessment of v5r2

### 2.1 What Is Actually Novel

The parts with real systems novelty are:

1. **The mechanism/policy split**
   - kernel owns legality;
   - userspace owns profitability;
   - the split matches how production BPF systems are deployed.

2. **A fail-closed backend-policy substrate**
   - digest binding to one finalized pre-verifier image;
   - verifier rewrite remap via preserved `orig_idx`;
   - retained legality facts for JIT consumption;
   - exact per-kind validators;
   - shared logging, CPU gating, and fallback.

3. **Deployment control**
   - the optimization owner is a privileged loader or service agent such as Cilium/Katran userspace control software, not kernel maintainers shipping hard-coded heuristics for every fleet.

4. **Characterization-driven policy diversity**
   - the same verified site can want different lowerings on different CPUs or different workload classes.

### 2.2 What Is Incremental

The parts that are useful but not, by themselves, OSDI/SOSP-level are:

- `wide_load` as a standalone optimization;
- `cmov_select` as a standalone optimization;
- the validator template as a code-organization device;
- arch-specific emitters for local rewrites;
- any claim that this is a generic compiler substrate.

### 2.3 Bottom-Line Verdict

If the prototype remains **x86 + `wide_load` + `cmov_select` only**, the likely reviewer reaction is:

> "Interesting prototype, but this still looks like one real policy-sensitive optimization (`cmov`) plus one kernel peephole (`wide_load`) with extra plumbing."

That is good enough for implementation, and maybe for a narrower venue. It is **not yet enough** for a top-tier systems paper.

## 3. Recommended Paper Framing

### 3.1 Strongest Story

The strongest story is **not** "JIT advisor."

The strongest story is:

> **Userspace-guided backend optimization for eBPF JITs**

This says exactly what the system does:

- not a full compiler replacement;
- not free-form native-code injection;
- not merely a bag of hints;
- a bounded mechanism for guiding backend lowering.

### 3.2 Candidate Framings

| Framing | Verdict | Why |
| --- | --- | --- |
| `BPF JIT Advisor` | too weak as a paper title | sounds like optional hints and peepholes |
| `Compiler-as-a-Service for eBPF` | too broad and misleading | overclaims; the kernel still compiles and owns legality |
| `Microarchitecture-Aware eBPF Backend Optimization` | incomplete | captures hardware sensitivity, but misses deployment/updateability/control-plane value |
| **`Userspace-Guided Backend Optimization for eBPF JITs`** | **strongest** | matches the mechanism/policy split and the systems deployment model |

Recommended paper title:

> **From Characterization to Control: Userspace-Guided Backend Optimization for eBPF JITs**

### 3.3 Should This Be Combined with the Characterization Paper?

**Yes, probably.**

The current optimization paper depends too heavily on characterization evidence that already does most of the intellectual setup:

- llvmbpf/kernel exec-time geomean is `0.849x`;
- code-size geomean is `0.496x`;
- byte-recompose is `50.7%` of measured instruction surplus;
- isolated byte-recompose penalty is `2.24x`;
- LLVM emits `31` `cmov` instructions where the kernel emits `0`;
- real-program code-size validation already exists for `162` paired instances (`36` unique).

If the optimization paper is separate, it risks feeling like:

> "We characterized some backend gaps earlier; now we built a narrow advisory interface for two of them."

The stronger version is a single arc:

1. characterize the gap;
2. show that the gap is backend-local and partly policy-sensitive;
3. argue that fixed kernel heuristics are the wrong owner for some of these decisions;
4. build a mechanism/policy split;
5. demonstrate the split with concrete directives and deployment evidence.

If the papers stay separate, then the second paper needs a stronger prototype than v5r2:

- at least one additional policy-sensitive directive family beyond `cmov_select`;
- real multi-function program evidence;
- end-to-end deployment evaluation.

## 4. What the Real Contribution Should Be

The paper should explicitly say:

> This work is not about proving that every backend optimization belongs in userspace. It is about identifying the subset of backend decisions whose legality is stable and kernel-local, but whose profitability is deployment-specific and therefore belongs in userspace policy.

That immediately changes the contribution boundary.

### 4.1 Three Pieces That Must Appear Together

| Piece | Why it matters | If missing |
| --- | --- | --- |
| Characterization | proves the gaps are real and identifies candidate decisions | the system looks unmotivated |
| Legality substrate | makes userspace-guided lowering safe and fail-closed | the system looks unsound |
| Policy-sensitive directives | prove this is not just a transport for kernel peepholes | the paper looks incremental |

The framework alone is not enough.

The individual optimizations alone are not enough.

The publishable systems contribution is the **combination**.

## 5. System Model

### 5.1 Control Plane vs Data Plane

The key architectural change from v5r2 is conceptual:

- the kernel JIT is the **backend execution plane**;
- the userspace advisor is the **backend policy plane**.

That matches production deployment:

- Cilium already has a privileged agent that finalizes and loads BPF programs;
- Katran-style systems already have userspace control software choosing program versions and rollout policy;
- those components can own optimization policy far more naturally than the upstream kernel can.

### 5.2 Division of Responsibility

| Kernel owns | Userspace owns |
| --- | --- |
| digest binding | candidate discovery |
| verifier execution | CPU/workload policy |
| `orig_idx` preservation and remap | fleet policy DB |
| retained legality facts | A/B rollout and rollback |
| exact validator checks | program-specific code-size / latency budgets |
| native emission | offline characterization and training |
| fail-closed fallback | policy versioning |
| logging of accepts/rejects | per-service deployment choice |

This is the real systems split. It is not only about microarchitecture.

### 5.3 Why Userspace Policy Is Valuable Beyond Microarchitecture

The "why not just kernel peepholes?" answer must be broader than "some CPUs like `cmov` more than others."

Userspace policy is justified by **five** independent reasons:

1. **Updateability**
   - a userspace policy DB can change weekly;
   - a kernel heuristic table changes only with kernel upgrades.

2. **Program-specific composition**
   - a locally profitable transform may be globally harmful if a program is already close to an I-cache or code-size cliff;
   - userspace can budget directives across the whole program.

3. **Workload adaptation**
   - branch predictability and hotness depend on live traffic and data distribution, not just ISA features.

4. **Fleet management and A/B testing**
   - operators can roll out policy version `17` to 5% of machines, compare counters, then rollback without touching the kernel.

5. **Ownership**
   - service owners already own performance tuning for their BPF deployments;
   - kernel maintainers should not own every per-service backend heuristic.

Microarchitecture sensitivity is important, but it is only one part of the argument.

## 6. End-to-End Architecture

The transport/remap/validator mechanics from v5r2 remain the right low-level design. What changes in v6 is the end-to-end story and the feedback loop.

```text
finalized pre-verifier BPF image
  -> userspace backend-policy engine
       - discover candidate sites
       - extract site features
       - attach optional workload profile
       - consult CPU + fleet policy DB
       - emit bounded directive blob
       - bind policy_id / workload_class / site_ids
  -> BPF_PROG_LOAD(jit_directives_fd=fd)
  -> kernel
       - parse sealed blob
       - check digest and CPU contract
       - run verifier normally
       - preserve orig_idx through rewrites
       - retain only facts needed by requested directive kinds
       - remap directive ranges post-verifier
       - run exact kind-specific validators
       - emit native fused sequences or reject per site
       - fail closed to stock JIT on any failure
       - log accepted/rejected site_ids and reasons
  -> userspace telemetry / rollout system
       - aggregate acceptance
       - correlate with runtime / PMU / application SLOs
       - update policy DB
```

Two details matter here and should be explicit in the paper:

- the advisor runs **after CO-RE relocation and subprogram finalization**, on the exact image passed to `BPF_PROG_LOAD`;
- logging is part of the system story, not just debugging. It enables canaries, policy rollback, and fleet-wide tuning.

## 7. Concrete End-to-End Examples

### 7.1 Example A: `wide_load` on `load_byte_recompose`

Source-level kernel:

```c
u64 value = micro_read_u64_le(data, 8 + i * 8U);
acc += value;
acc ^= value >> (i & 15U);
```

Actual BPF region in `load_byte_recompose.bpf.o`:

```c
r1 = *(u8 *)(r0 - 0x3)
r1 <<= 0x20
r4 = *(u8 *)(r0 - 0x5)
r4 <<= 0x10
r4 |= r1
r5 = *(u8 *)(r0 - 0x4)
r5 <<= 0x18
r1 = *(u8 *)(r0 - 0x6)
r1 <<= 0x8
r1 |= r5
r1 |= r4
r4 = *(u8 *)(r0 - 0x2)
r4 <<= 0x28
r1 |= r4
r4 = *(u8 *)(r0 + 0x0)
r4 <<= 0x38
r5 = *(u8 *)(r0 - 0x1)
r5 <<= 0x30
r5 |= r4
r1 |= r5
r4 = *(u8 *)(r0 - 0x7)
r1 |= r4
```

Userspace candidate extraction:

```text
kind           = wide_load
site shape     = 8 byte loads from one base register with constant offsets [-7, 0]
mem class      = map value
liveout        = r1
required facts = nonfaulting, const offset, min_readable >= 8
```

Userspace policy decision:

```text
if cpu_profile == wide_ooo_x86:
    accept width=8 with min_align_log2=0 or 3 depending on policy
elif cpu_profile == small_core_x86:
    accept only when align_log2 >= 3
else:
    reject
```

Example directive record:

```text
wide_load {
  site_id         = 17
  orig_range      = [30, 52)
  width           = 8
  mem_class       = MAP_VALUE
  base_reg        = r0
  base_off        = -7
  liveout_reg     = r1
  min_align_log2  = 3
}
```

Kernel validation path:

1. verifier preserves `orig_idx` across rewrites;
2. retained memory fact proves `MAP_VALUE`, `CONST_OFFSET`, `NONFAULTING`, `min_readable >= 8`, and an alignment lower bound;
3. remap confirms the region is contiguous post-verifier;
4. exact validator confirms one base, one offset ladder, one liveout, and no side effects;
5. x86 emitter replaces the ladder with one native load.

Stock x86 lowering today is byte-recompose. Representative native sequence:

```asm
movzbq -0x3(%rax), %r13
shl    $0x20, %r13
...
movzbq 0x0(%rax), %r8
shl    $0x38, %r8
or     %r8, %r14
```

Guided lowering:

```asm
mov    -0x7(%rax), %r14
```

What this example proves:

- the legality substrate can safely consume retained verifier facts;
- the same transport/remap machinery works for local fused emission;
- `wide_load` is useful, but this example still looks like a kernel peephole unless the paper connects it to the broader policy plane.

### 7.2 Example B: `cmov_select` on `binary_search`

Source-level kernel:

```c
if (found) {
    acc += index;
} else {
    acc ^= target + BINARY_SEARCH_MAX_DATA_LEN;
}
```

What the advisor sees conceptually:

```text
miss_value = acc ^ (target + 32)
hit_value  = acc + index
next_acc   = found ? hit_value : miss_value
```

Userspace site features:

```text
kind                  = cmov_select
value width           = 64
compare source        = found flag
true value shape      = reg+reg arithmetic
false value shape     = reg xor (reg+imm)
workload feature      = branch predictability bucket
```

Policy decision:

```text
if cpu_profile == wide_ooo_x86 and workload_predictability == unpredictable:
    accept cmov_select
elif workload_predictability == predictable:
    reject
elif cpu_profile == small_core_x86:
    reject
```

Example directive:

```text
cmov_select {
  site_id       = 42
  orig_range    = [153, 158)
  condition     = (found == 0)
  dst_reg       = acc
  true_val      = miss_value
  false_val     = hit_value
  width         = 64
}
```

Stock kernel lowering keeps the select as a control diamond.

Guided x86 lowering can produce the branchless select already seen in llvmbpf-style code:

```asm
add    $0x20, %rdi      ; miss_value = target + 32
xor    %rdx, %rdi       ; miss_value ^= acc
add    %r8, %rdx        ; hit_value = acc + index
test   %r11b, %r11b     ; found?
cmove  %rdi, %rdx       ; choose miss_value when !found
```

What this example proves:

- the profitable lowering depends on input predictability, not just legality;
- the right owner of that decision is userspace policy;
- the same verified site may want different lowerings on different machines or workloads.

### 7.3 Example C: Future `hot_fallthrough` on `branch_layout`

This is the most important missing example in v5r2, because it demonstrates a second userspace-worthy directive family.

Characterization already shows that `branch_layout` changes materially with input distribution:

- predictable input: `0.225x` llvmbpf/kernel;
- random input: `0.326x`;
- ratio delta: `44.6%`.

That is exactly the kind of case where a fixed kernel heuristic is the wrong owner.

A future directive family could be:

```text
hot_fallthrough {
  site_id          = 91
  orig_range       = [entry, join)
  preferred_arm    = true
  allow_inversion  = yes
  max_dup_insns    = 4
}
```

The point is not arbitrary block scheduling. The point is a bounded, validated one-diamond layout choice whose profitability depends on workload and code-size budget.

This family is a better second novelty carrier than `wide_load`.

## 8. Expanded Directive Inventory

The paper needs a broader directive inventory, but it must be honest about which directives actually belong in userspace.

### 8.1 Strong Userspace-Policy Families

| Directive family | Why it needs userspace policy | Example evidence | v6 status |
| --- | --- | --- | --- |
| **`cmov_select`** | depends on branch predictability, dependency depth, and CPU family; same legal site can want different lowerings | `binary_search`, `switch_dispatch`, no-cmov ablation, `31` vs `0` `cmov` | prototype |
| **`hot_fallthrough` / `branch_layout`** | depends on workload hotness, input distribution, code-size budget, and frontend behavior | `branch_layout` predictable vs random differs by `44.6%`; branch-heavy kernels show large gaps | **should be added** |
| **`subprog_inline` / call-boundary policy** | depends on hotness, code-size budget, I-cache pressure, and multi-function structure; best choice varies by deployment | real-program corpus is `97.2%` multi-function while the original authoritative suite has `0%` multi-function coverage; `local_call_fanout` provisional result is ~`0.72x` | future, but highly compelling |

These are the directive families that make this a systems contribution rather than a peephole collection.

### 8.2 Shared-Substrate but Mostly Kernel-First Families

| Directive family | Honest assessment | Why it does not carry the paper |
| --- | --- | --- |
| `wide_load` | valuable substrate exercise; mostly a kernel peephole | legality is verifier-sensitive, but profitability is usually local and weakly policy-dependent |
| `wide_store` | useful for code size; probably kernel-first | mostly fixed-overhead cleanup, little workload sensitivity |
| `rotate_fusion` | local idiom recognition | good peephole, weak systems story |
| `lea_fusion` | local arithmetic combine | classic backend peephole, weak userspace case |

These should appear in the paper as:

- evidence that the substrate can host multiple local transforms;
- examples of where the right end state may still be direct kernel optimization.

That honesty improves credibility.

### 8.3 Directive Ideas That Should **Not** Be the Focus

| Idea | Why it is a bad directive fit |
| --- | --- |
| register-allocation hints | too backend-internal, too unstable across JIT revisions, too target-specific |
| instruction-scheduling hints | difficult to validate, weak evidence of payoff in this JIT, poor abstraction boundary |
| arbitrary native snippets | destroys the safety story |
| target-independent replacement IR | returns to the v4 problem: heavy kernel equivalence machinery |

The right abstraction level is **bounded backend decisions**, not "remote-control the whole compiler backend."

## 9. Why This Is Not Just Kernel Peepholes

The v5r2 answer was directionally right but too narrow. v6 should argue at four levels.

### 9.1 Some Things Really Are Just Peepholes

The paper should say this explicitly:

- `wide_load` alone does **not** justify a new interface;
- `wide_store`, `rotate_fusion`, and `lea_fusion` probably do **not** justify a new interface either.

This is not a weakness. It is necessary honesty.

### 9.2 The Interface Is for Policy-Sensitive Decisions

The userspace-guided interface is justified when:

1. legality can be validated locally by the kernel;
2. multiple legal lowerings exist;
3. the best lowering depends on deployment-specific information the kernel should not own.

That is true for:

- `cmov_select`;
- `hot_fallthrough` / branch layout;
- call-boundary/inlining policy.

### 9.3 The Kernel Is the Wrong Place for Fleet Heuristics

A kernel-local heuristic table would eventually need rules like:

- "use `cmov` on CPU class A only for unpredictability bucket X;"
- "invert this diamond only when workload class is 90/10 hot/cold and code-size budget permits duplication;"
- "inline this subprog only for deployment profiles that prioritize latency over I-cache footprint."

That is exactly the kind of policy that should live in privileged userspace:

- easier to update;
- easier to canary;
- easier to roll back;
- easier to tailor per service.

### 9.4 The Real Competitor Is Not Only Peepholes, but Verifier-Assisted JIT

Review feedback is right that another strong alternative is:

> verifier computes legality summaries, kernel JIT consumes them, userspace is optional.

That is the right baseline architecture to beat on safety grounds.

The userspace-guided design only wins if it shows benefits that verifier-assisted kernel-only policy cannot provide easily:

- deployment-specific rollout;
- workload adaptation;
- fleet-level policy management;
- faster iteration than kernel heuristics;
- cleaner separation between stable legality and changing profitability.

### 9.5 Mandatory Falsification Condition

The paper must say this explicitly:

> If fixed kernel policies recover the same gains across the tested hardware and workloads, then the correct conclusion is "use kernel peepholes or kernel-only verifier-assisted JIT," not "ship the userspace-guided interface."

That makes the claim falsifiable and more credible.

## 10. Recommended Prototype Scope for a Top-Tier Submission

### 10.1 Minimum Scope That Looks Publishable

For OSDI/SOSP, the minimum convincing scope is:

- x86-64 prototype;
- automated userspace directive generation;
- same v5r2 transport/remap/fail-closed substrate;
- `wide_load`;
- `cmov_select`;
- **one more policy-sensitive family**, preferably `hot_fallthrough`, secondarily `subprog_inline`;
- real-program acceptance census;
- at least one end-to-end deployment evaluation.

### 10.2 What Stays Out of Scope

- arbitrary native-code injection;
- target-independent replacement IR;
- scheduling hints;
- register-allocation hints;
- constant-blinding compatibility in v1;
- heterogeneous per-core selection in the kernel.

### 10.3 If Only `wide_load` + `cmov_select` Ship

Then the paper should either:

1. be merged with the characterization paper; or
2. be retargeted as a narrower systems/compiler paper, not an OSDI/SOSP bet.

## 11. Evaluation Plan for OSDI/SOSP

The evaluation must answer reviewer questions, not just show speedups.

### 11.1 Required Baselines

1. stock kernel JIT;
2. `kernel-wide-load`;
3. `kernel-fixed-cmov`;
4. `kernel-fixed-layout` or `kernel-fixed-inline` for the third family;
5. `advisor-static` (CPU DB only);
6. `advisor-profiled` (CPU DB + workload profile);
7. llvmbpf as an upper bound.

### 11.2 Required Questions

1. **Does userspace policy actually differ across hardware, workloads, and programs?**
2. **Do those differences outperform fixed kernel heuristics anywhere meaningful?**
3. **How often does the legality substrate accept directives on real programs?**
4. **Does the system generalize beyond one novelty-carrying optimization?**
5. **Can operators manage policy safely in a production-like deployment?**

### 11.3 Required Workloads

#### Mechanism-Isolation Microbenchmarks

- `load_byte_recompose`
- `binary_search`
- `switch_dispatch`
- `branch_layout`

These remain necessary for causal clarity.

#### Stronger Policy-Sensitivity Benchmarks

- `packet_rss_hash`
  - provisional signal is strong (`~0.47x`);
  - combines field extraction with arithmetic.
- `local_call_fanout`
  - provisional signal is meaningful (`~0.72x`);
  - directly stresses the multi-function gap missing from the current suite.
- `packet_parse_vlans_tcpopts`
  - useful for variable-length parsing and branch/layout sensitivity.
- `branch_fanout_32`
  - stronger branch-layout stress than constant-return `switch_dispatch`.
- `mega_basic_block_2048`
  - useful for code-size budget and I-cache-cliff effects.

#### Real Programs

The paper should use the existing real-program corpus more aggressively:

- `162` paired instances (`36` unique) for acceptance and code-size evidence;
- per-program candidate counts and acceptance rates by directive kind;
- explicit reporting of which pointer/memory classes accept `wide_load`;
- multi-function acceptance results, since the corpus is overwhelmingly multi-function while the original authoritative suite is not.

This is mandatory because the current microbenchmark suite only covers about `0.8%` of the observed 5D feature box in the real-program corpus. The microbenchmarks are good for mechanism isolation, but they cannot carry external-validity claims by themselves.

#### End-to-End Deployments

At least one of these is needed:

- Cilium datapath path with real packet traffic;
- Katran-style XDP load balancer;
- another production-like BPF deployment with an actual privileged control process.

This is also where the paper should escape the `BPF_PROG_TEST_RUN` limitation, which structurally biases execution-time validation toward packet-oriented program types. Without this, the paper still reads like a compiler microbenchmark study plus kernel plumbing.

### 11.4 Required Hardware Diversity

The current frequency sweep is useful but not sufficient.

A stronger evaluation needs:

1. one modern wide OoO x86 core;
2. one smaller-core or Atom-like x86 system;
3. ideally one arm64 system.

Frequency changes on one host can support the story, but should not substitute for real hardware diversity.

### 11.5 Required Metrics

Primary metrics:

- runtime / throughput;
- native code size;
- accepted directives per kind;
- remap rejection rate;
- validator rejection rate;
- compile/load overhead;
- branch-miss and IPC deltas where relevant.

Operational metrics:

- time to update policy without kernel change;
- A/B rollout overhead;
- fleet acceptance / rejection telemetry;
- rollback behavior.

These operational metrics are part of the systems story.

### 11.6 What "Generalization" Should Mean

The paper should **not** claim:

- "we support arbitrary backend optimization."

It should claim:

> the substrate generalizes across a small family of bounded backend decisions with different legality sources and different profitability owners.

That is a much more defensible form of generality.

## 12. Cross-Architecture Positioning

The arch-neutral/arch-specific split from v5r2 is still correct:

- shared blob format;
- shared remap;
- shared retained facts;
- shared validator logic;
- arch-specific emitter only.

But the paper should be careful:

- if only x86 is implemented, the paper is an x86 prototype with an arch-neutral design;
- do not oversell arm64 unless there is at least one real emitter or a strong analysis track.

The best top-tier version would include:

- x86 full prototype;
- arm64 acceptance census using the same userspace discovery and shared validators;
- ideally one real arm64 emitter for either `wide_load` or `cmov_select`.

If that cannot be built, then arm64 should remain clearly future work.

## 13. Honest Novelty Statement

The paper should have a section that says, in substance:

### Novel

- separating backend legality from backend profitability for eBPF JITs;
- making that separation concrete with a fail-closed kernel substrate;
- placing profitability policy in privileged userspace where deployment owners can update and test it;
- showing that some profitable lowerings differ by CPU, workload, and program.

### Incremental

- each individual peephole optimization;
- the x86 emitter code itself;
- the directive template as a software-engineering convenience;
- any claim that this is a general optimizer IR.

This section will make the paper stronger, not weaker.

## 14. Final Recommendation

### 14.1 What v6 Should Claim

v6 should claim:

> We introduce a userspace-guided backend-policy substrate for eBPF JITs, driven by characterization evidence and designed for production deployment. The kernel owns legality and fail-closed adoption; userspace owns profitability, rollout, and policy evolution.

### 14.2 What v6 Should Not Claim

v6 should not claim:

- that `wide_load` and `cmov_select` alone justify a new interface;
- that this is a generic compiler service;
- that every backend optimization belongs in userspace;
- that x86-only evidence proves cross-architecture value.

### 14.3 Go / No-Go Guidance

**Go for OSDI/SOSP only if all of the following are true:**

1. the paper is merged with, or deeply incorporates, the characterization results;
2. the prototype includes at least one additional policy-sensitive directive family beyond `cmov_select`;
3. the evaluation includes real multi-function programs and at least one end-to-end deployment;
4. fixed kernel baselines do not recover the same gains everywhere.

**Otherwise:**

- implement v5r2/v6 as a strong research prototype;
- publish the characterization separately;
- and treat the interface paper as follow-on work once the third directive family and deployment evidence exist.

## 15. Bottom Line

v5r2 found the right mechanism.

v6 changes the paper claim:

- the contribution is **not** "two peepholes with extra plumbing";
- the contribution is a **backend policy plane** for eBPF JITs;
- the most important missing step is to add a second truly policy-sensitive family such as `hot_fallthrough` or `subprog_inline`;
- the strongest publication path is to join the characterization and optimization stories into one end-to-end systems argument.

That is the version that has a plausible OSDI/SOSP thesis.
