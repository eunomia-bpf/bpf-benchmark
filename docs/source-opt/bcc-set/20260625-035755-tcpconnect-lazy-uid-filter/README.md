# bcc/set source-opt attempt: tcpconnect-lazy-uid-filter

- Time: 2026-06-25 03:57:55
- App: `bcc/set`
- Status: accepted-for-analysis
- Source files: `vendor/repos/bcc/libbpf-tools/tcpconnect.bpf.c`
- Hypothesis: `tcpconnect` entry path only needs
  `bpf_get_current_uid_gid()` when `filter_uid` is configured. Moving the helper
  call inside that branch removes one helper from the default no-UID-filter path
  without changing configured UID-filter behavior.
- Expected hot path: `enter_tcp_connect()` for `tcp_v4_connect` and
  `tcp_v6_connect` kprobes.
- Correctness argument: the same `filter_uid != -1` predicate controls whether
  UID filtering is active. When inactive, both old and new code allow the event;
  when active, both compare the current UID against `filter_uid`. The sockets
  map, count maps, event payloads, attach points, and exit path are unchanged.
- Build command: covered by the documented single-app `make corpus` run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_110418_916430`
- Follow-up: if accepted, compare raw workload payload externally against the
  clean-source baseline.

Result:

- Build/provenance: formal `make corpus` rebuilt `tcpconnect.bpf.o`,
  regenerated `tcpconnect.skel.h`, rebuilt `tcpconnect`, and copied updated
  BCC binaries into the runtime image. `opensnoop` also rebuilt due to timestamp
  state, but the saved source patch only modifies `tcpconnect.bpf.c`.
- Gate: suite/app `status=ok`, `error=""`, 3 workload samples all returned 0,
  `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`.
- Disk after run: `/dev/nvme0n1p2 915G 697G 172G 81% /`; no Docker image
  cleanup needed.
