# V5 Architectural Refactor — User Requirements

## 核心原则

**所有 verifier-derived / IR-derived 分析必须在 lift / BBProgram 构造阶段一次性算好,cache 在 BBProgram 数据结构里。Pass 不允许跑数据流或维护状态机,只做 O(1) cached lookup。**

LLVM 类比:`AnalysisManager::getAnalysis<X>()` 返回缓存的 LivenessInfo / DominanceInfo / ScalarEvolution。我们 BBProgram 必须做到同样的事。

## 禁止

1. **Pass 内不允许**:
   - `compute_liveness()` 之类的 lazy 计算
   - `[RegValue; 11]` 手写状态机
   - `simulate_block` / `apply_transfer` / `solve_block_entry_states` 手写数据流
   - 32-insn lookback 自己找 packet pointer / frame pointer
   - 任何 `RegConstFact` / `RegValue::PacketData` 自己的 reg-tracking 枚举

2. **创建独立文件/文件夹**:已经删过两次(map_inline/、bulk_memory/),不允许再犯
3. **删功能**:任何减小 apply 数的优化都不允许
4. **Revert/restore commits**:错了 fix forward,不来回 bounce

## 必须

1. **每次改完立刻 build + test + clippy + fmt 4 件套全绿**
2. **碰到 verifier oracle 没覆盖的 site,扩展 BBProgram API 加 method,而不是在 pass 里写状态机**
3. **不停下来,直到 production LOC 减少 ≥ -1000 from session start (17527 → ≤ 16527)**

## 当前进度

- Session 起点: 17527 LOC
- V4c-fix codex 完成后预期: ~16700~16800
- V5 完成后目标: 16000~16300(再 -500~-800)

## V5 步骤

| Phase | 内容 | LOC 目标 |
|---|---|---:|
| V5b | BBProgram 加 cached liveness/use-def/dom 字段,lift 一次性算 | ~0 LOC delta(为下面解锁)|
| V5c | lift 加 reg-value/reg-kind/packet-pointer 分析,cache 进 BBProgram | ~0 LOC delta |
| V5d | try_replace_range / replace_terminator 等加 invalidation | +~30 |
| V5e-V5k | 7 个 pass 删 hand-rolled state machine | **-700~800** |
| V5l | testbin 542 progs + corpus 7-app smoke 验证 | 0 |

## 当前需 oracle 扩展的能力

| Pass | 目前自己算的 | 需要的 oracle 查询 |
|---|---|---|
| const_prop | RegConstFact + dataflow | `reg_known_constant(site, reg) -> Option<i64>` ✓ 已有 |
| bulk_memory | scalar tracking + stack pointer | `reg_known_constant` ✓ + `reg_kind == FramePointer` ✓ |
| bounds_check_merge | packet pointer tracking + root_id | `reg_kind == PacketPointer/PacketEnd` ✓,**root_id 关联**需扩展 |
| wide_mem | is_likely_packet_ptr | `reg_kind == PacketPointer` ✓ |
| skb_load_bytes | Ctx/FpPlusConst 跟踪 | `reg_kind == Context` ✓ + `reg_known_stack_bytes` ✓ |
| map_inline | r0 alias 跟踪、stack pointer resolve | use-def chain ✓ + `reg_kind` ✓ |
| endian | use-def(已做 V5k) | ✓ 已 done |

## 不需要

- 不要先验证 verifier oracle 覆盖率(用户明确说过)
- 直接相信 oracle,删 state machine,跑测试,如果失败再 fix forward
