# Cilium native build back on the agent's compile-time switches (2026-11-25)

The timed Cilium arms differed: the eBPF arm runs the agent's own programs (runner/libs/app_runners/cilium.py:
--policy-audit-mode=true, --enable-monitor=false, --enable-hubble=false, no --monitor-aggregation, so the agent's
headers carry #undef MONITOR_AGGREGATION, TRACE_NOTIFY 1, DROP_NOTIFY 1, POLICY_AUDIT_MODE 1, POLICY_VERDICT_NOTIFY 1,
CT_REPORT_FLAGS 0x0007; captured in /workspaces/kprog-raw/perf/20261113-cilium-live-config/baseline-state/state/),
while the native objects were built with MONITOR_AGGREGATION=3, CT_REPORT_FLAGS=0x0002 and host firewall, DSR,
nodeport acceleration, BPF host routing and ENCAP_IFINDEX=1 (the 5/29 option set). At level 3 the native code skips
the inbound trace points and every packet without a conntrack report flag, where the agent's code builds a trace
record and calls perf_event_output on every packet. 3ff2ac946 (11-17) had aligned the switches; the 5/29 restore
3aa496416 (11-21) dropped that alignment. Analysis: /workspaces/kprog-raw/coordinator/sa-20261125/cilium-parity/.

This commit puts the agent's switch set back for the three objects the workload loads (bpf_lxc, bpf_host, bpf_xdp);
overlay, sock and wireguard, which the workload leaves unloaded, keep the broader set. Rebuilt with
`make -C vendor/bpf native-cilium` (rc 0); the DWARF producer flags of the three objects now read
MONITOR_AGGREGATION=0, CT_REPORT_FLAGS=0x0007, ENABLE_MASQUERADE_IPV4=1 and no DSR/host-firewall (build-x86.log).

Consequence for the numbers: every Cilium native/eBPF ratio measured with the 5/29 option set (05-29 1.319x per call;
11-21 onward, including 30e401e37's 1.105x-1.248x per call and 1.179x-1.190x stats off on x86, and arm64 runs 5-7)
compares arms with different per-packet work and is marked not comparable. Cilium is timed again on the rebuilt image.
