# daemon pass 测试迁移到真实 `.bpf.o` 的评审

日期：2026-03-26

## 结论摘要

- “ALL daemon pass tests 都是手写 insn” 这句话在 2026-03-26 这个时点已经不完全准确：15 个 pass 文件合计 283 个 `#[test]`，其中 276 个仍是手写 `BpfInsn`，7 个已经接入真实 ELF，但它们全部来自 `micro/programs/*.bpf.o`，不是 `corpus/build/`。
- 当前最值得优先迁移的不是所有 pass 同时开工，而是 `map_inline -> const_prop -> dce` 这一条链，再加上 `skb_load_bytes` 和 `bounds_check_merge`。这三组最容易因为“手写模式像、真实 clang 输出不像”而失真。
- `daemon/src/insn.rs` 里现有的 `load_bpf_insns_from_elf()` 只能拿到“第一个可执行 section”的原始指令流；它不做 section 选择、不解析 relocation、不推断 `prog_type`、不保留 map 引用关系。对 `map_inline` 这类依赖 `.maps` relocation 的 pass 来说，这个能力不够。
- `corpus/build/` 是通过 `make corpus-build` 生成的，不是 `make daemon-tests` 的前置步骤。默认单元测试如果直接硬依赖 `corpus/build`，在干净 checkout / CI 上会不稳定。
- `rotate` 是明显例外：按当前 pass 的精确匹配逻辑扫描 `corpus/build/*.bpf.o`，没有扫到高置信命中。这个 pass 不应该强行先迁；应继续保留手写用例和现有 `micro/programs/rotate_dense.bpf.o`，后续再补一个真正来自上游源码的 source-backed fixture。

## 审计方法

### 1. 测试审计

- 逐个阅读了以下文件：
  - `daemon/src/passes/wide_mem.rs`
  - `daemon/src/passes/map_inline.rs`
  - `daemon/src/passes/const_prop.rs`
  - `daemon/src/passes/dce.rs`
  - `daemon/src/passes/rotate.rs`
  - `daemon/src/passes/cond_select.rs`
  - `daemon/src/passes/extract.rs`
  - `daemon/src/passes/endian.rs`
  - `daemon/src/passes/bounds_check_merge.rs`
  - `daemon/src/passes/skb_load_bytes.rs`
  - `daemon/src/passes/bulk_memory.rs`
  - `daemon/src/passes/dangerous_helper_firewall.rs`
  - `daemon/src/passes/live_patch.rs`
  - `daemon/src/passes/branch_flip.rs`
  - `daemon/src/passes/spectre.rs`
- 分类标准：
  - “手写” = 测试主体直接构造 `BpfProgram::new(vec![...])` / `BpfInsn { ... }`
  - “真实” = 测试体使用 `load_bpf_insns_from_elf()` 或等价真实 ELF 字节来源

### 2. `corpus/build` 候选扫描

- 对 `corpus/build/**/*.bpf.o` 所有可执行 section 做了只读 ELF 扫描。
- 计数方式：
  - `map_inline`、`skb_load_bytes`、`dangerous_helper_firewall`：按 helper ID 精确统计
  - `wide_mem`、`extract`、`endian_fusion`、`cond_select`、`branch_flip`：按当前 pass 源码的精确局部模式做扫描
  - `bounds_check_merge`、`bulk_memory`：按 pass 主模式做近似扫描，足够用于筛对象，不足以替代真实 pass 运行
  - `live_patch`：只按子模式代理信号筛选对象（`map_lookup_elem`、`probe_read*`、`tail_call`、`xdp_adjust_head` / `skb_store_bytes`），没有复刻完整 liveness/ctx-root 证明
- 重要结论：
  - `rotate` 精确扫描命中数为 0
  - `bulk_memory` 的真实对象几乎全是 memcpy 类命中，没有找到可信的 memset 真实命中

## 现有 `.bpf.o` 解析能力评估

### 已有能力

- `daemon/src/insn.rs` 提供了 `#[cfg(test)] fn load_bpf_insns_from_elf(path: &str) -> Option<Vec<BpfInsn>>`
- 它能：
  - 读取 ELF64 little-endian
  - 找到“第一个可执行 `PROGBITS` section”
  - 按 8-byte `struct bpf_insn` 解码为 `Vec<BpfInsn>`

### 明确缺口

- 不能枚举多个程序 section
- 不能按 section 名选择程序
- 不解析 `.rel*` relocation
- 不提取 map symbol / map index / `.maps` 对应关系
- 不推断 `prog_type`
- 不提取 section 级元数据，无法把一个 `.bpf.o` 稳定地拆成多个 pass fixture

### 为什么这会卡住迁移

- `map_inline` / `const_prop` / `dce`
  - `MapInfoAnalysis` 依赖 `program.map_ids`
  - map 引用来自 `LD_IMM64 + BPF_PSEUDO_MAP_FD`
  - 真实 `.bpf.o` 里如果不解 relocation，很多 map load 的 `imm` 仍然是 `0`
  - 多 map 对象会被错误合并成一个“老 fd”
- `skb_load_bytes` / `bounds_check_merge` / `live_patch` / `wide_mem`
  - 都和 `PassContext.prog_type` 有关
  - 如果不从 section 推断程序类型，测试会跑在错误语义下
- `branch_flip`
  - 还需要外部注入 mock PGO/branch profile

### 依赖检查结果

- `daemon/Cargo.toml` 当前没有 `object`、`goblin`、`libbpf-rs`、`libbpf_rs`
- 也就是说，仓库里现在没有现成的“真实 `.bpf.o` -> 多 section fixture + relocation”解析层

### 可复用的现有测试基础设施

- `crate::bpf::install_mock_map()` / `MockMapState`
- `BpfProgram::set_map_ids()`
- `PassContext::test_default()`
- `ProfilingData` / `BranchProfile`

结论：共享 harness 不是从 0 开始，但必须补 section/relocation/prog_type 这一层。

## `corpus/build` 在测试时是否可用

- 顶层 `Makefile` 里，`corpus/build` 的规范入口是：
  - `make corpus-fetch`
  - `make corpus-build`
- `corpus/README.md` 也明确写了 `corpus/build/<repo>/` 是 `make corpus-build` 的产物
- 当前 `make daemon-tests` 只做：
  - `cargo test --manifest-path daemon/Cargo.toml`
- 这意味着：
  - 干净 checkout 上，`corpus/build` 不保证存在
  - 默认 unit test 不应隐式依赖本地残留的 `corpus/build`

## 每个 pass 的现状与迁移建议

说明：

- “手写 / 真实” 列按测试数量统计
- “现有真实夹具” 全部来自 `micro/programs/*.bpf.o`
- “推荐 `.bpf.o`” 优先给出 2 到 3 个对象
- 计数写法如 `map=324` / `skb=230` / `wide=98` 来自本次扫描
- 优先级定义：
  - `P0`：应最先迁
  - `P1`：共享 harness 建好后应尽快迁
  - `P2`：值得迁，但不是首批
  - `P3`：暂缓
- “增量工作量” 是在共享 real-object harness 已经存在后的 pass 侧增量，不含公共基建

| Pass | 当前测试 | 手写 / 真实 | 现有真实夹具 | 推荐 `.bpf.o` | 优先级 | 增量工作量 | 备注 |
| --- | ---: | ---: | --- | --- | --- | --- | --- |
| `map_inline` | 27 | 27 / 0 | 无 | `corpus/build/katran/xdp_pktcntr.bpf.o`（`map=2`，1 section，已知真实命中）<br>`corpus/build/cilium/bpf_xdp.bpf.o`（`map=324`，3 sections）<br>`corpus/build/tracee/tracee.bpf.o`（`map=4555`，157 sections，扩展压测） | P0 | 1.5-2d | 最高价值迁移项；必须同时补 relocation、`map_ids`、mock map 值与 section 选择 |
| `const_prop` | 5 | 5 / 0 | 无 | `corpus/build/katran/xdp_pktcntr.bpf.o`<br>`corpus/build/cilium/bpf_xdp.bpf.o`<br>`corpus/build/tracee/tracee.bpf.o` | P0 | 0.5d | 建议不要单独测裸 `.bpf.o`；应写成 `map_inline -> const_prop` 的 pipeline 测试 |
| `dce` | 5 | 5 / 0 | 无 | `corpus/build/katran/xdp_pktcntr.bpf.o`<br>`corpus/build/cilium/bpf_xdp.bpf.o`<br>`corpus/build/tracee/tracee.bpf.o` | P0 | 0.5d | 同上，建议作为 `map_inline -> const_prop -> dce` 链路测试 |
| `wide_mem` | 39 | 38 / 1 | `test_scan_wide_mem_real_bytecode` -> `micro/programs/load_byte_recompose.bpf.o` | `corpus/build/tetragon/bpf_generic_uprobe.bpf.o`（`wide=98`，3 sections）<br>`corpus/build/calico/to_hep_debug.bpf.o`（`wide=20`，1 section）<br>`corpus/build/loxilb/llb_ebpf_main.bpf.o`（`wide=863`，9 sections，压测） | P1 | 0.5-1d | 迁移阻力低；现有 pass 已经证明能吃真实 clang 风格 byte ladder |
| `rotate` | 19 | 18 / 1 | `test_scan_rotate_real_bytecode` -> `micro/programs/rotate_dense.bpf.o` | 暂无高置信 `corpus/build` 候选；按当前精确 scanner 扫描命中数为 0 | P3 | 0.5d（仅维持现状） / 1-2d（另找新 fixture） | 不建议强行从 `corpus/build` 迁；继续保留手写与 `rotate_dense`，后续再补 source-backed 真实对象 |
| `cond_select` | 26 | 25 / 1 | `test_scan_cond_select_real_bytecode` -> `micro/programs/cond_select_dense.bpf.o` | `corpus/build/tetragon/bpf_generic_lsm_core.bpf.o`（`select=1207`，2 sections）<br>`corpus/build/cilium/bpf_xdp.bpf.o`（`select=230`，3 sections）<br>`corpus/build/calico/to_hep_debug.bpf.o`（`select=40`，1 section） | P1 | 0.5-1d | 候选丰富，真实迁移价值高；可以明显替代当前手写 diamond 模式 |
| `extract` | 28 | 27 / 1 | `test_scan_extract_real_bytecode` -> `micro/programs/bitfield_extract.bpf.o` | `corpus/build/tetragon/bpf_generic_kprobe.bpf.o`（`extract=22`，4 sections）<br>`corpus/build/tetragon/bpf_generic_uprobe.bpf.o`（`extract=22`，3 sections）<br>`corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o`（`extract=6`，3 sections，紧凑） | P1 | 0.5-1d | 现有微基准已经是对的方向；应补 corpus 侧真实对象 |
| `endian_fusion` | 24 | 23 / 1 | `test_scan_endian_real_bytecode` -> `micro/programs/endian_swap_dense.bpf.o` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_endian.bpf.o`（`endian=3`，1 section，最干净）<br>`corpus/build/calico/to_hep_debug.bpf.o`（`endian=150`，1 section）<br>`corpus/build/cilium/bpf_lxc.bpf.o`（`endian=16`，3 sections） | P1 | 0.5-1d | `test_endian.bpf.o` 很适合当 committed fast fixture；Calico 适合真实网络路径回归 |
| `bounds_check_merge` | 14 | 14 / 0 | 无 | `corpus/build/cilium/bpf_xdp.bpf.o`（`bounds=43`，3 sections）<br>`corpus/build/xdp-tools/xdp_flowtable.bpf.o`（`bounds=30`，1 section）<br>`corpus/build/calico/from_hep_debug.bpf.o`（`bounds=27`，1 section） | P0 | 0.5-1d | 计数来自 guard proxy，但对象选择很清晰；这类 pass 非常依赖真实 packet parser 形状 |
| `skb_load_bytes` | 14 | 14 / 0 | 无 | `corpus/build/cilium/bpf_lxc.bpf.o`（`skb=230`，3 sections）<br>`corpus/build/cilium/bpf_overlay.bpf.o`（`skb=198`，3 sections）<br>`corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o`（`skb=49`，2 sections，紧凑） | P0 | 0.5-1d | helper `#26` 命中非常多，且真实参数准备顺序与手写最容易偏离 |
| `bulk_memory` | 16 | 16 / 0 | 无 | `corpus/build/calico/to_hep_debug.bpf.o`（`bulk_memcpy=88`，1 section）<br>`corpus/build/loxilb/llb_ebpf_main.bpf.o`（`bulk_memcpy=139`，9 sections）<br>`corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o`（`bulk_memcpy=14`，3 sections） | P2 | 0.5-1d | 真实对象主要覆盖 memcpy 路径；memset/zero-fill 仍建议保留手写 |
| `dangerous_helper_firewall` | 12 | 12 / 0 | 无 | `corpus/build/tetragon/bpf_enforcer.bpf.o`（helpers=`[58,109]`，12K，1 section）<br>`corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_send_signal_kern.bpf.o`（helpers=`[109,117]`，40K）<br>`corpus/build/KubeArmor/protectproc.bpf.o`（helpers 含 `113`，`danger=365`，1 section） | P2 | 0.5-1d | 这组对象可以把 deny / coarseify / audit-only 三类 helper 行为拆开覆盖，不需要一上来用 `tracee` 巨对象 |
| `live_patch` | 13 | 13 / 0 | 无 | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_flow.bpf.o`（`tail=53`，1 section）<br>`corpus/build/katran/balancer.bpf.o`（helper `44`，`map=70`，2 sections）<br>`corpus/build/KubeArmor/protectproc.bpf.o`（`probe_helpers=365`，1 section） | P2 | 1-2d | 只建议先迁 helper_sanitize / tail-call / pointer-refresh 子类；null-guard 漏洞注入仍应保留手写 |
| `branch_flip` | 18 | 16 / 2 | `test_branch_flip_real_bytecode_with_mock_pgo` / `test_branch_flip_real_bytecode_high_miss_rate` -> `micro/programs/branch_flip_dense.bpf.o` | `corpus/build/cilium/bpf_lxc.bpf.o`（`branch_flip=178`，3 sections）<br>`corpus/build/cilium/bpf_xdp.bpf.o`（`155`，3 sections）<br>`corpus/build/tracee/tracee.bpf.o`（`2070`，157 sections，扩展压测） | P1 | 0.5-1d | 已有真实 ELF + mock PGO 先例，迁移到真实 corpus 对象非常直接 |
| `speculation_barrier` | 23 | 23 / 0 | 无 | `corpus/build/cilium/bpf_lxc.bpf.o`（`cond_jumps=4132`）<br>`corpus/build/cilium/bpf_xdp.bpf.o`（`cond_jumps=2919`）<br>`corpus/build/tracee/tracee.bpf.o`（`cond_jumps=30039`，扩展压测） | P1 | 0.5-1d | 这是最容易迁的安全 pass：只要有条件跳转就能产生稳定真实覆盖 |

## 推荐的新测试架构

### 总体方向

建议引入一个 **test-only 的真实对象夹具层**，把“读取 `.bpf.o`”升级成“读取 `.bpf.o` 的多个程序 section，并保留 relocation / section metadata / prog_type 映射”。

### 推荐实现

- 在 `daemon` 侧引入一个仅测试使用的解析模块
- 依赖优先级：
  - 首选：`object` crate，作为 `dev-dependencies`
  - 备选：`goblin`
- 不建议把 `libbpf-rs` 拉进 unit test 层；这类测试并不需要进入内核，也不需要 libbpf loader 语义

### 夹具层至少要提供的能力

1. 打开一个 `.bpf.o`
2. 枚举所有可执行程序 section，而不是只拿第一个
3. 按 section 名选择 fixture，例如：
   - `xdp`
   - `tc/entry`
   - `tc/tail`
   - `raw_tracepoint/sys_enter`
   - `kprobe/...`
4. 从 section 名推断 `PassContext.prog_type`
5. 解析 `.rel*` relocation，恢复 map 引用顺序 / map index
6. 暴露每个 section 的：
   - `name`
   - `insns`
   - `prog_type`
   - `map_relocs`
7. 允许在测试里继续附加：
   - mock map 元信息和值
   - mock PGO branch profile
   - kfunc / packed ABI 可用性

### 期望的测试调用方式

理想上，一个真实 `.bpf.o` 测试应该像这样表达：

1. 打开对象
2. 选择一个 section
3. 构造 `BpfProgram`
4. 按需要注入：
   - `program.set_map_ids(...)`
   - `install_mock_map(...)`
   - `ctx.prog_type = ...`
   - `ctx.kinsn_registry...`
   - `prog.inject_profiling(...)`
5. 跑 pass 或 pass pipeline
6. 断言：
   - `changed == true`
   - `insns_after != insns_before`
   - 输出仍是结构合法的 BPF 指令流

### 断言建议

- `changed == true`
- `insns_after != insns_before`
- 最后一条仍是 `EXIT`
- `LD_IMM64` 没有被截断成单槽
- 分支修正后重新跑 `BranchTargetAnalysis` 不崩
- 对 `map_inline -> const_prop -> dce` 这类链路，优先断言 pipeline 结果，而不是单个 pass 的中间形状

## 为什么不建议“预抽取指令数组”作为主方案

可以做，但不应作为主路线。

主要问题：

- 会丢 section 名，进而丢 `prog_type`
- 会丢 relocation，`map_inline` 直接受影响
- 多程序 `.bpf.o` 会退化成一堆匿名 `Vec<BpfInsn>`
- fixture 更新成本高，和真实 ELF 脱节
- 一旦 clang 输出变化，Rust 源码里的大数组 diff 非常难 review

结论：

- `pre-extracted instruction arrays` 只适合：
  - 极少数不能稳定随仓库存放 `.bpf.o` 的负例
  - 某些必须手工制造的错误/边界条件
- 不适合当“真实 `.bpf.o` 迁移”的主体方案

## 哪些测试应该继续保留手写

以下内容不应该被真实对象完全替代：

- `rotate`
  - 目前 `corpus/build` 没有高置信命中
- `map_inline`
  - key materialization 的边角输入
  - unsupported map type / percpu / lru-percpu 的拒绝路径
  - pointer escape / write-back / interleaved arg setup 等精细负例
- `const_prop` / `dce`
  - 死分支清理的最小化边界条件
  - subprog 删除/保留的精细负例
- `bulk_memory`
  - memset 零填充、overlap、alias gate、tmp live-out 等负例
- `live_patch`
  - 人工构造的 verifier-CVE 风格脆弱模式
  - “ctx save 被 clobber” 这类非常精细的 liveness 回归
- `speculation_barrier`
  - 幂等性、`LD_IMM64` 邻接、branch fixup 的细颗粒度边界
- 所有 pass 的：
  - kfunc unavailable
  - packed ABI unavailable
  - unsupported width / unsupported prog_type
  - interior branch target / alias conflict 等安全拒绝路径

建议目标不是“删掉所有手写测试”，而是：

- 把“是否真的匹配真实 clang 输出”交给真实 `.bpf.o`
- 把“极端边界 / 负例 / 安全门”继续留给手写测试

## fixture 打包建议

### 不建议

- 默认 `cargo test` 直接吃整棵 `corpus/build/`
- 把 `tracee.bpf.o` 这类大对象直接塞进 fast unit tests

原因：

- `tracee.bpf.o` 大约 15M，且有 157 个可执行 section
- `corpus/build` 是 `make corpus-build` 产物，不是默认存在

### 建议的两层方案

#### A. 提交到仓库的小型 committed fixture pack

建议首批挑一组 10 个左右的小/中型对象，覆盖大多数 pass：

- `corpus/build/katran/xdp_pktcntr.bpf.o`，约 8K
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_endian.bpf.o`，约 4K
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o`，约 48K
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o`，约 60K
- `corpus/build/xdp-tools/xdp_flowtable.bpf.o`，约 124K
- `corpus/build/tetragon/bpf_enforcer.bpf.o`，约 12K
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_send_signal_kern.bpf.o`，约 40K
- `corpus/build/calico/from_hep_debug.bpf.o`，约 764K
- `corpus/build/calico/to_hep_debug.bpf.o`，约 820K
- `corpus/build/cilium/bpf_xdp.bpf.o`，约 1.2M
- `corpus/build/cilium/bpf_lxc.bpf.o`，约 1.9M
- `corpus/build/KubeArmor/protectproc.bpf.o`，约 1.1M

这套总量仍可控，足以支撑 fast unit test。

#### B. 可选的扩展 corpus sweep

- 对超大/超多 section 对象，如：
  - `corpus/build/tracee/tracee.bpf.o`
  - `corpus/build/KubeArmor/system_monitor.bpf.o`
  - `corpus/build/loxilb/llb_ebpf_main.bpf.o`
- 放到扩展测试层
- 前置条件：
  - 显式执行 `make corpus-build`
  - 由单独的 Make target 或环境变量打开

## 推荐迁移顺序

### Phase 0：先补公共 harness

预计 2-3d

- 加 test-only ELF/section/relocation 解析层
- 加 section -> `prog_type` 映射
- 加 fixture API
- 把 mock map / mock PGO glue 统一起来

### Phase 1：先做高价值真实回归

预计 3-4d

按顺序：

1. `map_inline`
2. `const_prop`
3. `dce`
4. `skb_load_bytes`
5. `bounds_check_merge`

原因：

- 这组最容易因手写模式偏差而误判
- `map_inline` 已经有真实 bug 先例
- `const_prop` / `dce` 依赖 `map_inline` 的真实输出

### Phase 2：迁移“已证明可吃真实 clang 输出”的模式类 pass

预计 3-5d

- `wide_mem`
- `extract`
- `endian_fusion`
- `cond_select`
- `branch_flip`
- `speculation_barrier`

### Phase 3：迁移复合语义 / 安全类 pass

预计 2-3d

- `dangerous_helper_firewall`
- `bulk_memory`
- `live_patch`

说明：

- 这批应该采用“真实对象 + 手写负例并存”
- 尤其 `live_patch` 不适合追求 100% 真实对象替代

### Phase 4：最后处理 `rotate`

- 如果目标只是“别再全靠手写”，那 `rotate` 现在已经有真实 `micro/programs/rotate_dense.bpf.o`
- 如果目标必须是 `corpus/build/`，那就应先承认：当前 corpus 没有合格对象
- 后续方案：
  - 从上游真实源码里挑一个含 rotate idiom 的 `.bpf.c`
  - 用仓库现有构建链把它编进 fixture pack

## 最终建议

- 不要做“全量一次性迁移”
- 先做共享 harness，然后先打通 `map_inline -> const_prop -> dce`
- 默认 unit test 用 committed 小型 fixture pack
- `tracee` / `system_monitor` / `llb_ebpf_main` 这类大对象放到扩展层
- 手写测试不删，只把它们的职责收缩到：
  - 边界条件
  - 负例
  - 安全门
  - 解析器无法稳定提供的极端输入

如果只允许做一轮最小有效迁移，我的建议是：

1. 先补公共 harness
2. 先迁 `map_inline`
3. 紧接着补 `const_prop` 和 `dce` pipeline 测试
4. 再迁 `skb_load_bytes` 与 `bounds_check_merge`
5. 其余 pass 分批跟上

这条路径最能尽快减少“手写模式看起来对，真实程序里完全打不到”的风险。
