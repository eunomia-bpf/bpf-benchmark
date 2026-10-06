# bpfopt/llvm 移植到仓库内 kinsn LLVM-23 (2026-05-21)

## 2026-05-22 策略修正
LLVM 版 `bpfopt` 的 pass 模式统一定义为 **每个 `--pass <name>` 都执行一次
lift → LLVM O3 → BPF lower 回环**；`noop` 也不能走 O0 或 raw-bytecode fallback。
`--verifier-states` 不再是 LLVM 版契约的一部分，现有调用里出现时仅作为兼容参数
忽略。`map_inline` 以后只有一种 `--inline-hint=<map>:<key_hex>`：提示某个 map
entry key，使优化器使用 snapshot 中对应的 value；旧 `!<key_hex>` 写法只兼容接受，
不再表达 hard/soft 区别。

post-lowering 不再作为 verifier repair 层使用。LLVM BPF backend 生成 object 后，
这里只做 relocation 和 raw instruction stream 恢复；range/signed-jump/bounds/
dead-ALU/memory-address 等 bytecode repair 已移除，后续若要恢复必须有 verifier log
和最小 reproducer，并优先落在 IR 或 BPF backend。

## 目标
让 `bpfopt/llvm`(eBPF→LLVM IR→O3→eBPF 回环工具)依赖仓库里的 kinsn LLVM
(`llvm-backend/build-bpf-kinsn`, **LLVM 23.0.0git**, 内含 kinsn pass),而不是系统的
LLVM-18。这样回环工具就能用到 kinsn 后端。

## 结果:成功
`bpfopt/llvm/build-kinsn/bpfopt` 已能针对 kinsn LLVM-23 **静态链接**编译通过
(`ldd` 无任何动态 LLVM 依赖),并在全部 **542 个 testbin 程序**上跑 noop 回环
**0 失败**——比系统 LLVM-18 build 更健壮(后者在 35 个程序上 "BPF stack limit
exceeded" 失败)。

## 改动清单

### 1. `bpfopt/llvm/CMakeLists.txt`(我们的代码)
- 丢弃 `llvm-config --libs` shell-out:kinsn LLVM build 没有可用的 `llvm-config`
  (`tools/llvm-config` 因 `CMAKE_CFG_INTDIR` 宏问题无法编译),回退到系统
  `llvm-config-18` 导致链接到 `-lLLVM-18`(头文件 23、库 18 的版本错配)。
- 改用 CMake 原生 `llvm_map_components_to_libnames`,从已加载的
  `find_package(LLVM CONFIG)` 解析组件库;组件库的 transitive deps 自带 zlib/zstd
  等系统库。
- `bpf` 伞形组件在该 config 下未注册(被误映射成 `-lLLVMbpf`),改为显式列
  `bpfcodegen bpfasmparser bpfdisassembler bpfdesc bpfinfo`。
- host 后端(`native x86 aarch64`)按 `LLVM_TARGETS_TO_BUILD` 条件加入——kinsn LLVM
  只 build 了 BPF target,系统 LLVM-18 才有 x86/aarch64。
- 按 `LLVM_ENABLE_RTTI` 决定 `-fno-rtti`:kinsn LLVM 是 RTTI-OFF,我们的 TU 用
  RTTI-ON 编译会留下 `ErrorInfoBase`/`format_adapter` 的 typeinfo 未解析符号。
- `build-kinsn` 必须用 `-DCMAKE_BUILD_TYPE=Release`(`NDEBUG`),否则 LLVM 头里的
  inline assert 触发(见下)。

### 2. kinsn LLVM 缺失的库
kinsn LLVM 是个最小 codegen build,缺 JIT/反汇编库。在 `build-bpf-kinsn` 里补 build:
`LLVMMCDisassembler LLVMExecutionEngine LLVMRuntimeDyld LLVMOrcJIT LLVMJITLink
LLVMOrcTargetProcess LLVMOrcShared LLVMMCJIT LLVMBPFDisassembler`(llvmbpf 的
OrcJIT 路径引用它们)。

### 3. `vendor/llvmbpf/src/llvm_jit_context.cpp`(submodule, LLVM 18→23 API)
- `setTargetTriple(...getTargetTriple().str())` → 去掉 `.str()`
  (LLVM 23 `setTargetTriple(Triple)` 收 `Triple`)。
- nvptx/spirv: `lookupTarget(triple_name/std::string, ...)` →
  `lookupTarget(triple/Triple, ...)`;`createTargetMachine(triple_name, ...)` →
  `createTargetMachine(triple, ...)`(LLVM 23 两者都收 `const Triple&`,移除了
  string 重载)。

### 4. `vendor/llvmbpf/src/compiler.cpp`(submodule, **真·正确性 bug**)
回环的 lifter 在 fallthrough 收尾循环里用
`if (currBlk->getTerminator() == nullptr)` 判断块是否缺 terminator。
**LLVM 16+ 起 `getTerminator()` 改为 `assert(hasTerminator())` 后无条件返回
`back()`**——所以在 Release(NDEBUG,assert 被编译掉)下,对缺 terminator 的块它
返回的是**非空的非终结指令**,而不是 `nullptr`。于是 `== nullptr` 永远为 false,
`setupBlock` 拿不到收尾的 `br`,产生 `bb_inst_0: No predecessors!` 的非法 module。
- 改为 `if (!currBlk->hasTerminator())`——在所有 LLVM 版本上都正确。
- 这是 llvmbpf 此前在 assertion-off / 旧 LLVM 上被掩盖的潜在 bug;LLVM-18 build
  之所以"能跑",纯粹因为旧 `getTerminator()` 在缺 terminator 时返回 `nullptr`。

## 等价性验证(542 testbin 程序, noop 回环)
| | 数量 |
|---|---|
| 总数 | 542 |
| LLVM-18 与 kinsn-23 字节完全一致 | 369 |
| 字节不同(LLVM 版本 codegen 差异,双方都过 verifyModule) | 138 |
| LLVM-18 失败(BPF stack limit exceeded,大程序) | 35 |
| **kinsn-23 失败** | **0** |

- 138 处字节差异是两个不同 LLVM 大版本(18 vs 23)优化器/调度/寄存器分配差异,
  属预期;两边输出都通过 LLVM IR verifier 并成功 emit BPF ELF。
- kinsn-23 在 LLVM-18 失败的 35 个 "stack limit" 大程序上反而 **0 失败**。
- `map_inline` 单 pass 在两个 build 上都是 0 成功——因为 `--pass map_inline` 缺
  `--inline-hint`/`--map-values` 侧输入;两版行为一致,非 kinsn 回归。真正的
  map_inline 端到端(带 hint)由 loader 在 katran 上 TEST_RUN 驱动验证(此前已测,
  ~20% 提速),需 root。

## 内核加载 + TEST_RUN 性能(kinsn-built bpfopt, 本机 stock 6.15 kernel)
用 `bpfopt-loader` 把全部 35 个 testobject 逐个 libbpf 加载进内核、跑 pass、重验、
`BPF_PROG_TEST_RUN`(`--bpfopt` 指向 kinsn build)。

**全部 35 个的可加载性**:本机是 **stock 6.15 内核(非 rejit fork)**,且大多数程序是
kprobe/tracepoint/LSM/cgroup 类型(不支持 `BPF_PROG_TEST_RUN`),还缺 fork 内核的
kfunc/BTF/map/attach 上下文。结果:
- **katran_balancer / balancer_ingress(XDP)**:唯一能完整加载 + TEST_RUN 的(exit 0)。
- bcc_*(kprobe):能 libbpf 加载,但 TEST_RUN 不支持该类型 → exit 1。
- cilium_*/otel_*/tracee_*/katran 其余/healthchecking:stock 内核上加载失败 → exit 1。
- bpftrace_*:prepared 程序列表为空(无可加载入口程序)→ exit 0 无 test_run。
- 结论:**真正的跨 app 性能必须在 rejit-fork VM 里走 `make corpus`**,host TEST_RUN 只
  有 katran 这一条可靠路径(与此前结论一致)。

**katran balancer_ingress 性能**(live-XDP, repeat=10000, 各 3 样本, ns/run):
| pass | s1 | s2 | s3 | 中位 |
|---|---|---|---|---|
| noop(baseline) | 127 | 136 | 131 | ~131 |
| map_inline | 125 | 128 | 130 | ~128 |

map_inline 比 noop 基线快 ~2%,**落在测量噪声带内**(两组区间重叠)。即 kinsn-built
bpfopt 的端到端 kernel-load + TEST_RUN 管线工作正常,katran 这个站点在本机上 map_inline
收益不显著。

## 复盘:map_inline / const_prop / dce / 加载失败(2026-05-21 追加)

### 之前 sweep 里 map_inline "0 收益" 的真因
`bpfopt-loader` 的 `load_pass_command()` **永远读 `default.yaml`**,从不读 `katran.yaml`。
`default.yaml` 的 map_inline 命令**不带任何 `--inline-hint`** → 命中 0 site → 等于没优化。
带 5 个 hint 的 katran 路径只走 (a) corpus runner 选 `katran.yaml`,或
(b) cargo test `katran_optimization_path`(hint 硬编码在 `katran_test_cli`/
`run_katran_map_inline`)。所以 host sweep 用 `--pass map_inline` 测出来的 ~2% 是噪声,
不是 map_inline 结果。

### map_inline 真实结果(kinsn bpfopt, katran balancer_ingress, 5 hint)
`katran_optimization_path` test(`BPFOPT_LOADER_SKIP_BYTECODE_PASSES=1`):
- `sites_applied=16 / sites_matched=16 / sites_skipped=0`,**5 个 map** 被内联:
  vip_map ×4、reals ×6、ctl_array ×2、ch_rings ×2、server_id_map ×2。
- insn `2542 → 2496`(-46)。
- **baseline 126 ns → optimized 104 ns ≈ -17%**,retval=3 转发正确
  (`assert_katran_forwarding_output` 通过)。

### 为什么 map_inline + const_prop + dce 链失败
全链(不 skip)在 const_prop/dce 步**报错**:
`Looks like the BPF stack limit is exceeded` / `requires 520 bytes of stack,
exceeding the kernel limit`,`dce exited with exit status: 1` → test FAILED。
根因:**LLVM bpfopt 每个 pass 都做一次完整 O3 roundtrip**(lift→IR→O3→bytecode)。
map_inline 本身就是 O3(已含常量传播 + DCE)。再把 const_prop、dce 当独立 pass 跑
= 又跑两次 O3;多次 O3 的 spill/stack-slot 叠加后程序需 520B > 512B BPF 栈上限,
BPF backend 直接拒绝。**对 LLVM 路径 const_prop/dce 是冗余的**,所以 loader 用
`BPFOPT_LOADER_SKIP_BYTECODE_PASSES` 跳过它们(注释见 main.rs:1518-1521)。
→ 正确用法:LLVM bpfopt 只跑 map_inline(O3 已覆盖 const-prop/dce)。

### "加载失败" 真相:其实没有加载失败,是 TEST_RUN 失败
去掉 `--bpftestrun` 后,cilium_bpf_xdp / katran_xdp_pktcntr / bcc_biosnoop 等
**`BPF_PROG_LOAD` + verify 全部成功(exit 0)**——kinsn bpfopt 的 O3 roundtrip 产物
能正常过内核 verifier。之前 sweep 的 exit 1 全来自 `BPF_PROG_TEST_RUN`:
| 类型 | errno | 原因 |
|---|---|---|
| kprobe (bcc_*) | EFAULT 14 | TEST_RUN 需要 ctx_in(pt_regs),loader 给的是 data buffer |
| LSM/tracepoint (tracee_lsm) | ENOTSUPP 524 | 内核该 prog 类型不支持 TEST_RUN |
| XDP/TC (cilium_xdp, katran_pktcntr) | EINVAL 22 | TEST_RUN 需要合法报文输入,默认空输入 |
| otel_* | — | split object,需先 link tracer.ebpf.amd64(缺依赖) |

**能不能修?——不应该修。** 唯一让它们 TEST_RUN 跑起来的办法是注入合成报文/合成 ctx,
这违反项目规则 `feedback_no_synthetic_workload`("严禁用 BPF_PROG_TEST_RUN 注入合成包
测 latency,必须真实 workload 触发,katran 现状也是违规要重审")。正确的性能测量路径是
rejit-fork VM 里 `make corpus`(stress-ng/fio/iperf3 等真实 workload 驱动)。host
TEST_RUN 只对 packet 类 + 带真实报文(katran)这一条可靠。

## map_inline 真的 inline 了吗?——bytecode 级证据 + LLVM vs Rust 对比

同一 canonical 输入(2542 insn,70 个 `bpf_map_lookup_elem`/helper#1 调用):

| | insns | helper#1 调用 | **实删调用** | report applied | retval | 正确性 |
|---|---|---|---|---|---|---|
| 原始 | 2542 | 70 | — | — | — | — |
| **LLVM map_inline** | 2496 | 54 | **16** | 16 | 3 | ✅ IPIP 84B |
| **Rust map_inline** | 2456 | 60 | **10** | 16 | 2 | ❌ 期望 XDP_TX(3) |
| Rust 全链(+const_prop+dce) | 2421 | 60 | 10 | — | 3 | ❌ outer proto 6≠IPIP4 |

**结论 1:LLVM 真的 inline 了。** 70→54,删掉 16 个 `map_lookup_elem` 调用,且把 map 值
作为常量直接嵌入。反汇编铁证:LLVM 输出新出现 `r1 = 0xb0000000002 ll`(=ctl_array 值
`02000000000b0000`)2 处,对应 ctl_array ×2;新增折叠立即数 `0x0`(server_id_map)、
`0x2`(vip_map)、`0x3`/`0x9`(ch_rings/reals)等。原始的
「`r1=mapfd; call helper#1; if r0==0 jmp; r1=*(r0+8)`」lookup 序列被替换成直接 load 常量。

**结论 2:Rust 不是"效果好很多",而是这条 host katran 路径上 broken。**
- Rust report 写 applied=16,但实际只删了 **10** 个调用(70→60)——它把 lookup 后的值
  折叠了,却没把 call 指令 DCE 掉(LLVM 的整函数 O3 在值变常量后会把死 call 整个消掉,
  更彻底)。Rust insn 更少(2456)是结构不同 + 它额外的 const_prop/dce,但……
- Rust map_inline-only 输出 **retval=2**(期望 XDP_TX=3),全链输出 outer protocol 6 ≠
  IPIP(4)——**语义错误**,`assert_katran_forwarding_output` 失败。所以没有可比的有效
  Rust perf 数。
- 注意:Rust bpfopt 二进制是 2026-05-20 build,可能 stale;其当前不正确是 stale-binary
  还是真实回归,需 rebuild 复核(单独调查)。

**结论 3:LLVM 的 baseline 126→104 ns(-17%)是真实且正确的 map_inline 收益。**

## 备注
- 所有 git 改动均未提交,等用户 review(`git add` 已按要求 stage)。
- submodule `vendor/llvmbpf` 的 4 处改动都是 LLVM-23 兼容/正确性修复,无功能删除。
