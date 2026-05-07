# Cilium Reload Blocker Investigation

Date: 2026-05-06

Scope: investigation only. I read `docs/kernel-jit-optimization-plan.md`, `CLAUDE.md`, and `runner/libs/app_runners/cilium.py`. The relevant constraints are: do not filter ReJIT programs, do not replace Cilium with a fake loader, keep the runner on real app startup, and do not add framework-side summaries.

## Short answer

The most concrete reload trigger is Cilium's endpoint BPF program watchdog. In this Cilium tree it is named `ep-bpf-prog-watchdog`, defaults to 30 seconds, checks whether endpoint TC/TCX programs are still attached, and calls `orchestrator.Reinitialize()` if it thinks they are missing (`runner/repos/cilium/pkg/endpoint/watchdog/ep-bpfprog-watchdog.go:25`, `:31`, `:54-56`, `:81-83`, `:96-145`). `orchestrator.Reinitialize()` feeds the normal datapath reinitialize path, which issues `RegenerateAllEndpoints` with `ReasonDeviceConfigurationChanged` and `RegenerateWithDatapath` (`runner/repos/cilium/pkg/datapath/orchestrator/orchestrator.go:310-317`, `:319-367`).

That timing matches the artifacts better than policy or identity churn. The failed SAMPLES=3 run (`corpus/results/x86_kvm_corpus_20260507_023000_475311`) completed all three baseline workload samples, then failed on the final BPF stats snapshot with missing IDs 171, 174, 176, 177, 183, 185, 186. Those three Cilium workload samples took about 14.15s, 16.23s, and 14.44s, so baseline kept the agent alive for more than the watchdog's 30s default. The SAMPLES=1 run (`corpus/results/x86_kvm_corpus_20260507_031724_078597`) had one baseline and one post_rejit sample, each about 14.16s, and did not cross the same baseline watchdog window.

Primary minimal fix: add these agent args in `runner/libs/app_runners/cilium.py`:

```python
"--endpoint-bpf-prog-watchdog-interval=0",
"--endpoint-regen-interval=0",
```

Deterministic fix if any other controller still reloads: SIGSTOP `cilium-agent` immediately after endpoint setup and stable program discovery, and SIGCONT it before cleanup.

## Current Runner Setup

The runner starts real `cilium-agent`, not a custom loader. It disables Kubernetes, L7 proxy, Cilium health checks, endpoint health checks, drift checker, dynamic config, monitor, Hubble, and L2 neighbor discovery, while enabling BPF-heavy datapath features including BPF masquerade, clock probe, fragmentation tracking, PMTU, extended IP protocols, conntrack accounting, XDP prefilter, and native LB acceleration (`runner/libs/app_runners/cilium.py:281-323`).

It creates exactly two managed endpoints: `bpfbench-cepa` on `lxcbench0` and `bpfbench-cepb` on `lxcbench1` (`runner/libs/app_runners/cilium.py:41-44`). Endpoint creation builds veths/netns/routes (`runner/libs/app_runners/cilium.py:376-411`) and PUTs `/v1/endpoint/0` with static labels and `"sync-build-endpoint": True` (`runner/libs/app_runners/cilium.py:430-450`, `:452-459`). `start()` waits for both endpoints to reach ready, then refreshes the BPF program set (`runner/libs/app_runners/cilium.py:492-517`, `:536-556`).

There is no policy file loaded by `runner/libs/app_runners/cilium.py`; policy churn is not coming from runner-side policy updates.

## Reload Path

All endpoint datapath reloads funnel through Cilium's regeneration path:

- `Endpoint.Regenerate()` creates an `EndpointRegenerationEvent` and enqueues it on the endpoint event queue (`runner/repos/cilium/pkg/endpoint/policy.go:800-887`).
- `Endpoint.regenerate()` takes the build lock, transitions state, and calls `regenerateBPF()` (`runner/repos/cilium/pkg/endpoint/policy.go:403-545`).
- `regenerateBPF()` reloads datapath only when the regeneration level reaches `RegenerateWithDatapath`; endpoint config hash changes also bump the level to `RegenerateWithDatapath` (`runner/repos/cilium/pkg/endpoint/bpf.go:376-385`, `:429-446`, `:502-513`).
- `realizeBPFState()` calls `e.orchestrator.ReloadDatapath(...)` and logs "Reloaded endpoint BPF program" after success (`runner/repos/cilium/pkg/endpoint/bpf.go:593-628`).
- `orchestrator.ReloadDatapath()` waits for datapath initialization, then calls `Loader.ReloadDatapath(...)` (`runner/repos/cilium/pkg/datapath/orchestrator/orchestrator.go:370-377`).
- `loader.ReloadDatapath()` recompiles/fetches the template and calls `reloadHostEndpoint()` for host endpoints or `reloadEndpoint()` for LXC endpoints (`runner/repos/cilium/pkg/datapath/loader/endpoint.go:83-115`).
- `reloadEndpoint()` loads/assigns the BPF collection, updates policy tail-call maps, attaches ingress/egress TC programs, and commits pins/routes (`runner/repos/cilium/pkg/datapath/loader/endpoint.go:195-272`). Host endpoint reload reattaches `bpf_host.c` programs to `cilium_host`, `cilium_net`, and external/native devices (`runner/repos/cilium/pkg/datapath/loader/host.go:44-62`). XDP load/attach goes through `compileAndLoadXDPProg()` (`runner/repos/cilium/pkg/datapath/loader/xdp.go:146-185`).

## Controllers And Triggers

### 1. `ep-bpf-prog-watchdog`

This is the best match for the observed SAMPLES=3-only failure. The watchdog cell is named `ep-bpf-prog-watchdog`, has flag `--endpoint-bpf-prog-watchdog-interval`, defaults to 30s, and is disabled when the interval is 0 (`runner/repos/cilium/pkg/endpoint/watchdog/ep-bpfprog-watchdog.go:25`, `:31-33`, `:54-63`). After endpoint restoration it registers a timer with that interval (`runner/repos/cilium/pkg/endpoint/watchdog/ep-bpfprog-watchdog.go:71-83`). The timer calls `checkEndpointBPFPrograms()`, checks each ready endpoint with `loader.DeviceHasSKBProgramLoaded()`, and calls `orchestrator.Reinitialize(ctx)` if any endpoint is missing programs (`runner/repos/cilium/pkg/endpoint/watchdog/ep-bpfprog-watchdog.go:96-145`). The checker looks for TC, TCX, or netkit links on ingress and optionally egress (`runner/repos/cilium/pkg/datapath/loader/netlink.go:524-565`).

Trigger condition: timer, every 30s by default; reload if endpoint TC/TCX/netkit programs appear missing. In our artifact, SAMPLES=3 baseline ran long enough to cross this timer; SAMPLES=1 did not.

### 2. Datapath Orchestrator `reinitialize`

The orchestrator starts a one-shot job named `reinitialize` (`runner/repos/cilium/pkg/datapath/orchestrator/orchestrator.go:160`). I spot-checked the reconcile loop: it waits for agent config, local node state, and host devices, builds a new local node config, and if that config differs from the previous one, calls `o.reinitialize(...)` (`runner/repos/cilium/pkg/datapath/orchestrator/orchestrator.go:165-277`). It wakes on the merged local-node-config watch, retry timer, local node updates, or explicit trigger (`runner/repos/cilium/pkg/datapath/orchestrator/orchestrator.go:263-270`).

`newLocalNodeConfig()` watches selected devices, node addresses, MTU, direct-routing device if needed, `cilium_host`, and `cilium_net` (`runner/repos/cilium/pkg/datapath/orchestrator/localnodeconfig.go:54-99`, `:129-143`). The config includes devices, node addresses, MTU, XDP config, LB config, and datapath mode bits (`runner/repos/cilium/pkg/datapath/orchestrator/localnodeconfig.go:149-197`). `reinitialize()` runs `Loader.Reinitialize`, `ConnectorConfig.Reinitialize`, stores the latest config, and triggers all endpoints with `ReasonDeviceConfigurationChanged` and `RegenerateWithDatapath` (`runner/repos/cilium/pkg/datapath/orchestrator/orchestrator.go:319-367`).

Trigger condition: device/address/MTU/local-node/config changes or explicit `Orchestrator.Reinitialize()`. This is the actual load/replace path used by the watchdog.

### 3. `devices-controller`

The devices controller subscribes to kernel netlink state for devices, routes, and neighbors (`runner/repos/cilium/pkg/datapath/linux/devices_controller.go:36-68`). `Start()` launches `go dc.run(ctx)` (`runner/repos/cilium/pkg/datapath/linux/devices_controller.go:141-154`). It subscribes to address, route, link, and neighbor updates, initializes tables, then processes incremental updates (`runner/repos/cilium/pkg/datapath/linux/devices_controller.go:189-248`). Updates are batched every 100ms (`runner/repos/cilium/pkg/datapath/linux/devices_controller.go:344-405`). `processBatch()` mutates the device/route/neighbor tables and logs "Devices changed" when the selected device set changes (`runner/repos/cilium/pkg/datapath/linux/devices_controller.go:430-603`). Explicit `--devices` filters selection (`runner/repos/cilium/pkg/datapath/linux/devices_controller.go:613-688`).

Trigger condition: netlink link/address/route/neighbor updates. It does not directly call BPF load, but its table watches feed the orchestrator local-node config loop.

### 4. Endpoint Create / Identity Resolver

Endpoint creation adds the endpoint to the endpoint manager, then in non-k8s mode calls `UpdateLabels(..., blocking=true)` (`runner/repos/cilium/pkg/endpoint/api/endpoint_api_manager.go:287-307`). If that did not trigger regeneration, creation explicitly requests `ReasonEndpointInit` with `RegenerateWithDatapath`, and `sync-build-endpoint` waits for first regeneration (`runner/repos/cilium/pkg/endpoint/api/endpoint_api_manager.go:315-334`).

`UpdateLabels()` only resolves identity when labels actually changed (`runner/repos/cilium/pkg/endpoint/endpoint.go:2074-2138`). The identity resolver runs synchronously for blocking/local identity resolution and then registers controller `resolve-identity-<id>` with a 5-minute interval (`runner/repos/cilium/pkg/endpoint/endpoint.go:2171-2228`). `identityLabelsChanged()` allocates the identity and, when the endpoint has an ID, requests `ReasonLabelsUpdate` with `RegenerateWithDatapath` (`runner/repos/cilium/pkg/endpoint/endpoint.go:2230-2395`).

Trigger condition: initial endpoint creation and future label/identity changes. In our runner, the two endpoint labels are static and created once before measurement (`runner/libs/app_runners/cilium.py:41-44`, `:444-450`), so this should be startup-only.

### 5. Endpoint API PATCH

PATCH `/endpoint/{id}` builds a new endpoint model, calls `ProcessChangeRequest()`, and if a reason is returned, requests `ReasonEndpointUpdate` with `RegenerateWithDatapath` (`runner/repos/cilium/pkg/endpoint/api/endpoint_api_handler.go:270-327`). `ProcessChangeRequest()` treats ifindex, interface name, valid state transition, and identity-label changes as changes that force policy computation and can move a ready endpoint to waiting-to-regenerate (`runner/repos/cilium/pkg/endpoint/api.go:520-608`).

Trigger condition: external endpoint API PATCH. The runner does not PATCH endpoints during measurement.

### 6. Policy Update Paths

`policy.Updater.TriggerPolicyUpdates()` bumps policy revision and triggers full endpoint regeneration (`runner/repos/cilium/pkg/policy/trigger.go:12-20`). The endpoint manager's `TriggerRegenerateAllEndpoints()` triggers the periodic regeneration controller and policy callbacks (`runner/repos/cilium/pkg/endpointmanager/manager.go:629-636`). Policy callbacks run in separate goroutines (`runner/repos/cilium/pkg/endpointmanager/callback.go:57-70`). The policy importer queues updates, replaces policy by resource, computes affected identities, and calls `epm.UpdatePolicy(...)` (`runner/repos/cilium/pkg/policy/cell/policy_importer.go:103-105`, `:259-322`). Per-endpoint `UpdatePolicy()` usually requests `ReasonPolicyUpdate` with `RegenerateWithoutDatapath`, unless the endpoint missed a policy revision (`runner/repos/cilium/pkg/endpoint/policy.go:716-773`).

Trigger condition: policy repository changes, CIDR/group/k8s watcher changes, or full policy recalculation. The runner has `--enable-k8s=false` and no policy-file load in `cilium.py`, so this is not the likely measurement-window reload source.

### 7. Periodic Endpoint Regeneration

`--endpoint-regen-interval` controls periodic endpoint regeneration and is documented as "Set to 0 to disable"; the default is 2 minutes (`runner/repos/cilium/pkg/endpointmanager/config.go:44-63`). The endpoint-manager cell registers the periodic regeneration controller only when the interval is greater than 0 (`runner/repos/cilium/pkg/endpointmanager/cell.go:222-244`). The controller calls `RegenerateAllEndpoints()` with `ReasonPeriodicRegeneration` and `RegenerateWithoutDatapath` (`runner/repos/cilium/pkg/endpointmanager/manager.go:150-179`).

Trigger condition: timer, default 2 minutes. It is not the SAMPLES=3 baseline culprit, but disabling it is low-risk hygiene for longer corpus windows.

### 8. Regeneration Failure Recovery

Each endpoint starts `endpoint-<id>-regeneration-recovery`, which waits on `regenFailedChan`, then retries with `ReasonRegenerationFailure` and `RegenerateWithDatapath`; its run interval is 1s (`runner/repos/cilium/pkg/endpoint/policy.go:987-1035`).

Trigger condition: a previous regeneration failure. This should not fire in a healthy endpoint setup, but SIGSTOP prevents it by freezing the agent.

### 9. IP Identity Sync

`sync-<IPv4/IPv6>-identity-mapping (<id>)` syncs endpoint IP to identity mapping into kvstore and runs every 5 minutes (`runner/repos/cilium/pkg/endpoint/policy.go:1057-1142`). It does not call `Regenerate()` or `ReloadDatapath()`.

Trigger condition: 5-minute IP identity sync, not a datapath reload.

## Existing Knobs

| Knob | Source | Effect | Safe for this benchmark? |
| --- | --- | --- | --- |
| `--endpoint-bpf-prog-watchdog-interval=0` | `runner/repos/cilium/pkg/endpoint/watchdog/ep-bpfprog-watchdog.go:31-63` | Disables the 30s endpoint BPF program presence watchdog that can call `orchestrator.Reinitialize()` (`:81-83`, `:139-142`). | Yes. Keeps real datapath; only disables self-healing during the benchmark. Best minimal fix. |
| `--endpoint-regen-interval=0` | `runner/repos/cilium/pkg/endpointmanager/config.go:44-63`, `runner/repos/cilium/pkg/endpointmanager/cell.go:238-240` | Disables periodic endpoint recalculation. | Yes. It is a maintenance timer and not needed for a fixed benchmark topology. |
| `--enable-health-checking=false`, `--enable-endpoint-health-checking=false` | `runner/repos/cilium/pkg/healthconfig/cell.go:11-57`; runner already sets them at `runner/libs/app_runners/cilium.py:287-289`. | Health manager returns before registering the health init job when health checking is disabled (`runner/repos/cilium/pkg/health/health_manager.go:99-121`); endpoint health controls health endpoint launch (`runner/repos/cilium/pkg/health/health_manager.go:151-167`). | Already safe and already set. I found no `--disable-cilium-health`; these are the actual flags. |
| `--enable-monitor=false` | `runner/repos/cilium/pkg/monitor/agent/cell.go:31-45`, `:75-80`; runner sets it at `runner/libs/app_runners/cilium.py:296`. | Disables monitor UDS server setup. | Already safe. Not a reload trigger. |
| `--enable-hubble=false` | `runner/repos/cilium/pkg/hubble/cell/config.go:22-64`; runner sets it at `runner/libs/app_runners/cilium.py:297`. | Disables Hubble server. | Already safe. Not a reload trigger. |
| `--enable-drift-checker=false`, `--enable-dynamic-config=false`, `--enable-dynamic-lifecycle-manager=false` | `runner/repos/cilium/pkg/driftchecker/cell.go:24-36`, `runner/repos/cilium/pkg/dynamicconfig/cell.go:50-66`, `runner/repos/cilium/pkg/dynamiclifecycle/cell.go:41-53`; runner sets them at `runner/libs/app_runners/cilium.py:293-295`. | Disables config drift/dynamic config/lifecycle features; configmap reflectors do nothing when k8s or dynamic config is disabled (`runner/repos/cilium/pkg/dynamicconfig/reflectors.go:35-43`). | Already safe. |
| `--config-dir` | `runner/repos/cilium/daemon/cmd/daemon_main.go:176-180` | Reads config entries from a directory. | Equivalent to CLI flags; runner should keep explicit args for clarity. |
| `--enable-l7-proxy=false` | Flag source `runner/repos/cilium/daemon/cmd/daemon_main.go:286-290`; runner sets it at `runner/libs/app_runners/cilium.py:287`. | Disables L7 proxy. | Already safe for this L3/L4 datapath workload. |
| `--enable-bpf-tproxy` | `runner/repos/cilium/daemon/cmd/daemon_main.go:280-281`; default false from `runner/repos/cilium/pkg/defaults/defaults.go:240-244`. | BPF proxy redirection. | Leave disabled; not needed and not a reload blocker. |
| `--enable-endpoint-routes` | `runner/repos/cilium/daemon/cmd/daemon_main.go:188-195`; default false from `runner/repos/cilium/pkg/defaults/defaults.go:296-298`. | Per-endpoint routes instead of routing via `cilium_host`. | Do not change; it changes datapath shape. |
| `--datapath-mode` | `runner/repos/cilium/daemon/cmd/daemon_main.go:188-192`; runner leaves default veth/netkit auto behavior. | Datapath mode selection. | Do not change for this fix; mode changes are reviewer-visible. |
| `--enable-bpf-masquerade`, `--enable-xdp-prefilter`, `--bpf-lb-acceleration=native` | `runner/repos/cilium/daemon/cmd/daemon_main.go:500-501`, `runner/repos/cilium/pkg/option/config.go:340-341`, `runner/repos/cilium/pkg/option/config.go:226-227`, `runner/repos/cilium/pkg/datapath/xdp/cell.go:25-48`; runner enables them at `runner/libs/app_runners/cilium.py:302`, `:308-309`. | Enable important BPF/XDP datapath paths. | Do not disable unless all better options fail; this would strip the measurement. |
| `--conntrack-gc-interval`, `--bpf-ct-global-tcp-max`, `--bpf-policy-map-max` | `runner/repos/cilium/pkg/maps/ctmap/gc/gc.go:77-84`, `runner/repos/cilium/daemon/cmd/daemon_main.go:577-578`, `runner/repos/cilium/pkg/maps/policymap/cell.go:41-48`. | CT GC cadence and map sizes. | Not program reload controls. Leave unchanged. |
| `--max-controller-interval` | `runner/repos/cilium/daemon/cmd/daemon_main.go:516-518`. | Hidden max interval cap between controller runs; zero means no limit. | Not a pause mechanism. Leave unchanged. |
| `--policy-trigger-interval` | `runner/repos/cilium/daemon/cmd/daemon_main.go:679-681`; default 1s from `runner/repos/cilium/pkg/defaults/defaults.go:374-376`. | Coalesces policy update triggers. | Not useful with no policy churn. |

## Endpoint Identity / IP Cache Churn

Identity churn is not the likely source here. The runner creates two endpoints once, with static `container:app=bpfbench-cilium` and `container:instance=a/b` labels (`runner/libs/app_runners/cilium.py:41-44`, `:444-450`). Cilium's non-k8s endpoint create path resolves identity during endpoint creation (`runner/repos/cilium/pkg/endpoint/api/endpoint_api_manager.go:293-307`), and `sync-build-endpoint` waits for the first regeneration to finish before the runner proceeds (`runner/repos/cilium/pkg/endpoint/api/endpoint_api_manager.go:330-334`). The identity resolver's periodic controller is 5 minutes (`runner/repos/cilium/pkg/endpoint/endpoint.go:2209-2224`), not the 30-45s failure window.

IP identity sync also runs every 5 minutes and only upserts/deletes IP-to-identity data (`runner/repos/cilium/pkg/endpoint/policy.go:1057-1142`). It does not reload datapath programs.

## SIGSTOP Feasibility

SIGSTOP is viable for a short steady-state datapath measurement. The agent cannot catch SIGSTOP. The Cilium agent root command initializes config, calls `h.Run(...)`, and logs graceful stop when `h.Run()` exits; I found no agent-specific SIGSTOP handling in `daemon/` or `pkg/`, and SIGSTOP is not catchable by Go anyway (`runner/repos/cilium/daemon/cmd/root.go:21-56`).

Effects:

- BPF programs, links, and pinned maps stay resident in the kernel.
- The datapath workload continues because packets hit TC/XDP programs, not Cilium userspace.
- Cilium API, UDS sockets, monitor, and controllers stop responding while frozen. In this runner, API is only needed for setup and cleanup; monitor and Hubble are disabled (`runner/libs/app_runners/cilium.py:296-297`).
- Cleanup must SIGCONT before `_delete_managed_endpoints()` or before `stop_agent()` sends termination. Otherwise graceful deletion can hang behind a stopped process.

## Pause / Disconnect CLI

I found no endpoint "pause regeneration" CLI in this Cilium version. The tempting command is not a pause:

```text
cilium endpoint disconnect <endpoint-id>
```

The command is defined as `disconnect <endpoint-id>` and calls `client.EndpointDelete(id)` (`runner/repos/cilium/cilium-dbg/cmd/endpoint_disconnect.go:12-24`). The API delete path removes the endpoint from Cilium and releases resources including BPF programs and maps (`runner/repos/cilium/pkg/endpoint/api/endpoint_api_manager.go:397-405`, `:423-430`). That would destroy the datapath being measured, so it is not acceptable.

## Health / Monitor Finding

`--disable-cilium-health` does not appear to exist in this tree. The actual health knobs are `--enable-health-checking` and `--enable-endpoint-health-checking` (`runner/repos/cilium/pkg/healthconfig/cell.go:11-57`). The runner already sets both false (`runner/libs/app_runners/cilium.py:287-289`). With health checking disabled, the health manager returns before registering the health init job (`runner/repos/cilium/pkg/health/health_manager.go:99-121`). Endpoint health controls whether the virtual health endpoint is launched (`runner/repos/cilium/pkg/health/health_manager.go:151-167`). Health is not the likely reload culprit in these runs.

Monitor and Hubble are also already disabled (`runner/libs/app_runners/cilium.py:296-297`). Their flags set up observability sockets/servers, not endpoint datapath reloads (`runner/repos/cilium/pkg/monitor/agent/cell.go:31-45`, `runner/repos/cilium/pkg/hubble/cell/config.go:22-64`).

## Reproduction Interpretation

The failed app JSON records:

- `status=error`
- `error="BPF stats missing requested program IDs: 171, 174, 176, 177, 183, 185, 186"`
- `baseline.workloads | length == 3`
- `post_rejit.workloads | length == 0`
- baseline workload durations about 14.15s, 16.23s, 14.44s

So Cilium got through baseline workload execution and failed when the runner sampled final baseline BPF stats. That means the IDs existed for the initial stats snapshot but disappeared before final stats. The exact Cilium agent logs are not preserved in the artifact, so the artifact alone cannot prove which Cilium controller fired. The source-level timer that fits the observed timing is `ep-bpf-prog-watchdog`: 30s default and a direct path to `orchestrator.Reinitialize()`.

The successful SAMPLES=1 Cilium-only run records one baseline workload and one post_rejit workload, each about 14.16s. It does not keep the agent running inside one baseline phase long enough to cross the 30s watchdog timer before the final baseline stats snapshot.

## Recommended Fix Paths

### 1. Disable Cilium's self-reload timers

Paper rigor: high. This keeps real Cilium, real endpoint creation, real TC/XDP datapath, and the same workload. It disables maintenance/self-healing timers during a controlled fixed-topology measurement.

Implementation cost: trivial. Risk: low. If endpoint programs actually disappear, the workload should fail instead of Cilium silently replacing the measured IDs, which matches this framework's fail-fast rules.

Exact `runner/libs/app_runners/cilium.py` change:

```python
# In CiliumRunner._command(), near the existing health/controller disables:
"--endpoint-bpf-prog-watchdog-interval=0",
"--endpoint-regen-interval=0",
```

This should be the first patch to try. It directly addresses the 30s watchdog path and removes the 2-minute periodic regeneration path.

### 2. Freeze `cilium-agent` after setup

Paper rigor: medium-high. It measures the real Cilium datapath generated by the real agent; the control plane is frozen during the short steady-state measurement. This is common for stabilizing datapath-only measurements, but should be documented in the benchmark method.

Implementation cost: small. Risk: low if cleanup resumes before deleting endpoints.

Exact `runner/libs/app_runners/cilium.py` sketch:

```python
import os
import signal

# in __init__
self._agent_paused = False

def _pause_agent(self) -> None:
    process = None if self.session is None else self.session.process
    if process is None or process.poll() is not None or self._agent_paused:
        return
    os.kill(int(process.pid), signal.SIGSTOP)
    self._agent_paused = True

def _resume_agent(self) -> None:
    process = None if self.session is None else self.session.process
    if process is None or process.poll() is not None or not self._agent_paused:
        return
    os.kill(int(process.pid), signal.SIGCONT)
    self._agent_paused = False

# in start(), after endpoint setup and stable discovery:
self._setup_managed_endpoints()
programs = self.refresh_programs()
self._pause_agent()
return [int(program["id"]) for program in programs if int(program.get("id", 0) or 0) > 0]

# at the top of stop(), before API deletion:
self._resume_agent()
self._delete_managed_endpoints()
```

This is the deterministic solution if any non-watchdog controller still reloads programs during SAMPLES=3.

### 3. Strip or lower BPF datapath feature flags

Paper rigor: low. Disabling `--enable-xdp-prefilter`, `--bpf-lb-acceleration=native`, or `--enable-bpf-masquerade=true` would reduce global datapath reload surface, but it also removes the Cilium paths that make Cilium important for the map_inline paper result (`runner/libs/app_runners/cilium.py:299-309`). I do not recommend this except as a last-resort diagnostic.

Implementation cost: trivial. Risk: high for benchmark validity.

Exact diagnostic-only change:

```python
"--enable-xdp-prefilter=false",
"--bpf-lb-acceleration=disabled",
"--enable-bpf-masquerade=false",
```

Do not use this as the paper-grade fix unless the paper explicitly reports it as a stripped-down Cilium configuration.

## Recommended Order

1. Add `--endpoint-bpf-prog-watchdog-interval=0` and `--endpoint-regen-interval=0`.
2. Re-run only Cilium with `BPFREJIT_CORPUS_APPS="cilium/agent" BPFREJIT_BENCH_PASSES="noop,map_inline" SAMPLES=3 make vm-corpus`.
3. If IDs still churn, add the SIGSTOP/SIGCONT wrapper after `refresh_programs()` and before cleanup.

