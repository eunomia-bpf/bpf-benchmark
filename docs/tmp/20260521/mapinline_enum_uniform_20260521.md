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

### 性能说明 + proto 修复(2026-05-21 追加)
之前 host TEST_RUN 包 retval=2(不转发)的根因:`populate_katran_maps` 把 VIP 注册成
**proto 17(UDP)**,而测试包是 **TCP(6)** → vip_map miss → 不转发 → 折的 map 没执行到。
（corpus 真实 workload 是 `xdp_traffic`:wrk 打真 HTTP/TCP,VIP 用 TCP_PROTO;只有合成
`xdp_pktgen` 才用 UDP。loader 合成包是 TCP,所以 populate 也该是 TCP。）

**修复**:`bpfopt/loader/src/main.rs` `populate_katran_maps` `vip[18] = 17` → `6`(TCP)。
修复后:
- katran cargo test **通过**:优化后 retval **3(XDP_TX)**、data_size_out **84(IPIP 封装)**,
  `assert_katran_forwarding_output` 满足 → **6-site 折叠现在落在执行的转发路径上且正确**。
- **性能(repeat=10000,转发路径,ns/run)**:baseline ~104 vs fold ~102 → **~0-2%,噪声内**。

结论:即便正确转发、折叠在热路径上,katran 的 map 查找**不是每包瓶颈**(瓶颈在解析 +
IPIP 封装 + 校验和),所以 soft 折叠 ≈ 0%。之前传说的「~17%」其实是
**noop(O0) baseline + hard-fold 强制转发** 的叠加假象,对比真正的 original baseline 并不存在。
soft fold 机制正确 + sound;katran 上收益微小是因为查找非瓶颈。

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

### arm64 也切到「仓库 LLVM-23」✅(已完成)
在 host 上**交叉编译**(aarch64-linux-gnu 工具链 + 复用 x86 `llvm-tblgen`,非 qemu)了
arm64 版的 kinsn LLVM-23 → `llvm-backend/build-bpf-kinsn-arm64`:
```
cmake -S llvm-backend/llvm/llvm -B llvm-backend/build-bpf-kinsn-arm64 -G Ninja \
  -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_RTTI=OFF -DLLVM_ENABLE_ASSERTIONS=OFF \
  -DBUILD_SHARED_LIBS=OFF -DLLVM_BUILD_TOOLS=OFF -DLLVM_TARGETS_TO_BUILD="AArch64;BPF" \
  -DLLVM_ENABLE_ZSTD=OFF -DLLVM_ENABLE_ZLIB=OFF \
  -DCMAKE_SYSTEM_NAME=Linux -DCMAKE_SYSTEM_PROCESSOR=aarch64 \
  -DCMAKE_C_COMPILER=aarch64-linux-gnu-gcc -DCMAKE_CXX_COMPILER=aarch64-linux-gnu-g++ \
  -DCMAKE_SYSROOT=.cache/aarch64-sysroot -DCMAKE_FIND_ROOT_PATH=.cache/aarch64-sysroot \
  -DLLVM_HOST_TRIPLE=aarch64-unknown-linux-gnu \
  -DLLVM_TABLEGEN=<x86>/build-bpf-kinsn/bin/llvm-tblgen \
  -DLLVM_NATIVE_TOOL_DIR=<x86>/build-bpf-kinsn/bin
```
- 产物:`LLVM_PACKAGE_VERSION 23.0.0git`,`AArch64;BPF`,libs 是 ARM aarch64 ELF。约 7 分钟。
- `runner/mk/build.mk:18` `ARM64_RUNNER_LLVM_DIR` 已从 `arm64-llvm15` 改到
  `build-bpf-kinsn-arm64/lib/cmake/llvm`。
- **验证**:arm64 runner cmake configure 干净 + `micro_exec` 编译并**链接** arm64 LLVM-23
  通过 → 产出 ARM aarch64 ELF(75 MB)。即 **arm/x86 两边的 corpus 现在都链接仓库改过的
  LLVM-23**。

## 状态
- map_inline 多条目枚举 + uniform 消除:✅ 实现 + sound + kinsn 编译通过。
- llvmbpf LLVM 多版本兼容宏:✅ x86-23 编译通过,arm64-15 语法兼容。
- arm64 用仓库 LLVM-23:⏳ 需交叉构建 arm64 kinsn LLVM(重)。
- 所有改动未 commit。
