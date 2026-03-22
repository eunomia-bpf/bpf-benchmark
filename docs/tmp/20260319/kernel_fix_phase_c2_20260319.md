# Kernel Fix Phase C2

日期：2026-03-19

范围：

- `validator/emitter params` 统一，覆盖剩余 7 个 canonical form：
  - `WIDE_MEM`
  - `ROTATE`
  - `ADDR_CALC`
  - `BITFIELD_EXTRACT`
  - `ZERO_EXT_ELIDE`
  - `ENDIAN_FUSION`
  - `BRANCH_FLIP`
- 仅修改 `vendor/linux-framework/` 内核代码
- 未修改用户态代码
- 未 commit / push

## 结论

本轮已把剩余 7 个 form 统一到同一条数据流：

- validator 是唯一从真实 BPF site 提取 canonical/emitter 参数的地方
- validator 成功后会把 `rule->params` 重写为规范化后的 site-derived params
- x86 emitter 不再为这 7 个 form 回看 `bpf_prog->insnsi`

其中：

- `WIDE_MEM` / `ROTATE` / `ADDR_CALC` / `BITFIELD_EXTRACT` / `ENDIAN_FUSION`
  - x86 emitter 原本已经是 params-only
  - 本次补齐 validator 侧的 normalized write-back

- `ZERO_EXT_ELIDE` / `BRANCH_FLIP`
  - x86 emitter 原本仍直接读取 `bpf_prog->insnsi`
  - 本次改为只消费 validator 回填到 `rule->params` 的内核内部参数

## 代码修改

修改文件：

- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c`
- `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

### 1. Kernel-internal normalized params

在 `include/linux/bpf_jit_directives.h` 新增了仅内核使用的 param slot：

- `BPF_JIT_ZEXT_PARAM_ALU32_PTR`
- `BPF_JIT_BFLIP_PARAM_SITE_PTR`

用途：

- 不暴露给 userspace binding
- 仅用于 validator 在 exact site 校验通过后，把 emitter 真正需要的输入写回 `rule->params`

### 2. 7 个 form 的 validator 统一为 “parse site -> match legacy/user params -> fill normalized params”

在 `kernel/bpf/jit_directives.c`：

- 新增通用的 `bpf_jit_param_set_reg()` / `bpf_jit_param_set_imm()` / `bpf_jit_param_set_ptr()`
- 下面 7 个 validator 现在都会在 site 校验成功后 `memset(params)` 并回填规范化结果：
  - `bpf_jit_validate_wide_mem_rule()`
  - `bpf_jit_validate_rotate_rule()`
  - `bpf_jit_validate_addr_calc_rule()`
  - `bpf_jit_validate_bitfield_extract_rule()`
  - `bpf_jit_validate_zero_ext_elide_rule()`
  - `bpf_jit_validate_endian_fusion_rule()`
  - `bpf_jit_validate_branch_flip_rule()`

具体变化：

- `WIDE_MEM`
  - validator 从真实 site 解析 `dst/base/off/encoded_width`
  - 成功后重写 `rule->params`

- `ROTATE`
  - validator 从真实 site 解析 `dst/src/amount/width`
  - 成功后重写 `rule->params`

- `ADDR_CALC`
  - validator 从真实 site 解析 `dst/base/index/scale`
  - 成功后重写 `rule->params`

- `BITFIELD_EXTRACT`
  - validator 从真实 site 解析 `dst/src/shift/mask/width/order`
  - 成功后重写 `rule->params`

- `ZERO_EXT_ELIDE`
  - 新增 `bpf_jit_parse_zero_ext_elide_shape()`
  - validator 仍兼容现有 userspace 只绑定 `DST_REG`
  - 成功后额外写入 `BPF_JIT_ZEXT_PARAM_ALU32_PTR`

- `ENDIAN_FUSION`
  - validator 从真实 site 解析 `data/base/off/width/direction`
  - 成功后重写 `rule->params`

- `BRANCH_FLIP`
  - 新增 `bpf_jit_parse_branch_flip_shape()`
  - validator 从真实 site 解析 `cond_op/body_a/body_b/join`
  - 成功后额外写入 `BPF_JIT_BFLIP_PARAM_SITE_PTR`

### 3. x86 emitter 改为只读 `rule->params`

在 `arch/x86/net/bpf_jit_comp.c`：

- `emit_canonical_zero_ext_elide()`
  - 删除对 `bpf_prog->insnsi[site_start]` 的直接读取
  - 改为从 `BPF_JIT_ZEXT_PARAM_ALU32_PTR` 取 validator 已验证的 ALU32 insn

- `emit_canonical_branch_flip()`
  - 删除对 `bpf_prog->insnsi`、`site_start`、`site_len` 的依赖
  - 改为从 `BPF_JIT_BFLIP_PARAM_SITE_PTR` 取 validator 已验证的 site 起点
  - body size 测量和 body emission 都改为基于该 params 内指针

- `bpf_jit_try_emit_rule()`
  - `ZERO_EXT_ELIDE` / `BRANCH_FLIP` dispatcher 入口现在只传 `&rule->params`

## 每个 form 的最终状态

| canonical form | validator 负责 site-derived fill | x86 emitter params-only |
| --- | --- | --- |
| `WIDE_MEM` | 是 | 是 |
| `ROTATE` | 是 | 是 |
| `ADDR_CALC` | 是 | 是 |
| `BITFIELD_EXTRACT` | 是 | 是 |
| `ZERO_EXT_ELIDE` | 是 | 是 |
| `ENDIAN_FUSION` | 是 | 是 |
| `BRANCH_FLIP` | 是 | 是 |

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
- 最终消息：`Kernel: arch/x86/boot/bzImage is ready  (#54)`

### 2. `make vm-selftest`

命令：

```bash
source /home/yunwei37/workspace/.venv/bin/activate
cd /home/yunwei37/workspace/bpf-benchmark
make vm-selftest
```

结果：

- 保持项目当前既有状态：`19/20 PASS`
- 唯一失败项仍是既有的 `Wide Site-Only JIT Diff`

失败摘要：

```text
FAIL Wide Site-Only JIT Diff: non-site bytes changed outside site image 149->137 pre[0x33,0x45) post[0x33,0x39) [0x91]=3b -> [0x85]=7b [0x92]=30 -> [0x86]=2f
```

说明：

- 这条失败与本轮 `params` 统一无直接关联
- 同一次运行中其余与 `ROTATE` / `CMOV` / recompile 语义相关的自测均通过

### 3. `make vm-micro-smoke`

命令：

```bash
source /home/yunwei37/workspace/.venv/bin/activate
cd /home/yunwei37/workspace/bpf-benchmark
make vm-micro-smoke
```

结果：

- PASS

关键结果：

```text
[bench] simple
  kernel     ... result 12345678
  kernel-recompile ... result 12345678
[bench] load_byte_recompose
  kernel     ... result 1253018829653002637
  kernel-recompile ... result 1253018829653002637
```

### 4. `make vm-micro`

命令：

```bash
source /home/yunwei37/workspace/.venv/bin/activate
cd /home/yunwei37/workspace/bpf-benchmark
make vm-micro
```

结果：

- PASS
- 产物：`/home/yunwei37/workspace/bpf-benchmark/micro/results/dev/vm_micro.json`

覆盖到的本轮相关 benchmark 结果一致，包括：

- `rotate64_hash`
- `rotate_dense`
- `addr_calc_stride`
- `bitfield_extract`
- `extract_dense`
- `endian_swap_dense`
- `branch_flip_dense`
- `cond_select_dense`
- `load_byte_recompose`

这些 benchmark 的 `kernel` / `kernel-recompile` 均返回相同结果值。

## 最终状态

- 剩余 7 个 canonical form 的 validator/emitter params 统一：已完成
- `rule->params` 现在对这 7 个 form 都由 validator 基于真实 site 归一化写回
- x86 emitter 对这 7 个 form 不再直接回看 `bpf_prog->insnsi`
- `bzImage`：通过
- `vm-micro-smoke`：通过
- `vm-micro`：通过
- `vm-selftest`：仍保留项目既有 `19/20`，唯一失败为 `Wide Site-Only JIT Diff`
