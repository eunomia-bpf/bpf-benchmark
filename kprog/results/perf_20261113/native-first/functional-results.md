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
