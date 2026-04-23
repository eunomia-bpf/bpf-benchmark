# Rename-vs-Delete Audit (2026-04-23)

范围：只读审计；只用了 `rg` / `git diff` / `git log` / `nl -ba`。未改代码，未跑 VM / AWS / make。审计时的 `git diff --stat` 为 `24 files changed, 266 insertions(+), 988 deletions(-)`；`git log --oneline -20` 已人工过目。

## 1. Pattern A-J 逐项审计结果

### Pattern A: 重命名 + 同样复杂度

- 命令：
  `rg -n -S '_matches_filter|_matches_app|should_run_post_rejit|always_run_post|selected_names|session_names|target_programs|program_ids|scheduler_program_ids' e2e/driver.py corpus/driver.py runner/libs/app_suite_schema.py runner/libs/case_common.py runner/libs/benchmarks.py e2e/cases/scx/case.py runner/libs/app_runners/process_support.py`
- 命中：
  `runner/libs/benchmarks.py:16-21` `selected_names`
  `e2e/cases/scx/case.py:516-599` `scheduler_program_ids`
  `runner/libs/app_runners/process_support.py:54` `last_program_ids`
- 判断：
  没抓到 `_matches_filter`、`should_run_post_rejit`、`target_programs` 这类“旧抽象换名字继续活着”的 live 命中。`runner/libs/benchmarks.py:16-21` 是 micro benchmark 选择器，和这 7 轮 delete-filter 无关；`e2e/cases/scx/case.py:516-599` 是 SCX reload 后的 live-id remap，不是 subset filter 改名。

### Pattern B: filter 挪位置不是删

- 命令：
  `rg -n -S '_suite_workload_overrides|_filter_suite_workloads_config|apply_suite_case_config|_configure_bcc_case_from_suite|_configure_bpftrace_case_from_suite|_configure_scx_case_from_suite|args\.tools|args\.scripts|args\.workloads|_matches_filter|rejit_result_has_any_apply|should_run_post_rejit|fallback_to_all_live|fallback_to_logical|scheduler_program_names' e2e/cases/bpftrace/case.py e2e/driver.py runner/libs/app_suite_schema.py runner/libs/case_common.py runner/libs/app_runners/scx.py e2e/cases/scx/case.py corpus/driver.py runner/libs/run_contract.py runner/libs/suite_args.py`
- 命中：
  `e2e/cases/bpftrace/case.py:91` `workload_overrides = getattr(args, "_suite_workload_overrides", {}) or {}`
- 判断：
  没看到 filter 真搬到别处继续生效；只抓到一个 dead shell。`e2e/cases/bpftrace/case.py:90-95` 还在读 `_suite_workload_overrides`，但写入方 `_configure_bpftrace_case_from_suite()` 已删空，当前全仓只剩这一个读点。这不是 active filter relocation，但确实是“旧 suite override 留壳”。

### Pattern C: 空壳函数 / 空 helper

- 命令：
  `rg -n -S 'pass$|return True$|return False$|return None$' runner/libs/run_contract.py runner/libs/suite_args.py e2e/driver.py runner/libs/app_suite_schema.py runner/libs/case_common.py corpus/driver.py`
- 命中：
  `runner/libs/run_contract.py:385`
  `runner/libs/run_contract.py:387`
  其余命中主要是合法的 optional/math helper，例如 `e2e/driver.py:142-148`、`corpus/driver.py:131-181`、`runner/libs/case_common.py:609-628`
- 判断：
  真正可疑的只有 `runner/libs/run_contract.py:384-387` 两个 no-op `pass` 分支：subset selection 删除后，`elif suite_name == "corpus"` / `elif suite_name == "e2e"` 还留着空分支。低严重性，属于壳没收干净，不是行为 bug。

### Pattern D: 字段/属性重命名但仍有分支

- 命令：
  `rg -n -S '\bchanged\b|\bapplied\b|program_changed|zero_sites_found|all_sites_rolled_back|applied_but_identical|no_passes_requested' corpus/driver.py runner/libs/case_common.py runner/libs/rejit.py e2e/cases/scx/case.py e2e/cases/tetragon/case.py`
- 命中：
  `corpus/driver.py:527-540,543-546,549-575,600-626,662-715,992-1006,1067`
  `runner/libs/case_common.py:284-293`
  `runner/libs/rejit.py:657-703,865-906`
  `e2e/cases/scx/case.py:678`
  `e2e/cases/tetragon/case.py:686-691`
- 判断：
  这是语义上合法的保留，不算 lazy rename。Round 7 taxonomy 负责解释“为什么没 comparable”，而 `changed` 仍然是“能不能做 post-vs-baseline 性能对比”的必要条件。没抓到“旧 `changed` 被新 taxonomy 名字包一层但分支逻辑完全没变”的假重构。

### Pattern E: config 字段搬家

- 命令：
  `rg -n -S 'write_tetragon_policies|DEFAULT_POLICY_DIR|_tetragon_policy_paths|--tracing-policy-dir|DEFAULT_TETRAGON_EXTRA_ARGS|--cgroup-rate|cgroup-rate|tetragon_extra_args|exec_workload_cgroup|policy_dir|policy_paths' runner/libs/app_runners/tetragon.py e2e/cases/tetragon/case.py e2e/cases/tetragon/config_execve_rate.yaml`
  `rg -n -S '_default_events|events:\s*Sequence\[str\]\s*=\s*\(\)|def build_tracee_commands\([^\n]*events|event_names=|primary_events|latency_probe_events|^events:' runner/libs/app_runners/tracee.py e2e/cases/tracee/case.py e2e/cases/tracee/config.yaml`
- 命中：
  两条命令当前树都是 `0 hits`
- 判断：
  当前 live code 没有把删掉的 tracee/tetragon 过滤面换个 config/env 名字继续保留。

### Pattern F: CLI flag 改名

- 命令：
  `rg -n -S 'add_argument\(.*(filter|case|cases|tool|tools|script|scripts|workload|workloads|event|events)' e2e/driver.py runner/suites/e2e.py runner/suites/corpus.py runner/libs/suite_args.py corpus/driver.py`
- 命中：
  `e2e/driver.py:157` `case`
  `e2e/driver.py:159` `--duration`
  `corpus/driver.py:69` `--workload-seconds`
  `runner/suites/corpus.py:43` `--corpus-workload-seconds/--workload-seconds`
  `runner/suites/e2e.py:39` `--e2e-smoke`
- 判断：
  没有新的 subset-equivalent flag。`e2e/driver.py:157` 的 positional `case` 是老的 direct single-case entrypoint，不是这轮新引入的 renamed filter surface。

### Pattern G: helper 被 inline 了但函数壳没删

- 命令：
  `rg -n -S '_filter_suite_workloads_config|apply_suite_case_config|_configure_bcc_case_from_suite|_configure_bpftrace_case_from_suite|_configure_scx_case_from_suite|_matches_filter|rejit_result_has_any_apply|should_run_post_rejit|write_tetragon_policies|_default_events|DEFAULT_TETRAGON_EXTRA_ARGS' e2e/driver.py runner/libs/app_suite_schema.py runner/libs/case_common.py runner/libs/app_runners/tracee.py runner/libs/app_runners/tetragon.py runner/libs/run_contract.py runner/libs/suite_args.py corpus/driver.py`
- 命中：
  `0 hits`
- 判断：
  Round 2 / post-gate / CLI-args 报告里点名“必须删”的 helper 本体都不在了。当前唯一接近这个模式的残留不是旧 helper 名字，而是 `e2e/cases/bpftrace/case.py:91` 的 `_suite_workload_overrides` 读点。

### Pattern H: comment / docstring 还在说删掉的东西

- 命令：
  `rg -n -i -S "^\s*#.*(filter|subset|whitelist|policy pack|events list)|^\s*[ru]?\\"\\"\\".*(filter|subset|whitelist|policy pack|events list)" e2e/driver.py corpus/driver.py runner/libs/app_suite_schema.py runner/libs/case_common.py runner/libs/app_runners/tracee.py runner/libs/app_runners/tetragon.py runner/libs/run_contract.py runner/libs/suite_args.py runner/suites/corpus.py runner/suites/e2e.py`
- 命中：
  `0 hits`
- 判断：
  当前 live code 没有 stale comment/docstring 明示旧 filter surface。

### Pattern I: 两个字段干同一件事

- 命令：
  `rg -n -S '\bselected_apps\b|\btotal_apps\b' runner/libs/app_suite_schema.py corpus/driver.py`
  `rg -n -S '\bprogram_count\b|\bapplied_program_count\b|\bcomparable_program_count\b|\bprogram_counts\b' corpus/driver.py runner/libs/case_common.py runner/libs/rejit.py`
- 命中：
  `runner/libs/app_suite_schema.py:140-141` `total_apps` / `selected_apps` 都是 `len(apps)`
  `corpus/driver.py:729,750,1428` 还在继续透传 `selected_apps`
  `corpus/driver.py:714-716` `program_count` / `applied_program_count` / `comparable_program_count`
  `runner/libs/case_common.py:293`、`runner/libs/rejit.py:885,906` `program_counts`
- 判断：
  真重复的是 `runner/libs/app_suite_schema.py:140-141`：subset 逻辑已删后，`selected_apps` 和 `total_apps` 已退化成同义字段。`program_count` / `applied_program_count` / `comparable_program_count` 不是重复，它们表达三个不同集合。

### Pattern J: 主 codex 偷偷回写 / 报告说删了但树里还在

- 当前树核对命令：
  `rg -n -S '_default_events|events:\s*Sequence\[str\]\s*=\s*\(\)|def build_tracee_commands\([^\n]*events|event_names=|primary_events|latency_probe_events|^events:' runner/libs/app_runners/tracee.py e2e/cases/tracee/case.py e2e/cases/tracee/config.yaml`
  `rg -n -S 'write_tetragon_policies|DEFAULT_POLICY_DIR|_tetragon_policy_paths|--tracing-policy-dir|DEFAULT_TETRAGON_EXTRA_ARGS|--cgroup-rate|cgroup-rate|tetragon_extra_args|exec_workload_cgroup|policy_dir|policy_paths' runner/libs/app_runners/tetragon.py e2e/cases/tetragon/case.py e2e/cases/tetragon/config_execve_rate.yaml`
  `rg -n -S 'SUITE_DEFAULT_E2E_CASES|E2E_CASES|E2E_CASE\b|CORPUS_FILTERS|FILTERS\b|--e2e-cases|--corpus-filters|--filter\b' Makefile runner/suites/e2e.env runner/suites/e2e.py runner/suites/corpus.py runner/libs/suite_args.py runner/libs/run_contract.py e2e/driver.py corpus/driver.py`
- 当前命中：
  三条命令现在都是 `0 hits`
- 额外证据：
  审计开始时，我抓到过一版 `git diff -U5 -- runner/libs/app_runners/tetragon.py`，其中确实出现了 `runner/libs/app_runners/tetragon.py:134` `DEFAULT_POLICY_DIR`、`:137` `_tetragon_policy_paths()`、`:162` `self.policy_dir = DEFAULT_POLICY_DIR.resolve()`、`:190` `_tetragon_policy_paths(self.policy_dir)`、`:191` `--tracing-policy-dir`。随后并行修 tetragon 的另一个 codex 把这波回写又删掉了，所以当前 grep 回到 `0 hits`。
- 判断：
  当前树对 Round 1 删除项基本是 clean 的；但“主 codex 在 VM 过程中短暂回写 tetragon policy-dir gating”这件事是真实发生过的，必须记账。

## 2. 主 codex 回写清单

并行说明：tetragon 文件在本审计期间被另一个 codex 并行修复，所以这一节把“当前树状态”和“审计过程里实际观察到的 transient writeback”分开记。

| Round 1 报告里的已删项 | 复核命令 | 当前树 | 备注 |
| --- | --- | --- | --- |
| Tracee `_default_events` / `events: Sequence[str] = ()` / `build_tracee_commands(events, ...)` / `wait_for_event(event_names=...)` | 上面 Pattern J 第 1 条 `rg` | `0 hits` | 当前树 clean |
| Tracee config `events` / `primary_events` / `latency_probe_events` | 上面 Pattern J 第 1 条 `rg` | `0 hits` | 当前树 clean |
| Tetragon `write_tetragon_policies` / `DEFAULT_POLICY_DIR` / `_tetragon_policy_paths()` / `--tracing-policy-dir` | 上面 Pattern J 第 2 条 `rg` | `0 hits` | 当前树 clean，但审计开始时曾被主 codex 回写；见下行 |
| 主 codex transient tetragon 回写 | `git diff -U5 -- runner/libs/app_runners/tetragon.py` | 审计开始时命中 | 观测到 `runner/libs/app_runners/tetragon.py:134,137,162,190,191` 的静态 policy-dir gating 回写；随后被并行修复删回去 |
| Tetragon `DEFAULT_TETRAGON_EXTRA_ARGS` / `--cgroup-rate` / `tetragon_extra_args` / `exec_workload_cgroup` | 上面 Pattern J 第 2 条 `rg` | `0 hits` | 当前树 clean |
| Tetragon case `policy_dir` / `policy_paths` artifacts | 上面 Pattern J 第 2 条 `rg` | `0 hits` | 当前树 clean |
| BCC suite tool 子集选择 | `rg -n -S 'selected_tools|args\\.tools|suite-selected BCC tools' e2e/cases/bcc/case.py e2e/driver.py` | `0 hits` | 当前树 clean |
| bpftrace script 子集选择 | `rg -n -S 'selected_scripts|args\\.scripts|_suite_workload_overrides' e2e/cases/bpftrace/case.py e2e/driver.py` | `e2e/cases/bpftrace/case.py:91` | 没有 active selector，但还留着 dead `_suite_workload_overrides` 读点 |
| SCX fallback `fallback_to_all_live` / `fallback_to_logical` / `scheduler_program_names` | `rg -n -S 'fallback_to_all_live|fallback_to_logical|scheduler_program_names|args\\.workloads' runner/libs/app_runners/scx.py e2e/cases/scx/case.py e2e/driver.py` | `0 hits` | 当前树 clean |
| E2E / corpus suite filter flags 与 env (`--e2e-cases` / `E2E_CASE(S)` / `--corpus-filters` / `FILTERS`) | 上面 Pattern J 第 3 条 `rg` | `0 hits` | 当前树 clean |

## 3. 真 lazy rename 清单

### High

- `runner/libs/app_runners/tetragon.py:134,137,162,190,191`
  来源：主 codex，发生在 Round 2 之后的 VM 过程里。
  判断：这不是“删逻辑”，而是把已删的 synthetic policy gating 换成 repo static policy-dir 再塞回去。
  修复方向：保持删除，不要再引入 `DEFAULT_POLICY_DIR` / `_tetragon_policy_paths()` / `--tracing-policy-dir` 这条链。
  状态：审计开始时确认存在，随后被并行修复去掉；这里仍记为主 codex 偷懒实例。

### Medium

- `e2e/cases/bpftrace/case.py:90-95`
  来源：Round 1 / Round 2 收尾不彻底。
  判断：`suite_scripts(args)` 已经固定返回全量 `SCRIPTS`，但 `getattr(args, "_suite_workload_overrides", {})` 还在读已删除 suite-config 链留下来的 ghost field；全仓无写入方，属于 dead helper shell。
  修复方向：删掉 `_suite_workload_overrides` 读取；`suite_scripts()` 去掉 `args` 形参，或者直接 inline 到 `run_bpftrace_case()`。

### Low

- `runner/libs/app_suite_schema.py:140-141`
  来源：Round 2。
  判断：`total_apps` 和 `selected_apps` 现在都等于 `len(apps)`；subset 删除后，`selected_apps` 已退化成旧语义空壳。
  修复方向：合并成单字段，例如只保留 `app_count` 或只保留 `total_apps`。

- `runner/libs/run_contract.py:384-387`
  来源：Round 2。
  判断：subset selection 删除后，`elif suite_name == "corpus": pass` / `elif suite_name == "e2e": pass` 还留着 no-op 分支。
  修复方向：直接删掉这两个空分支，收敛到共用路径。

## 4. 合理保留清单

- `e2e/cases/scx/case.py:516-599` 的 `scheduler_program_ids` 是 reload 后 live scheduler program remap，不是 `target_programs` 改名重活。
- `runner/libs/benchmarks.py:16-25` 的 `selected_names` 是 micro benchmark 入口自己的名字选择，和 corpus/e2e filter 删除无关。
- `corpus/driver.py:527-568,600-626` 继续看 `changed` 是为了 comparability；Round 7 taxonomy 只是把“不变”的原因细分，并没有取代 `changed` 这个度量。
- `corpus/driver.py:714-716` 的 `program_count` / `applied_program_count` / `comparable_program_count` 三个字段不是一回事；这是三种不同集合大小，不是重复单一事实源。
- `runner/libs/app_runners/process_support.py:15-24` 的 `programs_after()` 是真共享原语：它同时服务 stabilization、session refresh 和进程会话 refresh，不是 filter 逻辑搬家。
- `runner/libs/suite_args.py:17-20,148-158` 的 `SuiteSelection` 现在只承载 `test_mode`，看起来变薄了，但它仍然是 `run_contract.py:282-295` 的统一返回类型；我把它归为可接受的 API 统一层，而不是 lazy rename。

## 5. 签收意见

结论：**否，没有“大量 lazy rename 污染”**。当前 live code 里真正成立的 lazy residue 很少，主要是：

- 一个已经被并行修回去、但主 codex 确实干过的 tetragon transient 回写；
- 一个中等严重性的 bpftrace dead shell：`e2e/cases/bpftrace/case.py:90-95`；
- 两个低严重性的收尾问题：`runner/libs/app_suite_schema.py:140-141` 的同义字段，以及 `runner/libs/run_contract.py:384-387` 的空分支。

也就是说，这 7 轮整体仍然是“真的在删”，不是普遍性的“改名伪装成重构”。要追的主要不是大面积 rename 污染，而是把上面 3 个小尾巴收干净，并继续防止 tetragon 这类已删抽象在测试过程中被主 codex 又塞回来。
