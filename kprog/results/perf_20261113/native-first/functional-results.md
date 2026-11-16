2026-11-16T04:24:05Z

Completed checked functional runs, one10-second sample with stats on, image d9e29630 and source b2793af35. The service uses the tested production bridge in the existing regression binary; source has not yet been published into the timing image.

| App | Status | Program bodies requested | Native installed | B generated | B passing stock | Request attempts | Tracked baseline/native IDs |
|---|---|---:|---:|---:|---:|---:|---|
| otelcol-ebpf-profiler/profiling | ok | 14 | 13 | 13 | 5 | 15 | 13/12 |
| bcc/set | error | 23 | 22 | 23 | 21 | 24 | 25/0 |

| cilium/agent | error | 23 | 23 | 23 | 1 | 28 | 53/0 |

Program bodies are distinct native ELF SHA256/entry/type tuples submitted to the service. Active tracked IDs, body counts and retry attempts have different scopes. A missing manifest or startup abort can prevent later bodies from reaching the service; these counts do not establish complete application coverage. The remaining three apps are still queued/running.

OTel installs five checked bodies and eight direct native bodies. custom__generic fails twice; its original map ownership fix remains open. The recorded B failures include stack limits (hotspot, Python, Ruby) and scalar subtraction from the modeled stack pointer (Perl, V8, .NET, Go labels). perf_unwind_native hit the scheduled-base generation error; its forward fix and actual704B stack refusal are under relative-schedule/.

BCC installs21 checked bodies and sched_switch direct native after its B stack-528 rejection. Startup stops at tcp_v4_connect_ret: libbpf cannot resolve B extern count_v4.zero while opening the simulator, so the verification-only CLI exits before BPF_PROG_LOAD and the current continuation path does not try native. This is an artifact-specific verification-preparation error; native continuation will be extended to cover it, with diagnostics preserved and native/transport errors still surfaced. The last two baseline programs never reached the service. This run is an app error despite the framework Make exit0.

count_app.py SERVICE_ARCHIVE RUN_DIR OUTPUT reproduces these counts from request archives and raw app output. Complete JSON rows retain per-body attempts, stages and verifier tails. Raw service archives stay under /workspaces/kprog-raw/perf/20261116-checked-six-apps.

2026-11-16T04:44:53Z: Cilium functional run041417_544240 fails the API endpoint-generation deadline. The service completes28 load requests across23 bodies; all23 bodies install native, all23 B objects generate and one passes stock. No service body fails native loading in this run. Logs show program attachment/endpoint reload finishing after the endpoint deadline. The frozen deadline is unchanged and the app error is retained. This is the synchronous checked-generation startup cost, not the earlier unresolved RAX helper failure. Missing later requests and baseline53 active IDs remain different coverage scopes; no complete-app success claim follows.

2026-11-16T04:53:24Z: BCC-only preparation retry043640_944453 completes appOK after e4b9a57fe:25 program bodies,25 native installed,25 B generated,23 B passing stock,25 request attempts and25/25 tracked baseline/native IDs. This replaces the earlier startup failure as the latest BCC functional observation while preserving the failed run. The two non-stock bodies run direct native. The underlying BTF alias and stack failures remain open. This is a one10-second functional run on16-18/8GiB, not a timing claim.

2026-11-16T05:28:05Z: Latest whole-app counts remain OTel14/13/13/5 (program bodies/native/B generated/stock accepted), BCC25/25/25/23 from its successful retry, and Cilium23/23/23/1 with endpoint-deadline error. BCC tcp_v4_connect_ret separately passes stock after243a40967; a new whole-app compiler confirmation has not run, so its table count stays23. Tetragon is partial: event_exit_acct_process and event_exit_disassociate_ctty both generated B, failed stock and installed direct native (2/2/2/0 completed bodies). Its third request event_wake_up_new_task remains in the old generator;85f3fea1d fixes that nonconvergence in fresh replay. The actual new third-body B reaches stock but rejects stack-752. No final Tetragon totals or Tracee/Katran checked results yet.
