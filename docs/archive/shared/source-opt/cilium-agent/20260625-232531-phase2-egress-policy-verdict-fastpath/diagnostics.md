# Diagnostics

Patch shape:

- Starts from the first-round best Cilium patch: mark both failed
  `revalidate_data()` checks in `tail_ipv4_to_endpoint()` as `unlikely()`.
- Adds three IPv4 egress cold-branch hints in `handle_ipv4_from_lxc()`:
  `verdict == DROP_POLICY_AUTH_REQUIRED`, `verdict != CTX_ACT_OK`, and
  `ct_state->proxy_redirect`.
- Does not mark `ct_status != CT_ESTABLISHED` cold because the pktgen workload
  varies destination ports with `flows 65535`.

Rejected pre-run candidate:

- A larger rewrite split the policy verdict block into an explicit
  `likely(verdict == CTX_ACT_OK)` fast path.
- It was not run formally because the offline diagnostic grew
  `tail_handle_ipv4_cont` from `0x6da8` to `0x7210` and `tc/tail` from
  `0x5de00` to `0x5e268`.
- The rejected diff and diagnostics are preserved as
  `source-rejected-large-verdict.diff` and `diag-rejected-large-verdict-*`.

Offline diagnostic compile:

```text
make -C vendor/repos/cilium/bpf CLANG=clang-18 bpf_lxc.o
```

This uses Cilium's BPF Makefile max-LXC compile-test flags, so it is a
relative codegen diagnostic rather than the formal runtime config. The formal
performance result still comes only from `SKIP_REJIT=all ... make corpus`.

Key symbol sizes:

| Symbol | Clean | Base | Patched |
| --- | ---: | ---: | ---: |
| `tail_ipv4_to_endpoint` | `0x3648` | `0x3648` | `0x3648` |
| `tail_handle_ipv4_cont` | `0x6da8` | `0x6da8` | `0x6dd0` |
| `tail_ipv4_ct_egress` | `0x2aa0` | `0x2aa0` | `0x2aa0` |
| `tail_ipv4_policy` | `0x3a98` | `0x3a98` | `0x3a98` |
| `tail_ipv4_ct_ingress` | `0x2930` | `0x2930` | `0x2930` |
| `cil_lxc_policy` | `0x03f0` | `0x03f0` | `0x03f0` |

Section sizes:

| Section | Clean | Base | Patched |
| --- | ---: | ---: | ---: |
| `.text` | `0x6be8` | `0x6be8` | `0x6be8` |
| `tc/tail` | `0x5de00` | `0x5de00` | `0x5de28` |
| `tc/entry` | `0x26c8` | `0x26c8` | `0x26c8` |

Observed before formal run:

- The accepted candidate is small: `tail_handle_ipv4_cont` and `tc/tail`
  increase by only `0x28`.
- The change targets caller-side egress error/proxy paths instead of the
  already-tested `tail_ipv4_to_endpoint()` policy return layout.

Formal result:

| Metric | Value |
| --- | ---: |
| Result | `corpus/results/x86_kvm_corpus_20260626_063507_838342` |
| pktgen_total_pps samples | `1473623, 1488389, 1467531` |
| pktgen_total_pps mean | `1476514.33` |
| Parsed pktgen errors | `0` |
| vs clean baseline mean `1488103` | `-0.78%` |
| vs first-round best mean `1672124` | `-11.70%` |

Interpretation:

- Correctness passed, but the caller-side egress verdict/proxy hint patch hurt
  the workload enough to fall below the clean-source baseline.
- Do not stack this patch. The next Cilium attempt should move away from simple
  branch-layout hints in `handle_ipv4_from_lxc()` / `tail_ipv4_to_endpoint()`
  and target a more structural hot-path cost.
