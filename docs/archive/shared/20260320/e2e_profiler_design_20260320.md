# E2E Profiler Design

Date: 2026-03-20

## Goal

为 BpfReJIT 增加一条可自动执行的 E2E profile pipeline：

1. 在 **live BPF programs** 上收集 runtime hotness
2. 在可用时收集 **program-wide perf branch counters**
3. 保留 **live enumerate site census**
4. 基于 profile + census 生成 **per-program v3 policy YAML**
5. 能复用现有 Tracee / Tetragon / Katran harness 做 guest-side collection

## Implemented Artifacts

### 1. Core profiler library

新增 `runner/libs/profiler.py`

能力：

- live 程序发现：`bpftool prog show`
- per-program delta stats：
  - `run_cnt`
  - `run_time_ns`
  - `avg_ns`
- 排名与 hotness：
  - `run_cnt_rank`
  - `run_time_rank`
  - `hotness = hot / warm / cold`
- live census：
  - 复用 `scanner enumerate --prog-id ... --json`
  - 输出 per-program `site_summary` + full `sites[]`
- optional perf：
  - `perf stat --bpf-prog <id>`
  - events: `cycles,instructions,branches,branch-misses`
  - 可计算 `branch_miss_rate`
  - 如果 perf 不可用，JSON 内显式标记 `supported=false` 与错误信息

### 2. Direct profiler CLI

新增 `runner/scripts/bpf_profiler.py`

用法：

```bash
sudo -n python3 runner/scripts/bpf_profiler.py \
  --duration 30 \
  --prog-id 42 \
  --output /tmp/profile.json
```

支持：

- `--prog-id`
- `--name-contains`
- `--type`
- `--no-sites`
- `--no-perf`

### 3. Profile-guided policy generator

新增 `runner/scripts/profile_guided_policy.py`

输入：

- `runner/scripts/bpf_profiler.py` 输出
- 或 `runner/scripts/collect_e2e_profile.py` 的 wrapper JSON
- 可选外部 `--census-json`

输出：

- per-program `v3` YAML
- `summary.json`

默认决策逻辑：

- hot gate：
  - `run_cnt >= --run-cnt-threshold`
  - `run_time_ns >= --run-time-threshold-ns`
- always families：
  - `wide,rotate,lea,extract,endian`
- `branch-flip`：
  - 仅在 `branch_miss_rate >= threshold`
  - 且 `branches >= min_branch_samples`
- `cmov`：
  - 仅在 `branch_miss_rate <= threshold`
  - 且 `branches >= min_branch_samples`
- 无 perf branch data 时：
  - branch-sensitive family 全部关闭

### 4. E2E collection driver

新增：

- `runner/scripts/collect_e2e_profile.py`
- `runner/scripts/collect_e2e_profile.sh`

支持 case：

- `tracee`
- `tetragon`
- `katran`

设计原则：

- **case 负责 bring-up / workload**
- **profiler 负责采样 / enumerate / perf**

也就是说，driver 只复用现有 session/workload 逻辑，不重复实现 BPF stats 或 scanner 调用。

## Output Shape

核心 profile JSON 结构：

```json
{
  "summary": {
    "program_count": 4,
    "active_program_count": 4,
    "total_run_cnt": 31760,
    "total_run_time_ns": 8933877
  },
  "perf": {
    "requested": true,
    "supported": false,
    "error": "..."
  },
  "programs": [
    {
      "prog_id": 9,
      "name": "trace_security_",
      "run_cnt": 23817,
      "run_time_ns": 7274425,
      "avg_ns": 305.43,
      "branch_misses": null,
      "branch_miss_rate": null,
      "hotness": "hot",
      "site_summary": {
        "total_sites": 10,
        "branch_flip_sites": 4,
        "cmov_sites": 6
      },
      "sites": [
        {"insn": 9, "family": "branch-flip", "pattern_kind": "branch-flip"}
      ]
    }
  ]
}
```

`collect_e2e_profile.py` 的输出在外层再包一层 case metadata：

- `case`
- `mode`
- `workloads`
- `setup`
- `profile`

`profile_guided_policy.py` 已兼容这两种输入形态。

## Validation

### A. Host smoke: direct profiler

命令：

```bash
sudo -n python3 runner/scripts/bpf_profiler.py \
  --duration 1 \
  --type kprobe \
  --no-perf \
  --output /tmp/bpf_profile_smoke.json
```

结果：

- programs: `133`
- active programs: `0`
- total sites discovered by live enumerate: `1278`

说明：

- CLI / bpftool / scanner / JSON 输出链路正常
- 这次 host smoke 没有主动打 workload，所以 `run_cnt` 全为 `0` 是预期现象

### B. Host smoke: perf probe

命令：

```bash
sudo -n python3 runner/scripts/bpf_profiler.py \
  --duration 1 \
  --prog-id 25 \
  --no-sites \
  --output /tmp/bpf_profile_perf_probe.json
```

结果：

- profiler 正确捕获 perf 错误并写入 JSON
- 当前 host 的 `perf` 与运行内核版本不匹配
- 因此 `perf.supported=false`

这条路径说明：

- perf 不可用时不会让 profiling 失败
- branch-sensitive policy 会自动退化为 conservative mode

### C. Guest smoke: Tracee collection

guest 运行命令：

```bash
python3 runner/scripts/collect_e2e_profile.py tracee \
  --output-json docs/tmp/e2e_profiler_tracee_smoke_20260320.json \
  --duration 6 \
  --no-perf
```

结果文件：

- `docs/tmp/e2e_profiler_tracee_smoke_20260320.json`

结果摘要：

- mode: `manual_fallback`
- active programs: `4`
- total run_cnt: `31760`
- site totals:
  - `branch_flip_sites=21`
  - `cmov_sites=21`
  - `wide_sites=3`
  - total `45`
- top hot program:
  - `prog_id=9`
  - `name=trace_security_`
  - `run_cnt=23817`
  - `run_time_ns=7274425`
  - `hotness=hot`

这说明：

- guest-side bring-up
- workload execution
- BPF delta profiling
- live enumerate

已经形成闭环。

### D. Guest smoke: profile-guided policy generation

命令：

```bash
python3 runner/scripts/profile_guided_policy.py \
  --profile-json docs/tmp/e2e_profiler_tracee_smoke_20260320.json \
  --output-dir docs/tmp/e2e_pgo_tracee_smoke_policies_20260320 \
  --emit-empty-policies
```

结果文件：

- `docs/tmp/e2e_pgo_tracee_smoke_policies_20260320/summary.json`

摘要：

- generated policies: `4`
- `prog_id=8` 选出了 `3` 个 `wide` sites
- `branch-flip` / `cmov` 因无 perf branch data 被关闭

这和目标逻辑一致：

- hot program 才生成非空 policy
- branch-sensitive family 需要 branch telemetry 才会打开

### E. Guest smoke: Katran status

尝试过两条 smoke：

1. `katran --smoke --duration 3 --no-perf`
2. `katran --smoke --duration 3 --no-perf --katran-packet-repeat 1 --katran-use-wrk`

当前结果：**都未成功完成**

失败点：

- Python parallel warmup timeout
- `wrk` warmup timeout

对应异常分别位于：

- `measure_phase()` warmup validation
- `run_wrk()` subprocess timeout

结论：

- Katran case 的当前 guest workload 稳定性仍需单独调参
- 失败点在 **workload path / guest networking**, 不是 profiler library 或 policy generator

## Tests

新增单测：

- `tests/test_profile_guided_policy.py`

覆盖：

- wrapper profile 兼容
- nested census 提取
- hot gate + branch-sensitive gate 决策

执行：

```bash
python -m unittest discover -s tests -p 'test_profile_guided_policy.py'
python -m unittest corpus.tests.test_policy_utils
```

结果：通过。

## Notable Tradeoffs

1. `perf stat --bpf-prog` 目前按 **program-wide** 计数
   - 适合做 admission / gating
   - 不足以直接做 per-site attribution

2. `hot/warm/cold` 当前是基于 interval delta 排名
   - 适合自动批处理
   - 不是长期稳定的全局标签

3. policy generator 目前是规则式
   - 优点：保守、可解释、便于论文陈述
   - 缺点：还不是搜索式 auto-tune

## Next Steps

1. 给 Katran collection 增加更稳的 traffic preset
   - 例如单请求 canary / 更长 warmup / 明确 attach-ready 检测

2. 在 perf 可用 VM 上补一次 branch-miss smoke
   - 验证 `branch-flip` / `cmov` gating 真正由 PMU 驱动

3. 可选扩展：
   - 输出独立 `site_census.json`
   - 增加 leave-one-out site profitability runner
   - 把 `collect_e2e_profile.py` 挂到 `e2e/run.py` 子命令里
