# Correctness

Status: passed

Formal run:

- Result path: `corpus/results/x86_kvm_corpus_20260626_004646_185930`
- suite/app status: `ok`
- app error string: `""`
- `post_rejit`: `null`
- `rejit_result`: `{"mode": "skip_rejit_all", "status": "skipped"}`
- baseline workload samples: 3
- workload component return codes: twelve `0` values
- pktgen total pps samples: `3390361, 3336180, 3320175`
- pktgen error samples: `329745738, 374701196, 304005090`

No map ABI, packet metadata ABI, tail-call layout, or runner/workload setting is
intentionally changed.
