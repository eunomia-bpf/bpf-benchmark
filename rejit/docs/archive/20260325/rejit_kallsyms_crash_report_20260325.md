# REJIT 并行 kallsyms 双重删除 Kernel Panic 报告

**日期**: 2026-03-25
**严重性**: CRITICAL — kernel panic，阻塞全量 VM 验证
**触发路径**: `bpf_prog_rejit` → `bpf_prog_kallsyms_del_all` → `bpf_ksym_del` → GPF on LIST_POISON

---

## 1. 摘要

在 daemon serve 模式下并行 REJIT 30+ 个 BPF 程序时，kernel 在 `bpf_ksym_del` 中触发 general protection fault（访问 `0xdead000000000122` = `LIST_POISON2`），导致 kernel panic。根因是 REJIT swap 路径中 kallsyms 链表节点被重复删除。

---

## 2. 复现步骤

### 环境

- Host: Intel Core Ultra 9 285K, Ubuntu, kernel 6.15.11
- VM: QEMU/KVM + virtme-ng 1.40
- Guest kernel: 7.0-rc2+rejit-v2 分支（`vendor/linux-framework`）
- kinsn modules: bpf_barrier, bpf_endian, bpf_extract, bpf_rotate, bpf_select

### 复现命令（Makefile 方式）

```bash
source /home/yunwei37/workspace/.venv/bin/activate
make vm-static-test TARGET=x86
```

### 复现命令（手动方式，可看 panic 输出）

```bash
source /home/yunwei37/workspace/.venv/bin/activate
vng -v -r vendor/linux-framework/arch/x86/boot/bzImage \
    --cpus 4 --memory 8G \
    --rwdir /home/yunwei37/workspace/bpf-benchmark \
    --rwdir /home/yunwei37/workspace/bpf-benchmark/docs/tmp \
    -- ". /home/yunwei37/workspace/.venv/bin/activate; \
        export TMPDIR=/home/yunwei37/workspace/bpf-benchmark/docs/tmp/vm-tmp; \
        mkdir -p \$TMPDIR; \
        bash module/load_all.sh 2>/dev/null || true; \
        python3 daemon/tests/static_verify.py \
            --daemon-binary daemon/target/release/bpfrejit-daemon \
            --output \$TMPDIR/sv_all.json 2>&1; echo RC=\$?"
```

### 触发条件

| objects 数量 | parallel_jobs | 结果 |
|:---:|:---:|:---:|
| 5 | 3 | ✅ 通过 |
| 20 | 3 | ✅ 通过 |
| 30 | 3 | ✅ 通过 |
| 40 | 3 | ❌ kernel panic |
| 62 | 8 | ❌ kernel panic |
| 191 (全量) | 6-8 | ❌ kernel panic（每次必现） |

关键变量是**同时被 REJIT 的程序数量**。daemon serve 接收 batch runner 的 optimize 请求后串行处理，但多个 batch worker 同时加载 .bpf.o 并请求 optimize，导致多个 `BPF_PROG_REJIT` syscall 并发执行。

---

## 3. 完整 Panic 信息

```
[    7.286487] Oops: general protection fault, probably for non-canonical address 0xdead000000000122: 0000 [#1] SMP NOPTI
[    7.287086] CPU: 2 UID: 0 PID: 222 Comm: bpfrejit-daemon Tainted: G           OE       7.0.0-rc2+ #90 PREEMPT(full)
[    7.287717] Tainted: [O]=OOT_MODULE, [E]=UNSIGNED_MODULE
[    7.288119] Hardware name: QEMU Ubuntu 24.04 PC v2 (i440FX + PIIX, arch_caps fix, 1996)
[    7.288734] RIP: 0010:bpf_ksym_del+0x72/0xa0
[    7.289015] Code: 83 34 06 02 01 48 c7 c6 d0 9b 80 aa 48 8d bb 38 02 00 00 e8 b0 73 fe 00
               48 8b 83 18 02 00 00 48 8b 93 10 02 00 00 48 89 42 08
               <48> 89 10 48 b8 22 01 00 00 00 00 ad de 48 89 83 18 02 00 00 48 c7
[    7.289817] RSP: 0018:ffffcf9ac02efbe0 EFLAGS: 00010246
[    7.290038] RAX: dead000000000122 RBX: ffff8a8441b23158 RCX: 0000000000000000
[    7.290334] RDX: ffff8a8446cd3368 RSI: 0000000000000000 RDI: 0000000000000000
[    7.292490] Call Trace:
[    7.292594]  <TASK>
[    7.292685]  bpf_prog_kallsyms_del_all+0x46/0x80
[    7.292884]  __bpf_prog_put_noref+0x14/0x120
[    7.293068]  bpf_prog_rejit+0xce7/0xdb0
[    7.293555]  __sys_bpf+0x58f/0x2660
[    7.294293]  do_syscall_64+0xcf/0x1570
[    7.294624]  entry_SYSCALL_64_after_hwframe+0x76/0x7e
[    7.297614] Modules linked in: bpf_select(OE) bpf_rotate(OE) bpf_extract(OE) bpf_endian(OE) bpf_barrier(OE)
               overlay(E) 9pnet_virtio(E) virtiofs(E) 9p(E) 9pnet(E) netfs(E)
[    7.298453] RIP: 0010:bpf_ksym_del+0x72/0xa0
[    7.302072] Kernel panic - not syncing: Fatal exception in interrupt
```

---

## 4. 分析

### 4.1 直接原因

`RAX = 0xdead000000000122` 是 `LIST_POISON2`，表示链表节点已被 `list_del_rcu` 删除过。`bpf_ksym_del` 尝试对该节点再次执行 `list_del_rcu`，触发 GPF。

### 4.2 Call Path

```
userspace: daemon → BPF_PROG_REJIT syscall
kernel:
  bpf_prog_rejit()
    → 创建 tmp_prog，复制 orig bytecode
    → bpf_check(tmp_prog)    // verify，过程中 tmp_prog 被注册到 kallsyms
    → bpf_int_jit_compile(tmp_prog)
    → swap: 把 tmp_prog 的 JIT image 移交给 real_prog
    → cleanup: bpf_prog_put(tmp_prog)
      → __bpf_prog_put_noref(tmp_prog)
        → bpf_prog_kallsyms_del_all(tmp_prog)   // 尝试从 kallsyms 删除 tmp 的 ksym
          → bpf_ksym_del()                       // ← GPF: 节点已是 LIST_POISON
```

### 4.3 竞争场景推测

```
Thread A (REJIT prog X):              Thread B (REJIT prog Y):
  bpf_check(tmp_A)                      bpf_check(tmp_B)
  // tmp_A 注册到全局 kallsyms            // tmp_B 注册到全局 kallsyms
  swap(real_X, tmp_A)                    swap(real_Y, tmp_B)
  // swap 中 del_all(real_X 旧 ksyms)
  bpf_prog_put(tmp_A)
    bpf_prog_kallsyms_del_all(tmp_A)
      bpf_ksym_del(tmp_A.ksym)          // 可能已被 swap 路径删除
                                         // → LIST_POISON → GPF
```

两种可能的竞争窗口：
1. **swap 路径和 cleanup 路径重复删除**：swap 先调了 `bpf_prog_kallsyms_del_all` 把旧 ksyms 删掉，然后 cleanup 对 tmp_prog 再删一次
2. **两个 REJIT 的 tmp prog 在 kallsyms 全局链表上互相干扰**：虽然有 per-prog `rejit_mutex`，但 kallsyms 全局数据结构只靠 `bpf_lock` 保护，REJIT 路径可能在持有/释放锁的间隙出现竞争

### 4.4 关键观察

- **单个 REJIT 从不触发**：所有 unit test（包括 #348 的 rapid kallsyms 20/20）都通过
- **少量并行不触发**：30 objects 在 parallel_jobs=3 时稳定通过
- **大量并行必触发**：40+ objects 或 parallel_jobs=6+ 几乎 100% 复现
- crash 发生在 daemon 进程（PID 222, comm: bpfrejit-daemon），不是 batch runner

---

## 5. 历史

- **#346**（2026-03-22）：修复 "kallsyms latch_tree 双重注册" bug（kernel `21c1b1f89`）
- **#348**（2026-03-22）：回归测试 5 项全 PASS，包括 "rapid kallsyms 20/20" 和 "并发 REJIT 40/40"
- 但 #348 的并发测试是对**同一个程序**做 40 次 REJIT（per-prog mutex 串行化了），不是对 **40 个不同程序** 同时 REJIT
- 当前场景是 daemon serve 对不同 prog_fd 并行发 REJIT syscall，触发了新的竞争窗口

---

## 6. 修复方向

| 方向 | 说明 | 复杂度 |
|------|------|:---:|
| **A. 修复 REJIT 中 tmp_prog 的 kallsyms 生命周期** | swap 后 tmp_prog 的 ksyms 已移交给 real_prog，cleanup 不应再删。检查 `bpf_prog_rejit` 的 swap 路径是否正确清除了 tmp_prog 的 ksym 注册状态 | 中 |
| **B. 防御性检查** | `bpf_ksym_del` 中加 `list_empty` / `LIST_POISON` 检查，跳过已删除节点 | 低 |
| **C. 全局 kallsyms 锁保护** | REJIT 整个 swap+cleanup 路径持有全局锁 | 高 |

建议：先用 B 做防御性修复验证 crash 消失，再用 A 做根本修复确保 ksym 状态一致。

---

## 7. 影响

- **`make vm-static-test`**：30+ objects 时 crash，全量 191 objects 无法跑
- **`make vm-corpus`**：daemon serve 并行 REJIT 同样触发
- **`make vm-e2e`**：Tracee/Tetragon 加载大量 BPF 程序后 REJIT 可能触发
- **单独 REJIT 和小规模测试不受影响**：unit test、vm-selftest、vm-micro-smoke 全部正常

---

## 8. 修复

### 8.1 根因确认

分析报告：`docs/tmp/20260325/rejit_kallsyms_crash_analysis_20260325.md`

根因不是并发竞争，是 `bpf_prog_rejit_swap()` 的逻辑 bug：
1. Line 3426 `bpf_prog_kallsyms_del_all(prog)` 删除旧 subprogs 的 ksym → `lnode` 变成 `LIST_POISON`
2. Line 3429 `swap(prog->aux->func, tmp->aux->func)` 把这些 poisoned 的旧 subprogs 转移到 tmp
3. Line 3890 `__bpf_prog_put_noref(tmp, ...)` 对 tmp 再次调 `bpf_prog_kallsyms_del_all` → GPF

### 8.2 修复

在 `post_swap_sync` 中、`__bpf_prog_put_noref(tmp)` 之前，对 tmp 的旧 subprogs 的 `ksym.lnode`（和 `ksym_prefix.lnode`）做 `INIT_LIST_HEAD_RCU()` 重置。这样后续 `bpf_ksym_del` 中的 `list_empty()` 检查会返回 true 并跳过。

改动：`vendor/linux-framework/kernel/bpf/syscall.c`，+10 行。

### 8.3 验证

**复现测试**：`tests/unittest/rejit_regression.c` Test 6 `parallel_subprog_rejit`
- 加载 8 个含 subprog（bpf2bpf call）的 XDP 程序
- 每个程序并行 REJIT 20 次（共 160 次）
- 修复前：kernel panic on `bpf_ksym_del` (LIST_POISON2)
- 修复后：**6/6 PASS，160/160 REJITs 成功**

**全量验证**：`make vm-static-test TARGET=x86`
- 修复前：30+ objects 时 kernel panic，无法完成
- 修复后：**191 objects, 616 programs, 217 applied, 576 verifier accepted, 0 crash**
