# bcc/set source-opt summary

App: `bcc/set`

Status: complete

Start state:

- Started: 2026-06-25
- Initial worktree status: existing source-opt/katran docs and corpus result
  files present; `vendor/repos/bcc` was clean.
- Initial disk: `/dev/nvme0n1p2 915G 693G 176G 80% /`
- Benchmark contract: single-app `make corpus`, `SKIP_REJIT=all`,
  `SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1`,
  `BPFREJIT_CORPUS_BPF_STATS=0`
- BCC tools: `capable`, `biosnoop`, `vfsstat`, `opensnoop`, `syscount`,
  `tcpconnect`, `tcplife`, `runqlat`

Baseline:

- Status: accepted
- Result path: `corpus/results/x86_kvm_corpus_20260625_102432_554290`
- App result: `corpus/results/x86_kvm_corpus_20260625_102432_554290/details/apps/bcc__set.json`
- Gate: suite `status=ok`; app `status=ok`; `error=""`; 3 workload
  samples all returned 0; `post_rejit=null`;
  `rejit_result.mode="skip_rejit_all"`; disk after run:
  `/dev/nvme0n1p2 915G 695G 175G 80% /`.

Attempts:

| Attempt | Status | Result path | Notes |
| --- | --- | --- | --- |
| 1 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_104426_414018` | `opensnoop` reuses one `bpf_get_current_pid_tgid()` result in `trace_exit()`; gate passed; source restored after run. |
| 2 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_110418_916430` | `tcpconnect` calls `bpf_get_current_uid_gid()` only when UID filtering is active; gate passed; source restored after run. |
| 3 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_112427_430171` | `tcplife` caches `args->newstate` for repeated state checks; gate passed; source restored after run. |
| 4 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_114437_519205` | `syscount` handles interrupt `args->id == -1` before `bpf_get_current_pid_tgid()` in `sys_exit`; gate passed; source restored after run. |
| 5 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_120517_651286` | `runqlat` skips reading `prev->tgid` when `prev->pid == 0`, matching the existing `trace_enqueue()` early return; gate passed; source restored after run. |

Completion gate:

- [x] Clean-source baseline result recorded.
- [x] Five independent source optimization attempts recorded.
- [x] Every accepted attempt has `source.diff`, command, result path, and correctness notes.
- [x] bcc source tree returned to attempt-start state after each attempt.
