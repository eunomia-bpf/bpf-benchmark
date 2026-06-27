# Diagnostics

Current base before this attempt:

- `docs/source-opt/cilium-agent/20260626-120930-phase3-cil-to-container-error-unlikely-stack/source.diff`
- Mean `1686212` pktgen_total_pps, `+13.31%` vs clean baseline.

Candidate stacked patch:

- Reused `docs/source-opt/cilium-agent/20260625-082528-cil-lxc-policy-error-unlikely/source.diff`.
- That first-round attempt alone measured mean `1509617`, `+1.45%` vs clean baseline.
- The candidate marks `cil_lxc_policy()` invalid ethertype and failed L3 header pull branches as `unlikely()`.

Why this direction:

- Attempt 4 showed that stacking a small, independently positive datapath error-path layout hint could improve over the phase3 base.
- Attempts 2-3 showed that larger policy verdict/event preparation rewrites regress this workload, so this attempt stayed with small branch-layout-only changes.
- The final diff is still limited to `bpf/bpf_lxc.c` and does not alter policy, map lookup, event payload, or tail-call behavior.

Operational checks:

- Pre-run build passed: `build.log`.
- Formal result: `corpus/results/x86_kvm_corpus_20260626_193753_200824`.
- Post-run source restore used `patch -d vendor/repos/cilium -p1 -R < source.diff`.
- Post-restore build passed: `restore-build.log`.
- Post-restore `vendor/repos/cilium` status was clean and `git -C vendor/repos/cilium diff -- bpf/bpf_lxc.c` was empty.
- Disk after run: `/dev/nvme0n1p2 915G 757G 112G 88% /`.
- Docker after run: images `55 / 57.87GB`, containers `26 / 29.73GB`, build cache `80.31GB`; no cleanup performed.
