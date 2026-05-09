# Katran `balancer_ingress` x86 优化上界分析

日期：2026-05-08

范围：Katran XDP `balancer_ingress`，x86_64，当前 BPF JIT/ReJIT 证据、native 编译对照、ReJIT-only 与手写 x86 上界估算。

本文是分析产物；没有修改框架代码，没有 commit。native 编译 stub 放在 `/tmp/katran_native_compile`，仓库内主输出是本文。

## 0. 结论先行

当前 `balancer_ingress` 是一个已经很大的 BPF 程序：输入 2,542 条 BPF insn，kernel xlated 23,840 B，baseline x86 JIT 13,629 B。

May 8 运行数据：baseline `run_time_ns_delta / run_cnt_delta = 317.39 ns/run`；post 行为 `299.07 ns/run`；ratio `0.9423`，speedup `1.061x`，绝对节省 `18.32 ns/run`。

用 3.0 GHz 仅作换算：baseline 约 `952 cycles/pkt`，post 约 `897 cycles/pkt`，当前已回收约 `55 cycles/pkt`。

这个 55-cycle 收益只吃到了手写 x86 上界差距的一小段。真正大头不是某一个 exotic 指令，而是 map/helper 调用、verifier 形状、BPF ABI register pressure、packet bounds/null checks，以及 benchmark 配置没有被 specialization。

生产安全的 ReJIT-only 上界大约是 baseline 的 `1.15x-1.35x`。如果允许 benchmark-only specialization，把固定 VIP、uniform `ch_rings`、`reals[1]`、`ctl_array[0]` 都内联，上界可能到 `1.8x-2.5x`。

去掉 BPF 包装后的手写/native x86 上界估计：generic direct-map hot path 约 `180-300 cycles/pkt`；完全 benchmark-specialized one-VIP/one-real path 约 `120-180 cycles/pkt`。相对当前 900-950 cycles 的 BPF JIT，大概是 `3x-5x` 和 `5x-8x` 两档。

## 1. 证据边界

本轮无法拿到真实 live x86 JIT dump。宿主机 `bpftool prog show` 返回 `Operation not permitted`，已有 `KEEP_WORKDIRS=1` corpus run 只保留了失败 workdir tarball，没有成功优化后 JIT 机器码。

所以 `docs/tmp/katran_jited.disasm` 是状态说明，不是真实 `bpftool prog dump jited` 输出。本文对 JIT basic block 的判断来自 BPF xlated 形状、当前 pass report、native objdump 和性能计数；精确 machine-code 结论需要后续在 KVM guest 或 privileged host 重新 dump。

本轮生成/使用的仓库产物：

- `docs/tmp/katran_native_compile/clang.s`
- `docs/tmp/katran_native_compile/native.disasm`
- `docs/tmp/katran_xlated_baseline.disasm`
- `docs/tmp/katran_xlated_post_5pass.disasm`
- `docs/tmp/katran_xlated_prefetch_attempt.disasm`
- `docs/tmp/katran_baseline_windows.disasm`
- `docs/tmp/katran_post5_windows.disasm`
- `docs/tmp/katran_prefetch_attempt_windows.disasm`
- `docs/tmp/katran_jited.disasm`

native 编译命令：

```bash
clang -O3 -mavx2 -mbmi2 -fno-stack-protector \
  -I/tmp/katran_native_compile/native_include \
  -Irunner/repos/katran \
  -S -masm=intel runner/repos/katran/katran/lib/bpf/balancer.bpf.c \
  -o docs/tmp/katran_native_compile/clang.s
```

native objdump 命令：

```bash
clang -O3 -mavx2 -mbmi2 -fno-stack-protector \
  -I/tmp/katran_native_compile/native_include \
  -Irunner/repos/katran \
  -c runner/repos/katran/katran/lib/bpf/balancer.bpf.c \
  -o /tmp/katran_native_compile/build/balancer_native.o

objdump -d -M intel /tmp/katran_native_compile/build/balancer_native.o \
  > docs/tmp/katran_native_compile/native.disasm
```

stub 只为让 BPF C 源码能 native 编译：定义 `SEC`、map declaration macro，以及 `bpf_map_lookup_elem`、`bpf_ktime_get_ns`、`bpf_get_smp_processor_id`、`bpf_xdp_adjust_head` 等 helper 的 inline/no-op 替身。因此 native 产物不能直接 perf 当作 Katran dataplane，只能用于 instruction selection 和代码形状对照。

## 2. 输入程序和 map inventory

主要 bytecode artifact：

- `corpus/results/x86_kvm_corpus_20260430_193236_794969/details/workdirs/553/prog.bin`
- 同目录 `prog_info.json`、`map_fds.json`、`target.json`、`bpfopt_report.json`

`prog_info.json` 要点：

- program name: `balancer_ingres`
- type: XDP
- input bytecode: 20,336 B / 2,542 insn
- xlated length: 23,840 B
- jited length: 13,629 B
- func_info: 3
- line_info: 1,084

prompt 里说 13 maps；本地 `map_fds.json` 实际有 14 个：

| map | role / relevance |
|---|---|
| `stats` | mutable per-cpu stats，不能常量内联 |
| `vip_map` | hot VIP lookup；benchmark traffic 固定但 key 来自 packet |
| `lru_mapping` | per-cpu map-in-map / LRU path |
| `fallback_cache` | fallback path |
| `quic_stats_map` | QUIC stats，benchmark TCP 热路径通常不是第一优先级 |
| `server_id_stats` | server-id stats |
| `reals` | dependent on selected real id |
| `vip_to_down_rea` | down-real map-in-map |
| `ctl_array` | `ctl_array[0]` 是最好的 Route A 候选 |
| `reals_stats` | mutable stats |
| `ch_rings` | hot CH ring lookup，benchmark 上界关键 |
| `vip_miss_stats` | mutable diagnostic stats |
| `lru_miss_stats` | mutable diagnostic stats |
| `server_id_map` | server-id path |

benchmark 配置对 specialization 非常友好：一个 VIP，一个 real，VIP `10.100.1.1:8080/TCP`，router MAC `02:00:00:00:00:0b`，`CH_RING_SIZE=65537`，VIP 0 的 ring entries 指向 real 1。但这些不是 production-safe 默认假设。

## 3. 当前 ReJIT/pass 现状

May 8 artifact 中 program id 9 的 pass 状态：

| pass | bpfopt matched/applied | live ReJIT | insn effect |
|---|---:|---|---:|
| `rotate` | 0 / 0 | ok | 2542 -> 2542 |
| `cond_select` | 7 / 7 | ok | 2542 -> 2549 |
| `extract` | 0 / 0 | ok | 2549 -> 2549 |
| `endian_fusion` | 6 / 6 | ok | 2549 -> 2549 |
| `bulk_memory` | 0 / 0 | ok | 2549 -> 2549 |
| `prefetch` | 42 / 42 | failed | 2549 -> 2633 offline |

`prefetch` offline 插入了 42 个 kfunc call、增加 84 条 BPF insn，但 live `BPF_PROG_REJIT` 失败，errno 7 / `Argument list too long`。因此当前 accepted post state 应当按 last successful state 理解：`cond_select + endian_fusion`，不是成功接受的 42-site prefetch。

baseline offline disasm 统计：

- 2,542 insn
- 249 branch insn
- 941 memory ops
- 365 stack memory ops
- 70 static `bpf_map_lookup_elem`
- 8 static `bpf_ktime_get_ns`
- 4 static `bpf_xdp_adjust_head`
- 4 static `bpf_map_update_elem`
- 2 static `bpf_get_smp_processor_id`

post-5-pass offline disasm：

- 2,549 insn
- 242 branches
- 935 memory ops
- 361 stack memory ops
- same 70 map lookups
- 7 `bpf_select64`
- 4 `bpf_endian_load32`
- 2 `bpf_endian_load16`

这解释了为什么当前收益有限：成功 pass 主要减少少量 branch/mem 形状，没有碰最大头的 map helper、stack key、null checks、packet bounds、hash/ring arithmetic。

## 4. Hot path

benchmark 热路径是 IPv4/TCP XDP path：

`balancer_ingress -> process_packet -> parse_l3_headers -> parse_tcp -> VIP key -> vip_map -> stats/LRU bookkeeping -> get_packet_dst -> is_under_flood -> get_packet_hash -> ch_rings -> reals -> ctl_array -> stats/reals_stats -> IPIP encap -> XDP action`

关键源码：

- `runner/repos/katran/katran/lib/bpf/balancer.bpf.c`
- `runner/repos/katran/katran/lib/bpf/pckt_parsing.h`
- `runner/repos/katran/katran/lib/bpf/pckt_encap.h`
- 其他 helper header 在 `runner/repos/katran/katran/lib/bpf/*.h`

热路径中的 dominant operations：

- packet bounds checks
- VIP map lookup
- per-cpu stats lookup/update
- LRU bypass / CPU id / LRU map path
- jhash
- CH ring modulo/index
- `ch_rings` map lookup
- `reals` map lookup
- `ctl_array[0]` config lookup
- encapsulation header writes

## 5. Native compile 观察

native disasm 的静态 instruction mix 说明 LLVM 在没有 BPF target/verifier 限制时想做什么：

| instruction/family | count-ish | implication |
|---|---:|---|
| `mov` | 435 | scalar data motion still dominates |
| `lea` | 152 | address arithmetic and scaled adds |
| `movzx` | 132 | packet byte/halfword extraction |
| `cmp` | 125 | checks still exist |
| `test` | 121 | flag checks |
| conditional jumps | 200+ | cold/hot path checks still significant |
| `rorx` | 20 | jhash rotate lowering |
| `cmovb` / `cmove` | 16 | branchless select |
| `sete` / `setne` | 3 | boolean materialization |
| `bswap` | 2 | endian scalar lowering |
| AVX/SSE moves/adds | dozens | userspace-native vectorization; kernel BPF should not copy this blindly |
| `imul` | 2 | magic-constant arithmetic, likely modulo lowering |

没有观察到：`pext`、`pdep`、`bzhi`、`andn`、`crc32`、`vpgather`、AES-NI。

所以 Katran 的缺口不是 PEXT/PDEP/BZHI 这类 BMI2 指令。native 想要的是 rotate、cmov/setcc、constant modulo/address arithmetic、copy grouping，以及大量 map/helper 结构被消掉。

native 主体 prologue 大约 reserve 168 B stack，远小于 BPF 512 B 限制。栈限制本身不是 blocker；BPF 栈流量来自 helper key materialization、packet structs、spilled live values、verifier-visible lifetime。

## 6. Native vs BPF/JIT basic block 对照

这里的 JIT 列是从 BPF xlated 形状和 pass 状态推断，不是 live x86 JIT dump。

| hot block | native x86 shape | current BPF/ReJIT shape | gap |
|---|---|---|---|
| entry/eth parse | direct load, `movzx`, `cmp` | packet ptr load + `data_end` guard | verifier bounds overhead |
| IPv4 parse | flag reuse, fewer temps | repeated offset/bounds branches | range facts reuse不足 |
| TCP parse | direct halfword/byte reads | header availability checks | 部分语义必要，部分可 merge |
| VIP key build | registers/stack struct | BPF stack slots for helper key | helper ABI forces addressable key |
| `vip_map` lookup | with specialization can be compare + constant/direct value | `r1=map`, `r2=&key`, call, null check | major gap |
| CPU/LRU key | native could inline/specialize | CPU helper shape + stack key + lookup | CPU helper may already be kernel-inline |
| jhash | about 20 `rorx` | current `rotate` pass finds 0 | missing canonicalization |
| CH ring index | `imul` magic / `lea` style | likely modulo/mul/add BPF sequence | must confirm real JIT |
| `ch_rings` | direct/constant under benchmark specialization | map lookup by hash-derived key | largest benchmark-only lever |
| `reals` | dependent direct pointer/constant | map lookup by real id | follows CH specialization |
| `ctl_array[0]` | immediate MAC/direct array | stack key 0 + lookup + null check | best safe Route A target |
| stats updates | direct per-cpu pointer possible | lookup/value pointer + increments | mutable map semantics |
| encap | direct stores, sometimes vectorized native | BPF packet writes + adjust helper semantics | helper/pointer revalidation |
| exit | direct return | BPF return in `r0` | small |

## 7. BPF 强制约束的代价

寄存器：BPF 有 `R0-R10`，`R10` 是 frame pointer，`R0` 是 return，`R1-R5` 是 helper args 并且跨 helper clobber。native x86_64 有 16 GPR，编译器能自然使用 `rbx/rbp/r12-r15` 等 callee-saved register。当前 BPF 有 365 个静态 stack memory ops，很多是 ABI/verifier 形状，不是算法需要。

栈：native 约 168 B stack，BPF 能放进 512 B。问题不是 BPF stack 太小，而是 BPF 必须把 map key、packet metadata、跨 helper live values 变成 verifier 可见的栈对象。

packet pointer：Katran 是 XDP direct packet pointer，不是 skb/dynptr 主导。开销来自 `data + off <= data_end`、header length、post-adjust reload/revalidate 等 verifier 证明。ReJIT 能删除 dominated/redundant checks，但不能无条件删除真正的 packet safety。

tail-call：本分析的 May 8 `balancer_ingress` row 有非零 `run_cnt_delta`，standalone attach 模式下可直接用于该程序。一般 tail-called target 的 `run_cnt=0` caveat 仍成立，但这里不是主 blocker。

helper boundary：map lookup/helper call 会强迫 `R1/R2` 准备、stack key、call、`R0` null check、live value reload。native/direct-map 形状常常只是 `lea + cmp/load`。

## 8. 现有 kinsn 映射

| pass | kinsn | intended x86 | Katran status |
|---|---|---|---|
| `rotate` | `bpf_rotate64/32` | `RORX`/rotate | 0 sites |
| `cond_select` | `bpf_select64` | `CMOVcc` | 7 sites |
| `extract` | `bpf_extract64` | `BEXTR` | 0 sites |
| `endian_fusion` | `bpf_endian_load16/32/64` | `MOVBE`/fused endian load | 6 sites |
| `bulk_memory` | `bpf_memcpy_bulk/memset_bulk` | `rep movsb/stosb` or scalar bulk | 0 sites |
| `prefetch` | `bpf_prefetch` | `PREFETCHT0` | 42 offline, live fail |
| `ccmp` | compare-combine | arm64-focused | not x86 Katran |

## 9. 新 kinsn/pass 候选

### 9.1 `jhash_rotate_canonicalize`

Trigger：BPF bytecode 中 Jenkins hash 的 `(x << c) | (x >> (32-c))` 或反向 shift/or，夹在 add/sub/xor 之间。

替换：`bpf_rotate32` kinsn 或 x86 JIT peephole，lower 到 `RORX`/`ROL`/`ROR`。

证据：native 有约 20 个 `rorx`；当前 `rotate` pass 对 Katran 是 0/0。

预期 site：12-20 static sites，主要在 `get_packet_hash` / `jhash_2words`。

估算收益：单 site 1-2 cycles；如果都在 CH hot path，合计可能 10-30 cycles/pkt。第一步应做 bytecode shape census。

### 9.2 `const_mod_reduce`

Trigger：`hash % RING_SIZE`，其中 `RING_SIZE=65537`，随后用于 `ch_rings` key。

替换：reciprocal multiply-high / shift / subtract，x86 用 magic `imul` 序列，避免 division。

证据：native 有 magic-constant `imul`，没有 `div/idiv`；但当前 BPF JIT 是否已经优化 constant modulo 需要 live JIT dump 确认。

预期 site：1-2 hot sites。

估算收益：如果当前 JIT emits divide，15-35 cycles/pkt；如果已是 reciprocal，接近 0。优先级是先验证再实现。

### 9.3 `setcc_bool`

Trigger：branch materializes boolean 0/1，例如 init register、conditional branch、overwrite opposite value。

替换：x86 `SETcc + zero extend`，或显式 `bpf_setcc64` kinsn。

证据：native 有 `sete/setne`；当前 `cond_select` 只覆盖 arbitrary select，不覆盖所有 bool materialization。

预期 site：2-4 Katran static sites。

估算收益：1-3 cycles/site；若移除 unpredictable branch 则更高。Katran 本地收益小，corpus 泛化价值可能更大。

### 9.4 `lea_index_fold`

Trigger：`vip_num * 65537 + hash_mod` 或等价 CH ring index arithmetic。

替换：`(vip_num << 16) + vip_num + hash_mod`，用 `LEA/add` 或 BPF-level strength reduction。

证据：native `lea` 很多；CH ring index 是 hot path 中心。

预期 site：1-2 hot sites。

估算收益：1-5 cycles/pkt；若同时缩短 map-key live range，收益更大。实现风险较低，但需精确 unsigned semantics。

### 9.5 `small_copy_scalar_pack`

Trigger：固定 8/12/16/24/32 B packet/header/struct copy，被 BPF 表达成 byte/halfword ladder；当前 `bulk_memory` 对 Katran 0 sites。

替换：paired scalar 64-bit loads/stores，必要时 `rep movsb`；不要用 AVX/SIMD，因为 kernel FPU state 成本会压过小 copy 收益。

证据：native userspace compile 使用 `vmovdqu/vmovdqa/vpaddq` 等，但 kernel BPF 不应照搬 SIMD。

预期 site：4-8 static sites，hot sites 可能在 encap 和 metadata copy。

估算收益：2-8 cycles/executed copy；若减少 stack temp 更高。

### 9.6 `branch_flip_pgo`

Trigger：有真实 per-site PMU：`branch_count`、`branch_misses`、`miss_rate`、`taken`、`not_taken`。

替换：按 PGO 反转/重排 branch layout。不能 heuristic fallback，缺 PMU 必须失败。

证据：baseline 249 branches，post 仍 242；hot path 有 QUIC/ICMP/LRU/flood/server-id/fallback 等大量 cold checks。

预期 site：10-20 candidate branches，真正改动应更少。

估算收益：已 predictable 的 branch 近 0；真正 mispredict 的 hot branch 每个可省 5-20 cycles。

### 9.7 `selective_prefetch_budget`

这不是新机器指令，而是现有 `prefetch` kinsn 的必要策略修复。

Trigger：map lookup result non-null 后，后续 block 会 dereference map value，且距离足够隐藏 latency。

替换：只对 hot subset 插入 `bpf_prefetch`，lower 到 `PREFETCHT0`。

证据：offline 找到 42 sites，live ReJIT 因 E2BIG/参数长度失败；一次性插 42 个太粗。

预期 accepted sites：先做 4/8/12/16 site budget sweep，目标 6-12 个 hot sites，例如 `vip_map` value、`ch_rings` value、`reals` value、少量 stats value。

估算收益：value 已在 cache 时为 0 或负；隐藏一两个 miss 时可省 10-50 cycles/pkt。

## 10. Helper / map 转换机会

`bpf_map_lookup_elem` 是最大静态问题：baseline 有 70 个 static lookup。hot path 只执行其中一部分，但每次都包含 map arg setup、stack key、call、`R0` check、spill reload、value field loads。

`ctl_array[0]`：force-inline recipe 识别两个站点，key 常量 0，default-router MAC 在 benchmark 中 read-mostly。这是最安全的 Route A 目标。预期收益约 20-40 cycles on executed path，且能删 stack key/null check/byte loads。

`vip_map`：热 key 来自 packet，benchmark 固定 VIP 但 verifier 不知道。可以在显式 traffic specialization 下把 lookup 变成固定 key compare + direct metadata constants。预期 2-4 static sites，约 30-80 cycles/pkt；不应作为 default policy。

`ch_rings`：benchmark VIP 0 的所有 ring entries 指向 real 1。如果允许 snapshot + invalidation，可把 hash-derived ring lookup 替换成 constant real id 1。这是最大 benchmark-only lever，预期 50-150 cycles/pkt，语义风险也最高。

`reals`：只有当 `ch_rings`/server-id/LRU path 已证明 real id 后才能内联。作为 dependent specialization，预期 1-3 sites，约 30-80 cycles/pkt。

mutable stats maps：`stats`、`reals_stats`、`vip_miss_stats`、`lru_miss_stats`、`quic_stats_map` 不应常量内联。可能方向是 direct per-cpu pointer fast path，但这是 helper/kernel/JIT 语义工作，不是普通 map_inline。

`bpf_get_smp_processor_id`：设计文档指出相关路径已 kernel-inline，不要把它算成大新收益。只有 pinned CPU specialization 才可能进一步删 setup，但 workload 风险高。

`bpf_ktime_get_ns`：native stub 用 `rdtsc` 只是为了编译，不是语义等价替换。低优先级。

`bpf_csum_diff`：可能昂贵，但默认 IPv4/IPIP hot path 里不是第一瓶颈。checksum fold/ADC chain 可以研究，优先级低于 map 和 scalar arithmetic。

`bpf_xdp_adjust_head`：会改变 packet headroom 并 invalidate packet pointers；一般不能用普通 BPF-to-BPF 安全替换。ReJIT-only 低优先级。

`bpf_redirect_map`：不是当前 `balancer_ingress` XDP_TX hot path 主 helper，暂不优先。

## 11. Verifier-imposed elision 机会

Dominated packet bounds：如果早期已证明 `data + large_off <= data_end`，后续 smaller checks 可由 `bounds_check_merge`/range dominance 删除。预计 20-60 cycles/pkt 的量级，但必须保持 verifier acceptance。

Map helper 内部 bounds/null：array map key 常量或 range-bounded 时，generic helper 仍做检查。只有 map specialization/direct value pointer 才能真正删除，`ctl_array[0]` 是安全起点，`ch_rings/reals` 是 benchmark-only 大头。

Required config null check：`ctl_array[0]`、固定 `vip_map` entry 在显式 invariant 下可删 null branch。必须有 map update invalidation，不可静默隐藏配置错误。

Stack key materialization：`store key fields -> r10-off -> pass &key` 是 map-inline 能直接删的结构。对 constant-key array lookup 风险低，对 packet-derived key 风险高。

`xdp_adjust_head` 后 pointer revalidation：encap path 中存在价值，但 helper 语义会 invalidate 旧 packet pointer proof，不适合作第一波。

## 12. 上界估算

May 8 实测：

| phase | ns/run | cycles/run @ 3.0 GHz |
|---|---:|---:|
| baseline | 317.39 | 952 |
| post row | 299.07 | 897 |
| saving | 18.32 | 55 |

CPU 频率未在本轮测量；cycle 数只作线性换算。2.6 GHz 时 baseline 约 825 cycles，3.5 GHz 时约 1,111 cycles。

native object 不能 honest `perf stat`，因为 helper/map/XDP semantics 都被 stub 掉。合理 decomposed 上界：

| target | estimate | speedup vs 952-cycle baseline |
|---|---:|---:|
| current baseline BPF JIT | 950-ish cycles | 1.0x |
| current post row | 900-ish cycles | 1.06x |
| generic native direct-map | 180-300 cycles | 3.2x-5.3x |
| benchmark-specialized native | 120-180 cycles | 5.3x-7.9x |

generic native 拆分直觉：parse/check 40-70 cycles，jhash/CH index 30-60，direct map/value loads 40-100，stats/encap stores 40-80，branch/return/bookkeeping 30-60。

benchmark-specialized native 会删 `vip_map`、`ch_rings`、dependent `reals`、大部分 CH index/null/drop 分支，所以可落到 120-180 cycles/pkt 量级。

ReJIT-only production-safe：当前约 55 cycles；加 `wide_mem`、bounds merge、rotate/mod/setcc、`ctl_array[0]`、budgeted prefetch，合理总上界 `1.15x-1.35x`。

ReJIT-only benchmark-specialized：固定 VIP + uniform CH ring + `reals[1]` + `ctl_array[0]` + scalar/bounds/prefetch，合理上界 `1.8x-2.5x`。仍低于 native，因为 BPF ABI、helper semantics、verifier-friendly CFG、寄存器分配和 kernel SIMD 限制仍在。

## 13. 理想 BR/pass list

Default-safe / near-safe：

| pass | expected Katran sites | reason |
|---|---:|---|
| `noop` | 1 program | verifier-state producer |
| `wide_mem` | 4 from eval | collapse byte ladders |
| `const_prop` | unknown | feed DCE/bounds |
| `dce` | unknown | remove dead artifacts |
| `bounds_check_merge` | 5-20 hot candidates | packet check dominance |
| `cond_select` | 7 observed | CMOV lowering |
| `endian_fusion` | 6 observed | fused endian loads |
| `jhash_rotate_canonicalize` | 12-20 | recover native `RORX` shape |
| `const_mod_reduce` | 1-2 | avoid division if present |
| `lea_index_fold` | 1-2 | shorten CH key arithmetic |
| `setcc_bool` | 2-4 | branchless bool |
| `small_copy_scalar_pack` | 4-8 | reduce copy ladders |
| `selective_prefetch_budget` | 6-12 accepted | avoid 42-site E2BIG |

Specialization-only：

| pass | expected Katran sites | reason |
|---|---:|---|
| `map_inline_route_a` | 2 `ctl_array[0]` | safest config inline |
| `traffic_key_specialize_vip_map` | 2-4 | fixed benchmark VIP |
| `uniform_ch_ring_specialize` | 1-2 | all ring slots -> real 1 |
| `dependent_reals_inline` | 1-3 | after real id proof |
| `required_config_null_elide` | tied to above | remove impossible null branch |
| `branch_flip_pgo` | 10-20 candidates | only with real per-site PMU |

## 14. 优先级排序

| rank | item | work | benefit | default-safe? | note |
|---:|---|---|---|---|---|
| 1 | Finish `map_inline` Route A for `ctl_array[0]` | medium | moderate | yes-ish | 已知两站点，纪律最好 |
| 2 | `prefetch` budget / E2BIG avoidance | low-medium | moderate-high | yes if accepted | 42 sites 已找出但 live fail |
| 3 | Verify `%65537` JIT, then `const_mod_reduce` | low then medium | high if divide exists | yes | 先 dump machine code |
| 4 | `jhash_rotate_canonicalize` | medium | moderate | yes | native 20 `rorx`，当前 0 |
| 5 | Make `bounds_check_merge` effective on Katran | medium-high | moderate | yes if verified | 需要 dominance/range proof |
| 6 | Keep/re-enable `wide_mem` | low-medium | small-moderate | yes | eval 有 4/4 |
| 7 | `setcc_bool` | medium | small local, broader corpus | yes | 补 `cond_select` |
| 8 | `lea_index_fold` | low-medium | small-moderate | yes | CH index |
| 9 | `small_copy_scalar_pack` | medium | small-moderate | yes with proof | 不用 SIMD |
| 10 | VIP traffic specialization | high | high benchmark-only | no | 需要 invalidation |
| 11 | uniform CH-ring specialization | high | very high benchmark-only | no | 最大上界杠杆 |
| 12 | dependent `reals` inline | medium | high only after rank 11 | no | 依赖 real id proof |
| 13 | `branch_flip_pgo` | medium-high | unknown-moderate | only with PMU | 必须真实 per-site PGO |
| 14 | helper inline: `ktime/csum/xdp_adjust_head` | high | uncertain | mostly no | 语义风险高 |

## 15. 下一步测量

必须补的第一个测量是真实 `bpftool prog dump jited`：baseline 和 post-ReJIT 都要，从 KVM guest 或 privileged host 抓。

第二个测量是 CH modulo 路径：确认 `%65537` 是否已经被 x86 JIT lower 成 reciprocal arithmetic；如果还是真 divide，`const_mod_reduce` 立即变高优。

第三个测量是 jhash rotate bytecode census：解释 native 20 个 `rorx` 为什么 current `rotate` pass 是 0/0。

第四个测量是 prefetch site budget sweep：4、8、12、16 sites，避免再一次 42-site E2BIG。

第五个测量是只开 `ctl_array[0]` Route A 的 Katran run，在尝试 VIP/ring specialization 前先拿一个干净小步。

第六个测量是 `branch_flip` 所需的真实 per-site PMU；没有 PMU 就不要做 heuristic branch flip。

## 16. Bottom line

当前 ReJIT 结果只回收了手写 x86 差距中的小段 scalar 机会。成功 pass 主要是 `cond_select` 和 `endian_fusion`；`prefetch` 找到了站点但没有 live accepted。

native 编译显示的新增指令机会集中在 rotate、setcc/cmov、constant arithmetic 和 copy grouping，不是 PEXT/PDEP/BZHI/AESNI。

生产安全路线先做 `ctl_array[0]` Route A、budgeted prefetch、`%65537` 验证、jhash rotate canonicalization、bounds merge。

benchmark 上界路线的决定性杠杆是固定 VIP、uniform `ch_rings`、dependent `reals[1]`、required config null-elide。这能把 Katran 从当前约 `1.06x` 推向 `1.8x-2.5x` 的 ReJIT-only 区间，但仍不会追平完全手写/native x86 fast path。

## 17. Map_inline Route A 分阶段 roadmap (live tracking)

### 算法判据 (replaces §10's vague "可 inline" 列)

**正确判据**: BPF kernel 数据通路是否调用 `bpf_map_update_elem` / `_delete_elem` / `_push/_pop_elem` 写这个 map (LRU 类型本身 lookup 即改 LRU 顺序也算)。
- 写 → snapshot 值 stale,**不能 inline**
- 不写 → 可以 inline (key 是源码 const 还是 packet-derived 都不影响,只是 paper 标签 production-safe vs workload-specialized 的区别)

**实施状态** (2026-05-08): 旧 `BPF_F_RDONLY_PROG` flag guard 已被 **#244 kernel-write static filter** 替换 — bpfopt 扫 BPF bytecode 找 `bpf_map_update_elem` / `_delete_elem` / `_push_elem` / `_pop_elem` 调用,加 LRU 类型规则,任何写入 map 的 lookup 站点都拒绝 inline,无论有无 hint。LRU/HASH_OF_MAPS 等也按规则拒。

### 分阶段 inline 计划

| Phase | 内容 | 状态 | 期望新增 site | paper 标签 |
|---:|---|---|---:|---|
| 1 | `ctl_array[0]` ×2 hard fold | **DONE** (#242, ratio 0.9715) | 2 | production-safe |
| 2 | `vip_map[VIP+port+TCP]` ×N hard fold | **DONE** (#243, applied=4 含 port=0 fallback) | +4 | workload-specialized |
| 3a | bpfopt map-level kernel-write 静态过滤 + map_name hint 接口 + hard/soft fold 2D 矩阵 | **DONE** (#244,但软 fold broken,见 #249) | 0 (correctness) | bug fix |
| 3b | bpfopt compressed overlay reader (uniform/sparse/enumerated) + size-skip per-site diagnostic | **DONE** (#245,310+ 测试通过) | 0 (enabler) | enabler |
| 3c | 写 `runner/config/passes/map_inline/overlays/katran/{ch_rings,reals}.json` + yaml 内嵌 jq 注入 overlays.json + `--inline-hint=ch_rings:!00000000` + `--inline-hint=reals:!01000000` | **DONE** (#246, applied=11) | +8 (ch_rings 2 + reals 3 实际,offset 多发出 5 个 fold) | workload-specialized |
| 3d | server_id_map uniform overlay + hint | **DONE** (#246 增量) | +2 (PC 534, 886) | workload-specialized |
| 4 | map-in-map Mode A (outer+inner 双硬 hint) | **DONE** (#247, katran 0 applied 因 inner LRU 拒) | 0 katran (inner LRU 拒) | future-paper enabler (cilium/tracee 真用) |
| 4b | map-in-map Mode B outer-only fold + LPM_TRIE NULL fold | **DONE** (#254, 323 测试过) | +N (lru_mapping/global_lru_maps outer + lpm_v4/v6 NULL) | workload-specialized |
| 5 | 调研 14 skipped 站点 map 归属 | **DONE** (#248,§19) | — | discovery |
| const_prop EACCES | Path C verifier post-state guard 修复 #244 触发的 const_prop bug(默认 13-pass 退化 1.23) | **DONE** (#250 调研 + #251 Path C + #252 二级 InsnDeltaState guard) | — | bug fix |
| 软 fold 重设计 | else=NULL + hit 整段 fold scalar (verifier-clean) | **DONE** (#249 实施 + #253 unreachable insn 修复) | 解锁多 VIP / dynamic key 安全 fold | enabler |
| const_prop 单跑无价值 audit | 70 fold 中 57 用 LD_IMM64 反而胀 bytecode → 必须跟 dce 配套报数据 | **DONE** (#255) | — | paper integrity |
| pass 架构 audit | 重复造轮子 / 抽象缺口 / LLVM 对比 / 渐进改进路径 | **IN PROGRESS** (#256) | — | engineering 重构准备 |

### 各 Map 现状 (inline 适用性)

| Map | 类型 | size | BPF 写? | 当前 dump? | 解锁路径 |
|---|---|---:|---|---|---|
| ctl_array | ARRAY | 128B | NO | ✓ | **Phase 1 ✅** |
| vip_map | HASH | 4KB | NO | ✓ | Phase 2 |
| ch_rings | ARRAY | 256KB | NO | ❌ SkippedBySize | Phase 3 (overlay uniform) |
| reals | ARRAY | 128KB | NO | ❌ SkippedBySize | Phase 3 (overlay sparse) |
| stats / reals_stats / lru_miss_stats / vip_miss_stats / quic_stats_map / stable_rt_stats / decap_vip_stats / tpr_stats_map / server_id_stats | (PER)CPU/ARRAY | small | **YES** (RMW) | ✓ | **不 inline** (kernel 写) |
| fallback_cache | LRU_HASH | varies | YES (LRU + update) | varies | 不 inline |
| lru_mapping (outer) | ARRAY_OF_MAPS | small | NO outer | ✓ | Phase 4 (但 inner LRU 仍不可 inline → 整 chain 阻塞) |
| lru_mapping (inner) | LRU_HASH | varies | YES | varies | 不 inline |
| vip_to_down_reals_map | HASH_OF_MAPS | empty | NO | ✓ outer | Phase 4 (benchmark 空,inline 0 site) |
| global_lru_maps / fallback_glru | HASH_OF_MAPS / LRU_HASH | varies | YES (inner LRU) | varies | 不 inline |
| flow_debug_map | HASH | varies | YES (debug_helpers update) | varies | 不 inline |
| server_id_map | HASH | varies | NO | ✓ | 可 inline 但 benchmark 不必命中 |
| lpm_src_v4 / lpm_src_v6 | LPM_TRIE | varies | NO | varies | LPM_TRIE fold 复杂,paper 不优先 |

### Phase 数据表 (随每次 SAMPLES=3 测试更新)

| Phase | result_dir | sites_applied (map_inline) | per-prog geomean | 备注 |
|---:|---|---:|---:|---|
| baseline (kinsn 6-pass, no map_inline) | x86_kvm_corpus_20260508_041822_768126 | 0 | 0.9423 | 1.061x speedup,55 cycles |
| Phase 1 (ctl_array×2 hint + map_inline) | x86_kvm_corpus_20260508_231402_301128 | 2/16 | 0.9715 | map_inline 排在 noop 后第 2 位避免 PC 漂移;skipped 14: 8 verifier-state miss / 2 fixed-offset miss / 4 map-in-map (待 Phase 3/4) |
| Phase 2 (+ vip_map hard fold) | x86_kvm_corpus_20260509_013938_112049 / 015615_631003 | 6/23→73 | 0.8811 / **1.0099** | 两次 run 数据差异大(VM 噪声:baseline avg_ns 228→151)。applied=6 一致(ctl_array×2 + vip_map×4)。第二次跑用 #245 后代码,matched 涨到 73 是因为 size-skipped map 现在可见(ch_rings 2 + reals 6 + lru_miss_stats/reals_stats/etc.)。真实 phase 2 speedup 在 0.88-1.01 噪声窗内,需 paper-grade 多 run 平均才能确定 |

| Phase 3 (+ ch_rings uniform + reals sparse overlay,3-pass) | x86_kvm_corpus_20260509_022133_477580 / 031932_134386 | **11/78** | 0.9454 / **0.7458** | 第 1 次:**+5.8%** (baseline 156 ns)。第 2 次 (#252 const_prop 二级 guard 后):**+25.4%** (baseline 250 ns,VM 噪声放大)。Applied 11 = ctl_array×2 + vip_map×4 + ch_rings×2 + reals×3。const_prop 70/126 (#251+#252 拒 56 unsafe ptr-arith fold);pipeline 全 ok |
| **map_inline only (无 const_prop, 隔离测试)** | x86_kvm_corpus_20260509_031956_984494 | 11/78 | **1.0670** | **map_inline 单独跑慢 6.3%**。原因:hard fold 替换 lookup 后留下死指令 (lookup setup / null check / unused offset loads),没有 const_prop+dce 配套清理 → 字节码反而更大、JIT 输出更长。**关键论点 for paper: map_inline 不是独立优化,必须跟 const_prop+dce pipeline 配套** |
| Phase 4 (+ server_id_map + lpm_src_v4/v6 NULL fold + lru_mapping/global_lru_maps outer-only) | TBD (bddhjo4m4 跑中) | 期望 **+8 sites** | TBD | #254 落地 outer-only mode B + LPM enumerated empty NULL fold。新增 hint:server_id_map (uniform 0) + lpm_src_v4/v6 (NULL fold) + lru_mapping/global_lru_maps (outer-only mode B,inner LRU 仍动态)。vip_to_down_rea 不 hint(benchmark 空 outer entry)。Mode B outer fold 用 `BPF_LD_IMM64_RAW + BPF_PSEUDO_MAP_FD` 保 verifier-typed map_ptr |

> **核心实验观察 (paper-grade)**: map_inline 单独跑会让 katran 慢 6.3%(死指令未清理);跟 const_prop 配套跑 +25.4%。在 paper 里 map_inline 不能作为独立 pass 报数据,必须跟 const_prop+dce 一起报。这跟 hard fold 的语义一致 — fold 把 lookup 替换成 scalar load,后续传播+清理需要 const_prop+dce。

测下一次后回填本表。

> **2026-05-08 const_prop EACCES 修复**: #244 引入 hard fold 后,默认 13-pass 在 map_inline → const_prop 触发 EACCES (verifier 拒绝 bytecode),后续 pass 全跳过 → ratio 退化到 1.2323。**根因**: const_prop 把 packet pointer 复制 (`r7 = r1`) 误折成 scalar 立即数 (`r7 = 62`),丢失 verifier 类型 provenance — 跟 map_inline 输出无关,只是被 hard fold 触发到这条路径。**修复** (#251 Path C): const_prop 在生成 scalar replacement 前查 verifier post-state,确认目的寄存器是 scalar exact 才替换;不命中走 fail-closed,记 diagnostic。详见 `docs/tmp/const_prop_after_map_inline_eacces_2026-05-08.md` (调研) + `const_prop_pathc_fix_2026-05-08.md` (实施)。

> **软 fold broken (#249 待修)**: #244 实现的 `<anchor>:<hex>` 软 fold 产出 verifier 拒绝的 bytecode (R8 invalid mem access scalar) — hit 路径返回 const_blob_ptr,跟 fallback lookup 路径的 map_value_or_null 类型不能 merge。新设计 (#249): hit 路径整段 fold scalar (复用 hard fold 机制),else 路径直接跳到现有 null handler (相当于 map miss),**不再 fallback lookup**。katran.yaml 当前所有 hint 都用 hard fold (`!`)。

> **Hint 接口已落地** (#244 + #245 + #247 + #254): `--inline-hint=<anchor>:[!]<hex_key>`,anchor 是 PC (纯数字) 或 map_name (字母开头),`!` = hard fold(替换为 const)/ 不带 = soft fold(else=NULL,#249/#253 落地)。Map-in-map 两个 mode:**Mode A 全链 fold** = outer + inner 双硬 hint(inner 必须静态);**Mode B outer-only** (#254) = 只给 outer 硬 hint,outer 折成 const map_ptr,inner lookup 保留(inner LRU 也允许)。Compressed overlay (`uniform/sparse/enumerated`) 解决 daemon size-skipped 大 map (ch_rings 33M-entry 等);**enumerated 空 entries** + hard hint = NULL fold(#254 LPM_TRIE 用),lookup 折成 r0=0,后续 dce 删 dead non-NULL path。kernel-write filter 静态扫 update/delete/push/pop 调用 + LRU 类型,override hint 也拒。

> **const_prop 单独跑无价值** (#255 audit): const_prop 70 个 fold 中 57 个用 LD_IMM64 替换单 ALU,**字节码反而胀 +57 insns**,JIT 也 +379 字节。它只是给 dce 创造 dead def,**必须跟 dce 配套报数据**。3-pass (无 dce) 看到的 0.74-0.98 ratio 都是 VM 噪声,不是 const_prop 真实贡献;真贡献体现在默认 13-pass 含 const_prop+dce 后的 jited 1968 字节 shrink。详见 `docs/tmp/const_prop_perf_audit_2026-05-08.md`。

## 18. Hint 接口最终设计 (已实施: #244 + #247)

### 语法

```
--inline-hint=<anchor>:[!]<hex_key>
```

| 维度 | 取值 |
|---|---|
| **Anchor** | 纯数字 → PC 锚点 (只命中那一站) /  字母开头 → map_name 锚点 (覆盖该 map 所有 lookup 站点) |
| **Mode** | 裸 hex → soft fold (if-guard,**目前 broken,#249 待重设计**) / `!` + hex → hard fold (lookup 整段删除替换为 const) |

4 个组合都支持: `<pc>:<hex>` / `<pc>:!<hex>` / `<map>:<hex>` / `<map>:!<hex>`。同 anchor 多条 soft 串成 PIC 链;同 anchor 多条 hard 报错;混用报错。

### map-in-map (Route A 双 hint 链, #247)

```yaml
--inline-hint=<outer_map>:!<outer_key>     # outer (ARRAY_OF_MAPS / HASH_OF_MAPS)
--inline-hint=<inner_map>:!<inner_key>     # 跟 outer fold 出的 inner_map_id 关联
```

outer hard fold 出 inner_map_id (从 raw entries 或 compressed overlay),inner 当普通 map fold。inner 命中 kernel-write filter (LRU/HASH 等) 直接拒绝。katran 上 inner = lru_mapping LRU → 0 applied,但代码路径是 cilium/tetragon paper enabler。

### Compressed overlay (#245)

`MAP_VALUES/overlays.json` 按 map_id 提供三种 form 给 daemon size-skipped 大 map:

```json
{
  "<map_id>": {
    "compression": "uniform" | "sparse" | "enumerated",
    "value_size": <bytes>,
    ...
  }
}
```

- `uniform`: 所有 key 返回 `value_hex`
- `sparse`: 命中 `entries[<key>]` 返该 value,否则返 `default_hex`
- `enumerated`: 仅列出 key 存在 (其他视为 entry-not-exist)

### Kernel-write filter (#244)

bpfopt 静态扫 bytecode 找 `bpf_map_update_elem` / `_delete_elem` / `_push_elem` / `_pop_elem`,标记 kernel-mutable map_id。LRU 类型 (LRU_HASH / LRU_PERCPU_HASH) 自动加。命中的 map 拒绝 inline,operator hint 也不能 override (fail-fast exit 1)。

### 设计选择回顾

| 选择 | 理由 |
|---|---|
| `:` = soft, `:!` = hard | 软是更安全默认,operator 显式 opt-in 硬 fold (paper-grade max speedup) |
| 同时保留 PC 和 map_name | map_name 是稳定主路径(跨 pass / rebuild 不变),PC 是稀有"多 const key 同 map 不同站点"的 escape hatch |
| 不做 Mode A 自动检测 (源码 const key) | katran 等 7 app 的实际形态都能用 Mode B (hint key) 表达,Mode A 没增量价值 |
| Soft fold else 路径走原 lookup (#244 实现) | broken,verifier 拒绝 merge — 重设计为 else 走 NULL handler (#249) |

## 19. 14-skipped-site map 归属调研 (Phase 5 闭环)

数据源:

- Phase 1 result: `corpus/results/x86_kvm_corpus_20260508_231402_301128/details/apps/katran.json`
- Bytecode / map fd snapshot: `corpus/results/x86_kvm_corpus_20260430_193236_794969/details/workdirs/553/{prog.bin,map_fds.json,target.json}`
- 源码: `runner/repos/katran/katran/lib/bpf/balancer.bpf.c` 和 include headers

方法:解析 `prog.bin` 的 raw `struct bpf_insn[]`,在每个 skipped call PC 前找最近的 `BPF_LD_IMM64` pseudo-map-fd load,取 `imm` 作为 old fd,再用 `map_fds.json` 转为 map id/name。源码行号用 `corpus/build/katran/balancer.bpf.o` 的 xdp section BTF line info 对齐,再按 map name + 邻近控制流 grep 到实际 `bpf_map_lookup_elem()` 表达式所在源码行。

### 19.1 14 行归属表

| PC | map_name | map_id | skip reason | 源码行号 | 适用 hint 模式 / Phase |
|---:|---|---:|---|---|---|
| 512 | `vip_map` | 3948 | lookup key is not available from verifier-guided state | `balancer.bpf.c:787` | Phase 2, `vip_map:<VIP,8080,TCP>`;主路径 fixed VIP/port hint |
| 520 | `vip_map` | 3948 | lookup key is not available from verifier-guided state | `balancer.bpf.c:790` | 当前 Phase 不计预期;这是 port-zero fallback,runner 未预填该 entry |
| 562 | `lru_mapping` | 3950 | map-in-map chain is not inlineable | `balancer.bpf.c:839` | Phase 4 map-in-map enabler only;inner LRU 仍不可 value-inline |
| 762 | `vip_map` | 3948 | lookup key is not available from verifier-guided state | `balancer.bpf.c:787` | Phase 2,第二个编译拷贝的 fixed VIP/port hint |
| 770 | `vip_map` | 3948 | lookup key is not available from verifier-guided state | `balancer.bpf.c:790` | 当前 Phase 不计预期;同 PC 520 |
| 814 | `lru_mapping` | 3950 | map-in-map chain is not inlineable | `balancer.bpf.c:839` | Phase 4 map-in-map enabler only;inner LRU 仍不可 value-inline |
| 863 | `quic_stats_map` | 3957 | lookup key is not available from verifier-guided state | `balancer.bpf.c:876` | 不应进默认 hint;per-cpu stats/RMW map,Phase 3a filter 应提前排除 |
| 895 | `quic_stats_map` | 3957 | lookup key is not available from verifier-guided state | `balancer.bpf.c:876` | 不应进默认 hint;同上 |
| 1072 | `vip_to_down_rea` | 3965 | map-in-map outer key unavailable after prior rewrite | `balancer.bpf.c:662` | Phase 4 only;当前 benchmark outer map 为空,预期 0 site |
| 1105 | `ctl_array` | 3947 | lookup result is not consumed by fixed-offset scalar loads | `balancer.bpf.c:1033` | Phase 1 已解决;round 2 重新扫描已 rewrite site 的统计性 skip,应改成 `ctl_array:00000000` hint |
| 1351 | `vip_miss_stats` | 3956 | lookup key is not available from verifier-guided state | `balancer.bpf.c:588` | 不进 Phase 3/4;diagnostic path,低价值且应由 mutability/writer filter 保护 |
| 1776 | `vip_to_down_rea` | 3965 | map-in-map outer key unavailable after prior rewrite | `balancer.bpf.c:662` | Phase 4 only;当前 benchmark outer map 为空,预期 0 site |
| 1807 | `ctl_array` | 3947 | lookup result is not consumed by fixed-offset scalar loads | `balancer.bpf.c:1033` | Phase 1 已解决;round 2 统计性 skip |
| 2062 | `vip_miss_stats` | 3956 | lookup key is not available from verifier-guided state | `balancer.bpf.c:588` | 不进 Phase 3/4;diagnostic path |

归属计数:

| map | count in 14 skipped PCs |
|---|---:|
| `vip_map` | 4 |
| `lru_mapping` | 2 |
| `quic_stats_map` | 2 |
| `vip_to_down_rea` | 2 |
| `ctl_array` | 2 |
| `vip_miss_stats` | 2 |
| `ch_rings` | 0 |
| `reals` | 0 |

### 19.2 skip reason 根因

`lookup key is not available from verifier-guided state` 的 8 个站点不是同一类业务机会。4 个 `vip_map` 是 Phase 2 的 fixed traffic key specialization 目标;2 个 `quic_stats_map` 和 2 个 `vip_miss_stats` 是 stats/diagnostic path,默认不该为了 map_inline 追它们。当前 bpfopt 的根因是 key extraction 过度依赖前一轮 `noop` 的 verifier log snapshot;这些 call PC 没有 state snapshot,而 map 又没有 `BPF_F_RDONLY_PROG` 这类只读标志时,pass 不能走 runtime-key rewrite,于是落到 verifier-state miss。Phase 3a 的 map-level kernel-write/static writer filter 应该先把 stats 类 map 从候选集中拿掉;Phase 2/§18 的 map-name+key hint 应该只显式覆盖 `vip_map`。

`lookup result is not consumed by fixed-offset scalar loads` 的 2 个站点是 `ctl_array[0]` 的 round-2 artifact。PC 1105/1807 在 round 1 已经成功 inline,然后 fixed-point 第二轮重新扫描修改后的 bytecode,原来的 R0 use pattern 已经不存在,所以被计入 skip reason。这不是未解锁机会,但 bpfopt reporting 可以改进:已经 applied 的 PC 不应该再次贡献最终 `sites_skipped`。

`map-in-map chain is not inlineable` 的 2 个站点是 `lru_mapping`。这个 outer map 返回 per-cpu inner LRU map pointer,后续 `bpf_map_lookup_elem(lru_map,&pckt->flow)` 仍是 LRU map lookup,lookup 本身改变 LRU 状态,不能当作普通 frozen value inline。Phase 4 即使支持 map-in-map outer rewrite,这里也不能算作 `ch_rings/reals` 那种 value specialization。

`map-in-map outer key unavailable after prior rewrite` 的 2 个站点是 `vip_to_down_reals_map` outer lookup。它需要从 VIP struct 提取 outer key,并且还需要 populated outer/inner snapshot。当前 benchmark 的 down-real map 为空,所以 Phase 4 在 Katran 当前配置上预期仍是 0 applied site;它更像 Cilium/Tracee map-in-map 论文扩展的 enabler。

### 19.3 ch_rings / reals 验证结论

`ch_rings` 和 `reals` **不在这 14 个 skipped PC 里**,也**不在 Phase 1 的 matched-site accounting 里**。注意这里有 fixed-point 计数噪声:`ctl_array[0]` at PC 1105/1807 在 round 1 已 applied,round 2 又以 fixed-offset reason 计入 skipped。所以这张 14 行表不是 14 个从未 applied 的 unique miss,但它覆盖了 diagnostics 里的 14 个 skipped PC。

全程序 bytecode 里确实存在 `ch_rings`/`reals` lookup,但它们被挡在 16-site 列表之前:

| map | bytecode lookup PCs | map_id | 主要源码 |
|---|---|---:|---|
| `ch_rings` | 1292, 1995 | 3951 | `balancer.bpf.c:146` |
| `reals` | 1041, 1311, 1524, 1702, 1726, 1746, 2018 | 3952 | `balancer.bpf.c:159`, `balancer.bpf.c:198`, `balancer.bpf.c:540`, `balancer.bpf.c:898`, `pckt_parsing.h:334` |

直接原因是 map snapshot size gate。`map_inline` 对 `map_snapshots_skipped_by_size` 只记录总数 `maps_skipped_by_size=7`;逐站逻辑在发现 map snapshot skipped by size 后直接 `continue`,没有把这些 PCs 写入 `sites_skipped` diagnostics。因此 Phase 3 不是在修复当前 14 个 skip reason,而是在让 `ch_rings`/`reals` 这类 size-skipped map 通过 compressed overlay/hint 进入候选集合。

### 19.4 Phase 3 / Phase 4 预期修正

Phase 2 (`vip_map`) 的实际 hot-path 候选是 2 个静态站点:PC 512/762 是 fixed VIP+port 主 lookup。PC 520/770 是 port=0 fallback lookup,当前 runner 未预填该 entry,所以不应算进 Phase 2 预期;只有额外构造 wildcard/port-zero VIP snapshot 时才可能到 4。

Phase 3 (`ch_rings` + `reals`) 的实际工作是:

1. 提供 `ch_rings` uniform overlay,让 33M-entry array 不再因 size gate 消失。
2. 提供 `reals` sparse overlay,至少包含 real id 1 的 `real_definition`。
3. 把 hint 锚点从 PC 改为 map name + key / compressed map overlay,否则这些 PC 不稳定且没法表达 uniform ring。
4. 让 pass 在没有 exact verifier key 的情况下利用 uniform/sparse snapshot 做合法 rewrite,尤其是 `ch_rings` uniform real_id=1 后再带出 dependent `reals[1]`。

Phase 3 静态候选上界是 `ch_rings` 2 个 site + `reals` 7 个 site。现实 hot-path 预期应更保守:先按 `ch_rings` 2 个 site + `get_packet_dst` dependent `reals` 2 个 site 估计;其余 `reals` 来自 server-id/TCP-opt/QUIC/LRU 旁路,是否值得 inline 取决于 workload 是否触发。如果第一版只有 overlay+map-name hint,但没有 dependent propagation,保守预期就是 `ch_rings` 2、`reals` 0。

Phase 4 当前 Katran 配置预期 applied 仍是 0:

- `vip_to_down_rea` 有 2 个 outer skipped site,但 benchmark map 为空;只有构造 populated down-real map 后才有意义。
- `lru_mapping` 有 2 个 outer skipped site,但 inner LRU lookup 不能 value-inline;最多是 outer-map pointer rewrite enabler,不能算当前 map_inline speed site。

### 19.5 bpfopt 可改进点

1. **reporting**:对 size-skipped map 记录 per-site diagnostics,至少包含 PC/map_id/map_name/reason。现在只写 `maps_skipped_by_size=7`,导致 `ch_rings/reals` 从 16-site 表面结果里消失。
2. **fixed-point accounting**:已经成功 applied 的 PC 不应在下一轮被计入最终 `sites_skipped`。PC 1105/1807 的 round-2 fixed-offset skip 应该从最终 skip count 里剥离,或标成 `already_rewritten`.
3. **map writer filter**:用 BPF bytecode 静态扫描 `bpf_map_update_elem/delete_elem/push/pop` 和 LRU map 类型,替代 `BPF_F_RDONLY_PROG` flag guard。这样 `quic_stats_map`、`vip_miss_stats` 这类 stats/diagnostic map 不会伪装成 verifier-state miss。
4. **verifier-state coverage**:当前 `noop` log 的 state snapshot 不覆盖这些 call PC。可改进 verifier log parser 的 PC 对齐/邻近 state 回退,或在 pass 内做 stack key store 的局部常量传播。对 `vip_map` 这类 traffic-specialized map,更直接的路径仍是 explicit hint,不应假装从 verifier 自动证明 deployment invariant。
5. **hint redesign**:实现 §18 的 `map_name:key` / compressed overlay 语义。Phase 3 的 `ch_rings` uniform 和 `reals` sparse 都不是稳定 PC hint 能自然表达的东西。
6. **map-in-map support**:Phase 4 要先区分 `vip_to_down_reals_map` 这种可作为 benchmark/future-paper enabler 的 outer map,和 `lru_mapping` 这种 inner LRU 不可 value-inline 的 map。二者不能混成同一个 "map-in-map unlock count"。
