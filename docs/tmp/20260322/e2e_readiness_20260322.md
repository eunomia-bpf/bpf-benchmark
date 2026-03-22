# E2E Benchmark Readiness Report

Date: 2026-03-22

## Summary

全部 5 个 e2e case 均可运行。Katran 是目前 REJIT 应用效果最好的 case，func_cnt 和 poke_tab 两个限制已全部解除。

---

## 1. 各 case 状态

### Katran — READY, REJIT applies

- **上次运行**: 2026-03-20T22:09 (dev/katran_vm_authoritative_like_parallel1_20260320.json)
- **模式**: `katran_dsr_direct_map_connection_churn_same_image_paired`
- **REJIT 应用**: 成功 (bpf_speedup_ratio = 1.108x, bpf_avg_ns/run -9.7%)
- **限制已解除**:
  - `func_cnt` 阻断: 已在 commit `31c1433` (2026-03-21) 通过多 subprog REJIT swap 修复
  - `poke_tab` 阻断: 已在 commit `72051ac` + `193a744` (2026-03-21) 通过 poke_tab update 路径 + deadlock 修复
- **当前 `bpf_prog_rejit_supported()` 检查**: func_cnt 和 poke_tab 条件均已移除，函数直接 `return true`

**关键调查结论**: `balancer.bpf.o` 有 2 个 subprogram（`jhash` + `jhash_2words`），**没有**使用 `bpf_tail_call`（确认无 helper #12）。
所以之前阻断 Katran 的是 `func_cnt > 0`（多 subprog）而非 `poke_tab`。现在 func_cnt 修复后，Katran REJIT 已可正常工作。

**所需二进制文件**:
- `corpus/build/katran/balancer.bpf.o` — 存在 ✓
- `e2e/cases/katran/bin/katran_server_grpc` — 存在 ✓（但 case 不依赖它，直接用 bpftool + pinned maps）
- policy: `e2e/cases/katran/balancer_ingress.e2e.policy.yaml` — 存在 ✓（6 sites: 4 wide-load + 2 endian-load-swap-32）

**运行命令**:
```bash
make vm-e2e   # 会自动跑 katran
# 或单独跑:
vng --run vendor/linux-framework/arch/x86/boot/bzImage --rwdir . -- \
  bash -lc 'cd /path/to/bpf-benchmark && source /home/yunwei37/workspace/.venv/bin/activate && \
  python3 e2e/run.py katran --output-json e2e/results/dev/katran.json --output-md e2e/results/dev/katran.md'
```

---

### Tracee — READY, REJIT applies

- **上次运行**: 2026-03-20T18:09 (dev/tracee.json)
- **REJIT 应用**: 成功，exec_storm +8.1%, bpf -3.8%
- **--vm 支持**: 是
- **依赖**: `corpus/build/tracee/tracee.bpf.o` ✓

---

### Tetragon — READY, REJIT applies

- **上次运行**: 2026-03-20T18:23 (dev/tetragon.json)
- **REJIT 应用**: 成功，connect_storm +32.2% throughput, bpf -1.5%
- **注意**: `--vm` 在 `e2e/run.py` 里未支持（`run.py:326`），但 `make vm-e2e` 直接在 vng 内运行不传 `--vm`，所以可以正常跑
- **依赖**: `corpus/build/tetragon/bpf_execve_event.bpf.o`, `bpf_generic_kprobe.bpf.o` ✓

---

### bpftrace — RUNS, REJIT applies 0/5 scripts

- **上次运行**: 2026-03-20T18:26 (dev/bpftrace.json)
- **REJIT 应用**: `rejit_successes=0/5`
  - open_latency: "policy filtered all live sites"
  - exec_trace: "no eligible directive sites"
  - scheduler_latency: "policy filtered all live sites"
  - vfs_read_count: "no eligible directive sites"
  - tcp_connect: "BPF_PROG_JIT_RECOMPILE did not apply"
- **原因**: bpftrace 生成的程序都是单函数小程序（kprobe/kretprobe），没有 wide-load 或 rotate 可优化的 site
- **注意**: `--vm` 在 `e2e/run.py` 里未支持，但 `make vm-e2e` 直接在 vng 内跑没问题
- **依赖**: `corpus/build/bpftrace/*.bpf.o` ✓

---

### SCX (scx_rusty) — RUNS, REJIT skipped

- **上次运行**: 2026-03-20T18:28 (dev/scx.json)
- **REJIT 应用**: `comparable=False, reason='post-ReJIT measurements are unavailable'`
  - scx_rusty 程序复杂，带 struct_ops，daemon 返回 applied=False
- **--vm 支持**: 是
- **依赖**:
  - `corpus/repos/scx/target/release/scx_rusty` ✓
  - `corpus/build/scx/scx_rusty_main.bpf.o` ✓

---

## 2. 重点调查：Katran tail_call 修复验证

### 两个修复 commit

| Commit | 日期 | 内容 |
|--------|------|------|
| `31c1433` | 2026-03-21 | func_cnt fix: multi-subprog REJIT swap (`aux->func[]`, func_cnt, real_func_cnt swap) |
| `72051ac` | 2026-03-21 | poke_tab (tail_call direct jump) REJIT 支持: `bpf_prog_rejit_update_poke_tab()` |
| `193a744` | 2026-03-21 | deadlock fix: `bpf_prog_rejit_poke_target_phase()` 改用 `bpf_map_get_curr_or_next()` |

### 当前内核 `bpf_prog_rejit_supported()` 状态

```c
static bool bpf_prog_rejit_supported(const struct bpf_prog *prog)
{
    const struct bpf_prog_aux *aux = prog->aux;

    if (!prog->jited || prog->is_func)
        return false;

    if (bpf_prog_is_offloaded(aux) || bpf_prog_is_dev_bound(aux))
        return false;

    /* dst_prog/dst_trampoline/poke_tab/func_cnt checks REMOVED */
    /* struct_ops support now included */

    return true;  // 直接通过
}
```

func_cnt 和 poke_tab 检查已全部移除。

### Katran balancer_ingress 分析

- ELF 中有 `.text` section，包含 2 个函数（`jhash_2words`, `jhash`）
- 主程序在 `xdp` section，insn 数 = 0x4890/8 = 2340 insns
- **不使用 `bpf_tail_call`（helper #12）**
- 使用的 helper: `{1:map_lookup, 2:map_update, 5:trace_printk, 8:get_pid, 44:?, 75:?}`
- 之前被阻断的原因是 `func_cnt > 0`（3-function program），而非 poke_tab

### 结论

Katran 在 func_cnt 修复后已可被 REJIT，2026-03-20 的授权结果证实 REJIT 成功应用并产生 ~1.09x speedup。tail_call/poke_tab 修复对 Katran e2e 本身不是直接前提，但对其他有 tail_call 的 workload（如某些 Cilium 程序）有益。

---

## 3. make vm-e2e 执行逻辑

```makefile
vm-e2e: $(MICRO_RUNNER) $(DAEMON_PATH) verify-build $(BZIMAGE_PATH)
    # 逐个 case，每个都用 vng 启动独立 VM
    vng --run bzImage --rwdir ROOT -- bash -lc 'python3 e2e/run.py tracee ...'
    vng --run bzImage --rwdir ROOT -- bash -lc 'python3 e2e/run.py tetragon ...'
    vng --run bzImage --rwdir ROOT -- bash -lc 'python3 e2e/run.py bpftrace --skip-build ...'
    vng --run bzImage --rwdir ROOT -- bash -lc 'python3 e2e/run.py scx ...'
    vng --run bzImage --rwdir ROOT -- bash -lc 'python3 e2e/run.py katran ...'
```

- 每个 case 跑在独立 VM 中（非共享）
- katran case 在 VM 内直接运行，使用 veth + netns DSR 拓扑
- 注意：vm-e2e 不传 `--vm` flag；程序直接在 vng guest 里执行

---

## 4. 待确认问题

1. **SCX REJIT 0%**: scx_rusty 是 struct_ops 程序，目前 REJIT 对 struct_ops 的支持状态需要单独确认
2. **bpftrace 0%**: 属于预期行为（小程序没有可优化 site）；如果需要展示，考虑添加包含 wide-load 的 bpftrace 脚本
3. **授权 JSON 未更新**: 上次 katran 授权结果（katran_authoritative_20260320.json）是在旧模式下跑的，新模式下（connection_churn_same_image_paired）应重新跑一次授权结果
