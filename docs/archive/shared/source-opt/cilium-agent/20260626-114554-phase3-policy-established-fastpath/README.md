# cilium/agent phase3 attempt: policy established fastpath

Status: completed-not-stacked

Base:

- Stacks `20260626-105321-phase3-reserved-identity-cold`, which itself stacks
  `20260625-090437-tail-ipv4-to-endpoint-revalidate-unlikely`.

Change:

- Keep the current Cilium phase3 base in `tail_ipv4_to_endpoint()`.
- In IPv4 egress and ingress policy paths, wrap policy verdict notification and
  non-OK verdict handling in an explicit cold block:
  `verdict != CTX_ACT_OK || CT status != CT_ESTABLISHED`.
- Preserve all `send_policy_verdict_notify()` calls for CT_NEW and drop/proxy
  cases; no policy, CT, event, map, or tail-call behavior is removed.

Rationale:

- The endpoint pktgen workload runs for long enough that established allow
  traffic should dominate after flow warmup.
- Making the established+allow path visually direct is a source-level attempt to
  reduce hot-path branch clutter without changing the event semantics for
  non-established or denied traffic.

Risk:

- The workload uses `flows=65535` with a full destination-port range, so CT_NEW
  and policy verdict notification are not purely cold.
- Cilium's C/BPF compiler may already produce similar code for the original
  branch shape.

Result:

- Formal run passed correctness with `post_rejit=null` and
  `rejit_result.mode="skip_rejit_all"`.
- `pktgen_total_pps` samples: `1579206, 1566724, 1563584`; mean=1569838.
- This is +5.49% vs the clean baseline mean 1488103, but -6.15% vs the current
  Cilium phase3 base mean 1672664.
- The patch is not stacked. The current Cilium phase3 base remains
  `20260626-105321-phase3-reserved-identity-cold`.

Artifacts:

- `source.diff`: complete cumulative source patch used for the formal run.
- `candidate-only.diff`: policy established fast-path patch relative to the
  current Cilium phase3 base.
- `build.log` / `candidate-build.log`: pre-run build logs.
- `restore-build.log`: Cilium x86 rebuild log after reversing the patch.
- `run-command.sh`: exact formal benchmark command.
- `run.log`: formal benchmark log.
- `result-paths.txt`: formal result path.
- `correctness.md`: correctness gate and raw workload samples.
- `diagnostics.md`: pre-run diagnostic caveats and source-level decision.
