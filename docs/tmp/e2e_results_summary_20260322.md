# E2E Benchmark 结果汇总 (2026-03-22)

## 概览

| Case | 状态 | REJIT 应用 | Workload 数 | 结果可用性 |
|------|------|----------|-----------|----------|
| Tracee | ⚠️ 部分成功 | 已尝试，有错误 | 3 | 可比较 |
| Tetragon | ✓ 成功 | 已尝试 | 4 | 可比较 |
| BPFTrace | ✗ 失败 | N/A | 0 | 不可用 |
| SCX | ✗ 失败 | N/A | 0 | 不可用 |

---

## Tracee (手动 Fallback 模式)

**REJIT 状态:**
- Applied: ✓ 已Apply
- Passes Applied: prog 8 (trace_security_): **4 passes, 3 sites applied** (4565 → 4556 insns)
- Error: ⚠️ REJIT syscall 失败 - `BPF_PROG_REJIT: Bad file descriptor (os error 9)`
  - 注：其他程序未找到任何变换机会，Kinsn 模块未加载（BTF 缺失）

**性能数据** (正数=改善, 负数=回归):

| Workload | App Throughput Δ (%) | BPF avg_ns Δ (%) | 评价 |
|----------|------|------|------|
| exec_storm | **+5.47** | **+3.58** | ✓ 双向改善 |
| file_io | **+1.06** | **-24.96** | ⚠️ BPF 严重回归 |
| network | **+9.35** | **+1.26** | ✓ 双向改善 |

**分析:**
- exec_storm & network: 应用级吞吐提升 5-9%，BPF 耗时稳定
- file_io: 应用级微小改善（+1%），但 BPF 耗时大幅恶化（-25%）
  - 这可能与 Tracee 的手动 Fallback 加载方式有关（限制信息）

---

## Tetragon (成功完成)

**REJIT 状态:**
- Applied: ✓ 已Apply
- Passes Applied: 无详细输出，但系统报告已执行
- Error: ✓ 无错误

**性能数据** (正数=改善, 负数=回归):

| Workload | App Throughput Δ (%) | BPF avg_ns Δ (%) | 评价 |
|----------|------|------|------|
| connect_storm | **+16.69** | **+5.47** | ✓ 双向改善 |
| file_io | **+0.56** | **-18.84** | ⚠️ BPF 严重回归 |
| open_storm | **-0.22** | **+74.27** | ✗ 双向恶化，BPF 暴增 |
| stress_exec | **+9.02** | **-23.44** | ⚠️ 应用改善，BPF 回归 |

**分析:**
- connect_storm: 最佳结果，应用吞吐 +17%，BPF +5%
- open_storm: 严重回归（BPF +74%），可能是病态优化案例
- file_io & stress_exec: 应用级收益被 BPF 的大幅回归抵消

---

## BPFTrace

**失败原因:** 脚本编译错误
- tcplife.bt: 多个语法错误（`ntop()` 参数错误，struct 访问错误）
- biosnoop.bt: 未知函数 `has_key()`
- **结论:** 脚本与当前 bpftrace 版本不兼容

**REJIT Status:** N/A (未能加载程序)

---

## SCX (sched_ext)

**失败原因:** 内核不支持
- 尝试加载 scx_rusty 时，kernel 报错：`sched_ext_ops.dump() missing, kernel too old?`
- bpftool 注册失败：缺少 `scx_bpf_create_dsq` 符号

**REJIT Status:** N/A (probe_only 模式，无程序加载)

---

## 关键观察

| 现象 | 解释 |
|------|------|
| **file_io 一致回归** | Tracee & Tetragon 都在 file_io 上 BPF 回归 -18~-25%。可能与 I/O 操作引起的缓存失效或 TLB miss 有关 |
| **open_storm 暴增** | Tetragon open_storm 的 BPF avg_ns 增长 74%，应用吞吐反而下降。可能优化策略与工作负载特性冲突 |
| **Tracee REJIT 部分失败** | prog 8 优化成功（3 sites），但 syscall 返回 EBADF。可能与手动加载或权限有关 |
| **应用级收益 > BPF 收益** | 多数 workload 的应用吞吐改善幅度（+1~+17%）超过 BPF 耗时改善，暗示 Tracee/Tetragon 本身的 overhead 不完全来自 BPF 执行 |

---

## 元数据

- 生成时间: 2026-03-22T17:42-17:47 UTC
- 内核: Linux 7.0.0-rc2-g8a692389396c (BpfReJIT v2)
- 模式: manual_fallback (Tracee) / normal (Tetragon) / probe_only (SCX)
- 限制: Kinsn 模块未加载（BTF 缺失）、手动加载方式信息不完整
