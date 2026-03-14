# Stage Review Report

Date: 2026-03-12

## Executive Verdict

当前最严重的问题不是“数字不够漂亮”，而是“设计文档里宣称的 v2 steady-state policy system，和现在真正被 micro/corpus/E2E 消费与评估的系统，不是同一个东西”。

- scanner 的 per-site v2 parser/compiler 已经落地，但 authoritative design doc 仍把 v2 主线写成 family-level allowlist artifact。
- consumer 层仍保留了与设计相反的 steady-state 语义：缺 policy 时回退 blind all-apply，而不是 stock。
- E2E 的 live path 甚至没有直接消费原 policy，而是先按 family 顺序重映射 site，再 apply；这意味着同一份 policy 在 micro/corpus 和 E2E 里语义不同。

关于“E2E v2 lookup 为什么 site 坐标漂移，是设计问题还是实现问题”的结论很明确：两者都有。

- 设计问题：steady-state artifact 没有绑定 exact xlated identity，只靠 `(program, insn, family)` 过于脆弱。
- 实现问题：`e2e/common/recompile.py` 没有把 mismatch 当成 stale artifact 硬失败，而是用 family-order remap 去“凑一个能 apply 的 live policy”。

因此，`#120` 和 `#121` 当前更像 pipeline migration / wiring smoke test，不是能直接支撑论文主张的 steady-state evaluation。

## 1. 设计-实现不一致清单

| Severity | Issue | Evidence | Judgment |
| --- | --- | --- | --- |
| critical | **v2 spec 已经分叉，当前仓库没有单一、最新、可执行的 authoritative spec。** | 设计文档把 steady-state 主线写成 family-level allowlist，最小 schema 仍是 `version: 1` + `selection.mode: allowlist`，并明确说 per-site override 不是 v2 主线：`docs/tmp/policy-configuration-design-v2.md:213-230`, `313-356`。实现则强制 `version: 2` + `program` + `default` + `sites[]`：`scanner/src/policy_config.cpp:331-368`。迁移报告也明确说 scanner 已是 v2-only per-site：`docs/tmp/v2-pipeline-migration-report.md:7-24`, `29-40`。 | 这是文档级 critical mismatch。现在 reviewer 如果按 design-v2 理解系统，会直接理解错。 |
| critical | **steady-state 默认语义被实现反过来了：设计要求“没 policy 就 stock”，实现仍是“没 policy 就 blind all-apply”。** | 设计文档明确写了 “有 tuned policy -> apply；没 tuned policy -> stock；all-apply 只用于 tuning/debug”：`docs/tmp/policy-configuration-design-v2.md:48-56`, `143-150`。但 micro `kernel-recompile` runtime 在没有 `policy/policy_file` 时直接加 `--recompile-v5 --recompile-all`：`micro/orchestrator/commands.py:158-173`。共享 corpus helper 也是 `recompile_all = recompile_v5 and policy_file is None`：`corpus/common.py:199-232`。corpus framework/vm drivers miss policy 时都走 auto-scan-v5：`corpus/_driver_impl_run_corpus_v5_framework.py:328-332`, `350-363`, `387-400`; `corpus/_driver_impl_run_corpus_v5_vm_batch.py:503-507`, `553-567`, `591-604`。E2E 没 policy 时直接 `--all`：`e2e/common/recompile.py:397-410`。 | 这是实现级 critical mismatch，也是 `#120/#121` 结果被污染的根因之一。 |
| critical | **E2E live path 改写了 policy 语义：micro/corpus 是 exact `(insn,family)`，E2E 是 family-order remap。** | scanner 和 micro_exec 都按 exact `(insn,family)` 过滤 site：`scanner/src/policy_config.cpp:413-466`, `micro/runner/src/kernel_runner.cpp:1028-1085`。E2E 却先 live-scan，再把 stored policy 按“每个 family 的第 N 个 live site”重映射：`e2e/common/recompile.py:184-239`, `389-396`; `corpus/policy_utils.py:244-340`。注释甚至直接写了 `Remapped onto live scanner sites by family order.`：`corpus/policy_utils.py:308-319`。同时 scanner manifest 明明已经导出了 `site_id`, `pattern_kind`, `site_len`, `canonical_form` 等更强 identity：`scanner/src/policy_config.cpp:511-568`。 | 这不是小修小补。现在同一份 v2 policy 在不同 layer 里不是同一个语言。 |
| critical | **micro manifest 的 inline `policy:` 路径仍在生成旧 v1 JSON；`--policy-file` 可以用，但 `--policy` inline 路径是坏的。** | `config/micro_pure_jit.yaml` 仍有 inline `policy:`：`config/micro_pure_jit.yaml:118-120`, `208-209`。`BenchmarkSpec.inline_policy_text` 仍生成 `{\"version\":1,\"selection\":{\"mode\":\"denylist\",\"families\":[...]}}`：`micro/benchmark_catalog.py:124-139`。scanner 现在只接受 `version: 2`：`scanner/src/policy_config.cpp:338-368`。本地直接验证：manifest inline policy 被 `scanner/build/bpf-jit-scanner compile-policy` 拒绝，错误为 `unsupported policy version 1`。micro_exec 本身的 `--policy/--policy-file` plumbing 是对的：`micro/runner/src/common.cpp:269-277`, `445-459`; `micro/runner/src/kernel_runner.cpp:1028-1085`。 | `#98b` 不能算完整闭环。当前能工作的只有 file-based v2 path。 |
| major | **当前 corpus policy tree 不是 design-v2 里的“auto-tuned steady-state policy”，而是“default generator + object-level CMOV skip heuristic”。** | 设计文档把 auto-tuner 定义为主路径，search unit 是 single program：`docs/tmp/policy-configuration-design-v2.md:83-98`, `117-197`。但当前批量生成 `corpus/policies/` 的是 `generate_default_policies.py`，它对所有 discovered sites 默认写 `apply`，只在 object-level CMOV regressor 上统一 skip：`corpus/generate_default_policies.py:314-348`, `425-484`, `581-605`。迁移报告也确认 `corpus/policies/` 是由这个脚本重生成的：`docs/tmp/v2-pipeline-migration-report.md:44-55`, `65-99`。 | 所以 `#120` 评估的不是 design-v2 主线 auto-tuner，而是“per-site 格式迁移后的默认生成器”。 |
| major | **`auto_tune.py` 输出在语法上能被 scanner 消费，但它只实现了“shipped per-site schema”，没有实现 design-v2 承诺的完整 workflow。** | `auto_tune.py` 确实会基于 allowlist 渲染 scanner 可消费的 per-site v2 YAML：`corpus/auto_tune.py:336-378`, `699-717`, `1049-1067`。但设计文档要求 winner 还要做 final validation rerun：`docs/tmp/policy-configuration-design-v2.md:185-197`。当前 phase 5 只是 `choose_winner()` 后直接落盘，没有 validation candidate rerun：`corpus/auto_tune.py:1021-1069`。同时 `generate_default_policies.py` 有 section-byte fallback scan，而 `auto_tune.py` 的 `scan_program_manifest()` 没有相同 fallback：`corpus/generate_default_policies.py:207-299`, `corpus/auto_tune.py:381-403`。 | 结论不是“auto_tune 输出坏 YAML”，而是“它输出的是 scanner 能吃的 YAML，但还不是 design 文档承诺的完整 steady-state artifact”。 |
| major | **Python 侧和 C++ 侧的 policy parser 不是同一个语言。** | Python parser 要求每个 `sites[*]` 都显式带 `action`，且不拒绝 duplicate：`corpus/policy_utils.py:205-241`。C++ parser 允许缺 `action` 时默认 `apply`，并且会拒绝 duplicate `(insn,family)`：`scanner/src/policy_config.cpp:276-329`。 | 这会导致 Python 预校验、E2E remap 生成和 scanner runtime acceptance 的语义不一致。 |
| minor | **scanner manifest 缺少 exact xlated identity / source provenance，drift 调试成本高。** | design-v2 期望 manifest 至少带 xlated hash / insn count：`docs/tmp/policy-configuration-design-v2.md:385-392`。当前 JSON 只有 `prog_tag` 和 `insn_cnt`，没有 xlated hash，也没有标记这份 manifest 是 live xlated 还是 raw ELF fallback：`scanner/src/policy_config.cpp:532-573`, `scanner/src/cli.cpp:398-438`。 | 这不是当前最致命的问题，但会持续放大 stale artifact 排查成本。 |

## 2. 论文薄弱点排名

### P0 必须修

1. **E2E tuned-v2 evaluation 目前无效。**  
   三个 case 合计 `config-mode v2 policies applied to 0 live programs`。Tracee 没有 post phase；Tetragon 和 bpftrace 的 post-ReJIT 数据来自 blind fallback，而不是 config-mode v2 apply：`docs/tmp/e2e-v2-policy-rerun.md:20-29`, `108-128`。  
   这不是“效果一般”，而是“evaluation object 不存在”。

2. **安全/稳健性 claim 现在站不住。**  
   strict blind authoritative run 仍有 `4` 个 `result-mismatch` 和 `2` 个 `VM crash`：`binary_search`、`switch_dispatch`、`branch_dense`、`bpf_call_chain`、`bounds_ladder`、`mixed_alu_mem`：`docs/tmp/kernel-recompile-micro-strict.md:74-104`。tuned 只是把 invalid 从 `6 -> 2`，并没有证明机制本身 clean：`docs/tmp/kernel-recompile-micro-v2-tuned.md:30-34`, `67-69`。  
   如果论文继续强调 fail-closed substrate，这些不能只靠“policy disable 了”带过。

3. **主 thesis 不能再写成“closing the LLVM-vs-kernel gap”。**  
   strict characterization gap 是 `1.641x`，blind recovery 只有 `1.028x`，overall 只恢复了 `4.3%`，隐含剩余 gap 仍有 `1.598x`：`docs/tmp/characterization-gap-decomposition.md:19-35`, `198-202`。  
   `1.028x blind / 1.040x tuned applied-only` 够支撑“局部 backend lowering + policy sensitivity 真有价值”，不够支撑“大幅收复 backend gap”。

4. **Corpus v2 的负结果是真问题，而且不主要是 site drift。**  
   v2 per-program rerun 只有 `0.848x`，差于 blind `0.868x` 和 v1 tuned `0.898x`；shared 142-program overlap 上仍是 `0.847x`：`docs/tmp/corpus-v2-policy-rerun.md:44-65`。同时 final run 只有 `1` 个 stale-site failure，说明大盘变差不主要是坐标漂移：`docs/tmp/corpus-v2-policy-rerun.md:130-149`。  
   更像是 policy content/coverage/default semantics 本身有问题。

### P1 应该修

1. **E2E drift 不是“刷新一下 policy 文件”就结束。**  
   当前问题是双层的：设计上 artifact 没有 exact xlated identity；实现上又用 family-order remap 掩盖 mismatch。即便这轮手工 refresh Tracee/Tetragon，对下一轮 live build 仍会再漂。

2. **当前 v2 evaluation object 不一致。**  
   micro tuned 是 targeted/manual probe 产物：`docs/tmp/kernel-recompile-micro-v2-tuned.md:96-103`。corpus v2 用的是 default generator。E2E v2 则复用 corpus policy tree。论文如果把三者统称为“the v2 policy system”，会被直接质疑。

3. **XDP forwarding 1.003x 只能算 deployment sanity check。**  
   数据几乎打平，而且 authoritative setup 已从 guest-created `veth` 改成 virtio loop NIC pairs：`docs/tmp/xdp-forwarding-live-vm-report.md:10-17`, `31-38`。这个结果不适合承载强 end-to-end throughput claim。

4. **bpftrace 当前根本没有 v2 artifact。**  
   `corpus/build/bpftrace/` 为空，`corpus/policies/bpftrace/` 不存在，所以 `#121` 的 bpftrace rerun 只是 blind fallback 新测了一遍：`docs/tmp/e2e-v2-policy-rerun.md:83-107`。

### P2 Nice-to-have

1. **硬件泛化仍弱。**  
   plan 里 smaller-core x86 仍缺，arm64 只有有限性能数据：`docs/kernel-jit-optimization-plan.md:261-267`。如果正文不主动收 scope，这会被 reviewer 当成缺口。

2. **部分 gap-source 归因仍偏 inference。**  
   `llvm_pass_likely` / `overhead_likely` bucket 的解释是合理推断，不是 per-benchmark direct proof：`docs/tmp/characterization-gap-decomposition.md:104-135`。

3. **strict micro 的环境元数据不够干净。**  
   `CPU governor: unknown`、`Turbo state: unknown`：`docs/tmp/kernel-recompile-micro-strict.md:5-11`。这不是最主要问题，但属于 measurement-credibility 的小口子。

## 3. TODO 审计结果

### 已标 `✅`，但完成度表述过度乐观的条目

1. **`#98b P2 Micro manifest-driven policy`：只能算半完成。**  
   `--policy-file` path 是通的，但 manifest 里的 inline `policy:` 仍产出 v1 JSON，当前 scanner 会拒绝。这个条目不能被理解成“micro policy path fully working”。

2. **`#121 E2E rerun with tuned v2 policy`：rerun 任务完成，但 evaluation closure 没完成。**  
   当前结果只能证明 wiring 走到了 v2 lookup，不足以证明 live v2 policy actually works。这个条目更准确的定义应是“pipeline validation rerun complete, config-mode evaluation failed”。

3. **`#122 v2 pipeline migration`：format migration 完成，不等于 steady-state system 完成。**  
   scanner/generator 的 v2-only 迁移确实做完了，但 no-policy default 仍不是 stock，micro inline path 仍坏，E2E live path 仍靠 remap hack。它不应被解读成“v2 设计已落地闭环”。

4. **`#98f P4 Auto-tuner`：代码存在，但还没成为 authoritative evaluation 主路径。**  
   它没有 final validation rerun，也没有成为 `#120/#121` 实际使用的 policy source。这个任务更像“prototype landed”，不是“design complete and adopted”。

5. **`#114 Per-site policy v2 格式 + scanner 实现` 的 plan 文案已经自相矛盾。**  
   plan 里 `#114` 仍写“保留 v1 backward compat”：`docs/kernel-jit-optimization-plan.md:437`；但 `#122` 和实际代码都说明 scanner 已是 v2-only：`docs/kernel-jit-optimization-plan.md:445`, `scanner/src/policy_config.cpp:338-368`。这条 `✅` 的描述需要回写修正。

6. **plan 第 2 节的 headline 仍有过时内容。**  
   `docs/kernel-jit-optimization-plan.md:128` 还写着 `BpfReJIT micro improvement (recompile/stock) | 待测`，但 `#118`、`#126` 已经给出 authoritative strict rerun。这个不是实现没做，而是 plan 没维护干净。

### 已标 `✅`，但应理解为“任务完成，结果为负”的条目

1. **`#120 Corpus rerun with v2 per-program policies` 可以继续标 `✅`。**  
   rerun 这件事确实完成了，且结论明确是负向：`0.848x < 0.868x < 0.898x`。问题不在“有没有跑”，而在“不要把它误解为 v2 design validated”。

2. **`#126 Micro v2 tuned policy rerun` 也可以继续标 `✅`。**  
   rerun 本身做完了；问题是它只能支持 mechanism evidence，不能单独托起整篇论文的 performance thesis。

### 仍标 `🔄` 或 `❌`，且论文前必须解决或明确 down-scope 的

1. **Plan Q5: `Operators 能否在类似 production 部署中安全管理 policy？`**  
   当前是 P0。E2E v2 config-mode apply 为 `0`，这个问题不能再保留在“后面看看”的状态。

2. **Plan Q3: `Legality substrate 在真实程序上的 directive 接受率？`**  
   如果安全 substrate 是贡献之一，这个问题必须被收束成一段干净结论，而不是一直挂 `🔄`。

3. **`#53 Overlap/priority 语义`**  
   safety interface 没有明确 overlap arbitration，会被 reviewer 质疑为 contract 不完整。即便来不及做 kernel 仲裁，也至少要在 scanner/compiler 端拒绝 overlap。

4. **`#57 消融补全`**  
   如果正文还要强讲“剩余 gap 到底来自哪里”，这个条目要么做完，要么在 paper 里显式降调为 inference only。

### 当前 plan 漏掉、但提交前必须补上的任务

1. **给 policy artifact 增加 exact identity。**  
   最低要求是 `prog_tag + insn_cnt`；更稳妥的是再加 xlated hash / manifest provenance。

2. **把 no-policy steady-state 统一改成 stock。**  
   blind all-apply 只能留给 tuning/debug，不应再作为 miss policy 的默认路径。

3. **拆开“default-generated policy”和“auto-tuned policy”。**  
   artifact 名称、结果名称、目录都要分开，否则 `v2 policy rerun` 这个名字会持续误导。

4. **给 micro inline `policy:` 路径补 regression test。**  
   当前这个 bug 说明 `#98b` 没有被持续覆盖。

5. **去掉 family-order remap，或者把它降级为 debug-only。**  
   在 authoritative evaluation 路径里，mismatch 应该暴露 stale artifact，而不是改写 policy 语义。

6. **补 Python/C++ parser consistency tests。**  
   现在两边不是同一个语言，后续还会反复出“本地解析过了，runtime 不接受”的问题。

## 4. 推荐的下一步 Action Items

### P0

1. **冻结 spec，然后回写文档。**  
   直接重写 `docs/tmp/policy-configuration-design-v2.md`，或者新增一份 authoritative per-site v2 spec 并把旧文档显式标为 obsolete。现在最忌讳的是继续让 design 和 implementation 同时存在、语义不同。

2. **先修 steady-state 语义，再重跑任何 v2 数据。**  
   把 micro/corpus/E2E 的 no-policy default 全部改成 stock；blind all-apply 改成显式 `--explore`/`--debug` path。否则后续所有 v2 rerun 仍然是混杂态。

3. **取消 E2E family-order remap，改成 exact identity precheck。**  
   artifact 不匹配时，应该明确报 stale policy / cache miss，而不是偷偷改写 policy 再 apply。

4. **修掉或移除 micro inline policy path。**  
   最快的做法是全部换成 file-based v2 policy；如果要保留 inline path，就把 `BenchmarkSpec.inline_policy_text` 升到 current v2 schema 并补测试。

5. **对安全 claim 做硬处理。**  
   `4` 个 `result-mismatch` 和 `2` 个 `VM crash`，要么修掉，要么在论文和代码里把相关 family/path 明确标成 unsupported，从 authoritative safety story 里剔除。

### P1

1. **不要再用 `generate_default_policies.py` 的输出代表“tuned v2 policy”。**  
   用 `corpus/auto_tune.py` 真正产出一批 tuned policies，并且和 default-generated policies 分目录、分结果、分图表。

2. **给 `auto_tune.py` 补 final validation rerun。**  
   没有这一步，winner 只能算候选，不算 steady-state artifact。

3. **刷新 exact E2E artifacts 后重做 `#121`。**  
   Tracee/Tetragon 至少要有 config-mode apply 成功；bpftrace 至少要先补齐 `corpus/build/bpftrace/*.bpf.o` 和 `corpus/policies/bpftrace/...`。

4. **补 parser consistency tests。**  
   Python render/parse、scanner parse/filter、micro_exec consume 至少要用同一组 golden policies 对齐。

5. **重命名现有结果，避免继续误导。**  
   把“default-generated v2 rerun”和“auto-tuned v2 rerun”明确拆开命名。现在 `corpus v2 policy rerun` 太容易被读成“auto-tuned steady-state system rerun”。

### P2

1. **重写论文 framing。**  
   当前更稳的叙事不是“我们显著收复 LLVM-vs-kernel gap”，而是“backend-only headroom 真实存在，但 naïve policy 只能回收一小部分，因此需要一个可控、可 fail-close、可演化的 policy substrate”。

2. **尽快决定 scope，要么补，要么主动收。**  
   smaller-core x86、arm64 完整性能故事、scx live recompile，这些如果来不及做，就在正文里主动 down-scope，不要让 reviewer 替你指出来。

## Bottom Line

最该直说的一句是：`#122` 的“v2 migration”完成了格式迁移，但没有完成 steady-state 语义闭环；`#121` 的“E2E tuned-v2 rerun”完成了 wiring check，但没有得到任何可用的 config-mode live apply；`#120` 的负结果也不是“设计已被证伪”，而是“当前生成器 + fallback semantics + artifact identity 设计一起把结果做坏了”。

如果论文现在就定稿，最容易被 reviewer 打穿的不是单个 benchmark，而是“你们到底在评估哪一个 policy system”这个问题。
