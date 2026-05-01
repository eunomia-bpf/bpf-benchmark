# bpfopt-suite 设计文档 v3

> 本文档自包含，是 bpfopt-suite v3 的权威设计。实现和其它文档必须与这里保持一致。

## 1. Overview

bpfopt-suite v3 的稳定边界是：

- `bpfopt`：standalone pure bytecode CLI，只做 `struct bpf_insn[]` 变换。
- `bpfprof`：standalone profiling CLI，负责 PMU/per-site profile。
- `bpfrejit-daemon`：runner socket + JSON 边界，负责 live discovery、map invalidation、fd-array 构造、可选 `const_prop` verifier-state capture、最终 `BPF_PROG_REJIT`。
- `bpfget`：daemon-owned library，只做 live program snapshot。
- `kernel-sys`：唯一 BPF syscall 边界。

`bpfverify` 和 `bpfrejit` crate 已删除。daemon 主路径不做 `BPF_PROG_LOAD` dry-run；candidate 由内核在 `BPF_PROG_REJIT` 内走标准 verifier 路径。`const_prop` 是唯一需要 verifier states 的 opt-in 路径，daemon 只在显式请求 `const_prop` 时做 thin dry-run。

工具列表：

| 组件 | 归属 | 职责 | 依赖内核？ |
|------|------|------|:---:|
| `bpfopt` | standalone CLI | BPF 字节码优化器，stdin/stdout 传 raw bytecode | 否 |
| `bpfprof` | standalone CLI | 采集 PMU/per-site profile | 是 |
| `bpfget` | daemon-owned lib | 读取原始 bytecode、prog info、map metadata | 是 |
| `bpfrejit-daemon` | standalone daemon | runner socket、watch、map invalidation、fd-array、ReJIT | 是 |
| `kernel-sys` | shared lib | libbpf/libbpf-sys wrappers 和 fork syscall wrappers | 是 |

典型 runner path：

```bash
printf '{"cmd":"optimize","prog_id":123,"enabled_passes":["wide_mem","map_inline","dce"]}\n' | socat - /var/run/bpfrejit.sock
```

显式 `const_prop` path：

```bash
printf '{"cmd":"optimize","prog_id":123,"enabled_passes":["const_prop","dce"]}\n' | socat - /var/run/bpfrejit.sock
```

离线 `bpfopt` path：

```bash
bpfopt optimize --report report.json < prog.bin > opt.bin
bpfopt const-prop --verifier-states states.json < prog.bin > opt.bin
```

## 2. Core Principles

### 2.1 Daemon 主路径直接 ReJIT

`optimize` 请求的主路径是：

1. runner 发 socket JSON。
2. daemon 用 `bpfget` snapshot live program。
3. daemon 写 `prog.bin`、`info.json`、可选 `map-values.json`、可选 `target.json` side files。
4. daemon fork+exec `bpfopt optimize`，stdin/stdout 传 raw `struct bpf_insn[]`。
5. daemon 从 snapshot 的 `used_maps` 和 target kinsn BTF 信息构造 in-memory `fd_array`。
6. daemon 调 `kernel_sys::prog_rejit()`，内核在 `BPF_PROG_REJIT` 内 re-verify + re-JIT + image swap。

主路径没有 `BPF_PROG_LOAD` dry-run、没有 final verify artifact、没有 per-pass verify loop、没有 pass rollback。ReJIT 失败时 errno/verifier log 直接作为错误和 failure artifact 暴露，不降级、不跳过、不过滤。

### 2.2 三条 rollback 设计原则

1. **零 reconstruction**：daemon 不从字节码反推 map/BTF 上下文，不重建 relocation。`prog_info` 字段和 `used_maps` 顺序直接使用。
2. **不传 BTF func_info / line_info**：thin dry-run 使用 `func_info = None`、`line_info = None`；ProgramSnapshot 不保存这些 bytes；daemon 不做 BTF normalize/replay。
3. **`const_prop` 默认关**：default 11-pass `bpfopt optimize` 不包含 `const_prop`。只有显式 `enabled_passes` 包含 `const_prop` 时，daemon 才做 thin dry-run 生成 `verifier-states.json` 并传给 `bpfopt`。

### 2.3 Runner 边界不变

`runner/libs/`、`corpus/`、`e2e/`、`micro/` 继续走 daemon socket + JSON。v3 migration 期间 runner Python 只允许 bug fix 和 stale test data 更新，不能改成直接调用 kernel-facing CLI。

## 3. Components

### 3.1 bpfopt

`bpfopt` 是 pure bytecode CLI。它不直接调用 BPF syscall，不链接 daemon crate，也不依赖 `bpfrejit-daemon`。

- stdin/stdout：raw binary `struct bpf_insn[]`，每条 8 字节。
- side-input/output：`--target`、`--profile`、`--verifier-states`、`--map-values`、`--report` 都走文件。
- default `optimize` pass list 是 11 pass，不含 `const_prop` 和 Paper B `branch_flip`。
- `const_prop` 和 `branch_flip` 仍是生产 pass，但必须显式 opt-in 并提供真实 side-input。缺失 side-input 时 exit 1。

常见命令：

```bash
bpfopt list-passes
bpfopt optimize --passes wide_mem,map_inline,dce --report report.json < in.bin > out.bin
bpfopt branch-flip --profile profile.json < in.bin > out.bin
bpfopt const-prop --verifier-states verifier-states.json < in.bin > out.bin
```

### 3.2 bpfprof

`bpfprof` 是 standalone CLI。daemon 只管理 `profile-start`/`profile-stop` lifecycle，不在进程内做 PMU profiling。

`branch_flip` 需要 `bpfprof --per-site` 的真实 per-site PGO 数据。每个 candidate site 必须有 `branch_count`、`branch_misses`、`miss_rate`、`taken`、`not_taken`；缺失数据直接 exit 1。

### 3.3 bpfget

`bpfget` 是 daemon-owned library。职责限于 snapshot live BPF program：

- `BPF_PROG_GET_ORIGINAL` 读取原始 bytecode。
- `BPF_OBJ_GET_INFO_BY_FD` 读取 `prog_info`，包括 `map_ids`、prog type、attach fields、BTF ids 等。
- `BPF_MAP_GET_FD_BY_ID` 打开 used maps 并读取 map metadata/value snapshot。
- target probing 为 `bpfopt` 生成 kinsn capability JSON。

`ProgramSnapshot` 不包含 BTF `func_info` / `line_info` bytes，不做 BTF normalize，不做 map relocation 反向解析。

### 3.4 bpfrejit-daemon

daemon 是事件源 + runner socket boundary + kernel syscall orchestrator。

职责：

1. watch 新 BPF 程序加载。
2. 检测 map invalidation。
3. 维护 runner socket + JSON protocol。
4. 管理外部 `bpfprof` lifecycle。
5. 对 `optimize` 请求执行 snapshot -> `bpfopt` CLI -> direct `BPF_PROG_REJIT`。
6. 对显式 `const_prop` 请求执行 thin dry-run -> verifier states side-input -> `bpfopt` CLI。

不做的事：

- 不维护 `PassManager`。
- 不链接或调用 bpfopt library。
- 不在进程内做 bytecode transform。
- 不在主路径做 `BPF_PROG_LOAD` dry-run。
- 不做 per-pass verify/rollback。
- 不重建 BTF func_info/line_info normalize/replay。
- 不重建 multi-map relocation 反向解析。

### 3.5 Thin Dry-Run for const_prop

thin dry-run 是 `const_prop` 的 side-input 生成机制，不是 ReJIT 接受条件。

输入：

- snapshot 原始 bytecode。
- snapshot 的 `prog_info` 基础字段。
- daemon in-memory `fd_array`。
- `func_info = None`。
- `line_info = None`。
- `log_level = 2`。

输出：

- `verifier-states.json`，由 `kernel-sys` 的 verifier log parser 生成。

失败策略：

- dry-run syscall error、verifier reject、log parse failure、timeout 都直接让 request 失败。
- 不写空 states，不继续跑 `const_prop`，不降级为无 states 的 pass。

### 3.6 kernel-sys

`kernel-sys` 是唯一 BPF syscall 边界。

- 标准 BPF 命令优先使用 `libbpf-rs` / `libbpf-sys`。
- fork-only 命令 `BPF_PROG_REJIT`、`BPF_PROG_GET_ORIGINAL` 在 `kernel-sys` 内用 `libc::syscall` 包装。
- `bpfopt` 可以依赖 `kernel-sys` 的 pure data APIs，如 `bpf_insn` 类型、opcode 常量和 prog type enum，但不能调用 syscall。
- `bpfprof`、`bpfrejit-daemon`、`bpfget` 只能通过 `kernel-sys` 调 BPF syscall。

## 4. Data and Protocol

### 4.1 Socket JSON

daemon 保留 newline-delimited JSON socket。典型请求：

```json
{"cmd":"status"}
{"cmd":"optimize","prog_id":42,"enabled_passes":["map_inline","dce"]}
{"cmd":"optimize","prog_id":42,"enabled_passes":["const_prop","dce"]}
```

`enabled_passes` 必须非空。daemon 不过滤/跳过任何 ReJIT program；失败自然进入结果。

### 4.2 bpfopt bytecode

stdin/stdout 是 raw binary `struct bpf_insn[]`，无 header、无 framing。文件 side-input 只存在于 `bpfopt` / `bpfprof` CLI 边界，不用于 daemon kernel-facing state 的跨进程协议。

### 4.3 fd_array

daemon 构造 in-memory `fd_array`：

- map fd 按 `prog_info.used_maps` / `map_ids` 顺序打开并放入数组。
- kinsn BTF fd 按 `target.json` capability 顺序追加。
- 若没有 map fd 但存在 kinsn BTF fd，`fd_array[0]` 复制第一个 BTF fd，占住 kinsn call offset 的 vmlinux sentinel 位置；真实 kinsn offset 从 1 开始。

daemon 不读写 `fd_array.json` / `map_fds.json`。

## 5. Failure Semantics

- 所有 syscall、IO、parse、CLI 失败都 fail-fast。
- 不允许 fallback、warning-and-continue、空结果替代、隐藏错误。
- ReJIT errno 和 verifier log 要写入 failure artifact 并返回 socket error。
- `const_prop` 缺 verifier states 时必须失败。
- `branch_flip` 缺真实 per-site PGO 时必须失败。

## 6. Implementation Layout

```text
bpfopt/
  Cargo.toml
  crates/bpfopt/         # pure bytecode optimizer lib + bin
  crates/bpfprof/        # profiling CLI
  crates/kernel-sys/     # only BPF syscall boundary + shared ABI/data helpers

daemon/
  Cargo.toml
  crates/bpfget/         # live program snapshot only
  src/commands.rs        # socket command orchestration + direct ReJIT
  src/dry_run.rs         # const_prop-only thin dry-run
  src/server.rs          # socket server
  src/invalidation.rs    # map invalidation watch
```

Standalone CLI binary crates (`bpfopt`, `bpfprof`, `bpfrejit-daemon`) must not depend on each other at compile time. Runtime composition is through stdin/stdout and side-input files only.

## 7. Acceptance Checks

- daemon kernel-facing production Rust is <= 2,400 lines after rollback.
- daemon main optimize path does not call `BPF_PROG_LOAD`.
- `const_prop` is absent from default optimize pass lists and benchmark config.
- ProgramSnapshot contains no BTF func_info/line_info bytes.
- No `map_fds.json`, `fd_array.json`, `btf-info`, or `verifier-states-out` protocol remains.
- `cargo test --workspace --manifest-path daemon/Cargo.toml`
- `cargo test --workspace --manifest-path bpfopt/Cargo.toml`
- `make daemon-tests`
- `make check`
