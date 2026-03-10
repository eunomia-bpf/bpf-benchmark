# BPF JIT 可扩展 Pass 框架 v3 设计

日期：2026-03-09

## 1. 摘要

POC v2 已经证明一件关键事实：`cmov_select` 可以作为真正的 JIT backend lowering 落在内核里，且满足我们的核心不变量:

- `xlated_prog_len` 不变
- `jited_prog_len` 变化

因此，v3 不再接受任何会改写 BPF 字节码的设计。旧稿中的 `VERIFIER_REWRITE` stage、`branch_reorder`、`bounds_window` 都必须移除；它们本质上是 BPF 指令变换，不属于本文要解决的层。v3 只有一个 stage：`JIT_LOWERING`。

这条边界与 `paper-comparison.md` 的主叙事是一致的：论文已经把差距定位在**验证之后的 backend lowering**，而不是 BPF bytecode 本身。实证上，89% 的 native instruction gap 集中在三类 lowering 决策：byte-load recomposition、缺少 `cmov`、以及固定 callee-saved 保存；LLVM pass ablation 进一步表明真正起作用的只有 `InstCombinePass` 和 `SimplifyCFGPass`。因此，v3 要解决的问题不是“把完整 LLVM 搬进 kernel”，而是给 kernel JIT 增加一个**fail-closed、可扩展、只作用于 native lowering 的 backend policy substrate**。

v3 的目标也不是再堆几个 ad-hoc directive，而是把 POC v2 的“单一 kind + 单一 x86 hook”扩展成一个**可复用的 JIT backend policy substrate**，更准确地说，是把 `kernel legality plane` 与 `userspace backend policy plane` 分开。这个 substrate 要复用的不是某一条优化，而是下面五类基础设施：

1. 通用 region dispatcher
2. 通用 plan system
3. 通用 alt table / emitter registry
4. 通用 transport / validation pipeline
5. 通用 `addrs[]` commit

### 1.1 与计划文档的 supersedes / out-of-scope 关系

`docs/kernel-jit-optimization-plan.md` 仍然保留了不少历史路径与未来研究项；它作为 hub 文档可以继续存在，但下表中的条目**对 v3 MVP 已经不再适用**。v3 设计文档在这些点上是更新、更窄、也更可实现的 contract。

| 计划文档中的旧条目 | v3 MVP 状态 | 处理原则 |
|------------------|------------|----------|
| `branch_reorder`（包括 policy-sensitive 主角、TODO `#20/#32`、`opt3-vm`） | **superseded / out-of-scope** | 它需要 BPF CFG permutation / verifier substrate，不属于 `JIT_LOWERING` |
| `bounds_window` | **superseded / out-of-scope** | 它依赖 retained verifier facts 与结构性 BPF reasoning，不是 native lowering 选择 |
| `Hybrid / Path B / verifier structural rewrite` 作为 v3 主方向 | **superseded for v3 MVP** | 保留为未来 verifier substrate 研究记录，但不再是当前 MVP 交付 |
| `v3 rule 定义：5+ rules`（把 `branch_reorder` 算进 v3） | **superseded** | v3 MVP 规则集固定为 4 个 `JIT_LOWERING` family：`SELECT`、`ADDR_MODE`、`ROTATE`、`WIDE_MEM` |
| `subprog_inline` | **future, not MVP** | 需要跨过程 validator、预算与 code-size reasoning；不进入首版实现 |

换句话说，v3 不是在执行计划文档里的 `Hybrid Path B`，也不是在把 `branch_reorder` 包装成 JIT rule；它明确只做一件事：**final verified BPF image 上的 JIT-only lowering policy substrate**。

v3 首批 rule 只保留 4 个纯 JIT_LOWERING 家族：

- `cmov_select`，`SELECT` family
- `lea_fusion`，`ADDR_MODE` family
- `rotate_fusion`，`ROTATE` family
- `wide_load`，`WIDE_MEM` family

这 4 个 family 在论文中的角色并不完全对等：

- `SELECT` 是首个、也是当前最强的 **policy-sensitive anchor**；它直接承接论文中“kernel 完全不发 `cmov`（31 vs 0）”以及 `no-cmov` mixed result
- `WIDE_MEM` 是对论文中“byte-load recomposition 占 50.7% surplus、隔离时间惩罚 2.24x”这一**最大 backend gap**的直接承接；它证明最大差距也能在 **JIT-only** 层修复
- `ADDR_MODE` 与 `ROTATE` 不是 characterization 论文的三大 headline gap；它们保留下来，是为了证明框架不是只为 `cmov`/`wide_load` 定制的点方案，而是能泛化到其它纯 JIT-level lowering family
- 因而，MVP 的 why-userspace 证据层级是：`SELECT` > `WIDE_MEM` > `ADDR_MODE`/`ROTATE`
- 论文中的第三个 headline gap，callee-saved register policy，不作为 v3 family；原因是它已经在 kernel `v7.0-rc2` 里作为 stock-kernel liveness 优化落地，更适合被视为“应直接 upstream 的固定 kernel heuristic”，而不是 userspace policy rule

顶层状态从 v2 的“validated directives array”提升为“raw records + validated plans + start map”：

```c
enum bpf_jit_rule_family {
	BPF_JIT_RF_SELECT    = 1,
	BPF_JIT_RF_ADDR_MODE = 2,
	BPF_JIT_RF_ROTATE    = 3,
	BPF_JIT_RF_WIDE_MEM  = 4,
};

struct bpf_jit_pass_state {
	u32 raw_rec_cnt;
	u32 plan_cnt;
	u32 log_cnt;
	u32 subprog_cnt;
	struct bpf_jit_rule_rec_v3 *raw_recs;
	struct bpf_jit_plan_hdr *plans;
	struct bpf_jit_start_map *start_maps;
	struct bpf_jit_rule_log_entry *logs;
};
```

与 POC v2 的对比：

- v2 每新增一个 directive，都要新增 UAPI kind、payload struct、verifier matcher、JIT hook、`addrs[]` 更新代码，实际成本约 `~250-350 LOC/directive`
- v3 把 transport、validation、dispatch、commit 变成一次性基础设施后，新增一个**既有 family 内的新 rule**只需要：
  1. 用户态 pattern matcher
  2. 内核侧注册一个 emitter alt，约 `~50-100 LOC/arch`

安全性边界：

- 用户态不能上传机器码
- 用户态不能改写 BPF 指令流
- 用户态只能请求 kernel 已知 family 的合法 site
- 任何 site 失败都应该按 site 回退到 stock JIT，而不是让整次 JIT 失败

控制权边界：

- userspace 只控制 **policy**：在哪些 site 上请求哪些已知 lowering alt、何时启用、面向哪些 workload/CPU/fleet
- kernel 只控制 **safety / legality**：只能从预注册 emitter alt 中选择，逐 site 精确验证，失败即 fail-closed fallback，绝不接受 raw native code upload 或 verifier override

实现工作量：

- x86 的 JIT-only MVP 核心内核改动，`SELECT + ADDR_MODE + ROTATE + WIDE_MEM + 通用基础设施`，总量预计 `1200-2000 LOC`
- hardening / observability / selftests / 论文评估 plumbing 额外预计 `500-900 LOC`
- 这个拆分后的量级与 review 的判断一致，且明显低于“把 4 个 directive 分别手工塞进 `do_jit()`”的累积成本

---

## 2. 设计边界与总体架构

### 2.1 设计边界

v3 的试金石非常直接：

> 如果某个 rule 让 `xlated_prog_len` 发生变化，那么它就是 BPF bytecode 变换，不属于 v3。

这条边界直接排除了旧稿中的两类内容：

- `branch_reorder`
- `bounds_window`

它们即使“只有 kernel 能安全做”，本质上仍然是 BPF 指令或 CFG 改写；这类能力如果要做，应当作为未来单独的 verifier substrate 研究，而不是混入 v3。

v3 因而只有一个 stage：

```c
enum bpf_jit_pass_stage {
	BPF_JIT_STAGE_JIT_LOWERING = 1,
};

struct bpf_jit_framework_caps {
	u16 stage_cnt;   /* 固定为 1 */
	u16 family_cnt;  /* 初始为 4 */
	u32 flags;       /* 预留 */
};
```

这意味着 v3 只覆盖这样一类 backend 决策：**legality 是稳定的，profitability 是 deployment-sensitive 的**。凡是“对所有程序/CPU/workload 都明显更好”的 lowering，更诚实的结论仍然是直接把 heuristic 做进 stock kernel；`paper-comparison.md` 里的 callee-saved adaptive save 已经是这种 case。

### 2.2 总体架构

v3 的执行路径如下：

```text
userspace backend policy plane
  -> exact BPF image analysis
  -> rule bundle (pattern + constraints + action + cpu contract)
  -> sealed memfd
  -> BPF_PROG_LOAD

kernel legality plane / transport
  -> parse / size check / digest bind / cpu contract parse

kernel legality plane / final materialization
  -> 在所有 verifier-owned late rewrites / fixups 结束后
  -> 在 `bpf_int_jit_compile()` 可能执行 constant blinding 之前
  -> orig_range remap
  -> generic constraint check
  -> family exact validator
  -> arch alt selection
  -> overlap arbitration
  -> build start_map

arch JIT data plane
  -> generic region dispatcher
  -> per-site emitter alt
  -> generic addrs[] commit
  -> site fallback or applied region
```

这里最关键的调整是：**plan materialization 的时机必须后移到所有内核自带 late rewrite 之后**。与 v2 当前在 `fixup_call_args()` 之前校验不同，v3 应当把 materialization 放在最终 BPF 指令流稳定之后；因为我们不再做 framework 自己的 BPF rewrite，这时再做 `orig_range` remap 最简单也最稳。

```c
struct bpf_jit_rule_pipeline {
	int (*transport_load)(struct bpf_prog *prog, int fd, u32 flags);
	int (*materialize_after_fixups)(struct bpf_verifier_env *env);
	void (*free_state)(struct bpf_jit_pass_state *state);
};
```

### 2.2.1 Constant Blinding / Late-Rewrite Contract

这部分必须写死，否则 materialization 与当前真实内核 pipeline 会错位。MVP contract 如下：

1. **materialization 绑定的 program image**  
   `prog_tag`、`insn_cnt`、`orig_idx`、`orig_range -> cur_range` remap，都绑定到**verifier 完成后的最终 BPF image**：也就是所有 verifier-owned late rewrite / fixup 已结束、但 `bpf_int_jit_compile()` 还没有执行 `bpf_jit_blind_constants()` 之前的那份 `prog->insnsi`。

2. **constant blinding 的支持策略**  
   MVP **不支持** blinded program 上继续使用 v3 plan。原因不是“懒得做”，而是当前内核的 blinding 会在 JIT 前 clone 并扩展 BPF 指令流；一旦进入 blinded clone，`prog->len`、site 边界、`orig_idx` 语义对象都会从 v3 绑定的 image 漂移。  
   因而，只要 `prog->blinding_requested` 为真，或者 JIT 路径已经切换到 `prog->blinded` clone，v3 必须 fail-closed 地丢弃整份 plan state，并记录 `BPF_JIT_RJ_BLINDED_PROG`。

3. **reject vs fallback 边界**  
   - **whole-bundle reject / disable v3**：digest mismatch、arch mismatch、range remap 失败、blinded program。这里不是“某个 site 不合法”，而是“整份 plan 没有稳定绑定对象”；结果是**关闭 v3 并继续走 stock JIT / interpreter 路径**，而不是让程序加载失败。
   - **per-site reject（materialization 阶段）**：pattern mismatch、constraint fail、family exact validate fail、alt unavailable、overlap reject、budget exceed。它们只是不让该 site 进入冻结 plan。
   - **per-site fallback（JIT 阶段）**：仅在 site 已经 materialize 成 plan 之后，emitter 因局部编码条件失败而回退到 stock emission；它不能改变别的 site，也不能把 blinded clone 重新解释成合法对象。

4. **不做的事**  
   MVP 不尝试把 unblinded `prog_tag` / `orig_idx` / remap 结果重新投影到 blinded image，也不引入第二套“blinding remap table”。若未来真的要支持 blinded program，应把它作为单独 hardening 扩展，而不是在首版里半支持。

与 POC v2 的对比：

- v2：`bpf_jit_directives_validate()` 只产出 `kind + subprog_idx + insn_idx`
- v3：同一条 transport 路径，产出的是 `validated plan + start_map`
- v2：`cmov_select` 直接绑死在 x86 `do_jit()` 两个 hook 点
- v3：arch JIT 只认通用 `plan`

安全性分析：

- v3 没有 framework-owned rewrite，因此不需要额外重跑 liveness/SCC，也不会引入 `orig_start/orig_end` block permutation provenance 问题
- rule 的合法性证明发生在最终 BPF 指令流上，而不是早期中间状态上
- 用户态仍然不能改变 verifier 的证明对象，只能在最终已验证程序上请求另一种 native lowering

实现工作量：

- materialization hook 后移和 plumbing 调整：`80-150 LOC`
- 把 v2 的 validate 结果从“directives array”改成“plans + start_map”：`120-180 LOC`

### 2.3 为什么是 userspace policy，而不是只加 kernel heuristics

v3 的论点不是“kernel 不该做优化”，而是要把两类问题分开：

- **kernel heuristic 该做的事**：universally-good、deployment-insensitive 的 lowering。例如 callee-saved liveness save；既然它在不同 workload 上都成立，就应该直接进入 stock kernel
- **userspace policy 该做的事**：legality 稳定，但 profitability 依赖 CPU、输入分布、程序级组合和部署 rollout 的 lowering site

`kernel-jit-optimization-plan.md` 里给出的 5 个 why-userspace 理由，在 v3 里都必须保留，因为它们回答的是“为什么需要 framework”，而不是“为什么需要某个 peephole”：

1. **可更新性**：policy DB 可以独立于 kernel release 频繁更新；fixed kernel heuristic 需要等内核升级
2. **程序级组合**：局部有利的 lowering 可能在全程序层面导致 code-size / I-cache cliff；userspace 可以做全局预算
3. **workload 适应**：像 `cmov_select` 这样的合法 site，其收益取决于分支可预测性和运行时输入分布，不是纯 ISA 常量
4. **fleet A/B rollout**：service owner 可以先在 5% 节点启用一组 policy，再决定是否扩大，不需要先改 kernel
5. **所有权**：真正承担 BPF 性能/回归风险的是 Cilium、Katran 等 loader/operator，而不是 kernel maintainer

因此，v3 必须坚持下面这个分工：

- userspace controls **POLICY**：which optimization, when, for which workloads, under which code-size budget
- kernel controls **SAFETY**：only pre-registered emitter alts, exact validation, digest binding, CPU gating, per-site fail-closed fallback

这也给出一个必须正面承认的 falsification condition：

> 如果 fixed kernel policies 在所有目标 CPU / workload / program 上都恢复同等收益，那么正确结论就是“做 kernel peepholes”，而不是“发布 userspace-guided interface”。

换句话说，v3 只有在**存在 policy-sensitive site** 的前提下才成立。`cmov_select` 是首个、也是当前最强的 policy-sensitive 锚点；`WIDE_MEM` 证明最大的实证 backend gap 也能维持在 JIT-only 边界内；`ADDR_MODE`、`ROTATE` 则证明这个 substrate 不止能承载一个特例，但它们不是与 `SELECT` 等强度的 why-userspace 证据。

---

## 3. 可扩展基础设施设计

### 3.1 通用 Region Dispatcher

核心思想：所有 v3 rule 都必须先被归一化成“一个连续 BPF span，可以被另一个连续 native span 替代”。JIT 主循环不再知道 `cmov`、`lea`、`rotate`、`wide_load` 的细节，只知道“当前位置是否有一个已经验证好的 region plan”。

```c
struct bpf_jit_region_plan {
	u32 subprog_idx;
	u32 start_insn;   /* 当前 subprog 内的起点 */
	u32 end_insn;     /* 半开区间 [start, end) */
	u16 family;
	u16 alt_id;
	u16 policy_prio;  /* userspace-owned cross-site ordering */
	u16 plan_flags;
	u16 budget_cost;  /* kernel-owned size-budget charge */
	u16 reserved;
	u32 plan_off;     /* 指向 family-private payload */
};

struct bpf_jit_start_map_entry {
	u32 start_insn;
	s32 plan_idx;     /* -1 表示无 plan */
};

struct bpf_jit_start_map {
	u32 subprog_idx;
	u32 nr_entries;
	struct bpf_jit_start_map_entry entries[];
};

struct bpf_jit_emit_ctx {
	u8 *image;
	u8 *scratch;
	u32 *addrs;
	u32 oldproglen;
	u32 proglen;
	bool image_pass;
	bool use_priv_fp;
};
```

dispatcher 逻辑是统一的：

1. `bpf_idx = i - 1`
2. 查询 `start_map[bpf_idx]`
3. 若无 plan，走 stock emission
4. 若有 plan，调用对应 emitter alt
5. `APPLIED` 则跳过整个 span 并统一 commit
6. `FALLBACK` 则只发当前指令的 stock emission，不跳过 span

与 POC v2 的对比：

- v2：compact/diamond 两处手工写死，分别更新 `addrs[i-1...i+2]` 与 `addrs[i...i+3]`
- v3：一个 dispatcher 处理所有 family，消除“某个 switch case 才能看见 directive”的结构缺陷
- 这也顺手修掉了 v2 那种“verifier 接受 `BPF_X`，但 JIT 某个 `*_K` case 才查 directive”的路径分裂

安全性分析：

- 只接受单入口、连续 span、无 interior edge 的 region
- dispatcher 不重新解释 pattern，不做重新匹配，只消费 validator 产出的 plan
- 对 JIT 来说，plan 是只读的；JIT 不能修改合法性状态

实现工作量：

- x86 通用 dispatcher glue：`180-260 LOC`
- 用 dispatcher 替换 v2 两个 `cmov_select` 专用 hook：`80-120 LOC`

### 3.2 通用 Plan System

plan system 的任务是把“用户态上传的 rule record”编译成“JIT 可以 O(1) 消费的冻结站点描述”。JIT 不再读 pattern IR，不再做 CFG 查询，不再读 verifier side table。

```c
struct bpf_jit_site_key {
	u32 orig_start;
	u16 orig_len;
	u16 rule_id;
};

struct bpf_jit_plan_hdr {
	struct bpf_jit_site_key key;
	u32 cur_start;
	u16 cur_len;
	u16 family;
	u16 alt_id;
	u16 policy_prio;
	u16 private_len;
	u16 budget_cost;
	u16 reserved;
	u32 private_off;
};

union bpf_jit_plan_private {
	struct bpf_jit_select_plan select;
	struct bpf_jit_addr_mode_plan addr_mode;
	struct bpf_jit_rotate_plan rotate;
	struct bpf_jit_wide_mem_plan wide_mem;
};
```

plan materialization 的关键原则：

- 用户态 record 用 `orig_start + orig_len` 标识原始 BPF site
- 内核在最终 BPF 流上通过 `insn_aux_data[i].orig_idx` 做 range remap
- remap 完成后，把所有 family 所需的派生信息都冻结到 `plan_private`
- cross-site 排序只冻结一个字段：`policy_prio`
- budget charging 只冻结一个字段：`budget_cost`，且它来自 kernel-selected alt，而不是用户伪造的成本值

与 POC v2 的对比：

- v2 的 validated 结果只有 `subprog_idx + insn_idx + payload`
- v3 的 plan 额外冻结了：
  - 当前 span 边界
  - 选中的 alt
  - overlap arbitration 读取的 `policy_prio`
  - size budget 计费值
  - family-private 派生字段

安全性分析：

- 因为 framework 自己不改写 BPF，`orig_range -> cur_range` 的映射不再需要 block permutation provenance
- plan 只在 verifier 结束时生成一次；JIT 不再依赖动态的 verifier facts
- plan 是“已验证的 lowering site”，不是“待执行的小程序”

实现工作量：

- plan allocator / arena / lookup：`150-220 LOC`
- `orig_range` remap + freeze private payload：`120-180 LOC`

### 3.3 通用 Alt Table / Emitter Registry

这部分是 v3 降低新增 directive 成本的关键。新增 rule 不该再改 transport、lookup、dispatcher；它只需要把合法 site 绑定到某个 kernel-owned emitter alt。

```c
enum bpf_jit_emit_status {
	BPF_JIT_EMIT_APPLIED  = 1,
	BPF_JIT_EMIT_FALLBACK = 2,
	BPF_JIT_EMIT_FATAL    = 3,
};

struct bpf_jit_emit_result {
	u8 status;
	u8 reserved;
	u16 emitted_len;
};

struct bpf_jit_alt_desc {
	u16 arch_id;
	u16 family;
	u16 alt_id;
	u16 alt_rank;      /* same-site alt ordering, not cross-site policy */
	u16 budget_cost;   /* worst-case positive code-size charge */
	u64 feature_must_have;
	void (*emit)(struct bpf_jit_emit_ctx *ctx,
		     const struct bpf_jit_region_plan *plan,
		     const void *private_data,
		     struct bpf_jit_emit_result *res);
};

struct bpf_jit_family_ops {
	u16 family;
	u16 default_policy_prio;
	int (*exact_validate)(struct bpf_verifier_env *env,
			      const struct bpf_jit_rule_rec_v3 *rec,
			      struct bpf_jit_plan_hdr *plan,
			      void *private_dst);
	int (*select_alt)(const struct bpf_jit_cpu_contract *cpu,
			  const struct bpf_jit_target_desc *target,
			  const struct bpf_jit_rule_rec_v3 *rec,
			  struct bpf_jit_plan_hdr *plan);
};
```

**per-site fallback contract** 必须写清楚：

- `APPLIED`：region 成功发射，dispatcher 跳过整个 span
- `FALLBACK`：只禁用当前 site，本次 JIT 继续按 stock emission 逐条发射
- `FATAL`：只保留给内核不变量被破坏的情况，例如 image pass 长度不一致；它不是普通 rule miss 的返回路径

`emit()` 的 pseudo-API 也必须统一：**site outcome 只由 `bpf_jit_emit_result.status` 表达**。`emit()` 本身不再返回第二份 status；否则实现者会在“函数返回值”和“结果结构体”之间制造双重真相。

这解决了 review 指出的 contract 缺口。对正常规则而言，绝大多数“不满足条件”应该在 materialization 阶段被过滤；JIT 阶段允许出现的失败，应该几乎都属于 `FALLBACK`，而不是整次 JIT 失败。

与 POC v2 的对比：

- v2：`kind -> hardcoded lookup -> hardcoded emitter`
- v3：`family -> alt table -> generic dispatcher`
- v2：新增 directive 要新增 lookup 调用点
- v3：新增既有 family 内 rule，不需要改 dispatcher

安全性分析：

- alt id 只在 kernel registry 中解析，用户态不能指定原生字节
- CPU feature gating 发生在 alt table，不发生在用户态
- `alt_rank` 只用于**同一个 site 内**的 emitter 选择，不能拿来覆盖 userspace 的 cross-site `policy_prio`
- `FATAL` 被限制到内核 bug / invariant break，避免把“站点不适用”升级成“整次 JIT 失败”

实现工作量：

- registry / alt lookup / status contract：`150-220 LOC`
- 每新增一个 emitter alt：`50-100 LOC/arch`

### 3.4 通用 Transport / Validation Pipeline

transport 要解决的不是“让用户上传更复杂的 payload”，而是一次性把 size check、digest bind、CPU gating、exact validation、arbitration 都做成共享管线。

```c
struct bpf_jit_rule_bundle_hdr_v3 {
	__u32 magic;
	__u16 version;
	__u16 hdr_len;
	__u32 total_len;
	__u32 rec_cnt;
	__u32 insn_cnt;
	__u8  prog_tag[BPF_TAG_SIZE]; /* 当前 kernel UAPI 中 BPF_TAG_SIZE == 8 */
	__u16 budget_cnt;
	__u16 budget_off;
	__u16 arch_id;
	__u16 flags;
};

#define BPF_JIT_POLICY_PRIO_MAX 1023

struct bpf_jit_subprog_budget_v3 {
	__u16 subprog_idx;
	__u16 reserved;
	__s32 max_extra_jited_bytes; /* < 0 表示不限额 */
};

#define BPF_JIT_RULE_MAX_PAT       8
#define BPF_JIT_RULE_MAX_CST      16
#define BPF_JIT_RULE_MAX_ACT       4
#define BPF_JIT_RULE_MAX_ALT_PREF  4

struct bpf_jit_cpu_contract {
	__u64 must_have;
	__u64 must_not_have;
	__u16 arch_id;
	__u16 min_bundle_version;
};

struct bpf_jit_rule_rec_v3 {
	__u16 family;
	__u16 pattern_id;
	__u16 rule_id;
	__u16 orig_len;
	__u32 orig_start;
	__u16 policy_prio;  /* userspace-owned, clamped to MAX */
	__u16 reserved;
	__u16 pat_cnt;
	__u16 cst_cnt;
	__u16 act_cnt;
	__u16 rec_len;
	__u16 cpu_off;
	__u16 cpu_len;
	__u16 payload_off;
	__u16 payload_len;
};
```

validation pipeline 统一分 5 步：

1. transport parse：sealed memfd、长度、偏移、record 上界检查
2. digest bind：`prog_tag + insn_cnt` 绑定到当前程序
3. final remap：在最终 BPF 流上解析 `orig_start/orig_len`
4. exact validate：generic constraints + family exact validator
5. arbitration：去重、去重叠、构建 `start_map`

### 3.4.1 Policy Ownership / Priority / Budget Contract

这部分必须把“谁拥有 policy”写成可执行 contract，而不是口号。

1. **cross-site priority 的所有权在 userspace**  
   overlap arbitration 读取的唯一 policy 字段是 `rec.policy_prio`。内核只做两件事：把它 clamp 到 `[0, BPF_JIT_POLICY_PRIO_MAX]`，以及在 materialization 后把它冻结进 `plan.policy_prio`。  
   `family_ops.default_policy_prio` 只在用户态没有显式给出 `policy_prio` 时使用；它不能反超一个显式更高优先级的合法 userspace site。

2. **userspace 可以给出 bounded budget，但 kernel 只做机械执行**  
   bundle 可选携带 `subprog_budget[]`。它表达的是“这个 subprog 最多允许多少正向 code-size 增长”。  
   每个 accepted alt 的 `budget_cost` 由 kernel registry 提供并冻结到 plan；userspace 不上传成本值，只决定优先级和是否启用预算。这样 budget 仍是 userspace policy，但 cost accounting 仍由 kernel 控制。

3. **kernel 不能做隐藏的 policy override**  
   对两个都合法、且都在预算内的重叠候选，kernel 必须先看 `policy_prio`；只有在 `policy_prio` 相同或缺失时，才允许进入 deterministic tie-break。  
   kernel 不能因为“自己觉得这个 alt 更便宜/更快”就把低优先级合法 site 提升到高优先级 site 之前。

4. **kernel 只允许 legality-only filter**  
   kernel 可以推翻 userspace 请求的情况只有：digest 不匹配、CPU feature 不满足、family exact validator 失败、arch alt 不可用、program 处于 blinded path、或该 site 会超出 userspace 自己给出的 budget。  
   这些都是 legality / availability / budget enforcement；它们不是 policy override。

5. **same-site alt 选择与 cross-site priority 分离**  
   `alt_pref[]` 是 userspace 给出的**同一 site 内**偏好顺序；kernel 只允许在这个列表里从前往后找第一个合法 alt。  
   若 `alt_pref[]` 全部不可用，只有在 `policy_flags` 显式允许 `BPF_JIT_POLICY_F_ALLOW_KERNEL_DEFAULT` 时，kernel 才能退回 family default alt；否则该 site 直接 reject/fallback。

**overlap arbitration** 也必须是通用规则，而不是 family-specific ad-hoc 代码：

```c
struct bpf_jit_arbitration_key {
	u16 policy_prio; /* 高优先级先选，归 userspace 所有 */
	u16 span_len;   /* 同优先级时长窗口优先 */
	u32 cur_start;  /* 再按起点稳定排序 */
	u32 rule_id;    /* 最后按 rule_id 打破平局 */
};
```

规则定义：

1. 同一 subprog 内，先按 `policy_prio desc, span_len desc, cur_start asc, rule_id asc` 排序
2. 维护一个已接受 interval set，以及 userspace 指定的剩余 `subprog_budget`
3. 任意 `[start, end)` 与已接受区间重叠的候选，统一拒绝并写 log
4. 任意会让该 subprog 超出 budget 的候选，也统一拒绝并写 log
5. 因而 `start_map` 中天然只有一个 plan，可 O(1) 查询

这直接回应了 review 的 `start_map overlap arbitration` 问题。

与 POC v2 的对比：

- v2 只会拒绝“同一 kind、同一 insn_idx”的重复记录
- v3 统一处理“同一起点冲突”和“不同起点但区间重叠”两类冲突
- v2 没有 digest bind；v3 明确把 bundle 绑定到 `prog_tag`

安全性分析：

- `pat_cnt <= 8`、`cst_cnt <= 16`、`act_cnt <= 4`、`rec_len` 自洽等上界检查必须在 transport 阶段硬编码
- final remap 发生在最终 BPF 流上，避免“后续 fixup 改变了 site”的漂移
- `prog_tag` 复用真实 kernel UAPI 的 `BPF_TAG_SIZE == 8`；如果未来要更强 digest，应单独加新字段，而不是伪装成现有 prog tag
- arbitration 保证 dispatcher 永远只看见一条 plan，不会在 JIT hot path 做冲突判断

实现工作量：

- v3 bundle parser + bounds checking：`180-260 LOC`
- digest bind + arbitration + log：`180-260 LOC`

### 3.5 通用 `addrs[]` Commit

`addrs[]` 是现有 `do_jit()` fixed-point 模型的核心。v3 不能绕开它，而是要把每个 directive 手写的地址提交收束成一个共享 helper。

```c
struct bpf_jit_commit_range {
	u32 start_insn;
	u32 end_insn;      /* 半开区间 [start, end) */
	u32 native_start;
	u32 native_end;
};

static inline void
bpf_jit_commit_range(u32 *addrs, const struct bpf_jit_commit_range *r)
{
	u32 i;

	for (i = r->start_insn; i < r->end_insn; i++)
		addrs[i] = r->native_start;
	addrs[r->end_insn] = r->native_end;
}
```

commit contract：

1. `APPLIED` 时统一调用 `bpf_jit_commit_range()`
2. `FALLBACK` 时不调用 commit helper，保持 stock per-insn 逻辑
3. image pass 必须满足 `native_end == addrs[end_insn]`

与 POC v2 的对比：

- v2：compact 和 diamond 各写一份地址更新逻辑
- v3：所有 family 共用同一 helper，emitter 只负责报告 span 和实际长度

安全性分析：

- JIT 仍然遵守原有两遍 fixed-point 模型
- 如果某个 site 在 measure pass 选择了 `FALLBACK`，它在 image pass 也必须 `FALLBACK`
- 一旦 image pass 出现“measure pass 和 image pass 长度不一致”，这是 `FATAL`，因为它说明 emitter 不满足 pass-determinism

实现工作量：

- commit helper + generic region bookkeeping：`80-140 LOC`
- 每个新 rule 的增量成本：`0 LOC`

---

## 4. Pattern / Constraint / Action IR

v3 的 IR 不是一个通用 rewrite DSL，而是一个**受限 site selector IR**。它的职责只有三件事：

1. 描述某个局部 BPF 窗口的形状
2. 描述 kernel 能直接验证的约束
3. 指向 kernel 内建 semantic alt

### 4.1 Pattern IR

旧稿在这里有一个明确缺口：缺少 load/store 宽度和 mode 字段，导致 `wide_load` 的关键语义被推给 family-specific validator。这个缺口需要补上。

```c
enum bpf_jit_ir_width {
	BPF_JIT_W_ANY = 0,
	BPF_JIT_W8,
	BPF_JIT_W16,
	BPF_JIT_W32,
	BPF_JIT_W64,
};

enum bpf_jit_ir_mem_mode {
	BPF_JIT_MM_NONE = 0,
	BPF_JIT_MM_MEM,
	BPF_JIT_MM_PROBE_MEM,
	BPF_JIT_MM_MEMSX,
};

enum bpf_jit_pat_op {
	BPF_JIT_PAT_MOV = 1,
	BPF_JIT_PAT_ALU,
	BPF_JIT_PAT_JCC,
	BPF_JIT_PAT_JA,
	BPF_JIT_PAT_LOAD,
	BPF_JIT_PAT_STORE,
	BPF_JIT_PAT_ENDIAN,
};

struct bpf_jit_pat_node {
	__u8  op;
	__u8  bpf_class_mask;
	__u8  width;        /* 修正点：显式区分 B/H/W/DW */
	__u8  mem_mode;     /* 修正点：显式区分 MEM/PROBE_MEM/MEMSX */
	__u8  flags;
	__u8  dst_slot;
	__u8  src_slot;
	__u8  base_slot;
	__u8  aux_slot;
	__s16 off;
	__s32 imm;
};
```

### 4.2 Constraint IR

```c
enum bpf_jit_constraint_op {
	BPF_JIT_C_SAME_SLOT = 1,
	BPF_JIT_C_SAME_WIDTH,
	BPF_JIT_C_STRAIGHT_LINE,
	BPF_JIT_C_SAME_SUBPROG,
	BPF_JIT_C_NO_INTERIOR_EDGE,
	BPF_JIT_C_NO_CALLS,
	BPF_JIT_C_NO_SIDE_EFFECTS,
	BPF_JIT_C_LIVEOUT_MASK,
	BPF_JIT_C_IMM_RANGE,
	BPF_JIT_C_CONST_OFF_RANGE,
	BPF_JIT_C_SAME_MEM_BASE,
	BPF_JIT_C_CONTIGUOUS_OFFS,
	BPF_JIT_C_MEM_CLASS,
	BPF_JIT_C_TARGET_FEATURE,
};

struct bpf_jit_constraint {
	__u8  op;
	__u8  a;
	__u8  b;
	__u8  flags;
	__s32 imm0;
	__s32 imm1;
};
```

### 4.3 Action IR

```c
enum bpf_jit_action_op {
	BPF_JIT_A_SELECT_ALT = 1,
	BPF_JIT_A_FUSE_ADDR_MODE,
	BPF_JIT_A_FUSE_ROTATE,
	BPF_JIT_A_FUSE_WIDE_MEM,
};

#define BPF_JIT_POLICY_F_ALLOW_KERNEL_DEFAULT (1U << 0)

struct bpf_jit_action {
	__u8  op;
	__u8  alt_pref_cnt;
	__u16 alt_pref[4];
	__u32 policy_flags;
};
```

这里的 ownership 要保持单值：

- `rec.policy_prio` 负责 **cross-site policy ordering**
- `action.alt_pref[]` 负责 **same-site alt preference**
- `alt_desc.alt_rank` 只负责 **kernel registry 内部的同 site 稳定顺序**

三者不能混用，否则“谁拥有 priority”会重新变模糊。

与 POC v2 的对比：

- v2 没有 IR，只有一个 `kind + payload`
- 旧稿的 IR 缺少 load/store 宽度和 mem mode
- 新 IR 明确把 width/mode 放进 pattern 层，从而让 `wide_load` 的大部分合法性进入共享 IR，而不是藏在 family validator 里

安全性分析：

- IR 不能表达机器码，也不能表达“替换成另一串 BPF”
- IR 不能描述任意 CFG rewrite，只能描述局部窗口和受限约束
- action 指向的是 kernel-owned alt id，不是用户自定义实现

实现工作量：

- UAPI / parser / bounds check 更新：`150-240 LOC`
- 把 width/mode 接入 exact validator：`60-100 LOC`

---

## 5. Rule 安全性验证模型

v3 的安全模型要回答的不是“用户态 rule 是否聪明”，而是“内核能否把它约束成只影响 native lowering”。验证模型可以拆成 4 层。

### 5.1 传输层安全

```c
enum bpf_jit_reject_reason {
	BPF_JIT_RJ_BAD_BLOB = 1,
	BPF_JIT_RJ_DIGEST_MISMATCH,
	BPF_JIT_RJ_ARCH_MISMATCH,
	BPF_JIT_RJ_RANGE_REMAP_FAIL,
	BPF_JIT_RJ_PATTERN_MISMATCH,
	BPF_JIT_RJ_CONSTRAINT_FAIL,
	BPF_JIT_RJ_FAMILY_VALIDATE_FAIL,
	BPF_JIT_RJ_ALT_UNAVAILABLE,
	BPF_JIT_RJ_OVERLAP_REJECT,
	BPF_JIT_RJ_BUDGET_EXCEEDED,
	BPF_JIT_RJ_BLINDED_PROG,
};

struct bpf_jit_rule_log_entry {
	u32 rule_id;
	u32 orig_start;
	u16 family;
	u16 reason;
	s32 detail0;
	s32 detail1;
};
```

传输层负责：

- sealed memfd 检查
- `magic/version/rec_len` 检查
- digest bind
- arch / CPU contract 检查

### 5.2 结构层安全

结构层验证所有不依赖特定 family 的事实：

- `orig_range` 能 remap 到唯一当前窗口
- 窗口在单一 subprog 内
- 直线段或受限 diamond，无 interior edge
- liveout / side-effect / calls 约束成立

### 5.3 family 精确验证

family validator 只做该家族不可共享的最后一步。例如：

- `SELECT`：验证两臂都是真正的 simple mov
- `ADDR_MODE`：验证 scale/disp 落在目标 ISA 可接受的集合内
- `ROTATE`：验证 shift 常量满足 `lhs + rhs == width`
- `WIDE_MEM`：验证是 contiguous byte ladder，且 mem class 在 MVP 白名单中；exact shape 见 §8.4.1

### 5.4 backend 发射安全

emit contract 必须满足：

```c
struct bpf_jit_emission_contract {
	bool pass_deterministic;
	bool no_bpf_rewrite;
	bool site_local_fallback;
	bool exact_addrs_commit;
};
```

解释如下：

1. `pass_deterministic`：measure pass、收敛 loop、padding/extra pass、image pass 必须读取同一份冻结 plan，并作出同一 alt / fallback 选择
2. `no_bpf_rewrite`：发射只能改原生 bytes，不能回写 BPF
3. `site_local_fallback`：单个 site 失败只回退这个 site
4. `exact_addrs_commit`：`APPLIED` 的 site 必须满足 `addrs[end]` 一致性

`pass_deterministic` 还隐含一条禁止项：第二遍选择不能依赖当前 `proglen`、当前 `addrs[]` 收缩结果、随机数、或 image 地址。允许影响选择的输入只有冻结后的 `plan`、target feature bits、以及整个 JIT 生命周期内稳定的 arch context。

与 POC v2 的对比：

- v2 的安全性主要来自“只有一个 kind，人工 audit 可控”
- v3 把安全性拆成共享验证层 + family validator + backend contract，避免每个新 rule 重写一次 fail-closed 逻辑

安全性结论：

- 由于 v3 永远不改 `prog->insnsi`，`xlated_prog_len` 天然保持不变
- 所有风险都被压缩到“该 site 是否允许另一种 native lowering”这个问题上
- 因而 reject / fallback 也天然可以做到 per-site，而不必升级成 whole-JIT failure

实现工作量：

- reject reason / logging：`120-180 LOC`
- generic validators：`120-180 LOC`

---

## 6. JIT Backend 抽象层（x86 具体设计）

v3 在 x86 上的落地点不是“再加几个 `if (directive)`”，而是把 `do_jit()` 前半段重构成统一的 region dispatch 前门。

```c
struct bpf_jit_x86_subprog_ctx {
	const struct bpf_jit_pass_state *state;
	const struct bpf_jit_target_desc *target;
	u32 func_idx;
	bool use_priv_fp;
};

struct bpf_jit_x86_emit_ops {
	void (*emit_mov_reg)(u8 **pprog, bool is64, u32 dst, u32 src);
	void (*emit_mov_imm32)(u8 **pprog, bool is64, u32 dst, s32 imm);
	int (*emit_cmp)(u8 **pprog, const struct bpf_insn *insn,
			u32 dst_reg, u32 src_reg);
};
```

建议的 `do_jit()` 入口形态：

```c
const struct bpf_jit_region_plan *plan;
struct bpf_jit_emit_result res;

plan = bpf_jit_lookup_region(bpf_prog, func_idx, i - 1);
if (plan) {
	res.status = BPF_JIT_EMIT_FALLBACK;
	bpf_jit_emit_region_x86(&ctx, plan, &res);
	if (res.status == BPF_JIT_EMIT_APPLIED) {
		bpf_jit_commit_range(addrs, &range);
		i += plan->end_insn - plan->start_insn - 1;
		insn += plan->end_insn - plan->start_insn - 1;
		continue;
	}
}
```

插入点也要写实一些：region lookup 放在 `do_jit()` 每次取到当前 `bpf_idx = i - 1`、进入原有大 `switch` 之前；measure/convergence loop、padding/extra pass、final image pass 全部读取同一份 `state->plans + start_map + alt_id`。也就是说，v3 **不允许**在 pass 之间基于“这次 code size 又缩了”重新做一次 policy 选择。

x86 只保留两类代码：

1. 通用 dispatch / fallback glue
2. 每个 alt 的 emitter

pattern 再匹配、payload 解释、冲突处理都不应再出现在 `do_jit()` 里。

与 POC v2 的对比：

- v2 有两个手工 hook 点：compact 前门和 `*_K` 条件跳转分支
- v3 只有一个统一前门，不再依赖某个 `switch` case 是否记得查 directive
- v2 的 `BPF_X` diamond 漏洞，本质上是“hook 点和 matcher 语言不一致”；v3 结构上消除了这类问题

安全性分析：

- x86 `do_jit()` 不再做 legality 判断，只执行已冻结 plan
- 所有 family 共享同一 fallback 语义
- `FATAL` 只出现在 image pass 长度不一致等内核 invariant break；普通 site miss 不得让整次 JIT 失败

实现工作量：

- x86 dispatcher 重构：`220-320 LOC`
- 复用现有 `emit_bpf_cmov_select*()` 迁移到 emitter registry：`80-120 LOC`

---

## 7. 跨架构 Target Description

target description 的目标不是把 policy 内核化，而是把“某个 semantic op 在该架构上有哪些 kernel-owned lowering alt”编码出来。它必须足够轻，但不能退回 x86-only ifdef。

```c
enum bpf_jit_arch_id {
	BPF_JIT_ARCH_X86_64 = 1,
	BPF_JIT_ARCH_ARM64  = 2,
};

enum bpf_jit_target_feature {
	BPF_JIT_TF_COND_MOVE        = (1ULL << 0),
	BPF_JIT_TF_SCALE_ADDR       = (1ULL << 1),
	BPF_JIT_TF_ROTATE_IMM       = (1ULL << 2),
	BPF_JIT_TF_UNALIGNED_LOAD   = (1ULL << 3),
	BPF_JIT_TF_X86_BMI2         = (1ULL << 16),
	BPF_JIT_TF_ARM64_EXTR       = (1ULL << 17),
};

struct bpf_jit_target_desc {
	u16 arch_id;
	u16 alt_cnt;
	u64 feature_bits;
	const struct bpf_jit_alt_desc *alts;
};
```

每个 family 只面向 semantic alt 选项，而不是面向具体机器码。例如：

- `SELECT`
  - x86：`cmp/test + cmovcc`
  - arm64：`cmp + csel`
- `ADDR_MODE`
  - x86：`lea` 或 folded load/store addressing mode
  - arm64：`add shifted register`
- `ROTATE`
  - x86：`ror` / `rorx`
  - arm64：`ror`
- `WIDE_MEM`
  - x86：`mov`/`movzx` + extract
  - arm64：`ldr` + `ubfx`

与 POC v2 的对比：

- v2 完全没有 target description；x86 emitter 直接散在 `bpf_jit_comp.c`
- v3 用 `target_desc + alt_table` 把跨架构扩展点前置

安全性分析：

- userspace 只能请求 family 和 alt preference，不能请求“发 `rorx` 而不是 `ror`”这类机器码级别决策
- target description 由 kernel 提供，feature gating 也由 kernel 执行

实现工作量：

- 通用 `target_desc` 核心：`80-120 LOC`
- x86/arm64 alt table 建模：`50-100 LOC/arch`
- arm64 首次 bring-up 额外 plumbing：`300-600 LOC`

---

## 8. 4 个具体 Rule

这 4 个 family 的论文地位必须显式分层，不能再写成“4 个同强度样本”：

- **第一层：`SELECT`**  
  首个、当前最强的 why-userspace 证据。它既有 paper 中 `31 vs 0 cmov` 的静态 gap，也有 `no-cmov` mixed result 的 policy-sensitive 动态证据。
- **第二层：`WIDE_MEM`**  
  最大 backend gap 的 JIT-only recovery。它解释“为什么框架值得做”，但它本身不是与 `SELECT` 同强度的 userspace-policy 证据。
- **第三层：`ADDR_MODE` / `ROTATE`**  
  extensibility proof。它们证明 substrate 不是为一个 `cmov` 特例硬写出来的，但不应被包装成与 `SELECT` 同级的 why-userspace anchor。

因此，v3 不把这 4 个 family 全都包装成“论文已测得的 4 个 root cause”。更准确的说法是：`SELECT` 负责锚定 userspace-policy thesis，`WIDE_MEM` 负责锚定最大 backend gap 的正确层次修复，`ADDR_MODE` / `ROTATE` 负责证明**贡献是 extensible infrastructure，而不是单个 peephole**。

### 8.1 `cmov_select` (`SELECT` family)

这是从 POC v2 直接迁移的 rule，也是论文里最重要的 policy-sensitive lowering 代表。它直接承接 `paper-comparison.md` 的两个关键信号：

- JIT dump 中 kernel `cmov = 0`，而 LLVM 有 `31` 个 `cmov`
- `no-cmov` ablation 显示收益并不单调，说明它不是“永远该开”的 fixed heuristic，而是典型 policy-sensitive site

```c
enum bpf_jit_select_shape {
	BPF_JIT_SELECT_COMPACT = 1,
	BPF_JIT_SELECT_DIAMOND = 2,
};

struct bpf_jit_select_plan {
	u8  shape;
	u8  cond_op;
	u8  mov_width;
	u8  dst_slot;
	u8  true_src_kind;
	u8  false_src_kind;
	u8  reserved[2];
	s32 true_imm;
	s32 false_imm;
};
```

与 POC v2 的对比：

- v2：单一 `CMOV_SELECT` kind，payload 只有保留字段
- v3：`SELECT` family 把 compact/diamond、`BPF_K`/`BPF_X`、未来其它 select 变体统一进同一 plan
- v2 每新增一个 select 变体都要改 verifier matcher 和 JIT hook；v3 只需用户态产出新 pattern，内核复用 family validator 和 x86 emitter

安全性分析：

- 仅接受 simple mov arms
- 单一 liveout 目的寄存器
- 无 interior edge
- 不修改 BPF，只改变 `branch + mov` 与 `cmp + mov + cmov` 的 native lowering

实现工作量：

- 迁移 v2 emitter 到 registry：`60-100 LOC`
- `SELECT` family 通用 validator：`120-180 LOC`

### 8.2 `lea_fusion` (`ADDR_MODE` family)

`lea_fusion` 不是 characterization 论文的 headline root cause。它被放进 v3，是因为它满足三个条件：

1. 它是纯 `JIT_LOWERING`，不会碰 `xlated_prog_len`
2. 它来自计划文档里的真实候选（smallmul / parser indexing / local_call_fanout 类证据）
3. 它能证明 v3 的 family 机制不仅适用于 branch/select，也适用于地址形成类 lowering

`lea_fusion` 的价值不在于 `lea` 本身，而在于证明“地址形成类 lowering”可以被 family 化，而不是为每个算术小窗口单独开一个 directive。

```c
struct bpf_jit_addr_mode_plan {
	u8  dst_slot;
	u8  base_slot;
	u8  index_slot;
	u8  scale_log2;   /* 0,1,2,3 -> scale 1,2,4,8 */
	u8  value_width;
	u8  op_kind;      /* load-fold / store-fold / lea */
	u8  reserved[2];
	s32 disp;
};
```

与 POC v2 的对比：

- 在 v2 模式下，`lea_fusion` 需要重新发明一套新的 UAPI kind、payload、lookup、hook、commit
- 在 v3 里，它只是在既有 transport / dispatcher / commit 上增加一个 family validator 和 x86/arm64 emitter alt

安全性分析：

- 仅接受有限集合的 scale
- 仅接受 constant displacement
- 要求 liveout 与 flags 依赖满足 family 约束
- 对 JIT 的影响只是“地址计算在哪里被折叠”，不改变 BPF 语义

实现工作量：

- `ADDR_MODE` family validator：`100-160 LOC`
- x86 emitter alt：`80-120 LOC`
- arm64 emitter alt：`40-80 LOC`

### 8.3 `rotate_fusion` (`ROTATE` family)

`rotate_fusion` 同样不是 characterization 论文的 headline gap；它来自计划文档中的 Tier 2 候选，用来证明 v3 还能承载 bit-manip / ISA-feature-sensitive lowering。它之所以适合作为 v3 family，是因为 legality 简单稳定，而 alt 选择又明显依赖 target feature（如 BMI2）。

`rotate_fusion` 证明 v3 不只覆盖 select 和 addressing mode，也能覆盖典型 bit-manip lowering。

```c
enum bpf_jit_rotate_dir {
	BPF_JIT_ROR = 1,
	BPF_JIT_ROL = 2,
};

struct bpf_jit_rotate_plan {
	u8  dir;
	u8  value_width;
	u8  shift_imm;
	u8  dst_slot;
	u8  src_slot;
	u8  tmp_slot;
	u8  reserved[2];
};
```

与 POC v2 的对比：

- v2 完全没有 bit-manip family
- v3 允许把 `(x >> c) | (x << (w - c))` 与 `(x << c) | (x >> (w - c))` 统一进 `ROTATE` family

安全性分析：

- 只接受 constant shift
- 要求两侧 shift 互补，且 width 一致
- CPU feature 例如 BMI2 只影响 alt 选择，不影响 legality

实现工作量：

- `ROTATE` family validator：`80-140 LOC`
- x86 emitter alt：`80-120 LOC`
- arm64 emitter alt：`40-80 LOC`

### 8.4 `wide_load` (`WIDE_MEM` family，纯 JIT-level)

这是 v3 与 POC v1 最重要的切割点，也是与 characterization 论文绑定最紧的 family。`paper-comparison.md` 已经把 byte-load recomposition 定位为最大 backend gap：占 50.7% surplus，隔离时间惩罚 2.24x。v3 的 `WIDE_MEM` family 就是这个机会的**正确层次版本**：不是改 BPF，而是在已验证的 byte ladder site 上选择另一种 native lowering。

`wide_load` 在 v3 里必须明确是**native emission 选择**，而不是 verifier-side BPF rewrite。

```c
enum bpf_jit_mem_class {
	BPF_JIT_MC_STACK = 1,
	BPF_JIT_MC_MAP_VALUE = 2,
};

struct bpf_jit_wide_mem_plan {
	u8  mem_class;
	u8  total_width;   /* 2/4/8 */
	u8  elem_width;    /* MVP 固定为 1 */
	u8  endian;        /* MVP 固定 little-endian */
	u8  dst_slot;
	u8  base_slot;
	u8  part_cnt;
	u8  reserved;
	s16 base_off;
};
```

MVP 安全子集必须明确收窄为：

- 仅 `stack` / `map-value`
- 仅 non-`PROBE_MEM`
- 仅 contiguous byte ladder
- 不覆盖 packet/ctx
- 仅 little-endian 的 `elem_width == 1` ladder

与 POC v2 / v1 的对比：

- 相对 v2：`wide_load` 不需要新增 transport、dispatcher、commit；只新增 `WIDE_MEM` family validator 和 emitter
- 相对 v1：v1 改的是 BPF 指令流，因此方向错误；v3 改的是 native lowering，符合 `xlated_prog_len` 不变的原则

安全性分析：

- family validator 必须检查 load width、mem mode、contiguous offsets、same base、同一 mem class
- JIT 只是在 native 层一次宽 load 再做 extract，不改 BPF 指令语义
- packet/ctx 与 `PROBE_MEM` 排除在 MVP 外，避免把 extable / faulting path 混进首版框架

### 8.4.1 `WIDE_MEM` exact validator（MVP 实现级 contract）

MVP 的 `WIDE_MEM` validator 不做“看起来像 wide load 就接受”的模糊匹配；它只接受**极窄的 canonical byte ladder**。

**正例形状 A：stack 上的 little-endian 4-byte ladder**

```text
r1 = *(u8 *)(r10 - 8)
r2 = *(u8 *)(r10 - 7)
r2 <<= 8
r1 |= r2
r2 = *(u8 *)(r10 - 6)
r2 <<= 16
r1 |= r2
r2 = *(u8 *)(r10 - 5)
r2 <<= 24
r1 |= r2
```

接受条件：

- 所有 load 都是 `LDX | MEM | B`
- base slot 恒定（这里是 `r10`）
- offset 精确连续：`base_off + 0/1/2/3`
- 只有一个最终 liveout 聚合值（这里是 `r1`）
- 中间寄存器 `r2` 不外泄，只用于当前 ladder

**正例形状 B：map-value 上的 little-endian 8-byte ladder**

```text
r1 = *(u8 *)(r6 + 0)
r2 = *(u8 *)(r6 + 1); r2 <<= 8;  r1 |= r2
r2 = *(u8 *)(r6 + 2); r2 <<= 16; r1 |= r2
...
r2 = *(u8 *)(r6 + 7); r2 <<= 56; r1 |= r2
```

接受条件与 stack 相同，只是 mem class 必须是 `MAP_VALUE`，且 `[base_off, base_off + total_width)` 必须完全落在 verifier 已证明安全的 value range 内。

**反例形状（必须 reject）**

```text
; 1. mixed base
r1 = *(u8 *)(r6 + 0)
r2 = *(u8 *)(r7 + 1)

; 2. non-contiguous offset
r1 = *(u8 *)(r6 + 0)
r2 = *(u8 *)(r6 + 2)

; 3. intermediate value escapes
r1 = *(u8 *)(r6 + 0)
r3 = r1

; 4. side effect / helper / store in the middle
r1 = *(u8 *)(r6 + 0)
call bpf_foo

; 5. partial aggregate participates in branch/compare before completion
r1 = *(u8 *)(r6 + 0)
if r1 == 0 goto L

; 6. non-MEM or non-byte load
r1 = *(u16 *)(r6 + 0)
```

精确 reject 规则：

1. **intermediate use reject**：任何 byte result 或 partial aggregate 一旦被当前 ladder 之外的指令读取，立即 reject。  
   这包括复制到第三个寄存器、作为 helper 参数、作为 store 值、或作为后续非 ladder ALU 输入。
2. **side-effect reject**：ladder 中间不允许 `CALL`、`STX/ST`、atomic、tail call、或任何会让 memory/CFG state 变化的指令。
3. **branch / flags-dependence reject**：ladder 中间不允许 `JCC/JA` 读取 partial aggregate 或 temp；BPF 虽然没有显式 flags SSA，但任何“部分值先参与比较/分支”的形状都视为 escape。
4. **shape reject**：只接受 little-endian、零扩展 byte ladder；`MEMSX`、`PROBE_MEM`、mixed width、mixed mem class、balanced tree、字节顺序重排，一律 reject。
5. **alignment / target reject**：若目标架构没有稳定的 unaligned wide-load alt，则 exact validator 必须额外证明 `base_off` 对 `total_width` 对齐；否则该 alt 不可用并记录 reject。

**每个 mem class 的 MVP 安全理由**

- `STACK`：verifier 已经证明访问落在当前 BPF frame 内；把多个相邻 byte load collapse 成一个 wide native load，只触及同一段已验证 stack window，不引入新的 fault path，也不需要 extable 语义。
- `MAP_VALUE`：base 是 verifier 认可的 `PTR_TO_MAP_VALUE`，访问对象是连续 map value 内存；只要总窗口仍在同一 value range 内，wide load 与 byte ladder 触及的是同一对象，且 MVP 明确排除了 `PROBE_MEM`/faulting access。

因此，MVP 的 `WIDE_MEM` 不是“所有 wide-load 看起来都能做”，而是**只在 stack/map-value 的 canonical byte ladder 上做 JIT-only collapse**。

实现工作量：

- `WIDE_MEM` family validator：`120-200 LOC`
- x86 emitter alt：`120-180 LOC`
- arm64 emitter alt：`80-120 LOC`

---

## 9. 从 POC v2 到 v3 的渐进实现路径

v3 不需要推倒重来。正确路径是：**先把 v2 的 transport 和 `cmov_select` 迁成通用 substrate，再逐步挂上新的 family**。

```c
struct bpf_jit_v2_compat_rec {
	__u32 site_idx;
	__u16 family;      /* 固定映射到 SELECT */
	__u16 pattern_id;  /* compact / diamond */
	__u16 preferred_alt;
	__u16 reserved;
};
```

建议的 5 步路径：

1. `v2 -> v3 transport shim`
   - 复用 sealed memfd、基本 header 校验
   - 让旧 `CMOV_SELECT` blob 能被翻译成 `SELECT` family raw record
2. 通用 dispatcher + 通用 commit
   - 先只接 `SELECT`
   - x86 上用现有 `emit_bpf_cmov_select*()` 跑通
3. plan system + overlap arbitration + logging
   - 把 v2 的 `validated_cnt + linear lookup` 升级为 `plans + start_map + reject logs`
4. 增加 `ADDR_MODE`、`ROTATE`
   - 不改 transport / dispatcher
   - 只加 family validator 和 emitter alt
5. 增加 `WIDE_MEM`
   - 首版只做 `stack/map-value`
   - packet/ctx 以后再作为 `WIDE_MEM` 扩展，而不是新架构

里程碑工作量可以这样估算：

| 步骤 | 主要内容 | 预计 LOC |
|------|----------|----------:|
| Step 1 | v2 compat + bundle parser | 150-250 |
| Step 2 | generic dispatcher + generic commit | 250-400 |
| Step 3 | plan system + arbitration + logs | 300-450 |
| Step 4 | `ADDR_MODE` + `ROTATE` | 250-450 |
| Step 5 | `WIDE_MEM` MVP | 200-350 |

总计：

- x86 的 JIT-only MVP **核心内核改动**：`1200-2000 LOC`
- hardening / observability / selftests / negative tests / 论文评估 plumbing：额外 `500-900 LOC`
- 加上 arm64：额外 `300-600 LOC`

与 POC v2 的对比：

- v2 的增量是“继续堆 directive”
- v3 的增量是“先付一次 infrastructure 成本，然后把每个新 rule 降成 family/plugin 的局部增量”

为什么新增成本会从 `~300 LOC/directive` 降到 `~50-100 LOC/directive`：

1. transport / validation / dispatcher / `addrs[]` commit 只实现一次
2. 既有 family 内新增 rule 不再需要新增 UAPI kind
3. 既有 family 内新增 rule 不再需要新增 JIT hook 点
4. 常见情况下只需为目标架构注册一个 emitter alt

更精确地说：

- 新增**既有 family 内 rule**：`0 LOC` 核心框架 + `50-100 LOC/arch` emitter alt
- 新增**新 family**：`100-250 LOC` family validator + `50-100 LOC/arch` emitter alt

安全性分析：

- 这条迁移路径始终维持 `xlated_prog_len` 不变
- 即使只做到 Step 4，也已经是完整的 JIT-only v3
- `branch_reorder` 和 `bounds_window` 不属于这条路径，不应混入 v3 的交付范围

---

## 10. 论文 Story

v3 的论文主角不应是某一条 peephole，而应是**可扩展的 backend policy substrate**。这个 story 必须同时接住 characterization 论文的两条主线：

1. 差距确实在 backend lowering，而不是 bytecode
2. 真正起作用的是少量 backend combine / CFG cleanup，而不是完整 LLVM pipeline

因此，v3 要讲的不是“kernel 需要一个更大的 compiler”，而是“kernel 需要一个 bounded、fail-closed、可由 userspace 驱动 policy 的 lowering substrate”。这个 story 还必须回答 review 的核心担忧：如果 `lea_fusion` 和 `rotate_fusion` 能直接做成 kernel peephole，为什么还需要 userspace rule？

答案是：论文的 novelty 从来不在个别 peephole，而在于**bounded extensibility + policy-sensitive lowering**。

```c
struct bpf_jit_policy_sample {
	u32 rule_id;
	u16 family;
	u16 alt_id;
	s16 code_size_delta;
	s32 cycles_delta;
	u16 accept_reason;
	u16 reject_reason;
};
```

v3 的 story 应该这样组织：

1. Characterization 先证明差距主要来自 backend lowering，而不是 BPF bytecode
2. pass ablation 进一步说明：closing 这个 gap 不需要把完整 LLVM 放进 kernel，只需要能承载少数有价值的 backend lowering family
3. `cmov_select` / `SELECT` 证明同一个合法 site 的最优 lowering 会随 workload / CPU 变化，因而需要 userspace policy；它是当前 MVP 的主锚点
4. `wide_load` / `WIDE_MEM` 证明最大实证 gap 可以在**不改 BPF**的前提下，以 JIT-only lowering 方式纳入同一 framework；它主要回答“为什么 backend substrate 值得做”
5. `lea_fusion`、`rotate_fusion` 证明这不是一个只为 `cmov` / `wide_load` 特制的点方案，而是一个可扩展 substrate；它们是 extensibility witness，不是同强度 why-userspace anchor
6. 真正的贡献是：
   - kernel 持有 legality 和 native emission ownership
   - userspace 持有 profitability 和 rollout policy
   - 两者通过 fail-closed、digest-bound、site-local backend directives 连接

与 POC v2 的对比：

- v2 只能讲“一个 lowering choice 可行”
- v3 能讲“一个通用、可扩展、可跨架构移植的 backend policy substrate 可行”

安全性分析：

- 论文必须明确：v3 不开放任意 rewrite，不开放任意机器码，不开放任意 verifier override
- novelty 来自 mechanism/policy 分离，而不是“rule 语言更强”

实现工作量：

- 为论文准备的 applied/rejected telemetry、policy A/B log：`100-180 LOC`
- 这部分工作量很小，但对证明“同一合法 site 在不同 workload 下选择不同 alt”至关重要

### 10.1 为什么不是只做 kernel peepholes

这个问题必须直接回答，而且答案必须与 `paper-comparison.md` 和 `kernel-jit-optimization-plan.md` 一致。

首先，v3 不否认 fixed kernel heuristics 的价值。相反，论文应当把它们当成必须比较的 baseline：如果某个 lowering 在所有 CPU / workload / program 上都稳定更优，那么最好的工程结论就是直接 upstream。callee-saved adaptive save 已经证明了这一点，它验证了 characterization 的 backend diagnosis，但并不天然支持 userspace policy story。

其次，v3 只为另一类 case 建立接口：**legality 稳定、profitability 依赖部署环境**。这正是 userspace backend policy plane 存在的理由：

1. userspace policy 可以比 kernel heuristic 更快更新
2. userspace 能做 program-level 组合和 code-size budget，而不是逐 site 的局部贪心
3. userspace 能利用 workload profile，处理 `cmov`/branch predictability 这类运行时敏感决策
4. userspace 能做 fleet A/B rollout，而不是一次性把 heuristic 强推给所有机器
5. userspace owner 本来就承担 BPF service 的性能与回归责任

因此，v3 论文的 claim 必须收敛为：

- kernel heuristic 是 baseline，而且对 universally-good case 仍应优先 upstream
- userspace-guided interface 的**主证据**当前由 `SELECT` 承担；`WIDE_MEM` 负责证明最大 gap 的正确层次修复，但不单独证明 why-userspace
- `ADDR_MODE` / `ROTATE` 只作为 extensibility 证明，不应被包装成与 `SELECT` 同强度的 policy-sensitive evidence
- userspace-guided interface 只服务于 fixed heuristic 无法在所有部署环境下同时最优的 lowering site
- 论文的贡献不是初始 4 个 family，而是承载这些 family 的 extensible infrastructure

### 10.2 证据层级与诚实 claim

为了让 MVP claim 与现有证据严格对齐，v3 论文应显式采用下面的层级：

1. **`SELECT` = policy-sensitive anchor**  
   这是 why-userspace thesis 的主证据；如果 fixed kernel `cmov` policy 在评测里已经与 userspace policy 等价，那么 userspace story 会直接变弱。
2. **`WIDE_MEM` = largest backend gap, JIT-only recovery**  
   它主要回答“最大 gap 是否能在不做 verifier rewrite 的前提下进入同一 framework”；即使最终 fixed kernel wide-load heuristic 已足够好，它也仍然证明了 JIT-only substrate 的边界是对的。
3. **`ADDR_MODE` / `ROTATE` = extensibility proof**  
   它们证明 framework 不是单个 `cmov` 特例，但不应被写成“第二个、第三个强 policy-sensitive case”。

因此，最稳妥的 MVP 论文表述不是“4 个 equally policy-sensitive families”，而是：

> 一个 fail-closed、userspace-guided JIT backend substrate，当前由一个强 policy-sensitive anchor（`SELECT`）、一个最大 backend-gap recovery family（`WIDE_MEM`）、以及两个 extensibility families（`ADDR_MODE` / `ROTATE`）共同支撑。

### 10.3 诚实的贡献边界

v3 首版不再声称“统一覆盖 JIT lowering + verifier rewrite”。这不是退步，而是把系统边界收回到正确层次：

- v3：JIT backend policy substrate
- future：如果真的要做 `branch_reorder` 这类结构性变换，应作为单独 verifier substrate 继续研究

这条收缩后的 story 反而更稳，因为它与 POC v2、当前 x86 JIT、以及 `xlated_prog_len` 不变量完全一致。
