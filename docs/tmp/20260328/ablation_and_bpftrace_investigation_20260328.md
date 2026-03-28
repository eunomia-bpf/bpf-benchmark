# Ablation Study 设计与 bpftrace 0-ReJIT 调查

日期: 2026-03-28

## 结论摘要

- `corpus/config/benchmark_config.yaml` 目前已经有 6/7 个目标 ablation profile，缺的是 `no pass` baseline。
- 现有 ablation profile 不对称: 默认是 `iterations=3`, `warmups=1`, `repeat=200`，只有 `ablation_map_inline_full` 把 `repeat` 提到了 `500`。这不适合作为最终 SOSP paper numbers。
- 推荐把 `corpus` 作为主 ablation 载体，完整跑 7 点矩阵；`e2e` 只跑精选子集做 external validity；`micro` 只做机制级 sanity/control，不适合承载完整 7 点矩阵。
- 最新 bpftrace E2E (`e2e/results/bpftrace_20260328_143337`) 不是“daemon 坏了”，而是“当前选择的 pass 集合不覆盖 bpftrace 的命中站点”。
- 证据是: 最新 bpftrace 有 21 个 eligible sites，全部是 `wide_mem`；但这次 E2E 选择的 pass 只有 `map_inline,const_prop,dce`，没有 `wide_mem`。
- 次要问题是观测性: `e2e/cases/bpftrace/case.py` 只有在 `rejit_apply["applied"] == true` 时才写 post-ReJIT 结果，所以 latest artifact 里没有留下可直接查看的 daemon apply 日志。

## 第一部分: Ablation Study 设计

### 1. 现有 profile 盘点

`corpus/config/benchmark_config.yaml:1-46` 当前内容如下:

- `defaults`: `iterations=3`, `warmups=1`, `repeat=200`
- `passes.performance`: `map_inline`, `const_prop`, `dce`
- `profiles.dev`
- `profiles.strict`: `iterations=10`, `warmups=2`, `repeat=500`
- `profiles.ablation_map_inline`: `[map_inline, const_prop, dce]`
- `profiles.ablation_map_inline_only`: `[map_inline]`
- `profiles.ablation_const_prop_only`: `[const_prop]`
- `profiles.ablation_dce_only`: `[dce]`
- `profiles.ablation_map_inline_const_prop`: `[map_inline, const_prop]`
- `profiles.ablation_map_inline_full`: `[map_inline, const_prop, dce]` with `repeat=500`
- `profiles.ablation_wide_mem`: `[wide_mem]`

现状判断:

- 已覆盖用户要求中的 6 个 profile。
- 缺少 `no pass` / zero-pass baseline。
- `ablation_map_inline` 和 `ablation_map_inline_full` 实际上都是 “all passes”，命名重复且容易混淆。
- `strict` 不能和 ablation profile 叠加使用；`vm-corpus` 一次只能选一个 profile。

### 2. 推荐的完整 ablation matrix

主张: `corpus` 跑完整 7 点矩阵，`e2e` 跑精选子集，`micro` 只做辅助。

| Ablation | Pass 集合 | micro | corpus | e2e | 备注 |
| --- | --- | --- | --- | --- | --- |
| all passes | `map_inline,const_prop,dce` | 不建议作为主表 | 必跑 | 必跑 | SOSP 主线配置 |
| map_inline only | `map_inline` | 不建议 | 必跑 | 建议跑 | 证明 map specialization 独立贡献 |
| const_prop only | `const_prop` | 可选 | 必跑 | 建议跑 | micro 里有少量命中，但不够当主表 |
| dce only | `dce` | 不建议 | 必跑 | 建议跑 | 主要看 real programs 上的清理收益 |
| map_inline + const_prop | `map_inline,const_prop` | 不建议 | 必跑 | 可选 | 用来证明 `dce` 是否提供额外边际收益 |
| wide_mem only | `wide_mem` | 建议做 control | 必跑 | 必跑 | 机制对照；bpftrace 当前尤其需要 |
| no pass | 空 | 当前无直达命令 | 必跑 | 必跑 | zero-pass baseline |

### 3. 每个 workload 层应该怎么用

#### micro

不建议把 `micro` 作为完整 7 点 ablation 的主载体，原因有两个:

- 接口不支持按 pass 子集直接跑。`runner/Makefile:309-317` 的 `vm-micro` 只调用 `micro/driver.py`；`micro/driver.py:58-119` 没有 `--enabled-passes` 之类的 CLI。
- 底层 batch runner 虽然支持 `enabled_passes`，但只是 `runner/src/batch_runner.cpp:1263` 和 `runner/src/batch_runner.cpp:1316` 支持；`micro/driver.py:430-497` 并没有把它传下去。

从已有 `micro/results/*.json` 看，命中基本集中在 `wide_mem`，少量是 `const_prop`，没有看到 `map_inline` / `dce` 的已有命中记录。因此:

- `micro` 只建议跑 `all/default` 和 `wide_mem only` 这种机制级 control。
- 不建议把 `map_inline only` / `dce only` 的论文主结论建立在 micro 上。

#### corpus

`corpus` 应该是 SOSP ablation 的主表，原因:

- 接口已经支持按 profile 选择 pass 组合。见 `corpus/modes.py:177-242`。
- 当前已有多组 `ablation_*` profile，说明这就是 repo 现有的 intended path。
- corpus 规模足够大，能同时体现覆盖率、命中率和真实性能收益。

推荐:

- 完整 7 点矩阵全部在 `corpus` 上跑。
- 论文主表、主图、主结论都以 `corpus` 为准。

#### e2e

`e2e` 用来补 external validity，不建议把所有 case 都乘上完整 7 点矩阵。

推荐 case:

- `bpftrace`
- `tracee`
- `tetragon`

不推荐第一轮就把 `bcc` / `katran` / `scx` 全部加入 ablation，原因是实验成本高、论文增益有限。

推荐的 e2e 组合:

- 必跑: `all passes`
- 必跑: `wide_mem only`
- 必跑: `no pass`
- 建议跑: `map_inline only`
- 建议跑: `const_prop only`
- 建议跑: `dce only`
- 可选: `map_inline + const_prop`

其中 `bpftrace` 必须保留 `wide_mem only`，因为它当前的 site-positive 脚本基本都是 `wide_mem` 命中。

### 4. 迭代 / repeat 建议

#### 论文级推荐值

- `micro`: `iterations=10`, `warmups=2`, `repeat=500`
- `corpus`: `iterations=10`, `warmups=2`, `repeat=500`
- `e2e`: 保持单次 case 内部的 `30s baseline + 30s post-ReJIT`，每个 ablation 做 `3` 次独立完整运行

理由:

- `strict` profile 已经给出 `10/2/500`，这就是 repo 里现成的 publication-grade 量级。
- e2e 每个 phase 已经是 30 秒，没必要再把单次 case 内部 repeat 做得更复杂，独立重跑 3 次更稳妥。

#### 当前 repo 的现实约束

- `vm-corpus` 目前不能把 `strict` 和 `ablation_*` 组合起来。
- 所以现有 profile 下，除了 `ablation_map_inline_full` 之外，其余 ablation 都还是 `3/1/200`。
- 这意味着: 现在可以做 preliminary ablation；最终 paper run 之前，需要补一套对称的 strict ablation profiles。

### 5. 推荐执行顺序

建议按下面顺序做:

1. `corpus` 先跑完整 7 点矩阵，拿主表。
2. `e2e` 再跑 `bpftrace/tracee/tetragon` 的精选子集，验证真实系统上的趋势是否一致。
3. `micro` 最后只补 control 图，不承担独立贡献证明。

### 6. 可直接复制的 Makefile 命令

以下分成 “今天就能直接跑” 和 “当前接口缺口”。

#### 6.1 corpus: 今天可直接跑的 profile

```bash
make vm-corpus PROFILE=ablation_map_inline_full
make vm-corpus PROFILE=ablation_map_inline_only
make vm-corpus PROFILE=ablation_const_prop_only
make vm-corpus PROFILE=ablation_dce_only
make vm-corpus PROFILE=ablation_map_inline_const_prop
make vm-corpus PROFILE=ablation_wide_mem
```

当前缺口:

- 没有 zero-pass profile，所以今天不能直接执行 `make vm-corpus PROFILE=<zero-pass>`。
- 如果要做最终 paper run，也还缺一套对称的 strict ablation profiles。

#### 6.2 e2e: 今天可直接跑的 pass 组合

以下命令对 `bpftrace` / `tracee` / `tetragon` 都适用，把 `E2E_CASE=` 替换成对应 case 即可。

```bash
make vm-e2e E2E_CASE=bpftrace E2E_ARGS='--rejit-passes map_inline,const_prop,dce'
make vm-e2e E2E_CASE=bpftrace E2E_ARGS='--rejit-passes map_inline'
make vm-e2e E2E_CASE=bpftrace E2E_ARGS='--rejit-passes const_prop'
make vm-e2e E2E_CASE=bpftrace E2E_ARGS='--rejit-passes dce'
make vm-e2e E2E_CASE=bpftrace E2E_ARGS='--rejit-passes map_inline,const_prop'
make vm-e2e E2E_CASE=bpftrace E2E_ARGS='--rejit-passes wide_mem'
make vm-e2e E2E_CASE=bpftrace E2E_ARGS='--rejit-passes ""'
```

```bash
make vm-e2e E2E_CASE=tracee E2E_ARGS='--rejit-passes map_inline,const_prop,dce'
make vm-e2e E2E_CASE=tracee E2E_ARGS='--rejit-passes map_inline'
make vm-e2e E2E_CASE=tracee E2E_ARGS='--rejit-passes const_prop'
make vm-e2e E2E_CASE=tracee E2E_ARGS='--rejit-passes dce'
make vm-e2e E2E_CASE=tracee E2E_ARGS='--rejit-passes map_inline,const_prop'
make vm-e2e E2E_CASE=tracee E2E_ARGS='--rejit-passes wide_mem'
make vm-e2e E2E_CASE=tracee E2E_ARGS='--rejit-passes ""'
```

```bash
make vm-e2e E2E_CASE=tetragon E2E_ARGS='--rejit-passes map_inline,const_prop,dce'
make vm-e2e E2E_CASE=tetragon E2E_ARGS='--rejit-passes map_inline'
make vm-e2e E2E_CASE=tetragon E2E_ARGS='--rejit-passes const_prop'
make vm-e2e E2E_CASE=tetragon E2E_ARGS='--rejit-passes dce'
make vm-e2e E2E_CASE=tetragon E2E_ARGS='--rejit-passes map_inline,const_prop'
make vm-e2e E2E_CASE=tetragon E2E_ARGS='--rejit-passes wide_mem'
make vm-e2e E2E_CASE=tetragon E2E_ARGS='--rejit-passes ""'
```

原因说明:

- `e2e/run.py:177-181` 已经支持 `--rejit-passes`，并明确说明空字符串就是 zero-pass。
- `e2e/run.py:391-392` 会把它传成环境变量 `BPFREJIT_BENCH_PASSES`。

#### 6.3 micro: 当前没有 row-level pass ablation 的直达 Makefile 命令

今天能直接跑的只有默认 pipeline:

```bash
make vm-micro
```

但这不是完整 ablation matrix 的合格入口，因为:

- 没法像 `e2e` 那样显式传 `--rejit-passes`
- 没法像 `corpus` 那样通过 profile 选择 pass 子集

结论:

- 不要承诺 “micro 上完整 7 点矩阵今天可直接跑”
- 如果要补这个能力，应单独加 micro profile / batch-spec plumbing

## 第二部分: bpftrace 0 ReJIT 调查

### 1. `e2e/cases/bpftrace/case.py` 里的 ReJIT 流程

`e2e/cases/bpftrace/case.py:332-410` 的关键流程是:

1. 启动 bpftrace 脚本。
2. 等待程序 attach，收集 `prog_ids`。
3. 对 live programs 做 `scan_programs()`，统计 eligible sites。
4. 先测 baseline。
5. 调用:

```python
rejit_apply = apply_daemon_rejit(
    daemon_binary,
    prog_ids,
    enabled_passes=benchmark_rejit_enabled_passes(),
)
```

6. 只有 `rejit_apply["applied"]` 为真时，才会生成 `post_rejit` 结果。

这有两个直接后果:

- apply 失败时没有 post-ReJIT 结果。
- apply 返回 “ok but no_change” 时，同样没有 post-ReJIT 结果。

### 2. 最新 bpftrace E2E 结果现状

最新目录是:

- `e2e/results/bpftrace_20260328_143337`

`e2e/results/bpftrace_20260328_143337/details/result.md:15-31` 显示:

- `Scripts selected: 6`
- `Baseline successes: 6`
- `ReJIT successes: 0`
- `Eligible-site scripts: 4`
- `Aggregate sites: 21 (cmov=0, wide=21, rotate=0, lea=0)`

逐脚本看:

- `tcplife`: 8 sites, post-ReJIT 缺失
- `biosnoop`: 4 sites, post-ReJIT 缺失
- `tcpretrans`: 3 sites, post-ReJIT 缺失
- `capable`: 6 sites, post-ReJIT 缺失
- `runqlat`: 0 sites
- `vfsstat`: 0 sites

同时，`e2e/results/bpftrace_20260328_143337/metadata.json:2135-2139` 显示:

- `selected_rejit_passes = ["map_inline", "const_prop", "dce"]`

这和上面的 site summary 拼起来就是一个非常强的信号:

- 有站点，而且全是 `wide_mem` 站点。
- 但本次根本没开 `wide_mem`。

### 3. daemon apply 的日志 / 错误在哪里

我检查了最新目录下的所有文件:

- `details/progress.json`
- `details/report.md`
- `details/result.json`
- `details/result.md`
- `metadata.json`

没有单独的 daemon stdout/stderr artifact。

在这个目录里搜索 `REJIT ok` / `passes_applied` / daemon apply 结果，也没有最新 bpftrace 的持久化记录。也就是说:

- 最新 artifact 并没有留下可直接查看的 daemon apply 输出。
- 这不是因为我没找到路径，而是因为当前 harness 没把它保存下来。

根因是 `bpftrace/case.py` 的持久化条件太严格:

- 只有 `rejit_apply["applied"] == true` 才写 `rejit` 段
- 否则 latest result 只能看到 baseline，看不到 apply 返回的是 error 还是 no-change

### 4. 为什么 ReJIT 没有生效

#### 根因

根因不是 bpftrace attach 失败，也不是没有 eligible sites，而是 pass-set mismatch。

证据链如下:

1. 最新 bpftrace 结果有 21 个 eligible sites，且全部是 `wide_mem`。
2. 最新 bpftrace metadata 记录的 `selected_rejit_passes` 只有 `map_inline,const_prop,dce`。
3. `runner/libs/rejit.py:31-79` 里，`benchmark_rejit_enabled_passes()` 会从 `corpus/config/benchmark_config.yaml` 读默认 pass 集。
4. `corpus/config/benchmark_config.yaml:8-13` 当前 `passes.performance` 就是 `map_inline,const_prop,dce`。
5. 所以 bpftrace E2E 实际上传给 daemon 的默认 pass 集，不包含 `wide_mem`。

据此推断:

- 最新 bpftrace 大概率不是 “daemon 报错”。
- 更可能是 daemon 正常执行了 `map_inline/const_prop/dce`，但这些 pass 对当前 21 个 `wide_mem` 站点都没有变化，因此返回了 no-change。

这里是推断，但它和现有证据完全一致。

#### 历史对照

`e2e/results/bpftrace_20260327_013320/metadata.json:2233` 能看到历史成功样本，里面明确写了:

- `passes_applied: ["wide_mem"]`

而且这个历史样本是 `capable`，正好是最新 run 里同样 site-positive 但 post-ReJIT 消失的脚本之一。

这说明:

- bpftrace 的 ReJIT 路径以前是通的。
- 当前 “0 ReJIT data” 的回归，与 `wide_mem` 被排除在默认 pass 集之外高度一致。

#### 回归引入点

最可疑的两个提交是:

- `3da9e45 Add support for enabling optimization passes in ReJIT`
- `ba9f398 Enhance benchmark configuration handling in rejit.py`

推断的回归链:

1. `3da9e45` 把 bpftrace E2E 改成显式传 `enabled_passes=benchmark_rejit_enabled_passes()`。
2. 同时 benchmark config 的主 performance 集被收窄成 `map_inline,const_prop,dce`。
3. `ba9f398` 又把 `runner/libs/rejit.py` 的默认行为改成从 `benchmark_config.yaml` 读取 pass 集。
4. 结果就是: E2E 也隐式继承了 corpus 的 3-pass performance 配置。

这对 `tracee` / `tetragon` 不一定是错的，但对当前 `bpftrace` 明显不对，因为它的有效站点目前主要在 `wide_mem`。

### 5. 次要但真实存在的 harness 问题

`runner/libs/rejit.py:572-642` 里，`apply_daemon_rejit()` 对多程序脚本的聚合规则是:

- `all_applied = all_applied and bool(result["applied"])`
- 最终返回 `{"applied": all_applied, ...}`

这意味着:

- 只要一个子程序没有 `applied=true`，整个脚本级别就会被视为 “not applied”
- 对多程序 bpftrace 脚本来说，这个判定过于严格

它不是本次 “全部 0 数据” 的主根因，因为 `capable` / `tcpretrans` 这种单程序脚本也一起回归了；但它确实会继续放大未来的观测缺口。

### 6. 修复方案

#### 立刻可用的操作性修复

如果目标只是恢复 bpftrace 的 post-ReJIT 数据，直接这样跑:

```bash
make vm-e2e E2E_CASE=bpftrace E2E_ARGS='--rejit-passes wide_mem'
```

如果想保留主线 3 个 pass 再额外允许 `wide_mem`:

```bash
make vm-e2e E2E_CASE=bpftrace E2E_ARGS='--rejit-passes map_inline,const_prop,dce,wide_mem'
```

#### 代码层面的正确修复方向

1. 不要让 E2E 默认继承 `corpus/config/benchmark_config.yaml` 的 `passes.performance`。
2. E2E 应该有自己的默认 pass policy，或者要求 case 显式传 `--rejit-passes`。
3. `bpftrace/case.py` 应该无论 `applied` 是否为真，都持久化 `rejit_apply` 的返回内容。
4. script-level success 不应只接受 “所有 prog 都 applied”；更合理的是:
   - 记录 partial apply
   - 或者至少用 `any(program_changed)` 决定是否生成 post-ReJIT phase

#### 对论文实验的直接影响

- 如果主 ablation 把 `wide_mem` 定义为 control，而不是主线 pass，那么最新 bpftrace 结果中 “all passes = 0 ReJIT data” 是合理现象，不是坏数据。
- 但这时必须再配一组 `wide_mem only`，否则读者会误以为 bpftrace 根本没有 ReJIT 机会。
- 如果想让 bpftrace 继续作为正例，就必须显式开启 `wide_mem`。

## Bottom Line

- SOSP ablation 主表应放在 `corpus`，完整跑 7 点矩阵。
- `e2e` 只跑精选子集，重点保留 `bpftrace/tracee/tetragon`。
- `micro` 不适合承载完整矩阵，因为当前接口不支持 pass 子集，且已有覆盖以 `wide_mem` 为主。
- 最新 bpftrace 0 post-ReJIT 的直接原因是: 当前默认 pass 集是 `map_inline,const_prop,dce`，而最新命中的 21 个站点全部属于 `wide_mem`。
- 当前 harness 还把 no-change / apply-failed 都折叠成 “没有 post-ReJIT 记录”，导致日志不可见；这应当单独修。
