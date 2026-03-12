# v1 Policy Cleanup

Date: 2026-03-12

## Summary

- 实际 policy tree 已经没有存活的 v1 YAML schema。`micro/policies/`、`micro/policies/per_family/`、`corpus/policies/` 下未发现 `version: 1`、`selection:`、`mode: allowlist`、或 list-form `families: [...]`。
- 本次清理重点转为两类残留：
  - parser/test 里的兼容入口：`default: stock`、non-canonical family names
  - 形式上是 v2、语义上仍接近 blind all-apply 的 policy 内容

## Removed Compat Code

### C++ scanner

- `scanner/src/policy_config.cpp`
  - 删除 `default: stock -> skip` 兼容归一化。
  - policy family 解析收紧为 canonical v2 names only：`cmov`、`wide`、`rotate`、`lea`、`extract`、`zero-ext`、`endian`、`branch-flip`。
- `scanner/tests/test_scanner.cpp`
  - 删除 valid `default: stock` 覆盖。
  - 删除 valid family alias 覆盖。
  - 新增 invalid `default: stock` 和 invalid non-canonical family 覆盖。
- `scanner/tests/policy_v2_golden/`
  - 移除旧的 `02-valid-stock-alias.yaml`、`04-valid-family-alias.yaml`、`08-invalid-duplicate-family-alias.yaml`。
  - 新增 strict-v2 golden：
    - `02-valid-default-apply.yaml`
    - `04-valid-family-only.yaml`
    - `06-invalid-stock-default.yaml`
    - `09-invalid-noncanonical-family.yaml`

### Python

- `corpus/policy_utils.py`
  - `parse_policy_v2()` / `render_policy_v2_text()` 现在只接受 `default: apply|skip`。
  - policy files 的 family 名现在要求 canonical；alias 归一化保留给非-policy 输入路径使用，不再是 policy parser 的兼容入口。
- `corpus/auto_tune.py`
  - 生成 policy 时不再写 `default_action="stock"`；统一写成 strict v2 的 `skip`。
- `corpus/generate_default_policies.py`
  - steady-state 逻辑改为：只要程序有 `cmov` sites，就生成 `families: {cmov: skip}`。
  - 不再按旧的 object-level regression gate 才决定是否写 `cmov: skip`。
- `micro/benchmark_catalog.py`
  - 审计确认无 v1 compat；已继续保持拒绝 inline `policy`。
- `micro/orchestrator/commands.py`
  - 审计确认无 v1 policy schema compat。

## Policy Content Changes

### Micro Policies

- 以下 6 个 micro benchmark 从裸 `default: apply` 收紧为 family-level steady-state：
  - `micro/policies/binary_search.yaml`
  - `micro/policies/bounds_ladder.yaml`
  - `micro/policies/bpf_call_chain.yaml`
  - `micro/policies/branch_dense.yaml`
  - `micro/policies/mixed_alu_mem.yaml`
  - `micro/policies/switch_dispatch.yaml`
- 这 6 个 benchmark 都不是显式测 `cmov` 的 case；现在统一为：

```yaml
version: 2
default: apply
families:
  cmov: skip
sites: []
```

### Corpus Policies

- 用更新后的 `corpus/generate_default_policies.py` 重新生成了 `corpus/policies/`。
- 生成结果：
  - `582` 个 corpus policy 文件写回
  - `494` 个程序现在带 `families: {cmov: skip}`
  - `88` 个程序仍是 `default: apply` 且无 `families`
    - 这 `88` 个文件的注释里 `cmov=0`
    - 即剩余 bare `default: apply` 文件不再遗漏 `cmov` family override
- 额外移除了 `2` 个 stale policy：
  - `corpus/policies/bpftrace/open_latency/do_sys_openat2.policy.yaml`
  - `corpus/policies/bpftrace/scheduler_latency/sched_switch.policy.yaml`
  - 当前 inventory 对应的新文件名是：
    - `corpus/policies/bpftrace/open_latency/kretprobe_do_sys_openat2.policy.yaml`
    - `corpus/policies/bpftrace/scheduler_latency/tracepoint_sched_sched_switch.policy.yaml`

## Validation

- Python compile:
  - `python3 -m py_compile corpus/policy_utils.py`
  - `python3 -m py_compile corpus/generate_default_policies.py`
  - `python3 -m py_compile micro/benchmark_catalog.py`
  - 均通过
- Python parser/unit tests:
  - `python3 -m unittest corpus.tests.test_policy_utils`
  - 通过
- Scanner tests:
  - 重新编译 `cmake --build scanner/build --target test_scanner -j`
  - 运行 `./scanner/build/test_scanner`
  - 结果：`PASS 170`
- Policy parsing:
  - 用 `corpus.policy_utils.parse_policy_v2()` 全量校验 `micro/policies/`、`micro/policies/per_family/`、`corpus/policies/`
  - 结果：`validated_policies=622`
- Tree search:
  - `micro/policies/`、`micro/policies/per_family/`、`corpus/policies/` 中未发现 `version: 1`、`selection:`、`mode: allowlist`、或 list-form `families: [...]`
  - 唯一剩余的 `default: stock` 位于 negative golden `scanner/tests/policy_v2_golden/06-invalid-stock-default.yaml`

## Notes

- `corpus/generate_default_policies.py` 本次跑批 summary：
  - `scanned_objects=565`
  - `site_positive_programs=582`
  - `cmov_skip_programs=494`
  - `stale_removed=2`
  - `warnings=111`
- 这些 warnings 来自部分 object 无法 inventory / 不含可枚举程序；不影响已生成的 `582` 个 site-positive policy 文件。
