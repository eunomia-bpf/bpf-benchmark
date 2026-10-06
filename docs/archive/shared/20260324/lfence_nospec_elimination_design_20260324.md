# #433 LFENCE / BPF_NOSPEC 消除设计报告

日期：2026-03-24  
上下文：`docs/kernel-jit-optimization-plan.md`，`docs/tmp/20260323/comprehensive_optimization_survey_20260323.md` Section A

## 1. 结论摘要

这轮设计结论先说在前面：

1. 当前 corpus 的 live xlated census 里，**没有观测到任何一条 `BPF_ST_NOSPEC`**。在 `corpus/build/` 的 568 个 `.bpf.o` 里，278 个对象成功加载，导出了 861 个 xlated program；`BPF_ST_NOSPEC` 总数为 0，按项目和按 `prog_type` 聚合也全部为 0。原始统计见 `docs/tmp/20260324/lfence_nospec_census_20260324.json`。
2. 因为 `BPF_NOSPEC` 是 verifier/fixup 的 **post-load rewrite** 产物，不存在于 ELF 原文里，所以 daemon **不能**“直接删掉现有 xlated 里的 LFENCE”；它只能提交 **pre-fixup bytecode**，然后让 kernel 重新跑 `bpf_check()`，由 verifier 重新决定是否插 `BPF_ST_NOSPEC()`。
3. 因此，#433 的正确实现方式不是“barrier 删除器”，而是三类**前置重写**：
   - `bounds-window rewrite`
   - `typed stack overwrite reduction`
   - `variable ptr arithmetic rewrite`
4. `safe-load` 的正确方向也不是“盲目 mask 后访问”，而是 `bounds check + index_nospec/mask + access` 这种**显式 speculative contract**。这棵树里 tail call fixup 已经在这么做。
5. 由于 corpus 当前实测 `BPF_ST_NOSPEC = 0`，#433 的工程优先级应低于“已经在 corpus 里能看到收益”的 pass；但它仍然有设计价值，因为：
   - verifier 逻辑明确支持这类 barrier；
   - future corpus 或 microbench 可能出现 carrier；
   - 同一套分析框架还能同时吃到 `sanitize_ptr_alu()` 和 stack-spill 相关收益。

## 2. Corpus 统计：`corpus/build/` 的 live xlated `BPF_ST_NOSPEC`

### 2.1 统计口径

统计必须基于 **live xlated bytecode**，不能只扫 `.bpf.o` 原文，原因是：

- `BPF_ST_NOSPEC()` 的 opcode 是 `BPF_ST | BPF_NOSPEC`，也就是 `0xc2`，定义见 `vendor/linux-framework/include/linux/filter.h:87-90,519-524`。
- 这条指令不是 clang/libbpf 写进 ELF 的，而是 verifier 在 `convert_ctx_accesses()` 里根据 `aux->nospec` / `aux->nospec_result` 动态 patch 进去的，见 `vendor/linux-framework/kernel/bpf/verifier.c:23077-23163`。

因此本次统计方法是：

1. 在 VM 内实际 load `corpus/build/**/*.bpf.o`。
2. 用 `BPF_OBJ_GET_INFO_BY_FD` 读取 `before_xlated`。
3. 在 xlated dump 里数首字节为 `0xc2` 的指令。
4. 按 project / `prog_type` 聚合。

### 2.2 汇总结果

| metric | value |
|---|---:|
| objects_total | 568 |
| objects_ok | 278 |
| objects_skip_load | 290 |
| programs_total | 1151 |
| programs_with_xlated | 861 |
| programs_with_nospec | 0 |
| total_nospec_insns | 0 |

解读：

- 对象覆盖率按 object 算是 `278 / 568 = 48.9%`。
- 程序覆盖率按 program 算是 `861 / 1151 = 74.8%`。
- 在**所有成功导出 xlated** 的 861 个 program 里，`BPF_ST_NOSPEC` 总数为 **0**。
- `skip_load` 对象仍然是盲区，所以结论必须写成“当前 loadable 子集实测为 0”，不能扩大成“整个 corpus 永远没有 nospec”。

### 2.3 按项目聚合

| project | programs_total | programs_with_xlated | programs_with_nospec | total_nospec_insns | max_program_nospec |
|---|---:|---:|---:|---:|---:|
| linux-selftests | 620 | 424 | 0 | 0 | 0 |
| bcc | 233 | 209 | 0 | 0 | 0 |
| calico | 59 | 59 | 0 | 0 | 0 |
| coroot-node-agent | 46 | 46 | 0 | 0 | 0 |
| xdp-tutorial | 41 | 29 | 0 | 0 | 0 |
| scx | 27 | 25 | 0 | 0 | 0 |
| real_world_code_size | 23 | 21 | 0 | 0 | 0 |
| libbpf-bootstrap | 20 | 18 | 0 | 0 | 0 |
| tetragon | 27 | 15 | 0 | 0 | 0 |
| xdp-tools | 14 | 5 | 0 | 0 | 0 |
| katran | 5 | 5 | 0 | 0 | 0 |
| systemd | 8 | 3 | 0 | 0 | 0 |
| suricata | 2 | 1 | 0 | 0 | 0 |
| tracee | 2 | 1 | 0 | 0 | 0 |
| bpftrace | 5 | 0 | 0 | 0 | 0 |
| KubeArmor | 3 | 0 | 0 | 0 | 0 |
| cilium | 3 | 0 | 0 | 0 | 0 |
| loxilb | 3 | 0 | 0 | 0 | 0 |
| opentelemetry-ebpf-profiler | 3 | 0 | 0 | 0 | 0 |
| datadog-agent | 2 | 0 | 0 | 0 | 0 |
| manual-test | 2 | 0 | 0 | 0 | 0 |
| netbird | 2 | 0 | 0 | 0 | 0 |
| tubular | 1 | 0 | 0 | 0 | 0 |

### 2.4 按 `prog_type` 聚合

| prog_type | programs_total | programs_with_xlated | programs_with_nospec | total_nospec_insns | max_program_nospec |
|---|---:|---:|---:|---:|---:|
| kprobe | 206 | 206 | 0 | 0 | 0 |
| tracing | 178 | 178 | 0 | 0 | 0 |
| tracepoint | 128 | 128 | 0 | 0 | 0 |
| sched_cls | 100 | 100 | 0 | 0 | 0 |
| struct_ops | 51 | 51 | 0 | 0 | 0 |
| raw_tracepoint | 45 | 45 | 0 | 0 | 0 |
| xdp | 43 | 43 | 0 | 0 | 0 |
| syscall | 33 | 33 | 0 | 0 | 0 |
| perf_event | 16 | 16 | 0 | 0 | 0 |
| lsm | 14 | 14 | 0 | 0 | 0 |
| cgroup_sockopt | 9 | 9 | 0 | 0 | 0 |
| flow_dissector | 7 | 7 | 0 | 0 | 0 |
| sk_msg | 5 | 5 | 0 | 0 | 0 |
| sk_skb | 5 | 5 | 0 | 0 | 0 |
| sock_ops | 5 | 5 | 0 | 0 | 0 |
| cgroup_skb | 4 | 4 | 0 | 0 | 0 |
| cgroup_sock_addr | 3 | 3 | 0 | 0 | 0 |
| sk_reuseport | 3 | 3 | 0 | 0 | 0 |
| cgroup_sock | 2 | 2 | 0 | 0 | 0 |
| netfilter | 2 | 2 | 0 | 0 | 0 |
| cgroup_sysctl | 1 | 1 | 0 | 0 | 0 |
| socket_filter | 1 | 1 | 0 | 0 | 0 |
| unknown | 290 | 0 | 0 | 0 | 0 |

### 2.5 统计意义

这组数字有两个直接含义：

1. **当前 corpus 没有“高 NOSPEC 程序”可直接拿来做 barrier 删除收益证明。**
2. #433 必须写成一份**前瞻性设计报告**，而不是“现有热程序里已经有大量 LFENCE，只等删掉”的故事。

## 3. Verifier / REJIT 事实模型

### 3.1 `BPF_NOSPEC` 的真实来源

这棵树里的 `BPF_ST_NOSPEC()` 有两条来源：

1. `aux->nospec`
   - speculative verifier path 在某条指令上遇到 `-EPERM / -EACCES / -EINVAL` 这类“可通过 nospec 恢复”的错误时，把当前指令标成 `nospec = true`，见 `vendor/linux-framework/kernel/bpf/verifier.c:2116-2125,21837-21846`。
   - 后续 `convert_ctx_accesses()` 会在该指令**前面**插一条 `BPF_ST_NOSPEC()`，见 `vendor/linux-framework/kernel/bpf/verifier.c:23077-23096`。

2. `aux->nospec_result`
   - 在当前树里，唯一显式 setter 是 `check_stack_write_fixed_off()`：当一次 stack write 要么写入 spillable reg type，要么覆盖了非 `STACK_MISC/STACK_ZERO` 的 typed slot，便把当前写指令标成 `nospec_result = true`，见 `vendor/linux-framework/kernel/bpf/verifier.c:5721-5760`。
   - 后续 `convert_ctx_accesses()` 会在该 write **后面**插一条 `BPF_ST_NOSPEC()`，见 `vendor/linux-framework/kernel/bpf/verifier.c:23147-23163`。

落到执行端：

- 解释器把 `BPF_ST | BPF_NOSPEC` 派发到 `barrier_nospec()`，见 `vendor/linux-framework/kernel/bpf/core.c:1766-1768,2135-2147`。
- x86 JIT 把它降成 `LFENCE`，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:679,2134-2137`。
- arm64 JIT 把它降成 `SB` 或 `DSB NSH; ISB`，见 `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1778-1785`。

### 3.2 `sanitize_ptr_alu()` 与 `BPF_NOSPEC` 不是同一机制

`variable ptr arithmetic` 的 speculative hardening 主要不是 `LFENCE`，而是 `sanitize_ptr_alu()` 驱动的 masking 序列，见 `vendor/linux-framework/kernel/bpf/verifier.c:15052-15212,15331-15510`。

关键事实：

- `can_skip_alu_sanitation()` 在三种情况下跳过 masking：
  - `bypass_spec_v1`
  - 立即数 ALU
  - `cur_aux(env)->nospec`
- 也就是说，**删掉一个 `nospec` 触发条件，未必等于净减少 hardening**；它有可能让 verifier 改成插一段更长的 ALU mask window。

这点是 #433 最容易做错的地方。设计上必须比较的是**总 speculative hardening footprint**，而不是只比较 `LFENCE` 个数。

### 3.3 daemon 提交的是 pre-fixup bytecode，kernel 会重新决定是否插 barrier

答案是：**会重新决定。**

REJIT 路径里：

- `bpf_prog_rejit()` 先把用户提交的新 insn 拷进 `tmp->insns`，再拷一份到 `tmp->aux->orig_insns` / `orig_prog_len`，见 `vendor/linux-framework/kernel/bpf/syscall.c:3534-3545`。
- 然后它对这份新程序再次调用完整的 `bpf_check()`，见 `vendor/linux-framework/kernel/bpf/syscall.c:3601-3602`。
- `bpf_check()` 在验证成功后又会重新执行 `convert_ctx_accesses()` 和 `do_misc_fixups()`，见 `vendor/linux-framework/kernel/bpf/verifier.c:26638-26659`。

因此：

- daemon **不能**拿到一段“已经含 LFENCE 的 xlated”，把那几个 opcode 直接删掉再塞回去。
- daemon **只能**改写 pre-fixup bytecode，让 verifier 在第二次 `bpf_check()` 时：
  - 不再设置 `aux->nospec`
  - 不再设置 `aux->nospec_result`
  - 或者把原来的 barrier 型 hardening 变成 `sanitize_ptr_alu()` / `index_nospec` 这类更便宜的 hardening

这也意味着 #433 的实现天然是“kernel 作为 final oracle”的闭环，而不是用户态私自相信自己的静态分析。

## 4. 安全判断算法

### 4.1 总体策略

推荐把 #433 做成“三段式判定”：

1. **语法候选筛选**
   - 只在已知 pattern 上重写，不做全局任意变换。
2. **verifier-oracle 复验**
   - 让 kernel 重新跑 `bpf_check()`。
3. **收益门槛**
   - 只接受同时满足“语义不变”和“hardening 变少”的版本。

更具体地说，候选程序 `P'` 只有在以下条件同时成立时才接受：

- `bpf_check(P')` 成功；
- 回放输入上结果与 baseline 一致；
- `xlated(P')` 中 `BPF_ST_NOSPEC` 数量下降，或者虽然 `BPF_ST_NOSPEC` 不变，但总 hardening footprint（barrier + sanitizer）缩短；
- 没有引入新的 verifier rejection，也没有把 hot path 变成更长的 masking 序列。

下面分三类 pattern 给判定条件。

### 4.2 `bounds-window rewrite`

#### 目标

把“多次局部 bounds check + 紧随其后的访问”改成：

- 一个**支配整个 fast path** 的 widened bounds check
- 加一个 slow path fallback
- fast path 内部只保留 fixed-offset access

#### 适用场景

- packet parser / header walker
- 同一 base pointer 上的重复访问
- 多个访问都受同一个 `data_end` / map-value-size witness 保护

#### 必须同时满足的安全条件

1. **同源 base**
   - 所有候选访问都必须来自同一个 provenance：同一个 `data` / `pkt` / `map_value` base，不能混不同 ptr family。

2. **同一个 witness**
   - 所有 bounds proof 都必须对应同一个上界 witness，比如 `data_end` 或一个常量 map value size。

3. **一个 guard 能支配全部访问**
   - widened guard 必须在 CFG 上支配它保护的全部 memory op。
   - 不能存在从 guard 中间“跳进来”的边。

4. **guard 与 use 之间不能破坏事实**
   - guard 和最后一次 use 之间不能有会改变 base / end / packet layout 的 helper 或指令。
   - 典型禁止项：`bpf_xdp_adjust_head/tail`、`bpf_skb_change_tail`、可能改变 packet pointer 的 helper。

5. **window 必须连续**
   - 能把所有访问抽象成一个连续窗口 `[base + lo, base + hi)`。
   - 如果访问窗口不连续，但中间空洞过大，直接 widen 会造成无意义的过度检查，应放弃。

6. **fast path 不能改语义**
   - 若原程序在“包不够大”时会执行一部分访问再退出，则 widened 版本必须拆成：
     - fast path：足够大的常见输入，单 guard 后无局部 check
     - slow path：保留原来的逐步检查逻辑
   - 不能把“部分成功”粗暴改成“一次失败全退出”。

7. **访问在 fast path 内要变成 fixed-offset**
   - 如果 widened 之后 fast path 里仍然存在 `ptr += var` 之类的可变偏移，那 verifier 仍可能回到 `nospec` / sanitizer 路径，重写就没有意义。

#### 推荐判定算法

1. 找出形如 `if (base + k > end) goto slow; use(base + off)` 的重复片段。
2. 计算所有 use 的最小起点 `lo` 和最大终点 `hi`。
3. 生成 fast path guard：`if (base + hi > end) goto slow;`
4. fast path 内把各个 use 重写为固定窗口内的立即数偏移访问。
5. 保留 slow path 原逻辑。
6. 用 REJIT 再过一遍 verifier；若 xlated 里 hardening 不降，则撤销。

#### 何时直接拒绝

- guard 之后有 helper/call 会改变 packet layout；
- 内部存在非支配分支；
- 原逻辑的 partial-progress 语义无法保留；
- widened 之后仍需 variable pointer arithmetic。

### 4.3 `typed stack overwrite reduction`

#### 目标

减少或消除会触发 `nospec_result` 的 stack write。

`check_stack_write_fixed_off()` 的规则很直接，见 `vendor/linux-framework/kernel/bpf/verifier.c:5747-5760`：

- 写入 spillable reg type：触发
- 覆盖一个已有 typed slot（即 slot type 不是 `STACK_MISC/STACK_ZERO`）：触发

所以真正能做的不是“把 barrier 删掉”，而是**让那次 offending write 根本不存在**。

#### 必须同时满足的安全条件

1. **删的是 write，不是删 barrier**
   - 如果那次写还在，`nospec_result` 大概率还会回来。
   - 因此只考虑：
     - dead spill/fill 删除
     - helper 去掉后不再需要的临时 spill
     - 把跨 call 临时值改成留在 callee-saved reg 或可重算值

2. **slot 不可被别名引用**
   - 目标 slot 不能被 address-taken，也不能作为 helper/kfunc 的内存参数别名出去。

3. **live range 要闭合**
   - 被删掉的 spill/fill 对必须是单一定义、所有 use 都能由寄存器值或可重算表达式覆盖。

4. **不能把 typed overwrite 挪成另一个 typed overwrite**
   - 只是“换个槽继续 spill pointer”没有意义，verifier 仍会标 `nospec_result`。
   - 真正有收益的只有：
     - spill 整段消失
     - 写入改成纯 scalar imm/scalar reg，且目标 slot 当时是 `MISC/ZERO`

5. **helper ABI 不变**
   - 任何跨 helper 保存的值，如果不再落栈，就必须证明寄存器分配仍符合 BPF helper clobber 规则。

#### 推荐判定算法

1. 用 def-use 分析找 stack spill/fill 对。
2. 标记以下高价值候选：
   - helper 前后的单次 spill/fill
   - kinsn / direct load 替代 helper 后变 dead 的 spill
   - 为了 verifier 保活而引入、但可在后续 block 重算的 scalar spill
3. 尝试寄存器保活或局部重算。
4. 只有当 offending write 真正消失时才继续。
5. REJIT 后若 `nospec_result` 没降，回滚。

#### 何时直接拒绝

- spill 的是 pointer/dynptr/refstate，且确实要跨 call 活下去；
- slot 被多个 path 复用；
- 删除 write 后会引入更多 helper 或更长 critical path。

### 4.4 `variable ptr arithmetic rewrite`

#### 目标

把会触发 `sanitize_ptr_alu()` 的 `ptr += var` / `ptr -= var` 改写成 verifier 更容易接受、也更便宜的形式：

- 立即数 pointer arithmetic
- 或“先约束 scalar，再做访问”

#### 关键 verifier 条件

这条路径的主要拒绝条件在 `sanitize_ptr_alu()` / `sanitize_err()`，见 `vendor/linux-framework/kernel/bpf/verifier.c:15013-15212,15227-15263`：

- `REASON_BOUNDS`：scalar 有 mixed signed bounds
- `REASON_TYPE`：pointer family 不支持这种 sanitation
- `REASON_PATHS`：不同 path 得到不同的 `alu_state/alu_limit`
- `REASON_LIMIT`：超出 pointer 可接受范围
- `REASON_STACK`：无法为 speculative path 建模

#### 必须同时满足的安全条件

1. **优先把 var 变成 imm**
   - 如果某个 scalar 在当前 dominated region 内已经等价于常量，就直接改成 immediate ALU；这是最干净的做法。

2. **拒绝 mixed-sign unknown**
   - 只要 offset 可能同时取正负两边，直接放弃；这正是 `REASON_BOUNDS`。

3. **path 上限必须一致**
   - 若同一条 ALU 在不同 path 下推导出不同 `alu_limit`，说明 rewrite 后可能造成 path join 爆炸或 verifier 重新拒绝；直接放弃。

4. **只在“能消掉 variable ptr arithmetic”的地方做**
   - 对 packet path，优先做 `bounds-window rewrite`，让 pointer use 回到 fixed-offset。
   - 对数组/map index，优先做 `index_nospec` 或 `mask-before-access`，而不是保留 `ptr += var`。

5. **指针家族要保守**
   - `retrieve_ptr_limit()` 的直接支持对象是 `PTR_TO_STACK` 和 `PTR_TO_MAP_VALUE`，见 `vendor/linux-framework/kernel/bpf/verifier.c:15021-15049`。
   - 对 packet/ctx 这类场景，建议只在 rewrite 后**不再留下 variable ptr arithmetic**时接受；不要指望 verifier 自动“更聪明”。

6. **删除 `nospec` 不能换来更长 sanitizer**
   - 因为 `cur_aux(env)->nospec` 会抑制 ALU sanitation，删 barrier 后若出现新的 mask window，就未必值得。

#### 推荐判定算法

1. 查找 `ADD/SUB` 到 pointer 的站点。
2. 看 scalar 是否能被 constant-fold 到 dominated region 内。
3. 不能 constant-fold 时，优先尝试：
   - 提前 bounds check
   - `index_nospec` / compare+mask
   - 让后续 use 变成 fixed-offset load/store
4. 若 rewrite 后仍有 variable pointer arithmetic，默认拒绝。

## 5. `safe-load` 替代方案：`index_nospec` / `mask-before-access`

### 5.1 现成内核模式

kernel 已经有两个现成模式：

1. `array_index_nospec()` / `array_index_mask_nospec()`
   - 语义定义在 `vendor/linux-framework/include/linux/nospec.h:18-65`
   - 模式是：先做 bounds check，再在 speculative domain 内把 index clamp 到合法范围

2. tail call fixup 的 compare+mask
   - `do_misc_fixups()` 对 unprivileged tail call 显式插入：
     - `if (index >= max_entries) goto out;`
     - `index &= array->index_mask;`
   - 见 `vendor/linux-framework/kernel/bpf/verifier.c:24327-24345`

这说明 kernel 自己已经认可：**比起访问点前后插 barrier，更好的方法是“保留架构语义的边界分支 + 为 speculative path 单独做 mask”**。

### 5.2 适合 daemon 做的两种替代

| 方案 | 适用对象 | 优点 | 主要风险 |
|---|---|---|---|
| compare + `array_index_nospec()` 风格 | array/map index | 不需要 kernel 改动；语义直观 | 必须先有架构上的 bounds check |
| compare + `index &= mask` | `max_entries` 已知、mask 容易构造的 array-like access | 与 tail-call 现有 fixup 一致；成本低 | 只适合 array-like index，不适合任意 packet pointer |

### 5.3 不推荐的做法

1. **不推荐“无前置 bounds check 的 blind mask”**
   - 那会把真正的 OOB 访问改成“访问别的合法元素”，架构语义已经变了。

2. **不推荐把 packet pointer 直接 clamp 到窗口内**
   - array index 的 mask-before-access 语义比较自然；
   - packet parser 若直接 clamp pointer，常常会把“应当 drop/abort 的报文”改成“读取别的位置继续执行”，语义风险太高。
   - packet path 上更安全的方案仍然是 `bounds-window fast path + 原 slow path fallback`。

3. **不推荐 helper/kfunc 形式的 safe-load**
   - 这与 BpfReJIT “zero runtime overhead” 的目标相冲突。
   - 若以后真要把 safe-load 固化成 first-class contract，更合理的是 verifier 识别的 pseudo/intrinsic，而不是运行时 helper 调用。

## 6. Case Study：corpus 中的高压力程序推演

### 6.1 先说明：当前 corpus 没有“高 NOSPEC 样本”

本次 census 的客观结果是：**没有任何一个已加载 program 含 `BPF_ST_NOSPEC`**。因此这里不能伪造“高 NOSPEC 程序”。

本节采用的口径是：

- 先列出 corpus 里**最可能承受 speculative hardening 压力**的 packet-path program；
- 再对其中有源码可读的程序做**反事实推演**：如果未来 verifier 在这些 path 上插 `nospec`，哪种 rewrite 最合理。

### 6.2 当前高压力 packet-path 候选

| project | object | prog_name | prog_type | insn_count_before | nospec_count |
|---|---|---|---|---:|---:|
| linux-selftests | linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o | balancer_ingres | sched_cls | 15202 | 0 |
| linux-selftests | linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o | balancer_ingres | sched_cls | 14750 | 0 |
| calico | calico/from_hep_debug.bpf.o | calico_tc_main | sched_cls | 8604 | 0 |
| calico | calico/to_hep_debug.bpf.o | calico_tc_main | sched_cls | 8173 | 0 |
| calico | calico/to_nat_debug.bpf.o | calico_tc_main | sched_cls | 8145 | 0 |
| calico | calico/from_wep_debug.bpf.o | calico_tc_main | sched_cls | 7127 | 0 |
| calico | calico/from_nat_debug.bpf.o | calico_tc_main | sched_cls | 6847 | 0 |
| calico | calico/to_wep_debug.bpf.o | calico_tc_main | sched_cls | 6310 | 0 |
| calico | calico/from_hep_debug.bpf.o | calico_tc_skb_n | sched_cls | 4751 | 0 |
| calico | calico/from_wep_debug.bpf.o | calico_tc_skb_a | sched_cls | 4659 | 0 |
| calico | calico/to_hep_debug.bpf.o | calico_tc_skb_a | sched_cls | 4584 | 0 |
| calico | calico/to_hep_debug.bpf.o | calico_tc_host_ | sched_cls | 4559 | 0 |

`calico` 是最像“真实系统高压力 carrier”的一组程序，但本仓库没有它们对应的源码上下文，因此下面的细粒度推演用两个源码可读且同样在 corpus 里的程序：`balancer_ingress` 和 `syncookie_xdp/tc`。

### 6.3 `balancer_ingress`：典型 `bounds-window rewrite`

源码见：

- `vendor/linux-framework/tools/testing/selftests/bpf/progs/test_verif_scale2.c:8-29`
- `vendor/linux-framework/tools/testing/selftests/bpf/progs/core_kern.c:74-101`

核心模式非常明确：

```c
ptr = data + i;
if (ptr + nh_off > data_end)
    break;
ctx->tc_index = jhash(ptr, nh_off, ctx->cb[0] + i++);
```

而这段模板被展开了 90 次。

#### 为什么它是 bounds-window 的理想样本

- 所有访问都基于同一个 `data` / `data_end`
- `nh_off` 固定为 14
- 每次只把 `i` 增 1
- fast path 的常见输入通常是“包足够长”，于是 90 次小检查本质上都在证明同一件事

#### 正确的重写方式

不能简单改成“一个大检查失败就整个函数直接返回”，因为原程序对短包是“跑到某一轮再 `break`”，存在 partial-progress 语义。

正确拆法应该是：

1. fast path：
   - 先检查 `data + 103 <= data_end`
   - 其中 `103 = 89 + 14`
   - 若成立，执行无局部 bounds check 的 90 次 `jhash`
2. slow path：
   - 保留原来的逐次检查逻辑

#### 为什么这能帮助 `nospec`

如果某些访问原本会在 speculative path 下把 `aux->nospec` 立在局部 use 点，那么 fast path 上一个 widened guard 会让后续 use 都被同一个支配条件覆盖，verifier 更容易不再需要在每个 use 点前单独补 barrier。

即便当前 census 没看到 `nospec`，这仍是 #433 最有价值的一类“正宗删除入口”。

### 6.4 `syncookie_xdp` / `syncookie_tc`：stack overwrite 与 ptr arithmetic 压力

源码见 `vendor/linux-framework/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.c`，几个关键信号非常典型：

1. `tsopt` 被强制写成 `volatile`，因为否则 verifier 无法证明死分支不会把它设成 `NULL`，见 `:585-602`
2. `syncookie_part1()` 里 `old_len` 被写成 `volatile u64`，注释明确写着“否则 verifier 报 `32-bit pointer arithmetic prohibited`”，见 `:771-781`
3. `syncookie_part2()` 里 `tcp_len` 重新从 packet 里读一次，注释直接说“我们寄存器不够，`tcp_len` 会 spill 到 stack，verifier 会忘掉之前验证过的 min/max”，见 `:810-815`

#### 这说明什么

这类程序即使当前没有 materialize 出 `BPF_ST_NOSPEC`，也已经处在 verifier 的“敏感边缘”上：

- register pressure 高
- helper / tail-adjust 多
- stack spill 对验证结果敏感
- pointer arithmetic 稍改就会触发更强的 speculative hardening

#### 若未来出现 `nospec_result`，最合理的入口是什么

不是“删 barrier”，而是：

1. 先找能否把 helper 前后的 spill/fill 变成寄存器保活或局部重算；
2. 把会跨 `adjust_tail` 失效的 pointer/length 重新组织成：
   - fast path 重新取 pointer
   - scalar 重算而不是落栈回填
3. 若必须跨 path 保留长度信息，优先保留为纯 scalar，不要保留 pointer-typed spill

#### 为什么它不适合直接做 `mask-before-access`

`syncookie_*` 里的很多访问是 packet header parser 和 checksum 逻辑。对这类代码，错误地把 pointer clamp 到某个窗口里，语义风险远大于 array-index 场景。这里更适合：

- `bounds-window rewrite`
- spill elimination
- pointer arithmetic 变立即数 / 变重新取值

而不是“盲目把 offset mask 一下继续访问”。

## 7. 风险评估

| 风险 | 严重性 | 说明 | 缓解 |
|---|---|---|---|
| 只保留架构安全，破坏 speculative 安全 | 高 | 最典型错误是“程序功能没变，但 speculative path 又能越界” | 必须以 verifier 复验为最终裁决，不能用户态自证安全 |
| 删掉 `nospec` 后反而触发更长 `sanitize_ptr_alu()` | 高 | `cur_aux(env)->nospec` 会抑制 ALU sanitation | acceptance gate 比较总 hardening footprint，不只比 barrier 个数 |
| `bounds-window` 改坏 partial-progress 语义 | 高 | 原程序可能允许短输入执行一部分后退出 | fast path + 原 slow path fallback；禁止“一刀切早退” |
| spill 消除改坏 helper ABI / live range | 中 | helper clobber 规则非常刚性 | 只做单一定义、单一消费、非 address-taken 的 spill/fill |
| `mask-before-access` 造成语义 aliasing | 高 | 尤其是 packet parser，不该把 OOB 变成“访问别的合法位置” | 仅用于 array-like index；packet path 默认不用 blind mask |
| corpus 里当前没有 carrier，收益不确定 | 中 | 花了工程成本，但当前 benchmark 未必体现 | 先做小规模 dry-run / synthetic carrier，再决定是否产品化 |
| verifier 可接受但语义仍可能回归 | 中 | verifier 只保安全，不保业务逻辑完全等价 | 需要 runner 回放和 corpus correctness compare |

## 8. 实施建议

### 8.1 不建议做的版本

不建议实现一个“扫描 xlated 里的 `LFENCE` 然后删掉”的 pass。这个方案和 REJIT 接口事实不相容，也无法通过下一轮 `bpf_check()`。

### 8.2 建议做的版本

建议把 #433 定义成一个组合设计：

1. `bounds-window rewrite`
2. `typed stack overwrite reduction`
3. `variable ptr arithmetic normalization`
4. 以 verifier 复验和 xlated diff 作为 acceptance gate

### 8.3 当前优先级判断

基于这次 corpus census，我的建议是：

- **设计上保留 #433**
- **工程上暂不把它排到 corpus-first 的最前面**

原因很简单：当前 corpus 的 loadable 子集里 `BPF_ST_NOSPEC = 0`。  
如果下一轮要投入实现，最合理的顺序是：

1. 先做一个 dry-run only 分析 pass，定位 potential carrier 与可重写 region；
2. 用 `balancer_ingress` / `syncookie_*` 一类源码可控样本做 synthetic validation；
3. 只有当 xlated hardening footprint 真能下降时，再把它升级成默认 pass。

## 9. 最终回答六个必答问题

### 9.1 Corpus 统计

- `corpus/build/` 共 568 个对象，278 个成功加载，导出 861 个 xlated program。
- 当前观测到的 `BPF_ST_NOSPEC` 总数为 **0**。
- 按 project / `prog_type` 聚合也全部为 **0**。

### 9.2 安全判断算法

- `bounds-window rewrite`：要求一个 widened guard 支配全部访问，且 fast path 语义可由 slow path fallback 保留。
- `typed stack overwrite reduction`：只有 offending stack write 真正消失时才有意义。
- `variable ptr arithmetic rewrite`：优先常量化，否则只在能消掉 variable ptr arithmetic 本身时才接受。

### 9.3 Verifier 交互

- `BPF_NOSPEC` 是 verifier/fixup 的 post-load patch。
- daemon 提交的是 pre-fixup bytecode。
- REJIT 会重新调用 `bpf_check()`，verifier 会重新决定插不插 `BPF_ST_NOSPEC()`。

### 9.4 Safe-load 替代

- 正确替代是 `index_nospec` / `compare + mask-before-access`。
- 这类方案已经在 tail-call fixup 中被 kernel 自己采用。
- packet path 默认更适合 `bounds-window + fallback`，不适合 blind mask。

### 9.5 Case study

- 当前 corpus 没有实测高-NOSPEC program。
- 反事实推演里：
  - `balancer_ingress` 对应 `bounds-window rewrite`
  - `syncookie_xdp/tc` 对应 spill / ptr-arithmetic pressure reduction

### 9.6 风险评估

- 最大风险不是“删不掉 barrier”，而是“删 barrier 后换来别的 speculative hardening 或语义回归”。
- 必须把 kernel verifier 复验和输入回放都纳入 acceptance gate。
