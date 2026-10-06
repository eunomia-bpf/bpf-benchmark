# bcc/set source-opt attempt: opensnoop-reuse-pidtgid

- Time: 2026-06-25 03:38:14
- App: `bcc/set`
- Status: accepted-for-analysis
- Source files: `vendor/repos/bcc/libbpf-tools/opensnoop.bpf.c`
- Hypothesis: `opensnoop` exit path can reuse the `bpf_get_current_pid_tgid()`
  value already needed for the start-map lookup, removing one helper call while
  preserving the emitted event's tgid/pid semantics.
- Expected hot path: `trace_exit()` for `sys_exit_open` and `sys_exit_openat`.
- Correctness argument: the tracepoint handler runs in one task context, so the
  low 32 bits used as the start-map key and the high 32 bits emitted as
  `event.pid` come from the same helper result. The start map key type, event
  payload layout, attach points, filters, stack collection, and perf output are
  unchanged.
- Build command: covered by the documented single-app `make corpus` run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_104426_414018`
- Follow-up: if accepted, compare raw workload payload externally against the
  clean-source baseline.

Result:

- Build/provenance: formal `make corpus` rebuilt `opensnoop.bpf.o`,
  regenerated `opensnoop.skel.h`, rebuilt `opensnoop`, and copied the updated
  BCC binaries into the runtime image.
- Gate: suite/app `status=ok`, `error=""`, 3 workload samples all returned 0,
  `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`.
- Disk after run: `/dev/nvme0n1p2 915G 696G 173G 81% /`; no Docker image
  cleanup needed.
