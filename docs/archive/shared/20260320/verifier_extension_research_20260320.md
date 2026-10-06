# Verifier 扩展替代 `jit_validators.c` 调研

日期：2026-03-20

## 结论摘要

结论先行：

1. **技术上可行，但不建议按“在 `do_check()` 主循环里逐条指令直接做完整 pattern matching”实现。**
2. **如果目标是“删除独立 validator 层”，更合理的形态是 verifier-owned post-pass collector：**
   在 verifier 完成、最终 xlated 形态稳定后，利用 verifier 期间积累的 facts 和最终 `prog->insnsi`，一次性生成持久化 site table。
3. **如果目标是“大幅减少内核代码量”，收益没有表面看起来大。**
   现在的 `jit_validators.c` 是 `1990` 物理行，近似实现行约 `1662`；但其中大约 **900-1100 行是 form-specific 识别逻辑，本质上无论放在 verifier 还是独立文件都还要存在**。真正因为“独立 validator 层”才多出来、可稳定删除的，大致只有 **300-700 行**。
4. **上游接受度：**
   - “给 verifier 增加少量、和验证强相关的 annotation/fixup 元数据”有先例，**中等可接受**。
   - “把 recompile policy 的完整 pattern engine 塞进 `verifier.c` 主 walk 热路径”会显著增加敏感文件复杂度，**上游接受度偏低**。
5. **推荐路线：**
   - 若追求上游友好：先做 **混合方案**，在 verifier 里只产出基础事实/轻量 annotation，recompile 时做更小的 validator。
   - 若追求替代独立 validator：做 **post-fixup collector**，不要做 `do_check()` inline hook。

我的总体判断：

- **“用 verifier 生命周期替代 recompile-time validator”是可行方向。**
- **“因此能净省掉接近 1791 行内核代码”不成立。**
- **更现实的净减幅度是几百行，不是一整个文件体量。**

---

## 1. Verifier 的 insn walk 结构

### 1.1 主循环在哪里

- `do_check_common()` 初始化单次验证状态，然后调用 `do_check()`：
  `vendor/linux-framework/kernel/bpf/verifier.c:24530-24757`
- `do_check()` 是 verifier 的主 insn walk：
  `vendor/linux-framework/kernel/bpf/verifier.c:21200-21373`
- `do_check_insn()` 按指令类别分发到 ALU/load/store/jump/helper 等检查函数：
  `vendor/linux-framework/kernel/bpf/verifier.c:21032-21197`

核心观察：

- verifier 确实会逐条走 `env->prog->insnsi[env->insn_idx]`。
- 当前没有一个**通用的 per-insn callback API**给普通 JIT/recompile 逻辑复用。
- 现有“每条 insn 的外部 hook”只有 **offload verifier** 的 `insn_hook`：
  - `struct bpf_prog_offload_ops` 定义：`include/linux/bpf.h:1126-1138`
  - 调用点：`kernel/bpf/offload.c:303-316`
  - 在 `do_check()` 中触发：`kernel/bpf/verifier.c:21289-21293`

换句话说：

- **没有现成的、通用的 verifier annotation callback。**
- 若要“在 walk 中打优化标记”，要么：
  - 直接在 `do_check()` / `do_check_insn()` 内插逻辑；
  - 要么仿照 offload，再发明一层新的通用 hook。

后者比前者更结构化，但也更难上游化，因为会扩大 verifier 的外部接口面。

### 1.2 verifier 在 walk 前后还做了什么

`bpf_check()` 的顺序很关键：

- 分配 `env->insn_aux_data`：`verifier.c:25935-25942`
- CFG / postorder / stack liveness 初始化：`verifier.c:26030-26040`
- **先做 CFG 派生分析**：
  - `compute_scc()`：`verifier.c:26046-26048`
  - `compute_live_registers()`：`verifier.c:26050-26052`
  - `mark_fastcall_patterns()`：`verifier.c:26054-26055`
- 再进入主验证：
  - `do_check_main()`：`verifier.c:26058`
  - `do_check_subprogs()`：`verifier.c:26059`
- 验证通过后，继续做一系列 **rewrite/fixup**：
  - dead code / nop removal：`verifier.c:26080-26089`
  - `convert_ctx_accesses()`：`verifier.c:26092-26094`
  - `do_misc_fixups()`：`verifier.c:26096-26097`
  - `opt_subreg_zext_lo32_rnd_hi32()`：`verifier.c:26102-26106`
  - `fixup_call_args()` / subprog JIT prep：`verifier.c:26108-26109`

这意味着：

- **verifier 的“逐条 walk”不是最终 xlated 形态。**
- recompile 当前读的是 **最终 live `prog->insnsi`**，而不是 `do_check()` 当时的中间形态。
- 因此“在主 walk 里直接标 site”如果要给 recompile 用，必须处理后续 rewrite/remap。

### 1.3 现有 rewrite 已经会维护 `insn_aux_data`

这点很重要：

- 插入/替换时会调整 aux：`adjust_insn_aux_data()`  
  `verifier.c:21922-21955`
- 删除指令时也会 `memmove` aux：`verifier_remove_insns()`  
  `verifier.c:22223-22252`

所以：

- **把“临时 annotation”放进 `insn_aux_data` 是可行的。**
- 它能跟着 verifier rewrite 一起 remap。
- 但它**不会自动持久化到 prog 生命周期**，因为 `env->insn_aux_data` 最后会被释放。

---

## 2. Verifier 对每条 insn 已知哪些信息

### 2.1 当前 path 上的强语义信息

在 `do_check()` 某次访问某条 insn 时，verifier 手里有：

- 当前 insn 字节码本身：`env->prog->insnsi[env->insn_idx]`
- 当前 path 的寄存器状态：`env->cur_state->frame[*]->regs`
- 当前 path 的栈状态
- 当前 frame / callsite / speculative 标志
- 当前锁状态、ref 状态、ptr type、tnum/range 等

这些都是做“语义型 pattern matching”的宝贵信息。

### 2.2 已持久化到 `insn_aux_data` 的每-insn facts

`struct bpf_insn_aux_data` 定义在：
`vendor/linux-framework/include/linux/bpf_verifier.h:525-598`

当前已经存在不少“不是最终安全判定本身，但供后续 fixup/JIT 使用”的字段，例如：

- `ptr_type`
- `ctx_field_size`
- `nospec` / `nospec_result`
- `zext_dst` / `needs_zext`
- `non_sleepable`
- `loop_inline_state`
- `fastcall_pattern` / `fastcall_spills_num`
- `jmp_point` / `prune_point`
- `scc`
- `live_regs_before`

这点非常关键：

- **在 verifier 里存“后续优化/变换会消费的 annotation”是有先例的。**
- verifier 并不是只存纯安全 verdict。

### 2.3 但 verifier 没有持久化“单一、稳定的 per-insn reg-state summary”

这是限制条件。

同一条 insn：

- 可能从不同控制流路径多次访问；
- 每次进入时寄存器 type/range/tnum 可能不同；
- verifier 当前只在访问时持有 path-sensitive state，不会在程序生命周期里保留一份“这个 insn 的最终统一语义状态”。

因此：

- 如果 pattern 依赖**当前 path**的寄存器值范围或别名关系，
- 那么 inline annotation 逻辑必须回答“多条路径合并后怎么定义 site 是否有效”。

这是比“纯看指令字节模式”复杂得多的地方。

---

## 3. 当前 `jit_validators.c` 实际在做什么

### 3.1 调用链

当前 recompile 路径：

- `jit_policy.c` 解析 policy blob 时，对每条 rule 调  
  `bpf_jit_validate_rule(...)`：
  `vendor/linux-framework/kernel/bpf/jit_policy.c:195-203`
- `bpf_jit_validate_rule()` 在 `jit_validators.c` 中做：
  - header/range/native choice 检查
  - side-effect 检查
  - canonical params 提取
  - interior edge 检查  
  入口：`vendor/linux-framework/kernel/bpf/jit_validators.c:1934-1990`
- 成功后把 canonical params 存进 `rule->params`
- JIT emitter 只按 `site_start` 查 active rule，然后直接消费 `rule->params`：
  - x86：`arch/x86/net/bpf_jit_comp.c:3025-3185`
  - arm64：`arch/arm64/net/bpf_jit_comp.c:828-909`

### 3.2 它并不只是“重复 walk 一遍 verifier”

这点需要校正。

当前 validator 确实重新扫描 insn，但它和 verifier 主 walk 不完全等价：

1. **它看的是最终 live xlated program**
   而不是 `do_check()` 当时的中间形态。
2. **它只验证 policy 请求的 site**
   不是枚举全程序所有候选 site。
3. **它主要是 syntax-driven**
   当前 forms 几乎都靠指令形状、寄存器编号、imm/off、CFG 局部结构完成，不真正依赖 verifier 的 path-sensitive reg facts。

所以“重复 insn walk”这个判断在成本模型上是对的，但在抽象层上并不完全对。

### 3.3 代码量现实

本仓库当前统计：

- `jit_validators.c`：`1990` 物理行
- 近似实现行：`1662`

粗分段：

- `shared + cond_select`：`753` 行
- `wide_mem`：`191` 行
- `rotate`：`171` 行
- `bitfield_extract`：`197` 行
- `addr_calc`：`43` 行
- `endian_fusion`：`131` 行
- `branch_flip`：`299` 行
- `dispatch + meta`：`193` 行

其中真正“因为它是独立 validator 层”而存在、迁移后最容易消失的，主要是：

- rule-wrapper / dispatch / logging glue
- site-range / side-effect / interior-edge 这类通用 recompile-time 检查
- 一部分 canonical-params substrate

但：

- **各 form 的 shape parser / normalize / bounds 逻辑仍然要存在 somewhere。**

因此：

- **删掉文件名，不等于删掉 1990 行逻辑。**

---

## 4. 能否在 verifier walk 中直接加 hook 做 pattern matching

### 4.1 纯技术可行性：可以

如果只是问“能不能在 `do_check()` 某个点上接一个 hook，看当前 insn 和后几条 insn 是否匹配 pattern”：

- **可以。**

最直接的位置是：

- `do_check()` 中，`do_check_insn()` 成功返回前后：
  `verifier.c:21296-21329`
- 或者在 `do_check_insn()` 里每个类别处理成功后加 form-specific 逻辑：
  `verifier.c:21032-21197`

而且 verifier 的当前 path state 可直接读。

### 4.2 但工程上不建议这么做

原因有四个。

#### (1) 主 loop 是 verifier 最敏感路径

`do_check()` / `do_check_insn()` 是 BPF 子系统最敏感的代码路径之一。

把 7 个 canonical form 的匹配逻辑直接放进去，会带来：

- 更多分支和状态机
- 更难 review
- 更难 bisect verifier bug
- 更难说服上游“这和安全验证的核心职责足够近”

#### (2) 同一 insn 会被多 path 多次访问

如果 annotation 想用 path-sensitive facts，就要定义：

- 首次访问就记？
- 还是所有访问都一致才记？
- 如果一条 path 可优化、另一条 path 不可优化，最终 site 算不算合法？

这会把 recompile concern 带进 verifier state merge 问题。

#### (3) 主 walk 看到的还不是最终 xlated 形态

后续还有：

- dead-code removal
- ctx access conversion
- misc fixups
- call arg fixups / subprog rewrite

即使你在主 walk 标了 site，后面还得继续 remap/validate 一次。

#### (4) 当前 forms 本身几乎不吃 verifier facts

当前 7 个 form 主要是：

- 局部 BPF shape
- 局部 CFG 结构
- imm/off 边界
- 少量 alias 约束

它们不是 `bounds_window` 这类真正需要 retained verifier facts 的优化。

所以把它们塞进 verifier 主 loop，收益不够高。

### 4.3 更合理的形态：verifier-owned post-pass

我认为更好的方案是：

1. verifier 正常完成 `do_check()`
2. 所有 rewrite/fixup 完成，最终 `prog->insnsi` 稳定
3. 在 `clear_insn_aux_data()` 之前执行一次 `bpf_jit_collect_sites(env)`
4. collector 用：
   - 最终 `prog->insnsi`
   - verifier 期间积累的 `insn_aux_data`
   - 需要的话再加少量 transient facts
   生成持久化的 `jit_site_table`

这仍然是“verifier 生命周期拥有 annotation”，但：

- 不污染主验证 loop
- 不受后续 rewrite 失配影响
- 语义上比 recompile-time validator 更接近“load-time certification”

---

## 5. Annotation 持久化方案

### 5.1 不能直接复用现有 `env->insn_aux_data`

因为 verifier 结束时：

- `clear_insn_aux_data(env, 0, env->prog->len);`
- `vfree(env->insn_aux_data);`

见：`vendor/linux-framework/kernel/bpf/verifier.c:26191-26192`

所以：

- **现有 `insn_aux_data` 只是 verifier 临时工作区，不是 prog lifetime 的 metadata。**

### 5.2 方案对比

#### 方案 A：把 `insn_aux_data` 直接变成持久化

不推荐。

问题：

- `insn_aux_data` 是按 insn 数量分配的全量数组
- 里面很多字段只对 verifier 临时分析有意义
- 把整个数组挂到 `bpf_prog_aux` 会引入较大常驻内存

这会把 verifier 内部工作集泄漏到长期对象模型里。

#### 方案 B：在 `insn_aux_data` 里只放“临时 site 起点标记 + side vector index”

可行，适合作为**过渡层**。

比如加：

- `jit_site_start`
- `jit_site_idx`
- 或若干 `jit_fact_*` bits

然后在 verifier 结束前把真正需要长期保留的信息压缩到 `bpf_prog_aux`。

优点：

- rewrite/remap 已有机制可复用
- 不需要让整个 aux 数组长期常驻

#### 方案 C：在 `bpf_prog_aux` 挂一个 compact site table

这是**最推荐**的持久化载体。

建议类似：

```c
struct bpf_jit_site_desc {
	u16 form;
	u16 site_len;
	u32 site_start;   /* absolute idx in main xlated prog */
	union {
		struct rotate_site rotate;
		struct wide_mem_site wide_mem;
		struct cond_select_site select;
		...
		struct branch_flip_site branch_flip;
	};
};

struct bpf_prog_aux {
	...
	struct bpf_jit_site_desc *jit_sites;
	u32 nr_jit_sites;
};
```

为什么不建议直接持久化 `struct bpf_jit_rule`：

- 现在 `struct bpf_jit_rule` 里嵌了完整 `bpf_jit_canonical_params`
- 其大小按当前布局约 **280 bytes/site**

粗略内存量级：

- `1000` sites 约 `280 KB`
- `2000` sites 约 `560 KB`

而文档里的真实 site 数量已经到：

- Tracee：`2028` sites
- Calico：`904` sites
- Katran：`74`~`94` sites

如果再把 `BRANCH_FLIP` 的两个 body 直接 `kmemdup()` 持久化，常驻内存会更大。

因此：

- **持久化必须用 compact descriptor，不应直接复用 `bpf_jit_rule`。**

### 5.3 subprog / recompile lookup

这部分当前架构已经有现成模式：

- JIT rule lookup 总是挂在 `main_prog_aux->jit_policy`
- subprog JIT 时通过 `subprog_start` 转成 absolute site index：
  - x86：`arch/x86/net/bpf_jit_comp.c:3025-3038`
  - arm64：`arch/arm64/net/bpf_jit_comp.c:828-841`

因此新 site table 也应：

- 归 `main_prog_aux` 所有
- 用 absolute `site_start`
- subprog 侧沿用相同加 `subprog_start` 的 lookup 方式

---

## 6. 和当前方案的对比

## 6.1 当前方案

### 结构

1. load 时 verifier 通过
2. recompile syscall 读用户 policy
3. `jit_validators.c` 对 live xlated insn 做 exact validation
4. emitter 吃 `rule->params`

### 优点

- verifier 不背 recompile 复杂度
- 只验证 policy 请求的 site，不必枚举全量候选
- 逻辑边界清楚：validator 是唯一安全门

### 缺点

- recompile 时重新扫 insn
- 无法直接复用 verifier 的 path facts
- validator 和 verifier 都要理解 CFG/insn shape 的一部分

## 6.2 新方案：verifier load-time annotation

### 真正增加的职责

不是简单“把 validate 挪进去”，而是：

- **要在 load 时发现所有潜在 site**
- **要把 site 结果持久化**
- **recompile 时从持久化 site table 激活 policy 子集**

### 优点

- recompile 时不再需要 exact validator 扫描
- 能使用 verifier 现有 facts
- kernel safety gate 变成 load-time 一次认证

### 缺点

- load-time verifier 逻辑更复杂
- 需要新的持久化对象模型
- 现在 validator 只验证 active rules；新方案要做 candidate discovery，职责扩大

### 关键现实

**“替代独立 validator”与“减少代码量”不是同一件事。**

前者可行；后者收益有限。

---

## 7. 上游接受度与先例

## 7.1 支持这一方向的先例

### 先例 A：verifier 已经产出供后续 JIT/fixup 使用的 annotation

本地 7.0-rc2 源码里已经有：

- `fastcall_pattern` / `fastcall_spills_num`
- `live_regs_before`
- `scc`
- `ctx_field_size`
- `call_imm`

这些都说明 verifier 可以合理地产出“超出纯 reject/accept verdict”的 metadata。

### 先例 B：`bpf_fastcall` pattern 直接在 verifier 里识别

本地代码：

- `mark_fastcall_pattern_for_call()`：`verifier.c:18433-18518`
- `mark_fastcall_patterns()`：`verifier.c:18520-18542`

对应补丁系列已被 Alexei 合入：

- patchwork bot, 2024-08-22：
  <https://www.spinics.net/lists/bpf/msg124099.html>

这说明：

- **“verifier 内部识别 JIT/fixup 相关 pattern”这件事本身，上游并不排斥。**

### 先例 C：`live_regs_before` 被拿来驱动 verifier 后续优化/清理

- 补丁：2025-09-10  
  <https://www.spinics.net/lists/bpf/msg152224.html>

这里明确把 `insn_aux_data->live_regs_before` 用到 `clean_func_state()`，说明：

- **`insn_aux_data` 里的派生分析结果可被后续 verifier 阶段消费。**

### 先例 D：verifier/fixup 阶段会额外扫描 generated insns

- 2024-12-20 补丁：
  <https://www.spinics.net/lists/netdev/msg1055058.html>

该补丁为了 prologue/epilogue 里的 kfunc，把新的扫描逻辑加进 verifier fixup 阶段，而不是单纯坚持“verifier 只看用户原始 insns”。

这对本题很重要：

- **把“最终 xlated 形态上的 collector”放在 verifier 尾部，是符合现有演进方向的。**

## 7.2 不利因素

### Verifier 是 BPF 子系统最敏感文件

这一点无需赘述，`verifier.c` 当前已经：

- `26201` 物理行
- 近似实现行约 `18726`

任何新逻辑都要非常克制。

### 上游维护者对“扩大 verifier 角色边界”比较谨慎

在 modular verifier RFC 讨论里，Alexei Starovoitov 的意见是：

- 移动一些代码、做少量定向 export 可以；
- 但把边界扩太大 “goes too far”。

见 2025-04-21 回复：
<https://www.spinics.net/lists/bpf/msg142433.html>

这虽然讨论的是 modular verifier，不是本题，但信号很明确：

- **maintainers 愿意接受 verifier 的局部、内聚扩展**
- **不愿意把 verifier 变成一个更大的通用基础设施容器**

### 推断

我对上游接受度的推断是：

- **高**：在 verifier 尾部增加一个小型、明确受限的 post-pass collector；或者只增加少量 per-insn facts
- **中**：在 `insn_aux_data` / `bpf_prog_aux` 增加 compact JIT-site metadata
- **低**：把 7 个 form 的完整 pattern engine 直接塞进 `do_check()` 主循环

---

## 8. LOC 估算

下面给的是**净内核代码量**估算，不是“删文件名”的估算。

### 8.1 基线

- 当前 `jit_validators.c`：`1990` 物理行，约 `1662` 近似实现行

### 8.2 为什么不会省掉整个文件体量

因为 form-specific 逻辑不会消失：

- `WIDE_MEM`
- `ROTATE`
- `COND_SELECT`
- `BITFIELD_EXTRACT`
- `ADDR_CALC`
- `ENDIAN_FUSION`
- `BRANCH_FLIP`

无论它们放在：

- `jit_validators.c`
- `verifier.c`
- verifier-owned collector helper

都还是要存在。

真正比较容易删掉的是：

- validator wrapper / dispatch / logging glue
- recompile-time range / interior-edge / side-effect 壳层
- 一部分 canonical param 通用 substrate

### 8.3 三种设计的净效果

| 设计 | 大致新增 | 大致删除 | 净变化 | 备注 |
|---|---:|---:|---:|---|
| 直接把现有 matcher 搬进 `do_check()` 主 loop | `+1700 ~ +1950` | `-1990` | `0 ~ -300` | 几乎只是搬家，代码量下降很有限，风险最高 |
| verifier-owned **post-fixup collector**（推荐的“替代 validator”形态） | `+1200 ~ +1550` | `-1990`，`jit_policy.c` 再减 `50 ~ 100` | `-500 ~ -900` | 需要 compact site table，收益中等 |
| **混合方案**：verifier 只导出基础 facts，保留轻量 validator | `+150 ~ +250` | `-250 ~ -500` | `-100 ~ -350` | 上游友好，代码量收益最保守 |

我的判断：

- **现实可拿到的净减幅度大概率是几百行。**
- **只有做 aggressive redesign，且把 site storage 设计得很紧凑，才有机会接近 1k 行级别的净减少。**
- **想靠“并入 verifier”直接净省掉 1.6k~2.0k 行，不现实。**

### 8.4 内存模型估算

如果 naïve 地把每个 site 持久化成一个 `struct bpf_jit_rule` 级别对象：

- 约 `280 bytes/site`
- `2028` sites 约 `560 KB`

而这还**没算 `BRANCH_FLIP` body 副本**。

因此必须：

- 用 compact site descriptor
- 对 `BRANCH_FLIP` 只持久化 body range，recompile 时再从 immutable `prog->insnsi` 复制

否则上游很难接受。

---

## 9. 推荐方案

## 9.1 不推荐：`do_check()` inline hook

不推荐原因：

- 污染 verifier 热路径
- path-sensitive state 合并复杂
- 最终 xlated 形态尚未稳定
- 当前 forms 对 verifier facts 的收益有限

## 9.2 推荐：verifier-owned post-fixup collector

推荐实现：

1. verifier 期间只保留/补充少量 transient facts 到 `insn_aux_data`
2. 所有 rewrite/fixup 完成后，执行 `bpf_jit_collect_sites(env)`
3. 生成 `main_prog_aux->jit_sites`
4. `jit_policy.c` 在 parse/activate 时只做：
   - blob 结构校验
   - overlap 检测
   - arch/cpu gating
   - 在 `jit_sites` 中查找对应 `site_start + form`
   - 拷贝 compact params 到 active policy/rule

这样得到的效果是：

- **“安全 gate 在 verifier 生命周期内完成”**
- **recompile 时不再做 exact site scan**
- **不把 form matcher 塞进 verifier 主 loop**

## 9.3 若以“上游概率”为第一目标：混合方案更好

混合方案建议 verifier 只暴露这类基础属性：

- `pure_compute` / `has_side_effect`
- `jmp_point` / `incoming edge count`
- `subprog boundary`
- 已有的 `scc` / `live_regs_before`
- 若未来需要，再加少量“site-start reg facts”

然后 recompile validator 变成更薄的一层。

这条路：

- 代码量收益较小
- 但风险最小
- 对未来 `bounds_window` 这类真正需要 verifier facts 的 form 更有价值

---

## 10. 最终判断

对原问题的直接回答：

- **能不能扩展 verifier 来替代当前独立 `jit_validators.c`？**
  - **能。**
- **最合理的实现是不是在 `do_check()` walk 里直接做完整 pattern matching？**
  - **不是。**
- **这样做能不能大幅减少内核代码量？**
  - **不能达到“删掉 1791 行就净减 1791 行”的程度。**
  - **现实净收益更像是几百行。**
- **哪个方案最平衡？**
  - **verifier-owned post-fixup collector**，或者更保守的 **混合方案**。

我的推荐结论：

> 如果目标是“架构更干净，recompile 不再重新 exact-validate”，可以做。  
> 如果目标是“尽量少碰 verifier 且上游更容易接受”，做混合方案。  
> 如果目标是“靠并入 verifier 大幅砍掉内核 LOC”，不值得把复杂度压进 `verifier.c` 主循环。

---

## 参考

### 本地源码

- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/kernel/bpf/jit_validators.c`
- `vendor/linux-framework/kernel/bpf/jit_policy.c`
- `vendor/linux-framework/include/linux/bpf.h`
- `vendor/linux-framework/include/linux/bpf_verifier.h`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `docs/kernel-jit-optimization-plan.md`

### 外部原始资料

- `bpf_fastcall` pattern 合入：
  <https://www.spinics.net/lists/bpf/msg124099.html>
- `live_regs_before` 被后续 verifier 阶段复用：
  <https://www.spinics.net/lists/bpf/msg152224.html>
- verifier/fixup 阶段扫描 prologue/epilogue 中 kfunc：
  <https://www.spinics.net/lists/netdev/msg1055058.html>
- Alexei 对 modular verifier 边界扩张的谨慎态度：
  <https://www.spinics.net/lists/bpf/msg142433.html>
