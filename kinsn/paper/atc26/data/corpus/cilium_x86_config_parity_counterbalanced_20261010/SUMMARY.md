# Cilium x86-64 JIT versus whole-program native, config-parity rerun

## Result

With Cilium's generated configuration held identical, whole-program native
processed a median **1.1938x** as many packets/s as kernel JIT (**+19.38%**).
This is the primary BPF-stats-off result across six fresh treatment guests,
three in each order.  Its inclusive IQR is **1.1853--1.2056x** and its full
range is **1.0744--1.2077x**.

The old paper-era **2.357974x** transmitter-rate ratio is not an
equivalent-forwarding result.  Its JIT arm enabled `POLICY_AUDIT_MODE`, while
the retained native recipe did not.  Replays of that recipe drop the native
traffic as policy reason 133, and the old artifacts do not retain an exact
native object, receiver counters, verdict counters, or live attachments.
The corrected 1.1938x result is 49.37% lower than the old ratio and supersedes
it for same-work claims.

## Functional gate

The accepted gate is
`corpus/results/x86_kvm_corpus_20261010_091727_881080`.

- The paired compiler captured Cilium's actual `bpf_alignchecker`, `bpf_host`,
  `bpf_lxc`, and `bpf_xdp` compiler commands and generated node, netdev, and
  endpoint headers.  All four archived macro comparisons passed with zero
  unexpected or missing differences.  The only permitted differences are
  the compiler target, audited native entry ABI, and an exact specialization
  of the paired JIT object's `hybrid_routing_enabled` rodata scalar required
  by the native ABI.
- JIT and native each had 8 attached roots, 51 reachable live programs, and
  382 captured tail-map edges.  Their attachment signatures and canonical
  `(type, full program name, multiplicity)` inventories were identical.
- JIT sent 7,225,419 packets and receivers counted 7,225,443; native sent
  8,172,952 and receivers counted 8,172,974.  Both had zero pktgen errors,
  receiver errors, receiver drops, and reason-133 drops.  JIT had two small
  non-allow control verdicts and native had none.

The timing analysis rechecks the same contracts.  All 12 native treatment
guests have a passing 51-versus-51 live-inventory record, and all 48 paired
object macro-parity records pass.  The accepted gate's generated headers,
both preprocessed macro sets, parity reports, and before/after live graphs are
retained under `functional-gate-evidence/`.

## Counterbalanced timing

Every cell used a fresh 8-vCPU, 64-GiB local KVM guest pinned with
`vng --pin 0-7` to host P-cores 0--7.  Each phase ran the unchanged
bidirectional, random-flow, 64-byte UDP pktgen workload for 60 seconds.  The
unit of analysis is one fresh guest containing the two compared starts.  For
each stats mode there are three JIT-to-native guests, three native-to-JIT
guests, and six JIT-to-JIT restart-control guests placed in the two order
blocks.

| Measurement | n | Median | Inclusive IQR | Range |
| --- | ---: | ---: | ---: | ---: |
| Stats off, native/JIT throughput, both orders | 6 | 1.1938x | 1.1853--1.2056x | 1.0744--1.2077x |
| Stats off, JIT then native | 3 | 1.2014x | 1.1938--1.2042x | 1.1862--1.2070x |
| Stats off, native then JIT | 3 | 1.1850x | 1.1297--1.1963x | 1.0744--1.2077x |
| Stats on, native/JIT throughput, both orders | 6 | 1.1537x | 1.1267--1.1849x | 1.0999--1.2421x |
| Stats on, JIT/native pooled BPF ns/run | 6 | 1.4044x | 1.3329--1.5094x | 1.2637--1.6351x |

With stats enabled, the across-guest medians are 659.20 ns/run for JIT and
463.88 ns/run for native.  These are pooled entry-program accounting costs;
tail-call work is charged to the entry invocation by the kernel, so they are
not independent per-tail-program timings.  Stats-on throughput is secondary
because BPF accounting itself changes the datapath cost.

### Restart controls and order drift

The stats-off JIT/JIT second/first ratio has median **1.0378x**, inclusive IQR
**1.0156--1.0635x**, and range **0.9812--1.0866x**.  By placement, its medians
are 1.0121x in the JIT-to-native block and 1.0496x in the native-to-JIT block.
The treatment-order medians differ by 1.39 percentage points (1.2014x versus
1.1850x), while one native-first treatment is the 1.0744x low outlier.  The
control spread remains material, so 1.1938x is reported with its complete
spread rather than as a precision estimate.

The stats-on JIT/JIT control median is 1.0096x, IQR 1.0028--1.0517x, range
0.9878--1.1467x.  Its order-block medians are 1.0009x and 1.0653x.

## Same-work and placement counters

Across all 48 accepted timing phases, pktgen sent 4,060,754,735 packets and
receivers counted 4,060,761,436.  Every phase had zero pktgen errors, receiver
errors, receiver drops, and reason-133 events.  Receiver-minus-sent is
136--142 packets per phase (median 140), attributable to startup/control
traffic.  Cilium's metrics map records:

- reason 0, direction 1: 4,060,760,977;
- reason 0, direction 2: 4,060,761,177;
- reason 3, direction 1: 141;
- reason 139, direction 2: 239;
- reason 133: 0.

Both pktgen workers are recorded on guest CPUs 0 and 1.  NET_RX softirq deltas
are 2,028,449,771 on CPU0 (49.953%), 2,032,305,846 on CPU1 (50.047%), and only
274 total on CPUs2--7.  NET_TX softirq deltas are zero.  The vCPU threads were
observed pinned one-to-one to host CPUs0--7.  QEMU helper threads were not
separately isolated.

## Program images

Every treatment phase archives `bpftool` translated dumps and program-info
image sizes for all reachable programs.  This bpftool build reports `No JIT
disassembly support`; the failed binary-dump attempts and stderr are retained
rather than silently omitted.  `live-program-images.csv` is the normalized
51-program-per-arm size export.  The live JIT set totals 233,646 bytes and
native totals 258,579 bytes in every guest: native is **1.1067x** the JIT image
size (+10.67%).  `programs.csv` retains raw per-program BPF counters and sizes
from every phase.

## Counterbalanced profile

The corrected profile is in
`corpus/results/cilium_profile_jit_kprog_counterbalanced_20261010`.  It uses
four additional fresh 8-vCPU, 64-GiB guests pinned to host CPUs0--7: one JIT
and one native guest in each order.  The counterbalanced geometric-mean
native/JIT ratios are **0.8640 cycles/packet**, **0.9719
instructions/packet**, **1.0031 branches/packet**, **0.6852 branch
misses/packet**, **1.4171 cache misses/packet**, and **0.6756 aggregate BPF
ns/run**.  Thus native's benefit is visible as 13.60% fewer host cycles per
packet and 32.44% less kernel-accounted BPF time, despite 41.71% more cache
misses; it is not explained by skipping an attachment, direction, or verdict.

Guest `cpu-clock:k` frame-pointer samples place the reduction primarily in
BPF code and map work.  In the two orders, estimated BPF-code time is
135.548 to 91.308 and 159.346 to 87.677 ns/packet, and map time is 356.504 to
262.197 and 375.410 to 239.952 ns/packet.  Helper time is nearly unchanged
(85.409 to 83.932 and 86.584 to 84.226 ns/packet); the rest of the stack also
falls modestly (805.317 to 778.760 and 810.944 to 778.920 ns/packet).  Across
orders, maps account for 56.1--56.6% and BPF code for 26.6--29.7% of the
positive sampled savings.  The dominant JIT symbols include the
policy and IPv4 conntrack tail programs; `lookup_nulls_elem_raw` dominates map
samples in both arms.  This supports the interpretation that whole-program
native reduces executed BPF/map-path cost, not the amount of externally
visible policy work.

All four profile phases have one endpoint-root BPF invocation per packet,
bidirectional allow counters, and zero pktgen errors, receiver errors,
receiver drops, or reason-133 drops.  Host KVM has `enable_pmu=N`, so guest
hardware PMU and guest LBR branch stacks are unavailable.  Hardware counters
therefore come from host `perf stat`; call graphs use fixed-period guest
software sampling.  Post-workload module symbolization resolves all retained
non-idle leaves.  The category split remains diagnostic rather than exact
causal accounting because the native compiler omits caller frame pointers
above native code and the samples are fixed-period observations.

## Fixes made for this rerun

1. **Configuration parity.**  The old native build hardcoded host firewall,
   DSR, and monitor-aggregation defines that the daemon-generated JIT objects
   did not have.  Native Cilium is now compiled from the exact intercepted JIT
   compile command and generated headers.  Both full preprocessed macro sets
   are archived and a non-ABI difference is fatal.
2. **Live inventory parity.**  Truncated kernel program names had hidden which
   native symbol occupied a hook or tail slot.  Evidence capture now constructs
   the reachable XDP/TCX/tail-call graph, canonicalizes native names from the
   loader log, and fails on any attachment or inventory mismatch.
3. **Both timing orders.**  The lifecycle can place native in either the first
   or second start, allowing native-to-JIT as well as JIT-to-native guests and
   matched JIT-to-JIT controls.
4. **Native loader cache race.**  concurrent Cilium load threads used the same
   PID-only temporary proof path and could delete one another's files.  Cache
   temporary names now include PID and TID; a regression unit test covers the
   collision.
5. **Read-only placement evidence.**  Workload results now retain pktgen worker
   CPUs and per-CPU NET_RX/NET_TX softirq deltas.  Reads occur outside the
   measured packet-generation window.
6. **Runtime-image modules.**  Runtime-image assembly now preserves the full
   built module tree, including `pktgen.ko`, instead of requiring a repair
   after each rebuild.  The fixed image and tar hashes are in
   `fixed-image.txt`.

## Attempts, provenance, and limitations

Twenty-four guests were accepted from 28 attempts.  Four partial attempts had
no accepted artifact: one stopped before Docker startup, one stopped during a
baseline pktgen phase, and two reached the bounded 480-second timeout when a
second pktgen phase did not return.  Each cell was rerun from a fresh guest.
No partial phase was used.

The host did not reboot during the gate or timing sequence.  Its boot ID was
`04dc0087-5ccc-4c46-9997-b9a92f0e5167` throughout.  The fixed runtime image is
`sha256:4483167ce49bcfd064e88f8728034ebb11975c96740d945389cd278a257a9508`;
the atomic image tar SHA-256 is
`d293c3ec43a6521ec62e517a6c23c25d6b8eb6d5bd1554fc21d888b4ced508b4`.

The run retains the paper's Cilium source
`1b721c2964e7799cab3e18c38066905ea240fa34` (`1.20.0-dev`), daemon
configuration, policy, two-endpoint topology, packet shape, and two-start
measurement model.  Necessary differences are the paired native ABI/compiler
path, strict parity and read-only evidence, complete native replacement, and
counterbalanced fresh guests.  This rerun uses the current local benchmark
kernel `7.0.0-rc2+`, 8 pinned P-cores, 64 GiB, and 60-second phases; the old
paper run used three 180-second within-guest samples and did not retain enough
metadata to certify its kernel or CPU pinning.

The profile's unavailable guest-PMU/LBR fields are reported as host capability
limitations and are not inferred from the older pre-parity profile.

Raw accepted run locations, rejected attempts, start/end times, and host boot
IDs are in `runs-fixed.tsv`; phase counters are in `samples.csv`; guest ratios
are in `guests.csv`; the reproducible aggregation is `analyze.py` and
`analysis.json`.
