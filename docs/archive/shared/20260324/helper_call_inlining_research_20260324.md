# #444 Helper Call 内联/特化 深度调研报告

日期：2026-03-24  
任务：#444 Helper call 内联/优化  
上下文入口：`docs/kernel-jit-optimization-plan.md`  
前置统计：`docs/tmp/20260323/simd_constprop_opportunity_analysis_20260323.md`

## TL;DR

结论先说：

1. **第一优先级是 `skb_load_bytes -> direct packet access`，而且优先做 XDP/TC fast path 的纯 bytecode rewrite。**  
   这类 site 的 helper 语义与 direct packet access 最接近；内核已有完整 verifier 合同（`data/data_end`、`PTR_TO_PACKET`、bounds check），不需要新 kinsn。

2. **`skb_store_bytes` 只能做窄子集特化，不能把“所有 packet store helper”简单改成 direct write。**  
   `flags`、non-linear/cloned skb、按需 `make_writable()` 以及 TC direct-write prologue 都会改变成本模型。最现实的子集是 `flags=0`、固定小长度、已经有 writable/linear 保证的 path。

3. **`probe_read_kernel` 不是“把 4B/8B helper call 换成 LDX”这么简单。**  
   它的核心价值是 `copy_from_kernel_nofault()` + fault 后清零目标缓冲区。这个 fault-handling 语义不能省。对 Tracee 这类 tracing workload，绝大多数 site 的 `unsafe_ptr` 本来就是 verifier 不会允许直接解引用的“opaque/unsafe pointer”。  
   因此：**纯 bytecode rewrite 只适用于极窄的 non-faulting typed-pointer 子集；一般情形若要内联，必须引入新的 safe-load intrinsic/kinsn 或等价内核支持。**

4. **`ktime_get_ns` 不适合做纯 bytecode rewrite。**  
   BPF ISA 里没有“读 monotonic ns”的等价指令；helper 已经直接走 `ktime_get_mono_fast_ns()`。除非引入新的 arch-specific intrinsic/kinsn，否则只能保留 helper。即使做 inline，语义也比 packet helper 更难保持。

5. **Tracee 与 Cilium 恰好代表两种完全不同的安全模型。**  
   Tracee 的 `probe_read_kernel` 优化面“量大但危险”；Cilium 的 `skb_load_bytes` 优化面“量没那么大，但 verifier 合同最清楚、最适合先落地”。

## 1. 统计口径与快照差异

这份报告混用两组数字，并刻意把它们分开：

1. **2026-03-23 helper census lower bound**  
   来自 `simd_constprop_opportunity_analysis_20260323.md`，是上一轮“保守识别”结果。
2. **2026-03-24 raw rescan / refined local proof**  
   我对当前 `corpus/build/**/*.bpf.o` 重新扫了一遍 raw helper call，并额外做了一个**同 basic block 内向后追踪 register copy + `mov32/mov64 imm`** 的 refined local proof。

这两个口径的意义不同：

- `2026-03-23` 数字适合作为**保守下界**。
- `2026-03-24 refined` 适合作为“当前 corpus 里，明显可静态证明的常量参数比例”。

### 1.1 全局计数

当前 `corpus/build` raw rescan 结果：

| helper | 2026-03-23 文档 | 2026-03-24 raw rescan | 备注 |
|---|---:|---:|---|
| `probe_read_kernel` | `25296` | `25299` | 仅 `+3`，可视为 build 快照漂移 |
| `skb_load_bytes` | `590` | `590` | 无变化 |
| `skb_store_bytes` | `536` | `536` | 无变化 |
| `ktime_get_ns` | 未单列 | `933` | 本轮新增统计 |

### 1.2 常量参数比例：lower bound vs refined proof

| helper | 参数 | 2026-03-23 lower bound | 2026-03-24 refined local proof | 解释 |
|---|---|---:|---:|---|
| `probe_read_kernel` | `size` | `99.9%` | `99.96%` (`25290 / 25299`) | 两轮结论一致：几乎全是固定小尺寸 |
| `skb_load_bytes` | `len` | `29.5%` | `100.0%` (`590 / 590`) | 3/23 是下界；4/24 识别了 basic-block 内 register copy 和 `mov32 imm` |
| `skb_store_bytes` | `len` | `58.4%` | `96.64%` (`518 / 536`) | 仍有一小部分 len 需要动态值 |
| `ktime_get_ns` | 无参数 | N/A | N/A | 只有调用开销，没有“参数 specialization” |

### 1.3 常见尺寸与 `skb_store_bytes` flags

`probe_read_kernel` 最常见 `size`：

- `8`: `16715`
- `4`: `6113`
- `16`: `1456`
- `65`: `452`
- `104`: `207`
- `2`: `159`

`skb_load_bytes` 最常见 `len`：

- `2`: `166`
- `8`: `139`
- `4`: `88`
- `20`: `62`
- `1`: `61`
- `16`: `20`
- `40`: `18`
- `14`: `12`

`skb_store_bytes` 最常见 `len`：

- `4`: `176`
- `2`: `124`
- `16`: `74`
- `6`: `52`
- `8`: `26`
- `20`: `18`

`skb_store_bytes` 的 `flags` 分布非常关键：

- `0`: `498`
- `BPF_F_RECOMPUTE_CSUM` (`1`): `16`
- `BPF_F_INVALIDATE_HASH` (`2`): `18`
- 未在 local proof 中解析出的 `flags`: `4`

这说明：

- `skb_store_bytes` 的**大多数** site 语义上只是“写小块 packet bytes”；
- 但仍有一批 site 依赖 helper 的 checksum/hash side effect，不能被“普通 store”替代。

## 2. 按 helper / 项目 / prog_type 的 corpus 分布

### 2.1 按项目

这里 project 统计使用 raw helper call；constant ratio 用 2026-03-24 refined local proof。

| helper | 项目分布 |
|---|---|
| `probe_read_kernel` | `tracee 21732 (100%)`, `KubeArmor 2688 (100%)`, `bcc 387 (99.7%)`, `tetragon 257 (100%)`, `linux-selftests 118 (100%)` |
| `skb_load_bytes` | `cilium 428 (100%)`, `linux-selftests 81 (100%)`, `calico 56 (100%)`, `loxilb 16 (100%)`, `tracee 2 (100%)` |
| `skb_store_bytes` | `loxilb 258 (100%)`, `cilium 215 (100%)`, `calico 42 (57.1%)`, `linux-selftests 21 (100%)` |
| `ktime_get_ns` | `cilium 221`, `bcc 211`, `tracee 168`, `calico 97`, `KubeArmor 66` |

直接解读：

- `probe_read_kernel` 是**安全/可观测项目**主导，尤其是 Tracee。
- `skb_load_bytes` / `skb_store_bytes` 是**networking datapath** 主导，尤其是 Cilium / loxilb / Calico。
- `ktime_get_ns` 分布最散，但仍明显偏向 networking + tracing。

### 2.2 按 prog_type

prog_type 归因只能对**可识别 section root**做；共享 `.text` 子程序无法无歧义归到单一 prog_type，因此下面的 prog_type 表是“可归因子集”，不是 raw total。

| helper | prog_type 分布（可归因 section） |
|---|---|
| `probe_read_kernel` | `kprobe 16163 (100%)`, `tracing 3964 (100%)`, `raw_tracepoint 3321 (99.9%)`, `lsm 824 (100%)`, `tracepoint 213 (100%)` |
| `skb_load_bytes` | `sched_cls 532 (100%)`, `flow_dissector 28 (100%)`, `socket_filter 7 (100%)`, `cgroup_skb 4 (100%)` |
| `skb_store_bytes` | `sched_cls 278 (93.5%)`, `tc_packet_hook2 138 (100%)`, `tc_packet_hook6 116 (100%)` |
| `ktime_get_ns` | `sched_cls 264`, `kprobe 234`, `tracing 114`, `tracepoint 70`, `xdp 68`, `raw_tracepoint 38` |

这张表基本确定了四个 helper 的“主战场”：

- `probe_read_kernel`: **kprobe/raw_tracepoint/tracing**
- `skb_load_bytes` / `skb_store_bytes`: **sched_cls/TC**
- `ktime_get_ns`: **跨 tracing + networking 分布**

## 3. 逐 helper 安全性分析

## 3.1 `probe_read_kernel`

### 内核语义

UAPI 把它定义成“**safely attempt to read** kernel space address `unsafe_ptr` into `dst`” (`vendor/linux-framework/include/uapi/linux/bpf.h:4298-4303`)。  
真实实现更关键：`bpf_probe_read_kernel_common()` 调 `copy_from_kernel_nofault()`，失败时**显式 `memset(dst, 0, size)`** (`vendor/linux-framework/include/linux/bpf.h:3473-3480`)。

helper proto 也暴露了 verifier 合同差异：

- `arg1 = ARG_PTR_TO_UNINIT_MEM`
- `arg2 = ARG_CONST_SIZE_OR_ZERO`
- `arg3 = ARG_ANYTHING`  
  见 `vendor/linux-framework/kernel/trace/bpf_trace.c:241-248`

这意味着 verifier 对第三个参数的态度是：**你可以传一个“unsafe/opaque pointer”，helper 自己去 nofault 地碰它**。

### 为什么不能直接改成 load

如果把：

```c
bpf_probe_read_kernel(&x, 8, unsafe_ptr)
```

改成：

```c
x = *(u64 *)unsafe_ptr;
```

会同时丢掉两层语义：

1. **fault containment**
   - helper 用 `copy_from_kernel_nofault()`；
   - 直接 `LDX` 没有 extable/no-fault recover 语义。
2. **verifier 合同**
   - helper 接受 `ARG_ANYTHING`；
   - 直接 load 必须让 verifier 看到一个可证明安全的 source pointer。

因此，`probe_read_kernel` 不是“替换 call 开销”的问题，而是“把 unsafe memory access contract 改成 safe typed-pointer access contract”的问题。

### 什么时候纯 bytecode rewrite 才可能成立

只在下面的窄子集成立时，`probe_read_kernel -> direct load` 才有讨论价值：

1. `unsafe_ptr` 实际上不是“opaque address”，而是 verifier 已知的合法 pointer family  
   例如 `PTR_TO_BTF_ID` / `PTR_TO_MAP_VALUE` / 已通过 ctx access 转换出的 typed pointer。
2. 访问窗口可静态证明不 fault。
3. `size` 是很小的固定值（`1/2/4/8/16` 最现实）。
4. 使用点本身不依赖“fault 时清零 + 返回负 errno”的可观察行为。

现实问题是：**Tracee 的大头恰恰不是这个子集。**

### 风险判断

- **安全风险最高。**
- **实现风险最高。**
- **对 Tracee upside 很大，但 ready-to-ship 程度最低。**

结论：  
`probe_read_kernel` 的**一般情形**不应先做纯 bytecode rewrite。若真要内联，方向应该是“带 verifier 语义的新 safe-load intrinsic / kinsn / 内核 special-case”，而不是盲目换成 `LDX`。

## 3.2 `skb_load_bytes`

### 内核语义

UAPI 文档已经把路线说得很清楚：`skb_load_bytes()` 原本是“easy way to load data from a packet”，但自 Linux 4.7 以后大多被 **direct packet access** 替代；它仍有价值的场景是“一次把较大数据块搬到 BPF stack” (`vendor/linux-framework/include/uapi/linux/bpf.h:2526-2540`)。

真实实现走的是：

- `skb_header_pointer(skb, offset, len, to)`
- 如果返回的是外部指针，再 `memcpy(to, ptr, len)`
- 出错则 `memset(to, 0, len)` + `-EFAULT`  
  见 `vendor/linux-framework/net/core/filter.c:1753-1783`

关键点：`skb_header_pointer()` **可以处理 non-linear skb**。  
这也是 helper 和 direct packet access 的最大差异。

### 改成 direct packet access 后 verifier 要求什么

要把 helper 改成 direct packet access，新的 bytecode 必须走 verifier 已有 contract：

1. prog type 必须允许 direct packet access  
   `may_access_direct_pkt_data()` 只对 `XDP` / `SCHED_CLS` / `SCHED_ACT` / `SK_SKB` / `SK_MSG` / `CGROUP_SKB` 等开放 (`vendor/linux-framework/kernel/bpf/verifier.c:6777-6808`)
2. 必须通过 ctx access 拿到 `data` / `data_end`  
   `tc_cls_act_is_valid_access()` / `xdp_is_valid_access()` 会把 `data` 标成 `PTR_TO_PACKET`、`data_end` 标成 `PTR_TO_PACKET_END` (`vendor/linux-framework/net/core/filter.c:9147-9190`, `9227-9270`)
3. 必须显式建立 bounds proof  
   verifier 最终看的是 `check_packet_access()` 对 `reg->range` 的检查 (`vendor/linux-framework/kernel/bpf/verifier.c:6811-6855`)
4. 中间不能跨过会让 packet proof 失效的 helper  
   `clear_all_pkt_pointers()` 会把旧 packet pointer 证明全部清掉 (`vendor/linux-framework/kernel/bpf/verifier.c:11005-11017`)

### 风险边界

`skb_load_bytes` 最适合 rewrite，但仍有两个边界：

1. **non-linear skb**
   - helper 可跨 frag/head 边界；
   - direct packet access 只对当前 linear/head-visible 窗口成立。
2. **大块 copy 到 stack**
   - 对非常大的 `len`，helper 仍可能是更稳妥表达；
   - 但 corpus 里主流尺寸其实很小，集中在 `2/4/8/14/20/40`。

### 判断

- **最适合做纯 bytecode rewrite。**
- **不需要 kinsn。**
- **改写后还能继续喂给 `wide_mem` / `extract` / `endian_fusion`。**

结论：  
`skb_load_bytes` 是 #444 的 **P0**。

## 3.3 `skb_store_bytes`

### 内核语义

UAPI 文档明确说了两个 helper-only side effect：

- `BPF_F_RECOMPUTE_CSUM`
- `BPF_F_INVALIDATE_HASH`  
  见 `vendor/linux-framework/include/uapi/linux/bpf.h:2097-2115`

实现也不是简单 `memcpy`：

1. 检查 `flags`
2. `bpf_try_make_writable(skb, offset + len)`
3. 可选 checksum pull/push
4. `memcpy(ptr, from, len)`
5. 可选 `skb_clear_hash()`  
   见 `vendor/linux-framework/net/core/filter.c:1710-1745`

文档还明确写道：这个 helper **susceptible to change the underlying packet buffer**，因此 verifier 会把之前的 direct packet proof 判定为失效 (`vendor/linux-framework/include/uapi/linux/bpf.h:2109-2115`)。

### 为什么不能一股脑改成 direct write

`skb_store_bytes` 至少有三类额外语义：

1. **按需 `make_writable()`**
   - helper 在 site 上按需处理 cloned/non-linear skb。
2. **checksum / hash side effect**
   - 不是普通 store 能自动继承的。
3. **TC direct-write 成本模型**
   - direct write 不是“零成本写 packet”；它会走 verifier 的 direct-write contract，并可能引入 prologue。

这点在 Cilium 代码里写得很直白：

- `runner/repos/cilium/bpf/include/bpf/ctx/skb.h`：`CTX_DIRECT_WRITE_OK 0`
- 注释：`Discouraged since prologue will unclone full skb.`

也就是说：**Cilium 并不是“还没想到 direct write”，而是有意避免它。**

### 结合 corpus 的判断

好消息是：`flags=0` 占 `498 / 536`，多数 site 没有 checksum/hash side effect。  
坏消息是：即便如此，TC/cloned-skb/writability 仍是成本和正确性问题。

因此更合理的切法是：

1. **只看 `flags=0` 子集**
2. **只看已经有 linear/writable 保证的 path**
3. **优先 XDP 或明确不会被 unclone-prologue 反噬的 path**

结论：  
`skb_store_bytes` 可以做，但只能是**窄子集**；它不是 #444 的第一波。

## 3.4 `ktime_get_ns`

### 内核语义

UAPI：返回自 boot 以来的 monotonic ns (`vendor/linux-framework/include/uapi/linux/bpf.h:2007-2013`)。  
实现：直接返回 `ktime_get_mono_fast_ns()` (`vendor/linux-framework/kernel/bpf/helpers.c:178-187`)。

### 为什么不适合纯 bytecode rewrite

这里没有像 packet helper 那样的“BPF 里已经存在的等价表达”：

- 没有 BPF 指令能直接读 monotonic ns；
- 把它改成普通 bytecode 序列是做不到的；
- 如果发明一个 arch-specific `rdtsc`/`cntvct` lowering，又会改语义，不再等于 `ktime_get_mono_fast_ns()`。

更重要的是：`ktime_get_ns()` 的结果本身是**可观察语义**。  
你不能像对纯函数那样自由 hoist / CSE 两次 time read。

结论：  
`ktime_get_ns` 不是一个好的“helper call inlining”首目标。除非引入新的 helper-inline contract/kinsn，并明确接受其语义边界，否则应保持 helper。

## 4. Verifier 交互：helper 改成 direct access 后要满足什么

| rewrite | verifier 新要求 | 关键内核证据 | 主要 blocker |
|---|---|---|---|
| `probe_read_kernel -> direct load` | source reg 必须是 verifier 可证明安全的 pointer；访问范围必须被证明；不能再是 opaque `unsafe_ptr` | `bpf_probe_read_kernel_proto.arg3_type = ARG_ANYTHING` (`kernel/trace/bpf_trace.c`)；direct memory access 走普通 pointer/type/bounds 检查 | helper 原本承接了 nofault + zero-on-error；direct load 没有 |
| `skb_load_bytes -> direct packet access` | 必须先取 `data/data_end`，建立 `PTR_TO_PACKET` range 证明，且中间无 packet-proof invalidation | `may_access_direct_pkt_data()`、`check_packet_access()`、`tc_cls_act_is_valid_access()`、`xdp_is_valid_access()` | non-linear skb / 缺少 bounds guard |
| `skb_store_bytes -> direct packet write` | 同上，外加 direct-write 合同、writable/linear 保证、必要的 prologue/side effect | `bpf_skb_store_bytes()` 实现、`clear_all_pkt_pointers()`、TC direct-write prologue | `flags`、unclone 成本、helper side effect |
| `ktime_get_ns -> inline` | verifier 本身无现成 bytecode contract；需要新 intrinsic/helper-inline 语义 | helper 直接返回 `ktime_get_mono_fast_ns()` | 纯 bytecode 无等价表达 |

一句话概括：

- packet helper 的 rewrite 是“**把 helper 语义翻译成 verifier 已经会证明的 packet contract**”；
- `probe_read_kernel` 的 rewrite 是“**试图把 unsafe nofault access 改成普通 typed load**”，这两者难度不是一个量级。

## 5. 安全风险：为什么 tracing 和 XDP/TC 不是一回事

### 5.1 `probe_read` 的 fault handling 不能省

这是本任务最硬的 safety line：

- `probe_read_kernel` 在 fault 时返回负 errno，并清零 `dst`；
- tracing 程序经常把目标 buffer 后续拿去做 event serialization / map key / string output；
- 如果省掉 fault handling，就不是“优化”，而是改变了可见语义，甚至可能把内核 fault surface 暴露出来。

因此：

- **对 `probe_read_kernel`，安全性不是“bounds check 够不够”的问题；**
- **而是“有没有完整保留 nofault recover contract”的问题。**

### 5.2 tracing vs XDP 的安全模型完全不同

**Tracing / kprobe / raw_tracepoint**

- 面对的是 arbitrary kernel pointer / task/file/path/syscall table 等对象；
- 需要 helper 去承接 may-fault access；
- verifier 对这类 pointer 往往不会给你“直接解引用”的 green light。

**XDP**

- 面对的是 `data .. data_end` 之间的 packet window；
- verifier 直接跟踪 `PTR_TO_PACKET` / `PTR_TO_PACKET_END`；
- 安全边界是 bounds proof，不是 nofault recover。

**TC / skb**

- 介于两者之间；
- 也有 direct packet access contract，但还要面对 non-linear skb、cloned skb、direct-write prologue 等复杂性。

所以：

- `probe_read_kernel` 的问题本质上是 **fault-safe memory access**
- `skb_load_bytes` 的问题本质上是 **packet bounds / linearity**
- `skb_store_bytes` 的问题本质上是 **packet writability + side effect**

## 6. Case Study

## 6.1 Tracee：`probe_read_kernel` 重度用户

这是最典型的“量大但危险”案例。

### 统计

- `corpus/build/tracee/tracee.bpf.o`
  - `probe_read_kernel`: `21732`
  - `ktime_get_ns`: `168`
  - `skb_load_bytes`: `2`

top sections 也全是 tracing/security 相关：

- `uprobe/syscall_table_check`: `892`
- `uprobe/lkm_seeker_kset_tail`: `861`
- `uprobe/lkm_seeker_modtree_loop_tail`: `808`
- `uprobe/lkm_seeker_proc_tail`: `793`
- `raw_tracepoint/exec_test`: `566`

### 真实代码形态

Tracee 的 probe_read 不是“读 packet header”，而是类似：

- 读 syscall table 项：`bpf_probe_read_kernel(&effective_address, sizeof(u64), sys_call_table + index);`
  - `runner/repos/tracee/pkg/ebpf/c/tracee.bpf.c:1768-1779`
- 读 kernel struct name/path：`bpf_probe_read_kernel_str(..., prog_aux->name)`
  - `runner/repos/tracee/pkg/ebpf/c/tracee.bpf.c:1988-1996`
- 读 file metadata / offsets / pid / size：
  - `runner/repos/tracee/pkg/ebpf/c/common/filesystem.h:456-464`
- 读 policies config：
  - `runner/repos/tracee/pkg/ebpf/c/common/context.h:182-190`

### 判断

Tracee 的 `probe_read_kernel` 之所以多，不是因为 kernel JIT “漏了一条 8B load”，而是因为 Tracee 的工作负载本来就在大量遍历/探测**不受 verifier 直接 trust 的 kernel memory**。

因此：

- **如果目标是“立刻做一个安全可投产的 helper specialization”**，Tracee 不是第一站；
- **如果目标是“未来展示 BpfReJIT 对 security tracing 的能力”**，Tracee 是最有价值的长期目标，但前提是先设计 safe-load contract。

## 6.2 Cilium：`skb_load_bytes` / `skb_store_bytes` 典型用户

这是“量适中但工程 readiness 最高”的案例。

### 统计

- `corpus/build/cilium/bpf_lxc.bpf.o`
  - `skb_load_bytes`: `230`
  - `skb_store_bytes`: `115`
  - `ktime_get_ns`: `89`
- `corpus/build/cilium/bpf_overlay.bpf.o`
  - `skb_load_bytes`: `198`
  - `skb_store_bytes`: `100`
  - `ktime_get_ns`: `75`
- `corpus/build/cilium/bpf_xdp.bpf.o`
  - `ktime_get_ns`: `57`

### 真实代码形态

Cilium 的 helper 使用非常规律：

- 固定 2B/4B/8B/16B/20B/40B 读包头
  - `runner/repos/cilium/bpf/lib/l4.h:67-82`
  - `runner/repos/cilium/bpf/lib/icmp6.h:256-296`
  - `runner/repos/cilium/bpf/bpf_xdp.c:148-160`
- 固定 4B/16B/20B/56B/68B 写 header / addr / payload
  - `runner/repos/cilium/bpf/lib/lb.h:1521-1537`
  - `runner/repos/cilium/bpf/lib/icmp6.h:268-296`

更关键的是它的 abstraction：

- `ctx_load_bytes -> skb_load_bytes`
- `ctx_store_bytes -> skb_store_bytes`
- `CTX_DIRECT_WRITE_OK 0`
- 注释：`Discouraged since prologue will unclone full skb.`  
  见 `runner/repos/cilium/bpf/include/bpf/ctx/skb.h`

### 判断

对 Cilium 来说：

- `skb_load_bytes` 特化非常自然：固定小窗口、hot packet path、能直接接到 packet direct access + 后续 peephole
- `skb_store_bytes` 要谨慎：helper 在这里不只是“写几字节”，还在编码 TC/skb 的 writability 成本模型

因此：

- **Cilium 最适合做 `skb_load_bytes` first implementation**
- **不适合把 `skb_store_bytes` 一刀切换成 direct write**

## 7. kinsn vs 纯 bytecode rewrite 决策

| helper | 首选实现形态 | 需要 kinsn 吗 | 结论 |
|---|---|---|---|
| `skb_load_bytes` | `ctx->data/data_end` + bounds guard + direct load/store to stack | **不需要** | **纯 bytecode rewrite** 最合适 |
| `skb_store_bytes` | 仅 `flags=0`、小长度、明确 writable/linear path 的 direct write | **窄子集不需要**；全语义等价需要额外内核支持 | 先做**纯 rewrite 的窄子集**，不要做全覆盖 |
| `probe_read_kernel` | 窄子集可以纯 rewrite；一般情形需要 safe-load contract | **一般情形需要**（或等价内核 special-case） | 不建议先做纯 rewrite |
| `ktime_get_ns` | helper 保留；若要 inline 只能走新 intrinsic / arch-specific special case | **需要** | 纯 bytecode rewrite 不可行 |

这里最重要的判断是：

- `skb_load_bytes` 是**bytecode 问题**
- `probe_read_kernel` / `ktime_get_ns` 是**ABI / helper contract 问题**
- `skb_store_bytes` 是**语义副作用 + 成本模型问题**

## 8. 优先级排序

这里给的是**工程实现优先级**，不是“如果某天全都解决，理论收益谁最大”。

### P0: `skb_load_bytes -> direct packet access`

理由：

- 语义最接近 direct access
- verifier 合同现成
- corpus 中 `590` 个 site，且 `cilium` 一家就有 `428`
- 固定小长度特别多，后续还能叠加已有 native-code pass

### P1: `skb_store_bytes` 的 `flags=0` 窄子集

理由：

- `498 / 536` site 的 `flags=0`
- 但要明确避开 TC direct-write prologue 反噬、checksum/hash side effect、non-linear/cloned skb
- 适合做“严格过滤后少量命中”的 specialized pass，不适合做 blanket rewrite

### P2: `probe_read_kernel` 的“typed, non-faulting, fixed-size”极窄子集

理由：

- corpus 体量极大，Tracee case study 价值高
- 但**fault handling 不能省**
- 只有在 pointer provenance 已经被 verifier 证明、安全 contract 非常清楚的前提下才值得尝试

换句话说：  
这是**高 leverage、低 readiness**，更像第二阶段研究线。

### P3: `ktime_get_ns`

理由：

- 没有参数 specialization
- 纯 bytecode rewrite 不可行
- helper 已经是 fast monotonic path
- CSE/hoisting 会碰 observable time semantics

如果只看“现在能安全落地多少真实收益”，它应该排最后。

## 9. 最终结论

把 #444 压缩成一句话：

> **值得立刻做的是 packet helper specialization，尤其 `skb_load_bytes`；不值得把 `probe_read_kernel` 当成普通 load peephole 来做；`ktime_get_ns` 不是 bytecode rewrite 题。**

更具体地说：

- **先做**：`skb_load_bytes -> direct packet access`
- **谨慎做**：`skb_store_bytes(flags=0)` 的极窄子集
- **先研究 contract 再谈实现**：`probe_read_kernel`
- **暂缓**：`ktime_get_ns`

这和论文叙事也一致：

- networking datapath 的 helper specialization 可以作为**近期可交付的 optimization pass**
- tracing/security 的 `probe_read_kernel` 更适合作为**“BpfReJIT 能扩展到 helper ABI specialization”** 的长期研究方向，而不是第一波实现
