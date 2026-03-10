# POC v2 设计一致性审查

日期：2026-03-09

审查范围：

- 内核侧：`vendor/linux/kernel/bpf/jit_directives.c`、`vendor/linux/include/linux/bpf_jit_directives.h`、`vendor/linux/arch/x86/net/bpf_jit_comp.c`、`vendor/linux/kernel/bpf/verifier.c`、`vendor/linux/kernel/bpf/syscall.c`、`vendor/linux/include/uapi/linux/bpf.h`、`vendor/linux/kernel/bpf/core.c`、`vendor/linux/include/linux/bpf.h`
- 用户侧：`micro/tools/directive_hint.c`、`micro/runner/src/kernel_runner.cpp`、`micro/programs/cmov_select.bpf.c`
- 设计/验证文档：`docs/kernel-jit-optimization-plan.md`、`docs/tmp/poc-v2-implementation-summary.md`、`docs/tmp/poc-v2-validation-report.md`、`docs/tmp/poc-v2-validation-results.json`

## 总体结论

当前 POC v2 **基本忠实于“狭义 POC v2”目标**：它确实通过 sealed memfd 把 directive blob 传入内核，verifier 只做 pattern 合法性验证和站点定位，不改写 BPF 指令流；真正的 `cmovcc` 发射发生在 x86 JIT `do_jit()` 内，因此 `cmov_select` 已经从 v1 的错误 verifier rewrite，转成了真正的 JIT 后端 lowering。这个结论既能从代码结构看出来，也被验证结果中的 `xlated_prog_len` 不变、`jited_prog_len` 改变所支撑（`docs/tmp/poc-v2-validation-report.md:13-18`，`docs/tmp/poc-v2-validation-results.json:473-484`，`docs/tmp/poc-v2-validation-results.json:707-718`）。

但它**没有完全达到更宽泛设计文档里描述的 Hybrid 架构**。当前实现没有 digest binding、没有 CPU contract、没有真正的 “normalized select plan”、没有实际的 directive logging，用户态 payload 也没有承载 profitability/policy 信息，仍然只是“找站点 + 请求 x86 cmov lowering”的最小版本（`docs/kernel-jit-optimization-plan.md:238-249`，`docs/kernel-jit-optimization-plan.md:438-442`，`vendor/linux/kernel/bpf/jit_directives.c:208-221`，`micro/tools/directive_hint.c:190-199`）。

另外，我确认了一个明确的功能缺口：**verifier 允许 `BPF_X` 和 `BPF_K` 两类 diamond compare，但 x86 JIT 只在 `*_K` 条件跳转分支上查 diamond directive**。这意味着“寄存器比较的 diamond pattern”会被 verifier 接受，却不会被 JIT 降成 `cmov`。这是当前实现与文档叙述不完全一致的最重要 bug（`vendor/linux/kernel/bpf/jit_directives.c:27-51`，`vendor/linux/kernel/bpf/jit_directives.c:72-104`，`vendor/linux/arch/x86/net/bpf_jit_comp.c:2922-2946`，`vendor/linux/arch/x86/net/bpf_jit_comp.c:2964-2992`）。

## 单独列出的问题

### 明确 bug / 缺口

1. `diamond + BPF_X` 形状会被 verifier 接受，但不会触发 x86 JIT 的 `cmov` 发射。
   - verifier 的 `bpf_jit_is_cmov_cond_jump()` 同时接受 `BPF_X`/`BPF_K`（`vendor/linux/kernel/bpf/jit_directives.c:27-51`），`bpf_jit_cmov_select_match_diamond()` 也不限制 source type（`vendor/linux/kernel/bpf/jit_directives.c:72-104`）。
   - 但 JIT 中对 diamond directive 的查找只出现在 `*_K` 条件跳转 case（`vendor/linux/arch/x86/net/bpf_jit_comp.c:2964-2992`）；`*_X` case 直接走普通 `cmp` + `jcc`（`vendor/linux/arch/x86/net/bpf_jit_comp.c:2922-2946`）。

2. `BPF_F_JIT_DIRECTIVES_LOG` 已定义，但没有实际日志实现。
   - UAPI 有该 flag（`vendor/linux/include/uapi/linux/bpf.h:1464-1466`），load 时也只做掩码校验（`vendor/linux/kernel/bpf/jit_directives.c:248-249`），但内核里没有消费它的日志路径。
   - 结果是验证报告里的 “applied site” 只能靠长度变化间接推断，而不是由内核直接报告（`docs/tmp/poc-v2-validation-report.md:20-25`）。

### 需要澄清的语义差异

1. “fail-closed” 只对 verifier legality failure 成立，不对所有错误都成立。
   - pattern 不匹配/跨 subprog/interior edge/冲突时，directive 会被静默丢弃，程序仍走普通 JIT（`vendor/linux/kernel/bpf/jit_directives.c:379-410`）。
   - 但 malformed blob / 非法 memfd / header 错误会直接导致 `BPF_PROG_LOAD` 失败（`vendor/linux/kernel/bpf/jit_directives.c:248-329`，`vendor/linux/kernel/bpf/syscall.c:3046-3053`）。
   - 更进一步，若 JIT 发射函数返回错误，x86 JIT 会整体失败并回退解释器，而不是“普通 JIT”（`vendor/linux/arch/x86/net/bpf_jit_comp.c:2145-2148`，`vendor/linux/arch/x86/net/bpf_jit_comp.c:2990-2992`，`vendor/linux/arch/x86/net/bpf_jit_comp.c:4235-4251`）。

2. 当前实现更像“最小 x86 POC”，不是宽文档里的完整 Hybrid substrate。

## A. 架构正确性

### A1. POC v2 是否真正做到了“不修改 BPF 字节码，只改变原生代码”？

结论：**是，狭义上成立。**

1. verifier hook 只做验证，不做重写。
   - verifier 只在 `ret == 0` 后调用 `bpf_jit_directives_validate(env)`（`vendor/linux/kernel/bpf/verifier.c:26109-26110`）。
   - `bpf_jit_directives_validate()` 只会：
     - 清空/重建 `flags`、`subprog_idx`、`insn_idx`、`validated_cnt`（`vendor/linux/kernel/bpf/jit_directives.c:368-377`）
     - 用 `orig_idx` 找到当前指令位置（`vendor/linux/kernel/bpf/jit_directives.c:177-187`）
     - 对 pattern 做 legality 检查并记录 metadata（`vendor/linux/kernel/bpf/jit_directives.c:383-405`）
   - 它没有修改 `prog->insnsi`、`prog->len` 或调用任何 patch/rewrite helper。与 v1 的 verifier rewrite 本质不同。

2. `cmov` 发射发生在 JIT 阶段，不在 verifier 阶段。
   - compact 形状在 `do_jit()` 主循环顶部查 directive 并直接发 `emit_bpf_cmov_select_compact()`（`vendor/linux/arch/x86/net/bpf_jit_comp.c:2137-2173`）。
   - diamond 形状在 cond-jump 分支里查 directive 并发 `emit_bpf_cmov_select()`（`vendor/linux/arch/x86/net/bpf_jit_comp.c:2964-3017`）。
   - 真正的 x86 `cmov` 编码由 `emit_cmov_reg()` 发射（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1086-1095`），条件码由 `bpf_jmp_to_x86_cmov()` 选择（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1174-1209`）。

3. 验证结果也符合这个结构判断。
   - `cmov_select` 的 `xlated_prog_len` 在有无 directive 下相同，`jited_prog_len` 从 `4168` 变成 `4167`（`docs/tmp/poc-v2-validation-report.md:13-18`，`docs/tmp/poc-v2-validation-results.json:473-484`，`docs/tmp/poc-v2-validation-results.json:707-718`）。

### A2. 这个优化是否是用户态无法做的？

结论：**作为“保持 BPF 不变、仅改变 native lowering”的优化，它必须在 JIT 后端完成。**

理由：

1. 用户态工具只负责“找候选 site + 生成 blob”，不负责 native codegen。
   - `directive_hint` 只是匹配 pattern、写 header/record/payload（`micro/tools/directive_hint.c:202-288`）。
   - payload 当前只有全 0 的 `flags/reserved`，并不携带任何可直接生成机器码的内容（`micro/tools/directive_hint.c:190-199`）。
   - manual loader 只是把 sealed memfd fd 填进 `BPF_PROG_LOAD`（`micro/runner/src/kernel_runner.cpp:429-447`，`micro/runner/src/kernel_runner.cpp:515-537`）。

2. eBPF ISA 本身没有“条件移动”这一 native opcode 选择接口。
   - 这里真正改变的是 x86 `cmp/test + mov + cmovcc` 与 `cmp/test + jcc + mov` 的 lowering 选择（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1313-1352`，`vendor/linux/arch/x86/net/bpf_jit_comp.c:1377-1420`）。
   - 这个选择依赖 x86 条件码和 `CMOVcc` 编码（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1086-1095`，`vendor/linux/arch/x86/net/bpf_jit_comp.c:1174-1209`），不是用户态在 BPF 字节码层面可以“等价表达”的同一件事。

3. 设计文档自己也把这个标准写得很明确。
   - “如果用户态也能做同样的事，就在错误的层；`cmov_select` JIT lowering 是只有 JIT 能做的” (`docs/kernel-jit-optimization-plan.md:488-495`)。

### A3. `xlated_prog_len` 不变 + `jited_prog_len` 改变 的设计不变量是否成立？

结论：**在当前验证样本 `cmov_select` 上成立，而且从代码结构上看也应该成立。**

1. 代码结构上：
   - directive state 只挂在 `bpf_prog_aux->jit_directives`，不进入 BPF 指令流（`vendor/linux/include/linux/bpf.h:1708-1712`，`vendor/linux/include/linux/bpf_jit_directives.h:12-25`）。
   - verifier 阶段只写 metadata（`vendor/linux/kernel/bpf/jit_directives.c:360-405`）。
   - `jited_len` 由 JIT 最终写回（`vendor/linux/arch/x86/net/bpf_jit_comp.c:4329-4331`）。

2. 实测上：
   - manual no-directives：`jited_prog_len=4168`、`xlated_prog_len=7480`（`docs/tmp/poc-v2-validation-results.json:473-484`）。
   - manual with directives：`jited_prog_len=4167`、`xlated_prog_len=7480`（`docs/tmp/poc-v2-validation-results.json:707-718`）。

## B. 安全性审查

### B1. sealed memfd 验证是否正确（`F_SEAL_WRITE | F_SEAL_GROW | F_SEAL_SHRINK`）？

结论：**正确。**

1. 用户态 memfd 构造：
   - `memfd_create(..., MFD_ALLOW_SEALING)`（`micro/runner/src/kernel_runner.cpp:433-435`）
   - 写入 blob 后加 `F_SEAL_WRITE | F_SEAL_GROW | F_SEAL_SHRINK`（`micro/runner/src/kernel_runner.cpp:442-445`）

2. 内核态验证：
   - `memfd_fcntl(file, F_GET_SEALS, 0)` 获取 seals（`vendor/linux/kernel/bpf/jit_directives.c:15-24`）
   - 必须至少包含这三种 seal（`vendor/linux/kernel/bpf/jit_directives.c:23-24`）

3. 备注：
   - 当前**没有**要求 `F_SEAL_SEAL`。这不是 correctness bug，因为写、扩容、缩容已经被禁止；但若想把 seal 集合本身也冻结，`F_SEAL_SEAL` 可以作为额外 hardening。

### B2. blob 大小限制是否合理？

结论：**合理。**

1. 内核把 blob 上限固定为 `64 KiB`（`vendor/linux/kernel/bpf/jit_directives.c:13`，`vendor/linux/kernel/bpf/jit_directives.c:262-265`）。
2. 同时做了：
   - header 最小长度检查（`vendor/linux/kernel/bpf/jit_directives.c:283-285`）
   - `rec_cnt * sizeof(rec)` 的 overflow 检查（`vendor/linux/kernel/bpf/jit_directives.c:297-302`）
   - `expected_len == blob_len` 检查（`vendor/linux/kernel/bpf/jit_directives.c:304-308`）
3. 以当前 `16B` record 计，`64 KiB` 足够容纳约 `4096` 条记录，已经远大于当前 POC 的需求，同时也避免了无限制的内核分配。

### B3. fail-closed 是否正确实现？

结论：**部分正确。**

1. 对 pattern/legality validation 而言，确实是 fail-closed。
   - 不匹配、跨 subprog、interior edge、冲突都会 `continue` 丢弃 directive，不报错（`vendor/linux/kernel/bpf/jit_directives.c:388-401`）。
   - `prog->blinded` 时 lookup 直接返回 `NULL`，静默回退普通 JIT（`vendor/linux/kernel/bpf/jit_directives.c:424-425`）。
   - 这与“验证失败不影响普通 JIT”一致。

2. 但对 transport/parser 错误，不是 fail-closed，而是 hard-fail。
   - 非 sealed memfd、非法 header、非法 record 直接让 `bpf_jit_directives_load()` 返回错误（`vendor/linux/kernel/bpf/jit_directives.c:248-329`）。
   - `BPF_PROG_LOAD` 随即失败（`vendor/linux/kernel/bpf/syscall.c:3046-3053`）。

3. 对 JIT 发射内部错误，也不是“回退普通 JIT”，而是“回退解释器”。
   - 这是比文档叙述更强烈的退化路径（`vendor/linux/arch/x86/net/bpf_jit_comp.c:4235-4251`）。

### B4. 是否有潜在的内核安全问题（越界访问、信息泄露等）？

结论：**没有发现明显的内核内存安全问题。**

支撑点：

1. blob 读取前后边界检查充分。
   - 文件大小、header、record 数、最终长度都检查（`vendor/linux/kernel/bpf/jit_directives.c:257-308`）。

2. record 和 payload 校验严格。
   - `site_idx < insn_cnt`、`reserved == 0`（`vendor/linux/kernel/bpf/jit_directives.c:223-230`）
   - `cmov_select` payload 里的 `flags/reserved` 必须为 0（`vendor/linux/kernel/bpf/jit_directives.c:208-221`）

3. pattern 匹配有边界保护。
   - diamond 需要 `idx + 3 < insn_cnt`（`vendor/linux/kernel/bpf/jit_directives.c:78-79`）
   - compact 需要 `idx > 0` 且 `idx + 1 < insn_cnt`（`vendor/linux/kernel/bpf/jit_directives.c:112-113`）

4. JIT 最终 image pass 对融合区有长度一致性断言，能挡住 `addrs[]` 不一致导致的错误写入。
   - compact 校验 `region_start + ilen == addrs[i + 2]`（`vendor/linux/arch/x86/net/bpf_jit_comp.c:2156-2160`）
   - diamond 校验 `region_start + ilen == addrs[i + 3]`（`vendor/linux/arch/x86/net/bpf_jit_comp.c:3000-3004`）
   - 普通路径也校验 `proglen + ilen == addrs[i]`（`vendor/linux/arch/x86/net/bpf_jit_comp.c:3189-3206`）

5. 仍有两个“不是安全漏洞，但会影响鲁棒性”的点：
   - 缺少 digest binding，blob 没有与程序内容强绑定（`docs/kernel-jit-optimization-plan.md:242-249` 对比 `vendor/linux/include/uapi/linux/bpf.h:1475-1493`）。
   - 缺少日志，accepted/applied 站点难以直接审计。

## C. 功能正确性

### C1. diamond pattern 匹配（`jcc+2 -> mov + ja+1 -> mov`）是否正确？

结论：**matcher 本身正确，但 end-to-end 实现不完整。**

1. kernel matcher 的形状定义是正确的。
   - 条件跳转偏移必须是 `2`（`vendor/linux/kernel/bpf/jit_directives.c:86-87`）
   - 中间必须是 `JA +1`（`vendor/linux/kernel/bpf/jit_directives.c:90-92`）
   - 两个 arm 必须都是 simple mov、同一目标寄存器、同一位宽（`vendor/linux/kernel/bpf/jit_directives.c:88-103`）

2. JIT 发射函数 `emit_bpf_cmov_select()` 的语义也正确。
   - 先准备 “branch taken arm” 的源，再把 fallthrough arm 作为默认值，最后用原条件发 `cmov`（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1336-1350`）。

3. 但 end-to-end 存在实现缺口。
   - verifier 会验证 `BPF_X`/`BPF_K` 的 diamond（`vendor/linux/kernel/bpf/jit_directives.c:27-51`，`vendor/linux/kernel/bpf/jit_directives.c:72-104`）。
   - x86 JIT 只在 `*_K` cond-jump case 做 diamond lookup（`vendor/linux/arch/x86/net/bpf_jit_comp.c:2964-2992`），`*_X` 不会触发 directive（`vendor/linux/arch/x86/net/bpf_jit_comp.c:2922-2946`）。
   - 所以应评价为：**diamond matcher 正确，但 JIT consumer 只完整覆盖了 `*_K` diamond。**

### C2. compact pattern 匹配（`mov -> jcc+1 -> mov`）是否正确？

结论：**正确，而且这正是当前 benchmark 的真实正例。**

1. 用户态和内核态 matcher 基本一致。
   - 用户态：`match_cmov_select_compact()`（`micro/tools/directive_hint.c:145-179`）
   - 内核态：`bpf_jit_cmov_select_match_compact()`（`vendor/linux/kernel/bpf/jit_directives.c:106-134`）

2. 当前 benchmark 源码就是为了制造这种窄形状。
   - `cmov_select_pick()` 被刻意放在单独的 `__noinline` helper 中（`micro/programs/cmov_select.bpf.c:25-38`）
   - 外层 128 次重复调用这个 helper（`micro/programs/cmov_select.bpf.c:40-51`，`micro/programs/cmov_select.bpf.c:69-76`）

3. 实际编译出来的 BPF 目标程序也确实是这个形状。
   - 本地 `llvm-objdump` 看到 `cmov_select_pick` 降成：
     - `r0 = r3`
     - `if r1 > r2 goto +1`
     - `r0 = r4`
   - 这与实现摘要中对 compact shape 的描述一致（`docs/tmp/poc-v2-implementation-summary.md:39-47`）。

### C3. `cmovcc` 发射的 x86 编码是否正确？

结论：**正确。**

1. `emit_cmov_reg()` 明确按 `CMOVcc r, r/m` 形式发射 `0F <op> /r`（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1086-1095`）。
2. `bpf_jmp_to_x86_cmov()` 的条件码映射与 x86 语义一致。
   - unsigned：`JGT->CMOVA`、`JLT->CMOVB`、`JGE->CMOVAE`、`JLE->CMOVBE`（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1183-1194`）
   - signed：`JSGT->CMOVG`、`JSLT->CMOVL`、`JSGE->CMOVGE`、`JSLE->CMOVLE`（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1195-1205`）
3. `emit_bpf_jmp_cmp()` 的 compare/test 与普通跳转路径复用同一语义（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1212-1295`）。

### C4. `addrs[]` bookkeeping 是否正确（之前有 bug，是否已修复）？

结论：**当前代码看起来已经修复。**

1. compact 融合区现在显式更新了四个地址点：
   - `addrs[i - 1]`、`addrs[i]`、`addrs[i + 1]` 都指向 region start
   - `addrs[i + 2]` 指向 region end（`vendor/linux/arch/x86/net/bpf_jit_comp.c:2165-2169`）
2. 同时 final image pass 会验证 `region_start + ilen == addrs[i + 2]`（`vendor/linux/arch/x86/net/bpf_jit_comp.c:2156-2160`）。
3. diamond 路径的 bookkeeping 也自洽（`vendor/linux/arch/x86/net/bpf_jit_comp.c:3000-3013`）。
4. 验证报告也明确说明这里修过 bug，并指出它曾导致 subprog call target corruption（`docs/tmp/poc-v2-validation-report.md:26-35`）。

### C5. 条件码映射（BPF -> x86）是否正确？

结论：**正确。**

1. 普通跳转的 `bpf_jmp_to_x86_cond()` 映射（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1135-1172`）和 `cmov` 的 `bpf_jmp_to_x86_cmov()` 映射（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1174-1209`）是对应的。
2. `BPF_JSET` 没有被纳入 `cmov_select` matcher，这是一个有意收窄的 contract，而不是遗漏。
   - matcher 只接受 `JEQ/JNE/JGT/JLT/JGE/JLE/JSGT/JSLT/JSGE/JSLE`（`vendor/linux/kernel/bpf/jit_directives.c:36-49`，`micro/tools/directive_hint.c:66-79`）。

### C6. 条件码反转逻辑是否正确？

结论：**正确。**

1. compact lowering 先做 default move，再只在“原分支不跳转”的情况下覆盖，因此必须反转条件（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1392-1407`）。
2. `bpf_jmp_invert()` 的反转表是标准逻辑反转（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1097-1133`）。
3. 对当前 `cmov_select_pick()` 例子尤其合理：
   - BPF 代码是 `if r1 > r2 goto +1; r0 = r4`
   - 默认值已经是 `r0 = r3`
   - 所以需要在 `r1 <= r2` 时做 `cmov`，即把 `JGT` 反转成 `JLE`。

## D. 性能分析

### D1. 验证结果显示 `cmov` 比分支慢 13.2%，原因是什么？

结论：**现有数据只能支持“合理推断”，不能支持“已证明因果”。最可能的原因是 workload 不够不规则、收益面太小，而 `cmov` 又引入了依赖链。**

证据与推断：

1. 真正公平的比较是 manual no-directives vs manual with directives。
   - 报告明确说明 same-loader manual 对比才公平（`docs/tmp/poc-v2-validation-report.md:38-42`）。
   - 对应中位数是 `742 ns -> 840 ns`，约 `+13.2%`（`docs/tmp/poc-v2-validation-report.md:42`，`docs/tmp/poc-v2-validation-results.json:473-484`，`docs/tmp/poc-v2-validation-results.json:707-718`）。

2. 这个 workload 并不是“随机不可预测分支”。
   - 输入生成器按 index parity 强制比较结果交替：偶数 index 令 `lhs <= rhs`，奇数 index 令 `lhs > rhs`（`micro/input_generators.py:675-695`）。
   - 外层运行顺序正好是 `0..127`（`micro/programs/cmov_select.bpf.c:69-76`），所以动态分支结果是高度规则的交替序列，而不是随机熵输入。
   - 这种模式是否“完全可预测”取决于具体分支预测器，但它显然比随机 workload 更结构化。

3. 这里只有一个静态 site，代码尺寸收益极小。
   - `directive_hint` 只找到 `1` 个 site（`docs/tmp/poc-v2-validation-report.md:15-18`，`docs/tmp/poc-v2-validation-results.json:11-17`）。
   - `jited_prog_len` 只减了 `1` 字节（`docs/tmp/poc-v2-validation-report.md:15-18`）。
   - 这意味着前端/I-cache/code-size 收益非常有限。

4. `cmov` 自己也有成本。
   - compact lowering 是 `default mov + cmp + cmov`（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1392-1419`），它会让结果寄存器依赖 flags 和 override source。
   - 若原本分支已经被较好预测，那么 `cmov` 的消分支收益可能抵不过依赖链成本。

5. 目前验证结果没有 perf counters。
   - JSON 里 `perf_counters_meta.collected` 为 false（如 `docs/tmp/poc-v2-validation-results.json:50-57`）。
   - 所以当前不能把 slowdown 归因为某个具体微架构事件，只能给出上述合乎代码和 workload 的推断。

### D2. `jited_prog_len` 只变了 1 字节（`4168 -> 4167`），合理吗？

结论：**合理，而且和当前 helper 的寄存器分配、短跳转形式高度一致。**

对 `cmov_select_pick()` 的 compact 形状，默认 lowering 大致是：

1. `mov r0, r3`
2. `cmp r1, r2`
3. short `jcc +disp8`
4. `mov r0, r4`

而 directive lowering 是：

1. `mov r0, r3`
2. `cmp r1, r2`
3. `cmovcc r0, r4`

结合 x86 JIT 的寄存器映射：

- `BPF_REG_0 -> RAX`
- `BPF_REG_1 -> RDI`
- `BPF_REG_2 -> RSI`
- `BPF_REG_3 -> RDX`
- `BPF_REG_4 -> RCX`

见 `vendor/linux/arch/x86/net/bpf_jit_comp.c:182-187`。

对于这些都是 legacy reg 的情况：

- `mov reg, reg` 是 3 字节（`vendor/linux/arch/x86/net/bpf_jit_comp.c:976-990`）
- `cmp reg, reg` 是 3 字节（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1240-1242`）
- short `jcc` 是 2 字节；JIT 也会在 offset 足够小时用 `imm8` 形式（`vendor/linux/arch/x86/net/bpf_jit_comp.c:3026-3044`）
- `cmov reg, reg` 是 4 字节（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1086-1095`）

所以默认路径约 `3 + 3 + 2 + 3 = 11` 字节，`cmov` 路径约 `3 + 3 + 4 = 10` 字节，**正好差 1 字节**。这与实测 `4168 -> 4167` 完全吻合。

### D3. 只找到 1 个 directive site，是不是 pattern matcher 太严格了？

结论：**对当前 benchmark 来说，不是。1 个 site 是设计使然；对其它程序来说，matcher 确实是刻意偏严格。**

1. 当前 benchmark 把 select 人为集中到一个 `__noinline` helper `cmov_select_pick()` 中（`micro/programs/cmov_select.bpf.c:25-38`）。
2. 外层 128 次执行的是同一个静态 site 的重复调用（`micro/programs/cmov_select.bpf.c:40-51`，`micro/programs/cmov_select.bpf.c:69-76`）。
3. 所以“只有 1 个静态 directive site”本来就是合理结果。
4. 实现摘要也明确写了当前正例就是这个 narrow helper，`directive_hint` 对 `cmov_select` 找到 `1` 个 site 是预期行为（`docs/tmp/poc-v2-implementation-summary.md:35-55`）。
5. 但与此同时，matcher 的确很严格。
   - 它只接受纯 local、pure assignment 的 diamond / compact 形状（`vendor/linux/kernel/bpf/jit_directives.c:72-152`，`micro/tools/directive_hint.c:104-179`）。
   - 这也是 `binary_search`、`switch_dispatch` 当前得到 `0` 个 site 的原因之一（`docs/tmp/poc-v2-implementation-summary.md:49-55`，`docs/tmp/poc-v2-validation-report.md:43-50`）。

### D4. `cmov_select` benchmark 的分支是否可预测（导致 `cmov` 反而更慢）？

结论：**是，至少它不是“故意不可预测”的 workload。**

1. 输入生成器按偶奇交替构造比较关系（`micro/input_generators.py:681-695`）。
2. benchmark 以固定顺序消费这些值（`micro/programs/cmov_select.bpf.c:69-76`）。
3. 因此动态分支结果是有规则的 alternating pattern。

这不等于“所有 CPU 上都容易预测”，但至少说明：

- 当前 workload 不是随机 compare；
- 它不能代表 `cmov` 最有优势的“高度不可预测、mispredict 成本主导”的情况。

### D5. 有没有办法让 `cmov` 在某些 workload 下确实更快？

结论：**有，但当前 POC 还没有把这些条件编码进 policy。**

可行方向：

1. 让 compare 结果接近随机，而不是 index-parity 交替。
   - 例如用真实输入数据驱动 compare，而不是离线生成的规则序列。

2. 增加 hot path 中的 select 密度，减少“一个 site 只省 1 字节”的情况。
   - 当前是一个 helper 站点被重复调用；如果目标是观察 native codegen 差异，内联多个独立 select site 会更有辨识度。

3. 选择 mispredict 成本更高、而 `cmov` 依赖代价相对较低的 CPU/workload 组合。
   - 这正是设计文档把 `cmov_select` 定位成 policy-sensitive directive 的原因（`docs/kernel-jit-optimization-plan.md:193-196`）。

4. 把“是否启用 cmov”做成真正的 policy，而不是当前这样“只要匹配就一律请求”。
   - 现在 payload 里没有 profitability/policy bit，只有全 0 的占位结构（`vendor/linux/kernel/bpf/jit_directives.c:208-221`，`micro/tools/directive_hint.c:190-199`）。

## E. 与设计文档的一致性

### E1. 实现是否与 `kernel-jit-optimization-plan.md` 中描述的一致？

结论：**与 P1 / POC v2 的狭义目标一致；与文档更上层的完整 Hybrid 架构不完全一致。**

一致的部分：

1. P1 修正后的目标是“真正的 JIT-level directive：BPF 不变，只改 native emission”（`docs/kernel-jit-optimization-plan.md:488-511`）。
2. `cmov_select` 被文档定义为“只有 JIT 能做的 lowering choice”（`docs/kernel-jit-optimization-plan.md:492-500`）。
3. 当前实现正是：
   - `BPF_PROG_LOAD(jit_directives_fd)` transport（`vendor/linux/kernel/bpf/syscall.c:3046-3055`）
   - verifier legality check（`vendor/linux/kernel/bpf/jit_directives.c:360-405`）
   - x86 `cmovcc` emitter（`vendor/linux/arch/x86/net/bpf_jit_comp.c:1313-1420`，`vendor/linux/arch/x86/net/bpf_jit_comp.c:2137-2173`，`vendor/linux/arch/x86/net/bpf_jit_comp.c:2964-3017`）

不一致的部分：

1. 文档更宽的架构写了 `Digest binding + CPU contract + Fail-closed fallback + logging`（`docs/kernel-jit-optimization-plan.md:238-249`），当前实现没有 digest binding、没有 CPU contract、没有 logging。
2. 文档把 `cmov_select` 描述成 “verifier 识别 diamond -> 内部 select 抽象 -> JIT 选择 cmovcc/csel/branch” 的 Hybrid 例子（`docs/kernel-jit-optimization-plan.md:438-442`），当前实现没有内部 normalized select plan，只记录了 `subprog_idx/insn_idx`（`vendor/linux/include/linux/bpf_jit_directives.h:12-25`）。
3. 文档的 P1 还写了第二个 JIT directive、kernel-fixed baselines 等任务（`docs/kernel-jit-optimization-plan.md:500-506`），当前都未实现。

### E2. 实现是否与 `poc-v2-implementation-summary.md` 中描述的一致？

结论：**大体一致，但有一个重要例外。**

一致的部分：

1. summary 说 userspace 用 sealed memfd 传 blob（`docs/tmp/poc-v2-implementation-summary.md:15-20`），这与 runner + syscall + loader 实现一致（`micro/runner/src/kernel_runner.cpp:429-447`，`micro/runner/src/kernel_runner.cpp:515-537`，`vendor/linux/kernel/bpf/syscall.c:3046-3055`）。
2. summary 说 verifier 只做合法性验证并记录 validated site（`docs/tmp/poc-v2-implementation-summary.md:17-22`），代码确实如此（`vendor/linux/kernel/bpf/jit_directives.c:360-405`）。
3. summary 说当前正例是 compact shape（`docs/tmp/poc-v2-implementation-summary.md:39-47`），而当前 benchmark/helper 也确实是这个形状（`micro/programs/cmov_select.bpf.c:25-38`）。
4. summary 说 `directive_hint` 当前对 `cmov_select` 找到 `1` 个 site（`docs/tmp/poc-v2-implementation-summary.md:49-55`），验证结果也一致（`docs/tmp/poc-v2-validation-results.json:11-17`）。

不一致的部分：

1. summary 写“kernel-side validator and x86 JIT still support the canonical four-insn diamond form”（`docs/tmp/poc-v2-implementation-summary.md:47-48`）。
2. 当前代码只对 `*_K` diamond 真正做了 JIT lookup（`vendor/linux/arch/x86/net/bpf_jit_comp.c:2964-2992`），对 `*_X` diamond 没有。
3. 因此“x86 JIT 支持 canonical diamond form”这句话现在只能算**部分成立**。

### E3. 有哪些设计文档中描述的功能没有实现？

1. `BPF_F_JIT_DIRECTIVES_LOG` 的实际日志通路没有实现。
   - 文档提到 logging（`docs/kernel-jit-optimization-plan.md:249`），UAPI 也定义了 flag（`vendor/linux/include/uapi/linux/bpf.h:1464-1466`），但代码没有真正输出 directive 日志。

2. digest binding 没有实现。
   - 文档架构里把它列为 kernel legality plane 的组成部分（`docs/kernel-jit-optimization-plan.md:242-247`），当前 blob header 只有 `magic/version/rec_size/rec_cnt/insn_cnt`（`vendor/linux/include/uapi/linux/bpf.h:1475-1493`）。

3. CPU contract / CPU feature binding 没有实现。
   - 文档架构中有这个概念（`docs/kernel-jit-optimization-plan.md:242-249`），当前 payload 为空占位，没有 CPU/workload policy 字段（`vendor/linux/kernel/bpf/jit_directives.c:208-221`，`micro/tools/directive_hint.c:190-199`）。

4. Hybrid 所需的 normalized select plan 没有实现。
   - 当前 verifier 只记录站点，不构造抽象 plan（`vendor/linux/kernel/bpf/jit_directives.c:402-405`）。

5. 第二个 JIT directive 没有实现。
   - 文档列了 `lea_fusion` 或 `rotate_fusion` 作为下一步（`docs/kernel-jit-optimization-plan.md:500-503`）。

6. kernel-fixed baseline 不是实现功能，但仍未完成，导致论文层面的 policy 论证还不充分（`docs/kernel-jit-optimization-plan.md:505-506`）。

### E4. 有哪些实现的功能在设计文档中没有描述？

1. **compact pattern 支持**是当前实现里很重要的实际增强。
   - 宽计划文档的 P1 描述更像 canonical diamond（`docs/kernel-jit-optimization-plan.md:500`），但当前代码和 summary 都额外支持 `mov; jcc+1; mov` 的 compact 形状（`vendor/linux/kernel/bpf/jit_directives.c:106-152`，`vendor/linux/arch/x86/net/bpf_jit_comp.c:1354-1420`，`docs/tmp/poc-v2-implementation-summary.md:39-47`）。

2. **blinded path 的静默禁用**在实现里是明确存在的。
   - `bpf_jit_directive_lookup()` 对 `prog->blinded` 直接返回 `NULL`（`vendor/linux/kernel/bpf/jit_directives.c:424-425`）。
   - 这在宽计划文档里有原则性提及（`docs/kernel-jit-optimization-plan.md:541`），但在 POC v2 summary 里没有展开说明。

3. **userspace manual loader 的兼容性处理**没有出现在架构文档里。
   - 例如 local `BPF_PROG_LOAD` layout 和 `ENOSPC` 时关闭 verifier log 重试（`micro/runner/src/kernel_runner.cpp:248-287`，`micro/runner/src/kernel_runner.cpp:544-581`）。

## 总体评价

如果按“**POC v2 要证明自己不是 v1 那种 verifier rewrite，而是真正的 JIT-level directive**”这个标准来打分，我认为当前实现是**忠实的**。核心证据链完整：

1. directive blob 通过 sealed memfd 传入；
2. verifier 只做合法性验证和站点定位；
3. x86 JIT 在 `do_jit()` 中消费 validated site 并发射 `cmovcc`；
4. `xlated_prog_len` 不变，而 `jited_prog_len` 变化。

但如果按“**设计文档完整的 Hybrid / legality-plane / policy-plane 架构**”来打分，它还只是一个**最小可工作的 x86 POC**。缺少 digest binding、CPU contract、normalized select plan、logging、第二个 directive，也还没有把 policy-sensitive 的故事做完整。

## 建议改进

1. 先修复 `diamond + BPF_X` 的 JIT consumer 缺口。
   - 这是当前最直接、最明确的功能 bug。

2. 明确 fail-closed 语义边界。
   - 若目标真是“任何 directive 相关失败都不影响普通 JIT”，则 parser/load 错误和 JIT emitter 内部错误的处理策略需要重新定义；否则应在文档里明确区分 “legality failure” 与 “transport failure”。

3. 实现或删除 `BPF_F_JIT_DIRECTIVES_LOG`。
   - 当前它是一个死 flag。

4. 若要对齐宽设计文档，应补齐至少一项：
   - digest binding
   - CPU/policy contract
   - normalized select plan
   - 第二个纯 JIT directive

5. 重新设计 `cmov_select` 的评测 workload。
   - 当前输入是规则交替，site 只有一个，代码尺寸只省 1 字节，不足以证明 `cmov` 的 policy-sensitive 优势。

## 最终判断

**判断：实现忠实于“狭义 POC v2”，但不完全忠实于“广义设计文档架构”。**

- 对 v1 的根本性修正：**成功**
- 对 “不改 BPF、只改 native lowering” 的证明：**成功**
- 对宽文档 Hybrid 架构的实现完成度：**明显不足**
- 当前最需要修的实现问题：**`diamond + BPF_X` 不会实际 lower 成 `cmov`**
