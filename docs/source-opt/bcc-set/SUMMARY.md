# bcc/set source-opt summary

App: `bcc/set`

Status: phase2-complete

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

Phase2 attempts:

| Attempt | Status | Result path | Primary metric | Notes |
| --- | --- | --- | ---: | --- |
| 1 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_020646_300498` | `stress_ng_sum_bogo_ops_s` mean=718235, samples `719939, 713743, 721022`, +1.09% vs clean baseline | Stacks first-round `syscount` early return with `capable` fexit rewrite; gate passed; source restored after run. |
| 2 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_023049_621850` | `stress_ng_sum_bogo_ops_s` mean=717722, samples `716964, 718507, 717694`, +1.02% vs clean baseline | Stacks attempt 1 base with `tcpconnect` fexit rewrite; gate passed; source restored after run; not selected as the next stacked base because it is below attempt 1. |
| 3 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_025631_917158` | `stress_ng_sum_bogo_ops_s` mean=724628, samples `727466, 720947, 725471`, +1.99% vs clean baseline | Stacks attempt 1 base and rewrites `syscount` from formatted tracepoints to raw tracepoints; gate passed; source restored after run; selected as the next stacked base. |
| 4 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_031853_909472` | `stress_ng_sum_bogo_ops_s` mean=715349, samples `713487, 715830, 716731`, +0.69% vs clean baseline | Stacks attempt 3 base and specializes the `syscount -L` exit path with a dedicated `raw_tracepoint/sys_exit` program; gate passed; source restored after run; not selected as the next stacked base because it is below attempt 3. |
| 5 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_034309_094312` | `stress_ng_sum_bogo_ops_s` mean=729628, samples `729898, 726762, 732224`, +2.70% vs clean baseline | Stacks attempt 3 base with the `tcpconnect` fexit rewrite; gate passed; source restored after run; selected as bcc/set phase2 best. |

Phase2 gate:

- [x] Five phase2 attempts recorded.
- [x] Phase2 attempt 1 source tree returned to clean state after run.
- [x] Phase2 attempt 2 source tree returned to clean state after run.
- [x] Phase2 attempt 3 source tree returned to clean state after run.
- [x] Phase2 attempt 4 source tree returned to clean state after run.
- [x] Phase2 attempt 5 source tree returned to clean state after run.
