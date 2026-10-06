# P89H multi-subprog ReJIT candidate review

## Verdict

Overall severity: **HIGH**.

`bad918ea` and `858ddd97` do not remove a live BPF program from the whole ReJIT pipeline, but they do add pass-level, program-wide guards that skip every kinsn candidate in a multi-subprog program before candidate scanning. Under `CLAUDE.md`'s no-filtering/fail-fast rules and the additional review constraint that site-level skips are already a bad smell, these two commits should be treated as policy violations that hide the root cause.

`6708d2a1` is different: it fixes endian stack-offset encoding and does not add multi-subprog filtering.

## Reference rules

- `CLAUDE.md:5-10`: no BPF program may be filtered, skipped, or excluded from ReJIT; ReJIT failures must surface naturally.
- `CLAUDE.md:29-33`: no fallback, no silenced errors, and no hidden downgrade path.
- `CLAUDE.md:35-40`: tests should detect bugs, not codify tautological or policy-avoidance behavior.
- `docs/tmp/bpfopt_design_v3.md:94-99`: no optimizable site is normal, but bytecode/side-input errors must exit 1 and failures must not be silent.
- `docs/tmp/bpfopt_design_v3.md:410-440`: the per-pass verify loop verifies only when a pass changes bytecode; a no-change skip avoids verification.
- `docs/kernel-jit-optimization-plan.md:159-169`: verify failure should return an error and the suite operates on full replacement bytecode.
- `docs/kernel-jit-optimization-plan.md:370-379`: structured per-pass records are the intended externally visible facts.

## Commit bad918ea: bulk_memory

Commit: `bad918ea fix(kinsn/bulk_memory): avoid multi-subprog rejit candidates`

Level: **PASS**.

Skip condition:

- `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:110-118` returns `PassResult::unchanged` when `func_info_record_count(program)? > 1`.
- `bpfopt/crates/bpfopt/src/passes/utils.rs:114-132` defines that helper as a raw `func_info` record count. The condition is therefore "program has more than one func_info record", not "this candidate crosses a subprog boundary".
- The guard runs before the normal scan at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:124-128`, so no bulk-memory site is inspected.

Skipped side effect:

- The pass records one internal `SkipReason` with fake `pc: 0` at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:111-116`.
- This is not an error, and it is not a distinct `not_applicable` result. `PassResult::unchanged` sets `changed=false` and `sites_applied=0` at `bpfopt/crates/bpfopt/src/pass.rs:567-575`.
- `PassManager` still continues later passes at `bpfopt/crates/bpfopt/src/pass.rs:987-999`, so the program is not removed from the whole pipeline. Other passes may still rewrite and the final program may still be ReJITed.
- Externally, the skip is effectively silent because `PassReport` has no `sites_skipped`/reason field at `bpfopt/crates/bpfopt/src/main.rs:215-225`, and `pass_report()` serializes only changed/site/count/map fields at `bpfopt/crates/bpfopt/src/main.rs:1233-1246`.

Site-level validity assessment:

- This is not a site-level validity check. A valid site-level check would run after `scan_sites`, attach the skip to the specific candidate pc, and reject only a candidate whose replacement would cross a subprog boundary or place a kinsn call at a subprog entry.
- Existing site checks in this pass already operate at candidate granularity, for example different-base alias safety and missing packed ABI at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:133-177`.
- The test added by the commit codifies the broad skip by asserting no program change, zero applied sites, a `multi-subprog` skip, and no kinsn call at `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:349-365`.

Finding:

- **HIGH**. This is not a literal whole-program ReJIT exclusion, but it is a program-scoped pass filter. It hides every bulk-memory optimization opportunity in multi-subprog programs and converts a supposed ReJIT/verifier failure into an unchanged pass result.

## Commit 858ddd97: extract

Commit: `858ddd97 fix(kinsn/extract): avoid multi-subprog rejit candidates`

Level: **PASS**.

Skip condition:

- `bpfopt/crates/bpfopt/src/passes/extract.rs:114-122` returns `PassResult::unchanged` when `func_info_record_count(program)? > 1`.
- The helper added in the same commit is `bpfopt/crates/bpfopt/src/passes/utils.rs:114-132`; it checks only the count of `func_info` records.
- The guard runs before kfunc availability, branch-target analysis, and candidate scanning at `bpfopt/crates/bpfopt/src/passes/extract.rs:124-151`.

Skipped side effect:

- The pass records one internal `SkipReason` with `pc: 0` at `bpfopt/crates/bpfopt/src/passes/extract.rs:115-120`.
- It is an unchanged pass, not an error. `PassResult::unchanged` is `changed=false` and `sites_applied=0` at `bpfopt/crates/bpfopt/src/pass.rs:567-575`.
- Later passes still run because `PassManager` pushes the result and continues at `bpfopt/crates/bpfopt/src/pass.rs:987-999`.
- The reason does not reach the CLI report because `PassReport` omits skip reasons at `bpfopt/crates/bpfopt/src/main.rs:215-225` and `pass_report()` drops `sites_skipped` at `bpfopt/crates/bpfopt/src/main.rs:1233-1246`.

Site-level validity assessment:

- This is not a site-level validity check. It skips all extract candidates in any multi-subprog program without proving that a candidate spans subprogs or that the kinsn sidecar/call pair would be invalid.
- The pass already has a candidate-local branch-target check at `bpfopt/crates/bpfopt/src/passes/extract.rs:153-166`; multi-subprog safety belongs in that style of candidate-local validation if it is truly required.
- The test added by the commit asserts the broad skip and absence of kinsn calls at `bpfopt/crates/bpfopt/src/passes/extract.rs:416-441`; it does not prove the root cause is fixed.

Finding:

- **HIGH**. Same issue as `bad918ea`: it is a pass-level, program-wide skip keyed only on multi-subprog metadata. It avoids candidate generation and verification instead of fixing or precisely rejecting the unsafe site.

## Commit 6708d2a1: endian

Commit: `6708d2a1 fix(kinsn/endian): encode stack offsets directly`

Level: **SITE/TRANSFORM**, not a multi-subprog skip.

Skip condition:

- No multi-subprog guard is added.
- The change removes the x86 stack-address materialization exception and allows direct offset encoding whenever `offset_is_directly_encodable()` says the target can encode the offset at `bpfopt/crates/bpfopt/src/passes/endian.rs:135-148` and `bpfopt/crates/bpfopt/src/passes/endian.rs:151-177`.
- The remaining endian pass skips are unrelated capability/site checks: missing endian kfuncs or packed ABI at `bpfopt/crates/bpfopt/src/passes/endian.rs:224-255`, and candidate-local kfunc/branch/packed checks at `bpfopt/crates/bpfopt/src/passes/endian.rs:257-315`.

Skipped side effect:

- None for multi-subprog. The commit changes emitted bytecode for stack loads rather than suppressing candidates.
- The new test asserts a direct sidecar payload for `r10,-88` and a three-insn output at `bpfopt/crates/bpfopt/src/passes/endian.rs:653-673`.

Site-level validity assessment:

- This is a direct root-cause fix: preserve the original stack base and offset in the kinsn payload when x86 can encode it, instead of growing the replacement into address-materialization instructions.

Finding:

- **NONE**. This commit does not violate `No ReJIT Filtering` or `Fail-Fast`.

## Root cause 是否可修

The bulk/extract root cause appears fixable. The current evidence points to missing precision in kinsn candidate/subprog handling, not an inherent inability to optimize every multi-subprog program.

Evidence:

- The kernel verifier explicitly rejects one concrete invalid layout: a pseudo kinsn call whose immediately preceding sidecar would be in a different subprog. It nulls the sidecar when the call pc is a subprog start at `vendor/linux-framework/kernel/bpf/verifier.c:3755-3768`.
- The same verifier later rejects `func_info` that no longer matches subprog layout at `vendor/linux-framework/kernel/bpf/verifier.c:19543-19549`.
- Verification order is `check_btf_info_early`, `add_subprog_and_kfunc`, `lower_kinsn_proof_regions`, `check_subprogs`, then `check_btf_info` at `vendor/linux-framework/kernel/bpf/verifier.c:26406-26434`, so kinsn proof lowering can affect the layout that `func_info` must match.
- The REJIT syscall submits replacement insns and fd array, not a full fresh userspace BTF/func_info payload, at `bpfopt/crates/kernel-sys/src/lib.rs:1356-1381` and `vendor/linux-framework/kernel/bpf/syscall.c:3636-3645`. Normal programs do not get the EXT-only copied func_info setup at `vendor/linux-framework/kernel/bpf/syscall.c:3718-3754`.
- The forked kernel already has multi-subprog swap/layout support in scope: `bpf_prog_rejit_swap()` swaps `func_info`, `func_info_cnt`, `func`, `func_cnt`, and `real_func_cnt` at `vendor/linux-framework/kernel/bpf/syscall.c:3397-3407` and `vendor/linux-framework/kernel/bpf/syscall.c:3433-3444`; the plan also lists "multi-subprog layout match" as REJIT syscall responsibility at `docs/kernel-jit-optimization-plan.md:350-358` and the `rejit-v2` branch as supporting multi-subprog at `docs/kernel-jit-optimization-plan.md:696-700`.
- User-space already has the pieces for precise validation. `BranchTargetAnalysis` marks BPF-to-BPF pseudo-call targets at `bpfopt/crates/bpfopt/src/analysis/branch_target.rs:36-42`; `CFGAnalysis` collects pseudo-call and pseudo-func entries as subprog entries at `bpfopt/crates/bpfopt/src/analysis/cfg.rs:45-64`; `kinsn_proof_subprog_starts()` already adjusts subprog starts for proof-region expansion and rejects a kinsn call at a subprog start at `bpfopt/crates/bpfopt/src/passes/utils.rs:237-272`.

Conclusion:

- A specific site that would split sidecar and call across a subprog boundary truly should not be transformed. That is a legitimate site-level validity rejection with a precise pc and reason.
- The two reviewed guards do not implement that. They skip the whole pass before finding the site and before using the existing CFG/proof-region helpers. Because the root cause is likely a metadata/proof-remapping or boundary-validation defect, the correct fix is to make the kinsn passes subprog-aware rather than skipping all candidates in multi-subprog programs.

## Fail-Fast, dead code, and tests

Fail-Fast:

- `bad918ea` and `858ddd97` conflict with fail-fast. They turn a candidate that may have produced a verifier/ReJIT error into `changed=false`, which the v3 per-pass loop treats as "no change" and therefore does not verify (`docs/tmp/bpfopt_design_v3.md:424-435`).
- The skip reason is internal-only in normal CLI reporting because `PassReport` omits skipped sites (`bpfopt/crates/bpfopt/src/main.rs:215-225`, `bpfopt/crates/bpfopt/src/main.rs:1233-1246`). That is silent from the benchmark/report boundary.
- `6708d2a1` does not have this problem because it fixes emitted bytecode instead of suppressing a failure.

Dead code:

- No unreachable branch or unused helper is introduced in the current HEAD: `func_info_record_count()` has real callers in bulk and extract (`bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:110-118`, `bpfopt/crates/bpfopt/src/passes/extract.rs:114-122`).
- If the broad guards are removed, re-check whether `func_info_record_count()` still has a real caller; otherwise remove it under `CLAUDE.md:29-33`.

Unit tests:

- The bulk/extract tests assert the skip behavior itself (`bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:349-365`, `bpfopt/crates/bpfopt/src/passes/extract.rs:416-441`). Under `CLAUDE.md:35-40`, these are weak bug-detection tests because they prove the workaround, not the root-cause fix.
- Better tests should include a multi-subprog program with a candidate wholly inside one subprog and assert the candidate is transformed with correct pseudo-call offsets, proof-region metadata, and final verifier/ReJIT behavior. A negative test should cover the real invalid case: sidecar in one subprog and kinsn call at another subprog's entry.

## Summary against No ReJIT Filtering

| Verdict evidence | Details |
|---|---|
| YES | `bad918ea` and `858ddd97` add pass-level, program-wide filters keyed on `func_info_record_count(program)? > 1` (`bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:110-118`, `bpfopt/crates/bpfopt/src/passes/extract.rs:114-122`). They skip all candidate sites before scanning. Under the additional review constraint, this is a HIGH-severity violation even if it is not a runner-level `live_rejit_programs()` exclusion. |
| NO | The two guards do not prevent the whole BPF program from entering `PassManager`; later passes still run (`bpfopt/crates/bpfopt/src/pass.rs:987-999`). `6708d2a1` is a bytecode emission fix and adds no multi-subprog filtering (`bpfopt/crates/bpfopt/src/passes/endian.rs:151-177`). |
| MAYBE | If a particular candidate would put a kinsn call at a subprog start, the kernel rejects it (`vendor/linux-framework/kernel/bpf/verifier.c:3755-3768`) and a precise site-level rejection would be valid. The reviewed bulk/extract commits do not prove that condition per site; they only infer risk from the program having more than one `func_info` record. |

Fail-Fast verdict:

- `bad918ea`: **violates / HIGH**. It silently downgrades possible ReJIT failure to unchanged pass output.
- `858ddd97`: **violates / HIGH**. Same failure mode.
- `6708d2a1`: **does not violate / NONE**.

## 修复建议

1. Remove the `func_info_record_count(program)? > 1` early returns from `bulk_memory` and `extract` (`bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:110-118`, `bpfopt/crates/bpfopt/src/passes/extract.rs:114-122`).
2. Replace the skip tests with root-cause tests. Keep one positive multi-subprog test where a candidate is fully inside one subprog and must still be optimized; add one negative test for the exact invalid sidecar/call-at-subprog-entry case.
3. Extend candidate validation to compute each candidate's containing subprog from CFG/func_info and reject only candidates whose replacement span or sidecar/call pair crosses the subprog boundary. The existing branch/CFG/proof helpers are the right starting point (`bpfopt/crates/bpfopt/src/analysis/branch_target.rs:36-42`, `bpfopt/crates/bpfopt/src/analysis/cfg.rs:45-64`, `bpfopt/crates/bpfopt/src/passes/utils.rs:237-272`).
4. Audit `remap_kinsn_btf_metadata()`/proof-region offset mapping against the verifier order so `func_info` remains aligned after proof lowering (`vendor/linux-framework/kernel/bpf/verifier.c:26406-26434`, `vendor/linux-framework/kernel/bpf/verifier.c:19543-19549`).
5. If any site is deliberately skipped after precise validation, make it visible in the external CLI/report boundary or fail the pass when the missing capability is a bug. Do not rely on internal `sites_skipped` that disappears from `PassReport` (`bpfopt/crates/bpfopt/src/main.rs:215-225`, `bpfopt/crates/bpfopt/src/main.rs:1233-1246`).
