# BpfReJIT Daemon 架构与算法参考文档

本文档基于当前仓库 `daemon/src/` 下的实际 Rust 实现编写，目标是给出可对照源码的正式参考说明，而不是概述性介绍。文中提到的类型名、行为和约束均以当前代码为准；若用户需求中的术语与实现命名不同，本文会明确指出两者对应关系。

## 1. 概述

### 1.1 daemon 的定位和职责

`bpfrejit-daemon` 是 BpfReJIT 的用户态控制面，核心职责有四类：

1. 枚举内核中的 live BPF program，并读取其原始字节码、map 元数据、JIT 镜像和运行统计。
2. 将 live program 提升为 daemon 自己的线性 IR `BpfProgram`，运行一条多 pass rewrite pipeline。
3. 通过内核扩展 syscall `BPF_PROG_REJIT` 把重写后的字节码重新提交给内核，原地替换程序镜像。
4. 在 daemon 模式下持续跟踪 map-inline 形成的“值快照依赖”，当 map 内容变化时重新优化对应程序。

它不负责：

1. 编译 BPF C/Rust 源码。
2. 通过 libbpf 管理对象生命周期。
3. 在内核里做 JIT 优化本体；优化真正生效仍依赖内核 verifier + JIT + kinsn 机制。

### 1.2 与内核组件的关系

当前体系分成三层：

1. 用户态 daemon。
   读取 live program、分析、重写、回滚、服务化暴露。
2. BPF syscall / BpfReJIT syscall 扩展。
   `daemon/src/bpf.rs` 直接发 `bpf(2)`；常用命令包括 `BPF_PROG_GET_NEXT_ID`、`BPF_OBJ_GET_INFO_BY_FD`、`BPF_MAP_GET_FD_BY_ID`、`BPF_BTF_GET_*`、`BPF_PROG_REJIT`。
3. 内核侧 verifier / JIT / kinsn。
   daemon 只负责把“更好的 BPF 字节码”或“packed kinsn 调用”送进内核；是否合法、如何 lowered 成目标架构指令，由内核 verifier/JIT 和导出的 kinsn stub 决定。

从代码实现看，daemon 与内核的交互主要有两条线：

1. 读取路径。
   `GET_NEXT_ID` 枚举 program/BTF，`GET_INFO_BY_FD` 拉取 `bpf_prog_info`/`bpf_map_info`，再用 `orig_prog_insns`、`xlated_prog_insns`、`jited_prog_insns` 指针字段取回程序镜像。
2. 写入路径。
   `BPF_PROG_REJIT` 提交新字节码和 `fd_array`，让内核重新 verifier + JIT，并原子替换 live image。

### 1.3 与 syscall + kinsn 的关系

需要区分两类“优化实现方式”：

1. 纯 BPF 重写。
   例如 `wide_mem`、`const_prop`、`dce`、`bounds_check_merge`、`skb_load_bytes_spec`，它们直接产生更短或更适合 JIT 的普通 BPF 指令。
2. kinsn 调用重写。
   例如 `rotate`、`cond_select`、`extract`、`bulk_memory`、`endian_fusion`。这些 pass 把某个 BPF idiom 替换成 `BPF_PSEUDO_KINSN_CALL`，由内核侧 kinsn stub 在 JIT 阶段进一步降到原生指令或小段内联代码。

daemon 自己不实现 kinsn，只做三件事：

1. 启动时扫描 `/sys/kernel/btf/`，发现已加载模块里的 kinsn stub。
2. 为每个 kinsn 记录 BTF FUNC id、所属 BTF FD、支持的编码方式。
3. 在 rewrite 时发出 packed sidecar + kinsn call，并把所需 BTF FD 填进 `BPF_PROG_REJIT` 的 `fd_array`。

### 1.4 零 libbpf 依赖设计

`daemon/src/bpf.rs` 明确采用“raw syscall wrapper”设计：

1. 所有交互都走 `libc::syscall(SYS_bpf, ...)`。
2. 所有 `bpf_attr` 变体在 Rust 中手工定义，按 128 字节对齐布局构造。
3. `bpf_prog_info` / `bpf_map_info` / `btf_info` 也手工镜像 UAPI 布局。
4. map fd relocation、verifier log 采集、BTF FD 查询都在 daemon 内部完成，不依赖 libbpf 的对象模型。

这样做的直接效果是：

1. daemon 可以对 live program 做“读原始镜像 -> 改字节码 -> REJIT”的闭环，而无需重建原始 `BPF_PROG_LOAD` 上下文。
2. syscall 行为完全可控，方便承接 BpfReJIT 扩展字段，例如 `orig_prog_insns` 和 `BPF_PROG_REJIT`。
3. 所有“老 map fd 失效、需要重绑”的细节在用户态显式可见。

## 2. CLI 和运行模式

### 2.1 实际存在的子命令

当前 CLI 只保留一个子命令：

1. `bpfrejit-daemon serve [--socket PATH]`

这里需要注意：

1. `serve` 是唯一的命令入口；历史上的 `watch`、`apply`、`apply-all`、`enumerate`、`rewrite` 已全部删除。
2. 历史上的 `--pgo`、`--pgo-interval-ms`、`--no-rollback` 已移除；当前 profiling 通过 socket 协议里的 `profile-start` / `profile-stop` 请求触发。

### 2.2 `serve`

输入：

1. `--socket`，默认 `/var/run/bpfrejit.sock`

行为：

1. 绑定 Unix socket。
2. 使用非阻塞 `accept()` 循环接收客户端。
3. 每 1 秒跑一次 invalidation tick；`MapInvalidationTracker` 仍然由 `serve` 持有并在这里驱动。
4. 对每一行请求做一次 JSON 解析和处理。
5. profiling 不是 CLI 模式，而是 request-scoped：客户端可在 `optimize` 前发送 `profile-start` / `profile-stop`，daemon 把采样结果注入后续 pipeline。

`serve` 是唯一长期运行模式；不再存在独立的 watch / enumerate / rewrite / apply 子命令。live program 的枚举只发生在 `optimize-all` 请求或 invalidation 驱动的重优化路径里。

### 2.3 serve 模式的 Unix socket 协议

协议是“逐行 JSON request / 逐行 JSON response”：

1. 每个请求必须是一行 JSON。
2. 每个响应也是一行 JSON。
3. 空行会被忽略。
4. 单个连接可以连续发送多条请求。

已实现命令：

1. `{"cmd":"status"}`
2. `{"cmd":"optimize","prog_id":123}`
3. `{"cmd":"optimize-all"}`

请求侧还支持两个可选字段，用于覆盖 pipeline 选择：

1. `enabled_passes: ["map_inline","wide_mem",...]`
2. `disabled_passes: ["branch_flip",...]`

这两个数组会直接覆写 `PassContext.policy`，并在进入请求处理前做名字校验；未知 pass 会返回错误。

#### `status`

响应：

```json
{"status":"ok","version":"<crate version>"}
```

#### `optimize`

请求：

```json
{"cmd":"optimize","prog_id":123}
```

成功响应是 `OptimizeOneResult`，核心字段包括：

1. `status`
2. `prog_id`
3. `changed`
4. `passes_applied`
5. `program`
6. `summary`
7. `passes`
8. `attempts`
9. `timings_ns`
10. `inlined_map_entries`
11. `error_message`

其中：

1. `passes` 是每个 pass 的 `PassDetail`。
2. `attempts` 记录 rollback 过程中的每次 REJIT 尝试。
3. `inlined_map_entries` 是 `map_inline` 为这个程序内联过的 `(map_id, key_hex, value_hex)` 去重列表。

#### `optimize-all`

响应：

```json
{"status":"ok","total":N,"applied":M,"errors":K}
```

#### 错误响应

统一形如：

```json
{"status":"error","message":"..."}
```

出错来源包括：

1. 非法 JSON。
2. 缺少 `prog_id`。
3. 未知 `cmd`。
4. `enabled_passes` / `disabled_passes` 包含未知 pass。
5. 请求处理过程中 panic；此时 server 用 `catch_unwind` 包装并返回 panic 文本。

## 3. 核心数据结构

### 3.1 `BpfInsn`

定义位置：`daemon/src/insn.rs`

`BpfInsn` 是 daemon 的最底层指令表示，和内核 `struct bpf_insn` ABI 兼容，固定 8 字节：

1. `code`
2. `regs`
3. `off`
4. `imm`

关键特性：

1. `regs` 低 4 位是 `dst_reg`，高 4 位是 `src_reg`。
2. `LD_IMM64` 是双槽指令，第二槽由下一条 8 字节承载高 32 位。
3. 提供 `is_call/is_exit/is_ldimm64/is_ldx_mem/is_cond_jmp/is_ja` 等分类接口。
4. 提供 `mov64_reg/mov64_imm/ldx_mem/stx_mem/alu64_imm/alu64_reg/ja` 等构造器。
5. 为 kfunc/kinsn 提供特殊构造器：
   `call_kfunc_with_off`、`call_kinsn_with_off`、`kinsn_sidecar`。

在整个 daemon 中，所有 pass 都直接操作 `Vec<BpfInsn>`，没有更高层 CFG IR。

### 3.2 `BpfProgram`

定义位置：`daemon/src/pass.rs`

`BpfProgram` 是 daemon 的“程序对象”，包含：

1. `insns`
   当前可变指令流。
2. `annotations`
   与指令同步长度的注解数组。
3. `transform_log`
   每次 pass 应用后的 `sites_applied` 记录。
4. `required_btf_fds`
   该程序重写后需要放入 `BPF_PROG_REJIT.fd_array` 的 BTF FD 列表。
5. `map_ids`
   该程序引用的 live map ID，顺序对齐内核 `used_maps`。
6. `map_fd_bindings`
   稳定的 `old_fd -> map_id` 映射，用于在删除/重排 pseudo-map load 后仍能正确重定位 map FD。
7. `branch_miss_rate`
   由当前 daemon session 的 profiling 请求注入的 PMU 分支失效率，供 `branch_flip` 使用。
8. `verifier_states`
   原始程序 `log_level=2` verifier 状态快照，用于 `map_inline` 的 verifier-guided key 提取。

重要方法：

1. `set_map_ids()`
   附带建立 `map_fd_bindings`。
2. `sync_annotations()`
   重写后补齐注解长度。
3. `remap_annotations(addr_map)`
   把旧 PC 上的注解迁移到新 PC。
4. `inject_profiling()`
   注入 `branch_profiles` 和 `branch_miss_rate`。
5. `set_verifier_states()` / `set_verifier_log()`
   为后续 pass 挂 verifier 状态。

### 3.3 `InsnAnnotation`

当前只有一个字段：

1. `branch_profile: Option<BranchProfile>`

它主要服务 `BranchFlipPass`。也就是说，当前 annotation 机制是通用的，但真正写入的动态注解只有分支 profile。
这些 per-site profile 也是由当前 daemon session 的 profiling 请求采集并注入。

### 3.4 `PassContext`

`PassContext` 是整条 pipeline 的只读上下文，包含：

1. `kinsn_registry: KinsnRegistry`
2. `platform: PlatformCapabilities`
3. `policy: PolicyConfig`
4. `prog_type: u32`

这里的 `prog_type` 非常重要，因为多个 pass 直接按 program type 做安全过滤：

1. `wide_mem` 会对 XDP/TC/packet 类程序额外保守。
2. `skb_load_bytes_spec` 只在 `SCHED_CLS/SCHED_ACT` 生效。
3. `bounds_check_merge` 只在 packet 类程序生效。

### 3.5 `PassManager`

`PassManager` 维护两类对象：

1. `passes: Vec<Box<dyn BpfPass>>`
2. `analyses: AnalysisRegistry`

其输出 `PipelineResult` 包含：

1. `pass_results`
2. `total_sites_applied`
3. `program_changed`
4. `attribution`
5. `debug_traces`

其中 `attribution` 是 rollback 的关键：它不是“哪个 pass 运行过”，而是“哪个 pass 实际修改了哪些 PC 范围”。

## 4. Pass 框架

### 4.1 `BpfPass` trait 语义

所有 transform pass 统一实现：

1. `name()`
2. `category()`
3. `required_analyses()`
4. `run(program, analyses, ctx) -> anyhow::Result<PassResult>`

语义上有几个约定：

1. pass 直接改写 `program.insns`。
2. 若 pass 修改了指令流，必须在返回的 `PassResult.changed` 中反映出来。
3. branch fixup、annotation remap 通常由 pass 自己完成；`PassManager` 只在 pass 返回后做 cache invalidation 和长度同步。

### 4.2 pipeline 构建与执行

标准 pipeline 定义在 `passes::PASS_REGISTRY`，默认顺序是：

1. `map_inline`
2. `const_prop`
3. `dce`
4. `skb_load_bytes_spec`
5. `bounds_check_merge`
6. `wide_mem`
7. `bulk_memory`
8. `rotate`
9. `cond_select`
10. `extract`
11. `endian_fusion`
12. `branch_flip`

运行时构建方式只有一种：

1. `build_full_pipeline()`
   全量按注册表顺序加入。

另有一个 `build_custom_pipeline(names)`，但它当前只在测试代码中存在，不是 CLI/daemon 的运行时入口。

执行流程：

1. 校验 policy 中 `enabled_passes/disabled_passes` 是否都在已知 pass 集合内。
2. 对每个 pass，预先运行 `required_analyses()` 指定的 analysis。
3. 执行 pass。
4. 若 `changed=true`：
   记录 before/after debug trace。
   计算该 pass 的修改 PC 范围。
   清空 analysis cache。
   调 `program.sync_annotations()`。

### 4.3 `const_prop + dce` 的固定点执行

`PassManager` 内置了唯一一对特殊固定点：

1. 当前 pass 为 `const_prop`
2. 下一个 pass 为 `dce`
3. 且两者都被 policy 允许

此时 `PassManager` 不按单次线性执行，而是最多做 5 轮：

1. 跑 `const_prop`
2. 跑 `dce`
3. 只要这对 pass 任一轮有改动，就继续下一轮

这是框架级固定点；与 `map_inline` 自己内部的固定点迭代是两套机制。

### 4.4 rollback 机制与归因

rollback 不在 `PassManager` 内部做，而是在 `commands::try_apply_one()` 做：

1. 每轮重新从原始字节码开始构造 `BpfProgram`。
2. 将已经判定有问题的 pass 放进 `local_ctx.policy.disabled_passes`。
3. 重新跑整条 pipeline。
4. 再尝试 `BPF_PROG_REJIT`。

失败归因有两类：

1. verifier rejection。
   从 verifier log 抽取失败 PC，再看 `PipelineResult.attribution` 中哪个 pass 覆盖了该 PC。若多个 pass 都覆盖，取最后一个。
2. verifier 已通过但 REJIT 后处理失败。
   无法精确定位 PC 时，退化为“最后一个发生改动的 pass”。

`PassManager` 计算 `attribution` 的算法不是简单 diff，而是：

1. 将 before/after 指令流转换成“出现次序 token”。
2. 通过最长递增子序列找出 after 中仍保持相对顺序的“未改动指令”。
3. 其余 after PC 视为被当前 pass 修改，合并成区间。

这使得 rollback 归因关注的是“新程序里哪些 PC 来自某个 pass 的修改结果”，而不是原始程序里的静态位置。

### 4.5 错误传播模型

错误沿以下链路上传：

1. analysis 自身如果返回普通值，直接放进 `AnalysisCache`。
2. `MapInfoAnalysis` 比较特殊，它的 `Result` 类型本身就是 `Result<MapInfoResult, String>`；也就是说 analysis cache 缓存的是“成功或失败”的值。
3. pass 在读取 `MapInfoAnalysis` 时显式 `.map_err(anyhow::Error::msg)?`，把分析失败提升为 pass 失败。
4. `PassManager::run_single_pass()` 直接返回 `anyhow::Result<PassResult>`。
5. `commands::try_apply_one()` 再把 pipeline 失败、map relocation 失败、REJIT 失败包装进最终 `OptimizeOneResult` 或直接报错。

另有一类“不是错误、但要阻止 site rewrite”的情况，`map_inline` 用了 `site_level_inline_veto` 前缀包装；调用方会把它降级成 skip reason，而不是让整条 pipeline 失败。

## 5. 分析层（Analysis）

### 5.1 `CFGAnalysis`

输入：

1. 线性 `BpfProgram.insns`

输出 `CFGResult`：

1. `blocks`
2. `insn_to_block`
3. `branch_targets`
4. `subprogs`

算法：

1. 第一遍扫描收集 branch/call target。
   对普通 jump 用 `pc + 1 + off`，对 `BPF_PSEUDO_CALL` 用 `pc + 1 + imm`。
2. 根据 target 和“跳转后的 fallthrough”确定 basic block 起点。
3. 按 block 边界切分出 `BasicBlock {start,end,preds,succs}`。
4. 读取每个 block 尾指令，构造 CFG 边。
5. 伪调用目标也被登记为 subprogram entry。

这个 CFG 是多数结构化优化的基础，尤其是 `const_prop`、`dce`。

### 5.2 `LivenessAnalysis`

输出：

1. `live_in[pc]`
2. `live_out[pc]`

算法：

1. 先对单条指令算 `use/def`。
2. 再做标准 backward dataflow 到不动点。
3. successor 计算考虑 `LD_IMM64` 双槽宽度。

它主要用于证明某些临时寄存器在 rewrite 后不需要保留：

1. `rotate` 看 `tmp_reg` 是否 live-out。
2. `wide_mem` 看 scratch regs 是否 live-out。
3. `bulk_memory` 看 memcpy 的临时寄存器是否 live-out。
4. `bounds_check_merge` 看 cursor reg 是否可删除整个 setup。

### 5.3 `MapInfoAnalysis`

职责：

1. 扫描程序中的 `BPF_PSEUDO_MAP_FD` 型 `LD_IMM64`。
2. 把旧 loader fd 重新绑定到 live map id。
3. 再通过 `bpf_map_get_info_by_id()` 取回运行时 `MapInfo`。

输出：

1. `references`
   每个 pseudo-map load 的 `pc/dst_reg/old_fd/map_index/map_id/info`。
2. `unique_maps`
   去重后的 `MapInfo` 列表。

关键判断逻辑封装在 `MapInfo` 上：

1. `supports_direct_value_access()`
   只有 `HASH/ARRAY/PERCPU_ARRAY/LRU_HASH` 返回 true。
2. `is_inlineable_v1()`
   当前等于 `supports_direct_value_access()`，不要求 frozen。
3. `can_remove_lookup_pattern_v1()`
   只有 `ARRAY/PERCPU_ARRAY` 可移除 lookup/null-check 模式。
4. `is_speculative_v1()`
   `HASH/LRU_HASH` 视为 speculative inline。

注意：

1. 这个 analysis 不处理 `BPF_PSEUDO_MAP_VALUE`；那部分由 `map_inline` 自己追踪。
2. 它返回的是运行时 map 元数据，而不是 ELF 静态描述。

### 5.4 `KinsnRegistry`（对应需求中的 “KfuncRegistry”）

代码里的实际类型名是 `KinsnRegistry`，其来源是 `kfunc_discovery.rs`。

它记录三类信息：

1. 每个 kinsn target 的 BTF FUNC id。
2. 每个 target 所属的 BTF FD。
3. 每个 target 支持的 kinsn encoding bitmask。

发现算法：

1. 读取 `/sys/kernel/btf/vmlinux`，得到 `str_len` 和类型数。
2. 读取每个候选模块 `/sys/kernel/btf/<module>` 的 split BTF。
3. 在 split BTF 中按函数名查找 `BTF_KIND_FUNC`。
4. 对模块 BTF 的 `name_off` 做 `base_str_off` 偏移修正。
5. 对模块本地 type id 加 `type_id_bias`，得到 verifier 接受的全局 BTF id。
6. 再通过 `BPF_BTF_GET_NEXT_ID/BTF_GET_FD_BY_ID/OBJ_GET_INFO_BY_FD` 找到真正可放进 `fd_array` 的 BTF FD。

当前内置已知 target 包括：

1. `bpf_rotate64`
2. `bpf_select64`
3. `bpf_extract64`
4. `bpf_memcpy_bulk`
5. `bpf_memset_bulk`
6. `bpf_endian_load16`
7. `bpf_endian_load32`
8. `bpf_endian_load64`

## 6. 每个 Pass 的算法详解

### 6.1 `MapInlinePass`

这是当前实现中最复杂、也是论文故事核心的 pass。

#### 6.1.1 目标和适用场景

目标有两类：

1. 把 `bpf_map_lookup_elem()` 返回值上的固定偏移标量 load 直接替换成常量。
2. 把 `BPF_PSEUDO_MAP_VALUE` 指向的 frozen map value load 直接常量化。

它并不追求“所有 map lookup 全删掉”，而是按 map type、key 形式、use 形态分层降级：

1. 最激进：
   `ARRAY/PERCPU_ARRAY`，key 常量，可直接读 value，可删 lookup/null-check/setup。
2. 中间层：
   `HASH/LRU_HASH`，key 常量，但只做 speculative fixed-load inline，原 lookup/null-check 仍保留。
3. 特例：
   `PSEUDO_MAP_VALUE` 的直接 load，只要源 map frozen，就不需要 helper call。

#### 6.1.2 外层固定点迭代

`MapInlinePass::run()` 不是单轮执行，而是最多 8 轮固定点：

1. 第 0 轮 `use_verifier_guided_keys=true`。
2. 后续轮次 `use_verifier_guided_keys=false`。
3. 每轮若发生改写，就手动 `analyses.invalidate_all()`，再进入下一轮。
4. 如果某轮无改动，则停止。

原因：

1. 某轮 map inline 可能会把伪 map value load 先常量化。
2. 常量化后会暴露新的栈常量、消掉 alias、使后续 lookup site 变得可内联。
3. verifier-guided key 只在第一轮可信，因为后续程序已不是原 verifier log 对应的字节码。

#### 6.1.3 lookup site 枚举

`find_map_lookup_sites()` 的规则很直接：

1. 扫描所有指令。
2. 找到 `is_call && src_reg==0 && imm==1`，即普通 helper `bpf_map_lookup_elem`。
3. 向前找最近一次定义 `r1` 的指令，且必须是 `LD_IMM64 dst=r1, src=BPF_PSEUDO_MAP_FD`。

因此，一个 site 同时记录：

1. `call_pc`
2. `map_load_pc`

#### 6.1.4 map type 过滤与站点前置 veto

每个 site 先通过 `MapInfoAnalysis` 解析到 `MapInfo`，随后执行如下过滤：

1. `!info.is_inlineable_v1()`
   直接跳过。当前只允许 `HASH/ARRAY/PERCPU_ARRAY/LRU_HASH`。
2. map 元数据不可用
   跳过。
3. key 不是常量
   跳过。
4. 对 `ARRAY/PERCPU_ARRAY`，若常量 key 超出 `max_entries`
   直接跳过。

这里的核心策略是：

1. “map 可读”是必要条件。
2. “map frozen”不是必要条件。
3. 对 mutable map，不再做“程序级/整张 map 只要出现写就全部禁用”的 writeback guard；当前 guard 是 site-local 的。
4. 也就是说，daemon 只检查“当前 lookup site 返回的 `r0` use region 是否逃逸出固定偏移只读 load”。同一张 mutable map 上，某些 site 可以被内联，另一些 site 可以因为逃逸写而被跳过。

#### 6.1.5 constant key 提取：三条路径

`extract_site_constant_key()` 实际实现了三条提取路径。

##### 路径 A：verifier-guided stack key

只在第一轮启用。

算法：

1. 在 `program.verifier_states` 中找到 `pc == call_pc` 的所有状态快照。
2. 对每个 occurrence，向前找最近一次 `r2=fp+off` 的 verifier 状态。
3. 再在 verifier 状态流中找覆盖 `[fp+off, width]` 的常量 stack store。
4. 要求所有 occurrence 推导出的 key 一致。

限制：

1. 当前只支持 `key_size <= 8`。
2. verifier log 必须存在 call 点状态。
3. 若多次到达 call 点但推导出不同 key，则整站点放弃。

这条路径的意义是：即便纯回溯源码指令找不到完整的常量 store，verifier 仍可能已经把 key 约束为常量。

##### 路径 B：普通 backward stack scan

这是默认路径。

算法：

1. 先把 `r2` 解析成“fp-relative stack pointer”。
   支持 `mov r2, r10` 加若干常量 `add/sub` 链。
2. 以 `map.key_size` 为目标宽度，在 call 前向后扫描栈写。
3. 只接受写到 `fp+off` 的 `ST` 或 `STX`，并且被写的值可解析为常量。
4. 若目标范围跨多个 store，就按字节拼出完整 key。

常量来源又支持：

1. `ST [fp+off], imm`
2. `STX [fp+off], reg`，其中 `reg` 必须能递归解析成常量
3. `LDX` 从栈上再取常量，也能继续递归
4. 一部分常量 ALU 链也会被求值

##### 路径 C：pseudo-map-value key

当 `r2` 不是指向栈，而是来源于 `BPF_PSEUDO_MAP_VALUE` 时，走第三条路径。

算法：

1. 解析 key pointer origin，要求最终是 `MapValue { old_fd, value_off, ldimm_pc }`。
2. 根据 `old_fd -> map_id` 找到源 map。
3. 要求源 map frozen。
4. 读取源 map 的 key 0 value。
5. 从这个 value 的 `value_off .. value_off + key_size` 截出 bytes，当作 lookup key。

这允许类似“map of structs 中某个 frozen 字段又作为另一张 map 的 key”这种常量传播穿透。

#### 6.1.6 `r0` use classification

`classify_r0_uses_with_options()` 会从 lookup helper 之后开始，跟踪 `r0` 及其 alias 的整个 use region。

它维护两类 alias：

1. `alias_regs`
   当前哪些寄存器仍可视为 lookup result 指针。
2. `alias_stack_slots`
   哪些 8 字节 stack slot 存了 lookup result 指针副本。

分类结果分成四类：

1. `fixed_loads`
   `LDX_MEM dst, [alias + const_off]`，这是可内联的核心消费点。
2. `other_uses`
   任何无法证明为“固定偏移标量 load”的其余 use。
3. `alias_copy_pcs`
   `mov`、保存到栈、从栈恢复等 alias 复制点。
4. `null_check_pc`
   紧跟在 lookup 后、针对 alias 的 `JEQ/JNE reg, 0` 空指针判断。

若结果满足：

1. 至少有一个 `fixed_load`
2. 当前 site 的 mutable lookup result 没有 `other_uses`
3. speculative map 具备立即 null-check

才可能继续 inline。

换句话说，mutable writeback guard 现在是“按当前 site 的 alias/use region 判定”，而不是“先做整程序扫描，再把整张 map 一刀切禁用”。

#### 6.1.7 null-check 识别与消除

`map_inline` 对 null-check 有两层处理：

1. 识别阶段：
   只在还没出现其他 use 之前，接受 `JEQ/JNE alias, 0`。
2. 消除阶段：
   只对 `JEQ alias, 0` 且“fallthrough 是非空路径”的情况尝试删掉。

真正允许删除 null-check 还要同时满足：

1. map type 允许删整个 lookup pattern。
2. 被删除的 lookup pattern 是一个紧凑连续区间，且全部位于首个 fixed load 之前。
3. null-check 到 slow path 之间的窗口是 trivial。
   除了即将被跳过或替换的指令，只允许 `exit`、`ja`、普通 `mov imm`、普通 `ldimm64` 这类无副作用语句。

如果 null-check 不能安全移除，则即便 fixed load 可以常量化，也只替换 load，不删除 helper call 模式。

#### 6.1.8 value 读取与 inline

`build_site_rewrite()` 的核心步骤：

1. 把 `ConstantKey.bytes` 按 `map.key_size` 编码成最终 key。
2. 用 `bpf_map_lookup_value_size_by_id()` 决定 userspace lookup 需要读多大的 value blob。
3. 通过 `bpf_map_lookup_elem_by_id()` 真正读取 live value。
4. 对 `PERCPU_ARRAY`，调用 `prepare_inline_value()`。
   只有所有 CPU slot 的 value 完全相同，才允许 collapse 成单个 value。
5. 对每个 `fixed_load`，从 value 的 `offset/size` 位置读出标量。
6. 用 `emit_constant_load()` 生成 `mov64_imm` 或 `ldimm64` 替换该 load。

注意：

1. `MapInlineRecord.expected_value` 记录的是原始 lookup 返回的完整 value blob。
2. `PERCPU_ARRAY` 的 invalidation 也比较完整原始 blob，而不是 collapse 后的单 slot 值。

#### 6.1.9 lookup pattern removal

对 `ARRAY/PERCPU_ARRAY`，若同时满足：

1. 所有 `r0` use 都已被常量替换。
2. 没有 `other_uses`。
3. key setup / map load / helper call / alias copy / null-check 都在可安全删除的连续窗口中。

那么 `skipped_pcs` 会包含：

1. map load 两槽
2. helper call
3. key store
4. 可删除的 `r2` setup
5. alias copies
6. 可删除的 null-check

之后 pass 会在重建指令流时直接跳过这些 PC，并在最后额外跑一次：

1. `eliminate_unreachable_blocks`
2. `eliminate_nops`

这是因为删除 null-check 后，原 slow path 经常会变成不可达块。

#### 6.1.10 direct pseudo-map-value load 常量化

`build_direct_map_value_load_rewrites()` 是独立于 lookup site 的第二条主线。

它会扫描所有 `LDX_MEM`，判断其 base 是否最终解析到 `BPF_PSEUDO_MAP_VALUE`：

1. 若能解析到 `old_fd + value_off`。
2. 且该 map frozen。
3. 且访问不越界。

就直接把 load 替换成常量加载。

特点：

1. 不需要 helper call。
2. 不需要 invalidation tracking。
3. 只针对 frozen map。

#### 6.1.11 invalidation tracking

CLI 虽然已经只剩 `serve`，但 invalidation tracking 并没有被移走；`map_inline` 本身只产出 `MapInlineRecord`，真正的 tracking 仍然在 `commands.rs` 和 `server.rs`：

1. 每个成功应用的 inline site 会记录：
   `map_id/key/expected_value`。
2. `record_map_inline_records()` 会打开 map fd，并把 `(prog_id, map_fd, key, expected_value)` 存进 `MapInvalidationTracker`。
3. `serve` 每秒调用 `check_for_invalidations()`。
4. tracker 以 map 为单位 batch lookup 所有被追踪 key。
5. 只要当前 value 与 `expected_value` 不同，就把对应 `prog_id` 标为 invalidated。
6. invalidated program 会立刻重新走 `try_apply_one()`。

因此，当前实现对 mutable map 的策略不是“禁止内联”，而是“只要值模式足够简单，就允许特化，并在值变化时重优化”。

#### 6.1.12 与其他 pass 的交互

最重要的交互有三条：

1. 与 `const_prop`
   map_inline 把 load 变成常量后，会暴露更多寄存器常量和可折叠分支。
2. 与 `dce`
   当 lookup/null-check 被整段移除后，dead block 需要 `dce` 清掉。
3. 与 invalidation tracker
   speculative inline 的正确性不只靠 verifier，而靠“记录值快照 + 周期性重优化”维持。

### 6.2 `ConstPropPass`

目标：

1. 把寄存器已知常量传播到后续 ALU/JMP。
2. 把可求值的 ALU 结果改写成常量加载。
3. 把可确定真假的条件跳转折叠成 `JA` 或 `NOP`。

算法：

1. 基于 `CFGAnalysis`，对每个 block 求入口常量状态。
2. 状态是 11 个寄存器的 `Option<u64>`。
3. merge 时只有“所有前驱都相同的常量”才保留，其余变 `None`。
4. 再对每个 block 顺序模拟，尝试生成 replacement。

匹配与重写：

1. `MOV`、常量 `LD_IMM64` 会把目标寄存器标成常量。
2. 支持 `ADD/SUB/MUL/DIV/MOD/OR/AND/XOR/LSH/RSH/ARSH/NEG` 的常量求值。
3. 条件跳转若左右操作数都是常量，则折叠成：
   `taken -> JA`
   `not taken -> NOP`

安全约束：

1. 对 pseudo source 的 `LD_IMM64` 不会重发成普通标量 `LD_IMM64`，避免丢失 verifier-visible 类型。
2. 遇到 helper call，`r0..r5` 状态清空。

与其他 pass 的交互：

1. 与 `dce` 构成固定点。
2. 常见触发源是 `map_inline` 输出的常量 load。

### 6.3 `DcePass`

目标：

1. 删除 CFG 不可达块。
2. 删除 `ja +0` 形成的 NOP。

算法：

1. 先用 CFG 删不可达 basic block。
   reachability 不只看主入口，还会从 reachable block 中的 pseudo-call 推出被调用 subprog 的 entry。
2. 再循环执行 `eliminate_nops()`，直到没有新 NOP 可删。
3. 多轮 cleanup 产生的地址映射通过 `compose_addr_maps()` 叠加。

它故意不做“死寄存器定义删除”；当前 DCE 只处理控制流和显式 NOP。

### 6.4 `WideMemPass`

目标：

1. 把逐字节 load + shift + or 拼装宽值的 idiom，变成单条 `LDX_MEM(H/W/DW)`。

匹配算法：

1. 支持 low-byte-first 形式。
2. 也支持 clang 常见的 high-byte-first 形式。
3. 优先匹配最长宽度，支持宽度仅有 2/4/8 字节。

rewrite：

1. 生成单条 `ldx_mem(size, dst, base, off)`。

安全约束：

1. site 内部不能有 branch target。
2. 所有 scratch reg 在 site 后必须 dead。
3. 只允许输出 2/4/8 字节宽 load。
4. 对 packet 类 program，若 base reg 很可能来自 `ctx->data`，直接跳过。
   因为 verifier 对 packet pointer 的宽 load 对齐/范围要求比 byte load 更严。

与其他 pass 的交互：

1. `bounds_check_merge` 若先放宽 packet window，可间接帮助后续 wide load，但当前 pipeline 中 `wide_mem` 在其后。
2. `const_prop/dce` 不直接依赖它。

### 6.5 `RotatePass`

目标：

1. 把 rotate idiom 变成 `bpf_rotate64` packed kinsn call。

匹配算法：

1. 必须先有一条紧邻的 provenance `MOV tmp, dst`。
2. 后接两条 `RSH/LSH`，位移量相加必须为 64。
3. 再接一条 `OR`，且 OR 正好合并这两个寄存器。
4. 支持 `RSH->LSH->OR` 和 `LSH->RSH->OR` 两种顺序。

rewrite：

1. 发出 `kinsn_sidecar + call_kinsn` 两条指令。
2. payload 编码 `dst_reg / val_reg / shift_amount / tmp_reg`。

安全约束：

1. 需要 `bpf_rotate64` 已发现。
2. 需要 packed ABI 支持。
3. 程序中若存在 `BPF_PSEUDO_CALL`，整个 pass 直接禁用。
4. site 内部不能有 branch target。
5. `tmp_reg` 在 site 结束后不能 live-out。

与其他 pass 的交互：

1. 依赖 `KinsnRegistry` 和 `required_btf_fds`。
2. 不做 save/restore；完全依赖 packed ABI 语义。

### 6.6 `CondSelectPass`

目标：

1. 把短 if/else“选择值”模式降成 `bpf_select64`。

匹配算法：

1. Pattern A，四指令 diamond：
   `Jcc +2 ; mov false ; ja +1 ; mov true`
2. Pattern C，三指令短模式：
   `mov true ; Jcc +1 ; mov false`

当前只接受简单零测试：

1. `JNE reg, 0`
2. `JEQ reg, 0`

重写：

1. 对 `JNE reg, 0`，kfunc 参数按 `(true_val, false_val, cond_reg)`。
2. 对 `JEQ reg, 0`，为了适配 `select64(a,b,cond)` 的“cond!=0 选 a”，实现中会交换 true/false 两个值。
3. 当前 packed path 要求 true/false 两个值都是寄存器值；imm 虽然被检测出来，但不会进入 rewrite。

安全约束：

1. 平台需有 `CMOV/CSEL` 能力标记。
2. `bpf_select64` kinsn 必须存在且支持 packed ABI。
3. site 内部不能有外部 branch target；对 3-insn pattern 还要排除 JCC 自己的 target。
4. 对 Pattern C，前置 `mov true` 不能 clobber JCC 条件寄存器。

### 6.7 `ExtractPass`

目标：

1. 把位域提取 idiom `RSH ; AND mask` 降成 `bpf_extract64`。

匹配算法：

1. `RSH64_IMM dst, shift`
2. `AND64_IMM dst, mask`
3. `mask` 必须是从 bit0 开始的连续 1 掩码，即 `(1<<n)-1`
4. 还要求 `shift + bit_len <= 64`

重写：

1. sidecar payload 编码 `dst / shift_amount / bit_len`
2. 发出 packed kinsn call。

安全约束：

1. 需要 `bpf_extract64` kinsn 和 packed ABI。
2. site 内部不能有 branch target。

### 6.8 `EndianFusionPass`

目标：

1. 把 `LDX_MEM + ENDIAN_TO_BE` 融成 `bpf_endian_load16/32/64` kinsn。

匹配算法：

1. 第一条必须是 `LDX_MEM(H/W/DW)`。
2. 第二条必须是 `ALU|END|TO_BE`。
3. 两条指令 `dst_reg` 必须相同。
4. load size 与 endian size 必须匹配。

重写算法：

1. 对能直接编码 offset 的目标架构，直接发 sidecar+call。
2. 若 offset 不能直接编码，则仍然坚持 packed transport：
   通过临时 `ADD` 到 base，再发“零 offset” packed call，必要时再把 base 加回去。
3. 对 AArch64，`offset_is_directly_encodable()` 明确按 size 检查可编码范围；x86_64 直接认为可编码。

安全约束：

1. 至少要有一个 endian_loadXX kinsn 可用。
2. 每个 site 还要检查对应 size 的 kinsn 是否存在。
3. site 内部不能有 branch target。

### 6.9 `BranchFlipPass`

目标：

1. 根据当前 daemon session 注入的 profile，把热点 taken-path 的 if/else diamond 翻面，使热点 path 变成 fallthrough。

匹配算法：

1. 识别标准 diamond：
   `Jcc +N ; then-body ; JA +M ; else-body`
2. `then_len = N-1`
3. `else_len = M`
4. 两侧 body 都不能以 straddling `LD_IMM64` 结尾。

触发条件：

1. `program.branch_miss_rate` 必须存在，且不超过阈值。
2. 若 site 上有 `BranchProfile`，则要求 `taken_count / total >= min_bias`。
3. 若 site 上没有 `BranchProfile`，但程序级 PMU miss-rate gate 已通过，则允许退化到一个保守的 size-asymmetry fallback：
   `else_len > 0 && then_len > 2 * else_len`
4. 若完全没有 PMU 数据，则整个 pass 仍然跳过；也就是说 `branch_flip` 要真正生效，入口仍然是先通过 socket profile 请求为当前 daemon session 注入 profiling 数据。

rewrite：

1. 反转 JCC opcode。
2. 交换 then/else body 顺序。
3. 重写新的 `Jcc.off` 与中间 `JA.off`。
4. 全局 branch fixup 后，再手工恢复这两个 site-local offset，防止被通用 fixup 覆盖。

安全约束：

1. 不接受 `JSET`，因为没有简单反操作。
2. site 内不能有来自外部的 interior target，JCC 自己的 target 除外。
3. 没有 PMU 数据时完全不做 fallback；只有当前 daemon session 已成功收集到程序级 profile 后，才会考虑 per-site profile 或 size-asymmetry fallback。

### 6.10 `BoundsCheckMergePass`

目标：

1. 识别 packet access 前反复出现的 bounds-check ladder，把多个 guard 合并成一个更大的 dominant guard。

识别对象：

1. `mov cursor, root`
2. `add cursor, window_end`
3. `jgt/jlt/jge/jle cursor, data_end, slow`

分析基础：

1. `apply_transfer()` 维护每个寄存器的抽象状态：
   `PacketData {root_id,const_off}`、`PacketEnd {root_id}`、`Scalar/Unknown`
2. `ctx->data` load 会分配一个新的 `root_id`
3. 紧跟的 `ctx->data_end` 会共享最近的 `root_id`

可合并条件：

1. 同一个 `root_id`
2. 同一个 `root_reg`
3. 同一个 `data_end_reg`
4. 同一种比较语义
   `Strict` 或 `Inclusive`
5. 同一个 slow path target
6. 后续 guard 的 `window_end` 更大，但增长不超过 `MAX_LADDER_WINDOW_GROWTH=24`
7. 两个 guard 之间的 interleave 指令必须是 merge-safe。
   不能有 branch；store 只能写栈。

rewrite：

1. 选最早的 guard 做 dominant guard。
2. 仅把 dominant guard 的 `ADD imm` 改成该 ladder 的最大 `window_end`。
3. 后续 guard 若 `cursor` 在 compare 后已 dead 且 setup 可删，则删 `mov/add/compare` 三条。
4. 否则至少删 compare。
5. 全局 fixup 后，再跑 unreachable-block 和 nop 清理。

额外策略：

1. 变量窗口 guard 会被识别，但统一给 skip reason：
   `variable packet window is not mergeable in v1`

### 6.11 `SkbLoadBytesSpecPass`

目标：

1. 把 `bpf_skb_load_bytes()` 的“小常量长度”调用专门化成 direct packet read fast path，并保留原 helper slow path。

适用 program type：

1. 仅 `SCHED_CLS`
2. 仅 `SCHED_ACT`

匹配算法：

1. 扫描 regular helper call `imm==26`。
2. 要求：
   `r1 == ctx`
   `r2 == 常量非负 offset`
   `r3 == fp-relative stack 指针`
   `r4 == 常量 len`
3. `len` 必须在 `1..=8`。
4. call PC 不能是 branch target。

rewrite：

1. 在原 helper call 位置展开：
   从 `skb->data` / `skb->data_end` 取包边界
   计算 `data + offset + len`
   与 `data_end` 做 `JGT`
   若不越界，逐字节复制到目标栈槽，`r0=0`
   再 `JA` 跳过 slow path
   slow path 重建 `r2=offset`、`r4=len` 后执行原 helper call
2. 注意：即便 `len` 是 2/4/8，也仍然保持 bytewise copy，不做宽 load。

安全约束：

1. 只专门化 call，不删除原参数准备代码。
2. fast path 故意不 widening，避免把 helper 合法的“非对齐 copy”变成 verifier 可能拒绝的直接宽访问。

### 6.12 `BulkMemoryPass`

目标：

1. 把大块标量化 memcpy/memset 降成 `bpf_memcpy_bulk` / `bpf_memset_bulk` kinsn。

#### memcpy 匹配

把以下 lane 视为一个 memcpy lane：

1. `LDX width tmp, [src_base + src_off]`
2. `STX width [dst_base + dst_off], tmp`

然后要求多组 lane：

1. width 相同
2. src/dst base 相同
3. src/dst offset 连续递增
4. 中间不能穿过 branch target

触发阈值：

1. 总字节数至少 `MIN_BULK_BYTES = 32`
2. 单个 kinsn chunk 最多 `CHUNK_MAX_BYTES = 128`
3. 通过 `uniform_chunk_sizes()` 把大 run 切成多个 chunk

安全约束：

1. same-base 且区间重叠的 memcpy 直接拒绝。
2. 被使用的 `tmp_reg` 在 site 后不能 live-out。
3. 若 `src_base != dst_base`，只有在“一个明显是 stack、另一个明显不是 stack”时才认为 alias 可分离；否则拒绝。

#### memset 匹配

识别的是连续 store run：

1. `ST/ STX [base+off] = fill`
2. 当前实现要求 fill byte 必须是 0

也就是说，虽然 payload 编码为一般化 memset 预留了 fill byte 字段，但当前实际识别的是“zero memset”。

chunk 规则：

1. 通过 `greedy_store_chunk_sizes()` 聚合 lane，尽量拼到 128 字节。
2. 最后一个 chunk 若小于 32 字节则丢弃。

rewrite：

1. 一个 site 可能发出多个 packed kinsn call。
2. memcpy payload 编码：
   `dst_base/src_base/dst_off/src_off/len/temp_reg`
3. memset payload 编码：
   `base/dst_off/len/width_class/zero_fill/fill_byte`

## 7. BPF Syscall 层

### 7.1 `bpf.rs` 的 raw wrapper 总体设计

`bpf.rs` 做了三件事：

1. 定义 `bpf_attr` 各变体布局。
2. 提供一组 typed wrapper。
3. 把 daemon 侧需要的“补齐逻辑”封装起来，例如两段式 `GET_INFO`、map fd relocation、REJIT verifier log 重试。

底层统一入口是：

1. `unsafe fn sys_bpf(cmd, attr_ptr, size) -> c_long`

### 7.2 `GET_NEXT_ID`

涉及 wrapper：

1. `bpf_prog_get_next_id(start_id) -> Result<Option<u32>>`
2. `bpf_btf_get_next_id(start_id) -> Result<u32>`

用途：

1. program 枚举
2. BTF 枚举

其中 `iter_prog_ids()` 只是对 `bpf_prog_get_next_id()` 的 iterator 封装。

### 7.3 `GET_INFO`

涉及 wrapper：

1. `bpf_prog_get_info(fd, fetch_orig)`
2. `bpf_prog_get_runtime_images(fd)`
3. `bpf_prog_get_map_ids(fd)`
4. `bpf_map_get_info(fd)`
5. `bpf_map_get_info_by_id(id)`
6. `bpf_btf_get_info_name(fd)`（内部）

典型模式是“两段式 GET_INFO”：

1. 第一遍拿长度字段。
2. 分配缓冲区并把缓冲区指针写回 `*_insns`/`map_ids` 字段。
3. 第二遍真正取回内容。

### 7.4 “GET_ORIGINAL” 的实际实现

当前代码没有独立的 `BPF_PROG_GET_ORIGINAL` 命令常量。

原始程序镜像的读取方式是：

1. 调 `BPF_OBJ_GET_INFO_BY_FD`
2. 读取 `BpfProgInfo.orig_prog_len`
3. 将 `BpfProgInfo.orig_prog_insns` 指向用户态缓冲区
4. 再次 `BPF_OBJ_GET_INFO_BY_FD`

因此，文档里如果说“GET_ORIGINAL”，应理解为：

1. 基于扩展后的 `bpf_prog_info.orig_prog_insns/orig_prog_len` 字段的原始镜像读取协议
2. 而不是一个独立 syscall 编号

### 7.5 `REJIT`

核心 wrapper：

1. `bpf_prog_rejit(prog_fd, insns, fd_array)`
2. `bpf_prog_rejit_capture_verifier_log(...)`

实现策略：

1. 先以 `log_level=0` 快速尝试。
2. 若失败，再分配 16MB log buffer，以 `log_level=2` 重新调用。
3. 若第二次失败且 log 非空，错误消息中拼接 `verifier log:\n...`。
4. 若第二次成功，也会返回 `RejitResult { verifier_log }`。

### 7.6 map fd relocation

为什么需要 relocation：

1. 原始字节码中的 `BPF_PSEUDO_MAP_FD` / `BPF_PSEUDO_MAP_VALUE` 持有的是“原加载进程当时的 fd 编号”。
2. daemon 进程里这些 fd 不存在，因此 REJIT 前必须重绑。

算法：

1. 扫描所有 `LD_IMM64` map reference。
2. 收集 unique old fd，保持 first-seen 顺序。
3. 用 `map_fd_bindings` 优先恢复 `old_fd -> map_id`；若没有，则退化为按 `map_ids` 顺序匹配。
4. 对每个 map_id 调 `BPF_MAP_GET_FD_BY_ID` 打开新 fd。
5. 把字节码中的旧 fd 立即数改写成新 fd。
6. 返回 `Vec<OwnedFd>`，由调用方保持活着直到 REJIT 完成。

### 7.7 verifier log 解析

`verifier_log.rs` 负责：

1. 从 `log_level=2` 文本中解析结构化状态快照 `VerifierInsn`。
2. 从失败日志中提取 failure PC。

解析结果包括：

1. 当前 `pc`
2. `from_pc`
3. `frame`
4. 各寄存器 `RegState`
5. 各栈槽 `StackState`

它的主要消费者有两个：

1. `commands::attribute_verifier_failure()`
   用于 rollback 归因。
2. `map_inline`
   用于 verifier-guided key 提取。

## 8. Rewrite 基础设施

### 8.1 branch fixup 算法

核心工具是 `passes::utils::fixup_all_branches()`。

输入：

1. `new_insns`
2. `old_insns`
3. `addr_map[old_pc] = new_pc`

算法：

1. 遍历 old 指令流。
2. 若旧指令是 pseudo-call，则把旧 target `old_pc + 1 + imm` 映到 `new_target`，重算新 `imm`。
3. 若旧指令是普通 jump，则把旧 target `old_pc + 1 + off` 映到 `new_target`，重算新 `off`。
4. 只在“该旧指令以未修改形式活到了新流中”时重写其 offset。

另外，`eliminate_marked_insns()` 内部还提供了更窄用途的 `fixup_surviving_branches()`，用于 DCE/NOP cleanup。

### 8.2 address map 构建

几乎所有 transform pass 都采用同一模板：

1. 遍历旧程序。
2. 当遇到替换 site 时，令该 site 覆盖的所有 old PC 都映射到同一个 `new_pc`。
3. 当遇到删除 site 时，被删指令的 `addr_map` 也指向删除后的下一个新 PC。
4. `LD_IMM64` 第二槽单独占一个 old PC，因此 `addr_map` 必须显式为 continuation slot 填值。
5. 最终还会设置 `addr_map[old_len] = new_len`，作为 past-the-end sentinel。

### 8.3 指令插入 / 删除 / 替换

当前 pass 的实现风格很统一：

1. 插入。
   在 `new_insns` 里追加 replacement，比旧代码更长。
2. 删除。
   用 `skip_pcs` 或 `deleted[]` 标记要跳过的 old PC。
3. 替换。
   用 `BTreeMap<pc, Vec<BpfInsn>>` 存 replacement，重建新流时按 PC 命中。

这种方式的优点是：

1. 所有 rewrite 都是“从旧流重建新流”，没有原地 edit。
2. 易于同时构造 `addr_map`。
3. 易于在最后统一做 branch fixup 和 annotation remap。

### 8.4 multi-pass 交互保证

当前实现通过四个机制保证多 pass 交互：

1. `AnalysisCache.invalidate_all()`
   任一 pass 改了程序，后续 analysis 一律重算。
2. `program.remap_annotations(addr_map)`
   确保 profiling 注解不会错位。
3. `map_fd_bindings`
   即便前面 pass 删除/挪动了 pseudo-map load，后续 REJIT 仍能做正确 fd relocation。
4. 固定点与 cleanup。
   `map_inline` 自身固定点、`const_prop+dce` 固定点、以及某些 pass 内部的 cleanup，使后续 pass 看到的是相对稳定的线性流。

## 9. Pipeline 配置

### 9.1 daemon 默认 pipeline 组成

默认 pipeline 就是 `PASS_REGISTRY` 全量顺序：

1. `map_inline`
2. `const_prop`
3. `dce`
4. `skb_load_bytes_spec`
5. `bounds_check_merge`
6. `wide_mem`
7. `bulk_memory`
8. `rotate`
9. `cond_select`
10. `extract`
11. `endian_fusion`
12. `branch_flip`

这 12 个 pass 就是当前 daemon 注册表中的全部优化 pass；安全 pass `speculation_barrier`、`dangerous_helper_firewall`、`live_patch` 已不在 registry 中，也不在默认 pipeline 中。

### 9.2 `benchmark_config.yaml` 的 performance pass 集

`corpus/config/benchmark_config.yaml` 的 `passes.performance` 当前列出了 11 个 performance pass：

1. `wide_mem`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`
6. `map_inline`
7. `const_prop`
8. `dce`
9. `bounds_check_merge`
10. `skb_load_bytes_spec`
11. `bulk_memory`

这里与 daemon 默认 pipeline 有一个刻意差异：

1. 这 11 个 pass 覆盖了当前 benchmark 配置里默认启用的非 PGO pass。
2. `branch_flip` 仍然在 daemon `PASS_REGISTRY` 里，但不在这个 `performance` 列表中；它只有在请求显式启用、并且该 session 已成功收集 profile 时才真正有意义。
3. 三个安全 pass 既不在 registry 中，也不在 `benchmark_config.yaml` 中。

### 9.3 排序原因与依赖关系

当前顺序体现了三层意图：

1. 先做“去 helper / 出常量”的高收益结构化简化。
   `map_inline -> const_prop -> dce`
2. 再做 packet/memory 模式专门化。
   `skb_load_bytes_spec -> bounds_check_merge -> wide_mem -> bulk_memory`
3. 最后做 kinsn lowering 和 PGO 布局。
   `rotate -> cond_select -> extract -> endian_fusion -> branch_flip`

几个关键依赖：

1. `const_prop` 依赖 `map_inline` 暴露常量。
2. `dce` 需要跟在 `const_prop` 后反复收尾。
3. `branch_flip` 放最后，避免后续 pass 再打乱其已重排的分支布局。

### 9.4 按请求覆盖 pass 选择

当前代码支持两种覆盖方式：

1. 进程启动时的 `PassContext.policy.enabled_passes/disabled_passes`
2. `serve` 请求里的 `enabled_passes` / `disabled_passes`

约束：

1. 名字必须是 canonical pass name。
2. unknown name 会在请求入口直接报错。
3. 运行时不会重建“子集 pipeline”；daemon 始终从 `build_full_pipeline()` 出发，再由 policy 决定哪些 pass 被启用或禁用。

### 9.5 不在当前范围内的 pass

以下安全 pass 不在当前 OSDI 评测范围内，且已经从当前 registry / 默认 pipeline / benchmark config 中移除：

1. `speculation_barrier`
2. `dangerous_helper_firewall`
3. `live_patch`

因此，本文件里与 pipeline 相关的描述都只以上文 daemon 默认 12-pass pipeline 和 benchmark 默认 11-pass performance 集为准。
