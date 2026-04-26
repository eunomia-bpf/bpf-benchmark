# P0 Fix Code Review - 2026-04-26

## Scope

Reviewed the latest code changes in:

- `cc762f62 Fix cilium program ID drift: rediscover programs on ID disappearance`
- `db754540 Fix P0 bugs: error propagation, program discovery, workload triggers`
- `7b67f722 Add metadata files for various benchmark runs including bcc, bpftrace, katran, tetragon, and tracee`

Commands reviewed first, per request:

- `git log --oneline -5`
- `git diff HEAD~3..HEAD`

Only the first two commits contain relevant code changes. The metadata-only commit does not affect runtime logic.

## corpus/driver.py — BUG

- `BUG`: `_rediscover_session_programs()` accepts any non-empty identity match as success and never checks that the rediscovered set is complete. `matched_programs` can be a strict subset of `expected_programs`, but `_refresh_active_session_programs()` still overwrites `session.state.prog_ids`, `session.state.artifacts["programs"]`, and `session.runner.programs` with that smaller set (`corpus/driver.py:214-240`, `corpus/driver.py:265-305`). This can silently drop live programs from baseline/ReJIT/post-ReJIT measurement instead of failing fast.
- `BUG`: claimed-ID conflict handling is incomplete on the partial-match path. `claimed_overlap` only becomes fatal when `live_programs` is empty (`corpus/driver.py:265-272`). If rediscovery finds some matches and some replacements overlap another session's claimed IDs, the overlap is ignored and the truncated set is accepted.
- `BUG`: the rediscovery candidate pool is not session-scoped. For native-process runners, `runner.session._discover_programs()` returns `programs_after(self.before_ids)`, which means "all programs loaded since this runner started," not "only this app's programs" (`runner/libs/app_runners/process_support.py:266-267`). The fallback is even broader: whole-system `bpftool prog show` (`corpus/driver.py:234-240`, `corpus/driver.py:247-253`). The identity key only uses `(name, type, attach_type, attach target, attach_btf_id)` and has no app provenance (`corpus/driver.py:167-174`). So yes: another app's programs can be mistaken for this session if identities collide.
- `WARN`: `_session_program_records()` prefers `session.runner.live_rejit_programs()` over the original startup artifacts (`corpus/driver.py:160-164`), and the refresh path mutates both `session.runner.programs` and `session.state.artifacts["programs"]` in place (`corpus/driver.py:303-305`). After one bad rediscovery, future rediscovery attempts use already-corrupted "expected" records, making the mistake self-reinforcing.
- `WARN`: the warning log is too weak and can mask the real failure. The emitted message always says "refreshed live session programs" and logs only previous/missing/refreshed IDs (`corpus/driver.py:278-288`). It does not report expected-vs-matched counts, partial loss, or non-fatal `claimed_overlap`. Because the code overwrites the stored program set immediately afterward, the original evidence is lost.
- `OK`: there is no recursion and no obvious dead loop in the new helpers themselves. The problem is incorrect acceptance criteria, not control-flow non-termination.
- `OK`: this change does not add ReJIT filtering/skip logic and does not add direct `.bpf.o` loading.

## runner/libs/app_runners/process_support.py — OK

- `OK`: moving from count-based stability to ID-set stability is directionally correct. It fixes the old false-stable case where program count stayed constant but IDs churned (`runner/libs/app_runners/process_support.py:68-97`).
- `OK`: `required_stable_observations = ceil(stable_window / poll_interval) + 1` is conservative and bounded (`runner/libs/app_runners/process_support.py:65-69`). I do not see an off-by-one that would cause an early return before the requested stable window.
- `OK`: edge cases are handled reasonably. `stable_window_s` is clamped at `>= 0`, `poll_interval_s` at `>= 0.05`, and the loop still times out cleanly (`runner/libs/app_runners/process_support.py:65-68`, `runner/libs/app_runners/process_support.py:96-106`).
- `OK`: no ReJIT filtering/skip logic and no direct `.bpf.o` loading were introduced here.

## e2e/cases/tracee/case.py — OK

- `OK`: ReJIT/apply errors now propagate to top-level case status. Per-cycle `rejit_result["error"]` is appended to both `limitations` and `errors`, and the final payload flips to `status="error"` with `error_message` when any cycle reports an error (`e2e/cases/tracee/case.py:340-381`).
- `OK`: there is no silent bypass for missing lifecycle phases. Missing baseline or missing `post_rejit` still raises immediately and returns an error payload (`e2e/cases/tracee/case.py:325-349`).
- `OK`: this change records errors instead of swallowing them, and it does not introduce any ReJIT filtering or direct `.bpf.o` loading.

## e2e/cases/tetragon/case.py — BUG

- `BUG`: the new `post_rejit` status check is incompatible with the actual payload shape. `run_phase()` returns only `{"phase": ..., "records": [...]}` and never sets `status` or `reason` (`e2e/cases/tetragon/case.py:87-100`). But the new logic treats `post_rejit.get("status") != "ok"` as failure (`e2e/cases/tetragon/case.py:278-283`). On a normal successful run, `post_rejit.get("status")` is empty, so this branch fires and appends `"post_rejit failed"`.
- `BUG`: because of the above, successful tetragon runs are now misreported as top-level `status="error"` even when there is no ReJIT error. This is a correctness bug in result reporting, not just a logging issue (`e2e/cases/tetragon/case.py:272-301`).
- `OK`: actual `rejit_result["error"]` propagation itself is fine (`e2e/cases/tetragon/case.py:265-277`), but it is wrapped in a broken success-path check.
- `OK`: no ReJIT filtering/skip logic and no direct `.bpf.o` loading were introduced here.

## runner/libs/benchmark_catalog.py — WARN

- `WARN`: changing `calico/felix` and `cilium/agent` from `network` to `exec_storm` is not well-supported by the rest of the code. Both runners are explicitly configured around interface-bound network datapaths: Calico sets `FELIX_BPFDATAIFACEPATTERN` / `FELIX_BPFL3IFACEPATTERN` and enables BPF/XDP (`runner/libs/app_runners/calico.py:70-100`), while Cilium pins `--devices` and `--direct-routing-device` (`runner/libs/app_runners/cilium.py:52-80`). `exec_storm` only runs `stress-ng --exec` process churn (`runner/libs/workload.py:460-496`).
- `WARN`: there is no accompanying runner change proving that `exec_storm` exercises those network/XDP/TC hooks. So this workload swap can make BPF stats and throughput numbers much less representative of the apps being measured.
- `WARN`: `network` is also imperfect because it drives a loopback-only local HTTP server (`runner/libs/workload.py:1061-1072`). That means the old workload was already weak for real datapath coverage. Still, this diff does not make the measurement model more defensible; it moves even farther away from the apps' actual hook points.
- `OK`: no ReJIT filtering/skip logic and no direct `.bpf.o` loading were introduced here.

## runner/libs/aws_executor.py — BUG

- `BUG`: the new swap setup does not survive the code path that immediately reboots the instance. `_ensure_instance_for_suite()` enables swap before calling `_maybe_setup()` (`runner/libs/aws_executor.py:569-580`), but `_setup_instance()` performs a reboot (`runner/libs/aws_executor.py:447-490`). `_ensure_instance_for_suite()` then returns immediately after setup without re-running `_ensure_remote_swap()` on the post-reboot machine. So on fresh-instance / kernel-mismatch / missing-BTF paths, the swap fix is effectively lost exactly where it is most needed.
- `WARN`: `_ensure_remote_swap()` mutates the root filesystem without any free-space check (`runner/libs/aws_executor.py:321-331`). The default root volume is 32 GiB, so this is probably survivable in normal runs, but it is still an unguarded rootfs mutation.
- `WARN`: the swapfile is not made persistent across reboot, so correctness depends on `_ensure_remote_swap()` being called after every reboot. The current control flow does not guarantee that.
- `OK`: this change is unrelated to ReJIT filtering or `.bpf.o` loading.

## Design-Rule Validation

- `OK`: I did not find any new ReJIT filtering/skip mechanism in these diffs. No exclusion lists, no `LifecycleAbort` skip path for ReJIT, and no pass exclusions were added.
- `OK`: I did not find any new direct `.bpf.o` loading path in these diffs. The touched code still relies on app-native startup or existing app-owned loader paths.
- `BUG`: error handling is still not consistently trustworthy because `corpus/driver.py` can silently shrink a session's live program set behind a warning, and `e2e/cases/tetragon/case.py` now misclassifies successful runs as errors.

## Conclusion

These changes are **not trustworthy as-is**.

Blocking issues:

- `corpus/driver.py` can silently accept partial or cross-session rediscovery results and then overwrite its own ground truth.
- `e2e/cases/tetragon/case.py` will report successful runs as failures because it expects a `status` field that the phase payload does not contain.
- `runner/libs/aws_executor.py` enables swap on the pre-setup machine but can return a post-reboot machine with no active swap.

Non-blocking but still concerning:

- `runner/libs/benchmark_catalog.py` changes `calico/cilium` workloads in a way that is not clearly aligned with the apps' actual BPF hook points.

Patches that look good:

- `runner/libs/app_runners/process_support.py`
- `e2e/cases/tracee/case.py`

Bottom line: the patch set fixes some symptoms, but the current code still has correctness bugs in session rediscovery, tetragon status propagation, and AWS medium-instance swap handling. I would not rely on these changes for authoritative benchmark results until those issues are fixed.
