# bpfopt/llvm 移植到仓库内 kinsn LLVM-23 (2026-05-21)

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

## 备注
- 所有 git 改动均未提交,等用户 review(`git add` 已按要求 stage)。
- submodule `vendor/llvmbpf` 的 4 处改动都是 LLVM-23 兼容/正确性修复,无功能删除。
