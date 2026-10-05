# cilium/agent phase3 attempt: lazy policy verdict payload

Status: completed-not-stacked

Base:

- Stacks `20260626-105321-phase3-reserved-identity-cold`, which itself stacks
  `20260625-090437-tail-ipv4-to-endpoint-revalidate-unlikely`.

Change:

- Keep the current Cilium phase3 base in `bpf/bpf_lxc.c`.
- In `send_policy_verdict_notify()`, move `ctx_full_len(ctx)`, `cap_len`, and
  rate-limit key/settings initialization after the early monitor-filter check.
- Keep policy verdict payload layout, event type, return path, map layouts, and
  rate-limit behavior unchanged.

Rationale:

- The benchmark runs `cilium-agent` with monitor output disabled in the runner
  workload path, but policy verdict notification code is still compiled into the
  datapath.
- Length calculation and rate-limit struct preparation are pure setup work for
  the event path. Deferring them until after the filter should reduce cold-event
  preparation work without changing emitted events when the filter allows one.

Risk:

- The compiler may already keep most of this work off the dominant path.
- The policy-verdict helper is not necessarily hot in the endpoint pktgen path,
  so smaller code size does not guarantee workload throughput improvement.

Result:

- Formal run passed correctness with `post_rejit=null` and
  `rejit_result.mode="skip_rejit_all"`.
- `pktgen_total_pps` samples: `1554963, 1566899, 1596952`; mean=1572938.
- This is +5.70% vs the clean baseline mean 1488103, but -5.96% vs the current
  Cilium phase3 base mean 1672664.
- The patch is not stacked. The current Cilium phase3 base remains
  `20260626-105321-phase3-reserved-identity-cold`.

Artifacts:

- `source.diff`: complete cumulative source patch used for the formal run.
- `candidate-only.diff`: policy verdict payload deferral patch relative to the
  current Cilium phase3 base.
- `build.log`: Cilium x86 rebuild log before the benchmark.
- `restore-build.log`: Cilium x86 rebuild log after reversing the patch.
- `base-*.txt` / `candidate-*.txt`: symbol and section diagnostics.
- `base-tail.objdump.txt` / `candidate-tail.objdump.txt`: disassembly for
  `bpf_lxc.o`.
- `tail-objdump.diff`: candidate-vs-base disassembly diff.
- `run-command.sh`: exact formal benchmark command.
- `result-paths.txt`: formal result path.
- `correctness.md`: correctness gate and raw workload samples.
