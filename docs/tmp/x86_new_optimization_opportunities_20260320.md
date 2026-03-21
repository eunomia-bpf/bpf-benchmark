# x86 BPF JIT 新优化机会调研（2026-03-20）

## TL;DR

结论先行：

1. 当前三个 E2E workload 里，已实现 canonical forms 的 live 分布并不支持“继续深挖 `cmov`/`branch-flip`”作为首要方向。
   - Tracee live sites 聚焦在 `cmov`。
   - Tetragon live sites 只有 `branch-flip + cmov`，而且 `event_execve` 的现有收益已接近持平。
   - Katran 数量上 `branch-flip` 最多，但最明显的**未覆盖** native gap 反而是 prologue、stack zero-init、tree-shaped wide-load。
2. x86 stock JIT 当前最值得补的不是另一个“小 CFG form”，而是：
   - program-entry `PROLOGUE_TIGHTEN`
   - `NARROW_OPS`（load-width narrowing / 32-bit lowering）
   - `ZERO_STORE_FUSION`
   - `WIDE_MEM_TREE_BE`
   - `BOUNDS_WINDOW`（需要 verifier facts）
3. Katran 给出了最强的直接指令级证据；Tracee 次之；Tetragon 在 host 上拿不到 stock dump，所以只能做中等置信度判断。

## Scope / Method

输入：

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/llvm_vs_kernel_jit_disasm_analysis_20260319.md`
- `docs/tmp/emitter_cost_and_branchflip_analysis_20260320.md`
- `docs/tmp/katran_wide_load_investigation_20260320.md`
- `docs/tmp/katran_storepair_stock_jited_20260320.txt`
- `arch/x86/net/bpf_jit_comp.c`
- `e2e/results/{tracee,tetragon,katran}_authoritative_*.json`
- `scanner/build/bpf-jit-scanner`

我实际做的：

1. 用 authoritative E2E JSON 里的 live scan / remap 结果汇总当前 workload 的 form 分布。
2. 对代表程序做 native dump 对比：
   - Tracee: `syscall__execve_enter`
   - Tetragon: `event_execve`
   - Katran: `balancer_ingress`
3. 审查 `arch/x86/net/bpf_jit_comp.c` 的 prologue、zero-extension、div/mod、callee-saved、短编码机会。
4. 用 `llvm_vs_kernel_jit_disasm_analysis_20260319.md` 判断哪些 LLVM 优势是当前 8-form taxonomy 没覆盖的。

限制：

1. 不跑 VM。
2. Tetragon 的 host-side stock kernel JIT dump拿不到：
   - `run-kernel --compile-only --dump-jit` 失败在 `execve_calls` prog-array 初始化；
   - `--manual-load` 仍失败，最终报到 `bpf_map_create(tcpmon_map) failed: Invalid argument`。
   因此 Tetragon 的 stock-vs-LLVM 指令级证据只能用：
   - live site mix
   - `event_execve` 的 llvmbpf dump
   - 既有 March 19, 2026 micro disasm 分析
3. Katran 有两份 live census：
   - March 19, 2026 authoritative JSON：`94` sites
   - March 20, 2026 wide-load investigation：`74` sites
   两者来自不同 run。本文对**总体 workload 分布**采用 `94`；对 **WIDE_MEM tree/BE gap** 采用 March 20 这次专项调查，因为它专门把 `wide` 形状追到了具体 insn offset。

## 1. 当前 workload 的 live site 分布

### 1.1 Workload-level live totals

| Workload | Live programs used | `branch-flip` | `cmov` | `rotate` | `wide` | `endian` | `extract` | total |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| Tracee | 11 policy-hit live programs | 37 | 88 | 0 | 0 | 0 | 5 | 130 |
| Tetragon | 7 live programs | 49 | 24 | 0 | 0 | 0 | 0 | 73 |
| Katran | 1 live program | 56 | 8 | 20 | 4 | 4 | 2 | 94 |
| Combined | 19 | 142 | 120 | 20 | 4 | 4 | 7 | 297 |

直接结论：

- 现有 live workload 里，数量最大的 family 仍是 `branch-flip` 和 `cmov`。
- 但这**不等于**它们还是最值得继续做的新方向。
- 从已有结果看，`cmov` 强 policy-sensitive；`branch-flip` 在 workload 中也不是稳定正收益。
- 真正还没被覆盖的高置信度 gap 更偏 x86 lowering / prologue / store/load shape。

### 1.2 Per-workload observations

#### Tracee

- live remap 总计：`cmov=88`, `branch-flip=37`, `extract=5`
- 代表程序：
  - `sys_exit_submit`: live `30` sites = `branch-flip 4`, `cmov 21`, `extract 5`
  - `syscall__execve_enter`: live `8` sites = `branch-flip 2`, `cmov 6`
  - `lkm_seeker_modtree_loop`: live `26` sites = `branch-flip 4`, `cmov 22`

最重要的事实不是总数，而是 **object-level 和 live-level 差得很大**：

- `lkm_seeker_modtree_loop` object scan 有 `195` sites，其中 `branch-flip 85`；
- 但 live remap 后只剩 `26`，其中 `branch-flip` 只剩 `4`。

这说明：

- Tracee 的大量 candidate site 只存在于离线 object / explicit policy allowlist；
- 真正在当前 E2E 路径上还活着的，主要是少量 branch-flip 和一批 `cmov`。

#### Tetragon

- live scan 总计：`73` sites = `branch-flip 49`, `cmov 24`
- 代表程序：
  - `event_execve`: `29` = `branch-flip 14`, `cmov 15`
  - `execve_send`: `14` = `branch-flip 5`, `cmov 9`
  - `execve_rate`: `7` = `branch-flip 7`
  - `event_wake_up_new_task`: `13` = `branch-flip 13`

这里最重要的现象是：

- 当前 live Tetragon 没有 `wide/rotate/endian/extract`；
- `event_execve` 的 live `cmov=15` 已经被 policy 全 skip；
- `event_execve` 的 observed speedup 约 `0.994x`，说明继续追加“另一个 branch-like local form”不是高 ROI。

#### Katran

- March 19, 2026 authoritative live scan：`94` sites = `branch-flip 56`, `rotate 20`, `cmov 8`, `wide 4`, `endian 4`, `extract 2`
- `docs/tmp/katran_wide_load_investigation_20260320.md` 的专项 run 给出 `74` sites，并确认 `wide` 细节：
  - `4` 个当前 wide sites 全来自同一段 MAC copy
  - 另外还有 tree-shaped LE/BE byte-recompose 没被 current WIDE_MEM 抓到
  - 当前 binary 上可信的增量是 `4 -> 6` start sites

Katran 的关键信号是：

- numerically 最大的是 `branch-flip`
- 但**native dump 里最扎眼**的未覆盖 gap 不是 branch layout，而是：
  - 入口 NOP/prologue
  - scalar zero-init
  - `add [mem], 1` vs `inc [mem]`
  - byte ladder / endian load shape

## 2. 代表程序的 native gap

### 2.1 Tracee: `syscall__execve_enter`

代表性：

- live sites `8`
- stock JIT size `20392` bytes
- xlated size `31992` bytes

我看到的 stock kernel JIT 特征：

- 开头就有 `5-byte + 3-byte` NOP padding，然后才 `push rbp / mov rbp, rsp`。
- 早期大块初始化是 scalar stores。
- 整个 binary 里 `movzx` 非常多；粗数 native dump 里有 `252` 个 `movzx`。

我看到的 llvmbpf 特征：

- 早期直接用 `vpcmpeqd + vmovdqu` 清大块状态。
- 布尔条件组合更倾向 `sete/setne + andn`，而不是 stock 那种 `cmp + xor/or/neg` 长链。

结论：

- Tracee 当前最值得补的不是再扩大 `branch-flip`。
- 更像是两个方向：
  - `NARROW_OPS`
  - `ZERO_STORE_FUSION`

### 2.2 Tetragon: `event_execve`

代表性：

- live sites `29`
- 构成完全是 `branch-flip 14 + cmov 15`

我能拿到的 llvmbpf dump特征：

- 大 helper-heavy tracepoint 程序；
- 大 frame；
- 有明显的 stack copy / state init 区域；
- 没看到 workload-specific `wide/rotate/endian` 信号。

由于 host 上 stock dump不可得，我不把这部分写成“事实对比”，只保守下结论：

- Tetragon 当前没有证据表明“再加一个 local branch/cmov family”会是高回报；
- 更像需要：
  - prologue / save-set tighten
  - stack zero/store fusion
  - 可能的 boolean-mask lowering

### 2.3 Katran: `balancer_ingress`

代表性：

- authoritative live sites `94`
- stock JIT size `13412` bytes
- xlated size `23872` bytes

`bpftool prog dump jited` 的 stock dump一上来就能看到 prologue 低效：

- `endbr64`
- `nopl (%rax,%rax)`
- `nopl (%rax)`
- `pushq %rbp`
- `movq %rsp, %rbp`
- `subq $184, %rsp`
- `pushq %rbx/%r13/%r14/%r15`

这在 `docs/tmp/katran_storepair_stock_jited_20260320.txt:4-14` 很直接。

随后还能看到：

- `data_stats->v1 += 1` 被 lowering 成 `load; addq $1; store`，不是 `inc [mem]`，见同文件 `:49-56`
- `eth->h_proto` 仍是 byte ladder `movzbq + movzbq + shl + or`，见同文件 `:57-66`
- `struct packet_description pckt = {};` 是一串 scalar zero stores，见同文件 `:72-80`

llvmbpf 对同一程序则更激进：

- 大量 `inc QWORD PTR [...]`
- `movbe`
- `vxorps + vmovups`
- 少量 `dec WORD PTR [...]`

这说明 Katran 当前 workload 里，最值得补的是：

1. `PROLOGUE_TIGHTEN`
2. `ZERO_STORE_FUSION`
3. `WIDE_MEM_TREE_BE`
4. 小型短编码优化只是加分项，不是主菜

## 3. 从 x86 kernel JIT 源码看到的已知低效

### 3.1 Prologue NOP / entry layout

`emit_prologue()` 明确写着：

> “BPF trampoline can be made to work without these nops, but let's waste 5 bytes for now and optimize later”

位置：`arch/x86/net/bpf_jit_comp.c:516-566`

关键点：

- 固定发 `emit_nops(..., X86_PATCH_SIZE)`，即 `5` bytes
- 某些路径再补一个 `nop3` 保持布局
- 这不是 accidental bloat，而是**有意保守**

这是最干净的 `PROLOGUE_TIGHTEN` 证据。

### 3.2 Callee-saved push/pop 仍偏保守

`push_callee_regs()` / `pop_callee_regs()` 在 `:365-400`，本身已经按 `callee_regs_used[]` 做了 usage-based save/restore。

但仍有两个保守点：

1. exception-boundary path 用的是 `all_callee_regs_used`
2. arena path 对 `r12` 还有额外约束

因此，“callee-saved 优化”不应单独做成高优先 form；它更适合作为 `PROLOGUE_TIGHTEN` 的一个 native choice。

### 3.3 冗余 zero-extension / 保守 64-bit lowering

`BPF_END` lowering 在 `:3602-3655`：

- `FROM_LE 16` 发 `movzwl`
- `FROM_LE 32` 发 `mov eax, eax`

这和 `llvm_vs_kernel_jit_disasm_analysis_20260319.md:57-64,303-319` 的结论正好对上：

- 当前 stock-vs-LLVM gap 里，`extract_dense` 的关键差异不是 `bextr`
- 而是 LLVM 会把 whole pipeline 压到 `32-bit`

这是 `NARROW_OPS` 的直接源码证据。

### 3.4 div/mod 过于保守

`BPF_{DIV,MOD}` lowering 在 `:3431-3497`：

- 如果 `dst != rax` 就 `push rax`
- 如果 `dst != rdx` 就 `push rdx`
- imm divisor 统一先搬到 `r11`

这在功能上是稳的，但：

- 保存/恢复范围大
- 没有“只求 quotient / 只求 remainder”的更细分 fast path
- 没有 workload-driven 证据表明当前三类 workload 里它是主 gap

所以它是**已知低效**，但不是这轮 top-5。

### 3.5 缺少短编码 idiom

tail-call path 和其他 hot path 里能看到：

- `add qword ptr [rax], 1`

位置例如 `:786` 和 `:853`。

如果 flags dead，`inc [mem]` 更短；Katran 的 llvmbpf dump里大量是这么做的。

但它属于：

- 低复杂度
- 低单点收益
- 需要 flag liveness guard

因此更像 stock cleanup，不像 top-5 新 form。

## 4. LLVM 的优势里，哪些是当前 taxonomy 没覆盖的

`docs/tmp/llvm_vs_kernel_jit_disasm_analysis_20260319.md` 给出的最重要结论是：

1. 一阶大头仍是 `WIDE_MEM` 和 `ROTATE`，见 `:48-50`
2. `ENDIAN_FUSION` 解释成立，见 `:54-56`
3. `extract_dense` 暴露了一个**新 gap 类别**：`load-width narrowing / partial-width lowering`，见 `:57-64` 和 `:303-319`
4. `simple` 暴露了另一个 taxonomy 外差异：`store coalescing`，见 `:547-549,576-578`
5. `large_mixed_500` 说明还有 whole-function register/layout gap，但那已经超出当前 local canonical form 舒适区

映射到 BpfReJIT：

### 可以比较自然地放进 canonical form framework 的

- `PROLOGUE_TIGHTEN`
- `NARROW_OPS` 的**局部版**
- `ZERO_STORE_FUSION`
- `WIDE_MEM_TREE_BE`

### 需要 verifier facts 或超出当前 v5 形态的

- `BOUNDS_WINDOW`
- `NARROW_OPS` 的跨-block激进版
- whole-function register/layout optimization

## 5. Top-5 新 form 候选

### Ranking

| Rank | Candidate | 当前 workload 证据 | 预计 site 数 | 预计收益 | 复杂度（LOC） | 需要 verifier facts | 当前 v5 fit | 备注 |
| --- | --- | --- | ---: | --- | ---: | --- | --- | --- |
| 1 | `PROLOGUE_TIGHTEN` | 3 个 workload 全命中；Katran/Tracee stock dump直接可见；plan 已量化 prologue surplus `18.5%` | `21` live program entries | 高 | `80-140` | 否 | 部分可做 | 更像“program-entry pseudo-site”；应把 NOP、frame-pointer、save-set 当一个 family 处理 |
| 2 | `NARROW_OPS` | `extract_dense` 明确指出 taxonomy 缺口；Tracee stock dump `252` `movzx`，Katran stock dump `216` `movzx` | `~40-80`（估计） | 中高 | `220-380` | 局部版否；激进版是 | 局部版可做 | 建议先做 local 版本：load-width + 32-bit ALU/compare/zext folding |
| 3 | `ZERO_STORE_FUSION` | Tracee/Katran/Tetragon 都有大块 state init；llvmbpf 已用 `vpcmpeqd/vmovdqu` 或 `vxorps/vmovups` | `~6-12` regions | 中高 | `180-320` | 否 | 可做 | 先做 “zero-store run -> wider scalar stores”，向量版作为 second step |
| 4 | `WIDE_MEM_TREE_BE` | Katran March 20 专项调查已定位 tree LE/BE gaps；当前 live `4 -> 6` start sites 可确认 | `+2` confirmed new sites（另有 `2` site upgrades） | 中 | `120-220` incremental | 否 | 可做 | 当前 workload 主要价值在 Katran；适合直接复用现有 WIDE_MEM substrate |
| 5 | `BOUNDS_WINDOW` | Katran parser / bounds-heavy code最像真实需求；已在 #82 讨论；现有 branch-heavy gap 里还有事实依赖的 guard redundancy | `~10-20` windows（估计） | 高 | `300-500` + facts plumbing | 是 | 不可直接做 | 需要 verifier-fact-backed 扩展，超出当前纯 local v5 舒适区 |

### 为什么不是继续做 `cmov` / `branch-flip`

- Tracee/Tetragon live site 数虽然大，但这是**已知 family**，不是新机会。
- `cmov` 已经被多轮结果证明高度 policy-sensitive。
- `branch-flip` 在 micro attribution 中也不是 LLVM gap 的主解释；`bounds_ladder` 里更大的赢面仍来自 load widening，不是单纯翻转分支。

### 为什么 `div/mod`、`inc/dec` 没进 top-5

#### `DIVMOD_SPECIALIZE`

- 源码里确实保守；
- 但这轮三个 workload 没给出“它是当前主 gap”的直接证据；
- 更适合做 stock cleanup / opportunistic fast path。

#### `INCDEC_SHORTEN`

- Katran llvmbpf dump里很多；
- 但单点收益太小；
- 还要 guard flags liveness；
- 应排在 top-5 之后。

## 6. 最终优先级建议

如果只允许做两项，我建议：

1. `PROLOGUE_TIGHTEN`
2. `NARROW_OPS`

原因：

- 两者都在**当前 workload**里真实出现；
- 都不依赖 VM；
- 都不需要先引入 verifier facts；
- 都比“再扩一个 control-flow form”更接近现在的真实 gap。

如果允许做三到四项：

3. `ZERO_STORE_FUSION`
4. `WIDE_MEM_TREE_BE`

如果允许启动一条更长期的 fact-backed 方向：

5. `BOUNDS_WINDOW`

## Appendix: 关键证据点

- `arch/x86/net/bpf_jit_comp.c:516-566`
  - prologue 固定 NOP + layout NOP
- `arch/x86/net/bpf_jit_comp.c:365-400`
  - callee-saved save/restore substrate
- `arch/x86/net/bpf_jit_comp.c:3431-3497`
  - div/mod save/restore
- `arch/x86/net/bpf_jit_comp.c:3602-3655`
  - `movzwl` / `mov eax,eax` zero-extension paths
- `docs/tmp/katran_storepair_stock_jited_20260320.txt:4-14`
  - Katran stock prologue NOP + save-set
- `docs/tmp/katran_storepair_stock_jited_20260320.txt:49-80`
  - Katran stock `addq $1` + scalar zero-init + byte ladder
- `docs/tmp/katran_wide_load_investigation_20260320.md:5-33,97-114`
  - Katran current `wide` coverage与 tree/BE gap
- `docs/tmp/llvm_vs_kernel_jit_disasm_analysis_20260319.md:48-64`
  - LLVM vs kernel 一阶总结
- `docs/tmp/llvm_vs_kernel_jit_disasm_analysis_20260319.md:303-319`
  - `extract_dense` = `NARROW_OPS` 证据
- `docs/tmp/llvm_vs_kernel_jit_disasm_analysis_20260319.md:547-578`
  - `simple` = store coalescing / zero-store fusion 证据
