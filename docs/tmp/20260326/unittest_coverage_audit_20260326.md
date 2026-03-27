# BpfReJIT unittest 覆盖审计

日期：2026-03-26  
范围：`docs/kernel-jit-optimization-plan.md`、`module/`、`tests/unittest/`  
方法：只读源码审计；未运行测试；不含 `build-*` 产物

## 结论摘要

- 当前 `tests/unittest/` 一共 **24** 个 test source（`23` 个 `rejit_*.c` + `1` 个 `module/rejit_*.c`），由 [`tests/unittest/Makefile`](../../../tests/unittest/Makefile) 自动发现。
- **REJIT syscall 主路径覆盖较强**：有 PoC、21 个 prog_type、12 个 hotswap 场景、tail call、swap/metadata、并发、若干 kernel bug regression。
- **kernel module unittest 明显不均衡**：`rotate/select/extract/endian/barrier` 有一定覆盖；`x86/arm64 bulk_memory` 和 `arm64 bpf_ldp` **完全没有 unittest 命中**。
- **daemon 集成在当前 unittest 中是空白**：没有任何 `tests/unittest/*` 直接启动 `bpfrejit-daemon` 的 `apply/apply-all/watch/serve` 路径。最接近的只是“模拟 daemon pass pattern”或“回放 past daemon bug”的测试。
- **失败回滚测试不够深**：现在主要证明“verifier 拒绝时原程序不变”，但缺少更晚阶段的 rollback，例如 trampoline refresh / map poke / late swap failure。
- **hotswap breadth 很好**：12 个 attached prog type 都有 live REJIT stress test。

补充说明：文档里说的 `BPF_PROG_GET_ORIGINAL`，在当前 unittest 里主要通过 `BPF_OBJ_GET_INFO_BY_FD + orig_prog_len/orig_prog_insns` 这条 UAPI 路径覆盖，而不是单独的 `sys_bpf(BPF_PROG_GET_ORIGINAL, ...)` 调用。

## 1. 当前 unittest 覆盖范围

### 1.1 全量测试清单

| 测试文件 | 主要类别 | 当前在测什么 |
|---|---|---|
| `tests/unittest/rejit_poc.c` | a, f | same-length / different-length REJIT、`fd_array`、`test_run` 正确性、`orig_prog_len`、双线程并发 REJIT |
| `tests/unittest/rejit_prog_types.c` | a | **21 个 prog type** 的 identity REJIT + `GET_ORIGINAL` + 部分 `TEST_RUN` |
| `tests/unittest/rejit_safety_tests.c` | a, d, f | **N01-N16** 负面测试；**C01-C05** 正确性/roundtrip/metadata；含 unprivileged、bad fd、wrong helper、failed REJIT preserves original |
| `tests/unittest/rejit_verifier_negative_tests.c` | d, f | 回放 4 个 daemon bug 模式：map_value 常量折叠、unreachable insn、bad call dest、unsupported `BPF_PSEUDO_MAP_VALUE` |
| `tests/unittest/rejit_kinsn.c` | b, d | kinsn discovery；rotate/select/extract/endian/barrier 的 verifier/JIT 建模；少量负面 case |
| `tests/unittest/module/rejit_select_alias.c` | b | x86 `bpf_select64` alias bug 回归；9 个 vector 比较 plain BPF proof vs native kinsn |
| `tests/unittest/rejit_pass_correctness.c` | a, e(近似) | **16 个 daemon pass pattern** 对应 `.bpf.o` 的 identity REJIT；含 struct_ops / fentry best-effort |
| `tests/unittest/rejit_spectre.c` | a, e(近似) | branch-containing program 在 changed insn count 下的 REJIT correctness；显式注明不是实际 SpectreMitigationPass |
| `tests/unittest/rejit_tail_call.c` | a | tail-call caller/target 两个基础 REJIT 交互 case |
| `tests/unittest/rejit_swap_tests.c` | a | swap metadata、一致性、并发 `get_info+REJIT`、tail-call poke_tab、一致更新 `orig_prog_insns`、callchain buffer |
| `tests/unittest/rejit_regression.c` | a, f | text_mutex、RCU latency、kallsyms、XDP test_run、并发 REJIT+run、tail call+map update、struct_ops unregister 等 regression |
| `tests/unittest/rejit_audit_tests.c` | a, f | kernel audit fix regression：`fd_array` leak、`xlated_prog_len/insns`、flags、func_info leak、struct_ops multi-slot |
| `tests/unittest/rejit_hotswap_xdp.c` | c | XDP attached live REJIT，10 轮切换 patched behavior |
| `tests/unittest/rejit_hotswap_socket_filter.c` | c | socket filter attached live REJIT，10 轮切换返回长度 |
| `tests/unittest/rejit_hotswap_sched_cls.c` | c | `sched_cls`/TC ingress attached live REJIT，10 轮切换 action |
| `tests/unittest/rejit_hotswap_cgroup_skb.c` | c | cgroup_skb attached live REJIT，10 轮切换 allow/deny |
| `tests/unittest/rejit_hotswap_kprobe.c` | c | kprobe attached live REJIT，10 轮切换 map 累加值 |
| `tests/unittest/rejit_hotswap_tracepoint.c` | c | tracepoint attached live REJIT，10 轮切换 map 累加值 |
| `tests/unittest/rejit_hotswap_perf_event.c` | c | perf_event attached live REJIT，10 轮切换 map 累加值 |
| `tests/unittest/rejit_hotswap_fentry.c` | c | fentry attached live REJIT，检查 attach BTF context 未丢失 |
| `tests/unittest/rejit_hotswap_ext.c` | c | freplace/EXT attached live REJIT，切换 target 返回值 |
| `tests/unittest/rejit_hotswap_lsm.c` | c | LSM attached live REJIT，10 轮切换 map 累加值 |
| `tests/unittest/rejit_hotswap_sk_lookup.c` | c | sk_lookup attached live REJIT，切换 reuseport 目标 |
| `tests/unittest/rejit_hotswap_struct_ops.c` | c | struct_ops attached live REJIT，切换 map store immediate |

### 1.2 按审计要求分类

#### a. REJIT syscall 测试（`BPF_PROG_REJIT`、`BPF_PROG_GET_ORIGINAL`）

覆盖较强。主要文件：

- `rejit_poc.c`
- `rejit_prog_types.c`
- `rejit_swap_tests.c`
- `rejit_regression.c`
- `rejit_tail_call.c`
- `rejit_audit_tests.c`
- `rejit_safety_tests.c`
- `rejit_spectre.c`
- `rejit_pass_correctness.c`
- 全部 `rejit_hotswap_*.c`

具体覆盖点：

- same-length / different-length REJIT
- `orig_prog_len` / `orig_prog_insns` 更新
- `xlated_prog_len` / `xlated_prog_insns` 一致性
- attached program live REJIT
- tail-call poke_tab 更新
- 并发 REJIT、并发 `get_info+REJIT`、并发 `REJIT+run`
- 多次连续 REJIT / roundtrip
- `fd_array` / map fd 传递

不足：

- 缺少更“后半段”的 rollback 测试，尤其是 verifier 通过后、swap/refresh/poke 失败时的恢复语义。

#### b. kinsn 模块测试

当前 unittest 主要集中在：

- `rejit_kinsn.c`
- `module/rejit_select_alias.c`
- `rejit_safety_tests.c` 的 barrier kinsn 有效路径
- `rejit_pass_correctness.c` 的 pattern `.bpf.o`（更多是 identity REJIT，不是直接模块单测）

关键边界：

- [`tests/unittest/rejit_kinsn.c`](../../../tests/unittest/rejit_kinsn.c) 的 discovery matrix 只包含 `rotate/select/extract/endian/barrier` 五个 family；**没有 `bulk_memory`，也没有 `arm64/bpf_ldp`**。

#### c. hotswap 压力测试（12 个 prog_type）

当前已覆盖 **12/12**：

1. `xdp`
2. `socket_filter`
3. `sched_cls`
4. `cgroup_skb`
5. `kprobe`
6. `tracepoint`
7. `perf_event`
8. `fentry`
9. `ext` / freplace
10. `lsm`
11. `sk_lookup`
12. `struct_ops`

特点：

- 都是“**attached live program + 多轮 REJIT**”。
- 每个 case 都验证观测行为切换，而不只是 syscall 成功。

不足：

- 大多只切换一个 immediate/return value，偏向 smoke/stress，不是深语义验证。

#### d. verifier 测试（kinsn 验证语义）

当前已有：

- `rejit_safety_tests.c`
  - `N01-N16`：空程序、未知 opcode、无 exit、未初始化 `r0`、越界 stack、反向跳转、非法 helper、oversized、invalid register、bad fd、non-BPF fd、truncated `LD_IMM64`、wrong helper for prog type、unprivileged REJIT、failed REJIT preserves original、valid barrier kinsn path
- `rejit_verifier_negative_tests.c`
  - 4 个 daemon bug regression
- `rejit_kinsn.c`
  - `rotate_invalid_tmp_rejected`
  - `endian_invalid_access_rejected`
  - `extract_range_narrowing`

评价：

- generic verifier negative 覆盖不错。
- 但“**每个 kinsn payload 的边界与错误处理**”覆盖仍然浅。

#### e. daemon 集成测试

**在 `tests/unittest/` 中没有。**

当前 unittest 里最接近 daemon 的只有：

- `rejit_pass_correctness.c`：测试对象是 daemon pass pattern 对应 `.bpf.o`
- `rejit_verifier_negative_tests.c`：回放 past daemon optimizer bug
- `rejit_spectre.c`：明确说明不是实际 SpectreMitigationPass

项目里确实存在 daemon 侧测试，但不在本次 unittest 范围内：

- `daemon/tests/static_verify.py`
- Rust integration / unit tests（例如 `daemon/src/bpf.rs`、`daemon/src/commands.rs`、各个 pass 文件）

结论：**项目全局并非没有 daemon 测试，但当前 `tests/unittest/` 没有真正的 daemon E2E/integration。**

#### f. 负面测试（权限、错误输入、边界条件）

现有负面覆盖主要来自：

- `rejit_safety_tests.c`：权限、错误 fd、invalid bytecode、oversized、wrong helper、unprivileged
- `rejit_verifier_negative_tests.c`：4 个 malformed bytecode regression
- `rejit_kinsn.c`：rotate invalid tmp、endian invalid access
- `rejit_audit_tests.c`：`flags!=0` rejected

不足：

- per-kinsn 的 payload boundary / error handling 还没有系统化 matrix。

## 2. kinsn 模块 unittest 审计

### 2.1 审计总览

从 [`module/`](../../../module) 看，当前共有 13 个 kinsn module source：

- x86：`bpf_rotate`、`bpf_select`、`bpf_extract`、`bpf_endian`、`bpf_barrier`、`bpf_bulk_memory`
- arm64：`bpf_rotate`、`bpf_select`、`bpf_extract`、`bpf_endian`、`bpf_barrier`、`bpf_bulk_memory`、`bpf_ldp`

但 [`tests/unittest/rejit_kinsn.c`](../../../tests/unittest/rejit_kinsn.c) 的 discovery enum / table 只注册了：

- `MOD_ROTATE`
- `MOD_SELECT`
- `MOD_EXTRACT`
- `MOD_ENDIAN`
- `MOD_BARRIER`

也就是说，**当前 unittest 框架层面就没有把 `bulk_memory` 和 `arm64/bpf_ldp` 纳入 kinsn discovery/test matrix**。

### 2.2 逐模块审计

| 模块 | 有没有 unittest | 当前测了什么 | 主要缺口 |
|---|---|---|---|
| `module/x86/bpf_rotate.c` | 有，直接覆盖 | `rejit_kinsn.c` 覆盖 apply、x86 `ROL` byte pattern、arbitrary regs、`r5` preserved、`LD_IMM64` layout、invalid tmp reject；`rejit_pass_correctness.c` 还覆盖 rotate pattern `.bpf.o` | 缺 `shift=0`、`shift=63`、`dst==src`、invalid `dst/src`、更复杂多-site/attached 场景 |
| `module/arm64/bpf_rotate.c` | 只有共享覆盖，无 arm64 专项 | 理论上 `rejit_kinsn.c` 在 arm64 运行时可触发 rotate success path | 缺 `EXTR` emit 专项验证、arm64 scratch/clobber、`shift=0/63` 边界 |
| `module/x86/bpf_select.c` | 有，直接覆盖 | `rejit_kinsn.c` 覆盖 apply、arbitrary dst；`module/rejit_select_alias.c` 覆盖 9 个 alias/normal/high-reg vector，直接打 x86 alias bug | 缺 invalid cond mode、`true_reg==false_reg` fast path、更多 payload reject case、x86 emit byte pattern |
| `module/arm64/bpf_select.c` | 只有共享覆盖，无 arm64 专项 | 共享 success path 可在 arm64 运行时触发 | 缺 `CSEL` emit 专项、arm64 alias/fast path、invalid payload |
| `module/x86/bpf_extract.c` | 有，但偏浅 | `rejit_kinsn.c` 只测 `extract_range_narrowing`；`rejit_pass_correctness.c` 有 `bitfield_extract` / `bitfield_extract_boundary` pattern | 缺 invalid `start/len` reject、`len==32` special case、native emit (`BEXTR`/x86 lowering) 专项 |
| `module/arm64/bpf_extract.c` | 只有共享覆盖，无 arm64 专项 | 共享 `extract_range_narrowing` 可在 arm64 运行时触发 | 缺 `UBFM` emit 专项、boundary/invalid payload matrix |
| `module/x86/bpf_endian.c` | 有，但偏浅 | `rejit_kinsn.c` 覆盖 endian16、endian32、arbitrary regs、invalid access reject；`rejit_pass_correctness.c` 有 endian pattern | 缺 64-bit path、offset/alignment boundary、x86 emit byte pattern |
| `module/arm64/bpf_endian.c` | 只有共享覆盖，无 arm64 专项 | 共享 endian success path 可在 arm64 运行时触发 | 缺 `REV` 16/32/64 emit、scaled/unscaled offset path、boundary case |
| `module/x86/bpf_barrier.c` | 有，但很浅 | `rejit_kinsn.c` 的 `barrier_preserves_r5`；`rejit_safety_tests.c:N16` 覆盖有效 barrier kinsn 路径 | 缺 `LFENCE` emit 检查、non-zero payload reject、multi-barrier、与真实 Spectre pass 的联动 |
| `module/arm64/bpf_barrier.c` | 只有共享覆盖，无 arm64 专项 | barrier success path 可在 arm64 运行时触发 | 缺 `DSB SY + ISB` emit 检查、payload reject、arm64 特有语义 |
| `module/x86/bpf_bulk_memory.c` | **没有** | `tests/unittest/` 对 `bpf_memcpy_bulk` / `bpf_memset_bulk` 无引用 | 缺整个 family：`memcpy/memset` 正确性、zero-fill / value-from-reg / width class / len 上界 / offset 边界 / reg preservation / emit bytes |
| `module/arm64/bpf_bulk_memory.c` | **没有** | 无 unittest 命中 | 缺整个 family；尤其 arm64 loop/tail handling、宽度/长度/偏移边界、错误 payload、emit correctness |
| `module/arm64/bpf_ldp.c` | **没有** | 无 unittest 命中 | 缺 `bpf_ldp128` / `bpf_stp128` 正确性、load/store 双向、offset `[-512,504]` 边界、lane/base alias reject、emit bytes |

### 2.3 对 kernel module unittest 是否充分的判断

结论：**不充分。**

原因不是“完全没有 module test”，而是“覆盖高度偏科”：

- 已测到的 family：`rotate/select/extract/endian/barrier`
- 完全没测到的 family：`bulk_memory`（x86/arm64）、`arm64 ldp/stp`
- 已测 family 里，x86 比 arm64 深很多；arm64 backend 大多没有 architecture-specific emit 断言
- 已测 family 里，success path 比 boundary/error handling 深很多

## 3. 缺失的测试

### 3.1 按任务要求逐项判断

| 应有测试 | 当前状态 | 审计结论 |
|---|---|---|
| a. 并发 REJIT 测试 | **部分已有** | `rejit_poc.c`、`rejit_regression.c`、`rejit_swap_tests.c` 已覆盖 same-prog / different-prog / `REJIT+run` / `get_info+REJIT` 并发；但缺 attached prog type 上的同 prog 冲突式并发 REJIT |
| b. REJIT 失败回滚测试 | **部分已有** | `rejit_safety_tests.c:N15`、`rejit_kinsn.c` 的 failure-preserves-original 只覆盖 verifier reject；缺 swap/trampoline/map-poke 等 late failure rollback |
| c. map 引用计数测试 | **基本缺失** | 有 `fd_array` leak stress，但没有直接 map refcount/lifetime 断言，例如 close original map fd 后程序是否仍持有正确引用、反复 REJIT 后 `map_ids` 稳定、prog_array / map delete 交错生命周期 |
| d. tail call + REJIT 交互测试 | **已有** | `rejit_tail_call.c`、`rejit_swap_tests.c:T4`、`rejit_regression.c:T7` 已覆盖 caller/target/concurrent map update |
| e. daemon 集成测试 | **当前 unittest 缺失** | `tests/unittest/` 内没有任何真实 daemon process E2E |
| f. kinsn 注册/注销测试 | **缺失** | 现在只有 discovery 已加载模块；没有 module load/unload、stale BTF fd、重复注册/卸载、re-load 路径 |
| g. 性能回归测试 | **当前 unittest 缺失** | 性能应放在 `vm-micro` / `vm-corpus` / `vm-e2e`，当前 unittest 没有 regression gate |

### 3.2 额外缺口

除了题目列出的 a-g，还存在这些明显空洞：

1. `bulk_memory` / `arm64 ldp` 完全无 unittest
2. arm64 backend 缺少 emit-level 验证
3. `bpf_endian_load64()` 没有直接 module unittest
4. `bpf_select64()` 的 invalid payload / fast path 没有系统化负测
5. barrier family 没有“真实 barrier emit 序列”验证

## 4. 建议（按优先级）

### P0

1. **先补 `bulk_memory` 和 `arm64 bpf_ldp` unittest。**  
   这是当前 module 覆盖最大的硬缺口，属于“代码已经进仓，但 unit suite 完全不知道它存在”。

2. **补一个真实 daemon E2E/VM 集成测试。**  
   最小可行形式：加载 `tests/unittest/progs/*.bpf.o` -> 启动 `bpfrejit-daemon apply` / `apply-all` / `serve` -> 校验行为、`orig_prog_insns`、verifier fallback、disabled passes。

3. **补 late-failure rollback 测试。**  
   不要只测 verifier reject；要测 verify/JIT 之后、refresh/poke/swap 失败时，旧 program / link / trampoline 是否仍然可用。

4. **补 kinsn 注册/注销生命周期测试。**  
   覆盖 module load、discover、use、unload、stale BTF fd reject、reload。

### P1

5. **把已有 kinsn family 的 boundary/error matrix 补完整。**
   - rotate：`shift=0/63`、`dst==src`
   - select：invalid cond mode、`true_reg==false_reg`
   - extract：invalid `start/len`、`len==32`
   - endian：64-bit path、offset/alignment boundary
   - barrier：payload reject、emit bytes

6. **为 arm64 backend 增加 architecture-specific emit 断言。**  
   现在 x86 有 `ROL`/alias 类深测，arm64 基本没有对应的 `EXTR/CSEL/REV/DSB+ISB/LDP/STP` 验证。

7. **补 map lifetime/refcount 测试。**  
   重点是 repeated REJIT 后 map 生命周期是否正确，而不只是 `fd_array` 没泄漏。

### P2

8. **把并发测试从“简单 XDP 程序”扩展到 attached program。**  
   当前并发覆盖主要是简单 program；attached type 的竞争路径（trampoline、struct_ops、tail-call caller）还不够深。

9. **把性能回归 gate 放到 benchmark target，而不是 unittest。**  
   建议走 `vm-micro` / `vm-corpus`，按 AGENTS 约束串行化，不要塞进 `tests/unittest/`。

## 5. 最终判断

如果问题是“当前 unittest 对 **REJIT syscall** 覆盖够不够”，答案是：**中上，主路径和若干关键 regression 都覆盖到了。**

如果问题是“当前 unittest 对 **kernel module / kinsn** 覆盖够不够”，答案是：**不够。**

根本原因有三条：

1. **family coverage 不全**：`bulk_memory` / `arm64 ldp` 完全缺失
2. **backend coverage 不对称**：x86 明显深于 arm64
3. **lifecycle / integration coverage 薄弱**：没有 daemon E2E，也没有 module 注册/注销测试

因此，下一步最该补的不是再加一个 REJIT syscall smoke test，而是：

- `bulk_memory` / `ldp` unit tests
- daemon 真集成测试
- late rollback + module lifecycle tests
