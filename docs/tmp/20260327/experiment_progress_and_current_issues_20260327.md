# 实验进展与当前问题汇总

日期：2026-03-27

## 1. 当前结论

截至目前，这一轮工作的核心结论是：

1. `map_inline` 的主线正确性问题已经修到“能在真实程序上稳定 fire”，不再停留在只对 toy case 生效。
2. `corpus` / `e2e` 的 pass 控制已经按设计改成 **request-level**，`daemon serve` 启动参数保持不变；现在可以确保性能实验只跑 `map_inline + const_prop + dce`，不会再混入 `wide_mem` / `endian_fusion` / `branch_flip` 等无关 pass。
3. Katran 的 corpus runtime 路径此前不是“程序本身不能测”，而是 `runner` prepared-state 复用错误导致 `io_mode=packet` 被错误降成 `context`，这个 `EINVAL` 根因已经修复。
4. 但是，**目标还没有达成**：当前还没有拿到用户要求的 `50%+` 级别真实 runtime 提升；Tetragon 现有 runtime 仍接近持平或略慢，Tracee 还存在 attach / fixture 双重阻塞。

换句话说，当前状态是：

- **基础设施和 pass 接线已经基本打通**
- **若干 correctness blocker 已修掉**
- **真实代码尺寸收益已经存在**
- **显著 runtime 收益仍未完成，需要继续攻坚**

## 2. 已完成的关键修复

### 2.1 `map_inline` 正确性主线修复

这一轮已经完成的关键修复包括：

1. **后续 pseudo-map load 绑定错位修复**
   - 删除前序 lookup / map load 后，后续 map pseudo load 的 `old_fd -> map_id` 绑定不再错位。
   - 真实程序不会再因为这个问题直接 verifier fail。

2. **`PERCPU_ARRAY` inline 支持**
   - 现在 `PERCPU_ARRAY` 在“同一个 key 的所有 CPU slot 值完全一致”时允许 inline。
   - 如果各 CPU slot 不一致，会明确 skip，并给出精确 skip reason。

3. **zero-value inline 修复**
   - 普通 `ARRAY` 和 `PERCPU_ARRAY` 的默认全零 value 现在都能 inline。
   - 不会再把全零误判成“map 没数据”。

4. **Katran null-check 过删修复**
   - Katran `balancer_ingress` 之前不是 constant-key 提取不了，而是 `map_inline` 对某些 lookup/null-check 窗口删得过头，导致 verifier 丢失 non-null 约束。
   - 现在对 non-null 窗口引入了更保守的 triviality 检查：能 inline 固定 load，但不再盲目删除整个 lookup/null-check pattern。

### 2.2 `corpus` / `e2e` request-level pass 控制打通

当前设计目标是：

- `daemon serve` 启动参数不要承担有意义的 pass 选择职责
- pass 选择应该跟随每次 `optimize` 请求发送
- `corpus` / `e2e` 只运行当前关注的 pass 集，而不是默认全 performance pipeline

现在已经完成：

1. **daemon request-level pass override**
   - `daemon/src/server.rs` 现在支持每次请求传 `enabled_passes` / `disabled_passes`
   - 启动 `daemon serve` 时不需要额外参数变化

2. **runner socket 请求链支持 `enabled_passes`**
   - `runner/include/micro_exec.hpp`
   - `runner/src/common.cpp`
   - `runner/src/kernel_runner.cpp`
   - `runner/src/batch_runner.cpp`
   已经都能把 `enabled_passes` 带到 daemon socket optimize 请求

3. **corpus 默认 active passes 已收口**
   - `corpus/config/benchmark_config.yaml` 当前 `performance` active list 已固定为：
     - `map_inline`
     - `const_prop`
     - `dce`

4. **e2e 不再只能直跑 `daemon apply`**
   - `runner/libs/rejit.py` 现在在显式传 pass 时，会起一个临时 `serve`，然后通过 Unix socket 发 request-level optimize 请求
   - `tracee` / `tetragon` / `katran` / `bcc` / `bpftrace` / `scx` 六个 case 都走同一条 request-level 控制面

### 2.3 Tracee fixture replay / object-id 修复

Tracee 的 fixture replay 之前有一个典型问题：

- fixture 保存的是旧的 object id
- live kernel 里 map/prog id 已经变了
- replay 直接用旧 id 会失败

现在已经修到：

- 先做 fixture-local `map_id -> live fd` 重映射
- 再 fallback 到当前内核 live object 查询
- 对 versioned map-of-maps 里的坏 entry，不再整批失败，而是跳过缺失 entry 继续 replay 其余内容

这个修复解决了“旧 object id 一上来就炸”的问题，但 **还没有解决 Tracee fixture 本身不完整** 的问题。

### 2.4 Katran corpus prepared-run `EINVAL` 根因修复

Katran corpus 一度看起来像是：

- `balancer_ingress` compile 可以
- run 阶段一直 `bpf_prog_test_run_opts failed: Invalid argument`

现在已经确认并修复根因：

- prepared batch 先执行 object compile job
- compile job 固定是 `io_mode=context`、`memory=None`
- 后续 run job 明明声明的是 `io_mode=packet + test_input=katran_vip_packet_64.bin`
- 但 `execute_prepared_kernel_run()` 错误复用了 prepared-state 里的 compile-only 输入配置

修复后，`execute_prepared_kernel_run()` 现在会：

- 按 **当前 run job** 重新 `materialize_memory()`
- 重新解析 **当前 job** 的 `effective_io_mode`
- 只复用 prepared object/program FD

最小 VM repro 已验证：

- 修复前：`baseline-run ok=false, error=EINVAL`
- 修复后：`baseline-run ok=true`
- 并得到真实样本：
  - `exec_ns=28`
  - `wall_exec_ns=326752`
  - `retval=2`

### 2.5 Corpus `warmup_repeat` 接线修复

这一轮又确认了一个会显著污染 corpus 结果的 runner 问题：

- `corpus/config/benchmark_config.yaml` 里已经有 `warmups` 配置
- 但 `corpus/modes.py` 之前没有把它传进 batch job
- `runner/src/batch_runner.cpp` 因而会回落到默认 `warmup_repeat=5`

这会直接导致：

- 配置里本来想跑 `warmups=0` 或 `warmups=1` 的 profile
- 实际都会先多跑 5 次 warmup
- 对 Katran 这类 stateful `bpf_prog_test_run` 程序，会把 corpus 与 direct batch / e2e 的语义拉开

已经完成的修复是：

- `corpus/modes.py` 新增 `benchmark_warmup_repeat()`
- `build_test_run_batch_job()` / `build_target_batch_plan()` / `build_object_batch_plan_v2()` / `run_guest_batch_mode()` 现在都会把 `warmup_repeat` 显式传到 batch runner

已做的最小验证：

- `python3 -m py_compile corpus/modes.py`：通过
- 本地读取配置确认：
  - `dev -> warmup_repeat = 0`
  - `ablation_map_inline_only -> warmup_repeat = 1`

## 3. 构建与验证状态

当前已经确认通过的验证包括：

1. `make runner`：通过
2. `make daemon-tests`：通过
   - 当前结果：`550 passed / 0 failed / 13 ignored`
3. `pytest -q tests/python/test_rejit.py`：通过
4. `python3 -m py_compile runner/libs/rejit.py tests/python/test_rejit.py`：通过
5. `python3 -m py_compile corpus/modes.py runner/libs/rejit.py e2e/cases/{tracee,tetragon,katran,scx,bpftrace,bcc}/case.py`：通过

因此当前问题已经不再是“主线代码不能编译 / 基础测试不过”，而是：

- 真实热路径还没完全打出来
- `map_inline` 在复杂真实程序上的覆盖率还不够高
- 部分应用的 runtime 采样路径还存在 fixture/attach 级别阻塞

## 4. 当前真实数据与真值

### 4.1 Katran live e2e 旧真值

已有一轮 Katran live e2e 权威真值：

- artifact:
  - `e2e/results/katran_live_20260327_070135_20260327_140143/details/result.json`

这轮结果的重要含义是：

1. **live 路径已经可稳定测量**
2. 但当时还没切到新的 request-level pass 控制，所以实际改写的不是纯 `map_inline + const_prop + dce`

当时真实结果：

- `balancer_ingress` same-image paired：`3/3` cycles comparable
- `map_inline`：`0 hit`
- 实际改写 pass：`wide_mem + endian_fusion`
- 尺寸：
  - insns: `2546 -> 2534`
  - xlated: `23872 -> 23776`
  - jited: `13645 -> 13597`
- runtime：
  - BPF mean: `220.52ns -> 224.18ns`
  - 约 `-1.6%`
- app throughput：
  - paired median 约 `-3.92%`

结论：

- 这轮 live Katran 已经证明“测量链路正常”
- 但它 **不能回答** `map_inline + const_prop + dce` 的真实收益，因为当时混入了别的 pass 且 `map_inline` 根本没有命中

### 4.2 Katran corpus compile 真值

已有一轮 Katran corpus 定向结果：

- artifact:
  - `corpus/results/corpus_vm_batch_20260327_141413/`
- 文档：
  - `docs/tmp/20260327/katran_corpus_map_inline_20260327.md`

这轮结果表明：

- `katran:balancer.bpf.o:balancer_ingress`
  - `sites_found = 64`
  - `sites_applied = 7`
  - `sites_skipped = 57`

skip 分类：

- `lookup key is not a constant stack or pseudo-map-value materialization`: `24`
- `lookup result has non-load uses`: `20`
- `lookup result is not consumed by fixed-offset scalar loads`: `9`
- `map type 12 not inlineable in v1`: `2`
- `map type 13 not inlineable in v1`: `2`

命中的 site 包括：

- `PC=1059`
- `PC=1248`
- `PC=1354`
- `PC=1636`
- `PC=1764`
- `PC=1952`
- `PC=2267`

但当时 run 结果仍是：

- `baseline_run`: `EINVAL`
- `rejit_run`: `EINVAL`

这轮已经证明 **Katran corpus 里 `map_inline` 实际可以命中真实 hot program**，只是当时 runtime 被 prepared-run bug 卡死了。这个 bug 现在已经修掉，所以下一步需要重新跑定向 corpus，把 runtime 数字真正补出来。

### 4.3 Tetragon 当前真值

Tetragon 已确认的情况：

1. `map_inline` 在真实程序上可以 fire
2. 当前已经拿到稳定的代码尺寸收益
3. 但已测到的 runtime 还没有明显收益

当前最明确的一组 runtime 真值来自：

- `bpf_fork.bpf.o:event_wake_up_new_task`

结果：

- baseline `exec_ns = 90`
- rejit `exec_ns = 93`
- speedup `0.968x`
- 约等于 `-3.2%`

尺寸收益：

- JIT size: `6820 -> 5802`
- xlated size: `10512 -> 8760`
- 约 `15%` 级别缩减

fixture smoke 中已确认能命中的更有潜力的程序包括：

- `tetragon/bpf_execve_event.bpf.o:execve_rate`
  - `applied 2`
- `tetragon/bpf_execve_event.bpf.o:event_execve`
  - `applied 2`
- `tetragon/bpf_fork.bpf.o:event_wake_up_new_task`
  - `applied 1`

这意味着 Tetragon 当前更大的问题不是“pass 不 work”，而是：

- 之前选中的 `wake_up_new_task` 不是最值得打的热路径
- 下一步应转向 `execve_rate` / `event_execve` 这种更可能因为 map 常量而触发更深折叠的程序

### 4.4 Tracee 当前真值

Tracee 当前状态最复杂，因为它同时有：

1. fixture 问题
2. attach/runtime 问题

已知情况：

- `tracee.bpf.o:cgroup_skb_egress`
  - compile 可做
  - 但 `bpf_prog_test_run_opts` 返回 `EINVAL`
- `tracee.bpf.o:sys_enter_submit`
  - stale object-id 问题修掉后，又暴露出 attach 问题：
    - `bpf_program__attach failed: No such file or directory`

更关键的是，Tracee 的 fixture 目前只录了 version maps，比如：

- `events_map_version`
- `pid_filter_version`

但没有把真实的动态 inner maps 内容一并完整录下来，所以像：

- `reset_event()`
- `evaluate_scope_filters()`

这种真实热路径所依赖的 state 还原不完整。结果就是：

- compile/apply 可以前进
- 但 runtime 还原不出真正热路径
- `measured_pairs` 仍是 `0`

## 5. 当前最核心的问题

虽然表面上现在有多个 case、多个 failure，但归纳起来，当前最核心的问题只有三类。

### 5.1 真实热路径状态还原不完整

这主要影响 Tracee，也部分影响 corpus 场景。

表现：

- fixture 只录到了外层 version map，没有录到动态 inner maps 的真实内容
- live 程序运行时依赖这些 inner maps 的值来决定分支和行为
- 结果是 compile/apply 看起来没问题，但 runtime 不是实际热路径

### 5.2 Katran 仍有大量高价值 site 没吃到

Katran `balancer_ingress` 现在已经能命中 7 个 site，但离“明显 runtime 提升”还差得远，核心原因是剩下的 skip site 仍然太多。

最重要的 miss 类别：

1. **constant key 提取失败**
   - `24` 个 site
   - 其中一部分来自 `vip_map` 这类 `20-byte key`
   - 当前 `map_inline` 只支持 `<= 8B` constant key

2. **lookup result has non-load uses**
   - `20` 个 site
   - 当前 use-classifier 只接受比较纯的“lookup -> fixed-offset load”形态

3. **lookup result is not consumed by fixed-offset scalar loads**
   - `9` 个 site
   - 当前 rewrite 模型还比较保守，只覆盖简单固定 offset 标量 load

4. **map type 12 / 13**
   - 当前 v1 明确不支持
   - 数量不大，但确实限制 coverage

### 5.3 `const_prop` / `dce` 还没有吃到足够多的前提

现在虽然 request-level pass 控制已经保证只跑：

- `map_inline`
- `const_prop`
- `dce`

但在 Katran 和部分 Tetragon 路径里，后两个 pass 没出效果，不是它们“坏了”，而是：

- 前面的 `map_inline` 只吃到了少数 site
- 被 inline 的值多是零值 / 局部字段
- 还不足以把更多分支或子路径折叠掉

## 6. 目前最有希望继续提速的方向

### 6.1 Katran：先拿干净 runtime，再继续扩命中

Katran 是当前最接近“短期能打出明显收益”的对象，原因是：

1. live e2e 路已经稳定
2. corpus 里已经确认有 7 个真实命中
3. prepared-run `EINVAL` 已修掉
4. `balancer_ingress` 的热路径、map 形态、主要 skip reason 都已经比较清楚

因此 Katran 下一步的优先级应该是：

1. 用新的 request-level pass 控制重跑 live e2e
2. 用修复后的 prepared-run 路重跑定向 corpus
3. 再决定算法投入方向：
   - 先扩 fallback key scan / use-classifier
   - 还是直接做 `>8B` constant key 支持

### 6.2 Tetragon：换程序，不要继续浪费在 `wake_up_new_task`

`wake_up_new_task` 已经证明：

- 能缩尺寸
- 但不代表能提 runtime

下一步更值得打的是：

- `bpf_execve_event.bpf.o:execve_rate`
- `bpf_execve_event.bpf.o:event_execve`

### 6.3 Tracee：先修 fixture/attach，不要过早优化 pass

Tracee 现在不适合继续只盯 `map_inline.rs`。

正确顺序应该是：

1. 补全 versioned map-of-maps 的真实 inner-map state replay
2. 修 attach orchestration
3. 让 `sys_enter_submit` / 相关热路径真正可测
4. 再评估 `map_inline + const_prop`

## 7. 当前正在进行的实验

写这份文档时，正在进行一轮新的 Katran live e2e 重跑，目标是验证：

1. `e2e` 是否已经真的只走 `map_inline + const_prop + dce`
2. 当前 request-level pass 控制在真实 VM live 路径中是否生效
3. 新结果是否还会混入旧的 `wide_mem` / `endian_fusion`

benchmark 完成后，需要立即检查：

- `pass_details`
- `passes_applied`
- `inlined_map_entries`
- paired runtime summary

## 8. 接下来最重要的 TODO

按优先级排序，下一步应该是：

1. **收 Katran live e2e 新结果**
2. **重跑 Katran 定向 corpus runtime**
3. **把 Tetragon 转到 `execve_rate` / `event_execve`**
4. **修 Tracee 的 versioned inner-map state replay + attach**
5. **继续扩 `map_inline` coverage**

## 9. 当前判断

到目前为止，项目的真实状态可以概括为：

- **不是“map_inline 不 work”**
- 而是“map_inline 已经开始 work，但在最复杂真实程序上的覆盖率还不够，且部分应用的 runtime 场景还没完全还原出来”

更具体地说：

- **Katran**：最接近突破口，基础设施已基本打通，下一步重点是拿干净 runtime 并扩大命中
- **Tetragon**：pass 已 work，但目标程序要换
- **Tracee**：最大 blocker 在 runtime fixture/attach，不在 pass 本身

现在还不能说：

- “运行时收益已经达标”
- “50%+ 提升已经实现”
- “corpus / e2e 已全部完成”

但可以明确说：

- 关键 correctness 问题已经修掉一批
- 控制面已经按设计收口
- Katran corpus 的 runtime 死路已经打通
- 真实 hot program 上的 `map_inline` 命中已经存在
- 后续优化已经从“盲修”进入“针对明确 skip 类别逐个清掉”的阶段

## 10. 2026-03-27 最新进展补充

这一轮又向前推了一步，主要集中在 Katran 的 `20-byte` key 形态。

### 10.1 新实现

- `map_inline` 的 `ConstantKey` 现在保留原始 `bytes`，不再只保留截断后的 `u64`
- `build_site_rewrite()` / `MapInlineRecord` 现在会把完整 key bytes 传给 map value 读取与 invalidation 记录
- 新增回归测试：
  - `map_inline_pass_rewrites_hash_lookup_with_pseudo_map_value_20_byte_key`

这修掉的是一个很具体、但对 Katran 很关键的问题：

- 以前 `BPF_PSEUDO_MAP_VALUE` 提供的 key 如果超过 `8` 字节，虽然前面已经能把 key bytes 读出来，但真正去做 map lookup 时还是只把前 `8` 字节写回
- 结果就是像 Katran `vip_map` 这种 `20-byte` key 形态，逻辑上“看起来支持了”，实际上还不能命中真实 value

### 10.2 当前验证结果

- `make daemon-tests`
  - **546 passed / 0 failed / 13 ignored**

- Katran 定向 corpus：
  - 命令：
    - `make vm-corpus TARGET=x86 PROFILE=ablation_map_inline_full FILTERS='katran:balancer.bpf.o:balancer_ingress' SKIP_CORPUS_FETCH=1`
  - artifact：
    - `runner/corpus/results/vm_corpus_20260327_164205/details/result.json`

### 10.3 最新 Katran 真实数字

`balancer_ingress` 这一轮结果是：

- `map_inline`
  - `sites_applied = 41`
  - `sites_found = 105`
  - 相比上一轮 `40 / 104`，又多吃掉了 `1` 个 site
- `const_prop`
  - `29 -> 30`
- `dce`
  - 维持 `2`
- `constant-key` 相关 skip
  - `24 -> 23`

运行时：

- baseline `exec_ns = 7`
- rejit `exec_ns = 6`
- `speedup_ratio = 1.1667x`

更可信的 wall/cycles：

- `wall_exec_ns: 32433 -> 27814`
  - 约 **-14.2%**
- `exec_cycles: 119556 -> 102530`
  - 约 **-14.2%**

代码尺寸：

- JIT `13645 -> 13573`
- xlated `23872 -> 23856`

### 10.4 现在 Katran 还剩什么

现在 Katran 这条线已经不是“完全打不动”，而是进入了很明确的剩余问题阶段：

- 第一类：`lookup result is not consumed by fixed-offset scalar loads`
  - 当前还是 **37**
  - 这是最大的残余 skip 类别
- 第二类：`map type 12/13`
  - 还是 **2 + 2**
  - 也就是 map-in-map 相关形态还没吃
- 第三类：剩余 `constant-key` miss
  - 现在已经从 **24** 降到 **23**
  - 说明这次 `20-byte pseudo-map-value key` 修复是真实生效的，但还没有把所有复杂 key 形态全打掉

### 10.5 对整体状态的影响

这次更新后的判断更清晰了：

- **Katran**：已经连续多轮拿到真实正收益，且 coverage 还在继续上升
- **Tetragon**：仍然主要卡在 attach orchestration + `BPF_PROG_REJIT: Invalid argument`
- **Tracee**：仍然主要卡在 attach / fixture replay 完整性，不是 `map_inline` 本体

所以当前最合理的下一步仍然是：

1. 继续沿着 Katran 剩余 skip 类别往下打，把 `non-load uses` 和 map-in-map 形态继续吃掉
2. 并行修 Tetragon `execve_rate` 的 attach + REJIT blocker
3. 修 Tracee versioned map-of-maps / inner-map fixture replay

## 11. Katran correctness 复核后的最新真值

这一轮最大的变化不是“又多拿了多少 site”，而是把一个之前看起来很漂亮、但实际上不可信的 Katran runtime 结果彻底证伪了。

### 11.1 先证伪：之前的 1.714x 不是可信收益

之前有一轮 Katran `balancer_ingress` 的结果一度显示：

- baseline `exec_ns = 12`
- rejit `exec_ns = 7`
- `speedup_ratio = 1.714x`

但后续把 `run` 路径和输出包一起对上以后，确认那不是“正确程序更快”，而是 **语义已经变了**。

真正的证据来自后面的 corpus 复跑：

- artifact:
  - `corpus/results/vm_corpus_20260327_171855/details/result.json`
- 结果：
  - baseline `retval = 3`
  - rejit `retval = 1`
  - baseline `result = 02000000000b0200`
  - rejit `result = 02000000000a0200`

也就是说，这一轮 REJIT 已经把包改写行为打坏了，不能再把之前那组“更快”的数字当成有效性能收益。

### 11.2 第一个真根因：mutable stats/vip_miss_stats 被错误 inline

这轮复核里最先确认的问题是：

- `map_inline` 以前会把 `stats` / `vip_miss_stats` 一类 mutable map 的 lookup 也 inline 掉
- 即便后面还有 store-back / counter update，它也会先把 `*(u64 *)(r0 + off)` 这种 load 直接替成常量
- 这样就会把“读旧值 -> +1 -> 写回”的逻辑改成“写死某个常量派生值”

Katran 里这类 site 非常多，典型就是：

- `PC=13`
- `PC=366`
- `PC=469`
- `PC=543`
- `PC=572`
- `PC=594`
- `PC=618`
- `PC=657`
- `PC=796`
- `PC=826`
- `PC=848`
- `PC=899`
- `PC=1089`
- `PC=1552`
- `PC=1793`
- `PC=2010`
- `PC=2031`
- `PC=2066`
- `PC=2206`
- `PC=2227`

现在已经加了新的保守规则：

- `mutable lookup result has non-load uses`

只要 lookup 结果后面除了 fixed-offset scalar load 之外还有别的指针用途，就不再 inline 该 site。

对应新回归测试：

- `classify_r0_uses_marks_store_back_as_other_use`
- `map_inline_pass_skips_mutable_array_lookup_with_store_back`

### 11.3 第二个真根因：spill-slot alias 活得太久

把上面的 mutable-site 清掉之后，Katran 一度恢复了语义正确，但 runtime 没有提升，甚至更慢：

- artifact:
  - `corpus/results/vm_corpus_20260327_171557/details/result.json`
- 结果：
  - baseline `retval = 3`
  - rejit `retval = 3`
  - baseline `exec_ns = 1928`
  - rejit `exec_ns = 3142`
  - `speedup_ratio = 0.614x`

这时我又尝试把 `ctl_array` 第二个热 site 重新放进来，也就是允许 backward `JEQ r0, 0` 也被识别成 null-check。结果是：

- `PC=1811` 又重新被 inline
- 语义再次坏掉

对应 artifact：

- `corpus/results/vm_corpus_20260327_171855/details/result.json`

对应结果：

- baseline `retval = 3`
- rejit `retval = 1`
- baseline `result = 02000000000b0200`
- rejit `result = 02000000000a0200`

这说明 `PC=1811` 不是“单纯 null-check 识别不够”的问题，而是这个 site 的 spill/reload use 区间本身更复杂。

进一步看 bytecode 后确认：

- `PC=1811` 会把 `ctl_array` lookup 结果 spill 到 `fp-0x98`
- 后面还有一次 `stats` helper
- 再后面既有最近的一簇字节 load，也有更远处跨多个 block 的 flag/config load

之前的 stack-slot alias 跟踪会把 `fp-0x98` 一直当成 alias 根，导致一次 spill 后，后面很远的 use cluster 也被一起归到这次 lookup 上。

现在已经改成：

- **stack-slot alias 在第一次 reload 后就消费掉**

这样只保留最近的一簇 reload/load，不再把远距离 use cluster 全部吃进去。

对应已有回归：

- `classify_r0_uses_tracks_stack_spill_and_reload_across_helper`

### 11.4 当前 Katran 的稳定真值

做完上面两层回退后，Katran 当前最可信的一轮是：

- artifact:
  - `corpus/results/vm_corpus_20260327_172402/details/result.json`

结果如下：

- baseline `retval = 3`
- rejit `retval = 3`
- baseline `result = 02000000000b0200`
- rejit `result = 02000000000b0200`
- baseline `exec_ns = 1474`
- rejit `exec_ns = 3096`
- `speedup_ratio = 0.476x`

代码尺寸：

- baseline JIT `13656`
- rejit JIT `13634`
- `code_ratio = 1.0016x`

pass 统计：

- `sites_applied = 2`
- `sites_found = 66`
- `sites_skipped = 64`

这轮真正被吃到的 site 只剩两条 `ctl_array`：

- `site at PC=1105: inlined successfully, value=0x02000000000b0000`
- `site at PC=1807: inlined successfully, value=0x02000000000b0000`

注意这里的 PC 比前面的 object-level call-site 低 3，是因为这轮 rewrite 后最终记录点落在 map-setup 边界上；但本质上对应的仍然是之前那两条 `ctl_array` 热路径。

### 11.5 当前判断

Katran 这条线现在的真状态应该更新为：

- **correctness 已经重新拉回来了**
- **之前的 1.714x 不能再当成有效成果**
- **当前安全版本的 map_inline 还没有拿到正 runtime 收益**

更具体地说：

- 只吃安全的 `ctl_array` 近距离 load cluster，收益太小，JIT 尺寸几乎没变
- 一旦把更远的 spill/reload use cluster 也吃进去，`PC=1811` 这条路径又会把语义打坏
- 所以下一步不能继续靠“再放宽一点 use-classifier”赌收益，必须换成更可证明的方法：
  - 要么做 dominated-use / CFG-aware 的更精细判定
  - 要么直接转去 live e2e，找能让 `ctl_array` / 其它 config map 触发明显 `const_prop + dce` 折叠的真实配置

### 11.6 当前代码与测试状态

这一轮之后，daemon 当前验证状态是：

- `make daemon-tests`
  - **550 passed / 0 failed / 13 ignored**

所以现在可以确定：

- 新加的保守规则没有把基础 `map_inline` 功能打坏
- Katran 的问题已经从“明显 correctness bug”收敛成“safe 版本 coverage 太保守，导致没有性能收益”

### 11.7 corpus warmup 配置失真已修复

这一轮又确认了一个会直接污染 Katran corpus 结果解释的 runner 问题：

- `corpus/config/benchmark_config.yaml` 里虽然早就有 `warmups` 字段
- 但 `corpus/modes.py` 之前没有把它传进 batch job
- `runner/src/batch_runner.cpp` 会把未显式传入的 `warmup_repeat` 默认成 `5`

这意味着在修复前：

- `dev` profile 即使设计上想要 `warmups=0`
- 实际跑进 guest/batch 时仍会变成 `warmup_repeat=5`

对 Katran 这种 stateful 的 `bpf_prog_test_run` 程序，这会带来两个直接问题：

1. corpus 的 baseline/rejit run 不再是“fresh single-shot”语义
2. direct batch repro 和 corpus 结果会被额外的 warmup 次数污染，导致 `retval` / `exec_ns` 很难直接对齐解释

现在已经修复：

- `corpus/modes.py` 新增 `benchmark_warmup_repeat()`
- `build_test_run_batch_job()` 开始显式写入 `warmup_repeat`
- target/object/batch guest 几条路径都已把 profile 的 warmups 透传到最终 job

已做静态验证：

- `python3 -m py_compile corpus/modes.py`
- 本地读取配置结果：
  - `dev -> warmup_repeat=0`
  - `ablation_map_inline_only -> warmup_repeat=1`

这条修复不会直接带来性能提升，但它是现在解释 Katran corpus runtime 的必要前提；没有它，后面的性能数字不可信。

### 11.8 Tracee 的当前 blocker 是 versioned inner maps fixture 不完整

这部分现在已经可以下定论：

- Tracee `sys_enter_submit` 的热路径不是 attach 控制面本身没打通
- 真正的 blocker 是 fixture capture/replay 还原不出 versioned map-of-maps 指向的 inner maps

具体来说：

1. `sys_enter_submit` 热路径会读：
   - `events_map_version -> events_map`
   - `pid/uid/mnt/pidns/uts/comm/cgroup/process_tree/binary` 这些 `*_version -> inner map`
2. Tracee userspace 会在运行时动态创建这些 inner maps，再插进 outer version map
3. 当前 `corpus/fixtures/tracee/tracee.bpf.o/sys_enter_submit.json` 只保存了 outer maps
4. outer map 的 `value_hex` 里引用的 inner map id `242..251` 并没有对应的 fixture map 节点

所以 replay 时会出现：

- `unable to resolve referenced object id 242 for fixture map 'events_map_version'`

runner 当前的 replay 逻辑只会：

- 匹配 object 内已经存在的 live map
- 或尝试按内核当前 object id 直接取 fd

但 Tracee 这些 inner maps：

- 不在 BPF object 静态 maps 里
- fresh replay 时也没有现成 live id

所以 outer map-of-maps 的 entry 无法真正回放，程序虽然能加载，但走不到真实热路径。

当前最小修复方向已经明确：

1. `runner/scripts/capture_map_state.py`
   - 不能再只靠 daemon 返回的 `inlined_map_entries`
   - 需要按 `prog_id` 枚举 live program maps，并递归抓取 `HASH_OF_MAPS` / `ARRAY_OF_MAPS` 的 inner maps
2. `runner/src/kernel_runner.cpp`
   - replay 时需要支持“fixture 里有、object 里没有”的 inner map
   - 也就是先创建 fixture-only live inner maps，先填充 inner，再回填 outer map-of-maps entry

这件事没做完之前：

- Tracee `sys_enter_submit` 的 `map_inline + const_prop`
- 还不是在真实热路径状态上工作

### 11.9 Tetragon `execve_rate` 还存在 post-verify `EINVAL`

Tetragon 这条线也有了新结论：

- `execve_rate` / `event_execve` 这组程序仍然是更值得打的目标
- 但 `execve_rate` 当前存在一种不是普通 verifier reject 的 `BPF_PROG_REJIT -> -EINVAL`

现在更像是：

1. verifier 已经完整看完了新程序
2. 但 REJIT 在 verifier 之后返回 `Invalid argument`
3. 这和 direct tail-call `poke_tab` 的 insn index 不匹配高度一致

当前已知现象是：

- `map_inline` 吃掉前几个 lookup 之后
- `const_prop + dce` 继续把 `cgroup_rate()` 周围逻辑大幅折叠
- 最终 tail-call 所在 pc 发生了显著前移

这类失败当前最合理的短期处理不是让整条 benchmark 硬失败，而是：

- 把“complete verifier log + `EINVAL`”归入现有 post-verify REJIT failure
- 走 daemon 已有的“禁掉最近改动 pass 再重试”回退路径

这样可以先把：

- `dce`
- 必要时再到 `const_prop`

从导致 tail-call poke mismatch 的组合里剥掉，先保住 `map_inline` 的其它收益，再继续定位真正该保留/该禁用的边界。

### 11.10 Tracee versioned inner maps 的 capture/replay 修复已落代码

上一节里写的最小修复现在已经不是“计划”，而是已经落到代码里了：

1. `runner/scripts/capture_map_state.py`
   - 已恢复 raw `bpf()` live dump 路径
   - 不再只抄 daemon 返回的 `inlined_map_entries`
   - 现在会按 `prog_id` 枚举 live program maps，并递归抓取 `HASH_OF_MAPS` / `ARRAY_OF_MAPS` 引用到的 inner maps
2. `runner/src/kernel_runner.cpp`
   - replay 端已支持“fixture 里有、object 里没有”的 inner map
   - 会先创建 fixture-only live inner maps
   - 先填充 inner，再回填 outer map-of-maps entry
   - 同时补上 fixture `map_type` 字符串到 `enum bpf_map_type` 的解析

当前已做的最小验证：

- `python3 -m py_compile runner/scripts/capture_map_state.py`：通过
- `make runner`：通过

这说明：

- Tracee `sys_enter_submit` 之前那条“outer version map 能 replay、但 inner map 根本不存在”的结构性缺口，现在在代码层已经补上
- 剩下要验证的是 VM 上重新跑一轮 Tracee e2e / corpus，确认新的 fixture capture 确实把 inner maps 抓出来并能在 replay 时被消费

### 11.11 Katran warmup 修复后的新权威真值

warmup 接线修复后，我重新跑了一轮：

- artifact:
  - `runner/corpus/results/katran_ablation_map_inline_full_20260327_1_20260327_175405/details/result.json`

这轮的重要意义是：

- 它已经不再受“profile 写的是 `warmups=0/1`，实际 batch 默认跑 5 次 warmup”这个污染项影响
- 因此比前面那些 corpus 数字更适合作为当前 Katran 的权威真值

结果如下：

- baseline `retval = 3`
- rejit `retval = 3`
- baseline `result = 575044581326850`
- rejit `result = 575044581326850`
- baseline `exec_ns = 1643`
- rejit `exec_ns = 2448`
- `speedup_ratio = 0.671x`

代码尺寸：

- baseline JIT `13656`
- rejit JIT `13634`
- `size_ratio = 1.0016x`

pass 结果：

- `compile_passes_applied = [map_inline]`
- `run_passes_applied = [map_inline]`
- `total_sites_applied = 2`
- `verifier_retries = 0`

也就是说，这轮并没有出现：

- `const_prop`
- `dce`

的实质生效；当前 Katran `balancer_ingress` 上真正起作用的仍然只有 2 个安全 `ctl_array` site 的 `map_inline`。

所以 Katran 当前的最新判断应更新为：

1. warmup 污染已经去掉
2. correctness 仍然正确
3. 当前安全 coverage 下 runtime 仍然是明显退化
4. 真正的下一步不是再重复同一轮 corpus，而是：
   - 要么扩大可证明安全的 inline coverage
   - 要么换一个能让 `const_prop + dce` 真正折叠掉长路径的 Katran 配置 / live workload
