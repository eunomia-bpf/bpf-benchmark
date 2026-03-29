# C++ Cleanup Report (2026-03-29)

## Scope

目标是把 C++ 侧 `micro_exec` 收缩到新架构要求的单一职责:

- `load .bpf.o`
- `BPF_PROG_TEST_RUN`
- 输出 JSON
- 退出

不再让 C++ 承担 batch orchestration、prepared state、daemon socket 通信、attach trigger workload、app 生命周期管理。

## Removed

### `runner/src/kernel_runner.cpp`

已删除或清空旧架构路径，只保留单次 TEST_RUN 执行链路:

- 删除 prepared kernel state / prepared handle 路径
- 删除 daemon REJIT / daemon socket 相关逻辑
- 删除 attach-trigger workload / auto trigger suites
- 删除 `execute_prepared_kernel_attach`
- 删除 `run_attach_workload`
- 删除 `run_auto_attach_trigger_workload`
- 删除 `run_trigger_workload_command`
- 删除 `section_supports_auto_attach_trigger`
- 删除 `build_auto_attach_trigger_plan`

当前文件只保留:

- 打开并加载 `.bpf.o`
- 选择目标 program
- `BPF_PROG_TEST_RUN`
- 读取 `exec_ns` / `retval` / `result`
- 输出 measurement JSON
- 可选 fixture replay / perf counters / jit/xlated dump

文件内已保留迁移注释:

```cpp
// TODO: moved to Python orchestrator (§5.6)
```

### `runner/include/micro_exec.hpp`

已删除与旧 orchestration/daemon/attach 路径绑定的 CLI 和结果结构字段，包括:

- `daemon_socket`
- `attach_program_name`
- `load_program_names`
- `trigger_command`
- `trigger_timeout_seconds`
- `manual_load`
- `rejit_program`
- `rejit`
- `opt_level`
- `no_cmov`
- `llvm_target_cpu`
- `llvm_target_features`
- `enabled_passes_specified`
- `enabled_passes`
- `disabled_passes`
- `log_passes`
- `compile_only`
- `attach_mode`
- `workload_iterations`
- `workload_type`

同时删除了结果结构中的死字段:

- `phase`
- `native_code_size`
- `bpf_insn_count`
- `correctness_mismatch`
- 整个 `rejit_summary`
- 整个 `daemon_pass_detail`

### `runner/src/common.cpp`

CLI 解析已收缩为仅支持:

- `test-run`
- `list-programs`

已删除解析项:

- `trigger_command`
- `trigger_timeout_seconds`
- `daemon_socket`
- `attach_mode`
- `attach_program_name`

同时删除了 JSON 输出层中遗留的 `rejit/daemon/attach` 结果字段，只保留 TEST_RUN measurement 所需输出。

### Build Graph

`runner/CMakeLists.txt` 已不再构建旧路径源文件:

- `runner/src/json_parser.cpp`
- `runner/src/llvmbpf_runner.cpp`
- `runner/src/batch_runner.cpp`
- `runner/src/daemon_client.cpp`

其中本次实际删除/移除出构建的死代码文件为:

- 删除 `runner/include/json_parser.hpp`
- 删除 `runner/src/json_parser.cpp`
- 删除 `runner/src/llvmbpf_runner.cpp`

## Verified Existing State

以下项当前已符合目标状态，本次主要做了确认，没有新增 diff:

### `runner/src/batch_runner.cpp`

当前已是占位文件，并明确标注:

```cpp
// TODO: moved to Python orchestrator (§5.6)
```

该文件不再参与 `micro_exec` 构建。

### `runner/include/daemon_client.hpp` / `runner/src/daemon_client.cpp`

这两个文件当前在工作树中已经不存在。本次确认了:

- 文件缺失
- `runner` 的 CMake / `src` / `include` 中无任何残留引用

## Kept

当前 C++ 侧保留的功能:

- `micro_exec test-run`
- `micro_exec list-programs`
- `.bpf.o` 加载
- `BPF_PROG_TEST_RUN`
- `exec_ns` / `wall_exec_ns` / `exec_cycles` / `retval` / `result` JSON 输出
- `map` / `staged` / `packet` / `context` 输入模式
- fixture replay
- perf counters
- JIT / xlated dump

## Validation

已执行:

1. `make runner`
2. `./runner/build/micro_exec --help`
3. `./runner/build/micro_exec test-run --help`
4. `./runner/build/micro_exec list-programs micro/programs/simple.bpf.o`

结果:

- `make runner` 通过
- `micro_exec` CLI 仅暴露 `test-run` 和 `list-programs`
- `list-programs` 正常列出 BPF object 中的 program

未执行:

- 真实 `micro_exec test-run` 运行

原因:

- 仓库 `AGENTS.md` 明确禁止在 host kernel 上执行 kernel/BPF runtime 动作；因此只做了 host-safe 编译和 CLI 验证。

## Line Count

只统计本次 C++ cleanup 实际涉及的文件，不包含现有的 Python 脏改动:

| file | + | - |
|---|---:|---:|
| `runner/CMakeLists.txt` | 2 | 0 |
| `runner/include/micro_exec.hpp` | 0 | 58 |
| `runner/src/common.cpp` | 3 | 112 |
| `runner/src/kernel_runner.cpp` | 311 | 3345 |
| `runner/include/json_parser.hpp` | 0 | 47 |
| `runner/src/json_parser.cpp` | 0 | 471 |
| `runner/src/llvmbpf_runner.cpp` | 0 | 905 |
| **total** | **316** | **4938** |

补充说明:

- `runner/src/batch_runner.cpp` 已经是 TODO 占位文件，但不在本次 diff 统计内
- `runner/include/daemon_client.hpp` / `runner/src/daemon_client.cpp` 当前已不存在，因此也不在本次 diff 统计内
- `runner/libs/corpus.py` 与 `runner/libs/rejit.py` 存在独立脏改动，未纳入本报告统计
