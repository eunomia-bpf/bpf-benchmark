Katran sample decay, 2026-11-16

Coordinator 21:19 requests the sample-by-sample slowdown after the shared-hash
comparison. The current image remains 6641a7e1. This directory analyzes retained
raw results only; it launches no guest and changes no frozen file or setting.

The default Make target analyzes C's stats-off run 192946_405839, committed in
15d1fda7d. Pass RUN=<stats-on run directory> CASE=stats-on when C's ongoing
round reaches Katran. Each thread's packetgen packets, pps, errors, kernel
duration, wrapper duration and return code remain separate in the report.
Packetgen errors do not establish the number of BPF drops.

Counter scope is a material limit: runner/libs/rejit.py:462-484 has one
measure_start before the sample loop and one measure_finish after it.
Consequently the frozen three-sample result contains one aggregate BPF delta
per arm and three workload records. It does not contain three per-call times.
BCC run 202317_937563's shim log independently shows one start/finish pair
covering the full approximately 541-second arm. A throughput curve cannot be
converted to per-sample BPF ns/call without additional counter observations.
The analysis retains the aggregate per-call value when stats are enabled and
reports the missing sample times explicitly. No new collection or gate is added.

Stats-off result, run 192946_405839

| Worker | JIT sample 1 | JIT sample 2 | JIT sample 3 | Native sample 1 | Native sample 2 | Native sample 3 |
|---|---:|---:|---:|---:|---:|---:|
| 0 | 537420 | 947725 | 935808 | 669008 | 784120 | 602560 |
| 1 | 474129 | 351340 | 258669 | 558930 | 529538 | 538766 |
| 2 | 523417 | 846011 | 821358 | 825331 | 711764 | 499452 |
| 3 | 556232 | 821997 | 888751 | 826852 | 629003 | 633561 |
| Total pps | 2091198 | 2967073 | 2904586 | 2880121 | 2654425 | 2274339 |

Native workers 2 and 3 lose 519170 of the total 605782 pps between the first
and third samples, about 85.7% of the decline. Worker 1 loses 3.6%, while
worker 2 loses 39.5%. The JIT arm also has a sharply declining worker 1
(45.4%) alongside three rising workers. Per-worker execution or queue/cache
state therefore deserves attention in the next stats-on comparison. This
pattern alone does not identify scheduling, cache behavior or a code defect.

All packetgen kernel intervals span 179.895–180.005 seconds. The native
reported-error counts are 336148672/352860124/279585127; errors per reported
packet are 0.649/0.739/0.683. The error fraction is not a monotonic explanation
of the PPS series, and these counts cannot be renamed BPF drops. Stats are off,
so per-call time is unmeasured. stats-off.json retains every component and
the arm metadata. C's current round is on Tracee stats-on at this checkpoint;
Katran stats-on follows. No additional timing run has been started.

Transport and cache source facts

All 24 worker observations in the retained run have queue_map_min=0,
queue_map_max=0 and cur_queue_map=0. The analyzer now keeps those fields.
The frozen runner sets four pktgen aliases without a queue-map command
(runner/libs/app_runners/katran.py:746-777). Kernel pktgen selects that range
at net/core/pktgen.c:2438-2456 and writes it to the skb at 2994.

veth_xmit uses that queue mapping to choose one receive rq
(drivers/net/veth.c:365-379). Its veth_xdp_rx enqueues into rq->xdp_ring
(312-317), and ptr_ring_produce serializes producers on producer_lock
(include/linux/ptr_ring.h:124-132). veth is lockless at the outer TX layer
(veth.c:1742), so HARD_TX_LOCK itself is not the contention site here.
All four producers nevertheless share the ring producer lock and one NAPI
poller. Packetgen worker numbers therefore do not identify four independent
BPF execution queues or four corresponding LRU consumers.

The ring-full path returns NETDEV_TX_BUSY before veth_poll runs XDP.
For a no-queue qdisc, veth_xmit frees it and returns NET_XMIT_DROP
(veth.c:393-410); pktgen increments errors at pktgen.c:3662-3665. This is a
concrete pre-XDP source of the observed error counter. XDP runs later in
veth_xdp_rcv_skb (veth.c:819), called from the NAPI consumer at 934.
The observations alone do not say how many errors took that path.

The retained same-image four-vCPU shared-hash PMU diagnostic is consistent
with substantial locking work. Dividing its external root cycles by app calls:

| Unowned guest root | JIT cycles/app call | Native cycles/app call |
|---|---:|---:|
| __pv_queued_spin_lock_slowpath | 340.623 | 336.469 |
| _raw_spin_lock | 225.626 | 235.060 |
| __raw_callee_save___pv_queued_spin_unlock | 122.892 | 117.230 |

Source data: shared-hash-regression-20261116/katran-shared.costs.json.
These roots have no exclusive caller ownership; they cannot all be assigned
to the ring or used as measured costs of the three-sample stats-off run.
The queue topology and worker imbalance prioritize this transport path as a
cause to distinguish from changing BPF cost. The frozen queue setup stays.

Cache initialization is also shared in the checked source: the runner command
at katran.py:479-492 supplies no forwarding_cores argument; upstream
example_grpc/katran_server.cpp:62 defaults it to an empty list and sets the
config at 130. KatranLb::attachLrus iterates only those cores
(KatranLb.cpp:551-555); empty forwarding cores create an inner template but
populate no per-core entries (527-537). balancer.c:838-850 then selects
fallback_cache, declared as a 1000-entry LRU (balancer_maps.h:40-47 and
balancer_consts.h:113). This predicts shared fallback use under these defaults,
not separate populated per-worker caches. It is source reasoning; the timed
run has no retained dump of lru_mapping entries or fallback-counter deltas.
The shared/copied hash change preserves the LRU marking operations in either
case. No cache capacity or benchmark configuration is changed.

The three transport kernel files above are unchanged between boot build
099357174783 and the pending kernel source HEAD; this source explanation
applies to the current boot. Exact per-sample per-call times remain absent.

Stats-on follow-up, 2026-11-16T22:33:10Z

Run 215758_610196 on the same 6641a7e1 image completed both arms. JIT
aggregate time is 185.812 ns/call over 1,273,952,408 calls; native is
187.283 ns/call over 1,272,388,027 calls (JIT/native 0.99215x). Installed
JIT/native bytes are 13,641/10,546 (0.7731 native/JIT). These counters span
the whole three-sample arm; the frozen recorder retains no sample ns/call.

| Arm | Sample 1 pps | Sample 2 pps | Sample 3 pps |
| --- | ---: | ---: | ---: |
| JIT | 2,273,993 | 2,392,485 | 2,414,048 |
| Native | 2,469,673 | 2,215,775 | 2,330,732 |

Native worker series are 744282/726301/559463, 147141/38149/420201,
825751/749178/691346 and 752499/702147/659722. Worker 1's later rise offsets
losses at the other workers; its JIT series is 458702/469025/159354. All
workers again select queue 0. The monotone native decline of the stats-off
run did not repeat here; this observation does not establish why it happened
or rule out an image interaction. Aggregate per-call times are near parity,
and the differing worker shares keep shared transport scheduling/cache state
as a lead. BPF-stats, queue, capacity and workloads were unchanged.

The packetgen errors/packets ratios are 1.279/1.152/1.242 for JIT and
1.227/1.129/1.215 for native. These are retained producer reports, not BPF
drop counts. Reproduce with the committed analyze target, RUN pointing at
215758_610196 and CASE=stats-on. Raw component values are in stats-on.json.
