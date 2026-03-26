# corpus mode 审查报告

日期：2026-03-26

审查范围：

- `corpus/driver.py`
- `corpus/modes.py`
- `runner/Makefile`
- `Makefile`
- 辅助核对：`runner/libs/inventory.py`、`runner/libs/corpus.py`、`runner/src/kernel_runner.cpp`、`runner/src/common.cpp`

## 结论摘要

1. `corpus/driver.py` 当前只暴露四个 mode：`packet / tracing / perf / code-size`。分发逻辑非常简单：`packet` 走 `packet_main()`，其他三个都走同一个 `run_linear_mode()`。
2. `make vm-corpus` 在根 `Makefile` 和 `runner/Makefile` 里都只调用 `python3 corpus/driver.py packet`；没有任何 `make` 入口调用 `perf / tracing / code-size`。
3. 当前代码里真正跑通、且有 Makefile/近期产物共同支撑的只有 `packet`。
4. `perf / tracing / code-size` 三个 linear mode 当前默认实际上跑不起来。根因不是 mode 自己的业务逻辑，而是共享 discovery 路径坏了：
   - `discover_linear_targets()` 依赖 `discover_corpus_objects()`
   - `discover_corpus_objects()` 依赖 `filter_bpf_object_paths()`
   - `filter_bpf_object_paths()` 里的 `_is_bpf_machine()` 用 `int(elf.header["e_machine"]) == 247` 判断 BPF ELF
   - 当前 `pyelftools` 返回的是字符串 `'EM_BPF'`，于是 `_is_bpf_machine()` 抛 `ValueError`，异常被吞掉后所有 `.bpf.o` 都被当成非 BPF 文件跳过
   - 结果是 linear mode 默认得到 `0 target`，最后 batch runner 报 `batch spec must contain a non-empty jobs sequence`
5. 从架构上看，四个 mode 都已经接到 v2 共享批处理/daemon 路径，没有残留独立的 v1 执行器；但从“产品形态”看，`perf / tracing / code-size` 仍然是 v1 时代“按报告类型拆 mode”的遗留外壳，和现在的 v2 架构并不匹配。
6. 重复关系很明显：
   - `tracing` 本质上就是 `code-size + kind==tracing`
   - `code-size` 本质上就是 `perf - execution`
   - `packet` 和 `perf` 都能做 compile/run 对比，只是一个走 `macro_corpus.yaml + VM`，一个走 `discover_corpus_objects() + host`
7. 如果收敛为一个 public mode，建议保留 `packet`，删除 `tracing / perf / code-size`。如果未来仍想保留本地开发态调试能力，也应把 `perf` 降成 `packet` 的一个 flag，而不是继续保留成独立 mode。

## 1. mode 清单、功能、代码路径、行数

### 1.1 入口分发

- `corpus/driver.py:13-24`
  - `MODE_NAMES = {"packet", "tracing", "perf", "code-size"}`
  - `packet` -> `packet_main()`
  - 其他三个 -> `run_linear_mode(mode_name, ...)`
- `corpus/driver.py` 全文件 28 行；真正 mode 分发核心只有 12 行。

### 1.2 共享代码块

这几块不是某一个 mode 独占，而是所有 mode 共用：

| 共享块 | 行号 | 行数 | 作用 |
| --- | --- | ---: | --- |
| `build_target_batch_plan()` | `corpus/modes.py:524-736` | 213 | 生成 baseline/rejit compile/run 的 batch jobs |
| `build_record_from_batch_results()` | `corpus/modes.py:737-804` | 68 | 把 batch runner 输出折叠成 corpus record |
| `run_targets_locally_batch()` | `corpus/modes.py:805-860` | 56 | 启 daemon `--pgo serve`，调用 `run_batch_runner()` |

共享批处理总计：337 行。

### 1.3 `packet`

定位：

- 入口分发：`corpus/driver.py:22-23`
- 参数解析：`corpus/modes.py:119-187`，69 行
- YAML target 加载：`corpus/modes.py:1003-1074`，72 行
- VM guest batch：`corpus/modes.py:1075-1309`，235 行
- packet 汇总：`corpus/modes.py:1310-1491`，182 行
- packet Markdown：`corpus/modes.py:1492-1718`，227 行
- 主入口：`corpus/modes.py:1719-1920`，202 行
- packet 专属代码合计：987 行
- 若加上共享批处理：1324 行

做什么：

- 读取 `macro_corpus.yaml`，不是扫描 `corpus/build/**/*.bpf.o`
- 在 VM 里跑严格 guest batch
- 结果同时包含 baseline compile、REJIT compile、baseline run、REJIT run
- `test_method: bpf_prog_test_run` 走 test-run；`test_method: attach_trigger` 走 attach runtime

关键证据：

- `load_targets_from_yaml()` 用 `test_method == "bpf_prog_test_run"` 设置 `can_test_run`：`corpus/modes.py:1014-1042`
- packet 说明明确写到 `bpf_prog_test_run` 和 `attach_trigger` 都在这个 mode 内：`corpus/modes.py:1707-1712`
- 共享 batch 里，`can_test_run=True` 用 `kernel / kernel-rejit`，否则用 `kernel-attach / kernel-attach-rejit`：`corpus/modes.py:591-629`、`corpus/modes.py:686-720`

额外观察：

- 这个 mode 名叫 `packet`，但实际不是“只测 packet”。
- 当前 `macro_corpus.yaml` 共有 764 条 entry，其中：
  - `bpf_prog_test_run`: 322
  - `attach_trigger`: 390
  - `compile_only`: 52
- 但 `load_targets_from_yaml()` 只区分 `bpf_prog_test_run` / “其他”，所以这 52 个 `compile_only` entry 当前也会被归入 `can_test_run=False` 那一侧，没有独立语义。

### 1.4 `perf`

定位：

- 参数解析：`corpus/modes.py:1931-1977`，47 行
- target discovery：`corpus/modes.py:1988-2061`，74 行
- linear 汇总：`corpus/modes.py:2062-2102`，41 行
- linear Markdown：`corpus/modes.py:2103-2172`，70 行
- 主入口：`corpus/modes.py:2173-2336`，164 行
- linear 公共代码合计：396 行
- `perf` 自身唯一的行为差异：`enable_exec = mode_name == "perf"`，见 `corpus/modes.py:2203`

做什么：

- 本地 discovery 模式，不看 `macro_corpus.yaml`
- 默认扫描/读取 corpus object inventory，构造 target
- 开启 execution，对 compile pair 和 measured pair 都做
- 实际 scope 不是“perf_event 程序”，而是“所有 discover 出来的程序，只是会对可执行程序做 execution”

关键证据：

- mode 描述：`Measure corpus programs locally with stock vs REJIT runs ...`，`corpus/modes.py:1933-1936`
- `enable_exec = mode_name == "perf"`：`corpus/modes.py:2203`
- 对 `can_test_run=False` 的 target，仍会生成 `kernel-attach / kernel-attach-rejit` run job：`corpus/modes.py:614-629`、`corpus/modes.py:710-720`

结论：

- `perf` 的实际含义更像“本地 execution-enabled corpus mode”，不是“perf_event mode”。

### 1.5 `tracing`

定位：

- 与 `perf` / `code-size` 共用同一条 linear 路径：`corpus/modes.py:1931-2336`
- 唯一专属差异：
  - discovery 时强制 `kind == "tracing"`：`corpus/modes.py:2015-2017`
  - Markdown 额外加一句“compile-only inspection”：`corpus/modes.py:2131-2132`
  - `enable_exec` 仍为 `False`，因为只有 `perf` 才开 execution：`corpus/modes.py:2203`

做什么：

- 发现 tracing 类程序
- 只做 compile-only 的 stock vs REJIT inspection
- 不做 attach 后的真实 workload replay，也不做 execution pair

结论：

- 它不是一个独立执行架构，只是 `code-size` 的 tracing 子集。

### 1.6 `code-size`

定位：

- 与 `perf` / `tracing` 共用同一条 linear 路径：`corpus/modes.py:1931-2336`
- 自身没有额外分支；只是 mode 名不同、默认输出路径不同、标题不同

做什么：

- discovery 所有 corpus 程序
- 只做 compile-only
- 汇总 code size ratio

结论：

- 它本质上就是 `perf` 去掉 execution 的 compile-only 子模式。

## 2. 每个 mode 的区别

| mode | target 来源 | 运行位置 | 是否 execution | 是否 VM | 主要用途 |
| --- | --- | --- | --- | --- | --- |
| `packet` | `macro_corpus.yaml` | guest 内 batch | 是 | 是 | 当前 canonical corpus 评测路径 |
| `perf` | `discover_corpus_objects()` | host 本地 | 是 | 否 | 本地 execution-enabled 调试/探索 |
| `tracing` | `discover_corpus_objects()` + `kind==tracing` | host 本地 | 否 | 否 | tracing compile-only inspection |
| `code-size` | `discover_corpus_objects()` | host 本地 | 否 | 否 | 全 corpus compile-only code-size inspection |

最关键的真实区别只有两个维度：

1. target 来源不同：`packet` 看 YAML；其他三个看 object discovery。
2. execution 开关不同：只有 `perf` 开 execution；`tracing` 和 `code-size` 都不开。

## 3. 哪些 mode 当前实际能跑通

### 3.1 能跑通：`packet`

证据链：

- `make vm-corpus` 只调 `packet`
  - 根 Makefile：`Makefile:309-312`
  - runner Makefile：`runner/Makefile:267-276`
- `packet_main()` 明确要求 `kernel_image`、`btf_custom_path`、`runner`、`daemon` 都存在：`corpus/modes.py:1743-1762`
- 当前工作区这些依赖都在：
  - `runner/build/micro_exec`
  - `daemon/target/release/bpfrejit-daemon`
  - `vendor/linux-framework/vmlinux`
  - `vendor/linux-framework/arch/x86/boot/bzImage`
- 仓库现有近期产物里，`mode=packet` 有多次 `completed` 的 `vm_corpus_*` metadata，常见 summary 形态是 `targets_attempted=152 / compile_pairs=152 / measured_pairs=152`

因此：

- `packet` 是当前唯一“代码、Makefile、现有产物”三方都指向的活跃 mode。

### 3.2 默认跑不通：`perf / tracing / code-size`

直接证据：

- `discover_corpus_objects()` 默认优先读取 `expanded_corpus_build_authoritative_*.json`：`runner/libs/inventory.py:121-136`
- 但真正的 BPF 对象过滤用了：
  - `_is_bpf_machine()`：`runner/libs/inventory.py:101-104`
  - 代码是 `int(elf.header["e_machine"]) == 247`
- 当前 `pyelftools` 在本仓库里返回的是字符串 `'EM_BPF'`，不是整数 247
- 因此 `_is_bpf_machine()` 抛 `ValueError`，被 `filter_bpf_object_paths()` 吞掉，所有 `.bpf.o` 都被加入 `skipped`

我在当前工作区做了静态验证：

- `file corpus/build/.../*.bpf.o` 明确显示是 `ELF ... eBPF`
- 但 `discover_corpus_objects()` 返回：
  - 默认 authoritative report：`count=0`
  - 强制 filesystem scan：`count=0`
- `discover_object_programs()` 本身对单个 `.bpf.o` 是正常的，说明坏的是共享过滤逻辑，不是 `micro_exec list-programs`

连锁后果：

- `discover_linear_targets()` -> `targets=[]`
- `run_linear_mode()` 仍继续调用 `run_targets_locally_batch()`
- batch spec 变成空 jobs
- batch runner 报错：`batch spec must contain a non-empty jobs sequence`

现有产物也支持这个判断：

- 仓库里能找到多个 `mode=perf` 的 metadata，全部 `status=error`、`targets_attempted=0`
- 我没有找到任何近期 `mode=tracing` 或 `mode=code-size` 的 metadata

因此当前状态应判断为：

- `packet`：可跑
- `perf`：默认不可跑
- `tracing`：默认不可跑
- `code-size`：默认不可跑

## 4. 哪些 mode 是 v1 遗留、已经不兼容 v2 架构

严格说，没有哪个 mode 还在走独立的 v1 执行器。

原因：

- 四个 mode 最终都落到同一个 v2 共享批处理骨架：
  - `run_targets_locally_batch()`：`corpus/modes.py:805-860`
  - daemon 用的是 `--pgo serve --socket`：`corpus/modes.py:281-291`
  - REJIT runtime 用的是 `kernel-rejit / kernel-attach-rejit`：`corpus/modes.py:654-720`

所以“v1 不兼容”如果按执行栈来定义，答案是：

- `没有纯 v1 残留 mode`

但如果按“工作流形态”来定义，`perf / tracing / code-size` 确实是 v1 时代的遗留拆法：

1. 它们不是按 v2 架构边界拆的，而是按“报告长什么样”拆的。
2. `tracing` 已经没有独立的 tracing attach+trigger 运行模型，只剩 compile-only 子集。
3. `code-size` 不是架构模式，只是 `perf` 去掉 execution 之后的报告预设。
4. 它们不在 canonical `make vm-corpus` 路径上，也没有 repo 级别的 VM 封装。

所以更准确的判断是：

- `packet`：当前 v2 canonical mode
- `perf / tracing / code-size`：v1 工作流形态的遗留 public mode；不是“旧执行器残留”，但已经不适合作为独立 public mode 继续保留

## 5. 哪些 mode 有重复功能

### 5.1 `tracing` 与 `code-size` 基本重复

两者都走：

- `parse_linear_mode_args()`：`corpus/modes.py:1931-1977`
- `discover_linear_targets()`：`corpus/modes.py:1988-2061`
- `run_linear_mode()`：`corpus/modes.py:2173-2336`

两者都：

- `enable_exec=False`
- 只做 compile-only
- 共享同一套 summary/markdown 结构

唯一差异：

- `tracing` 额外在 discovery 阶段加了 `kind == "tracing"` 过滤：`corpus/modes.py:2015-2017`
- `tracing` Markdown 多一条说明文案：`corpus/modes.py:2131-2132`

结论：

- `tracing == code-size --kind tracing`

### 5.2 `code-size` 与 `perf` 高度重复

两者唯一区别：

- `perf`：`enable_exec=True`
- `code-size`：`enable_exec=False`

除 execution 开关外，其余 target discovery、compile pair、记录折叠、输出结构都是同一套逻辑。

结论：

- `code-size == perf - execution`

### 5.3 `packet` 与 `perf` 也有结果层重叠

两者都能生成：

- baseline compile
- REJIT compile
- baseline run
- REJIT run
- size ratio
- speedup ratio

核心区别只是：

- `packet`：`macro_corpus.yaml + VM + Makefile canonical`
- `perf`：`discover_corpus_objects() + host local + 非 canonical`

所以如果未来只保留一个 public mode，保留 `packet` 更合理。

## 6. vm-corpus make target 用的是哪个 mode

明确就是 `packet`。

调用链：

1. 根 Makefile `vm-corpus`：`Makefile:309-312`
2. 转到 `runner/Makefile` 的 `vm-corpus`：`runner/Makefile:267-276`
3. 实际命令：
   - `python3 "$(REPO_ROOT)/corpus/driver.py" packet ...`

## 7. corpus 的 retval correctness check 覆盖了哪个 mode

结论：

- 覆盖 `packet` 和 `perf`
- 不覆盖 `tracing` 和 `code-size`

原因：

- correctness check 不在 `corpus/modes.py`，而在 `runner/src/kernel_runner.cpp`
- 只有在“成对 execution”时，runner 才会拿 stock / REJIT 的 `retval` 做比较：
  - `run_kernel` 路径：`runner/src/kernel_runner.cpp:1874-1885`
  - `run_kernel_attach` 路径：`runner/src/kernel_runner.cpp:2497-2508`
- 比较结果以 `correctness_mismatch` 写进 sample JSON：`runner/src/common.cpp:925-928`
- `corpus/modes.py` 自己没有任何 `correctness_mismatch` 读取逻辑；它只把最后一个 sample 原样塞进 record：`corpus/modes.py:485-495`

这意味着：

- `packet`：会覆盖
  - `kernel / kernel-rejit`
  - `kernel-attach / kernel-attach-rejit`
- `perf`：理论上也会覆盖同样两条 runtime
- `tracing` / `code-size`：`enable_exec=False`，没有 paired execution，自然没有 retval correctness check

补充：

- corpus 层目前并不会把 `correctness_mismatch` 提升为 summary 字段；这个字段只停留在 sample 级别。

## 8. 建议保留 / 删除

### 8.1 建议保留：`packet`

理由：

1. 它是唯一被 `make vm-corpus` 正式使用的 mode。
2. 它是唯一有近期稳定 `completed` 产物证明在跑的 mode。
3. 它直接对齐 repo 的 VM 边界和 v2 daemon/guest batch 架构。
4. 它已经同时覆盖 `bpf_prog_test_run` 和 `attach_trigger` 两类 workload，实际 scope 最大。

保留时建议注意：

- mode 名称已经失真，后续更合理的名字应是 `vm`、`macro-vm` 或 `corpus-vm`；
- 但短期内可以继续保留 `packet` 作为兼容 alias。

### 8.2 建议删除：`tracing`

理由：

1. 功能上就是 `code-size --kind tracing`。
2. 没有独立执行架构。
3. 当前默认也跑不起来。
4. 名称会误导人以为它还代表 tracing attach+trigger 全流程；实际并没有。

### 8.3 建议删除：`code-size`

理由：

1. 功能上就是 `perf` 去掉 execution。
2. 当前默认也跑不起来。
3. 作为 public mode 没有明确独立价值，更像报告预设。

### 8.4 建议删除：`perf`

理由：

1. 它不是 Makefile canonical path。
2. 当前默认 discovery 已坏，事实上不可用。
3. 它和 `packet` 在 compile/run 结果层高度重叠。
4. “保留一个 mode”这个目标下，保留 VM canonical 的 `packet` 比保留 host-local 的 `perf` 更合理。

保守替代方案：

- 如果团队确实还想保留“本地、不进 VM 的 debug harness”，也不建议继续作为 public `perf` mode 暴露；
- 更合理做法是将来把它折叠成 `packet` 的一个非默认 flag。

## 9. 收敛方案

建议收敛到一个 public mode：保留 `packet`，但把它语义化为“唯一 corpus benchmark mode”。

### 9.1 目标形态

- public CLI 只保留一个 mode
- 这个 mode 默认代表：
  - corpus benchmark canonical path
  - VM guest batch
  - YAML 驱动 target 选择
  - compile + execute + REJIT 对比

### 9.2 迁移建议

1. 第一步：冻结 public mode 集合，只承认 `packet`
   - 文档、Makefile、README 都只写这一条路径
   - `tracing / perf / code-size` 标记为 deprecated
2. 第二步：如果仍需要保留调试能力，把差异改成 flag，而不是 mode
   - 例如 target 来源用 flag 区分：`--macro-corpus-yaml` / `--discovery-source`
   - execution 开关用 flag：`--compile-only`
   - 运行位置用 flag：`--vm` / `--local`
3. 第三步：最后再考虑把 `packet` 改名成更准确的名字
   - 如 `vm` / `corpus-vm`
   - 但先保留 `packet` alias，避免脚本大面积抖动

### 9.3 我建议的最终落点

- public mode：只保留一个，逻辑上等于今天的 `packet`
- `perf / tracing / code-size`：删除
- 若必须保留本地调试能力：改成 `packet` 的内部 flag，不再保留为一等 public mode

## 10. 逐题回答

### 10.1 所有 mode

- `packet`
- `tracing`
- `perf`
- `code-size`

### 10.2 每个 mode 做什么、有什么区别

- `packet`：YAML 驱动、VM guest batch、compile+run 对比、当前 canonical
- `perf`：本地 discovery、本地 execution-enabled、host 调试/探索路径
- `tracing`：本地 discovery、只看 tracing 类程序、compile-only
- `code-size`：本地 discovery、全 corpus、compile-only

### 10.3 哪些 mode 当前代码里实际能跑通

- 能跑：`packet`
- 默认跑不通：`perf / tracing / code-size`

### 10.4 哪些 mode 是 v1 遗留、已经不兼容 v2 架构

- 如果按执行器看：没有纯 v1 mode 残留
- 如果按 public workflow 形态看：`perf / tracing / code-size` 都是遗留拆法，不适合继续作为 v2 public mode

### 10.5 哪些 mode 有重复功能

- `tracing` 与 `code-size` 重复
- `code-size` 与 `perf` 重复
- `packet` 与 `perf` 在结果层也有较大重叠

### 10.6 如果收敛为一个 mode，应该保留哪个

- 保留 `packet`

### 10.7 vm-corpus make target 用的是哪个 mode

- `packet`

### 10.8 corpus 的 retval correctness check 覆盖了哪个 mode

- `packet` 和 `perf`
- 不覆盖 `tracing` 和 `code-size`

