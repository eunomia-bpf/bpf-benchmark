# Diagnostics

Pre-run status:

- `vendor/repos/cilium` was clean after phase3 attempt 2 restore.
- Applied `20260626-105321-phase3-reserved-identity-cold` as the current Cilium
  phase3 base.
- `make -C vendor cilium-x86` passed before the formal run.

Source-level observation:

- The candidate keeps the original semantics:
  - established+allow traffic skips policy verdict notification as before;
  - CT_NEW allow traffic still emits policy verdict notification;
  - non-OK verdicts still emit notification and return the verdict;
  - egress deny response tail-call handling is preserved.
- The workload uses `flows=65535` and `udp_dst_min=1` /
  `udp_dst_max=65535`, so CT_NEW is not guaranteed to be rare. This was the
  main risk before running.

Offline object caveat:

- The local `bpf_lxc.o` diagnostics showed no useful difference between the
  copied base and candidate artifacts:
  - `tc/tail` section: `0x5ddb8` for both.
  - key symbols such as `tail_handle_ipv4_cont`, `tail_ipv4_to_endpoint`, and
    `tail_ipv4_policy` had unchanged sizes in that local object.
- This diagnostic is not authoritative for the formal result because
  `make -C vendor cilium-x86` rebuilds the Go agent and does not force a fresh
  Cilium datapath object build. The authoritative test remains the
  `make corpus` run with the edited `vendor/repos/cilium/bpf/` source copied
  into the runtime image.

Post-run observation:

- Formal samples were `1579206, 1566724, 1563584`; mean=1569838.
- The candidate stayed above clean baseline by 5.49%, but regressed by 6.15%
  vs the current Cilium phase3 base. Do not stack it.
