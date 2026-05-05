# Correctness review of recent cleanup, 2026-05-05

Reviewed object: `origin/main` / `HEAD` = `8b0dfaa7a689c1e9ed64193eeda2ad49a1e2b5ae` (`Refactor optimization reporting and metadata handling`). I fetched `origin/main` twice during the review; no newer bgv5s8aii opaque-summary commit had landed on `origin/main`.

Method: source claims below are from `git show HEAD:<path>` unless explicitly marked "bgv5 pre-commit working tree". The local worktree was dirty with bgv5's uncommitted source edits, so build/test validation for main HEAD was run from a clean `git archive HEAD` export at `/tmp/bpf-benchmark-head.ZA2z2i`.

## 1. Daemon try_apply_one chain semantics

Verdict: CORRECT for main HEAD.

The daemon initializes `current_bytes` from the original program and `verifier_states_ready = false` before the pass loop (`daemon/src/commands.rs:593-596`). For each pass, it writes the current bytecode as pass input (`daemon/src/commands.rs:596-603`), skips only verifier-state-dependent passes when states are absent (`daemon/src/commands.rs:605-615`), runs `bpfopt` (`daemon/src/commands.rs:628-649`), reads and decodes pass output (`daemon/src/commands.rs:650-672`), and then calls `BPF_PROG_REJIT` unconditionally after successful bpfopt output decode (`daemon/src/commands.rs:673-683`). It updates verifier states, marks them ready, and assigns `current_bytes = pass_bytes` only after successful ReJIT (`daemon/src/commands.rs:684-688`).

The chain loop itself always iterates through the requested pass list unless the closure returns an infrastructure error (`daemon/src/commands.rs:745-753`). bpfopt failures are converted to `FailedBpfopt` pass records (`daemon/src/commands.rs:641-648`, `daemon/src/commands.rs:652-659`, `daemon/src/commands.rs:664-671`), ReJIT failures are converted to `FailedRejit` pass records (`daemon/src/commands.rs:673-681`), and subsequent passes are still attempted by `run_pass_chain` (`daemon/src/commands.rs:749-752`). The regression test covers the minimal 3-pass shape where pass 1 reports `FailedRejit` and pass 2 is still attempted (`daemon/src/commands.rs:1392-1421`).

Verifier-state bootstrap is present. `const_prop` and `map_inline` are the only passes that require prior verifier states (`daemon/src/commands.rs:724-725`). `noop` itself is a bpfopt unchanged pass (`bpfopt/crates/bpfopt/src/passes/noop.rs:18-24`), but the daemon no longer has an unchanged/changed gate before ReJIT, so `noop` still reaches the ReJIT call and can populate verifier states (`daemon/src/commands.rs:673-688`). The same is true for any first pass that does not require verifier states and whose bpfopt output decodes successfully.

I did not find a silent cascade-to-skip path in main HEAD. A shape such as `prefetch,map_inline` where `prefetch` fails ReJIT leaves `verifier_states_ready` false, and `map_inline` is then explicitly recorded as `skipped_missing_states`; that is visible, not silent (`daemon/src/commands.rs:605-615`, `daemon/src/commands.rs:673-681`).

## 2. changed field elimination consistency

Verdict: WRONG in main HEAD. Severity: HIGH.

Daemon and bpfopt have removed `changed` from the live protocol. `OptimizeOneResult` has only `status`, `prog_id`, `program`, `passes`, `inlined_map_entries`, and `error_message` (`daemon/src/commands.rs:126-135`). `PassDetail` has `pass`, `status`, `sites_applied`, `insns_before`, `insns_after`, `insn_delta`, and optional `error`, but no `changed` (`daemon/src/commands.rs:184-195`). The daemon's bpfopt report reader also has no `changed` field (`daemon/src/commands.rs:245-253`). bpfopt's CLI `PassReport` has no `changed` field (`bpfopt/crates/bpfopt/src/main.rs:155-164`), and `PassResult` no longer stores `changed` (`bpfopt/crates/bpfopt/src/pass.rs:489-505`).

The runner still requires `changed`. `_normalize_apply_passes()` reads `item.get("changed")` and raises unless it is a bool (`runner/libs/rejit.py:141-162`). `_apply_result_from_response()` also requires top-level `response["changed"]` for any `status == "ok"` daemon result (`runner/libs/rejit.py:432-440`). `apply_daemon_rejit()` feeds every per-program daemon record into that validator (`runner/libs/rejit.py:616-631`). Therefore a normal current daemon response will fail before corpus output can be normalized.

Concrete reproduction shape:

```json
{
  "status": "ok",
  "per_program": {
    "7": {
      "status": "ok",
      "prog_id": 7,
      "program": {"prog_id": 7, "prog_name": "p", "prog_type": 6, "orig_insn_count": 1, "final_insn_count": 1, "insn_delta": 0},
      "passes": [{"pass": "noop", "status": "ok", "sites_applied": 0, "insns_before": 1, "insns_after": 1, "insn_delta": 0}]
    }
  }
}
```

`apply_daemon_rejit()` will call `_apply_result_from_response()` for program `7` (`runner/libs/rejit.py:616-631`), which raises `daemon response field 'changed' must be a boolean` because `changed` is absent (`runner/libs/rejit.py:432-438`).

There is a second stale source-side assertion in `scripts/p88_branch_flip_dense_pgo.sh`, which still expects bpfopt's report to contain `.changed == true` (`scripts/p88_branch_flip_dense_pgo.sh:108-115`) even though bpfopt's `PassReport` does not emit that field (`bpfopt/crates/bpfopt/src/main.rs:155-164`).

bgv5 status: no bgv5 commit is on `origin/main`. The local bgv5 pre-commit working tree was trying to move daemon pass details toward opaque `bpfopt_summary` (`daemon/src/commands.rs:185-192` in the dirty worktree), but that tree was not buildable when I first ran the daemon build; see section 8.

## 3. noop hint preservation

Verdict: WRONG in main HEAD, narrowly. Severity: LOW.

The missing-states path does put a hint in `PassDetail.error` when it returns `PassStatus::SkippedMissingStates` (`daemon/src/commands.rs:605-615`). However the required memory text says "requires verifier states from a previous successful per-pass ReJIT". The actual string omits "successful": `pass {pass} requires verifier states from a previous per-pass ReJIT ...` (`daemon/src/commands.rs:611-613`).

Concrete reproduction shape: run a pass chain starting with `map_inline` or `const_prop`, with no earlier successful ReJIT. The pass record is emitted as `skipped_missing_states`, but the error text is not the required exact hint (`daemon/src/commands.rs:605-615`).

This is in main HEAD, not bgv5-only.

## 4. map_inline reporting

Verdict: SUSPECT in main HEAD. Severity: MED.

bpfopt still does not emit the inlined value in `map_inline_records`. The shared pass record contains only `map_id` and `key` (`bpfopt/crates/bpfopt/src/pass.rs:542-547`). The bpfopt JSON report shape similarly contains only `map_id` and `key_hex` (`bpfopt/crates/bpfopt/src/main.rs:166-170`), and `map_inline_record_report()` serializes only those two fields (`bpfopt/crates/bpfopt/src/main.rs:1165-1169`). The unit test explicitly asserts that `value_hex` is absent (`bpfopt/crates/bpfopt/src/main.rs:1323-1340`).

bpfopt has the value at inline time. Helper lookup rewrites read the scalar from `inline_value` before emitting constants (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1188-1199`) and then store only `(map_id, key)` in the record (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1205-1212`). Direct pseudo-map-value rewrites read from `map_value.value` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1293-1295`) and also record only `(map_id, key)` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1318-1322`).

The daemon compensates by resolving `(map_id, key)` through its own snapshot. It collects bpfopt records from committed `map_inline` reports (`daemon/src/commands.rs:358-372`), looks up the value in `MapValueSnapshot`, and fails if the record is absent from that snapshot (`daemon/src/commands.rs:375-390`). It serializes `InlinedMapEntry { map_id, key_hex, value_hex }` from that snapshot value (`daemon/src/commands.rs:393-400`), and the result field itself requires `value_hex` (`daemon/src/commands.rs:158-163`).

This means result.json can contain populated `(map_id, key_hex, value_hex)` entries for current helper and direct `map_inline` sites, because both current map_inline paths emit records (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1209-1212`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1318-1322`) and tests cover those records (`bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:362-370`, `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:388-396`, `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1533-1541`). The weak point is that the daemon has no explicit invariant that `map_inline sites_applied > 0` implies a matching record count; it trusts whatever records bpfopt reports (`daemon/src/commands.rs:358-372`, `daemon/src/commands.rs:694-696`).

Concrete failure shape: a future `map_inline` rewrite increments `sites_applied` but forgets to push a `MapInlineRecord`. The pass would still be `ok` and committed (`daemon/src/commands.rs:684-689`), while `collect_inlined_map_entries()` would see no missing snapshot key because it only iterates the records that exist (`daemon/src/commands.rs:375-390`). Result artifacts would then have `map_inline sites_applied > 0` but no corresponding `inlined_map_entries`.

bgv5 status: no bgv5 commit has landed. The dirty pre-commit tree appears to be moving value reporting into opaque bpfopt summaries, but that tree was not part of main HEAD and was not buildable at the first daemon build attempt.

## 5. PassStatus enum integrity

Verdict: CORRECT for main HEAD.

`PassStatus` has exactly the expected variants: `Ok`, `SkippedMissingStates`, `FailedBpfopt`, and `FailedRejit` (`daemon/src/commands.rs:175-182`). I found no daemon source variant or match arm for `Unchanged`; the only current source uses are the four expected statuses (`daemon/src/commands.rs:607-615`, `daemon/src/commands.rs:641-648`, `daemon/src/commands.rs:652-659`, `daemon/src/commands.rs:664-681`, `daemon/src/commands.rs:689`).

Every normal pass-outcome path produces exactly one pass detail: missing verifier states uses `pass_detail_without_report()` (`daemon/src/commands.rs:605-615`), bpfopt command/read/decode failures use `FailedBpfopt` (`daemon/src/commands.rs:641-671`), ReJIT failures use `FailedRejit` (`daemon/src/commands.rs:673-681`), and success uses `Ok` (`daemon/src/commands.rs:684-689`). The constructors set the status directly in the emitted detail (`daemon/src/commands.rs:798-829`).

Infrastructure errors such as failure to write pass input or verifier-state side files still abort the whole optimize attempt rather than emit a pass status (`daemon/src/commands.rs:602-603`, `daemon/src/commands.rs:684-685`). I did not count that as a pass-status bug because those are framework IO failures, not bpfopt/ReJIT pass outcomes, and the project fail-fast rule prefers surfacing IO errors.

## 6. kinsn pass correctness after cleanup

Verdict: SUSPECT overall because `cond_select` remains suspect. `rotate` is no longer suspect for the old `changed` silent-failure surface; `endian` remains correct.

rotate: CORRECT for the reviewed bug. The old failure surface depended on bpfopt reporting `changed=false` while output bytes changed. That surface is closed in main HEAD because `PassResult` has no `changed` field (`bpfopt/crates/bpfopt/src/pass.rs:489-505`), bpfopt `PassReport` has no `changed` field (`bpfopt/crates/bpfopt/src/main.rs:155-164`), and the daemon runs ReJIT after any successful bpfopt output decode without checking a changed flag (`daemon/src/commands.rs:650-689`). The rotate matcher remains conservative: it requires adjacent provenance (`bpfopt/crates/bpfopt/src/passes/rotate.rs:214-227`) and rejects sites where the OR result writes the verifier proof scratch (`bpfopt/crates/bpfopt/src/passes/rotate.rs:344-354`), matching the x86 kinsn constraint that `tmp_reg` must not equal `dst_reg` or `src_reg` (`module/x86/bpf_rotate.c:27-30`). Those are missed optimizations, not confirmed wrong rewrites.

cond_select: SUSPECT in main HEAD. The pass still chooses temporary registers from syntactic liveness, not verifier or callgraph-aware liveness. Calls are modeled as using/clobbering only r0-r5 (`bpfopt/crates/bpfopt/src/analysis/liveness.rs:93-102`), and successor computation does not walk into BPF-to-BPF callees (`bpfopt/crates/bpfopt/src/analysis/liveness.rs:123-140`). `choose_temp_reg()` may choose `site.dst_reg` or any r0-r9 not forbidden, not allocated, and not syntactically live after the site (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:609-621`). Concrete trigger shape: a caller has a cond_select immediate site before a BPF-to-BPF call; the callee reads r6, but r6 is not syntactically live in the caller after the site. `choose_temp_reg()` may use r6 for immediate materialization, clobbering a value the callee observes (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:422-449`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:573-597`).

cond_select also remains non-idempotent for generic predicate lowering. The scanner recognizes Pattern C as `MOV dst,true; Jcc +1; MOV dst,false` (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:333-381`). For non-JEQ/JNE generic compares, `condition_prefix()` can emit `MOV pred,0; inverse Jcc +1; MOV pred,1` (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:504-526`), which is itself Pattern C-shaped on a second run. The concrete trigger is a JGT/JLE/JSGT-style cond_select site; after one pass, the generated predicate prefix can be rematched by the same pass.

The cleanup commits did not fix the cond_select issues. `8b0dfaa7` removed only the `changed: applied > 0` field from cond_select's `PassResult` literal, while the current temp-selection and generic predicate code above remains in place (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:273-279`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:504-526`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:609-621`).

endian: CORRECT. The narrowing fusion is conservative: `find_narrowing_site()` scans only within `MAX_NARROW_SCAN` and stops when the loaded destination is read or written before the endian op (`bpfopt/crates/bpfopt/src/passes/endian.rs:92-108`, `bpfopt/crates/bpfopt/src/passes/endian.rs:201-203`). Reads include source use, ALU/ST/STX destination use, conditional jump destination use, LDX base use, calls for r1-r5, and exits for r0 (`bpfopt/crates/bpfopt/src/passes/endian.rs:209-220`). Emission replaces the load with the endian kinsn call, copies only the safe intervening instructions, deletes the final endian op, then fixes branches (`bpfopt/crates/bpfopt/src/passes/endian.rs:494-524`, `bpfopt/crates/bpfopt/src/passes/endian.rs:541-555`). I found no new semantic regression from the cleanup.

## 7. Test coverage gaps

Verdict: SUSPECT in main HEAD. Severity: MED.

The `FrozenMapValue` rename is consistent in source and tests. The production type is now `SnapshotMapValue` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:94`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1240`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1340-1376`), and the pseudo-map-value tests use snapshot wording (`bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:348`, `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:374`).

The cascade test exists but is too shallow for the real bug class. It asserts that `run_pass_chain()` invokes a closure for three synthetic passes and records a synthetic `FailedRejit` in the middle (`daemon/src/commands.rs:1392-1421`). It does not exercise `try_apply_one()`, `current_bytes`, bpfopt subprocess output, ReJIT error handling, or the verifier-state gate (`daemon/src/commands.rs:593-689`). A bug in the real closure that accidentally returned `Err` or mutated `verifier_states_ready` incorrectly could still leave this test passing.

There is no effective test coverage for the current daemon-to-runner protocol. The runner still rejects missing `changed` (`runner/libs/rejit.py:141-162`, `runner/libs/rejit.py:432-440`), while daemon/server tests build successful `OptimizeOneResult` values without any changed field (`daemon/src/server.rs:293-308`). Those tests prove the daemon's new shape serializes, but not that the Python runner accepts it.

The cleanup report confirms 11 tests were deleted during the cleanup/refactor sequence (`docs/tmp/design-cleanup-execution-20260505.md:48-52`). Some deletions were valid, but one remaining test now preserves an old protocol limitation: `pass_report_serializes_map_inline_records_as_hex()` asserts that bpfopt does not include `value_hex` (`bpfopt/crates/bpfopt/src/main.rs:1323-1340`) even though section 4 shows bpfopt already has the value at inline time (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1188-1199`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1293-1295`).

Silently passing tests with weak or obsolete invariants:

- `daemon/src/commands.rs:1392-1421`: passes while not exercising actual `try_apply_one` cascade semantics.
- `bpfopt/crates/bpfopt/src/main.rs:1323-1340`: passes by asserting `value_hex` is absent from map_inline records, which is now the old side of the intended opaque/value pass-through protocol.
- `daemon/src/server.rs:293-308`: constructs the new daemon response shape, but no paired runner-side test consumes that shape, so it passes while the runner still rejects it.

## 8. Build, lint, and dead code

Verdict: WRONG for clippy in main HEAD; build/test are CORRECT.

Clean main HEAD validation from `/tmp/bpf-benchmark-head.ZA2z2i`:

- PASS: `cargo build --release --workspace --manifest-path bpfopt/Cargo.toml`
- PASS: `cargo build --release --workspace --manifest-path daemon/Cargo.toml`
- PASS: `cargo test --release --workspace --manifest-path bpfopt/Cargo.toml` - 353 bpfopt lib tests, 9 bpfopt bin tests, 10 `cli_pipeline` tests, 7 bpfprof unit tests, 4 bpfprof CLI tests, 21 kernel-sys tests, 2 kernel-sys integration tests, doc tests all passed.
- PASS: `cargo test --release --workspace --manifest-path daemon/Cargo.toml` - 26 daemon tests passed, bpfget had 0 tests.
- FAIL: `cargo clippy --release --workspace --manifest-path bpfopt/Cargo.toml -- -D warnings` - `kernel-sys::create_map()` has 8 arguments and trips `clippy::too_many_arguments` (`bpfopt/crates/kernel-sys/src/lib.rs:931-940`).
- FAIL: `cargo clippy --release --workspace --manifest-path daemon/Cargo.toml -- -D warnings` - nested `if` in map-reference canonicalization trips `clippy::collapsible_if` (`daemon/src/bpf.rs:48-56`), and `run_bpfopt_pass()` trips `clippy::too_many_arguments` (`daemon/src/commands.rs:756-767`).

I did not find a newer bgv5 commit to test. The dirty bgv5 pre-commit working tree failed the first in-place daemon build during this review with stale references to deleted typed bpfopt report fields. That failure is not in main HEAD. The dirty tree changed while the review was running, so this report treats it only as a pre-commit integration risk, not as an authoritative source review.

## Aggregate severity

HIGH: 1

- Runner still requires `changed`, so main HEAD daemon responses are rejected before corpus runs complete (`runner/libs/rejit.py:432-440`, `runner/libs/rejit.py:616-631`).

MED: 3

- `map_inline` value is still omitted from bpfopt reports and reconstructed in daemon without a `sites_applied` to record-count invariant (`bpfopt/crates/bpfopt/src/main.rs:166-170`, `daemon/src/commands.rs:358-390`).
- `cond_select` remains suspect for BPF-to-BPF temp clobber and generic predicate non-idempotence (`bpfopt/crates/bpfopt/src/analysis/liveness.rs:93-140`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:504-526`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:609-621`).
- Tests do not cover the daemon-to-runner protocol mismatch or real `try_apply_one` cascade semantics (`runner/libs/rejit.py:141-162`, `daemon/src/commands.rs:1392-1421`).

LOW: 2

- `skipped_missing_states` hint is semantically present but not the required exact text because it omits "successful" (`daemon/src/commands.rs:611-613`).
- Clippy fails under `-D warnings` for current HEAD (`bpfopt/crates/kernel-sys/src/lib.rs:931-940`, `daemon/src/bpf.rs:48-56`, `daemon/src/commands.rs:756-767`).

## Top 3 bugs before SAMPLES=30 paper run

1. Fix the daemon/runner protocol mismatch around `changed`. Main HEAD is not runnable through the Python runner as-is (`daemon/src/commands.rs:126-195`, `runner/libs/rejit.py:432-440`).
2. Fix or disable the remaining suspect `cond_select` generic compare and BPF-to-BPF temp-liveness cases before allowing it in authoritative pass chains (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:504-526`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:609-621`).
3. Finish the map_inline value pass-through or add a hard invariant that every applied map_inline site produces a `(map_id,key,value)` dependency in result artifacts (`bpfopt/crates/bpfopt/src/main.rs:166-170`, `daemon/src/commands.rs:375-400`).

## Paper-run readiness

Main HEAD is not ready for a SAMPLES=30 paper run. The blocker is the HIGH protocol mismatch: current daemon responses omit `changed`, while the runner still requires it and raises before producing accepted artifacts (`runner/libs/rejit.py:432-440`, `runner/libs/rejit.py:616-631`). The `cond_select` correctness risk should also be handled before authoritative runs if that pass is in the chain.
