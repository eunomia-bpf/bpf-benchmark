# Correctness

Formal run status: passed

Result path:
`corpus/results/x86_kvm_corpus_20260626_002120_778242`

Required gates:
- App result `status` must be `ok`.
- App `error` must be empty.
- `post_rejit` must be `null`.
- `rejit_result.mode` must be `skip_rejit_all`.
- `rejit_result.status` must be `skipped`.
- Baseline workloads must contain 3 pktgen samples.
- No workload component may report a nonzero exit code.

Observed gates:
- App result `status`: `ok`.
- App `error`: empty string.
- `post_rejit`: `null`.
- `rejit_result`: `{"mode": "skip_rejit_all", "status": "skipped"}`.
- Baseline workloads: 3.
- Component exit codes: `[0, 0, 0, 0]` for each sample.

Source-level reasoning:
- The `proto_match` change turns an apparent typo into the same comparison
  pattern already used for VIP address and port.
- The `*dst` guard only checks UDP flow-migration down-real maps when a real
  has already been selected; if there is no selected real, there is no down
  real to invalidate and the following consistent-hash fallback remains
  responsible for selection.
