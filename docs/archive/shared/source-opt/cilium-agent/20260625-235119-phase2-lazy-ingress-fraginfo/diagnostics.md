# Diagnostics

Patch shape:

- Starts from the first-round best Cilium patch: mark both failed
  `revalidate_data()` checks in `tail_ipv4_to_endpoint()` as `unlikely()`.
- Changes `ipv4_policy()` so `ipfrag_encode_ipv4(ip4)` is no longer computed
  unconditionally at function entry.
- If `CONFIG(enable_ipv4_fragments)` is false, it computes `fraginfo` before
  deriving `is_untracked_fragment`, preserving the old non-tracking behavior.
- If reply/rev-NAT needs `ipfrag_has_l4_header(fraginfo)` and fragment tracking
  is enabled, it computes `fraginfo` in that rare branch.

Offline diagnostic compile:

```text
make -C vendor/repos/cilium/bpf CLANG=clang-18 bpf_lxc.o
```

This uses Cilium's BPF Makefile max-LXC compile-test flags, so it is a
relative codegen diagnostic rather than the formal runtime config. The formal
performance result still comes only from `SKIP_REJIT=all ... make corpus`.

Key symbol sizes:

| Symbol | Previous base | Patched |
| --- | ---: | ---: |
| `tail_ipv4_to_endpoint` | `0x3648` | `0x3728` |
| `tail_handle_ipv4_cont` | `0x6da8` | `0x6da8` |
| `tail_ipv4_ct_egress` | `0x2aa0` | `0x2aa0` |
| `tail_ipv4_policy` | `0x3a98` | `0x3b10` |
| `tail_ipv4_ct_ingress` | `0x2930` | `0x2930` |
| `cil_lxc_policy` | `0x03f0` | `0x03f0` |

Section sizes:

| Section | Previous base | Patched |
| --- | ---: | ---: |
| `.text` | `0x6be8` | `0x6be8` |
| `tc/tail` | `0x5de00` | `0x5df58` |
| `tc/entry` | `0x26c8` | `0x26c8` |

Observed before formal run:

- The patch increases code size because `CONFIG(enable_ipv4_fragments)` is a
  rodata config load in the offline compile-test object.
- The candidate is still worth one formal run because the workload enables IPv4
  fragment tracking and sends non-fragmented UDP packets, so the intended
  runtime hot path skips IPv4 fragment decoding in ingress policy.
- If this regresses, avoid further config-branching in `ipv4_policy()` and pivot
  to a more direct endpoint-local delivery specialization.

Formal result:

| Metric | Value |
| --- | ---: |
| pktgen total pps samples | `1460702, 1462853, 1446400` |
| pktgen total pps mean | `1456651.67` |
| vs clean baseline `1488103` | `-2.11%` |
| vs first-round best `1672124` | `-12.89%` |
| pktgen errors | `0` |

Interpretation: correctness passed, but the extra config-dependent control flow
and larger `tail_ipv4_to_endpoint` / `tail_ipv4_policy` codegen outweighed any
saved fragment decode work for this workload. Do not stack this patch.
