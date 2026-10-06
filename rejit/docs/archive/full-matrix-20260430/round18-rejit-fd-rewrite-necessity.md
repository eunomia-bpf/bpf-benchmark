# Round 18: BPF_PROG_REJIT fd rewrite necessity

## 一句话结论

**在当前 vendor/linux-framework 的 `BPF_PROG_REJIT` ABI 下，daemon 端某种 map fd 重新绑定是必要的；但当前 `PSEUDO_MAP_FD` first-seen 重写方式不是理想 ABI 的必然形态，而是为了适配现有 verifier 仍按当前进程 fd / `fd_array` 解析 map 的实现。**

如果不改 kernel，不能把 ReJIT 简化成只传 `prog_id + new_bytecode`。最多可以把 daemon 内部 bytecode 预先归一化成 `PSEUDO_MAP_IDX(_VALUE)`，并把 imm 设为实际 ReJIT `fd_array` 下标，从而移除每次 ReJIT 前的 `relocate_map_fds_for_rejit()`；但仍要打开 map fd、传 `fd_array`，并且仍要做一次从原始 loader fd 到 map 下标的归一化。

## 读码范围

- `kernel/bpf/syscall.c`: `BPF_PROG_REJIT` 入口、swap、`orig_insns` 保存和导出。
- `kernel/bpf/verifier.c`: `bpf_check()`、`process_fd_array()`、`resolve_pseudo_ldimm64()`、module kfunc/kinsn BTF 解析。
- `daemon/src/bpf.rs`: `relocate_map_fds_for_rejit()`。
- `daemon/src/commands.rs`: `rejit_program()`、`build_rejit_fd_array()`。
- `bpfopt/crates/kernel-sys/src/lib.rs`: `prog_rejit()` attr 包装、`prog_get_original()`。
- `daemon/crates/bpfget/src/lib.rs`: snapshot bytecode / map_ids / target BTF probing。

## Q1: REJIT 怎么处理 PSEUDO_MAP_FD / IDX

当前 `BPF_PROG_REJIT` 实现会完整调用 verifier，不是只换 JIT image。

`kernel/bpf/syscall.c` 的 `bpf_prog_rejit()` 做了这些事：

- 从 `attr->rejit.prog_fd` 取旧 `prog`，锁 `prog->aux->rejit_mutex`。
- 构造一个新的 `load_attr`，把旧程序的 `prog_type`、`expected_attach_type`、`prog_flags` 复制进去，把用户传入的 `insns/log/fd_array_cnt` 填进去。
- 如果用户传了 `fd_array` 且 `fd_array_cnt > 0`，复制成内核内存 `kfd_array`，再把 `load_attr.fd_array` 指向这个内核数组。
- 分配临时 `tmp` program，复制 REJIT bytecode 到 `tmp->insns`，并把这份提交字节码原样保存到 `tmp->aux->orig_insns`。
- 调用 `bpf_check(&tmp, &load_attr, KERNEL_BPFPTR(&load_attr), BPF_PROG_REJIT_LOAD_ATTR_SIZE)`。

关键代码点：

- `load_attr.fd_array_cnt = attr->rejit.fd_array_cnt`: `kernel/bpf/syscall.c:3644`
- 复制 `attr->rejit.fd_array` 到 `kfd_array`: `kernel/bpf/syscall.c:3646-3662`
- 复制 REJIT bytecode 到 `tmp->insns`: `kernel/bpf/syscall.c:3692-3695`
- 保存原样 `tmp->aux->orig_insns`: `kernel/bpf/syscall.c:3697-3703`
- 调用 verifier: `kernel/bpf/syscall.c:3760-3761`
- swap 时把 `used_maps` 从 `tmp` 换到 live `prog`: `kernel/bpf/syscall.c:3420-3421`

所以 REJIT 的 map 解析路径就是 normal verifier 路径。`tmp->aux->used_maps` 没有在进入 verifier 前从旧 `prog->aux->used_maps` 复制。旧程序的 attach/dst/BTF 一部分 metadata 会复制给 `tmp`，但 `used_maps` 不复制。

`PSEUDO_MAP_FD` 的解析在 `resolve_pseudo_ldimm64()` 中完成：

- `PSEUDO_MAP_FD` / `PSEUDO_MAP_VALUE`: `fd = insn[0].imm`
- `PSEUDO_MAP_IDX` / `PSEUDO_MAP_IDX_VALUE`: 从 `env->fd_array[insn[0].imm]` 读 fd
- 然后统一走 `add_used_map(env, fd)`
- `add_used_map()` 用当前进程 fd table 里的 fd 取 `struct bpf_map *`，失败就报 `fd N is not pointing to valid bpf_map`

关键代码点：

- `add_used_map()` 通过 fd 取 map: `kernel/bpf/verifier.c:22088-22099`
- `PSEUDO_MAP_IDX` 要求 `env->fd_array` 非空并从 `fd_array` 读 fd: `kernel/bpf/verifier.c:22176-22187`
- `PSEUDO_MAP_FD` 直接使用 `insn[0].imm`: `kernel/bpf/verifier.c:22188-22190`
- map 加入 `env->used_maps`: `kernel/bpf/verifier.c:22193-22199`
- `bpf_check()` 最后把 `env->used_maps` 复制到 `env->prog->aux->used_maps`: `kernel/bpf/verifier.c:26551-26565`

结论：当前 kernel 没有“REJIT-only 跳过 map fd 解析，直接使用旧 `prog->aux->used_maps[]`”的路径。要让它跳过解析，必须改 kernel。

## Q2: PSEUDO_MAP_IDX 的 imm 含义

当前 verifier 中，`PSEUDO_MAP_IDX` 的 `imm` 是 **`attr.fd_array` 下标**，不是 `prog->aux->used_maps` 下标。

证据是 `resolve_pseudo_ldimm64()` 对 `BPF_PSEUDO_MAP_IDX(_VALUE)` 的处理：

```c
copy_from_bpfptr_offset(&fd, env->fd_array,
                        insn[0].imm * sizeof(fd),
                        sizeof(fd))
```

也就是 `imm` 直接乘 `sizeof(int)` 去 `env->fd_array` 取 fd。它不读 `prog->aux->used_maps`，也不读 `env->used_maps[imm]`。

这对 `BPF_PROG_LOAD` 和 `BPF_PROG_REJIT` 一样成立，因为 REJIT 是把 `attr->rejit.fd_array` 包成 `load_attr.fd_array` 后调用同一个 `bpf_check()`。

额外细节：

- `process_fd_array()` 在 `fd_array_cnt > 0` 时会预扫描整个 `fd_array`，把每个 map fd 加进 `env->used_maps`，把每个 BTF fd 加进 `env->used_btfs`。
- 这个预扫描只影响绑定和 refcount，不改变 `PSEUDO_MAP_IDX` 的索引语义。
- 如果 `fd_array` 前面有 module BTF fd，map 的 `PSEUDO_MAP_IDX` imm 必须按 **完整 fd_array** 下标计算，而不是 map-only 下标。

这解释了 daemon 当前为什么把 IDX lowering 成 FD：`build_rejit_fd_array()` 把 BTF module fd 放在前缀，map fd 放在后面；如果 candidate 里保留 map-only IDX=0，而完整 `fd_array[0]` 是 BTF placeholder，verifier 会把 BTF fd 当 map fd 解析并失败。

## Q3: verifier 能区分 new map vs existing map 吗

不能。当前 REJIT verifier 只看到：

- 新提交的 bytecode
- 当前 syscall 进程 fd table 中的 fd
- 当前 syscall 传入的 `fd_array`
- 少量从旧 `prog->aux` 复制到 `tmp->aux` 的 attach/dst/BTF metadata

它没有拿旧 `prog->aux->used_maps` 作为“允许列表”，也没有检查新 `env->used_maps` 必须等于旧 `prog->aux->used_maps`。

因此：

- 如果 candidate 用 `PSEUDO_MAP_FD` 引用了一个 daemon 当前进程里有效、兼容的 map fd，verifier 会把它加入新 `tmp->aux->used_maps`。
- 如果 candidate 用 `PSEUDO_MAP_IDX` 引用了 `fd_array` 里的一个 map fd，也会加入新 `tmp->aux->used_maps`。
- 通过 verifier 后，swap 会把 live `prog->aux->used_maps` 换成 `tmp->aux->used_maps`。

也就是说当前 ABI 实际允许 REJIT 改变 map set，至少 generic map 解析层没有禁止。某些运行时结构仍有额外约束，例如 direct tail call 的 `poke_tab` 会比较 old/new `tail_call.map` 和 key，变了会失败；但这不是一个通用的 “map set must equal old used_maps” 检查。

`fd_array_cnt > 0` 的另一个效果是：`fd_array` 里的 map 会被绑定到 program，即使 bytecode 没直接引用。UAPI 注释也明确说 `fd_array_cnt` 会把所有 map fd 绑定到 program，即使不被直接引用：`include/uapi/linux/bpf.h:1640-1647`。daemon 当前传入所有旧 `map_ids` 打开的 fd，所以即使某个 pass 删除了最后一次 map 引用，`tmp->aux->used_maps` 仍会包含那些 map。这是在当前 ABI 下维持“old maps 不消失”的手段，而不是旧 `used_maps` 自动复用。

## Q4: PSEUDO_MAP_* 数据流 trace

daemon 端：

1. `bpfget::snapshot_program()` 打开 prog fd，读取 `prog_get_original()`，再读取 `prog_info.map_ids`：`daemon/crates/bpfget/src/lib.rs:126-140`。
2. `build_rejit_fd_array()`：
   - module kinsn BTF fd 按 `call_offset` 放进 `fd_array` 前缀。
   - 如果有 module BTF，`fd_array[0]` 放第一个 module BTF fd 的 duplicate placeholder。
   - map fd 按 `map_ids` 顺序 append：`daemon/src/commands.rs:1466-1590`。
3. `rejit_program()` 复制 candidate，调用 `relocate_map_fds_for_rejit()`，然后把 relocated insns 和完整 `fd_array` 传给 `kernel_sys::prog_rejit()`：`daemon/src/commands.rs:368-392`。
4. `kernel_sys::prog_rejit()` 把 `prog_fd/insn_cnt/insns/log/fd_array/fd_array_cnt` 填进 `AttrRejit`，发 `BPF_PROG_REJIT` syscall：`bpfopt/crates/kernel-sys/src/lib.rs:46-58`、`1390-1501`。

kernel syscall 端：

1. `bpf_prog_rejit()` 从 `attr->rejit.fd_array` 复制 int 数组到 `kfd_array`。
2. 构造 `load_attr.fd_array = kfd_array`、`load_attr.fd_array_cnt = attr->rejit.fd_array_cnt`。
3. 分配 `tmp`，复制 candidate 到 `tmp->insns`，保存 `tmp->aux->orig_insns`。
4. 调用 `bpf_check()`。

verifier 端：

1. `bpf_check()` 先调用 `process_fd_array()`：`kernel/bpf/verifier.c:26383`。
2. `process_fd_array()` 在 `fd_array_cnt > 0` 时扫描完整 `fd_array`：
   - map fd: `__add_used_map(env, map)`
   - BTF fd: `__add_used_btf(env, btf)`
   - 其它 fd: reject
   代码：`kernel/bpf/verifier.c:25835-25895`
3. `add_subprog_and_kfunc()` 处理 kfunc/kinsn call。对 module BTF 的 call，`insn->off > 0` 会在后续 `find_kfunc_desc_btf()` 中从 `fd_array[off]` 取 module BTF fd：`kernel/bpf/verifier.c:3273-3315`、`3348-3359`。
4. `resolve_pseudo_ldimm64()` 解析 map pseudo ldimm64：`kernel/bpf/verifier.c:26437`、`22109-22225`。

四种 map pseudo mode：

| pseudo mode | fd 来源 | `insn[1].imm` | 当前 REJIT 要求 |
|---|---|---:|---|
| `BPF_PSEUDO_MAP_FD` | `insn[0].imm` 直接当当前进程 map fd | 必须为 0 | daemon 必须把 loader fd 改成 daemon fd，或者原始 fd 恰好在 daemon fd table 中有效 |
| `BPF_PSEUDO_MAP_VALUE` | `insn[0].imm` 直接当当前进程 map fd | map value offset | 同上，并且 map 类型必须支持 direct value addr |
| `BPF_PSEUDO_MAP_IDX` | `fd_array[insn[0].imm]` | 必须为 0 | 必须传 `fd_array`，imm 是完整 fd_array 下标 |
| `BPF_PSEUDO_MAP_IDX_VALUE` | `fd_array[insn[0].imm]` | map value offset | 必须传 `fd_array`，imm 是完整 fd_array 下标，并且 map 支持 direct value addr |

## Q5: 理想 REJIT 设计 vs 当前实现

用户直觉里的理想 ABI 是：

```rust
prog_rejit(prog_fd, new_bytecode)
```

语义是：原 live program 的 maps / BTF / attach context / used_maps 都不变，新 bytecode 中的 map reference 只是引用旧 `used_maps` 的 slots。

当前 kernel 不是这个 ABI。当前 kernel 的实际 ABI 是：

```text
prog_fd + new bytecode + optional fd_array
    -> 构造 tmp prog
    -> 完整 bpf_check()
    -> verifier 重新从 fd / fd_array 解析 maps 和 module BTF
    -> tmp->aux->used_maps / used_btfs 成为新的 live aux
```

所以当前 daemon 和理想实现的差距主要在三个地方：

1. **map 引用必须重新变成当前 syscall 进程可解析的 fd**  
   `PSEUDO_MAP_FD` 的 imm 是 fd，不是 map id、map index、kernel pointer，也不是旧 `used_maps` index。loader 进程 fd 在 daemon 进程中通常无效，所以必须重写或改成 IDX。

2. **`PSEUDO_MAP_IDX` 也不是旧 `used_maps` index**  
   它是 `fd_array` index。daemon 若想用 IDX 规避 raw fd，就必须传 `fd_array`，并且 imm 要匹配完整 `fd_array` 布局。

3. **module BTF 也要每次 verify 时提供 fd**  
   module kfunc/kinsn call 的 `off > 0` 被解释成 `fd_array[off]`。当前 verifier 不从旧 `prog->aux->kfunc_btf_tab` / `used_btfs` 复用 module BTF。

### fd_array 是否能退化成“原始 fd_array 的 daemon 端等价”

对 maps 来说，当前 daemon 做的 `BPF_MAP_GET_FD_BY_ID(map_id)` 确实是在构造 daemon 端等价 fd。`prog_info.map_ids` 来自当前 live `prog->aux->used_maps`，这些 fd 指向同一批 map object。

但这只能解决 `fd_array`/IDX 路径，不能自动修复 FD-form bytecode，因为 `PSEUDO_MAP_FD` 完全不查 `fd_array`。只传 map fd_array 而不改 `PSEUDO_MAP_FD imm`，verifier 仍会把 loader fd 当 daemon fd 解析，通常失败。

### 不改 kernel 能不能完全删除 relocate_map_fds_for_rejit

不能删除所有“map fd 重新绑定”概念，但可以删除当前这个每次 ReJIT 前把 FD/IDX 都 lowering 成 FD 的函数，改成一个更稳定的 daemon 内部 ABI：

1. snapshot 后立即把 daemon 内部 bytecode 归一化：
   - `PSEUDO_MAP_FD` -> `PSEUDO_MAP_IDX`
   - `PSEUDO_MAP_VALUE` -> `PSEUDO_MAP_IDX_VALUE`
   - imm 写成完整 ReJIT `fd_array` 下标，而不是 map-only 下标。
2. 后续 `bpfopt` passes 保留这种 IDX form，不再携带 raw loader fd。
3. 每次 REJIT 只传 normalized bytecode + 完整 `fd_array`，不再调用 `relocate_map_fds_for_rejit()`。

这个方案仍然需要：

- 打开 `prog_info.map_ids` 对应 map fd；
- 传 `fd_array`；
- 对初始 GET_ORIGINAL 的 raw loader fd 做一次归一化；
- 正确处理 module BTF prefix 对 map IDX 的偏移。

因此它能减少 Bug D 这类“candidate first-seen 顺序变化导致错绑”的风险，但不是用户直觉里的“daemon 完全不关心 maps”。

### 如果想实现用户直觉，需要的最小 kernel 改动

这部分只是分析，不实施。

最小 kernel 方向有两类：

1. **REJIT 复用旧 `used_maps`，定义 REJIT 专用 map-index ABI**
   - 给 `bpf_check()` / verifier env 增加 `is_rejit` 或 `old_prog_aux`。
   - REJIT 时把旧 `prog->aux->used_maps` 作为只读 map table 传入 verifier。
   - 对 REJIT bytecode 中的 `PSEUDO_MAP_IDX(_VALUE)`，把 imm 解释为旧 `used_maps` index，而不是 `fd_array` index；或者新增 REJIT-only pseudo type，避免破坏现有 `PSEUDO_MAP_IDX` ABI。
   - verifier 仍要设置 `aux->map_index`，但 map object 来自旧 `used_maps`，不从 fd table 获取。
   - 成功后 live `used_maps` 保持旧数组，或者只在显式允许新 map 的模式下更新。

2. **GET_ORIGINAL 返回 normalized bytecode**
   - 不再暴露 raw loader fd。
   - 对 map reference 返回 `PSEUDO_MAP_IDX(_VALUE)`，imm 是可重放的 map table index。
   - 同时定义这个 index 到底是 `prog_info.map_ids`/`used_maps` index，还是某个新的 `orig_map_ids` table。
   - REJIT verifier 要能接受该 normalized form，不要求 daemon 提供 loader fd。

如果只改 GET_ORIGINAL、不改 REJIT verifier，仍不够；因为当前 verifier 的 IDX 仍是 `fd_array` index，daemon 仍要传 fd_array。要达到 `prog_rejit(prog_fd, new_bytecode)`，REJIT verifier 必须能从旧 aux 解析 maps。

## Q6: BTF module fd_array

module kfunc/kinsn 的 BTF fd_array 不是 daemon 自己凭空发明的；当前 verifier 明确这样设计：

- `CALL.off == 0`: 使用 vmlinux BTF。
- `CALL.off > 0`: `off` 是 `fd_array` 下标，verifier 从 `fd_array[off]` 读取 BTF fd。
- 该 fd 必须是 module BTF；不是 module BTF 会 reject。

代码点：

- `find_kfunc_desc_btf()` 对 `offset > 0` 调 `__find_kfunc_desc_btf()`: `kernel/bpf/verifier.c:3348-3359`
- `__find_kfunc_desc_btf()` 要求 `env->fd_array` 非空，从 `fd_array[offset]` 读 `btf_fd`: `kernel/bpf/verifier.c:3289-3299`
- 检查 `btf_is_module(btf)`: `kernel/bpf/verifier.c:3305-3308`
- `add_subprog_and_kfunc()` 对 `BPF_PSEUDO_KINSN_CALL` 调 `add_kfunc_desc(..., true)`: `kernel/bpf/verifier.c:3954-3964`

REJIT swap 确实会交换 `used_btfs` 和 `kfunc_btf_tab`，但这些是 tmp verifier pass 生成的新 metadata，不是进入 verifier 前从旧 prog 复用的解析表：`kernel/bpf/syscall.c:3401-3402`、`3422-3423`。

所以当前 ABI 下，如果 candidate 里有 module kinsn/kfunc call，daemon 必须每次 verify 提供 module BTF fd。这个复杂度是 kernel verifier ABI 强制的。

## Q7: GET_ORIGINAL 里的 old loader fd

当前 fork 的 `kernel_sys::prog_get_original()` 实际是通过 `BPF_OBJ_GET_INFO_BY_FD` 的 fork 扩展 `orig_prog_len/orig_prog_insns` 读取，不是单独 syscall command：`bpfopt/crates/kernel-sys/src/lib.rs:1514-1548`。

kernel 端的保存策略是“提交时原样保存”：

- `BPF_PROG_LOAD` 在 verifier 前把用户 insns 复制到 `prog->aux->orig_insns`: `kernel/bpf/syscall.c:3027-3038`
- `BPF_PROG_REJIT` 也在 verifier 前把用户提交 insns 复制到 `tmp->aux->orig_insns`: `kernel/bpf/syscall.c:3692-3703`
- swap 后 live `prog->aux->orig_insns` 变成这次 REJIT 提交的 bytecode: `kernel/bpf/syscall.c:3399-3400`
- `BPF_OBJ_GET_INFO_BY_FD` 直接 copy `prog->aux->orig_insns` 给用户: `kernel/bpf/syscall.c:5944-5954`

因此初始 program 的 `GET_ORIGINAL` 里，`PSEUDO_MAP_FD imm` 是 loader 进程当时传给 `BPF_PROG_LOAD` 的 raw fd。它不是 map id，不是 used_maps index，也不是 kernel pointer。

这不是 verifier 没有解析成功；verifier 已经把 map fd 解析到 `env->used_maps` 并在 xlated insns 中改成 map pointer。但 `orig_insns` 是 verifier 前的 raw snapshot。

注意另一个路径：`bpf_prog_info.xlated_prog_insns` 的 dump 会用 `bpf_insn_prepare_dump()` 把 xlated insn 里的 map pointer 反查 `used_maps`，然后把 imm 改成 map id，src_reg 改回 `BPF_PSEUDO_MAP_FD` / `VALUE`：`kernel/bpf/syscall.c:5685-5709`、`5723-5764`。但这只是 xlated dump 的展示/导出逻辑，不是 REJIT 可直接接受的 bytecode，因为 verifier 对 `BPF_PSEUDO_MAP_FD imm` 仍按 fd 解析，不按 map id 解析。

所以如果想让 `GET_ORIGINAL` 直接服务 daemon ReJIT，kernel ABI 最好返回 normalized form，例如 `PSEUDO_MAP_IDX` + `used_maps` index；但单独改 GET_ORIGINAL 不够，REJIT verifier 也要定义并接受这个 index 语义。

## maps 处理是否冗余

从理想架构看，当前 maps 处理确实绕远：

1. kernel 在第一次 load 时已经解析 loader fd，持有 `prog->aux->used_maps[]`。
2. daemon snapshot 又通过 `prog_info.map_ids` 拿 map id。
3. daemon 用 `BPF_MAP_GET_FD_BY_ID` 在自己的进程里重新打开 map fd。
4. `GET_ORIGINAL` bytecode 里还带着 loader 进程 raw fd。
5. daemon 再用 first-seen old fd 顺序把 raw fd 映射到 daemon map fd。
6. kernel REJIT verifier 最后再把 daemon fd 解析回同一个 `struct bpf_map *`。

Bug D 本质就是这条绕路造成的：如果 daemon 从 transformed candidate 重新推断 first-seen 顺序，DCE 删除早期 LD_IMM64 后，old fd 到 map slot 的映射会错位。当前代码已经改成从 `original_insns` 收集 first-seen old fd，避免 candidate 改变顺序：`daemon/src/bpf.rs:29-35`、`50-74`。但这仍是在用户态复刻 kernel 曾经做过的 fd 解析顺序。

不过在当前 kernel ABI 下，这套流程不是完全无意义的冗余：

- map fd 重新打开是必要的，因为 verifier 当前只认 fd/fd_array。
- `fd_array_cnt` 预绑定所有旧 maps，有助于在 pass 删除 map 引用时仍保持 live program 的 map bindings。
- module BTF fd_array 是 verifier 对 module kfunc/kinsn 的硬要求。

真正可以质疑的是当前 FD-form rewrite 的形态。更稳的 no-kernel-change 方向是尽早把 daemon 内部 bytecode 从 raw fd 语义切到 IDX 语义，避免每个 pass 都携带 loader fd。

## 最终判断

- **fd 重写到底必不必要？**  
  当前 ABI 下必要。更准确地说，必要的是“把 bytecode 中的 map reference 变成当前 REJIT syscall 可解析的 fd 或 fd_array index”。当前 `relocate_map_fds_for_rejit()` 是实现这一点的一种方式。

- **如果必要，kernel ABI 哪里强制了？**  
  `BPF_PROG_REJIT` 调完整 `bpf_check()`；`resolve_pseudo_ldimm64()` 对 `PSEUDO_MAP_FD` 把 imm 当 fd，对 `PSEUDO_MAP_IDX` 把 imm 当 `fd_array` 下标；进入 verifier 前没有把旧 `prog->aux->used_maps` 复制到 tmp。

- **如果不改 kernel，能不能消除？**  
  不能消除 map fd_array / fd 重新绑定。可以消除当前每次 ReJIT 前的 FD-form rewrite：snapshot 后把 daemon 内部 bytecode normalized 成完整 `fd_array` IDX form，并让 passes 保持 IDX。

- **如果想彻底消除，需要 kernel 最小改动？**  
  给 REJIT verifier 一条复用旧 `prog->aux->used_maps` 的路径，并定义 REJIT bytecode 中 map index 的 ABI；或者同时让 GET_ORIGINAL 返回 normalized map-index form、让 REJIT verifier 接受这个 form。用户已禁止改 kernel，本报告不实施。

- **maps 处理是否冗余？**  
  从理想 ABI 看是冗余且脆弱；从当前 ABI 看是被 verifier fd 解析模型逼出来的兼容层。Bug D 证明用户态 first-seen 映射是在重复 kernel 已完成的工作，长期应通过 kernel ABI 或 daemon 内部 IDX 归一化移除这类 per-pass raw-fd 推断。
