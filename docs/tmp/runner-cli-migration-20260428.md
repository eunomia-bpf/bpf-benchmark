# Benchmark runner 从 daemon socket 迁移到 CLI pipeline 调研

日期: 2026-04-28

## 结论

v3 的方向是可行的: benchmark runner 不需要 daemon 的 watch/event loop，应该把 `runner/libs/rejit.py` 保留为高层 Python API，并把内部实现从 Unix socket JSON 请求替换为 `bpfget | bpfopt | bpfverify | bpfrejit` 的 CLI pipeline。driver 层不应该直接拼 pipeline，否则 corpus/e2e/micro 后续会复制超时、stderr、per-program result schema、profile 和 discover 逻辑。

当前代码与任务背景有两个重要差异:

- runner 通过 daemon socket 发送的命令只有 `optimize`、`profile-start`、`profile-stop`。daemon 还支持 `optimize-all`、`profile-save`、`profile-load`、`status`，但 benchmark runner 当前没有调用这些命令。没有 runner socket 命令叫 `discover-progs` 或单独 `rejit`。
- `micro/driver.py` 当前不走 daemon socket，也不做 live ReJIT。它只运行 C++ `micro_exec` 的 `run-llvmbpf` 和 `test-run` 两种 stock runtime，对 `.bpf.o` 做 paired sample。若以后要加 "kernel baseline -> ReJIT -> post" micro runtime，应作为新增 runtime/driver path 设计，而不是当前 socket 迁移的阻塞项。

另一个实现状态: 现在仓库内 `bpfopt/` workspace 只有 `bpfopt` 和 `kernel-sys` 两个 crate，`bpfopt` CLI 也只有 `list-passes`，`bpfget/bpfverify/bpfprof/bpfrejit` 还没有落地。本文设计假设 v3 的 6 个 CLI 工具完成后再切 runner。

## 代码依据

- v3 总纲: `docs/tmp/bpfopt_design_v3.md` 定义 6 个 Unix 风格 CLI，raw `struct bpf_insn[]` 通过 stdin/stdout 传输，side-input 用文件。
- v3 §4.3: per-pass verify loop 应放在 shell/外部脚本中，最终 `bpfrejit $PROG_ID $CURRENT`。
- v3 §8: benchmark runner 推荐方案 A，直接调 CLI，不经过 daemon socket。
- v3 §9 场景 8: `bpfget --list --json` 枚举程序，然后对每个 prog_id 跑 `bpfget | bpfopt optimize | bpfrejit`。
- 当前 socket wrapper: `runner/libs/rejit.py` 中 `_daemon_request()` 负责 Unix socket JSON line 协议，`_optimize_request()` 构造 `{"cmd":"optimize","prog_id":...}`，`_prepare_branch_flip_profile()` 构造 `profile-start/profile-stop`，`apply_daemon_rejit()` 对 prog_id 列表循环调用 optimize。
- 当前 lifecycle: `runner/libs/case_common.py` 和 `corpus/driver.py` 在 baseline 后通过 `DaemonSession.apply_rejit()` 触发 ReJIT。

## 当前 `runner/libs/rejit.py` 接口

### 被 driver 调用的公开面

当前 driver 直接依赖的符号主要是:

- `DaemonSession.start(...).apply_rejit(prog_ids, enabled_passes=...)`
- `benchmark_rejit_enabled_passes()`
- `benchmark_run_provenance()`
- `compact_rejit_results_for_artifact()`

`case_common.py` 还通过 `PreparedDaemonSession` 包装 `DaemonSession`，所有 e2e case 和 corpus suite 最终都走 `active_daemon_session.apply_rejit(...)`。

`rejit.py` 还暴露/复用了一些结果处理函数，迁移时应保留语义:

- `load_benchmark_config()`
- `benchmark_config_enabled_passes()`
- `benchmark_policy_exclusions()`
- `applied_site_totals_from_rejit_result()`
- `compact_rejit_result_for_artifact()`
- `apply_daemon_rejit()`，迁移后应改名或兼容为 `apply_rejit()`/`apply_cli_rejit()`

### 当前 socket JSON 命令

runner 发送:

| 当前 JSON | 触发条件 | 当前语义 | v3 CLI 替代 |
|---|---|---|---|
| `{"cmd":"optimize","prog_id":N,"enabled_passes":[...]}` | 每个 live prog_id | daemon 内部读取原始字节码、跑 PassManager、per-pass verify、最终 `BPF_PROG_REJIT` | `bpfget N --full --outdir DIR`; `bpfopt optimize --passes ... --target target.json --map-fds DIR/map_fds.json --report DIR/report.json < DIR/prog.bin > DIR/opt.bin`; per-pass 时插入 `bpfverify`; 最终 `bpfrejit N DIR/current.bin` |
| `{"cmd":"profile-start","interval_ms":1000}` | enabled passes 包含 `branch_flip` | daemon 启动 profiler，采集 BPF stats/profile | `bpfprof --all --duration 1s --output profile.json`，或对当前 app 的 prog_id 集合逐个/批量采集 |
| `{"cmd":"profile-stop"}` | profile-start 后 | daemon 冻结 profile snapshot，后续 optimize 使用 | `bpfprof` 命令自然结束并写出 profile 文件；`bpfopt branch-flip/optimize --profile profile.json` 读取 |

daemon 支持但 runner 当前不发送:

| daemon JSON | 当前 runner 使用? | CLI 替代 |
|---|---:|---|
| `optimize-all` | 否 | `bpfget --list --json` + Python loop/小 shell loop |
| `profile-save` / `profile-load` | 否 | 直接读写 `bpfprof` 产出的 profile JSON |
| `status` | 否 | CLI 自检: `bpfopt list-passes`, `bpfget --version`, `bpfrejit --version` 等 |

discover 当前也不通过 daemon socket。app runner 在应用启动前记录 `bpftool prog show` 的 before set，启动真实上游 app 后轮询 `bpftool prog show`，再用差集/稳定窗口发现新程序。

## 当前流程图

### corpus

```text
corpus/driver.py
  parse args, load macro_apps.yaml
  DaemonSession.start(bpfrejit-daemon serve --socket ...)
  enable_bpf_stats()
  for each app:
    get_app_runner(app.runner)
    runner.start()                 # 真实应用启动并加载 BPF
    app runner discovers programs  # 当前 bpftool prog show polling
    save CorpusAppSession

  _run_suite_lifecycle_sessions()
    baseline_refresh:
      _refresh_active_session_programs()  # bpftool/current runner refresh
    baseline:
      run app workload N samples
      sample BPF run_cnt/run_time delta
    rejit_refresh:
      refresh live prog_ids again
    rejit:
      active_daemon_session.apply_rejit(prog_ids)
        optional profile-start/sleep/profile-stop if branch_flip
        for each prog_id: send {"cmd":"optimize", ...}
    post_rejit:
      run workload N samples
      sample BPF run_cnt/run_time delta
    stop all apps

  build per_program ratios from baseline/post_rejit avg_ns_per_run
```

corpus 的三阶段已经是 "baseline -> apply ReJIT -> post_rejit"。CLI 迁移只替换 `apply_rejit()` 内部实现，以及可选把 discover helper 从 `bpftool` 切到 `bpfget --list --json`。

### e2e

```text
e2e/driver.py
  DaemonSession.start(...)
  prepare_daemon_session(...)
  inject args._prepared_daemon_session
  run selected case(s)

case.py
  start real app/tool/script
  discover live programs
  run_case_lifecycle() or run_app_runner_lifecycle()
    baseline workload + BPF stats
    active_daemon_session.apply_rejit(live_rejit_prog_ids)
    post_rejit workload + BPF stats
  write artifact
```

case 差异:

- `bpftrace` 和 `bcc`: 每个 script/tool 跑一次 lifecycle。
- `katran`: 单 runner lifecycle，`xdp_root` 仍是允许的 XDP chain bootstrap 例外。
- `tetragon`: 单 lifecycle，多 workload 记录。
- `tracee`: 多 cycle，每个 cycle 启动 Tracee、baseline、ReJIT、post，再聚合记录。

### micro

```text
micro/driver.py
  load micro/config/micro_pure_jit.yaml
  select stock runtimes only
  for each .bpf.o benchmark:
    warmups:
      micro_exec run-llvmbpf or micro_exec test-run
    measured samples:
      alternate runtime order
      collect compile_ns, exec_ns, perf counters
```

当前 micro 明确拒绝 `policy_mode != "stock"` 的 runtime，因此不存在 "daemon socket -> CLI" 的迁移点。若要做 live ReJIT micro，应新增 runtime，例如 `kernel_rejit_cli`，由 C++ helper 或 Python wrapper 加载一次程序、测 baseline、调用 `apply_rejit([prog_id])`、测 post。这个新增 path 要单独设计，因为 current `test-run` 每个 sample 都独立加载/运行程序，prog_id 生命周期很短。

## 目标 CLI pipeline 流程

### 单程序简单 pipeline

```python
def optimize_program_simple(prog_id: int, passes: list[str]) -> CompletedProcess:
    with tempfile.TemporaryDirectory(prefix=f"bpfrejit-{prog_id}-") as td:
        outdir = Path(td)
        run(["bpfget", str(prog_id), "--full", "--outdir", str(outdir)])
        run_pipeline([
            ["bpfopt", "optimize",
             "--passes", ",".join(passes),
             "--target", str(outdir / "target.json"),
             "--map-fds", str(outdir / "map_fds.json"),
             "--report", str(outdir / "optimize_report.json"),
             "--input", str(outdir / "prog.bin")],
            ["bpfrejit", str(prog_id)],
        ])
```

实际实现建议避免 `shell=True`，用 `subprocess.Popen` 串 stdout/stdin。shell pipeline 适合文档和一次性调试，runner 内部要用 argv list，避免路径/参数 quoting 问题。

### per-pass verify pipeline

v3 §4.3 的推荐是外部 bash loop。runner 可以调用一个 repo 内脚本，例如:

```text
runner/libs/rejit.py
  CliRejitSession.apply_rejit()
    create artifact tempdir
    optional bpfprof profile collection
    for prog_id:
      subprocess.run([
        "bpfrejit-pipeline",
        "--prog-id", str(prog_id),
        "--passes", ",".join(passes),
        "--workdir", prog_dir,
        "--profile", profile_json,
        "--json-out", result_json,
      ])
      parse result_json
      normalize to existing apply_rejit result schema
```

脚本职责:

```text
bpfget PROG_ID --full --outdir WORKDIR
CURRENT=WORKDIR/prog.bin
for PASS in enabled passes:
  bpfopt PASS side-inputs < CURRENT > CANDIDATE --report pass-N.json
  if changed:
    bpfverify --prog-type INFO.prog_type --map-fds map_fds.json < CANDIDATE > /dev/null
    accept candidate on rc=0, otherwise keep CURRENT and record rolled_back
bpfrejit PROG_ID CURRENT
write result.json
```

这个形态最贴近 v3: pipeline 和 per-pass rollback 不在 daemon 内部。Python 仍然负责高层生命周期、timeout、stderr tail、JSON artifact schema 和错误聚合。

### 错误处理

规则应保持当前 `apply_daemon_rejit()` 的外部行为:

- 单个程序失败不应让 wrapper 静默跳过程序；应写入 `per_program[prog_id].exit_code != 0` 和 `error`。
- `bpfget` 失败通常表示 prog_id 消失或权限问题，记录该程序失败。
- `bpfopt` 失败表示 pass/side-input/bytecode 错误，记录 stderr tail 和 report path。
- `bpfverify` 失败表示当前 pass rollback，不等于整个程序失败；最终没有改变时可返回 applied=false/changed=false。
- `bpfrejit` 失败表示最终替换失败，记录 verifier log/stderr，不做排除。
- wrapper 返回顶层 `exit_code=max(per-program exit_code)`，`error="; ".join(...)`，保持 artifact compact 逻辑可用。

## profile / PGO 数据流

当前 branch_flip 数据流:

```text
if "branch_flip" enabled:
  send profile-start(interval_ms=1000)
  sleep(1s)
  send profile-stop
for each prog_id:
  send optimize(prog_id)
daemon optimize 从 frozen ProfilingState 取对应 prog_id 的 ProfilingData
```

CLI 数据流建议:

```text
if "branch_flip" enabled:
  bpfprof --all --duration 1s --output WORKDIR/profile.json
for each prog_id:
  bpfget prog_id --full --outdir WORKDIR/prog_id
  bpfopt optimize --passes ... --profile WORKDIR/profile.json ...
```

需要补齐/确认的 CLI contract:

- `profile.json` 如果包含多个 prog_id，`bpfopt` 需要能根据当前程序选择 profile。可以通过 `bpfget --full` 的 `prog_info.json` 或显式 `--prog-id` 完成。
- 如果 profile 采集失败，当前 wrapper 会让整批 prog_id 都返回 profile failure。CLI wrapper 应保持这个行为，避免 branch_flip 在无 profile 情况下悄悄退化。
- profile 采集应在 baseline 之后、ReJIT 之前。它不属于 baseline/post measurement 窗口，但会延长 suite wall time。

## discover 迁移

当前 discover 模型已经是 runner 轮询，不是 daemon watch:

- `ManagedProcessSession.__enter__()` 启动 app 前记录 before prog IDs。
- app 启动后用 health check + `wait_until_program_set_stable()` 轮询，默认 `poll_interval_s=0.2`、`stable_window_s=2.0`，直到新程序集合稳定。
- corpus 在 baseline 前和 ReJIT 前再次 `_refresh_active_session_programs()`，如果原 prog_id 消失，会用 runner refresh 或 `bpftool prog show` 按程序 identity 重新匹配。

CLI 模式推荐:

- 新增 `runner.libs.rejit/list_programs()` 或 `runner.libs.bpf_programs.list_programs()`，默认实现为 `bpfget --list --json`，返回与当前 `bpftool -j prog show` 兼容的字段子集。
- 保留当前 polling/stable-window 语义。不要改成固定 "应用启动后 X ms 扫一次"，因为不同 app attach 时机差异很大。
- corpus/e2e 继续在 app start、baseline_refresh、rejit_refresh 做显式 discover。daemon 的 event-driven watch 对 benchmark runner 不是必需能力。

迁移风险:

- `bpfget --list --json` 输出字段必须覆盖当前 identity matching: `id/name/type/attach_type/expected_attach_type/attach_to/attach_target/attach_btf_name/attach_btf_id`。
- app reload 发生在 `bpfget --full` 和 `bpfrejit` 之间时，pipeline 会失败；应按程序错误记录，不重试过滤。
- corpus 同时启动多个 app，discover 需要继续维护 claimed_ids，避免多个 session 认领同一个 prog_id。

## Python wrapper API 草案

保留 driver 调用面:

```python
class RejitSession:
    @classmethod
    def start(cls, *, load_kinsn: bool = False) -> "RejitSession": ...
    def apply_rejit(
        self,
        prog_ids: Sequence[int],
        *,
        enabled_passes: Sequence[str] | None = None,
    ) -> dict[str, object]: ...
    def close(self) -> None: ...
```

CLI 实现:

```python
@dataclass
class CliToolchain:
    bpfget: Path | str = "bpfget"
    bpfopt: Path | str = "bpfopt"
    bpfverify: Path | str = "bpfverify"
    bpfprof: Path | str = "bpfprof"
    bpfrejit: Path | str = "bpfrejit"
    pipeline_script: Path | str = "bpfrejit-pipeline"

@dataclass
class CliRejitSession(RejitSession):
    tools: CliToolchain
    work_root: Path
    kinsn_metadata: dict[str, object]

    def apply_rejit(self, prog_ids, *, enabled_passes=None):
        passes = normalize(enabled_passes or benchmark_rejit_enabled_passes())
        profile = self.collect_profile_once(passes, prog_ids)
        per_program = {}
        for prog_id in prog_ids:
            per_program[prog_id] = self.run_program_pipeline(prog_id, passes, profile)
        return aggregate_like_apply_daemon_rejit(per_program, passes)
```

辅助 API:

```python
def list_live_programs() -> list[dict[str, object]]:
    # bpfget --list --json, with temporary bpftool fallback only during migration

def run_program_pipeline(
    prog_id: int,
    *,
    enabled_passes: Sequence[str],
    profile_json: Path | None,
    timeout_s: float,
) -> dict[str, object]:
    # returns one existing per-program result object

def run_pipeline(argvs: list[list[str]], *, timeout_s: float) -> PipelineResult:
    # Popen chain, capture final stdout and all stderr tails, close pipes correctly
```

不建议让 corpus/e2e driver 直接调用 subprocess。driver 应只知道 "baseline -> apply_rejit -> post_rejit"，否则后续 per-pass verify、profile、result schema、discover fallback 会分散到多个入口。

## 迁移步骤

1. CLI 完整性门槛: 先完成 v3 的 `bpfget`, `bpfopt optimize/per-pass`, `bpfverify`, `bpfprof`, `bpfrejit`。当前 repo 还没有这些可用命令，runner 不能先切。
2. 定义 CLI result schema: pipeline script 写 `result.json`，字段覆盖当前 daemon response 中 runner 使用的 `status/changed/summary/passes/inlined_map_entries/error_message/timings_ns`。
3. 在 `runner/libs/rejit.py` 内新增 `CliRejitSession`，保持 `apply_rejit()` 返回结构兼容现有 artifacts。
4. 新增 `bpfget --list --json` discover wrapper，先只替换内部 helper，不碰 app-level loader。
5. corpus/e2e 切换 session 创建: `RejitSession.start()` 默认 CLI。`--daemon` 参数改为兼容期参数或删除，artifact 中的 `daemon` 字段改为 `rejit_backend/toolchain` 这类有行为意义的字段。
6. 跑 VM smoke: 单 e2e case、单 corpus app、多 app corpus。重点看 program identity refresh、per_program ratio 和 ReJIT error surfacing。
7. 跑含 `branch_flip` 的 profile path，确认 `bpfprof` profile 被正确传给 `bpfopt`。
8. 删除 runner 对 daemon socket 的依赖，daemon 后续按 #45 瘦身成 watch + external command trigger。

## 过渡策略建议

推荐主线采用方案 B 的精神: 6 个 CLI 工具通过 smoke 后，runner 直接切 CLI，daemon 同步进入瘦身，不长期维护双后端。

可以接受一个很短的兼容窗口:

```text
BPFREJIT_RUNNER_BACKEND=cli     # default after migration
BPFREJIT_RUNNER_BACKEND=daemon  # only for bisect/rollback, planned removal
```

但不要把双后端作为长期产品面。长期双后端会让 bug 修复和 result schema 同时落在 daemon pipeline 与 CLI pipeline 两边，正好违背 v3 "Pipeline 是 bash/脚本，不是 daemon 内部逻辑" 的目标。

## 风险

### fork+exec 性能

每个程序至少会有 `bpfget + bpfopt + bpfrejit`，per-pass verify 还会有多个 `bpfopt + bpfverify`。fork+exec 是 ms 级，单个大 app 的 ReJIT 阶段可能增加数百 ms 到数秒。

影响判断:

- ReJIT 阶段发生在 baseline 与 post_rejit 测量窗口之间，通常不直接污染 `avg_ns_per_run`。
- suite wall time 会增加，尤其是 corpus 同时启动多个 app 且每个 app 多程序时。
- 可以通过一次 `bpfget --full` 准备 side-input、一次 `bpfprof --all --duration` 覆盖整批程序、顺序执行避免并发抖动来控制成本。

### discover 时机

daemon watch 是事件驱动，CLI 模式是 runner 轮询。当前 runner 已经轮询，因此风险主要在 `bpfget --list --json` 字段兼容和 app reload race。

建议沿用:

- app start 前取 before_ids。
- 启动后 poll 0.2s，稳定 2s。
- baseline 前和 ReJIT 前 refresh。
- 失败记录为错误，不引入过滤/跳过名单。

### 并发

corpus 会同时保持多个 app session 活着，但 ReJIT 当前是逐 app、逐 prog_id 调用。CLI 也应默认顺序执行，避免:

- 多个 `bpfrejit` 同时改内核程序表。
- 多个 pipeline 共用 target/profile/report 路径。
- 一个 app reload 导致另一个 app 的 discover claimed_ids 冲突。

如果未来并发优化，至少要保证 per-program workdir 隔离、claimed_ids 全局锁、stderr/result 聚合稳定。

### result schema 回归

现有 artifact compact 逻辑依赖 `passes`, `summary`, `per_program`, `program_counts`, `error`, `exit_code`, `enabled_passes`。CLI pipeline 初期最容易丢的是 per-pass `action=rolled_back`、`verify.status/error`、`sites_applied/sites_skipped`。这些字段必须由 `bpfopt --report` + wrapper 聚合补回来，否则 corpus/e2e artifact 会变薄，后续排错变差。

### profile contract

`bpfprof --all` 输出多程序 profile 时，`bpfopt` 必须知道当前 prog_id，否则 branch_flip 可能读错 profile 或静默无 profile。这个 CLI contract 需要在切 runner 前固定。

## 推荐最终结构

```text
runner drivers
  corpus/driver.py
  e2e/driver.py
  e2e/cases/*
      |
      v
runner.libs.case_common
      |
      v
runner.libs.rejit.RejitSession.apply_rejit()
      |
      v
CLI backend
  bpfprof --all --duration ... --output profile.json   # optional
  for prog_id:
    bpfget prog_id --full --outdir prog_dir
    bpfrejit-pipeline --prog-id prog_id --passes ... --workdir prog_dir
      bpfopt PASS < current > candidate --report pass.json
      bpfverify --prog-type ... < candidate
      bpfrejit prog_id current
```

这能让 corpus/e2e 保持现有生命周期语义，同时把 v3 要求的 bytecode pipeline、per-pass verify 和 profile side-input 都移出 daemon。
