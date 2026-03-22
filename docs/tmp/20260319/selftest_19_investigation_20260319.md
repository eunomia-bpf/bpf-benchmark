# Selftest 19 Investigation - 2026-03-19

## Findings

1. `tests/kernel/test_recompile.c` 当前 worktree 里有 **19** 个测试；在 framework kernel 的 VM 里实跑 `make vm-selftest`，结果是 **`PASS all 19 test(s)`**。这不是新的运行时失败。
2. 从 **20 -> 19** 的原因是测试删除/改写，不是新增失败：
   - 删除了 `Recompile Count Increments`
   - 把 `Repeated Recompile Reaches Count Two` 改成了 `Repeated Recompile Succeeds`
3. 这两个变化都直接对应 `recompile_count` 接口被删：旧测试依赖 `bpf_prog_info.recompile_count`，接口删掉后这些断言不再成立。
4. 内核主 UAPI 简化基本干净：`recompile_count` 和 `BPF_F_RECOMPILE_ROLLBACK` 都已从主路径移除，`jit_directives.c` 里也没有再按 rollback flag 分支，`log_level` 现在实际上只当 bool 用。
5. 当前 review 里唯一明确的问题是：`vendor/linux-framework/tools/include/uapi/linux/bpf.h` 仍然没有同步 `BPF_PROG_JIT_RECOMPILE` 和 `union bpf_attr::jit_recompile`，所以主内核 UAPI 和 tools UAPI 镜像仍然不一致。

## Task 1: Selftest 20 -> 19

### 当前测试数量

- 当前 `tests[]` 列表有 **19** 项，见 `tests/kernel/test_recompile.c:2041-2060`。
- 当前运行结果：

```text
PASS all 19 test(s)
```

这是通过 `make vm-selftest` 在 `vendor/linux-framework/arch/x86/boot/bzImage` 上拿到的结果。

### 和之前 20 个测试的对比

对比对象应当是当前仓库 `HEAD` 版本，因为 `tests/kernel/test_recompile.c` 现在是 **未提交 worktree 修改**。

- `HEAD` 版本有 **20** 个测试，见 `git show HEAD:tests/kernel/test_recompile.c`，其中 `tests[]` 列表在 `HEAD:2105-2125`。
- 当前 worktree 相对 `HEAD` 的差异：
  - **删除**: `Recompile Count Increments`
  - **改写/改名**: `Repeated Recompile Reaches Count Two` -> `Repeated Recompile Succeeds`
  - 其他 18 个测试名称和位置保持不变

### 被删/改写的具体原因

#### 1. 被删的测试：`Recompile Count Increments`

- `HEAD` 中旧测试体在 `git show HEAD:tests/kernel/test_recompile.c` 的 `1469-1515`。
- 它做的事情很直接：
  - 读取 `meta.info.recompile_count`
  - 做一次 recompile
  - 再读 `meta_after.info.recompile_count`
  - 断言 `after == before + 1`

这和现在的接口简化目标冲突，因为：

- `recompile_count` 已经从内核内部 aux 结构里删掉
- 也已经从 `struct bpf_prog_info` 里删掉
- `kernel/bpf/syscall.c` 不再导出它
- `bpftool` 也不再打印它

所以这个测试被删是 **合理的**，不是漏测；它测的是一个已经明确删除的观察性接口。

#### 2. 被改写的测试：`Repeated Recompile Reaches Count Two`

- `HEAD` 中旧版本在 `git show HEAD:tests/kernel/test_recompile.c:1866-1915`。
- 旧逻辑也是读 `before = meta.info.recompile_count`，连续 recompile 两次，再断言 `after == before + 2`。
- 当前 worktree 版本在 `tests/kernel/test_recompile.c:1817-1849`，只验证：
  - 第一次 recompile 成功
  - 第二次 recompile 成功

这同样是合理改写，因为保留了“重复 recompile 可成功执行”的行为覆盖，但去掉了已经不存在的 `recompile_count` 断言。

### 结论

- **20 -> 19 不是新失败。**
- 原因是 **1 个 count-based 测试被删除**，另 **1 个 count-based 断言被改写**。
- 在正确的 framework kernel 环境里，当前套件是 **19/19 全通过**。

## Task 2: Quick Review of Current Kernel State

### 改动规模

`git -C vendor/linux-framework diff master --stat`:

- 11 files changed
- `5800 insertions(+), 193 deletions(-)`
- **净改动行数: +5607**

补充：当前未提交的“接口精简” worktree 增量是：

- `git -C vendor/linux-framework diff --stat`
- 6 files changed
- `12 insertions(+), 54 deletions(-)`
- **净变化: -42**

### 1. UAPI 是否干净

#### 主 UAPI / 主内核路径

主路径上，这次精简是干净的：

- `include/uapi/linux/bpf.h`
  - `BPF_F_RECOMPILE_ROLLBACK` 已删
  - `struct bpf_prog_info` 里的 `recompile_count` 已删
  - `jit_recompile.flags` 注释现在明确为 `must be zero`
  - `jit_recompile.log_level` 注释现在明确为 `0 disables, non-zero enables log`
- `include/linux/bpf.h:1731-1734`
  - `recompile_count` 已不在 `struct bpf_prog_aux` 中
- `kernel/bpf/syscall.c:5046-5053`
  - `bpf_prog_get_info_by_fd()` 不再导出 `recompile_count`
- `tools/bpf/bpftool/prog.c:438-444` 和 `523-529`
  - `bpftool` 已不再打印 `recompile_count`

结论：**主内核路径是干净的。**

#### 仍存在的问题：tools UAPI 镜像未同步

这里有一个当前问题：

- 主 UAPI `vendor/linux-framework/include/uapi/linux/bpf.h`
  - `enum bpf_cmd` 已包含 `BPF_PROG_JIT_RECOMPILE` (`996`)
  - `union bpf_attr` 已包含 `jit_recompile` (`2010-2017`)
- 但 tools 镜像 `vendor/linux-framework/tools/include/uapi/linux/bpf.h`
  - `enum bpf_cmd` 仍停在 `BPF_PROG_ASSOC_STRUCT_OPS` (`992-996`)
  - `union bpf_attr` 也没有 `jit_recompile` 成员 (`1919-1925` 后直接结束)

这意味着：

- `include/uapi/linux/bpf.h` 和 `tools/include/uapi/linux/bpf.h` **不是同一份接口**
- vendored tools/userspace header 仍然无法完整表达当前 kernel UAPI

`micro/runner/src/kernel_runner.cpp:67-68` 里的：

```c
#ifndef BPF_PROG_JIT_RECOMPILE
#define BPF_PROG_JIT_RECOMPILE 39
#endif
```

本质上就是在绕过这个 header 不一致问题。

所以如果问题是“UAPI 是否完全干净”，我的结论是：

- **主内核 UAPI：是**
- **整个 vendored UAPI（含 tools 镜像）：还不是**

### 2. `jit_directives.c` 中 rollback 逻辑是否已简化

结论：**是，已简化；但内部 snapshot/restore 机制仍保留。**

当前 `vendor/linux-framework/kernel/bpf/jit_directives.c`：

- `2966-2967`: `if (attr->jit_recompile.flags) return -EINVAL;`
  - 说明 UAPI 层已经不再接受任何 rollback flag
- `3046`: 仍然先做 `bpf_jit_recompile_snapshot()`
- `3076-3084`: re-JIT 失败时统一 `bpf_jit_recompile_restore(&rollback)`，并恢复旧 policy
- `3092-3096`: custom policy 但 `num_applied == 0` 时，也恢复 pre-recompile image

也就是说：

- **rollback 作为用户可选模式位已经消失**
- **rollback 作为内核内部安全恢复手段仍然保留**

这是合理的简化，不再有“按 flag 选择不同 rollback 行为”的分支。

### 3. `log_level` 是否真的只当 bool 用

结论：**是，当前语义已经是 bool。**

证据：

- `kernel/bpf/jit_directives.c:138-141`
  - 只检查 `!attr->jit_recompile.log_level`
  - 非零就开日志，零就不开
- 旧的 `log->level` 字段已从 `struct bpf_jit_recompile_log` 中删掉
- `tests/kernel/test_recompile.c:800-816`
  - helper 现在直接接收 `bool log_enabled`
  - 写入方式是 `attr.jit_recompile.log_level = log_enabled ? 1 : 0`

因此虽然字段名还叫 `log_level`，但实现和测试都已经把它收缩成了 **boolean enable bit**。

### 4. 有没有新引入的问题

#### 明确问题

1. **tools UAPI 镜像不同步**
   - 这是本次 review 唯一明确的当前问题。
   - 影响不是内核 selftest 失败，而是 **header hygiene / tools-side UAPI 一致性**。

#### 没看到的新 runtime 回归

- 在 framework kernel 的 VM 里，`make vm-selftest` 是 **19/19 PASS**
- 所以这次接口精简 **没有引入新的 selftest 运行时失败**

### 5. 当前内核净改动行数

- 相对 `master`: **+5607**
- 当前未提交接口精简 worktree 增量: **-42**

## Environment Note

直接在当前 host 上运行：

```text
sudo -n ./tests/kernel/build/test_recompile
```

会得到 `9 passed, 10 failed`，但这 **不是** 当前内核代码的有效回归信号，因为 host kernel 是：

```text
Linux 6.15.11-061511-generic
```

而不是 `vendor/linux-framework` 的 framework kernel。很多失败都是 generic kernel 对 `BPF_PROG_JIT_RECOMPILE` 返回 `EINVAL` 导致的。这个调查里，**应以 `make vm-selftest` 的 VM 结果为准**。

## Bottom Line

- `test_recompile.c` 当前是 **19** 个测试。
- 相比之前的 **20**，少掉的是 **`Recompile Count Increments`**。
- `Repeated Recompile Reaches Count Two` 也被合理地改成了 **`Repeated Recompile Succeeds`**。
- 原因是 **`recompile_count` 接口被删**，因此相关断言不再有意义。
- 在 framework kernel 上当前 selftest 是 **19/19 PASS**，所以不是“新失败”。
- 内核主路径的 UAPI / rollback / `log_level` 简化都基本 coherent。
- 当前唯一明确问题是：**`tools/include/uapi/linux/bpf.h` 还没同步到新的 `BPF_PROG_JIT_RECOMPILE` UAPI。**
