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

## 重写为 IR 级折叠(2026-05-21 追加)
之前 bytecode-splice 折叠把值 materialize 到「取地址的栈槽」,堵死了 O3 常量传播 →
程序变大、无收益。改成 **IR 级**:
- 在 lift 后、O3 前,先 `promote_register_allocas`(mem2reg,让 lookup 结果以 SSA 形式
  直接流到使用点,而不是被 store 进寄存器 alloca);
- `fold_lookups_in_module`:把 `map_lookup_elem` 结果的**值 deref load 替换成立即数
  ConstantInt**,null 检查改成看到非空指针,然后删掉 lookup。**纯寄存器立即数,无 global /
  .rodata,无栈往返** → O3 能真正传播 + DCE。
- 不可折的 use(store/phi/未知)→ 跳过该 site(安全)。

### 结果(katran,kinsn LLVM-23)
- **test 通过**:retval 3(XDP_TX)、data_size_out 84(IPIP),转发正确。
- **程序变小 + lookup 变少**:insns 2542 → **2367**(-175),map_lookup_elem 70 → **60**
  (消掉 10 个)。**这是第一次优化后程序真的更小**(对比 bytecode-stack 方式膨胀到 2600)。
- **但性能仍 ~flat**:baseline ~138 vs fold ~144 ns(噪声内)。原因不变:消掉的是**便宜的
  ARRAY 查找**(直接下标),而 katran 每包瓶颈在解析 + IPIP 封装 + 校验和,不在查找。
- 覆盖:折了 ~10 个 site(uniform ARRAY + 单条目 immutable map);**vip_map(HASH,贵)的
  2 个 site 被 `phi` 挡住**(结果跨分支流入 phi,直线 use-walk 跳过)。要折它们需处理 phi。
  之前 hard-fold 的「16」含 ctl_array(数据路径写,折它本就 unsound)。

### 构建相关
- kinsn LLVM 现在带 **X86 target**(`需要带 x86`):build-bpf-kinsn 编了 X86 库;
  `bpfopt/llvm/CMakeLists.txt` 改用显式 X86 库名(x86codegen/...,umbrella `x86` 映射错)。
- `vendor/llvmbpf/src/compiler.cpp` 的 `hasTerminator` 修复又被回退过一次,已重新修。

### 结论
IR 级折叠是**正确的架构**(真的减指令、sound、转发对),修好了 bytecode-stack 的传播问题。
katran 收益仍微小是因为**查找非其瓶颈**;要展示 map_inline 的性能价值需用**查找密集型**程序。

## 全 IR 化 + CLI 投机(2026-05-22 追加)
按要求:**lift 之前不碰 bytecode,所有判定都在 lifted LLVM IR 上**,并加 CLI 投机 hint。
- **认 map(IR)**:llvmbpf(kernel-compatible)把 map 引用 lower 成
  `ptrtoint(@__llvmbpf_pseudo_map_idx_<8hex>)`;`resolve_map_idx_ir` 把 lookup 的 map 参数
  追到该全局符号 → 解析 hex idx → 经 `--map-ids` 得 map_id。**消掉了 bytecode `map_id_for_lookup`
  + ordinal 对齐那个脆 hack。**
- **mutability(IR)**:`ir_mutable_maps` 扫 IR 里 `map_update/delete/push/pop` 调用,用同样的
  符号-trace 认它们的 map → mutable 集合。不再扫 bytecode。
- **fold(IR)**:每个 lookup call 解析 map_id、跳过 mutable;
  - uniform map → 无条件:value-deref load 换立即数、null 检查看到非空、删 lookup(O3 传播+DCE);
  - **CLI 投机 hint**(`--inline-hint=mapname:keyhex`)→ **soft guard**:每个 load 值变
    `select(key==K, const, 真 load)`,**保留真 lookup 当 fallback**。const/可证 key → O3 把
    select 折掉并 DCE lookup;runtime key → 保留守卫回退(对其他 key sound)。无 hard fold。

### katran 结果(全 IR,kinsn LLVM-23)
- test **通过**(retval 3 / IPIP 84,转发正确)。
- insns 2542 → **2367**,map_lookup_elem 70 → **60**(消 10 个),折 ch_rings + server_id。
- **性能 5 次:baseline ~138 vs fold ~138 ns(噪声内)**——再次确认查找非 katran 瓶颈。
- **vip_map 仍未折**:即便给了 `--inline-hint=vip_map:<TCP VIP key>`,其 lookup 结果**跨分支
  流入 phi**,use-walk(只认 icmp/inttoptr→load)拒掉 → guard 找不到 load → 跳过。要折它需要
  在 IR 里做**分支级 guard 重构**(SplitBlock + 每个 load 值 phi 合并),不是直线 select 能解决。
- reals:runtime key + 4096 entry,仍需 guard;const-key(ctl_array)需 IR 里追 key 指针常量
  store。两者都待分支级 guard / IR-const-key。

### 现状小结
- ✅ 全 IR(无 pre-lift、无 ordinal):map/mutability/fold 全在 IR。
- ✅ CLI 投机 hint 机制(soft select,有 fallback)。
- ⏳ vip_map(phi)/ reals(runtime 多值)需 IR 分支级 guard;ctl_array 需 IR 常量-key。
- katran 性能与覆盖无关地 flat(查找非瓶颈);要量 map_inline 价值得用查找密集程序。

## 分支级 soft guard 完成 + vip_map 折成功(2026-05-22 再追加)
之前的 select 是错的:**select 两个操作数都求值,昂贵的 vip_map HASH 查找每包仍跑**,所以
runtime key 零收益——这正是"没做到位"。改成**真控制流分支**:
```
orig:  %m = (key==K); br %m, fast, slow
fast:  <把快照 value 物化到栈槽(无 .rodata 全局)>; br merge   ; 跳过查找
slow:  %r = call map_lookup_elem(...);          br merge       ; 仅 miss 才查
merge: %r0 = phi [fastptr, fast], [%r, slow]
```
- 在 **call 边界**替换结果(`call->replaceAllUsesWith(phi)`),**统一处理所有下游用法**
  (load / null 检查 / **PHI**)——vip_map 结果流经 phi,旧的 per-load select 路径够不到,
  分支法天然解决。
- value 物化进**栈 alloca**(i32 字 + i8 尾),O3 SROA 把存的字节转发进下游 load;**无常量
  全局 → 不触发 .rodata.cst8 relocation 问题**。
- uniform map 改成同样的"物化栈指针 + 删 call",也天然支持 phi。
- 删掉死代码:整段 bytecode-era helper(`apply_map_inline_auto` / `build_guard_chain_block` /
  `scan_data_path_mutable_maps` / `find_key_stack_off` / `value_ptr_is_read_only` /
  `build_stack_value_block` / `stack_bytes_used` / `allocate_stack_slot` / `mem_access_size` /
  `collect_value_loads` / `le_value` / `GuardEntry`)。

### katran 结果(分支级 guard,kinsn LLVM build-kinsn,map_inline-only)
- test **通过**(retval 3 / IPIP 84,转发正确)。
- insns 2542 → **2371**,map_lookup_elem 70 → **56**(消 14 个)。
- **sites_applied=8**:vip_map(25740)**4 个守卫站** + ch_rings(25744)/server_id(25752)
  4 个 uniform 站。vip_map 不再被跳过——**这是之前缺的那块**。
- **静态验证守卫已生成**:output.bin 里出现 key-match 立即数 `0x0101640a`(word0)/
  `0x0006901f`(word4)各 4 次(8 个 JNE32),中间全零字 O3 合并;vip_map HASH 查找**只留在
  mismatch 慢路径**,匹配 VIP 的快路径跳过它。
- **性能(live XDP frames,repeat=10000,6 次):baseline ~103 vs opt ~102 ns,持平。**

### 为什么折了还是 flat(定论)
守卫正确、查找确实在快路径被跳过(静态+动态都验证),但每帧时间不动。原因:**katran 的
vip_map 只有 1 个 VIP 条目**,HASH 查找 cache-hot 极廉(hash + 1 次比较,~个位 ns),省下来的
被 ~100ns 的解析 + IPIP encap + csum + XDP/NAPI 基建开销和测量噪声(±5ns)淹没。
**结论:对 katran 这个 1-条目热 vip_map,查找不是瓶颈**——与"lookup 是瓶颈"的假设在 katran
上不成立。要展示 map_inline 性能价值需用**多条目 / cache-cold / 查找密集**的程序。
注:LLVM bpfopt 目前只接在 host loader(live-frames),未接入 corpus(corpus 走 Rust bpfopt),
所以无法用 corpus 的 per-program run_time_ns_delta 复测此 LLVM 折叠。

## 覆盖率 + 常量传播核查(2026-05-22,基于 BPFOPT_DUMP_IR 实证)
加了 `BPFOPT_DUMP_IR=1` env 在 O3 后 dump module IR。对 katran 优化后 IR 逐项核查:

### 覆盖率:当前 8 站 / 3 map,**未达旧 hard-fold 的 16**
优化后 IR 里按 map idx 数残留 lookup:
| map idx | map | 残留 lookup | 状态 |
|---|---|---|---|
| 0xa | ch_rings | **0** | uniform 全消 ✅ |
| 0xd | server_id | **0** | uniform 全消 ✅ |
| 1 | vip_map | 4 | guarded 慢路径保留(快路径跳过)✅ |
| 0 | stats(percpu) | 28 | mutable 计数器,正确不折 |
| 2 | lru_mapping | 2 | array_of_maps,非 value-inline |
| 6 | **reals** | 4 | **未折**(runtime key,没给 hint) |
| 8 | **ctl_array** | 2 | **未折**(只读 config,需 IR 常量-key 推导) |

→ **缺口 = ctl_array(2,常量-key)+ reals(4,runtime-key 需 hint)**。这正是旧 hard-fold
能折而现在没做的:**IR 里没实现常量-key 推导**(`derive_const_lookup_key` 删掉后没用 IR 重做),
ctl_array 的 key 在 IR 里是 `r10-120` 栈槽,要 sound 地认出常量需追该槽的常量 store(被
stackBegin GEP 别名搞复杂,脆)。

### 常量传播:**uniform 生效,guarded(vip_map)不生效**
- **uniform 无条件折(ch_rings/server_id)**:O3 后对应 `mapinline.val` alloca **全部消失**,
  InstCombine 把 `inttoptr(ptrtoint(alloca))→alloca`,SROA promote,value load 折成立即数
  1/0,lookup 全消。**常量传播 ✅**。
- **guarded vip_map**:O3 后仍残留 4 个 `store i32 2`(real_pos=2)+ alloca。原因:vip_map
  结果流入**程序自己的 4-way 指针 phi**(`%r0.0 = phi [%470,%471,%485,%486...]`,合并 4 个
  vip 站),`ptrtoint(栈槽)` 混进 phi → **SROA 无法 promote** → 快路径上 value 2 是
  **运行时栈 store+load**,**没有常量传播进下游 reals[2] 索引**。**常量传播链在 guard 处断掉 ❌**。
  → 修需要在快路径携带**字面值**而非栈指针,即对下游 value-load 做 per-value phi;但 katran
  把 4 个 vip 站先 merge 成一个指针再 load,per-site const-prop 需把 load 区按 4 路复制,代价大。

### 对三问的结论
1. **katran lookup 非瓶颈**:折掉的 vip(1 条目热 hash)+ ch_rings/server_id(array)本就廉;
   贵的 LRU 连接跟踪 hash(fallback_cache)是 mutable 不能折;reals/ctl_array 是 array/config 也廉。
2. **没到 16**:当前 8 站,差 ctl_array(常量-key)+ reals(hint),需补 IR 常量-key 推导。
3. **常量传播**:uniform 生效;guarded vip_map **不生效**(指针-phi 破坏 SROA,值运行时 load)。

## 状态
- map_inline 多条目枚举 + uniform 消除:✅ 实现 + sound + kinsn 编译通过。
- llvmbpf LLVM 多版本兼容宏:✅ x86-23 编译通过,arm64-15 语法兼容。
- arm64 用仓库 LLVM-23:⏳ 需交叉构建 arm64 kinsn LLVM(重)。
- 所有改动未 commit。
