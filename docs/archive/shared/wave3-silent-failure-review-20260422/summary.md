# Wave 3 Silent Failure / Contract Drift Review

Date: 2026-04-22

Scope reviewed: `runner/`, `corpus/`, `e2e/`, `daemon/`, `tests/`, `Makefile`, `micro/`, `bpfopt-suite/` (excluding the user-listed generated/result/vendor paths).  
Read-only validation: `make check` passed.

## CRITICAL

### 1. Runner still treats daemon `applied=true` as "program changed", even on the daemon's explicit no-change path
- Evidence: `daemon/src/commands.rs:748`, `runner/libs/rejit.py:627`, `runner/libs/case_common.py:88`, `runner/libs/case_common.py:483`, `runner/libs/case_common.py:667`
```rust
744             debug.warnings.push(
745                 "final optimized program was unchanged; skipping final REJIT".to_string(),
746             );
747         }
748         return Ok(make_result(
749             "ok",
750             true,
751             false,
```
```python
627             applied = exit_code == 0 and summary_applied
628             applied_sites = total_sites_applied
...
633     return {
634         "applied": applied,
635         "output": output,
```
```python
88 def rejit_result_has_any_apply(rejit_result: Mapping[str, object] | None) -> bool:
89     if not isinstance(rejit_result, Mapping):
90         return False
91     per_program = rejit_result.get("per_program")
92     if isinstance(per_program, Mapping) and per_program:
93         return any(bool(r.get("applied")) for r in per_program.values() if isinstance(r, Mapping))
96     return bool(rejit_result.get("applied")) or applied_sites > 0
```
```python
483         run_post_rejit = rejit_result_has_any_apply(rejit_result)
484         if should_run_post_rejit is not None:
485             run_post_rejit = bool(should_run_post_rejit(rejit_result))
486         if run_post_rejit:
487             post_rejit = workload(setup_state, lifecycle_state, "post_rejit")
```
```python
667         if rejit_result_has_any_apply(rejit_apply):
668             rr = "" if post_measurement is not None else "post-ReJIT measurement is missing"
669             rejit = {"phase": "post_rejit", "status": "ok" if not rr else "error", "reason": rr,
670                      "measurement": post_measurement, **_shared}
```
- Why this is a problem: the daemon intentionally distinguishes transport/apply success from a real code change. The runner collapses those semantics back together and uses `applied` to decide whether to run post-ReJIT measurement and whether missing post-ReJIT data is an error. That can benchmark unchanged programs as if a meaningful ReJIT happened.
- Fix direction: runner-side "did anything change?" logic should key off `changed` / `summary.program_changed` / `total_sites_applied > 0`, not `applied`. Keep `applied` only if you still need a separate "request/syscall succeeded" bit.

## HIGH

### 2. `bpftool prog show` schema drift is silently downgraded to "no programs found"
- Evidence: `runner/libs/agent.py:125`, `runner/libs/app_runners/tracee.py:319`, `runner/libs/app_runners/tracee.py:258`
```python
125     payload = run_json_command([resolve_bpftool_binary(), "-j", "-p", "prog", "show"], timeout=30)
126     if not isinstance(payload, list):
127         return []
```
```python
318 def _current_prog_ids() -> list[int]:
319     parsed = json.loads(run_command([resolve_bpftool_binary(), "-j", "-p", "prog", "show"], timeout=30).stdout)
320     if not isinstance(parsed, list): return []
321     return [int(record["id"]) for record in parsed if isinstance(record, dict) and "id" in record]
```
```python
258                 healthy = wait_healthy(
259                     proc,
260                     self.load_timeout,
261                     lambda: (
262                         _tracee_healthz_ready(TRACEE_HEALTH_HOST, TRACEE_HEALTH_PORT)
...
266                         [item for item in find_bpf_programs(proc.pid or 0) if int(item.get("id", -1)) not in preexisting_ids]
267                     ),
```
- Why this is a problem: a malformed/non-list `bpftool` payload should be a hard contract error. Returning `[]` turns it into a generic "no programs" condition, which then shows up as startup timeout / no-new-programs rather than the real parser or contract failure.
- Fix direction: raise `RuntimeError` with payload-shape context whenever `bpftool` returns the wrong JSON type. Reserve empty lists for genuine "validated payload, but no matching program" cases.

### 3. Malformed `counts.applied_sites` / `counts.total_sites` is silently coerced to `0`
- Evidence: `runner/libs/rejit.py:516`, `e2e/cases/scx/case.py:709`
```python
516 def _adjust_counts_from_raw(counts: dict[str, int], raw_counts: Mapping[str, Any] | None, *, also_total: bool = False) -> None:
517     rc = raw_counts or {}
518     try:
519         reported = max(0, int((rc.get("applied_sites") or (rc.get("total_sites") if also_total else None) or 0)))
520     except (TypeError, ValueError):
521         reported = 0
```
```python
709         "site_totals": applied_site_totals_from_rejit_result(rejit_result if isinstance(rejit_result, Mapping) else None),
710     }
711     applied_site_total = int(((site_summary.get("site_totals") or {}).get("total_sites", 0)) or 0)
712     comparison = (
713         compare_phases(baseline, post_rejit)
714         if applied_site_total > 0
715         else {"comparable": False, "reason": "no scheduler programs changed during ReJIT apply"}
```
- Why this is a problem: any type drift in daemon `counts` fields gets silently flattened into `0`. In SCX, that directly suppresses post-ReJIT comparison and re-labels the run as "no scheduler programs changed", even if the real problem was a malformed response.
- Fix direction: validate `counts` fields strictly and raise on bad types. Only synthesize/adjust missing counters under an explicitly supported legacy contract, not under generic `TypeError` / `ValueError`.

### 4. Daemon silently falls back to `1` CPU when per-CPU map sizing cannot be determined
- Evidence: `daemon/src/bpf.rs:849`, `daemon/src/bpf.rs:878`, `daemon/src/invalidation.rs:39`
```rust
849 pub fn bpf_map_lookup_value_size(info: &BpfMapInfo) -> usize {
850     if is_percpu_map_type(info.map_type) {
851         round_up_8(info.value_size as usize).saturating_mul(possible_cpu_count())
```
```rust
878 fn possible_cpu_count() -> usize {
879     static POSSIBLE_CPU_COUNT: OnceLock<usize> = OnceLock::new();
880     *POSSIBLE_CPU_COUNT.get_or_init(|| read_possible_cpu_count().unwrap_or(1))
881 }
...
883 fn read_possible_cpu_count() -> Option<usize> {
884     let text = std::fs::read_to_string("/sys/devices/system/cpu/possible").ok()?;
885     parse_possible_cpu_list(&text)
886         .or_else(|| std::thread::available_parallelism().ok().map(usize::from))
```
```rust
39 impl MapValueReader for BpfMapValueReader {
40     fn lookup_values_batch(&self, map_fd: u32, keys: &[Vec<u8>]) -> Result<Vec<BatchLookupValue>> {
41         let info = bpf::bpf_map_get_info(map_fd as i32)?;
42         let value_size = bpf::bpf_map_lookup_value_size(&info);
```
- Why this is a problem: this is production-path sizing for per-CPU map lookups. If CPU-topology discovery fails, the daemon silently allocates for one CPU and keeps going, which can skew or break invalidation/map-inline reads on multi-CPU systems without surfacing the real root cause.
- Fix direction: make CPU-count discovery return `Result<usize>` and fail hard when it cannot be read or parsed. Do not silently substitute `1`.

### 5. Tracee event-file parsing silently drops malformed lines and re-labels the run as "zero events"
- Evidence: `runner/libs/app_runners/tracee.py:123`, `runner/libs/app_runners/tracee.py:146`, `e2e/cases/tracee/case.py:460`
```python
123                 if raw_line:
124                     line = raw_line.rstrip()
125                     with self._lock:
126                         self.event_tail.append(line)
127                     self._parse_event_line(line)
```
```python
146     def _parse_event_line(self, line: str) -> None:
147         try:
148             payload = json.loads(line)
149         except json.JSONDecodeError:
150             return
151         if not isinstance(payload, Mapping):
152             return
153         event_name = payload.get("eventName") or payload.get("event_name") or payload.get("name")
154         if not event_name:
155             return
```
```python
460     if int(record.get("primary_events_total", 0) or 0) <= 0:
461         raise RuntimeError(f"{record.get('name')} produced zero primary Tracee events")
462     drops = record.get("drop_counters") or {}
...
465     bpf_summary = (record.get("bpf") or {}).get("summary") or {}
466     if int(bpf_summary.get("total_events", 0) or 0) <= 0:
467         raise RuntimeError(f"{record.get('name')} produced zero selected-program BPF runtime events: {bpf_summary}")
```
- Why this is a problem: the collector is reading the dedicated Tracee event file, not a mixed human log stream. Malformed JSON or missing event-name fields are dropped silently, and the downstream failure becomes a generic zero-events complaint instead of the actual event schema/format break.
- Fix direction: for the event-file path, accumulate parse failures and fail/report them explicitly. Silent skip is only defensible for mixed stdout/stderr streams, not for structured event files.

## MEDIUM

### 6. `sample_bpf_stats(prog_fds=...)` is a dead argument that callers still trust
- Evidence: `runner/libs/bpf_stats.py:44`, `corpus/driver.py:246`
```python
44 def sample_bpf_stats(
45     prog_ids: list[int] | tuple[int, ...],
46     *,
47     prog_fds: dict[int, int] | None = None,
48 ) -> dict[int, dict[str, object]]:
49     del prog_fds
50     wanted = {int(prog_id) for prog_id in prog_ids if int(prog_id) > 0}
```
```python
245     else:
246         initial_stats = sample_bpf_stats(sampled_prog_ids, prog_fds=runner.program_fds)
247     for _ in range(samples):
```
- Why this is a problem: the API advertises a loader-owned-FD path, but the implementation throws it away immediately and samples only by prog_id. That is signature drift: callers can reasonably believe they are getting a stronger truth source than they actually are.
- Fix direction: either remove `prog_fds` from the interface and all callers, or implement and validate the FD-based path for real.

### 7. Katran case CLI flags are effectively dead because the top-level e2e driver never uses the case-local parser
- Evidence: `e2e/cases/katran/case.py:38`, `e2e/cases/katran/case.py:168`, `e2e/driver.py:184`, `e2e/driver.py:602`
```python
38 def build_parser() -> argparse.ArgumentParser:
39     parser = argparse.ArgumentParser(description="Run the Katran end-to-end benchmark case.")
40     parser.add_argument(
41         "--daemon",
...
66         "--smoke-duration",
67         type=int,
68         default=DEFAULT_SMOKE_DURATION_S,
69         help="Smoke-mode workload duration in seconds.",
70     )
71     parser.add_argument(
72         "--iface",
```
```python
168     smoke_duration_s = int(getattr(args, "smoke_duration", DEFAULT_SMOKE_DURATION_S) or DEFAULT_SMOKE_DURATION_S)
169     duration_override = int(getattr(args, "duration", 0) or 0)
170     duration_s = int(duration_override or (smoke_duration_s if args.smoke else DEFAULT_DURATION_S))
171     workload_kind = str(getattr(args, "workload", "") or "network")
172     runner = KatranRunner(
173         iface=str(getattr(args, "iface", DEFAULT_INTERFACE)),
174         router_peer_iface=getattr(args, "router_peer_iface", None),
175         concurrency=int(getattr(args, "concurrency", DEFAULT_CONCURRENCY)),
```
```python
184 def build_parser() -> argparse.ArgumentParser:
185     parser = argparse.ArgumentParser(description="Run the repository end-to-end benchmark suite driver.")
186     parser.add_argument("case", choices=("tracee", "tetragon", "bpftrace", "scx", "bcc", "katran", "all"))
187     parser.add_argument("--suite", default=str(DEFAULT_SUITE))
188     parser.add_argument("--smoke", action="store_true", help="Run the smoke-sized configuration.")
...
602 def main(argv: list[str] | None = None) -> int:
603     parser = build_parser()
604     args = parser.parse_args(argv)
```
- Why this is a problem: Katran-specific flags exist and are read later via `getattr(...)`, but the canonical e2e entrypoint never exposes them. They silently fall back to defaults, so the parser definition is dead and the CLI contract is misleading.
- Fix direction: either merge Katran-specific arguments into `e2e/driver.py`'s parser, or delete the unused case-local parser and keep defaults in one authoritative place.

## LOW

### 8. Suite temp-file cleanup swallows unlink failures
- Evidence: `e2e/driver.py:256`
```python
256 def _cleanup_suite_temp_paths(args: argparse.Namespace) -> None:
257     for raw_path in getattr(args, "_suite_temp_paths", []) or []:
258         try:
259             Path(raw_path).unlink(missing_ok=True)
260         except OSError:
261             continue
```
- Why this is a problem: cleanup failures disappear completely, which makes stale temp files and path/permission regressions harder to diagnose during repeated e2e runs.
- Fix direction: ignore `FileNotFoundError` explicitly, but log or surface other `OSError`s in artifact metadata or stderr.

## Counts

- CRITICAL: 1
- HIGH: 4

## Suggested Fix Order

1. Fix the runner-side `applied` vs `changed` split first. This is the only finding here that can directly manufacture fake post-ReJIT coverage and distort benchmark interpretation.
2. Then make structured-input parsing fail fast: `runner/libs/agent.py`, `runner/libs/app_runners/tracee.py`, and `runner/libs/rejit.py` counts parsing.
3. Remove the daemon CPU-count fallback next; it is production-path silent fallback in map reading.
4. Clean up the dead/drifted interfaces last: `sample_bpf_stats(prog_fds)`, Katran's dead case-local parser, and temp cleanup swallowing.
