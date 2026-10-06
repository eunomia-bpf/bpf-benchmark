# katran clean-source baseline correctness

Status: accepted-for-analysis

Checks:

- Build: passed through `make corpus` dependencies.
- Load: real `katran_server_grpc` loaded `balancer.bpf.o` through the katran runner.
- Workload: 3 `xdp_pktgen` samples returned 0.
- Result schema: app `status=ok`, `error=""`, `baseline.workloads[]`
  present, `post_rejit=null`.
- ReJIT disabled: `rejit_result.mode="skip_rejit_all"`.
- ABI/Coverage: no source changes in the baseline.

This baseline is the clean-source reference for later source-only attempts.
