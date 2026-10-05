# BpfReJIT 内核代码必要性审计

日期: 2026-03-19  
仓库: `vendor/linux-framework`  
分支: `jit-directive-v5`

## 范围与方法

本报告审计的是 `vendor/linux-framework` 当前工作树相对 `master` 的全部改动，不只看已提交内容。

我实际查看了两组 diff:

- `git -C vendor/linux-framework diff master..HEAD`
- `git -C vendor/linux-framework diff master`

其中 `master..HEAD` 只覆盖已提交改动，无法覆盖未提交改动；下面所有总量和判断都以当前工作树的 `git diff master` 为准。

当前工作树相对 `master` 的精确 diff 总量:

- `6951` 行新增
- `193` 行删除
- `6758` 行净新增代码

本次审计覆盖文件:

| 文件 | 当前 diff footprint |
| --- | ---: |
| `kernel/bpf/jit_directives.c` | `4038` |
| `arch/x86/net/bpf_jit_comp.c` | `+2191/-176` |
| `include/uapi/linux/bpf.h` | `258` |
| `include/linux/bpf_jit_directives.h` | `197` |
| `include/linux/bpf.h` | `59` |
| `include/trace/events/bpf.h` | `85` |
| `kernel/bpf/core.c` | `+101/-16` |
| `kernel/bpf/syscall.c` | `5` |
| `kernel/bpf/helpers.c` | `+5/-1` |
| `kernel/bpf/verifier.c` | `2` |
| `include/linux/filter.h` | `1` |
| `kernel/bpf/Makefile` | `1` |
| `tools/bpf/bpftool/prog.c` | `4` |
| `tools/include/uapi/linux/bpf.h` | `4` |

## 核心结论

最大的膨胀点不是 live re-JIT 本身，而是下面这层“通用规则 DSL”:

1. UAPI 暴露 pattern / constraint / binding 三层描述。
2. 内核先按这套 DSL 做一次通用匹配和参数提取。
3. 然后每个 canonical form 又重新解析真实 BPF site，并把参数重写成内核自己的 normalized params。
4. emitter 最终消费的是 normalized params，而不是用户原始 bindings。

也就是说，当前实现实际上把“语义来源”放在 per-form validator 里，却又保留了一整套通用 pattern DSL 作为前置层。这个前置层是本次审计里最值得删除的一块。

第二个明显信号是 `include/linux/bpf_jit_directives.h` 里已经出现了内核私有的 pointer-param hack:

- `BPF_JIT_ZEXT_PARAM_ALU32_PTR`
- `BPF_JIT_BFLIP_PARAM_SITE_PTR`

这说明统一的 `canonical_params[16]` 抽象已经装不下真实 emitter 需要的信息，设计本身已经开始破。

## 总体判断

高置信度结论:

- live-safe re-JIT 状态机是 `ESSENTIAL`
- x86 emitter 接入点和 staged image commit/abort 是 `ESSENTIAL`
- `kallsyms/extable` 热替换支持是 `ESSENTIAL`
- 通用 pattern/constraint/binding DSL 是 `REMOVABLE`
- 4 个低价值 canonical form 可以直接删掉: `ADDR_CALC`, `ZERO_EXT_ELIDE`, `ENDIAN_FUSION`, `BRANCH_FLIP`
- tracepoints、`recompile_count`、多级 `log_level`、用户可填 `cpu_features_required` 都不是核心功能

## 请求区块审计

说明:

- 下表中的“当前行数”是按当前工作树代码块估算，混合已有文件的改写区时采用当前 hunk footprint 近似值。
- 各区块之间有少量重叠，尤其是 header/helper；最终总量以文末“整树汇总”表为准。

| 功能区块 | 判定 | 当前行数 | 必要行数估计 | 可删/可简化 | 具体建议 |
| --- | --- | ---: | ---: | ---: | --- |
| syscall 入口和参数解析 | `ESSENTIAL` | `205` | `110` | `95` | 保留 `BPF_PROG_JIT_RECOMPILE` 和 handler；把 `policy_fd == 0` 改成 `-1` 或显式 flag；把 `log_level` 收缩成 bool；失败时统一“保留旧 policy/旧 image”，删掉双模式分支。 |
| policy blob 解析和验证 | `SIMPLIFIABLE` | `1076` | `220` | `856` | 删除 pattern/constraint/binding DSL，改成固定 rule array: `site_start + form + native_choice (+ 可选 flags)`；`cpu_features_required` 不要放 UAPI，内核按 choice 自己推导。 |
| rule 结构和管理 | `SIMPLIFIABLE` | `255` | `120` | `135` | `struct bpf_jit_rule` 可缩成轻量结构；如果一个 site 只允许一个 rule，可以删除 `priority` 和 tie-break 排序。 |
| recompile 状态机 (snapshot/commit/restore/rollback) | `ESSENTIAL` | `930` | `650` | `280` | 保留 staged image/commit/abort；最大可简化点是不要原地改 `prog->insnsi`，改用 scratch copy 做 pseudo-call fixup，这样 snapshot/restore 可以明显缩短。 |
| kallsyms/extable 管理 | `ESSENTIAL` | `140` | `95` | `45` | 保留 shadow ksym + replace；`owner/extable/num_exentries` 元数据必要，`recompile_count` 一类观察性字段不必要。 |
| tracepoints | `REMOVABLE` | `94` | `0` | `94` | 调试已经有 log buffer；tracepoints 不是功能正确性的必要条件。若还想留，至少应放在 `CONFIG_BPF_JIT_RECOMPILE_TRACE` 之类开关后。 |
| UAPI 定义 | `SIMPLIFIABLE` | `267` | `70` | `197` | 保留 syscall cmd 和最小 attr；删除 pattern DSL 相关 enums/structs、stock native-choice 枚举、用户 `cpu_features_required`、`recompile_count`；`BPF_JIT_ARCH_ARM64` 目前是死占位。 |
| helper 函数和工具函数 | `SIMPLIFIABLE` | `440` | `220` | `220` | 合并 `param_matches_*` / `param_set_*` / `binding_value_*` 一类胶水；如果删掉通用 DSL，很多 helper 会自然消失。 |
| 内核头文件中的声明 | `SIMPLIFIABLE` | `257` | `110` | `147` | `include/linux/bpf_jit_directives.h` 现在承载了太多实现细节；把 x86-specific staged API 和 generic rule struct 拆薄，只保留最小 forward decl 和少量 helper。 |
| 其他小文件 | `SIMPLIFIABLE` | `16` | `6` | `10` | `Makefile` 和 `filter.h` 声明保留；`bpftool` 打印和 `recompile_count` 可删；`verifier.c` 这 2 行对 recompile 主路径并不必要。 |

## per-form validator 审计

这里按当前工作树中的 validator 主体代码估算。

| canonical form | 判定 | 当前行数 | 必要行数估计 | 可删/可简化 | 具体建议 |
| --- | --- | ---: | ---: | ---: | --- |
| `COND_SELECT` | `ESSENTIAL` | `248` | `120` | `128` | 保留。它是少数真正体现 re-lowering 价值的 form。可删除“用户 binding 再比对一次”的层，只保留 shape parse + normalize。 |
| `WIDE_MEM` | `ESSENTIAL` | `172` | `100` | `72` | 保留，但可只支持“连续 byte gather -> native load”这一条主路径；不必维持现在这么通用的 width/endianness 编码。 |
| `ROTATE` | `SIMPLIFIABLE` | `541` | `220` | `321` | 当前覆盖 4/5/6 指令、masked 32-bit 变体、RORX。可以先收缩到最常见的 4-insn / 5-insn 旋转，BMI2 作为可选。 |
| `ADDR_CALC` | `REMOVABLE` | `92` | `0` | `92` | 这是纯 `lea` 微优化，收益小，代码和 UAPI 成本不值。建议整块删掉。 |
| `BITFIELD_EXTRACT` | `SIMPLIFIABLE` | `147` | `90` | `57` | 保留价值还行，但可以只保留 `shr + and` normalize；`mask_first/order` 这套通用化可明显收缩。 |
| `ZERO_EXT_ELIDE` | `REMOVABLE` | `85` | `0` | `85` | 收益小，而且已经靠内核私有 pointer param 强行穿透抽象。建议删。 |
| `ENDIAN_FUSION` | `REMOVABLE` | `132` | `0` | `132` | `movbe` 是很窄的 x86 特性，UAPI 和 validator 成本明显高于价值。建议删。 |
| `BRANCH_FLIP` | `REMOVABLE` | `148` | `0` | `148` | 纯布局/局部分支方向优化，不是 BpfReJIT 的核心卖点，而且依赖 site pointer hack。建议删。 |

### validator 总结

如果只保留 `COND_SELECT` / `WIDE_MEM` / `ROTATE` / `BITFIELD_EXTRACT` 四类，validator 层大约可以从 `1565` 行压到 `530` 行左右。

## per-form emitter 审计

说明:

- `COND_SELECT` 当前行数包含其共享 compare/binding helper。
- `BITFIELD_EXTRACT` 当前行数包含 `emit_bitfield_extract_core()`。
- `BRANCH_FLIP` 当前行数包含 body measure/emit 小 helper。

| canonical form | 判定 | 当前行数 | 必要行数估计 | 可删/可简化 | 具体建议 |
| --- | --- | ---: | ---: | ---: | --- |
| `COND_SELECT` | `ESSENTIAL` | `228` | `120` | `108` | 保留。可把当前 `binding_value` 抽象压缩成更直接的 shape struct，减少胶水。 |
| `WIDE_MEM` | `SIMPLIFIABLE` | `125` | `80` | `45` | 可压成宽度特化的 2/4/8 fast path，3/5/6/7 如无强需求可退化到 stock。 |
| `ROTATE` | `SIMPLIFIABLE` | `79` | `50` | `29` | 保留 `ror` 主路径即可；`rorx` 可以放在后续增量里，不必占核心版本。 |
| `ADDR_CALC` | `REMOVABLE` | `31` | `0` | `31` | 和 validator 一起删。 |
| `BITFIELD_EXTRACT` | `SIMPLIFIABLE` | `188` | `90` | `98` | 若不追求 `bextr`，仅保留 `mov/shr/and` 优化就够了。 |
| `ZERO_EXT_ELIDE` | `REMOVABLE` | `21` | `0` | `21` | 和 validator 一起删。 |
| `ENDIAN_FUSION` | `REMOVABLE` | `74` | `0` | `74` | 和 validator 一起删。 |
| `BRANCH_FLIP` | `REMOVABLE` | `148` | `0` | `148` | 和 validator 一起删。 |

### emitter 总结

如果删掉 4 个低价值 form，并把 `ROTATE` / `BITFIELD_EXTRACT` 压回常见主路径，emitter 层大约可以从 `894` 行压到 `340` 到 `400` 行。

## 关键冗余点

### 1. 通用 pattern DSL 基本可以整块删除

最值得先删的代码:

- `bpf_jit_match_pattern()`
- `bpf_jit_check_constraints()`
- `bpf_jit_validate_binding_desc()`
- `bpf_jit_extract_bindings()`
- 大部分 `bpf_jit_validate_canonical_params()`
- `struct bpf_jit_pattern_insn`
- `struct bpf_jit_pattern_constraint`
- `struct bpf_jit_binding`
- 与之对应的 UAPI enums / constants

原因:

- 每个 form 最终都还是靠真实 site parser 重新推导语义。
- validator 已经把参数重写成 normalized form。
- emitter 只消费 normalized params。
- 这意味着用户 bindings 并不是最终真相，最多只是一个昂贵的前置过滤器。

建议替代方案:

- UAPI 直接传最小 rule: `site_start`, `site_len`, `canonical_form`, `native_choice`
- 内核只做 per-form `parse_site()`
- parse 成功则直接得到 emitter 需要的 shape
- emitter 直接吃 shape，完全不走 `canonical_params[16]`

### 2. `canonical_params[16]` 抽象已经开始失真

当前实现已经不得不引入内核私有 pointer 参数:

- `BPF_JIT_ZEXT_PARAM_ALU32_PTR`
- `BPF_JIT_BFLIP_PARAM_SITE_PTR`

这说明“统一的 scalar binding array”并不能自然表达真实 emitter 所需状态。继续在这个抽象上加 form，只会继续长出更多内核私有 escape hatch。

建议:

- 删除 pointer-style internal params
- 每个 form 定义自己的 `shape` 结构
- validator 直接返回 `shape`
- emitter 直接消费 `shape`

### 3. stock native-choice 枚举基本是冗余的

当前这些 choice:

- `BPF_JIT_SEL_BRANCH`
- `BPF_JIT_WMEM_BYTE_LOADS`
- `BPF_JIT_ROT_SHIFT`
- `BPF_JIT_ACALC_SHIFT_ADD`
- `BPF_JIT_BFLIP_ORIGINAL`

本质都只是“不要优化，走 stock path”。但当前系统已经有两种天然表达 stock path 的方式:

- 根本不下发 rule
- `policy_fd == 0` 直接 stock re-JIT

所以这些 choice 在 UAPI 和 dispatcher 中都属于可删冗余。

### 4. `log_level` 设计过头了

当前 `log_level` 只被当作布尔值使用:

- `0` 不记录
- 非 `0` 记录

并没有多级日志语义。建议改成简单 bool 或单个 flag。

### 5. `BPF_F_RECOMPILE_ROLLBACK` 不值得保留成一个模式位

当前代码无论如何都不会把失败的新 image 留在线上；这个 flag 实际主要影响的是“失败后是否保留旧 policy”。

建议:

- 把“保留旧 image/旧 policy 直到新版本成功提交”改成唯一语义
- 删除 `BPF_F_RECOMPILE_ROLLBACK`
- 直接减少 handler 中一大段失败分支

### 6. `recompile_count` 和 bpftool 输出不是核心功能

它们属于观察性功能，不影响 recompile 正确性，也不影响 live commit 安全性。可以后补，不该占第一版核心复杂度预算。

## 已经是 DEAD 或近似 DEAD 的部分

| 项目 | 判定 | 原因 |
| --- | --- | --- |
| `BPF_JIT_ARCH_ARM64` | `DEAD` | 当前 parser 明确只接受 `BPF_JIT_ARCH_X86_64`，没有 arm64 backend。 |
| `log_level > 1` 语义 | `DEAD` | 当前实现只检查零/非零，没有 level 级别差异。 |
| `BPF_JIT_POLICY_VERSION_2` 兼容别名 | `DEAD-ish` | 如果没有已发布的 v1/v2 userspace 兼容包袱，这只是别名噪音。 |

## 文件级最小化估计

这个表是用来做“整树汇总”的，不再按功能块重叠计算。

| 文件/文件组 | 当前净新增行数 | 估计最小必要行数 | 潜在可削减 |
| --- | ---: | ---: | ---: |
| `kernel/bpf/jit_directives.c` | `4038` | `1500` | `2538` |
| `arch/x86/net/bpf_jit_comp.c` | `2015` | `900` | `1115` |
| `include/uapi/linux/bpf.h` + `tools/include/uapi/linux/bpf.h` | `262` | `70` | `192` |
| `include/linux/bpf_jit_directives.h` | `197` | `70` | `127` |
| `include/linux/bpf.h` | `59` | `35` | `24` |
| `kernel/bpf/core.c` | `85` | `45` | `40` |
| `include/trace/events/bpf.h` | `85` | `0` | `85` |
| `kernel/bpf/syscall.c` | `5` | `5` | `0` |
| `kernel/bpf/helpers.c` | `4` | `4` | `0` |
| `kernel/bpf/verifier.c` | `2` | `0` | `2` |
| `include/linux/filter.h` + `kernel/bpf/Makefile` + `tools/bpf/bpftool/prog.c` | `6` | `2` | `4` |

## 最终汇总

- 当前总量: `6758` 行净新增代码
- 估计最小必要行数: `2631` 行
- 潜在可削减行数: `4127` 行
- 潜在可削减比例: `61.1%`

## 建议的删减顺序

1. 先删通用 pattern DSL 和对应 UAPI。
2. 再删 4 个低价值 form: `ADDR_CALC`, `ZERO_EXT_ELIDE`, `ENDIAN_FUSION`, `BRANCH_FLIP`。
3. 删除 tracepoints、`recompile_count`、bpftool 展示、用户 `cpu_features_required`、多级 `log_level`。
4. 把 rollback 语义固定成“成功前不替换旧版本”，删掉 `BPF_F_RECOMPILE_ROLLBACK`。
5. 最后再压缩 `ROTATE` / `WIDE_MEM` / `BITFIELD_EXTRACT` 的变体覆盖面。

## 最后判断

BpfReJIT 现在这版代码不是“功能做不出来”，而是“为了一个还很窄的 x86 重编译器，先搭了一个过于通用的规则语言和参数抽象层”。如果目标是把它收敛成一个可以长期维护的内核特性，最合理的方向不是继续修补这层 DSL，而是承认当前真正的语义核心已经落在 per-form validator/emitter 上，然后把前面的通用层拆掉。
