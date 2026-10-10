# Cilium x86-64 JIT versus whole-program native rerun

## Result

The repaired whole-program-native arm passes the externally visible functional
gate. It has the same eight live attachment locations as JIT (one XDP and seven
TCX), forwards both packet directions, and has zero reason-133 policy drops,
receiver errors, receiver drops, or pktgen errors. The loader records 163
replacement events over multiple Cilium generations, including tail-call
targets; the final measured phase contains 72 native program IDs. This proves
matching live roots and packet outcomes, not identical internal instruction or
tail-call work.

The primary stats-off timing result is **1.213800x** by ratio of median packet
rates: JIT 843,734 pps [775,949, 912,163] and native 1,024,124 pps
[1,012,485, 1,076,259]. The five paired sample ratios have median 1.217861x
[1.122742, 1.304834]. This is an observed raw comparison, not a clean causal
native estimate: the separate JIT/JIT restart control had a large negative
drift, 0.808244x by ratio of medians (798,259 to 645,188 pps), with paired
median 0.790240x [0.695410, 0.924488]. Dividing treatment by that control gives
1.501774x, but the runs are separate and the drift is large, so that adjusted
number is diagnostic only.

With BPF statistics enabled in a separate run, pooled BPF cost was
913.696 ns/run for JIT and 743.726 ns/run for native, a raw 1.228538x cost
speedup. The stats-on JIT/JIT restart control itself improved from 988.203 to
909.102 ns/run, an apparent 1.087011x speedup. The corresponding diagnostic
control-adjusted native cost ratio is 1.130199x. The two hot
`cil_from_container` programs improved by 1.245360x and 1.208879x in the native
run; the control improved by 1.078222x and 1.118977x.

The same stats-on run's workload-rate medians were 894,425 pps JIT and
971,729 pps native (1.086429x); its JIT/JIT control moved 890,636 to
905,073 pps (1.016210x). This rate is supplementary because BPF accounting was
enabled.

This does **not** reproduce or validate the paper's 2.357974x result. The new
raw throughput ratio is 48.524% lower relative to that ratio. More importantly,
the paper-era native path did different packet work: retained source and replay
evidence shows that it was built without `POLICY_AUDIT_MODE` while the JIT
Cilium agent ran with audit mode, and its native arm policy-dropped traffic
that JIT forwarded. See [paper-audit-mode.md](paper-audit-mode.md).

An independent post-run configuration review also found that complete
compile-time parity still fails: the paper-era `CILIUM_MAX_*` native recipes
hardcode host-firewall, DSR, and monitor-aggregation defines that the paired
JIT daemon configuration does not emit. Packet-path parity is established, but
identical conditional code is not. Consequently these measurements are a
diagnostic repaired-paper rerun, not a final unbiased native upper bound.

## Functional gates

The accepted native/JIT gate is
`x86_kvm_corpus_20261010_052134_234335` (one four-second sample per phase,
stats off):

| Arm | Sent | Receiver packets | Allow dir. 1 | Allow dir. 2 | reason 133 | Other verdicts | pktgen/RX errors or drops |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| JIT | 3,705,358 | 3,705,379 | 3,705,376 | 3,705,376 | 0 | 0 | 0 |
| native | 1,979,182 | 1,979,202 | 1,979,200 | 1,979,200 | 0 | 0 | 0 |

Receiver and allow counts exceed admitted traffic only by 18--21 startup/control
packets. The raw `bpftool net` snapshots show XDP on `bpfbench0`; TCX ingress
and egress on `bpfbench0`; TCX ingress on `cilium_net`; TCX ingress and egress
on `cilium_host`; and endpoint ingress on `lxcbench0` and `lxcbench1` in both
arms. The post-native IDs are 409 (XDP) and 514, 490, 473, 541, 559, 426, and
503 (TCX). The initial filtered validator took its program inventory before
the final two `bpfbench0` TCX IDs appeared and reported 6/8; the unfiltered raw
snapshot, captured in the same phase, proves 8/8.

The already-completed kinsn gate is retained only as a scoped-out result in
`x86_kvm_corpus_20261010_052139_855300`. JIT sent 5,399,205 packets and kinsn
sent 6,145,763, with zero pktgen/RX errors or drops and zero reason-133 drops.
Each arm recorded sent+18 allows in both directions; JIT had one reason-139
control event and kinsn had none. Per the final operator scope, kinsn was not
profiled or timed.

## Timing counters and parity

Each timing run used a single 8-vCPU, 64 GiB guest. The vCPU threads were
individually pinned to host P-cores 0--7; QEMU helper threads were allowed on
0--23. Each phase used one warmup followed by five retained 60-second samples.
BPF statistics were disabled for throughput and enabled only for the separate
cost runs.

Across all 40 retained phase samples, pktgen errors, receiver errors, receiver
drops, and reason-133 drops were zero. Receiver counts were sent+125--131 and
both directional allow counts were sent+122--127 per sample. The only other
verdicts were zero to four reason-139/reason-3 control events per sample. Thus
the timing arms exercised the same successful bidirectional outcome path; the
native speedup is not explained by dropping the measured packets.

Totals across the five samples in each stats-off phase were:

| Comparison | Phase | Sent | Receiver packets | Allow dir. 1 / dir. 2 | Other verdicts |
| --- | --- | ---: | ---: | ---: | ---: |
| JIT/JIT control | first JIT | 241,693,356 | 241,693,997 | 241,693,974 / 241,693,980 | 8 |
| JIT/JIT control | restarted JIT | 193,375,387 | 193,376,028 | 193,376,008 / 193,376,012 | 7 |
| JIT/native | JIT | 254,073,969 | 254,074,608 | 254,074,585 / 254,074,591 | 8 |
| JIT/native | native | 309,684,705 | 309,685,340 | 309,685,321 / 309,685,324 | 7 |

The stats-on totals and every individual sample are in `analysis.json` and
`samples.csv`; every program's raw run count, run time, and image-size fields
are in `bpf-programs.csv` and the source corpus directories.

## Profile explanation

The separate 60-second profiles are under
`../cilium_profile_jit_kprog_full_20261010/`. With profiling enabled on a
4-vCPU/16 GiB guest, native was 3.244% slower in packet throughput and used
3.207% more cycles/packet. It used 1.398% more instructions/packet, had 1.753%
lower IPC, and used 5.129% more branches/packet. Conversely, branch
misses/packet fell 19.524%, branch-miss rate fell 23.451%, and cache
misses/packet fell 20.379%.

Resolved non-idle leaf sampling estimates JIT/native ns per packet as
91.988/100.210 in BPF code, 34.399/37.864 in helpers, 567.087/517.490 in map
operations, and 2,138.258/2,431.623 in the rest of the kernel stack. Native's
map-leaf estimate improves 8.746% and `lookup_nulls_elem_raw` samples fall
12,620 to 8,223, but `htab_lru_map_update_elem` rises 5,969 to 7,865 and
`_raw_spin_unlock_irqrestore` rises 28,045 to 32,742. The better locality
counters and map lookups therefore coexist with no net gain in this one
profiled pair; the sampled categories alone do not establish causality.
The split is a leaf-symbol heuristic, not inclusive callchain attribution;
unresolved leaves are 5.352% for JIT and 0.124% for native.

Across all 163 lifecycle replacement events, original JIT images total 687,766
bytes; native blobs total 792,890 bytes (+15.285%), and BPF-callable native
stubs total 797,332 bytes (+15.931%). Restricting the comparison to the final
72 native IDs gives 301,961 JIT bytes, 353,834 native-blob bytes (+17.179%),
and 355,802 callable-stub bytes (+17.830%). Per-program sizes, run counts, PMU counters, perf
data, call graphs, top symbols, kernel symbol/module snapshots, and image
metadata are retained in the profile result. Gate/timing evidence also retains
the `bpftool` translated-image output and every raw-JIT dump attempt. The guest
`bpftool` reported `No JIT disassembly support` for binary dump attempts, so no
raw `.jited.bin` payloads exist; the kernel-reported per-program JIT byte sizes
and native object/stub sizes are the retained image comparison.

## Fixes used by this result

- `648a57149`: the guest inherited a host Docker daemon configuration whose
  storage settings prevented the inner daemon from creating `/run/docker.sock`.
  A guest-private empty config, data/exec roots, explicit socket, readiness
  check, and regression test make the runtime container start reliably.
- `7f70d5ca9`: native data symbols were resolved by the native ELF offset even
  when Cilium's source BTF data-section layout differed. The loader now resolves
  the source map symbol offset from BTF and has an ABI/layout regression test.
- `8db310e54`: `/proc/self/fd` enumeration raced FD reuse, allowing metadata
  and kernel addresses from different maps. The loader duplicates each FD
  before inspection and tests the reuse race.
- `d820f689c`: native TC programs treated `skb->cb` as the start of
  `sk_buff.cb`, while verifier-rewritten JIT uses `qdisc_skb_cb(skb)->data` at
  +8 bytes. The native compatibility layout now includes that pivot and static
  offset assertions.
- `c049e2232`: native Cilium objects omitted `POLICY_AUDIT_MODE`, so policy
  failures returned drops while the JIT agent's `--policy-audit-mode=true`
  path forwarded them. The native build now defines the macro and a test ties
  the build setting to the runner setting.
- `1a23be6a1`, `911cd0fba`, and `d129aac16`: evidence capture was made
  observational, tail-call snapshots tolerate only documented ID churn, and
  raw-JIT dump attempts are retained. Capture runs outside timed workload
  windows.
- `8a775701c`: the image build deleted the only module staging tree before a
  replacement was complete, so an interrupted or overlapping rebuild could
  package no `pktgen.ko`. It now validates a sibling generation for
  `modules.order` and `pktgen.ko`, then atomically switches a `current` symlink.
  The regression test covers invalid and successive generations. A full image
  rebuild validated 842 modules including `pktgen.ko`.

## Paper comparability and remaining differences

The Cilium gitlink is identical to the reconstructed paper source:
`1b721c2964e7799cab3e18c38066905ea240fa34` (`1.20.0-dev`). The Cilium runner
configuration, policy, two-endpoint/veth topology, bidirectional 64-byte UDP
pktgen traffic, random-flow packet shape, and two-start measurement procedure
were kept. Changes are limited to native/JIT semantic parity, complete
replacement/attachment handling, runtime packaging, and read-only evidence.

Remaining differences are recorded rather than hidden:

- The paper retained three 180-second samples; this run uses five 60-second
  samples after a warmup. The paper did not record its CPU model or affinity.
  This host is an Intel Core Ultra 9 285K, with timing vCPUs pinned 0--7.
- This guest uses the rebuilt custom `7.0.0-rc2+` kernel, 8 vCPUs and 64 GiB.
  The paper metadata does not retain an exact kernel/source pin or guest size.
- The current native arm replaces 163 programs and proves all eight attachment
  locations. The paper audit reported 113 replacements and its replay loses
  five host/network TCX attachments, retaining only the two endpoint TCX
  attachments plus XDP.
- The current native build adds the required data-layout, skb-layout, and audit
  macro fixes. Map FDs are pinned during discovery. These alter only bugs that
  made native do different work from JIT.
- The inherited paper-era native recipes still use hardcoded `CILIUM_MAX_*`
  feature sets rather than Cilium's exact per-object generated configuration.
  In particular they enable host firewall and DSR and force monitor aggregation
  level 3/`CT_REPORT_FLAGS=0x0002`, while the paired JIT daemon defaults to host
  firewall off, SNAT load-balancing mode, and monitor aggregation none. This is
  a known compile-time configuration mismatch even though the observed live
  hooks, root invocations, verdict class, and delivery match.
- Outcome snapshots, attachment inventories, JIT/image metadata, and profiling
  are new read-only observations. They are taken outside timing windows; the
  profile itself is a separate diagnostic run.
- Profiles intentionally use 4 vCPUs, 16 GiB, CPUs 16--19, BPF stats, PMU
  counters, and callgraph sampling; they are not pooled with timing.
- Timing used one fixed-order two-start transition per guest. Its five samples
  are repeated measurements, not five independent VM/restart replications;
  pktgen directions were imbalanced and QEMU helper threads were not isolated
  from the benchmark P-cores. The large, sign-changing controls make the raw
  ratios useful observations but not a precise causal speedup.

The timing runtime image SHA-256 is
`94f7dc5845b38bc6c81469aee07ad3f320a00de5092d277192e09edf9ea05f44`.
The accepted gate used the immediately preceding equivalent runtime image
`e1192651c83290a830b7bdee79c8e3c27ac15d727e2fce42fa7b14844cf93110`;
the later rebuild validates only atomic module packaging and includes the same
datapath changes. No host reboot occurred during this run; host boot ID stayed
`04dc0087-5ccc-4c46-9997-b9a92f0e5167`.
