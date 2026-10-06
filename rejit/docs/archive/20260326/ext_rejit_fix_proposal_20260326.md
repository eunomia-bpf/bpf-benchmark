# attached EXT (freplace) live REJIT 最小修复方案

日期：2026-03-26

## 范围

本文只讨论一件事：

- 让“**已经 attach 的 `BPF_PROG_TYPE_EXT`（freplace）程序自身**”支持 `BPF_PROG_REJIT`

本文**不**试图解决：

- freplace target prog 在存在 inbound BPF trampoline 时的 REJIT
- 一般化的 BPF-to-BPF tracing REJIT 语义
- detached EXT 在丢失 live attach 上下文后的 REJIT

结论先行：

1. 这个问题可以做成一个相对局部的修复，不需要改 verifier 主逻辑。
2. 最小可行路径不是把 `dst_prog` 永久留在 `prog->aux`，也不是从 `bpf_tracing_link` 建新 reverse index。
3. 最小修复应该：
   - 在 REJIT 时从 **live trampoline state** 恢复 `dst_prog + live attach_btf_id`
   - 在 post-swap refresh 时给 `BPF_TRAMP_REPLACE` 增加专门的 `JUMP -> JUMP` patch 路径
   - 在 EXT refresh 失败时走 **rollback**，不能沿用当前“保留新旧 image 并返回错误”的语义

## 1. 精确代码路径

### 1.1 EXT load 时 `dst_prog` 怎么设置

`BPF_PROG_LOAD` 先把 `attach_prog_fd` 解析成 `dst_prog`：

- `vendor/linux-framework/kernel/bpf/syscall.c:2957-2961`

然后把它挂到新建 prog 上：

- `vendor/linux-framework/kernel/bpf/syscall.c:3011-3016`

关键赋值：

- `prog->aux->attach_btf = attach_btf`
- `prog->aux->attach_btf_id = attr->attach_btf_id`
- `prog->aux->dst_prog = dst_prog`

随后 verifier 在 `check_attach_btf_id()` 里直接取：

- `vendor/linux-framework/kernel/bpf/verifier.c:25730-25738`

并在 `bpf_check_attach_target()` 里用 `tgt_prog` 做 freplace target 检查：

- `vendor/linux-framework/kernel/bpf/verifier.c:25761-25762`
- `vendor/linux-framework/kernel/bpf/verifier.c:25350`
- `vendor/linux-framework/kernel/bpf/verifier.c:25578-25583`

同时 load-time 创建好的 trampoline 会保存在：

- `vendor/linux-framework/kernel/bpf/verifier.c:25809-25817`

也就是 attach 前，EXT 的 target 上下文在：

- `prog->aux->dst_prog`
- `prog->aux->dst_trampoline`

### 1.2 attach 时 `dst_prog` 怎么丢

attach 成功后，target 引用被转移进 tracing link：

- `struct bpf_tracing_link` 持有 `trampoline` 和 `tgt_prog`
  - `vendor/linux-framework/include/linux/bpf.h:1936-1940`
- 赋值发生在：
  - `vendor/linux-framework/kernel/bpf/syscall.c:4549-4550`

随后 `bpf_tracing_prog_attach()` 明确把 prog 本体上的 `dst_*` 清空：

- `vendor/linux-framework/kernel/bpf/syscall.c:4552-4565`

这不是 accidental overwrite，而是设计选择：避免 attach/re-attach 后 `prog->aux` 继续 pin 住旧 target。

detach/release 时，link 再负责释放 target 引用：

- `vendor/linux-framework/kernel/bpf/syscall.c:4301-4314`

而 `bpf_tracing_link_fill_link_info()` 还能把 live target id 暴露给用户态：

- `vendor/linux-framework/kernel/bpf/syscall.c:4345-4355`

这说明 attach 之后，target 信息并没有“彻底消失”，只是**不再存在于 `prog->aux->dst_prog`**，而是存在于：

1. `struct bpf_tracing_link::tgt_prog`
2. `struct bpf_tracing_link::trampoline->key`

### 1.3 REJIT 时哪行代码需要 `dst_prog`

REJIT 主路径：

- `vendor/linux-framework/kernel/bpf/syscall.c:3589-3945`

构造临时 `tmp` prog 时，当前只复制两类 attach 上下文：

1. `attach_btf/attach_btf_id`
   - `vendor/linux-framework/kernel/bpf/syscall.c:3666-3671`
2. `dst_prog`
   - `vendor/linux-framework/kernel/bpf/syscall.c:3673-3680`

之后 REJIT 重新走 verifier：

- `vendor/linux-framework/kernel/bpf/syscall.c:3751-3752`

进入 verifier 后：

- `vendor/linux-framework/kernel/bpf/verifier.c:25733`

这里直接读：

- `struct bpf_prog *tgt_prog = prog->aux->dst_prog;`

真正依赖 `tgt_prog` 的关键点是：

1. 选 target BTF：
   - `vendor/linux-framework/kernel/bpf/verifier.c:25350`
2. 找 target subprog 和 target JIT 地址：
   - `vendor/linux-framework/kernel/bpf/verifier.c:25377-25385`
   - `vendor/linux-framework/kernel/bpf/verifier.c:25578-25583`

所以对 freplace 来说，REJIT 不是“缺少 EXT 自己的 BTF”，而是“缺少 live target prog + live target btf_id”。

当前内核已经因为这个原因直接拒绝 attached EXT：

- `vendor/linux-framework/kernel/bpf/syscall.c:3177-3183`

### 1.4 fentry 为什么通常能 REJIT，而 EXT 不能

`tests/unittest/rejit_hotswap_fentry.c` 里的 hotswap fentry attach 到的是 kernel function：

- `tests/unittest/rejit_hotswap_fentry.c:171-183`
- `tests/unittest/rejit_hotswap_fentry.c:251-265`

这种场景的 attach 上下文长期保存在：

- `prog->aux->attach_btf`
- `prog->aux->attach_btf_id`

这些字段 attach 后不会被清掉：

- load 时设置：`vendor/linux-framework/kernel/bpf/syscall.c:3013-3014`
- REJIT 时复制：`vendor/linux-framework/kernel/bpf/syscall.c:3666-3671`

而 verifier 在 `tgt_prog == NULL` 时正是走 `attach_btf` 路径：

- `vendor/linux-framework/kernel/bpf/verifier.c:25350-25355`

所以差异不是“fentry 天生支持，EXT 天生不支持”，而是：

- kernel-function fentry：attach 上下文常驻在 prog 本体
- EXT/freplace：attach 上下文在 attach 后被 link/trampoline 接管，`prog->aux->dst_prog` 被清空

补充一点：

- attach 到另一个 BPF prog 的 tracing/fentry 其实也会遇到类似 metadata 丢失问题
- 只是它没有像 EXT 一样在 `bpf_prog_rejit_supported()` 里被早期拒绝

## 2. 最小修复设计

## 2.1 REJIT 时从哪里恢复 live target：trampoline 还是 tracing link

### 结论

最小修复应当从 **`prog->aux->trampoline_users` + `tr->key`** 恢复，而不是直接从 `bpf_tracing_link` 恢复。

### 原因

当前已经有一个专门给 REJIT 用的 reverse index：

- `prog->aux->trampoline_users`
  - `vendor/linux-framework/include/linux/bpf.h:1728-1729`
- link/unlink 时都在维护它
  - `vendor/linux-framework/kernel/bpf/trampoline.c:846-869`
  - `vendor/linux-framework/kernel/bpf/trampoline.c:903-927`

而且它和 REJIT 用同一把锁串行化：

- `prog->aux->rejit_mutex`
  - `vendor/linux-framework/kernel/bpf/trampoline.c:859-865`
  - `vendor/linux-framework/kernel/bpf/trampoline.c:910-925`
  - `vendor/linux-framework/kernel/bpf/syscall.c:3625`

这意味着：

1. REJIT 在 `rejit_mutex` 下扫描 `trampoline_users` 是稳定的
2. 并发 detach 不会把 link/trampoline 从列表里抽走
3. 不需要新增新的 per-prog reverse index

反过来，`bpf_tracing_link` 虽然持有更直接的 `tgt_prog`：

- `vendor/linux-framework/include/linux/bpf.h:1936-1940`

但内核里**没有**“从 prog 找到全部 tracing links”的现成 reverse index。现状只有全局：

- `link_idr`
  - `vendor/linux-framework/kernel/bpf/syscall.c:65-66`

所以如果坚持从 `bpf_tracing_link` 恢复，要么：

1. 扫全局 `link_idr`
2. 新增 per-prog link list / reverse index

这两条都比直接使用现有 `trampoline_users` 更大、更通用、更不“最小”。

### 为什么 `tr->key` 足够

`tr->key` 已经编码了：

- target prog id
- target btf_id

编码/解码函数：

- `vendor/linux-framework/include/linux/bpf_verifier.h:927-943`

这两个量正是 freplace REJIT verifier 需要恢复的 live attach 上下文。

## 2.2 最小方案的核心思路

### A. 不恢复到原 prog，而是只给 `tmp` 恢复 transient attach 上下文

不要试图把 `prog->aux->dst_prog` 永久“补回去”。原因有两个：

1. attach 后清空 `dst_prog` 是刻意设计
2. 单个 `dst_prog`/`attach_btf_id` 字段无法正确表达多 live link 状态

所以最小修复应当只在 `BPF_PROG_REJIT` 的 `tmp` prog 上恢复：

- `tmp->aux->dst_prog`
- `tmp->aux->attach_btf_id`

原始 `prog` 本体保持不变。

### B. 对 EXT 单独从 live trampoline state 恢复 target

如果 `prog->aux->dst_prog` 还在，沿用当前逻辑。

如果 `prog->type == BPF_PROG_TYPE_EXT && !prog->aux->dst_prog`，则：

1. 在 `rejit_mutex` 下遍历 `prog->aux->trampoline_users`
2. 取 live REPLACE trampoline
3. 用 `tr->key` 解出 `(target_prog_id, target_btf_id)`
4. 用 `bpf_prog_by_id()` 取回 live `tgt_prog`
5. 填到 `tmp->aux->dst_prog` 和 `tmp->aux->attach_btf_id`

这里要特别注意：**不能继续沿用 `prog->aux->attach_btf_id`**。

因为 EXT attach 到新 target 时，`prog->aux->attach_btf_id` 并不会被更新：

- `vendor/linux-framework/kernel/bpf/syscall.c:3014`
- `vendor/linux-framework/kernel/bpf/syscall.c:4549-4565`

也就是说，attach 后真正 live 的 `btf_id` 只有 trampoline key 里那份是可靠的。

### C. 对 REPLACE 增加专门 refresh

当前 `bpf_trampoline_refresh_prog()` 无差别对所有 trampoline 调：

- `bpf_trampoline_update()`
  - `vendor/linux-framework/kernel/bpf/trampoline.c:931-945`

但 REPLACE attach 根本不是 image-backed trampoline 路径：

- attach 时是直接 `NOP -> JUMP ext->bpf_func`
  - `vendor/linux-framework/kernel/bpf/trampoline.c:788-798`
- detach 时是 `JUMP ext->bpf_func -> NOP`
  - `vendor/linux-framework/kernel/bpf/trampoline.c:880-888`

所以 attached EXT 的 post-swap refresh 必须改成：

- `JUMP old_ext_bpf_func -> JUMP new_ext_bpf_func`

而不是 rebuild trampoline image。

## 2.3 建议修改的函数

### 需要改的文件

1. `vendor/linux-framework/kernel/bpf/syscall.c`
2. `vendor/linux-framework/kernel/bpf/trampoline.c`
3. `vendor/linux-framework/include/linux/bpf.h`

### 不需要改的文件

1. `vendor/linux-framework/kernel/bpf/verifier.c`
2. `vendor/linux-framework/kernel/bpf/btf.c`

原因是 verifier 现有逻辑已经足够；只要 `tmp->aux->dst_prog + attach_btf_id` 正确，它就会走通。

### 预计改动面

按当前代码结构，比较现实的最小 patch 大概是：

- `syscall.c`: 30-45 行
- `trampoline.c`: 60-90 行
- `bpf.h`: 6-10 行

总计约：

- 100-140 行

不含额外注释的话，接近 3 个函数修改 + 2 个新 helper。

## 2.4 建议的伪代码 / diff

### 2.4.1 头文件

```diff
--- a/vendor/linux-framework/include/linux/bpf.h
+++ b/vendor/linux-framework/include/linux/bpf.h
@@
-int bpf_trampoline_refresh_prog(struct bpf_prog *prog);
+int bpf_trampoline_refresh_prog(struct bpf_prog *prog,
+			       bpf_func_t old_bpf_func);
+int bpf_trampoline_recover_ext_attach_ctx(struct bpf_prog *prog,
+					  struct bpf_prog **tgt_prog,
+					  u32 *attach_btf_id);
@@
-static inline int bpf_trampoline_refresh_prog(struct bpf_prog *prog)
+static inline int bpf_trampoline_refresh_prog(struct bpf_prog *prog,
+					      bpf_func_t old_bpf_func)
 {
 	return 0;
 }
+static inline int bpf_trampoline_recover_ext_attach_ctx(struct bpf_prog *prog,
+							struct bpf_prog **tgt_prog,
+							u32 *attach_btf_id)
+{
+	return -ENOENT;
+}
```

### 2.4.2 trampoline.c：恢复 live EXT attach 上下文

```diff
--- a/vendor/linux-framework/kernel/bpf/trampoline.c
+++ b/vendor/linux-framework/kernel/bpf/trampoline.c
@@
+int bpf_trampoline_recover_ext_attach_ctx(struct bpf_prog *prog,
+					  struct bpf_prog **tgt_prog,
+					  u32 *attach_btf_id)
+{
+	struct bpf_tramp_user *tu;
+	struct bpf_prog *found = NULL;
+	u32 obj_id, btf_id;
+	int err = -ENOENT;
+
+	lockdep_assert_held(&prog->aux->rejit_mutex);
+
+	list_for_each_entry(tu, &prog->aux->trampoline_users, list) {
+		struct bpf_trampoline *tr = tu->tr;
+		struct bpf_prog *cur;
+
+		/* EXT prog 自己的 trampoline_users 应该只包含 REPLACE users */
+		if (READ_ONCE(tr->extension_prog) != prog)
+			continue;
+
+		bpf_trampoline_unpack_key(tr->key, &obj_id, &btf_id);
+		cur = bpf_prog_by_id(obj_id);
+		if (IS_ERR(cur))
+			goto err_put;
+
+		if (found) {
+			bpf_prog_put(cur);
+			err = -EOPNOTSUPP; /* 先拒绝 multi-attach */
+			goto err_put;
+		}
+
+		found = cur;
+		*attach_btf_id = btf_id;
+	}
+
+	if (!found)
+		return -ENOENT;
+
+	*tgt_prog = found;
+	return 0;
+
+err_put:
+	if (found)
+		bpf_prog_put(found);
+	return err;
+}
```

实现细节建议：

1. helper 只在 `rejit_mutex` 下调用
2. v1 直接拒绝多 live REPLACE user
3. 这里用 `bpf_prog_by_id()` 额外拿一份 ref，给 `tmp->aux->dst_prog`

### 2.4.3 syscall.c：REJIT 时恢复 `tmp->aux->dst_prog + attach_btf_id`

```diff
--- a/vendor/linux-framework/kernel/bpf/syscall.c
+++ b/vendor/linux-framework/kernel/bpf/syscall.c
@@
-	/* Attached freplace/EXT programs clear dst_prog after link setup.
-	 * REJIT's verifier path still needs a live dst_prog to resolve the
-	 * replacement target, so reject the attached case until that state
-	 * can be reconstructed safely.
-	 */
-	if (prog->type == BPF_PROG_TYPE_EXT && !aux->dst_prog)
-		return false;
-
 	return true;
@@
 	tmp->aux->attach_btf_id = prog->aux->attach_btf_id;
 
-	if (prog->aux->dst_prog) {
+	if (prog->aux->dst_prog) {
 		bpf_prog_inc(prog->aux->dst_prog);
 		tmp->aux->dst_prog = prog->aux->dst_prog;
+	} else if (prog->type == BPF_PROG_TYPE_EXT) {
+		u32 live_attach_btf_id = 0;
+
+		err = bpf_trampoline_recover_ext_attach_ctx(prog,
+							    &tmp->aux->dst_prog,
+							    &live_attach_btf_id);
+		if (err)
+			goto free_tmp;
+		tmp->aux->attach_btf_id = live_attach_btf_id;
 	}
```

建议把这段整理成一个局部 helper，例如：

- `bpf_prog_rejit_prepare_attach_ctx(prog, tmp)`

这样更清晰，也方便以后把同样逻辑扩展到 BPF-to-BPF tracing。

### 2.4.4 trampoline.c：给 REPLACE 增加 refresh 分支

```diff
--- a/vendor/linux-framework/kernel/bpf/trampoline.c
+++ b/vendor/linux-framework/kernel/bpf/trampoline.c
@@
-int bpf_trampoline_refresh_prog(struct bpf_prog *prog)
+int bpf_trampoline_refresh_prog(struct bpf_prog *prog, bpf_func_t old_bpf_func)
 {
 	struct bpf_tramp_user *tu;
 	int err = 0;
 
 	list_for_each_entry(tu, &prog->aux->trampoline_users, list) {
 		struct bpf_trampoline *tr = tu->tr;
 
 		mutex_lock(&tr->mutex);
 
-		err = bpf_trampoline_update(tr, true);
+		if (tr->extension_prog == prog) {
+			err = bpf_arch_text_poke(tr->func.addr,
+						 BPF_MOD_JUMP,
+						 BPF_MOD_JUMP,
+						 (void *)old_bpf_func,
+						 (void *)prog->bpf_func);
+		} else {
+			err = bpf_trampoline_update(tr, true);
+		}
 
 		mutex_unlock(&tr->mutex);
 
 		if (err)
 			break;
 	}
 
 	return err;
 }
```

但这个版本还不够安全。对 EXT 来说必须再补一个“已 patch REPLACE users 的本地回滚”，否则 refresh 中途失败会留下混合状态。

更安全的版本应当是：

```c
static int bpf_trampoline_refresh_ext(struct bpf_prog *prog, bpf_func_t old_bpf_func)
{
	struct bpf_tramp_user *tu;
	int err;

	list_for_each_entry(tu, &prog->aux->trampoline_users, list) {
		struct bpf_trampoline *tr = tu->tr;

		mutex_lock(&tr->mutex);
		err = bpf_arch_text_poke(tr->func.addr,
					 BPF_MOD_JUMP, BPF_MOD_JUMP,
					 (void *)old_bpf_func,
					 (void *)prog->bpf_func);
		mutex_unlock(&tr->mutex);
		if (err)
			goto rollback;
	}
	return 0;

rollback:
	list_for_each_entry_continue_reverse(tu, &prog->aux->trampoline_users, list) {
		struct bpf_trampoline *tr = tu->tr;

		mutex_lock(&tr->mutex);
		if (bpf_arch_text_poke(tr->func.addr,
				       BPF_MOD_JUMP, BPF_MOD_JUMP,
				       (void *)prog->bpf_func,
				       (void *)old_bpf_func))
			pr_warn("bpf_rejit: ext refresh rollback failed\n");
		mutex_unlock(&tr->mutex);
	}
	return err;
}
```

然后总入口改成：

```c
if (prog->type == BPF_PROG_TYPE_EXT)
	return bpf_trampoline_refresh_ext(prog, old_bpf_func);
```

### 2.4.5 syscall.c：EXT refresh 失败时必须 rollback

当前 forward refresh 失败后会：

- 返回错误
- `retain_old_image = true`
- 不做整体验证性回滚

这对普通 trampoline 还能勉强接受，但对 EXT 不行。原因是：

1. `prog->bpf_func` 已经换成新地址
2. 如果 REPLACE callsite 还停在旧地址，link state 就和 `prog->bpf_func` 不一致
3. 后续 detach 会走：
   - `vendor/linux-framework/kernel/bpf/trampoline.c:882-884`
4. 这里会按 `tr->extension_prog->bpf_func` 作为“当前 JUMP 目标”去 unpatch
5. 一旦 callsite 还指向 old image，unlink 会因为 old_addr mismatch 而失败

因此 EXT refresh 失败时必须走 rollback，而不是简单 retain。

建议改成：

```diff
--- a/vendor/linux-framework/kernel/bpf/syscall.c
+++ b/vendor/linux-framework/kernel/bpf/syscall.c
@@
-		err = bpf_trampoline_refresh_prog(prog);
+		err = bpf_trampoline_refresh_prog(prog, old_bpf_func);
 		if (err) {
 			pr_warn("bpf_rejit: trampoline refresh failed: %d\n", err);
 			ret = err;
-			retain_old_image = true;
+			if (prog->type == BPF_PROG_TYPE_EXT) {
+				err = bpf_prog_rejit_rollback(prog, tmp,
+							      new_bpf_func,
+							      saved_poke_tab,
+							      saved_poke_cnt,
+							      &rollback_state);
+				if (err) {
+					pr_warn("bpf_rejit: rollback after ext refresh failure failed: %d\n",
+						err);
+					retain_old_image = true;
+				}
+			} else {
+				retain_old_image = true;
+			}
 			goto post_swap_sync;
 		}
@@
-	err = bpf_trampoline_refresh_prog(prog);
+	err = bpf_trampoline_refresh_prog(prog, new_bpf_func);
```

## 2.5 refcount / 生命周期分析

### 2.5.1 为什么从 live trampoline 恢复是安全的

link/unlink 修改 `trampoline_users` 时与 REJIT 用的是同一把锁：

- `vendor/linux-framework/kernel/bpf/trampoline.c:859-865`
- `vendor/linux-framework/kernel/bpf/trampoline.c:910-925`

所以在：

- `vendor/linux-framework/kernel/bpf/syscall.c:3625`

拿住 `prog->aux->rejit_mutex` 后，REJIT 看到的是一个稳定的 live attached-user 集合。

### 2.5.2 target prog 生命周期

attached link 建立后会持有 target prog ref：

- `vendor/linux-framework/kernel/bpf/syscall.c:4549-4550`

直到 release 时才放掉：

- `vendor/linux-framework/kernel/bpf/syscall.c:4312-4314`

所以在 attached EXT 的 REJIT 窗口里：

1. live link 保证 target prog 不会消失
2. REJIT helper 再额外用 `bpf_prog_by_id()` 拿一份 ref 给 `tmp->aux->dst_prog`
3. 这份 ref 在已有 cleanup 路径里释放即可
   - 成功后：`vendor/linux-framework/kernel/bpf/syscall.c:3882-3885`
   - 失败后：`vendor/linux-framework/kernel/bpf/syscall.c:3917-3929`

### 2.5.3 为什么不要把 live target 写回 `prog->aux->dst_prog`

因为那会重新引入 attach path 当初刻意避免的问题：

1. stale target pin
2. 单字段无法表示多 live link
3. detach / re-attach 语义混乱

所以正确做法是：

- 只恢复给 `tmp`
- 只活到这次 verifier/JIT 完成

### 2.5.4 `attach_btf_id` 也必须恢复 live 值

这是一个容易漏掉但必须修的点。

如果 EXT attach 到了一个不是 load-time target 的新 prog，那么：

- `prog->aux->attach_btf_id` 仍可能是旧值
- verifier 重新 attach check 时会拿错 subprog type id

因此 REJIT helper 必须优先使用：

- `tr->key` 里 unpack 出来的 live `btf_id`

而不是：

- `prog->aux->attach_btf_id`

## 3. 风险评估

### 3.1 改动影响面

影响面总体可控，原因是：

1. verifier 不需要改
2. attach/detach 正常路径不需要改行为
3. 主要变化集中在 REJIT metadata 恢复和 post-swap refresh

真正被改语义的范围只有：

1. attached EXT 的 `BPF_PROG_REJIT`
2. `bpf_trampoline_refresh_prog()` 对 `BPF_TRAMP_REPLACE` 的处理
3. EXT refresh failure 的回滚策略

### 3.2 主要 edge case

#### A. multi-attach EXT

同一个 EXT prog 可以同时 attach 到多个 target；当前单个 `tmp->aux->dst_prog` 只够表达一个 verifier target。

因此 v1 最小修复建议：

- 发现多个 live REPLACE user 直接 `-EOPNOTSUPP`

不要在 v1 里试图“验证一个 target，假设其它 target 兼容”。

#### B. detached EXT

这个方案只修“attached EXT”。

如果 EXT 已经 detach，且 `prog->aux->dst_prog` 又早已被清空，那么：

- 没有 live trampoline
- 也没有 live link
- 就没有可恢复的 target 上下文

这类 detached-after-attach REJIT 仍应拒绝。

#### C. refresh 中途失败

对 EXT 来说这是最需要认真处理的边界。

如果做成“先 swap，再 patch callsite，但失败不 rollback”，会破坏：

1. 后续 detach
2. target-side 实际执行路径
3. `prog->bpf_func` 与 live callsite 的一致性

所以 EXT 必须在 refresh failure 上走 rollback。

#### D. 跨架构 `JUMP -> JUMP` text_poke

本仓库内核树里，至少这些实现都按“old/new branch image”生成 patch：

- x86: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:621-681`
- arm64: `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:3037-3098`
- riscv: `vendor/linux-framework/arch/riscv/net/bpf_jit_comp64.c:855-887`
- s390: `vendor/linux-framework/arch/s390/net/bpf_jit_comp.c:2415-2465`

所以从接口形态上看，`BPF_MOD_JUMP -> BPF_MOD_JUMP` 是合理的。

但仍然建议在实际 guest 架构上做验证；不要只靠代码阅读假设所有后端都完全等价。

### 3.3 不解决的风险

这个方案**不**解决：

- target prog 自己被 REJIT 时，inbound BPF trampoline refresh 缺失的问题

也就是说，本文修的是：

- “attached EXT prog 自己做 REJIT”

不是：

- “被 freplace/fentry/fexit attach 的 target prog 做 REJIT”

后者仍是独立问题。

## 4. 建议测试

按仓库约束，这些都应在 VM 内跑，不在 host kernel 上做。

### 4.1 必跑正向验证

1. 现有 `tests/unittest/rejit_hotswap_ext.c`
   - 目标：从当前 FAIL 变成 PASS
   - 这应是本修复最直接的验收标准

2. attached EXT identity REJIT
   - attach 后做一次 identity `BPF_PROG_REJIT`
   - 验证 syscall 成功，功能不变

3. attached EXT patched REJIT
   - attach 后改返回值
   - `BPF_PROG_TEST_RUN` target prog 观察到新行为

4. attach 后 detach
   - 成功 REJIT 后 destroy link
   - 验证 unlink 不失败
   - 这是检查 REPLACE callsite 是否真的切到 current `prog->bpf_func`

### 4.2 必跑负向验证

1. multi-attach EXT + REJIT
   - 同一个 EXT attach 到两个 target
   - `BPF_PROG_REJIT` 预期返回 `-EOPNOTSUPP`

2. detached EXT + REJIT
   - attach 后 detach，再 REJIT
   - 预期仍不支持
   - 这样能把本 patch 的支持边界写清楚

### 4.3 建议增加的回归测试

1. reattach-to-new-target 后 REJIT
   - EXT load 到 target A
   - attach 到 target B（通过 link_create 指定 `tgt_prog_fd + btf_id`）
   - REJIT 成功
   - 这能验证 REJIT 用的是 live trampoline key 里的 `btf_id`，不是 stale `prog->aux->attach_btf_id`

2. 现有 fentry/trampoline 回归
   - 确认普通 `bpf_trampoline_update()` 路径没被影响

3. unattached freplace REJIT
   - 确认原有“freshly loaded、未 attach 的 EXT”路径不回归

## 5. 最终建议

如果目标是“最小改动让 attached EXT 支持 live REJIT”，我建议按下面顺序做：

1. 去掉 `bpf_prog_rejit_supported()` 对 attached EXT 的早期拒绝
2. 在 REJIT 路径给 `tmp` 增加 **live target 恢复 helper**
   - 来源：`trampoline_users + tr->key`
   - 恢复：`dst_prog + live attach_btf_id`
3. 给 `bpf_trampoline_refresh_prog()` 增加 **REPLACE 专用 refresh**
   - `JUMP old_ext -> JUMP new_ext`
4. 对 EXT refresh failure 改成 **rollback**
5. v1 明确拒绝 multi-attach EXT REJIT

这样改的优点是：

1. 不碰 verifier 主逻辑
2. 不改 attach/detach 正常语义
3. 不需要引入新的 link reverse index
4. 能把 hotswap EXT 的当前 FAIL 直接变成 PASS

从工程角度看，这是当前内核树里“足够小、但语义完整”的修法。
