# OTEL program ID disappearance investigation

Date: 2026-05-10

Run investigated: `corpus/results/x86_kvm_corpus_20260510_181727_574962/`

## Executive verdict

The most likely cause is: **the OTEL-owned BPF object lifetime ended after the last successful ReJIT syscall and before the first post-ReJIT stats sample**. In concrete terms, all durable references to program IDs 6-18 were closed, most likely because the `otelcol-ebpf-profiler` process exited or the receiver shut down and closed its BPF links/program handles.

The two kernel/daemon ID-mechanics hypotheses are not supported:

- `BPF_PROG_REJIT` does **not** replace the public program object/ID. It swaps a new verified/JITed image into the existing `struct bpf_prog`.
- The daemon opens temporary program FDs and drops them, but that only releases the daemon's extra references. It does not and cannot close the OTEL process's own program/link references.

The remaining gap is process evidence: the latest artifact set does not persist the OTEL process return code or stdout/stderr tail, so the exact exit reason is not recoverable from this run.

## Run facts

Baseline saw the original 13 OTEL program IDs:

- `corpus/results/x86_kvm_corpus_20260510_181727_574962/details/apps/otelcol-ebpf-profiler__profiling.json:5`
  starts baseline ID 6, `perf_unwind_stop`.
- Same baseline object has IDs 7-18 at lines `14, 23, 32, 41, 50, 59, 68, 77, 86, 95, 104, 113`.
- The two programs with nonzero baseline stats are ID 17 and ID 18:
  - `tracepoint__sched_process_free`: lines `104-111`
  - `native_tracer_entry`: lines `113-120`

ReJIT reported success for every requested program:

- The `rejit_result.per_program` object starts at line `258`.
- ReJIT per-program entries are present for all IDs 6-18:
  - IDs 10-18: lines `259, 1551, 2416, 3297, 4766, 6037, 6444, 6801, 7158`
  - IDs 6-9: lines `7687, 8291, 9337, 10810`
- The last per-program block ends with `"status": "ok"` at line `12351`.
- The top-level `rejit_result` has `"status": "ok"` at line `12354`.

Post-ReJIT stats failed before a post-ReJIT measurement could be recorded:

```text
corpus/results/x86_kvm_corpus_20260510_181727_574962/details/apps/otelcol-ebpf-profiler__profiling.json:255
"error": "BPF stats missing requested program IDs: 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18",

corpus/results/x86_kvm_corpus_20260510_181727_574962/details/apps/otelcol-ebpf-profiler__profiling.json:256
"post_rejit": null,
```

The stats error comes from the first `bpftool -j prog show` sample in `_measure_runner_phase()`:

```text
corpus/driver.py:189
initial_stats = sample_bpf_stats(logical_prog_ids)

runner/libs/bpf_stats.py:68-73
missing = sorted(int(prog_id) for prog_id in wanted if int(prog_id) not in stats)
if missing:
    raise RuntimeError(
        "BPF stats missing requested program IDs: "
        + ", ".join(str(prog_id) for prog_id in missing)
    )
```

## Hypothesis 1: OTEL process crashed/exited during or after ReJIT

Verdict: **partial / most likely but not directly proven**

Confidence: **medium**

Evidence for:

1. If the OTEL process or receiver closes its program/link FDs, all program objects can be freed. That exactly matches all 13 requested IDs disappearing together.

2. The framework does not intentionally stop OTEL before the post-ReJIT stats query. In the corpus lifecycle, post-ReJIT measurement starts at lines `670-686`; only after all phases, in `finally`, does it stop the app at lines `707-710`:

```text
corpus/driver.py:670-686
for session, result in active_pairs:
    try:
        _print_progress(... phase="post_rejit" ...)
        result.post_rejit = _measure_runner_phase(...)

corpus/driver.py:707-710
finally:
    for session, result in session_results:
        if not result.stopped:
            stop_session(session, result)
```

3. The OTEL runner uses a live `ManagedProcessSession`; its `close()` path calls `stop_agent()` only when the corpus lifecycle stops the runner:

```text
runner/libs/app_runners/process_support.py:272-275
def close(self) -> None:
    if self.process is not None:
        stop_agent(self.process, timeout=80)
        self.process = None
```

4. `stop_agent()` sends SIGINT/terminate/kill, but only when called:

```text
runner/libs/agent.py:46-57
def stop_agent(proc: subprocess.Popen[str], timeout: int | float = 10) -> int:
    if proc.poll() is None:
        proc.send_signal(signal.SIGINT)
        ...
            proc.terminate()
        ...
                proc.kill()
```

5. The daemon's process-stop code only stops the daemon, not OTEL:

```text
runner/libs/rejit.py:284-291
def _kill_proc(proc: subprocess.Popen[str], *, timeout: int) -> None:
    proc.terminate()
    ...

def _stop_daemon_server(proc: subprocess.Popen[str], socket_dir: str) -> None:
    _kill_proc(proc, timeout=50)
```

6. The daemon stdout for this run shows only daemon lifecycle:

```text
corpus/results/x86_kvm_corpus_20260510_181727_574962/details/daemon.stdout.log:1
serve: listening on /var/tmp/bpfrejit-daemon.sock

corpus/results/x86_kvm_corpus_20260510_181727_574962/details/daemon.stdout.log:2
serve: shutting down
```

Evidence against / gap:

1. The latest artifact directory contains only suite/result/daemon files and the app JSON. There is no nested OTEL stdout/stderr directory:

```text
corpus/results/x86_kvm_corpus_20260510_181727_574962/details/daemon.stderr.log
corpus/results/x86_kvm_corpus_20260510_181727_574962/details/progress.json
corpus/results/x86_kvm_corpus_20260510_181727_574962/details/result.json
corpus/results/x86_kvm_corpus_20260510_181727_574962/details/daemon.stdout.log
corpus/results/x86_kvm_corpus_20260510_181727_574962/details/apps/otelcol-ebpf-profiler__profiling.json
```

2. The app JSON has no `lifecycle_events` field. Its top-level app status is only the final error:

```text
corpus/results/x86_kvm_corpus_20260510_181727_574962/details/apps/otelcol-ebpf-profiler__profiling.json:12356-12358
"runner": "otelcol-ebpf-profiler",
"selected_workload": "otel_mixed_workload",
"status": "error"
```

3. `progress.json` does not preserve per-app lifecycle events:

```text
corpus/results/x86_kvm_corpus_20260510_181727_574962/details/progress.json:1-5
{
  "error_message": "corpus suite reported errors",
  "failed_at": "2026-05-10T18:18:07.306055+00:00",
  "status": "error",
  "suite": "corpus"
}
```

4. The runner does capture process output in memory, but that capture is populated only during `NativeProcessRunner.stop()` and is not copied into the app result in this path:

```text
runner/libs/app_runners/process_support.py:380-386
snapshot = session.collector_snapshot()
session.close()
self.process_output = {
    "returncode": None if process is None else process.returncode,
    "stdout_tail": "\n".join(snapshot.get("stdout_tail") or []),
    "stderr_tail": "\n".join(snapshot.get("stderr_tail") or []),
}

corpus/driver.py:208-213
result_details = runner.artifacts.get("result_details")
if isinstance(result_details, Mapping):
    artifacts["result_details"] = dict(result_details)
```

Conclusion: process exit/shutdown is the most plausible lifetime explanation, but the run lacks the process stderr/returncode needed to distinguish panic, clean collector shutdown, receiver teardown, or external signal.

## Hypothesis 2: `BPF_PROG_REJIT` replaces program ID

Verdict: **refuted**

Confidence: **high**

The forked kernel does allocate a temporary `struct bpf_prog`, but it does not expose it through `prog_idr` and does not assign it a new public ID.

Normal `BPF_PROG_LOAD` assigns IDs explicitly:

```text
vendor/linux-framework/kernel/bpf/syscall.c:3117-3139
err = bpf_prog_alloc_id(prog);
...
bpf_prog_kallsyms_add(prog);
perf_event_bpf_event(prog, PERF_BPF_EVENT_PROG_LOAD, 0);
bpf_audit_prog(prog, BPF_AUDIT_LOAD);

err = bpf_prog_new_fd(prog);
```

`bpf_prog_alloc_id()` is what inserts into `prog_idr`:

```text
vendor/linux-framework/kernel/bpf/syscall.c:2328-2337
static int bpf_prog_alloc_id(struct bpf_prog *prog)
{
    ...
    id = idr_alloc_cyclic(&prog_idr, prog, 1, INT_MAX, GFP_ATOMIC);
    if (id > 0)
        prog->aux->id = id;
    ...
}
```

`BPF_PROG_REJIT` does not call `bpf_prog_alloc_id()` or `bpf_prog_new_fd()` for the temporary program. It gets the existing program from the caller's FD:

```text
vendor/linux-framework/kernel/bpf/syscall.c:3638-3646
prog = bpf_prog_get(attr->rejit.prog_fd);
...
mutex_lock(&prog->aux->rejit_mutex);
```

It allocates `tmp` privately:

```text
vendor/linux-framework/kernel/bpf/syscall.c:3676-3685
tmp = bpf_prog_alloc(bpf_prog_size(attr->rejit.insn_cnt), GFP_USER);
...
tmp->expected_attach_type = prog->expected_attach_type;
...
tmp->len = attr->rejit.insn_cnt;
```

It verifies/JITs `tmp`, then swaps fields into the original `prog`:

```text
vendor/linux-framework/kernel/bpf/syscall.c:3771-3778
err = bpf_check(&tmp, &load_attr, load_uattr,
        BPF_PROG_REJIT_LOAD_ATTR_SIZE);
...
tmp = bpf_prog_select_runtime(tmp, &err);

vendor/linux-framework/kernel/bpf/syscall.c:3836
bpf_prog_rejit_swap(prog, tmp);
```

`bpf_prog_rejit_swap()` swaps bytecode/JIT/runtime metadata, not `prog->aux->id` and not the public `prog_idr` entry:

```text
vendor/linux-framework/kernel/bpf/syscall.c:3387-3407
static void bpf_prog_rejit_swap(struct bpf_prog *prog, struct bpf_prog *tmp)
{
    ...
    swap(prog->aux->orig_insns, tmp->aux->orig_insns);
    swap(prog->aux->orig_prog_len, tmp->aux->orig_prog_len);
    swap(prog->aux->used_btfs, tmp->aux->used_btfs);

vendor/linux-framework/kernel/bpf/syscall.c:3454-3497
memcpy(prog->digest, tmp->digest, sizeof(prog->digest));
prog->jited = tmp->jited;
...
memcpy(prog->insnsi, tmp->insnsi, bpf_prog_insn_size(tmp));
prog->len = tmp->len;
smp_store_release(&prog->bpf_func, tmp->bpf_func);
```

After the swap, `tmp` is freed as an unexposed temporary:

```text
vendor/linux-framework/kernel/bpf/syscall.c:3936-3944
if (retain_old_image) {
    pr_warn("bpf_rejit: retaining old JIT image after refresh failure\n");
} else {
    __bpf_prog_put_noref(tmp, tmp->aux->real_func_cnt > 0);
}
...
bpf_prog_put(prog);
return ret;
```

`BPF_OBJ_GET_INFO_BY_FD` still reports the existing object's `prog->aux->id`:

```text
vendor/linux-framework/kernel/bpf/syscall.c:5893-5895
info.type = prog->type;
info.id = prog->aux->id;
info.load_time = prog->aux->load_time;
```

Conclusion: if IDs 6-18 disappear, this kernel path did not intentionally replace them with 19-31. The public ID is preserved by design.

## Hypothesis 3: daemon closes original program FDs after ReJIT

Verdict: **refuted as root cause; confirmed only as temporary reference handling**

Confidence: **high**

The daemon opens temporary FDs by program ID. Those FDs add daemon-owned references, but dropping them only removes those extra references.

Snapshot opens a temporary FD, reads original bytecode/info, and returns no FD:

```text
daemon/src/bpf.rs:70-84
pub(crate) fn snapshot_program(prog_id: u32) -> Result<ProgramSnapshot> {
    let fd = syscall::prog_get_fd_by_id(prog_id)
        .with_context(|| format!("open BPF program id {prog_id}"))?;
    let insns = syscall::prog_get_original(fd.as_fd())
        .with_context(|| format!("read original bytecode for BPF program id {prog_id}"))?;
    ...
    Ok(ProgramSnapshot { ... })
}
```

`prog_get_original()` does not return a fresh program FD. It reads fork-only `orig_prog_len/orig_prog_insns` via `BPF_OBJ_GET_INFO_BY_FD` on the existing borrowed FD:

```text
daemon/src/syscall.rs:481-503
pub(crate) fn prog_get_original(prog_fd: BorrowedFd<'_>) -> Result<Vec<bpf_insn>> {
    let info = obj_get_info_by_fd(prog_fd)?;
    ...
    prog_obj_get_info_by_fd_into(prog_fd, &mut info)?;
```

The forked UAPI exposes original bytecode as `bpf_prog_info` fields:

```text
vendor/linux-framework/include/uapi/linux/bpf.h:6721-6722
__u32 orig_prog_len;
__aligned_u64 orig_prog_insns;

vendor/linux-framework/kernel/bpf/syscall.c:5966-5973
ulen = info.orig_prog_len;
info.orig_prog_len = prog->aux->orig_prog_len;
if (info.orig_prog_len && ulen) {
    ...
    if (copy_to_user(uinsns, prog->aux->orig_insns, ulen))
        return -EFAULT;
}
```

Each ReJIT pass opens a fresh FD by ID, calls the syscall, writes the verifier log, and returns:

```text
daemon/src/commands.rs:199-223
fn rejit_program(...) -> Result<()> {
    let prog_fd = syscall::prog_get_fd_by_id(prog_id)
        .with_context(|| format!("open BPF program id {prog_id} for BPF_PROG_REJIT"))?;
    ...
    if let Err(err) = syscall::prog_rejit(prog_fd.as_fd(), ...) {
        ...
    }
    ...
    Ok(())
}
```

The syscall wrapper passes that borrowed FD as `attr.prog_fd`; it does not load a replacement program:

```text
daemon/src/syscall.rs:445-469
fn prog_rejit_once(...) -> std::result::Result<(), ProgRejitFailure> {
    let mut attr: AttrRejit = zeroed();
    attr.prog_fd = prog_fd.as_raw_fd() as u32;
    attr.insn_cnt = insn_cnt;
    attr.insns = new_insns.as_ptr() as u64;
    ...
    let ret = unsafe { sys_bpf(BPF_PROG_REJIT, &mut attr, std::mem::size_of::<AttrRejit>()) };
```

Kernel-side, `BPF_PROG_GET_FD_BY_ID` increments the program refcount and returns an anon-inode FD:

```text
vendor/linux-framework/kernel/bpf/syscall.c:5628-5642
struct bpf_prog *bpf_prog_by_id(u32 id)
{
    ...
    prog = idr_find(&prog_idr, id);
    if (prog)
        prog = bpf_prog_inc_not_zero(prog);
    ...
}

vendor/linux-framework/kernel/bpf/syscall.c:5645-5666
static int bpf_prog_get_fd_by_id(const union bpf_attr *attr)
{
    ...
    prog = bpf_prog_by_id(id);
    ...
    fd = bpf_prog_new_fd(prog);
```

Closing that FD eventually calls `bpf_prog_put()`:

```text
vendor/linux-framework/kernel/bpf/syscall.c:2432-2437
static int bpf_prog_release(struct inode *inode, struct file *filp)
{
    struct bpf_prog *prog = filp->private_data;

    bpf_prog_put(prog);
    return 0;
}
```

When the last reference drops, the kernel removes the public ID:

```text
vendor/linux-framework/kernel/bpf/syscall.c:2412-2422
static void __bpf_prog_put(struct bpf_prog *prog)
{
    struct bpf_prog_aux *aux = prog->aux;

    if (atomic64_dec_and_test(&aux->refcnt)) {
        ...
            bpf_prog_put_deferred(&aux->work);
    }
}

vendor/linux-framework/kernel/bpf/syscall.c:2404-2409
prog = aux->prog;
perf_event_bpf_event(prog, PERF_BPF_EVENT_PROG_UNLOAD, 0);
bpf_audit_prog(prog, BPF_AUDIT_UNLOAD);
bpf_prog_free_id(prog);
__bpf_prog_put_noref(prog, true);
```

Conclusion: daemon FD closure can only reveal that no durable OTEL-side references remain. It cannot close those OTEL-owned references. If the OTEL process/link FDs are alive, closing the daemon's temporary FD should not remove IDs 6-18.

## Most likely cause

The strongest explanation is: **the OTEL process or receiver closed all BPF references between the last successful ReJIT and `_measure_runner_phase()`'s first post-ReJIT `sample_bpf_stats()` call**.

Why this is the most likely cause:

- Kernel ReJIT preserves the original public program ID.
- Daemon FD handling is balanced and temporary.
- The corpus driver does not stop OTEL until after the post-ReJIT measurement attempt.
- `bpftool prog show` missing all 13 IDs means the objects were removed from `prog_idr`, which happens when the last references are gone.
- P1-L already refuted OTEL self-reload/replacement. That leaves process/receiver shutdown or another close of the OTEL-owned BPF handles as the plausible lifetime event.

The exact reason for the shutdown is not known from this run because process return code and stderr were not persisted.

## Diagnostic patch proposal

No implementation in this investigation. Proposed diff plan:

1. Add daemon ID-survival logging around each `BPF_PROG_REJIT`.
   - File: `daemon/src/commands.rs`
   - In `rejit_program()`, call `syscall::obj_get_info_by_fd(prog_fd.as_fd())` before and after `syscall::prog_rejit()`.
   - Also call `syscall::prog_get_fd_by_id(prog_id)` after ReJIT and log whether lookup still succeeds.
   - Log one stderr line:
     `daemon: rejit_id_check requested_prog_id=N fd_before_id=N fd_after_id=N get_by_id_after=ok name=... load_time_before=... load_time_after=...`

2. Persist native process liveness and output on app result failures.
   - File: `runner/libs/app_runners/process_support.py`
   - Add a method such as `diagnostic_snapshot()` returning `pid`, `poll_returncode`, `stdout_tail`, `stderr_tail`.
   - File: `corpus/driver.py`
   - When `_measure_runner_phase()` raises, attach that snapshot under `runner_details.process` before writing the app JSON.
   - This should happen before `runner.stop()` so the return code shows whether the process was already dead at the stats failure.

3. Add pre/post phase program snapshots in the runner.
   - File: `corpus/driver.py`
   - Around `apply_rejit()` and before post-ReJIT stats, capture `bpftool -j prog show` filtered by:
     - original IDs,
     - original program names,
     - any IDs loaded after the original max ID.
   - Store this only in failure diagnostics, not as a performance summary.

4. Optional kernel diagnostic for one repro run.
   - File: `vendor/linux-framework/kernel/bpf/syscall.c`
   - Add temporary `pr_info()` in `bpf_prog_rejit()` before and after `bpf_prog_rejit_swap()`:
     `old_id=prog->aux->id tmp_id=tmp->aux->id old_func=... new_func=... ret=...`
   - Expected output should show `tmp_id=0` and unchanged `old_id`.

## Mitigation proposal

Since the confirmed findings refute ID replacement and daemon-owned FD closure as root causes, there is no kernel-ID remapping or daemon-FD mitigation to apply.

Practical mitigation for the likely cause:

1. Make process death explicit instead of surfacing as missing BPF IDs.
   - Before post-ReJIT `sample_bpf_stats()`, check native app process liveness.
   - If dead, fail with `otelcol-ebpf-profiler exited rc=<rc>` and include stderr/stdout tails.

2. Keep the missing-ID failure behavior.
   - Do not hold duplicate framework FDs across the measurement as a default mitigation. That would keep program IDs artificially alive after the app exits and could turn a real app failure into misleading zero-run measurements.

3. Once stderr identifies the exit reason, fix forward at the source:
   - If OTEL panics or exits on a perf/event/BPF error after ReJIT, fix the collector interaction or kernel ReJIT side effect causing that error.
   - If kernel ReJIT corrupts an attachment/tail-call state and triggers OTEL shutdown, add a focused kernel fix plus a diagnostic regression.
   - If the process is externally signaled, fix the runner lifecycle path that sends the signal.
