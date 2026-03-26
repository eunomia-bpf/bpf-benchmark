# LivePatchPass 设计文档（2026-03-26）

## 1. 目标与范围

本文定义 BpfReJIT daemon 中 `LivePatchPass` 的实现级设计。该 pass 的目标不是修复 verifier，而是在 **REJIT 前** 对已经加载的 BPF 程序做字节码级硬化，消除已知 verifier CVE 可利用 gadget，并要求补丁后的程序重新通过 verifier。

本设计只覆盖：

- daemon 侧 CVE 签名库与匹配逻辑
- 4 类热补丁模板的字节码插入方案
- proof shift 规则
- REJIT 重新验收与回滚
- Pass 排序与测试计划

本设计不覆盖：

- verifier 本身修复
- 任意 CVE 的通用程序综合
- kernel-side image swap productionization
- 依赖复杂跨函数全程序证明的补丁

## 2. 与现有 pass 框架的集成

`LivePatchPass` 应按现有 `daemon/src/pass.rs` 的 `BpfPass` 模型实现，形态上与 [`skb_load_bytes.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/skb_load_bytes.rs) 和 [`bounds_check_merge.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/bounds_check_merge.rs) 一致：先扫描候选点，再批量改写，再统一做 branch fixup 与 annotation remap。

建议属性：

- `name() = "live_patch"`
- `category() = PassCategory::Security`
- `required_analyses() = ["cfg", "branch_targets", "liveness"]`

建议新增的 daemon 侧组件：

- `daemon/src/passes/live_patch.rs`
  负责扫描、匹配、模板展开、重写与 skip reason。
- `daemon/src/live_patch_db.rs`
  负责 YAML 签名库加载、kernel range 判定、CVE entry 校验。
- `daemon/config/live_patch_signatures.yaml`
  CVE 签名数据库。

v1 不要求新增复杂全局分析。匹配尽量基于当前已有的 `CFG`、`BranchTarget`、`Liveness` 和局部抽象解释完成。

## 3. CVE 签名数据库 Schema

### 3.1 顶层格式

```yaml
version: 1
entries:
  - cve_id: CVE-2024-56702
    affected_kernel_range:
      introduced: "6.10"
      fixed: "6.12.9"
      include_fixed: false
      distro_overrides: {}
    match_criteria:
      prog_type: ["raw_tracepoint", "tracing"]
      helper_ids: []
      pattern:
        kind: ptr_deref_without_null_guard
        source: raw_tp_arg
        attach_name: "trace_kfree_skb"
        ptr_arg_index: 1
        deref_offsets: [0, 8, 16]
        max_local_window: 12
        requires_single_bb: true
    patch_template:
      kind: null_guard
      fallback:
        action: return_imm
        imm: 0
      reuse_existing_fail_block: true
    proof_shift:
      buggy_rule: trusted_raw_tp_arg_is_nonnull
      inserted_invariant: explicit_ptr_nonnull_branch_dominates_deref
      verifier_simple_form: direct_conditional_guard_then_safe_exit

  - cve_id: CVE-2024-58098
    affected_kernel_range:
      introduced: "6.9"
      fixed: "6.13.4"
      include_fixed: false
      distro_overrides: {}
    match_criteria:
      prog_type: ["xdp", "sched_cls", "sched_act", "sk_skb", "lwt_in", "lwt_out", "lwt_xmit"]
      helper_ids: []
      pattern:
        kind: stale_packet_ptr_after_changes_pkt_data
        call_kind: global_subprog
        ctx_reg_policy: preserve_if_needed
        stale_use_within: 16
        requires_single_bb: true
    patch_template:
      kind: pointer_refresh
      packet_layout:
        data_off_by_prog_type:
          xdp: 0
          sched_cls: 76
          sched_act: 76
        data_end_off_by_prog_type:
          xdp: 4
          sched_cls: 80
          sched_act: 80
      fallback:
        action: reuse_existing_slow_path_or_return_imm
        imm: 0
    proof_shift:
      buggy_rule: old_packet_root_remains_valid_after_changes_pkt_data
      inserted_invariant: reload_packet_root_and_rebuild_guard_after_call
      verifier_simple_form: fresh_ctx_load_plus_dominating_bounds_check
```

### 3.2 字段定义

- `cve_id`
  唯一键。
- `affected_kernel_range`
  用于 kernel gate。v1 至少支持 `introduced`、`fixed`、`include_fixed`、`distro_overrides`。
- `match_criteria.prog_type`
  程序类型白名单；不匹配直接跳过。
- `match_criteria.helper_ids`
  需要出现的 helper ID 列表；为空表示不依赖 helper 预过滤。
- `match_criteria.pattern`
  模式匹配 DSL。v1 只支持少数固定 `kind`，不做通用 AST。
- `patch_template`
  模板种类和参数。
- `proof_shift`
  不是注释字段，而是审计字段。它明确说明“原漏洞依赖什么错误证明、补丁后改成什么局部不变量、为什么重新验收不再依赖同一个 buggy proof rule”。

### 3.3 v1 支持的 `pattern.kind`

- `ptr_deref_without_null_guard`
- `helper_arg_requires_sanitization`
- `stale_packet_ptr_after_changes_pkt_data`
- `dangerous_tail_call_or_helper_edge`

### 3.4 v1 支持的 `patch_template.kind`

- `null_guard`
- `arg_sanitize`
- `pointer_refresh`
- `edge_quarantine`

## 4. 匹配算法

## 4.1 总体流程

`LivePatchPass::run()` 的匹配应分 5 段：

1. `kernel gate`
   依据运行内核版本和 `affected_kernel_range` 过滤不相关 CVE。
2. `program metadata prefilter`
   用 `prog_type`、attach 名称、helper 集合做第一轮缩小。
3. `local symbolic scan`
   单次线性扫描指令流，维护局部寄存器事实。
4. `pattern recognizer`
   每种 `pattern.kind` 有独立识别器，输出 `PatchCandidate`。
5. `patchability validation`
   检查是否有 scratch reg、是否可安全 early exit、是否已存在等价 guard、是否会和 branch target 冲突。

输出结构建议：

```text
PatchCandidate {
  cve_id,
  template_kind,
  site_pc,
  end_pc,
  matched_regs,
  local_facts,
  fallback_kind,
}
```

## 4.2 局部寄存器事实

v1 不做完整 verifier 仿真，只追踪补丁所需的最小事实：

- `Unknown`
- `Const(i64)`
- `Ctx`
- `StackPtr(fp_off)`
- `PacketData { root_id, const_off }`
- `PacketEnd { root_id }`
- `MaybeNullPtr { tag }`
- `NonNullPtr { tag }`
- `ReadonlyMem { source }`
- `ReleasedRef`

规则：

- 在 branch target 入口保守清空状态，类似现有两个参考 pass。
- 遇到 helper call 后将 `r0-r5` 视为 clobbered，`r6-r9` 保留。
- 对 `ldimm64`、`mov`、`add imm`、`ctx->data/data_end` load 做有限传播。
- 遇到复杂 join、间接模式、未知 bpf2bpf side effect 时保守跳过。

## 4.3 各模板的识别条件

### A. Null guard

候选点是“可能为空指针的首次解引用”：

- 内存读/写的 base reg 来自 `raw_tp arg`、`socket->sk`、trusted ptr、或签名指定源；
- 从当前点向前回看 `max_local_window` 条指令；
- 若同一 basic block 或唯一前驱链上不存在显式 `if rP == 0` / `if rP != 0` guard，则命中；
- 如果已有等价 guard，则记录 skip reason `already_guarded`。

### B. Argument sanitization

候选点是“helper 调用参数可能触发漏洞 contract”：

- `call helper#H`，且 `H` 在 `helper_ids` 中；
- 参数寄存器指向 `ReadonlyMem`、`ReleasedRef` 或签名定义的危险对象；
- 调用窗口内不存在等价的预清零/redirect；
- 若 helper 语义要求可写 out buffer，则优先 `scratch-stack redirect`；否则 `zero/poison`。

### C. Pointer refresh

候选点是“可能使 packet root 失效的 call 后继续使用旧 packet ptr”：

- 匹配 `changes_pkt_data` 的 helper / global subprog / extension 边；
- call 后 `stale_use_within` 条指令内出现使用旧 `PacketData { root_id }` 的 packet 访问；
- 中间没有重新读取 `ctx->data/data_end` 并重建 guard；
- 如没有可用 ctx 保存寄存器且也无法在 call 前插入保存，跳过。

### D. Boundary isolation

候选点是“危险 helper / tail-call 边仍然存在”：

- helper ID 或 tail-call site 落在签名库黑名单；
- attach/prog class 与签名中的危险边一致；
- 若该边已被前置 `helper_firewall` 或已有等价 quarantine 替换，则 skip。

## 4.4 v1 匹配边界

v1 有意收窄：

- 只补“局部窗口可证明”的站点
- 默认只处理单 basic block 或唯一前驱链
- 默认跳过 outstanding ref/lock/dynptr 站点
- 默认跳过没有安全 fallback 的程序类型
- 默认跳过没有 scratch reg 的站点

这比“尽量多 patch”更重要。Live patch 的优先级是可靠地消除 exploit gadget，而不是追求覆盖率。

## 5. 补丁模板实现

## 5.1 公共约定

### 共享失败块

凡是需要 fail-closed 退出的模板，优先：

1. 复用程序里已经存在的慢路径/错误块；
2. 否则在程序尾部追加一个共享 `LP_SAFE_EXIT_<ret>` 块：

```text
LP_SAFE_EXIT_<ret>:
  r0 = <RET_IMM>
  exit
```

每个不同的 `<RET_IMM>` 最多追加一次。

### Scratch register 选择

优先从 `r6-r9` 中选一个在站点 live-out 之后不再需要的寄存器；选不出就跳过。v1 不抢占 live 的 callee-saved reg。

### 重写方法

实现形式应与参考 pass 一致：

- 扫描阶段只收集 site，不立即改写
- `rewrite_sites()` 统一展开
- 对宽指令和 `ja/jcc` 做统一 branch fixup
- 调用 `program.remap_annotations()` 与 `program.log_transform()`

## 5.2 模板 1：Null guard insertion

### 适用场景

- `CVE-2024-38566`
- `CVE-2024-56702`
- `CVE-2025-21852`

### 精确插入序列

假设待保护指针寄存器是 `rP`，共享失败块位于 `LP_SAFE_EXIT_0`：

```text
; 插在第一条 deref 前
if rP != 0 goto +1
ja +E

; 原始 deref 序列继续
...

LP_SAFE_EXIT_0:
  r0 = 0
  exit
```

如果签名指定返回值不是 `0`，则 `LP_SAFE_EXIT_<ret>` 中的 `r0 = <ret>` 改为对应立即数。

### 说明

- 这是最短、最稳定的 proof shift 形式。
- 若原程序已经有等价失败块，优先直接跳到原块，不新建 epilogue。
- 若站点位于必须执行资源释放之后才能退出的区域，v1 跳过，不做 early exit patch。

## 5.3 模板 2：Argument sanitization

该模板有 3 个子型，签名库必须显式指定。

### A. 直接清零标量参数

```text
; 原 call 前插入
rA = 0
call helper#H
```

适用于“漏洞依赖危险立即数/长度/flags 参数”的情况。

### B. Redirect 到零化 scratch stack

假设危险参数为 `rA`，需要一个 8-byte out buffer，使用 `r9` 和 `[r10-8]`：

```text
r9 = 0
*(u64 *)(r10 - 8) = r9
rA = r10
rA += -8
call helper#H
```

如果需要 16/32 byte 缓冲区，则重复零化 store，并使用更大的负偏移窗口，比如 `-16`、`-32`。

适用于：

- `CVE-2024-49861`
- `CVE-2024-50164`

其本质是把“helper 能写到错误对象”的前提，转换成“helper 最多写到临时零化 stack scratch”。

### C. release 后寄存器 poison

```text
call helper_or_kfunc_release
rP = 0
```

适用于 release/reference-state 类漏洞；Phase 1 只对签名明确要求的 CVE 开启。

## 5.4 模板 3：Pointer refresh

### 适用场景

- `CVE-2024-58098`
- `CVE-2024-58100`

### 精确插入序列

若 call 后 packet pointer 可能失效，且不存在现成 ctx 保存寄存器，则在 call 前先保存 `r1` 到 dead 的 callee-saved reg `r9`：

```text
; 原 call 前插入
r9 = r1
call helper_or_subprog

; call 后插入
r7 = *(u32 *)(r9 + DATA_OFF)
r8 = *(u32 *)(r9 + DATA_END_OFF)
r6 = r7
r6 += NEED_END
if r6 > r8 goto +E
rP = r7
rP += CONST_OFF
```

其中：

- `DATA_OFF` / `DATA_END_OFF` 由 `prog_type` 决定
- `NEED_END` 是后续访问需要的最大窗口终点
- `CONST_OFF` 是原 stale ptr 相对 packet root 的常量偏移
- `+E` 指向已有慢路径或共享 `LP_SAFE_EXIT_<ret>`

如果程序里已经有持久化的 ctx 寄存器，比如 `r6 = r1`，则复用该寄存器，不再额外插入 `r9 = r1`。

### 说明

- 该模板必须同时“刷新 root”与“重建 bounds guard”，只做前者不够。
- v1 只处理 `CONST_OFF` 可恢复的 packet ptr；动态 offset 情况跳过。

## 5.5 模板 4：Boundary isolation

### 适用场景

- `CVE-2024-50063`
- 危险 helper edge 隔离

### Phase 1 的精确替换序列

#### A. 直接禁用 tail-call 边

把原始：

```text
call bpf_tail_call
```

替换为：

```text
r0 = 0
```

理由：tail call 失败路径本来就会继续执行，`r0 = 0` 等价于“强制此边总是失败，不离开当前程序”。

#### B. 直接禁用危险 helper

把原始：

```text
call helper#H
```

替换为：

```text
r0 = <SAFE_ERR_OR_ZERO>
```

`<SAFE_ERR_OR_ZERO>` 由签名指定，默认不做全局常量假设。

### Phase 2 可选扩展

若未来要做 selective edge allowlist，可扩展成：

```text
if rIDX == ALLOWED goto +1
r0 = 0
ja +1
call bpf_tail_call
```

但这不是 v1 必需项。v1 只做整站点 quarantine。

## 6. Proof Shift 设计

## 6.1 原则

`proof_shift` 的核心不是“补丁后再跑一次 verifier”，而是：

> 把程序从依赖 buggy proof rule 的形状，改写成 verifier 最简单、最稳定、最局部的证明形状。

## 6.2 四类模板对应的 proof shift

| 模板 | 原漏洞依赖的错误证明 | 补丁后依赖的新不变量 |
|---|---|---|
| null guard | verifier 错把指针当 non-null | 显式 `if ptr == 0` 分支主导所有 deref |
| arg sanitize | verifier 错把参数目标当可写/可安全使用 | 参数被清零、导向 scratch stack、或 release 后寄存器被 poison |
| pointer refresh | verifier 错把旧 packet root 当仍有效 | call 后重新 load `data/data_end` 并重建 guard |
| edge quarantine | verifier 错放过危险 helper/tail-call edge | 边在字节码里直接消失，不再需要 verifier 证明兼容性 |

## 6.3 实施约束

每个 CVE entry 必须能回答 3 个问题：

1. 旧程序依赖了哪个 buggy proof rule？
2. 补丁后插入的局部不变量是什么？
3. 新程序为什么不会再次依赖同一类错误推理？

若 entry 无法清楚回答这三点，不应进入签名库。

## 7. Verifier 重新验收（REJIT）

补丁后的验收流程应完全复用当前 daemon 的 REJIT 路径：

1. 枚举 live 程序，读取 `orig_prog_insns`
2. 执行现有优化 pipeline
3. 最后执行 `LivePatchPass`
4. 重定位 map FD / 补齐 BTF FD
5. 调用 `BPF_PROG_REJIT(log_level=2)`
6. 捕获 verifier log

验收标准：

- `sites_applied > 0` 或明确 `no_change`
- verifier 接受新字节码
- 未出现 post-verify REJIT failure

若 verifier 拒绝：

- 复用现有 `commands.rs` 的 attribution + disable-pass-and-retry 机制
- 因为 `LivePatchPass` 放在最后，禁用它后会直接回退到“仅优化、不热补丁”的版本

v1 的 pass 级回滚粒度已经够用，但 `diagnostics` 应补充更细日志，例如：

```text
applied CVE-2024-56702 null_guard at pc=41
skipped CVE-2024-58098 at pc=88: no_dead_callee_saved_reg
```

这样即使 attribution 还是“按 pass 粗粒度”，排障也能定位到具体 CVE/site。

## 8. 回滚机制

## 8.1 验证失败回滚

这是现有机制，直接复用：

- verifier reject 时归因到 `live_patch`
- 将 `live_patch` 加入 `disabled_passes`
- 重新从原始 bytecode 跑 pipeline

## 8.2 功能性回滚

Live patch 还需要处理“verifier 接受但业务功能坏了”的情况。建议加一个用户态 ledger：

```text
LivePatchLedger {
  prog_id,
  prog_tag_before,
  prog_tag_after,
  orig_insn_digest,
  patched_insn_digest,
  applied_cves,
  applied_at,
  rollback_token
}
```

触发回滚的来源：

- operator 显式回滚
- 健康检查失败
- 统计指标突变
- 新版本签名库将该 CVE 标记为误报/停用

回滚动作：

1. 用 ledger 中记录的“原始程序镜像”重新发起一次 `BPF_PROG_REJIT`
2. 或者在 `disabled_passes += ["live_patch"]` 的模式下重跑

建议支持 3 个策略模式：

- `alert-only`
- `patch-if-safe`
- `patch-or-quarantine`

其中 `patch-or-quarantine` 只建议用于 emergency mitigation，不应做默认模式。

## 9. Pass 排序

`LivePatchPass` 必须放在 **最后**。

推荐顺序：

```text
所有优化 pass
-> helper_firewall（若启用）
-> speculation_barrier（若启用）
-> live_patch
```

原因：

- 优化 pass 会改变局部形状；live patch 必须匹配最终字节码
- `helper_firewall` 可能已经消掉危险 helper edge；live patch 不应先补再被其覆盖
- live patch 插入的是显式 guard/exit/redirect；后续再做 DCE、merge、select、rotate 等会破坏 proof shift 的可审计性
- 它最后执行时，REJIT 失败的回退最简单

在 [`passes/mod.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/mod.rs) 中，`live_patch` 应作为 registry 最后一项。

## 10. 测试计划

## 10.1 Host-side 单元测试

这些测试不需要接触 host kernel BPF runtime，可直接跑在 Rust 单测中：

- YAML schema 解析与字段校验
- kernel range gate
- pattern matcher 命中/误报
- scratch reg 选择
- 共享 `LP_SAFE_EXIT` 去重
- branch fixup 后 offset 正确
- 重复运行 pass 的幂等性

## 10.2 每类模板的合成程序测试

至少各做一组 synthetic vulnerable program：

1. `null_guard/raw_tp`
   maybe-null 参数被直接 dereference，期望插入 2 条 guard + 共享 exit stub。
2. `null_guard/socket_sk`
   trusted pointer 被直接解引用，期望同上。
3. `arg_sanitize/readonly_map`
   helper 输出原本指向危险对象，期望改写为 stack scratch redirect。
4. `pointer_refresh/stale_pkt_ptr`
   `changes_pkt_data` 调用后继续使用旧 `data` 派生指针，期望插入 ctx 保存、root reload、guard rebuild。
5. `edge_quarantine/tail_call`
   危险 `bpf_tail_call` 站点被替换为 `r0 = 0`。

## 10.3 Negative 测试

- 已有 guard，不应重复 patch
- 站点是 branch target，不应强插
- 无 dead scratch reg，应 skip
- 存在 outstanding ref/lock，应 skip
- fallback 未定义，应 skip
- 动态 offset packet ptr，应 skip

## 10.4 VM 集成测试

REJIT 验收必须在 VM 内进行，不得触碰 host kernel。建议新增 repo-owned 测试目录，通过 `make` 目标驱动：

- 对每个 synthetic 程序做 `rewrite -> REJIT -> verifier accepted`
- 对至少一个拒绝样例做 `rollback retry`
- 对 `alert-only` / `patch-if-safe` 模式做控制面测试

## 11. Phase 1 范围

建议 Phase 1 先做 5 个高可行 CVE：

| CVE | 模板 | 入选原因 |
|---|---|---|
| `CVE-2024-56702` | null guard | raw_tp 参数可空，模式稳定，fallback 明确，最适合做第一个模板 |
| `CVE-2024-38566` | null guard | 与 raw_tp 空指针不同，验证 trusted pointer 家族的泛化能力 |
| `CVE-2024-58098` | pointer refresh | 与现有 packet/bounds 研究天然兼容，价值高 |
| `CVE-2024-49861` | arg sanitize | 可直接用 scratch-stack redirect，proof shift 清晰 |
| `CVE-2024-50164` | arg sanitize | 与上一个共用大部分模板逻辑，投入产出比高 |

`CVE-2024-50063` 建议作为 Phase 1.5：

- 模板本身已在框架里预留为 `edge_quarantine`
- 但它更容易改变业务语义
- 更适合放在 `patch-or-quarantine` 或 emergency-only 模式下启用

## 12. 结论

`LivePatchPass` 的正确定位是“最后执行的安全重写 pass”。它依赖现有 BpfReJIT pass 框架、分析缓存、REJIT 与 verifier log 机制，但安全论证不建立在“再跑一次同一个 verifier 就万事大吉”上，而建立在 **proof shift**：把程序重写成显式 guard、参数净化、packet root 刷新、边隔离这四类 verifier-simple 形状。

Phase 1 不追求大而全，只做局部、可审计、可回滚、可在 VM 中稳定复验的 5 个高可行 CVE。这样实现风险最低，也最符合当前仓库的成熟度。
