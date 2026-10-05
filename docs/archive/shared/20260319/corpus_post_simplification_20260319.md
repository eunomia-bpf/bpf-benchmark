# Corpus Post-Simplification Baseline (2026-03-19)

## Run

- Command:
  ```bash
  source /home/yunwei37/workspace/.venv/bin/activate
  make vm-corpus
  ```
- Output JSON: `corpus/results/dev/vm_corpus.json`
- Output markdown: `corpus/results/dev/vm_corpus.md`
- Guest kernel: `7.0.0-rc2-gb50fd62797d7-dirty`
- Repeat: `200`

## Topline

| Metric | Value |
| --- | ---: |
| Measured pairs | `152/152` |
| Applied programs | `61` |
| Overall exec geomean | `0.816131x` |
| Applied-only exec geomean | `1.061757x` |
| Non-applied exec geomean | `0.684171x` |

Comparison against prior corpus baselines:

- Versus authoritative build #42 (`2026-03-14`, `1.046336x` overall): current run is `0.780x` of that topline, about `-22.0%`.
- Versus post-revert rerun (`2026-03-19`, `0.899971x` overall): current run is `0.907x` of that topline, about `-9.3%`.
- Applied-only improved versus post-revert (`1.022548x -> 1.061757x`), about `+3.8%`.
- Applied count stayed at `61`, same as the post-revert run and well above the March 14 authoritative run (`39`).

Verdict:

- This does **not** establish a stronger corpus baseline than the March 14 authority.
- The applied subset is healthy and improved, but the clean post-simplification corpus topline regressed sharply overall.

## By Project

| Project | Current exec geomean | Post-revert (2026-03-19) | Authority (2026-03-14) | Current applied |
| --- | ---: | ---: | ---: | ---: |
| calico | `1.013x` | `1.023x` | `1.097x` | `46` |
| linux-selftests | `0.577x` | `0.708x` | `1.005x` | `4` |
| xdp-tutorial | `1.100x` | `1.244x` | `1.091x` | `4` |
| katran | `0.745x` | `0.759x` | `0.872x` | `2` |
| xdp-tools | `1.007x` | `1.005x` | `1.062x` | `1` |
| tracee | `1.041x` | `1.060x` | `0.990x` | `2` |
| suricata | `1.000x` | `0.971x` | `0.857x` | `0` |
| libbpf-bootstrap | `1.128x` | `0.968x` | `0.944x` | `1` |
| real_world_code_size | `1.083x` | `0.961x` | `1.059x` | `1` |

Project-level takeaways:

- `linux-selftests` is the dominant regression source and worsened again (`0.708x -> 0.577x`).
- `katran` remains a persistent negative source and got slightly worse (`0.759x -> 0.745x`).
- `calico` stayed positive, but fell below both prior reruns (`1.023x -> 1.013x`, far below `1.097x` authority).
- `tracee`, `xdp-tools`, `suricata`, `libbpf-bootstrap`, and `real_world_code_size` are not the reason the topline collapsed.

## Notable Regressions

### 1. Linux-selftests short no-op rows dominate the overall loss

- `linux-selftests` contributed `45` regressions out of `59` measured rows, with only `4` applied rows.
- Worst rows are mostly non-applied ultra-short programs:
  - `__encap_ip6gre_eth`: `4ns -> 27ns` (`0.148x`)
  - `skb_pkt_end/main_prog`: `5ns -> 17ns` (`0.294x`)
  - `__encap_ip6tnl_none`: `4ns -> 13ns` (`0.308x`)
  - `decap_f`: `8ns -> 26ns` (`0.308x`)
  - `pkt_ptr`: `3ns -> 9ns` (`0.333x`)

Noise concentration is still obvious:

- `80/152` rows have baseline `<=20ns`
- `71/152` are both baseline `<=20ns` and non-applied
- `48` of those `<=20ns` rows are regressors

### 2. This run is worse than the post-revert rerun even after removing short non-applied rows

- If I exclude non-applied rows with baseline `<=10ns`, the geomean is only `0.956575x`.
- If I exclude non-applied rows with baseline `<=20ns`, the geomean is only `0.966311x`.

So the current `0.816x` topline is **not** explained purely by `3-10ns` quantization noise.

### 3. There are medium-length non-applied regressions, especially in calico

- `calico/from_hep_debug/...calico_tc_skb_ipv4_frag`: `108ns -> 293ns` (`0.369x`)
- `calico/xdp_debug/...calico_xdp_accepted_entrypoint`: `140ns -> 298ns` (`0.470x`)
- `calico/to_nat_debug/...calico_tc_skb_icmp_inner_nat`: `111ns -> 231ns` (`0.481x`)
- `calico/from_nat_debug/...calico_tc_skb_ipv4_frag`: `107ns -> 201ns` (`0.532x`)
- `xdp-tutorial/tracing03-xdp-debug-print/...xdp_prog_simple`: `162ns -> 314ns` (`0.516x`)

These rows are not applied-policy regressions; they sit in the non-applied population that is dragging down the full-suite result.

### 4. There is also at least one clear applied regression

- `katran/balancer_ingress` applied `wide+endian`, but regressed from `21ns -> 52ns` (`0.404x`).

Other applied regressions above `100ns` baseline:

- `calico/xdp_debug/calico_xdp_main`: `236ns -> 275ns` (`0.858x`)
- `calico/from_nat_debug/calico_tc_skb_drop`: `106ns -> 120ns` (`0.883x`)
- `calico/to_nat_debug/calico_tc_main`: `108ns -> 121ns` (`0.893x`)

### 5. The applied subset still has real wins

- `calico/from_hep_debug/calico_tc_skb_icmp_inner_nat`: `198ns -> 100ns` (`1.980x`)
- `xdp-tutorial/packet03-redirecting/xdp_redirect_map_func`: `26ns -> 18ns` (`1.444x`)
- `tracee` stayed net positive overall at `1.041x`

## Bottom Line

- Post-simplification corpus rerun: overall `0.816x`, applied-only `1.062x`, applied `61`.
- Relative to the post-revert rerun, the applied subset improved, but the full corpus baseline got materially worse.
- Relative to the March 14 authoritative corpus result (`1.046x`), this rerun is not competitive and should **not** replace the authority.
