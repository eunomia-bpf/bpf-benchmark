# tracee/monitor source-opt attempt: socket-dup-unix-else

- Time: 2026-06-25 07:02:58
- App: `tracee/monitor`
- Status: accepted-for-analysis
- Source files: `vendor/repos/tracee/pkg/ebpf/c/tracee.bpf.c`
- Hypothesis: after `send_socket_dup()` rejects every family except `AF_INET`,
  `AF_INET6`, and `AF_UNIX`, the final branch can be a plain `else` instead of
  re-checking `family == AF_UNIX`.
- Expected hot path: socket dup tail handler for `dup`, `dup2`, and `dup3`.
- Correctness argument: the preceding guard returns for every unsupported
  family, and the two earlier branches handle `AF_INET` and `AF_INET6`.
  Therefore the final branch is reachable only for `AF_UNIX`. The patch does
  not change event fields, map layout, attach points, or submit behavior.
- Build command: covered by the documented single-app `make corpus` run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_141005_857825`
- Result gate: suite `status=ok`; app `status=ok`; `error=""`; 3 workload
  samples all returned 0; `post_rejit=null`;
  `rejit_result.mode="skip_rejit_all"`; disk after run:
  `/dev/nvme0n1p2 915G 711G 158G 82% /`.
- Follow-up: if accepted, compare raw workload payload externally against the
  clean-source baseline.
