# Cilium: the two arms run different packet paths

From the both-arm timing run `x86_kvm_corpus_20261114_171558_223789`
(`kprog/results/cilium-d08-20261114/`, 3 x 180 s, `status ok`, 113 native
replacements and 0 in the baseline). No `perf` capture exists for Cilium yet, so this is
the BPF-stats view, not an attribution.

## What the counters say

Active programs (per-program `run_cnt_delta > 100`) and their runs:

| arm | active programs | total runs |
|---|---:|---:|
| baseline (eBPF) | **2** | 808 155 254 |
| native | **4** | 3 115 871 992 |

By name:

| program | eBPF runs | native runs | eBPF ns/inv | native ns/inv |
|---|---:|---:|---:|---:|
| `cil_from_container` (2 instances) | 808 155 242 | 1 038 623 997 | 685.4 | 287.0 |
| `cil_from_host` | **2** | **1 038 623 994** | 1 587.0 | 151.1 |
| `cil_to_host` | **4** | **1 038 623 995** | 1 117.5 | 26.2 |
| `cil_xdp_entry`, `cil_to_netdev`, `cil_from_netdev` | 2 each | 2 each | — | — |

The two arms load the same 9 instances of each host program and both issue 80
`prog_array` writes and 11 `BPF_LINK_UPDATE`s on the same `link_fd`s. What differs is
which instances end up **attached to the device that carries the benchmark traffic**.

## The consequential facts

1. **Native runs per packet are identical across three programs.** `cil_from_host`,
   `cil_to_host` and `cil_from_container` all execute exactly 1 038 623 99x times, i.e.
   once per packet. Baseline's host programs execute twice in the whole 180 s.
2. **That count ratio equals the throughput ratio.** `1 038 623 997 / 808 155 242 =
   1.285`, and the pktgen throughput ratio measured the same way is **1.2852x**. The
   native arm is not processing packets faster per program on a different path — it
   processes 1.285x the packets, and each one traverses the host path the baseline's
   counters never see.
3. **`cil_from_container` is 2.39x cheaper** (685.4 -> 287.0 ns/inv) with the same
   number of invocations per packet. That is the container-datapath change `67802556c`
   (`micro_native_xdp_ingress_ifindex`) plus the D08/D09 work, and it is what frees the
   vCPUs to push 1.285x.

## What this means for the 1.319x floor

The frozen floor for Cilium is 1.319x; this run is **1.2852x**, so Cilium is 2.6% short.
The gap is not codegen: the four active programs' per-invocation costs all improved
(2.39x, 10.5x, 42x), and the remaining BPF time is dominated by `cil_from_container`'s
298 s of 482 s. Two candidate explanations, neither yet measured:

- The baseline's host programs are effectively free because they are not on the traffic
  path, so the native arm is paying for work the baseline skips. If the benchmark
  intended `cil_from_host`/`cil_to_host` to run, the baseline arm under-measures the app,
  and the honest comparison is the packet count, not the current pps ratio.
- The extra host-path work (157 s + 27 s of 482 s BPF) is real cost that a container-to-
  container benchmark does not need to pay; then the native arm's 1.285x is a *lower*
  bound and the container datapath itself is faster than the number shows.

Tell them apart by pinning one packet path (e.g. host-only or container-only pktgen) and
re-running both arms. Do not quote 1.2852x as the Cilium improvement without saying the
two arms exercise different programs.

## Where the numbers live

- Run: `corpus/results/x86_kvm_corpus_20261114_171558_223789`
- Record: `kprog/results/cilium-d08-20261114/README.md`
- Counters: `details/apps/cilium__agent.json` -> `.baseline.bpf` / `.post_rejit.bpf`
  (dicts keyed by record key; `run_cnt_delta`, `run_time_ns_delta`, `id`, `name`)
