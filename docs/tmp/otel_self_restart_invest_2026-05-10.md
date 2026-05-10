# OTEL eBPF profiler self-restart / reload investigation

Date: 2026-05-10

## Verdict

**Refuted for the bundled `otelcol-ebpf-profiler` version.**

The corpus image downloads the official `otelcol-ebpf-profiler` release `0.140.0` (`runner/containers/runner-runtime.Dockerfile:211-284`). That collector distribution pins `go.opentelemetry.io/ebpf-profiler v0.0.202547` (`/tmp/otel_collector_releases_v0.140.0/distributions/otelcol-ebpf-profiler/manifest.yaml:27-29`), cloned for this investigation at:

- `/tmp/otel_profiler_v202547`
- tag `v0.0.202547`
- commit `646ba4cdaca904ae53959c45e2aea16f58a57be3`

In that source, the agent loads BPF programs during receiver startup, stores the resulting `*ebpf.Program` handles, then attaches/enables them. I found no code path that reloads programs after startup, watches BPF program state, responds to `BPF_PROG_REJIT`, or handles `SIGHUP`/`SIGUSR*` as a reload trigger.

So the specific hypothesis, "OTEL sees ReJIT and reloads its own programs, replacing IDs 6-18", is not supported by the shipped source. The program-ID disappearance likely comes from a different lifecycle event, such as the profiler process closing/exiting, collector shutdown, or a kernel/framework-side interaction that drops the original program objects.

## Evidence

### Exact shipped source

The runtime Dockerfile does not build from local OTEL source. It downloads:

- `OTELCOL_EBPF_PROFILER_VERSION=0.140.0`
- GitHub release asset `otelcol-ebpf-profiler_${OTELCOL_EBPF_PROFILER_VERSION}_linux_${otel_arch}.tar.gz`

Source reference: `runner/containers/runner-runtime.Dockerfile:211-284`.

The official collector release manifest for tag `v0.140.0` uses the profiling receiver module:

- `/tmp/otel_collector_releases_v0.140.0/distributions/otelcol-ebpf-profiler/manifest.yaml:27-29`
- `go.opentelemetry.io/ebpf-profiler v0.0.202547`
- import `go.opentelemetry.io/ebpf-profiler/collector`

### Startup is the only persistent BPF program load path

Collector receiver startup calls the internal controller once:

- `/tmp/otel_profiler_v202547/internal/controller/controller.go:75-99`
- key line: `trc, err := tracer.NewTracer(...)`

After that, the controller only attaches/enables the already-loaded tracer:

- `AttachTracer`: `/tmp/otel_profiler_v202547/internal/controller/controller.go:108-112`
- optional off-CPU/probe attach: `/tmp/otel_profiler_v202547/internal/controller/controller.go:114-125`
- perf-event enable or probabilistic enable/disable: `/tmp/otel_profiler_v202547/internal/controller/controller.go:128-135`
- scheduler monitor attach: `/tmp/otel_profiler_v202547/internal/controller/controller.go:137-143`

`NewTracer` loads maps/programs once and stores them in the `Tracer` struct:

- `/tmp/otel_profiler_v202547/tracer/tracer.go:211-250`
- key line: `ebpfMaps, ebpfProgs, err := initializeMapsAndPrograms(...)`

`initializeMapsAndPrograms` loads the embedded collection spec, creates maps, rewrites map references, then loads the selected programs:

- load collection spec: `/tmp/otel_profiler_v202547/tracer/tracer.go:295-298`
- load maps: `/tmp/otel_profiler_v202547/tracer/tracer.go:315-327`
- load perf unwinder programs: `/tmp/otel_profiler_v202547/tracer/tracer.go:402-405`
- optional kprobe/off-CPU/uprobe programs: `/tmp/otel_profiler_v202547/tracer/tracer.go:407-445`

The persistent program loader is:

- `/tmp/otel_profiler_v202547/tracer/tracer.go:650-690`
- key line: `unwinder, err := cebpf.NewProgramWithOptions(...)`
- it stores the handle at `/tmp/otel_profiler_v202547/tracer/tracer.go:679`
- it updates the tail-call map at `/tmp/otel_profiler_v202547/tracer/tracer.go:684-690`

I searched the shipped source for other production program-load APIs:

```text
rg -n "NewProgram\(|NewProgramWithOptions\(" /tmp/otel_profiler_v202547 -g '*.go'
```

Only two production load sites appear:

- `/tmp/otel_profiler_v202547/tracer/tracer.go:663`
- `/tmp/otel_profiler_v202547/tracer/systemconfig.go:140`

The remaining match is an integration test.

### The other `NewProgram` is a short-lived startup analysis helper

The second production load site is not a reload/watchdog path. It is a transient system-analysis program used while determining kernel layout:

- `/tmp/otel_profiler_v202547/tracer/systemconfig.go:113-168`
- key lines: `prog, err := cebpf.NewProgram(...)`, then `defer prog.Close()`
- it attaches to either raw `sys_enter` or `syscalls/sys_enter_bpf`
- it closes the link before returning at `/tmp/otel_profiler_v202547/tracer/systemconfig.go:161-162`

The BPF code only reads kernel memory/task-struct data for the agent's own PID:

- `/tmp/otel_profiler_v202547/support/ebpf/system_config.ebpf.c:18-46`
- `/tmp/otel_profiler_v202547/support/ebpf/system_config.ebpf.c:48-87`

This is the only `sys_enter_bpf` hook in the shipped source. It does not inspect the BPF command, does not mention `BPF_PROG_REJIT`, and is not retained after initialization.

### Attach paths reuse existing program handles

The main perf-event attach path retrieves an existing handle:

- `/tmp/otel_profiler_v202547/tracer/tracer.go:983-1018`
- key line: `tracerProg, ok := t.ebpfProgs["native_tracer_entry"]`
- attach is via `perfEvent.SetBPF(uint32(tracerProg.FD()))`

The scheduler monitor also uses an existing handle:

- `/tmp/otel_profiler_v202547/tracer/tracepoints.go:31-42`
- key line: `t.ebpfProgs[name]`

Off-CPU/probe attach paths are the same pattern:

- `/tmp/otel_profiler_v202547/tracer/tracer.go:1095-1163`

There is no detach-then-load replacement path in these attach functions.

### Timers do not reload BPF programs

The timers in the shipped source are for map polling, metric reporting, process cleanup, and perf-event enable/disable:

- PID cleanup ticker: `/tmp/otel_profiler_v202547/tracer/events.go:39-57`
- trace perf-buffer poll ticker: `/tmp/otel_profiler_v202547/tracer/events.go:137-178`
- map/metric monitor timers: `/tmp/otel_profiler_v202547/tracer/tracer.go:942-980`
- probabilistic profiling timer: `/tmp/otel_profiler_v202547/tracer/tracer.go:1080-1092`
- interpreter metrics timer: `/tmp/otel_profiler_v202547/processmanager/manager.go:141-170`
- reporter timers: `/tmp/otel_profiler_v202547/reporter/runloop.go:19-38`

The probabilistic timer only calls `event.Enable()` / `event.Disable()` on existing perf events:

- `/tmp/otel_profiler_v202547/tracer/tracer.go:1040-1078`

No timer calls `initializeMapsAndPrograms`, `loadProgram`, `NewTracer`, `NewProgramWithOptions`, or any libbpf load API.

### Signals do not trigger reload

Standalone `main.go` handles only termination signals:

- `/tmp/otel_profiler_v202547/main.go:90-91`
- signals: `SIGINT`, `SIGTERM`, `SIGABRT`

Repository-wide search found no `SIGHUP`, `SIGUSR1`, or `SIGUSR2` handlers in the shipped source.

### No BPF program state watcher

I searched the exact shipped source for:

```text
ProgramInfo
BPF_OBJ_GET_INFO
BPF_PROG_REJIT
BPF_PROG_LOAD
bpf_prog_load
LoadPinnedProgram
LoadAndAssign
LoadCollection(
Program.Info(
```

There were no production matches. That means the profiler is not querying its own program state via `BPF_OBJ_GET_INFO_BY_FD`, watching program IDs, or dispatching on ReJIT-specific state changes.

### Current local `main` note

The local checkout at `runner/repos/opentelemetry-ebpf-profiler` is newer than the shipped `v0.0.202547` source. It contains a kallsyms refresh hook:

- `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/kallsyms.ebpf.c:5-10`
- `runner/repos/opentelemetry-ebpf-profiler/tracer/tracer.go:1169-1191`
- `runner/repos/opentelemetry-ebpf-profiler/tracer/events.go:80-88`

That hook attaches to `bpf_ksym_add` and sends `EVENT_TYPE_RELOAD_KALLSYMS`; userspace then calls `kernelSymbolizer.Reload()`. This reloads kernel symbol metadata only. It does not call any BPF program load or attach function and is not present in the shipped `v0.0.202547` receiver used by `0.140.0`.

## Answers to the specific questions

1. **Does the agent call `bpf_prog_load` or libbpf program reload after initial load?**
   No. The persistent load is `cebpf.NewProgramWithOptions` during `initializeMapsAndPrograms`; no later load path was found.

2. **Is there a watchdog goroutine that periodically reloads programs?**
   No. Periodic goroutines poll maps, metrics, trace buffers, interpreter metrics, and reporter output.

3. **Is there a "prog state changed" callback that triggers reload?**
   No. No `Program.Info`, `BPF_OBJ_GET_INFO`, or program-state watcher exists in the shipped source.

4. **Does signal handling trigger reload?**
   No. The standalone binary handles `SIGINT`, `SIGTERM`, and `SIGABRT` for termination only. No `SIGHUP`/`SIGUSR*` reload path exists.

5. **Does the agent watch its own BPF programs via `BPF_OBJ_GET_INFO_BY_FD`?**
   No. No matching code was found.

6. **Are there timers that periodically detach + re-attach + re-load?**
   No. Timers do not call load/attach replacement paths. Probabilistic profiling toggles existing perf events only.

7. **Does the agent react to `BPF_PROG_REJIT`?**
   No evidence in the shipped version. It has a short-lived startup `sys_enter_bpf` helper, but that helper reads kernel layout data for the agent PID and is closed before normal operation.

## Trigger

There is no OTEL-triggered BPF program reload trigger in the shipped source.

The only trigger for persistent BPF program loading is receiver startup:

`collector/internal.Controller.Start` -> `internal/controller.Controller.Start` -> `tracer.NewTracer` -> `initializeMapsAndPrograms` -> `loadProgram`.

## Mitigation options

### Disable reload via OTEL config flag

No such flag exists because no BPF program reload path exists in the shipped source.

Relevant config fields are unrelated:

- `probabilistic_threshold`: controls periodic enable/disable of existing perf events.
- `load_probe`: controls loading an extra generic probe program.
- `off_cpu_threshold`: controls optional off-CPU programs.
- `tracers`: controls which interpreter unwinder programs/maps are enabled.

None disables a self-reload/watchdog because there is no such code path.

### Patch agent

Patching OTEL to disable reload would not address this symptom.

Useful last-resort patches would instead be observability patches:

- log current BPF program IDs after startup and before shutdown;
- expose current program IDs/FDS through a debug endpoint;
- pin programs or links under bpffs for external inspection;
- emit a clear log if `Tracer.Close()` runs.

Those patches would help distinguish "agent process closed all FDs" from "kernel/framework replaced program objects".

### Use long-lived program ID by attach point

No stable attach-point program ID exists here.

The agent keeps private Go `*ebpf.Program` handles in `t.ebpfProgs`. External code sees kernel-assigned program IDs, which are object IDs, not stable attach-point identities. Perf-event attachments do not provide a durable bpffs object to look up by attach point. Tail-called programs are reachable through prog-array map values, but those are FDs inside OTEL-owned maps, not stable IDs.

If IDs truly change, a rescan-by-name/tag/map relationship could discover the replacement objects, but that would be a different measurement contract and would hide the lifecycle problem rather than explain it.

## Confidence

**High** for refuting OTEL self-reload in the bundled `otelcol-ebpf-profiler 0.140.0` / `go.opentelemetry.io/ebpf-profiler v0.0.202547` source.

Residual risk: I did not disassemble the release binary or audit the full OpenTelemetry Collector runtime internals. The pinned receiver source itself has no reload path, and the collector wrapper starts/shuts down that receiver; it does not contain profiler-specific reload logic.
