# Review of `interface-design-detail.md`

## Executive Summary

This is a good ABI draft for a **narrow v1**: load-time only, fail-closed, x86-first, with userspace choosing profitability and the kernel choosing legality. It is much more concrete than v6 on syscall shape, blob versioning, digest binding, CPU gating, and telemetry.

It is **not** yet a complete or internally consistent implementation spec for the broader design set in this repo.

The biggest problem is not the wire format. The biggest problem is that the document writes as if the mechanism choice is already settled and the JIT pipeline is a clean “verify, remap, emit/fallback” flow. The other documents and the kernel analysis say that is not true:

- the x86 JIT is a convergence loop plus final image pass, not a simple two-pass backend;
- `jit_subprogs()` means multi-function programs do not have one simple post-verifier, pre-JIT handoff point;
- `addrs[]` semantics are central for any fused directive and completely absent from the interface doc;
- the repo still has an unresolved Path A vs Path B decision, while this document hard-codes the JIT-level path as if that decision were over.

My bottom line: **good draft, not ready to implement from as written**.

## 1. Consistency Check

### 1.1 Mechanism/policy split

At the top level, yes: the interface document is consistent with v6's intended split.

- Userspace chooses candidates and policy.
- The kernel owns digest binding, legality, remap, validation, and fail-closed fallback.
- The design stays bounded, load-time only, and non-extensible-by-default.

That part is aligned with v6 and the hub doc.

The inconsistency is scope, not philosophy.

- `interface-design-detail.md` is effectively a **v5r2-style narrow v1** document. It defines only `wide_load` and `cmov_select` payloads, and everything about the blob format assumes local single-region directives.
- `bpf-jit-advisor-v6.md` and `kernel-jit-optimization-plan.md` still lean on a stronger story that needs a third policy-sensitive family such as `hot_fallthrough` / `branch_reorder` or `subprog_inline`.
- The hub doc explicitly says Path A vs Path B is still unresolved and that `branch_reorder` depends on that decision. This interface doc ignores that and proceeds as if JIT-level consumption is settled.

So the answer is:

- **Yes** on the core legality/profitability split.
- **No** on consistency with the current repo-level scope story.

If this document is meant to define **v1 = JIT-level `wide_load` + narrow `cmov_select` only**, it needs to say that explicitly and stop pretending to be the settled interface for the broader v6 paper scope.

### 1.2 Handling v6-review constraints

It handles some of them, but not all.

Handled reasonably:

- `orig_idx` remap is kept as the core coordinate bridge.
- Constant blinding is treated as incompatible in v1 and causes whole-blob drop.
- The design stays local and single-image, which matches the JIT analysis better than the more ambitious v6 prose.

Not handled adequately:

- The document does not account for the **actual x86 pass model**. It never states that directive plans must be fixed before the convergence loop and consumed identically on every dry pass and the final image pass.
- It never defines the `addrs[]` rule for fused regions, even though the JIT analysis says that is the main correctness constraint.
- It describes “per-site remap/validation/emission failure: reject only that site, emit stock code for that region” as if emission failure were always recoverable. On x86, once a plan is being consumed inside the converged pass machinery, a late length mismatch is a backend bug, not a graceful per-site fallback.

This is the main technical gap in the whole document.

### 1.3 Blob format vs v5r2 validator template model

Mostly compatible, but only for the narrow v5r2 directive set.

What is consistent:

- original-coordinate ranges per site;
- one exact pre-verifier digest;
- per-site kind/version/payload;
- CPU contract plus per-site feature masks;
- non-overlapping local regions;
- shared `precond_mask`.

What is not true is the stronger implicit claim that the blob format itself captures the full validator contract.

It does not. v5r2 still needs kernel-side state that is intentionally out of band:

- post-verifier `orig_idx` remap;
- retained memory facts;
- CFG/single-entry-single-exit checks;
- `zext_dst` handling for ALU32 cases;
- the `addrs[]` invariant for collapsed regions.

That is acceptable, but the document should say so clearly. Right now it reads too much like “the blob fully describes legality,” which is false.

There are also two real field-level mismatches with v5r2:

- `wide_load.base_off` is signed in v5r2 but written as `__le16` in the interface doc. Negative stack offsets are implicit instead of explicit.
- `bpf_jit_value_ref.imm` is signed in v5r2 but written as `__le32` in the interface doc. Negative immediates are again implicit.

Those are fixable, but they are real mismatches, not style issues.

### 1.4 Contradictions between documents

There are several.

1. v5r2 says v1 is `wide_load` + narrow `cmov_select`; v6 and the hub doc push for a third policy-sensitive family. The interface doc silently follows v5r2.

2. v6's `cmov_select` example is richer than both v5r2 and the interface payload. The payload supports reg/imm values. The example describes expression-valued arms. Those are not the same directive.

3. The hub doc says the implementation path is still unresolved. The interface doc behaves as though JIT-level path selection is already final.

4. The load skeleton in `interface-design-detail.md` is not consistent with the real kernel pipeline for multi-subprogram programs. It omits `bpf_prog_select_runtime()` and pretends directive finalization happens after verifier and before JIT in one clean step. That is not what the actual pipeline does.

## 2. Feasibility Against JIT Constraints

### 2.1 Does the interface account for `do_jit()` being a convergence loop?

No, not really.

This is the most important feasibility miss.

The interface doc describes a conceptual sequence:

1. parse blob
2. verify digest/CPU
3. run verifier
4. remap
5. validate
6. emit or fallback

That is too abstract to be implementation-safe on x86.

What the JIT analysis actually requires is:

- remap and legality validation must produce a **stable per-site plan** before JIT pass consumption;
- that plan must be stored in a place like `prog->aux`;
- every dry pass and the final image pass must consume the **same plan** and therefore emit the **same lengths**;
- acceptance/rejection should be decided once, before pass-loop consumption, not dynamically per pass.

The interface doc never says this. Without it, the design sounds simpler than the real backend is.

### 2.2 `orig_idx` remap vs pass-count changes

Conceptually, `orig_idx` remap is orthogonal to pass count. Remap is a verifier/post-verifier issue, not a branch-shortening-pass issue.

But the document misses the practical consequence:

- remap must produce a stable plan over the final post-verifier BPF stream;
- that plan must not be re-derived opportunistically inside `do_jit()`;
- otherwise pass-to-pass differences can break convergence.

There is another omission here: the doc relies on `orig_idx` remap but does not restate the required verifier surgery from v5r2 and the JIT analysis.

That surgery is not optional:

- inserted verifier patchlets must inherit `orig_idx`;
- removal paths must allow ranges to become empty or non-contiguous and reject them;
- `wide_load` still needs retained memory facts and, realistically, post-rewrite CFG/liveness rebuilding or equivalent propagation.

So the interface doc is directionally correct on `orig_idx`, but not complete enough to be standalone.

### 2.3 `addrs[]` complications for fused instructions

The blob design is only acceptable here because v1 is still implicitly limited to fused local directives.

For `wide_load` and narrow `cmov_select`, the kernel can use the standard fused-region rule:

- all covered BPF instructions share one native start address;
- `addrs[end]` points to the first uncovered native boundary;
- external edges into the interior are forbidden.

The interface doc never says this.

That omission matters for three reasons:

1. `addrs[]` has two consumers, not one. Insn-array mapping and line info use it differently.

2. The meaning of `BPF_JIT_PC_NO_INTERIOR_TARGET` is not purely abstract. It is what makes collapsed `addrs[]` legal.

3. Any future directive involving duplication or real block reordering needs a canonical-PC rule. The current blob format and result model have nothing to say about that.

So the answer is:

- **For narrow fused v1 directives:** the blob design is acceptable but underspecified.
- **For future layout-changing directives:** no, the design does not handle this at all.

### 2.4 Constant blinding: whole-blob drop vs partial compatibility

For v1, whole-blob drop is the right call.

This is one of the better choices in the document.

Why it is right:

- blinding runs after verifier completion and before x86 JIT emission;
- it clones and rewrites the program outside the normal verifier aux-data propagation path;
- any aux-based directive metadata would otherwise drift or disappear;
- pretending partial compatibility is easy would be a serious mistake.

Where the document is still weak:

- it treats this as a routine non-fatal whole-blob drop, but operationally it is a **major feature cutoff**;
- any environment that insists on blinding gets no advisor at all;
- that should be presented as a real deployment limitation, not as a minor footnote.

On partial compatibility:

- in theory, unaffected sites could be salvaged if directive state were copied into a separate side structure and revalidated on the blinded clone;
- in practice, that is future work and the current doc should not imply otherwise.

## 3. Security Gaps

### 3.1 Is `CAP_BPF + CAP_PERFMON` the right privilege level?

It is defensible for a prototype, but not convincingly justified yet as a permanent UAPI boundary.

What is good about it:

- it clearly rejects any idea that this is an unprivileged hint mechanism;
- it frames the feature as privileged performance steering, which is correct.

What is weak:

- the document does not tie this choice tightly enough to the existing kernel permission matrix for `BPF_PROG_LOAD`;
- `CAP_PERFMON` is thematically plausible, but the argument is still “closest existing capability boundary,” which is not a strong UAPI argument;
- the BPF token story is hand-wavy: the document invents a new delegated permission bit, but the current token model is organized around delegated commands/maps/programs/attach types and namespace capability checks, not arbitrary per-feature bits.

My view:

- for a research prototype, `CAP_BPF + CAP_PERFMON` is acceptable;
- for a real upstreamable UAPI, the permission model needs a tighter argument and a more realistic token integration design.

### 3.2 Attack vectors the security analysis missed

The document covers parser/validator bugs and side-channel shape changes in general terms, but it misses several concrete surfaces.

1. It does not analyze the additional attack surface created by **multi-subprog state handling**. Any real implementation will need directive slicing/copying through `jit_subprogs()`, which is not mentioned.

2. It treats “correct native code with different timing/speculation behavior” as categorically acceptable because the loader is privileged. That is too relaxed. A privileged loader can still accidentally turn a semantically correct program into a timing-sensitive one.

3. It does not discuss access control for the proposed structured results in `bpf_prog_info`. In practice that probably follows normal prog-fd ownership rules, but it should be stated.

4. It does not analyze how mixed-loader or fleet-service deployments affect trust boundaries. A central advisor that sees finalized program images is a new high-trust component, not just a convenience library.

### 3.3 Memfd sealing vs simpler approaches

The `memfd` design is clever, but I do not think it is the simplest correct design.

A simpler alternative is:

- `__aligned_u64 jit_directives`
- `__u32 jit_directives_len`
- kernel copies the blob once at syscall entry, just like instructions and logs

That would still give:

- kernel-owned immutable snapshot for the rest of the load;
- no pathname or lifetime issues;
- no memfd-specific boilerplate;
- no seal verification logic.

`memfd` is not wrong. It is just not obviously worth the complexity for a load-time-only object that the kernel immediately copies and detaches from.

If the project keeps `memfd`, it should justify it in terms stronger than “seals are queryable.”

### 3.4 Correct but timing-vulnerable code

The document underestimates this case.

`cmov_select` and future layout directives can absolutely produce code that is:

- semantically correct;
- verifier-safe;
- still worse from a timing-side-channel or constant-time perspective.

Saying “the loader is privileged, so timing changes are allowed” is not sufficient.

At minimum, the design should do one of these:

- explicitly declare constant-time or side-channel-sensitive BPF programs out of scope;
- add a program-level opt-out bit for directive use;
- or require the advisor to be disabled for sensitive program classes.

Right now the security analysis treats semantic equivalence as the only relevant safety property. That is too narrow.

## 4. Deployment Realism

### 4.1 Cilium scenario and atomic link replacement

This is only partially realistic.

`bpf_link_update(..., BPF_F_REPLACE)` is real, but it is not a universal “BPF programs can always be atomically swapped” primitive. It depends on:

- using link-based attachment;
- the specific link type implementing `update_prog`;
- the deployment not still relying on legacy attachment paths.

So the current wording is too broad.

The scenario becomes realistic if it is narrowed to:

- deployments that already use link-based attach points with `update_prog` support; or
- deployments willing to build attach-specific rollout logic.

As written, it reads like a generic Cilium truth. It is not.

### 4.2 Retry-without-directives on `E2BIG`

This is plausible, but too optimistic and too overloaded.

What is true:

- on older kernels, passing a larger `bpf_attr` with non-zero tail can indeed yield `E2BIG`;
- so retry-once is a reasonable compatibility tactic.

What is not okay:

- the same document also uses `E2BIG` for “blob length is 0 or exceeds 64 KiB”;
- `E2BIG` is used elsewhere in BPF for real load failures;
- a blind retry can therefore hide genuine advisory bugs or oversize-blob problems and silently degrade to stock loading.

This needs cleanup.

Two reasonable fixes:

1. reserve `E2BIG` for old-kernel / UAPI-negotiation style failures and use another errno for oversize blob; or
2. keep the errno set but make retry conditional on a more reliable capability probe than “saw `E2BIG` once.”

As written, the fallback policy is too coarse.

### 4.3 JSON policy DB for fleet management

JSON is fine for v1 experiments and test artifacts. It is not a serious fleet-management answer.

What JSON is good at:

- human editing;
- diffs;
- embedding in tests;
- bootstrapping.

What it is weak at:

- schema evolution discipline;
- signatures and provenance;
- rollout metadata;
- queryability and auditability at fleet scale;
- stable packaging and distribution.

For production-like fleet management, I would expect at least one of:

- a signed versioned artifact format;
- protobuf/flatbuffer/capnproto style schema;
- SQLite or equivalent local DB;
- or a central service-backed policy API.

This is not a kernel ABI issue, but the deployment section currently oversells JSON as if it were enough.

### 4.4 Mixed loaders and exact-image generation

The deployment story is still too centralized and too clean.

Because the blob is bound to the exact finalized pre-verifier image:

- the loader that creates that image must also create the blob, or hand that image to a directive-aware sidecar;
- semantically “same” source programs built or finalized differently will not share blobs;
- policy distribution alone is not enough; exact-image generation has to be directive-aware everywhere.

v6-review called this out, and the interface document still does not really absorb it.

## 5. Missing Pieces

### 5.1 `jit_subprogs()` and multi-function programs

This is the biggest missing implementation piece.

The blob format includes `subprog_id`, so the document knows multi-function programs matter. But it never specifies:

- when remap happens relative to `jit_subprogs()`;
- how directive state is sliced/copied into per-subprog `struct bpf_prog`s;
- how per-subprog results are aggregated back into one `bpf_prog_info` view;
- how subprogram recompilation and extra passes interact with directive telemetry.

Given the actual kernel pipeline, this is not optional detail. It is core mechanism.

### 5.2 Directive interaction rules

The document assumes independent, non-overlapping sites and stops there.

Missing:

- conflict resolution beyond overlap rejection;
- dependency ordering;
- whether one accepted directive can invalidate another site's retained facts;
- how the kernel reports “rejected because an earlier directive fired”;
- whether userspace must fully pre-resolve all interactions.

For v1 with only non-overlapping `wide_load` and narrow `cmov_select`, this may stay simple. But the document should say that explicitly.

### 5.3 Feature discovery and compatibility probing

The doc relies too heavily on “try load, see errno, retry.”

Missing:

- how userspace learns supported blob ABI major/minor;
- how it learns supported directive kinds;
- how it learns whether structured `jit_dir_results` are available;
- how `bpftool` or libraries do capability probing without ambiguous errno heuristics.

This is not fatal for a prototype, but it is missing.

### 5.4 BPF arena, token, and recent subsystem additions

`BPF arena`

- The current mem-class enum excludes arena, and that is correct for v1.
- But the interface doc should say so explicitly.
- Arena loads are not “just another pointer class”; they are rewritten into special probe forms with extable metadata and `r12`-based addressing. Silent omission is not enough.

`BPF token`

- The token section is too hand-wavy.
- It proposes a new delegated permission bit without grounding it in the existing token model.
- This needs a real design, not an example name.

Other recent additions

- The document does not say anything about private-stack mode implications, exception callbacks, tail-call poke sites, or other backend modes that materially affect addressability and safe region selection.
- Some of these are probably kernel-internal exclusions, but the detailed design should name them.

### 5.5 Path B: verifier-level rewrites

If the project switches to verifier-level rewrites, this interface only partly survives.

What probably survives:

- load-time transport idea;
- digest binding to exact pre-verifier image;
- CPU contract fields;
- policy/version/workload tagging;
- structured telemetry idea.

What does not survive cleanly:

- the whole “JIT directives” framing;
- JIT-specific reason codes such as `EMIT_FAILED`;
- “JIT disabled or offloaded -> drop blob” semantics;
- arch-specific per-site feature gating as currently phrased;
- the assumption that the last stage is emitter adoption/fallback.

So the answer is:

- **the transport skeleton could survive**;
- **the current semantics would need major rewriting**.

That is another reason the repo should not treat this document as fully settled while Path A vs Path B is still open.

## 6. Comparison with v5r2 Mechanism

### 6.1 Does the blob format support all v5r2 validator needs?

It supports the **user-supplied parameters** for the current v5r2 validators.

That means:

- `wide_load`: yes;
- narrow `cmov_select`: yes.

It does **not** support the full validator contract by itself, because v5r2 was never designed that way. Kernel-side validation still needs:

- remap;
- retained facts;
- CFG checks;
- side-effect checks;
- `zext_dst`;
- `addrs[]`-compatible single-entry semantics.

That is fine, but it should be stated more explicitly.

### 6.2 Missing features from v5r2

Compared with v5r2, the interface document is weaker on several correctness-critical details:

- it does not restate the exact `orig_idx` propagation rule;
- it does not restate the `addrs[]` collapse rule for fused regions;
- it does not restate the ALU32 / zero-extension details for `cmov_select`;
- it does not restate big-endian rejection or exact byte-order constraints for `wide_load`;
- it does not restate x86 temp-register and flag-discipline issues for `cmov_select`;
- it does not mention the likely need for post-rewrite metadata rebuild for liveness/CFG-sensitive checks.

Those were not “nice to have” details in v5r2. They were part of why v5r2 was implementation-ready.

### 6.3 What the interface doc improves over v5r2

It does improve several real things:

- much better blob versioning story;
- explicit endian handling;
- cleaner header/section layout;
- more concrete telemetry/result APIs;
- better loader and deployment discussion;
- clearer CPU contract structure.

So this is not a regression overall. It is an ABI refinement layered on top of a weaker mechanism discussion.

### 6.4 Features missing from interface design, or vice versa

Missing in interface design:

- explicit tie-back from precondition bits to `addrs[]` semantics;
- explicit statement that v1 is only local single-region lowerings;
- explicit unsupported classes such as arena and other special fault-handled paths;
- explicit multi-subprog handling.

Added in interface design:

- memfd transport and sealing;
- structured `bpf_prog_info` reporting;
- more formal CPU/workload/policy tagging;
- richer forward-compatibility machinery.

The additions are useful. The omissions are more serious.

## 7. Overall Assessment

### Score: 6/10

This is good enough to preserve as the basis of a narrow v1 ABI draft.

It is not good enough to treat as the implementation spec for the current repo-wide design without another revision.

### Top 3 strengths

1. It makes the ABI concrete. Syscall fields, blob layout, digest binding, CPU contract, and telemetry are described at a level that can actually be discussed and implemented.

2. It preserves the right high-level split. Userspace profitability vs kernel legality remains the right design center.

3. It is disciplined about fail-closed behavior and avoids the worst forms of API creep such as arbitrary code injection, runtime mutation, or post-load attach.

### Top 3 weaknesses

1. It is written against an oversimplified kernel pipeline. The actual `jit_subprogs()` flow, convergence-loop JIT, and `addrs[]` constraints are not integrated into the design.

2. It is inconsistent with the rest of the repo on scope. It quietly narrows back to v5r2 while v6 and the hub doc still talk like the broader mechanism question is open and the third-family story matters.

3. Its deployment and compatibility story is too optimistic. `E2BIG` fallback, Cilium atomic replacement, JSON fleet policy, and token delegation are all presented more cleanly than reality warrants.

### Recommended changes before implementation

1. Make the scope explicit: either say “v1 is JIT-level `wide_load` + narrow `cmov_select` only” or stop pretending this interface is already the settled answer for `branch_reorder` / `subprog_inline`.

2. Rewrite the sequencing section around the real kernel pipeline:
   `bpf_prog_load()` -> verifier -> `jit_subprogs()` implications -> `bpf_prog_select_runtime()` -> possible blinding -> x86 convergence passes -> final image pass.

3. Add the missing JIT-consumption contract explicitly:
   stable prevalidated plan, identical pass consumption, non-recoverable late-pass mismatches, and exact `addrs[]` semantics for fused regions.

4. Add a real multi-subprog section:
   how `subprog_id` sites are stored, remapped, sliced/copied, emitted, and reported.

5. Fix the wire-format signedness mismatches:
   signed `base_off`, signed `imm`.

6. Clean up compatibility probing:
   do not rely on ambiguous `E2BIG` retry logic alone.

7. Either justify `memfd` more strongly or simplify the transport to pointer+length.

8. Explicitly blacklist or defer arena, probe/extable-heavy accesses, tail-call poke regions, exception boundaries, and any other special backend modes that v1 will not support.

9. State clearly how much of this survives a future Path B verifier-rewrite pivot, and what would need to change.

## Final Recommendation

Do **not** proceed straight to implementation from `interface-design-detail.md` as written.

Proceed only after one more design revision that does two things:

1. narrows and states the actual v1 scope; and
2. rewrites the mechanism sections so they match the real kernel pipeline rather than the idealized one.

If that revision is done, this can become a solid v1 interface spec.
