# Per-form Benchmarks Implementation

日期：2026-03-13

## 目标

按 `docs/tmp/per-form-benchmark-analysis.md` 的建议，为当前 x86 object-scan micro suite 新增 6 个纯隔离 benchmark：

- `cond_select_dense` for `COND_SELECT`
- `rotate_dense` for `ROTATE`
- `addr_calc_stride` for `ADDR_CALC`
- `extract_dense` for `BITFIELD_EXTRACT`
- `endian_swap_dense` for `ENDIAN_FUSION`
- `branch_flip_dense` for `BRANCH_FLIP`

## 实现内容

新增程序：

- `micro/programs/cond_select_dense.bpf.c`
- `micro/programs/rotate_dense.bpf.c`
- `micro/programs/addr_calc_stride.bpf.c`
- `micro/programs/extract_dense.bpf.c`
- `micro/programs/endian_swap_dense.bpf.c`
- `micro/programs/branch_flip_dense.bpf.c`

输入生成器与注册：

- `micro/input_generators.py`
  - `generate_cond_select_dense()`
  - `generate_rotate_dense()`
  - `generate_addr_calc_stride()`
  - `generate_extract_dense()`
  - `generate_endian_swap_dense()`
  - `generate_branch_flip_dense()`
  - 注册到 `GENERATORS`

manifest：

- `config/micro_pure_jit.yaml`
  - 新增 6 个 benchmark 条目
  - 绑定到对应 `micro/policies/per_family/*.yaml`
  - 填入各自 `expected_result`

## 关键实现点

- `cond_select_dense`
  - 使用 aligned staged struct 的 direct load。
  - 热路径只保留 `selected = on_true; if (lhs <= rhs) selected = on_false; acc += selected ^ bias;`
  - 不使用 `micro_read_u64_le()`，不使用 `micro_rotl64()`。

- `rotate_dense`
  - 入口只 native-load 8 个 seed。
  - 后续 8 groups x 8 rounds 全部在寄存器里做 ARX。
  - 热路径只有 `micro_rotl64()` 驱动的 rotate pattern。

- `addr_calc_stride`
  - 第一个版本被 clang 折叠成 `shift + mask + add base`，scanner 不认。
  - 最终版本先把 `index` 稳定下来，再用独立的
    `addr = index; addr <<= 3; addr += base_addr;`
    生成 scanner 需要的 `mov/lsh/add` 三连。

- `extract_dense`
  - 使用 aligned `u64 vals[]` direct load。
  - 每个 site 只做 `(word >> 5) & 0x1f` 和 `(word >> 17) & 0x3ff`。

- `endian_swap_dense`
  - 使用 aligned `__u32` load + `__builtin_bswap32()`。
  - 不使用 `micro_read_u16_be()` / `micro_read_u32_be()` byte ladder。

- `branch_flip_dense`
  - 第一个版本在 branch body 里用了大 64-bit 常量，clang 生成 `lddw`，scanner 不认。
  - 最终版本把 body immediates 压到 32-bit 范围内，保持 body 只含简单 ALU。
  - scanner 最终识别出 `255` 个 `branch-flip` site；隔离性是干净的，缺失的 1 个 site 来自首个分支块被编译器折叠。

## 验证命令

已执行：

```bash
make -C micro programs
python3 micro/run_micro.py --list | grep -E 'cond_select_dense|rotate_dense|addr_calc_stride|extract_dense|endian_swap_dense|branch_flip_dense'
./scanner/build/bpf-jit-scanner scan --all --json micro/programs/cond_select_dense.bpf.o
./scanner/build/bpf-jit-scanner scan --all --json micro/programs/rotate_dense.bpf.o
./scanner/build/bpf-jit-scanner scan --all --json micro/programs/addr_calc_stride.bpf.o
./scanner/build/bpf-jit-scanner scan --all --json micro/programs/extract_dense.bpf.o
./scanner/build/bpf-jit-scanner scan --all --json micro/programs/endian_swap_dense.bpf.o
./scanner/build/bpf-jit-scanner scan --all --json micro/programs/branch_flip_dense.bpf.o
```

`run_micro.py --list` 已确认 6 个 benchmark 都已注册：

- `cond_select_dense`
- `rotate_dense`
- `addr_calc_stride`
- `extract_dense`
- `endian_swap_dense`
- `branch_flip_dense`

## Scanner 结果

| Benchmark | Target form | Scanner summary | Isolation |
|---|---|---|---|
| `cond_select_dense` | `COND_SELECT` | `cmov=256`, others `0` | Pass |
| `rotate_dense` | `ROTATE` | `rotate=256`, others `0` | Pass |
| `addr_calc_stride` | `ADDR_CALC` | `lea=8`, others `0` | Pass |
| `extract_dense` | `BITFIELD_EXTRACT` | `extract=512`, others `0` | Pass |
| `endian_swap_dense` | `ENDIAN_FUSION` | `endian=256`, others `0` | Pass |
| `branch_flip_dense` | `BRANCH_FLIP` | `branch_flip=255`, others `0` | Pass |

补充说明：

- `extract_dense` 的 scanner JSON 同时填了 `extract_sites=512` 和 `bitfield_sites=512`，但不包含任何非目标 form。
- `branch_flip_dense` 的 `255` site 已满足“>=8 且其他 form = 0”的隔离目标。

## Expected Results

最终写入 manifest 的 `expected_result`：

- `cond_select_dense`: `10269805450048292947`
- `rotate_dense`: `14870098989209412331`
- `addr_calc_stride`: `9302301800681049161`
- `extract_dense`: `13503953896175652977`
- `endian_swap_dense`: `4354686090269194327`
- `branch_flip_dense`: `255429993929868791`
