# Correctness

Status: passed

Gates to check after `make corpus`:

- suite status is `ok`
- app status is `ok`
- app error string is empty
- `post_rejit` is `null`
- `rejit_result.mode` is `skip_rejit_all`
- `rejit_result.status` is `skipped`
- three baseline workload samples are present
- all workload component return codes are 0
- pktgen stdout contains total `pps` lines for each sample

No map ABI, packet metadata ABI, tail-call layout, or runner/workload setting is
intentionally changed.

Checked result:

- Result path: `corpus/results/x86_kvm_corpus_20260626_011245_701549`
- App result: `corpus/results/x86_kvm_corpus_20260626_011245_701549/details/apps/katran.json`
- suite status: `ok`
- app status: `ok`
- app error string: `""`
- `post_rejit`: `null`
- `rejit_result`: `{"mode": "skip_rejit_all", "status": "skipped"}`
- baseline workload samples: 3
- component return codes: all 0
- pktgen total pps samples: `3272779, 3268211, 3286301`
