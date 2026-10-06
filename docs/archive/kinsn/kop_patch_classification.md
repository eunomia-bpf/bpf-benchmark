# kop-only Branch Patch Classification

**目标**: 从 `vendor/linux-framework` 的 `rejit-v2` 分支(42 commits, +2140/-150)中剥离 BPF_PROG_REJIT 全部 kernel patch,只保留 kop(in-kernel kfunc emit / verifier modeling / arch JIT emit)。剩余性能优化走 userspace path,详见 `userspace_speculative_opt_design.md`。

**Baseline**: `c23719abc33` (merge-base with master, Linux 7.0-rc 系列)

## 总分类(按文件,基于 final-state diff)

### 整文件 DROP(0 kop 引用,纯 REJIT)

| 文件 | LOC | 内容 |
|------|-----|------|
| `kernel/bpf/syscall.c` | +965 | 整组 `bpf_prog_rejit_*` 函数:supported / update_poke_tab / untrack_tmp_pokes / poke_target_phase / swap / prepare_rollback / restore_rollback / release_rollback / rollback / bpf_prog_rejit (主入口) / get_subprog / expose_subprog_metadata。每个新加函数都是 REJIT。 |
| `kernel/bpf/bpf_struct_ops.c` | +160 | struct_ops multi-site refresh + rollback,REJIT 配套 |
| `kernel/bpf/trampoline.c` | +60 | REJIT 用的 trampoline refresh |
| `kernel/bpf/arraymap.c` | +17 | `prog_array_map_poke_run` void→int 改 + `bpf_arch_poke_desc_update` 错误返回路径,REJIT 替换 PROG_ARRAY tail-call target 用的 |
| `kernel/bpf/dispatcher.c` | +23 | `bpf_dispatcher_update` 加 `expedited` 参数 + `bpf_dispatcher_refresh_prog`,REJIT 后刷新 dispatcher image |
| `kernel/bpf/core.c` | +2 | `rejit_mutex` + `trampoline_users` list 初始化 |
| `net/core/filter.c` | +5 | `bpf_prog_refresh_xdp` wrapper(REJIT 用) |

### 整文件 KEEP(纯 kop)

| 文件 | LOC | 内容 |
|------|-----|------|
| `include/linux/btf.h` | +2 | `struct bpf_kop` forward decl + `kop_descs` 字段进 `btf_kfunc_id_set` |
| `include/linux/bpf_verifier.h` | +21 | `INSN_BUF_SIZE 32→256`(kop bulk-memory 展开需要) + `struct bpf_kop_region` + verifier env 里 `kop_regions/kop_call_cnt/kop_region_cnt/kop_region_cap` + `btf_kfunc_kop_desc` 声明 |
| `kernel/bpf/disasm.c` | +2 | `BPF_PSEUDO_KOP_CALL` 反汇编识别 |
| `kernel/bpf/btf.c` | +156 | kop kfunc descriptor 注册路径,btf_kfunc_id_set 携带 kop 元数据,`btf_kfunc_kop_desc()` 实现。grep 验证:0 处 REJIT/orig_prog/poke_desc 字样 |

### 整文件 SURGERY(混合)

| 文件 | LOC | 边界规则 |
|------|-----|----------|
| `include/uapi/linux/bpf.h` | +24 | **KEEP**: `BPF_PSEUDO_KOP_SIDECAR`, `BPF_PSEUDO_KOP_CALL` 两个常量。**DROP**: `BPF_PROG_REJIT` cmd enum 项、`rejit` struct 进 `union bpf_attr`、`orig_prog_len`/`orig_prog_insns` 进 `bpf_prog_info` |
| `tools/include/uapi/linux/bpf.h` | +24 | 同上(纯 mirror) |
| `include/linux/bpf.h` | +77 | **KEEP**: `struct bpf_kop` 定义、`bpf_kop_has_native_emit` / `bpf_kop_is_sidecar_insn` / `bpf_kop_sidecar_payload` inline、`bpf_jit_get_kop_payload` 声明 (含 EOPNOTSUPP stub)。**DROP**: `map_poke_run` void→int 改、`bpf_dispatcher_refresh_prog` 声明、`bpf_trampoline_refresh_prog` 声明、`bpf_prog_aux` 里 `rejit_mutex/trampoline_users/prog_flags/orig_insns/orig_prog_len` 字段、`bpf_struct_ops_refresh_prog` 声明、`bpf_arch_poke_desc_update` void→int 改 |
| `include/linux/filter.h` | +7 | **DROP all**: `bpf_func = smp_load_acquire(&prog->bpf_func)`(REJIT atomic swap 用)、`bpf_prog_refresh_xdp` 声明。kop 不需要任何 filter.h 改动 |
| `kernel/bpf/verifier.c` | +566 | **大头 surgery**。详见下方 hunk 表。kop 改动集中在:`add_kfunc_call` 路径(识别 kop kfunc)、`fetch_kfunc_meta`、kop region 跟踪、do_misc_fixups 把 kop sidecar 插入。**DROP**: 任何 REJIT 用的 `orig_insns` 保存、`prog_flags` 替换、`bpf_check` 末尾 REJIT clone 路径 |
| `arch/x86/net/bpf_jit_comp.c` | +125 | **KEEP**: `emit_call` 里 kop-call handling、`detect_reg_usage` 扩展(kop 占用 reg)、kop 主 emit dispatch。**DROP**: `bpf_arch_poke_desc_update` 签名改 + 返回 -EOPNOTSUPP 改造 |
| `arch/arm64/net/bpf_jit_comp.c` | +54 | **KEEP**: `add_exception_handler` kop 路径、`build_insn` kop dispatch。整体 +54 几乎全是 kop(ARM64 stock kernel 没有 poke_desc,所以不掺和) |

## 验证脚本(可重跑)

```bash
cd vendor/linux-framework
git diff c23719abc33..rejit-v2 -- kernel/bpf/syscall.c     | grep -E '^\+' | grep -c 'kop'   # 期望 0
git diff c23719abc33..rejit-v2 -- kernel/bpf/btf.c          | grep -E '^\+' | grep -cE 'rejit|REJIT'  # 期望 0
git diff c23719abc33..rejit-v2 -- kernel/bpf/disasm.c       | grep -E '^\+' | grep -cE 'rejit|REJIT'  # 期望 0
git diff c23719abc33..rejit-v2 -- include/linux/bpf_verifier.h | grep -E '^\+' | grep -cE 'rejit|REJIT' # 期望 0
```

## verifier.c hunk 级 surgery 表

行号是 final-state diff 的 `@@ -<old>,N +<new>,M @@` 头。

| Hunk @@ | 区域 | 处理 | 说明 |
|---------|------|------|------|
| `-272,6 +272,12` | `bpf_pseudo_kfunc_call` 附近 | KEEP | kop pseudo 识别 |
| `-301,6 +307,1` | `bpf_call_arg_meta` 扩展 | KEEP | kop metadata 入参 |
| `-3172,6 +3179,1` | exception callback search | KEEP | kop 跳过逻辑 |
| `-3199 / -3211 / -3257` | kfunc_btf_tab/kfunc_desc | KEEP | kop 共享 kfunc 注册管线 |
| `-3422 / -3429 / -3441 / -3470 / -3498` | `add_kfunc_call` 多 hunk | KEEP | kop-call 分支 |
| `-3536 / -3558 / -3577,267` | kfunc desc sort + kop region 表初始化 | KEEP | +267 行是 kop region tracking 主体 |
| `-3605 / -3620 / -3636` | `add_subprog_and_kfunc` | KEEP | |
| `-4162 / -4409` | `get_prev_insn_idx`、`backtrack_insn` | **TBD** | 看是否提到 orig_insns / rejit;若提到则 DROP,否则 KEEP |
| `-21029` | `check_indirect_jump` +23 | **TBD** | 看是否 kop 还是 REJIT |
| `-21098 / -21123` | `do_check_insn` 两处 | KEEP | kop region/proof 模型 |
| `-23066 / -23080` | `fixup_call_args` | KEEP | kop fixup |
| `-23386,50` | `do_misc_fixups` +50 大块 | KEEP | kop sidecar 插入 |
| `-23695` | `do_misc_fixups` 尾 | KEEP | |
| `-25988 / -25999 / -26061 / -26194` | `bpf_check` 末尾几处 | **TBD** | REJIT 在 bpf_check 末尾保存 orig_insns 的逻辑要 DROP;kop 注册要 KEEP |

TBD 行的最终决定在实际打 patch 时,基于 hunk 内容是否提到 `orig_insns`/`rejit_mutex`/`prog->aux->prog_flags` 等关键字判定。

## 推荐执行路径

1. 用 final-state squashed diff 比 per-commit surgery 简单——因为 42 个 commit 里大量是 "add 后又 remove" 的折返。
2. 从 baseline `c23719abc33` 起新分支 `kop-only`。
3. 逐文件构造 curated patch:
   - 7 个 wholesale-drop 文件:直接跳过
   - 4 个 wholesale-keep 文件:`git diff baseline..rejit-v2 -- <file>` 直接 pipe 到 patch
   - 7 个 surgical 文件:手动编辑 diff
4. 单个 `git apply` 落地,然后 `git commit -s -m "bpf: kop-only kernel support"` (用户自己提交)。
5. `make -C build-x86 -j$(nproc) bzImage modules` 验证编译。

## 历史 commit → 处置映射(参考,正式 surgery 用 squashed 方式)

| commit | subject | 处置 |
|--------|---------|------|
| `a3173b11969` | inline kfunc emit poc | KEEP (kop 前身,后被 0014 替换) |
| `36e41e7a04d` | expose original prog insns | DROP |
| `4d46ee60994` | minimal prog rejit syscall | DROP |
| `a11b37a2e97` | prog rejit poc selftest | DROP |
| `6e8c03dc3cf` | relax rejit metadata guard | DROP |
| `4bcbc8e21d6` | kernel POC fixes (maps/kfunc/mutex) | MIXED — maps/kfunc 部分 KEEP,mutex(rejit_mutex)DROP |
| `1d040ec0c3f` | REJIT Phase 0-2 + ARM64 inline kfunc + selftest | MIXED — ARM64 kop KEEP,REJIT phase fixes DROP |
| `21c1b1f8915` | multi-subprog REJIT support | DROP |
| `0b2d749c2e2` | code review + st_ops REJIT | DROP |
| `e7d27ef3731` | tail_call REJIT support + EXT/freplace | DROP |
| `f4be5f31b61` | deadlock fix in rejit poke_target_phase | DROP |
| `b4bd737efc9` | 4 kernel bugs (rejit deadlock 等) | DROP |
| `8a692389396` | memory leaks + struct_ops multi-slot + UAPI | DROP |
| `20831c82d41` | **kop: implement bpf_kop_ops** | KEEP (kop 核心) |
| `c03cf516d7f` | Remove docs from kernel tree | DROP (清理,新分支不需要) |
| `cefee264889` | CRITICAL/HIGH review fixes | MIXED — kop fixes KEEP,REJIT fixes DROP |
| `cb82fae354a` | Update BTF handling + remove inline kfunc tests | KEEP (kop 演进) |
| `cb06f790849` | Refactor kop + verifier region | KEEP |
| `f503d95d837` | Enhance kop structures | KEEP |
| `78cb12db28a` | REJIT EXT/dst_prog enhancement | DROP |
| `756c12548a3` | Remove unused kop structures | KEEP |
| `03cad914536` | Refactor kop → kfunc unification | KEEP |
| `494c8de8ddc` | Remove unused kop structures | KEEP |
| `307d063b715` | Remove unused kop functions | KEEP |
| `b8fa3a48a12` | btf_kfunc_kop_desc | KEEP |
| `b6ee495d6cd` | Remove unused kfunc_desc_tab | MIXED — kop cleanup KEEP,syscall.c 触及 DROP |
| `f0e7f673ee8` | Remove unused kop functions + filter.h | KEEP (filter.h 部分只是 kop cleanup,不是 smp_load_acquire) |
| `2d3c5adb3c4` | Refactor trampoline + signatures | MIXED — kop KEEP,trampoline (REJIT) DROP |
| `1268862b9d3` | REJIT swap fields + struct_ops refresh safety | DROP |
| `9be94921f39` | native emit check for kop + verifier | MIXED — kop check KEEP,syscall.c 部分 DROP |
| `b43e757f528` | rejit kallsyms double-delete fix | DROP |
| `07351111679` | struct_ops multi-site refresh + rollback | DROP |
| `8d1f1784ae5` | remove rejit_test debugfs | DROP (清理,新分支不需要) |
| `81608ed9edb` | 4 review issues (insn_buf, callchain_buf, ARM64 scratch) | MIXED — ARM64 scratch (kop) KEEP,REJIT bits DROP |
| `c0938be8614` | 3 review issues (poke_tab rollback, trampoline_users) | DROP |
| `b07468207ab` | verifier patch buffer restore | **TBD** — 是 kop 还是 REJIT 用,看 hunk |
| `0725c44fd23` | Relax REJIT poke table insn index | DROP |
| `a1b8bade169` | refactor reg usage detection | MIXED — 看是 kop 用还是 REJIT 用,x86 only,可能 KEEP |
| `37166911e47` | drop EXT-only restriction on REJIT func_info | DROP |
| `81cb8848bac` | poke desc update BUG_ON → error return | DROP |
| `aff50541931` | simplify kop proof sequence | KEEP |

## 预期最终 LOC

- KEEP 净 LOC ≈ 800-1000 行(kop 实现 + verifier modeling + arch JIT emit + btf 注册)
- DROP 净 LOC ≈ 1300-1500 行(REJIT + GET_ORIGINAL + struct_ops refresh + dispatcher refresh + arraymap poke updates)
- 相比当前 +2140,kop-only 缩到 ~40% 体量

这个体量在 paper 里更可主张 "minimal kernel additions",并且基本不会引入 REJIT 那些 race / rollback / kallsyms / poke 边界 bug。
