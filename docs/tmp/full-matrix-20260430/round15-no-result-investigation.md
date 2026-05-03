# Round 15 vm-corpus 无 result.md 调研报告

**结论先行**：round 15（`x86_kvm_corpus_20260502_171403_783423`）以及 May 1–2 的另外 4 个 `status=running` 失败 run，均因 **VM 超时（7200s） → SIGKILL 杀掉 vng 进程 → 整个 VM 及 VM 内 docker 容器被强制终止 → driver.py 收到 SIGKILL，Python 来不及执行任何 cleanup**，导致只有 `started_at` 时的初始写入（progress.json + metadata.json with `status="running"`），没有后续 finalize。

---

## Q1：result.md / per-app summary 何时写？

写入逻辑集中在 `corpus/driver.py` 的 `main()` 函数（lines 862–914）：

1. **启动时**（line 860）：`session.write(status="running", progress_payload=...)` → 写 `metadata.json`（status=running）+ `details/progress.json`（4 个字段）。
2. **run_suite() 正常返回后**（lines 868–891）：
   - 若 `payload_status == "ok"` → `session.write(status="completed", result_payload=payload, detail_texts={"result.md": ...})`
   - 若有错误但 `run_suite()` 正常返回 → `session.write(status="error", result_payload=payload, detail_texts={"result.md": ...})`
   - 两条路径都会写 `details/result.json` 和 `details/result.md`。
3. **run_suite() 抛异常时**（lines 903–913）：`except Exception` 块调用 `session.write(status="error", progress_payload=...)` **但没有 `result_payload=` 和 `detail_texts=`**，所以 result.json/result.md 不会写入。然后 `raise` 重新抛出。

`session.write()` 实现在 `runner/libs/run_artifacts.py`，是简单的同步文件写，写完立即 flush 到挂载的 virtiofs/9p 目录（bind-mount 进 docker 的 `corpus/results/`）。

**没有增量写**：每个 app 完成后不写，仅在最终 finalize 阶段一次性写全部结果。

---

## Q2：metadata.json status 停在 "running" 的原因

round 15 的 metadata.json 和 progress.json 均只有初始内容（仅 5 个字段），且文件的 mtime 为 `2026-05-02 12:15` PDT（即 17:14 UTC，刚启动时），**之后没有任何文件被写入或修改**（`find -newer metadata.json` 返回空）。

这说明 driver.py 进程在初始 `session.write(status="running")` 之后 **从未再写过任何文件**。Python 的 `except` / `finally` / 正常返回路径均未执行。唯一解释是进程被 **SIGKILL 强制终止**，没有机会执行任何 Python cleanup。

---

## Q3：vng VM 超时 kill 机制

路径：`make vm-corpus` → `run_target_suite._run_action()` → `kvm_executor.run_vm_suite()` → `vm.run_in_vm()` → `vm._run_command_with_script_pty()`:

```python
# runner/libs/vm.py, line 160-166
completed = subprocess.run(
    ["script", "-qfec", shlex.join(command), str(log_path)],
    cwd=ROOT_DIR,
    timeout=timeout,   # = 7200s (VM_CORPUS_TIMEOUT)
    check=False,
)
```

当 `timeout=7200` 秒到期，Python 的 `subprocess.run` 调用 `process.kill()` 对 `script` 进程发送 **SIGKILL**。`script` 包装的 `vng` 进程也随之被杀。vng 对应的 QEMU 虚拟机立刻断电，VM 内运行的 docker 容器（driver.py 进程）被强制终止，**Python 来不及运行任何 try/except/finally**。

代码中 **没有任何地方捕获 `subprocess.TimeoutExpired`**（`vm.py`、`kvm_executor.py`、`run_target_suite.py` 均不 catch），该异常一路向上传播，最终 `_run_action()` 以 `finally` cleanup 后抛出。`make` 收到非零退出码。

---

## Q4：是不是某类 error 阻止了 finalize？

**不是 Python 层面的 error 阻止了 finalize**，而是 VM 在 finalize 之前就被 SIGKILL 了。

证据：
- round 15 的 metadata.json 仍是 `status=running`（若 Python 的 `except` 块执行了，至少会写 `status=error`）。
- May 1–2 另 4 个 `status=running` 的失败 run（`204938`, `212856`, `023837`, `033522`）也是同样模式。
- 唯一完整 run（`215827`）花了约 1h30m 完成了 22 个 app（包括 tetragon 287 个程序），写出了完整 result.md。

**为什么 round 15 会超时？**

Round 15 使用 30 个 samples，且引入了 **per-pass ReJIT** 架构（commit `298211a0`，May 1 19:32 PDT，round 15 于 10:14 PDT 跑，对应 commit `4522507e`）：每个程序需要执行 12 次独立的 `BPF_PROG_REJIT` 系统调用。

- Tetragon：287 个程序 × 12 passes = **3444 次 REJIT 调用**
- Tracee：158 个程序 × 12 passes = **1896 次 REJIT 调用**

`BPF_PROG_REJIT` 是同步系统调用，CLAUDE.md 明确指出"没有 daemon-side timeout；verifier hang 会阻塞 daemon"。哪怕每次调用平均只需 2 秒，tetragon 一个 app 就需要 ~6900 秒 > 7200s 总超时。

另外，daemon socket 请求超时（`_DEFAULT_APPLY_TIMEOUT_SECONDS = 600s`）若触发，Python 这侧会抛 RuntimeError，被 `_run_suite_lifecycle_sessions()` 的 `try/except` 捕获，设 `fatal_error`，然后 `run_suite()` 正常返回（此时 result.md 是**应该能写的**）。但 VM 层面的超时（7200s）发生在 REJIT 过程中（kernel 未超时，600s socket timeout 还没到），直接杀掉了整个 VM。

---

## Bug 定位

### 主要 bug（根因）

**`runner/libs/vm.py:160-166`**：`subprocess.run(timeout=7200)` 超时直接 SIGKILL，无任何清理机会。

没有机制在 VM 超时前给 driver.py 发送 SIGTERM / graceful shutdown 信号。

### 次要 bug（叠加问题）

**`corpus/driver.py:903-913`**：`except Exception` 块调用 `session.write()` 时缺少 `result_payload=payload` 和 `detail_texts={"result.md": ...}`：

```python
except Exception as exc:
    session.write(
        status="error",
        progress_payload={...},
        error_message=str(exc),
        # ← 没有 result_payload, 没有 detail_texts
    )
    raise
```

若 `run_suite()` 中途抛异常（例如 daemon socket timeout），已完成的 per-app 结果（保存在 `results_by_name` 里）会被丢弃，result.md 不写。但这个路径在这次 round 15 没有触发（进程在此之前已被 SIGKILL）。

### 进一步叠加问题

`run_suite()` 内没有 `try/finally` 保证在异常时也能构建并返回 partial payload。若 `DaemonSession.start()` 或任何外层代码抛异常（不是 per-app 的 Exception），`run_suite()` 会直接上抛，`main()` 的 `except` 块捕获，但缺少 result_payload。

---

## 修复建议

### Fix 1（必须）：增量写 per-app 结果

在 `corpus/driver.py` 的 `run_suite()` 里，每个 app 完成后立刻将该 app 结果追加写入 `details/` 目录（例如 `details/app_{name}.json`）。这样即使 SIGKILL，已完成的 app 数据不丢失。

### Fix 2（必须）：VM timeout 改为先 SIGTERM 再 SIGKILL

在 `runner/libs/vm.py` 的 `_run_command_with_script_pty()` 中：捕获 `TimeoutExpired`，先对进程发 SIGTERM（给 60s 清理），再发 SIGKILL：

```python
except subprocess.TimeoutExpired:
    process.terminate()
    try:
        process.wait(timeout=60)
    except subprocess.TimeoutExpired:
        process.kill()
        process.wait()
    raise
```

在 driver.py 注册 SIGTERM handler，触发时执行 finalize 写入。

### Fix 3（应该）：try/finally 保证 finalize

在 `corpus/driver.py` 的 `main()` 中，用 `try/finally` 确保即使异常也写入已收集的 partial results：

```python
try:
    payload = run_suite(args, suite)
    # write ok/error result
finally:
    # if payload was partially collected, write partial result
```

### Fix 4（应该）：exception handler 里保存 partial results

`corpus/driver.py:903-913` 的 `except` 块应该尝试从 `run_suite()` 已构建的 partial state 里恢复并写 result.md（或传入 partial payload）。

---

## 200 字总结

Round 15 vm-corpus 跑了 ~2 小时后被 VM 超时（7200s）强制 SIGKILL，整个 vng 虚拟机瞬间断电，VM 内 docker 容器中的 driver.py 来不及执行任何 Python cleanup，导致 metadata.json 停留在 `status=running`、无 result.md。根因是 `vm.py` 用 `subprocess.run(timeout=7200)` 超时后直接 SIGKILL，没有先给 VM 发 SIGTERM 让 driver.py 有机会 flush。超时的直接原因是 per-pass ReJIT 架构使 tetragon（287 个程序）需要 3444 次 REJIT 调用，累计远超 7200s。同样模式在 May 1–2 的 4 个其他 run 中重现。次要 bug 是 driver.py `except` 块缺少 `result_payload=`，即便 Python 层面异常也不写 result.md。修复方向：增量写 per-app 结果（Fix 1），VM timeout 改 SIGTERM+60s grace（Fix 2），driver.py 注册 SIGTERM handler 触发 finalize（Fix 3）。
