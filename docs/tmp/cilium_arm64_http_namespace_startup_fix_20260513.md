# cilium ARM64 HTTP namespace startup fix (2026-05-13)

## Verdict
The broken piece is the generic namespaced HTTP workload readiness check, not Cilium endpoint namespace setup; replace the 5s stdout-marker wait in `runner/libs/workload.py` with a longer Katran-style active listener probe that preserves child stdout/stderr diagnostics.

## Failure trace
Full stored error from `corpus/results/aws_arm64_corpus_20260513_221545_067112/details/apps/cilium__agent.json`:

```text
interface-bound HTTP server in namespace bpfbench-cepa did not report ready at http://10.244.0.50:18080/
```

The cilium app result has `status: error`, `selected_workload: network_lossy_multi`, `baseline: null`, `post_rejit: null`, and `rejit_result: {}`. That means the failure happened during baseline workload startup, before raw BPF counters were sampled. There is no Python stack trace in this artifact: `corpus/driver.py` records only `str(exc)` for measurement failures, and the run directory only has app JSON plus daemon stdout/stderr. The daemon logs only show:

```text
serve: listening on /var/tmp/bpfrejit-daemon.sock
serve: shutting down
```

Relevant code path:

- `runner/libs/benchmark_catalog.py:30`: `cilium/agent` uses workload `network_lossy_multi`.
- `runner/libs/app_runners/cilium.py:44-45`: endpoint namespaces are `bpfbench-cepa` and `bpfbench-cepb`.
- `runner/libs/app_runners/cilium.py:389-424`: `_prepare_endpoint_link()` deletes/recreates the endpoint netns, creates the veth, renames the peer to `eth0`, assigns `<cilium-ip>/32`, and installs the default route.
- `runner/libs/app_runners/cilium.py:490-511`: Cilium endpoint readiness is API polling on `/v1/endpoint/<id>` until `status.state == "ready"`, with `load_timeout_s` defaulted to 1200s.
- `runner/libs/workload.py:814-825`: `_run_cilium_endpoint_matrix()` starts `NamespacedHttpServer(endpoint_a.namespace, endpoint_a.ipv4)` first, so the observed failure is the first endpoint server in `bpfbench-cepa`.
- `runner/libs/workload.py:235-285`: `NamespacedHttpServer` runs `ip netns exec <namespace> <python> -u -c _NAMESPACED_HTTP_SERVER_SCRIPT <host> 18080`, then waits only 5.0s for stdout line `READY`.
- `runner/libs/workload.py:128-163`: the server is Python stdlib `ThreadingHTTPServer`; it binds to the requested endpoint IP and prints `READY` after bind/listen. Readiness is stdout marker detection, not HTTP polling, port-open probing, or log scraping.

Failure-mode assessment from the saved artifact and code:

- Timeout too short: likely. The only timeout on this path is the hard-coded 5.0s in `NamespacedHttpServer.__enter__()`. Katran's namespace HTTP server uses a 150s startup timeout plus active socket probing.
- Network namespace creation failure: unlikely. `_cilium_endpoint_topology()` would have returned `None` unless `bpfbench-cepa` existed and had an IPv4 address plus default route.
- iptables/nftables backend mismatch: no direct evidence. The failure occurs before any `wrk` request to this endpoint server; it is waiting for the server process to report listener startup.
- Missing kernel modules: unlikely for this specific error. `ip link add type veth`, `tc netem`, endpoint creation, and endpoint readiness would fail earlier if required modules were unavailable. Arm64 does build more network pieces as modules (`veth`, `bridge`, `nf_conntrack`, `sch_netem`), so explicit module loading is a useful hardening option, but it is not the primary symptom here.
- Veth race: unlikely. Topology discovery found `eth0`, its IPv4 address, and the default gateway before the server start.
- HTTP listener bound to wrong interface: unlikely. If the address were missing, Python bind should exit with a traceback; this path timed out with the process not reporting `READY`.
- SELinux/AppArmor: unlikely from available evidence. The runtime container is privileged, AppArmor is not enabled in the project kernel configs, and Katran's namespace HTTP server succeeds on the same arm64 run.

## Comparison: x86 vs arm64
Latest completed x86 KVM cilium app-detail result found:

```text
corpus/results/x86_kvm_corpus_20260513_200534_705861/details/apps/cilium__agent.json
status: ok
selected_workload: network_lossy_multi
baseline workloads: 1
post_rejit workloads: 1
```

That x86 run completed the `cilium_endpoint_matrix` with 9 components: host-to-endpoint, endpoint-to-host, endpoint-to-endpoint, reverse endpoint-to-endpoint, endpoint-to-external, external-to-endpoint, and three UDP bursts. Example successful endpoint server URLs in that run include `http://10.244.0.232:18080/` and `http://10.244.0.186:18080/`.

AWS arm64 cilium app-detail results found:

```text
corpus/results/aws_arm64_corpus_20260506_222705_228991/details/apps/cilium__agent.json
status: error
error: interface-bound HTTP server in namespace bpfbench-cepa did not report ready at http://10.244.0.177:18080/

corpus/results/aws_arm64_corpus_20260513_221545_067112/details/apps/cilium__agent.json
status: error
error: interface-bound HTTP server in namespace bpfbench-cepa did not report ready at http://10.244.0.50:18080/
```

Relevant platform differences:

- x86 KVM target uses the project x86 kernel in a KVM guest, `TARGET_KVM_BENCH_CPUS_SPEC=16`, `TARGET_KVM_BENCH_MEM=64G`, and starts dockerd with `--bridge=none --iptables=false --ip-masq=false --ip-forward=false`.
- AWS arm64 target uses AL2023 (`/aws/service/ami-amazon-linux-latest/al2023-ami-kernel-default-arm64`), installs Docker with `dnf`, then boots the project arm64 kernel and runs the same Ubuntu 24.04 runtime container image for `arm64`.
- The runtime image includes both `iptables` and `nftables`, and uses Cilium v1.19.3 from `quay.io/cilium/cilium:v1.19.3`.
- There are no `runner/config/passes/*/cilium.yaml` overrides. The only app-specific pass YAML currently present is `runner/config/passes/map_inline/katran.yaml`.

The x86-vs-arm64 difference that matches the symptom best is resource/startup timing and readiness robustness, not a different Cilium workload policy. Arm64 t4g.small is much smaller than the x86 KVM bench VM, and this code gives the endpoint HTTP server only 5s to start and print a marker.

## Fix options
Option A - increase and harden `NamespacedHttpServer` readiness:

- In `runner/libs/workload.py`, introduce a named timeout such as `_NAMESPACED_SERVER_START_TIMEOUT_S = 30.0`.
- Replace the bare stdout-marker wait with a loop that also probes the listener from inside the same namespace, following `runner/libs/app_runners/katran.py:421-433`.
- On timeout, terminate the child, collect `stdout` and `stderr`, and include the command plus tail output in the raised error.
- Consider matching Katran's server settings: `allow_reuse_address = True`, `daemon_threads = True`, and `request_queue_size = 128`.

Option B - centralize the namespace HTTP server implementation:

- Move the Katran-style namespace server/probe logic into a shared helper under `runner/libs/workload.py` or a small support module.
- Use that shared helper for both Cilium workload servers and Katran, so readiness behavior is consistent across namespace HTTP workloads.

Option C - add arm64/AWS module preflight if later logs show module failures:

- Before Cilium endpoint or workload setup, explicitly load `veth`, `sch_netem`, `nf_conntrack`, and possibly `br_netfilter` using the existing `runner.libs.kernel_modules` helper pattern.
- This is hardening, not the primary fix for the current trace, because the current error occurs after namespace/address/topology checks have already succeeded.

Option D - skip Cilium on arm64:

- Do not choose this unless the real Cilium datapath is proven incompatible with the arm64 target. The current evidence points to workload server readiness, and cilium is one of the supported corpus apps.

## Recommendation
Pick Option A now: update `NamespacedHttpServer` to use a 30s active listener readiness probe with child stdout/stderr diagnostics, then rerun `PLATFORM=aws ARCH=arm64 BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_BENCH_PASSES=noop SAMPLES=1 WORKLOAD_DURATION=10 make corpus`. If that still fails, the improved error should distinguish a true bind/listen failure from a namespace or Cilium datapath problem; only then add Option C module preflight.
