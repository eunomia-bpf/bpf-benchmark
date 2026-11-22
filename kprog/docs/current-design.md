# 当前设计和与原话的差异（协调者，每小时更新）

更新时间 2026-11-22T00:3x UTC。依据：运营者 2026-11-21“每小时定时任务都需要汇报完整的当前设计以及和设计的差异.”、“停掉所有测试, 你来做, codex 只负责 verify 的部分, 去确保设计完全符合我说的, 做好之前不要测量”、“应该在 5/29 基础上, 除了 verify 的部分以外整个路径 1000 行以内的 fix 和优化? 因为之前都跑通了?”、“都做好之后再完整详细测试性能, 重点是确保符合 design, 不需要调参. 可以和 5/29 对比.”。design.md 保持原样，本文件写按原话定义的设计、实际形态和差异。

## 一、设计（按运营者原话定义）

```text
target P ─┬─ 验证侧（只在 load / 验证期）：native P + 已验证的忠实解释器 I → “I 跑 P” 表示成 eBPF
          │    → stock eBPF verifier 照常分析 → verifier 接受 = 确证 P 内存安全
          └─ 执行侧（装载后）：链接时优化（LTO），绑定并内联 map 查找和 helper → 直接执行原生代码；eBPF 只被分析
```

1. **整体**：每个程序都以原生代码运行，安全由库存 verifier 对 simulator 形式的分析给出。
   - “任何情况下绝对不允许留在 ebpf 上面跑”（11-21）。
   - “verify 不了的也需要跑 native 先.”（11-16）；“恢复这个, 吧 verify 和运行分开看”（11-19）。
2. **P 怎么来**：从应用自己的源码直接编成机器码。
   - “不是直接出机器码吗? 为啥变成这样了”（11-14）。
   - “我们应该尽可能禁止改源代码吧? 尽可能减少修改?”（11-13）；“必要的话改一点是可以接受的, 不需要过于严格, 但尽可能不改”（11-15）。
   - 兼容靠头文件：“不允许放进编译过程, 不是用头文件兼容吗”（11-15）。
   - “编译参数所有 app 统一.”（11-15）；“编译参数固定 O3. 不需要调代码大小了. 确保 inline 啥的都正常就好”（11-21）。
3. **P 怎么执行**：“直接执行 P 其实没错, 不需要改写. LTO 只是内核也做的事情, 算是 design detail?”（11-14）。
4. **优化（链接时）**：
   - “应该是先优化, 再验证优化后的那一份, 再优化, 再链接”（11-14）。
   - “比如 inline map / helper 这个就是链接”；“没有额外的 受信改写, 只有 LTO”（11-14）。
   - map 查找像 JIT 一样内联：“必须支持, 改 linker 或者或者在源代码的时候内联”（11-14）。
   - “手写的 helper 例程 是不是应替换成 c 实现的直接编译进去的”（11-19）。
   - “读内核内存要调用 bpf_probe_read … 不能也直接内联和解引用???”（11-19）。
   - “helper map 也可以这样内联之后常量消除”（11-11）。
5. **不要的东西**：“禁止加任何额外的 check”（11-16）；“不允许增加新的 check”（11-09）；return thunk、地址范围检查、私有栈“没必要吧”（11-19）；“代码要显著减少”（11-19）；“旧的会误导的不要关闭, 要拆掉丢掉.”（11-15）。
6. **verify 侧完整保留**：“verify 和功能的部分完整保留?”（11-21）；“codex 只负责 verify 的部分”（11-21）。
7. **基准和测量**：框架不改（11-15、11-20）；“做好之前不要测量”“不允许随便测量”（11-21）；“都做好之后再完整详细测试性能, 重点是确保符合 design, 不需要调参. 可以和 5/29 对比.”（11-21）；“你要用历史上最好的数据作为合理的数据 … 功能正常就可以”（11-18）。
8. **目标**：“必须继续优化到至少 20%”（11-14）；“你应该无论如何比 kinsn 好得多”（11-18）。
9. **起点和预算**：“直接 git revert 对应的文件到 ATC rebuttal 结束的时候.”；“应该在 5/29 基础上, 除了 verify 的部分以外整个路径 1000 行以内的 fix 和优化”；“Cilium 我们之前 atc 结束之后, 10 月份有一些必要的修复”（均 11-21）。

## 二、现在的实际形态

**基础**：性能路径（P 的构建 vendor/bpf、native-link、加载器、direct-native 模块、shim）是 2026-05-29（82ec89cb4）的内容，3aa496416 换回；verify 侧文件保持原样（可信服务、kprog/x86 的 B 生成、perf_context_lto、形式化）。

**相对 5/29 的修复和优化**（kprog/results/restore-529-20261121/tally.sh 逐文件统计，生成的 vmlinux 头不计）：

| 类别 | 内容 | 位置 |
|---|---|---|
| 今天的内核 | 模块把上传的镜像 arm 给装载线程（bpf_native_image_arm），加载器写 callee-saved 掩码后以 BPF_F_NATIVE_IMAGE 装载 B（`r0 = 0; exit`，尾调用程序带尾调用点）；kfunc 查找删掉 | 模块、加载器 |
| 今天的内核 | Tetragon：-fms-extensions（struct filename 的匿名头）；补 bpf_copy_from_user_str 声明（内核 BTF 不带 kfunc 声明） | vendor/bpf |
| Cilium 10 月 | 数据符号按程序自己的 BTF datasec 定偏移（端点值是程序 map 里的装载期 CONFIG）、扫描 fd 时固定 fd、skb cb 布局、POLICY_AUDIT_MODE、链接临时文件按线程 | 加载器、vendor/bpf |
| arm64 | 同一份模块源码编 bpf_arm64_native_lab（目录名、256 字节块） | 模块 |
| arm64 | 构建按架构参数化（vmlinux 头、__TARGET_ARCH、系统头）；-mno-outline-atomics；pt_regs 参数寄存器；Tetragon regs.h 的 arm64 分支用普通 C；OTel 部分链接带目标；入口函数多处保存（shrink-wrapping）时保留自己的保存 | vendor/bpf、native-link |
| arm64 | 尾调用内联：P 编译时保留 x26（-ffixed-x26，arm64 所有应用一致），x26 在原生帧里指向尾调用计数；native-link 把 bpf_tail_call 展开成 JIT 同样的序列（界检查、计数、取 prog、回到帧底、弹出五对寄存器、跳到目标序言之后），任何深度的调用点都可用 | native-link、加载器、vendor/bpf |
| 去掉 | 5/29 构建期对每个符号跑 native-link proof 模式的关卡（产物没有人读；checked 配置在装载时自己跑 proof），90 行 | vendor/bpf |
| arm64 | 数据重定位按段处理（proof 拷整段、kernel 用段副本加偏移）；调用对象内其它函数（构建时把可执行段合成一个 .text，native-link 跟进 CALL26）；按编号调用的 helper：函数只给这个寄存器写过一个编号时直接调，其余按运行时编号分派（5f1f0cd3a；8294617c9 的按块取编号让 Katran 在来宾里崩溃，已退回）；模块和加载器收 2048 块（arm64 512 KiB，x86 256 KiB） | native-link、模块、加载器、vendor/bpf |
| 功能修复 | OTel 的 perf_event 入口在原生编译下经内核上下文 bpf_perf_event_data_kern 的 regs 指针读寄存器（95cb987c5，6 行，MICRO_NATIVE 分支）：5/29 的原生入口按公开布局读 ctx+160，找不到用户态寄存器，跳过了栈展开 | vendor/bpf（OTel 源码一处） |
| arm64 | Tetragon 的尾调用特性探测程序在 arm64 上也认得出（它的指令里带 prog array 的 fd，x86 是 7、arm64 是 6，5/29 的规则按指令哈希认，33989a177 去掉哈希条件） | shim |
| 功能修复 | helper 绑定到内核对这个程序类型实际调用的函数（模块 helper_targets，按 get_func_proto 查；复用 verify 侧的查询函数） | 模块、加载器 |
| 功能修复 | 字符串常量（.rodata.str*）留在镜像里，不绑到程序的 map（Tracee）；cilium_snat_v4_external 按类型和 key/value 大小匹配（agent 按内存定大小） | 加载器、manifest |
| 功能修复 | B 持有 P 引用的全部 map（5/29）；内核因 prog array 主人类型不同拒绝时，去掉原程序没用的 prog array 再装（OTel custom__generic） | 加载器 |
| 测量修复 | shim 的快照等进行中的原生加载做完（2026-11-12 的 1af32bdae）；测量开始前等原生加载静止 2 秒（最多等 180 秒，fd7b7d5d7）：冻结 runner 看到 100 个程序就开始测，Tetragon 288 个原生加载要跑约 100 秒，之前原生臂只取样到 175 个程序，现在两臂都是 287 个 | shim |
| 优化 | 读内核内存直接 load：头文件把 bpf_probe_read_kernel(_str) 和 bpf_probe_read(_str) 的内核半区写成普通 load；native-link 给 P 里每条读内存指令记 load site；加载器上传；模块转成内核 extable 项（出错读 0 继续，和 JIT 的 PROBE_MEM 一样） | vendor/bpf、native-link、加载器、模块 |
| 路径 | native-sim → kprog | vendor/bpf |

5/29 本来就有的链接时优化：ARRAY/PERCPU_ARRAY 查找和更新内联、hash 查找直接绑定 __htab_map_lookup_elem、CPU 号内联、x86 尾调用内联。

**helper 的形式**：

| helper | 形式 |
|---|---|
| map 查找 / 更新 | ARRAY、PERCPU_ARRAY 内联；hash 直接调 __htab_map_lookup_elem；其余调 helper |
| 读内核内存 | 普通 load + load site |
| 读用户内存 | helper 调用 |
| bpf_get_smp_processor_id | 内联 |
| bpf_tail_call | x86 内联（入口函数内）；arm64 内联（任何函数内） |
| 其余 | 按名字绑定内核 helper |

**匹配**：加载器按程序名找 manifest 条目（5/29 的规则）；4abd03352 的“常量对不上就留在 eBPF”随 5/29 恢复一起去掉。

**两种配置**：direct native（冻结入口计时的）在 5/29 基础上完整；checked（主配置）由 formal 线（Codex，verify 侧）接回：dd6559b54 把可信加载放进单独的 native_loader_trusted.cpp，性能代码里只有一处分派；1cb485711 补回 --preserve-entry-abi。

**行数**：相对 5/29，路径文件合计新增 1326、删除 814（tally.sh，33989a177 时点；之后 5f1f0cd3a 净减 26 行、95cb987c5 加 6 行），其中约 370 行是 checked 配置（verify 侧）落在共用文件里的接入；修复和优化约 950 行，在 1000 行以内。

**构建**：native-link（7 个测试）、加载器、shim、x86 和 arm64 模块、x86 和 arm64 六应用原生对象都已构建通过（/workspaces/kprog-raw/coordinator/restore-529/）。x86 镜像 19:25Z 用 8430daa81 重建（含 fd7b7d5d7）；arm64 镜像在 arm64 检查跑完后用 33989a177 之后的头重建（chain3.sh）。

## 三、和原话的差异

| # | 差异 | 原话 |
|---|---|---|
| 1 | x86 六应用全部原生（OTel 14、BCC 25、Cilium 135、Tetragon 288、Tracee 169、Katran 1）；库的特性探测程序（libbpf、cilium/ebpf 加载后马上卸载）按 5/29 规则留在 eBPF | “任何情况下绝对不允许留在 ebpf 上面跑” |
| 2 | arm64 来宾检查（镜像 5f1f0cd3a）：BCC、Tracee、Katran 原生通过；OTel（分派处 brk）、Cilium（printk 收到垃圾参数）、Tetragon（尾调用跳到字符串地址）崩溃，原因在查；按 11-20 原话，这三个应用的 arm64 数用 5/27 的（06-14 矩阵） | 2026-11-20“确保 arm 和 x86 都要弄好, 不然就用 5/27 的数字 … 如果 11/22 之前弄不好就还是 5/27 的” |
| 5 | OTel 19:29Z 轮换的数作废（原生跳过栈展开），95cb987c5 修复后在新镜像上重测 | 2026-11-18“… 功能正常就可以” |
| 3 | 装载时常量特化（perf_context_lto）只在 checked 配置里用；它要求 P 带 bitcode、运行时带编译器，和 11-11“不需要 构建时多保留一份 LLVM bitcode?”、11-12“运行时镜像里要带源码和编译器? 不需要吧?”相反，所以 direct native 不接 | “helper map 也可以这样内联之后常量消除” |
| 4 | 读用户内存、current_task 仍是 helper 调用 | “手写的 helper 例程 是不是应替换成 c 实现的直接编译进去的” |

## 四、进度和下一步

1. x86 功能检查（每应用 10 秒、stats 开）全部通过：OTel、BCC、Cilium、Tracee、Katran 在 18:4x–18:59Z（镜像 6004ea7ac），Tetragon 19:29Z 在新镜像上复查（x86_kvm_corpus_20261121_192644_031303：288 个原生，两臂各取样 287 个程序，3 个活跃程序都跟中位数一致）。
2. x86 完整性能测试（冻结入口，六应用 × stats 关、开，3 样本 × 180 秒，不调参数）19:29Z 起在镜像 8430daa81 上跑，进度 /workspaces/kprog-raw/one-image-runs/progress.log。截至 00:25Z（may29_ratio.py）：

   | 应用 | 吞吐 stats 关 | 每次调用 stats 开 | 吞吐 stats 开 | 5/29 |
   |---|---|---|---|---|
   | OTel | 1.847x（作废） | 19.3x（作废） | 1.850x（作废） | 1.849x |
   | BCC | 1.014x | 0.999x | 0.999x | 0.985x |
   | Cilium | 1.026x | 1.108x | 1.048x | 1.319x |
   | Tetragon | 1.335x | 2.439x | 1.982x | 1.009x |
   | Tracee | 1.908x | 1.978x | 1.690x | 0.948x |
   | Katran | 1.106x | 在跑 | 在跑 | 1.113x |

   Cilium 每次调用低于 5/29 的 1.319x。之后 chain5.sh 清掉 x86 原生对象、重建镜像、重跑 OTel 两遍。
3. arm64：继续查 OTel、Cilium、Tetragon 的崩溃；这三个应用的 arm64 数用 5/27 的（06-14 矩阵）。修好后六应用再检查一遍，然后在 Spark KVM 上计时（暂停 DeepSeek，测完立刻恢复）。
