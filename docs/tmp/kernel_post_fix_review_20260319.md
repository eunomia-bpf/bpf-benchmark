# Kernel Post-Fix Review

日期：2026-03-19

审查范围：

- Phase A: `func_cnt`/`real_func_cnt` 修复 + 架构 gate
- Phase B: snapshot 后移 + `do_jit()` 短路 + helper 去重
- Phase C1: `COND_SELECT` 2-insn guarded-update validator
- Phase C2: validator/emitter params 统一

审查输入：

- `cd vendor/linux-framework && git diff HEAD`
- 相关实现：
  - [kernel/bpf/jit_directives.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c)
  - [arch/x86/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c)
  - [include/linux/bpf.h](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/bpf.h)
  - [include/linux/bpf_jit_directives.h](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/bpf_jit_directives.h)
  - [include/linux/filter.h](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/filter.h)
  - [kernel/bpf/core.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/core.c)

附加验证：

- `git -C vendor/linux-framework diff --check`: PASS
- `make -C vendor/linux-framework -j$(nproc) bzImage`: PASS
- `make vm-micro-smoke`: PASS
  - `simple`: `kernel` / `kernel-recompile` 结果一致，均为 `12345678`
  - `load_byte_recompose`: `kernel` / `kernel-recompile` 结果一致，均为 `1253018829653002637`

## 结论

本次 review 未发现新的 blocking correctness 问题，也未发现新引入的 use-after-free、null deref 或内存泄漏。

就当前 diff 而言，四个 phase 的核心修复方向是成立的：

- Phase A 的 hidden-subprog 计数修复和 recompile capability gate 是正确的。
- Phase B 的 snapshot 后移没有引入 policy / rollback 泄漏；`do_jit()` 短路不会改变 JIT convergence。
- Phase C1 的 2-insn guarded-update validator 语义与 x86 emitter 对齐。
- Phase C2 的 validator-derived params 流已经闭合；`ZERO_EXT_ELIDE` / `BRANCH_FLIP` 不再回看 `bpf_prog->insnsi` 的旧入口参数。

## 分项审查

### 1. Correctness

Phase A:

- hidden-subprog ksym 替换路径现在按 `real_func_cnt` 覆盖，避免遗漏 hidden subprog 的 kallsyms replace，见 [jit_directives.c:428](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L428)。
- `bpf_jit_rule_within_single_subprog()` 改用 `real_func_cnt` 做边界判定，hidden subprog 边界现在会参与 rule-range 校验，见 [jit_directives.c:3147](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L3147)。
- 统一 capability gate 通过弱符号默认 `false`、x86 显式 `true` 完成收口，见 [filter.h:1171](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/filter.h#L1171)、[core.c:3232](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/core.c#L3232)、[bpf_jit_comp.c:6312](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c#L6312)、[jit_directives.c:3878](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L3878)。

Phase B:

- `bpf_prog_jit_recompile()` 现在先做 blinded reject / policy parse / `active_cnt` reject，再做 snapshot；直到 snapshot 成功之后才 swap `main_aux->jit_policy`，因此没有“parse 成功但 snapshot 失败后把新 policy 留在 live prog 上”的路径，见 [jit_directives.c:3937](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L3937) 和 [jit_directives.c:3956](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L3956)。
- 公共 helper 去重没有改变语义；`bpf_prog_main_aux()` 只是变成 null-safe，stage reset 逻辑仍是纯字段清零，见 [bpf.h:1842](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/bpf.h#L1842)。

Phase C1:

- `site_len==2` guarded-update 现在按真实 BPF 语义建模：条件为真时保持 `dst` 原值，条件为假时执行 update；这个语义与 x86 `emit_bpf_cmov_guarded_update()` 一致，见 [jit_directives.c:898](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L898) 和 [bpf_jit_comp.c:1488](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c#L1488)。
- legacy `TRUE_VAL/FALSE_VAL` 交换绑定只对 `site_len==2` 放宽，且最终会归一化写回 `rule->params`，不会把历史兼容状态泄漏给 emitter，见 [jit_directives.c:1021](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L1021)。

Phase C2:

- `ZERO_EXT_ELIDE` validator 先从 site 提取 `dst_reg + alu32_insn`，再写入内部 pointer param；x86 emitter 只消费已验证过的 `ALU32_PTR` 和 `DST_REG`，见 [jit_directives.c:2069](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L2069) 和 [bpf_jit_comp.c:2712](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c#L2712)。
- `BRANCH_FLIP` validator 先解析出 `cond/body_a/body_b/join/site_ptr`，再统一写回；x86 emitter 只读 `rule->params`，不再混合依赖 `site_start/site_len/bpf_prog->insnsi`，见 [jit_directives.c:2263](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L2263) 和 [bpf_jit_comp.c:3212](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c#L3212)。

### 2. Use-After-Free / Null Deref / Memory Leak

未发现新引入的问题。

检查点：

- snapshot 后移后，新 `policy` 在 snapshot 成功前都只保存在局部变量 `policy`，所有早退路径都会在 `out_put` 统一 `bpf_jit_free_policy(policy)`，没有泄漏，见 [jit_directives.c:3856](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L3856)。
- `rollback` 仍通过 `bpf_jit_recompile_snapshot_free()` 统一回收；snapshot 部分成功时也会先回收已分配项再返回 `-ENOMEM`，见 [jit_directives.c:272](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L272)。
- 新增的内部 params (`ALU32_PTR` / `SITE_PTR`) 指向的是 prog instruction storage，而不是 policy blob 内存，因此不会随着 policy blob 释放变成悬垂指针，定义见 [bpf_jit_directives.h:54](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/bpf_jit_directives.h#L54)。
- `do_jit()` 的 `main_aux` 读取来自有效 `bpf_prog`，没有新增额外的 NULL-use 路径；此次变更也没有新增任何需要手工释放的新堆对象，见 [bpf_jit_comp.c:3727](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c#L3727)。

### 3. Validator Params 与 Emitter 消费是否对齐

结论：对齐。

- `COND_SELECT`：
  - validator 归一化出 `dst/cond/true/false/width`
  - x86 emitter 仍按 site lower，但语义和 validator 现在一致，特别是 `site_len==2`
- `ZERO_EXT_ELIDE`：
  - validator 填 `DST_REG + ALU32_PTR`
  - emitter 只检查并消费这两项
- `BRANCH_FLIP`：
  - validator 填 `COND_OP/BODY_A_START/BODY_A_LEN/BODY_B_START/BODY_B_LEN/JOIN_TARGET/SITE_PTR`
  - emitter 真实消费的是 `COND_OP/BODY_A_LEN/BODY_B_LEN/SITE_PTR`
  - 未消费的 `*_START/JOIN_TARGET` 主要用于用户态绑定匹配与 validator exact-shape 自证，不构成错配
- 其余 `WIDE_MEM/ROTATE/ADDR_CALC/BITFIELD_EXTRACT/ENDIAN_FUSION` 现在都走 “parse site -> match public params -> normalized write-back” 统一模式，没有看到参数槽位错位或类型错配。

### 4. 2-insn Guarded-Update Validator Edge Cases

结论：处理正确。

已覆盖的关键 edge case：

- `jcc->off != 1`：拒绝
- `update` 不是 simple mov：拒绝
- `JMP`/`JMP32` 与 mov 宽度不一致：拒绝
- `src` 为寄存器或立即数：都能正确归一化
- `mov dst, dst` / 自赋值 noop：接受，且 emitter 会在保留比较语义后省掉无效 cmov
- legacy `TRUE_VAL/FALSE_VAL` 交换绑定：仅 `site_len==2` 接受，写回后统一成真实语义
- interior edge：仍由公共 `bpf_jit_has_interior_edge()` 在 canonical-site 校验后拦住，未被本轮改动绕过

### 5. Snapshot 后移是否可能导致 Policy 泄漏

结论：没有看到泄漏路径。

原因：

- 新 policy 在 [jit_directives.c:3937](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L3937) 处解析，但直到 [jit_directives.c:3971](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L3971) 之后才真正挂到 `main_aux->jit_policy`。
- snapshot 若失败，会直接走 `out_put`；此时 live prog 上还是旧 policy，而局部 `policy` 会被释放。
- `policy->active_cnt == 0` 的 cheap reject 也在 snapshot 之前完成，并在本地释放 `policy`，不会污染 live state。

### 6. `do_jit()` 短路是否影响 JIT Convergence

结论：不会。

原因：

- 短路条件是 `policy == NULL` 或 `policy->active_cnt == 0`，见 [bpf_jit_comp.c:3732](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c#L3732)。
- 在这些情况下，旧逻辑逐条调用 `bpf_jit_apply_prog_rule()` 最终也只会得到 `0`，不会改写 `addrs[]`、不会改变 emitted bytes，也不会影响 pass-to-pass 长度收敛。
- 一旦有 active rule，仍然完整走旧的 dispatch 路径；因此 convergence 行为没有被稀释，只是把确定无规则可应用的 case 从 hot loop 里提前剪掉。

## 建议

- 建议新增一个 multi-subprog regression，覆盖 `BRANCH_FLIP` 和 `ZERO_EXT_ELIDE` 在 subprog 上的 recompile 路径。当前我没有看到 correctness break，但内部 pointer params 现在依赖 validator 从主程序指令数组回填，最好用测试把这个假设锁死。
- 建议补一个 `COND_SELECT site_len==2` 的专门自测，覆盖：
  - legacy swapped binding
  - `mov dst, dst` noop update
  - `JMP32 + ALU32` 宽度匹配
- 建议保留一个 cheap-reject 回归测试，验证 blinded prog / `active_cnt==0` policy 不会先做 snapshot。

## Review 评分

- 评分：`9.2 / 10`

理由：

- 修复方向正确，数据流比之前更干净，Phase B/C2 对状态和参数来源的收口是加分项。
- 静态审查未见新的 correctness / memory-safety 问题。
- 构建和 `vm-micro-smoke` 都通过。
- 扣分点主要是测试覆盖还可以更有针对性，尤其是 multi-subprog + pointer-backed internal params 的回归场景。

## 最终判断

可以接受当前 Phase A/B/C1/C2 的未提交内核改动；本次 review 没有发现需要阻塞合入的新问题。

本次我没有重跑完整 `vm-selftest`，但静态审查结论与本次 `bzImage` / `vm-micro-smoke` 结果一致。
