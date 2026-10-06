# cilium/agent phase3 attempt: reserved identity cold branch

Status: accepted-for-analysis; selected as current Cilium phase3 base

Base:

- Stacks `20260625-090437-tail-ipv4-to-endpoint-revalidate-unlikely`.

Change:

- Keep both `tail_ipv4_to_endpoint()` `revalidate_data()` failure checks marked
  with Cilium's existing `unlikely()` macro from the current best base.
- Mark the `identity_is_reserved(src_sec_identity)` branch in IPv4
  `tail_ipv4_to_endpoint()` as unlikely.
- Do not change map layouts, tail-call keys, policy semantics, packet bounds
  checks, or endpoint lookup behavior.

Rationale:

- The benchmark drives bidirectional endpoint-to-endpoint UDP traffic through the
  Cilium endpoint datapath.
- Non-reserved endpoint identities should be the hot path for this workload.
  The reserved-identity branch performs a remote endpoint lookup only for proxy
  or reserved-source traffic, so moving it cold may improve hot-path layout
  without removing any check.

Risk:

- This is still a branch-layout hint rather than a reduction in actual helper or
  map work on the dominant path.
- The candidate slightly increases `tail_ipv4_to_endpoint()` object size, so any
  win is expected to be small and noise-sensitive.

Result:

- Formal run passed correctness with `post_rejit=null` and
  `rejit_result.mode="skip_rejit_all"`.
- `pktgen_total_pps` samples: `1683410, 1662935, 1671646`; mean=1672664.
- This is +12.40% vs the clean baseline mean 1488103, and +0.03% vs the
  previous Cilium best mean 1672124.
- The patch is selected as the current Cilium phase3 base because it is a small
  positive result over the previous best, but the margin is tiny. The next
  Cilium attempts should switch to larger hot-path work reduction, such as
  avoiding unnecessary map/helper work under benchmark-valid invariants, not
  just adding more cold-branch annotations.

Artifacts:

- `source.diff`: complete source patch used for the formal run.
- `build.log`: Cilium x86 rebuild log before the benchmark.
- `restore-build.log`: Cilium x86 rebuild log after reversing the patch.
- `base-*.txt` / `candidate-*.txt`: symbol and section diagnostics.
- `base-tail.objdump.txt` / `candidate-tail.objdump.txt`: disassembly for
  `bpf_lxc.o`.
- `tail-objdump.diff`: candidate-vs-base disassembly diff.
- `run-command.sh`: exact formal benchmark command.
- `result-paths.txt`: formal result path.
- `correctness.md`: correctness gate and raw workload samples.
