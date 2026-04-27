# Complexity Review

Reviewed `main..HEAD` with focus on code and file additions that increase maintenance cost without enough payoff.

## Findings

1. `docs/tmp/` and `e2e/results/*/metadata.json` add a large amount of branch noise with little source value.
   - `git diff --stat main..HEAD -- docs/tmp e2e/results` shows 71 files and 8072 inserted lines from scratch reports and generated metadata alone.
   - Examples: `docs/tmp/benchmark-framework-review-20260425/summary.md`, `docs/tmp/dockerfile-build-analysis-20260426/summary.md`, `e2e/results/tracee_20260426_050754_753361/metadata.json`.
   - Recommendation: keep one authoritative summary per topic and move the rest to ignored artifacts or external logs. These files make review harder and hide real code changes.

2. AWS workspace staging is still too hand-maintained and has already proven fragile.
   - `runner/libs/aws_executor.py:394-430` hardcodes suite-specific sync members in the executor. This branch first needed a corpus-only fix, and now test and e2e need follow-up additions for the same reason.
   - Recommendation: make each suite declare its required staged inputs in one place and have the executor consume that manifest. The executor should not own duplicated path knowledge for `corpus`, `e2e`, and `test`.

3. `runner/libs/case_common.py` has grown into a generic lifecycle framework that is more abstract than the current harness needs.
   - `runner/libs/case_common.py:187-358` introduces `CaseLifecycleState`, `PreparedDaemonSession`, `LifecycleAbort`, `LifecycleRunResult`, plus a large callback-driven `run_lifecycle_sessions()` pipeline.
   - The result is harder to audit because the actual benchmark flow is split across many optional hooks instead of one explicit sequence.
   - Recommendation: collapse this to a smaller paired-run helper with fixed phases: start, baseline, rejit, post-rejit, stop.

4. The new etcd/network runner support is framework-shaped when it only serves two apps.
   - `runner/libs/app_runners/etcd_support.py:99-174` builds synthetic namespace/interface management, `:184-298` adds a local etcd supervisor, and `:301-348` adds a hook-heavy `EtcdBackedNativeRunner`.
   - `runner/libs/benchmark_net.py` and large new sections of `runner/libs/workload.py:1-260` extend that shared surface further.
   - Recommendation: keep only a minimal `LocalEtcdSession` helper and move app-specific bootstrap/network logic back into `calico.py` and `cilium.py`. The current shape is a small framework, not a small reuse layer.

5. Corpus program rediscovery is implemented through too many helper layers for one policy decision.
   - `corpus/driver.py:152-280` stacks `_normalize_live_programs`, `_session_program_records`, `_program_identity`, `_match_programs_by_identity`, `_runner_rediscovered_programs`, `_rediscover_session_programs`, and `_refresh_active_session_programs`.
   - This solves a real issue, but the control flow is now indirect and the acceptance policy for partial replacement is easy to miss.
   - Recommendation: keep one rediscovery routine that returns either a full replacement set, a warning-class partial set, or an error. The fallback order should be explicit at the call site.

## Lower-Priority Notes

- `tests/python/test_corpus_driver.py:50-87` still expects partial rediscovery to raise, while `corpus/driver.py:269-299` now warns and accepts partial sets. Even if the runtime policy is intentional, the mismatch is another sign that the rediscovery path is harder to reason about than it should be.
