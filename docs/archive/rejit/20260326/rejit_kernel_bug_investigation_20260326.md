# REJIT 内核 bug 调研报告

日期：2026-03-26

## 范围

本报告只基于代码阅读，没有修改内核代码，也没有运行新的 VM 测试。

重点阅读的文件：

- `vendor/linux-framework/kernel/bpf/syscall.c`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/kernel/bpf/trampoline.c`
- `vendor/linux-framework/kernel/bpf/btf.c`
- `vendor/linux-framework/kernel/bpf/core.c`
- `vendor/linux-framework/kernel/bpf/arraymap.c`
- `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c`
- `vendor/linux-framework/include/linux/bpf.h`
- `vendor/linux-framework/include/linux/bpf_verifier.h`
- `vendor/linux-framework/include/linux/filter.h`

## 结论摘要

### 已确认的内核问题

1. `BPF_PROG_TYPE_EXT` attach 后不能 REJIT，不只是因为 `dst_prog` 丢失。
   - 第一层根因：attach 成功后，`prog->aux->dst_prog` / `dst_trampoline` 被清空，REJIT verifier 无法重建 freplace 上下文。
   - 第二层根因：即使把 `dst_prog` 补回来，当前 post-swap refresh 路径也不支持 `BPF_TRAMP_REPLACE`，不能正确把旧的 ext `bpf_func` 补丁切到新的 ext `bpf_func`。

2. `target` BPF prog 在已有 inbound BPF trampoline 的情况下做 REJIT，target-side refresh 缺失。
   - `tr->func.addr` / `tr->ip` 只在 trampoline 首次创建时设置一次；
   - target prog 的 REJIT 路径不会更新这些字段；
   - 结果是 freplace/fentry/fexit attached 到另一个 BPF prog 的 target-side attach 点在 target REJIT 后会失效，或者至少不再跟随新 JIT 地址。

3. `BPF_PROG_REJIT` 的失败语义不是事务性的。
   - 正常成功路径没有明显执行期 race；
   - 但一旦 trampoline refresh 在 swap 之后失败，syscall 会返回错误，同时保留已经发布的新程序，不能保证 “error == 没生效”。

### 未确认的 bug

1. 同一个 prog 的并发 REJIT：未发现问题，`rejit_mutex` 已串行化。
2. map 引用计数：未发现问题，`used_maps` 在 swap 时整体转移，旧引用随旧 prog 释放。
3. tail call poke：未发现 correctness bug，现有逻辑已经显式处理 caller-side / target-side 两个方向。
4. struct_ops refresh：未发现明显 bug，已有专门 refresh 和 rollback。

## 1. EXT（freplace）attach 后不能 REJIT

### 1.1 根因链路

#### A. attach 前 `dst_prog` 存在哪里

`BPF_PROG_LOAD` 时，attach target prog fd 解析出的目标程序保存在 `prog->aux->dst_prog`：

- `vendor/linux-framework/kernel/bpf/syscall.c:2957-2961`
- `vendor/linux-framework/kernel/bpf/syscall.c:3011-3016`

load-time verifier 完成 attach target 检查后，又把 load 阶段创建好的 trampoline 保存在 `prog->aux->dst_trampoline`：

- `vendor/linux-framework/kernel/bpf/verifier.c:25761-25818`

也就是说，attach 前 freplace 的 target 上下文在 prog 自身上：

- `prog->aux->dst_prog`
- `prog->aux->dst_trampoline`

#### B. attach 后为什么消失

attach 成功后，target 引用被“搬”进 tracing link：

- `struct bpf_tracing_link` 持有 `trampoline` 和 `tgt_prog`
  - `vendor/linux-framework/include/linux/bpf.h:1936-1940`
- attach 成功时赋值：
  - `vendor/linux-framework/kernel/bpf/syscall.c:4549-4550`
- link release 时释放 target prog / trampoline 引用：
  - `vendor/linux-framework/kernel/bpf/syscall.c:4301-4314`

随后 `bpf_tracing_prog_attach()` 会把 prog 上的这两个字段清空：

- `vendor/linux-framework/kernel/bpf/syscall.c:4552-4565`

这段代码的设计意图很明确：不要继续让 `prog->aux` 持有“原始 attach 目标”，否则程序在 detach / reattach 到其他 target 后会继续 pin 住旧 target。

所以答案是：

- attach 前：`dst_prog` 在 `prog->aux->dst_prog`
- attach 后：引用被转移到 `struct bpf_tracing_link::tgt_prog`
- `prog->aux->dst_prog` 被故意置空，不是 accidental overwrite

#### C. 为什么 REJIT verifier 会失败

REJIT 构造 tmp prog 时，只会继承两类 attach 上下文：

1. `attach_btf` / `attach_btf_id`
   - `vendor/linux-framework/kernel/bpf/syscall.c:3666-3671`
2. 仍然存在的 `dst_prog`
   - `vendor/linux-framework/kernel/bpf/syscall.c:3673-3680`

另外，REJIT 已经会把 EXT 自身的 `btf/func_info/func_info_aux` 预先复制到 tmp：

- `vendor/linux-framework/kernel/bpf/syscall.c:3709-3745`

所以这里的根因不是 “EXT 自己的 BTF 丢了”，而是 “target attach 上下文丢了”。

而 `bpf_check_attach_target()` 的核心分支是：

- `tgt_prog != NULL` 时，BPF-to-BPF attach 用 target prog 自己的 BTF
- `tgt_prog == NULL` 时，用 `prog->aux->attach_btf`

代码位置：

- `vendor/linux-framework/kernel/bpf/verifier.c:25346-25355`

对 freplace 来说，target 是另一个 BPF prog，不是 kernel BTF target。load 时通常没有 `attach_btf`，而是靠 `dst_prog` 来拿 target BTF 和 subprog 地址：

- `vendor/linux-framework/kernel/bpf/verifier.c:25366-25425`
- `vendor/linux-framework/kernel/bpf/verifier.c:25578-25583`

因此 attach 后一旦 `dst_prog` 被清空，REJIT verifier 就无法重建 freplace 上下文。

当前代码已经显式承认这一点，并直接拒绝 attached EXT：

- `vendor/linux-framework/kernel/bpf/syscall.c:3177-3183`

#### D. 这不是只影响 EXT，BPF-to-BPF tracing 也有同类问题

当前 guard 只拒绝 attached `BPF_PROG_TYPE_EXT`：

- `vendor/linux-framework/kernel/bpf/syscall.c:3182-3183`

但如果是 attach 到另一个 BPF prog 的 tracing/fentry/fexit，attach 后同样会丢掉 `dst_prog`，而 `attach_btf` 仍然是空的。那样 REJIT 不会被早期拒绝，而是会在 verifier 里以 “没有 attach BTF / target BTF” 的形式失败。

所以：

- “fentry REJIT 能成功” 只对 attach 到 kernel function 的场景成立；
- 对 attach 到 BPF prog 的 fentry，当前实现也不能可靠 REJIT。

### 1.2 为什么 kernel fentry REJIT 能成功

kernel-function fentry 的 load-time attach 上下文保存在 `prog->aux->attach_btf` / `attach_btf_id`，这些字段 attach 后不会被清掉：

- load 时设置：`vendor/linux-framework/kernel/bpf/syscall.c:3013-3014`
- REJIT 时复制到 tmp：`vendor/linux-framework/kernel/bpf/syscall.c:3666-3671`
- verifier 在 `tgt_prog == NULL` 时正是用 `attach_btf` 继续工作：
  - `vendor/linux-framework/kernel/bpf/verifier.c:25350-25355`

所以 kernel fentry 和 freplace 的关键差别是：

- kernel fentry：attach 上下文长期保存在 prog 本体上
- freplace/BPF-to-BPF tracing：attach 上下文主要靠 `dst_prog`，attach 完后被 link 接管并从 prog 本体移除

### 1.3 只补 `dst_prog` 还不够：当前 refresh 路径不支持 REPLACE

即使在 REJIT 时把 freplace 的 `dst_prog` 重建回来，attached EXT 仍然不能直接走现有 refresh 路径。

原因是 `BPF_TRAMP_REPLACE` attach 根本不是 image-backed trampoline rebuild 路径：

- `__bpf_trampoline_link_prog()` 对 `BPF_TRAMP_REPLACE` 直接执行 `bpf_arch_text_poke()`，然后立刻返回：
  - `vendor/linux-framework/kernel/bpf/trampoline.c:788-798`

它不会：

- 增加 `tr->progs_cnt[]`
- 创建 `tr->cur_image`
- 调用 `bpf_trampoline_update()`

但 REJIT 完成后，attached prog 的 refresh 逻辑现在是无差别地遍历 `trampoline_users`，对每个 trampoline 都调用 `bpf_trampoline_update()`：

- `vendor/linux-framework/kernel/bpf/trampoline.c:930-945`

而 `bpf_trampoline_update()` 只理解 image-backed fentry/fexit/fmod_ret 这类 trampoline，它依赖：

- `tr->progs_cnt[]`
- `tr->cur_image`

代码位置：

- `vendor/linux-framework/kernel/bpf/trampoline.c:441-463`
- `vendor/linux-framework/kernel/bpf/trampoline.c:607-623`

因此如果只是“去掉 attached EXT 的拒绝”并补 `dst_prog`，后面 refresh 还是走不通。REPLACE 需要的是：

- 把 target site 上原来跳到 `old_ext_bpf_func` 的补丁改成跳到 `new_ext_bpf_func`

而不是 rebuild trampoline image。

### 1.4 修复方案

#### 方案 A：最小安全修复

先不支持 attached EXT 的 live REJIT，只把错误边界补齐：

1. 保持 attached EXT 仍然返回 `-EOPNOTSUPP`
2. 再补一条对 BPF-to-BPF tracing 的 guard
   - 条件可以是：`prog->type == BPF_PROG_TYPE_TRACING && !prog->aux->attach_btf && !prog->aux->dst_prog`
   - 避免它掉进 verifier 后报误导性的 BTF 错误

优点：

- 风险最低
- 错误语义一致

缺点：

- 不能解决 hotswap freplace 压测暴露的真实需求

#### 方案 B：支持 attached EXT 的 REJIT

要完整支持，至少要同时做两件事。

##### B1. 在 REJIT 时重建 target 上下文，而不是“继承原始 prog 里的 dst_prog”

不能简单从原始 prog 继承 `dst_prog`，因为 attach 之后它已经被故意清掉，而且单个字段也无法正确表达多 link / 多 target 的 live 状态。

可行做法是：

1. 在 `prog->aux->rejit_mutex` 下遍历 `prog->aux->trampoline_users`
   - 该链表本来就用于 attached prog side refresh
   - `vendor/linux-framework/include/linux/bpf.h:1728-1729`
   - `vendor/linux-framework/kernel/bpf/trampoline.c:858-865`

2. 对每个 REPLACE trampoline：
   - 用 `tr->key` 解出 `target prog id + attach_btf_id`
     - `vendor/linux-framework/include/linux/bpf_verifier.h:927-943`
   - 用 `bpf_prog_by_id()` 取回 live `tgt_prog`
     - `vendor/linux-framework/kernel/bpf/syscall.c:5597-5611`

3. 至少把一个 target 填给 `tmp->aux->dst_prog` 供 verifier 使用

4. 如果 attached EXT 存在多个 live target：
   - 短期：直接拒绝，返回 `-EOPNOTSUPP`
   - 长期：用一个 target 跑完整 verifier，再对其余 target 逐个调用 `bpf_check_attach_target()` 做 post-verify compatibility check

##### B2. 专门为 REPLACE 增加 refresh 分支

需要把 `bpf_trampoline_refresh_prog()` 改成“区分 REPLACE 和普通 trampoline”：

- 对普通 fentry/fexit/fmod_ret：继续走 `bpf_trampoline_update()`
- 对 `tr->extension_prog == prog` 的 REPLACE trampoline：
  - 不 rebuild image
  - 直接把 target site 上的 text patch 从 `old_ext_bpf_func` 改成 `new_ext_bpf_func`

也就是说，refresh helper 需要拿到 `old_bpf_func` 和 `new_bpf_func`，而不只是 `prog`。

如果架构支持 `JUMP -> JUMP` 的 `text_poke`，可以直接做；
如果不支持，就需要 `JUMP -> NOP -> JUMP` 的两步更新。

### 1.5 风险评估

#### 风险等级：高

主要风险点：

1. 多 target attach
   - 单个 `dst_prog` 字段不足以描述 attach 后的 live 状态
   - 如果修复只处理“一个 target”，需要明确拒绝 multi-attach

2. refcount
   - REJIT 临时取回的 `tgt_prog` 引用必须在所有失败路径上正确释放

3. rollback
   - attached EXT 的 refresh 一旦支持了，就必须连 rollback 一起支持
   - 否则 swap 后失败会留下一半旧 patch、一半新 patch

## 2. REJIT 成功但行为可能没变；以及 image swap 是否有 race

### 2.1 当前没有“行为真的变了”的检测机制

`bpf_prog_rejit_swap()` 的工作是：

- 交换 digest
- 复制 verified/rewritten BPF insns
- 更新 `prog->len`
- 最后发布新的 `prog->bpf_func`

代码位置：

- `vendor/linux-framework/kernel/bpf/syscall.c:3439-3482`

这里没有任何 old/new compare，因此：

1. 如果新 bytecode 和旧 bytecode 完全一样
   - syscall 仍然可能返回成功
   - 只是 JIT image 地址、load_time 等元数据变了

2. 如果 verifier 之后的 bytecode 变了，但 JIT 出来的 native code 恰好语义等价
   - 也不会被检测
   - kernel 仍然按“新 image 生效”处理

结论：

- 当前没有 no-op detection
- success 只表示 “swap + 后续 refresh 完成”
- success 不表示 “语义一定变化”

### 2.2 这本身不是执行期 correctness bug

正常成功路径上，我没有发现明显执行期 race。

#### A. `bpf_func` 发布顺序是对的

REJIT 侧：

- `smp_store_release(&prog->bpf_func, tmp->bpf_func)`
  - `vendor/linux-framework/kernel/bpf/syscall.c:3480-3482`

执行侧：

- `smp_load_acquire(&prog->bpf_func)`
  - `vendor/linux-framework/include/linux/filter.h:700-707`

也就是说，执行路径看到新的 `bpf_func` 时，也会看到 swap 之前已经写好的 insn / metadata。

#### B. 旧 image 不是立刻 free

swap 之后会先等 RCU grace period，再释放旧 image：

- `vendor/linux-framework/kernel/bpf/syscall.c:3864-3909`

因此正常成功路径上没有明显的 “published new pointer, immediately free old text” 的 UAF 问题。

#### C. tail call poke 的并发也做了专门保护

caller-side poke descriptor 更新：

- `vendor/linux-framework/kernel/bpf/syscall.c:3218-3281`

target-side “旧 target 先撤掉，再指向新 target”：

- `vendor/linux-framework/kernel/bpf/syscall.c:3302-3370`
- `vendor/linux-framework/kernel/bpf/syscall.c:3808-3819`

并且 `map_poke_run()` 会检查 `tailcall_target_stable`：

- `vendor/linux-framework/kernel/bpf/arraymap.c:1107-1153`

所以在 direct tail call 这一块，我没有发现明显 race。

### 2.3 真正的问题：失败路径不是事务性的

当前更严重的问题不是 success-path race，而是 error-path 非事务化。

`bpf_trampoline_refresh_prog()` 会一个个刷新 attached prog 的 trampoline user：

- `vendor/linux-framework/kernel/bpf/trampoline.c:936-950`

如果中途某一个刷新失败，那么前面已经刷新的 user 不会自动回滚。

REJIT 主路径在这种情况下的处理是：

- 先保留已经 swap 进去的新 prog
- 再把 `retain_old_image = true`
- 返回错误，但不 rollback

代码位置：

- `vendor/linux-framework/kernel/bpf/syscall.c:3822-3833`
- `vendor/linux-framework/kernel/bpf/syscall.c:3905-3909`

这意味着当前语义是：

- `ret == 0`：不保证语义一定变化
- `ret < 0`：也不保证系统仍然保持旧状态

这对控制面来说是明显的原子性缺口。

### 2.4 修复方案

#### 方案 A：先补 observability，不改语义

如果只是想知道 “这次 REJIT 是不是 no-op”，可以在 swap 前增加诊断比较：

1. 比较 `prog->len` / `tmp->len`
2. 比较 `prog->digest` / `tmp->digest`
3. 必要时比较 rewritten `insnsi`

然后：

- 记录到 tracepoint / stats / debug log
- 但不影响 syscall 成败

这是低风险 observability 改动。

#### 方案 B：把 refresh 改成 staged/transactional

如果目标是让 `error == 未生效`，就不能在 publish 新 `bpf_func` 之后才边刷新边赌成功。

更稳妥的方式是：

1. swap 前先为所有 dependent object 做 prepare
   - 普通 trampoline：先生成所有新 image
   - struct_ops：先收集所有待 patch callsite
   - tail call poke：现有逻辑已经基本具备 prepare 性质

2. 只有在所有 prepare 都成功后，才 publish 新 `bpf_func`

3. commit 阶段如果仍有步骤失败
   - 必须支持全量 rollback
   - 不能只 rollback struct_ops，而对 trampoline 留 partial state

### 2.5 风险评估

#### 风险等级

- no-op observability：低
- transactional refresh：高

原因：

- trampoline refresh 牵涉 ftrace/direct-call/text-poke，回滚成本高
- 但如果不修，REJIT 的 error 语义就一直不可靠

## 3. 其他 REJIT 内核问题

### 3.1 已确认：target-side BPF trampoline refresh 缺失

这是另一类独立于 “attached EXT verifier 上下文丢失” 的 bug。

#### 根因

当前只维护了“attached prog -> trampoline”的 reverse index：

- `bpf_trampoline_link_prog()` 把 `tu->tr` 加到 `link->link.prog->aux->trampoline_users`
  - `vendor/linux-framework/kernel/bpf/trampoline.c:858-865`

这里的 `link->link.prog` 是 attached program，不是 target prog。

因此 target prog 自己 REJIT 时：

- 看不到有哪些 inbound trampoline 正挂在自己身上
- `bpf_trampoline_refresh_prog(target_prog)` 也不会触到这些 inbound trampoline

而 trampoline 自身又把 target 地址缓存死了：

- `tr->func.addr` 只在首次 `bpf_trampoline_get()` 时初始化一次
  - `vendor/linux-framework/kernel/bpf/trampoline.c:1137-1142`
- `tr->ip` 也是首次 lookup 时按旧 target 地址建好的
  - `vendor/linux-framework/kernel/bpf/trampoline.c:354-360`

更糟的是，direct ftrace 相关逻辑明确依赖 `tr->ip`：

- `vendor/linux-framework/kernel/bpf/trampoline.c:195-248`
- `vendor/linux-framework/kernel/bpf/trampoline.c:275-305`

所以 target prog REJIT 后，如果 target 的 JIT text 地址变了，当前 kernel 不会更新：

- `tr->func.addr`
- `tr->ip`
- `trampoline_ip_table`

#### 影响

##### A. freplace target REJIT

freplace attach 时，内核是在 target site 上直接打 jump patch：

- `vendor/linux-framework/kernel/bpf/trampoline.c:788-798`

target prog REJIT 后：

- 新 JIT image 的 target site 没被重新 patch
- freplace 行为会静默失效

##### B. BPF-to-BPF fentry/fexit/fsession target REJIT

这类 attach 虽然不是 REPLACE，但同样依赖旧的 `tr->func.addr` / `tr->ip`。

所以它们也存在 target-side refresh 缺失的问题，只是修复面更大，因为不仅要更新 call target，还要更新 ftrace/direct-op 的 target IP bookkeeping。

### 3.2 修复方案

#### 方案 A：最小安全修复

先拒绝 target prog REJIT，只要这个 prog 正被 inbound BPF trampoline 使用。

最低配做法：

1. 至少先拒绝 `prog->aux->is_extended == true` 的 prog
   - 这个 bit 就是在 freplace attach 时打上的
   - `vendor/linux-framework/kernel/bpf/trampoline.c:749-764`

2. 更完整一点，可以在 REJIT supported check 里扫描 trampoline table，找出：
   - `key` 的高 32 位等于 `prog->aux->id`
   - 低 32 位不是 kernel-BTF marker
   - trampoline 里确实有 live attached prog

这样可以把 BPF-to-BPF fentry/fexit 也一起挡掉。

#### 方案 B：完整支持 target-side refresh

需要新增 target-side reverse index，或者在 REJIT 时扫描全局 trampoline table，然后对每个 inbound trampoline：

1. 重新按 `(target prog id, attach_btf_id)` 计算新的 target subprog 地址
2. 更新 `tr->func.addr`
3. 更新 `tr->ip`
4. 维护 `trampoline_ip_table` 的 hash 链
5. 分 attach kind 做 refresh：
   - REPLACE：给新的 target site 重打 ext jump patch
   - fentry/fexit/fsession：重新 register/modify trampoline

这已经不是一个小修补，而是 target-side trampoline 生命周期修正。

### 3.3 风险评估

#### 风险等级：很高

原因：

1. 不只是补一个指针
2. 还要更新 trampoline 全局表和 direct ftrace 绑定
3. 出错时还要保证 rollback 和 refcount 都成立

### 3.4 并发安全：多个线程同时 REJIT 同一个 prog

我没有发现同一个 prog 的并发 REJIT bug。

证据：

- `rejit_mutex` 定义：
  - `vendor/linux-framework/include/linux/bpf.h:1728-1729`
- REJIT 主路径先拿这个锁：
  - `vendor/linux-framework/kernel/bpf/syscall.c:3625`
- trampoline link/unlink 改 `trampoline_users` 时也拿同一个锁：
  - `vendor/linux-framework/kernel/bpf/trampoline.c:858-865`
  - `vendor/linux-framework/kernel/bpf/trampoline.c:910-925`

所以“同一 prog 被多个线程同时 REJIT / attach / detach”这类竞争，当前基本被串行化了。

### 3.5 map 引用计数：未发现 bug

`used_maps` 在 swap 时整体从 `tmp` 转给 `prog`：

- `vendor/linux-framework/kernel/bpf/syscall.c:3411-3412`

旧 map refs 随旧 `tmp` 释放：

- `vendor/linux-framework/kernel/bpf/core.c:2861-2883`
- `vendor/linux-framework/kernel/bpf/syscall.c:3908`

另外，tmp 在 free 前还会先从 `poke_progs` 链表里 untrack：

- `vendor/linux-framework/kernel/bpf/syscall.c:3284-3300`
- `vendor/linux-framework/kernel/bpf/syscall.c:3802-3806`

我没有看到明显的 map ref leak / double put 问题。

### 3.6 tail call：未发现 bug

tail call 在 REJIT 里其实做了两层处理：

1. caller-side poke descriptor 更新
   - `vendor/linux-framework/kernel/bpf/syscall.c:3218-3281`
2. 如果被 REJIT 的 prog 自己是 tail call target，则在 swap 前后分别撤掉/恢复 direct jump
   - `vendor/linux-framework/kernel/bpf/syscall.c:3302-3370`
   - `vendor/linux-framework/kernel/bpf/syscall.c:3808-3819`

并且如果新旧 bytecode 的 tail-call layout 变了，会直接拒绝：

- `vendor/linux-framework/kernel/bpf/syscall.c:3235-3239`

所以 tail call 这一块我没有确认出新的 correctness bug。

### 3.7 struct_ops：未发现 bug

REJIT 对 struct_ops 有专门 refresh：

- swap 后调用：
  - `vendor/linux-framework/kernel/bpf/syscall.c:3835-3858`
- 具体实现：
  - `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:1521-1615`

这段逻辑会：

1. 扫描 struct_ops trampoline image 中 direct CALL 的 site
2. 把旧 `bpf_func` 改成新 `bpf_func`
3. patch 失败时尝试回滚已打过的 callsite

所以 struct_ops 至少在代码层面是被单独照顾到了。

## 4. 推荐修复顺序

### 第 1 阶段：先补安全边界

1. target prog 上若存在 inbound BPF trampoline，则直接拒绝 REJIT
2. attached BPF-to-BPF tracing 若 attach 上下文已丢失，也直接拒绝 REJIT

这样可以先消除 silent breakage / 误导性 verifier 错误。

### 第 2 阶段：支持 attached EXT prog 自身的 REJIT

1. 从 live trampoline state 重建 `dst_prog`
2. 对 `BPF_TRAMP_REPLACE` 增加专门 refresh/rollback 分支
3. 明确 multi-attach 语义
   - 先 reject
   - 或做 post-verify multi-target revalidation

### 第 3 阶段：再考虑 target-side BPF-to-BPF trampoline refresh

这是最大的一块，需要一起处理：

- `tr->func.addr`
- `tr->ip`
- `trampoline_ip_table`
- ftrace/direct-call
- REPLACE patch

不建议把它和“attached EXT 自身 REJIT”混成一个小 patch 一次性提交。
