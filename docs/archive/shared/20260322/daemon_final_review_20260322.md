# daemon/src 最终代码审查 - 2026-03-22

审查范围：

- 逐个阅读 `daemon/src/` 下全部 19 个 Rust 文件
- 对照上一轮报告：`docs/tmp/20260322/daemon_code_review_20260322.md`、`docs/tmp/20260322/daemon_postfix_review_20260322.md`
- 实际运行：
  - `cargo test --quiet` in `daemon/`
  - `cargo check --tests` in `daemon/`

## 总结

当前版本相比上一轮 review **明显改善**，尤其是：

- `branch_flip` 已改成 true diamond 扫描，且变成 PGO-only：`daemon/src/passes/branch_flip.rs:253-294`
- `cond_select` 的 Pattern B 已删除，寄存器别名通过共享的 swap-safe 参数搬运修掉：`daemon/src/passes/cond_select.rs:331-364`，`daemon/src/passes/utils.rs:96-214`
- `rotate` 现在会检查 provenance 和 live-out：`daemon/src/passes/rotate.rs:233-303`
- `fd_array` 已从 pass 打通到 REJIT：`daemon/src/pass.rs:338-375`，`daemon/src/main.rs:434-446`，`daemon/src/main.rs:584-595`
- rewrite 后的 annotation remap 已接上：`daemon/src/pass.rs:122-149`，各 rewrite pass 都调用了 `program.remap_annotations(...)`
- `spectre` 已不再是 placeholder，而是真正发 `bpf_speculation_barrier()` kfunc：`daemon/src/passes/spectre.rs:73-95`
- `verifier_log` 已进入 REJIT 失败路径：`daemon/src/bpf.rs:315-325`，`daemon/src/main.rs:455-469`，`daemon/src/main.rs:600-613`

但它还没有到“架构收口、行为闭环、可长期扩展”的状态。最主要的未完成项有 4 个：

1. **PGO 闭环没有打通到任何实际 pass 决策**。`--pgo` 现在只采样 program hotness；`branch_flip` 需要的是 branch profile，而 profiler 返回的 `branch_profiles` 仍然是空的：`daemon/src/profiler.rs:158-179`，`daemon/src/pass.rs:155-160`，`daemon/src/passes/branch_flip.rs:119-136`
2. **pass 之间并不真正独立**。默认 pipeline 和 `--passes` 子集 pipeline 的顺序不一致，说明当前结果依赖隐式顺序：`daemon/src/passes/mod.rs:40-45` 对比 `daemon/src/passes/mod.rs:74-82`
3. **`main.rs` 仍然是 god file**。819 行同时承担 CLI、bootstrap、PGO、enumerate/rewrite/apply、server、watch、signal handling：`daemon/src/main.rs:24-819`
4. **新增 pass / 新增 kfunc 的扩展点仍然过于手工**。`passes/mod.rs`、`main.rs` help、`pass.rs::KfuncRegistry`、`pass.rs::module_fd_for_pass()`、`kfunc_discovery.rs` 都要手改，而且已经出现了文档漂移：`main.rs` help 没列出 `endian_fusion`，见 `daemon/src/main.rs:27-30`

## 关键发现

### HIGH 1: PGO 运行链路只到 program hotness，没到 branch-guided rewrite

- `main.rs` 的 `collect_pgo_data()` 会调用 `profiler::collect_program_profiling()`：`daemon/src/main.rs:166-193`
- `collect_program_profiling()` 明确只返回 `program_hotness`，`branch_profiles` 为空：`daemon/src/profiler.rs:153-179`
- `PassManager::run_with_profiling()` 只会把 `branch_profiles` 注入 annotation：`daemon/src/pass.rs:623-638`
- `BranchFlipPass` 只读 `program.annotations[pc].branch_profile`：`daemon/src/passes/branch_flip.rs:119-136`

结论：**真实运行时的 `--pgo` 目前不会改变 `branch_flip`，也不会影响任何现有 pass 的改写决策。**

### HIGH 2: pass 顺序是隐式契约，而且默认/自定义 pipeline 不一致

- 默认 pipeline 顺序：`wide_mem -> rotate -> cond_select -> extract -> endian_fusion -> branch_flip`：`daemon/src/passes/mod.rs:31-47`
- `build_pipeline_with_passes()` 的固定顺序却是：`wide_mem -> rotate -> cond_select -> branch_flip -> extract -> endian_fusion -> speculation_barrier`：`daemon/src/passes/mod.rs:50-90`
- `branch_flip` 的 PGO annotation 语义本来就依赖前面 pass 不改变其意义；现在默认和自定义路径顺序不一致，说明这不是“独立 pass 集合”，而是“靠顺序维持行为”的 pipeline

结论：**pass 之间存在顺序耦合，而且这种耦合没有被框架显式表达。**

### HIGH 3: `main.rs` 仍是 god file

`daemon/src/main.rs` 现在同时包含：

- CLI 定义：`daemon/src/main.rs:24-106`
- daemon bootstrap / kfunc discovery / platform detect：`daemon/src/main.rs:108-157`
- PGO 配置与 hotness ranking：`daemon/src/main.rs:160-253`
- enumerate/rewrite/apply/apply-all/profile：`daemon/src/main.rs:257-616`
- serve/socket protocol：`daemon/src/main.rs:618-729`
- watch loop / signal handling：`daemon/src/main.rs:731-819`

结论：**`serve/watch/apply` 都还没拆出去，`main.rs` 还是单文件调度中心。**

### MEDIUM 4: `watch` 逻辑是“一次看过就不再看”，失败和 no-op 也不会重试

- `cmd_watch()` 里对每个 `ranked_ids` 先 `optimized.insert(*prog_id)`，再调用 `try_apply_one()`：`daemon/src/main.rs:767-777`
- 因此第一次观察到的程序即使 `Ok(false)` 或 `Err(_)`，后续轮次也不会再尝试：`daemon/src/main.rs:757-761`

结论：这会让 watch 模式更像 “seen set” 而不是 “optimized set”。如果程序第一次出现时是冷的、profiling 没采到、或 REJIT 临时失败，它以后都不会再被处理。

### MEDIUM 5: `PlatformCapabilities` 是弱检测，不是强能力探测

- x86_64 只解析 `/proc/cpuinfo` 第一条 `flags` 行：`daemon/src/pass.rs:414-437`
- `aarch64` 只硬编码 `has_cmov = true`：`daemon/src/pass.rs:399-406`
- 没有 `CPUID` / `getauxval()` / `/sys/devices/system/cpu` 等更强来源
- 唯一测试只验证“不 panic”，不是验证检测准确：`daemon/src/pass.rs:1473-1489`

结论：**它能做粗略 gating，但还不能叫“真的检测了 CPU 能力”。**

### MEDIUM 6: `verifier_log` 已接入 REJIT 失败路径，但实现还是脆的

- `bpf_prog_rejit()` 会分配 log buffer，并在失败时把 verifier log 拼进 error string：`daemon/src/bpf.rs:285-325`
- `cmd_apply()` / `try_apply_one()` 通过查找 `"verifier log:\n"` 再调用 `parse_verifier_log()`：`daemon/src/main.rs:455-469`，`daemon/src/main.rs:600-613`
- 但 parser 模块注释写的是 “captured with `log_level=2`”，实际 `bpf_prog_rejit()` 用的是 `log_level = 1`：`daemon/src/verifier_log.rs:2-13` 对比 `daemon/src/bpf.rs:293`

结论：**接上了，但还是 string-scraping 集成，不是结构化接口。**

## 逐项回答

### 1. 新增一个 pass 需要改哪些文件？有没有不必要的 boilerplate？

结论：**如果是纯 pass，至少要改 3 处；如果还带新 analysis 或新 kfunc，改动面会继续扩到 5-10 处。boilerplate 仍然偏多。**

最少改动面：

- 新建 `daemon/src/passes/<new>.rs`
- 在 `daemon/src/passes/mod.rs:4-19` 增加 `mod` 和 `pub use`
- 在 `daemon/src/passes/mod.rs:31-47` / `daemon/src/passes/mod.rs:50-90` 注册到 default pipeline 和 named pipeline
- 如果要对外暴露 CLI 帮助，还要改 `daemon/src/main.rs:27-30`

如果 pass 依赖新 analysis：

- 新建 `daemon/src/analysis/<new>.rs`
- 在 `daemon/src/analysis/mod.rs:4-10` 导出
- 在 `daemon/src/passes/mod.rs:35-37` / `daemon/src/passes/mod.rs:58-60` 注册 analysis

当前存在的 boilerplate / 漂移点：

- pipeline 注册写了两遍：`daemon/src/passes/mod.rs:31-47` 和 `daemon/src/passes/mod.rs:50-90`
- `main.rs` help 又写了第三遍，而且已经漂移，遗漏了 `endian_fusion`：`daemon/src/main.rs:27-30`
- 每个 rewrite pass 都重复一遍“scan/filter/rewrite/fixup/remap/log/module_fd”模板：
  - `rotate`: `daemon/src/passes/rotate.rs:125-198`
  - `extract`: `daemon/src/passes/extract.rs:189-264`
  - `endian_fusion`: `daemon/src/passes/endian.rs:283-355`
  - `cond_select`: `daemon/src/passes/cond_select.rs:226-311`
  - `spectre`: `daemon/src/passes/spectre.rs:68-148`
- `required_analyses()` 只是字符串声明，真正执行时每个 pass 又自己 `analyses.get(...)` 一遍，重复且不权威：
  - trait 定义：`daemon/src/pass.rs:289-306`
  - 预计算逻辑：`daemon/src/pass.rs:574-582`
  - 典型 pass 自己再取 analysis：`daemon/src/passes/rotate.rs:61-64`

### 2. pass 之间的耦合：每个 pass 是否真正独立？有没有隐式依赖？

结论：**不独立；主要靠隐式顺序和共享协议工作。**

证据：

- 默认/自定义 pipeline 顺序不一致：`daemon/src/passes/mod.rs:40-45` 对比 `daemon/src/passes/mod.rs:74-82`
- 所有 size-changing pass 都依赖同一套隐式协议：
  - 必须维护 `addr_map`
  - 必须调用 `fixup_all_branches(...)`
  - 必须调用 `program.remap_annotations(...)`
  - 必须自己记录 `required_module_fds`
- `branch_flip` 甚至要在 generic branch fixup 之后再手工把自己 special-case 的 offset 写回去：`daemon/src/passes/branch_flip.rs:221-230`
- `module_fd_for_pass()` 用 pass 名字硬编码映射到 kfunc 名字：`daemon/src/pass.rs:347-360`
- `required_analyses()` 只是软提示，不是强依赖；registry miss 也不会报错：`daemon/src/pass.rs:574-582`

按具体 pass 看：

- `wide_mem` 最独立，纯 BPF rewrite，不依赖 kfunc：`daemon/src/passes/wide_mem.rs:327-497`
- `rotate` / `extract` / `endian_fusion` / `cond_select` 都共享 kfunc 参数搬运、caller-saved 约束和 module FD 约定：`daemon/src/passes/utils.rs:55-214`
- `branch_flip` 对 annotation remap 和 PGO profile 的位置最敏感：`daemon/src/passes/branch_flip.rs:119-145`
- `spectre` 也不是独立 pass，它依赖 kfunc discovery、module FD 和 branch fixup：`daemon/src/passes/spectre.rs:53-148`

### 3. kfunc 注册流程：新增一个 kinsn 需要改多少代码？

结论：**现在还是手工多点修改。新增一个 kfunc，保守估计至少 4 个生产代码点 + 4 个测试/默认初始化点。**

生产代码必须改的地方：

- `daemon/src/pass.rs:326-341` 给 `KfuncRegistry` 加字段
- `daemon/src/pass.rs:347-360` 给 `module_fd_for_pass()` 加 pass-name -> kfunc-name 映射
- `daemon/src/kfunc_discovery.rs:19-27` 给 `KNOWN_KFUNCS` 增加 `(kfunc_name, module_name)`
- `daemon/src/kfunc_discovery.rs:295-304` 在 discovery 的 `match` 里把 BTF ID 写回 registry

默认值 / 测试还要改的地方：

- `daemon/src/pass.rs:649-660` `PassContext::test_default()`
- `daemon/src/pass.rs:1189-1315` 这几组手写 `KfuncRegistry { ... }` 测试 literal
- `daemon/src/kfunc_discovery.rs:233-245` discovery 初始 registry literal

如果这个 kfunc 对应一个新 pass，还要再改：

- `daemon/src/passes/mod.rs:4-19`, `31-47`, `50-90`
- `daemon/src/main.rs:27-30`

额外的架构问题：

- `module_fd_for_pass()` 是按 pass 名映射，不是按“实际发射过哪些 kfunc”映射：`daemon/src/pass.rs:347-360`
- `endian_fusion` 里 16/32/64 三个 kfunc 被 pass 级 API 折叠成一个名字，这隐含了“它们都来自同一个 module FD”的假设：`daemon/src/pass.rs:353`

### 4. 死代码：还有 `#[allow(dead_code)]` 吗？还有未使用的函数吗？

结论：**还有不少。无 suppress 的编译告警只剩 3 条，但 `#[allow(dead_code)]` 仍然很多，且有几处 helper 明显只在测试里用。**

仍存在的 `#[allow(dead_code)]`：

- `daemon/src/analysis/liveness.rs:11`
- `daemon/src/analysis/cfg.rs:8`, `daemon/src/analysis/cfg.rs:18`, `daemon/src/analysis/cfg.rs:26`
- `daemon/src/insn.rs:220`, `daemon/src/insn.rs:231`, `daemon/src/insn.rs:242`
- `daemon/src/kfunc_discovery.rs:35-70`
- `daemon/src/pass.rs:23`, `daemon/src/pass.rs:63`, `daemon/src/pass.rs:80`, `daemon/src/pass.rs:93`, `daemon/src/pass.rs:169`, `daemon/src/pass.rs:253`, `daemon/src/pass.rs:265`, `daemon/src/pass.rs:286`, `daemon/src/pass.rs:325`, `daemon/src/pass.rs:450`, `daemon/src/pass.rs:534`, `daemon/src/pass.rs:646`
- `daemon/src/profiler.rs:52`
- `daemon/src/passes/utils.rs:222`, `daemon/src/passes/utils.rs:227`
- `daemon/src/passes/wide_mem.rs:42`

这次实际跑出来的未抑制告警只有 3 个：

- `daemon/src/pass.rs:445` `Arch::Aarch64` never constructed
- `daemon/src/profiler.rs:88` `PgoAnalysis.total` never read
- `daemon/src/profiler.rs:129` `HotnessRanking.observation_window` never read

明显只在测试里用、生产代码未消费的函数/接口：

- `daemon/src/passes/utils.rs:223-248` `insn_iter_skip_ldimm64` / `InsnIterSkipLdimm64`
- `daemon/src/pass.rs:170-172` `BpfProgram::has_transforms`
- `daemon/src/pass.rs:535-536` `PassManager::pass_count`
- `daemon/src/pass.rs:647-665` `PassContext::test_default`

结论不是“完全没有死代码”，而是“**大部分死代码被 `allow(dead_code)` 压掉了**”。

### 5. 测试覆盖：关键路径是否都有测试？有没有 placeholder 测试？

结论：**pass 局部单测很强，但主流程集成测试明显缺失；确实还有 placeholder/弱断言测试。**

这次跑的结果：

- `cargo test --quiet`：229 tests passed
- `cargo check --tests`：通过，但有 3 个 dead-code warning

覆盖比较好的部分：

- `wide_mem` pattern/branch-fixup：`daemon/src/passes/wide_mem.rs:549-1197`
- `cond_select` 别名安全穷举：`daemon/src/passes/cond_select.rs:821-931`
- `rotate` provenance/live-out：`daemon/src/passes/rotate.rs:576-623`
- BTF mixed-kind parsing：`daemon/src/kfunc_discovery.rs:497-575`
- verifier log parser：`daemon/src/verifier_log.rs:353-463`

关键缺口：

- `main.rs` 没有任何 `#[cfg(test)]`；`apply` / `try_apply_one` / `serve` / `watch` 都没有单测
- 没有 mock `bpf_prog_rejit()` 的集成测试，无法验证真实 `fd_array` / REJIT 失败路径
- 没有真正的 end-to-end PGO 测试，只有手工构造 profile

明显偏 placeholder / 弱断言的测试：

- `daemon/src/kfunc_discovery.rs:452-460`
  `test_discover_kfuncs_no_modules_loaded()` 只是断言 “要么 -1 要么 >0”，基本等于“函数别 panic”
- `daemon/src/pass.rs:1473-1489`
  `test_platform_detect_returns_valid_result()` 只验证 detect 能跑完，不验证能力位真假
- `daemon/src/profiler.rs:374-389`
  `profiling_data_from_pgo_analysis()` 只测 struct 组装，不测真实采样链路
- `daemon/src/pass.rs:1421-1465`
  `test_run_with_profiling_enables_branch_flip()` 使用手工塞入的 `branch_profiles`，不是实际 profiler 输出
- `daemon/src/verifier_log.rs:441-463`
  `parse_verifier_rejection_from_rejit_error()` 用模拟字符串，不是实际 REJIT 返回值

### 6. `main.rs` 是否还是 god file？`serve/watch/apply` 拆分了吗？

结论：**还是；没有拆。**

证据已经很直接：

- 文件总长 819 行：`daemon/src/main.rs`
- `cmd_apply()`：`daemon/src/main.rs:383-472`
- `try_apply_one()`：`daemon/src/main.rs:546-616`
- `cmd_serve()` / `handle_client()` / `process_request()`：`daemon/src/main.rs:620-729`
- `cmd_watch()`：`daemon/src/main.rs:731-805`

这几个职责都还留在 `main.rs`，没有拆成 `apply.rs` / `serve.rs` / `watch.rs` / `bootstrap.rs` 一类模块。

### 7. PGO 闭环是否真的通了？从哪里到哪里？

结论：**只通了 “采样 -> 打印/排序”，没有通到 “采样 -> branch-guided rewrite”。**

实际链路是：

1. CLI `--pgo` -> `PgoConfig`：`daemon/src/main.rs:33-46`, `daemon/src/main.rs:137-143`
2. `collect_pgo_data()` -> `profiler::collect_program_profiling()`：`daemon/src/main.rs:166-193`
3. profiler 采两次 `run_cnt/run_time_ns`，产出 `ProfilingData { program_hotness, branch_profiles: {} }`：`daemon/src/profiler.rs:153-179`
4. `PassManager::run_with_profiling()` 只注入 `branch_profiles` 到 annotation：`daemon/src/pass.rs:623-638`
5. `branch_flip` 只看 `annotation.branch_profile`：`daemon/src/passes/branch_flip.rs:119-136`

卡住的地方有两个：

- profiler 当前没有 branch-level 数据，只返回 `program_hotness`：`daemon/src/profiler.rs:158-176`
- `program_hotness` 没有任何 pass 消费，甚至字段本身都被 `#[allow(dead_code)]` 掩着：`daemon/src/pass.rs:55-64`

唯一真的用到 hotness 的地方是 watch 排序：

- `rank_programs_by_hotness()`：`daemon/src/main.rs:208-253`
- `cmd_watch()`：`daemon/src/main.rs:740-779`

所以当前 PGO 闭环的真实状态是：

- `profile` 子命令能看 stats
- `watch` 能按热度排序程序
- **但 `--pgo` 不会改变任何现有 pass 的 rewrite 决策**

### 8. `PlatformCapabilities` 是否真的检测了 CPU 能力？

结论：**做了粗粒度检测，但还谈不上“真的检测了”。**

现状：

- x86_64：
  - 读 `/proc/cpuinfo` 第一条 `flags`：`daemon/src/pass.rs:417-425`
  - 用字符串包含判断 `bmi1/bmi2/cmov/movbe`：`daemon/src/pass.rs:429-436`
- aarch64：
  - 只设置 `has_cmov = true` 和 `arch = Aarch64`：`daemon/src/pass.rs:399-406`

问题：

- 没用 `is_x86_feature_detected!()` / raw CPUID
- 没用 `getauxval()` 看 ARM feature bits
- 没有 fallback/consistency check
- 测试没有断言任何真实能力位：`daemon/src/pass.rs:1473-1489`

所以更准确的表述应是：**当前是 lightweight feature sniffing，不是 robust capability detection。**

### 9. `verifier_log` 是否真的接入了 REJIT 失败路径？

结论：**接入了，但方式比较脆。**

正向证据：

- `bpf_prog_rejit()` 在失败时会把 verifier log 拼进 error string：`daemon/src/bpf.rs:315-320`
- `cmd_apply()` 会从 error string 中找 `"verifier log:\n"`，再调用 parser：`daemon/src/main.rs:455-469`
- `try_apply_one()` 也做了同样的事：`daemon/src/main.rs:600-613`
- parser 本身有真实风格日志测试：`daemon/src/verifier_log.rs:353-463`

不足：

- 这是 string-based integration，不是结构化错误类型
- parser 注释和实际 `log_level` 不一致：`daemon/src/verifier_log.rs:2-13` vs `daemon/src/bpf.rs:293`

所以这项的判定是：**“是，已经接上失败路径；但实现仍偏脆弱”**。

### 10. 整体架构是否比上次 review 改善了？

结论：**是，且是实质性改善；但还没有收口。**

相对上一轮，当前明确已经改善的点：

- `branch_flip` 从错误 CFG 变成了 true diamond + PGO-only：`daemon/src/passes/branch_flip.rs:253-294`
- `cond_select` 砍掉了错误 Pattern B：`daemon/src/passes/cond_select.rs:331-364`
- `cond_select` 寄存器别名问题通过共享参数搬运修掉，并且有穷举测试：`daemon/src/passes/utils.rs:96-214`，`daemon/src/passes/cond_select.rs:821-931`
- `rotate` provenance 检查补上了“dst 在 MOV 后被改写”的场景：`daemon/src/passes/rotate.rs:241-248`，`daemon/src/passes/rotate.rs:576-623`
- annotation remap 已落地：`daemon/src/pass.rs:122-149`
- `fd_array` 已从 kfunc discovery/pass/apply 串起来：`daemon/src/pass.rs:338-375`，`daemon/src/main.rs:434-446`
- `spectre` 从 placeholder 变成真实 kfunc barrier：`daemon/src/passes/spectre.rs:73-95`
- `analysis/pgo.rs` 这套旧 abstraction 已消失，至少没有再双轨并行到那个程度

仍然没改善到位的点：

- PGO 仍然没闭环到实际 rewrite
- pass 注册 / kfunc 注册仍然 stringly-typed、手工化
- `main.rs` 仍没拆
- `PlatformCapabilities` 仍弱

我的判断：

- **比上次 review 好很多，已经从“高风险原型”走到了“框架成形但闭环未完成”**
- **但还不能宣称 architecture 已经 clean/closed**

## 附加发现

### MEDIUM: `build_pipeline_with_passes()` 会静默忽略未知 pass 名

- 注释里已经写明 Unknown names are silently ignored：`daemon/src/passes/mod.rs:54-55`
- 这会让 CLI typo、pass 重命名、help 漂移都更难发现

### LOW: `PassManager` 的 targeted invalidation 基本是多余样板

- 先按已知类型逐个 `invalidate`：`daemon/src/pass.rs:587-604`
- 然后马上 `invalidate_all()`：`daemon/src/pass.rs:605-606`

这不是 correctness bug，但说明框架里还有没收干净的样板代码。

## 验证记录

- `cargo test --quiet` in `daemon/`
  - 结果：`229 passed; 0 failed`
- `cargo check --tests` in `daemon/`
  - 结果：通过
  - 额外告警：
    - `daemon/src/pass.rs:445` `Arch::Aarch64` never constructed
    - `daemon/src/profiler.rs:88` `PgoAnalysis.total` never read
    - `daemon/src/profiler.rs:129` `HotnessRanking.observation_window` never read

## 最终结论

如果目标是“和上次 review 相比是否进步”，答案是 **明显进步**。

如果目标是“是否已经是一个低-boilerplate、弱耦合、PGO/verifier/kfunc 全闭环的 daemon 架构”，答案仍然是 **还没有**。

我会优先建议下一轮只做 4 件事：

1. 把 PGO 真正接到 `branch_flip` 或删掉 `--pgo`
2. 把 pass 注册和 kfunc 注册改成单一声明源，去掉 `passes/mod.rs` / `main.rs` / `module_fd_for_pass()` 的三份手写列表
3. 拆 `main.rs`，至少拆出 `apply.rs`、`serve.rs`、`watch.rs`
4. 让 `watch` 只在“成功优化”后才把程序放进 `optimized` 集合
