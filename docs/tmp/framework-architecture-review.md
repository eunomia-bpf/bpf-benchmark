# BPF JIT Policy Framework Architecture Review

Date: 2026-03-10
Scope: `docs/kernel-jit-optimization-plan.md`, `docs/tmp/jit-pass-framework-v4-design.md`, `docs/tmp/jit-pass-framework-v5-design.md`, kernel framework code in `vendor/linux-framework/`, benchmark scanner path in `micro/runner/src/kernel_runner.cpp`, and extracted scanner framework in `scanner/`.

## Executive Summary

The current implementation is a credible **v4 prototype**: the kernel owns legality checks and native emission, userspace owns site discovery and policy choice, and the x86 JIT hook is small enough to be believable as a Linux-facing mechanism. The main weakness is that the code still implements a **closed-enum, pattern-specific v4 substrate**, while the paper narrative in the source-of-truth docs has already moved to **v5 declarative patterns + canonical lowering**.

Architecturally, the kernel/userspace split is clean in concept but not yet clean in the codebase. The kernel side is one substrate; the userspace side is split across two parallel implementations (`micro/runner` and `scanner/`), with duplicated scanners, duplicated UAPI constants, and a policy engine that is directionally right but still mostly scaffolding.

If this were framed as "a prototype v4 mechanism with preliminary policy tooling," it is solid. If framed as "the submission-ready framework described in the docs," it is not there yet.

## Architecture Diagram

```text
Current implementation

Userspace policy plane
  +---------------------------------------------------------------+
  | Path A: micro/runner                                           |
  |   - scan xlated BPF with imperative family-specific matchers   |
  |   - build fixed-size v4 policy blob                            |
  |   - call BPF_PROG_JIT_RECOMPILE                                |
  |                                                               |
  | Path B: scanner/                                               |
  |   - C scanners (same matcher logic, re-extracted)              |
  |   - C++ PolicyEngine (registry, heuristics, YAML overrides)    |
  |   - build same fixed-size v4 policy blob                       |
  +-------------------------------+-------------------------------+
                                  |
                                  v
Kernel legality plane
  +---------------------------------------------------------------+
  | jit_directives.c                                               |
  |   - parse sealed memfd blob                                    |
  |   - bind to prog_tag / insn_cnt / arch                         |
  |   - generic checks: bounds, side effects, cpu features         |
  |   - exact family validators: cond_select / wide_mem / rotate / |
  |     addr_calc                                                  |
  |   - attach validated rule array to prog                        |
  +-------------------------------+-------------------------------+
                                  |
                                  v
Arch-specific lowering
  +---------------------------------------------------------------+
  | x86 do_jit()                                                   |
  |   - lookup rule at current site_start                          |
  |   - dispatch to family-specific emitter                        |
  |   - otherwise fall back to stock emission                      |
  +---------------------------------------------------------------+

Key gap vs v5
  Current: userspace picks among fixed rule kinds; kernel hardcodes pattern matchers.
  v5 goal: userspace supplies declarative patterns; kernel owns canonical lowerings.
```

## Strengths

- The core mechanism/policy split is real. Userspace selects candidate sites and desired lowerings; the kernel still owns validation and emits native code itself. This is visible in `vendor/linux-framework/kernel/bpf/jit_directives.c` and the single JIT dispatch hook in `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2598-2649`.
- The transport hardening is directionally correct for a prototype: sealed memfd check, blob size cap, `insn_cnt` binding, `prog_tag` binding, and per-rule fail-closed activation (`vendor/linux-framework/kernel/bpf/jit_directives.c:31-41`, `1449-1580`).
- The x86 emitter integration is intentionally narrow. Four family-specific emitters behind `bpf_jit_try_emit_rule()` are much easier to reason about than a second compiler pipeline (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2429-2509`).
- The project has already demonstrated multiple directive families and composed wins, which matters for the paper story in `docs/kernel-jit-optimization-plan.md`.
- `scanner/` has a sensible high-level decomposition: `scan()`, `decide()`, `materialize()`. The basic unit tests pass (`ctest --test-dir scanner/build`).

## Top 10 Issues Ranked By Severity

1. **Critical: kernel bounds checks are overflow-prone.** The kernel repeatedly validates `site_start + site_len` without overflow protection before dereferencing instructions (`vendor/linux-framework/kernel/bpf/jit_directives.c:618-624`, `702-708`, `806-812`, `917-924`, `1121-1129`, `1284-1289`, `1370-1372`, `1573-1574`). A malicious large `site_start` can wrap and bypass checks.

2. **Critical: CPU legality is partly delegated to userspace.** `native_choice` drives emission, but feature legality is only checked if userspace supplied `cpu_features_required` (`vendor/linux-framework/kernel/bpf/jit_directives.c:1374-1378`; `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2280-2303`). For example, `RORX` can be requested with `cpu_features_required=0`, which breaks the "kernel legality plane" claim.

3. **Critical: re-JIT is not implemented as a transactional/serialized operation.** `bpf_prog_jit_recompile()` swaps policy state directly and calls `bpf_int_jit_compile(prog)` with no visible concurrency protocol in this layer (`vendor/linux-framework/kernel/bpf/jit_directives.c:1714-1733`). That may be acceptable for a benchmark POC, but not for a submission-ready framework claim.

4. **High: overlap and priority semantics are underspecified and incorrectly implemented in-kernel.** The API exposes `priority`, but the parser does not reject or arbitrate general overlaps, and `bpf_jit_rule_lookup()` only returns a rule when `insn_idx == site_start` (`vendor/linux-framework/kernel/bpf/jit_directives.c:477-492`, `1611-1638`). This does not implement the documented "higher wins on overlap" behavior.

5. **High: the current implementation still hardcodes pattern recognition in the kernel, so extensibility is much weaker than the paper story.** Each new variant needs new C validator code, as seen with `bpf_jit_validate_wide_mem_high_first()` and `bpf_jit_validate_rotate_6insn()` (`vendor/linux-framework/kernel/bpf/jit_directives.c:692-739`, `1114-1223`). This is exactly the scaling problem v5 is trying to solve.

6. **High: the shipped UAPI is materially weaker than the v4 design doc.** The design calls for `log_level/log_buf/log_size` and extensible rule payloads, but the actual `jit_recompile` attr and `bpf_jit_rewrite_rule` are much narrower (`vendor/linux-framework/include/uapi/linux/bpf.h:1526-1533`, `2030-2034`; compare `docs/tmp/jit-pass-framework-v4-design.md`). This weakens the iterative-policy and observability story.

7. **Medium-High: the userspace policy plane is fragmented into two implementations.** `micro/runner/src/kernel_runner.cpp:495-1047` still contains the original scanners and blob builder, while `scanner/src/scanner.cpp` explicitly says it is a re-extraction of that logic (`scanner/src/scanner.cpp:5-7`). This duplication will drift, and it already obscures which userspace layer is authoritative.

8. **Medium: scanner framework v2 is directionally well-designed, but its policy engine is still mostly placeholder logic.** The registry/engine/materialize split is good, but decisions are driven by simple static heuristics and a stub profile hook (`scanner/src/engine.cpp:440-484`, `807-888`). This is not yet the evidence-backed CPU/workload policy plane claimed in the docs.

9. **Medium: multi-subprogram support is not architecturally coherent.** Userspace comments imply the full translated program can be scanned (`micro/runner/src/kernel_runner.cpp:1389-1395`), but the kernel still deactivates non-main-subprog rules (`vendor/linux-framework/kernel/bpf/jit_directives.c:1568-1574`). That weakens claims about general program-level re-JIT, especially since real corpora are heavily multi-function.

10. **Medium: userspace UAPI duplication is brittle and leaks prototype assumptions.** `micro/runner` and `scanner/src/cli.cpp` both hardcode `BPF_PROG_JIT_RECOMPILE = 39` and duplicate rule constants instead of sharing a generated or vendored authoritative header (`micro/runner/src/kernel_runner.cpp:61-96`; `scanner/src/cli.cpp:55-57`; `scanner/include/bpf_jit_scanner/types.h:44-125`). This is manageable in a private fork, but weak for a submission-ready artifact.

## Kernel/Userspace Split Assessment

Conceptually, the split is good: userspace finds sites and proposes lowerings; the kernel re-validates exact BPF shapes and emits native code itself. That is the right boundary for a safe prototype.

In codebase terms, the split is not fully clean. The kernel side is one framework, but the userspace side is split between a benchmark-specific path and an extracted library/CLI. The result is that the "policy plane" exists twice, with duplicated scanners and duplicated blob/UAPI knowledge. Submission-ready code should have exactly one authoritative userspace frontend.

## Extensibility Assessment

### Current v4 implementation

Adding a **new directive family** is currently moderate-to-hard:

1. Add new UAPI enum values and native choices in `include/uapi/linux/bpf.h`.
2. Add a new kernel-internal `rule_kind` path and validator in `jit_directives.c`.
3. Add a new x86 emitter and dispatcher case in `bpf_jit_comp.c`.
4. Add a new userspace scanner in both `micro/runner` and `scanner/` unless the duplication is removed.
5. Add policy-engine naming/config plumbing and tests.

Adding a **new pattern variant inside an existing family** is also expensive, because pattern recognition still lives in kernel C code. That is the biggest architectural limit.

### Gap to v5

The code is still at v4's abstraction level:

- No variable-length v5 blob parser.
- No declarative pattern descriptions or constraint language.
- No generic matcher.
- No canonical-form abstraction.
- Emitters still re-parse BPF instructions instead of accepting canonical parameters.

This gap is not cosmetic. It is the difference between "new compiler idiom requires a kernel patch" and "new compiler idiom is just userspace data." Right now the code supports the former, not the latter.

## Scanner Framework v2 Assessment

`scanner/` is **not fundamentally over-engineered**, but it is ahead of the rest of the implementation.

What is good:

- Keeping low-level C scanners and a higher-level C++ engine is a reasonable layering.
- `PatternRegistry`, `PolicyEngine`, and `materialize()` are the right seams if the policy plane will grow.
- The library/CLI extraction is the correct direction and has basic test coverage.

What is premature or incomplete:

- The engine is not yet the authoritative userspace layer because `micro/runner` still duplicates the core logic.
- The decision logic is mostly a placeholder heuristic, not a measured policy substrate.
- The YAML parser is intentionally tiny, which is fine for a prototype, but not yet a convincing deployment control plane.

My verdict: **well-shaped, mildly over-built for the current v4 code, but worth keeping**. It becomes the right amount of engineering once it replaces `kernel_runner` as the only userspace policy frontend and once decisions are grounded in real profile/CPU data.

## Security Assessment

### What is working

- Userspace cannot inject native code; the kernel emits instructions.
- Exact validators plus digest binding make it hard for honest userspace to mis-target a rule.
- The fail-closed per-rule activation model is good.

### What is insufficient

- The overflowable bounds checks are a real kernel bug, not just a prototype limitation.
- CPU legality must be derived in-kernel from `native_choice`; otherwise privileged userspace can request illegal instructions.
- Overlap handling is undefined enough that the kernel should reject overlapping active rules until it has correct arbitration.
- The re-JIT path lacks the synchronization and transactionality needed for a stronger safety claim.

Bottom line: the validator model is **mostly sufficient against accidental misuse**, but **not yet strong enough against adversarial privileged userspace**.

## Paper-Readiness Score

**4/10**

Why not lower:

- The core v4 mechanism exists in code.
- There are multiple directive families, real performance data, and a believable mechanism/policy split.
- The extracted scanner framework shows the right long-term direction.

Why not higher:

- The implementation does not yet match the v5 paper story that the source-of-truth docs now emphasize.
- The userspace policy layer is still fragmented and only lightly policy-driven.
- The kernel still has submission-blocking correctness/security gaps.
- The interface lacks the observability needed for the iterative-policy story.
- The implementation is x86-only and effectively main-subprog-only.

This is strong enough for "prototype with promising results," not strong enough for "submission-ready framework implementation."

## Concrete Recommendations For Next Steps

1. **Fix the kernel hard blockers first.** Add overflow-safe bounds validation, derive CPU legality from `native_choice`, reject overlapping active rules, and serialize/transactionalize `BPF_PROG_JIT_RECOMPILE`.
2. **Make `scanner/` authoritative.** Delete or wrap the duplicated scanners/blob builder in `micro/runner` so there is one userspace policy implementation.
3. **Align the UAPI with the claimed workflow.** At minimum, add a real feedback channel (`log_level`, `log_buf`, `log_size`) so userspace can observe accept/reject decisions without relying on `pr_debug`.
4. **Resolve the paper framing explicitly.** Either:
   - submit an honest v4 story and present v5 as future work, or
   - implement a minimal v5 path in code for one or two canonical forms so the paper claims match the artifact.
5. **Choose one extensibility story and prove it.** If staying on v4, measure and report the real code cost of adding new variants. If moving to v5, prioritize the generic matcher and canonical emitter interface.
6. **Make policy decisions data-driven.** Replace the placeholder static heuristics in `scanner/src/engine.cpp` with decisions backed by the existing benchmark/ablation results and actual CPU feature detection.
7. **Close the subprog gap.** Either support subprog-aware re-JIT end to end or narrow the scope in code, tooling, and paper text. Right now the implementation and comments diverge.
8. **Remove x86-only overclaiming.** Either add at least one minimal arm64 backend slice or rewrite the evaluation/architecture text so x86-only is explicit.
9. **Add end-to-end observability and reproducibility.** The paper needs a clear load -> scan -> decide -> re-JIT -> measure loop that a reviewer can reproduce from the artifact.
10. **Before submission, rerun the review after one architecture simplification.** The biggest structural risk is claiming v5 while shipping v4. Fix that mismatch first, then do another review.

