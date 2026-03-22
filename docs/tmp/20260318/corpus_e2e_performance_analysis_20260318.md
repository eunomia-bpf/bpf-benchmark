# Corpus / E2E 性能分析（2026-03-18）

输入文件：

- `corpus/results/corpus_recompile_authoritative_20260313.json`
- `corpus/policies/**`
- `e2e/results/tracee_authoritative_20260313_postfix.json`
- `e2e/results/bpftrace_authoritative_20260312.json`
- `e2e/results/scx_authoritative_20260311.json`
- `e2e/results/xdp_forwarding_authoritative_20260312.json`
- Tetragon 额外参考：`e2e/results/archive/tetragon-e2e-v2-fixed.json`、`e2e/results/archive/tetragon-real-e2e.md`
- 背景文档：`docs/kernel-jit-optimization-plan.md`、`CLAUDE.md`

---

## 1. Corpus 现状

### 1.1 Topline

- 共有 `152` 个 measured program-pair。
- 整体 exec geomean：`1.0463x`
- 分布：`81` winner，`49` regressor，`22` tie。
- 只看实际发生 recompile 的 program，applied-only geomean 是 `1.0238x`。

按 source project 分组的 geomean：

| Source | Count | Geomean |
| --- | ---: | ---: |
| calico | 59 | `1.0972x` |
| katran | 5 | `0.8718x` |
| libbpf-bootstrap | 1 | `0.9437x` |
| linux-selftests | 59 | `1.0047x` |
| real_world_code_size | 1 | `1.0592x` |
| suricata | 1 | `0.8571x` |
| tracee | 2 | `0.9904x` |
| xdp-tools | 4 | `1.0624x` |
| xdp-tutorial | 20 | `1.0914x` |

### 1.2 当前 corpus policy 到底是什么

当前 `corpus/policies/` 不是 v2 的 `default: apply + families: {cmov: skip}` 了，而是全量 `version: 3` 显式 site allowlist：

- policy 文件总数：`582`
- 全部都是 `version: 3`
- `216` 个 policy 是 `sites: []`
- `366` 个 policy 是非空 allowlist
- 文件里没有 `default:` 和 `families:` 字段；语义是“只有 `sites:` 里列出的 site 才会 apply”

生成策略来自 `corpus/generate_default_policies.py`：

- 生成器注释写得很直接：`keep every discovered site except CMOV`
- 也就是“扫描到的所有非-CMOV site 全进 allowlist”
- 这和 micro 最后的 tuned policy 不同：micro 是按 benchmark 清 regressor；corpus 现在是全局粗暴地保留所有非-CMOV

从 policy 文件本身统计到的 allowlist family 总量：

- `wide`: `2832`
- `branch-flip`: `2034`
- `rotate`: `1820`
- `endian`: `1029`
- `extract`: `344`
- `lea`: `14`

但在这次 authoritative corpus run 里，真正落到 measured program 上并实际 apply 的 family 只有三类：

- `wide`: 16 个 applied program，subset geomean `1.1110x`
- `endian`: 24 个 applied program，subset geomean `1.0278x`
- `extract`: 16 个 applied program，subset geomean `0.9767x`

结论：

- `CMOV` 已经不像 micro 早期那样激进了，当前 corpus policy 全局排除了 CMOV。
- 但它仍然有“类似 micro 的过于激进”问题，只是对象换成了 `extract/endian/branch-flip` 这类非-CMOV form：生成器是无差别全开，缺少 per-program cleanup。
- 从实测看，`wide` 是净正向，`endian` 轻微正向，`extract` 已经偏负。

### 1.3 Winner / Regressor

Top winners：

| Ratio | Source | Program | 备注 |
| ---: | --- | --- | --- |
| `4.0000x` | xdp-tutorial | `xdp_router_func` | 无 policy，branch-flip-only，明显是噪声型大值 |
| `2.7143x` | linux-selftests | `get_netns_cookie_cgroup_skb` | 无 policy |
| `2.0987x` | calico | `calico_tc_main` | 有 policy，但这行本身没实际 apply |
| `2.0000x` | linux-selftests | `tcx5` | 无 policy |
| `1.7143x` | linux-selftests | `xdp_redirect_to_222` | 无 policy |
| `1.6859x` | calico | `calico_tc_skb_drop` | 有 policy，但这行本身没实际 apply |
| `1.6000x` | calico | `calico_xdp_drop` | 无 policy |
| `1.6000x` | linux-selftests | `decap_sanity` | policy 命中但 0 site apply |
| `1.5833x` | xdp-tools | `xdp_probe_prog` | policy 命中但 0 site apply |
| `1.5714x` | xdp-tutorial | `xdp_pass_func` | 无 policy |

Top regressors：

| Ratio | Source | Program | 备注 |
| ---: | --- | --- | --- |
| `0.3125x` | linux-selftests | `pkt_ptr` | policy 是 `sites: []` 空 policy，实际没 apply |
| `0.4545x` | linux-selftests | `xdp_prog1` | 无 policy |
| `0.5385x` | xdp-tutorial | `xdp_sock_prog` | 无 policy，branch-flip-only |
| `0.5580x` | linux-selftests | `test_pkt_access` | 无 policy / 另一 object 的同名程序 0 site |
| `0.5667x` | katran | `balancer_ingress` | stale policy，`selected 0 of 94 eligible rules` |
| `0.6452x` | linux-selftests | `res_spin_lock_test_BA` | 无 policy |
| `0.6667x` | linux-selftests | `xdp_count_pkts` | 无 policy |
| `0.6923x` | xdp-tutorial | `xdp_drop_func` | 无 policy，branch-flip-only |
| `0.6962x` | linux-selftests | `res_spin_lock_test` | policy 命中但 0 site apply |
| `0.7143x` | calico | `calico_xdp_accepted_entrypoint` | 无 policy，branch-flip-only |

最需要区分的三类 regressors：

1. **空 policy / no-op regressors**
   - 代表：`pkt_ptr 0.3125x`
   - `pkt_ptr.policy.yaml` 只有一个 `cmov` site，因此生成器输出 `sites: []`
   - 运行时 `requested_families=[]`，`applied=False`
   - 这类不是“policy apply 后回归”，而是 stock/no-op + 短基线噪声

2. **stale policy regressors**
   - 代表：`katran/balancer_ingress 0.5667x`、`xdp-tutorial/_fix_port_egress 0.75x`
   - 文件存在，但 live site 一个都没对上
   - 这类优先级是 refresh policy，不是微调 family

3. **高置信 actual-apply regressors**
   - 代表：`__encap_sit_none 0.75x`、`__encap_ipip6_none 0.8519x`、`__encap_ip6gre_none 0.8571x`、`xdp_fwd_fib_full 0.7895x`
   - 这类才最像 micro 里应该直接清掉的 regressor

### 1.4 Katran 0.872x 的根因

`katran` 共有 5 行 measured row：

| Program | Section | Ratio | Policy | Live sites |
| --- | --- | ---: | --- | ---: |
| `balancer_ingress` | xdp | `0.5667x` | 有 | 94 |
| `healthcheck_encap` | tc | `1.3333x` | 有 | 9 |
| `healthcheck_encap` | tc | `1.0000x` | 无 | 3 |
| `pktcntr` | xdp | `0.8571x` | 无 | 2 |
| `xdp_root` | xdp | `0.7778x` | 无 | 0 |

`balancer_ingress` 是 `katran 0.8718x` 的主导项。它的情况非常明确：

- 当前 policy 文件只列了 `10` 个 site：
  - `wide=4`
  - `endian=4`
  - `extract=2`
- 但 authoritative run 里的 live scan 是：
  - `branch-flip=56`
  - `rotate=20`
  - `cmov=8`
  - `endian=4`
  - `wide=4`
  - `bitfield(extract)=2`
  - 合计 `94` site
- 运行时日志明确报：
  - `policy site ... was not found in the live program`
  - `policy selected 0 of 94 eligible rules`
- baseline / recompile exec_ns 是 `34ns -> 60ns`

结论：

- 这不是 micro 那种“policy 太激进，apply 后回归”。
- 这是 **policy artifact 过时** 导致的 **0-apply + 短基线噪声**。
- `healthcheck_encap` 也是同类问题：当前文件只保留 1 个 endian site，但 live scan 已经是 9 个 site，最终同样 0-apply。

如果只把 `balancer_ingress` 这一行拉回 `1.0x`，katran source geomean 会从 `0.8718x` 回升到 `0.9767x`。

### 1.5 有没有“完全没有 policy 但有 sites”的 corpus program

有，`14` 个。

其中 `11` 个是 branch-flip-only，不像 micro 的 `rotate64_hash` 那样是高价值遗漏：

- calico：`calico_xdp_accepted_entrypoint`、`calico_xdp_drop`
- katran：`healthcheck_encap`、`pktcntr`
- xdp-tutorial：`xdp_abort_func`、`xdp_drop_func`、`xdp_pass_func`、`xdp_router_func`、`xdp_sock_prog`、`xdp_stats1_func`

真正值得补 policy 的只有 3 个非 branch-flip 候选：

| Program | Family | 当前 ratio | 结论 |
| --- | --- | ---: | --- |
| `linux-selftests/decap_f` | `cmov + wide + endian` | `1.0000x` | 值得补一份 policy 做 sweep |
| `linux-selftests/cls_ingress` | `endian` | `1.0000x` | 可补，但收益预期不大 |
| `linux-selftests/test_pkt_access` | `cmov` | `1.0000x` | 不优先；只是 CMOV-only |

结论：

- **有遗漏，但没有看到像 micro `rotate64_hash` 那样的高置信大漏项。**
- 真正值得补的只有 `decap_f` / `cls_ingress` 两个非 branch-flip 候选。

---

## 2. E2E 现状

### 2.1 Tracee

文件：`e2e/results/tracee_authoritative_20260313_postfix.json`

直接从该文件读出的 workload 结果：

| Workload | App delta | BPF avg ns delta |
| --- | ---: | ---: |
| `exec_storm` | `+5.97%` | `-7.11%` |
| `file_io` | `+1.51%` | `-1.00%` |
| `network` | `+3.26%` | `-0.87%` |

补充统计：

- app throughput geomean：`1.0357x`
- BPF avg ns geomean：`0.9696x`
- 程序数：`13`
- 配到 policy 的 program：`11`
- 实际 recompile 的 program：`11`
- 实际 apply 的 site：`42`

这 11 个 configured program 的 live site 组成：

- `branch-flip=37`
- `cmov=88`
- `extract=5`
- 合计 `130`

最终 policy remap 后真正 apply 的是：

- `branch-flip=37`
- `extract=5`
- `cmov=0`

判断：

- 如果坚持 `CMOV` 继续 skip，那么当前 Tracee policy **已经基本吃满了全部非-CMOV opportunity**。
- 所以 `Tracee +6.28% 能不能更高` 的答案是：
  - **保守答案：空间不大。**
  - **激进答案：只有在你愿意做 selective-CMOV sweep 时，才可能再往上。**
- 我不建议为了当前论文主线先动 Tracee policy；现在更像“已接近局部最优”。

注意一个数据源冲突：

- `tracee_authoritative_20260313_postfix.json` 这份文件里是 `+5.97% / +1.51% / +3.26%`
- `docs/kernel-jit-optimization-plan.md` 的摘要 later 写成了 `+6.28% / +7.00% / +1.44%`
- 以仓库当前能直接验证的 JSON 为准，应先用前者

### 2.2 Tetragon

当前 **没有 top-level authoritative Tetragon JSON**。`e2e/results/README.md` 顶层只保留了 4 份权威 JSON，Tetragon 需要看 archive。

可用 artifact 有两份：

1. `e2e/results/archive/tetragon-real-e2e.md`（2026-03-11）
2. `e2e/results/archive/tetragon-e2e-v2-fixed.json`（2026-03-12）

#### 2026-03-11 早期 daemon-mode 结果

- overall mean app throughput：`+3.8%`
- `connect_storm`: `-10.2%`
- 当时文档结论把它解释成 `CMOV regression`

#### 2026-03-12 v2-fixed 归档结果

- 4 个 workload 的 app throughput geomean：`0.9868x`
- `connect_storm`: `-50.5%`
- `file_io`: `-0.008%`
- `open_storm`: `-0.245%`
- `stress_exec`: `+92.1%`
- 程序数：`5`
- 配到 policy：`3`
- 实际 recompile：`3`
- live sites：`52 = branch-flip 37 + cmov 15`
- 归档 run 中实际 apply 的 counts：`43 = branch-flip 28 + cmov 15`

现在再看当前磁盘上的 Tetragon policy 文件，会发现它们又变了：

- `event_execve.policy.yaml`：只保留 `4` 个 `branch-flip`，显式排除了 `65` 个 `cmov`
- `event_wake_up_new_task.policy.yaml`：只保留 `5` 个 `branch-flip`
- `execve_map_update.policy.yaml`：空 policy

所以 Tetragon 当前的真实状态是：

- **历史上 `connect_storm -10.2%` 确实可能和 CMOV 有关**
- **但仓库里最新保留下来的更晚分析（plan #140）又说明大回归更像 workload 噪声**
- **更关键的是：当前 on-disk policy 已经不再等价于 archive 里跑过的 policy**

我的判断：

- `Tetragon：为什么 connect_storm -10.2%？是不是 CMOV 回归？可以 skip 吗？`
  - **历史 2026-03-11 结果：是，CMOV 是合理怀疑对象。**
  - **当前 2026-03-18 仓库状态：应该先 refresh policy 并显式 skip CMOV，再 rerun。**
  - 现在直接根据 archive 数字下结论不安全，因为 policy 已经换了，artifact 也有明显漂移。

### 2.3 bpftrace

文件：`e2e/results/bpftrace_authoritative_20260312.json`

这份 authoritative 文件的结论非常干净：

- 只选了 `2` 个 script
- 总 site 数 `12`
- `12` 个全都是 `CMOV`
- 两个 script 的 rejit phase 都被标成 `skipped`
- 原因都是 `policy filtered all live sites`
- top-level summary 的 `speedup_geomean` 是 `null`

对应 policy 文件：

- `corpus/policies/bpftrace/open_latency/kretprobe_do_sys_openat2.policy.yaml`
- `corpus/policies/bpftrace/scheduler_latency/tracepoint_sched_sched_switch.policy.yaml`
- 两个文件都是 `sites: []`

所以：

- `bpftrace 0.992x：纯 CMOV 导致，能不能 skip CMOV 改善？`
  - **当前 authoritative JSON 里根本没有 apply CMOV。**
  - **skip CMOV 已经做了。**
  - 这份文件不能支持“再 skip 一点就会更好”的说法。
- 现在 bpftrace 的问题不是 policy 太激进，而是 **workload 本身只暴露了 CMOV，导致当前 policy 下完全没有可测正向信号**。

### 2.4 scx

文件：`e2e/results/scx_authoritative_20260311.json`

结论：

- `BPF_PROG_JIT_RECOMPILE: Invalid argument`
- `13` 个 requested program，`7` 个 site-bearing program
- live sites `28 = cmov 27 + lea 1`
- 实际 applied program：`0`
- `comparison.comparable = false`
- 没有 post-ReJIT workload measurement

所以：

- `scx` 现在不是 policy 优化问题
- blocker 是 **struct_ops 路径在当前 kernel 上根本不支持这条 recompile 流**
- 在这个前提没变之前，不值得做 policy 级 rerun

### 2.5 XDP forwarding

顶层文件：`e2e/results/xdp_forwarding_authoritative_20260312.json`

问题是这份 top-level authoritative JSON **不是实测结果，而是 dry-run**：

- `mode = dry-run`
- 只给了 topology / setup plan
- 甚至 `policy_matches` 指向的是一个不存在的对象级 policy：
  - `corpus/policies/xdp-tools/xdp_forward.bpf.o.policy.yaml` 不存在
  - 实际存在的是程序级 policy：`corpus/policies/xdp-tools/xdp_forward/xdp_fwd_fib_full.policy.yaml`

同一天真正的 live VM 结果在 archive：

- 文件：`e2e/results/archive/xdp_forwarding_vm_20260312.json`
- stock receiver PPS：`990,522.6`
- post-ReJIT receiver PPS：`993,209.6`
- PPS speedup：`1.0027x`（`+0.27%`）
- live sites：`3 = endian 2 + cmov 1`
- 实际 apply：`2` 个 endian
- 剩余 `1` 个 cmov 被 warning 掉

所以：

- `XDP forwarding +0.27%：太弱，有没有更多 sites 可以利用？`
  - **基本没有。**
  - `xdp_fwd_fib_full` 一共就 3 个 site，所有非-CMOV site 已经都用了。
  - 如果想要更强的 E2E XDP 信号，方向不是“再调当前 policy”，而是“换一个 site 更丰富的 XDP workload / program”。

---

## 3. Corpus policy 改进建议

### 3.1 应该调整哪些 program 的 policy

优先级最高：

1. **先 refresh stale v3 policy**
   - 这次 corpus run 里有 `60` 行是“policy 文件存在，但 live 0 site apply 且日志明确显示 stale”
   - 其中 `39` 行最后表现成 winner，`17` 行表现成 regressor，`4` 行 tie
   - 这批结果不能当成可信 policy 收益
   - 第一批该刷新的对象：
     - `katran/balancer_ingress`
     - `katran/healthcheck_encap`
     - `xdp-tutorial/_fix_port_egress`
     - `suricata/xdp_hashfilter`
     - 其余所有 `policy selected 0 of N` 的 row

2. **清掉 extract-heavy regressor**
   - 高置信 candidate：
     - `linux-selftests/.../__encap_sit_none`
     - `linux-selftests/.../__encap_ipip6_none`
     - `linux-selftests/.../__encap_ip6gre_none`
     - `linux-selftests/.../__encap_ip6tnl_none`
     - `linux-selftests/.../__encap_ip6udp_none`
   - 这些程序要么是 `extract-only`，要么是 `extract + endian`
   - 当前最简单的修法是直接 `sites: []` 回 stock；更细一点可以先只清 `extract`

3. **谨慎处理 xdp_forward 的 endian**
   - corpus 里：
     - `xdp_fwd_fib_full = 0.7895x`
     - `xdp_fwd_fib_direct = 0.8919x`
   - 两者都只 apply 了 `2` 个 endian site
   - 但 E2E live forwarding 的 PPS 是 `+0.27%`
   - 所以这更像 **corpus / E2E workload sensitivity 不一致**
   - 建议：把它列成 corpus-only sweep 候选，不要直接把 E2E policy 也跟着清掉

4. **补上少量非 branch-flip 的 no-policy 程序**
   - `decap_f`
   - `cls_ingress`

### 3.2 Katran 回归修复方案

最直接方案：

1. 重新基于当前 `corpus/build/katran/*.bpf.o` 生成 `balancer_ingress` 和 `healthcheck_encap` 的 v3 policy
2. 继续保持 `CMOV` 不进 allowlist
3. 如果只想快速止血，直接让 `balancer_ingress` 暂时回 stock 也可以

不建议的方案：

- 不要照抄 micro 的“按 family 直接清”思路去调 Katran
- 因为当前问题不是 live apply 后的 family regression，而是 policy artifact 已经过时

### 3.3 预期改进后的 corpus geomean

几个可量化的 projection：

- 只修 `katran/balancer_ingress` 这一行回到 `1.0x`：整体从 `1.0463x` 到 `1.0491x`
- 再把明显的 `extract/endian` applied regressors 拉回 `1.0x`：
  - `__encap_sit_none`
  - `__encap_ipip6_none`
  - `__encap_ip6gre_none`
  - `__encap_ip6tnl_none`
  - `__encap_ip6udp_none`
  - `xdp_fwd_fib_full`
  - `xdp_fwd_fib_direct`
  - `_fix_port_egress`
  - 再加上 `balancer_ingress`
  - 整体可到约 `1.0598x`

我会把这个区间解释为：

- **保守值：`1.05x` 左右**
- **明显 cleanup 全做完后的上界：`1.06x` 左右**

---

## 4. E2E 改进建议

### 4.1 哪些 E2E case 值得 rerun

优先级排序：

1. **Tetragon：高优先级**
   - 当前没有 top-level authoritative JSON
   - archive 结果互相冲突
   - 当前 on-disk policy 已经变了，archive 数字不再代表当前 policy
   - 建议：refresh policy 后做 `5-10` 次 rerun，至少对 `connect_storm` 取中位数

2. **XDP forwarding：中高优先级**
   - 顶层权威文件居然是 dry-run
   - 需要把 live VM 结果提升成真正权威 artifact
   - 建议：至少再跑一次 `64B` PPS；如果时间允许，加一个更大包长点

3. **Tracee：低优先级**
   - 如果只是为了当前论文主线，现有 policy 已经足够好
   - 只有在想探索 selective-CMOV 时才值得 rerun

4. **bpftrace：低优先级**
   - 当前 workload 全是 CMOV-only，且 policy 已经把 CMOV 全跳过
   - 没有新 workload 前，rerun 不会产出新信息

5. **scx：暂不 rerun**
   - 先解决 struct_ops recompile 不支持的问题

### 4.2 E2E policy 调整建议

Tracee：

- 保持当前方向不变
- 继续跳过 CMOV
- 当前 42 个非-CMOV live site 已全部被吃到，没必要先动

Tetragon：

- 先 refresh v3 policy
- refresh 后继续 **显式跳过 CMOV**
- 再用 refreshed branch-flip-only policy 重跑

bpftrace：

- 当前 policy 已经是正确的 `CMOV -> empty policy`
- 不建议再做 policy 调整
- 要改的是 workload，不是 policy

XDP forwarding：

- 当前 `xdp_fwd_fib_full` policy 已经把 2 个 endian 全用上了
- 不建议为了这一个 case 打开 CMOV

scx：

- 当前没有 policy 调整价值

### 4.3 是否需要新的 E2E workload

需要。

最缺的是两类：

1. **bpftrace 的 non-CMOV workload**
   - 现在两个 script 都只产出 CMOV
   - 这会让 bpftrace E2E 永远变成“policy filtered all live sites”
   - 需要新的 script，最好能稳定暴露 `wide / endian / branch-flip`

2. **site 更丰富的 XDP workload**
   - `xdp_fwd_fib_full` 只有 3 个 site，头顶很低
   - 要更强的 XDP E2E 信号，需要换到 site 更多的 forwarding / dataplane program

Tetragon workload 本身也需要整理：

- `stress_exec` / `file_io` 比 `connect_storm` 更稳定，值得作为主展示 workload
- `connect_storm` 适合保留成“噪声敏感 / policy-sensitive”对照项，但需要多次重复

---

## 5. 结论

最重要的结论有四个：

1. **Corpus 当前不是 CMOV 问题，而是 v3 explicit allowlist 的 artifact freshness + extract/endian cleanup 问题。**
2. **Katran 0.872x 的主因是 stale policy，不是 live-applied policy regression。**
3. **Tracee 当前 policy 已经基本吃满全部非-CMOV opportunity；再往上主要得靠 selective-CMOV 实验。**
4. **Tetragon / XDP 的“权威 artifact”状态都不够干净：前者缺 top-level authoritative JSON，后者顶层文件还是 dry-run。**

按投入产出比，下一步建议顺序是：

1. refresh corpus/Tetragon 的 stale v3 policy
2. rerun Tetragon
3. rerun XDP forwarding，把 live VM 结果提升为真正权威 artifact
4. 清掉 corpus 里 extract-heavy tunnel regressors
5. 如果还要扩 E2E 说服力，再补 bpftrace non-CMOV workload
