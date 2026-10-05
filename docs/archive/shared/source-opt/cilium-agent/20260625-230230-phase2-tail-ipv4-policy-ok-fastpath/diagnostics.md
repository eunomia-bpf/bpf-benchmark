# Diagnostics

Patch shape:

- Starts from the first-round best Cilium patch: mark both failed
  `revalidate_data()` checks in `tail_ipv4_to_endpoint()` as `unlikely()`.
- Rewrites the ingress policy result handling in `tail_ipv4_to_endpoint()` from
  `switch (ret)` to `if (likely(ret == CTX_ACT_OK)) goto out;`.
- Keeps proxy redirect handling and all drop/error handling on the same paths.

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
| `tail_ipv4_to_endpoint` | `0x3648` | `0x3648` | `0x3670` |
| `tail_ipv4_policy` | `0x3a98` | `0x3a98` | `0x3a98` |
| `tail_ipv4_ct_ingress` | `0x2930` | `0x2930` | `0x2930` |
| `tail_ipv4_ct_ingress_policy_only` | `0x2930` | `0x2930` | `0x2930` |
| `cil_lxc_policy` | `0x03f0` | `0x03f0` | `0x03f0` |
| `tail_handle_ipv4_cont` | `0x6da8` | `0x6da8` | `0x6da8` |

Section sizes:

| Section | Clean | Base | Patched |
| --- | ---: | ---: | ---: |
| `.text` | `0x6be8` | `0x6be8` | `0x6be8` |
| `tc/tail` | `0x5de00` | `0x5de00` | `0x5de28` |
| `tc/entry` | `0x26c8` | `0x26c8` | `0x26c8` |

Observed before formal run:

- The new fast-path rewrite increases `tail_ipv4_to_endpoint` and `tc/tail` by
  `0x28`, so this is a branch-layout attempt rather than an instruction-size
  reduction.
- It remains narrowly scoped to the current Cilium best hot function.

Formal result:

| Metric | Value |
| --- | ---: |
| pktgen total pps samples | `1635252, 1608005, 1585824` |
| pktgen total pps mean | `1609693.67` |
| vs clean baseline (`1488103`) | `+8.17%` |
| vs first-round best (`1672124`) | `-3.73%` |
| pktgen parsed errors | `0` |

Interpretation:

- Correctness passed and the patch remained faster than clean source.
- The explicit OK fast path did not improve over the current Cilium best and
  also underperformed the phase2 all-first-round stack.
- The next Cilium attempt should stop optimizing the `tail_ipv4_to_endpoint()`
  policy return layout and instead inspect another caller-side hot segment.
