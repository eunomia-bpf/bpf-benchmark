# REJIT Mutex Consolidation Review

**日期**: 2026-05-04  
**Kernel HEAD**: `adabaf342` (vendor/linux-framework)  
**任务**: 只读分析，不改代码

---

## 1. 4 把锁各自精确覆盖范围

### 1.1 `text_mutex` (upstream)

**定义**: `arch/x86/net/bpf_jit_comp.c` — 全局 mutex（x86 arch-level）  
**覆盖**: `__bpf_arch_text_poke()` 函数内部，保护对 JIT 文本段的读-compare-write (cmpxchg)。  

```c
// bpf_jit_comp.c:651-661
ret = -EBUSY;
mutex_lock(&text_mutex);
if (memcmp(ip, old_insn, X86_PATCH_SIZE))  // <- 如果此处 memcmp 失败 -> -EBUSY
    goto out;
...
smp_text_poke_single(ip, new_insn, X86_PATCH_SIZE, NULL);
mutex_unlock(&text_mutex);
```

**关键点**: `-EBUSY` 的 memcmp 失败发生在 `mutex_lock` 之后 —— 即 `text_mutex` 已持有，但 ip 处字节不等于 caller 传入的 `old_insn`。这意味着 `text_mutex` 本身不能阻止外部 TOCTOU：`old_insn` 是 caller 在 `mutex_lock` 之前构造的。  
**commit**: upstream，非 fork 新增

---

### 1.2 `prog->aux->rejit_mutex` (fork 新增)

**定义**: `include/linux/bpf.h:1728` — per-prog mutex  
```c
struct mutex rejit_mutex; /* serializes BPF_PROG_REJIT on this prog */
struct list_head trampoline_users; /* trampolines using this prog, protected by rejit_mutex */
```

**覆盖**:
- `bpf_prog_rejit()` 全程（`syscall.c:3638` lock → `3936/3969` unlock）
- `bpf_prog_get_info_by_fd()` 读取 prog 元数据时（`syscall.c:5878`），防止与 in-place swap 并发读到半更新状态

**精确范围**（单 prog 视角）:
```
mutex_lock(rejit_mutex)          // 3638
  [fd_array copy, alloc tmp]     // 3641-3669
  bpf_check(tmp)                 // 3763   <- verify（在全局 mutex 之外）
  mutex_lock(global_rejit_swap_mutex)  // 3775
    bpf_prog_select_runtime(tmp) // 3778   <- JIT
    bpf_prog_rejit_update_poke_tab()
    bpf_prog_rejit_untrack_tmp_pokes()
    poke_target_phase(delete)
    bpf_prog_rejit_swap()        // in-place swap bpf_func
    poke_target_phase(insert)
  mutex_unlock(global_rejit_swap_mutex)  // 3842
  trampoline_refresh / struct_ops_refresh / xdp_refresh
  synchronize_rcu_expedited()
  kallsyms_add
mutex_unlock(rejit_mutex)        // 3936
```

**作用**: 防止同一 prog 并发两次 REJIT。  
**commit**: 初始 REJIT POC，非特定 commit

---

### 1.3 `global_rejit_swap_mutex` (fork 新增)

**定义**: `syscall.c:67` — 全局 static mutex  
```c
static DEFINE_MUTEX(global_rejit_swap_mutex);
```

**覆盖** (commit `adabaf342`，扩展自 `67504c548`):
```
// 3775-3842（正常路径）
mutex_lock(&global_rejit_swap_mutex)
  bpf_prog_select_runtime(tmp)       // JIT（含 bpf_tail_call_direct_fixup）
  bpf_prog_rejit_update_poke_tab()   // 把 tmp 的 poke_tab 地址写入 prog 的 poke_tab
  bpf_prog_rejit_untrack_tmp_pokes()
  bpf_prog_rejit_poke_target_phase(delete)  // PROG_ARRAY poke 删除阶段
  bpf_prog_rejit_swap()             // in-place swap bpf_func
  bpf_prog_rejit_poke_target_phase(insert)  // PROG_ARRAY poke 插入阶段
mutex_unlock(&global_rejit_swap_mutex)

// rollback 路径 (3544-3579) 也持全局锁
```

**commit `67504c548`** 原始覆盖：仅 swap+poke 阶段（verify 和 JIT 在外）  
**commit `adabaf342`** 扩展：将 JIT 纳入覆盖，原因是 `bpf_tail_call_direct_fixup` 在 JIT 时捕获 callee->bpf_func 地址写入新 image，若此后另一 prog 的 REJIT swap 改变了 callee 的 bpf_func，cached JUMP 就会过期

**作用**: 跨 prog REJIT 的 JIT→swap→poke 序列化。verify 仍可并行。

---

### 1.4 `array->aux->poke_mutex` (upstream)

**定义**: `include/linux/bpf.h:1873` — per-prog_array map mutex  
```c
struct bpf_array_aux {
    ...
    struct mutex poke_mutex;
};
```

**覆盖**:
- `prog_array_map_poke_run()` — 调用链入口处有 `WARN_ON_ONCE(!mutex_is_locked(&aux->poke_mutex))`
- `bpf_fd_array_map_update_elem()` (map_update_elem syscall): 持 poke_mutex 调 map_poke_run
- `__fd_array_map_delete_elem()`: 同上
- `prog_array_map_poke_track/untrack()`: 管理 poke_progs 链表
- fork 的 `bpf_prog_rejit_update_poke_tab()` (3271-3288): 每个 poke entry 更新时各自持对应 array 的 poke_mutex
- fork 的 `bpf_prog_rejit_poke_target_phase()` (3366-3375): 在 map 上调 poke_run 前持此 mutex

**作用**: upstream 保证 poke_run 与 map 的 update/delete 不并发；fork 复用此 mutex 保护 poke_tab in-place 修改。

---

## 2. Q1: 两把 fork mutex 能否合并成一把？

### 分析

`rejit_mutex`（per-prog）与 `global_rejit_swap_mutex`（全局）的分层设计来自 `67504c548` commit 的明确决策：

> "Verifier and JIT work remain outside the global mutex and still run in parallel under each program's rejit_mutex."

两把锁的语义不同：
- `rejit_mutex`：per-prog 序列化（防止同一 prog 两个 REJIT 并发）
- `global_rejit_swap_mutex`：跨 prog 序列化 JIT→swap→poke 序列（防止两个不同 prog 的 JIT 互相看到对方的旧 bpf_func）

**能否合并？**

理论上可以合并成一把全局 mutex 包覆 verify + JIT + swap + poke。代价分析：

**当前（分层）**: verify 并行，JIT+swap+poke 串行  
**合并后（全局）**: verify + JIT + swap + poke 全部串行

**实测数据**（来自 `corpus/results/x86_kvm_corpus_20260503_212536_397107/details/daemon.stderr.log`，453 次 REJIT_EXIT 样本）:

| 统计量 | elapsed_us |
|--------|-----------|
| 最小值 | 3,606 |
| 中位数 | 7,894 |
| 平均值 | 17,437 |
| p95 | 73,350 |
| 最大值 | 967,228 |

**tetragon 287 progs × 11 passes 场景估算**:
- 当前（verify 并行，JIT 串行）：16 worker，287 × 11 = 3157 次 REJIT，平均 17ms/次，JIT 约占整体时间的 ~1/3，理论并行效率：verify 阶段 16× parallel
- 合并后全部串行：287 × 11 × 17ms ≈ **883 秒**（~15 分钟），而当前 218s 已经是瓶颈
- 实测最大 REJIT 时间 967ms（1 次），对于这种量级的串行化，总时间会显著拉长

**结论**: 合并两把锁技术上可行，但对于 tetragon 287×11 场景，全局串行化会让 benchmark 时间从几分钟拉长到 15 分钟级别，不实际。但更关键的问题是：合并后**仍然无法修复当前 panic**（见 Q2）。

---

## 3. Q2: 单一全局 REJIT mutex 是否能修当前 panic？

### Panic 的准确类型

**证据**（`parallel-rejit-decision-summary-20260503.md` + 实际 kernel panic 调用栈）:

```
kernel BUG at arch/x86/net/bpf_jit_comp.c:4135
RIP: bpf_arch_poke_desc_update+0xd8
RAX = 0xfffffff0  (-EBUSY)
Call Trace:
  prog_array_map_poke_run
  bpf_prog_rejit_poke_target_phase
  bpf_prog_rejit
```

**BUG_ON 发生在** `bpf_arch_poke_desc_update` 第 4135 行：
```c
ret = __bpf_arch_text_poke(poke->tailcall_target, t, BPF_MOD_JUMP, old_addr, new_addr);
BUG_ON(ret < 0);  // <- 4135: ret = -EBUSY
```

**-EBUSY 来源**: `__bpf_arch_text_poke` 里：
```c
ret = -EBUSY;
mutex_lock(&text_mutex);
if (memcmp(ip, old_insn, X86_PATCH_SIZE))  // ip 处字节不等于 old_insn -> return -EBUSY
    goto out;
```

**`old_insn` 的来源**: 由 `bpf_arch_poke_desc_update` 计算：
```c
old_addr = old ? (u8 *)old->bpf_func + poke->adj_off : NULL;
// old_insn = emit_jump(old_addr, ip) ← 用 old_addr 算 5-byte jmp 指令
```

这里 `old_addr` 来自 caller prog 的 `poke->adj_off` + **callee 的 bpf_func（cached at JIT time）**。

### Race 的根本原因

这是 **Race 2（TOCTOU：caller REJIT 让 ip 处的字节漂移）**，不是 Race 1（非 REJIT map_update_elem 路径）。

时序：

```
Thread A: REJIT prog_X (callee)
  JIT: captures callee_Y->bpf_func (addr_Y_old) into tmp_X.poke_tab[i]
  ...
Thread B: REJIT prog_Y (callee_Y, concurrent)
  swap: prog_Y.bpf_func = addr_Y_new (via bpf_prog_rejit_swap)
  → addr_Y_old JIT image memory enters RCU deferred free
  poke_target_phase(insert): pokes all callers → ip 处字节已更新为 jmp addr_Y_new
  ...
Thread A continues:
  update_poke_tab: 把 tmp_X.tailcall_target（指向 callee_Y new image）写入 prog_X.poke_tab
  poke_target_phase(delete on prog_X):
    → 调 poke_run for every PROG_ARRAY with prog_X
    → bpf_arch_poke_desc_update(old=prog_X@old, new=NULL)
    → old_addr = prog_X.poke_tab[j].tailcall_target (now = callee_Y new addr, post update_poke_tab!)
    → but ip at prog_X.poke_tab[j].tailcall_target 字节实际是 jmp callee_Y_old (修改前)
    → memcmp 失败 → -EBUSY → BUG_ON
```

（实际时序可以有多种变体，但根本原因都是：fork 在 in-place mutate `prog->bpf_func` 时破坏了 upstream 的"bpf_func 发布后不可变"不变量。）

### 单一全局 REJIT mutex 的效果

**能防住**: 两个 REJIT 完全串行，不会有跨 prog 的 JIT cache 失效。  
**防不住**:
- `prog_array_map_update_elem` 路径（非 REJIT）也会触发 `poke_run` → `bpf_arch_poke_desc_update`，且不持任何 REJIT mutex
- 当 REJIT 的 swap+poke 序列与用户态 `map_update_elem` 并发时，仍可能 race

**理论上全局 REJIT mutex 能消除 REJIT-vs-REJIT race**（上面的 Thread A vs Thread B 场景）。当前 panic 的触发点是两个并发 REJIT，因此全局 mutex 在实践中会让 panic 消失（退化为纯串行）。

**但这不代表系统正确**：`map_update_elem` 并发路径的 race 仍然存在，只是在 benchmark 场景中不常被触发。

**要防住 `map_update_elem` 并发**，需要把 `poke_mutex`（per-prog_array）与 REJIT 的 poke 阶段的锁语义统一。目前 fork 的 `poke_target_phase` 已经持 `array->aux->poke_mutex`（见 `syscall.c:3366-3375`），与 upstream `map_update_elem` 路径相同的锁。但问题是：REJIT 更新的 `poke_tab[i].tailcall_target`（callee 地址）与 `map_update_elem` 更新的 `array->ptrs[key]`（callee prog 指针）是两套不同的状态，两者的同步依赖不匹配。

**结论**: 单一全局 REJIT mutex 可以消除当前 panic（因为 panic 的直接原因是 REJIT-vs-REJIT race），但不是架构正确性修复；`map_update_elem` 并发 race 仍然潜在存在。

---

## 4. Q3: 4 把锁是否本质重复？

### Upstream 视角（去掉 fork 2 把）

Upstream 在 prog_array poke 场景的并发保证：
- `poke_mutex`（per-map）序列化 `map_update_elem` 与 `poke_run`
- `text_mutex`（arch）序列化单次 text patch 的 compare-exchange
- `bpf_func` 是不可变的（published once via JIT，never mutated）：`tailcall_target` 指向的地址永远稳定

Upstream 没有"动态替换 prog 的 JIT image"的概念，所以完全不需要 fork 的 2 把锁。

### Fork 新增锁的必要性

**`rejit_mutex`**: 必要。同一 prog 的两次并发 REJIT 会导致 `bpf_prog_rejit_swap` 里的 ~50 个字段双重 swap，无法靠其他锁替代。这是 fundamentally 必需的 per-prog 序列化。

**`global_rejit_swap_mutex`**: 目前必要，但是 narrow workaround。它解决的问题（bpf_func 不稳定导致 cached poke 地址失效）是 fork 违反 upstream 不变量的直接后果。如果改用 X1 RCU 替换设计（每次 REJIT 生成新的不可变 prog 对象），这把锁完全可以删除。

### 两把是否本质重复？

**否**。两把锁覆盖不同颗粒度：
- `rejit_mutex`：同 prog 的 REJIT 互斥
- `global_rejit_swap_mutex`：不同 prog 的 JIT→swap→poke 互斥

去掉 `rejit_mutex` 而只留全局锁：verify 也会被序列化，性能大损。  
去掉 `global_rejit_swap_mutex` 而只留 per-prog 锁：跨 prog race 仍存在（即使有 per-prog 锁，两个不同 prog 仍可并行 JIT，导致 callee bpf_func cache 失效）。

**两把是 narrow workaround（`67504c548` commit 自己已经承认）**，但在 in-place mutation 架构下，它们填补了 upstream 不存在的 gap，目前不能简单合并或删除任何一把。

---

## 5. Q4: 真正架构正解（RCU-based 替换）

### RCU 设计大概什么样？

（以下基于 `docs/tmp/x1-rcu-rejit-patch-proposal-20260503.md` 的分析）

核心思路：**不 mutate 活跃 `struct bpf_prog` 的任何字段；每次 REJIT 生成新的不可变 prog 对象，通过 owner-level RCU/atomic 替换所有引用**。

关键设计点：
1. REJIT 生成 `new = bpf_prog_alloc(...)` 并完整 JIT，`new->bpf_func` 是新 image
2. 用 `idr_replace(&prog_idr, new, old_id)` 保持 prog_id ABI
3. PROG_ARRAY slot: `xchg(array->ptrs + key, new)` + `map_poke_run(old, new)` — upstream 的单次 poke，old 和 new 的 bpf_func 都不变
4. FD/pin 语义需要 `struct bpf_prog_handle` 稳定句柄层（否则已有 FD 仍指旧 prog）
5. 所有其他 owner（cgroup、perf_event、trampoline、XDP driver 等）需要各自的 replacement callback

### 消除哪些锁？

- `global_rejit_swap_mutex`：**完全删除**（不需要序列化 JIT→swap，因为没有 in-place swap）
- `rejit_mutex` 仍需保留（防止同一逻辑 prog 的两次并发 REJIT，保证 ID/FD 一致性）
- `bpf_prog_get_info_by_fd()` 的 `rejit_mutex` 锁：**可删**（prog 对象不可变，无需快照保护）

poke 路径还需要 `poke_mutex` 吗？需要，因为 `map_update_elem` 路径本身也要持 `poke_mutex`，RCU 只是让 bpf_func 稳定，不消除 map 并发更新。

### 改动规模估算

基于 `x1-rcu-rejit-patch-proposal-20260503.md`（§6）：

| 指标 | 估算 |
|------|------|
| 删除行数 | ~560 LOC（in-place swap/rollback/poke 机制） |
| 新增行数 | ~1720 LOC（RCU 替换机制 + per-owner callbacks） |
| 净增 | ~+1160 LOC |
| 涉及文件 | 18 个核心 kernel 文件，若 XDP driver 逐一处理则 35+ 个文件 |
| 工作量 | 25-35 person-days（full coverage）|
| 含 selftests | ~300 LOC |

---

## 6. 推荐方案对比

### 方案 A：合 2 把 fork mutex 成 1 把全局锁

**做法**: 删除 `rejit_mutex`，用 `global_rejit_swap_mutex` 包覆从 fd_array copy 到 kallsyms_add 的全部 REJIT 路径。

| 项目 | 结论 |
|------|------|
| 改动规模 | ~10-20 行 kernel |
| 修复当前 panic | 是（REJIT-vs-REJIT race 消失） |
| 修复 map_update_elem race | 否 |
| verify+JIT 并行 | **否**（全部串行化） |
| tetragon 287×11 场景 | 283progs × 11 × 平均 17ms ≈ **14 分钟**（不可接受） |
| 上游 acceptability | 极低 |
| 推荐 | **不推荐** |

---

### 方案 B：维持现状（4 把锁，narrow workaround）

**做法**: 什么都不改，接受现有 panic（已知触发场景：otelcol + calico 并发大 prog REJIT，tetragon 287 progs）。

| 项目 | 结论 |
|------|------|
| 改动规模 | 0 |
| 修复当前 panic | **否**（已知 100% 复现：`make vm-corpus SAMPLES=1`） |
| 修复 map_update_elem race | 否 |
| verify+JIT 并行 | 是（verify 并行，JIT 串行） |
| 上游 acceptability | 极低（BUG_ON 仍存在） |
| 推荐 | **不推荐**（benchmark 无法正常完成） |

---

### 方案 B'：窄化 mutex（daemon 侧检测 tail-call progs 并序列化）

**做法**: 不改 kernel，在 daemon Python/Rust 侧检测 prog 是否参与 PROG_ARRAY 关系（通过 `prog_info.used_maps` 判断），对这类 prog 的 REJIT 串行化，其他 prog 仍并行。

| 项目 | 结论 |
|------|------|
| 改动规模 | ~10-15 行 daemon Rust |
| 修复当前 panic | **是**（tail-call progs 串行后 race 窗口消失） |
| 修复 map_update_elem race | 否（但该 race 在 benchmark 场景极低概率触发） |
| verify+JIT 并行 | 是（非 tail-call progs 全并行） |
| tetragon 287 progs | tail-call progs 串行，但数量有限（otel 13 progs 串行）|
| 上游 acceptability | n/a（daemon-side workaround） |
| 推荐 | **短期推荐**（paper deadline 前可用） |

**限制**: 本方案仅作 fork userspace 的诊断修复，需在 paper 中明确写"Limitation"。`parallel-rejit-decision-summary-20260503.md` 已有详细论述。

---

### 方案 C：X1 RCU 重构（等并实施）

**做法**: 实现完整 RCU-based prog replacement。

| 项目 | 结论 |
|------|------|
| 改动规模 | +1160 LOC net，18-35 kernel 文件，25-35 person-days |
| 修复当前 panic | **是**（消除 in-place mutation 根本原因） |
| 修复 map_update_elem race | **是**（upstream poke 语义被正确使用） |
| 删除 global_rejit_swap_mutex | **是** |
| verify+JIT 并行 | 是 |
| 上游 acceptability | 中等（需配合 FD/pin handle 设计） |
| 推荐 | **长期推荐，不在本 paper 周期内** |

---

## 7. 综合推荐

**短期（paper benchmark 可用）**: 方案 B'（daemon 侧 narrow mutex for tail-call progs）  
**长期（upstream RFC）**: 方案 C（X1 RCU 替换）

**不推荐**:
- 方案 A（合并 2 把锁）：verify 全串行会让 tetragon 287-prog benchmark 从可完成变为不可接受（估算 14 分钟串行）
- 方案 B（维持现状）：benchmark `make vm-corpus` 100% 复现 panic，无法出数据

---

## 附录：关键代码坐标

| 锁 | 定义位置 | 加锁位置（主要） | commit |
|----|---------|----------------|--------|
| `text_mutex` | `arch/x86/net/bpf_jit_comp.c:652` | `__bpf_arch_text_poke` 内部 | upstream |
| `rejit_mutex` | `include/linux/bpf.h:1728` | `syscall.c:3638, 3936, 3969, 5878` | 初始 POC |
| `global_rejit_swap_mutex` | `syscall.c:67` | `syscall.c:3544, 3775, 3842, 3966` | `67504c548`（swap/poke），`adabaf342`（扩展至 JIT） |
| `array->aux->poke_mutex` | `include/linux/bpf.h:1873` | `arraymap.c:919, 942, 1058, 1090`；`syscall.c:3271, 3366` | upstream（部分）+ fork 复用 |

| 相关文档 | 路径 |
|----------|------|
| X1 RCU 完整分析 | `docs/tmp/x1-rcu-rejit-patch-proposal-20260503.md` |
| 并发 panic 根因分析 | `docs/tmp/parallel-rejit-decision-summary-20260503.md` |
| 详细 rootcause | `docs/tmp/parallel-rejit-rootcause-analysis-20260503.md` |
