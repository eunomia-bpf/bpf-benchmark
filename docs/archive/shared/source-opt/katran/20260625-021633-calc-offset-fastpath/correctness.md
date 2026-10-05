# katran calc-offset-fastpath correctness

Status: accepted-for-analysis

Checks:

- Build: passed through `make corpus`; katran `pckt_parsing.h` change rebuilt
  dependent katran BPF objects.
- Load: passed; real katran runner started and loaded the BPF objects.
- Workload: passed; 3 `xdp_pktgen` samples returned 0.
- Result schema: passed; suite/app `status=ok`, `error=""`,
  `baseline.workloads[]` present, `post_rejit=null`,
  `rejit_result.mode="skip_rejit_all"`.
- ABI: passed by source inspection; no map layout, event payload, tail-call
  key, attach point, or helper ABI changed.
- Coverage: passed by source inspection; non-ICMP IPv4/IPv6 offsets are
  unchanged and ICMP offsets use the existing equivalent constants.
- Source restore: passed; `patch -p1 -R < source.diff` completed and
  `git -C vendor/repos/katran status --short` is empty.

Disk after run:

- `/dev/nvme0n1p2 915G 691G 179G 80% /`
