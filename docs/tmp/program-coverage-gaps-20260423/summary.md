# Program Coverage Gaps Investigation (2026-04-23)

范围：只读代码 + 已落盘 artifact / result JSON；未跑 VM/AWS / make / 新 benchmark。

## 1. 层级总览

1. `Load`：没发现当前 runner-side load whitelist。Tracee runner 直接强制 `--events "*"`（`runner/libs/app_runners/tracee.py:438-442`），`tracee.bpf.o` 有 156 个 TEXT program section；Tetragon runner 总是加载整个 policy dir（25 kprobes + 13 tracepoints，`runner/libs/app_runners/tetragon.py:175,200-203` + `e2e/cases/tetragon/policies/*`）；SCX `scx_rusty_main.bpf.o` 有 13 个 struct_ops section；Katran 固定加载 `xdp_root + balancer + healthchecker` 三个 object；BCC 10 tools / bpftrace 6 scripts 都走全量 suite。剩余异常主要体现在 Tracee/Tetragon 的 corpus vs E2E 计数仍明显不齐。
2. `Discovery`：没发现 parser/type allowlist，也不是 PID-scoped；`bpftool prog show` 是全局 diff by prog_id（`runner/libs/agent.py:64-79`，`runner/libs/app_runners/process_support.py:31-43`）。唯一确认的问题是 exact-set 2s stabilization 过严，会把整个 loader discovery 判失败。
3. `Request`：没发现 discovery set 到 daemon request 的二次 name/size/type 过滤。`prog_id` 集直接进入 scan/apply（`runner/libs/case_common.py:406-439`，`corpus/driver.py:1265-1318`）。唯一的 per-prog 差异是 benchmark policy 对 `struct_ops` 禁掉 `map_inline,dce`（`corpus/config/benchmark_config.yaml:30-36`），不是 program drop。
4. `Attempt`：没发现 daemon 在“requested passes”之前按 prog size / prog type 做全局 hard skip；pass 级别的 type checks 都是显式 `PassResult::unchanged/skipped`。唯一残留风险是 `orig_insns.is_empty()` 会直接 short-circuit（`daemon/src/commands.rs:533-547`），但当前 app artifacts 里没抓到实例。
5. `Apply`：没发现 apply-result 汇总里 silent drop program。group merge 缺 per-program record 会补失败记录或直接 raise（`runner/libs/case_common.py:283-315`），corpus `_build_program_measurements()` 也会在缺 record 时报错（`corpus/driver.py:611-615`）。不过程序级 `rolled_back` / `skipped` 没有单独守恒桶。
6. `Measurement alignment`：SCX 明确做 live-id remap（`e2e/cases/scx/case.py:238-321`，`corpus/driver.py:1020-1083`）；其他路径默认按原始 `prog_id` 对齐，但这和架构文档“same struct bpf_prog image swap”一致（`docs/kernel-jit-optimization-plan.md:284-289,458-459`）。因此目前没抓到非-SCX 的已证实 misalignment bug。
7. `Per-case threshold / gate`：`expected_programs|min_programs|max_programs` 这类 count hard-gate 在源码里已经找不到；剩下的是 activity gate，而不是 count gate。Tracee/Tetragon 都会在 preflight 0 runtime-activity 时整 case fail（`e2e/cases/tracee/case.py:1343-1355`，`e2e/cases/tetragon/case.py:617-627`）。
8. `Corpus vs E2E`：这里仍有真实抽象差异。corpus 把 `prog_ids` 冻结在 startup snapshot，然后在更晚的共享 scan/apply 阶段复用；E2E 是 per-app 立即进入 baseline→scan/apply（`corpus/driver.py:1172-1179,1265-1318` vs `runner/libs/case_common.py:370-444`）。最新落盘 artifact 仍显示 `tracee corpus 37 / e2e 158`、`tetragon corpus 35 / e2e 260`。
9. `抽象分层`：没发现 `AppRunner -> Session -> case -> driver` 里有按 name 去重、list->set->dict-by-name 之类的隐式 drop。除 SCX 为了活跃 id 迁移显式按 name remap 外，其余路径都按 `prog_id` 传递。
10. `Silent skip`：没发现新的源码级 `except: pass` / `except Exception: continue` program-drop。Wave 3 修过的 Tracee event-file silent skip 现在会计数 parse error 并 fail loud（`runner/libs/app_runners/tracee.py:81-89,131-205`）。

## 2. 详细发现

### High: corpus 把 startup `prog_ids` 快照拖到更晚的共享 scan/apply 阶段复用

位置：`corpus/driver.py:1172-1179`, `corpus/driver.py:1265-1318`

现象：corpus 在 `runner.start()` 之后立即把 `started_prog_ids` 固化进 `state.prog_ids`，然后继续把其他 app 全部启动、做 baseline，直到最后才对所有 active session 的 startup snapshot 做一次共享 `scan_programs()` / `apply_rejit()`。中间没有任何 per-session live refresh。只要 loader 在 baseline 到 apply 之间自刷新 / reload / 替换 prog_id，corpus 就会继续针对旧 id 集工作。

影响：这是当前代码里最像“Tracee/Tetragon 还在悄悄漏 program”的残留抽象。按最新落盘 artifact，`tracee/default` 仍有 `corpus 37 / e2e 158` 的差距，`tetragon/default` 仍有 `corpus 35 / e2e 260` 的差距；即使把跨 revision 噪声算进去，量级也足以是“几十到上百 program”的问题。

验证方法：

```bash
python - <<'PY'
import json
c=json.load(open('corpus/results/x86_kvm_corpus_20260423_124338_026179/result.json'))
counts={r['app']: len(r.get('programs') or []) for r in c['results']}
t=json.load(open('e2e/results/tracee_20260423_204635_440107/result.json'))
g=json.load(open('e2e/results/tetragon_20260423_193339_605299/result.json'))
print('tracee corpus/e2e', counts['tracee/default'], len(t['preflight']['program_activity']['programs']['programs']))
print('tetragon corpus/e2e', counts['tetragon/default'], len(g['tetragon_programs']))
PY
```

修复方向：不要复用 startup snapshot 到共享 apply 阶段；改成在 corpus 真正 `scan/apply/post-measure` 之前按 session refresh live `prog_ids`，或把 corpus 生命周期改成和 E2E 一样的 per-app 近距离 apply。

### Medium-High: corpus 和 E2E 的 post-ReJIT measurement gate 语义不一致

位置：`corpus/driver.py:549-558`, `corpus/driver.py:1325-1334`, `runner/libs/case_common.py:53-84`, `runner/libs/case_common.py:440-444`

现象：corpus 只要“没有任何 program 最终 `changed=true`”就直接跳过 post-ReJIT measurement；E2E 只要“有任一 program `changed=true` 或 `summary.total_sites_applied>0`”就会继续跑 post phase。也就是说，`all_sites_rolled_back` / `applied_but_identical` 这类“确实进入过 pass、但最终没变”的 loader，在 E2E 仍可测 post phase，在 corpus 会变成 baseline-only。

影响：这会把“已经尝试过 REJIT 的 loader”在 corpus 里压成“没有 paired measurement”。上界是整 loader 的全部 discovered programs；具体数量取决于当前 workload 落入 `all_sites_rolled_back` / `applied_but_identical` 的频率。

验证方法：

```bash
rg -n "_rejit_result_has_any_change|rejit_result_has_any_apply|run_post_rejit" \
  corpus/driver.py runner/libs/case_common.py
```

修复方向：统一 corpus 和 E2E 的 post-phase gate；至少别再让 corpus 比 E2E 更严格，应该按“发生过 attempt / 有过 applied sites”而不是最终 `changed` 决定是否继续测。

### Medium: discovery 的 exact-set 2s stabilization 过严，会把整个 loader loud-fail

位置：`runner/libs/app_runners/process_support.py:15-50`

现象：`wait_until_program_set_stable()` 只有在“当前新 prog_id 集连续 2 秒完全不变”时才返回；任何增减 / reload / id churn 都会重置计时器。loader 已经健康、也已经出现非空 program set，但 discovery 仍可能因 exact-set 不稳定而整体失败。

影响：直接丢整 loader，而不是丢单个 program。当前已落盘的明确实例是 `bpftrace/capable`；如果同样的 churn 出现在 Tracee/Tetragon 这类大 loader，上界就是几十到上百 program 一次性没测到。

验证方法：

```bash
rg -n "did not stabilize before timeout" \
  e2e/results/bpftrace_20260423_110040_383189
```

修复方向：改 discovery 成功条件，不要再要求 exact prog-id set 连续 2 秒完全相同；至少应该允许“health 已达成 + 新 program 不再继续增加”的语义，而不是把所有 id churn 都视为 fatal。

## 3. 最值得先修的 3 条

1. `P0` corpus startup snapshot 复用到更晚的共享 apply 阶段。影响最大，而且正好对应最新 Tracee/Tetragon corpus-vs-E2E 剩余大差值；修复也集中在 `corpus/driver.py` 的 lifecycle 语义，不需要碰 daemon pass。
2. `P1` corpus / E2E post-measure gate 不一致。这个不是“看起来奇怪”，而是明确导致 paired measurement 覆盖面不一致；改动范围小，收益直接。
3. `P2` exact-set stabilization。它是 loud failure，不是 silent undercount，但一旦命中就是整 loader 归零；已经有现成失败 artifact，修复成本也比改 daemon 小。

## 4. “已经解决” 的清单

- `#664` 提到的 Tracee event subset 问题现在不再是现役问题：计划文档记录旧问题在 `#664`（`docs/kernel-jit-optimization-plan.md:1041`），当前工作树里 runner 已固定 `--events "*"`（`runner/libs/app_runners/tracee.py:438-442`），配置文件也不再只列 4 个 event（`e2e/cases/tracee/config.yaml:15-20`）。
- `#664` 提到的 Tetragon corpus adapter 没传 e2e config 也不是现役代码：当前 shared adapter 会显式注入 `setup_result`（`runner/libs/app_runners/__init__.py:51-59`），runner 总是挂 `--bpf-lib` + `--tracing-policy-dir`（`runner/libs/app_runners/tetragon.py:175,200-203`），而且 policy pack 已落成静态目录（`e2e/cases/tetragon/policies/10-kprobes.yaml:6-56`, `20-tracepoints.yaml:6-32`）。
- `#667` / `bpftrace-bcc-threshold-refresh` 提到的 program-count threshold 家族基本已经删干净：本次源码 grep `expected_programs|min_programs|max_programs|program_count` 只剩 `program_counts` bookkeeping，没找到 hard gate；这和计划文档里 `#667` 的删除项一致（`docs/kernel-jit-optimization-plan.md:1044`）。
- `#668` 的 Katran 扩覆盖已经进当前树：runner 现在明确加载 `xdp_root`、`balancer`、`healthchecker` 三个 object（`runner/libs/app_runners/katran.py:484-518`, `820-870`），对应 `#668` 里“Katran healthcheck + xdp_root 接线”。
- `#668` 的 BCC / bpftrace suite 侧 filter-delete 也已经在当前树：BCC case 直接跑 `tools = list(suite.tools)`（`e2e/cases/bcc/case.py:448-450`），bpftrace case 直接返回全量 `SCRIPTS`（`e2e/cases/bpftrace/case.py:90-95`），不再有本地子集白名单。
- 旧的 discovery parser/type allowlist 和 agent attach-close FD 路径已经不在当前热路径：`bpftool_prog_show_records()` 只返回原始 JSON records（`runner/libs/agent.py:64-79`），共享 discovery 只做 global diff by id（`runner/libs/app_runners/process_support.py:31-43`）。
- Wave 3 / Round 6 修过的 Tracee event-file silent skip 没有回归：现在 parse error 会累计计数样本（`runner/libs/app_runners/tracee.py:81-89`），partial line / rotate / truncate 也都显式处理（`runner/libs/app_runners/tracee.py:131-205`），`verify_phase_measurement()` 会把 parse error 和 lost events 直接升级为 failure（`e2e/cases/tracee/case.py:460-475`）。

## 5. 未验证但可能重要的假设

- `daemon/src/commands.rs:533-547`：任何 `BPF_PROG_GET_ORIGINAL` 拿不到 `orig_insns` 的 program，都在 pass scheduling 之前直接返回 `applied=false/changed=false/passes=[]`。代码路径明确存在，但当前 app artifacts 里没抓到命中样本；如果某类 prog type 命中，这会绕开 Round 7 taxonomy。
- `runner/libs/case_common.py:370-404` vs `e2e/cases/scx/case.py:559-599`：除 SCX 外，E2E generic lifecycle 也不 refresh live `prog_ids`。我没有现成 artifact 证明 Tracee/Tetragon/BCC/bpftrace/Katran 会在 baseline→apply 之间换 id，但代码层面只有 SCX 显式处理了这个问题。
- `corpus/driver.py:1038-1052`, `e2e/cases/tetragon/case.py:317-341`, `e2e/cases/tracee/case.py:945-956`：非-SCX measurement 对齐依赖 `prog_id` 稳定，没有 SCX 风格的 name-based remap。按照架构文档这本来应该成立；如果某个 loader 在 measurement 期间自刷新 program，当前代码不会自动补齐。
- Tracee / Tetragon 最新落盘 `corpus vs e2e` 计数差值很大，但这两组 artifact 不一定来自完全相同的工作树。当前代码里旧 filters 已基本删掉；在没有一轮 fresh corpus rerun 的前提下，我不能把全部残差都归因到上面的 startup-snapshot 问题。
