# map_inline 多条目枚举 + uniform 消除 + LLVM 多版本兼容(2026-05-21)

## 1. map_inline:单条目 guard → 多条目枚举 + uniform 消除(LLVM bpfopt)
统一成一个 guard-chain 机制(`build_guard_chain_block`),splice 在 `map_lookup_elem`
call 之前:
```
entry i: r3 = *(u32)(r10+key_off+4c); if r3 != Ki_c goto <下一 entry / SLOW>
         <materialize Vi; r0 = &Vi>; goto OVER_CALL
SLOW:    <原 call>          ; 任何未列出的 key / miss 走真 lookup
OVER_CALL:<原 null 检查>
```
- **多条目枚举**(`1..MAX_ENUM=4` 个精确快照条目):对每个 key 发一段 compare,命中用常量、
  否则跳下一条,全不命中 → SLOW(真 lookup)。**sound**:未枚举的 key / miss 都走真 lookup。
- **uniform 消除**(`truly_uniform` 的 map):发一个**无 compare** 的 entry(空 key)→
  无条件 `r0=&V` + 跳过 call → call 变死代码 → O3 消除整个 lookup。假设 in-range presence
  + 值稳定(对 bounded-index ARRAY 如一致性哈希环 sound)。
- **const key** 自动归入「精确条目枚举」(O3 把恒真 guard 折掉 → lookup 消除)。
- gate:跳过 data-path-mutable map(update/delete/push/pop)、value 指针被写穿/拷出/存内存的
  site、非普通值类型。r3 是 scratch(r1-r5 调用约定下视为 clobbered,fast path 跳过 call,
  覆盖 r3 安全)。
- 删掉了被取代的 `derive_const_lookup_key` / `lookup_snapshot_value`(dead)。

### katran 验证(kinsn LLVM-23,带 overlays)
**6 个 site 折叠,sound**:
- vip_map ×2(枚举 guard,1 条目)
- ch_rings ×2(uniform 消除)
- server_id_map ×2(uniform 消除)
- 优化后 **retval 2 == baseline 2**(完全一致;cargo test 只因断言硬编码 ==XDP_TX(3) 而
  "失败",而 faithful 行为本就是 2)。insn 2542 → 2600。
- reals 未折(其 lookup 的 key 设置不匹配 `r2=r10+off` 模式 / find_key_stack_off 失败 → skip,
  安全)。

### 性能说明
katran 这个 benchmark 包 retval=2(不转发),ch_rings/server_id/reals 在转发决策更深处,
**这个包根本没执行到那些 lookup** → 消除它们对该包运行时≈0。要看真实收益需要一个**会转发的
包**(走到 ch_rings→reals 链)。机制本身正确 + sound;收益取决于 workload 是否触达被折的 map。

## 2. LLVM 多版本兼容(llvmbpf)
`make corpus` 默认用**仓库的 kinsn LLVM-23**(`runner/mk/build.mk:14`
`DEFAULT_RUNNER_LLVM_DIR = llvm-backend/build-bpf-kinsn`);ARM64 corpus 目前用
`arm64-llvm15` sysroot(`build.mk:18`)。LLVM 21 起 `lookupTarget`/`createTargetMachine`/
`setTargetTriple` 从收 `std::string` triple 改成收 `llvm::Triple`。

在 `vendor/llvmbpf/src/llvm_jit_context.cpp` 加了版本宏:
```cpp
#if LLVM_VERSION_MAJOR >= 21
#define BPFTIME_TRIPLE_ARG(t) (t)
#else
#define BPFTIME_TRIPLE_ARG(t) ((t).str())
#endif
```
5 处调用点改用该宏 → **同一份代码在 LLVM-15(arm64).str() 和 LLVM-23(x86)Triple 下都能编译**。
- x86 kinsn LLVM-23:已实测 `build-kinsn` 编译干净(EXIT 0)。
- arm64 LLVM-15:宏走 `.str()` 分支,语法正确(未在 arm64 实测,无 arm64 LLVM 环境)。

### 仍待办:arm64 真正用「仓库 LLVM-23」
要让 ARM64 corpus 也用我们改过的 LLVM-23(而非 llvm-15),需要**为 arm64 交叉构建 kinsn
LLVM-23**(目前 `llvm-backend/` 只有 x86 的 `build-bpf-kinsn`),再把 `build.mk:18` 的
`ARM64_RUNNER_LLVM_DIR` 指过去。这是一次重的 LLVM 交叉编译(数小时),且当前 arm64 sysroot
是按 llvm-15 装的。**版本宏已保证 arm64 即便留在 LLVM-15 也能编译**;切到 LLVM-23 是独立的
基础设施任务。

## 状态
- map_inline 多条目枚举 + uniform 消除:✅ 实现 + sound + kinsn 编译通过。
- llvmbpf LLVM 多版本兼容宏:✅ x86-23 编译通过,arm64-15 语法兼容。
- arm64 用仓库 LLVM-23:⏳ 需交叉构建 arm64 kinsn LLVM(重)。
- 所有改动未 commit。
