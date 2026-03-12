# llvmbpf Array Map Lookup Inline POC

Date: March 11, 2026

## 结论摘要

- `llvmbpf` 当前对 `bpf_map_lookup_elem` 的处理是普通 external helper call，不做 map-type-specific inline。helper 注册入口在 `vendor/llvmbpf/include/llvmbpf.hpp:50-57`、`vendor/llvmbpf/src/vm.cpp:85-99`，JIT 符号注册在 `vendor/llvmbpf/src/llvm_jit_context.cpp:615-656`。
- helper call 的 LLVM IR 生成点在 `vendor/llvmbpf/src/compiler.cpp:1058-1122`，真正的 `CreateCall(...)` 在 `vendor/llvmbpf/src/compiler_utils.cpp:312-349`。
- `llvmbpf` 现有 API 能在 JIT 时知道 map handle，以及 direct map/global access 所需的 `map_val()` 基址，但不知道 helper-based map lookup 需要的 `map type / max_entries / stride`。这正是不能直接仿 kernel `array_map_gen_lookup()` 的关键缺口。
- Linux kernel 的做法是 verifier/JIT 前重写 helper：如果 helper 是 `BPF_FUNC_map_lookup_elem` 且 `map->ops->map_gen_lookup` 存在，则直接把 helper call patch 成 map-specific BPF 指令。array map 的实现见 `vendor/linux-framework/kernel/bpf/arraymap.c:219-249`，触发点见 `vendor/linux-framework/kernel/bpf/verifier.c:23876-23910`。
- 因此，结论是：
  - 只靠 llvmbpf 现有 public API，helper-based array lookup inline 不足以落地。
  - 只要 embedding runtime 在 compile 前额外把 array map 元数据传给 llvmbpf，这个优化就是可行的。
- 本次 POC 采用了一个最小可工作的方案：
  - 新增可选 API `register_array_map(...)`
  - 在第一次 LLVM 优化后、ORC JIT addIRModule 前，扫描 `_bpf_helper_ext_0001`
  - 当 call 的第一个参数已经被 LLVM 常量传播成常量 map handle，且该 handle 已注册为 array map 时，把 helper call 改写成：
    - `index = *(u32 *)key_ptr`
    - `index < max_entries ? value_base + index * value_stride : 0`
  - 否则保持原 helper call 不变

## 0. 读到的相关文件

- 已读：
  - `docs/tmp/llvmbpf-map-and-parallel-analysis.md`
  - `vendor/llvmbpf/src/llvm_jit_context.cpp`
  - `vendor/llvmbpf/include/llvmbpf.hpp`
  - `vendor/llvmbpf/src/*`
  - `vendor/llvmbpf/example/maps.cpp`
  - `vendor/linux-framework/kernel/bpf/arraymap.c`
  - `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/llvmbpf/src/llvm_bpf_jit.cpp` 在当前 tree 里不存在。

## 1. Part 1: 当前 llvmbpf 是怎么做的

### 1.1 helper 是如何注册的

- public API 是 `llvmbpf_vm::register_external_function()`，定义在 `vendor/llvmbpf/include/llvmbpf.hpp:50-57`，实现见 `vendor/llvmbpf/src/vm.cpp:85-99`。
- VM 内部把 helper 存在 `ext_funcs` 里，JIT 初始化时再把这些函数注册成 ORC absolute symbols，见 `vendor/llvmbpf/src/llvm_jit_context.cpp:615-656`。
- helper 符号名不是用用户传入的字符串直接调用，而是统一映射成 `_bpf_helper_ext_%04u`，符号名生成函数在 `vendor/llvmbpf/src/compiler_utils.hpp:39-43`。

### 1.2 LLVM IR 里 helper call 在哪里发出来

- `generateModule()` 先为所有 external helpers 创建统一签名：
  - `i64 (i64, i64, i64, i64, i64)`，见 `vendor/llvmbpf/src/compiler.cpp:132-147`
- 指令 lowering 遇到 `EBPF_OP_CALL` 时：
  - local call 走自己的 call stack 逻辑
  - external helper call 走 `emitExtFuncCall(...)`
  - 见 `vendor/llvmbpf/src/compiler.cpp:1058-1122`
- `emitExtFuncCall(...)` 会直接：
  - 读取 `r1..r5`
  - 发一个 `builder.CreateCall(helperFuncTy, ...)`
  - 把结果写回 `r0`
  - 见 `vendor/llvmbpf/src/compiler_utils.cpp:312-349`

结论：当前 helper 1 (`bpf_map_lookup_elem`) 完全没有 special-case。

### 1.3 有没有 hook point 可以把 array map lookup inline 掉

有两个理论位置：

1. 原始 eBPF lowering 阶段
   - 在 `compiler.cpp` 的 `EBPF_OP_CALL` 分支里拦截 helper 1
   - 问题是这时 `r1` 只是从 alloca load 出来的普通 LLVM value，很难稳妥判断它是不是 compile-time constant map handle，尤其跨 basic block/phi 时更麻烦

2. LLVM 常量传播之后
   - 先跑一轮优化，让 `r1` 这种“由 pseudo-LDDW 载入的 map handle”尽可能被折叠成常量
   - 再扫描 `_bpf_helper_ext_0001` 的 call site
   - 如果 `arg0` 已经是 `ConstantInt`，就能安全判断“这是某个固定 map 的 lookup”

本次 POC 选了第 2 条路。对应实现：

- hook 本身在 `vendor/llvmbpf/src/llvm_jit_context.cpp:305-402`
- 接入 JIT pipeline 在 `vendor/llvmbpf/src/llvm_jit_context.cpp:427-453`

这不是用户描述里“在原始 `BPF_CALL` lowering 时直接拦截”的最字面实现，但工程上更稳妥，因为它复用了 LLVM 自己的常量传播，而不是在 llvmbpf 里重写一套寄存器数据流分析。

### 1.4 llvmbpf 在 JIT 时到底知道哪些 map 信息

#### 现有 llvmbpf 已经知道的

- helper 的 numeric id
- pseudo-LDDW map handle
  - `inst.src == 1` 时，`map_by_fd()` 在 compile time 被求值；如果没提供，就直接把 `imm` 当 map handle
  - 见 `vendor/llvmbpf/src/compiler.cpp:845-862`
- direct map/global access 的 value base
  - `inst.src == 2` / `6` 时，JIT 模式默认 `patch_map_val_at_compile_time=true`
  - 会直接调用 `vm.map_val(...)` 把基址常量写进 IR
  - 见 `vendor/llvmbpf/src/compiler.cpp:864-920` 与 `970-1030`
- JIT 路径只保留 `map_val` runtime symbol 的机会，其他 LDDW helpers 视为 compile-time relocation
  - 见 `vendor/llvmbpf/src/llvm_jit_context.cpp:576-582`、`632-640`

#### 现有 llvmbpf 不知道的

- map type
- key size
- value size / stride
- max entries

这些信息在 benchmark loader 里其实是有的：

- `micro/runner/include/micro_exec.hpp:12-18` 的 `map_spec`
- `micro/runner/src/elf_program_loader.cpp:656-667` 会从 ELF/libbpf 提取 `type/key_size/value_size/max_entries`

但这些元数据没有传进 llvmbpf core。

### 1.5 kernel 是怎么做的

Kernel array map 的普通 C 语义：

- `array_map_lookup_elem()`:
  - `u32 index = *(u32 *)key`
  - 越界返回 `NULL`
  - 否则返回 `array->value + elem_size * (index & index_mask)`
  - 见 `vendor/linux-framework/kernel/bpf/arraymap.c:167-176`

Kernel 的 inline 版本：

- `array_map_gen_lookup()` 直接发 BPF 指令：
  - `map_ptr += offsetof(struct bpf_array, value)`
  - `ret = *(u32 *)key`
  - bounds check
  - `ret <<= ilog2(elem_size)` 或 `ret *= elem_size`
  - `ret += map_ptr`
  - 越界则 `ret = 0`
  - 见 `vendor/linux-framework/kernel/bpf/arraymap.c:219-249`

触发机制：

- verifier/JIT patch 阶段，如果 helper 是 `BPF_FUNC_map_lookup_elem`
- 且 `ops->map_gen_lookup` 存在
- 直接用 `ops->map_gen_lookup(map_ptr, insn_buf)` 生成替代指令
- 见 `vendor/linux-framework/kernel/bpf/verifier.c:23876-23910`

这和 llvmbpf 的本质差别是：

- kernel verifier 已经知道 `aux->map_ptr_state.map_ptr`
- 所以 helper 调用点对应的是一个确定的 `struct bpf_map *`
- 而 llvmbpf 只有“helper arg0 是个 opaque integer/handle”，缺少 map 元数据

## 2. Part 2: Feasibility 评估

### 2.1 llvmbpf 能在 JIT compile time 知道 map type 吗

- 现状：不能。
- 现有 API 没有任何 `map type / max_entries / value_size` 输入路径。
- 只靠 `map_by_fd()` / `map_val()` 不够，因为它们最多告诉 llvmbpf “handle 是多少”和“value area 基址是多少”。

结论：

- “不改 API，只改 llvmbpf 内核” 对 helper-based array lookup inline 不够。
- “加一个很小的元数据注册 API” 则完全可行。

### 2.2 llvmbpf 能在 JIT compile time 知道 value array base address 吗

- 能，但要满足下列之一：
  - host 直接注册 `value_base`
  - 或者 host 提供 `map_val(handle)`，且 handle 在 helper call 处是常量

本次 POC 两种都支持：

- `array_map_descriptor.value_base`
- 如果 `value_base == 0` 且 `vm.map_val` 存在，则 fallback 到 `vm.map_val(map_handle)`，见 `vendor/llvmbpf/src/llvm_jit_context.cpp:354-357`

### 2.3 最小改动应该是什么

严格看，“最小能工作的改动”不是只拦 `helper_id=1`，还必须加一条元数据输入路径。

本次 POC 的最小改动集是：

1. 新增 `array_map_descriptor` + `register_array_map()`
   - `vendor/llvmbpf/include/llvmbpf.hpp:29-36`
   - `vendor/llvmbpf/include/llvmbpf.hpp:55-57`
   - `vendor/llvmbpf/src/vm.cpp:101-127`
2. 在 JIT pipeline 增加 helper-1 call-site rewrite
   - `vendor/llvmbpf/src/llvm_jit_context.cpp:305-402`
3. 仅在以下条件成立时 inline：
   - helper 是 `_bpf_helper_ext_0001`
   - 第一个参数已经被 LLVM 折叠成常量 handle
   - 该 handle 有已注册的 array descriptor
   - `key_size == 4`
   - `max_entries != 0`
   - `value_stride/value_size != 0`
   - `value_base` 可解析
4. 否则 fallback 到当前 external call，不影响旧行为

### 2.4 LOC / complexity 估计

- core llvmbpf POC 改动量：
  - API + VM storage
  - 一个 JIT-time IR rewrite
  - 两个 unit tests
- 从本次实际 diff 看：
  - core + tests 约 260+ inserted lines
  - benchmark example 另加 182 行
- 复杂度：中等，不算高。

复杂度主要不在地址计算，而在“什么时候能可靠地证明 map handle 是常量”。这也是为什么后置到 LLVM 常量传播之后实现比在原始 lowering 阶段更合理。

### 2.5 安全性与语义风险

已处理：

- 越界返回 `0`/`NULL`
- 只对 `key_size == 4` 的 array map 生效
- map 未注册、元数据不完整、base 无法解析时全部 fallback
- helper 1 以外不动

仍需注意：

- 这是 JIT-only POC，AOT/object path 没接入
- `value_base` 被 bake 进 JIT 后，host 必须保证 backing storage 在 jitted code 生命周期内稳定
- 目前只支持“常量 map handle”的 call site
- 目前没有接 `percpu array / array-of-maps / hash map`
- stride 用的是 host 注册值，不是 kernel 的 `round_up(value_size, 8)` 规则
  - 这是故意的，因为 llvmbpf embedding runtime 可能不是 kernel 内存布局

## 3. Part 3: POC 实现

### 3.1 改动内容

#### 新增 array map registry

- `vendor/llvmbpf/include/llvmbpf.hpp:29-36`
- `vendor/llvmbpf/include/llvmbpf.hpp:55-57`
- `vendor/llvmbpf/src/vm.cpp:101-127`

含义：

- host 在 compile 前把“helper arg0 对应的 map handle”注册成 array map
- descriptor 里包含：
  - `map_handle`
  - `value_base`
  - `key_size`
  - `value_size`
  - `value_stride`
  - `max_entries`

#### 新增 JIT-time helper rewrite

- `vendor/llvmbpf/src/llvm_jit_context.cpp:305-402`

逻辑：

- 找到 `_bpf_helper_ext_0001`
- 扫所有 call site
- 如果 `arg0` 是 `ConstantInt` 且 descriptor 匹配：
  - `key = *(u32 *)arg1`
  - `in_range = key < max_entries`
  - `offset = key * stride`，power-of-two stride 用 shift
  - `addr = value_base + offset`
  - `result = select(in_range, addr, 0)`
  - 替换 helper call

#### 接入 JIT pipeline

- `vendor/llvmbpf/src/llvm_jit_context.cpp:427-453`

流程：

1. 先跑一轮 LLVM optimize
2. 执行 array helper rewrite
3. 如果发生替换，再跑一轮 optimize

### 3.2 测试

新增 unit tests：

- fallback path: `vendor/llvmbpf/test/unit-test/vm_test.cpp:417-434`
  - 没注册 array map descriptor
  - helper 调用次数应为 1
- inline path: `vendor/llvmbpf/test/unit-test/vm_test.cpp:436-461`
  - 注册 descriptor 后
  - helper 调用次数应为 0

### 3.3 Benchmark

新增 benchmark example：

- `vendor/llvmbpf/example/array_map_inline_bench.cpp:98-181`
- `vendor/llvmbpf/example/CMakeLists.txt:14-20`

这个 benchmark 的目的不是模拟整个 micro framework，而是把变量尽量收窄：

- 同一段 bytecode
- 同一个 helper 实现
- 同一个 map backing
- 唯一差异是：是否调用 `register_array_map(...)`

## 4. Part 4: 构建、验证、性能

### 4.1 构建

按要求构建：

```sh
cd vendor/llvmbpf
mkdir -p build
cd build
cmake ..
make -j$(nproc)
```

结果：成功，`maps-example` 与新增 `array-map-inline-bench` 都编译通过。

额外验证：

```sh
mkdir -p vendor/llvmbpf/build-tests
cd vendor/llvmbpf/build-tests
cmake .. -DBPFTIME_ENABLE_UNIT_TESTING=ON
make -j$(nproc) llvm_jit_tests
./test/unit-test/llvm_jit_tests
```

结果：

- `All tests passed (78 assertions in 13 test cases)`

### 4.2 benchmark 命令

```sh
cd vendor/llvmbpf/build
./array-map-inline-bench 10000000
./array-map-inline-bench --inline 10000000
```

### 4.3 benchmark 结果

原始结果：

- baseline #1: `7.46960 ns/iter`, helper calls `10000000`
- baseline #2: `7.48114 ns/iter`, helper calls `10000000`
- baseline #3: `7.58090 ns/iter`, helper calls `10000000`
- inline #1: `5.83939 ns/iter`, helper calls `0`
- inline #2: `5.60865 ns/iter`, helper calls `0`
- inline #3: `5.87614 ns/iter`, helper calls `0`

平均值：

- baseline avg: `7.51055 ns/iter`
- inline avg: `5.77473 ns/iter`
- speedup: `1.3006x`
- reduction: `23.11%`

### 4.4 如何解读

- 这个 benchmark 已经证明：
  - helper call 本身的开销在 llvmbpf JIT 下是可见的
  - 一旦把 array lookup 变成直接地址计算，helper 调用完全消失
  - 即便只是一个很小的例子，仍然能拿到约 `23%` 的单次执行时间下降

## 5. 限制与后续建议

### 5.1 当前 POC 的限制

- 只支持 JIT path，不支持 AOT path
- 只支持 helper 1 (`bpf_map_lookup_elem`)
- 只支持已注册的 array map
- 只支持 `key_size == 4`
- 只支持 compile-time constant map handle 的 call site
- 只支持 host 保证 `value_base` 生命周期稳定

### 5.2 为什么没有直接复用 archived runtime benchmark

仓库里确实有：

- `micro/programs/archive/runtime/map_lookup_repeat.bpf.c`

但当前 `micro/runner/src/llvmbpf_runner.cpp` 只注册了 helper，没有把 `image.maps` 里的 map metadata 传进 llvmbpf，所以现有 runner 还不知道哪些 helper lookup 可以 inline。

也就是说：

- llvmbpf core POC 已经可用
- 但如果要让 archived runtime benchmark 自动吃到这个优化，还需要额外一小步 glue code：
  - 在 `micro/runner/src/llvmbpf_runner.cpp` 初始化 `map_state` 后
  - 对每个 `BPF_MAP_TYPE_ARRAY` map 调用 `vm.register_array_map(...)`
  - `map_handle` 用当前 runner 的 map id
  - `value_base` 用 `map.storage.data()`
  - `value_stride` 用当前 userspace runtime 的实际布局

这一步我这次没有改，因为用户要求如果提交代码，提交到 `vendor/llvmbpf`；我把 POC 保持在 llvmbpf 子树内。

### 5.3 如果要做成更完整的 upstream 版本

建议下一步：

1. 把 `register_array_map()` 扩展成更通用的 `register_map_descriptor()`
2. 在 embedding runtime 里自动把 ELF/libbpf map metadata 注入 llvmbpf
3. 对 percpu array / array-of-maps 分别建专门路径
4. 如果要覆盖更多程序形态，再考虑把 rewrite 做成正式 LLVM pass，而不是当前的 JIT hook
5. 若要兼顾 AOT，则需要额外设计“可重定位 map base”表示，而不是把绝对地址 bake 进 object

## 最终判断

`llvmbpf inline array map lookup` 是可行的，但前提不是“llvmbpf 靠自己猜出 map type”，而是“embedding runtime 必须把 array map metadata 显式给到 llvmbpf”。

在这个前提下，最小可工作的方案已经通过本次 POC 证明：

- 语义正确
- fallback 安全
- helper 调用确实被消除
- 在简化 benchmark 上拿到了 `1.3006x` 的速度提升
