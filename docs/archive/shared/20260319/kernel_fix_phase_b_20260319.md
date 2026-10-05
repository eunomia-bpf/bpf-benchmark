# Kernel Fix Phase B

日期：2026-03-19

范围：

- Problem 4a：`bpf_jit_recompile_snapshot()` 后移，避免非法 policy / cheap reject 先付出 O(total_insns) snapshot 成本
- Problem 5：`do_jit()` 在无 policy / 无 active rule 时绕过每条指令的 rule dispatch
- Problem 8a/b：去重 `main_aux` / stage-reset helper，统一到公共层

约束：

- 仅修改 `vendor/linux-framework/` 内核代码
- 未修改用户态代码
- 未 commit / push

## 结论

本轮已完成三项 Phase B 改动：

1. `bpf_prog_jit_recompile()` 现在先完成 cheap reject 和 policy parse/validate，再做 rollback snapshot。
2. x86 `do_jit()` 在进入主循环前缓存 `has_active_rules`；当 `policy == NULL` 或 `active_cnt == 0` 时，不再为每条 BPF 指令调用 `bpf_jit_apply_prog_rule()`。
3. 删除 `jit_directives.c` 的本地 `bpf_jit_main_aux()`，统一复用公共 `bpf_prog_main_aux()`；同时把 recompile stage 清理 helper 提到公共头，消除和 x86 私有 `bpf_jit_recompile_clear_stage()` 的重复实现。

## 代码修改

### 1. Snapshot 后移到 parse/validate 之后

修改：

- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c:3530`

要点：

- `prog->blinded` 的 reject 现在发生在 stock re-JIT / custom policy 两条路径之前。
- custom policy 路径先执行 `bpf_jit_parse_policy()` 和 `active_cnt` 检查。
- 只有在这些 cheap reject 全部通过后，才调用 `bpf_jit_recompile_snapshot()`。

效果：

- 非法 policy、零 active rule、blinded prog、unsupported case 不再先 `kmemdup()` 整个 prog/subprog 指令数组。
- stock re-JIT 仍保留 rollback 语义，但 snapshot 不再早于 `blinded` reject。

### 2. 无 active rule 时跳过 `do_jit()` rule dispatch

修改：

- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3716`

要点：

- `do_jit()` 入口新增：
  - `main_aux = bpf_prog_main_aux(bpf_prog)`
  - `policy = main_aux->jit_policy`
  - `has_active_rules = policy && policy->active_cnt`
- 主循环里仅在 `has_active_rules` 为真时调用 `bpf_jit_apply_prog_rule()`。

效果：

- non-recompile / no-policy 场景不会再为每条 BPF 指令走一层 rule lookup / dispatch。
- 运行时 JIT image 不变，优化的是 JIT 编译期 hot path。

### 3. 公共 helper 去重

修改：

- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/bpf.h:1842`
- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c:67`
- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5831`

要点：

- `bpf_prog_main_aux()` 改为 null-safe，并作为唯一的 main-aux helper。
- 新增公共 inline：
  - `bpf_jit_recompile_clear_stage()`
  - `bpf_jit_recompile_reset_prog_aux()`
- `jit_directives.c` 删除本地 `bpf_jit_main_aux()` / `bpf_jit_recompile_reset_prog_aux()`。
- x86 删除本地 `bpf_jit_recompile_clear_stage()`，直接复用公共 helper。

效果：

- `main_aux` 选择逻辑和 stage 字段清零逻辑各只保留一份。
- 避免公共层和 x86 backend 继续出现实现漂移。

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
- 最终消息：`Kernel: arch/x86/boot/bzImage is ready  (#52)`

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
FAIL Wide Site-Only JIT Diff: non-site bytes changed outside site image 149->137 pre[0x33,0x45) post[0x33,0x39) [0x91]=27 -> [0x85]=67 [0x92]=20 -> [0x86]=1f
```

结论：

- 结果和 Phase A 一致，没有新增 selftest 回归。
- 本轮 Phase B 修改未改变项目当前已知的 `19/20 pass` 状态。

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
  kernel     compile median 4.623 ms | exec median 12 ns | result 12345678
  kernel-recompile compile median 4.089 ms | exec median 10 ns | result 12345678
[bench] load_byte_recompose
  kernel     compile median 4.264 ms | exec median 296 ns | result 1253018829653002637
  kernel-recompile compile median 4.064 ms | exec median 356 ns | result 1253018829653002637
```

说明：

- stock / recompile 两条路径都成功执行。
- 两个 smoke benchmark 的结果值保持一致。

### 4. Diff hygiene

命令：

```bash
git -C vendor/linux-framework diff --check
```

结果：

- PASS
- 无空白 / 尾随空格问题

## 变更清单

- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/bpf.h`
- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c`
- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

## 最终状态

- Problem 4a：已修复
- Problem 5：已修复
- Problem 8a：已修复
- Problem 8b：已修复
- 内核构建：通过
- `vm-micro-smoke`：通过
- `vm-selftest`：保持项目既有状态 `19/20 pass`，唯一失败项仍为已知 `Wide Site-Only JIT Diff`
