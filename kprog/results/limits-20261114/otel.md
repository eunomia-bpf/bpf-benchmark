# OTel performance limits, 2026-11-14

The measured same-source known-hash diagnostic is **0.954x throughput** and **0.885x per invocation** (3315.2 to 3745.7 ns). The 20% target is throughput; neither per-invocation speed nor a host component pass satisfies it. Run `054100_189324`, raw `/workspaces/kprog-raw/perf/20261114-known-hash-instruction-profile`; source analysis/receipt: `../perf_20261113/known-hash-instruction-profile-results.json`.

## Observed profile

These are sampled cycle shares of **all measured guest-kernel roots**, not shares of BPF time. Inlined map/tail code stays in program text. Root-only IPs cannot assign an inclusive helper caller or separate tail dispatch after inlining. Unknown and unrelated kernel roots stay visible.

| Root bucket | eBPF | Native |
| --- | ---: | ---: |
| other_guest_kernel | 36.17% | 32.24% |
| lpm_lookup | 19.75% | 21.16% |
| program_text | 14.04% | 16.83% |
| user_nofault_copy | 17.07% | 15.72% |
| hash_lookup | 9.53% | 7.93% |
| array_lookup | 1.55% | 4.24% |
| generic_lookup_dispatch | 1.00% | 1.12% |
| probe_read_user_entry | 0.85% | 0.74% |
| probe_read_kernel_entry | 0.02% | 0.01% |
| kernel_nofault_copy | 0.01% | 0.01% |

## Conditional code-generation limit

For a BPF-time program fraction f and a program-only speedup s, total speedup is `1 / (1-f+f/s)`. The absolute program-only ceiling in that model is `1/(1-f)`; a modest assumed code speedup is a different calculation, not an absolute ceiling.

If the identified program/helper candidate roots were a representative BPF denominator, f would be 0.2200. Under that **unproven denominator assumption**, eliminating all program-text cost gives 1.282x, making code 30% faster gives 1.053x, and reaching 1.20x needs 4.13x program-only speed. The actual native main unwinder is slower: normalized root cycles rise 2221.88 to 2894.39 per entry. This supports prioritizing helper LTO, while it does not establish a measured 1.06x absolute ceiling.

Exact BPF-time shares for every helper and tail calls are **still unmeasured** in this capture. Caller-sensitive BPF attribution is needed to complete that part of the requested profile. This is not a new measurement admission gate; the complete 0.954x result is retained. Cilium and Tetragon profiles remain separate open work. Probe-read first, then hash/LPM LTO, remains the optimization order.
