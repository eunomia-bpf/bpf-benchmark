# bpfopt-suite 设计文档 v3

> 本文档自包含，不需要参考其他文件即可开始实现。

## 1. Overview

bpfopt-suite 是一组 Unix 风格的 BPF 字节码工具，每个工具做一件事，通过 stdin/stdout/文件协作。核心理念：**Pipeline 是 bash，不是任何工具内部的概念。**

工具列表：

| 工具 | 职责 | 依赖内核？ |
|------|------|:---:|
| **bpfopt** | BPF 字节码优化器，每个 pass 是子命令 | 否 |
| **bpfverify** | BPF_PROG_LOAD dry-run 验证 | 是 |
| **bpfprof** | 采集 BPF 程序运行时 profile | 是 |
| **bpfget** | 读取内核中 BPF 程序的原始字节码 | 是 |
| **bpfrejit** | 提交字节码给内核 BPF_PROG_REJIT | 是 |
| **bpfrejit-daemon** | 常驻 watch 进程（可选） | 是 |

典型用法：

```bash
# 完整优化管道
bpfget 123 | bpfopt wide-mem | bpfopt rotate | bpfopt const-prop | bpfverify | bpfrejit 123

# 预编译替换（绕过 bpfopt）
llvm-objcopy -O binary --only-section=.text new.bpf.o new.bin
bpfrejit 123 new.bin

# 离线优化报告
bpfopt optimize --report report.json < prog.bin > opt.bin
```

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

### 2.2 bpfverify

调用内核 BPF_PROG_LOAD dry-run 验证字节码。

```bash
# 管道模式：验证通过则透传字节码，失败则 exit 1
bpfopt wide-mem < prog.bin | bpfverify --prog-type xdp | bpfrejit 123

# 独立模式：输出验证报告
bpfverify --prog-type socket_filter --input candidate.bin --report verify.json

# 带 verifier states 输出（供 const-prop 等 pass 消费）
bpfverify --prog-type xdp --input prog.bin --verifier-states-out states.json
```

#### 行为

- **管道模式**（stdout 是 pipe/文件）：验证通过 → 透传 stdin 到 stdout，exit 0；失败 → stderr 输出 verifier log，exit 1，stdout 无输出
- **`--report FILE`**：输出结构化 JSON（pass/fail + verifier log + 解析后的 states）
- **`--verifier-states-out FILE`**：解析 verifier log 中的寄存器常量/range/tnum 信息，输出 JSON

#### 必需 flags

| Flag | 说明 |
|------|------|
| `--prog-type TYPE` | BPF 程序类型（xdp, socket_filter, kprobe, ...） |

#### 可选 flags

| Flag | 说明 |
|------|------|
| `--expected-attach-type TYPE` | attach 类型 |
| `--map-fds FILE` | map FD 绑定 JSON（从 bpfget 获取） |
| `--fd-array FILE` | kinsn BTF fd_array JSON |
| `--log-level N` | verifier log level（0-2），默认 0，取 states 时自动用 2 |

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

### 2.4 bpfget

从内核读取 BPF 程序信息。

```bash
# 读取原始字节码到 stdout（binary）
bpfget 123 > prog.bin

# 读取程序元数据
bpfget 123 --info --output info.json

# 读取字节码 + 元数据 + map 绑定（所有 bpfopt/bpfverify 需要的 side-input）
bpfget 123 --full --outdir /tmp/prog123/
# 输出: /tmp/prog123/prog.bin, prog_info.json, map_fds.json

# 枚举所有活跃 BPF 程序
bpfget --list --json --output programs.json
```

#### 关键功能

- `BPF_PROG_GET_ORIGINAL` → 原始字节码
- `BPF_OBJ_GET_INFO_BY_FD` → prog_name, prog_type, map_ids 等
- `BPF_PROG_GET_NEXT_ID` → 枚举
- `--full` 模式输出所有 side-input 文件，一次性准备好 bpfopt/bpfverify 需要的一切

### 2.5 bpfrejit

提交字节码给内核。

```bash
# 从文件
bpfrejit 123 opt.bin

# 从 stdin（管道末端）
bpfopt wide-mem < prog.bin | bpfrejit 123
```

#### 行为

- 调用 `BPF_PROG_REJIT(prog_fd, new_insns, new_insn_cnt)`
- 成功 → exit 0，输出 summary 到 stderr
- 内核 verify 失败 → exit 1，输出 verifier log 到 stderr
- 验证不替换由 `bpfverify` 负责；`bpfrejit` 不提供 dry-run 模式
- `--fd-array FILE`：kinsn BTF fd_array（如果新字节码包含 kinsn 调用）

### 2.6 bpfrejit-daemon（可选）

常驻 watch 进程。**不做任何优化，不跑 pass pipeline。**

```bash
# 启动 daemon，新程序加载时触发外部脚本
bpfrejit-daemon --on-new-prog /path/to/optimize.sh --socket /var/run/bpfrejit.sock

# optimize.sh 内容示例：
#!/bin/bash
PROG_ID=$1
bpfget $PROG_ID | bpfopt wide-mem | bpfopt rotate | bpfrejit $PROG_ID
```

#### 职责

1. watch 新 BPF 程序加载（轮询 `BPF_PROG_GET_NEXT_ID`）
2. map invalidation 检测（轮询 map values，对比之前 inline 的值）
3. 触发外部脚本/命令进行优化
4. 维护 session 生命周期

#### 不做的事

- 不跑 pass pipeline
- 不调用 bpfopt
- 不做 profiling
- 不做字节码变换
- 不维护 PassManager

daemon 只是一个事件源 + 外部命令触发器。

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

1. **字节码走 stdin/stdout**，二进制流，无 framing
2. **side-input/output 走文件**（--profile, --target, --report 等 flag）
3. **stderr 用于日志和错误信息**
4. **exit 0 = 成功**，exit 1 = 错误
5. pass 无可优化 site → exit 0，原样透传字节码

### 4.2 管道串联示例

```bash
# 三个 pass 管道
bpfopt wide-mem < prog.bin | bpfopt rotate --target target.json | bpfopt const-prop --verifier-states states.json > opt.bin

# 带验证的完整管道
bpfget 123 | bpfopt wide-mem | bpfverify --prog-type xdp | bpfrejit 123

# 带 report 的管道（report 写文件，不影响 stdout 管道）
bpfopt wide-mem --report r1.json < prog.bin | bpfopt rotate --report r2.json > opt.bin
```

### 4.3 per-pass verify 管道

daemon 或外部 runner orchestration 实现 §4.6 的 per-pass verify loop：

```bash
#!/bin/bash
# per-pass verify loop
PROG_ID=$1
PROG_TYPE=$2
CURRENT=$(mktemp)
CANDIDATE=$(mktemp)

bpfget $PROG_ID > $CURRENT

for PASS in wide-mem rotate const-prop cond-select; do
  bpfopt $PASS --target target.json < $CURRENT > $CANDIDATE 2>/dev/null
  if ! diff -q $CURRENT $CANDIDATE >/dev/null 2>&1; then
    # changed — verify
    if bpfverify --prog-type $PROG_TYPE < $CANDIDATE >/dev/null 2>&1; then
      cp $CANDIDATE $CURRENT  # accept
      echo "pass $PASS: accepted"
    else
      echo "pass $PASS: verify failed, rolled back"
    fi
  else
    echo "pass $PASS: no change"
  fi
done

# 最终 REJIT
bpfrejit $PROG_ID $CURRENT
rm -f $CURRENT $CANDIDATE
```

这就是 daemon 过去在 Rust 里实现的 per-pass verify loop。实现时它必须在 daemon 外部编排；如果没有真实调用方，不保留未使用的 checked-in 脚本。

### 4.4 verifier-in-the-loop 管道

```bash
# pass 1: const-prop 需要 verifier states
bpfverify --prog-type xdp --input prog.bin --verifier-states-out states.json
bpfopt const-prop --verifier-states states.json < prog.bin > step1.bin

# pass 2: 用新字节码重新获取 verifier states
bpfverify --prog-type xdp --input step1.bin --verifier-states-out states2.json
bpfopt dce --verifier-states states2.json < step1.bin > step2.bin
```

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
bpfopt-suite/
├── Cargo.toml                    # [workspace]
├── crates/
│   ├── bpfopt-core/              # 共享库 crate（workspace 内部，不对外发布）
│   │   ├── Cargo.toml
│   │   └── src/
│   │       ├── lib.rs            # 公共 re-exports
│   │       ├── insn.rs           # BPF 指令编解码（从 daemon/src/insn.rs）
│   │       ├── pass.rs           # BpfProgram, BpfPass trait, PassManager（从 daemon/src/pass.rs）
│   │       ├── analysis/         # 分析 pass（从 daemon/src/analysis/）
│   │       │   ├── mod.rs
│   │       │   ├── branch_target.rs
│   │       │   ├── cfg.rs
│   │       │   ├── liveness.rs
│   │       │   └── map_info.rs
│   │       ├── passes/           # 所有变换 pass（从 daemon/src/passes/）
│   │       │   ├── mod.rs
│   │       │   ├── wide_mem.rs
│   │       │   ├── rotate.rs
│   │       │   ├── cond_select.rs
│   │       │   ├── extract.rs
│   │       │   ├── endian.rs
│   │       │   ├── branch_flip.rs
│   │       │   ├── const_prop.rs
│   │       │   ├── dce.rs
│   │       │   ├── map_inline.rs
│   │       │   ├── bulk_memory.rs
│   │       │   ├── bounds_check_merge.rs
│   │       │   ├── skb_load_bytes.rs
│   │       │   └── utils.rs
│   │       └── verifier_log.rs   # verifier log 解析（从 daemon/src/verifier_log.rs）
│   │
│   ├── kernel-sys/               # 共享库 crate：raw BPF syscall wrappers
│   │   ├── Cargo.toml
│   │   └── src/
│   │       └── lib.rs            # bpf syscall, OwnedFd 等（从 daemon/src/bpf.rs 的 syscall 部分）
│   │
│   ├── bpfopt/                   # CLI binary
│   │   ├── Cargo.toml            # depends on bpfopt-core
│   │   └── src/main.rs
│   │
│   ├── bpfverify/                # CLI binary
│   │   ├── Cargo.toml            # depends on kernel-sys, bpfopt-core（verifier_log 解析）
│   │   └── src/main.rs
│   │
│   ├── bpfprof/                  # CLI binary
│   │   ├── Cargo.toml            # depends on kernel-sys
│   │   └── src/main.rs
│   │
│   ├── bpfget/                   # CLI binary
│   │   ├── Cargo.toml            # depends on kernel-sys
│   │   └── src/main.rs
│   │
│   ├── bpfrejit/                 # CLI binary
│   │   ├── Cargo.toml            # depends on kernel-sys
│   │   └── src/main.rs
│   │
│   └── bpfrejit-daemon/          # CLI binary（可选）
│       ├── Cargo.toml            # depends on kernel-sys
│       └── src/main.rs
│
├── tests/                        # 集成测试
│   ├── pipeline_test.sh          # 管道集成测试
│   └── fixtures/                 # 测试用字节码
│
└── docs/
    └── README.md
```

### Crate 依赖关系

```
bpfopt-core（纯 bytecode，零内核依赖）
  ↑
  ├── bpfopt（CLI，只依赖 bpfopt-core）
  └── bpfverify（CLI，依赖 bpfopt-core + kernel-sys）

kernel-sys（raw BPF syscall）
  ↑
  ├── bpfverify
  ├── bpfprof
  ├── bpfget
  ├── bpfrejit
  └── bpfrejit-daemon
```

关键：**bpfopt 不依赖 kernel-sys**。它是纯用户态工具。

---

## 7. 从 daemon 迁移的代码映射

| daemon 文件 | 去向 | 改动 |
|-------------|------|------|
| `daemon/src/insn.rs` | `bpfopt-core/src/insn.rs` | 直接移动，无改动 |
| `daemon/src/pass.rs` | `bpfopt-core/src/pass.rs` | 移动；删除 `required_btf_fds`（kinsn FD 不再在 pass 层面管理）；ProfilingData/BranchProfile 保留 |
| `daemon/src/passes/*.rs` | `bpfopt-core/src/passes/*.rs` | 移动；MapInlinePass 改为从 JSON 读 map values（不再调 bpf syscall） |
| `daemon/src/analysis/*.rs` | `bpfopt-core/src/analysis/*.rs` | 直接移动 |
| `daemon/src/verifier_log.rs` | `bpfopt-core/src/verifier_log.rs` | 直接移动 |
| `daemon/src/bpf.rs` | `kernel-sys/src/lib.rs` | 移动 syscall wrappers；删除 pass 相关逻辑 |
| `daemon/src/profiler.rs` | `bpfprof/src/main.rs` | 重写为 CLI；核心采集逻辑保留 |
| `daemon/src/kfunc_discovery.rs` | `bpfget/src/main.rs` 的一部分 | 发现逻辑给 bpfget --target 用 |
| `daemon/src/invalidation.rs` | `bpfrejit-daemon/src/` | 移动到 daemon |
| `daemon/src/commands.rs` | 删除 | pipeline 逻辑由 bash 替代 |
| `daemon/src/server.rs` | `bpfrejit-daemon/src/main.rs` | 大幅简化，只保留 watch + 触发外部命令 |
| `daemon/src/main.rs` | 删除 | 被各个 CLI binary 的 main.rs 替代 |
| `daemon/src/elf_parser.rs` | `bpfopt-core/src/elf_parser.rs`（可选） | 如果需要读 .bpf.o 则保留 |
| `daemon/src/test_utils.rs` | `bpfopt-core/src/test_utils.rs` | 移动 |

### 需要新增的胶水代码

1. **bpfopt CLI**（~200 行）：clap 子命令定义 + stdin/stdout 读写 + side-input JSON 反序列化 + 调用对应 pass
2. **bpfverify CLI**（~150 行）：读 stdin → BPF_PROG_LOAD dry-run → 透传或报错
3. **bpfprof CLI**（~100 行）：clap + 调用 profiler 采集逻辑 + JSON 输出
4. **bpfget CLI**（~150 行）：GET_NEXT_ID + GET_ORIGINAL + GET_INFO + 输出
5. **bpfrejit CLI**（~80 行）：读文件/stdin → BPF_PROG_REJIT

---

## 8. Daemon 瘦身方案

### 瘦身后保留的功能

1. **Watch 新程序加载**：轮询 `BPF_PROG_GET_NEXT_ID`，发现新 prog_id 时触发外部 pipeline
2. **Map invalidation 检测**：读取 `invalidation-hints.json`（由 bpfopt map-inline --report 产出），轮询 map values，检测变化时触发 re-optimize
3. **Unix socket 服务**（可选）：接受 benchmark runner 的 `optimize` 请求，内部执行配置好的外部 pipeline 脚本

### 不再保留的功能

- ~~PassManager~~
- ~~所有 pass 代码~~
- ~~profiler 线程~~
- ~~kfunc discovery~~（移到 bpfget）
- ~~verifier log 解析~~（移到 bpfverify）
- ~~commands.rs 的 optimize pipeline~~（变成 bash 脚本）

### daemon 调外部 pipeline 的方式

```rust
// daemon 核心循环（伪代码）
fn on_new_program(prog_id: u32, config: &Config) {
    let script = &config.on_new_prog_script; // e.g., "/opt/bpfrejit/optimize.sh"
    let status = Command::new(script)
        .arg(prog_id.to_string())
        .status();
    if !status.success() {
        eprintln!("optimize script failed for prog {}", prog_id);
    }
}

fn on_map_invalidation(prog_id: u32, config: &Config) {
    // 同上，调用 re-optimize 脚本
    let script = &config.on_invalidation_script;
    Command::new(script).arg(prog_id.to_string()).status();
}
```

### 与 benchmark runner 的集成

当前 benchmark runner 通过 Unix socket 给 daemon 发 JSON 请求。瘦身后两种选择：

**方案 A**：runner 直接调 CLI 工具（不需要 daemon）
```python
# runner/libs/rejit.py
def optimize(prog_id, target_json):
    subprocess.run(f"bpfget {prog_id} | bpfopt optimize --target {target_json} | bpfrejit {prog_id}", shell=True)
```

**方案 B**：保留 daemon socket，daemon 内部调 CLI
```python
# runner 发请求
send_json(sock, {"cmd": "optimize", "prog_id": 123})
# daemon 收到后执行外部脚本
```

推荐 **方案 A**（benchmark 场景），因为 benchmark 不需要 watch/invalidation。daemon 只在"持续运行自动优化"场景下才需要。

---

## 9. 典型使用场景

### 场景 1：单 pass 优化

```bash
bpfget 123 | bpfopt wide-mem | bpfrejit 123
```

### 场景 2：多 pass 管道 + 验证

```bash
bpfget 123 | bpfopt wide-mem | bpfopt rotate --target target.json | bpfverify --prog-type xdp | bpfrejit 123
```

### 场景 3：带 PGO profile

```bash
# 先采集 profile
bpfprof --prog-id 123 --per-site --duration 1s --output profile.json

# 用 profile 优化
bpfget 123 | bpfopt branch-flip --profile profile.json | bpfrejit 123
```

### 场景 4：预编译替换（绕过 bpfopt）

```bash
# 用户自己编译了一个新版本的 BPF 程序
clang -O2 -target bpf -c new_prog.c -o new_prog.bpf.o
llvm-objcopy -O binary --only-section=.text new_prog.bpf.o new_prog.bin
bpfrejit 123 new_prog.bin
```

### 场景 5：Verifier-in-the-loop（const-prop 需要 verifier states）

```bash
bpfget 123 > prog.bin
bpfverify --prog-type xdp --input prog.bin --verifier-states-out states.json
bpfopt const-prop --verifier-states states.json < prog.bin | bpfopt dce | bpfrejit 123
```

### 场景 6：离线 corpus 优化报告（不需要内核）

```bash
for f in corpus/*.bin; do
  bpfopt optimize --report "$f.report.json" < "$f" > "$f.opt.bin"
done
```

### 场景 7：Daemon 自动优化

```bash
# optimize.sh
#!/bin/bash
PROG_ID=$1
bpfget $PROG_ID | bpfopt optimize --target /etc/bpfopt/target.json | bpfrejit $PROG_ID

# 启动 daemon
bpfrejit-daemon --on-new-prog /opt/bpfrejit/optimize.sh
```

### 场景 8：Benchmark runner 直接调 CLI

```bash
# 在 VM 内，benchmark 脚本直接调工具
bpfget --list --json --output programs.json
for PROG_ID in $(jq -r '.[].id' programs.json); do
  bpfget $PROG_ID | bpfopt optimize --target target.json --report reports/$PROG_ID.json | bpfrejit $PROG_ID
done
```

---

## 10. 实现优先级

### Phase 1：核心工具（最小可用）

1. **bpfopt-core**：从 daemon 移动 insn.rs, pass.rs, passes/, analysis/, verifier_log.rs。确保现有 ~300 tests 全部通过
2. **bpfopt CLI**：实现 `optimize` 子命令 + 至少 `wide-mem` 单 pass 子命令。stdin/stdout binary 读写
3. **bpfrejit CLI**：实现基本的 `bpfrejit PROG_ID FILE` 功能
4. **bpfget CLI**：实现 `bpfget PROG_ID > prog.bin` 和 `bpfget --list --json --output programs.json`

Phase 1 完成后，可以跑：`bpfget 123 | bpfopt wide-mem | bpfrejit 123`

### Phase 2：完整工具链

5. **bpfopt 所有 pass 子命令**：12 个 pass 全部可独立调用
6. **bpfverify CLI**：dry-run + verifier states 输出
7. **bpfprof CLI**：profile 采集
8. **bpfget --full**：一次性输出所有 side-input

### Phase 3：集成

9. **Benchmark runner 适配**：从 daemon socket 协议切换到直接调 CLI
10. **bpfrejit-daemon 瘦身**：删除 pass pipeline，改为触发外部脚本
11. **bpf-benchmark 子模块化**：独立 repo + submodule

### Phase 4：增强

12. per-pass verify loop 外部编排（参考 §4.3 示例；只在存在真实调用方时落地）
13. target.json 自动生成（`bpfget --target` 探测当前平台 kinsn 能力）
14. invalidation-hints 支持

---

## 11. 明确排除的东西

- C FFI / .a / .so
- 公共 Rust 库 API（bpfopt-core 是 workspace 内部的，不 publish）
- ValidationOracle / hook 抽象
- KinsnRequirement 符号化延迟绑定
- 自定义 pipe framing / binary header
- daemon 内部的 PassManager / pass pipeline
- daemon 内部的 profiler
- libbpf 直接链接（未来走 fork+exec）
