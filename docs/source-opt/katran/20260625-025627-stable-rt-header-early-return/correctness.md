# katran stable-rt-header-early-return correctness

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
- Coverage: passed by source inspection; non-stable routing packets still
  return without setting `is_stable_rt_pkt`, and stable routing packets still
  run the same bounds check before reading `connection_id`.
- Source restore: passed; `patch -p1 -R < source.diff` completed and
  `git -C vendor/repos/katran status --short` is empty.

Disk after run:

- `/dev/nvme0n1p2 915G 693G 176G 80% /`
