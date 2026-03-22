# BpfReJIT 测试目录结构设计

**日期**: 2026-03-22
**作者**: 测试架构审查

---

## 1. 当前状态扫描

### 1.1 tests/ 顶层（直接堆放文件，无子目录分类）

| 类别 | 文件数量 | 示例 |
|------|---------|------|
| 调试脚本（trace_close*.sh）| 11 | trace_close.sh, trace_close2.sh ... trace_close10.sh |
| strace/sysrq 诊断脚本 | 6 | strace_rejit.sh, strace_rejit2.sh, strace_rejit3.sh, sysrq_minimal.sh, sysrq_quick.sh, sysrq_trace.sh, sysrq_trace2.sh |
| verify_fix 验证脚本 | 6 | verify_fix.sh, verify_fix2.sh ... verify_fix5.sh, verify_comprehensive.sh |
| check_* 状态检查脚本 | 5 | check_cgroup.sh, check_cgroup2.sh, check_oom_kprobe.sh, check_state.sh, check_wchan.sh |
| 调试 Python 脚本 | 8 | debug_hang.py, test_double_run.py, test_double_run_norejit.py, test_minimal_hang.py, test_other_subprog.py, test_sleep_timing.py, trace_driver.py, test_perf_debug.py |
| 正式 Python 测试（unittest） | 2 | test_profile_guided_policy.py, test_perf_attach.py |
| 集成测试脚本 | 4 | vm_test_comprehensive.sh, vm_test_daemon_live.sh, run_attach_trigger_test.sh, test_perf_config.sh |
| 辅助工具 | 2 | hold_bpf_prog.c, hold_bpf_prog（编译产物） |
| 二进制数据 | 1 | lbr_input.bin |
| __pycache__ | 1 | 含已删除源文件的 .pyc（test_live_policy_discovery.cpython-312.pyc） |

### 1.2 tests/unittest/

| 文件 | 状态 | 说明 |
|------|------|------|
| rejit_poc.c + 可执行文件 | 正式测试 | 6 个基础 REJIT 功能测试 |
| rejit_safety_tests.c + 可执行文件 | 正式测试 | 20 个安全测试 |
| rejit_prog_types.c + 可执行文件 | 正式测试 | 21 个 prog_type 覆盖测试 |
| rejit_regression.c + 可执行文件 | 正式测试 | 4 个回归测试（deadlock/RCU/kallsyms/test_run） |
| rejit_tail_call.c + 可执行文件 | 正式测试 | tail call REJIT 兼容性测试 |
| rejit_spectre.c | 正式测试源码 | Spectre 缓解 pass 集成测试，**无编译产物，无构建规则** |
| progs/ | 辅助文件 | BPF 对象文件（freplace_ext, freplace_target, struct_ops），含预编译 .bpf.o |

### 1.3 tests/kernel/

| 文件/目录 | 说明 |
|-----------|------|
| test_recompile.c | 主测试驱动程序（用 libbpf，运行在 VM 内） |
| progs/*.bpf.c（16 个） | BPF 被测程序 |
| Makefile | 完整的构建规则（编译 libbpf、BPF 对象、test_recompile 二进制） |
| README.md | 正确描述构建和运行方法 |
| build/ | 构建产物（应在 .gitignore 中） |
| build-arm64/ | ARM64 交叉构建产物（应在 .gitignore 中） |

### 1.4 散落在其他位置的测试文件

| 位置 | 文件 | 状态 |
|------|------|------|
| corpus/tests/test_policy_utils.py | PolicyUtils Python unittest | **放错位置**：测试的是 runner.libs.policy，应在 tests/ 或 runner/tests/ |
| tests/__pycache__/test_live_policy_discovery.cpython-312.pyc | 孤儿 .pyc | **源文件已删除**，只剩 .pyc |
| docs/tmp/analyze_per_form_ablation.py | 一次性分析脚本 | 分析用途，非测试，位置合理 |

---

## 2. 当前的问题

### 问题 1：大量临时调试脚本混入正式测试目录

`tests/` 顶层目前是一个"垃圾桶"。以下文件是 2026-03-22 前后用于调试内核 deadlock 的一次性脚本，问题修复后理应删除：

**应删除（调试脚本，bug 已修复）**：
- `trace_close.sh` ~ `trace_close10.sh`（11 个）— 调试 bpf fd close 行为
- `strace_rejit.sh`, `strace_rejit2.sh`, `strace_rejit3.sh` — strace 辅助
- `sysrq_minimal.sh`, `sysrq_quick.sh`, `sysrq_trace.sh`, `sysrq_trace2.sh` — sysrq 死机诊断
- `verify_fix.sh`, `verify_fix2.sh` ~ `verify_fix5.sh`（6 个）— 逐步验证某个具体 fix
- `check_state.sh`, `check_wchan.sh` — 进程状态检查
- `check_cgroup.sh`, `check_cgroup2.sh`, `check_oom_kprobe.sh` — cgroup/OOM 调试
- `debug_hang.py`, `test_minimal_hang.py`, `test_sleep_timing.py` — hang 调试
- `test_double_run.py`, `test_double_run_norejit.py` — 重复运行行为调试
- `test_other_subprog.py` — subprog hang 调试
- `trace_driver.py` — driver.py hang 追踪
- `test_perf_debug.py`, `test_perf_v2.py`, `test_perf_config.sh` — perf_event_open 调试
- `trace_rejit.sh`, `trace_rejit2.sh` — rejit 追踪

这 30+ 个文件占了 tests/ 的大多数，全部是过去调试 fd-close deadlock 和 hang 问题时产生的，bug 在 b4bd737ef 中修复后已无价值。

### 问题 2：命名不一致

- 正式 unittest（`rejit_poc.c`）放在 `tests/unittest/`
- 正式集成测试（`vm_test_comprehensive.sh`, `vm_test_daemon_live.sh`）放在 `tests/`
- 有些命名为 `test_*`（暗示正式），实则是调试脚本
- `test_perf_attach.py` 是真正的 unittest（检查 perf_event_open），而 `test_perf_debug.py` 和 `test_perf_v2.py` 是调试脚本

### 问题 3：编译产物提交到仓库

- `tests/unittest/` 目录含 5 个可执行文件（`rejit_poc`, `rejit_safety_tests`, `rejit_prog_types`, `rejit_regression`, `rejit_tail_call`）
- `tests/unittest/progs/` 含 3 个 `.bpf.o` 预编译对象
- `tests/kernel/build/` 和 `tests/kernel/build-arm64/` 是完整的构建目录（含 libbpf.a、header、.bpf.o）

这些都应该在 `.gitignore` 中，不应提交。

### 问题 4：tests/unittest/ 缺少构建系统

`tests/unittest/*.c` 文件在各自的注释里给出了手动 `clang` 命令，但没有 Makefile。`rejit_spectre.c` 甚至没有编译产物。Makefile targets 也不包含 `tests/unittest/`，导致：
- CI/CD 无法自动构建这些测试
- `rejit_spectre.c` 实际上从未被运行过（只有源码，无构建规则，不在 Makefile 中）

### 问题 5：corpus/tests/ 的 test_policy_utils.py 放错位置

`corpus/tests/test_policy_utils.py` 测试的是 `runner.libs.policy`（`parse_policy_v3`, `remap_policy_v3_to_live`），不是 corpus 模块。它依赖 `daemon/tests/policy_v3_golden/*.yaml` 的 golden 文件，但这个目录并不存在（`corpus/tests/` 中无法找到 golden 目录）。

### 问题 6：孤儿 .pyc 文件

`tests/__pycache__/test_live_policy_discovery.cpython-312.pyc` 对应的源文件 `tests/test_live_policy_discovery.py` 已被删除，只剩 .pyc。这个 `__pycache__` 目录本身也不应提交。

### 问题 7：vm_test_*.sh 与 Makefile 重叠

`vm_test_comprehensive.sh` 和 `vm_test_daemon_live.sh` 实现了完整的集成测试流程，但 Makefile 中没有对应的目标来驱动它们。它们是手工脚本，不是 CI 入口。`vm_test_daemon_live.sh` 中的 `hold_bpf_prog` helper 路径是硬编码的绝对路径。

### 问题 8：hold_bpf_prog.c 没有构建规则

`tests/hold_bpf_prog.c` 是 `vm_test_daemon_live.sh` 的依赖，但没有 Makefile 规则来构建它（只有预编译的 `tests/hold_bpf_prog` 二进制提交到仓库）。

---

## 3. 设计目标

1. **tests/ 只放"会被 CI 运行"的测试** — 调试脚本移出或删除
2. **构建规则完整** — 每个 .c 文件都有对应 Makefile 目标
3. **不提交编译产物** — 可执行文件、.bpf.o、build/ 目录加入 .gitignore
4. **命名反映层次** — 文件名传递"这是什么类型的测试"
5. **Makefile 是唯一入口** — 所有测试通过 `make` 目标运行

---

## 4. 目标目录结构

```
tests/
├── kernel/                     # 内核 REJIT syscall 自测（需要 VM）
│   ├── Makefile                # 构建 test_recompile + libbpf（现有，保留）
│   ├── README.md               # 构建和运行说明（现有，保留）
│   ├── test_recompile.c        # 主测试驱动（现有，保留）
│   └── progs/                  # 被测 BPF 程序源码（现有，保留）
│       └── *.bpf.c
│
├── unittest/                   # 内核 REJIT API 单元测试（需要 VM）
│   ├── Makefile                # 新增：统一构建所有 rejit_*.c + hold_bpf_prog
│   ├── progs/                  # BPF 辅助对象（现有，保留源码，.o 加入 .gitignore）
│   │   ├── test_freplace_ext.bpf.c
│   │   ├── test_freplace_target.bpf.c
│   │   └── test_struct_ops.bpf.c
│   ├── rejit_poc.c             # 6 个基础 REJIT 功能测试（现有）
│   ├── rejit_safety_tests.c    # 20 个安全测试（现有）
│   ├── rejit_prog_types.c      # 21 个 prog_type 覆盖测试（现有）
│   ├── rejit_regression.c      # 4 个回归测试（现有）
│   ├── rejit_tail_call.c       # tail call 兼容性测试（现有）
│   └── rejit_spectre.c         # Spectre 缓解 pass 测试（现有，需加入构建）
│
├── integration/                # 集成测试（需要 VM，测试组件间协作）
│   ├── vm_daemon_live.sh       # 原 vm_test_daemon_live.sh（重命名）
│   └── vm_comprehensive.sh     # 原 vm_test_comprehensive.sh（重命名）
│
└── helpers/                    # 测试辅助工具（C 源码）
    └── hold_bpf_prog.c         # 原 tests/hold_bpf_prog.c（移动）
```

### Python 测试的位置

| 测试文件 | 当前位置 | 目标位置 | 说明 |
|---------|---------|---------|------|
| test_profile_guided_policy.py | tests/ | tests/python/ | 使用 unittest，测试 runner.libs |
| test_perf_attach.py | tests/ | tests/python/ | 使用 unittest，测试 perf_event_open |
| corpus/tests/test_policy_utils.py | corpus/tests/ | tests/python/ | 放错位置，测试 runner.libs.policy |

```
tests/
└── python/                     # Python unittest（可无需 VM，cargo test 类似）
    ├── test_profile_guided_policy.py   # 测试 runner.libs.profile_guided_policy
    ├── test_perf_attach.py             # 测试 perf_event_open 可用性
    └── test_policy_utils.py            # 测试 runner.libs.policy（从 corpus/tests/ 迁入）
```

---

## 5. 迁移计划

### 阶段一：删除调试垃圾（立即可做）

删除以下文件（全部是 bug 修复后无价值的调试脚本）：

```bash
# trace_close 系列（11 个）
rm tests/trace_close.sh tests/trace_close2.sh tests/trace_close3.sh \
   tests/trace_close4.sh tests/trace_close5.sh tests/trace_close6.sh \
   tests/trace_close7.sh tests/trace_close8.sh tests/trace_close9.sh \
   tests/trace_close10.sh

# strace/sysrq 诊断（7 个）
rm tests/strace_rejit.sh tests/strace_rejit2.sh tests/strace_rejit3.sh \
   tests/sysrq_minimal.sh tests/sysrq_quick.sh \
   tests/sysrq_trace.sh tests/sysrq_trace2.sh

# verify_fix 系列（6 个）
rm tests/verify_fix.sh tests/verify_fix2.sh tests/verify_fix3.sh \
   tests/verify_fix4.sh tests/verify_fix5.sh tests/verify_comprehensive.sh

# check_* 系列（5 个）
rm tests/check_cgroup.sh tests/check_cgroup2.sh tests/check_oom_kprobe.sh \
   tests/check_state.sh tests/check_wchan.sh

# hang 调试脚本（Python）
rm tests/debug_hang.py tests/test_minimal_hang.py tests/test_sleep_timing.py \
   tests/test_double_run.py tests/test_double_run_norejit.py \
   tests/test_other_subprog.py tests/trace_driver.py \
   tests/test_perf_debug.py tests/test_perf_v2.py tests/test_perf_config.sh

# trace_rejit 系列
rm tests/trace_rejit.sh tests/trace_rejit2.sh

# 孤儿 .pyc 和 __pycache__
rm -rf tests/__pycache__

# lbr 调试数据
rm tests/lbr_input.bin

# run_attach_trigger_test.sh（功能已由 Makefile vm-corpus 覆盖，且硬编码了绝对路径）
rm tests/run_attach_trigger_test.sh
```

删除后 tests/ 顶层只剩：`kernel/`, `unittest/`, `hold_bpf_prog.c`, `hold_bpf_prog`（二进制）, `vm_test_comprehensive.sh`, `vm_test_daemon_live.sh`, `test_profile_guided_policy.py`, `test_perf_attach.py`

### 阶段二：清理编译产物

将以下内容加入 `.gitignore`（如尚未加入）：

```gitignore
# tests/ 编译产物
tests/unittest/rejit_poc
tests/unittest/rejit_safety_tests
tests/unittest/rejit_prog_types
tests/unittest/rejit_regression
tests/unittest/rejit_tail_call
tests/unittest/rejit_spectre
tests/unittest/hold_bpf_prog
tests/unittest/progs/*.bpf.o
tests/unittest/build/
tests/kernel/build/
tests/kernel/build-arm64/
tests/hold_bpf_prog
```

然后从 git 仓库中移除已提交的产物：

```bash
git rm --cached tests/unittest/rejit_poc tests/unittest/rejit_safety_tests \
    tests/unittest/rejit_prog_types tests/unittest/rejit_regression \
    tests/unittest/rejit_tail_call tests/hold_bpf_prog \
    tests/unittest/progs/test_freplace_ext.bpf.o \
    tests/unittest/progs/test_freplace_target.bpf.o \
    tests/unittest/progs/test_struct_ops.bpf.o
```

注意：`tests/kernel/build/` 和 `tests/kernel/build-arm64/` 已在当前 `.gitignore` 中（需确认），若未加入需补充。

### 阶段三：创建目录并迁移文件

```bash
# 创建新目录
mkdir -p tests/integration tests/helpers tests/python

# 迁移集成测试
mv tests/vm_test_daemon_live.sh tests/integration/vm_daemon_live.sh
mv tests/vm_test_comprehensive.sh tests/integration/vm_comprehensive.sh

# 迁移辅助工具
mv tests/hold_bpf_prog.c tests/helpers/hold_bpf_prog.c

# 迁移 Python 单元测试
mv tests/test_profile_guided_policy.py tests/python/
mv tests/test_perf_attach.py tests/python/
mv corpus/tests/test_policy_utils.py tests/python/
rmdir corpus/tests  # 删空目录

# 修复 test_policy_utils.py 中的路径引用
# 原来引用: ROOT_DIR = Path(__file__).resolve().parents[2]
# 迁移后: ROOT_DIR = Path(__file__).resolve().parents[2]（同级 parents[2] 仍指向项目根，无需修改）
```

### 阶段四：为 tests/unittest/ 添加 Makefile

创建 `tests/unittest/Makefile`，统一构建所有 `rejit_*.c`：

```makefile
ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
UNITTEST_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
BUILD_DIR ?= $(UNITTEST_DIR)/build

CC ?= cc
CFLAGS ?= -O2 -g -Wall -Wno-\#warnings
INCLUDES := -isystem $(ROOT_DIR)/vendor/linux-framework/include/uapi

TESTS := rejit_poc rejit_safety_tests rejit_prog_types \
         rejit_regression rejit_tail_call rejit_spectre

BPF_PROGS_DIR := $(UNITTEST_DIR)/progs
BPF_SRCS := $(wildcard $(BPF_PROGS_DIR)/*.bpf.c)
BPF_OBJS := $(patsubst $(BPF_PROGS_DIR)/%.bpf.c,$(BUILD_DIR)/progs/%.bpf.o,$(BPF_SRCS))

.PHONY: all clean run tests

all: $(addprefix $(BUILD_DIR)/,$(TESTS)) $(BPF_OBJS)

$(BUILD_DIR)/%: $(UNITTEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< -lpthread

$(BUILD_DIR)/progs/%.bpf.o: $(BPF_PROGS_DIR)/%.bpf.c | $(BUILD_DIR)/progs
	clang -O2 -g --target=bpf $(INCLUDES) -c $< -o $@

$(BUILD_DIR) $(BUILD_DIR)/progs:
	mkdir -p $@

run: all
	@for t in $(TESTS); do \
	    echo "=== $$t ==="; \
	    sudo $(BUILD_DIR)/$$t || exit 1; \
	done

clean:
	rm -rf $(BUILD_DIR)
```

### 阶段五：添加 helpers/Makefile

```makefile
ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
HELPERS_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
BUILD_DIR ?= $(HELPERS_DIR)/build

LIBBPF_A ?= $(ROOT_DIR)/micro/build/vendor/libbpf/obj/libbpf.a
LIBBPF_PREFIX ?= $(ROOT_DIR)/micro/build/vendor/libbpf/prefix

.PHONY: all clean hold_bpf_prog

all: $(BUILD_DIR)/hold_bpf_prog

$(BUILD_DIR)/hold_bpf_prog: $(HELPERS_DIR)/hold_bpf_prog.c | $(BUILD_DIR)
	$(CC) -O2 -g -I$(LIBBPF_PREFIX)/include \
	    -o $@ $< $(LIBBPF_A) -lelf -lz -lzstd -lpthread

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)
```

### 阶段六：更新根 Makefile

在根 `Makefile` 中：

1. 增加 `unittest-tests` 目标：
```makefile
unittest-tests:
    @echo "=== Running make unittest-tests ==="
    $(MAKE) -C tests/unittest run
```

2. 增加 `python-tests` 目标：
```makefile
python-tests:
    @echo "=== Running Python unit tests ==="
    $(VENV_ACTIVATE) python3 -m pytest tests/python/ -v
```

3. 更新 `check` 目标以包含 `python-tests`：
```makefile
check:
    @echo "=== Running make check ==="
    $(MAKE) all
    $(MAKE) daemon-tests
    $(MAKE) python-tests
    $(MAKE) smoke
```

4. 更新 `KERNEL_SELFTEST` 的引用，以及 vm-selftest 的 `hold_bpf_prog` 路径（改为 `tests/helpers/build/hold_bpf_prog`）。

5. 在 help 中更新描述：
```
  make unittest-tests   - Build+run tests/unittest/ (requires VM + REJIT kernel)
  make python-tests     - Run Python unit tests (no VM needed)
```

### 阶段七：修复 integration/ 脚本中的硬编码路径

`tests/integration/vm_daemon_live.sh` 中有：
```bash
sudo ./tests/hold_bpf_prog micro/programs/load_byte_recompose.bpf.o 120 &
```
需改为：
```bash
HOLD_PROG="${ROOT_DIR}/tests/helpers/build/hold_bpf_prog"
sudo "$HOLD_PROG" "${ROOT_DIR}/micro/programs/load_byte_recompose.bpf.o" 120 &
```

---

## 6. 迁移后目录结构一览

```
tests/
├── kernel/                     # BPF_PROG_JIT_RECOMPILE 内核自测（VM）
│   ├── Makefile
│   ├── README.md
│   ├── test_recompile.c
│   └── progs/
│       └── *.bpf.c（16 个）
│
├── unittest/                   # REJIT syscall API 单元测试（VM，CAP_BPF）
│   ├── Makefile                # 新增
│   ├── progs/
│   │   └── *.bpf.c（3 个，.bpf.o 在 .gitignore 中）
│   ├── rejit_poc.c
│   ├── rejit_safety_tests.c
│   ├── rejit_prog_types.c
│   ├── rejit_regression.c
│   ├── rejit_tail_call.c
│   └── rejit_spectre.c
│
├── integration/                # 端到端集成测试（VM）
│   ├── vm_daemon_live.sh       # daemon enumerate/rewrite/apply 集成
│   └── vm_comprehensive.sh    # 多 BPF 程序 + 多场景综合测试
│
├── python/                     # Python 单元测试（无需 VM）
│   ├── test_profile_guided_policy.py
│   ├── test_perf_attach.py
│   └── test_policy_utils.py
│
└── helpers/                    # 测试辅助工具
    ├── Makefile
    └── hold_bpf_prog.c
```

---

## 7. 摘要：问题 vs 解决方案

| 问题 | 解决方案 |
|------|---------|
| 30+ 调试脚本混入正式测试 | 全部删除（bug 已修复，无价值） |
| unittest/ 无构建规则 | 新增 tests/unittest/Makefile |
| rejit_spectre.c 从未被构建 | 加入 unittest/Makefile |
| 编译产物提交到仓库 | .gitignore + git rm --cached |
| corpus/tests/test_policy_utils.py 放错位置 | 迁移到 tests/python/ |
| hold_bpf_prog.c 无构建规则 | 新增 tests/helpers/Makefile |
| integration 脚本硬编码路径 | 改用 ROOT_DIR 相对路径 |
| python tests 未接入 make check | 新增 python-tests 目标并接入 check |
| 孤儿 .pyc 文件 | 删除 __pycache__，加入 .gitignore |
| tests/ 顶层文件散乱 | 按职责分入 4 个子目录 |

---

## 8. 不需要动的部分

- `daemon/src/` 中的 `#[cfg(test)]` 模块 — Rust 惯例，`cargo test` 已覆盖
- `micro/`, `corpus/`, `e2e/` 中的 benchmark 驱动脚本 — 不是测试，是 benchmark 框架
- `tests/kernel/Makefile` — 已经完善，无需修改
- `tests/kernel/README.md` — 内容准确
