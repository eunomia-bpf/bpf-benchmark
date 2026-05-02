# Round 15：删除 corpus/e2e/micro VM 超时

## 改了哪些文件

| 文件 | 行号 | 变更 |
|------|------|------|
| `runner/suites/corpus.env` | 原第 3 行 | 删除 `SUITE_DEFAULT_VM_TIMEOUT_SECONDS=7200` |
| `runner/suites/e2e.env` | 原第 3 行 | 删除 `SUITE_DEFAULT_VM_TIMEOUT_SECONDS=7200` |
| `runner/suites/micro.env` | 原第 3 行 | 删除 `SUITE_DEFAULT_VM_TIMEOUT_SECONDS=7200` |
| `runner/libs/run_contract.py` | 296 | 默认值从 `"7200"` 改为 `""` |
| `runner/libs/kvm_executor.py` | 152 | `int(config.kvm.timeout_seconds)` → `_optional_int(config.kvm.timeout_seconds)`（已有 `_optional_int` 函数，空字符串返回 `None`） |
| `runner/libs/vm.py` | 116, 144 | `timeout: int` → `timeout: int \| None`；两个 `subprocess.run(timeout=timeout)` 改为 `effective_timeout = timeout if timeout else None`，传 `effective_timeout` |

## test.env 为什么保留 3600s

`test` suite 是 kernel unittest（selftests / fuzz），单次跑 60 分钟已经够充裕。
更重要的是 test 跑在 CI 里，如果内核 panic 或 hang，需要 watchdog 来终止并报错，否则 CI job 永远不返回。
corpus/e2e/micro 是长跑 benchmark，本来就要跑几千秒，不需要 watchdog；如果 hang 了人工 Ctrl+C 即可。

## timeout=0 vs None：选择 `""` → `None`

选择"空字符串 `""` = 无超时"而不是 `"0"`：

- `_optional_int("")` 已在 `kvm_executor.py` 中定义，返回 `None`，与 `_optional_int(cpus)` 逻辑完全一致。
- Python `subprocess.run(timeout=None)` 的语义就是"无限等待"，清晰无歧义。
- `0` 在很多语境下容易被误读为"立刻超时"，不如 `None` 直觉。
- `KvmConfig.timeout_seconds: str = ""` 默认值已经是空字符串，自然对齐。

数据流：`suite.env` 不设 → `run_contract.py` 默认 `""` → `RUN_VM_TIMEOUT_SECONDS=""` → `KvmConfig.timeout_seconds=""` → `_optional_int("") = None` → `subprocess.run(timeout=None)`，全链路无超时，无需改 `KvmConfig` 类型。

## SIGTERM grace 是否加了

**未加**。最小改动原则：删掉 7200s watchdog 是主要目的，人工 Ctrl+C 时 vng 会正常传播 SIGTERM 给 guest，driver.py 有机会 finalize。SIGTERM handler 需要额外信号处理逻辑（`signal.signal` + grace period loop），改动量较大且容易引入新 bug，暂缓到有实际需求时再做。

## 验证

```
grep -nE 'SUITE_DEFAULT_VM_TIMEOUT_SECONDS' runner/suites/*.env
# 输出：runner/suites/test.env:3:SUITE_DEFAULT_VM_TIMEOUT_SECONDS=3600

python3 -m py_compile runner/libs/vm.py runner/libs/run_contract.py corpus/driver.py
# 无错误

python3 -m pytest tests/python/ -x -q
# 10 passed, 4 subtests passed
```
