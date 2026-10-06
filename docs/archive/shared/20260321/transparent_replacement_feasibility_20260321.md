# 运行时透明替换 live BPF 程序的可行性调研

日期: 2026-03-21  
范围: `vendor/linux-framework/` (7.0-rc2), `vendor/libbpf/`

## 结论先行

如果要求同时满足:

1. 完全透明  
2. 严格零运行时开销  
3. 零 attach 变化  
4. 尽量覆盖 link 与非 link attach

那么**唯一能严格满足目标的终局方案是“同一个 `struct bpf_prog` 原地重验证 + 重 JIT + 原子 image swap”**。这在当前树里已经有一半基础设施:

- 已有 `BPF_PROG_JIT_RECOMPILE` 可以在**不替换 `struct bpf_prog`** 的前提下，原子替换 JIT image，且会处理 trampoline retarget，见 `vendor/linux-framework/kernel/bpf/jit_directives.c:311-582`, `584-747`
- 但它目前是 **native/JIT-level** recompile，不是 bytecode-level rewrite
- 当前内核**不保留原始 eBPF 字节码**；`prog->insnsi` 是 verifier/xlator 之后的当前指令流，不是可直接重放的原始 load 输入，见 `vendor/linux-framework/kernel/bpf/syscall.c:3017-3040`, `vendor/linux-framework/kernel/bpf/verifier.c:22012-22041`, `22990-23022`

因此推荐路线是:

- **短期最优**: 对能接受 native-level rewrite 的场景，优先用现有 **路径 3 (`BPF_PROG_JIT_RECOMPILE`)**
- **中期/终局**: 在路径 3 的 commit/swap 基础上新增 **路径 4 (`BPF_PROG_REJIT`)**，并补一个 **`BPF_PROG_GET_ORIGINAL`**
- **路径 1 (`bpf_link_update`)** 只能做“换一个新 prog”，不是“原地改同一个 prog”；对 app 不是完全透明
- **路径 2 (`freplace`)** steady-state 不是通用 trampoline，但仍然有**一个额外入口跳转**，严格来说**不是零运行时开销**

## 术语和判定标准

- “零运行时开销”: 替换后 fast path 与原始 attach 路径相比，不新增 trampoline / 间接调用 / 入口额外跳转
- “零 attach 开销”: 不需要 detach + reattach，不改变 hook 上持有的引用关系
- “完全透明”: loader 持有的原 `prog_fd` / `prog_id` / map state / link 关系继续表示同一个 live 程序实例；应用不需要感知程序对象被替换

按这个标准，**路径 3/4 才是严格命中目标的路线**。

---

## 1. 路径 1: `bpf_link_update` 在 link 层替换整个程序

### 1.1 通用机制

`bpf_link_update` 的通用入口在:

- `vendor/linux-framework/include/linux/bpf.h:1910-1932`  
  `struct bpf_link_ops` 定义了 `update_prog` / `update_map`
- `vendor/linux-framework/kernel/bpf/syscall.c:5817-5870`  
  `link_update()` 先拿 `link_fd`，若 link 支持 `update_map` 则走 map update；否则拿 `new_prog_fd` / 可选 `old_prog_fd` 并调用 `link->ops->update_prog`

通用语义:

- `flags` 只允许 `BPF_F_REPLACE`，见 `syscall.c:5827-5829`
- 带 `BPF_F_REPLACE` 时会抓取 `old_prog_fd` 并传给 hook-specific `update_prog` 回调，见 `syscall.c:5846-5852`
- 如果 link type 没有 `update_prog`，直接 `-EINVAL`，见 `syscall.c:5858-5861`

### 1.2 各 `bpf_link` type 逐一分析

当前树中的 link type 枚举位于 `vendor/linux-framework/include/uapi/linux/bpf.h:1166-1183`。  
注意: 这棵树里除了题目列出的 13 个 type，**还额外有 `BPF_LINK_TYPE_SOCKMAP = 14`**。

### 1.3 总表

| link type | 有 `update_prog`? | 原子? | 严格零开销? | 源码位置 | 主要限制 |
|---|---|---|---|---|---|
| `RAW_TRACEPOINT` | 否 | 否 | 否 | `vendor/linux-framework/kernel/bpf/syscall.c:3851-3856` | link 本身可由 `BPF_RAW_TRACEPOINT_OPEN` 创建，但没有 update 回调 |
| `TRACING` (`fentry`/`fexit`/`fmod_ret`/`freplace`) | 否 | 否 | 否 | `vendor/linux-framework/kernel/bpf/syscall.c:3560-3565` | `BPF_LINK_TYPE_TRACING` 不支持 `link_update`; freplace 不能靠路径 1 做更新 |
| `CGROUP` | 是 | 是 | 是 | ops: `vendor/linux-framework/kernel/bpf/cgroup.c:1461-1468`; replace: `976-1032` | 新旧 `prog_type` 必须相同；`attach_type` 通过 `attach_btf_id` 映射，见 `986-988`; `old_prog` 不匹配返回 `-EPERM` |
| `ITER` | 是 | 是 | 是，但只影响未来新开的 iterator FD | ops: `vendor/linux-framework/kernel/bpf/bpf_iter.c:491-497`; replace: `408-430`; seq-file snapshot: `589-620` | `prog_type` / `expected_attach_type` / `attach_btf_id` 必须全相同；已打开的 iterator 在 `prepare_seq_file()` 抓取了旧 `prog` 引用 |
| `NETNS` | 是 | 是 | 是 | ops: `vendor/linux-framework/kernel/bpf/net_namespace.c:235-241`; update: `163-200` | `prog_type` 必须相同；通过 `bpf_prog_array_update_at()` 改 run-array slot |
| `XDP` | 是 | 基本是 | 是 | ops: `vendor/linux-framework/net/core/dev.c:10649-10656`; update: `10599-10647` | `prog_type` 和 `expected_attach_type` 必须相同；走 `dev_xdp_install()`，原位换 driver/netdev 持有的 XDP prog |
| `PERF_EVENT` | 否 | 否 | 否 | `vendor/linux-framework/kernel/bpf/syscall.c:4165-4169` | 无 `update_prog`; perf/kprobe/tracepoint 这条路无法靠路径 1 替换 |
| `KPROBE_MULTI` | 否 | 否 | 否 | `vendor/linux-framework/kernel/trace/bpf_trace.c:2478-2485` | 无 `update_prog` |
| `STRUCT_OPS` | **不是 `update_prog`，而是 `update_map`** | map 级别是 | 对“struct_ops map swap”是，但**不是通用 prog 替换** | `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:1260-1307`, `1350-1356`; 另有内部 link ops `592-595` | 只能换 `struct_ops map`；新旧 `struct_ops` 类型必须相同；不适合作为“任意 live prog 替换”通道 |
| `NETFILTER` | 有，但永远 `-EOPNOTSUPP` | 否 | 否 | `vendor/linux-framework/net/netfilter/nf_bpf_link.c:165-178` | 回调存在，但实现直接拒绝 |
| `TCX` | 是 | 是 | 是 | ops: `vendor/linux-framework/kernel/bpf/tcx.c:289-296`; update: `203-244`; mprog fast path: `vendor/linux-framework/include/linux/bpf_mprog.h:95-113`, `242-246`; replace core: `vendor/linux-framework/kernel/bpf/mprog.c:108-125` | 走 `bpf_mprog_attach(..., BPF_F_REPLACE | BPF_F_ID, link->prog->aux->id, ...)`; 不改 attach 关系，只换 slot 中 prog |
| `UPROBE_MULTI` | 否 | 否 | 否 | `vendor/linux-framework/kernel/trace/bpf_trace.c:3065-3072` | 无 `update_prog` |
| `NETKIT` | 是 | 是 | 是 | ops: `vendor/linux-framework/drivers/net/netkit.c:763-770`; update: `678-718`; fast path: `39-52` | 和 TCX 同类，走 `bpf_mprog` 原位替换 |
| `SOCKMAP` | 是（额外 type） | 是 | 是 | ops: `vendor/linux-framework/net/core/sock_map.c:1833-1840`; update: `1746-1799` | 题目未列出，但当前树存在；要求 `prog_type` 与 `expected_attach_type` 匹配；通过 `psock_set_prog/replace_prog` 更新 map 持有的 prog |

### 1.4 关键观察

1. **路径 1 的覆盖面比直觉小得多**  
   真正支持 `update_prog` 的只有: `CGROUP`, `ITER`, `NETNS`, `XDP`, `TCX`, `NETKIT`, `SOCKMAP`

2. **对严格透明性的致命问题**  
   路径 1 是“**link 指向新 `struct bpf_prog`**”，不是“改原来的 `struct bpf_prog`”。  
   比如 `CGROUP` / `XDP` / `NETNS` / `TCX` 都会 `xchg(&link->prog, new_prog)`，见:
   - `vendor/linux-framework/kernel/bpf/cgroup.c:1004-1006`
   - `vendor/linux-framework/net/core/dev.c:10641-10642`
   - `vendor/linux-framework/kernel/bpf/net_namespace.c:191-196`
   - `vendor/linux-framework/kernel/bpf/tcx.c:235-239`

   这意味着:

   - loader 手里的原 `prog_fd` 仍指向旧 prog
   - 旧 prog 的 `prog_id` / stats / JIT image 都还在旧对象上
   - app 如果观察自己的原始 prog，会发现“它不再是 live 的那一个”

   所以**路径 1 不是“完全透明”**，只是“hook 层透明”

3. **零运行时开销只对支持更新的 hook 成立**  
   对 `CGROUP` / `NETNS` / `XDP` / `TCX` / `NETKIT` / `SOCKMAP`，update 之后 fast path 仍然直接跑新的 `bpf_prog`，没有额外 trampoline/indirect call  
   但这不等于“完全透明”

### 1.5 路径 1 的判定

- 优点: 不需要 detach + reattach；对支持的 link type 运行时没有额外开销
- 缺点: 覆盖面有限；**程序对象 identity 变化**，不满足“完全透明”
- 结论: **可作为非终局 fallback，不适合作为总方案**

---

## 2. 路径 2: `freplace` (`BPF_PROG_TYPE_EXT`) 用 trampoline 子系统替换函数

### 2.1 实际机制不是“steady-state 通用 trampoline”

`freplace` 的 attach 逻辑在 trampoline 子系统，但**steady-state 执行并不是走通用 save-regs trampoline image**。

关键代码:

- attach 类型映射到 `BPF_TRAMP_REPLACE`: `vendor/linux-framework/kernel/bpf/trampoline.c:967-989`
- freplace 检查目标 prog: `991-1007`
- freplace attach 时直接 `text_poke` 目标函数入口:
  - `vendor/linux-framework/kernel/bpf/trampoline.c:1009-1041`
  - 真正的 patch 在 `1038-1040`
- dettach/rollback 时把入口从 `JUMP` 改回 `NOP`:
  - `vendor/linux-framework/kernel/bpf/trampoline.c:1095-1122`
  - patch-back 在 `1105-1107`
- x86 `text_poke` 生成 5-byte near `JMP`/`CALL`:
  - `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:601-661`
  - `0xE9` 为 jump，见 `emit_jump` 路径

也就是说，freplace steady-state 是:

- 原目标 BPF 函数入口的 5-byte NOP
- 被改成 `jmp new_prog->bpf_func`

**不是**:

- 先跳到一个保存所有寄存器的 trampoline，再间接 call 新 prog

### 2.2 通用 trampoline 的真实开销

通用 fentry/fexit/fmod_ret trampoline 的 x86 JIT 代码确实很重:

- 保存 frame / stack / RBX / 参数寄存器，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:4852-4878`
- 可能先 `call __bpf_tramp_enter`，见 `4880-4888`
- 每个附加 BPF prog 通过 `__bpf_prog_enter* -> prog->bpf_func -> __bpf_prog_exit*` 跑，见:
  - x86 JIT 示例注释: `4655-4681`
  - trampoline runtime helpers: `vendor/linux-framework/kernel/bpf/trampoline.c:1372-1568`
- 若需要 call original / fexit / fmod_ret，还会有额外 call、恢复寄存器、写回返回值，见 `4918-5010`

所以如果问题是“通用 tracing trampoline 有多重”，答案是:

- 有寄存器保存/恢复
- 有 helper call
- 有 `prog->bpf_func` 调用
- 代码里**没有提供纳秒级数字**

### 2.3 freplace 自身的 steady-state 开销

对 freplace 本身，源码支持的严格结论是:

- **没有**通用 trampoline 的 save/restore 成本
- **没有**额外间接调用
- **有**一个额外的入口 `JMP`

因此:

- 如果判定标准是“没有 trampoline / 没有间接调用”，freplace 很接近目标
- 如果判定标准是“和原来一模一样快”，那**仍然不是严格零运行时开销**

### 2.4 “能不能消除 trampoline 开销?”

问题里的三个方向对应源码结论如下:

1. 直接修改目标函数 JIT image 入口跳转  
   **已经是 freplace 当前实现**，见 `trampoline.c:1038-1040`

2. freplace 后把 trampoline inline 进去  
   对 freplace steady-state 不成立，因为 steady-state 本来就没走通用 trampoline image

3. 用 `text_poke` 直接 patch  
   **已经这样做了**

如果还要进一步把“入口额外 `JMP`”也消掉，那就不再是 freplace，而是:

- 改 target prog 自己的 JIT image
- 或改 `prog->bpf_func` 指向同一对象的新 image

这已经回到**路径 3/4**

### 2.5 支持哪些 `prog_type`?

源码没有给 EXT 维护一个“目标 prog_type 白名单”。相反，它让 EXT 在验证阶段**继承目标程序的 verifier ops 和 attach_type**:

- `vendor/linux-framework/kernel/bpf/verifier.c:25354-25361`
- `vendor/linux-framework/include/linux/bpf_verifier.h:959-963`

约束来自 `bpf_check_attach_target()`:

- 必须提供 `btf_id`，见 `24935-24938`
- 目标 prog 必须有 BTF，见 `24939-24944`
- 目标子函数必须在 `func_info[]` 里，见 `24966-24974`
- 只能替换 **global function**，不能替换 static function，见:
  - target-side conservative/static 限制: `24981-24987`
  - BTF linkage 检查: `vendor/linux-framework/kernel/bpf/btf.c:7552-7559`
- EXT 自己必须请求 JIT，见 `24988-24992`
- target 也必须是 JITed prog，见 `25011-25014`
- 不能 EXT-on-EXT，见 `25025-25033`
- 不能扩展 `fentry/fexit/fsession` target，见 `25034-25054`
- **不能替换 kernel functions**，见 `25056-25060`

另外还有两个 attach-time 限制在 trampoline 子系统里:

- target prog 若已经是某个 `prog_array` 的成员，会拒绝 freplace，以避免 `A -> tailcall -> B -> extension -> B entry` 这类环，见 `vendor/linux-framework/kernel/bpf/trampoline.c:991-1007`
- replace 目标上如果已经挂了 `fentry/fexit/fmod_ret`，会在 link 阶段直接 `-EBUSY`，见 `vendor/linux-framework/kernel/bpf/trampoline.c:1009-1041`

因此支持集合可以概括为:

- **任何 JITed、带 BTF func info、含 global function 的 BPF 程序**
- 但不包括:
  - kernel function
  - static function
  - 另一层 EXT
  - fentry/fexit/fsession 作为 target

### 2.6 BTF 签名匹配有多严格?

很严格。`btf_check_type_match()` / `btf_check_func_type_match()` 要求:

- 目标函数和替换函数都必须 `BTF_FUNC_GLOBAL`，见 `vendor/linux-framework/kernel/bpf/btf.c:7552-7559`
- 参数个数相同，见 `7573-7577`
- 返回类型 `info` 相同，见 `7579-7587`
- 每个参数类型 `info` 相同，若有 size 还要 size 相同，见 `7589-7605`
- 允许的复杂类型极窄:
  - scalar / enum
  - 或“指向 context struct 的指针”，并且 struct 名字要匹配，见 `7607-7647`

结论: **这是“函数 ABI 等价”级别的严格匹配，不是宽松匹配**。

### 2.7 能否替换整个程序 main function?

**可以。**

`bpf_check_attach_target()` 找 `func_info[i].type_id == btf_id`，若 `subprog == 0`，目标地址就是:

- `addr = (long)tgt_prog->bpf_func`，见 `vendor/linux-framework/kernel/bpf/verifier.c:25167-25171`

所以 EXT 不只是替换 subprogram，也可以替换主入口函数，只要:

- main function 有 BTF func info
- 它是 global function
- 签名严格匹配

### 2.8 可回滚机制

detach freplace link 时:

- 入口 `JUMP` 会被 `text_poke` 回 `NOP`，见 `vendor/linux-framework/kernel/bpf/trampoline.c:1105-1107`
- `tr->extension_prog` 被清空，见 `1110`
- 在 `tgt_prog->aux->ext_mutex` 保护下把 `tgt_prog->aux->is_extended = false`，见 `1113-1118`

所以 freplace 的回滚是明确、成体系的。

### 2.9 freplace 的致命缺点

1. **不是严格零运行时开销**  
   多了一个入口 `JMP`

2. **不是完全透明**  
   target prog 仍是旧对象；新逻辑在 ext prog 对象里  
   loader 观察原 `prog_fd` / stats / `prog_id` 时并不等价于“同一个程序被原地改写”

3. **不是零 attach 变化**  
   需要新建一个 tracing link/extension attach

4. **覆盖面窄**  
   依赖 BTF/global/JIT/signature match

### 2.10 路径 2 的判定

- 优点: 比通用 trampoline 轻得多；不走间接调用；支持 detach 回滚
- 缺点: 仍有入口跳转；不是同 prog 对象；覆盖面窄
- 结论: **可以作为特定 BTF-rich 程序的“近似零开销” fallback，但不满足题目最严格目标**

---

## 3. 路径 3: 直接替换 JIT image（当前 `BPF_PROG_JIT_RECOMPILE` 扩展）

### 3.1 现有机制概览

当前树已经有:

- UAPI 命令 `BPF_PROG_JIT_RECOMPILE`，见 `vendor/linux-framework/include/uapi/linux/bpf.h:980-997`
- attr 定义，见 `vendor/linux-framework/include/uapi/linux/bpf.h:2010-2017`
- `prog->aux` 上的 staged/rollback 字段，见 `vendor/linux-framework/include/linux/bpf.h:1727-1740`
- 主逻辑在 `vendor/linux-framework/kernel/bpf/jit_directives.c:584-747`

### 3.2 它到底换了什么

**它不换 `struct bpf_prog`。**

核心点:

- 抓 `prog_fd`，锁 `main_aux->jit_recompile_mutex`，见 `jit_directives.c:610-619`
- 只接受 JITed prog，见 `637-642`
- live `struct_ops` 先拒绝，见 `644-649`
- blinded prog 先拒绝，见 `652-657`
- 先 snapshot 当前 state，见 `679-685`
- 重 JIT 所有 image，再 commit staged image，见 `311-582`

真正 commit 的地方是 arch-specific:

- x86: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5495-5522`
- arm64: `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2908-2933`

两边都用:

- `smp_store_release(&prog->bpf_func, staged_func)`

而不是 `xchg/cmpxchg`

所以 current image swap 模型是:

- staged new text
- release-store 更新 `prog->bpf_func`
- `synchronize_rcu()` 后回收旧 image，见 `vendor/linux-framework/kernel/bpf/jit_directives.c:516-522`

### 3.3 如何原子替换 JIT image

关键链路:

1. snapshot 旧状态  
   `vendor/linux-framework/kernel/bpf/jit_directives.c:88-149`

2. 每个 image prog 打开 `jit_recompile_active`，见 `338-348`

3. `bpf_int_jit_compile()` 生成 staged image，见 `350-362`

4. 若有 subprog，先把 pseudo func/pseudo call 重定向到 staged subprog targets，见 `364-426`

5. arch `bpf_jit_recompile_commit()` 原子发布新的 `bpf_func`，见:
   - x86 `5515-5517`
   - arm64 `2926-2927`

6. `bpf_prog_regenerate_trampolines(prog, old_prog_func)` 处理 freplace / fentry / fexit / target trampoline retarget，见:
   - `vendor/linux-framework/kernel/bpf/jit_directives.c:503-504`
   - `vendor/linux-framework/kernel/bpf/trampoline.c:905-965`

7. `synchronize_rcu()` 后释放旧 image/header/private stack，见 `jit_directives.c:516-546`

### 3.4 tailcall prog_array / trampoline / repoke

#### tailcall prog_array

对于“别的地方把本 prog 当 tailcall callee”的情况，**不需要替换 prog_array entry**，因为:

- `prog_array` 里存的是同一个 `struct bpf_prog *`
- 路径 3 不换 prog 对象，只换 `prog->bpf_func`

因此外部 tailcall callee identity 不变。

#### 程序内的 pseudo func / pseudo call

如果 prog 自己有 subprog，重 JIT 时会把 `prog->insnsi` 中的 pseudo func / pseudo call 临时重定向到 staged subprog image，见 `jit_directives.c:364-426`。

#### arch tailcall poke

tailcall text-poke 基础设施本身在 arch JIT:

- x86 `bpf_arch_poke_desc_update()`: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5645-5690`

但 recompile 路径本身不需要“外部 repoke 某个新 prog 对象”，因为 live object identity 没变。

#### trampoline retarget

`bpf_prog_regenerate_trampolines()` 会:

- 对 attached ext 做 `bpf_trampoline_retarget_extension()`，见 `trampoline.c:941-943`
- 对 target prog 做 `bpf_trampoline_retarget_target()`，见 `947-948`
- 对普通 attached prog 重建 trampoline，见 `949-950`

`bpf_trampoline_retarget_extension()` 本身也是 `text_poke JUMP->JUMP`，见 `vendor/linux-framework/kernel/bpf/trampoline.c:835-848`。

### 3.5 这个路径为什么接近理想

因为 fast path 最终还是:

- 同一个 `struct bpf_prog`
- 同一个 attach/link/map/tailcall/trampoline 关系
- 只是 `prog->bpf_func` 指向了新的 native image

而 `bpf_prog_run()` 最终就是把 `prog->insnsi` 和 `prog->bpf_func` 交给 dispatcher，见:

- `vendor/linux-framework/include/linux/filter.h:700-724`
- `vendor/linux-framework/include/linux/bpf.h:1835-1843`

因此路径 3 具备:

- **零运行时开销**
- **零 attach 变化**
- **极高透明性**

### 3.6 当前路径 3 的限制

1. 只在支持的 arch 上可用  
   当前树里:
   - x86 `bpf_jit_supports_recompile() = true`，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5761-5764`
   - arm64 `= true`，见 `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:3867-3870`
   - generic weak default `false`，见 `vendor/linux-framework/kernel/bpf/core.c:3232-3235`

2. 只接受 JITed prog，见 `jit_directives.c:637-642`

3. 当前 POC 不支持 blinded prog，见 `652-657`

4. 当前明确不支持 live `struct_ops`，见 `644-649`  
   原因判定在 `jit_recompile_has_trampoline_dependency()`，见 `vendor/linux-framework/kernel/bpf/jit_directives.c:284-290`

### 3.7 能否把路径 3 扩展到 bytecode-level rewrite?

**可以复用 commit/swap 框架，但不能直接拿它当“现成的 bytecode rewrite 方案”。**

要分两层看:

#### 机械层面: 可以

因为当前 re-JIT 已经:

- snapshot 了 `prog->insnsi`，见 `jit_directives.c:102-107`
- rollback 时能拷回 `prog->insnsi`，见 `127-148`

说明“同一 prog 对象上改当前指令流，再重 JIT，再失败回滚”这条机械路径是存在的。

#### 语义层面: 直接做不够

因为 `prog->insnsi` 不是原始 eBPF load 输入，而是**当前 verifier/fixup/子程序拆分后的 xlated 指令流**:

- 用户 load 进来后先复制到 `prog->insns`/`prog->insnsi`，见 `vendor/linux-framework/kernel/bpf/syscall.c:3017-3023`
- verifier 会通过 `bpf_patch_insn_data()` / `bpf_patch_insn_single()` 原地改它，见:
  - `vendor/linux-framework/kernel/bpf/verifier.c:22012-22041`
  - `vendor/linux-framework/kernel/bpf/core.c:460-518`
- 最后还会把 main prog 的 interpreter insns 改成“适合 dump”的形式，见 `vendor/linux-framework/kernel/bpf/verifier.c:23002-23018`

所以:

- 直接 patch 当前 `prog->insnsi` 可以做一些“后端/本地 IR 风格”的 rewrite
- 但它**不是**“对原始 bytecode 做 patch 再重验证”

### 3.8 路径 3 的判定

- 优点: 已经具备 strict 零开销/零 attach/高透明的关键骨架
- 缺点: 现在只做 native-level re-JIT；缺原始字节码；有 arch/blinding/struct_ops 限制
- 结论: **这是最关键的现有基础设施，也是路径 4 的正确底座**

---

## 4. 路径 4: 新 syscall `BPF_PROG_REJIT`

目标定义:

1. 读取 prog 的原始/当前 bytecode
2. 应用 userspace patch
3. 重新 verify
4. 重新 JIT
5. 原子替换 JIT image
6. 所有 link/attach/map/tailcall/trampoline 引用继续工作

### 4.1 与路径 3 的本质区别

- 路径 3: **native-level / JIT-level** rewrite，当前已存在
- 路径 4: **bytecode-level rewrite + re-verify + same-prog image swap**

### 4.2 当前内核里缺什么

#### 缺口 A: 原始字节码没有被保存

`struct bpf_prog` 里有:

- `prog->bpf_func`
- `prog->insnsi`
- `prog->orig_prog`

但这里的 `orig_prog` 不是 eBPF 原始字节码快照；它是 classic socket filter 的原始 `sock_fprog_kern`:

- 字段定义: `vendor/linux-framework/include/linux/bpf.h:1835-1843`
- classic filter 保存原始程序: `vendor/linux-framework/net/core/filter.c:1158-1178`
- eBPF load 路径显式 `prog->orig_prog = NULL`，见 `vendor/linux-framework/kernel/bpf/syscall.c:3040`

所以对 eBPF 来说，当前内核**没有保存原始 load 输入**

#### 缺口 B: `prog->insnsi` 已经被 verifier/xlator 改写

见上一节 `bpf_patch_insn_data()` / `bpf_patch_insn_single()` 与 `verifier.c:23002-23018`。

#### 缺口 C: dump 出来的 xlated insns 不是可重提交的原始程序

`BPF_OBJ_GET_INFO_BY_FD` 导出 `xlated_prog_insns` 时，会先跑 `bpf_insn_prepare_dump()`:

- `vendor/linux-framework/kernel/bpf/syscall.c:4903-4958`
- `vendor/linux-framework/kernel/bpf/syscall.c:5066-5079`

它只做“清洗/脱敏”:

- 把 tail call opcode 还原成 helper call 形式
- 把 `BPF_CALL_ARGS` 还原成普通 call
- 隐藏 helper imm
- 把 `PROBE_MEM` 变回普通 `MEM`
- 把 map 指针 imm 改成 map id / off

这**不是**可逆的“恢复原始 load bytecode”。

#### 缺口 D: license 字符串也没保留

load 时从 userspace 拷入 `license[128]`，只留下:

- `prog->gpl_compatible = license_is_gpl_compatible(license)`

见 `vendor/linux-framework/kernel/bpf/syscall.c:3024-3032`

所以要想重新走 verifier/load 语义，**原始 license string 也得额外保存**。

### 4.3 `BPF_PROG_REJIT` 的推荐设计

#### 4.3.1 新保存的 load-time 元数据

在 `bpf_prog_aux` 增加一组“原始程序镜像”字段:

- `orig_insns`
- `orig_insn_cnt`
- `orig_license`
- `orig_prog_type`
- `orig_expected_attach_type`
- `orig_prog_flags`
- `orig_prog_name`
- `orig_prog_ifindex` / dev-bound 信息
- `orig_attach_prog_id` 或 `orig_attach_btf_obj_id + orig_attach_btf_id`
- `orig_prog_btf_id`
- `orig_func_info`
- `orig_line_info`
- `orig_core_relos` 或至少保留最终 load 所需的 attach/BTF 元信息
- `orig_fd_array_obj_ids` 或“原始 map/BTF object ID 集”

V1 不必保存 ELF；只要保存**足够重建一次语义等价 `BPF_PROG_LOAD`** 的元数据即可。

#### 4.3.2 syscall 语义

建议新命令:

- `BPF_PROG_REJIT`

建议 attr 大致包含:

- `prog_fd`
- `expected_prog_revision`
- `patches` / `patch_cnt`
- 或直接支持 `new_insns` / `new_insn_cnt`
- `flags`
- `log_level` / `log_buf` / `log_size`

推荐 V1 采用“**完整新 bytecode blob**”而不是“patch list only”，因为:

- kernel 端实现更简单
- userspace optimizer/PGO/safety pass 更自由
- 不需要把 patch DSL 固化进 UAPI

如果一定要 patch-list，也建议内核内部先重建完整候选字节码。

#### 4.3.3 内核执行流程

1. `bpf_prog_get(prog_fd)`
2. 锁 `main_aux->jit_recompile_mutex`  
   当前已有同 prog 串行化点，见 `vendor/linux-framework/include/linux/bpf.h:1737`, `vendor/linux-framework/kernel/bpf/jit_directives.c:615-619`
3. 校验 `expected_prog_revision` / tag / generation  
   这个字段需要新增；避免两个 daemon 同时提交
4. 从保存的 `orig_*` 元数据构造 shadow `struct bpf_prog`
5. 对 shadow prog 应用新 bytecode / patch
6. 用现有 verifier 路径重新验证 shadow prog
7. 检查外部 ABI 不变:
   - `prog_type`
   - `expected_attach_type`
   - sleepable
   - BTF function topology
   - attach target
   - map/BTF 集合
   - subprog 布局
8. 把 verifier 产物迁移/覆盖回 live prog 对象及其 `func[]`
9. 复用现有 `bpf_jit_recompile_prog_images()` 做 staged JIT + commit
10. 复用 `bpf_prog_regenerate_trampolines()` + `synchronize_rcu()`
11. 失败时复用当前 rollback snapshot 逻辑

### 4.4 re-verify 能否对已 attach 的 prog 做?

**当前内核没有现成接口。**

但从机制上看，推荐做法不是“对 live prog 原地直接 verifier mutate”，而是:

- 在 shadow prog 上完整 verifier
- 验证通过后，再进入路径 3 的 same-object image swap 提交流程

这种方式的好处是:

- 不让 live prog 暴露在半验证状态
- 与当前 rollback model 更一致

### 4.5 `prog->insnsi` 是原始还是 xlated?

对 eBPF 来说，**它是当前 xlated / verifier-fixed 的指令流，不是原始 load 输入**。

证据:

- 用户 load 时把 insns 复制进 `prog->insns`，见 `syscall.c:3017-3023`
- verifier 通过 patch API 改写它，见 `verifier.c:22012-22041`, `core.c:460-518`
- 最终还会再调整成 dump-friendly 形式，见 `verifier.c:23002-23018`

### 4.6 并发保护

当前同 prog 已有:

- `main_aux->jit_recompile_mutex`，见 `include/linux/bpf.h:1737`
- `bpf_prog_jit_recompile()` 用 `mutex_trylock()`，见 `jit_directives.c:615-619`

所以 `BPF_PROG_REJIT` 最自然的做法是:

- 复用这把 mutex 做串行化
- 另增 `prog_rewrite_revision` / `expected_prog_revision` 做 CAS 语义

### 4.7 path 4 的 V1 约束建议

如果追求低风险，V1 应限制为“**外部 ABI 不变的同对象重验证**”:

- map/BTF 集不变
- `prog_type` / `expected_attach_type` 不变
- sleepable / packet-data / might_sleep 等语义位不变
- BTF func_info count / type_id 不变
- subprog count / order 不变

这已经足以覆盖:

- peephole optimization
- 安全加固
- PGO code layout / instruction selection
- 恶意 prog no-op 化

不需要一开始支持“任意改结构”的 full program replacement。

### 4.8 路径 4 的判定

- 优点: 唯一严格命中“完全透明 + 零运行时开销 + 零 attach 变化”的终局方案
- 缺点: 需要新增内核接口与 load-time metadata 保留
- 结论: **推荐最终方案**

---

## 5. 非 `bpf_link` 的 legacy attach

这里单独分析题目指定的几类。

### 5.1 总表

| legacy attach | 当前 attach 表示 | 路径 1 `link_update` | 路径 2 `freplace` | 路径 3 image swap | 路径 4 `PROG_REJIT` | 备注 |
|---|---|---|---|---|---|---|
| TC `cls_bpf` via netlink | `struct cls_bpf_prog->filter` | 否 | 否 | 是 | 是 | 现有还有 hook-specific netlink replace，但不是同对象透明替换 |
| socket filter `SO_ATTACH_BPF` | `sk->sk_filter->prog` | 否 | 否 | 是 | 是 | 发现与重拿 socket fd 很难；`SO_GET_FILTER` / sock_diag 对 eBPF 基本无帮助 |
| cgroup v1 `BPF_PROG_ATTACH` | cgroup prog list / effective array | 否 | 否 | 是 | 是 | 现有就支持 `BPF_F_REPLACE`，但仍是换新 prog 对象 |
| raw tracepoint 旧 API | 现在实际会创建 `RAW_TRACEPOINT` link | 否 | 否 | 是 | 是 | `BPF_RAW_TRACEPOINT_OPEN` 已经内部走 link，但该 link type 无 `update_prog` |
| legacy XDP（额外，和场景 A 直接相关） | netdev XDP slot | 否 | 否 | 是 | 是 | netlink 已支持 `XDP_FLAGS_REPLACE`，但仍是换新 prog 对象 |
| perf-event kprobe/tracepoint attach（额外，和场景 B 直接相关） | `event->prog` / tp `prog_array` | 否 | 否 | 是 | 是 | 无通用 `BPF_PROG_QUERY` 覆盖这一类 |

### 5.2 TC `cls_bpf`

attach / fast path:

- 运行时直接跑 `prog->filter`，见 `vendor/linux-framework/net/sched/cls_bpf.c:81-120`
- 从 eBPF fd 装载时把 `prog->filter = fp`，见 `374-404`

旧对象替换路径:

- `cls_bpf_change()` 加载新 prog 后 `list_replace_rcu(&oldprog->link, &prog->link)`，见 `vendor/linux-framework/net/sched/cls_bpf.c:512-519`

这说明:

- TC 自己有 hook-specific replace
- 但它是**新 `cls_bpf_prog` / 新 `struct bpf_prog` 替换旧对象**
- 所以不是“完全透明”

daemon 发现 TC eBPF 可通过 netlink dump:

- `cls_bpf_dump_ebpf_info()` 会导出 `TCA_BPF_ID = prog->filter->aux->id`，见 `vendor/linux-framework/net/sched/cls_bpf.c:556-575`

### 5.3 socket filter `SO_ATTACH_BPF`

attach / fast path:

- `SO_ATTACH_BPF` 进入 `sk_attach_bpf()`，见 `vendor/linux-framework/net/core/sock.c:1471-1481`
- `sk_attach_bpf()` 最终走 `__sk_attach_prog()`，见 `vendor/linux-framework/net/core/filter.c:1599-1614`
- `__sk_attach_prog()` 直接 `rcu_assign_pointer(sk->sk_filter, fp)`，其中 `fp->prog = prog`，见 `1480-1503`
- 运行时 `sk_filter_trim_cap()` 直接取 `sk->sk_filter->prog` 执行，见 `vendor/linux-framework/net/core/filter.c:134-175`

这意味着:

- 如果 daemon 手里**已经有 socket fd**，socket filter 本身其实也支持原位“换 socket 当前 prog”
- 但这不是 generic BPF replace API，而是 socket 层 attach API

发现难点:

- `SO_GET_FILTER` / `sock_diag_put_filterinfo()` 只返回 `orig_prog`
- eBPF `SO_ATTACH_BPF` 路径不会保存 `orig_prog`，见 `vendor/linux-framework/net/core/filter.c:1451-1456`, `1401-1406`
- 因此 `sock_diag_put_filterinfo()` 对 eBPF 附加的 socket filter 基本拿不到程序，见 `vendor/linux-framework/net/core/sock_diag.c:76-112`

结论:

- 路径 3/4 在技术上可行
- 但**“发现 live socket filter + 重新拿到 socket fd”是最大的系统问题**

### 5.4 cgroup v1 `BPF_PROG_ATTACH`

旧 API 本身就有 replace:

- `cgroup_bpf_prog_attach()` 在 `BPF_F_ALLOW_MULTI | BPF_F_REPLACE` 时抓 `replace_bpf_fd`，见 `vendor/linux-framework/kernel/bpf/cgroup.c:1325-1352`
- 真正 attach/replace 在 `__cgroup_bpf_attach()`，见 `785-924`

它和 link 版一样:

- 更新 cgroup prog list
- 更新 effective prog arrays
- 无需 detach+reattach

但它仍然是**换新 prog 对象**，所以不满足“完全透明”。

### 5.5 raw tracepoint 旧 API

`BPF_RAW_TRACEPOINT_OPEN` 今天已经不是“纯 linkless attach”了:

- `bpf_raw_tracepoint_open()` 直接 `bpf_raw_tp_link_attach(...)`，见 `vendor/linux-framework/kernel/bpf/syscall.c:4297-4316`
- `bpf_raw_tp_link_attach()` 内部创建 `BPF_LINK_TYPE_RAW_TRACEPOINT` link，见 `4250-4295`

但问题在于:

- `RAW_TRACEPOINT` link ops 没有 `update_prog`，见 `3797-3856`

所以:

- 它虽然“内部是 link”
- 但**路径 1 仍然不能更新**

### 5.6 legacy XDP（额外但很重要）

这是 Cilium 场景必须看的。

libbpf 旧接口:

- `bpf_xdp_attach()` 走 rtnetlink `RTM_SETLINK + IFLA_XDP_FD`，见 `vendor/libbpf/src/netlink.c:286-337`

kernel 侧:

- `RTM_GETLINK` dump 时会返回 `IFLA_XDP_*_PROG_ID` 和 `IFLA_XDP_PROG_ID`，见 `vendor/linux-framework/net/core/rtnetlink.c:1748-1774`
- `RTM_SETLINK` 时支持 `XDP_FLAGS_REPLACE + IFLA_XDP_EXPECTED_FD`，见 `3353-3395`
- 最终走 `dev_change_xdp_fd(dev, ..., fd, expected_fd, flags)`，见 `vendor/linux-framework/net/core/dev.c:10717-10755`

这说明:

- legacy XDP 自己也支持“replace old prog with new prog”
- 但本质仍然是**换新 prog 对象**

### 5.7 perf-event kprobe/tracepoint attach（额外但和场景 B 强相关）

旧 perf attach 路径:

- `perf_event_set_bpf_prog()` / `perf_event_attach_bpf_prog()`，见:
  - `vendor/linux-framework/kernel/events/core.c:11621-11680`
  - `vendor/linux-framework/kernel/trace/bpf_trace.c:1920-1961`

数据结构:

- `event->prog = prog`
- tracepoint side `prog_array` 也会更新

所以:

- 路径 3/4 对这一类很自然
- 但路径 1 没有通用 link_update 覆盖 perf-event attach

---

## 6. `BPF_PROG_GET_ORIGINAL` 应怎么做

### 6.1 回答题目里的直接问题

#### `struct bpf_prog` 中 `insnsi` 是什么?

对 eBPF 来说是**当前 xlated / verifier-fixed 的指令流**，不是原始 load 输入。见:

- `vendor/linux-framework/kernel/bpf/syscall.c:3017-3023`
- `vendor/linux-framework/kernel/bpf/verifier.c:22012-22041`
- `vendor/linux-framework/kernel/bpf/verifier.c:23002-23018`

#### verifier + fixup 是 in-place 修改吗?

是。  
`bpf_patch_insn_single()` 可能:

- 原地 `memcpy()` 改单条
- 或 `bpf_prog_realloc()` 扩容后 `memmove()` / `memcpy()` 改 `prog->insnsi`

见 `vendor/linux-framework/kernel/bpf/core.c:460-518`。

#### `bpf_insn_prepare_dump()` 做了什么?

它是**导出前清洗**，不是“恢复原始字节码”:

- tailcall opcode -> helper call
- `CALL_ARGS` -> `CALL`
- 去掉 raw helper imm
- `PROBE_MEM` -> `MEM`
- map pointer imm -> map id / off

见 `vendor/linux-framework/kernel/bpf/syscall.c:4903-4958`。

#### 清洗后能否重新提交?

**不能认为可靠可重提交。**

原因:

- 不是可逆变换
- map pointer / helper / pseudo-call / verifier patch 信息都丢失了原始 load 语义

### 6.2 需要返回什么信息

建议 `BPF_PROG_GET_ORIGINAL` 返回两层信息:

#### A. 原始 load 输入

- `orig_insns`
- `orig_insn_cnt`
- `license`
- `prog_type`
- `expected_attach_type`
- `prog_flags`
- `prog_name`
- `prog_ifindex`
- `attach_prog_id`
- `attach_btf_obj_id`
- `attach_btf_id`
- `prog_btf_id`
- `func_info`
- `line_info`
- `core_relos` 或必要的 CO-RE 结果元信息

#### B. 当前 live 绑定信息

这部分很多已经可从现有 `BPF_OBJ_GET_INFO_BY_FD` 得到:

- `map_ids`，见 `vendor/linux-framework/kernel/bpf/syscall.c:5025-5040`
- `attach_btf_id` / `attach_btf_obj_id`，见 `5199-5202`
- `func_info` / `line_info`，见 `5204-5224`
- `prog_tags` 等

### 6.3 如果在 load 时额外保存，需要多少改动?

只做“保存原始 load 输入 + 导出查询”这一部分，改动量不大，量级大概:

- **约 300-600 LOC kernel 改动**

涉及:

- `bpf_prog_aux` 加字段
- `BPF_PROG_LOAD` 时复制/持有
- prog free 路径释放
- 新 info/query 命令

真正大的工作量在 `BPF_PROG_REJIT` 的 shadow verify + transplant + commit。

---

## 7. map 复用

### 7.1 路径 1 / 2 为什么必须考虑 map 复用

因为这两条路都要**加载一个新的 prog 对象**。

内核 `BPF_PROG_LOAD` 已支持:

- `fd_array`
- `fd_array_cnt`

见 `vendor/linux-framework/include/uapi/linux/bpf.h:1671-1724`。  
verifier 会立刻扫描 `fd_array` 并把 map/BTF 记入 used set，见:

- `vendor/linux-framework/kernel/bpf/verifier.c:25421-25483`
- `vendor/linux-framework/kernel/bpf/verifier.c:21692-21725`

libbpf 侧:

- `struct bpf_prog_load_opts` 有 `fd_array` / `fd_array_cnt`，见 `vendor/libbpf/src/bpf.h:71-118`
- `bpf_map__reuse_fd()` 会把对象内 map fd 替换成现有 fd，并校验兼容性，见:
  - `vendor/libbpf/src/libbpf.c:4979-5030`
  - `vendor/libbpf/src/libbpf.c:5166-5198`

### 7.2 全局变量 `.data/.rodata/.bss` 怎么办

libbpf 把它们当特殊内部 map 处理:

- 说明见 `vendor/libbpf/src/libbpf.h:1123-1130`
- 初始填充见 `vendor/libbpf/src/libbpf.c:5237-5255`

因此 daemon 如果走路径 1/2 加载替换 prog:

- 不能只复用“业务 map”
- 还要处理 `.data/.rodata/.bss` 这些 data section maps
- `rodata` 还可能被冻结

### 7.3 路径 3 / 4 为什么不需要 map 复用

因为它们保持同一个 `struct bpf_prog`:

- `used_maps`
- map refcnt
- data section maps
- map 内状态

都原封不动

这也是路径 3/4 对“透明变换”最有价值的地方。

---

## 8. 端到端场景

## 8.1 场景 A: Cilium XDP 程序优化

### A1. daemon 怎么发现?

分两种现实路径:

#### 情况 1: Cilium 用 XDP link

daemon 可用:

- `BPF_LINK_GET_NEXT_ID` / `BPF_LINK_GET_FD_BY_ID` / `BPF_OBJ_GET_INFO_BY_FD`
- link info 里会有:
  - `type`
  - `prog_id`
  - `xdp.ifindex`

证据:

- libbpf wrappers: `vendor/libbpf/src/bpf.c:1078-1225`
- kernel `BPF_LINK_GET_NEXT_ID`: `vendor/linux-framework/kernel/bpf/syscall.c:4731-4755`, `6249-6310`
- link info 通用 `prog_id`: `vendor/linux-framework/kernel/bpf/syscall.c:5375-5396`
- XDP `ifindex`: `vendor/linux-framework/net/core/dev.c:10584-10597`

#### 情况 2: Cilium 用 legacy XDP netlink

daemon 可通过 `RTM_GETLINK` 读取:

- `IFLA_XDP_ATTACHED`
- `IFLA_XDP_PROG_ID`
- `IFLA_XDP_DRV_PROG_ID`
- `IFLA_XDP_SKB_PROG_ID`
- `IFLA_XDP_HW_PROG_ID`

见 `vendor/linux-framework/net/core/rtnetlink.c:1748-1774`。

### A2. daemon 怎么拿 bytecode?

当前已有:

- `BPF_OBJ_GET_INFO_BY_FD` -> `xlated_prog_insns`

但这是 sanitized xlated dump，不是原始 load bytecode，见:

- `vendor/linux-framework/kernel/bpf/syscall.c:4992-5108`
- `vendor/linux-framework/kernel/bpf/syscall.c:4903-4958`

所以:

- 如果只做 native/JIT rewrite，路径 3 足够
- 如果要做 bytecode-level optimization/PGO，需要新增 `BPF_PROG_GET_ORIGINAL`

### A3. 四条路径分别怎么做

#### 路径 1

前提:

- Cilium 用的是 XDP link
- daemon 用旧 map fd / data-map fd 加载一个新 XDP prog

然后:

- `BPF_LINK_UPDATE(link_fd, new_prog_fd, old_prog_fd)`
- kernel 走 `bpf_xdp_link_update()`，见 `vendor/linux-framework/net/core/dev.c:10599-10647`

结果:

- 运行时无额外开销
- 但 Cilium 原来的 `prog_fd` 仍指向旧对象
- **不是完全透明**

#### 路径 2

前提:

- 原 XDP prog 有 BTF
- 主函数是 global function
- EXT 函数签名严格匹配

然后:

- 用 `BPF_PROG_TYPE_EXT` 替换 main function

结果:

- steady-state 只有一个入口 `JMP`
- 不走通用 trampoline
- 但严格说不是零开销
- 也不是完全透明

#### 路径 3

前提:

- arch 支持 `BPF_PROG_JIT_RECOMPILE`
- prog 已 JIT，且不是 blinded/live struct_ops

然后:

- daemon 以当前 prog 为对象做 native-level rewrite policy
- 调 `BPF_PROG_JIT_RECOMPILE`

结果:

- 同一 `prog_id`
- 同一 attach
- 同一 maps
- 严格零运行时开销

#### 路径 4

前提:

- 内核新增 `BPF_PROG_GET_ORIGINAL` + `BPF_PROG_REJIT`

然后:

- daemon 取原始 bytecode
- 做优化/PGO/safety rewrite
- 内核 shadow verify + re-JIT + image swap

结果:

- 这是题目意义上的最佳答案

### A4. Cilium 不知情的情况下能正常工作吗?

- 路径 1: 大概率业务可继续工作，但如果 Cilium 观察自己持有的原 `prog_fd` / stats，它会看到旧 prog，不是完全透明
- 路径 2: Cilium 看到的原 prog 对象仍在，但逻辑被入口 `JMP` 劫持；若它观测 stats/links，也不是完全透明
- 路径 3/4: **是**。这两条路保留了相同 `struct bpf_prog` 身份

### A5. Cilium reload 时 daemon 怎么应对?

无论走哪条路，只要 Cilium 卸载旧 prog、装载新 prog，对 daemon 来说都是**新 live 实例**。

daemon 应监视:

- `BPF_LINK_GET_NEXT_ID` / link info
- `RTM_GETLINK` 的 XDP prog id
- `BPF_PROG_GET_NEXT_ID` 新出现的 prog id

一旦发现 XDP prog id 变化，就重新应用策略。  
路径 3/4 只能保证“同一个 prog 对象在其存活期内原地替换透明”。

## 8.2 场景 B: 恶意 kprobe 程序阻断

### B1. daemon 怎么发现?

先全局枚举 prog:

- `BPF_PROG_GET_NEXT_ID` -> `BPF_PROG_GET_FD_BY_ID` -> `BPF_OBJ_GET_INFO_BY_FD`

若 prog type 是 `BPF_PROG_TYPE_KPROBE`:

- 如果是 `kprobe_multi` link，可继续从 `BPF_LINK_GET_NEXT_ID` 中找到 link info
- 如果是 perf-event attach，则 link 路径通常是 `BPF_LINK_TYPE_PERF_EVENT` 或更老的 perf attach；这类没有统一的 `BPF_PROG_QUERY`

相关源码:

- prog/link 枚举: `vendor/linux-framework/kernel/bpf/syscall.c:4731-4755`, `6249-6310`
- `PERF_EVENT` link 无 update: `vendor/linux-framework/kernel/bpf/syscall.c:4165-4169`
- perf-event 持有 `event->prog`: `vendor/linux-framework/kernel/trace/bpf_trace.c:1920-1961`, `vendor/linux-framework/kernel/events/core.c:11621-11680`

### B2. daemon 怎么替换为 no-op?

#### 路径 1

对常见恶意 kprobe attach:

- `PERF_EVENT` link 无 `update_prog`
- `KPROBE_MULTI` link 无 `update_prog`

所以**基本做不到**

#### 路径 2

freplace 不能拿来替换“一个 live kprobe hook 的 attach 关系”。  
它只能替换另一个 BPF prog 的 BTF/global function。

所以**不适用**

#### 路径 3

最自然:

- 保持同一个 kprobe prog 对象
- native-level rewrite 成 `R0=0; EXIT`
- 走 `BPF_PROG_JIT_RECOMPILE`

attach 完全不变，恶意逻辑立即失效。

#### 路径 4

同理:

- 用原始 bytecode 生成 no-op 版本
- re-verify
- 原地 swap image

### B3. 四条路径能做到吗?

- 路径 1: 对常见 kprobe attach **基本不行**
- 路径 2: **不行**
- 路径 3: **行**
- 路径 4: **行，且更通用**

---

## 9. 四条路径综合对比

| 维度 | 路径 1 `link_update` | 路径 2 `freplace` | 路径 3 image swap | 路径 4 `BPF_PROG_REJIT` |
|---|---|---|---|---|
| 运行时开销 | 对支持的 link type 为 0 | **非 0**，多一个入口 `JMP` | 0 | 0 |
| attach 开销 | 无 detach+reattach，但只对少数 link type | 需要新建 ext/tracing attach | 0 | 0 |
| 透明性 | 中等，只对 hook 透明，不对 prog identity 透明 | 低到中，target 被入口跳转劫持 | 高 | 最高 |
| 覆盖面 | 中等偏窄 | 窄，依赖 BTF/global/JIT | 宽，但当前只支持 native/JIT rewrite，且有 arch/struct_ops/blinding 限制 | 最宽，取决于实现约束 |
| 需要新内核接口 | 否 | 否 | 已有 `BPF_PROG_JIT_RECOMPILE` | **是** |
| 实现复杂度 | 低到中 | 中 | 中到高，但框架已在 | 高 |
| 可回滚 | 能 update 回旧 prog | detach 可恢复 | 已有 snapshot/restore | 可直接建立在 snapshot/restore 上 |
| map 处理 | 要复用旧 map fd / data maps | 要复用旧 map fd / data maps | 不需要 | 不需要 |
| 是否严格满足题目目标 | 否 | 否 | 只差“还没有 bytecode-level rewrite” | **是** |

---

## 10. 推荐方案

## 10.1 最优方案

**最优终局方案: 路径 4 `BPF_PROG_REJIT`，并复用路径 3 的 staged JIT image swap 基础设施。**

推荐架构:

1. load-time 保留原始程序镜像
2. 新增 `BPF_PROG_GET_ORIGINAL`
3. 新增 `BPF_PROG_REJIT`
4. `BPF_PROG_REJIT` 的 commit 阶段直接复用:
   - `jit_recompile_mutex`
   - staged JIT fields
   - `bpf_jit_recompile_commit()`
   - `bpf_prog_regenerate_trampolines()`
   - rollback snapshot/restore

## 10.2 是否需要组合多条路径

需要，但要明确主次:

- **主路径**: 路径 4  
  适合所有追求 strict 透明/zero-overhead 的场景

- **短期可落地路径**: 路径 3  
  对 native/JIT-level rewrite 立即有价值

- **fallback**: 路径 1  
  当 hook 恰好支持 `update_prog` 且应用不关心 prog identity 时可用

- **niche fallback**: 路径 2  
  仅适合 BTF/global/JIT 条件都满足，且能接受“一个入口 JMP”的场景

换句话说:

- **link-attached 程序**: 若要 strict 透明，仍应优先路径 3/4，而不是路径 1
- **legacy attach**: 基本更应依赖路径 3/4

## 10.3 内核需要改什么

### 必须新增

1. `BPF_PROG_GET_ORIGINAL`
2. `BPF_PROG_REJIT`
3. `bpf_prog_aux` 保存原始 load 输入
4. per-prog rewrite revision / CAS 语义

### 可以复用

1. `BPF_PROG_JIT_RECOMPILE` 的 staged image / commit / rollback
2. arch `bpf_jit_recompile_commit()`
3. `bpf_prog_regenerate_trampolines()`
4. 现有 prog/link 枚举与 info 查询
5. 现有 map get-by-id / BTF get-by-id

### 建议的 V1 范围

先做:

- x86/arm64
- 非 blinded
- 非 live struct_ops
- 外部 ABI 不变的 rewrite

这样能最快得到一个真正可用的“透明 live rewrite”版本。

## 10.4 预估改动量

粗略估算，不含 selftests / tools:

- 原始镜像保存 + `BPF_PROG_GET_ORIGINAL`: **300-600 LOC**
- `BPF_PROG_REJIT` syscall + shadow verify + transplant + reuse 路径 3 commit: **1500-2500 LOC**
- revision/CAS + 细节清理: **100-300 LOC**
- 若再补 live `struct_ops` 支持: **额外 300-800 LOC**

所以一个现实的 V1 量级大概是:

- **约 2k-3.5k LOC kernel 改动**

## 10.5 最终结论

### 严格按题目目标排序

1. **路径 4 `BPF_PROG_REJIT`**: 终局正确方案
2. **路径 3 current image swap**: 最重要的现有基础设施，也是短期最强方案
3. **路径 1 `link_update`**: 只适合“hook 透明”替换，不是“prog 透明”
4. **路径 2 `freplace`**: 很巧妙，但严格来说不是零开销，也不是完全透明

### 一句话建议

**把现有 `BPF_PROG_JIT_RECOMPILE` 当作 commit/swap backend；补 `BPF_PROG_GET_ORIGINAL` 和 `BPF_PROG_REJIT`，不要把 `link_update` 或 `freplace` 当总方案。**
