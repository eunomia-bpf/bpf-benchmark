# Kernel Fix Phase C1

日期：2026-03-19

范围：

- `COND_SELECT` 的 `site_len==2` guarded-update validator 支持
- 仅修改 `vendor/linux-framework/` 内核代码
- 未修改用户态代码
- 未 commit / push

## 结论

本轮已补齐 `COND_SELECT` 的 2-insn guarded-update validator 支持，x86 emitter 里的 `emit_bpf_cmov_guarded_update()` 不再是死代码。

修复后：

- validator 接受 `site_len==2` 的 `jcc +1; mov dst, src/imm` guarded-update shape
- validator 会从真实 BPF site 解析并归一化 `COND_SELECT` canonical params
- `rule->params` 现在会被填成完整、规范化后的 `dst/cond/true/false/width`
- 为兼容现有 scanner 产出的 2-insn rule，validator 在校验时接受 legacy 的 `TRUE_VAL/FALSE_VAL` 交换绑定，但写回 `rule->params` 时会统一归一化成真实语义

## 代码修改

修改文件：

- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c`

要点：

1. 新增 `COND_SELECT` site parser
   - 新增 `bpf_jit_cmov_select_match_guarded_update()`
   - 新增 `bpf_jit_parse_cond_select_shape()`
   - 统一支持 3 种 x86 当前可 lower 的 shape：
     - `site_len=2` guarded-update
     - `site_len=3` compact
     - `site_len=4` diamond

2. `COND_SELECT` validator 改为 exact shape + param 校验
   - `bpf_jit_validate_cond_select_rule()` 现在不只是看 `site_len`
   - 会把 site 解析成 canonical shape，再核对：
     - `DST_REG`
     - `COND_OP`
     - `COND_A`
     - `COND_B`
     - `TRUE_VAL`
     - `FALSE_VAL`
     - `WIDTH`

3. 归一化写回 `rule->params`
   - validator 成功后会用真实 site 重新填充 `params`
   - 这样 x86 emitter 后续如果改为直接消费 `rule->params`，字段已经齐全

4. legacy 2-insn binding 兼容
   - 当前 scanner 的 2-insn guarded-update 绑定顺序与真实分支语义存在历史交换
   - validator 对 `site_len==2` 会接受这组 legacy 绑定
   - 但最终写回的 `rule->params` 已归一化为：
     - `TRUE_VAL = dst`（条件为真时跳过 update）
     - `FALSE_VAL = mov src/imm`（条件为假时执行 update）

## Spot Check

仓库内确实存在真实的 `site_len==2` `COND_SELECT` 输入：

命令：

```bash
./scanner/build/bpf-jit-scanner scan micro/programs/log2_fold.bpf.o --cmov --json
```

关键结果：

```text
site_id=cmov:101:cond-select-64
site_len=2
canonical_form=4
native_choice=1
```

这说明本次修复覆盖的不是理论路径，而是当前仓库已有的真实 scanner 输出。

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
- 最终消息：`Kernel: arch/x86/boot/bzImage is ready  (#53)`

### 2. `make vm-selftest`

命令：

```bash
source /home/yunwei37/workspace/.venv/bin/activate
cd /home/yunwei37/workspace/bpf-benchmark
make vm-selftest
```

结果：

- 保持项目当前既有状态：`19/20 PASS`
- 唯一失败项仍是已知的 `Wide Site-Only JIT Diff`

失败摘要：

```text
FAIL Wide Site-Only JIT Diff: non-site bytes changed outside site image 149->137 pre[0x33,0x45) post[0x33,0x39) [0x91]=43 -> [0x85]=83 [0x92]=20 -> [0x86]=1f
```

结论：

- 本轮 `COND_SELECT` validator 修复没有引入新的 selftest 回归

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
  kernel     compile median 5.752 ms | exec median 11 ns | result 12345678
  kernel-recompile compile median 3.892 ms | exec median 10 ns | result 12345678
[bench] load_byte_recompose
  kernel     compile median 4.413 ms | exec median 124 ns | result 1253018829653002637
  kernel-recompile compile median 4.114 ms | exec median 285 ns | result 1253018829653002637
```

说明：

- stock / recompile 两条路径都能正常执行
- recompile 后结果值保持一致

### 4. Diff hygiene

命令：

```bash
git -C vendor/linux-framework diff --check
```

结果：

- PASS
- 无空白 / 尾随空格问题

## 最终状态

- `COND_SELECT` `site_len==2` guarded-update validator：已支持
- `rule->params` 归一化填充：已完成
- 内核构建：通过
- `vm-selftest`：保持项目既有 `19/20 pass`
- `vm-micro-smoke`：通过
