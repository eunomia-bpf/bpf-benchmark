# 当前设计和与原话的差异（协调者，每小时更新）

更新时间 2026-11-21T15:5x UTC。依据：运营者 2026-11-21 约 15:5x UTC“每小时定时任务都需要汇报完整的当前设计以及和设计的差异.”、“停掉所有测试, 你来做, codex 只负责 verify 的部分, 去确保设计完全符合我说的, 做好之前不要测量”。design.md 保持原样，本文件写实际形态和差异。

## 一、设计（按运营者原话定义；design.md 保持原样）

1. **整体**：程序在内核里以原生代码运行，安全由库存 eBPF verifier 对 simulator 形式的分析给出（design.md §编译流水线，运营者同意的设计）。
   - 每个程序都走原生：“任何情况下绝对不允许留在 ebpf 上面跑”（11-21）。
   - verify 不过的程序也先跑原生：“verify 不了的也需要跑 native 先.”（11-16）；verify 和运行分开看：“恢复这个, 吧 verify 和运行分开看”（11-19）。
2. **P 怎么来**：从应用自己的源码直接编成机器码。
   - “不是直接出机器码吗? 为啥变成这样了”（11-14）。
   - 源码尽量不改：“我们应该尽可能禁止改源代码吧? 尽可能减少修改?”（11-13）；“必要的话改一点是可以接受的, 不需要过于严格, 但尽可能不改”（11-15）。
   - 兼容靠头文件：“不允许放进编译过程, 不是用头文件兼容吗”（11-15）；“可以往 "编译里塞头文件" 这个头文件把 bpf_core_field_exists 直接定成了 1 应该也行? 不需要这么复杂?”（11-14）。
   - 编译参数：“编译参数所有 app 统一.”（11-15）；“所有优化参数必须打开”（11-15）；“编译参数固定 O3. 不需要调代码大小了. 确保 inline 啥的都正常就好”（11-21）。
   - 运行时不带源码和编译器：“运行时镜像里要带源码和编译器? 不需要吧?”（11-12）；不多留 bitcode：“不需要 构建时多保留一份 LLVM bitcode?”（11-11）。
3. **P 怎么执行**：“直接执行 P 其实没错, 不需要改写. LTO 只是内核也做的事情, 算是 design detail?”（11-14）。
4. **优化放在哪**：
   - 顺序：“应该是先优化, 再验证优化后的那一份, 再优化, 再链接”（11-14）。
   - LTO 就是链接时内联 map 和 helper：“比如 inline map / helper 这个就是链接”；“这两个都叫做链接时优化. 没有额外的 受信改写, 只有 LTO”（11-14）。
   - map 查找像 JIT 一样内联：“verifier 会把 array、hash 这类 map 查找直接内联进代码，原生这边仍走 helper 调用。必须支持, 改 linker 或者或者在源代码的时候内联”（11-14）。
   - helper 用 C 直接编进去：“手写的 helper 例程 是不是应替换成 c 实现的直接编译进去的”（11-19）；“这些不是就是一个简单的头文件操作吗?”（11-20）。
   - 读内核内存直接内联解引用：“读内核内存要调用 bpf_probe_read … 不能也直接内联和解引用???”（11-19）。
   - 加载时特化、常量消除：“helper map 也可以这样内联之后常量消除”（11-11）。
   - 自己的 memset：“你可以改链接器, 自己写 mmset, 不要用内核的”（11-13）。
5. **不要的东西**：
   - “去审核代码. 禁止加任何额外的 check. 内核不必要的 check 也需要拆掉一部分, 确保这些被内联进去了.”（11-16）；“不允许增加新的 check”（11-09）。
   - “函数返回要经过内核的 return thunk … 没必要吧??? … 地址范围检查 … 没必要吧??? 栈改成私有区域 … 没必要吧????”（11-19）。
   - “禁止做这样的额外的改动, 以后记住. … 代码要显著减少, 你来做. 不要做这种额外的事情”（11-19）。
   - 内核：“内核是不是应该几乎不要修改, 整体 patch 也要少于 500 loc?”（11-16，问句）。
   - “旧的会误导的不要关闭, 要拆掉丢掉.”（11-15）。
6. **verify 侧**（完整保留：“verify 和功能的部分完整保留?”，11-21）：
   - simulator 特化：“把 P 当作 static const 数据，把 simulator 展开成直线 eBPF 为啥不直接把.rodata 值放进 C 里面? 干嘛还需要 bitcode?”（11-11）。
   - 形式化换成成熟项目：“让它清理掉, 换成成熟的.”“作为 submodule, 不要自己写.”（11-13）；“M1–M6 … 让它按顺序做”（11-14）。
   - “codex 只负责 verify 的部分”（11-21）。
7. **基准和测量**：
   - “不许改 bench 除非我同意”（11-15）；“整个 benchmark 框架不是说都不允许改动???”（11-20）；计时广度优先（11-11）。
   - “做好之前不要测量”“不允许随便测量”（11-21）；“不要随便重跑”（11-19）。
   - “你要用历史上最好的数据作为合理的数据 … 功能正常就可以”；“不应该拿调用次数做对比和 gate”（11-18）。
8. **目标**：“必须继续优化到至少 20%”（11-14）；“吞吐肯定也需要好 30% 以上”（11-14）；“你应该无论如何比 kinsn 好得多”（11-18）。
9. **起点**：“要不要从 5/29 的基础上重新改?”（11-16）；“如果从 5/29 开始, 性能这部分开始只重新 apply 部分必要的修复, 以及必要的优化 … verify 和功能的部分完整保留?”（11-21）；“直接 git revert 对应的文件到 ATC rebuttal 结束的时候.”（11-21）；“Cilium 我们之前 atc 结束之后, 10 月份有一些必要的修复”（11-21）。

## 二、现在实际的形态

1. **P 的构建**：vendor/bpf/Makefile 用 clang-18 从各应用自己的源码编原生对象，所有应用同一组参数（-O3）；编译时 -include core-compat.h（CO-RE 答案）和 native-helpers.h；每个应用一份 manifest。
2. **helper 的形式**（native-helpers.h 和 native-link）：

| helper | 现在的形式 |
|---|---|
| bpf_ktime_get_ns | 头文件内联，直接调用 ktime_get_mono_fast_ns |
| bpf_jiffies64 | 头文件内联，直接读 jiffies_64 |
| 读内核内存（bpf_probe_read_kernel(_str)、bpf_probe_read 的内核半） | 头文件内联，普通 load；坏地址由 load site 的异常修复兜底，和 JIT 的 PROBE_MEM 相同 |
| 读用户内存（bpf_probe_read_user(_str)、bpf_probe_read 的用户半） | helper 调用 |
| bpf_get_current_task(_btf)、bpf_get_smp_processor_id | helper 调用（0e4f2da6f 改成 gs 直接读，Tracee 来宾崩溃后 3b5fa4b40 改回调用） |
| map 查找 | ARRAY/PERCPU_ARRAY 由 native-link 内联，hash 族直接调用 map 操作，其余经 bpf_map_lookup_elem 调用 |
| bpf_tail_call | x86：native-link 的内联桩；arm64：无桩，这些程序留在 eBPF |
| 其余 helper | 按名字从 kallsyms 绑定的直接调用 |

3. **链接**：native-link 按名字绑定 helper、map 和数据，内联 array/percpu 查找，折叠只读数据，记录 load site。
4. **装载**：应用本身不改；shim（LD_PRELOAD）截获 BPF_PROG_LOAD；加载器按 BTF 函数名找 manifest 条目，再比较源码一致性（操作码和未被重定位的立即数，4abd03352）；一致则 native-link、经 direct-native 模块上传、替换程序入口；找不到一致的条目则留在 eBPF。
5. **两种配置**：
   - direct native（冻结计时入口量的就是它）：P 不经验证直接运行。
   - 主配置（checked）：可信服务生成 B，库存 verifier 验收；通过 → checked native；不通过或生成失败 → direct native。
6. **verify**：库存 verifier 验 B；形式化 M1–M6，M5（定理迁移）在做，M6 待做。
7. **覆盖**：
   - x86 direct native（镜像 3b5fa4b40）：Cilium 135 个里 107 个按端点编译的程序和 Tetragon 4 个程序留在 eBPF，其余全部原生。
   - 主配置 checked：BCC 25/25，Cilium 28/28（107 个按端点程序未进入），OTel 7/14，Tetragon 21/142（120 个 direct native、1 个失败），Katran 0/1，Tracee 最近一轮在 15:5x 停掉、无完整记录。
   - arm64：带尾调用和跨段调用的程序留在 eBPF（OTel 0/13、Cilium 9/113）；Tracee 在 KVM 的 180 秒负载里原生 trace_do_sigact 崩溃。
8. **规模**：性能路径（native-link、加载器、direct-native 模块、native-helpers.h、core-compat.h）17,340 行；2026-05-29 以来这条路径净增约 1.9 万行；最近 14 天 335 个提交、加 19,820 行删 21,687 行。

## 三、和原话的差异

| # | 差异 | 原话 |
|---|---|---|
| 1 | Cilium 107 个、Tetragon 4 个程序留在 eBPF；arm64 带尾调用和跨段调用的程序留在 eBPF。规则（找不到一致条目就留在 eBPF，4abd03352）是协调者 11-19 自己定的 | 2026-11-21“任何情况下绝对不允许留在 ebpf 上面跑” |
| 2 | 主配置里 B 验不过或生成失败的程序跑 direct native（Tetragon 120、OTel 7、Katran 1）：这一条按 11-16“verify 不了的也需要跑 native 先.”成立；差异在“按记录”回落的机制（加载器按 coverage 记录决定路径） | 2026-11-19“按记录回落到直接原生 是是什么鬼???” |
| 3 | 读用户内存、current_task、CPU 号、hash 以外的 map 查找仍是 helper 调用 | 设计“LTO：绑定并内联 map 查找和 helper”；2026-11-19“手写的 helper 例程 是不是应替换成 c 实现的直接编译进去的”、“不能也直接内联和解引用???” |
| 4 | 性能路径 5/29 以来净增约 1.9 万行 | 2026-11-19“代码要显著减少, 你来做” |
| 5 | checked 路径的 IR 仍有栈规整（packet_bounds_ir.cpp normalize_private_stack_accesses） | 2026-11-19“栈改成私有区域 … 没必要吧????” |
| 6 | 主配置的计时走 kprog/results/lto-apps-20261119/Makefile 和 queue-*.sh，在冻结入口之外 | 2026-11-15“你去删掉. 立刻删掉.”（外包的计时脚本） |

## 四、下一步（按 2026-11-21 的原话，不测量）

1. 列出 5/29 的性能路径（/workspaces/kprog-raw/paper-tree-untracked 和 2026-05-29 的提交 82ec89cb4）和今天的逐文件差异。
2. 定“必要修复”清单：今天的内核和应用上跑起来所需的，加上 Cilium 在 10 月的必要修复。
3. 定“必要优化”清单：设计写明的 LTO 内联（map 查找和 helper，包括读内核内存直接 load）。
4. 性能路径回到 5/29，再按清单加回；verify 和功能部分完整保留；差异 1–6 逐条消掉。
5. 全部做好之后，跑一次六应用检查和一次冻结入口计时。
