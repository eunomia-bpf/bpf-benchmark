# Operator words (kprog)

Every word the operator says about kprog is recorded here verbatim, with its date, in the turn it is said (operator, 2026-11-14: "确保没有做错, 并且每一个原话都记录下来"). Rules quote these words; a rule that is his own words keeps his wording, neither tightened nor relaxed, and a rule is relaxed only when it blocks the work ("要不还是不要放宽, 除非 blovk 了"). Older words also sit in AGENTS.md, kprog/docs/todo.md and kprog/docs/design.md where the rules they set live.

## From COORDINATION.md (the OPERATOR lines, in order)

- OPERATOR 2026-11-11T21:38:23Z (verbatim, asked about Tracee and BCC): "workload 如果能优化的话也行? 但是要分析处理 workload 哪里不好再说,我需要批准." Reading: a workload change is allowed once its analysis shows what is wrong with the workload; the change itself waits for the operator's approval (benchmark settings stay fixed until then).
- OPERATOR (verbatim, on the BCC/Tracee analysis): "这个是不是我们加载时的特化也要保持, 并且做的更过分? 比如说相当于 helper map 也可以这样内联之后常量消除. 在 llvm 层面做? 你看看?"
- OPERATOR 2026-11-11T21:49:19Z (verbatim, follow-up): "或者在 verifier 特化那一步做也可以?"
- OPERATOR 2026-11-11T21:49:50Z (verbatim): "我们可以保留两种版本, isolate 出来性能差异,一个是有内联特化的版本一个是没有内联特化的版本?"
- OPERATOR 2026-11-11T21:55:28Z (verbatim): "等等" then "不是 在 LLVM 层? 是在 simulator 那一层, 那不是用 c 做产量传播吗? 还可以进一步优化?" Prototype held until the operator continues.
- OPERATOR 2026-11-11T21:56:14Z (verbatim): "不需要 构建时多保留一份 LLVM bitcode?"
- OPERATOR 2026-11-11T22:21:03Z (verbatim): "干嘛要改机器码? 那里确实是 clang 在 C 层做常量传播：把 P 当作 static const 数据，把 simulator 展开成直线 eBPF 为啥不直接把.rodata 值放进 C 里面? 干嘛还需要 bitcode?"
- OPERATOR 2026-11-11T22:49:54Z (verbatim): "6 小时审核 可以是 claude." Decision: from the next 6-hourly run the detour audit runs as a fresh Claude subagent from kprog-control/detour-audit.md; audit-20261111T21 already running in omp finishes and is verified as usual. All other review stays with omp; the lanes stay stopped.
- OPERATOR (verbatim, 2026-11-11 ~22:55 UTC): "6 小时审核 可以是 claude. 开发让 omp 做" "每一个 workspace 一个 omp 在里面跑, 持续推进. local large"
- OPERATOR 2026-11-11T22:57:00Z (verbatim): "通知一下, audit 的提示词不允许改变吧? 只是不要启动 subagent"
- OPERATOR (verbatim, said in the eBPFOS session and relayed by it 2026-11-11 ~23:15 UTC): "eBPFOS 的固定提示词是按在这台 Windows 机器上运行写的,要逐字节不改就必须在本机执行,因此我改用桌面应用的定时任务,每 6 小时起一个全新会话 这个能不能通知大家都放进 workspace 里面执行? 你看看?" (the first half quotes the eBPFOS session).
- OPERATOR (verbatim, ModelOS quote 230, relayed by the ModelOS session 2026-11-12 ~05:40 UTC): "你看看等他恢复了, 通知三个实验, 每一个 workspace 里面都可以加一个 codex lane 一直干, 用 gpt 6.1 sol". The ModelOS session reports the cluster Codex login back on yunwei356@gmail.com at 05:25 UTC.
- OPERATOR (verbatim, 2026-11-12 ~07:25 UTC, on the verified lane's linker changes): "链接器要保留两种选项, 用runtime flag 之类的控制对吧"
- OPERATOR (verbatim, 2026-11-12 ~11:40 UTC): "运行时镜像里要带源码和编译器? 不需要吧?"
- OPERATOR (verbatim, 2026-11-12 ~22:30 UTC): "直接让另外一个临时 codex 去看看这个" "停掉 omp,开一个新的. 以后记住, 如果omp 两三次没有按照你说的, 你有权停掉他"
- OPERATOR (verbatim, 2026-11-13 ~02:25 UTC): "原生阶段只装了 106 个，两边连装的程序都不一样，正是临时 Codex 要查的 tailcall 是不是也要被静态链接起来? 这可能也是?"
- OPERATOR (verbatim, 2026-11-13 ~02:35 UTC): "bcc / tracee 之类的是不是也要看看继续优化? 我们几个 lane 了"
- OPERATOR (verbatim, 2026-11-13 ~02:45 UTC): "可以两个 codex lane. 尽可能不需要向你申请和协调, 你要给他们准备好 todo. 通知所有的实验管理者和写在 server manager, 不应该是申请协调, 而是你作为 advisor, 去 steer 和管理他们, 给他们设置目标和 todo? 这是不是更好? 多个的话让他们自己想办法协商"
- OPERATOR (verbatim, 2026-11-13 ~06:00 UTC): "我觉得这个做法不是改源代码, 我们应该尽可能禁止改源代码吧? 尽可能减少修改? ... 你可以改链接器, 自己写 mmset, 不要用内核的; 顺便去看看有没有类似的情况, 这不公平也很容易出错, 我们应该在链接器或者编译 flag 上面做文章"
- OPERATOR (verbatim, 2026-11-13 ~06:20 UTC): "新的 codex 检查还有没有别的源码不一致的?"
- OPERATOR (verbatim, 2026-11-13 ~06:25 UTC, on P0): "这个是不是还能优化一下? 性能更好一些? 比如特殊硬件指令"
- OPERATOR (verbatim, said in the ModelOS session ~06:40 UTC 2026-11-13, for all three research projects, relayed): "能不能派一些比较大的任务" "确保至少一天的任务, 你去看看, 让它自由开发并且和 codex 讨论" "3个 research 都是这样的"
- OPERATOR (verbatim, 2026-11-13 ~23:05 UTC): "之前不就是这样做的吗? 谁 tm 停掉了" "检查所有的实验, 必须都要有这样的东西"
- OPERATOR (verbatim, 2026-11-14 ~02:00 UTC): "OTel 读上下文的问题改对后，它只有 0.975x，每次调用 1.004x。为啥会这样? 性能肯定是没有优化好, 还是尽可能优化. 必须继续优化到至少 20%"
- OPERATOR (verbatim, 2026-11-14 ~02:10 UTC): "JIT 那边还占着便宜： verifier 会把 array、hash 这类 map 查找直接内联进代码，原生这边仍走 helper 调用。必须支持, 改 linker 或者或者在源代码的时候内联对不对? 比如说在受保护的 service 里面, 也就是进入内核之后并且链接器特化完成获取c代码之后, 可以把链接好 sim 的 c 复制一份, 一个拿来优化, 一个拿来 verify, 这也不破坏安全模型也不是 pcc?"
- OPERATOR (verbatim, 2026-11-14 ~02:20 UTC): "不可以先优化，再验证优化后的那一份。 因为内核就是这样的啊 "复制一份 sim C，一份优化来跑、一份拿去 verify"这个做法会破坏安全模型 不会吧? 你去仔细想想 应该是先优化, 再验证优化后的那一份, 再优化, 再链接时优化."
- OPERATOR (verbatim, 2026-11-14 ~02:25 UTC): "比如 inline map / helper 这个就是链接"
- OPERATOR (verbatim, 2026-11-14 ~03:20-03:30 UTC, on re-optimizing the checked sim C copy and inlining map/helper at link time): "这两个都叫做链接时优化. 没有额外的 受信改写, 只有 LTO" "都叫做 LTO" "改进去"
- OPERATOR (verbatim, 2026-11-14 ~05:35 UTC): "换成本地的 codex"
- OPERATOR (verbatim, 2026-11-13, relayed by the eBPF runtime formal verification session on 2026-11-14): "让它清理掉, 换成成熟的." "能不能基于什么上面 fork 一个改? 这也比较合理, 作为 submodule, 不要自己写." "不是交叉对造, 而是引入作为 subdmoule, 替换掉."
- OPERATOR (verbatim, 2026-11-14 ~07:10 UTC): "M1–M6 新的一个 codex, 用 goal 设置好六个让它按顺序做, 这个和别的无关吧? 你可以开一个新的 worktree?" "还是你觉得不需要 worktree?"
- OPERATOR (verbatim, 2026-11-14 ~07:25 UTC): "本地可以用到剩下 5%, 没事"
- OPERATOR (verbatim, 2026-11-14 ~09:35 UTC): "perf、verified、formal 需要3 个吗" "不要互相等等"
- OPERATOR (verbatim, 2026-11-14 ~09:50 UTC): "明确记录, 以后建议每个 lane 负责一部分代码. 所有 research 都生效"
- OPERATOR (verbatim, 2026-11-14 ~10:05 UTC): "我觉得要不要合并一下? 另外代码库的组织结构要不要整理?"
- OPERATOR (verbatim, 2026-11-14 ~10:20 UTC): "直接执行 P 其实没错, 不需要改写. LTO 只是内核也做的事情, 算是 design detail?"
- OPERATOR (verbatim, 2026-11-14 ~10:35 UTC): "同源构建测得 1.016x 我觉得肯定不对. 不可能这么点"
- OPERATOR (verbatim, 2026-11-14 ~12:20 UTC): "可以往 \"编译里塞头文件\" 这个头文件把 bpf_core_field_exists 直接定成了 1 应该也行? 不需要这么复杂?"
- OPERATOR (verbatim, 2026-11-14 ~12:25 UTC, on headers added with -include): "我没说过不行吧?"
- OPERATOR (verbatim, 2026-11-14 ~12:35 UTC): "还有没有过于严格的自我限制? 去看看, 所有实验也得看看"
- OPERATOR (verbatim, 2026-11-14 ~12:45 UTC, on the per-step OTel LTO rows): "不需要这样细粒度区分. 只需要都做就好."
- OPERATOR (verbatim, 2026-11-14 ~12:50 UTC): "然后你要想办法优化一下, LTO + native 我觉得到 40% 性能进步是完全肯定可以的. 先确保管线正确, 然后开始考虑优化. 每一个优化也得记录在哪里怎么做的."
- OPERATOR (verbatim, 2026-11-14 ~12:55-13:00 UTC): "LFENCE 为啥会有?" "编译选项是不是得开对?" "吞吐肯定也需要好 30% 以上"

## 2026-11-14, words said to the coordinator and recorded here first

- 2026-11-14 ~03:35 UTC: "确保现在的设计没有不符合的, 讲解一下现在的设计方式, 以及优化方案, 以及之后你打算怎么在哪里加优化方案."
- 2026-11-14 ~09:45 UTC: "你要看看其他的几个 research 有米有类似的问题"
- 2026-11-14 ~10:15 UTC: "我们现在离投稿还差啥? 实验和系统?"
- 2026-11-14 ~10:20 UTC: "所有应用?"
- 2026-11-14 ~12:40 UTC: "现在的所有数据?"
- 2026-11-14 ~20:20 UTC: "这些是我的原话. 这些不能还款"
- 2026-11-14 ~20:22 UTC: "kops 确实没有退役."
- 2026-11-14 ~20:22 UTC: "确保没有做错, 并且每一个原话都记录下来"
- 2026-11-14 ~20:25 UTC: "不新建 worktree 结果一出来就提交, 有更改就提交 git, 但不能改论文 不许 revert 提交 都是我的原话. 我没说的不能收紧, 可以放宽 这个你自己斟酌一下, 可以按照我的意思来, 但是有可能你检查不完全导致出错, 自己判断, 要不还是不要放宽, 除非 blovk 了. 这些是要记录在 workspace 里面, 全部适用的"

## Standing words for every Workspace (also in spark-manage workspace-rules.md)

- "不新建 worktree"
- "结果一出来就提交, 有更改就提交 git, 但不能改论文"
- "不许 revert 提交"

