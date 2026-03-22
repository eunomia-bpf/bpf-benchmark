# BpfReJIT 内核最终 Review

日期：2026-03-19

## 范围与输入

本次 review 以当前工作树为准，基于：

- `cd vendor/linux-framework && git diff master`
- 历史文档：
  - `docs/tmp/kernel_deep_review_20260319.md`
  - `docs/tmp/kernel_fix_phase_a_20260319.md`
  - `docs/tmp/kernel_fix_phase_b_20260319.md`
  - `docs/tmp/kernel_fix_phase_c1_20260319.md`
  - `docs/tmp/kernel_fix_phase_c2_20260319.md`
  - `docs/tmp/kernel_tracepoint_stock_cleanup_20260319.md`
  - `docs/tmp/kernel_dsl_removal_20260319.md`
  - `docs/tmp/kernel_post_fix_review_20260319.md`

当前相对 `master` 的内核侧改动共 13 个文件，核心评审对象仍然是：

- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/include/linux/bpf.h`
- `vendor/linux-framework/include/linux/filter.h`
- `vendor/linux-framework/kernel/bpf/core.c`
- `vendor/linux-framework/kernel/bpf/syscall.c`

附带关注的 ancillary diff：

- `vendor/linux-framework/kernel/bpf/Makefile`
- `vendor/linux-framework/kernel/bpf/helpers.c`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/tools/bpf/bpftool/prog.c`
- `vendor/linux-framework/tools/include/uapi/linux/bpf.h`

## 验证

执行过的验证：

- `git -C vendor/linux-framework diff --check master`: PASS
- `make -C vendor/linux-framework -j$(nproc) bzImage`: PASS
  - `Kernel: arch/x86/boot/bzImage is ready  (#57)`
- `make vm-selftest`: PASS
  - `PASS all 20 test(s)`
- `make vm-micro-smoke`: PASS
  - `simple`: `kernel` / `kernel-recompile` 结果一致，均为 `12345678`
  - `load_byte_recompose`: `kernel` / `kernel-recompile` 结果一致，均为 `1253018829653002637`

## 结论

当前代码相比最初 deep review 已明显收敛：

- hidden subprog 的 `real_func_cnt` / kallsyms 生命周期问题已修复。
- generic syscall 的 “非实现架构半暴露” 已通过统一 gate 收口到 `-EOPNOTSUPP`。
- `COND_SELECT` 2-insn guarded-update 已补齐 validator。
- 8 个 canonical form 的 validator/emitter 数据流已经闭合，x86 emitter 现在只消费 `rule->params`。
- DSL 已从 kernel UAPI 中移除，`include/uapi/linux/bpf.h` 的 policy on-wire 格式已经简化为最小 rule 结构。

但当前版本还没有完全收尾。我认为剩余问题里没有 P0，也没有新的常规路径内存安全 blocker；不过还有 2 个 P1 的 ABI/语义问题，以及 3 个 P2 的性能/可维护性问题。

如果标准是“继续内部实验和 benchmark”，当前版本可以接受；如果标准是“ABI/语义已经稳定、可以长期维护”，还不够。

## 分级问题

### P1-1: `policy_fd == 0` 作为 stock re-JIT 哨兵值的 ABI 歧义仍然存在

位置：

- `vendor/linux-framework/include/uapi/linux/bpf.h:2015-2022`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:2981-2983`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3064-3068`

说明：

- UAPI 仍定义 `policy_fd == 0` 表示 “stock re-JIT / clear policy”。
- `fd 0` 在 Linux 中是合法 fd；如果 policy memfd 恰好落在 `0`，内核会静默走错语义。
- 这不是实现细节，而是 ABI 设计歧义。

结论：

- 之前问题 3：`未修复`

建议：

- 改成 `-1` 哨兵并显式拒绝 `< -1`。
- 或改成单独 flag，例如 `BPF_F_RECOMPILE_CLEAR_POLICY`。

### P1-2: `BPF_F_RECOMPILE_ROLLBACK` 的 UAPI 注释和真实行为仍不一致

位置：

- `vendor/linux-framework/include/uapi/linux/bpf.h:1563-1566`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3056-3074`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:3081-3114`

说明：

- Phase B 已经把 snapshot 后移到 cheap reject / policy parse 之后，这部分修复是成立的。
- 但 flag 语义问题还在：
  - re-JIT 失败时，image restore 是无条件发生的，见 `bpf_jit_recompile_restore(&rollback)`。
  - `BPF_F_RECOMPILE_ROLLBACK` 实际只影响 old policy 是否恢复。
- 因此当前实现并不存在一个真正的 “不 rollback image” 模式。
- UAPI 注释写的是 “preserve the current JIT image and policy until recompile succeeds”，这和当前代码表达的真实 contract 不一致。

结论：

- 之前问题 4：`部分修复`
  - snapshot 成本问题：`已修复`
  - rollback flag 语义问题：`未修复`

建议：

- 二选一：
  - 要么把 UAPI 注释改成“policy rollback”语义。
  - 要么实现真正不依赖 live image 原地回滚的 no-rollback fast path。

### P2-1: `do_jit()` 的无规则短路优化不在当前 tip 中

位置：

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3332-3459`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3596-3626`

说明：

- 当前 `do_jit()` 主循环仍然对每条 BPF 指令无条件调用 `bpf_jit_apply_prog_rule()`。
- `bpf_jit_rule_lookup_prog()` 虽然会快速返回 `NULL`，但 rule lookup / dispatch 这层调用成本仍然存在。
- 这不影响生成的 JIT image 正确性，也不影响运行时 hot path。
- 但它意味着 Phase B 报告里提到的 “no policy / no active rule 时跳过 dispatch” 优化，在当前 tip 不存在。

结论：

- 之前问题 5：`未修复`

建议：

- 把 `has_active_rules` 短路重新放回 `do_jit()`，避免无 policy 场景下每条指令都做一次 rule lookup。

### P2-2: `recompile_count` 仍会统计到“未替换 live image”的 no-op custom recompile

位置：

- `vendor/linux-framework/kernel/bpf/jit_directives.c:3122-3129`
- `vendor/linux-framework/include/linux/bpf.h:1734`
- `vendor/linux-framework/kernel/bpf/syscall.c:5051-5053`

说明：

- 当 custom policy 解析成功，但最终 `jit_recompile_num_applied == 0` 时，代码会：
  - `bpf_jit_recompile_restore(&rollback)`
  - 记录 “no rules applied; kept the pre-recompile image”
  - 然后仍然 `recompile_count++`
- 这使 `recompile_count` 更接近“成功返回的 recompile 请求数”，而不是“live image 实际切换次数”。

结论：

- 之前问题 9：`未修复`

建议：

- 如果字段语义是 image switch 次数，应只在真正 commit 并保留新 image 时递增。
- 如果字段语义只是 successful attempts，需要同步改字段注释和用户态预期。

### P2-3: `include/linux/bpf_jit_directives.h` 仍有 DSL 清理后的残留字段/类型

位置：

- `vendor/linux-framework/include/linux/bpf_jit_directives.h:24-35`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h:48-52`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h:109-139`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:757-780`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:2190-2205`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3071-3095`

说明：

- `enum bpf_jit_var_type` / `struct bpf_jit_var` 当前全仓库无引用，属于 DSL 时代遗留。
- `struct bpf_jit_canonical_params` 的 `present_mask` / `param_count` 现在只写不读。
- `BRANCH_FLIP` 的 `BODY_A_START` / `BODY_B_START` / `JOIN_TARGET` 现在只由 validator 回填，x86 emitter 实际只消费 `COND_OP`、`BODY_A_LEN`、`BODY_B_LEN`、`SITE_PTR`。

结论：

- 之前问题 8：`功能性修复完成，但清理未做干净`

建议：

- 这不是 correctness 问题，但可以继续删掉不用的 DSL-era 类型/字段，降低头文件噪音。

## 逐文件结论

### 1. `kernel/bpf/jit_directives.c`

结论：

- policy 解析逻辑对当前简化格式是正确的。
  - `bpf_jit_parse_policy()` 现在只保留 header 校验和固定大小 rule 数组读取，见 `2529-2679`。
  - `bpf_jit_parse_policy_format_v2()` 正确校验了 rule 截断、site range、canonical form/native choice、subprog 边界、exact-shape validator，见 `2452-2520`。
- per-form validator 已完整覆盖 8 个 canonical form。
  - `bpf_jit_validate_canonical_site()` 的 switch 覆盖 `COND_SELECT/WIDE_MEM/ROTATE/ADDR_CALC/BITFIELD_EXTRACT/ZERO_EXT_ELIDE/ENDIAN_FUSION/BRANCH_FLIP` 全 8 项，见 `2278-2345`。
- snapshot / commit / restore / rollback 主状态机总体正确。
  - snapshot 后移到 parse/validate 之后是对的。
  - success path 的 staged image / shadow ksym / commit / RCU / replace 顺序也是对的。
- 常规成功/失败路径下，我没有看到新引入的内存泄漏、use-after-free、null deref。
- 仍可继续简化：
  - 顶部注释仍写着 “declarative patterns only”，已经过时。
  - internal params / header 里还有 DSL-era 残留。
- CPU feature gating 移到 validator 后是正确的。
  - `CMOV`：`941-945`
  - `BMI2`：`1610-1614`
  - `MOVBE`：`2056-2060`
  - emitter 侧保留 `BMI2` / `MOVBE` 冗余检查是安全的。

### 2. `arch/x86/net/bpf_jit_comp.c`

结论：

- emitter dispatch 是正确的。
  - `bpf_jit_try_emit_rule()` 的 switch 完整覆盖 8 个 canonical form，见 `3356-3442`。
- 8 个 form 的 emitter 当前都只消费 `params`。
  - `COND_SELECT/WIDE_MEM/ROTATE/ADDR_CALC/BITFIELD_EXTRACT/ENDIAN_FUSION` 直接消费 canonical params。
  - `ZERO_EXT_ELIDE` / `BRANCH_FLIP` 通过 validator 写入的 internal pointer params (`ALU32_PTR` / `SITE_PTR`) 消费，不再从 `bpf_prog->insnsi` 重新解析。
- 我没有看到残留的“旧 rule DSL / raw insn site_start/site_len 解析入口”还留在 emitter dispatch 路径里。
- `do_jit()` 短路优化当前不在代码中，这一点需要单独记为 P2。

### 3. `include/uapi/linux/bpf.h`

结论：

- 删除 DSL 后，主 UAPI 已基本干净。
  - 在 JIT policy block（`1463-1544`）里现在只剩 header、canonical/native enum、以及最小 `struct bpf_jit_rewrite_rule_v2`。
  - 没有残留 `pattern/constraint/binding` 结构或枚举。
- 还留着两个 UAPI 语义问题：
  - `policy_fd == 0` 哨兵歧义。
  - `BPF_F_RECOMPILE_ROLLBACK` 注释与实现不一致。
- 另外，`BPF_JIT_ARCH_ARM64` 仍然暴露在 UAPI 中，而当前后端实际只通过 `bpf_jit_supports_recompile()` 支持 x86。功能上已被 gate 住，但 ABI 表面仍然比真实实现更宽。

### 4. `include/linux/bpf_jit_directives.h`

结论：

- 大方向合理：canonical param enum 已从 UAPI 移到 internal header，符合 DSL removal 目标。
- `struct bpf_jit_rule` / `struct bpf_jit_policy` 结构本身是合理的。
- 仍有不再需要或暂时未使用的字段/类型：
  - `bpf_jit_var*`
  - `present_mask`
  - `param_count`
  - 部分 `BRANCH_FLIP` params

### 5. 其他文件

`include/linux/filter.h`

- 只新增 `bpf_jit_supports_recompile()` 声明，最小且必要。

`include/linux/bpf.h`

- recompile state 字段、shared helper、ksym metadata 扩展整体是必要的。
- 但内部 param/container 还有继续减法空间，见上面的 P2-3。

`kernel/bpf/core.c`

- `jit_recompile_mutex` 初始化/销毁、policy 生命周期、weak gate、kallsyms replace 支撑都属于必要改动。
- 这部分 diff 是合理的。

`kernel/bpf/syscall.c`

- 新 syscall case 和 `recompile_count` 导出是必要的。
- 这里没有看到多余逻辑。

`kernel/bpf/Makefile`

- `jit_directives.o` 接入是必要的，见 `9-10`。

`kernel/bpf/helpers.c`

- `bpf_throw()` 的 `READ_ONCE()` / NULL guard 是小型健壮性改动，和 BpfReJIT 不是强耦合，但本身没有问题。

`kernel/bpf/verifier.c`

- `orig_idx` 传播修复是小型 verifier 修正，也不是 BpfReJIT 核心路径。

`tools/bpf/bpftool/prog.c`

- `recompile_count` 打印是合理且最小的辅助改动。

## 对之前 9 个问题的逐项确认

| # | 历史问题 | 当前状态 | 备注 |
| --- | --- | --- | --- |
| 1 | hidden subprog 的 kallsyms/extable 生命周期错配 | 已修复 | `bpf_jit_recompile_ksym_prog()` 已按 `real_func_cnt` 覆盖，commit 后也会 replace hidden subprog kallsyms |
| 2 | generic syscall 暴露半实现 recompile | 已修复 | `bpf_jit_supports_recompile()` 统一 gate 已生效 |
| 3 | `policy_fd == 0` 哨兵歧义 | 未修复 | ABI 仍有歧义 |
| 4 | rollback 语义和 snapshot 成本问题 | 部分修复 | snapshot 后移已修；flag 语义仍不一致 |
| 5 | `do_jit()` 无 policy 时仍逐条 dispatch | 未修复 | 当前 tip 没有 Phase B 短路 |
| 6 | `COND_SELECT` 2-insn guarded-update 死代码 | 已修复 | validator 已支持 `site_len == 2` |
| 7 | hidden subprog 边界校验仍用 `func_cnt` | 已修复 | 已切到 `real_func_cnt` |
| 8 | helper / stage-reset / parser 重复漂移 | 基本修复，仍有残留清理 | shared helper 和 params-only emitter 已收口；头文件还有 vestigial 类型/字段 |
| 9 | `recompile_count` 会统计到 no-op recompile | 未修复 | 当前仍 overcount |

## 总体评分

- 评分：`8.4 / 10`

理由：

- correctness 主体已经闭环，hidden subprog / ksym / validator-emitter 数据流这几类高风险点都修掉了。
- 当前代码可以稳定构建，selftest 和 micro smoke 都通过。
- 扣分点主要在 ABI/语义收尾：
  - `policy_fd == 0`
  - `BPF_F_RECOMPILE_ROLLBACK`
  - `recompile_count`
- 另外还有一个当前 tip 缺失的 compile-time 优化，以及一些 DSL removal 后的头文件残留。

## 最终判断

当前版本可以接受为“当前 BpfReJIT 内核代码的可运行实验版 / benchmark 版”。

如果目标是把接口和语义打磨到长期稳定、可维护的状态，我建议至少先收掉这两项 P1：

1. `policy_fd == 0` ABI 歧义
2. `BPF_F_RECOMPILE_ROLLBACK` 语义收敛

之后再补：

1. `do_jit()` 的无规则短路
2. `recompile_count` 语义修正
3. `include/linux/bpf_jit_directives.h` 的残留清理
