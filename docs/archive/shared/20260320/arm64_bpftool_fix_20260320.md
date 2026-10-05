# ARM64 bare metal `bpftool` blocker fix report (2026-03-20)

## 结论

- 根因确认：AWS t4g.micro 上的 Amazon Linux 2023 自带 `bpftool` 不支持 `bpftool prog loadall ... kernel_btf ...`，因此上次 smoke 中用于给 `scanner enumerate --prog-id` / `BPF_PROG_JIT_RECOMPILE` 准备 live prog id 的 loadall 步骤先失败了。
- 额外发现：这台机器上的同一版 `bpftool` 也不支持 `autoattach`。所以 `kernel_btf` 只是第一个 blocker，不是唯一 blocker。
- 已实施的最小修复：在 [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py) 中把 `bpftool prog loadall` 改成能力感知的 fallback。
  - 先尝试带 `kernel_btf`
  - 如果 stderr 明确表明该参数不受支持，则自动重试不带 `kernel_btf`
- 实机验证结果：
  - `katran` 路径已在 AWS ARM64 上实际跑通 `loadall -> scanner enumerate --prog-id -> scanner enumerate --recompile`
  - `tracee` 仍被 `autoattach` 语法缺失阻塞
  - `tetragon` 去掉 `kernel_btf` 后不再卡在参数解析，但会进入单独的 libbpf/verifier load failure

## 1. 根因分析

### 1.1 scanner/recompile 本身不依赖 `bpftool loadall`

- [runner/libs/recompile.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/recompile.py) 的 live path 直接调用 `scanner enumerate --prog-id <id> --json`
- [scanner/src/cli.cpp](/home/yunwei37/workspace/bpf-benchmark/scanner/src/cli.cpp) 的 enumerate 子命令通过 `BPF_PROG_GET_NEXT_ID` / `BPF_PROG_GET_FD_BY_ID` 打开 live program，并通过 `BPF_PROG_JIT_RECOMPILE` 发起重编译
- 换句话说，真正依赖 `bpftool` 的不是 enumerate/recompile syscall，而是“如何先把对象加载到内核并拿到 prog id”

### 1.2 触发点在 `corpus/driver.py`

仓库里真正把 `bpftool prog loadall` 作为 live-program 准备步骤的，是 [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py)：

- `run_attach_trigger_sample()`：原来拼 `bpftool prog loadall ... kernel_btf ... autoattach`
- `run_compile_only_loadall_sample()`：原来拼 `bpftool prog loadall ... kernel_btf ...`

这和上次 smoke 里“先 loadall，再 enumerate/recompile”的手工流程一致。

### 1.3 为什么之前要传 `kernel_btf`

`kernel_btf` 的意图是给 `bpftool`/libbpf 显式指定 kernel BTF 文件，确保 CO-RE 对象在远端 live load 时能解析内核类型信息。这个参数在较新的 `bpftool` 可用，但 AL2023 机器上的版本不接受。

### 1.4 AWS 实机确认的真实症状

验证机器：

- 实例类型：`t4g.micro`
- Region：`us-east-1`
- profile：`codex-ec2`
- 内核：`7.0.0-rc2+`
- BTF：`/sys/kernel/btf/vmlinux`
- `bpftool`：`/usr/sbin/bpftool v7.1.0 using libbpf v1.1`

`bpftool prog help` 在这台机器上显示的 `load/loadall` 语法只有：

```text
/usr/sbin/bpftool prog { load | loadall } OBJ PATH [type TYPE] [dev NAME] [map ...] [pinmaps MAP_DIR]
```

没有 `kernel_btf`，也没有 `autoattach`。

实测 stderr：

```text
Error: expected no more arguments, 'type', 'map' or 'dev', got: 'kernel_btf'?
```

去掉 `kernel_btf` 后，`tracee` 又命中第二个 parser error：

```text
Error: expected no more arguments, 'type', 'map' or 'dev', got: 'autoattach'?
```

所以之前 smoke 把问题归因到 `kernel_btf` 是对的，但不完整。

## 2. 方案比较

### 方案 A：交叉编译 vendored `bpftool` 并上传远端

优点：

- 理论上可同时解决 `kernel_btf` 和 `autoattach`
- 最接近原始 smoke 流程

缺点：

- 需要额外构建、分发和远端切换二进制
- 比这次实际需要的修复面更大
- 对复现实验环境的稳定性要求更高

### 方案 B：E2E pipeline 完全绕开 `bpftool loadall`

优点：

- 直接贴近 scanner 的真实需求：只要能拿到 live `prog_id` 即可
- 对 compile-only / pinned 流程尤其自然

缺点：

- 需要按 case 重写加载路径
- attach-trigger 类型 case 仍然需要一个稳定的 attach 方案

### 方案 C：做最小能力降级，并把未修复问题分离出来

做法：

- 对 `kernel_btf` 做自动 fallback
- 保持 enumerate/recompile 的 `--prog-id` 路径不变
- 把 `autoattach` 缺失识别为独立后续问题

选择：本次采用方案 C。

原因：

- 能最小化修改面
- 能立刻恢复 compile-only / pinned 的 live enumerate + recompile
- 不会把 `autoattach` 的独立兼容性问题伪装成 scanner 问题

## 3. 实施内容

修改文件：[corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py)

### 3.1 新增 `kernel_btf` 兼容性判定

- `kernel_btf_unsupported(error_text)`
- 识别 `expected no more arguments` / `unknown option` / `unrecognized option` / `invalid argument` 这类 parser 失败

### 3.2 新增统一 loader helper

- `run_bpftool_loadall(...)`
- 首次尝试：

```text
bpftool prog loadall OBJ PIN_DIR kernel_btf BTF ...
```

- 如果确定是 `kernel_btf` 不支持，则自动重试：

```text
bpftool prog loadall OBJ PIN_DIR ...
```

- 同时把每次尝试记录到 `bpftool_attempts`

### 3.3 接入两个样本路径

- `run_attach_trigger_sample()`
- `run_compile_only_loadall_sample()`

这样 compile-only 和 attach-trigger 两类路径都能受益于 `kernel_btf` fallback，但 attach-trigger 仍可能在 `autoattach` 上失败，这一点会被如实保留下来。

本地检查：

```text
python3 -m py_compile corpus/driver.py
```

通过。

## 4. AWS ARM64 实机验证

### 4.1 环境与执行方式

使用要求中的脚本和缓存：

- `source /home/yunwei37/workspace/.venv/bin/activate`
- `scripts/aws_arm64.sh launch`
- `.cache/aws-arm64/` 中已有缓存内核产物

说明：

- `scripts/aws_arm64.sh setup` 在当前工作树会失败，因为本地 `vendor/linux-framework` 存在未提交改动，`make arm64-worktree` 无法安全 checkout
- 为避免碰工作树，我保留 `launch` / `terminate`，并手动复用 `.cache/aws-arm64/` 的缓存内核产物完成远端安装与引导
- 最终验证仍然是在 AWS t4g.micro 的真实 ARM64 bare metal-like 环境完成

关键结果目录：

- `.cache/aws-arm64/results/arm64_bpftool_fix_run_20260320_224958/`

### 4.2 `bpftool` 能力确认

- `results/bpftool_version.txt`
- `results/bpftool_prog_help.txt`

确认：

- `kernel_btf` 不在 `loadall` 语法里
- `autoattach` 也不在 `loadall` 语法里

### 4.3 tracee

结果：

- `loadall_with_kernel_btf/rc = 255`
- `loadall_with_kernel_btf/stderr` 命中 `kernel_btf` parser error
- `loadall_without_kernel_btf/rc = 255`
- `loadall_without_kernel_btf/stderr` 命中 `autoattach` parser error

结论：

- 本次修复可以绕过第一个 blocker
- 但 tracee 这条 attach-trigger 路径仍需解决 `autoattach`

### 4.4 katran

结果：

- `loadall_with_kernel_btf/rc = 255`
- `loadall_without_kernel_btf/rc = 0`
- pinned prog info：`id=62`, `name=balancer_ingress`, `bytes_xlated=23840`, `bytes_jited=14472`
- `scanner enumerate --prog-id 62 --json`：`rc = 0`
- `scanner enumerate --prog-id 62 --recompile --json`：`rc = 0`

关键输出：

- enumerate：`total_sites = 74`
- recompile：`total_sites = 74`, `applied_sites = 6`, `recompile_ok = true`

这条路径证明：

- 在 AWS ARM64 上，只要程序能成功 load/pin 并拿到 `prog_id`
- scanner enumerate 与 `BPF_PROG_JIT_RECOMPILE` 已经可以真实跑通

### 4.5 tetragon

结果：

- `loadall_with_kernel_btf/rc = 255`
- `loadall_without_kernel_btf/rc = 255`

去掉 `kernel_btf` 后不再是参数解析错误，而是进入实际 load 失败：

```text
libbpf: Error in bpf_create_map_xattr(...): Invalid argument(-22). Retrying without BTF.
libbpf: prog 'event_execve': BPF program load failed: Invalid argument
```

结论：

- `kernel_btf` blocker 已经被分离出去
- tetragon 还存在独立的对象加载/验证问题

## 5. 最终结论

本次最简单可行修复是：

- 不引入 vendored `bpftool`
- 不重写 scanner enumerate/recompile 本身
- 只在 `bpftool prog loadall` 的准备步骤上增加 `kernel_btf` fallback

这个修复已经在 AWS ARM64 上实际恢复了 `katran` 的 scanner enumerate + recompile。

还未一并解决的内容：

- `tracee` 的 `autoattach` 兼容性
- `tetragon` 的对象加载失败

如果下一步要把 attach-trigger 路径也全部打通，优先级建议是：

1. 对 attach-trigger case 引入 vendored/newer `bpftool`
2. 或者彻底改为不依赖 `bpftool autoattach` 的 native loader path

## 6. 资源清理

已执行实例回收。

证据：

- `.cache/aws-arm64/results/arm64_bpftool_fix_run_20260320_224958/final_instances.json` 为 `[]`
- 复核 `aws ec2 describe-instances` 后，`us-east-1` / `codex-ec2` 下无 `pending|running|stopping|stopped|shutting-down` 实例
