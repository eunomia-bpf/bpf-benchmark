# bpfprof CLI 实现调研

日期：2026-04-28

范围：只读调研 `daemon/src/profiler.rs`、v3 设计和 libbpf/libbpf-rs/libbpf-sys 文档。本文不修改实现代码。

## 1. daemon/src/profiler.rs 现有实现细节

### 答案

现有 daemon 的 profiling 有两条路径。

第一条是长期会话 `ProfilerSession`。`start()` 先校验 interval 非 0，再检查 `/proc/sys/kernel/bpf_stats_enabled` 是否为 1，然后读取所有当前 BPF program 的初始 `run_cnt`/`run_time_ns` 快照，最后启动名为 `bpfrejit-profiler` 的后台线程。线程打开 PMU counter，reset/enable 后按 interval 轮询所有程序；停止时再轮询一次、disable PMU，并把累计结果转为 `ProfileSnapshot`。引用：`daemon/src/profiler.rs:311`, `daemon/src/profiler.rs:316`, `daemon/src/profiler.rs:322`, `daemon/src/profiler.rs:328`, `daemon/src/profiler.rs:388`, `daemon/src/profiler.rs:393`, `daemon/src/profiler.rs:398`, `daemon/src/profiler.rs:401`, `daemon/src/profiler.rs:402`, `daemon/src/profiler.rs:409`。

第二条是一次性单程序采样 `collect_program_profiling(prog_id, interval)`。它打开目标 program fd，读取 baseline，sleep 一个 interval，再读取 final，计算 delta；PMU counter 在同一个窗口 reset/enable/read/disable。引用：`daemon/src/profiler.rs:511`, `daemon/src/profiler.rs:524`, `daemon/src/profiler.rs:525`, `daemon/src/profiler.rs:527`, `daemon/src/profiler.rs:531`, `daemon/src/profiler.rs:532`, `daemon/src/profiler.rs:537`。

delta 计算是 `after - before` 的 saturating subtraction：`run_cnt_delta` 和 `run_time_ns_delta`，并用 `run_time_ns_delta / run_cnt_delta` 得到 `avg_ns`。引用：`daemon/src/profiler.rs:61`, `daemon/src/profiler.rs:62`, `daemon/src/profiler.rs:63`, `daemon/src/profiler.rs:77`, `daemon/src/profiler.rs:706`。

注意：现有 daemon 没有执行 v3 背景里描述的“启动 stats fd”。它只检查 sysctl 是否已启用。`bpf_stats_enabled()` 读取 `/proc/sys/kernel/bpf_stats_enabled`，如果不是 1 就报错。引用：`daemon/src/profiler.rs:316`, `daemon/src/profiler.rs:518`, `daemon/src/profiler.rs:667`。

使用的 syscall/API：

- BPF program 枚举：`BPF_PROG_GET_NEXT_ID`。daemon 自己封装 raw `bpf(2)`，迭代器从 `start_id=0` 开始，直到 ENOENT。引用：`daemon/src/bpf.rs:25`, `daemon/src/bpf.rs:627`, `daemon/src/bpf.rs:637`, `daemon/src/bpf.rs:639`, `daemon/src/bpf.rs:1727`, `daemon/src/bpf.rs:1735`, `daemon/src/bpf.rs:1752`。
- 打开 program：`BPF_PROG_GET_FD_BY_ID`。引用：`daemon/src/bpf.rs:28`, `daemon/src/bpf.rs:647`, `daemon/src/bpf.rs:648`, `daemon/src/bpf.rs:653`。
- 读取 `bpf_prog_info`：`BPF_OBJ_GET_INFO_BY_FD`，其中 `run_time_ns` 和 `run_cnt` 在 daemon 自定义 `BpfProgInfo` 里。引用：`daemon/src/bpf.rs:30`, `daemon/src/bpf.rs:491`, `daemon/src/bpf.rs:499`, `daemon/src/bpf.rs:193`, `daemon/src/bpf.rs:194`。
- PMU：`libc::syscall(SYS_perf_event_open, ...)` 打开 `PERF_COUNT_HW_BRANCH_INSTRUCTIONS` 和 `PERF_COUNT_HW_BRANCH_MISSES`；`ioctl` reset/enable/disable；`read` 读 u64 counter；`close` 关闭 fd。引用：`daemon/src/profiler.rs:714`, `daemon/src/profiler.rs:717`, `daemon/src/profiler.rs:718`, `daemon/src/profiler.rs:719`, `daemon/src/profiler.rs:784`, `daemon/src/profiler.rs:786`, `daemon/src/profiler.rs:788`, `daemon/src/profiler.rs:793`, `daemon/src/profiler.rs:800`, `daemon/src/profiler.rs:837`, `daemon/src/profiler.rs:819`, `daemon/src/profiler.rs:823`。
- 没有使用 `BPF_PROG_BIND_MAP`；当前 profiling 也没有使用 `BPF_ENABLE_STATS`。仓库搜索只在 `kernel-sys` 目标 wrapper 里出现 `bpf_enable_stats`，不在 daemon profiling 调用链里。引用：`bpfopt/crates/kernel-sys/src/lib.rs:196`。

fd 生命周期：

- program fd：`ProgStatsPoller` 持有一个 `OwnedFd`，用于单程序轮询；全量轮询每个 program 临时打开 `OwnedFd`，读完快照后自然 drop。引用：`daemon/src/profiler.rs:597`, `daemon/src/profiler.rs:599`, `daemon/src/profiler.rs:612`, `daemon/src/profiler.rs:614`, `daemon/src/profiler.rs:470`, `daemon/src/profiler.rs:476`。
- PMU fd：`PmuCounters` 持有 `branch_insns_fd` 和 `branch_misses_fd` 两个 raw fd，`Drop` 中 close；如果第二个 counter 打开失败，会先 close 第一个。引用：`daemon/src/profiler.rs:760`, `daemon/src/profiler.rs:767`, `daemon/src/profiler.rs:768`, `daemon/src/profiler.rs:771`, `daemon/src/profiler.rs:810`, `daemon/src/profiler.rs:813`。
- stats fd：现有 daemon 没有。目标 bpfprof 应持有 `BPF_ENABLE_STATS` 返回的 fd，使 stats 在采样窗口内保持启用。
- 线程生命周期：`ProfilerSession` 持有 `mpsc::Sender` 和 `JoinHandle`，`stop()` 发送停止信号并 join；`Drop` 也会尝试停止并 join。引用：`daemon/src/profiler.rs:260`, `daemon/src/profiler.rs:348`, `daemon/src/profiler.rs:355`, `daemon/src/profiler.rs:370`。

线程模型：长期 session 是多线程，后台 profiling 线程加 `Arc<Mutex<SessionState>>`；`collect_program_profiling` 和 `collect_hotness_ranking` 是同步单线程采样。引用：`daemon/src/profiler.rs:13`, `daemon/src/profiler.rs:261`, `daemon/src/profiler.rs:328`, `daemon/src/profiler.rs:550`, `daemon/src/profiler.rs:566`, `daemon/src/profiler.rs:567`。

URL：

- libbpf `BPF_ENABLE_STATS` wrapper source：https://github.com/libbpf/libbpf/blob/v1.7.0/src/bpf.c

## 2. libbpf-rs / libbpf-sys 相关 API

### 答案

`libbpf_sys::bpf_enable_stats` 存在。docs.rs 上的签名是：

```rust
pub unsafe extern "C" fn bpf_enable_stats(type_: bpf_stats_type) -> c_int
```

`BPF_STATS_RUN_TIME` 也存在，类型是 `bpf_stats_type`，值为 0。URL：https://docs.rs/libbpf-sys/latest/libbpf_sys/fn.bpf_enable_stats.html ，https://docs.rs/libbpf-sys/latest/libbpf_sys/constant.BPF_STATS_RUN_TIME.html ，https://docs.rs/libbpf-sys/latest/src/libbpf_sys/bindings.rs.html

libbpf 的 C API 定义是 `int bpf_enable_stats(enum bpf_stats_type type);`，用途是启用 system-wide BPF stats，之后通过 `bpf_prog_get_info_by_fd` 读取 stats。URL：https://docs.ebpf.io/ebpf-library/libbpf/userspace/bpf_enable_stats/

返回值需要按 libbpf 源码理解，而不是只看二级文档的“0 on success”描述。v1.7.0 `bpf_enable_stats()` 内部调用 `sys_bpf_fd(BPF_ENABLE_STATS, ...)`，再 `return libbpf_err_errno(fd)`；`libbpf_err_errno` 对非负返回值原样返回。因此实际成功返回的是 fd，需要 RAII 持有并 close。URL：https://github.com/libbpf/libbpf/blob/v1.7.0/src/bpf.c ，https://github.com/libbpf/libbpf/blob/v1.7.0/src/libbpf_internal.h 。本仓库当前 `kernel-sys::enable_stats` 也已经按 `OwnedFd` 包装。引用：`bpfopt/crates/kernel-sys/src/lib.rs:196`, `bpfopt/crates/kernel-sys/src/lib.rs:198`, `bpfopt/crates/kernel-sys/src/lib.rs:202`。

`libbpf-rs` 高层 crate re-export `libbpf_sys`，但它主要是对象加载、map、program attach 的安全封装。URL：https://docs.rs/libbpf-rs/latest/libbpf_rs/ 。它有 `Program::attach_perf_event` / `attach_perf_event_with_opts`，但语义是把一个 BPF program attach 到一个已存在的 perf event fd，不是打开硬件 PMU counter fd。URL：https://docs.rs/libbpf-rs/latest/libbpf_rs/struct.ProgramImpl.html ，https://docs.rs/libbpf-rs/latest/src/libbpf_rs/program.rs.html

`perf_event_open` 本身不由 libbpf-rs 提供“打开硬件 counter”的 wrapper。可选方案：

- 继续像 daemon 一样在 `kernel-sys` 内用 `libc::syscall(SYS_perf_event_open, ...)`。
- 或引入 `perf-event-open-sys`，它提供 `pub unsafe fn perf_event_open(attrs, pid, cpu, group_fd, flags) -> c_int`，并提供 `perf_event_attr` 和 ioctl 相关绑定。URL：https://docs.rs/perf-event-open-sys/latest/perf_event_open_sys/ ，https://docs.rs/perf-event-open-sys/latest/perf_event_open_sys/fn.perf_event_open.html ，https://docs.rs/perf-event-open-sys/latest/perf_event_open_sys/bindings/struct.perf_event_attr.html

结论：bpfprof CLI 的 BPF syscalls 应通过 `kernel-sys`，`enable_stats` 已有雏形；PMU 也建议放进 `kernel-sys`，避免 CLI crate 直接散落 syscall/ioctl/read/close 细节。

## 3. profile.json schema 与现有 daemon 输出对比

### 答案

现有 daemon 的保存格式是 `ProfileSnapshot`：

```json
{
  "version": 1,
  "collected_at": "...",
  "duration_ms": 1234,
  "programs": {
    "123": {
      "run_cnt": 10,
      "run_time_ns": 1000,
      "avg_ns": 100.0,
      "branch_miss_rate": 0.01
    }
  }
}
```

字段来源：`ProfileSnapshot` 包含 `version`、`collected_at`、`duration_ms`、`programs`，`ProgramProfile` 包含 `run_cnt`、`run_time_ns`、`avg_ns`、`branch_miss_rate`。引用：`daemon/src/profiler.rs:156`, `daemon/src/profiler.rs:157`, `daemon/src/profiler.rs:158`, `daemon/src/profiler.rs:160`, `daemon/src/profiler.rs:161`, `daemon/src/profiler.rs:179`, `daemon/src/profiler.rs:181`, `daemon/src/profiler.rs:184`。

注意现有 `ProgramProfile.run_cnt` 和 `run_time_ns` 实际存的是累计 delta，不是 kernel total。`add_delta()` 把每次窗口 delta 累加进去；`hotness_ranking()` 也把 snapshot 内的 `run_cnt` 当 `delta_run_cnt` 使用。引用：`daemon/src/profiler.rs:165`, `daemon/src/profiler.rs:166`, `daemon/src/profiler.rs:167`, `daemon/src/profiler.rs:224`, `daemon/src/profiler.rs:225`。

v3 §3.4 要求的 schema 是单个 program profile object：`prog_id`、`duration_ms`、`run_cnt_delta`、`run_time_ns_delta`、`branch_miss_rate`、`branch_misses`、`branch_instructions`、可选 `per_insn`。引用：`docs/tmp/bpfopt_design_v3.md:313`, `docs/tmp/bpfopt_design_v3.md:319`, `docs/tmp/bpfopt_design_v3.md:320`, `docs/tmp/bpfopt_design_v3.md:321`, `docs/tmp/bpfopt_design_v3.md:322`, `docs/tmp/bpfopt_design_v3.md:323`, `docs/tmp/bpfopt_design_v3.md:324`, `docs/tmp/bpfopt_design_v3.md:325`, `docs/tmp/bpfopt_design_v3.md:326`, `docs/tmp/bpfopt_design_v3.md:333`, `docs/tmp/bpfopt_design_v3.md:334`。

字段映射和缺口：

- `programs["123"].run_cnt` -> `run_cnt_delta`
- `programs["123"].run_time_ns` -> `run_time_ns_delta`
- `programs["123"].branch_miss_rate` -> `branch_miss_rate`
- `duration_ms` 可复用
- `avg_ns`、`version`、`collected_at`、顶层 `programs` map 是 daemon snapshot 私有格式，不在 v3 schema
- `prog_id` 需要从 map key 移到 profile object 内
- `branch_misses` 和 `branch_instructions` 当前没有保存。daemon 只保存 ratio；`read_branch_miss_rate()` 内部读两个 counter 后立即只返回 `misses / insns`。引用：`daemon/src/profiler.rs:800`, `daemon/src/profiler.rs:801`, `daemon/src/profiler.rs:802`, `daemon/src/profiler.rs:806`。
- `per_insn` 当前没有生产来源。daemon 明确写着 per-PC `branch_profiles` 为空，因为还没有 production source；`ProgramProfile::to_profiling_data()` 也构造空 `HashMap`。引用：`daemon/src/profiler.rs:171`, `daemon/src/profiler.rs:173`, `daemon/src/profiler.rs:509`, `daemon/src/profiler.rs:510`, `daemon/src/profiler.rs:542`, `daemon/src/profiler.rs:543`。

`per_insn taken/not_taken` 不是来自 verifier，也不是当前 PMU counter。`bpfopt` 的 pass 层只定义了可被注入的 `ProfilingData.branch_profiles: HashMap<usize, BranchProfile>`，branch-flip 会优先消费 per-site `BranchProfile`，但 daemon 当前从未填充它。引用：`bpfopt/crates/bpfopt/src/pass.rs:27`, `bpfopt/crates/bpfopt/src/pass.rs:34`, `bpfopt/crates/bpfopt/src/pass.rs:35`, `bpfopt/crates/bpfopt/src/pass.rs:36`, `bpfopt/crates/bpfopt/src/pass.rs:319`, `bpfopt/crates/bpfopt/src/pass.rs:324`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:30`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:153`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:154`。

URL：

- v3 profile schema 在仓库内，无外部 URL。
- libbpf stats 可通过 `bpf_prog_get_info_by_fd` 取回：https://docs.ebpf.io/ebpf-library/libbpf/userspace/bpf_enable_stats/

## 4. --all 模式实现思路

### 答案

枚举所有活跃 BPF 程序应通过 `BPF_PROG_GET_NEXT_ID` 循环。现有 daemon 的 `iter_prog_ids()` 已经是这个模式：保存 `next_id`，每次调用 `bpf_prog_get_next_id(self.next_id)`，成功后把返回 id 作为下一轮 start_id，ENOENT 结束。引用：`daemon/src/bpf.rs:1722`, `daemon/src/bpf.rs:1727`, `daemon/src/bpf.rs:1735`, `daemon/src/bpf.rs:1736`, `daemon/src/bpf.rs:1740`, `daemon/src/bpf.rs:1752`。目标 `kernel-sys` 已有 `prog_get_next_id(start_id) -> Result<Option<u32>>`。引用：`bpfopt/crates/kernel-sys/src/lib.rs:156`, `bpfopt/crates/kernel-sys/src/lib.rs:157`, `bpfopt/crates/kernel-sys/src/lib.rs:159`, `bpfopt/crates/kernel-sys/src/lib.rs:167`。

`bpf_enable_stats` 不需要每个 program 单独调用。它是 system-wide stats 开关，CLI 应在采样窗口开始前调用一次 `kernel_sys::enable_stats(BPF_STATS_RUN_TIME)`，持有返回 fd 到所有 final snapshots 读取完成。每个 program 需要独立打开 program fd 并读取 `bpf_prog_info`。URL：https://docs.ebpf.io/ebpf-library/libbpf/userspace/bpf_enable_stats/ 。本仓库 wrapper：`bpfopt/crates/kernel-sys/src/lib.rs:196`。

PMU counter 的情况不同。现有 daemon 是打开一组 branch instructions/misses counter，并把同一个 `branch_miss_rate` 写给所有 program。引用：`daemon/src/profiler.rs:393`, `daemon/src/profiler.rs:441`, `daemon/src/profiler.rs:447`, `daemon/src/profiler.rs:459`。这不是严格 per-program PMU attribution。`--all` 的 MVP 应避免声称 raw branch counters 是每个 BPF program 独立测得；实现前需要明确语义。若保持 v3 schema 不变，推荐先输出 per-program stats delta，并仅在能给出正确窗口含义时填 `branch_misses`/`branch_instructions`。

输出结构推荐：`--all --output profiles/` 写目录，生成 `profiles/<prog_id>.json`，每个文件都是 v3 §3.4 的单 program schema。理由是 v3 的 `bpfopt branch-flip --profile FILE` 消费单个 profile 文件，且 v3 示例把 `--all` 的 output 写成目录。引用：`docs/tmp/bpfopt_design_v3.md:147`, `docs/tmp/bpfopt_design_v3.md:315`, `docs/tmp/bpfopt_design_v3.md:678`, `docs/tmp/bpfopt_design_v3.md:681`。

## 5. --show 模式实现

### 答案

`--show` 应显示热度排名，默认按当前 daemon 的 `HotnessRanking` 语义排序：`run_cnt_delta / duration` 降序，tie-breaker 为 `run_time_ns_delta` 降序、`avg_ns`、`prog_id` 升序。引用：`daemon/src/profiler.rs:110`, `daemon/src/profiler.rs:117`, `daemon/src/profiler.rs:131`, `daemon/src/profiler.rs:134`, `daemon/src/profiler.rs:138`, `daemon/src/profiler.rs:144`。

建议输出固定 ASCII table，不用 box drawing 字符，列控制在 8 列：

```text
RANK PROG_ID NAME TYPE RUNS RUN_TIME_NS AVG_NS BR_MISS%
1    123     xdp1 xdp  1500 4500000     3000.0 3.20
```

如果 raw PMU counts 已能正确采集，可在 `--verbose` 或后续扩展中增加 `BR_MISSES`、`BR_INSNS`；v3 当前未定义 `--verbose`，第一版不要增加隐含复杂度。`--show` 可与 `--output` 同时使用：stdout 打表，`--output` 仍写 JSON；如果没有 `--output`，只显示 table。

## 6. CLI 参数解析

### 答案

推荐 flags 与行为：

- `--prog-id N`：采样单个 program。与 `--all` 互斥且二选一。
- `--all`：枚举所有活跃 BPF program，统一采样窗口，默认只输出成功采样的 program。
- `--duration D`：采样窗口，必须大于 0。示例要求 `500ms`、`1s`、`250ms`。引用：`docs/tmp/bpfopt_design_v3.md:144`, `docs/tmp/bpfopt_design_v3.md:147`, `docs/tmp/bpfopt_design_v3.md:150`。
- `--output PATH`：JSON 输出路径。单程序时是文件；`--all` 时是目录，生成 `<prog_id>.json`。当未指定 `--show` 时应必填，避免把 profiling JSON 和错误混在 stdout/stderr 语义里。
- `--show`：显示热度排名。可单独使用，也可与 `--output` 同时使用。

duration 解析建议用 `humantime::parse_duration`，而不是手写 `ms/s` parser。理由是 clap 自定义 value_parser 很薄，错误消息更稳定，也自然支持 `2s`、`1m` 等格式。当前 workspace 已有 `clap`，但没有 `humantime`；实现 bpfprof 时需要给 workspace 加依赖。引用：`bpfopt/Cargo.toml:10`。

CLI crate 依赖应是：`anyhow`、`clap`、`serde`、`serde_json`、`humantime`、`kernel-sys`。bpfprof 不应依赖 `bpfopt` CLI 或其他 CLI binary crate，符合 v3 的 crate 依赖结构。引用：`docs/tmp/bpfopt_design_v3.md:526`, `docs/tmp/bpfopt_design_v3.md:527`, `docs/tmp/bpfopt_design_v3.md:550`, `docs/tmp/bpfopt_design_v3.md:558`, `docs/tmp/bpfopt_design_v3.md:561`。

## 7. 错误处理边界

### 答案

`prog_id` 不存在：

- 单程序模式：`prog_get_fd_by_id(prog_id)` 返回 ENOENT 时直接 exit 1，stderr 包含 `prog <id>` 和底层 errno。daemon 现有 wrapper 对 `BPF_PROG_GET_FD_BY_ID(id)` 失败会带上下文报错。引用：`daemon/src/profiler.rs:612`, `daemon/src/profiler.rs:614`, `daemon/src/bpf.rs:647`, `daemon/src/bpf.rs:658`, `daemon/src/bpf.rs:659`。
- `--all`：program 可能在枚举后卸载。对单个 program 的 ENOENT 应记录到 stderr 并继续其他 program；最终如果有任何 per-program 失败，进程 exit 1，但已写成功的 profile 文件。

没权限：

- `BPF_ENABLE_STATS` 或 program fd/info 失败是 fatal。错误直接展示底层 errno，例如 EPERM/EACCES，并提示需要 root 或相应 capability。目标 wrapper 已有 `BPF_ENABLE_STATS` 错误上下文。引用：`bpfopt/crates/kernel-sys/src/lib.rs:196`, `bpfopt/crates/kernel-sys/src/lib.rs:198`, `bpfopt/crates/kernel-sys/src/lib.rs:200`。
- `perf_event_open` 失败通常和 `perf_event_paranoid`、CAP_PERFMON/CAP_SYS_ADMIN 或硬件 PMU 支持有关。daemon 当前是 optional，`PmuCounters::open()` 失败返回 `None`，不会报错。引用：`daemon/src/profiler.rs:765`, `daemon/src/profiler.rs:767`, `daemon/src/profiler.rs:768`, `daemon/src/profiler.rs:774`。bpfprof CLI 若要满足 v3 的 `branch_misses`/`branch_instructions` 字段，建议默认把 PMU 打不开当成 error，而不是静默输出缺字段。

kernel 不支持 stats：

- 目标实现调用 `BPF_ENABLE_STATS(BPF_STATS_RUN_TIME)`，若返回 EINVAL/EOPNOTSUPP/ENOSYS 等，exit 1 并显示 `BPF_ENABLE_STATS(BPF_STATS_RUN_TIME)` 失败。不要退回到读取 0 delta 或伪造数据。
- 现有 daemon 对旧路径的处理是 sysctl 文件读失败或值不是 1 就报错。引用：`daemon/src/profiler.rs:667`, `daemon/src/profiler.rs:668`, `daemon/src/profiler.rs:670`。

`--all` 部分失败：

- 全局初始化失败必须 abort：duration 非法、`BPF_ENABLE_STATS` 失败、PMU 初始化按 strict 策略失败、枚举 syscall 失败、output directory 不可写。
- 单 program 失败可继续：program 消失、单个 fd/info 读取失败。stderr 列出 `prog_id: error`，process 最终 exit 1。不要把 `errors`、`limitations` 等 informational 字段写进 profile JSON。

## 8. 从 daemon 迁移代码的步骤

### 答案

可直接拆走或改写进 bpfprof CLI 的 public/核心 API：

- `ProgStats`、`ProgStatsSnapshot`、`ProgStatsDelta` 的 delta 计算。引用：`daemon/src/profiler.rs:23`, `daemon/src/profiler.rs:40`, `daemon/src/profiler.rs:47`, `daemon/src/profiler.rs:61`。
- `PgoAnalysis`、`HotnessRanking` 的排名逻辑。引用：`daemon/src/profiler.rs:82`, `daemon/src/profiler.rs:121`, `daemon/src/profiler.rs:130`。
- `ProgStatsPoller` 的单 program open/snapshot/collect_deltas 流程，但 BPF 调用要从 `crate::bpf` 改成 `kernel-sys`。引用：`daemon/src/profiler.rs:597`, `daemon/src/profiler.rs:612`, `daemon/src/profiler.rs:624`, `daemon/src/profiler.rs:630`, `daemon/src/profiler.rs:648`。
- PMU 的 RAII 思路和 reset/enable/read/disable/close 流程，但应扩展为返回 raw counts，不只返回 ratio。引用：`daemon/src/profiler.rs:760`, `daemon/src/profiler.rs:784`, `daemon/src/profiler.rs:793`, `daemon/src/profiler.rs:800`, `daemon/src/profiler.rs:837`。

需要重写的部分：

- `ProfileSnapshot` schema 要替换成 v3 `ProfileJson`，不保留 daemon 的 `version/collected_at/programs` 外壳。引用：`daemon/src/profiler.rs:179`, `docs/tmp/bpfopt_design_v3.md:313`。
- `ProfilerSession` 后台线程不适合 CLI 第一版。CLI 直接同步采样：baseline -> enable PMU -> sleep(duration) -> disable/read PMU -> final -> JSON。引用：`daemon/src/profiler.rs:260`, `docs/tmp/bpfopt_design_v3.md:594`。
- `bpf_stats_enabled()` sysctl 检查应替换成 `kernel_sys::enable_stats(BPF_STATS_RUN_TIME)` guard。引用：`daemon/src/profiler.rs:667`, `bpfopt/crates/kernel-sys/src/lib.rs:196`。

留在 daemon 的内容：

- v3 瘦身后的 daemon 只 watch 新程序、检测 map invalidation、触发外部 pipeline；不维护 PassManager，不跑 pass pipeline，不保留 profiler 线程。引用：`docs/tmp/bpfopt_design_v3.md:212`, `docs/tmp/bpfopt_design_v3.md:214`, `docs/tmp/bpfopt_design_v3.md:600`, `docs/tmp/bpfopt_design_v3.md:604`, `docs/tmp/bpfopt_design_v3.md:608`, `docs/tmp/bpfopt_design_v3.md:610`, `docs/tmp/bpfopt_design_v3.md:612`。

当前 daemon 确实把 profiling 数据反馈给优化路径。`ProfilingState::profiling_data_for()` 从 snapshot 转出 `pass::ProfilingData`；`optimize` 和 `optimize-all` 调 `commands::try_apply_one(..., profiling, ...)`；`BpfProgram::inject_profiling()` 再把 `branch_profiles` 和 `branch_miss_rate` 注入 pass IR。引用：`daemon/src/server.rs:78`, `daemon/src/server.rs:91`, `daemon/src/server.rs:476`, `daemon/src/server.rs:482`, `daemon/src/server.rs:485`, `daemon/src/server.rs:629`, `daemon/src/server.rs:635`, `bpfopt/crates/bpfopt/src/pass.rs:319`, `bpfopt/crates/bpfopt/src/pass.rs:324`, `bpfopt/crates/bpfopt/src/pass.rs:330`。

v3 改成文件边界：`bpfprof --prog-id 123 --duration 1s --output profile.json` 先采集，`bpfget 123 | bpfopt branch-flip --profile profile.json | bpfrejit 123` 再消费；branch-flip 是需要 `--profile` 的 pass。引用：`docs/tmp/bpfopt_design_v3.md:83`, `docs/tmp/bpfopt_design_v3.md:465`, `docs/tmp/bpfopt_design_v3.md:674`, `docs/tmp/bpfopt_design_v3.md:678`, `docs/tmp/bpfopt_design_v3.md:681`。

## 实现 plan

### bpfprof/src/main.rs 大致结构

```rust
#[derive(Parser)]
struct Args {
    #[arg(long, conflicts_with = "all")]
    prog_id: Option<u32>,
    #[arg(long)]
    all: bool,
    #[arg(long, value_parser = parse_duration)]
    duration: Duration,
    #[arg(long)]
    output: Option<PathBuf>,
    #[arg(long)]
    show: bool,
}

fn main() -> Result<()> {
    let args = Args::parse();
    validate_args(&args)?;

    let stats_fd = kernel_sys::enable_stats(kernel_sys::BPF_STATS_RUN_TIME)?;
    let targets = collect_targets(&args)?;
    let before = read_snapshots(&targets)?;

    let pmu = BranchCounters::open()?;
    pmu.reset_and_enable()?;
    sleep(args.duration);
    pmu.disable()?;
    let branch = pmu.read_counts()?;

    let after = read_snapshots(&targets)?;
    let profiles = build_v3_profiles(before, after, branch, args.duration)?;

    if let Some(path) = args.output { write_profiles(path, &profiles, args.all)?; }
    if args.show { print_table(&profiles); }
    drop(stats_fd);
    Ok(())
}
```

### 依赖

- `clap`：参数解析。当前 workspace 已有。引用：`bpfopt/Cargo.toml:10`。
- `anyhow`：错误上下文。当前 workspace 已有。引用：`bpfopt/Cargo.toml:9`。
- `serde`/`serde_json`：v3 JSON。当前 workspace 已有。引用：`bpfopt/Cargo.toml:11`, `bpfopt/Cargo.toml:12`。
- `humantime`：duration parser，需要新增 workspace dep。
- `kernel-sys`：唯一 BPF syscall 边界。v3 结构要求 bpfprof 依赖 kernel-sys。引用：`docs/tmp/bpfopt_design_v3.md:526`, `docs/tmp/bpfopt_design_v3.md:527`, `docs/tmp/bpfopt_design_v3.md:558`, `docs/tmp/bpfopt_design_v3.md:561`。

### 需要新加或确认的 kernel-sys API

已存在但需确认稳定：

- `prog_get_next_id(start_id) -> Result<Option<u32>>`。引用：`bpfopt/crates/kernel-sys/src/lib.rs:156`。
- `prog_get_fd_by_id(id) -> Result<OwnedFd>`。引用：`bpfopt/crates/kernel-sys/src/lib.rs:170`。
- `obj_get_info_by_fd(fd) -> Result<bpf_prog_info>`。引用：`bpfopt/crates/kernel-sys/src/lib.rs:179`。
- `enable_stats(BPF_STATS_RUN_TIME) -> Result<OwnedFd>`。引用：`bpfopt/crates/kernel-sys/src/lib.rs:196`。

建议新增：

- `iter_prog_ids() -> impl Iterator<Item = Result<u32>>`，从 daemon `ProgIdIter` 迁移。
- `prog_info_by_id(id) -> Result<(OwnedFd, bpf_prog_info)>` 或只返回 info 的 convenience，减少 CLI 重复上下文代码。
- `BranchCounters`/`PerfCounter` RAII：封装 `perf_event_open`、`ioctl RESET/ENABLE/DISABLE`、`read u64`、`Drop close`。
- `BranchCounts { branch_misses, branch_instructions, branch_miss_rate }`，由 PMU raw counter 读数构建。

### 迁移步骤

1. 新建 `bpfopt/crates/bpfprof/` binary crate，只依赖 `kernel-sys` 和通用 crate，不依赖其他 CLI crate。
2. 从 `daemon/src/profiler.rs` 迁移 stats snapshot/delta/ranking/PMU RAII 思路，替换所有 `crate::bpf` 调用。
3. 用 `kernel_sys::enable_stats(BPF_STATS_RUN_TIME)` 替代 sysctl precondition，持有 fd 覆盖整个采样窗口。
4. 把 PMU reader 改成 raw counts + ratio，满足 v3 `branch_misses`/`branch_instructions`。
5. 实现单 program JSON 和 `--all` 目录输出；实现 `--show` ASCII table。
6. 后续瘦身 daemon 时删除 profiler 线程和 socket profile-start/stop/save/load 路径，把 benchmark runner 改为直接调用 CLI。

## 风险与未决

- 当前 daemon 的 PMU counter 不是 per-BPF-program attribution。它打开一组 counter 后把同一个 `branch_miss_rate` 赋给所有 program。`branch_misses`/`branch_instructions` 在 v3 schema 中看起来是 program-level 字段，但现有实现没有可靠来源。引用：`daemon/src/profiler.rs:441`, `daemon/src/profiler.rs:459`, `docs/tmp/bpfopt_design_v3.md:323`, `docs/tmp/bpfopt_design_v3.md:324`, `docs/tmp/bpfopt_design_v3.md:325`。
- `per_insn taken/not_taken` 没有 production source。verifier 不提供运行时 taken/not_taken，当前 PMU 也只是 program/window 级硬件 counter。需要另行设计 kernel hook、instrumentation、采样归因或 fork 内核支持。引用：`daemon/src/profiler.rs:509`, `daemon/src/profiler.rs:510`, `docs/tmp/bpfopt_design_v3.md:326`。
- `perf_event_open` 的 pid/cpu scope 需要重新确认。现有 daemon 用 `pid=0,cpu=-1`，这更像当前进程/线程窗口 counter，不等于所有 BPF program 执行。引用：`daemon/src/profiler.rs:823`, `daemon/src/profiler.rs:825`, `daemon/src/profiler.rs:826`, `daemon/src/profiler.rs:827`。URL：https://docs.rs/perf-event-open-sys/latest/perf_event_open_sys/fn.perf_event_open.html
- `bpf_enable_stats` 返回值文档有不一致。docs.rs 只给签名；eBPF Docs 写 0 on success；libbpf v1.7.0 源码和本仓库 `kernel-sys` wrapper 表明需要当 fd 持有。实现时以 libbpf 源码和 wrapper 行为为准。
- `--all` 会持有 program fd 到采样结束，这会在窗口内延长 program 生命周期。通常可接受，但需要在文档/测试中确认不会影响卸载敏感场景。
- 旧内核、低权限容器、`perf_event_paranoid` 会导致 stats 或 PMU 不可用。按“失败自然 surface”原则，CLI 不应伪造字段。
