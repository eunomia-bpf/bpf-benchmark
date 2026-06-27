# Diagnostics

Pre-run status:

- `vendor/repos/cilium` was clean after the prior Cilium phase2 state.
- Applied `20260625-090437-tail-ipv4-to-endpoint-revalidate-unlikely` as the
  base patch.
- A first `TAIL_CT_LOOKUP4` cold-check idea produced identical object code and
  was discarded before formal benchmarking; it is not counted as an attempt.
- `make -C vendor cilium-x86` passed after adding the reserved-identity cold
  hint.

Instruction / symbol-size observation:

| Object / symbol | Base | Candidate | Delta |
| --- | ---: | ---: | ---: |
| `tc/tail` section | `0x5de00` | `0x5de08` | `+0x8` |
| `tail_ipv4_to_endpoint` | `0x3648` | `0x3650` | `+0x8` |
| `tail_handle_ipv4_cont` | `0x6da8` | `0x6da8` | unchanged |
| `tail_ipv4_ct_egress` | `0x2aa0` | `0x2aa0` | unchanged |
| `tail_ipv4_policy` | `0x3a98` | `0x3a98` | unchanged |
| `tail_ipv4_ct_ingress` | `0x2930` | `0x2930` | unchanged |
| `cil_from_container` | `0x0bb8` | `0x0bb8` | unchanged |
| `cil_lxc_policy` | `0x03f0` | `0x03f0` | unchanged |

Object / disassembly checks:

- Base `tail` objdump SHA256:
  `fefe79ab15cf11ddff381263d171d4f589f15fbd147c1925374d23c1aebd8205`.
- Candidate `tail` objdump SHA256:
  `6f3f531c7e19ae64d31f7da8d9234750d4401769e7866da48c18afa2513209af`.
- `tail-objdump.diff` has 19,466 lines because labels and downstream offsets
  shifted, but the size change is confined to `tail_ipv4_to_endpoint` and the
  containing section.

Decision rule:

- Stack only if the formal run improves over the current Cilium best mean
  `1672124`.
- If the result is flat or lower, keep
  `20260625-090437-tail-ipv4-to-endpoint-revalidate-unlikely` as the base and
  switch away from additional cold-branch hints.

Post-run observation:

- Formal samples were `1683410, 1662935, 1671646`; mean=1672664.
- The candidate improved by 12.40% vs clean baseline and by 0.03% vs the
  previous Cilium best. The result is positive but tiny, so future attempts need
  larger hot-path work reduction rather than more branch-layout hints.
