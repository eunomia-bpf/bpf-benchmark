# Native Corpus Build 调研与实现报告

日期: 2026-03-27

## 目标

把 corpus 构建从 `build_corpus_objects.py` 的 generic clang 单文件编译，扩展为优先走各 repo 自己的原生构建系统，并把产物统一收敛到：

- `.bpf.o`: `corpus/build/<repo>/...`
- 用户态 binary: `corpus/build/<repo>/bin/...`

保留 `runner/scripts/build_corpus_objects.py` 作为 fallback，不修改 `runner/repos/` 下的上游源码。

## 本次实现

已接入的原生构建 repo：

- `bcc`
- `libbpf-bootstrap`
- `xdp-tools`
- `xdp-tutorial`
- `scx`

新增入口：

- 根目录 `make corpus-build-native`
- 根目录 `make corpus-build-bcc`
- 根目录 `make corpus-build-libbpf-bootstrap`
- 根目录 `make corpus-build-xdp-tools`
- 根目录 `make corpus-build-xdp-tutorial`
- 根目录 `make corpus-build-scx`

对应 `runner/Makefile` 新增同名 target，并新增原生构建脚本：

- `runner/scripts/build_corpus_native.py`

## 统一输出布局

- `bcc`
  - `.bpf.o`: `corpus/build/bcc/libbpf-tools/*.bpf.o`
  - binary: `corpus/build/bcc/bin/*`
- `libbpf-bootstrap`
  - `.bpf.o`: `corpus/build/libbpf-bootstrap/examples/c/*.bpf.o`
  - binary: `corpus/build/libbpf-bootstrap/bin/*`
- `xdp-tools`
  - `.bpf.o`: `corpus/build/xdp-tools/*.bpf.o`
  - binary: `corpus/build/xdp-tools/bin/<tool>/<binary>`
- `xdp-tutorial`
  - `.bpf.o`: `corpus/build/xdp-tutorial/<lesson>/*.bpf.o`
  - binary: `corpus/build/xdp-tutorial/bin/<lesson>/<binary>`
- `scx`
  - `.bpf.o`: `corpus/build/scx/*.bpf.o`
  - binary: `corpus/build/scx/bin/*`

native stage 完成后会显式清理 `*.tmp.o` / `*.tmp.bpf.o` / `*.bpf.tmp.o`，最终目录只保留可消费产物。

## 已实现 repo 产出

| repo | 原生命令 | `.bpf.o` 数量 | binary 数量 | 示例 binary | 示例 `.bpf.o` |
| --- | --- | ---: | ---: | --- | --- |
| `bcc` | `make -C runner/repos/bcc/libbpf-tools -j$(nproc)` | 57 | 57 | `bindsnoop`, `biolatency`, `execsnoop` | `libbpf-tools/bindsnoop.bpf.o` |
| `libbpf-bootstrap` | `make -C runner/repos/libbpf-bootstrap/examples/c -j$(nproc)` | 14 | 14 | `bootstrap`, `minimal`, `fentry` | `examples/c/bootstrap.bpf.o` |
| `xdp-tools` | `make -C runner/repos/xdp-tools -j$(nproc)` | 13 | 7 | `xdp-loader`, `xdp-dump`, `xdp-bench` | `xdp_loader.bpf.o`, `xdp_monitor.bpf.o` |
| `xdp-tutorial` | `make -C runner/repos/xdp-tutorial -j$(nproc)` | 23 | 25 | `xdp_pass_user`, `xdp_loader`, `af_xdp_user` | `basic01-xdp-pass/xdp_pass_kern.bpf.o` |
| `scx` | `build_scx_artifacts.py --force` + Rust release build | 4 | 4 | `scx_rusty`, `scx_flash`, `scx_lavd` | `scx_rusty_main.bpf.o` |

binary 示例路径：

- `corpus/build/bcc/bin/bindsnoop`
- `corpus/build/libbpf-bootstrap/bin/bootstrap`
- `corpus/build/xdp-tools/bin/xdp-loader/xdp-loader`
- `corpus/build/xdp-tutorial/bin/packet01-parsing/xdp-loader`
- `corpus/build/scx/bin/scx_rusty`

## 各 repo 原生构建方式调研

### 1. bcc/libbpf-tools

- 构建文件
  - `runner/repos/bcc/libbpf-tools/Makefile`
- 原生命令
  - `make -C runner/repos/bcc/libbpf-tools -j$(nproc)`
- 主要依赖
  - `libbpf`
  - `bpftool`
  - `libelf`
  - `zlib`
  - clang BPF 头文件搜索路径
- 产物位置
  - binary: `runner/repos/bcc/libbpf-tools/<tool>`
  - `.bpf.o`: `runner/repos/bcc/libbpf-tools/.output/*.bpf.o`
- 本次实现状态
  - 已实现
- 接入时做的兼容处理
  - `LIBBPF_SRC` 指向仓库内 `vendor/libbpf/src`
  - `BPFTOOL` 指向 `runner/build/vendor/bpftool/bootstrap/bpftool`
  - `USE_BLAZESYM=0`
  - `CLANG` 增补 `-idirafter` 系统头文件目录，解决 `asm/*.h` 缺失

### 2. libbpf-bootstrap

- 构建文件
  - `runner/repos/libbpf-bootstrap/examples/c/Makefile`
- 原生命令
  - `make -C runner/repos/libbpf-bootstrap/examples/c -j$(nproc)`
- 主要依赖
  - `libbpf`
  - `bpftool`
  - `libelf`
  - `zlib`
  - `vmlinux.h`
- 产物位置
  - binary: `runner/repos/libbpf-bootstrap/examples/c/<app>`
  - `.bpf.o`: `runner/repos/libbpf-bootstrap/examples/c/.output/*.bpf.o`
- 本次实现状态
  - 已实现
- 接入时做的兼容处理
  - `LIBBPF_SRC` 和 `BPFTOOL` 均改指向仓库 vendor 版本
  - 复用 `corpus/build/**/vmlinux.h` 缓存，不在 host 上调用 `bpftool btf dump`
  - `CARGO=` 禁用可选 `profile/blazesym`
  - 上游 pattern rule 会把 `*.bpf.c` 和普通 `%.c` 规则串在一起，生成了临时 wrapper Makefile 显式展开 BPF 规则，避免 `minimal` / `bootstrap` 这类目标被 `%.o: %.c` 吞掉

### 3. katran

- 构建文件
  - `runner/repos/katran/CMakeLists.txt`
  - `runner/repos/katran/katran/CMakeLists.txt`
- 原生命令
  - `cmake -S runner/repos/katran -B <build-dir> && cmake --build <build-dir> -j$(nproc)`
- 主要依赖
  - `fmt`
  - `folly`
  - `glog`
  - `gflags`
  - `libzstd`
  - 线程库
- 产物位置
  - 预期 binary: CMake build tree
  - `.bpf.o`: 需要进一步绑定 Katran 的 BPF 构建脚本与输出路径
- 本次实现状态
  - 未实现
- 原因
  - 依赖栈明显重于当前已接入 repo，且需要独立 CMake build 目录与第三方 C++ 依赖解析；本轮优先先把 BCC 路线打通

### 4. xdp-tools

- 构建文件
  - `runner/repos/xdp-tools/Makefile`
- 原生命令
  - `make -C runner/repos/xdp-tools -j$(nproc)`
- 主要依赖
  - `libxdp`
  - `libbpf`
  - `bpftool`
- 产物位置
  - binary: `runner/repos/xdp-tools/<tool>/<binary>`
  - `.bpf.o`: repo 树下若干 `*.bpf.o`
- 本次实现状态
  - 已实现
- 接入时做的兼容处理
  - 显式传入 `BPFTOOL=runner/build/vendor/bpftool/bootstrap/bpftool`，否则 `xdp-bench` / `xdp-forward` / `xdp-monitor` / `xdp-trafficgen` 不会被纳入 `UTILS`

### 5. xdp-tutorial

- 构建文件
  - `runner/repos/xdp-tutorial/Makefile`
  - lesson 目录各自的 `Makefile`
- 原生命令
  - `make -C runner/repos/xdp-tutorial -j$(nproc)`
  - 某些额外 lesson 需要单独进入子目录执行
- 主要依赖
  - `xdp-tools/xdp-loader`
  - `libbpf`
  - clang/libelf 等
- 产物位置
  - binary: lesson 目录内可执行文件
  - `.o`: lesson 目录内 `*.o`，其中 BPF 对象需要按 ELF machine 筛选
- 本次实现状态
  - 已实现
- 接入时做的兼容处理
  - 先构建 `xdp-tools`
  - 主仓库构建后，再 best-effort 构建 `advanced03-AF_XDP` 和 `experiment01-tailgrow`
  - 通过 ELF `e_machine=EM_BPF` 过滤 BPF 对象，并统一改名为 `.bpf.o`
- 已知问题
  - `experiment01-tailgrow` 在当前环境下会因为 `/usr/include/bpf/bpf_helpers.h` 与教程头文件中的 `barrier_var` 宏冲突而失败
  - 当前脚本将其视为 warning 并跳过，不影响其余 lesson 的 stage 与验证

### 6. tracee

- 构建文件
  - `runner/repos/tracee/Makefile`
  - `runner/repos/tracee/go.mod`
- 原生命令
  - `make -C runner/repos/tracee bpf`
  - `make -C runner/repos/tracee tracee`
  - `make -C runner/repos/tracee evt`
  - `make -C runner/repos/tracee traceectl`
- 主要依赖
  - Go toolchain
  - clang/llvm 工具链
  - pkg-config / libbpf
  - repo 内部 `3rdparty/libbpf`
- 产物位置
  - `.bpf.o`: `runner/repos/tracee/dist/tracee.bpf.o`
  - binary: `runner/repos/tracee/dist/tracee`, `runner/repos/tracee/dist/evt`, `runner/repos/tracee/dist/traceectl`
- 本次实现状态
  - 未实现
- 原因
  - Makefile 较大，内部同时管理 libbpf 构建、CGO/Go 构建、多个发行目标；接入成本高于本轮的 Make/Cargo 直连型 repo

### 7. tetragon

- 构建文件
  - `runner/repos/tetragon/Makefile`
  - `runner/repos/tetragon/bpf/Makefile`
- 原生命令
  - `make -C runner/repos/tetragon tetragon-bpf LOCAL_CLANG=1`
  - `make -C runner/repos/tetragon tetragon`
  - `make -C runner/repos/tetragon tetra`
- 主要依赖
  - Go toolchain
  - clang
  - 默认还支持 containerized clang 路径
- 产物位置
  - `.bpf.o`: `runner/repos/tetragon/bpf/objs/*.o`
  - binary: repo 根目录下 `tetragon`, `tetra`, `tetragon-bench`
- 本次实现状态
  - 未实现
- 原因
  - BPF 侧和 userspace 侧分离明显，且默认路径倾向 container build；需要先明确 host-only 模式下的最小稳定变量组合

### 8. bpftrace

- 构建文件
  - 当前 `runner/repos/` 下未发现 `bpftrace`
- 原生命令
  - 理论上应为 CMake，但本仓库当前未 checkout 对应 repo
- 产物位置
  - 无
- 本次实现状态
  - 未实现
- 原因
  - repo 不在当前 corpus checkout 中

### 9. cilium

- 构建文件
  - `runner/repos/cilium/Makefile`
  - `runner/repos/cilium/bpf/Makefile`
  - `runner/repos/cilium/go.mod`
- 原生命令
  - `make -C runner/repos/cilium build`
  - 或单独 `make -C runner/repos/cilium/bpf`
- 主要依赖
  - 大量 Go 子模块
  - Cilium 多个子组件
  - BPF 代码生成
- 产物位置
  - `.bpf.o`: `runner/repos/cilium/bpf/*.o`
  - binary: `daemon`, `cilium-health`, `hubble`, `bugtool`, `plugins/cilium-cni` 等多个子组件输出
- 本次实现状态
  - 未实现
- 原因
  - 顶层 `build` 会递归多个子目录，不适合先用“统一收敛小脚本”快速接入；需要决定只收 `bpf/` + 哪些 agent/client binary 才有稳定价值

### 10. scx

- 构建文件
  - `runner/repos/scx/Cargo.toml`
  - `runner/repos/scx/lib/Makefile`
- 原生命令
  - `cargo build --release`
  - 或 `cargo build --release -p <scheduler>`
- 主要依赖
  - Rust toolchain
  - clang/bpftool
  - sched-ext 相关 BPF 构建环境
- 产物位置
  - binary: `runner/repos/scx/target/release/<scheduler>`
  - `.bpf.o`: `target/release/build/<pkg>/out/bpf.bpf.o`
- 本次实现状态
  - 已实现
- 接入方式
  - 复用仓库已有 `runner/scripts/build_scx_artifacts.py --force`
  - 再把 `target/release` 下的 `scx_bpfland` / `scx_flash` / `scx_lavd` / `scx_rusty` 复制到统一 `bin/`

## Makefile 接口

### 顶层

```bash
make corpus-build-native REPOS='bcc libbpf-bootstrap xdp-tools xdp-tutorial scx'
make corpus-build-bcc
make corpus-build-libbpf-bootstrap
make corpus-build-xdp-tools
make corpus-build-xdp-tutorial
make corpus-build-scx
```

### runner 层

```bash
make -C runner corpus-build-native REPOS='bcc libbpf-bootstrap xdp-tools xdp-tutorial scx'
make -C runner corpus-build-bcc
```

## 实际验证

2026-03-27 已在 host 上完成以下构建验证：

- `make corpus-build-bcc`
- `make corpus-build-libbpf-bootstrap`
- `make corpus-build-xdp-tools`
- `make corpus-build-xdp-tutorial`
- `make corpus-build-scx`
- `make corpus-build-native REPOS='bcc libbpf-bootstrap xdp-tools xdp-tutorial scx'`

代表性 binary 验证命令：

- `corpus/build/bcc/bin/bindsnoop -h`
- `corpus/build/libbpf-bootstrap/bin/bootstrap -h`
- `corpus/build/xdp-tools/bin/xdp-loader/xdp-loader --help`
- `corpus/build/xdp-tutorial/bin/packet01-parsing/xdp-loader --help`
- `corpus/build/scx/bin/scx_rusty --help`

最终聚合结果：

- `bcc`: 57 个 `.bpf.o`，57 个 binary，验证通过
- `libbpf-bootstrap`: 14 个 `.bpf.o`，14 个 binary，验证通过
- `xdp-tools`: 13 个 `.bpf.o`，7 个 binary，验证通过
- `xdp-tutorial`: 23 个 `.bpf.o`，25 个 binary，验证通过
- `scx`: 4 个 `.bpf.o`，4 个 binary，验证通过

## 已知限制

- `build_corpus_objects.py` 仍然需要保留，native build 目前只覆盖一部分 repo
- `libbpf-bootstrap` 依赖已有缓存 `vmlinux.h`，当前不在 host 上主动生成
- `xdp-tutorial/experiment01-tailgrow` 在当前环境下不是稳定可编译目标
- `katran` / `tracee` / `tetragon` / `cilium` 仍需逐个定义“值得 stage 的 binary 集合”和更明确的 host 依赖约束

## 下一步建议

1. 第二批优先接入 `tracee`
   - 它的输出结构最清晰，`dist/tracee.bpf.o` 与 `dist/tracee`/`evt`/`traceectl` 很适合统一 stage
2. 然后接入 `tetragon`
   - 先限定 `LOCAL_CLANG=1` 路径，只收 `tetragon`、`tetra` 和 `bpf/objs/*.o`
3. `katran` 与 `cilium` 放在第三批
   - 前者先解决 CMake 依赖闭包
   - 后者先收窄到最有价值的一组 BPF 对象和用户态二进制
