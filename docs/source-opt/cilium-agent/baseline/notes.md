# cilium/agent clean-source baseline

- Time: 2026-06-25 07:24:20 PDT
- Source state: no Cilium source edits applied.
- Command: see `run-command.sh`.
- Expected workload: `cilium_endpoint_pktgen`.
- Expected ReJIT behavior: `SKIP_REJIT=all`, so `post_rejit=null` and
  `rejit_result.mode="skip_rejit_all"`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_143038_806522`
- Gate: suite `status=ok`; app `status=ok`; `error=""`; 3 workload samples;
  each sample has forward/reverse pktgen component returncodes `[0, 0]`;
  `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`.
- Disk after run: `/dev/nvme0n1p2 915G 712G 158G 82% /`.
