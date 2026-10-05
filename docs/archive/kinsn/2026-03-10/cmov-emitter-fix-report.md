# cmov_select Emitter Fix Report

日期：2026-03-10

## 1. Bug 根因

`cmov_select` 的唯一站点来自 subprog `cmov_select_pick()`，在完整 xlated 程序里的绝对偏移是 `925`，但在该 subprog 的本地指令流里它是一个从 `0` 开始的 3-insn compact select：

```text
0: r0 = r3
1: if r1 > r2 goto +1
2: r0 = r4
3: exit
```

v4 re-JIT 路径里的 `COND_SELECT` emitter 本身没有做错 `cmov` lowering，真正的问题是 **rule 坐标系错位**：

- policy rule 的 `site_start` 是针对完整 xlated 程序的 program-absolute index；
- 但 subprog re-JIT 时传给 emitter 的 `bpf_prog->insnsi` 是当前 subprog 的 local instruction array。

如果直接把 `rule->site_start` 拿去索引当前 subprog 的 `insns[]`，`emit_bpf_cmov_select()` / `emit_bpf_cmov_select_compact()` 就会在 subprog 边界上读错 BPF 窗口，最终生成错误的 native code。这个问题只在 subprog-local rule 上暴露；主程序内的 site 不受影响。

这不是 register save / restore 问题，也不是 compact-vs-diamond lowering 本身的语义错误。`cmov` 发射逻辑在拿到正确的 3 条 BPF 指令后是正确的；错的是它之前用来定位 site 的索引空间。

## 2. 修复方式

修复落在 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` 的 v4 rule dispatch：

1. `do_jit()` 先用 **program-absolute** 指令序号查 rule。
   - subprog 情况下，`abs_insn_idx = (i - 1) + bpf_prog->aux->subprog_start`
   - 见 `do_jit()` 中的 `abs_insn_idx` 计算和 `bpf_jit_rule_lookup()` 调用

2. `bpf_jit_try_emit_rule()` 在把 rule 交给 emitter 前，把 `site_start` 从 absolute index **rebased** 成当前 subprog 的 local index。
   - 新增 `bpf_jit_rule_local_site_start()`
   - 然后复制出 `local_rule`，用 `local_rule.site_start` 去索引 `insns[]`

3. `COND_SELECT` 的 diamond / compact emitter 都统一改为读取 `local_rule.site_start`。

对应位置：

- `bpf_jit_rule_local_site_start()`：
  `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2742`
- `bpf_jit_try_emit_rule()` 使用 rebased `local_rule`：
  `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2778`
- `do_jit()` 使用 absolute `abs_insn_idx` 查 rule：
  `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2976`

修复后的不变量是：

- rule lookup 始终在完整 xlated 程序坐标系里进行；
- emitter 访问 `insns[]` 时始终使用当前 subprog 的本地坐标；
- 同一个 rule 不允许跨 subprog boundary，这一点仍由 kernel validator 保证。

## 3. 验证方法

以下运行都基于当前 worktree 做过一次增量重建之后的内核镜像：

```bash
make -C vendor/linux-framework -j8 bzImage
```

### 3.1 `cmov_select` correctness

执行：

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec \
  "micro/build/runner/micro_exec run-kernel \
   --program micro/programs/cmov_select.bpf.o \
   --memory micro/generated-inputs/cmov_select.mem \
   --input-size 1024 --io-mode staged --repeat 3"
```

baseline 结果：

- `result = 11332120082118096118`

执行：

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec \
  "micro/build/runner/micro_exec run-kernel \
   --program micro/programs/cmov_select.bpf.o \
   --memory micro/generated-inputs/cmov_select.mem \
   --input-size 1024 --io-mode staged --repeat 3 --recompile-cmov"
```

recompile 结果：

- `directive_scan.cmov_sites = 1`
- `recompile.applied = true`
- `result = 11332120082118096118`

结论：subprog-local `cmov_select` 在 `BPF_PROG_JIT_RECOMPILE` 下已经保持与 baseline 相同的结果，不再发生错误 native emission。

### 3.2 回归 sanity check

对已有主程序内多站点 benchmark `log2_fold` 做同样验证：

- baseline：`result = 9`
- `--recompile-cmov`：`directive_scan.cmov_sites = 6`，`result = 9`

结论：这次修复没有破坏已有的非-subprog `COND_SELECT` 路径。

## 4. 结论

`cmov_select` 的 subprog correctness bug 是一个 **absolute-vs-local site index** 的 emitter dispatch bug。修复后，x86 JIT 在 subprog re-JIT 时会先用全程序坐标找到 rule，再把 `site_start` 正确 rebased 到当前 subprog 的本地指令流，`emit_bpf_cmov_select_compact()` 因而读取到正确的 3-insn select 窗口并生成正确的 `cmov` native code。
