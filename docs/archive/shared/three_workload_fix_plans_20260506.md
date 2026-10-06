# Three Workload Fix Plans

Date: 2026-05-06

Scope: plans only. Do not implement these together. Implement one app plan, run the app-specific corpus target through `make`, inspect raw `result.json` counters externally, then move to the next plan.

Input docs read:
- `docs/kernel-jit-optimization-plan.md`: app-native loaders, runner socket boundary, Makefile-only benchmark entrypoint, and min-runs paper-grade rule.
- `docs/tmp/corpus_workload_coverage_audit_20260506.md`: app coverage gaps and exact unqualified program rows.
- `CLAUDE.md`: no ReJIT filtering, no in-framework summaries, app-level loader only, fail-fast behavior, and Makefile-only runs.

Recommended first implementation: OTEL profiler.

Why: the first useful OTEL slice requires no root-only kernel side effects, no module load/unload, and no Tetragon selector semantics change. Python, Node/V8, Ruby, Perl, and PHP are already in the runner image at `runner/containers/runner-runtime.Dockerfile:89-96`; the remaining blockers are Java, dotnet, and BEAM packaging. Tracee is second because it depends on module-load behavior and root capabilities. Tetragon is last because qualifying every dormant generic tail requires matching multiple policy selectors and proving the policy-to-program mapping after the run.

## Tetragon

### Root Cause

`tetragon/observer` loads the whole policy directory through `--tracing-policy-dir` in `runner/libs/app_runners/tetragon.py:168-175`, but the catalog workload is `stress_ng_os_io_network` at `runner/libs/benchmark_catalog.py:28`. That workload excludes process stressors because `_STRESS_NG_PROCESS_STRESSORS` is not part of `stress_ng_os_io_network` in `runner/libs/workload.py:470-501`, so exec lifecycle paths are underdriven and many selector-gated generic kprobe tail calls never advance past entry.

Upstream Tetragon confirms the gate: `generic_kprobe_event` tail-calls the filter path, `generic_process_filter()` only accepts matching selectors, `generic_filter_arg()` only reaches actions for selector-action matches, and `generic_actions()` only posts output when a `Post` action fires (`/tmp/tetragon-src/bpf/process/bpf_generic_kprobe.c:29-41`, `:88-166`; `/tmp/tetragon-src/bpf/process/generic_calls.h:76-78`, `:1323-1390`, `:1463-1493`, `:1127-1162`).

### Exact Files To Edit

- `runner/libs/benchmark_catalog.py:28`: change `tetragon/observer` workload from `stress_ng_os_io_network` to `tetragon_selector_coverage`.
- `runner/libs/app_runners/tetragon.py:113-119`: accept `kind == "tetragon_selector_coverage"` and call a new workload helper.
- `runner/libs/workload.py:1281-1303`: add the new `tetragon_selector_coverage` dispatch helper, returning a raw `WorkloadResult`.
- `runner/assets/tetragon_policies/filename_monitoring.yaml:19-24`, `:39-44`, `:55-60`: add explicit `matchActions: [{action: Post}]` to the existing `/etc/` selectors if the file/mmap/truncate selectors do not reach `generic_kprobe_actions`.
- `runner/assets/tetragon_policies/datagram-with-sock-tracking.yaml:53-55`: remove or raise `rateLimit: "5"` for the benchmark policy path, otherwise `generic_kprobe_actions` and `generic_kprobe_output` cannot reach 100 in a 5-second run.
- `runner/assets/tetragon_policies/tcp-connect-with-selectors.yaml:12-18`, `:24-30`, `:38-44`: leave the selector values as loopback and drive them with workload traffic.
- `runner/assets/tetragon_policies/host-changes/monitor-kernel-modules.yaml:35-52`: leave the `READING_MODULE` selector intact and drive it with `modprobe` only if module coverage is included in this plan's first patch.

### Exact Code Changes / New Workload Commands

Planned runner change: add one workload helper, not per-program filtering. The helper should run deterministic selector-matching operations and return raw stdout/stderr plus operation counters only.

The workload body should be equivalent to this command:

```bash
set -euo pipefail

export BPFBENCH_DURATION="${BPFBENCH_DURATION:-5}"
python3 - <<'PY'
import mmap
import os
import socket
import subprocess
import threading
import time

duration = float(os.environ.get("BPFBENCH_DURATION", "5"))
deadline = time.monotonic() + duration
iters = int(os.environ.get("BPFBENCH_TETRAGON_ITERS", "150"))

path = "/etc/bpfbench-tetragon-selector"
with open(path, "wb") as f:
    f.write(b"x" * 4096)

tcp_srv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcp_srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
tcp_srv.bind(("127.0.0.1", 0))
tcp_srv.listen(128)
tcp_port = tcp_srv.getsockname()[1]
stop = False

def accept_loop():
    tcp_srv.settimeout(0.1)
    while not stop:
        try:
            conn, _ = tcp_srv.accept()
            conn.recv(64)
            conn.close()
        except socket.timeout:
            pass

thread = threading.Thread(target=accept_loop)
thread.start()
udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

ops = {"file": 0, "mmap": 0, "truncate": 0, "tcp": 0, "udp": 0, "exec": 0, "symlink": 0}
for i in range(iters):
    if time.monotonic() >= deadline and i >= 110:
        break

    with open(path, "r+b", buffering=0) as f:
        f.seek(0)
        f.read(1)
        ops["file"] += 1
        os.ftruncate(f.fileno(), 4096 + (i % 2))
        ops["truncate"] += 1
        mm = mmap.mmap(f.fileno(), 4096, access=mmap.ACCESS_READ)
        mm[0:1]
        mm.close()
        ops["mmap"] += 1

    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(("127.0.0.1", tcp_port))
    client.sendall(b"x")
    client.close()
    ops["tcp"] += 1

    udp.sendto(b"x", ("127.0.0.1", 518))
    ops["udp"] += 1

    subprocess.run(["/bin/true"], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    ops["exec"] += 1

    link = f"/tmp/bpfbench-tetragon-link-{i}"
    try:
        os.symlink(path, link)
        with open(link, "rb") as f:
            f.read(1)
        ops["symlink"] += 1
    finally:
        try:
            os.unlink(link)
        except FileNotFoundError:
            pass

stop = True
thread.join(timeout=1.0)
tcp_srv.close()
udp.close()
os.unlink(path)
print(ops)
PY
```

Optional module-selector phase, only if the VM image has loadable modules and root capabilities:

```bash
set -euo pipefail

iters="${BPFBENCH_TETRAGON_MODULE_ITERS:-120}"
for i in $(seq 1 "$iters"); do
    modprobe dummy numdummies=0
    modprobe -r dummy
done
```

Validation run must use the Makefile entrypoint:

```bash
BPFREJIT_CORPUS_APPS="tetragon/observer" SAMPLES=3 make vm-corpus
```

### Validation

External validation inspects raw per-program counters only. No runner summary, ratio, win/loss count, or framework-side qualification logic should be added.

Required raw-counter pass condition: each listed program row must have `baseline.run_cnt_delta >= 100` and `post_rejit.run_cnt_delta >= 100`.

- `event_execve`, audit line 245.
- `tg_kp_bprm_committing_creds`, audit line 441.
- Every `generic_kprobe_process_event` row in audit lines 201-233.
- Every `generic_kprobe_process_filter` row in audit lines 247-279.
- Every `generic_kprobe_filter_arg` row in audit lines 282-314.
- Every `generic_kprobe_actions` row in audit lines 328-360.
- Every `generic_kprobe_output` row in audit lines 372-404.

The audit text calls this "32x" per family, while the table spans 33 rows per generic tail family. Treat the audit table as authoritative during validation: if 33 rows are present, all 33 rows in each family must qualify unless a separate audit proves one row is a duplicate or stale artifact.

### Risks / Blockers

- `generic_kprobe_actions` requires selector actions, not just kprobe entry. The datagram policy already has `matchActions: Post`, but its `rateLimit: "5"` blocks 100-run qualification.
- Some generic program IDs may correspond to policies that this workload cannot trigger in an unprivileged or noninteractive VM, such as TTY or mount-only policies. If so, the blocker is missing policy-to-program mapping, not a reason to filter ReJIT.
- The module phase needs root, `/lib/modules`, and a loadable `dummy` module. If unavailable, leave it out of the first Tetragon patch and document the still-unqualified module-policy rows.
- Adding selector actions changes policy behavior and event volume. Keep the action changes scoped to benchmark policies and avoid adding any in-framework result annotations.
- Tetragon may rate-limit events in userspace even when BPF programs run. Validation is BPF `run_cnt_delta`, not emitted event count.

### Expected Paper-Quotable Benefit

Full target: 165 generic tail programs from 0/0 to qualified, plus `event_execve` and `tg_kp_bprm_committing_creds`, for 167 additional qualifying program rows by the audit table. If the final audited family count is 32 rather than 33, the expected target is 160 generic tails plus 2 exec/security rows.

This plan is not the easiest first implementation because it requires selector-action semantics, possible policy edits, and a policy-to-program-ID check after the run.

## Tracee

### Root Cause

Tracee is already launched with all events enabled through `--events "*"` in `runner/libs/app_runners/tracee.py:204-208`, but `tracee/monitor` still uses `stress_ng_os_io_network` at `runner/libs/benchmark_catalog.py:30`. That workload does not load/unload kernel modules, does not trigger Tracee's internal syscall-table and seq_ops checks during the measured phase, and barely exercises exec security paths.

Upstream Tracee confirms these probes exist and are event-driven: module load/free, LSM bprm/file/module hooks, fixed uprobes for syscall-table/LKM/seq_ops checks, execve/execveat, ptrace, and process_vm_writev are all registered in `/tmp/tracee-src/pkg/ebpf/probes/probe_group.go:204-329`. After the pipeline is ready, Tracee starts the uprobe-trigger routines at `/tmp/tracee-src/pkg/ebpf/tracee.go:1867-1882`; module loads wake the LKM seeker and also trigger syscall-table and seq_ops checks through `/tmp/tracee-src/pkg/ebpf/processor_funcs.go:221-265`.

### Exact Files To Edit

- `runner/libs/benchmark_catalog.py:30`: change `tracee/monitor` workload from `stress_ng_os_io_network` to `tracee_security_coverage`.
- `runner/libs/app_runners/tracee.py:227-231`: accept `kind == "tracee_security_coverage"` and call a new workload helper.
- `runner/libs/workload.py:1281-1303`: add `tracee_security_coverage` dispatch helper, returning raw workload stdout/stderr and operation counts only.
- No Tracee event-policy config change is needed for the first fix because `build_tracee_commands()` already passes `--events "*"` at `runner/libs/app_runners/tracee.py:204-208`.

### Exact Code Changes / New Workload Commands

Planned workload helper: run three deterministic phases in one workload call, then return raw phase operation counts.

Module-load and security-detector phase:

```bash
set -euo pipefail

iters="${BPFBENCH_TRACEE_MODULE_ITERS:-120}"
for i in $(seq 1 "$iters"); do
    modprobe dummy numdummies=0
    modprobe -r dummy
done
```

Execve and execveat storm:

```bash
set -euo pipefail

python3 - <<'PY'
import ctypes
import os
import platform
import subprocess

iters = int(os.environ.get("BPFBENCH_TRACEE_EXEC_ITERS", "180"))
for _ in range(iters):
    subprocess.run(["/bin/true"], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

machine = platform.machine()
if machine in ("x86_64", "amd64"):
    sys_execveat = 322
elif machine in ("aarch64", "arm64"):
    sys_execveat = 281
else:
    raise RuntimeError(f"unsupported execveat arch: {machine}")

libc = ctypes.CDLL(None, use_errno=True)
AT_FDCWD = -100
for _ in range(iters):
    pid = os.fork()
    if pid == 0:
        argv = (ctypes.c_char_p * 2)(b"true", None)
        envp = (ctypes.c_char_p * 1)(None)
        rc = libc.syscall(
            ctypes.c_long(sys_execveat),
            ctypes.c_int(AT_FDCWD),
            ctypes.c_char_p(b"/bin/true"),
            ctypes.byref(argv),
            ctypes.byref(envp),
            ctypes.c_int(0),
        )
        os._exit(0 if rc == 0 else (ctypes.get_errno() or 1))
    _, status = os.waitpid(pid, 0)
    if status != 0:
        raise RuntimeError(f"execveat child failed: status={status}")
PY
```

Magic-write, writev-tail, ptrace, and mount security phase:

```bash
set -euo pipefail

python3 - <<'PY'
import ctypes
import os
import signal

iters = int(os.environ.get("BPFBENCH_TRACEE_MISC_ITERS", "160"))
libc = ctypes.CDLL(None, use_errno=True)

for i in range(iters):
    with open("/proc/self/comm", "w", encoding="utf-8") as f:
        f.write("fake-comm\n")

fd = os.open("/tmp/bpfbench-tracee-writev", os.O_CREAT | os.O_WRONLY | os.O_TRUNC, 0o600)
try:
    for _ in range(iters):
        os.writev(fd, [b"x" * 4096, b"y" * 4096])
finally:
    os.close(fd)
    os.unlink("/tmp/bpfbench-tracee-writev")

PTRACE_TRACEME = 0
for _ in range(iters):
    pid = os.fork()
    if pid == 0:
        rc = libc.ptrace(PTRACE_TRACEME, 0, None, None)
        if rc != 0:
            os._exit(ctypes.get_errno() or 1)
        os.kill(os.getpid(), signal.SIGSTOP)
        os._exit(0)
    os.waitpid(pid, os.WUNTRACED)
    os.kill(pid, signal.SIGCONT)
    _, status = os.waitpid(pid, 0)
    if status != 0:
        raise RuntimeError(f"ptrace child failed: status={status}")
PY

mount_dir=/tmp/bpfbench-tracee-mount
mkdir -p "$mount_dir"
iters="${BPFBENCH_TRACEE_MOUNT_ITERS:-120}"
for i in $(seq 1 "$iters"); do
    mount -t tmpfs bpfbench-tracee "$mount_dir"
    umount "$mount_dir"
done
rmdir "$mount_dir"
```

Validation run must use the Makefile entrypoint:

```bash
BPFREJIT_CORPUS_APPS="tracee/monitor" SAMPLES=3 make vm-corpus
```

### Validation

External validation inspects raw per-program counters only. Required raw-counter pass condition: each listed program row must have `baseline.run_cnt_delta >= 100` and `post_rejit.run_cnt_delta >= 100`.

- LKM seeker family: `lkm_seeker_kset_tail`, `lkm_seeker_modtree_loop`, `lkm_seeker_proc_tail`, `lkm_seeker_new_mod_only_tail`, and `lkm_seeker_mod_tree_tail`, audit lines 525-528, 646, and 659.
- Internal detector uprobes: `uprobe_syscall_table_check`, `uprobe_seq_ops_trigger`, `uprobe_lkm_seeker_submitter`, and `uprobe_lkm_seeker`, audit lines 529, 637, 642, and 645.
- Exec/security path: `trace_security_bprm_check`, `trace_execute_finished`, `syscall__execve_enter`, `syscall__execve_exit`, `syscall__execveat_enter`, and `syscall__execveat_exit`, audit lines 533, 538, and 544-548.
- Write tails: `trace_ret_kernel_write_tail`, `trace_ret_vfs_write_tail`, and `trace_ret_vfs_writev_tail`, audit lines 534-536.
- Module and module-read hooks: `tracepoint__module__module_load`, `tracepoint__module__module_free`, and `trace_security_kernel_read_file`, audit lines 552, 611, and 563.
- Mount hook: `trace_security_sb_mount`, audit line 562.

Do not make `trace_security_settime64` a first-patch validation gate. It is audit line 620, but driving it requires `CAP_SYS_TIME` and can perturb the VM clock. Treat it as a separate blocker unless a time-namespace-safe trigger is proven.

### Risks / Blockers

- `modprobe dummy` needs root, loadable modules for the running kernel, and no existing dummy module users. If it fails, the workload should fail fast rather than silently skipping the detector phase.
- The module loop may exceed the nominal 5-second catalog duration if 120 cycles are slow on the VM. Tune the iteration count down only if raw counters still pass `>=100`.
- `execveat` syscall numbers are architecture-specific. The helper must support x86_64 and arm64 explicitly and fail on unknown architectures.
- Mount/umount loops require `CAP_SYS_ADMIN`; if unavailable, `trace_security_sb_mount` remains a documented blocker.
- `trace_ret_kernel_write_tail` may still need Tracee's magic-write path rather than ordinary file writes. The `/proc/self/comm` `fake-comm` trigger is included to drive that path, but validate before claiming the tail is fixed.

### Expected Paper-Quotable Benefit

First Tracee target: 22 heavy or detector-related program rows from 0/0 or 4/4 to qualified:

- 5 LKM seeker tails.
- 4 internal detector uprobes.
- 6 exec/security rows.
- 3 write-tail rows.
- 3 module/module-read rows.
- 1 mount row.

`trace_security_settime64` is intentionally excluded from the first target because it has a system-clock safety blocker. Tracee is second easiest: event config is already broad, but root/module/mount capabilities are real blockers.

## OTEL Profiler

### Root Cause

`otelcol-ebpf-profiler/profiling` uses `stress_ng_cpu` at `runner/libs/benchmark_catalog.py:26`, so perf samples mostly hit native stress code and the profiler entry program. The heavy language unwinders only run when a sampled PC falls inside a recognized interpreter mapping and `interpreter_offsets` selects that unwinder; current optional idlers in `runner/libs/app_runners/otel_profiler.py:15-21` are not tied to the measured workload, silently skip missing runtimes at `:135-149`, and do not cover HotSpot, dotnet, or BEAM.

Upstream OTEL confirms the mechanism: interpreter loaders are registered for Perl, Python, PHP, HotSpot, Ruby, V8, dotnet, and BEAM in `runner/repos/opentelemetry-ebpf-profiler/processmanager/execinfomanager/manager.go:98-126`; executable mappings are synchronized lazily when a PID/address is encountered in `runner/repos/opentelemetry-ebpf-profiler/processmanager/processinfo.go:445-455`; and `get_next_interpreter()` tail-calls language unwinders only when the PC matches `interpreter_offsets` in `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracemgmt.h:480-500`.

### Exact Files To Edit

- `runner/libs/benchmark_catalog.py:26`: change workload from `stress_ng_cpu` to `otel_language_unwinders`.
- `runner/libs/app_runners/otel_profiler.py:15-21`: replace optional infinite idlers with a required runtime workload table for `python3`, `nodejs`, `ruby`, `perl`, `php`, `java`, `dotnet`, and `erl`.
- `runner/libs/app_runners/otel_profiler.py:113-126`: after profiler start, launch a short warmup set of interpreter processes, sleep long enough for process-manager synchronization, then start measurement workload processes for each phase.
- `runner/libs/app_runners/otel_profiler.py:135-149`: fail fast if a runtime selected for validation is missing; do not silently continue.
- `runner/libs/app_runners/process_support.py:331-334` is the inherited generic workload path; add an `OtelProfilerRunner._run_workload()` override in `runner/libs/app_runners/otel_profiler.py` instead of adding this workload to generic `run_named_workload`, because it needs profiler-specific process management.
- `runner/containers/runner-runtime.Dockerfile:89-98`: Python, Node/V8, Ruby, Perl, and PHP are already installed; add `openjdk-17-jdk-headless` for HotSpot. Add `erlang-base` only if BEAM is a validation gate. Dotnet packaging is a blocker unless `dotnet-runtime-8.0` is available in the base Ubuntu 24.04 repositories or a pinned Microsoft package source is approved.

### Exact Code Changes / New Workload Commands

Planned workload command set. The runner should spawn these processes concurrently for the full measured duration, wait for all of them, and return raw per-runtime stdout/stderr/exit status. The helper should run the same workload in baseline and post-ReJIT phases.

Installed-runtime first slice:

```bash
set -euo pipefail

duration="${BPFBENCH_DURATION:-5}"

python3 - "$duration" <<'PY' &
import math
import sys
import time
deadline = time.monotonic() + float(sys.argv[1])
x = 0.0
while time.monotonic() < deadline:
    x += math.sin(x) * math.cos(x + 1.0)
print(x)
PY

nodejs -e 'const end = Date.now() + Number(process.argv[1]) * 1000; let x = 0; function f(n){ return n < 2 ? n : f(n-1) + f(n-2); } while (Date.now() < end) { x += f(20); } console.log(x);' "$duration" &

ruby -e 'deadline = Time.now + ARGV.fetch(0).to_f; x = 0; while Time.now < deadline; x = (x * 1103515245 + 12345) & 0x7fffffff; end; puts x' "$duration" &

perl -e 'my $end = time() + $ARGV[0]; my $x = 0; while (time() < $end) { $x = ($x * 1103515245 + 12345) & 0x7fffffff; } print "$x\n";' "$duration" &

php -r '$end = microtime(true) + (float)$argv[1]; $x = 0; while (microtime(true) < $end) { $x = ($x * 1103515245 + 12345) & 0x7fffffff; } echo $x, PHP_EOL;' "$duration" &

wait
```

HotSpot phase after adding `openjdk-17-jdk-headless`:

```bash
set -euo pipefail

duration="${BPFBENCH_DURATION:-5}"
tmpdir="$(mktemp -d)"
cat > "$tmpdir/BpfBenchHotspotLoop.java" <<'JAVA'
public final class BpfBenchHotspotLoop {
    public static void main(String[] args) {
        long deadline = System.nanoTime() + (long)(Double.parseDouble(args[0]) * 1_000_000_000L);
        long x = 0;
        while (System.nanoTime() < deadline) {
            x = (x * 1103515245L + 12345L) & 0x7fffffffL;
        }
        System.out.println(x);
    }
}
JAVA
javac "$tmpdir/BpfBenchHotspotLoop.java"
java -Xint -cp "$tmpdir" BpfBenchHotspotLoop "$duration"
rm -rf "$tmpdir"
```

Optional BEAM phase after adding `erlang-base`:

```bash
set -euo pipefail

duration="${BPFBENCH_DURATION:-5}"
erl -noshell -eval '
Duration = list_to_integer(os:getenv("BPFBENCH_DURATION", "5")),
Deadline = erlang:monotonic_time(second) + Duration,
Loop = fun F(X) ->
    case erlang:monotonic_time(second) < Deadline of
        true -> F((X * 1103515245 + 12345) band 16#7fffffff);
        false -> io:format("~p~n", [X])
    end
end,
Loop(0),
halt().
'
```

Optional dotnet phase after packaging is resolved:

```bash
set -euo pipefail

duration="${BPFBENCH_DURATION:-5}"
dotnet /opt/bpfbench/OtelDotnetLoop/OtelDotnetLoop.dll "$duration"
```

The dotnet DLL must be built as a normal image artifact, not generated during the benchmark run. If dotnet packaging is not approved, leave `perf_unwind_dotnet` out of the first validation gate and list it as blocked.

Validation run must use the Makefile entrypoint:

```bash
BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" SAMPLES=3 make vm-corpus
```

### Validation

External validation inspects raw per-program counters only. Required raw-counter pass condition: each listed program row must have `baseline.run_cnt_delta >= 100` and `post_rejit.run_cnt_delta >= 100`.

First slice, using runtimes already in the image plus Java:

- `perf_unwind_native`, audit line 700.
- `perf_unwind_v8`, audit line 702.
- `perf_unwind_python`, audit line 703.
- `perf_unwind_hotspot`, audit line 704, after Java packaging.
- `perf_unwind_perl`, audit line 705.
- `perf_unwind_ruby`, audit line 706.
- `perf_unwind_php`, audit line 707.
- `perf_unwind_stop`, audit line 708.
- `native_tracer_entry` remains qualified as the entry control row, audit line 709.

Blocked until packaging is solved:

- `perf_unwind_dotnet`, audit line 701.
- `perf_unwind_beam`, audit line 712.

Full OTEL success means all 10 real unwinder/stop rows above qualify in both phases. First implementation success is 8 rows: native, V8, Python, HotSpot, Perl, Ruby, PHP, and stop.

### Risks / Blockers

- The current code silently skips missing runtimes at `runner/libs/app_runners/otel_profiler.py:135-149`; the fix must fail fast for any runtime included in the validation gate.
- The profiler synchronizes interpreter mappings lazily. Add a warmup interval after spawning the language processes before taking baseline counters, otherwise the samples may stay on `native_tracer_entry`.
- Java requires adding a JDK package, not just a JRE, because the plan compiles a tiny loop class in the runtime temp dir. To avoid runtime compilation, prebuild the class during image build.
- Dotnet is the largest packaging blocker. Do not add an unpinned external package feed casually; either use a pinned Ubuntu package if available or add a prebuilt, pinned runtime artifact.
- BEAM needs `erlang-base` and may still produce too few samples if the loop spends time in native scheduler code rather than BEAM interpreter frames.
- Increasing `samples_per_second` in `_MINIMAL_CONFIG` is not the first fix. The first fix is making samples land in interpreter loops; only tune sample rate after validating process synchronization.

### Expected Paper-Quotable Benefit

First OTEL target: 8 heavy real unwinder rows from 0/0 to qualified when Java is included: `perf_unwind_native`, V8, Python, HotSpot, Perl, Ruby, PHP, and `perf_unwind_stop`. If the first patch is limited to already-installed runtimes, expected benefit is 7 rows: native, V8, Python, Perl, Ruby, PHP, and stop.

Full target after dotnet and BEAM packaging: 10 rows from 0/0 to qualified, including `perf_unwind_dotnet` and `perf_unwind_beam`.

OTEL is the easiest first implementation because it is ordinary process workload generation, it does not need root-only kernel side effects, and most language runtimes are already present in the runner image.
