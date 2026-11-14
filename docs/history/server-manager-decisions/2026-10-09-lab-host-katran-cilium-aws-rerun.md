# Katran/Cilium native rerun driven from the lab host, measured on AWS

- Date: 2026-10-09
- Scope: host processes on `lab` (user `yunwei37`) and AWS EC2 in us-east-1 (profile `codex-ec2`)
- Status: deployed; the AWS phase was stopped at its one-hour budget, the Cilium measurement finished on `lab` on 2026-10-10 and the paused workloads were resumed

## User request and approval

> “能不能想办法直接在 lab 上面, ssh 过去测试, 不需要在容器里面, lab 上面有 aws 的访问 token 可以复用”

> “是不是应该本地都构建好, 线上加起来跑不超过 1h?”

> “然后主机上的 clilum 也需要修好并且去跑, 最好代码和功能都要一样”

> “去做, 我授权了” (for starting an unattended Codex run on `lab` that uses the AWS access configured there)

> “先都在 lab 上面吧性能测试好啊”

> “不要限制本地虚拟机?”

> “不是禁止在 aws 上面开发吗”

> “能不能多个 ai 并行去做去解决问题” … “去做, 快去, 还可以再开一两个, 不要多个 workspace, 就一个 workspace”

> “能不能顺便停掉 lab 上面别的工作负载多测试几次” … “去做啊”

> “继续做, profile 和性能数据做好之后 commit push 并且恢复所有的集群里面的任务正常运行”

This is an explicit exception to AGENTS.md §7 ("lab 上面安装测试都要走 k8s") for this task.

## Defaults and decisions

| ID | Setting | Current default | Proposed value | Reason | Risk | Decision |
| --- | --- | --- | --- | --- | --- | --- |
| K1 | Where the rerun builds and runs | tests on `lab` go through K8s | host processes on `lab` in a fresh clone `~/workspace/bpf-benchmark-rerun-20261009` | the operator asked for a direct host run | host load and reboot exposure on `lab` | approved (“去做, 我授权了”) |
| K2 | AWS use | none | fixed-performance x86-64 instances, at most about one hour in total | timing on dedicated hardware | cost; debugging on AWS | approved, then stopped at the budget (see “Stop”) |
| K3 | Lab-only measurement | no benchmarks on `lab` | functional gates and timing on `lab`, guests pinned to P-cores 0-7, no AWS | AWS was spent on debugging | `lab` may reboot with guests running | approved (“先都在 lab 上面吧性能测试好啊”) |
| K4 | Local KVM guests | one short guest at a time | unlimited | faster fixing | more reboot exposure | approved (“不要限制本地虚拟机?”) |
| K5 | Parallel agents | one Codex run | three Codex runs in the same clone with a coordination file | faster Cilium work | interference between agents | approved (“去做, 快去 … 就一个 workspace”) |
| K6 | Other `lab` workloads during timing | running | SIGSTOP of gpu-smt Lean preparation, `telegram-desktop` and Xvfb, the bpf-benchmark-supervisor `omp`; three CronJobs suspended | quieter host for timing | paused work loses time; a Pod restart loses a paused process | approved (“去做啊”) |

## Evidence and implementation

### What runs where

- `lab` host: a fresh clone `~/workspace/bpf-benchmark-rerun-20261009` (the existing `~/workspace/bpf-benchmark` checkout is not touched), kernel/module/program builds, and the fix that makes Cilium's native-execution arm attach and forward like the kernel JIT arm. No benchmarks run on `lab`; at most short single functional guests while debugging, because `lab` has rebooted repeatedly while guests ran (see `incident-logs/2026-10-09-lab-reboot-during-cilium-native-rerun.md`).
- AWS: fixed-performance x86-64 instances (for example `c7i.2xlarge`), about one hour per session, Katran first and Cilium after its native arm is validated; every instance is terminated afterwards and its type, AMI, time and cost are recorded with the results.
- Run directory and logs: `lab:~/workspace/codex-runs/lab-aws-20261009/`. Results go to bpf-benchmark `corpus/results/`.

### Stop (2026-10-09, about 19:50 PDT)

Claude stopped the run because AWS use had passed the one-hour budget quoted above with no accepted result.

- AWS use: CloudTrail shows eight `RunInstances` calls from 18:09 to 19:39 PDT, each a single `c7i.2xlarge` that ran 7 to 16 minutes, then two more launches (`katran-final-20261009i`, `-j`) that were cut off within a minute or two of starting when the run was stopped. Total about 75 instance-minutes. No instance is left running (`describe-instances` with state pending/running/stopping/stopped is empty).
- Why no result: every Katran session failed a functional or accounting gate that the run itself had added: incomplete backend counts after 60 s, veth ring drops on the peer, receiver skb path capped below Katran's packet rate, and finally a devmap update issued from the wrong network namespace. Each fix was committed locally and needed a new instance, because staging the 2 GB runner image takes most of each session. Cilium was not measured in this run.
- What was stopped: `run.sh`, its `codex exec` child and the `run-series.sh`/`make` children, and instance `i-0a755015d39e729ba` (terminated). `exit` in the run directory is set to 130.
- Left in place: eight unpushed commits in `lab:~/workspace/bpf-benchmark-rerun-20261009` (Katran test topology and counters, native Cilium data symbol layout; HEAD `6781f6809`) and ten `corpus/results/aws_x86_corpus_20261010_*` directories, none accepted as results.

### Lab-only phase (started 2026-10-10 03:10 UTC)

- A new Codex run (`lab:~/workspace/codex-runs/lab-local-20261009/`, session 01a123ca-05f7-7c12-96dd-e7bcdf63af3b) continues in the same clone from `6781f6809`: fix the local KVM guest's runtime container start, pass the Katran and Cilium functional gates (JIT, kinsn, whole-program native; counters and attachments must match) in local guests, then time both apps on `lab` with the guest pinned to P-cores 0-7, one guest at a time.
- No AWS: `run.sh` points the AWS CLI at nonexistent credential files, and the watcher checks that no EC2 instance is pending or running.
- Local KVM guests are not limited. This accepts that `lab` may reboot again and take its Coder Workspace pods down with it. After a reboot the watcher relaunches `run.sh`, which resumes the same Codex session; each start is logged with its boot id in `starts.log`.

### Three agents in one clone (from 2026-10-10 04:31 UTC)

- Three Codex runs share the lab clone `~/workspace/bpf-benchmark-rerun-20261009`, with no other clone or Workspace: agent 1 (`lab-local-20261009`) leads the Cilium gates, merges origin/master (to pick up the scratch-free kinsn modules) and pushes; agent 2 (`lab-ai2-20261009`) builds and runs the Cilium profile; agent 3 (`lab-ai3-20261009`) checks that the micro suite still loads with the current kinsn modules and measures verifier work.
- Rules are in `~/workspace/codex-runs/RULES.md` and status lines in `~/workspace/codex-runs/COORDINATION.md`: separate CPU sets and memory caps per agent (0-15 at 40 GB per guest, 16-19 at 16 GB, 20-23 at 8 GB), an image-rebuild lock, commits by path only, and a host-exclusive marker for profiling and timing.
- Runs started with `run-agent.sh`; the Windows watcher restarts any of the three after a reboot. Agent 3 was paused at 04:55 UTC to keep `lab` free for Cilium and was not resumed.

### Other lab workloads paused for the Cilium timing (2026-10-10 07:08 UTC)

- Paused with SIGSTOP (not killed): the gpu-smt Lean native preparation (PIDs 3489695, 3489707, 3489709, in a Coder Workspace), `telegram-desktop` (107173) and its Xvfb (105789), and the bpf-benchmark-supervisor `omp` session (3624916).
- Suspended: CronJobs `agent-duties/bpf-benchmark-supervisor`, `agent-duties/datrail-daily-check` and `telegram-archive/telegram-export-supervisor`. The DatRail check that was already running (light, network-bound) was left to finish.
- The list and the resume commands are in `lab:~/workspace/codex-runs/paused-workloads.txt`. Agent 1's counterbalanced timing used five fresh guests per order where it could.

### Outcome

- Cilium: the native object now uses the exact Cilium-generated configuration of its paired eBPF object (macro-set parity gate), both arms run the same 51 live programs with 8 attachments, and all 48 accepted phases forward every packet with zero errors and drops. Counterbalanced timing over fresh guests gives native/JIT 1.194x throughput (stats off, median of six guests; JIT/JIT controls 1.038x) and 659.2 to 463.9 ns per BPF run. A counterbalanced P-core profile is committed. bpf-benchmark `origin/master` `e3f503e1e`; the paper uses these numbers from `cccf592`.
- Katran stayed parked after its local gate passed; no Katran timing was taken.
- Resume (checked 2026-10-10 17:58 to 2026-10-11 00:09 UTC): the three CronJobs were unsuspended and `telegram-desktop`/Xvfb were running again before this agent got to them. The paused gpu-smt Lean preparation and the supervisor `omp` were lost when the Workspace Pods on `lab` were recreated during the 17:38 UTC disk-pressure recovery (`incident-logs/2026-10-10-lab-disk-pressure-build-cache-recovery.md`); gpu-smt's own lane restarted its preparation at 18:04 UTC (`full-recovery-20261010T180425+0000`) and the supervisor duty reconnected at 18:01 UTC.

## Validation and rollback

The AWS phase left no instance running (`describe-instances` empty). The lab phase's results and code are on bpf-benchmark `origin/master` `e3f503e1e`; nothing on `lab` outside the clone and `~/workspace/codex-runs` was changed beyond the K6 pauses, which are resumed.

Rollback: stop any remaining run (`pkill -f codex-runs/lab-`), delete `~/workspace/bpf-benchmark-rerun-20261009` and `~/workspace/codex-runs`, and resume any process still stopped with `sudo kill -CONT <pid>` and any CronJob still suspended with `kubectl patch cronjob … -p '{"spec":{"suspend":false}}'`.
