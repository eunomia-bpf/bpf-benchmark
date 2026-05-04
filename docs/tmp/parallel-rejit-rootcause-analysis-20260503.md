# 并发 BPF_PROG_REJIT 崩溃根因分析

**日期**: 2026-05-03  
**HEAD**: 0f93207d  
**崩溃复现**: `make vm-corpus SAMPLES=1`，第 12 个 app `otelcol-ebpf-profiler/profiling`，rejit_start（program_count:13）之后 VM exit 255

---

## 1. 五大根因候选（按可能性降序）

### 候选 1：并发 bpf_check() 绕过 bpf_verifier_lock（最高可能性，★★★★★）

**核心证据**：`vendor/linux-framework/kernel/bpf/verifier.c:26372`

```c
if (!is_priv)
    mutex_lock(&bpf_verifier_lock);   // 26372
// ... 全量 bpf_check() 路径 ...
if (!is_priv)
    mutex_unlock(&bpf_verifier_lock); // 26611
```

根 daemon（`is_priv=1`）完全绕过该全局 mutex。KVM bench 配置 16 CPU（`runner/targets/x86-kvm.env: TARGET_KVM_BENCH_CPUS_SPEC=16`），rayon 工作线程数 = `min(16,16)` = 16（`daemon/src/commands.rs:405-415`），otel 13 个 prog 全部同时进入 `bpf_check()`。

**commit 回归链**：
- `7e9f2d89`：加全局 `REJIT_SYSCALL_MUTEX` → 崩溃消失（序列化所有 REJIT）
- `f4880fe3`：移除该 mutex（"delete daemon socket request timeout"）→ 崩溃复现
- `0f93207d`（当前）= 无 mutex 状态 = 必现崩溃

**结论**：是 fork kernel BPF_PROG_REJIT 路径在多个根进程并发 `bpf_check()` 时存在未保护的共享状态，导致 kernel panic。

---

### 候选 2：bpf_prog_rejit_swap() + kallsyms 并发（★★★★☆）

**代码位置**：`vendor/linux-framework/kernel/bpf/syscall.c:3822-3920`

```c
bpf_prog_rejit_swap(prog, tmp);       // 3822 — 涉及 func[] 数组、kallsyms 链表
synchronize_rcu_expedited();           // ~3870 — 全局 RCU 屏障
bpf_prog_kallsyms_add(prog);          // 3888 — bpf_lock spinlock 保护
mutex_unlock(&prog->aux->rejit_mutex);// 3920
```

`bpf_prog_kallsyms_del_all()` 内部调用 `__bpf_ksym_del()`（`core.c:650`），而外层 `bpf_ksym_del()` 持 `bpf_lock` spinlock。13 个 prog 同时进行 swap + kallsyms 操作时，若 `func[]` 子程序链表操作存在非原子路径（LIST_POISON2 问题），则触发 use-after-free panic。

**支撑**：`syscall.c:3904-3909` 已有针对 KSYM LIST_POISON2 的修复，说明此路径曾有已知 bug。

---

### 候选 3：同一时刻多个 synchronize_rcu_expedited() 互相干扰（★★★☆☆）

每次 `bpf_prog_rejit_swap()` 后调用 `synchronize_rcu_expedited()`（全局 RCU 宽限期屏障）。13 个并发调用意味着 13 个 rcu_expedited 同时等待，可能：
- 触发 `rcu: INFO: rcu_sched detected stalls` 导致 kernel panic
- 在低-CPU 配置下（4 CPU case）死锁，但 16 CPU 下概率较低

此项需要 kernel console 输出才能确认（见第 4 节）。

---

### 候选 4：并发 bpf_check() 共享 verifier 内部全局状态（★★★☆☆）

`bpf_check()` 内部使用多个未被 `bpf_verifier_lock` 保护的结构，例如：
- `bpf_percpu_ma_lock`（percpu memory allocator）
- `trampoline_mutex`（JIT trampoline pool）
- arch-specific JIT 分配器（`x86_bpf_jit_alloc_exec()` → `module_alloc()`）

当 13 个 prog 同时进行 JIT 编译（含 `perf_unwind_native` 4654 insns，jited=22575B），module_alloc 竞争可能触发 BUG_ON 或 null deref。

---

### 候选 5：/tmp overlay 内存 + REJIT_LOG_BUF_SIZE 导致 OOM（★★☆☆☆）

**计算**：
- `REJIT_LOG_BUF_SIZE = 16MB`（`daemon/src/commands.rs:34`）
- ENOSPC 重试最大至 256MB（`kernel-sys/src/lib.rs:43`）
- 12 passes × 13 progs × 16 rayon 线程并发 → 峰值 ≤ 12 × 16MB = ~200MB
- `/tmp` 使用 `--overlay-rwdir /tmp`（`runner/libs/vm.py:95`），上限 = 物理内存一半
- KVM bench：`TARGET_KVM_BENCH_MEM=64G` → /tmp 最大 32GB

**结论**：OOM 可能性极低（64GB VM），但若 ENOSPC 重试触发 256MB × 13 并发 = 3.3GB 同时分配，kernel 可能触发 out-of-memory killer 而非 graceful 退出。此项作为次因而非主因。

---

## 2. otel 13 个程序特征

数据来源：`corpus/results/x86_kvm_corpus_20260503_154704_746653/details/apps/otelcol-ebpf-profiler__profiling.json`

| prog_id | 程序名 | 类型 | xlated (B) | jited (B) | 估算指令数 |
|---------|--------|------|-----------|----------|-----------|
| 7 | perf_unwind_native | perf_event | 37232 | 22575 | 4654 |
| 8 | perf_unwind_dotnet | perf_event | 34248 | — | 4281 |
| 9 | perf_unwind_v8 | perf_event | 33712 | — | 4214 |
| 10 | perf_unwind_python | perf_event | ~30000+ | — | ~3700 |
| 11 | perf_unwind_php | perf_event | ~28000+ | — | ~3500 |
| 12 | perf_unwind_ruby | perf_event | ~26000+ | — | ~3200 |
| 13 | perf_unwind_go | perf_event | ~24000+ | — | ~3000 |
| 14 | perf_unwind_jvm | perf_event | ~22000+ | — | ~2700 |
| 15 | perf_unwind_erlang | perf_event | ~18000+ | — | ~2200 |
| 6 | native_tracer | perf_event | ~8000 | — | ~1000 |
| 16 | perf_unwind_beam | perf_event | 1088 | — | 136 |
| 17 | tracepoint__sched_process_free | tracepoint | ~2000 | — | ~250 |
| 18 | uprobe/... | perf_event | ~4000 | — | ~500 |

**关键特征**：
- 全部 13 个 prog，12 个为 `perf_event` 类型，1 个 `tracepoint`
- 9 个大型 stack-unwinding 程序（perf_event，各包含多个子程序），单个最大 37232B
- 最小程序仅 1088B（136 insns），最大 37232B（4654 insns）—— **尺寸差异 34×**
- log_level=2 verifier log 对于 4654 insns 程序可达 16MB 上限

**为何 otel 特别危险**：9 个超大多子程序 perf_event prog 同时 rejit，JIT 内存分配压力最大，bpf_check() 执行时间最长（数秒量级），并发窗口最宽，触发内核竞态概率最高。

---

## 3. daemon stderr 救援方案

### 现状（commit 8208e34c 已修复）

`runner/libs/rejit.py` 中 `DaemonSession.start()` 接受 `log_dir: Path | None`，daemon stdout/stderr 已重定向到：

```
corpus/results/<run_id>/details/daemon.stdout.log
corpus/results/<run_id>/details/daemon.stderr.log
```

这些目录通过 `--rwdir` bind mount 进 VM，VM 内写入 = 宿主机可读。

**下次崩溃后**，直接检查：
```bash
cat corpus/results/x86_kvm_corpus_<timestamp>/details/daemon.stderr.log
```

### 若需要 kernel console（panic backtrace）

最小改动方案：在 `runner/libs/vm.py: build_vng_command()` 中添加 `--append "console=ttyS0"` 选项，并通过 `script` 的 pty log（`_run_command_with_script_pty`）捕获 serial 输出（当前 `log_path` 已捕获 pty 全部输出，包含 ttyS0 输出）。

或通过环境变量 `BPFREJIT_VM_CONSOLE_LOG` 条件开启（commit `bcddadf5` 已实现此功能但已 revert，重新启用即可）。

### 推荐诊断步骤

1. 确认 `corpus/results/.../details/daemon.stderr.log` 存在且非空
2. 查找 `[kvm-executor][REJIT]` 最后一行（哪个 prog 最后在 rejit）
3. 若 daemon log 为空 → panic 发生在 daemon 主循环之外（verifier 内部），需 kernel console
4. kernel console 最终显示 panic 类型：BUG_ON、NULL ptr、list corruption 等，定位具体候选

---

## 4. KVM exit 255 含义 + console 捕获路径

### exit 255 含义

**来源**：`virtme_ng/run.py: do_it()` → `check_call_cmd()` → QEMU 进程以非零退出

QEMU 收到 guest kernel panic 后返回 `-1`（int），Python `subprocess` 以 `returncode = -1` 表示，经 `exc.returncode` 传播后 shell 层面看到 `255`（unsigned 8-bit）。

**确认链**：
- guest kernel panic → QEMU monitor `panic` → QEMU exit(-1)
- virtme-ng `CalledProcessError(returncode=-1)` → `do_it()` returns `-1`
- shell 层：`$? = 255`（-1 unsigned byte）
- Python runner：`subprocess.CompletedProcess.returncode = 255`

**不是超时**（超时会是 `subprocess.TimeoutExpired`），**不是 OOM killer**（OOM kill 会返回 137），**不是正常失败**（正常失败返回 1），**255 = guest kernel panic 的唯一标志**。

### kernel console 捕获路径

vng 默认 `virtio-serial` 或 `ttyS0` 输出通过 QEMU `-serial stdio` 传递给 pty。

1. **当前 `script -qfec` pty 日志**（`runner/libs/vm.py:_run_command_with_script_pty`）：
   - `log_path` 文件包含 pty 全部字符，包含 kernel console 输出
   - **问题**：崩溃时 `finally: log_path.unlink(missing_ok=True)` 删除了该文件！
   - **最小修复**：崩溃时不删除 log_path，或先 copy 到 result dir

2. **BPFREJIT_VM_CONSOLE_LOG 方案（已实现但已 revert）**：
   - commit `bcddadf5`：添加了此 env var 保存 console 输出
   - commit `e46b0410`：revert 掉了
   - **重新启用此 env var 即可**，代价最小

---

## 5. 修复方案推荐

**约束**：禁止 mutex/序列化/chunk/filter/改 kernel

### 推荐方案 A：降低日志级别（低风险，减少 /tmp 压力）

`daemon/src/commands.rs` 中 `rejit_program()` 使用 `log_level=2`（full verifier log）。

改为 `log_level=0`（仅统计）可将每次 REJIT 从"分配 16MB buf + verifier 逐指令记录"降低到"不分配 buf"。减少 kernel 侧 verifier 路径的 `verbose_linfo()` 写入量，间接减少并发冲突窗口长度。

**注意**：这不修复竞态本身，只是减小触发概率。

### 推荐方案 B：kernel 侧修复 bpf_prog_rejit() 并发路径（根治，但用户禁止改 kernel）

`syscall.c:bpf_prog_rejit()` 需要在 `bpf_check()` 调用前加一个 per-verifier-state 锁，或恢复 `bpf_verifier_lock` 对 root 路径的覆盖。

**用户禁止改 kernel**，此方案仅作记录。

### 推荐方案 C：daemon 侧 per-app 串行化（变相 mutex，用户禁止）

用户明确禁止。跳过。

### 推荐方案 D：捕获 kernel panic backtrace，精确定位竞态位置（诊断优先）

**最务实的下一步**：不改任何逻辑，只修复 console 日志捕获：

1. 恢复 `BPFREJIT_VM_CONSOLE_LOG` env var（commit `bcddadf5` 逻辑）
2. 或修复 `_run_command_with_script_pty` 的 `log_path` 在崩溃时不删除

获得 panic backtrace 后，可精确确认是候选 1（verifier 内部共享状态）还是候选 2（kallsyms 并发），再针对性向上游报告或修复。

### 推荐方案 E：减少 rayon 工作线程数（非 mutex，但改变并发度）

`daemon/src/commands.rs:default_worker_count()` 对 `cpus > 4` 返回 `min(cpus, 16)`。

将上限从 16 改为更小值（如 4）可降低并发度。**但用户禁止 chunk/serialize**，此方案存疑，暂不推荐。

### 总结推荐优先级

| 优先级 | 方案 | 改动量 | 是否根治 |
|--------|------|--------|---------|
| 1 | 恢复 console log 捕获（方案 D） | ~5行 | 否（诊断） |
| 2 | 降低 log_level=0（方案 A） | ~1行 | 否（缓解） |
| 3 | kernel 侧修复（方案 B） | ~10行 kernel | 是（禁止） |

**最终建议**：先恢复 console log 捕获，重跑 `make vm-corpus SAMPLES=1` 获取 panic backtrace，再根据具体 BUG 决定是否申请解禁 kernel 修改。

---

## 附录：关键代码坐标速查

| 文件 | 行号 | 内容 |
|------|------|------|
| `vendor/linux-framework/kernel/bpf/verifier.c` | 376 | `DEFINE_MUTEX(bpf_verifier_lock)` |
| `vendor/linux-framework/kernel/bpf/verifier.c` | 26372 | `if (!is_priv) mutex_lock(...)` ← root 绕过 |
| `vendor/linux-framework/kernel/bpf/syscall.c` | 3634 | `mutex_lock(&prog->aux->rejit_mutex)` |
| `vendor/linux-framework/kernel/bpf/syscall.c` | 3822 | `bpf_prog_rejit_swap()` |
| `daemon/src/commands.rs` | 34 | `REJIT_LOG_BUF_SIZE = 16MB` |
| `daemon/src/commands.rs` | 405-415 | `default_worker_count()` |
| `daemon/src/commands.rs` | 666-707 | `par_iter().map(apply_one)` |
| `bpfopt/crates/kernel-sys/src/lib.rs` | 43 | `MAX_REJIT_LOG_BUF_SIZE = 256MB` |
| `runner/targets/x86-kvm.env` | — | `TARGET_KVM_BENCH_CPUS_SPEC=16` |
| `runner/libs/vm.py` | 95 | `--overlay-rwdir /tmp` |
| `runner/libs/vm.py` | 168-170 | `log_path.unlink()` ← panic 时删除日志 |
