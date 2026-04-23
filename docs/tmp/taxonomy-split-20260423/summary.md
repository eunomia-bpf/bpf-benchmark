# Taxonomy Split 2026-04-23

Scope:
- touched [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py)
- touched [runner/libs/rejit.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/rejit.py)
- did not touch `e2e/*`, `runner/libs/app_runners/*`, `daemon/*`
- did not run `vm-e2e` or `vm-corpus`

Checks:
- `python3 -m py_compile corpus/driver.py runner/libs/rejit.py runner/libs/case_common.py`: PASS
- `make check`: PASS
- `cargo test --manifest-path daemon/Cargo.toml`: PASS

## 1. 决策树代码位置 + 新子类 string

New reason strings:
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:57): `zero_sites_found`
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:58): `all_sites_rolled_back`
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:59): `applied_but_identical`
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:60): `no_passes_requested`
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:61): retained fallback `no_programs_changed_in_loader`

Decision-tree entrypoints:
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:529): `_apply_record_no_change_reason()`
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:563): `_comparison_exclusion_reason()`
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:595): `_build_program_measurements()`

Support wiring:
- [runner/libs/rejit.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/rejit.py:625): `_apply_result_from_response()` now validates and hoists `passes` + `enabled_passes`
- [runner/libs/rejit.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/rejit.py:825): `apply_daemon_rejit()` now preserves `enabled_passes` on both top-level and per-program records
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:965): `_slice_rejit_result()` now attaches per-program `scan` and normalized `enabled_passes`

## 2. 每个子类的判定条件

`no_passes_requested`
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:532)
- 条件：`enabled_passes` 为空，且没有任何回填的 requested pass

`zero_sites_found`
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:535)
- 条件：requested passes 非空，`scan.counts` 按 requested pass 聚合后的 `total_sites_found == 0`

`all_sites_rolled_back`
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:538)
- 条件：requested passes 非空，`total_sites_found > 0`，但 `summary.total_sites_applied == 0`
- 这里不要求 daemon 提供 `sites_rolled_back`；runner/corpus 侧把它视作 `sites_found - sites_applied`

`applied_but_identical`
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:540)
- 条件：`summary.total_sites_applied > 0`，但 top-level `changed == false`

Fallback `no_programs_changed_in_loader`
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:531)
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:542)
- 仅保留作理论兜底；正常四类应该吃掉原先 bucket

Related semantic cleanup:
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:545): row-level `changed` 现在只表示 final program changed
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:551): corpus 内 `any_changed` 也只看 final changed，所以 `applied_but_identical` 不再触发 post-REJIT measurement 或 “no comparable measurement” 误报

## 3. Daemon Apply Result Schema Requirements

Daemon apply response must keep:
- [runner/libs/rejit.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/rejit.py:652): top-level `changed: bool`
- [runner/libs/rejit.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/rejit.py:655): `summary.total_sites_applied: int`
- [runner/libs/rejit.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/rejit.py:660): `summary.passes_executed: int`
- [runner/libs/rejit.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/rejit.py:664): `passes: list`
- [runner/libs/rejit.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/rejit.py:213): `passes[].pass_name`
- [runner/libs/rejit.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/rejit.py:226): `passes[].sites_applied`

Runner-added fields consumed by corpus:
- [runner/libs/rejit.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/rejit.py:688): `enabled_passes`
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:984): `scan`

Scan-side requirement for `zero_sites_found` / `all_sites_rolled_back`:
- [runner/libs/rejit.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/rejit.py:278): `scan_site_totals_for_passes()`
- source is per-program dry-run scan counts, not daemon apply detail
- `sites_rolled_back` is derived as `sites_found - sites_applied`; no daemon field was added

## 4. 旧 `no_programs_changed_in_loader` reader grep

Command:

```bash
rg -n "no_programs_changed_in_loader|NO_PROGRAMS_CHANGED_IN_LOADER_REASON" \
  corpus/driver.py runner/libs/rejit.py runner/libs/case_common.py
```

Result:
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:61): constant definition
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:531): fallback return for non-mapping apply record
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:542): fallback return for logically unreachable leftover case

Conclusion:
- code-side reader/producer 已只剩 fallback；没有其它 active branch 继续直接产出旧 bucket

## 5. 38 个 program 的预测分布

这是基于 #664 证据的猜测，不是 VM 结果：

| reason | predicted count | basis |
| --- | ---: | --- |
| `zero_sites_found` | 33 | #664 结论里明确说旧 bucket 主体是 “0 site 命中”；这是大头 |
| `all_sites_rolled_back` | 4 | 现有硬证据是 `tetragon/default:event_execve` 的 rollback；按三 target + round6 的 38 口径，猜有少量同类 |
| `applied_but_identical` | 1 | #664 把它列为真实第三类，但没看到它是主流，先按稀有样本估计 |
| `no_passes_requested` | 0 | 这是本次补上的第 4 类，当前 benchmark policy 看起来更像“可能出现但未见硬证据” |

合计：`38`

## 6. Shortstat

Command:

```bash
git diff --shortstat
```

Result:

```text
2 files changed, 210 insertions(+), 42 deletions(-)
```
