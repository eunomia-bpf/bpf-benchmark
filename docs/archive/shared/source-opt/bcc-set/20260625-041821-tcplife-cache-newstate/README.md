# bcc/set source-opt attempt: tcplife-cache-newstate

- Time: 2026-06-25 04:18:21
- App: `bcc/set`
- Status: accepted-for-analysis
- Source files: `vendor/repos/bcc/libbpf-tools/tcplife.bpf.c`
- Hypothesis: `tcplife` can read `args->newstate` once per
  `inet_sock_set_state` tracepoint invocation and reuse it for the birth,
  identity, and close checks, avoiding repeated CO-RE field reads.
- Expected hot path: `inet_sock_set_state` tracepoint handler.
- Correctness argument: tracepoint payload fields are stable during a single
  handler invocation. The cached `newstate` value feeds the same comparisons as
  before. Maps, event payload layout, attach point, filters, and cleanup logic
  are unchanged.
- Build command: covered by the documented single-app `make corpus` run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_112427_430171`
- Follow-up: if accepted, compare raw workload payload externally against the
  clean-source baseline.

Result:

- Build/provenance: formal `make corpus` rebuilt `tcplife.bpf.o`, regenerated
  `tcplife.skel.h`, rebuilt `tcplife`, and copied updated BCC binaries into the
  runtime image. `tcpconnect` also rebuilt due to timestamp state, but the saved
  source patch only modifies `tcplife.bpf.c`.
- Gate: suite/app `status=ok`, `error=""`, 3 workload samples all returned 0,
  `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`.
- Disk after run: `/dev/nvme0n1p2 915G 699G 171G 81% /`; no Docker image
  cleanup needed.
