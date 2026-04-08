# VM 管理重构设计文档

本文件是 2026-04-07 某一轮重构时的历史设计快照，不是当前 canonical
runner contract。当前有效的设计、active todo、以及最新重构状态统一以
`docs/tmp/aws_arm64_remote.md` 为准。

日期：2026-04-07

## 1. 现状分析

### 1.1 架构图

```
                         Makefile (vm-test / vm-micro / vm-corpus / vm-e2e)
                              │
                    ┌─────────┴─────────┐
                    ▼                   ▼
           prepare_local_inputs.sh   run_target_suite.sh
           (生成 manifest .env)      (分发到 executor)
                    │                   │
                    ▼                   ├──────────────────┐
           load_run_contract.sh         │                  │
           (560 行 manifest 生成)       ▼                  ▼
                                kvm_executor.sh      aws_executor.sh
                                (72 行)              (158 行)
                                       │                  │
                                       ▼                  ▼
                              run_vm_shell.py → vng   SSH → 远端
                                       │                  │
                                       └──────┬───────────┘
                                              ▼
                                    install_guest_prereqs.sh
                                    validate_guest_prereqs.sh
                                              │
                                              ▼
                                    suite_entrypoint.sh (432 行)
                                    (分发到 test/micro/corpus/e2e)
                                              │
                              ┌───────┬───────┼───────┐
                              ▼       ▼       ▼       ▼
                          vm-selftest  micro   corpus   e2e
                          .sh         /driver  /driver  /driver
                                      .py     .py      .py
```

### 1.2 组件职责

| 组件 | 行数 | 职责 |
|------|------|------|
| `load_run_contract.sh` | 588 | 解析 target/*.env + suite/*.env → 生成 manifest .env（60+ 个变量） |
| `suite_entrypoint.sh` | 432 | 读取 manifest → 验证 prereqs → 分发到对应 Python driver |
| `kvm_local_prep_lib.sh` | 213 | KVM 本地准备：构建 kernel/daemon/tests → 打包 workspace |
| `local_prep_common_lib.sh` | 288 | 共享准备函数：fetch repos、build artifacts、stage modules |
| `aws_local_prep_lib.sh` | ~200 | AWS 准备：类似 KVM prep 但增加 cross-build + bundle 上传 |
| `kvm_executor.sh` | 72 | KVM executor：构建 vng 命令并执行 |
| `aws_executor.sh` | 158 | AWS executor：SSH 上传 bundle + 远端执行 |
| `vm.py` | 199 | Python VM 工具：write_guest_script + build_vng_command + run_in_vm |
| `run_vm_shell.py` | ~100 | Python wrapper：调用 vm.py 的 CLI 入口 |

**总计 shell 编排代码：~2000 行**（不含 ARM64 cross-build 脚本）。

### 1.3 数据流：manifest .env

配置传递用 shell `source` 加载 `.env` 文件，60+ 个 `RUN_*` 变量通过环境传递：

```
runner/targets/x86-kvm.env    ─┐
runner/targets/aws-arm64.env   ├─→ load_run_contract.sh ─→ manifest.env
runner/suites/test.env         │                             (60+ 变量)
runner/suites/corpus.env      ─┘
                                                                │
                                                    source 到每个脚本
```

**问题**：
- 没有 schema 验证 — 拼错变量名静默传空字符串
- 60+ 个变量全部 flat 命名空间，靠 `RUN_` 前缀区分
- `run_contract_prefixed_env_or_default` 通过字符串拼接间接访问变量（`${!env_name:-}`）

### 1.4 KVM vs AWS 路径对比

| 步骤 | KVM | AWS |
|------|-----|-----|
| 准备 | `kvm_local_prep_lib.sh` — 本地构建 + stage | `aws_local_prep_lib.sh` — 同上 + cross-build + bundle |
| 执行 | `kvm_executor.sh` → `run_vm_shell.py` → vng | `aws_executor.sh` → SSH → 解包 |
| Guest 入口 | `suite_entrypoint.sh`（相同） | `suite_entrypoint.sh`（相同） |
| Prereqs | `install_guest_prereqs.sh` + `validate_guest_prereqs.sh` | 相同 |

两条路径 **70%+ 的逻辑重复**（manifest 生成、workspace 打包、prereq 安装、suite 分发），只有 executor 层不同（vng vs SSH）。

## 2. 核心问题

### P1: Shell 编排 vs Python 编排边界模糊

`suite_entrypoint.sh` 本质是一个 432 行的 orchestrator：解析 manifest、验证环境、准备路径、分发到 Python driver。但 Python driver（corpus/driver.py, e2e/driver.py）也在做编排（daemon session、app runner lifecycle、workload 调度）。两层 orchestrator 导致：
- 配置传递断裂（shell 变量 → CLI args → Python argparse）
- 错误处理分散（shell `set -e` vs Python exception）
- 调试困难（哪层出了问题？）

### P2: manifest .env 无 schema 验证

60+ 个变量通过 `source` 注入 shell 环境。没有类型检查、没有必选字段验证（除了散落的 `[[ -n "$VAR" ]] || die`）、没有默认值文档。新增一个变量需要改：target.env + suite.env + load_run_contract.sh + suite_entrypoint.sh，4 个地方。

### P3: 本地准备逻辑过度分散

构建 kernel、daemon、tests、modules 的逻辑分散在 3 个 prep 库（kvm_local_prep_lib.sh、aws_local_prep_lib.sh、local_prep_common_lib.sh）中，通过 shell `source` 组合。每个 suite（test/micro/corpus/e2e）在每个 prep 库中都有一个大 `case` 分支，逻辑高度重复。

### P4: CSV 工具函数过度工程化

`load_run_contract.sh` 和 `local_prep_common_lib.sh` 各自实现了一套 CSV 操作函数（`csv_append_unique`、`csv_merge_unique`、`run_contract_append_csv`、`run_contract_append_csv_list`）。shell 里处理 CSV 本身就不适合，而且两套函数功能重复。

## 3. 重构方案

### 3.1 目标

1. **Shell 只做 VM lifecycle（boot/exec/shutdown）**，不做编排
2. **Python 统一做编排**（manifest 生成、prereq 验证、suite 分发、结果收集）
3. **manifest 从 .env 迁移到 YAML + dataclass**，有 schema 验证
4. **KVM/AWS 共享一个 Executor 抽象**，只有 transport 不同

### 3.2 目标架构

```
Makefile (vm-test / vm-micro / vm-corpus / vm-e2e)
    │
    ▼
runner/orchestrate.py  ← 单一 Python 入口
    │
    ├─ load target + suite config (YAML → dataclass)
    ├─ local_prep(): build kernel/daemon/tests/modules
    ├─ stage_workspace(): 打包 workspace
    │
    ├─ executor.run():
    │   ├─ KVMExecutor: vng 启动 VM → 执行 guest 脚本
    │   └─ AWSExecutor: SSH 上传 bundle → 远端执行 guest 脚本
    │
    └─ guest 脚本（极简 shell）:
        install_prereqs → validate → Python driver
```

### 3.3 分阶段实施

#### Phase 0: 不动架构，收敛重复（短期，低风险）

- [ ] 合并 `kvm_local_prep_lib.sh` 和 `aws_local_prep_lib.sh` 的重复逻辑到 `local_prep_common_lib.sh`
- [ ] 删除 `load_run_contract.sh` 中重复的 CSV 工具函数，统一用 `local_prep_common_lib.sh` 的版本
- [ ] 给 manifest .env 加一个 `validate_manifest.sh`（集中验证所有必选变量，替代散落的 `[[ -n ]] || die`）

#### Phase 1: manifest 迁移到 Python（中期，中风险）

- [ ] 新建 `runner/libs/run_contract.py`：用 dataclass 定义 manifest schema，替代 `load_run_contract.sh`
- [ ] Makefile 调 Python 生成 manifest（YAML），不再用 shell `source`
- [ ] `suite_entrypoint.sh` 从读 .env 改为读 JSON/YAML manifest
- [ ] 删除 `load_run_contract.sh`（588 行）

#### Phase 2: Executor 抽象（长期，大改动）

- [ ] 新建 `runner/libs/executor.py`：`KVMExecutor` + `AWSExecutor`
- [ ] `KVMExecutor` 吸收 `kvm_executor.sh`（72 行）和 `run_vm_shell.py`（~100 行）
- [ ] `AWSExecutor` 吸收 `aws_executor.sh`（158 行）的 SSH 逻辑
- [ ] `suite_entrypoint.sh` 简化为只做 prereq install + 调 Python driver（<50 行）
- [ ] 删除 `kvm_executor.sh`、`aws_executor.sh`

#### Phase 3: 统一 Python 编排（终态）

- [ ] `runner/orchestrate.py` 统一入口：local_prep → stage → executor.run → collect results
- [ ] `suite_entrypoint.sh` 退化为极简 guest bootstrap（<30 行：install prereqs + exec Python）
- [ ] 删除 `kvm_local_prep_lib.sh`、`aws_local_prep_lib.sh` 中的 prep 逻辑（迁入 Python）

### 3.4 风险评估

| Phase | 风险 | 缓解 |
|-------|------|------|
| 0 | 低 — 只合并重复，不改接口 | 每步 `make vm-test` 验证 |
| 1 | 中 — manifest 格式变化 | 保留 .env 兼容层，双写过渡 |
| 2 | 中 — executor 层替换 | KVM 先做，AWS 后做；保留旧脚本作 fallback |
| 3 | 高 — 整体架构迁移 | 最后做，依赖 Phase 1+2 稳定 |

### 3.5 预期收益

| 指标 | 现在 | Phase 3 后 |
|------|------|------------|
| Shell 编排代码 | ~2000 行 | <200 行（guest bootstrap only） |
| manifest 变量 | 60+ flat env vars, 无 schema | Python dataclass, 类型检查 |
| 新增 suite 改动点 | 4 个文件 | 1 个 YAML + 1 个 Python |
| KVM/AWS 代码重复 | ~70% | 0%（共享 Executor 抽象） |
| 调试体验 | shell -x + env dump | Python traceback + structured logging |

## 4. 优先级建议

**当前阶段（论文评估期）**：不动。Shell 编排虽复杂但稳定运行，改它的 ROI 不如论文评估。

**论文提交后**：Phase 0 → Phase 1，大约 2-3 天工作量，删 ~600 行 shell，收益明显。

**开源/upstream 前**：Phase 2 → Phase 3，使项目对外贡献者友好。
