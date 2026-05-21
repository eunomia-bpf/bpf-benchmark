# Morpheus (DSRO, ASPLOS'22) 深度分析 — 对 idea #1 的影响

- 论文:Domain Specific Run Time Optimization for Software Data Planes
- 作者:Sebastiano Miano, Alireza Sanaee, Fulvio Risso, Gábor Rétvári, Gianni Antichi
- 会议:ASPLOS '22(QMUL / Politecnico di Torino / Budapest)
- PDF:`docs/reference/papers/10-dsro-domain-specific-run-time-optimization.pdf`
- 代码:https://github.com/Morpheus-compiler/Morpheus(~6000 行 C++,LLVM 工具链)
- 分析日期:2026-05-20

> 结论先行:**Morpheus 是 idea #1(BpfReJIT)最近邻、机制高度重叠的 prior work。**
> 它的 eBPF 路径同样是 online + 多版本 + profile-driven + guard + tail-call 原子换
> + **重 load 经 in-kernel verifier 兜底**,优化 pass 也几乎逐个对应。idea #1 原先的
> 两个卖点("用 verifier 当 oracle"、"online/multi-version/profile-driven+guard 是
> 本质差异")**对 Morpheus 不成立**。站得住的差异只剩"通用 eBPF(非网络)"+"字节码
> 层 + LD_PRELOAD 透明 shim(非 IR 层 + 框架集成)"。

---

## 1. Morpheus 做了啥

**定位**:面向**软件数据面(packet processing)**的 runtime 编译/优化框架,unsupervised
(不需预先知道 control-plane 配置或流量模式),在 **LLVM IR 层**做优化,建在 LLVM JIT
工具链上。

**4 段 pipeline(Fig 2)**:

1. **Analysis(§4.1)**:静态分析定位所有 map 访问点;signature-based call-site 分析 +
   MemorySSA / alias 分析把 map 分成 **RO(只读)** 与 **RW**。RO 可激进特化,RW 保守。
2. **Instrumentation(§4.2)**:自适应插桩,给 map 访问建 heatmap/sketch(LRU、per-CPU、
   采样 5–25%)找 heavy hitter。naive 全记录 14–23% 开销 → 自适应压到 0.9–9%。
3. **Optimization passes(§4.3, Table 2)**:JIT(把高频 table entry inline 进代码)、
   Table Elimination、Constant Propagation、Dead Code Elimination、Data Structure
   Specialization、Branch Injection、Guard Elision。
4. **Update(§4.4)**:原子换数据面,control-plane 更新在重编译期间排队。

**eBPF 具体实现(§5.1 + §6.3,关键)**:

- 后端用 **Polycube**,数据面是一串 eBPF 程序经 **tail-call BPF_PROG_ARRAY** 串联。
- 调 eBPF LLVM backend 生成新 eBPF → **`bpf()` syscall 重新 load → 原子更新
  BPF_PROG_ARRAY 入口指向新程序**。
- **重 load 必过 in-kernel verifier。** §6.3 原文:代码 "must pass the in-kernel
  verifier for a safety check before being activated. This also ensures that the
  mistaken Morpheus optimization pass will never break the data plane." ——
  **verifier 就是 Morpheus 的 safety net。**
- **Guard**:程序级版本检查 guard 放入口;RW map 在 `map_update_elem` 指令地址插
  guard pre-handler,写 map 时失效 guard、回退原版本。control-plane 更新由单个
  程序级 guard 覆盖。
- 注入耗时 0.5–3.4ms(最差 6.1ms),重编译周期默认 1s,优化器跑在独立 core(~5% CPU)。

**评测(§6)**:Polycube 的 L2 switch / Router / NAT / BPF-iptables + Facebook Katran。
eBPF 吞吐 **最高 +94%**,L1 i-cache miss −17.1%,Katran 延迟降 ~123%;高局部性流量比
ESwitch 快 5–10×。DPDK/FastClick plugin 也有(但 stateful 优化被禁用作为 workaround)。

---

## 2. Morpheus 没做啥(= idea #1 的空间)

1. **只做网络数据面。** 标题与全部 use case 都是 packet processing(switch/router/
   NAT/iptables/Katran/XDP)。**没有 tracing、没有安全观测(Tetragon/Tracee/BCC)、
   没有 scheduling。** 整套 domain-specific 机制建在 **match-action table + 流量模式**
   上 —— 一个 kprobe handler 没有 match-action table,Morpheus 那套用不上。
2. **在 LLVM IR 层 + 必须集成进工具链。** §7 自承 IR 层 drawback:拿不到机器码,
   **做不了 peephole / vectorization/SIMD / packet 级 micro-opt**。且需要程序的 IR、
   要建在 Polycube/FastClick 里 —— **不能透明作用于已部署、未改动的任意 eBPF 程序**。
3. **profiling 信号是 per-packet map-access 插桩**(networking 专用 heatmap),不泛化到
   "syscall 触发的 tracing 程序"。
4. **stateful 退化(§6.5)**:NAT conn-tracking 这种高频写 RW map,guard 无法 elide,
   只剩 ~5% 收益,还要**人工干预**手动关优化。
5. **依赖 match-action table 抽象**做 Table Elimination / Data Structure Specialization。

---

## 3. 与 idea #1(BpfReJIT)的逐项对照

| 维度 | Morpheus(eBPF 路径) | bpfopt / BpfReJIT(idea #1) | 是否区别 |
|---|---|---|---|
| 时机 | online / runtime | online / post-load | 相同 |
| 版本数 | 多版本 + guard 回退 | 多版本 + inline guard + slow path | 相同 |
| profile-driven | ✅ | ✅ | 相同 |
| 安全保证 | **重 load 过 in-kernel verifier** | **重 load 过 stock verifier** | **相同(原先以为是区别,错)** |
| 换版本 | tail-call BPF_PROG_ARRAY 原子换 | attach-update / LINK_UPDATE 等 | 大体相同 |
| 优化 pass | const_prop / dce / table-inline / branch-injection / data-struct-spec | const_prop / dce / map_inline / branch_flip / map representation switching | **高度重叠** |
| 适用域 | 网络数据面(match-action table) | 通用 eBPF(含 tracing/安全/观测) | **✅ 区别** |
| 操作层次 | LLVM IR + Polycube/FastClick 工具链 | raw BPF 字节码 + LD_PRELOAD 透明 shim | **✅ 区别** |
| 透明性 | 否(需用其工具链构建程序) | 是(拦截未改动上游 app,作用于已部署程序) | **✅ 区别** |
| profiling 信号 | per-packet map-access heatmap 插桩 | run-stats / PMU per-site | **✅ 区别** |
| 下游硬件 lowering | ✗(IR 层做不了,§7 自承) | ✅(字节码产物可喂 kinsn / idea #2) | **✅ 区别(衍生)** |

---

## 4. 对 idea #1 paper framing 的硬结论

**两个原卖点作废:**

- ❌ "用 stock verifier 当 safety oracle" —— Morpheus 也靠 verifier(§6.3 白纸黑字)。
- ❌ "online / multi-version / profile-driven + guard 是本质差异" —— Morpheus 全有。

**站得住的差异只剩:**

1. **域**:Morpheus 只网络数据面;bpfopt 通用 eBPF(tracing/安全/观测,无 match-action
   table)。
2. **层次 + 透明性**:Morpheus 在 IR 层、集成进 Polycube/FastClick;bpfopt 在字节码层 +
   LD_PRELOAD shim 透明拦截未改动上游 app,作用于已部署程序、不要源码/IR。**最干净的一条。**
3. **信号**:Morpheus per-packet 插桩;bpfopt run-stats/PMU。
4. (衍生)bpfopt 字节码产物能喂 kinsn 做硬件 lowering —— Morpheus §7 说 IR 层做不到。

**审稿人会打**:"这就是把 Morpheus 从 networking 推广到 general eBPF、从 IR 层换到
bytecode+shim 层,机制一样,delta 够 OSDI 吗?" —— idea #1 必须把 contribution **重新
锚定到「通用 eBPF + 透明字节码 shim,作用于未改动的已部署程序」**,而不是「online
speculative recompile」(后者 Morpheus 已占)。同时需要 ablation 证明收益来自 online
speculation 而非单纯 better codegen。

---

## 5. 引用落点

- `docs/rejit-speculative-optimization-ebpf_idea.md` §1.8 两张比较表已加入 Morpheus 行,
  并更正了"verifier 当 oracle 是区别"的错误表述。
- 相关工作全集见 `docs/tmp/related-work-gap-analysis-20260520.md`。
