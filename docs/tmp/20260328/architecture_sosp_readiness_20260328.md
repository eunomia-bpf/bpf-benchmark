# BpfReJIT 架构级审查报告（SOSP Reviewer 视角）

日期：2026-03-28  
审查方式：静态代码审查，不运行内核/BPF 路径，不修改源码  
输出目标：评估当前代码库距离 “可让 SOSP 审稿人/Artifact Reviewer 信服” 还有多远

## 0. 方法与统计口径

本报告主要基于四类证据：

1. `wc -l` / 逐目录 LOC 统计。
2. `rg` 搜索接口漂移、TODO/FIXME、硬编码路径、重复实现、artifact 脚本缺失等模式。
3. 逐目录阅读核心入口与 God file。
4. 审核 paper/doc/artifact 路径是否闭环。

代码量统计口径：

- 只看 repo-owned 代码/配置。
- 排除 `vendor/**`、`runner/repos/**`、`docs/tmp/**`、明显 build/output/result 产物、`__pycache__`、`.pyc` 等。
- 但仓库 hygiene 相关问题会单独检查 `docs/tmp/**`、`micro/results/**`、`corpus/results/**`、`e2e/results/**` 这些被跟踪的输出。

静态统计结果：

- 总计：`302 files / 120,644 LOC`
- 目录分布：

| 目录 | 文件数 | LOC | 评语 |
| --- | ---: | ---: | --- |
| `daemon/` | 43 | 31,572 | 核心价值高，但接口面与文档严重漂移 |
| `runner/` | 52 | 23,002 | 当前最低“价值密度”，重复实现最多 |
| `corpus/` | 7 | 22,429 | 价值高，但大量复杂度被塞进单文件/单 YAML |
| `tests/` | 83 | 24,404 | 量很大但大体合理；问题在陈旧测试路径 |
| `e2e/` | 26 | 8,392 | 科学价值高，但 case scaffold 明显复制 |
| `micro/` | 70 | 7,039 | 价值合理，但 artifact 链路不闭环 |
| `module/` | 18 | 2,990 | 高杠杆、低 LOC，最像论文想讲的“扩展性”故事 |

最值得注意的一点：`corpus/config/macro_corpus.yaml` 单文件就有 `18,331 LOC`。这不是“实现复杂”，而是“基准库存管理复杂”。

## 1. 总体结论

一句话结论：

> 这是一个“研究想法清晰、核心系统已经成形，但代码库还没有收敛成 SOSP-ready artifact”的仓库。

我认为当前最危险的五个 reviewer red flags 是：

1. **评测 pass policy 不统一。** `daemon` 默认启用所有 pass，但 `corpus/e2e` 默认只启用 `map_inline,const_prop,dce`，而 `micro` 很可能没有把 benchmark pass policy 传到底层，导致不同评测套件测到的不是同一系统。
2. **可执行接口与文档/测试严重漂移。** 当前 `daemon/src/main.rs` 只暴露 `serve`，但 README、架构文档、integration tests、一些 helper 仍在谈 `enumerate/rewrite/apply/apply-all/watch/profile`。
3. **`runner/` 低价值重复实现过多。** 已经有 `daemon_client.cpp` + `json_parser.cpp`，但 `kernel_runner.cpp` 和 `batch_runner.cpp` 仍各自复制 daemon socket client / JSON 解析。
4. **artifact 复现链不闭环。** README 声称的 `make verify-build`、`make compare` 不存在；`micro/README.md` 引用不存在的 `docs/paper/scripts/run_micro.sh`；paper figures 仍是 synthetic placeholder。
5. **存在静默失败路径。** `runner/Makefile:77`、`corpus/modes.py:887` 通过 `module/load_all.sh 2>/dev/null || true` 隐藏模块加载失败；`module/load_all.sh:19` 自己也在 `insmod` 失败时仅打印 `WARN` 继续执行。

如果我是 SOSP 审稿人，我会给出这样的评价：

- 研究系统本身有内容。
- 但 artifact 组织、接口稳定性、评测闭环、代码卫生还没达到“可放心复现”的程度。
- 最需要修的不是算法，而是 **一致性、收敛性、可验证性**。

## 2. 代码量 vs 功能量：每个模块是否物有所值？

### `daemon/`：总体“值得”，但收尾明显不完整

优点：

- `daemon/src/passes/mod.rs:49-112` 的 `PASS_REGISTRY` 很像成熟系统该有的中心注册点。
- `pass.rs` / `analysis/*` / `kfunc_discovery.rs` / `server.rs` 组合起来，能看出明确的中间表示、分析缓存、pass pipeline、平台能力发现、serve protocol。
- `module/` 配合 `daemon` 的结构很契合论文里的“用户态复杂、内核态极薄”的故事。

问题：

- 当前真正公开的 CLI 只有 `serve`。`daemon/src/main.rs:48-56` 的 `Command` 枚举只剩一个 `Serve`，这意味着很多历史路径已经从 live binary surface 消失。
- 但 `daemon/README.md:34-90,206-213` 还在描述 `enumerate/rewrite/apply/apply-all/watch/profile`；`docs/daemon-architecture.md:76-85` 甚至明确写“这些命令都存在”。这会让 reviewer 直接怀疑代码/文档是否同代。
- `daemon/README.md:111` 还把 default pipeline 写成 `wide_mem -> rotate -> cond_select -> branch_flip`，而当前 `PASS_REGISTRY` 已经是 12 个 pass。文档不是“略旧”，而是系统级叙述已经不可信。

判断：

- `daemon` 的核心复杂度大体是值得的。
- 但作为论文 artifact，它最需要的是 **接口面收敛**，不是继续加功能。

### `runner/`：当前最不值

`runner` 同时承担了：

- C++ measurement engine
- daemon protocol client
- JSON protocol parsing
- batch/static-verify 执行器
- Python orchestration / reporting / profiler / repro helpers

问题不在“功能多”，而在 **重复的实现方式太多**：

- 已存在专门的 `runner/include/json_parser.hpp` + `runner/src/json_parser.cpp`，以及 `runner/include/daemon_client.hpp` + `runner/src/daemon_client.cpp`。
- 但 `runner/src/kernel_runner.cpp:1400-1781` 又复制了一套 `extract_json_*` / `build_daemon_optimize_request` / `daemon_socket_optimize`。
- `runner/src/batch_runner.cpp:507-846` 还复制了一套 `_batch` 版本。
- 这使得 `runner` 看起来像“几轮重构叠出来”的仓库，而不是已经稳定下来的 artifact。

更糟的是，`runner/src/json_parser.cpp:45-58` 解析失败直接返回 `0`，缺 key 也返回空值。这是 fail-open protocol parser，不符合研究 artifact 对错误可见性的预期。

判断：

- `runner` 是当前代码库最像 reviewer 攻击面的部分。
- 如果只允许重构一个目录，我会先动 `runner/`。

### `corpus/`：研究价值高，但实现结构差

这是代码库里“功能值很高、实现可维护性偏低”的典型目录。

优点：

- `runner/repos.yaml` + `corpus/config/macro_corpus.yaml` 体现了真实程序语料库的野心，这对论文是加分项。
- `corpus/modes.py` 中对对象与 program 结果做排序，说明作者在意同一 checkout 内的确定性。

问题：

- `corpus/config/macro_corpus.yaml` 单文件 `18,331 LOC`，已经接近“数据仓库”而不是配置文件。
- `corpus/modes.py` 把 benchmark config、pass 选择、guest command 拼装、VM 调用、manifest 解析、结果汇总、markdown 生成全塞在一起。
- `corpus/modes.py:883-889` 在 guest command 前缀里直接拼 `module/load_all.sh 2>/dev/null || true;`，这会把关键依赖失败隐藏掉。

判断：

- `corpus` 对论文价值很高。
- 但 reviewer 会问：这究竟是“框架”还是“脚本集合 + 巨型 YAML”。

### `micro/`：价值合理，但没有完全接上 artifact story

优点：

- `micro/driver.py` 明确控制 benchmark 顺序；`--shuffle-seed` 未指定时仍是确定性的。
- 输入生成器普遍用固定 seed，这对复现是加分。

问题：

- `micro/README.md:40,46,52` 引用的 `docs/paper/scripts/run_micro.sh` 并不存在。
- `micro/driver.py:175-176,432-448,470-478` 只把 `daemon_socket` 传给 job，没有把 `enabled_passes` 传下去。
- 底层 `runner` 明明支持 `enabled_passes` (`runner/include/micro_exec.hpp:66-68`, `runner/src/common.cpp:804-807`)，但 `micro` 没接。这意味着 micro suite 极可能使用 daemon 默认 pass 集，而不是论文 benchmark config 定义的 pass 集。

判断：

- `micro` 的代码量本身不算夸张。
- 但它现在可能在测一套与 `corpus/e2e` 不同的系统配置，这是高优先级问题。

### `e2e/`：科学价值高，但工程上明显复制

这部分是论文结果的重要组成，但代码结构重复度很高。

- 所有 case 都有 `DEFAULT_DAEMON`、`ensure_artifacts()`、`measure_workload()`、`run_phase()`、`compare_phases()`、`build_markdown()` 这一套骨架。
- `e2e/cases/katran/case.py` 则已经膨胀成“环境搭建 + traffic + case logic + markdown/reporting”大全。

判断：

- `e2e` 是论文必要成本，不是纯粹浪费。
- 但当前写法更像 6 个 fork，而不是 1 个框架 + 6 个适配器。

### `module/`：最“值回票价”

`module/` 只有 `2,990 LOC`，但它几乎正好承载了论文想讲的那部分最关键系统故事：

- 新 capability 的内核落地点局部化。
- x86/arm64 分离明确。
- 低 LOC 带来高系统杠杆。

问题：

- `module/x86/Makefile:8-13`、`module/arm64/Makefile:8-14` 仍默认构建 `bpf_barrier`。
- `module/load_all.sh:14-25` 会无差别加载所有 `.ko`，包括当前 OSDI/SOSP scope 外的 barrier 模块。

判断：

- 这是最适合拿来讲“extensibility”的目录。
- 但必须把 out-of-scope 安全相关 capability 从默认路径剥离。

### `tests/`：量大合理，但有陈旧接口债

优点：

- 对这样一个会 live rewrite BPF 的系统来说，大量测试是加分项，不是减分项。
- `tests/unittest/*.c` 的大体量说明作者确实在压 semantic / verifier / rollback 风险。

问题：

- `tests/integration/vm_daemon_live.sh` 与 `tests/integration/vm_comprehensive.sh` 仍直接调用 `bpfrejit-daemon enumerate/rewrite/apply/apply-all`，而当前 main binary 已不暴露这些命令。

判断：

- 测试量不是问题。
- **测试接口与当前产品接口不同代** 才是问题。

## 3. 从未在当前 eval 主路径中行使，或明显陈旧的代码/路径

这里我分成三类说。

### A. 已经从 live executable surface 消失，但文档/测试还在讲

高置信度陈旧项：

- `watch` / `profile` / `enumerate` / `rewrite` / `apply` / `apply-all` 这些 CLI 不再出现在 `daemon/src/main.rs:48-56`。
- 但仍出现在：
  - `daemon/README.md:34-90,206-213`
  - `docs/daemon-architecture.md:76-85,161-215`
  - `docs/paper/documents/eval-spec.md:21,240,345-348`
  - `tests/integration/vm_daemon_live.sh:45,65,82,99`
  - `tests/integration/vm_comprehensive.sh:32,141`

这说明“watch 正在删”这件事在代码层面基本已经发生，但清理没有完成。

### B. 仍留在 helper 层、但明显不在主 artifact 路径

高概率 sidecar / stale path：

- `runner/libs/rejit.py:309-332` 的 `_run_enumerate()`
- `runner/libs/rejit.py:347-364` 的 `enumerate_program_record()`
- `runner/libs/rejit.py:433-760` 的 one-shot `_apply_one()` / `apply-all` 分支
- `runner/scripts/arm64_t4g_remote_benchmark.py:336,468` 仍调用 `apply_daemon_rejit(..., [prog_id])`，未显式给 `enabled_passes`，会走旧 CLI apply 路径
- `runner/libs/profiler.py:16` 默认 daemon 路径还是 `daemon/build/bpfrejit-daemon`，和主路径 `daemon/target/release/bpfrejit-daemon` 不一致
- `runner/scripts/bpf_profiler.py`、`runner/scripts/collect_e2e_profile.py` 的 help 仍写 “live enumerate”

这些路径未必完全无用，但已经不像当前论文 artifact 的 canonical path。

### C. 仍在源里、但不属于当前 evaluation scope

- 安全相关 barrier 残留：
  - `module/x86/Makefile:12`
  - `module/arm64/Makefile:12`
  - `tests/unittest/rejit_kinsn.c:134,176`
  - `daemon/README.md:165-171`
- 这和仓库约束里“security passes out of scope”是不一致的。

### D. 仍活着、不要误删

不要把这些错判成 dead code：

- `profiler.rs` 仍被 `serve --pgo` 使用：`daemon/src/commands.rs:169-190`
- `invalidation.rs` 仍被 `serve` 每秒 tick 使用：`daemon/src/server.rs:83-109`

也就是说，**真正陈旧的是旧 CLI / 旧文档 / 旧集成脚本，不是整个 PGO 或 invalidation 机制**。

## 4. God Files（>500 LOC）与职责分析

### 4.1 最危险的生产/配置 God Files

| LOC | 文件 | 主要职责 | 评价 |
| ---: | --- | --- | --- |
| 18,331 | `corpus/config/macro_corpus.yaml` | 整个语料库清单与触发/元数据 | 研究价值高，但已经不可人工审阅；应拆分/生成/加 schema lint |
| 4,304 | `runner/src/kernel_runner.cpp` | kernel load/attach/measure + daemon socket client + REJIT apply + workload path | 典型 God file，职责过多 |
| 2,525 | `daemon/src/passes/map_inline.rs` | 最复杂的 pass，本身是论文核心之一 | 复杂度大体合理，但需要更强局部封装 |
| 2,296 | `corpus/modes.py` | benchmark config、guest exec、manifest 解析、结果汇总、markdown | 明显应拆模块 |
| 2,239 | `e2e/cases/katran/case.py` | Katran setup/traffic/control/report 全包 | 单文件承担了整个 deployment harness |
| 1,991 | `runner/src/batch_runner.cpp` | batch spec、daemon batch client、static verify、progress JSON | 第二个 God file |
| 1,288 | `corpus/run_code_size_comparison.py` | code-size experiment orchestration | 偏 sidecar，放在主仓库核心层级不划算 |
| 1,206 | `daemon/src/commands.rs` | optimize flow、PGO、rollback、结果归因 | 核心但过宽 |
| 1,180 | `daemon/src/elf_parser.rs` | ELF lifting / parse | 复杂但相对合理 |
| 1,171 | `daemon/src/bpf.rs` | live BPF interaction | 核心 glue，合理但需要更明确边界 |
| 1,103 | `runner/src/common.cpp` | CLI args、keep-alive JSON、sample/result serialization | 已经像公共层，但又继续长大 |
| 1,077 | `e2e/cases/tetragon/case.py` | Tetragon harness | 重复骨架明显 |
| 1,033 | `e2e/cases/tracee/case.py` | Tracee harness | 重复骨架明显 |
| 1,020 | `daemon/src/passes/bounds_check_merge.rs` | 新 pass 实现 | 功能合理，但单 pass 体积开始接近 reviewer 警戒线 |
| 989 | `daemon/src/passes/endian.rs` | 新 pass 实现 | 同上 |
| 909 | `micro/driver.py` | micro suite orchestration | 体量还能接受，但应统一 pass plumbing |
| 905 | `runner/src/llvmbpf_runner.cpp` | llvmbpf runtime path | 大体合理 |
| 892 | `daemon/src/kfunc_discovery.rs` | kfunc/BTF discovery | 合理 |
| 871 | `daemon/src/passes/skb_load_bytes.rs` | pass 实现 | 合理但偏大 |
| 853 | `daemon/src/passes/bulk_memory.rs` | pass 实现 | 合理 |
| 852 | `micro/generate_figures.py` | figure generation | 存在，但 paper figure 链并未真正闭环 |

### 4.2 大文件里最明显的职责混杂

#### `runner/src/kernel_runner.cpp`

至少同时承担：

- daemon socket 协议客户端
- JSON 解析
- REJIT syscall path
- prepared kernel state
- attach/load/measure workload path
- compile/run reporting 聚合

更糟的是，这些职责本来已经有可抽出的公共实现：

- `runner/src/daemon_client.cpp`
- `runner/src/json_parser.cpp`

所以这不是“不可避免的大文件”，而是 **重构未完成的大文件**。

#### `corpus/modes.py`

至少同时承担：

- benchmark config 读取
- pass 配置解析
- VM 命令构造
- corpus manifest 解析
- batch job 生成
- guest/host 执行
- markdown 结果生成

这是最典型的“脚本长成框架”的文件。

#### `e2e/cases/katran/case.py`

Katran case 的问题不是它长，而是它在一个文件里做了过多异构事情：

- 环境/拓扑 setup
- traffic generation
- phase compare
- markdown/report 输出
- live apply 协调

这会让 Katran 成为整个 artifact 最脆弱的一环。

### 4.3 测试 God Files

测试侧 >500 LOC 的文件也很多，主要集中在：

- `tests/unittest/rejit_kinsn.c`
- `tests/unittest/rejit_regression.c`
- `tests/unittest/rejit_prog_types.c`
- `tests/unittest/rejit_safety_tests.c`
- `tests/unittest/rejit_late_rollback.c`
- `tests/unittest/rejit_audit_tests.c`
- `tests/unittest/rejit_swap_tests.c`
- `tests/unittest/rejit_pass_correctness.c`
- `tests/unittest/rejit_poc.c`
- `tests/unittest/rejit_spectre.c`
- `tests/unittest/rejit_hotswap_sched_cls.c`
- `tests/negative/adversarial_rejit.c`
- `tests/negative/scx_prog_show_race.c`

这些大文件更多反映“测试场景铺得很广”，不是一等架构问题。真正的架构问题还是生产路径的大文件。

## 5. 重复实现：最明显的四处

### 5.1 daemon 启动/默认路径重复

同一个默认 daemon 路径被硬编码在多处：

- `corpus/modes.py:70`
- `daemon/tests/static_verify.py:38`
- `e2e/cases/tracee/case.py:63`
- `e2e/cases/tetragon/case.py:63`
- `e2e/cases/scx/case.py:49`
- `e2e/cases/bpftrace/case.py:57`
- `e2e/cases/katran/case.py:60`
- `e2e/cases/bcc/case.py:68`

同时还有不一致实现：

- 主路径使用 `daemon/target/release/bpfrejit-daemon`
- `runner/libs/profiler.py:16` 却使用 `daemon/build/bpfrejit-daemon`

这类重复最容易导致“某个边缘脚本永远跟不上主路径”。

### 5.2 pass 配置解析重复

几乎同一逻辑出现了三遍：

- `runner/libs/rejit.py:123-140,174-185`
- `corpus/modes.py:216-240`
- `daemon/tests/static_verify.py:93`

更严重的是：

- `micro` 没有复用任何一份，而是干脆没把 pass list 传下去。

### 5.3 JSON / daemon protocol 重复

仓库里已经有：

- `runner/src/json_parser.cpp`
- `runner/src/daemon_client.cpp`

但仍然存在：

- `runner/src/kernel_runner.cpp:1400-1781` 的本地复制版
- `runner/src/batch_runner.cpp:507-846` 的 `_batch` 复制版

这是当前最典型的“同一协议三份实现”。

### 5.4 E2E case scaffold 重复

六个 case 文件都在重复同一套 life cycle：

- attach/ensure artifacts
- baseline phase
- apply rejit
- post-rejit phase
- compare
- markdown/report

这说明 `e2e/case_common.py` 的抽象还远远不够。

## 6. Artifact 可复现性

### 6.1 正面评价

仓库并不是完全没有 canonical entry point：

- 根 `Makefile` 确实提供了 `make vm-micro`、`make vm-corpus`、`make vm-e2e`、`make vm-all`
- `e2e/run.py` 也能统一调度多 case
- `corpus/modes.py`、`micro/driver.py` 在同一 checkout 内对排序/seed 的处理总体偏确定性

同一 checkout 内的正面信号：

- `micro/driver.py:604-606`：未指定 `--shuffle-seed` 时顺序稳定
- `corpus/modes.py:1597-1598,1718-1736`：结果/目标按 canonical name 排序
- `runner/libs/reporting.py:317,484,554`：bootstrap seed 固定
- `runner/libs/input_generators.py`：广泛使用固定 seed

### 6.2 负面评价

但从 artifact reviewer 角度，闭环仍不成立。

#### 缺失/失效的入口

- `README.md:68-69` 宣称存在 `make verify-build` 和 `make compare`
- 代码库里没有这两个 Make target
- `micro/README.md:40,46,52` 引用 `docs/paper/scripts/run_micro.sh`
- 该路径并不存在

#### paper figure 仍是 placeholder

- `docs/paper/figures-next/fig-rq1-micro-overview.tex:1-5`
- `docs/paper/figures-next/tab-rq3-daemon-overhead.tex:1-5`
- `docs/paper/sections/6-evaluation.tex:83-127`

这些文件明确写着 `Synthetic placeholder` / `placeholder dataset`。这意味着 “运行 artifact -> 生成 paper figure” 这条路径现在并不成立。

#### 语料库来源没有 pin 到 commit

- `runner/repos.yaml` 只记录 `url + branch`
- `runner/scripts/fetch_corpus_repos.py:65-73` 做的是 branch head fetch / checkout

结果：

- 同一 checkout 内可以 deterministic
- 跨时间不能 deterministic

对于真实程序 corpus，这会被 reviewer 视为复现实验设计的硬伤。

#### 结果与临时文档污染主仓库

当前被跟踪的输出规模：

- `e2e/results/**`: `214 files`
- `corpus/results/**`: `74 files`
- `micro/results/**`: `55 files`
- `docs/tmp/**`: `1104 files`

工作树中的结果目录大小：

- `micro/results`: `461M`
- `corpus/results`: `79M`
- `e2e/results`: `315M`

这不是“审美问题”。对 artifact reviewer 来说，这会带来三个负面信号：

1. 不容易分辨 source of truth。
2. 容易把旧结果误认为当前可复现结果。
3. 仓库导航成本显著升高。

## 7. 审稿人会抓的 red flags

### 高优先级

1. **接口漂移**
   - 当前 binary 只有 `serve`，但 README/doc/tests 还在写老 CLI。
2. **评测 pass policy 不一致**
   - `daemon/src/pass.rs:567-571` 默认启用全部 `PASS_REGISTRY`
   - `corpus/config/benchmark_config.yaml:8-13` 默认只启用 `map_inline,const_prop,dce`
   - `runner/libs/rejit.py:31,123-140,267-274` 与 `corpus/modes.py:216-240` 也都围绕这三项
   - `micro/driver.py` 只传 `daemon_socket`，不传 `enabled_passes`
3. **静默失败**
   - `runner/Makefile:77`
   - `corpus/modes.py:887`
   - `module/load_all.sh:19`
4. **手写协议解析 fail-open**
   - `runner/src/json_parser.cpp:21-28,45-58,165-186`
5. **paper 仍带 placeholder / TODO / ACM 占位符**
   - `docs/paper/main.tex:18`
   - `docs/paper/documents/draft-v0.md:22,439-598`
   - `docs/paper/sections/6-evaluation.tex:83-127`

### 中优先级

1. **硬编码路径和 socket**
   - `daemon/target/release/bpfrejit-daemon`
   - `/tmp/bpfrejit.sock`
   - `/var/run/bpfrejit.sock`
2. **硬编码启动时序**
   - `runner/Makefile:307,317` 直接 `sleep 0.5`
3. **docs/README 结构陈旧**
   - `README.md:22-24` 仍列出顶层 `config/ scripts/ docker/`
4. **scope 外能力残留在默认模块路径**
   - `bpf_barrier` 仍在默认 build/load 流程里

### 低优先级

- 源码中的 TODO/FIXME/HACK 本身并不多，真正的问题不是注释债，而是 **结构漂移和 artifact 漂移**。
- 也就是说，这个仓库现在不像“到处 TODO 的原型”，更像“经历多轮快速迭代但还没收口”的研究系统。

## 8. 按目录给出的简短 reviewer verdict

- `daemon/`: 研究系统主体，值得保留和打磨；优先修接口收敛和文档一致性。
- `runner/`: 最需要重构；当前 reviewer 最容易攻击这里的重复实现和 God file。
- `corpus/`: 数据价值高，但需要把“巨型 YAML + 巨型脚本”转成更可审阅的结构。
- `micro/`: 需要补 pass plumbing 和 paper figure regeneration。
- `e2e/`: 需要抽公共框架，否则每修一次 daemon/client 都要改六遍。
- `module/`: 这是论文最漂亮的部分之一；只需把 out-of-scope 模块从默认路径拿掉。
- `tests/`: 量大不是问题；陈旧接口测试才是问题。
- `docs/`: 当前是最容易让 reviewer 失去信心的部分之一。

## 9. 我建议的提交前清理顺序

如果目标是 “SOSP 审稿人看到 repo 就不皱眉”，我会按这个顺序修：

1. **统一 pass policy**
   - 定义一个唯一真源，让 `micro/corpus/e2e/daemon` 共享。
   - `micro` 必须显式传 `enabled_passes`。
2. **收敛 daemon public surface**
   - 要么恢复 one-shot CLI 并维护它；
   - 要么删掉所有文档/测试/helper 中对旧 CLI 的引用。
3. **去掉 silent failure**
   - 模块加载失败必须失败，不要 `2>/dev/null || true`
   - 协议解析失败不要默认成 `0` 或空值
4. **拆 `runner`**
   - 强制 `kernel_runner.cpp` / `batch_runner.cpp` 复用 `daemon_client.cpp` + `json_parser.cpp`
5. **补 artifact 闭环**
   - 真正提供 `make artifact` / `make figures`
   - 删除 README 中不存在的 target
   - 删除 `micro/README.md` 中不存在的脚本引用
6. **pin corpus repos**
   - `runner/repos.yaml` 记录 commit SHA，而不是 floating branch
7. **清理 repo hygiene**
   - 把 `docs/tmp/**`、大量 `results/**` 从主仓库主线中移出，或者至少明确区分 snapshot 与 regenerate path

## 10. 最终判断

从 SOSP 论文审稿人视角，这个代码库最有说服力的部分是：

- `daemon + module` 的职责切分
- `PASS_REGISTRY` 驱动的 pass 架构
- 真实语料库与 E2E 场景的野心

最不让人放心的部分是：

- 跑的到底是不是同一套 pass policy
- 代码、文档、测试是否处于同一版本面
- artifact 是否真的能从源码一键走到论文图表

所以我的结论不是“系统不行”，而是：

> **系统架构已经值得投稿，但仓库组织与 artifact 收敛程度还没达到最强版本。**

如果只按 reviewer 风险排序，优先级最高的不是继续加新 pass，而是把 **pass policy 一致性、旧接口清理、silent failure、paper/artifact 闭环** 先做干净。
