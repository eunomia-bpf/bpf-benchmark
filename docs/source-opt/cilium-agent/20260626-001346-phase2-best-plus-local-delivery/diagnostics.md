# Diagnostics

Patch shape:

- Keeps the first-round best Cilium patch: mark both failed
  `revalidate_data()` checks in `tail_ipv4_to_endpoint()` as `unlikely()`.
- Adds only the first-round positive `local_delivery()` simplification:
  remove the temporary `use_redirect_peer`, inline the equivalent
  `!should_redirect_peer(from_host)` condition, and pass literal `false` to
  `redirect_ep()` in the branch where redirect peer cannot be used.

Offline diagnostic compile:

```text
make -C vendor/repos/cilium/bpf CLANG=clang-18 bpf_lxc.o
```

This is a relative codegen diagnostic; formal performance comes only from
`SKIP_REJIT=all ... make corpus`.

Key symbol sizes:

| Symbol | Previous clean/first-round base | Patched |
| --- | ---: | ---: |
| `tail_ipv4_to_endpoint` | `0x3648` | `0x3648` |
| `tail_handle_ipv4_cont` | `0x6da8` | `0x6d80` |
| `tail_ipv4_ct_egress` | `0x2aa0` | `0x2aa0` |
| `tail_ipv4_policy` | `0x3a98` | `0x3a98` |
| `tail_ipv4_ct_ingress` | `0x2930` | `0x2930` |
| `cil_lxc_policy` | `0x03f0` | `0x03f0` |

Section sizes:

| Section | Previous base | Patched |
| --- | ---: | ---: |
| `.text` | `0x6be8` | `0x6be8` |
| `tc/tail` | `0x5de00` | `0x5ddb0` |
| `tc/entry` | `0x26c8` | `0x26c8` |

Observed before formal run:

- This candidate is much smaller than the rejected lazy-fraginfo attempt and
  does not expand `ipv4_policy()`.
- It directly targets the local endpoint handoff path that precedes
  `tail_ipv4_to_endpoint()` for the pktgen workload.
- If this still loses to the first-round best, Cilium phase2 should keep the
  focused `tail_ipv4_to_endpoint()` patch as best result.

Formal result:

| Metric | Value |
| --- | ---: |
| pktgen total pps samples | `1534942, 1516759, 1532465` |
| pktgen total pps mean | `1528055.33` |
| vs clean baseline `1488103` | `+2.68%` |
| vs first-round best `1672124` | `-8.62%` |
| pktgen errors | `0` |

Interpretation: correctness passed and the result stayed above clean source,
but it did not compose with the first-round best. The local-delivery
simplification's standalone +1.04% does not stack with the much larger
`tail_ipv4_to_endpoint()` layout win for this workload. Do not stack this patch.
