# BpfReJIT 全项目 Round-2 Review

审查日期：2026-03-22  
审查输入：`docs/kernel-jit-optimization-plan.md`、`docs/tmp/20260322/full_project_review_20260322.md`、当前工作树  
实际检查：`make daemon-tests` 通过（241 tests）；`make python-tests` 失败

## 0. 结论

今天的改动把系统从“很多骨架未接线”推进到了“主路径基本成型”，尤其是：

- `daemon/src/` 的 `main.rs` 拆分、`PASS_REGISTRY`、verifier log、rollback、daemon serve 接线都是真改进。
- `module/` 上一轮最严重的 UB / 跨架构语义错误基本修完了。
- `Makefile` 的 x86 主 pipeline 现在明显更干净。

但还没到“整体收口”的状态。当前最突出的剩余问题有三个：

1. `corpus` 新的 daemon-socket 路径把 daemon 结果压扁成了 `bool applied`，同时 Python 结果层还在 `rejit` / `recompile` 双 schema 混用；这使得今天的 `applied=2` 既不可解释，也不可审计。  
   关键代码：`daemon/src/server.rs:95-112`、`runner/src/kernel_runner.cpp:725-748`、`corpus/modes.py:620-623`、`corpus/modes.py:879-885`、`runner/src/common.cpp:421-428`。
2. “PGO 闭环已完成”这个说法仍然偏强。接线是修好了，但 profiler 仍只有 program-level hotness，`branch_flip` 仍是 branch-profile 才能启用。  
   关键代码：`daemon/src/commands.rs:20-47`、`daemon/src/pass.rs:672-681`、`daemon/src/profiler.rs:158-177`、`daemon/src/passes/branch_flip.rs:119-132`。

## 1. 上轮 4 个 HIGH 是否修好

| 上轮 HIGH | Round-2 结论 | 证据 |
|---|---|---|
| runtime-guided / PGO 没闭环 | **部分修复** | 已接线到 apply/apply-all/watch/serve：`daemon/src/commands.rs:20-47`、`daemon/src/commands.rs:304`、`daemon/src/commands.rs:551`、`daemon/src/pass.rs:672-681`。但 profiler 仍明确返回空 `branch_profiles`：`daemon/src/profiler.rs:158-177`；`branch_flip` 仍是 PGO-only：`daemon/src/passes/branch_flip.rs:119-132`。 |
| Spectre 还是 placeholder | **代码基本修好，测试/文档没跟上** | pass 现在插入真实 `bpf_speculation_barrier()` kfunc：`daemon/src/passes/spectre.rs:53-96`；module 侧已有 x86/arm64 barrier：`module/x86/bpf_barrier.c:20-67`、`module/arm64/bpf_barrier.c:35-87`。但 `tests/unittest/rejit_spectre.c` 还在按 `JA+0` placeholder 写：`tests/unittest/rejit_spectre.c:7-10`、`tests/unittest/rejit_spectre.c:152-176`。 |
| `module/` 有 UB + ARM64 rotate 语义错 | **已修复** | `extract(len==64)` 保护：`module/x86/bpf_extract.c:38-45`、`module/arm64/bpf_extract.c:35-42`；`rotate(shift==0)` 保护：`module/x86/bpf_rotate.c:26-32`、`module/arm64/bpf_rotate.c:29-35`；ARM64 rotate 语义已与 x86 对齐：`module/arm64/bpf_rotate.c:3-20`、`module/arm64/bpf_rotate.c:93-127`。 |
| 死代码 / compat 债太重 | **未修完，只是改善** | 上轮是 `51` 处 `allow(dead_code)`；当前 `daemon/src` 仍有 `45` 处，主要集中在 `daemon/src/kfunc_discovery.rs`（19）和 `daemon/src/pass.rs`（13）。典型位置：`daemon/src/pass.rs:23`、`daemon/src/pass.rs:63-64`、`daemon/src/pass.rs:80`、`daemon/src/pass.rs:93`、`daemon/src/kfunc_discovery.rs:35-71`、`daemon/src/kfunc_discovery.rs:236`。 |

## 2. Component Review

### 2.1 `daemon/src/`

**明显进步**

- `main.rs` 已拆成 CLI + `commands.rs` + `server.rs`，结构比上轮合理得多：`daemon/src/main.rs:15`、`daemon/src/main.rs:170-176`。
- rollback / verifier log / PGO / `PASS_REGISTRY` 都是实接线，不再是摆设：`daemon/src/bpf.rs:578-648`、`daemon/src/commands.rs:64-81`、`daemon/src/commands.rs:288-432`、`daemon/src/passes/mod.rs:31-93`。

**剩余问题**

1. `serve` 仍是单连接串行服务，不是稳定 daemon protocol。  
   `cmd_serve()` 接到 client 后直接 inline `handle_client()`：`daemon/src/server.rs:43-47`；`handle_client()` 会一直读到 EOF：`daemon/src/server.rs:75-90`。一个长连接就能独占服务。

2. 协议仍然太薄，而且是无 schema 的 `serde_json::Value`。  
   `process_request()` 只认 `"cmd"` / `"prog_id"`，没有版本号、没有 typed request/response、没有 rollback / no-op / per-pass 细节：`daemon/src/server.rs:95-112`。

3. `watch` 语义离 production 还差一截。  
   一旦某个 prog id 进了 `optimized` 或 `no_op` 集合就永不重试：`daemon/src/server.rs:143-177`。没有 unload 清理、没有内容变更检测、没有重新评估机制。

4. rollback attribution 仍然过粗。  
   当前每个改动过的 pass 都被保守记成覆盖整个最终程序 `0..program.insns.len()`：`daemon/src/pass.rs:643-657`。这只能做“最后修改 pass 猜测”，不能做可信 blame。

5. 新增逻辑还有明显重复。  
   `cmd_apply()` 和 `try_apply_one()` 各自维护了一套几乎相同的 rollback / relocate / rejit retry loop：`daemon/src/commands.rs:288-432` 对 `daemon/src/commands.rs:540-647`。这会提高后续修 bug 的漂移风险。

### 2.2 `runner/`

**明显进步**

- daemon-socket 路径和 CPU freq fix 是真实修复：`runner/src/kernel_runner.cpp:1245-1304`。

**剩余问题**

1. daemon socket client 仍是 brittle string matching。  
   `daemon_socket_optimize()` 只搜 `"status":"ok"` 和 `"applied":true"`：`runner/src/kernel_runner.cpp:725-748`。只要 daemon 响应字段扩展或排序变化，runner 侧就容易失配。

2. producer / consumer schema 仍在漂移。  
   C++ 现在只写 `sample.rejit`：`runner/src/common.cpp:421-428`；但 Python 结果层仍默认补 `sample.recompile`：`runner/libs/results.py:48-64`、`runner/libs/results.py:233-249`；`runner/libs/corpus.py` 的 failure summary 还在读 `sample.recompile.error`：`runner/libs/corpus.py:533-543`。  
   另外 paired phase 名也没统一，C++ 写 `phase="rejit"`：`runner/src/kernel_runner.cpp:1627-1629`，而 `collapse_command_samples()` 还在等 `phase=="recompile"`：`runner/libs/results.py:157-161`。

3. generic runner 仍被 Katran 特化逻辑污染。  
   Katran 常量和 fixture 还在主文件里：`runner/src/kernel_runner.cpp:71-78`、`runner/src/kernel_runner.cpp:232-235`。

4. ARM64/AWS 辅助脚本没有跟上今天的删 policy / 改 build path。  
   仍用 `daemon/build`：`runner/scripts/aws_arm64.sh:34-35`；仍要求不存在的 `micro/policies/*` 和 `corpus/policies/*`：`runner/scripts/aws_arm64.sh:572`、`runner/scripts/aws_arm64.sh:576`、`runner/scripts/aws_arm64.sh:583-595`。这条线现在是坏的。

### 2.3 `micro/`

**结论**

- 今天“删 policy”这个方向是对的，runtime correctness mismatch 检查也是真改进：`micro/driver.py:558-581`。
- 但 `micro/driver.py` 仍保留了 import/path fallback 和旧 CLI shim：`micro/driver.py:18-63`、`micro/driver.py:125-129`。  
  这是低风险问题，不是 blocker，但说明 migration 还没完全收口。

### 2.4 `corpus/`

这是本轮最需要优先修的 component。

1. **`applied=2` 的直接根因不是单一 pass，而是“选择层 + 观测层一起退化”。**  
   现在 `corpus` 只要有 socket 就直接开启 `--rejit`：`corpus/modes.py:360-379`；每个 target 还会临时起一个 daemon：`corpus/modes.py:545-570`。这等于把旧的 per-program family selection 整体换成了 opaque daemon-auto mode。  
   对比旧 authoritative 结果，之前 `policy-file` 模式下会显式记录 `requested_families`，例如 `endian`：`corpus/results/corpus_authoritative_20260320.json:796-815`；当时 `summary.applied_programs=26`：`corpus/results/corpus_authoritative_20260320.json:61-68`。现在这层“请求了什么 family”信息已经丢失了。

2. **结果 schema 现在是半迁移状态。**  
   `v5_compile_applied` / `v5_run_applied` 从 `sample.rejit.applied` 取：`corpus/modes.py:620-621`；但 `requested_families_*` 仍从 `sample.recompile` 取：`corpus/modes.py:444-447`、`corpus/modes.py:622-623`；failure reason 也还是看 `sample.rejit.error`，而 daemon-socket 成功但 `applied=false` 时根本没有原因：`corpus/modes.py:879-885`。  
   这会导致 family-level attribution、failure summary、后续 root-cause 分析都失真。

3. **daemon-socket 路径的 observability 太差。**  
   daemon 侧 `"optimize"` 只返回 `{status, applied}`：`daemon/src/server.rs:103-112`；runner 侧也只保留 `{ok, applied, error}`：`runner/src/kernel_runner.cpp:664-748`。  
   这意味着当前 JSON 只能回答“有没有 apply”，回答不了“为什么没 apply / 哪个 pass rollback / 是否 verifier reject / no-op 还是 disabled-all”。

4. `run_target_locally()` 的 daemon 启动是固定睡眠 `0.5s`，有 race。  
   `corpus/modes.py:546-555`。

5. headline path 仍保留自动 `host-fallback`。  
   CLI description 还写着 automatic fallback：`corpus/modes.py:125-130`；执行上 build/BTF/guest smoke 任一失败就 silently 切到 host-fallback：`corpus/modes.py:1287-1361`。

6. 旧路径残留仍多。  
   `corpus/driver.py:98`、`corpus/config/macro_corpus.yaml:15-16`、`corpus/directive_census.py:128-130` 还在指向 `daemon/build/...`。  
   当前 authoritative artifact 也仍写着 `scanner_binary` 和 `policy_dir`：`corpus/results/corpus_authoritative_20260320.json:22-23`、`corpus/results/corpus_authoritative_20260320.json:60-61`。

### 2.5 `e2e/`

**明显进步**

- `case_common` 抽取本身是对的，`run.py` 也比上轮集中一些。

**剩余问题**

1. 抽出的 shared helper 仍然在用旧 build 系统。  
   `ensure_daemon_binary()` 的参数还叫 `scanner_binary`，实现还是 `cmake -S daemon -B daemon/build`：`e2e/case_common.py:106-116`。

2. 文档没有跟上今天的重构。  
   `e2e/README.md` 仍要求 `make scanner`、仍写 `scanner/build/bpf-jit-scanner`：`e2e/README.md:17-27`；`scx` case 说明也还写 auto-build scanner：`e2e/README.md:55-58`。

3. case 代码命名层还在旧世界。  
   `scx` / `tetragon` 仍导入 `runner.libs.recompile`：`e2e/cases/scx/case.py:30-42`、`e2e/cases/tetragon/case.py:33-52`。  
   这不一定功能错误，但 migration 没收口。

### 2.6 `module/`

本轮 source review 没再发现上一轮那种会挡投稿的 correctness blocker。

- common header / barrier / endian / extract / rotate 这些关键点现在都对：`module/include/kinsn_common.h:94-99`、`module/include/kinsn_common.h:148-153`、`module/x86/bpf_barrier.c:20-67`、`module/arm64/bpf_barrier.c:35-87`。
- 结论：`module/` 现在是“可以继续做评测”的状态，不再是 P0 blocker。

### 2.7 `tests/`

**明显进步**

- fuzz + adversarial negative tests 是实打实补强：计划文档已记录 `tests/negative/` 新增，`vm-negative-test` 接入：`docs/kernel-jit-optimization-plan.md:686-687`。

**剩余问题**


2. Spectre integration test 仍验证旧 placeholder 语义。  
   `tests/unittest/rejit_spectre.c:7-10`、`tests/unittest/rejit_spectre.c:152-176`。

3. 没有看到 dedicated `serve` / `watch` 测试。  
   搜索命中只有实现定义：`daemon/src/server.rs:29-205`。这块现在正好又是新引入的协议/常驻逻辑。

### 2.8 `Makefile`

**明显进步**

- x86 主线现在清楚很多：release daemon 路径统一到了 `daemon/target/release`：`Makefile:63`；`daemon` / `vm-micro` / `vm-corpus` / `vm-e2e` 这条链也基本连起来了：`Makefile:142-143`、`Makefile:207-235`。

**剩余问题**

1. “全自动 pipeline” 主要成立于 x86 主线，不成立于 ARM64/AWS 支线。  
   `Makefile` 里 ARM64 cross daemon 仍是 `daemon/build/...real`：`Makefile:41`；对应 AWS 脚本同样仍在打包 `daemon/build`：`runner/scripts/aws_arm64.sh:34-35`、`runner/scripts/aws_arm64.sh:583-595`。

2. ARM64/AWS smoke bundle 还依赖已经删掉的 policy 文件。  
   `runner/scripts/aws_arm64.sh:572`、`runner/scripts/aws_arm64.sh:576`。这两条路径在当前树里都不存在。

## 3. 死代码与兼容残留

当前 `allow(dead_code)` 已从上轮 `51` 处降到 `45` 处，但“还有不少”这个结论没有变。

- `daemon/src/kfunc_discovery.rs`: 19 处，核心是整套 BTF kind 常量保留和 `open_btf_path()` fallback：`daemon/src/kfunc_discovery.rs:35-71`、`daemon/src/kfunc_discovery.rs:236-249`
- `daemon/src/pass.rs`: 13 处，集中在未来设计提前占位的数据结构：`daemon/src/pass.rs:23`、`daemon/src/pass.rs:63-64`、`daemon/src/pass.rs:80`、`daemon/src/pass.rs:93`、`daemon/src/pass.rs:169`、`daemon/src/pass.rs:253`、`daemon/src/pass.rs:265-287`、`daemon/src/pass.rs:325`、`daemon/src/pass.rs:450`、`daemon/src/pass.rs:555-562`、`daemon/src/pass.rs:690`

## 4. 距离论文还差什么

如果按当前代码和计划文档状态，我认为离论文还差四件事：

1. **要么收缩主张，要么补齐证据。**  
   计划文档同时声称 micro 正收益和 corpus 净回归：`docs/kernel-jit-optimization-plan.md:175`、`docs/kernel-jit-optimization-plan.md:184-185`。如果不解决 corpus，论文主叙事不能继续写成“通用 runtime-guided optimization framework”。

2. **如果保留 PGO/branch specialization 叙事，必须给出真实 branch-level 数据源。**  
   现在只有 hot-program ranking，不是 hot-branch decision：`docs/kernel-jit-optimization-plan.md:699` 对当前代码实现是过度概括；真实实现见 `daemon/src/profiler.rs:158-177`、`daemon/src/passes/branch_flip.rs:119-132`。

3. **要把 daemon-socket 结果做成结构化、可复现的 artifact。**  
   当前接口边界把 daemon 内部 pipeline / rollback / verifier 信息压扁成了 `bool`，这一点今天的临时设计文档自己也承认了：`docs/tmp/20260322/observability_design_20260322.md:90-108`、`docs/tmp/20260322/observability_design_20260322.md:734-739`。

4. **要么证明 `watch/serve` 是 production-ready，要么缩回 `apply-all`。**  
   计划文档仍把 `watch` 写成 production 目标：`docs/kernel-jit-optimization-plan.md:165`；但当前 `watch` 仍是“一次见过就永久跳过”的缓存语义：`daemon/src/server.rs:143-177`。

## 5. `corpus applied=2`：最可能的根因与修复方向

### 5.1 最可能的根因

我认为这是一个“三层叠加”的问题，不是单一 pass bug：

1. **选择层退化**：删掉 policy 后，`corpus` 现在对所有 target 都走 opaque daemon-auto，而不是显式 family selection。  
   代码：`corpus/modes.py:360-379`、`corpus/modes.py:545-570`。  
   对比基线：旧 authoritative 结果还是按 `policy-file` + `requested_families` 驱动的：`corpus/results/corpus_authoritative_20260320.json:796-815`。

2. **观测层退化**：daemon optimize 结果在 socket 边界只剩 `applied: bool`。  
   代码：`daemon/src/server.rs:103-112`、`runner/src/kernel_runner.cpp:664-748`。  
   结果：当大量程序变成 `applied=false` 时，当前 JSON 说不清是 no-op、rollback-all、verifier reject、subprog skip，还是 protocol failure。

3. **结果 schema 半迁移**：`corpus` 现在同时看 `rejit` 和 `recompile`。  
   代码：`corpus/modes.py:620-623`、`corpus/modes.py:879-885`、`runner/src/common.cpp:421-428`、`runner/libs/results.py:233-249`。  
   结果：即使 apply 成功，family-level attribution / failure summary 也已经不可靠。

### 5.2 修复方向

我建议按这个顺序修：

1. **先修 protocol，不先修 pass。**  
   `optimize` 响应至少返回：`result_kind`（applied / no-op / verifier-reject / rollback-applied / skipped-unsupported）、`requested_passes`、`applied_passes`、`applied_sites`、`rollback_history`、`verifier_error`、`eligible_families`。

2. **统一 schema，只保留 `rejit`。**  
   `corpus/modes.py`、`runner/libs/results.py`、`runner/libs/corpus.py` 全部切到一套 versioned `rejit` schema，删掉默认 `recompile` fallback。

3. **恢复 corpus-side selection layer。**  
   即使不回到旧 YAML policy，也至少要有一个显式的 family allowlist / denylist / PGO chooser；不能让 authoritative batch 完全依赖 opaque daemon-auto。

4. **把 applied=false 变成可调试 artifact。**  
   每个 target 落一份 optimize record JSON；否则下一次再出现 `applied=2`，仍然只能靠猜。

## 6. 最终判断

Round-2 之后，项目状态可以概括为：

- **核心 daemon / module 机制已经明显比上轮扎实。**
- **最大的系统性风险已经从“代码没写完”变成“接口/结果层失真”。**
- **真正需要优先处理的不是再加 pass，而是把 `corpus` 的 daemon-auto + daemon-socket + result schema 这条线做成可解释、可审计、可复现。**

如果明天继续推进，我的优先级建议是：

1. 修 `corpus` socket protocol + schema unified `rejit`
3. 修 `e2e/case_common.py` / `e2e/README.md` / ARM64-AWS stale paths
4. 然后再决定是继续强化 PGO 叙事，还是收缩论文主张
