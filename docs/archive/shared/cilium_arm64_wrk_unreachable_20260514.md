# cilium ARM64 wrk unreachable root cause (2026-05-14)

## Verdict

The failing condition is root-namespace traffic to a Cilium-managed endpoint blackholing after Cilium has already reported the endpoint ready; add fail-fast route/sysctl/Cilium endpoint diagnostics around the first host-to-endpoint `wrk`, then fix the confirmed route path, most likely by enabling Cilium endpoint routes and/or normalizing host `rp_filter`.

## Failure trace

The two post-HTTP-startup AWS arm64 retries fail at the first Cilium endpoint matrix leg:

```text
Command '['/usr/bin/wrk', '-t2', '-c20', '-d1s', '--timeout', '1s', 'http://10.244.0.247:18080/']' timed out after 31.0 seconds
Command '['/usr/bin/wrk', '-t2', '-c20', '-d1s', '--timeout', '1s', 'http://10.244.0.75:18080/']' timed out after 31.0 seconds
```

`NamespacedHttpServer` now starts successfully in the endpoint namespace: it runs `ip netns exec <namespace> python3 -u -c ... <endpoint-ip> 18080` and waits for `READY` for up to 30 seconds at `runner/libs/workload.py:236`. The failure is after that, in `_run_cilium_endpoint_matrix()` at `runner/libs/workload.py:846`, where the first `wrk` is called with no `namespace=` argument at `runner/libs/workload.py:854`. `_run_wrk_http_load()` only wraps clients with `ip netns exec` when `namespace` is non-null at `runner/libs/workload.py:771`, so this failed client runs in the root network namespace.

Expected packet path for the failing leg:

1. Root netns `wrk` opens TCP to `10.244.0.x:18080`.
2. Linux route lookup in the root netns must find Cilium's local-endpoint route, either through `cilium_host` or directly to the endpoint host veth.
3. Traffic should pass Cilium's host/endpoint BPF path and enter `bpfbench-cepa` on `eth0`.
4. The endpoint Python server replies from `10.244.0.x`; the reply path should return through the endpoint veth/Cilium datapath to the root netns socket.

If the root netns route to `10.244.0.x` is missing, the SYN can follow the default AWS route and disappear. If the route is present but reverse-path filtering, policy, or Cilium BPF drops the packet, `wrk` sees the same symptom: no completed TCP connection and eventual subprocess timeout. A manual root-netns `curl -v http://10.244.0.x:18080/` or `ping 10.244.0.x` on the failing instance would therefore be expected to hang or time out; the current artifacts do not include those probes.

The runner itself only adds a `10.244.0.0/24` route inside the synthetic external namespace `bpfbenchns` at `runner/libs/app_runners/cilium.py:512`. It does not add a root-netns route to the endpoint CIDR. Root-netns reachability is Cilium's responsibility.

## Cilium agent state at failure time

The failed app payloads contain only the workload exception:

- `corpus/results/aws_arm64_corpus_20260514_033028_884185/details/apps/cilium__agent.json`: `status=error`, zero persisted workloads, no `runner_details`, no lifecycle payload.
- `corpus/results/aws_arm64_corpus_20260514_035843_762748/details/apps/cilium__agent.json`: same shape, with endpoint IP `10.244.0.75`.

The run-level daemon logs are not Cilium logs. For the first failed run, `daemon.stdout.log` only says:

```text
serve: listening on /var/tmp/bpfrejit-daemon.sock
serve: shutting down
```

`daemon.stderr.log` is empty. No Cilium-agent stdout/stderr, endpoint JSON, route table, policy dump, `cilium-dbg status`, or drop monitor output was persisted in either failed artifact.

The Cilium state we can infer from control flow is stronger than the persisted JSON:

- `CiliumRunner.start()` starts the real `cilium-agent`, calls `_setup_managed_endpoints()`, refreshes BPF program IDs, then SIGSTOPs the agent at `runner/libs/app_runners/cilium.py:590`.
- `_setup_managed_endpoints()` calls `_wait_endpoint_ready()` for both managed endpoints before returning at `runner/libs/app_runners/cilium.py:505`.
- `_wait_endpoint_ready()` returns only when Cilium's API reports `status.state == "ready"` at `runner/libs/app_runners/cilium.py:490`.
- The remote progress logs show `lifecycle_phase_done` for `baseline_refresh` before `measurement_start`, so app startup and refresh completed before the workload failed.

Therefore the endpoint did reach Cilium API `ready` state. The artifacts do not show the endpoint's policy state, realized route state, or BPF drop counters at the failure time. There is also no evidence of a Cilium BPF load error surfacing before the workload. The failed payloads have zero persisted BPF samples because the baseline measurement aborted before a successful workload sample was recorded, not because the agent necessarily loaded no programs.

For comparison, the x86 KVM baseline artifact completes the same first leg in about one second:

```text
/usr/bin/wrk -t2 -c20 -d1s --timeout 1s http://10.244.0.90:18080/
120 requests in 1.00s
```

That x86 run has `status=ok`, 53 Cilium BPF programs in the baseline snapshot, and the expected Cilium datapath counters are non-zero, including `cil_xdp_entry`, `cil_from_host`, `cil_to_netdev`, `cil_from_netdev`, and `cil_from_container`.

## x86 vs arm64 env diff

Target/runtime shape:

- AWS arm64 uses AL2023 via `/aws/service/ami-amazon-linux-latest/al2023-ami-kernel-default-arm64` and `t4g.small` for bench runs at `runner/targets/aws-arm64.env:1`.
- x86 KVM uses the local VM executor with 8 bench CPUs and 64G memory at `runner/targets/x86-kvm.env:1`.
- Both run the Ubuntu 24.04 runner-runtime container as privileged with host networking and host PID namespace at `runner/libs/suite_commands.py:106`.
- The runtime container installs `iptables`, `iproute2`, `ipset`, `kmod`, `nftables`, and `wrk` at `runner/containers/runner-runtime.Dockerfile:15`.
- The Cilium binary comes from `quay.io/cilium/cilium:v1.19.3` and is copied into the runtime image at `runner/containers/runner-runtime.Dockerfile:228`.

Sysctl setup:

- The suite only forces `kernel.bpf_stats_enabled=1` globally at `runner/suites/_common.py:156`.
- Cilium endpoint setup disables `rp_filter` only on each endpoint host veth and inside each endpoint namespace at `runner/libs/app_runners/cilium.py:410`.
- The runner does not set root-netns `net.ipv4.ip_forward`, `net.ipv4.conf.all.rp_filter`, `net.ipv4.conf.default.rp_filter`, `net.ipv4.conf.bpfbench0.rp_filter`, or Cilium-created-device `rp_filter`.
- Kernel docs say `ip_forward` defaults to disabled and `rp_filter` source validation uses the max of `all` and per-interface values; the same docs note distributions may enable `rp_filter` in startup scripts at `vendor/linux-framework/Documentation/networking/ip-sysctl.rst:10` and `vendor/linux-framework/Documentation/networking/ip-sysctl.rst:2044`.

Kernel/module shape:

- The arm64 defconfig builds `veth`, `bridge`, `br_netfilter`, `nf_conntrack`, `nf_tables`, and `sch_netem` as modules at `vendor/bpfrejit_arm64_defconfig:1341`, `vendor/bpfrejit_arm64_defconfig:1358`, `vendor/bpfrejit_arm64_defconfig:1398`, `vendor/bpfrejit_arm64_defconfig:1690`, `vendor/bpfrejit_arm64_defconfig:1726`, and `vendor/bpfrejit_arm64_defconfig:2549`.
- The x86 defconfig has `veth`, `bridge`, and `nf_conntrack` built in, while `br_netfilter`, `nf_tables`, and `sch_netem` are modules at `vendor/bpfrejit_x86_defconfig:1434`, `vendor/bpfrejit_x86_defconfig:1451`, `vendor/bpfrejit_x86_defconfig:1491`, `vendor/bpfrejit_x86_defconfig:1783`, `vendor/bpfrejit_x86_defconfig:1819`, and `vendor/bpfrejit_x86_defconfig:2598`.
- The arm64 module tree in `.cache/repo-artifacts/arm64/kernel-modules/lib/modules/7.0.0-rc2+/` contains the expected `veth`, `sch_netem`, `nf_conntrack`, and `br_netfilter` modules. The failed run does not capture `lsmod`, so load state is unknown.

iptables/nftables:

- The runtime image installs both `iptables` and `nftables` and only verifies that `iptables`, `iptables-save`, `ip6tables-save`, `ipset`, and `nft` exist at `runner/containers/runner-runtime.Dockerfile:250`.
- The Dockerfile does not switch alternatives to `iptables-legacy`.
- Ubuntu 24.04 normally uses the nft-backed iptables frontend; the current host shows `iptables v1.8.10 (nf_tables)`. The actual failed container did not persist `iptables -V`, so this is strong expectation but not captured evidence.
- Both defconfigs have `CONFIG_NETFILTER_XTABLES_LEGACY` unset, so switching to legacy userspace is not a low-risk first fix.

Cilium docs and local docs:

- `runner/repos/cilium/Documentation/` does not exist in this sparse checkout, so local Cilium documentation could not be read.
- Official Cilium routing docs say native routing relies on Linux routing and Cilium enables IP forwarding for native routing; they also document exact local endpoint routes in the AWS ENI ingress model and the `enable-endpoint-routes` option: https://docs.cilium.io/en/stable/network/concepts/routing/
- Official Cilium system requirements say required kernel options may be built in or modules, and list routing/tunneling and iptables-based requirements separately: https://docs.cilium.io/en/stable/operations/system_requirements/
- Official Cilium iptables usage docs describe iptables as fallback/interop when eBPF features are unavailable: https://docs.cilium.io/en/latest/network/ebpf/iptables/
- Official Cilium masquerading docs say BPF masquerading attaches to selected devices and can be inspected with `cilium-dbg status`: https://docs.cilium.io/en/stable/network/concepts/masquerading/
- I did not find an official Cilium doc tying AL2023+nftables alone to this local host-to-endpoint blackhole. A closed Cilium issue tracks general AL2023 compatibility concerns, but it flags IMDSv2, SELinux, and kernel version rather than this nftables symptom: https://github.com/cilium/cilium/issues/24397

## Hypothesis verification

### A. AL2023 sysctl differs from KVM x86

Status: inconclusive, high priority.

Evidence for:

- The runner does not normalize root-netns forwarding or global/default `rp_filter`.
- The failure is a blackhole, which is consistent with route/source-validation problems.
- `rp_filter` per-interface disables at `runner/libs/app_runners/cilium.py:410` are insufficient if `net.ipv4.conf.all.rp_filter` is non-zero, because the kernel uses the max of `all` and per-interface settings.
- AWS arm64 is the only reproduced failing environment; x86 KVM works.

Evidence against:

- Cilium native routing should enable IP forwarding according to Cilium docs.
- No sysctl values were captured from the failed instance, so this is not proven.

What would confirm it:

```text
sysctl -n net.ipv4.ip_forward
sysctl -n net.ipv4.conf.all.rp_filter
sysctl -n net.ipv4.conf.default.rp_filter
sysctl -n net.ipv4.conf.bpfbench0.rp_filter
sysctl -n net.ipv4.conf.lxcbench0.rp_filter
ip -4 route get 10.244.0.247
```

### B. Missing kernel modules on arm64 AL2023

Status: mostly rejected for `veth` and `sch_netem`; inconclusive for `nf_conntrack`/`br_netfilter` load state.

Evidence against:

- Endpoint namespace/veth setup reached Cilium endpoint readiness.
- `network_lossy_multi` enters `_netem_qdisc()` before the Cilium matrix at `runner/libs/workload.py:992`; if `sch_netem` were missing, failure should occur before the endpoint `wrk`.
- The arm64 kernel artifacts include the relevant module files.
- The topology does not use a Linux bridge, so `br_netfilter`/`bridge-nf-call-iptables` are unlikely to explain the first host-to-endpoint leg.

Remaining gap:

- The failed run does not persist `lsmod`, `modprobe -n`, or Cilium's feature-probe output.
- `nf_conntrack` load state could still matter if a Cilium feature path unexpectedly depends on kernel conntrack, but this is not the first explanation for a local endpoint route blackhole.

### C. iptables vs nftables backend mismatch

Status: weak/inconclusive, not the leading cause.

Evidence for:

- The runtime image likely uses iptables-nft by default and does not record `iptables -V`.
- AL2023 and Ubuntu 24.04 both commonly expose nft-backed netfilter tooling.

Evidence against:

- The runner enables BPF masquerading at `runner/libs/app_runners/cilium.py:315`, disables L7 proxy at `runner/libs/app_runners/cilium.py:290`, and does not run Kubernetes/kube-proxy.
- Official Cilium docs describe iptables as fallback or legacy masquerading support, not the primary local endpoint path when BPF masquerading/native routing are active.
- Both defconfigs have xtables legacy disabled, so forcing `iptables-legacy` is likely to create a new failure rather than fix this one.
- There is no Cilium log showing iptables restore failure, nftables error, or missing xtables extension.

### D. Cilium BPF programs drop packets because policy/endpoint not ready

Status: endpoint-not-ready rejected; BPF/policy drop inconclusive.

Evidence against endpoint-not-ready:

- `_wait_endpoint_ready()` must have returned for both endpoints before `measurement_start`.
- The first failed command is not the HTTP server startup wait; it is the root-netns `wrk`.

Evidence against policy as the likely cause:

- Runner code creates endpoint labels but does not install Cilium policy objects.
- x86 KVM completes host-to-endpoint, endpoint-to-host, endpoint-to-endpoint, external-to-endpoint, and UDP legs with the same runner workload.

Remaining gap:

- No endpoint status JSON, policy map dump, drop monitor, or `cilium-dbg endpoint get` output exists in the failed artifacts.
- If Cilium installed a default-deny or host policy unexpectedly on arm64, the current artifacts cannot prove or disprove it.

### E. Veth/eth0 routing in `bpfbench-cepa` does not forward to outside

Status: confirmed as the failure surface; exact missing component still unproven.

Evidence:

- Server is in `bpfbench-cepa`; client is root netns.
- Endpoint `eth0` gets a `/32`, a route to the Cilium gateway, and a default route via that gateway at `runner/libs/app_runners/cilium.py:416`.
- The only runner-installed `10.244.0.0/24` route is inside `bpfbenchns`, not root netns.
- The first failing leg is exactly host/root to endpoint. No later Cilium matrix leg runs on arm64.

What is still unknown:

- Whether `ip route get 10.244.0.x` in root netns returns a Cilium route, the AWS default route, or no route.
- Whether traffic reaches `lxcbench0` and is dropped by Cilium BPF/policy.
- Whether the reply path is blocked by `rp_filter`.

## Fix options

### 1. Add fail-fast Cilium connectivity diagnostics before the first endpoint `wrk`

File/line: `runner/libs/workload.py:839` or `runner/libs/app_runners/cilium.py:505`

Change description:

- Before `_run_cilium_endpoint_matrix()` launches the first `wrk`, record and fail fast on:
  - `ip -4 route get <endpoint_a.ipv4>`
  - `ip -4 route show table all`
  - `ip rule show`
  - `ip -d link show dev bpfbench0`
  - `ip -d link show dev lxcbench0`
  - `tc filter show dev bpfbench0 ingress`
  - `tc filter show dev lxcbench0 ingress`
  - `bpftool net`
  - `sysctl -n net.ipv4.ip_forward net.ipv4.conf.all.rp_filter net.ipv4.conf.default.rp_filter net.ipv4.conf.bpfbench0.rp_filter net.ipv4.conf.lxcbench0.rp_filter`
  - `iptables -V`
  - `readlink -f "$(command -v iptables)"`
  - `lsmod | grep -E '^(veth|sch_netem|nf_conntrack|br_netfilter)\b'`
- Capture Cilium API endpoint payloads for the two managed endpoint IDs returned by `_setup_managed_endpoints()`.
- Run bounded probes: `timeout 3 ping -c1 <endpoint-ip>` and `timeout 3 curl -v --max-time 3 http://<endpoint-ip>:18080/`.

Risk:

- Low if emitted only on Cilium workload failure or as runner details for the failing app.
- Do not add always-on informational result fields; keep this tied to the failure path so it surfaces the real error.

Expected effect:

- Turns the current 31 second opaque timeout into a concrete route/sysctl/BPF/policy diagnosis.
- Distinguishes missing route from route-present/drop-present in one retry.

### 2. Enable explicit Cilium endpoint routes

File/line: `runner/libs/app_runners/cilium.py:330`

Change description:

- Add `--enable-endpoint-routes=true` near the existing native-routing flags:

```text
--routing-mode=native
--enable-endpoint-routes=true
--devices=bpfbench0
--direct-routing-device=bpfbench0
```

Risk:

- Medium. This changes the local endpoint route shape, likely from routing through `cilium_host` to exact routes via the endpoint veth.
- It may alter which Cilium BPF programs see host-to-endpoint traffic, so x86 coverage and raw BPF counters must be rechecked.

Expected effect:

- If arm64 is missing or misprogramming the root-netns route to the local endpoint, Cilium should install exact local endpoint routes such as `10.244.0.x dev lxcbench0`.
- This directly targets the confirmed failure surface without bypassing the real Cilium agent.

### 3. Normalize root-netns forwarding and reverse-path filtering for the Cilium app

File/line: `runner/libs/app_runners/cilium.py:572`

Change description:

- Before starting `cilium-agent`, set:

```text
net.ipv4.ip_forward=1
net.ipv4.conf.all.rp_filter=0
net.ipv4.conf.default.rp_filter=0
net.ipv4.conf.bpfbench0.rp_filter=0
```

- After Cilium creates any additional host devices, also ensure their `rp_filter=0` if present.
- Keep the existing endpoint veth and endpoint-netns disables at `runner/libs/app_runners/cilium.py:410`.

Risk:

- Low to medium. It changes host networking sysctls for the duration of the privileged benchmark container, but the benchmark already runs with host networking and creates dedicated synthetic interfaces.

Expected effect:

- Removes AL2023 distribution defaults as a variable.
- Prevents strict or loose source validation from dropping asymmetric Cilium endpoint traffic.

### 4. Preload required Cilium/network modules on arm64

File/line: `runner/libs/app_runners/cilium.py:572`

Change description:

- Before interface setup, load modules through the existing module helper rather than relying on implicit autoload:

```text
veth
sch_netem
nf_conntrack
br_netfilter
```

Risk:

- Low, but this is probably not the current root cause.

Expected effect:

- Fails early if the module tree is missing or unusable.
- Removes module autoload timing from arm64 startup.

### 5. Do not switch to `iptables-legacy` as the first fix

File/line: `runner/containers/runner-runtime.Dockerfile:250`

Change description:

- No immediate change recommended.
- If a future diagnostic shows a concrete nft/iptables failure in Cilium logs, investigate Cilium flags or nft-compatible operation first.

Risk:

- High for a blind legacy switch. The project kernels have `CONFIG_NETFILTER_XTABLES_LEGACY` unset on both x86 and arm64, and forcing legacy userspace may break Cilium startup.

Expected effect:

- None for the current host-to-endpoint blackhole unless diagnostics prove iptables rule installation is failing.

### 6. Do not add a runner-owned host route as the first fix

File/line: `runner/libs/app_runners/cilium.py:505`

Change description:

- Prefer validating `ip route get <endpoint-ip>` and failing with diagnostics over installing a manual root route from the framework.
- If a temporary diagnostic route is ever used, it should be guarded, explicit, and documented as a test-only probe, not a benchmark behavior change.

Risk:

- Medium to high. A framework-added route can hide a Cilium route-programming defect and change the datapath being benchmarked.

Expected effect:

- As a diagnostic only, it can prove "route missing" if adding the route immediately makes `curl` work.

## Recommendation

Run one AWS arm64 Cilium-only retry with a diagnostic patch that records root route, sysctl, module, iptables backend, Cilium endpoint JSON, `bpftool net`, and bounded `ping`/`curl` immediately before the first host-to-endpoint `wrk`.

If `ip route get 10.244.0.x` is missing or points at the AWS default route, apply fix option 2 (`--enable-endpoint-routes=true`) and recheck x86 + arm64 Cilium raw workloads. If the route is present but replies drop and any root/global `rp_filter` is non-zero, apply fix option 3. If Cilium endpoint JSON or drop telemetry shows policy/BPF drops despite endpoint `ready`, keep the fix in Cilium runner configuration and do not add framework-owned loader/routes.
