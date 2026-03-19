# BPF_PROG_JIT_RECOMPILE 与 trampoline regeneration 调研

日期：2026-03-19

## 结论

`BPF_PROG_JIT_RECOMPILE` 目前只会更新 `prog->bpf_func`，但 live trampoline/freplace callsite 里仍然硬编码旧地址，所以 attached program 在 recompile 之后会继续走旧 image。

正确做法不是加 guard 拒绝 trampoline programs，而是：

1. 在 recompile 成功提交新 image 之后、释放旧 image 之前，显式触发 trampoline regeneration。
2. 复用现有的 `bpf_trampoline_update()` 路径来重建 fentry/fexit/fmod_ret/LSM trampoline。
3. 对 freplace 单独处理，因为它根本不走 `bpf_trampoline_update()`，而是直接把 target callsite/jump poke 到 `extension_prog->bpf_func`。
4. 这个 regenerate 触发点必须放在 `jit_directives.c` 的 commit 之后、`synchronize_rcu()`/释放旧 header 之前。
5. 失败回滚不能只依赖 `bpf_prog_jit_recompile()` 外层的 `bpf_jit_recompile_restore()`，因为那时新 header 已经只剩 `prog->bpf_func` 可达；一旦 post-commit regeneration 失败，会泄漏新 image。回滚必须在 `bpf_jit_recompile_prog_images()` 里就地完成。

## 代码阅读结果

### 1. trampoline 侧的关键点

`vendor/linux-framework/kernel/bpf/trampoline.c`

- `bpf_trampoline_update()` 是普通 trampoline 的唯一 regenerate 入口。它会：
  - 从 `tr->progs_hlist[]` 抽出当前 link 集合：`bpf_trampoline_get_progs()`（`trampoline.c:441-463`）
  - 调 `arch_bpf_trampoline_size()` / `arch_prepare_bpf_trampoline()` 生成新 image（`trampoline.c:660-680`）
  - 用 `modify_fentry()` / `register_fentry()` 切到新 image（`trampoline.c:688-712`）
  - 旧 image 通过 `bpf_tramp_image_put()` 延迟退休（`trampoline.c:516-563`）

- attach/update 现有路径已经完全复用这套逻辑：
  - `__bpf_trampoline_link_prog()` 里 link 成功后直接 `bpf_trampoline_update(tr, true)`（`trampoline.c:767-839`）
  - `__bpf_trampoline_unlink_prog()` 里 unlink 后也直接 `bpf_trampoline_update(tr, true)`（`trampoline.c:853-880`）

- x86 trampoline 生成时会把每个 attached program 的 `p->bpf_func` 直接编码进 trampoline body：
  - `arch/x86/net/bpf_jit_comp.c:5055`
  - 所以只改 `prog->bpf_func` 不会自动影响已经生成好的 trampoline image。

- freplace 是单独路径，不走 `bpf_trampoline_update()`：
  - attach 时：`__bpf_trampoline_link_prog()` 直接 `bpf_arch_text_poke(..., link->link.prog->bpf_func)`（`trampoline.c:788-799`）
  - detach 时：`__bpf_trampoline_unlink_prog()` 直接从 `tr->extension_prog->bpf_func` poke 回 NOP（`trampoline.c:861-869`）
  - 也就是说 freplace 需要单独 repoke target site。

### 2. recompile 侧的关键点

`vendor/linux-framework/kernel/bpf/jit_directives.c`

- `bpf_jit_recompile_prog_images()` 的流程是：
  - 给每个 image `stage_begin()`（`jit_directives.c:3309-3317`）
  - 重新 JIT，产出 staged image（`jit_directives.c:3319-3391`）
  - 记录 `old_headers[]` / `old_priv_stacks[]`（`jit_directives.c:3417-3425`）
  - 为每个 image `bpf_jit_recompile_commit()`（`jit_directives.c:3439-3443`）
  - 如果有 subprog，再把顶层 `prog->bpf_func` 指到 `func[0]->bpf_func`（`jit_directives.c:3445-3455`）
  - `synchronize_rcu()`（`jit_directives.c:3459`）
  - 替换 kallsyms，最后 free `old_headers[]` / `old_priv_stacks[]`（`jit_directives.c:3461-3481`）

- x86 `bpf_jit_recompile_commit()` 会：
  - 更新 `priv_stack_ptr` / `extable` / `jited_len`
  - `smp_store_release(&prog->bpf_func, staged_func)`
  - 然后释放 `jit_data`
  - 代码在 `arch/x86/net/bpf_jit_comp.c:6070-6097`

- 这意味着：
  - 一旦 commit 完成，新 image 已经 live；
  - 但如果此时 trampoline regeneration 失败，外层只做 `bpf_jit_recompile_restore()` 已经不够，因为新 header 的唯一可达路径刚刚就是 `prog->bpf_func`，restore 以后这个指针会切回旧 image，新 header 会丢失引用并泄漏。

### 3. 结构体与生命周期

`vendor/linux-framework/include/linux/bpf.h`

- `struct bpf_trampoline`：
  - `progs_hlist[]` / `progs_cnt[]` 保存普通 trampoline attached progs
  - `extension_prog` 单独保存 freplace prog
  - `cur_image` 是普通 trampoline 的 live image
  - 见 `bpf.h:1337-1365`

- `struct bpf_prog_aux`：
  - `dst_prog` / `dst_trampoline` 只是 load/attach 期间的暂存
  - attach 完成后会被清空
  - 见 `bpf.h:1688-1693`

- `struct bpf_prog`：
  - live entry point 在 `prog->bpf_func`
  - 见 `bpf.h:1802-1833`

### 4. 为什么不能依赖 `dst_trampoline` / `bpf_prog_has_trampoline()`

- `bpf_tracing_prog_attach()` attach 成功后会清掉 `prog->aux->dst_prog` 和 `prog->aux->dst_trampoline`（`syscall.c:3752-3765`）。
  - 所以 recompile 发生时，不能靠 `prog->aux->dst_trampoline` 找 live trampoline。

- `bpf_prog_has_trampoline()` 只看 prog type/attach type（`trampoline.c:137-153`）：
  - 它不表示“当前已 attached”
  - 它不覆盖 `BPF_PROG_TYPE_EXT`，所以 freplace 会漏掉
  - 用它做 syscall guard 会把 unattached tracing prog 也挡掉，连 `BPF_PROG_TEST_RUN` 这种直接跑 `prog->bpf_func` 的路径都一起误伤

- `bpf_trampoline_get()`/`bpf_trampoline_lookup()` 也不适合直接给 recompile 用：
  - `bpf_trampoline_lookup()` 在 miss 时会新建 trampoline（`trampoline.c:331-367`）
  - recompile 这里需要的是“只找 live trampoline，不创建新对象”
  - 对 freplace 来说更麻烦：attach 完成后 `dst_prog` 已经丢掉，recompile 侧根本无法从 `prog` 重算 target-prog key

## 推荐方案

### 总体思路

新增一个 trampoline 层 helper，按“当前 live trampoline 是否引用这个 prog”来扫描并 regenerate：

- 普通 trampoline：`tr->progs_hlist[]` 里有 `link->link.prog == prog`
  - 调 `bpf_trampoline_update(tr, true)`
- freplace：`tr->extension_prog == prog`
  - 调 `bpf_arch_text_poke(... JUMP -> JUMP ..., old_func, new_func)`

这样做的好处：

- 不依赖 `dst_trampoline`
- 不依赖重新计算 key
- 自动覆盖 fentry/fexit/fmod_ret/LSM/freplace
- unattached prog 只会 scan 一遍然后 no-op，不会影响 `BPF_PROG_TEST_RUN`

### regenerate 的正确插点

插在 `bpf_jit_recompile_prog_images()` 里：

- 所有 `bpf_jit_recompile_commit()` 都成功之后
- 如果有 subprog，顶层 `prog->bpf_func` 也更新完成之后
- `synchronize_rcu()` 之前
- `old_headers[]` / `old_priv_stacks[]` 还没释放之前

也就是当前 `jit_directives.c:3456-3459` 之间。

原因：

- 这时 trampoline 看到的是新 `prog->bpf_func`
- 旧 image 还在，regeneration 失败时还有回滚抓手
- kallsyms 还没 replace，影子 ksym 也还在 staged 状态

## 具体改动方案

### A. `include/linux/bpf.h`：导出一个 recompile 专用 helper

新增原型：

```diff
diff --git a/vendor/linux-framework/include/linux/bpf.h b/vendor/linux-framework/include/linux/bpf.h
@@
 int bpf_trampoline_link_prog(struct bpf_tramp_link *link,
                              struct bpf_trampoline *tr,
                              struct bpf_prog *tgt_prog);
 int bpf_trampoline_unlink_prog(struct bpf_tramp_link *link,
                                struct bpf_trampoline *tr,
                                struct bpf_prog *tgt_prog);
+int bpf_prog_regenerate_trampolines(struct bpf_prog *prog,
+                                    bpf_func_t other_bpf_func);
 struct bpf_trampoline *bpf_trampoline_get(u64 key,
                                           struct bpf_attach_target_info *tgt_info);
```

这里 `other_bpf_func` 的含义是“另一个 image 的 entry”，只给 freplace 用：

- 正向 regenerate 时：`other_bpf_func = old_prog_func`
- 失败回滚时：`other_bpf_func = committed_new_prog_func`

普通 trampoline 完全不需要这个参数。

### B. `kernel/bpf/trampoline.c`：实现 `bpf_prog_regenerate_trampolines()`

建议新增三个小 helper：

1. `bpf_trampoline_refs_prog(tr, prog)`  
   判断这个 trampoline 当前是否引用 `prog`

2. `bpf_trampoline_collect_prog_matches(prog, &trs, &nr)`  
   在 `trampoline_key_table[]` 上扫描 live trampoline，把匹配项先 `refcount_inc()` 收集到临时数组里，然后释放 `trampoline_mutex`

3. `bpf_trampoline_retarget_extension(tr, from, to)`  
   处理 freplace 的 `JUMP -> JUMP`

核心逻辑如下：

```diff
diff --git a/vendor/linux-framework/kernel/bpf/trampoline.c b/vendor/linux-framework/kernel/bpf/trampoline.c
@@
+static bool bpf_trampoline_refs_prog(const struct bpf_trampoline *tr,
+                                     const struct bpf_prog *prog)
+{
+        struct bpf_tramp_link *link;
+        int kind;
+
+        if (tr->extension_prog == prog)
+                return true;
+
+        for (kind = 0; kind < BPF_TRAMP_MAX; kind++) {
+                hlist_for_each_entry(link, &tr->progs_hlist[kind], tramp_hlist) {
+                        if (link->link.prog == prog)
+                                return true;
+                }
+        }
+
+        return false;
+}
+
+static int bpf_trampoline_retarget_extension(struct bpf_trampoline *tr,
+                                             bpf_func_t from,
+                                             bpf_func_t to)
+{
+        int err;
+
+        err = bpf_arch_text_poke(tr->func.addr, BPF_MOD_JUMP, BPF_MOD_JUMP,
+                                 (void *)from, (void *)to);
+        if (err == 0 || err == 1)
+                return 0;
+
+        /* idempotent no-op: already points at @to */
+        err = bpf_arch_text_poke(tr->func.addr, BPF_MOD_JUMP, BPF_MOD_JUMP,
+                                 (void *)to, (void *)to);
+        return (err == 0 || err == 1) ? 0 : err;
+}
+
+int bpf_prog_regenerate_trampolines(struct bpf_prog *prog,
+                                    bpf_func_t other_bpf_func)
+{
+        struct bpf_trampoline **trs = NULL;
+        bpf_func_t cur_bpf_func = READ_ONCE(prog->bpf_func);
+        u32 nr = 0, i;
+        int err = 0;
+
+        /* scan trampoline_key_table[] under trampoline_mutex,
+         * refcount_inc() every matching trampoline,
+         * then drop trampoline_mutex before doing real updates
+         */
+
+        for (i = 0; i < nr; i++) {
+                struct bpf_trampoline *tr = trs[i];
+
+                mutex_lock(&tr->mutex);
+                if (tr->extension_prog == prog)
+                        err = bpf_trampoline_retarget_extension(tr,
+                                                                other_bpf_func,
+                                                                cur_bpf_func);
+                else
+                        err = bpf_trampoline_update(tr, true);
+                mutex_unlock(&tr->mutex);
+
+                if (err)
+                        break;
+        }
+
+        while (nr--)
+                bpf_trampoline_put(trs[nr]);
+        kfree(trs);
+        return err;
+}
```

实现细节注意点：

- 不要在持有 `trampoline_mutex` 时调用 `bpf_trampoline_update()`；先收集引用再做更新。
- 对 freplace，不能调用 `bpf_trampoline_update()`，因为 `BPF_TRAMP_REPLACE` 根本没有 `cur_image`。
- `bpf_arch_text_poke()` 在 x86 上返回 `1` 表示“目标已经是 new 指令”，应当当成成功处理。

### C. `kernel/bpf/jit_directives.c`：在 commit 后、释放旧 image 前调用 helper

#### C1. 扩充 rollback snapshot，补齐 `fp_start/fp_end`

当前 `bpf_jit_recompile_prog_state` 没保存 `aux->ksym.fp_start/fp_end`，这在 post-commit rollback 时不够。

```diff
diff --git a/vendor/linux-framework/kernel/bpf/jit_directives.c b/vendor/linux-framework/kernel/bpf/jit_directives.c
@@
 struct bpf_jit_recompile_prog_state {
         struct bpf_prog *prog;
         bpf_func_t bpf_func;
         void __percpu *priv_stack_ptr;
         struct exception_table_entry *extable;
         void *jit_data;
         struct bpf_insn *insnsi_copy;
         u32 insn_cnt;
         u32 jited_len;
         u32 num_exentries;
+        u32 fp_start;
+        u32 fp_end;
         bool jited;
         bool exception_boundary;
 };
@@
         state->jited_len = prog->jited_len;
         state->num_exentries = prog->aux->num_exentries;
+        state->fp_start = prog->aux->ksym.fp_start;
+        state->fp_end = prog->aux->ksym.fp_end;
         state->jited = prog->jited;
@@
-        prog->bpf_func = state->bpf_func;
         prog->aux->priv_stack_ptr = state->priv_stack_ptr;
         prog->aux->extable = state->extable;
         prog->aux->jit_data = state->jit_data;
         prog->jited_len = state->jited_len;
         prog->aux->num_exentries = state->num_exentries;
+        prog->aux->ksym.fp_start = state->fp_start;
+        prog->aux->ksym.fp_end = state->fp_end;
         prog->jited = state->jited;
         prog->aux->exception_boundary = state->exception_boundary;
+        smp_store_release(&prog->bpf_func, state->bpf_func);
         bpf_jit_recompile_reset_prog_aux(prog);
```

这里把 restore 的 `bpf_func` 改成 `smp_store_release()`，因为它现在不再只是“未 commit 前的清理”，还要承担 post-commit 回滚时重新发布旧 entry point。

#### C2. 改 `bpf_jit_recompile_prog_images()` 的插点

把签名改成拿到 rollback state，方便 post-commit 失败时原地恢复：

```diff
diff --git a/vendor/linux-framework/kernel/bpf/jit_directives.c b/vendor/linux-framework/kernel/bpf/jit_directives.c
@@
-static int bpf_jit_recompile_prog_images(struct bpf_prog *prog)
+static int bpf_jit_recompile_prog_images(struct bpf_prog *prog,
+        struct bpf_jit_recompile_rollback_state *rollback)
 {
         struct bpf_prog_aux *main_aux = bpf_jit_main_aux(prog);
         struct bpf_binary_header **old_headers = NULL;
+        struct bpf_binary_header **new_headers = NULL;
         void __percpu **old_priv_stacks = NULL;
+        void __percpu **new_priv_stacks = NULL;
+        bpf_func_t old_prog_func = READ_ONCE(prog->bpf_func);
+        bpf_func_t committed_prog_func;
         u64 (*new_exception_cb)(u64 cookie, u64 sp, u64 bp, u64, u64);
         u32 image_cnt = 1;
```

在分配 `old_headers` / `old_priv_stacks` 的地方一起分配 `new_headers` / `new_priv_stacks`。

然后在现有 commit 完成、顶层 `prog->bpf_func` 和 `main_aux->bpf_exception_cb` 都写好之后，插入 regenerate：

```diff
@@
         if (main_aux->func_cnt && main_aux->func) {
                 prog->jited = 1;
                 prog->jited_len = main_aux->func[0]->jited_len;
                 prog->aux->extable = main_aux->func[0]->aux->extable;
                 prog->aux->num_exentries = main_aux->func[0]->aux->num_exentries;
                 prog->aux->exception_boundary =
                         main_aux->func[0]->aux->exception_boundary;
                 prog->aux->ksym.fp_start = main_aux->func[0]->aux->ksym.fp_start;
                 prog->aux->ksym.fp_end = main_aux->func[0]->aux->ksym.fp_end;
                 smp_store_release(&prog->bpf_func, main_aux->func[0]->bpf_func);
         }
         if (new_exception_cb)
                 smp_store_release(&main_aux->bpf_exception_cb, new_exception_cb);
+
+        err = bpf_prog_regenerate_trampolines(prog, old_prog_func);
+        if (err)
+                goto out_restore_committed;
 
         synchronize_rcu();
```

#### C3. 新增 `out_restore_committed:`，不要把 post-commit 失败交给外层 restore

这是这次修复里最重要的部分。原因是：

- 走到这里时，`bpf_jit_recompile_commit()` 已经把 `prog->bpf_func` 切到新 image；
- 如果直接 `goto out_abort`，外层 `bpf_jit_recompile_restore()` 虽然能把 `prog->bpf_func` 指回旧 image，但新 header/new priv stack 会丢引用并泄漏；
- 所以必须在 `bpf_jit_recompile_prog_images()` 内部先抓住“当前 committed 新资源”，然后 restore，再 free 新资源。

建议增加下面这个 block：

```diff
@@
+out_restore_committed:
+        committed_prog_func = READ_ONCE(prog->bpf_func);
+        for (i = 0; i < image_cnt; i++) {
+                struct bpf_prog *image_prog = bpf_jit_recompile_image_prog(prog, i);
+
+                if (!image_prog)
+                        continue;
+                if (image_prog->jited && image_prog->bpf_func)
+                        new_headers[i] = bpf_jit_binary_pack_hdr(image_prog);
+                new_priv_stacks[i] = image_prog->aux->priv_stack_ptr;
+        }
+
+        bpf_jit_recompile_restore(rollback);
+
+        /* rollback trampoline/freplace callsites back to old prog->bpf_func */
+        WARN_ON_ONCE(bpf_prog_regenerate_trampolines(prog, committed_prog_func));
+
+        synchronize_rcu();
+
+        for (i = 0; i < image_cnt; i++) {
+                struct bpf_prog *image_prog = bpf_jit_recompile_image_prog(prog, i);
+
+                if (new_headers[i] &&
+                    (!image_prog || new_headers[i] != bpf_jit_binary_pack_hdr(image_prog)))
+                        bpf_jit_binary_pack_free(new_headers[i], NULL);
+                if (new_priv_stacks[i] &&
+                    (!image_prog || new_priv_stacks[i] != image_prog->aux->priv_stack_ptr))
+                        free_percpu(new_priv_stacks[i]);
+        }
+        goto out_abort;
```

然后把 `out_free:` 里多释放 `new_headers` / `new_priv_stacks` 这两个临时数组本身。

#### C4. 调整 call site

`bpf_prog_jit_recompile()` 里把：

```c
err = bpf_jit_recompile_prog_images(prog);
```

改成：

```c
err = bpf_jit_recompile_prog_images(prog, &rollback);
```

外层原有的 `if (err) bpf_jit_recompile_restore(&rollback);` 可以先保留，功能上是幂等的；更干净的版本是再加一个 `bool restored_in_callee` 或直接让 callee 对所有失败都自己 restore。

## 为什么这个方案是对的

### 1. 它复用了 attach/update 的既有 regenerate 机制

attach/unlink/link update 现在本来就是：

- 改 `tr->progs_hlist[]` / `tr->extension_prog`
- 然后 `bpf_trampoline_update()` 或 `bpf_arch_text_poke()`

recompile 只是“引用集合没变，但 `prog->bpf_func` 变了”，本质上也应该走同一个 regenerate 机制。

### 2. 它不会误伤 unattached tracing prog

新 helper 扫的是 live trampoline table：

- attached 就 regenerate
- unattached 就 no-op

所以不会像粗暴 guard 那样把 `BPF_PROG_TEST_RUN` 一起挡掉。

### 3. 它覆盖了 freplace

只靠 `bpf_trampoline_update()` 不够，因为 freplace 没有 `cur_image`，只有 `tr->func.addr -> extension_prog->bpf_func` 的 direct poke。

### 4. 它避开了 `dst_trampoline` 生命周期陷阱

attach 完成后 `dst_trampoline` 已经清掉，recompile 再去读它一定不稳。扫描 live trampoline table 才是可靠来源。

### 5. 它把 rollback 放在还能拿到“新 committed 资源”的地方

这是和“简单在 commit 后插一个 `bpf_trampoline_update()`”最大的区别。只有在 `bpf_jit_recompile_prog_images()` 内部，才还来得及：

- 抓住新 header / new priv stack
- restore 旧 state
- 重新 regenerate trampoline 回旧 image
- 然后 free 新 committed 资源

## 不推荐的方案

### 方案一：直接拒绝 trampoline programs

不行，原因有三点：

- 会误伤 unattached tracing/LSM prog
- 会把 `BPF_PROG_TEST_RUN` 这类只走 `prog->bpf_func` 的路径一起挡掉
- 还漏掉 `BPF_PROG_TYPE_EXT`

### 方案二：在 jit_directives.c 里通过 `prog->aux->dst_trampoline` 直接 update

不行，因为 attach 成功后这个字段已经被清掉。

### 方案三：在 recompile 里重新 `bpf_trampoline_get(key, ...)`

不理想：

- miss 时会错误地新建 trampoline
- freplace attach 完成后已经拿不到 `dst_prog`，无法重建 key

## 建议验证项

1. `fentry` attached prog：recompile 后通过真实 hook 触发，确认走新 image。
2. `fexit` / `fmod_ret` attached prog：确认 trampoline regenerate 后返回路径正常。
3. `LSM` attached prog：确认和普通 tracing tramp 一样能更新。
4. `freplace` attached prog：确认 target site 已 repoke 到新 `prog->bpf_func`。
5. unattached tracing prog：recompile 仍成功，`BPF_PROG_TEST_RUN` 不受影响。
6. 故障注入：
   - `bpf_tramp_image_alloc()` 失败
   - `arch_prepare_bpf_trampoline()` 失败
   - `bpf_arch_text_poke()` 失败
   期望结果是：syscall 返回错误，旧 prog image 仍 live，旧 trampoline/callsite 仍 live，没有泄漏新 committed image。

## 最后建议

如果只想做最小正确修复，我建议分两步：

1. 先按上面的方式补 `bpf_prog_regenerate_trampolines()` 和 `jit_directives.c` 的 post-commit 插点。
2. 同时把 post-commit rollback 收进 `bpf_jit_recompile_prog_images()`，不要再依赖外层 restore 处理这一路错误。

否则，功能上虽然能“尝试 regenerate”，但一旦 regenerate 失败，recompile 会留下新 committed image 的资源泄漏或 trampoline/callsite 与 `prog->bpf_func` 不一致的问题。
