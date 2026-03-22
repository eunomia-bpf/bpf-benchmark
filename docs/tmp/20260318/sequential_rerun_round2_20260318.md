# Sequential Rerun Round 2 (2026-03-18)

## Scope

按顺序执行：

1. Tracee E2E bpftool 修复 + rerun
2. Corpus 干净 rerun
3. 所有剩余改动分组 commit + push

约束：

- 每次启动 VM 前先检查 `ps aux | grep -E 'qemu|vng' | grep -v grep`
- 全程同一时间只允许一个 VM

## Task 1: Tracee E2E bpftool 修复 + rerun

### 1.1 问题确认

guest 内 `/usr/sbin/bpftool` 实际是 Ubuntu wrapper，需要匹配的 `linux-tools-*` 包；但 benchmark 使用的是自编译 framework kernel `7.0.0-rc2-*`，guest 中不存在匹配包，因此之前的 Tracee authoritative rerun 失败。

host 侧可用 bpftool 已确认：

- `/usr/local/sbin/bpftool`
- `micro/build/vendor/bpftool/bpftool`（本轮重新构建得到）

### 1.2 修复内容

主仓库 Tracee/E2E harness 修复：

- `e2e/common/__init__.py`
  - `resolve_bpftool_binary()` 现在优先解析显式 env、vendored bpftool、`/usr/local/sbin/bpftool`，最后才回退到 PATH。
  - 新增 `prepare_bpftool_environment()`，把解析出的 bpftool 写入 `BPFTOOL_BIN`，并把其目录 prepend 到 `PATH`。
- `e2e/run.py`
  - 统一入口启动时先调用 `prepare_bpftool_environment()`，这样 guest 里即使默认 `bpftool` 是 wrapper，也会优先命中 workspace 里的真实二进制。
- `e2e/common/metrics.py`
- `e2e/cases/tracee/case.py`
- `e2e/run_e2e_tracee.py`
  - 所有 `bpftool prog show` 调用都改成显式走 `resolve_bpftool_binary()`，不再依赖 guest PATH 上的 wrapper。

guest 内验证：

- 初始 `which bpftool` 为 `/sbin/bpftool`
- 调用 `prepare_bpftool_environment()` 后，`which bpftool` 变为 `/home/yunwei37/workspace/bpf-benchmark/micro/build/vendor/bpftool/bpftool`

### 1.3 rerun 中发现的第二个 blocker

bpftool 问题修好后，Tracee rerun 不再卡在 wrapper，而是在 guest 内触发内核 WARN + panic：

- `arch/x86/net/bpf_jit_comp.c:893`
- `WARN_ON_ONCE(READ_ONCE(poke->tailcall_target_stable))`
- call trace 落在 trampoline / LSM attach 路径，最终 `Kernel panic - not syncing: Fatal exception in interrupt`

根因：当前 recompile 流程仍会重写已经被 BPF trampoline/LSM attach 使用的 `prog->bpf_func`；trampoline 持有的直接调用目标不会自动重建，因此 live rewrite 后内核状态不一致。

### 1.4 内核 workaround

在 `vendor/linux-framework/kernel/bpf/jit_directives.c` 增加保护：

- 若 `bpf_prog_has_trampoline(prog)` 为真，则直接返回 `-EOPNOTSUPP`
- log 明确说明：attached trampoline program 目前不支持 recompile，需要先 regenerate associated trampoline

这和已有的 `struct_ops` guard 是同一类保护：不是“修 trampoline”，而是先禁止错误重写。

补丁后重新编译 `vendor/linux-framework/arch/x86/boot/bzImage`，新内核构建成功。

### 1.5 Tracee rerun 结果

本轮实际成功跑通的命令使用：

- vendored bpftool
- host 预下载的 Tracee `v0.24.1` binary
- `--skip-setup`，避免 guest 无网络时再次拉取

结果文件：

- `e2e/results/dev/tracee_20260318.json`
- `e2e/results/dev/tracee_20260318.md`

关键元数据：

- `mode = tracee_daemon`
- `policy_summary.configured_programs = 11`
- `policy_summary.fallback_programs = 2`
- `recompile_summary.applied = true`
- `recompile_summary.applied_programs = 11`
- `recompile_summary.requested_programs = 13`

per-workload app throughput delta：

- `exec_storm`: `+5.9733%`
- `file_io`: `+1.6789%`
- `network`: `+2.1984%`

对比旧 authoritative `e2e/results/archive/tracee_authoritative_20260313.json`：

- 旧 `exec_storm`: `+6.2775%`
- 旧 `file_io`: `+6.9997%`
- 旧 `network`: `+1.4359%`

结论：

- `exec_storm` 基本接近旧权威
- `network` 略好
- `file_io` 明显低于旧权威 `+7.00%`

因此本轮 **不提升** 为新的 authoritative，保留旧文件，不执行 `cp -> e2e/results/tracee_authoritative_20260318.json`。

## Task 2: Corpus 干净 rerun

### 2.1 执行

再次确认无其他 VM 后，执行：

```bash
make vm-corpus REPEAT=200
```

结果文件：

- `corpus/results/dev/vm_corpus.json`
- `corpus/results/dev/vm_corpus.md`

### 2.2 结果摘要

新结果：

- `summary.effective_mode = vm`
- `summary.targets_attempted = 152`
- `summary.compile_pairs = 152`
- `summary.measured_pairs = 152`
- `summary.applied_programs = 61`
- `summary.exec_ratio_geomean = 0.9335571461691422`

按 source 分组：

- `calico = 1.06099`
- `katran = 1.57794`
- `linux-selftests = 0.76909`
- `libbpf-bootstrap = 0.79618`
- `suricata = 0.87179`
- `tracee = 1.00074`
- `xdp-tools = 0.87590`
- `xdp-tutorial = 1.00802`
- `real_world_code_size = 1.00000`

对比旧 authoritative `corpus/results/corpus_recompile_authoritative_20260313.json`：

- 旧 `exec_ratio_geomean = 1.0463358483799616`
- 新 `exec_ratio_geomean = 0.9335571461691422`
- 相对旧权威下降约 `10.78%`

结论：

本轮 corpus rerun 明显低于旧 authoritative `1.046x`，因此 **不提升** 为新的 authoritative，不执行 `cp -> corpus/results/corpus_recompile_authoritative_20260318.json`。

## Current Decision

本轮顺序 rerun 的最终判断：

- Tracee：修复完成，rerun 成功，但 `file_io` 明显退化，不晋升 authoritative
- Corpus：rerun 成功，但 overall exec geomean 明显低于旧 authoritative，不晋升 authoritative

换句话说，这一轮的价值主要是：

1. 修掉了 Tracee guest bpftool wrapper 问题
2. 暴露并规避了 trampoline-attached program 的内核 crash 路径
3. 重新确认了当前内核/策略组合下，Tracee 与 Corpus 都还不满足 authoritative 替换条件

## Follow-up For Task 3

下一步把剩余代码和结果按主题分组提交：

- Tracee bpftool/harness 修复
- framework kernel trampoline guard
- 其他已有的 Katran / Tetragon / micro authoritative 变更

若无额外 blocker，完成后直接推送 `origin main`。
