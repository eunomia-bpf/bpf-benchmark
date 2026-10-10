# Cilium JIT versus whole-program native: profile findings

## Result and provenance

This profile used the runtime image validated by Agent 1
(`sha256:4483167ce49bcfd064e88f8728034ebb11975c96740d945389cd278a257a9508`),
host P-cores 0--7, eight guest vCPUs, 64 GiB, one 60-second sample per fresh
guest, BPF statistics enabled, and both guest orders (`JIT -> native` and
`native -> JIT`). It is a diagnostic profile separate from the timing suite.

The counterbalanced geometric-mean native/JIT ratios are 0.8640 for
cycles/packet, 0.9719 for instructions/packet, 1.0031 for branches/packet,
0.6852 for branch misses/packet, 1.4171 for cache misses/packet, and 0.6756
for aggregate BPF ns/run. Thus native's remaining gain is not fewer branches:
it executes about 2.8% fewer instructions, suffers about 31.5% fewer branch
misses, and raises IPC, while trading for about 41.7% more cache misses.
Order remains material: native saves 10.9% and 16.2% cycles/packet in the two
orders, and 27.3% and 37.2% aggregate BPF ns/run.

## Where the sampled time changes

The positive sampled ns/packet savings split consistently in both orders:

- maps contribute 56.6% and 56.1%; normalized `lookup_nulls_elem_raw` alone
  falls from 257.6 to 195.1 ns/packet and from 275.3 to 171.4 ns/packet;
- BPF program code contributes 26.6% and 29.7%; the two hot endpoint roots
  fall from 557--559 to 388--424 ns/run in `JIT -> native`, and from 604--611
  to 371--393 ns/run in `native -> JIT`;
- the rest of the stack contributes 15.9% and 13.3%; and
- helpers contribute only 0.9% and 1.0%, so helper time is essentially flat.

All sampled `_raw_spin*` leaves whose callchain passes through
`htab_lru_map_update_elem` or `bpf_common_lru_pop_free` are classified as
maps: 35/34 such samples in `JIT -> native` and 33/24 in `native -> JIT`.
They are not included in the rest category.

## Same-work evidence

All four runs have zero workload-component errors, RX errors, and RX drops.
Both endpoint directions produce the dominant allow verdict. In every run,
the sum of the two hot endpoint-root invocation counts equals the received
packet count exactly, and total selected-program invocations are 1.000002
per sent packet to displayed precision. The 4 native and 10 JIT non-allow
verdicts, and the additional one- or two-run control hooks, are startup/control
traffic rather than workload-scale skipped work.

## Image size

The image calculation is restricted to the 51 native IDs reachable in each
post-replacement `live-program-graph.json`, not phase-counter rows or all
lifecycle replacement events. Both fresh native boots therefore have the same
live-program total: 233,646 original JIT bytes versus 257,161 native-blob bytes
(+10.064%). Native BPF-callable stubs total 258,579 bytes (+10.671%).

## Callgraph boundary

Post-workload `/proc/modules` and `/proc/kallsyms` snapshots resolve the pktgen
addresses that perf originally rendered as `[unknown]`; all four final reports
have zero unresolved leaf samples. Raw `perf.data`, compressed symbolized
scripts, full reports, counters, program inventories, and outcome records are
retained in the four arm directories.

This hybrid host intentionally exposes no KVM guest architectural PMU.
Capability probes established that software events reject LBR, Intel PT is
not exposed to the guest, and host LBR captures only VM-exit host branches.
The retained, arm-neutral `cpu-clock` callgraphs therefore use frame pointers:
they resolve native frames and helper/map callees but cannot unwind callers
above omit-frame-pointer native code. No synthetic ancestry is reported.
