# 2026-05-20 shim audit round 2

Scope: read-only audit of the LD_PRELOAD shim, the new XDP netlink intercept, bpfopt kop-pass interactions, and BCC compatibility failures. I did not run benchmark targets or mutate git state. The only write from this audit is this report.

## 1. 总览

上一轮 audit 的 3 个 root-cause fix 已经反映到当前树里：

- `reload_and_reattach()` 里会清 `func_info` / `line_info` / `core_relos`，避免沿用旧程序的 BTF debug metadata。
- `reload_and_reattach()` 对 fork `bpf_attr` 的 `prog_token_fd` / `fd_array_cnt` 做了清零，上一轮 stale `fd_array_cnt` 根因已消失。
- `bcc_set.py` 已通过 `_shim_env_for(str(tool_binary))` 给 BCC tool 注入 `LD_PRELOAD` / shim env。

本轮新增/修复项的总体状态：

- perf table close+reopen fallback 的方向是对的，应该能消掉旧 fd close 后 perf table 仍指向旧 fd 导致的 `EEXIST` 类问题；这部分没有看到和当前 5 个 bug 直接相关的新根因。
- inner-map id supplement 的 4096 cap 是合理防护，但仍应把 cap 命中当作明确错误/诊断，而不是悄悄产生不完整 side input。
- map size pre-filter 现在写出的 skip marker 字段和 daemon `size_bytes` schema 对齐。当前实现用 256 KiB 估算阈值跳过、64 KiB snapshot limit 写 marker，语义可以接受，但这个 skip 仍是 benchmark corpus 语义改变，后续要确保只作为 side-input 不可用的显式失败/跳过，而不是隐藏优化失败。
- `/usr/bin/python -> python3` symlink 修复了旧 BCC tool shebang/runner 环境问题的一部分。
- 新增的 `shim_netlink.h` 能覆盖最常见的 XDP netlink attach 形态，但 replay 端有高概率实 bug：flags 语义不适合 replace、ACK 被忽略、detach 不更新状态、fd reuse/race 没防住。详见第 3 节。

仍未解的 bug：

- #34 不是 shim fd_array shift 的全局错误。证据指向 bpfopt/kfunc-kop 侧：`rotate` 是 kop callee 内部读未初始化 `R6`；`cond_select` / `endian_fusion` / `lea` 是特定 BTF module/kfunc target 在 attr 阶段被拒，0 verifier insns processed。
- #35 是 bpfopt 内部 verifier-PC namespace 和当前 raw bytecode PC namespace 没有显式映射，kop pass 改写布局后下一轮 verifier state lift 可能把 PC 解释错。
- bpftrace/set 的 12 个 step 失败大概率和 #34/#35 同源：`lea`、`cond_select`、`endian_fusion` 归入 kop target 问题，`const_prop` 更像 #35 PC remap 问题。
- BCC `KeyError(b["events"])` 不像 shim map 污染；更像 BCC compat header/sitecustomize 影响了编译/加载输入，导致 BCC 没生成预期 table/program。

Artifact note: prompt 中列的 `corpus/results/x86_kvm_corpus_20260519_155851_162854/details/shim-workdirs/work_9/` 仍带有上一轮 func_info/line_info 类旧症状，不是当前 #34 四个 kop pass 失败的最干净证据。当前最匹配描述的是 `corpus/results/x86_kvm_corpus_20260519_235235_032511/details/shim-workdirs/work_9/`：同一个 `target.json` shift 形态，`rotate` 为 `EACCES` 且 verifier 已跑 481 条，`cond_select` / `endian_fusion` / `lea` 为 `EINVAL` 且 0 insns processed。

## 2. #34 真正根因

### 2.1 bpfopt pass output 和 `shift_target_module_call_offsets` 的联动

`target.json` 中 kop entry 有两个不同概念：

- `btf_func_id`: kfunc/kmodule 内的函数 BTF id，写进 `BPF_PSEUDO_KOP_CALL` 指令的 `imm`。
- `btf_id`: BTF object id，shim 用 `BPF_BTF_GET_FD_BY_ID` 打开 BTF fd，并放进 `fd_array[call_offset]`。
- `call_offset`: fork verifier 用来从 `fd_array` 取 BTF fd 的槽位，写进 call 指令 `off`。

`bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs` 的 `shift_target_module_call_offsets_for_map_prefix()` 做的是：

```text
module_base = max(map_count, 1)
shifted_call_offset = module_base + original_module_call_offset - 1
```

katran 这个程序有 14 个 map，所以 kop module slots 被整体平移到 14..20：

| slot | btf_id | kop target |
| --- | ---: | --- |
| 14 | 2 | `bpf_x86_andl`, `bpf_x86_shrq` |
| 15 | 4 | `bpf_x86_bswapl`, `bpf_x86_rolw` |
| 16 | 5 | `bpf_x86_cmoveq`, `bpf_x86_cmovneq`, `bpf_x86_testq` |
| 17 | 7 | `bpf_x86_leal`, `bpf_x86_leaq` |
| 18 | 8 | `bpf_x86_mov*` |
| 19 | 13 | `bpf_x86_prefetcht0` |
| 20 | 14 | `bpf_x86_rolq`, `bpf_x86_rorxl` |

这个 shift 结果会进入 `KopRegistry`。各 pass 通过 registry 查 target name，再由 `emit_packed_kop_call_with_off()` 生成 kop call，call 指令里的 `off` 已经是 shifted slot。shim 侧 `build_full_fd_array()` 又读同一个 shifted `target.json`，把 BTF fd 放到相同 slot。因此 bpfopt 和 shim 对 call_offset 的协议本身是一致的。

关键判断：如果这里是 shim shift 或 fd_array 全局错位，`extract`、`bulk_memory`、`prefetch` 不可能稳定成功，因为它们使用同一套 shifted call_offset/fd_array 机制。当前失败只集中在 slot 15/16/17/20 的特定 target，slot 14/18/19 成功，说明不是全局 fd_array prefix bug。

### 2.2 `rotate` 的根因

`rotate` 失败不是 attr-stage，verifier 已进入候选程序并处理了 481 条指令，日志显示 kop callee 内部出现：

```text
(7b) *(u64 *)(r10 -376) = r6
R6 !read_ok
```

这意味着 call target 被解析到了真实 kop callee；否则不会进到 callee 内部并报 `R6` read state。shim 已经把 `btf_id=14` 的 BTF fd 放到了 slot 20，`BPF_PSEUDO_KOP_CALL` 至少完成了目标解析。

真正的问题在 bpfopt/kfunc-kop ABI 侧：`rotate.rs` 生成的 payload/descriptor 没有把 callee 实际读取的隐式寄存器 `R6` 初始化或声明为输入。`rotate_register_uses()` 只从 payload offset 8 收集 use，defs 只覆盖 offset 4；x86 W64 `rolq` 路径还会把 `call_dst` / `call_src` 都设成原 `dst_reg`。如果 kop module stub 或 lowered helper 需要 `R6` 作为 scratch/input，bpfopt 当前的 sidecar ABI 描述是不完整的。

修复方向：

- 对 `bpf_x86_rolq` / `bpf_x86_rorxl` 的 kop module ABI 做一次反查：callee 是否约定读取 `R6`，以及这个寄存器应由 payload、调用约定还是 module prologue 初始化。
- bpfopt pass 侧要么把隐式 register use/def 明确建模并在 replacement 前生成初始化，要么修正 target stub，不能让 callee 读未初始化 BPF register。
- 给 `rotate` 加候选 bytecode preservation / verifier-load regression。当前 workdir 会覆盖 `output.next.bin`，失败候选没有被稳定保留下来，定位成本太高。

### 2.3 `cond_select` / `endian_fusion` / `lea` 的根因

这三个失败都是 `EINVAL` 且 0 verifier insns processed。0 insns processed 说明 kernel 在真正 verifier walk 之前拒了 attr 或 call target metadata，不是普通 CFG/dataflow 验证失败。

共同点：

- `cond_select` 使用 slot 16 (`btf_id=5`) 和 slot 18 的 `mov*`。
- `endian_fusion` 使用 slot 15 (`btf_id=4`) 和 slot 18 的 `mov*`。
- `lea` 使用 slot 17 (`btf_id=7`)。
- `bulk_memory` 使用 slot 18 并成功，所以 slot 18 本身不是问题。
- `extract` 使用 slot 14 成功，`prefetch` 使用 slot 19 成功。

因此最可能根因是特定 BTF module/kfunc target 的 prototype、BTF exposure、attach compatibility 或 bpfopt 生成的 call metadata 不被 fork kernel 接受。它不是 shim 侧 “fd_array 没有打开 BTF fd” 的问题；当前日志里 `fd_array_n=21` 且没有负 slot，成功 target 也证明 module fd lookup 可用。

修复方向：

- 对失败 target 的 call 指令逐条 dump：`imm=btf_func_id`、`off=shifted_call_offset`、payload 常量、前后寄存器状态。需要把每个失败 step 的 candidate bytecode 单独保存，例如 `candidate_stepN.bin`，不要只保留最后一次成功 `output.bin`。
- 对 `btf_id=4/5/7/14` 的 module BTF fd 做启动时自检：打开 BTF fd 后，查 `btf_func_id` 是否在该 BTF 对象内、prototype 是否符合 kop verifier 预期。
- 若 `BPF_PROG_LOAD/REJIT` 在 0 insns 阶段失败，shim 应把 kernel `errno`、pass name、candidate insn count、每条 kop call 的 `(pc, imm, off, target_name, btf_id)` 写入 workdir manifest。现在光看 `target.json` 和最后 `output.bin` 不够。

### 2.4 shim 侧仍可改进的点

`build_full_fd_array()` 的调用点用了 `(void)build_full_fd_array(...)`。如果 JSON parse、BTF fd 打开或 slot 构造失败，shim 可能继续用缺失 fd_array 的 attr 去 ReJIT，错误会变成下游 verifier/attr failure。这个不一定是 #34 的当前根因，但违反 fail-fast 原则。

建议把 fd_array 构造失败改成 ReJIT step 的明确失败，并把失败原因写进 step log。不要让 “没有 fd_array” 和 “目标 kop 自己无效” 在同一个 `EINVAL` 里混在一起。

## 3. #41 netlink XDP intercept code review

### 3.1 Parse: `RTM_SETLINK` / `IFLA_XDP` / nested NLA

`nl_parse_setlink_xdp_attach()` 的基本层次是对的：遍历 `nlmsghdr`，识别 `RTM_SETLINK` / `RTM_NEWLINK`，取 `ifinfomsg`，扫描 top-level `IFLA_XDP`，再扫描 nested `IFLA_XDP_FD` 和 `IFLA_XDP_FLAGS`。`RTA_OK` / `RTA_NEXT` / `RTA_ALIGN` 用法也符合 rtnetlink attribute layout；netlink payload 是 host-endian，不需要 `ntohl`/`htonl`。

存在的问题：

- `rta_type` 没有 mask `NLA_TYPE_MASK`。普通 `IFLA_XDP` 不会带 nested/order flag 时没事，但 robust parser 应该按 UAPI mask type bits。
- `sendmsg` intercept 逐个 iovec 调 parser，没有把 iovec 线性化。合法 `sendmsg` 可以把 `nlmsghdr`、`ifinfomsg`、attrs 拆到多个 iovec；这种情况下当前 parser 会漏抓。libbpf/iproute2 常见路径通常是一块 contiguous request，所以 katran 可能刚好能抓到，但覆盖面不完整。
- observe 发生在真实 `sendto/sendmsg` 之前。原始 attach 如果被 kernel NACK，shim 仍然记录了 `(ifindex, flags)`，后续会 replay 一个从未成功安装过的 attach。
- `IFLA_XDP_FD = -1` detach 被忽略，但已有 attach 记录不会删除。如果 app 后续 detach 同一 ifindex/mode，shim 仍会在 ReJIT 后重新挂回去。
- `netlink_observe_xdp()` 在持锁时拿到 `struct prog_entry *p`，解锁后再调用 `prog_xdp_attach_append(p, ...)`，后者重新加锁并解引用 `p`。另一个线程可以在中间 close fd 并 `prog_remove()`，这是 use-after-free race。
- fd reuse 没有校验。netlink message 只携带 fd number；在 observe 时应该用 `BPF_OBJ_GET_INFO_BY_FD` 验证它仍是同一个 BPF prog id/type，再把 attach 记录到对应 kernel prog id。只按 fd number 查 `prog_table`，在 close/reopen 或多线程 fd reuse 下可能误关联。

### 3.2 Replay: `RTM_SETLINK` 构造

`nl_send_setlink_xdp_replace()` 构造的 netlink 层次大体正确：

- `nlmsg_type = RTM_SETLINK`，带 `NLM_F_REQUEST | NLM_F_ACK`。
- payload 是 `ifinfomsg`。
- top-level attr 是 nested `IFLA_XDP`。
- nested attrs 包含 `IFLA_XDP_FD` 和 `IFLA_XDP_FLAGS`。
- `rta_len` / `nlmsg_len` 使用 `RTA_LENGTH`、`RTA_ALIGN`、`NLMSG_LENGTH` 的组合基本正确，64 字节 attr buffer 足够容纳当前两个 nested attrs。

真正的大 bug 是 replay flags。代码把原始 attach 的 `xdp_flags` 原样带入 replay。初次 attach 常见 flags 会包含 `XDP_FLAGS_UPDATE_IF_NOEXIST`，而 replay 的语义是替换已有 old prog。原样 replay 很可能被 kernel 以 `EEXIST` 或 `EINVAL` 拒掉。libbpf 的 replace 路径会在 `XDP_FLAGS_REPLACE` 下携带 `IFLA_XDP_EXPECTED_FD`；iproute2 的 replace 语义也不是简单复用初次 attach flags。

修复方向：

- replay 时保留 mode bits，例如 `XDP_FLAGS_SKB_MODE` / `DRV_MODE` / `HW_MODE`，但不要保留 `UPDATE_IF_NOEXIST`。
- replay 应显式使用 replace 语义。最好记录 old attached prog fd 或 old prog id，并发送 `IFLA_XDP_EXPECTED_FD`；如果 old fd 已关闭，则至少不要伪装成初次 attach。
- replay failure 必须返回错误并进入 step log，不能只打印 “OK”。

另外，`nl_send_setlink_xdp_replace()` 内部直接调用 `socket/sendto/recv/close`。如果此时没有 `in_shim` guard，shim 自己发的 replay netlink 也会经过 `sendto` intercept。当前大概率因为 `new_pfd` 尚未写回 `prog_entry` 而找不到 entry，不会形成状态递归，但这是偶然行为。应使用 resolved real libc function 或显式 shim guard。

### 3.3 `SO_DOMAIN` / `SO_PROTOCOL`

只看 glibc/Linux，`getsockopt(SO_DOMAIN)` 和 `getsockopt(SO_PROTOCOL)` 是可用方案，当前 benchmark kernel 上不应有兼容性问题。真正的覆盖风险不是 glibc 是否支持，而是应用是否绕过 libc wrapper：

- direct `syscall(SYS_sendto/sendmsg)` 不会被当前 LD_PRELOAD hook 抓到。
- static linked binary 不会被抓到。
- connected netlink socket 上用 `send()` 的路径不会被抓到，因为当前没有 intercept `send`。

### 3.4 多 katran 实例 / fd reuse

多进程 katran 实例本身不是问题，因为 shim state 是进程内的。问题在单进程多线程和 fd lifecycle：

- `prog_find(prog_fd)` 只按 fd number 找 entry；fd close 后 number 被新 BPF prog 复用时，可能把 attach 记录到错误 prog。
- 如果原始 prog fd 在 attach 后被 app close，但 netdev 仍持有 attached prog，当前 `close` hook 会移除 `prog_entry`，后续就失去 replay 所需的 xdp attach state。很多 XDP loader 会保留 object fd，但这不应该是 shim 正确性的前提。
- `xdp_attaches` dedup 只按 `ifindex`，没有把 XDP mode/flags 纳入 key。对同一 ifindex 的不同 mode 或 replace/expected-fd 语义会互相覆盖。

建议把 attach 状态从 “fd table entry 的附属字段” 提升为按 kernel prog id / ifindex / mode 记录，并在 close fd 时不要立即丢掉 still-attached netdev state。至少 observe 时要确认 fd 对应的 kernel prog id，replay 时用这个 id 关联到 replacement prog。

### 3.5 iproute2 和 libbpf 两条路径覆盖

当前 hook 应能覆盖动态链接 glibc 且使用 `sendto`/`sendmsg` 的常见路径：

- libbpf `bpf_xdp_attach()` 的 rtnetlink 路径通常会被抓到。
- iproute2 `ip link set dev X xdp obj Y` 通常也会发 `RTM_SETLINK + IFLA_XDP`，如果是动态链接且 request contiguous，也会被抓到。

覆盖缺口：

- `send()`、direct syscall、static binary、分裂 iovec。
- 如果某些 libbpf 版本走 `bpf_link_create` / netdev BPF link，而不是 rtnetlink `IFLA_XDP_FD`，这条 netlink hook 不会触发；那应由现有 `BPF_LINK_CREATE`/fd 追踪路径负责。
- iproute2 replace/update flag 组合比当前 replay 复杂，抓到不等于能正确重放。

### 3.6 ACK 处理和 retry

当前 replay 发出 `NLM_F_ACK` 后只做一次 `recv(..., MSG_DONTWAIT)`，并且不解析返回内容。这是不正确的：

- ACK 可能尚未到达，`EAGAIN` 被当成成功。
- ACK 可能是 `NLMSG_ERROR` 且 `error < 0`，当前仍当成成功。
- 没有匹配 `nlmsg_seq` / sender pid，未来如果 socket 复用或收到异步通知会误读。
- extended ACK 里的具体原因被丢掉，step log 无法区分 flags 错、ifindex 错、权限错、old prog mismatch。

修复方向：blocking recv loop，匹配 seq，解析 `NLMSG_ERROR`。`error == 0` 才成功；`error < 0` 设置 `errno = -error` 并返回失败。只对 `EINTR` 做循环；不要对 kernel NACK 做盲 retry。若需要处理 `EEXIST`，应先修正 replace flags/expected fd，而不是靠 retry 掩盖。

## 4. #35 verifier-PC remapper 接口设计

当前 `verifier_log.rs` 解析出的 `VerifierInsn.pc` 被 `bbprogram_lift.rs` 直接当成当前 raw bytecode PC。kop pass 改写 bytecode 后，这个假设不再稳定；下一轮 `const_prop` 等 pass 可能把 verifier PC 对到不存在的 CFG pc，于是报：

```text
verifier state pc N is not present in CFG
```

需要显式区分 namespace，并让每个改写布局的 pass 产出 PC 映射。接口草案如下，仅表示边界，不是实现：

```rust
#[derive(Clone, Copy, Debug, Eq, PartialEq, Ord, PartialOrd, Hash)]
pub(crate) struct RawPc(pub usize);

#[derive(Clone, Copy, Debug, Eq, PartialEq, Ord, PartialOrd, Hash)]
pub(crate) struct VerifierPc(pub usize);

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub(crate) enum PcRemapDisposition {
    Exact,
    DeltaToNextInsn,
    DroppedDeletedInsn,
    DroppedUnreachable,
}

#[derive(Clone, Debug)]
pub(crate) struct VerifierPcRemapEntry {
    pub verifier_pc: VerifierPc,
    pub raw_pc: Option<RawPc>,
    pub site: Option<InsnSite>,
    pub disposition: PcRemapDisposition,
}

pub(crate) trait VerifierPcRemapper {
    fn remap_state_pc(
        &self,
        state: &VerifierInsn,
        current_pc_to_site: &BTreeMap<RawPc, InsnSite>,
    ) -> anyhow::Result<Option<VerifierPcRemapEntry>>;
}

pub(crate) fn lift_verifier_states_by_site_with_remapper(
    verifier_states: Option<Arc<[VerifierInsn]>>,
    btf: &BtfMetadataMap,
    remapper: &dyn VerifierPcRemapper,
) -> anyhow::Result<Option<VerifierStatesBySite>>;
```

接口约束：

- 默认实现是 identity remapper，只能用于没有改变 PC layout 的输入。
- 改写布局的 pass 必须交出 old/raw/new/verifier PC translation artifact；不能让下游猜。
- `Exact` 才能承载完整 verifier state；`DeltaToNextInsn` 只能用于当前已有的 delta-state 语义。
- 对 deleted/unreachable PC，remapper 可以显式返回 `Ok(None)`，但必须带 disposition 进入诊断。不能 silent drop，也不能把 state 贴到最近 PC。
- `lift_verifier_states_by_site` 遇到无法 remap 的 non-delta state 应 fail-fast，错误信息要同时打印 verifier pc、可用 raw pc range、上一轮 pass name。

这个接口能把 #35 从 “PC 不在 CFG” 的后验报错，变成 “哪个 pass 没有提供 verifier/raw PC 映射” 的前置错误。

## 5. BCC compat `KeyError`

当前 `runner/libs/app_runners/bcc.py` 的 monkeypatch 做两件事：

- 给 `_bcc.BPF.__init__` 追加 `cflags`。
- 如果有 `text`，在源码前 prepend `#include "<compat_header>"`。

它没有改 `BPF.__getitem__`、`get_table()`、`self.tables` 或 BPF map 名称。`BCC_COMPAT_HEADER` 也没有定义/undef `events`、`BPF_PERF_OUTPUT` 或 table 宏。因此 `KeyError(b["events"])` 不像是 shim 或 monkeypatch 在 Python runtime 污染了 `"events"` map。

更像的问题是 compile/load 输入被 compat 层改变后，BCC 没有生成预期 map/program，但 tool 继续执行到 Python 侧访问 table 才炸。当前失败也不只 `"events"`：

- `capable` / `opensnoop` 报 `events` missing。
- `vfsstat` 报 `stats` missing。
- `syscount` 报 `data` missing。
- `tcplife` 报 `ipv4_events` missing。
- `tcpconnect` 报 unknown program `trace_connect_entry`。

这是一组 “BCC 编译/section/table 生成不符合 tool 预期” 的症状，不是单个 map 被污染。

修复方向：

- 对一个最小失败 tool 开 `DEBUG_BPF` 或等价 BCC debug，把最终 C source、cflags、clang stderr、libbcc load stderr 写入 app workdir。
- 检查 compat header 是否改变了某些 kernel feature macro，使 tool 走到没有 `BPF_PERF_OUTPUT(events)` 的条件分支。
- 保留当前 LD_PRELOAD 注入修复；不要把这个问题归因到 shim ReJIT attach。

## 6. 修复优先级 + ROI

P0 / highest ROI:

- 修 #41 replay ACK：blocking 读 ACK、解析 `NLMSG_ERROR`、失败返回并写 step log。否则 replay 实际失败会被报告成成功。
- 修 #41 replay flags：保留 mode bits，去掉 `UPDATE_IF_NOEXIST`，使用 replace 语义；能记录 old fd 时加 `IFLA_XDP_EXPECTED_FD`。
- 修 #41 状态正确性：detach 删除 attach 记录；observe 不要在 kernel attach 成功前 commit；消除 `prog_entry *` 解锁后使用的 race。
- 给 shim 保存每个失败 step 的 candidate bytecode 和 kop call manifest。#34 没这个会反复卡在 “最后 output.bin 不是失败候选”。

P1:

- `rotate` kop ABI 修复：明确 `R6` 是 callee bug、payload ABI bug，还是 pass register-use 描述缺失；加 verifier regression。
- `cond_select` / `endian_fusion` / `lea`：对 `btf_id=4/5/7` 做 BTF fd + func prototype 自检，确认是 module/kfunc metadata 还是 pass call encoding。
- 实现 #35 PC remapper 接口，让 const_prop after kop 不再把 verifier pc 误当 raw pc。
- netlink observe 改为按 kernel prog id 校验，处理 fd reuse；补 `send()` 或 linearize split-iov `sendmsg`。

P2:

- `build_full_fd_array()` 失败不要 `(void)` 忽略，改为 fail-fast 诊断。
- 把 target/workdir JSON parsing 从 string scan 换成明确 JSON parser，避免 schema 小改导致 silent misparse。
- BCC compat 加 full compile/load artifact，先定位 header/cflags 对 tool source 的实际影响。
