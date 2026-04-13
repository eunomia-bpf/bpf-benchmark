# Refactor Review v2 (2026-04-12)

## 背景

审查 git diff 中的 20 个文件改动，重点关注有无实际价值、是否过度工程化、以及若干具体疑点。

---

## 一、保留的改动（有价值）

### 1. `runner/libs/app_runners/scx.py` — SCX live program discovery

**状态：保留**

**理由：** 这是一个真实的 bugfix。问题根源：scx_rusty 在 `refresh_programs()` 时，如果 scheduler 已经卸载了旧程序并加载了新版本，用 `/proc/<pid>/fd` 只能找到当前 owner 持有的 FD，新加载的 struct_ops 程序如果 PID 没变但 ID 变了就会漏掉。`_discover_live_scheduler_programs()` 通过 bpftool 全局扫描 struct_ops + 按程序名过滤 + 合并 owner 信息，可以正确找到 live 程序。`require_owner=False` 在 refresh 时允许找到无 FD 的程序是合理的（只需要 ID 做追踪，不需要 dup FD）。`_remember_scheduler_programs` 缓存名字集合也合理。

### 2. `runner/libs/app_runners/tracee.py` — ENODATA 处理

**状态：保留**

**理由：** 真实 bugfix。tracee 通过 FIFO/pipe 传日志，在特定内核版本下 `readline()` 会抛 `OSError(ENODATA)` 而非返回 `""`。之前代码没有捕获这个异常，会导致整个 output collector 线程崩溃。加上 `errno.ENODATA` 处理后行为等同于 EOF/空行，是正确的。

### 3. `runner/libs/workload.py` — `_ensure_null_blk_device_node`

**状态：保留**

**理由：** 真实 bugfix。KVM guest 里 `null_blk` 模块加载后，`/dev/nullb0` 设备节点可能不存在（guest devtmpfs 没自动创建），原来的 `_wait_for_block_device` 只等 `/dev/nullb0` 出现，但如果设备节点根本没被 udev/devtmpfs 创建就会永久超时。新代码通过读 sysfs major:minor 然后手动 `mknod` 是正确的低级修复。

### 4. `runner/libs/input_generators.py` — `meta_b_key` 修复

**状态：保留**

**理由：** 一行 bugfix。原代码当 `meta_b_key == "seed"` 时返回 `header_b`（LCG 中间值），应该返回原始 seed。逻辑错误，修复正确。

### 5. `runner/containers/runner-build.Dockerfile` — 手动安装 Go tarball

**状态：保留**

**理由：** 必要的修复。Tetragon 的 `go.mod` 要求 Go 1.26.0（`go 1.26.0` 行），RockyLinux 9 的 `golang` 包版本通常是 1.21.x，无法满足要求，会导致 tetragon 编译失败。手动从 go.dev 下载指定版本的 tarball 是标准做法（参考 Docker 官方 Go image 的做法）。`ARG GO_VERSION=1.26.0` + `ARG TARGETARCH` 的实现方式干净。

### 6. `runner/containers/runner-runtime.Dockerfile` — 新增 glog/libevent/curl

**状态：保留**

**理由：** 与 build.mk 的 katran 改动配合：katran_server_grpc 现在链接到系统 `/usr/lib64/libglog.so` 和 libevent，runtime 容器里必须有这些包。`curl-minimal` 也是新的 katran deps 安装脚本可能调用的，保留合理。

### 7. `runner/mk/build.mk` — Katran CMake 链接系统库

**状态：保留（部分）**

**理由：** katran 的 `folly-targets.cmake` 里硬编码了 gflags_static 等静态库路径，这在运行时容器里不存在。用 `sed` 替换成 `/usr/lib64/libgflags.so` 是个 workaround，但在没有更好方案的情况下是合理的。`-DLIBELF=/usr/lib64/libelf.so -DGLOG_LIBRARY=...` 等 CMake 参数也正确对应 RockyLinux 9 的实际路径。

### 8. `runner/mk/build.mk` — cache stamp 机制（BCC / Tetragon / Katran / workload-tools）

**状态：保留，但见下方风险注意**

**理由：** 当 build image 更新（比如 Dockerfile 改了）但 make prerequisite 文件没变时，原来的代码不会重新编译，导致用旧容器构建的产物留在缓存里。用 docker image ID 作 cache key 是正确的思路。

### 9. `runner/mk/build.mk` — `luajit` symlink 修复

**状态：保留**

**理由：** sysbench 的 luajit 构建后产出 `luajit-2.x.x` 这样的版本化二进制，但 wrk 构建时需要 `luajit` 这个名字。自动找到版本化二进制并创建 symlink 是正确修复。

### 10. `Makefile` — `VM_MICRO_BENCH_ARGS` 多值 `--bench`

**状态：保留**

**理由：** 原来 `BENCH` 只能传单个值，`$(if ...,--bench "$(BENCH)",)` 无法支持 `BENCH=a,b,c`。新实现用 `$(foreach)` 展开逗号分隔的 bench 名字，允许一次跑多个 bench，功能改进。

### 11. `Makefile` — `check` target 加更多模块

**状态：保留**

**理由：** 增加了更多 Python 文件的语法检查覆盖面，低成本高价值。

### 12. `Makefile` — ARM64 kernel build 的 stale object 清理

**状态：保留**

**理由：** 修复了 incremental build 时 0 字节 `.o` 文件导致 `vmlinux.a` 链接失败的问题，这是已知的 kernel cross-compile 问题。

### 13. `runner/suites/_common.py` — TMPDIR 透传到 runtime container

**状态：保留**

**理由：** Guest 里 TMPDIR 可能指向特定路径（比如 `/dev/shm` 或非默认位置），不透传的话 container 内的工具会用默认 `/tmp`，可能导致空间不足。透传 TMPDIR/TMP/TEMP 是标准做法。

### 14. `e2e/cases/scx/case.py` — 加 `programs` key

**状态：保留**

**理由：** `artifacts` 里原来只有 `scheduler_programs`，加一个 `programs` 别名保持向后兼容，无害。

---

## 二、建议 Revert 的改动（不必要）

### 1. `runner/suites/_common.py` — `suite_runtime_ld_library_path` 收窄 + 去掉环境 LD_LIBRARY_PATH 继承

**状态：建议谨慎，高风险**

**理由：**
- 去掉了 `katran/lib64`、`katran/lib`、`tracee/lib`、`bcc/libbpf-tools/lib`、`workload_root/lib` 这些路径
- 去掉了对外部 `os.environ.get("LD_LIBRARY_PATH")` 的继承
- 理论上：build.mk 已经改成链接 `/usr/lib64` 系统库，katran_server_grpc 应该不再需要 install_root lib
- 实际上：katran 的 `ManagedProcessSession` 启动时用 `os.environ.copy()`，它自身不读 `LD_LIBRARY_PATH` from suite env，而是从进程环境里继承；如果进程启动时 `LD_LIBRARY_PATH` 不对，katran 会找不到 glog/gflags。
- 重要：这个改动的正确性**完全依赖** build.mk 的 katran CMake 参数改动是完整的，即 katran_server_grpc 真的只用系统 lib。如果有任何 lib 没被覆盖到，运行时会崩溃。
- 建议：不 revert，但**必须有完整 e2e 测试验证** katran 能正常运行后才能合入。目前没有记录验证结果。

### 2. `runner/suites/test.env` — 删除 `SUITE_DEFAULT_FUZZ_ROUNDS` 和 `SUITE_DEFAULT_SCX_PROG_SHOW_RACE_*`

**状态：建议 Revert**

**理由：**
- 这些 defaults 在 `suite_args.py` 的 `_env(values, "FUZZ_ROUNDS", "1000")` 等调用里已经有硬编码默认值，所以删掉 `.env` 里的不影响功能
- 但 `.env` 文件是给人看的文档，记录了 suite 的默认参数配置，删掉后降低了可读性和可调试性
- `SUITE_DEFAULT_REMOTE_COMMANDS` 的删除是正确的（下面说），但同时删 FUZZ_ROUNDS 等是多余的清理
- **建议恢复** `SUITE_DEFAULT_FUZZ_ROUNDS`、`SUITE_DEFAULT_SCX_PROG_SHOW_RACE_*` 这几行

### 3. `runner/suites/*.env` — 删除 `SUITE_DEFAULT_REMOTE_COMMANDS`

**状态：可以保留删除**

**理由：** 经过代码追踪，`SUITE_DEFAULT_REMOTE_COMMANDS` 变量在当前代码中没有任何读取点——`suite_args.py`、`run_contract.py`、`suite_commands.py` 都不读这个变量。`aws_executor.py` 里的 `_remote_required_commands()` 是硬编码的，不从 env 读。所以这几个 `.env` 里的 `SUITE_DEFAULT_REMOTE_COMMANDS` 本来就是死代码（可能是旧架构遗留），删了没有功能影响。

### 4. `runner/libs/kvm_executor.py` — KVM guest 自举 dockerd

**状态：建议 Revert**

**理由：**
- 整个逻辑是：如果 guest 里 docker daemon 没在跑，就在 guest 里后台启动一个 dockerd
- **但是**：benchmark 的标准运行模式是把 runtime container image 的 tar 通过 `_artifact_transfer_paths` rsync 到 remote/guest，然后在 guest 里 `docker load` 再 `docker run`。这整个流程要求 dockerd 已经在 guest 里以 service 形式运行（通过 AMI 或 cloud-init 启动），不是 ad-hoc 在 benchmark 运行时启动的
- KVM guest 的 init system 是 systemd，dockerd 应该通过 `systemctl enable docker` 在 AMI 构建时配置好
- 在 guest script 里 ad-hoc 启动 dockerd：(1) 竞争条件：`seq 1 40; sleep 1` 轮询 40 秒太长；(2) 这个 dockerd 没有配置 cgroup driver，可能与 guest kernel 的 cgroup v2 不兼容；(3) docker daemon 的 data-root 放在 `/run/bpf-benchmark-docker/data` 这个 tmpfs 上，guest 重启后所有 image 消失，需要每次重新 load
- 正确做法：在 guest AMI/image 构建时确保 docker service 启用
- **建议 revert** 这个函数，改在 AMI 构建脚本里保证 docker 服务

---

## 三、需要注意的风险点

### 风险 1：LD_LIBRARY_PATH 收窄可能导致 katran/tracee 运行时崩溃

- katran_server_grpc 通过 `os.environ.copy()` 继承启动环境
- `base_suite_runtime_env` 里已经不再设置 `LD_LIBRARY_PATH`，所以 katran 会用系统默认路径
- 这只有在 katran **确实完全链接到 `/usr/lib64/` 系统库** 的情况下才安全
- 必须跑 `make vm-e2e E2E_CASE=katran` 验证

### 风险 2：build.mk cache stamp 的 Katran 条件判断过于复杂

`build.mk` 里 Katran 的 cache stamp 逻辑：如果 stamp 文件不存在，先检查现有 install 是否干净（检查 cmake 文件里是否有 `/usr/lib/...-linux-gnu` 路径），才决定要不要 rm -rf。这个逻辑有点脆弱：
- 如果 cmake 文件格式变化，正则可能匹配不到
- 当判断 "已有产物干净" 时，不 rm -rf 就直接写 stamp 文件，但这样就跳过了重新构建，可能用到过时的 folly/grpc

**建议**：简化成"stamp 不存在就 rm -rf 重建"，不做 cmake 文件内容检查。

### 风险 3：SCX `_discover_live_scheduler_programs` 引入了 bpftool 全局扫描

- 每次 `refresh_programs()` 调用都会跑一次 `bpftool prog show`
- 在高频 refresh 场景下（benchmark 每个 sample 都 refresh）这会增加测量噪声
- 原有的 `/proc/<pid>/fd` 方式只扫描 scheduler 进程，代价低得多
- 应该考虑只在必要时（比如 owned 程序发现数量与缓存不符时）才做全局扫描

### 风险 4：KVM guest dockerd 自举与 rsync 流程的关系

AWS 远端执行的完整流程是：
1. 本地构建 runtime container image → 打包成 tar（`_artifact_transfer_paths` 里包含）
2. 通过 `_rsync_to` 把 tar 传到 remote
3. remote 上 `_common.py` 的 `_ensure_runtime_container_image` 调用 `docker load` 加载 image
4. 然后 `docker run` 跑 suite

rsync 在 AWS 流程里是必须的（传 image tar + 代码），即使 suite 在 container 里跑，**rsync 仍然是传输手段**，不存在冗余。

`kvm_executor.py` 里的 guest dockerd 自举是针对 KVM local 执行路径，但 KVM guest 的 image 是通过 virtio-fs/9p 或 cloud-init 配置的，AMI 应该自带 docker service。这个改动的场景假设（guest 里没有运行 dockerd）应该不应该在正常流程里出现。

---

## 总结

| 类别 | 文件/改动 | 建议 |
|------|-----------|------|
| 确认保留 | scx.py live discovery bugfix | ✓ |
| 确认保留 | tracee.py ENODATA bugfix | ✓ |
| 确认保留 | workload.py nullb0 mknod bugfix | ✓ |
| 确认保留 | input_generators.py seed bugfix | ✓ |
| 确认保留 | runner-build.Dockerfile Go tarball | ✓ |
| 确认保留 | runner-runtime.Dockerfile glog/libevent | ✓ |
| 确认保留 | build.mk katran CMake 系统库参数 | ✓ |
| 确认保留 | build.mk cache stamp (BCC/tetragon/workload-tools) | ✓ |
| 确认保留 | build.mk luajit symlink | ✓ |
| 确认保留 | Makefile VM_MICRO_BENCH_ARGS | ✓ |
| 需验证 | _common.py LD_LIBRARY_PATH 收窄 | 先 e2e 测试再决定 |
| 建议 Revert | test.env 删 FUZZ_ROUNDS/SCX_RACE_* | Revert（文档价值） |
| 建议 Revert | kvm_executor.py ad-hoc dockerd 自举 | Revert（设计不对） |
| 可删除 | *.env 删 SUITE_DEFAULT_REMOTE_COMMANDS | ✓ 无功能影响 |
| 建议简化 | build.mk katran cache stamp 条件判断 | 简化逻辑 |
