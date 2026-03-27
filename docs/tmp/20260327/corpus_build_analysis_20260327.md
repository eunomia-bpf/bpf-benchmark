# Corpus Build Analysis (2026-03-27)

## TL;DR

- 当前用户入口确实是 `make corpus-build`，但真正的 repo 构建并不是调用各 repo 自己的 `Makefile`/`CMake`/`Meson`，而是 `runner/scripts/build_corpus_objects.py` 用一条统一的 `clang` 命令逐个源文件编译。
- 当前报告快照里一共考虑了 `1213` 个对象来源，其中 `1077` 个是源码编译尝试，只有 `429` 个成功，源码成功率 `39.8%`。另外 `136` 个只是把 `macro_corpus.yaml` 里已经存在的对象标成 `existing`，所以总可用对象是 `565`，整体可用率 `46.6%`。
- `648` 个 clang 失败里，至少 `531` 个是直接的 include path 问题：
  - `504` 个缺 arch/uapi asm 头。
  - `27` 个缺 repo 私有头目录，全部来自 `tetragon`。
- 剩下主要是 `linux-selftests` 的内核头 / helper 声明 / `vmlinux.h` 不匹配。它单 repo 就占了 `555/648` 个失败。
- 当前最值得做的不是先“换 clang 版本”，而是把构建模式分层：
  - 简单 repo 继续走 generic clang。
  - 需要少量参数的 repo 补 per-repo include/flags。
  - `linux-selftests`、`cilium`、`tetragon`、`systemd`、`netbird` 这类 repo 改为复用上游原生构建。

## 1. 当前构建流程

### 1.1 用户入口

根 `Makefile` 里的 `corpus-build` 只是透传：

```make
corpus-build:
	$(MAKE) -j"$(JOBS)" -C "$(RUNNER_DIR)" JOBS="$(JOBS)" PYTHON="$(PYTHON)" REPOS="$(REPOS)" corpus-build
```

`runner/Makefile` 才是真入口：

```make
REPOS ?=
REPO_FLAGS := $(foreach repo,$(REPOS),--repo $(repo))

corpus-fetch:
	$(PYTHON) $(ROOT_DIR)/scripts/fetch_corpus_repos.py $(REPO_FLAGS)

corpus-build-objects:
	$(PYTHON) $(ROOT_DIR)/scripts/build_corpus_objects.py $(REPO_FLAGS)

corpus-build: corpus-fetch corpus-build-objects
```

结论：

- 用户看到的是 `make corpus-build`。
- 实际 fetch 是 `fetch_corpus_repos.py`。
- 实际 compile 是 `build_corpus_objects.py`。
- `REPOS="a b c"` 会被展开成多个 `--repo a --repo b --repo c`。

### 1.2 fetch 阶段

`runner/scripts/fetch_corpus_repos.py` 的行为：

- 读取 `runner/repos.yaml`。
- 对每个 repo 执行 `git clone --depth 1 --filter=blob:none --sparse --branch <branch>`。
- 如果 repo 已存在，则 `git fetch --depth 1 origin <branch>`，然后更新到对应分支。
- 如果 manifest 里有 `sparse_paths`，就执行 `git sparse-checkout set ...`。

这一步不区分 repo 是“源码编译型”还是“仅 staging 预构建对象型”。因此当前 generic build 仍然会拉很多根本不会被源码编译的 repo。

### 1.3 build 阶段

`runner/scripts/build_corpus_objects.py` 的核心逻辑是：

1. 读取 `runner/repos.yaml`。
2. 对每个 repo 用 `harvest_globs` 收集源文件，再减去 `exclude_globs`。
3. 为每个 repo 在 `corpus/build/<repo>/vmlinux.h` 下生成一个 `vmlinux.h`。
4. 对每个源文件执行统一 clang 编译。
5. 成功后再执行 `bpftool gen object` 生成最终 `.bpf.o`。
6. 最后读取 `corpus/config/macro_corpus.yaml`，把其中已经存在于 `corpus/build/...` 的对象标记为 `existing`。
7. 输出：
  - `corpus/results/expanded_corpus_build.latest.json`
  - `corpus/results/expanded_corpus_build.md`

### 1.4 当前实际编译命令

当前不是 per-repo native build，而是统一命令模板：

```bash
clang -O2 -g -target bpf -D__TARGET_ARCH_<arch> \
  -I <repo_build_root_for_vmlinux.h> \
  -I vendor/linux-framework/tools/lib \
  -I vendor/linux-framework/tools/lib/bpf \
  -I vendor/linux-framework/tools/include \
  -I vendor/linux-framework/tools/include/uapi \
  -I vendor/linux-framework/include \
  -I vendor/linux-framework/include/uapi \
  -I vendor/libbpf/include/uapi \
  -I vendor/libbpf/include \
  -I vendor/libbpf/src \
  -I <compile_include_dirs from repos.yaml> \
  [-include <forced_includes from repos.yaml>] \
  -c <source> -o <temp>.tmp.o

bpftool gen object <final>.bpf.o <temp>.tmp.o
```

参数来源如下：

- 全局 include path：硬编码在 `build_corpus_objects.py` 的 `GLOBAL_INCLUDE_DIRS`。
- repo include path：来自 `runner/repos.yaml` 的 `compile_include_dirs`。
- 强制 include：来自 `runner/repos.yaml` 的 `forced_includes`。
- `__TARGET_ARCH_*`：由脚本根据当前机器架构推断。
- `vmlinux.h`：由 `bpftool btf dump file /sys/kernel/btf/vmlinux format c` 生成。

当前没有的东西：

- 没有 per-repo `CFLAGS` / `-D` 宏。
- 没有 per-repo `clang` 版本选择。
- 没有运行 repo 的 `configure` / `meson setup` / `go generate`。
- 没有生成 repo 自己依赖的 `config.h`、feature headers、variant objects。
- 没有使用 repo 原生 Makefile/CMake/Meson 的对象命名和产物布局。

### 1.5 macro corpus 的作用

`corpus/config/macro_corpus.yaml` 在这里的作用不是“触发构建”，而是：

- 列出 `corpus/build/...` 下期望存在的对象。
- 如果对象已经存在，就记成 `existing`。
- 如果不存在，就在报告里记成 `missing_object`。

因此很多 repo 现在实际上是“预构建对象 staging”，并不是通过当前 generic builder 现编译出来的。

## 2. 当前构建结果

### 2.1 报告快照

基于 `corpus/results/expanded_corpus_build.latest.json` / `.md`：

| 指标 | 数值 |
| --- | ---: |
| Sources considered | 1213 |
| Built from source | 429 |
| Staged existing objects | 136 |
| Available objects | 565 |
| Failures | 648 |
| Source-backed total | 1077 |
| Source-backed success rate | 39.8% |
| Overall availability | 46.6% |

### 2.2 live build 目录

当前目录实际扫描得到 `568` 个 `.bpf.o`，比报告多 `3` 个：

- `corpus/build/datadog-agent/noisy-neighbor-kern.bpf.o`
- `corpus/build/linux-selftests/minimal_sched_ext.bpf.o`
- `corpus/build/netbird/client/internal/ebpf/ebpf/src/prog.bpf.o`

这说明：

- `corpus/build` 不是 hermetic snapshot。
- 当前目录里有增量残留对象。
- 真正可信的统计应以 JSON/MD 报告为准，而不是直接扫目录。

建议后续补一个 `corpus-clean` / `corpus-build-fresh`，避免旧对象污染结果。

### 2.3 按 repo 的源码构建成功率

下面只看真的走了源码编译的 repo：

| Repo | source_files | ok | error | success rate | existing |
| --- | ---: | ---: | ---: | ---: | ---: |
| bcc | 57 | 57 | 0 | 100.0% | 0 |
| libbpf-bootstrap | 15 | 11 | 4 | 73.3% | 1 |
| linux-selftests | 916 | 361 | 555 | 39.4% | 7 |
| netbird | 1 | 0 | 1 | 0.0% | 1 |
| katran | 2 | 0 | 2 | 0.0% | 5 |
| systemd | 6 | 0 | 6 | 0.0% | 8 |
| cilium | 9 | 0 | 9 | 0.0% | 3 |
| xdp-examples | 13 | 0 | 13 | 0.0% | 0 |
| xdp-tools | 14 | 0 | 14 | 0.0% | 13 |
| xdp-tutorial | 16 | 0 | 16 | 0.0% | 25 |
| tetragon | 28 | 0 | 28 | 0.0% | 23 |

结论：

- 目前 generic builder 真正“完全适配”的 repo 基本只有 `bcc`。
- `libbpf-bootstrap` 也基本可用，但还有明显的 include 问题。
- 失败的大头绝对不是“到处均匀失败”，而是高度集中在少数几类仓库。

### 2.4 失败最多的 repo

| Repo | failures | 占全部失败比例 |
| --- | ---: | ---: |
| linux-selftests | 555 | 85.6% |
| tetragon | 28 | 4.3% |
| xdp-tutorial | 16 | 2.5% |
| xdp-tools | 14 | 2.2% |
| xdp-examples | 13 | 2.0% |
| cilium | 9 | 1.4% |
| systemd | 6 | 0.9% |
| libbpf-bootstrap | 4 | 0.6% |
| katran | 2 | 0.3% |
| netbird | 1 | 0.2% |

## 3. 648 个 clang 失败的主要原因

### 3.1 分类结果

按“第一个可行动根因”做互斥分类：

| 分类 | Count | Share | 主要 repo |
| --- | ---: | ---: | --- |
| 缺 arch/uapi asm 头 | 504 | 77.8% | linux-selftests, xdp-*, cilium, systemd, libbpf-bootstrap, katran, netbird |
| 缺 repo 私有 include 目录 | 27 | 4.2% | tetragon |
| 内核头 / helper 声明冲突 | 87 | 13.4% | linux-selftests |
| 内核 BTF / API 不匹配 | 28 | 4.3% | linux-selftests, tetragon |
| 其它依赖定义缺失 | 2 | 0.3% | linux-selftests |

换句话说：

- `531/648 = 81.9%` 的失败本质上是 include path 问题。
- 另外 `115/648 = 17.7%` 是更深层的 kernel header / helper / `vmlinux.h` 版本匹配问题。

### 3.2 缺头文件是不是主因？

是，绝对是主因。

最常见缺失：

| 缺失头 | Count |
| --- | ---: |
| `asm/types.h` | 498 |
| `api.h` | 23 |
| `asm/socket.h` | 5 |
| `compiler.h` | 4 |
| `asm/unistd_64.h` | 1 |

其中：

- `asm/types.h` 基本横扫了 `linux-selftests`、`xdp-tools`、`xdp-tutorial`、`xdp-examples`、`systemd`、`libbpf-bootstrap`、`cilium`、`katran`、`netbird`。
- `api.h` / `compiler.h` 全部来自 `tetragon`，因为这些头实际在 `runner/repos/tetragon/bpf/include/`，但 manifest 没把这个目录加进去。

### 3.3 clang 版本问题是不是主因？

不是主因，但它是次级问题。

当前工具链：

- `clang`: `Ubuntu clang version 18.1.3 (1ubuntu1)`
- `bpftool`: `v7.7.0`

我统计到有 `137` 个失败的 stderr 含有 `Stack dump:` 或 `PLEASE submit a bug report`，分布如下：

| Repo | 带 crash 栈的失败数 |
| --- | ---: |
| linux-selftests | 105 |
| xdp-tools | 9 |
| cilium | 7 |
| xdp-tutorial | 7 |
| xdp-examples | 5 |
| katran | 2 |
| libbpf-bootstrap | 1 |
| netbird | 1 |

这说明：

- clang 18 确实会在一部分复杂源文件上崩。
- 但这些 crash 多数并不是第一根因，很多是前面已经出现了缺头或 AST/类型冲突后，clang 又继续崩掉。
- 所以“先降 clang 版本”不是第一优先级。

一个需要注意的例外是 `netbird`：它上游 `go:generate` 明确写的是 `bpf2go -cc clang-14 ... -- -I /usr/x86_64-linux-gnu/include`。这说明它本来就不是“任意 clang 即可”。

### 3.4 内核头 / `vmlinux.h` 版本不匹配是不是主因？

对 `linux-selftests` 来说，是第二大主因，而且比 clang 版本更关键。

代表性问题：

- `bpf_experimental.h` 里的 `bpf_path_d_path(const struct path *...)` 与当前生成出来的 `vmlinux.h` 里的 `bpf_path_d_path(struct path *...)` 冲突。
- `bpf_kfuncs.h` 里的 `bpf_dynptr_slice(..., __u64 offset, ..., __u64 ...)` 与当前 `vmlinux.h` 的 `u32` 版本冲突。
- `bad_struct_ops.c` 同时出现 `wchar_t` / `intptr_t` / `uintptr_t` 重定义。
- 多个 selftest 直接引用了当前 `vmlinux.h` 里不存在的 struct 成员或 helper，例如：
  - `tcp_retransmit_timer`
  - `icsk_keepalive_timer`
  - `bpf_qdisc_skb_drop`
  - `bpf_get_mem_cgroup_from_task`

根因不是单纯“头没加够”，而是当前 generic builder 的 `vmlinux.h` 来自：

```bash
bpftool btf dump file /sys/kernel/btf/vmlinux format c
```

也就是宿主机正在运行的 kernel BTF，而不是 repo / benchmark 自己的 kernel 视图。  
这和仓库里“优先用 repo/source-tree headers，不要依赖 host kernel headers”的约束方向是相反的。

## 4. 当前 repo 构建方式观察

### 4.1 当前 builder 是不是统一 clang？

是。

- 所有 `harvest_globs` 找到的源文件都走同一套 clang 模板。
- 每个 repo 只有 include path 和 forced include 可配置。
- 没有 repo 自己的 Makefile / CMake / Meson / `go generate` 被调用。

### 4.2 哪些 repo 已经有自己的构建系统可复用？

| Repo | 上游构建方式 | 当前 generic 适配度 | 结论 |
| --- | --- | --- | --- |
| bcc | `libbpf-tools/Makefile` | 已经 57/57 成功 | 继续 generic 即可 |
| libbpf-bootstrap | `examples/c/Makefile` | 11/15 成功 | 可 generic，也可直接复用 Makefile |
| xdp-tools | `configure` + `Makefile` | 0/14 | 至少要复用其 `configure` 产出的 `ARCH_INCLUDES` / `BPF_CFLAGS` |
| xdp-tutorial | `configure` + `Makefile` | 0/16 | 同上 |
| xdp-examples | `configure` + `Makefile` | 0/13 | 同上 |
| tetragon | `bpf/Makefile`，会产出多组 variant object | 0/28 | 应改 native build |
| cilium | `bpf/Makefile` + `Makefile.bpf`，大量 feature define/permutation | 0/9 | 应改 native build |
| systemd | Meson custom target，依赖 `config.h`、`vmlinux-h-path`、`bpftool gen object` | 0/6 | 应改 native build |
| linux-selftests | upstream selftests Makefile / kbuild 辅助规则 | 361/916 | 应改 native build |
| netbird | `go generate` / `bpf2go`, 且 pin `clang-14` | 0/1 | 应改 native build |
| katran | CMake 主要看起来是用户态库构建 | 0/2 | 先尝试 include 修复，必要时再定制 |
| scx | 已有 `scx-artifacts` 专用 target | 不走 generic source build | 保持专用流程 |

### 4.3 重要 repo 的具体观察

#### xdp-tools / xdp-tutorial / xdp-examples

这三类 repo 的上游流程都类似：

- 先跑 `configure`
- `configure` 生成 `config.mk`
- `config.mk` 写入 `ARCH_INCLUDES=-I/usr/include/x86_64-linux-gnu`
- 后续所有 BPF 编译都继承这个值

当前 builder 没有执行这个准备步骤，所以整批卡在 `asm/types.h`。

#### libbpf-bootstrap

它的 `examples/c/Makefile` 已经明确说明，为了处理 `asm/types.h` / `asm/socket.h` / `sys/cdefs.h` 一类问题，它会把 clang 默认系统 include 路径以 `-idirafter` 形式重新注入到 BPF 编译里。  
这和当前 generic builder 的问题正好对上。

#### tetragon

`tetragon/bpf/Makefile` 不是“一个 `.c` 对一个 `.o`”这么简单：

- 它有 `v310` / `v53` / `v511` / `v61` 等 variant object。
- 同一个源文件会衍生出多个对象。
- 其 `Makefile.defs` 里还有自己的 `CLANG_FLAGS`、`-mcpu=v2`、`-D__TARGET_ARCH_*`、本地 include 布局。

当前 manifest 只扫描 `bpf/**/*.c`，再套一个统一 clang，这和上游真实产物模型差别很大。

#### cilium

`cilium/bpf/Makefile` / `Makefile.bpf` 也不是简单单文件构建：

- 使用自己的 `CLANG_FLAGS`。
- 明确带 `-nostdinc`。
- 每个大对象有大量 feature permutations。
- `BPF2GO_CFLAGS` 由上游构建系统控制。

当前 generic builder 既没有这些宏定义，也没有 permutations。

#### systemd

`systemd` 的 Meson 已经把这些事情都封装了：

- `bpf_o_unstripped_cmd`
- `bpftool gen object`
- `config.h` 强制 include
- `vmlinux-h-path` / `generated vmlinux.h`
- libbpf include path

所以它不是“多给几个 `-I` 就能变好”的 repo。

#### linux-selftests

它本来就依赖 upstream selftests 自己的 build harness：

- `tools/testing/selftests/bpf/Makefile`
- `tools/include`
- `tools/arch/<arch>/include`
- `VMLINUX_BTF`
- `LLVM` 相关设置

当前 generic builder 没有复用这些机制，而且 `vmlinux.h` 取自宿主机 `/sys/kernel/btf/vmlinux`，这也是它大规模 mismatch 的根因。

## 5. 改进建议

### 5.1 哪些失败可以通过修 include paths 解决？

可以明显通过 include path 修掉的失败至少有 `531` 个：

- `504` 个缺 arch/uapi asm 头：
  - `linux-selftests`: 439
  - `xdp-tutorial`: 16
  - `xdp-tools`: 14
  - `xdp-examples`: 13
  - `cilium`: 9
  - `systemd`: 6
  - `libbpf-bootstrap`: 4
  - `katran`: 2
  - `netbird`: 1
- `27` 个缺 repo 私有头目录：
  - 全部 `tetragon`

建议分两层做：

1. generic builder 增加“系统/多架构 include 发现”：
   - 优先保留现有 repo/vendor include 在前。
   - 再把 clang 或 gcc multiarch include 以 `-idirafter` 注入。
   - 实现方式可参考 `libbpf-bootstrap` 和 `systemd`。

2. manifest 增加 per-repo extra include：
   - `tetragon` 追加 `bpf/include`。
   - 未来允许声明 `system_include_dirs` / `system_include_mode`。

### 5.2 哪些 repo 的 Makefile/CMake/Meson 值得复用？

优先级从高到低：

1. `linux-selftests`
   - 必须优先改 native build。
   - 这是最大失败源，且 generic 模式天然不可靠。

2. `tetragon`
   - 需要上游 `bpf/Makefile` 的 variant build 逻辑。

3. `cilium`
   - 需要上游 `bpf/Makefile` / `Makefile.bpf` 的宏定义和对象矩阵。

4. `systemd`
   - 需要上游 Meson 生成 `config.h` 和管理 `vmlinux.h`。

5. `netbird`
   - 需要 `go generate` / `bpf2go`，并支持 repo 指定的 clang 版本。

6. `xdp-tools` / `xdp-tutorial` / `xdp-examples`
   - 短期可以只借用 `configure` 结果。
   - 中期也可以直接复用上游 Makefile。

`bcc` 可以先继续走 generic；它已经 100% 成功，不值得优先改成 native。

### 5.3 是否应该为不同 repo 定制构建参数？

应该，而且应该从 manifest 层面显式建模，而不是继续把所有 repo 压成同一种 clang 模式。

建议在 `runner/repos.yaml` 里增加类似字段：

```yaml
build_mode: generic | make | meson | cmake | go_generate | cargo | prebuilt
prepare:
  - ./configure
build:
  - make -C bpf
collect_globs:
  - build/**/*.bpf.o
extra_cflags:
  - -D...
system_include_mode: none | clang-default | gcc-multiarch
clang: clang | clang-14
vmlinux_source: host-btf | vendor-vmlinux | explicit-path
```

推荐分三类：

- `generic`
  - 适合 `bcc`、可能也适合 `libbpf-bootstrap`
- `generic+repo-params`
  - 适合 `xdp-tools`、`xdp-tutorial`、`xdp-examples`、`katran`
- `native`
  - 适合 `linux-selftests`、`tetragon`、`cilium`、`systemd`、`netbird`

### 5.4 `vmlinux.h` 来源应改掉

这是一个关键点。

当前：

- 永远从宿主机 `/sys/kernel/btf/vmlinux` 生成。

问题：

- 结果依赖 host kernel。
- 与 repo 自己的源码视图可能不匹配。
- 与 benchmark 实际目标 kernel 也可能不匹配。

建议：

- 默认改为从 `vendor/linux-framework/vmlinux` 生成。
- 或至少允许显式传入 `VMLINUX_BTF=<path>`。
- `linux-selftests` / `systemd` 这类 repo 应优先使用 repo / benchmark kernel 视图，而不是 host。

### 5.5 fetch 也要分层

现在很多 repo 在当前 generic build 下根本没有源码编译输入，却仍然被完整拉取：

| Repo | Size | 当前 source_files |
| --- | ---: | ---: |
| scx | 1.6G | 0 |
| datadog-agent | 294M | 0 |
| calico | 70M | 0 |
| KubeArmor | 49M | 0 |
| suricata | 41M | 0 |

建议：

- 给 manifest 增加 `prebuilt_only: true` 或 `build_mode: prebuilt`。
- generic `corpus-fetch` 默认只拉 source-backed repo。
- native build 再按需拉对应 repo。
- 对大 repo 补 `sparse_paths`。

## 6. 推荐的 Makefile target 设计

我不建议直接把现有 `corpus-build` 语义改掉，因为它现在已经表示“generic fetch + generic clang compile”。  
更稳妥的是保留它，再增加更高层的一键目标。

### 6.1 runner/Makefile 建议新增

#### `corpus-clean`

用途：

- 只清理 `corpus/build` 和 `corpus/results/expanded_corpus_build.*`
- 避免旧对象污染统计

#### `corpus-build-generic`

用途：

- 语义等同今天的 `corpus-build-objects`
- 只处理 `build_mode=generic` 的 repo

#### `corpus-build-native`

用途：

- 调 repo 原生构建
- 负责 `make` / `meson` / `go generate`
- 把最终 `.bpf.o` 复制或收集到 `corpus/build/<repo>/...`

#### `corpus-build-all`

建议依赖链：

```make
corpus-build-all: corpus-fetch corpus-build-native corpus-build-generic
```

语义：

- 一键获取“尽可能多 repo 可成功构建”的 corpus
- 同时保留 `REPOS=` 过滤

#### `corpus-build-fresh`

建议依赖链：

```make
corpus-build-fresh: corpus-clean corpus-build-all
```

语义：

- 获取干净、可复现的统计
- 用于 CI 和正式报告

### 6.2 根 Makefile 建议镜像同名 target

根 `Makefile` 继续保持 thin wrapper，只做透传：

- `corpus-clean`
- `corpus-build-generic`
- `corpus-build-native`
- `corpus-build-all`
- `corpus-build-fresh`

### 6.3 `vm-corpus` 的建议

短期：

- 保持 `vm-corpus` 依赖当前 `corpus-build` 不变，避免突然改变现有行为。

中期：

- 增加 `vm-corpus-expanded` 或让 `vm-corpus` 切到 `corpus-build-all`。

我更推荐先新增：

```make
vm-corpus-expanded: corpus-build-all ...
```

这样不会影响已有 baseline。

## 7. 建议的实施优先级

### 第一阶段：低风险高收益

1. 给 generic builder 增加 system/multiarch include 注入。
2. 给 `tetragon` manifest 增加 `bpf/include`。
3. 让 `vmlinux.h` 来源可配置，不再硬编码 host `/sys/kernel/btf/vmlinux`。
4. 增加 `corpus-clean` / `corpus-build-fresh`。

预期收益：

- 直接改善 `531` 个 include 类失败。

### 第二阶段：把最不适合 generic 的 repo 切到 native

1. `linux-selftests`
2. `tetragon`
3. `cilium`
4. `systemd`
5. `netbird`

预期收益：

- 解决当前 generic builder 最核心的不适配 repo。
- 让对象产物更接近 repo 自己真实使用的编译方式。

### 第三阶段：优化 fetch 成本和 manifest 模型

1. 给 repo 标注 `build_mode`。
2. 跳过 `prebuilt_only` repo 的无效 fetch。
3. 对大 repo 增加 `sparse_paths`。
4. 统一 native build 的收集和报告格式。

## 8. 最终判断

当前 corpus 的主要问题不是“clang 太新”或“单个 repo 坏了”，而是：

- 当前 builder 过度统一。
- 它只支持 include path 级别的 repo 差异。
- 但真实 repo 的差异远不止 include path：
  - 有的 repo 需要 `configure`
  - 有的需要 `config.h`
  - 有的需要 `go generate`
  - 有的需要 variant build
  - 有的需要特定 `vmlinux.h`
  - 有的需要固定 clang 版本

因此，要让更多 repo 成功构建，正确方向不是继续在一个统一 clang 命令上打补丁，而是：

- 短期先补 include path 和 `vmlinux.h` 来源。
- 中期把明显需要原生构建的 repo 切到 native build。
- 长期在 manifest 中显式描述 repo 的构建模式。

