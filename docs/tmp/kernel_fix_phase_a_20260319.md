# Kernel Fix Phase A

日期：2026-03-19

范围：

- Bug 1 + 7：hidden subprog 的 `func_cnt` / `real_func_cnt` 混用
- Bug 2：非 x86 暴露半实现 `BPF_PROG_JIT_RECOMPILE`

约束：

- 仅修改 `vendor/linux-framework/` 内核代码
- 未修改用户态代码
- 未 commit / push

## 结论

本轮已完成两个内核 bug 的修复：

1. `bpf_jit_recompile_ksym_prog()` 改为按 `real_func_cnt` 覆盖 hidden subprog，避免 recompile 成功后释放旧 JIT image 但遗漏对应 kallsyms replace。
2. `bpf_jit_rule_within_single_subprog()` 的边界判断改为使用 `real_func_cnt`，避免跨 visible/hidden subprog 的 rule 被误判为单 subprog 内规则。
3. `bpf_prog_jit_recompile()` 开头增加统一能力检查 `bpf_jit_supports_recompile()`；非实现架构统一返回 `-EOPNOTSUPP`。

## 代码修改

### 1. Hidden subprog 的 ksym / 生命周期修复

修改：

- [vendor/linux-framework/kernel/bpf/jit_directives.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L450)

要点：

- `bpf_jit_recompile_ksym_prog()` 现在先取 `real_func_cnt`。
- 多 subprog 程序中，`idx == 0` 仍映射到主 prog 的 ksym。
- `idx >= 1 && idx < real_func_cnt` 时，无论 visible 还是 hidden subprog，都映射到 `main_aux->func[idx]`。

效果：

- 所有会随 `image_cnt == real_func_cnt` 一起进入 recompile/commit/free 流程的 subprog，都会先进入 shadow ksym add，再在 commit 后走 `bpf_prog_kallsyms_replace()`。
- 这样旧 image 在 `bpf_jit_binary_pack_free()` 之前，不会再遗留 stale `bpf_ksym`。

### 2. Hidden subprog 边界校验修复

修改：

- [vendor/linux-framework/kernel/bpf/jit_directives.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L2808)

要点：

- `bpf_jit_rule_within_single_subprog()` 改为使用 `bpf_jit_recompile_real_func_cnt(main_aux)`。
- subprog 枚举和 `i + 1` 的边界都从 `func_cnt` 切到 `real_func_cnt`。

效果：

- hidden subprog 的边界现在参与 rule 范围判定。
- 跨 visible/hidden 边界的 rule 不会再被误标为 `within single subprog`。

### 3. Recompile 能力统一 gate

修改：

- [vendor/linux-framework/kernel/bpf/jit_directives.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L3536)
- [vendor/linux-framework/include/linux/filter.h](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/filter.h#L1171)
- [vendor/linux-framework/kernel/bpf/core.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/core.c#L3232)
- [vendor/linux-framework/arch/x86/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c#L6309)

要点：

- 新增统一 helper：`bpf_jit_supports_recompile()`
- 默认弱符号返回 `false`
- x86-64 backend 返回 `true`
- `bpf_prog_jit_recompile()` 在 flags 校验后立即调用该 helper

效果：

- 非实现架构不会再进入 staged recompile 状态机
- syscall 入口统一返回 `-EOPNOTSUPP`
- 保留 `BPF_JIT_ARCH_ARM64` UAPI 常量，但不会再误导到半实现内核路径

## 验证

### 1. 内核构建

命令：

```bash
source /home/yunwei37/workspace/.venv/bin/activate
cd vendor/linux-framework
make -j$(nproc) bzImage
```

结果：

- PASS
- 产物：`vendor/linux-framework/arch/x86/boot/bzImage`
- 最终消息：`Kernel: arch/x86/boot/bzImage is ready  (#51)`

### 2. `make vm-selftest`

命令：

```bash
source /home/yunwei37/workspace/.venv/bin/activate
cd /home/yunwei37/workspace/bpf-benchmark
make vm-selftest
```

结果：

- 19/20 PASS，1 个已知失败
- 失败项：`Wide Site-Only JIT Diff`

失败摘要：

```text
FAIL Wide Site-Only JIT Diff: non-site bytes changed outside site image 149->137 pre[0x33,0x45) post[0x33,0x39) [0x91]=3b -> [0x85]=6f [0x92]=20 -> [0x86]=1f
```

分析：

- 这不是本轮修复引入的新回归。
- 计划文档已记录该用例为已知预期失败：site 优化触发 full-image recompile 后，helper 相对位移等 relocation-sensitive 字节会一起变化。
- 参考：[docs/kernel-jit-optimization-plan.md](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L630)。
- 同样的验证结论也已记录在 [docs/tmp/2026-03-12/post-cleanup-validation.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/2026-03-12/post-cleanup-validation.md)。

结论：

- `vm-selftest` 当前状态仍是项目已知的 `19/20 pass`，本轮两个 bug 修复没有新增 selftest 回归。

### 3. `make vm-micro-smoke`

命令：

```bash
source /home/yunwei37/workspace/.venv/bin/activate
cd /home/yunwei37/workspace/bpf-benchmark
make vm-micro-smoke
```

结果：

- PASS

关键输出：

```text
[bench] simple
  kernel     compile median 6.631 ms | exec median 10 ns | result 12345678
  kernel-recompile compile median 3.811 ms | exec median 4 ns | result 12345678
[bench] load_byte_recompose
  kernel     compile median 4.157 ms | exec median 261 ns | result 1253018829653002637
  kernel-recompile compile median 4.048 ms | exec median 216 ns | result 1253018829653002637
```

说明：

- stock / recompile 两条路径都成功执行
- `load_byte_recompose` 在 recompile 后结果保持一致

## 变更清单

- [vendor/linux-framework/kernel/bpf/jit_directives.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c)
- [vendor/linux-framework/include/linux/filter.h](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/filter.h)
- [vendor/linux-framework/kernel/bpf/core.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/core.c)
- [vendor/linux-framework/arch/x86/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c)

## 最终状态

- Bug 1：已修复
- Bug 7：已修复
- Bug 2：已修复
- 内核构建：通过
- `vm-micro-smoke`：通过
- `vm-selftest`：保持项目既有状态 `19/20 pass`，唯一失败项为已知 `site-only diff` 约束，不属于本轮修复回归
