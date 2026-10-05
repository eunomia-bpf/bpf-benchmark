# Katran gRPC 构建问题调研

日期: 2026-04-27

## 范围说明

用户给出的两个路径在当前 checkout 中不存在:

- `runner/apps/katran/` 实际实现路径是 `runner/libs/app_runners/katran.py`。
- `vendor/katran/` 实际源码路径是 `runner/repos/katran`。

Katran 的 sparse checkout 配置在 `runner/repos.yaml:59-70`: 仓库是 `facebookincubator/katran`，分支是 `main`，当前拉取 `CMakeLists.txt`、`build`、`build_bpf_modules_opensource.sh`、`build_katran.sh`、`cmake`、`example_grpc`、`katran/decap`、`katran/lib`。

## 1. Katran benchmark 实际怎么启动 Katran

当前 benchmark 确实启动 `katran_server_grpc`。

证据:

- `runner/libs/app_runners/__init__.py:63-66` 把 Katran workload 转成 `workload_spec`，`runner/libs/app_runners/__init__.py:75-80` 把 runner 名 `katran` 映射到 `runner.libs.app_runners.katran.KatranRunner`。
- `runner/libs/benchmark_catalog.py:78-83` 定义 corpus Katran app: `MacroAppDefinition(name="katran", runner="katran", workload="test_run")`。
- `runner/libs/app_runners/katran.py:167-170` 默认 server binary 解析为 `repo_artifact_root()/katran/bin/katran_server_grpc`。
- `runner/libs/app_runners/katran.py:893-900` 从 repo artifacts 解析 BPF artifacts: `bpf/balancer.bpf.o`、`bpf/healthchecking_ipip.bpf.o`、`bpf/xdp_root.bpf.o`。
- `runner/libs/app_runners/katran.py:920-938` 创建 DSR test topology，network workload 时额外启动 namespace HTTP server，然后解析 `katran_server_grpc`，创建 `KatranServerSession` 并启动 session。

`KatranServerSession.__enter__` 的启动流程:

- `runner/libs/app_runners/katran.py:481-490` 检查网卡和三个 BPF artifact 是否存在。
- `runner/libs/app_runners/katran.py:494-498` 先安装 `xdp_root.bpf.o`。这是框架规则里允许 Katran root XDP bootstrap 使用 bpftool 的例外。
- `_install_root_xdp_program()` 在 `runner/libs/app_runners/katran.py:819-869` 用 `bpftool prog load ... type xdp pinmaps ...` 和 `bpftool net attach xdp pinned ...` 加载并 attach root XDP。
- `runner/libs/app_runners/katran.py:499-512` 随后启动 server binary，参数包括:
  - `-balancer_prog=<balancer.bpf.o>`
  - `-healthchecker_prog=<healthchecking_ipip.bpf.o>`
  - `-default_mac=<router mac>`
  - `-intf=<iface>`
  - `-ipip_intf=ipip0`
  - `-ipip6_intf=ipip60`
  - `-map_path=<root_array pin>`
  - `-prog_pos=2`
  - `-logtostderr`
  - `-alsologtostderr`
- `runner/libs/app_runners/katran.py:516-519` 等待新加载的 BPF program 集合稳定，并在 `runner/libs/app_runners/katran.py:574-585` 等待 server 暴露 `vip_map`、`reals`、`ch_rings`、`ctl_array`。

workload 行为:

- server 加载并 attach BPF 后，runner 自己用 `bpftool batch` 配置 Katran maps，入口是 `configure_katran_maps()`，见 `runner/libs/app_runners/katran.py:628-647`。
- 默认 corpus workload 是 `test_run`，不使用 gRPC client。runner 直接对 balancer program id 做 `bpftool prog run id <id>`，见 `_bpftool_prog_test_run()` 和 `run_katran_prog_test_run()`: `runner/libs/app_runners/katran.py:256-267`、`runner/libs/app_runners/katran.py:650-660`。
- `_run_test_run_workload()` 在 `runner/libs/app_runners/katran.py:973-984` 循环执行 `BPF_PROG_TEST_RUN` batch。

结论: benchmark 现在启动的是 `katran_server_grpc`，但只把它当作 app-level BPF loader 使用。启动后 benchmark 不使用 gRPC 控制面，而是直接用 bpftool 写 map 和跑 `BPF_PROG_TEST_RUN`。

## 2. ACTIVE_KATRAN_REQUIRED 和构建流程

`ACTIVE_KATRAN_REQUIRED` 在 `runner/mk/build.mk:60` 定义，列出四个 artifact:

- `$(REPO_KATRAN_ROOT)/bin/katran_server_grpc`
- `$(REPO_KATRAN_ROOT)/bpf/balancer.bpf.o`
- `$(REPO_KATRAN_ROOT)/bpf/healthchecking_ipip.bpf.o`
- `$(REPO_KATRAN_ROOT)/bpf/xdp_root.bpf.o`

runtime suite 也强制要求同一组 artifact:

- `runner/suites/_common.py:131-140` 列出 server 和三个 BPF object。
- `runner/suites/_common.py:141-146` 要求 server 可执行，BPF objects 存在。
- `runner/suites/_common.py:147-149` 还要求 Katran runtime library artifact 目录存在。

当前 Docker 构建流程:

- `runner/containers/runner-runtime.Dockerfile:156-172` 把 Katran 源码复制进 build stage，或 sparse clone Katran。
- `runner/containers/runner-runtime.Dockerfile:191-199` 先构建并安装 `bpftool` 到 `/usr/local/bin/bpftool`。
- `runner/containers/runner-runtime.Dockerfile:200` 执行 `make image-katran-artifacts RUN_TARGET_ARCH=... BPFREJIT_IMAGE_BUILD=1`。
- `runner/mk/build.mk:214` 让 `image-katran-artifacts` 依赖 `ACTIVE_KATRAN_REQUIRED`。

Katran Make 规则在 `runner/mk/build.mk:260-312`，实际分三段:

1. 先构建 Katran dependencies，且开启 gRPC:
   - `runner/mk/build.mk:270-273` 运行 `./build_katran.sh`，传入 `KATRAN_SKIP_SYSTEM_PACKAGES=1`、`BUILD_EXAMPLE_GRPC=1`、`INSTALL_DEPS_ONLY=1` 和 clang。
   - 因为 `INSTALL_DEPS_ONLY=1`，这一步只构建依赖，包括 gRPC/protobuf，不构建 Katran 主体。
2. 再用 CMake 构建并 install Katran，且开启 gRPC example:
   - `runner/mk/build.mk:281-282` 创建 `grpc/_build/grpc_cpp_plugin` symlink。
   - `runner/mk/build.mk:284-305` 运行 CMake，显式设置 `CMAKE_BUILD_EXAMPLE_GRPC=1`、`BUILD_TESTS=OFF` 和依赖路径。
   - `runner/mk/build.mk:306` 构建并 install CMake install target。
3. 最后构建 BPF objects:
   - `runner/mk/build.mk:307` 运行 `build_bpf_modules_opensource.sh -s <repo> -b <build_root> -o <artifact bpf root>`。
   - `runner/mk/build.mk:308` 显式检查 `bin/katran_server_grpc`。
   - `runner/mk/build.mk:309-310` 把 `healthchecking_ipip.o` 和 `xdp_root.o` 改名成 `.bpf.o`。
   - `runner/mk/build.mk:311-312` 校验所有 required artifacts 并 touch。

为什么会编译 gRPC:

- Katran 顶层 `CMakeLists.txt:51-52` 只有在 `CMAKE_BUILD_EXAMPLE_GRPC` 被定义时才 `add_subdirectory(example_grpc)`。
- `runner/mk/build.mk:284` 在 CMake install 步骤显式定义了 `CMAKE_BUILD_EXAMPLE_GRPC=1`。
- `runner/repos/katran/build_katran.sh:94-97` 在 `BUILD_EXAMPLE_GRPC` 未设置时默认把它设为 `1`。
- `runner/repos/katran/build_katran.sh:690-692` 在 `BUILD_EXAMPLE_GRPC=1` 时调用 `get_grpc()`。
- `runner/repos/katran/build_katran.sh:523-573` 的 `get_grpc()` clone gRPC `v1.49.1`，初始化 submodules，构建并 install gRPC，然后如果 nested protobuf 有 Makefile，也构建并 install protobuf。

## 3. vendored Katran 源码里有没有不需要 gRPC 的 simpler binary

当前 vendored Katran tree 中，没有完整的、可替代 `katran_server_grpc` 的非 RPC loader binary。

已有的轻量 binary:

- `runner/repos/katran/katran/lib/CMakeLists.txt:209-229` 构建 `xdproot`，它只负责加载和 attach `xdp_root`。
- `runner/repos/katran/katran/lib/xdproot.cpp:23-29` 定义 interface、BPF program path、pin path、XDP flags 等参数。
- `runner/repos/katran/katran/lib/xdproot.cpp:37-49` 打开或创建共享 root map，并加载 root program。
- `runner/repos/katran/katran/lib/xdproot.cpp:55-78` detach 旧 XDP program，attach root program，并 pin `root_array`。

`xdproot` 对 benchmark 不够，因为它不加载 `balancer.bpf.o` 或 `healthchecking_ipip.bpf.o`。而且当前 runner 已经在 `runner/libs/app_runners/katran.py:819-869` 自己用 bpftool 做了 `xdp_root` bootstrap。

`katran_server_grpc` 做了什么:

- `runner/repos/katran/example_grpc/katran_server.cpp:38-66` 定义 runner 正在传的 flags，包括 `intf`、`balancer_prog`、`healthchecker_prog`、`default_mac`、`map_path`、`prog_pos`。
- `runner/repos/katran/example_grpc/katran_server.cpp:117-128` 把 flags 转成 `katran::KatranConfig`。
- `runner/repos/katran/example_grpc/katran_server.cpp:84-105` 构造 `KatranGrpcService`，启动 insecure gRPC listener，注册 signal handler，然后等待。
- `runner/repos/katran/example_grpc/KatranGrpcService.cpp:65-72` 构造 `KatranLb`，调用 `lb_.loadBpfProgs()` 和 `lb_.attachBpfProgs()`。
- `runner/repos/katran/example_grpc/KatranGrpcService.h:34-48` 显示该 service 继承 generated `KatranService::Service`，`runner/repos/katran/example_grpc/KatranGrpcService.h:142-147` 保存 `::katran::KatranLb lb_`。
- `runner/repos/katran/example_grpc/KatranGrpcService.cpp:95-245` 暴露 add VIP、delete VIP、modify real、stats 等 RPC wrapper。当前 benchmark 绕过这些 RPC，自己写 map。

真正加载 balancer 的核心在 `KatranLb`:

- `runner/repos/katran/katran/lib/KatranLb.h:180-201` 声明 `loadBpfProgs()`、`reloadBalancerProg()`、`attachBpfProgs()`。
- `runner/repos/katran/katran/lib/KatranLbStructs.h:169-186` 说明 standalone mode 和 shared root-map mode。
- `runner/repos/katran/katran/lib/KatranLbStructs.h:187-223` 定义 `KatranConfig`，包含 `mainInterface`、`balancerProgPath`、`healthcheckingProgPath`、`rootMapPath`、`rootMapPos`、`enableHc`、`cleanupOnShutdown` 等。
- `runner/repos/katran/katran/lib/KatranLb.cpp:120-122` 在 `rootMapPath` 非空时切换出 standalone mode。
- `runner/repos/katran/katran/lib/KatranLb.cpp:758-859` 加载 balancer 和 healthchecker programs，初始化 maps，更新 control maps，并 attach LRU maps。
- `runner/repos/katran/katran/lib/KatranLb.cpp:899-959` 把 balancer 直接 attach 到 XDP 或注册到 shared root map，并在启用 healthchecker 时 attach TC egress filter。
- `runner/repos/katran/katran/lib/KatranLb.cpp:195-220` 在 destructor 中清理 attached programs。

看起来像替代方案的 `simple_katran_server` 并不是无 gRPC 的 minimal loader:

- `runner/repos/katran/start_katran_simple_server.sh:37-38` 引用了 `${KATRAN_BUILD_DIR}/example/simple_katran_server`。
- Katran 顶层 CMake 在 `runner/repos/katran/CMakeLists.txt:46-49` 用 `CMAKE_BUILD_EXAMPLE_THRIFT` 控制 `example`。
- 当前 pinned commit 的 upstream tree 下，`example` 目录只有 `example/CMakeLists.txt`，没有该 CMake 文件引用的 `KatranSimpleServer.cpp` 等源码。
- Git 中存在的 `example/CMakeLists.txt` 引用了 thrift、fbthrift、wangle、fizz 等重依赖。即使恢复完整 thrift example，它也是把 gRPC/protobuf 换成 fbthrift 依赖栈，不是轻量 loader。

结论: 当前构建路径里，`katran_server_grpc` 是唯一完整 app-level loader。真正简单的替代方案是新增一个我们自己的 minimal loader binary，链接 `katranlb`，只调用 `KatranLb::loadBpfProgs()` 和 `KatranLb::attachBpfProgs()`，然后 sleep 等 signal。

## 4. BPF objects 能不能不编译 gRPC server 就构建出来

可以。BPF object 构建与 gRPC/protobuf 无关。

证据:

- `runner/repos/katran/build_bpf_modules_opensource.sh:29-34` 接受 `SRC_DIR`、`BUILD_DIR`、`DEFINES`、`BPF_OUT_DIR`。
- `runner/repos/katran/build_bpf_modules_opensource.sh:72-79` 从 build dir 或 `/usr` 选择 clang/llc。
- `runner/repos/katran/build_bpf_modules_opensource.sh:81-91` 只 stage BPF Makefile、`katran/lib/bpf`、`katran/lib/linux_includes`、`katran/decap/bpf`。
- `runner/repos/katran/build_bpf_modules_opensource.sh:92-94` 直接用 `CLANG` 和 `LLC` 调 make。这里没有 CMake，没有 gRPC，没有 protobuf。
- `runner/repos/katran/katran/lib/Makefile-bpf:15-19` 定义 BPF 输出: `bpf/balancer.bpf.o`、`bpf/healthchecking_ipip.o`、`bpf/healthchecking.bpf.o`、`bpf/xdp_pktcntr.o`、`bpf/xdp_root.o`。
- `runner/repos/katran/katran/lib/Makefile-bpf:38-42` 用 clang 生成 LLVM IR，并 pipe 给 `llc -march=bpf` 生成 object。

当前构建规则把 BPF artifacts 和 `katran_server_grpc` 绑在一起，是因为 `ACTIVE_KATRAN_REQUIRED` 同时包含四个输出，且 grouped rule 一次性构建四个，见 `runner/mk/build.mk:260-312`。这个耦合来自我们的 Makefile，不是 Katran BPF build script 的要求。

实际含义:

- 可以新增一个 `make image-katran-bpf-artifacts` 类 target，只调用 `build_bpf_modules_opensource.sh`，生成三个 required BPF objects，不触发 `build_katran.sh`、CMake、gRPC、protobuf。
- 但当前 runner 仍会失败，除非 `repo-artifacts/<arch>/katran/bin/katran_server_grpc` 仍存在并可执行，或者把 runner 改成使用另一个 loader binary。

## 5. 能不能像 Tracee/Tetragon 那样用预编译 Katran 镜像

当前 repo 对有可用 upstream runtime image 的 app 是这样做的:

- `runner/containers/runner-runtime.Dockerfile:2-5` 声明 pinned upstream images: Tracee、Tetragon、Cilium、Calico。
- `runner/containers/runner-runtime.Dockerfile:142-148` 从这些 image 创建 upstream stages。
- `runner/containers/runner-runtime.Dockerfile:208-222` 从 upstream images copy Tracee 和 Tetragon binaries/artifacts。
- `runner/containers/runner-runtime.Dockerfile:355-360` 把 Tracee/Tetragon 链接到 repo artifact root。
- `runner/containers/runner-runtime.Dockerfile:425-439` 从 upstream images copy Cilium 和 Calico artifacts。
- `runner/containers/runner-runtime.Dockerfile:479-487` 把 Cilium、Calico、otelcol-ebpf-profiler 链接到 repo artifact root。

Katran 当前不是这样:

- `runner/containers/runner-runtime.Dockerfile:156-172` copy 或 clone Katran source。
- `runner/containers/runner-runtime.Dockerfile:200` 在 image build 阶段从源码构建 Katran artifacts。
- Dockerfile 中没有 `KATRAN_IMAGE` ARG，没有 Katran upstream image stage，也没有 `COPY --from=<katran image>`。

我在 2026-04-27 检查了公开镜像:

- `docker manifest inspect facebookincubator/katran:latest` 返回 access denied 或 authentication required。
- `docker manifest inspect ghcr.io/facebookincubator/katran:latest` 返回 denied。
- Katran 官方源码树没有 Dockerfile 或 Containerfile。
- Web search 找到的是官方源码仓库 [facebookincubator/katran](https://github.com/facebookincubator/katran)，没有看到类似 `aquasec/tracee` 或 `quay.io/cilium/tetragon` 的官方公开 multi-arch runtime image。

结论: 目前没有明显可用的官方 Katran 预编译 runtime image 可以直接当 base image 使用。可以做项目自有的预编译 artifact image，但那只是把构建成本挪到另一个 pipeline，不是从根上消除 gRPC/protobuf 依赖。

## 建议

### 不改 runner 语义的最小改进

把 BPF object 生成和 userspace loader 构建拆开:

- 新增 BPF-only Make target，运行 `runner/repos/katran/build_bpf_modules_opensource.sh`，只 stage `balancer.bpf.o`、`healthchecking_ipip.bpf.o`、`xdp_root.bpf.o`。
- 暂时保留现有 `katran_server_grpc` loader 路径。

这个改动有利于缓存和明确 dependency boundary，但不能消除 gRPC，因为当前 runner 仍依赖 `katran_server_grpc`。

### 推荐的小设计改动

新增一个项目自有的 minimal Katran loader binary，并把 `ACTIVE_KATRAN_REQUIRED` 和 `KatranRunner` 改为使用它。

loader 应该:

- 接受当前 runner 需要的同一组 flags: `balancer_prog`、`healthchecker_prog`、`default_mac`、`intf`、`ipip_intf`、`ipip6_intf`、`map_path`、`prog_pos`，以及 logging flags 或兼容性忽略的 flags。
- 按 `example_grpc/katran_server.cpp:117-128` 的方式构造 `katran::KatranConfig`。
- 用 `std::make_unique<katran::BpfAdapter>(config.memlockUnlimited)` 构造 `katran::KatranLb`。
- 调用 `loadBpfProgs()` 和 `attachBpfProgs()`，等价于 `KatranGrpcService.cpp:65-72`。
- sleep 到 SIGTERM/SIGINT，让 benchmark 有真实 app process，并让 `KatranLb` destructor 负责 cleanup。

配套构建变化:

- 构建 Katran dependencies 时设置 `BUILD_EXAMPLE_GRPC=0`，并确保 `CMAKE_BUILD_EXAMPLE_GRPC` 未定义。
- CMake 步骤不要定义 `CMAKE_BUILD_EXAMPLE_GRPC`。
- 只构建并 install `katran/lib` 加 minimal loader target。
- BPF objects 继续通过 `build_bpf_modules_opensource.sh` 生成。
- artifact validation 从 `bin/katran_server_grpc` 改成 `bin/katran_loader` 或类似名字。

这个方案应该能从 Katran image build 中完全消除 gRPC 和 protobuf 编译，同时保留“app 自己加载 BPF program”的设计规则。框架仍只对 Katran 的 `xdp_root` bootstrap 使用 bpftool，这与现有例外一致。

### 不建议用 simple_katran_server

`simple_katran_server` 是 thrift-based，不是 minimal no-RPC loader。它当前也没有完整出现在 sparse checkout 中；即使恢复，也会引入 thrift 依赖栈。因此它不是 `katran_server_grpc` 的好替代。

### 预编译镜像方案

目前不建议依赖 upstream Katran image，因为没有找到包含 `katran_server_grpc` 和 required BPF objects 且支持 x86_64/arm64 的官方公开镜像。项目自有预编译 artifact image 可作为缓存或分发优化，但不如删除 gRPC 依赖干净。

最终建议: 实现 minimal loader，并拆出 BPF-only artifact target。这是最小且能完全移除 gRPC/protobuf 编译的方案，同时仍满足 app-level BPF loading。
