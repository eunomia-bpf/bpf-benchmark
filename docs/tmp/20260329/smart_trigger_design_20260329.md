# Section-Name-Based Smart Trigger 设计

日期：2026-03-29

## 1. 目标

目标是把 `attach_trigger` 的触发策略从 corpus YAML 里的硬编码 shell command，收敛成 runner 侧的：

`section name -> trigger category -> canonical workload`

约束：

- 只分析 `runner/corpus/results/vm_corpus_20260329_091745/metadata.json` 对应的 `214` 个 `did not fire` 样本。
- 不修改 `vendor/linux-framework`。
- 不改代码、不改 paper、不 commit；本文只给设计、覆盖率和工程量估计。

## 2. 数据口径

`vm_corpus_20260329_091745` 的 summary 里，核心数字是：

- `targets_attempted = 2009`
- `attach_trigger = 1536`
- `supported attach_trigger roots = 1060`
- `measured_pairs = 705`
- `comparable_pairs = 415`
- `attach_trigger did not fire = 214`
- `attach_trigger unsupported = 27`
- `exec_ns=0 (非 did-not-fire) = 49`

也就是说，这轮测量里真正的主缺口就是这 `214` 个 `run_cnt_delta=0`。

## 3. 方法说明

这轮 run 的 `details/result.json` 已被后续同 `run_type` artifact 清理，磁盘上只剩 `metadata.json`。所以这里不能直接枚举当时的 214 个 `program_records`，只能做“section-name recovery”：

1. 用 `runner/corpus/results/vm_corpus_20260329_091745/metadata.json` 锁定 ground truth 计数。
2. 用 `git show HEAD:corpus/config/macro_corpus.yaml` 和 `git show HEAD:corpus/results/expanded_corpus_build.latest.json` 重建与 artifact 对齐的 corpus 选择。
3. 在 `1060` 个“runner 已认可 root、理论可 auto-trigger”的 `attach_trigger` 程序里，按 section name 识别“当前 trigger 明显语义错配”的 bucket。
4. 这些 bucket 精确加总为 `214`，作为本设计的恢复分布。

这不是逐程序 ground truth dump，但它和 artifact 的总数严格对齐，足够支撑 category 设计和工程优先级。

## 4. 当前触发器的结构性问题

当前 corpus 里 `attach_trigger` 一共只用了 `20` 种显式 `trigger` 命令，其中：

- `1067` 个程序共用 `for i in $(seq 200); do /bin/true; done`
- `127` 个程序共用 `bpftool prog show`
- `93` 个程序共用 `mktemp && rm`
- `88` 个程序共用 `curl 127.0.0.1`
- `78` 个程序共用 `ping 127.0.0.1`

runner 侧虽然已经有 auto-trigger fallback，但只有 6 个粗粒度 suite：

- `exec`
- `process`
- `sched`
- `file`
- `memory`
- `network`

这两个问题叠加以后，会出现“section 已经包含足够强的语义线索，但显式 trigger 和 fallback 都没有真正打到对应 hook”的情况。`214` 个未触发程序就是这个缝隙。

## 5. 214 个未触发程序的 section name 分布

### 5.1 Recovery bucket 分布

| Bucket | Count | Share | 典型 section | 当前 trigger | 结论 |
| --- | ---: | ---: | --- | --- | --- |
| `xdp` | 67 | 31.3% | `tp_btf/xdp_devmap_xmit`, `tp_btf/xdp_cpumap_kthread` | `ping 127.0.0.1` | loopback ping 不会命中 XDP redirect/devmap/cpumap 路径 |
| `sleep_getpgid` | 32 | 15.0% | `fentry/__x64_sys_nanosleep`, `fentry/__x64_sys_getpgid` | mostly `/bin/true` | generic exec workload 不覆盖特定 syscall |
| `memory_hotpath` | 30 | 14.0% | `lsm/file_mprotect`, `mark_page_accessed`, `mm_vmscan_*` | `/bin/true`, `mktemp`, `cat /proc/meminfo` | workload 没打到 reclaim/page-cache/mprotect 热路径 |
| `cgroup_lifecycle` | 29 | 13.6% | `tp_btf/cgroup_mkdir`, `raw_tracepoint/cgroup_rmdir` | `/bin/true` | 完全没有 cgroup create/delete/release 行为 |
| `net_bind_create` | 18 | 8.4% | `socket_post_create`, `socket_bind`, `inet_bind` | `curl`, `/bin/true`, `socket().close()` | connect 不等于 bind/create/post-create |
| `block_longtail` | 17 | 7.9% | `block_io_start`, `blk_account_io_*`, `writeback_dirty_*` | `/bin/true`, `dd _bio_bench` | 现有 bio workload 只覆盖一部分 block path |
| `security_longtail` | 13 | 6.1% | `audit_rule_known`, `ptrace`, `mount`, `umount`, `setns` | `/bin/true`, `mktemp` | 需要特权/namespace/admin syscall 组合 |
| `irq_softirq` | 8 | 3.7% | `irq_handler_*`, `softirq_*` | `ls /tmp` | 文件枚举不会稳定制造 IRQ/softirq |

合计：`67 + 32 + 30 + 29 + 18 + 17 + 13 + 8 = 214`

### 5.2 Top raw section names

| Section | Count |
| --- | ---: |
| `tp_btf/cgroup_mkdir` | 19 |
| `tp_btf/xdp_devmap_xmit` | 15 |
| `tp_btf/xdp_cpumap_kthread` | 15 |
| `fentry/__x64_sys_nanosleep` | 11 |
| `tp_btf/xdp_redirect_err` | 7 |
| `tp_btf/xdp_redirect` | 7 |
| `tp_btf/xdp_cpumap_enqueue` | 7 |
| `tp_btf/xdp_exception` | 7 |
| `fentry/__x64_sys_getpgid` | 5 |
| `lsm/file_mprotect` | 5 |
| `lsm/audit_rule_known` | 4 |

### 5.3 Root / repo 集中度

- section root 上，`tp_btf = 88/214`，是第一大根因。
- repo 上，`linux-selftests = 72`，`xdp-tools = 57`，`bcc = 52`。
- 前三个 repo 合计 `181/214 = 84.6%`，说明 smart trigger 的收益非常集中。

## 6. Smart Trigger Category 映射表

建议把 runner 里的 smart trigger 做成“section-name classifier + workload registry”，优先映射到下面 8 类：

| Smart Category | Section match rule | Canonical workload | 预计回收 |
| --- | --- | --- | ---: |
| `xdp_redirect_path` | `xdp`, `devmap`, `cpumap` | 建临时 `veth` 对，加载极小 helper XDP redirect fixture，双向发包触发 `redirect/devmap/cpumap` | 67 |
| `cgroup_lifecycle` | `cgroup_mkdir`, `cgroup_rmdir`, `cgroup_release` | 创建子 cgroup，迁移当前 pid，删除 cgroup | 29 |
| `socket_bind_create` | `bind`, `post_bind`, `sock_create`, `socket_post_create`, `inet_csk_clone`, `getsockopt` | `socket() -> bind() -> listen() -> accept() -> getsockopt()` loopback 套件 | 18 |
| `irq_softirq_burst` | `irq_handler_*`, `softirq_*` | 用 `veth`/UDP burst 造 softirq；hard IRQ 作为 best-effort | 8 |
| `syscall_specific` | `nanosleep`, `getpgid` | 直接 syscall loop，不再用 `/bin/true` 代替 | 32 |
| `memory_hotpath` | `mprotect`, `mm_vmscan`, `oom_kill`, `mark_page_accessed`, `add_to_page_cache`, `page_alloc/free` | `mmap/mprotect` + page-cache touch + cgroup memory pressure 组合 | 30 |
| `block_writeback` | `block_io_*`, `blk_account_io_*`, `blk_mq_*`, `writeback_*` | buffered write + fsync + sync + 较大 IO，必要时配 loop file | 17 |
| `security_admin` | `audit_rule_known`, `ptrace`, `mount`, `umount`, `setns` | `ptrace child` + `unshare -m` + `mount/umount` + `setns` 组合 | 13 |

## 7. 设计建议

### 7.1 运行时顺序

建议 runner 侧触发顺序改成：

1. 先跑 manifest 里已有的 `trigger_command`
2. 如果 `run_cnt_delta == 0`，按 `section_name` 选择 `smart_trigger_category`
3. 如果 smart trigger 仍未命中，再退回现有的 coarse auto-trigger sweep

这样做的原因：

- 不破坏现有 manifest 行为
- 可以直接复用已经有效的显式 trigger
- smart trigger 只接管“显式 trigger 打空了”的 case
- 保留当前 coarse fallback 作为最后兜底

### 7.2 分类器接口

建议 runner 内部抽象成：

```text
classify_section_name(section_name) -> smart_trigger_category
run_smart_trigger(category, fixture_cache, iterations) -> bool
```

分类依据只看：

- root
- suffix token
- 若干高优先级子串

不要在第一版引入复杂 DSL；一个按优先级匹配的表就够了。

### 7.3 Fixture 缓存

高成本 category 需要缓存 fixture，避免把 corpus runtime 再拉长一倍：

- `xdp_redirect_path`: 复用单个 `veth` + helper fixture
- `socket_bind_create`: 复用 loopback server helper
- `memory_hotpath`: 复用 tmp dir / cgroup
- `security_admin`: 复用 child process / namespace shell

## 8. 覆盖率估计

### 8.1 直接收益

如果这 `214` 个 did-not-fire 都被 smart trigger 修复，那么：

- comparable pairs 从 `415` 提升到 `629`
- measured-pair coverage 从 `415/705 = 58.9%` 提升到 `629/705 = 89.2%`

换句话说，这项工作不是边角优化，而是会把运行时可比对覆盖率直接抬高 `30.4` 个百分点。

### 8.2 分阶段覆盖

| Phase | Category | 增量覆盖 | 累计覆盖 | 估计工程量 |
| --- | --- | ---: | ---: | --- |
| P1 | `syscall_specific` + `cgroup_lifecycle` + `socket_bind_create` + `block_writeback` | 96 | 44.9% of 214 | 2-3 engineer-days |
| P2 | `memory_hotpath` + `security_admin` | 43 | 65.0% of 214 | 2-3 engineer-days |
| P3 | `xdp_redirect_path` + `irq_softirq_burst` | 75 | 100% of 214 | 3-5 engineer-days |

总计：`7-11 engineer-days`

更现实的结论：

- 如果只做容易且收益稳定的 P1，已经能回收 `96/214 = 44.9%`
- 如果做到 P2，能回收 `139/214 = 65.0%`
- 真正昂贵的是 `xdp` 和 `irq/softirq`

## 9. 风险和边界

- 这 `214` 只覆盖 `did-not-fire`，不包含 `27` 个 `unsupported`；`iter.*` 这类根因是 attach support，不是 trigger workload。
- `49` 个 `exec_ns=0` 也不在本文范围内；那是 measurement path，不是 trigger path。
- `xdp` 是最大收益 bucket，但也是最难的 bucket，因为它不是“换个命令”就能解决，通常需要 helper fixture。
- `security_admin` 里 `audit_rule_known` 是否能在所有环境里稳定触发，取决于权限；建议允许降级 skip。

## 10. 结论

这 `214` 个未触发程序，不是“还缺一些零散 trigger”，而是当前触发策略的抽象层级错了：

- 现在是“program -> 手写 shell command”
- 应该变成“section name -> smart category -> canonical workload”

从分布上看，优先级非常清楚：

1. 先做 `syscall_specific` / `cgroup_lifecycle` / `socket_bind_create` / `block_writeback`
2. 再做 `memory_hotpath` / `security_admin`
3. 最后专门啃 `xdp` / `irq_softirq`

只要 runner 侧把这层 section-name smart trigger 补上，就能把 `415/705` 的可比对覆盖率推进到接近 `629/705`，这是值得单独立项的工作。
