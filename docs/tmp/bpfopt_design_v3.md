# bpfopt-suite 设计文档 v3

> 本文档自包含，是 bpfopt-suite v3 的权威设计。实现和其它文档必须与这里保持一致。

## 1. Overview

bpfopt-suite v3 的稳定边界是：

- `bpfopt`：standalone pure bytecode CLI，只做 `struct bpf_insn[]` 变换；一次 invocation 只跑一个 `--pass <name>`。
- `bpfprof`：standalone profiling CLI，负责 PMU/per-site profile。
- `bpfrejit-daemon`：runner socket + JSON 边界，负责 live discovery、map invalidation、runner 提供 pass list 的 per-pass orchestration、minimal fd-array 构造、每个 pass 后的 `BPF_PROG_REJIT(log_level=2)`。
- `bpfget`：daemon-owned library，只做 live program snapshot 和 target probing。
- `kernel-sys`：唯一 BPF syscall 边界。

`bpfverify`、`bpfrejit` crate 和 daemon thin dry-run module 均已删除。daemon 不调用 `BPF_PROG_LOAD`，不重建 `LoadAttr`，不传 `func_info` / `line_info` / `attach_btf_obj_fd`。所有 program metadata 由 kernel 在 `BPF_PROG_REJIT` 内从原 live `prog->aux` 复用；daemon 只提交新 bytecode、从 `prog_info.used_maps` 打开的 map fd，以及 kinsn module call 所需的 BTF module fd。

工具列表：

| 组件 | 归属 | 职责 | 依赖内核？ |
|------|------|------|:---:|
| `bpfopt` | standalone CLI | BPF 字节码单 pass 优化器，stdin/stdout 传 raw bytecode | 否 |
| `bpfprof` | standalone CLI | 采集 PMU/per-site profile | 是 |
| `bpfget` | daemon-owned lib | 读取原始 bytecode、prog info、map metadata、target kinsn capability | 是 |
| `bpfrejit-daemon` | standalone daemon | runner socket、watch、map invalidation、per-pass ReJIT | 是 |
| `kernel-sys` | shared lib | libbpf/libbpf-sys wrappers 和 fork syscall wrappers | 是 |

典型 runner path：

```bash
printf '{"cmd":"optimize","prog_id":123,"enabled_passes":["wide_mem"]}\n' | socat - /var/run/bpfrejit.sock
```

runner 是 benchmark pass policy 的配置中心。daemon 不维护默认 pass list；`optimize` 请求必须显式提供非空 `enabled_passes`，daemon 按 runner 提供的顺序逐个执行。当前 runner x86_64 policy 是：

```text
wide_mem, rotate, cond_select, extract, endian_fusion, map_inline,
const_prop, dce, bounds_check_merge, skb_load_bytes_spec, bulk_memory,
prefetch
```

离线 `bpfopt` path：

```bash
bpfopt --pass wide-mem --report wide.json < in.bin > out.bin
bpfopt --pass const-prop --verifier-states states.json < in.bin > out.bin
bpfopt list-passes
```

## 2. Core Principles

### 2.1 Per-Pass ReJIT Is the Acceptance Path

`optimize` 请求的主路径是：

1. runner 发 socket JSON。
2. daemon 用 `bpfget` snapshot live program，并立即把原始 bytecode 中的 map references canonicalize 为 `BPF_PSEUDO_MAP_IDX(_VALUE)`。
3. daemon 写 `prog.bin`、`info.json`、可选 `map-values.json`、可选 `target.json` side files。
4. daemon 从 `target.json` 打开非 vmlinux kinsn 的 BTF module fd，从 `prog_info.map_ids` 打开 map fd，构造 in-memory `fd_array`。
5. 对 runner 请求中的 `enabled_passes` 逐个执行：
   - fork+exec `bpfopt --pass <name>`，stdin/stdout 传 raw `struct bpf_insn[]`。
   - daemon 立即调用 `kernel_sys::prog_rejit()`，传当前 pass 输出、包含所需 BTF module fd 和 map fd 的 fd_array、large verifier log buffer。
   - kernel 在 `BPF_PROG_REJIT` 内从 live `prog->aux` 复用 program metadata，re-verify + re-JIT + image swap。
   - daemon 解析本次 ReJIT `log_level=2` verifier log，写 `verifier-states.json` 供后续需要 states 的 pass 使用。

没有 final aggregate ReJIT。每个 pass 成功后就已经 commit 到 live program；任一 pass 失败时，该 program 停在前 K 个成功 pass 的 partial 优化状态，并返回 `failed_pass` 和 `committed_passes_before_failure`。单个 program 失败不影响其它 program 的 worker。

主路径没有 `BPF_PROG_LOAD` dry-run、没有 `LoadAttr` rebuild、没有 verifier dry-run artifact、没有 daemon-side rollback。ReJIT errno/verifier log 直接作为错误和 failure artifact 暴露，不降级、不跳过、不过滤。

`BPF_PROG_REJIT` 是同步 syscall，daemon 不加 timeout 或 subprocess fallback；如果 kernel verifier hang，daemon 会被阻塞。这是当前接受的限制，目的是避免用复杂 watchdog 隐藏真实 kernel-side defect。

### 2.2 ReJIT Metadata Ownership

1. **零 reconstruction**：daemon 不从字节码反推 map/BTF/attach context，不重建 relocation，不拼 `LoadAttr`。
2. **只传 minimal fd_array**：daemon 对 `target.json` 中 `call_offset > 0` 的 kinsn BTF module ID 逐个 `BPF_BTF_GET_FD_BY_ID`，并对 `prog_info.used_maps` / `map_ids` 逐个 `BPF_MAP_GET_FD_BY_ID`。fd_array 只包含这些 BTF module fd 和 map fd，不写 `fd_array.json` / `map_fds.json`。
3. **不传 BTF metadata**：daemon 不传 `func_info`、`line_info`、`attach_btf_obj_fd` 给任何 syscall。`ProgramSnapshot` 不保存这些 bytes，不做 BTF normalize/replay。
4. **snapshot-time map canonicalization**：daemon 只在 snapshot 后做一次 map pseudo 归一化。`PSEUDO_MAP_FD` / `PSEUDO_MAP_VALUE` 根据原始 bytecode first-seen loader fd 顺序映射到 `prog_info.map_ids` index；IDX forms 在可获得 loader fd_array 时重新校准，否则按 map_ids 顺序校验保留。后续 per-pass ReJIT 不再做 fd rewrite。
5. **states 来自真实 ReJIT**：`map_inline` / `const_prop` 的 verifier states 只能来自前一个成功的 per-pass `BPF_PROG_REJIT(log_level=2)` log parser；没有 placeholder、空 states 或 heuristic fallback。

### 2.3 Runner 边界不变

`runner/libs/`、`corpus/`、`e2e/`、`micro/` 继续走 daemon socket + JSON。v3 migration 期间 runner Python 只允许 bug fix 和 stale test data 更新，不能改成直接调用 kernel-facing CLI。

## 3. Components

### 3.1 bpfopt

`bpfopt` 是 pure bytecode CLI。它不直接调用 BPF syscall，不链接 daemon crate，也不依赖 `bpfrejit-daemon`。

- stdin/stdout：raw binary `struct bpf_insn[]`，每条 8 字节。
- 必须显式传 `--pass <name>`；一次只跑一个 pass。
- 不提供 default pass pipeline，不接受 `--enabled-passes` 或 pass list。
- side-input/output：`--target`、`--profile`、`--verifier-states`、`--map-values`、`--report` 都走文件。
- `const_prop` 和 `map_inline` 需要真实 verifier-state side-input；离线 CLI 调用必须显式提供 `--verifier-states`。
- `branch_flip` 必须显式 opt-in 并提供真实 PMU profile。

常见命令：

```bash
bpfopt list-passes
bpfopt --pass wide-mem --report report.json < in.bin > out.bin
bpfopt --pass map-inline --verifier-states states.json --map-values map-values.json --map-ids 1,2 < in.bin > out.bin
bpfopt --pass branch-flip --profile profile.json < in.bin > out.bin
```

### 3.2 bpfprof

`bpfprof` 是 standalone CLI。daemon 只管理 `profile-start`/`profile-stop` lifecycle，不在进程内做 PMU profiling。

`branch_flip` 需要 `bpfprof --per-site` 的真实 per-site PGO 数据。每个 candidate site 必须有 `branch_count`、`branch_misses`、`miss_rate`、`taken`、`not_taken`；缺失数据直接 exit 1。

### 3.3 bpfget

`bpfget` 是 daemon-owned library。职责限于 snapshot live BPF program：

- `BPF_PROG_GET_ORIGINAL` 读取原始 bytecode。
- `BPF_OBJ_GET_INFO_BY_FD` 读取 `prog_info` 和 `map_ids`。
- `BPF_MAP_GET_FD_BY_ID` 打开 used maps 并读取 map metadata/value snapshot。
- target probing 为 `bpfopt --target` 生成 kinsn capability JSON。

`ProgramSnapshot` 不包含 BTF `func_info` / `line_info` bytes，不做 BTF normalize，不做 map relocation 反向解析，不做 resolved kernel pointer rewrite。

### 3.4 bpfrejit-daemon

daemon 是事件源 + runner socket boundary + kernel syscall orchestrator。

职责：

1. watch 新 BPF 程序加载。
2. 检测 map invalidation。
3. 维护 runner socket + JSON protocol。
4. 管理外部 `bpfprof` lifecycle。
5. 对 `optimize` 请求执行 snapshot -> per-pass `bpfopt` CLI -> per-pass `BPF_PROG_REJIT`。
6. 将每次成功 ReJIT 的 verifier log 解析为 register states，作为后续 pass side-input。
7. 对 `optimize-batch` / invalidation reoptimize 使用 per-program worker pool；默认 worker 数为 `min(num_cpus, 16)`，小 VM 中减半。

不做的事：

- 不维护 `PassManager`。
- 不链接或调用 bpfopt library。
- 不在进程内做 bytecode transform。
- 不调用 `BPF_PROG_LOAD`。
- 不重建 `LoadAttr`。
- 不做 thin dry-run。
- 不传或 normalize/replay BTF func_info/line_info。
- 不做 per-pass pseudo-map fd rewrite；snapshot 后只 canonicalize 一次为 map-index form。
- 不传无关 BTF fd；只把当前 target kinsn call 实际需要的 BTF module fd 塞进 ReJIT fd_array。

### 3.5 kernel-sys

`kernel-sys` 是唯一 BPF syscall 边界。

- 标准 BPF 命令优先使用 `libbpf-rs` / `libbpf-sys`。
- fork-only 命令 `BPF_PROG_REJIT`、`BPF_PROG_GET_ORIGINAL` 在 `kernel-sys` 内用 `libc::syscall` 包装。
- `prog_rejit()` 支持 `log_level=2 | BPF_LOG_STATS` verifier log，并在 `ENOSPC` 时把 log buffer 扩到 256 MiB 上限后重试。
- `verifier_states_from_log()` 把 ReJIT verifier log 转为 `verifier-states.json` ABI。
- `bpfopt` 可以依赖 `kernel-sys` 的 pure data APIs，如 `bpf_insn` 类型、opcode 常量和 prog type enum，但不能调用 syscall。
- `bpfprof`、`bpfrejit-daemon`、`bpfget` 只能通过 `kernel-sys` 调 BPF syscall。

## 4. Data and Protocol

### 4.1 Socket JSON

daemon 保留 newline-delimited JSON socket。典型请求：

```json
{"cmd":"status"}
{"cmd":"optimize","prog_id":42,"enabled_passes":["wide_mem","rotate"]}
{"cmd":"optimize-batch","prog_ids":[42,43,44],"enabled_passes":["wide_mem","rotate"]}
```

`enabled_passes` 是必填非空列表。daemon 不维护默认 pass list，也不把缺失列表降级成内部默认；runner 传什么，daemon 就按该顺序执行什么。缺失或空列表必须返回错误 `no enabled_passes provided by runner`。daemon 不过滤/跳过任何 ReJIT program；失败自然进入结果。

### 4.2 bpfopt bytecode

stdin/stdout 是 raw binary `struct bpf_insn[]`，无 header、无 framing。文件 side-input 只存在于 `bpfopt` / `bpfprof` CLI 边界，不用于 daemon kernel-facing state 的跨进程协议。

### 4.3 fd_array

daemon 构造 in-memory `fd_array`：

- 如果新 bytecode 可能包含 module kinsn call，daemon 从 `target.json.kinsns[*].call_offset` 收集 `call_offset > 0` 的 BTF module IDs；`call_offset=0` 表示 vmlinux，不需要 fd。
- Kernel verifier 对 module kfunc/kinsn call 使用 `fd_array[CALL.off]`，而 `CALL.off=0` 保留给 vmlinux。
- map fd 按 `prog_info.used_maps` / `map_ids` 顺序打开，放在 fd_array 开头；canonical `PSEUDO_MAP_IDX` imm 直接索引这个 map fd 前缀。
- module BTF fd 放在 map fd 之后。daemon 会把写给 bpfopt 的 target.json module `call_offset` 平移到 map fd 前缀之后；如果没有 map 但存在 module BTF fd，则 `fd_array[0]` 放第一个 module BTF fd 的 duplicate placeholder。
- 没有 kinsn module BTF 且没有 map 时传空 fd_array。
- 不写 JSON，不传无关 fd，不做 BTF `func_info` / `line_info` replay。

## 5. Failure Semantics

- 所有 syscall、IO、parse、CLI 失败都 fail-fast。
- 不允许 fallback、warning-and-continue、空结果替代、隐藏错误。
- 单个 pass ReJIT errno 要保留 workdir，包含 pass name、pass input bytecode、pass output bytecode、verifier log、errno/error text。
- 单个 program 任一 pass 失败时，返回 partial result：前 K 个 pass 已 commit，`failed_pass` 标明失败 pass。
- 单个 program 失败不影响其它 program worker。
- `map_inline` / `const_prop` 缺 verifier states 时必须失败。
- `branch_flip` 缺真实 per-site PGO 时必须失败。

## 6. Implementation Layout

```text
bpfopt/
  Cargo.toml
  crates/bpfopt/         # pure bytecode optimizer lib + single-pass bin
  crates/bpfprof/        # profiling CLI
  crates/kernel-sys/     # only BPF syscall boundary + shared ABI/data helpers

daemon/
  Cargo.toml
  crates/bpfget/         # live program snapshot + target probing only
  src/commands.rs        # socket command orchestration + per-pass ReJIT
  src/server.rs          # socket server
  src/invalidation.rs    # map invalidation watch
```

Standalone CLI binary crates (`bpfopt`, `bpfprof`, `bpfrejit-daemon`) must not depend on each other at compile time. Runtime composition is through stdin/stdout and side-input files only.

## 7. Acceptance Checks

- daemon source and daemon-owned crates contain no `BPF_PROG_LOAD`, `prog_load_dryrun`, `LoadAttr`, `attach_btf_obj_fd`, `func_info`/`line_info` syscall replay, pseudo-map rewrite, or dry-run module.
- daemon ReJIT path only calls `kernel_sys::prog_rejit()` plus read-only discovery APIs such as `prog_get_original`, `obj_get_info_by_fd`, `prog_map_ids`, and `map_get_fd_by_id`.
- `bpfopt` requires `--pass <name>` for optimization, runs exactly one pass, and has no default/multi-pass optimize command.
- `cargo test --workspace --manifest-path daemon/Cargo.toml`
- `cargo test --workspace --manifest-path bpfopt/Cargo.toml`
- `make daemon-tests`
- `make check`
