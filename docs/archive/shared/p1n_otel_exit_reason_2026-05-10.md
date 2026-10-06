# P1-N OTEL exit reason after ReJIT

Date: 2026-05-10

## Diagnostic patch diff

```diff
diff --git a/corpus/driver.py b/corpus/driver.py
index d59da874..0c3000a9 100644
--- a/corpus/driver.py
+++ b/corpus/driver.py
@@ -490,6 +490,22 @@ def _build_app_result_from_lifecycle(
     )
 
 
+def _record_process_diagnostic(
+    session: "CorpusAppSession",
+    result: LifecycleRunResult,
+) -> None:
+    snapshot_fn = getattr(session.runner, "process_diagnostic_snapshot", None)
+    if not callable(snapshot_fn):
+        return
+    snapshot = snapshot_fn()
+    if not isinstance(snapshot, Mapping):
+        raise RuntimeError(f"{session.app.name}: process diagnostic snapshot was not a mapping")
+    result_details = result.state.artifacts.get("result_details") if result.state is not None else None
+    details = dict(result_details) if isinstance(result_details, Mapping) else {}
+    details["process"] = dict(snapshot)
+    result.state.artifacts["result_details"] = details
+
+
 @dataclass
 class CorpusAppSession:
     app: AppSpec
@@ -597,6 +613,7 @@ def _run_suite_lifecycle_sessions(
                         status="error",
                         error=str(exc),
                     )
+                    _record_process_diagnostic(session, result)
                     record_baseline_failure(session, result, str(exc))
             check_daemon()
 
@@ -692,6 +709,7 @@ def _run_suite_lifecycle_sessions(
                     status="ok",
                 )
             except Exception as exc:
+                _record_process_diagnostic(session, result)
                 result.error = str(exc)
                 _print_progress(
                     "measurement_done",
diff --git a/runner/libs/app_runners/process_support.py b/runner/libs/app_runners/process_support.py
index 6a7b5fd6..c08984d5 100644
--- a/runner/libs/app_runners/process_support.py
+++ b/runner/libs/app_runners/process_support.py
@@ -269,6 +269,16 @@ class ManagedProcessSession:
     def collector_snapshot(self) -> dict[str, object]:
         return self.collector.snapshot()
 
+    def diagnostic_snapshot(self) -> dict[str, object]:
+        snapshot = self.collector.snapshot()
+        process = self.process
+        return {
+            "pid": None if process is None else int(process.pid or 0),
+            "returncode": None if process is None else process.poll(),
+            "stdout_tail": "\n".join(snapshot.get("stdout_tail") or []),
+            "stderr_tail": "\n".join(snapshot.get("stderr_tail") or []),
+        }
+
     def close(self) -> None:
         if self.process is not None:
             stop_agent(self.process, timeout=80)
@@ -371,6 +381,16 @@ class NativeProcessRunner(AppRunner):
             raise RuntimeError(f"{type(self).__name__} workload spec is missing a workload kind")
         return run_named_workload(requested_kind, seconds)
 
+    def process_diagnostic_snapshot(self) -> dict[str, object]:
+        if self.session is not None:
+            return self.session.diagnostic_snapshot()
+        return {
+            "pid": None,
+            "returncode": self.process_output.get("returncode"),
+            "stdout_tail": str(self.process_output.get("stdout_tail") or ""),
+            "stderr_tail": str(self.process_output.get("stderr_tail") or ""),
+        }
+
     def stop(self) -> None:
         if self.session is None:
             return
```

## Corpus run

Command:

```sh
SAMPLES=1 WORKLOAD_DURATION=10 KEEP_WORKDIRS=1 BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" make corpus
```

Latest result directory:

```text
/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260510_184345_155237
```

Per-app artifact:

```text
/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260510_184345_155237/details/apps/otelcol-ebpf-profiler__profiling.json
```

The run reproduced the same framework-side symptom:

```text
BPF stats missing requested program IDs: 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18
```

## Captured process diagnostic

JSON path:

```text
.runner_details.process
```

Captured values:

```json
{
  "pid": 1863,
  "returncode": 2,
  "stdout_tail": ""
}
```

Decisive stderr tail:

```text
2026-05-10T18:43:54.651Z	info	Profiles	... "sample records": 1374}
2026-05-10T18:44:00.144Z	info	Profiles	... "sample records": 1893}
2026-05-10T18:44:05.711Z	info	Profiles	... "sample records": 1570}
panic: trace record too small

goroutine 74 [running]:
go.opentelemetry.io/ebpf-profiler/tracer.(*Tracer).loadBpfTrace(...)
	go.opentelemetry.io/ebpf-profiler@v0.0.202547/tracer/tracer.go:873 +0x4f2
go.opentelemetry.io/ebpf-profiler/tracer.(*Tracer).startTraceEventMonitor.func1()
	go.opentelemetry.io/ebpf-profiler@v0.0.202547/tracer/events.go:217 +0x34a
created by go.opentelemetry.io/ebpf-profiler/tracer.(*Tracer).startTraceEventMonitor in goroutine 1
	go.opentelemetry.io/ebpf-profiler@v0.0.202547/tracer/events.go:153 +0x245
```

## Verdict

OTEL died from a Go panic in its userspace trace-event reader after ReJIT:

```text
panic: trace record too small
```

This is not an external signal, not a clean shutdown, and not a segfault. The process return code was `2`, which matches a Go panic exit. Once that process exited, it dropped its BPF program/link FDs, which explains why program IDs 6-18 disappeared before the post-ReJIT stats sample.

Root-cause interpretation: a reJITed OTEL BPF program emitted a malformed or truncated `trace_events` perf sample. OTEL then panicked while parsing that raw BPF trace in `Tracer.loadBpfTrace`. The directly attached program with nonzero baseline execution is `native_tracer_entry` (ID 18), and ReJIT applied transformations to it (`cond_select`, `map_inline`, `dce`, `bulk_memory`, `prefetch`). Tail-called `perf_unwind_*` programs were also transformed, so pass isolation must consider caller plus tail-call descendants.

## Confidence

Confidence: high.

Evidence:

- The diagnostic snapshot was captured before `runner.stop()`, so `returncode: 2` is the live process state at measurement failure time.
- Stderr contains an explicit panic and stack in OTEL code: `panic: trace record too small`, `Tracer.loadBpfTrace`, `startTraceEventMonitor`.
- The framework error immediately after ReJIT is missing all OTEL IDs, consistent with the OTEL process exiting and closing its BPF references.

## Mitigation proposal

Do not add framework exclusions, fallback loaders, or ReJIT filters. The benchmark should keep surfacing this as a real app failure.

Next root-cause step: isolate the first pass that causes the malformed trace record with make-only OTEL runs such as `BPFREJIT_BENCH_PASSES="<single-pass>" ... make corpus`, then inspect the transformed bytecode around the `trace_events`/`bpf_perf_event_output` write path. Prioritize `native_tracer_entry` and any tail-called `perf_unwind_*` descendant whose transformed code contributes to trace record construction. The fix should preserve the trace record ABI: stack buffer initialization, record size argument, and helper-call register values must be unchanged unless a pass proves the rewrite is semantics-preserving.

OTEL-side hardening is also useful, but secondary: malformed trace records should be logged and the receiver should stop or drop the record instead of panicking the whole process. That would prevent ID disappearance from process death, but it would not fix the ReJIT correctness bug that generated the bad record.
