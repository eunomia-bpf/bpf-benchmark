# Katran Site Coverage Analysis (2026-03-20)

## 结论

- **Katran 只 apply 4/74 的直接原因** 不是 validator，而是 **policy 选站点太窄**。
  - 当前 live `balancer_ingress` 一致复现为 **74 sites**:
    - `branch-flip=56`
    - `cmov=8`
    - `wide=4`
    - `endian=4`
    - `extract=2`
    - `rotate=0`
    - `lea=0`
  - 旧默认 E2E policy 只列了 `4` 个 `wide-load-2`，所以 runtime 只能 apply `4/74`。
- **更深层的真正问题** 是当前 v3 policy 生成链路仍然基于 **offline object scan + explicit site allowlist**。
  - `scanner scan corpus/build/katran/balancer.bpf.o --program-name balancer_ingress --all --json`
    只看到 **18 object-level sites**:
    - `cmov=8`
    - `wide=4`
    - `extract=2`
    - `endian=4`
    - `branch-flip=0`
  - 也就是说，Katran 的 `56` 个 live `branch-flip` **根本没有进入默认 policy 生成输入**。
  - 这不是“policy 代码显式 skip 了 branch-flip/endian”；而是 **policy 生成看错了 IR 层级**。
- **branch-flip 不是 validator reject**。
  - 我在 VM 里手工生成 live policy，`56/56 branch-flip` 都能 apply，HTTP correctness 也正常。
  - 但当前 workload 上性能明显负面: `wide+branch-flip=60 sites` 的 smoke run 里 BPF `256.8ns -> 347.3ns`，`0.739x`。
  - 所以它是 **coverage 缺口**，但 **不是当前 safe default**。
- **endian 也不是 validator reject**，但它不是“4 个都安全”。
  - 当前 corpus Katran policy 的 `4 endian` 全部能 apply。
  - 但在 VM 里，`4 wide + 4 endian` 会把请求路径直接打坏，post-reJIT 单请求超时。
  - 进一步消融后定位到：
    - `2` 个 `endian-load-swap-32` 一起开：正确
    - `2` 个 `endian-swap-store-16` 一起开：**错误**
    - 任意单个 endian site：正确
    - 任意 `1 load + 1 store`：正确
  - 所以问题不是“endian family 整体不行”，而是 **`endian-swap-store-16` 这对 live sites 的组合级 correctness bug**。
- **安全可落地的改进** 是把 Katran E2E 默认 policy 从 `4 wide` 提升到 **`6 sites = 4 wide + 2 safe endian-load-swap-32`**。
  - 我已更新 `e2e/cases/katran/balancer_ingress.e2e.policy.yaml`。
  - VM 默认路径验证通过:
    - applied sites: `4 -> 6`
    - BPF avg ns: `291.0 -> 321.2`（旧 wide4, `0.906x`）变为 `291.2 -> 279.6`（新 safe6, `1.042x`）
    - correctness: HTTP 成功，IPIP decap 正常

## Phase 1: 根因分析

### 1. Katran 相关 policy 文件

当前相关 policy 有两套：

- `corpus/policies/katran/balancer/balancer_ingress.policy.yaml`
  - 由 `corpus/generate_default_policies.py` 生成
  - 当前文件内容是 `8` 个显式 site:
    - `wide=4`
    - `endian=4`
  - 注释里的 `Total scanner sites: 18` 是 **object scan** 的结果，不是 live result
- `e2e/cases/katran/balancer_ingress.e2e.policy.yaml`
  - E2E case 专用 policy
  - 原来只有 `4` 个 `wide-load-2`
  - 这就是 E2E 里只 apply `4` 个 site 的最直接原因

### 2. 默认 policy 生成逻辑

`corpus/generate_default_policies.py` 的当前行为：

- 它调用 `scanner scan <object> --program-name ... --all --json`
- 然后把 **扫描到的 site 显式写成 v3 allowlist**
- `--skip-families` 只负责排除某些 family，不会凭空生成 live-only family

关键点：

- `parse_args()` 默认 `--skip-families=cmov`
- 但 2026-03-20 的 corpus regen 实际命令是：
  - `python3 corpus/generate_default_policies.py --skip-families cmov,extract`
- 所以：
  - `cmov` 和 `extract` 是 **显式 policy skip**
  - `branch-flip` 不是被 skip；它是 **object scan 根本没看到**
  - `endian` 不是被 skip；它被保留进了 corpus policy，但 E2E policy 另行缩窄成了 wide-only

更深层的问题是：v3 现在又回到了 **offline explicit site allowlist**。这会重新暴露 object/live drift 和 live-only family 问题。Katran 正是这类问题的典型。

### 3. scanner 实际 live enumerate 结果

在 VM guest 里手工 bring-up Katran topology、attach `balancer_ingress` 后，`scan_programs()` 通过
`scanner enumerate --prog-id <id> --all --json` 稳定返回：

| Family | Live sites |
| --- | ---: |
| `branch-flip` | `56` |
| `cmov` | `8` |
| `wide` | `4` |
| `endian` | `4` |
| `extract` | `2` |
| `rotate` | `0` |
| `lea` | `0` |
| **Total** | **`74`** |

当前仓库里一些旧文档提到过 `94` 或 `rotate=20`。在 **2026-03-20 当前 tree + 当前 bzImage + 当前 Katran object** 上，我没有复现 `94`；稳定结果是 `74`。

### 4. family-by-family 为什么没 apply

| Family | Object scan | Live enumerate | 当前为什么没 apply | 结论 |
| --- | ---: | ---: | --- | --- |
| `wide` | `4` | `4` | E2E policy 允许 `4` | 当前唯一默认 apply family |
| `branch-flip` | `0` | `56` | 不是 validator reject；是 **object-based policy generation看不到它**，E2E 也没手写进去 | **主要 coverage 缺口** |
| `endian` | `4` | `4` | corpus policy 允许，E2E 原来不允许 | 但 `4` 全开不安全，只能安全开其中 `2` 个 load-swap |
| `cmov` | `8` | `8` | `--skip-families cmov,extract` 明确排除 | skip 是合理的，旧 corpus ablation 已证明 `balancer_ingress` 上 CMOV 严重负面 |
| `extract` | `2` | `2` | `--skip-families cmov,extract` 明确排除 | 当前不值得优先打开 |
| `rotate` | `0` | `0` | 无 site | 无问题 |
| `lea` | `0` | `0` | 无 site | 无问题 |

### 5. validator / scanner / policy 的责任边界

- **scanner live enumerate 没问题**
  - 它能稳定看到 `56` 个 `branch-flip`
  - 也能稳定看到 `4` 个 `endian`
- **validator 也不是 primary blocker**
  - `56` 个 `branch-flip` 可以 apply
  - `4` 个 `endian` 也可以 apply
- **真正的 blocker 在 policy 层**
  - `branch-flip`：默认 policy 根本没覆盖到
  - `endian`：E2E policy 太窄；而 corpus 8-site policy 又过宽，带入 unsafe store-pair

### 6. 4 个已 apply wide sites 在哪

object disassembly 显示 4 个 wide sites 对应两段重复的 byte-recompose 序列：

- `112/117`
- `263/268`

它们都在做这种模式：

- 读取 `r9 + 0xb / 0xa`
- 读取 `r9 + 0x7 / 0x6`
- 组合成 `u16`

从上下文看，这些 wide sites 不在 LRU / server_id / branch-heavy lookup 主体里，而是在 **packet header rewrite / checksum related** 的前向路径代码里。  
这是基于 disassembly 的推断，不是源码行号级映射。

所以它们的特点是：

- 每个包都会很容易命中
- 但它们只是几个很小的 byte-recompose 优化点
- 即使全部 apply，也不可能解释 Katran 的主要潜力；真正的大头仍然是 `branch-flip=56`

## Phase 2: 改进方案

### 真正安全的短期方案

不要把 `branch-flip` 或 `4 endian` 盲目全开。当前有数据支持的 safe default 是：

- `wide=4`
- `endian-load-swap-32=2`
- 显式排除：
  - `branch-flip`
  - `cmov`
  - `extract`
  - `endian-swap-store-16` pair

我生成了两个分析用 policy：

- `docs/tmp/katran_balancer_safe6_20260320.policy.yaml`
  - `4 wide + 2 safe endian-load`
- `docs/tmp/katran_balancer_wide_bflip60_20260320.policy.yaml`
  - `4 wide + 56 branch-flip`

实测结论：

- `safe6`：功能正确，可作为默认 E2E policy
- `wide+bflip60`：功能正确，但当前 workload 上明显负面，不能作为默认 policy

### 对 corpus / policy pipeline 的改进路线

1. **不要再把 Katran 的 steady-state policy 建在 object scan allowlist 上**
   - 当前 `branch-flip=56` 完全消失，就是因为 `object scan` 看不到它
   - 对 Katran 这类 live-only family 明显的程序，policy source 必须切到 live enumerate
2. **给 Katran 加 program-specific safety filter**
   - 至少要临时排除 `endian-swap-store-16`
   - 否则 `wide+endian` 这种看起来“保守”的 policy 也会打坏 datapath
3. **branch-flip 要按 workload 调**
   - correctness 没问题
   - 但当前 short-flow DSR path 上 perf 明显差
   - 不能因为 coverage 大就默认打开

## Phase 3: 实施 + VM 验证

### 1. 已实施的改动

更新了默认 E2E policy：

- 文件：`e2e/cases/katran/balancer_ingress.e2e.policy.yaml`
- 旧：`4 wide`
- 新：`4 wide + 2 endian-load-swap-32`

并在文件顶部加了注释，明确说明：

- `endian-swap-store-16` pair 故意不打开
- 原因是 guest-verified correctness failure

### 2. VM 验证结果

为了避免当前 `--smoke` 默认 `packet_repeat=4` 的 traffic-driver 抖动，我用同一个 E2E harness 走 VM 路径验证，但把 `--katran-packet-repeat` 固定为 `1`，这样能稳定复现 datapath 与 site coverage。

#### Baseline: 旧默认 E2E policy（`wide=4`）

Artifact:

- `docs/tmp/katran_sitecov_baseline_wideonly_rpt1_20260320.json`

结果：

- applied sites: `4`
- family: `wide=4`
- BPF avg ns: `291.0 -> 321.2`
- speedup: `0.906x`
- correctness: OK

#### Unsafe corpus policy（`wide=4 + endian=4`）

Artifacts / evidence:

- official `e2e/run.py katran --vm ... --katran-policy corpus/policies/katran/balancer/balancer_ingress.policy.yaml`
  在 post-reJIT warmup 阶段直接失败，未产出 JSON
- guest 手工 apply 复现：post-reJIT 单请求超时

结论：

- `8` 个 site 都能 apply
- 但 correctness 不通过
- 根因收敛到 `endian-swap-store-16` pair

#### Experimental `wide + branch-flip = 60 sites`

Artifact:

- `docs/tmp/katran_sitecov_bflip60_rpt1_20260320.json`

结果：

- applied sites: `60`
- family: `wide=4`, `branch-flip=56`
- correctness: OK
- BPF avg ns: `256.8 -> 347.3`
- speedup: `0.739x`

结论：

- `branch-flip` 是可 apply 的
- 但在当前 Katran DSR short-flow path 上，不适合作为默认 policy

#### Final: 新默认 E2E policy（`safe6`）

Artifact:

- `docs/tmp/katran_sitecov_default_safe6_rpt1_20260320.json`

结果：

- applied sites: `6`
- family: `wide=4`, `endian=2`
- BPF avg ns: `291.2 -> 279.6`
- speedup: `1.042x`
- packet PPS delta: `+1.15%`
- correctness: OK

## 最终判断

### 真正的根因

1. **E2E 本地配置问题**
   - 默认 Katran E2E policy 被手工缩成了 `4 wide`
2. **更深层的系统性问题**
   - v3 默认 policy 生成仍依赖 `object scan + explicit allowlist`
   - Katran 的 `branch-flip` 是 live-only family，offline object scan 看不到
   - 所以默认 policy 不可能自动覆盖到 `56` 个 live `branch-flip`
3. **额外的 correctness 风险**
   - `endian-swap-store-16` pair 当前能通过 apply，但会破坏 Katran datapath
   - 说明仅凭 validator “可 apply” 还不够，Katran 需要 program-specific safety gating

### 这次实际改进了什么

- 默认 Katran E2E policy 从 `4` site 提升到 **`6` site**
- 保持 correctness
- 在当前稳定 smoke 配置下把 BPF 结果从一次 `0.906x` 的 wide-only regression，拉到 **`1.042x` 的 safe6 positive result**

### 后续路线图

1. **短期**
   - 保持当前默认 E2E `safe6`
   - 明确不要再把 `store-pair` 加回去
2. **中期**
   - 给 Katran 增加 live-enumerate-based policy generation / refresh
   - 让 `branch-flip` 至少能进入候选集，而不是在 object scan 阶段直接丢失
3. **长期**
   - 单独调查 `endian-swap-store-16` pair 的 emitter / validation correctness
   - 修完之前，不要在 Katran 上默认开启这两个 site
4. **branch-flip**
   - 当前只证明了 “functional yes, perf no”
   - 需要按 workload / branch distribution 单独调，不能做默认全开
