# OTel Mid-ReJIT Crash Investigation

Date: 2026-05-03  
Current HEAD: `2093d7a8` (`Fix corpus ReJIT failure artifact scope`)  
Evidence:

- Old failure log before the socket-artifact fix: `/tmp/kvm-8apps-kinsn-1777795577.log`
- Old failure log after the socket-artifact fix: `/tmp/vm-corpus-failure-export-full-1777819749.log`
- Current single-app rerun: `/tmp/otel-fullpass-20260503.log`
- Current 12-app prefix rerun: `/tmp/otel-prefix-12apps-20260503.log`
- Current successful result dirs:
  - `corpus/results/x86_kvm_corpus_20260503_151052_661801`
  - `corpus/results/x86_kvm_corpus_20260503_151406_373421`

---

## Symptom

Two previous corpus runs reached `otelcol-ebpf-profiler/profiling`, completed its baseline
measurement, printed:

```text
{"app": "otelcol-ebpf-profiler/profiling", "event": "rejit_start", "program_count": 13, "runner": "otelcol-ebpf-profiler"}
```

and then the outer VM target exited with:

```text
[run-target-suite][ERROR] preserved debug artifact: ...
make: *** [Makefile:112: vm-corpus] Error 255
```

There was no `rejit_done`, no `app_done`, no per-program daemon response, and no
`details/apps/otelcol-ebpf-profiler__profiling.json` for the failed run.

---

## Old Failure Evidence

### `/tmp/kvm-8apps-kinsn-1777795577.log`

The run completed these apps successfully before OTel:

```text
bcc/capable
bcc/execsnoop
bcc/bindsnoop
bcc/biosnoop
bcc/vfsstat
bcc/opensnoop
bcc/syscount
bcc/tcpconnect
bcc/tcplife
bcc/runqlat
calico/felix
```

OTel then completed baseline measurement and stopped immediately after `rejit_start`
with `program_count: 13`. The preserved debug artifact directory was:

```text
.state/runner-contracts/run.x86-kvm.corpus.36f49337
```

That directory contains no files. There is no daemon stderr tail, console log, or
per-program response in the preserved artifact.

### `/tmp/vm-corpus-failure-export-full-1777819749.log`

This run happened after `2093d7a8` and shows the same shape:

```text
{"app": "otelcol-ebpf-profiler/profiling", "event": "measurement_done", "phase": "baseline", "runner": "otelcol-ebpf-profiler", "status": "ok"}
{"app": "otelcol-ebpf-profiler/profiling", "event": "rejit_start", "program_count": 13, "runner": "otelcol-ebpf-profiler"}
[run-target-suite][ERROR] preserved debug artifact: /home/yunwei37/workspace/bpf-benchmark/.state/runner-contracts/run.x86-kvm.corpus.3e770163
make: *** [Makefile:112: vm-corpus] Error 255
```

The preserved debug artifact directory is also empty. The result dir
`corpus/results/x86_kvm_corpus_20260503_145110_428181` contains completed app JSON
files through `calico__felix.json`, but no OTel app JSON. Its metadata status is still
`running`, which means the Python corpus driver did not get far enough to finalize the
run or write OTel's incremental app result.

---

## Current Reproduction Attempts

### OTel single-app run

Command:

```bash
VM_CORPUS_TIMEOUT=600 \
BPFREJIT_BENCH_PASSES="rotate,cond_select,extract,endian_fusion,bulk_memory,prefetch" \
BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
make vm-corpus SAMPLES=1
```

Result: success.

```text
{"app": "otelcol-ebpf-profiler/profiling", "event": "rejit_start", "program_count": 13, "runner": "otelcol-ebpf-profiler"}
{"app": "otelcol-ebpf-profiler/profiling", "event": "rejit_done", "runner": "otelcol-ebpf-profiler", "status": "ok"}
{"app": "otelcol-ebpf-profiler/profiling", "error": "", "event": "app_done", "status": "ok"}
```

Result dir: `corpus/results/x86_kvm_corpus_20260503_151052_661801`

### 12-app prefix run

This reran the same prefix visible in both old failure logs, ending with OTel:

```bash
VM_CORPUS_TIMEOUT=900 \
BPFREJIT_BENCH_PASSES="rotate,cond_select,extract,endian_fusion,bulk_memory,prefetch" \
BPFREJIT_CORPUS_APPS="bcc/capable,bcc/execsnoop,bcc/bindsnoop,bcc/biosnoop,bcc/vfsstat,bcc/opensnoop,bcc/syscount,bcc/tcpconnect,bcc/tcplife,bcc/runqlat,calico/felix,otelcol-ebpf-profiler/profiling" \
make vm-corpus SAMPLES=1
```

Result: success.

```text
{"app": "otelcol-ebpf-profiler/profiling", "event": "rejit_start", "program_count": 13, "runner": "otelcol-ebpf-profiler"}
{"app": "otelcol-ebpf-profiler/profiling", "event": "rejit_done", "runner": "otelcol-ebpf-profiler", "status": "ok"}
{"app": "otelcol-ebpf-profiler/profiling", "error": "", "event": "app_done", "status": "ok"}
```

Result dir: `corpus/results/x86_kvm_corpus_20260503_151406_373421`

The OTel app result has:

```json
{
  "program_counts": {
    "requested": 13,
    "applied": 13,
    "not_applied": 0
  },
  "exit_code": 0,
  "changed": true,
  "error": ""
}
```

No `details/failures/` directory was created, which is correct for a no-failure run.

---

## Host State Checks

The docker loop image path requested for inspection is not present after the completed
runs:

```text
df -h /var/tmp/bpf-benchmark-docker.img
df: /var/tmp/bpf-benchmark-docker.img: No such file or directory
```

That is expected for these KVM target runs because the runner removes the temporary
docker disk image after teardown. `docker ps -a --no-trunc` showed no retained
containers. Host journal queries over the old failure windows did not return OOM,
`Killed process`, docker overlay, loop-device, read-only filesystem, or no-space
entries.

---

## OTel Program Set

The current successful 12-app prefix run discovered these 13 programs:

```text
120 perf_unwind_stop                 perf_event bytes_xlated=6232  bytes_jited=3721
121 perf_unwind_native               perf_event bytes_xlated=37232 bytes_jited=22575
122 perf_unwind_hotspot              perf_event bytes_xlated=28048 bytes_jited=18290
123 perf_unwind_perl                 perf_event bytes_xlated=29144 bytes_jited=17737
124 perf_unwind_php                  perf_event bytes_xlated=25032 bytes_jited=15178
125 perf_unwind_python               perf_event bytes_xlated=33264 bytes_jited=19909
126 perf_unwind_ruby                 perf_event bytes_xlated=28000 bytes_jited=16540
127 perf_unwind_v8                   perf_event bytes_xlated=33712 bytes_jited=20050
128 perf_unwind_dotnet               perf_event bytes_xlated=34248 bytes_jited=22565
129 perf_go_labels                   perf_event bytes_xlated=2496  bytes_jited=1580
130 perf_unwind_beam                 perf_event bytes_xlated=1088  bytes_jited=696
131 tracepoint__sched_process_free   tracepoint  bytes_xlated=1320  bytes_jited=788
132 native_tracer_entry              perf_event bytes_xlated=5496  bytes_jited=3532
```

For all 13 programs, the current run shows only `prefetch` changed bytecode. The
first five passes matched zero sites:

```text
120 prefetch sites_applied=15
121 prefetch sites_applied=98
122 prefetch sites_applied=35
123 prefetch sites_applied=48
124 prefetch sites_applied=27
125 prefetch sites_applied=40
126 prefetch sites_applied=41
127 prefetch sites_applied=48
128 prefetch sites_applied=44
129 prefetch sites_applied=2
130 prefetch sites_applied=3
131 prefetch sites_applied=2
132 prefetch sites_applied=12
```

If the old crash was tied to an actual OTel transformed ReJIT candidate, the best
inference is therefore `prefetch`, but the old artifacts do not identify a specific
program. Current `2093d7a8` reruns apply `prefetch` successfully to all 13 programs.

---

## Root-Cause Classification

### Daemon crash

Not proven. The old logs do not show the normal daemon-crash symptoms the Python driver
usually surfaces, such as `daemon socket returned an empty response`, a socket error, or
the daemon stderr tail. The run exits at the outer VM target boundary with code 255 before
the corpus driver writes OTel's app result.

The absence of a daemon response means a daemon crash is possible, but the available
artifacts cannot distinguish it from a guest/VM termination.

### KVM VM / vng termination

Most consistent with the old evidence. The only error emitted is from
`run-target-suite`, and both preserved debug artifact directories are empty. That points
to the outer VM wrapper exiting before the guest corpus driver could report a structured
Python exception or write incremental OTel result JSON.

### Docker container killed

Not supported by current evidence. There are no retained docker containers after the
runs, no preserved docker error, and the old log does not contain the `read-only file
system` / overlay cleanup failures seen in the tetragon 287-program disk-full incident.

### Host OOM

Unlikely. Host journal queries for the relevant windows produced no OOM-killer entries
or `Killed process` evidence. Current reruns succeed with the same OTel program set and
the same pass list.

### Docker disk full

Unlikely. The tetragon 287-program failure had strong disk-full signatures:
large preserved failure workdir accumulation, read-only filesystem errors, and docker
overlay cleanup failures. The OTel old logs have none of those signatures. Current OTel
runs create no failure artifacts and complete successfully.

### Kernel page cap / E2BIG

Not supported for OTel. Tracee prog 43 reproducibly returns E2BIG and now exports
`details/failures/43/`. OTel does not reproduce that behavior: all 13 OTel programs
complete `BPF_PROG_REJIT` with `exit_code: 0`, and no `details/failures/` directory is
created.

---

## Conclusion

The OTel mid-ReJIT `exit 255` is **not reproducible on current HEAD `2093d7a8`**.
Both the single-app OTel run and the 12-app prefix matching the old failure sequence
completed successfully with all 13 programs applied.

The old artifacts prove only that the run died after OTel baseline measurement and after
the `rejit_start` event. They do not contain enough data to identify a specific
program/pass or to prove daemon crash vs guest/VM termination. Based on the error shape,
the most likely classification is **VM/vng-level termination before the Python corpus
driver could receive or serialize the daemon response**. If it was tied to an OTel pass,
`prefetch` is the most plausible pass because it is the only pass that currently changes
OTel bytecode, but current reruns show every OTel `prefetch` candidate succeeds.

No code fix is recommended from the current evidence. If the issue recurs, the next run
needs preserved VM console output or an equivalent vng/qemu exit reason; the current
empty debug artifact directories are insufficient to distinguish daemon death from VM
death.
