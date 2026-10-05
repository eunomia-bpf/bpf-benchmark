# Tetragon Revert 2026-04-23

## 1. 起点状态

工作开始前执行了 `git diff -- runner/libs/app_runners/tetragon.py e2e/cases/tetragon/`。主 codex 回写的 tetragon 差异是：

- `runner/libs/app_runners/tetragon.py:134-143` 重新加回 `DEFAULT_POLICY_DIR` 和 `_tetragon_policy_paths()`，要求仓库内静态 policy pack 存在。
- `runner/libs/app_runners/tetragon.py:162-191` 重新加回 `self.policy_dir` / `self.policy_paths`，并在启动命令里注入 `--tracing-policy-dir`.
- `e2e/cases/tetragon/case.py:580-585,701-727` 重新把 `policy_dir` / `policy_paths` 写进 lifecycle artifacts 和最终 payload。
- `e2e/cases/tetragon/case.py:759-804` 仍然读取 `require_program_activity`，而 `e2e/cases/tetragon/config_execve_rate.yaml:10` 把它设成了 `true`。
- `e2e/cases/tetragon/policies/10-kprobes.yaml:1` 和 `e2e/cases/tetragon/policies/20-tracepoints.yaml:1` 又回到了仓库里。
- 起点 subset shortstat：`3 files changed, 34 insertions(+), 173 deletions(-)`。

## 2. 删除清单

- `e2e/cases/tetragon/policies/10-kprobes.yaml:1` 删除整份静态 kprobe policy。
- `e2e/cases/tetragon/policies/20-tracepoints.yaml:1` 删除整份静态 tracepoint policy。
- `runner/libs/app_runners/tetragon.py:142-151` 删除 runner 内部的 policy-dir 状态，不再保存 `policy_dir` / `policy_paths`。
- `runner/libs/app_runners/tetragon.py:166-178` 删除 `--tracing-policy-dir` 注入；Tetragon 现在直接走 native default CLI，只保留 `--server-address`、`--health-server-address` 和可选 `--bpf-lib`。
- `e2e/cases/tetragon/case.py:581-588` 删除 `policy_dir` / `policy_paths` artifacts plumbing，只保留 `tetragon_launch_command`、`tetragon_programs` 和 `rejit_policy_context`。
- `e2e/cases/tetragon/case.py:705-719` 删除最终结果 payload 里的 `policy_dir` / `policy_paths` 字段。
- `e2e/cases/tetragon/case.py:726-773` 删除 `require_program_activity` config 读取和向 `daemon_payload()` 的传递。
- `e2e/cases/tetragon/config_execve_rate.yaml:1-9` 删除旧的 `tetragon_extra_args` 和 `require_program_activity` 配置面。

## 3. Activity Gate 改动

- `e2e/cases/tetragon/case.py:591-608` 保留 preflight 采样和 `program_activity` 统计，但删除了“preflight 必须观测到 program run_cnt > 0”这一 loud fail gate。
- 新逻辑：preflight 只记录，不再以最少程序活动量决定 case 成败。
- 保留的硬错误不变：
  - `runner/libs/app_runners/tetragon.py:166-183` Tetragon 启动失败或 attach 0 programs 仍然直接报错。
  - `e2e/cases/tetragon/case.py:622-636` baseline 后 daemon/process crash 仍然直接报错。
  - `e2e/cases/tetragon/case.py:689-691` post-ReJIT phase 缺失仍然直接报错。

## 4. LOC 改动

- 起点 subset：`git diff --shortstat -- runner/libs/app_runners/tetragon.py e2e/cases/tetragon/`
  - `3 files changed, 34 insertions(+), 173 deletions(-)`
- 终点 subset：`git diff --shortstat -- runner/libs/app_runners/tetragon.py e2e/cases/tetragon/`
  - `3 files changed, 21 insertions(+), 211 deletions(-)`
- 这次 revert 相对起点继续减少了 `13` 行新增、增加了 `38` 行删除，净变化 `-51 LOC`。
- 写报告前全仓 shortstat：`24 files changed, 266 insertions(+), 988 deletions(-)`。

## 5. 自我 Review

- grep 验证 `DEFAULT_POLICY_DIR|_tetragon_policy_paths|tracing-policy-dir|tetragon_extra_args`
  - 命令：`rg -n -S 'DEFAULT_POLICY_DIR|_tetragon_policy_paths|tracing-policy-dir|tetragon_extra_args' runner/libs/app_runners/tetragon.py e2e/cases/tetragon`
  - 结果：`0 命中`
- grep 验证 `policy_dir|policy_paths`
  - 命令：`rg -n -S 'policy_dir|policy_paths' runner/libs/app_runners/tetragon.py e2e/cases/tetragon`
  - 结果：`0 命中`
- grep 验证 `expected_programs|min_.*programs|activity.*count >=`
  - 命令：`rg -n -S 'expected_programs|min_.*programs|activity.*count >=' runner/libs/app_runners/tetragon.py e2e/cases/tetragon`
  - 结果：`0 命中`

## 6. 验证

- `source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile runner/libs/app_runners/tetragon.py e2e/cases/tetragon/case.py`
  - `exit 0`
- `source /home/yunwei37/workspace/.venv/bin/activate && make check`
  - `exit 0`
- `source /home/yunwei37/workspace/.venv/bin/activate && make -n vm-e2e`
  - 输出：`"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run x86-kvm e2e --`
