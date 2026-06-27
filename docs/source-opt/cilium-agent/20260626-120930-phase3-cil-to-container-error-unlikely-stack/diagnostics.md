# Diagnostics

Current base before this attempt:

- `docs/source-opt/cilium-agent/20260626-105321-phase3-reserved-identity-cold/source.diff`
- Mean `1672664` pktgen_total_pps, `+12.40%` vs clean baseline.

Candidate stacked patch:

- Reused `docs/source-opt/cilium-agent/20260625-084516-cil-to-container-error-unlikely/source.diff`.
- That first-round attempt alone measured mean `1510065`, `+1.48%` vs clean baseline.
- The candidate marks `cil_to_container()` invalid ethertype and failed L3 header pull branches as `unlikely()`.

Why this direction:

- Cilium phase3 attempts 2-3 moved work in policy verdict/event handling and both regressed by about 6% relative to the phase3 base.
- This attempt pivots back to a smaller datapath branch-layout change that had already shown an independent positive signal.
- The patch is limited to existing error branches and does not alter policy, map lookup, event payload, or tail-call behavior.

Operational checks:

- Pre-run build passed: `build.log`.
- Formal result: `corpus/results/x86_kvm_corpus_20260626_191637_695574`.
- Post-run source restore used `patch -d vendor/repos/cilium -p1 -R < source.diff`.
- Post-restore build passed: `restore-build.log`.
- Post-restore `vendor/repos/cilium` status was clean and `git -C vendor/repos/cilium diff -- bpf/bpf_lxc.c` was empty.
- Disk after run: `/dev/nvme0n1p2 915G 756G 113G 88% /`.
- Docker after run: images `54 / 57.28GB`, containers `26 / 29.73GB`, build cache `79.72GB`; no cleanup performed.
