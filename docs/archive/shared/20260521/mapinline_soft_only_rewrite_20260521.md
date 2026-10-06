# LLVM bpfopt map_inline:删 hard+hint,改全自动 soft fold(2026-05-21)

## 做了什么(按用户指令)
把 LLVM bpfopt(kop 路径)的 map_inline 从「手写 hint + hard fold」改成
「无 hint、全自动 soft fold,提供 snapshot + 满足条件就尽量折」。hint 后续提升到全局层。

### 改动
- **删 `--inline-hint` 解析 + hard 模式**(`parse_map_inline_args` 去掉 hint;删 InlineHint
  结构和 hard-only guard)。
- **自动发现折叠点**(`apply_map_inline_auto`):
  - `derive_const_lookup_key`:从 bytecode 回溯 r2=r10+off + 常量 ST_MEM 写,恢复编译期
    常量 key;运行期 key 返回 nullopt(留给全局层)。
  - `truly_uniform`:snapshot 里 compression=="uniform" 的 map(每个 entry 同值),不需要
    key 也能折;与 sparse 的 default fallback 区分开(后者只对缺失 key 正确,不能当折叠值)。
- **soft codegen**:保留真实 lookup 当 presence guard,只在「lookup 命中」路径上把值
  替换成 snapshot 常量(materialize 到栈 + r0=&V),**不删 miss/slow 路径**(hard 才删)。
- **正确性 gate**(无 daemon,无 deopt,必须保守):
  - 跳过 data-path-mutable map(`scan_data_path_mutable_maps`:程序里有
    map_update/delete/push/pop)。
  - 跳过 value 指针被写穿(`*(r0+x)=`)、被拷出(`MOV rX,r0`)、或被存进内存
    (`STX *(rX)=r0`,即 map-value 指针存栈再复用)的 site —— `value_ptr_is_read_only`。
  - 跳过非普通值类型(map-in-map/prog_array/ringbuf 等)。
- snapshot 增加 `map_type` / `truly_uniform`(从 `bpftool map show -j` 的 `type` 读)。
- loader:`run_katran_map_inline` 去掉 5 个 `--inline-hint` 参数(工具不再接受);
  `verify_workdir` 在 `BPF_PROG_LOAD` 返回 ENOSPC 时重试 `log_level=0`(复杂程序的
  verbose verifier log 撑爆 64MB → ENOSPC,但程序其实能过),与 prepare_workdir 一致。

## 结果:实现完成且 sound,但 katran 验证暴露了一个**独立的 O3 roundtrip 正确性 bug**

### 机制本身工作
katran balancer 上自动折出 **4 个 site**(ch_rings ×2 + server_id_map ×2,都是 uniform
overlay,且 snapshot 值与内核 populate 的值一致),其余 56 个 site 是 stats/reals/lru 等
无 snapshot 值或运行期 key 的,正确跳过;输出能加载。

### 但 katran 转发测试失败(retval=2,期望 XDP_TX=3)——**根因不是 soft fold**
关键隔离实验:用 `BPFOPT_MAPINLINE_DISABLE` 把折叠**完全关掉(0 fold)**,只跑 O3
roundtrip,**仍然 retval=2**。所以:
- **是 LLVM O3 roundtrip 本身把未简化的 katran balancer 编译错了**,不是 soft fold 的问题。
- 之前 hard fold(16 site)给出 retval=3 / -17%,是因为**hard 折叠把程序简化够多,O3 才
  恰好保持正确**。删掉 hard 后程序不被简化,O3 roundtrip 的不保语义问题就暴露了。
- 即:`llvmbpf` 的 eBPF→IR→O3→eBPF 回环在复杂程序上**不可靠地保持语义**(retval 2 vs 3)。
  这是个先前被 hard fold 掩盖的潜在 bug,独立于 map_inline。

## 结论 / 待决策
- soft-only 自动 map_inline **已按规格实现、编译干净、542 testbin noop 0 失败、gate sound**。
- 但**无法用 katran 验证**,因为 O3 roundtrip 在未折叠的完整 katran 上就已经 mis-compile
  (retval=2),与折叠无关。
- 三条路(等用户定):
  1. **查/修 O3 roundtrip 正确性 bug**(深,独立于 map_inline;可能是 llvmbpf O3 lift 的
     某个 pass 在这个程序上不保语义)。
  2. **保留 hard fold** 给「把值强行投机进 map」的 speculative 场景(katran 基准本质需要它:
     ch_rings/reals 等被 hard 折成 overlay 意图值)——soft 只在内核 map 真被 populate 且值
     稳定时正确。
  3. **换一个 populated-map 的简单 app 验证 soft fold**(O3 roundtrip 在简单程序上正确)。

## 备注
- 所有改动未 commit,等用户 review。debug 脚手架(计数器/DISABLE env)已清理。
