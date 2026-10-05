# tracee/monitor source-opt attempt: socket-dup-late-args

- Time: 2026-06-25 06:42:12
- App: `tracee/monitor`
- Status: accepted-for-analysis
- Source files: `vendor/repos/tracee/pkg/ebpf/c/tracee.bpf.c`
- Hypothesis: `send_socket_dup()` can defer writing `oldfd` and `newfd` into
  the submit buffer until after the fd is confirmed to be a supported socket
  family, avoiding unused buffer writes on non-submitted paths.
- Expected hot path: socket dup tail handler for `dup`, `dup2`, and `dup3`.
- Correctness argument: unsupported fd/family paths do not submit an event, so
  their previous buffer writes were not visible. For supported socket families,
  the patch still writes fields 0 and 1 before field 2 and preserves the same
  `SOCKET_DUP` event payload, map usage, attach points, and submit call.
- Build command: covered by the documented single-app `make corpus` run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_134931_275984`
- Result gate: suite `status=ok`; app `status=ok`; `error=""`; 3 workload
  samples all returned 0; `post_rejit=null`;
  `rejit_result.mode="skip_rejit_all"`.
- Follow-up: compare raw workload payload externally against the clean-source
  baseline.
