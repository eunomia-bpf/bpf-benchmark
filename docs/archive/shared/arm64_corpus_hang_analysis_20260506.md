# ARM64 corpus hang analysis: tetragon ReJIT stalls on t4g.small

Date: 2026-05-06 UTC

## A. Current State

Remote target:

- EC2: `i-0a1426ea4b58ecd81`, `t4g.small`, `18.210.22.9`
- Container: `3224b31a988b`, image `bpf-benchmark/runner-runtime:arm64`, up about 4 hours
- Kernel: `Linux 7.0.0-rc2+ #1 SMP PREEMPT Tue May 5 11:09:25 PDT 2026 aarch64`
- Runner command: `python3 -m runner.suites.corpus ... --target-arch arm64 --target-name aws-arm64 --samples 1`
- Remote log: `/var/tmp/bpf-benchmark-aws-arm64/corpus/run.aws-arm64.corpus.7ce4510d/runs/corpus_run.aws-arm64.corpus.7ce4510d_20260506_011434/remote.log`

Observed processes:

- `bpfrejit-daemon` PID 2672, worker thread PID 95660
- `tetragon` PID 93860
- Daemon has 2 threads. Main thread sleeps in `futex_do_wait`; worker thread is runnable and consuming CPU.

Resource state:

- `docker stats`: about 188-199% CPU, about 924-929 MiB / 1.798 GiB memory, 18 PIDs
- `vmstat 1 10`: CPU idle 0-2%, IO wait 0%, system CPU roughly 55-67%, user CPU roughly 33-45%
- Swap in use: about 208 MiB / 2 GiB, with no active swap storm during sampling
- Load average around 3.6 on 2 vCPU

Timeline from `remote.log`:

- 10 apps finished before tetragon: 8 BCC apps, otelcol, cilium
- Pre-tetragon ReJIT program counts: `1+3+5+4+2+3+1+3+12+49 = 83`
- Last remote log line remains:
  `{"app": "tetragon/observer", "event": "rejit_start", "program_count": 287, "runner": "tetragon"}`

No current ARM64 partial result has synced back to local `corpus/results`. The remote partial result directory exists only inside the remote run output:

- `corpus/results/aws_arm64_corpus_20260506_011437_276695`
- `metadata.json` status is `running`
- `progress.json` says `apps_done=10`, `last_app=cilium/agent`
- There is no `tetragon__observer.json` yet because tetragon ReJIT has not returned.

Current ARM64 run pass list is 13 passes:

`wide_mem, rotate, cond_select, extract, endian_fusion, map_inline, const_prop, dce, bounds_check_merge, skb_load_bytes_spec, bulk_memory, prefetch, ccmp`

This is not the same as the local x86 KVM run `x86_kvm_corpus_20260506_023522_768608`, whose metadata shows 6 kop-ish passes:

`rotate, cond_select, extract, endian_fusion, bulk_memory, prefetch`

Historical local ARM64 completed corpus directories:

- `aws_arm64_corpus_20260421_184345_176691`
- `aws_arm64_corpus_20260421_190630_849712`
- `aws_arm64_corpus_20260421_213547_871838`
- `aws_arm64_corpus_20260422_012535_821296`
- `aws_arm64_corpus_20260422_044304_037607`

The latest completed one is `aws_arm64_corpus_20260422_044304_037607`, completed `2026-04-22T04:46:21Z`. It is not comparable to this hang: that old corpus had `tetragon/default` with 1 program, while the current run is `tetragon/observer` with 287 programs.

## B. 30s strace Analysis

Container did not have `strace`; host did. Because the container runs with `--pid=host`, I attached host `strace` to PID 2672. Host `strace` rejects `-tt` together with `--absolute-timestamps`, so I used `-tt`, which gives absolute time-of-day timestamps.

Key captured pattern:

```text
strace: Process 2672 attached with 2 threads
[pid 95660] 04:59:19.713275 bpf(0x27 /* BPF_??? */, 0xffff84b7ccf0, 48) = -1 ENOSPC
[pid 95660] 04:59:21.620773 bpf(0x27 /* BPF_??? */, 0xffff84b7ccf0, 48) = -1 ENOSPC
[pid 95660] 04:59:23.779506 bpf(0x27 /* BPF_??? */, 0xffff84b7ccf0, 48) = 0
[pid 95660] 04:59:26.275265 openat(... "pass-09-skb_load_bytes_spec.verifier.log", ...) = 30
[pid 95660] 04:59:26.276946 write(30, ..., 76202655) = 76202655
[pid 95660] 04:59:26.375878 close(30) = 0
[pid 95660] 04:59:27.237604 openat(... "verifier-states.json", ...) = 29
[pid 95660] 04:59:27... many small write(29, ...) calls
```

Important details:

- The syscall command was `0x27` decimal 39, which matches this repo's `kernel_sys::BPF_PROG_REJIT = 39`. It is not `0x1f` on this running kernel/userspace combination.
- This is not a syscall that never returns. The captured `BPF_PROG_REJIT` retried on verifier-log `ENOSPC` and then succeeded.
- The daemon then wrote a 76,202,655-byte verifier log for a single pass of one tetragon program.
- It then serialized parsed verifier states to `verifier-states.json` through many tiny JSON writes.
- The worker thread stayed runnable; main thread stayed in futex waiting for the rayon job.

Current workdir:

`/var/tmp/bpfrejit-runtime/run.aws-arm64.corpus.7ce4510d/bpfrejit-daemon-optimize-2672-113`

Workdir contents at sampling time:

- Total size: about 743 MiB for one program.
- Ten verifier logs already existed for this one program, each about 73 MiB:
  `pass-00-wide_mem` through `pass-09-skb_load_bytes_spec`.
- `prog.bin`: about 8 KiB, report says original instruction count 1021.
- After `wide_mem`, instruction count was 997.
- `pass-05-map_inline` matched 21 sites and applied 0; the other shown passes applied no further changes except `wide_mem`.

Position in tetragon:

- Previous completed apps account for 83 optimize workdirs.
- Workdir ID 113 is zero-based, so it is the 114th program globally.
- Therefore it is tetragon program `113 - 83 + 1 = 31` of 287.
- Current live sorted tetragon program #31 is BPF prog id 280:
  `generic_kprobe_actions`, type `kprobe`, tag `e7f22a5a65cd8abd`.

## C. Hypotheses Checked

### Single-program kernel hang

Not supported by evidence.

`strace` showed `BPF_PROG_REJIT` returning. The daemon was not stuck forever inside one kernel syscall during the sample. It was in userspace writing/parsing/serializing verifier output after successful ReJIT.

### ENOSPC retry infinite loop

Not supported by evidence.

There are `ENOSPC` retries, but the sampled call eventually returned 0. This is expected with the current retry growth policy when the initial verbose log buffer is too small. The problem is not "cap too low"; the problem is that the daemon is requesting and persisting huge `log_level=2` verifier logs for many passes and many programs.

### Slow but still making progress

Supported.

The daemon reached tetragon program #31/287 after roughly 3h14m in tetragon ReJIT. Program #31 alone had already accumulated about 743 MiB of per-pass artifacts and was still busy. At that rate, waiting for the whole 287-program tetragon ReJIT is not practical on `t4g.small`.

This is forward progress, but it is pathological progress.

### Kernel verifier deadlock / OOM / hung task

Not supported.

`dmesg` has no OOM, hung task, or verifier loop report. `hung_task_timeout_secs` is 120. The only relevant kernel messages are ARM64 warnings:

```text
WARNING: kernel/bpf/arraymap.c:1104 at bpf_arch_poke_desc_update+0x8/0x20
...
bpf_prog_rejit_poke_target_phase+0x130/0x180
bpf_prog_rejit+0xa64/0xe00
```

These warnings are ARM64-specific and worth tracking, but the system kept running after them.

### Resource throttling only

Not the root cause.

The machine is overloaded: the container consumes nearly 2 full CPUs, with 0% idle in `vmstat`. But there is no IO wait and no swap storm. The overload is an effect of daemon verifier-log processing plus tetragon workload activity, not the primary explanation.

## D. Root Cause and Fix Recommendations

Most likely root cause:

The remote container is running daemon code from before the local fix `e59bf141` (`Limit verbose ReJIT logs to stateful passes`). That old daemon requests verbose verifier logs and writes verifier-state artifacts for every pass. On tetragon's larger multi-subprogram `generic_kprobe_actions` programs, each pass can emit about 73 MiB of verifier log. With 10+ passes, one program produces hundreds of MiB of temporary verifier artifacts and burns minutes serializing JSON. Multiplying that by 287 tetragon programs makes the run look hung.

Why x86 KVM completed:

- The referenced x86 KVM run completed `2026-05-06T02:44:07Z`; `daemon.stderr.log` is empty.
- Its `tetragon__observer.json` has 287 per-program ReJIT results, all `ok`.
- That result has no per-program ReJIT timestamps.
- Its pass list is different and much lighter: 6 passes, without `map_inline`, `const_prop`, `dce`, `bounds_check_merge`, `skb_load_bytes_spec`, or `ccmp`.

Recommended fixes:

1. Do not raise the ReJIT log cap as the primary fix. The sampled call already succeeded after retries; larger caps would make the artifact and memory problem worse.
2. Use a daemon image containing at least `e59bf141`, which limits verbose `log_level=2` ReJIT to stateful passes (`noop`, `map_inline`, `const_prop`) and uses basic logging for stateless kop/peephole passes.
3. Keep the new `execute_plan` protocol question separate. The immediate hang signature is explained by pre-`e59bf141` verbose logging behavior, not by needing the new protocol.
4. If full stateful passes remain too expensive on 287-prog tetragon even after `e59bf141`, treat compact verifier-state transport as a follow-up engineering item: avoid pretty JSON for large state arrays, avoid persisting success logs by default, or move to compact binary/state sidecar files.
5. Track the ARM64 `bpf_arch_poke_desc_update()` WARN separately as a kernel-side ARM64 ReJIT correctness/post-paper item. It is not the observed 4-hour stall mechanism.

## E. Action Recommendation

Do not wait for this container to finish. It is only at tetragon program #31/287 after hours, and the run is using a stale daemon behavior that produces pathological verifier-log amplification. The result will not be useful as an authoritative corpus run.

Recommended action, with explicit user approval because it is destructive:

- Stop/kill the current remote container.
- Do not restart the same image.
- Rebuild/rerun only after the runtime image includes `e59bf141` or newer.

I did not kill the EC2 instance, container, or any process during this investigation.
