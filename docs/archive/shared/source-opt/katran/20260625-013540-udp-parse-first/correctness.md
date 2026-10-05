# katran udp-parse-first correctness

Status: accepted-for-analysis

Checks:

- Build: passed through `make corpus`; katran `balancer.c` was rebuilt into
  `balancer.bpf.o`.
- Load: passed; real katran runner started and loaded the BPF object.
- Workload: passed; 3 `xdp_pktgen` samples returned 0.
- Result schema: passed; app `status=ok`, `error=""`, `baseline.workloads[]`
  present, `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`.
- ABI: passed by source inspection; no map layout, event payload, tail-call
  key, attach point, or helper ABI changed.
- Coverage: passed by source inspection; TCP, UDP, GUE, and fallback paths
  remain present, only the TCP/UDP branch order changed.
- Source restore: passed; `patch -p1 -R < source.diff` completed and
  `git -C vendor/repos/katran status --short` is empty.

Disk after run:

- `/dev/nvme0n1p2 915G 687G 182G 80% /`
