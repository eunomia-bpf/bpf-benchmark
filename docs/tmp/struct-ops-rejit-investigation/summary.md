# struct_ops ReJIT Investigation

Date: 2026-04-25

## Verdict

当前代码树里，`BPF_PROG_REJIT` syscall 本身并没有显式拒绝 `BPF_PROG_TYPE_STRUCT_OPS`。`daemon/` 目录里的 ReJIT 路径也没有对 `struct_ops` 做特殊跳过。现在看到的 `"unsupported"` 结论，直接来源是 benchmark runtime 在进入 daemon apply 之前主动跳过了 scx 的 post-ReJIT 阶段。

结论归类：

- `a. 内核 rejit handler 明确拒绝 struct_ops`：**否**
- `b. 内核没拒绝但替换后有 race/crash 风险`：**当前树有专门的 struct_ops refresh/rollback 和 metadata-race 缓解；仓库里仍保留相关风险回归测试，但不是 handler 级别的显式拒绝**
- `c. daemon 侧跳过了`：**否，至少 `daemon/` 本身没有**
- `d. 其他原因`：**是。真正的 skip 来自 `runner` / `corpus` / `e2e` 的上层 runtime hook**

## 1. Kernel: `BPF_PROG_REJIT` 没有排除 `STRUCT_OPS`

`vendor/linux-framework/kernel/bpf/syscall.c:3167-3199`

- `bpf_prog_rejit_supported()` 只拒绝这些情况：
  - `!prog->jited || prog->is_func`
  - offloaded / dev-bound program
  - 已 attach 且 `dst_prog` 已清空的 `BPF_PROG_TYPE_EXT`
- 这里**没有** `prog->type == BPF_PROG_TYPE_STRUCT_OPS` 的排除分支。
- 同一个函数的注释 `3185-3197` 还明确写了：
  - generic trampoline user 由 `trampoline_users` refresh
  - `struct_ops trampolines bake bpf_func into a direct CALL`
  - `bpf_struct_ops_refresh_prog()` 会用 `text_poke` 修补它们

`vendor/linux-framework/kernel/bpf/syscall.c:3598-3634`

- `bpf_prog_rejit()` 先拿 `prog = bpf_prog_get(...)`
- 然后把 `err` 预设成 `-EOPNOTSUPP`
- 仅在 `!bpf_prog_rejit_supported(prog)` 时走 `goto out_put_prog`
- 因为 support predicate 没有排除 `STRUCT_OPS`，所以 syscall handler 本身并不会因为 `prog->type == BPF_PROG_TYPE_STRUCT_OPS` 而拒绝

容易混淆但**不相关**的一处检查：

`vendor/linux-framework/kernel/bpf/syscall.c:7048-7080`

- `prog_assoc_struct_ops()` 里有 `if (prog->type == BPF_PROG_TYPE_STRUCT_OPS) return -EINVAL;`
- 但这是 **`BPF_PROG_ASSOC_STRUCT_OPS`** syscall，不是 `BPF_PROG_REJIT`
- 它只限制 userspace 通过这个辅助 syscall 去给“非 struct_ops 程序”绑定 struct_ops map；真正的 struct_ops 程序关联是内核内部完成的

## 2. Kernel: struct_ops 的 JIT 替换路径和普通程序不同

### 2.1 普通 trampoline user

`vendor/linux-framework/include/linux/bpf.h:1728-1729`

- `aux->rejit_mutex` 序列化单个程序的 REJIT
- `aux->trampoline_users` 记录 generic trampoline 反向引用

`vendor/linux-framework/kernel/bpf/trampoline.c:846-865`

- `bpf_trampoline_link_prog()` 在 link 时把 trampoline 挂进 `prog->aux->trampoline_users`

`vendor/linux-framework/kernel/bpf/trampoline.c:930-950`

- `bpf_trampoline_refresh_prog()` 在 `bpf_func` 更新后遍历 `trampoline_users`
- 它不是 patch 某个 call 指令，而是直接 `bpf_trampoline_update()` 重建 trampoline image

### 2.2 struct_ops 程序

`vendor/linux-framework/include/linux/bpf.h:1824-1825`

- `aux->st_ops_assoc_mutex`
- `aux->st_ops_assoc`

`vendor/linux-framework/kernel/bpf/core.c:141-143`

- `bpf_prog` 创建时初始化了 `rejit_mutex`、`trampoline_users`、`st_ops_assoc_mutex`

`vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:807-822`

- struct_ops map setup 时，内核校验被引用程序必须真的是 `BPF_PROG_TYPE_STRUCT_OPS`
- 然后内部调用 `bpf_prog_assoc_struct_ops(prog, &st_map->map)`

`vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:1421-1448`

- `bpf_prog_assoc_struct_ops()` 把关联 map 写进 `prog->aux->st_ops_assoc`
- 这说明 REJIT 后续确实有地方能找到“这个 prog 对应哪个 struct_ops map”

`vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:1521-1618`

- `bpf_struct_ops_refresh_prog()` 是 struct_ops 的专用 refresh 路径
- 它会：
  - 从 `prog->aux->st_ops_assoc` 找到关联的 struct_ops map
  - 扫描 trampoline image，寻找 direct `CALL old_bpf_func`
  - 用 `bpf_arch_text_poke(... old_bpf_func, new_bpf_func)` 把 call site 原地改掉
  - 如果 patch 中途失败，还会回滚已 patch 的 call site

换句话说：

- 普通 trampoline user：**重建 trampoline**
- struct_ops：**对现有 trampoline 做 in-place text poke**

## 3. Kernel: REJIT 主路径确实调用了 struct_ops refresh 和 rollback

`vendor/linux-framework/kernel/bpf/syscall.c:3795-3862`

- swap 前后主流程是：
  - `bpf_prog_rejit_update_poke_tab(prog, tmp)`
  - `bpf_prog_rejit_poke_target_phase(prog, false)`
  - `bpf_prog_rejit_swap(prog, tmp)`
  - `bpf_prog_rejit_poke_target_phase(prog, true)`
  - `bpf_trampoline_refresh_prog(prog)`
  - 如果 `rcu_access_pointer(prog->aux->st_ops_assoc)` 非空，再调用
    `bpf_struct_ops_refresh_prog(prog, old_bpf_func)`
- 这说明内核不仅“没拒绝”，而且已经把 struct_ops 当成一个需要专门 post-swap refresh 的支持场景来处理

`vendor/linux-framework/kernel/bpf/syscall.c:3534-3591`

- rollback 路径里也有：
  - `bpf_trampoline_refresh_prog(prog)`
  - 若 `st_ops_assoc` 存在，则 `bpf_struct_ops_refresh_prog(prog, new_bpf_func)`
- 即使 struct_ops refresh 失败，代码也尝试把 call site 恢复到旧 image

## 4. `daemon/` 本身没有把 struct_ops 标成 unsupported

`daemon/src/bpf.rs:1608-1639`

- `run_rejit_once()` 只是构造 `AttrRejit` 然后直接发 `BPF_PROG_REJIT`
- 这里没有任何 `prog_type == STRUCT_OPS` 的检查

`daemon/src/commands.rs:531-573`

- live optimize path 把 `local_ctx.prog_type = info.prog_type`
- 然后只做通用的 BTF fd 校验和 `fd_array` 构造
- 没有 struct_ops special-case skip

`daemon/src/commands.rs:737-740`

- final apply 直接执行：
  - `validate_required_btf_fds(...)`
  - `let fd_array = build_rejit_fd_array(...)`
  - `bpf::bpf_prog_rejit(...)`
- 同样没有 struct_ops 分支

`daemon/src/bpf.rs:1141-1199`

- per-pass verify 的 `ProgLoadMeta` 从 live `bpf_prog_info` 回填：
  - `prog_type`
  - `attach_btf_obj_id`
  - `attach_btf_id`
  - `prog BTF`
  - `func_info` / `line_info`
- 这也是通用路径，不存在“看到 struct_ops 就不处理”的逻辑

额外观察：

`daemon/src/elf_parser.rs:1081-1087`

- 离线 ELF section 推断把 `struct_ops/` 归到 `BPF_PROG_TYPE_TRACING`
- 但 live ReJIT 路径使用的是 `bpf_prog_info.prog_type`，不是这个 section-name 推断，所以这不是本次 scx live skip 的直接原因

## 5. 真正触发 `"unsupported"` 的是 benchmark runtime，不是 daemon

`runner/libs/app_runners/scx.py:144-161`

- `ScxRunner` 发现 scx live programs 时，明确按 `bpftool` 返回的 `type == "struct_ops"` 过滤

`runner/libs/app_runners/scx.py:379-385`

- `live_rejit_skip_reason()` 只要发现当前 scheduler programs 里有 `struct_ops`，就返回：
  - `"live ReJIT for sched_ext struct_ops callbacks is currently unsupported on the benchmark runtime; skipping post-ReJIT phase"`

`corpus/driver.py:367-374`

- corpus lifecycle 的 `_before_rejit()` 会调用 `session.runner.live_rejit_skip_reason()`
- 如果有 reason，就直接返回 `LifecycleAbort(status="skipped", reason=reason)`

`e2e/cases/scx/case.py:341-349`

- e2e scx case 的 `before_rejit()` 也做了同样的事情

`runner/libs/case_common.py:262-279`

- `before_rejit` hook 发生在计算 live prog ids 和 daemon apply 之前
- 一旦 abort，这个 session 就不会进入后面的 REJIT/apply 阶段

所以当前 `"unsupported"` 的直接来源不是 syscall，也不是 `daemon/`，而是 **上层 benchmark runtime 在调用 daemon 之前主动跳过**

## 6. 风险上下文：仓库里确实还保留了 scx/struct_ops 的保守策略

下面这部分是**上下文证据**，不是当前 skip 的直接控制点。

`corpus/config/benchmark_config.yaml:29-34`

- 对 `prog_type: struct_ops`，显式禁用了 `map_inline` 和 `dce`
- 注释写得很直白：`struct_ops workloads currently rely on live scheduler-owned kptr state`
- 说明仓库维护者对 scx live state 仍然持保守态度

`tests/negative/scx_prog_show_race.c:3-13`

- 仓库保留了一个负向测试，标题就是
  `Repo-owned reproducer for the live scx struct_ops prog-show crash path`
- 这个测试会在启用 scx 后反复跑 `bpftool -j -p prog show`

`vendor/linux-framework/kernel/bpf/syscall.c:5816-5829`

- `bpf_prog_info_expose_subprog_metadata()` 对 `STRUCT_OPS` 返回 `false`
- 注释说明原因是：
  - `struct_ops programs can be registered/unregistered while userspace is polling prog metadata`
  - 因此只导出 stable main-program JIT fields

`vendor/linux-framework/kernel/bpf/syscall.c:5858-5866`

- `bpf_prog_get_info_by_fd()` 还会在 `rejit_mutex` 下 snapshot prog metadata
- 这是明显在缓解 live metadata polling 与 REJIT 并发时的一致性问题

我对这组证据的判断是：

- 当前内核代码已经在**努力支持** live struct_ops REJIT
- 但 benchmark runtime 仍旧出于保守性，选择直接跳过 scx 的 post-ReJIT 阶段
- 这个保守策略更像是“上层还没认可这条路径足够稳”，而不是“内核 syscall 明确不支持”

## Bottom Line

如果问题是“为什么现在看到 `struct_ops` 被标成 unsupported”，当前仓库里的直接答案是：

1. `vendor/linux-framework/kernel/bpf/syscall.c` 的 `BPF_PROG_REJIT` **没有**类型级别拒绝 `STRUCT_OPS`
2. 内核甚至已经实现了 `struct_ops` 专用的 refresh / rollback 路径
3. `daemon/` 也**没有**对 `struct_ops` 做 skip
4. 真正把 scx 跳过的是上层 runtime：
   - `runner/libs/app_runners/scx.py`
   - `corpus/driver.py`
   - `e2e/cases/scx/case.py`

因此，本次调查的主结论是：**当前 “unsupported” 的直接原因是 userspace runtime policy，不是 `BPF_PROG_REJIT` syscall handler 的内核拒绝，也不是 `daemon/` 本身的显式跳过。**
