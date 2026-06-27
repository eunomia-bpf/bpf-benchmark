# Diagnostics

Pre-run status:

- `vendor/repos/cilium` was clean after phase3 attempt 1 restore.
- Applied `20260626-105321-phase3-reserved-identity-cold` as the current Cilium
  phase3 base.
- `make -C vendor cilium-x86` passed for the base and for the candidate.

Instruction / symbol-size observation:

| Object / symbol | Base | Candidate | Delta |
| --- | ---: | ---: | ---: |
| `tc/tail` section | `0x5de08` | `0x5ddb8` | `-0x50` |
| `tail_handle_ipv4_cont` | `0x6da8` | `0x6d98` | `-0x10` |
| `tail_ipv4_to_endpoint` | `0x3650` | `0x3640` | `-0x10` |
| `cil_lxc_policy` | `0x03f0` | `0x03f0` | unchanged |
| `cil_lxc_policy_egress` | `0x0458` | `0x0458` | unchanged |
| `cil_from_container` | `0x0bb8` | `0x0bb8` | unchanged |
| `tail_ipv4_policy` | `0x3a98` | `0x3a98` | unchanged |
| `tail_ipv4_ct_ingress` | `0x2930` | `0x2930` | unchanged |
| `tail_ipv4_ct_ingress_policy_only` | `0x2930` | `0x2930` | unchanged |

Object / disassembly checks:

- Base `tail` objdump SHA256:
  `f1b74d88163c307bb853200587f53f713eebd90c6016cd16bba16f47cce7fd41`.
- Candidate `tail` objdump SHA256:
  `212e6ffeb43f2ebe215db68a0917dab81548c322334cdc803e9cea1719f9a5fc`.
- `tail-objdump.diff` has 70,958 lines because labels and downstream offsets
  shifted. The useful size signal is that the containing `tc/tail` section
  shrank by `0x50`, while several directly relevant symbols were unchanged or
  shrank slightly.

Decision rule:

- Stack only if the formal run improves over the current Cilium phase3 base mean
  `1672664`.
- If the result is lower, keep `20260626-105321-phase3-reserved-identity-cold`
  as the base and pivot away from policy verdict event preparation.

Post-run observation:

- Formal samples were `1554963, 1566899, 1596952`; mean=1572938.
- The candidate remained above clean baseline by 5.70%, but regressed by 5.96%
  vs the current Cilium phase3 base. Smaller `tc/tail` code did not translate
  into better endpoint pktgen throughput, so this patch should not be stacked.
