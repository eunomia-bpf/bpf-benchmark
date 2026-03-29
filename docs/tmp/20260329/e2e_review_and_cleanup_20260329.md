# E2E Review And Cleanup (2026-03-29)

## Executive summary

- E2E 现在已经有一个共享壳层：`e2e/case_common.py` 负责统一的 `setup -> start -> baseline -> scan/apply -> post_rejit -> stop/cleanup` 顺序。
- 但每个 repo 的 app lifecycle 仍然大量留在各自 `case.py` 里，和新架构 `runner/libs/app_runners/` 的目标还有明显距离。
- 这次清理主要删掉了三类遗留物：
  - 旧 scan 结果兼容层 `enumerate_record`
  - 旧 Katran/Tracee payload schema 字段
  - 已经失效的 E2E profile 脚本和硬编码 smoke 脚本
- 未实现 `app_runners`；只在各 case 的 lifecycle 代码旁加了 TODO。

## Counting note

- 下表的行数是按“函数/代码块归属”做的粗粒度统计，不是 AST 级精确切片。
- `lifecycle` 指 setup/start/workload dispatch/stop/cleanup/session 管理。
- `measurement` 指 app metrics collection / BPF stats collection / phase comparison。
- `reporting` 指 markdown/report/result payload formatting。

## 1. Structure analysis

| File | Lifecycle LOC | Measurement LOC | Reporting LOC | Reuse / extraction candidates |
| --- | ---: | ---: | ---: | --- |
| `e2e/case_common.py` | ~395 | ~46 | ~33 | 已经是共享 orchestration；不该再塞 repo-specific logic。真正该抽的是各 case 传入的 `start/workload/stop` hooks。 |
| `e2e/cases/bcc/case.py` | ~294 | ~129 | ~309 | `run_setup_script()`, tool binary resolution, `ToolProcessSession`, `wait_for_attached_programs()`, `run_phase()` 里的 `start/workload/stop`。 |
| `e2e/cases/bpftrace/case.py` | ~235 | ~116 | ~283 | `ensure_required_tools()`, attach wait, script session startup/shutdown, `run_phase()` 里的 lifecycle hooks。 |
| `e2e/cases/scx/case.py` | ~281 | ~252 | ~82 | `ScxSchedulerSession`, artifact checks, workload selection, `run_scx_case()` 里的 lifecycle hooks。 |
| `e2e/cases/tetragon/case.py` | ~608 | ~410 | ~173 | `TetragonAgentSession`, policy staging, binary/setup resolution, preflight hook, map capture hook, `daemon_payload()` 里的 lifecycle hooks。 |
| `e2e/cases/tracee/case.py` | ~657 | ~903 | ~175 | `TraceeAgentSession`, command construction, warmup/latency probe orchestration, per-cycle lifecycle hooks in `run_tracee_case()`。 |
| `e2e/cases/katran/case.py` | ~866 | ~446 | ~70 | `KatranDsrTopology`, `NamespaceHttpServer`, `KatranDirectSession`, map config/reset, per-cycle lifecycle hooks in `run_katran_case()`。 |

## 1.1 `case_common.py` boundary

- `case_common.py` 里没有 repo-specific app runner。
- 它主要是 generic lifecycle shell + kinsn/module metadata + result persistence。
- 因此它和新架构不冲突；真正要下沉到 `runner/libs/app_runners/` 的是各 case 传给 `run_case_lifecycle()` 的 repo-specific hooks。

## 1.2 Extraction priority

1. `katran`
   生命周期代码最多，而且 topology/server/session/reset/workload 都是 corpus 与 E2E 最可能共享的部分。
2. `tracee`
   统计逻辑复杂，但真正应抽出去的是 launch/program selection/warmup/workload/stop 这层。
3. `tetragon`
   policy staging + agent lifecycle + preflight gating 很适合做成 AppRunner。
4. `bcc` / `bpftrace`
   结构已经比较规整，抽成 `app_runners` 的成本低。
5. `scx`
   共享潜力明确，但当前 corpus 复用面比前几项小一些。

## 2. Methodology audit

| Case | Same-image paired measurement | Significance test | Repeat / sample_count | Notes |
| --- | --- | --- | --- | --- |
| `tracee` | Yes, explicit paired cycles plus control phase | Yes, `exact_paired_permutation_on_signed_deltas` | full `sample_count=5`, smoke `2`; full duration `20s`, smoke `6s`; warmup `4s/2s`; latency probes `8/3` | 当前 E2E 方法学里最完整。 |
| `katran` | Yes, explicit paired cycles | No | full `sample_count=3`, smoke `1`; duration `10s/3s`; `packet_repeat=4/2`; warmup `2s/1s` | 用 paired-cycle median 做比较，没有显著性检验。 |
| `tetragon` | Single live-session stock -> rejit, but not repeated paired cycles | No | effective repeat `1`; duration `30s/8s`; preflight `5s` | 更像 single-pass before/after。 |
| `bcc` | Single tool session stock -> rejit | No | effective repeat `1`; duration `30s/10s` | 每个 tool 只测一次 baseline 和一次 post。 |
| `bpftrace` | Single script session stock -> rejit | No | effective repeat `1`; duration full `30s`, smoke `5s` | 每个 script 只测一次 baseline 和一次 post。 |
| `scx` | Single scheduler session stock -> rejit | No | effective repeat `1`; duration `30s/10s` | 没有 sample_count。 |

## 3. Old-path audit

### 3.1 Manual fallback

- `tracee` 已确认没有 manual `.bpf.o` fallback；binary 不存在时直接报错：`manual .bpf.o fallback is forbidden`。
- `tetragon` 也一样，binary 缺失时直接报错，不再伪造 fallback 成功。

### 3.2 Skip disguised as success

- `e2e/run.py` 只接受 `status in {"ok", "error"}`。
- `tests/python/test_e2e_run.py::test_run_single_case_rejects_skipped_payload` 仍然覆盖这一点。
- `tracee` / `tetragon` 的 markdown `skip_reason` 兼容 fallback 已在当前工作树中移除；这次确认无需再补额外兼容。

### 3.3 Old daemon CLI compatibility

- 当前 Python 侧已经是 serve-only：`runner/libs/rejit.py` 走 `_start_daemon_server(... serve --socket ...)` + socket optimize/apply。
- 没有发现旧 `apply/apply-all/watch/rewrite/enumerate` CLI 分支残留在 E2E Python 路径里。
- 这次删掉了 scan 结果里仅为旧 enumerate pipeline 保留的 `enumerate_record` 包装。

## 4. Cleanup performed

### 4.1 Removed code / schema

- `runner/libs/rejit.py`
  - 删除 scan result 的 `enumerate_record` 兼容层。
- `runner/libs/profiler.py`
  - 不再依赖 `enumerate_record`。
  - 删除未使用的 `render_profile_json()`。
- `e2e/cases/tracee/case.py`
  - 删除旧 result schema 字段 `same_image_measurement`。
- `e2e/cases/katran/case.py`
  - 删除旧 result schema 字段 `same_image_measurement`。
  - 删除旧 result schema 字段 `control_plane_mode`。
- `e2e/run.py`
  - 删除未消费的 `--katran-policy`。
  - 删除未消费的 `--katran-server-binary`。
- `tests/python/test_case_common.py`
  - 更新为新的 scan result schema。

### 4.2 Removed files

- `e2e/cases/tetragon/guest_smoke.sh`
  - 全仓库没有代码调用；脚本硬编码个人路径，属于旧手工入口。
- `runner/scripts/collect_e2e_profile.py`
  - 已经漂移成失效脚本；当前直接 import 就失败：
    - `ImportError: cannot import name 'DEFAULT_RUNNER' from 'e2e.cases.tracee.case'`
  - 代码调用者只有它自己的 `.sh` wrapper。
- `runner/scripts/collect_e2e_profile.sh`
  - 只包装已删除的 `collect_e2e_profile.py`。

## 5. TODOs added for AppRunner extraction

- `e2e/cases/bcc/case.py`
- `e2e/cases/bpftrace/case.py`
- `e2e/cases/scx/case.py`
- `e2e/cases/tetragon/case.py`
- `e2e/cases/tracee/case.py`
- `e2e/cases/katran/case.py`

这些 TODO 都标在 repo-specific lifecycle hooks 附近，明确下一步应该把 `setup/start/workload/stop` 挪到 `runner/libs/app_runners/<repo>.py`。

## 6. Dead-file audit by directory

### `e2e/`

- 已删除：
  - `e2e/cases/tetragon/guest_smoke.sh`
- 未删除：
  - `e2e/cases/tracee/config_read_hotpath.yaml`
    - 不是默认路径，但仍然可通过 `--config` 选择，且内容不是坏配置；证据不足，不按死文件处理。

### `runner/libs/`

- 已清理旧字段/死函数：
  - `runner/libs/rejit.py` 的 `enumerate_record`
  - `runner/libs/profiler.py` 的 `render_profile_json()`
- 未删除：
  - `runner/libs/profiler.py`
    - 仍被 `runner/scripts/bpf_profiler.py` 使用，不能按死库删除。

### `tests/python/`

- 没有发现只服务于已删除功能、且可整体删掉的 test file。
- 只需要把 `test_case_common.py` 的 mock schema 跟着新 scan result 结构更新。

### `runner/scripts/`

- 已删除：
  - `runner/scripts/collect_e2e_profile.py`
  - `runner/scripts/collect_e2e_profile.sh`
- 保留：
  - `runner/scripts/bpf_profiler.py`
    - 仍是可工作的 generic live-program profiler CLI。
  - `runner/scripts/aws_x86.sh`
    - 仍有自己的 Katran server binary 分支；不是“只被已删代码引用”的死脚本。

## 7. Corpus reuse conclusions

- 复用潜力最高的不是 measurement/reporting，而是 app lifecycle。
- 对 corpus/orchestrator 最理想的共享面应该是：
  - AppRunner owns:
    - setup artifacts
    - userspace app/session start
    - live program discovery / target selection
    - workload driving
    - stop / cleanup
  - Corpus owns:
    - batch scan/apply
    - BPF stats measurement
    - corpus-level result aggregation
  - E2E owns:
    - app metrics measurement
    - paired-cycle / significance methodology
    - app-facing report formatting

- 以当前代码看，最值得优先抽的共享对象：
  - `KatranDsrTopology` + `NamespaceHttpServer` + `KatranDirectSession`
  - `TraceeAgentSession` + command/program selection
  - `TetragonAgentSession` + policy staging
  - `BCC` / `bpftrace` 的 session + attach wait helpers

## 8. Verification

- `python3 -m py_compile $(rg --files e2e runner/libs tests/python runner/scripts -g '*.py')`
  - passed
- `make python-tests`
  - passed, `61 passed`
- `pytest tests/python/ -q`
  - passed, `61 passed`

