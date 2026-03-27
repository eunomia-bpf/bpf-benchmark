# Native Corpus Build 调研与实现报告

日期: 2026-03-27

## 目标

把 `runner/scripts/build_corpus_native.py` 从当前已支持的：

- `bcc`
- `libbpf-bootstrap`
- `xdp-tools`
- `xdp-tutorial`
- `scx`

扩展到剩余 repo：

- `katran`
- `tracee`
- `tetragon`
- `cilium`
- `bpftrace`

统一产物布局保持不变：

- `.bpf.o`: `corpus/build/<repo>/...`
- userspace binary: `corpus/build/<repo>/bin/...`

## 本次实现

### 代码改动

- 扩展 `runner/scripts/build_corpus_native.py`
  - 新增 `katran` builder
  - 新增 `tracee` builder
  - 新增 `tetragon` builder
  - 新增 `cilium` builder
  - 新增 `bpftrace` builder
  - native build 改为按 repo 继续执行，单 repo 失败或 partial 不阻塞全量
  - summary 输出新增 `status=ok|partial|failed` 和失败原因
- 更新 `runner/repos.yaml`
  - 新增 `bpftrace` checkout 配置
- 更新 `runner/Makefile`
  - 新增 `corpus-build-katran`
  - 新增 `corpus-build-tracee`
  - 新增 `corpus-build-tetragon`
  - 新增 `corpus-build-cilium`
  - 新增 `corpus-build-bpftrace`
- 更新顶层 `Makefile`
  - 暴露同名 target，支持直接在 repo 根目录执行 `make corpus-build-<repo>`

### 当前已接入 native build 的 repo

- `bcc`
- `libbpf-bootstrap`
- `xdp-tools`
- `xdp-tutorial`
- `scx`
- `katran`
- `tracee`
- `tetragon`
- `cilium`
- `bpftrace`

## 各 repo 接入方式

### 1. katran

- 构建方式
  - 不走完整 CMake
  - 复用上游 `katran/lib/Makefile-bpf`
  - 在临时 build 目录准备 `bpf/`、`include/`、`katran/lib/{bpf,linux_includes}`
- 产物
  - `.bpf.o`: 5 个
  - binary: 0
- stage 布局
  - `corpus/build/katran/*.bpf.o`
- 结果
  - `ok`

### 2. tracee

- 构建方式
  - 直接走上游 Makefile
  - 执行 `make bpf tracee evt traceectl lsm-check`
- 产物
  - `.bpf.o`: 3 个
  - binary: 4 个
- stage 布局
  - `corpus/build/tracee/tracee.bpf.o`
  - `corpus/build/tracee/lsm_support/*.bpf.o`
  - `corpus/build/tracee/bin/{tracee,evt,traceectl,lsm-check}`
- 结果
  - `ok`

### 3. tetragon

- 构建方式
  - 直接走上游 Makefile
  - 执行 `make tetragon-bpf LOCAL_CLANG=1`
  - 将 `bpf/objs/*.o` 中的 BPF ELF 统一改名 stage 为 `.bpf.o`
- 产物
  - `.bpf.o`: 86 个
  - binary: 0
- stage 布局
  - `corpus/build/tetragon/*.bpf.o`
- 结果
  - `ok`
- 说明
  - 当前 checkout 只覆盖 BPF 侧，未把 userspace `cmd/*` 纳入稳定 stage 范围

### 4. cilium

- 构建方式
  - 不走顶层 `make build`
  - 不走 `bpf/Makefile` 默认 `generate`
  - 直接调用显式对象 target：
    - `bpf_lxc.o`
    - `bpf_overlay.o`
    - `bpf_sock.o`
    - `bpf_host.o`
    - `bpf_wireguard.o`
    - `bpf_xdp.o`
    - `bpf_alignchecker.o`
- 产物
  - `.bpf.o`: 7 个
  - binary: 0
- stage 布局
  - `corpus/build/cilium/*.bpf.o`
- 结果
  - `ok`
- 说明
  - `bpf/Makefile` 默认会进入 `generate`，但当前 sparse checkout 缺 `pkg/datapath/*`
  - 因此本轮只接 BPF 对象阶段

### 5. bpftrace

- 构建方式
  - 先尝试最小 CMake userspace build
    - `cmake -DBUILD_TESTING=OFF -DENABLE_MAN=OFF -DENABLE_SKB_OUTPUT=OFF -DUSE_SYSTEM_LIBBPF=ON`
  - userspace configure 失败后，额外对 `src/stdlib/**/*.bpf.c` 做 best-effort BPF 编译并统一 stage
- 产物
  - `.bpf.o`: 7 个
  - binary: 0
- stage 布局
  - `corpus/build/bpftrace/stdlib/**/*.bpf.o`
- 结果
  - `partial`
- 失败原因
  - userspace CMake configure 缺少 `libcereal` 开发包
  - `src/stdlib/task/vma.bpf.c` 与当前缓存 `vmlinux.h` 的 kfunc 原型冲突
  - `src/stdlib/usdt/usdt.bpf.c` 在当前系统 `usdt.bpf.h` / 类型定义组合下编译失败

## 统一输出布局

当前 10 个 native repo 的 stage 约定如下：

| repo | `.bpf.o` stage | binary stage |
| --- | --- | --- |
| `bcc` | `corpus/build/bcc/libbpf-tools/*.bpf.o` | `corpus/build/bcc/bin/*` |
| `libbpf-bootstrap` | `corpus/build/libbpf-bootstrap/examples/c/*.bpf.o` | `corpus/build/libbpf-bootstrap/bin/*` |
| `xdp-tools` | `corpus/build/xdp-tools/*.bpf.o` | `corpus/build/xdp-tools/bin/<tool>/<binary>` |
| `xdp-tutorial` | `corpus/build/xdp-tutorial/<lesson>/*.bpf.o` | `corpus/build/xdp-tutorial/bin/<lesson>/<binary>` |
| `scx` | `corpus/build/scx/*.bpf.o` | `corpus/build/scx/bin/*` |
| `katran` | `corpus/build/katran/*.bpf.o` | 无 |
| `tracee` | `corpus/build/tracee/**/*.bpf.o` | `corpus/build/tracee/bin/*` |
| `tetragon` | `corpus/build/tetragon/*.bpf.o` | 无 |
| `cilium` | `corpus/build/cilium/*.bpf.o` | 无 |
| `bpftrace` | `corpus/build/bpftrace/stdlib/**/*.bpf.o` | 无 |

## Makefile 入口

### 顶层

```bash
make corpus-build-native
make corpus-build-katran
make corpus-build-tracee
make corpus-build-tetragon
make corpus-build-cilium
make corpus-build-bpftrace
```

### runner 层

```bash
make -C runner corpus-build-native
make -C runner corpus-build-katran
make -C runner corpus-build-tracee
make -C runner corpus-build-tetragon
make -C runner corpus-build-cilium
make -C runner corpus-build-bpftrace
```

## 实际验证

### 新增 repo 单项验证

已执行：

- `make corpus-build-katran`
- `make corpus-build-tracee`
- `make corpus-build-tetragon`
- `make corpus-build-cilium`
- `make corpus-build-bpftrace`

对应 stage 目录确认：

- `find corpus/build/katran -maxdepth 2 -type f`
- `find corpus/build/tracee -maxdepth 3 -type f`
- `find corpus/build/tetragon -maxdepth 2 -type f`
- `find corpus/build/cilium -maxdepth 2 -type f`
- `find corpus/build/bpftrace -maxdepth 4 -type f`

### 全量验证

已执行：

```bash
make corpus-build-native
```

结果：

- 全量命令返回成功
- `bpftrace` 为 `partial`
- 其余 9 个 repo 为 `ok`
- `partial` 不阻塞其他 repo 的构建和 stage

### 最终 native build 结果

| repo | status | `.bpf.o` | binary | 备注 |
| --- | --- | ---: | ---: | --- |
| `bcc` | `ok` | 57 | 57 | 已有实现，验证通过 |
| `libbpf-bootstrap` | `ok` | 14 | 14 | 已有实现，验证通过 |
| `xdp-tools` | `ok` | 13 | 7 | 已有实现，验证通过 |
| `xdp-tutorial` | `ok` | 23 | 25 | `experiment01-tailgrow` 仍按 warning 跳过 |
| `scx` | `ok` | 4 | 4 | 已有实现，验证通过 |
| `katran` | `ok` | 5 | 0 | BPF-only |
| `tracee` | `ok` | 3 | 4 | `tracee/evt/traceectl/lsm-check` |
| `tetragon` | `ok` | 86 | 0 | BPF-only |
| `cilium` | `ok` | 7 | 0 | BPF-only |
| `bpftrace` | `partial` | 7 | 0 | `libcereal` 缺失，`vma/usdt` 未过 |

## 已知限制

- `build_corpus_objects.py` 仍需保留，native build 目前只覆盖部分 corpus repo
- `katran` 当前只接 BPF 侧，未接完整 CMake userspace
- `tetragon` 当前只接 `tetragon-bpf`，未 stage userspace binary
- `cilium` 当前只接显式 BPF 对象 target，未接 userspace binary
- `bpftrace` 当前是 partial
  - userspace 受 `libcereal` 依赖阻塞
  - stdlib 里的 `vma/usdt` 仍需单独兼容处理

## 结论

剩余 5 个 repo 已全部纳入 `build_corpus_native.py` 的 native 路径。

其中：

- `katran`
- `tracee`
- `tetragon`
- `cilium`

已经达到当前环境下的稳定可用状态。

`bpftrace` 已完成 fetch、builder 接入、stage 输出与 partial 失败记录，但在当前 host 依赖与头文件组合下尚未达到完整成功。整体全量 `make corpus-build-native` 已能跑完，并把 partial repo 的原因写入 summary，而不会阻塞其他 repo。 
