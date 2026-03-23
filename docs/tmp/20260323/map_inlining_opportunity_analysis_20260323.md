# Map Inlining Opportunity Analysis (2026-03-23)

## TL;DR

- 在我调研的真实 BPF workload 中，显式 `BPF_MAP_FREEZE` 几乎不存在。对 `Cilium`、`Katran`、`Tetragon`、`systemd`、`NetBird`、`bcc`、`xdp-tools`、`scx` 等源码镜像做 source-level 搜索，没有发现业务代码调用 `bpf_map_freeze()`；看到的调用点只出现在 `libbpf`、`bpftool`、内核 selftests 和内核/用户态库代码里。
- `libbpf` 确实会自动 freeze `.rodata` 和 `.kconfig` map（`vendor/libbpf/src/libbpf.c:5260-5263`），但这些 map 通常不是 hot-path `bpf_map_lookup_elem()`，而是全局数据/伪 map-value 访问。因此，基于“已经 frozen 的真实业务 map”的 constant inlining 机会很小。
- 真正大的优化空间来自 `dynamic map inlining + invalidation`。真实 workload 里有大量低更新频率的 `config / policy / routing / filter / feature-flag` map，而它们被包路径或事件路径频繁读取。
- corpus 静态统计显示：`565` 个 `.bpf.o` 中共有 `11,556` 个静态 `bpf_map_lookup_elem` call site；真实 workload 子集（去掉 selftests/tutorial/examples）有 `142` 个对象、`11,231` 个静态 lookup call site，lookup-site / BPF-insn 静态密度约 `0.79%`。其中 `Tracee + KubeArmor + Tetragon + Cilium` 四个项目占了 `85.3%` 的静态 lookup site。
- 典型单个 lookup site 在 BPF bytecode 中大约占 `7-8` 条指令（key setup + `ldimm64` map pseudo + `call` + null check + first dereference）。若被常量替换，通常能直接省掉 `6-7` 条；如果这个值又控制分支，还会继续触发 dead branch elimination。
- break-even 很敏感于 invalidation 成本。若一次 re-REJIT 总成本真能做到 `~30us`，则只需大约 `300-600` 次 hot lookup / update 即可回本（按每次 lookup 节省 `100-50ns` 估算）。若必须走完整 re-verify，则我们仓库内设计笔记给出的量级是 `re-verify ~ ms`、`re-JIT ~ 30us`，break-even 会抬升到 `10k-60k` 次 lookup / update。

## 方法与边界

### 方法

1. 源码级调研
   - 搜索 `corpus/repos/` 中真实项目的 `bpf_map_freeze()` / `BPF_MAP_FREEZE` 使用情况。
   - 阅读典型项目中 map 定义、注释和使用点，判断 map 是否属于 low-churn control-plane state。
2. corpus 静态统计
   - 对 `corpus/build/**/*.bpf.o` 做静态分析。
   - 用 ELF 可执行 section 大小 / 8 估算每个对象的 BPF 指令数。
   - 用 `llvm-objdump` 统计 `call 0x1` 的静态 call site 数，作为 `bpf_map_lookup_elem` 调用次数。
3. 文献与官方资料
   - 阅读仓库已有 paper PDF。
   - 补充查阅 `docs.ebpf.io`、LPC 页面和 OpenJDK 官方 wiki。

### 边界与注意事项

- 这里统计的是 **静态 call site 数**，不是动态执行次数。
- 对于像 `Tracee` 这种超大单体 `.bpf.o`，对象级静态 lookup 总数很大，但单次事件只会走其中一小段 handler；因此“对象总数大”不等于“单个 hot path 就被 lookup 主导”。
- 对于 `Tracee`、`Loxilb`、`Suricata`、`KubeArmor` 这类当前仓库里只有 build 产物、没有完整源码镜像的项目，我对 map 的变更频率判断主要基于 BTF map 名称和常见部署语义，属于 **推断**。

## 1. Frozen Map Inlining

### 1.1 真实 workload 中有多少 map 是 frozen 的？

结论：**显式 frozen 的业务 map 基本为 0。**

- 在真实 workload 源码镜像中，没有发现业务代码调用 `bpf_map_freeze()`。
- 搜到的 `bpf_map_freeze()` 调用点只出现在：
  - `vendor/libbpf/src/libbpf.c`
  - `vendor/bpftool/src/map.c`
  - Linux selftests
  - 内核/工具链副本
- 在被调研的真实项目源码中，只能看到 `BPF_MAP_FREEZE` 这个枚举常量出现在头文件或自动生成的 `vmlinux.h` 中，而不是被 workload loader 主动使用。

更重要的是，`libbpf` 会自动 freeze 内部只读 map：

- `vendor/libbpf/src/libbpf.c:5260-5263`
  - 注释明确写着：freeze `.rodata` 和 `.kconfig` map。
- 这说明现实中“被冻结的 map”主要是 libbpf 的内部只读数据 map，而不是应用自己显式 freeze 的 config/policy/routing map。

### 1.2 frozen map 的 lookup 在 hot path 上占多少比例？

结论：**在当前调研到的真实 workload 中，显式 frozen map 的 hot-path helper lookup 占比接近 0。**

原因有两层：

1. 当前几乎没有 workload 主动对业务 map 调用 `BPF_MAP_FREEZE`。
2. libbpf 自动 freeze 的 `.rodata/.kconfig` map 通常不是通过 `bpf_map_lookup_elem()` helper 访问，而是通过全局变量 / map-value 伪装载访问，所以不会出现在 `call 0x1` 统计里。

因此，如果把问题限定为“**已经 frozen 的真实业务 map lookup**”，那当前语料里的优化空间非常窄。

### 1.3 如果把 frozen map lookup 替换为常量，能消除多少条指令？

对典型反汇编模式的观察表明，一个普通 lookup site 常见形态是：

1. 把 key 写到栈上
2. `r2 = fp - off`
3. `r1 = map pseudo`（`ldimm64`，在 BPF 层面算 2 条指令）
4. `call 0x1`
5. `if r0 == 0` 空指针检查
6. 读返回值中的第一个字段

在 `cilium/bpf_xdp.bpf.o`、`katran/balancer.bpf.o`、`tracee/tracee.bpf.o`、`tetragon/bpf_generic_tracepoint.bpf.o` 中都能看到这个模式。按 BPF 指令计，**单个 site 通常占 `7-8` 条指令**；若直接变成常量/直接装载，**常见可直接省 `6-7` 条**。

但是，对“frozen map”这个子问题本身，当前真实 workload 的直接收益基本可以近似为：

- **helper-call site 级别：接近 0**
- **静态可删指令数：接近 0**

因为现有真实 workload 几乎没有把 hot-path 业务 map freeze 起来。

### 1.4 消除 lookup 后能触发多少 dead branch elimination？

对 frozen map 的官方描述很明确：其主要价值不是单纯省掉 helper call，而是让 verifier/optimizer 把内容看成常量标量，从而进一步剪枝。

- `docs.ebpf.io` 的 `BPF_MAP_FREEZE` 文档明确写到：
  - freeze map 的主要目的，是让 verifier 可以做额外优化；
  - frozen map 的内容可被视为 scalar，而不是普通 map-value pointer；
  - 这会让 dead code elimination 成为可能。

但在当前 workload 中，这类机会大多还停留在“**如果把低更新频率 map 做成 frozen/specialized，会很有用**”，而不是“今天已经存在大量 frozen lookup 可剪枝”。

两个非常有代表性的例子：

#### 例子 A: Katran `ctl_array` gate

- `corpus/repos/katran/katran/lib/bpf/xdp_pktcntr.c:45-61`
- 对应反汇编 `corpus/build/katran/xdp_pktcntr.bpf.o` 总共只有 `22` 条 BPF 指令：
  - 第 5-10 条完成 `ctl_array[0]` 的 lookup + null/value 检查
  - 若开关关闭，直接返回 `XDP_PASS`
  - 若开关打开，再做第二次 lookup 更新计数器

如果 `ctl_array[0]` 能被看成编译期常量 `0`，这个函数的 hot path 基本可坍缩成：

- `r0 = XDP_PASS`
- `exit`

也就是从 `22` 条几乎缩到 `2` 条，连第二个 map lookup 都一并被删掉。  
这说明 **“常量传播触发的分支剪枝”** 往往比“单独省一个 helper call”更值钱。

#### 例子 B: Cilium agent liveness gate

- `corpus/repos/cilium/bpf/lib/config_map.h:10-26, 43-50`
- `corpus/repos/cilium/bpf/lib/l2_responder.h:63-72`

`handle_l2_announcement()` 先读取 `RUNTIME_CONFIG_AGENT_LIVENESS`：

- 如果为 `0`，直接 `return`
- 如果超时，也直接 `return`
- 只有通过这个 gate，后面才会继续走 responder map 的 lookup 和 ARP/ND 回复逻辑

因此，若这个配置槽位被 specialization 成编译期常量，后续整段 responder 逻辑都可能被 verifier/optimizer 剪掉。

### 1.5 有没有已有 paper / benchmark 测量过 map lookup 开销？

有，而且结论对这个问题很关键。

#### 直接测 map access 成本的论文

`Demystifying Performance of eBPF Network Applications` 给出了很有价值的数字：

- `ARRAY`: `3.9 +- 0.8 ns`
- `HASH`: `18.8 +- 1.2 ns`
- `LRU HASH`: `19.2 +- 1.4 ns`

同一篇论文还指出：

- JIT 在可能时会对 map access 做已有优化；
- 对 `ARRAY`，helper call 可以被“内联式”替换，访问时间改善约 `20%`；
- 对 `HASH` / `LRU HASH`，helper 会被替换成对内部例程的直接调用，改善约 `8%` / `4%`。

这有两个启示：

1. **map type 很重要**。`ARRAY` 本来就便宜，进一步 inline 的边际收益较小；`HASH/LPM` 一类的收益更大。
2. **Linux JIT 已经做了一部分 map-access lowering**。因此真正的增量收益，不仅来自去掉 helper call，也来自 null-check 消除、常量传播和分支剪枝。

#### 研究 map access pattern / update conflict 的论文

`Understanding Performance of eBPF-based Applications` 更强调：

- map update 的额外成本不只是函数调用；
- 共享 `ARRAY` map 在多核下会因为 cache-line invalidation 增加 latency；
- `ARRAY` vs `PERCPU ARRAY` 的优劣高度依赖工作集大小、写冲突和访问模式。

这意味着：

- 对低更新频率 config/policy map，specialization 很有希望；
- 对高写入 churn 的 `ct_map`、stats map、runtime state map，lookup 本身未必是主要瓶颈，cache/memory 行为才是。

### 1.6 小结

如果只看“**现有 workload 里已经 frozen 的 map**”，优化空间偏小，原因不是 map inlining 没价值，而是 **真实 workload 今天几乎没把 hot-path 业务 map freeze 起来**。  

也就是说：

- `frozen map constant inlining` 在 **当前生态的立即收益** 不大；
- 但它证明了一个方向：**一旦 map 内容在一段时间里足够稳定，常量传播 + DCE 能非常值钱**；
- 这正好把焦点引向下一节的 `dynamic map inlining + invalidation`。

## 2. Dynamic Map Inlining + Invalidation

### 2.1 哪些 map 在真实部署中很少被修改？

下面给出按项目划分的 low-churn map 候选。

| 项目 | 低更新频率候选 | 证据 | 推断的更新节奏 | 适合 inline? |
|---|---|---|---|---|
| Cilium | `cilium_runtime_config` 的部分槽位，尤其 `RUNTIME_CONFIG_UTIME_OFFSET` | `corpus/repos/cilium/bpf/lib/config_map.h:10-26` 注释说这是全局 pinned runtime config，供所有 datapath 程序共享 | `UTIME_OFFSET` 接近 startup/rare；`AGENT_LIVENESS` 是秒级 heartbeat | 部分适合；必须做到 **slot-level**，不能把整张 map 一刀切 |
| Katran | `ctl_array`；部分 `vip_map` / `reals` / `server_id_map` | `corpus/repos/katran/katran/lib/bpf/control_data_maps.h:31-41` 把 `ctl_array` 定义为控制数据；`xdp_pktcntr.c:51-59`、`balancer_helpers.h:54-59` 显示其直接控制 hot path | `ctl_array` 多为 startup / rare；后端健康状态常是秒级到分钟级；VIP/reals 多为运维事件驱动 | `ctl_array` 很适合；VIP/reals 中等适合，需谨慎 invalidation |
| Tetragon | `tg_conf_map`、`config_map`、`filter_map`、`policy_filter_maps` | `environ_conf.h:32-35` 注释写明 “startup and environment discovery only”；`generic_maps.h:43` 注释写明 size-1 array 会被 verifier 改写成 direct load；`policy_filter.h:34-37` 明确是 policy->cgroup 关系 | startup-only 到 policy lifecycle（分钟/小时/事件驱动） | 很适合；其中 size-1 array 已经部分吃到现有 verifier rewrite 红利 |
| Tracee | `config_map`、`netconfig_map`、`policies_config_map`、`uid/pid/ns/comm/binary/..._filter`、以及大量 `*_version` map | 来自 `tracee.bpf.o` BTF map 名称；同时存在 `*_version` map 是非常强的信号，说明控制面本身就把“版本变化”显式建模了 | 过滤器/策略一般是事件驱动、分钟级到小时级；不是每事件修改 | 很适合；尤其适合做 **version-based invalidation** |
| Loxilb | `rt_v4_map`、`rt_v6_map`、`fw_v4_map`、`fw_v6_map`、`nh_map`、`polx_map`、`nat_map` | 来自 `llb_ebpf_main.bpf.o` 的 BTF map 名称；这些显然是路由/防火墙/策略/邻接状态 | 路由和策略通常是控制面事件驱动；steady-state 下分钟/小时级并不少见 | 适合；但 `ct_map` 明显不适合 |
| systemd | `userns_mnt_id_hash`、`userns_setgroups_deny`、`sd_bind_allow`、`sd_bind_deny`、`sd_restrictif`、`cgroup_hash` | `userns-restrict.bpf.c:33-39` 明确这是 userspace allowlist；`userns-restrict.c:236-276, 383-385` 由用户态在配置变更时更新 | 服务启动/停止、namespace 生命周期、管理员配置变更 | 很适合 |
| NetBird | `nb_map_dns_ip`、`nb_map_dns_port`、`nb_wg_proxy_settings_map`、`nb_features` | 来自 `prog.bpf.o` BTF map 名称，语义上就是 DNS / proxy / feature settings | startup / reconfigure-only | 很适合 |
| Suricata | `cpus_available`、`cpus_count` | 来自 `xdp_lb.bpf.o` BTF map 名称 | startup-only 或极低频 | 很适合 |

与此同时，有一类 map 明显 **不适合** dynamic inlining：

- `conntrack / ct_map`
- `stats` / `counter` / `percpu stats`
- `execve_map` / `task_info_map` / `proc_info_map`
- ringbuf / event / scratch / temporary buffer map

这些 map 要么每包/每事件改，要么承担 runtime state，不应拿来做 speculative constantization。

### 2.2 map update 频率通常是多少？

能从公开论文里直接拿到“每秒/每分钟/每小时”的精确分布其实很少，真实系统更多是 **按语义分层**：

#### A. startup-only / environment-discovery-only

- `Tetragon tg_conf_map` 最典型，源码注释直接说只在 startup / environment discovery 时由 userspace 设置。
- `NetBird` 的 feature / DNS / proxy settings 也明显属于这一类。
- `Suricata` 的 CPU 配置 map 也更像启动时填充。

这个层次通常是：

- **每次程序启动 1 次**
- 或 **极少量人工 reconfigure**

#### B. event-driven control-plane updates

- `systemd` allow/deny map
- `Tracee` policy/filter map
- `Tetragon` policy / cgroup filter map
- `Loxilb` routing / firewall / policy map

这一类更像：

- **按配置变更触发**
- steady-state 下常见是 **分钟到小时级**
- 在运维变更窗口中才会短时间 burst

#### C. 秒级心跳 / 健康状态

- `Cilium RUNTIME_CONFIG_AGENT_LIVENESS`
- Katran 的后端健康状态、部分 control-plane 标志

这一类常见是：

- **每秒到每数秒**
- 比 startup-only 频繁很多，但相对 packet/event path 仍然是低频

### 2.3 30us re-REJIT vs 50-100ns lookup 的 break-even

最简单的回本条件是：

```text
lookup_rate * saved_per_lookup > update_rate * rejit_cost
```

等价地：

```text
每次更新至少需要省下的 lookup 次数 = rejit_cost / saved_per_lookup
```

#### 按用户给定假设（`~30us` verify + JIT, `50-100ns` / lookup）

| re-REJIT 成本 | 每次 lookup 节省 `100ns` | `50ns` |
|---|---:|---:|
| `30us` | `300` 次 / update | `600` 次 / update |

这其实很低。

- 如果某个 map 每秒只更新一次，那么只要 hot path 每秒能命中 `600` 次 lookup，就回本。
- 对网络 datapath 来说，`600` 次/s 几乎可以忽略不计。

#### 更保守地看：考虑论文中更低的 map access 数字

`Demystifying Performance...` 给出的 access time 下界是：

- array 约 `3.9ns`
- hash / lru-hash 约 `19ns`

若真正能省掉的只是 lookup 本身，而没有额外的 DCE 收益，则 break-even 会变成：

| re-REJIT 成本 | `20ns` | `4ns` |
|---|---:|---:|
| `30us` | `1,500` 次 / update | `7,500` 次 / update |

这仍然不高，尤其对 packet path。

#### 但如果必须走完整 re-verify，情况会明显变化

仓库内设计笔记 `docs/kernel-jit-optimization-plan.md:587` 明确写到：

- `re-verify ~ ms 级`
- `re-JIT ~ 30us`

所以若真实机制不是“30us 总成本”，而是“30us JIT + ms 级 verifier”，则回本门槛会被抬高一个数量级以上：

| 总 invalidation 成本 | `100ns` | `50ns` | `20ns` | `4ns` |
|---|---:|---:|---:|---:|
| `30us` | `300` | `600` | `1,500` | `7,500` |
| `1ms` | `10,000` | `20,000` | `50,000` | `250,000` |
| `3ms` | `30,000` | `60,000` | `150,000` | `750,000` |

### 2.4 把 break-even 换成“每秒能不能回本”

这个视角更接近真实部署。

以 `50ns` 节省为例：

| 更新频率 | `30us` 成本需要的 lookup/s | `1ms` 成本 | `3ms` 成本 |
|---|---:|---:|---:|
| 每秒 1 次更新 | `600/s` | `20,000/s` | `60,000/s` |
| 每 10 秒 1 次更新 | `60/s` | `2,000/s` | `6,000/s` |
| 每分钟 1 次更新 | `10/s` | `333/s` | `1,000/s` |

这说明：

- 对 **分钟级 / 小时级变更** 的 config / policy / routing map，哪怕 invalidation 需要完整 re-verify，也通常是划算的。
- 对 **秒级 heartbeat** 类型 map，收益高度依赖两件事：
  - lookup 是否真的在超热路径上；
  - 这个 map 是否被很多程序共享，从而一改就要 re-JIT 多个程序。

### 2.5 一个非常关键的现实因素：共享 map 会把 invalidation 成本线性放大

`Cilium` 的 `cilium_runtime_config` 注释明确写着：

- 这是一个 **global pinned array**
- 被 **all Cilium BPF programs on the node** 共享  
  见 `corpus/repos/cilium/bpf/lib/config_map.h:10-13`

这意味着：

- 若你把同一个 slot inline 进多个程序，单次 update 的真实成本不是 `R`，而是 `N_programs * R`。
- 因此像 `RUNTIME_CONFIG_AGENT_LIVENESS` 这种 **秒级更新、又被多个程序共享** 的槽位，并不是最优候选。
- 相反，像 `RUNTIME_CONFIG_UTIME_OFFSET` 这种 **极低更新频率** 的槽位，就更适合 specialization。

这一点说明：**dynamic inlining 应该是“按 map slot / key specialization”，而不是“整张 map 特化”。**

### 2.6 JVM deoptimization 对我们的启示

OpenJDK 的 `LoopPredication` 页面描述了一个非常贴近这里的思路：

- 把 loop-invariant check 提到循环外；
- 在入口放一个 predicate；
- 条件不满足时走 `uncommon trap`；
- 从而把循环体内部的检查全部消掉。

这和 dynamic map inlining 很像：

1. **先做投机假设**
   - 假设某个 map slot / key 在一段时间内稳定。
2. **在 hot path 使用 specialized 版本**
   - 用常量值替代 lookup。
3. **当假设失效时 cheap invalidation**
   - 触发 fallback / deopt，而不是让热路径每次都付检查成本。

对 BPF 来说，最有价值的 JVM 经验不是“JIT 本身”，而是下面这些工程原则：

- **依赖粒度要细**：按 map、最好按 key/slot 建依赖，避免“一次 update 让所有程序全失效”。
- **保留通用 fallback 版本**：更新发生时可以先切回 generic version，再异步生成新的 specialized version。
- **优先投机 low-churn state**：不要对高 churn runtime state 做 aggressive specialization。
- **批量失效 / 合并更新**：多次 control-plane update 可以 coalesce，再做一次 re-REJIT。
- **版本号优于内容比较**：Tracee 已经显式维护大量 `*_version` map，这是一种天然的 invalidation substrate。

### 2.7 这一方向的真实机会到底多大？

我的结论是：

- **比 frozen-map inlining 大得多，而且是真实 workload 里最值得做的方向。**

原因如下：

1. 低更新频率 map 在真实 workload 中非常常见。
2. 很多这类 map 就在 hot path 上充当 gate、policy 决策或 metadata source。
3. 这些 map 一旦常量化，不仅省掉 lookup，还能剪掉分支和后续次级 lookup。
4. 在分钟级甚至秒级以下的 update 频率下，只要 specialization 覆盖的是 packet/event hot path，回本门槛并不高。

我会把优先级排序成：

1. `startup-only` / `reconfigure-only` 的小型 config map
2. 有显式 version counter 的 filter / policy map
3. routing / firewall / policy 这类控制面 map
4. 秒级 heartbeat / health map
5. 高 churn runtime state map（基本不建议）

## 3. 相关 paper 是否讨论过类似优化？

### 总结表

| 工作 | 是否直接讨论 map inlining / runtime specialization？ | 结论 |
|---|---|---|
| K2 (SIGCOMM'21) | 否 | 重点是 map/helper 语义建模、等价性检查和 superoptimization，不是 runtime specialization |
| Merlin (ASPLOS'24) | 部分相关，但不是这个问题 | 做通用 compiler optimization（含 constant propagation / DCE），并在 related work 里提到过 domain-specific 的 map-lookup reduction，但 Merlin 自己不是 dynamic map inlining |
| EPSO (ASE'25) | 否 | 是 caching-based superoptimizer / rule-based optimizer，不讨论 runtime invalidation / deopt |
| BCF (SOSP'25) | 否 | 是 verifier / proof / abstraction refinement 方向，与 constant map specialization 没有直接关系 |
| ePass (LPC'25) | 否 | 是 runtime safety instrumentation 框架，不是性能 specialization |
| hXDP (OSDI'20) | 间接相关 | 讨论硬件 offload 中如何实现 maps/helpers；map access 仍然是显式 stateful operation，不是 constant inlining |
| BMC (NSDI'21) | 间接相关 | 展示了 map-heavy、stateful eBPF 应用的真实性能意义，但不优化掉 map access |
| 其他 map 性能论文 | 是，提供成本背景 | 主要是测成本和 access pattern，不是做 runtime specialization |

### 3.1 K2 (SIGCOMM'21)

K2 与 map 的关系在于：

- 它认真建模了 BPF map 和 helper 的语义；
- 引入了 `map type concretization`，用来把不同 map 的访问拆开建模；
- 这样可以让等价性检查和 superoptimization 更可做。

但 K2 没有做：

- frozen map constant propagation
- runtime specialization
- invalidation / deoptimization

所以 K2 更像是“**证明你可以精确理解 map 访问**”，而不是“**利用 map 稳定性做投机优化**”。

### 3.2 Merlin (ASPLOS'24)

Merlin 做的是多层优化框架，和这个问题最近的地方有两点：

1. 它明确讨论了 **constant propagation** 和 **dead code elimination**；
2. 它在 related work 中提到，已有 domain-specific 工作曾针对 traffic control 做过 **减少 map lookup** 的优化。

但 Merlin 本身并没有讨论：

- 基于 `BPF_MAP_FREEZE` 的 specialization
- map 更新后的 invalidation / re-REJIT
- JVM-style deoptimization

所以 Merlin 更像是“**静态编译器优化框架**”，不是“**运行时投机 specialization 框架**”。

### 3.3 EPSO (ASE'25)

EPSO 的关键词是：

- caching-based superoptimization
- 规则发现 + 规则复用
- 低优化时开销

它关注的是：

- 如何更高效地产生 / 复用 rewrite rules
- 如何在优化质量和优化时延之间折中

它没有讨论：

- map value specialization
- runtime invalidation
- deopt / fallback 版本切换

### 3.4 BCF (SOSP'25)

BCF 关注的是 verifier 的精度问题和 proof-guided abstraction refinement。

它和 map 的关系主要体现在：

- 用 `map_lookup(...)` 这样的例子来说明 verifier 如何推理 pointer/range/state；
- 但目标是验证精度，不是性能优化。

因此，BCF 和 “constant map” 只有 **verifier semantics 层面** 的关系，没有优化策略层面的关系。

### 3.5 ePass (LPC'25)

LPC 页面显示，`ePass` 关注的是：

- 扩展 eBPF 程序灵活性
- 通过 runtime checks 弥补 verifier 的静态限制
- 提升 runtime safety

这与 `dynamic map inlining + invalidation` 并不是一条线：

- ePass 是“加检查以放宽可接受程序”
- map inlining 是“去检查 / 去 lookup 以加速 hot path”

### 3.6 hXDP (OSDI'20)

hXDP 非常有用，但用途不同。

它明确讨论了：

- 在 FPGA/NIC 上如何实现 XDP maps 和 helper functions
- map access 如何通过硬件模块提供

它说明：

- maps 在硬件 offload 场景下仍然被当作 **显式的 stateful memory abstraction**
- 不是把 map 变成常量，而是把“访问 map”这件事搬到硬件上做

### 3.7 BMC (NSDI'21)

BMC 不在讨论 map inlining，但它说明了一件重要事实：

- map-heavy、stateful eBPF 应用不是学术玩具，而是现实的性能敏感 workload。

因此，BMC 对本问题的贡献不是直接算法，而是：

- 证明“map access 成本值得被优化”这件事在真实系统里成立。

### 3.8 其他最相关的 paper / benchmark

最相关的其实是两类：

1. **直接测 map access 成本**
   - `Demystifying Performance of eBPF Network Applications`
2. **研究 map access pattern / update conflict / cache 行为**
   - `Understanding Performance of eBPF-based Applications`

它们都不是 map inlining 论文，但它们给了这个问题最关键的数量级背景。

## 4. 我们 corpus 中的 map 使用统计

### 4.1 总体统计

对 `corpus/build/**/*.bpf.o` 的静态分析结果：

| 集合 | 对象数 | 总 BPF 指令数 | 静态 `map_lookup_elem` call site | lookup / insn |
|---|---:|---:|---:|---:|
| 全部 `.bpf.o` | `565` | `1,494,858` | `11,556` | `0.773%` |
| 真实 workload 子集 | `142` | `1,416,489` | `11,231` | `0.793%` |

补充：

- 全部对象里，`194/565` (`34.3%`) 至少包含一个 lookup call site。
- 真实 workload 子集里，`125/142` (`88.0%`) 至少包含一个 lookup call site。
- lookup 密度 `>=1%` 的对象有 `73/142`。
- lookup 密度 `>=2%` 的对象有 `34/142`。
- lookup 密度 `>=3%` 的对象有 `15/142`。

### 4.2 按项目聚合

| 项目 | 对象数 | 总 BPF 指令数 | 静态 lookup site | lookup / insn |
|---|---:|---:|---:|---:|
| Tracee | `2` | `436,457` | `4,555` | `1.044%` |
| KubeArmor | `3` | `357,155` | `2,671` | `0.748%` |
| Tetragon | `23` | `172,508` | `1,403` | `0.813%` |
| Cilium | `3` | `97,621` | `953` | `0.976%` |
| Calico | `8` | `158,995` | `534` | `0.336%` |
| Loxilb | `3` | `77,619` | `280` | `0.361%` |
| bcc | `57` | `23,707` | `262` | `1.105%` |
| coroot-node-agent | `1` | `37,060` | `157` | `0.424%` |
| xdp-tools | `13` | `9,094` | `111` | `1.221%` |
| Katran | `5` | `3,013` | `85` | `2.821%` |
| 其余项目 | - | - | - | - |

最重要的观察是：

- `Tracee + KubeArmor + Tetragon + Cilium` 这四个项目贡献了 `9,582 / 11,231 = 85.3%` 的静态 lookup site。
- 如果想最大化“绝对可优化站点数”，这四个项目是主战场。
- 如果想找“lookup 很可能就是 hot path 主体”的程序，则更要看密度和程序形态，而不是只看总数。

### 4.3 静态 lookup site 最多的对象

| 对象 | BPF 指令数 | 静态 lookup site | lookup / insn |
|---|---:|---:|---:|
| `tracee/tracee.bpf.o` | `436,443` | `4,555` | `1.044%` |
| `KubeArmor/system_monitor.bpf.o` | `323,003` | `2,328` | `0.721%` |
| `cilium/bpf_lxc.bpf.o` | `41,881` | `392` | `0.936%` |
| `KubeArmor/enforcer.bpf.o` | `29,013` | `334` | `1.151%` |
| `cilium/bpf_xdp.bpf.o` | `26,129` | `324` | `1.240%` |
| `cilium/bpf_overlay.bpf.o` | `29,611` | `237` | `0.800%` |
| `tetragon/bpf_generic_tracepoint.bpf.o` | `17,605` | `237` | `1.346%` |
| `tetragon/bpf_generic_uprobe.bpf.o` | `21,548` | `201` | `0.933%` |
| `tetragon/bpf_generic_kprobe.bpf.o` | `19,321` | `190` | `0.983%` |
| `tetragon/bpf_generic_usdt.bpf.o` | `19,633` | `183` | `0.932%` |

这些对象代表的是“**绝对 call site 数多**”。  
但要注意：

- `Tracee` / `Tetragon` 这类对象更像“很多 handler 的总和”；
- `Cilium` / `Katran` / `Loxilb` / `NetBird` 更接近持续运行的 datapath。

### 4.4 lookup 密度最高的对象

| 对象 | BPF 指令数 | 静态 lookup site | lookup / insn |
|---|---:|---:|---:|
| `katran/xdp_pktcntr.bpf.o` | `22` | `2` | `9.09%` |
| `tetragon/bpf_execve_map_update.bpf.o` | `12` | `1` | `8.33%` |
| `systemd/restrict-ifaces.bpf.o` | `38` | `2` | `5.26%` |
| `netbird/prog.bpf.o` | `264` | `13` | `4.92%` |
| `systemd/restrict-fs.bpf.o` | `63` | `3` | `4.76%` |
| `katran/healthchecking_ipip.bpf.o` | `103` | `4` | `3.88%` |
| `tetragon/bpf_exit.bpf.o` | `294` | `10` | `3.40%` |
| `tubular/inet-kern.bpf.o` | `124` | `4` | `3.23%` |
| `calico/xdp_no_log.bpf.o` | `416` | `12` | `2.88%` |
| `katran/healthchecking.bpf.o` | `325` | `9` | `2.77%` |

这张表更接近“**lookup-heavy hot path 候选**”。

### 4.5 哪些程序的 hot path 被 map lookup 主导？

严格地说，仅凭对象级静态统计，不能证明“主导 cycle”。  
但结合程序形态、反汇编和 map 语义，我认为可以分两类看：

#### A. lookup 很可能主导 critical path 的小程序

这些对象有两个共同特征：

- BPF 指令总数很小；
- 逻辑结构接近“读几个 map -> 判定 -> 返回”。

最典型的是：

- `katran/xdp_pktcntr.bpf.o`
- `systemd/restrict-ifaces.bpf.o`
- `systemd/restrict-fs.bpf.o`
- `netbird/prog.bpf.o`
- `katran/healthchecking_ipip.bpf.o`
- `katran/healthchecking.bpf.o`
- `suricata/xdp_filter.bpf.o`
- `suricata/xdp_lb.bpf.o`

在这类程序里，map lookup 即使只占 2%-9% 的 **静态指令数**，也很可能占掉更高的 **动态 cycle 比例**，因为一次 hash/array lookup 远比一次简单 ALU/branch 指令贵。

#### B. lookup site 很多，但 hot path 需要按 handler 拆分的大对象

这类对象包括：

- `tracee/tracee.bpf.o`
- `KubeArmor/system_monitor.bpf.o`
- `tetragon/bpf_generic_*`
- `cilium/bpf_lxc.bpf.o`
- `cilium/bpf_xdp.bpf.o`

对它们的结论应该更谨慎：

- **绝对 lookup site 很多**，说明这类程序体系对 map 很依赖；
- 但真正是否“hot path dominated”，必须按具体 hook / packet path / event path 来拆开看。

其中：

- `Cilium/Katran/Loxilb/NetBird/Suricata` 更像 packet path，lookup-heavy 更可能直接转化为 datapath 周期。
- `Tracee/Tetragon/KubeArmor/systemd` 更像 tracing/security/policy path，lookup-heavy 也重要，但 hotness 更依赖事件分布。

## 5. 结论与优先级建议

### 5.1 Frozen map inlining 的真实空间

如果问题限定为“**真实 workload 中已经 frozen 的 map**”：

- 结论是 **机会很小**。
- 不是因为优化没用，而是因为 **现在几乎没人 freeze 业务 hot-path map**。
- 今天真正被冻结的 map 主要是 libbpf 的 `.rodata/.kconfig`，它们通常不走 helper lookup。

所以：

- 这条线在当前生态里更像 **补完现有 verifier/JIT 能力**；
- 但它不是最值得优先投入的方向。

### 5.2 Dynamic map inlining + invalidation 的真实空间

如果问题放宽到“**运行后很少改，但今天没 freeze 的 map**”：

- 结论是 **机会很大，而且是真实 workload 中最值得做的 map specialization 方向**。

最有价值的目标是：

- startup-only config map
- policy/filter map
- routing/firewall/policy control-plane map
- feature flag / allowlist / denylist map

最不值得碰的是：

- conntrack
- stats/counters
- runtime process/task state
- event/scratch/buffer map

### 5.3 我对优先实现顺序的建议

1. 先做 **slot/key 级** specialization，不做 whole-map specialization。
2. 先挑 **startup-only** 和 **versioned filter/policy** map。
3. 失效机制优先走 **version-based dependency tracking**，不要做粗粒度全局失效。
4. 始终保留 generic fallback 版本，更新先 fallback，再异步生成 specialized 版本。
5. 对秒级 heartbeat/shared map（例如 Cilium liveness）默认谨慎，除非能证明：
   - 只有少量程序依赖它；
   - 单次 specialization 能剪掉非常大的 hot subtree。

## 参考资料

### 官方资料

- `BPF_MAP_FREEZE` 文档: <https://docs.ebpf.io/linux/syscall/BPF_MAP_FREEZE/>
- `libbpf bpf_map_freeze()` 文档: <https://docs.ebpf.io/ebpf-library/libbpf/userspace/bpf_map_freeze/>
- OpenJDK HotSpot LoopPredication: <https://wiki.openjdk.org/spaces/HotSpot/pages/11829293/LoopPredication>
- LPC 2025 eBPF track / ePass: <https://lpc.events/event/19/sessions/235/>

### 论文

- K2 (SIGCOMM'21): <https://doi.org/10.1145/3452296.3472929>
- Merlin (ASPLOS'24): <https://doi.org/10.1145/3620666.3651387>
- EPSO (ASE'25 preprint): <https://arxiv.org/abs/2511.15589>
- BCF (SOSP'25): <https://doi.org/10.1145/3731569.3764796>
- hXDP (OSDI'20): <https://www.usenix.org/conference/osdi20/presentation/brunella>
- BMC (NSDI'21): <https://inria.hal.science/hal-03361644v1>
- Demystifying Performance of eBPF Network Applications: <https://doi.org/10.1145/3749216>
- Understanding Performance of eBPF-based Applications: `docs/reference/papers/67-understanding-performance-of-ebpf-based-applications.pdf`

### 仓库内直接证据

- `vendor/libbpf/src/libbpf.c:5260-5263`
- `corpus/repos/cilium/bpf/lib/config_map.h:10-26, 43-50`
- `corpus/repos/cilium/bpf/lib/l2_responder.h:63-72`
- `corpus/repos/katran/katran/lib/bpf/xdp_pktcntr.c:45-61`
- `corpus/repos/katran/katran/lib/bpf/balancer_helpers.h:54-59`
- `corpus/repos/katran/katran/lib/bpf/control_data_maps.h:31-41`
- `corpus/repos/tetragon/bpf/process/generic_maps.h:43-56`
- `corpus/repos/tetragon/bpf/lib/environ_conf.h:32-41`
- `corpus/repos/tetragon/bpf/process/policy_filter.h:34-37, 54-75`
- `corpus/repos/systemd/src/nsresourced/bpf/userns-restrict/userns-restrict.bpf.c:33-39`
- `corpus/repos/systemd/src/nsresourced/userns-restrict.c:236-276, 383-385`
- `docs/kernel-jit-optimization-plan.md:587`
