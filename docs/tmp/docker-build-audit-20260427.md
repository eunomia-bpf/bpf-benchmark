# Docker 镜像构建审计 - 2026-04-27

范围：`runner/containers/runner-runtime.Dockerfile`、`runner/mk/build.mk`、顶层 `Makefile`，以及这些入口实际触达的构建脚本和源码。

## 结论摘要

当前 runtime image 里混合了三类工作：

1. 必要源码构建：自定义 Linux kernel、kinsn kernel module、`bpfrejit-daemon`、`micro_exec`、micro benchmark `.bpf.o`、测试 artifacts、Katran artifacts。
2. 主要由构建方式导致的源码构建：多次 libbpf 构建、vendored `bpftool`、Katran 的 folly/gRPC/protobuf 依赖栈，以及 Katran 的 googletest 依赖。
3. 直接安装或复制：Ubuntu apt 包、Go/Rust binary toolchain、Tracee/Tetragon/Cilium/Calico upstream image、repo 内预编译 corpus object、`otelcol-ebpf-profiler` release tarball。

最大可避免耗时是 Katran 依赖栈，尤其 gRPC/protobuf 和 folly。最大必要耗时是自定义 kernel。最实际的优化方向不是把 C++/Rust 改成 Python，而是预构建/缓存按架构区分的 artifacts，并拆分 Docker cache 边界，避免 daemon 或 micro 改动触发 Katran/kernel 重编。

## 顶层入口

顶层 `Makefile` 基本是 dispatcher：

- 启动时要求 `vendor/linux-framework` submodule 存在（`Makefile:4`），并定义 repo root、micro/runner/daemon/kernel/cache 目录（`Makefile:6-11`）。
- 构建规则来自 `runner/mk/build.mk`（`Makefile:26`）。
- canonical targets 是 Python suite 入口：`vm-test`、`vm-micro`、`vm-corpus`、`vm-e2e`、AWS test/benchmark/terminate（`Makefile:62-67`，`Makefile:94-148`）。
- `vm-corpus` 调 `python -m runner.libs.run_target_suite run x86-kvm corpus`（`Makefile:106-107`）；`vm-e2e` 类似（`Makefile:109-110`）。
- local prep 由 Python 算出目标，再执行 `make -C <repo> ...`（`runner/libs/run_target_suite.py:47-55`，`runner/libs/run_target_suite.py:98-113`）。
- 需要 runtime image 的 suite 是 `test/micro/corpus/e2e`；需要 daemon binary 的 suite 是 `test/corpus/e2e`（`runner/libs/workspace_layout.py:9-10`）。KVM executor 还会准备 KVM kernel image（`runner/libs/workspace_layout.py:109-119`）。
- runtime image tar 路径是 `.cache/container-images/<arch>-runner-runtime.image.tar`（`runner/libs/workspace_layout.py:73-74`）。KVM 运行前通过 `runner/scripts/bpfrejit-install` 安装该 image（`runner/libs/kvm_executor.py:90-103`）。

## `build.mk` 构建图

关键变量：

- 默认目标架构是 `x86_64`（`runner/mk/build.mk:3`）。
- runtime image tar 输出是 `.cache/container-images/x86_64-runner-runtime.image.tar` 和 `.cache/container-images/arm64-runner-runtime.image.tar`（`runner/mk/build.mk:44-48`）。
- image 内 kernel build root 是 `/tmp/bpf-benchmark-build/<arch>.../kernel-build`（`runner/mk/build.mk:12-17`，`runner/mk/build.mk:54-59`）。
- Katran 必需输出是 `bin/katran_server_grpc`、`bpf/balancer.bpf.o`、`bpf/healthchecking_ipip.bpf.o`、`bpf/xdp_root.bpf.o`（`runner/mk/build.mk:60`）。
- source dependency set 覆盖 daemon、runner、tests、micro programs、kinsn module、Katran、libbpf、vendored Linux runtime files、Python/YAML/env runtime files、kernel metadata 和 kernel source（`runner/mk/build.mk:64-104`）。

主要 target：

- `image-runner-runtime-image-tar` 构建当前架构 runtime image tar（`runner/mk/build.mk:137-138`）。
- x86 image tar：`docker build --platform linux/amd64 --target runner-runtime ...` 后 `docker save`（`runner/mk/build.mk:117-125`）。
- arm64 image tar：`docker build --platform linux/arm64 --target runner-runtime ...` 后 `docker save`（`runner/mk/build.mk:127-135`）。
- `$(X86_RUNTIME_KERNEL_IMAGE)` 依赖 x86 image tar 和 install script，只从 image 中抽取 kernel（`runner/mk/build.mk:140-144`）。
- `image-kernel-artifacts` 构建 kernel、install modules、构建 kinsn modules、复制 kernel image、写 manifest（`runner/mk/build.mk:148-161`）。
- `image-kernel-build` 执行 Linux `olddefconfig` 并构建 `bzImage/modules` 或 `Image/vmlinuz.efi/modules`（`runner/mk/build.mk:163-180`）。
- `image-kernel-modules-artifacts` 执行 `modules_install`、`depmod`，并 staging `/lib/modules/<release>`（`runner/mk/build.mk:184-200`）。
- `image-kinsn-artifacts` 用 `M=<module source>` 构建 out-of-tree kinsn module（`runner/mk/build.mk:202-205`）。
- Docker-only artifact target 由 `BPFREJIT_IMAGE_BUILD=1` 保护（`runner/mk/build.mk:207-218`）。
- `image-runner-artifacts` 构建 `runner/build-llvmbpf/micro_exec` 或 `runner/build-arm64-llvmbpf/micro_exec`（`runner/mk/build.mk:215`，`runner/mk/build.mk:231-243`）。
- `image-daemon-artifact` 构建 Rust daemon（`runner/mk/build.mk:216`，`runner/mk/build.mk:227-230`）。
- `image-micro-program-artifacts` 编译所有 micro `.bpf.c`（`runner/mk/build.mk:217`，`runner/mk/build.mk:253-256`）。
- `image-test-artifacts` 构建 unit 和 negative test artifacts（`runner/mk/build.mk:218`，`runner/mk/build.mk:245-251`）。
- `image-katran-artifacts` 构建 Katran server 和 BPF artifacts（`runner/mk/build.mk:214`，`runner/mk/build.mk:260-312`）。

## Dockerfile 分 stage 分析

### `runner-runtime-build-base`

基于 Ubuntu 24.04（`runner/containers/runner-runtime.Dockerfile:6`）。

直接安装：

- 一个很大的 apt layer，包含 build toolchain、kernel build deps、C/C++ libs、BPF tools、Python runtime packages、benchmark workload tools、runtime networking tools（`runner/containers/runner-runtime.Dockerfile:16-105`）。
- Go binary toolchain，从 `go.dev` 下载 tarball 后解压（`runner/containers/runner-runtime.Dockerfile:107-121`）。
- Rust binary toolchain，通过 `rustup` 安装（`runner/containers/runner-runtime.Dockerfile:123-135`）。

Go 目前不是用于本 repo 的 Go 代码编译，而是满足 Katran `get_grpc` 对 `go` 的检查：在 `KATRAN_SKIP_SYSTEM_PACKAGES=1` 下，如果没有 Go 就退出（`runner/repos/katran/build_katran.sh:523-537`）。如果 Katran gRPC source build 被预构建或改用系统包，这层 Go 很可能可以删除。

### upstream app image stages

这些都是预编译 image 导入：

- Tracee image arg/stage（`runner/containers/runner-runtime.Dockerfile:2`，`runner/containers/runner-runtime.Dockerfile:142`）。
- Tetragon image arg/stage（`runner/containers/runner-runtime.Dockerfile:3`，`runner/containers/runner-runtime.Dockerfile:144`）。
- Cilium image arg/stage（`runner/containers/runner-runtime.Dockerfile:4`，`runner/containers/runner-runtime.Dockerfile:146`）。
- Calico node image arg/stage（`runner/containers/runner-runtime.Dockerfile:5`，`runner/containers/runner-runtime.Dockerfile:148`）。

### `runner-runtime-userspace`

这个 stage 编译并 staging Katran 和 `bpftool`。

做的事：

- 复制顶层 Makefile、`runner/mk`、Katran repo files、vendored libbpf/llvmbpf，以及 `vendor/linux-framework` 的 sparse 子集（`runner/containers/runner-runtime.Dockerfile:156-190`）。
- 如果 `runner/repos/katran` 不存在，sparse-clone Katran GitHub repo（`runner/containers/runner-runtime.Dockerfile:163-172`）。
- 从 `vendor/linux-framework/tools/bpf/bpftool` 编译 `bpftool`，禁用若干 optional features，安装到 `/usr/local/bin/bpftool`，并验证 `bpftool version`（`runner/containers/runner-runtime.Dockerfile:191-199`）。
- 执行 `make image-katran-artifacts`（`runner/containers/runner-runtime.Dockerfile:200`）。
- 从 Tracee image 复制 `tracee`、`tracee-ebpf`、musl loader/libc 和相关 libs（`runner/containers/runner-runtime.Dockerfile:208-220`）。
- 从 Tetragon image 复制 `/usr/bin/tetragon` 和 `/var/lib/tetragon`（`runner/containers/runner-runtime.Dockerfile:221-222`）。

### `runner-runtime-kernel-artifacts`

这个 stage 编译 kernel-side artifacts。

做的事：

- 通过 apt 安装 `bsdextrautils`（`runner/containers/runner-runtime.Dockerfile:230-232`）。
- 复制 Makefile、`runner/mk`、defconfig、module sources，并把 `vendor/linux-framework` symlink 到 bind-mounted source tree（`runner/containers/runner-runtime.Dockerfile:234-252`）。
- 执行 `make image-kernel-artifacts`，进而构建自定义 kernel、modules、kinsn modules（`runner/containers/runner-runtime.Dockerfile:253-256`）。
- 删除临时 source/build inputs（`runner/containers/runner-runtime.Dockerfile:257-262`）。

### `runner-runtime`

最终 runtime stage 从 `runner-runtime-userspace` 开始，所以继承 base apt、Go/Rust toolchain（直到后面删除）、已构建 `bpftool`、Katran artifacts、Tracee/Tetragon artifacts（`runner/containers/runner-runtime.Dockerfile:264`）。

源码编译：

- 复制 runner C++ sources、micro programs、test sources、daemon source、corpus runtime data、e2e cases、Python runtime code、targets/configs（`runner/containers/runner-runtime.Dockerfile:274-317`）。
- 构建 runner C++ artifacts、micro `.bpf.o` artifacts、test artifacts、daemon（`runner/containers/runner-runtime.Dockerfile:318-321`）。
- 删除 build directories、Rust toolchain/cargo cache、build sources，并 apt purge 大量 build deps（`runner/containers/runner-runtime.Dockerfile:323-419`）。

直接复制/安装：

- 从 `runner-runtime-kernel-artifacts` 复制 kernel artifacts（`runner/containers/runner-runtime.Dockerfile:421-424`）。
- 从 Cilium image 复制 Cilium binaries、Cilium BPF assets、Cilium 自带 `clang`/`llc`（`runner/containers/runner-runtime.Dockerfile:425-434`）。
- 从 Calico image 复制 `calico-node`、configs、BPF assets、included source、libpcap（`runner/containers/runner-runtime.Dockerfile:435-440`）。
- 复制 `runner/scripts/bpfrejit-install` 到 `/usr/local/bin`（`runner/containers/runner-runtime.Dockerfile:441`）。
- apt 安装 `etcd-server` 和 `nftables`（`runner/containers/runner-runtime.Dockerfile:443-449`）。
- 下载并解压预编译 `otelcol-ebpf-profiler` release tarball（`runner/containers/runner-runtime.Dockerfile:467-478`）。
- 创建 Tracee/Tetragon/Calico/Cilium/Otel repo-artifact symlink（`runner/containers/runner-runtime.Dockerfile:479-487`）。

### `runner-default`

只是 alias stage（`runner/containers/runner-runtime.Dockerfile:495`）。

## A. 从源码编译的组件

### 1. 自定义 Linux kernel 和 in-tree modules

- 语言：C、assembly、Kbuild。
- 构建路径：`image-kernel-build` 执行 Linux `make olddefconfig` 和 kernel image/modules targets（`runner/mk/build.mk:163-180`）。
- Dockerfile 触发点：`make image-kernel-artifacts`（`runner/containers/runner-runtime.Dockerfile:253-256`）。
- 复杂度：很大。它是必要构建中最重的一项。
- 为什么编译：benchmark 需要 vendored `vendor/linux-framework` kernel，包含 BPF ReJIT 支持和匹配的 modules。stock Ubuntu kernel package 不能替代。
- 是否必须在每次 Docker build 中编译：不必须。需要的是 artifact，不一定要在 runtime image build 过程中编。
- 替代方案：按架构预构建 kernel image、modules、manifest，key 包括 `vendor/linux-framework`、defconfig、compiler、module source。
- 缓存/预构建：最高优先级之一。把 `kernel/`、`modules/`、`kinsn/`、`manifest.json` 发布为 OCI layer 或 CI artifact；只有 kernel/config/module sources 变更时重建。

### 2. kinsn out-of-tree kernel modules

- 语言：C/Kbuild。
- 构建路径：`make ... M=<module source> MO=<artifact dir> modules`（`runner/mk/build.mk:202-205`）。
- 规模：`module/` 下 C/H/Makefile 约 3.4k 行。
- 复杂度：中等，但强绑定 exact kernel build。
- 为什么编译：daemon 启动时发现 exported kinsn stubs（`daemon/src/main.rs:46-72`），module 必须匹配自定义 kernel。
- 替代方案：只能和 exact kernel release 一起预构建。
- 缓存/预构建：和 kernel 一起做。

### 3. `bpftool`

- 语言：C。
- 构建路径：Dockerfile 执行 `make -C vendor/linux-framework/tools/bpf/bpftool ...` 并安装（`runner/containers/runner-runtime.Dockerfile:191-199`）。
- 额外用途：unit tests 会构建 bootstrap `bpftool` 用来生成 `vmlinux.h`（`tests/unittest/Makefile:104-110`）。
- runtime 用途：Python 从 env、vendored path、`/usr/local/sbin` 或 `PATH` 解析 `bpftool`（`runner/libs/__init__.py:14-18`，`runner/libs/__init__.py:92-104`）；suite 用它做 `prog show`、`map show/update`、`net attach`、`prog run`、BTF dump。
- 复杂度：中等。比 Katran/kernel 小很多，但仍然可避免。
- 是否必须从 vendor 编译：不严格必须。daemon 自己实现 `BPF_PROG_REJIT` syscall constants（`daemon/src/bpf.rs:38-41`），runtime `bpftool` 主要做普通 BPF inspect/control。和 vendored kernel 版本一致有价值，但不是 ReJIT 的硬依赖。
- `apt install bpftool` 可行性：不能直接假设可行。我在当前 Noble apt 配置下查到 `apt-cache policy bpftool` 没有 candidate；Ubuntu 常见路径是 `linux-tools-*` 系列，而不是稳定的 standalone `bpftool` 包名。
- 更稳替代：复制一个 known-good per-arch 预编译 `bpftool`，或把 vendor `bpftool` 构建放进共享 artifact/base image。
- 缓存/预构建：中优先级。不要把它排在 Katran/kernel 前面。

### 4. libbpf

当前存在多次 libbpf 源码构建：

- runner libbpf：`make -C vendor/libbpf/src ... BUILD_STATIC_ONLY=1 ... libbpf.a install_headers`（`runner/mk/build.mk:220-225`）。
- unit-test libbpf：`tests/unittest/Makefile` 另建一个 static libbpf archive（`tests/unittest/Makefile:93-102`）。
- Katran libbpf：Katran `build_katran.sh` clone `https://github.com/libbpf/libbpf`，执行 `make`，install 并 patch headers（`runner/repos/katran/build_katran.sh:576-608`）。

语言：C。

复杂度：单次小到中等，但重复构建不合理。

为什么编译：runner 静态链接 libbpf，tests 需要 static libbpf 和 headers，Katran build 需要 libbpf prefix。

是否必须源码构建：不一定。base apt 已安装 `libbpf-dev`（`runner/containers/runner-runtime.Dockerfile:49`）。取舍是版本确定性和与 vendored kernel headers 的兼容性。

缓存/预构建：中优先级。至少避免构建三次。更好的方式是一次 vendored libbpf build artifact 供 runner/tests/Katran 共用，或者验证后让部分 consumer 改用 apt `libbpf-dev`。

### 5. `micro_exec` runner binary

- 语言：C++20 加 vendored llvmbpf C++。
- 构建路径：CMake configure/build（`runner/mk/build.mk:231-243`）。
- 源码定义：`runner/CMakeLists.txt` 设置 C/C++ 标准和 sources（`runner/CMakeLists.txt:3-8`，`runner/CMakeLists.txt:37-44`）。
- llvmbpf integration 会额外编译 `runner/src/llvmbpf_runner.cpp` 和 `vendor/llvmbpf/src/*.cpp`，并链接 LLVM components（`runner/CMakeLists.txt:46-97`，`runner/CMakeLists.txt:135-140`）。
- 规模：`runner/src` 和 `runner/include` 约 3.7k 行。
- 做什么：CLI 支持 `list-programs`、`test-run`、`run-llvmbpf`（`runner/src/main.cpp:6-24`）。kernel path 用 libbpf open/load BPF object，并执行 `bpf_prog_test_run_opts`（`runner/src/kernel_runner.cpp:966-1002`，`runner/src/kernel_runner.cpp:429-441`）。llvmbpf path 负责 BPF ELF image extraction、JIT compile、helper shim、repeat execution（`runner/src/llvmbpf_runner.cpp:623-689`，`runner/src/llvmbpf_runner.cpp:671-680`，`runner/src/llvmbpf_runner.cpp:723-857`）。
- 为什么编译：这不是普通 orchestration。它负责 libbpf loading、低开销 timing、perf counters、BPF ELF relocation、llvmbpf C++ API。
- 能否用 Python 替代：理论上能重写，但不适合作为缩短 build time 的方案。Python 版本会引入 libbpf/syscall/LLVM binding 维护成本，并影响 timing 行为。
- 缓存/预构建：高价值低风险。按架构预构建，或拆成 CMake/ccache layer，key 包括 `runner/src`、`runner/include`、`vendor/llvmbpf`、`vendor/libbpf`。

### 6. `bpfrejit-daemon`

- 语言：Rust。
- 构建路径：`make -C daemon release`（`runner/mk/build.mk:227-230`），内部执行 `cargo build --release`（`daemon/Makefile:10-11`）。
- crates：`anyhow`、`clap`、`goblin`、`libc`、`serde`、`serde_json`（`daemon/Cargo.toml:11-17`），release profile 使用 `opt-level=3` 和 LTO（`daemon/Cargo.toml:19-21`）。
- 规模：production Rust 约 24k 行，含 tests 约 33k 行。
- 做什么：ReJIT control plane，扫描 live BPF programs 并通过 `BPF_PROG_REJIT` 应用 rewrite（`daemon/README.md:3-5`）。当前 CLI 只有 `serve`（`daemon/src/main.rs:33-41`），启动时做 kinsn discovery 和 platform capability detection（`daemon/src/main.rs:43-75`）。server 处理 `optimize`、`optimize-all`、`status` 等 JSON commands（`daemon/src/server.rs:459-789`）。核心 apply path 是 `commands::try_apply_one`（`daemon/src/commands.rs:440-452`）。
- 为什么编译：这是 pass pipeline 和 ReJIT 控制面，不是 wrapper。
- 能否用 Python 替代：不适合。等价于 port verifier/rewrite logic、syscall structs、analysis passes、invalidation 和 server protocol。
- 能否预编译：可以。daemon 编译期不强绑定某个 kernel build；它运行时发现 capability/kfunc/BTF 状态。需要保留兼容性测试，但这是最安全的预构建候选之一。

### 7. Micro benchmark `.bpf.o`

- 语言：C 编译为 eBPF。
- 构建路径：`make -C micro/programs OUTPUT_DIR=... all`（`runner/mk/build.mk:253-256`）。
- Makefile 用 `clang -target bpf` 编译每个 `*.bpf.c`（`micro/programs/Makefile:5-16`）。
- 数量：62 个 `.bpf.c`。
- 复杂度：小到中等。比 Katran/kernel 快很多，但目前总是在 final runtime build step 中构建。
- 为什么编译：micro suite 需要 object files；`runner/suites/micro.py` 要求 runner binary 和 micro program artifact root 存在（`runner/suites/micro.py:136-147`）。
- 能否预编译：可以。这些是 deterministic benchmark input artifacts。除非 program/include 使用 arch-specific macros，否则甚至未必需要按 arch 分开；当前 make rule 本身没有传 `__TARGET_ARCH_*`。
- 缓存/预构建：中优先级。按 `micro/programs/**` 和 clang version 生成 artifact tarball，或单独 Docker layer。

### 8. Test artifacts

- 语言：C host tests 加 C-to-eBPF test programs。
- 构建路径：`image-test-artifacts` 构建 unit 和 negative tests（`runner/mk/build.mk:245-251`）。
- Unit tests auto-discover `rejit_*.c`、module tests、`tests/unittest/progs/*.bpf.c`（`tests/unittest/Makefile:65-83`）。
- Unit host tests 静态链接 libbpf（`tests/unittest/Makefile:85-102`）。
- Unit BPF programs 需要 `vmlinux.h`；未提供时由 bootstrap `bpftool` dump 生成（`tests/unittest/Makefile:104-120`）。
- Negative tests 构建 `fuzz_rejit` 和 `adversarial_rejit`（`tests/negative/Makefile:10-17`）。
- 数量：35 个 unit BPF programs，`tests/unittest` 下 61 个 C 文件，negative C 文件 2 个。
- 为什么编译：默认 `make vm-test`、`make aws-x86-test`、`make aws-arm64-test` 需要零手工配置可用。
- 能否预编译：可以按 arch 缓存。另一个方向是拆分 benchmark runtime image 和 test runtime image；如果必须一个 image 支持所有目标，就把 test artifacts 放独立 cache layer。

### 9. Katran dependency stack、server、BPF artifacts

- 语言：主要是 C++17/C++20、C、protobuf-generated C++、eBPF C。
- 构建路径：`ACTIVE_KATRAN_REQUIRED` target（`runner/mk/build.mk:260-312`）。
- Dockerfile 复制或 sparse-clone Katran source（`runner/containers/runner-runtime.Dockerfile:156-172`），然后执行 `make image-katran-artifacts`（`runner/containers/runner-runtime.Dockerfile:200`）。
- required outputs：`katran_server_grpc`、`balancer.bpf.o`、`healthchecking_ipip.bpf.o`、`xdp_root.bpf.o`（`runner/mk/build.mk:60`）。
- runtime 在 Katran enabled 时要求这些 artifacts 存在（`runner/suites/_common.py:131-149`），app runner 以这些 BPF artifact paths 启动 `katran_server_grpc`（`runner/libs/app_runners/katran.py:167-170`，`runner/libs/app_runners/katran.py:484-510`，`runner/libs/app_runners/katran.py:893-930`）。

Katran 源码构建的依赖：

- `fast_float` clone 为 headers（`runner/repos/katran/build_katran.sh:224-242`）。
- folly clone、CMake build、install（`runner/repos/katran/build_katran.sh:244-316`）。
- googletest clone/CMake install，即使后面的 Katran CMake pass 使用 `-DBUILD_TESTS=OFF`（`runner/repos/katran/build_katran.sh:348-371`，`runner/mk/build.mk:305`）。
- gRPC v1.49.1 clone、submodule init、CMake build/install，并可能构建/install third-party protobuf（`runner/repos/katran/build_katran.sh:523-573`）。
- libbpf clone/build/install，专供 Katran prefix（`runner/repos/katran/build_katran.sh:576-608`）。
- `INSTALL_DEPS_ONLY=1` 模式仍会跑这些 dependency setup；之后 `build.mk` 再显式跑 Katran CMake build（`runner/mk/build.mk:270-273`，`runner/repos/katran/build_katran.sh:673-697`）。

Katran server build：

- final CMake pass 使用 `BUILD_TESTS=OFF`、C++20 override、system glog/gflags/libelf、installed dependency prefix（`runner/mk/build.mk:284-306`）。
- Katran top-level CMake 只有在 `CMAKE_BUILD_EXAMPLE_GRPC` 设置时才 add `example_grpc`（`runner/repos/katran/CMakeLists.txt:51-53`）。
- `example_grpc/CMakeLists.txt` 通过 `protoc` 和 `grpc_cpp_plugin` 生成 `katran.pb.cc`、`katran.grpc.pb.cc`，再链接 `katran_server_grpc`（`runner/repos/katran/example_grpc/CMakeLists.txt:14-39`，`runner/repos/katran/example_grpc/CMakeLists.txt:69-97`）。

Katran BPF build：

- `build_bpf_modules_opensource.sh` 把 Katran BPF sources copy 到 build area 后用 `CLANG`/`LLC` 跑 make（`runner/repos/katran/build_bpf_modules_opensource.sh:81-94`）。
- `Makefile-bpf` 编译 `balancer`、healthchecking、packet counter、`xdp_root`（`runner/repos/katran/katran/lib/Makefile-bpf:15-20`，`runner/repos/katran/katran/lib/Makefile-bpf:38-42`）。

复杂度：userspace 中最大。当前 sparse Katran subset 在 `katran/lib`、`katran/decap`、`example_grpc` 下约 38k 行，还不含 cloned dependencies。

是否必须编译：必须有真实 Katran artifacts 来满足 app-level loader 规则。用自写 loader 替代 `katran_server_grpc` 会改变 benchmark 语义，且很可能违反“app-level loader only”。

能否避免 gRPC 编译：可以优化，但不能今天直接跳过。当前 required binary 就是 `katran_server_grpc`，它的 CMake target 依赖 generated gRPC/protobuf sources。把 `BUILD_EXAMPLE_GRPC=0` 会直接丢失 required artifact。

可行方向：

- 按架构预构建 `katran_server_grpc` 和 BPF artifacts。
- patch Katran build 使用 distro `libgrpc++-dev`、`protobuf-compiler`、`protobuf-compiler-grpc` 等包，并把 `grpc_cpp_plugin` 指到 system binary，而不是 source-build gRPC v1.49.1。需要测试，因为当前 CMake 依赖 `CMAKE_PREFIX_PATH` 里的 gRPC package 和 `grpc/_build` 下的 plugin path（`runner/mk/build.mk:281-282`，`runner/repos/katran/example_grpc/CMakeLists.txt:5-12`，`runner/repos/katran/example_grpc/CMakeLists.txt:33-37`）。
- 预生成 `katran.pb.*` 和 `katran.grpc.pb.*`，patch CMake 直接消费 generated files。这能去掉 protoc/plugin 执行，但仍需要 gRPC/protobuf link deps。
- 换另一个 upstream Katran entrypoint，前提是它仍由 Katran app 自己加载同一批 BPF programs。这是更大的产品/实验设计决策。

缓存/预构建：userspace 最高优先级。

## B. 预编译镜像/包直接安装的组件

### Ubuntu apt packages

base image 通过 apt 安装（`runner/containers/runner-runtime.Dockerfile:16-105`）：

- build toolchain/deps：`autoconf`、`automake`、`binutils-dev`、`bison`、`clang`、`cmake`、`dwarves`、`flex`、`g++`、`gcc`、`git`、LLVM packages、各类 `lib*-dev`、`make`、`pkg-config`、`rsync`、`scons`、`xxd`、compression tools。
- runtime tools：`bash`、`bpfcc-tools`、`bpftrace`、`curl`、`fio`、`iproute2`、`ipset`、`iptables`、`kmod`、`procps`、`python3`、`python3-bpfcc`、`python3-yaml`、`rt-tests`、`stress-ng`、`tar`、`util-linux`、`wrk`。
- 部分 libraries 同时服务 build 和 copied upstream binaries 的 runtime。

final runtime apt 安装：

- `etcd-server` 和 `nftables`（`runner/containers/runner-runtime.Dockerfile:443-449`）。

当前 Dockerfile/build path 没有 `pip install` 或 `python -m pip`。Python code 是从 repo copy 进 image（`runner/containers/runner-runtime.Dockerfile:305-317`），依赖 apt-installed Python modules。

### Go 和 Rust toolchains

- Go 从 `go.dev` 下载预编译 tarball（`runner/containers/runner-runtime.Dockerfile:107-118`）。
- Rust 通过 `rustup` 安装预编译 toolchain（`runner/containers/runner-runtime.Dockerfile:123-135`）。
- 它们是 build tools，不是最终 runtime artifacts；后面会删除 `/opt/cargo` 和 `/opt/rustup`（`runner/containers/runner-runtime.Dockerfile:323-327`）。

### upstream app artifacts

- Tracee：从 pinned Tracee image 复制 `tracee`、`tracee-ebpf`、musl loader/libc、相关 libs（`runner/containers/runner-runtime.Dockerfile:208-220`）。
- Tetragon：从 pinned Tetragon image 复制 `/usr/bin/tetragon` 和 `/var/lib/tetragon`（`runner/containers/runner-runtime.Dockerfile:221-222`）。
- Cilium：从 pinned Cilium image 复制 Cilium binaries、`/var/lib/cilium`、Cilium 自带 `clang`/`llc`（`runner/containers/runner-runtime.Dockerfile:425-434`）。
- Calico：从 pinned Calico image 复制 `calico-node`、`/etc/calico`、`/usr/lib/calico/bpf`、`/included-source`、libpcap（`runner/containers/runner-runtime.Dockerfile:435-440`）。

这些已经是正确的“不要本地源码构建 app”的模式。

### Otel eBPF profiler

- `otelcol-ebpf-profiler` 是下载预编译 release tarball 并解压到 `/usr/local/bin`（`runner/containers/runner-runtime.Dockerfile:270-272`，`runner/containers/runner-runtime.Dockerfile:467-478`）。

### Corpus BPF corpus

- Dockerfile 复制 `corpus/bcf` 和 `corpus/inputs`；image build 不编译 corpus objects（`runner/containers/runner-runtime.Dockerfile:305-306`）。
- 观察到 `corpus/bcf` 下有 1589 个文件，约 664 MiB。这些是 repo 内预编译 object/corpus artifacts。

### Config、scripts、Python runtime code

直接复制：

- micro/corpus/e2e Python files 和 configs（`runner/containers/runner-runtime.Dockerfile:307-313`）。
- runner Python libs、suites、targets、repo metadata（`runner/containers/runner-runtime.Dockerfile:314-317`）。
- Tetragon policies 只验证存在，不编译（`runner/containers/runner-runtime.Dockerfile:311-322`）。

## 重点问题回答

### `bpftool` 是否一定要从 `vendor/linux-framework` 编译？

不一定。

当前从 vendor 编译的理由：

- 保证 image 中有 `bpftool`（`runner/containers/runner-runtime.Dockerfile:191-199`）。
- 和 vendored Linux tooling/UAPI 保持一致。
- unit tests 可构建 bootstrap bpftool 来 dump `vmlinux.h`（`tests/unittest/Makefile:104-110`）。

它大概率可替换的理由：

- runtime 使用的是普通 BPF inspect/control，不是 custom ReJIT syscall。`BPF_PROG_REJIT` 由 daemon 自己实现（`daemon/src/bpf.rs:38-41`）。
- Python 已支持从 env 或 PATH 解析 bpftool（`runner/libs/__init__.py:92-104`）。

实际建议：

- 不要直接写 `apt install bpftool`，除非先固定 apt source 并验证该包名存在。当前 Noble apt 配置下 `bpftool` 没有 standalone candidate。
- 更稳的是 per-arch 预编译 known-good `bpftool`，或者保留 vendor build 但只在 base/artifact layer 构建一次。
- 优先级低于 Katran/kernel 缓存。

### runner binary (C++) 做了什么？能否 Python 替代？

`micro_exec` 做：

- CLI dispatch：`list-programs`、`test-run`、`run-llvmbpf`（`runner/src/main.cpp:6-24`）。
- libbpf object open/load 和 program selection（`runner/src/kernel_runner.cpp:981-1017`）。
- `BPF_PROG_TEST_RUN` execution/timing（`runner/src/kernel_runner.cpp:429-441`，`runner/src/kernel_runner.cpp:1097-1132`）。
- JSON phase/code-size/perf 输出（`runner/src/kernel_runner.cpp:1146-1178`）。
- userspace llvmbpf 所需的 BPF ELF image extraction 和 relocation patching（`runner/src/elf_program_loader.cpp:548-598`，`runner/src/elf_program_loader.cpp:600-725`）。
- llvmbpf compile/execute path（`runner/src/llvmbpf_runner.cpp:623-689`，`runner/src/llvmbpf_runner.cpp:723-857`）。

不建议用 Python 替代。它不是简单 wrapper，而是低层 libbpf/LLVM/timing 组件。应该预编译或缓存，而不是重写。

### daemon binary (Rust) 做了什么？能否预编译？

daemon 是 ReJIT control plane：

- Unix socket JSON protocol（`daemon/README.md:31-82`）。
- 启动时 kinsn discovery 和 platform capability detection（`daemon/src/main.rs:46-72`）。
- `optimize`、`optimize-all`、`status` commands（`daemon/src/server.rs:459-789`）。
- `try_apply_one` 执行 pass pipeline 和最终 ReJIT（`daemon/src/commands.rs:440-452`）。

可以预编译。daemon 编译期不绑定某个 kernel build；runtime 会发现 capability/kfunc/BTF 状态。建议按 arch 发布/缓存 binary，并保留 smoke/e2e 验证。

### Katran 的 gRPC 编译能不能避免？

不能直接跳过，但可以优化掉 source-build gRPC。

当前 required artifact 是 `katran_server_grpc`（`runner/mk/build.mk:60`，`runner/suites/_common.py:131-149`）。该 target 需要 generated protobuf/gRPC C++ files，并链接 gRPC（`runner/repos/katran/example_grpc/CMakeLists.txt:24-39`，`runner/repos/katran/example_grpc/CMakeLists.txt:69-97`）。因此 `BUILD_EXAMPLE_GRPC=0` 会让 Katran runner 缺 artifact。

可行路径：

1. 预构建 Katran artifacts per arch。
2. 用系统 gRPC/protobuf dev packages 替换 `build_katran.sh` 的 gRPC source build，并 patch `grpc_cpp_plugin` 路径。
3. 预生成 protobuf outputs，减少 generation，但仍要链接 gRPC。

不建议用自写 loader 替代 Katran server；这会碰到 app-level loader 规则。

### micro benchmark 的 `.bpf.o` 能不能预编译？

可以。

它们是 deterministic benchmark input artifacts，由 `micro/programs/Makefile` 用 `clang -target bpf` 生成（`micro/programs/Makefile:7-16`），由 micro suite 消费（`runner/suites/micro.py:140-147`）。建议按 source hash + clang version 预构建，复制到 `/artifacts/user/micro-programs/<arch>`。

## 最小化编译时间的优先级建议

### P0: 预构建/缓存 Katran artifacts

这是最大可避免 userspace cost。产物应是 `repo-artifacts/<arch>/katran/{bin,lib,bpf}`，在 runtime image build 外生成并复制进来。

具体动作：

- 测试 system `libgrpc++`/protobuf packages 或预构建 gRPC prefix，停止每次 source-build gRPC/protobuf。
- final Katran CMake 已 `-DBUILD_TESTS=OFF`，应避免 `build_katran.sh` 仍 clone/install googletest。
- 避免 Katran 再 clone/build 一份 libbpf；复用 vendored libbpf 或 system libbpf。

### P1: 按架构预构建 custom kernel/modules/kinsn

stock apt kernel 不能替代 BPF ReJIT kernel，但 kernel image、modules、kinsn modules、manifest 可以预构建并复制。这对 AWS arm64 尤其重要，因为 `docker build --platform linux/arm64` 在 x86 builder 上通常会走 emulation。

### P1: 预构建或缓存 `bpfrejit-daemon`

使用 per-arch Rust builder artifact，或 Docker BuildKit cache mounts 缓存 Cargo registry/git/target。key 包括 `daemon/Cargo.toml`、`daemon/Cargo.lock`、`daemon/src/**`、Rust version、target triple。

### P1: 预构建或缓存 `micro_exec`

按架构构建 `micro_exec`，放独立 CMake layer 或 CI artifact。若保留本地构建，启用 ccache。key 包括 `runner/src/**`、`runner/include/**`、`vendor/llvmbpf/**`、`vendor/libbpf/**`、LLVM version、compiler version。

### P2: 预编译 micro `.bpf.o` 和 test artifacts

micro objects 很适合预构建。test artifacts 也可以按 arch cache。另一个设计是拆 benchmark runtime image 和 test runtime image；如果必须一个 image 支持所有默认 target，则至少把 test artifact 放独立 layer。

### P2: 替换或缓存 `bpftool`

使用 per-arch known-good prebuilt `bpftool`，或保留 vendor build 但移到稳定 base/artifact layer。不要在未验证 apt source 的情况下假设 `apt install bpftool` 可用。

### P2: 拆分 Docker cache 边界

final `runner-runtime` 当前一个大 `RUN` 同时构建 runner、micro programs、tests、daemon（`runner/containers/runner-runtime.Dockerfile:274-419`）。建议拆成：

- daemon build layer
- runner/libbpf/llvmbpf build layer
- micro BPF build layer
- test artifact build layer
- runtime copy/purge layer

这样无关 source 改动不会导致所有组件一起重编。

### P3: 保持 upstream app image 导入模式

Tracee、Tetragon、Cilium、Calico、Otel 已经是预编译 artifact 导入，这是正确方向。不要回退到本地源码构建这些 app。
