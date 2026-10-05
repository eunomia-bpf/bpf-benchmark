# 最小改动 Refactor — 删 suite_args.py + run_target_suite.py，Makefile 接管 dispatch

日期：2026-05-07（v2，原 typed-config v1 替换为这版）

## 目标

**约束**（用户）：
- 不新建任何文件
- 删除/merge 一两个 Python 文件
- Makefile 直接 call VM 管理脚本，参数走 env var
- 最大化 LoC 删除，最小化代码改动

## 删什么

### Delete 1: `runner/libs/suite_args.py` (-88 行)

整个文件删。它的 5 个 export 都有去处：

| 现有函数 | 改去哪 |
|---|---|
| `suite_args_from_env()` | 删，等价逻辑由 `RunConfig.from_env()`（已存在）扩展接收 suite-specific env vars 实现 |
| `csv_tokens()` / `join_csv()` | `_common.py` 已有 `csv_tokens`（重复定义）；`join_csv` 唯一调用点 inline 为 `",".join(...)` |
| `suite_test_mode_from_args()` | 改成访问 `config.test_mode` 字段，函数删 |
| `read_suite_args_file()` / `write_suite_args_file()` | 删；改用既有 `read_run_config_file()` / `write_run_config_file()`（RunConfig 已经 round-trip JSON）|
| `MICRO_BENCHMARK_DEFAULT_*` 常量 | 移到 RunConfig 字段默认值 |

### Delete 2: `runner/libs/run_target_suite.py` (-195 行)

整个文件删。它的责任 Makefile 接：

| 现有职责 | Makefile 怎么干 |
|---|---|
| dispatch by executor (kvm/aws) | `ifeq ($(PLATFORM),kvm) … else …`（Makefile 已有 PLATFORM 变量）|
| 生成 run_token | `RUN_TOKEN := $(shell openssl rand -hex 4)` |
| mkdir control_dir | `mkdir -p .state/runner-contracts/$(RUN_TOKEN)` |
| build_run_config + write JSON | 调 `python -m runner.libs.run_contract write-config $(CONFIG_PATH)`，run_contract 已有 `to_json()` |
| 调 kvm_executor / aws_executor | Makefile 直接 `python -m runner.libs.kvm_executor $(CONFIG_PATH)` 或 `python -m runner.libs.aws_executor run $(CONFIG_PATH)` |
| cleanup-on-failure (preserve control dir) | Makefile 拿 trap 不好做，可放进 kvm_executor.py 的 main()：失败时打印路径 |
| `_parse_benchmark_suites()` parsing "all"/"micro,corpus" | Makefile 直接 `make corpus micro` 顺序执行；不需要 "all" 解析 |
| terminate action | 加一个 `terminate-aws-x86 / -arm64` Make target，调 `python -m runner.libs.aws_executor terminate ...` |

## 改什么（必要修改）

### `Makefile` (+~50 行)

加 dispatch + token + config 写入：

```make
RUN_TOKEN := $(shell openssl rand -hex 4)
CONTROL_DIR := $(ROOT_DIR)/.state/runner-contracts/run.$(TARGET).$(SUITE).$(RUN_TOKEN)
CONFIG_PATH := $(CONTROL_DIR)/run-config.json

# Generate config from current env
$(CONFIG_PATH):
	mkdir -p $(CONTROL_DIR)
	$(PYTHON) -m runner.libs.run_contract write-config $(TARGET) $(SUITE) $@

corpus: $(COMMON_DEPS) $(CONFIG_PATH)
ifeq ($(PLATFORM),kvm)
	$(PYTHON) -m runner.libs.kvm_executor $(CONFIG_PATH)
else ifeq ($(PLATFORM),aws)
	$(PYTHON) -m runner.libs.aws_executor run $(CONFIG_PATH)
else
	$(error unknown PLATFORM=$(PLATFORM))
endif
	rm -rf $(CONTROL_DIR)

terminate-aws-arm64:
	$(PYTHON) -m runner.libs.aws_executor terminate aws-arm64

terminate-aws-x86:
	$(PYTHON) -m runner.libs.aws_executor terminate aws-x86
```

### `runner/libs/run_contract.py` (~+30 / -30 净 0)

- 扩 `RunConfig` 加字段：`samples / warmups / skip_rejit / workload_seconds / keep_failure_artifacts / enabled_passes / enabled_apps / inner_repeat / bench_filter / fuzz_rounds / test_mode`（现在分散在 list[str] 里的）
- 加 CLI entry `python -m runner.libs.run_contract write-config <target> <suite> <output_path>`：从当前 env 构造 RunConfig 并写 JSON
- 删 `suite_test_mode_from_args` 等老接口

### `runner/libs/kvm_executor.py` (~-30)

- 删 `suite_args` 参数 / `read_suite_args_file()` 调用
- 改成读 RunConfig 自己的字段 (`config.samples` 等)
- `suite_command()` 不再接 list[str] suite_args，直接 `config.to_command_args()`

### `runner/libs/aws_executor.py` (~-30)

同上，删 suite_args 通道。

### `runner/libs/suite_commands.py` (~-50)

- 4 个 `build_*_suite_argv` 删 `suite_args: list[str]` 参数
- 改成从 RunConfig 字段构造 argv

### 各 suite (`runner/suites/{corpus,micro,test}.py`) (~-15 each)

- 仍然用 argparse 接收 driver 参数，但**只做容器初始化**
- 启动 driver 时把 RunConfig 传过去（环境变量 `BPFREJIT_RUN_CONFIG_PATH` 或 stdin）
- driver 自己读 RunConfig

### `corpus/driver.py` (~-25)

- `parse_args` 改成只接收 `--config-path`（其余字段从 RunConfig 读）
- 既有 `--samples`/`--warmups`/`--skip-rejit` 字段保留向后兼容（runner suites 还在用 argparse 透传）

## 净 LoC

| 操作 | Δ |
|---|---|
| Delete suite_args.py | −88 |
| Delete run_target_suite.py | −195 |
| Makefile +50 | +50 |
| run_contract.py extend (净 0) | 0 |
| kvm_executor.py 简化 | −30 |
| aws_executor.py 简化 | −30 |
| suite_commands.py 简化 | −50 |
| 3 个 suite (corpus/micro/test) 简化 | −45 |
| corpus/driver.py 简化 | −25 |

**总：净 −413 行**，**0 个新文件**，**2 个 Python 文件删除**

## 实施顺序

每步完成必须过：
- `make corpus PLATFORM=kvm ARCH=x86 SAMPLES=1 BPFREJIT_CORPUS_APPS=tracee/monitor`

不同步：(终点) 还要过：
- `make micro PLATFORM=kvm ARCH=x86 SAMPLES=1 WARMUPS=0 INNER_REPEAT=1`
- `make test  PLATFORM=kvm ARCH=x86 FUZZ_ROUNDS=10`
- AWS 路径在 plan 报告里标 TODO（不在本轮验证）

### Step 1：扩 RunConfig 字段 + 加 write-config CLI
- 改 `runner/libs/run_contract.py`：加新字段 + `python -m runner.libs.run_contract write-config` entry
- 旧 `RunConfig.from_env(suite_args=list[str])` 接口暂时保留（向后兼容）
- 验证：`python -m runner.libs.run_contract write-config x86-kvm corpus /tmp/c.json && cat /tmp/c.json` 输出包含 samples/warmups 字段

### Step 2：让 kvm_executor.py 直接读 RunConfig 字段（不再接 suite_args）
- `kvm_executor.py:run_vm_suite()` 删 suite_args 参数；内部从 `config.samples`、`config.warmups` 等字段读
- `suite_commands.py:build_corpus_suite_argv()` 改成从 RunConfig 字段构造 argv
- 验证：`python -m runner.libs.kvm_executor /path/to/config.json` 直接跑通

### Step 3：删 suite_args.py
- inline 唯一一处 `csv_tokens` 的重复使用
- inline `join_csv` 为 `",".join(...)`
- 删整个文件
- 验证：`python -m runner.libs.run_contract write-config ...` 仍 work

### Step 4：Makefile 接管 dispatch + 删 run_target_suite.py
- Makefile 加 `RUN_TOKEN`、`CONTROL_DIR`、`CONFIG_PATH` 变量
- `corpus:` rule 改成调 kvm/aws executor 直接
- 删 `runner/libs/run_target_suite.py`
- 验证：`make corpus PLATFORM=kvm`、`make micro PLATFORM=kvm`、`make test PLATFORM=kvm` 全过

### Step 5：清理调用方残留
- 各 suite 入口（`runner/suites/{corpus,micro,test}.py`）的 argparse 简化（只留必要字段）
- `corpus/driver.py:parse_args` 简化
- 验证：5 个 make 命令仍 work

## 不在范围

- AWS 路径完整验证（标 TODO，等手动验）
- Container 内 Python 重构（suite layer 还可以更瘦，但留作下一轮）
- micro 的 C++ runner 不动
- CLAUDE.md 文档不动（重构完后单独 commit）
- 不 commit

## codex prompt 摘要

```
执行 docs/tmp/typed_config_refactor_plan_20260507.md 第 1-5 步。
约束：
- 严格按顺序，每步完成必须过 'make corpus PLATFORM=kvm ARCH=x86 SAMPLES=1 BPFREJIT_CORPUS_APPS=tracee/monitor'
- Step 5 前还要过 'make micro PLATFORM=kvm ARCH=x86 SAMPLES=1 WARMUPS=0 INNER_REPEAT=1' + 'make test PLATFORM=kvm ARCH=x86 FUZZ_ROUNDS=10'
- 不允许新建文件
- 不允许 commit
- 不允许动 micro C++ runner
- 不动 CLAUDE.md
- 净 LoC 目标：-400 行左右
报告写到 docs/tmp/typed_config_refactor_executed_20260507.md
```

## 下一轮（不在本 plan）

- AWS 路径同样改造（aws_executor.py 也读 RunConfig 字段，Makefile 直接调）
- 进一步：把 suite_commands.py 整个删，docker run 命令直接放 Makefile
- 进一步：vm.py 也合并进 kvm_executor.py
- 累计可达 −1000+ 行

那一轮等本轮稳定后再做。
