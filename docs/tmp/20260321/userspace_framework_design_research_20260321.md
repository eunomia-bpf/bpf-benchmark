# 新 kinsn 架构下用户态 framework 设计调研

日期：2026-03-21  
仓库：`/home/yunwei37/workspace/bpf-benchmark`  
调研范围：`vendor/linux-framework/`、`vendor/libbpf/`、`scanner/`、`runner/`、`micro/`、`corpus/`、`e2e/`

## 0. 核心结论

### 0.1 结论先行

1. **live xlated bytecode 不能作为通用输入直接重新 `BPF_PROG_LOAD`。**
   原因不是单点，而是 verifier/JIT 链路里存在多类不可逆或不可靠逆的变换：ctx access 重写、helper/kfunc/map fixup、dead code 改写或删除、constant blinding、部分 helper/kfunc 内联、多函数 JIT 地址修补。当前树里的真实链路是 `bpf_prog_load()` -> `bpf_check()` -> `convert_ctx_accesses()` -> `do_misc_fixups()` -> `fixup_call_args()` -> `convert_pseudo_ld_imm64()` -> `bpf_prog_select_runtime()`，并不存在单独的 `fixup_bpf_calls()` 函数；对应职责分散在多个阶段里（`vendor/linux-framework/kernel/bpf/syscall.c:2872-3127`, `vendor/linux-framework/kernel/bpf/verifier.c:25912-26164`）。

2. **三条路径里，短期唯一工程上可落地的是路径 A：从原始 `.bpf.o` 重写。**
   但它有一个前提：**必须拿得到原始 ELF/BTF/relo/map 定义**。内核不会从 live program 反向告诉你“它来自哪个 `.bpf.o`”；`fdinfo`、`BPF_OBJ_GET_INFO_BY_FD`、bpffs pin 都不给这个信息（`vendor/linux-framework/kernel/bpf/syscall.c:2488-2515`, `5000-5155`, `5424-5445`; `vendor/linux-framework/include/uapi/linux/bpf.h:6753-6793`; `vendor/linux-framework/kernel/bpf/inode.c:319-380`）。

3. **路径 B（加载时拦截）不适合作为“用户态 daemon 自动重写”的主方案。**
   `security_bpf_prog_load()` / `bpf_prog_load` LSM hook 确实能在 verifier 之前看到 `struct bpf_prog *prog` 和原始 `union bpf_attr *attr`，但它本质是内核同步 allow/deny hook，不是“把原始 bytecode 交给用户态，等用户态改完再继续当前 syscall”的接口（`vendor/linux-framework/security/security.c:5236-5260`, `vendor/linux-framework/include/linux/lsm_hook_defs.h:430-445`, `vendor/linux-framework/kernel/bpf/syscall.c:3085`）。seccomp 也不解决这个问题，它只能看到 syscall 编号和 6 个参数值，指针参数存在明确 TOCTOU 警告（`vendor/linux-framework/include/uapi/linux/seccomp.h:54-116`, `vendor/linux-framework/kernel/seccomp.c:1163-1257`）。

4. **路径 C（新内核接口）是长期最干净的解，但必须显式保存 pre-fixup eBPF 镜像。**
   当前 `struct bpf_prog` 常驻的是 verifier/JIT 要消费的 `insnsi`；`orig_prog` 的类型是 `struct sock_fprog_kern *`，服务的是 classic BPF 兼容路径，不是 eBPF 原始副本（`vendor/linux-framework/include/linux/bpf.h:1807-1844`, `vendor/linux-framework/net/core/filter.c:1158-1188`, `1399-1455`）。如果要做 `BPF_PROG_CLONE` / `BPF_PROG_REWRITE`，内核需要新增保存 pre-xlated eBPF insns、BTF.ext、relocation 元数据的结构。

5. **relocation 是路径 A 的最大工程成本。**
   如果允许变长替换，至少要同步维护：
   - relocation site 的 `insn_idx`
   - 所有 BPF jump/call 的相对偏移
   - subprogram 边界和 `BPF_PSEUDO_CALL`
   - `.BTF.ext` 中 `func_info` / `line_info` 的 `insn_off`
   - CO-RE relocation 对应的指令位点
   
   libbpf 内部正是这么做的（`vendor/libbpf/src/libbpf.c:6356-6821`）。**建议 Phase 1 只做等长替换；Phase 2 再引入完整 relocator。**

6. **建议的总体路线：**
   - **近中期**：路径 A + “origin manifest” + 等长 rewrite 子集 + map reuse + 能原子替换的 attach 面优先
   - **长期**：推动路径 C，新内核接口直接暴露 clone/rewrite 入口

### 0.2 三条路径的明确判定

| 路径 | 结论 | 原因 |
| --- | --- | --- |
| A. 从原始 `.bpf.o` 重写 | **可行，且是推荐短期方案** | 不需要逆向 xlated；能复用 libbpf 加载、map reuse、link update；难点集中在 origin 获取、relocation、attach 覆盖面 |
| B. 加载时拦截 | **不建议，基本不成立为“纯用户态 daemon”方案** | LSM/seccomp 都不能把当前 `BPF_PROG_LOAD` 暂停并安全交给用户态改写后续跑；能做的只是 allow/deny 或外部旁路 |
| C. 新内核接口 | **长期最佳方案，但需要内核改动** | 当前内核不保存 eBPF pre-fixup 镜像；要么新增 clone 对象，要么新增 rewrite syscall |

## 1. 现有用户态栈现状

### 1.1 scanner 当前做什么

- `scanner` 既能读 ELF，也能读 live xlated bytecode，再跑 pattern matching。读取 live program 的入口是 `BPF_PROG_GET_NEXT_ID` + `BPF_PROG_GET_FD_BY_ID` + `BPF_OBJ_GET_INFO_BY_FD`，随后把 `xlated_prog_insns` 拉回用户态（`scanner/src/cli.cpp:400-434`, `481-504`, `650-730`）。
- 当前 scanner 的产物是 **policy blob**，服务现有 `BPF_PROG_JIT_RECOMPILE` 路径，而不是改写 `.bpf.o`。
- pattern engine 主要在 `scanner/src/pattern_v5.cpp`，这是未来 rewriter 最直接可复用的部分。

### 1.2 runner / benchmark 当前做什么

- `micro_exec` 当前支持 `run-llvmbpf` 和 `run-kernel` 两条执行路径（`runner/src/main.cpp:22`, `CLAUDE.md:107-109`）。
- `run-kernel` 路径已经有完整的 `BPF_PROG_TEST_RUN` 测量和 phase timing 输出，包含 `object_open_ns`、`object_load_ns`、`recompile_apply_ns`、`prog_run_wall_ns` 等（`runner/src/kernel_runner.cpp:1163-1780`）。
- 现有 benchmark 栈已经支持 same-image paired measurement：先测 `stock`，再在同一 image 上 apply/recompile，再测 `recompile`，结果由 `runner/libs/results.py:152-171` 折叠。
- `runner/src/elf_program_loader.cpp:207-550`, `606-730` 已经实现了一套“读 ELF + patch map/subprog relocation”的轻量 loader，这会是未来 relocator 的直接种子代码。

## 2. 为什么 xlated bytecode 不能直接重载

## 2.1 内核真实处理链

`BPF_PROG_LOAD` 进入 `bpf_prog_load()` 后，先把用户态原始 insns 复制到 `prog->insnsi`，再跑 LSM、verifier 和 runtime/JIT 选择（`vendor/linux-framework/kernel/bpf/syscall.c:3020-3023`, `3085-3094`）。

`bpf_check()` 在当前树里的关键顺序是（`vendor/linux-framework/kernel/bpf/verifier.c:25912-26164`）：

1. `add_subprog_and_kfunc()`
2. `resolve_pseudo_ldimm64()`
3. `check_cfg()`
4. `do_check_main()` / `do_check_subprogs()`
5. dead code hard-wire / sanitize / remove
6. `convert_ctx_accesses()`
7. `do_misc_fixups()`
8. `opt_subreg_zext_lo32_rnd_hi32()`
9. `fixup_call_args()`
10. `convert_pseudo_ld_imm64()`

注意：这份树里**没有单独的 `fixup_bpf_calls()`**；helper/kfunc/subprog/map fixup 分散在上面的几个阶段。

## 2.2 `convert_ctx_accesses()` 做了什么

### 2.2.1 哪些 prog type 会触发

触发条件不是“prog type 名字固定表”，而是对应 `bpf_verifier_ops` 提供了 `convert_ctx_access` 回调。当前树里至少包括：

- `socket_filter` / `sched_cls` / `sched_act` / `xdp` / `cgroup_skb`
- `lwt_in` / `lwt_out` / `lwt_xmit` / `lwt_seg6local`
- `cgroup_sock` / `cgroup_sock_addr` / `sock_ops`
- `sk_skb` / `sk_msg` / `flow_dissector` / `sk_reuseport` / `sk_lookup`
- `cgroup_sysctl` / `cgroup_sockopt`
- `perf_event`

源码位置见：

- `vendor/linux-framework/net/core/filter.c:11206-11343`, `11679-11895`
- `vendor/linux-framework/kernel/bpf/cgroup.c:2478-2482`, `2701-2705`
- `vendor/linux-framework/kernel/trace/bpf_trace.c:1907-1911`

### 2.2.2 转换形态

`convert_ctx_accesses()` 本身会：

- 根据寄存器类型区分 `PTR_TO_CTX`、`PTR_TO_SOCKET`、`PTR_TO_TCP_SOCK`、`PTR_TO_XDP_SOCK`、`PTR_TO_BTF_ID`、`PTR_TO_ARENA`
- 调具体 callback 生成替代指令序列
- 通过 `bpf_patch_insn_data()` 插入/删除指令并更新跳转、subprog 起点、poke desc（`vendor/linux-framework/kernel/bpf/verifier.c:22480-22778`, `21927-22047`, `22048-22140`）
- 对窄字段 load 做 widen + shift/mask（`vendor/linux-framework/kernel/bpf/verifier.c:22737-22758`）
- 在需要时插入 `BPF_ST_NOSPEC`

几个典型例子：

- `__sk_buff.ifindex` 被展开成 “load `skb->dev` -> null check -> load `dev->ifindex`” 的多指令序列（`vendor/linux-framework/net/core/filter.c:9797-9805`）
- `__sk_buff.remote_port` 会走 `skb->sk` / `skc_dport` 路径，并根据字节序补 shift（`vendor/linux-framework/net/core/filter.c:10032-10045`）
- `xdp_md.ingress_ifindex` 被展开成 “load `xdp_buff->rxq` -> `xdp_rxq_info->dev` -> `net_device.ifindex`” （`vendor/linux-framework/net/core/filter.c:10341-10350`）

### 2.2.3 能否逆向还原

**一般不能可靠逆向。**

原因：

- 一个原始 ctx load/store 可能变成多条指令
- 展开依赖目标 kernel 的结构体布局和字节序
- verifier 可能插入额外临时寄存器搬运、null check、`nospec`
- 变长 patch 会改变后续指令索引和跳转

所以 live xlated 里看到的是“目标内核语义化后的展开结果”，不是原始源码层面的 ctx 访问。

## 2.3 helper / kfunc / subprogram call fixup

### 2.3.1 helper call

原始 helper call 在 verifier 检查阶段仍然用 `imm = func_id` 表示；真正 fixup 在 `do_misc_fixups()` 中完成。关键逻辑是：

- 通过 `env->ops->get_func_proto(insn->imm, env->prog)` 找到 helper 原型
- 把 `insn->imm` 改成 `fn->func - __bpf_call_base`
- 对某些 map helper 改写成 map-specific op
- 对某些 helper 直接内联成指令序列

源码：`vendor/linux-framework/kernel/bpf/verifier.c:23696-24231`

这意味着 live xlated 里的 helper call `imm` 已经不是 UAPI `enum bpf_func_id`。

### 2.3.2 kfunc call

用户态 libbpf 对 kfunc relocation 的编码是：

- `src_reg = BPF_PSEUDO_KFUNC_CALL`
- `imm = kernel_btf_id`
- `off = btf_fd_idx`

见 `vendor/libbpf/src/libbpf.c:6420-6429`。

内核 verifier 再做两步：

- `add_kfunc_call()` / `set_kfunc_desc_imm()` 解析 BTF 元数据并用 `kallsyms_lookup_name()` 找内核地址（`vendor/linux-framework/kernel/bpf/verifier.c:3432-3575`）
- `fixup_kfunc_call()` 在非 far-call JIT 场景下把 `imm` 改成 `BPF_CALL_IMM(desc->addr)`，必要时还可能展开专门序列（`vendor/linux-framework/kernel/bpf/verifier.c:23184-23214`）

所以 live xlated 里的 kfunc call 也不是原始 `kernel_btf_id` 形式。

### 2.3.3 subprogram call

`jit_subprogs()` 会在 JIT 阶段临时把 bpf-to-bpf call 改成内部子程序索引和地址形式，JIT 完成后再恢复解释器视图，但整个过程中 `imm`/`off` 都不是稳定的“原始 ELF 相对目标”（`vendor/linux-framework/kernel/bpf/verifier.c:22780-23063`）。

## 2.4 map 引用 fixup

用户态 `.bpf.o` 里的 map/global data 引用，经过 libbpf 和 verifier 两轮变换：

1. libbpf 先把 relocation site 改成 `BPF_PSEUDO_MAP_FD` / `BPF_PSEUDO_MAP_VALUE` 等形式（`vendor/libbpf/src/libbpf.c:6366-6396`）
2. verifier 的 `resolve_pseudo_ldimm64()` 再把：
   - `BPF_PSEUDO_MAP_FD` / `BPF_PSEUDO_MAP_IDX` 变成 `map` 内核指针
   - `BPF_PSEUDO_MAP_VALUE` / `BPF_PSEUDO_MAP_IDX_VALUE` 变成 direct value 地址
   
   核心写回发生在 `insn[0].imm` / `insn[1].imm` 上（`vendor/linux-framework/kernel/bpf/verifier.c:21756-21890`，特别是 `21840`, `21870-21871`）。
3. `convert_pseudo_ld_imm64()` 再把 `src_reg` 清零，使其不再保留 pseudo 类型信息（`vendor/linux-framework/kernel/bpf/verifier.c:21907-21919`）

所以 live xlated 里的 `ldimm64` 已经不携带用户态 map fd，不能直接拿来 reload。

## 2.5 dead code elimination / sanitization

verifier 在通过主检查后还会处理 dead code：

- `sanitize_dead_code()` 在某些路径把 unreachable 指令改成 trap `JA -1`（`vendor/linux-framework/kernel/bpf/verifier.c:22266-22280`）
- `opt_hard_wire_dead_code_branches()` / `opt_remove_dead_code()` 在 privileged 路径可能真正删掉死代码（`vendor/linux-framework/kernel/bpf/verifier.c:22322-22344`）

这会改变 CFG 和指令编号，进一步破坏“xlated == 原始输入”的假设。

## 2.6 constant blinding

### 2.6.1 何时启用

`bpf_prog_alloc_no_stats()` 在程序创建时就记录：

- `jit_requested = ebpf_jit_enabled()`
- `blinding_requested = bpf_jit_blinding_enabled(prog)`

见 `vendor/linux-framework/kernel/bpf/core.c:101-130`。

`bpf_jit_blinding_enabled()` 的条件是（`vendor/linux-framework/include/linux/filter.h:1347-1363`）：

- JIT 已启用
- `prog->jit_requested` 为真
- `bpf_jit_harden` 非零
- 如果 `bpf_jit_harden == 1`，带 `CAP_BPF`/token 能力的 loader 可豁免

### 2.6.2 做了什么

`bpf_jit_blind_insn()` 会把常量 ALU/jump/store/ldimm64 指令改写成带随机掩码和 AX 临时寄存器的序列（`vendor/linux-framework/kernel/bpf/core.c:1374-1508`）；`bpf_jit_blind_constants()` 会克隆整段程序并逐条改写（`vendor/linux-framework/kernel/bpf/core.c:1569-1634`）。

### 2.6.3 能否逆向

**不能可靠逆向。**

blinding 用随机 `imm_rnd`，而且指令长度会变化。没有额外 side state 的情况下，无法从 blinded xlated 唯一恢复原始常量。

## 2.7 直接 reload 结论

**结论：live xlated bytecode 不能作为通用可重载格式重新 `BPF_PROG_LOAD`。**

至少以下几类变换在当前树里不可逆或不可靠逆：

- ctx access rewrite
- helper imm -> helper address / map op / inline sequence
- kfunc id -> address-relative call
- map fd/value relocation -> kernel pointer/direct value address
- dead code trap/delete
- constant blinding

此外，`BPF_OBJ_GET_INFO_BY_FD` 对 xlated/jited dump 本身还受权限约束：非 `bpf_capable()` 时，`jited_prog_len` / `xlated_prog_len` 等字段被清零（`vendor/linux-framework/kernel/bpf/syscall.c:5055-5063`）。

## 3. 路径 A：从原始 `.bpf.o` 重写

## 3.1 结论

**可行，而且是推荐的短期路线。**  
但必须把问题收缩为：

- 有 origin `.bpf.o`
- rewriter 初期只支持受控的 rewrite 子集
- 优先覆盖可原子替换的 attach 面

## 3.2 原始 `.bpf.o` 怎么拿

### 3.2.1 内核不会告诉你原始 ELF 路径

live 枚举路径只有：

- `BPF_PROG_GET_NEXT_ID`（`vendor/linux-framework/kernel/bpf/syscall.c:6249-6252`）
- `BPF_PROG_GET_FD_BY_ID`
- `BPF_OBJ_GET_INFO_BY_FD`

`struct bpf_prog_info` 暴露的是 type/id/tag/load_time/map_ids/name/ifindex/BTF/func_info/line_info/run_time_ns/run_cnt 等（`vendor/linux-framework/include/uapi/linux/bpf.h:6753-6793`），**没有 ELF path 字段**。

`/proc/<pid>/fdinfo` 对 prog 只打印：

- `prog_type`
- `prog_jited`
- `prog_tag`
- `memlock`
- `prog_id`
- `run_time_ns`
- `run_cnt`
- `recursion_misses`
- `verified_insns`

见 `vendor/linux-framework/kernel/bpf/syscall.c:2488-2515`。  
而 BPF fd 自身是 `anon_inode:bpf-prog` / `anon_inode:bpf-map` / `anon_inode:bpf-link`（`vendor/linux-framework/kernel/bpf/syscall.c:1190`, `2535`, `3480`），因此 `/proc/<pid>/fd` 也不会给出 `.bpf.o` 路径。

### 3.2.2 bpffs pin 也不是原始 ELF

bpffs pin 保存的是 BPF object 本身，不是源 ELF。`bpf_mkprog()` / `bpf_mkmap()` / `bpf_mklink()` 只是把内核对象挂到 bpffs inode，prog/link pin 的 open 甚至直接返回 `-EIO`（`vendor/linux-framework/kernel/bpf/inode.c:319-380`）。

### 3.2.3 对已知系统的现实情况

- **Cilium**
  - 官方默认路径常量显示：
    - `LibraryPath = "/var/lib/cilium"`
    - `BpfDir = "bpf"`
    - `RuntimePath = "/var/run/cilium"`
    - `StateDir = "state"`
    - `TemplatesDir = "templates"`
    
    即常见对象目录会落在 `/var/lib/cilium/bpf` 和 `/var/run/cilium/state/templates`（官方 `pkg/defaults` 文档，`https://pkg.go.dev/github.com/cilium/cilium/pkg/defaults`，页面行 `212-233`、`220-230`）。
  - 官方命令 `cilium-dbg bpf sha list` 明确是 “List BPF template objects”，说明运行期还有 template object 管理层，而不是由内核保存 ELF 来源（`https://docs.cilium.io/en/latest/cmdref/cilium-dbg_bpf_sha_list/`，`278-281`）。

- **Tracee**
  - 官方 non-CO-RE 构建文档明确使用 `TRACEE_BPF_FILE=/tmp/tracee/tracee.bpf....o ./dist/tracee-ebpf`，说明对象文件可能由用户显式指定，也可能是临时路径（`https://aquasecurity.github.io/tracee/v0.11/contributing/building/nocore-ebpf/`）。
  - 本仓库的 e2e 路径当前使用的是 `corpus/build/tracee/tracee.bpf.o`（`e2e/run.py:75`, `e2e/README.md:34`），这是 benchmark 自己维护的副本，不是内核可反查的路径。

### 3.2.4 工程结论

路径 A **必须引入 origin registry**。建议 daemon 依赖以下之一：

1. **loader cooperation**
   loader 在加载时写 sidecar manifest，记录：
   - `prog_tag`
   - `prog_name`
   - `expected_attach_type`
   - source ELF absolute path
   - build-id / git sha
   - map pin paths
   - attach handle / link pin path

2. **bpffs sidecar**
   在 pin 目录同时写 `program.meta.json`

3. **known-loader adapters**
   为 Cilium、Tracee、Tetragon 等做专用 resolver

如果 origin ELF 不可得，则**禁止 rewrite**，退回 scanner-only / profiler-only 模式。

## 3.3 map 复用机制

### 3.3.1 `bpf_map__reuse_fd()` 实际语义

`bpf_map__reuse_fd()` 会：

- 读取旧 map info
- `F_DUPFD_CLOEXEC` 复制 fd
- 把 type/key/value/max_entries/map_flags/BTF id/map_extra 写回 libbpf map 对象
- 标记 `map->reused = true`

见 `vendor/libbpf/src/libbpf.c:4979-5030`。

兼容性检查在 `map_is_reuse_compat()`，要求 type/key/value/max_entries/map_flags/map_extra 相同（`vendor/libbpf/src/libbpf.c:5166-5198`）。

### 3.3.2 数据是否保留

**保留。**

reuse 只是复用已有 kernel map fd，不会清空 key/value。`bpf_object__create_maps()` 在 `map->reused` 时直接跳过新建（`vendor/libbpf/src/libbpf.c:5548-5664`, 特别是 `5602-5605`）。

### 3.3.3 全局变量 map 的特殊性

`.data/.bss/.rodata/.kconfig` 在 libbpf 里本质上是 ARRAY map，`max_entries = 1`，`value_size = section_size`（`vendor/libbpf/src/libbpf.c:1957-2048`）。

新建 map 时，libbpf 会：

- 用初始 section bytes 填充
- 对 `.rodata/.kconfig` 调 `bpf_map_freeze()`

见 `vendor/libbpf/src/libbpf.c:5238-5269`。

但**重用 map 时不会重新 populate**。因此：

- 普通 `.data/.bss` 会保留旧值，而不是应用新 ELF 初始化值
- `.rodata/.kconfig` 旧 map 往往已 frozen，不能直接切到不同常量布局

这意味着：**如果 rewrite 改变了全局变量布局或 `.rodata` 内容，不能简单 reuse 原 internal map。**

### 3.3.4 per-CPU map

per-CPU map 只要元数据兼容，reuse 是允许的；但内容仍然保留旧 kernel 状态，libbpf 不会帮你重新初始化每 CPU 槽位。对于 benchmark 这通常可接受；对于生产替换则必须由 framework 明确声明“状态继承”还是“状态迁移/重建”。

## 3.4 program replacement 覆盖面

### 3.4.1 `bpf_link_update()` 真正支持哪些 link

内核 `link_update()` 只有在 link ops 提供 `update_prog` / `update_map` 时才成立（`vendor/linux-framework/kernel/bpf/syscall.c:5817-5868`）。

当前明确支持 `update_prog` 的有：

- XDP：`vendor/linux-framework/net/core/dev.c:10599-10655`
- cgroup：`vendor/linux-framework/kernel/bpf/cgroup.c:1461-1467`
- iter：`vendor/linux-framework/kernel/bpf/bpf_iter.c:491-497`
- TCX：`vendor/linux-framework/kernel/bpf/tcx.c:289-295`
- netns：`vendor/linux-framework/kernel/bpf/net_namespace.c:235-240`

`struct_ops` 不是 update program，而是 **update map**：

- kernel：`vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:1350-1356`
- libbpf：`vendor/libbpf/src/libbpf.c:13530-13564`

当前**不支持** `update_prog` 的典型 link：

- tracing/fentry/fexit/LSM：`vendor/linux-framework/kernel/bpf/syscall.c:3560-3565`
- raw tracepoint：`vendor/linux-framework/kernel/bpf/syscall.c:3851-3856`
- perf/tracepoint/kprobe/uprobe perf-link：`vendor/linux-framework/kernel/bpf/syscall.c:4165-4170`

### 3.4.2 各 attach 类型怎么替换

| attach 类别 | 当前推荐替换方式 | 原子性结论 |
| --- | --- | --- |
| XDP（bpf_link） | `bpf_link_update()` / `bpf_link__update_program()` | **是** |
| XDP（老 fd attach） | `bpf_xdp_attach(..., old_prog_fd, XDP_FLAGS_REPLACE)` | **是**；compare-and-swap 语义，见 `vendor/libbpf/src/libbpf.h:1339-1362`, `vendor/linux-framework/net/core/dev.c:10418-10447`, `10716-10759` |
| TCX | `bpf_link_update()` | **是** |
| legacy TC cls_bpf/act_bpf | `bpf_tc_attach(..., BPF_TC_F_REPLACE)` | **近似是**；走 rtnetlink replace filter，见 `vendor/libbpf/src/netlink.c:732-804`, `vendor/linux-framework/net/sched/cls_bpf.c:407-520` |
| cgroup（bpf_link） | `bpf_link_update()` | **是** |
| netns（bpf_link） | `bpf_link_update()` | **是** |
| iter | `bpf_link_update()` | **是** |
| kprobe/tracepoint/perf/uprobe | 新建新 link，再 detach 旧 link | **否** |
| fentry/fexit/fmod_ret/LSM | 新建新 link，再 detach 旧 link | **否** |
| struct_ops | 加载新 struct_ops map 后 `bpf_link__update_map()` | **是，但更新对象是 map，不是单个 prog** |

### 3.4.3 对路径 A 的影响

路径 A 不应该承诺“所有 attach 点都能无缝原子替换”。  
建议按覆盖面分级：

- **Tier 1**：XDP、TCX、legacy TC、cgroup、netns、iter、struct_ops
- **Tier 2**：kprobe/tracepoint/raw_tp/fentry/LSM，只支持 best-effort swap

## 3.5 libbpf skeleton 限制

Skeleton 不是独立加载机制，本质上只是对 `bpf_object_open()` / `bpf_object__load()` / attach 的包装：

- `bpf_object__open_skeleton()` 内部直接调用 `bpf_object_open()`（`vendor/libbpf/src/libbpf.c:14348-14376`）
- `bpf_object__load_skeleton()` 内部直接调用 `bpf_object__load()`（`vendor/libbpf/src/libbpf.c:14448-14472`）

所以：

- **如果原程序是 skeleton 加载的，daemon 完全可以绕过 skeleton，直接用 libbpf object API 操作。**
- 真正的限制在于 skeleton 会把 internal mmaped map 指针绑定到本进程对象上（`vendor/libbpf/src/libbpf.h:1802-1839`, `vendor/libbpf/src/libbpf.c:14458-14468`）。daemon 重载新对象后，不会更新原 loader 进程里的 skeleton 指针。

这不是 blocker，但意味着 daemon 方案应当把“原 loader 仍持有旧 skeleton 对象”视为正常状态，不依赖它协作。

## 4. 路径 B：加载时拦截

## 4.1 BPF LSM / `security_bpf_prog_load()` 能看到什么

`bpf_prog_load()` 在 verifier 前调用 `security_bpf_prog_load(prog, attr, token, kernel)`（`vendor/linux-framework/kernel/bpf/syscall.c:3085`）。LSM hook 定义在：

- `vendor/linux-framework/include/linux/lsm_hook_defs.h:430-445`
- `vendor/linux-framework/security/security.c:5236-5260`

因此**内核代码**确实能在 verifier 前看到：

- `struct bpf_prog *prog`（此时 `prog->insnsi` 刚从用户态复制过来）
- `union bpf_attr *attr`

## 4.2 这为什么仍然不适合“用户态 daemon 拦截重写”

因为这个 hook 的接口语义是：

- 同步执行
- 返回 `int`
- allow / deny

它**不是**：

- 把原始 bytecode 发送给用户态
- 挂起当前 syscall
- 等用户态回传新 bytecode
- 再从当前内核路径继续 verifier/JIT

如果你自己写一个内核 LSM 模块，理论上可以在 hook 里做更多事情；但那已经不是“用户态 framework”，而是“另一个内核实现路径”。

## 4.3 seccomp 为什么不行

seccomp 程序看到的是 `struct seccomp_data`：

- syscall 编号
- arch
- IP
- `args[6]`

见 `vendor/linux-framework/include/uapi/linux/seccomp.h:54-80`。

这意味着它拿到的只是：

- `cmd = BPF_PROG_LOAD`
- `attr` 指针
- `size`

而不是内核已经安全复制出来的 BPF insn/btf/relo 对象。  
即使走 `SECCOMP_RET_USER_NOTIF`，用户态监听进程拿到的仍然是这个结构，而且官方注释明确警告了指针参数改写的 TOCTOU 风险（`vendor/linux-framework/include/uapi/linux/seccomp.h:82-109`，`vendor/linux-framework/kernel/seccomp.c:1163-1257`）。

## 4.4 路径 B 判定

**不作为主方案。**

可以做的只有：

- 旁路观测/审计
- deny 原始 load，再让外部 orchestration 走另一条“优化后重新加载”的路径

但这会破坏原 loader 的透明性，不是用户要求的那种 seamless daemon。

## 5. 路径 C：新内核接口

## 5.1 当前内核保存了什么

`struct bpf_prog` 里有：

- `len`
- `jited_len`
- `aux`
- `orig_prog`
- `insnsi`

见 `vendor/linux-framework/include/linux/bpf.h:1807-1844`。

其中：

- `insnsi` 是当前 interpreter/verifier/JIT 使用的指令数组
- `orig_prog` 的类型是 `struct sock_fprog_kern *`

`orig_prog` 在 classic BPF 兼容路径里由 `bpf_prog_store_orig_filter()` 填入，并保存的是 classic filter 副本（`vendor/linux-framework/net/core/filter.c:1158-1188`），不是 eBPF `.o` 原始镜像。

## 5.2 因此需要什么新内核状态

如果要做路径 C，内核至少要在 load 时额外保存：

- pre-fixup eBPF `struct bpf_insn[]`
- 原始 `insn_cnt`
- 原始 BTF / BTF.ext 引用
- 原始 relocation 描述
- map symbol <-> used_map slot 对应
- 原始子程序边界

最合适的位置是 `struct bpf_prog_aux` 新增一个 `orig_ebpf_image` 子结构，而不是复用 `orig_prog`。

## 5.3 两种接口设计

### 方案 C1：`BPF_PROG_CLONE(prog_fd)`

返回一个可编辑 clone handle，内核导出：

- 原始 pre-fixup insns
- 只读 meta：BTF, BTF.ext, relo, map defs, attach attrs
- 写接口：提交新的 insns 或 patch list

后续再走：

- verifier
- JIT
- `bpf_link_update()` / attach replace

优点：语义清晰，便于做“先读后改”。  
缺点：接口较大，需要内核维护 clone 生命周期。

### 方案 C2：`BPF_PROG_REWRITE(prog_fd, new_insns, new_cnt, flags)`

用户态直接提交 rewrite 后的 pre-fixup insns；内核复用原程序的：

- map slots
- attach attrs
- BTF/BTF.ext
- subprog metadata

优点：接口小。  
缺点：内核需要做更多一致性检查，错误边界更复杂。

## 5.4 我更推荐的长期接口

推荐 **C1 + patch-style commit**：

1. `BPF_PROG_CLONE(prog_fd)` -> 返回 clone fd
2. `BPF_PROG_CLONE_GET_IMAGE(clone_fd)` -> 导出 pre-fixup image + meta
3. `BPF_PROG_CLONE_APPLY_PATCH(clone_fd, patch_blob)` -> 内核做 patch 与 meta consistency 检查
4. `BPF_PROG_CLONE_COMMIT(clone_fd, old_prog_fd/link_fd)` -> verifier + JIT + replace

这样用户态只需要关注 rewrite 逻辑，最难的 map/BTF/relo consistency 可以留在内核里。

## 6. 含 kinsn 的 ELF 是否还能走 libbpf

## 6.1 libbpf 会不会拒绝未知 opcode

**libbpf 本身通常不会逐条做通用 opcode 白名单检查。**

程序加载最终只是把 `prog->insns` / `prog->insns_cnt` 填到 `bpf_prog_load()` syscall（`vendor/libbpf/src/libbpf.c:8212-8238`, `7783-7900`; `vendor/libbpf/src/bpf.c:238-387`）。

所以：

- 只要 relocation/section parsing 没踩到 libbpf 的特例路径
- 未知 opcode 通常会一路传到 kernel

真正会拒绝的是 kernel verifier 的 opcode 白名单：

- `resolve_pseudo_ldimm64()` 调 `bpf_opcode_in_insntable()`（`vendor/linux-framework/kernel/bpf/verifier.c:21879-21883`）
- `bpf_opcode_in_insntable()` 依赖 `BPF_INSN_MAP` 构造的公开 opcode 表（`vendor/linux-framework/kernel/bpf/core.c:1651`, `1795-1812`）

**因此 kinsn 至少要改 kernel opcode table。**

## 6.2 BTF / BTF.ext 要不要更新

- **BTF** 本身描述类型，不描述指令语义；只要 rewrite 不改 map/value/type layout，通常不用变。
- **BTF.ext** 则不同，它记录 `func_info` / `line_info` 的 `insn_off`，如果指令长度或 subprog 布局变化，必须同步更新（`vendor/libbpf/src/libbpf.c:6469-6607`）。

所以：

- 等长替换：BTF 一般不动，BTF.ext 也通常可保持不变
- 变长替换：BTF.ext 必须重写

## 6.3 bpftool / perf / ftrace 可读性

- `bpftool prog dump xlated` 复用内核 `print_bpf_insn()`，见 `vendor/linux-framework/tools/bpf/bpftool/xlated_dumper.c:270-271`, `352-353`
- `print_bpf_insn()` 的格式化逻辑在 `vendor/linux-framework/kernel/bpf/disasm.c:186-360`

所以如果新增 `kinsn` 而不更新 disassembler：

- verifier 若已放行，disasm 可能打印成 `BUG_xx` 一类占位
- 如果 opcode 连 verifier 白名单都没进，甚至会在更早阶段报 `unknown opcode`

perf/ftrace 看到的是 JIT/native 指令流，它们不需要知道 eBPF opcode 才能看 native asm；但如果想把 native PC 映回 eBPF 指令语义，仍然依赖 line info / jit line info / disasm 逻辑。因此运维可观测性也要求同步更新 disassembler。

## 7. Relocation：最关键问题与解决方案

## 7.1 当前 ELF relocation 类型

你关心的四类在 libbpf 里都能直接对上：

- map/global data relocation：`RELO_LD64`, `RELO_DATA`
- kfunc relocation：`RELO_EXTERN_CALL`
- subprog call/address relocation：`RELO_CALL`, `RELO_SUBPROG_ADDR`
- CO-RE relocation：`RELO_CORE`

见 `vendor/libbpf/src/libbpf.c:6356-6467`, `6715-6821`。

## 7.2 变长 rewrite 需要维护什么

一旦插入/删除指令，至少要更新：

1. **relocation site -> `insn_idx`**
   - libbpf 的 `reloc_desc.insn_idx` 就是按指令索引定位（`vendor/libbpf/src/libbpf.c:6360-6362`, `6627-6653`）

2. **所有 BPF jump/call 相对偏移**
   - 本仓库现有 loader 里也已经手工 patch 了 subprog call 的 `imm`（`runner/src/elf_program_loader.cpp:505-545`）

3. **subprogram 边界**
   - libbpf 在 append subprog 时显式维护 `sub_insn_off`（`vendor/libbpf/src/libbpf.c:6674-6712`, `6715-6821`）

4. **`func_info` / `line_info` 的 `insn_off`**
   - `adjust_prog_btf_ext_info()` 就是专门做这个的（`vendor/libbpf/src/libbpf.c:6469-6535`）

5. **CO-RE relocation 关联位点**
   - `bpf_program_record_relos()` 和 `RELO_CORE` 都按 insn offset 记录（`vendor/libbpf/src/libbpf.c:6442-6444`, `8168-8209`）

## 7.3 等长替换是否能规避问题

**能规避绝大多数问题，且值得作为 Phase 1 硬约束。**

如果 rewrite 满足：

- 不插入/删除指令
- 不跨越 relocation site
- 不改变 subprog 边界

则通常可以避免：

- `reloc_desc.insn_idx` 迁移
- `func_info/line_info` `insn_off` 调整
- CO-RE site 迁移

仍然要注意：

- 新指令本身的 immediate/offset 编码是否需要更新
- 替换段内部 jump target 是否仍正确

因此建议 Phase 1 只支持：

- 单 basic-block 内
- 无外部 relocation 经过
- 无 subprog 边界穿越
- 固定 `N -> N`

## 7.4 如果必须做变长替换

复杂度是真实存在的，但不是不可做。建议做法：

1. 建立 bytecode IR
   - 节点：指令
   - 边：fallthrough / jump / call
   - 附件：relo / linfo / finfo / core_relo 标注

2. rewrite 前先构造 `old_insn_idx -> new_insn_idx` 映射

3. 一次性重写：
   - 本地 jump/call
   - reloc site
   - subprog starts
   - BTF.ext offsets

4. 最后再序列化回 ELF/code blob

## 7.5 有没有现成 bytecode manipulation 库

**没有看到成熟、通用、专门面向 eBPF ELF 重写的现成库。**

现实上只有三类“半成品”：

1. **libbpf 内部代码**
   - 最权威，但不是 public rewrite API（`vendor/libbpf/src/libbpf.c:6356-6821`）

2. **本仓库现有 `runner/src/elf_program_loader.cpp`**
   - 已经做了 map/subprog relocation 和 section 拼接
   - 很适合作为 `relocator.cpp` 的起点

3. **更高层 loader 库（libbpfgo, cilium/ebpf, aya 等）**
   - 主要解决 load/attach，不解决“保持 ELF relocation/BTF.ext 一致性的重写器”

因此，最现实的路线是：**复用 scanner 的 matcher + 参考 libbpf 内部逻辑 + 直接在本仓库实现一套最小专用 relocator。**

## 8. 推荐的用户态 framework 设计

## 8.1 设计原则

1. 不从 xlated 反推 reloadable image
2. origin `.bpf.o` 是一级输入，不是可选优化
3. Phase 1 只支持等长 rewrite
4. 替换面按原子性分 tier
5. 失败默认回退原程序；verifier 拒绝即 fail-safe

## 8.2 模块级架构

```text
bpf-rejit-daemon/
  src/
    discovery.cpp
    origin_registry.cpp
    analyzer.cpp
    rewriter.cpp
    relocator.cpp
    loader.cpp
    replacer.cpp
    profiler.cpp
    policy.cpp
    orchestrator.cpp
```

### `discovery.cpp`

职责：

- 枚举 live program：`BPF_PROG_GET_NEXT_ID` -> `BPF_PROG_GET_FD_BY_ID`
- 拉 `bpf_prog_info`
- 拉 `xlated_prog_insns` 仅用于 pattern index / profile correlation

可直接复用：

- `scanner/src/cli.cpp:400-434`, `481-504`, `650-730`
- `runner/src/kernel_runner.cpp:774-835`

### `origin_registry.cpp`

职责：

- 从 sidecar manifest / known-loader adapter 找 origin ELF
- 建立 `prog_id/tag -> origin_elf + attach handle + map pin metadata`

这是路径 A 的关键模块；没有它，rewrite 直接失效。

### `analyzer.cpp`

职责：

- 读取原始 `.bpf.o` 的程序 image
- 用 scanner 的 pattern matcher 在**原始 bytecode**上定位 site
- 同时维护“site 是否落在可重写子集内”的约束检查

建议复用：

- `scanner/src/pattern_v5.cpp`
- `runner/src/elf_program_loader.cpp:606-730`

### `rewriter.cpp`

职责：

- 把匹配到的 site 从原始指令序列改写为 `kinsn`
- Phase 1 只输出等长替换
- 为 Phase 2 预留 patch list 格式：
  - `site_start`
  - `old_len`
  - `new_len`
  - `new_insns[]`

### `relocator.cpp`

职责：

- 维护 jump/call/BTF.ext/reloc/subprog 边界
- Phase 1 下主要做验证：
  - 替换后长度未变
  - relocation site 未漂移
  - func_info/line_info 不必改

Phase 2 再引入完整 offset remap。

### `loader.cpp`

职责：

- 用 libbpf 打开 rewrite 后对象
- 对普通 map 调 `bpf_map__reuse_fd()`
- 对 internal global-data map 按策略：
  - `inherit`
  - `recreate`
  - `deny if layout changed`
- 调 `bpf_object__load()`

### `replacer.cpp`

职责：

- 根据 attach 类型选择 replace 方法
- Tier 1 用 `bpf_link_update()` / XDP replace / TC replace
- Tier 2 做 best-effort attach-new-then-detach-old

### `profiler.cpp`

职责：

- 周期性拉 `run_time_ns` / `run_cnt` / `bytes_jited` / `bytes_xlated`
- 可选开启 `BPF_ENABLE_STATS`
- 与 perf counters / e2e workload 数据结合

相关现有代码：

- `runner/libs/metrics.py:19-167`
- `vendor/linux-framework/kernel/bpf/syscall.c:5994-6019`

### `policy.cpp`

职责：

- 根据 profile 决定是否应用 rewrite
- 例如：
  - hot enough 才优化
  - 站点密度太高则跳过
  - attach type 不可原子替换则只在 maintenance window 做

### `orchestrator.cpp`

职责：

- 串联 discovery -> origin resolve -> analyze -> rewrite -> load -> replace
- 记录审计日志
- 维护回滚点

## 8.3 推荐的数据模型

```text
LiveProgramRecord
  prog_id
  prog_fd
  tag
  name
  type
  expected_attach_type
  link_info
  map_ids[]
  xlated_len
  jited_len
  run_cnt
  run_time_ns

OriginRecord
  elf_path
  program_name
  attach_kind
  attach_handle
  map_pin_paths[]
  loader_id
  build_id

RewritePlan
  program_name
  sites[]
  requires_varlen_reloc
  changed_global_layout
  replacement_strategy
```

## 8.4 建议的最小落地子集

第一阶段只支持：

- prog type：XDP / sched_cls(TCX or legacy TC) / cgroup_skb
- attach：可原子更新者优先
- rewrite：等长
- maps：普通 map reuse；internal global map 要求 layout 不变
- origin：只支持有 manifest 的 loader

这样能把系统复杂度从“通用 live rewriter”收敛到“受控对象重载器”。

## 9. benchmark framework 该怎么改

## 9.1 当前 benchmark 已有的能力

- `run-kernel` 当前已经输出 `compile_ns`、`exec_ns`、`phases_ns`
- 已经支持 same-image paired measurement：`stock` -> apply -> `recompile`
- phase 输出里已经有：
  - `object_open_ns`
  - `object_load_ns`
  - `recompile_apply_ns`
  - `prog_run_wall_ns`

见：

- `runner/src/kernel_runner.cpp:1641-1779`
- `runner/libs/results.py:152-171`
- `micro/driver.py:89-140`
- `corpus/driver.py:142-156`

## 9.2 新方案下的 micro benchmark

建议新增 runtime，例如 `kernel-rewrite-kinsn`：

1. 打开原始 `.bpf.o`
2. baseline:
   - `bpf_object__load()`
   - `BPF_PROG_TEST_RUN`
   - 记录 `object_open_ns + object_load_ns + exec_ns`
3. optimized:
   - `rewrite_ns`
   - `bpf_object__load()` 新对象
   - `verify+jit` 时间直接计入第二次 `object_load_ns`
   - `BPF_PROG_TEST_RUN`
4. 输出 paired record：
   - `phase = stock`
   - `phase = rewrite`

我建议把 timing 细化为：

- `rewrite_analyze_ns`
- `rewrite_apply_ns`
- `object_open_ns`
- `object_load_ns`
- `prog_run_wall_ns`
- `result_read_ns`

其中 verifier/JIT 无法从内核直接拆分；在 userspace benchmark 里最现实的是把它们合并进 `object_load_ns`。

## 9.3 same-image paired measurement

对 micro benchmark，可以完全沿用 `runner/src/kernel_runner.cpp:1702-1779` 的 paired 结构，只是把“post-load live recompile”替换成“rewrite -> reload optimized image”。

具体做法：

1. 同一轮 benchmark 中先 load baseline object 并测 `stock`
2. 保持同一输入 buffer / same process / same CPU pinning
3. 销毁 baseline object
4. 立即 load rewrite 后 object 并测 `rewrite`

这样保持：

- same benchmark input
- same host state
- same image generation logic

## 9.4 macro / e2e benchmark

- `corpus/driver.py` 当前已经有 `kernel-recompile-v5` runtime 和 `recompile_apply_ns` 字段（`corpus/driver.py:752-919`）
- 可以并行引入 `kernel-rewrite-kinsn-v1`
- e2e 则分两层：
  - **control-plane cost**：rewrite/load/replace latency
  - **steady-state benefit**：替换后 workload 的 `run_cnt_delta` / `run_time_ns delta`

## 10. 与已有 scanner 的重叠与差异

## 10.1 重叠

- pattern 发现
- live program 枚举
- xlated 读取
- 成本模型/策略过滤

## 10.2 差异

| 组件 | 当前 scanner | 新 rewriter |
| --- | --- | --- |
| 输入 | ELF 或 live xlated | 原始 `.bpf.o` + origin metadata |
| 输出 | policy blob | 修改后的 object image |
| 依赖 | `BPF_PROG_JIT_RECOMPILE` | `BPF_PROG_LOAD` + map reuse + replace |
| relocation 责任 | 基本无 | 很重 |

## 10.3 复用建议

**强烈建议复用 scanner 的 matcher，不要重写 pattern engine。**

合理拆分是：

- scanner 保留：
  - `pattern_v5`
  - site summary / family taxonomy
  - 成本模型

- rewriter 新增：
  - origin ELF loader
  - rewrite emit
  - relocator
  - loader/replacer

## 11. 安全模型

## 11.1 daemon 需要什么权限

最小权限不是一句 `CAP_SYS_ADMIN` 就能概括，源码里的 load 检查是：

- 基础 load 需要 `CAP_BPF` 或 token 等价能力（`vendor/linux-framework/kernel/bpf/syscall.c:2914-2940`）
- net admin 类 prog type 还需要 `CAP_NET_ADMIN`（`vendor/linux-framework/kernel/bpf/syscall.c:2942-2943`）
- perfmon 类 prog type 还需要 `CAP_PERFMON`（`vendor/linux-framework/kernel/bpf/syscall.c:2944-2945`）
- 开启 runtime stats 的 `BPF_ENABLE_STATS` 还需要 `CAP_SYS_ADMIN`（`vendor/linux-framework/kernel/bpf/syscall.c:6004-6019`）

因此 daemon 的推荐权限模型是：

- 基础：`CAP_BPF`
- 按目标 prog type 增补：`CAP_NET_ADMIN` / `CAP_PERFMON`
- 仅当需要 `BPF_ENABLE_STATS` 或其他管理操作时再给 `CAP_SYS_ADMIN`

## 11.2 失败模式

### bytecode rewrite 有 bug

- 如果生成非法 bytecode：verifier 拒绝，安全失败
- 如果 map/layout 不兼容：load 失败，不替换原程序
- 如果 attach replace 不支持：保留原程序

### kinsn verifier callback 有 bug

这是新架构最核心的安全风险。  
当前方案和原始 `BPF_PROG_JIT_RECOMPILE` 相比，新增了一个风险面：**用户态 rewrite 会把更多语义编码为新 opcode，需要对应 verifier 证明。**

## 11.3 与当前方案对比

当前 scanner + `BPF_PROG_JIT_RECOMPILE` 方案：

- 不改 bytecode 入口格式
- 只给 JIT 一个 policy blob

新 userspace rewrite 方案：

- 直接生成新的可验证 BPF bytecode
- 需要处理 ELF/relo/map/link 全链路

所以新方案的安全优势是“仍经 verifier 复查”；安全代价是“用户态生成器和新 opcode verifier 都变成 TCB 的一部分”。

## 12. 最终建议

## 12.1 近期建议

1. **明确放弃“从 live xlated 反推 reloadable image”**
2. **以路径 A 为主线**
3. **先做 origin manifest 机制**
4. **第一阶段只支持等长 rewrite**
5. **第一阶段只覆盖 XDP / TC / cgroup / netns / iter / struct_ops**

## 12.2 中期建议

1. 把 `runner/src/elf_program_loader.cpp` 演进成正式 `relocator.cpp`
2. 把 scanner matcher 抽成可复用库
3. 在 benchmark 中增加 `kernel-rewrite-kinsn` runtime

## 12.3 长期建议

如果团队希望覆盖：

- 没有 origin ELF 的 live program
- tracing/fentry/LSM 等 attach 面的低扰动更新
- 变长 rewrite / 更复杂的 bytecode surgery

那就应该直接投入路径 C，新增内核 clone/rewrite 接口，而不是继续在用户态做 xlated 逆向。

## 13. 一个可执行的分阶段计划

### Phase 0: 只做设计闭环

- 建 `origin_registry`
- 把 live program 和 origin ELF 对上
- 先不 rewrite，只验证发现率与覆盖率

### Phase 1: 等长 rewrite MVP

- 只支持单 basic-block 内等长 rewrite
- 只支持 XDP / TC / cgroup_skb
- 只支持普通 map reuse，禁止 global layout 变化

### Phase 2: 变长 relocator

- 引入 `old_idx -> new_idx` remap
- 更新 jump / call / BTF.ext / CO-RE site

### Phase 3: 内核接口化

- 评估 `BPF_PROG_CLONE` / `BPF_PROG_REWRITE`
- 保存 pre-fixup eBPF image

---

## 参考源码索引

- `vendor/linux-framework/kernel/bpf/syscall.c`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/kernel/bpf/core.c`
- `vendor/linux-framework/include/linux/bpf.h`
- `vendor/linux-framework/include/linux/filter.h`
- `vendor/linux-framework/net/core/filter.c`
- `vendor/linux-framework/kernel/bpf/cgroup.c`
- `vendor/linux-framework/kernel/trace/bpf_trace.c`
- `vendor/linux-framework/kernel/bpf/bpf_iter.c`
- `vendor/linux-framework/kernel/bpf/tcx.c`
- `vendor/linux-framework/kernel/bpf/net_namespace.c`
- `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c`
- `vendor/libbpf/src/libbpf.c`
- `vendor/libbpf/src/bpf.c`
- `vendor/libbpf/src/netlink.c`
- `runner/src/elf_program_loader.cpp`
- `runner/src/kernel_runner.cpp`
- `scanner/src/cli.cpp`

