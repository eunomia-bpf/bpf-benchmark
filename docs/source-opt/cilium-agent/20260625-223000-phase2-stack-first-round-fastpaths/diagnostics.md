# Diagnostics

Patch shape:

- Stacks all five first-round Cilium source patches that passed correctness and
  had positive pktgen signals.
- `local_delivery()` expands `!should_redirect_peer(from_host)` into the
  equivalent direct condition and passes `false` to `redirect_ep()` in that
  branch.
- `cil_from_container()`, `cil_lxc_policy()`, and `cil_to_container()` mark
  invalid ethertype and failed `pull_l3_hdr()` branches as `unlikely()`.
- `tail_ipv4_to_endpoint()` marks both failed `revalidate_data()` checks as
  `unlikely()`.

Offline diagnostic compile:

```text
make -C vendor/repos/cilium/bpf CLANG=clang-18 bpf_lxc.o
```

This uses Cilium's BPF Makefile max-LXC compile-test flags, so it is a
relative codegen diagnostic rather than the formal runtime config. The formal
performance result still comes only from `SKIP_REJIT=all ... make corpus`.

Key symbol sizes, clean to patched:

| Symbol | Clean | Patched |
| --- | ---: | ---: |
| `cil_from_container` | `0x0bb8` | `0x0bb8` |
| `cil_lxc_policy` | `0x03f0` | `0x03b8` |
| `cil_to_container` | `0x12c8` | `0x12c8` |
| `tail_ipv4_to_endpoint` | `0x3648` | `0x3648` |
| `tail_ipv4_policy` | `0x3a98` | `0x3a98` |
| `tail_ipv4_ct_ingress` | `0x2930` | `0x2930` |

Section sizes, clean to patched:

| Section | Clean | Patched |
| --- | ---: | ---: |
| `.text` | `0x6be8` | `0x6be8` |
| `tc/tail` | `0x5de00` | `0x5ddb0` |
| `tc/entry` | `0x26c8` | `0x2690` |

Observed before formal run:

- The stacked patch does not increase hot section size.
- `cil_lxc_policy` shrinks by `0x38` bytes in the offline object.
- `tc/tail` shrinks by `0x50` bytes and `tc/entry` by `0x38` bytes.

Formal-run provenance note:

- The first formal-run start was interrupted before VM/container execution after
  noticing that the diagnostic compile had left `bpf_lxc.o` under
  `vendor/repos/cilium/bpf/`, which is copied wholesale into the runtime image.
- The generated diagnostic object and side files were deleted, then the formal
  `make corpus` run was restarted. The successful result below therefore used
  source-only input plus the normal runtime image build path.

Formal result:

| Metric | Value |
| --- | ---: |
| pktgen total pps samples | `1595444, 1626858, 1630134` |
| pktgen total pps mean | `1617478.67` |
| vs clean baseline (`1488103`) | `+8.69%` |
| vs first-round best (`1672124`) | `-3.27%` |
| pktgen parsed errors | `0` |

Interpretation:

- Correctness passed and the patch remained faster than clean source.
- The all-first-round stack is worse than the focused first-round
  `tail_ipv4_to_endpoint()` patch, so the next Cilium phase2 attempt should not
  use this complete stack as the base.
- Switching direction: inspect the exact benchmark config and compiled hot
  caller path instead of adding more broad `unlikely()` hints.
