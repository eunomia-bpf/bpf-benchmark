# kprog: performance work starts ahead of the six-application milestone

- Date: 2026-11-08 (UTC)
- Scope: CronJob `agent-duties/bpf-benchmark-supervisor` prompt (lane R) for Workspace `yunwei356/bpf-benchmark-dev`
- Status: deployed

## User request and approval

> “接下来高优先级的是啥? 性能优化呢”
>
> “提前开工”
>
> “也要看看为啥之前快现在变慢. 你的性能优化可以在哪里做不能在哪里做? 你知道吗”

The coordinator had scheduled the link-time optimizations for after all six applications bind on the x86-64 verified path, and proposed starting earlier. The operator approved starting now.

## Defaults and decisions

| ID | Setting | Before | After | Reason |
| --- | --- | --- | --- | --- |
| BPF-35 | R's current task | Port the kernel selftests, then per-program attribution | Explain why the 2026-05-29 numbers were faster, then time Katran on the verified arm, then split run time per call site into computation, helper calls, map lookups and tail calls | Lanes A and C finished the selftests port (BPF-34), and the existing counters measure whole programs only |
| BPF-36 | Start of link-time optimizations | After six applications bind on the x86-64 verified path | Lane C starts on BCC and Katran, the two applications that bind, once its current job chain closes, in the native compile of P | On real applications the verified path measures 0.96x to 1.00x, so the optimizations decide the performance result |
| BPF-37 | R's explanation of the 2026-05-29 gap | Per-program medians, concluding both arms moved alike | Katran first, comparing the 2026-05-29 and current native code, with the per-call-site work held | The archived per-run totals show the JIT arm steady and the native arm slower on Tetragon and Katran |
| BPF-38 | Benchmark framework and target | Framework edited alongside the lanes, target unstated | Framework frozen at b44be576b; target geometric mean of native/JIT throughput across six applications 1.20x to 1.40x | Operator 2026-11-09: “也要确保 benchmark framework 不能变化.”, “要确保变快, 目标大概是平均之后 20%-40% 进步”, “这肯定能做到, 要仔细分析” |
| BPF-39 | Benchmark workload baseline | Current tree, with OTel at 1000 samples per second since 2026-05-30 and the Katran workload changed on 2026-10-10 | The 2026-05-29 definition (9f3855f6f): OTel 100000 samples per second, Katran four pktgen workers, 65535 flows, flag !SHARED. R restores it and confirms both arms pass through XDP with equal work before any comparison | Operator 2026-11-09: “是不是 5 月份之后就应该冻结”, then “我建议恢复到 05-29 的工作负载” |
| BPF-40 | Protection of the freeze | Written rule in AGENTS.md since 2026-09-25 | Freeze point recorded as 9f3855f6f, 2026-05-29 02:22:18 UTC; commit and push hooks in the Workspace checkout plus the immutable attribute on 162 tracked files; audit.sh lists edits, missing hooks and lost attributes | Operator 2026-11-09: “明确记录冻结时间, 以后也要想办法防止继续改动” |
| BPF-41 | Native arm of R's timing runs | Native objects packaged in the restored image on 2026-11-07, which end with EIO at the specializer | Lane C's payloads on the current ABI, overlaid per timing-request.md; R reads the COORDINATION.md lines addressed to it before each run | Operator: “要确保变快, 目标大概是平均之后 20%-40% 进步”; R's 636e7a56f names the stale objects, and C's BCC payload had waited since 07:28 UTC while R waited on C |
| BPF-42 | R's prompt | About 12 KB accumulated since 2026-11-05, with finished tasks and retired lanes | Short prompt in current task order; complete 2026-05-29 version of Katran and OTel first, then walk forward, then current payloads; commit and push every step | Operator 2026-11-09: “性能是不是恢复之前的版本先? otel 和 katran?”, “一些旧的混乱的是不是要清理, 免得干扰? 另外是不是做一步 commit push 一步”. The earlier prompt stays in git history |
| BPF-43 | R's acceptance and order | A restored number counted when it returned; candidates timed after verified coverage | Equal work is the acceptance test; published P candidates are timed on the unbound path today; each table row names run directory, duration, samples and status; BPF share is measured | First detour audit of 2026-11-09, findings 1, 3 and 5, checked against the raw runs; operator 2026-11-06: “如果直接跑 native 有碰到 verifier 错误, 我们是不是也应该先把性能跑出来” |
| BPF-44 | R's task order | 2026-05-29 restore first, then current-ABI payloads | Commit cited runs; time C's Katran candidates on the direct native path; settle OTel equal work from the apps' own counters; run the other four apps on the 05-29 image; BPF share against the bounding CPU | Operator 2026-11-09: “我们优化和 verifier 目前还是暂时分开”; third detour audit: candidate timings stood at zero for about 23 hours |
| BPF-45 | R's first task | Katran candidates before the other four apps | All six applications on the rebuilt 2026-05-29 image first, each beside its archive figure, then candidates | Operator 2026-11-10: “性能呢? 先把所有的都测试一遍了吗? 回到之前的数字了吗” |
| BPF-46 | Where R's six-application timing runs | /paper-tree, a copy of the 2026-05-29 benchmark files, and private harnesses under /root | The committed recipe kprog/perf/may29-image from /workspaces/repository on master | Operator 2026-11-10: “/paper-tree 是什么???? 又违规开了 worktree 了?” |
| BPF-47 | What a timing row needs | Equal-work counters of both arms on every run, and a counter-reading run for OTel | audit_native_arm.py plus the same program names in both arms; per-application counters only when a number looks wrong | Operator 2026-11-11: “工作量相同之类的额外审查是不是太严格?” |
| BPF-48 | R after the 2026-11-10 23:53 UTC Workspace container restart | Job bpf-benchmark-supervisor-29905720 Running since 20:40 with its process gone, CronJob Forbid blocking the next run; prompt on the finished 2026-05-29 queue and cleared /var/tmp paths | Job deleted so the CronJob starts R again; R first rebuilds the timing bases on /workspaces/.agent-state/kprog-r-art, then reads OTel and Tracee counters once, then times lane C candidates and the Katran walk steps 0 and 3 | Operator 2026-11-06: “你也要设计每小时监控, 用中文给我汇报结果, 并且盯着去做.” |
| BPF-49 | Kernel for timing | Rebuild the 2026-05-29 kernel and image for the reproduction and the Katran walk | Every run on the current kernel; the 2026-05-29 image stays the finished reference; the Katran 31 ns is settled on the direct-native image | Operator 2026-11-11: “干嘛要编译这个? 内核能不能都在新的上面跑?” |
| BPF-50 | R's timing | Running on the 2026-11-09 kernel and several images built after the container restart | CronJob suspended; old kernels, images and ARTs removed; timing resumes as one six-application sweep on the single kernel line once one clean image exists, with optimization as the focus | Operator 2026-11-11: “R 的计时其实还在用 11-09 的旧内核 我觉得应该停下来, 清理一下所有东西, 确保不会出现多个版本或者旧的内核什么的. 是不是也不需要 5 月份的对比了? 接下来重点是优化?” and “能不能不要这样折腾乱七八糟的计时? 讲讲现在完整的性能和故事? 现在是不是太乱了?” |
| BPF-51 | Kernels, worktrees, images, bases; benchmark settings; performance floor (highest priority) | Several kernel versions (7d6b7d663 line, 9c50491de, the 2026-11-09 build, the 2026-05-29 kernel, ART copies), extra worktrees, 16 images, per-lane bases; current objects below the 2026-05-29 system on Katran, Cilium and OTel | One worktree, one kernel line (needed functions from 9c50491de and a3cb8790e merged into the 7d6b7d663 line, then every other kernel removed), one image bpf-benchmark/kprog:current, one base kprog-ck; raw data kept on /workspaces; benchmark settings stay at 9f3855f6f; every application reaches at least its 2026-05-29 number, with the 2026-05-29 code as the byte-level reference. Recorded at the top of bpf-benchmark AGENTS.md (ed44df5f1), COORDINATION.md, both lane prompts, the hourly skill and audit, kprog/docs/todo.md | Operator 2026-11-11: “确保需要的功能 merge 到一起之后, 删掉所有别的内核版本. 任何时候只允许一个镜像和一个底座. 所有原始数据不允许删掉, 不允许建立任何新的 worktree. 明确记录.” “这个规则要记录在好几个地方, 最高优先级” “我们要确保在当前系统也达到这样的性能. benchmark 设置也不能改, 除非得到我同意” “得确保当前对象也是 05-29 系统的性能数据, 当前对象为啥会差? 是不是有回归? 代码为啥不是直接和 05-29 一致?” |

**Placement.** Design step (e) reads: the JIT emits the same kernel copy of P with its relocations resolved. Optimizations therefore live where P is produced: compiler flags, subprogram inlining, lowering of helpers and map lookups into P's own instructions with existing relocation kinds, and recompiling P from stable map contents before submission. B simulates that P as usual and the stock verifier decides. The coordinator's earlier list named link-time inlining, direct tail-call linking and load-time specialization inside the kernel path; those rewrite P after verification and are withdrawn. A new relocation kind is a new link step, and lane V adds its O4 theorem with it.

## Evidence and implementation

- **Timing recipe.** Lane C posted the Katran verified-path recipe under "Timing requests" in `COORDINATION.md` on 2026-11-08 at 16:25 UTC.
- **Prompt.** In `services/agent-duties/duties.yaml`, the selftests and attribution paragraphs of R's prompt become the performance paragraph. The admission annotations point at this record.
- **Priorities.** `COORDINATION.md` item 5 records the new order.

## Validation and rollback

Validation:
- The CronJob carries the new paragraph, and the next R Job's argv carries it.
- R extends `kprog/results/kprog_perf_attribution_20261108/README.md` with per-call-site shares.

Rollback: revert this commit.
