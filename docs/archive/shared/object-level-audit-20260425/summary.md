# Object-level Audit 2026-04-25

## 结论

- 当前主线 `corpus` / `e2e` benchmark 路径已经基本切到 app-level。
- 我没有在 `corpus/driver.py`、`runner/suites/corpus.py`、`runner/suites/e2e.py`、`corpus/config/benchmark_config.yaml`、`corpus/config/macro_apps.yaml` 里发现直接 `bpf_object__open*` / `bpftool prog load` / object-manifest 驱动的活跃路径。
- 仍然存在的 object-level 残留主要分成四类：
  1. `katran` runner 里还保留了 runner 侧直接加载 `xdp_root.bpf.o` 的活跃逻辑。
  2. 整套 `micro` 子系统仍然是 object-level，并且还在 build/runtime 镜像里持续构建。
  3. `runner/repos.yaml` 和 `corpus/results/*` 里仍然保留旧 object-level corpus 路线的历史配置/结果。
  4. `daemon` 和 `tests/unittest` 里还有大量 test-only 的 `.bpf.o` 解析/加载代码，但它们不属于当前 app-native corpus 主路径。

## 已确认没有发现 object-level 主路径残留

- `corpus/driver.py`
  - 未发现 `bpf_object_open`、`bpftool prog load`、`.bpf.o` 直接加载、`compile_pairs`、`source_name`、`object_path`、`elf_path`。
  - 当前路径是：启动 app runner，让真实应用自己加载 BPF，然后 daemon 对 live programs 做 ReJIT。
- `runner/suites/corpus.py`
  - 未发现 object-level 启动路径。
- `runner/suites/e2e.py`
  - 未发现 object-level 启动路径。
- `corpus/config/benchmark_config.yaml`
  - 只有 benchmark policy / pass 配置，没有 object/build/source 清单。
- `corpus/config/macro_apps.yaml`
  - 只有 app 清单和 workload 配置，没有 `.bpf.o` object 列表。
- `runner/libs/*.py`
  - 没有发现通用的 object loading helper。
  - `bpftool` 相关通用函数主要用于 program/map introspection，不是 `prog load`。

## 1. 活跃残留：Katran 仍有 runner-side object loading

| 文件与行号 | 性质 | 说明 | 建议 |
| --- | --- | --- | --- |
| `runner/libs/app_runners/katran.py:481-498` | 活跃代码 | `KatranServerSession.__enter__()` 在启动 `katran_server_grpc` 之前，先由 runner 主动安装 root XDP program。 | 如果目标是彻底 app-level，这段应移出 runner。要么让 Katran 自己完成 root program 装载，要么把它明确定义成唯一允许的特例并写入设计文档。 |
| `runner/libs/app_runners/katran.py:819-869` | 活跃代码 | `_install_root_xdp_program()` 直接执行 `bpftool prog load <xdp_root.bpf.o>` 和 `bpftool net attach xdp pinned ...`。这是明确的 object-level load。 | 同上。这是本次审计里最明确、最重要的活跃残留。 |
| `runner/libs/app_runners/katran.py:893-900` | 活跃代码 | `KatranRunner` 直接解析 `balancer.bpf.o`、`healthchecking_ipip.bpf.o`、`xdp_root.bpf.o` 三个 artifact 路径。前两个随后交给 Katran app 自己加载；`xdp_root.bpf.o` 则由 runner 直接 load。 | 若保留 Katran，建议至少把 `xdp_root` 这条 runner-side 加载路径单独隔离并显式标注为 exception。 |
| `runner/suites/_common.py:131-149` | 活跃支撑代码 | suite 启动前强制要求 `katran` 的 `.bpf.o` artifact 存在。这里本身不 load，但它为上面的 direct-load 路径服务。 | 如果 Katran root XDP direct-load 被移除，这里的必需 artifact 列表也应相应缩减。 |
| `runner/mk/build.mk:60,307-311` | 活跃构建逻辑 | 仍把 `xdp_root.bpf.o` 等 Katran BPF objects 当作 runtime 必需物；还会把 upstream `.o` rename 成 `.bpf.o`。 | 若想彻底 app-native，重新定义 Katran 需要的 runtime artifact 边界。 |
| `runner/containers/runner-runtime.Dockerfile:151-195` | 活跃镜像构建 | runtime Dockerfile 专门 sparse-clone Katran repo、构建 `bpftool`，再执行 `make image-katran-artifacts` 产出 Katran `.bpf.o` artifacts。 | 如果 Katran root XDP direct-load 被移除，这一段也应重新审视，只保留 app 真正需要的 artifacts。 |

补充说明：

- `runner/libs/app_runners/tetragon.py:97-100` 也检查 `.bpf.o` artifact 是否存在，但这里只是验证 upstream Tetragon BPF lib 目录是否完整，随后仍由 `tetragon` 自己加载，不属于 runner-side object loading。

## 2. 活跃残留：整套 `micro` 子系统仍然是 object-level

这部分不是 `corpus` 主线，但它仍在同一仓库里、仍被构建、仍被 runtime 镜像带上。

| 文件与行号 | 性质 | 说明 | 建议 |
| --- | --- | --- | --- |
| `runner/suites/micro.py:132-148` | 活跃代码 | suite 明确把 `BPFREJIT_MICRO_PROGRAM_DIR` 和 `BPFREJIT_MICRO_RUNNER_BINARY` 注入环境，然后启动 `micro/driver.py`。 | 如果仓库要完全转为 app-level benchmark，应把 `micro` 从 benchmark 主产品线剥离，至少不要继续和 corpus/e2e 共用 runtime 镜像。 |
| `micro/config/micro_pure_jit.yaml:4-15,42-50` | 活跃配置 | manifest 直接声明 `program_dir`、`runner_binary`，`benchmarks[].base_name` 解析为 `.bpf.o`。 | 同上；这是标准 object-level manifest。 |
| `micro/catalog.py:81-87,228-258` | 活跃代码 | `CatalogTarget` 有 `object_path` 字段，`_load_micro_catalog()` 直接构造 `program_dir / <base_name>.bpf.o`。 | 若 `micro` 不再属于当前 benchmark 框架，应整体迁出或标记为 legacy。 |
| `micro/driver.py:229-232,335-354` | 活跃代码 | 运行前校验所有 `benchmark.object_path`，执行时把 `--program <object_path>` 传给 runner。 | 同上。 |
| `runner/CMakeLists.txt:37-44,99` | 活跃构建 | 仍然编译 `micro_exec`，其核心源文件就是 object loader / kernel runner。 | 若弃用 object-level micro，停止默认构建。 |
| `runner/src/elf_program_loader.cpp:548-620` | 活跃代码 | `list_programs()`、`load_program_image()` 直接 `bpf_object__open_file()` 解析 `.bpf.o`。 | 这是典型 object-level loader。若 `micro` 废弃，可直接删除。 |
| `runner/src/kernel_runner.cpp:981-1000` | 活跃代码 | `run_kernel()` 直接 `bpf_object__open_file()` + `bpf_object__load()`。 | 同上。 |
| `runner/src/common.cpp:207-218` | 活跃支撑代码 | `benchmark_name_for_program()` 直接剥离 `.bpf.o` / `.o` 后缀。 | 若 `micro` 迁出，这类命名辅助也应一起迁走。 |
| `runner/mk/build.mk:19-22` | 活跃构建 | `MICRO_PROGRAM_OBJECTS` 直接把 `micro/programs/*.bpf.c` 编译成 `.bpf.o`。 | 停止默认生成。 |
| `micro/programs/Makefile:8,15,23` | 活跃构建 | 明确构建并管理 `*.bpf.o`。 | 同上。 |
| `runner/containers/runner-runtime.Dockerfile:267-313` | 活跃镜像构建 | 复制 `runner/src`、`micro/programs`、`micro/config`、`runner/repos.yaml`，然后执行 `make image-runner-artifacts` 和 `make image-micro-program-artifacts`。 | 如果 runtime image 只服务 app-native corpus/e2e，应移除 micro/object-level 构建步骤。 |

## 3. 旧 object-level corpus 路线的死代码/历史残留

### 3.1 `runner/repos.yaml`

| 文件与行号 | 性质 | 说明 | 建议 |
| --- | --- | --- | --- |
| `runner/repos.yaml:1-220` | 死配置 / 历史残留 | 整个文件是旧 object-level corpus 的 harvest/compile manifest：`harvest_globs`、`compile_include_dirs`、`sparse_paths`、`forced_includes`。本次审计没有找到当前 app-native `corpus/driver.py` / `runner/suites/corpus.py` 仍消费它的路径。 | 如果确认不再用于任何现役流程，建议移到 `archive/` 或直接删除；至少不要再进入 runtime image。 |

### 3.2 `corpus/results/` 历史结果

| 文件与行号 | 性质 | 说明 | 建议 |
| --- | --- | --- | --- |
| `corpus/results/expanded_corpus_build.md:4,6,127` | 历史结果 | 明确引用 `runner/repos.yaml` 和 `macro_corpus.yaml`，描述“scan repo sources directly”。 | 可保留为历史记录，但建议迁到 `archive/legacy-object-corpus/` 或在文件头标注“historical object-level corpus result”。 |
| `corpus/results/expanded_corpus_build_smoke_20260324.json:3` | 历史结果 | `manifest` 直接指向 `runner/repos.yaml`。 | 同上。 |
| `corpus/results/expanded_corpus_build_authoritative_20260310.json:72091-72092` | 历史结果 | 文件中大量 `object_path` / `temp_object_path` 条目，显然是旧 expanded/object corpus build 输出。 | 同上。 |
| `corpus/results/tracing_corpus_vm_full_20260312.json:25-39` | 历史结果 | 明确写着 `expanded_corpus`、`corpus/build/` object root、`expanded build report`，并在 `37-44` 等位置记录 `object_path` 和 `micro_exec list-programs --program <.bpf.o>` 错误。 | 同上。 |
| `corpus/results/vm_corpus_new.json:11,14,16,59,871` | 历史结果 | 仍引用 `macro_corpus.yaml`，并记录 `"object": "corpus/build/...bpf.o"`。 | 同上。 |

补充说明：

- 我没有在当前活跃代码里找到 `compile_pairs` 或 `source_name`；这两个概念现在主要只出现在历史结果和 `docs/tmp/*` 分析文档里。

## 4. `daemon/src/*.rs` 审计结果

### 4.1 应保留的 live-program verify 路径，不算 object-level corpus 残留

| 文件与行号 | 性质 | 说明 | 建议 |
| --- | --- | --- | --- |
| `daemon/src/commands.rs:535-596` | 活跃代码，但不是问题 | 这是对已经 live 的 program 构造 per-pass `BPF_PROG_LOAD` dry-run verify，用于 verifier-in-the-loop pass gating。它不是从 `.bpf.o` 打开 object。 | 保留。 |
| `daemon/src/bpf.rs:1141-1580` | 活跃代码，但不是问题 | 这里实现的是 live-program metadata 到 `BPF_PROG_LOAD` verify attr 的重建，不是 object-level benchmark loader。 | 保留。 |

### 4.2 test-only 的 `.bpf.o` 解析辅助

| 文件与行号 | 性质 | 说明 | 建议 |
| --- | --- | --- | --- |
| `daemon/src/insn.rs:447-470` | 测试辅助 | `#[cfg(test)]` 下的 `load_bpf_insns_from_elf()` / `micro_program_path()` 明确针对 `.bpf.o` test fixture。 | 如果希望 repo 内部也减少 object-level 术语，可把 helper 移入 test module；否则可以保留。 |
| `daemon/src/elf_parser.rs:1-2,1133-1168` | 测试辅助 | 文件头直接说明用于 real `.bpf.o` test fixtures，单测读取 fixture `.bpf.o`。 | 同上。 |
| `daemon/src/test_utils.rs:1-25` | 测试辅助 | `LoadedFixtureProgram` 仍持有 `object_path`，依赖 `parse_bpf_object()`。 | 同上。 |
| `daemon/src/passes/rotate.rs:746-807` | 测试辅助 | 用 `rotate_dense.bpf.o` 做 pass 测试。 | 同上。 |
| `daemon/src/passes/endian.rs:931-972` | 测试辅助 | 用 `endian_swap_dense.bpf.o` 做 pass 测试。 | 同上。 |
| `daemon/src/passes/extract.rs:807-854` | 测试辅助 | 用 `bitfield_extract.bpf.o` 做 pass 测试。 | 同上。 |
| `daemon/src/passes/branch_flip.rs:944-1020` | 测试辅助 | 用 `branch_flip_dense.bpf.o` 做 pass 测试。 | 同上。 |
| `daemon/src/passes/wide_mem_tests.rs:740-784` | 测试辅助 | 用 `load_byte_recompose.bpf.o` 做 pass 测试。 | 同上。 |
| `daemon/src/passes/cond_select_tests.rs:658-685` | 测试辅助 | 用 `cond_select_dense.bpf.o` 做 pass 测试。 | 同上。 |
| `daemon/src/passes/mod_tests.rs:466-678` | 测试辅助 | 多个 full-pipeline test 直接读取 `.bpf.o` fixture。 | 同上。 |

## 5. 其他 repo-wide grep 命中：不属于 benchmark 主路径，但仍是 object-level

这些文件不在你给的核心检查范围里，但从“全仓 grep 残留”角度确实还在：

| 文件与行号 | 性质 | 说明 | 建议 |
| --- | --- | --- | --- |
| `tests/unittest/Makefile:77-119` | 活跃测试构建 | 大量 unittest BPF program 会被编译为 `.bpf.o`。 | 如果目标只是清 benchmark 路线，可以不动。若要 repo-wide 去 object-level，就需要单独设计替代测试策略。 |
| `tests/unittest/rejit_pass_correctness.c:11,38,224-362,458-460,532-534,637` | 活跃测试代码 | 直接通过 libbpf 加载 `.bpf.o` 做 correctness test。 | 同上。 |
| `tests/unittest/rejit_regression.c:1359-1410,1564-1574` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_prog_types.c:1232-1276,1390-1410,1575` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_audit_tests.c:977-983,1105` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_hotswap_sk_lookup.c:283-287` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_hotswap_fentry.c:212-217` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_hotswap_struct_ops.c:285-289` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_hotswap_xdp.c:232-251` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_hotswap_lsm.c:209-228` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_hotswap_kprobe.c:172-176` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_hotswap_ext.c:126-128,239-246` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_hotswap_sched_cls.c:399-403` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_hotswap_perf_event.c:311-315` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_hotswap_socket_filter.c:204-208` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_hotswap_cgroup_skb.c:272-276` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_hotswap_tracepoint.c:250-254` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_late_rollback.c:536-540,841-845` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |
| `tests/unittest/rejit_swap_tests.c:918-921` | 活跃测试代码 | 直接打开 `.bpf.o`。 | 同上。 |

## 建议的清理优先级

1. 先处理 `runner/libs/app_runners/katran.py` 的 `xdp_root.bpf.o` direct-load。
   - 这是当前 app-native benchmark 主线上唯一明确的 runner-side object load 残留。
2. 决定 `micro` 子系统的命运。
   - 如果它已经不属于“当前 benchmark 框架”的正式范围，建议整体迁出、归档或至少停止默认构建进 `runner-runtime`。
3. 把 `runner/repos.yaml` 和 `corpus/results/*` 的旧 object-level 历史产物归档。
   - 至少从当前 runtime/build 路径里摘掉，避免继续制造“旧路线还在服役”的信号。
4. `daemon` test-only helper 和 `tests/unittest/*` 可以后处理。
   - 它们确实仍是 object-level，但不影响当前 app-native corpus 设计是否成立。

## 最终判断

- 如果标准是“当前 `corpus` 主线是否还在走 object-level 路线”，答案是：**主线基本没有，只有 Katran root XDP bootstrap 这一个明显活跃残留。**
- 如果标准是“整个仓库是否还残留 object-level 基础设施”，答案是：**有，而且不少，主要集中在 `micro`、历史结果/配置、daemon test helper、unittest。**
