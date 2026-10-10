# Cilium JIT versus whole-program native profile

These profiles are separate from timing runs, use the timing topology (host P-cores 0--7, 8 vCPUs, 64 GiB), and counterbalance fresh-boot order.
There is one fresh-guest pair per order, so the profile diagnoses mechanisms but does not estimate between-guest uncertainty.

| Order | Position | Arm | Packets | BPF runs/packet | aggregate BPF ns/run | cycles/packet | instructions/packet | IPC | branches/packet | branch misses/packet | branch miss rate | cache misses/packet |
| --- | ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| jit-kprog | 1 | jit | 87976501 | 1.000 | 558.025 | 5119.152 | 12571.090 | 2.456 | 2296.618 | 2.468274 | 0.107474% | 4.505008 |
| jit-kprog | 2 | kprog | 98830204 | 1.000 | 405.563 | 4560.677 | 12201.885 | 2.675 | 2302.589 | 1.763710 | 0.076597% | 6.643630 |
| kprog-jit | 1 | kprog | 100824230 | 1.000 | 381.713 | 4463.253 | 12230.122 | 2.740 | 2307.016 | 1.734653 | 0.075190% | 6.334797 |
| kprog-jit | 2 | jit | 84576785 | 1.000 | 607.760 | 5326.072 | 12568.547 | 2.360 | 2298.683 | 2.640238 | 0.114859% | 4.652043 |

## Within-order native/JIT ratios

Ratios compare the two fresh boots within each order; values below 1.0 favor native.

| Order | cycles/packet | instructions/packet | branches/packet | branch misses/packet | cache misses/packet | aggregate BPF ns/run |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| jit-kprog | 0.8909 | 0.9706 | 1.0026 | 0.7146 | 1.4747 | 0.7268 |
| kprog-jit | 0.8380 | 0.9731 | 1.0036 | 0.6570 | 1.3617 | 0.6281 |
| counterbalanced geometric mean | 0.8640 | 0.9719 | 1.0031 | 0.6852 | 1.4171 | 0.6756 |

## Hot endpoint-root BPF cost

| Order | Arm | Attach point | Runs | ns/run |
| --- | --- | --- | ---: | ---: |
| jit-kprog | jit | `tc:lxcbench0:tcx/ingress` | 43988164 | 559.036 |
| jit-kprog | jit | `tc:lxcbench1:tcx/ingress` | 43988478 | 557.013 |
| jit-kprog | kprog | `tc:lxcbench0:tcx/ingress` | 50261430 | 387.703 |
| jit-kprog | kprog | `tc:lxcbench1:tcx/ingress` | 48568910 | 424.044 |
| kprog-jit | kprog | `tc:lxcbench0:tcx/ingress` | 50021847 | 392.625 |
| kprog-jit | kprog | `tc:lxcbench1:tcx/ingress` | 50802521 | 370.969 |
| kprog-jit | jit | `tc:lxcbench0:tcx/ingress` | 42288650 | 611.415 |
| kprog-jit | jit | `tc:lxcbench1:tcx/ingress` | 42288275 | 604.105 |

## Outcome counters

| Order | Arm | Sent | Received | Component errors | RX errors | RX drops | Allow dir. 1 | Allow dir. 2 | Other verdicts |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| jit-kprog | jit | 87976501 | 87976642 | 0 | 0 | 0 | 87976631 | 87976637 | 10 |
| jit-kprog | kprog | 98830204 | 98830340 | 0 | 0 | 0 | 98830334 | 98830336 | 4 |
| kprog-jit | kprog | 100824230 | 100824368 | 0 | 0 | 0 | 100824360 | 100824362 | 4 |
| kprog-jit | jit | 84576785 | 84576925 | 0 | 0 | 0 | 84576915 | 84576921 | 10 |

## Resolved non-idle context-attributed split

Frame-pointer context assigns LRU map spin-lock samples to maps. The units are estimated guest sampled nanoseconds per packet. These are context associations, not proof that native directly speeds map implementations.

| Order | Arm | BPF code ns/packet | Helpers ns/packet | Maps ns/packet | Rest ns/packet |
| --- | --- | ---: | ---: | ---: | ---: |
| jit-kprog | jit | 135.548 | 85.409 | 356.504 | 805.317 |
| jit-kprog | kprog | 91.308 | 83.932 | 262.197 | 778.760 |
| kprog-jit | kprog | 87.677 | 84.226 | 239.952 | 778.920 |
| kprog-jit | jit | 159.346 | 86.584 | 375.410 | 810.944 |

### Within-order sampled savings attribution

Positive values are JIT minus native sampled ns/packet. The share is relative to the sum of positive category savings in that order.

| Order | BPF code | Helpers | Maps | Rest | Total |
| --- | ---: | ---: | ---: | ---: | ---: |
| jit-kprog | 44.239 (26.6%) | 1.477 (0.9%) | 94.307 (56.6%) | 26.557 (15.9%) | 166.581 |
| kprog-jit | 71.669 (29.7%) | 2.358 (1.0%) | 135.458 (56.1%) | 32.024 (13.3%) | 241.509 |

## Measured live-program image sizes

Only programs reachable from the final measured XDP/TCX roots are included; stale measured IDs and earlier lifecycle replacements are excluded.

| Order | Live programs | Original JIT bytes | Native blob bytes | Native stub bytes | Blob growth | Stub growth |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| jit-kprog | 51 | 233646 | 257161 | 258579 | 10.064% | 10.671% |
| kprog-jit | 51 | 233646 | 257161 | 258579 | 10.064% | 10.671% |

| Order | Arm | Unresolved leaf samples | Estimated unresolved sampled ns/packet | Unresolved share of non-idle samples |
| --- | --- | ---: | ---: | ---: |
| jit-kprog | jit | 0 | 0.000 | 0.000% |
| jit-kprog | kprog | 0 | 0.000 | 0.000% |
| kprog-jit | kprog | 0 | 0.000 | 0.000% |
| kprog-jit | jit | 0 | 0.000 | 0.000% |

## Callgraph capability boundary

This hybrid host's KVM intentionally exposes no guest architectural PMU; software events reject LBR sampling, guest Intel PT is absent, and a host LBR probe records only VM-exit host branches. The retained callgraphs therefore use arm-neutral guest `cpu-clock` sampling and frame pointers. They resolve native frames and their helper/map callees, but cannot unwind callers above native code compiled with omitted frame pointers. No synthetic ancestry is used.

Raw counters, perf data, symbol snapshots, full call graphs, and per-program tables are in each arm directory.
