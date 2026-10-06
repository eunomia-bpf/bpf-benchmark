# Weekly Report: bpf-benchmark 2026-04-25 → 2026-05-01

## Overview (commit count, line count, contributor share)

Counting basis: unique commits from the user-specified command `git log --since='2026-04-25' --all`, including stash-like commits visible via `--all`. Line counts accumulate `git show --numstat` per commit, so already-committed corpus/e2e/micro result JSON is also included.

- Total commits: 280, 7-day average 40.0 commits/day.
- Per day: 4/25 7, 4/26 31, 4/27 16, 4/28 63, 4/29 71, 4/30 84, 5/1 8.
- Authors: OpenAI Codex 269 (96.1%), yunwei37/Zhengjie Ji 11 (3.9%), Claude 0.
- Full diffstat cumulative: 2,673 file change entries, +10,831,510 / -80,376, net +10,751,134. This number is mostly inflated by result files.
- After excluding result/report artifacts such as `corpus/results/`, `e2e/results/`, `micro/results/`, `docs/tmp/`, metadata, etc.: 1,164 file change entries, +44,887 / -71,142, net -26,255, indicating the source code direction is overall slimming and refactoring.
- Unique files touched: 1,739 in full; 251 after excluding result artifacts.
- Largest single commit: `2f9aed86`, tracking per-run summary/result files, +8,971,905 / -5.
- Smallest single commit: `5144fdb2` is an `--all`-visible index/stash-like 0 diff; the smallest non-empty commit is `50b2337e`, 1 line deleted.

## Topic Classification Table (commit count + line count + representative commits)

| Category | commits | file entries | lines | representative commits |
| --- | ---: | ---: | ---: | --- |
| v3 daemon architecture | 52 | 294 | +21,136 / -19,629 | `9bbd56f8` pivot; `9f59ee43` kernel-sys; `dc3abe33` bpfget/bpfrejit CLI; `681f5ba8` bpfverify/bpfprof |
| vm-corpus fixes | 40 | 1,272 | +10,751,558 / -1,480 | `441ad97f` replay hang; `7c768acd` round4; `e9c6bf69` round5; `dc92a15c` round6; `b8f4b21b` line_info |
| bpfopt passes | 27 | 125 | +12,095 / -2,049 | `9b9bd28e` prefetch enabled by default; `1943a03a` prefetch pass; `3f0653bb` wide_mem alignment; `59a5e82b` map-inline live values |
| kinsn modules | 18 | 50 | +2,233 / -204 | `b3a5f650` prefetch modules; `d02ac35e` ccmp module; `ce956452` BTF metadata remap |
| Build / image | 33 | 100 | +4,100 / -779 | `a27b8100` GHCR push/pull; `bd423eef` Katran cache; Docker layering/kernel-fork commits |
| Benchmark framework | 24 | 193 | +8,278 / -3,756 | per-program metrics, standard workload, runner pass override, micro baseline |
| Docs / research | 49 | 194 | +13,220 / -10,391 | v3 docs, SETcc/ANDN/BLS/division/register/region research, review reports |
| Tests / CI / verification | 20 | 113 | +15,526 / -1,355 | phase4 smoke, live minimal pipeline, unit-test quality cleanup, P89 validation |
| Cleanup / refactor | 17 | 355 | +4,435 / -40,733 | remove disabled passes, delete dead APIs, delete stale subcommands/profile residue |

## Key Milestones (chronological, plain narrative)

From 4/25 to 4/27 the benchmark boundary was tightened first: only 8 supported apps were kept, scx and ReJIT skip/filter logic were removed; corpus metrics were changed to per-program `avg_ns_per_run`, informational fields like `workload_miss/limitations` were removed; workloads migrated to standard tools such as stress-ng/fio/iperf/wrk, and calico/cilium network workloads and program rediscovery were added.

4/28 was the v3 toolchain landing day: `bpfopt-core` was merged, `kernel-sys` was introduced as the only syscall boundary, the `bpfopt` 12-pass CLI, `bpfget`, `bpfverify`, `bpfrejit`, and `bpfprof` were filled in, and plan B was recorded: runner Python continues to go through the daemon socket, the daemon adapts to CLIs internally.

On 4/29 daemon v3 integration and fail-fast cleanup began: `daa5bd48` replaced the internal PassManager with fork+exec CLIs, then `bb354cd3` removed the fallback and propagated subprocess errors. This decision exposed real defects such as map-inline live values, verifier-state side input, BTF metadata, and failure workdir. The same day Paper B `branch_flip`'s real per-site PGO route was also restored, and the heuristic fallback was removed.

4/30 focused on image and pass/kinsn: `a27b8100` added the GHCR push/pull mechanism, but the report shows the GHCR token lacked package scope and push did not succeed; `bd423eef` narrowed Katran artifact cache inputs to avoid small daemon/kernel changes triggering full folly/Katran rebuilds. P89 prefetch finished module, pass, and runtime wiring, and structural prefetch was enabled by default by `9b9bd28e`. In the same period verifier rejects such as wide_mem misaligned load, tail-call-sensitive kinsn, and BTF remap were fixed.

5/1 was the corpus bug marathon and v3 pivot: rounds 2-6 successively fixed daemon timeout, BTF/line_info, resolved map pointer relocation, Calico/Cilium HTTP netns and keep-alive, and Tetragon verifier-state timeout amplification. 7 rounds of fixes proved that the cross-process kernel CLI protocol was too costly, so `9bbd56f8` pivoted: `bpfget`/`bpfverify`/`bpfrejit` became daemon-owned in-process libraries, keeping only `bpfopt`/`bpfprof` CLIs. Subsequently `b8f4b21b` fixed the line_info replay normalization that was lost after the pivot.

## Bug Type Frequency Table

| bug type | estimated frequency | typical manifestation |
| --- | ---: | --- |
| cross-process protocol / load-context | ~35% | `map_fds.json`, BTF side files, `prog_flags`, verifier-states-out, failure report files missing or truncated by timeout |
| workload setup | ~22% | Calico/Cilium readiness, `ip netns exec` path, HTTP/1.0 causing TIME_WAIT/ephemeral port pressure, timerfd flaky |
| relocation / metadata reconstruction | ~17% | single-map to multi-map resolved pointer, `PSEUDO_MAP_IDX/IDX_VALUE`, map helper/tail-call argument recognition |
| daemon hang / timeout | ~17% | blocking `Command::output()`, global 5s too short, 60s per program too long, 5/30/60 ramp amplified on Tetragon |
| line_info / func_info offset | ~13% | multi-subprog coverage, post-pass offset remap, post-pivot `Invalid insn code at line_info[35].insn_off` |
| verifier reject optimized bytecode | ~13% | misaligned wide load, kinsn subprog/tail-call boundary, candidate BTF metadata inconsistency |

These frequencies are roughly classified by round reports and related fix commits; categories overlap; the core conclusion is that protocol/metadata-type issues dominate.

## Detours Taken (Lessons)

- The timeout strategy went through three rounds: first there was no timeout, causing a 600s socket hang; then a global 5s killed verifier-heavy programs; then 60s and the 5/30/60 ramp on Tetragon's 287 programs exceeded the 2h VM upper bound. The conclusion is that original verifier-state capture cannot do long ramps per program, and the larger direction is to eliminate the kernel-facing subprocess protocol.
- Calico/Cilium HTTP was fixed multiple times before the root cause was located: first thought to be a readiness race, server `READY` was changed; then it was found that the client needed to enter `bpfbenchns`; finally it was discovered that HTTP/1.0 short connections were saturating namespace ports/TIME_WAIT, switched to HTTP/1.1 keep-alive.
- map pointer replay first did the single-map special case, then tracee/katran multi-map exposed that guessing was impossible; switched to reconstruction by `prog_info.map_ids`/used-map order, and finally after the pivot the daemon holds the fd, reducing JSON reconstruction.
- Multi-subprog pass skip/exclusion was attempted or appeared, but this violates No ReJIT Filtering, and was subsequently reverted to per-site boundary validation and natural error reporting.
- The GHCR mechanism was added, but the remote package does not exist and the token lacks scope; the local fallback rebuilt Katran due to broad prerequisites. The lesson is that the cache path and push permission must be closed-loop together.

## Unfinished + Next 7-Day Outlook

- `make vm-corpus` has not yet completely and stably passed; in the report round 6 was still on Tetragon timeout, the user note shows the longest round 7 was stuck on Tetragon, and the current round 9 is verifying the `9bbd56f8` pivot + `b8f4b21b` line_info fix.
- `vm-e2e` and `vm-micro` have not yet completed post-pivot verification; the micro `BpfReJIT` entry is still marked as to-be-restored/known limitation in the plan doc.
- AWS x86 / arm64 full matrix has not yet started; the cost default has been lowered to small, with medium only as the OOM upper bound.
- The pivot review still has risk items: the in-process verifier has no equivalent watchdog, and the docs need to be synchronized with the actual final-verify-only behavior for per-pass verify/rollback.
- Next 7-day priorities: first get KVM x86 corpus to run a complete round, then run vm-e2e/vm-micro; then push the GHCR cache or fix auth; finally bring up AWS x86/arm64 to fill in three-platform data after Paper A prefetch/v3 pivot.
