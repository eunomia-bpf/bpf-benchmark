# daemon Rust 审计（2026-04-23）

范围：`daemon/src/**`，排除 `daemon/src/bpfopt-suite/**`；不碰 `vendor/linux-framework/**`；只读分析，不改源码，不跑 VM/AWS。基线约束来自 [docs/kernel-jit-optimization-plan.md](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md:17)、[docs/kernel-jit-optimization-plan.md](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md:356)、[docs/kernel-jit-optimization-plan.md](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md:401)。

结论先行：

- **有 1 条真实高优先级问题**：单程序 `optimize` 路径在 `orig_insns.is_empty()` 时返回 `status="ok"` 的空结果，绕过 pass scheduling / per-pass observability / Round 7 taxonomy；而 `optimize-all` 同场景已经 loud-fail，语义不一致。
- **没有发现 daemon 侧与本轮 Python runner 清理同型的 lazy rename / 旧 helper 兼容壳 / 隐式 benchmark gate 残留**。
- **有 1 处明确的生产死壳**：`elf_parser` 明写“test fixtures”，却仍被 production daemon 编译进来。
- **还有几处低价值 wrapper / 冗余 guard**，但都不是 blocker。

## 1. 矩阵 A-J 逐项结果

### 矩阵 A：`orig_insns` 短路（coverage-gap §5 点名）

- Command: `rg -n -S 'orig_insns\.is_empty|orig_prog_len|get_orig_insns_by_id|BPF_PROG_GET_ORIGINAL' daemon/src docs/tmp/program-coverage-gaps-20260423/summary.md docs/tmp/20260325/kernel_diff_unnecessary_changes_20260325.md docs/tmp/20260321/bpfrejit_v2_design_gaps_20260321.md docs/tmp/20260320/bpf_program_replacement_research_20260320.md`
- Hits:
  - `daemon/src/commands.rs:533-547`：`orig_insns.is_empty()` 直接 `return Ok(make_result(... passes=[], attempts=[], applied=false, changed=false ...))`
  - `daemon/src/commands.rs:477-485`：先取 `(info, orig_insns)`，`orig_insn_count` 在空字节码时退回 `info.orig_prog_len / 8`
  - `daemon/src/bpf.rs:565-583`：只有 `info.orig_prog_len > 0` 才申请 `orig_bytes`；否则直接返回空 `orig_insns`
  - `daemon/src/bpf.rs:1206-1214`、`1761-1765`：`try_apply_one()` / `collect_live_program_candidates()` 都走同一个 `bpf_prog_get_info(..., fetch_orig=true)` 取数路径
  - `daemon/src/server.rs:117-129`：`optimize-all` 遇到空 `orig_insns` 会 `bail!("missing original bytecode ...")`
  - `docs/tmp/20260325/kernel_diff_unnecessary_changes_20260325.md:219`：repo 内核差异文档明确写了 `info.orig_prog_len = 0` 可由 “non-capable” 触发
  - `docs/tmp/20260321/bpfrejit_v2_design_gaps_20260321.md:142-143`：GET_ORIGINAL 至少要求 `bpf_capable()` + raw-dump 语义
  - `docs/tmp/20260320/bpf_program_replacement_research_20260320.md:221`：`bpf_capable()` = `CAP_BPF` 或 `CAP_SYS_ADMIN`
- 判断：
  - **确认存在**，而且是当前 daemon 最严重的 observability 漏洞。
  - 这不是 prog-type gate，也不是 kinsn/verifier 限制。当前证据只支持“**权限 / raw dump policy 导致 `orig_prog_len==0`**”这个解释；daemon 代码里没有任何按 `prog_type` 特判空 `orig_insns` 的逻辑。
  - 单程序 `optimize` 是**静默成功**，`optimize-all` 是**显式错误**，两条入口现在不一致。

### 矩阵 B：daemon 内 filter/select/gate 残留

- Command: `rg -n -S 'should_.*|_if_.*|filter.*program|skip.*program|select.*program|gate.*|bypass|short.?circuit|early.?return' daemon/src --glob '!bpfopt-suite/**'`
- Follow-up（去测试噪音）: `rg -n -S 'should_.*|_if_.*|filter.*program|skip.*program|select.*program|gate.*|bypass|short.?circuit|early.?return' daemon/src --glob '!bpfopt-suite/**' --glob '!**/*test*.rs'`
- Hits:
  - `daemon/src/commands.rs:236,572,693`：`OptimizeMode::should_apply()` 和 dry-run/apply 分支；这是模式分流，不是 program gate
  - `daemon/src/server.rs:200,219,282`：`remove_socket_file_if_present()`；纯 socket 清理
  - `daemon/src/passes/rotate.rs:50-64`：遇到 pseudo-call program 全局 skip；这是明确的 intraprocedural safety guard
  - `daemon/src/passes/wide_mem.rs:470-496`：XDP/TC probable packet pointer skip；明确的 verifier-conservative safety path
  - `daemon/src/passes/branch_flip.rs:89-111,153-179`：PMU 缺失 / 高 miss rate / 无 branch profile 时的保守 skip；明确算法 guard
  - `daemon/src/pass.rs:66`：注释提到 “gate optimization”，不是运行时壳
- 判断：
  - **没发现 benchmark harness 那类“本不该跑就早退”的隐式 filter/select/gate 残留**。
  - 命中的 live 分支要么是 apply/dry-run 模式选择，要么是 pass 级安全保守路径，属于合法短路。

### 矩阵 C：Python 侧删掉但 Rust 侧还有的 helper

- Command（精确 helper 名）: `rg -n -S 'rejit_result_has_any_apply|should_run_post_rejit|had_post_rejit_measurement|rejit_result_has_any_change' daemon/src --glob '!bpfopt-suite/**'`
- Result: `0 命中`
- Command（宽搜当前 changed/applied 形态）: `rg -n -S 'RejitResult|PassResult|ApplyResult|ServeOptimize|changed|applied' daemon/src --glob '!bpfopt-suite/**' | head -n 200`
- Hits:
  - `daemon/src/bpf.rs:1417-1421`：`RejitResult` 只是底层 syscall 结果，只有 `verifier_log`
  - `daemon/src/pass.rs:276-298`：`PassResult`
  - `daemon/src/commands.rs:23-42,99-106,116-135`：当前 socket 输出字段
  - `daemon/src/commands.rs:45-46`：`ServeOptimizeResponse` 仅为 `#[cfg(test)]` alias
  - `daemon/src/pass.rs:818-888`：`any_changed -> program_changed` 只是 pipeline 内部聚合
- 判断：
  - **没有发现** Python 本轮删掉的那几个 helper 在 Rust 侧的命名残留，也没看到“等价 post-rejit gate”。
  - Rust 侧保留的是正常的 pass/pipeline bookkeeping，不是 runner 级 decision helper。

### 矩阵 D：空壳 Rust 函数 / 单调用点 helper

- Command（精确 trivial body regex）: `rg -n -P 'fn [a-z_]+\([^)]*\)\s*(->\s*[^{]+)?\s*\{\s*(return\s+)?(true|false|Ok\(\(\)\)|None)\s*;?\s*\}' daemon/src --glob '!bpfopt-suite/**'`
- Result: `0 命中`
- Follow-up: `rg -n -S 'fn should_apply|fn build_pipeline|fn build_prog_load_fd_array|fn summarize_error' daemon/src/commands.rs && rg -n -S 'should_apply\(|build_pipeline\(|build_prog_load_fd_array\(|summarize_error\(' daemon/src --glob '!bpfopt-suite/**'`
- Hits:
  - `daemon/src/commands.rs:236-238`：`should_apply()` 一行 `matches!`
  - `daemon/src/commands.rs:244-245`：`build_pipeline()` 只转发到 `passes::build_full_pipeline()`
  - `daemon/src/commands.rs:363-365`：`build_prog_load_fd_array()` 只转发到 `build_rejit_fd_array()`
  - `daemon/src/commands.rs:386-388`：`summarize_error()` 只转发到 `error_headline()`
  - `daemon/src/commands.rs:423-430`：`maybe_attach_original_verifier_states()` 内部还有一个 `orig_insns.is_empty()` guard；当前唯一调用点在 `commands.rs:554`，而外层 `try_apply_one()` 已在 `533-547` 先短路
- 判断：
  - 没有 literal “`return true` / `Ok(())`” 空壳函数。
  - 但有几处**低价值 wrapper**和 **1 处冗余 defensive guard**，属于可继续删薄的死壳/样板。

### 矩阵 E：单字段二用 / 字段重命名但分支未改

- Command: `rg -n -S '\bchanged\b|\bapplied\b|\brequested\b|\brolled_back\b|\bskipped\b' daemon/src --glob '!bpfopt-suite/**'`
- Follow-up（查旧 alias 是否还在）: `rg -n -S 'final_disabled_passes|program_changed|\"pass\"|\bpass:\b' daemon/src/commands.rs daemon/src/server.rs daemon/src/pass.rs daemon/src --glob '!bpfopt-suite/**' --glob '!**/*test*.rs'`
- Hits:
  - `daemon/src/commands.rs:23-42,99-106,116-145`：wire 字段是 `changed` / `summary.applied` / `passes[*].pass_name` / `passes[*].action`
  - `daemon/src/pass.rs:726-733,885-889`：`program_changed` 只存在于内部 `PipelineResult`
  - `daemon/src/commands.rs:144-147`：`action = "rolled_back" | "kept"`
  - `final_disabled_passes`：`0 命中`
  - 旧 JSON alias `pass`：在当前 `daemon/src` live 代码里未发现
- 判断：
  - **没看到 lazy rename**。当前 daemon wire shape 已经收口到 `changed` / `summary.applied` / `pass_name`。
  - `program_changed` 仍存在，但它是**内部 pipeline 字段**，没有和外部 `changed` 并存暴露成重复 schema。

### 矩阵 F：Pass 内 heuristic fallback（合法保留白名单）

- Command: `rg -n -S 'fallback|Legacy|deprecated|compat' daemon/src --glob '!bpfopt-suite/**' --glob '!**/*test*.rs'`
- Hits:
  - `daemon/src/passes/branch_flip.rs:31-33,161-195`：无 per-site profile 时的 size-asymmetry fallback
  - `daemon/src/passes/map_inline.rs:1124-1240`：verifier-guided key extraction -> backward-scan -> pseudo-map-value fallback 链
  - `daemon/src/pass.rs:514-515,553-565`：`target_supported_encodings` 的 packed-only fallback；这是 capability fallback，不是 API 兼容壳
  - `daemon/src/bpf.rs:174,313,467,1191`：`gpl_compatible` 是 kernel struct mirror / ABI 命名，不是 legacy shim
- 判断：
  - **没发现 API 兼容壳**。
  - 命中项都属于算法保守退化、能力探测回退或 ABI 字段镜像，应该保留。

### 矩阵 G：死 pass 或死 pass option

- Command: `rg -n -S 'PassResult::(Unchanged|Skipped|Error)|pass\..*enabled|enabled_passes\.contains' daemon/src --glob '!bpfopt-suite/**'`
- Result: `0 命中`
- Follow-up（registry / benchmark 对照）:
  - `daemon/src/passes/mod.rs:52-118`：`PASS_REGISTRY` 有 12 个 live pass，包含 `branch_flip`
  - `daemon/src/pass.rs:672-676`：`default_enabled_passes()` 直接取完整 `PASS_REGISTRY`
  - `corpus/config/benchmark_config.yaml:18-29`：benchmark 默认 active list 只有 11 个 pass，**不含 `branch_flip`**
  - `runner/libs/rejit.py:868-886`：如果请求里包含 `branch_flip`，Python 还会专门准备 profile；说明它不是死 pass
- 判断：
  - **没找到死 pass**。
  - `branch_flip` 只是当前 benchmark 默认 profile 未启用，不是 daemon 死代码。
  - `disabled_passes` 是 live socket 协议面，当前 benchmark 默认不走它，但也不能判死。

### 矩阵 H：taxonomy 源字段在 Rust 端是否准确

- Command（daemon 侧）: `rg -n -S 'zero_sites_found|all_sites_rolled_back|applied_but_identical|no_passes_requested|program_changed' daemon/src --glob '!bpfopt-suite/**'`
- Command（Python consumer 侧）: `rg -n -S '_apply_record_no_change_reason|_apply_record_requested_site_totals|_site_counts_from_optimize_response|_apply_record_program_changed' corpus/driver.py runner/libs/rejit.py`
- Hits:
  - daemon 侧只命中内部 `program_changed`：`daemon/src/pass.rs:729,888`、`daemon/src/commands.rs:697,716,727,821,828,874`
  - Python 侧 taxonomy 发生在 `corpus/driver.py:517-540`、`543-565`
  - scan totals 来自 `runner/libs/rejit.py:556-566`
  - apply 结果字段规范化在 `runner/libs/rejit.py:639-711`
- 判断：
  - **Round 7 那 4 个 taxonomy bucket 全部是 Python 端推导，不是 daemon 原生字段。**
  - daemon 真正提供的是原语：`changed`、`summary.total_sites_applied`、`passes[*].sites_applied`、`passes[*].action`
  - 这套原语在“pass 真跑过”的情况下是够用的；但 `orig_insns` 空值短路直接返回 `passes=[]`，会让 Python 把“取不到 original bytecode”误判成普通 `zero_sites_found` / `no_change`

### 矩阵 I：metrics / observability field drift

- Command（daemon 输出面）: `rg -n -S 'serialize\(|Serialize|#\[serde' daemon/src --glob '!bpfopt-suite/**' | rg -v 'test'`
- Command（Python 消费面）: `rg -n -S '_normalize_apply_passes|_apply_result_from_response|_site_counts_from_optimize_response' runner/libs/rejit.py`
- Hits:
  - daemon 输出结构体：
    - `daemon/src/commands.rs:23-42` `OptimizeOneResult`
    - `daemon/src/commands.rs:88-96` `ProgramInfo`
    - `daemon/src/commands.rs:99-106` `OptimizeSummary`
    - `daemon/src/commands.rs:116-135` `PassDetail`
    - `daemon/src/pass.rs:339-360` `PassVerifyStatus` / `PassVerifyResult` / `PassRollbackResult`
  - Python 严格消费字段：
    - `runner/libs/rejit.py:201-238`：要求 `passes[*].pass_name` / `action` / `sites_applied`
    - `runner/libs/rejit.py:639-711`：要求 `summary.applied` / `changed` / `summary.total_sites_applied` / `summary.passes_executed`
    - `runner/libs/rejit.py:556-566`：scan counts 从 `passes` 推导
- 判断：
  - **当前 daemon -> Python 字段命名对齐，没有 live drift。**
  - 额外输出字段如 `program` / `passes_applied` / `timings_ns` / `attempts` 目前大多只是 debug payload，不影响 consumer。
  - 历史 alias（如 `summary.program_changed` / `pass` / `final_disabled_passes`）已经不在当前 live daemon 代码里，只出现在旧 docs/artifacts。

### 矩阵 J：无谓 abstraction

- Command: `rg -n -S 'trait ' daemon/src --glob '!bpfopt-suite/**' && rg -n -S 'impl [A-Za-z0-9_:<> ,]+ for [A-Za-z0-9_:<> ,]+' daemon/src --glob '!bpfopt-suite/**' | head -n 80`
- Follow-up: `rg -n -S 'MapValueReader|BpfMapValueReader' daemon/src --glob '!bpfopt-suite/**' --glob '!**/*test*.rs'`
- Hits:
  - `daemon/src/pass.rs:213,451,682`：`Analysis` / `BpfPass` / `AnyAnalysis`
  - `daemon/src/passes/mod.rs:52-118`：registry 驱动多 pass dispatch
  - `daemon/src/invalidation.rs:31-39,124-125`：`MapValueReader` + generic tracker
  - `daemon/src/analysis/*`、`daemon/src/passes/*`：多实现真实存在
- 判断：
  - pass dispatch / registry / analysis traits 都有多个实现和明确用途，**不是空 abstraction**。
  - `MapValueReader` 只有一个 production impl，但 generic tracker 和 mock 测试都在用，仍然合理。
  - 真正多余的是 `commands.rs` 里的几层一行 wrapper，以及 production build 里仍保留的 test-fixture `elf_parser` 模块。

## 2. `orig_insns` 短路详细分析

### 2.1 代码结构

- `daemon/src/commands.rs:477-478`：`try_apply_one()` 先拿 `(info, orig_insns) = bpf::bpf_prog_get_info(fd, true)`
- `daemon/src/bpf.rs:1206-1214`：`bpf_prog_get_info()` 实际调用 `bpf_prog_get_images()`
- `daemon/src/bpf.rs:565-583`：只有 `info.orig_prog_len > 0` 才申请 `orig_bytes`；否则直接返回空 `Vec`
- `daemon/src/commands.rs:481-485`：空 `orig_insns` 时，`orig_insn_count` 退回 `info.orig_prog_len / 8`
- `daemon/src/commands.rs:533-547`：只要 `orig_insns.is_empty()`，立刻返回

```rust
if orig_insns.is_empty() {
    return Ok(make_result(
        "ok",
        false,
        false,
        0,
        orig_insn_count,
        vec![],
        vec![],
        0,
        0,
        vec![],
        None,
    ));
}
```

- 这条 return 发生在下面这些步骤**之前**：
  - `daemon/src/commands.rs:549-551`：map ID 抓取
  - `daemon/src/commands.rs:552-560`：original verifier-state capture
  - `daemon/src/commands.rs:567-680`：pass manager / per-pass verify / pipeline scheduling
  - `daemon/src/commands.rs:693-713`：dry-run 结果结构化
  - `daemon/src/commands.rs:727-757`：`restored_original` / `no_change` / `identity_rejit` 区分

### 2.2 触发场景

- 当前 repo 内可证实的触发条件是：**kernel 报 `orig_prog_len == 0`，daemon 就拿不到 `orig_insns`**
- repo 自带文档给出的内核语义：
  - [docs/tmp/20260325/kernel_diff_unnecessary_changes_20260325.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260325/kernel_diff_unnecessary_changes_20260325.md:219)：`bpf_prog_get_info_by_fd` 对 non-capable 调用者可把 `info.orig_prog_len = 0`
  - [docs/tmp/20260321/bpfrejit_v2_design_gaps_20260321.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260321/bpfrejit_v2_design_gaps_20260321.md:142)：GET_ORIGINAL 至少应满足 `bpf_capable()` + raw-dump 语义
  - [docs/tmp/20260320/bpf_program_replacement_research_20260320.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260320/bpf_program_replacement_research_20260320.md:221)：`bpf_capable()` 需要 `CAP_BPF` 或 `CAP_SYS_ADMIN`
- **没找到任何 daemon 侧证据表明这跟 prog type、kinsn、或 verifier 限制有关。**
  - 这条短路发生在 pass scheduling / verifier 之前，所以不是 verifier 限制
  - kinsn/BTF 缺失会在更后面的 per-pass verify 路径报 rejected，不会让 `orig_insns` 先天为空
  - daemon 没有按 `prog_type` 对空 `orig_insns` 做任何区分逻辑

### 2.3 为什么它绕过 Round 7 taxonomy

- benchmark 的 scan 阶段走的是单程序 dry-run：
  - `runner/libs/rejit.py:627-635`：对每个 `prog_id` 发 `optimize(dry_run=True)`
  - `runner/libs/rejit.py:556-566`：scan counts 完全从 `response["passes"]` 推导
- apply 阶段同样走单程序 optimize：
  - `runner/libs/rejit.py:888-892`：对每个 `prog_id` 发 `optimize(dry_run=False)`
  - `runner/libs/rejit.py:639-711`：只消费 `changed` / `summary.*` / `passes`
- corpus taxonomy 在 Python 端推导：
  - `corpus/driver.py:527-540`：`zero_sites_found` / `all_sites_rolled_back` / `applied_but_identical` / `no_passes_requested`
  - `corpus/driver.py:533-539`：逻辑依赖 `requested_passes`、scan totals、`summary.total_sites_applied`、`changed`
- 所以一旦 daemon 因 `orig_insns.is_empty()` 返回：
  - `passes=[]`
  - `summary.total_sites_applied=0`
  - `changed=false`
  - `error_message=None`
- scan 阶段会被记成“零 site”；apply 阶段也会被记成普通 no-change。**Python 根本不知道这是 “缺 original bytecode” 而不是 “pass 没命中”。**

### 2.4 与 `optimize-all` 的不一致

- `daemon/src/server.rs:117-129`：`collect_live_program_candidates()` 对同样的 `orig_insns.is_empty()` 会直接 `bail!`
- 也就是说：
  - `optimize-all`：显式失败
  - `optimize`：静默成功 + 空结果
- 这已经不是“不同 UI 呈现”，而是**同一底层异常在两条入口上的语义分叉**

### 2.5 修复方向（只写方向，不实施）

- 不要再把 “缺 original bytecode” 伪装成 `status=ok + passes=[]`
- 两个可接受方向：
  - 方向 1：像 `optimize-all` 一样，把单程序 `optimize` 也改成显式错误
  - 方向 2：保留 `status=ok`，但必须落入明确 taxonomy bucket，例如新增 `no_original_bytecode`
- 无论选哪条，关键要求都一样：
  - **不能再返回 indistinguishable 的空成功结果**
  - **要让 Python 端能把它和 `zero_sites_found` / `all_sites_rolled_back` / `applied_but_identical` 分开**

## 3. 严重性排序的真 finding 清单

### 🔴 BLOCKER

- `daemon/src/commands.rs:533-547`，配对 `daemon/src/server.rs:117-129`
  - 单程序 `optimize` 在缺失 original bytecode 时静默返回 `ok + 空 passes`，而 `optimize-all` 已经 loud-fail。
  - 这违反 [docs/kernel-jit-optimization-plan.md](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md:18) 的 “零静默失败”，并直接绕过 Round 7 taxonomy。
  - 修复方向：统一两条入口语义，把该分支改成显式 surfaced outcome，而不是空成功结果。

### 🟡 SHOULD

- `daemon/src/main.rs:10`，`daemon/src/elf_parser.rs:2-3`，`daemon/src/insn.rs:452-456`
  - `elf_parser` 顶部直接写明它是 “ELF/BTF parsing helpers for real .bpf.o test fixtures”，当前主要调用者也是 `#[cfg(test)]` 辅助路径；但它仍通过 `mod elf_parser;` 编进 production daemon，并靠 `#![cfg_attr(not(test), allow(dead_code))]` 压警告。
  - 这是 production build 里的 test-fixture 死壳。
  - 修复方向：把这块收回 test-only 边界，不再让 release daemon 携带它。

- `daemon/src/commands.rs:423-430`
  - `maybe_attach_original_verifier_states()` 内部的 `orig_insns.is_empty()` guard 对当前唯一调用路径是冗余的；外层 `try_apply_one()` 已在 `533-547` 先短路。
  - 这不是 correctness bug，但属于“外层已经处理，内层壳还在”的残留。
  - 修复方向：在修正外层 missing-original 语义时，一并消掉重复 guard。

### 🟢 NICE

- `daemon/src/commands.rs:236-245`，`363-388`
  - `should_apply()` / `build_pipeline()` / `build_prog_load_fd_array()` / `summarize_error()` 都是单行 wrapper，live 调用点很少，没有承载独立策略。
  - 修复方向：后续 daemon 清薄时直接 inline。

## 4. 合理保留清单

- `daemon/src/server.rs:31-60`
  - invalidation reoptimization failure 会聚合后 `bail!`，不是 silent swallow。

- `daemon/src/pass.rs:950-973`
  - verifier reject 后恢复 pre-pass snapshot，同时保留 `sites_applied` 并打 `rollback`；这是 Python 端区分 `all_sites_rolled_back` 的必要原语。

- `daemon/src/passes/rotate.rs:50-64`
  - pseudo-call program 全局 skip 是明确的 intraprocedural safety boundary，不是 lazy gate。

- `daemon/src/passes/wide_mem.rs:470-496`
  - XDP/TC probable packet pointer skip 是 verifier-conservative path，应保留。

- `daemon/src/passes/branch_flip.rs:91-111,153-195`
  - 无 PMU 数据时整体 skip，以及 size-asymmetry fallback，都是算法保守路径，不是兼容壳。

- `daemon/src/passes/map_inline.rs:1124-1240`
  - verifier-guided key extraction 失败后退回 backward-scan，再退到 pseudo-map-value，是正常 heuristic fallback 链。

- `daemon/src/pass.rs:988-1017`
  - `pass_allowed()` / `validate_policy_pass_names()` 是 live 的 request policy 执行逻辑，不是 dead option。

## 5. 签收意见

- **lazy rename**：未发现。当前 daemon wire schema 没看到旧字段名和新字段名并存的 live 漂移；旧 alias 只留在历史 docs/artifacts。
- **删了 Python 没删 Rust**：未发现同型残留。Python 本轮删掉的 `rejit_result_has_any_apply` / `should_run_post_rejit` / `had_post_rejit_measurement` / `rejit_result_has_any_change` 在 daemon 里都没有命名或功能对等的活跃 helper。
- **orig_insns 短路绕过 taxonomy**：**确认存在，而且严重**。这不是“可能有一天会踩到”的风格问题；它是当前单程序 `optimize` 路径上的真实静默异常分支，并且与 `optimize-all` 已有行为冲突。
- **是否立刻需要派 fix codex**：**需要**。原因不是它一定在每次 benchmark 都触发，而是它一旦触发，scan/apply 两阶段都会被伪装成普通 no-change，直接污染覆盖率与 exclusion reason 统计。这个修复应在下一轮 daemon observability / taxonomy 校验前优先落掉。
