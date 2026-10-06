# bcc/set source-opt summary

App: `bcc/set`

Status: phase3-complete; current best is phase3 attempt 4

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

Phase3 attempts:

| Attempt | Status | Result path | Primary metric | Notes |
| --- | --- | --- | ---: | --- |
| 1 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_135003_717963` | `stress_ng_sum_bogo_ops_s` mean=730977, samples `730828, 727856, 734246`, +2.89% vs clean baseline | Stacks phase2 best and adds unlikely branch layout hints to default-cold `tcpconnect` filter/count branches; gate passed; selected as current bcc/set phase3 base. |
| 2 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_141358_076518` | `stress_ng_sum_bogo_ops_s` mean=733113, samples `733995, 732654, 732689`, +3.19% vs clean baseline | Stacks phase3 attempt 1 and adds a no-filter `syscount` enter fast path plus exit branch-layout hints; gate passed; selected as current bcc/set phase3 base. |
| 3 | completed-not-stacked | `corpus/results/x86_kvm_corpus_20260626_143534_405266` | `stress_ng_sum_bogo_ops_s` mean=727184, samples `725965, 726577, 729010`, +2.35% vs clean baseline | Stacks phase3 attempt 2 and adds `capable` default-cold branch layout hints; gate passed but regressed vs attempt 2, so do not stack. |
| 4 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_150154_266900` | `stress_ng_sum_bogo_ops_s` mean=794393, samples `794399, 794426, 794353`, +11.81% vs clean baseline | Stacks phase3 attempt 2 and changes `syscount`'s private latency `start` map from tid hash to task local storage; gate passed; selected as current bcc/set phase3 base. |
| 5 | completed-not-stacked | `corpus/results/x86_kvm_corpus_20260626_152354_967827` | `stress_ng_sum_bogo_ops_s` mean=789683, samples `790657, 788288, 790104`, +11.15% vs clean baseline | Stacks phase3 attempt 4 and adds a default-event fast path to `tcpconnect`; gate passed but regressed by 0.59% vs attempt 4, so do not stack. |

Phase3 gate:

- [x] Phase3 attempt 1 recorded.
- [x] Phase3 attempt 1 source tree returned to clean state after run.
- [x] Phase3 attempt 2 recorded.
- [x] Phase3 attempt 2 source tree returned to clean state after run.
- [x] Phase3 attempt 3 recorded.
- [x] Phase3 attempt 3 source tree returned to clean state after run.
- [x] Phase3 attempt 4 recorded.
- [x] Phase3 attempt 4 source tree returned to clean state after run.
- [x] Phase3 attempt 5 recorded.
- [x] Phase3 attempt 5 source tree returned to clean state after run.

Phase3 outcome:

- Best bcc/set phase3 result remains attempt 4:
  `stress_ng_sum_bogo_ops_s` mean=`794393`, `+11.81%` vs clean baseline.
- Attempt 5 confirmed that duplicating the default `tcpconnect` event path is
  not worth stacking on top of the task-storage `syscount` base.
