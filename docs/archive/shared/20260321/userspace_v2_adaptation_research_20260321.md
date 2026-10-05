# BpfReJIT v2 用户态与 Benchmark 框架适配调研

日期: 2026-03-21

## 0. 结论先行

基于本仓库现有代码和 `vendor/linux-framework/` 内核树，结论可以先压缩成 7 条:

1. **scanner 的 pattern matching 核心可以大量复用，约 70%-80%**。可直接复用的是 `scanner/src/pattern_v5.cpp` 的 matcher、pattern descriptor、family taxonomy；**不能复用**的是 policy/blob 输出、`enumerate --recompile` CLI、以及只返回 `site_start/site_len` 的结果类型。
2. **v2 的核心变化不是“扫描 live xlated 然后出 policy blob”，而是“扫描 original bytecode 然后生成整段新程序”**。因此 scanner 需要从 `V5PolicyRule` 升级为 `RewriteSite/RewritePlan`。
3. **如果目标真的是完整 `N -> M` bytecode 重写，等长替换 + NOP padding 不够**。必须做全程序重发射，并统一修正所有 branch offset、`BPF_PSEUDO_CALL`、以及可选的 `func_info/line_info`。
4. **插入 kfunc call 不是纯 pattern matching 问题，而是 liveness + calling convention 问题**。因为 helper/kfunc call 会 clobber `R1-R5`，所以 rotate/select 这类 call-based rewrite 需要保存活跃 caller-saved 寄存器，或者跳过该 site。
5. **BTF ID 获取问题是可解的**。vmlinux kfunc 可以只用 libbpf 公共 API 解决；module kfunc 也可解，但前提是 `BPF_PROG_REJIT` 要像 `BPF_PROG_LOAD` 一样接受 `fd_array/fd_array_cnt` 或等价元数据。
6. **当前内核树里的 `BPF_PROG_REJIT` 原型与目标 v2 语义仍有明显差距**。它现在只支持“同长度替换”，并且拒绝 maps/BTF/kfunc/func_info/line_info 等复杂程序。也就是说，daemon/benchmark 可以先改，但要想支持你描述的完整 v2 流程，内核 UAPI 还得继续扩。
7. **benchmark 框架大部分可以复用，尤其是 `run_kernel()` 的 paired measurement 逻辑**。建议新增 `run-rejit` 子命令和 `kernel-rejit` runtime，而不是把 v2 继续塞进现有 `kernel-recompile` 语义里。

---

## 1. 现有用户态代码结构

### 1.1 scanner/

相关代码:

- `scanner/src/pattern_v5.cpp`
- `scanner/include/bpf_jit_scanner/pattern_v5.hpp`
- `scanner/src/policy_config.cpp`
- `scanner/include/bpf_jit_scanner/policy_config.hpp`
- `scanner/src/cli.cpp`

当前 scanner 的真实职责:

- `scan_v5_builtin()` 在原始 8-byte BPF insn 流上做 pattern matching。
- matcher 核心是 `match_v5_pattern_at()`，内部已经有 operand/binding/constraint 机制。
- 输出类型是 `V5PolicyRule`，只保留:
  - family
  - `site_start`
  - `site_len`
  - `canonical_form`
  - `native_choice`
  - `pattern_kind`
- `policy_config.*` 负责:
  - manifest
  - v3 policy YAML
  - live policy remap/filter
- `cli.cpp::run_enumerate()` 当前 live 路径是:
  - `BPF_PROG_GET_NEXT_ID`
  - `BPF_PROG_GET_FD_BY_ID`
  - `BPF_OBJ_GET_INFO_BY_FD`
  - 读 live xlated bytecode
  - 扫描
  - 生成 policy blob
  - `BPF_PROG_JIT_RECOMPILE`

这说明 scanner 现在本质上是:

- 一个可复用的 **site discovery engine**
- 外挂了一层明显 v1/v5 特化的 **policy/blob/apply frontend**

### 1.2 runner/ 与 micro_exec

相关代码:

- `runner/src/main.cpp`
- `runner/src/common.cpp`
- `runner/src/kernel_runner.cpp`
- `runner/src/elf_program_loader.cpp`
- `runner/include/micro_exec.hpp`

当前 `micro_exec` 只有 3 个子命令:

- `run-kernel`
- `run-llvmbpf`
- `list-programs`

v1 recompile 路径在 `kernel_runner.cpp` 中完成:

- `apply_recompile_policy()` 调 `BPF_PROG_JIT_RECOMPILE`
- `run_kernel()` 会在同一个 `prog_fd` 上先测 stock，再 apply，再测 recompile
- `phases_ns` 里已经有 `recompile_apply_ns`

这部分对 v2 很重要，因为 **same-image paired measurement 逻辑已经存在**。

### 1.3 micro/driver.py

相关代码:

- `micro/driver.py`
- `micro/benchmark_catalog.py`
- `micro/config/micro_pure_jit.yaml`
- `runner/libs/commands.py`
- `runner/libs/results.py`

当前 micro suite:

- 一共有 **62 个 benchmark**
- runtimes 是:
  - `llvmbpf`
  - `kernel`
  - `kernel-recompile`

当前 `kernel-recompile` 其实不是独立子命令，而是:

- 仍调用 `micro_exec run-kernel`
- 加 `--recompile-v5 --recompile-all`
- 或 policy 相关参数

注意:

- `runner.libs.results.collapse_command_samples()` 现在只认识 `stock -> recompile` 这对 phase
- 这意味着如果直接引入 `phase="rejit"`，解析层也要一起改

### 1.4 corpus/driver.py 与 e2e/

相关代码:

- `corpus/driver.py`
- `corpus/modes.py`
- `runner/libs/recompile.py`
- `runner/libs/policy.py`
- `e2e/cases/*/case.py`

当前 live apply 共享层是 `runner/libs/recompile.py`:

- `scan_programs()`
- `apply_recompile()`
- 内部走 `scanner enumerate --prog-id --recompile`

`corpus/driver.py` 里有两类 v1 path:

- `run_micro_exec_sample()`: `micro_exec run-kernel`
- `run_compile_only_loadall_sample()` / `apply_recompile_v5()`: `bpftool loadall` 后对 live prog_id 循环调用 scanner

`e2e` 里的 tracee/tetragon/scx/bpftrace/katran 都直接依赖这层 `scan_programs()/apply_recompile()`。

因此，**`runner/libs/recompile.py` 是整个 live benchmark/e2e 迁移的中心切点**。

---

## 2. scanner 改造方案

## 2.1 哪些能复用，哪些必须重写

### 2.1.1 可直接复用的部分

建议直接复用:

- `match_v5_pattern_at()` 的匹配引擎
- 现有 family 分类:
  - `Cmov`
  - `WideMem`
  - `Rotate`
  - `AddrCalc`
  - `BitfieldExtract`
  - `EndianFusion`
  - `BranchFlip`
- 现有 pattern descriptors 和 `pattern_kind`
- `scan_v5_builtin()` 的大部分遍历框架

原因:

- 这些逻辑本来就是在 BPF insn 流上工作，不依赖 native policy blob。
- 现有 matcher 内部已经有 operand binding 和 constraint 机制，只是现在没有把 captures 暴露给外层。

### 2.1.2 需要重写的部分

必须重写:

- `V5PolicyRule`
- `build_policy_blob_v5()`
- `policy_config.*`
- `cli.cpp` 中所有 `generate-policy/compile-policy/apply/enumerate --recompile` 路径
- cost-model 与 live policy remap 逻辑

原因:

- v2 输出不再是 `{site_start, site_len, canonical_form, native_choice}`，而是 **完整新 bytecode**
- v2 还需要携带更多信息:
  - 被捕获的寄存器/立即数
  - site safety 信息
  - 是否需要 spill
  - 是否需要 `fd_array` / `prog_btf_fd`

### 2.1.3 建议的新数据模型

建议把 scanner 输出从 `V5PolicyRule` 升级为:

```c++
struct RewriteBinding {
  std::string name;
  enum { Reg, Imm, Off } kind;
  int64_t value;
};

struct RewriteSite {
  V5Family family;
  std::string pattern_kind;
  uint32_t start_pc;
  uint16_t old_len;
  std::vector<RewriteBinding> bindings;
  uint32_t live_in_mask;
  uint32_t live_out_mask;
  bool has_interior_branch_target;
  bool crosses_func_boundary;
};

struct RewritePlan {
  std::vector<RewriteSite> sites;
  std::vector<std::string> warnings;
};
```

这里最关键的新字段是:

- `bindings`: rewriter 需要知道具体是哪几个寄存器、哪些 immediates
- `live_in/live_out`: call-based rewrite 必须知道周围寄存器活跃性
- `has_interior_branch_target`: 站内是否有控制流落点
- `crosses_func_boundary`: 是否跨 BPF-to-BPF subprog 边界

### 2.1.4 复用比例判断

按工程量估算:

- **matcher 核心**: 70%-80% 可复用
- **pattern 描述库**: 60%-70% 可复用
- **scanner 整体仓库**: 40%-50% 可复用

因为当前 scanner 里大量代码其实是 v1 policy/frontend，而不是 site discovery 本身。

## 2.2 bytecode 重写的具体逻辑

### 2.2.1 目标结构

v2 不应再做“原地 patch”，而应做:

1. 解析原始 bytecode 为 `std::vector<bpf_insn>`
2. 构建 CFG 边界:
   - branch target
   - fallthrough leader
   - `BPF_PSEUDO_CALL` target
   - subprog entry
3. 扫描并挑选 rewrite sites
4. 生成新的整段程序
5. 回填所有相对跳转和相对调用
6. 可选地回填 `func_info/line_info`

### 2.2.2 `N > M` 时怎么办

**目标 v2 语义下，不应该靠 NOP 填充。**

原因:

- 既然 `BPF_PROG_REJIT` 语义是提交整段新程序，就应该允许 instruction count 变化。
- 安全检查插入、kfunc lowering、multi-site compose 都天然会产生 `N != M`。
- 只做等长替换会把 v2 自己阉割回 v1 风格。

**但是**，当前内核树里的 `bpf_prog_rejit()` 还明确要求 `tmp->len == prog->len`。这意味着:

- **当前原型内核只能接受等长替换**
- 如果要先在这棵树上做 PoC，只能:
  - 选择等长 rewrite
  - 或者 `N > M` 用 NOP/`JA +0`/self-move 之类填充到原长度

这只是原型兼容技巧，不应成为最终架构。

### 2.2.3 `N < M` 时怎么办

必须做全程序 offset 重算。

具体规则:

- 对普通 branch:
  - `new_off = new_target_pc - (new_pc + 1)`
- 对 `BPF_PSEUDO_CALL`:
  - `new_imm = new_subprog_entry_pc - (new_pc + 1)`
- 对 `LD_IMM64`:
  - 视为 2 条 insn，不可把 site 切到中间

site 选择必须额外满足:

- 没有外部 branch target 落在 site 内部
- site 不跨 subprog boundary
- site 间不重叠

### 2.2.4 call-based rewrite 的隐藏难点: `R1-R5` clobber

这是 v2 相比 v1 最大的用户态新增复杂度之一。

例如:

- `shift+or -> bpf_rotate64()`
- `branch+mov -> bpf_select64()`

都要插入 `BPF_CALL`。

而 helper/kfunc call 的 calling convention 是:

- 参数走 `R1-R5`
- 返回值在 `R0`
- `R1-R5` 是 caller-saved
- `R6-R9` 是 callee-saved

因此 rewrite 前必须做 liveness 分析:

- 如果 site 前后有活跃值还留在 `R1-R5`
  - 要先 spill 到栈或挪到 `R6-R9`
  - 否则这类 site 不能安全改写

这也意味着:

- **wide-load 这类无 call 的 rewrite 最先落地**
- **rotate/select 这类 kfunc rewrite 需要 second pass 的 liveness/spill 逻辑**

### 2.2.5 安全插入类 rewrite

例如:

- 插 bounds check
- 插 speculation barrier

这类 rewrite 比 rotate/wide 更难，因为它们通常:

- 新增 branch
- 改 CFG
- 改 line/func info offset

建议把它们放在 v2 的第二阶段，而不是和 basic optimization rewrite 同期起步。

## 2.3 推荐的 rewrite 分层

建议按难度分三层推进:

### Tier 1: 无 call、局部替换

- byte loads -> wide load
- 某些 endian / extract / addr-calc 合并

特点:

- 不引入 helper/kfunc call
- 不碰 caller-saved clobber
- 最适合先把整段重写框架打通

### Tier 2: kfunc-based 优化

- rotate -> `bpf_rotate64()`
- select/cmov -> `bpf_select64()`

特点:

- 需要 BTF ID 解析
- 需要寄存器活跃性分析
- 需要 spill/restore

### Tier 3: 安全加固与 CFG 变换

- bounds check
- speculation barrier
- branch rewrite with new edges

特点:

- 需要更完整的 CFG repair
- 需要 `func_info/line_info` 修复或重建

---

## 3. kfunc 调用编码与 BTF ID 获取

## 3.1 `BPF_CALL` kfunc 的精确编码

这部分在当前内核树里已经很清楚。

UAPI 定义:

- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `BPF_PSEUDO_KFUNC_CALL == 2`

编码规则:

- `code = BPF_JMP | BPF_CALL`
- `src_reg = BPF_PSEUDO_KFUNC_CALL`
- `imm = BTF_KIND_FUNC 的 BTF ID`
- `off = 0` 表示 vmlinux kfunc
- `off = module BTF 在 fd_array 中的索引` 表示 module kfunc

内核宏也一样:

- `vendor/linux-framework/include/linux/filter.h`
- `BPF_CALL_KFUNC(OFF, IMM)`

JIT/core 路径也印证了 `off` 的语义:

- `vendor/linux-framework/kernel/bpf/core.c`
- `bpf_get_kfunc_addr(prog, insn->imm, insn->off, &addr)`

## 3.2 daemon 怎么拿 `bpf_rotate64` 的 BTF ID

### 3.2.1 推荐解法: 优先用 libbpf 公共 BTF API

vmlinux kfunc:

1. `btf = btf__load_vmlinux_btf()`
2. `id = btf__find_by_name_kind(btf, "bpf_rotate64", BTF_KIND_FUNC)`
3. 生成:

```c
BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, BPF_PSEUDO_KFUNC_CALL, 0, id)
```

这条路径完全可行，且只依赖公开 API。

### 3.2.2 module kfunc

module kfunc 也能做，但有额外前提。

推荐流程:

1. `vmlinux = btf__load_vmlinux_btf()`
2. `mod = btf__load_module_btf("your_module", vmlinux)`
3. 在 module split-BTF 中找 `BTF_KIND_FUNC`
4. 取:
   - `imm = func_btf_id`
   - `off = module_btf_fd 在 fd_array 里的 slot`

有一个实现细节要注意:

- libbpf 内部用的是 `btf__find_by_name_kind_own()` 去做“只搜 module 自己，不搜 base BTF”的查找
- 但这个函数 **不是公共 libbpf API**

因此 daemon 最稳的做法有两个:

1. **要求自定义 kfunc 名字全局唯一**
2. 或者自己用公共 API 拼一个 module-only 搜索:
   - `base_cnt = btf__type_cnt(btf__base_btf(mod))`
   - `type_cnt = btf__type_cnt(mod)`
   - 遍历 `[base_cnt, type_cnt)`，对 `btf__type_by_id()` + `btf__name_by_offset()` 做 module-only 匹配

### 3.2.3 当前 REJIT UAPI 对 module kfunc 还不够

这是重点。

当前树里的 `BPF_PROG_REJIT` attr 只有:

- `prog_fd`
- `insn_cnt`
- `insns`
- `log_level/log_size/log_buf`

**没有**:

- `fd_array`
- `fd_array_cnt`

所以如果新程序里插了 module kfunc call，那么 `insn.off` 虽然语义上应该填 module BTF fd slot，但 **用户态没有通道把这个 BTF fd array 传给 REJIT**。

结论:

- **vmlinux kfunc 在当前设计里是可行的**
- **module kfunc 只有在 REJIT attr 扩成类似 `BPF_PROG_LOAD` 后才真正可行**

因此第一版建议:

- 把 `bpf_rotate64` / `bpf_select64` 放在 vmlinux BTF 可见域
- 等 REJIT attr 有 `fd_array` 后，再支持 module kfunc

## 3.3 `KF_INLINE_EMIT` 对用户态意味着什么

对 daemon 来说，`KF_INLINE_EMIT` 不改变 bytecode 编码。

用户态仍然只需要发普通 kfunc call:

- `src_reg = BPF_PSEUDO_KFUNC_CALL`
- `imm = BTF ID`
- `off = 0 或 module slot`

是否 inline 展开，是 verifier/JIT 侧对这个 kfunc 的实现选择，不是 userspace 编码选择。

---

## 4. daemon 架构设计

## 4.1 语言建议

你给的目录结构是 `.c`，但**实现上更推荐 C++ 而不是纯 C**。

原因:

- scanner 现有可复用部分是 C++
- 如果 daemon 强行写纯 C，就得再包一层 C ABI shim

推荐折中:

- 模块划分保持你给的结构
- 但文件后缀用 `.cc/.cpp`

如果必须纯 C，则额外增加一个 `scanner_bridge.cpp`，向 daemon 暴露 `extern "C"` 包装。

## 4.2 推荐模块划分

| 模块 | 输入 | 输出 | 依赖 | 代码量估计 |
|---|---|---|---|---|
| `discovery.cc` | 无或 prog_id filter | live prog 列表，`prog_fd`，`bpf_prog_info`，`orig_insns` | `BPF_PROG_GET_NEXT_ID`、`BPF_PROG_GET_FD_BY_ID`、`BPF_OBJ_GET_INFO_BY_FD` | 400-600 LoC |
| `analyzer.cc` | 原始 insn 流，prog info | `RewritePlan` | scanner matcher core，CFG/liveness 分析 | 900-1300 LoC |
| `rewriter.cc` | `RewritePlan`，原始 insn 流，kfunc resolver | 新 insn 流，optional `fd_array`/BTF metadata | BTF API，branch/call patching | 1400-2000 LoC |
| `profiler.cc` | prog ids/fds | hotness、`run_cnt`/`run_time_ns`、perf 统计 | `BPF_OBJ_GET_INFO_BY_FD`，`BPF_ENABLE_STATS`，perf_event | 300-500 LoC |
| `policy.cc` | analyzer/profiler 输出，配置 | `apply/skip/rollback` 决策 | 无特殊 syscall | 250-450 LoC |
| `rejit.cc` | prog fd，新程序镜像 | syscall result，latency，verifier log | `BPF_PROG_REJIT` | 250-400 LoC |
| `main.cc` | CLI/config | daemon 主循环，状态持久化 | epoll/timerfd/signal | 250-400 LoC |

不含测试时，daemon 主体大致 **3.8k-5.6k LoC**。

如果把 scanner 的 v2 rewrite 输出层一起算进去，再加 **1.2k-1.8k LoC** 比较合理。

## 4.3 每个模块的职责

### `discovery`

职责:

- 周期性枚举 live programs
- 为每个 prog 拉取:
  - `id`
  - `name`
  - `type`
  - `run_cnt/run_time_ns`
  - `orig_prog_len/orig_prog_insns`
  - `nr_map_ids`
  - `btf_id`
  - `nr_func_info/nr_line_info`

说明:

- 当前树里实际上已经能通过 `bpf_prog_info.orig_prog_insns` 拿到 original insns
- 所以 userspace helper 可以先把它抽象成 `get_original_prog(fd)`，底层继续用 `BPF_OBJ_GET_INFO_BY_FD`

### `analyzer`

职责:

- 解析 original bytecode
- 跑 pattern matching
- 构建 CFG/liveness
- 输出“哪些 site 可安全改、哪些不能改、为什么”

建议的 skip 条件:

- site interior 有外部 branch target
- site 跨 subprog boundary
- kfunc rewrite 需要的 caller-saved 寄存器 spill 不可满足
- 当前原型内核不支持的程序类型:
  - maps
  - BTF
  - kfunc
  - subprog-heavy

### `rewriter`

职责:

- 把 `RewritePlan` 变成新的整段程序
- 处理:
  - `N -> M` 替换
  - branch retarget
  - `BPF_PSEUDO_CALL` retarget
  - kfunc 编码
  - optional `func_info/line_info` 修复

这是整个 daemon 里工程风险最高的模块。

### `profiler`

职责:

- 记录哪些 prog 值得优化
- 采样:
  - `run_cnt`
  - `run_time_ns`
  - 可选 perf counters

建议 first version 不做复杂 profile-guided transform，只做:

- 热度阈值
- apply 之后的 before/after 退化检测

### `policy`

职责:

- 决定什么时候 apply / rollback

建议 first version 规则:

- `run_cnt` 增量超过阈值才尝试 apply
- apply 后若 `exec_ns` 退化超过阈值则 rollback
- rollback 直接用 cached original bytecode 再调一次 `BPF_PROG_REJIT`

### `rejit`

职责:

- 包装 syscall
- 管理 verifier log buffer
- 统计 apply latency

这里建议一开始就把接口设计成:

```c
int rejit_apply(int prog_fd,
                const struct rejit_image *img,
                struct rejit_result *out);
```

不要把 syscall 细节散落到别的模块里。

---

## 5. benchmark 框架适配

## 5.1 `micro_exec` 需要新增什么子命令

建议新增:

- **`run-rejit`**

不要把 v2 继续塞进 `run-kernel` 的 `--recompile-*` 参数体系，原因有 3 个:

1. 现有 `run-kernel` 的 recompile 语义明显是 policy/blob 模型
2. v2 输入是 original bytecode + rewrite plan，不是 policy blob
3. v2 需要新的输出字段:
   - `orig_insn_cnt`
   - `new_insn_cnt`
   - `rejit_apply_ns`
   - `verifier_log`
   - `rewrite_families`
   - `rollback_applied`

推荐实现方式:

- 把 `run_kernel()` 里通用的:
  - object load
  - map prepare
  - `BPF_PROG_TEST_RUN`
  - paired stock/post measure
  抽成共享 helper
- 再分别挂:
  - `apply_recompile_policy()` for v1
  - `apply_rejit_image()` for v2

可复用比例估计:

- `run_kernel()` 主体逻辑可复用 **70% 左右**

## 5.2 `run-rejit` 的建议输出

建议 JSON 在现有 `sample_result` 上新增 `rejit` 字段，而不是复用 `recompile` 字段:

```json
"rejit": {
  "requested": true,
  "applied": true,
  "mode": "original-bytecode-rewrite",
  "families": ["wide", "rotate"],
  "orig_insn_cnt": 128,
  "new_insn_cnt": 119,
  "apply_ns": 123456,
  "error": ""
}
```

同时:

- `phases_ns` 新增 `rejit_apply_ns`
- phase 用:
  - `stock`
  - `rejit`

## 5.3 `micro/driver.py` 需要怎么改

建议改动:

1. `micro/config/micro_pure_jit.yaml` 新增 runtime:
   - `kernel-rejit`
2. `runner/libs/commands.py::build_micro_benchmark_command()` 支持:
   - `runtime_mode == "kernel-rejit"` -> `micro_exec run-rejit`
3. `micro/driver.py` 的 runtime 过滤与显示逻辑接受新 mode
4. `runner/libs/results.py::collapse_command_samples()` 不能只认 `stock/recompile`

更稳的做法是:

- 不再“collapse 丢掉 before sample”
- 直接把 paired 样本保留下来
- 聚合层显式计算:
  - `before_exec_ns`
  - `after_exec_ns`
  - `delta`
  - `rejit_apply_ns`

否则 v2 最重要的 paired 信息会在解析层被提前丢掉。

## 5.4 和现有 recompile mode 的关系

建议不要覆盖旧 mode，而是并存:

- `kernel-recompile-v1` 或保留 `kernel-recompile`
- 新增 `kernel-rejit`

原因:

- v1 是“scanner 选 site + kernel  native rewrite”
- v2 是“userspace 生成整段新 BPF 程序 + kernel re-verify/re-JIT”

这两者不是同一种机制，覆盖同名 runtime 会把历史数据和新数据混在一起。

## 5.5 `corpus/driver.py` 怎么改

当前 `corpus` 有两条 v1 路径:

- `run_micro_exec_sample()`
- `run_compile_only_loadall_sample()` + `apply_recompile_v5()`

v2 迁移建议:

1. 把 runtime `kernel-recompile-v5` 改成 `kernel-rejit`
2. 对 `micro_exec` 路径:
   - 直接调用 `run-rejit`
3. 对 `bpftool loadall` / live attach 路径:
   - 用新 daemon CLI 或 `runner.libs.rejit.py`
   - 不再 shell out 到 `scanner enumerate --recompile`

建议新增共享层:

- `runner/libs/rejit.py`

职责与当前 `runner/libs/recompile.py` 类似，但面向:

- `scan_programs()` -> `analyze_programs()`
- `apply_recompile()` -> `apply_rejit()`

## 5.6 e2e 需要怎么改

`e2e/cases/*/case.py` 现在统一依赖:

- `runner.libs.recompile.scan_programs()`
- `runner.libs.recompile.apply_recompile()`

所以迁移策略非常明确:

- 保留调用点不变
- 把底层换成 `runner.libs.rejit`

这样 tracee/tetragon/scx/bpftrace/katran 的 orchestrator 不需要整体重写。

## 5.7 benchmark 侧代码量估计

如果按“新增 v2 路径，不破坏 v1”来做，benchmark 侧大致是下面这个量级:

| 区域 | 主要改动 | 代码量估计 |
|---|---|---|
| `runner/src/kernel_runner.cpp` | 抽公共测量路径，新增 `apply_rejit_image()` / `run-rejit` | 500-800 LoC |
| `runner/src/main.cpp` + `runner/src/common.cpp` + `runner/include/micro_exec.hpp` | 新子命令、新 CLI 参数、新 JSON schema | 150-300 LoC |
| `runner/libs/commands.py` + `runner/libs/results.py` | 新 runtime 命令构造、paired sample 解析 | 120-220 LoC |
| `micro/config/micro_pure_jit.yaml` + `micro/driver.py` | 新 runtime、结果聚合、展示 | 120-220 LoC |
| `runner/libs/rejit.py` | 替代现有 `recompile.py` 的 live apply 层 | 350-650 LoC |
| `corpus/driver.py` | runtime 切换、loadall/live apply 改 daemon/rejit | 180-350 LoC |
| `e2e/cases/*/case.py` | import 与结果字段迁移 | 100-250 LoC |

合计大致 **1.5k-2.8k LoC**，其中真正有技术风险的仍然是:

- `run-rejit` 的 C++ 侧实现
- `runner.libs.rejit.py`
- paired result schema 迁移

---

## 6. 完整新 bytecode 生成时的关键问题

## 6.1 `GET_ORIGINAL` 拿到的 map 引用还有效吗

**不能直接假设有效。**

这是本调研里最重要的 userspace 问题之一。

代码事实:

- `bpf_prog_load()` 在 load 很早的阶段把 `prog->insns` 拷贝到 `prog->aux->orig_insns`
- `BPF_OBJ_GET_INFO_BY_FD` 导出 `orig_prog_insns` 时直接把这份 `orig_insns` 抄给用户态
- libbpf 在 program load 前会把 map relocation 改成:
  - `BPF_PSEUDO_MAP_FD + map->fd`
  - 或 `BPF_PSEUDO_MAP_VALUE + map->fd`

**推论（基于源码推断）**:

- 如果原程序是由 libbpf/autocreate map 加载的，那么 `orig_insns` 里保存的很可能是“当时 loader 进程里的 map fd 数字”
- 这些 fd 对后来的 daemon 来说通常已经失效，不能直接重放

所以答案是:

- **当前实现下，`orig_prog_insns` 不是跨进程可重放的 canonical IR**
- 它更像“当时 load 输入的保真拷贝”

## 6.2 那 REJIT 该怎么处理 map 引用

最终 v2 需要在 `BPF_PROG_REJIT` attr 里补上至少与 `BPF_PROG_LOAD` 同等级的元数据通道:

- `fd_array`
- `fd_array_cnt`

这样用户态就可以把 rewritten 程序中的:

- `BPF_PSEUDO_MAP_IDX`
- `BPF_PSEUDO_MAP_IDX_VALUE`
- module kfunc 的 BTF fd

一起交给 verifier。

否则:

- map 引用无法可靠重绑定
- module kfunc 也无法可靠重绑定

## 6.3 新 bytecode 需要带 BTF / `func_info` / `line_info` 吗

### 6.3.1 对很多简单程序: 不一定需要

内核 verifier 的 `check_btf_info_early()` / `check_btf_info()` 都有一个早退路径:

- 如果 `func_info_cnt == 0 && line_info_cnt == 0`
- 则直接返回 0

因此:

- **普通简单程序在不带 program BTF / `func_info` / `line_info` 时仍可能通过 verify**

### 6.3.2 什么时候必须带

如果 rewritten 程序依赖这些能力，则必须带:

- callback / `BPF_PSEUDO_FUNC`
- 某些本地 BTF 类型信息
- 需要保留精确 subprog/source mapping 的场景

而且一旦 `N -> M` 重写发生:

- 原有 `func_info.insn_off`
- 原有 `line_info.insn_off`

都可能失效，必须:

- 要么重算并重新提交
- 要么明确丢弃

### 6.3.3 当前 REJIT 原型的限制

当前树里的 `bpf_prog_rejit_supported()` 直接拒绝:

- `aux->used_map_cnt`
- `aux->used_btf_cnt`
- `aux->kfunc_tab`
- `aux->btf`
- `aux->func_info`
- `aux->linfo`

所以现实是:

- **当前内核原型还不能处理你想要的完整 v2 universe**
- 这不是 daemon 端 workaround 能彻底补掉的

## 6.4 当前内核树与目标 v2 之间的差距

当前 `BPF_PROG_REJIT` 原型与目标架构相比，至少差 4 点:

1. 只支持同长度替换
2. 不支持 maps/BTF/kfunc universe
3. 不支持 `fd_array`
4. 不支持 `prog_btf_fd` / `func_info` / `line_info`

因此最终 v2 UAPI 至少应扩成类似:

```c
struct bpf_prog_rejit_attr_v2 {
  __u32 prog_fd;
  __u32 insn_cnt;
  __aligned_u64 insns;

  __u32 prog_btf_fd;
  __u32 func_info_rec_size;
  __aligned_u64 func_info;
  __u32 func_info_cnt;
  __u32 line_info_rec_size;
  __aligned_u64 line_info;
  __u32 line_info_cnt;

  __aligned_u64 fd_array;
  __u32 fd_array_cnt;

  __u32 log_level;
  __u32 log_size;
  __aligned_u64 log_buf;
};
```

如果只想先做 userspace 原型，建议 first version 明确限制:

- 只做 no-map/no-BTF/no-kfunc 微基准
- 或只做 wide-load 这类不引入额外 extern universe 的 rewrite

---

## 7. 与 v1 benchmark 数据的关系

## 7.1 62 个 micro benchmark 能复用多少

**工作负载本身几乎 62/62 都能复用。**

原因:

- 这些 benchmark 测的是程序形态和执行特征，不依赖 v1 policy blob 机制本身
- `kernel` baseline 和 `llvmbpf` baseline 仍然有意义

但要区分“工作负载可复用”和“结果可复用”:

- **benchmark workload**: 基本都能复用
- **v1 optimized result**: 不能直接当 v2 结果复用

因为 v1/v2 机制不同:

- v1: kernel 内部 native rewrite
- v2: userspace full-bytecode rewrite + reverify + rejit

## 7.2 policy 文件能复用多少

现有 micro/corpus policy 文件只能 **部分复用**。

原因:

- 现有 policy 是围绕 xlated/live manifest 的 site identity 设计的
- v2 更自然的 site identity 应该建立在 original bytecode 上

建议:

- v1 policy 文件只保留为“family allowlist / experiment selection”参考
- 不要强依赖现有 site 编号直接迁移

## 7.3 新架构下应该新增什么 benchmark

至少新增 6 类:

1. **rejit latency vs insn count**
   - 程序长度从小到大
2. **rejit latency vs site count**
   - 单 site、多 site、密集 site
3. **kfunc rewrite 盈亏点**
   - rotate/select 在有无 spill 时的差异
4. **jump retarget 压力**
   - 分支密集、subprog 密集
5. **map/BTF 重绑定**
   - 验证未来扩展后的 `fd_array` 路径
6. **security insertion**
   - bounds/spec barrier 的纯开销

## 7.4 `llvmbpf` 对比还有没有意义

**有意义，但意义变了。**

保留 `llvmbpf` 的理由:

- 它仍然提供一个 userspace whole-program JIT 的 steady-state 参考点
- 对 steady-state `exec_ns` 比较仍有价值

但不应拿它比较:

- live same-image swap latency
- verifier/rejit 开销
- attach continuity

换句话说:

- `llvmbpf` 仍是“执行上界/替代实现”对照
- 不是“在线热替换机制”对照

---

## 8. 推荐落地顺序

### Phase A: 先打通 userspace rewrite pipeline

目标:

- 基于 `orig_prog_insns`
- 只做 Tier 1 rewrites
- 新增 `run-rejit`
- 先在 simple micro benchmarks 上跑通 paired measurement

这一步主要改:

- scanner matcher 输出
- rewriter
- `micro_exec run-rejit`
- `micro/driver.py`

### Phase B: 扩 REJIT UAPI

目标:

- 支持 `N != M`
- 支持 `fd_array`
- 支持 optional BTF / `func_info` / `line_info`

这一步之后，rotate/select/module kfunc/map-heavy 程序才真正可落地。

### Phase C: daemon 化与 live workload 接入

目标:

- 新 `runner/libs/rejit.py`
- `corpus` / `e2e` 统一迁移
- profiler/policy/rollback 全部接上

---

## 9. 最终建议

最小可行路线不是“一次性重写 scanner + daemon + runner + corpus + e2e”，而是:

1. **保留 scanner matcher 核心，先把输出改成 `RewriteSite`**
2. **先做 Tier 1 rewrite + `micro_exec run-rejit`**
3. **把 `kernel-rejit` 加进 micro suite**
4. **确认 paired measurement、`rejit_apply_ns`、before/after 统计都稳定**
5. **再扩内核 UAPI 去支持 `fd_array`、BTF metadata 和 `N != M`**
6. **最后替换 `runner/libs/recompile.py`，迁移 corpus/e2e**

如果按这条路走:

- scanner 现有核心不会被浪费
- benchmark 框架也不用推倒重来
- 同时能尽早暴露真正的接口缺口:
  - maps
  - module kfunc
  - BTF
  - `N != M`

这比先写一个“表面上完整、实际上被当前 REJIT 原型卡死”的 daemon 更稳。
