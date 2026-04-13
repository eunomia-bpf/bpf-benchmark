# Refactor Review

## 数据来源

- 已运行 `git diff --stat`、`git diff`、`git status --short`。
- 为了补齐统计，还额外查看了 `git diff --name-status`、`git diff --numstat`、`git status --porcelain=v1 -uall`、`git ls-files --others --exclude-standard`。

## 修改概览

以下统计基于写入本报告前的工作区状态，不包含本报告文件 `docs/tmp/refactor-review.md` 自身；报告写入后，当前 status 会额外多出这个新增未跟踪文件。

### 跟踪文件变更

- 跟踪文件修改数: 24
- 跟踪文件新增数: 0
- 跟踪文件删除数: 0
- `git diff --stat` 总行数变化: 347 insertions(+), 87 deletions(-), 净增 260 行

| 文件 | + | - | 状态 |
| --- | ---: | ---: | --- |
| `Makefile` | 31 | 3 | 修改 |
| `docs/remote_machine_aws_skills.md` | 2 | 2 | 修改 |
| `e2e/cases/scx/case.py` | 1 | 0 | 修改 |
| `runner/containers/runner-build.Dockerfile` | 22 | 1 | 修改 |
| `runner/containers/runner-runtime.Dockerfile` | 3 | 0 | 修改 |
| `runner/libs/app_runners/process_support.py` | 0 | 2 | 修改 |
| `runner/libs/app_runners/scx.py` | 63 | 9 | 修改 |
| `runner/libs/app_runners/tracee.py` | 21 | 7 | 修改 |
| `runner/libs/aws_common.py` | 47 | 12 | 修改 |
| `runner/libs/aws_executor.py` | 4 | 4 | 修改 |
| `runner/libs/aws_remote_host.py` | 13 | 4 | 修改 |
| `runner/libs/input_generators.py` | 1 | 1 | 修改 |
| `runner/libs/kvm_executor.py` | 36 | 1 | 修改 |
| `runner/libs/results.py` | 0 | 2 | 修改 |
| `runner/libs/workload.py` | 22 | 2 | 修改 |
| `runner/mk/build.mk` | 63 | 9 | 修改 |
| `runner/suites/_common.py` | 11 | 12 | 修改 |
| `runner/suites/corpus.env` | 0 | 1 | 修改 |
| `runner/suites/corpus.py` | 2 | 2 | 修改 |
| `runner/suites/e2e.env` | 0 | 1 | 修改 |
| `runner/suites/e2e.py` | 2 | 2 | 修改 |
| `runner/suites/micro.env` | 0 | 1 | 修改 |
| `runner/suites/test.env` | 0 | 6 | 修改 |
| `runner/suites/test.py` | 3 | 3 | 修改 |

### 未跟踪新增文件

`git status --short` 还显示 80 个未跟踪文件，属于运行契约和结果产物。它们没有进入 `git diff --stat`，用 `wc -l` 粗略统计为 347,849 行文本内容。

分组如下:

| 分组 | 文件数 | 说明 |
| --- | ---: | --- |
| `.state/runner-contracts/*` | 22 | 11 个 `run.aws-arm64.corpus.*` 契约目录，每个包含 `run-config.json` 和 `suite-args.json` |
| `corpus/results/*` | 12 | 4 个 `x86_kvm_corpus_*` 结果目录，每个包含 `metadata.json`、`result.json`、`result.md` |
| `e2e/results/*` | 46 | bcc、bpftrace、katran、scx、tetragon、tracee 的 E2E 结果目录，包含 `metadata.json`、`result.json`、`result.md`，部分 bcc/bpftrace 目录还包含 `report.md` |

如果把这些未跟踪文本文件也按新增文件计入，则当前工作区共有 104 个已修改或新增文件，新增行约 348,196 行，删除 87 行，净增约 348,109 行。这个合计会被运行结果产物严重放大，代码重构规模更应参考上面的跟踪文件统计。

## 每个修改文件的具体变更说明

### `Makefile`

- 增加 `empty`、`space`、`comma` 辅助变量，并把 `BENCH` 从单个 `--bench` 参数改成逗号拆分后的多个 `--bench` 参数。
- 扩展 `check` 目标的 `py_compile` 覆盖范围，纳入 app runners、bpf stats、case/input helpers、suite commands、workspace layout、suite common 等更多 Python 文件。
- ARM64 本地和 AWS kernel image 构建前新增清理步骤: 创建容器内 HOME/构建目录，删除 0 字节 `*.o`，并移除可能污染重建的 `vmlinux.a`、`vmlinux.o`、`drivers/of/built-in.a`。

### `docs/remote_machine_aws_skills.md`

- 文档将“root 级 rsync”表述改为“root 级同步”。
- 远端落盘建议从 `sudo install` / `sudo rsync` 改为 `sudo install` / `sudo tar`，与代码中 rsync -> tar 的远端同步改造一致。

### `e2e/cases/scx/case.py`

- SCX case 的 lifecycle artifacts 新增 `programs` 键，内容与 `scheduler_programs` 相同。
- 这看起来是兼容旧的通用 program 消费路径，同时保留更语义化的 `scheduler_programs`。

### `runner/containers/runner-build.Dockerfile`

- 新增 `GO_VERSION=1.26.0` 和 `TARGETARCH` build arg。
- 用 `curl-minimal`、`ca-certificates` 加手动下载 `go.dev` tarball 的方式安装 Go，替代 Rocky 包里的 `golang`。
- 根据 `TARGETARCH`/`uname -m` 映射 `amd64` 与 `arm64`，并设置 `PATH=/usr/local/go/bin`、`GOTOOLCHAIN=local`。
- 结果是构建 Go 工具链从发行版包切到固定上游版本，减少发行版版本漂移，但也引入网络下载和版本可用性依赖。

### `runner/containers/runner-runtime.Dockerfile`

- 运行时镜像新增 `curl-minimal`、`glog`、`libevent`。
- 这些包主要服务于运行期工具或 Katran/依赖库场景，补齐构建产物运行时动态库依赖。

### `runner/libs/app_runners/process_support.py`

- 仅删除文件末尾多余空行，没有行为变化。

### `runner/libs/app_runners/scx.py`

- 引入 `resolve_bpftool_binary`、`run_json_command`，新增 `_bpftool_struct_ops_programs()`，通过 `bpftool -j -p prog show` 查询所有 live `struct_ops` BPF programs。
- 将原先 `_discover_programs()` 拆成 `_discover_owned_programs()`，只负责从 scheduler 进程 owner FDs 里找当前进程拥有的 struct_ops programs。
- 新增 `_program_id()`、`_program_name()` 和 `scheduler_program_names`，用 scheduler 启动时拥有的 program name 作为后续 live program 识别依据。
- `__enter__` 健康检查和初始 FD duplication 仍要求 scheduler-owned FD，保证初始加载时有可 dup 的 FD。
- `refresh_programs()` 改为 `_discover_live_scheduler_programs()`，会合并进程拥有的 programs 与全局 bpftool struct_ops 列表；刷新时 `_dup_program_fds(..., require_owner=False)`，遇到非 scheduler-owned live program 时跳过 FD duplication 而不是报错。
- 架构意图是让 SCX 在 rejit 或 reload 后还能观察到同名 live scheduler programs，即使它们不再暴露为原 scheduler 进程的 owned FD。

### `runner/libs/app_runners/tracee.py`

- `TraceeOutputCollector` 新增 `errno` 依赖。
- 读 tracee 输出时对 `OSError(errno.ENODATA)` 做容错: 非停止状态下短暂 sleep 并重试，停止时退出。
- finally 阶段 drain 剩余输出时也忽略 `ENODATA`，但仍会对其他 `OSError` 抛错。
- 这降低了 FIFO/特殊输出源暂时无数据时 collector 线程异常退出的概率。

### `runner/libs/aws_common.py`

- 删除 `_rsync_to()` / `_rsync_from()`，新增基于 tar over ssh 的 `_sync_dir_to()` / `_sync_dir_from()`。
- 新增 `_tar_exclude_args()`，把 excludes 扩展为 `pattern`、`pattern/*`、`*/pattern`、`*/pattern/*` 形式，模拟目录同步排除规则。
- 新增 `_wait_for_pipe()`，等待本地 tar producer 和远端/本地 tar consumer，并在任一端失败时统一 `_die()`。
- `_sync_dir_to()` 会先在远端 `rm -rf dest`，再创建目录并通过 tar 流解包；`_sync_dir_from()` 则从远端 tar 到本地 tar 解包。
- 该文件是远端同步架构变化的核心: 从依赖 rsync 切到只要求 ssh + tar。

### `runner/libs/aws_executor.py`

- `_remote_required_commands()` 移除 `rsync`，保留 `tar`，与 tar 同步改造一致。
- kernel modules staging、remote roots 同步和 results 拉取全部从 `aws_common._rsync_*` 调用切到 `_sync_dir_*`。

### `runner/libs/aws_remote_host.py`

- 新增 `shlex` import 和 `_install_modules_tree()`。
- x86/arm64 kernel setup 安装 `/lib/modules/<version>` 时，从 `sudo mkdir + sudo rsync --delete` 改成先 `sudo rm -rf` 目标，再通过 `sudo sh -c 'tar ... | tar ...'` 拷贝模块树。
- 这让远端 host setup 不再需要 root 级 rsync，和 AWS 同步路径保持一致。

### `runner/libs/input_generators.py`

- `_build_simple_lcg_u64_ii()` 的 metadata 返回逻辑调整: 当 `header_b_key` 是默认 `seed` 时，返回原始 `seed`；只有自定义 `header_b_key` 时才返回 `header_b`。
- 这修正了 metadata 中 `seed` 字段语义，把它从派生后的 header 值恢复为输入 seed。

### `runner/libs/kvm_executor.py`

- 新增 `_guest_runtime_container_prelude()`。
- 当 suite 配置了 `runtime_container_image` 且 runtime 是 `docker` 时，guest script 会先检查 Docker CLI；若 `docker info` 不通，则尝试启动 `dockerd`，使用 `/run/bpf-benchmark-docker/{data,exec}` 作为临时 data-root/exec-root，并等待最多 40 秒。
- `run_vm_suite()` 将 prelude 和 suite command 一起写入 guest script。
- 新架构允许 KVM guest 内的 runtime-container suite 在没有预启动 Docker daemon 时自举 dockerd。

### `runner/libs/results.py`

- 仅删除文件末尾多余空行，没有行为变化。

### `runner/libs/workload.py`

- 新增 `_ensure_null_blk_device_node()`。
- `run_block_io_load()` 加载 `null_blk` 后不再只等待 `/dev/nullb0`，而是先等待 `/sys/block/nullb0/dev`，必要时用 `os.mknod()` 手动创建 block device node，再调用 `_wait_for_block_device()` 验证。
- 这为没有 udev 或设备节点创建滞后的 guest/runtime 环境提供兜底。

### `runner/mk/build.mk`

- BCC 构建新增 runner build image ID + container platform cache stamp；当 stamp 不存在或不匹配时，清理 BCC build output 和 tool 可执行文件，构建成功后写入 stamp。
- Tetragon 构建新增同类 cache stamp；不匹配时清理 build repo、BPF output、Go build cache 和 artifact root。
- Katran 构建新增 cache stamp 与旧 install root 兼容探测；不匹配或探测失败时清理 deps/build/install root。
- Katran 依赖构建后修补 folly CMake targets 中的 `gflags_*_static` 为 `/usr/lib64/libgflags.so`，并显式传入 `LIBELF`、`GLOG_*`、`gflags_DIR`、`GFLAGS_*`、`-fpermissive`、绝对路径 `ar`/`ranlib` 等 CMake 参数。
- Katran 构建在第二阶段前删除 `build_root/build`，避免旧 CMake cache 污染，并在多个阶段写入 cache stamp。
- workload tools 构建新增 image/platform cache stamp；不匹配时清理 work/wrk-luajit/install root。
- workload tools 为 wrk 构建显式寻找 `luajit-*` 可执行文件，并创建 `luajit` symlink，避免 wrk 找不到架构对应 LuaJIT。
- 总体上，build.mk 从“默认复用已有 build tree”转向“按构建镜像 ID 失效缓存”，同时补齐 Katran 和 workload tools 的跨架构/动态库构建约束。

### `runner/suites/_common.py`

- `run_in_runtime_container()` 会把宿主环境中的 `TMPDIR`、`TMP`、`TEMP`、`BPFREJIT_RUNTIME_TMPDIR` 透传到 runtime container。
- `suite_runtime_ld_library_path()` 从宽泛加入 repo artifacts 的 `katran/lib*`、`tracee/lib`、`bcc/libbpf-tools/lib`、`workload-tools/lib`，收窄为只加入 `workload-tools/lib/luajit` 和 arm64 cross unittest lib。
- 新增注释说明避免 build-container 产物库 shadow 系统库。
- `env_with_cross_runtime_ld()` 重命名/替换为 `env_with_suite_runtime_ld()`，实际设置 suite runtime LD，而不是只设置 cross runtime LD。
- `base_suite_runtime_env()` 不再全局设置 `LD_LIBRARY_PATH`，改由需要运行 driver/test 的调用点局部包装 runtime env。

### `runner/suites/corpus.env`

- 删除 `SUITE_DEFAULT_REMOTE_COMMANDS=curl,file,ip,tar,taskset`。
- 当前代码中没有剩余 `SUITE_DEFAULT_REMOTE_COMMANDS` 引用，远端必需命令由 executor 侧逻辑集中处理。

### `runner/suites/corpus.py`

- import 和调用点从 `env_with_cross_runtime_ld` 切换为 `env_with_suite_runtime_ld`。
- corpus driver 运行时使用新的收窄 LD_LIBRARY_PATH。

### `runner/suites/e2e.env`

- 删除 `SUITE_DEFAULT_REMOTE_COMMANDS=curl,file,ip,tar,taskset`。
- 与 corpus 一样，远端命令默认值从 suite env 中移除。

### `runner/suites/e2e.py`

- import 和调用点从 `env_with_cross_runtime_ld` 切换为 `env_with_suite_runtime_ld`。
- e2e driver 运行时使用新的收窄 LD_LIBRARY_PATH。

### `runner/suites/micro.env`

- 删除 `SUITE_DEFAULT_REMOTE_COMMANDS=taskset`。
- 远端命令默认值从 suite env 中移除。

### `runner/suites/test.env`

- 删除 `SUITE_DEFAULT_FUZZ_ROUNDS`、`SUITE_DEFAULT_SCX_PROG_SHOW_RACE_*` 和 `SUITE_DEFAULT_REMOTE_COMMANDS`。
- `FUZZ_ROUNDS` 与 `SCX_PROG_SHOW_RACE_*` 默认值仍存在于 `Makefile` 和 `runner/libs/suite_args.py`，所以这不是功能删除，而是去掉 suite env 里的重复默认值。

### `runner/suites/test.py`

- import 和两个 test runner 调用点从 `env_with_cross_runtime_ld` 切换为 `env_with_suite_runtime_ld`。
- negative suite 返回的 `runtime_ld` 也改为新的 suite runtime LD。

## 架构变化总结

### 远端同步: rsync -> tar over ssh/tar

旧架构依赖本地/远端可用 `rsync`，包括 AWS remote root 同步、kernel modules staging、结果拉取，以及远端 host 上 root 权限安装 `/lib/modules`。

新架构把目录同步统一改为 tar 流:

- 本地到远端: 本地 `tar -C src -cf - .` 通过 ssh 发送到远端 `tar -C dest --no-same-owner -xf -`。
- 远端到本地: 远端 tar 输出，本地 tar 解包。
- root 安装 modules: 远端本机 `sudo sh -c 'tar ... | tar ...'`。
- AWS required commands 删除 `rsync`，保留 `tar`。

收益是减少远端依赖和 root 级 rsync 问题；代价是需要自己维护删除、exclude、失败恢复等语义。

### 运行时库路径: 宽泛全局 LD -> 局部收窄 LD

旧架构在 suite env 中较宽泛地加入 artifact lib 目录，可能让 build container 里的库 shadow guest/host 系统库。

新架构把 `LD_LIBRARY_PATH` 收窄到 suite driver/test 运行点，并且只加入 LuaJIT 专用目录与 arm64 cross unittest lib。`base_suite_runtime_env()` 不再全局设置 LD，corpus/e2e/test 通过 `env_with_suite_runtime_ld()` 局部注入，micro 仍直接使用 cross runtime LD。

### 构建缓存和工具链: 发行版/隐式复用 -> 镜像 ID 感知缓存

旧架构更依赖已有 build tree 与发行版 Go 包。新架构:

- runner build image 固定安装上游 Go tarball，并设置 `GOTOOLCHAIN=local`。
- BCC、Tetragon、Katran、workload-tools 按 active container platform + image ID 写 stamp，镜像变化时清理缓存。
- Katran 构建显式修复/指定系统库和 CMake 参数。
- workload-tools 显式修复 LuaJIT binary symlink。

这会提升跨架构和镜像更新后的可重复性，但增加构建脚本复杂度和外部下载依赖。

### SCX program 发现: owner FD-only -> name-based live struct_ops discovery

旧架构主要通过 scheduler 进程 owner FDs 发现 struct_ops programs，并要求 refresh 时也能 dup 到 scheduler-owned FD。

新架构在初始加载时仍要求 owner FD，但 refresh 时会用 bpftool 查询全局 live struct_ops programs，再按初始 scheduler program names 过滤。这样可以在 rejit/reload 后继续追踪同名 scheduler program，即使 owner FD 不再属于原 scheduler 进程。

### KVM/runtime container: 假设 daemon 可用 -> guest 自举 dockerd

旧架构在 KVM guest 中运行 runtime container 时更依赖 Docker daemon 预先可用。新架构在 guest script 前插入 Docker prelude，必要时启动 dockerd 并等待 ready。

### block_io workload: 依赖设备节点出现 -> sysfs + mknod 兜底

旧架构加载 `null_blk` 后只等待 `/dev/nullb0`。新架构先从 `/sys/block/nullb0/dev` 读取 major/minor，并在设备节点缺失时手动 `mknod`，适配缺少 udev 的环境。

## 潜在风险点

- tar 同步在 `_sync_dir_to()` 中会先 `rm -rf dest`，再传输/解包。如果 ssh 或 tar 中途失败，远端目标目录可能处于空或半写入状态；rsync 的部分失败语义被替换掉了。
- `_tar_exclude_args()` 是手写模式扩展，不完全等价于 rsync exclude 语义，尤其是复杂路径、根锚定、通配符和目录结尾语义。
- tar 同步默认不等价于 rsync 的所有元数据行为；权限、owner、mtime、symlink 处理需要依赖 tar 语义和 `--no-same-owner`。
- `runner-build.Dockerfile` 现在构建时下载 Go tarball，依赖网络、go.dev 可用性和 `GO_VERSION` 对应 tarball 存在；`GOTOOLCHAIN=local` 也会让需要更高 Go 版本的上游项目直接失败。
- `run_in_runtime_container()` 透传宿主 `TMPDIR`/`TMP`/`TEMP`，如果这些路径没有挂载进容器，容器内程序可能看到不可用的临时目录。
- 收窄 `LD_LIBRARY_PATH` 可以减少库 shadow，但也可能暴露原先被 artifact lib 目录掩盖的运行时依赖问题，尤其是 Katran/Tracee/BCC 或 workload tool 的动态库。
- KVM Docker prelude 假设 guest 内有 Docker CLI/dockerd，且当前权限能启动 dockerd；如果 guest 使用非 Docker runtime 或 rootless/系统级 daemon 策略不同，需要额外路径。
- KVM Docker prelude 会清理 `/var/run/docker.sock` 和 `/run/bpf-benchmark-docker`，在 guest 内已有 Docker daemon 或其他并发任务时有冲突风险。
- SCX name-based live discovery 可能匹配到同名但非本次 scheduler session 的 struct_ops program；如果 program name 复用或并发运行多个 scheduler，会有误归属风险。
- SCX refresh 对非 owner program 不再强制 dup FD，后续如果某些路径仍要求 `program_fds` 覆盖所有 live programs，可能出现 program 列表和 FD map 不一致。
- `e2e/cases/scx/case.py` 同时写 `programs` 和 `scheduler_programs`，短期有兼容意义，但两个 key 后续如果被不同路径修改，可能产生双写不一致。
- 未跟踪的 80 个结果/契约文件体量很大，若误提交会把 PR 噪音和仓库体积显著放大；建议明确是否要保留或加入 ignore 策略。

## 遗留死代码或不一致

- 没有发现 `_rsync_to` / `_rsync_from` 的剩余引用；调用点已切到 `_sync_dir_to` / `_sync_dir_from`。
- 没有发现 `env_with_cross_runtime_ld` 的剩余引用；corpus/e2e/test 已切到 `env_with_suite_runtime_ld`，`cross_runtime_ld_library_path` 仍被 micro 和 suite runtime LD 逻辑使用，不是死代码。
- 没有发现 `SUITE_DEFAULT_REMOTE_COMMANDS` 的剩余引用；删除 suite env 中的远端命令默认值与当前代码一致。
- `FUZZ_ROUNDS` 与 `SCX_PROG_SHOW_RACE_*` 默认值仍在 `Makefile` 和 `runner/libs/suite_args.py` 中存在，因此从 `runner/suites/test.env` 删除这些默认值没有留下明显缺口。
- `runner/libs/app_runners/process_support.py`、`runner/libs/results.py`、`runner/libs/workload.py` 的末尾空行删除仅是格式清理。
- 主要不一致风险是 SCX artifacts 中 `programs` 与 `scheduler_programs` 的双字段，以及 SCX `programs` 列表与 `program_fds` 在非 owner live program 情况下可能不再一一对应。

## 验证状态

- 本次报告仅基于 diff/status 和静态搜索审阅，没有运行测试或构建。
