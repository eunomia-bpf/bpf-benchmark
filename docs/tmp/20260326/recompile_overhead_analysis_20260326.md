# BpfReJIT 重编译开销分解分析（2026-03-26）

## 1. 结论摘要

1. 现有工件可以直接回答两件事：`daemon` pipeline 耗时，以及 `BPF_PROG_REJIT` syscall 的合并耗时；但**不能**再把内核内部精确拆成 verify / JIT / swap 三段，因为现有 JSON 只有合并字段 `rejit_syscall_ns`。
2. 在唯一保留 daemon 内部分段计时的 micro 工件 `micro/results/vm_micro_smoke_20260324_015916` 中，**成功应用**路径的中位数是：pipeline **1.994 ms**，kernel REJIT **13.358 ms**，daemon 内部 total **515.402 ms**。
3. 这个 `total_ns` 明显被一个近似固定的 **500.526 ms** 残余项主导。结合代码中 `--pgo-interval-ms` 默认值为 500 ms，以及 `collect_program_profiling()` 会 `sleep(interval)`，这是一个**高置信度推断**：smoke 工件是在启用 PGO 观察窗的配置下采到的，因此 `total_ns` 里包含了一段约 500 ms 的等待时间。
4. 最新完整 `vm_micro` 工件 `micro/results/vm_micro_20260326_201241/metadata.json` 只保留 runner 视角的 `compile_ns` / `phases_ns` 聚合值，没有 `daemon_response.timings_ns`。它给出的 REJIT 相对 kernel 的外部编译开销中位数是 **1581.751 ms**，远大于 daemon 内部 `total_ns`，因此**不能**把它直接当作 daemon 内部分解结果。
5. 对 Tracee / Tetragon / Katran 这类真实程序，单次程序执行通常只有几百 ns 到几万 ns；而一次重编译总耗时是几 ms 到几百 ms。换算成“等价多少次程序执行”，大致是 **646x 到 226,140x**（成功样本），Katran 失败样本甚至在 **105,890x 到 149,724x**。结论是：**重编译必须依赖长期热路径摊销，不能指望靠单次或少量事件回本。**

## 2. 数据源与口径

- `daemon/src/commands.rs`
  - `pipeline_run_ns`：pass 匹配 + bytecode rewrite 的累积 wall time。
  - `rejit_syscall_ns`：围绕 `bpf::bpf_prog_rejit()` 的累积 wall time，语义上最接近“verify + JIT + image swap”的合并耗时。
  - `total_ns`：从 `try_apply_one()` 入口到生成结果对象的总 wall time；它还包含 FD/info 查询、可选 PGO 采样等待、错误处理、回滚/重试等，**不是**纯 REJIT 核心耗时。
- `daemon/tests/results/static_verify.json`
  - 最新静态验证工件覆盖 **62** 个程序，**55** 个 applied，**62** 个 verifier accepted，程序规模范围 **21-13777 insns**。
  - 但当前版本**没有**保存 `timings_ns`，因此只能用来说明覆盖范围，不能直接做开销分解。
- `micro/results/vm_micro_smoke_20260324_015916/details/daemon_debug/*.json`
  - 这是当前仓库里我找到的唯一保留 `daemon_response.timings_ns` 的 micro 结果，能直接做 daemon 内部分段分析。
- `micro/results/vm_micro_20260326_201241/metadata.json`
  - 这是最新完整 `vm_micro` 结果，保留了每个 runtime 的 `compile_ns` 和 `phases_ns` 聚合值，但没有 `daemon_response.timings_ns`。
- `e2e/results/*/details/result.json`
  - Tracee / Tetragon 在 `rejit_result.per_program.<pid>.debug_result.timings_ns` 下有分段计时。
  - Katran 在 `paired_cycles[*].rejit_result.per_program.<pid>.debug_result.timings_ns` 下有分段计时。

## 3. 现有字段到底能回答什么

| 问题 | 现有字段 | 能否直接回答 | 备注 |
| --- | --- | --- | --- |
| daemon pipeline time | `pipeline_run_ns` | 可以 | 直接对应 pattern matching + rewrite |
| kernel REJIT time | `rejit_syscall_ns` | 可以，但只能给合并值 | verify/JIT/swap 无法再细拆 |
| daemon 内部端到端 time | `total_ns` | 可以 | 从 `try_apply_one()` 入口计时，不含 client 侧 socket/JSON 往返 |
| runner 外部 compile wall time | `compile_ns` | 可以 | 这是 benchmark harness 视角，不等于 daemon 内部 `total_ns` |
| verify / JIT / swap 三段各自耗时 | 无 | 不可以 | 需要更细粒度内核或 syscall 侧打点 |

## 4. Micro：daemon 内部分段耗时

### 4.1 总体统计（来自 `vm_micro_smoke_20260324_015916`）

| 样本集合 | 样本数 | pipeline 中位数 (ms) | kernel REJIT 中位数 (ms) | total 中位数 (ms) | 残余项中位数 (ms) | 说明 |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| 全部程序 | 62 | 1.993 | 16.195 | 518.462 | 500.597 | 混合 applied 与 failed/no-change |
| applied only | 39 | 1.994 | 13.358 | 515.402 | 500.526 | 最接近“正常成功重编译路径” |
| failed / no-change | 23 | 1.968 | 252.103 | 848.697 | 554.364 | verifier rejection / rollback / no-change 会显著拉高 syscall 时间 |

补充观察：

- 成功路径里，`pipeline_run_ns` 是稳定的低毫秒级；P95 只有 **5.065 ms**。
- 成功路径里，`rejit_syscall_ns` 中位数 **13.358 ms**，P95 **50.468 ms**，最大值 **73.499 ms**。
- 失败/不变路径里，`rejit_syscall_ns` 中位数抬升到 **252.103 ms**，最大值达到 **3710.785 ms**，说明“慢”的主因不是 userspace rewrite，而是内核侧失败路径与重试。
- applied 样本里的残余项中位数 **500.526 ms**，而且分布极窄（P95 **501.113 ms**），这和 `--pgo-interval-ms=500` 的代码默认值高度吻合。

### 4.2 按程序规模分组（applied-only）

| 规模桶 | 样本数 | pipeline 中位数 (ms) | kernel REJIT 中位数 (ms) | total 中位数 (ms) | latest vm_micro 外部 compile overhead 中位数 (ms) |
| --- | ---: | ---: | ---: | ---: | ---: |
| 小程序（<=128 insns） | 19 | 1.462 | 13.814 | 516.302 | 1075.876 |
| 中程序（129-1024 insns） | 15 | 2.568 | 20.476 | 523.876 | 1581.837 |
| 大程序（>1024 insns） | 5 | 5.030 | 3.782 | 508.855 | 2148.979 |

解读：

- `pipeline_run_ns` 随程序规模上升而上升，符合预期；小程序中位数约 1.46 ms，中程序约 2.57 ms，大程序约 5.03 ms。
- 成功样本里，kernel REJIT 中位数并没有严格单调随 insn 数增长。原因是样本数较少、程序结构差异很大，而且这里统计的是“成功样本”；像 Tracee 那类真实大程序就能看到更高的 REJIT 时间。
- `total_ns` 在三个规模桶都接近 500+ ms，再次说明 smoke 结果的 total 基本被固定观察窗主导，而不是被 rewrite 或 REJIT 核心本身主导。

### 4.3 代表性单程序样本

| 程序 | orig insns | applied | verifier retries | pipeline (ms) | kernel REJIT (ms) | total (ms) | latest vm_micro 外部 compile overhead (ms) |
| --- | ---: | --- | ---: | ---: | ---: | ---: | ---: |
| simple | 24 | no | 0 | 2.502 | 0.000 | 509.318 | 565.517 |
| memory_pair_sum | 78 | yes | 0 | 0.901 | 2.780 | 506.230 | 1075.876 |
| binary_search | 180 | no | 1 | 1.499 | 290.726 | 848.697 | 1571.636 |
| switch_dispatch | 321 | no | 1 | 3.106 | 321.358 | 890.234 | 2624.607 |
| local_call_fanout | 530 | yes | 0 | 3.958 | 23.843 | 528.518 | 2108.165 |
| large_mixed_1000 | 1008 | no | 2 | 7.160 | 541.903 | 1160.122 | 2631.575 |
| rotate_dense | 2796 | yes | 0 | 3.537 | 3.782 | 507.899 | 2160.662 |
| extract_dense | 2595 | yes | 0 | 5.030 | 5.198 | 511.078 | 1096.246 |
| mega_basic_block_2048 | 13777 | yes | 0 | 26.928 | 18.044 | 547.566 | 2445.103 |

其中最值得注意的两个点：

- `mega_basic_block_2048` 这种 **13,777 insns** 的超大程序，pipeline 也只有 **26.928 ms**；说明 userspace rewrite 的绝对成本仍可控。
- `large_mixed_1000`、`switch_dispatch`、`binary_search` 这类失败/重试样本，真正被拉高的是 `rejit_syscall_ns`，而不是 pipeline。

## 5. Latest vm_micro：runner 视角 compile overhead

`micro/results/vm_micro_20260326_201241/metadata.json` 保留了最新完整套件的 `compile_ns` 聚合值。把 `kernel-rejit.compile_ns.median - kernel.compile_ns.median` 作为“外部额外编译开销”后，62 个 micro 程序的分布如下：

| 统计量 | 外部 compile overhead (ms) |
| --- | ---: |
| min | 518.794 |
| median | 1581.751 |
| mean | 1573.255 |
| p95 | 2637.577 |
| max | 2955.396 |

这个字段的价值在于回答“从 benchmark harness 角度看，多花了多少编译时间”；但它**不能**替代 daemon 内部 `pipeline_run_ns / rejit_syscall_ns / total_ns`，因为它把对象打开/加载、runner 编排、以及其他 harness 级准备工作揉在了一起。

## 6. Tracee / Tetragon / Katran：相对程序执行时间的开销比例

这里把 `debug_result.timings_ns.total_ns` 与 workload baseline 中每个程序的 `avg_ns_per_run` 做对比。这个比例不是“整体业务吞吐影响”，而是一个更直接的问题：**做一次重编译，相当于多少次该程序的单次执行时间。**

| 场景 | PID / cycle | 程序 | orig insns | 状态 | pipeline (ms) | kernel REJIT (ms) | total (ms) | baseline 单次执行 (ns) | 折合执行次数 | 开销百分比 |
| --- | --- | --- | ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| Tracee | 43 | trace_security_ | 4629 | ok | 59.404 | 399.597 | 525.233 | 2,322.6 | 226,140.1x | 22,614,005.9% |
| Tracee | 29 | tracepoint__sch | 4069 | ok | 48.673 | 48.445 | 112.425 | 6,368.8 | 17,652.4x | 1,765,243.9% |
| Tracee | 38 | tracepoint__sch | 4370 | error | 36.823 | 145.199 | 216.154 | 10,083.5 | 21,436.4x | 2,143,638.5% |
| Tetragon | 152 | event_wake_up_n | 1365 | ok | 12.931 | 17.210 | 37.618 | 5,183.25 | 7,257.5x | 725,753.6% |
| Tetragon | 153 | event_execve | 2461 | error | 11.939 | 0.256 | 13.680 | 18,647.25 | 733.6x | 73,362.2% |
| Tetragon | 160 | tg_kp_bprm_comm | 292 | ok | 3.103 | 0.555 | 4.769 | 1,431.50 | 3,331.3x | 333,130.6% |
| Tetragon | 150 | event_exit_acct | 177 | ok | 2.804 | 0.346 | 4.256 | 6,585.67 | 646.3x | 64,628.5% |
| Katran(cycle 0) | 917 | balancer_ingres | 2546 | error | 33.687 | 0.863 | 39.624 | 264.647 | 149,724.0x | 14,972,399.9% |
| Katran(cycle 1) | 1050 | balancer_ingres | 2546 | error | 23.986 | 0.538 | 27.990 | 264.328 | 105,889.8x | 10,588,984.2% |
| Katran(cycle 2) | 1183 | balancer_ingres | 2546 | error | 30.804 | 0.796 | 35.120 | 254.976 | 137,737.1x | 13,773,714.0% |

解读：

- Tracee 的大程序样本最能说明问题：
  - `trace_security_`（4,629 insns）成功重编译一次要 **525.233 ms**，相当于 **226,140x** 次单次执行。
  - `tracepoint__sch`（4,069 insns）成功样本是 **112.425 ms**，也仍然要 **17,652x** 次执行才能摊平。
- Tetragon 的成功样本明显更轻：
  - `event_exit_acct` 只要 **4.256 ms**，但因为单次执行也只有 **6.59 us** 左右，所以仍然需要 **646x** 次执行才能回本。
  - `event_wake_up_n` 成功样本是 **37.618 ms**，折合 **7,257x** 次执行。
- Katran 三次都失败在同一 verifier 错误：`jump out of range from insn 1051 to 2537`。即使失败得很快，总耗时也仍有 **27.990-39.624 ms**；而它的单次 XDP 执行只有 **~255-265 ns**，因此折合 **105,890x-149,724x** 次执行。

## 7. 这份数据真正支持的结论

1. **Daemon pipeline 很便宜。** 在 micro 成功路径里，中位数只有 **1.994 ms**；即便是超大程序，userspace rewrite 也通常还在几十毫秒以内。
2. **内核 REJIT 是主要的“真实重编译成本”。** 成功的 micro 样本里，中位数 **13.358 ms**；对更复杂的真实程序，Tracee 可以上升到 **399.597 ms**。
3. **现有 `total_ns` 经常被配置项主导。** 在 smoke 工件里，大约 **500 ms** 的固定残余项几乎肯定来自 PGO 观察窗，所以不能把 `total_ns` 直接理解为“rewrite+verify+JIT 本身要 500 ms”。
4. **latest vm_micro 的 `compile_ns` 是外部 wall time，不是内部细分。** 它适合做“用户看到的额外编译开销”讨论，但不适合拿来回答 reviewer 追问的“verify / JIT / swap / pipeline 各自多少”。
5. **相对于单次程序执行，重编译开销极高，必须依赖摊销。** 对真实程序，回本门槛从数百次到数十万次不等；因此是否值得重编译，核心取决于程序是否足够热、优化收益是否足够大、以及这段代码还能活多久。

## 8. 还缺什么数据

如果 reviewer 要追问“verify 时间多少、JIT 时间多少、swap 时间多少”，当前仓库内已有结果**不够**。下一步需要的是：

- 在 `BPF_PROG_REJIT` 内核路径上新增更细粒度打点，至少把 verify、JIT 编译、image swap 分开。
- 或者在 syscall 返回结构里扩展子字段，而不是只暴露一个合并的 `rejit_syscall_ns`。
- 同时保留最新 `static_verify.json` / `vm_micro` 工件里的 `timings_ns` 明细，避免出现“最新覆盖最全，但时间字段被聚合掉”的情况。
