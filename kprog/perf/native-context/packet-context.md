# Upstream Cilium TC/XDP compiler experiment

The optional socket compiler also lowers TC and XDP entry contexts. These targets
read the unchanged `vendor/repos/cilium/bpf` sources. They do not select a runtime
manifest, replace the default native build, or modify the benchmark.

```sh
make -f kprog/perf/native-context/Makefile packet-context-check
make -f kprog/perf/native-context/Makefile upstream-cilium-link \
  CILIUM_UNIT=bpf_lxc CILIUM_CAPTURE=/path/to/retained/parity/bpf_lxc/capture
```

The capture must contain the existing Cilium parity recorder's `parity.json` and
`live-headers/` configuration data. `cilium-upstream.py` replays its original BPF
compiler flags, substitutes the canonical upstream source/include paths, and
reads the saved generated configuration directly. It records both commands,
source hashes and configuration hashes. It neither uses the old native command
nor reads its source overlay. Current evidence uses a retained November 9 run;
its configuration is not a new capture of the currently running application.

Both BPF and native objects come from that frontend IR. TC public metadata keeps
its 20-byte extent and maps onto `skb.cb + qdisc_skb_cb.data`. Class ID and wire
length map separately to qdisc fields. This preserves upstream scratch-map size
and metadata clearing. Native code retains upstream hybrid-routing branches and
live configuration accesses rather than forcing the routing setting off.

XDP ingress interface reads follow `rxq->dev->ifindex`; queue and egress fields
follow their kernel pointer chains. Public 32-bit packet-pointer fields become
full-width physical pointer loads. Compiler normalization preserves the upstream
BPF asm's length calculation, masked offsets, unsigned end check and error
result. Constant-map tail-call asm becomes an ordinary canonical helper call for
the existing linker. Empty memory barriers remain barriers.

Host fixtures detect qdisc overlap, narrow stores, suppressed queue-mapping
stores at/above 65535, VLAN normalization, packet-type masking, pointer truncation,
and XDP exact-end/overrun/zero-length/checksum bounds. A second fixture uses the
actual BPF asm forms before native retargeting. The socket executable sections
remain byte-identical to the retained dual-stack candidate.

`upstream-cilium-link` generates the existing offline linker's artifacts for all
TC/XDP entry sections and keeps each diagnostic. It runs all selected entries
even when an earlier entry fails; the final exit reports any failure. This is
ELF integration evidence, with no verifier submission or native execution.
Original-program helper deployment, actual application decisions, remaining
context/CO-RE mechanisms and throughput comparison still require completion.
