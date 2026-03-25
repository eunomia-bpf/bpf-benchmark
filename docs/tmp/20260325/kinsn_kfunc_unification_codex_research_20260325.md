# kinsn 伪指令编码统一到 kfunc CALL 路径调研报告

- 日期：2026-03-25
- 仓库：`/home/yunwei37/workspace/bpf-benchmark`
- 调研范围：只读调研，不修改代码，不运行内核/BPF 测试

## 结论摘要

1. 当前代码里的 kinsn 不是“只差一个 pseudo tag 的 kfunc”。它是一条独立的 `BTF_KIND_VAR -> struct bpf_kinsn -> verifier proof lowering -> JIT native emit` 管线。
2. 当前树里不存在任务背景里提到的 `bpf_kinsn_ops` / `bpf_kinsn_effect` / `bpf_kinsn_call` / `model_call -> bpf_kinsn_effect` 实现；`HEAD` 的真实实现是 `struct bpf_kinsn { instantiate_insn, emit_x86, emit_arm64 }`，并通过 `lower_kinsn_proof_regions()` 在主 verifier 前做 proof lowering。
3. 如果“字面上只把 `BPF_PSEUDO_KINSN_CALL` 改成 `BPF_PSEUDO_KFUNC_CALL`，其余逻辑不动”，当前树不能工作：
   - 模块侧 today 只导出 descriptor `VAR`，没有真实 `FUNC` kfunc、没有 `register_btf_kfunc_id_set()` 注册。
   - `check_kfunc_call()` 会自动套上 kfunc 的参数检查、GPL 限制、prog-type allowlist、`R0-R5` clobber，这与当前 packed sidecar ABI 和 proof-seq 语义直接冲突。
   - `fixup_kfunc_call()` 会改写 `imm`，现有 kinsn JIT lookup keyed by `(imm, off)` 会失效。
4. 可行的统一方式不是“让 kinsn 直接吃进标准 `check_kfunc_call()` 语义”，而是：
   - CALL 编码统一成 `BPF_PSEUDO_KFUNC_CALL`
   - 真实目标统一成 kfunc `FUNC` + `register_btf_kfunc_id_set()`
   - 但 verifier 仍对“带 sidecar 的 `KF_KINSN` kfunc”走现有 proof-lowering 旁路，避免落入 generic kfunc arg/clobber 语义
   - JIT 在现有 kfunc CALL 分支里按 `KF_KINSN` 再分派到现有 `emit_x86/emit_arm64`
5. 从 reviewer 视角，这种改法是“删除并行 kinsn CALL/VAR registry，保留 sidecar + native emit 的 kfunc 化”，上游接受性明显好于继续维护一套独立 pseudo/UAPI/verifier/JIT path。

## 0. 当前代码现实与任务背景的偏差

这一步必须先讲清楚，否则后面的“可行性”会被错误前提带偏。

- 当前 UAPI 确实同时存在 `BPF_PSEUDO_KFUNC_CALL=2`、`BPF_PSEUDO_KINSN_SIDECAR=3`、`BPF_PSEUDO_KINSN_CALL=4`，见 `vendor/linux-framework/include/uapi/linux/bpf.h:1378-1394`。
- 当前内核里真实存在的是 `struct bpf_kinsn`、`struct bpf_kinsn_id`、`struct bpf_kinsn_set`，见 `vendor/linux-framework/include/linux/bpf.h:968-1003`。
- 当前 verifier/JIT 依赖的是：
  - `instantiate_insn()` 生成 proof sequence
  - `emit_x86()` / `emit_arm64()` 做 native emit
  - `lower_kinsn_proof_regions()` / `restore_kinsn_proof_regions()` 完成 verifier lowering/restore
- 当前树中没有任务背景里提到的这些代码符号：
  - `bpf_kinsn_ops`
  - `bpf_kinsn_effect`
  - `bpf_kinsn_call`
  - `model_call`

因此，本报告后续所有结论都以 **当前 HEAD 的真实代码** 为准，而不是以背景描述中的旧设计为准。

## 1. kfunc 路径完整流程

### 1.1 总体 call graph

```text
daemon / userspace emit
  -> CALL(code=BPF_JMP|BPF_CALL, src_reg=BPF_PSEUDO_KFUNC_CALL,
          imm=BTF_KIND_FUNC id, off=0|fd_array slot)

bpf_check()                                     verifier.c:26518
  -> process_fd_array()                         verifier.c:26576
  -> add_subprog_and_kfunc()                    verifier.c:26603 / 4149
     -> add_kfunc_call()                        verifier.c:3512
        -> fetch_kfunc_meta()                   verifier.c:3449
           -> find_kfunc_desc_btf()             verifier.c:3405
              -> __find_kfunc_desc_btf()        verifier.c:3301
                 -> btf_get_by_fd()
                 -> btf_try_get_module()
           -> btf_kfunc_flags()                 btf.c:8903
           -> btf_type_by_id(func_id)
           -> find_kfunc_impl_proto()           verifier.c:3423, optional for KF_IMPLICIT_ARGS
        -> kallsyms_lookup_name(kfunc.name)
        -> btf_distill_func_proto()
        -> stash into prog->aux->kfunc_tab

  -> do_check_main()/do_check_subprogs()
     -> do_check_insn()                         verifier.c:21596
        -> check_kfunc_call()                   verifier.c:14632
           -> fetch_kfunc_arg_meta()            verifier.c:14424
              -> fetch_kfunc_meta()             verifier.c:3449
              -> btf_kfunc_is_allowed()         btf.c:8876
           -> check_kfunc_args()                verifier.c:13877
           -> check_special_kfunc()             verifier.c:14455
           -> mark caller-saved regs clobbered  verifier.c:14864-14869
           -> set R0 return state               verifier.c:14871+

  -> do_misc_fixups()                           verifier.c:23931 / 26711
     -> fixup_kfunc_call()                      verifier.c:23760
        -> find_kfunc_desc()                    verifier.c:3274
        -> specialize_kfunc()                   verifier.c:23694
        -> imm = BPF_CALL_IMM(desc->addr)       verifier.c:23788-23789
        -> maybe inject extra ldimm64/shims     verifier.c:23791-23897
     -> sort_kfunc_descs_by_imm_off()           verifier.c:24915 / 3740

  -> fixup_call_args()                          verifier.c:26723 / 23637
     -> jit_subprogs() or reject non-JIT kfunc

JIT / core
  -> bpf_prog_select_runtime()                  core.c:2528
     -> bpf_prog_has_kfunc_call()               verifier.c:3760
  -> arch JIT emit CALL
     -> x86_64: generic call path uses __bpf_call_base + imm
                (after verifier fixup)          x86 JIT:2483-2510
     -> arm64: bpf_jit_get_func_addr()          arm64 JIT:1635-1639
        -> if far-kfunc supported:
             bpf_get_kfunc_addr()               core.c:1278-1282 / verifier.c:3288
           else:
             __bpf_call_base + imm              core.c:1283-1289
```

### 1.2 关键函数与作用

| 文件:函数:行号 | 作用 |
| --- | --- |
| `vendor/linux-framework/kernel/bpf/verifier.c:add_subprog_and_kfunc():4149-4216` | 预扫描整个程序；发现 `PSEUDO_KFUNC_CALL` 时创建/填充 `kfunc_tab` |
| `vendor/linux-framework/kernel/bpf/verifier.c:add_kfunc_call():3512-3604` | 建立 `(func_id, off) -> addr + func_model` 描述项；同时做 JIT/GPL 支持检查 |
| `vendor/linux-framework/kernel/bpf/verifier.c:fetch_kfunc_meta():3449-3509` | 按 `func_id + off` 找 BTF、函数名、proto、flags |
| `vendor/linux-framework/kernel/bpf/verifier.c:find_kfunc_desc_btf():3405-3418` | `off=0` 用 vmlinux BTF；`off>0` 用 `fd_array` 模块 BTF |
| `vendor/linux-framework/kernel/bpf/verifier.c:__find_kfunc_desc_btf():3301-3371` | 读取 `fd_array[offset]`、`btf_get_by_fd()`、`btf_try_get_module()` 并 pin 住模块生命周期 |
| `vendor/linux-framework/kernel/bpf/btf.c:btf_kfunc_flags():8903-8915` | 从 kfunc id set 取内部 `KF_*` flags |
| `vendor/linux-framework/kernel/bpf/btf.c:btf_kfunc_is_allowed():8876-8894` | 按 prog type/common hook 做 kfunc allowlist 判定 |
| `vendor/linux-framework/kernel/bpf/verifier.c:check_kfunc_call():14632-15024` | 完整 verifier kfunc call 语义：权限、sleepable/RCU、参数、返回值、clobber |
| `vendor/linux-framework/kernel/bpf/verifier.c:check_kfunc_args():13877-14421` | 严格按 BTF func_proto 检查 R1-R5 参数类型和值域 |
| `vendor/linux-framework/kernel/bpf/verifier.c:fixup_kfunc_call():23760-23898` | 把 `imm` 从 BTF func id 改为真实 call imm，外加特殊 kfunc patch |
| `vendor/linux-framework/kernel/bpf/verifier.c:sort_kfunc_descs_by_imm_off():3740-3757` | 生成 JIT lookup 需要的 `(imm, off)` 排序视图 |
| `vendor/linux-framework/kernel/bpf/core.c:bpf_jit_get_func_addr():1256-1294` | JIT 通用函数地址解析；far kfunc 才直接走 `bpf_get_kfunc_addr()` |
| `vendor/linux-framework/kernel/bpf/verifier.c:bpf_get_kfunc_addr():3288-3298` | 从 `prog->aux->kfunc_tab` 取真实地址 |
| `vendor/linux-framework/kernel/bpf/btf.c:register_btf_kfunc_id_set():8953-8969` | kfunc 正式注册入口；把 `BTF_ID_FLAGS(func, ..., KF_*)` 放进 `btf->kfunc_set_tab` |

### 1.3 `check_kfunc_call()` 自动附带的语义

只要 CALL 进入 `check_kfunc_call()`，以下行为会自动发生：

- 读取并验证 `KF_*` flags：`fetch_kfunc_arg_meta()` -> `btf_kfunc_is_allowed()` / `btf_kfunc_flags()`。
- 强制按 BTF 原型检查参数：`check_kfunc_args()`，对应 `vendor/linux-framework/kernel/bpf/verifier.c:14706-14709`。
- 应用 sleepable / destructive / RCU / preempt / callback 等通用 kfunc 规则。
- 无条件 clobber caller-saved BPF 寄存器：`R0-R5` 被 `mark_reg_not_init()`，见 `vendor/linux-framework/kernel/bpf/verifier.c:14864-14869`。
- 再根据返回类型重建 `R0` 状态。

这正是后面“为何不能让 packed kinsn 直接吃进 generic kfunc verifier 语义”的根因。

## 2. 当前 kinsn 路径完整流程

### 2.1 daemon 侧 emit / discovery

```text
daemon startup / cmd_apply
  -> discover_kinsns()                          daemon/src/kfunc_discovery.rs:323
     -> read /sys/kernel/btf/<module>
     -> find_var_btf_id(desc_name)              daemon/src/kfunc_discovery.rs:292-299, 383
     -> bpf_btf_get_fd_by_module_name()
     -> fill KinsnRegistry(target -> descriptor VAR id, module BTF fd)

pass rewrite
  -> ensure_btf_fd_slot()                       daemon/src/passes/utils.rs:239-247
  -> emit_packed_kinsn_call_with_off()          daemon/src/passes/utils.rs:228-237
     -> sidecar MOV pseudo
     -> CALL(src_reg=BPF_PSEUDO_KINSN_CALL,
             imm=descriptor VAR id,
             off=fd_array slot)
```

对应代码点：

- `daemon/src/insn.rs:56-60`：定义 `BPF_PSEUDO_KFUNC_CALL=2`、`BPF_PSEUDO_KINSN_SIDECAR=3`、`BPF_PSEUDO_KINSN_CALL=4`
- `daemon/src/insn.rs:229-240`：`call_kinsn_with_off()`
- `daemon/src/insn.rs:269-275`：`kinsn_sidecar(payload)`
- `daemon/src/kfunc_discovery.rs:21-33`：`KNOWN_KINSNS` 当前是 `(registry_key, descriptor_var_name, module_name)`
- `daemon/src/kfunc_discovery.rs:383-389`：当前按 `BTF_KIND_VAR` 查 descriptor
- `daemon/src/pass.rs:68-70`：`required_btf_fds` 目前注释写的是 descriptor BTF FDs
- `daemon/src/commands.rs:184-189`：`fd_array[0]` 预留，`CALL.off` 的模块 BTF slot 从 1 开始

### 2.2 内核 verifier / BTF / JIT call graph

```text
userspace emits
  -> sidecar MOV (src_reg=PSEUDO_KINSN_SIDECAR)
  -> CALL(src_reg=PSEUDO_KINSN_CALL, imm=descriptor VAR id, off=fd_array slot)

bpf_check()                                     verifier.c:26518
  -> add_subprog_and_kfunc()                    verifier.c:4149
     -> env->kinsn_call_cnt++                   verifier.c:4177-4179
     -> add_kinsn_call()                        verifier.c:3643
        -> fetch_kinsn_desc_meta()              verifier.c:3607
           -> find_kfunc_desc_btf()             verifier.c:3618
           -> btf_try_get_kinsn_desc()          btf.c:9175
        -> stash into prog->aux->kinsn_tab

  -> lower_kinsn_proof_regions()                verifier.c:3958 / 26607
     -> find preceding sidecar
     -> bpf_jit_find_kinsn_desc()               verifier.c:3796
     -> kinsn->instantiate_insn(payload)
     -> validate_kinsn_proof_seq()              verifier.c:3842
     -> replace [sidecar, call] with proof seq

  -> do_check_main()/do_check_subprogs()
     -> verifier sees proof seq, not kinsn call
     -> if kinsn call leaked through:
          do_check_insn() hard-fails            verifier.c:21695-21696

  -> restore_kinsn_proof_regions()              verifier.c:4042 / 26679
     -> restore original [sidecar, call]

  -> do_misc_fixups()                           verifier.c:23931 / 26711
     -> if sidecar + kinsn call:
          build_kinsn_inst_seq()                verifier.c:4080
          if jit_requested && native_emit:
             keep original pair                 verifier.c:23977-23978
          else:
             replace with instantiated proof seq

  -> fixup_call_args()                          verifier.c:23637 / 26723
     -> reject non-JIT kinsn programs           verifier.c:23661-23663

JIT x86/arm64
  -> sidecar MOV is skipped                     x86:1906-1911 / arm64:1254-1255
  -> if src_reg == PSEUDO_KINSN_CALL:
       bpf_jit_get_kinsn_payload()              verifier.c:4111
         -> bpf_jit_find_kinsn_desc()
         -> find sidecar payload
       kinsn->emit_x86()/emit_arm64()
```

### 2.3 关键函数与作用

| 文件:函数:行号 | 作用 |
| --- | --- |
| `vendor/linux-framework/kernel/bpf/verifier.c:add_kinsn_call():3643-3678` | 建立 `(imm=descriptor VAR id, off) -> struct bpf_kinsn*` 映射 |
| `vendor/linux-framework/kernel/bpf/verifier.c:fetch_kinsn_desc_meta():3607-3640` | 用 descriptor VAR id + 模块 BTF 找 `struct bpf_kinsn` |
| `vendor/linux-framework/kernel/bpf/btf.c:register_bpf_kinsn_set():9029-9090` | kinsn 独立注册表；把 `VAR id -> desc ptr` 放进 `btf->kinsn_tab` |
| `vendor/linux-framework/kernel/bpf/btf.c:btf_try_get_kinsn_desc():9175-9190` | 从 `btf->kinsn_tab` 取 descriptor |
| `vendor/linux-framework/kernel/bpf/verifier.c:lower_kinsn_proof_regions():3958-4035` | 主 verifier 前把 sidecar+call 替换成 proof sequence |
| `vendor/linux-framework/kernel/bpf/verifier.c:restore_kinsn_proof_regions():4042-4066` | 主 verifier 后恢复原始 sidecar+call |
| `vendor/linux-framework/kernel/bpf/verifier.c:validate_kinsn_proof_seq():3842-3893` | proof sequence 合法性检查 |
| `vendor/linux-framework/kernel/bpf/verifier.c:build_kinsn_inst_seq():4080-4108` | `do_misc_fixups()` 里重新实例化 proof sequence |
| `vendor/linux-framework/kernel/bpf/verifier.c:bpf_jit_get_kinsn_payload():4111-4131` | JIT 从原始程序里取 descriptor + sidecar payload |
| `vendor/linux-framework/kernel/bpf/verifier.c:check_kinsn_sidecar_insn():21576-21593` | sidecar 只能跟 `PSEUDO_KINSN_CALL`；否则报错 |
| `vendor/linux-framework/kernel/bpf/verifier.c:do_check_insn():21691-21696` | 若 `PSEUDO_KINSN_CALL` 没被 lowering 掉，直接报 internal error |
| `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:579-606` | x86 原生 kinsn emit 回调 |
| `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2487-2493` | x86 独立 `PSEUDO_KINSN_CALL` JIT dispatch |
| `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1195-1219` | arm64 原生 kinsn emit 回调 |
| `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1627-1633` | arm64 独立 `PSEUDO_KINSN_CALL` JIT dispatch |

### 2.4 当前 kinsn 语义的关键事实

最重要的一点：**主 verifier 实际上不会验证 `PSEUDO_KINSN_CALL` 本身**。

它验证的是 lowering 后的 proof sequence。因此当前 kinsn 的 verifier 语义来源不是 kfunc call 规则，而是 `instantiate_insn()` 生成的那段普通 BPF 指令序列。

这意味着：

- 现有 kinsn 可以保留任意寄存器，只要 proof sequence 没 clobber。
- 现有 kinsn 的返回值可以直接体现在 payload 指定的目标寄存器上，而不必遵守“结果总在 R0”。
- 这与 generic kfunc call 的 `R0-R5` clobber + `R0` return 语义并不相同。

## 3. 合并可行性分析

### 3.1 如果直接把 kinsn CALL 改成 `BPF_PSEUDO_KFUNC_CALL`，哪些步骤会自动适用

自动可复用的部分：

- `find_kfunc_desc_btf()` / `__find_kfunc_desc_btf()`：模块 BTF fd 解析与生命周期 pinning。
- `register_btf_kfunc_id_set()` / `btf_kfunc_flags()` / `btf_kfunc_is_allowed()`：标准 kfunc 注册和 allowlist。
- `add_kfunc_call()`：地址解析、`kallsyms_lookup_name()`、`btf_distill_func_proto()`、`kfunc_tab` 建立。
- `bpf_get_kfunc_addr()` / `bpf_jit_get_func_addr()`：标准 kfunc 地址查询入口。
- `bpf_prog_has_kfunc_call()`：自动强制 JIT。

这些正是“想统一到 kfunc CALL 路径”里最有价值的部分。

### 3.2 直接复用 `check_kfunc_call()` 会发生的冲突

冲突点不是一两个，而是结构性冲突。

1. **模块 today 没有真实 kfunc**

- 当前模块只导出 descriptor 变量，例如：
  - `module/x86/bpf_rotate.c:119`
  - `module/x86/bpf_select.c:139`
  - `module/x86/bpf_extract.c:121`
  - `module/x86/bpf_endian.c:222/230/238`
  - `module/x86/bpf_barrier.c:39`
  - arm64 对应文件同理
- 当前模块注册宏 `DEFINE_KINSN_V2_MODULE()` 只调用 `register_bpf_kinsn_set()`，见 `module/include/kinsn_common.h:126-152`。
- 代码库里没有这些目标的 `register_btf_kfunc_id_set()` 调用，也没有 `BTF_ID_FLAGS(func, ...)`。

结论：不先补真实 kfunc 符号/BTF/注册，单改 pseudo tag 连 `fetch_kfunc_meta()` 都过不去。

2. **generic kfunc 参数检查与 packed sidecar ABI 冲突**

- `check_kfunc_call()` 总会走 `check_kfunc_args()`，见 `vendor/linux-framework/kernel/bpf/verifier.c:14706-14709`。
- `check_kfunc_args()` 严格按 BTF `FUNC_PROTO` 检查 `R1-R5`，见 `vendor/linux-framework/kernel/bpf/verifier.c:13877-14421`。
- 当前 packed kinsn ABI 的真正操作数放在 sidecar payload，不是放在 `R1-R5`。

如果为了“骗过” kfunc verifier 把这些 kfunc 定义成 `void foo(void)`：

- 参数检查倒是能过
- 但 verifier 完全看不到当前 packed ABI 里 encoded 的 dst/src/shift/tmp 语义

如果把它们定义成真实参数：

- daemon 就必须把操作数 move 到 `R1-R5`
- 结果也必须从 `R0` 拿出
- 这已经不是“保持当前 sidecar ABI 不动”了

3. **generic kfunc call 会 clobber `R0-R5`**

- `check_kfunc_call()` 在 `vendor/linux-framework/kernel/bpf/verifier.c:14864-14869` 无条件清空 caller-saved regs。
- 当前 kinsn 语义来自 proof sequence，不存在统一的 `R1-R5` clobber 规则。
- `tests/unittest/rejit_kinsn.c:875+` 里甚至有 `test_rejit_barrier_preserves_r5()`，这至少说明当前语义和实现都依赖“不是普通 kfunc call clobber”。

结论：只要 kinsn 进入 `check_kfunc_call()`，就已经偏离当前 ABI/语义。

4. **`add_kfunc_call()` 会自动附带额外 gating**

- 要求 JIT 支持 kfunc call，见 `vendor/linux-framework/kernel/bpf/verifier.c:3537-3539`
- 要求 GPL-compatible，见 `vendor/linux-framework/kernel/bpf/verifier.c:3542-3545`
- kfunc allowlist 受 prog type/common hook 约束，见 `vendor/linux-framework/kernel/bpf/btf.c:8829-8894`

当前独立 kinsn 路径没有这些相同的 gating。

### 3.3 sidecar 前一条指令还能不能保留

可以保留，而且建议保留。

证据：

- UAPI 对 sidecar 的注释已经写成“for the immediately following kfunc call”，见 `vendor/linux-framework/include/uapi/linux/bpf.h:1386-1389`
- daemon `kinsn_sidecar()` 的注释也已经写成“immediately following kfunc call”，见 `daemon/src/insn.rs:263-268`

但当前代码里真正消费 sidecar 的 verifier/JIT 路径仍强绑定 `PSEUDO_KINSN_CALL`：

- `check_kinsn_sidecar_insn()` 要求下一条必须是 `PSEUDO_KINSN_CALL`，见 `vendor/linux-framework/kernel/bpf/verifier.c:21576-21593`
- `lower_kinsn_proof_regions()` / `do_misc_fixups()` / x86/arm64 JIT 都只识别 `PSEUDO_KINSN_CALL`

所以 sidecar 本身不是问题，问题是它的消费者需要统一改成识别“带 sidecar 的 kfunc 且目标被标记为 kinsn”。

### 3.4 `fixup_kfunc_call()` 会不会错误改写 kinsn CALL

会，除非显式绕开。

`fixup_kfunc_call()` 的默认行为：

- 先按 `(func_id, off)` 找 `bpf_kfunc_desc`，见 `vendor/linux-framework/kernel/bpf/verifier.c:23777-23782`
- 再把 `insn->imm` 改成 `BPF_CALL_IMM(desc->addr)`，见 `vendor/linux-framework/kernel/bpf/verifier.c:23788-23789`
- 某些特殊 kfunc 还会额外注入 patch 指令，见 `vendor/linux-framework/kernel/bpf/verifier.c:23791-23897`

而当前 x86/arm64 kinsn native emit lookup 是按“原始 `(imm, off)`”查 descriptor/payload：

- `bpf_jit_find_kinsn_desc()`：`vendor/linux-framework/kernel/bpf/verifier.c:3796-3803`
- `bpf_jit_get_kinsn_payload()`：`vendor/linux-framework/kernel/bpf/verifier.c:4111-4131`

如果让 kinsn 直接走 `fixup_kfunc_call()`，现有 keyed-by-`(imm, off)` 的 JIT lookup 就会错位。

结论：`KF_KINSN` call 必须在 `fixup_kfunc_call()` 里走单独分支，最干净的是 **直接跳过 generic kfunc fixup**。

### 3.5 JIT 中 kfunc CALL emit 路径在哪，怎么加 `KF_KINSN` 分支最干净

当前 x86/arm64 都有两条路：

- generic kfunc/helper CALL 路
- 独立 `PSEUDO_KINSN_CALL` 路

现状代码点：

- x86 generic CALL：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2483-2510`
- x86 独立 kinsn branch：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2488-2493`
- arm64 generic CALL：`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1627-1639`
- arm64 独立 kinsn branch：`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1627-1633`

最干净的改法不是保留第三条 pseudo，而是：

1. CALL 一律编码为 `PSEUDO_KFUNC_CALL`
2. 在 `PSEUDO_KFUNC_CALL` 分支内先查“该 desc 是否带 `KF_KINSN` / 是否有关联 `struct bpf_kinsn`”
3. 若是，则直接调用现有 `emit_kinsn_desc_call()` / `emit_kinsn_desc_call_arm64()`
4. 否则走原本 generic kfunc CALL

注意：

- `bpf_jit_find_kfunc_model()` 不是 x86_64 / arm64 program-call emit 的合适切点；它在这两个路径里 today 并没有承担“选择 native kinsn emit”的责任。
- 更合适的是给 x86/arm64 增一个新 helper，例如 `bpf_jit_get_kinsn_payload_from_kfunc()` 或在 `bpf_kfunc_desc` 上直接附 `const struct bpf_kinsn *kinsn`。

### 3.6 可行的统一方案

基于当前代码，**推荐方案** 是：

1. **统一 CALL 编码到 `BPF_PSEUDO_KFUNC_CALL`**
2. **模块侧补真实 kfunc FUNC 符号和 `register_btf_kfunc_id_set()`**
3. **引入内部 `KF_KINSN` 标记**
4. **让 verifier 继续对 `sidecar + KF_KINSN kfunc` 做 proof lowering**
   - 这样主 verifier 仍验证 proof sequence，而不是 generic kfunc call
5. **让 `do_misc_fixups()` 和 JIT 继续复用现有 native emit**
6. **删除独立 `BPF_PSEUDO_KINSN_CALL` / descriptor VAR registry / `kinsn_tab`**

也就是说，统一的是：

- UAPI CALL 编码
- BTF 查找对象类型（VAR -> FUNC）
- 标准 kfunc 注册与地址解析
- arch JIT 的 CALL 入口

不统一的是：

- verifier 里的 packed-ABI 语义本身

如果这层不保留，现有 kinsn 语义就会退化成“普通 kfunc 调用”，那已经不是当前 feature 了。

## 4. 具体改动清单

下面按“推荐方案”给出文件、函数、当前行号、建议动作。

### 4.1 内核侧

#### 需要删除/收敛的独立 kinsn CALL / VAR registry 基础设施

- `vendor/linux-framework/include/uapi/linux/bpf.h:1386-1394`
  - 动作：保留 `BPF_PSEUDO_KINSN_SIDECAR`
  - 动作：删除或废弃 `BPF_PSEUDO_KINSN_CALL`
  - 动作：把 sidecar 注释彻底改成“紧邻的 `PSEUDO_KFUNC_CALL`”

- `vendor/linux-framework/include/linux/bpf.h:1758-1769`
  - 动作：从 `struct bpf_prog_aux` 删除 `kinsn_tab`

- `vendor/linux-framework/include/linux/bpf.h:3095-3112`
  - 动作：删除 `bpf_free_kinsn_desc_tab()`
  - 动作：删除 `bpf_jit_find_kinsn_desc()` 的 old keyed-by-`PSEUDO_KINSN_CALL` 版本
  - 动作：保留/改造 `bpf_jit_get_kinsn_payload()`，使其从 kfunc desc 侧取 kinsn 元数据

- `vendor/linux-framework/kernel/bpf/btf.c:8978-9190`
  - 动作：删除 `register_bpf_kinsn_set()`
  - 动作：删除 `unregister_bpf_kinsn_set()`
  - 动作：删除 `btf_try_get_kinsn_desc()` 的 VAR-id registry 版本
  - 动作：用“kfunc id -> struct bpf_kinsn*”的关联替代

- `vendor/linux-framework/kernel/bpf/verifier.c:3207-3216`
  - 动作：删除独立 `struct bpf_kinsn_desc` / `struct bpf_kinsn_desc_tab`

- `vendor/linux-framework/kernel/bpf/verifier.c:3387-3403`
  - 动作：删除 `bpf_free_kinsn_desc_tab()`

- `vendor/linux-framework/kernel/bpf/verifier.c:3643-3678`
  - 动作：删除/合并 `add_kinsn_call()`
  - 建议：在 `add_kfunc_call()` 建好 `kfunc_tab` 后，顺手把 `KF_KINSN -> struct bpf_kinsn*` 也挂到 `bpf_kfunc_desc`

- `vendor/linux-framework/kernel/bpf/verifier.c:3765-3775`
  - 动作：删除 `bpf_prog_has_kinsn_call()`
  - 理由：统一后 kinsn 由 `bpf_prog_has_kfunc_call()` 自然覆盖

- `vendor/linux-framework/kernel/bpf/verifier.c:3796-3803`
  - 动作：删除 old `bpf_jit_find_kinsn_desc()`

#### 需要保留但要改识别条件的 proof lowering / restore / emit glue

- `vendor/linux-framework/kernel/bpf/verifier.c:3958-4035`
  - 函数：`lower_kinsn_proof_regions()`
  - 动作：把“识别 `PSEUDO_KINSN_CALL`”改成“识别 sidecar 后跟 `PSEUDO_KFUNC_CALL` 且目标 desc 带 `KF_KINSN`”

- `vendor/linux-framework/kernel/bpf/verifier.c:4042-4066`
  - 函数：`restore_kinsn_proof_regions()`
  - 动作：恢复的 call 也应是 `PSEUDO_KFUNC_CALL`

- `vendor/linux-framework/kernel/bpf/verifier.c:4080-4108`
  - 函数：`build_kinsn_inst_seq()`
  - 动作：descriptor 查找入口从 old `kinsn_tab` 改为 kfunc desc 侧关联

- `vendor/linux-framework/kernel/bpf/verifier.c:4111-4131`
  - 函数：`bpf_jit_get_kinsn_payload()`
  - 动作：改为从 `PSEUDO_KFUNC_CALL` + 关联 desc 取 payload/kinsn

- `vendor/linux-framework/kernel/bpf/verifier.c:23966-23993`
  - 函数：`do_misc_fixups()`
  - 动作：把“sidecar + `PSEUDO_KINSN_CALL`”改成“sidecar + `KF_KINSN` kfunc”
  - 动作：JIT native emit 时保留 sidecar+kfunc；否则替换成 proof seq

#### 需要加的 kfunc 标记/旁路

- `vendor/linux-framework/include/linux/btf.h:18-81`
  - 动作：新增内部 flag，例如 `KF_KINSN`
  - 说明：这是 internal flag，不是 UAPI

- `vendor/linux-framework/kernel/bpf/verifier.c:14632-15024`
  - 函数：`check_kfunc_call()`
  - 建议：理想情况是 **不让 `KF_KINSN` call 进入这里**
  - 保底方案：若某条漏进来，需显式报错或旁路，不能落入 generic arg/clobber 语义

- `vendor/linux-framework/kernel/bpf/verifier.c:23760-23898`
  - 函数：`fixup_kfunc_call()`
  - 动作：对 `KF_KINSN` 直接跳过 generic `imm` rewrite / special-kfunc patch

- `vendor/linux-framework/kernel/bpf/verifier.c:21576-21593`
  - 函数：`check_kinsn_sidecar_insn()`
  - 动作：若保留该 sanity check，需要接受“下一条是 `KF_KINSN` kfunc”
  - 备注：如果所有此类指令在主 verifier 前都 lowering 掉，该函数影响会变小，但仍建议同步收敛

#### JIT 收口点

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:579-606`
  - 函数：`emit_kinsn_desc_call()`
  - 动作：可直接复用，lookup source 改成 kfunc desc 侧

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2483-2510`
  - 动作：删除 `src_reg == BPF_PSEUDO_KINSN_CALL` branch
  - 动作：在 `src_reg == BPF_PSEUDO_KFUNC_CALL` 内增加 `KF_KINSN` branch

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1195-1219`
  - 函数：`emit_kinsn_desc_call_arm64()`
  - 动作：可直接复用，lookup source 改成 kfunc desc 侧

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1627-1639`
  - 动作：删除 `PSEUDO_KINSN_CALL` 分支
  - 动作：在 generic kfunc CALL 分支内增加 `KF_KINSN` 分支

#### 模块侧，当前方案无法回避的前置改动

下面这些文件不在题目“必须阅读”清单里，但如果真要落地统一方案，它们是硬前置条件：

- `module/include/kinsn_common.h:126-152`
  - 动作：把 today 只注册 `register_bpf_kinsn_set()` 的宏，改成“注册 kfunc id set + 关联 kinsn desc”

- `module/x86/bpf_rotate.c:119-128`
- `module/x86/bpf_select.c:139-148`
- `module/x86/bpf_extract.c:121-130`
- `module/x86/bpf_endian.c:222-249`
- `module/x86/bpf_barrier.c:39-49`
- `module/arm64/bpf_rotate.c:90-99`
- `module/arm64/bpf_select.c:100-109`
- `module/arm64/bpf_extract.c:85-94`
- `module/arm64/bpf_endian.c:277-304`
- `module/arm64/bpf_barrier.c:52-62`
  - 动作：新增真实 kfunc stub symbol
  - 动作：为 stub symbol 增 `BTF_ID_FLAGS(func, ..., KF_KINSN)` 之类的注册项
  - 动作：把 stub symbol 与现有 `struct bpf_kinsn` 描述符关联起来

### 4.2 daemon 侧

- `daemon/src/kfunc_discovery.rs:21-33`
  - 动作：`KNOWN_KINSNS` 从 `(registry_key, descriptor_var_name, module_name)` 改为 `(registry_key, kfunc_func_name, module_name)`

- `daemon/src/kfunc_discovery.rs:277-299`
  - 动作：从 `find_var_btf_id()` 切到 `find_func_btf_id()`
  - 备注：这个 helper 已经存在，用户态切换成本不高

- `daemon/src/kfunc_discovery.rs:343-389`
  - 动作：更新注释与日志，不再提“descriptor VAR id accepted by `PSEUDO_KINSN_CALL`”
  - 动作：发现结果改成 `BTF_KIND_FUNC` id

- `daemon/src/insn.rs:229-240`
  - 动作：废弃 `call_kinsn_with_off()`

- `daemon/src/passes/utils.rs:228-237`
  - 动作：`emit_packed_kinsn_call_with_off()` 的第二条指令改成 `call_kfunc_with_off()`
  - 建议：函数名也同步改，避免继续误导为 “kinsn call”

- `daemon/src/passes/rotate.rs:160`
- `daemon/src/passes/cond_select.rs:284`
- `daemon/src/passes/extract.rs:199`
- `daemon/src/passes/endian.rs:176/190/205`
- `daemon/src/passes/spectre.rs:91/124`
  - 动作：统一改 emit 路径到 `PSEUDO_KFUNC_CALL`

- `daemon/src/passes/rotate.rs:532/537/590`
- `daemon/src/passes/cond_select.rs:603`
- `daemon/src/passes/extract.rs:442/447/479/643/745`
- `daemon/src/passes/endian.rs:619/624/701/881/912`
- `daemon/src/passes/spectre.rs:110/114/230/339/349`
  - 动作：测试和断言从 `PSEUDO_KINSN_CALL` 改到 `PSEUDO_KFUNC_CALL`

- `daemon/src/pass.rs:68-70, 320-414`
  - 动作：注释里 “descriptor BTF / descriptor id” 术语改成 “kfunc BTF / func id”
  - 动作：数据结构本身大体可复用，`required_btf_fds` / `target_btf_fds` / `fd_array` 语义不需要根改

- `daemon/src/commands.rs:184-189`
  - 动作：更新注释
  - 说明：slot 0 / 1-based module BTF slot 逻辑在 kfunc 路径下仍成立

### 4.3 测试侧

- `tests/unittest/rejit_kinsn.c:188-196`
  - 动作：`BPF_CALL_KINSN()` 宏改成 kfunc CALL 宏

- `tests/unittest/rejit_kinsn.c:532-603`
  - 动作：`find_var_btf_id()` 改成 `find_func_btf_id()`

- `tests/unittest/rejit_kinsn.c:672-715`
  - 动作：discovery 逻辑改成发现 `FUNC id`

- `tests/unittest/rejit_kinsn.c:730-754`
  - 动作：patch helper 从 `PSEUDO_KINSN_CALL` 改成 `PSEUDO_KFUNC_CALL`

- `tests/unittest/rejit_kinsn.c:846-872`
  - 动作：测试输出和失败消息从 “descriptor BTF id” 改成 “kfunc BTF id”

## 5. 改动量估算

以下是 **结构性估算**，不是实做后的精确 diff。

### 5.1 以当前 `vendor/linux-framework` 相对本地 `origin/master` 为基线

当前 kinsn 相关 kernel diff 现状：

- 命令基线：`git -C vendor/linux-framework diff --shortstat origin/master...HEAD -- include/uapi/linux/bpf.h include/linux/bpf.h include/linux/btf.h kernel/bpf/verifier.c kernel/bpf/core.c kernel/bpf/btf.c arch/x86/net/bpf_jit_comp.c arch/arm64/net/bpf_jit_comp.c`
- 结果：`8 files changed, 1135 insertions(+), 37 deletions(-)`

推荐统一方案的粗估：

- 内核 8 文件净新增大概率会 **下降**，因为：
  - `BPF_PSEUDO_KINSN_CALL`
  - `kinsn_tab`
  - `register_bpf_kinsn_set()/unregister/try_get`
  - `add_kinsn_call()/bpf_prog_has_kinsn_call()/独立 JIT dispatch`
  这批“并行基础设施”会被删除/折叠
- 但模块侧会新增真实 kfunc stub + 注册 glue

保守估算：

- kernel 8-file diff：大致会从 `+1135/-37` 收敛到 `+850~950 / -80~140`
- 也就是相对当前 `rejit-v2`，**内核侧净减少约 150~260 行新增规模**
- repo 总体（含 `module/daemon/tests`）改动量不会小，但“架构噪音”会明显减少

## 6. 风险评估

### 6.1 风险矩阵

| 风险项 | 概率 | 影响 | 依据 | 缓解 |
| --- | --- | --- | --- | --- |
| 333 daemon tests 直接回归 | 高 | 高 | 多个 pass/unit test 直接断言 `PSEUDO_KINSN_CALL` 和 descriptor VAR id | 必须同步改 emit/discovery/tests |
| vm-selftest 70/70 回归 | 高 | 高 | `tests/unittest/rejit_kinsn.c` 明确依赖 descriptor VAR id、`PSEUDO_KINSN_CALL` | 同步改 unittest 和 VM selftest 预期 |
| sidecar 被 verifier/JIT 误判或丢弃 | 中高 | 高 | today 只有 `PSEUDO_KINSN_CALL` 消费 sidecar | 统一改 sidecar consumer；对 `KF_KINSN` 做单独 helper |
| generic `check_kfunc_call()` 语义泄漏到 kinsn | 高 | 高 | 参数检查 + `R0-R5` clobber 与 packed ABI 冲突 | 继续走 proof lowering 旁路，不让它进入 generic kfunc verifier |
| `fixup_kfunc_call()` 改写 `imm` 破坏 native emit lookup | 高 | 高 | today JIT payload lookup keyed by `(imm, off)` | 对 `KF_KINSN` 跳过 generic kfunc fixup |
| GPL/prog-type gating 行为变化 | 中高 | 中高 | `add_kfunc_call()` / `btf_kfunc_is_allowed()` 会自动生效 | 明确使用 `BPF_PROG_TYPE_UNSPEC` common hook 或重新评估策略 |
| 非 x86/arm64 fallback 丢失 | 中 | 中高 | today proof seq fallback 允许无 native emit 架构工作 | 保留 proof lowering/fixup fallback |
| module 生命周期回归 | 低中 | 中 | today 依赖 `kfunc_btf_tab` pin module BTF，`btf_try_get_kinsn_desc()` 只要求 owner 一致 | 统一到标准 kfunc 后，生命周期通常更简单，不应更差 |

### 6.2 对题目中四个具体风险问题的回答

#### 1. 会不会破坏现有 333 daemon tests

会，如果只改 kernel 不改 daemon/tests，几乎必坏。

原因不是推测，是代码硬编码：

- `daemon/src/passes/*` 多处断言/筛选 `src_reg == BPF_PSEUDO_KINSN_CALL`
- `daemon/src/kfunc_discovery.rs` today 明确找的是 descriptor `VAR`
- `daemon/src/passes/utils.rs:228-237` today 就是 emit sidecar + `call_kinsn_with_off()`

如果 kernel/daemon/tests 一起改，非 kinsn 相关 daemon tests 大概率不受影响；但直接相关的 kinsn pass/unit tests 需要整体更新。

#### 2. 会不会破坏 vm-selftest（70/70）

会，如果不同时更新 `tests/unittest/rejit_kinsn.c`。

依据：

- `tests/unittest/rejit_kinsn.c:188-196` 宏直接编码 `PSEUDO_KINSN_CALL`
- `tests/unittest/rejit_kinsn.c:532-715` discovery 直接找 descriptor `VAR`
- `tests/unittest/rejit_kinsn.c:730-754` patch helper 直接改 `PSEUDO_KINSN_CALL`

这里不是“可能”，而是 ABI 一变必改。

#### 3. sidecar 编码在 kfunc 路径下会不会被意外修改/丢弃

有风险，但可控。

风险来源：

- current sidecar consumer 只认 `PSEUDO_KINSN_CALL`
- generic kfunc fixup/JIT 路不会自动保留 sidecar 语义

控制方法：

- sidecar 保持独立 pseudo，不进入 generic ALU 语义
- `lower_kinsn_proof_regions()` / `do_misc_fixups()` / `bpf_jit_get_kinsn_payload()` 全部改成 “sidecar + `KF_KINSN` kfunc” 识别
- `fixup_kfunc_call()` 对 `KF_KINSN` 直接跳过

#### 4. module 加载/卸载生命周期是否受影响

大概率不会更差，甚至会更简单。

依据：

- today 模块 BTF 生命周期已经由 `__find_kfunc_desc_btf()` 里的 `btf_try_get_module()` + `kfunc_btf_tab` 管住，见 `vendor/linux-framework/kernel/bpf/verifier.c:3301-3371`
- `btf_try_get_kinsn_desc()` 自己并不额外 pin 第二份 module ref，它依赖“descriptor owner 与 module BTF owner 一致”，见 `vendor/linux-framework/kernel/bpf/btf.c:9170-9173`

如果统一到真实 kfunc registration：

- 模块入口更标准
- 生命周期语义更接近现有 upstream kfunc 模型

真正的风险不是生命周期，而是“过渡期若双注册并存，容易把两套 lookup 保持太久”。

## 7. 上游接受性

### 7.1 reviewer 现在会看到什么

当前 reviewer 看到的是：

- 新 UAPI pseudo：`BPF_PSEUDO_KINSN_CALL`
- 新内核并行注册表：`register_bpf_kinsn_set()`
- 新 verifier 并行 desc tab / lowering / restore
- 新 arch JIT 并行 dispatch hook

这很容易被评价为“在 kfunc 旁边又造了一条平行子系统”。

### 7.2 推荐统一后 reviewer 会看到什么

如果按本报告推荐方案实现，reviewer 看到的是：

1. CALL 编码统一回标准 `BPF_PSEUDO_KFUNC_CALL`
2. 模块目标统一成标准 kfunc `FUNC` + `register_btf_kfunc_id_set()`
3. sidecar 作为 kinsn packed ABI 附件保留
4. verifier 只有一个额外特例：`KF_KINSN` kfunc 在主 verifier 前做 proof lowering
5. x86/arm64 只在已有 kfunc CALL 路里多一个 `KF_KINSN` 分支

这比当前方案更像“kfunc 的特化扩展”，而不是“独立第二套调用系统”。

### 7.3 与主线新增行数的含义

基于本地 `origin/master...rejit-v2` 统计，当前这 8 个 kernel 文件的 delta 是：

- `+1135 / -37`

统一后，预计内核新增行数会下降，但不会降到零，因为仍需保留：

- sidecar pseudo
- `struct bpf_kinsn`
- proof lowering glue
- x86/arm64 native emit glue

也就是说，统一方案不是“完全回到 upstream 零 diff”，而是把 **“独立 kinsn CALL/VAR registry 的 diff”** 收缩成 **“kfunc 框架上的一个内部扩展 diff”**。

## 8. 最终建议

### 建议结论

不建议做“字面 pseudo-tag-only 改动”。

原因：

- 当前模块没有真实 kfunc
- 当前 verifier 语义不是 generic kfunc 语义
- 当前 JIT lookup 依赖 `PSEUDO_KINSN_CALL` 的 `(imm, off)` 约定

### 推荐实施路径

建议按下面 3 步做，而不是一次性硬切：

1. **先做模块/daemon/BTF id 统一**
   - 模块补真实 kfunc stub + `register_btf_kfunc_id_set()`
   - daemon discovery 从 `VAR` 切到 `FUNC`
   - daemon emit 从 `PSEUDO_KINSN_CALL` 切到 `PSEUDO_KFUNC_CALL`

2. **再做 verifier/JIT 旁路**
   - 引入 `KF_KINSN`
   - proof lowering / fixup / native emit 都改成识别 `KF_KINSN kfunc`
   - 不让 `KF_KINSN` 落入 generic `check_kfunc_call()` / `fixup_kfunc_call()`

3. **最后删除旧并行基础设施**
   - `BPF_PSEUDO_KINSN_CALL`
   - `register_bpf_kinsn_set()` / `btf_try_get_kinsn_desc()` old VAR registry
   - `kinsn_tab`
   - arch 独立 `PSEUDO_KINSN_CALL` dispatch

### 一句话判断

“统一到 kfunc CALL 路径”这件事本身是可行且值得做的；但 **必须统一的是“注册/查找/地址解析/编码入口”**，而不是把当前 packed kinsn 直接塞进 generic kfunc verifier 语义。

如果目标是保留现有 sidecar ABI、proof-seq verifier 语义和 native emit 回调，那么正确实现是 **kfunc 化 transport，保留 kinsn 旁路语义**。
