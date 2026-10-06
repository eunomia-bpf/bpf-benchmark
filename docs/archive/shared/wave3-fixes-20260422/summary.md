# Wave 3 Silent-Failure Fixes Summary

Date: 2026-04-22
Status: completed
Scope: fix all 8 findings from `docs/tmp/wave3-silent-failure-review-20260422/summary.md`

## Finding 1 — CRITICAL — runner 把 `applied` 误当 `changed`

Status: fixed

Changed files:
- `runner/libs/rejit.py:632-672,830-868` — apply result 现在显式解析并校验 daemon `changed` / `summary.program_changed`，聚合结果新增 top-level `changed` / `changed_any` / `all_changed`。
- `runner/libs/case_common.py:89-124` — `rejit_result_has_any_apply()` 改为看 `changed`、`summary.program_changed`、`summary.total_sites_applied > 0`，不再看 `applied`。

Before:
- daemon 可以返回 `applied=true, changed=false`，runner 仍会把它当成“发生过程序变化”，继续跑 post-ReJIT measurement，并把缺 post 阶段当成错误。

After:
- `applied` 只表示 apply 请求成功。
- “是否真的改动过程序”统一由 `changed` / `summary.program_changed` / `total_sites_applied > 0` 决定。
- post-ReJIT measurement 和 post 缺失错误只在真实发生程序变化时触发。

## Finding 2 — HIGH — `bpftool prog show` schema drift 静默降级

Status: fixed

Changed files:
- `runner/libs/agent.py:110-131,147-149` — 新增 `bpftool_prog_show_records()`；payload 不是 list 或 list 元素不是 object 时直接 raise，错误里包含类型和 payload 片段。
- `runner/libs/app_runners/tracee.py:21-27,375` — Tracee 当前 program id 发现切换到共享的严格 `bpftool_prog_show_records()`。

Before:
- `bpftool -j -p prog show` 一旦返回非 list，runner 直接返回空数组，后续表现成“没找到 program”，属于静默降级。

After:
- schema mismatch 立即显式失败。
- 真正的空 list 只保留给“bpftool 正常返回 list，但当前没有匹配 program”的场景。

## Finding 3 — HIGH — `counts.applied_sites/total_sites` 类型错误被静默归零

Status: fixed

Changed files:
- `runner/libs/rejit.py:516-581` — counts 字段改为 strict validation；`counts.applied_sites` 类型错误直接 raise；只有显式 legacy contract 才允许用 `counts.total_sites` 合成。
- `e2e/cases/scx/case.py:711-719` — `site_totals.total_sites` 改为显式类型检查，不再 `int(... or 0)` 静默兜底。

Before:
- `counts.applied_sites="oops"`、`counts.total_sites={}` 这类响应会被 runner/SCX case 吞掉并当成 0。

After:
- 非 `int` / `bool` / 负数 都会直接报错。
- 只有老合同明确允许时，才会从 `counts.total_sites` synthesize `applied_sites`。

## Finding 4 — HIGH — daemon per-CPU map size fallback 1

Status: fixed

Changed files:
- `daemon/src/bpf.rs:849-975` — `bpf_map_lookup_value_size()` 改成 `Result<usize>`；`possible_cpu_count()` / `read_possible_cpu_count()` / `parse_possible_cpu_list()` 全链路改成 hard fail，错误包含 `/sys/devices/system/cpu/possible` 路径和解析原因；`OnceLock` 缓存 `Result` 而不是静默值。
- `daemon/src/invalidation.rs:42` — batch lookup 读取 map value size 改为 `?` 传播失败。
- `daemon/src/passes/map_inline.rs:251-256,1501` — map-inline lookup size 调用点改成显式传播，pseudo-map-value 分支补充 map id 上下文。

Before:
- 读不到 `/sys/devices/system/cpu/possible` 时 daemon 会静默 fallback 到 1 CPU，导致 per-CPU map value size 可能被低估，下游 batch lookup / map_inline 在错误大小上继续运行。

After:
- 读取或解析 possible CPU count 失败会立刻 hard fail。
- per-CPU map lookup size 不再用错误的 1 CPU 大小继续执行。

## Finding 5 — HIGH — Tracee event 文件 parse 静默丢行

Status: fixed

Changed files:
- `runner/libs/app_runners/tracee.py:83,110-155,163-230,244,267,313-328` — event file reader 加 strict mode；JSON parse 失败、非 object、缺 `event_name` 时记录错误并唤醒等待方；`wait_for_event()` / Tracee 健康检查会优先抛出 parse error。
- `e2e/cases/tracee/case.py:484-486,522-524` — workload 前后显式检查 collector parse error，避免坏 event file 被吞掉后继续做零事件统计。

Before:
- dedicated event file 中的坏行会被 `_parse_event_line()` 直接 `return`，结果变成“丢事件但不报错”。
- stdout/stderr 混合流和 dedicated event file 用同一套 silent skip 逻辑。

After:
- dedicated event file 走 strict path，遇到坏行会带原始行片段直接失败。
- stdout/stderr 混合日志仍保留 silent skip，不影响原本容错需求。

## Finding 6 — MEDIUM — `sample_bpf_stats(prog_fds=)` 死参数

Status: fixed

Changed files:
- `runner/libs/bpf_stats.py:44-46` — 删除 `prog_fds` 参数和内部 `del prog_fds`。
- `runner/libs/case_common.py:595,617`、`corpus/driver.py:246,258,434`、`e2e/cases/scx/case.py:163,196,307`、`e2e/cases/tracee/case.py:484,522` — 所有 caller 改成只传 program ids。

Before:
- API surface 暗示 `sample_bpf_stats()` 会利用 loader-owned FDs，但实现完全忽略。

After:
- 接口与实现一致，所有 caller 不再传死参数。

## Finding 7 — MEDIUM — Katran case-local parser 从未被用

Status: fixed

Changed files:
- `e2e/cases/katran/case.py:37-97` — 删除未接入的 case-local `build_parser()`。
- `e2e/cases/katran/case.py:107-112` — 去掉 `getattr(..., default)` 风格的“伪暴露参数”，改成直接使用 authoritative parser 已提供的通用参数和 Katran 内建默认值。

Before:
- `build_parser()` 定义了一堆 Katran-specific flags，但 `e2e/driver.py` 并不会暴露这些 flag。
- case 里又用 `getattr(..., default)` 读取它们，形成“看起来可配置，实际上永远走默认”的死接口。

After:
- 只保留 `e2e/driver.py` 这一套 authoritative parser。
- Katran case 不再声明或读取未接入 CLI 的 case-local 参数。

## Finding 8 — LOW — suite temp cleanup 吞 `OSError`

Status: fixed

Changed files:
- `e2e/driver.py:257-269` — `FileNotFoundError` 明确忽略；其他 `OSError` 收集到 `args._suite_cleanup_errors` 并打印到 stderr。

Before:
- cleanup 中所有 `OSError` 都直接 `continue`，无法区分“文件已经没了”和“权限/IO 问题”。

After:
- 正常 race（文件不存在）继续忽略。
- 其他 cleanup 失败会保留诊断信息，不再被完全吞掉。

## Validation

Completed:
- `python3 -m py_compile runner/libs/agent.py runner/libs/app_runners/tracee.py runner/libs/rejit.py runner/libs/case_common.py runner/libs/bpf_stats.py corpus/driver.py e2e/cases/scx/case.py e2e/cases/tracee/case.py e2e/cases/katran/case.py e2e/driver.py` — PASS
- `make -C daemon release` — PASS
- `make check` — PASS
- `make check` (after `runner/libs/agent.py` strict list-item validation) — PASS
- `make check` (after Tracee partial-line buffering fix) — PASS
- `make vm-e2e E2E_SMOKE=1` — PASS
  - initial run token `run.x86-kvm.e2e.6af579a6` exposed a new regression in the first Tracee smoke case: dedicated event-file strict parsing treated a temporary EOF fragment as a complete line and raised `invalid JSON`.
  - follow-up fix in `runner/libs/app_runners/tracee.py` buffered unterminated event-file fragments until newline or final flush.
  - rerun token `run.x86-kvm.e2e.321a376a` completed with `e2e: ALL PASSED`:
    - `tracee` OK
    - `tetragon` OK
    - `bpftrace` OK
    - `scx` OK
    - `bcc` OK
    - `katran` OK
- `make vm-corpus SAMPLES=5` — FAIL, but REJIT-specific validation succeeded
  - run token `run.x86-kvm.corpus.e8510c61`
  - preserved artifact run dir: `corpus/results/x86_kvm_corpus_20260422_190826_775848`
  - suite-level exit reason: multiple app-native attach/measurement failures unrelated to this patchset:
    - `bcc/capable`
    - `bcc/bindsnoop`
    - `bcc/biosnoop`
    - `bcc/vfsstat`
    - `bcc/opensnoop`
    - `bcc/tcpconnect`
    - `bpftrace/vfsstat`
    - `tetragon/default`
  - REJIT-side signal for this task was healthy:
    - `optimization_summary.applied_sample_count = 8`
    - `comparison_exclusion_reason_counts.no_programs_changed_in_loader = 23`
    - excluded program records now correctly show `applied=true, changed=false` rather than being treated as changed, e.g. `bcc/execsnoop`, `bcc/syscount`, `bcc/tcplife`, `bcc/runqlat`, `scx/rusty`, `tracee/default`, `katran`

Pending:
- none

Run IDs / artifact paths:
- `vm-e2e`:
  - initial failing smoke run: `run.x86-kvm.e2e.6af579a6`
  - passing smoke rerun: `run.x86-kvm.e2e.321a376a`
  - rerun result directories:
    - `e2e/results/tracee_20260422_185002_130541`
    - `e2e/results/tetragon_20260422_185159_187408`
    - subsequent rerun case directories are created under `e2e/results/` with the same 2026-04-22 18:50Z run window
- `vm-corpus`: pending
- `vm-corpus`:
  - run token: `run.x86-kvm.corpus.e8510c61`
  - preserved artifact dir: `corpus/results/x86_kvm_corpus_20260422_190826_775848`
  - summary signals live in:
    - `corpus/results/x86_kvm_corpus_20260422_190826_775848/result.json`
    - `corpus/results/x86_kvm_corpus_20260422_190826_775848/metadata.json`

## Edge Cases / Trade-offs

- `bpftool_prog_show_records()` 现在不仅校验顶层 payload 是 list，也校验 list 元素必须是 object；这样可以把“顶层没坏，但元素 schema 已漂移”的情况也拉成显式失败。
- Tracee strict parse 只应用在 dedicated event file；stdout/stderr 混合流仍保持 silent skip，避免把普通日志噪音当成 event parser failure。
- Tracee dedicated event file 还需要区分“真正的坏尾行”和“writer 尚未写完、当前 EOF 暂时没有换行的半行”；最终实现是 strict parser 仍保留，但只在拿到完整行或 stop/final flush 时触发。
- daemon per-CPU CPU-count 失败现在是 hard fail，代价是错误更早暴露；这是刻意行为，避免错误 value size 污染后续 benchmark 和 invalidation 结果。
- 当前 `vm-corpus` 的失败点集中在 BCC/BPFTrace/Tetragon app-native attach expectations 和 comparable-measurement preconditions，不像本次 silent-failure 修复引入的回归；artifact 中 REJIT comparison exclusions 已经正确区分了 `applied` 与 `changed`。

## Next Step Suggestions

- `make vm-e2e E2E_SMOKE=1` 和 `make vm-corpus SAMPLES=5` 完成后，建议至少对受影响最大的 case 做一次 authoritative rerun：
- `make vm-e2e E2E_SMOKE=1` 和 `make vm-corpus SAMPLES=5` 已完成；建议至少对受影响最大的 case 做一次 authoritative rerun：
  - Tracee / SCX：受 changed-vs-applied 与 strict parse/strict counts 影响，最可能改变“是否进入 post phase”与 error accounting。
  - any per-CPU map heavy path：受 daemon hard fail 影响，旧结果如果是在错误 CPU count 下跑出来，benchmark 数字不应继续沿用。
- 如果要继续把 corpus 绿掉，下一步应该单独处理 app-native failures：
  - BCC attach-count expectations under current kernel/toolchain
  - `bpftrace/vfsstat` 内核头提取时的 `tar ... Cannot change ownership ...` 路径
  - `tetragon/default` 的 `missing_baseline_exec_ns` / comparable-measurement gating
