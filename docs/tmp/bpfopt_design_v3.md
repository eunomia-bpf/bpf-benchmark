# bpfopt-suite 设计文档 v3

> 本文档自包含，不需要参考其他文件即可开始实现。

## 1. Overview

bpfopt-suite v3 经过 2026-05-01 架构 pivot 后分为两类边界：`bpfopt` / `bpfprof` 仍是 Unix 风格 CLI，daemon-owned `bpfget` / `bpfverify` / `bpfrejit` 是 in-process library。核心理念保持不变：**字节码变换属于 `bpfopt`，kernel syscall 属于 daemon/kernel-sys 边界，不在 `bpfopt` 内部。**

工具列表：

| 组件 | 归属 | 职责 | 依赖内核？ |
|------|------|------|:---:|
| **bpfopt** | standalone CLI | BPF 字节码优化器，每个 pass 是子命令 | 否 |
| **bpfprof** | standalone CLI | 采集 BPF 程序运行时 profile | 是 |
| **bpfget** | daemon-owned lib | 读取内核中 BPF 程序的原始字节码、metadata、map fd、BTF records | 是 |
| **bpfverify** | daemon-owned lib | BPF_PROG_LOAD dry-run 验证和 verifier-state 捕获 | 是 |
| **bpfrejit** | daemon-owned lib | 提交字节码给内核 BPF_PROG_REJIT | 是 |
| **bpfrejit-daemon** | standalone daemon | watch、map invalidation、runner socket、in-process kernel syscall orchestration | 是 |

典型用法：

```bash
# runner/daemon path: runner 发 socket JSON，daemon 进程内做 bpfget/bpfverify/bpfrejit，
# 中间只 fork+exec bpfopt 做 pure bytecode transform
printf '{"cmd":"optimize","prog_id":123,"enabled_passes":["wide_mem","const_prop"]}\n' | socat - /var/run/bpfrejit.sock

# profile 仍是独立 CLI
bpfprof --prog-id 123 --per-site --duration 500ms --output profile.json

# 离线优化报告
bpfopt optimize --report report.json < prog.bin > opt.bin
```

> Pivot note: 本文档中早期的 “all tools are CLI / socket-to-CLI” 描述已由 2026-05-01 pivot 覆盖。`bpfget`、`bpfverify`、`bpfrejit` 不再维护 standalone CLI 或跨进程 JSON 协议；`bpfopt` 与 `bpfprof` 保持 CLI。

## 2. 工具详细设计

### 2.1 bpfopt

纯字节码优化器。**零内核依赖**。输入字节码，输出字节码。

#### 子命令

**Per-pass 子命令**（每个 pass 都是顶层子命令）：

```bash
bpfopt wide-mem    [FLAGS] < in.bin > out.bin
bpfopt rotate      [FLAGS] < in.bin > out.bin
bpfopt const-prop  [FLAGS] < in.bin > out.bin
bpfopt cond-select [FLAGS] < in.bin > out.bin
bpfopt extract     [FLAGS] < in.bin > out.bin
bpfopt endian      [FLAGS] < in.bin > out.bin
bpfopt branch-flip --profile profile.json [FLAGS] < in.bin > out.bin   # Paper B PGO
bpfopt dce         [FLAGS] < in.bin > out.bin
bpfopt map-inline  [FLAGS] < in.bin > out.bin
bpfopt bulk-memory [FLAGS] < in.bin > out.bin
bpfopt bounds-check-merge [FLAGS] < in.bin > out.bin
bpfopt skb-load-bytes     [FLAGS] < in.bin > out.bin
```

**批量子命令**（convenience，等价于串联多个 pass）：

```bash
bpfopt optimize --passes wide-mem,rotate,const-prop < in.bin > out.bin
```

**工具子命令**：

```bash
bpfopt list-passes               # 列出所有可用 pass
bpfopt list-passes --json        # JSON 格式
```

#### 通用 flags

| Flag | 说明 | 默认 |
|------|------|------|
| `--input FILE` | 输入文件（不指定则 stdin） | stdin |
| `--output FILE` | 输出文件（不指定则 stdout） | stdout |
| `--report FILE` | 输出 pass 报告 JSON | 不输出 |
| `--platform ARCH` | 目标平台：x86_64, aarch64 | 自动检测 |
| `--kinsns LIST` | 可用 kinsn 列表（逗号分隔） | 无 |
| `--target FILE` | 目标描述 JSON（替代 --platform + --kinsns） | 无 |
| `--profile FILE` | PGO profile JSON 输入 | 无 |
| `--verifier-states FILE` | Verifier states JSON 输入 | 无 |
| `--map-values FILE` | Map values JSON 输入 | 无 |
| `--map-ids LIST` | Map IDs（逗号分隔） | 无 |

#### stdin/stdout 约定

- **stdin/stdout 传输 raw binary 字节码**：`struct bpf_insn` 数组（每条 8 字节，little-endian）
- 无 framing、无 header，纯二进制流
- 管道串联时每个 pass 读 stdin、写 stdout，字节码自然流过
- side-input/side-output 通过文件传递，不混入 stdin/stdout

#### 错误处理

- pass 无可优化 site：正常退出（exit 0），原样透传字节码，report 中 `changed=false`
- 缺少必需 side-input（如 branch-flip 需要 --profile）：exit 1，stderr 报错
- 字节码格式错误：exit 1，stderr 报错
- 不得静默失败

### 2.2 bpfverify（daemon-owned lib）

daemon 进程内调用内核 BPF_PROG_LOAD dry-run 验证字节码。它不是 standalone CLI；调用方传入 candidate bytecode、prog type、attach type、BTF records、map fd 绑定和可选 kinsn fd_array。

#### 行为

- 验证通过 → 返回 `VerifyReport { ok: true, verifier_log, states }`
- 验证失败 → 返回 error，daemon 记录 failure artifact，socket 请求失败
- verifier states 在同进程由 `bpfverify` library 解析 verifier log 后传给 daemon；daemon 只在调用 `bpfopt const-prop --verifier-states FILE` 时写 `bpfopt` side-input 文件
- map fd 和 kinsn fd_array 是 daemon 进程内 fd，不走 JSON reopen 协议

#### 必需输入

| 字段 | 说明 |
|------|------|
| `insns` | candidate `struct bpf_insn[]` |
| `prog_type` | BPF 程序类型（xdp, socket_filter, kprobe, ...） |
| `map_fds` | daemon 进程持有的 map fd |

#### 可选输入

| 字段 | 说明 |
|------|------|
| `expected_attach_type` | attach 类型 |
| `attach_btf_id` / `attach_prog_fd` | tracing/freplace 等 attach metadata |
| `btf_fd` / `func_info` / `line_info` | 原程序 BTF metadata，同进程复用 |
| `fd_array` | kinsn BTF fd_array |
| `log_level` | verifier log level（0-2），取 states 时使用 2 |

### 2.3 bpfprof

采集 BPF 程序运行时 profile 数据。

```bash
# 采集单个程序的 profile
bpfprof --prog-id 123 --per-site --duration 500ms --output profile.json

# 采集所有活跃程序
bpfprof --all --per-site --duration 1s --output-dir profiles/
```

#### 采集内容

- `bpf_enable_stats` → per-program run_cnt, run_time_ns
- `perf_event_open` + `bpf_get_branch_snapshot()` sidecar → hardware LBR branch records
- `BPF_OBJ_GET_INFO_BY_FD` JIT metadata + JIT image disassembly → native IP 映射到 BPF source PC
- 计算 delta（窗口前后差值），并输出 per-site branch counters

#### 输出

输出 `profile.json`，schema 见 §3.4。

### 2.4 bpfget（daemon-owned lib）

daemon 进程内从内核读取 BPF 程序信息，生成 `ProgramSnapshot`。它不是 standalone CLI；不再输出 program-info / map-fd JSON 协议给其它进程。

#### 关键功能

- `BPF_PROG_GET_ORIGINAL` → 原始字节码
- `BPF_OBJ_GET_INFO_BY_FD` → prog_name, prog_type, map_ids 等
- `BPF_MAP_GET_FD_BY_ID` → daemon 进程内 map fd，用于 relocation、dry-run verify、final ReJIT
- `BPF_PROG_GET_NEXT_ID` → 枚举
- BTF func_info / line_info 在同进程内保存为 bytes；调用 `bpfopt` 时仅作为 `bpfopt` side-input/output 文件存在，验证和 ReJIT 继续使用内存中的 records
- map value snapshot 在 daemon 内读取后写给 `bpfopt map-inline --map-values FILE`

### 2.5 bpfrejit（daemon-owned lib）

daemon 进程内提交字节码给内核。它不是 standalone CLI；不再从文件/stdin 读取候选字节码。

#### 行为

- 调用 `BPF_PROG_REJIT(prog_fd, new_insns, new_insn_cnt, fd_array)`
- `fd_array` 使用 daemon 进程内持有的 BTF fd 和 map fd，ABI 仍是 fork kernel 的 fd-array ABI
- 成功 → 返回 summary，daemon 写 `bpfrejit_summary.json` artifact
- 内核 verify 失败 → 返回 errno/log error，daemon socket 请求失败
- 预验证由 in-process `bpfverify` 负责；final syscall 仍走 kernel re-verify

### 2.6 bpfrejit-daemon（可选）

常驻 watch 进程。**不维护 PassManager，不在进程内变换 bytecode，不做 in-process profiling。** live BPF discovery、dry-run verification、verifier-state capture、final ReJIT 归 daemon-owned libraries；bytecode transform 只通过 external `bpfopt` CLI。

```bash
bpfrejit-daemon serve --socket /var/run/bpfrejit.sock
```

#### 职责

1. watch 新 BPF 程序加载（轮询 `BPF_PROG_GET_NEXT_ID`）
2. map invalidation 检测（轮询 map values，对比之前 inline 的值）
3. 维护 session 生命周期
4. 作为 runner socket + JSON 协议的稳定边界
5. 对 `optimize` 请求：进程内 snapshot → fork+exec `bpfopt` → 进程内 verify/rejit
6. 对 `profile-start`/`profile-stop` 请求：管理外部 `bpfprof` CLI 生命周期

#### 不做的事

- 不在 daemon 进程内跑 pass pipeline
- 不链接或调用 bpfopt library
- 不在 daemon 进程内做 profiling
- 不做字节码变换
- 不维护 PassManager

daemon 是事件源 + runner socket boundary + kernel syscall orchestrator。为了保持 runner Python 在 v3 迁移期不变，`profile-start`/`profile-stop` 只启动和停止 `bpfprof --per-site` CLI；`optimize` 在 daemon 内部持有 prog/map/BTF fd，消除 `bpfget`/`bpfverify`/`bpfrejit` 的 fork+exec 和 JSON/file 协议。禁止的是 daemon 内部 profiler、内部 PassManager 和内部 bytecode transform。

---

## 3. 数据格式

### 3.1 字节码（binary）

`struct bpf_insn` 数组，每条 8 字节，little-endian：

```
offset  size  field
0       1     opcode (u8)
1       1     dst_reg:4 | src_reg:4 (u8, dst in low nibble)
2       2     off (i16, little-endian)
4       4     imm (i32, little-endian)
```

文件大小必须是 8 的倍数。LD_IMM64 占两条指令（16 字节）。

这就是 stdin/stdout 管道中的格式。没有 header、没有 framing。

### 3.2 target.json

描述目标平台能力。bpfopt 的 `--target` 输入。

```json
{
  "arch": "x86_64",
  "features": ["cmov", "movbe", "bmi1", "bmi2", "rorx"],
  "kinsns": {
    "bpf_rotate64": { "btf_func_id": 12345 },
    "bpf_select64": { "btf_func_id": 12346 },
    "bpf_extract64": { "btf_func_id": 12347 },
    "bpf_endian_load64": { "btf_func_id": 12348 },
    "bpf_bulk_memcpy": { "btf_func_id": 12349 },
    "bpf_bulk_memset": { "btf_func_id": 12350 }
  }
}
```

- `arch`：`x86_64` 或 `aarch64`
- `features`：CPU 特性列表
- `kinsns`：已加载的 kinsn 模块导出的函数。`btf_func_id` 是 kinsn 编码需要的 BTF ID
- 缺少某 pass 需要的 kinsn 时，该 pass 报错或跳过（取决于 pass 是否要求 kinsn）

### 3.3 map-values.json

Map 值快照。bpfopt map-inline 的输入。

```json
{
  "maps": [
    {
      "map_id": 123,
      "map_type": "array",
      "key_size": 4,
      "value_size": 8,
      "max_entries": 1024,
      "entries": [
        { "key": "01000000", "value": "2a00000000000000" },
        { "key": "02000000", "value": "0000000000000000" }
      ]
    }
  ]
}
```

- key/value 是 hex 编码的 raw bytes
- 只包含程序实际 lookup 的 key，不是全量 dump
- `value` 为 null 表示 lookup miss

### 3.4 profile.json

PGO profile 数据。bpfprof 输出，bpfopt branch-flip 等 pass 消费。

```json
{
  "prog_id": 123,
  "duration_ms": 500,
  "run_cnt_delta": 15000,
  "run_time_ns_delta": 4500000,
  "branch_miss_rate": 0.032,
  "branch_misses": 480,
  "branch_instructions": 15000,
  "per_site": {
    "42": {
      "branch_count": 15000,
      "branch_misses": 480,
      "miss_rate": 0.032,
      "taken": 12000,
      "not_taken": 3000
    },
    "67": {
      "branch_count": 15000,
      "branch_misses": 32,
      "miss_rate": 0.00213,
      "taken": 200,
      "not_taken": 14800
    }
  }
}
```

- `per_site` 的 key 是 BPF 指令 PC（十进制字符串）
- `per_site` 中每个字段都是必填；缺 program/site profile 数据时 `bpfprof` 或消费方必须 exit 1
- `branch_miss_rate` 是程序级的 PMU 数据；`per_site.*.miss_rate` 是 site 级 PMU 数据

### 3.5 verifier-states.json

Verifier 解析结果。bpfverify 输出，bpfopt const-prop 消费。

```json
{
  "insns": [
    {
      "pc": 5,
      "regs": {
        "r1": { "type": "scalar", "const_val": 42 },
        "r2": { "type": "scalar", "min": 0, "max": 255, "tnum": "0x0/0xff" }
      }
    },
    {
      "pc": 12,
      "regs": {
        "r0": { "type": "scalar", "const_val": 0 }
      }
    }
  ]
}
```

- 只包含有精确常量或 range 信息的 PC
- `const_val` 存在时表示该寄存器在该 PC 是确定常量

### 3.6 pass-report.json

每个 pass 执行后的报告。bpfopt `--report` 输出。

```json
{
  "pass": "wide_mem",
  "changed": true,
  "sites_applied": 7,
  "insn_count_before": 150,
  "insn_count_after": 143,
  "insn_delta": -7
}
```

---

## 4. 管道协议

### 4.1 基本规则

1. **`bpfopt` 字节码走 stdin/stdout**，二进制流，无 framing
2. **`bpfopt` side-input/output 走文件**（`--profile`, `--target`, `--verifier-states`, `--map-values`, `--report` 等 flag）
3. **daemon-owned kernel data 不走跨进程协议**：prog info、map ids、map fds、BTF records、fd_array 都在 daemon 进程内传递
4. **`bpfprof` profile 仍走 CLI 文件输出**
5. pass 无可优化 site → exit 0，原样透传字节码

### 4.2 bpfopt 管道示例

```bash
# 三个 pass 管道
bpfopt wide-mem < prog.bin | bpfopt rotate --target target.json | bpfopt const-prop --verifier-states states.json > opt.bin

# 带 report 的管道（report 写文件，不影响 stdout 管道）
bpfopt wide-mem --report r1.json < prog.bin | bpfopt rotate --report r2.json > opt.bin
```

### 4.3 daemon optimize flow

runner 仍通过 socket 发 JSON；daemon 内部做 kernel syscall orchestration：

```text
runner socket JSON
  → daemon bpfget::snapshot_program(prog_id)
  → daemon writes bpfopt side files only when bpfopt needs them
  → daemon fork+execs bpfopt pass/optimize
  → daemon bpfverify::verify_pass(candidate, in-memory metadata)
  → daemon bpfrejit::rejit_program(prog_id, candidate, in-memory fd_array)
```

`bpfopt` 是唯一保留的 bytecode transform subprocess。`bpfget`、`bpfverify`、`bpfrejit` 不再作为 subprocess 存在。

### 4.4 verifier-in-the-loop

`const-prop` 需要 verifier states 时，daemon 调用 in-process `bpfverify::verifier_states()`，再把结果写成 `bpfopt const-prop --verifier-states FILE` 的 side-input。缺失 verifier states、dry-run 失败或 parse 失败都直接返回 error，不允许空 states fallback。

---

## 5. Pass 清单

从当前 daemon 代码提取的全部 pass，每个对应 bpfopt 的一个子命令：

| 子命令 | pass 名 | 说明 | 需要 kinsn？ | 需要 side-input？ |
|--------|---------|------|:---:|------|
| `wide-mem` | WideMemPass | byte load+shift+or → wide load | 否 | 无 |
| `rotate` | RotatePass | shift+or → bpf_rotate64 kinsn | 是 | --target |
| `cond-select` | CondSelectPass | branch+mov → bpf_select64 kinsn | 是 | --target |
| `extract` | ExtractPass | shift+and → bpf_extract64 kinsn | 是 | --target |
| `endian` | EndianFusionPass | load+bswap → endian kinsn (MOVBE) | 可选 | --target |
| `branch-flip` | BranchFlipPass | if/else body 重排（Paper B / PGO-gated） | 否 | --profile |
| `const-prop` | ConstPropPass | verifier 常量折叠 | 否 | --verifier-states |
| `dce` | DcePass | 死代码消除 | 否 | 无 |
| `map-inline` | MapInlinePass | map lookup → 常量内联 | 否 | --map-values, --map-ids |
| `bulk-memory` | BulkMemoryPass | 大块 memcpy/memset → kinsn | 是 | --target |
| `bounds-check-merge` | BoundsCheckMergePass | 合并 bounds check guard | 否 | 无 |
| `skb-load-bytes` | SkbLoadBytesSpecPass | skb_load_bytes → direct packet access | 否 | 无 |

`branch-flip` 是 Paper B 的 profile/info-guided speculative runtime optimization pass，不属于当前默认优化策略。P88 后它要求真实 `bpfprof --per-site` profile：程序级 `branch_miss_rate` 和每个候选 site 的 `branch_count`/`branch_misses`/`miss_rate`/direction 数据缺一不可；缺数据直接 exit 1，不允许 placeholder 或 heuristic fallback。

**默认 pass 顺序**（`bpfopt optimize` 不指定 `--passes` 时）：
map-inline → const-prop → dce → skb-load-bytes → bounds-check-merge → wide-mem → bulk-memory → rotate → cond-select → extract → endian

---

## 6. 仓库结构

```
bpf-benchmark/
├── bpfopt/
│   ├── Cargo.toml                 # workspace: kernel-sys, bpfopt, bpfprof
│   └── crates/
│       ├── kernel-sys/            # 唯一 BPF syscall boundary
│       ├── bpfopt/                # standalone pure-bytecode CLI + lib
│       └── bpfprof/               # standalone PMU/profile CLI
│
└── daemon/
    ├── Cargo.toml                 # workspace: daemon + daemon-owned kernel libs
    ├── crates/
    │   ├── bpfget/                # live ProgramSnapshot library
    │   ├── bpfverify/             # dry-run verify + verifier states library
    │   └── bpfrejit/              # BPF_PROG_REJIT library
    └── src/
        ├── commands.rs            # runner socket command orchestration
        ├── server.rs              # socket server
        ├── invalidation.rs        # map invalidation
        └── bpf.rs                 # daemon helpers using kernel-sys/libbpf
```

### Crate 依赖关系

```
bpfopt crate（pure bytecode transform）
  ↑
  └── bpfopt CLI

kernel-sys（唯一 BPF syscall boundary）
  ↑
  ├── bpfprof CLI
  ├── bpfrejit-daemon
  ├── daemon/crates/bpfget
  ├── daemon/crates/bpfverify
  └── daemon/crates/bpfrejit
```

关键：**`bpfopt` 不直接调用 BPF syscall**。它可以依赖 `kernel-sys` 的纯数据 API（`bpf_insn` 类型、opcode 常量、prog type enum），但任何 kernel-touching syscall 都只能在 `kernel-sys` 内实现并由 daemon-owned libs 或 `bpfprof` 调用。

---

## 7. Pivot 代码映射

| 原归属 | 新归属 | 改动 |
|--------|--------|------|
| `bpfopt/crates/bpfget` | `daemon/crates/bpfget` | CLI main 改为 `ProgramSnapshot` library；prog/map/BTF metadata 进程内返回 |
| `bpfopt/crates/bpfverify` | `daemon/crates/bpfverify` | CLI main 改为 `VerifyRequest`/`VerifyReport` library；verifier states 进程内捕获 |
| `bpfopt/crates/bpfrejit` | `daemon/crates/bpfrejit` | CLI main 改为 `rejit_program()` library；fd_array 由 daemon 直接传入 syscall |
| `daemon/src/commands.rs` | 保留 | 删除三条 fork+exec 路径；只 fork+exec `bpfopt` 和 `bpfprof` |
| `bpfopt/crates/bpfopt` | 保留 | pure bytecode transformer；仍用 stdin/stdout 和 side files |
| `bpfopt/crates/bpfprof` | 保留 | PMU/profile CLI；daemon 只管理其 lifecycle |

---

## 8. Daemon 集成方案

### 保留的功能

1. **Watch 新程序加载**：轮询 `BPF_PROG_GET_NEXT_ID`，发现新 prog_id 后可触发 optimize 请求。
2. **Map invalidation 检测**：读取 `bpfopt map-inline --report` 产出的 invalidation hints，轮询 map values，检测变化时触发 re-optimize。
3. **Unix socket 服务**：接受 benchmark runner 的 `optimize` / `profile-start` / `profile-stop` / `discover` 请求。
4. **In-process kernel syscall orchestration**：snapshot、map relocation、dry-run verify、verifier-state capture、final ReJIT 都在 daemon 进程内完成。

### 不保留的功能

- ~~PassManager~~
- ~~所有 pass 代码~~
- ~~profiler 线程~~
- ~~`bpfget`/`bpfverify`/`bpfrejit` subprocess~~
- ~~prog/map/BTF/fd_array JSON protocol between kernel-facing tools~~
- ~~replay report protocol for bpfverify subprocess~~

### 与 benchmark runner 的集成

当前 benchmark runner 通过 Unix socket 给 daemon 发 JSON 请求，并且该边界保持不变：

```python
send_json(sock, {"cmd": "optimize", "prog_id": 123, "enabled_passes": ["map_inline", "const_prop", "dce"]})
```

daemon 收到请求后：

1. `bpfget::snapshot_program()` 获取 bytecode、prog info、map ids、map fds、BTF records。
2. daemon 写 `bpfopt` 需要的 `target.json`、`map-values.json`、`verifier-states.json` 等 side-input。
3. daemon fork+exec `bpfopt` 做 pure bytecode transform。
4. `bpfverify::verify_pass()` 用 in-memory metadata dry-run candidate。
5. `bpfrejit::rejit_program()` 用 in-memory fd_array 调 `BPF_PROG_REJIT`。

---

## 9. 典型使用场景

### 场景 1：daemon runner optimize

```bash
printf '{"cmd":"optimize","prog_id":123,"enabled_passes":["wide_mem","const_prop"]}\n' | socat - /var/run/bpfrejit.sock
```

### 场景 2：带 PGO profile

```bash
bpfprof --prog-id 123 --per-site --duration 1s --output profile.json
printf '{"cmd":"optimize","prog_id":123,"enabled_passes":["branch_flip"]}\n' | socat - /var/run/bpfrejit.sock
```

### 场景 3：离线 corpus 优化报告（不需要内核）

```bash
for f in corpus/*.bin; do
  bpfopt optimize --report "$f.report.json" < "$f" > "$f.opt.bin"
done
```

---

## 10. 实现优先级

### Phase 1：核心 bytecode CLI

1. **bpfopt CLI**：实现 `optimize` 子命令、pass 子命令、stdin/stdout binary 读写。
2. **kernel-sys**：集中 BPF syscall wrappers 和 libbpf-rs/libbpf-sys 边界。

### Phase 2：daemon-owned kernel libs

3. **bpfget library**：live snapshot、map fd、BTF records、target probing。
4. **bpfverify library**：dry-run verify、verifier log parse、verifier states。
5. **bpfrejit library**：final `BPF_PROG_REJIT` with fd_array ABI。

### Phase 3：runner integration

6. **daemon socket boundary**：runner Python 不改，daemon 内部链接 daemon-owned libs，只 fork+exec `bpfopt` / `bpfprof`。
7. **Docker/build**：runtime image 只安装 `bpfopt`、`bpfprof`、`bpfrejit-daemon`。

### Phase 4：增强

8. invalidation-hints 完整生命周期。
9. target probing/kInsn BTF capability 扩展。

---

## 11. 明确排除的东西

- `bpfget` / `bpfverify` / `bpfrejit` standalone production CLI
- `bpfget` / `bpfverify` / `bpfrejit` subprocess protocols
- 自定义 pipe framing / binary header
- daemon 内部的 PassManager / pass pipeline
- daemon 内部的 profiler
- daemon 直接绕过 `kernel-sys` 调 `libc::syscall`
