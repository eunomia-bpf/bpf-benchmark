Same-load Cilium packet comparison

Minimal scope: use upstream app-loaded original/native program IDs, one
captured workload packet, and upstream bpftool's libbpf test-run operation.
Record return value, returned context and redirect helper target. No new BPF
object, custom loader, source copy, image, benchmark setting or launcher change.

The existing diagnostic profile guest starts Cilium normally. During its
native workload phase, a result-local callback selects cil_from_container on
lxcbench0 from bpftool's actual network attachments. The shim's original/native
jit-info pair supplies the original ID retained through its shadow FD. Thus
both tests use the same endpoint and map configuration; actual FD lifetime is
checked by the kernel operation itself. A missing original ID is a diagnostic
failure, not permission to load a replacement object or compare another app.

AF_PACKET captures one incoming IPv4 UDP packet from the frozen endpoint
workload. Public context offsets and size come from the sole kernel UAPI.
Both tests use identical packet/context bytes, ifindex and wire length.
Transient tracefs kprobes on redirect/redirect_peer/redirect_neigh record the
actual helper target, filtered to each bpftool caller PID. The returned skb
ifindex is the source device and is not mislabeled as the redirect target.
The callback removes only its own probes after retaining the traces.

This is a functional experiment on CPUs20-23 under image SH; timing lock and
CPUs0-7 remain with the frozen check. Diagnostic counters include these test
calls and profile overhead, so this run supplies no official speed number.
Live connection-tracking state can change between calls; the packet is from
an already active workload, and returned packet/context plus helper traces
remain to expose differences. No map reset or workload change is made.

Preflight: UAPI context192B, ifindex40, ingress36, wire_len160. The pairing
parser finds113 pairs in retained Cilium063056_107201. The four Python/C entry
files parse/compile. bpftool's current TCX schema uses prog_id; clsact uses id.
The real packet execution remains pending at this commit.

Run with the result-local Makefile. Raw output is retained under
/workspaces/kprog-raw/perf/20261116-cilium-packet; no shared Makefile target is
added. The existing phase-profile guest/host machinery owns execution and
cleanup, with this callback inserted only in the experiment's local wrapper.
