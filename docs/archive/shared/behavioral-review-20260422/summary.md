# Behavioral / Correctness Review 2026-04-22

Scope:
- read-only review
- no code changes
- no VM runs
- focus: Round 3 + 4 + 5 deletions, but judged against the current working tree

Bottom line:
- I found 1 live blocker that can silently bias authoritative Tracee event metrics.
- I found 1 medium post-run regression from deleted cleanup handling.
- Most other prompted concerns are false alarms in the current tree: either another path still covers them, or the allegedly removed behavior is still live.

## Part 1 — 严重度分类

- BLOCKER
  - `B1` Tracee event-file collector can silently undercount non-zero workloads after Round 3B removed strict parse accounting and file-reopen handling.
- HIGH
  - none confirmed in the current tree
- MEDIUM
  - `M1` `_cleanup_suite_temp_paths()` can now flip a successful e2e suite run into a final error on any non-`ENOENT` unlink failure.
- LOW
  - no additional live correctness bugs confirmed; the main remaining risk is coverage blindness rather than a second proven regression

## Part 2 — Findings

### B1 — Tracee event-file collector silently undercounts non-zero workloads

- Files: `runner/libs/app_runners/tracee.py:105-170,180-185`; `e2e/cases/tracee/case.py:441-451,507-571`
- 删除 round 归因: Round 3B / `docs/tmp/round3-cases-20260422/summary.md` item 1
- 触发场景:
  - `TraceeOutputCollector.consume_event_file()` now tails one file descriptor forever and never reopens on inode replacement or size shrink.
  - `_parse_event_line()` now silently returns on malformed JSON, non-object payloads, or missing event names.
  - `verify_phase_measurement()` only fails on `primary_events_total <= 0`, Tracee-reported drop counters, or `bpf.summary.total_events <= 0`.
- 行为分析:
  - The Tracee event sink here is not a mixed human log stream; it is the dedicated `--output json:<path>` file (`runner/libs/app_runners/tracee.py:366-372`).
  - If Tracee rewrites/recreates that file, or leaves a torn/truncated last line, the collector can now either keep reading the old fd forever or silently skip the malformed line.
  - Downstream measurement uses `after_tracee - before_tracee` deltas from collector state (`e2e/cases/tracee/case.py:507-520`), so every silently skipped line directly undercounts `event_counts`, `events_total`, `primary_events_total`, `events_per_sec`, and `events_per_op`.
  - Because the phase verifier only guards against going all the way to zero, partial loss stays green and can distort authoritative benchmark numbers without any explicit failure.
- 为什么 smoke 抓不住:
  - smoke and `SAMPLES=1` catch the gross cases: zero events, Tracee-reported lost events, or no post-ReJIT phase
  - they do not catch “collector lost 3% of lines but still saw plenty of events”
- 修复方向:
  - Keep stdout/stderr permissive.
  - Restore a minimal structured contract only for the dedicated event file: count parse errors, surface them in the snapshot, reopen on inode change / size shrink, and fail the measured phase on any parse-error delta.
- Ready-to-apply diff:

```diff
diff --git a/runner/libs/app_runners/tracee.py b/runner/libs/app_runners/tracee.py
@@
         self.latest_stats: dict[str, int] = {}
+        self.event_parse_error_count = 0
+        self.event_parse_error_samples: deque[str] = deque(maxlen=8)
+
+    def _record_event_parse_error(self, reason: str, line: str) -> None:
+        sample = f"{reason}: {tail_text(line, max_lines=1, max_chars=200)}"
+        with self._lock:
+            self.event_parse_error_count += 1
+            self.event_parse_error_samples.append(sample)
+            self._condition.notify_all()
@@
                 if stop_event.is_set():
                     break
-                time.sleep(0.05)
+                try:
+                    current_stat = path.stat()
+                    handle_stat = os.fstat(handle.fileno())
+                    if (
+                        (current_stat.st_dev, current_stat.st_ino)
+                        != (handle_stat.st_dev, handle_stat.st_ino)
+                        or current_stat.st_size < handle.tell()
+                    ):
+                        handle.close()
+                        handle = None
+                        time.sleep(0.05)
+                        continue
+                except FileNotFoundError:
+                    handle.close()
+                    handle = None
+                    time.sleep(0.05)
+                    continue
+                time.sleep(0.05)
@@
-        except json.JSONDecodeError:
+        except json.JSONDecodeError as exc:
+            self._record_event_parse_error(f"invalid JSON ({exc.msg})", line)
             return
         if not isinstance(payload, Mapping):
+            self._record_event_parse_error("event payload is not an object", line)
             return
         event_name = payload.get("eventName") or payload.get("event_name") or payload.get("name")
         if not event_name:
+            self._record_event_parse_error("event payload is missing event name", line)
             return
@@
-            return {"event_counts": dict(self.event_counts), "recent_events": list(self.events),
-                    "total_events": self.total_events, "latest_stats": dict(self.latest_stats),
-                    "stdout_tail": list(self.stdout_tail), "stderr_tail": list(self.stderr_tail),
-                    "event_tail": list(self.event_tail)}
+            return {"event_counts": dict(self.event_counts), "recent_events": list(self.events),
+                    "total_events": self.total_events, "latest_stats": dict(self.latest_stats),
+                    "stdout_tail": list(self.stdout_tail), "stderr_tail": list(self.stderr_tail),
+                    "event_tail": list(self.event_tail),
+                    "event_parse_error_count": self.event_parse_error_count,
+                    "event_parse_error_samples": list(self.event_parse_error_samples)}
diff --git a/e2e/cases/tracee/case.py b/e2e/cases/tracee/case.py
@@
 def verify_phase_measurement(record: Mapping[str, object], *, require_tracee_activity: bool) -> None:
     if not require_tracee_activity:
         return
+    if int(record.get("event_parse_errors", 0) or 0) > 0:
+        raise RuntimeError(
+            f"{record.get('name')} encountered malformed Tracee event-file lines: "
+            f"{record.get('event_parse_errors')}"
+        )
     if int(record.get("primary_events_total", 0) or 0) <= 0:
         raise RuntimeError(f"{record.get('name')} produced zero primary Tracee events")
@@
         drop_counters = {
             field: int(after_stats.get(field, 0)) - int(before_stats.get(field, 0))
             for field in ("event_count", "lost_event_count", "lost_write_count")
         }
+        event_parse_errors = (
+            int(after_tracee.get("event_parse_error_count", 0) or 0)
+            - int(before_tracee.get("event_parse_error_count", 0) or 0)
+        )
         total_events = int(after_tracee.get("total_events", 0)) - int(before_tracee.get("total_events", 0))
     else:
         event_counts = {}
         drop_counters = {}
+        event_parse_errors = 0
         total_events = None
@@
         "event_counts": event_counts,
         "drop_counters": drop_counters,
+        "event_parse_errors": event_parse_errors,
+        "event_parse_error_samples": list(after_tracee.get("event_parse_error_samples") or []) if after_tracee is not None else [],
         "latency_probe": None if latency_probe is None else dict(latency_probe),
```

### M1 — Suite temp cleanup can fail the whole run after results are already written

- Files: `e2e/driver.py:254-260,591-592`
- 删除 round 归因: Round 3A / `docs/tmp/round3-core-20260422/summary.md` item 7
- 触发场景:
  - any non-`FileNotFoundError` `Path.unlink()` failure in `_cleanup_suite_temp_paths()`
  - examples: transient permission issue, stale bind mount, `EBUSY`, read-only temp path, or unexpected suite-path ownership drift
- 行为分析:
  - `_cleanup_suite_temp_paths()` runs in the `finally` block after the main case body (`e2e/driver.py:591-592`).
  - At that point `ArtifactSession.write(...)` may already have recorded a successful result, but an unlink failure will still raise out of `finally` and turn the overall command into an error exit.
  - This does not falsify benchmark numbers, but it can waste a long suite run and mislabel a completed run as failed.
- 为什么 smoke 抓不住:
  - it only appears when the temp-path failure actually happens
  - normal happy-path runs never exercise it
- 修复方向:
  - Keep `FileNotFoundError` ignored.
  - Downgrade other cleanup `OSError`s to a concise stderr warning instead of aborting the already-finished suite.
- Ready-to-apply diff:

```diff
diff --git a/e2e/driver.py b/e2e/driver.py
@@
 def _cleanup_suite_temp_paths(args: argparse.Namespace) -> None:
     for raw_path in getattr(args, "_suite_temp_paths", []) or []:
         try:
             Path(raw_path).unlink()
         except FileNotFoundError:
             continue
+        except OSError as exc:
+            print(f"warning: failed to remove suite temp file {raw_path}: {exc}", file=sys.stderr)
```

## Part 3 — 不需要修的“假警报”

- `FA1` “Round 3A removed the EINVAL degradation, so any live `EINVAL` now hard-fails the app” is not true in the current tree.
  - Evidence: `corpus/driver.py:993-997` still has `fatal_apply_error = bool(apply_error) and not has_comparable_measurement`.
  - Historical evidence says this path matters: `docs/tmp/20260318/corpus_e2e_performance_analysis_20260318.md:319` records `BPF_PROG_JIT_RECOMPILE: Invalid argument`; `e2e/results/tetragon_authoritative_20260328.json:4368` records `BPF_PROG_REJIT: Invalid argument`; the same artifact family also contains `raw_tracepoint` programs at `e2e/results/tetragon_authoritative_20260328.json:5011`, `...20260329.json:1679`, `...20260331.json:1655`, `...20260403.json:2082`.
  - Conclusion: the current tree still degrades single-program apply errors when the rest of the loader instance produced comparable measurements. That is not a new regression from these cleanup rounds; it is the opposite.

- `FA2` `target_prog_ids` / `apply_prog_ids` collapse did not break SCX live-id remap in the current tree.
  - Evidence: `e2e/cases/scx/case.py:263-289` remaps logical ids to live ids by program name; `:625-648` uses `resolve_rejit_prog_ids(...)` to hand daemon scan/apply the live ids; `:593-605` remaps again for post-ReJIT workload sampling.
  - Conclusion: the shared state simplification is still behaviorally correct for SCX reload/remap.

- `FA3` Tetragon’s deleted implicit `inspect_tetragon_setup()` fallback is an acceptable contract tightening.
  - Evidence: `runner/libs/app_runners/tetragon.py:252-255` now requires `setup_result`, and the only live caller already passes it at `e2e/cases/tetragon/case.py:609`.
  - Conclusion: this now fails fast on a future bad caller, but there is no live regression in the current repo.

- `FA4` Deleting synthetic `counts.total_sites` / `counts.applied_sites` did not break the current daemon contract.
  - Evidence: current reader path accepts canonical `passes` or `summary.total_sites_applied` at `runner/libs/rejit.py:513-544`; current daemon write path emits `summary.total_sites_applied` on both changed and unchanged `ok` responses at `daemon/src/commands.rs:727-757`; pipeline helpers still maintain `total_sites_applied` at `daemon/src/pass.rs:817-888`.
  - Conclusion: for the current daemon, the deleted synthetic counts were redundant rather than required.

- `FA5` Deleting `passes[].pass`, `summary.program_changed`, and `message`/`error` fallbacks does not currently break any in-repo reader.
  - Old archived artifacts still contain those legacy fields: e.g. `corpus/results/single-bpftrace_capable.json:281` has `"pass": "map_inline"`, and `e2e/results/tetragon_authoritative_20260328.json:1254` has `"program_changed": false`.
  - But the current in-repo readers consume only canonical fields: `runner/libs/rejit.py:575-623`, `runner/libs/rejit.py:513-544`, `runner/libs/run_artifacts.py:129-207`.
  - Conclusion: archived JSON compatibility may matter for external ad-hoc scripts, but I did not find a live in-tree reanalysis path that still depends on the deleted aliases.

- `FA6` Katran’s “return full program set instead of one collapsed program” is not proven to be a live behavioral regression from the current evidence.
  - Evidence: `runner/libs/app_runners/katran.py:443-464` still derives the attached XDP `prog_id` from live attach metadata, and `e2e/cases/katran/case.py:118-149` now consistently uses `lifecycle.prog_ids`.
  - Conclusion: this remains a coverage gap, not a confirmed bug. Authoritative rerun is still needed to prove or disprove side effects on non-data-plane Katran programs.

## Part 4 — Round 6 持续删除候选

- `C1` `e2e/cases/scx/case.py:603-604,632-639`
  - Candidate: delete `post_rejit_scheduler_programs`, `baseline_live_program_id_map`, and `baseline_live_scheduler_programs`.
  - Why it looks dead: repo-wide search only found the writes/returns themselves; no later reader consumes those artifacts.
  - Ready diff:

```diff
diff --git a/e2e/cases/scx/case.py b/e2e/cases/scx/case.py
@@
-            if scheduler_programs:
-                lifecycle.artifacts["post_rejit_scheduler_programs"] = [dict(program) for program in scheduler_programs]
             prog_ids = list(scheduler_program_ids)
             return run_phase(runner, workloads, duration_s, agent_pid=runner.pid, prog_ids=prog_ids)
@@
-        lifecycle.artifacts["baseline_live_program_id_map"] = {
-            str(logical_prog_id): int(live_prog_id)
-            for logical_prog_id, live_prog_id in logical_to_live.items()
-        }
-        lifecycle.artifacts["baseline_live_scheduler_programs"] = [dict(program) for program in scheduler_programs]
-        return {
-            "baseline_live_program_id_map": dict(lifecycle.artifacts.get("baseline_live_program_id_map") or {}),
-            "baseline_live_scheduler_programs": list(lifecycle.artifacts.get("baseline_live_scheduler_programs") or []),
-        }
+        return {}
```

- `C2` `runner/libs/app_runners/tracee.py:182`
  - Candidate: delete the `snapshot()["recent_events"]` field only.
  - Why it looks dead: repo-wide search found no reader for `recent_events`; keep `self.events` itself because `wait_for_event()` still uses it at `runner/libs/app_runners/tracee.py:200`.
  - Ready diff:

```diff
diff --git a/runner/libs/app_runners/tracee.py b/runner/libs/app_runners/tracee.py
@@
-            return {"event_counts": dict(self.event_counts), "recent_events": list(self.events),
+            return {"event_counts": dict(self.event_counts),
                     "total_events": self.total_events, "latest_stats": dict(self.latest_stats),
                     "stdout_tail": list(self.stdout_tail), "stderr_tail": list(self.stderr_tail),
                     "event_tail": list(self.event_tail)}
```

- No third pure-dead candidate is strong enough to recommend without falling back into the same orphan/import class that the semantic review already covered.

## Part 5 — 对 VM sample 结果的解读 guide

Coverage reality first:
- `Makefile:109-129` shows `make check` is Python `py_compile`, not behavioral Python tests.
- `tests/` is almost entirely C kernel/daemon coverage (`tests/unittest/*`, `tests/negative/*`); there is no direct Python test for `TraceeOutputCollector`, tracee phase verification, SCX live-id remap, Katran multi-program apply behavior, or suite-temp cleanup.
- So VM smoke and `SAMPLES=1` corpus are still the first place these Python-path behavior regressions would show up.

What VM signals would mean:
- If Tracee fails with `produced zero primary Tracee events` or `produced zero Tracee BPF runtime events`, that is consistent with `B1`, but it is only the gross version. The more dangerous `B1` signature is a run that stays green while `primary_events_total` or `events_per_sec` drops inexplicably between otherwise identical reruns.
- If Tracee stdout/stderr look healthy, BPF counters are non-zero, but event counts are suspiciously low or unstable, prioritize `B1` before chasing workload-level causes.
- If the suite ends with a traceback from `_cleanup_suite_temp_paths()` / `unlink()` / `Permission denied` / `Device or resource busy`, that maps directly to `M1`.
- If corpus/e2e still shows `Invalid argument` on raw-tracepoint-like programs but the app stays overall `ok`, that is not this review’s new blocker; it matches `FA1`, meaning the apply-error degradation path is still live.
- If Katran or SCX show only comparability gaps without a concrete crash, treat them as rerun-required coverage questions first, not as already-proven regressions from these deletion rounds.
