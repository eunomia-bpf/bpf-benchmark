# crash path trace 2026-03-25

## 结论先行

这次不是一个 bug，而是两条被混在一起的路径：

1. `rusty_exit` / `rusty_init_task` 一类 malformed rewrite 的直接根因，在 daemon：
   `daemon/src/passes/const_prop.rs:analyze_instruction():202-218`、
   `fold_alu_instruction():237-251`、
   `evaluate_alu_result():269-375`、
   `emit_constant_load()/emit_ldimm64():443-470`。
   这组逻辑把 `BPF_PSEUDO_MAP_VALUE` 产生的 `map_value` 指针当普通常量做代数折叠，最后回写成 `src=0` 的普通 `LD_IMM64`，把 verifier 可见的 `map_value` provenance 改成了 `scalar`。

2. live 场景里真正导致 QEMU crash 的，不是 malformed `prog 20` 被 verifier 放过，也不是 REJIT 成功后的 trampoline/text_poke，而是 `probe_bpftool_register()` 之后第二次 `scx_rusty` 加载期间，对 live `struct_ops` 程序做 owner/metadata 查询时触发的内核 metadata race。最可能假说是 A，不是 B/C/D。
   路径是：
   `e2e/cases/scx/case.py:run_scx_case():657`
   -> `ScxSchedulerSession.__enter__():137-141`
   -> `_discover_programs():162-171`
   -> `runner/libs/agent.py:find_bpf_programs():113-144`
   -> `bpftool -j -p prog show`
   -> `vendor/linux-framework/kernel/bpf/syscall.c:bpf_prog_get_info_by_fd():5727-5802`。
   该路径里第一处已经被报告实锤的 crash 点是 `bpf_prog_get_stats():2460-2479` 历史版本缺少 `prog->stats == NULL` 保护；修掉后 crash 频率下降但未彻底消失，说明同一 metadata window 里还有额外 lifetime/race bug。

下面按用户要求拆开回答。

## 1. 复现报告里，哪些程序 REJIT 失败？错误是什么？

来自 `docs/tmp/20260325/tcg_min_repro_and_e2e_investigation_20260325.md`：

- `sysctl_monitor`
  - `BPF_PROG_REJIT: Invalid argument`
  - verifier: `call to invalid destination`
- `event_execve`
  - `BPF_PROG_REJIT: Invalid argument`
  - verifier: `unreachable insn 169`
- `lkm_seeker_modt`（`tracee --smoke`）
  - verifier: `unreachable insn 252`
- `rusty_init_task`（`prog 17`）
  - verifier: `R2 invalid mem access 'scalar'`
- `rusty_exit_task`（`prog 18`）
  - verifier: `R2 invalid mem access 'scalar'`
- `rusty_init`（`prog 19`）
  - verifier: `R2 invalid mem access 'scalar'`
- `rusty_exit`（`prog 20`，历史坏样本）
  - verifier: `R1 type=scalar expected=... map_value ...`

同一份报告里，QEMU crash 的外部签名是稳定的：

- 进程：`qemu-system-x86_64`
- 信号：`SIGSEGV`
- fault offset：`0x8d8f21`
- `addr2line` 指向 `tlb_set_dirty`

但这个 crash 不等于 `prog 20` 被 verifier 接受；后面的 dump 已经把这件事排除了。

## 2. QEMU crash 的具体触发路径

代码级路径如下：

1. `run_scx_case()` 先做 raw probe：
   `e2e/cases/scx/case.py:657`
   `bpftool_probe = probe_bpftool_register(...)`
2. 然后进入正常 `scx_rusty` loader：
   `e2e/cases/scx/case.py:673-679`
3. `ScxSchedulerSession.__enter__()` 用 health check 等待：
   `e2e/cases/scx/case.py:137-141`
   `read_scx_state() == "enabled" and bool(self._discover_programs())`
4. `_discover_programs()` 调 `find_bpf_programs(self.pid)`：
   `e2e/cases/scx/case.py:162-171`
5. `find_bpf_programs()` 先扫 `/proc/<pid>/fdinfo`，再执行
   `bpftool -j -p prog show`：
   `runner/libs/agent.py:93-144`
6. 内核进入 `bpf_prog_get_info_by_fd()`：
   `vendor/linux-framework/kernel/bpf/syscall.c:5727-5802`
7. 报告里的内核插桩表明，第一处明确缩小到的 crash 点是
   `bpf_prog_get_stats()`：
   `vendor/linux-framework/kernel/bpf/syscall.c:2460-2479`

报告后期的最小 live 触发器已经进一步缩小到：

- `probe_bpftool_register()`
- 启动第二个 `scx_rusty --stats 1`
- 等待 `sched_ext == enabled`
- 只执行一次 `bpftool -j -p prog show id 42`

这就足够再次打出 host `qemu-system-x86_64` segfault。也就是说，最小 live crash 现在已经不需要 daemon `apply`，更不需要 bad `prog 20` 被发布。

## 3. `rusty_exit` (`prog 20`) 的 malformed rewrite 长什么样？

### 原始字节码

见 `docs/tmp/20260325/scx_prog20_dump/orig_xlated_opcodes.txt`：

- `pc 4: r1 = map[id:13][0]+424`
- `pc 6: r1 += 16`
- `pc 9: r1 = map[id:13][0]+424`
- `pc 11: r1 += 144`

这两次 `+=` 都是在 `map_value` pointer 上做偏移，verifier 会继续把它看成 `map_value + off`。

### 历史坏 rewrite

见 `docs/tmp/20260325/scx_apply_20/apply.stderr`：

- `const_prop changed:true, sites_applied:3`
- `dce changed:true`
- `30 -> 31 insns`

坏样本在 verifier log 里直接长这样：

- `4: (18) r1 = 0xffff... ; R1=map_value(... off=424)`
- `6: (18) r1 = 0x1a800000021 ; R1=scalar`
- `9: call bpf_probe_read_kernel_str#115`
- verifier: `R1 type=scalar expected=... map_value ...`

后面第二处同样被折坏：

- `10: r1 = map_value(... off=424)`
- `12: r1 = 0x1a8000000a1`

所以 malformed rewrite 的本质不是“把 helper 参数算错了一点”，而是把“带类型的 map_value 指针”改写成了“无类型的普通立即数”。

### 当前好 rewrite

见 `docs/tmp/20260325/scx_prog20_dump/rewrite.stdout`：

- `30 -> 29 insns`
- `pc 4/5` 仍然是 pseudo map-value `LD_IMM64`
- `pc 6` 仍然保留 `r1 += 16`
- `pc 11` 仍然保留 `r1 += 144`

这说明“正确 rewrite”不是不能做，而是历史坏样本里的 `const_prop` 误把 pointer arithmetic 当成了 scalar arithmetic。

## 4. verifier 为什么在 live 场景“放过了” malformed bytecode？

没有放过。

这点现在已经可以直接下结论：

- `docs/tmp/20260325/scx_probe_stage/`
  - `enumerate -> apply 20`，同一个坏 `prog 20`，verifier 直接拒绝
  - 无 QEMU crash
- `docs/tmp/20260325/scx_apply_probe_silent/`
  - 同一个坏 `prog 20`，`apply20_rc=1`
  - verifier 同样拒绝
  - 无 QEMU crash
- `docs/tmp/20260325/scx_bad20_replay/`
  - 直接把坏字节码走 `BPF_PROG_REJIT`
  - `errno=13`
  - verifier 在 insn 9 停下
  - 无 QEMU crash

内核代码也支持这个结论。`BPF_PROG_REJIT` 在
`vendor/linux-framework/kernel/bpf/syscall.c:3680-3683`
先调用 `bpf_check(&tmp, ...)`；只要 verifier 拒绝，就直接走错误清理路径。只有 verifier 通过以后，才会走：

- `bpf_prog_rejit_swap()`：`3739`
- `bpf_trampoline_refresh_prog()`：`3747`
- `bpf_struct_ops_refresh_prog()`：`3764-3765`

所以 bad `prog 20` 这条路径上，根本到不了 trampoline/text_poke。

## 5. replay 为什么能正确拒绝，而 live 会 crash？

因为 replay 和 live 走的根本不是同一条危险路径。

### replay 场景

`docs/tmp/20260325/scx_bad20_replay/` 只做一件事：把坏字节码直接提交给 `BPF_PROG_REJIT`。

结果：

- verifier 在 helper 调用前就看到 `R1=scalar`
- `rejit_ret=-1 errno=13`
- 程序未发布
- 不会进入 `bpf_prog_rejit_swap()`
- 不会进入 `bpf_struct_ops_refresh_prog()`
- 也不会触发 `bpftool prog show` 的 program-info 查询

### live 场景

live crash 需要额外的共享状态和时间窗口：

- 先做一次 raw `struct_ops register` probe
- 再启动第二次正常 `scx_rusty` loader
- 在第二次 loader 尚未稳定时，health check 里开始跑 `find_bpf_programs(pid)`
- `find_bpf_programs(pid)` 又会调用 `bpftool -j -p prog show`
- 于是内核开始枚举 live `struct_ops` program metadata

报告里的后续最小化已经证明：

- 跳过 raw probe，`ScxSchedulerSession` 稳定
- 只做 raw probe，也稳定
- `probe + second loader + state-only wait` 可稳定
- `probe + second loader + find_bpf_programs(pid)` 会死
- 甚至只查 `bpftool prog show id 42` 就够了

因此，live crash 的真正差异不是 verifier 环境不同，而是 live 额外踩到了“probe 后第二次 loader 的 metadata 枚举竞态窗口”。

## 6. dump 目录交叉结论

### `scx_apply_20/`

- 坏 `prog 20`
- `map_inline changed:false`
- `const_prop changed:true`
- verifier 明确报 `R1 type=scalar expected=... map_value ...`

### `scx_prog20_dump/`

- `orig_xlated_opcodes.txt` 给出原始 `map_value + 16` / `map_value + 144`
- `rewrite.stdout` 给出当前正确 rewrite，偏移加法仍保留

### `scx_apply_17/`

- 当前好样本
- `REJIT ok`
- 只有 `extract` 变更，没有出现这次坏 `const_prop`

### `scx_apply_17_bad_1256/`

- 历史坏样本
- `const_prop changed:true`
- verifier 最终在：
  - `r2 = 0`
  - `*(u32 *)(r2 + 4)`
  - 报 `R2 invalid mem access 'scalar'`

### `scx_prog17_dump/`

- 对应 `prog 17` 的 dump
- 用来对照 bad/good pipeline 差异

### `scx_bad20_replay/`

- 复刻坏 `prog 20`
- 内核正常拒绝
- 无 crash

### `scx_apply_probe_silent/` 与 `scx_probe_stage/`

- 都证明：
  - 同一坏 `prog 20` 可以被 verifier 干净拒绝
  - 不需要 crash

### `scx_workload_probe/`

- 单纯 workload 稳定
- `scx_rusty` 自身不是普遍不稳定

### `scx_rejit_workload_probe/`

- `apply-20` 可成功
- `apply-17/18/19` 会被 verifier 拒绝
- 说明 “daemon apply-all 批量 REJIT 导致共享状态污染” 不是最强解释

## 7. daemon 代码追踪：到底哪个 pass 把 map_value pointer 改成了 scalar？

不是 `map_inline`，是 `const_prop`。

### 为什么不是 `map_inline`

`daemon/src/passes/map_inline.rs:405-447` 只是把“从 map value 固定 offset 读出的标量”替换成常量读；本次坏样本里 `scx_apply_20/apply.stderr` 已经明确记录：

- `map_inline changed:false`

所以这次 SCX malformed rewrite 不是它干的。

### 真正的责任链

`daemon/src/passes/const_prop.rs` 里有四个连续问题：

1. `analyze_instruction():202-205`
   - 任何 `LD_IMM64` 都会被 `decode_ldimm64()` 解成普通 `u64`
   - 完全不区分这是普通常量，还是 `BPF_PSEUDO_MAP_VALUE`

2. `evaluate_alu_result():269-375`
   - 对 `BPF_ADD/BPF_SUB/...` 只做纯数值计算
   - `map_value + 16` 会被当成 “某个 64-bit 常量 + 16”

3. `fold_alu_instruction():237-249`
   - 一旦算出结果，就把原来的 `ADD` 直接替换成 `emit_constant_load(...)`

4. `emit_constant_load()/emit_ldimm64():443-470`
   - 回写的是普通 `LD_IMM64`
   - `regs: make_regs(dst_reg, 0)`，也就是 `src=0`
   - 这一步把 pseudo map-value 的 verifier 类型信息彻底抹掉了

这四步连起来，正好和 dump 完全吻合：`map_value + off` 被折成了 `scalar ldimm64`。

## 8. 内核代码追踪：为什么我不选 D（trampoline/text_poke）？

因为 bad `prog 20` 的路径根本到不了那里。

`vendor/linux-framework/kernel/bpf/syscall.c` 中：

- `3554-3683`：构造 `tmp` 并跑 verifier
- `3680-3683`：verifier 失败直接退出
- `3739` 之后才是 `bpf_prog_rejit_swap()`
- `3747` 之后才是 `bpf_trampoline_refresh_prog()`
- `3764-3765` 才可能进入 `bpf_struct_ops_refresh_prog()`

而 `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:1518-1604`
里的 `bpf_struct_ops_refresh_prog()` 也确实只是“在 REJIT swap 成功后，去 patch
struct_ops trampoline 里旧的 direct CALL 目标”。它本身不是 verifier 前路径。

而 `docs/tmp/20260325/scx_apply_20/apply.stderr` 和
`docs/tmp/20260325/scx_bad20_replay/replay.stdout` 都证明 bad `prog 20` 在 verifier 就被挡住了。

所以 D 不成立。

## 9. 关键问题：为什么 live crash，但 replay 不 crash？

我选 A，而且要把 A 说完整：

> live 场景下存在 `probe_bpftool_register()` 之后、第二次 `scx_rusty` loader 尚未稳定时，对 live `struct_ops` program 做 metadata/owner 枚举的竞态；replay 根本不走这条路径。

代码级证据：

- 触发 probe 的地方：
  - `e2e/cases/scx/case.py:657`
- 触发 metadata 枚举的地方：
  - `e2e/cases/scx/case.py:137-141`
  - `e2e/cases/scx/case.py:162-171`
  - `runner/libs/agent.py:113-144`
- 内核元数据出口：
  - `vendor/linux-framework/kernel/bpf/syscall.c:bpf_prog_get_info_by_fd():5727-5802`
- 第一处已实锤的 crash-path bug：
  - `vendor/linux-framework/kernel/bpf/syscall.c:bpf_prog_get_stats():2460-2479`
  - 历史版本对 `prog->stats == NULL` 没保护就 `per_cpu_ptr(prog->stats, cpu)`

为什么不是 B：

- `scx_rejit_workload_probe/` 说明 apply-all 本身不是最小 crash 条件
- 后期最小 live reproducer 已经不需要 daemon apply，只需要 query owner id `42`

为什么不是 C：

- live/stage/silent/replay 对 bad `prog 20` 的 verifier 结论一致，都是拒绝

为什么不是 D：

- bad `prog 20` 没有通过 verifier，走不到 `swap/trampoline/text_poke`

## 10. root cause（精确到文件:函数:行号）

### 10.1 malformed rewrite 的 root cause

- 文件：`daemon/src/passes/const_prop.rs`
- 函数：
  - `analyze_instruction()`：`202-218`
  - `fold_alu_instruction()`：`237-251`
  - `evaluate_alu_result()`：`269-375`
  - `emit_constant_load()` / `emit_ldimm64()`：`443-470`
- 根因：
  - 把 `BPF_PSEUDO_MAP_VALUE` 物化出来的 typed pointer 当成普通常量传播
  - 再把 pointer arithmetic 折叠成普通 `LD_IMM64`
  - 导致 verifier 看到 `scalar` 而不是 `map_value`

### 10.2 live QEMU crash 的 root cause

- 文件：`vendor/linux-framework/kernel/bpf/syscall.c`
- 函数：
  - `bpf_prog_get_info_by_fd()`：`5727-5802`
  - `bpf_prog_get_stats()`：`2460-2479`
- 根因：
  - live crash 发生在 probe 后第二次 loader 的 program-info 查询窗口
  - 第一处已经确认的实际 crash bug，是历史版本 `bpf_prog_get_stats()` 对 `prog->stats == NULL` 缺少保护
  - 但由于加 guard 后仍可复现，说明 broader root cause 不是“单点 NULL 解引用”这么简单，而是同一 metadata path 上仍存在 lifetime/race bug

如果只允许给一个最可能答案，我给：

> `vendor/linux-framework/kernel/bpf/syscall.c:bpf_prog_get_info_by_fd()` 触发的 live struct_ops metadata race；
> `bpf_prog_get_stats()` 的 NULL-stats 解引用是这条 crash path 上第一处已被代码和插桩共同坐实的具体 bug。

## 11. 为什么之前的 review 没发现

有三个原因：

1. 之前把两类问题混成了一个问题
   - 把 “bad `prog 20` 被 verifier 拒绝” 和 “live QEMU crash” 串成单一路径
   - 但 `scx_probe_stage` / `scx_apply_probe_silent` / `scx_bad20_replay` 已经证明它们是分离的

2. `const_prop` 的测试覆盖缺口刚好卡在这类 bug 上
   - `daemon/src/passes/const_prop.rs:602-705` 的测试只覆盖：
     - 标量 ALU folding
     - 普通 `ldimm64` 常量追踪
     - branch folding
     - `map_inline` 后的标量分支折叠
   - 没有任何 `BPF_PSEUDO_MAP_VALUE` / pointer provenance 测试

3. 真正的 live crash 不在 REJIT publish path，而在 metadata query path
   - 如果只盯 `BPF_PROG_REJIT` / `bpf_struct_ops_refresh_prog()`，会自然走向错误假说 D
   - 但后续最小化已经把触发器缩到 `bpftool prog show id 42`

## 12. 修复方案

### daemon 侧

1. `const_prop` 必须区分“普通常量”和“typed pseudo value”
   - 至少对 `BPF_PSEUDO_MAP_VALUE` 禁止当前这类 constant fold
   - 更稳妥的是给寄存器状态加类型标签，而不是只存 `Option<u64>`

2. 禁止把 pointer arithmetic 回写成 `src=0` 的普通 `LD_IMM64`
   - 对 `map_value + const` 这种场景，要么保留原始 `ADD`
   - 要么显式保留 pseudo source/type 信息

3. 增加回归测试
   - `map_value + 16` 后喂 helper，rewrite 后 verifier type 不能变
   - 覆盖 `prog 17/18/19/20` 这类 struct_ops 模式

### 内核侧

1. 保留 `bpf_prog_get_stats()` 的 `!prog->stats` guard
   - 这是已确认的真实安全修复

2. 继续审计 `bpf_prog_get_info_by_fd()` 的 snapshot/lifetime
   - 特别是 raw probe 后第二次 loader 尚未稳定时的 `struct_ops` program metadata
   - 重点看 `used_maps`、`func/func_cnt`、stats、aux ownership 是否都在同一一致性边界内

3. 在修内核前，E2E 先规避触发窗口
   - 不要在 `probe_bpftool_register()` 之后立刻用 `find_bpf_programs(pid)` 做健康检查
   - 先等 `sched_ext == enabled` 稳定，再做 program enumeration

## 最终回答

这次 live crash 的真正 root cause，不是 verifier bypass，也不是 bad `prog 20` 被发布后把 trampoline/text_poke 打坏；最可能的是 `probe + second loader + bpftool prog show` 触发的 kernel metadata race。`const_prop` 确实有严重 rewrite bug，但它解释的是 `prog 17/18/19/20` 的 verifier rejection，不是 live QEMU crash 本身。
