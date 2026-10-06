# Kernel Runner Measurement Fixes

日期：2026-03-12

## 范围

修改文件：

- `micro/runner/include/micro_exec.hpp`
- `micro/runner/src/common.cpp`
- `micro/runner/src/kernel_runner.cpp`

## 修复内容

### 1. Dual timing output

- `exec_ns` 现在始终直接使用 `bpf_prog_test_run_opts().duration`
- `timing_source` 固定标记为 `ktime`
- `wall_exec_ns` 现在始终单独输出，不再只在 `duration == 0` 时参与 fallback
- 新增 `timing_source_wall = "rdtsc"`；若目标架构不支持 TSC，则输出 `timing_source_wall = "unavailable"` 且 `wall_exec_ns = null`

结果语义现在明确为：

- `exec_ns`: kernel `ktime` 的 per-repeat 平均执行时间
- `wall_exec_ns`: 外层 `rdtsc` 的 per-repeat 平均 wall time

### 2. Post-recompile warmup

- `--warmup/--warmups` 不再被吞掉，而是接入 runner
- 默认 `warmup_repeat = 5`
- warmup 只在 `recompile.applied == true` 后触发
- warmup 与正式计时共用同一条 `bpf_prog_test_run_opts()` 执行路径，并在每次调用前重置：
  - `duration` / `retval`
  - `data_out` / `data_size_out`
  - `ctx_out` / `ctx_size_out`
  - `result_map` 的结果槽

这样 warmup 和 measured run 看到的是同一套 test-run 配置，避免了 re-JIT 后首次执行的前端冷态污染正式样本。

### 3. Adaptive repeat

- 默认开启 adaptive repeat
- 新增 `--adaptive-repeat` / `--no-adaptive-repeat`
- 新增 `--target-window-ns`，默认 `100000`
- probe 固定使用 `repeat = 10`
- 若 probe 返回的 `duration < 50ns * repeat`，则按 `target_window_ns / probe_avg_ns` 放大 repeat
- 最终 repeat 取 `max(requested_repeat, computed_repeat)`，不会把用户显式传入的 repeat 降低

实现上，probe / warmup / measured run 全部复用同一个 helper，避免不同路径的 buffer/reset 行为不一致。

## 编译验证

已通过：

```bash
make -C micro micro_exec
```

## 运行验证

任务里给出的直跑命令：

```bash
./micro/build/runner/micro_exec run-kernel --bpf-obj micro/programs/simple.bpf.o --iterations 3 --repeat 200
```

对 `micro_exec` 直跑来说还缺少 `simple` 这个 benchmark 的 direct-run 元数据；等价可运行命令如下：

```bash
sudo -n ./micro/build/runner/micro_exec run-kernel \
  --bpf-obj micro/programs/simple.bpf.o \
  --io-mode staged \
  --input-size 64 \
  --repeat 200
```

实际输出示例：

```json
{
  "exec_ns": 9,
  "timing_source": "ktime",
  "timing_source_wall": "rdtsc",
  "wall_exec_ns": 5600
}
```

确认点：

- JSON 同时包含 `exec_ns` 和 `wall_exec_ns`
- `timing_source = "ktime"`
- `timing_source_wall = "rdtsc"`

从同一次 sample 的 `prog_run_wall_ns ~= 14.0 ms` 与 `wall_exec_ns ~= 5.6 us` 可反推出 effective repeat 大约是 `2500`，说明 adaptive repeat 已经把默认 `repeat=200` 放大到更长的测量窗口。

## 额外检查

我还尝试在当前 host 上走 recompile 路径：

```bash
sudo -n ./micro/build/runner/micro_exec run-kernel \
  --bpf-obj micro/programs/bitcount.bpf.o \
  --io-mode staged \
  --input-size 2056 \
  --repeat 200 \
  --recompile-all \
  --recompile-v5
```

当前内核对 `BPF_PROG_JIT_RECOMPILE` 返回 `EINVAL`，因此无法在这台机器上做一次“recompile 成功后 warmup 已执行”的 live 证明；但相关代码已编译通过，且 warmup 仅在 `recompile.applied == true` 时启用，不会污染 stock path 或 recompile-failed path。

## 结论

本次修复已经完成以下目标：

- kernel runner 结果中同时保留 `ktime` 与外层 `rdtsc` 两个时间源
- recompile 成功后增加 in-process warmup
- tiny program 默认启用 adaptive repeat，拉长 `ktime` 测量窗口
