# Per-form Benchmark Analysis

日期：2026-03-13

## 方法与范围

- 先阅读了 `docs/kernel-jit-optimization-plan.md`、`config/micro_pure_jit.yaml`、以及 `micro/programs/*.bpf.c`。
- 按用户要求实际构建并扫描了全部 micro objects。
- 需要说明一点：`micro/programs/Makefile` 实际产物在 `micro/programs/*.bpf.o`，不是 `micro/programs/build/*.bpf.o`。所以下面使用的真实扫描路径是：

```bash
make -C micro programs
cmake --build scanner/build --target bpf-jit-scanner -j
for f in micro/programs/*.bpf.o; do
  ./scanner/build/bpf-jit-scanner scan --all --json "$f"
done
```

- 原始扫描汇总已保存到 `docs/tmp/per_form_scan_micro.json`。
- 本报告的 coverage 表严格按 `.bpf.o` object scan 口径写；live xlated 结果可能不同。一个明显例子是 `cmov_select`：
  - 当前 object scan：`cmov=0, wide=6, rotate=4`
  - 当前 `micro/policies/cmov_select.yaml` 注释记录的是 live manifest：`cmov=1, rotate=4, wide=6`
- 因此，下面会把“scanner 实际看到的 form”和“benchmark 名义上想测什么”分开讨论。

## 结论摘要

1. 当前 56 个 benchmark 里，`23` 个是单 form，`29` 个是混合 form，`4` 个完全没有 site。
2. 这 `23` 个单 form benchmark 全部都是 `WIDE_MEM`；当前 suite 没有任何一个纯 `COND_SELECT` / `ROTATE` / `ADDR_CALC` / `BITFIELD_EXTRACT` / `BRANCH_FLIP` benchmark。
3. `ZERO_EXT_ELIDE` 和 `ENDIAN_FUSION` 在当前 micro object suite 上都是 `0` coverage。
4. 以 per-form benchmark 的标准看，当前 suite 还不是“每个 canonical form 都有隔离 benchmark”，而是“许多 workload-shaped benchmark 偶然携带了一些 canonical sites”。
5. 最严重的名实不符 benchmark：
   - `cmov_select`：名字是 select-diamond，但当前 object scan 没有 `COND_SELECT`
   - `branch_layout`：名字是 branch/layout，但当前 object scan 只有 `WIDE_MEM`
   - `branch_fanout_32`：名字是 branch-fanout，但当前 object scan 主体是 `ROTATE`
   - `packet_parse_vlans_tcpopts`：源码看起来 endian-heavy，但当前 object scan 是 `WIDE_MEM + BITFIELD_EXTRACT`，没有 `ENDIAN_FUSION`

## 56 Benchmark Coverage 表

说明：
- `cmov` = `COND_SELECT`
- `wide` = `WIDE_MEM`
- `rotate` = `ROTATE`
- `lea` = `ADDR_CALC`
- `extract` = `BITFIELD_EXTRACT`
- `zeroext` = `ZERO_EXT_ELIDE`
- `endian` = `ENDIAN_FUSION`
- `bflip` = `BRANCH_FLIP`

| Benchmark | YAML family | Object-scan sites | Class | Note |
|---|---|---|---|---|
| `simple` | `baseline` | none | none | no-site baseline |
| `simple_packet` | `baseline` | none | none | no-site baseline |
| `memory_pair_sum` | `baseline` | wide×2 | single | pure WIDE_MEM background load pair |
| `bitcount` | `popcount` | wide×2 | single | - |
| `log2_fold` | `log2-fold` | cmov×8, wide×3 | mixed | closest low-mix COND_SELECT candidate |
| `dep_chain_short` | `dep-chain` | wide×2 | single | - |
| `dep_chain_long` | `dep-chain` | wide×2 | single | - |
| `binary_search` | `search` | cmov×1, wide×2 | mixed | control-flow benchmark; scanner sees one COND_SELECT site |
| `branch_layout` | `branch-skew` | wide×2 | single | branch-skew benchmark, but no BRANCH_FLIP sites |
| `switch_dispatch` | `switch-dispatch` | cmov×1, wide×2 | mixed | control-flow benchmark; scanner sees COND_SELECT, not BRANCH_FLIP |
| `branch_dense` | `branch-density` | cmov×1, wide×2, bflip×4 | mixed | closest BRANCH_FLIP candidate |
| `cmov_select` | `select-diamond` | wide×6, rotate×4 | mixed | intended CMOV benchmark; object scan finds no COND_SELECT |
| `cmov_dense` | `select-diamond` | cmov×32, rotate×26 | mixed | closest high-density COND_SELECT candidate |
| `checksum` | `reduction` | wide×2 | single | - |
| `load_word32` | `load-width` | wide×2 | single | - |
| `load_byte` | `load-width` | wide×2 | single | - |
| `load_byte_recompose` | `causal-isolation` | wide×1 | single | best pure WIDE_MEM benchmark |
| `load_native_u64` | `causal-isolation` | none | none | no-site gap baseline; paired with load_byte_recompose |
| `packet_parse` | `parser` | wide×5 | single | - |
| `bounds_ladder` | `bounds-density` | cmov×2, wide×2 | mixed | mixed bounds + select, not pure COND_SELECT |
| `bounds_check_heavy` | `bounds-style` | wide×13, extract×1 | mixed | - |
| `stride_load_4` | `stride-load` | wide×2, lea×1 | mixed | closest ADDR_CALC candidate |
| `stride_load_16` | `stride-load` | wide×2, lea×1 | mixed | closest ADDR_CALC candidate |
| `mixed_alu_mem` | `mixed-alu-mem` | wide×1, extract×2 | mixed | - |
| `spill_pressure` | `spill-pressure` | wide×2 | single | - |
| `multi_acc_4` | `multi-acc` | wide×2, lea×1 | mixed | - |
| `multi_acc_8` | `multi-acc` | wide×2, lea×2 | mixed | - |
| `fibonacci_iter` | `recurrence` | wide×4 | single | - |
| `fibonacci_iter_packet` | `recurrence` | wide×4 | single | - |
| `fixed_loop_small` | `fixed-loop` | wide×3, rotate×1 | mixed | - |
| `fixed_loop_large` | `fixed-loop` | wide×3, rotate×1 | mixed | - |
| `nested_loop_2` | `nested-loop` | wide×3 | single | - |
| `nested_loop_3` | `nested-loop` | wide×3 | single | - |
| `code_clone_2` | `code-clone` | wide×1, rotate×1 | mixed | - |
| `code_clone_8` | `code-clone` | wide×1, rotate×2 | mixed | - |
| `large_mixed_500` | `large-mixed` | wide×1, rotate×7, bflip×3 | mixed | - |
| `large_mixed_1000` | `large-mixed` | wide×1, rotate×7, bflip×8 | mixed | highest BRANCH_FLIP count, but heavily mixed |
| `bpf_call_chain` | `bpf-local-call` | cmov×1, wide×2 | mixed | - |
| `memcmp_prefix_64` | `byte-compare` | wide×1, rotate×3 | mixed | - |
| `packet_parse_vlans_tcpopts` | `parser` | wide×6, extract×1 | mixed | semantically endian-ish parser, but no ENDIAN_FUSION sites |
| `local_call_fanout` | `bpf-local-call` | wide×3 | single | - |
| `packet_rss_hash` | `packet-hash` | wide×2, rotate×11 | mixed | - |
| `imm64_storm` | `immediate-stress` | wide×4, rotate×64 | mixed | near-pure ROTATE except header loads |
| `alu32_64_pingpong` | `mixed-width` | wide×3, rotate×1 | mixed | - |
| `branch_fanout_32` | `branch-fanout` | wide×1, rotate×8 | mixed | branch benchmark, but scanner mostly sees ROTATE |
| `deep_guard_tree_8` | `deep-guards` | wide×2 | single | - |
| `mega_basic_block_2048` | `mega-block` | wide×8, rotate×512 | mixed | closest ROTATE candidate; highest rotate density |
| `rotate64_hash` | `rotate-hash` | wide×7, rotate×116 | mixed | closest ROTATE candidate |
| `packet_redundant_bounds` | `bounds-density` | wide×8 | single | - |
| `const_fold_chain` | `const-fold` | wide×2 | single | - |
| `struct_field_cluster` | `field-access` | none | none | no-site characterization benchmark |
| `bitfield_extract` | `bitfield-extract` | wide×2, extract×9 | mixed | closest BITFIELD_EXTRACT candidate |
| `smallmul_strength_reduce` | `strength-reduce` | wide×2 | single | - |
| `tc_bitcount` | `popcount` | wide×2 | single | - |
| `tc_checksum` | `reduction` | wide×2 | single | - |
| `cgroup_hash_chain` | `hash-chain` | wide×2 | single | - |

## Coverage 汇总

### 按 canonical form 统计

| Canonical form | Benchmarks with sites | Total sites | Pure isolated benchmark? |
|---|---:|---:|---|
| `COND_SELECT` | 7 | 46 | No |
| `WIDE_MEM` | 51 | 146 | Yes |
| `ROTATE` | 15 | 764 | No |
| `ADDR_CALC` | 4 | 5 | No |
| `BITFIELD_EXTRACT` | 4 | 13 | No |
| `ZERO_EXT_ELIDE` | 0 | 0 | No |
| `ENDIAN_FUSION` | 0 | 0 | No |
| `BRANCH_FLIP` | 3 | 15 | No |

### 单 form / 混合 / 无 site

- 单 form：23 个
  - 全部都是 `WIDE_MEM` only
  - 名单：`bitcount`、`branch_layout`、`cgroup_hash_chain`、`checksum`、`const_fold_chain`、`deep_guard_tree_8`、`dep_chain_long`、`dep_chain_short`、`fibonacci_iter`、`fibonacci_iter_packet`、`load_byte`、`load_byte_recompose`、`load_word32`、`local_call_fanout`、`memory_pair_sum`、`nested_loop_2`、`nested_loop_3`、`packet_parse`、`packet_redundant_bounds`、`smallmul_strength_reduce`、`spill_pressure`、`tc_bitcount`、`tc_checksum`
- 混合 form：29 个
  - 这部分才是当前 suite 的主体现实
  - 尤其 `cmov_dense`、`rotate64_hash`、`bitfield_extract`、`stride_load_*`、`branch_dense` 都是“离目标 form 很近，但还不够干净”
- 无 site：4 个
  - `simple`
  - `simple_packet`
  - `load_native_u64`
  - `struct_field_cluster`

## 8 Form Isolation 状态

| Form | 是否已有纯 benchmark | 最接近的现有 benchmark | 结论 | 下一步 |
|---|---|---|---|---|
| `COND_SELECT` | No | `cmov_dense`；次优 `log2_fold` | 缺失纯隔离 benchmark | 新增纯 `COND_SELECT` benchmark |
| `WIDE_MEM` | Yes | `load_byte_recompose` | 已有可用纯 benchmark | 保留它作为 canonical WIDE benchmark |
| `ROTATE` | No | `mega_basic_block_2048`；次优 `rotate64_hash` | 近乎纯，但始终带少量 `WIDE_MEM` 读入噪声 | 新增纯 `ROTATE` benchmark |
| `ADDR_CALC` | No | `stride_load_16` / `stride_load_4` | 当前所有 `LEA` site 都和 `WIDE_MEM` 绑定 | 新增纯 `ADDR_CALC` benchmark |
| `BITFIELD_EXTRACT` | No | `bitfield_extract` | 非常接近纯 benchmark，但仍有 `WIDE_MEM` | 重写当前 benchmark 或新增纯版本 |
| `ZERO_EXT_ELIDE` | No | none | 当前 x86 raw-object 路径本身看不到它 | 移到 cross-arch / live-xlated 子套件 |
| `ENDIAN_FUSION` | No | none；语义上最接近 `packet_parse_vlans_tcpopts` | 当前 suite 完全缺失 | 新增纯 `ENDIAN_FUSION` benchmark |
| `BRANCH_FLIP` | No | `branch_dense`；次优 `large_mixed_1000` | 有少量 site，但 benchmark 明显混合 | 新增纯 `BRANCH_FLIP` benchmark |

### 逐 form 判断

#### `COND_SELECT`

- 没有纯 benchmark。
- `cmov_dense` 最接近：`cmov×32` 很强，但同时有 `rotate×26`。
- `log2_fold` 更干净一些：`cmov×8, wide×3`，但强度偏弱。
- `cmov_select` 不能再当作 object-scan authoritative 的 pure CMOV benchmark。

#### `WIDE_MEM`

- 唯一已经有纯隔离 benchmark 的 form。
- 最好的 canonical benchmark 仍然是 `load_byte_recompose`。
- `load_native_u64` 应保留为 paired no-site control，而不是算入 per-form benchmark。

#### `ROTATE`

- 没有纯 benchmark。
- `mega_basic_block_2048` 的热路径几乎全是 rotate，但开头 8 个输入种子仍由 byte-ladder 读入，scanner 记为 `wide×8, rotate×512`。
- `rotate64_hash` 也是类似问题：核心逻辑是 rotate-heavy，输入读入还是 `wide×7`。

#### `ADDR_CALC`

- 没有纯 benchmark。
- 当前 `stride_load_4` / `stride_load_16` 的 `LEA` 只出现 1 次，而且和 `micro_read_u64_le()` 的 `WIDE_MEM` 同时出现。
- 这说明 suite 有“LEA 能触发”的证据，但没有“LEA 能隔离测量”的 benchmark。

#### `BITFIELD_EXTRACT`

- 没有纯 benchmark。
- `bitfield_extract` 已经很接近：`extract×9, wide×2`。
- 它的问题主要不是 extract 热路径，而是输入读入仍然靠 `micro_read_u64_le()`。

#### `ZERO_EXT_ELIDE`

- 当前 suite 完全没有 site。
- 这不是 scanner 漏扫，而是当前 x86 raw-object 路径就没有这种 pair：
  - raw `.bpf.o` 没有 verifier 后插入的 zext
  - x86-64 live path 上 `bpf_jit_needs_zext()=false`，也不会插这类 pair
- 所以它不应该继续被当作“当前 x86 micro suite 的一个待补 benchmark”，而应被重新定义成：
  - cross-arch benchmark，或
  - live-xlated-only benchmark

#### `ENDIAN_FUSION`

- 当前 suite 完全没有 site。
- `packet_parse_vlans_tcpopts` 虽然在语义上大量做 big-endian 解析，但源码用的是 `micro_read_u16_be()` / `micro_read_u32_be()` byte ladder，所以 object scan 看不到 `ldx + bswap` 两连，自然也没有 `ENDIAN_FUSION`。

#### `BRANCH_FLIP`

- 没有纯 benchmark。
- `branch_dense` 是当前最接近的：`bflip×4`，但同时带 `cmov×1` 和 `wide×2`。
- `large_mixed_1000` 的 `bflip×8` 更高，但混合了 `rotate×7, wide×1`，不适合做 isolation。

## 新 Benchmark 设计建议

下面的设计都遵循同一原则：

- 热路径只包含目标 canonical form 的最小源码模式
- 输入读入改成 aligned native load，避免 `micro_read_u64_le()` 把 benchmark 污染成 `WIDE_MEM`
- 使用 `32` 到 `64` 次外层循环，配合 `8` 到 `16` 个内联 site，保证单次执行动态命中数达到 `256+`，让 `exec_ns` 明显高于 `100ns`

### scratch 验证过的纯模式

我在本次分析里用最小 scratch object 直接验证了这些源码形状确实能被当前 scanner 单独识别：

| Target form | Scratch object-scan result |
|---|---|
| `COND_SELECT` | `cmov×8`, others `0` |
| `ROTATE` | `rotate×32`, others `0` |
| `ADDR_CALC` | `lea×1`, others `0` |
| `BITFIELD_EXTRACT` | `extract×16`, others `0` |
| `ENDIAN_FUSION` | `endian×8`, others `0` |
| `BRANCH_FLIP` | `bflip×8`, others `0` |
| `ZERO_EXT_ELIDE` | x86 object-scan 仍为 `0` |

### 建议 1：`cond_select_native_dense.bpf.c`

- 目标 form：`COND_SELECT`
- 热路径模式：

```c
u64 selected = on_true;
if (lhs <= rhs)
    selected = on_false;
asm volatile("" : "+r"(selected), "+r"(on_true), "+r"(on_false) :: "memory");
acc += selected ^ bias;
```

- 输入布局：
  - aligned struct：`a[]`, `b[]`, `x[]`, `y[]`
  - 直接 `p->a[i]` / `p->b[i]` / `p->x[i]` / `p->y[i]`
- 预期 sites：
  - static：`cmov≈8-16`
  - others：`0`
- 规模建议：
  - `GROUPS=32`, `LANES=8`
  - 动态 select 命中 `256` 次以上
- 备注：
  - 不要再用 `__noinline` subprog + `micro_rotl64()` 的当前 `cmov_select` 写法；那会把 benchmark 重新污染成 `WIDE_MEM` / `ROTATE`

### 建议 2：`rotate_native_dense.bpf.c`

- 目标 form：`ROTATE`
- 热路径模式：

```c
a += micro_rotl64(b ^ c, k1);
b ^= micro_rotl64(c + d, k2);
c += micro_rotl64(d ^ a, k3);
d ^= micro_rotl64(a + b, k4);
```

- 输入布局：
  - 只在入口处一次性 native-load 4 到 8 个 seed
  - 后续热路径只在寄存器里滚动
- 预期 sites：
  - static：`rotate≈32`
  - others：`0`
- 规模建议：
  - `8` rounds × `4` rotate/block × `8` outer groups
  - 动态 rotate 命中 `256` 次以上
- 备注：
  - 这可以替代今天 `rotate64_hash` / `mega_basic_block_2048` 的“近乎纯 rotate，但仍带 header WIDE”状态

### 建议 3：`addr_calc_native_stride.bpf.c`

- 目标 form：`ADDR_CALC`
- 热路径模式：

```c
u64 addr = index;
addr <<= 3;
addr += (__u64)(unsigned long)base;
u64 v = *(__u64 *)(const void *)(unsigned long)addr;
acc += v ^ i;
```

- 预期 sites：
  - static：`lea≈8`（通过显式复制 8 个独立 block）
  - others：`0`
- 规模建议：
  - `8` 个静态 address-calc block
  - 外层 `32` 次循环
- 关键实现细节：
  - 不要写成普通的 `base + (index << 3)`；当前 clang 常会把它编成“copy base, add scaled index”的形状，scanner 不一定认成 `ADDR_CALC`
  - 上面这种“先构造整数地址，再转回指针”的写法已经 scratch 验证可触发纯 `lea`

### 建议 4：`bitfield_extract_native_dense.bpf.c`

- 目标 form：`BITFIELD_EXTRACT`
- 热路径模式：

```c
u64 word = p->vals[i];
u64 f0 = (word >> 5) & 0x1fULL;
u64 f1 = (word >> 17) & 0x3ffULL;
acc += f0 + f1;
```

- 输入布局：
  - aligned `u64 vals[]`
  - 不再使用 `micro_read_u64_le()`
- 预期 sites：
  - static：`extract≈16`
  - others：`0`
- 规模建议：
  - `32` records × `8` field ops 以上
- 备注：
  - 如果不想新增文件，也可以直接把当前 `bitfield_extract.bpf.c` 改造成这个版本

### 建议 5：`endian_load_swap_dense.bpf.c`

- 目标 form：`ENDIAN_FUSION`
- 热路径模式：

```c
__u32 v = __builtin_bswap32(p->vals[i]);
acc += v;
```

- 预期 sites：
  - static：`endian≈8`
  - others：`0`
- 规模建议：
  - `32` 到 `64` 个 big-endian words
  - 外层 `32` 次以上
- 关键实现细节：
  - 不要用 `micro_read_u16_be()` / `micro_read_u32_be()`；它们会编成 byte ladder，而不是 `ldx + bswap`
  - 要用 native aligned load + `__builtin_bswapXX()` 或 `bpf_ntohX()`
- 可选扩展：
  - 最好拆成 `endian_load_swap_16` / `_32` / `_64` 三个 width-specific benchmark，因为 `movbe` 变体本来就分宽度

### 建议 6：`branch_flip_dense_native.bpf.c`

- 目标 form：`BRANCH_FLIP`
- 热路径模式：

```c
if ((v & mask) != 0) {
    acc += v + c1;
    acc ^= v >> 3;
} else {
    acc ^= v + c2;
    acc += v << 1;
}
```

- 预期 sites：
  - static：`bflip≈8`
  - others：`0`
- 规模建议：
  - `8` 个静态 diamond
  - 外层 `32` 次循环
- 关键实现细节：
  - if/else body 里只能放 scanner 支持的简单 ALU / load / endian 类指令
  - 不要把 `micro_rotl64()` 或其他 rotate 操作放进 body，否则会重新混入 `ROTATE`

### 建议 7：`zero_ext_alu32_crossarch.bpf.c`

- 目标 form：`ZERO_EXT_ELIDE`
- 热路径模式：

```c
u32 acc = 0;
acc += v;
acc ^= v >> 3;
acc *= 33U;
```

- object-scan 现实：
  - 当前 x86 raw-object 扫描仍然会得到 `zeroext=0`
- 因此推荐定位：
  - 不放进“当前 x86 object-scan micro suite”的 per-form KPI
  - 单独放进：
    - ARM64 / RISC-V 子套件，或
    - `--prog-fd` / `--xlated` live verifier/JIT path benchmark

## 现有 Benchmark 改进建议

### 直接改造成更好 per-form isolation benchmark

| Existing benchmark | 建议动作 | 原因 |
|---|---|---|
| `cmov_dense` | 去掉 `micro_rotl64()`，保留 aligned loads + select diamond | 现在是最接近 pure `COND_SELECT` 的 benchmark |
| `bitfield_extract` | 改成 aligned native `u64` load + shift/mask | 现在只差 2 个 `WIDE_MEM` 污染就能变成纯 `BITFIELD_EXTRACT` |
| `stride_load_4` / `stride_load_16` | 改成显式 `u64 addr = index; addr <<= 3; addr += base;` | 这样可以保留 `ADDR_CALC`，同时去掉 `WIDE_MEM` |
| `rotate64_hash` 或 `mega_basic_block_2048` | 入口只 native-load seed，一旦进入热路径不再 byte-ladder load | 可以把近纯 `ROTATE` 改成纯 `ROTATE` |

### 保留，但从 per-form 角度重新分类

| Benchmark(s) | 重新分类建议 | 原因 |
|---|---|---|
| `cmov_select` | 重新标成“live-policy-sensitive mixed benchmark”，不要再当作 object-scan pure `COND_SELECT` | 当前 object scan 无 `COND_SELECT` |
| `branch_layout` | 重新标成“branch predictability characterization benchmark” | 当前 scanner 只有 `WIDE_MEM` |
| `binary_search` / `switch_dispatch` / `bounds_ladder` | 重新标成“control-flow mixed benchmark” | 都不是纯 `BRANCH_FLIP` 或纯 `COND_SELECT` |
| `branch_fanout_32` | 重新标成“mixed control-flow + rotate benchmark” | 当前主 form 是 `ROTATE`，不是 `BRANCH_FLIP` |
| `large_mixed_500` / `large_mixed_1000` | 重新标成“stress / interference benchmark” | 本来就是多 form 混合，不适合做 per-form evidence |
| `packet_parse_vlans_tcpopts` | 重新标成“parser mixed benchmark”，不要再暗示它是 endian benchmark | 当前没有 `ENDIAN_FUSION` site |

### 明确标成 no-site / characterization benchmark

| Benchmark(s) | 分类 | 原因 |
|---|---|---|
| `simple`, `simple_packet` | harness baseline | 本来就是 baseline |
| `load_native_u64` | no-site causal-isolation control | 用来和 `load_byte_recompose` 形成 gap 对照 |
| `struct_field_cluster` | field-access characterization | 当前 object scan 完全无 canonical site |

## 推荐的新 suite 结构

如果目标是“micro suite 定位为 per-form instruction benchmark”，建议把 suite 拆成三层：

1. `per-form canonical`
   - 每个 canonical form 至少 1 个纯 benchmark
   - 当前只有 `WIDE_MEM` 达标

2. `mixed / interaction`
   - 保留 `large_mixed_*`、`branch_dense`、`switch_dispatch`、`rotate64_hash` 这类 benchmark
   - 这些 benchmark 用来研究 family interaction，不再当作单 form 证据

3. `characterization / no-site controls`
   - `simple`
   - `simple_packet`
   - `load_native_u64`
   - `struct_field_cluster`

## 最终建议

- 先不要继续把现有 56-bench suite 当作“8 canonical forms 全覆盖的 per-form suite”。
- 最优先新增/改造的 benchmark：
  - `cond_select_native_dense.bpf.c`
  - `rotate_native_dense.bpf.c`
  - `addr_calc_native_stride.bpf.c`
  - `bitfield_extract_native_dense.bpf.c`
  - `endian_load_swap_dense.bpf.c`
  - `branch_flip_dense_native.bpf.c`
- `ZERO_EXT_ELIDE` 不建议硬塞进当前 x86 object suite；应单独按 cross-arch 或 live-xlated 路径处理。
- 在这些 benchmark 落地前，paper/报告里应使用更保守的表述：
  - 当前 micro suite 证明的是“scanner 在 suite 中能看到哪些 canonical forms”
  - 不是“每个 form 都已经有一个 clean isolation benchmark”
