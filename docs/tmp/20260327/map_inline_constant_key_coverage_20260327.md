# map_inline 对 ARRAY map + constant key 的覆盖分析

日期：2026-03-27

## 结论摘要

这次问题的真实 root cause 不是 `u32 key = 0; bpf_map_lookup_elem(&map, &key)` 的栈上 key=0 pattern 没被 `try_extract_constant_key()` 识别，而是：

1. 在 `corpus/build/bcc/libbpf-tools/*.bpf.o` 里，真实的 `ARRAY/PERCPU_ARRAY + bpf_map_lookup_elem` 站点非常少，总共只有 5 个。
2. 这 5 个站点的 key 都不是 `fp-4` 栈槽，而是 clang/libbpf 生成的 `BPF_PSEUDO_MAP_VALUE` `.rodata` 指针。
3. 这 5 个站点即使 key 能解析成常量，也仍然不会被当前 `map_inline` inline，因为返回值用途是“scratch/event buffer 指针”，属于 `other_use_only`，不满足“fixed-offset scalar loads only”的 use-pattern gate。
4. 因此，把 `const_prop` 提前到 `map_inline` 之前，并不能解决当前 BCC corpus 里的主要 miss。

这次修复之后，`map_inline` 已经能识别 `.rodata` pseudo-map-value 形式的 constant key；但按当前 corpus 统计，新增“key 可识别”的 ARRAY/PERCPU_ARRAY site 是 5 个，新增“真正可 inline”的 site 预期仍然是 0 个。

## 分析方法

- 直接分析编译后的 `.bpf.o`，不看 BCC 源码。
- 用 `llvm-objdump-18 -dr` spot-check 实际 bytecode。
- 另外写了一个临时离线分析脚本 `/tmp/map_inline_bcc_analysis.py`，按 `map_inline` 的 key/use 逻辑对整个 `corpus/build/bcc/libbpf-tools/` 做统计。
- 代码阅读范围：
  - `daemon/src/passes/map_inline.rs`
  - `daemon/src/passes/mod.rs`
  - `daemon/src/pass.rs`

## 1. 前 10 个 `.bpf.o` 的实际分布

前 10 个文件是：

| 文件 | map 数 | 实际 ARRAY/PERCPU_ARRAY map 数 | lookup 调用数 | 结论 |
|---|---:|---:|---:|---|
| `bashreadline.bpf.o` | 1 | 0 | 0 | 只有 `PERF_EVENT_ARRAY`，无 lookup |
| `bindsnoop.bpf.o` | 4 | 0 | 0 | 有 `CGROUP_ARRAY`/`PERF_EVENT_ARRAY` 定义，但无 lookup |
| `biolatency.bpf.o` | 3 | 0 | 0 | 有 `CGROUP_ARRAY` 定义，但无 lookup |
| `biopattern.bpf.o` | 1 | 0 | 2 | 两个 HASH lookup，key 都是动态 |
| `biosnoop.bpf.o` | 4 | 0 | 6 | 六个 HASH lookup，key 都是动态 |
| `biostacks.bpf.o` | 2 | 0 | 7 | 七个 HASH lookup，key 都是动态 |
| `biotop.bpf.o` | 3 | 0 | 12 | 十二个 HASH lookup，key 都是动态 |
| `bitesize.bpf.o` | 1 | 0 | 0 | 无 lookup |
| `cachestat.bpf.o` | 0 | 0 | 0 | 无 `.maps` |
| `capable.bpf.o` | 6 | 0 | 2 | 两个 HASH lookup，key 都是动态 |

前 10 个对象里，没有一个真实的 `ARRAY/PERCPU_ARRAY` lookup site。能看到一些名字里带 `*_ARRAY` 的 map，比如 `CGROUP_ARRAY`、`PERF_EVENT_ARRAY`，但它们不是这次关心的“普通 ARRAY/PERCPU_ARRAY + constant key lookup”。

## 2. 全部 BCC libbpf-tools corpus 的统计

离线统计结果：

```json
{
  "file_count": 57,
  "overall": {
    "lookup_total": 203,
    "lookup_dynamic_key": 196,
    "array_lookup_total": 5,
    "array_lookup_dynamic_key": 5,
    "lookup_constant_key": 7,
    "lookup_constant_key_zero": 7
  },
  "array_lookup_use": {
    "other_use_only": 5
  },
  "key_patterns": {
    "stack_store_const_reg+non_simple_r2_setup": 3,
    "stack_store_const_reg+simple_r2_fp_plus_imm": 4
  }
}
```

关键点：

- 总 lookup site：203
- 动态 key：196
- 常量 key：7
- 常量 key 全部都是 key=0
- 真正的 `ARRAY/PERCPU_ARRAY` lookup site：5
- 这 5 个站点在旧逻辑下全都被判成“动态 key”
- 这 5 个站点的返回值用途全是 `other_use_only`

也就是说：

- corpus 里“常量 key”确实存在，但它们全都不是 ARRAY/PERCPU_ARRAY；
- corpus 里“ARRAY/PERCPU_ARRAY lookup”也确实存在，但它们全都不是旧逻辑能识别的栈上 key 模式。

## 3. 真实 ARRAY/PERCPU_ARRAY site 在哪里

整个 `bcc/libbpf-tools` 里只有这 5 个真实站点：

| 文件 | section | map | 旧逻辑看到的 key | use pattern |
|---|---|---|---|---|
| `filelife.bpf.o` | `kretprobe/vfs_unlink` | `heap:PERCPU_ARRAY` | dynamic | `other_use_only` |
| `oomkill.bpf.o` | `kprobe/oom_kill_process` | `heap:PERCPU_ARRAY` | dynamic | `other_use_only` |
| `opensnoop.bpf.o` | `tracepoint/syscalls/sys_exit_open` | `heap:PERCPU_ARRAY` | dynamic | `other_use_only` |
| `opensnoop.bpf.o` | `tracepoint/syscalls/sys_exit_openat` | `heap:PERCPU_ARRAY` | dynamic | `other_use_only` |
| `opensnoop.bpf.o` | `tracepoint/syscalls/sys_exit_openat2` | `heap:PERCPU_ARRAY` | dynamic | `other_use_only` |

旧逻辑失败原因统一是：

```text
register does not resolve to fp-relative stack memory
```

这已经说明它们不是 `fp-4` 栈槽 key。

## 4. 真实 bytecode pattern 是什么

`opensnoop.bpf.o` 的三个 `heap` site 都是同一模式。关键片段如下：

```asm
29: r1 = 0x0 ll                ; R_BPF_64_64  heap
31: r2 = 0x10 ll               ; R_BPF_64_64  .rodata
33: call 0x1                   ; bpf_map_lookup_elem
34: r9 = r0
...
39: *(u32 *)(r9 + 0x8) = r0
41: *(u32 *)(r9 + 0xc) = r0
```

这里的语义不是：

```asm
*(u32 *)(r10 - 4) = 0
r2 = r10
r2 += -4
call bpf_map_lookup_elem
```

而是：

- `r1` 指向 `heap` map
- `r2` 是一个 `BPF_PSEUDO_MAP_VALUE` 形式的 `.rodata + offset`
- helper 从 `.rodata` 里取 key

这正是旧版 `try_extract_constant_key()` 完全看不到的模式。

## 5. `try_extract_constant_key()` 旧能力边界

从 `daemon/src/passes/map_inline.rs` 看，旧逻辑本质上是“回溯到 `r2` 指向的栈槽，然后找常量 store”：

- 支持 `*(u32 *)(fp-off) = imm`
- 支持 `mov reg, imm` 再 `stx *(fp-off) = reg`
- 支持简单的 `r2 = fp + const`
- 支持一些寄存器 copy / 常量 ALU 回溯

它可以处理典型 clang 生成的栈上 key=0 模式，例如：

```asm
r3 = 0
*(u32 *)(r10 - 4) = r3
r2 = r10
r2 += -4
call bpf_map_lookup_elem
```

这点也被 corpus 里的 7 个常量 key site 印证了：它们全都已经是“stack store const reg + r2 setup”的家族，只是都落在 HASH map 上，不是 ARRAY/PERCPU_ARRAY。

旧逻辑不能处理的是：

```asm
r2 = ldimm64(BPF_PSEUDO_MAP_VALUE, old_fd=.rodata, off=const)
call bpf_map_lookup_elem
```

阻塞点有两个：

1. `resolve_stack_pointer_to_stack*()` 只接受 FP-relative stack pointer。
2. `try_extract_constant_key()` 只会去找 stack store，不会去读 pseudo-map-value 指向的 frozen source map。

## 6. `const_prop` 是否应该跑在 `map_inline` 前面

当前默认 pipeline 顺序仍然是：

```text
map_inline -> const_prop -> dce -> ...
```

定义在 `daemon/src/passes/mod.rs`，`PassManager::run()` 里会把 `const_prop + dce` 当成固定点对执行，但它们仍然是在 `map_inline` 之后才开始。

对当前 corpus 来说，把 `const_prop` 提前并不能解决主要 miss，原因是：

1. BCC 里真实的 ARRAY/PERCPU_ARRAY miss 不是“算出来但还没 fold 的 key”，而是 `.rodata` pseudo-map-value key。
2. 典型的栈上 `key = 0` pattern 当前 `map_inline` 本来就能识别，不需要先跑 `const_prop`。
3. 这 5 个 ARRAY/PERCPU_ARRAY site 即使 key 提取成功，仍然会因为 `other_use_only` 被 use-pattern gate 拒绝。

所以：

- `const_prop` 前置不是当前 corpus 的关键修复；
- 真正有价值的是让 `map_inline` 自己理解 `BPF_PSEUDO_MAP_VALUE` key。

## 7. 这次修复

### 7.1 `map_inline` 修复

已在 `daemon/src/passes/map_inline.rs` 增加 pseudo-map-value constant key 支持：

- 新增 `KeyPointerOrigin::{Stack, MapValue}`
- 新增 `resolve_key_pointer_origin*()`，允许 key pointer 解析到：
  - FP-relative stack
  - `BPF_PSEUDO_MAP_VALUE`
- 支持在这两类 origin 之上继续回溯 `MOV/ADD/SUB`
- 新增 `try_extract_constant_key_from_map_value()`
  - 通过 `program.map_fd_bindings` 把 old fd 映射到 map id
  - 要求 source map frozen
  - 从 source map key=0 的 value 中切出 `[value_off, value_off + key_size)` 作为常量 key

对应新增单测覆盖：

- `map_inline_pass_rewrites_array_lookup_with_pseudo_map_value_zero_key`

### 7.2 测试/验证相关修正

为了让全量测试稳定通过，还顺手做了两个小修正：

- 旧测试里把 skip reason 文案写死为 `constant stack materialization`，现在更新为覆盖 pseudo-map-value 的新文案。
- `verifier_log` 里修了一个已有 bug：`fp-56` 之前会被误拆成 slot-type 前缀 `f` 和 reg-state `p-56`。

## 8. 修复后的影响评估

### 8.1 识别能力

修复后，当前 corpus 里原本 miss 掉的 5 个 `ARRAY/PERCPU_ARRAY + constant key` site，key 都可以被正确识别为常量来源于 pseudo-map-value。

### 8.2 真正能 inline 的 site

当前 BCC libbpf-tools corpus 里，这 5 个 site 的 use pattern 全是：

```text
other_use_only
```

它们的返回值被当成可写 scratch/event buffer 指针使用，而不是：

- `ldx *(r0 + const)` 这种固定 offset 的只读 scalar load

因此按 v1 的当前规则，这 5 个 site 仍然不会被 inline。

最终影响评估：

- 新增“constant key 可识别”的 ARRAY/PERCPU_ARRAY site：5
- 新增“满足当前 v1 inline 条件”的 site：0

## 9. 对用户最初假设的回应

### 假设 A：`try_extract_constant_key()` 没处理 clang 的 `key=0`

只对一部分场景成立。

- 对栈上 `key=0`，旧逻辑基本已经能处理。
- 对 `.rodata` pseudo-map-value 形式的 `key=0`，旧逻辑确实处理不了。

当前 BCC corpus 的真实 miss 属于后者，不是前者。

### 假设 B：`const_prop` 应该在 `map_inline` 前面

对当前 corpus 不成立。

- 这不是主要瓶颈。
- 真实瓶颈是 pseudo-map-value key extraction。

## 10. 验证

执行过的验证：

```bash
cargo test --manifest-path daemon/Cargo.toml map_inline -- --nocapture
make daemon-tests
```

结果：

- `map_inline` 相关测试通过
- `make daemon-tests` 通过（等价执行 `cargo test --manifest-path daemon/Cargo.toml`）

