# Tail-Call Specialization 深度调研报告

日期：2026-03-26  
任务：Tail-call specialization 深度调研  
上下文入口：`docs/kernel-jit-optimization-plan.md`  
相关前置设计：`docs/tmp/20260324/dynamic_map_inlining_design_20260324.md`

## TL;DR

结论先说：

1. **`bpf_tail_call()` 在当前 Linux/x86 上并不是“完全没优化”的间接调用。**  
   verifier 会把 helper `call 12` 重写成 `BPF_JMP | BPF_TAIL_CALL`；当 `map` 与 `key` 在 verifier 看来是立即数时，x86 JIT 会为该 site 建立 `poke_tab`，最终把它 patch 成 direct jump，而不是走间接跳转慢路径。

2. **因此，OSDI 级别的 BpfReJIT 贡献点，不能只是“把 constant-slot tail_call 变成 direct jump”。**  
   这件事 upstream x86 已经在做。真正的新机会是：**把原本动态索引的 tail-call site，特化成 monomorphic/oligomorphic fast path**，让 verifier/JIT 复用已有的 direct-tail-call 机制。

3. **Corpus 中 tail_call 并不罕见，但机会分两类。**  
   2026-03-26 快照下，`corpus/build/**/*.bpf.o` 共 568 个对象，其中 31 个对象含 tail call，总计 537 个 tail-call helper site。Cilium、Tetragon、Tracee、Calico、Katran 都在用。  
   但其中相当一部分是 Tetragon/Katran/Cilium internal 这类“常量 stage index”流水线，它们在 x86 上很可能已经吃到 direct patch；真正剩余的增量机会集中在 **动态 key 但运行期高度偏态** 的 site。

4. **BpfReJIT phase 1 最可行的实现，不应由 daemon 直接缓存 JIT 地址，而应做“guarded constant-key specialization”。**  
   也就是把
   `tail_call(ctx, map, idx)`  
   改成
   `if (idx == hot_key) tail_call(ctx, map, CONST_hot_key); else tail_call(ctx, map, idx);`
   让 fast path 重新落入内核现有的 direct-tail-call poke 体系。这样 correctness 由 kernel 的 `map_poke_run()` 负责，daemon 只负责决定何时 profile、何时 respecialize。

5. **“跨 tail_call 程序做 LTO” 是更强但更难的 phase 2。**  
   它确实有论文价值，但不能建立在“简单 bytecode inline”这种不严谨前提上。tail call 的语义包含“不返回”“重新进入新 prog frame”“受 `tail_call_cnt` 限制”；而 verifier 还明确限制 tail call 与 bpf-to-bpf call 的组合。  
   结论是：**phase 1 做 dynamic-site inline-cache；phase 2 再讨论 tail-transfer IR/kinsn 与 chain fusion。**

## 1. 调研范围与问题重述

本文基于当前仓库中的 Linux 内核树与 corpus 快照，回答以下问题：

1. Linux 现在如何实现 `BPF_MAP_TYPE_PROG_ARRAY + bpf_tail_call()`？
2. 真实 corpus 中，tail_call 到底有多常见，哪些项目在用？
3. 如果要把 tail_call 做成 BpfReJIT 的 runtime specialization，最合理的实现落点在哪里？
4. 哪些收益是 phase 1 就能拿到的，哪些收益属于更远的 phase 2？

本文的核心边界是：

- **基线以当前 `vendor/linux-framework` x86 JIT 为准。**
- **实现建议以 BpfReJIT 现有 daemon + REJIT kernel 基础设施为准。**
- **论文新意必须与 upstream 现有 direct-tail-call patching 区分开。**

## 2. BPF tail_call 机制与内核实现

### 2.1 UAPI 语义：`PROG_ARRAY` + non-returning tail transfer

`bpf_tail_call()` 的用户态语义在 UAPI 注释中写得很清楚：它从 `BPF_MAP_TYPE_PROG_ARRAY` 里按 key 取目标程序；成功时立刻开始执行目标程序第一条指令，不返回到原程序；失败时调用点后续指令继续执行。`MAX_TAIL_CALL_CNT` 当前为 33。参见：

- `vendor/linux-framework/include/uapi/linux/bpf.h:2190-2205`

这一定义决定了后续 specialization 的三个语义约束：

1. **tail call 不是普通函数调用。**
2. **失败必须 fall through，而不是 trap。**
3. **计数限制必须被严格保留。**

### 2.2 解释器实现：`tail_call_cnt`、边界检查与跳转

解释器主循环在 `vendor/linux-framework/kernel/bpf/core.c` 中维护 `u32 tail_call_cnt = 0`。对应的 `JMP_TAIL_CALL` 分支做了以下事情：

1. 检查 `index >= array->map.max_entries`
2. 检查 `tail_call_cnt >= MAX_TAIL_CALL_CNT`
3. `tail_call_cnt++`
4. `prog = READ_ONCE(array->ptrs[index])`
5. 若 `prog != NULL`，把 `insn` 指针切换到 `prog->insnsi`

参见：

- `vendor/linux-framework/kernel/bpf/core.c:1772`
- `vendor/linux-framework/kernel/bpf/core.c:2053-2078`
- `vendor/linux-framework/kernel/bpf/core.c:3046-3056`

这里有两个实现层面的重要观察：

1. **tail call 计数是解释器/JIT 共有的运行时合同，不是 verifier 里随便删掉的静态限制。**
2. **成功跳转的本质是“切换执行入口”，不是“call 后再 return”。**

### 2.3 verifier：helper `call 12` 会被重写成特殊 opcode

这是理解 specialization 设计空间的关键一步。

在 verifier 中，若识别到 `BPF_FUNC_tail_call`，会：

1. 把该 helper 标记为特殊 opcode：`insn->code = BPF_JMP | BPF_TAIL_CALL`
2. 清零 `insn->imm`
3. 若当前 site 的 map 指针和 key 在 verifier 看来都是“可立即数化”的，并且程序会走 JIT，则为其建立 `BPF_POKE_REASON_TAIL_CALL` 描述符
4. 将 `insn->imm = ret + 1`，供 x86 JIT 选择 direct-tail-call emission

参见：

- `vendor/linux-framework/kernel/bpf/verifier.c:24132-24171`

更具体地说，verifier 把 `tail_call.map` 和 `tail_call.key` 填进了 `poke_tab`：

- `vendor/linux-framework/kernel/bpf/verifier.c:24157-24160`

这意味着：

1. **upstream direct-tail-call 的触发条件不是“map 内容稳定”，而是“site 的 map 与 key 对 verifier 来说是静态常量”。**
2. **如果 BpfReJIT 想复用内核现有 fast path，最自然的办法不是自己缓存 target JIT 地址，而是把动态 site 变成“guarded constant-key site”。**

### 2.4 x86 JIT：间接路径 vs direct-patched 路径

#### 2.4.1 间接路径

`emit_bpf_tail_call_indirect()` 生成的逻辑基本就是：

1. 检查 `index < max_entries`
2. 检查 `tail_call_cnt < MAX_TAIL_CALL_CNT`
3. 从 `array->ptrs[index]` 取 `prog`
4. 若 `prog != NULL`，自增 `tail_call_cnt`
5. 取 `prog->bpf_func + X86_TAIL_CALL_OFFSET`
6. 通过 `emit_indirect_jump()` 跳过去

参见：

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:742-842`

`emit_indirect_jump()` 本身会根据内核缓解状态选择：

- ITS static thunk
- `LFENCE + indirect jump`
- retpoline thunk
- 或无缓解的原生 indirect jump

参见：

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:698-723`
- `https://docs.kernel.org/admin-guide/hw-vuln/indirect-target-selection.html`

内核官方 ITS 文档还明确写到：**eBPF 程序中的间接分支目前一律替换为跳向静态 ITS thunk**。这说明在受 Spectre/ITS 影响的内核上，generic indirect tail_call 的成本不只是一次普通的间接分支，而是带 mitigation 的间接控制转移。

#### 2.4.2 direct-tail-call 路径

当 `insn->imm != 0` 时，x86 JIT 走 `emit_bpf_tail_call_direct()`：

- 仍然检查 `tail_call_cnt`
- 为该 site 记录 `tailcall_bypass` / `tailcall_target` / `adj_off`
- 先发一个 bypass jump
- 再留下可 patch 的 NOP slot

JIT 完成后，`bpf_tail_call_direct_fixup()` 会：

1. 查 `array->ptrs[key]`
2. 若 target 存在，把 NOP patch 成 `jmp target->bpf_func + adj_off`
3. 再把 bypass jump patch 回 NOP
4. 最后把 `tailcall_target_stable` 设成 true

参见：

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:844-899`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:901-937`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2503-2517`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3922`

这里的结论非常重要：

1. **Linux x86 已经拥有“静态 monomorphic tail-call site -> direct JMP”的优化。**
2. **它不是 daemon 观察出来的 runtime stability，而是 verifier 已知常量 key 的 direct patch。**
3. **如果论文声称“我们发现 stable prog_array，于是把 indirect tail_call 变成 direct JMP”，必须先把 upstream constant-key fast path 扣掉。**

### 2.5 map 更新时的 repatch：kernel 已有 target-side 正确性机制

`prog_array_map_poke_run()` 会遍历引用该 `PROG_ARRAY` 的所有 `poke_tab`，对匹配 `(map, key)` 的 tail-call site 执行 `bpf_arch_poke_desc_update()`。也就是说，**当 prog_array 某个 slot 改变 target 时，内核已经知道如何把 direct-tail-call site 从旧 target repatch 到新 target**。

参见：

- `vendor/linux-framework/kernel/bpf/arraymap.c:1050-1154`

另外，用户态对 `PROG_ARRAY` 做 `BPF_MAP_LOOKUP_ELEM` 时，返回的是 **target prog ID**，不是内核指针：

- `vendor/linux-framework/kernel/bpf/arraymap.c:1007-1010`
- `vendor/linux-framework/kernel/bpf/arraymap.c:880-890`

这对 daemon 很有价值：**如果未来需要做 slot-level dependency tracking，用户态可以直接 snapshot `(map_id, key) -> prog_id`。**

### 2.6 BpfReJIT 当前已具备的 tail_call REJIT 支撑

本仓库内核树已经把 REJIT 与 tail_call poke 结合起来了：

- `bpf_prog_rejit_supported()` 明确写着 `poke_tab (tail_call direct jumps) is now supported`
- `bpf_prog_rejit_update_poke_tab()` 会把新镜像上的 `tailcall_target` / `tailcall_bypass` 地址回填到旧 `poke_tab`
- `bpf_prog_rejit_poke_target_phase()` 在 swap 前后做两阶段 NOP/JMP 切换，保证 target 程序 REJIT 时 caller 的 direct edge 不会悬空

参见：

- `vendor/linux-framework/kernel/bpf/syscall.c:3167-3200`
- `vendor/linux-framework/kernel/bpf/syscall.c:3218-3282`
- `vendor/linux-framework/kernel/bpf/syscall.c:3302-3370`
- `vendor/linux-framework/kernel/bpf/syscall.c:3372-3486`
- `vendor/linux-framework/kernel/bpf/syscall.c:3524-3562`
- `vendor/linux-framework/kernel/bpf/syscall.c:3769-3798`
- `tests/unittest/rejit_tail_call.c`

但这里有一个非常实在的限制：

`bpf_prog_rejit_update_poke_tab()` 当前要求 **old/new `poke_tab` 的大小、insn_idx、map、key 完全一致**，否则直接 `-EINVAL`。

这意味着：

1. **当前 REJIT 基础设施能安全交换“同一套 tail-call poke pattern 的新旧版本”。**
2. **如果 BpfReJIT 想把一个原本动态的 site 改造成“多一个 fast path 的 specialized 版本”，`poke_tab` 结构就会变化，现有代码会拒绝。**
3. **因此，phase 1 若要做真正的 dynamic tail-call specialization，kernel 侧首先要把“identical poke pattern only”放宽成“structural poke delta supported”。**

## 3. Corpus 数据：tail_call 在真实对象里到底有多少

### 3.1 统计方法

统计分两层：

1. **object 级总量**  
   基于已生成的 `docs/tmp/20260326/corpus_call_statistics_20260326.json` 与同目录 markdown 摘要。

2. **程序/函数级 attribution**  
   额外对 `corpus/build/**/*.bpf.o` 做 ELF 指令级扫描，把 `code=0x85, src_reg=0, imm=12` 的 helper 调用归入对应 `STT_FUNC` 符号区间。  
   object 总数与 helper 总数与已生成 JSON 对齐，均为 **31 个对象、537 个 tail-call helper site**。

注意：

- Cilium 这类对象里有大量 `STB_LOCAL` 的 tail fragment，所以**只看 GLOBAL 函数会低估**。
- 下面的项目/对象总量以 object 级计数为准；“代表性程序”表主要用于展示结构分布，不是说其余函数没有 tail call。

### 3.2 全局结果

2026-03-26 corpus 快照下：

- `.bpf.o` 总数：**568**
- 含 tail_call 的对象数：**31**
- tail_call helper 总数：**537**
- 对象覆盖率：**5.46%**

虽然对象占比不高，但分布高度集中，说明这是一个**局部高密度优化面**。

### 3.3 按项目汇总

| 项目 | 含 tail_call 的对象数 | tail_call site 总数 | 备注 |
|---|---:|---:|---|
| Cilium | 3 | 216 | corpus 中最密集 |
| Tetragon | 9 | 118 | 大量 staged pipeline |
| linux-selftests | 5 | 57 | 语义覆盖，不代表生产分布 |
| Calico | 8 | 55 | 明确使用 tail_call |
| Tracee | 1 | 49 | 动态 syscall/event arrays |
| Loxilb | 2 | 34 | TC pipeline |
| opentelemetry-ebpf-profiler | 2 | 5 | 少量 |
| Katran | 1 | 3 | 小型 root dispatch |

直接回答用户问题：

- **Cilium：是，且很多。**
- **Katran：是。**
- **Calico：是。**
- 另外 **Tetragon、Tracee、Loxilb、OTel profiler、linux selftests** 也在用。

### 3.4 Top objects

| 对象 | tail_call 数 |
|---|---:|
| `corpus/build/cilium/bpf_lxc.bpf.o` | 129 |
| `corpus/build/cilium/bpf_overlay.bpf.o` | 58 |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_flow.bpf.o` | 53 |
| `corpus/build/tracee/tracee.bpf.o` | 49 |
| `corpus/build/cilium/bpf_xdp.bpf.o` | 29 |
| `corpus/build/tetragon/bpf_generic_kprobe.bpf.o` | 20 |
| `corpus/build/tetragon/bpf_generic_uprobe.bpf.o` | 20 |
| `corpus/build/loxilb/llb_ebpf_emain.bpf.o` | 17 |
| `corpus/build/loxilb/llb_ebpf_main.bpf.o` | 17 |
| `corpus/build/tetragon/bpf_generic_rawtp.bpf.o` | 16 |

### 3.5 代表性项目解读

#### 3.5.1 Cilium：internal calls 与 policy arrays 并存

Cilium 的 tail-call 架构可以分成两类：

1. **`cilium_calls`**  
   私有 per-endpoint internal prog array，注释明确说 pin 会在对象重载时替换，旧 pinned map 不复用。  
   参见：
   - `runner/repos/cilium/bpf/lib/tailcall.h:104-137`

2. **`cilium_call_policy` / `cilium_egresscall_policy`**  
   以 endpoint_id 为 key 的 policy prog array，既有 static 也有 dynamic 调用路径。  
   参见：
   - `runner/repos/cilium/bpf/lib/local_delivery.h:15-55`

Corpus 中：

- `bpf_lxc.bpf.o`：129 个 tail calls  
  代表性 GLOBAL 函数：`tail_srv6_decap(7)`、`cil_to_container(6)`、`cil_from_container(4)`
- `bpf_overlay.bpf.o`：58 个  
  代表性函数：`tail_handle_ipv6(9)`、`tail_handle_ipv4(7)`、`cil_from_overlay(4)`
- `bpf_xdp.bpf.o`：29 个  
  代表性函数：`cil_xdp_entry(4)`、`tail_lb_ipv4(4)`、`tail_lb_ipv6(4)`

观察：

1. **Cilium internal `cilium_calls` 很像“稳定的 load-epoch static dispatch graph”。**
2. **但其中不少 site 已经是常量 key，x86 baseline 已经可能 direct patch。**
3. **真正值得做 dynamic specialization 的，是 policy 类 dynamic key site。**

也就是说，Cilium 同时提供了：

- 一个“constant-slot baseline 已经不错”的例子
- 一个“dynamic-key 仍有 PIC 空间”的例子

#### 3.5.2 Katran：root dispatch 很小，很稳定

Katran 的 `xdp_root()` 对 `root_array` 的 3 个 slot 逐个尝试 tail call：

- `runner/repos/katran/katran/lib/bpf/xdp_root.c:20-36`

Corpus 中：

- `katran/xdp_root.bpf.o`：3 个 tail calls
- 函数级：`xdp_root(3)`

这是典型的**小常量 dispatch fanout**。  
如果 loop 已经被编译器完全展开，那么这些 site 在 x86 上大概率已经满足 direct-tail-call 条件。

因此 Katran 更像：

- **“upstream 已有优化能吃到的下界案例”**
- 而不是 BpfReJIT dynamic specialization 的最好新意来源

#### 3.5.3 Tetragon：大量 tail calls 是“历史 instruction-budget 工程化”结果

Tetragon 的多条 pipeline 都通过预初始化的 prog array 分段：

- `runner/repos/tetragon/bpf/process/bpf_generic_kprobe.c:29-50`
- `runner/repos/tetragon/bpf/process/generic_calls.h:668-677`
- `runner/repos/tetragon/bpf/process/bpf_execve_event.c:326,341`

更重要的是，源码自己写得很直白：

- `runner/repos/tetragon/bpf/process/bpf_generic_kprobe.c:84-86`  
  对 4.19 kernel 需要用 tail call 把程序压到 4k insns 以下；对 5.x+ / 1M insn verifier 已不再是硬限制。

Corpus 中：

- `bpf_generic_kprobe.bpf.o`：20
- `bpf_generic_uprobe.bpf.o`：20
- `bpf_generic_rawtp.bpf.o`：16
- `bpf_generic_tracepoint.bpf.o`：15
- `bpf_generic_usdt.bpf.o`：15
- `bpf_generic_lsm_core.bpf.o`：12

这类 site 的意义在于：

1. **很多是常量 stage index，direct-edge elimination 本身未必还有大空间。**
2. **但它们是最像“人工切开的可融合 pipeline”的对象，因此 phase 2 的 cross-tail-call fusion/LTO 在 Tetragon 上最有故事。**

#### 3.5.4 Tracee：动态 syscall/event arrays，最像 runtime inline-cache 场景

Tracee 定义了多张 `PROG_ARRAY`：

- `prog_array`
- `prog_array_tp`
- `sys_enter_tails`
- `sys_exit_tails`
- `generic_sys_enter_tails`
- `generic_sys_exit_tails`
- `sys_enter_submit_tail`
- `sys_exit_submit_tail`

参见：

- `runner/repos/tracee/pkg/ebpf/c/maps.h:168-240`
- `runner/repos/tracee/pkg/ebpf/c/tracee.bpf.c:58,128,131,177,197,255,258,295,...`

Corpus 中：

- `tracee/tracee.bpf.o`：49 个 tail calls
- 代表性函数：`sys_enter_init(2)`、`sys_exit_init(2)`、`lkm_seeker_mod_tree_tail(2)`、`lkm_seeker_modtree_loop(2)`，其余大量函数各 1 个

这和 Tetragon 不同：

1. **Tracee 的 key 往往是 syscall id / event id / feature id，天然更动态。**
2. **这类 site 不容易被“静态 constant-key”覆盖。**
3. **如果 workload 热点集中在少数 syscall/event，上层逻辑就很适合做 monomorphic/oligomorphic inline cache。**

所以从论文新意上看，Tracee 比 Katran/Tetragon 更像 phase 1 的 target workload。

#### 3.5.5 Calico：明确在用，但源代码树不在当前仓库

当前仓库里没有完整 Calico BPF 源树，但 build artifact 足以证明其使用 tail call：

- `from_hep_debug.bpf.o`：13
- `to_hep_debug.bpf.o`：10
- `to_nat_debug.bpf.o`：10
- `from_nat_debug.bpf.o`：9
- `from_wep_debug.bpf.o`：6
- `to_wep_debug.bpf.o`：5
- `xdp_debug.bpf.o`：1
- `xdp_no_log.bpf.o`：1

函数级分布也很清晰：

- `calico_tc_main`
- `calico_tc_skb_accepted_entrypoint`
- `calico_tc_host_ct_conflict`
- `calico_tc_maglev`
- `calico_xdp_main`

因此对“Calico 到底有没有用 tail call”这个问题，答案是**明确用了**。

## 4. 现有工作已经覆盖了什么，剩余机会在哪里

### 4.1 Upstream 已经覆盖的子集：constant-key tail_call

如果一个 tail-call site 在 verifier 看来：

- map 是常量 `PROG_ARRAY`
- key 也是可立即数化的常量

那么 verifier 会为其建立 `poke_tab`，x86 JIT 会走 `emit_bpf_tail_call_direct()`，最终变成 direct JMP。

这意味着以下对象里的大量 site，**很可能已经被 upstream x86 baseline 优化过**：

- Katran `root_array`
- Tetragon staged pipelines
- Cilium 内部 `tail_call_static(...)` 路径
- 一部分 selftests

因此：

1. **如果论文只报告“我们把这些 site 变成 direct tail jump，所以更快”，说服力不够。**
2. **baseline 必须是当前 upstream/direct-tail-call-enabled kernel，而不是“所有 tail calls 都是 generic indirect helper”的虚拟基线。**

### 4.2 真正剩余的机会：dynamic-key, but biased

剩余空间主要在以下 site：

1. **map 常量，但 key 动态**
2. **运行期只命中 1 个或少数几个 key**
3. **generic path 仍然要走 indirect tail-call 慢路径**

这就是最典型的 monomorphic / oligomorphic inline-cache 场景。

可以把 tail-call specialization 的候选 site 分成四类：

| 类别 | 例子 | upstream 当前状态 | BpfReJIT 机会 |
|---|---|---|---|
| S0: static constant-key | Katran root array, Tetragon stages | x86 常已 direct patch | 主要作 baseline，不是新意 |
| S1: dynamic-key monomorphic | 某些 Cilium policy / Tracee 热 syscall site | 仍走 generic | **phase 1 最佳目标** |
| S2: dynamic-key oligomorphic | 少数 key 热点轮换 | 仍走 generic | phase 1.5 可做小型 PIC |
| S3: 高度多态/高 churn | 大量 syscall/event 均匀分布 | generic 更稳 | 不宜特化 |

### 4.3 “稳定的 prog_array”不是正确粒度；正确粒度是“稳定的 site+slot”

用户任务里提到“观察 prog_array 内容稳定”。  
更精确地说，BpfReJIT 不应以“整张 map 稳定”为判据，而应以：

- **site 粒度**
- **slot 粒度**
- 必要时再加 **key-profile 粒度**

作为 specialization 判据。

因为：

1. 一张 `PROG_ARRAY` 可以有几十上百个 slot，稳定性完全不同。
2. 一个 site 只关心自己会命中的少数 key，不关心整个 map。
3. Phase 1 真正要缓存的是“hot key”而不是“整个 map 不变”。

所以正确的 dependency key 应该是：

- `phase 1`: `(prog_id, insn_idx) -> hot_key_set`
- `phase 2`: `(map_id, key) -> target_prog_id`

而不是“某张 prog_array 是否整体不变”。

## 5. Specialization 方案：推荐设计与不推荐设计

### 5.1 不推荐设计：daemon 直接缓存 target JIT 地址并自己维护 direct edge

从工程上说，这是错误抽象。

原因有三：

1. **kernel 已经有 `map_poke_run()` 与 `tailcall_target_stable` 体系。**
2. **kernel 已经知道如何在 map update、prog free、REJIT swap 时安全 repatch direct edge。**
3. **daemon 自己缓存 JIT 地址，会把 text patch、一致性窗口、target 生命周期这些最脆弱的问题重新做一遍。**

换句话说：

**BpfReJIT 最好的 role 不是“替 kernel 管 direct JMP 的地址”，而是“把 site 改写成 kernel 能继续 direct patch 的形状”。**

### 5.2 推荐设计：guarded constant-key specialization

这是本文最推荐的 phase 1。

假设原始逻辑是：

```c
tail_call(ctx, &map, idx);
return FALLBACK;
```

若 profiling 发现此 site 绝大多数时间只命中 `idx == 17`，则 REJIT 后变成：

```c
u32 idx_saved = idx;

if (idx_saved == 17) {
    tail_call(ctx, &map, 17);   // constant-key fast path
}

tail_call(ctx, &map, idx_saved); // generic slow path
return FALLBACK;
```

其关键点不是“自己生成 `jmp target`”，而是：

1. fast path 上的 key 已经是常量
2. verifier 可以重新为这个新 site 建 `poke_tab`
3. x86 JIT 会自动把该 fast path 变成 direct-tail-call site
4. 如果 `(map,17)` 的 target 以后变化，kernel 的 `map_poke_run()` 会自动 repatch

因此，这个方案的优点是：

1. **bytecode 层实现，符合 BpfReJIT 体系**
2. **复用 kernel 正确性机制**
3. **无需 daemon 追踪 target 地址**
4. **即便 slot target 变化，也仍然语义正确**

### 5.3 这就是 tail-call 版本的 monomorphic inline cache

和 JVM / Self 里的 inline cache 类比时，应当明确：

- 这里 cache 的不是“对象类型 -> 方法地址”
- 而是“tail-call site 的 hot key -> constant-key direct-tail-call fast path”

如果继续扩展到两三个热点 key，就变成 oligomorphic PIC：

```c
u32 idx_saved = idx;

if (idx_saved == k1)
    tail_call(ctx, &map, k1);
if (idx_saved == k2)
    tail_call(ctx, &map, k2);
if (idx_saved == k3)
    tail_call(ctx, &map, k3);

tail_call(ctx, &map, idx_saved);
return FALLBACK;
```

这与 JumpSwitches/indirect-call promotion 的共同点是：

1. 先用 cheap compare 判定热点 target/key
2. 命中时走 direct 分支
3. 未命中时保留 generic fallback

### 5.4 发现 stable site：需要的是 key profile，不只是 map snapshot

这里必须说清楚一个研究陷阱：

**只观察 prog_array 当前内容，无法判断某个 dynamic site 会不会稳定命中某个 key。**

因为 map snapshot 只能告诉你：

- 哪些 key 存在
- 每个 key 目前对应哪个 prog_id

却不能告诉你：

- 这个 site 运行时到底更常见 `idx=3` 还是 `idx=17`

因此 phase 1 需要一层 **site-local key profiling**。最现实的方案有两种：

1. **短时 profile 版 REJIT**
   - 对候选 hot prog 临时插桩
   - 记录 `(site_id, idx)` 频次
   - 观察窗口结束后再 REJIT 成最终 specialized 版本

2. **采样式 profile**
   - 对 tail-call site 做低频采样
   - 记录 heavy hitter key

在当前仓库里，第一种更契合现有能力：

- daemon 已经能 REJIT
- 已经能按 prog hotness 排序
- 只差 tail-call-site analysis 与 profile-state machine

### 5.5 与 current daemon 架构的结合点

仓库里已有两块基础设施可以直接复用：

1. `daemon/src/bpf.rs`
   - 可取 `prog_info`
   - 可取 `map_ids`
   - 可按 `map_id` 打开 map fd
   - 可做 `BPF_MAP_LOOKUP_ELEM`

   参见：
   - `daemon/src/bpf.rs:106-120`
   - `daemon/src/bpf.rs:483-567`
   - `daemon/src/bpf.rs:693-743`

2. `MapInfoAnalysis`
   - 已能从重写前 bytecode 找到 map 引用并解析 live map metadata

   参见：
   - `daemon/src/analysis/map_info.rs:109-190`

这意味着 tail-call specialization 不缺 syscall plumbing，缺的是：

1. `TailCallSiteAnalysis`
2. `TailCallProfileController`
3. `SpecializationStateMachine`
4. `Dependency DB`

### 5.6 `watch` 逻辑必须改：不能“一次优化后永不再看”

当前 `cmd_watch()` 会把成功优化过的 prog 放进 `optimized: HashSet<u32>`，以后永不重访：

- `daemon/src/server.rs:176-179`
- `daemon/src/server.rs:202-210`
- `daemon/src/server.rs:222-226`

这与 dynamic specialization 根本不兼容。

前一份 dynamic map inlining 设计文档已经把这个问题说透了：

- pass 只做“给定 snapshot 的 bytecode rewrite”
- runtime controller 负责“何时 specialize / deopt / respecialize”

参见：

- `docs/tmp/20260324/dynamic_map_inlining_design_20260324.md:524-556`
- `docs/tmp/20260324/dynamic_map_inlining_design_20260324.md:558-571`

tail-call specialization 应完全复用这套分层：

- `apply-all`: 不支持 dynamic tail-call specialization
- `watch/serve`: 支持，并维护 specialization state machine

### 5.7 Kernel 侧需要的最小增量：放宽 `poke_tab` 结构不变假设

这是 phase 1 真正的 kernel blocker。

当前 REJIT 路径要求 old/new `poke_tab` shape 一样。  
但 dynamic specialization 一旦给 dynamic site 新增 fast path，`poke_tab` 条目就会变化。

因此必须把：

- “only identical poke pattern”

放宽成：

- “allow old/new poke_tab differ; untrack old entries, install new entries, then publish new image”

从现有代码看，这不是从零开始：

1. map `poke_track/untrack/run` 机制已经有
2. target-side two-phase NOP/JMP 机制已经有
3. 缺的是 **structural delta install**

也就是说，现有 kernel 不需要重写，只需要把当前“同形态交换”的支持扩成“新旧 poke set 可不同”。

## 6. Deopt / invalidation：phase 1 与 phase 2 应区别对待

### 6.1 Phase 1：guarded constant-key fast path 的 correctness 主要由 kernel 负责

如果 specialized fast path 只是“把 hot key 变成 constant-key tail call”，那么：

1. `(map,key)` 的 target 改变时
2. kernel 会通过 `map_poke_run()` repatch direct edge
3. specialized prog 仍然是语义正确的

因此 phase 1 的 daemon 不必在“slot target 变化”时做 correctness-driven deopt。  
它只需要在以下情况 **performance-driven respecialize**：

1. hot key 漂移
2. site 从 monomorphic 变成 polymorphic
3. miss rate 过高

这是一个非常关键的工程结论：

**phase 1 的 invalidation 重点不是“target 变了就必须退化”，而是“profile 漂了就该重选 hot key”。**

### 6.2 Phase 2：如果要做 chain fusion / LTO，才需要严格 slot dependency invalidation

一旦走到 phase 2，例如：

- 把跨 tail-call 的链融合成一个特殊 IR
- 或引入 tail-transfer kinsn
- 或做跨 prog constprop / DCE

这时 specialized artifact 就和“当前 slot target 是谁”直接绑定了。  
此时才需要严格维护：

- `(map_id, key) -> target_prog_id`

并在变化时做：

1. deopt 回 generic 版本
2. 或按新 target 重新 REJIT

好消息是，这个 dependency snapshot 在用户态完全可做：

1. `bpf_prog_get_map_ids()` 取出程序依赖 map
2. 过滤 `BPF_MAP_TYPE_PROG_ARRAY`
3. 对候选 `key` 做 `BPF_MAP_LOOKUP_ELEM`
4. 读取返回的 `prog_id`

因为 `PROG_ARRAY` 的 syscall lookup 返回的就是 `prog->aux->id`。

### 6.3 推荐的 invalidation backend

推荐分两层：

1. **v1: polling backend**
   - 最简单
   - daemon 周期性读取依赖 slot 的 `prog_id`
   - 与 `watch/serve` 架构一致

2. **v2: event backend**
   - 在 `prog_array_map_update/delete` 或 `map_poke_run()` 路径上提供变更通知
   - 减少轮询开销与反应延迟

论文原型阶段，v1 足够。

## 7. 收益分析：什么收益是现在就能拿到的

### 7.1 Direct-edge elimination 的收益

generic indirect tail_call 的成本包括：

1. `index < max_entries` 检查
2. `tail_call_cnt` 检查
3. 读取 `array->ptrs[index]`
4. 检查 `prog != NULL`
5. 取 `prog->bpf_func`
6. 一次带 mitigation 的 indirect jump

而 direct-tail-call path 主要保留：

1. `tail_call_cnt` 检查
2. 必要的 bypass/fallthrough 结构
3. 最终 direct jump

因此 fast path 至少能消掉：

- map slot 读取与 `prog` 判空
- `prog->bpf_func` 取址
- indirect-branch mitigation

在 Spectre-mitigated kernel 上，这部分收益通常不是个位数 cycles。  
工程上常见的保守估算是 **20-40 cycles**；JumpSwitches 则报告 retpoline 相关开销在某些场景可达 **约 70 cycles**，而且还可能造成显著总体 slowdown。

参见：

- `https://www.usenix.org/system/files/atc19-amit.pdf`

### 7.2 Guarded monomorphic fast path 的 break-even 很低

若 fast path 只额外增加：

- 1 个 compare
- 1 个前向条件跳转

那么其 steady-state 额外成本通常只有几 cycles。  
假设 direct-edge 相对 indirect-edge 保守节省 25 cycles，则命中率只要超过约 8% 就接近 break-even；若节省 35 cycles，则门槛更低。

所以真正的问题不是“guard 本身会不会太贵”，而是：

1. **能不能找到 hit rate 足够高的 hot key**
2. **代码膨胀是否可控**
3. **respecialization 是否会 thrash**

### 7.3 哪些项目会从 phase 1 受益最大

#### 受益大

- **Tracee**  
  因为其动态 key 很多，upstream static direct patch 覆盖不了全部机会。

- **Cilium 的 dynamic policy sites**  
  尤其是 endpoint/policy 分发明显偏态的场景。

#### 受益中等

- **Calico**
  当前缺源码细粒度判断，但从对象级分布看，TC/XDP 主路径里确实有 tail-call dispatch。

#### 直接收益有限，但 phase 2 值得做

- **Tetragon**
- **Katran**

原因不是它们不重要，而是：

1. constant-key direct jump 很可能 baseline 已有
2. 真正的增量在 chain fusion / LTO，不在 direct-edge elimination

### 7.4 跨 tail_call LTO：收益很大，但不是白送的

从直觉上看，tail-call chain 若能融合，确实可以获得：

- 跨 prog 常量传播
- 死代码删除
- 分支简化
- 更少的寄存器/控制流边界

但这件事不能被简单地描述成“把 callee bytecode inline 到 caller”。

原因有三个：

1. **tail call 不返回**
2. **tail call 具有“进入新 prog frame”的语义**
3. **verifier 限制 tail_call 与 bpf-to-bpf call 的组合**

相关 verifier 约束见：

- `vendor/linux-framework/kernel/bpf/verifier.c:10612-10618`
- `vendor/linux-framework/kernel/bpf/verifier.c:19563-19565`

因此 phase 2 若要做得严谨，需要：

1. 新的 tail-transfer IR / kinsn
2. 或 kernel 明确支持“frame-reset-preserving inter-prog transfer”

在没有这层 IR 之前，论文里只能把 cross-tail-call LTO 写成**有前景的下一阶段，而不是 phase 1 主实现**。

## 8. 相关工作定位

### 8.1 Linux kernel 自身：已有 static direct-tail-call patching

这是最直接的 baseline，也是本文所有结论的前提。  
如果不先承认 upstream 已经优化 constant-key site，后面的论文定位会失真。

### 8.2 K2：编译期 BPF 优化，但未见 runtime tail-call specialization

K2 是面向 BPF 的 synthesis-based compiler，重点在 compile-time 的安全与性能搜索。  
我检索其公开论文 PDF，未发现 `tail call` / `tail-call` / `prog_array` 的专门讨论，因此**推断**它没有把 runtime tail-call specialization 作为独立对象。

这个结论是基于关键词检索后的负证据推断，而不是作者明示声明。

参考：

- `https://conferences.sigcomm.org/sigcomm/2021/files/papers/3452296.3472929.pdf`

### 8.3 Polymorphic Inline Caches：最贴切的概念类比

PIC 的启发不是“在编译期知道所有 target”，而是：

1. 在 call site 缓存 hot case
2. 让 hot case 走更便宜的 direct path
3. miss 时回退到通用路径
4. 再根据 profile 重新编译

Tail-call specialization phase 1 与它高度同构。

参考：

- `https://bibliography.selflanguage.org/pics.html`

### 8.4 JumpSwitches / indirect call promotion：最贴切的系统类比

JumpSwitches 的核心思想是：  
在 Spectre 时代，间接调用尤其昂贵，因此值得以少量 compare/branch 换 direct call fast path。

这几乎就是本文 phase 1 的系统版类比，只不过：

- JumpSwitches 的对象是普通 indirect call
- 本文对象是 eBPF tail call

参考：

- `https://www.usenix.org/system/files/atc19-amit.pdf`

### 8.5 工程实践：Cilium / Katran / Tetragon / Tracee

这些项目提供的不是“学术相关工作”，而是：

1. tail call 为什么会在真实项目里大量出现
2. 哪些是 constant-stage pipeline
3. 哪些是 dynamic dispatch
4. 哪些是历史 verifier 限制的产物

对论文定位很重要，因为它决定了：

- 评测应选谁
- baseline 应怎么设
- phase 1 与 phase 2 分别该讲什么故事

## 9. 对 BpfReJIT 的具体实现建议

### 9.1 Phase 1：dynamic-key monomorphic specialization

建议的最小闭环：

1. **新增 `TailCallSiteAnalysis`**
   - 扫描 `BPF_JMP | BPF_TAIL_CALL`
   - 识别 site 的 map 引用
   - 区分 constant-key / dynamic-key

2. **新增短时 profiling 模式**
   - 对候选热程序临时插桩
   - 记录 `(site_id, key)` heavy hitter

3. **新增 `tail_call_icache` pass**
   - 对 dynamic-key site 生成 1-way 或 2-way fast path
   - 保留 generic fallback

4. **修改 `watch/serve`**
   - 引入 specialization state machine
   - 支持 `generic -> profiled -> specialized -> respecialize`

5. **放宽 kernel REJIT 的 `poke_tab` shape check**
   - 允许新增/删除 constant-key fast path 的 poke entries

### 9.2 关键 policy

推荐 policy：

- `min_hotness`
- `min_stable_rounds`
- `max_poly_keys`
- `cooldown_rounds`
- `max_code_growth_pct`
- `disable_on_slot_churn`

其中：

- **`min_stable_rounds`** 用于避免 profile 抖动
- **`disable_on_slot_churn`** 用于过滤频繁改 target 的 slot
- **`max_code_growth_pct`** 防止多态展开把程序吹太大

### 9.3 Phase 2：tail-transfer IR / chain fusion

如果论文希望强调“跨 tail_call 程序做 LTO”，建议把它定义成 phase 2，并明确写成：

1. 需要新的中间表示，显式表达 non-returning tail transfer
2. 需要 verifier/JIT 能理解“frame reset + direct transfer”
3. 需要 slot-level dependency invalidation

在这个 phase 里，daemon 观察到的“stable prog_array contents”才真正直接参与 correctness。

### 9.4 不建议的捷径

以下路线不建议作为论文主线：

1. **直接在 daemon 里缓存 JIT 地址并自己 text patch**
2. **把 constant-key site 当成主要创新点**
3. **在没有新 IR 的前提下宣称已经实现跨 tail_call LTO**

这三条都容易被审稿人指出“要么 upstream 已有，要么语义没讲清楚”。

## 10. 最终判断

综合内核实现、corpus 分布与当前仓库状态，我的判断是：

1. **Tail-call specialization 是值得做的，但要把问题定义改准。**
   真正有论文价值的不是“stable prog_array -> direct JMP”，而是“dynamic tail-call site 的 inline-cache specialization”。

2. **Phase 1 应该明确聚焦 dynamic-key monomorphic/oligomorphic fast path。**
   这条路线与 BpfReJIT 的 bytecode REJIT 模型一致，也能最大化复用 kernel 现有的 direct-tail-call patching。

3. **Phase 2 才讨论 chain fusion / LTO。**
   这会是更强的结果，但也需要新的语义载体，不能混在 phase 1 里一起讲。

4. **当前仓库最现实的 blocker 不是“没有 map/prog introspection”，而是两点：**
   - 缺 site-local key profiling
   - REJIT 目前只支持 identical `poke_tab` shape

5. **若面向 OSDI '26 写法，建议把贡献表述为：**
   - 一个 runtime-observed tail-call inline-cache framework
   - 一个利用现有 kernel direct-tail-call poke 的 bytecode specialization strategy
   - 一个用于 dynamic specialization 的 watch/serve state machine
   - 一个对 cross-tail-call fusion 的 phase-2 设计

---

## 附录 A：含 tail_call 的对象与代表性程序

下表覆盖当前 corpus 中全部 31 个含 tail-call 的对象。

| Project | Object | tail_call 数 | 代表性程序（函数） |
|---|---|---:|---|
| cilium | `cilium/bpf_lxc.bpf.o` | 129 | tail_srv6_decap(7); cil_to_container(6); cil_from_container(4) |
| cilium | `cilium/bpf_overlay.bpf.o` | 58 | tail_handle_ipv6(9); tail_handle_ipv4(7); cil_from_overlay(4) |
| linux-selftests | `linux-selftests/tools/testing/selftests/bpf/progs/bpf_flow.bpf.o` | 53 | flow_dissector_1(12); flow_dissector_2(12); flow_dissector_3(12) |
| tracee | `tracee/tracee.bpf.o` | 49 | lkm_seeker_mod_tree_tail(2); lkm_seeker_modtree_loop(2); sys_enter_init(2) |
| cilium | `cilium/bpf_xdp.bpf.o` | 29 | cil_xdp_entry(4); tail_lb_ipv4(4); tail_lb_ipv6(4) |
| tetragon | `tetragon/bpf_generic_kprobe.bpf.o` | 20 | generic_kprobe_filter_arg(4); generic_kprobe_process_event(4); generic_kprobe_filter_arg_2(3) |
| tetragon | `tetragon/bpf_generic_uprobe.bpf.o` | 20 | generic_uprobe_filter_arg(4); generic_uprobe_process_event(4); generic_uprobe_filter_arg_2(3) |
| loxilb | `loxilb/llb_ebpf_emain.bpf.o` | 17 | tc_packet_func_slow(5); tc_csum_func1(2); tc_csum_func2(2) |
| loxilb | `loxilb/llb_ebpf_main.bpf.o` | 17 | tc_packet_func_slow(5); tc_csum_func1(2); tc_csum_func2(2) |
| tetragon | `tetragon/bpf_generic_rawtp.bpf.o` | 16 | generic_rawtp_filter_arg(4); generic_rawtp_filter_arg_2(3); generic_rawtp_process_event(3) |
| tetragon | `tetragon/bpf_generic_tracepoint.bpf.o` | 15 | generic_tracepoint_arg(4); generic_tracepoint_arg_2(3); generic_tracepoint_process_event(3) |
| tetragon | `tetragon/bpf_generic_usdt.bpf.o` | 15 | generic_usdt_filter_arg(4); generic_usdt_filter_arg_2(3); generic_usdt_process_event(2) |
| calico | `calico/from_hep_debug.bpf.o` | 13 | calico_tc_main(6); calico_tc_skb_accepted_entrypoint(3); calico_tc_maglev(2) |
| tetragon | `tetragon/bpf_generic_lsm_core.bpf.o` | 12 | generic_lsm_filter_arg(3); generic_lsm_process_event(3); generic_lsm_setup_event(2) |
| calico | `calico/to_hep_debug.bpf.o` | 10 | calico_tc_main(4); calico_tc_host_ct_conflict(3); calico_tc_skb_accepted_entrypoint(2) |
| calico | `calico/to_nat_debug.bpf.o` | 10 | calico_tc_main(4); calico_tc_host_ct_conflict(3); calico_tc_skb_accepted_entrypoint(2) |
| calico | `calico/from_nat_debug.bpf.o` | 9 | calico_tc_main(5); calico_tc_skb_accepted_entrypoint(3); calico_tc_skb_drop(1) |
| tetragon | `tetragon/bpf_generic_retkprobe.bpf.o` | 9 | generic_retkprobe_filter_arg(4); generic_retkprobe_filter_arg_2(3); generic_retkprobe_actions(1) |
| tetragon | `tetragon/bpf_generic_retuprobe.bpf.o` | 9 | generic_retuprobe_filter_arg(4); generic_retuprobe_filter_arg_2(3); generic_retuprobe_actions(1) |
| calico | `calico/from_wep_debug.bpf.o` | 6 | calico_tc_main(3); calico_tc_skb_accepted_entrypoint(3) |
| calico | `calico/to_wep_debug.bpf.o` | 5 | calico_tc_main(3); calico_tc_skb_accepted_entrypoint(2) |
| opentelemetry-ebpf-profiler | `opentelemetry-ebpf-profiler/native_stack_trace.bpf.o` | 4 | native_tracer_entry(2) |
| katran | `katran/xdp_root.bpf.o` | 3 | xdp_root(3) |
| tetragon | `tetragon/bpf_execve_event.bpf.o` | 2 | event_execve(1); execve_rate(1) |
| calico | `calico/xdp_debug.bpf.o` | 1 | calico_xdp_main(1) |
| calico | `calico/xdp_no_log.bpf.o` | 1 | calico_xdp_main(1) |
| linux-selftests | `linux-selftests/tools/testing/selftests/bpf/progs/lsm_tailcall.bpf.o` | 1 | lsm_kernfs_init_security_entry(1) |
| linux-selftests | `linux-selftests/tools/testing/selftests/bpf/progs/tailcall_bpf2bpf_hierarchy_fentry.bpf.o` | 1 | subprog_tail(1) |
| linux-selftests | `linux-selftests/tools/testing/selftests/bpf/progs/test_prog_array_init.bpf.o` | 1 | entry(1) |
| linux-selftests | `linux-selftests/tools/testing/selftests/bpf/progs/test_xdp_devmap_tailcall.bpf.o` | 1 | xdp_entry(1) |
| opentelemetry-ebpf-profiler | `opentelemetry-ebpf-profiler/generic_probe.bpf.o` | 1 | kprobe__generic(1) |

---

## 参考文献与源码入口

### 仓库内源码

- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `vendor/linux-framework/kernel/bpf/core.c`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/kernel/bpf/arraymap.c`
- `vendor/linux-framework/kernel/bpf/syscall.c`
- `daemon/src/server.rs`
- `daemon/src/bpf.rs`
- `daemon/src/analysis/map_info.rs`
- `docs/tmp/20260324/dynamic_map_inlining_design_20260324.md`
- `tests/unittest/rejit_tail_call.c`
- `docs/tmp/20260326/corpus_call_statistics_20260326.json`

### 外部资料

- Linux kernel ITS 文档：`https://docs.kernel.org/admin-guide/hw-vuln/indirect-target-selection.html`
- JumpSwitches（USENIX ATC 2019）：`https://www.usenix.org/system/files/atc19-amit.pdf`
- Polymorphic Inline Caches（Self bibliography）：`https://bibliography.selflanguage.org/pics.html`
- K2（SIGCOMM 2021）：`https://conferences.sigcomm.org/sigcomm/2021/files/papers/3452296.3472929.pdf`
