# Audit Review: Git Diff 改动评估 + Dead Code 清理

日期: 2026-04-12

---

## 一、每个改动的评估结论

### 1. Makefile

#### 1a. `VM_MICRO_BENCH_ARGS` — comma-separated BENCH 支持 (+4行)
**结论: 保留**

将 `--bench "a,b"` 拆成 `--bench "a" --bench "b"`。这是真实需求：suite 的 `--bench` 参数是重复标志，不支持逗号分隔传入多个值。改动正确，逻辑简单。

#### 1b. Makefile `check:` 新增文件列表 (+18行)
**结论: 保留**

让 `make check` 覆盖更多 Python 文件。纯维护改动，低风险，无副作用。

#### 1c. ARM64 kernel build — 清理零大小 `.o` 和 `vmlinux.a` (+7行/处，共2处)
**结论: 保留**

解决真实 bug：跨架构 Docker 容器构建时，若宿主机有残留的零大小目标文件（来自不同架构的 QEMU 仿真），`make` 会误判缓存命中，导致 `ar: vmlinux.a: file format not recognized` 错误。清理步骤是必要的，代码量合理。

---

### 2. e2e/cases/scx/case.py — `"programs": runner.programs` (+1行)
**结论: 保留**

`case_common.py` 的 `_program_records_by_id()` 从 `lifecycle_state.artifacts.get("programs")` 取数据（第303行）。`scx/case.py` 之前只存 `"scheduler_programs"` key，导致 `programs` 查不到，policy 上下文缺失。这是真实 bug，单行修复，正确。

---

### 3. runner-build.Dockerfile — Go 手动安装 (+21行)

**结论: 保留，但版本号需关注**

**背景**: Rocky Linux 9 的 `golang` 包当前版本是 1.21（RHEL 9 生命周期），Tetragon/katran 的构建需要 Go 1.22+。之前用 `golang` 包会在 arm64 上因版本过低失败。

**Go 1.26.0 是否存在**: 是，已确认（go.dev/dl 上存在 `go1.26.0`，`go1.26.1`，`go1.26.2`）。

**ca-certificates + curl-minimal**: 是手动下载 Go tarball 的必要依赖，必须。

**TARGETARCH ARG**: 必须，用于在 `docker buildx` 多架构构建时选择正确的 Go 二进制。

结论：逻辑正确，无冗余。

---

### 4. runner-runtime.Dockerfile — 新增三个包 (+3行)

- **`curl-minimal`**: 用于运行时容器内下载资源/健康检查。**评估**: 如果 Tracee 或 katran 的 runtime 不需要在容器内 curl，这包多余。grep 整个 runner/ 未发现 runtime 容器内 curl 调用。**结论: 可疑，但低风险**。
- **`glog`**: katran 链接了 glog（build.mk 中 `-DGLOG_LIBRARY=/usr/lib64/libglog.so`）。runtime 容器需要运行 katran 二进制，所以 glog 是必须的。**结论: 保留**。
- **`libevent`**: grep 整个 runner/ 无 libevent 使用。katran/folly 的某些构建依赖 libevent，但构建时已静态链接。**结论: 可疑**，但 folly 的 fibersched 可能动态链接 libevent，风险低，保留但标注待验证。

---

### 5. process_support.py — 删除末尾空行 (-2行)
**结论: 保留**（无实质影响）

---

### 6. scx.py — live program discovery (+54行)
**结论: 保留，但设计偏复杂**

**问题背景**: SCX rejit 流程中，`refresh_programs()` 在 `REJIT` syscall 后调用。此时内核已加载新版 BPF 程序，新程序的 owner_fd 不再属于旧 scheduler 进程。旧方法只通过 `/proc/<pid>/fd` 找 owner fd，新程序无法找到 → `_dup_program_fds` 抛出异常。

**新方法**:
1. 记住 scheduler 启动时的程序名集合（`scheduler_program_names`）
2. refresh 时通过 `bpftool prog show` 枚举所有 struct_ops 程序
3. 按名字过滤，找出属于该 scheduler 的"活跃"程序
4. 对有 owner_fd 的 dup fd，无 owner_fd 的跳过（`require_owner=False`）

**是否过度工程**: 有替代方案——直接用 `bpftool prog show` 过滤名字，不需要 `_discover_owned_programs` 和 `_remember_scheduler_programs` 两层结构。但当前实现是正确的，且初始启动仍用严格路径（`require_owner=True`），逻辑分层合理。54行中有约20行是辅助函数拆分，不算过度。**结论: 保留**。

---

### 7. tracee.py — ENODATA 处理 (+15行)
**结论: 保留**

**ENODATA 是真实错误**: `errno.ENODATA = 61`，Linux 系统在读取某些特殊文件（如通过 tmpfs 挂载的命名文件、io_uring 等）时会出现 ENODATA。

**具体场景**: Tracee 在容器内写 `events.json`（JSON 行格式）。当 Tracee 进程刚启动或正在 rotate 输出文件时，读操作可能返回 ENODATA。如果不捕获，会抛出 OSError 导致收集线程崩溃，整个 benchmark 失败。

**是否应修根因**: 根因是 Tracee 自身的 IO 行为，不是 runner 能控制的。try/except errno.ENODATA 是正确的防御性处理，类似 `EAGAIN`/`EINTR` 的处理方式。**结论: 保留**。

---

### 8. workload.py — `_ensure_null_blk_device_node` (+21行)
**结论: 保留**

**问题背景**: 在 KVM 虚拟机中，`modprobe null_blk` 成功后 `/dev/nullb0` 设备节点可能不存在——因为 KVM guest 通常不运行 udevd，内核不会自动 mknod 设备节点。之前的 `_wait_for_block_device()` 只等待设备节点出现，在无 udevd 场景下会永远超时。

**新函数**:
1. 等待 sysfs 出现 (`/sys/block/nullb0/dev`)
2. 如果节点已存在且是块设备，直接用
3. 否则读 major:minor 手动 `os.mknod`

**是否 fallback 代码**: 这不是兼容旧接口的 fallback，而是修复真实 bug（无 udev 环境下 null_blk 设备节点缺失）。**结论: 保留**。

---

### 9. build.mk — katran CMake 参数 (+16行)

**结论: 保留（全部必须）**

- **删除 `folly_xlog_prefixes / FOLLY_XLOG_STRIP_PREFIXES`**: folly 的 XLOG 宏在 x86 build 时用路径前缀过滤日志，但在 arm64/容器构建中路径不匹配导致编译错误。删除正确。
- **`sed` 修复 `gflags_nothreads_static` → `/usr/lib64/libgflags.so`**: folly CMake 目标文件引用了静态 gflags 目标，但系统只有动态库。sed 替换是 known workaround，必要。
- **`-DLIBELF` / `-DGLOG_LIBRARY` / `-DGLOG_INCLUDE_DIR` / `-Dgflags_DIR` 等**: 这些是 CMake find_package 路径的显式覆盖，解决 Rocky Linux 9 的库路径非标准问题。全部必要。
- **`-DCMAKE_CXX_FLAGS="-fpermissive"`**: 允许不严格的 C++ 代码通过，folly 有部分代码在新版 GCC 下有警告变错误的问题。必要。
- **`-DCMAKE_AR=/usr/bin/ar` / `-DCMAKE_RANLIB=/usr/bin/ranlib`**: 从 `ar` 改成绝对路径，确保 Docker 容器内找到正确工具。必要。
- **`rm -rf "$$build_root/build"`**: 清理上次构建残留，防止 cmake 缓存冲突。必要。
- **luajit symlink 修复**: 找到实际的 `luajit-*` 二进制并创建 `luajit` 软链接，解决 wrk 找不到 LuaJIT 的问题。必要。
- **container_platform/container_image 变量提前**: 仅顺序调整，无功能变化。**结论: 全部保留**。

---

### 10. _common.py — LD_LIBRARY_PATH 收窄 + 函数改名

#### 10a. `suite_runtime_ld_library_path` 收窄候选路径 (-6行)
**结论: 保留**

**被删除的路径**:
- `repo_root/katran/lib64`, `repo_root/katran/lib`: katran 的 cmake 构建产物中含有 libfolly、libglog 等，这些库与系统库冲突可能导致 tracee/bcc 崩溃。
- `repo_root/tracee/lib`, `repo_root/bcc/libbpf-tools/lib`: 同理，构建容器产物不应暴露给 suite 进程。
- `workload_root/lib`: wrk 的 LuaJIT 在 `lib/luajit/` 子目录，不在 `lib/` 直接目录。

新保留 `workload_root/lib/luajit`，是 wrk 实际需要的路径。合理收窄。

#### 10b. 删除 `os.environ.get("LD_LIBRARY_PATH")` 继承 (-1行)
**结论: 保留**

suite 进程在 Docker runtime 容器中运行，继承宿主机 `LD_LIBRARY_PATH` 可能引入不一致。删除正确。

#### 10c. `base_suite_runtime_env` 删除全局设置 LD_LIBRARY_PATH (-2行)
**结论: 保留**

之前在 `base_suite_runtime_env` 里无条件设置 `LD_LIBRARY_PATH`，现在改为只在 `env_with_suite_runtime_ld` 中按需设置（corpus/e2e 调用时才设置）。更精确。

#### 10d. 函数改名: `env_with_cross_runtime_ld` → `env_with_suite_runtime_ld` (-1改+1)

**结论: 改名合理，但执行不完整，是 BUG**

旧名字 `env_with_cross_runtime_ld` 暗示只处理 cross-compile 的 LD，新名字更准确反映功能（suite 级 LD_LIBRARY_PATH）。改名合理。

**但: `test.py` 未同步更新** — `test.py` 第26行仍 import `env_with_cross_runtime_ld`，而该函数已不存在。已通过 `python3 -c "from runner.suites.test import *"` 验证会抛出 `ImportError`。**test 套件运行时将直接崩溃**。

#### 10e. `run_in_runtime_container` — 传递 TMPDIR 环境变量 (+3行)
**结论: 保留**

runtime 容器不继承宿主机 TMPDIR，导致 Tracee 等组件把临时文件写到 `/tmp`（无 bind mount）。显式传递 `TMPDIR`/`TMP`/`TEMP` 是正确修复。

---

### 11. corpus.py / e2e.py — 改名同步
**结论: 正确，但 test.py 遗漏（见上）**

---

### 12. aws_executor.py — 重构 kernel 部署方式 (大幅改动)

#### 12a. 删除 `_ordered_unique` / `_remote_required_commands` / `_verify_remote_base_prereqs` / `_require_remote_base_prereqs`
**结论: 保留删除**

`_verify_remote_base_prereqs` 通过检查远端机器上的命令列表来验证 AMI 完整性。这是脆弱的防御性代码：如果 AMI 镜像构建正确，这些命令必然存在；如果构建错误，run 时才发现也无法自动修复。现在改用 docker image 部署，不再依赖远端预装命令，前置检查变得多余。

#### 12b. 删除 `_sync_kernel_stage` / `_setup_kernel_instance`，合并进 `_setup_instance`
**结论: 保留删除**

原来的 `_setup_kernel_instance` 是高阶函数，通过回调 `build_kernel_artifacts` 和 `setup_helper` 参数区分 arm64/x86。现在直接在 `_setup_instance` 里 if/elif 分支处理，逻辑更直接，代码量减少。

#### 12c. 新的 `_build_and_push_kernel_image` Docker 部署方式
**结论: 保留**

旧方式：rsync 大量模块文件到远端临时目录 → 远端执行 grubby/dracut 安装脚本。
新方式：本地 docker build 打包 → `docker save | ssh docker load` → 远端容器执行安装脚本。

优点：避免 rsync 大量 `.ko` 文件（可能数百 MB）、原子性更好、不依赖远端有 rsync。

**BUG: `_sync_to` / `_sync_from` 不存在**

在 `_sync_remote_roots` 和 `_sync_remote_results` 中，代码调用 `aws_common._sync_to()` 和 `aws_common._sync_from()`，但 `aws_common.py` 只定义了 `_rsync_to()` 和 `_rsync_from()`，没有 `_sync_to`/`_sync_from`。**这会导致 AWS 套件在 sync 阶段抛出 AttributeError**。

#### 12d. `os.path.dirname(remote_path)` → `str(Path(remote_path).parent)`
**结论: 保留**（等价，更 Pythonic）

---

### 13. aws_remote_host.py — 删除 `_write_root_file` / `cmd_verify_base_prereqs` / `cmd_setup_kernel_x86` / `cmd_setup_kernel_arm64`
**结论: 保留删除**

这些函数是旧的 rsync 部署路径的远端侧，现在换成 Docker 方式后不再调用。`cmd_verify_base_prereqs` 对应的 `verify-base-prereqs` 命令也已从 `_ensure_instance_for_suite` 中删除。全部正确清理。

---

### 14. input_generators.py — `meta_b_key` 修复 (-1+1行)
**结论: 保留**

**旧代码**: `return {"count": count, meta_b_key: header_b}`
**新代码**: `return {"count": count, meta_b_key: seed if meta_b_key == "seed" else header_b}`

**分析**: `header_b_key` 有两个使用场景（见 `input_specs.yaml`）：
1. 默认 `header_b_key: "seed"` → 返回字典应该包含 `"seed": seed`（实际种子值）
2. 自定义 `header_b_key: "stride"` → 返回字典应该包含 `"stride": header_b`（header 第二字段）

旧代码在 `meta_b_key == "seed"` 时返回 `header_b` 而不是 `seed`，在两者相等时无影响，但当显式设置了不同的 `header_b` 时会返回错误值。修复是正确的真实 bug fix。**保留**。

---

### 15. results.py — 删除末尾空行 (-2行)
**结论: 保留**（无实质影响）

---

## 二、确认的 Bug（必须修复）

### Bug 1: `test.py` 使用已删除函数名
- **文件**: `runner/suites/test.py`，第26行
- **问题**: `from runner.suites._common import (..., env_with_cross_runtime_ld, ...)` — 该函数已改名为 `env_with_suite_runtime_ld`
- **影响**: test 套件（`make vm-test`）在 import 时立即崩溃，`ImportError`
- **修复**: 将 test.py 第26行的 `env_with_cross_runtime_ld` 改为 `env_with_suite_runtime_ld`

### Bug 2: `aws_executor.py` 调用不存在的函数
- **文件**: `runner/libs/aws_executor.py`，第400行和412行
- **问题**: 调用 `aws_common._sync_to(...)` 和 `aws_common._sync_from(...)`，但 `aws_common.py` 只有 `_rsync_to` 和 `_rsync_from`
- **影响**: AWS 套件运行时在 sync 文件阶段抛出 `AttributeError: module 'runner.libs.aws_common' has no attribute '_sync_to'`
- **修复**: 在 `aws_executor.py` 中将 `_sync_to` 改为 `_rsync_to`，`_sync_from` 改为 `_rsync_from`，**或**在 `aws_common.py` 中添加别名

---

## 三、旧代码 / fallback / wrapper 扫描结果

### 已被本次 diff 删除（标注为已删）

| 函数 | 文件 | 类型 | 状态 |
|------|------|------|------|
| `_write_root_file` | aws_remote_host.py | 旧部署路径帮助函数 | 已删除 |
| `cmd_verify_base_prereqs` | aws_remote_host.py | 脆弱的前置检查 | 已删除 |
| `cmd_setup_kernel_x86` | aws_remote_host.py | 旧 rsync 部署路径 | 已删除 |
| `cmd_setup_kernel_arm64` | aws_remote_host.py | 旧 rsync 部署路径 | 已删除 |
| `_ordered_unique` | aws_executor.py | prereqs 检查辅助 | 已删除 |
| `_remote_required_commands` | aws_executor.py | prereqs 检查辅助 | 已删除 |
| `_verify_remote_base_prereqs` | aws_executor.py | prereqs 检查 | 已删除 |
| `_require_remote_base_prereqs` | aws_executor.py | prereqs 检查包装 | 已删除 |
| `_sync_kernel_stage` | aws_executor.py | 旧 rsync 内核部署 | 已删除 |
| `_setup_kernel_instance` | aws_executor.py | 旧高阶部署函数 | 已删除 |
| `_staged_modules_root` | aws_remote_host.py | 旧部署路径帮助 | 已删除 |

### 现存但值得关注的残留

| 函数 | 文件 | 问题 | 建议 |
|------|------|------|------|
| `env_with_cross_runtime_ld` | _common.py | **已不存在** — 改名为 `env_with_suite_runtime_ld`，但 test.py 仍引用旧名 | 修复 test.py import |
| `cross_runtime_ld_library_path` | _common.py | 只处理 arm64 cross 场景，被 suite_runtime_ld_library_path 和 micro.py 调用。功能单一但仍有用途 | 保留 |
| `_scp_from` | aws_common.py | 定义了但在 aws_executor.py 中未找到调用者 | 低优先级，不紧急 |

---

## 四、行数统计

| 类别 | +行 | -行 |
|------|-----|-----|
| 新增功能（scx live discovery） | +54 | 0 |
| 新增功能（Docker kernel deploy） | +67 | 0 |
| Bug 修复（tracee ENODATA） | +15 | 0 |
| Bug 修复（workload mknod） | +21 | 0 |
| Bug 修复（input_generators seed） | +1 | -1 |
| Bug 修复（scx programs artifact key） | +1 | 0 |
| 重构/收窄（LD_LIBRARY_PATH 等） | +10 | -12 |
| 删除旧代码（aws_remote_host） | 0 | -63 |
| 删除旧代码（aws_executor prereqs/rsync） | 0 | -35 |
| 配置/Dockerfile（Go安装/packages） | +40 | -1 |
| Makefile 改进 | +34 | -1 |
| 空行清理 | 0 | -4 |
| **合计** | **+243** | **-117** |

净增: +126 行（有效功能代码 ~155 行，删除旧代码 ~117 行）

---

## 五、总结

**需要立即修复的 Bug（2个）**:
1. `runner/suites/test.py:26` — import `env_with_cross_runtime_ld` 改为 `env_with_suite_runtime_ld`
2. `runner/libs/aws_executor.py:400,412` — `_sync_to`/`_sync_from` 改为 `_rsync_to`/`_rsync_from`

**可接受但待验证**:
- `runner-runtime.Dockerfile` 中 `curl-minimal` 和 `libevent` 是否真正需要（风险低，保留无害）

**所有其他改动**: 均是真实 bug 修复或合理的重构，无过度工程化情况。
