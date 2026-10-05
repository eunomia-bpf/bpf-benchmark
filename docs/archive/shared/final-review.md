# 代码审查报告（2026-04-12）

## 一、修改文件行数变化表

| 文件 | 原始行数 | 现在行数 | 增减 | 类型 |
|------|---------|---------|------|------|
| Makefile | 268 | 296 | +28 | bugfix + 扩展 |
| e2e/cases/scx/case.py | 755 | 756 | +1 | bugfix |
| runner/containers/runner-build.Dockerfile | 70 | 91 | +21 | 功能改动 |
| runner/containers/runner-runtime.Dockerfile | 45 | 48 | +3 | bugfix |
| runner/libs/app_runners/process_support.py | 210 | 208 | -2 | 清理 |
| runner/libs/app_runners/scx.py | 373 | 427 | +54 | bugfix（功能扩展） |
| runner/libs/app_runners/tracee.py | 524 | 538 | +14 | bugfix |
| runner/libs/aws_executor.py | 510 | 511 | +1 | 重构（净零） |
| runner/libs/input_generators.py | 679 | 679 | 0 | bugfix（单行改动） |
| runner/libs/results.py | 160 | 158 | -2 | 清理 |
| runner/libs/workload.py | 705 | 725 | +20 | bugfix |
| runner/mk/build.mk | 683 | 699 | +16 | bugfix |
| runner/suites/_common.py | 406 | 405 | -1 | 重构 |
| runner/suites/corpus.py | 189 | 189 | 0 | 重构（rename） |
| runner/suites/e2e.py | 183 | 183 | 0 | 重构（rename） |

**新增未跟踪文件（runner/ 下）：**
- `runner/libs/aws_deploy_scripts/install-kernel-arm64.sh`：32 行
- `runner/libs/aws_deploy_scripts/install-kernel-x86.sh`：58 行

---

## 二、runner/ 总代码量变化

- **runner/ .py + .mk 文件（git 跟踪的）**：
  - 修改前：12,975 行
  - 修改后：13,075 行
  - **净增 +100 行**
- **加上新增 shell 脚本（90 行）**：实际净增约 **+190 行**

**结论：代码量是增加的，不是减少。** 用户期望简化，但本轮修改整体是膨胀的，主要原因是新增了 docker 部署路径（`_build_and_push_kernel_image`）替换了原来的 rsync 方式，以及 SCX 程序发现逻辑的扩展。

---

## 三、改动分类

### 纯 Bugfix（行为修复，逻辑不变）

| 文件 | 具体修复 |
|------|---------|
| `e2e/cases/scx/case.py` | artifacts 中补充 `"programs"` 键（与 `"scheduler_programs"` 对齐） |
| `runner/libs/app_runners/tracee.py` | 捕获 `ENODATA` OSError，防止 tracee 输出管道读取崩溃 |
| `runner/libs/input_generators.py` | `header_b_key == "seed"` 时返回 seed 而非 header_b，修正 LCG 元数据 bug |
| `runner/libs/workload.py` | 新增 `_ensure_null_blk_device_node`，修复 nullb0 块设备节点不存在的 race condition |
| `runner/mk/build.mk` | katran 构建修复：移除 `folly_xlog_prefixes`，通过 cmake 参数注入 gflags/glog/elfpath；wrk luajit 符号链接修复 |
| `runner/containers/runner-runtime.Dockerfile` | 补充缺失的 `glog`、`libevent`、`curl-minimal` 运行时依赖 |
| `Makefile` | ARM64 构建：清理零大小 .o 文件和 vmlinux.a 防止增量构建污染；`BENCH` 支持逗号分隔多值 |

### 重构（架构变化）

| 文件 | 重构内容 |
|------|---------|
| `runner/libs/aws_executor.py` | 用 `_build_and_push_kernel_image`（docker save/load）替换 `_sync_kernel_stage`（rsync）；合并 `_setup_kernel_instance` 和 `_setup_instance`；移除 `_verify_remote_base_prereqs` 和 `_require_remote_base_prereqs`（-31 行，但新 docker 路径 +98 行）；`_rsync_to/_from` 改名为 `_sync_to/_from` |
| `runner/libs/aws_deploy_scripts/install-kernel-*.sh` | 新增 docker 容器内运行的内核安装脚本（共 90 行新文件） |
| `runner/containers/runner-build.Dockerfile` | 移除 dnf `golang`，改为从 go.dev 下载指定版本 Go（1.26.0）并支持多架构 |
| `runner/suites/_common.py` | 重命名 `env_with_cross_runtime_ld` → `env_with_suite_runtime_ld`；移除 `LD_LIBRARY_PATH` 中过宽的库目录（katran/tracee/bcc 等），只保留 luajit；base_suite_runtime_env 不再直接设置 `LD_LIBRARY_PATH`；新增 TMPDIR 等环境变量透传到容器 |
| `runner/suites/corpus.py` + `e2e.py` | 跟随 `_common.py` 重命名更新调用 |
| `runner/libs/app_runners/scx.py` | 新增 `_discover_live_scheduler_programs` 和 `_remember_scheduler_programs`，支持 JIT recompile 后 struct_ops 程序 ID 变化时仍能跟踪；`_dup_program_fds` 新增 `require_owner` 参数 |

### 代码清理（无行为变化）

| 文件 | 内容 |
|------|------|
| `process_support.py` | 删除尾部多余空行 |
| `results.py` | 删除尾部多余空行 |
| `workload.py` | 删除尾部空行 |
| `aws_executor.py` | 部分函数调用格式化调整（减少多行展开），净行数为零 |
| `Makefile` | `check` 目标补全所有 runner/ 源文件的 py_compile 列表 |

---

## 四、有没有不必要的改动或遗漏？

### 潜在问题

1. **aws_executor.py 重构方向有争议**：原始 rsync 方式被整体替换为 docker build/save/load 方式，代码量反而增加了 ~67 行（净 +1 行，但新增了 90 行 shell 脚本）。虽然 docker 方式解决了 rsync 依赖和跨架构问题，但复杂度明显上升（build/save/push/load 4 个步骤，加上 symlink 处理）。是否有必要看实际 rsync 的具体失败原因。

2. **scx.py 新增 72 行**：`_discover_live_scheduler_programs` 逻辑相对复杂（两步查找：先按 owner 过滤，再按名字匹配 bpftool 全量输出）。如果只是为了支持 rejit 后 ID 变化，这个逻辑应该审查是否有更简单的实现。

3. **Dockerfile 中手动安装 Go 1.26.0**：Go 1.26 截至 2026-04-12 还未正式发布（当前最新约 1.22.x），这个版本号可能有误，需确认。

4. **`_common.py` 移除宽 LD_LIBRARY_PATH**：这是一个正确方向的简化（防止构建容器库污染运行时），但 corpus/e2e 中的 katran 二进制是否还能正确找到 glog/gflags 等库需要测试验证。

### 遗漏检查

- `runner/suites/test.py`、`runner/suites/micro.env` 等文件在 gitStatus 初始状态显示为修改，但 `git diff HEAD` 中没有变化，说明这些文件与已提交的最新 commit 一致，不在本轮未提交变更中。
- `runner/libs/kvm_executor.py` 同上。

---

## 五、总结

| 维度 | 结论 |
|------|------|
| 代码量 | 净增 **+190 行**（含新 shell 脚本），不是减少 |
| 主要增量来源 | aws_executor.py docker 重构 (+67行净) + scx.py 程序发现扩展 (+54行) + Dockerfile Go安装 (+21行) |
| Bugfix 质量 | tracee ENODATA、nullb0 race condition、input_generators seed、katran cmake 等修复合理，直接对应已知失败场景 |
| 重构质量 | LD_LIBRARY_PATH 收窄方向正确；docker 部署替换 rsync 是功能性变化，复杂度上升需权衡 |
| 风险点 | Go 版本号（1.26.0）疑似错误；katran 运行时库路径移除后需测试验证 |
